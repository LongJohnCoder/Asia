//**************************************************************************
//**************************************************************************
//**                                                                      **
//**  Copyright (c) 2015 - 2017 Shanghai Zhaoxin Semiconductor Co., Ltd.  **
//**                                                                      **
//**************************************************************************
//**************************************************************************

// This file is auto converted by Irs2h from IRS_CND003_PCIE PHY_R100(A0)_RD.doc.
#ifndef _IRS_CND003_PCIE_PHY_R100_A0_RD_H_
#define _IRS_CND003_PCIE_PHY_R100_A0_RD_H_
// PCIEPHYCFG
#define CND003_PCIEPHYCFG_PWR_GATE_FOR_PSO_EN_ISO_EN_AND_PSO_ACK 0x40 // Power Gate for-PSO_EN, ISO_EN and PSO_ACK
    #define CND003_PCIEPHYCFG_RSVPCIEPHYCFG_40 PCIEPHYCFG_PWR_GATE_FOR_PSO_EN_ISO_EN_AND_PSO_ACK // 0/x/x/x Reserved
#define CND003_PCIEPHYCFG_EPHY0_TPLL0_TPLL_LOCK_EN_PHYB_PHYA 0x41 // EPHY0 TPLL0 TPLL_LOCK_EN PHYB PHYA
    #define CND003_PCIEPHYCFG_FHP0_TPLL_LF_PHYB        BIT7    // 0/0/x/x Reserved ((No Use))
    #define CND003_PCIEPHYCFG_FHP0_GATECLK_EN_PHYB     BIT6    // 1b/1b/x/x TPLL0 Feedback Clock Delay Setting
    #define CND003_PCIEPHYCFG_FHP0_TPLL_FLAGCK_EN_PHYB BIT5    // 0/0/x/x Enable TPLL0 Flag Function when Debug Mode
    #define CND003_PCIEPHYCFG_FHP0_TPLL_LOCK_EN_PHYB   BIT4    // 0/0/x/x Overwrite TPLL0 Lock Flag Setting
    #define CND003_PCIEPHYCFG_FHP0_TPLL_LF_PHYA        BIT3    // 0/0/x/x Reserved ((No Use))
    #define CND003_PCIEPHYCFG_FHP0_GATECLK_EN_PHYA     BIT2    // 1b/1b/x/x TPLL0 Feedback Clock Delay Setting
    #define CND003_PCIEPHYCFG_FHP0_TPLL_FLAGCK_EN_PHYA BIT1    // 0/0/x/x Enable TPLL0 Flag Function when Debug Mode
    #define CND003_PCIEPHYCFG_FHP0_TPLL_LOCK_EN_PHYA   BIT0    // 0/0/x/x Overwrite TPLL0 Lock Flag Setting
#define CND003_PCIEPHYCFG_EPHY0_TPLL1_TPLL_LOCK_EN_PHYB_PHYA 0x42 // EPHY0 TPLL1 TPLL_LOCK_EN PHYB PHYA
    #define CND003_PCIEPHYCFG_FHP1_TPLL_SEL_PHYB       BIT7    // 0/0/x/x Reserved ((No Use))
    #define CND003_PCIEPHYCFG_FHP1_GATECLK_EN_PHYB     BIT6    // 1b/1b/x/x TPLL1 Feedback Clock Delay Setting
    #define CND003_PCIEPHYCFG_FHP1_TPLL_FLAGCK_EN_PHYB BIT5    // 0/0/x/x Enable TPLL1 Flag Function when Debug Mode
    #define CND003_PCIEPHYCFG_FHP1_TPLL_LOCK_EN_PHYB   BIT4    // 0/0/x/x Overwrite TPLL1 Lock Flag Setting
    #define CND003_PCIEPHYCFG_FHP1_TPLL_SEL_PHYA       BIT3    // 0/0/x/x Reserved ((No Use))
    #define CND003_PCIEPHYCFG_FHP1_GATECLK_EN_PHYA     BIT2    // 1b/1b/x/x TPLL1 Feedback Clock Delay Setting
    #define CND003_PCIEPHYCFG_FHP1_TPLL_FLAGCK_EN_PHYA BIT1    // 0/0/x/x Enable TPLL1 Flag Function when Debug Mode
    #define CND003_PCIEPHYCFG_FHP1_TPLL_LOCK_EN_PHYA   BIT0    // 0/0/x/x Overwrite TPLL0 Lock Flag Setting
#define CND003_PCIEPHYCFG_EPHY0_TPLL0_TPLL_LOCK_EN_EP 0x43 // EPHY0 TPLL0 TPLL_LOCK_EN EP
    #define CND003_PCIEPHYCFG_RSV_43               0xF0    // 0/0/x/x Reserved
    #define CND003_PCIEPHYCFG_FHP0_TPLL_LF         BIT3    // 0/0/x/x Reserved ((No Use))
    #define CND003_PCIEPHYCFG_FHP0_GATECLK_EN      BIT2    // 1b/1b/x/x TPLL0 Feedback Clock Delay Setting
    #define CND003_PCIEPHYCFG_FHP0_TPLL_FLAGCK_EN  BIT1    // 0/0/x/x Enable TPLL0 Flag Function when Debug Mode
    #define CND003_PCIEPHYCFG_FHP0_TPLL_LOCK_EN    BIT0    // 0/0/x/x Overwrite TPLL0 Lock Flag Setting
#define CND003_PCIEPHYCFG_EPHY0_TPLL1_TPLL_LOCK_EN_EP 0x44 // EPHY0 TPLL1 TPLL_LOCK_EN EP
    #define CND003_PCIEPHYCFG_RSV_44               0xF0    // 0/0/x/x Reserved
    #define CND003_PCIEPHYCFG_FHP1_TPLL_SEL        BIT3    // 0/0/x/x Reserved ((No Use))
    #define CND003_PCIEPHYCFG_FHP1_GATECLK_EN      BIT2    // 1b/1b/x/x TPLL1 Feedback Clock Delay Setting
    #define CND003_PCIEPHYCFG_FHP1_TPLL_FLAGCK_EN  BIT1    // 0/0/x/x Enable TPLL1 Flag Function when Debug Mode
    #define CND003_PCIEPHYCFG_FHP1_TPLL_LOCK_EN    BIT0    // 0/0/x/x Overwrite TPLL1 Lock Flag Setting
#define CND003_PCIEPHYCFG_EPHY0_TPLL0_1_TPLL_LOCK_EN_PHYC 0x45 // EPHY0 TPLL0,1 TPLL_LOCK_EN PHYC
    #define CND003_PCIEPHYCFG_RSV_45 PCIEPHYCFG_EPHY0_TPLL0_1_TPLL_LOCK_EN_PHYC // 0/0/x/x Reserved
#define CND003_PCIEPHYCFG_EPHY0_TPLL0_G1_TPLL_CP_PHYB 0x46 // EPHY0 TPLL0-G1 TPLL_CP PHYB
    #define CND003_PCIEPHYCFG_RSVPCIEPHYCFG_46_7           BIT7                    // 0/0/x/x Reserved
    #define CND003_PCIEPHYCFG_FRP0_TPLL_DIV_G1_PHYB_2_0    (BIT4 + BIT5 + BIT6)    // 0/0/x/x TPLL0 Feedback Frequency
    #define CND003_PCIEPHYCFG_FRP0_TPLL_CP_G1_PHYB_3_0     0xF                     // 0101b/0101/x/x TPLL0 CP Current Setting
#define CND003_PCIEPHYCFG_EPHY0_TPLL1_G1_TPLL_CP_PHYB 0x47 // EPHY0 TPLL1-G1 TPLL_CP PHYB
    #define CND003_PCIEPHYCFG_RSVPCIEPHYCFG_47_7           BIT7                    // 0/0/x/x Reserved
    #define CND003_PCIEPHYCFG_FRP1_TPLL_DIV_G1_PHYB_2_0    (BIT4 + BIT5 + BIT6)    // 0/0/x/x TPLL1 Feedback Frequency
    #define CND003_PCIEPHYCFG_FRP1_TPLL_CP_G1_PHYB_3_0     0xF                     // 0101b/0101/x/x TPLL1 CP Current Setting
#define CND003_PCIEPHYCFG_EPHY0_TPLL0_G2_TPLL_CP_PHYB 0x48 // EPHY0 TPLL0-G2 TPLL_CP PHYB
    #define CND003_PCIEPHYCFG_RSVPCIEPHYCFG_48_7           BIT7                    // 0/0/x/x Reserved
    #define CND003_PCIEPHYCFG_FRP0_TPLL_DIV_G2_PHYB_2_0    (BIT4 + BIT5 + BIT6)    // 0/0/x/x TPLL0 Feedback Frequency
    #define CND003_PCIEPHYCFG_FRP0_TPLL_CP_G2_PHYB_3_0     0xF                     // 0101b/0101/x/x TPLL0 CP Current Setting
#define CND003_PCIEPHYCFG_EPHY0_TPLL1_G2_TPLL_CP_PHYB 0x49 // EPHY0 TPLL1-G2 TPLL_CP PHYB
    #define CND003_PCIEPHYCFG_RSVPCIEPHYCFG_49_7           BIT7                    // 0/0/x/x Reserved
    #define CND003_PCIEPHYCFG_FRP1_TPLL_DIV_G2_PHYB_2_0    (BIT4 + BIT5 + BIT6)    // 0/0/x/x TPLL1 Feedback Frequency
    #define CND003_PCIEPHYCFG_FRP1_TPLL_CP_G2_PHYB_3_0     0xF                     // 0101b/0101/x/x TPLL1 CP Current Setting
#define CND003_PCIEPHYCFG_EPHY0_TPLL0_G3_TPLL_CP_PHYB 0x4A // EPHY0 TPLL0-G3 TPLL_CP PHYB
    #define CND003_PCIEPHYCFG_RSVPCIEPHYCFG_4A_7           BIT7                    // 0/0/x/x Reserved
    #define CND003_PCIEPHYCFG_FRP0_TPLL_DIV_G3_PHYB_2_0    (BIT4 + BIT5 + BIT6)    // 010b/010/x/x TPLL0 Feedback Frequency
    #define CND003_PCIEPHYCFG_FRP0_TPLL_CP_G3_PHYB_3_0     0xF                     // 0101b/0101/x/x TPLL0 CP Current Setting
#define CND003_PCIEPHYCFG_EPHY0_TPLL1_G3_TPLL_CP_PHYB 0x4B // EPHY0 TPLL1-G3 TPLL_CP PHYB
    #define CND003_PCIEPHYCFG_RSVPCIEPHYCFG_4B_7           BIT7                    // 0/0/x/x Reserved
    #define CND003_PCIEPHYCFG_FRP1_TPLL_DIV_G3_PHYB_2_0    (BIT4 + BIT5 + BIT6)    // 010b/010/x/x TPLL1 Feedback Frequency
    #define CND003_PCIEPHYCFG_FRP1_TPLL_CP_G3_PHYB_3_0     0xF                     // 0101b/0101/x/x TPLL1 CP Current Setting
#define CND003_PCIEPHYCFG_EPHY0_TPLL0_G1_TPLL_CP_PHYA 0x4C // EPHY0 TPLL0-G1 TPLL_CP PHYA
    #define CND003_PCIEPHYCFG_RSVPCIEPHYCFG_4C_7           BIT7                    // 0/0/x/x Reserved
    #define CND003_PCIEPHYCFG_FRP0_TPLL_DIV_G1_PHYA_2_0    (BIT4 + BIT5 + BIT6)    // 0/0/x/x TPLL0 Feedback Frequency
    #define CND003_PCIEPHYCFG_FRP0_TPLL_CP_G1_PHYA_3_0     0xF                     // 0101b/0101/x/x TPLL0 CP Current Setting
#define CND003_PCIEPHYCFG_EPHY0_TPLL1_G1_TPLL_CP_PHYA 0x4D // EPHY0 TPLL1-G1 TPLL_CP PHYA
    #define CND003_PCIEPHYCFG_RSVPCIEPHYCFG_4D_7           BIT7                    // 0/0/x/x Reserved
    #define CND003_PCIEPHYCFG_FRP1_TPLL_DIV_G1_PHYA_2_0    (BIT4 + BIT5 + BIT6)    // 0/0/x/x TPLL1 Feedback Frequency
    #define CND003_PCIEPHYCFG_FRP1_TPLL_CP_G1_PHYA_3_0     0xF                     // 0101b/0101/x/x TPLL1 CP Current Setting
#define CND003_PCIEPHYCFG_EPHY0_TPLL0_G2_TPLL_CP_PHYA 0x4E // EPHY0 TPLL0-G2 TPLL_CP PHYA
    #define CND003_PCIEPHYCFG_RSVPCIEPHYCFG_4E_7           BIT7                    // 0/0/x/x Reserved
    #define CND003_PCIEPHYCFG_FRP0_TPLL_DIV_G2_PHYA_2_0    (BIT4 + BIT5 + BIT6)    // 0/0/x/x TPLL0 Feedback Frequency
    #define CND003_PCIEPHYCFG_FRP0_TPLL_CP_G2_PHYA_3_0     0xF                     // 0101b/0101/x/x TPLL0 CP Current Setting
#define CND003_PCIEPHYCFG_EPHY0_TPLL1_G2_TPLL_CP_PHYA 0x4F // EPHY0 TPLL1-G2 TPLL_CP PHYA
    #define CND003_PCIEPHYCFG_RSVPCIEPHYCFG_4F_7           BIT7                    // 0/0/x/x Reserved
    #define CND003_PCIEPHYCFG_FRP1_TPLL_DIV_G2_PHYA_2_0    (BIT4 + BIT5 + BIT6)    // 0/0/x/x TPLL1 Feedback Frequency
    #define CND003_PCIEPHYCFG_FRP1_TPLL_CP_G2_PHYA_3_0     0xF                     // 0101b/0101/x/x TPLL1 CP Current Setting
#define CND003_PCIEPHYCFG_EPHY0_TPLL0_G3_TPLL_CP_PHYA 0x50 // EPHY0 TPLL0-G3 TPLL_CP PHYA
    #define CND003_PCIEPHYCFG_RSVPCIEPHYCFG_50_7           BIT7                    // 0/0/x/x Reserved
    #define CND003_PCIEPHYCFG_FRP0_TPLL_DIV_G3_PHYA_2_0    (BIT4 + BIT5 + BIT6)    // 010b/010/x/x TPLL0 Feedback Frequency
    #define CND003_PCIEPHYCFG_FRP0_TPLL_CP_G3_PHYA_3_0     0xF                     // 0101b/0101/x/x TPLL0 CP Current Setting
#define CND003_PCIEPHYCFG_EPHY0_TPLL1_G3_TPLL_CP_PHYA 0x51 // EPHY0 TPLL1-G3 TPLL_CP PHYA
    #define CND003_PCIEPHYCFG_RSVPCIEPHYCFG_51_7           BIT7                    // 0/0/x/x Reserved
    #define CND003_PCIEPHYCFG_FRP1_TPLL_DIV_G3_PHYA_2_0    (BIT4 + BIT5 + BIT6)    // 010b/010/x/x TPLL1 Feedback Frequency
    #define CND003_PCIEPHYCFG_FRP1_TPLL_CP_G3_PHYA_3_0     0xF                     // 0101b/0101/x/x TPLL1 CP Current Setting
#define CND003_PCIEPHYCFG_EPHY0_TPLL0_G1_TPLL_CP 0x52 // EPHY0 TPLL0-G1 TPLL_CP
    #define CND003_PCIEPHYCFG_RSV_52 PCIEPHYCFG_EPHY0_TPLL0_G1_TPLL_CP // 0/0/x/x Reserved
#define CND003_PCIEPHYCFG_EPHY0_TPLL1_G1_TPLL_CP 0x53 // EPHY0 TPLL1-G1 TPLL_CP
    #define CND003_PCIEPHYCFG_RSV_53 PCIEPHYCFG_EPHY0_TPLL1_G1_TPLL_CP // 0/0/x/x Reserved
#define CND003_PCIEPHYCFG_EPHY0_TPLL0_G2_TPLL_CP 0x54 // EPHY0 TPLL0-G2 TPLL_CP
    #define CND003_PCIEPHYCFG_RSV_54 PCIEPHYCFG_EPHY0_TPLL0_G2_TPLL_CP // 0/0/x/x Reserved
#define CND003_PCIEPHYCFG_EPHY0_TPLL1_G2_TPLL_CP 0x55 // EPHY0 TPLL1-G2 TPLL_CP
    #define CND003_PCIEPHYCFG_RSV_55 PCIEPHYCFG_EPHY0_TPLL1_G2_TPLL_CP // 0/0/x/x Reserved
#define CND003_PCIEPHYCFG_EPHY0_TPLL0_G3_TPLL_CP 0x56 // EPHY0 TPLL0-G3 TPLL_CP
    #define CND003_PCIEPHYCFG_RSV_56 PCIEPHYCFG_EPHY0_TPLL0_G3_TPLL_CP // 0/0/x/x Reserved
#define CND003_PCIEPHYCFG_EPHY0_TPLL1_G3_TPLL_CP 0x57 // EPHY0 TPLL1-G3 TPLL_CP
    #define CND003_PCIEPHYCFG_RSV_57 PCIEPHYCFG_EPHY0_TPLL1_G3_TPLL_CP // 0/0/x/x Reserved
#define CND003_PCIEPHYCFG_EPHY0_TPLL0_G1_TPLL_CP_EP 0x58 // EPHY0 TPLL0-G1 TPLL_CP EP
    #define CND003_PCIEPHYCFG_RSVPCIEPHYCFG_58_7       BIT7                    // 0/0/x/x Reserved
    #define CND003_PCIEPHYCFG_FRP0_TPLL_DIV_G1_EP_2_0  (BIT4 + BIT5 + BIT6)    // 0/0/x/x TPLL Feedback Frequency
    #define CND003_PCIEPHYCFG_FRP0_TPLL_CP_G1_EP_3_0   0xF                     // 0101b/0101/x/x TPLL CP Current Setting
#define CND003_PCIEPHYCFG_EPHY0_TPLL1_G1_TPLL_CP_EP 0x59 // EPHY0 TPLL1-G1 TPLL_CP EP
    #define CND003_PCIEPHYCFG_RSVPCIEPHYCFG_59_7       BIT7                    // 0/0/x/x Reserved
    #define CND003_PCIEPHYCFG_FRP1_TPLL_DIV_G1_EP_2_0  (BIT4 + BIT5 + BIT6)    // 0/0/x/x TPLL Feedback Frequency
    #define CND003_PCIEPHYCFG_FRP1_TPLL_CP_G1_EP_3_0   0xF                     // 0101b/0101/x/x TPLL CP Current Setting
#define CND003_PCIEPHYCFG_EPHY0_TPLL0_G2_TPLL_CP_EP 0x5A // EPHY0 TPLL0-G2 TPLL_CP EP
    #define CND003_PCIEPHYCFG_RSVPCIEPHYCFG_5A_7       BIT7                    // 0/0/x/x Reserved
    #define CND003_PCIEPHYCFG_FRP0_TPLL_DIV_G2_EP_2_0  (BIT4 + BIT5 + BIT6)    // 0/0/x/x TPLL Feedback Frequency
    #define CND003_PCIEPHYCFG_FRP0_TPLL_CP_G2_EP_3_0   0xF                     // 0101b/0101/x/x TPLL CP Current Setting
#define CND003_PCIEPHYCFG_EPHY0_TPLL1_G2_TPLL_CP_EP 0x5B // EPHY0 TPLL1-G2 TPLL_CP EP
    #define CND003_PCIEPHYCFG_RSVPCIEPHYCFG_5B_7       BIT7                    // 0/0/x/x Reserved
    #define CND003_PCIEPHYCFG_FRP1_TPLL_DIV_G2_EP_2_0  (BIT4 + BIT5 + BIT6)    // 0/0/x/x TPLL Feedback Frequency
    #define CND003_PCIEPHYCFG_FRP1_TPLL_CP_G2_EP_3_0   0xF                     // 0101b/0101/x/x TPLL CP Current Setting
#define CND003_PCIEPHYCFG_EPHY0_TPLL0_G3_TPLL_CP_EP 0x5C // EPHY0 TPLL0-G3 TPLL_CP EP
    #define CND003_PCIEPHYCFG_RSVPCIEPHYCFG_5C_7       BIT7                    // 0/0/x/x Reserved
    #define CND003_PCIEPHYCFG_FRP0_TPLL_DIV_G3_EP_2_0  (BIT4 + BIT5 + BIT6)    // 010b/010/x/x TPLL Feedback Frequency
    #define CND003_PCIEPHYCFG_FRP0_TPLL_CP_G3_EP_3_0   0xF                     // 0101b/0101/x/x TPLL CP Current Setting
#define CND003_PCIEPHYCFG_EPHY0_TPLL1_G3_TPLL_CP_EP 0x5D // EPHY0 TPLL1-G3 TPLL_CP EP
    #define CND003_PCIEPHYCFG_RSVPCIEPHYCFG_5D_7       BIT7                    // 0/0/x/x Reserved
    #define CND003_PCIEPHYCFG_FRP1_TPLL_DIV_G3_EP_2_0  (BIT4 + BIT5 + BIT6)    // 010b/010/x/x TPLL Feedback Frequency
    #define CND003_PCIEPHYCFG_FRP1_TPLL_CP_G3_EP_3_0   0xF                     // 0101b/0101/x/x TPLL CP Current Setting
#define CND003_PCIEPHYCFG_EPHY_BANDGAP_TRIM 0x5E // EPHY BandGap TRIM
    #define CND003_PCIEPHYCFG_RSV_5E               BIT7            // 0/0/x/x Reserved
    #define CND003_PCIEPHYCFG_FHP_REFCLK_SEL       BIT6            // 0/0/x/x Reference Clock Select
    #define CND003_PCIEPHYCFG_FHP_MPLL_LOCK_EN     BIT5            // 0/0/x/x Overwrite MPLL Lock Flag Setting (MPLL LOCKEN EP)
    #define CND003_PCIEPHYCFG_FHP_MPLLREFCLK_SEL   BIT4            // 1b/1b/x/x Manual Setting for Selection 25MHz or 100MHz Reference Clock for MP...
    #define CND003_PCIEPHYCFG_FHP_MPLL_OP          BIT3            // 0/0/x/x MPLL Operation Mode for Debugging (MPLL_OP for EP)
    #define CND003_PCIEPHYCFG_FHP_REFCLKPS_SEL     BIT2            // 0/0/x/x Manual Setting for Selecting Internal PCIe or SATA Clock (REFCLKPS SE...
    #define CND003_PCIEPHYCFG_FHP_BG_TRIM          (BIT0 + BIT1)   // 01b/01b/x/x Fine Tune Bandgap Setting (FHP_BG_TRIM for EP)
#define CND003_PCIEPHYCFG_EPHY_REFCLKPS_SEL 0x5F // EPHY REFCLKPS_SEL
    #define CND003_PCIEPHYCFG_RSV_5F                   BIT7            // 0/0/x/x Reserved
    #define CND003_PCIEPHYCFG_FHP_REFCLK_SEL_PHYA      BIT6            // 0/0/x/x Reference Clock Select
    #define CND003_PCIEPHYCFG_FHP_MPLL_LOCK_EN_PHYA    BIT5            // 0/0/x/x Overwrite MPLL Lock Flag Setting (MPLL LOCKEN PHYA)
    #define CND003_PCIEPHYCFG_FHP_MPLLREFCLK_SEL_PHYA  BIT4            // 1b/1b/x/x Manual Setting for Selection 25MHz or 100MHz Reference Clock for MP...
    #define CND003_PCIEPHYCFG_FHP_MPLL_OP_PHYA         BIT3            // 0/0/x/x MPLL Operation Mode for Debugging (MPLL_OP for PHYA)
    #define CND003_PCIEPHYCFG_FHP_REFCLKPS_SEL_PHYA    BIT2            // 0/0/x/x Manual Setting for Selecting Internal PCIe or SATA Clock (REFCLKPS SE...
    #define CND003_PCIEPHYCFG_FHP_BG_TRIM_PHYA         (BIT0 + BIT1)   // 01b/01b/x/x Fine Tune Bandgap Setting (FHP_BG_TRIM for PHYA)
#define CND003_PCIEPHYCFG_EPHY_MPLL_REFCLK 0x60 // EPHY MPLL REFCLK
    #define CND003_PCIEPHYCFG_RSV_60                   BIT7            // 0/0/x/x Reserved
    #define CND003_PCIEPHYCFG_FHP_REFCLK_SEL_PHYB      BIT6            // 0/0/x/x Reference Clock Select
    #define CND003_PCIEPHYCFG_FHP_MPLL_LOCK_EN_PHYB    BIT5            // 0/0/x/x Overwrite MPLL Lock Flag Setting (MPLL LOCKEN PHYB)
    #define CND003_PCIEPHYCFG_FHP_MPLLREFCLK_SEL_PHYB  BIT4            // 1b/1b/x/x Manual Setting for Selection 25MHz or 100MHz Reference Clock for MP...
    #define CND003_PCIEPHYCFG_FHP_MPLL_OP_PHYB         BIT3            // 0/0/x/x MPLL Operation Mode for Debugging (MPLL_OP for PHYB)
    #define CND003_PCIEPHYCFG_FHP_REFCLKPS_SEL_PHYB    BIT2            // 0/0/x/x Manual Setting for Selecting Internal PCIe or SATA Clock (REFCLKPS SE...
    #define CND003_PCIEPHYCFG_FHP_BG_TRIM_PHYB         (BIT0 + BIT1)   // 01b/01b/x/x Fine Tune Bandgap Setting (FHP_BG_TRIM for PHYB)
#define CND003_PCIEPHYCFG_EPHY_PHYB_MPLL 0x61 // EPHY PHYB MPLL
    #define CND003_PCIEPHYCFG_FHP_MPLLMODE_PHYB        BIT7            // 0/0/x/x MPLL Mode for PHYB
    #define CND003_PCIEPHYCFG_FHP_MPLL_FLAGCK_EN_PHYB  BIT6            // 0/0/x/x MPLL Flag CK Enable for PHYB
    #define CND003_PCIEPHYCFG_FHP_MPLL_DELAY_PHYB      (BIT4 + BIT5)   // 01b/01b/x/x MPLL Delay for PHYB
    #define CND003_PCIEPHYCFG_FHP_MPLL_CP_PHYB         0xF             // 3h/3h/x/x MPLL_CP for PHYB
#define CND003_PCIEPHYCFG_EPHY_PHYA_MPLL 0x62 // EPHY PHYA MPLL
    #define CND003_PCIEPHYCFG_FHP_MPLLMODE_PHYA        BIT7            // 0/0/x/x MPLL Mode for PHYA
    #define CND003_PCIEPHYCFG_FHP_MPLL_FLAGCK_EN_PHYA  BIT6            // 0/0/x/x MPLL Flag CK Enable for PHYA
    #define CND003_PCIEPHYCFG_FHP_MPLL_DELAY_PHYA      (BIT4 + BIT5)   // 01b/01b/x/x MPLL Delay for PHYA
    #define CND003_PCIEPHYCFG_FHP_MPLL_CP_PHYA         0xF             // 3h/3h/x/x MPLL_CP for PHYA
#define CND003_PCIEPHYCFG_EPHY_EP_MPLL 0x63 // EPHY EP MPLL
    #define CND003_PCIEPHYCFG_FHP_MPLLMODE         BIT7            // 0/0/x/x MPLL Mode for EP
    #define CND003_PCIEPHYCFG_FHP_MPLL_FLAGCK_EN   BIT6            // 0/0/x/x MPLL Flag CK Enable for EP
    #define CND003_PCIEPHYCFG_FHP_MPLL_DELAY       (BIT4 + BIT5)   // 01b/01b/x/x MPLL Delay for EP
    #define CND003_PCIEPHYCFG_FHP_MPLL_CP          0xF             // 3h/3h/x/x MPLL CP for EP
#define CND003_PCIEPHYCFG_EPHY0_TPLL0_G1_TPLL_BAND_PHYB_PHYA_EP 0x64 // EPHY0 TPLL0-G1 TPLL_BAND PHYB PHYA EP
    #define CND003_PCIEPHYCFG_FRP0_TPLL_BAND_G1_EP_1_0     (BIT6 + BIT7)   // 10b/10/x/x External Registers for TPLL VCO Operation Frequency
    #define CND003_PCIEPHYCFG_RSV_64                       (BIT4 + BIT5)   // 0/0/x/x Reserved
    #define CND003_PCIEPHYCFG_FRP0_TPLL_BAND_G1_PHYA_1_0   (BIT2 + BIT3)   // 10b/10/x/x External Registers for TPLL VCO Operation Frequency
    #define CND003_PCIEPHYCFG_FRP0_TPLL_BAND_G1_PHYB_1_0   (BIT0 + BIT1)   // 10b/10/x/x External Registers for TPLL VCO Operation Frequency
#define CND003_PCIEPHYCFG_EPHY0_TPLL1_G1_TPLL_BAND_PHYB_PHYA_EP 0x65 // EPHY0 TPLL1-G1 TPLL_BAND PHYB PHYA EP
    #define CND003_PCIEPHYCFG_FRP1_TPLL_BAND_G1_EP_1_0     (BIT6 + BIT7)   // 10b/10/x/x External Registers for TPLL VCO Operation Frequency
    #define CND003_PCIEPHYCFG_RSV_65                       (BIT4 + BIT5)   // 0/0/x/x Reserved
    #define CND003_PCIEPHYCFG_FRP1_TPLL_BAND_G1_PHYA_1_0   (BIT2 + BIT3)   // 10b/10/x/x External Registers for TPLL VCO Operation Frequency
    #define CND003_PCIEPHYCFG_FRP1_TPLL_BAND_G1_PHYB_1_0   (BIT0 + BIT1)   // 10b/10/x/x External Registers for TPLL VCO Operation Frequency
#define CND003_PCIEPHYCFG_EPHY0_TPLL0_G2_TPLL_BAND_PHYB_PHYA_EP 0x66 // EPHY0 TPLL0-G2 TPLL_BAND PHYB PHYA EP
    #define CND003_PCIEPHYCFG_FRP0_TPLL_BAND_G2_EP_1_0     (BIT6 + BIT7)   // 10b/10/x/x External Registers for TPLL VCO Operation Frequency
    #define CND003_PCIEPHYCFG_RSV_66                       (BIT4 + BIT5)   // 0/0/x/x Reserved
    #define CND003_PCIEPHYCFG_FRP0_TPLL_BAND_G2_PHYA_1_0   (BIT2 + BIT3)   // 10b/10/x/x External Registers for TPLL VCO Operation Frequency
    #define CND003_PCIEPHYCFG_FRP0_TPLL_BAND_G2_PHYB_1_0   (BIT0 + BIT1)   // 10b/10/x/x External Registers for TPLL VCO Operation Frequency
#define CND003_PCIEPHYCFG_EPHY0_TPLL1_G2_TPLL_BAND_PHYB_PHYA_EP 0x67 // EPHY0 TPLL1-G2 TPLL_BAND PHYB PHYA EP
    #define CND003_PCIEPHYCFG_FRP1_TPLL_BAND_G2_EP_1_0     (BIT6 + BIT7)   // 10b/10/x/x External Registers for TPLL VCO Operation Frequency
    #define CND003_PCIEPHYCFG_RSV_67                       (BIT4 + BIT5)   // 0/0/x/x Reserved
    #define CND003_PCIEPHYCFG_FRP1_TPLL_BAND_G2_PHYA_1_0   (BIT2 + BIT3)   // 10b/10/x/x External Registers for TPLL VCO Operation Frequency
    #define CND003_PCIEPHYCFG_FRP1_TPLL_BAND_G2_PHYB_1_0   (BIT0 + BIT1)   // 10b/10/x/x External Registers for TPLL VCO Operation Frequency
#define CND003_PCIEPHYCFG_EPHY0_TPLL0_G3_TPLL_BAND_PHYB_PHYA_EP 0x68 // EPHY0 TPLL0-G3 TPLL_BAND PHYB PHYA EP
    #define CND003_PCIEPHYCFG_FRP0_TPLL_BAND_G3_EP_1_0     (BIT6 + BIT7)   // 11b/11/x/x External Registers for TPLL VCO Operation Frequency
    #define CND003_PCIEPHYCFG_RSV_68                       (BIT4 + BIT5)   // 0/0/x/x Reserved
    #define CND003_PCIEPHYCFG_FRP0_TPLL_BAND_G3_PHYA_1_0   (BIT2 + BIT3)   // 11b/11/x/x External Registers for TPLL VCO Operation Frequency
    #define CND003_PCIEPHYCFG_FRP0_TPLL_BAND_G3_PHYB_1_0   (BIT0 + BIT1)   // 11b/11/x/x External Registers for TPLL VCO Operation Frequency
#define CND003_PCIEPHYCFG_EPHY0_TPLL1_G3_TPLL_BAND_PHYB_PHYA_EP 0x69 // EPHY0 TPLL1-G3 TPLL_BAND PHYB PHYA EP
    #define CND003_PCIEPHYCFG_FRP1_TPLL_BAND_G3_EP_1_0     (BIT6 + BIT7)   // 11b/11/x/x External Registers for TPLL VCO Operation Frequency
    #define CND003_PCIEPHYCFG_RSV_69                       (BIT4 + BIT5)   // 0/0/x/x Reserved
    #define CND003_PCIEPHYCFG_FRP1_TPLL_BAND_G3_PHYA_1_0   (BIT2 + BIT3)   // 11b/11/x/x External Registers for TPLL VCO Operation Frequency
    #define CND003_PCIEPHYCFG_FRP1_TPLL_BAND_G3_PHYB_1_0   (BIT0 + BIT1)   // 11b/11/x/x External Registers for TPLL VCO Operation Frequency
#define CND003_PCIEPHYCFG_EPHY0_TPLL0_G1_G2_G3_TPLL_BAND 0x6A // EPHY0 TPLL0-G1, G2, G3 TPLL_BAND
    #define CND003_PCIEPHYCFG_RSVPCIEPHYCFG_6A PCIEPHYCFG_EPHY0_TPLL0_G1_G2_G3_TPLL_BAND // 0/0/x/x Reserved
#define CND003_PCIEPHYCFG_EPHY0_TPLL1_G1_G2_G3_TPLL_BAND 0x6B // EPHY0 TPLL1-G1, G2, G3 TPLL_BAND
    #define CND003_PCIEPHYCFG_RSVPCIEPHYCFG_6B PCIEPHYCFG_EPHY0_TPLL1_G1_G2_G3_TPLL_BAND // 0/0/x/x Reserved
#define CND003_PCIEPHYCFG_RESERVED_FOR_ECO 0x6C // Reserved for ECO
    #define CND003_PCIEPHYCFG_RSVPCIEPHYCFG_ECO_53 PCIEPHYCFG_RESERVED_FOR_ECO // 0/0/x/x Reserved for ECO
#define CND003_PCIEPHYCFG_EPHY0_MAIN0_RTN_SET_ENABLE_PHYB 0x6D // EPHY0 MAIN0 (RTN Set Enable) PHYB
    #define CND003_PCIEPHYCFG_FHP1_TPLL_FSEL_PHYB_1_0  (BIT6 + BIT7)   // 01b/01/x/x TPLL1 LC Frequency Setting
    #define CND003_PCIEPHYCFG_FHP1_TPLL_ISEL_PHYB_1_0  (BIT4 + BIT5)   // 00b/0/x/x TPLL1 LC bias Setting
    #define CND003_PCIEPHYCFG_FH_RTNBIST_PHYB_1_0      (BIT2 + BIT3)   // 00b/0/x/x Verify Digital/Analog Circuit Functionalities
    #define CND003_PCIEPHYCFG_FHP_RTNRXSETEN_PHYB      BIT1            // 0/0/x/x RX Resistance Set 0 Enable
    #define CND003_PCIEPHYCFG_FHP_RTNTXSETEN_PHYB      BIT0            // 0/0/x/x TX Resistance Set 0 Enable
#define CND003_PCIEPHYCFG_EPHY0_MAIN0_RTN0_SET_PHYB 0x6E // EPHY0 MAIN0 (RTN0 Set) PHYB
    #define CND003_PCIEPHYCFG_FHP_RTNRXSET_PHYB_3_0    0xF0    // 1000b/1000/x/x RX Resistance Set Value 0
    #define CND003_PCIEPHYCFG_FHP_RTNTXSET_PHYB_3_0    0xF     // 1000b/1000/x/x TX Resistance Set Value 0
#define CND003_PCIEPHYCFG_EPHY0_MAIN0_RTN_SET_ENABLE_PHYA 0x6F // EPHY0 MAIN0 (RTN Set Enable) PHYA
    #define CND003_PCIEPHYCFG_FHP1_TPLL_FSEL_PHYA_1_0  (BIT6 + BIT7)   // 01b/01/x/x TPLL1 LC Frequency Setting
    #define CND003_PCIEPHYCFG_FHP1_TPLL_ISEL_PHYA_1_0  (BIT4 + BIT5)   // 00b/0/x/x TPLL1 LC bias Setting
    #define CND003_PCIEPHYCFG_FH_RTNBIST_PHYA_1_0      (BIT2 + BIT3)   // 00b/0/x/x Verify Digital/Analog Circuit Functionalities
    #define CND003_PCIEPHYCFG_FHP_RTNRXSETEN_PHYA      BIT1            // 0/0/x/x RX Resistance Set 0 Enable
    #define CND003_PCIEPHYCFG_FHP_RTNTXSETEN_PHYA      BIT0            // 0/0/x/x TX Resistance Set 0 Enable
#define CND003_PCIEPHYCFG_EPHY0_MAIN0_RTN0_SET_PHYA 0x70 // EPHY0 MAIN0 (RTN0 Set) PHYA
    #define CND003_PCIEPHYCFG_FHP_RTNRXSET_PHYA_3_0    0xF0    // 1000b/1000/x/x RX Resistance Set Value 0
    #define CND003_PCIEPHYCFG_FHP_RTNTXSET_PHYA_3_0    0xF     // 1000b/1000/x/x TX Resistance Set Value 0
#define CND003_PCIEPHYCFG_EPHY0_MAIN0_RTN_SET_ENABLE 0x71 // EPHY0 MAIN0 (RTN Set Enable)
    #define CND003_PCIEPHYCFG_RSV_71 PCIEPHYCFG_EPHY0_MAIN0_RTN_SET_ENABLE // 0/0/x/x Reserved
#define CND003_PCIEPHYCFG_EPHY0_MAIN0_RTN0_SET 0x72 // EPHY0 MAIN0 (RTN0 Set)
    #define CND003_PCIEPHYCFG_RSV_72 PCIEPHYCFG_EPHY0_MAIN0_RTN0_SET // 0/0/x/x Reserved
#define CND003_PCIEPHYCFG_EPHY0_MAIN0_RTN_SET_ENABLE_EP 0x73 // EPHY0 MAIN0 (RTN Set Enable) EP
    #define CND003_PCIEPHYCFG_FHP1_TPLL_FSEL_1_0   (BIT6 + BIT7)   // 01b/01/x/x TPLL1 LC Frequency Setting
    #define CND003_PCIEPHYCFG_FHP1_TPLL_ISEL_1_0   (BIT4 + BIT5)   // 00b/0/x/x TPLL1 LC bias Setting
    #define CND003_PCIEPHYCFG_FH_RTNBIST_1_0       (BIT2 + BIT3)   // 00b/0/x/x Verify Digital/Analog Circuit Functionalities
    #define CND003_PCIEPHYCFG_FHP_RTNRXSETEN       BIT1            // 0/0/x/x RX Resistance Set 0 Enable
    #define CND003_PCIEPHYCFG_FHP_RTNTXSETEN       BIT0            // 0/0/x/x TX Resistance Set 0 Enable
#define CND003_PCIEPHYCFG_EPHY0_MAIN0_RTN0_SET_EP 0x74 // EPHY0 MAIN0 (RTN0 Set) EP
    #define CND003_PCIEPHYCFG_FHP_RTNRXSET_3_0 0xF0    // 1000b/1000/x/x RX Resistance Set Value 0
    #define CND003_PCIEPHYCFG_FHP_RTNTXSET_3_0 0xF     // 1000b/1000/x/x TX Resistance Set Value 0
#define CND003_PCIEPHYCFG_EPHY0_MAIN0_RTN_SET_ENABLE_Z1 0x75 // EPHY0 MAIN0 (RTN Set Enable)
    #define CND003_PCIEPHYCFG_RSV_75 PCIEPHYCFG_EPHY0_MAIN0_RTN_SET_ENABLE_Z1 // 0/0/x/x Reserved
#define CND003_PCIEPHYCFG_EPHY0_MAIN0_RTN0_SET_Z1 0x76 // EPHY0 MAIN0 (RTN0 Set)
    #define CND003_PCIEPHYCFG_RSV_76 PCIEPHYCFG_EPHY0_MAIN0_RTN0_SET_Z1 // 0/0/x/x Reserved
#define CND003_PCIEPHYCFG_EPHY_ENTERING_TEST_MODE_BY_SETTING_TO_1_FHP_EPHYMSTEN_PHYB_EP 0x77 // EPHY Entering Test Mode by Setting to 1 (FHP_EPHYMSTEN) PHYB-EP
    #define CND003_PCIEPHYCFG_RSVPCIEPHYCFG_77     (BIT5 + BIT6 + BIT7)    // 0/x/x/x Reserved
    #define CND003_PCIEPHYCFG_FHP_EPHYMSTEN        BIT4                    // 0/0/x/x Force to Turn on All Functions in Master Block when EPHY Testing
    #define CND003_PCIEPHYCFG_RSV_77_3             BIT3                    // 0/0/x/x Reserved
    #define CND003_PCIEPHYCFG_RSV_77_2             BIT2                    // 0/0/x/x Reserved
    #define CND003_PCIEPHYCFG_FHP_EPHYMSTEN_PHYA   BIT1                    // 0/0/x/x Force to Turn on All Functions in Master Block when EPHY Testing
    #define CND003_PCIEPHYCFG_FHP_EPHYMSTEN_PHYB   BIT0                    // 0/0/x/x Force to Turn on All Functions in Master Block when EPHY Testing
#define CND003_PCIEPHYCFG_TPLL1_VCO_SWING_TUNING_FHP1_TPLL_SWSEL_PHYB_PHYA 0x78 // TPLL1 VCO Swing Tuning (FHP1_TPLL_SWSEL) PHYB PHYA
    #define CND003_PCIEPHYCFG_RSVPCIEPHYCFG_78         (BIT6 + BIT7)           // 0/x/x/x Reserved
    #define CND003_PCIEPHYCFG_FHP1_TPLL_SWSEL_PHYB_2_0 (BIT3 + BIT4 + BIT5)    // 101b/101/x/x TPLL1 VCO Swing Tuning
    #define CND003_PCIEPHYCFG_FHP1_TPLL_SWSEL_PHYA_2_0 (BIT0 + BIT1 + BIT2)    // 101b/101/x/x TPLL1 VCO Swing Tuning
#define CND003_PCIEPHYCFG_TPLL1_VCO_SWING_TUNING_FHP1_TPLL_SWSEL_EP 0x79 // TPLL1 VCO Swing Tuning (FHP1_TPLL_SWSEL) EP
    #define CND003_PCIEPHYCFG_RSVPCIEPHYCFG_79     0xF8                    // 0/x/x/x Reserved
    #define CND003_PCIEPHYCFG_FHP1_TPLL_SWSEL_2_0  (BIT0 + BIT1 + BIT2)    // 101b/101/x/x TPLL1 VCO swing tuning
#define CND003_PCIEPHYCFG_TPLL1_VCO_SWING_TUNING_FHP1_TPLL_SWSEL_PHYC 0x7A // TPLL1 VCO Swing Tuning (FHP1_TPLL_SWSEL) PHYC
    #define CND003_PCIEPHYCFG_RSVPCIEPHYCFG_7A PCIEPHYCFG_TPLL1_VCO_SWING_TUNING_FHP1_TPLL_SWSEL_PHYC // 0/x/x/x Reserved
#define CND003_PCIEPHYCFG_FHP_TPLLPD_TPLL_PWR_DOWN_EP_PHYA_PHYB 0x7B // FHP TPLLPD (TPLL Power Down) EP, PHYA, PHYB
    #define CND003_PCIEPHYCFG_FHP1_TPLLPD      BIT7    // 0/0/x/x TPLL1 Power Down Control
    #define CND003_PCIEPHYCFG_FHP0_TPLLPD      BIT6    // 0/0/x/x TPLL0 Power Down Control
    #define CND003_PCIEPHYCFG_FHP1_TPLLPD_PHYD BIT5    // 0/0/x/x Reserved
    #define CND003_PCIEPHYCFG_FHP0_TPLLPD_PHYD BIT4    // 0/0/x/x Reserved
    #define CND003_PCIEPHYCFG_FHP1_TPLLPD_PHYA BIT3    // 0/0/x/x TPLL1 Power Down Control
    #define CND003_PCIEPHYCFG_FHP0_TPLLPD_PHYA BIT2    // 0/0/x/x TPLL0 Power Down Control
    #define CND003_PCIEPHYCFG_FHP1_TPLLPD_PHYB BIT1    // 0/0/x/x TPLL1 Power Down Control
    #define CND003_PCIEPHYCFG_FHP0_TPLLPD_PHYB BIT0    // 0/0/x/x TPLL0 Power Down Control
#define CND003_PCIEPHYCFG_FHP_TPLLPD_TPLL_PWR_DOWN_PHYC 0x7C // FHP TPLLPD (TPLL Power Down) PHYC
    #define CND003_PCIEPHYCFG_RSVPCIEPHYCFG_7C PCIEPHYCFG_FHP_TPLLPD_TPLL_PWR_DOWN_PHYC // 0/0/x/x Reserved
#define CND003_PCIEPHYCFG_PWR_STATE_CTL_FOR_LANE00 0x7D // Power State Control for Lane00
    #define CND003_PCIEPHYCFG_RSV_7D PCIEPHYCFG_PWR_STATE_CTL_FOR_LANE00 // 0/x/x/x Reserved
#define CND003_PCIEPHYCFG_PWR_STATE_CTL_FOR_LANE04_PHYA 0x7E // Power State Control for Lane04 PHYA
    #define CND003_PCIEPHYCFG_RSVPCIEPHYCFG_7E_7       BIT7    // 0/x/x/x Reserved
    #define CND003_PCIEPHYCFG_FRP04_TXEIDLESETB_PHYA   BIT6    // 0/0/x/x TX Electrical Idle Control
    #define CND003_PCIEPHYCFG_FRP04_TXEIDLESETEN_PHYA  BIT5    // 0/0/x/x External Register of TX Electrical Idle Register Set
    #define CND003_PCIEPHYCFG_FRP04_TXPWRSET_PHYA_3_0  0x1E    // 0/0/x/x TX Power Status Set
    #define CND003_PCIEPHYCFG_FRP04_TXPWRSETEN_PHYA    BIT0    // 0/0/x/x TX Power Status Set Enable
#define CND003_PCIEPHYCFG_PWR_STATE_CTL_FOR_LANE00_PHYA 0x7F // Power State Control for Lane00 PHYA
    #define CND003_PCIEPHYCFG_RSVPCIEPHYCFG_7F_7       BIT7    // 0/x/x/x Reserved
    #define CND003_PCIEPHYCFG_FRP00_TXEIDLESETB_PHYA   BIT6    // 0/0/x/x TX Electrical Idle Control
    #define CND003_PCIEPHYCFG_FRP00_TXEIDLESETEN_PHYA  BIT5    // 0/0/x/x External Register of TX Electrical Idle Register Set
    #define CND003_PCIEPHYCFG_FRP00_TXPWRSET_PHYA_3_0  0x1E    // 0/0/x/x TX Power Status Set
    #define CND003_PCIEPHYCFG_FRP00_TXPWRSETEN_PHYA    BIT0    // 0/0/x/x TX Power Status Set Enable
#define CND003_PCIEPHYCFG_PWR_STATE_CTL_FOR_LANE01_PHYA 0x80 // Power State Control for Lane01 PHYA
    #define CND003_PCIEPHYCFG_RSVPCIEPHYCFG_80_7       BIT7    // 0/x/x/x Reserved
    #define CND003_PCIEPHYCFG_FRP01_TXEIDLESETB_PHYA   BIT6    // 0/0/x/x TX Electrical Idle Control
    #define CND003_PCIEPHYCFG_FRP01_TXEIDLESETEN_PHYA  BIT5    // 0/0/x/x External Register of TX Electrical Idle Register Set
    #define CND003_PCIEPHYCFG_FRP01_TXPWRSET_PHYA_3_0  0x1E    // 0/0/x/x TX Power Status Set
    #define CND003_PCIEPHYCFG_FRP01_TXPWRSETEN_PHYA    BIT0    // 0/0/x/x TX Power Status Set Enable
#define CND003_PCIEPHYCFG_PWR_STATE_CTL_FOR_LANE02_PHYA 0x81 // Power State Control for Lane02 PHYA
    #define CND003_PCIEPHYCFG_RSVPCIEPHYCFG_81_7       BIT7    // 0/x/x/x Reserved
    #define CND003_PCIEPHYCFG_FRP02_TXEIDLESETB_PHYA   BIT6    // 0/0/x/x TX Electrical Idle Control
    #define CND003_PCIEPHYCFG_FRP02_TXEIDLESETEN_PHYA  BIT5    // 0/0/x/x External Register of TX Electrical Idle Register Set
    #define CND003_PCIEPHYCFG_FRP02_TXPWRSET_PHYA_3_0  0x1E    // 0/0/x/x TX Power Status Set
    #define CND003_PCIEPHYCFG_FRP02_TXPWRSETEN_PHYA    BIT0    // 0/0/x/x TX Power Status Set Enable
#define CND003_PCIEPHYCFG_PWR_STATE_CTL_FOR_LANE03_PHYA 0x82 // Power State Control for Lane03 PHYA
    #define CND003_PCIEPHYCFG_RSVPCIEPHYCFG_82_7       BIT7    // 0/x/x/x Reserved
    #define CND003_PCIEPHYCFG_FRP03_TXEIDLESETB_PHYA   BIT6    // 0/0/x/x TX Electrical Idle Control
    #define CND003_PCIEPHYCFG_FRP03_TXEIDLESETEN_PHYA  BIT5    // 0/0/x/x External Register of TX Electrical Idle Register Set
    #define CND003_PCIEPHYCFG_FRP03_TXPWRSET_PHYA_3_0  0x1E    // 0/0/x/x TX Power Status Set
    #define CND003_PCIEPHYCFG_FRP03_TXPWRSETEN_PHYA    BIT0    // 0/0/x/x TX Power Status Set Enable
#define CND003_PCIEPHYCFG_PWR_STATE_CTL_FOR_LANE00_PHYB 0x83 // Power State Control for Lane00 PHYB
    #define CND003_PCIEPHYCFG_RSVPCIEPHYCFG_83_7       BIT7    // 0/x/x/x Reserved
    #define CND003_PCIEPHYCFG_FRP00_TXEIDLESETB_PHYB   BIT6    // 0/0/x/x TX Electrical Idle Control
    #define CND003_PCIEPHYCFG_FRP00_TXEIDLESETEN_PHYB  BIT5    // 0/0/x/x External Register of TX Electrical Idle Register Set
    #define CND003_PCIEPHYCFG_FRP00_TXPWRSET_PHYB_3_0  0x1E    // 0/0/x/x TX Power Status Set
    #define CND003_PCIEPHYCFG_FRP00_TXPWRSETEN_PHYB    BIT0    // 0/0/x/x TX Power Status Set Enable
#define CND003_PCIEPHYCFG_PWR_STATE_CTL_FOR_LANE01_PHYB 0x84 // Power State Control for Lane01 PHYB
    #define CND003_PCIEPHYCFG_RSVPCIEPHYCFG_84_7       BIT7    // 0/x/x/x Reserved
    #define CND003_PCIEPHYCFG_FRP01_TXEIDLESETB_PHYB   BIT6    // 0/0/x/x TX Electrical Idle Control
    #define CND003_PCIEPHYCFG_FRP01_TXEIDLESETEN_PHYB  BIT5    // 0/0/x/x External Register of TX Electrical Idle Register Set
    #define CND003_PCIEPHYCFG_FRP01_TXPWRSET_PHYB_3_0  0x1E    // 0/0/x/x TX Power Status Set
    #define CND003_PCIEPHYCFG_FRP01_TXPWRSETEN_PHYB    BIT0    // 0/0/x/x TX Power Status Set Enable
#define CND003_PCIEPHYCFG_PWR_STATE_CTL_FOR_LANE02_PHYB 0x85 // Power State Control for Lane02 PHYB
    #define CND003_PCIEPHYCFG_RSVPCIEPHYCFG_85_7       BIT7    // 0/x/x/x Reserved
    #define CND003_PCIEPHYCFG_FRP02_TXEIDLESETB_PHYB   BIT6    // 0/0/x/x TX Electrical Idle Control
    #define CND003_PCIEPHYCFG_FRP02_TXEIDLESETEN_PHYB  BIT5    // 0/0/x/x External Register of TX Electrical Idle Register Set
    #define CND003_PCIEPHYCFG_FRP02_TXPWRSET_PHYB_3_0  0x1E    // 0/0/x/x TX Power Status Set
    #define CND003_PCIEPHYCFG_FRP02_TXPWRSETEN_PHYB    BIT0    // 0/0/x/x TX Power Status Set Enable
#define CND003_PCIEPHYCFG_PWR_STATE_CTL_FOR_LANE03_PHYB 0x86 // Power State Control for Lane03 PHYB
    #define CND003_PCIEPHYCFG_RSVPCIEPHYCFG_86_7       BIT7    // 0/x/x/x Reserved
    #define CND003_PCIEPHYCFG_FRP03_TXEIDLESETB_PHYB   BIT6    // 0/0/x/x TX Electrical Idle Set
    #define CND003_PCIEPHYCFG_FRP03_TXEIDLESETEN_PHYB  BIT5    // 0/0/x/x External Register of TX Electrical Idle Register Set
    #define CND003_PCIEPHYCFG_FRP03_TXPWRSET_PHYB_3_0  0x1E    // 0/0/x/x TX Power Status Set
    #define CND003_PCIEPHYCFG_FRP03_TXPWRSETEN_PHYB    BIT0    // 0/0/x/x TX Power Status Set Enable
#define CND003_PCIEPHYCFG_PWR_STATE_CTL_FOR_LANE00_EP 0x87 // Power State Control for Lane00 EP
    #define CND003_PCIEPHYCFG_RSVPCIEPHYCFG_87_7       BIT7    // 0/x/x/x Reserved
    #define CND003_PCIEPHYCFG_FRP00_TXEIDLESETB_EP     BIT6    // 0/0/x/x TX Electrical Idle Control
    #define CND003_PCIEPHYCFG_FRP00_TXEIDLESETEN_EP    BIT5    // 0/0/x/x External Register of TX Electrical Idle Register Set
    #define CND003_PCIEPHYCFG_FRP00_TXPWRSET_EP_3_0    0x1E    // 0/0/x/x TX Power Status Set
    #define CND003_PCIEPHYCFG_FRP00_TXPWRSETEN_EP      BIT0    // 0/0/x/x TX Power Status Set Enable
#define CND003_PCIEPHYCFG_PWR_STATE_CTL_FOR_LANE01_EP 0x88 // Power State Control for Lane01 EP
    #define CND003_PCIEPHYCFG_RSVPCIEPHYCFG_88_7       BIT7    // 0/x/x/x Reserved
    #define CND003_PCIEPHYCFG_FRP01_TXEIDLESETB_EP     BIT6    // 0/0/x/x TX Electrical Idle Control
    #define CND003_PCIEPHYCFG_FRP01_TXEIDLESETEN_EP    BIT5    // 0/0/x/x External Register of TX Electrical Idle Register Set
    #define CND003_PCIEPHYCFG_FRP01_TXPWRSET_EP_3_0    0x1E    // 0/0/x/x TX Power Status Set
    #define CND003_PCIEPHYCFG_FRP01_TXPWRSETEN_EP      BIT0    // 0/0/x/x TX Power Status Set Enable
#define CND003_PCIEPHYCFG_PWR_STATE_CTL_FOR_LANE02_EP 0x89 // Power State Control for Lane02 EP
    #define CND003_PCIEPHYCFG_RSVPCIEPHYCFG_89_7       BIT7    // 0/x/x/x Reserved
    #define CND003_PCIEPHYCFG_FRP02_TXEIDLESETB_EP     BIT6    // 0/0/x/x TX Electrical Idle Control
    #define CND003_PCIEPHYCFG_FRP02_TXEIDLESETEN_EP    BIT5    // 0/0/x/x External Register of TX Electrical Idle Register Set
    #define CND003_PCIEPHYCFG_FRP02_TXPWRSET_EP_3_0    0x1E    // 0/0/x/x TX Power Status Set
    #define CND003_PCIEPHYCFG_FRP02_TXPWRSETEN_EP      BIT0    // 0/0/x/x TX Power Status Set Enable
#define CND003_PCIEPHYCFG_PWR_STATE_CTL_FOR_LANE03_EP 0x8A // Power State Control for Lane03 EP
    #define CND003_PCIEPHYCFG_RSVPCIEPHYCFG_8A_7       BIT7    // 0/x/x/x Reserved
    #define CND003_PCIEPHYCFG_FRP03_TXEIDLESETB_EP     BIT6    // 0/0/x/x TX Electrical Idle Control
    #define CND003_PCIEPHYCFG_FRP03_TXEIDLESETEN_EP    BIT5    // 0/0/x/x External Register of TX Electrical Idle Register Set
    #define CND003_PCIEPHYCFG_FRP03_TXPWRSET_EP_3_0    0x1E    // 0/0/x/x TX Power Status Set
    #define CND003_PCIEPHYCFG_FRP03_TXPWRSETEN_EP      BIT0    // 0/0/x/x TX Power Status Set Enable
#define CND003_PCIEPHYCFG_PWR_STATE_CTL_FOR_LANE00_PHYC 0x8B // Power State Control for Lane00 PHYC
    #define CND003_PCIEPHYCFG_RSVPCIEPHYCFG_8B_7 PCIEPHYCFG_PWR_STATE_CTL_FOR_LANE00_PHYC // 0/x/x/x Reserved
#define CND003_PCIEPHYCFG_PWR_STATE_CTL_FOR_LANE01_PHYC 0x8C // Power State Control for Lane01 PHYC
    #define CND003_PCIEPHYCFG_RSVPCIEPHYCFG_8C_7 PCIEPHYCFG_PWR_STATE_CTL_FOR_LANE01_PHYC // 0/x/x/x Reserved
#define CND003_PCIEPHYCFG_RESERVED 0x8D // Reserved
    #define CND003_PCIEPHYCFG_RSVPCIEPHYCFG_8D PCIEPHYCFG_RESERVED // 0/x/x/x Reserved
#define CND003_PCIEPHYCFG_RESERVED_Z1 0x90 // Reserved
    #define CND003_PCIEPHYCFG_RSVPCIEPHYCFG_90_7   0xF0            // 0/x/x/x Reserved
    #define CND003_PCIEPHYCFG_FRP_SATA_TXSET_1_0   (BIT2 + BIT3)   // 0/0/x/x Reserved
    #define CND003_PCIEPHYCFG_FRP_SATA_TXSET_EN    BIT1            // 0/0/x/x Reserved
    #define CND003_PCIEPHYCFG_RSVPCIEPHYCFG_90_1   BIT0            // 0/x/x/x Reserved
#define CND003_PCIEPHYCFG_CM_AND_DT_DRIVER_SPEED_SET_LANE00 0x91 // CM and DT Driver Speed Set Lane00
    #define CND003_PCIEPHYCFG_RSVPCIEPHYCFG_91_7 PCIEPHYCFG_CM_AND_DT_DRIVER_SPEED_SET_LANE00 // 0/x/x/x Reserved
#define CND003_PCIEPHYCFG_CM_AND_DT_DRIVER_SPEED_SET_LANE04_PHYA 0x92 // CM and DT Driver Speed Set Lane04 PHYA
    #define CND003_PCIEPHYCFG_RSVPCIEPHYCFG_92_7       0xF0                    // 0/x/x/x Reserved
    #define CND003_PCIEPHYCFG_FRP04_SPEEDSET_PHYA_2_0  (BIT1 + BIT2 + BIT3)    // 0/0/x/x Speed Manual Set Register
    #define CND003_PCIEPHYCFG_FRP04_SPEEDSETEN_PHYA    BIT0                    // 0/0/x/x Speed Manual Set Enable
#define CND003_PCIEPHYCFG_CM_AND_DT_DRIVER_SPEED_SET_LANE00_PHYA 0x93 // CM and DT Driver Speed Set Lane00 PHYA
    #define CND003_PCIEPHYCFG_RSVPCIEPHYCFG_93_7       0xF0                    // 0/x/x/x Reserved
    #define CND003_PCIEPHYCFG_FRP00_SPEEDSET_PHYA_2_0  (BIT1 + BIT2 + BIT3)    // 0/0/x/x Speed Manual Set Register
    #define CND003_PCIEPHYCFG_FRP00_SPEEDSETEN_PHYA    BIT0                    // 0/0/x/x Speed Manual Set Enable
#define CND003_PCIEPHYCFG_CM_AND_DT_DRIVER_SPEED_SET_LANE01_PHYA 0x94 // CM and DT Driver Speed Set Lane01 PHYA
    #define CND003_PCIEPHYCFG_RSVPCIEPHYCFG_94_7       0xF0                    // 0/x/x/x Reserved
    #define CND003_PCIEPHYCFG_FRP01_SPEEDSET_PHYA_2_0  (BIT1 + BIT2 + BIT3)    // 0/0/x/x Speed Manual Set Register
    #define CND003_PCIEPHYCFG_FRP01_SPEEDSETEN_PHYA    BIT0                    // 0/0/x/x Speed Manual Set Enable
#define CND003_PCIEPHYCFG_CM_AND_DT_DRIVER_SPEED_SET_LANE02_PHYA 0x95 // CM and DT Driver Speed Set Lane02 PHYA
    #define CND003_PCIEPHYCFG_RSVPCIEPHYCFG_95_7       0xF0                    // 0/x/x/x Reserved
    #define CND003_PCIEPHYCFG_FRP02_SPEEDSET_PHYA_2_0  (BIT1 + BIT2 + BIT3)    // 0/0/x/x Speed Manual Set Register
    #define CND003_PCIEPHYCFG_FRP02_SPEEDSETEN_PHYA    BIT0                    // 0/0/x/x Speed Manual Set Enable
#define CND003_PCIEPHYCFG_CM_AND_DT_DRIVER_SPEED_SET_LANE03_PHYA 0x96 // CM and DT Driver Speed Set Lane03 PHYA
    #define CND003_PCIEPHYCFG_RSVPCIEPHYCFG_96_7       0xF0                    // 0/x/x/x Reserved
    #define CND003_PCIEPHYCFG_FRP03_SPEEDSET_PHYA_2_0  (BIT1 + BIT2 + BIT3)    // 0/0/x/x Speed Manual Set Register
    #define CND003_PCIEPHYCFG_FRP03_SPEEDSETEN_PHYA    BIT0                    // 0/0/x/x Speed Manual Set Enable
#define CND003_PCIEPHYCFG_CM_AND_DT_DRIVER_SPEED_SET_LANE00_PHYB 0x97 // CM and DT Driver Speed Set Lane00 PHYB
    #define CND003_PCIEPHYCFG_RSVPCIEPHYCFG_97_7       0xF0                    // 0/x/x/x Reserved
    #define CND003_PCIEPHYCFG_FRP00_SPEEDSET_PHYB_2_0  (BIT1 + BIT2 + BIT3)    // 0/0/x/x Speed Manual Set Register
    #define CND003_PCIEPHYCFG_FRP00_SPEEDSETEN_PHYB    BIT0                    // 0/0/x/x Speed Manual Set Enable
#define CND003_PCIEPHYCFG_CM_AND_DT_DRIVER_SPEED_SET_LANE01_PHYB 0x98 // CM and DT Driver Speed Set Lane01 PHYB
    #define CND003_PCIEPHYCFG_RSVPCIEPHYCFG_98_7       0xF0                    // 0/x/x/x Reserved
    #define CND003_PCIEPHYCFG_FRP01_SPEEDSET_PHYB_2_0  (BIT1 + BIT2 + BIT3)    // 0/0/x/x Speed Manual Set Register
    #define CND003_PCIEPHYCFG_FRP01_SPEEDSETEN_PHYB    BIT0                    // 0/0/x/x Speed Manual Set Enable
#define CND003_PCIEPHYCFG_CM_AND_DT_DRIVER_SPEED_SET_LANE02_PHYB 0x99 // CM and DT Driver Speed Set Lane02 PHYB
    #define CND003_PCIEPHYCFG_RSVPCIEPHYCFG_99_7       0xF0                    // 0/x/x/x Reserved
    #define CND003_PCIEPHYCFG_FRP02_SPEEDSET_PHYB_2_0  (BIT1 + BIT2 + BIT3)    // 0/0/x/x Speed Manual Set Register
    #define CND003_PCIEPHYCFG_FRP02_SPEEDSETEN_PHYB    BIT0                    // 0/0/x/x Speed Manual Set Enable
#define CND003_PCIEPHYCFG_CM_AND_DT_DRIVER_SPEED_SET_LANE03_PHYB 0x9A // CM and DT Driver Speed Set Lane03 PHYB
    #define CND003_PCIEPHYCFG_RSVPCIEPHYCFG_9A_7       0xF0                    // 0/x/x/x Reserved
    #define CND003_PCIEPHYCFG_FRP03_SPEEDSET_PHYB_2_0  (BIT1 + BIT2 + BIT3)    // 0/0/x/x Speed Manual Set Register
    #define CND003_PCIEPHYCFG_FRP03_SPEEDSETEN_PHYB    BIT0                    // 0/0/x/x Speed Manual Set Enable
#define CND003_PCIEPHYCFG_CM_AND_DT_DRIVER_SPEED_SET_LANE00_EP 0x9B // CM and DT Driver Speed Set Lane00 EP
    #define CND003_PCIEPHYCFG_RSVPCIEPHYCFG_9B_7       0xF0                    // 0/x/x/x Reserved
    #define CND003_PCIEPHYCFG_FRP00_SPEEDSET_EP_2_0    (BIT1 + BIT2 + BIT3)    // 0/0/x/x Speed Manual Set Register
    #define CND003_PCIEPHYCFG_FRP00_SPEEDSETEN_EP      BIT0                    // 0/0/x/x Speed Manual Set Enable
#define CND003_PCIEPHYCFG_CM_AND_DT_DRIVER_SPEED_SET_LANE01_EP 0x9C // CM and DT Driver Speed Set Lane01 EP
    #define CND003_PCIEPHYCFG_RSVPCIEPHYCFG_9C_7       0xF0                    // 0/x/x/x Reserved
    #define CND003_PCIEPHYCFG_FRP01_SPEEDSET_EP_2_0    (BIT1 + BIT2 + BIT3)    // 0/0/x/x Speed Manual Set Register
    #define CND003_PCIEPHYCFG_FRP01_SPEEDSETEN_EP      BIT0                    // 0/0/x/x Speed Manual Set Enable
#define CND003_PCIEPHYCFG_CM_AND_DT_DRIVER_SPEED_SET_LANE02_EP 0x9D // CM and DT Driver Speed Set Lane02 EP
    #define CND003_PCIEPHYCFG_RSVPCIEPHYCFG_9D_7       0xF0                    // 0/x/x/x Reserved
    #define CND003_PCIEPHYCFG_FRP02_SPEEDSET_EP_2_0    (BIT1 + BIT2 + BIT3)    // 0/0/x/x Speed Manual Set Register
    #define CND003_PCIEPHYCFG_FRP02_SPEEDSETEN_EP      BIT0                    // 0/0/x/x Speed Manual Set Enable
#define CND003_PCIEPHYCFG_CM_AND_DT_DRIVER_SPEED_SET_LANE03_EP 0x9E // CM and DT Driver Speed Set Lane03 EP
    #define CND003_PCIEPHYCFG_RSVPCIEPHYCFG_9E_7       0xF0                    // 0/x/x/x Reserved
    #define CND003_PCIEPHYCFG_FRP03_SPEEDSET_EP_2_0    (BIT1 + BIT2 + BIT3)    // 0/0/x/x Speed Manual Set Register
    #define CND003_PCIEPHYCFG_FRP03_SPEEDSETEN_EP      BIT0                    // 0/0/x/x Speed Manual Set Enable
#define CND003_PCIEPHYCFG_CM_AND_DT_DRIVER_SPEED_SET_LANE00_PHYC 0x9F // CM and DT Driver Speed Set Lane00 PHYC
    #define CND003_PCIEPHYCFG_RSVPCIEPHYCFG_9F_7 PCIEPHYCFG_CM_AND_DT_DRIVER_SPEED_SET_LANE00_PHYC // 0/x/x/x Reserved
#define CND003_PCIEPHYCFG_TX_SWING_MAUNAL_SET_LANE00_EP 0xA0 // TX Swing Maunal Set Lane00 EP
    #define CND003_PCIEPHYCFG_RSVPCIEPHYCFG_C4_7           0xF000  // 0/x/x/x Reserved
    #define CND003_PCIEPHYCFG_FRP00_PCIE_TXEQSET_EP_10_0   0xFFE   // 0/0/x/x TX Swing Maunal Setting
    #define CND003_PCIEPHYCFG_FRP00_PCIE_TXEQSET_EN_EP     BIT0    // 0/0/x/x PCIe TX Swing and EQ Manual Set Enable
#define CND003_PCIEPHYCFG_TX_SWING_MAUNAL_SET_LANE01_EP 0xA2 // TX Swing Maunal Set Lane01 EP
    #define CND003_PCIEPHYCFG_RSVPCIEPHYCFG_C6_7           0xF000  // 0/x/x/x Reserved
    #define CND003_PCIEPHYCFG_FRP01_PCIE_TXEQSET_EP_10_0   0xFFE   // 0/0/x/x TX Swing Maunal Setting
    #define CND003_PCIEPHYCFG_FRP01_PCIE_TXEQSET_EN_EP     BIT0    // 0/0/x/x PCIe TX Swing and EQ Manual Set Enable
#define CND003_PCIEPHYCFG_TX_SWING_MAUNAL_SET_LANE02_EP 0xA4 // TX Swing Maunal Set Lane02 EP
    #define CND003_PCIEPHYCFG_RSVPCIEPHYCFG_C8_7           0xF000  // 0/x/x/x Reserved
    #define CND003_PCIEPHYCFG_FRP02_PCIE_TXEQSET_EP_10_0   0xFFE   // 0/0/x/x TX Swing Maunal Setting
    #define CND003_PCIEPHYCFG_FRP02_PCIE_TXEQSET_EN_EP     BIT0    // 0/0/x/x PCIe TX Swing and EQ Manual Set Enable
#define CND003_PCIEPHYCFG_TX_SWING_MAUNAL_SET_LANE03_EP 0xA6 // TX Swing Maunal Set Lane03 EP
    #define CND003_PCIEPHYCFG_RSVPCIEPHYCFG_CA_7           0xF000  // 0/x/x/x Reserved
    #define CND003_PCIEPHYCFG_FRP03_PCIE_TXEQSET_EP_10_0   0xFFE   // 0/0/x/x TX Swing Maunal Setting
    #define CND003_PCIEPHYCFG_FRP03_PCIE_TXEQSET_EN_EP     BIT0    // 0/0/x/x PCIe TX Swing and EQ Manual Set Enable
#define CND003_PCIEPHYCFG_TX_SWING_MAUNAL_SET_GEN1_PHYA_LANE00 0xA8 // TX Swing Maunal Set Gen1 PHYA Lane00
    #define CND003_PCIEPHYCFG_RSV_A8               0xFE000000              // 0/0/x/x Reserved
    #define CND003_PCIEPHYCFG_FRP00_TDPCIS_G1_PHYA 0x1F80000               // 0/0/x/x PCIe TDPCIS for GEN1 on PHYA Lane00
    #define CND003_PCIEPHYCFG_FRP00_TDCIS_G1_PHYA  0x7C000                 // 1Dh/1dh/x/x PCIe TDCIS for GEN1 on PHYA Lane00
    #define CND003_PCIEPHYCFG_FRP00_TDNCIS_G1_PHYA 0x3F00                  // 22h/22h/x/x PCIe TDNCIS for GEN1 on PHYA Lane00
    #define CND003_PCIEPHYCFG_FRP00_TXDUTY_G1_PHYA (BIT6 + BIT7)           // 0/0/x/x PCIe TXDUTY  for GEN1 on PHYA Lane00
    #define CND003_PCIEPHYCFG_FRP00_TXNSR_G1_PHYA  (BIT3 + BIT4 + BIT5)    // 011b/011b/x/x PCIe TXNSR for GEN1 on PHYA Lane00
    #define CND003_PCIEPHYCFG_FRP00_TXPSR_G1_PHYA  (BIT0 + BIT1 + BIT2)    // 011b/011b/x/x PCIe TXPSR for GEN1 on PHYA Lane00
#define CND003_PCIEPHYCFG_TX_SWING_MAUNAL_SET_GEN2_PHYA_LANE00 0xAC // TX Swing Maunal Set Gen2 PHYA Lane00
    #define CND003_PCIEPHYCFG_RSV_AC               0xFE000000              // 0/0/x/x Reserved
    #define CND003_PCIEPHYCFG_FRP00_TDPCIS_G2_PHYA 0x1F80000               // 0/0/x/x PCIe TDPCIS for GEN2 on PHYA Lane00
    #define CND003_PCIEPHYCFG_FRP00_TDCIS_G2_PHYA  0x7C000                 // 1Bh/1bh/x/x PCIe TDCIS for GEN2 on PHYA Lane00
    #define CND003_PCIEPHYCFG_FRP00_TDNCIS_G2_PHYA 0x3F00                  // 3Dh/3dh/x/x PCIe TDNCIS for GEN2 on PHYA Lane00
    #define CND003_PCIEPHYCFG_FRP00_TXDUTY_G2_PHYA (BIT6 + BIT7)           // 0/0/x/x PCIe TXDUTY for GEN2 on PHYA Lane00
    #define CND003_PCIEPHYCFG_FRP00_TXNSR_G2_PHYA  (BIT3 + BIT4 + BIT5)    // 011b/011b/x/x PCIe TXNSR for GEN2 on PHYA Lane00
    #define CND003_PCIEPHYCFG_FRP00_TXPSR_G2_PHYA  (BIT0 + BIT1 + BIT2)    // 011b/011b/x/x PCIe TXPSR for GEN2 on PHYA Lane00
#define CND003_PCIEPHYCFG_TX_SWING_MAUNAL_SET_GEN1_PHYA_LANE01 0xB0 // TX Swing Maunal Set Gen1 PHYA Lane01
    #define CND003_PCIEPHYCFG_RSV_B0               0xFE000000              // 0/0/x/x Reserved
    #define CND003_PCIEPHYCFG_FRP01_TDPCIS_G1_PHYA 0x1F80000               // 0/0/x/x PCIe TDPCIS for GEN1 on PHYA Lane01
    #define CND003_PCIEPHYCFG_FRP01_TDCIS_G1_PHYA  0x7C000                 // 1Dh/1dh/x/x PCIe TDCIS for GEN1 on PHYA Lane01
    #define CND003_PCIEPHYCFG_FRP01_TDNCIS_G1_PHYA 0x3F00                  // 22h/22h/x/x PCIe TDNCIS for GEN1 on PHYA Lane01
    #define CND003_PCIEPHYCFG_FRP01_TXDUTY_G1_PHYA (BIT6 + BIT7)           // 0/0/x/x PCIe TXDUTY for GEN1 on PHYA Lane01
    #define CND003_PCIEPHYCFG_FRP01_TXNSR_G1_PHYA  (BIT3 + BIT4 + BIT5)    // 011b/011b/x/x PCIe TXNSR for GEN1 on PHYA Lane01
    #define CND003_PCIEPHYCFG_FRP01_TXPSR_G1_PHYA  (BIT0 + BIT1 + BIT2)    // 011b/011b/x/x PCIe TXPSR for GEN1 on PHYA Lane01
#define CND003_PCIEPHYCFG_TX_SWING_MAUNAL_SET_GEN2_PHYA_LANE01 0xB4 // TX Swing Maunal Set Gen2 PHYA Lane01
    #define CND003_PCIEPHYCFG_RSV_B4               0xFE000000              // 0/0/x/x Reserved
    #define CND003_PCIEPHYCFG_FRP01_TDPCIS_G2_PHYA 0x1F80000               // 0/0/x/x PCIe TDPCIS for GEN2 on PHYA Lane01
    #define CND003_PCIEPHYCFG_FRP01_TDCIS_G2_PHYA  0x7C000                 // 1Bh/1bh/x/x PCIe TDCIS for GEN2 on PHYA Lane01
    #define CND003_PCIEPHYCFG_FRP01_TDNCIS_G2_PHYA 0x3F00                  // 3Dh/3dh/x/x PCIe TDNCIS for GEN2 on PHYA Lane01
    #define CND003_PCIEPHYCFG_FRP01_TXDUTY_G2_PHYA (BIT6 + BIT7)           // 0/0/x/x PCIe TXDUTY for GEN2 on PHYA Lane01
    #define CND003_PCIEPHYCFG_FRP01_TXNSR_G2_PHYA  (BIT3 + BIT4 + BIT5)    // 011b/011b/x/x PCIe TXNSR for GEN2 on PHYA Lane01
    #define CND003_PCIEPHYCFG_FRP01_TXPSR_G2_PHYA  (BIT0 + BIT1 + BIT2)    // 011b/011b/x/x PCIe TXPSR for GEN2 on PHYA Lane01
#define CND003_PCIEPHYCFG_TX_SWING_MAUNAL_SET_GEN1_PHYA_LANE02 0xB8 // TX Swing Maunal Set Gen1 PHYA Lane02
    #define CND003_PCIEPHYCFG_RSV_B8               0xFE000000              // 0/0/x/x Reserved
    #define CND003_PCIEPHYCFG_FRP02_TDPCIS_G1_PHYA 0x1F80000               // 0/0/x/x PCIe TDPCIS for GEN1 on PHYA Lane02
    #define CND003_PCIEPHYCFG_FRP02_TDCIS_G1_PHYA  0x7C000                 // 1Dh/1dh/x/x PCIe TDCIS for GEN1 on PHYA Lane02
    #define CND003_PCIEPHYCFG_FRP02_TDNCIS_G1_PHYA 0x3F00                  // 22h/22h/x/x PCIe TDNCIS for GEN1 on PHYA Lane02
    #define CND003_PCIEPHYCFG_FRP02_TXDUTY_G1_PHYA (BIT6 + BIT7)           // 0/0/x/x PCIe TXDUTY for GEN1 on PHYA Lane02
    #define CND003_PCIEPHYCFG_FRP02_TXNSR_G1_PHYA  (BIT3 + BIT4 + BIT5)    // 011b/011b/x/x PCIe TXNSR for GEN1 on PHYA Lane02
    #define CND003_PCIEPHYCFG_FRP02_TXPSR_G1_PHYA  (BIT0 + BIT1 + BIT2)    // 011b/011b/x/x PCIe TXPSR for GEN1 on PHYA Lane02
#define CND003_PCIEPHYCFG_TX_SWING_MAUNAL_SET_GEN2_PHYA_LANE02 0xBC // TX Swing Maunal Set Gen2 PHYA Lane02
    #define CND003_PCIEPHYCFG_RSV_BC               0xFE000000              // 0/0/x/x Reserved
    #define CND003_PCIEPHYCFG_FRP02_TDPCIS_G2_PHYA 0x1F80000               // 0/0/x/x PCIe TDPCIS for GEN2 on PHYA Lane02
    #define CND003_PCIEPHYCFG_FRP02_TDCIS_G2_PHYA  0x7C000                 // 1Bh/1bh/x/x PCIe TDCIS for GEN2 on PHYA Lane02
    #define CND003_PCIEPHYCFG_FRP02_TDNCIS_G2_PHYA 0x3F00                  // 3Dh/3dh/x/x PCIe TDNCIS for GEN2 on PHYA Lane02
    #define CND003_PCIEPHYCFG_FRP02_TXDUTY_G2_PHYA (BIT6 + BIT7)           // 0/0/x/x PCIe TXDUTY for GEN2 on PHYA Lane02
    #define CND003_PCIEPHYCFG_FRP02_TXNSR_G2_PHYA  (BIT3 + BIT4 + BIT5)    // 011b/011b/x/x PCIe TXNSR for GEN2 on PHYA Lane02
    #define CND003_PCIEPHYCFG_FRP02_TXPSR_G2_PHYA  (BIT0 + BIT1 + BIT2)    // 011b/011b/x/x PCIe TXPSR for GEN2 on PHYA Lane02
#define CND003_PCIEPHYCFG_TX_SWING_MAUNAL_SET_GEN1_PHYA_LANE03 0xC0 // TX Swing Maunal Set Gen1 PHYA Lane03
    #define CND003_PCIEPHYCFG_RSV_C0               0xFE000000              // 0/0/x/x Reserved
    #define CND003_PCIEPHYCFG_FRP03_TDPCIS_G1_PHYA 0x1F80000               // 0/0/x/x PCIe TDPCIS for GEN1 on PHYA Lane03
    #define CND003_PCIEPHYCFG_FRP03_TDCIS_G1_PHYA  0x7C000                 // 1Dh/1dh/x/x PCIe TDCIS for GEN1 on PHYA Lane03
    #define CND003_PCIEPHYCFG_FRP03_TDNCIS_G1_PHYA 0x3F00                  // 22h/22h/x/x PCIe TDNCIS for GEN1 on PHYA Lane03
    #define CND003_PCIEPHYCFG_FRP03_TXDUTY_G1_PHYA (BIT6 + BIT7)           // 0/0/x/x PCIe TXDUTY for GEN1 on PHYA Lane03
    #define CND003_PCIEPHYCFG_FRP03_TXNSR_G1_PHYA  (BIT3 + BIT4 + BIT5)    // 011b/011b/x/x PCIe TXNSR for GEN1 on PHYA Lane03
    #define CND003_PCIEPHYCFG_FRP03_TXPSR_G1_PHYA  (BIT0 + BIT1 + BIT2)    // 011b/011b/x/x PCIe TXPSR for GEN1 on PHYA Lane03
#define CND003_PCIEPHYCFG_TX_SWING_MAUNAL_SET_GEN2_PHYA_LANE03 0xC4 // TX Swing Maunal Set Gen2 PHYA Lane03
    #define CND003_PCIEPHYCFG_RSV_C4               0xFE000000              // 0/0/x/x Reserved
    #define CND003_PCIEPHYCFG_FRP03_TDPCIS_G2_PHYA 0x1F80000               // 0/0/x/x PCIe TDPCIS for GEN2 on PHYA Lane03
    #define CND003_PCIEPHYCFG_FRP03_TDCIS_G2_PHYA  0x7C000                 // 1Bh/1bh/x/x PCIe TDCIS for GEN2 on PHYA Lane03
    #define CND003_PCIEPHYCFG_FRP03_TDNCIS_G2_PHYA 0x3F00                  // 3Dh/3dh/x/x PCIe TDNCIS for GEN2 on PHYA Lane03
    #define CND003_PCIEPHYCFG_FRP03_TXDUTY_G2_PHYA (BIT6 + BIT7)           // 0/0/x/x PCIe TXDUTY for GEN2 on PHYA Lane03
    #define CND003_PCIEPHYCFG_FRP03_TXNSR_G2_PHYA  (BIT3 + BIT4 + BIT5)    // 011b/011b/x/x PCIe TXNSR for GEN2 on PHYA Lane03
    #define CND003_PCIEPHYCFG_FRP03_TXPSR_G2_PHYA  (BIT0 + BIT1 + BIT2)    // 011b/011b/x/x PCIe TXPSR for GEN2 on PHYA Lane03
#define CND003_PCIEPHYCFG_TX_SWING_MAUNAL_SET_GEN1_PHYA_LANE04 0xC8 // TX Swing Maunal Set Gen1 PHYA Lane04
    #define CND003_PCIEPHYCFG_RSV_C8               0xFE000000              // 0/0/x/x Reserved
    #define CND003_PCIEPHYCFG_FRP04_TDPCIS_G1_PHYA 0x1F80000               // 0/0/x/x PCIe TDPCIS for GEN1 on PHYA Lane04
    #define CND003_PCIEPHYCFG_FRP04_TDCIS_G1_PHYA  0x7C000                 // 1Dh/1dh/x/x PCIe TDCIS for GEN1 on PHYA Lane04
    #define CND003_PCIEPHYCFG_FRP04_TDNCIS_G1_PHYA 0x3F00                  // 22h/22h/x/x PCIe TDNCIS for GEN1 on PHYA Lane04
    #define CND003_PCIEPHYCFG_FRP04_TXDUTY_G1_PHYA (BIT6 + BIT7)           // 0/0/x/x PCIe TXDUTY for GEN1 on PHYA Lane04
    #define CND003_PCIEPHYCFG_FRP04_TXNSR_G1_PHYA  (BIT3 + BIT4 + BIT5)    // 011b/011b/x/x PCIe TXNSR for GEN1 on PHYA Lane04
    #define CND003_PCIEPHYCFG_FRP04_TXPSR_G1_PHYA  (BIT0 + BIT1 + BIT2)    // 011b/011b/x/x PCIe TXPSR for GEN1 on PHYA Lane04
#define CND003_PCIEPHYCFG_TX_SWING_MAUNAL_SET_GEN2_PHYA_LANE04 0xCC // TX Swing Maunal Set Gen2 PHYA Lane04
    #define CND003_PCIEPHYCFG_RSV_CC               0xFE000000              // 0/0/x/x Reserved
    #define CND003_PCIEPHYCFG_FRP04_TDPCIS_G2_PHYA 0x1F80000               // 0/0/x/x PCIe TDPCIS for GEN2 on PHYA Lane04
    #define CND003_PCIEPHYCFG_FRP04_TDCIS_G2_PHYA  0x7C000                 // 1Bh/1bh/x/x PCIe TDCIS for GEN2 on PHYA Lane04
    #define CND003_PCIEPHYCFG_FRP04_TDNCIS_G2_PHYA 0x3F00                  // 3Dh/3dh/x/x PCIe TDNCIS for GEN2 on PHYA Lane04
    #define CND003_PCIEPHYCFG_FRP04_TXDUTY_G2_PHYA (BIT6 + BIT7)           // 0/0/x/x PCIe TXDUTY for GEN2 on PHYA Lane04
    #define CND003_PCIEPHYCFG_FRP04_TXNSR_G2_PHYA  (BIT3 + BIT4 + BIT5)    // 011b/011b/x/x PCIe TXNSR for GEN2 on PHYA Lane04
    #define CND003_PCIEPHYCFG_FRP04_TXPSR_G2_PHYA  (BIT0 + BIT1 + BIT2)    // 011b/011b/x/x PCIe TXPSR for GEN2 on PHYA Lane04
#define CND003_PCIEPHYCFG_TX_SWING_MAUNAL_SET_GEN1_PHYB_LANE00 0xD0 // TX Swing Maunal Set Gen1 PHYB Lane00
    #define CND003_PCIEPHYCFG_RSV_D0               0xFE000000              // 0/0/x/x Reserved
    #define CND003_PCIEPHYCFG_FRP00_TDPCIS_G1_PHYB 0x1F80000               // 0/0/x/x PCIe TDPCIS for GEN1 on PHYB Lane00
    #define CND003_PCIEPHYCFG_FRP00_TDCIS_G1_PHYB  0x7C000                 // 1Dh/1dh/x/x PCIe TDCIS for GEN1 on PHYB Lane00
    #define CND003_PCIEPHYCFG_FRP00_TDNCIS_G1_PHYB 0x3F00                  // 22h/22h/x/x PCIe TDNCIS for GEN1 on PHYB Lane00
    #define CND003_PCIEPHYCFG_FRP00_TXDUTY_G1_PHYB (BIT6 + BIT7)           // 0/0/x/x PCIe TXDUTYe for GEN1 on PHYB Lane00
    #define CND003_PCIEPHYCFG_FRP00_TXNSR_G1_PHYB  (BIT3 + BIT4 + BIT5)    // 011b/011b/x/x PCIe TXNSR for GEN1 on PHYB Lane00
    #define CND003_PCIEPHYCFG_FRP00_TXPSR_G1_PHYB  (BIT0 + BIT1 + BIT2)    // 011b/011b/x/x PCIe TXPSR for GEN1 on PHYB Lane00
#define CND003_PCIEPHYCFG_TX_SWING_MAUNAL_SET_GEN2_PHYB_LANE00 0xD4 // TX Swing Maunal Set Gen2 PHYB Lane00
    #define CND003_PCIEPHYCFG_RSV_D4               0xFE000000              // 0/0/x/x Reserved
    #define CND003_PCIEPHYCFG_FRP00_TDPCIS_G2_PHYB 0x1F80000               // 0/0/x/x PCIe TDPCIS for GEN2 on PHYB Lane00
    #define CND003_PCIEPHYCFG_FRP00_TDCIS_G2_PHYB  0x7C000                 // 1Bh/1bh/x/x PCIe TDCIS for GEN2 on PHYB Lane00
    #define CND003_PCIEPHYCFG_FRP00_TDNCIS_G2_PHYB 0x3F00                  // 3Dh/3dh/x/x PCIe TDNCIS for GEN2 on PHYB Lane00
    #define CND003_PCIEPHYCFG_FRP00_TXDUTY_G2_PHYB (BIT6 + BIT7)           // 0/0/x/x PCIe TXDUTY for GEN2 on PHYB Lane00
    #define CND003_PCIEPHYCFG_FRP00_TXNSR_G2_PHYB  (BIT3 + BIT4 + BIT5)    // 011b/011b/x/x PCIe TXNSR for GEN2 on PHYB Lane00
    #define CND003_PCIEPHYCFG_FRP00_TXPSR_G2_PHYB  (BIT0 + BIT1 + BIT2)    // 011b/011b/x/x PCIe TXPSR for GEN2 on PHYB Lane00
#define CND003_PCIEPHYCFG_TX_SWING_MAUNAL_SET_GEN1_PHYB_LANE01 0xD8 // TX Swing Maunal Set Gen1 PHYB Lane01
    #define CND003_PCIEPHYCFG_RSV_D8               0xFE000000              // 0/0/x/x Reserved
    #define CND003_PCIEPHYCFG_FRP01_TDPCIS_G1_PHYB 0x1F80000               // 0/0/x/x PCIe TDPCIS for GEN1 on PHYB Lane01
    #define CND003_PCIEPHYCFG_FRP01_TDCIS_G1_PHYB  0x7C000                 // 1Dh/1dh/x/x PCIe TDCIS for GEN1 on PHYB Lane01
    #define CND003_PCIEPHYCFG_FRP01_TDNCIS_G1_PHYB 0x3F00                  // 22h/22h/x/x PCIe TDNCIS for GEN1 on PHYB Lane01
    #define CND003_PCIEPHYCFG_FRP01_TXDUTY_G1_PHYB (BIT6 + BIT7)           // 0/0/x/x PCIe TXDUTY for GEN1 on PHYB Lane01
    #define CND003_PCIEPHYCFG_FRP01_TXNSR_G1_PHYB  (BIT3 + BIT4 + BIT5)    // 011b/011b/x/x PCIe TXNSR for GEN1 on PHYB Lane01
    #define CND003_PCIEPHYCFG_FRP01_TXPSR_G1_PHYB  (BIT0 + BIT1 + BIT2)    // 011b/011b/x/x PCIe TXPSR for GEN1 on PHYB Lane01
#define CND003_PCIEPHYCFG_TX_SWING_MAUNAL_SET_GEN2_PHYB_LANE01 0xDC // TX Swing Maunal Set Gen2 PHYB Lane01
    #define CND003_PCIEPHYCFG_RSV_DC               0xFE000000              // 0/0/x/x Reserved
    #define CND003_PCIEPHYCFG_FRP01_TDPCIS_G2_PHYB 0x1F80000               // 0/0/x/x PCIe TDPCIS for GEN2 on PHYB Lane01
    #define CND003_PCIEPHYCFG_FRP01_TDCIS_G2_PHYB  0x7C000                 // 1Bh/1bh/x/x PCIe TDCIS for GEN2 on PHYB Lane01
    #define CND003_PCIEPHYCFG_FRP01_TDNCIS_G2_PHYB 0x3F00                  // 3Dh/3dh/x/x PCIe TDNCIS for GEN2 on PHYB Lane01
    #define CND003_PCIEPHYCFG_FRP01_TXDUTY_G2_PHYB (BIT6 + BIT7)           // 0/0/x/x PCIe TXDUTY for GEN2 on PHYB Lane01
    #define CND003_PCIEPHYCFG_FRP01_TXNSR_G2_PHYB  (BIT3 + BIT4 + BIT5)    // 011b/011b/x/x PCIe TXNSR for GEN2 on PHYB Lane01
    #define CND003_PCIEPHYCFG_FRP01_TXPSR_G2_PHYB  (BIT0 + BIT1 + BIT2)    // 011b/011b/x/x PCIe TXPSR for GEN2 on PHYB Lane01
#define CND003_PCIEPHYCFG_TX_SWING_MAUNAL_SET_GEN1_PHYB_LANE02 0xE0 // TX Swing Maunal Set Gen1 PHYB Lane02
    #define CND003_PCIEPHYCFG_RSV_E0               0xFE000000              // 0/0/x/x Reserved
    #define CND003_PCIEPHYCFG_FRP02_TDPCIS_G1_PHYB 0x1F80000               // 0/0/x/x PCIe TDPCIS for GEN1 on PHYB Lane02
    #define CND003_PCIEPHYCFG_FRP02_TDCIS_G1_PHYB  0x7C000                 // 1Dh/1dh/x/x PCIe TDCIS for GEN1 on PHYB Lane02
    #define CND003_PCIEPHYCFG_FRP02_TDNCIS_G1_PHYB 0x3F00                  // 22h/22h/x/x PCIe TDNCIS for GEN1 on PHYB Lane02
    #define CND003_PCIEPHYCFG_FRP02_TXDUTY_G1_PHYB (BIT6 + BIT7)           // 0/0/x/x PCIe TXDUTY for GEN1 on PHYB Lane02
    #define CND003_PCIEPHYCFG_FRP02_TXNSR_G1_PHYB  (BIT3 + BIT4 + BIT5)    // 011b/011b/x/x PCIe TXNSR for GEN1 on PHYB Lane02
    #define CND003_PCIEPHYCFG_FRP02_TXPSR_G1_PHYB  (BIT0 + BIT1 + BIT2)    // 011b/011b/x/x PCIe TXPSR for GEN1 on PHYB Lane02
#define CND003_PCIEPHYCFG_TX_SWING_MAUNAL_SET_GEN2_PHYB_LANE02 0xE4 // TX Swing Maunal Set Gen2 PHYB Lane02
    #define CND003_PCIEPHYCFG_RSV_E4               0xFE000000              // 0/0/x/x Reserved
    #define CND003_PCIEPHYCFG_FRP02_TDPCIS_G2_PHYB 0x1F80000               // 0/0/x/x PCIe TDPCIS for GEN2 on PHYB Lane02
    #define CND003_PCIEPHYCFG_FRP02_TDCIS_G2_PHYB  0x7C000                 // 1Bh/1bh/x/x PCIe TDCIS for GEN2 on PHYB Lane02
    #define CND003_PCIEPHYCFG_FRP02_TDNCIS_G2_PHYB 0x3F00                  // 3Dh/3dh/x/x PCIe TDNCIS for GEN2 on PHYB Lane02
    #define CND003_PCIEPHYCFG_FRP02_TXDUTY_G2_PHYB (BIT6 + BIT7)           // 0/0/x/x PCIe TXDUTY for GEN2 on PHYB Lane02
    #define CND003_PCIEPHYCFG_FRP02_TXNSR_G2_PHYB  (BIT3 + BIT4 + BIT5)    // 011b/011b/x/x PCIe TXNSR for GEN2 on PHYB Lane02
    #define CND003_PCIEPHYCFG_FRP02_TXPSR_G2_PHYB  (BIT0 + BIT1 + BIT2)    // 011b/011b/x/x PCIe TXPSR for GEN2 on PHYB Lane02
#define CND003_PCIEPHYCFG_TX_SWING_MAUNAL_SET_GEN1_PHYB_LANE03 0xE8 // TX Swing Maunal Set Gen1 PHYB Lane03
    #define CND003_PCIEPHYCFG_RSV_E8               0xFE000000              // 0/0/x/x Reserved
    #define CND003_PCIEPHYCFG_FRP03_TDPCIS_G1_PHYB 0x1F80000               // 0/0/x/x PCIe TDPCIS for GEN1 on PHYB Lane03
    #define CND003_PCIEPHYCFG_FRP03_TDCIS_G1_PHYB  0x7C000                 // 1Dh/1dh/x/x PCIe TDCIS for GEN1 on PHYB Lane03
    #define CND003_PCIEPHYCFG_FRP03_TDNCIS_G1_PHYB 0x3F00                  // 22h/22h/x/x PCIe TDNCIS for GEN1 on PHYB Lane03
    #define CND003_PCIEPHYCFG_FRP03_TXDUTY_G1_PHYB (BIT6 + BIT7)           // 0/0/x/x PCIe TXDUTY for GEN1 on PHYB Lane03
    #define CND003_PCIEPHYCFG_FRP03_TXNSR_G1_PHYB  (BIT3 + BIT4 + BIT5)    // 011b/011b/x/x PCIe TXNSR for GEN1 on PHYB Lane03
    #define CND003_PCIEPHYCFG_FRP03_TXPSR_G1_PHYB  (BIT0 + BIT1 + BIT2)    // 011b/011b/x/x PCIe TXPSR for GEN1 on PHYB Lane03
#define CND003_PCIEPHYCFG_TX_SWING_MAUNAL_SET_GEN2_PHYB_LANE03 0xEC // TX Swing Maunal Set Gen2 PHYB Lane03
    #define CND003_PCIEPHYCFG_RSV_EC               0xFE000000              // 0/0/x/x Reserved
    #define CND003_PCIEPHYCFG_FRP03_TDPCIS_G2_PHYB 0x1F80000               // 0/0/x/x PCIe TDPCIS for GEN2 on PHYB Lane03
    #define CND003_PCIEPHYCFG_FRP03_TDCIS_G2_PHYB  0x7C000                 // 1Bh/1bh/x/x PCIe TDCIS for GEN2 on PHYB Lane03
    #define CND003_PCIEPHYCFG_FRP03_TDNCIS_G2_PHYB 0x3F00                  // 3Dh/3dh/x/x PCIe TDNCIS for GEN2 on PHYB Lane03
    #define CND003_PCIEPHYCFG_FRP03_TXDUTY_G2_PHYB (BIT6 + BIT7)           // 0/0/x/x PCIe TXDUTY for GEN2 on PHYB Lane03
    #define CND003_PCIEPHYCFG_FRP03_TXNSR_G2_PHYB  (BIT3 + BIT4 + BIT5)    // 011b/011b/x/x PCIe TXNSR for GEN2 on PHYB Lane03
    #define CND003_PCIEPHYCFG_FRP03_TXPSR_G2_PHYB  (BIT0 + BIT1 + BIT2)    // 011b/011b/x/x PCIe TXPSR for GEN2 on PHYB Lane03
#define CND003_PCIEPHYCFG_PEMCU_USE_REG_0 0xF0 // PEMCU Use Register 0
    #define CND003_PCIEPHYCFG_PEMCU_REG_0 PCIEPHYCFG_PEMCU_USE_REG_0 // 0/x/x/x The Register for PEMCU
#define CND003_PCIEPHYCFG_PEMCU_USE_REG_1 0xF4 // PEMCU Use Register 1
    #define CND003_PCIEPHYCFG_PEMCU_REG_1 PCIEPHYCFG_PEMCU_USE_REG_1 // 0/x/x/x The Register for PEMCU
#define CND003_PCIEPHYCFG_PEMCU_USE_REG_2 0xF8 // PEMCU Use Register 2
    #define CND003_PCIEPHYCFG_PEMCU_REG_2 PCIEPHYCFG_PEMCU_USE_REG_2 // 0/x/x/x The Register for PEMCU
#define CND003_PCIEPHYCFG_PEMCU_USE_REG_3 0xFC // PEMCU Use Register 3
    #define CND003_PCIEPHYCFG_PEMCU_REG_3 PCIEPHYCFG_PEMCU_USE_REG_3 // 0/x/x/x The Register for PEMCU
#define CND003_PCIEPHYCFG_CM_AND_DT_DRIVER_TX_INDEX_LANE00 0x100 // CM and DT Driver TX Index Lane00
    #define CND003_PCIEPHYCFG_RSVPCIEPHYCFG_100_7 PCIEPHYCFG_CM_AND_DT_DRIVER_TX_INDEX_LANE00 // 0/x/x/x Reserved
#define CND003_PCIEPHYCFG_CM_AND_DT_DRIVER_TX_INDEX_LANE04_PHYA 0x102 // CM and DT Driver TX Index Lane04 PHYA
    #define CND003_PCIEPHYCFG_RSVPCIEPHYCFG_102_7 PCIEPHYCFG_CM_AND_DT_DRIVER_TX_INDEX_LANE04_PHYA // 0/x/x/x Reserved
#define CND003_PCIEPHYCFG_CM_AND_DT_DRIVER_TX_INDEX_LANE00_PHYA 0x104 // CM and DT Driver TX Index Lane00 PHYA
    #define CND003_PCIEPHYCFG_RSVPCIEPHYCFG_104_7 PCIEPHYCFG_CM_AND_DT_DRIVER_TX_INDEX_LANE00_PHYA // 0/x/x/x Reserved
#define CND003_PCIEPHYCFG_CM_AND_DT_DRIVER_TX_INDEX_LANE01_PHYA 0x106 // CM and DT Driver TX Index Lane01 PHYA
    #define CND003_PCIEPHYCFG_RSVPCIEPHYCFG_106_7 PCIEPHYCFG_CM_AND_DT_DRIVER_TX_INDEX_LANE01_PHYA // 0/x/x/x Reserved
#define CND003_PCIEPHYCFG_CM_AND_DT_DRIVER_TX_INDEX_LANE02_PHYA 0x108 // CM and DT Driver TX Index Lane02 PHYA
    #define CND003_PCIEPHYCFG_RSVPCIEPHYCFG_108_7 PCIEPHYCFG_CM_AND_DT_DRIVER_TX_INDEX_LANE02_PHYA // 0/x/x/x Reserved
#define CND003_PCIEPHYCFG_CM_AND_DT_DRIVER_TX_INDEX_LANE03_PHYA 0x10A // CM and DT Driver TX Index Lane03 PHYA
    #define CND003_PCIEPHYCFG_RSVPCIEPHYCFG_10A_7 PCIEPHYCFG_CM_AND_DT_DRIVER_TX_INDEX_LANE03_PHYA // 0/x/x/x Reserved
#define CND003_PCIEPHYCFG_CM_AND_DT_DRIVER_TX_INDEX_LANE00_PHYB 0x10C // CM and DT Driver TX Index Lane00 PHYB
    #define CND003_PCIEPHYCFG_RSVPCIEPHYCFG_10C_7 PCIEPHYCFG_CM_AND_DT_DRIVER_TX_INDEX_LANE00_PHYB // 0/x/x/x Reserved
#define CND003_PCIEPHYCFG_CM_AND_DT_DRIVER_TX_INDEX_LANE01_PHYB 0x10E // CM and DT Driver TX Index Lane01 PHYB
    #define CND003_PCIEPHYCFG_RSVPCIEPHYCFG_10E_7 PCIEPHYCFG_CM_AND_DT_DRIVER_TX_INDEX_LANE01_PHYB // 0/x/x/x Reserved
#define CND003_PCIEPHYCFG_CM_AND_DT_DRIVER_TX_INDEX_LANE02_PHYB 0x110 // CM and DT Driver TX Index Lane02 PHYB
    #define CND003_PCIEPHYCFG_RSVPCIEPHYCFG_110_7 PCIEPHYCFG_CM_AND_DT_DRIVER_TX_INDEX_LANE02_PHYB // 0/x/x/x Reserved
#define CND003_PCIEPHYCFG_CM_AND_DT_DRIVER_TX_INDEX_LANE03_PHYB 0x112 // CM and DT Driver TX Index Lane03 PHYB
    #define CND003_PCIEPHYCFG_RSVPCIEPHYCFG_112_7 PCIEPHYCFG_CM_AND_DT_DRIVER_TX_INDEX_LANE03_PHYB // 0/x/x/x Reserved
#define CND003_PCIEPHYCFG_CM_AND_DT_DRIVER_TX_INDEX_LANE00_EP 0x114 // CM and DT Driver TX Index Lane00 EP
    #define CND003_PCIEPHYCFG_RSVPCIEPHYCFG_114_7  0xFF00  // 0/x/x/x Reserved
    #define CND003_PCIEPHYCFG_FRP00_TXINDEX_EP_7_0 0xFF    // HwInit/x/x/x PHYLS Generated SI Index
#define CND003_PCIEPHYCFG_CM_AND_DT_DRIVER_TX_INDEX_LANE01_EP 0x116 // CM and DT Driver TX Index Lane01 EP
    #define CND003_PCIEPHYCFG_RSVPCIEPHYCFG_116_7  0xFF00  // 0/x/x/x Reserved
    #define CND003_PCIEPHYCFG_FRP01_TXINDEX_EP_7_0 0xFF    // HwInit/x/x/x PHYLS Generated SI Index
#define CND003_PCIEPHYCFG_CM_AND_DT_DRIVER_TX_INDEX_LANE02_EP 0x118 // CM and DT Driver TX Index Lane02 EP
    #define CND003_PCIEPHYCFG_RSVPCIEPHYCFG_118_7  0xFF00  // 0/x/x/x Reserved
    #define CND003_PCIEPHYCFG_FRP02_TXINDEX_EP_7_0 0xFF    // HwInit/x/x/x PHYLS Generated SI Index
#define CND003_PCIEPHYCFG_CM_AND_DT_DRIVER_TX_INDEX_LANE03_EP 0x11A // CM and DT Driver TX Index Lane03 EP
    #define CND003_PCIEPHYCFG_RSVPCIEPHYCFG_11A_7  0xFF00  // 0/x/x/x Reserved
    #define CND003_PCIEPHYCFG_FRP03_TXINDEX_EP_7_0 0xFF    // HwInit/x/x/x PHYLS Generated SI Index
#define CND003_PCIEPHYCFG_CM_AND_DT_DRIVER_TX_INDEX_LANE00_PHYC 0x11C // CM and DT Driver TX Index Lane00 PHYC
    #define CND003_PCIEPHYCFG_RSVPCIEPHYCFG_11C_7 PCIEPHYCFG_CM_AND_DT_DRIVER_TX_INDEX_LANE00_PHYC // 0/x/x/x Reserved
#define CND003_PCIEPHYCFG_CM_AND_DT_DRIVER_TX_INDEX_LANE01_PHYC 0x11E // CM and DT Driver TX Index Lane01 PHYC
    #define CND003_PCIEPHYCFG_RSVPCIEPHYCFG_11E_7 PCIEPHYCFG_CM_AND_DT_DRIVER_TX_INDEX_LANE01_PHYC // 0/x/x/x Reserved
// PCIEEPHYCFG
#define CND003_PCIEEPHYCFG_TX_SWING_TABLE_FOR_EP_PORT_GEN1_LANE00_INDEX00 0x120 // TX Swing Table For EP Port Gen1 Lane00-Index00
    #define CND003_PCIEEPHYCFG_FRP00_V0_00_TXPSR_G1    (BIT29 + BIT30 + BIT31) // 011b/011b/x/x PMOS TX Slew Rate Control
    #define CND003_PCIEEPHYCFG_FRP00_V0_00_TXNSR_G1    (BIT26 + BIT27 + BIT28) // 011b/011b/x/x NMOS TX Slew Rate Control
    #define CND003_PCIEEPHYCFG_FRP00_V0_00_TX_DUTY_G1  (BIT24 + BIT25)         // 00b/00b/x/x TX Clock Duty Control
    #define CND003_PCIEEPHYCFG_RSV00_120_22            (BIT22 + BIT23)         // 0/0/x/x Reserved
    #define CND003_PCIEEPHYCFG_FRP00_V0_00_TDNCIS_G1   0x3F0000                // 000000b/000000b/x/x TX De-emphasis Set
    #define CND003_PCIEEPHYCFG_RSV00_120_13            (BIT13 + BIT14 + BIT15) // 0/0/x/x Reserved
    #define CND003_PCIEEPHYCFG_FRP00_V0_00_TDCIS_G1    0x1F00                  // 10100b/10100b/x/x TX Bias Control Set
    #define CND003_PCIEEPHYCFG_RSV00_120_6             (BIT6 + BIT7)           // 0/0/x/x Reserved
    #define CND003_PCIEEPHYCFG_FRP00_V0_00_TDPCIS_G1   0x3F                    // 000000b/000000b/x/x TX Preshoot Set
#define CND003_PCIEEPHYCFG_TX_SWING_TABLE_FOR_EP_PORT_GEN2_LANE00_INDEX00 0x124 // TX Swing Table For EP Port Gen2 Lane00-Index00
    #define CND003_PCIEEPHYCFG_FRP00_V0_00_TXPSR_G2    (BIT29 + BIT30 + BIT31) // 011b/011b/x/x PMOS TX Slew Rate Control
    #define CND003_PCIEEPHYCFG_FRP00_V0_00_TXNSR_G2    (BIT26 + BIT27 + BIT28) // 011b/011b/x/x NMOS TX Slew Rate Control
    #define CND003_PCIEEPHYCFG_FRP00_V0_00_TX_DUTY_G2  (BIT24 + BIT25)         // 00b/00b/x/x TX Clock Duty Control
    #define CND003_PCIEEPHYCFG_RSV00_124_22            (BIT22 + BIT23)         // 0/0/x/x Reserved
    #define CND003_PCIEEPHYCFG_FRP00_V0_00_TDNCIS_G2   0x3F0000                // 010111b/010111b/x/x TX De-emphasis Set
    #define CND003_PCIEEPHYCFG_RSV00_124_13            (BIT13 + BIT14 + BIT15) // 0/0/x/x Reserved
    #define CND003_PCIEEPHYCFG_FRP00_V0_00_TDCIS_G2    0x1F00                  // 10001b/10001b/x/x TX Bias Control Set
    #define CND003_PCIEEPHYCFG_RSV00_124_6             (BIT6 + BIT7)           // 0/0/x/x Reserved
    #define CND003_PCIEEPHYCFG_FRP00_V0_00_TDPCIS_G2   0x3F                    // 001001b/001001b/x/x TX Preshoot Set
#define CND003_PCIEEPHYCFG_TX_SWING_TABLE_FOR_EP_PORT_GEN2_LANE00_INDEX01 0x128 // TX Swing Table For EP Port Gen2 Lane00-Index01
    #define CND003_PCIEEPHYCFG_FRP00_V0_01_TXPSR_G2    (BIT29 + BIT30 + BIT31) // 011b/011b/x/x PMOS TX Slew Rate Control
    #define CND003_PCIEEPHYCFG_FRP00_V0_01_TXNSR_G2    (BIT26 + BIT27 + BIT28) // 011b/011b/x/x NMOS TX Slew Rate Control
    #define CND003_PCIEEPHYCFG_FRP00_V0_01_TX_DUTY_G2  (BIT24 + BIT25)         // 00b/00b/x/x TX Clock Duty Control
    #define CND003_PCIEEPHYCFG_RSV00_128_22            (BIT22 + BIT23)         // 0/0/x/x Reserved
    #define CND003_PCIEEPHYCFG_FRP00_V0_01_TDNCIS_G2   0x3F0000                // 001100b/001100b/x/x TX De-emphasis Set
    #define CND003_PCIEEPHYCFG_RSV00_128_13            (BIT13 + BIT14 + BIT15) // 0/0/x/x Reserved
    #define CND003_PCIEEPHYCFG_FRP00_V0_01_TDCIS_G2    0x1F00                  // 10001b/10001b/x/x TX Bias Control Set
    #define CND003_PCIEEPHYCFG_RSV00_128_6             (BIT6 + BIT7)           // 0/0/x/x Reserved
    #define CND003_PCIEEPHYCFG_FRP00_V0_01_TDPCIS_G2   0x3F                    // 001100b/001100b/x/x TX Preshoot Set
#define CND003_PCIEEPHYCFG_TX_SWING_TABLE_FOR_EP_PORT_GEN1_LANE01_INDEX00 0x12C // TX Swing Table For EP Port Gen1 Lane01-Index00
    #define CND003_PCIEEPHYCFG_FRP01_V0_00_TXPSR_G1    (BIT29 + BIT30 + BIT31) // 011b/011b/x/x PMOS TX Slew Rate Control
    #define CND003_PCIEEPHYCFG_FRP01_V0_00_TXNSR_G1    (BIT26 + BIT27 + BIT28) // 011b/011b/x/x NMOS TX Slew Rate Control
    #define CND003_PCIEEPHYCFG_FRP01_V0_00_TX_DUTY_G1  (BIT24 + BIT25)         // 00b/00b/x/x TX Clock Duty Control
    #define CND003_PCIEEPHYCFG_RSV00_12C_22            (BIT22 + BIT23)         // 0/0/x/x Reserved
    #define CND003_PCIEEPHYCFG_FRP01_V0_00_TDNCIS_G1   0x3F0000                // 000000b/000000b/x/x TX De-emphasis Set
    #define CND003_PCIEEPHYCFG_RSV00_12C_13            (BIT13 + BIT14 + BIT15) // 0/0/x/x Reserved
    #define CND003_PCIEEPHYCFG_FRP01_V0_00_TDCIS_G1    0x1F00                  // 10100b/10100b/x/x TX Bias Control Set
    #define CND003_PCIEEPHYCFG_RSV00_12C_6             (BIT6 + BIT7)           // 0/0/x/x Reserved
    #define CND003_PCIEEPHYCFG_FRP01_V0_00_TDPCIS_G1   0x3F                    // 000000b/000000b/x/x TX Preshoot Set
#define CND003_PCIEEPHYCFG_TX_SWING_TABLE_FOR_EP_PORT_GEN2_LANE01_INDEX00 0x130 // TX Swing Table For EP Port Gen2 Lane01-Index00
    #define CND003_PCIEEPHYCFG_FRP01_V0_00_TXPSR_G2    (BIT29 + BIT30 + BIT31) // 011b/011b/x/x PMOS TX Slew Rate Control
    #define CND003_PCIEEPHYCFG_FRP01_V0_00_TXNSR_G2    (BIT26 + BIT27 + BIT28) // 011b/011b/x/x NMOS TX Slew Rate Control
    #define CND003_PCIEEPHYCFG_FRP01_V0_00_TX_DUTY_G2  (BIT24 + BIT25)         // 00b/00b/x/x TX Clock Duty Control
    #define CND003_PCIEEPHYCFG_RSV00_130_22            (BIT22 + BIT23)         // 0/0/x/x Reserved
    #define CND003_PCIEEPHYCFG_FRP01_V0_00_TDNCIS_G2   0x3F0000                // 010111b/010111b/x/x TX De-emphasis Set
    #define CND003_PCIEEPHYCFG_RSV00_130_13            (BIT13 + BIT14 + BIT15) // 0/0/x/x Reserved
    #define CND003_PCIEEPHYCFG_FRP01_V0_00_TDCIS_G2    0x1F00                  // 10001b/10001b/x/x TX Bias Control Set
    #define CND003_PCIEEPHYCFG_RSV00_130_6             (BIT6 + BIT7)           // 0/0/x/x Reserved
    #define CND003_PCIEEPHYCFG_FRP01_V0_00_TDPCIS_G2   0x3F                    // 001001b/001001b/x/x TX Preshoot Set
#define CND003_PCIEEPHYCFG_TX_SWING_TABLE_FOR_EP_PORT_GEN2_LANE01_INDEX01 0x134 // TX Swing Table For EP Port Gen2 Lane01-Index01
    #define CND003_PCIEEPHYCFG_FRP01_V0_01_TXPSR_G2    (BIT29 + BIT30 + BIT31) // 011b/011b/x/x PMOS TX Slew Rate Control
    #define CND003_PCIEEPHYCFG_FRP01_V0_01_TXNSR_G2    (BIT26 + BIT27 + BIT28) // 011b/011b/x/x NMOS TX Slew Rate Control
    #define CND003_PCIEEPHYCFG_FRP01_V0_01_TX_DUTY_G2  (BIT24 + BIT25)         // 00b/00b/x/x TX Clock Duty Control
    #define CND003_PCIEEPHYCFG_RSV00_134_22            (BIT22 + BIT23)         // 0/0/x/x Reserved
    #define CND003_PCIEEPHYCFG_FRP01_V0_01_TDNCIS_G2   0x3F0000                // 001100b/001100b/x/x TX De-emphasis Set
    #define CND003_PCIEEPHYCFG_RSV00_134_13            (BIT13 + BIT14 + BIT15) // 0/0/x/x Reserved
    #define CND003_PCIEEPHYCFG_FRP01_V0_01_TDCIS_G2    0x1F00                  // 10001b/10001b/x/x TX Bias Control Set
    #define CND003_PCIEEPHYCFG_RSV00_134_6             (BIT6 + BIT7)           // 0/0/x/x Reserved
    #define CND003_PCIEEPHYCFG_FRP01_V0_01_TDPCIS_G2   0x3F                    // 001100b/001100b/x/x TX Preshoot Set
#define CND003_PCIEEPHYCFG_TX_SWING_TABLE_FOR_EP_PORT_GEN1_LANE02_INDEX00 0x138 // TX Swing Table For EP Port Gen1 Lane02-Index00
    #define CND003_PCIEEPHYCFG_FRP02_V0_00_TXPSR_G1    (BIT29 + BIT30 + BIT31) // 011b/011b/x/x PMOS TX Slew Rate Control
    #define CND003_PCIEEPHYCFG_FRP02_V0_00_TXNSR_G1    (BIT26 + BIT27 + BIT28) // 011b/011b/x/x NMOS TX Slew Rate Control
    #define CND003_PCIEEPHYCFG_FRP02_V0_00_TX_DUTY_G1  (BIT24 + BIT25)         // 00b/00b/x/x TX Clock Duty Control
    #define CND003_PCIEEPHYCFG_RSV00_138_22            (BIT22 + BIT23)         // 0/0/x/x Reserved
    #define CND003_PCIEEPHYCFG_FRP02_V0_00_TDNCIS_G1   0x3F0000                // 000000b/000000b/x/x TX De-emphasis Set
    #define CND003_PCIEEPHYCFG_RSV00_138_13            (BIT13 + BIT14 + BIT15) // 0/0/x/x Reserved
    #define CND003_PCIEEPHYCFG_FRP02_V0_00_TDCIS_G1    0x1F00                  // 10100b/10100b/x/x TX Bias Control Set
    #define CND003_PCIEEPHYCFG_RSV00_138_6             (BIT6 + BIT7)           // 0/0/x/x Reserved
    #define CND003_PCIEEPHYCFG_FRP02_V0_00_TDPCIS_G1   0x3F                    // 000000b/000000b/x/x TX Preshoot Set
#define CND003_PCIEEPHYCFG_TX_SWING_TABLE_FOR_EP_PORT_GEN2_LANE02_INDEX00 0x13C // TX Swing Table For EP port Gen2 Lane02-Index00
    #define CND003_PCIEEPHYCFG_FRP02_V0_00_TXPSR_G2    (BIT29 + BIT30 + BIT31) // 011b/011b/x/x PMOS TX Slew Rate Control
    #define CND003_PCIEEPHYCFG_FRP02_V0_00_TXNSR_G2    (BIT26 + BIT27 + BIT28) // 011b/011b/x/x NMOS TX Slew Rate Control
    #define CND003_PCIEEPHYCFG_FRP02_V0_00_TX_DUTY_G2  (BIT24 + BIT25)         // 00b/00b/x/x TX Clock Duty Control
    #define CND003_PCIEEPHYCFG_RSV00_13C_22            (BIT22 + BIT23)         // 0/0/x/x Reserved
    #define CND003_PCIEEPHYCFG_FRP02_V0_00_TDNCIS_G2   0x3F0000                // 010111b/010111b/x/x TX De-emphasis Set
    #define CND003_PCIEEPHYCFG_RSV00_13C_13            (BIT13 + BIT14 + BIT15) // 0/0/x/x Reserved
    #define CND003_PCIEEPHYCFG_FRP02_V0_00_TDCIS_G2    0x1F00                  // 10001b/10001b/x/x TX Bias Control Set
    #define CND003_PCIEEPHYCFG_RSV00_13C_6             (BIT6 + BIT7)           // 0/0/x/x Reserved
    #define CND003_PCIEEPHYCFG_FRP02_V0_00_TDPCIS_G2   0x3F                    // 001001b/001001b/x/x TX Preshoot Set
#define CND003_PCIEEPHYCFG_TX_SWING_TABLE_FOR_EP_PORT_GEN2_LANE02_INDEX01 0x140 // TX Swing Table For EP Port Gen2 Lane02-Index01
    #define CND003_PCIEEPHYCFG_FRP02_V0_01_TXPSR_G2    (BIT29 + BIT30 + BIT31) // 011b/011b/x/x PMOS TX Slew Rate Control
    #define CND003_PCIEEPHYCFG_FRP02_V0_01_TXNSR_G2    (BIT26 + BIT27 + BIT28) // 011b/011b/x/x NMOS TX Slew Rate Control
    #define CND003_PCIEEPHYCFG_FRP02_V0_01_TX_DUTY_G2  (BIT24 + BIT25)         // 00b/00b/x/x TX Clock Duty Control
    #define CND003_PCIEEPHYCFG_RSV00_140_22            (BIT22 + BIT23)         // 0/0/x/x Reserved
    #define CND003_PCIEEPHYCFG_FRP02_V0_01_TDNCIS_G2   0x3F0000                // 001100b/001100b/x/x TX De-emphasis Set
    #define CND003_PCIEEPHYCFG_RSV00_140_13            (BIT13 + BIT14 + BIT15) // 0/0/x/x Reserved
    #define CND003_PCIEEPHYCFG_FRP02_V0_01_TDCIS_G2    0x1F00                  // 10001b/10001b/x/x TX Bias Control Set
    #define CND003_PCIEEPHYCFG_RSV00_140_6             (BIT6 + BIT7)           // 0/0/x/x Reserved
    #define CND003_PCIEEPHYCFG_FRP02_V0_01_TDPCIS_G2   0x3F                    // 001100b/001100b/x/x TX Preshoot Set
#define CND003_PCIEEPHYCFG_TX_SWING_TABLE_FOR_EP_PORT_GEN1_LANE03_INDEX00 0x144 // TX Swing Table For EP Port Gen1 Lane03-Index00
    #define CND003_PCIEEPHYCFG_FRP03_V0_00_TXPSR_G1    (BIT29 + BIT30 + BIT31) // 011b/011b/x/x PMOS TX Slew Rate Control
    #define CND003_PCIEEPHYCFG_FRP03_V0_00_TXNSR_G1    (BIT26 + BIT27 + BIT28) // 011b/011b/x/x NMOS TX Slew Rate Control
    #define CND003_PCIEEPHYCFG_FRP03_V0_00_TX_DUTY_G1  (BIT24 + BIT25)         // 00b/00b/x/x TX Clock Duty Control
    #define CND003_PCIEEPHYCFG_RSV00_144_22            (BIT22 + BIT23)         // 0/0/x/x Reserved
    #define CND003_PCIEEPHYCFG_FRP03_V0_00_TDNCIS_G1   0x3F0000                // 000000b/000000b/x/x TX De-emphasis Set
    #define CND003_PCIEEPHYCFG_RSV00_144_13            (BIT13 + BIT14 + BIT15) // 0/0/x/x Reserved
    #define CND003_PCIEEPHYCFG_FRP03_V0_00_TDCIS_G1    0x1F00                  // 10100b/10100b/x/x TX Bias Control Set
    #define CND003_PCIEEPHYCFG_RSV00_144_6             (BIT6 + BIT7)           // 0/0/x/x Reserved
    #define CND003_PCIEEPHYCFG_FRP03_V0_00_TDPCIS_G1   0x3F                    // 000000b/000000b/x/x TX Preshoot Set
#define CND003_PCIEEPHYCFG_TX_SWING_TABLE_FOR_EP_PPORT_GEN2_LANE03_INDEX00 0x148 // TX Swing Table For EP Pport Gen2 Lane03-Index00
    #define CND003_PCIEEPHYCFG_FRP03_V0_00_TXPSR_G2    (BIT29 + BIT30 + BIT31) // 011b/011b/x/x PMOS TX Slew Rate Control
    #define CND003_PCIEEPHYCFG_FRP03_V0_00_TXNSR_G2    (BIT26 + BIT27 + BIT28) // 011b/011b/x/x NMOS TX Slew Rate Control
    #define CND003_PCIEEPHYCFG_FRP03_V0_00_TX_DUTY_G2  (BIT24 + BIT25)         // 00b/00b/x/x TX Clock Duty Control
    #define CND003_PCIEEPHYCFG_RSV00_148_22            (BIT22 + BIT23)         // 0/0/x/x Reserved
    #define CND003_PCIEEPHYCFG_FRP03_V0_00_TDNCIS_G2   0x3F0000                // 010111b/010111b/x/x TX De-emphasis Set
    #define CND003_PCIEEPHYCFG_RSV00_148_13            (BIT13 + BIT14 + BIT15) // 0/0/x/x Reserved
    #define CND003_PCIEEPHYCFG_FRP03_V0_00_TDCIS_G2    0x1F00                  // 10001b/10001b/x/x TX Bias Control Set
    #define CND003_PCIEEPHYCFG_RSV00_148_6             (BIT6 + BIT7)           // 0/0/x/x Reserved
    #define CND003_PCIEEPHYCFG_FRP03_V0_00_TDPCIS_G2   0x3F                    // 001001b/001001b/x/x TX Preshoot Set
#define CND003_PCIEEPHYCFG_TX_SWING_TABLE_FOR_EP_PORT_GEN2_LANE03_INDEX01 0x14C // TX Swing Table For EP Port Gen2 Lane03-Index01
    #define CND003_PCIEEPHYCFG_FRP03_V0_01_TXPSR_G2    (BIT29 + BIT30 + BIT31) // 011b/011b/x/x PMOS TX Slew Rate Control
    #define CND003_PCIEEPHYCFG_FRP03_V0_01_TXNSR_G2    (BIT26 + BIT27 + BIT28) // 011b/011b/x/x NMOS TX Slew Rate Control
    #define CND003_PCIEEPHYCFG_FRP03_V0_01_TX_DUTY_G2  (BIT24 + BIT25)         // 00b/00b/x/x TX Clock Duty Control
    #define CND003_PCIEEPHYCFG_RSV00_14C_22            (BIT22 + BIT23)         // 0/0/x/x Reserved
    #define CND003_PCIEEPHYCFG_FRP03_V0_01_TDNCIS_G2   0x3F0000                // 001100b/001100b/x/x TX De-emphasis Set
    #define CND003_PCIEEPHYCFG_RSV00_14C_13            (BIT13 + BIT14 + BIT15) // 0/0/x/x Reserved
    #define CND003_PCIEEPHYCFG_FRP03_V0_01_TDCIS_G2    0x1F00                  // 10001b/10001b/x/x TX Bias Control Set
    #define CND003_PCIEEPHYCFG_RSV00_14C_6             (BIT6 + BIT7)           // 0/0/x/x Reserved
    #define CND003_PCIEEPHYCFG_FRP03_V0_01_TDPCIS_G2   0x3F                    // 001100b/001100b/x/x TX Preshoot Set
// PCIEPHYCFG
#define CND003_PCIEPHYCFG_SIGNAL_DETECTION_RX_PWR_STATE_CTL_LANE00 0x170 // Signal Detection RX Power State Control-Lane00
    #define CND003_PCIEPHYCFG_RSVPCIEPHYCFG_170_7 PCIEPHYCFG_SIGNAL_DETECTION_RX_PWR_STATE_CTL_LANE00 // 0/x/x/x Reserved
#define CND003_PCIEPHYCFG_SIGNAL_DETECTION_RX_PWR_STATE_CTL_LANE04_PHYA 0x171 // Signal Detection RX Power State Control-Lane04 PHYA
    #define CND003_PCIEPHYCFG_RSVPCIEPHYCFG_171_7      BIT7                    // 0/x/x/x Reserved
    #define CND003_PCIEPHYCFG_FRP04_RXPWRSETEN_PHYA    BIT6                    // 0/0/x/x RX Power Status Set Enable
    #define CND003_PCIEPHYCFG_FRP04_RXPWRSET_PHYA_1_0  (BIT4 + BIT5)           // 10b/10/x/x RX Power Status Set
    #define CND003_PCIEPHYCFG_FHP04_EIDLESQBW_PHYA     BIT3                    // 0/0/x/x EIDLE/Squelch Detection Mode Select
    #define CND003_PCIEPHYCFG_FHP04_EIDLESQTH_PHYA_2_0 (BIT0 + BIT1 + BIT2)    // 010b/010/x/x EIDLE Detection Threshold
#define CND003_PCIEPHYCFG_SIGNAL_DETECTION_RX_PWR_STATE_CTL_LANE00_PHYA 0x172 // Signal Detection RX Power State Control-Lane00 PHYA
    #define CND003_PCIEPHYCFG_RSVPCIEPHYCFG_172_7      BIT7                    // 0/x/x/x Reserved
    #define CND003_PCIEPHYCFG_FRP00_RXPWRSETEN_PHYA    BIT6                    // 0/0/x/x RX Power Status Set Enable
    #define CND003_PCIEPHYCFG_FRP00_RXPWRSET_PHYA_1_0  (BIT4 + BIT5)           // 10b/10/x/x RX Power Status Set
    #define CND003_PCIEPHYCFG_FHP00_EIDLESQBW_PHYA     BIT3                    // 0/0/x/x EIDLE/Squelch Detection Mode Select
    #define CND003_PCIEPHYCFG_FHP00_EIDLESQTH_PHYA_2_0 (BIT0 + BIT1 + BIT2)    // 010b/010/x/x EIDLE Detection Threshold
#define CND003_PCIEPHYCFG_SIGNAL_DETECTION_RX_PWR_STATE_CTL_LANE01_PHYA 0x173 // Signal Detection/RX Power State Control-Lane01 PHYA
    #define CND003_PCIEPHYCFG_RSVPCIEPHYCFG_173_7      BIT7                    // 0/x/x/x Reserved
    #define CND003_PCIEPHYCFG_FRP01_RXPWRSETEN_PHYA    BIT6                    // 0/0/x/x RX Power Status Set Enable
    #define CND003_PCIEPHYCFG_FRP01_RXPWRSET_PHYA_1_0  (BIT4 + BIT5)           // 10b/10/x/x RX Power Status Set
    #define CND003_PCIEPHYCFG_FHP01_EIDLESQBW_PHYA     BIT3                    // 0/0/x/x EIDLE/Squelch Detection Mode Select
    #define CND003_PCIEPHYCFG_FHP01_EIDLESQTH_PHYA_2_0 (BIT0 + BIT1 + BIT2)    // 010b/010/x/x EIDLE Detection Threshold
#define CND003_PCIEPHYCFG_SIGNAL_DETECTION_RX_PWR_STATE_CTL_LANE02_PHYA 0x174 // Signal Detection RX Power State Control Lane02 PHYA
    #define CND003_PCIEPHYCFG_RSVPCIEPHYCFG_174_7      BIT7                    // 0/x/x/x Reserved
    #define CND003_PCIEPHYCFG_FRP02_RXPWRSETEN_PHYA    BIT6                    // 0/0/x/x RX Power Status Set Enable
    #define CND003_PCIEPHYCFG_FRP02_RXPWRSET_PHYA_1_0  (BIT4 + BIT5)           // 10b/10/x/x RX Power Status Set
    #define CND003_PCIEPHYCFG_FHP02_EIDLESQBW_PHYA     BIT3                    // 0/0/x/x EIDLE/Squelch Detection Mode Select
    #define CND003_PCIEPHYCFG_FHP02_EIDLESQTH_PHYA_2_0 (BIT0 + BIT1 + BIT2)    // 010b/010/x/x EIDLE Detection Threshold
#define CND003_PCIEPHYCFG_SIGNAL_DETECTION_RX_PWR_STATE_CTL_LANE03_PHYA 0x175 // Signal Detection/RX Power State Control-Lane03 PHYA
    #define CND003_PCIEPHYCFG_RSVPCIEPHYCFG_175_7      BIT7                    // 0/x/x/x Reserved
    #define CND003_PCIEPHYCFG_FRP03_RXPWRSETEN_PHYA    BIT6                    // 0/0/x/x RX Power Status Set Enable
    #define CND003_PCIEPHYCFG_FRP03_RXPWRSET_PHYA_1_0  (BIT4 + BIT5)           // 10b/10/x/x RX Power Status Set
    #define CND003_PCIEPHYCFG_FHP03_EIDLESQBW_PHYA     BIT3                    // 0/0/x/x EIDLE/Squelch Detection Mode Select
    #define CND003_PCIEPHYCFG_FHP03_EIDLESQTH_PHYA_2_0 (BIT0 + BIT1 + BIT2)    // 010b/010/x/x EIDLE Detection Threshold
#define CND003_PCIEPHYCFG_SIGNAL_DETECTION_RX_PWR_STATE_CTL_LANE00_PHYB 0x176 // Signal Detection RX Power State Control-Lane00 PHYB
    #define CND003_PCIEPHYCFG_RSVPCIEPHYCFG_176_7      BIT7                    // 0/x/x/x Reserved
    #define CND003_PCIEPHYCFG_FRP00_RXPWRSETEN_PHYB    BIT6                    // 0/0/x/x RX Power Status Set Enable
    #define CND003_PCIEPHYCFG_FRP00_RXPWRSET_PHYB_1_0  (BIT4 + BIT5)           // 10b/10/x/x RX Power Status Set
    #define CND003_PCIEPHYCFG_FHP00_EIDLESQBW_PHYB     BIT3                    // 0/0/x/x EIDLE/Squelch Detection Mode Select
    #define CND003_PCIEPHYCFG_FHP00_EIDLESQTH_PHYB_2_0 (BIT0 + BIT1 + BIT2)    // 010b/010/x/x EIDLE Detection Threshold
#define CND003_PCIEPHYCFG_SIGNAL_DETECTION_RX_PWR_STATE_CTL_LANE01_PHYB 0x177 // Signal Detection/RX Power State Control-Lane01 PHYB
    #define CND003_PCIEPHYCFG_RSVPCIEPHYCFG_177_7      BIT7                    // 0/x/x/x Reserved
    #define CND003_PCIEPHYCFG_FRP01_RXPWRSETEN_PHYB    BIT6                    // 0/0/x/x RX Power Status Set Enable
    #define CND003_PCIEPHYCFG_FRP01_RXPWRSET_PHYB_1_0  (BIT4 + BIT5)           // 10b/10/x/x RX Power Status Set
    #define CND003_PCIEPHYCFG_FHP01_EIDLESQBW_PHYB     BIT3                    // 0/0/x/x EIDLE/Squelch Detection Mode Select
    #define CND003_PCIEPHYCFG_FHP01_EIDLESQTH_PHYB_2_0 (BIT0 + BIT1 + BIT2)    // 010b/010/x/x EIDLE Detection Threshold
#define CND003_PCIEPHYCFG_SIGNAL_DETECTION_RX_PWR_STATE_CTL_LANE02_PHYB 0x178 // Signal Detection RX Power State Control-Lane02 PHYB
    #define CND003_PCIEPHYCFG_RSVPCIEPHYCFG_178_7      BIT7                    // 0/x/x/x Reserved
    #define CND003_PCIEPHYCFG_FRP02_RXPWRSETEN_PHYB    BIT6                    // 0/0/x/x RX Power Status Set Enable
    #define CND003_PCIEPHYCFG_FRP02_RXPWRSET_PHYB_1_0  (BIT4 + BIT5)           // 10b/10/x/x RX Power Status Set
    #define CND003_PCIEPHYCFG_FHP02_EIDLESQBW_PHYB     BIT3                    // 0/0/x/x EIDLE/Squelch Detection Mode Select
    #define CND003_PCIEPHYCFG_FHP02_EIDLESQTH_PHYB_2_0 (BIT0 + BIT1 + BIT2)    // 010b/010/x/x EIDLE Detection Threshold
#define CND003_PCIEPHYCFG_SIGNAL_DETECTION_RX_PWR_STATE_CTL_LANE03_PHYB 0x179 // Signal Detection/RX Power State Control-Lane03 PHYB
    #define CND003_PCIEPHYCFG_RSVPCIEPHYCFG_179_7      BIT7                    // 0/x/x/x Reserved
    #define CND003_PCIEPHYCFG_FRP03_RXPWRSETEN_PHYB    BIT6                    // 0/0/x/x RX Power Status Set Enable
    #define CND003_PCIEPHYCFG_FRP03_RXPWRSET_PHYB_1_0  (BIT4 + BIT5)           // 10b/10/x/x RX Power Status Set
    #define CND003_PCIEPHYCFG_FHP03_EIDLESQBW_PHYB     BIT3                    // 0/0/x/x EIDLE/Squelch Detection Mode Select
    #define CND003_PCIEPHYCFG_FHP03_EIDLESQTH_PHYB_2_0 (BIT0 + BIT1 + BIT2)    // 010b/010/x/x EIDLE Detection Threshold
#define CND003_PCIEPHYCFG_SIGNAL_DETECTION_RX_PWR_STATE_CTL_LANE00_EP 0x17A // Signal Detection RX Power State Control-Lane00 EP
    #define CND003_PCIEPHYCFG_RSVPCIEPHYCFG_17A_7      BIT7                    // 0/x/x/x Reserved
    #define CND003_PCIEPHYCFG_FRP00_RXPWRSETEN_EP      BIT6                    // 0/0/x/x RX Power Status Set Enable
    #define CND003_PCIEPHYCFG_FRP00_RXPWRSET_EP_1_0    (BIT4 + BIT5)           // 10b/10/x/x RX Power Status Set
    #define CND003_PCIEPHYCFG_FHP00_EIDLESQBW          BIT3                    // 0/0/x/x EIDLE/Squelch Detection Mode Select
    #define CND003_PCIEPHYCFG_FHP00_EIDLESQTH_2_0      (BIT0 + BIT1 + BIT2)    // 010b/010/x/x EIDLE Detection Threshold
#define CND003_PCIEPHYCFG_SIGNAL_DETECTION_RX_PWR_STATE_CTL_LANE01_EP 0x17B // Signal Detection/RX Power State Control-Lane01 EP
    #define CND003_PCIEPHYCFG_RSVPCIEPHYCFG_17B_7      BIT7                    // 0/x/x/x Reserved
    #define CND003_PCIEPHYCFG_FRP01_RXPWRSETEN_EP      BIT6                    // 0/0/x/x RX Power Status Set Enable
    #define CND003_PCIEPHYCFG_FRP01_RXPWRSET_EP_1_0    (BIT4 + BIT5)           // 10b/10/x/x RX Power Status Set
    #define CND003_PCIEPHYCFG_FHP01_EIDLESQBW          BIT3                    // 0/0/x/x EIDLE/Squelch Detection Mode Select
    #define CND003_PCIEPHYCFG_FHP01_EIDLESQTH_2_0      (BIT0 + BIT1 + BIT2)    // 010b/010/x/x EIDLE Detection Threshold
#define CND003_PCIEPHYCFG_SIGNAL_DETECTION_RX_PWR_STATE_CTL_LANE02_EP 0x17C // Signal Detection RX Power State Control-Lane02 EP
    #define CND003_PCIEPHYCFG_RSVPCIEPHYCFG_17C_7      BIT7                    // 0/x/x/x Reserved
    #define CND003_PCIEPHYCFG_FRP02_RXPWRSETEN_EP      BIT6                    // 0/0/x/x RX Power Status Set Enable
    #define CND003_PCIEPHYCFG_FRP02_RXPWRSET_EP_1_0    (BIT4 + BIT5)           // 10b/10/x/x RX Power Status Set
    #define CND003_PCIEPHYCFG_FHP02_EIDLESQBW          BIT3                    // 0/0/x/x EIDLE/Squelch Detection Mode Select
    #define CND003_PCIEPHYCFG_FHP02_EIDLESQTH_2_0      (BIT0 + BIT1 + BIT2)    // 010b/010/x/x EIDLE Detection Threshold
#define CND003_PCIEPHYCFG_SIGNAL_DETECTION_RX_PWR_STATE_CTL_LANE03_EP 0x17D // Signal Detection/RX Power State Control-Lane03 EP
    #define CND003_PCIEPHYCFG_RSVPCIEPHYCFG_17D_7      BIT7                    // 0/x/x/x Reserved
    #define CND003_PCIEPHYCFG_FRP03_RXPWRSETEN_EP      BIT6                    // 0/0/x/x RX Power Status Set Enable
    #define CND003_PCIEPHYCFG_FRP03_RXPWRSET_EP_1_0    (BIT4 + BIT5)           // 10b/10/x/x RX Power Status Set
    #define CND003_PCIEPHYCFG_FHP03_EIDLESQBW          BIT3                    // 0/0/x/x EIDLE/Squelch Detection Mode Select
    #define CND003_PCIEPHYCFG_FHP03_EIDLESQTH_2_0      (BIT0 + BIT1 + BIT2)    // 010b/010/x/x EIDLE Detection Threshold
#define CND003_PCIEPHYCFG_SIGNAL_DETECTION_RX_PWR_STATE_CTL_LANE00_PHYC 0x17E // Signal Detection/RX Power State Control-Lane00 PHYC
    #define CND003_PCIEPHYCFG_RSVPCIEPHYCFG_17E_7 PCIEPHYCFG_SIGNAL_DETECTION_RX_PWR_STATE_CTL_LANE00_PHYC // 0/x/x/x Reserved
#define CND003_PCIEPHYCFG_SIGNAL_DETECTION_RX_PWR_STATE_CTL_LANE01_PHYC 0x17F // Signal Detection RX Power State Control-Lane01 PHYC
    #define CND003_PCIEPHYCFG_RSVPCIEPHYCFG_17F_7 PCIEPHYCFG_SIGNAL_DETECTION_RX_PWR_STATE_CTL_LANE01_PHYC // 0/x/x/x Reserved
#define CND003_PCIEPHYCFG_RESERVED_Z2 0x180 // Reserved
    #define CND003_PCIEPHYCFG_RSVPCIEPHYCFG_180_7 PCIEPHYCFG_RESERVED_Z2 // 0/x/x/x Reserved
#define CND003_PCIEPHYCFG_GAIN_AND_PWR_SEL_LAN00 0x190 // Gain and Power Selection Lan00
    #define CND003_PCIEPHYCFG_FHP00_RCVTHSEL PCIEPHYCFG_GAIN_AND_PWR_SEL_LAN00 // 0/0/x/x Reserved
#define CND003_PCIEPHYCFG_GAIN_AND_PWR_SEL_LANE04_PHYA 0x191 // Gain and Power Selection Lane04 PHYA
    #define CND003_PCIEPHYCFG_FHP04_RCVTHSEL_PHYA      BIT7                    // 0/0/x/x RCV VGA Gain Range Selection
    #define CND003_PCIEPHYCFG_FHP04_IVCPSEL_PHYA_2_0   (BIT4 + BIT5 + BIT6)    // 011b/011/x/x IV Gain Select
    #define CND003_PCIEPHYCFG_FHP04_VCOPDSEL_PHYA      BIT3                    // 0/0/x/x VCO Power off Method at P1
    #define CND003_PCIEPHYCFG_FHP04_RCVPDSEL_PHYA      BIT2                    // 1b/1b/x/x RCV Power off Method
    #define CND003_PCIEPHYCFG_FHP04_CDR_UGB_HBW_PHYA   BIT1                    // 0/0/x/x CDR Loop Filter Buffer BW
    #define CND003_PCIEPHYCFG_FHP04_CDR_VT_SW_PHYA     BIT0                    // 1b/1b/x/x CDR IV Control Source Select
#define CND003_PCIEPHYCFG_GAIN_AND_PWR_SEL_LANE00_PHYA 0x192 // Gain and Power Selection Lane00 PHYA
    #define CND003_PCIEPHYCFG_FHP00_RCVTHSEL_PHYA      BIT7                    // 0/0/x/x RCV VGA Gain Range Selection
    #define CND003_PCIEPHYCFG_FHP00_IVCPSEL_PHYA_2_0   (BIT4 + BIT5 + BIT6)    // 011b/011/x/x IV Gain Select
    #define CND003_PCIEPHYCFG_FHP00_VCOPDSEL_PHYA      BIT3                    // 0/0/x/x VCO Power off Method at P1
    #define CND003_PCIEPHYCFG_FHP00_RCVPDSEL_PHYA      BIT2                    // 1b/1b/x/x RCV Power off Method
    #define CND003_PCIEPHYCFG_FHP00_CDR_UGB_HBW_PHYA   BIT1                    // 0/0/x/x CDR Loop Filter Buffer BW
    #define CND003_PCIEPHYCFG_FHP00_CDR_VT_SW_PHYA     BIT0                    // 1b/1b/x/x CDR IV Control Source Select
#define CND003_PCIEPHYCFG_GAIN_AND_PWR_SEL_LANE01_PHYA 0x193 // Gain and Power Selection Lane01 PHYA
    #define CND003_PCIEPHYCFG_FHP01_RCVTHSEL_PHYA      BIT7                    // 0/0/x/x RCV VGA Gain Range Selection
    #define CND003_PCIEPHYCFG_FHP01_IVCPSEL_PHYA_2_0   (BIT4 + BIT5 + BIT6)    // 011b/011/x/x IV Gain Select
    #define CND003_PCIEPHYCFG_FHP01_VCOPDSEL_PHYA      BIT3                    // 0/0/x/x VCO Power off Method at P1
    #define CND003_PCIEPHYCFG_FHP01_RCVPDSEL_PHYA      BIT2                    // 1b/1b/x/x RCV Power off Method
    #define CND003_PCIEPHYCFG_FHP01_CDR_UGB_HBW_PHYA   BIT1                    // 0/0/x/x CDR Loop Filter Buffer BW
    #define CND003_PCIEPHYCFG_FHP01_CDR_VT_SW_PHYA     BIT0                    // 1b/1b/x/x CDR IV Control Source Select
#define CND003_PCIEPHYCFG_GAIN_AND_PWR_SEL_LANE02_PHYA 0x194 // Gain and Power Selection Lane02 PHYA
    #define CND003_PCIEPHYCFG_FHP02_RCVTHSEL_PHYA      BIT7                    // 0/0/x/x RCV VGA Gain Range Selection
    #define CND003_PCIEPHYCFG_FHP02_IVCPSEL_PHYA_2_0   (BIT4 + BIT5 + BIT6)    // 011b/011/x/x IV Gain Select
    #define CND003_PCIEPHYCFG_FHP02_VCOPDSEL_PHYA      BIT3                    // 0/0/x/x VCO Power off Method at P1
    #define CND003_PCIEPHYCFG_FHP02_RCVPDSEL_PHYA      BIT2                    // 1b/1b/x/x RCV Power off Method
    #define CND003_PCIEPHYCFG_FHP02_CDR_UGB_HBW_PHYA   BIT1                    // 0/0/x/x CDR Loop Filter Buffer BW
    #define CND003_PCIEPHYCFG_FHP02_CDR_VT_SW_PHYA     BIT0                    // 1b/1b/x/x CDR IV Control Source Select
#define CND003_PCIEPHYCFG_GAIN_AND_PWR_SEL_LANE03_PHYA 0x195 // Gain and Power Selection Lane03 PHYA
    #define CND003_PCIEPHYCFG_FHP03_RCVTHSEL_PHYA      BIT7                    // 0/0/x/x RCV VGA Gain Range Selection
    #define CND003_PCIEPHYCFG_FHP03_IVCPSEL_PHYA_2_0   (BIT4 + BIT5 + BIT6)    // 011b/011/x/x IV Gain Select
    #define CND003_PCIEPHYCFG_FHP03_VCOPDSEL_PHYA      BIT3                    // 0/0/x/x VCO Power off Method at P1
    #define CND003_PCIEPHYCFG_FHP03_RCVPDSEL_PHYA      BIT2                    // 1b/1b/x/x RCV Power off Method
    #define CND003_PCIEPHYCFG_FHP03_CDR_UGB_HBW_PHYA   BIT1                    // 0/0/x/x CDR Loop Filter Buffer BW
    #define CND003_PCIEPHYCFG_FHP03_CDR_VT_SW_PHYA     BIT0                    // 1b/1b/x/x CDR IV Control Source Select
#define CND003_PCIEPHYCFG_GAIN_AND_PWR_SEL_LANE00_PHYB 0x196 // Gain and Power Selection Lane00 PHYB
    #define CND003_PCIEPHYCFG_FHP00_RCVTHSEL_PHYB      BIT7                    // 0/0/x/x RCV VGA Gain Range Selection
    #define CND003_PCIEPHYCFG_FHP00_IVCPSEL_PHYB_2_0   (BIT4 + BIT5 + BIT6)    // 011b/011/x/x IV Gain Select
    #define CND003_PCIEPHYCFG_FHP00_VCOPDSEL_PHYB      BIT3                    // 0/0/x/x VCO Power off Method at P1
    #define CND003_PCIEPHYCFG_FHP00_RCVPDSEL_PHYB      BIT2                    // 1b/1b/x/x RCV Power off Method
    #define CND003_PCIEPHYCFG_FHP00_CDR_UGB_HBW_PHYB   BIT1                    // 0/0/x/x CDR Loop Filter Buffer BW
    #define CND003_PCIEPHYCFG_FHP00_CDR_VT_SW_PHYB     BIT0                    // 1b/1b/x/x CDR IV Control Source Select
#define CND003_PCIEPHYCFG_GAIN_AND_PWR_SEL_LANE01_PHYB 0x197 // Gain and Power Selection Lane01 PHYB
    #define CND003_PCIEPHYCFG_FHP01_RCVTHSEL_PHYB      BIT7                    // 0/0/x/x RCV VGA Gain Range Selection
    #define CND003_PCIEPHYCFG_FHP01_IVCPSEL_PHYB_2_0   (BIT4 + BIT5 + BIT6)    // 011b/011/x/x IV Gain Select
    #define CND003_PCIEPHYCFG_FHP01_VCOPDSEL_PHYB      BIT3                    // 0/0/x/x VCO Power off Method at P1
    #define CND003_PCIEPHYCFG_FHP01_RCVPDSEL_PHYB      BIT2                    // 1b/1b/x/x RCV Power off Method
    #define CND003_PCIEPHYCFG_FHP01_CDR_UGB_HBW_PHYB   BIT1                    // 0/0/x/x CDR Loop Filter Buffer BW
    #define CND003_PCIEPHYCFG_FHP01_CDR_VT_SW_PHYB     BIT0                    // 1b/1b/x/x CDR IV Control Source Select
#define CND003_PCIEPHYCFG_GAIN_AND_PWR_SEL_LANE02_PHYB 0x198 // Gain and Power Selection Lane02 PHYB
    #define CND003_PCIEPHYCFG_FHP02_RCVTHSEL_PHYB      BIT7                    // 0/0/x/x RCV VGA Gain Range Selection
    #define CND003_PCIEPHYCFG_FHP02_IVCPSEL_PHYB_2_0   (BIT4 + BIT5 + BIT6)    // 011b/011/x/x IV Gain Select
    #define CND003_PCIEPHYCFG_FHP02_VCOPDSEL_PHYB      BIT3                    // 0/0/x/x VCO Power off Method at P1
    #define CND003_PCIEPHYCFG_FHP02_RCVPDSEL_PHYB      BIT2                    // 1b/1b/x/x RCV Power off Method
    #define CND003_PCIEPHYCFG_FHP02_CDR_UGB_HBW_PHYB   BIT1                    // 0/0/x/x CDR Loop Filter Buffer BW
    #define CND003_PCIEPHYCFG_FHP02_CDR_VT_SW_PHYB     BIT0                    // 1b/1b/x/x CDR IV Control Source Select
#define CND003_PCIEPHYCFG_GAIN_AND_PWR_SEL_LANE03_PHYB 0x199 // Gain and Power Selection Lane03 PHYB
    #define CND003_PCIEPHYCFG_FHP03_RCVTHSEL_PHYB      BIT7                    // 0/0/x/x RCV VGA Gain Range Selection
    #define CND003_PCIEPHYCFG_FHP03_IVCPSEL_PHYB_2_0   (BIT4 + BIT5 + BIT6)    // 011b/011/x/x IV Gain Select
    #define CND003_PCIEPHYCFG_FHP03_VCOPDSEL_PHYB      BIT3                    // 0/0/x/x VCO Power off Method at P1
    #define CND003_PCIEPHYCFG_FHP03_RCVPDSEL_PHYB      BIT2                    // 1b/1b/x/x RCV Power off Method
    #define CND003_PCIEPHYCFG_FHP03_CDR_UGB_HBW_PHYB   BIT1                    // 0/0/x/x CDR Loop Filter Buffer BW
    #define CND003_PCIEPHYCFG_FHP03_CDR_VT_SW_PHYB     BIT0                    // 1b/1b/x/x CDR IV Control Source Select
#define CND003_PCIEPHYCFG_GAIN_AND_PWR_SEL_LANE00_EP 0x19A // Gain and Power Selection Lane00 EP
    #define CND003_PCIEPHYCFG_FHP00_RCVTHSEL_Z1    BIT7                    // 0/0/x/x RCV VGA Gain Range Selection
    #define CND003_PCIEPHYCFG_FHP00_IVCPSEL_2_0    (BIT4 + BIT5 + BIT6)    // 011b/011/x/x IV Gain Select
    #define CND003_PCIEPHYCFG_FHP00_VCOPDSEL       BIT3                    // 0/0/x/x VCO Power off Method at P1
    #define CND003_PCIEPHYCFG_FHP00_RCVPDSEL       BIT2                    // 1b/1b/x/x RCV Power off Method
    #define CND003_PCIEPHYCFG_FHP00_CDR_UGB_HBW    BIT1                    // 0/0/x/x CDR Loop Filter Buffer BW
    #define CND003_PCIEPHYCFG_FHP00_CDR_VT_SW      BIT0                    // 1b/1b/x/x CDR IV Control Source Select
#define CND003_PCIEPHYCFG_GAIN_AND_PWR_SEL_LANE01_EP 0x19B // Gain and Power Selection Lane01 EP
    #define CND003_PCIEPHYCFG_FHP01_RCVTHSEL       BIT7                    // 0/0/x/x RCV VGA Gain Range Selection
    #define CND003_PCIEPHYCFG_FHP01_IVCPSEL_2_0    (BIT4 + BIT5 + BIT6)    // 011b/011/x/x IV Gain Select
    #define CND003_PCIEPHYCFG_FHP01_VCOPDSEL       BIT3                    // 0/0/x/x VCO Power off Method at P1
    #define CND003_PCIEPHYCFG_FHP01_RCVPDSEL       BIT2                    // 1b/1b/x/x RCV Power off Method
    #define CND003_PCIEPHYCFG_FHP01_CDR_UGB_HBW    BIT1                    // 0/0/x/x CDR Loop Filter Buffer BW
    #define CND003_PCIEPHYCFG_FHP01_CDR_VT_SW      BIT0                    // 1b/1b/x/x CDR IV Control Source Select
#define CND003_PCIEPHYCFG_GAIN_AND_PWR_SEL_LANE02_EP 0x19C // Gain and Power Selection Lane02 EP
    #define CND003_PCIEPHYCFG_FHP02_RCVTHSEL       BIT7                    // 0/0/x/x RCV VGA Gain Range Selection
    #define CND003_PCIEPHYCFG_FHP02_IVCPSEL_2_0    (BIT4 + BIT5 + BIT6)    // 011b/011/x/x IV Gain Select
    #define CND003_PCIEPHYCFG_FHP02_VCOPDSEL       BIT3                    // 0/0/x/x VCO Power off Method at P1
    #define CND003_PCIEPHYCFG_FHP02_RCVPDSEL       BIT2                    // 1b/1b/x/x RCV Power off Method
    #define CND003_PCIEPHYCFG_FHP02_CDR_UGB_HBW    BIT1                    // 0/0/x/x CDR Loop Filter Buffer BW
    #define CND003_PCIEPHYCFG_FHP02_CDR_VT_SW      BIT0                    // 1b/1b/x/x CDR IV Control Source Select
#define CND003_PCIEPHYCFG_GAIN_AND_PWR_SEL_LANE03_EP 0x19D // Gain and Power Selection Lane03 EP
    #define CND003_PCIEPHYCFG_FHP03_RCVTHSEL       BIT7                    // 0/0/x/x RCV VGA Gain Range Selection
    #define CND003_PCIEPHYCFG_FHP03_IVCPSEL_2_0    (BIT4 + BIT5 + BIT6)    // 011b/011/x/x IV Gain Select
    #define CND003_PCIEPHYCFG_FHP03_VCOPDSEL       BIT3                    // 0/0/x/x VCO Power off Method at P1
    #define CND003_PCIEPHYCFG_FHP03_RCVPDSEL       BIT2                    // 1b/1b/x/x RCV Power off Method
    #define CND003_PCIEPHYCFG_FHP03_CDR_UGB_HBW    BIT1                    // 0/0/x/x CDR Loop Filter Buffer BW
    #define CND003_PCIEPHYCFG_FHP03_CDR_VT_SW      BIT0                    // 1b/1b/x/x CDR IV Control Source Select
#define CND003_PCIEPHYCFG_GAIN_AND_PWR_SEL_LANE00_PHYC 0x19E // Gain and Power Selection Lane00 PHYC
    #define CND003_PCIEPHYCFG_FHP00_RCVTHSEL_PHYC PCIEPHYCFG_GAIN_AND_PWR_SEL_LANE00_PHYC // 0/0/x/x Reserved
#define CND003_PCIEPHYCFG_GAIN_AND_PWR_SEL_LANE01_PHYC 0x19F // Gain and Power Selection Lane01 PHYC
    #define CND003_PCIEPHYCFG_FHP01_RCVTHSEL_PHYC PCIEPHYCFG_GAIN_AND_PWR_SEL_LANE01_PHYC // 0/0/x/x Reserved
#define CND003_PCIEPHYCFG_RESERVED_Z3 0x1A0 // Reserved
    #define CND003_PCIEPHYCFG_RSVPCIEPHYCFG_1A0_7 PCIEPHYCFG_RESERVED_Z3 // 0/x/x/x Reserved
#define CND003_PCIEPHYCFG_RX_RECOVERY_SETTING_LANE00_G1 0x1B0 // RX Recovery Setting Lane00 G1
    #define CND003_PCIEPHYCFG_FRP00_FTXSWN_G1_PHYB PCIEPHYCFG_RX_RECOVERY_SETTING_LANE00_G1 // 0/00/x/x Reserved
#define CND003_PCIEPHYCFG_RX_RECOVERY_SETTING_LANE04_PHYA_G1 0x1B1 // RX Recovery Setting Lane04 PHYA G1
    #define CND003_PCIEPHYCFG_FRP04_FTXSWN_G1_PHYA_1_0     (BIT6 + BIT7)           // 00b/00/x/x PCIe Lane Far-end TX Swing and De-emphasis as Reference for RX Equ...
    #define CND003_PCIEPHYCFG_FRP04_RXCLKSEL_G1_PHYA_2_0   (BIT3 + BIT4 + BIT5)    // 0/0/x/x Rising Edge of RXCLK Select
    #define CND003_PCIEPHYCFG_FRP04_RCV_HBW_G1_PHYA_2_0    (BIT0 + BIT1 + BIT2)    // 100b/100/x/x RCV HBW Option for VGA / BUF / VGA_BUF Respectively
#define CND003_PCIEPHYCFG_RX_RECOVERY_SETTING_LANE00_PHYA_G1 0x1B2 // RX Recovery Setting Lane00 PHYA G1
    #define CND003_PCIEPHYCFG_FRP00_FTXSWN_G1_PHYA_1_0     (BIT6 + BIT7)           // 00b/00/x/x PCIe Lane Far-end TX Swing and De-emphasis as Reference for RX Equ...
    #define CND003_PCIEPHYCFG_FRP00_RXCLKSEL_G1_PHYA_2_0   (BIT3 + BIT4 + BIT5)    // 0/0/x/x Rising Edge of RXCLK Select
    #define CND003_PCIEPHYCFG_FRP00_RCV_HBW_G1_PHYA_2_0    (BIT0 + BIT1 + BIT2)    // 100b/100/x/x RCV HBW Option for VGA / BUF / VGA_BUF Respectively
#define CND003_PCIEPHYCFG_RX_RECOVERY_SETTING_LANE01_PHYA_G1 0x1B3 // RX Recovery Setting Lane01 PHYA G1
    #define CND003_PCIEPHYCFG_FRP01_FTXSWN_G1_PHYA_1_0     (BIT6 + BIT7)           // 00b/00/x/x PCIe Lane Far-End Tx Swing and De-Emphasis as Reference for Rx Equ...
    #define CND003_PCIEPHYCFG_FRP01_RXCLKSEL_G1_PHYA_2_0   (BIT3 + BIT4 + BIT5)    // 0/0/x/x Rising Edge of RXCLK Select
    #define CND003_PCIEPHYCFG_FRP01_RCV_HBW_G1_PHYA_2_0    (BIT0 + BIT1 + BIT2)    // 100b/100/x/x RCV HBW Option for VGA / BUF / VGA_BUF Respectively
#define CND003_PCIEPHYCFG_RX_RECOVERY_SETTING_LANE02_PHYA_G1 0x1B4 // RX Recovery Setting Lane02 PHYA G1
    #define CND003_PCIEPHYCFG_FRP02_FTXSWN_G1_PHYA_1_0     (BIT6 + BIT7)           // 00b/00/x/x PCIe Lane Far-end TX Swing and De-emphasis as Reference for RX Equ...
    #define CND003_PCIEPHYCFG_FRP02_RXCLKSEL_G1_PHYA_2_0   (BIT3 + BIT4 + BIT5)    // 0/0/x/x Rising Edge of RXCLK Select
    #define CND003_PCIEPHYCFG_FRP02_RCV_HBW_G1_PHYA_2_0    (BIT0 + BIT1 + BIT2)    // 100b/100/x/x RCV HBW Option for VGA / BUF / VGA_BUF Respectively
#define CND003_PCIEPHYCFG_RX_RECOVERY_SETTING_LANE03_PHYA_G1 0x1B5 // RX Recovery Setting Lane03 PHYA G1
    #define CND003_PCIEPHYCFG_FRP03_FTXSWN_G1_PHYA_1_0     (BIT6 + BIT7)           // 00b/00/x/x PCIe Lane Far-end TX Swing and De-emphasis as Reference for RX Equ...
    #define CND003_PCIEPHYCFG_FRP03_RXCLKSEL_G1_PHYA_2_0   (BIT3 + BIT4 + BIT5)    // 0/0/x/x Rising Edge of RXCLK Select
    #define CND003_PCIEPHYCFG_FRP03_RCV_HBW_G1_PHYA_2_0    (BIT0 + BIT1 + BIT2)    // 100b/100/x/x RCV HBW Option for VGA / BUF / VGA_BUF Respectively
#define CND003_PCIEPHYCFG_RX_RECOVERY_SETTING_LANE00_PHYB_G1 0x1B6 // RX Recovery Setting Lane00 PHYB G1
    #define CND003_PCIEPHYCFG_FRP00_FTXSWN_G1_PHYB_1_0     (BIT6 + BIT7)           // 00b/00/x/x PCIe Lane Far-end TX Swing and De-emphasis as Reference for RX Equ...
    #define CND003_PCIEPHYCFG_FRP00_RXCLKSEL_G1_PHYB_2_0   (BIT3 + BIT4 + BIT5)    // 0/0/x/x Rising Edge of RXCLK Select
    #define CND003_PCIEPHYCFG_FRP00_RCV_HBW_G1_PHYB_2_0    (BIT0 + BIT1 + BIT2)    // 100b/100/x/x RCV HBW Option for VGA / BUF / VGA_BUF Respectively
#define CND003_PCIEPHYCFG_RX_RECOVERY_SETTING_LANE01_PHYB_G1 0x1B7 // RX Recovery Setting Lane01 PHYB G1
    #define CND003_PCIEPHYCFG_FRP01_FTXSWN_G1_PHYB_1_0     (BIT6 + BIT7)           // 00b/00/x/x PCIe Lane Far-end TX Swing and De-emphasis as Reference for RX Equ...
    #define CND003_PCIEPHYCFG_FRP01_RXCLKSEL_G1_PHYB_2_0   (BIT3 + BIT4 + BIT5)    // 0/0/x/x Rising Edge of RXCLK Select
    #define CND003_PCIEPHYCFG_FRP01_RCV_HBW_G1_PHYB_2_0    (BIT0 + BIT1 + BIT2)    // 100b/100/x/x RCV HBW Option for VGA / BUF / VGA_BUF Respectively
#define CND003_PCIEPHYCFG_RX_RECOVERY_SETTING_LANE02_PHYB_G1 0x1B8 // RX Recovery Setting Lane02 PHYB G1
    #define CND003_PCIEPHYCFG_FRP02_FTXSWN_G1_PHYB_1_0     (BIT6 + BIT7)           // 00b/00/x/x PCIe Lane Far-end TX Swing and De-emphasis as Reference for RX Equ...
    #define CND003_PCIEPHYCFG_FRP02_RXCLKSEL_G1_PHYB_2_0   (BIT3 + BIT4 + BIT5)    // 0/0/x/x Rising Edge of RXCLK Select
    #define CND003_PCIEPHYCFG_FRP02_RCV_HBW_G1_PHYB_2_0    (BIT0 + BIT1 + BIT2)    // 100b/100/x/x RCV HBW Option for VGA / BUF / VGA_BUF Respectively
#define CND003_PCIEPHYCFG_RX_RECOVERY_SETTING_LANE03_PHYB_G1 0x1B9 // RX Recovery Setting Lane03 PHYB G1
    #define CND003_PCIEPHYCFG_FRP03_FTXSWN_G1_PHYB_1_0     (BIT6 + BIT7)           // 00b/00/x/x PCIe Lane Far-end TX Swing and De-emphasis as Reference for RX Equ...
    #define CND003_PCIEPHYCFG_FRP03_RXCLKSEL_G1_PHYB_2_0   (BIT3 + BIT4 + BIT5)    // 0/0/x/x Rising Edge of RXCLK Select
    #define CND003_PCIEPHYCFG_FRP03_RCV_HBW_G1_PHYB_2_0    (BIT0 + BIT1 + BIT2)    // 100b/100/x/x RCV HBW Option for VGA / BUF / VGA_BUF Respectively
#define CND003_PCIEPHYCFG_RX_RECOVERY_SETTING_LANE00_EP_G1 0x1BA // RX Recovery Setting Lane00 EP G1
    #define CND003_PCIEPHYCFG_FRP00_FTXSWN_G1_EP_1_0   (BIT6 + BIT7)           // 00b/00/x/x PCIe Lane Far-end TX Swing and De-emphasis as Reference for RX Equ...
    #define CND003_PCIEPHYCFG_FRP00_RXCLKSEL_G1_EP_2_0 (BIT3 + BIT4 + BIT5)    // 0/0/x/x Rising Edge of RXCLK Select
    #define CND003_PCIEPHYCFG_FRP00_RCV_HBW_G1_EP_2_0  (BIT0 + BIT1 + BIT2)    // 100b/100/x/x RCV HBW Option for VGA / BUF / VGA_BUF Respectively
#define CND003_PCIEPHYCFG_RX_RECOVERY_SETTING_LANE01_EP_G1 0x1BB // RX Recovery Setting Lane01 EP G1
    #define CND003_PCIEPHYCFG_FRP01_FTXSWN_G1_EP_1_0   (BIT6 + BIT7)           // 00b/00/x/x PCIe Lane Far-end TX Swing and De-emphasis as Reference for RX Equ...
    #define CND003_PCIEPHYCFG_FRP01_RXCLKSEL_G1_EP_2_0 (BIT3 + BIT4 + BIT5)    // 0/0/x/x Rising Edge of RXCLK Select
    #define CND003_PCIEPHYCFG_FRP01_RCV_HBW_G1_EP_2_0  (BIT0 + BIT1 + BIT2)    // 100b/100/x/x RCV HBW Option for VGA / BUF / VGA_BUF Respectively
#define CND003_PCIEPHYCFG_RX_RECOVERY_SETTING_LANE02_EP_G1 0x1BC // RX Recovery Setting Lane02 EP G1
    #define CND003_PCIEPHYCFG_FRP02_FTXSWN_G1_EP_1_0   (BIT6 + BIT7)           // 00b/00/x/x PCIe Lane Far-end TX Swing and De-emphasis as Reference for RX Equ...
    #define CND003_PCIEPHYCFG_FRP02_RXCLKSEL_G1_EP_2_0 (BIT3 + BIT4 + BIT5)    // 0/0/x/x Rising Edge of RXCLK Select
    #define CND003_PCIEPHYCFG_FRP02_RCV_HBW_G1_EP_2_0  (BIT0 + BIT1 + BIT2)    // 100b/100/x/x RCV HBW Option for VGA / BUF / VGA_BUF Respectively
#define CND003_PCIEPHYCFG_RX_RECOVERY_SETTING_LANE03_EP_G1 0x1BD // RX Recovery Setting Lane03 EP G1
    #define CND003_PCIEPHYCFG_FRP03_FTXSWN_G1_EP_1_0   (BIT6 + BIT7)           // 00b/00/x/x PCIe Lane Far-end TX Swing and De-emphasis as Reference for RX Equ...
    #define CND003_PCIEPHYCFG_FRP03_RXCLKSEL_G1_EP_2_0 (BIT3 + BIT4 + BIT5)    // 0/0/x/x Rising Edge of RXCLK Select
    #define CND003_PCIEPHYCFG_FRP03_RCV_HBW_G1_EP_2_0  (BIT0 + BIT1 + BIT2)    // 100b/100/x/x RCV HBW Option for VGA / BUF / VGA_BUF Respectively
#define CND003_PCIEPHYCFG_RX_RECOVERY_SETTING_LANE00_PHYC_G1 0x1BE // RX Recovery Setting Lane00 PHYC G1
    #define CND003_PCIEPHYCFG_FRP00_FTXSWN_PHYC_G1 PCIEPHYCFG_RX_RECOVERY_SETTING_LANE00_PHYC_G1 // 0/0/x/x Reserved
#define CND003_PCIEPHYCFG_RX_RECOVERY_SETTING_LANE01_PHYC_G1 0x1BF // RX Recovery Setting Lane01 PHYC G1
    #define CND003_PCIEPHYCFG_FRP01_FTXSWN_PHYC_G1_1_0 PCIEPHYCFG_RX_RECOVERY_SETTING_LANE01_PHYC_G1 // 0/0/x/x Reserved
#define CND003_PCIEPHYCFG_RESERVED_Z4 0x1C0 // Reserved
    #define CND003_PCIEPHYCFG_RSVPCIEPHYCFG_1C0_7 PCIEPHYCFG_RESERVED_Z4 // 0/x/x/x Reserved
#define CND003_PCIEPHYCFG_RX_RECOVERY_SETTING_LANE00_G2 0x1D0 // RX Recovery Setting Lane00 G2
    #define CND003_PCIEPHYCFG_FRP00_FTXSWN_G2_PHYB PCIEPHYCFG_RX_RECOVERY_SETTING_LANE00_G2 // 0/0/x/x Reserved
#define CND003_PCIEPHYCFG_RX_RECOVERY_SETTING_LANE04_PHYA_G2 0x1D1 // RX Recovery Setting Lane04 PHYA G2
    #define CND003_PCIEPHYCFG_FRP04_FTXSWN_G2_PHYA_1_0     (BIT6 + BIT7)           // 00b/00/x/x PCIe Lane Far-end TX Swing and De-emphasis as Reference for RX Equ...
    #define CND003_PCIEPHYCFG_FRP04_RXCLKSEL_G2_PHYA_2_0   (BIT3 + BIT4 + BIT5)    // 0/0/x/x Rising Edge of RXCLK Select
    #define CND003_PCIEPHYCFG_FRP04_RCV_HBW_G2_PHYA_2_0    (BIT0 + BIT1 + BIT2)    // 101b/101/x/x RCV HBW Option for VGA / BUF / VGA_BUF Respectively
#define CND003_PCIEPHYCFG_RX_RECOVERY_SETTING_LANE00_PHYA_G2 0x1D2 // RX Recovery Setting Lane00 PHYA G2
    #define CND003_PCIEPHYCFG_FRP00_FTXSWN_G2_PHYA_1_0     (BIT6 + BIT7)           // 00b/00/x/x PCIe Lane Far-end TX Swing and De-emphasis as Reference for RX Equ...
    #define CND003_PCIEPHYCFG_FRP00_RXCLKSEL_G2_PHYA_2_0   (BIT3 + BIT4 + BIT5)    // 0/0/x/x Rising Edge of RXCLK Select
    #define CND003_PCIEPHYCFG_FRP00_RCV_HBW_G2_PHYA_2_0    (BIT0 + BIT1 + BIT2)    // 101b/101/x/x RCV HBW Option for VGA / BUF / VGA_BUF Respectively
#define CND003_PCIEPHYCFG_RX_RECOVERY_SETTING_LANE01_PHYA_G2 0x1D3 // RX Recovery Setting Lane01 PHYA G2
    #define CND003_PCIEPHYCFG_FRP01_FTXSWN_G2_PHYA_1_0     (BIT6 + BIT7)           // 00b/00/x/x PCIe Lane Far-end TX Swing and De-emphasis as Reference for RX Equ...
    #define CND003_PCIEPHYCFG_FRP01_RXCLKSEL_G2_PHYA_2_0   (BIT3 + BIT4 + BIT5)    // 0/0/x/x Rising Edge of RXCLK Select
    #define CND003_PCIEPHYCFG_FRP01_RCV_HBW_G2_PHYA_2_0    (BIT0 + BIT1 + BIT2)    // 101b/101/x/x RCV HBW Option for VGA / BUF / VGA_BUF Respectively
#define CND003_PCIEPHYCFG_RX_RECOVERY_SETTING_LANE02_PHYA_G2 0x1D4 // RX Recovery Setting Lane02 PHYA G2
    #define CND003_PCIEPHYCFG_FRP02_FTXSWN_G2_PHYA_1_0     (BIT6 + BIT7)           // 00b/00/x/x PCIe Lane Far-end TX Swing and De-emphasis as Reference for RX Equ...
    #define CND003_PCIEPHYCFG_FRP02_RXCLKSEL_G2_PHYA_2_0   (BIT3 + BIT4 + BIT5)    // 0/0/x/x Rising Edge of RXCLK Select
    #define CND003_PCIEPHYCFG_FRP02_RCV_HBW_G2_PHYA_2_0    (BIT0 + BIT1 + BIT2)    // 101b/101/x/x RCV HBW Option for VGA / BUF / VGA_BUF Respectively
#define CND003_PCIEPHYCFG_RX_RECOVERY_SETTING_LANE03_PHYA_G2 0x1D5 // RX Recovery Setting Lane03 PHYA G2
    #define CND003_PCIEPHYCFG_FRP03_FTXSWN_G2_PHYA_1_0     (BIT6 + BIT7)           // 00b/00/x/x PCIe Lane Far-end TX Swing and De-emphasis as Reference for RX Equ...
    #define CND003_PCIEPHYCFG_FRP03_RXCLKSEL_G2_PHYA_2_0   (BIT3 + BIT4 + BIT5)    // 0/0/x/x Rising Edge of RXCLK Select
    #define CND003_PCIEPHYCFG_FRP03_RCV_HBW_G2_PHYA_2_0    (BIT0 + BIT1 + BIT2)    // 101b/101/x/x RCV HBW Option for VGA / BUF / VGA_BUF Respectively
#define CND003_PCIEPHYCFG_RX_RECOVERY_SETTING_LANE00_PHYB_G2 0x1D6 // RX Recovery Setting Lane00 PHYB G2
    #define CND003_PCIEPHYCFG_FRP00_FTXSWN_G2_PHYB_1_0     (BIT6 + BIT7)           // 00b/00/x/x PCIe Lane Far-end TX Swing and De-emphasis as Reference for RX Equ...
    #define CND003_PCIEPHYCFG_FRP00_RXCLKSEL_G2_PHYB_2_0   (BIT3 + BIT4 + BIT5)    // 0/0/x/x Rising Edge of RXCLK Select
    #define CND003_PCIEPHYCFG_FRP00_RCV_HBW_G2_PHYB_2_0    (BIT0 + BIT1 + BIT2)    // 101b/101/x/x RCV HBW Option for VGA / BUF / VGA_BUF Respectively
#define CND003_PCIEPHYCFG_RX_RECOVERY_SETTING_LANE01_PHYB_G2 0x1D7 // RX Recovery Setting Lane01 PHYB G2
    #define CND003_PCIEPHYCFG_FRP01_FTXSWN_G2_PHYB_1_0     (BIT6 + BIT7)           // 00b/00/x/x PCIe Lane Far-end TX Swing and De-emphasis as Reference for RX Equ...
    #define CND003_PCIEPHYCFG_FRP01_RXCLKSEL_G2_PHYB_2_0   (BIT3 + BIT4 + BIT5)    // 0/0/x/x Rising Edge of RXCLK Select
    #define CND003_PCIEPHYCFG_FRP01_RCV_HBW_G2_PHYB_2_0    (BIT0 + BIT1 + BIT2)    // 101b/101/x/x RCV HBW Option for VGA / BUF / VGA_BUF Respectively
#define CND003_PCIEPHYCFG_RX_RECOVERY_SETTING_LANE02_PHYB_G2 0x1D8 // RX Recovery Setting Lane02 PHYB G2
    #define CND003_PCIEPHYCFG_FRP02_FTXSWN_G2_PHYB_1_0     (BIT6 + BIT7)           // 00b/00/x/x PCIe Lane Far-end TX Swing and De-emphasis as Reference for RX Equ...
    #define CND003_PCIEPHYCFG_FRP02_RXCLKSEL_G2_PHYB_2_0   (BIT3 + BIT4 + BIT5)    // 0/0/x/x Rising Edge of RXCLK Select
    #define CND003_PCIEPHYCFG_FRP02_RCV_HBW_G2_PHYB_2_0    (BIT0 + BIT1 + BIT2)    // 101b/101/x/x RCV HBW Option for VGA / BUF / VGA_BUF Respectively
#define CND003_PCIEPHYCFG_RX_RECOVERY_SETTING_LANE03_PHYB_G2 0x1D9 // RX Recovery Setting Lane03 PHYB G2
    #define CND003_PCIEPHYCFG_FRP03_FTXSWN_G2_PHYB_1_0     (BIT6 + BIT7)           // 00b/00/x/x PCIe Lane Far-end TX Swing and De-emphasis as Reference for RX Equ...
    #define CND003_PCIEPHYCFG_FRP03_RXCLKSEL_G2_PHYB_2_0   (BIT3 + BIT4 + BIT5)    // 0/0/x/x Rising Edge of RXCLK Select
    #define CND003_PCIEPHYCFG_FRP03_RCV_HBW_G2_PHYB_2_0    (BIT0 + BIT1 + BIT2)    // 101b/101/x/x RCV HBW Option for VGA / BUF / VGA_BUF Respectively
#define CND003_PCIEPHYCFG_RX_RECOVERY_SETTING_LANE00_EP_G2 0x1DA // RX Recovery Setting Lane00 EP G2
    #define CND003_PCIEPHYCFG_FRP00_FTXSWN_G2_EP_1_0   (BIT6 + BIT7)           // 00b/00/x/x PCIe Lane Far-end TX Swing and De-emphasis as Reference for RX Equ...
    #define CND003_PCIEPHYCFG_FRP00_RXCLKSEL_G2_EP_2_0 (BIT3 + BIT4 + BIT5)    // 0/0/x/x Rising Edge of RXCLK Select
    #define CND003_PCIEPHYCFG_FRP00_RCV_HBW_G2_EP_2_0  (BIT0 + BIT1 + BIT2)    // 101b/101/x/x RCV HBW Option for VGA / BUF / VGA_BUF Respectively
#define CND003_PCIEPHYCFG_RX_RECOVERY_SETTING_LANE01_EP_G2 0x1DB // RX Recovery Setting Lane01 EP G2
    #define CND003_PCIEPHYCFG_FRP01_FTXSWN_G2_EP_1_0   (BIT6 + BIT7)           // 00b/00/x/x PCIe Lane Far-end TX Swing and De-emphasis as Reference for RX Equ...
    #define CND003_PCIEPHYCFG_FRP01_RXCLKSEL_G2_EP_2_0 (BIT3 + BIT4 + BIT5)    // 0/0/x/x Rising Edge of RXCLK Select
    #define CND003_PCIEPHYCFG_FRP01_RCV_HBW_G2_EP_2_0  (BIT0 + BIT1 + BIT2)    // 101b/101/x/x RCV HBW Option for VGA / BUF / VGA_BUF Respectively
#define CND003_PCIEPHYCFG_RX_RECOVERY_SETTING_LANE02_EP_G2 0x1DC // RX Recovery Setting Lane02 EP G2
    #define CND003_PCIEPHYCFG_FRP02_FTXSWN_G2_EP_1_0   (BIT6 + BIT7)           // 00b/00/x/x PCIe Lane Far-end TX Swing and De-emphasis as Reference for RX Equ...
    #define CND003_PCIEPHYCFG_FRP02_RXCLKSEL_G2_EP_2_0 (BIT3 + BIT4 + BIT5)    // 0/0/x/x Rising Edge of RXCLK Select
    #define CND003_PCIEPHYCFG_FRP02_RCV_HBW_G2_EP_2_0  (BIT0 + BIT1 + BIT2)    // 101b/101/x/x RCV HBW Option for VGA / BUF / VGA_BUF Respectively
#define CND003_PCIEPHYCFG_RX_RECOVERY_SETTING_LANE03_EP_G2 0x1DD // RX Recovery Setting Lane03 EP G2
    #define CND003_PCIEPHYCFG_FRP03_FTXSWN_G2_EP_1_0   (BIT6 + BIT7)           // 00b/00/x/x PCIe Lane Far-end TX Swing and De-emphasis as Reference for RX Equ...
    #define CND003_PCIEPHYCFG_FRP03_RXCLKSEL_G2_EP_2_0 (BIT3 + BIT4 + BIT5)    // 0/0/x/x Rising Edge of RXCLK Select
    #define CND003_PCIEPHYCFG_FRP03_RCV_HBW_G2_EP_2_0  (BIT0 + BIT1 + BIT2)    // 101b/101/x/x RCV HBW Option for VGA / BUF / VGA_BUF Respectively
#define CND003_PCIEPHYCFG_RX_RECOVERY_SETTING_LANE00_PHYC_G2 0x1DE // RX Recovery Setting Lane00 PHYC G2
    #define CND003_PCIEPHYCFG_FRP00_FTXSWN_PHYC_G2 PCIEPHYCFG_RX_RECOVERY_SETTING_LANE00_PHYC_G2 // 0/0/x/x Reserved
#define CND003_PCIEPHYCFG_RX_RECOVERY_SETTING_LANE01_PHYC_G2 0x1DF // RX Recovery Setting Lane01 PHYC G2
    #define CND003_PCIEPHYCFG_FRP01_FTXSWN_PHYC_G2 PCIEPHYCFG_RX_RECOVERY_SETTING_LANE01_PHYC_G2 // 0/0/x/x Reserved
#define CND003_PCIEPHYCFG_RESERVED_Z5 0x1E0 // Reserved
    #define CND003_PCIEPHYCFG_RSVPCIEPHYCFG_1E0_7 PCIEPHYCFG_RESERVED_Z5 // 0/x/x/x Reserved
#define CND003_PCIEPHYCFG_RX_RECOVERY_SETTING_LANE00_G3 0x1F0 // RX Recovery Setting Lane00 G3
    #define CND003_PCIEPHYCFG_FRP00_FTXSWN_G3_PHYB PCIEPHYCFG_RX_RECOVERY_SETTING_LANE00_G3 // 0/0/x/x Reserved
#define CND003_PCIEPHYCFG_RX_RECOVERY_SETTING_LANE04_PHYA_G3 0x1F1 // RX Recovery Setting Lane04 PHYA G3
    #define CND003_PCIEPHYCFG_FRP04_FTXSWN_G3_PHYA_1_0     (BIT6 + BIT7)           // 00b/00/x/x PCIe Lane Far-end TX Swing and De-emphasis as Reference for RX Equ...
    #define CND003_PCIEPHYCFG_FRP04_RXCLKSEL_G3_PHYA_2_0   (BIT3 + BIT4 + BIT5)    // 0/0/x/x Rising Edge of RXCLK Select
    #define CND003_PCIEPHYCFG_FRP04_RCV_HBW_G3_PHYA_2_0    (BIT0 + BIT1 + BIT2)    // 101b/101/x/x RCV HBW Option for VGA / BUF / VGA_BUF Respectively
#define CND003_PCIEPHYCFG_RX_RECOVERY_SETTING_LANE00_PHYA_G3 0x1F2 // RX Recovery Setting Lane00 PHYA G3
    #define CND003_PCIEPHYCFG_FRP00_FTXSWN_G3_PHYA_1_0     (BIT6 + BIT7)           // 00b/00/x/x PCIe Lane Far-end TX Swing and De-emphasis as Reference for RX Equ...
    #define CND003_PCIEPHYCFG_FRP00_RXCLKSEL_G3_PHYA_2_0   (BIT3 + BIT4 + BIT5)    // 0/0/x/x Rising Edge of RXCLK Select
    #define CND003_PCIEPHYCFG_FRP00_RCV_HBW_G3_PHYA_2_0    (BIT0 + BIT1 + BIT2)    // 101b/101/x/x RCV HBW Option for VGA / BUF / VGA_BUF Respectively
#define CND003_PCIEPHYCFG_RX_RECOVERY_SETTING_LANE01_PHYA_G3 0x1F3 // RX Recovery Setting Lane01 PHYA G3
    #define CND003_PCIEPHYCFG_FRP01_FTXSWN_G3_PHYA_1_0     (BIT6 + BIT7)           // 00b/00/x/x PCIe Lane Far-end TX Swing and De-emphasis as Reference for RX Equ...
    #define CND003_PCIEPHYCFG_FRP01_RXCLKSEL_G3_PHYA_2_0   (BIT3 + BIT4 + BIT5)    // 0/0/x/x Rising Edge of RXCLK Select
    #define CND003_PCIEPHYCFG_FRP01_RCV_HBW_G3_PHYA_2_0    (BIT0 + BIT1 + BIT2)    // 101b/101/x/x RCV HBW Option for VGA / BUF / VGA_BUF Respectively
#define CND003_PCIEPHYCFG_RX_RECOVERY_SETTING_LANE02_PHYA_G3 0x1F4 // RX Recovery Setting Lane02 PHYA G3
    #define CND003_PCIEPHYCFG_FRP02_FTXSWN_G3_PHYA_1_0     (BIT6 + BIT7)           // 00b/00/x/x PCIe Lane Far-end TX Swing and De-emphasis as Reference for RX Equ...
    #define CND003_PCIEPHYCFG_FRP02_RXCLKSEL_G3_PHYA_2_0   (BIT3 + BIT4 + BIT5)    // 0/0/x/x Rising Edge of RXCLK Select
    #define CND003_PCIEPHYCFG_FRP02_RCV_HBW_G3_PHYA_2_0    (BIT0 + BIT1 + BIT2)    // 101b/101/x/x RCV HBW Option for VGA / BUF / VGA_BUF Respectively
#define CND003_PCIEPHYCFG_RX_RECOVERY_SETTING_LANE03_PHYA_G3 0x1F5 // RX Recovery Setting Lane03 PHYA G3
    #define CND003_PCIEPHYCFG_FRP03_FTXSWN_G3_PHYA_1_0     (BIT6 + BIT7)           // 00b/00/x/x PCIe Lane Far-end TX Swing and De-emphasis as Reference for RX Equ...
    #define CND003_PCIEPHYCFG_FRP03_RXCLKSEL_G3_PHYA_2_0   (BIT3 + BIT4 + BIT5)    // 0/0/x/x Rising Edge of RXCLK Select
    #define CND003_PCIEPHYCFG_FRP03_RCV_HBW_G3_PHYA_2_0    (BIT0 + BIT1 + BIT2)    // 101b/101/x/x RCV HBW Option for VGA / BUF / VGA_BUF Respectively
#define CND003_PCIEPHYCFG_RX_RECOVERY_SETTING_LANE00_PHYB_G3 0x1F6 // RX Recovery Setting Lane00 PHYB G3
    #define CND003_PCIEPHYCFG_FRP00_FTXSWN_G3_PHYB_1_0     (BIT6 + BIT7)           // 00b/00/x/x PCIe Lane Far-end TX Swing and De-emphasis as Reference for RX Equ...
    #define CND003_PCIEPHYCFG_FRP00_RXCLKSEL_G3_PHYB_2_0   (BIT3 + BIT4 + BIT5)    // 0/0/x/x Rising Edge of RXCLK Select
    #define CND003_PCIEPHYCFG_FRP00_RCV_HBW_G3_PHYB_2_0    (BIT0 + BIT1 + BIT2)    // 101b/101/x/x RCV HBW Option for VGA / BUF / VGA_BUF Respectively
#define CND003_PCIEPHYCFG_RX_RECOVERY_SETTING_LANE01_PHYB_G3 0x1F7 // RX Recovery Setting Lane01 PHYB G3
    #define CND003_PCIEPHYCFG_FRP01_FTXSWN_G3_PHYB_1_0     (BIT6 + BIT7)           // 00b/00/x/x PCIe Lane Far-end TX Swing and De-emphasis as Reference for RX Equ...
    #define CND003_PCIEPHYCFG_FRP01_RXCLKSEL_G3_PHYB_2_0   (BIT3 + BIT4 + BIT5)    // 0/0/x/x Rising Edge of RXCLK Select
    #define CND003_PCIEPHYCFG_FRP01_RCV_HBW_G3_PHYB_2_0    (BIT0 + BIT1 + BIT2)    // 101b/101/x/x RCV HBW Option for VGA / BUF / VGA_BUF Respectively
#define CND003_PCIEPHYCFG_RX_RECOVERY_SETTING_LANE02_PHYB_G3 0x1F8 // RX Recovery Setting Lane02 PHYB G3
    #define CND003_PCIEPHYCFG_FRP02_FTXSWN_G3_PHYB_1_0     (BIT6 + BIT7)           // 00b/00/x/x PCIe Lane Far-end TX Swing and De-emphasis as Reference for RX Equ...
    #define CND003_PCIEPHYCFG_FRP02_RXCLKSEL_G3_PHYB_2_0   (BIT3 + BIT4 + BIT5)    // 0/0/x/x Rising Edge of RXCLK Select
    #define CND003_PCIEPHYCFG_FRP02_RCV_HBW_G3_PHYB_2_0    (BIT0 + BIT1 + BIT2)    // 101b/101/x/x RCV HBW Option for VGA / BUF / VGA_BUF Respectively
#define CND003_PCIEPHYCFG_RX_RECOVERY_SETTING_LANE03_PHYB_G3 0x1F9 // RX Recovery Setting Lane03 PHYB G3
    #define CND003_PCIEPHYCFG_FRP03_FTXSWN_G3_PHYB_1_0     (BIT6 + BIT7)           // 00b/00/x/x PCIe Lane Far-end TX Swing and De-emphasis as Reference for RX Equ...
    #define CND003_PCIEPHYCFG_FRP03_RXCLKSEL_G3_PHYB_2_0   (BIT3 + BIT4 + BIT5)    // 0/0/x/x Rising Edge of RXCLK Select
    #define CND003_PCIEPHYCFG_FRP03_RCV_HBW_G3_PHYB_2_0    (BIT0 + BIT1 + BIT2)    // 101b/101/x/x RCV HBW Option for VGA / BUF / VGA_BUF Respectively
#define CND003_PCIEPHYCFG_RX_RECOVERY_SETTING_LANE00_EP_G3 0x1FA // RX Recovery Setting Lane00 EP G3
    #define CND003_PCIEPHYCFG_FRP00_FTXSWN_G3_EP_1_0   (BIT6 + BIT7)           // 00b/00/x/x PCIe Lane Far-end TX Swing and De-emphasis as Reference for RX Equ...
    #define CND003_PCIEPHYCFG_FRP00_RXCLKSEL_G3_EP_2_0 (BIT3 + BIT4 + BIT5)    // 0/0/x/x Rising Edge of RXCLK Select
    #define CND003_PCIEPHYCFG_FRP00_RCV_HBW_G3_EP_2_0  (BIT0 + BIT1 + BIT2)    // 101b/101/x/x RCV HBW Option for VGA / BUF / VGA_BUF Respectively
#define CND003_PCIEPHYCFG_RX_RECOVERY_SETTING_LANE01_EP_G3 0x1FB // RX Recovery Setting Lane01 EP G3
    #define CND003_PCIEPHYCFG_FRP01_FTXSWN_G3_EP_1_0   (BIT6 + BIT7)           // 00b/00/x/x PCIe Lane Far-end TX Swing and De-emphasis as Reference for RX Equ...
    #define CND003_PCIEPHYCFG_FRP01_RXCLKSEL_G3_EP_2_0 (BIT3 + BIT4 + BIT5)    // 0/0/x/x Rising Edge of RXCLK Select
    #define CND003_PCIEPHYCFG_FRP01_RCV_HBW_G3_EP_2_0  (BIT0 + BIT1 + BIT2)    // 101b/101/x/x RCV HBW Option for VGA / BUF / VGA_BUF Respectively
#define CND003_PCIEPHYCFG_RX_RECOVERY_SETTING_LANE02_EP_G3 0x1FC // RX Recovery Setting Lane02 EP G3
    #define CND003_PCIEPHYCFG_FRP02_FTXSWN_G3_EP_1_0   (BIT6 + BIT7)           // 00b/00/x/x PCIe Lane Far-end TX Swing and De-emphasis as Reference for RX Equ...
    #define CND003_PCIEPHYCFG_FRP02_RXCLKSEL_G3_EP_2_0 (BIT3 + BIT4 + BIT5)    // 0/0/x/x Rising Edge of RXCLK Select
    #define CND003_PCIEPHYCFG_FRP02_RCV_HBW_G3_EP_2_0  (BIT0 + BIT1 + BIT2)    // 101b/101/x/x RCV HBW Option for VGA / BUF / VGA_BUF Respectively
#define CND003_PCIEPHYCFG_RX_RECOVERY_SETTING_LANE03_EP_G3 0x1FD // RX Recovery Setting Lane03 EP G3
    #define CND003_PCIEPHYCFG_FRP03_FTXSWN_G3_EP_1_0   (BIT6 + BIT7)           // 00b/00/x/x PCIe Lane Far-end TX Swing and De-emphasis as Reference for RX Equ...
    #define CND003_PCIEPHYCFG_FRP03_RXCLKSEL_G3_EP_2_0 (BIT3 + BIT4 + BIT5)    // 0/0/x/x Rising Edge of RXCLK Select
    #define CND003_PCIEPHYCFG_FRP03_RCV_HBW_G3_EP_2_0  (BIT0 + BIT1 + BIT2)    // 101b/101/x/x RCV HBW Option for VGA / BUF / VGA_BUF Respectively
#define CND003_PCIEPHYCFG_RX_RECOVERY_SETTING_LANE00_PHYC_G3 0x1FE // RX Recovery Setting Lane00 PHYC G3
    #define CND003_PCIEPHYCFG_FRP00_FTXSWN_PHYC_G3 PCIEPHYCFG_RX_RECOVERY_SETTING_LANE00_PHYC_G3 // 0/0/x/x Reserved
#define CND003_PCIEPHYCFG_RX_RECOVERY_SETTING_LANE01_PHYC_G3 0x1FF // RX Recovery Setting Lane01 PHYC G3
    #define CND003_PCIEPHYCFG_FRP01_FTXSWN_PHYC_G3 PCIEPHYCFG_RX_RECOVERY_SETTING_LANE01_PHYC_G3 // 0/0/x/x Reserved
#define CND003_PCIEPHYCFG_RESERVED_Z6 0x200 // Reserved
    #define CND003_PCIEPHYCFG_RSVPCIEPHYCFG_203_7 PCIEPHYCFG_RESERVED_Z6 // 0/x/x/x Reserved
#define CND003_PCIEPHYCFG_LOW_PWR_EXIT_LATENCY_LANE00_G1 0x210 // Low Power Exit Latency Lane00 G1
    #define CND003_PCIEPHYCFG_RSVPCIEPHYCFG_210_7 PCIEPHYCFG_LOW_PWR_EXIT_LATENCY_LANE00_G1 // 0/x/x/x Reserved
#define CND003_PCIEPHYCFG_LOW_PWR_EXIT_LATENCY_LANE04_PHYA_G1 0x212 // Low Power Exit Latency Lane04 PHYA G1
    #define CND003_PCIEPHYCFG_RSVPCIEPHYCFG_212_7          0xF000                  // 0/x/x/x Reserved
    #define CND003_PCIEPHYCFG_FRP04_FDRATIO_G1_PHYA_2_0    (BIT9 + BIT10 + BIT11)  // 010b/010/x/x FD Mode Ratio during P1 to P0
    #define CND003_PCIEPHYCFG_FRP04_FTSRATIO_G1_PHYA_2_0   (BIT6 + BIT7 + BIT8)    // 100b/100/x/x PD Trainingmode Ratio during P0s to P0
    #define CND003_PCIEPHYCFG_FRP04_P1EXT_G1_PHYA_2_0      (BIT3 + BIT4 + BIT5)    // 100b/100/x/x ExitLatency P1 Exit Latency
    #define CND003_PCIEPHYCFG_FRP04_P0SP2EXT_G1_PHYA_2_0   (BIT0 + BIT1 + BIT2)    // 100b/100/x/x ExitLatency P0s Exit Latency
#define CND003_PCIEPHYCFG_LOW_PWR_EXIT_LATENCY_LANE00_PHYA_G1 0x214 // Low Power Exit Latency Lane00 PHYA G1
    #define CND003_PCIEPHYCFG_RSVPCIEPHYCFG_214_7          0xF000                  // 0/x/x/x Reserved
    #define CND003_PCIEPHYCFG_FRP00_FDRATIO_G1_PHYA_2_0    (BIT9 + BIT10 + BIT11)  // 010b/010/x/x FD Mode Ratio during P1 to P0
    #define CND003_PCIEPHYCFG_FRP00_FTSRATIO_G1_PHYA_2_0   (BIT6 + BIT7 + BIT8)    // 100b/100/x/x PD Trainingmode Ratio during P0s to P0
    #define CND003_PCIEPHYCFG_FRP00_P1EXT_G1_PHYA_2_0      (BIT3 + BIT4 + BIT5)    // 100b/100/x/x ExitLatency P1 Exit Latency
    #define CND003_PCIEPHYCFG_FRP00_P0SP2EXT_G1_PHYA_2_0   (BIT0 + BIT1 + BIT2)    // 100b/100/x/x ExitLatency P0s Exit Latency
#define CND003_PCIEPHYCFG_LOW_PWR_EXIT_LATENCY_LANE01_PHYA_G1 0x216 // Low Power Exit Latency Lane01 PHYA G1
    #define CND003_PCIEPHYCFG_RSVPCIEPHYCFG_216_7          0xF000                  // 0/x/x/x Reserved
    #define CND003_PCIEPHYCFG_FRP01_FDRATIO_G1_PHYA_2_0    (BIT9 + BIT10 + BIT11)  // 010b/010/x/x FD Mode Ratio during P1 to P0
    #define CND003_PCIEPHYCFG_FRP01_FTSRATIO_G1_PHYA_2_0   (BIT6 + BIT7 + BIT8)    // 100b/100/x/x PD Trainingmode Ratio during P0s to P0
    #define CND003_PCIEPHYCFG_FRP01_P1EXT_G1_PHYA_2_0      (BIT3 + BIT4 + BIT5)    // 100b/100/x/x ExitLatency P1 Exit Latency
    #define CND003_PCIEPHYCFG_FRP01_P0SP2EXT_G1_PHYA_2_0   (BIT0 + BIT1 + BIT2)    // 100b/100/x/x ExitLatency P0s Exit Latency
#define CND003_PCIEPHYCFG_LOW_PWR_EXIT_LATENCY_LANE02_PHYA_G1 0x218 // Low Power Exit Latency Lane02 PHYA G1
    #define CND003_PCIEPHYCFG_RSVPCIEPHYCFG_218_7          0xF000                  // 0/x/x/x Reserved
    #define CND003_PCIEPHYCFG_FRP02_FDRATIO_G1_PHYA_2_0    (BIT9 + BIT10 + BIT11)  // 010b/010/x/x FD Mode Ratio during P1 to P0
    #define CND003_PCIEPHYCFG_FRP02_FTSRATIO_G1_PHYA_2_0   (BIT6 + BIT7 + BIT8)    // 100b/100/x/x PD Trainingmode Ratio during P0s to P0
    #define CND003_PCIEPHYCFG_FRP02_P1EXT_G1_PHYA_2_0      (BIT3 + BIT4 + BIT5)    // 100b/100/x/x ExitLatency P1 Exit Latency
    #define CND003_PCIEPHYCFG_FRP02_P0SP2EXT_G1_PHYA_2_0   (BIT0 + BIT1 + BIT2)    // 100b/100/x/x ExitLatency P0s Exit Latency
#define CND003_PCIEPHYCFG_LOW_PWR_EXIT_LATENCY_LANE03_PHYA_G1 0x21A // Low Power Exit Latency Lane03 PHYA G1
    #define CND003_PCIEPHYCFG_RSVPCIEPHYCFG_21A_7          0xF000                  // 0/x/x/x Reserved
    #define CND003_PCIEPHYCFG_FRP03_FDRATIO_G1_PHYA_2_0    (BIT9 + BIT10 + BIT11)  // 010b/010/x/x FD Mode Ratio during P1 to P0
    #define CND003_PCIEPHYCFG_FRP03_FTSRATIO_G1_PHYA_2_0   (BIT6 + BIT7 + BIT8)    // 100b/100/x/x PD Trainingmode Ratio during P0s to P0
    #define CND003_PCIEPHYCFG_FRP03_P1EXT_G1_PHYA_2_0      (BIT3 + BIT4 + BIT5)    // 100b/100/x/x ExitLatency P1 Exit Latency
    #define CND003_PCIEPHYCFG_FRP03_P0SP2EXT_G1_PHYA_2_0   (BIT0 + BIT1 + BIT2)    // 100b/100/x/x ExitLatency P0s Exit Latency
#define CND003_PCIEPHYCFG_LOW_PWR_EXIT_LATENCY_LANE00_PHYB_G1 0x21C // Low Power Exit Latency Lane00 PHYB G1
    #define CND003_PCIEPHYCFG_RSVPCIEPHYCFG_21C_7          0xF000                  // 0/x/x/x Reserved
    #define CND003_PCIEPHYCFG_FRP00_FDRATIO_G1_PHYB_2_0    (BIT9 + BIT10 + BIT11)  // 010b/010/x/x FD Mode Ratio during P1 to P0
    #define CND003_PCIEPHYCFG_FRP00_FTSRATIO_G1_PHYB_2_0   (BIT6 + BIT7 + BIT8)    // 100b/100/x/x PD Trainingmode Ratio during P0s to P0
    #define CND003_PCIEPHYCFG_FRP00_P1EXT_G1_PHYB_2_0      (BIT3 + BIT4 + BIT5)    // 100b/100/x/x ExitLatency P1 Exit Latency
    #define CND003_PCIEPHYCFG_FRP00_P0SP2EXT_G1_PHYB_2_0   (BIT0 + BIT1 + BIT2)    // 100b/100/x/x ExitLatency P0s Exit Latency
#define CND003_PCIEPHYCFG_LOW_PWR_EXIT_LATENCY_LANE01_PHYB_G1 0x21E // Low Power Exit Latency Lane01 PHYB G1
    #define CND003_PCIEPHYCFG_RSVPCIEPHYCFG_21E_7          0xF000                  // 0/x/x/x Reserved
    #define CND003_PCIEPHYCFG_FRP01_FDRATIO_G1_PHYB_2_0    (BIT9 + BIT10 + BIT11)  // 010b/010/x/x FD Mode Ratio during P1 to P0
    #define CND003_PCIEPHYCFG_FRP01_FTSRATIO_G1_PHYB_2_0   (BIT6 + BIT7 + BIT8)    // 100b/100/x/x PD Trainingmode Ratio during P0s to P0
    #define CND003_PCIEPHYCFG_FRP01_P1EXT_G1_PHYB_2_0      (BIT3 + BIT4 + BIT5)    // 100b/100/x/x ExitLatency P1 Exit Latency
    #define CND003_PCIEPHYCFG_FRP01_P0SP2EXT_G1_PHYB_2_0   (BIT0 + BIT1 + BIT2)    // 100b/100/x/x ExitLatency P0s Exit Latency
#define CND003_PCIEPHYCFG_LOW_PWR_EXIT_LATENCY_LANE02_PHYB_G1 0x220 // Low Power Exit Latency Lane02 PHYB G1
    #define CND003_PCIEPHYCFG_RSVPCIEPHYCFG_220_7          0xF000                  // 0/x/x/x Reserved
    #define CND003_PCIEPHYCFG_FRP02_FDRATIO_G1_PHYB_2_0    (BIT9 + BIT10 + BIT11)  // 010b/010/x/x FD Mode Ratio during P1 to P0
    #define CND003_PCIEPHYCFG_FRP02_FTSRATIO_G1_PHYB_2_0   (BIT6 + BIT7 + BIT8)    // 100b/100/x/x PD Trainingmode Ratio during P0s to P0
    #define CND003_PCIEPHYCFG_FRP02_P1EXT_G1_PHYB_2_0      (BIT3 + BIT4 + BIT5)    // 100b/100/x/x ExitLatency P1 Exit Latency
    #define CND003_PCIEPHYCFG_FRP02_P0SP2EXT_G1_PHYB_2_0   (BIT0 + BIT1 + BIT2)    // 100b/100/x/x ExitLatency P0s Exit Latency
#define CND003_PCIEPHYCFG_LOW_PWR_EXIT_LATENCY_LANE03_PHYB_G1 0x222 // Low Power Exit Latency Lane03 PHYB G1
    #define CND003_PCIEPHYCFG_RSVPCIEPHYCFG_222_7          0xF000                  // 0/x/x/x Reserved
    #define CND003_PCIEPHYCFG_FRP03_FDRATIO_G1_PHYB_2_0    (BIT9 + BIT10 + BIT11)  // 010b/010/x/x FD Mode Ratio during P1 to P0
    #define CND003_PCIEPHYCFG_FRP03_FTSRATIO_G1_PHYB_2_0   (BIT6 + BIT7 + BIT8)    // 100b/100/x/x PD Trainingmode Ratio during P0s to P0
    #define CND003_PCIEPHYCFG_FRP03_P1EXT_G1_PHYB_2_0      (BIT3 + BIT4 + BIT5)    // 100b/100/x/x ExitLatency P1 Exit Latency
    #define CND003_PCIEPHYCFG_FRP03_P0SP2EXT_G1_PHYB_2_0   (BIT0 + BIT1 + BIT2)    // 100b/100/x/x ExitLatency P0s Exit Latency
#define CND003_PCIEPHYCFG_LOW_PWR_EXIT_LATENCY_LANE00_EP_G1 0x224 // Low Power Exit Latency Lane00 EP G1
    #define CND003_PCIEPHYCFG_RSVPCIEPHYCFG_224_7      0xF000                  // 0/x/x/x Reserved
    #define CND003_PCIEPHYCFG_FRP00_FDRATIO_G1_EP_2_0  (BIT9 + BIT10 + BIT11)  // 010b/010/x/x FD Mode Ratio during P1 to P0
    #define CND003_PCIEPHYCFG_FRP00_FTSRATIO_G1_EP_2_0 (BIT6 + BIT7 + BIT8)    // 100b/100/x/x PD Trainingmode Ratio during P0s to P0
    #define CND003_PCIEPHYCFG_FRP00_P1EXT_G1_EP_2_0    (BIT3 + BIT4 + BIT5)    // 100b/100/x/x ExitLatency P1 Exit Latency
    #define CND003_PCIEPHYCFG_FRP00_P0SP2EXT_G1_EP_2_0 (BIT0 + BIT1 + BIT2)    // 100b/100/x/x ExitLatency P0s Exit Latency
#define CND003_PCIEPHYCFG_LOW_PWR_EXIT_LATENCY_LANE01_EP_G1 0x226 // Low Power Exit Latency Lane01 EP G1
    #define CND003_PCIEPHYCFG_RSVPCIEPHYCFG_226_7      0xF000                  // 0/x/x/x Reserved
    #define CND003_PCIEPHYCFG_FRP01_FDRATIO_G1_EP_2_0  (BIT9 + BIT10 + BIT11)  // 010b/010/x/x FD Mode Ratio during P1 to P0
    #define CND003_PCIEPHYCFG_FRP01_FTSRATIO_G1_EP_2_0 (BIT6 + BIT7 + BIT8)    // 100b/100/x/x PD Trainingmode Ratio during P0s to P0
    #define CND003_PCIEPHYCFG_FRP01_P1EXT_G1_EP_2_0    (BIT3 + BIT4 + BIT5)    // 100b/100/x/x ExitLatency P1 Exit Latency
    #define CND003_PCIEPHYCFG_FRP01_P0SP2EXT_G1_EP_2_0 (BIT0 + BIT1 + BIT2)    // 100b/100/x/x ExitLatency P0s Exit Latency
#define CND003_PCIEPHYCFG_LOW_PWR_EXIT_LATENCY_LANE02_EP_G1 0x228 // Low Power Exit Latency Lane02 EP G1
    #define CND003_PCIEPHYCFG_RSVPCIEPHYCFG_228_7      0xF000                  // 0/x/x/x Reserved
    #define CND003_PCIEPHYCFG_FRP02_FDRATIO_G1_EP_2_0  (BIT9 + BIT10 + BIT11)  // 010b/010/x/x FD Mode Ratio during P1 to P0
    #define CND003_PCIEPHYCFG_FRP02_FTSRATIO_G1_EP_2_0 (BIT6 + BIT7 + BIT8)    // 100b/100/x/x PD Trainingmode Ratio during P0s to P0
    #define CND003_PCIEPHYCFG_FRP02_P1EXT_G1_EP_2_0    (BIT3 + BIT4 + BIT5)    // 100b/100/x/x ExitLatency P1 Exit Latency
    #define CND003_PCIEPHYCFG_FRP02_P0SP2EXT_G1_EP_2_0 (BIT0 + BIT1 + BIT2)    // 100b/100/x/x ExitLatency P0s Exit Latency
#define CND003_PCIEPHYCFG_LOW_PWR_EXIT_LATENCY_LANE03_EP_G1 0x22A // Low Power Exit Latency Lane03 EP G1
    #define CND003_PCIEPHYCFG_RSVPCIEPHYCFG_22A_7      0xF000                  // 0/x/x/x Reserved
    #define CND003_PCIEPHYCFG_FRP03_FDRATIO_G1_EP_2_0  (BIT9 + BIT10 + BIT11)  // 010b/010/x/x FD Mode Ratio during P1 to P0
    #define CND003_PCIEPHYCFG_FRP03_FTSRATIO_G1_EP_2_0 (BIT6 + BIT7 + BIT8)    // 100b/100/x/x PD Trainingmode Ratio during P0s to P0
    #define CND003_PCIEPHYCFG_FRP03_P1EXT_G1_EP_2_0    (BIT3 + BIT4 + BIT5)    // 100b/100/x/x ExitLatency P1 Exit Latency
    #define CND003_PCIEPHYCFG_FRP03_P0SP2EXT_G1_EP_2_0 (BIT0 + BIT1 + BIT2)    // 100b/100/x/x ExitLatency P0s Exit Latency
#define CND003_PCIEPHYCFG_LOW_PWR_EXIT_LATENCY_LANE00_PHYC_G1 0x22C // Low Power Exit Latency Lane00 PHYC G1
    #define CND003_PCIEPHYCFG_RSVPCIPHYCHYCFG_22C_7 PCIEPHYCFG_LOW_PWR_EXIT_LATENCY_LANE00_PHYC_G1 // 0/x/x/x Reserved
#define CND003_PCIEPHYCFG_LOW_PWR_EXIT_LATENCY_LANE01_PHYC_G1 0x22E // Low Power Exit Latency Lane01 PHYC G1
    #define CND003_PCIEPHYCFG_RSVPCIPHYCHYCFG_22E_7 PCIEPHYCFG_LOW_PWR_EXIT_LATENCY_LANE01_PHYC_G1 // 0/x/x/x Reserved
#define CND003_PCIEPHYCFG_RESERVED_Z7 0x230 // Reserved
    #define CND003_PCIEPHYCFG_RSVPCIEPHYCFG_230_7 PCIEPHYCFG_RESERVED_Z7 // 0/x/x/x Reserved
#define CND003_PCIEPHYCFG_RESERVED_Z8 0x231 // Reserved
    #define CND003_PCIEPHYCFG_RSVPCIEPHYCFG_231_7 PCIEPHYCFG_RESERVED_Z8 // 0/x/x/x Reserved
#define CND003_PCIEPHYCFG_LOW_PWR_EXIT_LATENCY_LANE00_G2 0x240 // Low Power Exit Latency Lane00 G2
    #define CND003_PCIEPHYCFG_RSVPCIEPHYCFG_240_7 PCIEPHYCFG_LOW_PWR_EXIT_LATENCY_LANE00_G2 // 0/x/x/x Reserved
#define CND003_PCIEPHYCFG_LOW_PWR_EXIT_LATENCY_LANE04_PHYA_G2 0x242 // Low Power Exit Latency Lane04 PHYA G2
    #define CND003_PCIEPHYCFG_RSVPCIEPHYCFG_242_7          0xF000                  // 0/x/x/x Reserved
    #define CND003_PCIEPHYCFG_FRP04_FDRATIO_G2_PHYA_2_0    (BIT9 + BIT10 + BIT11)  // 010b/010/x/x FD Mode Ratio during P1 to P0
    #define CND003_PCIEPHYCFG_FRP04_FTSRATIO_G2_PHYA_2_0   (BIT6 + BIT7 + BIT8)    // 100b/100/x/x PD Trainingmode Ratio during P0s to P0
    #define CND003_PCIEPHYCFG_FRP04_P1EXT_G2_PHYA_2_0      (BIT3 + BIT4 + BIT5)    // 100b/100/x/x ExitLatency P1 Exit Latency
    #define CND003_PCIEPHYCFG_FRP04_P0SP2EXT_G2_PHYA_2_0   (BIT0 + BIT1 + BIT2)    // 100b/100/x/x ExitLatency P0s Exit Latency
#define CND003_PCIEPHYCFG_LOW_PWR_EXIT_LATENCY_LANE00_PHYA_G2 0x244 // Low Power Exit Latency Lane00 PHYA G2
    #define CND003_PCIEPHYCFG_RSVPCIEPHYCFG_244_7          0xF000                  // 0/x/x/x Reserved
    #define CND003_PCIEPHYCFG_FRP00_FDRATIO_G2_PHYA_2_0    (BIT9 + BIT10 + BIT11)  // 010b/010/x/x FD Mode Ratio during P1 to P0
    #define CND003_PCIEPHYCFG_FRP00_FTSRATIO_G2_PHYA_2_0   (BIT6 + BIT7 + BIT8)    // 100b/100/x/x PD Trainingmode Ratio during P0s to P0
    #define CND003_PCIEPHYCFG_FRP00_P1EXT_G2_PHYA_2_0      (BIT3 + BIT4 + BIT5)    // 100b/100/x/x ExitLatency P1 Exit Latency
    #define CND003_PCIEPHYCFG_FRP00_P0SP2EXT_G2_PHYA_2_0   (BIT0 + BIT1 + BIT2)    // 100b/100/x/x ExitLatency P0s Exit Latency
#define CND003_PCIEPHYCFG_LOW_PWR_EXIT_LATENCY_LANE01_PHYA_G2 0x246 // Low Power Exit Latency Lane01 PHYA G2
    #define CND003_PCIEPHYCFG_RSVPCIEPHYCFG_246_7          0xF000                  // 0/x/x/x Reserved
    #define CND003_PCIEPHYCFG_FRP01_FDRATIO_G2_PHYA_2_0    (BIT9 + BIT10 + BIT11)  // 010b/010/x/x FD Mode Ratio during P1 to P0
    #define CND003_PCIEPHYCFG_FRP01_FTSRATIO_G2_PHYA_2_0   (BIT6 + BIT7 + BIT8)    // 100b/100/x/x PD Trainingmode Ratio during P0s to P0
    #define CND003_PCIEPHYCFG_FRP01_P1EXT_G2_PHYA_2_0      (BIT3 + BIT4 + BIT5)    // 100b/100/x/x ExitLatency P1 Exit Latency
    #define CND003_PCIEPHYCFG_FRP01_P0SP2EXT_G2_PHYA_2_0   (BIT0 + BIT1 + BIT2)    // 100b/100/x/x ExitLatency P0s Exit Latency
#define CND003_PCIEPHYCFG_LOW_PWR_EXIT_LATENCY_LANE02_PHYA_G2 0x248 // Low Power Exit Latency Lane02 PHYA G2
    #define CND003_PCIEPHYCFG_RSVPCIEPHYCFG_248_7          0xF000                  // 0/x/x/x Reserved
    #define CND003_PCIEPHYCFG_FRP02_FDRATIO_G2_PHYA_2_0    (BIT9 + BIT10 + BIT11)  // 010b/010/x/x FD Mode Ratio during P1 to P0
    #define CND003_PCIEPHYCFG_FRP02_FTSRATIO_G2_PHYA_2_0   (BIT6 + BIT7 + BIT8)    // 100b/100/x/x PD Trainingmode Ratio during P0s to P0
    #define CND003_PCIEPHYCFG_FRP02_P1EXT_G2_PHYA_2_0      (BIT3 + BIT4 + BIT5)    // 100b/100/x/x ExitLatency P1 Exit Latency
    #define CND003_PCIEPHYCFG_FRP02_P0SP2EXT_G2_PHYA_2_0   (BIT0 + BIT1 + BIT2)    // 100b/100/x/x ExitLatency P0s Exit Latency
#define CND003_PCIEPHYCFG_LOW_PWR_EXIT_LATENCY_LANE03_PHYA_G2 0x24A // Low Power Exit Latency Lane03 PHYA G2
    #define CND003_PCIEPHYCFG_RSVPCIEPHYCFG_24A_7          0xF000                  // 0/x/x/x Reserved
    #define CND003_PCIEPHYCFG_FRP03_FDRATIO_G2_PHYA_2_0    (BIT9 + BIT10 + BIT11)  // 010b/010/x/x FD Mode Ratio during P1 to P0
    #define CND003_PCIEPHYCFG_FRP03_FTSRATIO_G2_PHYA_2_0   (BIT6 + BIT7 + BIT8)    // 100b/100/x/x PD Trainingmode Ratio during P0s to P0
    #define CND003_PCIEPHYCFG_FRP03_P1EXT_G2_PHYA_2_0      (BIT3 + BIT4 + BIT5)    // 100b/100/x/x ExitLatency P1 Exit Latency
    #define CND003_PCIEPHYCFG_FRP03_P0SP2EXT_G2_PHYA_2_0   (BIT0 + BIT1 + BIT2)    // 100b/100/x/x ExitLatency P0s Exit Latency
#define CND003_PCIEPHYCFG_LOW_PWR_EXIT_LATENCY_LANE00_PHYB_G2 0x24C // Low Power Exit Latency Lane00 PHYB G2
    #define CND003_PCIEPHYCFG_RSVPCIEPHYCFG_24C_7          0xF000                  // 0/x/x/x Reserved
    #define CND003_PCIEPHYCFG_FRP00_FDRATIO_G2_PHYB_2_0    (BIT9 + BIT10 + BIT11)  // 010b/010/x/x FD Mode Ratio during P1 to P0
    #define CND003_PCIEPHYCFG_FRP00_FTSRATIO_G2_PHYB_2_0   (BIT6 + BIT7 + BIT8)    // 100b/100/x/x PD Trainingmode Ratio during P0s to P0
    #define CND003_PCIEPHYCFG_FRP00_P1EXT_G2_PHYB_2_0      (BIT3 + BIT4 + BIT5)    // 100b/100/x/x ExitLatency P1 Exit Latency
    #define CND003_PCIEPHYCFG_FRP00_P0SP2EXT_G2_PHYB_2_0   (BIT0 + BIT1 + BIT2)    // 100b/100/x/x ExitLatency P0s Exit Latency
#define CND003_PCIEPHYCFG_LOW_PWR_EXIT_LATENCY_LANE01_PHYB_G2 0x24E // Low Power Exit Latency Lane01 PHYB G2
    #define CND003_PCIEPHYCFG_RSVPCIEPHYCFG_24E_7          0xF000                  // 0/x/x/x Reserved
    #define CND003_PCIEPHYCFG_FRP01_FDRATIO_G2_PHYB_2_0    (BIT9 + BIT10 + BIT11)  // 010b/010/x/x FD Mode Ratio during P1 to P0
    #define CND003_PCIEPHYCFG_FRP01_FTSRATIO_G2_PHYB_2_0   (BIT6 + BIT7 + BIT8)    // 100b/100/x/x PD Trainingmode Ratio during P0s to P0
    #define CND003_PCIEPHYCFG_FRP01_P1EXT_G2_PHYB_2_0      (BIT3 + BIT4 + BIT5)    // 100b/100/x/x ExitLatency P1 Exit Latency
    #define CND003_PCIEPHYCFG_FRP01_P0SP2EXT_G2_PHYB_2_0   (BIT0 + BIT1 + BIT2)    // 100b/100/x/x ExitLatency P0s Exit Latency
#define CND003_PCIEPHYCFG_LOW_PWR_EXIT_LATENCY_LANE02_PHYB_G2 0x250 // Low Power Exit Latency Lane02 PHYB G2
    #define CND003_PCIEPHYCFG_RSVPCIEPHYCFG_250_7          0xF000                  // 0/x/x/x Reserved
    #define CND003_PCIEPHYCFG_FRP02_FDRATIO_G2_PHYB_2_0    (BIT9 + BIT10 + BIT11)  // 010b/010/x/x FD Mode Ratio during P1 to P0
    #define CND003_PCIEPHYCFG_FRP02_FTSRATIO_G2_PHYB_2_0   (BIT6 + BIT7 + BIT8)    // 100b/100/x/x PD Trainingmode Ratio during P0s to P0
    #define CND003_PCIEPHYCFG_FRP02_P1EXT_G2_PHYB_2_0      (BIT3 + BIT4 + BIT5)    // 100b/100/x/x ExitLatency P1 Exit Latency
    #define CND003_PCIEPHYCFG_FRP02_P0SP2EXT_G2_PHYB_2_0   (BIT0 + BIT1 + BIT2)    // 100b/100/x/x ExitLatency P0s Exit Latency
#define CND003_PCIEPHYCFG_LOW_PWR_EXIT_LATENCY_LANE03_PHYB_G2 0x252 // Low Power Exit Latency Lane03 PHYB G2
    #define CND003_PCIEPHYCFG_RSVPCIEPHYCFG_252_7          0xF000                  // 0/x/x/x Reserved
    #define CND003_PCIEPHYCFG_FRP03_FDRATIO_G2_PHYB_2_0    (BIT9 + BIT10 + BIT11)  // 010b/010/x/x FD Mode Ratio during P1 to P0
    #define CND003_PCIEPHYCFG_FRP03_FTSRATIO_G2_PHYB_2_0   (BIT6 + BIT7 + BIT8)    // 100b/100/x/x PD Trainingmode Ratio during P0s to P0
    #define CND003_PCIEPHYCFG_FRP03_P1EXT_G2_PHYB_2_0      (BIT3 + BIT4 + BIT5)    // 100b/100/x/x ExitLatency P1 Exit Latency
    #define CND003_PCIEPHYCFG_FRP03_P0SP2EXT_G2_PHYB_2_0   (BIT0 + BIT1 + BIT2)    // 100b/100/x/x ExitLatency P0s Exit Latency
#define CND003_PCIEPHYCFG_LOW_PWR_EXIT_LATENCY_LANE00_EP_G2 0x254 // Low Power Exit Latency Lane00 EP G2
    #define CND003_PCIEPHYCFG_RSVPCIEPHYCFG_254_7      0xF000                  // 0/x/x/x Reserved
    #define CND003_PCIEPHYCFG_FRP00_FDRATIO_G2_EP_2_0  (BIT9 + BIT10 + BIT11)  // 010b/010/x/x FD Mode Ratio during P1 to P0
    #define CND003_PCIEPHYCFG_FRP00_FTSRATIO_G2_EP_2_0 (BIT6 + BIT7 + BIT8)    // 100b/100/x/x PD Trainingmode Ratio during P0s to P0
    #define CND003_PCIEPHYCFG_FRP00_P1EXT_G2_EP_2_0    (BIT3 + BIT4 + BIT5)    // 100b/100/x/x ExitLatency P1 Exit Latency
    #define CND003_PCIEPHYCFG_FRP00_P0SP2EXT_G2_EP_2_0 (BIT0 + BIT1 + BIT2)    // 100b/100/x/x ExitLatency P0s Exit Latency
#define CND003_PCIEPHYCFG_LOW_PWR_EXIT_LATENCY_LANE01_EP_G2 0x256 // Low Power Exit Latency Lane01 EP G2
    #define CND003_PCIEPHYCFG_RSVPCIEPHYCFG_256_7      0xF000                  // 0/x/x/x Reserved
    #define CND003_PCIEPHYCFG_FRP01_FDRATIO_G2_EP_2_0  (BIT9 + BIT10 + BIT11)  // 010b/010/x/x FD Mode Ratio during P1 to P0
    #define CND003_PCIEPHYCFG_FRP01_FTSRATIO_G2_EP_2_0 (BIT6 + BIT7 + BIT8)    // 100b/100/x/x PD Trainingmode Ratio during P0s to P0
    #define CND003_PCIEPHYCFG_FRP01_P1EXT_G2_EP_2_0    (BIT3 + BIT4 + BIT5)    // 100b/100/x/x ExitLatency P1 Exit Latency
    #define CND003_PCIEPHYCFG_FRP01_P0SP2EXT_G2_EP_2_0 (BIT0 + BIT1 + BIT2)    // 100b/100/x/x ExitLatency P0s Exit Latency
#define CND003_PCIEPHYCFG_LOW_PWR_EXIT_LATENCY_LANE02_EP_G2 0x258 // Low Power Exit Latency Lane02 EP G2
    #define CND003_PCIEPHYCFG_RSVPCIEPHYCFG_258_7      0xF000                  // 0/x/x/x Reserved
    #define CND003_PCIEPHYCFG_FRP02_FDRATIO_G2_EP_2_0  (BIT9 + BIT10 + BIT11)  // 010b/010/x/x FD Mode Ratio during P1 to P0
    #define CND003_PCIEPHYCFG_FRP02_FTSRATIO_G2_EP_2_0 (BIT6 + BIT7 + BIT8)    // 100b/100/x/x PD Trainingmode Ratio during P0s to P0
    #define CND003_PCIEPHYCFG_FRP02_P1EXT_G2_EP_2_0    (BIT3 + BIT4 + BIT5)    // 100b/100/x/x ExitLatency P1 Exit Latency
    #define CND003_PCIEPHYCFG_FRP02_P0SP2EXT_G2_EP_2_0 (BIT0 + BIT1 + BIT2)    // 100b/100/x/x ExitLatency P0s Exit Latency
#define CND003_PCIEPHYCFG_LOW_PWR_EXIT_LATENCY_LANE03_EP_G2 0x25A // Low Power Exit Latency Lane03 EP G2
    #define CND003_PCIEPHYCFG_RSVPCIEPHYCFG_25A_7      0xF000                  // 0/x/x/x Reserved
    #define CND003_PCIEPHYCFG_FRP03_FDRATIO_G2_EP_2_0  (BIT9 + BIT10 + BIT11)  // 010b/010/x/x FD Mode Ratio during P1 to P0
    #define CND003_PCIEPHYCFG_FRP03_FTSRATIO_G2_EP_2_0 (BIT6 + BIT7 + BIT8)    // 100b/100/x/x PD Trainingmode Ratio during P0s to P0
    #define CND003_PCIEPHYCFG_FRP03_P1EXT_G2_EP_2_0    (BIT3 + BIT4 + BIT5)    // 100b/100/x/x ExitLatency P1 Exit Latency
    #define CND003_PCIEPHYCFG_FRP03_P0SP2EXT_G2_EP_2_0 (BIT0 + BIT1 + BIT2)    // 100b/100/x/x ExitLatency P0s Exit Latency
#define CND003_PCIEPHYCFG_LOW_PWR_EXIT_LATENCY_LANE00_PHYC_G2 0x25C // Low Power Exit Latency Lane00 PHYC G2
    #define CND003_PCIEPHYCFG_RSVPCIPHYCHYCFG_25C_7 PCIEPHYCFG_LOW_PWR_EXIT_LATENCY_LANE00_PHYC_G2 // 0/x/x/x Reserved
#define CND003_PCIEPHYCFG_LOW_PWR_EXIT_LATENCY_LANE01_PHYC_G2 0x25E // Low Power Exit Latency Lane01 PHYC G2
    #define CND003_PCIEPHYCFG_RSVPCIPHYCHYCFG_25E_7 PCIEPHYCFG_LOW_PWR_EXIT_LATENCY_LANE01_PHYC_G2 // 0/x/x/x Reserved
#define CND003_PCIEPHYCFG_RESERVED_Z9 0x260 // Reserved
    #define CND003_PCIEPHYCFG_RSVPCIEPHYCFG_260_7 PCIEPHYCFG_RESERVED_Z9 // 0/x/x/x Reserved
#define CND003_PCIEPHYCFG_RESERVED_Z10 0x261 // Reserved
    #define CND003_PCIEPHYCFG_RSVPCIEPHYCFG_261_7 PCIEPHYCFG_RESERVED_Z10 // 0/x/x/x Reserved
#define CND003_PCIEPHYCFG_LOW_PWR_EXIT_LATENCY_LANE00_G3 0x270 // Low Power Exit Latency Lane00 G3
    #define CND003_PCIEPHYCFG_RSVPCIEPHYCFG_270_7 PCIEPHYCFG_LOW_PWR_EXIT_LATENCY_LANE00_G3 // 0/x/x/x Reserved
#define CND003_PCIEPHYCFG_LOW_PWR_EXIT_LATENCY_LANE04_PHYA_G3 0x272 // Low Power Exit Latency Lane04 PHYA G3
    #define CND003_PCIEPHYCFG_RSVPCIEPHYCFG_272_7          0xF000                  // 0/x/x/x Reserved
    #define CND003_PCIEPHYCFG_FRP04_FDRATIO_G3_PHYA_2_0    (BIT9 + BIT10 + BIT11)  // 010b/010/x/x FD Mode Ratio during P1 to P0
    #define CND003_PCIEPHYCFG_FRP04_FTSRATIO_G3_PHYA_2_0   (BIT6 + BIT7 + BIT8)    // 100b/100/x/x PD Trainingmode Ratio during P0s to P0
    #define CND003_PCIEPHYCFG_FRP04_P1EXT_G3_PHYA_2_0      (BIT3 + BIT4 + BIT5)    // 100b/100/x/x ExitLatency P1 Exit Latency
    #define CND003_PCIEPHYCFG_FRP04_P0SP2EXT_G3_PHYA_2_0   (BIT0 + BIT1 + BIT2)    // 100b/100/x/x ExitLatency P0s Exit Latency
#define CND003_PCIEPHYCFG_LOW_PWR_EXIT_LATENCY_LANE00_PHYA_G3 0x274 // Low Power Exit Latency Lane00 PHYA G3
    #define CND003_PCIEPHYCFG_RSVPCIEPHYCFG_274_7          0xF000                  // 0/x/x/x Reserved
    #define CND003_PCIEPHYCFG_FRP00_FDRATIO_G3_PHYA_2_0    (BIT9 + BIT10 + BIT11)  // 010b/010/x/x FD Mode Ratio during P1 to P0
    #define CND003_PCIEPHYCFG_FRP00_FTSRATIO_G3_PHYA_2_0   (BIT6 + BIT7 + BIT8)    // 100b/100/x/x PD Trainingmode Ratio during P0s to P0
    #define CND003_PCIEPHYCFG_FRP00_P1EXT_G3_PHYA_2_0      (BIT3 + BIT4 + BIT5)    // 100b/100/x/x ExitLatency P1 Exit Latency
    #define CND003_PCIEPHYCFG_FRP00_P0SP2EXT_G3_PHYA_2_0   (BIT0 + BIT1 + BIT2)    // 100b/100/x/x ExitLatency P0s Exit Latency
#define CND003_PCIEPHYCFG_LOW_PWR_EXIT_LATENCY_LANE01_PHYA_G3 0x276 // Low Power Exit Latency Lane01 PHYA G3
    #define CND003_PCIEPHYCFG_RSVPCIEPHYCFG_276_7          0xF000                  // 0/x/x/x Reserved
    #define CND003_PCIEPHYCFG_FRP01_FDRATIO_G3_PHYA_2_0    (BIT9 + BIT10 + BIT11)  // 010b/010/x/x FD Mode Ratio during P1 to P0
    #define CND003_PCIEPHYCFG_FRP01_FTSRATIO_G3_PHYA_2_0   (BIT6 + BIT7 + BIT8)    // 100b/100/x/x PD Trainingmode Ratio during P0s to P0
    #define CND003_PCIEPHYCFG_FRP01_P1EXT_G3_PHYA_2_0      (BIT3 + BIT4 + BIT5)    // 100b/100/x/x ExitLatency P1 Exit Latency
    #define CND003_PCIEPHYCFG_FRP01_P0SP2EXT_G3_PHYA_2_0   (BIT0 + BIT1 + BIT2)    // 100b/100/x/x ExitLatency P0s Exit Latency
#define CND003_PCIEPHYCFG_LOW_PWR_EXIT_LATENCY_LANE02_PHYA_G3 0x278 // Low Power Exit Latency Lane02 PHYA G3
    #define CND003_PCIEPHYCFG_RSVPCIEPHYCFG_278_7          0xF000                  // 0/x/x/x Reserved
    #define CND003_PCIEPHYCFG_FRP02_FDRATIO_G3_PHYA_2_0    (BIT9 + BIT10 + BIT11)  // 010b/010/x/x FD Mode Ratio during P1 to P0
    #define CND003_PCIEPHYCFG_FRP02_FTSRATIO_G3_PHYA_2_0   (BIT6 + BIT7 + BIT8)    // 100b/100/x/x PD Trainingmode Ratio during P0s to P0
    #define CND003_PCIEPHYCFG_FRP02_P1EXT_G3_PHYA_2_0      (BIT3 + BIT4 + BIT5)    // 100b/100/x/x ExitLatency P1 Exit Latency
    #define CND003_PCIEPHYCFG_FRP02_P0SP2EXT_G3_PHYA_2_0   (BIT0 + BIT1 + BIT2)    // 100b/100/x/x ExitLatency P0s Exit Latency
#define CND003_PCIEPHYCFG_LOW_PWR_EXIT_LATENCY_LANE03_PHYA_G3 0x27A // Low Power Exit Latency Lane03 PHYA G3
    #define CND003_PCIEPHYCFG_RSVPCIEPHYCFG_27A_7          0xF000                  // 0/x/x/x Reserved
    #define CND003_PCIEPHYCFG_FRP03_FDRATIO_G3_PHYA_2_0    (BIT9 + BIT10 + BIT11)  // 010b/010/x/x FD Mode Ratio during P1 to P0
    #define CND003_PCIEPHYCFG_FRP03_FTSRATIO_G3_PHYA_2_0   (BIT6 + BIT7 + BIT8)    // 100b/100/x/x PD Trainingmode Ratio during P0s to P0
    #define CND003_PCIEPHYCFG_FRP03_P1EXT_G3_PHYA_2_0      (BIT3 + BIT4 + BIT5)    // 100b/100/x/x ExitLatency P1 Exit Latency
    #define CND003_PCIEPHYCFG_FRP03_P0SP2EXT_G3_PHYA_2_0   (BIT0 + BIT1 + BIT2)    // 100b/100/x/x ExitLatency P0s Exit Latency
#define CND003_PCIEPHYCFG_LOW_PWR_EXIT_LATENCY_LANE00_PHYB_G3 0x27C // Low Power Exit Latency Lane00 PHYB G3
    #define CND003_PCIEPHYCFG_RSVPCIEPHYCFG_27C_7          0xF000                  // 0/x/x/x Reserved
    #define CND003_PCIEPHYCFG_FRP00_FDRATIO_G3_PHYB_2_0    (BIT9 + BIT10 + BIT11)  // 010b/010/x/x FD Mode Ratio during P1 to P0
    #define CND003_PCIEPHYCFG_FRP00_FTSRATIO_G3_PHYB_2_0   (BIT6 + BIT7 + BIT8)    // 100b/100/x/x PD Trainingmode Ratio during P0s to P0
    #define CND003_PCIEPHYCFG_FRP00_P1EXT_G3_PHYB_2_0      (BIT3 + BIT4 + BIT5)    // 100b/100/x/x ExitLatency P1 Exit Latency
    #define CND003_PCIEPHYCFG_FRP00_P0SP2EXT_G3_PHYB_2_0   (BIT0 + BIT1 + BIT2)    // 100b/100/x/x ExitLatency P0s Exit Latency
#define CND003_PCIEPHYCFG_LOW_PWR_EXIT_LATENCY_LANE01_PHYB_G3 0x27E // Low Power Exit Latency Lane01 PHYB G3
    #define CND003_PCIEPHYCFG_RSVPCIEPHYCFG_27E_7          0xF000                  // 0/x/x/x Reserved
    #define CND003_PCIEPHYCFG_FRP01_FDRATIO_G3_PHYB_2_0    (BIT9 + BIT10 + BIT11)  // 010b/010/x/x FD Mode Ratio during P1 to P0
    #define CND003_PCIEPHYCFG_FRP01_FTSRATIO_G3_PHYB_2_0   (BIT6 + BIT7 + BIT8)    // 100b/100/x/x PD Trainingmode Ratio during P0s to P0
    #define CND003_PCIEPHYCFG_FRP01_P1EXT_G3_PHYB_2_0      (BIT3 + BIT4 + BIT5)    // 100b/100/x/x ExitLatency P1 Exit Latency
    #define CND003_PCIEPHYCFG_FRP01_P0SP2EXT_G3_PHYB_2_0   (BIT0 + BIT1 + BIT2)    // 100b/100/x/x ExitLatency P0s Exit Latency
#define CND003_PCIEPHYCFG_LOW_PWR_EXIT_LATENCY_LANE02_PHYB_G3 0x280 // Low Power Exit Latency Lane02 PHYB G3
    #define CND003_PCIEPHYCFG_RSVPCIEPHYCFG_280_7          0xF000                  // 0/x/x/x Reserved
    #define CND003_PCIEPHYCFG_FRP02_FDRATIO_G3_PHYB_2_0    (BIT9 + BIT10 + BIT11)  // 010b/010/x/x FD Mode Ratio during P1 to P0
    #define CND003_PCIEPHYCFG_FRP02_FTSRATIO_G3_PHYB_2_0   (BIT6 + BIT7 + BIT8)    // 100b/100/x/x PD Trainingmode Ratio during P0s to P0
    #define CND003_PCIEPHYCFG_FRP02_P1EXT_G3_PHYB_2_0      (BIT3 + BIT4 + BIT5)    // 100b/100/x/x ExitLatency P1 Exit Latency
    #define CND003_PCIEPHYCFG_FRP02_P0SP2EXT_G3_PHYB_2_0   (BIT0 + BIT1 + BIT2)    // 100b/100/x/x ExitLatency P0s Exit Latency
#define CND003_PCIEPHYCFG_LOW_PWR_EXIT_LATENCY_LANE03_PHYB_G3 0x282 // Low Power Exit Latency Lane03 PHYB G3
    #define CND003_PCIEPHYCFG_RSVPCIEPHYCFG_282_7          0xF000                  // 0/x/x/x Reserved
    #define CND003_PCIEPHYCFG_FRP03_FDRATIO_G3_PHYB_2_0    (BIT9 + BIT10 + BIT11)  // 010b/010/x/x FD Mode Ratio during P1 to P0
    #define CND003_PCIEPHYCFG_FRP03_FTSRATIO_G3_PHYB_2_0   (BIT6 + BIT7 + BIT8)    // 100b/100/x/x PD Trainingmode Ratio during P0s to P0
    #define CND003_PCIEPHYCFG_FRP03_P1EXT_G3_PHYB_2_0      (BIT3 + BIT4 + BIT5)    // 100b/100/x/x ExitLatency P1 Exit Latency
    #define CND003_PCIEPHYCFG_FRP03_P0SP2EXT_G3_PHYB_2_0   (BIT0 + BIT1 + BIT2)    // 100b/100/x/x ExitLatency P0s Exit Latency
#define CND003_PCIEPHYCFG_LOW_PWR_EXIT_LATENCY_LANE00_EP_G3 0x284 // Low Power Exit Latency Lane00 EP G3
    #define CND003_PCIEPHYCFG_RSVPCIEPHYCFG_284_7      0xF000                  // 0/x/x/x Reserved
    #define CND003_PCIEPHYCFG_FRP00_FDRATIO_G3_EP_2_0  (BIT9 + BIT10 + BIT11)  // 010b/010/x/x FD Mode Ratio during P1 to P0
    #define CND003_PCIEPHYCFG_FRP00_FTSRATIO_G3_EP_2_0 (BIT6 + BIT7 + BIT8)    // 100b/100/x/x PD Trainingmode Ratio during P0s to P0
    #define CND003_PCIEPHYCFG_FRP00_P1EXT_G3_EP_2_0    (BIT3 + BIT4 + BIT5)    // 100b/100/x/x ExitLatency P1 Exit Latency
    #define CND003_PCIEPHYCFG_FRP00_P0SP2EXT_G3_EP_2_0 (BIT0 + BIT1 + BIT2)    // 100b/100/x/x ExitLatency P0s Exit Latency
#define CND003_PCIEPHYCFG_LOW_PWR_EXIT_LATENCY_LANE01_EP_G3 0x286 // Low Power Exit Latency Lane01 EP G3
    #define CND003_PCIEPHYCFG_RSVPCIEPHYCFG_286_7      0xF000                  // 0/x/x/x Reserved
    #define CND003_PCIEPHYCFG_FRP01_FDRATIO_G3_EP_2_0  (BIT9 + BIT10 + BIT11)  // 010b/010/x/x FD Mode Ratio during P1 to P0
    #define CND003_PCIEPHYCFG_FRP01_FTSRATIO_G3_EP_2_0 (BIT6 + BIT7 + BIT8)    // 100b/100/x/x PD Trainingmode Ratio during P0s to P0
    #define CND003_PCIEPHYCFG_FRP01_P1EXT_G3_EP_2_0    (BIT3 + BIT4 + BIT5)    // 100b/100/x/x ExitLatency P1 Exit Latency
    #define CND003_PCIEPHYCFG_FRP01_P0SP2EXT_G3_EP_2_0 (BIT0 + BIT1 + BIT2)    // 100b/100/x/x ExitLatency P0s Exit Latency
#define CND003_PCIEPHYCFG_LOW_PWR_EXIT_LATENCY_LANE02_EP_G3 0x288 // Low Power Exit Latency Lane02 EP G3
    #define CND003_PCIEPHYCFG_RSVPCIEPHYCFG_288_7      0xF000                  // 0/x/x/x Reserved
    #define CND003_PCIEPHYCFG_FRP02_FDRATIO_G3_EP_2_0  (BIT9 + BIT10 + BIT11)  // 010b/010/x/x FD Mode Ratio during P1 to P0
    #define CND003_PCIEPHYCFG_FRP02_FTSRATIO_G3_EP_2_0 (BIT6 + BIT7 + BIT8)    // 100b/100/x/x PD Trainingmode Ratio during P0s to P0
    #define CND003_PCIEPHYCFG_FRP02_P1EXT_G3_EP_2_0    (BIT3 + BIT4 + BIT5)    // 100b/100/x/x ExitLatency P1 Exit Latency
    #define CND003_PCIEPHYCFG_FRP02_P0SP2EXT_G3_EP_2_0 (BIT0 + BIT1 + BIT2)    // 100b/100/x/x ExitLatency P0s Exit Latency
#define CND003_PCIEPHYCFG_LOW_PWR_EXIT_LATENCY_LANE03_EP_G3 0x28A // Low Power Exit Latency Lane03 EP G3
    #define CND003_PCIEPHYCFG_RSVPCIEPHYCFG_28A_7      0xF000                  // 0/x/x/x Reserved
    #define CND003_PCIEPHYCFG_FRP03_FDRATIO_G3_EP_2_0  (BIT9 + BIT10 + BIT11)  // 010b/010/x/x FD Mode Ratio during P1 to P0
    #define CND003_PCIEPHYCFG_FRP03_FTSRATIO_G3_EP_2_0 (BIT6 + BIT7 + BIT8)    // 100b/100/x/x PD Trainingmode Ratio during P0s to P0
    #define CND003_PCIEPHYCFG_FRP03_P1EXT_G3_EP_2_0    (BIT3 + BIT4 + BIT5)    // 100b/100/x/x ExitLatency P1 Exit Latency
    #define CND003_PCIEPHYCFG_FRP03_P0SP2EXT_G3_EP_2_0 (BIT0 + BIT1 + BIT2)    // 100b/100/x/x ExitLatency P0s Exit Latency
#define CND003_PCIEPHYCFG_LOW_PWR_EXIT_LATENCY_LANE00_PHYC_G3 0x28C // Low Power Exit Latency Lane00 PHYC G3
    #define CND003_PCIEPHYCFG_RSVPCIEPHYCFG_28C_7 PCIEPHYCFG_LOW_PWR_EXIT_LATENCY_LANE00_PHYC_G3 // 0/x/x/x Reserved
#define CND003_PCIEPHYCFG_LOW_PWR_EXIT_LATENCY_LANE01_PHYC_G3 0x28E // Low Power Exit Latency Lane01 PHYC G3
    #define CND003_PCIEPHYCFG_RSVPCIEPHYCFG_28E_7 PCIEPHYCFG_LOW_PWR_EXIT_LATENCY_LANE01_PHYC_G3 // 0/x/x/x Reserved
#define CND003_PCIEPHYCFG_RESERVED_Z11 0x290 // Reserved
    #define CND003_PCIEPHYCFG_RSVPCIEPHYCFG_290_7 PCIEPHYCFG_RESERVED_Z11 // 0/x/x/x Reserved
#define CND003_PCIEPHYCFG_RESERVED_Z12 0x291 // Reserved
    #define CND003_PCIEPHYCFG_RSVPCIEPHYCFG_291_7 PCIEPHYCFG_RESERVED_Z12 // 0/x/x/x Reserved
#define CND003_PCIEPHYCFG_RX_GAIN_SEL_LANE00_G1 0x300 // RX Gain Selection Lane00 G1
    #define CND003_PCIEPHYCFG_FRP00_NIPRSEL_G1_PHYB PCIEPHYCFG_RX_GAIN_SEL_LANE00_G1 // 0/0/x/x Reserved
#define CND003_PCIEPHYCFG_RX_GAIN_SEL_LANE04_PHYA_G1 0x302 // RX Gain Selection Lane04 PHYA G1
    #define CND003_PCIEPHYCFG_FRP04_NIPRSEL_G1_PHYA_1_0    (BIT14 + BIT15) // 11b/11/x/x Gain1 during Training Mode
    #define CND003_PCIEPHYCFG_FRP04_KIPRSEL_G1_PHYA_1_0    (BIT12 + BIT13) // 10b/10/x/x Gain1 during Tracking Mode
    #define CND003_PCIEPHYCFG_FRP04_NIPCSEL_G1_PHYA_1_0    (BIT10 + BIT11) // 01b/01/x/x Gain2 during Training Mode
    #define CND003_PCIEPHYCFG_FRP04_KIPCSEL_G1_PHYA_1_0    (BIT8 + BIT9)   // 00b/00/x/x Gain2 during Tracking Mode
    #define CND003_PCIEPHYCFG_FRP04_NTSEL_G1_PHYA_1_0      (BIT6 + BIT7)   // 01b/01/x/x Updatetime during Tracking Mode
    #define CND003_PCIEPHYCFG_FRP04_KTSEL_G1_PHYA_1_0      (BIT4 + BIT5)   // 10b/10/x/x Updatetime during Tracking Mode
    #define CND003_PCIEPHYCFG_FRP04_NLFSEL_G1_PHYA_1_0     (BIT2 + BIT3)   // 01b/01/x/x LF Select during Training Mode
    #define CND003_PCIEPHYCFG_FRP04_KLFSEL_G1_PHYA_1_0     (BIT0 + BIT1)   // 11b/11/x/x LF Select during Tracking Mode
#define CND003_PCIEPHYCFG_RX_GAIN_SEL_LANE00_PHYA_G1 0x304 // RX Gain Selection Lane00 PHYA G1
    #define CND003_PCIEPHYCFG_FRP00_NIPRSEL_G1_PHYA_1_0    (BIT14 + BIT15) // 11b/11/x/x Gain1 during Training Mode
    #define CND003_PCIEPHYCFG_FRP00_KIPRSEL_G1_PHYA_1_0    (BIT12 + BIT13) // 10b/10/x/x Gain1 during Tracking Mode
    #define CND003_PCIEPHYCFG_FRP00_NIPCSEL_G1_PHYA_1_0    (BIT10 + BIT11) // 01b/01/x/x Gain2 during Training Mode
    #define CND003_PCIEPHYCFG_FRP00_KIPCSEL_G1_PHYA_1_0    (BIT8 + BIT9)   // 00b/00/x/x Gain2 during Tracking Mode
    #define CND003_PCIEPHYCFG_FRP00_NTSEL_G1_PHYA_1_0      (BIT6 + BIT7)   // 01b/01/x/x Updatetime during Tracking Mode
    #define CND003_PCIEPHYCFG_FRP00_KTSEL_G1_PHYA_1_0      (BIT4 + BIT5)   // 10b/10/x/x Updatetime during Tracking Mode
    #define CND003_PCIEPHYCFG_FRP00_NLFSEL_G1_PHYA_1_0     (BIT2 + BIT3)   // 01b/01/x/x LF Select during Training Mode
    #define CND003_PCIEPHYCFG_FRP00_KLFSEL_G1_PHYA_1_0     (BIT0 + BIT1)   // 11b/11/x/x LF Select during Tracking Mode
#define CND003_PCIEPHYCFG_RX_GAIN_SEL_LANE01_PHYA_G1 0x306 // RX Gain Selection Lane01 PHYA G1
    #define CND003_PCIEPHYCFG_FRP01_NIPRSEL_G1_PHYA_1_0    (BIT14 + BIT15) // 11b/11/x/x Gain1 during Training Mode
    #define CND003_PCIEPHYCFG_FRP01_KIPRSEL_G1_PHYA_1_0    (BIT12 + BIT13) // 10b/10/x/x Gain1 during Tracking Mode
    #define CND003_PCIEPHYCFG_FRP01_NIPCSEL_G1_PHYA_1_0    (BIT10 + BIT11) // 01b/01/x/x Gain2 during Training Mode
    #define CND003_PCIEPHYCFG_FRP01_KIPCSEL_G1_PHYA_1_0    (BIT8 + BIT9)   // 00b/00/x/x Gain2 during Tracking Mode
    #define CND003_PCIEPHYCFG_FRP01_NTSEL_G1_PHYA_1_0      (BIT6 + BIT7)   // 01b/01/x/x Updatetime during Tracking Mode
    #define CND003_PCIEPHYCFG_FRP01_KTSEL_G1_PHYA_1_0      (BIT4 + BIT5)   // 10b/10/x/x Updatetime during Tracking Mode
    #define CND003_PCIEPHYCFG_FRP01_NLFSEL_G1_PHYA_1_0     (BIT2 + BIT3)   // 01b/01/x/x LF Select during Training Mode
    #define CND003_PCIEPHYCFG_FRP01_KLFSEL_G1_PHYA_1_0     (BIT0 + BIT1)   // 11b/11/x/x LF Select during Tracking Mode
#define CND003_PCIEPHYCFG_RX_GAIN_SEL_LANE02_PHYA_G1 0x308 // RX Gain Selection Lane02 PHYA G1
    #define CND003_PCIEPHYCFG_FRP02_NIPRSEL_G1_PHYA_1_0    (BIT14 + BIT15) // 11b/11/x/x Gain1 during Training Mode
    #define CND003_PCIEPHYCFG_FRP02_KIPRSEL_G1_PHYA_1_0    (BIT12 + BIT13) // 10b/10/x/x Gain1 during Tracking Mode
    #define CND003_PCIEPHYCFG_FRP02_NIPCSEL_G1_PHYA_1_0    (BIT10 + BIT11) // 01b/01/x/x Gain2 during Training Mode
    #define CND003_PCIEPHYCFG_FRP02_KIPCSEL_G1_PHYA_1_0    (BIT8 + BIT9)   // 00b/00/x/x Gain2 during Tracking Mode
    #define CND003_PCIEPHYCFG_FRP02_NTSEL_G1_PHYA_1_0      (BIT6 + BIT7)   // 01b/01/x/x Updatetime during Tracking Mode
    #define CND003_PCIEPHYCFG_FRP02_KTSEL_G1_PHYA_1_0      (BIT4 + BIT5)   // 10b/10/x/x Updatetime during Tracking Mode
    #define CND003_PCIEPHYCFG_FRP02_NLFSEL_G1_PHYA_1_0     (BIT2 + BIT3)   // 01b/01/x/x LF Select during Training Mode
    #define CND003_PCIEPHYCFG_FRP02_KLFSEL_G1_PHYA_1_0     (BIT0 + BIT1)   // 11b/11/x/x LF Select during Tracking Mode
#define CND003_PCIEPHYCFG_RX_GAIN_SEL_LANE01_PHYA_GEN1 0x30A // RX Gain Selection Lane01 PHYA Gen1
    #define CND003_PCIEPHYCFG_FRP03_NIPRSEL_G1_PHYA_1_0    (BIT14 + BIT15) // 11b/11/x/x Gain1 during Training Mode
    #define CND003_PCIEPHYCFG_FRP03_KIPRSEL_G1_PHYA_1_0    (BIT12 + BIT13) // 10b/10/x/x Gain1 during Tracking Mode
    #define CND003_PCIEPHYCFG_FRP03_NIPCSEL_G1_PHYA_1_0    (BIT10 + BIT11) // 01b/01/x/x Gain2 during Training Mode
    #define CND003_PCIEPHYCFG_FRP03_KIPCSEL_G1_PHYA_1_0    (BIT8 + BIT9)   // 00b/00/x/x Gain2 during Tracking Mode
    #define CND003_PCIEPHYCFG_FRP03_NTSEL_G1_PHYA_1_0      (BIT6 + BIT7)   // 01b/01/x/x Updatetime during Tracking Mode
    #define CND003_PCIEPHYCFG_FRP03_KTSEL_G1_PHYA_1_0      (BIT4 + BIT5)   // 10b/10/x/x Updatetime during Tracking Mode
    #define CND003_PCIEPHYCFG_FRP03_NLFSEL_G1_PHYA_1_0     (BIT2 + BIT3)   // 01b/01/x/x LF Select during Training Mode
    #define CND003_PCIEPHYCFG_FRP03_KLFSEL_G1_PHYA_1_0     (BIT0 + BIT1)   // 11b/11/x/x LF Select during Tracking Mode
#define CND003_PCIEPHYCFG_RX_GAIN_SEL_LANE00_PHYB_GEN1 0x30C // RX Gain Selection Lane00 PHYB Gen1
    #define CND003_PCIEPHYCFG_FRP00_NIPRSEL_G1_PHYB_1_0    (BIT14 + BIT15) // 11b/11/x/x Gain1 during Training Mode
    #define CND003_PCIEPHYCFG_FRP00_KIPRSEL_G1_PHYB_1_0    (BIT12 + BIT13) // 10b/10/x/x Gain1 during Tracking Mode
    #define CND003_PCIEPHYCFG_FRP00_NIPCSEL_G1_PHYB_1_0    (BIT10 + BIT11) // 01b/01/x/x Gain2 during Training Mode
    #define CND003_PCIEPHYCFG_FRP00_KIPCSEL_G1_PHYB_1_0    (BIT8 + BIT9)   // 00b/00/x/x Gain2 during Tracking Mode
    #define CND003_PCIEPHYCFG_FRP00_NTSEL_G1_PHYB_1_0      (BIT6 + BIT7)   // 01b/01/x/x Updatetime during Tracking Mode
    #define CND003_PCIEPHYCFG_FRP00_KTSEL_G1_PHYB_1_0      (BIT4 + BIT5)   // 10b/10/x/x Updatetime during Tracking Mode
    #define CND003_PCIEPHYCFG_FRP00_NLFSEL_G1_PHYB_1_0     (BIT2 + BIT3)   // 01b/01/x/x LF Select during Training Mode
    #define CND003_PCIEPHYCFG_FRP00_KLFSEL_G1_PHYB_1_0     (BIT0 + BIT1)   // 11b/11/x/x LF Select during Tracking Mode
#define CND003_PCIEPHYCFG_RX_GAIN_SEL_LANE01_PHYB_GEN1 0x30E // RX Gain Selection Lane01 PHYB Gen1
    #define CND003_PCIEPHYCFG_FRP01_NIPRSEL_G1_PHYB_1_0    (BIT14 + BIT15) // 11b/11/x/x Gain1 during Training Mode
    #define CND003_PCIEPHYCFG_FRP01_KIPRSEL_G1_PHYB_1_0    (BIT12 + BIT13) // 10b/10/x/x Gain1 during Tracking Mode
    #define CND003_PCIEPHYCFG_FRP01_NIPCSEL_G1_PHYB_1_0    (BIT10 + BIT11) // 01b/01/x/x Gain2 during Training Mode
    #define CND003_PCIEPHYCFG_FRP01_KIPCSEL_G1_PHYB_1_0    (BIT8 + BIT9)   // 00b/00/x/x Gain2 during Tracking Mode
    #define CND003_PCIEPHYCFG_FRP01_NTSEL_G1_PHYB_1_0      (BIT6 + BIT7)   // 01b/01/x/x Updatetime during Tracking Mode
    #define CND003_PCIEPHYCFG_FRP01_KTSEL_G1_PHYB_1_0      (BIT4 + BIT5)   // 10b/10/x/x Updatetime during Tracking Mode
    #define CND003_PCIEPHYCFG_FRP01_NLFSEL_G1_PHYB_1_0     (BIT2 + BIT3)   // 01b/01/x/x LF Select during Training Mode
    #define CND003_PCIEPHYCFG_FRP01_KLFSEL_G1_PHYB_1_0     (BIT0 + BIT1)   // 11b/11/x/x LF Select during Tracking Mode
#define CND003_PCIEPHYCFG_RX_GAIN_SEL_LANE02_PHYB_GEN1 0x310 // RX Gain Selection Lane02 PHYB Gen1
    #define CND003_PCIEPHYCFG_FRP02_NIPRSEL_G1_PHYB_1_0    (BIT14 + BIT15) // 11b/11/x/x Gain1 during Training Mode
    #define CND003_PCIEPHYCFG_FRP02_KIPRSEL_G1_PHYB_1_0    (BIT12 + BIT13) // 10b/10/x/x Gain1 during Tracking Mode
    #define CND003_PCIEPHYCFG_FRP02_NIPCSEL_G1_PHYB_1_0    (BIT10 + BIT11) // 01b/01/x/x Gain2 during Training Mode
    #define CND003_PCIEPHYCFG_FRP02_KIPCSEL_G1_PHYB_1_0    (BIT8 + BIT9)   // 00b/00/x/x Gain2 during Tracking Mode
    #define CND003_PCIEPHYCFG_FRP02_NTSEL_G1_PHYB_1_0      (BIT6 + BIT7)   // 01b/01/x/x Updatetime during Tracking Mode
    #define CND003_PCIEPHYCFG_FRP02_KTSEL_G1_PHYB_1_0      (BIT4 + BIT5)   // 10b/10/x/x Updatetime during Tracking Mode
    #define CND003_PCIEPHYCFG_FRP02_NLFSEL_G1_PHYB_1_0     (BIT2 + BIT3)   // 01b/01/x/x LF Select during Training Mode
    #define CND003_PCIEPHYCFG_FRP02_KLFSEL_G1_PHYB_1_0     (BIT0 + BIT1)   // 11b/11/x/x LF Select during Tracking Mode
#define CND003_PCIEPHYCFG_RX_GAIN_SEL_LANE03_PHYB_GEN1 0x312 // RX Gain Selection Lane03 PHYB Gen1
    #define CND003_PCIEPHYCFG_FRP03_NIPRSEL_G1_PHYB_1_0    (BIT14 + BIT15) // 11b/11/x/x Gain1 during Training Mode
    #define CND003_PCIEPHYCFG_FRP03_KIPRSEL_G1_PHYB_1_0    (BIT12 + BIT13) // 10b/10/x/x Gain1 during Tracking Mode
    #define CND003_PCIEPHYCFG_FRP03_NIPCSEL_G1_PHYB_1_0    (BIT10 + BIT11) // 01b/01/x/x Gain2 during Training Mode
    #define CND003_PCIEPHYCFG_FRP03_KIPCSEL_G1_PHYB_1_0    (BIT8 + BIT9)   // 00b/00/x/x Gain2 during Tracking Mode
    #define CND003_PCIEPHYCFG_FRP03_NTSEL_G1_PHYB_1_0      (BIT6 + BIT7)   // 01b/01/x/x Updatetime during Tracking Mode
    #define CND003_PCIEPHYCFG_FRP03_KTSEL_G1_PHYB_1_0      (BIT4 + BIT5)   // 10b/10/x/x Updatetime during Tracking Mode
    #define CND003_PCIEPHYCFG_FRP03_NLFSEL_G1_PHYB_1_0     (BIT2 + BIT3)   // 01b/01/x/x LF Select during Training Mode
    #define CND003_PCIEPHYCFG_FRP03_KLFSEL_G1_PHYB_1_0     (BIT0 + BIT1)   // 11b/11/x/x LF Select during Tracking Mode
#define CND003_PCIEPHYCFG_RX_GAIN_SEL_LANE00_EP_GEN1 0x314 // RX Gain Selection Lane00 EP Gen1
    #define CND003_PCIEPHYCFG_FRP00_NIPRSEL_G1_EP_1_0  (BIT14 + BIT15) // 11b/11/x/x Gain1 during Training Mode
    #define CND003_PCIEPHYCFG_FRP00_KIPRSEL_G1_EP_1_0  (BIT12 + BIT13) // 10b/10/x/x Gain1 during Tracking Mode
    #define CND003_PCIEPHYCFG_FRP00_NIPCSEL_G1_EP_1_0  (BIT10 + BIT11) // 01b/01/x/x Gain2 during Training Mode
    #define CND003_PCIEPHYCFG_FRP00_KIPCSEL_G1_EP_1_0  (BIT8 + BIT9)   // 00b/00/x/x Gain2 during Tracking Mode
    #define CND003_PCIEPHYCFG_FRP00_NTSEL_G1_EP_1_0    (BIT6 + BIT7)   // 01b/01/x/x Updatetime during Tracking Mode
    #define CND003_PCIEPHYCFG_FRP00_KTSEL_G1_EP_1_0    (BIT4 + BIT5)   // 10b/10/x/x Updatetime during Tracking Mode
    #define CND003_PCIEPHYCFG_FRP00_NLFSEL_G1_EP_1_0   (BIT2 + BIT3)   // 01b/01/x/x LF Select during Training Mode
    #define CND003_PCIEPHYCFG_FRP00_KLFSEL_G1_EP_1_0   (BIT0 + BIT1)   // 11b/11/x/x LF Select during Tracking Mode
#define CND003_PCIEPHYCFG_RX_GAIN_SEL_LANE01_EP_GEN1 0x316 // RX Gain Selection Lane01 EP Gen1
    #define CND003_PCIEPHYCFG_FRP01_NIPRSEL_G1_EP_1_0  (BIT14 + BIT15) // 11b/11/x/x Gain1 during Training Mode
    #define CND003_PCIEPHYCFG_FRP01_KIPRSEL_G1_EP_1_0  (BIT12 + BIT13) // 10b/10/x/x Gain1 during Tracking Mode
    #define CND003_PCIEPHYCFG_FRP01_NIPCSEL_G1_EP_1_0  (BIT10 + BIT11) // 01b/01/x/x Gain2 during Training Mode
    #define CND003_PCIEPHYCFG_FRP01_KIPCSEL_G1_EP_1_0  (BIT8 + BIT9)   // 00b/00/x/x Gain2 during Tracking Mode
    #define CND003_PCIEPHYCFG_FRP01_NTSEL_G1_EP_1_0    (BIT6 + BIT7)   // 01b/01/x/x Updatetime during Tracking Mode
    #define CND003_PCIEPHYCFG_FRP01_KTSEL_G1_EP_1_0    (BIT4 + BIT5)   // 10b/10/x/x Updatetime during Tracking Mode
    #define CND003_PCIEPHYCFG_FRP01_NLFSEL_G1_EP_1_0   (BIT2 + BIT3)   // 01b/01/x/x LF Select during Training Mode
    #define CND003_PCIEPHYCFG_FRP01_KLFSEL_G1_EP_1_0   (BIT0 + BIT1)   // 11b/11/x/x LF Select during Tracking Mode
#define CND003_PCIEPHYCFG_RX_GAIN_SEL_LANE02_EP_GEN1 0x318 // RX Gain Selection Lane02 EP Gen1
    #define CND003_PCIEPHYCFG_FRP02_NIPRSEL_G1_EP_1_0  (BIT14 + BIT15) // 11b/11/x/x Gain1 during Training Mode
    #define CND003_PCIEPHYCFG_FRP02_KIPRSEL_G1_EP_1_0  (BIT12 + BIT13) // 10b/10/x/x Gain1 during Tracking Mode
    #define CND003_PCIEPHYCFG_FRP02_NIPCSEL_G1_EP_1_0  (BIT10 + BIT11) // 01b/01/x/x Gain2 during Training Mode
    #define CND003_PCIEPHYCFG_FRP02_KIPCSEL_G1_EP_1_0  (BIT8 + BIT9)   // 00b/00/x/x Gain2 during Tracking Mode
    #define CND003_PCIEPHYCFG_FRP02_NTSEL_G1_EP_1_0    (BIT6 + BIT7)   // 01b/01/x/x Updatetime during Tracking Mode
    #define CND003_PCIEPHYCFG_FRP02_KTSEL_G1_EP_1_0    (BIT4 + BIT5)   // 10b/10/x/x Updatetime during Tracking Mode
    #define CND003_PCIEPHYCFG_FRP02_NLFSEL_G1_EP_1_0   (BIT2 + BIT3)   // 01b/01/x/x LF Select during Training Mode
    #define CND003_PCIEPHYCFG_FRP02_KLFSEL_G1_EP_1_0   (BIT0 + BIT1)   // 11b/11/x/x LF Select during Tracking Mode
#define CND003_PCIEPHYCFG_RX_GAIN_SEL_LANE03_EP_GEN1 0x31A // RX Gain Selection Lane03 EP Gen1
    #define CND003_PCIEPHYCFG_FRP03_NIPRSEL_G1_EP_1_0  (BIT14 + BIT15) // 11b/11/x/x Gain1 during Training Mode
    #define CND003_PCIEPHYCFG_FRP03_KIPRSEL_G1_EP_1_0  (BIT12 + BIT13) // 10b/10/x/x Gain1 during Tracking Mode
    #define CND003_PCIEPHYCFG_FRP03_NIPCSEL_G1_EP_1_0  (BIT10 + BIT11) // 01b/01/x/x Gain2 during Training Mode
    #define CND003_PCIEPHYCFG_FRP03_KIPCSEL_G1_EP_1_0  (BIT8 + BIT9)   // 00b/00/x/x Gain2 during Tracking Mode
    #define CND003_PCIEPHYCFG_FRP03_NTSEL_G1_EP_1_0    (BIT6 + BIT7)   // 01b/01/x/x Updatetime during Tracking Mode
    #define CND003_PCIEPHYCFG_FRP03_KTSEL_G1_EP_1_0    (BIT4 + BIT5)   // 10b/10/x/x Updatetime during Tracking Mode
    #define CND003_PCIEPHYCFG_FRP03_NLFSEL_G1_EP_1_0   (BIT2 + BIT3)   // 01b/01/x/x LF Select during Training Mode
    #define CND003_PCIEPHYCFG_FRP03_KLFSEL_G1_EP_1_0   (BIT0 + BIT1)   // 11b/11/x/x LF Select during Tracking Mode
#define CND003_PCIEPHYCFG_RX_GAIN_SEL_LANE00_PHYC_G1 0x31C // RX Gain Selection Lane00 PHYC G1
    #define CND003_PCIEPHYCFG_FRP00_NIPRSEL_PHYC_G1 PCIEPHYCFG_RX_GAIN_SEL_LANE00_PHYC_G1 // 0/0/x/x Reserved
#define CND003_PCIEPHYCFG_RX_GAIN_SEL_LANE01_PHYC_G1 0x31E // RX Gain Selection Lane01 PHYC G1
    #define CND003_PCIEPHYCFG_FRP01_NIPRSEL_PHYC_G1 PCIEPHYCFG_RX_GAIN_SEL_LANE01_PHYC_G1 // 0/0/x/x Reserved
#define CND003_PCIEPHYCFG_RESERVED_Z13 0x320 // Reserved
    #define CND003_PCIEPHYCFG_RSVPCIEPHYCFG_320_7 PCIEPHYCFG_RESERVED_Z13 // 0/x/x/x Reserved
#define CND003_PCIEPHYCFG_RESERVED_Z14 0x321 // Reserved
    #define CND003_PCIEPHYCFG_RSVPCIEPHYCFG_321_7 PCIEPHYCFG_RESERVED_Z14 // 0/x/x/x Reserved
#define CND003_PCIEPHYCFG_RX_GAIN_SEL_LANE00_G2 0x330 // RX Gain Selection Lane00 G2
    #define CND003_PCIEPHYCFG_FRP00_NIPRSEL_G2_PHYB PCIEPHYCFG_RX_GAIN_SEL_LANE00_G2 // 0/0/x/X Reserved
#define CND003_PCIEPHYCFG_RX_GAIN_SEL_LANE04_PHYA_G2 0x332 // RX Gain Selection Lane04 PHYA G2
    #define CND003_PCIEPHYCFG_FRP04_NIPRSEL_G2_PHYA_1_0    (BIT14 + BIT15) // 10b/10/x/x Gain1 during Training Mode
    #define CND003_PCIEPHYCFG_FRP04_KIPRSEL_G2_PHYA_1_0    (BIT12 + BIT13) // 01b/01/x/x Gain1 during Tracking Mode
    #define CND003_PCIEPHYCFG_FRP04_NIPCSEL_G2_PHYA_1_0    (BIT10 + BIT11) // 01b/01/x/x Gain2 during Training Mode
    #define CND003_PCIEPHYCFG_FRP04_KIPCSEL_G2_PHYA_1_0    (BIT8 + BIT9)   // 00b/00/x/x Gain2 during Tracking Mode
    #define CND003_PCIEPHYCFG_FRP04_NTSEL_G2_PHYA_1_0      (BIT6 + BIT7)   // 01b/01/x/x Updatetime during Tracking Mode
    #define CND003_PCIEPHYCFG_FRP04_KTSEL_G2_PHYA_1_0      (BIT4 + BIT5)   // 00b/00/x/x Updatetime during Tracking Mode
    #define CND003_PCIEPHYCFG_FRP04_NLFSEL_G2_PHYA_1_0     (BIT2 + BIT3)   // 01b/01/x/x LF Select during Training Mode
    #define CND003_PCIEPHYCFG_FRP04_KLFSEL_G2_PHYA_1_0     (BIT0 + BIT1)   // 11b/11/x/x LF Select during Tracking Mode
#define CND003_PCIEPHYCFG_RX_GAIN_SEL_LANE00_PHYA_G2 0x334 // RX Gain Selection Lane00 PHYA G2
    #define CND003_PCIEPHYCFG_FRP00_NIPRSEL_G2_PHYA_1_0    (BIT14 + BIT15) // 10b/10/x/x Gain1 during Training Mode
    #define CND003_PCIEPHYCFG_FRP00_KIPRSEL_G2_PHYA_1_0    (BIT12 + BIT13) // 01b/01/x/x Gain1 during Tracking Mode
    #define CND003_PCIEPHYCFG_FRP00_NIPCSEL_G2_PHYA_1_0    (BIT10 + BIT11) // 01b/01/x/x Gain2 during Training Mode
    #define CND003_PCIEPHYCFG_FRP00_KIPCSEL_G2_PHYA_1_0    (BIT8 + BIT9)   // 00b/00/x/x Gain2 during Tracking Mode
    #define CND003_PCIEPHYCFG_FRP00_NTSEL_G2_PHYA_1_0      (BIT6 + BIT7)   // 01b/01/x/x Updatetime during Tracking Mode
    #define CND003_PCIEPHYCFG_FRP00_KTSEL_G2_PHYA_1_0      (BIT4 + BIT5)   // 00b/00/x/x Updatetime during Tracking Mode
    #define CND003_PCIEPHYCFG_FRP00_NLFSEL_G2_PHYA_1_0     (BIT2 + BIT3)   // 01b/01/x/x LF Select during Training Mode
    #define CND003_PCIEPHYCFG_FRP00_KLFSEL_G2_PHYA_1_0     (BIT0 + BIT1)   // 11b/11/x/x LF Select during Tracking Mode
#define CND003_PCIEPHYCFG_RX_GAIN_SEL_LANE01_PHYA_G2 0x336 // RX Gain Selection Lane01 PHYA G2
    #define CND003_PCIEPHYCFG_FRP01_NIPRSEL_G2_PHYA_1_0    (BIT14 + BIT15) // 10b/10/x/x Gain1 during Training Mode
    #define CND003_PCIEPHYCFG_FRP01_KIPRSEL_G2_PHYA_1_0    (BIT12 + BIT13) // 01b/01/x/x Gain1 during Tracking Mode
    #define CND003_PCIEPHYCFG_FRP01_NIPCSEL_G2_PHYA_1_0    (BIT10 + BIT11) // 01b/01/x/x Gain2 during Training Mode
    #define CND003_PCIEPHYCFG_FRP01_KIPCSEL_G2_PHYA_1_0    (BIT8 + BIT9)   // 00b/00/x/x Gain2 during Tracking Mode
    #define CND003_PCIEPHYCFG_FRP01_NTSEL_G2_PHYA_1_0      (BIT6 + BIT7)   // 01b/01/x/x Updatetime during Tracking Mode
    #define CND003_PCIEPHYCFG_FRP01_KTSEL_G2_PHYA_1_0      (BIT4 + BIT5)   // 00b/00/x/x Updatetime during Tracking Mode
    #define CND003_PCIEPHYCFG_FRP01_NLFSEL_G2_PHYA_1_0     (BIT2 + BIT3)   // 01b/01/x/x LF Select during Training Mode
    #define CND003_PCIEPHYCFG_FRP01_KLFSEL_G2_PHYA_1_0     (BIT0 + BIT1)   // 11b/11/x/x LF Select during Tracking Mode
#define CND003_PCIEPHYCFG_RX_GAIN_SEL_LANE02_PHYA_G2 0x338 // RX Gain Selection Lane02 PHYA G2
    #define CND003_PCIEPHYCFG_FRP02_NIPRSEL_G2_PHYA_1_0    (BIT14 + BIT15) // 10b/10/x/x Gain1 during Training Mode
    #define CND003_PCIEPHYCFG_FRP02_KIPRSEL_G2_PHYA_1_0    (BIT12 + BIT13) // 01b/01/x/x Gain1 during Tracking Mode
    #define CND003_PCIEPHYCFG_FRP02_NIPCSEL_G2_PHYA_1_0    (BIT10 + BIT11) // 01b/01/x/x Gain2 during Training Mode
    #define CND003_PCIEPHYCFG_FRP02_KIPCSEL_G2_PHYA_1_0    (BIT8 + BIT9)   // 00b/00/x/x Gain2 during Tracking Mode
    #define CND003_PCIEPHYCFG_FRP02_NTSEL_G2_PHYA_1_0      (BIT6 + BIT7)   // 01b/01/x/x Updatetime during Tracking Mode
    #define CND003_PCIEPHYCFG_FRP02_KTSEL_G2_PHYA_1_0      (BIT4 + BIT5)   // 00b/00/x/x Updatetime during Tracking Mode
    #define CND003_PCIEPHYCFG_FRP02_NLFSEL_G2_PHYA_1_0     (BIT2 + BIT3)   // 01b/01/x/x LF Select during Training Mode
    #define CND003_PCIEPHYCFG_FRP02_KLFSEL_G2_PHYA_1_0     (BIT0 + BIT1)   // 11b/11/x/x LF Select during Tracking Mode
#define CND003_PCIEPHYCFG_RX_GAIN_SEL_LANE03_PHYA_G2 0x33A // RX Gain Selection Lane03 PHYA G2
    #define CND003_PCIEPHYCFG_FRP03_NIPRSEL_G2_PHYA_1_0    (BIT14 + BIT15) // 10b/10/x/x Gain1 during Training Mode
    #define CND003_PCIEPHYCFG_FRP03_KIPRSEL_G2_PHYA_1_0    (BIT12 + BIT13) // 01b/01/x/x Gain1 during Tracking Mode
    #define CND003_PCIEPHYCFG_FRP03_NIPCSEL_G2_PHYA_1_0    (BIT10 + BIT11) // 01b/01/x/x Gain2 during Training Mode
    #define CND003_PCIEPHYCFG_FRP03_KIPCSEL_G2_PHYA_1_0    (BIT8 + BIT9)   // 00b/00/x/x Gain2 during Tracking Mode
    #define CND003_PCIEPHYCFG_FRP03_NTSEL_G2_PHYA_1_0      (BIT6 + BIT7)   // 01b/01/x/x Updatetime during Tracking Mode
    #define CND003_PCIEPHYCFG_FRP03_KTSEL_G2_PHYA_1_0      (BIT4 + BIT5)   // 00b/00/x/x Updatetime during Tracking Mode
    #define CND003_PCIEPHYCFG_FRP03_NLFSEL_G2_PHYA_1_0     (BIT2 + BIT3)   // 01b/01/x/x LF Select during Training Mode
    #define CND003_PCIEPHYCFG_FRP03_KLFSEL_G2_PHYA_1_0     (BIT0 + BIT1)   // 11b/11/x/x LF Select during Tracking Mode
#define CND003_PCIEPHYCFG_RX_GAIN_SEL_LANE00_PHYB_G2 0x33C // RX Gain Selection Lane00 PHYB G2
    #define CND003_PCIEPHYCFG_FRP00_NIPRSEL_G2_PHYB_1_0    (BIT14 + BIT15) // 10b/10/x/x Gain1 during Training Mode
    #define CND003_PCIEPHYCFG_FRP00_KIPRSEL_G2_PHYB_1_0    (BIT12 + BIT13) // 01b/01/x/x Gain1 during Tracking Mode
    #define CND003_PCIEPHYCFG_FRP00_NIPCSEL_G2_PHYB_1_0    (BIT10 + BIT11) // 01b/01/x/x Gain2 during Training Mode
    #define CND003_PCIEPHYCFG_FRP00_KIPCSEL_G2_PHYB_1_0    (BIT8 + BIT9)   // 00b/00/x/x Gain2 during Tracking Mode
    #define CND003_PCIEPHYCFG_FRP00_NTSEL_G2_PHYB_1_0      (BIT6 + BIT7)   // 01b/01/x/x Updatetime during Tracking Mode
    #define CND003_PCIEPHYCFG_FRP00_KTSEL_G2_PHYB_1_0      (BIT4 + BIT5)   // 00b/00/x/x Updatetime during Tracking Mode
    #define CND003_PCIEPHYCFG_FRP00_NLFSEL_G2_PHYB_1_0     (BIT2 + BIT3)   // 01b/01/x/x LF Select during Training Mode
    #define CND003_PCIEPHYCFG_FRP00_KLFSEL_G2_PHYB_1_0     (BIT0 + BIT1)   // 11b/11/x/x LF Select during Tracking Mode
#define CND003_PCIEPHYCFG_RX_GAIN_SEL_LANE01_PHYB_G2 0x33E // RX Gain Selection Lane01 PHYB G2
    #define CND003_PCIEPHYCFG_FRP01_NIPRSEL_G2_PHYB_1_0    (BIT14 + BIT15) // 10b/10/x/x Gain1 during Training Mode
    #define CND003_PCIEPHYCFG_FRP01_KIPRSEL_G2_PHYB_1_0    (BIT12 + BIT13) // 01b/01/x/x Gain1 during Tracking Mode
    #define CND003_PCIEPHYCFG_FRP01_NIPCSEL_G2_PHYB_1_0    (BIT10 + BIT11) // 01b/01/x/x Gain2 during Training Mode
    #define CND003_PCIEPHYCFG_FRP01_KIPCSEL_G2_PHYB_1_0    (BIT8 + BIT9)   // 00b/00/x/x Gain2 during Tracking Mode
    #define CND003_PCIEPHYCFG_FRP01_NTSEL_G2_PHYB_1_0      (BIT6 + BIT7)   // 01b/01/x/x Updatetime during Tracking Mode
    #define CND003_PCIEPHYCFG_FRP01_KTSEL_G2_PHYB_1_0      (BIT4 + BIT5)   // 00b/00/x/x Updatetime during Tracking Mode
    #define CND003_PCIEPHYCFG_FRP01_NLFSEL_G2_PHYB_1_0     (BIT2 + BIT3)   // 01b/01/x/x LF Select during Training Mode
    #define CND003_PCIEPHYCFG_FRP01_KLFSEL_G2_PHYB_1_0     (BIT0 + BIT1)   // 11b/11/x/x LF Select during Tracking Mode
#define CND003_PCIEPHYCFG_RX_GAIN_SEL_LANE02_PHYB_G2 0x340 // RX Gain Selection Lane02 PHYB G2
    #define CND003_PCIEPHYCFG_FRP02_NIPRSEL_G2_PHYB_1_0    (BIT14 + BIT15) // 10b/10/x/x Gain1 during Training Mode
    #define CND003_PCIEPHYCFG_FRP02_KIPRSEL_G2_PHYB_1_0    (BIT12 + BIT13) // 01b/01/x/x Gain1 during Tracking Mode
    #define CND003_PCIEPHYCFG_FRP02_NIPCSEL_G2_PHYB_1_0    (BIT10 + BIT11) // 01b/01/x/x Gain2 during Training Mode
    #define CND003_PCIEPHYCFG_FRP02_KIPCSEL_G2_PHYB_1_0    (BIT8 + BIT9)   // 00b/00/x/x Gain2 during Tracking Mode
    #define CND003_PCIEPHYCFG_FRP02_NTSEL_G2_PHYB_1_0      (BIT6 + BIT7)   // 01b/01/x/x Updatetime during Tracking Mode
    #define CND003_PCIEPHYCFG_FRP02_KTSEL_G2_PHYB_1_0      (BIT4 + BIT5)   // 00b/00/x/x Updatetime during Tracking Mode
    #define CND003_PCIEPHYCFG_FRP02_NLFSEL_G2_PHYB_1_0     (BIT2 + BIT3)   // 01b/01/x/x LF Select during Training Mode
    #define CND003_PCIEPHYCFG_FRP02_KLFSEL_G2_PHYB_1_0     (BIT0 + BIT1)   // 11b/11/x/x LF Select during Tracking Mode
#define CND003_PCIEPHYCFG_RX_GAIN_SEL_LANE03_PHYB_G2 0x342 // RX Gain Selection Lane03 PHYB G2
    #define CND003_PCIEPHYCFG_FRP03_NIPRSEL_G2_PHYB_1_0    (BIT14 + BIT15) // 10b/10/x/x Gain1 during Training Mode
    #define CND003_PCIEPHYCFG_FRP03_KIPRSEL_G2_PHYB_1_0    (BIT12 + BIT13) // 01b/01/x/x Gain1 during Tracking Mode
    #define CND003_PCIEPHYCFG_FRP03_NIPCSEL_G2_PHYB_1_0    (BIT10 + BIT11) // 01b/01/x/x Gain2 during Training Mode
    #define CND003_PCIEPHYCFG_FRP03_KIPCSEL_G2_PHYB_1_0    (BIT8 + BIT9)   // 00b/00/x/x Gain2 during Tracking Mode
    #define CND003_PCIEPHYCFG_FRP03_NTSEL_G2_PHYB_1_0      (BIT6 + BIT7)   // 01b/01/x/x Updatetime during Tracking Mode
    #define CND003_PCIEPHYCFG_FRP03_KTSEL_G2_PHYB_1_0      (BIT4 + BIT5)   // 00b/00/x/x Updatetime during Tracking Mode
    #define CND003_PCIEPHYCFG_FRP03_NLFSEL_G2_PHYB_1_0     (BIT2 + BIT3)   // 01b/01/x/x LF Select during Training Mode
    #define CND003_PCIEPHYCFG_FRP03_KLFSEL_G2_PHYB_1_0     (BIT0 + BIT1)   // 11b/11/x/x LF Select during Tracking Mode
#define CND003_PCIEPHYCFG_RX_GAIN_SEL_LANE00_EP_G2 0x344 // RX Gain Selection Lane00 EP G2
    #define CND003_PCIEPHYCFG_FRP00_NIPRSEL_G2_EP_1_0  (BIT14 + BIT15) // 10b/10/x/x Gain1 during Training Mode
    #define CND003_PCIEPHYCFG_FRP00_KIPRSEL_G2_EP_1_0  (BIT12 + BIT13) // 01b/01/x/x Gain1 during Tracking Mode
    #define CND003_PCIEPHYCFG_FRP00_NIPCSEL_G2_EP_1_0  (BIT10 + BIT11) // 01b/01/x/x Gain2 during Training Mode
    #define CND003_PCIEPHYCFG_FRP00_KIPCSEL_G2_EP_1_0  (BIT8 + BIT9)   // 00b/00/x/x Gain2 during Tracking Mode
    #define CND003_PCIEPHYCFG_FRP00_NTSEL_G2_EP_1_0    (BIT6 + BIT7)   // 01b/01/x/x Updatetime during Tracking Mode
    #define CND003_PCIEPHYCFG_FRP00_KTSEL_G2_EP_1_0    (BIT4 + BIT5)   // 00b/00/x/x Updatetime during Tracking Mode
    #define CND003_PCIEPHYCFG_FRP00_NLFSEL_G2_EP_1_0   (BIT2 + BIT3)   // 01b/01/x/x LF Select during Training Mode
    #define CND003_PCIEPHYCFG_FRP00_KLFSEL_G2_EP_1_0   (BIT0 + BIT1)   // 11b/11/x/x LF Select during Tracking Mode
#define CND003_PCIEPHYCFG_RX_GAIN_SEL_LANE01_EP_G2 0x346 // RX Gain Selection Lane01 EP G2
    #define CND003_PCIEPHYCFG_FRP01_NIPRSEL_G2_EP_1_0  (BIT14 + BIT15) // 10b/10/x/x Gain1 during Training Mode
    #define CND003_PCIEPHYCFG_FRP01_KIPRSEL_G2_EP_1_0  (BIT12 + BIT13) // 01b/01/x/x Gain1 during Tracking Mode
    #define CND003_PCIEPHYCFG_FRP01_NIPCSEL_G2_EP_1_0  (BIT10 + BIT11) // 01b/01/x/x Gain2 during Training Mode
    #define CND003_PCIEPHYCFG_FRP01_KIPCSEL_G2_EP_1_0  (BIT8 + BIT9)   // 00b/00/x/x Gain2 during Tracking Mode
    #define CND003_PCIEPHYCFG_FRP01_NTSEL_G2_EP_1_0    (BIT6 + BIT7)   // 01b/01/x/x Updatetime during Tracking Mode
    #define CND003_PCIEPHYCFG_FRP01_KTSEL_G2_EP_1_0    (BIT4 + BIT5)   // 00b/00/x/x Updatetime during Tracking Mode
    #define CND003_PCIEPHYCFG_FRP01_NLFSEL_G2_EP_1_0   (BIT2 + BIT3)   // 01b/01/x/x LF Select during Training Mode
    #define CND003_PCIEPHYCFG_FRP01_KLFSEL_G2_EP_1_0   (BIT0 + BIT1)   // 11b/11/x/x LF Select during Tracking Mode
#define CND003_PCIEPHYCFG_RX_GAIN_SEL_LANE02_EP_G2 0x348 // RX Gain Selection Lane02 EP G2
    #define CND003_PCIEPHYCFG_FRP02_NIPRSEL_G2_EP_1_0  (BIT14 + BIT15) // 10b/10/x/x Gain1 during Training Mode
    #define CND003_PCIEPHYCFG_FRP02_KIPRSEL_G2_EP_1_0  (BIT12 + BIT13) // 01b/01/x/x Gain1 during Tracking Mode
    #define CND003_PCIEPHYCFG_FRP02_NIPCSEL_G2_EP_1_0  (BIT10 + BIT11) // 01b/01/x/x Gain2 during Training Mode
    #define CND003_PCIEPHYCFG_FRP02_KIPCSEL_G2_EP_1_0  (BIT8 + BIT9)   // 00b/00/x/x Gain2 during Tracking Mode
    #define CND003_PCIEPHYCFG_FRP02_NTSEL_G2_EP_1_0    (BIT6 + BIT7)   // 01b/01/x/x Updatetime during Tracking Mode
    #define CND003_PCIEPHYCFG_FRP02_KTSEL_G2_EP_1_0    (BIT4 + BIT5)   // 00b/00/x/x Updatetime during Tracking Mode
    #define CND003_PCIEPHYCFG_FRP02_NLFSEL_G2_EP_1_0   (BIT2 + BIT3)   // 01b/01/x/x LF Select during Training Mode
    #define CND003_PCIEPHYCFG_FRP02_KLFSEL_G2_EP_1_0   (BIT0 + BIT1)   // 11b/11/x/x LF Select during Tracking Mode
#define CND003_PCIEPHYCFG_RX_GAIN_SEL_LANE03_EP_G2 0x34A // RX Gain Selection Lane03 EP G2
    #define CND003_PCIEPHYCFG_FRP03_NIPRSEL_G2_EP_1_0  (BIT14 + BIT15) // 10b/10/x/x Gain1 during Training Mode
    #define CND003_PCIEPHYCFG_FRP03_KIPRSEL_G2_EP_1_0  (BIT12 + BIT13) // 01b/01/x/x Gain1 during Tracking Mode
    #define CND003_PCIEPHYCFG_FRP03_NIPCSEL_G2_EP_1_0  (BIT10 + BIT11) // 01b/01/x/x Gain2 during Training Mode
    #define CND003_PCIEPHYCFG_FRP03_KIPCSEL_G2_EP_1_0  (BIT8 + BIT9)   // 00b/00/x/x Gain2 during Tracking Mode
    #define CND003_PCIEPHYCFG_FRP03_NTSEL_G2_EP_1_0    (BIT6 + BIT7)   // 01b/01/x/x Updatetime during Tracking Mode
    #define CND003_PCIEPHYCFG_FRP03_KTSEL_G2_EP_1_0    (BIT4 + BIT5)   // 00b/00/x/x Updatetime during Tracking Mode
    #define CND003_PCIEPHYCFG_FRP03_NLFSEL_G2_EP_1_0   (BIT2 + BIT3)   // 01b/01/x/x LF Select during Training Mode
    #define CND003_PCIEPHYCFG_FRP03_KLFSEL_G2_EP_1_0   (BIT0 + BIT1)   // 11b/11/x/x LF Select during Tracking Mode
#define CND003_PCIEPHYCFG_RX_GAIN_SEL_LANE00_PHYC_G2 0x34C // RX Gain Selection Lane00 PHYC G2
    #define CND003_PCIEPHYCFG_FRP00_NIPRSEL_PHYC_G2 PCIEPHYCFG_RX_GAIN_SEL_LANE00_PHYC_G2 // 0/0/x/X Reserved
#define CND003_PCIEPHYCFG_RX_GAIN_SEL_LANE01_PHYC_G2 0x34E // RX Gain Selection Lane01 PHYC G2
    #define CND003_PCIEPHYCFG_FRP01_NIPRSEL_PHYC_G2 PCIEPHYCFG_RX_GAIN_SEL_LANE01_PHYC_G2 // 0/0/x/x Reserved
#define CND003_PCIEPHYCFG_RESERVED_Z15 0x350 // Reserved
    #define CND003_PCIEPHYCFG_RSVPCIEPHYCFG_350_7 PCIEPHYCFG_RESERVED_Z15 // 0/x/x/x Reserved
#define CND003_PCIEPHYCFG_RESERVED_Z16 0x351 // Reserved
    #define CND003_PCIEPHYCFG_RSVPCIEPHYCFG_351_7 PCIEPHYCFG_RESERVED_Z16 // 0/x/x/x Reserved
#define CND003_PCIEPHYCFG_RX_GAIN_SEL_LANE00_G3 0x360 // RX Gain Selection Lane00 G3
    #define CND003_PCIEPHYCFG_FRP00_NIPRSEL_G3_PHYB PCIEPHYCFG_RX_GAIN_SEL_LANE00_G3 // 0/0/x/X Reserved
#define CND003_PCIEPHYCFG_RX_GAIN_SEL_LANE04_PHYA_G3 0x362 // RX Gain Selection Lane04 PHYA G3
    #define CND003_PCIEPHYCFG_FRP04_NIPRSEL_G3_PHYA_1_0    (BIT14 + BIT15) // 10b/10/x/x Gain1 during Training Mode
    #define CND003_PCIEPHYCFG_FRP04_KIPRSEL_G3_PHYA_1_0    (BIT12 + BIT13) // 01b/01/x/x Gain1 during Tracking Mode
    #define CND003_PCIEPHYCFG_FRP04_NIPCSEL_G3_PHYA_1_0    (BIT10 + BIT11) // 01b/01/x/x Gain2 during Training Mode
    #define CND003_PCIEPHYCFG_FRP04_KIPCSEL_G3_PHYA_1_0    (BIT8 + BIT9)   // 00b/00/x/x Gain2 during Tracking Mode
    #define CND003_PCIEPHYCFG_FRP04_NTSEL_G3_PHYA_1_0      (BIT6 + BIT7)   // 01b/01/x/x Updatetime during Tracking Mode
    #define CND003_PCIEPHYCFG_FRP04_KTSEL_G3_PHYA_1_0      (BIT4 + BIT5)   // 00b/00/x/x Updatetime during Tracking Mode
    #define CND003_PCIEPHYCFG_FRP04_NLFSEL_G3_PHYA_1_0     (BIT2 + BIT3)   // 01b/01/x/x LF Select during Training Mode
    #define CND003_PCIEPHYCFG_FRP04_KLFSEL_G3_PHYA_1_0     (BIT0 + BIT1)   // 11b/11/x/x LF Select during Tracking Mode
#define CND003_PCIEPHYCFG_RX_GAIN_SEL_LANE00_PHYA_G3 0x364 // RX Gain Selection Lane00 PHYA G3
    #define CND003_PCIEPHYCFG_FRP00_NIPRSEL_G3_PHYA_1_0    (BIT14 + BIT15) // 10b/10/x/x Gain1 during Training Mode
    #define CND003_PCIEPHYCFG_FRP00_KIPRSEL_G3_PHYA_1_0    (BIT12 + BIT13) // 01b/01/x/x Gain1 during Tracking Mode
    #define CND003_PCIEPHYCFG_FRP00_NIPCSEL_G3_PHYA_1_0    (BIT10 + BIT11) // 01b/01/x/x Gain2 during Training Mode
    #define CND003_PCIEPHYCFG_FRP00_KIPCSEL_G3_PHYA_1_0    (BIT8 + BIT9)   // 00b/00/x/x Gain2 during Tracking Mode
    #define CND003_PCIEPHYCFG_FRP00_NTSEL_G3_PHYA_1_0      (BIT6 + BIT7)   // 01b/01/x/x Updatetime during Tracking Mode
    #define CND003_PCIEPHYCFG_FRP00_KTSEL_G3_PHYA_1_0      (BIT4 + BIT5)   // 00b/00/x/x Updatetime during Tracking Mode
    #define CND003_PCIEPHYCFG_FRP00_NLFSEL_G3_PHYA_1_0     (BIT2 + BIT3)   // 01b/01/x/x LF Select during Training Mode
    #define CND003_PCIEPHYCFG_FRP00_KLFSEL_G3_PHYA_1_0     (BIT0 + BIT1)   // 11b/11/x/x LF Select during Tracking Mode
#define CND003_PCIEPHYCFG_RX_GAIN_SEL_LANE01_PHYA_G3 0x366 // RX Gain Selection Lane01 PHYA G3
    #define CND003_PCIEPHYCFG_FRP01_NIPRSEL_G3_PHYA_1_0    (BIT14 + BIT15) // 10b/10/x/x Gain1 during Training Mode
    #define CND003_PCIEPHYCFG_FRP01_KIPRSEL_G3_PHYA_1_0    (BIT12 + BIT13) // 01b/01/x/x Gain1 during Tracking Mode
    #define CND003_PCIEPHYCFG_FRP01_NIPCSEL_G3_PHYA_1_0    (BIT10 + BIT11) // 01b/01/x/x Gain2 during Training Mode
    #define CND003_PCIEPHYCFG_FRP01_KIPCSEL_G3_PHYA_1_0    (BIT8 + BIT9)   // 00b/00/x/x Gain2 during Tracking Mode
    #define CND003_PCIEPHYCFG_FRP01_NTSEL_G3_PHYA_1_0      (BIT6 + BIT7)   // 01b/01/x/x Updatetime during Tracking Mode
    #define CND003_PCIEPHYCFG_FRP01_KTSEL_G3_PHYA_1_0      (BIT4 + BIT5)   // 00b/00/x/x Updatetime during Tracking Mode
    #define CND003_PCIEPHYCFG_FRP01_NLFSEL_G3_PHYA_1_0     (BIT2 + BIT3)   // 01b/01/x/x LF Select during Training Mode
    #define CND003_PCIEPHYCFG_FRP01_KLFSEL_G3_PHYA_1_0     (BIT0 + BIT1)   // 11b/11/x/x LF Select during Tracking Mode
#define CND003_PCIEPHYCFG_RX_GAIN_SEL_LANE02_PHYA_G3 0x368 // RX Gain Selection Lane02 PHYA G3
    #define CND003_PCIEPHYCFG_FRP02_NIPRSEL_G3_PHYA_1_0    (BIT14 + BIT15) // 10b/10/x/x Gain1 during Training Mode
    #define CND003_PCIEPHYCFG_FRP02_KIPRSEL_G3_PHYA_1_0    (BIT12 + BIT13) // 01b/01/x/x Gain1 during Tracking Mode
    #define CND003_PCIEPHYCFG_FRP02_NIPCSEL_G3_PHYA_1_0    (BIT10 + BIT11) // 01b/01/x/x Gain2 during Training Mode
    #define CND003_PCIEPHYCFG_FRP02_KIPCSEL_G3_PHYA_1_0    (BIT8 + BIT9)   // 00b/00/x/x Gain2 during Tracking Mode
    #define CND003_PCIEPHYCFG_FRP02_NTSEL_G3_PHYA_1_0      (BIT6 + BIT7)   // 01b/01/x/x Updatetime during Tracking Mode
    #define CND003_PCIEPHYCFG_FRP02_KTSEL_G3_PHYA_1_0      (BIT4 + BIT5)   // 00b/00/x/x Updatetime during Tracking Mode
    #define CND003_PCIEPHYCFG_FRP02_NLFSEL_G3_PHYA_1_0     (BIT2 + BIT3)   // 01b/01/x/x LF Select during Training Mode
    #define CND003_PCIEPHYCFG_FRP02_KLFSEL_G3_PHYA_1_0     (BIT0 + BIT1)   // 11b/11/x/x LF Select during Tracking Mode
#define CND003_PCIEPHYCFG_RX_GAIN_SEL_LANE03_PHYA_G3 0x36A // RX Gain Selection Lane03 PHYA G3
    #define CND003_PCIEPHYCFG_FRP03_NIPRSEL_G3_PHYA_1_0    (BIT14 + BIT15) // 10b/10/x/x Gain1 during Training Mode
    #define CND003_PCIEPHYCFG_FRP03_KIPRSEL_G3_PHYA_1_0    (BIT12 + BIT13) // 01b/01/x/x Gain1 during Tracking Mode
    #define CND003_PCIEPHYCFG_FRP03_NIPCSEL_G3_PHYA_1_0    (BIT10 + BIT11) // 01b/01/x/x Gain2 during Training Mode
    #define CND003_PCIEPHYCFG_FRP03_KIPCSEL_G3_PHYA_1_0    (BIT8 + BIT9)   // 00b/00/x/x Gain2 during Tracking Mode
    #define CND003_PCIEPHYCFG_FRP03_NTSEL_G3_PHYA_1_0      (BIT6 + BIT7)   // 01b/01/x/x Updatetime during Tracking Mode
    #define CND003_PCIEPHYCFG_FRP03_KTSEL_G3_PHYA_1_0      (BIT4 + BIT5)   // 00b/00/x/x Updatetime during Tracking Mode
    #define CND003_PCIEPHYCFG_FRP03_NLFSEL_G3_PHYA_1_0     (BIT2 + BIT3)   // 01b/01/x/x LF Select during Training Mode
    #define CND003_PCIEPHYCFG_FRP03_KLFSEL_G3_PHYA_1_0     (BIT0 + BIT1)   // 11b/11/x/x LF Select during Tracking Mode
#define CND003_PCIEPHYCFG_RX_GAIN_SEL_LANE00_PHYB_G3 0x36C // RX Gain Selection Lane00 PHYB G3
    #define CND003_PCIEPHYCFG_FRP00_NIPRSEL_G3_PHYB_1_0    (BIT14 + BIT15) // 10b/10/x/x Gain1 during Training Mode
    #define CND003_PCIEPHYCFG_FRP00_KIPRSEL_G3_PHYB_1_0    (BIT12 + BIT13) // 01b/01/x/x Gain1 during Tracking Mode
    #define CND003_PCIEPHYCFG_FRP00_NIPCSEL_G3_PHYB_1_0    (BIT10 + BIT11) // 01b/01/x/x Gain2 during Training Mode
    #define CND003_PCIEPHYCFG_FRP00_KIPCSEL_G3_PHYB_1_0    (BIT8 + BIT9)   // 00b/00/x/x Gain2 during Tracking Mode
    #define CND003_PCIEPHYCFG_FRP00_NTSEL_G3_PHYB_1_0      (BIT6 + BIT7)   // 01b/01/x/x Updatetime during Tracking Mode
    #define CND003_PCIEPHYCFG_FRP00_KTSEL_G3_PHYB_1_0      (BIT4 + BIT5)   // 00b/00/x/x Updatetime during Tracking Mode
    #define CND003_PCIEPHYCFG_FRP00_NLFSEL_G3_PHYB_1_0     (BIT2 + BIT3)   // 01b/01/x/x LF Select during Training Mode
    #define CND003_PCIEPHYCFG_FRP00_KLFSEL_G3_PHYB_1_0     (BIT0 + BIT1)   // 11b/11/x/x LF Select during Tracking Mode
#define CND003_PCIEPHYCFG_RX_GAIN_SEL_LANE01_PHYB_G3 0x36E // RX Gain Selection Lane01 PHYB G3
    #define CND003_PCIEPHYCFG_FRP01_NIPRSEL_G3_PHYB_1_0    (BIT14 + BIT15) // 10b/10/x/x Gain1 during Training Mode
    #define CND003_PCIEPHYCFG_FRP01_KIPRSEL_G3_PHYB_1_0    (BIT12 + BIT13) // 01b/01/x/x Gain1 during Tracking Mode
    #define CND003_PCIEPHYCFG_FRP01_NIPCSEL_G3_PHYB_1_0    (BIT10 + BIT11) // 01b/01/x/x Gain2 during Training Mode
    #define CND003_PCIEPHYCFG_FRP01_KIPCSEL_G3_PHYB_1_0    (BIT8 + BIT9)   // 00b/00/x/x Gain2 during Tracking Mode
    #define CND003_PCIEPHYCFG_FRP01_NTSEL_G3_PHYB_1_0      (BIT6 + BIT7)   // 01b/01/x/x Updatetime during Tracking Mode
    #define CND003_PCIEPHYCFG_FRP01_KTSEL_G3_PHYB_1_0      (BIT4 + BIT5)   // 00b/00/x/x Updatetime during Tracking Mode
    #define CND003_PCIEPHYCFG_FRP01_NLFSEL_G3_PHYB_1_0     (BIT2 + BIT3)   // 01b/01/x/x LF Select during Training Mode
    #define CND003_PCIEPHYCFG_FRP01_KLFSEL_G3_PHYB_1_0     (BIT0 + BIT1)   // 11b/11/x/x LF Select during Tracking Mode
#define CND003_PCIEPHYCFG_RX_GAIN_SEL_LANE02_PHYB_G3 0x370 // RX Gain Selection Lane02 PHYB G3
    #define CND003_PCIEPHYCFG_FRP02_NIPRSEL_G3_PHYB_1_0    (BIT14 + BIT15) // 10b/10/x/x Gain1 during Training Mode
    #define CND003_PCIEPHYCFG_FRP02_KIPRSEL_G3_PHYB_1_0    (BIT12 + BIT13) // 01b/01/x/x Gain1 during Tracking Mode
    #define CND003_PCIEPHYCFG_FRP02_NIPCSEL_G3_PHYB_1_0    (BIT10 + BIT11) // 01b/01/x/x Gain2 during Training Mode
    #define CND003_PCIEPHYCFG_FRP02_KIPCSEL_G3_PHYB_1_0    (BIT8 + BIT9)   // 00b/00/x/x Gain2 during Tracking Mode
    #define CND003_PCIEPHYCFG_FRP02_NTSEL_G3_PHYB_1_0      (BIT6 + BIT7)   // 01b/01/x/x Updatetime during Tracking Mode
    #define CND003_PCIEPHYCFG_FRP02_KTSEL_G3_PHYB_1_0      (BIT4 + BIT5)   // 00b/00/x/x Updatetime during Tracking Mode
    #define CND003_PCIEPHYCFG_FRP02_NLFSEL_G3_PHYB_1_0     (BIT2 + BIT3)   // 01b/01/x/x LF Select during Training Mode
    #define CND003_PCIEPHYCFG_FRP02_KLFSEL_G3_PHYB_1_0     (BIT0 + BIT1)   // 11b/11/x/x LF Select during Tracking Mode
#define CND003_PCIEPHYCFG_RX_GAIN_SEL_LANE03_PHYB_G3 0x372 // RX Gain Selection Lane03 PHYB G3
    #define CND003_PCIEPHYCFG_FRP03_NIPRSEL_G3_PHYB_1_0    (BIT14 + BIT15) // 10b/10/x/x Gain1 during Training Mode
    #define CND003_PCIEPHYCFG_FRP03_KIPRSEL_G3_PHYB_1_0    (BIT12 + BIT13) // 01b/01/x/x Gain1 during Tracking Mode
    #define CND003_PCIEPHYCFG_FRP03_NIPCSEL_G3_PHYB_1_0    (BIT10 + BIT11) // 01b/01/x/x Gain2 during Training Mode
    #define CND003_PCIEPHYCFG_FRP03_KIPCSEL_G3_PHYB_1_0    (BIT8 + BIT9)   // 00b/00/x/x Gain2 during Tracking Mode
    #define CND003_PCIEPHYCFG_FRP03_NTSEL_G3_PHYB_1_0      (BIT6 + BIT7)   // 01b/01/x/x Updatetime during Tracking Mode
    #define CND003_PCIEPHYCFG_FRP03_KTSEL_G3_PHYB_1_0      (BIT4 + BIT5)   // 00b/00/x/x Updatetime during Tracking Mode
    #define CND003_PCIEPHYCFG_FRP03_NLFSEL_G3_PHYB_1_0     (BIT2 + BIT3)   // 01b/01/x/x LF Select during Training Mode
    #define CND003_PCIEPHYCFG_FRP03_KLFSEL_G3_PHYB_1_0     (BIT0 + BIT1)   // 11b/11/x/x LF Select during Tracking Mode
#define CND003_PCIEPHYCFG_RX_GAIN_SEL_LANE00_EP_G3 0x374 // RX Gain Selection Lane00 EP G3
    #define CND003_PCIEPHYCFG_FRP00_NIPRSEL_G3_EP_1_0  (BIT14 + BIT15) // 10b/10/x/x Gain1 during Training Mode
    #define CND003_PCIEPHYCFG_FRP00_KIPRSEL_G3_EP_1_0  (BIT12 + BIT13) // 01b/01/x/x Gain1 during Tracking Mode
    #define CND003_PCIEPHYCFG_FRP00_NIPCSEL_G3_EP_1_0  (BIT10 + BIT11) // 01b/01/x/x Gain2 during Training Mode
    #define CND003_PCIEPHYCFG_FRP00_KIPCSEL_G3_EP_1_0  (BIT8 + BIT9)   // 00b/00/x/x Gain2 during Tracking Mode
    #define CND003_PCIEPHYCFG_FRP00_NTSEL_G3_EP_1_0    (BIT6 + BIT7)   // 01b/01/x/x Updatetime during Tracking Mode
    #define CND003_PCIEPHYCFG_FRP00_KTSEL_G3_EP_1_0    (BIT4 + BIT5)   // 00b/00/x/x Updatetime during Tracking Mode
    #define CND003_PCIEPHYCFG_FRP00_NLFSEL_G3_EP_1_0   (BIT2 + BIT3)   // 01b/01/x/x LF Select during Training Mode
    #define CND003_PCIEPHYCFG_FRP00_KLFSEL_G3_EP_1_0   (BIT0 + BIT1)   // 11b/11/x/x LF Select during Tracking Mode
#define CND003_PCIEPHYCFG_RX_GAIN_SEL_LANE01_EP_G3 0x376 // RX Gain Selection Lane01 EP G3
    #define CND003_PCIEPHYCFG_FRP01_NIPRSEL_G3_EP_1_0  (BIT14 + BIT15) // 10b/10/x/x Gain1 during Training Mode
    #define CND003_PCIEPHYCFG_FRP01_KIPRSEL_G3_EP_1_0  (BIT12 + BIT13) // 01b/01/x/x Gain1 during Tracking Mode
    #define CND003_PCIEPHYCFG_FRP01_NIPCSEL_G3_EP_1_0  (BIT10 + BIT11) // 01b/01/x/x Gain2 during Training Mode
    #define CND003_PCIEPHYCFG_FRP01_KIPCSEL_G3_EP_1_0  (BIT8 + BIT9)   // 00b/00/x/x Gain2 during Tracking Mode
    #define CND003_PCIEPHYCFG_FRP01_NTSEL_G3_EP_1_0    (BIT6 + BIT7)   // 01b/01/x/x Updatetime during Tracking Mode
    #define CND003_PCIEPHYCFG_FRP01_KTSEL_G3_EP_1_0    (BIT4 + BIT5)   // 00b/00/x/x Updatetime during Tracking Mode
    #define CND003_PCIEPHYCFG_FRP01_NLFSEL_G3_EP_1_0   (BIT2 + BIT3)   // 01b/01/x/x LF Select during Training Mode
    #define CND003_PCIEPHYCFG_FRP01_KLFSEL_G3_EP_1_0   (BIT0 + BIT1)   // 11b/11/x/x LF Select during Tracking Mode
#define CND003_PCIEPHYCFG_RX_GAIN_SEL_LANE02_EP_G3 0x378 // RX Gain Selection Lane02 EP G3
    #define CND003_PCIEPHYCFG_FRP02_NIPRSEL_G3_EP_1_0  (BIT14 + BIT15) // 10b/10/x/x Gain1 during Training Mode
    #define CND003_PCIEPHYCFG_FRP02_KIPRSEL_G3_EP_1_0  (BIT12 + BIT13) // 01b/01/x/x Gain1 during Tracking Mode
    #define CND003_PCIEPHYCFG_FRP02_NIPCSEL_G3_EP_1_0  (BIT10 + BIT11) // 01b/01/x/x Gain2 during Training Mode
    #define CND003_PCIEPHYCFG_FRP02_KIPCSEL_G3_EP_1_0  (BIT8 + BIT9)   // 00b/00/x/x Gain2 during Tracking Mode
    #define CND003_PCIEPHYCFG_FRP02_NTSEL_G3_EP_1_0    (BIT6 + BIT7)   // 01b/01/x/x Updatetime during Tracking Mode
    #define CND003_PCIEPHYCFG_FRP02_KTSEL_G3_EP_1_0    (BIT4 + BIT5)   // 00b/00/x/x Updatetime during Tracking Mode
    #define CND003_PCIEPHYCFG_FRP02_NLFSEL_G3_EP_1_0   (BIT2 + BIT3)   // 01b/01/x/x LF Select during Training Mode
    #define CND003_PCIEPHYCFG_FRP02_KLFSEL_G3_EP_1_0   (BIT0 + BIT1)   // 11b/11/x/x LF Select during Tracking Mode
#define CND003_PCIEPHYCFG_RX_GAIN_SEL_LANE03_EP_G3 0x37A // RX Gain Selection Lane03 EP G3
    #define CND003_PCIEPHYCFG_FRP03_NIPRSEL_G3_EP_1_0  (BIT14 + BIT15) // 10b/10/x/x Gain1 during Training Mode
    #define CND003_PCIEPHYCFG_FRP03_KIPRSEL_G3_EP_1_0  (BIT12 + BIT13) // 01b/01/x/x Gain1 during Tracking Mode
    #define CND003_PCIEPHYCFG_FRP03_NIPCSEL_G3_EP_1_0  (BIT10 + BIT11) // 01b/01/x/x Gain2 during Training Mode
    #define CND003_PCIEPHYCFG_FRP03_KIPCSEL_G3_EP_1_0  (BIT8 + BIT9)   // 00b/00/x/x Gain2 during Tracking Mode
    #define CND003_PCIEPHYCFG_FRP03_NTSEL_G3_EP_1_0    (BIT6 + BIT7)   // 01b/01/x/x Updatetime during Tracking Mode
    #define CND003_PCIEPHYCFG_FRP03_KTSEL_G3_EP_1_0    (BIT4 + BIT5)   // 00b/00/x/x Updatetime during Tracking Mode
    #define CND003_PCIEPHYCFG_FRP03_NLFSEL_G3_EP_1_0   (BIT2 + BIT3)   // 01b/01/x/x LF Select during Training Mode
    #define CND003_PCIEPHYCFG_FRP03_KLFSEL_G3_EP_1_0   (BIT0 + BIT1)   // 11b/11/x/x LF Select during Tracking Mode
#define CND003_PCIEPHYCFG_RX_GAIN_SEL_LANE00_PHYC_G3 0x37C // RX Gain Selection Lane00 PHYC G3
    #define CND003_PCIEPHYCFG_FRP00_NIPRSEL_PHYC_G3 PCIEPHYCFG_RX_GAIN_SEL_LANE00_PHYC_G3 // 0/0/x/X Reserved
#define CND003_PCIEPHYCFG_RX_GAIN_SEL_LANE01_PHYC_G3 0x37E // RX Gain Selection Lane01 PHYC G3
    #define CND003_PCIEPHYCFG_FRP01_NIPRSEL_PHYC_G3 PCIEPHYCFG_RX_GAIN_SEL_LANE01_PHYC_G3 // 0/0/x/x Reserved
#define CND003_PCIEPHYCFG_RESERVED_Z17 0x380 // Reserved
    #define CND003_PCIEPHYCFG_RSVPCIEPHYCFG_380_7 PCIEPHYCFG_RESERVED_Z17 // 0/x/x/x Reserved
#define CND003_PCIEPHYCFG_RESERVED_Z18 0x381 // Reserved
    #define CND003_PCIEPHYCFG_RSVPCIEPHYCFG_381_7 PCIEPHYCFG_RESERVED_Z18 // 0/x/x/x Reserved
#define CND003_PCIEPHYCFG_EQUALIZER_ADAPTIVE_EQTN_MODE_LANE00_G1 0x400 // Equalizer Adaptive EQTN Mode Lane00 G1
    #define CND003_PCIEPHYCFG_RSVPCIEPHYCFG_400_7 PCIEPHYCFG_EQUALIZER_ADAPTIVE_EQTN_MODE_LANE00_G1 // 0/x/x/x Reserved
#define CND003_PCIEPHYCFG_EQUALIZER_ADAPTIVE_EQTN_MODE_LANE04_PHYA_G1 0x402 // Equalizer Adaptive EQTN Mode Lane04 PHYA G1
    #define CND003_PCIEPHYCFG_RSVPCIEPHYCFG_402_7          0xF000  // 0/x/x/x Reserved
    #define CND003_PCIEPHYCFG_FRP04_EQTNMODE_G1_PHYA_11_0  0xFFF   // 0/0/x/x External Register of Equalizer Tuning Mode Select
#define CND003_PCIEPHYCFG_EQUALIZER_ADAPTIVE_EQTN_MODE_LANE00_PHYA_G1 0x404 // Equalizer Adaptive EQTN Mode Lane00 PHYA G1
    #define CND003_PCIEPHYCFG_RSVPCIEPHYCFG_404_7          0xF000  // 0/x/x/x Reserved
    #define CND003_PCIEPHYCFG_FRP00_EQTNMODE_G1_PHYA_11_0  0xFFF   // 0/0/x/x External Register of Equalizer Tuning Mode Select
#define CND003_PCIEPHYCFG_EQUALIZER_ADAPTIVE_EQTN_MODE_LANE01_PHYA_G1 0x406 // Equalizer Adaptive EQTN Mode Lane01 PHYA G1
    #define CND003_PCIEPHYCFG_RSVPCIEPHYCFG_406_7          0xF000  // 0/x/x/x Reserved
    #define CND003_PCIEPHYCFG_FRP01_EQTNMODE_G1_PHYA_11_0  0xFFF   // 0/0/x/x External Register of Equalizer Tuning Mode Select
#define CND003_PCIEPHYCFG_EQUALIZER_ADAPTIVE_EQTN_MODE_LANE02_PHYA_G1 0x408 // Equalizer Adaptive EQTN Mode Lane02 PHYA G1
    #define CND003_PCIEPHYCFG_RSVPCIEPHYCFG_408_7          0xF000  // 0/x/x/x Reserved
    #define CND003_PCIEPHYCFG_FRP02_EQTNMODE_G1_PHYA_11_0  0xFFF   // 0/0/x/x External Register of Equalizer Tuning Mode Select
#define CND003_PCIEPHYCFG_EQUALIZER_ADAPTIVE_EQTN_MODE_LANE03_PHYA_G1 0x40A // Equalizer Adaptive EQTN Mode Lane03 PHYA G1
    #define CND003_PCIEPHYCFG_RSVPCIEPHYCFG_40A_7          0xF000  // 0/x/x/x Reserved
    #define CND003_PCIEPHYCFG_FRP03_EQTNMODE_G1_PHYA_11_0  0xFFF   // 0/0/x/x External Register of Equalizer Tuning Mode Select
#define CND003_PCIEPHYCFG_EQUALIZER_ADAPTIVE_EQTN_MODE_LANE00_PHYB_G1 0x40C // Equalizer Adaptive EQTN Mode Lane00 PHYB G1
    #define CND003_PCIEPHYCFG_RSVPCIEPHYCFG_40C_7          0xF000  // 0/x/x/x Reserved
    #define CND003_PCIEPHYCFG_FRP00_EQTNMODE_G1_PHYB_11_0  0xFFF   // 0/0/x/x External Register of Equalizer Tuning Mode Select
#define CND003_PCIEPHYCFG_EQUALIZER_ADAPTIVE_EQTN_MODE_LANE01_PHYB_G1 0x40E // Equalizer Adaptive EQTN Mode Lane01 PHYB G1
    #define CND003_PCIEPHYCFG_RSVPCIEPHYCFG_40E_7          0xF000  // 0/x/x/x Reserved
    #define CND003_PCIEPHYCFG_FRP01_EQTNMODE_G1_PHYB_11_0  0xFFF   // 0/0/x/x External Register of Equalizer Tuning Mode Select
#define CND003_PCIEPHYCFG_EQUALIZER_ADAPTIVE_EQTN_MODE_LANE02_PHYB_G1 0x410 // Equalizer Adaptive EQTN Mode Lane02 PHYB G1
    #define CND003_PCIEPHYCFG_RSVPCIEPHYCFG_410_7          0xF000  // 0/x/x/x Reserved
    #define CND003_PCIEPHYCFG_FRP02_EQTNMODE_G1_PHYB_11_0  0xFFF   // 0/0/x/x External Register of Equalizer Tuning Mode Select
#define CND003_PCIEPHYCFG_EQUALIZER_ADAPTIVE_EQTN_MODE_LANE03_PHYB_G1 0x412 // Equalizer Adaptive EQTN Mode Lane03 PHYB G1
    #define CND003_PCIEPHYCFG_RSVPCIEPHYCFG_412_7          0xF000  // 0/x/x/x Reserved
    #define CND003_PCIEPHYCFG_FRP03_EQTNMODE_G1_PHYB_11_0  0xFFF   // 0/0/x/x External Register of Equalizer Tuning Mode Select
#define CND003_PCIEPHYCFG_EQUALIZER_ADAPTIVE_EQTN_MODE_LANE00_EP_G1 0x414 // Equalizer Adaptive EQTN Mode Lane00 EP G1
    #define CND003_PCIEPHYCFG_RSVPCIEPHYCFG_414_7          0xF000  // 0/x/x/x Reserved
    #define CND003_PCIEPHYCFG_FRP00_EQTNMODE_G1_EP_11_0    0xFFF   // 0/0/x/x External Register of Equalizer Tuning Mode Select
#define CND003_PCIEPHYCFG_EQUALIZER_ADAPTIVE_EQTN_MODE_LANE01_EP_G1 0x416 // Equalizer Adaptive EQTN Mode Lane01 EP G1
    #define CND003_PCIEPHYCFG_RSVPCIEPHYCFG_416_7          0xF000  // 0/x/x/x Reserved
    #define CND003_PCIEPHYCFG_FRP01_EQTNMODE_G1_EP_11_0    0xFFF   // 0/0/x/x External Register of Equalizer Tuning Mode Select
#define CND003_PCIEPHYCFG_EQUALIZER_ADAPTIVE_EQTN_MODE_LANE02_EP_G1 0x418 // Equalizer Adaptive EQTN Mode Lane02 EP G1
    #define CND003_PCIEPHYCFG_RSVPCIEPHYCFG_418_7          0xF000  // 0/x/x/x Reserved
    #define CND003_PCIEPHYCFG_FRP02_EQTNMODE_G1_EP_11_0    0xFFF   // 0/0/x/x External Register of Equalizer Tuning Mode Select
#define CND003_PCIEPHYCFG_EQUALIZER_ADAPTIVE_EQTN_MODE_LANE03_EP_G1 0x41A // Equalizer Adaptive EQTN Mode Lane03 EP G1
    #define CND003_PCIEPHYCFG_RSVPCIEPHYCFG_41A_7          0xF000  // 0/x/x/x Reserved
    #define CND003_PCIEPHYCFG_FRP03_EQTNMODE_G1_EP_11_0    0xFFF   // 0/0/x/x External Register of Equalizer Tuning Mode Select
#define CND003_PCIEPHYCFG_EQUALIZER_ADAPTIVE_EQTN_MODE_LANE00_PHYC_G1 0x41C // Equalizer Adaptive EQTN Mode Lane00 PHYC G1
    #define CND003_PCIEPHYCFG_RSVPCIEPHYCFG_41C_7 PCIEPHYCFG_EQUALIZER_ADAPTIVE_EQTN_MODE_LANE00_PHYC_G1 // 0/x/x/x Reserved
#define CND003_PCIEPHYCFG_EQUALIZER_ADAPTIVE_EQTN_MODE_LANE00_PHYC_G1_Z1 0x41E // Equalizer Adaptive EQTN Mode Lane00 PHYC G1
    #define CND003_PCIEPHYCFG_RSVPCIEPHYCFG_41E_7 PCIEPHYCFG_EQUALIZER_ADAPTIVE_EQTN_MODE_LANE00_PHYC_G1_Z1 // 0/x/x/x Reserved
#define CND003_PCIEPHYCFG_RESERVED_Z19 0x420 // Reserved
    #define CND003_PCIEPHYCFG_RSVPCIEPHYCFG_420_7 PCIEPHYCFG_RESERVED_Z19 // 0/x/x/x Reserved
#define CND003_PCIEPHYCFG_RESERVED_Z20 0x421 // Reserved
    #define CND003_PCIEPHYCFG_RSVPCIEPHYCFG_421_7 PCIEPHYCFG_RESERVED_Z20 // 0/x/x/x Reserved
#define CND003_PCIEPHYCFG_EQUALIZER_ADAPTIVE_EQTN_MODE_LANE00_G2 0x430 // Equalizer Adaptive EQTN Mode Lane00 G2
    #define CND003_PCIEPHYCFG_RSVPCIEPHYCFG_430_7 PCIEPHYCFG_EQUALIZER_ADAPTIVE_EQTN_MODE_LANE00_G2 // 0/x/x/x Reserved
#define CND003_PCIEPHYCFG_EQUALIZER_ADAPTIVE_EQTN_MODE_LANE04_PHYA_G2 0x432 // Equalizer Adaptive EQTN Mode Lane04 PHYA G2
    #define CND003_PCIEPHYCFG_RSVPCIEPHYCFG_432_7          0xF000  // 0/x/x/x Reserved
    #define CND003_PCIEPHYCFG_FRP04_EQTNMODE_G2_PHYA_11_0  0xFFF   // 0/0/x/x External Register of Equalizer Tuning Mode Select
#define CND003_PCIEPHYCFG_EQUALIZER_ADAPTIVE_EQTN_MODE_LANE00_PHYA_G2 0x434 // Equalizer Adaptive EQTN Mode Lane00 PHYA G2
    #define CND003_PCIEPHYCFG_RSVPCIEPHYCFG_434_7          0xF000  // 0/x/x/x Reserved
    #define CND003_PCIEPHYCFG_FRP00_EQTNMODE_G2_PHYA_11_0  0xFFF   // 0/0/x/x External Register of Equalizer Tuning Mode Select
#define CND003_PCIEPHYCFG_EQUALIZER_ADAPTIVE_EQTN_MODE_LANE01_PHYA_G2 0x436 // Equalizer Adaptive EQTN Mode Lane01 PHYA G2
    #define CND003_PCIEPHYCFG_RSVPCIEPHYCFG_436_7          0xF000  // 0/x/x/x Reserved
    #define CND003_PCIEPHYCFG_FRP01_EQTNMODE_G2_PHYA_11_0  0xFFF   // 0/0/x/x External Register of Equalizer Tuning Mode Select
#define CND003_PCIEPHYCFG_EQUALIZER_ADAPTIVE_EQTN_MODE_LANE02_PHYA_G2 0x438 // Equalizer Adaptive EQTN Mode Lane02 PHYA G2
    #define CND003_PCIEPHYCFG_RSVPCIEPHYCFG_438_7          0xF000  // 0/x/x/x Reserved
    #define CND003_PCIEPHYCFG_FRP02_EQTNMODE_G2_PHYA_11_0  0xFFF   // 0/0/x/x External Register of Equalizer Tuning Mode Select
#define CND003_PCIEPHYCFG_EQUALIZER_ADAPTIVE_EQTN_MODE_LANE03_PHYA_G2 0x43A // Equalizer Adaptive EQTN Mode Lane03 PHYA G2
    #define CND003_PCIEPHYCFG_RSVPCIEPHYCFG_43A_7          0xF000  // 0/x/x/x Reserved
    #define CND003_PCIEPHYCFG_FRP03_EQTNMODE_G2_PHYA_11_0  0xFFF   // 0/0/x/x External Register of Equalizer Tuning Mode Select
#define CND003_PCIEPHYCFG_EQUALIZER_ADAPTIVE_EQTN_MODE_LANE00_PHYB_G2 0x43C // Equalizer Adaptive EQTN Mode Lane00 PHYB G2
    #define CND003_PCIEPHYCFG_RSVPCIEPHYCFG_43C_7          0xF000  // 0/x/x/x Reserved
    #define CND003_PCIEPHYCFG_FRP00_EQTNMODE_G2_PHYB_11_0  0xFFF   // 0/0/x/x External Register of Equalizer Tuning Mode Select
#define CND003_PCIEPHYCFG_EQUALIZER_ADAPTIVE_EQTN_MODE_LANE01_PHYB_G2 0x43E // Equalizer Adaptive EQTN Mode Lane01 PHYB G2
    #define CND003_PCIEPHYCFG_RSVPCIEPHYCFG_43E_7          0xF000  // 0/x/x/x Reserved
    #define CND003_PCIEPHYCFG_FRP01_EQTNMODE_G2_PHYB_11_0  0xFFF   // 0/0/x/x External Register of Equalizer Tuning Mode Select
#define CND003_PCIEPHYCFG_EQUALIZER_ADAPTIVE_EQTN_MODE_LANE02_PHYB_G2 0x440 // Equalizer Adaptive EQTN Mode Lane02 PHYB G2
    #define CND003_PCIEPHYCFG_RSVPCIEPHYCFG_440_7          0xF000  // 0/x/x/x Reserved
    #define CND003_PCIEPHYCFG_FRP02_EQTNMODE_G2_PHYB_11_0  0xFFF   // 0/0/x/x External Register of Equalizer Tuning Mode Select
#define CND003_PCIEPHYCFG_EQUALIZER_ADAPTIVE_EQTN_MODE_LANE03_PHYB_G2 0x442 // Equalizer Adaptive EQTN Mode Lane03 PHYB G2
    #define CND003_PCIEPHYCFG_RSVPCIEPHYCFG_442_7          0xF000  // 0/x/x/x Reserved
    #define CND003_PCIEPHYCFG_FRP03_EQTNMODE_G2_PHYB_11_0  0xFFF   // 0/0/x/x External Register of Equalizer Tuning Mode Select
#define CND003_PCIEPHYCFG_EQUALIZER_ADAPTIVE_EQTN_MODE_LANE00_EP_G2 0x444 // Equalizer Adaptive EQTN Mode Lane00 EP G2
    #define CND003_PCIEPHYCFG_RSVPCIEPHYCFG_444_7          0xF000  // 0/x/x/x Reserved
    #define CND003_PCIEPHYCFG_FRP00_EQTNMODE_G2_EP_11_0    0xFFF   // 0/0/x/x External Register of Equalizer Tuning Mode Select
#define CND003_PCIEPHYCFG_EQUALIZER_ADAPTIVE_EQTN_MODE_LANE01_EP_G2 0x446 // Equalizer Adaptive EQTN Mode Lane01 EP G2
    #define CND003_PCIEPHYCFG_RSVPCIEPHYCFG_446_7          0xF000  // 0/x/x/x Reserved
    #define CND003_PCIEPHYCFG_FRP01_EQTNMODE_G2_EP_11_0    0xFFF   // 0/0/x/x External Register of Equalizer Tuning Mode Select
#define CND003_PCIEPHYCFG_EQUALIZER_ADAPTIVE_EQTN_MODE_LANE02_EP_G2 0x448 // Equalizer Adaptive EQTN Mode Lane02 EP G2
    #define CND003_PCIEPHYCFG_RSVPCIEPHYCFG_448_7          0xF000  // 0/x/x/x Reserved
    #define CND003_PCIEPHYCFG_FRP02_EQTNMODE_G2_EP_11_0    0xFFF   // 0/0/x/x External Register of Equalizer Tuning Mode Select
#define CND003_PCIEPHYCFG_EQUALIZER_ADAPTIVE_EQTN_MODE_LANE03_EP_G2 0x44A // Equalizer Adaptive EQTN Mode Lane03 EP G2
    #define CND003_PCIEPHYCFG_RSVPCIEPHYCFG_44A_7          0xF000  // 0/x/x/x Reserved
    #define CND003_PCIEPHYCFG_FRP03_EQTNMODE_G2_EP_11_0    0xFFF   // 0/0/x/x External Register of Equalizer Tuning Mode Select
#define CND003_PCIEPHYCFG_EQUALIZER_ADAPTIVE_EQTN_MODE_LANE00_PHYC_G2 0x44C // Equalizer Adaptive EQTN Mode Lane00 PHYC G2
    #define CND003_PCIEPHYCFG_RSVPCIEPHYCFG_44C_7 PCIEPHYCFG_EQUALIZER_ADAPTIVE_EQTN_MODE_LANE00_PHYC_G2 // 0/x/x/x Reserved
#define CND003_PCIEPHYCFG_EQUALIZER_ADAPTIVE_EQTN_MODE_LANE01_PHYC_G2 0x44E // Equalizer Adaptive EQTN Mode Lane01 PHYC G2
    #define CND003_PCIEPHYCFG_RSVPCIEPHYCFG_44E_7 PCIEPHYCFG_EQUALIZER_ADAPTIVE_EQTN_MODE_LANE01_PHYC_G2 // 0/x/x/x Reserved
#define CND003_PCIEPHYCFG_RESERVED_Z21 0x450 // Reserved
    #define CND003_PCIEPHYCFG_RSVPCIEPHYCFG_450_7 PCIEPHYCFG_RESERVED_Z21 // 0/x/x/x Reserved
#define CND003_PCIEPHYCFG_RESERVED_Z22 0x451 // Reserved
    #define CND003_PCIEPHYCFG_RSVPCIEPHYCFG_451_7 PCIEPHYCFG_RESERVED_Z22 // 0/x/x/x Reserved
#define CND003_PCIEPHYCFG_EQUALIZER_ADAPTIVE_EQTN_MODE_LANE00_G3 0x460 // Equalizer Adaptive EQTN Mode Lane00 G3
    #define CND003_PCIEPHYCFG_RSVPCIEPHYCFG_460_7 PCIEPHYCFG_EQUALIZER_ADAPTIVE_EQTN_MODE_LANE00_G3 // 0/x/x/x Reserved
#define CND003_PCIEPHYCFG_EQUALIZER_ADAPTIVE_EQTN_MODE_LANE04_PHYA_G3 0x462 // Equalizer Adaptive EQTN Mode Lane04 PHYA G3
    #define CND003_PCIEPHYCFG_RSVPCIEPHYCFG_462_7          0xF000  // 0/x/x/x Reserved
    #define CND003_PCIEPHYCFG_FRP04_EQTNMODE_G3_PHYA_11_0  0xFFF   // 0/0/x/x External Register of Equalizer Tuning Mode Select
#define CND003_PCIEPHYCFG_EQUALIZER_ADAPTIVE_EQTN_MODE_LANE00_PHYA_G3 0x464 // Equalizer Adaptive EQTN Mode Lane00 PHYA G3
    #define CND003_PCIEPHYCFG_RSVPCIEPHYCFG_464_7          0xF000  // 0/x/x/x Reserved
    #define CND003_PCIEPHYCFG_FRP00_EQTNMODE_G3_PHYA_11_0  0xFFF   // 0/0/x/x External Register of Equalizer Tuning Mode Select
#define CND003_PCIEPHYCFG_EQUALIZER_ADAPTIVE_EQTN_MODE_LANE01_PHYA_G3 0x466 // Equalizer Adaptive EQTN Mode Lane01 PHYA G3
    #define CND003_PCIEPHYCFG_RSVPCIEPHYCFG_466_7          0xF000  // 0/x/x/x Reserved
    #define CND003_PCIEPHYCFG_FRP01_EQTNMODE_G3_PHYA_11_0  0xFFF   // 0/0/x/x External Register of Equalizer Tuning Mode Select
#define CND003_PCIEPHYCFG_EQUALIZER_ADAPTIVE_EQTN_MODE_LANE02_PHYA_G3 0x468 // Equalizer Adaptive EQTN Mode Lane02 PHYA G3
    #define CND003_PCIEPHYCFG_RSVPCIEPHYCFG_468_7          0xF000  // 0/x/x/x Reserved
    #define CND003_PCIEPHYCFG_FRP02_EQTNMODE_G3_PHYA_11_0  0xFFF   // 0/0/x/x External Register of Equalizer Tuning Mode Select
#define CND003_PCIEPHYCFG_EQUALIZER_ADAPTIVE_EQTN_MODE_LANE03_PHYA_G3 0x46A // Equalizer Adaptive EQTN Mode Lane03 PHYA G3
    #define CND003_PCIEPHYCFG_RSVPCIEPHYCFG_46A_7          0xF000  // 0/x/x/x Reserved
    #define CND003_PCIEPHYCFG_FRP03_EQTNMODE_G3_PHYA_11_0  0xFFF   // 0/0/x/x External Register of Equalizer Tuning Mode Select
#define CND003_PCIEPHYCFG_EQUALIZER_ADAPTIVE_EQTN_MODE_LANE00_PHYB_G3 0x46C // Equalizer Adaptive EQTN Mode Lane00 PHYB G3
    #define CND003_PCIEPHYCFG_RSVPCIEPHYCFG_46C_7          0xF000  // 0/x/x/x Reserved
    #define CND003_PCIEPHYCFG_FRP00_EQTNMODE_G3_PHYB_11_0  0xFFF   // 0/0/x/x External Register of Equalizer Tuning Mode Select
#define CND003_PCIEPHYCFG_EQUALIZER_ADAPTIVE_EQTN_MODE_LANE01_PHYB_G3 0x46E // Equalizer Adaptive EQTN Mode Lane01 PHYB G3
    #define CND003_PCIEPHYCFG_RSVPCIEPHYCFG_46E_7          0xF000  // 0/x/x/x Reserved
    #define CND003_PCIEPHYCFG_FRP01_EQTNMODE_G3_PHYB_11_0  0xFFF   // 0/0/x/x External Register of Equalizer Tuning Mode Select
#define CND003_PCIEPHYCFG_EQUALIZER_ADAPTIVE_EQTN_MODE_LANE02_PHYB_G3 0x470 // Equalizer Adaptive EQTN Mode Lane02 PHYB G3
    #define CND003_PCIEPHYCFG_RSVPCIEPHYCFG_470_7          0xF000  // 0/x/x/x Reserved
    #define CND003_PCIEPHYCFG_FRP02_EQTNMODE_G3_PHYB_11_0  0xFFF   // 0/0/x/x External Register of Equalizer Tuning Mode Select
#define CND003_PCIEPHYCFG_EQUALIZER_ADAPTIVE_EQTN_MODE_LANE03_PHYB_G3 0x472 // Equalizer Adaptive EQTN Mode Lane03 PHYB G3
    #define CND003_PCIEPHYCFG_RSVPCIEPHYCFG_472_7          0xF000  // 0/x/x/x Reserved
    #define CND003_PCIEPHYCFG_FRP03_EQTNMODE_G3_PHYB_11_0  0xFFF   // 0/0/x/x External Register of Equalizer Tuning Mode Select
#define CND003_PCIEPHYCFG_EQUALIZER_ADAPTIVE_EQTN_MODE_LANE00_EP_G3 0x474 // Equalizer Adaptive EQTN Mode Lane00 EP G3
    #define CND003_PCIEPHYCFG_RSVPCIEPHYCFG_474_7          0xF000  // 0/x/x/x Reserved
    #define CND003_PCIEPHYCFG_FRP00_EQTNMODE_G3_EP_11_0    0xFFF   // 0/0/x/x External Register of Equalizer Tuning Mode Select
#define CND003_PCIEPHYCFG_EQUALIZER_ADAPTIVE_EQTN_MODE_LANE01_EP_G3 0x476 // Equalizer Adaptive EQTN Mode Lane01 EP G3
    #define CND003_PCIEPHYCFG_RSVPCIEPHYCFG_477_7          0xF000  // 0/x/x/x Reserved
    #define CND003_PCIEPHYCFG_FRP01_EQTNMODE_G3_EP_11_0    0xFFF   // 0/0/x/x External Register of Equalizer Tuning Mode Select
#define CND003_PCIEPHYCFG_EQUALIZER_ADAPTIVE_EQTN_MODE_LANE02_EP_G3 0x478 // Equalizer Adaptive EQTN Mode Lane02 EP G3
    #define CND003_PCIEPHYCFG_RSVPCIEPHYCFG_478_7          0xF000  // 0/x/x/x Reserved
    #define CND003_PCIEPHYCFG_FRP02_EQTNMODE_G3_EP_11_0    0xFFF   // 0/0/x/x External Register of Equalizer Tuning Mode Select
#define CND003_PCIEPHYCFG_EQUALIZER_ADAPTIVE_EQTN_MODE_LANE03_EP_G3 0x47A // Equalizer Adaptive EQTN Mode Lane03 EP G3
    #define CND003_PCIEPHYCFG_RSVPCIEPHYCFG_47A_7          0xF000  // 0/x/x/x Reserved
    #define CND003_PCIEPHYCFG_FRP03_EQTNMODE_G3_EP_11_0    0xFFF   // 0/0/x/x External Register of Equalizer Tuning Mode Select
#define CND003_PCIEPHYCFG_EQUALIZER_ADAPTIVE_EQTN_MODE_LANE00_PHYC_G3 0x47C // Equalizer Adaptive EQTN Mode Lane00 PHYC G3
    #define CND003_PCIEPHYCFG_RSVPCIEPHYCFG_47C_7 PCIEPHYCFG_EQUALIZER_ADAPTIVE_EQTN_MODE_LANE00_PHYC_G3 // 0/x/x/x Reserved
#define CND003_PCIEPHYCFG_EQUALIZER_ADAPTIVE_EQTN_MODE_LANE01_PHYC_G3 0x47E // Equalizer Adaptive EQTN Mode Lane01 PHYC G3
    #define CND003_PCIEPHYCFG_RSVPCIEPHYCFG_47E_7 PCIEPHYCFG_EQUALIZER_ADAPTIVE_EQTN_MODE_LANE01_PHYC_G3 // 0/x/x/x Reserved
#define CND003_PCIEPHYCFG_RESERVED_Z23 0x480 // Reserved
    #define CND003_PCIEPHYCFG_RSVPCIEPHYCFG_480_7 PCIEPHYCFG_RESERVED_Z23 // 0/x/x/x Reserved
#define CND003_PCIEPHYCFG_RESERVED_Z24 0x481 // Reserved
    #define CND003_PCIEPHYCFG_RSVPCIEPHYCFG_481_7 PCIEPHYCFG_RESERVED_Z24 // 0/x/x/x Reserved
#define CND003_PCIEPHYCFG_EQUALIZER_ADAPTIVE_EQTN_DC_HF_BANDWIDTH_LANE00_G1 0x500 // Equalizer Adaptive EQTN DC/HF Bandwidth Lane00 G1
    #define CND003_PCIEPHYCFG_RSV_500 PCIEPHYCFG_EQUALIZER_ADAPTIVE_EQTN_DC_HF_BANDWIDTH_LANE00_G1 // 0/0/x/X Reserved
#define CND003_PCIEPHYCFG_EQUALIZER_ADAPTIVE_EQTN_DC_HF_BANDWIDTH_LANE04_PHYA_G1 0x502 // Equalizer Adaptive EQTN DC/HF Bandwidth Lane04 PHYA G1
    #define CND003_PCIEPHYCFG_FRP04_EQTNDCBW_G1_PHYA_3_0   0xF000  // 0001b/0001/x/x LEQ DC Gain Tuning Bandwidth Set
    #define CND003_PCIEPHYCFG_FRP04_EQTNHFBW_G1_PHYA_3_0   0xF00   // 0001b/0001/x/x LEQ HF Gain Tuning Bandwidth Set
    #define CND003_PCIEPHYCFG_FRP04_EQTNOSBW_G1_PHYA_3_0   0xF0    // 0001b/0001/x/x LEQ Offset Tuning Bandwidth Set
    #define CND003_PCIEPHYCFG_FRP04_EQTNWTBW_G1_PHYA_3_0   0xF     // 0001b/0001/x/x DFE Weight Tuning Bandwidth Set
#define CND003_PCIEPHYCFG_EQUALIZER_ADAPTIVE_EQTN_DC_HF_BANDWIDTH_LANE00_PHYA_G1 0x504 // Equalizer Adaptive EQTN DC/HF Bandwidth Lane00 PHYA G1
    #define CND003_PCIEPHYCFG_FRP00_EQTNDCBW_G1_PHYA_3_0   0xF000  // 0001b/0001/x/x LEQ DC Gain Tuning Bandwidth Set
    #define CND003_PCIEPHYCFG_FRP00_EQTNHFBW_G1_PHYA_3_0   0xF00   // 0001b/0001/x/x LEQ HF Gain Tuning Bandwidth Set
    #define CND003_PCIEPHYCFG_FRP00_EQTNOSBW_G1_PHYA_3_0   0xF0    // 0001b/0001/x/x LEQ Offset Tuning Bandwidth Set
    #define CND003_PCIEPHYCFG_FRP00_EQTNWTBW_G1_PHYA_3_0   0xF     // 0001b/0001/x/x DFE Weight Tuning Bandwidth Set
#define CND003_PCIEPHYCFG_EQUALIZER_ADAPTIVE_EQTN_DC_HF_BANDWIDTH_LANE01_PHYA_G1 0x506 // Equalizer Adaptive EQTN DC/HF Bandwidth Lane01 PHYA G1
    #define CND003_PCIEPHYCFG_FRP01_EQTNDCBW_G1_PHYA_3_0   0xF000  // 0001b/0001/x/x LEQ DC Gain Tuning Bandwidth Set
    #define CND003_PCIEPHYCFG_FRP01_EQTNHFBW_G1_PHYA_3_0   0xF00   // 0001b/0001/x/x LEQ HF Gain Tuning Bandwidth Set
    #define CND003_PCIEPHYCFG_FRP01_EQTNOSBW_G1_PHYA_3_0   0xF0    // 0001b/0001/x/x LEQ Offset Tuning Bandwidth Set
    #define CND003_PCIEPHYCFG_FRP01_EQTNWTBW_G1_PHYA_3_0   0xF     // 0001b/0001/x/x DFE Weight Tuning Bandwidth Set
#define CND003_PCIEPHYCFG_EQUALIZER_ADAPTIVE_EQTN_DC_HF_BANDWIDTH_LANE02_PHYA_G1 0x508 // Equalizer Adaptive EQTN DC/HF Bandwidth Lane02 PHYA G1
    #define CND003_PCIEPHYCFG_FRP02_EQTNDCBW_G1_PHYA_3_0   0xF000  // 0001b/0001/x/x LEQ DC Gain Tuning Bandwidth Set
    #define CND003_PCIEPHYCFG_FRP02_EQTNHFBW_G1_PHYA_3_0   0xF00   // 0001b/0001/x/x LEQ HF Gain Tuning Bandwidth Set
    #define CND003_PCIEPHYCFG_FRP02_EQTNOSBW_G1_PHYA_3_0   0xF0    // 0001b/0001/x/x LEQ Offset Tuning Bandwidth Set
    #define CND003_PCIEPHYCFG_FRP02_EQTNWTBW_G1_PHYA_3_0   0xF     // 0001b/0001/x/x DFE Weight Tuning Bandwidth Set
#define CND003_PCIEPHYCFG_EQUALIZER_ADAPTIVE_EQTN_DC_HF_BANDWIDTH_LANE03_PHYA_G1 0x50A // Equalizer Adaptive EQTN DC/HF Bandwidth Lane03 PHYA G1
    #define CND003_PCIEPHYCFG_FRP03_EQTNDCBW_G1_PHYA_3_0   0xF000  // 0001b/0001/x/x LEQ DC Gain Tuning Bandwidth Set
    #define CND003_PCIEPHYCFG_FRP03_EQTNHFBW_G1_PHYA_3_0   0xF00   // 0001b/0001/x/x LEQ HF Gain Tuning Bandwidth Set
    #define CND003_PCIEPHYCFG_FRP03_EQTNOSBW_G1_PHYA_3_0   0xF0    // 0001b/0001/x/x LEQ Offset Tuning Bandwidth Set
    #define CND003_PCIEPHYCFG_FRP03_EQTNWTBW_G1_PHYA_3_0   0xF     // 0001b/0001/x/x DFE Weight Tuning Bandwidth Set
#define CND003_PCIEPHYCFG_EQUALIZER_ADAPTIVE_EQTN_DC_HF_BANDWIDTH_LANE00_PHYB_G1 0x50C // Equalizer Adaptive EQTN DC/HF Bandwidth Lane00 PHYB G1
    #define CND003_PCIEPHYCFG_FRP00_EQTNDCBW_G1_PHYB_3_0   0xF000  // 0001b/0001/x/x LEQ DC Gain Tuning Bandwidth Set
    #define CND003_PCIEPHYCFG_FRP00_EQTNHFBW_G1_PHYB_3_0   0xF00   // 0001b/0001/x/x LEQ HF Gain Tuning Bandwidth Set
    #define CND003_PCIEPHYCFG_FRP00_EQTNOSBW_G1_PHYB_3_0   0xF0    // 0001b/0001/x/x LEQ Offset Tuning Bandwidth Set
    #define CND003_PCIEPHYCFG_FRP00_EQTNWTBW_G1_PHYB_3_0   0xF     // 0001b/0001/x/x DFE Weight Tuning Bandwidth Set
#define CND003_PCIEPHYCFG_EQUALIZER_ADAPTIVE_EQTN_DC_HF_BANDWIDTH_LANE01_PHYB_G1 0x50E // Equalizer Adaptive EQTN DC/HF Bandwidth Lane01 PHYB G1
    #define CND003_PCIEPHYCFG_FRP01_EQTNDCBW_G1_PHYB_3_0   0xF000  // 0001b/0001/x/x LEQ DC Gain Tuning Bandwidth Set
    #define CND003_PCIEPHYCFG_FRP01_EQTNHFBW_G1_PHYB_3_0   0xF00   // 0001b/0001/x/x LEQ HF Gain Tuning Bandwidth Set
    #define CND003_PCIEPHYCFG_FRP01_EQTNOSBW_G1_PHYB_3_0   0xF0    // 0001b/0001/x/x LEQ Offset Tuning Bandwidth Set
    #define CND003_PCIEPHYCFG_FRP01_EQTNWTBW_G1_PHYB_3_0   0xF     // 0001b/0001/x/x DFE Weight Tuning Bandwidth Set
#define CND003_PCIEPHYCFG_EQUALIZER_ADAPTIVE_EQTN_DC_HF_BANDWIDTH_LANE02_PHYB_G1 0x510 // Equalizer Adaptive EQTN DC/HF Bandwidth Lane02 PHYB G1
    #define CND003_PCIEPHYCFG_FRP02_EQTNDCBW_G1_PHYB_3_0   0xF000  // 0001b/0001/x/x LEQ DC Gain Tuning Bandwidth Set
    #define CND003_PCIEPHYCFG_FRP02_EQTNHFBW_G1_PHYB_3_0   0xF00   // 0001b/0001/x/x LEQ HF Gain Tuning Bandwidth Set
    #define CND003_PCIEPHYCFG_FRP02_EQTNOSBW_G1_PHYB_3_0   0xF0    // 0001b/0001/x/x LEQ Offset Tuning Bandwidth Set
    #define CND003_PCIEPHYCFG_FRP02_EQTNWTBW_G1_PHYB_3_0   0xF     // 0001b/0001/x/x DFE Weight Tuning Bandwidth Set
#define CND003_PCIEPHYCFG_EQUALIZER_ADAPTIVE_EQTN_DC_HF_BANDWIDTH_LANE03_PHYB_G1 0x512 // Equalizer Adaptive EQTN DC/HF Bandwidth Lane03 PHYB G1
    #define CND003_PCIEPHYCFG_FRP03_EQTNDCBW_G1_PHYB_3_0   0xF000  // 0001b/0001/x/x LEQ DC Gain Tuning Bandwidth Set
    #define CND003_PCIEPHYCFG_FRP03_EQTNHFBW_G1_PHYB_3_0   0xF00   // 0001b/0001/x/x LEQ HF Gain Tuning Bandwidth Set
    #define CND003_PCIEPHYCFG_FRP03_EQTNOSBW_G1_PHYB_3_0   0xF0    // 0001b/0001/x/x LEQ Offset Tuning Bandwidth Set
    #define CND003_PCIEPHYCFG_FRP03_EQTNWTBW_G1_PHYB_3_0   0xF     // 0001b/0001/x/x DFE Weight Tuning Bandwidth Set
#define CND003_PCIEPHYCFG_EQUALIZER_ADAPTIVE_EQTN_DC_HF_BANDWIDTH_LANE00_EP_G1 0x514 // Equalizer Adaptive EQTN DC/HF Bandwidth Lane00 EP G1
    #define CND003_PCIEPHYCFG_FRP00_EQTNDCBW_G1_EP_3_0 0xF000  // 0001b/0001/x/x LEQ DC Gain Tuning Bandwidth Set
    #define CND003_PCIEPHYCFG_FRP00_EQTNHFBW_G1_EP_3_0 0xF00   // 0001b/0001/x/x LEQ HF Gain Tuning Bandwidth Set
    #define CND003_PCIEPHYCFG_FRP00_EQTNOSBW_G1_EP_3_0 0xF0    // 0001b/0001/x/x LEQ Offset Tuning Bandwidth Set
    #define CND003_PCIEPHYCFG_FRP00_EQTNWTBW_G1_EP_3_0 0xF     // 0001b/0001/x/x DFE Weight Tuning Bandwidth Set
#define CND003_PCIEPHYCFG_EQUALIZER_ADAPTIVE_EQTN_DC_HF_BANDWIDTH_LANE01_EP_G1 0x516 // Equalizer Adaptive EQTN DC/HF Bandwidth Lane01 EP G1
    #define CND003_PCIEPHYCFG_FRP01_EQTNDCBW_G1_EP_3_0 0xF000  // 0001b/0001/x/x LEQ DC Gain Tuning Bandwidth Set
    #define CND003_PCIEPHYCFG_FRP01_EQTNHFBW_G1_EP_3_0 0xF00   // 0001b/0001/x/x LEQ HF Gain Tuning Bandwidth Set
    #define CND003_PCIEPHYCFG_FRP01_EQTNOSBW_G1_EP_3_0 0xF0    // 0001b/0001/x/x LEQ Offset Tuning Bandwidth Set
    #define CND003_PCIEPHYCFG_FRP01_EQTNWTBW_G1_EP_3_0 0xF     // 0001b/0001/x/x DFE Weight Tuning Bandwidth Set
#define CND003_PCIEPHYCFG_EQUALIZER_ADAPTIVE_EQTN_DC_HF_BANDWIDTH_LANE02_EP_G1 0x518 // Equalizer Adaptive EQTN DC/HF Bandwidth Lane02 EP G1
    #define CND003_PCIEPHYCFG_FRP02_EQTNDCBW_G1_EP_3_0 0xF000  // 0001b/0001/x/x LEQ DC Gain Tuning Bandwidth Set
    #define CND003_PCIEPHYCFG_FRP02_EQTNHFBW_G1_EP_3_0 0xF00   // 0001b/0001/x/x LEQ HF Gain Tuning Bandwidth Set
    #define CND003_PCIEPHYCFG_FRP02_EQTNOSBW_G1_EP_3_0 0xF0    // 0001b/0001/x/x LEQ Offset Tuning Bandwidth Set
    #define CND003_PCIEPHYCFG_FRP02_EQTNWTBW_G1_EP_3_0 0xF     // 0001b/0001/x/x DFE Weight Tuning Bandwidth Set
#define CND003_PCIEPHYCFG_EQUALIZER_ADAPTIVE_EQTN_DC_HF_BANDWIDTH_LANE03_EP_G1 0x51A // Equalizer Adaptive EQTN DC/HF Bandwidth Lane03 EP G1
    #define CND003_PCIEPHYCFG_FRP03_EQTNDCBW_G1_EP_3_0 0xF000  // 0001b/0001/x/x LEQ DC Gain Tuning Bandwidth Set
    #define CND003_PCIEPHYCFG_FRP03_EQTNHFBW_G1_EP_3_0 0xF00   // 0001b/0001/x/x LEQ HF Gain Tuning Bandwidth Set
    #define CND003_PCIEPHYCFG_FRP03_EQTNOSBW_G1_EP_3_0 0xF0    // 0001b/0001/x/x LEQ Offset Tuning Bandwidth Set
    #define CND003_PCIEPHYCFG_FRP03_EQTNWTBW_G1_EP_3_0 0xF     // 0001b/0001/x/x DFE Weight Tuning Bandwidth Set
#define CND003_PCIEPHYCFG_EQUALIZER_ADAPTIVE_EQTN_DC_HF_BANDWIDTH_LANE00_PHYC_G1 0x51C // Equalizer Adaptive EQTN DC/HF Bandwidth Lane00 PHYC G1
    #define CND003_PCIEPHYCFG_FRP00_EQTNDCBW_PHYC_G1 PCIEPHYCFG_EQUALIZER_ADAPTIVE_EQTN_DC_HF_BANDWIDTH_LANE00_PHYC_G1 // 0/0/x/X Reserved
#define CND003_PCIEPHYCFG_EQUALIZER_ADAPTIVE_EQTN_DC_HF_BANDWIDTH_LANE01_PHYC_G1 0x51E // Equalizer Adaptive EQTN DC/HF Bandwidth Lane01 PHYC G1
    #define CND003_PCIEPHYCFG_FRP01_EQTNDCBW_PHYC_G1 PCIEPHYCFG_EQUALIZER_ADAPTIVE_EQTN_DC_HF_BANDWIDTH_LANE01_PHYC_G1 // 0/0/x/x Reserved
#define CND003_PCIEPHYCFG_RESERVED_Z25 0x520 // Reserved
    #define CND003_PCIEPHYCFG_RSVPCIEPHYCFG_520_7 PCIEPHYCFG_RESERVED_Z25 // 0/x/x/x Reserved
#define CND003_PCIEPHYCFG_RESERVED_Z26 0x521 // Reserved
    #define CND003_PCIEPHYCFG_RSVPCIEPHYCFG_521_7 PCIEPHYCFG_RESERVED_Z26 // 0/x/x/x Reserved
#define CND003_PCIEPHYCFG_EQUALIZER_ADAPTIVE_EQTN_DC_HF_BANDWIDTH_LANE00_G2 0x530 // Equalizer Adaptive EQTN DC/HF Bandwidth Lane00 G2
    #define CND003_PCIEPHYCFG_FRP00_EQTNDCBW_G2 PCIEPHYCFG_EQUALIZER_ADAPTIVE_EQTN_DC_HF_BANDWIDTH_LANE00_G2 // 0/0/x/X Reserved
#define CND003_PCIEPHYCFG_EQUALIZER_ADAPTIVE_EQTN_DC_HF_BANDWIDTH_LANE04_PHYA_G2 0x532 // Equalizer Adaptive EQTN DC/HF Bandwidth Lane04 PHYA G2
    #define CND003_PCIEPHYCFG_FRP04_EQTNDCBW_G2_PHYA_3_0   0xF000  // 0001b/0001/x/x LEQ DC Gain Tuning Bandwidth Set
    #define CND003_PCIEPHYCFG_FRP04_EQTNHFBW_G2_PHYA_3_0   0xF00   // 0001b/0001/x/x LEQ HF Gain Tuning Bandwidth Set
    #define CND003_PCIEPHYCFG_FRP04_EQTNOSBW_G2_PHYA_3_0   0xF0    // 0001b/0001/x/x LEQ Offset Tuning Bandwidth Set
    #define CND003_PCIEPHYCFG_FRP04_EQTNWTBW_G2_PHYA_3_0   0xF     // 0001b/0001/x/x DFE Weight Tuning Bandwidth Set
#define CND003_PCIEPHYCFG_EQUALIZER_ADAPTIVE_EQTN_DC_HF_BANDWIDTH_LANE00_PHYA_G2 0x534 // Equalizer Adaptive EQTN DC/HF Bandwidth Lane00 PHYA G2
    #define CND003_PCIEPHYCFG_FRP00_EQTNDCBW_G2_PHYA_3_0   0xF000  // 0001b/0001/x/x LEQ DC Gain Tuning Bandwidth Set
    #define CND003_PCIEPHYCFG_FRP00_EQTNHFBW_G2_PHYA_3_0   0xF00   // 0001b/0001/x/x LEQ HF Gain Tuning Bandwidth Set
    #define CND003_PCIEPHYCFG_FRP00_EQTNOSBW_G2_PHYA_3_0   0xF0    // 0001b/0001/x/x LEQ Offset Tuning Bandwidth Set
    #define CND003_PCIEPHYCFG_FRP00_EQTNWTBW_G2_PHYA_3_0   0xF     // 0001b/0001/x/x DFE Weight Tuning Bandwidth Set
#define CND003_PCIEPHYCFG_EQUALIZER_ADAPTIVE_EQTN_DC_HF_BANDWIDTH_LANE01_PHYA_G2 0x536 // Equalizer Adaptive EQTN DC/HF Bandwidth Lane01 PHYA G2
    #define CND003_PCIEPHYCFG_FRP01_EQTNDCBW_G2_PHYA_3_0   0xF000  // 0001b/0001/x/x LEQ DC Gain Tuning Bandwidth Set
    #define CND003_PCIEPHYCFG_FRP01_EQTNHFBW_G2_PHYA_3_0   0xF00   // 0001b/0001/x/x LEQ HF Gain Tuning Bandwidth Set
    #define CND003_PCIEPHYCFG_FRP01_EQTNOSBW_G2_PHYA_3_0   0xF0    // 0001b/0001/x/x LEQ Offset Tuning Bandwidth Set
    #define CND003_PCIEPHYCFG_FRP01_EQTNWTBW_G2_PHYA_3_0   0xF     // 0001b/0001/x/x DFE Weight Tuning Bandwidth Set
#define CND003_PCIEPHYCFG_EQUALIZER_ADAPTIVE_EQTN_DC_HF_BANDWIDTH_LANE02_PHYA_G2 0x538 // Equalizer Adaptive EQTN DC/HF Bandwidth Lane02 PHYA G2
    #define CND003_PCIEPHYCFG_FRP02_EQTNDCBW_G2_PHYA_3_0   0xF000  // 0001b/0001/x/x LEQ DC Gain Tuning Bandwidth Set
    #define CND003_PCIEPHYCFG_FRP02_EQTNHFBW_G2_PHYA_3_0   0xF00   // 0001b/0001/x/x LEQ HF Gain Tuning Bandwidth Set
    #define CND003_PCIEPHYCFG_FRP02_EQTNOSBW_G2_PHYA_3_0   0xF0    // 0001b/0001/x/x LEQ Offset Tuning Bandwidth Set
    #define CND003_PCIEPHYCFG_FRP02_EQTNWTBW_G2_PHYA_3_0   0xF     // 0001b/0001/x/x DFE Weight Tuning Bandwidth Set
#define CND003_PCIEPHYCFG_EQUALIZER_ADAPTIVE_EQTN_DC_HF_BANDWIDTH_LANE03_PHYA_G2 0x53A // Equalizer Adaptive EQTN DC/HF Bandwidth Lane03 PHYA G2
    #define CND003_PCIEPHYCFG_FRP03_EQTNDCBW_G2_PHYA_3_0   0xF000  // 0001b/0001/x/x LEQ DC Gain Tuning Bandwidth Set
    #define CND003_PCIEPHYCFG_FRP03_EQTNHFBW_G2_PHYA_3_0   0xF00   // 0001b/0001/x/x LEQ HF Gain Tuning Bandwidth Set
    #define CND003_PCIEPHYCFG_FRP03_EQTNOSBW_G2_PHYA_3_0   0xF0    // 0001b/0001/x/x LEQ Offset Tuning Bandwidth Set
    #define CND003_PCIEPHYCFG_FRP03_EQTNWTBW_G2_PHYA_3_0   0xF     // 0001b/0001/x/x DFE Weight Tuning Bandwidth Set
#define CND003_PCIEPHYCFG_EQUALIZER_ADAPTIVE_EQTN_DC_HF_BANDWIDTH_LANE00_PHYB_G2 0x53C // Equalizer Adaptive EQTN DC/HF Bandwidth Lane00 PHYB G2
    #define CND003_PCIEPHYCFG_FRP00_EQTNDCBW_G2_PHYB_3_0   0xF000  // 0001b/0001/x/x LEQ DC Gain Tuning Bandwidth Set
    #define CND003_PCIEPHYCFG_FRP00_EQTNHFBW_G2_PHYB_3_0   0xF00   // 0001b/0001/x/x LEQ HF Gain Tuning Bandwidth Set
    #define CND003_PCIEPHYCFG_FRP00_EQTNOSBW_G2_PHYB_3_0   0xF0    // 0001b/0001/x/x LEQ Offset Tuning Bandwidth Set
    #define CND003_PCIEPHYCFG_FRP00_EQTNWTBW_G2_PHYB_3_0   0xF     // 0001b/0001/x/x DFE Weight Tuning Bandwidth Set
#define CND003_PCIEPHYCFG_EQUALIZER_ADAPTIVE_EQTN_DC_HF_BANDWIDTH_LANE01_PHYB_G2 0x53E // Equalizer Adaptive EQTN DC/HF Bandwidth Lane01 PHYB G2
    #define CND003_PCIEPHYCFG_FRP01_EQTNDCBW_G2_PHYB_3_0   0xF000  // 0001b/0001/x/x LEQ DC Gain Tuning Bandwidth Set
    #define CND003_PCIEPHYCFG_FRP01_EQTNHFBW_G2_PHYB_3_0   0xF00   // 0001b/0001/x/x LEQ HF Gain Tuning Bandwidth Set
    #define CND003_PCIEPHYCFG_FRP01_EQTNOSBW_G2_PHYB_3_0   0xF0    // 0001b/0001/x/x LEQ Offset Tuning Bandwidth Set
    #define CND003_PCIEPHYCFG_FRP01_EQTNWTBW_G2_PHYB_3_0   0xF     // 0001b/0001/x/x DFE Weight Tuning Bandwidth Set
#define CND003_PCIEPHYCFG_EQUALIZER_ADAPTIVE_EQTN_DC_HF_BANDWIDTH_LANE02_PHYB_G2 0x540 // Equalizer Adaptive EQTN DC/HF Bandwidth Lane02 PHYB G2
    #define CND003_PCIEPHYCFG_FRP02_EQTNDCBW_G2_PHYB_3_0   0xF000  // 0001b/0001/x/x LEQ DC Gain Tuning Bandwidth Set
    #define CND003_PCIEPHYCFG_FRP02_EQTNHFBW_G2_PHYB_3_0   0xF00   // 0001b/0001/x/x LEQ HF Gain Tuning Bandwidth Set
    #define CND003_PCIEPHYCFG_FRP02_EQTNOSBW_G2_PHYB_3_0   0xF0    // 0001b/0001/x/x LEQ Offset Tuning Bandwidth Set
    #define CND003_PCIEPHYCFG_FRP02_EQTNWTBW_G2_PHYB_3_0   0xF     // 0001b/0001/x/x DFE Weight Tuning Bandwidth Set
#define CND003_PCIEPHYCFG_EQUALIZER_ADAPTIVE_EQTN_DC_HF_BANDWIDTH_LANE03_PHYB_G2 0x542 // Equalizer Adaptive EQTN DC/HF Bandwidth Lane03 PHYB G2
    #define CND003_PCIEPHYCFG_FRP03_EQTNDCBW_G2_PHYB_3_0   0xF000  // 0001b/0001/x/x LEQ DC Gain Tuning Bandwidth Set
    #define CND003_PCIEPHYCFG_FRP03_EQTNHFBW_G2_PHYB_3_0   0xF00   // 0001b/0001/x/x LEQ HF Gain Tuning Bandwidth Set
    #define CND003_PCIEPHYCFG_FRP03_EQTNOSBW_G2_PHYB_3_0   0xF0    // 0001b/0001/x/x LEQ Offset Tuning Bandwidth Set
    #define CND003_PCIEPHYCFG_FRP03_EQTNWTBW_G2_PHYB_3_0   0xF     // 0001b/0001/x/x DFE Weight Tuning Bandwidth Set
#define CND003_PCIEPHYCFG_EQUALIZER_ADAPTIVE_EQTN_DC_HF_BANDWIDTH_LANE00_EP_G2 0x544 // Equalizer Adaptive EQTN DC/HF Bandwidth Lane00 EP G2
    #define CND003_PCIEPHYCFG_FRP00_EQTNDCBW_G2_EP_3_0 0xF000  // 0001b/0001/x/x LEQ DC Gain Tuning Bandwidth Set
    #define CND003_PCIEPHYCFG_FRP00_EQTNHFBW_G2_EP_3_0 0xF00   // 0001b/0001/x/x LEQ HF Gain Tuning Bandwidth Set
    #define CND003_PCIEPHYCFG_FRP00_EQTNOSBW_G2_EP_3_0 0xF0    // 0001b/0001/x/x LEQ Offset Tuning Bandwidth Set
    #define CND003_PCIEPHYCFG_FRP00_EQTNWTBW_G2_EP_3_0 0xF     // 0001b/0001/x/x DFE Weight Tuning Bandwidth Set
#define CND003_PCIEPHYCFG_EQUALIZER_ADAPTIVE_EQTN_DC_HF_BANDWIDTH_LANE01_EP_G2 0x546 // Equalizer Adaptive EQTN DC/HF Bandwidth Lane01 EP G2
    #define CND003_PCIEPHYCFG_FRP01_EQTNDCBW_G2_EP_3_0 0xF000  // 0001b/0001/x/x LEQ DC Gain Tuning Bandwidth Set
    #define CND003_PCIEPHYCFG_FRP01_EQTNHFBW_G2_EP_3_0 0xF00   // 0001b/0001/x/x LEQ HF Gain Tuning Bandwidth Set
    #define CND003_PCIEPHYCFG_FRP01_EQTNOSBW_G2_EP_3_0 0xF0    // 0001b/0001/x/x LEQ Offset Tuning Bandwidth Set
    #define CND003_PCIEPHYCFG_FRP01_EQTNWTBW_G2_EP_3_0 0xF     // 0001b/0001/x/x DFE Weight Tuning Bandwidth Set
#define CND003_PCIEPHYCFG_EQUALIZER_ADAPTIVE_EQTN_DC_HF_BANDWIDTH_LANE02_EP_G2 0x548 // Equalizer Adaptive EQTN DC/HF Bandwidth Lane02 EP G2
    #define CND003_PCIEPHYCFG_FRP02_EQTNDCBW_G2_EP_3_0 0xF000  // 0001b/0001/x/x LEQ DC Gain Tuning Bandwidth Set
    #define CND003_PCIEPHYCFG_FRP02_EQTNHFBW_G2_EP_3_0 0xF00   // 0001b/0001/x/x LEQ HF Gain Tuning Bandwidth Set
    #define CND003_PCIEPHYCFG_FRP02_EQTNOSBW_G2_EP_3_0 0xF0    // 0001b/0001/x/x LEQ Offset Tuning Bandwidth Set
    #define CND003_PCIEPHYCFG_FRP02_EQTNWTBW_G2_EP_3_0 0xF     // 0001b/0001/x/x DFE Weight Tuning Bandwidth Set
#define CND003_PCIEPHYCFG_EQUALIZER_ADAPTIVE_EQTN_DC_HF_BANDWIDTH_LANE03_EP_G2 0x54A // Equalizer Adaptive EQTN DC/HF Bandwidth Lane03 EP G2
    #define CND003_PCIEPHYCFG_FRP03_EQTNDCBW_G2_EP_3_0 0xF000  // 0001b/0001/x/x LEQ DC Gain Tuning Bandwidth Set
    #define CND003_PCIEPHYCFG_FRP03_EQTNHFBW_G2_EP_3_0 0xF00   // 0001b/0001/x/x LEQ HF Gain Tuning Bandwidth Set
    #define CND003_PCIEPHYCFG_FRP03_EQTNOSBW_G2_EP_3_0 0xF0    // 0001b/0001/x/x LEQ Offset Tuning Bandwidth Set
    #define CND003_PCIEPHYCFG_FRP03_EQTNWTBW_G2_EP_3_0 0xF     // 0001b/0001/x/x DFE Weight Tuning Bandwidth Set
#define CND003_PCIEPHYCFG_EQUALIZER_ADAPTIVE_EQTN_DC_HF_BANDWIDTH_LANE00_PHYC_G2 0x54C // Equalizer Adaptive EQTN DC/HF Bandwidth Lane00 PHYC G2
    #define CND003_PCIEPHYCFG_FRP00_EQTNDCBW_PHYC_G2 PCIEPHYCFG_EQUALIZER_ADAPTIVE_EQTN_DC_HF_BANDWIDTH_LANE00_PHYC_G2 // 0/0/x/X Reserved
#define CND003_PCIEPHYCFG_EQUALIZER_ADAPTIVE_EQTN_DC_HF_BANDWIDTH_LANE01_PHYC_G2 0x54E // Equalizer Adaptive EQTN DC/HF Bandwidth Lane01 PHYC G2
    #define CND003_PCIEPHYCFG_FRP01_EQTNDCBW_PHYC_G2 PCIEPHYCFG_EQUALIZER_ADAPTIVE_EQTN_DC_HF_BANDWIDTH_LANE01_PHYC_G2 // 0/0/x/x Reserved
#define CND003_PCIEPHYCFG_RESERVED_Z27 0x550 // Reserved
    #define CND003_PCIEPHYCFG_RSVPCIEPHYCFG_550_7 PCIEPHYCFG_RESERVED_Z27 // 0/x/x/x Reserved
#define CND003_PCIEPHYCFG_RESERVED_Z28 0x551 // Reserved
    #define CND003_PCIEPHYCFG_RSVPCIEPHYCFG_551_7 PCIEPHYCFG_RESERVED_Z28 // 0/x/x/x Reserved
#define CND003_PCIEPHYCFG_EQUALIZER_ADAPTIVE_EQTN_DC_HF_BANDWIDTH_LANE00_G3 0x560 // Equalizer Adaptive EQTN DC/HF Bandwidth Lane00 G3
    #define CND003_PCIEPHYCFG_FRP00_EQTNDCBW_G3 PCIEPHYCFG_EQUALIZER_ADAPTIVE_EQTN_DC_HF_BANDWIDTH_LANE00_G3 // 0/0/x/X Reserved
#define CND003_PCIEPHYCFG_EQUALIZER_ADAPTIVE_EQTN_DC_HF_BANDWIDTH_LANE04_PHYA_G3 0x562 // Equalizer Adaptive EQTN DC/HF Bandwidth Lane04 PHYA G3
    #define CND003_PCIEPHYCFG_FRP04_EQTNDCBW_G3_PHYA_3_0   0xF000  // 0001b/0001/x/x LEQ DC Gain Tuning Bandwidth Set
    #define CND003_PCIEPHYCFG_FRP04_EQTNHFBW_G3_PHYA_3_0   0xF00   // 0001b/0001/x/x LEQ HF Gain Tuning Bandwidth Set
    #define CND003_PCIEPHYCFG_FRP04_EQTNOSBW_G3_PHYA_3_0   0xF0    // 0001b/0001/x/x LEQ Offset Tuning Bandwidth Set
    #define CND003_PCIEPHYCFG_FRP04_EQTNWTBW_G3_PHYA_3_0   0xF     // 0001b/0001/x/x DFE Weight Tuning Bandwidth Set
#define CND003_PCIEPHYCFG_EQUALIZER_ADAPTIVE_EQTN_DC_HF_BANDWIDTH_LANE00_PHYA_G3 0x564 // Equalizer Adaptive EQTN DC/HF Bandwidth Lane00 PHYA G3
    #define CND003_PCIEPHYCFG_FRP00_EQTNDCBW_G3_PHYA_3_0   0xF000  // 0001b/0001/x/x LEQ DC Gain Tuning Bandwidth Set
    #define CND003_PCIEPHYCFG_FRP00_EQTNHFBW_G3_PHYA_3_0   0xF00   // 0001b/0001/x/x LEQ HF Gain Tuning Bandwidth Set
    #define CND003_PCIEPHYCFG_FRP00_EQTNOSBW_G3_PHYA_3_0   0xF0    // 0001b/0001/x/x LEQ Offset Tuning Bandwidth Set
    #define CND003_PCIEPHYCFG_FRP00_EQTNWTBW_G3_PHYA_3_0   0xF     // 0001b/0001/x/x DFE Weight Tuning Bandwidth Set
#define CND003_PCIEPHYCFG_EQUALIZER_ADAPTIVE_EQTN_DC_HF_BANDWIDTH_LANE01_PHYA_G3 0x566 // Equalizer Adaptive EQTN DC/HF Bandwidth Lane01 PHYA G3
    #define CND003_PCIEPHYCFG_FRP01_EQTNDCBW_G3_PHYA_3_0   0xF000  // 0001b/0001/x/x LEQ DC Gain Tuning Bandwidth Set
    #define CND003_PCIEPHYCFG_FRP01_EQTNHFBW_G3_PHYA_3_0   0xF00   // 0001b/0001/x/x LEQ HF Gain Tuning Bandwidth Set
    #define CND003_PCIEPHYCFG_FRP01_EQTNOSBW_G3_PHYA_3_0   0xF0    // 0001b/0001/x/x LEQ Offset Tuning Bandwidth Set
    #define CND003_PCIEPHYCFG_FRP01_EQTNWTBW_G3_PHYA_3_0   0xF     // 0001b/0001/x/x DFE Weight Tuning Bandwidth Set
#define CND003_PCIEPHYCFG_EQUALIZER_ADAPTIVE_EQTN_DC_HF_BANDWIDTH_LANE02_PHYA_G3 0x568 // Equalizer Adaptive EQTN DC/HF Bandwidth Lane02 PHYA G3
    #define CND003_PCIEPHYCFG_FRP02_EQTNDCBW_G3_PHYA_3_0   0xF000  // 0001b/0001/x/x LEQ DC Gain Tuning Bandwidth Set
    #define CND003_PCIEPHYCFG_FRP02_EQTNHFBW_G3_PHYA_3_0   0xF00   // 0001b/0001/x/x LEQ HF Gain Tuning Bandwidth Set
    #define CND003_PCIEPHYCFG_FRP02_EQTNOSBW_G3_PHYA_3_0   0xF0    // 0001b/0001/x/x LEQ Offset Tuning Bandwidth Set
    #define CND003_PCIEPHYCFG_FRP02_EQTNWTBW_G3_PHYA_3_0   0xF     // 0001b/0001/x/x DFE Weight Tuning Bandwidth Set
#define CND003_PCIEPHYCFG_EQUALIZER_ADAPTIVE_EQTN_DC_HF_BANDWIDTH_LANE03_PHYA_G3 0x56A // Equalizer Adaptive EQTN DC/HF Bandwidth Lane03 PHYA G3
    #define CND003_PCIEPHYCFG_FRP03_EQTNDCBW_G3_PHYA_3_0   0xF000  // 0001b/0001/x/x LEQ DC Gain Tuning Bandwidth Set
    #define CND003_PCIEPHYCFG_FRP03_EQTNHFBW_G3_PHYA_3_0   0xF00   // 0001b/0001/x/x LEQ HF Gain Tuning Bandwidth Set
    #define CND003_PCIEPHYCFG_FRP03_EQTNOSBW_G3_PHYA_3_0   0xF0    // 0001b/0001/x/x LEQ Offset Tuning Bandwidth Set
    #define CND003_PCIEPHYCFG_FRP03_EQTNWTBW_G3_PHYA_3_0   0xF     // 0001b/0001/x/x DFE Weight Tuning Bandwidth Set
#define CND003_PCIEPHYCFG_EQUALIZER_ADAPTIVE_EQTN_DC_HF_BANDWIDTH_LANE00_PHYB_G3 0x56C // Equalizer Adaptive EQTN DC/HF Bandwidth Lane00 PHYB G3
    #define CND003_PCIEPHYCFG_FRP00_EQTNDCBW_G3_PHYB_3_0   0xF000  // 0001b/0001/x/x LEQ DC Gain Tuning Bandwidth Set
    #define CND003_PCIEPHYCFG_FRP00_EQTNHFBW_G3_PHYB_3_0   0xF00   // 0001b/0001/x/x LEQ HF Gain Tuning Bandwidth Set
    #define CND003_PCIEPHYCFG_FRP00_EQTNOSBW_G3_PHYB_3_0   0xF0    // 0001b/0001/x/x LEQ Offset Tuning Bandwidth Set
    #define CND003_PCIEPHYCFG_FRP00_EQTNWTBW_G3_PHYB_3_0   0xF     // 0001b/0001/x/x DFE Weight Tuning Bandwidth Set
#define CND003_PCIEPHYCFG_EQUALIZER_ADAPTIVE_EQTN_DC_HF_BANDWIDTH_LANE01_PHYB_G3 0x56E // Equalizer Adaptive EQTN DC/HF Bandwidth Lane01 PHYB G3
    #define CND003_PCIEPHYCFG_FRP01_EQTNDCBW_G3_PHYB_3_0   0xF000  // 0001b/0001/x/x LEQ DC Gain Tuning Bandwidth Set
    #define CND003_PCIEPHYCFG_FRP01_EQTNHFBW_G3_PHYB_3_0   0xF00   // 0001b/0001/x/x LEQ HF Gain Tuning Bandwidth Set
    #define CND003_PCIEPHYCFG_FRP01_EQTNOSBW_G3_PHYB_3_0   0xF0    // 0001b/0001/x/x LEQ Offset Tuning Bandwidth Set
    #define CND003_PCIEPHYCFG_FRP01_EQTNWTBW_G3_PHYB_3_0   0xF     // 0001b/0001/x/x DFE Weight Tuning Bandwidth Set
#define CND003_PCIEPHYCFG_EQUALIZER_ADAPTIVE_EQTN_DC_HF_BANDWIDTH_LANE02_PHYB_G3 0x570 // Equalizer Adaptive EQTN DC/HF Bandwidth Lane02 PHYB G3
    #define CND003_PCIEPHYCFG_FRP02_EQTNDCBW_G3_PHYB_3_0   0xF000  // 0001b/0001/x/x LEQ DC Gain Tuning Bandwidth Set
    #define CND003_PCIEPHYCFG_FRP02_EQTNHFBW_G3_PHYB_3_0   0xF00   // 0001b/0001/x/x LEQ HF Gain Tuning Bandwidth Set
    #define CND003_PCIEPHYCFG_FRP02_EQTNOSBW_G3_PHYB_3_0   0xF0    // 0001b/0001/x/x LEQ Offset Tuning Bandwidth Set
    #define CND003_PCIEPHYCFG_FRP02_EQTNWTBW_G3_PHYB_3_0   0xF     // 0001b/0001/x/x DFE Weight Tuning Bandwidth Set
#define CND003_PCIEPHYCFG_EQUALIZER_ADAPTIVE_EQTN_DC_HF_BANDWIDTH_LANE03_PHYB_G3 0x572 // Equalizer Adaptive EQTN DC/HF Bandwidth Lane03 PHYB G3
    #define CND003_PCIEPHYCFG_FRP03_EQTNDCBW_G3_PHYB_3_0   0xF000  // 0001b/0001/x/x LEQ DC Gain Tuning Bandwidth Set
    #define CND003_PCIEPHYCFG_FRP03_EQTNHFBW_G3_PHYB_3_0   0xF00   // 0001b/0001/x/x LEQ HF Gain Tuning Bandwidth Set
    #define CND003_PCIEPHYCFG_FRP03_EQTNOSBW_G3_PHYB_3_0   0xF0    // 0001b/0001/x/x LEQ Offset Tuning Bandwidth Set
    #define CND003_PCIEPHYCFG_FRP03_EQTNWTBW_G3_PHYB_3_0   0xF     // 0001b/0001/x/x DFE Weight Tuning Bandwidth Set
#define CND003_PCIEPHYCFG_EQUALIZER_ADAPTIVE_EQTN_DC_HF_BANDWIDTH_LANE00_EP_G3 0x574 // Equalizer Adaptive EQTN DC/HF Bandwidth Lane00 EP G3
    #define CND003_PCIEPHYCFG_FRP00_EQTNDCBW_G3_EP_3_0 0xF000  // 0001b/0001/x/x LEQ DC Gain Tuning Bandwidth Set
    #define CND003_PCIEPHYCFG_FRP00_EQTNHFBW_G3_EP_3_0 0xF00   // 0001b/0001/x/x LEQ HF Gain Tuning Bandwidth Set
    #define CND003_PCIEPHYCFG_FRP00_EQTNOSBW_G3_EP_3_0 0xF0    // 0001b/0001/x/x LEQ Offset Tuning Bandwidth Set
    #define CND003_PCIEPHYCFG_FRP00_EQTNWTBW_G3_EP_3_0 0xF     // 0001b/0001/x/x DFE Weight Tuning Bandwidth Set
#define CND003_PCIEPHYCFG_EQUALIZER_ADAPTIVE_EQTN_DC_HF_BANDWIDTH_LANE01_EP_G3 0x576 // Equalizer Adaptive EQTN DC/HF Bandwidth Lane01 EP G3
    #define CND003_PCIEPHYCFG_FRP01_EQTNDCBW_G3_EP_3_0 0xF000  // 0001b/0001/x/x LEQ DC Gain Tuning Bandwidth Set
    #define CND003_PCIEPHYCFG_FRP01_EQTNHFBW_G3_EP_3_0 0xF00   // 0001b/0001/x/x LEQ HF Gain Tuning Bandwidth Set
    #define CND003_PCIEPHYCFG_FRP01_EQTNOSBW_G3_EP_3_0 0xF0    // 0001b/0001/x/x LEQ Offset Tuning Bandwidth Set
    #define CND003_PCIEPHYCFG_FRP01_EQTNWTBW_G3_EP_3_0 0xF     // 0001b/0001/x/x DFE Weight Tuning Bandwidth Set
#define CND003_PCIEPHYCFG_EQUALIZER_ADAPTIVE_EQTN_DC_HF_BANDWIDTH_LANE02_EP_G3 0x578 // Equalizer Adaptive EQTN DC/HF Bandwidth Lane02 EP G3
    #define CND003_PCIEPHYCFG_FRP02_EQTNDCBW_G3_EP_3_0 0xF000  // 0001b/0001/x/x LEQ DC Gain Tuning Bandwidth Set
    #define CND003_PCIEPHYCFG_FRP02_EQTNHFBW_G3_EP_3_0 0xF00   // 0001b/0001/x/x LEQ HF Gain Tuning Bandwidth Set
    #define CND003_PCIEPHYCFG_FRP02_EQTNOSBW_G3_EP_3_0 0xF0    // 0001b/0001/x/x LEQ Offset Tuning Bandwidth Set
    #define CND003_PCIEPHYCFG_FRP02_EQTNWTBW_G3_EP_3_0 0xF     // 0001b/0001/x/x DFE Weight Tuning Bandwidth Set
#define CND003_PCIEPHYCFG_EQUALIZER_ADAPTIVE_EQTN_DC_HF_BANDWIDTH_LANE03_EP_G3 0x57A // Equalizer Adaptive EQTN DC/HF Bandwidth Lane03 EP G3
    #define CND003_PCIEPHYCFG_FRP03_EQTNDCBW_G3_EP_3_0 0xF000  // 0001b/0001/x/x LEQ DC Gain Tuning Bandwidth Set
    #define CND003_PCIEPHYCFG_FRP03_EQTNHFBW_G3_EP_3_0 0xF00   // 0001b/0001/x/x LEQ HF Gain Tuning Bandwidth Set
    #define CND003_PCIEPHYCFG_FRP03_EQTNOSBW_G3_EP_3_0 0xF0    // 0001b/0001/x/x LEQ Offset Tuning Bandwidth Set
    #define CND003_PCIEPHYCFG_FRP03_EQTNWTBW_G3_EP_3_0 0xF     // 0001b/0001/x/x DFE Weight Tuning Bandwidth Set
#define CND003_PCIEPHYCFG_EQUALIZER_ADAPTIVE_EQTN_DC_HF_BANDWIDTH_LANE00_PHYC_G3 0x57C // Equalizer Adaptive EQTN DC/HF Bandwidth Lane00 PHYC G3
    #define CND003_PCIEPHYCFG_FRP00_EQTNDCBW_PHYC_G3 PCIEPHYCFG_EQUALIZER_ADAPTIVE_EQTN_DC_HF_BANDWIDTH_LANE00_PHYC_G3 // 0/0/x/X Reserved
#define CND003_PCIEPHYCFG_EQUALIZER_ADAPTIVE_EQTN_DC_HF_BANDWIDTH_LANE01_PHYC_G3 0x57E // Equalizer Adaptive EQTN DC/HF Bandwidth Lane01 PHYC G3
    #define CND003_PCIEPHYCFG_FRP01_EQTNDCBW_PHYC_G3 PCIEPHYCFG_EQUALIZER_ADAPTIVE_EQTN_DC_HF_BANDWIDTH_LANE01_PHYC_G3 // 0/0/x/x Reserved
#define CND003_PCIEPHYCFG_RESERVED_Z29 0x580 // Reserved
    #define CND003_PCIEPHYCFG_RSVPCIEPHYCFG_580_7 PCIEPHYCFG_RESERVED_Z29 // 0/x/x/x Reserved
#define CND003_PCIEPHYCFG_RESERVED_Z30 0x581 // Reserved
    #define CND003_PCIEPHYCFG_RSVPCIEPHYCFG_581_7 PCIEPHYCFG_RESERVED_Z30 // 0/x/x/x Reserved
#define CND003_PCIEPHYCFG_EQUALIZER_ADAPTIVE_SETTING_DFE_LANE00_G1 0x600 // Equalizer Adaptive Setting DFE Lane00 G1
    #define CND003_PCIEPHYCFG_FRP00_EQTNDFE_G1 PCIEPHYCFG_EQUALIZER_ADAPTIVE_SETTING_DFE_LANE00_G1 // 0/0/x/x Reserved
#define CND003_PCIEPHYCFG_EQUALIZER_ADAPTIVE_SETTING_DFE_LANE04_PHYA_G1 0x601 // Equalizer Adaptive Setting DFE Lane04 PHYA G1
    #define CND003_PCIEPHYCFG_FRP04_EQTNDFE_G1_PHYA        (BIT6 + BIT7)           // 0/0/x/x DFE Weight Tuning Bandwidth Set
    #define CND003_PCIEPHYCFG_FRP04_EQTNALWY_G1_PHYA       BIT5                    // 0/0/x/x Equalizer Always Tuning Mode Enable
    #define CND003_PCIEPHYCFG_FRP04_EQTNSPDSWEN_G1_PHYA    BIT4                    // 0/0/x/x Enable Low Speed Mode after the First Tuning Finished
    #define CND003_PCIEPHYCFG_FRP04_EQTNVTH_G1_PHYA_2_0    (BIT1 + BIT2 + BIT3)    // 001b/001/x/x Equalizer Tuning Threshold Voltage
    #define CND003_PCIEPHYCFG_FRP04_EQTNDFETRN_G1_PHYA     BIT0                    // 1b/1/x/x Enable DFE in Training Mode
#define CND003_PCIEPHYCFG_EQUALIZER_ADAPTIVE_SETTING_DFE_LANE00_PHYA_G1 0x602 // Equalizer Adaptive Setting DFE Lane00 PHYA G1
    #define CND003_PCIEPHYCFG_FRP00_EQTNDFE_G1_PHYA        (BIT6 + BIT7)           // 0/0/x/x DFE Weight Tuning Bandwidth Set
    #define CND003_PCIEPHYCFG_FRP00_EQTNALWY_G1_PHYA       BIT5                    // 0/0/x/x Equalizer Always Tuning Mode Enable
    #define CND003_PCIEPHYCFG_FRP00_EQTNSPDSWEN_G1_PHYA    BIT4                    // 0/0/x/x Enable Low Speed Mode after the First Tuning Finished
    #define CND003_PCIEPHYCFG_FRP00_EQTNVTH_G1_PHYA_2_0    (BIT1 + BIT2 + BIT3)    // 001b/001/x/x Equalizer Tuning Threshold Voltage
    #define CND003_PCIEPHYCFG_FRP00_EQTNDFETRN_G1_PHYA     BIT0                    // 1b/1/x/x Enable DFE in Training Mode
#define CND003_PCIEPHYCFG_EQUALIZER_ADAPTIVE_SETTING_DFE_LANE01_PHYA_G1 0x603 // Equalizer Adaptive Setting DFE Lane01 PHYA G1
    #define CND003_PCIEPHYCFG_FRP01_EQTNDFE_G1_PHYA        (BIT6 + BIT7)           // 0/0/x/x DFE Weight Tuning Bandwidth Set
    #define CND003_PCIEPHYCFG_FRP01_EQTNALWY_G1_PHYA       BIT5                    // 0/0/x/x Equalizer Always Tuning Mode Enable
    #define CND003_PCIEPHYCFG_FRP01_EQTNSPDSWEN_G1_PHYA    BIT4                    // 0/0/x/x Enable Low Speed Mode after the First Tuning Finished
    #define CND003_PCIEPHYCFG_FRP01_EQTNVTH_G1_PHYA_2_0    (BIT1 + BIT2 + BIT3)    // 001b/001/x/x Equalizer Tuning Threshold Voltage
    #define CND003_PCIEPHYCFG_FRP01_EQTNDFETRN_G1_PHYA     BIT0                    // 1b/1/x/x Enable DFE in Training Mode
#define CND003_PCIEPHYCFG_EQUALIZER_ADAPTIVE_SETTING_DFE_LANE02_PHYA_G1 0x604 // Equalizer Adaptive Setting DFE Lane02 PHYA G1
    #define CND003_PCIEPHYCFG_FRP02_EQTNDFE_G1_PHYA        (BIT6 + BIT7)           // 0/0/x/x DFE Weight Tuning Bandwidth Set
    #define CND003_PCIEPHYCFG_FRP02_EQTNALWY_G1_PHYA       BIT5                    // 0/0/x/x Equalizer Always Tuning Mode Enable
    #define CND003_PCIEPHYCFG_FRP02_EQTNSPDSWEN_G1_PHYA    BIT4                    // 0/0/x/x Enable Low Speed Mode after the First Tuning Finished
    #define CND003_PCIEPHYCFG_FRP02_EQTNVTH_G1_PHYA_2_0    (BIT1 + BIT2 + BIT3)    // 001b/001/x/x Equalizer Tuning Threshold Voltage
    #define CND003_PCIEPHYCFG_FRP02_EQTNDFETRN_G1_PHYA     BIT0                    // 1b/1/x/x Enable DFE in Training Mode
#define CND003_PCIEPHYCFG_EQUALIZER_ADAPTIVE_SETTING_DFE_LANE03_PHYA_G1 0x605 // Equalizer Adaptive Setting DFE Lane03 PHYA G1
    #define CND003_PCIEPHYCFG_FRP03_EQTNDFE_G1_PHYA        (BIT6 + BIT7)           // 0/0/x/x DFE Weight Tuning Bandwidth Set
    #define CND003_PCIEPHYCFG_FRP03_EQTNALWY_G1_PHYA       BIT5                    // 0/0/x/x Equalizer Always Tuning Mode Enable
    #define CND003_PCIEPHYCFG_FRP03_EQTNSPDSWEN_G1_PHYA    BIT4                    // 0/0/x/x Enable Low Speed Mode after the First Tuning Finished
    #define CND003_PCIEPHYCFG_FRP03_EQTNVTH_G1_PHYA_2_0    (BIT1 + BIT2 + BIT3)    // 001b/001/x/x Equalizer Tuning Threshold Voltage
    #define CND003_PCIEPHYCFG_FRP03_EQTNDFETRN_G1_PHYA     BIT0                    // 1b/1/x/x Enable DFE in Training Mode
#define CND003_PCIEPHYCFG_EQUALIZER_ADAPTIVE_SETTING_DFE_LANE00_PHYB_G1 0x606 // Equalizer Adaptive Setting DFE Lane00 PHYB G1
    #define CND003_PCIEPHYCFG_FRP00_EQTNDFE_G1_PHYB        (BIT6 + BIT7)           // 0/0/x/x DFE Weight Tuning Bandwidth Set
    #define CND003_PCIEPHYCFG_FRP00_EQTNALWY_G1_PHYB       BIT5                    // 0/0/x/x Equalizer Always Tuning Mode Enable
    #define CND003_PCIEPHYCFG_FRP00_EQTNSPDSWEN_G1_PHYB    BIT4                    // 0/0/x/x Enable Low Speed Mode after the First Tuning Finished
    #define CND003_PCIEPHYCFG_FRP00_EQTNVTH_G1_PHYB_2_0    (BIT1 + BIT2 + BIT3)    // 001b/001/x/x Equalizer Tuning Threshold Voltage
    #define CND003_PCIEPHYCFG_FRP00_EQTNDFETRN_G1_PHYB     BIT0                    // 1b/1/x/x Enable DFE in Training Mode
#define CND003_PCIEPHYCFG_EQUALIZER_ADAPTIVE_SETTING_DFE_LANE01_PHYB_G1 0x607 // Equalizer Adaptive Setting DFE Lane01 PHYB G1
    #define CND003_PCIEPHYCFG_FRP01_EQTNDFE_G1_PHYB        (BIT6 + BIT7)           // 0/0/x/x DFE Weight Tuning Bandwidth Set
    #define CND003_PCIEPHYCFG_FRP01_EQTNALWY_G1_PHYB       BIT5                    // 0/0/x/x Equalizer Always Tuning Mode Enable
    #define CND003_PCIEPHYCFG_FRP01_EQTNSPDSWEN_G1_PHYB    BIT4                    // 0/0/x/x Enable Low Speed Mode after the First Tuning Finished
    #define CND003_PCIEPHYCFG_FRP01_EQTNVTH_G1_PHYB_2_0    (BIT1 + BIT2 + BIT3)    // 001b/001/x/x Equalizer Tuning Threshold Voltage
    #define CND003_PCIEPHYCFG_FRP01_EQTNDFETRN_G1_PHYB     BIT0                    // 1b/1/x/x Enable DFE in Training Mode
#define CND003_PCIEPHYCFG_EQUALIZER_ADAPTIVE_SETTING_DFE_LANE02_PHYB_G1 0x608 // Equalizer Adaptive Setting DFE Lane02 PHYB G1
    #define CND003_PCIEPHYCFG_FRP02_EQTNDFE_G1_PHYB        (BIT6 + BIT7)           // 0/0/x/x DFE Weight Tuning Bandwidth Set
    #define CND003_PCIEPHYCFG_FRP02_EQTNALWY_G1_PHYB       BIT5                    // 0/0/x/x Equalizer Always Tuning Mode Enable
    #define CND003_PCIEPHYCFG_FRP02_EQTNSPDSWEN_G1_PHYB    BIT4                    // 0/0/x/x Enable Low Speed Mode after the First Tuning Finished
    #define CND003_PCIEPHYCFG_FRP02_EQTNVTH_G1_PHYB_2_0    (BIT1 + BIT2 + BIT3)    // 001b/001/x/x Equalizer Tuning Threshold Voltage
    #define CND003_PCIEPHYCFG_FRP02_EQTNDFETRN_G1_PHYB     BIT0                    // 1b/1/x/x Enable DFE in Training Mode
#define CND003_PCIEPHYCFG_EQUALIZER_ADAPTIVE_SETTING_DFE_LANE03_PHYB_G1 0x609 // Equalizer Adaptive Setting DFE Lane03 PHYB G1
    #define CND003_PCIEPHYCFG_FRP03_EQTNDFE_G1_PHYB        (BIT6 + BIT7)           // 0/0/x/x DFE Weight Tuning Bandwidth Set
    #define CND003_PCIEPHYCFG_FRP03_EQTNALWY_G1_PHYB       BIT5                    // 0/0/x/x Equalizer Always Tuning Mode Enable
    #define CND003_PCIEPHYCFG_FRP03_EQTNSPDSWEN_G1_PHYB    BIT4                    // 0/0/x/x Enable Low Speed Mode after the First Tuning Finished
    #define CND003_PCIEPHYCFG_FRP03_EQTNVTH_G1_PHYB_2_0    (BIT1 + BIT2 + BIT3)    // 001b/001/x/x Equalizer Tuning Threshold Voltage
    #define CND003_PCIEPHYCFG_FRP03_EQTNDFETRN_G1_PHYB     BIT0                    // 1b/1/x/x Enable DFE in Training Mode
#define CND003_PCIEPHYCFG_EQUALIZER_ADAPTIVE_SETTING_DFE_LANE00_EP_G1 0x60A // Equalizer Adaptive Setting DFE Lane00 EP G1
    #define CND003_PCIEPHYCFG_FRP00_EQTNDFE_G1_EP      (BIT6 + BIT7)           // 0/0/x/x DFE Weight Tuning Bandwidth Set
    #define CND003_PCIEPHYCFG_FRP00_EQTNALWY_G1_EP     BIT5                    // 0/0/x/x Equalizer Always Tuning Mode Enable
    #define CND003_PCIEPHYCFG_FRP00_EQTNSPDSWEN_G1_EP  BIT4                    // 0/0/x/x Enable Low Speed Mode after the First Tuning Finished
    #define CND003_PCIEPHYCFG_FRP00_EQTNVTH_G1_EP_2_0  (BIT1 + BIT2 + BIT3)    // 001b/001/x/x Equalizer Tuning Threshold Voltage
    #define CND003_PCIEPHYCFG_FRP00_EQTNDFETRN_G1_EP   BIT0                    // 1b/1/x/x Enable DFE in Training Mode
#define CND003_PCIEPHYCFG_EQUALIZER_ADAPTIVE_SETTING_DFE_LANE01_EP_G1 0x60B // Equalizer Adaptive Setting DFE Lane01 EP G1
    #define CND003_PCIEPHYCFG_FRP01_EQTNDFE_G1_EP_1_0  (BIT6 + BIT7)           // 0/0/x/x DFE Weight Tuning Bandwidth Set
    #define CND003_PCIEPHYCFG_FRP01_EQTNALWY_G1_EP     BIT5                    // 0/0/x/x Equalizer Always Tuning Mode Enable
    #define CND003_PCIEPHYCFG_FRP01_EQTNSPDSWEN_G1_EP  BIT4                    // 0/0/x/x Enable Low Speed Mode after the First Tuning Finished
    #define CND003_PCIEPHYCFG_FRP01_EQTNVTH_G1_EP_2_0  (BIT1 + BIT2 + BIT3)    // 001b/001/x/x Equalizer Tuning Threshold Voltage
    #define CND003_PCIEPHYCFG_FRP01_EQTNDFETRN_G1_EP   BIT0                    // 1b/1/x/x Enable DFE in Training Mode
#define CND003_PCIEPHYCFG_EQUALIZER_ADAPTIVE_SETTING_DFE_LANE02_EP_G1 0x60C // Equalizer Adaptive Setting DFE Lane02 EP G1
    #define CND003_PCIEPHYCFG_FRP02_EQTNDFE_G1_EP_1_0  (BIT6 + BIT7)           // 0/0/x/x DFE Weight Tuning Bandwidth Set
    #define CND003_PCIEPHYCFG_FRP02_EQTNALWY_G1_EP     BIT5                    // 0/0/x/x Equalizer Always Tuning Mode Enable
    #define CND003_PCIEPHYCFG_FRP02_EQTNSPDSWEN_G1_EP  BIT4                    // 0/0/x/x Enable Low Speed Mode after the First Tuning Finished
    #define CND003_PCIEPHYCFG_FRP02_EQTNVTH_G1_EP_2_0  (BIT1 + BIT2 + BIT3)    // 001b/001/x/x Equalizer Tuning Threshold Voltage
    #define CND003_PCIEPHYCFG_FRP02_EQTNDFETRN_G1_EP   BIT0                    // 1b/1/x/x Enable DFE in Training Mode
#define CND003_PCIEPHYCFG_EQUALIZER_ADAPTIVE_SETTING_DFE_LANE03_EP_G1 0x60D // Equalizer Adaptive Setting DFE Lane03 EP G1
    #define CND003_PCIEPHYCFG_FRP03_EQTNDFE_G1_EP_1_0  (BIT6 + BIT7)           // 0/0/x/x DFE Weight Tuning Bandwidth Set
    #define CND003_PCIEPHYCFG_FRP03_EQTNALWY_G1_EP     BIT5                    // 0/0/x/x Equalizer Always Tuning Mode Enable
    #define CND003_PCIEPHYCFG_FRP03_EQTNSPDSWEN_G1_EP  BIT4                    // 0/0/x/x Enable Low Speed Mode after the First Tuning Finished
    #define CND003_PCIEPHYCFG_FRP03_EQTNVTH_G1_EP_2_0  (BIT1 + BIT2 + BIT3)    // 001b/001/x/x Equalizer Tuning Threshold Voltage
    #define CND003_PCIEPHYCFG_FRP03_EQTNDFETRN_G1_EP   BIT0                    // 1b/1/x/x Enable DFE in Training Mode
#define CND003_PCIEPHYCFG_EQUALIZER_ADAPTIVE_SETTING_DFE_LANE00_PHYC_G1 0x60E // Equalizer Adaptive Setting DFE Lane00 PHYC G1
    #define CND003_PCIEPHYCFG_FRP00_EQTNDFE_PHYC_G1 PCIEPHYCFG_EQUALIZER_ADAPTIVE_SETTING_DFE_LANE00_PHYC_G1 // 0/0/x/X Reserved
#define CND003_PCIEPHYCFG_EQUALIZER_ADAPTIVE_SETTING_DFE_LANE01_PHYC_G1 0x60F // Equalizer Adaptive Setting DFE Lane01 PHYC G1
    #define CND003_PCIEPHYCFG_FRP01_EQTNDFE_PHYC_G1 PCIEPHYCFG_EQUALIZER_ADAPTIVE_SETTING_DFE_LANE01_PHYC_G1 // 0/0/x/x Reserved
#define CND003_PCIEPHYCFG_RESERVED_Z31 0x610 // Reserved
    #define CND003_PCIEPHYCFG_RSVPCIEPHYCFG_610_7 PCIEPHYCFG_RESERVED_Z31 // 0/x/x/x Reserved
#define CND003_PCIEPHYCFG_EQUALIZER_ADAPTIVE_SETTING_DFE_LANE00_G2 0x620 // Equalizer Adaptive Setting DFE Lane00 G2
    #define CND003_PCIEPHYCFG_FRP00_EQTNDFE_G2 PCIEPHYCFG_EQUALIZER_ADAPTIVE_SETTING_DFE_LANE00_G2 // 0/0/x/X Reserved
#define CND003_PCIEPHYCFG_EQUALIZER_ADAPTIVE_SETTING_DFE_LANE04_PHYA_G2 0x621 // Equalizer Adaptive Setting DFE Lane04 PHYA G2
    #define CND003_PCIEPHYCFG_FRP04_EQTNDFE_G2_PHYA_1_0    (BIT6 + BIT7)           // 0/0/x/x DFE Weight Tuning Bandwidth Set
    #define CND003_PCIEPHYCFG_FRP04_EQTNALWY_G2_PHYA       BIT5                    // 0/0/x/x Equalizer Always Tuning Mode Enable
    #define CND003_PCIEPHYCFG_FRP04_EQTNSPDSWEN_G2_PHYA    BIT4                    // 0/0/x/x Enable Low Speed Mode after the First Tuning Finished
    #define CND003_PCIEPHYCFG_FRP04_EQTNVTH_G2_PHYA_2_0    (BIT1 + BIT2 + BIT3)    // 001b/001/x/x Equalizer Tuning Threshold Voltage
    #define CND003_PCIEPHYCFG_FRP04_EQTNDFETRN_G2_PHYA     BIT0                    // 1b/1/x/x Enable DFE in Training Mode
#define CND003_PCIEPHYCFG_EQUALIZER_ADAPTIVE_SETTING_DFE_LANE00_PHYA_G2 0x622 // Equalizer Adaptive Setting DFE Lane00 PHYA G2
    #define CND003_PCIEPHYCFG_FRP00_EQTNDFE_G2_PHYA_1_0    (BIT6 + BIT7)           // 0/0/x/x DFE Weight Tuning Bandwidth Set
    #define CND003_PCIEPHYCFG_FRP00_EQTNALWY_G2_PHYA       BIT5                    // 0/0/x/x Equalizer Always Tuning Mode Enable
    #define CND003_PCIEPHYCFG_FRP00_EQTNSPDSWEN_G2_PHYA    BIT4                    // 0/0/x/x Enable Low Speed Mode after the First Tuning Finished
    #define CND003_PCIEPHYCFG_FRP00_EQTNVTH_G2_PHYA_2_0    (BIT1 + BIT2 + BIT3)    // 001b/001/x/x Equalizer Tuning Threshold Voltage
    #define CND003_PCIEPHYCFG_FRP00_EQTNDFETRN_G2_PHYA     BIT0                    // 1b/1/x/x Enable DFE in Training Mode
#define CND003_PCIEPHYCFG_EQUALIZER_ADAPTIVE_SETTING_DFE_LANE01_PHYA_G2 0x623 // Equalizer Adaptive Setting DFE Lane01 PHYA G2
    #define CND003_PCIEPHYCFG_FRP01_EQTNDFE_G2_PHYA_1_0    (BIT6 + BIT7)           // 0/0/x/x DFE Weight Tuning Bandwidth Set
    #define CND003_PCIEPHYCFG_FRP01_EQTNALWY_G2_PHYA       BIT5                    // 0/0/x/x Equalizer Always Tuning Mode Enable
    #define CND003_PCIEPHYCFG_FRP01_EQTNSPDSWEN_G2_PHYA    BIT4                    // 0/0/x/x Enable Low Speed Mode after the First Tuning Finished
    #define CND003_PCIEPHYCFG_FRP01_EQTNVTH_G2_PHYA_2_0    (BIT1 + BIT2 + BIT3)    // 001b/001/x/x Equalizer Tuning Threshold Voltage
    #define CND003_PCIEPHYCFG_FRP01_EQTNDFETRN_G2_PHYA     BIT0                    // 1b/1/x/x Enable DFE in Training Mode
#define CND003_PCIEPHYCFG_EQUALIZER_ADAPTIVE_SETTING_DFE_LANE02_PHYA_G2 0x624 // Equalizer Adaptive Setting DFE Lane02 PHYA G2
    #define CND003_PCIEPHYCFG_FRP02_EQTNDFE_G2_PHYA_1_0    (BIT6 + BIT7)           // 0/0/x/x DFE Weight Tuning Bandwidth Set
    #define CND003_PCIEPHYCFG_FRP02_EQTNALWY_G2_PHYA       BIT5                    // 0/0/x/x Equalizer Always Tuning Mode Enable
    #define CND003_PCIEPHYCFG_FRP02_EQTNSPDSWEN_G2_PHYA    BIT4                    // 0/0/x/x Enable Low Speed Mode after the First Tuning Finished
    #define CND003_PCIEPHYCFG_FRP02_EQTNVTH_G2_PHYA_2_0    (BIT1 + BIT2 + BIT3)    // 001b/001/x/x Equalizer Tuning Threshold Voltage
    #define CND003_PCIEPHYCFG_FRP02_EQTNDFETRN_G2_PHYA     BIT0                    // 1b/1/x/x Enable DFE in Training Mode
#define CND003_PCIEPHYCFG_EQUALIZER_ADAPTIVE_SETTING_DFE_LANE03_PHYA_G2 0x625 // Equalizer Adaptive Setting DFE Lane03 PHYA G2
    #define CND003_PCIEPHYCFG_FRP03_EQTNDFE_G2_PHYA_1_0    (BIT6 + BIT7)           // 0/0/x/x DFE Weight Tuning Bandwidth Set
    #define CND003_PCIEPHYCFG_FRP03_EQTNALWY_G2_PHYA       BIT5                    // 0/0/x/x Equalizer Always Tuning Mode Enable
    #define CND003_PCIEPHYCFG_FRP03_EQTNSPDSWEN_G2_PHYA    BIT4                    // 0/0/x/x Enable Low Speed Mode after the First Tuning Finished
    #define CND003_PCIEPHYCFG_FRP03_EQTNVTH_G2_PHYA_2_0    (BIT1 + BIT2 + BIT3)    // 001b/001/x/x Equalizer Tuning Threshold Voltage
    #define CND003_PCIEPHYCFG_FRP03_EQTNDFETRN_G2_PHYA     BIT0                    // 1b/1/x/x Enable DFE in Training Mode
#define CND003_PCIEPHYCFG_EQUALIZER_ADAPTIVE_SETTING_DFE_LANE00_PHYB_G2 0x626 // Equalizer Adaptive Setting DFE Lane00 PHYB G2
    #define CND003_PCIEPHYCFG_FRP00_EQTNDFE_G2_PHYB_1_0    (BIT6 + BIT7)           // 0/0/x/x DFE Weight Tuning Bandwidth Set
    #define CND003_PCIEPHYCFG_FRP00_EQTNALWY_G2_PHYB       BIT5                    // 0/0/x/x Equalizer Always Tuning Mode Enable
    #define CND003_PCIEPHYCFG_FRP00_EQTNSPDSWEN_G2_PHYB    BIT4                    // 0/0/x/x Enable Low Speed Mode after the First Tuning Finished
    #define CND003_PCIEPHYCFG_FRP00_EQTNVTH_G2_PHYB_2_0    (BIT1 + BIT2 + BIT3)    // 001b/001/x/x Equalizer Tuning Threshold Voltage
    #define CND003_PCIEPHYCFG_FRP00_EQTNDFETRN_G2_PHYB     BIT0                    // 1b/1/x/x Enable DFE in Training Mode
#define CND003_PCIEPHYCFG_EQUALIZER_ADAPTIVE_SETTING_DFE_LANE01_PHYB_G2 0x627 // Equalizer Adaptive Setting DFE Lane01 PHYB G2
    #define CND003_PCIEPHYCFG_FRP01_EQTNDFE_G2_PHYB_1_0    (BIT6 + BIT7)           // 0/0/x/x DFE Weight Tuning Bandwidth Set
    #define CND003_PCIEPHYCFG_FRP01_EQTNALWY_G2_PHYB       BIT5                    // 0/0/x/x Equalizer Always Tuning Mode Enable
    #define CND003_PCIEPHYCFG_FRP01_EQTNSPDSWEN_G2_PHYB    BIT4                    // 0/0/x/x Enable Low Speed Mode after the First Tuning Finished
    #define CND003_PCIEPHYCFG_FRP01_EQTNVTH_G2_PHYB_2_0    (BIT1 + BIT2 + BIT3)    // 001b/001/x/x Equalizer Tuning Threshold Voltage
    #define CND003_PCIEPHYCFG_FRP01_EQTNDFETRN_G2_PHYB     BIT0                    // 1b/1/x/x Enable DFE in Training Mode
#define CND003_PCIEPHYCFG_EQUALIZER_ADAPTIVE_SETTING_DFE_LANE02_PHYB_G2 0x628 // Equalizer Adaptive Setting DFE Lane02 PHYB G2
    #define CND003_PCIEPHYCFG_FRP02_EQTNDFE_G2_PHYB_1_0    (BIT6 + BIT7)           // 0/0/x/x DFE Weight Tuning Bandwidth Set
    #define CND003_PCIEPHYCFG_FRP02_EQTNALWY_G2_PHYB       BIT5                    // 0/0/x/x Equalizer Always Tuning Mode Enable
    #define CND003_PCIEPHYCFG_FRP02_EQTNSPDSWEN_G2_PHYB    BIT4                    // 0/0/x/x Enable Low Speed Mode after the First Tuning Finished
    #define CND003_PCIEPHYCFG_FRP02_EQTNVTH_G2_PHYB_2_0    (BIT1 + BIT2 + BIT3)    // 001b/001/x/x Equalizer Tuning Threshold Voltage
    #define CND003_PCIEPHYCFG_FRP02_EQTNDFETRN_G2_PHYB     BIT0                    // 1b/1/x/x Enable DFE in Training Mode
#define CND003_PCIEPHYCFG_EQUALIZER_ADAPTIVE_SETTING_DFE_LANE03_PHYB_G2 0x629 // Equalizer Adaptive Setting DFE Lane03 PHYB G2
    #define CND003_PCIEPHYCFG_FRP03_EQTNDFE_G2_PHYB_1_0    (BIT6 + BIT7)           // 0/0/x/x DFE Weight Tuning Bandwidth Set
    #define CND003_PCIEPHYCFG_FRP03_EQTNALWY_G2_PHYB       BIT5                    // 0/0/x/x Equalizer Always Tuning Mode Enable
    #define CND003_PCIEPHYCFG_FRP03_EQTNSPDSWEN_G2_PHYB    BIT4                    // 0/0/x/x Enable Low Speed Mode after the First Tuning Finished
    #define CND003_PCIEPHYCFG_FRP03_EQTNVTH_G2_PHYB_2_0    (BIT1 + BIT2 + BIT3)    // 001b/001/x/x Equalizer Tuning Threshold Voltage
    #define CND003_PCIEPHYCFG_FRP03_EQTNDFETRN_G2_PHYB     BIT0                    // 1b/1/x/x Enable DFE in Training Mode
#define CND003_PCIEPHYCFG_EQUALIZER_ADAPTIVE_SETTING_DFE_LANE00_EP_G2 0x62A // Equalizer Adaptive Setting DFE Lane00 EP G2
    #define CND003_PCIEPHYCFG_FRP00_EQTNDFE_G2_EP_1_0  (BIT6 + BIT7)           // 0/0/x/x DFE Weight Tuning Bandwidth Set
    #define CND003_PCIEPHYCFG_FRP00_EQTNALWY_G2_EP     BIT5                    // 0/0/x/x Equalizer Always Tuning Mode Enable
    #define CND003_PCIEPHYCFG_FRP00_EQTNSPDSWEN_G2_EP  BIT4                    // 0/0/x/x Enable Low Speed Mode after the First Tuning Finished
    #define CND003_PCIEPHYCFG_FRP00_EQTNVTH_G2_EP_2_0  (BIT1 + BIT2 + BIT3)    // 001b/001/x/x Equalizer Tuning Threshold Voltage
    #define CND003_PCIEPHYCFG_FRP00_EQTNDFETRN_G2_EP   BIT0                    // 1b/1/x/x Enable DFE in Training Mode
#define CND003_PCIEPHYCFG_EQUALIZER_ADAPTIVE_SETTING_DFE_LANE01_EP_G2 0x62B // Equalizer Adaptive Setting DFE Lane01 EP G2
    #define CND003_PCIEPHYCFG_FRP01_EQTNDFE_G2_EP_1_0  (BIT6 + BIT7)           // 0/0/x/x DFE Weight Tuning Bandwidth Set
    #define CND003_PCIEPHYCFG_FRP01_EQTNALWY_G2_EP     BIT5                    // 0/0/x/x Equalizer Always Tuning Mode Enable
    #define CND003_PCIEPHYCFG_FRP01_EQTNSPDSWEN_G2_EP  BIT4                    // 0/0/x/x Enable Low Speed Mode after the First Tuning Finished
    #define CND003_PCIEPHYCFG_FRP01_EQTNVTH_G2_EP_2_0  (BIT1 + BIT2 + BIT3)    // 001b/001/x/x Equalizer Tuning Threshold Voltage
    #define CND003_PCIEPHYCFG_FRP01_EQTNDFETRN_G2_EP   BIT0                    // 1b/1/x/x Enable DFE in Training Mode
#define CND003_PCIEPHYCFG_EQUALIZER_ADAPTIVE_SETTING_DFE_LANE02_EP_G2 0x62C // Equalizer Adaptive Setting DFE Lane02 EP G2
    #define CND003_PCIEPHYCFG_FRP02_EQTNDFE_G2_EP_1_0  (BIT6 + BIT7)           // 0/0/x/x DFE Weight Tuning Bandwidth Set
    #define CND003_PCIEPHYCFG_FRP02_EQTNALWY_G2_EP     BIT5                    // 0/0/x/x Equalizer Always Tuning Mode Enable
    #define CND003_PCIEPHYCFG_FRP02_EQTNSPDSWEN_G2_EP  BIT4                    // 0/0/x/x Enable Low Speed Mode after the First Tuning Finished
    #define CND003_PCIEPHYCFG_FRP02_EQTNVTH_G2_EP_2_0  (BIT1 + BIT2 + BIT3)    // 001b/001/x/x Equalizer Tuning Threshold Voltage
    #define CND003_PCIEPHYCFG_FRP02_EQTNDFETRN_G2_EP   BIT0                    // 1b/1/x/x Enable DFE in Training Mode
#define CND003_PCIEPHYCFG_EQUALIZER_ADAPTIVE_SETTING_DFE_LANE03_EP_G2 0x62D // Equalizer Adaptive Setting DFE Lane03 EP G2
    #define CND003_PCIEPHYCFG_FRP03_EQTNDFE_G2_EP_1_0  (BIT6 + BIT7)           // 0/0/x/x DFE Weight Tuning Bandwidth Set
    #define CND003_PCIEPHYCFG_FRP03_EQTNALWY_G2_EP     BIT5                    // 0/0/x/x Equalizer Always Tuning Mode Enable
    #define CND003_PCIEPHYCFG_FRP03_EQTNSPDSWEN_G2_EP  BIT4                    // 0/0/x/x Enable Low Speed Mode after the First Tuning Finished
    #define CND003_PCIEPHYCFG_FRP03_EQTNVTH_G2_EP_2_0  (BIT1 + BIT2 + BIT3)    // 001b/001/x/x Equalizer Tuning Threshold Voltage
    #define CND003_PCIEPHYCFG_FRP03_EQTNDFETRN_G2_EP   BIT0                    // 1b/1/x/x Enable DFE in Training Mode
#define CND003_PCIEPHYCFG_EQUALIZER_ADAPTIVE_SETTING_DFE_LANE00_PHYC_G2 0x62E // Equalizer Adaptive Setting DFE Lane00 PHYC G2
    #define CND003_PCIEPHYCFG_FRP00_EQTNDFE_PHYC_G2 PCIEPHYCFG_EQUALIZER_ADAPTIVE_SETTING_DFE_LANE00_PHYC_G2 // 0/0/x/X Reserved
#define CND003_PCIEPHYCFG_EQUALIZER_ADAPTIVE_SETTING_DFE_LANE01_PHYC_G2 0x62F // Equalizer Adaptive Setting DFE Lane01 PHYC G2
    #define CND003_PCIEPHYCFG_FRP01_EQTNDFE_PHYC_G2 PCIEPHYCFG_EQUALIZER_ADAPTIVE_SETTING_DFE_LANE01_PHYC_G2 // 0/0/x/x Reserved
#define CND003_PCIEPHYCFG_RESERVED_Z32 0x630 // Reserved
    #define CND003_PCIEPHYCFG_RSVPCIEPHYCFG_633_7 PCIEPHYCFG_RESERVED_Z32 // 0/x/x/x Reserved
#define CND003_PCIEPHYCFG_EQUALIZER_ADAPTIVE_SETTING_DFE_LANE00_G3 0x640 // Equalizer Adaptive Setting DFE Lane00 G3
    #define CND003_PCIEPHYCFG_FRP00_EQTNDFE_G3 PCIEPHYCFG_EQUALIZER_ADAPTIVE_SETTING_DFE_LANE00_G3 // 0/0/x/X Reserved
#define CND003_PCIEPHYCFG_EQUALIZER_ADAPTIVE_SETTING_DFE_LANE04_PHYA_G3 0x641 // Equalizer Adaptive Setting DFE Lane04 PHYA G3
    #define CND003_PCIEPHYCFG_FRP04_EQTNDFE_G3_PHYA_1_0    (BIT6 + BIT7)           // 10b/10/x/x DFE Weight Tuning Bandwidth Set
    #define CND003_PCIEPHYCFG_FRP04_EQTNALWY_G3_PHYA       BIT5                    // 0/0/x/x Equalizer Always Tuning Mode Enable
    #define CND003_PCIEPHYCFG_FRP04_EQTNSPDSWEN_G3_PHYA    BIT4                    // 0/0/x/x Enable Low Speed Mode after the First Tuning Finished
    #define CND003_PCIEPHYCFG_FRP04_EQTNVTH_G3_PHYA_2_0    (BIT1 + BIT2 + BIT3)    // 001b/001/x/x Equalizer Tuning Threshold Voltage
    #define CND003_PCIEPHYCFG_FRP04_EQTNDFETRN_G3_PHYA     BIT0                    // 1b/1/x/x Enable DFE in Training Mode
#define CND003_PCIEPHYCFG_EQUALIZER_ADAPTIVE_SETTING_DFE_LANE00_PHYA_G3 0x642 // Equalizer Adaptive Setting DFE Lane00 PHYA G3
    #define CND003_PCIEPHYCFG_FRP00_EQTNDFE_G3_PHYA_1_0    (BIT6 + BIT7)           // 10b/10/x/x DFE Weight Tuning Bandwidth Set
    #define CND003_PCIEPHYCFG_FRP00_EQTNALWY_G3_PHYA       BIT5                    // 0/0/x/x Equalizer Always Tuning Mode Enable
    #define CND003_PCIEPHYCFG_FRP00_EQTNSPDSWEN_G3_PHYA    BIT4                    // 0/0/x/x Enable Low Speed Mode after the First Tuning Finished
    #define CND003_PCIEPHYCFG_FRP00_EQTNVTH_G3_PHYA_2_0    (BIT1 + BIT2 + BIT3)    // 001b/001/x/x Equalizer Tuning Threshold Voltage
    #define CND003_PCIEPHYCFG_FRP00_EQTNDFETRN_G3_PHYA     BIT0                    // 1b/1/x/x Enable DFE in Training Mode
#define CND003_PCIEPHYCFG_EQUALIZER_ADAPTIVE_SETTING_DFE_LANE01_PHYA_G3 0x643 // Equalizer Adaptive Setting DFE Lane01 PHYA G3
    #define CND003_PCIEPHYCFG_FRP01_EQTNDFE_G3_PHYA_1_0    (BIT6 + BIT7)           // 10b/10/x/x DFE Weight Tuning Bandwidth Set
    #define CND003_PCIEPHYCFG_FRP01_EQTNALWY_G3_PHYA       BIT5                    // 0/0/x/x Equalizer Always Tuning Mode Enable
    #define CND003_PCIEPHYCFG_FRP01_EQTNSPDSWEN_G3_PHYA    BIT4                    // 0/0/x/x Enable Low Speed Mode after the First Tuning Finished
    #define CND003_PCIEPHYCFG_FRP01_EQTNVTH_G3_PHYA_2_0    (BIT1 + BIT2 + BIT3)    // 001b/001/x/x Equalizer Tuning Threshold Voltage
    #define CND003_PCIEPHYCFG_FRP01_EQTNDFETRN_G3_PHYA     BIT0                    // 1b/1/x/x Enable DFE in Training Mode
#define CND003_PCIEPHYCFG_EQUALIZER_ADAPTIVE_SETTING_DFE_LANE02_PHYA_G3 0x644 // Equalizer Adaptive Setting DFE Lane02 PHYA G3
    #define CND003_PCIEPHYCFG_FRP02_EQTNDFE_G3_PHYA_1_0    (BIT6 + BIT7)           // 10b/10/x/x DFE Weight Tuning Bandwidth Set
    #define CND003_PCIEPHYCFG_FRP02_EQTNALWY_G3_PHYA       BIT5                    // 0/0/x/x Equalizer Always Tuning Mode Enable
    #define CND003_PCIEPHYCFG_FRP02_EQTNSPDSWEN_G3_PHYA    BIT4                    // 0/0/x/x Enable Low Speed Mode after the First Tuning Finished
    #define CND003_PCIEPHYCFG_FRP02_EQTNVTH_G3_PHYA_2_0    (BIT1 + BIT2 + BIT3)    // 001b/001/x/x Equalizer Tuning Threshold Voltage
    #define CND003_PCIEPHYCFG_FRP02_EQTNDFETRN_G3_PHYA     BIT0                    // 1b/1/x/x Enable DFE in Training Mode
#define CND003_PCIEPHYCFG_EQUALIZER_ADAPTIVE_SETTING_DFE_LANE03_PHYA_G3 0x645 // Equalizer Adaptive Setting DFE Lane03 PHYA G3
    #define CND003_PCIEPHYCFG_FRP03_EQTNDFE_G3_PHYA_1_0    (BIT6 + BIT7)           // 10b/10/x/x DFE Weight Tuning Bandwidth Set
    #define CND003_PCIEPHYCFG_FRP03_EQTNALWY_G3_PHYA       BIT5                    // 0/0/x/x Equalizer Always Tuning Mode Enable
    #define CND003_PCIEPHYCFG_FRP03_EQTNSPDSWEN_G3_PHYA    BIT4                    // 0/0/x/x Enable Low Speed Mode after the First Tuning Finished
    #define CND003_PCIEPHYCFG_FRP03_EQTNVTH_G3_PHYA_2_0    (BIT1 + BIT2 + BIT3)    // 001b/001/x/x Equalizer Tuning Threshold Voltage
    #define CND003_PCIEPHYCFG_FRP03_EQTNDFETRN_G3_PHYA     BIT0                    // 1b/1/x/x Enable DFE in Training Mode
#define CND003_PCIEPHYCFG_EQUALIZER_ADAPTIVE_SETTING_DFE_LANE00_PHYB_G3 0x646 // Equalizer Adaptive Setting DFE Lane00 PHYB G3
    #define CND003_PCIEPHYCFG_FRP00_EQTNDFE_G3_PHYB_1_0    (BIT6 + BIT7)           // 10b/10/x/x DFE Weight Tuning Bandwidth Set
    #define CND003_PCIEPHYCFG_FRP00_EQTNALWY_G3_PHYB       BIT5                    // 0/0/x/x Equalizer Always Tuning Mode Enable
    #define CND003_PCIEPHYCFG_FRP00_EQTNSPDSWEN_G3_PHYB    BIT4                    // 0/0/x/x Enable Low Speed Mode after the First Tuning Finished
    #define CND003_PCIEPHYCFG_FRP00_EQTNVTH_G3_PHYB_2_0    (BIT1 + BIT2 + BIT3)    // 001b/001/x/x Equalizer Tuning Threshold Voltage
    #define CND003_PCIEPHYCFG_FRP00_EQTNDFETRN_G3_PHYB     BIT0                    // 1b/1/x/x Enable DFE in Training Mode
#define CND003_PCIEPHYCFG_EQUALIZER_ADAPTIVE_SETTING_DFE_LANE01_PHYB_G3 0x647 // Equalizer Adaptive Setting DFE Lane01 PHYB G3
    #define CND003_PCIEPHYCFG_FRP01_EQTNDFE_G3_PHYB_1_0    (BIT6 + BIT7)           // 10b/10/x/x DFE Weight Tuning Bandwidth Set
    #define CND003_PCIEPHYCFG_FRP01_EQTNALWY_G3_PHYB       BIT5                    // 0/0/x/x Equalizer Always Tuning Mode Enable
    #define CND003_PCIEPHYCFG_FRP01_EQTNSPDSWEN_G3_PHYB    BIT4                    // 0/0/x/x Enable Low Speed Mode after the First Tuning Finished
    #define CND003_PCIEPHYCFG_FRP01_EQTNVTH_G3_PHYB_2_0    (BIT1 + BIT2 + BIT3)    // 001b/001/x/x Equalizer Tuning Threshold Voltage
    #define CND003_PCIEPHYCFG_FRP01_EQTNDFETRN_G3_PHYB     BIT0                    // 1b/1/x/x Enable DFE in Training Mode
#define CND003_PCIEPHYCFG_EQUALIZER_ADAPTIVE_SETTING_DFE_LANE02_PHYB_G3 0x648 // Equalizer Adaptive Setting DFE Lane02 PHYB G3
    #define CND003_PCIEPHYCFG_FRP02_EQTNDFE_G3_PHYB_1_0    (BIT6 + BIT7)           // 10b/10/x/x DFE Weight Tuning Bandwidth Set
    #define CND003_PCIEPHYCFG_FRP02_EQTNALWY_G3_PHYB       BIT5                    // 0/0/x/x Equalizer Always Tuning Mode Enable
    #define CND003_PCIEPHYCFG_FRP02_EQTNSPDSWEN_G3_PHYB    BIT4                    // 0/0/x/x Enable Low Speed Mode after the First Tuning Finished
    #define CND003_PCIEPHYCFG_FRP02_EQTNVTH_G3_PHYB_2_0    (BIT1 + BIT2 + BIT3)    // 001b/001/x/x Equalizer Tuning Threshold Voltage
    #define CND003_PCIEPHYCFG_FRP02_EQTNDFETRN_G3_PHYB     BIT0                    // 1b/1/x/x Enable DFE in Training Mode
#define CND003_PCIEPHYCFG_EQUALIZER_ADAPTIVE_SETTING_DFE_LANE03_PHYB_G3 0x649 // Equalizer Adaptive Setting DFE Lane03 PHYB G3
    #define CND003_PCIEPHYCFG_FRP03_EQTNDFE_G3_PHYB_1_0    (BIT6 + BIT7)           // 10b/10/x/x DFE Weight Tuning Bandwidth Set
    #define CND003_PCIEPHYCFG_FRP03_EQTNALWY_G3_PHYB       BIT5                    // 0/0/x/x Equalizer Always Tuning Mode Enable
    #define CND003_PCIEPHYCFG_FRP03_EQTNSPDSWEN_G3_PHYB    BIT4                    // 0/0/x/x Enable Low Speed Mode after the First Tuning Finished
    #define CND003_PCIEPHYCFG_FRP03_EQTNVTH_G3_PHYB_2_0    (BIT1 + BIT2 + BIT3)    // 001b/001/x/x Equalizer Tuning Threshold Voltage
    #define CND003_PCIEPHYCFG_FRP03_EQTNDFETRN_G3_PHYB     BIT0                    // 1b/1/x/x Enable DFE in Training Mode
#define CND003_PCIEPHYCFG_EQUALIZER_ADAPTIVE_SETTING_DFE_LANE00_EP_G3 0x64A // Equalizer Adaptive Setting DFE Lane00 EP G3
    #define CND003_PCIEPHYCFG_FRP00_EQTNDFE_G3_EP_1_0  (BIT6 + BIT7)           // 10b/10/x/x DFE Weight Tuning Bandwidth Set
    #define CND003_PCIEPHYCFG_FRP00_EQTNALWY_G3_EP     BIT5                    // 0/0/x/x Equalizer Always Tuning Mode Enable
    #define CND003_PCIEPHYCFG_FRP00_EQTNSPDSWEN_G3_EP  BIT4                    // 0/0/x/x Enable Low Speed Mode after the First Tuning Finished
    #define CND003_PCIEPHYCFG_FRP00_EQTNVTH_G3_EP_2_0  (BIT1 + BIT2 + BIT3)    // 001b/001/x/x Equalizer Tuning Threshold Voltage
    #define CND003_PCIEPHYCFG_FRP00_EQTNDFETRN_G3_EP   BIT0                    // 1b/1/x/x Enable DFE in Training Mode
#define CND003_PCIEPHYCFG_EQUALIZER_ADAPTIVE_SETTING_DFE_LANE01_EP_G3 0x64B // Equalizer Adaptive Setting DFE Lane01 EP G3
    #define CND003_PCIEPHYCFG_FRP01_EQTNDFE_G3_EP_1_0  (BIT6 + BIT7)           // 10b/10/x/x DFE Weight Tuning Bandwidth Set
    #define CND003_PCIEPHYCFG_FRP01_EQTNALWY_G3_EP     BIT5                    // 0/0/x/x Equalizer Always Tuning Mode Enable
    #define CND003_PCIEPHYCFG_FRP01_EQTNSPDSWEN_G3_EP  BIT4                    // 0/0/x/x Enable Low Speed Mode after the First Tuning Finished
    #define CND003_PCIEPHYCFG_FRP01_EQTNVTH_G3_EP_2_0  (BIT1 + BIT2 + BIT3)    // 001b/001/x/x Equalizer Tuning Threshold Voltage
    #define CND003_PCIEPHYCFG_FRP01_EQTNDFETRN_G3_EP   BIT0                    // 1b/1/x/x Enable DFE in Training Mode
#define CND003_PCIEPHYCFG_EQUALIZER_ADAPTIVE_SETTING_DFE_LANE02_EP_G3 0x64C // Equalizer Adaptive Setting DFE Lane02 EP G3
    #define CND003_PCIEPHYCFG_FRP02_EQTNDFE_G3_EP_1_0  (BIT6 + BIT7)           // 10b/10/x/x DFE Weight Tuning Bandwidth Set
    #define CND003_PCIEPHYCFG_FRP02_EQTNALWY_G3_EP     BIT5                    // 0/0/x/x Equalizer Always Tuning Mode Enable
    #define CND003_PCIEPHYCFG_FRP02_EQTNSPDSWEN_G3_EP  BIT4                    // 0/0/x/x Enable Low Speed Mode after the First Tuning Finished
    #define CND003_PCIEPHYCFG_FRP02_EQTNVTH_G3_EP_2_0  (BIT1 + BIT2 + BIT3)    // 001b/001/x/x Equalizer Tuning Threshold Voltage
    #define CND003_PCIEPHYCFG_FRP02_EQTNDFETRN_G3_EP   BIT0                    // 1b/1/x/x Enable DFE in Training Mode
#define CND003_PCIEPHYCFG_EQUALIZER_ADAPTIVE_SETTING_DFE_LANE03_EP_G3 0x64D // Equalizer Adaptive Setting DFE Lane03 EP G3
    #define CND003_PCIEPHYCFG_FRP03_EQTNDFE_G3_EP_1_0  (BIT6 + BIT7)           // 10b/10/x/x DFE Weight Tuning Bandwidth Set
    #define CND003_PCIEPHYCFG_FRP03_EQTNALWY_G3_EP     BIT5                    // 0/0/x/x Equalizer Always Tuning Mode Enable
    #define CND003_PCIEPHYCFG_FRP03_EQTNSPDSWEN_G3_EP  BIT4                    // 0/0/x/x Enable Low Speed Mode after the First Tuning Finished
    #define CND003_PCIEPHYCFG_FRP03_EQTNVTH_G3_EP_2_0  (BIT1 + BIT2 + BIT3)    // 001b/001/x/x Equalizer Tuning Threshold Voltage
    #define CND003_PCIEPHYCFG_FRP03_EQTNDFETRN_G3_EP   BIT0                    // 1b/1/x/x Enable DFE in Training Mode
#define CND003_PCIEPHYCFG_EQUALIZER_ADAPTIVE_SETTING_DFE_LANE00_EP00_PHYC_G3 0x64E // Equalizer Adaptive Setting DFE Lane00 EP00 PHYC G3
    #define CND003_PCIEPHYCFG_FRP00_EQTNDFE_PHYC_G3 PCIEPHYCFG_EQUALIZER_ADAPTIVE_SETTING_DFE_LANE00_EP00_PHYC_G3 // 0/0/x/X Reserved
#define CND003_PCIEPHYCFG_EQUALIZER_ADAPTIVE_SETTING_DFE_LANE01_PHYC_G3 0x64F // Equalizer Adaptive Setting DFE Lane01 PHYC G3
    #define CND003_PCIEPHYCFG_FRP01_EQTNDFE_PHYC_G3 PCIEPHYCFG_EQUALIZER_ADAPTIVE_SETTING_DFE_LANE01_PHYC_G3 // 0/0/x/x Reserved
#define CND003_PCIEPHYCFG_RESERVED_Z33 0x650 // Reserved
    #define CND003_PCIEPHYCFG_RSVPCIEPHYCFG_650_7 PCIEPHYCFG_RESERVED_Z33 // 0/x/x/x Reserved
#define CND003_PCIEPHYCFG_EQUALIZER_ADAPTIVE_SETTING_DCSET_LANE00_G1 0x680 // Equalizer Adaptive Setting DCSET Lane00 G1
    #define CND003_PCIEPHYCFG_RSVPCIEPHYCFG_680_7 PCIEPHYCFG_EQUALIZER_ADAPTIVE_SETTING_DCSET_LANE00_G1 // 0/x/x/X Reserved
#define CND003_PCIEPHYCFG_EQUALIZER_ADAPTIVE_SETTING_DCSET_LANE04_PHYA_G1 0x681 // Equalizer Adaptive Setting DCSET Lane04 PHYA G1
    #define CND003_PCIEPHYCFG_RSVPCIEPHYCFG_681_7      (BIT6 + BIT7)   // 0/x/x/x Reserved
    #define CND003_PCIEPHYCFG_FRP04_DCSET_G1_PHYA_4_0  0x3E            // 00001b/00001/x/x Equalizer Tuning Threshold Voltage
    #define CND003_PCIEPHYCFG_FRP04_DCSETEN_G1_PHYA    BIT0            // 0/0/x/x LEQ DC Gain Manual Set Enable
#define CND003_PCIEPHYCFG_EQUALIZER_ADAPTIVE_SETTING_DCSET_LANE00_PHYA_G1 0x682 // Equalizer Adaptive Setting DCSET Lane00 PHYA G1
    #define CND003_PCIEPHYCFG_RSVPCIEPHYCFG_682_7      (BIT6 + BIT7)   // 0/x/x/x Reserved
    #define CND003_PCIEPHYCFG_FRP00_DCSET_G1_PHYA_4_0  0x3E            // 00001b/00001/x/x Equalizer Tuning Threshold Voltage
    #define CND003_PCIEPHYCFG_FRP00_DCSETEN_G1_PHYA    BIT0            // 0/0/x/x LEQ DC Gain Manual Set Enable
#define CND003_PCIEPHYCFG_EQUALIZER_ADAPTIVE_SETTING_DCSET_LANE01_PHYA_G1 0x683 // Equalizer Adaptive Setting DCSET Lane01 PHYA G1
    #define CND003_PCIEPHYCFG_RSVPCIEPHYCFG_683_7      (BIT6 + BIT7)   // 0/x/x/x Reserved
    #define CND003_PCIEPHYCFG_FRP01_DCSET_G1_PHYA_4_0  0x3E            // 00001b/00001/x/x Equalizer Tuning Threshold Voltage
    #define CND003_PCIEPHYCFG_FRP01_DCSETEN_G1_PHYA    BIT0            // 0/0/x/x LEQ DC Gain Manual Set Enable
#define CND003_PCIEPHYCFG_EQUALIZER_ADAPTIVE_SETTING_DCSET_LANE02_PHYA_G1 0x684 // Equalizer Adaptive Setting DCSET Lane02 PHYA G1
    #define CND003_PCIEPHYCFG_RSVPCIEPHYCFG_684_7      (BIT6 + BIT7)   // 0/x/x/x Reserved
    #define CND003_PCIEPHYCFG_FRP02_DCSET_G1_PHYA_4_0  0x3E            // 00001b/00001/x/x Equalizer Tuning Threshold Voltage
    #define CND003_PCIEPHYCFG_FRP02_DCSETEN_G1_PHYA    BIT0            // 0/0/x/x LEQ DC Gain Manual Set Enable
#define CND003_PCIEPHYCFG_EQUALIZER_ADAPTIVE_SETTING_DCSET_LANE03_PHYA_G1 0x685 // Equalizer Adaptive Setting DCSET Lane03 PHYA G1
    #define CND003_PCIEPHYCFG_RSVPCIEPHYCFG_685_7      (BIT6 + BIT7)   // 0/x/x/x Reserved
    #define CND003_PCIEPHYCFG_FRP03_DCSET_G1_PHYA_4_0  0x3E            // 00001b/00001/x/x Equalizer Tuning Threshold Voltage
    #define CND003_PCIEPHYCFG_FRP03_DCSETEN_G1_PHYA    BIT0            // 0/0/x/x LEQ DC Gain Manual Set Enable
#define CND003_PCIEPHYCFG_EQUALIZER_ADAPTIVE_SETTING_DCSET_LANE00_PHYB_G1 0x686 // Equalizer Adaptive Setting DCSET Lane00 PHYB G1
    #define CND003_PCIEPHYCFG_RSVPCIEPHYCFG_686_7      (BIT6 + BIT7)   // 0/x/x/x Reserved
    #define CND003_PCIEPHYCFG_FRP00_DCSET_G1_PHYB_4_0  0x3E            // 00001b/00001/x/x Equalizer Tuning Threshold Voltage
    #define CND003_PCIEPHYCFG_FRP00_DCSETEN_G1_PHYB    BIT0            // 0/0/x/x LEQ DC Gain Manual Set Enable
#define CND003_PCIEPHYCFG_EQUALIZER_ADAPTIVE_SETTING_DCSET_LANE01_PHYB_G1 0x687 // Equalizer Adaptive Setting DCSET Lane01 PHYB G1
    #define CND003_PCIEPHYCFG_RSVPCIEPHYCFG_687_7      (BIT6 + BIT7)   // 0/x/x/x Reserved
    #define CND003_PCIEPHYCFG_FRP01_DCSET_G1_PHYB_4_0  0x3E            // 00001b/00001/x/x Equalizer Tuning Threshold Voltage
    #define CND003_PCIEPHYCFG_FRP01_DCSETEN_G1_PHYB    BIT0            // 0/0/x/x LEQ DC Gain Manual Set Enable
#define CND003_PCIEPHYCFG_EQUALIZER_ADAPTIVE_SETTING_DCSET_LANE02_PHYB_G1 0x688 // Equalizer Adaptive Setting DCSET Lane02 PHYB G1
    #define CND003_PCIEPHYCFG_RSVPCIEPHYCFG_688_7      (BIT6 + BIT7)   // 0/x/x/x Reserved
    #define CND003_PCIEPHYCFG_FRP02_DCSET_G1_PHYB_4_0  0x3E            // 00001b/00001/x/x Equalizer Tuning Threshold Voltage
    #define CND003_PCIEPHYCFG_FRP02_DCSETEN_G1_PHYB    BIT0            // 0/0/x/x LEQ DC Gain Manual Set Enable
#define CND003_PCIEPHYCFG_EQUALIZER_ADAPTIVE_SETTING_DCSET_LANE03_PHYB_G1 0x689 // Equalizer Adaptive Setting DCSET Lane03 PHYB G1
    #define CND003_PCIEPHYCFG_RSVPCIEPHYCFG_689_7      (BIT6 + BIT7)   // 0/x/x/x Reserved
    #define CND003_PCIEPHYCFG_FRP03_DCSET_G1_PHYB_4_0  0x3E            // 00001b/00001/x/x Equalizer Tuning Threshold Voltage
    #define CND003_PCIEPHYCFG_FRP03_DCSETEN_G1_PHYB    BIT0            // 0/0/x/x LEQ DC Gain Manual Set Enable
#define CND003_PCIEPHYCFG_EQUALIZER_ADAPTIVE_SETTING_DCSET_LANE00_EP_G1 0x68A // Equalizer Adaptive Setting DCSET Lane00 EP G1
    #define CND003_PCIEPHYCFG_RSVPCIEPHYCFG_68A_7      (BIT6 + BIT7)   // 0/x/x/x Reserved
    #define CND003_PCIEPHYCFG_FRP00_DCSET_G1_EP_4_0    0x3E            // 00001b/00001/x/x Equalizer Tuning Threshold Voltage
    #define CND003_PCIEPHYCFG_FRP00_DCSETEN_G1_EP      BIT0            // 0/0/x/x LEQ DC Gain Manual Set Enable
#define CND003_PCIEPHYCFG_EQUALIZER_ADAPTIVE_SETTING_DCSET_LANE01_EP_G1 0x68B // Equalizer Adaptive Setting DCSET Lane01 EP G1
    #define CND003_PCIEPHYCFG_RSVPCIEPHYCFG_68B_7      (BIT6 + BIT7)   // 0/x/x/x Reserved
    #define CND003_PCIEPHYCFG_FRP01_DCSET_G1_EP_4_0    0x3E            // 00001b/00001/x/x Equalizer Tuning Threshold Voltage
    #define CND003_PCIEPHYCFG_FRP01_DCSETEN_G1_EP      BIT0            // 0/0/x/x LEQ DC Gain Manual Set Enable
#define CND003_PCIEPHYCFG_EQUALIZER_ADAPTIVE_SETTING_DCSET_LANE02_EP_G1 0x68C // Equalizer Adaptive Setting DCSET Lane02 EP G1
    #define CND003_PCIEPHYCFG_RSVPCIEPHYCFG_68C_7      (BIT6 + BIT7)   // 0/x/x/x Reserved
    #define CND003_PCIEPHYCFG_FRP02_DCSET_G1_EP_4_0    0x3E            // 00001b/00001/x/x Equalizer Tuning Threshold Voltage
    #define CND003_PCIEPHYCFG_FRP02_DCSETEN_G1_EP      BIT0            // 0/0/x/x LEQ DC Gain Manual Set Enable
#define CND003_PCIEPHYCFG_EQUALIZER_ADAPTIVE_SETTING_DCSET_LANE03_EP_G1 0x68D // Equalizer Adaptive Setting DCSET Lane03 EP G1
    #define CND003_PCIEPHYCFG_RSVPCIEPHYCFG_68D_7      (BIT6 + BIT7)   // 0/x/x/x Reserved
    #define CND003_PCIEPHYCFG_FRP03_DCSET_G1_EP_4_0    0x3E            // 00001b/00001/x/x Equalizer Tuning Threshold Voltage
    #define CND003_PCIEPHYCFG_FRP03_DCSETEN_G1_EP      BIT0            // 0/0/x/x LEQ DC Gain Manual Set Enable
#define CND003_PCIEPHYCFG_EQUALIZER_ADAPTIVE_SETTING_DCSET_LANE00_PHYC_G1 0x68E // Equalizer Adaptive Setting DCSET Lane00 PHYC G1
    #define CND003_PCIEPHYCFG_RSVPCIEPHYCFG_68E_7 PCIEPHYCFG_EQUALIZER_ADAPTIVE_SETTING_DCSET_LANE00_PHYC_G1 // 0/x/x/X Reserved
#define CND003_PCIEPHYCFG_EQUALIZER_ADAPTIVE_SETTING_DCSET_LANE01_PHYC_G1 0x68F // Equalizer Adaptive Setting DCSET Lane01 PHYC G1
    #define CND003_PCIEPHYCFG_RSVPCIEPHYCFG_68F_7 PCIEPHYCFG_EQUALIZER_ADAPTIVE_SETTING_DCSET_LANE01_PHYC_G1 // 0/x/x/x Reserved
#define CND003_PCIEPHYCFG_RESERVED_Z34 0x690 // Reserved
    #define CND003_PCIEPHYCFG_RSVPCIEPHYCFG_690_7 PCIEPHYCFG_RESERVED_Z34 // 0/x/x/x Reserved
#define CND003_PCIEPHYCFG_EQUALIZER_ADAPTIVE_SETTING_DCSET_LANE00_G2 0x6A0 // Equalizer Adaptive Setting DCSET Lane00 G2
    #define CND003_PCIEPHYCFG_RSVPCIEPHYCFG_6A0_7 PCIEPHYCFG_EQUALIZER_ADAPTIVE_SETTING_DCSET_LANE00_G2 // 0/x/x/X Reserved
#define CND003_PCIEPHYCFG_EQUALIZER_ADAPTIVE_SETTING_DCSET_LANE04_PHYA_G2 0x6A1 // Equalizer Adaptive Setting DCSET Lane04 PHYA G2
    #define CND003_PCIEPHYCFG_RSVPCIEPHYCFG_6A1_7      (BIT6 + BIT7)   // 0/x/x/x Reserved
    #define CND003_PCIEPHYCFG_FRP04_DCSET_G2_PHYA_4_0  0x3E            // 00001b/00001/x/x Equalizer Tuning Threshold Voltage
    #define CND003_PCIEPHYCFG_FRP04_DCSETEN_G2_PHYA    BIT0            // 0/0/x/x LEQ DC Gain Manual Set Enable
#define CND003_PCIEPHYCFG_EQUALIZER_ADAPTIVE_SETTING_DCSET_LANE00_PHYA_G2 0x6A2 // Equalizer Adaptive Setting DCSET Lane00 PHYA G2
    #define CND003_PCIEPHYCFG_RSVPCIEPHYCFG_6A2_7      (BIT6 + BIT7)   // 0/x/x/x Reserved
    #define CND003_PCIEPHYCFG_FRP00_DCSET_G2_PHYA_4_0  0x3E            // 00001b/00001/x/x Equalizer Tuning Threshold Voltage
    #define CND003_PCIEPHYCFG_FRP00_DCSETEN_G2_PHYA    BIT0            // 0/0/x/x LEQ DC Gain Manual Set Enable
#define CND003_PCIEPHYCFG_EQUALIZER_ADAPTIVE_SETTING_DCSET_LANE01_PHYA_G2 0x6A3 // Equalizer Adaptive Setting DCSET Lane01 PHYA G2
    #define CND003_PCIEPHYCFG_RSVPCIEPHYCFG_6A3_7      (BIT6 + BIT7)   // 0/x/x/x Reserved
    #define CND003_PCIEPHYCFG_FRP01_DCSET_G2_PHYA_4_0  0x3E            // 00001b/00001/x/x Equalizer Tuning Threshold Voltage
    #define CND003_PCIEPHYCFG_FRP01_DCSETEN_G2_PHYA    BIT0            // 0/0/x/x LEQ DC Gain Manual Set Enable
#define CND003_PCIEPHYCFG_EQUALIZER_ADAPTIVE_SETTING_DCSET_LANE02_PHYA_G2 0x6A4 // Equalizer Adaptive Setting DCSET Lane02 PHYA G2
    #define CND003_PCIEPHYCFG_RSVPCIEPHYCFG_6A4_7      (BIT6 + BIT7)   // 0/x/x/x Reserved
    #define CND003_PCIEPHYCFG_FRP02_DCSET_G2_PHYA_4_0  0x3E            // 00001b/00001/x/x Equalizer Tuning Threshold Voltage
    #define CND003_PCIEPHYCFG_FRP02_DCSETEN_G2_PHYA    BIT0            // 0/0/x/x LEQ DC Gain Manual Set Enable
#define CND003_PCIEPHYCFG_EQUALIZER_ADAPTIVE_SETTING_DCSET_LANE03_PHYA_G2 0x6A5 // Equalizer Adaptive Setting DCSET Lane03 PHYA G2
    #define CND003_PCIEPHYCFG_RSVPCIEPHYCFG_6A5_7      (BIT6 + BIT7)   // 0/x/x/x Reserved
    #define CND003_PCIEPHYCFG_FRP03_DCSET_G2_PHYA_4_0  0x3E            // 00001b/00001/x/x Equalizer Tuning Threshold Voltage
    #define CND003_PCIEPHYCFG_FRP03_DCSETEN_G2_PHYA    BIT0            // 0/0/x/x LEQ DC Gain Manual Set Enable
#define CND003_PCIEPHYCFG_EQUALIZER_ADAPTIVE_SETTING_DCSET_LANE00_PHYB_G2 0x6A6 // Equalizer Adaptive Setting DCSET Lane00 PHYB G2
    #define CND003_PCIEPHYCFG_RSVPCIEPHYCFG_6A6_7      (BIT6 + BIT7)   // 0/x/x/x Reserved
    #define CND003_PCIEPHYCFG_FRP00_DCSET_G2_PHYB_4_0  0x3E            // 00001b/00001/x/x Equalizer Tuning Threshold Voltage
    #define CND003_PCIEPHYCFG_FRP00_DCSETEN_G2_PHYB    BIT0            // 0/0/x/x LEQ DC Gain Manual Set Enable
#define CND003_PCIEPHYCFG_EQUALIZER_ADAPTIVE_SETTING_DCSET_LANE01_PHYB_G2 0x6A7 // Equalizer Adaptive Setting DCSET Lane01 PHYB G2
    #define CND003_PCIEPHYCFG_RSVPCIEPHYCFG_6A7_7      (BIT6 + BIT7)   // 0/x/x/x Reserved
    #define CND003_PCIEPHYCFG_FRP01_DCSET_G2_PHYB_4_0  0x3E            // 00001b/00001/x/x Equalizer Tuning Threshold Voltage
    #define CND003_PCIEPHYCFG_FRP01_DCSETEN_G2_PHYB    BIT0            // 0/0/x/x LEQ DC Gain Manual Set Enable
#define CND003_PCIEPHYCFG_EQUALIZER_ADAPTIVE_SETTING_DCSET_LANE02_PHYB_G2 0x6A8 // Equalizer Adaptive Setting DCSET Lane02 PHYB G2
    #define CND003_PCIEPHYCFG_RSVPCIEPHYCFG_6A8_7      (BIT6 + BIT7)   // 0/x/x/x Reserved
    #define CND003_PCIEPHYCFG_FRP02_DCSET_G2_PHYB_4_0  0x3E            // 00001b/00001/x/x Equalizer Tuning Threshold Voltage
    #define CND003_PCIEPHYCFG_FRP02_DCSETEN_G2_PHYB    BIT0            // 0/0/x/x LEQ DC Gain Manual Set Enable
#define CND003_PCIEPHYCFG_EQUALIZER_ADAPTIVE_SETTING_DCSET_LANE03_PHYB_G2 0x6A9 // Equalizer Adaptive Setting DCSET Lane03 PHYB G2
    #define CND003_PCIEPHYCFG_RSVPCIEPHYCFG_6A9_7      (BIT6 + BIT7)   // 0/x/x/x Reserved
    #define CND003_PCIEPHYCFG_FRP03_DCSET_G2_PHYB_4_0  0x3E            // 00001b/00001/x/x Equalizer Tuning Threshold Voltage
    #define CND003_PCIEPHYCFG_FRP03_DCSETEN_G2_PHYB    BIT0            // 0/0/x/x LEQ DC Gain Manual Set Enable
#define CND003_PCIEPHYCFG_EQUALIZER_ADAPTIVE_SETTING_DCSET_LANE00_EP_G2 0x6AA // Equalizer Adaptive Setting DCSET Lane00 EP G2
    #define CND003_PCIEPHYCFG_RSVPCIEPHYCFG_6AA_7      (BIT6 + BIT7)   // 0/x/x/x Reserved
    #define CND003_PCIEPHYCFG_FRP00_DCSET_G2_EP_4_0    0x3E            // 00001b/00001/x/x Equalizer Tuning Threshold Voltage
    #define CND003_PCIEPHYCFG_FRP00_DCSETEN_G2_EP      BIT0            // 0/0/x/x LEQ DC Gain Manual Set Enable
#define CND003_PCIEPHYCFG_EQUALIZER_ADAPTIVE_SETTING_DCSET_LANE01_EP_G2 0x6AB // Equalizer Adaptive Setting DCSET Lane01 EP G2
    #define CND003_PCIEPHYCFG_RSVPCIEPHYCFG_6AB_7      (BIT6 + BIT7)   // 0/x/x/x Reserved
    #define CND003_PCIEPHYCFG_FRP01_DCSET_G2_EP_4_0    0x3E            // 00001b/00001/x/x Equalizer Tuning Threshold Voltage
    #define CND003_PCIEPHYCFG_FRP01_DCSETEN_G2_EP      BIT0            // 0/0/x/x LEQ DC Gain Manual Set Enable
#define CND003_PCIEPHYCFG_EQUALIZER_ADAPTIVE_SETTING_DCSET_LANE02_EP_G2 0x6AC // Equalizer Adaptive Setting DCSET Lane02 EP G2
    #define CND003_PCIEPHYCFG_RSVPCIEPHYCFG_6AC_7      (BIT6 + BIT7)   // 0/x/x/x Reserved
    #define CND003_PCIEPHYCFG_FRP02_DCSET_G2_EP_4_0    0x3E            // 00001b/00001/x/x Equalizer Tuning Threshold Voltage
    #define CND003_PCIEPHYCFG_FRP02_DCSETEN_G2_EP      BIT0            // 0/0/x/x LEQ DC Gain Manual Set Enable
#define CND003_PCIEPHYCFG_EQUALIZER_ADAPTIVE_SETTING_DCSET_LANE03_EP_G2 0x6AD // Equalizer Adaptive Setting DCSET Lane03 EP G2
    #define CND003_PCIEPHYCFG_RSVPCIEPHYCFG_6AD_7      (BIT6 + BIT7)   // 0/x/x/x Reserved
    #define CND003_PCIEPHYCFG_FRP03_DCSET_G2_EP_4_0    0x3E            // 00001b/00001/x/x Equalizer Tuning Threshold Voltage
    #define CND003_PCIEPHYCFG_FRP03_DCSETEN_G2_EP      BIT0            // 0/0/x/x LEQ DC Gain Manual Set Enable
#define CND003_PCIEPHYCFG_EQUALIZER_ADAPTIVE_SETTING_DCSET_LANE00_PHYC_G2 0x6AE // Equalizer Adaptive Setting DCSET Lane00 PHYC G2
    #define CND003_PCIEPHYCFG_RSVPCIEPHYCFG_6AE_7 PCIEPHYCFG_EQUALIZER_ADAPTIVE_SETTING_DCSET_LANE00_PHYC_G2 // 0/x/x/X Reserved
#define CND003_PCIEPHYCFG_EQUALIZER_ADAPTIVE_SETTING_DCSET_LANE01_PHYC_G2 0x6AF // Equalizer Adaptive Setting DCSET Lane01 PHYC G2
    #define CND003_PCIEPHYCFG_RSVPCIEPHYCFG_6AF_7 PCIEPHYCFG_EQUALIZER_ADAPTIVE_SETTING_DCSET_LANE01_PHYC_G2 // 0/x/x/x Reserved
#define CND003_PCIEPHYCFG_RESERVED_Z35 0x6B0 // Reserved
    #define CND003_PCIEPHYCFG_RSVPCIEPHYCFG_6B0_7 PCIEPHYCFG_RESERVED_Z35 // 0/x/x/x Reserved
#define CND003_PCIEPHYCFG_EQUALIZER_ADAPTIVE_SETTING_DCSET_LANE00_G3 0x6C0 // Equalizer Adaptive Setting DCSET Lane00 G3
    #define CND003_PCIEPHYCFG_RSVPCIEPHYCFG_6C0_7 PCIEPHYCFG_EQUALIZER_ADAPTIVE_SETTING_DCSET_LANE00_G3 // 0/x/x/X Reserved
#define CND003_PCIEPHYCFG_EQUALIZER_ADAPTIVE_SETTING_DCSET_LANE04_PHYA_G3 0x6C1 // Equalizer Adaptive Setting DCSET Lane04 PHYA G3
    #define CND003_PCIEPHYCFG_RSVPCIEPHYCFG_6C1_7      (BIT6 + BIT7)   // 0/x/x/x Reserved
    #define CND003_PCIEPHYCFG_FRP04_DCSET_G3_PHYA_4_0  0x3E            // 00001b/00001/x/x Equalizer Tuning Threshold Voltage
    #define CND003_PCIEPHYCFG_FRP04_DCSETEN_G3_PHYA    BIT0            // 0/0/x/x LEQ DC Gain Manual Set Enable
#define CND003_PCIEPHYCFG_EQUALIZER_ADAPTIVE_SETTING_DCSET_LANE00_PHYA_G3 0x6C2 // Equalizer Adaptive Setting DCSET Lane00 PHYA G3
    #define CND003_PCIEPHYCFG_RSVPCIEPHYCFG_6C2_7      (BIT6 + BIT7)   // 0/x/x/x Reserved
    #define CND003_PCIEPHYCFG_FRP00_DCSET_G3_PHYA_4_0  0x3E            // 00001b/00001/x/x Equalizer Tuning Threshold Voltage
    #define CND003_PCIEPHYCFG_FRP00_DCSETEN_G3_PHYA    BIT0            // 0/0/x/x LEQ DC Gain Manual Set Enable
#define CND003_PCIEPHYCFG_EQUALIZER_ADAPTIVE_SETTING_DCSET_LANE01_PHYA_G3 0x6C3 // Equalizer Adaptive Setting DCSET Lane01 PHYA G3
    #define CND003_PCIEPHYCFG_RSVPCIEPHYCFG_6C3_7      (BIT6 + BIT7)   // 0/x/x/x Reserved
    #define CND003_PCIEPHYCFG_FRP01_DCSET_G3_PHYA_4_0  0x3E            // 00001b/00001/x/x Equalizer Tuning Threshold Voltage
    #define CND003_PCIEPHYCFG_FRP01_DCSETEN_G3_PHYA    BIT0            // 0/0/x/x LEQ DC Gain Manual Set Enable
#define CND003_PCIEPHYCFG_EQUALIZER_ADAPTIVE_SETTING_DCSET_LANE02_PHYA_G3 0x6C4 // Equalizer Adaptive Setting DCSET Lane02 PHYA G3
    #define CND003_PCIEPHYCFG_RSVPCIEPHYCFG_6C4_7      (BIT6 + BIT7)   // 0/x/x/x Reserved
    #define CND003_PCIEPHYCFG_FRP02_DCSET_G3_PHYA_4_0  0x3E            // 00001b/00001/x/x Equalizer Tuning Threshold Voltage
    #define CND003_PCIEPHYCFG_FRP02_DCSETEN_G3_PHYA    BIT0            // 0/0/x/x LEQ DC Gain Manual Set Enable
#define CND003_PCIEPHYCFG_EQUALIZER_ADAPTIVE_SETTING_DCSET_LANE03_PHYA_G3 0x6C5 // Equalizer Adaptive Setting DCSET Lane03 PHYA G3
    #define CND003_PCIEPHYCFG_RSVPCIEPHYCFG_6C5_7      (BIT6 + BIT7)   // 0/x/x/x Reserved
    #define CND003_PCIEPHYCFG_FRP03_DCSET_G3_PHYA_4_0  0x3E            // 00001b/00001/x/x Equalizer Tuning Threshold Voltage
    #define CND003_PCIEPHYCFG_FRP03_DCSETEN_G3_PHYA    BIT0            // 0/0/x/x LEQ DC Gain Manual Set Enable
#define CND003_PCIEPHYCFG_EQUALIZER_ADAPTIVE_SETTING_DCSET_LANE00_PHYB_G3 0x6C6 // Equalizer Adaptive Setting DCSET Lane00 PHYB G3
    #define CND003_PCIEPHYCFG_RSVPCIEPHYCFG_6C6_7      (BIT6 + BIT7)   // 0/x/x/x Reserved
    #define CND003_PCIEPHYCFG_FRP00_DCSET_G3_PHYB_4_0  0x3E            // 00001b/00001/x/x Equalizer Tuning Threshold Voltage
    #define CND003_PCIEPHYCFG_FRP00_DCSETEN_G3_PHYB    BIT0            // 0/0/x/x LEQ DC Gain Manual Set Enable
#define CND003_PCIEPHYCFG_EQUALIZER_ADAPTIVE_SETTING_DCSET_LANE01_PHYB_G3 0x6C7 // Equalizer Adaptive Setting DCSET Lane01 PHYB G3
    #define CND003_PCIEPHYCFG_RSVPCIEPHYCFG_6C7_7      (BIT6 + BIT7)   // 0/x/x/x Reserved
    #define CND003_PCIEPHYCFG_FRP01_DCSET_G3_PHYB_4_0  0x3E            // 00001b/00001/x/x Equalizer Tuning Threshold Voltage
    #define CND003_PCIEPHYCFG_FRP01_DCSETEN_G3_PHYB    BIT0            // 0/0/x/x LEQ DC Gain Manual Set Enable
#define CND003_PCIEPHYCFG_EQUALIZER_ADAPTIVE_SETTING_DCSET_LANE02_PHYB_G3 0x6C8 // Equalizer Adaptive Setting DCSET Lane02 PHYB G3
    #define CND003_PCIEPHYCFG_RSVPCIEPHYCFG_6C8_7      (BIT6 + BIT7)   // 0/x/x/x Reserved
    #define CND003_PCIEPHYCFG_FRP02_DCSET_G3_PHYB_4_0  0x3E            // 00001b/00001/x/x Equalizer Tuning Threshold Voltage
    #define CND003_PCIEPHYCFG_FRP02_DCSETEN_G3_PHYB    BIT0            // 0/0/x/x LEQ DC Gain Manual Set Enable
#define CND003_PCIEPHYCFG_EQUALIZER_ADAPTIVE_SETTING_DCSET_LANE03_PHYB_G3 0x6C9 // Equalizer Adaptive Setting DCSET Lane03 PHYB G3
    #define CND003_PCIEPHYCFG_RSVPCIEPHYCFG_6C9_7      (BIT6 + BIT7)   // 0/x/x/x Reserved
    #define CND003_PCIEPHYCFG_FRP03_DCSET_G3_PHYB_4_0  0x3E            // 00001b/00001/x/x Equalizer Tuning Threshold Voltage
    #define CND003_PCIEPHYCFG_FRP03_DCSETEN_G3_PHYB    BIT0            // 0/0/x/x LEQ DC Gain Manual Set Enable
#define CND003_PCIEPHYCFG_EQUALIZER_ADAPTIVE_SETTING_DCSET_LANE00_EP_G3 0x6CA // Equalizer Adaptive Setting DCSET Lane00 EP G3
    #define CND003_PCIEPHYCFG_RSVPCIEPHYCFG_6CA_7      (BIT6 + BIT7)   // 0/x/x/x Reserved
    #define CND003_PCIEPHYCFG_FRP00_DCSET_G3_EP_4_0    0x3E            // 00001b/00001/x/x Equalizer Tuning Threshold Voltage
    #define CND003_PCIEPHYCFG_FRP00_DCSETEN_G3_EP      BIT0            // 0/0/x/x LEQ DC Gain Manual Set Enable
#define CND003_PCIEPHYCFG_EQUALIZER_ADAPTIVE_SETTING_DCSET_LANE01_EP_G3 0x6CB // Equalizer Adaptive Setting DCSET Lane01 EP G3
    #define CND003_PCIEPHYCFG_RSVPCIEPHYCFG_6CB_7      (BIT6 + BIT7)   // 0/x/x/x Reserved
    #define CND003_PCIEPHYCFG_FRP01_DCSET_G3_EP_4_0    0x3E            // 00001b/00001/x/x Equalizer Tuning Threshold Voltage
    #define CND003_PCIEPHYCFG_FRP01_DCSETEN_G3_EP      BIT0            // 0/0/x/x LEQ DC Gain Manual Set Enable
#define CND003_PCIEPHYCFG_EQUALIZER_ADAPTIVE_SETTING_DCSET_LANE02_EP_G3 0x6CC // Equalizer Adaptive Setting DCSET Lane02 EP G3
    #define CND003_PCIEPHYCFG_RSVPCIEPHYCFG_6CC_7      (BIT6 + BIT7)   // 0/x/x/x Reserved
    #define CND003_PCIEPHYCFG_FRP02_DCSET_G3_EP_4_0    0x3E            // 00001b/00001/x/x Equalizer Tuning Threshold Voltage
    #define CND003_PCIEPHYCFG_FRP02_DCSETEN_G3_EP      BIT0            // 0/0/x/x LEQ DC Gain Manual Set Enable
#define CND003_PCIEPHYCFG_EQUALIZER_ADAPTIVE_SETTING_DCSET_LANE03_EP_G3 0x6CD // Equalizer Adaptive Setting DCSET Lane03 EP G3
    #define CND003_PCIEPHYCFG_RSVPCIEPHYCFG_6CD_7      (BIT6 + BIT7)   // 0/x/x/x Reserved
    #define CND003_PCIEPHYCFG_FRP03_DCSET_G3_EP_4_0    0x3E            // 00001b/00001/x/x Equalizer Tuning Threshold Voltage
    #define CND003_PCIEPHYCFG_FRP03_DCSETEN_G3_EP      BIT0            // 0/0/x/x LEQ DC Gain Manual Set Enable
#define CND003_PCIEPHYCFG_EQUALIZER_ADAPTIVE_SETTING_DCSET_LANE00_PHYC_G3 0x6CE // Equalizer Adaptive Setting DCSET Lane00 PHYC G3
    #define CND003_PCIEPHYCFG_RSVPCIEPHYCFG_6CE_7 PCIEPHYCFG_EQUALIZER_ADAPTIVE_SETTING_DCSET_LANE00_PHYC_G3 // 0/x/x/X Reserved
#define CND003_PCIEPHYCFG_EQUALIZER_ADAPTIVE_SETTING_DCSET_LANE01_PHYC_G3 0x6CF // Equalizer Adaptive Setting DCSET Lane01 PHYC G3
    #define CND003_PCIEPHYCFG_RSVPCIEPHYCFG_6CF_7 PCIEPHYCFG_EQUALIZER_ADAPTIVE_SETTING_DCSET_LANE01_PHYC_G3 // 0/x/x/x Reserved
#define CND003_PCIEPHYCFG_RESERVED_Z36 0x6D0 // Reserved
    #define CND003_PCIEPHYCFG_RSVPCIEPHYCFG_6D0_7 PCIEPHYCFG_RESERVED_Z36 // 0/x/x/x Reserved
#define CND003_PCIEPHYCFG_EQUALIZER_ADAPTIVE_HFSET_LANE00_G1 0x700 // Equalizer Adaptive HFSET Lane00 G1
    #define CND003_PCIEPHYCFG_RSVPCIEPHYCFG_700_7 PCIEPHYCFG_EQUALIZER_ADAPTIVE_HFSET_LANE00_G1 // 0/x/x/X Reserved
#define CND003_PCIEPHYCFG_EQUALIZER_ADAPTIVE_HFSET_LANE04_PHYA_G1 0x701 // Equalizer Adaptive HFSET Lane04 PHYA G1
    #define CND003_PCIEPHYCFG_RSVPCIEPHYCFG_701_7      (BIT6 + BIT7)   // 0/x/x/x Reserved
    #define CND003_PCIEPHYCFG_FRP04_HFSET_G1_PHYA_4_0  0x3E            // 00001b/00001/x/x LEQ HF Gain Initial or Set Value
    #define CND003_PCIEPHYCFG_FRP04_HFSETEN_G1_PHYA    BIT0            // 0/0/x/x LEQ HF Gain Manual Set Enable
#define CND003_PCIEPHYCFG_EQUALIZER_ADAPTIVE_HFSET_LANE00_PHYA_G1 0x702 // Equalizer Adaptive HFSET Lane00 PHYA G1
    #define CND003_PCIEPHYCFG_RSVPCIEPHYCFG_702_7      (BIT6 + BIT7)   // 0/x/x/x Reserved
    #define CND003_PCIEPHYCFG_FRP00_HFSET_G1_PHYA_4_0  0x3E            // 00001b/00001/x/x LEQ HF Gain Initial or Set Value
    #define CND003_PCIEPHYCFG_FRP00_HFSETEN_G1_PHYA    BIT0            // 0/0/x/x LEQ HF Gain Manual Set Enable
#define CND003_PCIEPHYCFG_EQUALIZER_ADAPTIVE_HFSET_LANE01_PHYA_G1 0x703 // Equalizer Adaptive HFSET Lane01 PHYA G1
    #define CND003_PCIEPHYCFG_RSVPCIEPHYCFG_703_7      (BIT6 + BIT7)   // 0/x/x/x Reserved
    #define CND003_PCIEPHYCFG_FRP01_HFSET_G1_PHYA_4_0  0x3E            // 00001b/00001/x/x LEQ HF Gain Initial or Set Value
    #define CND003_PCIEPHYCFG_FRP01_HFSETEN_G1_PHYA    BIT0            // 0/0/x/x LEQ HF Gain Manual Set Enable
#define CND003_PCIEPHYCFG_EQUALIZER_ADAPTIVE_HFSET_LANE02_PHYA_G1 0x704 // Equalizer Adaptive HFSET Lane02 PHYA G1
    #define CND003_PCIEPHYCFG_RSVPCIEPHYCFG_704_7      (BIT6 + BIT7)   // 0/x/x/x Reserved
    #define CND003_PCIEPHYCFG_FRP02_HFSET_G1_PHYA_4_0  0x3E            // 00001b/00001/x/x LEQ HF Gain Initial or Set Value
    #define CND003_PCIEPHYCFG_FRP02_HFSETEN_G1_PHYA    BIT0            // 0/0/x/x LEQ HF Gain Manual Set Enable
#define CND003_PCIEPHYCFG_EQUALIZER_ADAPTIVE_HFSET_LANE03_PHYA_G1 0x705 // Equalizer Adaptive HFSET Lane03 PHYA G1
    #define CND003_PCIEPHYCFG_RSVPCIEPHYCFG_705_7      (BIT6 + BIT7)   // 0/x/x/x Reserved
    #define CND003_PCIEPHYCFG_FRP03_HFSET_G1_PHYA_4_0  0x3E            // 00001b/00001/x/x LEQ HF Gain Initial or Set Value
    #define CND003_PCIEPHYCFG_FRP03_HFSETEN_G1_PHYA    BIT0            // 0/0/x/x LEQ HF Gain Manual Set Enable
#define CND003_PCIEPHYCFG_EQUALIZER_ADAPTIVE_HFSET_LANE00_PHYB_G1 0x706 // Equalizer Adaptive HFSET Lane00 PHYB G1
    #define CND003_PCIEPHYCFG_RSVPCIEPHYCFG_706_7      (BIT6 + BIT7)   // 0/x/x/x Reserved
    #define CND003_PCIEPHYCFG_FRP00_HFSET_G1_PHYB_4_0  0x3E            // 00001b/00001/x/x LEQ HF Gain Initial or Set Value
    #define CND003_PCIEPHYCFG_FRP00_HFSETEN_G1_PHYB    BIT0            // 0/0/x/x LEQ HF Gain Manual Set Enable
#define CND003_PCIEPHYCFG_EQUALIZER_ADAPTIVE_HFSET_LANE01_PHYB_G1 0x707 // Equalizer Adaptive HFSET Lane01 PHYB G1
    #define CND003_PCIEPHYCFG_RSVPCIEPHYCFG_707_7      (BIT6 + BIT7)   // 0/x/x/x Reserved
    #define CND003_PCIEPHYCFG_FRP01_HFSET_G1_PHYB_4_0  0x3E            // 00001b/00001/x/x LEQ HF Gain Initial or Set Value
    #define CND003_PCIEPHYCFG_FRP01_HFSETEN_G1_PHYB    BIT0            // 0/0/x/x LEQ HF Gain Manual Set Enable
#define CND003_PCIEPHYCFG_EQUALIZER_ADAPTIVE_HFSET_LANE02_PHYB_G1 0x708 // Equalizer Adaptive HFSET Lane02 PHYB G1
    #define CND003_PCIEPHYCFG_RSVPCIEPHYCFG_708_7      (BIT6 + BIT7)   // 0/x/x/x Reserved
    #define CND003_PCIEPHYCFG_FRP02_HFSET_G1_PHYB_4_0  0x3E            // 00001b/00001/x/x LEQ HF Gain Initial or Set Value
    #define CND003_PCIEPHYCFG_FRP02_HFSETEN_G1_PHYB    BIT0            // 0/0/x/x LEQ HF Gain Manual Set Enable
#define CND003_PCIEPHYCFG_EQUALIZER_ADAPTIVE_HFSET_LANE03_PHYB_G1 0x709 // Equalizer Adaptive HFSET Lane03 PHYB G1
    #define CND003_PCIEPHYCFG_RSVPCIEPHYCFG_709_7      (BIT6 + BIT7)   // 0/x/x/x Reserved
    #define CND003_PCIEPHYCFG_FRP03_HFSET_G1_PHYB_4_0  0x3E            // 00001b/00001/x/x LEQ HF Gain Initial or Set Value
    #define CND003_PCIEPHYCFG_FRP03_HFSETEN_G1_PHYB    BIT0            // 0/0/x/x LEQ HF Gain Manual Set Enable
#define CND003_PCIEPHYCFG_EQUALIZER_ADAPTIVE_HFSET_LANE00_EP_G1 0x70A // Equalizer Adaptive HFSET Lane00 EP G1
    #define CND003_PCIEPHYCFG_RSVPCIEPHYCFG_70A_7      (BIT6 + BIT7)   // 0/x/x/x Reserved
    #define CND003_PCIEPHYCFG_FRP00_HFSET_G1_EP_4_0    0x3E            // 00001b/00001/x/x LEQ HF Gain Initial or Set Value
    #define CND003_PCIEPHYCFG_FRP00_HFSETEN_G1_EP      BIT0            // 0/0/x/x LEQ HF Gain Manual Set Enable
#define CND003_PCIEPHYCFG_EQUALIZER_ADAPTIVE_HFSET_LANE01_EP_G1 0x70B // Equalizer Adaptive HFSET Lane01 EP G1
    #define CND003_PCIEPHYCFG_RSVPCIEPHYCFG_70B_7      (BIT6 + BIT7)   // 0/x/x/x Reserved
    #define CND003_PCIEPHYCFG_FRP01_HFSET_G1_EP_4_0    0x3E            // 00001b/00001/x/x LEQ HF Gain Initial or Set Value
    #define CND003_PCIEPHYCFG_FRP01_HFSETEN_G1_EP      BIT0            // 0/0/x/x LEQ HF Gain Manual Set Enable
#define CND003_PCIEPHYCFG_EQUALIZER_ADAPTIVE_HFSET_LANE02_EP_G1 0x70C // Equalizer Adaptive HFSET Lane02 EP G1
    #define CND003_PCIEPHYCFG_RSVPCIEPHYCFG_70C_7      (BIT6 + BIT7)   // 0/x/x/x Reserved
    #define CND003_PCIEPHYCFG_FRP02_HFSET_G1_EP_4_0    0x3E            // 00001b/00001/x/x LEQ HF Gain Initial or Set Value
    #define CND003_PCIEPHYCFG_FRP02_HFSETEN_G1_EP      BIT0            // 0/0/x/x LEQ HF Gain Manual Set Enable
#define CND003_PCIEPHYCFG_EQUALIZER_ADAPTIVE_HFSET_LANE03_EP_G1 0x70D // Equalizer Adaptive HFSET Lane03 EP G1
    #define CND003_PCIEPHYCFG_RSVPCIEPHYCFG_70D_7      (BIT6 + BIT7)   // 0/x/x/x Reserved
    #define CND003_PCIEPHYCFG_FRP03_HFSET_G1_EP_4_0    0x3E            // 00001b/00001/x/x LEQ HF Gain Initial or Set Value
    #define CND003_PCIEPHYCFG_FRP03_HFSETEN_G1_EP      BIT0            // 0/0/x/x LEQ HF Gain Manual Set Enable
#define CND003_PCIEPHYCFG_EQUALIZER_ADAPTIVE_HFSET_LANE00_PHYC_G1 0x70E // Equalizer Adaptive HFSET Lane00 PHYC G1
    #define CND003_PCIEPHYCFG_RSVPCIEPHYCFG_70E_7 PCIEPHYCFG_EQUALIZER_ADAPTIVE_HFSET_LANE00_PHYC_G1 // 0/x/x/X Reserved
#define CND003_PCIEPHYCFG_EQUALIZER_ADAPTIVE_HFSET_LANE01_PHYC_G1 0x70F // Equalizer Adaptive HFSET Lane01 PHYC G1
    #define CND003_PCIEPHYCFG_RSVPCIEPHYCFG_70F_7 PCIEPHYCFG_EQUALIZER_ADAPTIVE_HFSET_LANE01_PHYC_G1 // 0/x/x/x Reserved
#define CND003_PCIEPHYCFG_RESERVED_Z37 0x710 // Reserved
    #define CND003_PCIEPHYCFG_RSVPCIEPHYCFG_713_7 PCIEPHYCFG_RESERVED_Z37 // 0/x/x/x Reserved
#define CND003_PCIEPHYCFG_EQUALIZER_ADAPTIVE_HFSET_LANE00_G2 0x720 // Equalizer Adaptive HFSET Lane00 G2
    #define CND003_PCIEPHYCFG_RSVPCIEPHYCFG_720_7 PCIEPHYCFG_EQUALIZER_ADAPTIVE_HFSET_LANE00_G2 // 0/x/x/X Reserved
#define CND003_PCIEPHYCFG_EQUALIZER_ADAPTIVE_HFSET_LANE04_PHYA_G2 0x721 // Equalizer Adaptive HFSET Lane04 PHYA G2
    #define CND003_PCIEPHYCFG_RSVPCIEPHYCFG_721_7      (BIT6 + BIT7)   // 0/x/x/x Reserved
    #define CND003_PCIEPHYCFG_FRP04_HFSET_G2_PHYA_4_0  0x3E            // 00001b/00001/x/x LEQ HF Gain Initial or Set Value
    #define CND003_PCIEPHYCFG_FRP04_HFSETEN_G2_PHYA    BIT0            // 0/0/x/x LEQ HF Gain Manual Set Enable
#define CND003_PCIEPHYCFG_EQUALIZER_ADAPTIVE_HFSET_LANE00_PHYA_G2 0x722 // Equalizer Adaptive HFSET Lane00 PHYA G2
    #define CND003_PCIEPHYCFG_RSVPCIEPHYCFG_722_7      (BIT6 + BIT7)   // 0/x/x/x Reserved
    #define CND003_PCIEPHYCFG_FRP00_HFSET_G2_PHYA_4_0  0x3E            // 00001b/00001/x/x LEQ HF Gain Initial or Set Value
    #define CND003_PCIEPHYCFG_FRP00_HFSETEN_G2_PHYA    BIT0            // 0/0/x/x LEQ HF Gain Manual Set Enable
#define CND003_PCIEPHYCFG_EQUALIZER_ADAPTIVE_HFSET_LANE01_PHYA_G2 0x723 // Equalizer Adaptive HFSET Lane01 PHYA G2
    #define CND003_PCIEPHYCFG_RSVPCIEPHYCFG_723_7      (BIT6 + BIT7)   // 0/x/x/x Reserved
    #define CND003_PCIEPHYCFG_FRP01_HFSET_G2_PHYA_4_0  0x3E            // 00001b/00001/x/x LEQ HF Gain Initial or Set Value
    #define CND003_PCIEPHYCFG_FRP01_HFSETEN_G2_PHYA    BIT0            // 0/0/x/x LEQ HF Gain Manual Set Enable
#define CND003_PCIEPHYCFG_EQUALIZER_ADAPTIVE_HFSET_LANE02_PHYA_G2 0x724 // Equalizer Adaptive HFSET Lane02 PHYA G2
    #define CND003_PCIEPHYCFG_RSVPCIEPHYCFG_724_7      (BIT6 + BIT7)   // 0/x/x/x Reserved
    #define CND003_PCIEPHYCFG_FRP02_HFSET_G2_PHYA_4_0  0x3E            // 00001b/00001/x/x LEQ HF Gain Initial or Set Value
    #define CND003_PCIEPHYCFG_FRP02_HFSETEN_G2_PHYA    BIT0            // 0/0/x/x LEQ HF Gain Manual Set Enable
#define CND003_PCIEPHYCFG_EQUALIZER_ADAPTIVE_HFSET_LANE03_PHYA_G2 0x725 // Equalizer Adaptive HFSET Lane03 PHYA G2
    #define CND003_PCIEPHYCFG_RSVPCIEPHYCFG_725_7      (BIT6 + BIT7)   // 0/x/x/x Reserved
    #define CND003_PCIEPHYCFG_FRP03_HFSET_G2_PHYA_4_0  0x3E            // 00001b/00001/x/x LEQ HF Gain Initial or Set Value
    #define CND003_PCIEPHYCFG_FRP03_HFSETEN_G2_PHYA    BIT0            // 0/0/x/x LEQ HF Gain Manual Set Enable
#define CND003_PCIEPHYCFG_EQUALIZER_ADAPTIVE_HFSET_LANE00_PHYB_G2 0x726 // Equalizer Adaptive HFSET Lane00 PHYB G2
    #define CND003_PCIEPHYCFG_RSVPCIEPHYCFG_726_7      (BIT6 + BIT7)   // 0/x/x/x Reserved
    #define CND003_PCIEPHYCFG_FRP00_HFSET_G2_PHYB_4_0  0x3E            // 00001b/00001/x/x LEQ HF Gain Initial or Set Value
    #define CND003_PCIEPHYCFG_FRP00_HFSETEN_G2_PHYB    BIT0            // 0/0/x/x LEQ HF Gain Manual Set Enable
#define CND003_PCIEPHYCFG_EQUALIZER_ADAPTIVE_HFSET_LANE01_PHYB_G2 0x727 // Equalizer Adaptive HFSET Lane01 PHYB G2
    #define CND003_PCIEPHYCFG_RSVPCIEPHYCFG_727_7      (BIT6 + BIT7)   // 0/x/x/x Reserved
    #define CND003_PCIEPHYCFG_FRP01_HFSET_G2_PHYB_4_0  0x3E            // 00001b/00001/x/x LEQ HF Gain Initial or Set Value
    #define CND003_PCIEPHYCFG_FRP01_HFSETEN_G2_PHYB    BIT0            // 0/0/x/x LEQ HF Gain Manual Set Enable
#define CND003_PCIEPHYCFG_EQUALIZER_ADAPTIVE_HFSET_LANE02_PHYB_G2 0x728 // Equalizer Adaptive HFSET Lane02 PHYB G2
    #define CND003_PCIEPHYCFG_RSVPCIEPHYCFG_728_7      (BIT6 + BIT7)   // 0/x/x/x Reserved
    #define CND003_PCIEPHYCFG_FRP02_HFSET_G2_PHYB_4_0  0x3E            // 00001b/00001/x/x LEQ HF Gain Initial or Set Value
    #define CND003_PCIEPHYCFG_FRP02_HFSETEN_G2_PHYB    BIT0            // 0/0/x/x LEQ HF Gain Manual Set Enable
#define CND003_PCIEPHYCFG_EQUALIZER_ADAPTIVE_HFSET_LANE03_PHYB_G2 0x729 // Equalizer Adaptive HFSET Lane03 PHYB G2
    #define CND003_PCIEPHYCFG_RSVPCIEPHYCFG_729_7      (BIT6 + BIT7)   // 0/x/x/x Reserved
    #define CND003_PCIEPHYCFG_FRP03_HFSET_G2_PHYB_4_0  0x3E            // 00001b/00001/x/x LEQ HF Gain Initial or Set Value
    #define CND003_PCIEPHYCFG_FRP03_HFSETEN_G2_PHYB    BIT0            // 0/0/x/x LEQ HF Gain Manual Set Enable
#define CND003_PCIEPHYCFG_EQUALIZER_ADAPTIVE_HFSET_LANE00_EP_G2 0x72A // Equalizer Adaptive HFSET Lane00 EP G2
    #define CND003_PCIEPHYCFG_RSVPCIEPHYCFG_72A_7      (BIT6 + BIT7)   // 0/x/x/x Reserved
    #define CND003_PCIEPHYCFG_FRP00_HFSET_G2_EP_4_0    0x3E            // 00001b/00001/x/x LEQ HF Gain Initial or Set Value
    #define CND003_PCIEPHYCFG_FRP00_HFSETEN_G2_EP      BIT0            // 0/0/x/x LEQ HF Gain Manual Set Enable
#define CND003_PCIEPHYCFG_EQUALIZER_ADAPTIVE_HFSET_LANE01_EP_G2 0x72B // Equalizer Adaptive HFSET Lane01 EP G2
    #define CND003_PCIEPHYCFG_RSVPCIEPHYCFG_72B_7      (BIT6 + BIT7)   // 0/x/x/x Reserved
    #define CND003_PCIEPHYCFG_FRP01_HFSET_G2_EP_4_0    0x3E            // 00001b/00001/x/x LEQ HF Gain Initial or Set Value
    #define CND003_PCIEPHYCFG_FRP01_HFSETEN_G2_EP      BIT0            // 0/0/x/x LEQ HF Gain Manual Set Enable
#define CND003_PCIEPHYCFG_EQUALIZER_ADAPTIVE_HFSET_LANE02_EP_G2 0x72C // Equalizer Adaptive HFSET Lane02 EP G2
    #define CND003_PCIEPHYCFG_RSVPCIEPHYCFG_72C_7      (BIT6 + BIT7)   // 0/x/x/x Reserved
    #define CND003_PCIEPHYCFG_FRP02_HFSET_G2_EP_4_0    0x3E            // 00001b/00001/x/x LEQ HF Gain Initial or Set Value
    #define CND003_PCIEPHYCFG_FRP02_HFSETEN_G2_EP      BIT0            // 0/0/x/x LEQ HF Gain Manual Set Enable
#define CND003_PCIEPHYCFG_EQUALIZER_ADAPTIVE_HFSET_LANE03_EP_G2 0x72D // Equalizer Adaptive HFSET Lane03 EP G2
    #define CND003_PCIEPHYCFG_RSVPCIEPHYCFG_72D_7      (BIT6 + BIT7)   // 0/x/x/x Reserved
    #define CND003_PCIEPHYCFG_FRP03_HFSET_G2_EP_4_0    0x3E            // 00001b/00001/x/x LEQ HF Gain Initial or Set Value
    #define CND003_PCIEPHYCFG_FRP03_HFSETEN_G2_EP      BIT0            // 0/0/x/x LEQ HF Gain Manual Set Enable
#define CND003_PCIEPHYCFG_EQUALIZER_ADAPTIVE_HFSET_LANE00_PHYC_G2 0x72E // Equalizer Adaptive HFSET Lane00 PHYC G2
    #define CND003_PCIEPHYCFG_RSVPCIEPHYCFG_72E_7 PCIEPHYCFG_EQUALIZER_ADAPTIVE_HFSET_LANE00_PHYC_G2 // 0/x/x/X Reserved
#define CND003_PCIEPHYCFG_EQUALIZER_ADAPTIVE_HFSET_LANE01_PHYC_G2 0x72F // Equalizer Adaptive HFSET Lane01 PHYC G2
    #define CND003_PCIEPHYCFG_RSVPCIEPHYCFG_72F_7 PCIEPHYCFG_EQUALIZER_ADAPTIVE_HFSET_LANE01_PHYC_G2 // 0/x/x/x Reserved
#define CND003_PCIEPHYCFG_RESERVED_Z38 0x730 // Reserved
    #define CND003_PCIEPHYCFG_RSVPCIEPHYCFG_730_7 PCIEPHYCFG_RESERVED_Z38 // 0/x/x/x Reserved
#define CND003_PCIEPHYCFG_EQUALIZER_ADAPTIVE_HFSET_LANE00_G3 0x740 // Equalizer Adaptive HFSET Lane00 G3
    #define CND003_PCIEPHYCFG_RSVPCIEPHYCFG_740_7 PCIEPHYCFG_EQUALIZER_ADAPTIVE_HFSET_LANE00_G3 // 0/x/x/X Reserved
#define CND003_PCIEPHYCFG_EQUALIZER_ADAPTIVE_HFSET_LANE04_PHYA_G3 0x741 // Equalizer Adaptive HFSET Lane04 PHYA G3
    #define CND003_PCIEPHYCFG_RSVPCIEPHYCFG_741_7      (BIT6 + BIT7)   // 0/x/x/x Reserved
    #define CND003_PCIEPHYCFG_FRP04_HFSET_G3_PHYA_4_0  0x3E            // 00001b/00001/x/x LEQ HF Gain Initial or Set Value
    #define CND003_PCIEPHYCFG_FRP04_HFSETEN_G3_PHYA    BIT0            // 0/0/x/x LEQ HF Gain Manual Set Enable
#define CND003_PCIEPHYCFG_EQUALIZER_ADAPTIVE_HFSET_LANE00_PHYA_G3 0x742 // Equalizer Adaptive HFSET Lane00 PHYA G3
    #define CND003_PCIEPHYCFG_RSVPCIEPHYCFG_742_7      (BIT6 + BIT7)   // 0/x/x/x Reserved
    #define CND003_PCIEPHYCFG_FRP00_HFSET_G3_PHYA_4_0  0x3E            // 00001b/00001/x/x LEQ HF Gain Initial or Set Value
    #define CND003_PCIEPHYCFG_FRP00_HFSETEN_G3_PHYA    BIT0            // 0/0/x/x LEQ HF Gain Manual Set Enable
#define CND003_PCIEPHYCFG_EQUALIZER_ADAPTIVE_HFSET_LANE01_PHYA_G3 0x743 // Equalizer Adaptive HFSET Lane01 PHYA G3
    #define CND003_PCIEPHYCFG_RSVPCIEPHYCFG_743_7      (BIT6 + BIT7)   // 0/x/x/x Reserved
    #define CND003_PCIEPHYCFG_FRP01_HFSET_G3_PHYA_4_0  0x3E            // 00001b/00001/x/x LEQ HF Gain Initial or Set Value
    #define CND003_PCIEPHYCFG_FRP01_HFSETEN_G3_PHYA    BIT0            // 0/0/x/x LEQ HF Gain Manual Set Enable
#define CND003_PCIEPHYCFG_EQUALIZER_ADAPTIVE_HFSET_LANE02_PHYA_G3 0x744 // Equalizer Adaptive HFSET Lane02 PHYA G3
    #define CND003_PCIEPHYCFG_RSVPCIEPHYCFG_744_7      (BIT6 + BIT7)   // 0/x/x/x Reserved
    #define CND003_PCIEPHYCFG_FRP02_HFSET_G3_PHYA_4_0  0x3E            // 00001b/00001/x/x LEQ HF Gain Initial or Set Value
    #define CND003_PCIEPHYCFG_FRP02_HFSETEN_G3_PHYA    BIT0            // 0/0/x/x LEQ HF Gain Manual Set Enable
#define CND003_PCIEPHYCFG_EQUALIZER_ADAPTIVE_HFSET_LANE03_PHYA_G3 0x745 // Equalizer Adaptive HFSET Lane03 PHYA G3
    #define CND003_PCIEPHYCFG_RSVPCIEPHYCFG_745_7      (BIT6 + BIT7)   // 0/x/x/x Reserved
    #define CND003_PCIEPHYCFG_FRP03_HFSET_G3_PHYA_4_0  0x3E            // 00001b/00001/x/x LEQ HF Gain Initial or Set Value
    #define CND003_PCIEPHYCFG_FRP03_HFSETEN_G3_PHYA    BIT0            // 0/0/x/x LEQ HF Gain Manual Set Enable
#define CND003_PCIEPHYCFG_EQUALIZER_ADAPTIVE_HFSET_LANE00_PHYB_G3 0x746 // Equalizer Adaptive HFSET Lane00 PHYB G3
    #define CND003_PCIEPHYCFG_RSVPCIEPHYCFG_746_7      (BIT6 + BIT7)   // 0/x/x/x Reserved
    #define CND003_PCIEPHYCFG_FRP00_HFSET_G3_PHYB_4_0  0x3E            // 00001b/00001/x/x LEQ HF Gain Initial or Set Value
    #define CND003_PCIEPHYCFG_FRP00_HFSETEN_G3_PHYB    BIT0            // 0/0/x/x LEQ HF Gain Manual Set Enable
#define CND003_PCIEPHYCFG_EQUALIZER_ADAPTIVE_HFSET_LANE01_PHYB_G3 0x747 // Equalizer Adaptive HFSET Lane01 PHYB G3
    #define CND003_PCIEPHYCFG_RSVPCIEPHYCFG_747_7      (BIT6 + BIT7)   // 0/x/x/x Reserved
    #define CND003_PCIEPHYCFG_FRP01_HFSET_G3_PHYB_4_0  0x3E            // 00001b/00001/x/x LEQ HF Gain Initial or Set Value
    #define CND003_PCIEPHYCFG_FRP01_HFSETEN_G3_PHYB    BIT0            // 0/0/x/x LEQ HF Gain Manual Set Enable
#define CND003_PCIEPHYCFG_EQUALIZER_ADAPTIVE_HFSET_LANE02_PHYB_G3 0x748 // Equalizer Adaptive HFSET Lane02 PHYB G3
    #define CND003_PCIEPHYCFG_RSVPCIEPHYCFG_748_7      (BIT6 + BIT7)   // 0/x/x/x Reserved
    #define CND003_PCIEPHYCFG_FRP02_HFSET_G3_PHYB_4_0  0x3E            // 00001b/00001/x/x LEQ HF Gain Initial or Set Value
    #define CND003_PCIEPHYCFG_FRP02_HFSETEN_G3_PHYB    BIT0            // 0/0/x/x LEQ HF Gain Manual Set Enable
#define CND003_PCIEPHYCFG_EQUALIZER_ADAPTIVE_HFSET_LANE03_PHYB_G3 0x749 // Equalizer Adaptive HFSET Lane03 PHYB G3
    #define CND003_PCIEPHYCFG_RSVPCIEPHYCFG_749_7      (BIT6 + BIT7)   // 0/x/x/x Reserved
    #define CND003_PCIEPHYCFG_FRP03_HFSET_G3_PHYB_4_0  0x3E            // 00001b/00001/x/x LEQ HF Gain Initial or Set Value
    #define CND003_PCIEPHYCFG_FRP03_HFSETEN_G3_PHYB    BIT0            // 0/0/x/x LEQ HF Gain Manual Set Enable
#define CND003_PCIEPHYCFG_EQUALIZER_ADAPTIVE_HFSET_LANE00_EP_G3 0x74A // Equalizer Adaptive HFSET Lane00 EP G3
    #define CND003_PCIEPHYCFG_RSVPCIEPHYCFG_74A_7      (BIT6 + BIT7)   // 0/x/x/x Reserved
    #define CND003_PCIEPHYCFG_FRP00_HFSET_G3_EP_4_0    0x3E            // 00001b/00001/x/x LEQ HF Gain Initial or Set Value
    #define CND003_PCIEPHYCFG_FRP00_HFSETEN_G3_EP      BIT0            // 0/0/x/x LEQ HF Gain Manual Set Enable
#define CND003_PCIEPHYCFG_EQUALIZER_ADAPTIVE_HFSET_LANE01_EP_G3 0x74B // Equalizer Adaptive HFSET Lane01 EP G3
    #define CND003_PCIEPHYCFG_RSVPCIEPHYCFG_74B_7      (BIT6 + BIT7)   // 0/x/x/x Reserved
    #define CND003_PCIEPHYCFG_FRP01_HFSET_G3_EP_4_0    0x3E            // 00001b/00001/x/x LEQ HF Gain Initial or Set Value
    #define CND003_PCIEPHYCFG_FRP01_HFSETEN_G3_EP      BIT0            // 0/0/x/x LEQ HF Gain Manual Set Enable
#define CND003_PCIEPHYCFG_EQUALIZER_ADAPTIVE_HFSET_LANE02_EP_G3 0x74C // Equalizer Adaptive HFSET Lane02 EP G3
    #define CND003_PCIEPHYCFG_RSVPCIEPHYCFG_74C_7      (BIT6 + BIT7)   // 0/x/x/x Reserved
    #define CND003_PCIEPHYCFG_FRP02_HFSET_G3_EP_4_0    0x3E            // 00001b/00001/x/x LEQ HF Gain Initial or Set Value
    #define CND003_PCIEPHYCFG_FRP02_HFSETEN_G3_EP      BIT0            // 0/0/x/x LEQ HF Gain Manual Set Enable
#define CND003_PCIEPHYCFG_EQUALIZER_ADAPTIVE_HFSET_LANE03_EP_G3 0x74D // Equalizer Adaptive HFSET Lane03 EP G3
    #define CND003_PCIEPHYCFG_RSVPCIEPHYCFG_74D_7      (BIT6 + BIT7)   // 0/x/x/x Reserved
    #define CND003_PCIEPHYCFG_FRP03_HFSET_G3_EP_4_0    0x3E            // 00001b/00001/x/x LEQ HF Gain Initial or Set Value
    #define CND003_PCIEPHYCFG_FRP03_HFSETEN_G3_EP      BIT0            // 0/0/x/x LEQ HF Gain Manual Set Enable
#define CND003_PCIEPHYCFG_EQUALIZER_ADAPTIVE_HFSET_LANE00_PHYC_G3 0x74E // Equalizer Adaptive HFSET Lane00 PHYC G3
    #define CND003_PCIEPHYCFG_RSVPCIEPHYCFG_74E_7 PCIEPHYCFG_EQUALIZER_ADAPTIVE_HFSET_LANE00_PHYC_G3 // 0/x/x/X Reserved
#define CND003_PCIEPHYCFG_EQUALIZER_ADAPTIVE_HFSET_LANE01_PHYC_G3 0x74F // Equalizer Adaptive HFSET Lane01 PHYC G3
    #define CND003_PCIEPHYCFG_RSVPCIEPHYCFG_74F_7 PCIEPHYCFG_EQUALIZER_ADAPTIVE_HFSET_LANE01_PHYC_G3 // 0/x/x/x Reserved
#define CND003_PCIEPHYCFG_RESERVED_Z39 0x750 // Reserved
    #define CND003_PCIEPHYCFG_RSVPCIEPHYCFG_750_7 PCIEPHYCFG_RESERVED_Z39 // 0/x/x/x Reserved
#define CND003_PCIEPHYCFG_EQUALIZER_ADAPTIVE_FRP_OSSET_LANE00_G1 0x780 // Equalizer Adaptive FRP_OSSET Lane00 G1
    #define CND003_PCIEPHYCFG_RSVPCIEPHYCFG_780_7 PCIEPHYCFG_EQUALIZER_ADAPTIVE_FRP_OSSET_LANE00_G1 // 0/x/x/x Reserved
#define CND003_PCIEPHYCFG_EQUALIZER_ADAPTIVE_FRP_OSSET_LANE04_PHYA_G1 0x781 // Equalizer Adaptive FRP_OSSET Lane04 PHYA G1
    #define CND003_PCIEPHYCFG_RSVPCIEPHYCFG_781_7      (BIT6 + BIT7)   // 0/x/x/x Reserved
    #define CND003_PCIEPHYCFG_FRP04_OSSET_G1_PHYA_4_0  0x3E            // 0/0/x/x LEQ Offset Initial or Set Value
    #define CND003_PCIEPHYCFG_FRP04_OSSETEN_G1_PHYA    BIT0            // 0/0/x/x LEQ Offset Manual Set Enable
#define CND003_PCIEPHYCFG_EQUALIZER_ADAPTIVE_FRP_OSSET_LANE00_PHYA_G1 0x782 // Equalizer Adaptive FRP_OSSET Lane00 PHYA G1
    #define CND003_PCIEPHYCFG_RSVPCIEPHYCFG_782_7      (BIT6 + BIT7)   // 0/x/x/x Reserved
    #define CND003_PCIEPHYCFG_FRP00_OSSET_G1_PHYA_4_0  0x3E            // 0/0/x/x LEQ Offset Initial or Set Value
    #define CND003_PCIEPHYCFG_FRP00_OSSETEN_G1_PHYA    BIT0            // 0/0/x/x LEQ Offset Manual Set Enable
#define CND003_PCIEPHYCFG_EQUALIZER_ADAPTIVE_FRP_OSSET_LANE01_PHYA_G1 0x783 // Equalizer Adaptive FRP_OSSET Lane01 PHYA G1
    #define CND003_PCIEPHYCFG_RSVPCIEPHYCFG_783_7      (BIT6 + BIT7)   // 0/x/x/x Reserved
    #define CND003_PCIEPHYCFG_FRP01_OSSET_G1_PHYA_4_0  0x3E            // 0/0/x/x LEQ Offset Initial or Set Value
    #define CND003_PCIEPHYCFG_FRP01_OSSETEN_G1_PHYA    BIT0            // 0/0/x/x LEQ Offset Manual Set Enable
#define CND003_PCIEPHYCFG_EQUALIZER_ADAPTIVE_FRP_OSSET_LANE02_PHYA_G1 0x784 // Equalizer Adaptive FRP_OSSET Lane02 PHYA G1
    #define CND003_PCIEPHYCFG_RSVPCIEPHYCFG_784_7      (BIT6 + BIT7)   // 0/x/x/x Reserved
    #define CND003_PCIEPHYCFG_FRP02_OSSET_G1_PHYA_4_0  0x3E            // 0/0/x/x LEQ Offset Initial or Set Value
    #define CND003_PCIEPHYCFG_FRP02_OSSETEN_G1_PHYA    BIT0            // 0/0/x/x LEQ Offset Manual Set Enable
#define CND003_PCIEPHYCFG_EQUALIZER_ADAPTIVE_FRP_OSSET_LANE03_PHYA_G1 0x785 // Equalizer Adaptive FRP_OSSET Lane03 PHYA G1
    #define CND003_PCIEPHYCFG_RSVPCIEPHYCFG_785_7      (BIT6 + BIT7)   // 0/x/x/x Reserved
    #define CND003_PCIEPHYCFG_FRP03_OSSET_G1_PHYA_4_0  0x3E            // 0/0/x/x LEQ Offset Initial or Set Value
    #define CND003_PCIEPHYCFG_FRP03_OSSETEN_G1_PHYA    BIT0            // 0/0/x/x LEQ Offset Manual Set Enable
#define CND003_PCIEPHYCFG_EQUALIZER_ADAPTIVE_FRP_OSSET_LANE00_PHYB_G1 0x786 // Equalizer Adaptive FRP_OSSET Lane00 PHYB G1
    #define CND003_PCIEPHYCFG_RSVPCIEPHYCFG_786_7      (BIT6 + BIT7)   // 0/x/x/x Reserved
    #define CND003_PCIEPHYCFG_FRP00_OSSET_G1_PHYB_4_0  0x3E            // 0/0/x/x LEQ Offset Initial or Set Value
    #define CND003_PCIEPHYCFG_FRP00_OSSETEN_G1_PHYB    BIT0            // 0/0/x/x LEQ Offset Manual Set Enable
#define CND003_PCIEPHYCFG_EQUALIZER_ADAPTIVE_FRP_OSSET_LANE01_PHYB_G1 0x787 // Equalizer Adaptive FRP_OSSET Lane01 PHYB G1
    #define CND003_PCIEPHYCFG_RSVPCIEPHYCFG_787_7      (BIT6 + BIT7)   // 0/x/x/x Reserved
    #define CND003_PCIEPHYCFG_FRP01_OSSET_G1_PHYB_4_0  0x3E            // 0/0/x/x LEQ Offset Initial or Set Value
    #define CND003_PCIEPHYCFG_FRP01_OSSETEN_G1_PHYB    BIT0            // 0/0/x/x LEQ Offset Manual Set Enable
#define CND003_PCIEPHYCFG_EQUALIZER_ADAPTIVE_FRP_OSSET_LANE02_PHYB_G1 0x788 // Equalizer Adaptive FRP_OSSET Lane02 PHYB G1
    #define CND003_PCIEPHYCFG_RSVPCIEPHYCFG_788_7      (BIT6 + BIT7)   // 0/x/x/x Reserved
    #define CND003_PCIEPHYCFG_FRP02_OSSET_G1_PHYB_4_0  0x3E            // 0/0/x/x LEQ Offset Initial or Set Value
    #define CND003_PCIEPHYCFG_FRP02_OSSETEN_G1_PHYB    BIT0            // 0/0/x/x LEQ Offset Manual Set Enable
#define CND003_PCIEPHYCFG_EQUALIZER_ADAPTIVE_FRP_OSSET_LANE03_PHYB_G1 0x789 // Equalizer Adaptive FRP_OSSET Lane03 PHYB G1
    #define CND003_PCIEPHYCFG_RSVPCIEPHYCFG_789_7      (BIT6 + BIT7)   // 0/x/x/x Reserved
    #define CND003_PCIEPHYCFG_FRP03_OSSET_G1_PHYB_4_0  0x3E            // 0/0/x/x LEQ Offset Initial or Set Value
    #define CND003_PCIEPHYCFG_FRP03_OSSETEN_G1_PHYB    BIT0            // 0/0/x/x LEQ Offset Manual Set Enable
#define CND003_PCIEPHYCFG_EQUALIZER_ADAPTIVE_FRP_OSSET_LANE00_EP_G1 0x78A // Equalizer Adaptive FRP_OSSET Lane00 EP G1
    #define CND003_PCIEPHYCFG_RSVPCIEPHYCFG_78A_7      (BIT6 + BIT7)   // 0/x/x/x Reserved
    #define CND003_PCIEPHYCFG_FRP00_OSSET_G1_EP_4_0    0x3E            // 0/0/x/x LEQ Offset Initial or Set Value
    #define CND003_PCIEPHYCFG_FRP00_OSSETEN_G1_EP      BIT0            // 0/0/x/x LEQ Offset Manual Set Enable
#define CND003_PCIEPHYCFG_EQUALIZER_ADAPTIVE_FRP_OSSET_LANE01_EP_G1 0x78B // Equalizer Adaptive FRP_OSSET Lane01 EP G1
    #define CND003_PCIEPHYCFG_RSVPCIEPHYCFG_78B_7      (BIT6 + BIT7)   // 0/x/x/x Reserved
    #define CND003_PCIEPHYCFG_FRP01_OSSET_G1_EP_4_0    0x3E            // 0/0/x/x LEQ Offset Initial or Set Value
    #define CND003_PCIEPHYCFG_FRP01_OSSETEN_G1_EP      BIT0            // 0/0/x/x LEQ Offset Manual Set Enable
#define CND003_PCIEPHYCFG_EQUALIZER_ADAPTIVE_FRP_OSSET_LANE02_EP_G1 0x78C // Equalizer Adaptive FRP_OSSET Lane02 EP G1
    #define CND003_PCIEPHYCFG_RSVPCIEPHYCFG_78C_7      (BIT6 + BIT7)   // 0/x/x/x Reserved
    #define CND003_PCIEPHYCFG_FRP02_OSSET_G1_EP_4_0    0x3E            // 0/0/x/x LEQ Offset Initial or Set Value
    #define CND003_PCIEPHYCFG_FRP02_OSSETEN_G1_EP      BIT0            // 0/0/x/x LEQ Offset Manual Set Enable
#define CND003_PCIEPHYCFG_EQUALIZER_ADAPTIVE_FRP_OSSET_LANE03_EP_G1 0x78D // Equalizer Adaptive FRP_OSSET Lane03 EP G1
    #define CND003_PCIEPHYCFG_RSVPCIEPHYCFG_78D_7      (BIT6 + BIT7)   // 0/x/x/x Reserved
    #define CND003_PCIEPHYCFG_FRP03_OSSET_G1_EP_4_0    0x3E            // 0/0/x/x LEQ Offset Initial or Set Value
    #define CND003_PCIEPHYCFG_FRP03_OSSETEN_G1_EP      BIT0            // 0/0/x/x LEQ Offset Manual Set Enable
#define CND003_PCIEPHYCFG_EQUALIZER_ADAPTIVE_FRP_OSSET_LANE00_PHYC_G1 0x78E // Equalizer Adaptive FRP_OSSET Lane00 PHYC G1
    #define CND003_PCIEPHYCFG_RSVPCIEPHYCFG_78E_7 PCIEPHYCFG_EQUALIZER_ADAPTIVE_FRP_OSSET_LANE00_PHYC_G1 // 0/x/x/x Reserved
#define CND003_PCIEPHYCFG_EQUALIZER_ADAPTIVE_FRP_OSSET_LANE01_PHYC_G1 0x78F // Equalizer Adaptive FRP_OSSET Lane01 PHYC G1
    #define CND003_PCIEPHYCFG_RSVPCIEPHYCFG_78F_7 PCIEPHYCFG_EQUALIZER_ADAPTIVE_FRP_OSSET_LANE01_PHYC_G1 // 0/x/x/x Reserved
#define CND003_PCIEPHYCFG_RESERVED_Z40 0x790 // Reserved
    #define CND003_PCIEPHYCFG_RSVPCIEPHYCFG_790_7 PCIEPHYCFG_RESERVED_Z40 // 0/x/x/x Reserved
#define CND003_PCIEPHYCFG_EQUALIZER_ADAPTIVE_FRP_OSSET_LANE00_G2 0x7A0 // Equalizer Adaptive FRP_OSSET Lane00 G2
    #define CND003_PCIEPHYCFG_RSVPCIEPHYCFG_7A0_7 PCIEPHYCFG_EQUALIZER_ADAPTIVE_FRP_OSSET_LANE00_G2 // 0/x/x/x Reserved
#define CND003_PCIEPHYCFG_EQUALIZER_ADAPTIVE_FRP_OSSET_LANE04_PHYA_G2 0x7A1 // Equalizer Adaptive FRP_OSSET Lane04 PHYA G2
    #define CND003_PCIEPHYCFG_RSVPCIEPHYCFG_7A1_7      (BIT6 + BIT7)   // 0/x/x/x Reserved
    #define CND003_PCIEPHYCFG_FRP04_OSSET_G2_PHYA_4_0  0x3E            // 0/0/x/x LEQ Offset Initial or Set Value
    #define CND003_PCIEPHYCFG_FRP04_OSSETEN_G2_PHYA    BIT0            // 0/0/x/x LEQ Offset Manual Set Enable
#define CND003_PCIEPHYCFG_EQUALIZER_ADAPTIVE_FRP_OSSET_LANE00_PHYA_G2 0x7A2 // Equalizer Adaptive FRP_OSSET Lane00 PHYA G2
    #define CND003_PCIEPHYCFG_RSVPCIEPHYCFG_7A2_7      (BIT6 + BIT7)   // 0/x/x/x Reserved
    #define CND003_PCIEPHYCFG_FRP00_OSSET_G2_PHYA_4_0  0x3E            // 0/0/x/x LEQ Offset Initial or Set Value
    #define CND003_PCIEPHYCFG_FRP00_OSSETEN_G2_PHYA    BIT0            // 0/0/x/x LEQ Offset Manual Set Enable
#define CND003_PCIEPHYCFG_EQUALIZER_ADAPTIVE_FRP_OSSET_LANE01_PHYA_G2 0x7A3 // Equalizer Adaptive FRP_OSSET Lane01 PHYA G2
    #define CND003_PCIEPHYCFG_RSVPCIEPHYCFG_7A3_7      (BIT6 + BIT7)   // 0/x/x/x Reserved
    #define CND003_PCIEPHYCFG_FRP01_OSSET_G2_PHYA_4_0  0x3E            // 0/0/x/x LEQ Offset Initial or Set Value
    #define CND003_PCIEPHYCFG_FRP01_OSSETEN_G2_PHYA    BIT0            // 0/0/x/x LEQ Offset Manual Set Enable
#define CND003_PCIEPHYCFG_EQUALIZER_ADAPTIVE_FRP_OSSET_LANE02_PHYA_G2 0x7A4 // Equalizer Adaptive FRP_OSSET Lane02 PHYA G2
    #define CND003_PCIEPHYCFG_RSVPCIEPHYCFG_7A4_7      (BIT6 + BIT7)   // 0/x/x/x Reserved
    #define CND003_PCIEPHYCFG_FRP02_OSSET_G2_PHYA_4_0  0x3E            // 0/0/x/x LEQ Offset Initial or Set Value
    #define CND003_PCIEPHYCFG_FRP02_OSSETEN_G2_PHYA    BIT0            // 0/0/x/x LEQ Offset Manual Set Enable
#define CND003_PCIEPHYCFG_EQUALIZER_ADAPTIVE_FRP_OSSET_LANE03_PHYA_G2 0x7A5 // Equalizer Adaptive FRP_OSSET Lane03 PHYA G2
    #define CND003_PCIEPHYCFG_RSVPCIEPHYCFG_7A5_7      (BIT6 + BIT7)   // 0/x/x/x Reserved
    #define CND003_PCIEPHYCFG_FRP03_OSSET_G2_PHYA_4_0  0x3E            // 0/0/x/x LEQ Offset Initial or Set Value
    #define CND003_PCIEPHYCFG_FRP03_OSSETEN_G2_PHYA    BIT0            // 0/0/x/x LEQ Offset Manual Set Enable
#define CND003_PCIEPHYCFG_EQUALIZER_ADAPTIVE_FRP_OSSET_LANE00_PHYB_G2 0x7A6 // Equalizer Adaptive FRP_OSSET Lane00 PHYB G2
    #define CND003_PCIEPHYCFG_RSVPCIEPHYCFG_7A6_7      (BIT6 + BIT7)   // 0/x/x/x Reserved
    #define CND003_PCIEPHYCFG_FRP00_OSSET_G2_PHYB_4_0  0x3E            // 0/0/x/x LEQ Offset Initial or Set Value
    #define CND003_PCIEPHYCFG_FRP00_OSSETEN_G2_PHYB    BIT0            // 0/0/x/x LEQ Offset Manual Set Enable
#define CND003_PCIEPHYCFG_EQUALIZER_ADAPTIVE_FRP_OSSET_LANE01_PHYB_G2 0x7A7 // Equalizer Adaptive FRP_OSSET Lane01 PHYB G2
    #define CND003_PCIEPHYCFG_RSVPCIEPHYCFG_7A7_7      (BIT6 + BIT7)   // 0/x/x/x Reserved
    #define CND003_PCIEPHYCFG_FRP01_OSSET_G2_PHYB_4_0  0x3E            // 0/0/x/x LEQ Offset Initial or Set Value
    #define CND003_PCIEPHYCFG_FRP01_OSSETEN_G2_PHYB    BIT0            // 0/0/x/x LEQ Offset Manual Set Enable
#define CND003_PCIEPHYCFG_EQUALIZER_ADAPTIVE_FRP_OSSET_LANE02_PHYB_G2 0x7A8 // Equalizer Adaptive FRP_OSSET Lane02 PHYB G2
    #define CND003_PCIEPHYCFG_RSVPCIEPHYCFG_7A8_7      (BIT6 + BIT7)   // 0/x/x/x Reserved
    #define CND003_PCIEPHYCFG_FRP02_OSSET_G2_PHYB_4_0  0x3E            // 0/0/x/x LEQ Offset Initial or Set Value
    #define CND003_PCIEPHYCFG_FRP02_OSSETEN_G2_PHYB    BIT0            // 0/0/x/x LEQ Offset Manual Set Enable
#define CND003_PCIEPHYCFG_EQUALIZER_ADAPTIVE_FRP_OSSET_LANE03_PHYB_G2 0x7A9 // Equalizer Adaptive FRP_OSSET Lane03 PHYB G2
    #define CND003_PCIEPHYCFG_RSVPCIEPHYCFG_7A9_7      (BIT6 + BIT7)   // 0/x/x/x Reserved
    #define CND003_PCIEPHYCFG_FRP03_OSSET_G2_PHYB_4_0  0x3E            // 0/0/x/x LEQ Offset Initial or Set Value
    #define CND003_PCIEPHYCFG_FRP03_OSSETEN_G2_PHYB    BIT0            // 0/0/x/x LEQ Offset Manual Set Enable
#define CND003_PCIEPHYCFG_EQUALIZER_ADAPTIVE_FRP_OSSET_LANE00_EP_G2 0x7AA // Equalizer Adaptive FRP_OSSET Lane00 EP G2
    #define CND003_PCIEPHYCFG_RSVPCIEPHYCFG_7AA_7      (BIT6 + BIT7)   // 0/x/x/x Reserved
    #define CND003_PCIEPHYCFG_FRP00_OSSET_G2_EP_4_0    0x3E            // 0/0/x/x LEQ Offset Initial or Set Value
    #define CND003_PCIEPHYCFG_FRP00_OSSETEN_G2_EP      BIT0            // 0/0/x/x LEQ Offset Manual Set Enable
#define CND003_PCIEPHYCFG_EQUALIZER_ADAPTIVE_FRP_OSSET_LANE01_EP_G2 0x7AB // Equalizer Adaptive FRP_OSSET Lane01 EP G2
    #define CND003_PCIEPHYCFG_RSVPCIEPHYCFG_7AB_7      (BIT6 + BIT7)   // 0/x/x/x Reserved
    #define CND003_PCIEPHYCFG_FRP01_OSSET_G2_EP_4_0    0x3E            // 0/0/x/x LEQ Offset Initial or Set Value
    #define CND003_PCIEPHYCFG_FRP01_OSSETEN_G2_EP      BIT0            // 0/0/x/x LEQ Offset Manual Set Enable
#define CND003_PCIEPHYCFG_EQUALIZER_ADAPTIVE_FRP_OSSET_LANE02_EP_G2 0x7AC // Equalizer Adaptive FRP_OSSET Lane02 EP G2
    #define CND003_PCIEPHYCFG_RSVPCIEPHYCFG_7AC_7      (BIT6 + BIT7)   // 0/x/x/x Reserved
    #define CND003_PCIEPHYCFG_FRP02_OSSET_G2_EP_4_0    0x3E            // 0/0/x/x LEQ Offset Initial or Set Value
    #define CND003_PCIEPHYCFG_FRP02_OSSETEN_G2_EP      BIT0            // 0/0/x/x LEQ Offset Manual Set Enable
#define CND003_PCIEPHYCFG_EQUALIZER_ADAPTIVE_FRP_OSSET_LANE03_EP_G2 0x7AD // Equalizer Adaptive FRP_OSSET Lane03 EP G2
    #define CND003_PCIEPHYCFG_RSVPCIEPHYCFG_7AD_7      (BIT6 + BIT7)   // 0/x/x/x Reserved
    #define CND003_PCIEPHYCFG_FRP03_OSSET_G2_EP_4_0    0x3E            // 0/0/x/x LEQ Offset Initial or Set Value
    #define CND003_PCIEPHYCFG_FRP03_OSSETEN_G2_EP      BIT0            // 0/0/x/x LEQ Offset Manual Set Enable
#define CND003_PCIEPHYCFG_EQUALIZER_ADAPTIVE_FRP_OSSET_LANE00_PHYC_G2 0x7AE // Equalizer Adaptive FRP_OSSET Lane00 PHYC G2
    #define CND003_PCIEPHYCFG_RSVPCIEPHYCFG_7AE_7 PCIEPHYCFG_EQUALIZER_ADAPTIVE_FRP_OSSET_LANE00_PHYC_G2 // 0/x/x/x Reserved
#define CND003_PCIEPHYCFG_EQUALIZER_ADAPTIVE_FRP_OSSET_LANE01_PHYC_G2 0x7AF // Equalizer Adaptive FRP_OSSET Lane01 PHYC G2
    #define CND003_PCIEPHYCFG_RSVPCIEPHYCFG_7AF_7 PCIEPHYCFG_EQUALIZER_ADAPTIVE_FRP_OSSET_LANE01_PHYC_G2 // 0/x/x/x Reserved
#define CND003_PCIEPHYCFG_RESERVED_Z41 0x7B0 // Reserved
    #define CND003_PCIEPHYCFG_RSVPCIEPHYCFG_7B0_7 PCIEPHYCFG_RESERVED_Z41 // 0/x/x/x Reserved
#define CND003_PCIEPHYCFG_EQUALIZER_ADAPTIVE_FRP_OSSET_LANE00_G3 0x7C0 // Equalizer Adaptive FRP_OSSET Lane00 G3
    #define CND003_PCIEPHYCFG_RSVPCIEPHYCFG_7C0_7 PCIEPHYCFG_EQUALIZER_ADAPTIVE_FRP_OSSET_LANE00_G3 // 0/x/x/x Reserved
#define CND003_PCIEPHYCFG_EQUALIZER_ADAPTIVE_FRP_OSSET_LANE04_PHYA_G3 0x7C1 // Equalizer Adaptive FRP_OSSET Lane04 PHYA G3
    #define CND003_PCIEPHYCFG_RSVPCIEPHYCFG_7C1_7      (BIT6 + BIT7)   // 0/x/x/x Reserved
    #define CND003_PCIEPHYCFG_FRP04_OSSET_G3_PHYA_4_0  0x3E            // 0/0/x/x LEQ Offset Initial or Set Value
    #define CND003_PCIEPHYCFG_FRP04_OSSETEN_G3_PHYA    BIT0            // 0/0/x/x LEQ Offset Manual Set Enable
#define CND003_PCIEPHYCFG_EQUALIZER_ADAPTIVE_FRP_OSSET_LANE00_PHYA_G3 0x7C2 // Equalizer Adaptive FRP_OSSET Lane00 PHYA G3
    #define CND003_PCIEPHYCFG_RSVPCIEPHYCFG_7C2_7      (BIT6 + BIT7)   // 0/x/x/x Reserved
    #define CND003_PCIEPHYCFG_FRP00_OSSET_G3_PHYA_4_0  0x3E            // 0/0/x/x LEQ Offset Initial or Set Value
    #define CND003_PCIEPHYCFG_FRP00_OSSETEN_G3_PHYA    BIT0            // 0/0/x/x LEQ Offset Manual Set Enable
#define CND003_PCIEPHYCFG_EQUALIZER_ADAPTIVE_FRP_OSSET_LANE01_PHYA_G3 0x7C3 // Equalizer Adaptive FRP_OSSET Lane01 PHYA G3
    #define CND003_PCIEPHYCFG_RSVPCIEPHYCFG_7C3_7      (BIT6 + BIT7)   // 0/x/x/x Reserved
    #define CND003_PCIEPHYCFG_FRP01_OSSET_G3_PHYA_4_0  0x3E            // 0/0/x/x LEQ Offset Initial or Set Value
    #define CND003_PCIEPHYCFG_FRP01_OSSETEN_G3_PHYA    BIT0            // 0/0/x/x LEQ Offset Manual Set Enable
#define CND003_PCIEPHYCFG_EQUALIZER_ADAPTIVE_FRP_OSSET_LANE02_PHYA_G3 0x7C4 // Equalizer Adaptive FRP_OSSET Lane02 PHYA G3
    #define CND003_PCIEPHYCFG_RSVPCIEPHYCFG_7C4_7      (BIT6 + BIT7)   // 0/x/x/x Reserved
    #define CND003_PCIEPHYCFG_FRP02_OSSET_G3_PHYA_4_0  0x3E            // 0/0/x/x LEQ Offset Initial or Set Value
    #define CND003_PCIEPHYCFG_FRP02_OSSETEN_G3_PHYA    BIT0            // 0/0/x/x LEQ Offset Manual Set Enable
#define CND003_PCIEPHYCFG_EQUALIZER_ADAPTIVE_FRP_OSSET_LANE03_PHYA_G3 0x7C5 // Equalizer Adaptive FRP_OSSET Lane03 PHYA G3
    #define CND003_PCIEPHYCFG_RSVPCIEPHYCFG_7C5_7      (BIT6 + BIT7)   // 0/x/x/x Reserved
    #define CND003_PCIEPHYCFG_FRP03_OSSET_G3_PHYA_4_0  0x3E            // 0/0/x/x LEQ Offset Initial or Set Value
    #define CND003_PCIEPHYCFG_FRP03_OSSETEN_G3_PHYA    BIT0            // 0/0/x/x LEQ Offset Manual Set Enable
#define CND003_PCIEPHYCFG_EQUALIZER_ADAPTIVE_FRP_OSSET_LANE00_PHYB_G3 0x7C6 // Equalizer Adaptive FRP_OSSET Lane00 PHYB G3
    #define CND003_PCIEPHYCFG_RSVPCIEPHYCFG_7C6_7      (BIT6 + BIT7)   // 0/x/x/x Reserved
    #define CND003_PCIEPHYCFG_FRP00_OSSET_G3_PHYB_4_0  0x3E            // 0/0/x/x LEQ Offset Initial or Set Value
    #define CND003_PCIEPHYCFG_FRP00_OSSETEN_G3_PHYB    BIT0            // 0/0/x/x LEQ Offset Manual Set Enable
#define CND003_PCIEPHYCFG_EQUALIZER_ADAPTIVE_FRP_OSSET_LANE01_PHYB_G3 0x7C7 // Equalizer Adaptive FRP_OSSET Lane01 PHYB G3
    #define CND003_PCIEPHYCFG_RSVPCIEPHYCFG_7C7_7      (BIT6 + BIT7)   // 0/x/x/x Reserved
    #define CND003_PCIEPHYCFG_FRP01_OSSET_G3_PHYB_4_0  0x3E            // 0/0/x/x LEQ Offset Initial or Set Value
    #define CND003_PCIEPHYCFG_FRP01_OSSETEN_G3_PHYB    BIT0            // 0/0/x/x LEQ Offset Manual Set Enable
#define CND003_PCIEPHYCFG_EQUALIZER_ADAPTIVE_FRP_OSSET_LANE02_PHYB_G3 0x7C8 // Equalizer Adaptive FRP_OSSET Lane02 PHYB G3
    #define CND003_PCIEPHYCFG_RSVPCIEPHYCFG_7C8_7      (BIT6 + BIT7)   // 0/x/x/x Reserved
    #define CND003_PCIEPHYCFG_FRP02_OSSET_G3_PHYB_4_0  0x3E            // 0/0/x/x LEQ Offset Initial or Set Value
    #define CND003_PCIEPHYCFG_FRP02_OSSETEN_G3_PHYB    BIT0            // 0/0/x/x LEQ Offset Manual Set Enable
#define CND003_PCIEPHYCFG_EQUALIZER_ADAPTIVE_FRP_OSSET_LANE03_PHYB_G3 0x7C9 // Equalizer Adaptive FRP_OSSET Lane03 PHYB G3
    #define CND003_PCIEPHYCFG_RSVPCIEPHYCFG_7C9_7      (BIT6 + BIT7)   // 0/x/x/x Reserved
    #define CND003_PCIEPHYCFG_FRP03_OSSET_G3_PHYB_4_0  0x3E            // 0/0/x/x LEQ Offset Initial or Set Value
    #define CND003_PCIEPHYCFG_FRP03_OSSETEN_G3_PHYB    BIT0            // 0/0/x/x LEQ Offset Manual Set Enable
#define CND003_PCIEPHYCFG_EQUALIZER_ADAPTIVE_FRP_OSSET_LANE00_EP_G3 0x7CA // Equalizer Adaptive FRP_OSSET Lane00 EP G3
    #define CND003_PCIEPHYCFG_RSVPCIEPHYCFG_7CA_7      (BIT6 + BIT7)   // 0/x/x/x Reserved
    #define CND003_PCIEPHYCFG_FRP00_OSSET_G3_EP_4_0    0x3E            // 0/0/x/x LEQ Offset Initial or Set Value
    #define CND003_PCIEPHYCFG_FRP00_OSSETEN_G3_EP      BIT0            // 0/0/x/x LEQ Offset Manual Set Enable
#define CND003_PCIEPHYCFG_EQUALIZER_ADAPTIVE_FRP_OSSET_LANE01_EP_G3 0x7CB // Equalizer Adaptive FRP_OSSET Lane01 EP G3
    #define CND003_PCIEPHYCFG_RSVPCIEPHYCFG_7CB_7      (BIT6 + BIT7)   // 0/x/x/x Reserved
    #define CND003_PCIEPHYCFG_FRP01_OSSET_G3_EP_4_0    0x3E            // 0/0/x/x LEQ Offset Initial or Set Value
    #define CND003_PCIEPHYCFG_FRP01_OSSETEN_G3_EP      BIT0            // 0/0/x/x LEQ Offset Manual Set Enable
#define CND003_PCIEPHYCFG_EQUALIZER_ADAPTIVE_FRP_OSSET_LANE02_EP_G3 0x7CC // Equalizer Adaptive FRP_OSSET Lane02 EP G3
    #define CND003_PCIEPHYCFG_RSVPCIEPHYCFG_7CC_7      (BIT6 + BIT7)   // 0/x/x/x Reserved
    #define CND003_PCIEPHYCFG_FRP02_OSSET_G3_EP_4_0    0x3E            // 0/0/x/x LEQ Offset Initial or Set Value
    #define CND003_PCIEPHYCFG_FRP02_OSSETEN_G3_EP      BIT0            // 0/0/x/x LEQ Offset Manual Set Enable
#define CND003_PCIEPHYCFG_EQUALIZER_ADAPTIVE_FRP_OSSET_LANE03_EP_G3 0x7CD // Equalizer Adaptive FRP_OSSET Lane03 EP G3
    #define CND003_PCIEPHYCFG_RSVPCIEPHYCFG_7CD_7      (BIT6 + BIT7)   // 0/x/x/x Reserved
    #define CND003_PCIEPHYCFG_FRP03_OSSET_G3_EP_4_0    0x3E            // 0/0/x/x LEQ Offset Initial or Set Value
    #define CND003_PCIEPHYCFG_FRP03_OSSETEN_G3_EP      BIT0            // 0/0/x/x LEQ Offset Manual Set Enable
#define CND003_PCIEPHYCFG_EQUALIZER_ADAPTIVE_FRP_OSSET_LANE00_PHYC_G3 0x7CE // Equalizer Adaptive FRP_OSSET Lane00 PHYC G3
    #define CND003_PCIEPHYCFG_RSVPCIEPHYCFG_7CE_7 PCIEPHYCFG_EQUALIZER_ADAPTIVE_FRP_OSSET_LANE00_PHYC_G3 // 0/x/x/x Reserved
#define CND003_PCIEPHYCFG_EQUALIZER_ADAPTIVE_FRP_OSSET_LANE01_PHYC_G3 0x7CF // Equalizer Adaptive FRP_OSSET Lane01 PHYC G3
    #define CND003_PCIEPHYCFG_RSVPCIEPHYCFG_7CF_7 PCIEPHYCFG_EQUALIZER_ADAPTIVE_FRP_OSSET_LANE01_PHYC_G3 // 0/x/x/x Reserved
#define CND003_PCIEPHYCFG_RESERVED_Z42 0x7D0 // Reserved
    #define CND003_PCIEPHYCFG_RSVPCIEPHYCFG_7D3_7 PCIEPHYCFG_RESERVED_Z42 // 0/x/x/x Reserved
#define CND003_PCIEPHYCFG_EQUALIZER_ADAPTIVE_W1SET_LANE00_G1 0x800 // Equalizer Adaptive W1SET Lane00 G1
    #define CND003_PCIEPHYCFG_RSVPCIEPHYCFG_800_7 PCIEPHYCFG_EQUALIZER_ADAPTIVE_W1SET_LANE00_G1 // 0/x/x/X Reserved
#define CND003_PCIEPHYCFG_EQUALIZER_ADAPTIVE_W1SET_LANE04_PHYA_G1 0x801 // Equalizer Adaptive W1SET Lane04 PHYA G1
    #define CND003_PCIEPHYCFG_RSVPCIEPHYCFG_801_7      (BIT6 + BIT7)   // 0/x/x/x Reserved
    #define CND003_PCIEPHYCFG_FRP04_W1SET_G1_PHYA_4_0  0x3E            // 00001b/00001/x/x DFE Weight1 Initial or Set Value
    #define CND003_PCIEPHYCFG_FRP04_W1SETEN_G1_PHYA    BIT0            // 0/0/x/x DFE Weight1 Manual Set Enable
#define CND003_PCIEPHYCFG_EQUALIZER_ADAPTIVE_W1SET_LANE00_PHYA_G1 0x802 // Equalizer Adaptive W1SET Lane00 PHYA G1
    #define CND003_PCIEPHYCFG_RSVPCIEPHYCFG_802_7      (BIT6 + BIT7)   // 0/x/x/x Reserved
    #define CND003_PCIEPHYCFG_FRP00_W1SET_G1_PHYA_4_0  0x3E            // 00001b/00001/x/x DFE Weight1 Initial or Set Value
    #define CND003_PCIEPHYCFG_FRP00_W1SETEN_G1_PHYA    BIT0            // 0/0/x/x DFE Weight1 Manual Set Enable
#define CND003_PCIEPHYCFG_EQUALIZER_ADAPTIVE_W1SET_LANE01_PHYA_G1 0x803 // Equalizer Adaptive W1SET Lane01 PHYA G1
    #define CND003_PCIEPHYCFG_RSVPCIEPHYCFG_803_7      (BIT6 + BIT7)   // 0/x/x/x Reserved
    #define CND003_PCIEPHYCFG_FRP01_W1SET_G1_PHYA_4_0  0x3E            // 00001b/00001/x/x DFE Weight1 Initial or Set Value
    #define CND003_PCIEPHYCFG_FRP01_W1SETEN_G1_PHYA    BIT0            // 0/0/x/x DFE Weight1 Manual Set Enable
#define CND003_PCIEPHYCFG_EQUALIZER_ADAPTIVE_W1SET_LANE02_PHYA_G1 0x804 // Equalizer Adaptive W1SET Lane02 PHYA G1
    #define CND003_PCIEPHYCFG_RSVPCIEPHYCFG_804_7      (BIT6 + BIT7)   // 0/x/x/x Reserved
    #define CND003_PCIEPHYCFG_FRP02_W1SET_G1_PHYA_4_0  0x3E            // 00001b/00001/x/x DFE Weight1 Initial or Set Value
    #define CND003_PCIEPHYCFG_FRP02_W1SETEN_G1_PHYA    BIT0            // 0/0/x/x DFE Weight1 Manual Set Enable
#define CND003_PCIEPHYCFG_EQUALIZER_ADAPTIVE_W1SET_LANE03_PHYA_G1 0x805 // Equalizer Adaptive W1SET Lane03 PHYA G1
    #define CND003_PCIEPHYCFG_RSVPCIEPHYCFG_805_7      (BIT6 + BIT7)   // 0/x/x/x Reserved
    #define CND003_PCIEPHYCFG_FRP03_W1SET_G1_PHYA_4_0  0x3E            // 00001b/00001/x/x DFE Weight1 Initial or Set Value
    #define CND003_PCIEPHYCFG_FRP03_W1SETEN_G1_PHYA    BIT0            // 0/0/x/x DFE Weight1 Manual Set Enable
#define CND003_PCIEPHYCFG_EQUALIZER_ADAPTIVE_W1SET_LANE00_PHYB_G1 0x806 // Equalizer Adaptive W1SET Lane00 PHYB G1
    #define CND003_PCIEPHYCFG_RSVPCIEPHYCFG_806_7      (BIT6 + BIT7)   // 0/x/x/x Reserved
    #define CND003_PCIEPHYCFG_FRP00_W1SET_G1_PHYB_4_0  0x3E            // 00001b/00001/x/x DFE Weight1 Initial or Set Value
    #define CND003_PCIEPHYCFG_FRP00_W1SETEN_G1_PHYB    BIT0            // 0/0/x/x DFE Weight1 Manual Set Enable
#define CND003_PCIEPHYCFG_EQUALIZER_ADAPTIVE_W1SET_LANE01_PHYB_G1 0x807 // Equalizer Adaptive W1SET Lane01 PHYB G1
    #define CND003_PCIEPHYCFG_RSVPCIEPHYCFG_807_7      (BIT6 + BIT7)   // 0/x/x/x Reserved
    #define CND003_PCIEPHYCFG_FRP01_W1SET_G1_PHYB_4_0  0x3E            // 00001b/00001/x/x DFE Weight1 Initial or Set Value
    #define CND003_PCIEPHYCFG_FRP01_W1SETEN_G1_PHYB    BIT0            // 0/0/x/x DFE Weight1 Manual Set Enable
#define CND003_PCIEPHYCFG_EQUALIZER_ADAPTIVE_W1SET_LANE02_PHYB_G1 0x808 // Equalizer Adaptive W1SET Lane02 PHYB G1
    #define CND003_PCIEPHYCFG_RSVPCIEPHYCFG_808_7      (BIT6 + BIT7)   // 0/x/x/x Reserved
    #define CND003_PCIEPHYCFG_FRP02_W1SET_G1_PHYB_4_0  0x3E            // 00001b/00001/x/x DFE Weight1 Initial or Set Value
    #define CND003_PCIEPHYCFG_FRP02_W1SETEN_G1_PHYB    BIT0            // 0/0/x/x DFE Weight1 Manual Set Enable
#define CND003_PCIEPHYCFG_EQUALIZER_ADAPTIVE_W1SET_LANE03_PHYB_G1 0x809 // Equalizer Adaptive W1SET Lane03 PHYB G1
    #define CND003_PCIEPHYCFG_RSVPCIEPHYCFG_809_7      (BIT6 + BIT7)   // 0/x/x/x Reserved
    #define CND003_PCIEPHYCFG_FRP03_W1SET_G1_PHYB_4_0  0x3E            // 00001b/00001/x/x DFE Weight1 Initial or Set Value
    #define CND003_PCIEPHYCFG_FRP03_W1SETEN_G1_PHYB    BIT0            // 0/0/x/x DFE Weight1 Manual Set Enable
#define CND003_PCIEPHYCFG_EQUALIZER_ADAPTIVE_W1SET_LANE00_EP_G1 0x80A // Equalizer Adaptive W1SET Lane00 EP G1
    #define CND003_PCIEPHYCFG_RSVPCIEPHYCFG_80A_7      (BIT6 + BIT7)   // 0/x/x/x Reserved
    #define CND003_PCIEPHYCFG_FRP00_W1SET_G1_EP_4_0    0x3E            // 00001b/00001/x/x DFE Weight1 Initial or Set Value
    #define CND003_PCIEPHYCFG_FRP00_W1SETEN_G1_EP      BIT0            // 0/0/x/x DFE Weight1 Manual Set Enable
#define CND003_PCIEPHYCFG_EQUALIZER_ADAPTIVE_W1SET_LANE01_EP_G1 0x80B // Equalizer Adaptive W1SET Lane01 EP G1
    #define CND003_PCIEPHYCFG_RSVPCIEPHYCFG_80B_7      (BIT6 + BIT7)   // 0/x/x/x Reserved
    #define CND003_PCIEPHYCFG_FRP01_W1SET_G1_EP_4_0    0x3E            // 00001b/00001/x/x DFE Weight1 Initial or Set Value
    #define CND003_PCIEPHYCFG_FRP01_W1SETEN_G1_EP      BIT0            // 0/0/x/x DFE Weight1 Manual Set Enable
#define CND003_PCIEPHYCFG_EQUALIZER_ADAPTIVE_W1SET_LANE02_EP_G1 0x80C // Equalizer Adaptive W1SET Lane02 EP G1
    #define CND003_PCIEPHYCFG_RSVPCIEPHYCFG_80C_7      (BIT6 + BIT7)   // 0/x/x/x Reserved
    #define CND003_PCIEPHYCFG_FRP02_W1SET_G1_EP_4_0    0x3E            // 00001b/00001/x/x DFE Weight1 Initial or Set Value
    #define CND003_PCIEPHYCFG_FRP02_W1SETEN_G1_EP      BIT0            // 0/0/x/x DFE Weight1 Manual Set Enable
#define CND003_PCIEPHYCFG_EQUALIZER_ADAPTIVE_W1SET_LANE03_EP_G1 0x80D // Equalizer Adaptive W1SET Lane03 EP G1
    #define CND003_PCIEPHYCFG_RSVPCIEPHYCFG_80D_7      (BIT6 + BIT7)   // 0/x/x/x Reserved
    #define CND003_PCIEPHYCFG_FRP03_W1SET_G1_EP_4_0    0x3E            // 00001b/00001/x/x DFE Weight1 Initial or Set Value
    #define CND003_PCIEPHYCFG_FRP03_W1SETEN_G1_EP      BIT0            // 0/0/x/x DFE Weight1 Manual Set Enable
#define CND003_PCIEPHYCFG_EQUALIZER_ADAPTIVE_W1SET_LANE00_PHYC_G1 0x80E // Equalizer Adaptive W1SET Lane00 PHYC G1
    #define CND003_PCIEPHYCFG_RSVPCIEPHYCFG_80E_7 PCIEPHYCFG_EQUALIZER_ADAPTIVE_W1SET_LANE00_PHYC_G1 // 0/x/x/X Reserved
#define CND003_PCIEPHYCFG_EQUALIZER_ADAPTIVE_W1SET_LANE00_PHYC_G1_Z1 0x80F // Equalizer Adaptive W1SET Lane00 PHYC G1
    #define CND003_PCIEPHYCFG_RSVPCIEPHYCFG_80F_7 PCIEPHYCFG_EQUALIZER_ADAPTIVE_W1SET_LANE00_PHYC_G1_Z1 // 0/x/x/x Reserved
#define CND003_PCIEPHYCFG_RESERVED_Z43 0x810 // Reserved
    #define CND003_PCIEPHYCFG_RSVPCIEPHYCFG_810_7 PCIEPHYCFG_RESERVED_Z43 // 0/x/x/x Reserved
#define CND003_PCIEPHYCFG_EQUALIZER_ADAPTIVE_W1SET_LANE00_G2 0x820 // Equalizer Adaptive W1SET Lane00 G2
    #define CND003_PCIEPHYCFG_RSVPCIEPHYCFG_820_7 PCIEPHYCFG_EQUALIZER_ADAPTIVE_W1SET_LANE00_G2 // 0/x/x/X Reserved
#define CND003_PCIEPHYCFG_EQUALIZER_ADAPTIVE_W1SET_LANE04_PHYA_G2 0x821 // Equalizer Adaptive W1SET Lane04 PHYA G2
    #define CND003_PCIEPHYCFG_RSVPCIEPHYCFG_821_7      (BIT6 + BIT7)   // 0/x/x/x Reserved
    #define CND003_PCIEPHYCFG_FRP04_W1SET_G2_PHYA_4_0  0x3E            // 00001b/00001/x/x DFE Weight1 Initial or Set Value
    #define CND003_PCIEPHYCFG_FRP04_W1SETEN_G2_PHYA    BIT0            // 0/0/x/x DFE Weight1 Manual Set Enable
#define CND003_PCIEPHYCFG_EQUALIZER_ADAPTIVE_W1SET_LANE00_PHYA_G2 0x822 // Equalizer Adaptive W1SET Lane00 PHYA G2
    #define CND003_PCIEPHYCFG_RSVPCIEPHYCFG_822_7      (BIT6 + BIT7)   // 0/x/x/x Reserved
    #define CND003_PCIEPHYCFG_FRP00_W1SET_G2_PHYA_4_0  0x3E            // 00001b/00001/x/x DFE Weight1 Initial or Set Value
    #define CND003_PCIEPHYCFG_FRP00_W1SETEN_G2_PHYA    BIT0            // 0/0/x/x DFE Weight1 Manual Set Enable
#define CND003_PCIEPHYCFG_EQUALIZER_ADAPTIVE_W1SET_LANE01_PHYA_G2 0x823 // Equalizer Adaptive W1SET Lane01 PHYA G2
    #define CND003_PCIEPHYCFG_RSVPCIEPHYCFG_823_7      (BIT6 + BIT7)   // 0/x/x/x Reserved
    #define CND003_PCIEPHYCFG_FRP01_W1SET_G2_PHYA_4_0  0x3E            // 00001b/00001/x/x DFE Weight1 Initial or Set Value
    #define CND003_PCIEPHYCFG_FRP01_W1SETEN_G2_PHYA    BIT0            // 0/0/x/x DFE Weight1 Manual Set Enable
#define CND003_PCIEPHYCFG_EQUALIZER_ADAPTIVE_W1SET_LANE02_PHYA_G2 0x824 // Equalizer Adaptive W1SET Lane02 PHYA G2
    #define CND003_PCIEPHYCFG_RSVPCIEPHYCFG_824_7      (BIT6 + BIT7)   // 0/x/x/x Reserved
    #define CND003_PCIEPHYCFG_FRP02_W1SET_G2_PHYA_4_0  0x3E            // 00001b/00001/x/x DFE Weight1 Initial or Set Value
    #define CND003_PCIEPHYCFG_FRP02_W1SETEN_G2_PHYA    BIT0            // 0/0/x/x DFE Weight1 Manual Set Enable
#define CND003_PCIEPHYCFG_EQUALIZER_ADAPTIVE_W1SET_LANE03_PHYA_G2 0x825 // Equalizer Adaptive W1SET Lane03 PHYA G2
    #define CND003_PCIEPHYCFG_RSVPCIEPHYCFG_825_7      (BIT6 + BIT7)   // 0/x/x/x Reserved
    #define CND003_PCIEPHYCFG_FRP03_W1SET_G2_PHYA_4_0  0x3E            // 00001b/00001/x/x DFE Weight1 Initial or Set Value
    #define CND003_PCIEPHYCFG_FRP03_W1SETEN_G2_PHYA    BIT0            // 0/0/x/x DFE Weight1 Manual Set Enable
#define CND003_PCIEPHYCFG_EQUALIZER_ADAPTIVE_W1SET_LANE00_PHYB_G2 0x826 // Equalizer Adaptive W1SET Lane00 PHYB G2
    #define CND003_PCIEPHYCFG_RSVPCIEPHYCFG_826_7      (BIT6 + BIT7)   // 0/x/x/x Reserved
    #define CND003_PCIEPHYCFG_FRP00_W1SET_G2_PHYB_4_0  0x3E            // 00001b/00001/x/x DFE Weight1 Initial or Set Value
    #define CND003_PCIEPHYCFG_FRP00_W1SETEN_G2_PHYB    BIT0            // 0/0/x/x DFE Weight1 Manual Set Enable
#define CND003_PCIEPHYCFG_EQUALIZER_ADAPTIVE_W1SET_LANE01_PHYB_G2 0x827 // Equalizer Adaptive W1SET Lane01 PHYB G2
    #define CND003_PCIEPHYCFG_RSVPCIEPHYCFG_827_7      (BIT6 + BIT7)   // 0/x/x/x Reserved
    #define CND003_PCIEPHYCFG_FRP01_W1SET_G2_PHYB_4_0  0x3E            // 00001b/00001/x/x DFE Weight1 Initial or Set Value
    #define CND003_PCIEPHYCFG_FRP01_W1SETEN_G2_PHYB    BIT0            // 0/0/x/x DFE Weight1 Manual Set Enable
#define CND003_PCIEPHYCFG_EQUALIZER_ADAPTIVE_W1SET_LANE02_PHYB_G2 0x828 // Equalizer Adaptive W1SET Lane02 PHYB G2
    #define CND003_PCIEPHYCFG_RSVPCIEPHYCFG_828_7      (BIT6 + BIT7)   // 0/x/x/x Reserved
    #define CND003_PCIEPHYCFG_FRP02_W1SET_G2_PHYB_4_0  0x3E            // 00001b/00001/x/x DFE Weight1 Initial or Set Value
    #define CND003_PCIEPHYCFG_FRP02_W1SETEN_G2_PHYB    BIT0            // 0/0/x/x DFE Weight1 Manual Set Enable
#define CND003_PCIEPHYCFG_EQUALIZER_ADAPTIVE_W1SET_LANE03_PHYB_G2 0x829 // Equalizer Adaptive W1SET Lane03 PHYB G2
    #define CND003_PCIEPHYCFG_RSVPCIEPHYCFG_829_7      (BIT6 + BIT7)   // 0/x/x/x Reserved
    #define CND003_PCIEPHYCFG_FRP03_W1SET_G2_PHYB_4_0  0x3E            // 00001b/00001/x/x DFE Weight1 Initial or Set Value
    #define CND003_PCIEPHYCFG_FRP03_W1SETEN_G2_PHYB    BIT0            // 0/0/x/x DFE Weight1 Manual Set Enable
#define CND003_PCIEPHYCFG_EQUALIZER_ADAPTIVE_W1SET_LANE00_EP_G2 0x82A // Equalizer Adaptive W1SET Lane00 EP G2
    #define CND003_PCIEPHYCFG_RSVPCIEPHYCFG_82A_7      (BIT6 + BIT7)   // 0/x/x/x Reserved
    #define CND003_PCIEPHYCFG_FRP00_W1SET_G2_EP_4_0    0x3E            // 00001b/00001/x/x DFE Weight1 Initial or Set Value
    #define CND003_PCIEPHYCFG_FRP00_W1SETEN_G2_EP      BIT0            // 0/0/x/x DFE Weight1 Manual Set Enable
#define CND003_PCIEPHYCFG_EQUALIZER_ADAPTIVE_W1SET_LANE01_EP_G2 0x82B // Equalizer Adaptive W1SET Lane01 EP G2
    #define CND003_PCIEPHYCFG_RSVPCIEPHYCFG_82B_7      (BIT6 + BIT7)   // 0/x/x/x Reserved
    #define CND003_PCIEPHYCFG_FRP01_W1SET_G2_EP_4_0    0x3E            // 00001b/00001/x/x DFE Weight1 Initial or Set Value
    #define CND003_PCIEPHYCFG_FRP01_W1SETEN_G2_EP      BIT0            // 0/0/x/x DFE Weight1 Manual Set Enable
#define CND003_PCIEPHYCFG_EQUALIZER_ADAPTIVE_W1SET_LANE02_EP_G2 0x82C // Equalizer Adaptive W1SET Lane02 EP G2
    #define CND003_PCIEPHYCFG_RSVPCIEPHYCFG_82C_7      (BIT6 + BIT7)   // 0/x/x/x Reserved
    #define CND003_PCIEPHYCFG_FRP02_W1SET_G2_EP_4_0    0x3E            // 00001b/00001/x/x DFE Weight1 Initial or Set Value
    #define CND003_PCIEPHYCFG_FRP02_W1SETEN_G2_EP      BIT0            // 0/0/x/x DFE Weight1 Manual Set Enable
#define CND003_PCIEPHYCFG_EQUALIZER_ADAPTIVE_W1SET_LANE03_EP_G2 0x82D // Equalizer Adaptive W1SET Lane03 EP G2
    #define CND003_PCIEPHYCFG_RSVPCIEPHYCFG_82D_7      (BIT6 + BIT7)   // 0/x/x/x Reserved
    #define CND003_PCIEPHYCFG_FRP03_W1SET_G2_EP_4_0    0x3E            // 00001b/00001/x/x DFE Weight1 Initial or Set Value
    #define CND003_PCIEPHYCFG_FRP03_W1SETEN_G2_EP      BIT0            // 0/0/x/x DFE Weight1 Manual Set Enable
#define CND003_PCIEPHYCFG_EQUALIZER_ADAPTIVE_W1SET_LANE00_PHYC_G2 0x82E // Equalizer Adaptive W1SET Lane00 PHYC G2
    #define CND003_PCIEPHYCFG_RSVPCIEPHYCFG_82E_7 PCIEPHYCFG_EQUALIZER_ADAPTIVE_W1SET_LANE00_PHYC_G2 // 0/x/x/X Reserved
#define CND003_PCIEPHYCFG_EQUALIZER_ADAPTIVE_W1SET_LANE01_PHYC_G2 0x82F // Equalizer Adaptive W1SET Lane01 PHYC G2
    #define CND003_PCIEPHYCFG_RSVPCIEPHYCFG_82F_7 PCIEPHYCFG_EQUALIZER_ADAPTIVE_W1SET_LANE01_PHYC_G2 // 0/x/x/x Reserved
#define CND003_PCIEPHYCFG_RESERVED_Z44 0x830 // Reserved
    #define CND003_PCIEPHYCFG_RSVPCIEPHYCFG_830_7 PCIEPHYCFG_RESERVED_Z44 // 0/x/x/x Reserved
#define CND003_PCIEPHYCFG_EQUALIZER_ADAPTIVE_W1SET_LANE00_G3 0x840 // Equalizer Adaptive W1SET Lane00 G3
    #define CND003_PCIEPHYCFG_RSVPCIEPHYCFG_840_7 PCIEPHYCFG_EQUALIZER_ADAPTIVE_W1SET_LANE00_G3 // 0/x/x/X Reserved
#define CND003_PCIEPHYCFG_EQUALIZER_ADAPTIVE_W1SET_LANE04_PHYA_G3 0x841 // Equalizer Adaptive W1SET Lane04 PHYA G3
    #define CND003_PCIEPHYCFG_RSVPCIEPHYCFG_841_7      (BIT6 + BIT7)   // 0/x/x/x Reserved
    #define CND003_PCIEPHYCFG_FRP04_W1SET_G3_PHYA_4_0  0x3E            // 00001b/00001/x/x DFE Weight1 Initial or Set Value
    #define CND003_PCIEPHYCFG_FRP04_W1SETEN_G3_PHYA    BIT0            // 0/0/x/x DFE Weight1 Manual Set Enable
#define CND003_PCIEPHYCFG_EQUALIZER_ADAPTIVE_W1SET_LANE00_PHYA_G3 0x842 // Equalizer Adaptive W1SET Lane00 PHYA G3
    #define CND003_PCIEPHYCFG_RSVPCIEPHYCFG_842_7      (BIT6 + BIT7)   // 0/x/x/x Reserved
    #define CND003_PCIEPHYCFG_FRP00_W1SET_G3_PHYA_4_0  0x3E            // 00001b/00001/x/x DFE Weight1 Initial or Set Value
    #define CND003_PCIEPHYCFG_FRP00_W1SETEN_G3_PHYA    BIT0            // 0/0/x/x DFE Weight1 Manual Set Enable
#define CND003_PCIEPHYCFG_EQUALIZER_ADAPTIVE_W1SET_LANE01_PHYA_G3 0x843 // Equalizer Adaptive W1SET Lane01 PHYA G3
    #define CND003_PCIEPHYCFG_RSVPCIEPHYCFG_843_7      (BIT6 + BIT7)   // 0/x/x/x Reserved
    #define CND003_PCIEPHYCFG_FRP01_W1SET_G3_PHYA_4_0  0x3E            // 00001b/00001/x/x DFE Weight1 Initial or Set Value
    #define CND003_PCIEPHYCFG_FRP01_W1SETEN_G3_PHYA    BIT0            // 0/0/x/x DFE Weight1 Manual Set Enable
#define CND003_PCIEPHYCFG_EQUALIZER_ADAPTIVE_W1SET_LANE02_PHYA_G3 0x844 // Equalizer Adaptive W1SET Lane02 PHYA G3
    #define CND003_PCIEPHYCFG_RSVPCIEPHYCFG_844_7      (BIT6 + BIT7)   // 0/x/x/x Reserved
    #define CND003_PCIEPHYCFG_FRP02_W1SET_G3_PHYA_4_0  0x3E            // 00001b/00001/x/x DFE Weight1 Initial or Set Value
    #define CND003_PCIEPHYCFG_FRP02_W1SETEN_G3_PHYA    BIT0            // 0/0/x/x DFE Weight1 Manual Set Enable
#define CND003_PCIEPHYCFG_EQUALIZER_ADAPTIVE_W1SET_LANE03_PHYA_G3 0x845 // Equalizer Adaptive W1SET Lane03 PHYA G3
    #define CND003_PCIEPHYCFG_RSVPCIEPHYCFG_845_7      (BIT6 + BIT7)   // 0/x/x/x Reserved
    #define CND003_PCIEPHYCFG_FRP03_W1SET_G3_PHYA_4_0  0x3E            // 00001b/00001/x/x DFE Weight1 Initial or Set Value
    #define CND003_PCIEPHYCFG_FRP03_W1SETEN_G3_PHYA    BIT0            // 0/0/x/x DFE Weight1 Manual Set Enable
#define CND003_PCIEPHYCFG_EQUALIZER_ADAPTIVE_W1SET_LANE00_PHYB_G3 0x846 // Equalizer Adaptive W1SET Lane00 PHYB G3
    #define CND003_PCIEPHYCFG_RSVPCIEPHYCFG_846_7      (BIT6 + BIT7)   // 0/x/x/x Reserved
    #define CND003_PCIEPHYCFG_FRP00_W1SET_G3_PHYB_4_0  0x3E            // 00001b/00001/x/x DFE Weight1 Initial or Set Value
    #define CND003_PCIEPHYCFG_FRP00_W1SETEN_G3_PHYB    BIT0            // 0/0/x/x DFE Weight1 Manual Set Enable
#define CND003_PCIEPHYCFG_EQUALIZER_ADAPTIVE_W1SET_LANE01_PHYB_G3 0x847 // Equalizer Adaptive W1SET Lane01 PHYB G3
    #define CND003_PCIEPHYCFG_RSVPCIEPHYCFG_847_7      (BIT6 + BIT7)   // 0/x/x/x Reserved
    #define CND003_PCIEPHYCFG_FRP01_W1SET_G3_PHYB_4_0  0x3E            // 00001b/00001/x/x DFE Weight1 Initial or Set Value
    #define CND003_PCIEPHYCFG_FRP01_W1SETEN_G3_PHYB    BIT0            // 0/0/x/x DFE Weight1 Manual Set Enable
#define CND003_PCIEPHYCFG_EQUALIZER_ADAPTIVE_W1SET_LANE02_PHYB_G3 0x848 // Equalizer Adaptive W1SET Lane02 PHYB G3
    #define CND003_PCIEPHYCFG_RSVPCIEPHYCFG_848_7      (BIT6 + BIT7)   // 0/x/x/x Reserved
    #define CND003_PCIEPHYCFG_FRP02_W1SET_G3_PHYB_4_0  0x3E            // 00001b/00001/x/x DFE Weight1 Initial or Set Value
    #define CND003_PCIEPHYCFG_FRP02_W1SETEN_G3_PHYB    BIT0            // 0/0/x/x DFE Weight1 Manual Set Enable
#define CND003_PCIEPHYCFG_EQUALIZER_ADAPTIVE_W1SET_LANE03_PHYB_G3 0x849 // Equalizer Adaptive W1SET Lane03 PHYB G3
    #define CND003_PCIEPHYCFG_RSVPCIEPHYCFG_849_7      (BIT6 + BIT7)   // 0/x/x/x Reserved
    #define CND003_PCIEPHYCFG_FRP03_W1SET_G3_PHYB_4_0  0x3E            // 00001b/00001/x/x DFE Weight1 Initial or Set Value
    #define CND003_PCIEPHYCFG_FRP03_W1SETEN_G3_PHYB    BIT0            // 0/0/x/x DFE Weight1 Manual Set Enable
#define CND003_PCIEPHYCFG_EQUALIZER_ADAPTIVE_W1SET_LANE00_EP_G3 0x84A // Equalizer Adaptive W1SET Lane00 EP G3
    #define CND003_PCIEPHYCFG_RSVPCIEPHYCFG_84A_7      (BIT6 + BIT7)   // 0/x/x/x Reserved
    #define CND003_PCIEPHYCFG_FRP00_W1SET_G3_EP_4_0    0x3E            // 00001b/00001/x/x DFE Weight1 Initial or Set Value
    #define CND003_PCIEPHYCFG_FRP00_W1SETEN_G3_EP      BIT0            // 0/0/x/x DFE Weight1 Manual Set Enable
#define CND003_PCIEPHYCFG_EQUALIZER_ADAPTIVE_W1SET_LANE01_EP_G3 0x84B // Equalizer Adaptive W1SET Lane01 EP G3
    #define CND003_PCIEPHYCFG_RSVPCIEPHYCFG_84B_7      (BIT6 + BIT7)   // 0/x/x/x Reserved
    #define CND003_PCIEPHYCFG_FRP01_W1SET_G3_EP_4_0    0x3E            // 00001b/00001/x/x DFE Weight1 Initial or Set Value
    #define CND003_PCIEPHYCFG_FRP01_W1SETEN_G3_EP      BIT0            // 0/0/x/x DFE Weight1 Manual Set Enable
#define CND003_PCIEPHYCFG_EQUALIZER_ADAPTIVE_W1SET_LANE02_EP_G3 0x84C // Equalizer Adaptive W1SET Lane02 EP G3
    #define CND003_PCIEPHYCFG_RSVPCIEPHYCFG_84C_7      (BIT6 + BIT7)   // 0/x/x/x Reserved
    #define CND003_PCIEPHYCFG_FRP02_W1SET_G3_EP_4_0    0x3E            // 00001b/00001/x/x DFE Weight1 Initial or Set Value
    #define CND003_PCIEPHYCFG_FRP02_W1SETEN_G3_EP      BIT0            // 0/0/x/x DFE Weight1 Manual Set Enable
#define CND003_PCIEPHYCFG_EQUALIZER_ADAPTIVE_W1SET_LANE03_EP_G3 0x84D // Equalizer Adaptive W1SET Lane03 EP G3
    #define CND003_PCIEPHYCFG_RSVPCIEPHYCFG_84D_7      (BIT6 + BIT7)   // 0/x/x/x Reserved
    #define CND003_PCIEPHYCFG_FRP03_W1SET_G3_EP_4_0    0x3E            // 00001b/00001/x/x DFE Weight1 Initial or Set Value
    #define CND003_PCIEPHYCFG_FRP03_W1SETEN_G3_EP      BIT0            // 0/0/x/x DFE Weight1 Manual Set Enable
#define CND003_PCIEPHYCFG_EQUALIZER_ADAPTIVE_W1SET_LANE00_PHYC_G3 0x84E // Equalizer Adaptive W1SET Lane00 PHYC G3
    #define CND003_PCIEPHYCFG_RSVPCIEPHYCFG_84E_7 PCIEPHYCFG_EQUALIZER_ADAPTIVE_W1SET_LANE00_PHYC_G3 // 0/x/x/X Reserved
#define CND003_PCIEPHYCFG_EQUALIZER_ADAPTIVE_W1SET_LANE01_PHYC_G3 0x84F // Equalizer Adaptive W1SET Lane01 PHYC G3
    #define CND003_PCIEPHYCFG_RSVPCIEPHYCFG_84F_7 PCIEPHYCFG_EQUALIZER_ADAPTIVE_W1SET_LANE01_PHYC_G3 // 0/x/x/x Reserved
#define CND003_PCIEPHYCFG_RESERVED_Z45 0x850 // Reserved
    #define CND003_PCIEPHYCFG_RSVPCIEPHYCFG_850_7 PCIEPHYCFG_RESERVED_Z45 // 0/x/x/x Reserved
#define CND003_PCIEPHYCFG_EQUALIZER_ADAPTIVE_W2SET_LANE00_G1 0x880 // Equalizer Adaptive W2SET Lane00 G1
    #define CND003_PCIEPHYCFG_RSVPCIEPHYCFG_880_7 PCIEPHYCFG_EQUALIZER_ADAPTIVE_W2SET_LANE00_G1 // 0/x/x/X Reserved
#define CND003_PCIEPHYCFG_EQUALIZER_ADAPTIVE_W2SET_LANE04_PHYA_G1 0x881 // Equalizer Adaptive W2SET Lane04 PHYA G1
    #define CND003_PCIEPHYCFG_RSVPCIEPHYCFG_881_7      (BIT6 + BIT7)   // 0/x/x/x Reserved
    #define CND003_PCIEPHYCFG_FRP04_W2SET_G1_PHYA_4_0  0x3E            // 00001b/00001/x/x DFE Weight2 Initial or Set Value
    #define CND003_PCIEPHYCFG_FRP04_W2SETEN_G1_PHYA    BIT0            // 0/0/x/x DFE Weight2 Manual Set Enable
#define CND003_PCIEPHYCFG_EQUALIZER_ADAPTIVE_W2SET_LANE00_PHYA_G1 0x882 // Equalizer Adaptive W2SET Lane00 PHYA G1
    #define CND003_PCIEPHYCFG_RSVPCIEPHYCFG_882_7      (BIT6 + BIT7)   // 0/x/x/x Reserved
    #define CND003_PCIEPHYCFG_FRP00_W2SET_G1_PHYA_4_0  0x3E            // 00001b/00001/x/x DFE Weight2 Initial or Set Value
    #define CND003_PCIEPHYCFG_FRP00_W2SETEN_G1_PHYA    BIT0            // 0/0/x/x DFE Weight2 Manual Set Enable
#define CND003_PCIEPHYCFG_EQUALIZER_ADAPTIVE_W2SET_LANE01_PHYA_G1 0x883 // Equalizer Adaptive W2SET Lane01 PHYA G1
    #define CND003_PCIEPHYCFG_RSVPCIEPHYCFG_883_7      (BIT6 + BIT7)   // 0/x/x/x Reserved
    #define CND003_PCIEPHYCFG_FRP01_W2SET_G1_PHYA_4_0  0x3E            // 00001b/00001/x/x DFE Weight2 Initial or Set Value
    #define CND003_PCIEPHYCFG_FRP01_W2SETEN_G1_PHYA    BIT0            // 0/0/x/x DFE Weight2 Manual Set Enable
#define CND003_PCIEPHYCFG_EQUALIZER_ADAPTIVE_W2SET_LANE02_PHYA_G1 0x884 // Equalizer Adaptive W2SET Lane02 PHYA G1
    #define CND003_PCIEPHYCFG_RSVPCIEPHYCFG_884_7      (BIT6 + BIT7)   // 0/x/x/x Reserved
    #define CND003_PCIEPHYCFG_FRP02_W2SET_G1_PHYA_4_0  0x3E            // 00001b/00001/x/x DFE Weight2 Initial or Set Value
    #define CND003_PCIEPHYCFG_FRP02_W2SETEN_G1_PHYA    BIT0            // 0/0/x/x DFE Weight2 Manual Set Enable
#define CND003_PCIEPHYCFG_EQUALIZER_ADAPTIVE_W2SET_LANE03_PHYA_G1 0x885 // Equalizer Adaptive W2SET Lane03 PHYA G1
    #define CND003_PCIEPHYCFG_RSVPCIEPHYCFG_885_7      (BIT6 + BIT7)   // 0/x/x/x Reserved
    #define CND003_PCIEPHYCFG_FRP03_W2SET_G1_PHYA_4_0  0x3E            // 00001b/00001/x/x DFE Weight2 Initial or Set Value
    #define CND003_PCIEPHYCFG_FRP03_W2SETEN_G1_PHYA    BIT0            // 0/0/x/x DFE Weight2 Manual Set Enable
#define CND003_PCIEPHYCFG_EQUALIZER_ADAPTIVE_W2SET_LANE00_PHYB_G1 0x886 // Equalizer Adaptive W2SET Lane00 PHYB G1
    #define CND003_PCIEPHYCFG_RSVPCIEPHYCFG_886_7      (BIT6 + BIT7)   // 0/x/x/x Reserved
    #define CND003_PCIEPHYCFG_FRP00_W2SET_G1_PHYB_4_0  0x3E            // 00001b/00001/x/x DFE Weight2 Initial or Set Value
    #define CND003_PCIEPHYCFG_FRP00_W2SETEN_G1_PHYB    BIT0            // 0/0/x/x DFE Weight2 Manual Set Enable
#define CND003_PCIEPHYCFG_EQUALIZER_ADAPTIVE_W2SET_LANE01_PHYB_G1 0x887 // Equalizer Adaptive W2SET Lane01 PHYB G1
    #define CND003_PCIEPHYCFG_RSVPCIEPHYCFG_887_7      (BIT6 + BIT7)   // 0/x/x/x Reserved
    #define CND003_PCIEPHYCFG_FRP01_W2SET_G1_PHYB_4_0  0x3E            // 00001b/00001/x/x DFE Weight2 Initial or Set Value
    #define CND003_PCIEPHYCFG_FRP01_W2SETEN_G1_PHYB    BIT0            // 0/0/x/x DFE Weight2 Manual Set Enable
#define CND003_PCIEPHYCFG_EQUALIZER_ADAPTIVE_W2SET_LANE02_PHYB_G1 0x888 // Equalizer Adaptive W2SET Lane02 PHYB G1
    #define CND003_PCIEPHYCFG_RSVPCIEPHYCFG_888_7      (BIT6 + BIT7)   // 0/x/x/x Reserved
    #define CND003_PCIEPHYCFG_FRP02_W2SET_G1_PHYB_4_0  0x3E            // 00001b/00001/x/x DFE Weight2 Initial or Set Value
    #define CND003_PCIEPHYCFG_FRP02_W2SETEN_G1_PHYB    BIT0            // 0/0/x/x DFE Weight2 Manual Set Enable
#define CND003_PCIEPHYCFG_EQUALIZER_ADAPTIVE_W2SET_LANE03_PHYB_G1 0x889 // Equalizer Adaptive W2SET Lane03 PHYB G1
    #define CND003_PCIEPHYCFG_RSVPCIEPHYCFG_889_7      (BIT6 + BIT7)   // 0/x/x/x Reserved
    #define CND003_PCIEPHYCFG_FRP03_W2SET_G1_PHYB_4_0  0x3E            // 00001b/00001/x/x DFE Weight2 Initial or Set Value
    #define CND003_PCIEPHYCFG_FRP03_W2SETEN_G1_PHYB    BIT0            // 0/0/x/x DFE Weight2 Manual Set Enable
#define CND003_PCIEPHYCFG_EQUALIZER_ADAPTIVE_W2SET_LANE00_EP_G1 0x88A // Equalizer Adaptive W2SET Lane00 EP G1
    #define CND003_PCIEPHYCFG_RSVPCIEPHYCFG_88A_7      (BIT6 + BIT7)   // 0/x/x/x Reserved
    #define CND003_PCIEPHYCFG_FRP00_W2SET_G1_EP_4_0    0x3E            // 00001b/00001/x/x DFE Weight2 Initial or Set Value
    #define CND003_PCIEPHYCFG_FRP00_W2SETEN_G1_EP      BIT0            // 0/0/x/x DFE Weight2 Manual Set Enable
#define CND003_PCIEPHYCFG_EQUALIZER_ADAPTIVE_W2SET_LANE01_EP_G1 0x88B // Equalizer Adaptive W2SET Lane01 EP G1
    #define CND003_PCIEPHYCFG_RSVPCIEPHYCFG_88B_7      (BIT6 + BIT7)   // 0/x/x/x Reserved
    #define CND003_PCIEPHYCFG_FRP01_W2SET_G1_EP_4_0    0x3E            // 00001b/00001/x/x DFE Weight2 Initial or Set Value
    #define CND003_PCIEPHYCFG_FRP01_W2SETEN_G1_EP      BIT0            // 0/0/x/x DFE Weight2 Manual Set Enable
#define CND003_PCIEPHYCFG_EQUALIZER_ADAPTIVE_W2SET_LANE02_EP_G1 0x88C // Equalizer Adaptive W2SET Lane02 EP G1
    #define CND003_PCIEPHYCFG_RSVPCIEPHYCFG_88C_7      (BIT6 + BIT7)   // 0/x/x/x Reserved
    #define CND003_PCIEPHYCFG_FRP02_W2SET_G1_EP_4_0    0x3E            // 00001b/00001/x/x DFE Weight2 Initial or Set Value
    #define CND003_PCIEPHYCFG_FRP02_W2SETEN_G1_EP      BIT0            // 0/0/x/x DFE Weight2 Manual Set Enable
#define CND003_PCIEPHYCFG_EQUALIZER_ADAPTIVE_W2SET_LANE03_EP_G1 0x88D // Equalizer Adaptive W2SET Lane03 EP G1
    #define CND003_PCIEPHYCFG_RSVPCIEPHYCFG_88D_7      (BIT6 + BIT7)   // 0/x/x/x Reserved
    #define CND003_PCIEPHYCFG_FRP03_W2SET_G1_EP_4_0    0x3E            // 00001b/00001/x/x DFE Weight2 Initial or Set Value
    #define CND003_PCIEPHYCFG_FRP03_W2SETEN_G1_EP      BIT0            // 0/0/x/x DFE Weight2 Manual Set Enable
#define CND003_PCIEPHYCFG_EQUALIZER_ADAPTIVE_W2SET_LANE00_PHYC_G1 0x88E // Equalizer Adaptive W2SET Lane00 PHYC G1
    #define CND003_PCIEPHYCFG_RSVPCIEPHYCFG_88E_7 PCIEPHYCFG_EQUALIZER_ADAPTIVE_W2SET_LANE00_PHYC_G1 // 0/x/x/X Reserved
#define CND003_PCIEPHYCFG_EQUALIZER_ADAPTIVE_W2SET_LANE01_PHYC_G1 0x88F // Equalizer Adaptive W2SET Lane01 PHYC G1
    #define CND003_PCIEPHYCFG_RSVPCIEPHYCFG_88F_7 PCIEPHYCFG_EQUALIZER_ADAPTIVE_W2SET_LANE01_PHYC_G1 // 0/x/x/x Reserved
#define CND003_PCIEPHYCFG_RESERVED_Z46 0x890 // Reserved
    #define CND003_PCIEPHYCFG_RSVPCIEPHYCFG_890_7 PCIEPHYCFG_RESERVED_Z46 // 0/x/x/x Reserved
#define CND003_PCIEPHYCFG_EQUALIZER_ADAPTIVE_W2SET_LANE00_G2 0x8A0 // Equalizer Adaptive W2SET Lane00 G2
    #define CND003_PCIEPHYCFG_RSVPCIEPHYCFG_8A0_7 PCIEPHYCFG_EQUALIZER_ADAPTIVE_W2SET_LANE00_G2 // 0/x/x/X Reserved
#define CND003_PCIEPHYCFG_EQUALIZER_ADAPTIVE_W2SET_LANE04_PHYA_G2 0x8A1 // Equalizer Adaptive W2SET Lane04 PHYA G2
    #define CND003_PCIEPHYCFG_RSVPCIEPHYCFG_8A1_7      (BIT6 + BIT7)   // 0/x/x/x Reserved
    #define CND003_PCIEPHYCFG_FRP04_W2SET_G2_PHYA_4_0  0x3E            // 00001b/00001/x/x DFE Weight2 Initial or Set Value
    #define CND003_PCIEPHYCFG_FRP04_W2SETEN_G2_PHYA    BIT0            // 0/0/x/x DFE Weight2 Manual Set Enable
#define CND003_PCIEPHYCFG_EQUALIZER_ADAPTIVE_W2SET_LANE00_PHYA_G2 0x8A2 // Equalizer Adaptive W2SET Lane00 PHYA G2
    #define CND003_PCIEPHYCFG_RSVPCIEPHYCFG_8A2_7      (BIT6 + BIT7)   // 0/x/x/x Reserved
    #define CND003_PCIEPHYCFG_FRP00_W2SET_G2_PHYA_4_0  0x3E            // 00001b/00001/x/x DFE Weight2 Initial or Set Value
    #define CND003_PCIEPHYCFG_FRP00_W2SETEN_G2_PHYA    BIT0            // 0/0/x/x DFE Weight2 Manual Set Enable
#define CND003_PCIEPHYCFG_EQUALIZER_ADAPTIVE_W2SET_LANE01_PHYA_G2 0x8A3 // Equalizer Adaptive W2SET Lane01 PHYA G2
    #define CND003_PCIEPHYCFG_RSVPCIEPHYCFG_8A3_7      (BIT6 + BIT7)   // 0/x/x/x Reserved
    #define CND003_PCIEPHYCFG_FRP01_W2SET_G2_PHYA_4_0  0x3E            // 00001b/00001/x/x DFE Weight2 Initial or Set Value
    #define CND003_PCIEPHYCFG_FRP01_W2SETEN_G2_PHYA    BIT0            // 0/0/x/x DFE Weight2 Manual Set Enable
#define CND003_PCIEPHYCFG_EQUALIZER_ADAPTIVE_W2SET_LANE02_PHYA_G2 0x8A4 // Equalizer Adaptive W2SET Lane02 PHYA G2
    #define CND003_PCIEPHYCFG_RSVPCIEPHYCFG_8A4_7      (BIT6 + BIT7)   // 0/x/x/x Reserved
    #define CND003_PCIEPHYCFG_FRP02_W2SET_G2_PHYA_4_0  0x3E            // 00001b/00001/x/x DFE Weight2 Initial or Set Value
    #define CND003_PCIEPHYCFG_FRP02_W2SETEN_G2_PHYA    BIT0            // 0/0/x/x DFE Weight2 Manual Set Enable
#define CND003_PCIEPHYCFG_EQUALIZER_ADAPTIVE_W2SET_LANE03_PHYA_G2 0x8A5 // Equalizer Adaptive W2SET Lane03 PHYA G2
    #define CND003_PCIEPHYCFG_RSVPCIEPHYCFG_8A5_7      (BIT6 + BIT7)   // 0/x/x/x Reserved
    #define CND003_PCIEPHYCFG_FRP03_W2SET_G2_PHYA_4_0  0x3E            // 00001b/00001/x/x DFE Weight2 Initial or Set Value
    #define CND003_PCIEPHYCFG_FRP03_W2SETEN_G2_PHYA    BIT0            // 0/0/x/x DFE Weight2 Manual Set Enable
#define CND003_PCIEPHYCFG_EQUALIZER_ADAPTIVE_W2SET_LANE00_PHYB_G2 0x8A6 // Equalizer Adaptive W2SET Lane00 PHYB G2
    #define CND003_PCIEPHYCFG_RSVPCIEPHYCFG_8A6_7      (BIT6 + BIT7)   // 0/x/x/x Reserved
    #define CND003_PCIEPHYCFG_FRP00_W2SET_G2_PHYB_4_0  0x3E            // 00001b/00001/x/x DFE Weight2 Initial or Set Value
    #define CND003_PCIEPHYCFG_FRP00_W2SETEN_G2_PHYB    BIT0            // 0/0/x/x DFE Weight2 Manual Set Enable
#define CND003_PCIEPHYCFG_EQUALIZER_ADAPTIVE_W2SET_LANE01_PHYB_G2 0x8A7 // Equalizer Adaptive W2SET Lane01 PHYB G2
    #define CND003_PCIEPHYCFG_RSVPCIEPHYCFG_8A7_7      (BIT6 + BIT7)   // 0/x/x/x Reserved
    #define CND003_PCIEPHYCFG_FRP01_W2SET_G2_PHYB_4_0  0x3E            // 00001b/00001/x/x DFE Weight2 Initial or Set Value
    #define CND003_PCIEPHYCFG_FRP01_W2SETEN_G2_PHYB    BIT0            // 0/0/x/x DFE Weight2 Manual Set Enable
#define CND003_PCIEPHYCFG_EQUALIZER_ADAPTIVE_W2SET_LANE02_PHYB_G2 0x8A8 // Equalizer Adaptive W2SET Lane02 PHYB G2
    #define CND003_PCIEPHYCFG_RSVPCIEPHYCFG_8A8_7      (BIT6 + BIT7)   // 0/x/x/x Reserved
    #define CND003_PCIEPHYCFG_FRP02_W2SET_G2_PHYB_4_0  0x3E            // 00001b/00001/x/x DFE Weight2 Initial or Set Value
    #define CND003_PCIEPHYCFG_FRP02_W2SETEN_G2_PHYB    BIT0            // 0/0/x/x DFE Weight2 Manual Set Enable
#define CND003_PCIEPHYCFG_EQUALIZER_ADAPTIVE_W2SET_LANE03_PHYB_G2 0x8A9 // Equalizer Adaptive W2SET Lane03 PHYB G2
    #define CND003_PCIEPHYCFG_RSVPCIEPHYCFG_8A9_7      (BIT6 + BIT7)   // 0/x/x/x Reserved
    #define CND003_PCIEPHYCFG_FRP03_W2SET_G2_PHYB_4_0  0x3E            // 00001b/00001/x/x DFE Weight2 Initial or Set Value
    #define CND003_PCIEPHYCFG_FRP03_W2SETEN_G2_PHYB    BIT0            // 0/0/x/x DFE Weight2 Manual Set Enable
#define CND003_PCIEPHYCFG_EQUALIZER_ADAPTIVE_W2SET_LANE00_EP_G2 0x8AA // Equalizer Adaptive W2SET Lane00 EP G2
    #define CND003_PCIEPHYCFG_RSVPCIEPHYCFG_8AA_7      (BIT6 + BIT7)   // 0/x/x/x Reserved
    #define CND003_PCIEPHYCFG_FRP00_W2SET_G2_EP_4_0    0x3E            // 00001b/00001/x/x DFE Weight2 Initial or Set Value
    #define CND003_PCIEPHYCFG_FRP00_W2SETEN_G2_EP      BIT0            // 0/0/x/x DFE Weight2 Manual Set Enable
#define CND003_PCIEPHYCFG_EQUALIZER_ADAPTIVE_W2SET_LANE01_EP_G2 0x8AB // Equalizer Adaptive W2SET Lane01 EP G2
    #define CND003_PCIEPHYCFG_RSVPCIEPHYCFG_8AB_7      (BIT6 + BIT7)   // 0/x/x/x Reserved
    #define CND003_PCIEPHYCFG_FRP01_W2SET_G2_EP_4_0    0x3E            // 00001b/00001/x/x DFE Weight2 Initial or Set Value
    #define CND003_PCIEPHYCFG_FRP01_W2SETEN_G2_EP      BIT0            // 0/0/x/x DFE Weight2 Manual Set Enable
#define CND003_PCIEPHYCFG_EQUALIZER_ADAPTIVE_W2SET_LANE02_EP_G2 0x8AC // Equalizer Adaptive W2SET Lane02 EP G2
    #define CND003_PCIEPHYCFG_RSVPCIEPHYCFG_8AC_7      (BIT6 + BIT7)   // 0/x/x/x Reserved
    #define CND003_PCIEPHYCFG_FRP02_W2SET_G2_EP_4_0    0x3E            // 00001b/00001/x/x DFE Weight2 Initial or Set Value
    #define CND003_PCIEPHYCFG_FRP02_W2SETEN_G2_EP      BIT0            // 0/0/x/x DFE Weight2 Manual Set Enable
#define CND003_PCIEPHYCFG_EQUALIZER_ADAPTIVE_W2SET_LANE03_EP_G2 0x8AD // Equalizer Adaptive W2SET Lane03 EP G2
    #define CND003_PCIEPHYCFG_RSVPCIEPHYCFG_8AD_7      (BIT6 + BIT7)   // 0/x/x/x Reserved
    #define CND003_PCIEPHYCFG_FRP03_W2SET_G2_EP_4_0    0x3E            // 00001b/00001/x/x DFE Weight2 Initial or Set Value
    #define CND003_PCIEPHYCFG_FRP03_W2SETEN_G2_EP      BIT0            // 0/0/x/x DFE Weight2 Manual Set Enable
#define CND003_PCIEPHYCFG_EQUALIZER_ADAPTIVE_W2SET_LANE00_PHYC_G2 0x8AE // Equalizer Adaptive W2SET Lane00 PHYC G2
    #define CND003_PCIEPHYCFG_RSVPCIEPHYCFG_8AE_7 PCIEPHYCFG_EQUALIZER_ADAPTIVE_W2SET_LANE00_PHYC_G2 // 0/x/x/X Reserved
#define CND003_PCIEPHYCFG_EQUALIZER_ADAPTIVE_W2SET_LANE01_PHYC_G2 0x8AF // Equalizer Adaptive W2SET Lane01 PHYC G2
    #define CND003_PCIEPHYCFG_RSVPCIEPHYCFG_8AF_7 PCIEPHYCFG_EQUALIZER_ADAPTIVE_W2SET_LANE01_PHYC_G2 // 0/x/x/x Reserved
#define CND003_PCIEPHYCFG_RESERVED_Z47 0x8B0 // Reserved
    #define CND003_PCIEPHYCFG_RSVPCIEPHYCFG_8B0_7 PCIEPHYCFG_RESERVED_Z47 // 0/x/x/x Reserved
#define CND003_PCIEPHYCFG_EQUALIZER_ADAPTIVE_W2SET_LANE00_G3 0x8C0 // Equalizer Adaptive W2SET Lane00 G3
    #define CND003_PCIEPHYCFG_RSVPCIEPHYCFG_8C0_7 PCIEPHYCFG_EQUALIZER_ADAPTIVE_W2SET_LANE00_G3 // 0/x/x/X Reserved
#define CND003_PCIEPHYCFG_EQUALIZER_ADAPTIVE_W2SET_LANE04_PHYA_G3 0x8C1 // Equalizer Adaptive W2SET Lane04 PHYA G3
    #define CND003_PCIEPHYCFG_RSVPCIEPHYCFG_8C1_7      (BIT6 + BIT7)   // 0/x/x/x Reserved
    #define CND003_PCIEPHYCFG_FRP04_W2SET_G3_PHYA_4_0  0x3E            // 00001b/00001/x/x DFE Weight2 Initial or Set Value
    #define CND003_PCIEPHYCFG_FRP04_W2SETEN_G3_PHYA    BIT0            // 0/0/x/x DFE Weight2 Manual Set Enable
#define CND003_PCIEPHYCFG_EQUALIZER_ADAPTIVE_W2SET_LANE00_PHYA_G3 0x8C2 // Equalizer Adaptive W2SET Lane00 PHYA G3
    #define CND003_PCIEPHYCFG_RSVPCIEPHYCFG_8C2_7      (BIT6 + BIT7)   // 0/x/x/x Reserved
    #define CND003_PCIEPHYCFG_FRP00_W2SET_G3_PHYA_4_0  0x3E            // 00001b/00001/x/x DFE Weight2 Initial or Set Value
    #define CND003_PCIEPHYCFG_FRP00_W2SETEN_G3_PHYA    BIT0            // 0/0/x/x DFE Weight2 Manual Set Enable
#define CND003_PCIEPHYCFG_EQUALIZER_ADAPTIVE_W2SET_LANE01_PHYA_G3 0x8C3 // Equalizer Adaptive W2SET Lane01 PHYA G3
    #define CND003_PCIEPHYCFG_RSVPCIEPHYCFG_8C3_7      (BIT6 + BIT7)   // 0/x/x/x Reserved
    #define CND003_PCIEPHYCFG_FRP01_W2SET_G3_PHYA_4_0  0x3E            // 00001b/00001/x/x DFE Weight2 Initial or Set Value
    #define CND003_PCIEPHYCFG_FRP01_W2SETEN_G3_PHYA    BIT0            // 0/0/x/x DFE Weight2 Manual Set Enable
#define CND003_PCIEPHYCFG_EQUALIZER_ADAPTIVE_W2SET_LANE02_PHYA_G3 0x8C4 // Equalizer Adaptive W2SET Lane02 PHYA G3
    #define CND003_PCIEPHYCFG_RSVPCIEPHYCFG_8C4_7      (BIT6 + BIT7)   // 0/x/x/x Reserved
    #define CND003_PCIEPHYCFG_FRP02_W2SET_G3_PHYA_4_0  0x3E            // 00001b/00001/x/x DFE Weight2 Initial or Set Value
    #define CND003_PCIEPHYCFG_FRP02_W2SETEN_G3_PHYA    BIT0            // 0/0/x/x DFE Weight2 Manual Set Enable
#define CND003_PCIEPHYCFG_EQUALIZER_ADAPTIVE_W2SET_LANE03_PHYA_G3 0x8C5 // Equalizer Adaptive W2SET Lane03 PHYA G3
    #define CND003_PCIEPHYCFG_RSVPCIEPHYCFG_8C5_7      (BIT6 + BIT7)   // 0/x/x/x Reserved
    #define CND003_PCIEPHYCFG_FRP03_W2SET_G3_PHYA_4_0  0x3E            // 00001b/00001/x/x DFE Weight2 Initial or Set Value
    #define CND003_PCIEPHYCFG_FRP03_W2SETEN_G3_PHYA    BIT0            // 0/0/x/x DFE Weight2 Manual Set Enable
#define CND003_PCIEPHYCFG_EQUALIZER_ADAPTIVE_W2SET_LANE00_PHYB_G3 0x8C6 // Equalizer Adaptive W2SET Lane00 PHYB G3
    #define CND003_PCIEPHYCFG_RSVPCIEPHYCFG_8C6_7      (BIT6 + BIT7)   // 0/x/x/x Reserved
    #define CND003_PCIEPHYCFG_FRP00_W2SET_G3_PHYB_4_0  0x3E            // 00001b/00001/x/x DFE Weight2 Initial or Set Value
    #define CND003_PCIEPHYCFG_FRP00_W2SETEN_G3_PHYB    BIT0            // 0/0/x/x DFE Weight2 Manual Set Enable
#define CND003_PCIEPHYCFG_EQUALIZER_ADAPTIVE_W2SET_LANE01_PHYB_G3 0x8C7 // Equalizer Adaptive W2SET Lane01 PHYB G3
    #define CND003_PCIEPHYCFG_RSVPCIEPHYCFG_8C7_7      (BIT6 + BIT7)   // 0/x/x/x Reserved
    #define CND003_PCIEPHYCFG_FRP01_W2SET_G3_PHYB_4_0  0x3E            // 00001b/00001/x/x DFE Weight2 Initial or Set Value
    #define CND003_PCIEPHYCFG_FRP01_W2SETEN_G3_PHYB    BIT0            // 0/0/x/x DFE Weight2 Manual Set Enable
#define CND003_PCIEPHYCFG_EQUALIZER_ADAPTIVE_W2SET_LANE02_PHYB_G3 0x8C8 // Equalizer Adaptive W2SET Lane02 PHYB G3
    #define CND003_PCIEPHYCFG_RSVPCIEPHYCFG_8C8_7      (BIT6 + BIT7)   // 0/x/x/x Reserved
    #define CND003_PCIEPHYCFG_FRP02_W2SET_G3_PHYB_4_0  0x3E            // 00001b/00001/x/x DFE Weight2 Initial or Set Value
    #define CND003_PCIEPHYCFG_FRP02_W2SETEN_G3_PHYB    BIT0            // 0/0/x/x DFE Weight2 Manual Set Enable
#define CND003_PCIEPHYCFG_EQUALIZER_ADAPTIVE_W2SET_LANE03_PHYB_G3 0x8C9 // Equalizer Adaptive W2SET Lane03 PHYB G3
    #define CND003_PCIEPHYCFG_RSVPCIEPHYCFG_8C9_7      (BIT6 + BIT7)   // 0/x/x/x Reserved
    #define CND003_PCIEPHYCFG_FRP03_W2SET_G3_PHYB_4_0  0x3E            // 00001b/00001/x/x DFE Weight2 Initial or Set Value
    #define CND003_PCIEPHYCFG_FRP03_W2SETEN_G3_PHYB    BIT0            // 0/0/x/x DFE Weight2 Manual Set Enable
#define CND003_PCIEPHYCFG_EQUALIZER_ADAPTIVE_W2SET_LANE00_EP_G3 0x8CA // Equalizer Adaptive W2SET Lane00 EP G3
    #define CND003_PCIEPHYCFG_RSVPCIEPHYCFG_8CA_7      (BIT6 + BIT7)   // 0/x/x/x Reserved
    #define CND003_PCIEPHYCFG_FRP00_W2SET_G3_EP_4_0    0x3E            // 00001b/00001/x/x DFE Weight2 Initial or Set Value
    #define CND003_PCIEPHYCFG_FRP00_W2SETEN_G3_EP      BIT0            // 0/0/x/x DFE Weight2 Manual Set Enable
#define CND003_PCIEPHYCFG_EQUALIZER_ADAPTIVE_W2SET_LANE01_EP_G3 0x8CB // Equalizer Adaptive W2SET Lane01 EP G3
    #define CND003_PCIEPHYCFG_RSVPCIEPHYCFG_8CB_7      (BIT6 + BIT7)   // 0/x/x/x Reserved
    #define CND003_PCIEPHYCFG_FRP01_W2SET_G3_EP_4_0    0x3E            // 00001b/00001/x/x DFE Weight2 Initial or Set Value
    #define CND003_PCIEPHYCFG_FRP01_W2SETEN_G3_EP      BIT0            // 0/0/x/x DFE Weight2 Manual Set Enable
#define CND003_PCIEPHYCFG_EQUALIZER_ADAPTIVE_W2SET_LANE02_EP_G3 0x8CC // Equalizer Adaptive W2SET Lane02 EP G3
    #define CND003_PCIEPHYCFG_RSVPCIEPHYCFG_8CC_7      (BIT6 + BIT7)   // 0/x/x/x Reserved
    #define CND003_PCIEPHYCFG_FRP02_W2SET_G3_EP_4_0    0x3E            // 00001b/00001/x/x DFE Weight2 Initial or Set Value
    #define CND003_PCIEPHYCFG_FRP02_W2SETEN_G3_EP      BIT0            // 0/0/x/x DFE Weight2 Manual Set Enable
#define CND003_PCIEPHYCFG_EQUALIZER_ADAPTIVE_W2SET_LANE03_EP_G3 0x8CD // Equalizer Adaptive W2SET Lane03 EP G3
    #define CND003_PCIEPHYCFG_RSVPCIEPHYCFG_8CD_7      (BIT6 + BIT7)   // 0/x/x/x Reserved
    #define CND003_PCIEPHYCFG_FRP03_W2SET_G3_EP_4_0    0x3E            // 00001b/00001/x/x DFE Weight2 Initial or Set Value
    #define CND003_PCIEPHYCFG_FRP03_W2SETEN_G3_EP      BIT0            // 0/0/x/x DFE Weight2 Manual Set Enable
#define CND003_PCIEPHYCFG_EQUALIZER_ADAPTIVE_W2SET_LANE00_PHYC_G3 0x8CE // Equalizer Adaptive W2SET Lane00 PHYC G3
    #define CND003_PCIEPHYCFG_RSVPCIEPHYCFG_8CE_7 PCIEPHYCFG_EQUALIZER_ADAPTIVE_W2SET_LANE00_PHYC_G3 // 0/x/x/X Reserved
#define CND003_PCIEPHYCFG_EQUALIZER_ADAPTIVE_W2SET_LANE01_PHYC_G3 0x8CF // Equalizer Adaptive W2SET Lane01 PHYC G3
    #define CND003_PCIEPHYCFG_RSVPCIEPHYCFG_8CF_7 PCIEPHYCFG_EQUALIZER_ADAPTIVE_W2SET_LANE01_PHYC_G3 // 0/x/x/x Reserved
#define CND003_PCIEPHYCFG_RESERVED_Z48 0x8D0 // Reserved
    #define CND003_PCIEPHYCFG_RSVPCIEPHYCFG_8D3_7 PCIEPHYCFG_RESERVED_Z48 // 0/x/x/x Reserved
#define CND003_PCIEPHYCFG_EQUALIZER_ADAPTIVE_FRP_EQTNBIT_LANE00_G1 0x900 // Equalizer Adaptive FRP_EQTNBIT Lane00 G1
    #define CND003_PCIEPHYCFG_RSVPCIEPHYCFG_900_7 PCIEPHYCFG_EQUALIZER_ADAPTIVE_FRP_EQTNBIT_LANE00_G1 // 0/x/x/x Reserved
#define CND003_PCIEPHYCFG_EQUALIZER_ADAPTIVE_FRP_EQTNBIT_LANE04_PHYA_G1 0x901 // Equalizer Adaptive FRP_EQTNBIT Lane04 PHYA G1
    #define CND003_PCIEPHYCFG_RSVPCIEPHYCFG_901_7              0xF0                    // 0/x/x/x Reserved
    #define CND003_PCIEPHYCFG_FRP04_EQTNBISTEVT_G1_PHYA_2_0    (BIT1 + BIT2 + BIT3)    // 0/0/x/x DFE Weight2 Initial or Set Value
    #define CND003_PCIEPHYCFG_FRP04_EQTNBISTEN_G1_PHYA         BIT0                    // 0/0/x/x DFE Weight2 Manual Set Enable
#define CND003_PCIEPHYCFG_EQUALIZER_ADAPTIVE_FRP_EQTNBIT_LANE00_PHYA_G1 0x902 // Equalizer Adaptive FRP_EQTNBIT Lane00 PHYA G1
    #define CND003_PCIEPHYCFG_RSVPCIEPHYCFG_902_7              0xF0                    // 0/x/x/x Reserved
    #define CND003_PCIEPHYCFG_FRP00_EQTNBISTEVT_G1_PHYA_2_0    (BIT1 + BIT2 + BIT3)    // 0/0/x/x DFE Weight2 Initial or Set Value
    #define CND003_PCIEPHYCFG_FRP00_EQTNBISTEN_G1_PHYA         BIT0                    // 0/0/x/x DFE Weight2 Manual Set Enable
#define CND003_PCIEPHYCFG_EQUALIZER_ADAPTIVE_FRP_EQTNBIT_LANE01_PHYA_G1 0x903 // Equalizer Adaptive FRP_EQTNBIT Lane01 PHYA G1
    #define CND003_PCIEPHYCFG_RSVPCIEPHYCFG_903_7              0xF0                    // 0/x/x/x Reserved
    #define CND003_PCIEPHYCFG_FRP01_EQTNBISTEVT_G1_PHYA_2_0    (BIT1 + BIT2 + BIT3)    // 0/0/x/x DFE Weight2 Initial or Set Value
    #define CND003_PCIEPHYCFG_FRP01_EQTNBISTEN_G1_PHYA         BIT0                    // 0/0/x/x DFE Weight2 Manual Set Enable
#define CND003_PCIEPHYCFG_EQUALIZER_ADAPTIVE_FRP_EQTNBIT_LANE02_PHYA_G1 0x904 // Equalizer Adaptive FRP_EQTNBIT Lane02 PHYA G1
    #define CND003_PCIEPHYCFG_RSVPCIEPHYCFG_904_7              0xF0                    // 0/x/x/x Reserved
    #define CND003_PCIEPHYCFG_FRP02_EQTNBISTEVT_G1_PHYA_2_0    (BIT1 + BIT2 + BIT3)    // 0/0/x/x DFE Weight2 Initial or Set Value
    #define CND003_PCIEPHYCFG_FRP02_EQTNBISTEN_G1_PHYA         BIT0                    // 0/0/x/x DFE Weight2 Manual Set Enable
#define CND003_PCIEPHYCFG_EQUALIZER_ADAPTIVE_FRP_EQTNBIT_LANE03_PHYA_G1 0x905 // Equalizer Adaptive FRP_EQTNBIT Lane03 PHYA G1
    #define CND003_PCIEPHYCFG_RSVPCIEPHYCFG_905_7              0xF0                    // 0/x/x/x Reserved
    #define CND003_PCIEPHYCFG_FRP03_EQTNBISTEVT_G1_PHYA_2_0    (BIT1 + BIT2 + BIT3)    // 0/0/x/x DFE Weight2 Initial or Set Value
    #define CND003_PCIEPHYCFG_FRP03_EQTNBISTEN_G1_PHYA         BIT0                    // 0/0/x/x DFE Weight2 Manual Set Enable
#define CND003_PCIEPHYCFG_EQUALIZER_ADAPTIVE_FRP_EQTNBIT_LANE00_PHYB_G1 0x906 // Equalizer Adaptive FRP_EQTNBIT Lane00 PHYB G1
    #define CND003_PCIEPHYCFG_RSVPCIEPHYCFG_906_7              0xF0                    // 0/x/x/x Reserved
    #define CND003_PCIEPHYCFG_FRP00_EQTNBISTEVT_G1_PHYB_2_0    (BIT1 + BIT2 + BIT3)    // 0/0/x/x DFE Weight2 Initial or Set Value
    #define CND003_PCIEPHYCFG_FRP00_EQTNBISTEN_G1_PHYB         BIT0                    // 0/0/x/x DFE Weight2 Manual Set Enable
#define CND003_PCIEPHYCFG_EQUALIZER_ADAPTIVE_FRP_EQTNBIT_LANE01_PHYB_G1 0x907 // Equalizer Adaptive FRP_EQTNBIT Lane01 PHYB G1
    #define CND003_PCIEPHYCFG_RSVPCIEPHYCFG_907_7              0xF0                    // 0/x/x/x Reserved
    #define CND003_PCIEPHYCFG_FRP01_EQTNBISTEVT_G1_PHYB_2_0    (BIT1 + BIT2 + BIT3)    // 0/0/x/x DFE Weight2 Initial or Set Value
    #define CND003_PCIEPHYCFG_FRP01_EQTNBISTEN_G1_PHYB         BIT0                    // 0/0/x/x DFE Weight2 Manual Set Enable
#define CND003_PCIEPHYCFG_EQUALIZER_ADAPTIVE_FRP_EQTNBIT_LANE02_PHYB_G1 0x908 // Equalizer Adaptive FRP_EQTNBIT Lane02 PHYB G1
    #define CND003_PCIEPHYCFG_RSVPCIEPHYCFG_908_7              0xF0                    // 0/x/x/x Reserved
    #define CND003_PCIEPHYCFG_FRP02_EQTNBISTEVT_G1_PHYB_2_0    (BIT1 + BIT2 + BIT3)    // 0/0/x/x DFE Weight2 Initial or Set Value
    #define CND003_PCIEPHYCFG_FRP02_EQTNBISTEN_G1_PHYB         BIT0                    // 0/0/x/x DFE Weight2 Manual Set Enable
#define CND003_PCIEPHYCFG_EQUALIZER_ADAPTIVE_FRP_EQTNBIT_LANE03_PHYB_G1 0x909 // Equalizer Adaptive FRP_EQTNBIT Lane03 PHYB G1
    #define CND003_PCIEPHYCFG_RSVPCIEPHYCFG_909_7              0xF0                    // 0/x/x/x Reserved
    #define CND003_PCIEPHYCFG_FRP03_EQTNBISTEVT_G1_PHYB_2_0    (BIT1 + BIT2 + BIT3)    // 0/0/x/x DFE Weight2 Initial or Set Value
    #define CND003_PCIEPHYCFG_FRP03_EQTNBISTEN_G1_PHYB         BIT0                    // 0/0/x/x DFE Weight2 Manual Set Enable
#define CND003_PCIEPHYCFG_EQUALIZER_ADAPTIVE_FRP_EQTNBIT_LANE00_EP_G1 0x90A // Equalizer Adaptive FRP_EQTNBIT Lane00 EP G1
    #define CND003_PCIEPHYCFG_RSVPCIEPHYCFG_90A_7          0xF0                    // 0/x/x/x Reserved
    #define CND003_PCIEPHYCFG_FRP00_EQTNBISTEVT_G1_EP_2_0  (BIT1 + BIT2 + BIT3)    // 0/0/x/x DFE Weight2 Initial or Set Value
    #define CND003_PCIEPHYCFG_FRP00_EQTNBISTEN_G1_EP       BIT0                    // 0/0/x/x DFE Weight2 Manual Set Enable
#define CND003_PCIEPHYCFG_EQUALIZER_ADAPTIVE_FRP_EQTNBIT_LANE01_EP_G1 0x90B // Equalizer Adaptive FRP_EQTNBIT Lane01 EP G1
    #define CND003_PCIEPHYCFG_RSVPCIEPHYCFG_90B_7          0xF0                    // 0/x/x/x Reserved
    #define CND003_PCIEPHYCFG_FRP01_EQTNBISTEVT_G1_EP_2_0  (BIT1 + BIT2 + BIT3)    // 0/0/x/x DFE Weight2 Initial or Set Value
    #define CND003_PCIEPHYCFG_FRP01_EQTNBISTEN_G1_EP       BIT0                    // 0/0/x/x DFE Weight2 Manual Set Enable
#define CND003_PCIEPHYCFG_EQUALIZER_ADAPTIVE_FRP_EQTNBIT_LANE02_EP_G1 0x90C // Equalizer Adaptive FRP_EQTNBIT Lane02 EP G1
    #define CND003_PCIEPHYCFG_RSVPCIEPHYCFG_90C_7          0xF0                    // 0/x/x/x Reserved
    #define CND003_PCIEPHYCFG_FRP02_EQTNBISTEVT_G1_EP_2_0  (BIT1 + BIT2 + BIT3)    // 0/0/x/x DFE Weight2 Initial or Set Value
    #define CND003_PCIEPHYCFG_FRP02_EQTNBISTEN_G1_EP       BIT0                    // 0/0/x/x DFE Weight2 Manual Set Enable
#define CND003_PCIEPHYCFG_EQUALIZER_ADAPTIVE_FRP_EQTNBIT_LANE03_EP_G1 0x90D // Equalizer Adaptive FRP_EQTNBIT Lane03 EP G1
    #define CND003_PCIEPHYCFG_RSVPCIEPHYCFG_90D_7          0xF0                    // 0/x/x/x Reserved
    #define CND003_PCIEPHYCFG_FRP03_EQTNBISTEVT_G1_EP_2_0  (BIT1 + BIT2 + BIT3)    // 0/0/x/x DFE Weight2 Initial or Set Value
    #define CND003_PCIEPHYCFG_FRP03_EQTNBISTEN_G1_EP       BIT0                    // 0/0/x/x DFE Weight2 Manual Set Enable
#define CND003_PCIEPHYCFG_EQUALIZER_ADAPTIVE_FRP_EQTNBIT_LANE00_PHYC_G1 0x90E // Equalizer Adaptive FRP_EQTNBIT Lane00 PHYC G1
    #define CND003_PCIEPHYCFG_RSVPCIEPHYCFG_90E_7 PCIEPHYCFG_EQUALIZER_ADAPTIVE_FRP_EQTNBIT_LANE00_PHYC_G1 // 0/x/x/x Reserved
#define CND003_PCIEPHYCFG_EQUALIZER_ADAPTIVE_FRP_EQTNBIT_LANE01_PHYC_G1 0x90F // Equalizer Adaptive FRP_EQTNBIT Lane01 PHYC G1
    #define CND003_PCIEPHYCFG_RSVPCIEPHYCFG_90F_7 PCIEPHYCFG_EQUALIZER_ADAPTIVE_FRP_EQTNBIT_LANE01_PHYC_G1 // 0/x/x/x Reserved
#define CND003_PCIEPHYCFG_RESERVED_Z49 0x910 // Reserved
    #define CND003_PCIEPHYCFG_RSVPCIEPHYCFG_910_7 PCIEPHYCFG_RESERVED_Z49 // 0/x/x/x Reserved
#define CND003_PCIEPHYCFG_EQUALIZER_ADAPTIVE_FRP_EQTNBIT_LANE00_G2 0x920 // Equalizer Adaptive FRP_EQTNBIT Lane00 G2
    #define CND003_PCIEPHYCFG_RSVPCIEPHYCFG_920_7 PCIEPHYCFG_EQUALIZER_ADAPTIVE_FRP_EQTNBIT_LANE00_G2 // 0/x/x/x Reserved
#define CND003_PCIEPHYCFG_EQUALIZER_ADAPTIVE_FRP_EQTNBIT_LANE04_PHYA_G2 0x921 // Equalizer Adaptive FRP_EQTNBIT Lane04 PHYA G2
    #define CND003_PCIEPHYCFG_RSVPCIEPHYCFG_921_7              0xF0                    // 0/x/x/x Reserved
    #define CND003_PCIEPHYCFG_FRP04_EQTNBISTEVT_G2_PHYA_2_0    (BIT1 + BIT2 + BIT3)    // 0/0/x/x DFE Weight2 Initial or Set Value
    #define CND003_PCIEPHYCFG_FRP04_EQTNBISTEN_G2_PHYA         BIT0                    // 0/0/x/x DFE Weight2 Manual Set Enable
#define CND003_PCIEPHYCFG_EQUALIZER_ADAPTIVE_FRP_EQTNBIT_LANE00_PHYA_G2 0x922 // Equalizer Adaptive FRP_EQTNBIT Lane00 PHYA G2
    #define CND003_PCIEPHYCFG_RSVPCIEPHYCFG_922_7              0xF0                    // 0/x/x/x Reserved
    #define CND003_PCIEPHYCFG_FRP00_EQTNBISTEVT_G2_PHYA_2_0    (BIT1 + BIT2 + BIT3)    // 0/0/x/x DFE Weight2 Initial or Set Value
    #define CND003_PCIEPHYCFG_FRP00_EQTNBISTEN_G2_PHYA         BIT0                    // 0/0/x/x DFE Weight2 Manual Set Enable
#define CND003_PCIEPHYCFG_EQUALIZER_ADAPTIVE_FRP_EQTNBIT_LANE01_PHYA_G2 0x923 // Equalizer Adaptive FRP_EQTNBIT Lane01 PHYA G2
    #define CND003_PCIEPHYCFG_RSVPCIEPHYCFG_923_7              0xF0                    // 0/x/x/x Reserved
    #define CND003_PCIEPHYCFG_FRP01_EQTNBISTEVT_G2_PHYA_2_0    (BIT1 + BIT2 + BIT3)    // 0/0/x/x DFE Weight2 Initial or Set Value
    #define CND003_PCIEPHYCFG_FRP01_EQTNBISTEN_G2_PHYA         BIT0                    // 0/0/x/x DFE Weight2 Manual Set Enable
#define CND003_PCIEPHYCFG_EQUALIZER_ADAPTIVE_FRP_EQTNBIT_LANE02_PHYA_G2 0x924 // Equalizer Adaptive FRP_EQTNBIT Lane02 PHYA G2
    #define CND003_PCIEPHYCFG_RSVPCIEPHYCFG_924_7              0xF0                    // 0/x/x/x Reserved
    #define CND003_PCIEPHYCFG_FRP02_EQTNBISTEVT_G2_PHYA_2_0    (BIT1 + BIT2 + BIT3)    // 0/0/x/x DFE Weight2 Initial or Set Value
    #define CND003_PCIEPHYCFG_FRP02_EQTNBISTEN_G2_PHYA         BIT0                    // 0/0/x/x DFE Weight2 Manual Set Enable
#define CND003_PCIEPHYCFG_EQUALIZER_ADAPTIVE_FRP_EQTNBIT_LANE03_PHYA_G2 0x925 // Equalizer Adaptive FRP_EQTNBIT Lane03 PHYA G2
    #define CND003_PCIEPHYCFG_RSVPCIEPHYCFG_925_7              0xF0                    // 0/x/x/x Reserved
    #define CND003_PCIEPHYCFG_FRP03_EQTNBISTEVT_G2_PHYA_2_0    (BIT1 + BIT2 + BIT3)    // 0/0/x/x DFE Weight2 Initial or Set Value
    #define CND003_PCIEPHYCFG_FRP03_EQTNBISTEN_G2_PHYA         BIT0                    // 0/0/x/x DFE Weight2 Manual Set Enable
#define CND003_PCIEPHYCFG_EQUALIZER_ADAPTIVE_FRP_EQTNBIT_LANE00_PHYB_G2 0x926 // Equalizer Adaptive FRP_EQTNBIT Lane00 PHYB G2
    #define CND003_PCIEPHYCFG_RSVPCIEPHYCFG_926_7              0xF0                    // 0/x/x/x Reserved
    #define CND003_PCIEPHYCFG_FRP00_EQTNBISTEVT_G2_PHYB_2_0    (BIT1 + BIT2 + BIT3)    // 0/0/x/x DFE Weight2 Initial or Set Value
    #define CND003_PCIEPHYCFG_FRP00_EQTNBISTEN_G2_PHYB         BIT0                    // 0/0/x/x DFE Weight2 Manual Set Enable
#define CND003_PCIEPHYCFG_EQUALIZER_ADAPTIVE_FRP_EQTNBIT_LANE01_PHYB_G2 0x927 // Equalizer Adaptive FRP_EQTNBIT Lane01 PHYB G2
    #define CND003_PCIEPHYCFG_RSVPCIEPHYCFG_927_7              0xF0                    // 0/x/x/x Reserved
    #define CND003_PCIEPHYCFG_FRP01_EQTNBISTEVT_G2_PHYB_2_0    (BIT1 + BIT2 + BIT3)    // 0/0/x/x DFE Weight2 Initial or Set Value
    #define CND003_PCIEPHYCFG_FRP01_EQTNBISTEN_G2_PHYB         BIT0                    // 0/0/x/x DFE Weight2 Manual Set Enable
#define CND003_PCIEPHYCFG_EQUALIZER_ADAPTIVE_FRP_EQTNBIT_LANE02_PHYB_G2 0x928 // Equalizer Adaptive FRP_EQTNBIT Lane02 PHYB G2
    #define CND003_PCIEPHYCFG_RSVPCIEPHYCFG_928_7              0xF0                    // 0/x/x/x Reserved
    #define CND003_PCIEPHYCFG_FRP02_EQTNBISTEVT_G2_PHYB_2_0    (BIT1 + BIT2 + BIT3)    // 0/0/x/x DFE Weight2 Initial or Set Value
    #define CND003_PCIEPHYCFG_FRP02_EQTNBISTEN_G2_PHYB         BIT0                    // 0/0/x/x DFE Weight2 Manual Set Enable
#define CND003_PCIEPHYCFG_EQUALIZER_ADAPTIVE_FRP_EQTNBIT_LANE03_PHYB_G2 0x929 // Equalizer Adaptive FRP_EQTNBIT Lane03 PHYB G2
    #define CND003_PCIEPHYCFG_RSVPCIEPHYCFG_929_7              0xF0                    // 0/x/x/x Reserved
    #define CND003_PCIEPHYCFG_FRP03_EQTNBISTEVT_G2_PHYB_2_0    (BIT1 + BIT2 + BIT3)    // 0/0/x/x DFE Weight2 Initial or Set Value
    #define CND003_PCIEPHYCFG_FRP03_EQTNBISTEN_G2_PHYB         BIT0                    // 0/0/x/x DFE Weight2 Manual Set Enable
#define CND003_PCIEPHYCFG_EQUALIZER_ADAPTIVE_FRP_EQTNBIT_LANE00_EP_G2 0x92A // Equalizer Adaptive FRP_EQTNBIT Lane00 EP G2
    #define CND003_PCIEPHYCFG_RSVPCIEPHYCFG_92A_7          0xF0                    // 0/x/x/x Reserved
    #define CND003_PCIEPHYCFG_FRP00_EQTNBISTEVT_G2_EP_2_0  (BIT1 + BIT2 + BIT3)    // 0/0/x/x DFE Weight2 Initial or Set Value
    #define CND003_PCIEPHYCFG_FRP00_EQTNBISTEN_G2_EP       BIT0                    // 0/0/x/x DFE Weight2 Manual Set Enable
#define CND003_PCIEPHYCFG_EQUALIZER_ADAPTIVE_FRP_EQTNBIT_LANE01_EP_G2 0x92B // Equalizer Adaptive FRP_EQTNBIT Lane01 EP G2
    #define CND003_PCIEPHYCFG_RSVPCIEPHYCFG_92B_7          0xF0                    // 0/x/x/x Reserved
    #define CND003_PCIEPHYCFG_FRP01_EQTNBISTEVT_G2_EP_2_0  (BIT1 + BIT2 + BIT3)    // 0/0/x/x DFE Weight2 Initial or Set Value
    #define CND003_PCIEPHYCFG_FRP01_EQTNBISTEN_G2_EP       BIT0                    // 0/0/x/x DFE Weight2 Manual Set Enable
#define CND003_PCIEPHYCFG_EQUALIZER_ADAPTIVE_FRP_EQTNBIT_LANE02_EP_G2 0x92C // Equalizer Adaptive FRP_EQTNBIT Lane02 EP G2
    #define CND003_PCIEPHYCFG_RSVPCIEPHYCFG_92C_7          0xF0                    // 0/x/x/x Reserved
    #define CND003_PCIEPHYCFG_FRP02_EQTNBISTEVT_G2_EP_2_0  (BIT1 + BIT2 + BIT3)    // 0/0/x/x DFE Weight2 Initial or Set Value
    #define CND003_PCIEPHYCFG_FRP02_EQTNBISTEN_G2_EP       BIT0                    // 0/0/x/x DFE Weight2 Manual Set Enable
#define CND003_PCIEPHYCFG_EQUALIZER_ADAPTIVE_FRP_EQTNBIT_LANE03_EP_G2 0x92D // Equalizer Adaptive FRP_EQTNBIT Lane03 EP G2
    #define CND003_PCIEPHYCFG_RSVPCIEPHYCFG_92D_7          0xF0                    // 0/x/x/x Reserved
    #define CND003_PCIEPHYCFG_FRP03_EQTNBISTEVT_G2_EP_2_0  (BIT1 + BIT2 + BIT3)    // 0/0/x/x DFE Weight2 Initial or Set Value
    #define CND003_PCIEPHYCFG_FRP03_EQTNBISTEN_G2_EP       BIT0                    // 0/0/x/x DFE Weight2 Manual Set Enable
#define CND003_PCIEPHYCFG_EQUALIZER_ADAPTIVE_FRP_EQTNBIT_LANE00_PHYC_G2 0x92E // Equalizer Adaptive FRP_EQTNBIT Lane00 PHYC G2
    #define CND003_PCIEPHYCFG_RSVPCIEPHYCFG_92E_7 PCIEPHYCFG_EQUALIZER_ADAPTIVE_FRP_EQTNBIT_LANE00_PHYC_G2 // 0/x/x/x Reserved
#define CND003_PCIEPHYCFG_EQUALIZER_ADAPTIVE_FRP_EQTNBIT_LANE01_PHYC_G2 0x92F // Equalizer Adaptive FRP_EQTNBIT Lane01 PHYC G2
    #define CND003_PCIEPHYCFG_RSVPCIEPHYCFG_92F_7 PCIEPHYCFG_EQUALIZER_ADAPTIVE_FRP_EQTNBIT_LANE01_PHYC_G2 // 0/x/x/x Reserved
#define CND003_PCIEPHYCFG_RESERVED_Z50 0x930 // Reserved
    #define CND003_PCIEPHYCFG_RSVPCIEPHYCFG_930_7 PCIEPHYCFG_RESERVED_Z50 // 0/x/x/x Reserved
#define CND003_PCIEPHYCFG_EQUALIZER_ADAPTIVE_FRP_EQTNBIT_LANE00_G3 0x940 // Equalizer Adaptive FRP_EQTNBIT Lane00 G3
    #define CND003_PCIEPHYCFG_RSVPCIEPHYCFG_940_7 PCIEPHYCFG_EQUALIZER_ADAPTIVE_FRP_EQTNBIT_LANE00_G3 // 0/x/x/x Reserved
#define CND003_PCIEPHYCFG_EQUALIZER_ADAPTIVE_FRP_EQTNBIT_LANE04_PHYA_G3 0x941 // Equalizer Adaptive FRP_EQTNBIT Lane04 PHYA G3
    #define CND003_PCIEPHYCFG_RSVPCIEPHYCFG_941_7              0xF0                    // 0/x/x/x Reserved
    #define CND003_PCIEPHYCFG_FRP04_EQTNBISTEVT_G3_PHYA_2_0    (BIT1 + BIT2 + BIT3)    // 0/0/x/x DFE Weight2 Initial or Set Value
    #define CND003_PCIEPHYCFG_FRP04_EQTNBISTEN_G3_PHYA         BIT0                    // 0/0/x/x DFE Weight2 Manual Set Enable
#define CND003_PCIEPHYCFG_EQUALIZER_ADAPTIVE_FRP_EQTNBIT_LANE00_PHYA_G3 0x942 // Equalizer Adaptive FRP_EQTNBIT Lane00 PHYA G3
    #define CND003_PCIEPHYCFG_RSVPCIEPHYCFG_942_7              0xF0                    // 0/x/x/x Reserved
    #define CND003_PCIEPHYCFG_FRP00_EQTNBISTEVT_G3_PHYA_2_0    (BIT1 + BIT2 + BIT3)    // 0/0/x/x DFE Weight2 Initial or Set Value
    #define CND003_PCIEPHYCFG_FRP00_EQTNBISTEN_G3_PHYA         BIT0                    // 0/0/x/x DFE Weight2 Manual Set Enable
#define CND003_PCIEPHYCFG_EQUALIZER_ADAPTIVE_FRP_EQTNBIT_LANE01_PHYA_G3 0x943 // Equalizer Adaptive FRP_EQTNBIT Lane01 PHYA G3
    #define CND003_PCIEPHYCFG_RSVPCIEPHYCFG_943_7              0xF0                    // 0/x/x/x Reserved
    #define CND003_PCIEPHYCFG_FRP01_EQTNBISTEVT_G3_PHYA_2_0    (BIT1 + BIT2 + BIT3)    // 0/0/x/x DFE Weight2 Initial or Set Value
    #define CND003_PCIEPHYCFG_FRP01_EQTNBISTEN_G3_PHYA         BIT0                    // 0/0/x/x DFE Weight2 Manual Set Enable
#define CND003_PCIEPHYCFG_EQUALIZER_ADAPTIVE_FRP_EQTNBIT_LANE02_PHYA_G3 0x944 // Equalizer Adaptive FRP_EQTNBIT Lane02 PHYA G3
    #define CND003_PCIEPHYCFG_RSVPCIEPHYCFG_944_7              0xF0                    // 0/x/x/x Reserved
    #define CND003_PCIEPHYCFG_FRP02_EQTNBISTEVT_G3_PHYA_2_0    (BIT1 + BIT2 + BIT3)    // 0/0/x/x DFE Weight2 Initial or Set Value
    #define CND003_PCIEPHYCFG_FRP02_EQTNBISTEN_G3_PHYA         BIT0                    // 0/0/x/x DFE Weight2 Manual Set Enable
#define CND003_PCIEPHYCFG_EQUALIZER_ADAPTIVE_FRP_EQTNBIT_LANE03_PHYA_G3 0x945 // Equalizer Adaptive FRP_EQTNBIT Lane03 PHYA G3
    #define CND003_PCIEPHYCFG_RSVPCIEPHYCFG_945_7              0xF0                    // 0/x/x/x Reserved
    #define CND003_PCIEPHYCFG_FRP03_EQTNBISTEVT_G3_PHYA_2_0    (BIT1 + BIT2 + BIT3)    // 0/0/x/x DFE Weight2 Initial or Set Value
    #define CND003_PCIEPHYCFG_FRP03_EQTNBISTEN_G3_PHYA         BIT0                    // 0/0/x/x DFE Weight2 Manual Set Enable
#define CND003_PCIEPHYCFG_EQUALIZER_ADAPTIVE_FRP_EQTNBIT_LANE00_PHYB_G3 0x946 // Equalizer Adaptive FRP_EQTNBIT Lane00 PHYB G3
    #define CND003_PCIEPHYCFG_RSVPCIEPHYCFG_946_7              0xF0                    // 0/x/x/x Reserved
    #define CND003_PCIEPHYCFG_FRP00_EQTNBISTEVT_G3_PHYB_2_0    (BIT1 + BIT2 + BIT3)    // 0/0/x/x DFE Weight2 Initial or Set Value
    #define CND003_PCIEPHYCFG_FRP00_EQTNBISTEN_G3_PHYB         BIT0                    // 0/0/x/x DFE Weight2 Manual Set Enable
#define CND003_PCIEPHYCFG_EQUALIZER_ADAPTIVE_FRP_EQTNBIT_LANE01_PHYB_G3 0x947 // Equalizer Adaptive FRP_EQTNBIT Lane01 PHYB G3
    #define CND003_PCIEPHYCFG_RSVPCIEPHYCFG_947_7              0xF0                    // 0/x/x/x Reserved
    #define CND003_PCIEPHYCFG_FRP01_EQTNBISTEVT_G3_PHYB_2_0    (BIT1 + BIT2 + BIT3)    // 0/0/x/x DFE Weight2 Initial or Set Value
    #define CND003_PCIEPHYCFG_FRP01_EQTNBISTEN_G3_PHYB         BIT0                    // 0/0/x/x DFE Weight2 Manual Set Enable
#define CND003_PCIEPHYCFG_EQUALIZER_ADAPTIVE_FRP_EQTNBIT_LANE02_PHYB_G3 0x948 // Equalizer Adaptive FRP_EQTNBIT Lane02 PHYB G3
    #define CND003_PCIEPHYCFG_RSVPCIEPHYCFG_948_7              0xF0                    // 0/x/x/x Reserved
    #define CND003_PCIEPHYCFG_FRP02_EQTNBISTEVT_G3_PHYB_2_0    (BIT1 + BIT2 + BIT3)    // 0/0/x/x DFE Weight2 Initial or Set Value
    #define CND003_PCIEPHYCFG_FRP02_EQTNBISTEN_G3_PHYB         BIT0                    // 0/0/x/x DFE Weight2 Manual Set Enable
#define CND003_PCIEPHYCFG_EQUALIZER_ADAPTIVE_FRP_EQTNBIT_LANE03_PHYB_G3 0x949 // Equalizer Adaptive FRP_EQTNBIT Lane03 PHYB G3
    #define CND003_PCIEPHYCFG_RSVPCIEPHYCFG_949_7              0xF0                    // 0/x/x/x Reserved
    #define CND003_PCIEPHYCFG_FRP03_EQTNBISTEVT_G3_PHYB_2_0    (BIT1 + BIT2 + BIT3)    // 0/0/x/x DFE Weight2 Initial or Set Value
    #define CND003_PCIEPHYCFG_FRP03_EQTNBISTEN_G3_PHYB         BIT0                    // 0/0/x/x DFE Weight2 Manual Set Enable
#define CND003_PCIEPHYCFG_EQUALIZER_ADAPTIVE_FRP_EQTNBIT_LANE00_EP_G3 0x94A // Equalizer Adaptive FRP_EQTNBIT Lane00 EP G3
    #define CND003_PCIEPHYCFG_RSVPCIEPHYCFG_94A_7          0xF0                    // 0/x/x/x Reserved
    #define CND003_PCIEPHYCFG_FRP00_EQTNBISTEVT_G3_EP_2_0  (BIT1 + BIT2 + BIT3)    // 0/0/x/x DFE Weight2 Initial or Set Value
    #define CND003_PCIEPHYCFG_FRP00_EQTNBISTEN_G3_EP       BIT0                    // 0/0/x/x DFE Weight2 Manual Set Enable
#define CND003_PCIEPHYCFG_EQUALIZER_ADAPTIVE_FRP_EQTNBIT_LANE01_EP_G3 0x94B // Equalizer Adaptive FRP_EQTNBIT Lane01 EP G3
    #define CND003_PCIEPHYCFG_RSVPCIEPHYCFG_94B_7          0xF0                    // 0/x/x/x Reserved
    #define CND003_PCIEPHYCFG_FRP01_EQTNBISTEVT_G3_EP_2_0  (BIT1 + BIT2 + BIT3)    // 0/0/x/x DFE Weight2 Initial or Set Value
    #define CND003_PCIEPHYCFG_FRP01_EQTNBISTEN_G3_EP       BIT0                    // 0/0/x/x DFE Weight2 Manual Set Enable
#define CND003_PCIEPHYCFG_EQUALIZER_ADAPTIVE_FRP_EQTNBIT_LANE02_EP_G3 0x94C // Equalizer Adaptive FRP_EQTNBIT Lane02 EP G3
    #define CND003_PCIEPHYCFG_RSVPCIEPHYCFG_94C_7          0xF0                    // 0/x/x/x Reserved
    #define CND003_PCIEPHYCFG_FRP02_EQTNBISTEVT_G3_EP_2_0  (BIT1 + BIT2 + BIT3)    // 0/0/x/x DFE Weight2 Initial or Set Value
    #define CND003_PCIEPHYCFG_FRP02_EQTNBISTEN_G3_EP       BIT0                    // 0/0/x/x DFE Weight2 Manual Set Enable
#define CND003_PCIEPHYCFG_EQUALIZER_ADAPTIVE_FRP_EQTNBIT_LANE03_EP_G3 0x94D // Equalizer Adaptive FRP_EQTNBIT Lane03 EP G3
    #define CND003_PCIEPHYCFG_RSVPCIEPHYCFG_94D_7          0xF0                    // 0/x/x/x Reserved
    #define CND003_PCIEPHYCFG_FRP03_EQTNBISTEVT_G3_EP_2_0  (BIT1 + BIT2 + BIT3)    // 0/0/x/x DFE Weight2 Initial or Set Value
    #define CND003_PCIEPHYCFG_FRP03_EQTNBISTEN_G3_EP       BIT0                    // 0/0/x/x DFE Weight2 Manual Set Enable
#define CND003_PCIEPHYCFG_EQUALIZER_ADAPTIVE_FRP_EQTNBIT_LANE00_PHYC_G3 0x94E // Equalizer Adaptive FRP_EQTNBIT Lane00 PHYC G3
    #define CND003_PCIEPHYCFG_RSVPCIEPHYCFG_94E_7 PCIEPHYCFG_EQUALIZER_ADAPTIVE_FRP_EQTNBIT_LANE00_PHYC_G3 // 0/x/x/x Reserved
#define CND003_PCIEPHYCFG_EQUALIZER_ADAPTIVE_FRP_EQTNBIT_LANE01_PHYC_G3 0x94F // Equalizer Adaptive FRP_EQTNBIT Lane01 PHYC G3
    #define CND003_PCIEPHYCFG_RSVPCIEPHYCFG_94F_7 PCIEPHYCFG_EQUALIZER_ADAPTIVE_FRP_EQTNBIT_LANE01_PHYC_G3 // 0/x/x/x Reserved
#define CND003_PCIEPHYCFG_RESERVED_Z51 0x950 // Reserved
    #define CND003_PCIEPHYCFG_RSVPCIEPHYCFG_950_7 PCIEPHYCFG_RESERVED_Z51 // 0/x/x/x Reserved
#define CND003_PCIEPHYCFG_EPHY_MACRO_TEST_MODE_CTL_FOR_LANE00 0x990 // EPHY MACRO Test Mode Control for Lane00
    #define CND003_PCIEPHYCFG_RSVPCIEPHYCFG_990_7 PCIEPHYCFG_EPHY_MACRO_TEST_MODE_CTL_FOR_LANE00 // 0/x/x/x Reserved
#define CND003_PCIEPHYCFG_EPHY_MACRO_TEST_MODE_CTL_FOR_LANE04_PHYA 0x991 // EPHY MACRO Test Mode Control for Lane04 PHYA
    #define CND003_PCIEPHYCFG_RSVPCIEPHYCFG_991_7  (BIT6 + BIT7)   // 0/x/x/x Reserved
    #define CND003_PCIEPHYCFG_FHP04_PG3_EQ_LS_PHYA BIT5            // 0/0/x/x EQTN Tuning Speed at PCIE Gen3
    #define CND003_PCIEPHYCFG_FHP04_RDETEN_PHYA    BIT4            // 0/0/x/x EPHY TX Receiver Detect Enable Control in MACRO Test Mode
    #define CND003_PCIEPHYCFG_FHP04_TXRDETPDB_PHYA BIT3            // 0/0/x/x EPHY TX Receiver Detect Power Down Control in MACRO Test Mode
    #define CND003_PCIEPHYCFG_FHP04_RXHZ_PHYA      BIT2            // 0/0/x/x EPHY RXHZ Control in MACRO Test Mode
    #define CND003_PCIEPHYCFG_FHP04_TXHZ_PHYA      BIT1            // 0/0/x/x EPHY TXHZ Control in MACRO Test Mode
    #define CND003_PCIEPHYCFG_FHP04_RXDEIDPDB_PHYA BIT0            // 0/0/x/x EPHY RX Electrical Idle Detect Power Down Control in MACRO Test Mode
#define CND003_PCIEPHYCFG_EPHY_MACRO_TEST_MODE_CTL_FOR_LANE00_PHYA 0x992 // EPHY MACRO Test Mode Control for Lane00 PHYA
    #define CND003_PCIEPHYCFG_RSVPCIEPHYCFG_992_7  (BIT6 + BIT7)   // 0/x/x/x Reserved
    #define CND003_PCIEPHYCFG_FHP00_PG3_EQ_LS_PHYA BIT5            // 0/0/x/x EQTN Tuning Speed at PCIE Gen3
    #define CND003_PCIEPHYCFG_FHP00_RDETEN_PHYA    BIT4            // 0/0/x/x EPHY TX Receiver Detect Enable Control in MACRO Test Mode
    #define CND003_PCIEPHYCFG_FHP00_TXRDETPDB_PHYA BIT3            // 0/0/x/x EPHY TX Receiver Detect Power Down Control in MACRO Test Mode
    #define CND003_PCIEPHYCFG_FHP00_RXHZ_PHYA      BIT2            // 0/0/x/x EPHY RXHZ Control in MACRO Test Mode
    #define CND003_PCIEPHYCFG_FHP00_TXHZ_PHYA      BIT1            // 0/0/x/x EPHY TXHZ Control in MACRO Test Mode
    #define CND003_PCIEPHYCFG_FHP00_RXDEIDPDB_PHYA BIT0            // 0/0/x/x EPHY RX Electrical Idle Detect Power Down Control in MACRO Test Mode
#define CND003_PCIEPHYCFG_EPHY_MACRO_TEST_MODE_CTL_FOR_LANE01_PHYA 0x993 // EPHY MACRO Test Mode Control for Lane01 PHYA
    #define CND003_PCIEPHYCFG_RSVPCIEPHYCFG_993_7  (BIT6 + BIT7)   // 0/x/x/x Reserved
    #define CND003_PCIEPHYCFG_FHP01_PG3_EQ_LS_PHYA BIT5            // 0/0/x/x EQTN Tuning Speed at PCIE Gen3
    #define CND003_PCIEPHYCFG_FHP01_RDETEN_PHYA    BIT4            // 0/0/x/x EPHY TX Receiver Detect Enable Control in MACRO Test Mode
    #define CND003_PCIEPHYCFG_FHP01_TXRDETPDB_PHYA BIT3            // 0/0/x/x EPHY TX Receiver Detect Power Down Control in MACRO Test Mode
    #define CND003_PCIEPHYCFG_FHP01_RXHZ_PHYA      BIT2            // 0/0/x/x EPHY RXHZ Control in MACRO Test Mode
    #define CND003_PCIEPHYCFG_FHP01_TXHZ_PHYA      BIT1            // 0/0/x/x EPHY TXHZ Control in MACRO Test Mode
    #define CND003_PCIEPHYCFG_FHP01_RXDEIDPDB_PHYA BIT0            // 0/0/x/x EPHY RX Electrical Idle Detect Power Down Control in MACRO Test Mode
#define CND003_PCIEPHYCFG_EPHY_MACRO_TEST_MODE_CTL_FOR_LANE02_PHYA 0x994 // EPHY MACRO Test Mode Control for Lane02 PHYA
    #define CND003_PCIEPHYCFG_RSVPCIEPHYCFG_994_7  (BIT6 + BIT7)   // 0/x/x/x Reserved
    #define CND003_PCIEPHYCFG_FHP02_PG3_EQ_LS_PHYA BIT5            // 0/0/x/x EQTN Tuning Speed at PCIE Gen3
    #define CND003_PCIEPHYCFG_FHP02_RDETEN_PHYA    BIT4            // 0/0/x/x EPHY TX Receiver Detect Enable Control in MACRO Test Mode
    #define CND003_PCIEPHYCFG_FHP02_TXRDETPDB_PHYA BIT3            // 0/0/x/x EPHY TX Receiver Detect Power Down Control in MACRO Test Mode
    #define CND003_PCIEPHYCFG_FHP02_RXHZ_PHYA      BIT2            // 0/0/x/x EPHY RXHZ Control in MACRO Test Mode
    #define CND003_PCIEPHYCFG_FHP02_TXHZ_PHYA      BIT1            // 0/0/x/x EPHY TXHZ Control in MACRO Test Mode
    #define CND003_PCIEPHYCFG_FHP02_RXDEIDPDB_PHYA BIT0            // 0/0/x/x EPHY RX Electrical Idle Detect Power Down Control in MACRO Test Mode
#define CND003_PCIEPHYCFG_EPHY_MACRO_TEST_MODE_CTL_FOR_LANE03_PHYA 0x995 // EPHY MACRO Test Mode Control for Lane03 _PHYA
    #define CND003_PCIEPHYCFG_RSVPCIEPHYCFG_995_7  (BIT6 + BIT7)   // 0/x/x/x Reserved
    #define CND003_PCIEPHYCFG_FHP03_PG3_EQ_LS_PHYA BIT5            // 0/0/x/x EQTN Tuning Speed at PCIE Gen3
    #define CND003_PCIEPHYCFG_FHP03_RDETEN_PHYA    BIT4            // 0/0/x/x EPHY TX Receiver Detect Enable Control in MACRO Test Mode
    #define CND003_PCIEPHYCFG_FHP03_TXRDETPDB_PHYA BIT3            // 0/0/x/x EPHY TX Receiver Detect Power Down Control in MACRO Test Mode
    #define CND003_PCIEPHYCFG_FHP03_RXHZ_PHYA      BIT2            // 0/0/x/x EPHY RXHZ Control in MACRO Test Mode
    #define CND003_PCIEPHYCFG_FHP03_TXHZ_PHYA      BIT1            // 0/0/x/x EPHY TXHZ Control in MACRO Test Mode
    #define CND003_PCIEPHYCFG_FHP03_RXDEIDPDB_PHYA BIT0            // 0/0/x/x EPHY RX Electrical Idle Detect Power Down Control in MACRO Test Mode
#define CND003_PCIEPHYCFG_EPHY_MACRO_TEST_MODE_CTL_FOR_LANE00_PHYB 0x996 // EPHY MACRO Test Mode Control for Lane00 PHYB
    #define CND003_PCIEPHYCFG_RSVPCIEPHYCFG_996_7  (BIT6 + BIT7)   // 0/x/x/x Reserved
    #define CND003_PCIEPHYCFG_FHP00_PG3_EQ_LS_PHYB BIT5            // 0/0/x/x EQTN Tuning Speed at PCIE Gen3
    #define CND003_PCIEPHYCFG_FHP00_RDETEN_PHYB    BIT4            // 0/0/x/x EPHY TX Receiver Detect Enable Control in MACRO Test Mode
    #define CND003_PCIEPHYCFG_FHP00_TXRDETPDB_PHYB BIT3            // 0/0/x/x EPHY TX Receiver Detect Power Down Control in MACRO Test Mode
    #define CND003_PCIEPHYCFG_FHP00_RXHZ_PHYB      BIT2            // 0/0/x/x EPHY RXHZ Control in MACRO Test Mode
    #define CND003_PCIEPHYCFG_FHP00_TXHZ_PHYB      BIT1            // 0/0/x/x EPHY TXHZ Control in MACRO Test Mode
    #define CND003_PCIEPHYCFG_FHP00_RXDEIDPDB_PHYB BIT0            // 0/0/x/x EPHY RX Electrical Idle Detect Power Down Control in MACRO Test Mode
#define CND003_PCIEPHYCFG_EPHY_MACRO_TEST_MODE_CTL_FOR_LANE01_PHYB 0x997 // EPHY MACRO Test Mode Control for Lane01 _PHYB
    #define CND003_PCIEPHYCFG_RSVPCIEPHYCFG_997_7  (BIT6 + BIT7)   // 0/x/x/x Reserved
    #define CND003_PCIEPHYCFG_FHP01_PG3_EQ_LS_PHYB BIT5            // 0/0/x/x EQTN Tuning Speed at PCIE Gen3
    #define CND003_PCIEPHYCFG_FHP01_RDETEN_PHYB    BIT4            // 0/0/x/x EPHY TX Receiver Detect Enable Control in MACRO Test Mode
    #define CND003_PCIEPHYCFG_FHP01_TXRDETPDB_PHYB BIT3            // 0/0/x/x EPHY TX Receiver Detect Power Down Control in MACRO Test Mode
    #define CND003_PCIEPHYCFG_FHP01_RXHZ_PHYB      BIT2            // 0/0/x/x EPHY RXHZ Control in MACRO Test Mode
    #define CND003_PCIEPHYCFG_FHP01_TXHZ_PHYB      BIT1            // 0/0/x/x EPHY TXHZ Control in MACRO Test Mode
    #define CND003_PCIEPHYCFG_FHP01_RXDEIDPDB_PHYB BIT0            // 0/0/x/x EPHY RX Electrical Idle Detect Power Down Control in MACRO Test Mode
#define CND003_PCIEPHYCFG_EPHY_MACRO_TEST_MODE_CTL_FOR_LANE02_PHYB 0x998 // EPHY MACRO Test Mode Control for Lane02_PHYB
    #define CND003_PCIEPHYCFG_RSVPCIEPHYCFG_998_7  (BIT6 + BIT7)   // 0/x/x/x Reserved
    #define CND003_PCIEPHYCFG_FHP02_PG3_EQ_LS_PHYB BIT5            // 0/0/x/x EQTN Tuning Speed at PCIE Gen3
    #define CND003_PCIEPHYCFG_FHP02_RDETEN_PHYB    BIT4            // 0/0/x/x EPHY TX Receiver Detect Enable Control in MACRO Test Mode
    #define CND003_PCIEPHYCFG_FHP02_TXRDETPDB_PHYB BIT3            // 0/0/x/x EPHY TX Receiver Detect Power Down Control in MACRO Test Mode
    #define CND003_PCIEPHYCFG_FHP02_RXHZ_PHYB      BIT2            // 0/0/x/x EPHY RXHZ Control in MACRO Test Mode
    #define CND003_PCIEPHYCFG_FHP02_TXHZ_PHYB      BIT1            // 0/0/x/x EPHY TXHZ Control in MACRO Test Mode
    #define CND003_PCIEPHYCFG_FHP02_RXDEIDPDB_PHYB BIT0            // 0/0/x/x EPHY RX Electrical Idle Detect Power Down Control in MACRO Test Mode
#define CND003_PCIEPHYCFG_EPHY_MACRO_TEST_MODE_CTL_FOR_LANE03_PHYB 0x999 // EPHY MACRO Test Mode Control for Lane03 _PHYB
    #define CND003_PCIEPHYCFG_RSVPCIEPHYCFG_999_7  (BIT6 + BIT7)   // 0/x/x/x Reserved
    #define CND003_PCIEPHYCFG_FHP03_PG3_EQ_LS_PHYB BIT5            // 0/0/x/x EQTN Tuning Speed at PCIE Gen3
    #define CND003_PCIEPHYCFG_FHP03_RDETEN_PHYB    BIT4            // 0/0/x/x EPHY TX Receiver Detect Enable Control in MACRO Test Mode
    #define CND003_PCIEPHYCFG_FHP03_TXRDETPDB_PHYB BIT3            // 0/0/x/x EPHY TX Receiver Detect Power Down Control in MACRO Test Mode
    #define CND003_PCIEPHYCFG_FHP03_RXHZ_PHYB      BIT2            // 0/0/x/x EPHY RXHZ Control in MACRO Test Mode
    #define CND003_PCIEPHYCFG_FHP03_TXHZ_PHYB      BIT1            // 0/0/x/x EPHY TXHZ Control in MACRO Test Mode
    #define CND003_PCIEPHYCFG_FHP03_RXDEIDPDB_PHYB BIT0            // 0/0/x/x EPHY RX Electrical Idle Detect Power Down Control in MACRO Test Mode
#define CND003_PCIEPHYCFG_EPHY_MACRO_TEST_MODE_CTL_FOR_LANE00_EP 0x99A // EPHY MACRO Test Mode Control for Lane00 EP
    #define CND003_PCIEPHYCFG_RSVPCIEPHYCFG_99A_7  (BIT6 + BIT7)   // 0/x/x/x Reserved
    #define CND003_PCIEPHYCFG_FHP00_PG3_EQ_LS      BIT5            // 0/0/x/x EQTN Tuning Speed at PCIE Gen3
    #define CND003_PCIEPHYCFG_FHP00_RDETEN         BIT4            // 0/0/x/x EPHY TX Receiver Detect Enable Control in MACRO Test Mode
    #define CND003_PCIEPHYCFG_FHP00_TXRDETPDB      BIT3            // 0/0/x/x EPHY TX Receiver Detect Power Down Control in MACRO Test Mode
    #define CND003_PCIEPHYCFG_FHP00_RXHZ           BIT2            // 0/0/x/x EPHY RXHZ Control in MACRO Test Mode
    #define CND003_PCIEPHYCFG_FHP00_TXHZ           BIT1            // 0/0/x/x EPHY TXHZ Control in MACRO Test Mode
    #define CND003_PCIEPHYCFG_FHP00_RXDEIDPDB      BIT0            // 0/0/x/x EPHY RX Electrical Idle Detect Power Down Control in MACRO Test Mode
#define CND003_PCIEPHYCFG_EPHY_MACRO_TEST_MODE_CTL_FOR_LANE01_EP 0x99B // EPHY MACRO Test Mode Control for Lane01_EP
    #define CND003_PCIEPHYCFG_RSVPCIEPHYCFG_99B_7  (BIT6 + BIT7)   // 0/x/x/x Reserved
    #define CND003_PCIEPHYCFG_FHP01_PG3_EQ_LS      BIT5            // 0/0/x/x EQTN Tuning Speed at PCIE Gen3
    #define CND003_PCIEPHYCFG_FHP01_RDETEN         BIT4            // 0/0/x/x EPHY TX Receiver Detect Enable Control in MACRO Test Mode
    #define CND003_PCIEPHYCFG_FHP01_TXRDETPDB      BIT3            // 0/0/x/x EPHY TX Receiver Detect Power Down Control in MACRO Test Mode
    #define CND003_PCIEPHYCFG_FHP01_RXHZ           BIT2            // 0/0/x/x EPHY RXHZ Control in MACRO Test Mode
    #define CND003_PCIEPHYCFG_FHP01_TXHZ           BIT1            // 0/0/x/x EPHY TXHZ Control in MACRO Test Mode
    #define CND003_PCIEPHYCFG_FHP01_RXDEIDPDB      BIT0            // 0/0/x/x EPHY RX Electrical Idle Detect Power Down Control in MACRO Test Mode
#define CND003_PCIEPHYCFG_EPHY_MACRO_TEST_MODE_CTL_FOR_LANE02_EP 0x99C // EPHY MACRO Test Mode Control for Lane02_EP
    #define CND003_PCIEPHYCFG_RSVPCIEPHYCFG_99C_7  (BIT6 + BIT7)   // 0/x/x/x Reserved
    #define CND003_PCIEPHYCFG_FHP02_PG3_EQ_LS      BIT5            // 0/0/x/x EQTN Tuning Speed at PCIE Gen3
    #define CND003_PCIEPHYCFG_FHP02_RDETEN         BIT4            // 0/0/x/x EPHY TX Receiver Detect Enable Control in MACRO Test Mode
    #define CND003_PCIEPHYCFG_FHP02_TXRDETPDB      BIT3            // 0/0/x/x EPHY TX Receiver Detect Power Down Control in MACRO Test Mode
    #define CND003_PCIEPHYCFG_FHP02_RXHZ           BIT2            // 0/0/x/x EPHY RXHZ Control in MACRO Test Mode
    #define CND003_PCIEPHYCFG_FHP02_TXHZ           BIT1            // 0/0/x/x EPHY TXHZ Control in MACRO Test Mode
    #define CND003_PCIEPHYCFG_FHP02_RXDEIDPDB      BIT0            // 0/0/x/x EPHY RX Electrical Idle Detect Power Down Control in MACRO Test Mode
#define CND003_PCIEPHYCFG_EPHY_MACRO_TEST_MODE_CTL_FOR_LANE03_EP 0x99D // EPHY MACRO Test Mode Control for Lane03_EP
    #define CND003_PCIEPHYCFG_RSVPCIEPHYCFG_99D_7  (BIT6 + BIT7)   // 0/x/x/x Reserved
    #define CND003_PCIEPHYCFG_FHP03_PG3_EQ_LS      BIT5            // 0/0/x/x EQTN Tuning Speed at PCIE Gen3
    #define CND003_PCIEPHYCFG_FHP03_RDETEN         BIT4            // 0/0/x/x EPHY TX Receiver Detect Enable Control in MACRO Test Mode
    #define CND003_PCIEPHYCFG_FHP03_TXRDETPDB      BIT3            // 0/0/x/x EPHY TX Receiver Detect Power Down Control in MACRO Test Mode
    #define CND003_PCIEPHYCFG_FHP03_RXHZ           BIT2            // 0/0/x/x EPHY RXHZ Control in MACRO Test Mode
    #define CND003_PCIEPHYCFG_FHP03_TXHZ           BIT1            // 0/0/x/x EPHY TXHZ Control in MACRO Test Mode
    #define CND003_PCIEPHYCFG_FHP03_RXDEIDPDB      BIT0            // 0/0/x/x EPHY RX Electrical Idle Detect Power Down Control in MACRO Test Mode
#define CND003_PCIEPHYCFG_EPHY_MACRO_TEST_MODE_CTL_FOR_LANE00_PHYC 0x99E // EPHY MACRO Test Mode Control for Lane00_PHYC
    #define CND003_PCIEPHYCFG_RSVPCIEPHYCFG_99E_7 PCIEPHYCFG_EPHY_MACRO_TEST_MODE_CTL_FOR_LANE00_PHYC // 0/x/x/x Reserved
#define CND003_PCIEPHYCFG_EPHY_MACRO_TEST_MODE_CTL_FOR_LANE01_PHYC 0x99F // EPHY MACRO Test Mode Control for Lane01_PHYC
    #define CND003_PCIEPHYCFG_RSVPCIEPHYCFG_99F_7 PCIEPHYCFG_EPHY_MACRO_TEST_MODE_CTL_FOR_LANE01_PHYC // 0/x/x/x Reserved
#define CND003_PCIEPHYCFG_RESERVED_Z52 0x9A0 // Reserved
    #define CND003_PCIEPHYCFG_RSVPCIEPHYCFG_9A0_23 PCIEPHYCFG_RESERVED_Z52 // 0/x/x/x Reserved
#define CND003_PCIEPHYCFG_LEQ_DC_GAIN_OUTPUT_EPHY_LANE_00 0xA00 // LEQ DC Gain Output EPHY_Lane 00
    #define CND003_PCIEPHYCFG_RSV_A00 PCIEPHYCFG_LEQ_DC_GAIN_OUTPUT_EPHY_LANE_00 // 0/x/x/x Reserved
#define CND003_PCIEPHYCFG_LEQ_HF_GAIN_OUTPUT_EPHY_LANE_00 0xA01 // LEQ HF Gain Output EPHY_Lane 00
    #define CND003_PCIEPHYCFG_RSV_A01 PCIEPHYCFG_LEQ_HF_GAIN_OUTPUT_EPHY_LANE_00 // 0/x/x/X Reserved
#define CND003_PCIEPHYCFG_LEQ_OFS_OUTPUT_EPHY_LANE_00 0xA02 // LEQ Offset Output EPHY_Lane 00
    #define CND003_PCIEPHYCFG_RSV_A02 PCIEPHYCFG_LEQ_OFS_OUTPUT_EPHY_LANE_00 // 0/x/x/x Reserved
#define CND003_PCIEPHYCFG_LEQ_WEIGHT1_OUTPUT_EPHY_LANE_00 0xA03 // LEQ Weight1 Output EPHY_Lane 00
    #define CND003_PCIEPHYCFG_RSV_A03 PCIEPHYCFG_LEQ_WEIGHT1_OUTPUT_EPHY_LANE_00 // 0/x/x/x Reserved
#define CND003_PCIEPHYCFG_LEQ_WEIGHT2_OUTPUT_EPHY_LANE_00 0xA04 // LEQ Weight2 Output EPHY_Lane 00
    #define CND003_PCIEPHYCFG_RSV_A04 PCIEPHYCFG_LEQ_WEIGHT2_OUTPUT_EPHY_LANE_00 // 0/x/x/x Reserved
#define CND003_PCIEPHYCFG_RESERVED_Z53 0xA05 // Reserved
    #define CND003_PCIEPHYCFG_RSV_A05 PCIEPHYCFG_RESERVED_Z53 // 0/R/x/x Reserved
#define CND003_PCIEPHYCFG_RESERVED_Z54 0xA06 // Reserved
    #define CND003_PCIEPHYCFG_RSV_A06 PCIEPHYCFG_RESERVED_Z54 // 0/R/x/x Reserved
#define CND003_PCIEPHYCFG_RESERVED_Z55 0xA07 // Reserved
    #define CND003_PCIEPHYCFG_RSV_A07 PCIEPHYCFG_RESERVED_Z55 // 0/R/x/x Reserved
#define CND003_PCIEPHYCFG_FAR_END_DEV_FULL_SWING_VALUE_LANE00 0xA08 // FAR-END Device Full Swing Value Lane00
    #define CND003_PCIEPHYCFG_RSV_A08 PCIEPHYCFG_FAR_END_DEV_FULL_SWING_VALUE_LANE00 // 0/R/x/x Reserved
#define CND003_PCIEPHYCFG_FAR_END_DEV_LOW_FREQ_VALUE_LANE00_PHYB 0xA09 // FAR-END Device Low Frequency Value Lane00 PHYB
    #define CND003_PCIEPHYCFG_RSV_A09 PCIEPHYCFG_FAR_END_DEV_LOW_FREQ_VALUE_LANE00_PHYB // 0/R/x/x Reserved
#define CND003_PCIEPHYCFG_FAREND_TX_PRESET_00 0xA0A // FAREND_TX_PRESET_ 00
    #define CND003_PCIEPHYCFG_RSV_A0A PCIEPHYCFG_FAREND_TX_PRESET_00 // 0/R/x/x Reserved
#define CND003_PCIEPHYCFG_FAREND_PRE_CURSOR_00 0xA0B // FAREND_PRE_CURSOR_00
    #define CND003_PCIEPHYCFG_RSV_A0B PCIEPHYCFG_FAREND_PRE_CURSOR_00 // 0/R/x/x Reserved
#define CND003_PCIEPHYCFG_FAREND_CURSOR_00 0xA0C // FAREND_CURSOR_00
    #define CND003_PCIEPHYCFG_RSV_A0C PCIEPHYCFG_FAREND_CURSOR_00 // 0/R/x/x Reserved
#define CND003_PCIEPHYCFG_FAREND_POST_CURSOR_00 0xA0D // FAREND_POST_CURSOR_00
    #define CND003_PCIEPHYCFG_RSV_A0D PCIEPHYCFG_FAREND_POST_CURSOR_00 // 0/R/x/x Reserved
#define CND003_PCIEPHYCFG_BIT_ERR_RATE_00 0xA0E // BIT_ERROR_RATE_00
    #define CND003_PCIEPHYCFG_RSV_A0E PCIEPHYCFG_BIT_ERR_RATE_00 // 0/R/x/x Reserved
#define CND003_PCIEPHYCFG_FAREND_USE_TX_PRESET_AND_RCV_00 0xA0F // Farend Use TX Preset and RCV 00
    #define CND003_PCIEPHYCFG_RSV_A0F PCIEPHYCFG_FAREND_USE_TX_PRESET_AND_RCV_00 // 0/R/x/x Reserved
#define CND003_PCIEPHYCFG_LEQ_DC_GAIN_OUTPUT_EPHY_PHYA_LANE_04 0xA10 // LEQ DC Gain Output EPHY_PHYA Lane 04
    #define CND003_PCIEPHYCFG_RSV_PHYA_A10     (BIT5 + BIT6 + BIT7)    // 0/R/x/x Reserved
    #define CND003_PCIEPHYCFG_EP04_DCOUT_PHYA  0x1F                    // HwInit/x/x/x EPHY Lane4 LEQ DC Gain Output 
#define CND003_PCIEPHYCFG_LEQ_HF_GAIN_OUTPUT_EPHY_PHYA_LANE_04 0xA11 // LEQ HF Gain Output EPHY_PHYA Lane 04
    #define CND003_PCIEPHYCFG_RSV_PHYA_A11     (BIT5 + BIT6 + BIT7)    // 0/R/x/x Reserved
    #define CND003_PCIEPHYCFG_EP04_HFOUT_PHYA  0x1F                    // HwInit/x/x/x EPHY Lane4 LEQ HF Gain Output 
#define CND003_PCIEPHYCFG_LEQ_OFS_OUTPUT_EPHY_PHYA_LANE_04 0xA12 // LEQ Offset Output EPHY_PHYA Lane 04
    #define CND003_PCIEPHYCFG_RSV_PHYA_A12     (BIT5 + BIT6 + BIT7)    // 0/R/x/x Reserved
    #define CND003_PCIEPHYCFG_EP04_OSOUT_PHYA  0x1F                    // HwInit/x/x/x EPHY Lane4 LEQ OS Gain Output
#define CND003_PCIEPHYCFG_LEQ_WEIGHT1_OUTPUT_EPHY_PHYA_LANE_04 0xA13 // LEQ Weight1 Output EPHY_PHYA Lane 04
    #define CND003_PCIEPHYCFG_RSV_PHYA_A13     (BIT5 + BIT6 + BIT7)    // 0/R/x/x Reserved
    #define CND003_PCIEPHYCFG_EP04_W1OUT_PHYA  0x1F                    // HwInit/x/x/x EPHY Lane4 DFE Weight1 Output 
#define CND003_PCIEPHYCFG_LEQ_WEIGHT2_OUTPUT_EPHY_PHYA_LANE_04 0xA14 // LEQ Weight2 Output EPHY_PHYA Lane 04
    #define CND003_PCIEPHYCFG_RSV_PHYA_A14     (BIT5 + BIT6 + BIT7)    // 0/R/x/x Reserved
    #define CND003_PCIEPHYCFG_EP04_W2OUT_PHYA  0x1F                    // HwInit/x/x/x EPHY Lane4 DFE Weight2 Output 
#define CND003_PCIEPHYCFG_RESERVED_Z56 0xA15 // Reserved
    #define CND003_PCIEPHYCFG_RSV_A15 PCIEPHYCFG_RESERVED_Z56 // 0/R/x/x Reserved
#define CND003_PCIEPHYCFG_RESERVED_Z57 0xA16 // Reserved
    #define CND003_PCIEPHYCFG_RSV_A16 PCIEPHYCFG_RESERVED_Z57 // 0/R/x/x Reserved
#define CND003_PCIEPHYCFG_RESERVED_Z58 0xA17 // Reserved
    #define CND003_PCIEPHYCFG_RSV_PHYA_A17 PCIEPHYCFG_RESERVED_Z58 // 0/R/x/x Reserved
#define CND003_PCIEPHYCFG_FAR_END_DEV_FULL_SWING_VALUE_LANE40_PHYA 0xA18 // FAR-END Device Full Swing Value Lane40 PHYA
    #define CND003_PCIEPHYCFG_RSV_PHYA_A18 PCIEPHYCFG_FAR_END_DEV_FULL_SWING_VALUE_LANE40_PHYA // 0/R/x/x Reserved
#define CND003_PCIEPHYCFG_FAR_END_DEV_LOW_FREQ_VALUE_LANE40_PHYA 0xA19 // FAR-END Device Low Frequency Value Lane40 PHYA
    #define CND003_PCIEPHYCFG_RSV_PHYA_A19 PCIEPHYCFG_FAR_END_DEV_LOW_FREQ_VALUE_LANE40_PHYA // 0/R/x/x Reserved
#define CND003_PCIEPHYCFG_FAREND_TX_PRESET_04_PHYA 0xA1A // FAREND_TX_PRESET_ 04_PHYA
    #define CND003_PCIEPHYCFG_RSV_PHYA_A1A PCIEPHYCFG_FAREND_TX_PRESET_04_PHYA // 0/R/x/x Reserved
#define CND003_PCIEPHYCFG_FAREND_PRE_CURSOR_04_PHYA 0xA1B // FAREND_PRE_CURSOR_ 04_PHYA
    #define CND003_PCIEPHYCFG_RSV_PHYA_A1B PCIEPHYCFG_FAREND_PRE_CURSOR_04_PHYA // 0/R/x/x Reserved
#define CND003_PCIEPHYCFG_FAREND_CURSOR_04_PHYA 0xA1C // FAREND_CURSOR_ 04_PHYA
    #define CND003_PCIEPHYCFG_RSV_PHYA_A1C PCIEPHYCFG_FAREND_CURSOR_04_PHYA // 0/R/x/x Reserved
#define CND003_PCIEPHYCFG_FAREND_POST_CURSOR_04_PHYA 0xA1D // FAREND_POST_CURSOR_ 04_PHYA
    #define CND003_PCIEPHYCFG_RSV_PHYA_A1D PCIEPHYCFG_FAREND_POST_CURSOR_04_PHYA // 0/R/x/x Reserved
#define CND003_PCIEPHYCFG_BIT_ERR_RATE_04_PHYA 0xA1E // BIT_ERROR_RATE_ 04_PHYA
    #define CND003_PCIEPHYCFG_RSV_A1E PCIEPHYCFG_BIT_ERR_RATE_04_PHYA // 0/0/x/x Reserved
#define CND003_PCIEPHYCFG_FAREND_USE_TX_PRESET_AND_RCV_04_PHYA 0xA1F // Farend Use TX Preset and RCV 04 PHYA
    #define CND003_PCIEPHYCFG_RSV_A1F PCIEPHYCFG_FAREND_USE_TX_PRESET_AND_RCV_04_PHYA // 0/R/x/x Reserved
#define CND003_PCIEPHYCFG_LEQ_DC_GAIN_OUTPUT_EPHY_PHYA_LANE_00 0xA20 // LEQ DC Gain Output EPHY_PHYA Lane 00
    #define CND003_PCIEPHYCFG_RSV_PHYA_A20     (BIT5 + BIT6 + BIT7)    // 0/R/x/x Reserved
    #define CND003_PCIEPHYCFG_EP00_DCOUT_PHYA  0x1F                    // HwInit/x/x/x EPHY Lane0 LEQ DC Gain Output 
#define CND003_PCIEPHYCFG_LEQ_HF_GAIN_OUTPUT_EPHY_PHYA_LANE_00 0xA21 // LEQ HF Gain Output EPHY_PHYA Lane 00
    #define CND003_PCIEPHYCFG_RSV_PHYA_A21     (BIT5 + BIT6 + BIT7)    // 0/R/x/x Reserved
    #define CND003_PCIEPHYCFG_EP00_HFOUT_PHYA  0x1F                    // HwInit/x/x/x EPHY Lane0 LEQ HF Gain Output 
#define CND003_PCIEPHYCFG_LEQ_OFS_OUTPUT_EPHY_PHYA_LANE_00 0xA22 // LEQ Offset Output EPHY_PHYA Lane 00
    #define CND003_PCIEPHYCFG_RSV_PHYA_A22     (BIT5 + BIT6 + BIT7)    // 0/R/x/x Reserved
    #define CND003_PCIEPHYCFG_EP00_OSOUT_PHYA  0x1F                    // HwInit/x/x/x EPHY Lane0 LEQ OS Gain Output
#define CND003_PCIEPHYCFG_LEQ_WEIGHT1_OUTPUT_EPHY_PHYA_LANE_00 0xA23 // LEQ Weight1 Output EPHY_PHYA Lane 00
    #define CND003_PCIEPHYCFG_RSV_PHYA_A23     (BIT5 + BIT6 + BIT7)    // 0/R/x/x Reserved
    #define CND003_PCIEPHYCFG_EP00_W1OUT_PHYA  0x1F                    // HwInit/x/x/x EPHY Lane0 DFE Weight1 Output 
#define CND003_PCIEPHYCFG_LEQ_WEIGHT2_OUTPUT_EPHY_PHYA_LANE_00 0xA24 // LEQ Weight2 Output EPHY_PHYA Lane 00
    #define CND003_PCIEPHYCFG_RSV_PHYA_A24     (BIT5 + BIT6 + BIT7)    // 0/R/x/x Reserved
    #define CND003_PCIEPHYCFG_EP00_W2OUT_PHYA  0x1F                    // HwInit/x/x/x EPHY Lane0 DFE Weight2 Output 
#define CND003_PCIEPHYCFG_RESERVED_Z59 0xA25 // Reserved
    #define CND003_PCIEPHYCFG_RSV_A25 PCIEPHYCFG_RESERVED_Z59 // 0/R/x/x Reserved
#define CND003_PCIEPHYCFG_RESERVED_Z60 0xA26 // Reserved
    #define CND003_PCIEPHYCFG_RSV_A26 PCIEPHYCFG_RESERVED_Z60 // 0/R/x/x Reserved
#define CND003_PCIEPHYCFG_RESERVED_Z61 0xA27 // Reserved
    #define CND003_PCIEPHYCFG_RSV_PHYA_A27 PCIEPHYCFG_RESERVED_Z61 // 0/R/x/x Reserved
#define CND003_PCIEPHYCFG_FAR_END_DEV_FULL_SWING_VALUE_LANE00_PHYA 0xA28 // FAR-END Device Full Swing Value Lane00 PHYA
    #define CND003_PCIEPHYCFG_RSV_PHYA_A28 PCIEPHYCFG_FAR_END_DEV_FULL_SWING_VALUE_LANE00_PHYA // 0/R/x/x Reserved
#define CND003_PCIEPHYCFG_FAR_END_DEV_LOW_FREQ_VALUE_LANE00_PHYA 0xA29 // FAR-END Device Low Frequency Value Lane00 PHYA
    #define CND003_PCIEPHYCFG_RSV_PHYA_A29 PCIEPHYCFG_FAR_END_DEV_LOW_FREQ_VALUE_LANE00_PHYA // 0/R/x/x Reserved
#define CND003_PCIEPHYCFG_FAREND_TX_PRESET_00_PHYA 0xA2A // FAREND_TX_PRESET_ 00_PHYA
    #define CND003_PCIEPHYCFG_RSV_PHYA_A2A PCIEPHYCFG_FAREND_TX_PRESET_00_PHYA // 0/R/x/x Reserved
#define CND003_PCIEPHYCFG_FAREND_PRE_CURSOR_00_PHYA 0xA2B // FAREND_PRE_CURSOR_ 00_PHYA
    #define CND003_PCIEPHYCFG_RSV_PHYA_A2B PCIEPHYCFG_FAREND_PRE_CURSOR_00_PHYA // 0/R/x/x Reserved
#define CND003_PCIEPHYCFG_FAREND_CURSOR_00_PHYA 0xA2C // FAREND_CURSOR_ 00_PHYA
    #define CND003_PCIEPHYCFG_RSV_PHYA_A2C PCIEPHYCFG_FAREND_CURSOR_00_PHYA // 0/R/x/x Reserved
#define CND003_PCIEPHYCFG_FAREND_POST_CURSOR_00_PHYA 0xA2D // FAREND_POST_CURSOR_ 00_PHYA
    #define CND003_PCIEPHYCFG_RSV_PHYA_A2D PCIEPHYCFG_FAREND_POST_CURSOR_00_PHYA // 0/R/x/x Reserved
#define CND003_PCIEPHYCFG_BIT_ERR_RATE_00_PHYA 0xA2E // BIT_ERROR_RATE_ 00_PHYA
    #define CND003_PCIEPHYCFG_RSV_A2E PCIEPHYCFG_BIT_ERR_RATE_00_PHYA // 0/0/x/x Reserved
#define CND003_PCIEPHYCFG_FAREND_USE_TX_PRESET_AND_RCV_PHYA_00 0xA2F // Farend Use TX Preset and RCV PHYA 00
    #define CND003_PCIEPHYCFG_RSV_A2F PCIEPHYCFG_FAREND_USE_TX_PRESET_AND_RCV_PHYA_00 // 0/R/x/x Reserved
#define CND003_PCIEPHYCFG_LEQ_DC_GAIN_OUTPUT_EPHY_PHYA_LANE_01 0xA30 // LEQ DC Gain Output EPHY_PHYA Lane 01
    #define CND003_PCIEPHYCFG_RSV_PHYA_A30     (BIT5 + BIT6 + BIT7)    // 0/R/x/x Reserved
    #define CND003_PCIEPHYCFG_EP01_DCOUT_PHYA  0x1F                    // HwInit/x/x/x EPHY Lane1 LEQ DC Gain Output 
#define CND003_PCIEPHYCFG_LEQ_HF_GAIN_OUTPUT_EPHY_PHYA_LANE_01 0xA31 // LEQ HF Gain Output EPHY_PHYA Lane 01
    #define CND003_PCIEPHYCFG_RSV_PHYA_A31     (BIT5 + BIT6 + BIT7)    // 0/R/x/x Reserved
    #define CND003_PCIEPHYCFG_EP01_HFOUT_PHYA  0x1F                    // HwInit/x/x/x EPHY Lane1 LEQ HF Gain Output
#define CND003_PCIEPHYCFG_LEQ_OFS_OUTPUT_EPHY_PHYA_LANE_01 0xA32 // LEQ Offset Output EPHY_PHYA Lane 01
    #define CND003_PCIEPHYCFG_RSV_PHYA_A32     (BIT5 + BIT6 + BIT7)    // 0/R/x/x Reserved
    #define CND003_PCIEPHYCFG_EP01_OSOUT_PHYA  0x1F                    // HwInit/x/x/x EPHY Lane1 LEQ OS Gain Output
#define CND003_PCIEPHYCFG_LEQ_WEIGHT1_OUTPUT_EPHY_PHYA_LANE_01 0xA33 // LEQ Weight1 Output EPHY_PHYA Lane 01
    #define CND003_PCIEPHYCFG_RSV_PHYA_A33     (BIT5 + BIT6 + BIT7)    // 0/R/x/x Reserved
    #define CND003_PCIEPHYCFG_EP01_W1OUT_PHYA  0x1F                    // HwInit/x/x/x EPHY Lane1 DFE Weight1 Output
#define CND003_PCIEPHYCFG_LEQ_WEIGHT2_OUTPUT_EPHY_PHYA_LANE_01 0xA34 // LEQ Weight2 Output EPHY_PHYA Lane 01
    #define CND003_PCIEPHYCFG_RSV_PHYA_A34     (BIT5 + BIT6 + BIT7)    // 0/R/x/x Reserved
    #define CND003_PCIEPHYCFG_EP01_W2OUT_PHYA  0x1F                    // HwInit/x/x/x EPHY Lane1 DFE Weight2 Output
#define CND003_PCIEPHYCFG_RESERVED_Z62 0xA35 // Reserved
    #define CND003_PCIEPHYCFG_RSV_A35 PCIEPHYCFG_RESERVED_Z62 // 0/R/x/x Reserved
#define CND003_PCIEPHYCFG_RESERVED_Z63 0xA36 // Reserved
    #define CND003_PCIEPHYCFG_RSV_A36 PCIEPHYCFG_RESERVED_Z63 // 0/R/x/x Reserved
#define CND003_PCIEPHYCFG_RESERVED_Z64 0xA37 // Reserved
    #define CND003_PCIEPHYCFG_RSV_PHYA_A37 PCIEPHYCFG_RESERVED_Z64 // 0/R/x/x Reserved
#define CND003_PCIEPHYCFG_FAR_END_DEV_FULL_SWING_VALUE_LANE01_PHYA 0xA38 // FAR-END Device Full Swing Value Lane01 PHYA
    #define CND003_PCIEPHYCFG_RSV_PHYA_A38 PCIEPHYCFG_FAR_END_DEV_FULL_SWING_VALUE_LANE01_PHYA // 0/R/x/x Reserved
#define CND003_PCIEPHYCFG_FAR_END_DEV_LOW_FREQ_VALUE_LANE01_PHYA 0xA39 // FAR-END Device Low Frequency Value Lane01 PHYA
    #define CND003_PCIEPHYCFG_RSV_PHYA_A39 PCIEPHYCFG_FAR_END_DEV_LOW_FREQ_VALUE_LANE01_PHYA // 0/R/x/x Reserved
#define CND003_PCIEPHYCFG_FAREND_TX_PRESET_01_PHYA 0xA3A // FAREND_TX_PRESET_ 01_PHYA
    #define CND003_PCIEPHYCFG_RSV_PHYA_A3A PCIEPHYCFG_FAREND_TX_PRESET_01_PHYA // 0/R/x/x Reserved
#define CND003_PCIEPHYCFG_FAREND_PRE_CURSOR_01_PHYA 0xA3B // FAREND_PRE_CURSOR_ 01_PHYA
    #define CND003_PCIEPHYCFG_RSV_PHYA_A3B PCIEPHYCFG_FAREND_PRE_CURSOR_01_PHYA // 0/R/x/x Reserved
#define CND003_PCIEPHYCFG_FAREND_CURSOR_01_PHYA 0xA3C // FAREND_CURSOR_ 01_PHYA
    #define CND003_PCIEPHYCFG_RSV_PHYA_A3C PCIEPHYCFG_FAREND_CURSOR_01_PHYA // 0/R/x/x Reserved
#define CND003_PCIEPHYCFG_FAREND_POST_CURSOR_01_PHYA 0xA3D // FAREND_POST_CURSOR_ 01_PHYA
    #define CND003_PCIEPHYCFG_RSV_PHYA_A3D PCIEPHYCFG_FAREND_POST_CURSOR_01_PHYA // 0/R/x/x Reserved
#define CND003_PCIEPHYCFG_BIT_ERR_RATE_01_PHYA 0xA3E // BIT_ERROR_RATE_ 01_PHYA
    #define CND003_PCIEPHYCFG_RSV_A3E PCIEPHYCFG_BIT_ERR_RATE_01_PHYA // 0/0/x/x Reserved
#define CND003_PCIEPHYCFG_FAREND_USE_TX_PRESET_AND_RCV_PHYA_01 0xA3F // Farend Use TX Preset and RCV PHYA 01
    #define CND003_PCIEPHYCFG_RSV_A3F PCIEPHYCFG_FAREND_USE_TX_PRESET_AND_RCV_PHYA_01 // 0/R/x/x Reserved
#define CND003_PCIEPHYCFG_LEQ_DC_GAIN_OUTPUT_EPHY_PHYA_LANE_02 0xA40 // LEQ DC Gain Output EPHY_PHYA Lane 02
    #define CND003_PCIEPHYCFG_RSV_PHYA_A40     (BIT5 + BIT6 + BIT7)    // 0/R/x/x Reserved
    #define CND003_PCIEPHYCFG_EP02_DCOUT_PHYA  0x1F                    // HwInit/x/x/x EPHY Lane2 LEQ DC Gain Output
#define CND003_PCIEPHYCFG_LEQ_HF_GAIN_OUTPUT_EPHY_PHYA_LANE_02 0xA41 // LEQ HF Gain Output EPHY_PHYA Lane 02
    #define CND003_PCIEPHYCFG_RSV_PHYA_A41     (BIT5 + BIT6 + BIT7)    // 0/R/x/x Reserved
    #define CND003_PCIEPHYCFG_EP02_HFOUT_PHYA  0x1F                    // HwInit/x/x/x EPHY Lane2 LEQ HF Gain Output
#define CND003_PCIEPHYCFG_LEQ_OFS_OUTPUT_EPHY_PHYA_LANE_02 0xA42 // LEQ Offset Output EPHY_PHYA Lane 02
    #define CND003_PCIEPHYCFG_RSV_PHYA_A42     (BIT5 + BIT6 + BIT7)    // 0/R/x/x Reserved
    #define CND003_PCIEPHYCFG_EP02_OSOUT_PHYA  0x1F                    // HwInit/x/x/x EPHY Lane2 LEQ OS Gain Output
#define CND003_PCIEPHYCFG_LEQ_WEIGHT1_OUTPUT_EPHY_PHYA_LANE_02 0xA43 // LEQ Weight1 Output EPHY_PHYA Lane 02
    #define CND003_PCIEPHYCFG_RSV_PHYA_A43     (BIT5 + BIT6 + BIT7)    // 0/R/x/x Reserved
    #define CND003_PCIEPHYCFG_EP02_W1OUT_PHYA  0x1F                    // HwInit/x/x/x EPHY Lane2 DFE Weight1 Output
#define CND003_PCIEPHYCFG_LEQ_WEIGHT2_OUTPUT_EPHY_PHYA_LANE_02 0xA44 // LEQ Weight2 Output EPHY_PHYA Lane 02
    #define CND003_PCIEPHYCFG_RSV_PHYA_A44     (BIT5 + BIT6 + BIT7)    // 0/R/x/x Reserved
    #define CND003_PCIEPHYCFG_EP02_W2OUT_PHYA  0x1F                    // HwInit/x/x/x EPHY Lane2 DFE Weight2 Output
#define CND003_PCIEPHYCFG_RESERVED_Z65 0xA45 // Reserved
    #define CND003_PCIEPHYCFG_RSV_A45 PCIEPHYCFG_RESERVED_Z65 // 0/R/x/x Reserved
#define CND003_PCIEPHYCFG_RESERVED_Z66 0xA46 // Reserved
    #define CND003_PCIEPHYCFG_RSV_A46 PCIEPHYCFG_RESERVED_Z66 // 0/R/x/x Reserved
#define CND003_PCIEPHYCFG_RESERVED_Z67 0xA47 // Reserved
    #define CND003_PCIEPHYCFG_RSV_PHYA_A47 PCIEPHYCFG_RESERVED_Z67 // 0/R/x/x Reserved
#define CND003_PCIEPHYCFG_FAR_END_DEV_FULL_SWING_VALUE_LANE02_PHYA 0xA48 // FAR-END Device Full Swing Value Lane02 PHYA
    #define CND003_PCIEPHYCFG_RSV_PHYA_A48 PCIEPHYCFG_FAR_END_DEV_FULL_SWING_VALUE_LANE02_PHYA // 0/R/x/x Reserved
#define CND003_PCIEPHYCFG_FAR_END_DEV_LOW_FREQ_VALUE_LANE02_PHYA 0xA49 // FAR-END Device Low Frequency Value Lane02 PHYA
    #define CND003_PCIEPHYCFG_RSV_PHYA_A49 PCIEPHYCFG_FAR_END_DEV_LOW_FREQ_VALUE_LANE02_PHYA // 0/R/x/x Reserved
#define CND003_PCIEPHYCFG_FAREND_TX_PRESET_02_PHYA 0xA4A // FAREND_TX_PRESET_ 02_PHYA
    #define CND003_PCIEPHYCFG_RSV_PHYA_A4A PCIEPHYCFG_FAREND_TX_PRESET_02_PHYA // 0/R/x/x Reserved
#define CND003_PCIEPHYCFG_FAREND_PRE_CURSOR_02_PHYA 0xA4B // FAREND_PRE_CURSOR_ 02_PHYA
    #define CND003_PCIEPHYCFG_RSV_PHYA_A4B PCIEPHYCFG_FAREND_PRE_CURSOR_02_PHYA // 0/R/x/x Reserved
#define CND003_PCIEPHYCFG_FAREND_CURSOR_02_PHYA 0xA4C // FAREND_CURSOR_ 02_PHYA
    #define CND003_PCIEPHYCFG_RSV_PHYA_A4C PCIEPHYCFG_FAREND_CURSOR_02_PHYA // 0/R/x/x Reserved
#define CND003_PCIEPHYCFG_FAREND_POST_CURSOR_02_PHYA 0xA4D // FAREND_POST_CURSOR_ 02_PHYA
    #define CND003_PCIEPHYCFG_RSV_PHYA_A4D PCIEPHYCFG_FAREND_POST_CURSOR_02_PHYA // 0/R/x/x Reserved
#define CND003_PCIEPHYCFG_BIT_ERR_RATE_02_PHYA 0xA4E // BIT_ERROR_RATE_ 02_PHYA
    #define CND003_PCIEPHYCFG_RSV_A4E PCIEPHYCFG_BIT_ERR_RATE_02_PHYA // 0/0/x/x Reserved
#define CND003_PCIEPHYCFG_FAREND_USE_TX_PRESET_AND_RCV_PHYA_02 0xA4F // Farend Use TX Preset and RCV PHYA 02
    #define CND003_PCIEPHYCFG_RSV_A4F PCIEPHYCFG_FAREND_USE_TX_PRESET_AND_RCV_PHYA_02 // 0/R/x/x Reserved
#define CND003_PCIEPHYCFG_LEQ_DC_GAIN_OUTPUT_EPHY_PHYA_LANE_03 0xA50 // LEQ DC Gain Output EPHY_PHYA Lane 03
    #define CND003_PCIEPHYCFG_RSV_PHYA_A50     (BIT5 + BIT6 + BIT7)    // 0/R/x/x Reserved
    #define CND003_PCIEPHYCFG_EP03_DCOUT_PHYA  0x1F                    // HwInit/x/x/x EPHY Lane3 LEQ DC Gain Output
#define CND003_PCIEPHYCFG_LEQ_HF_GAIN_OUTPUT_EPHY_PHYA_LANE_03 0xA51 // LEQ HF Gain Output EPHY_PHYA Lane 03
    #define CND003_PCIEPHYCFG_RSV_PHYA_A51     (BIT5 + BIT6 + BIT7)    // 0/R/x/x Reserved
    #define CND003_PCIEPHYCFG_EP03_HFOUT_PHYA  0x1F                    // HwInit/x/x/x EPHY Lane3 LEQ HF Gain Output
#define CND003_PCIEPHYCFG_LEQ_OFS_OUTPUT_EPHY_PHYA_LANE_03 0xA52 // LEQ Offset Output EPHY_PHYA Lane 03
    #define CND003_PCIEPHYCFG_RSV_PHYA_A52     (BIT5 + BIT6 + BIT7)    // 0/R/x/x Reserved
    #define CND003_PCIEPHYCFG_EP03_OSOUT_PHYA  0x1F                    // HwInit/x/x/x EPHY Lane3 LEQ OS Gain Output
#define CND003_PCIEPHYCFG_LEQ_WEIGHT1_OUTPUT_EPHY_PHYA_LANE_03 0xA53 // LEQ Weight1 Output EPHY_PHYA Lane 03
    #define CND003_PCIEPHYCFG_RSV_PHYA_A53     (BIT5 + BIT6 + BIT7)    // 0/R/x/x Reserved
    #define CND003_PCIEPHYCFG_EP03_W1OUT_PHYA  0x1F                    // HwInit/x/x/x EPHY Lane3 DFE Weight1 Output
#define CND003_PCIEPHYCFG_LEQ_WEIGHT2_OUTPUT_EPHY_PHYA_LANE_03 0xA54 // LEQ Weight2 Output EPHY_PHYA Lane 03
    #define CND003_PCIEPHYCFG_RSV_PHYA_A54     (BIT5 + BIT6 + BIT7)    // 0/R/x/x Reserved
    #define CND003_PCIEPHYCFG_EP03_W2OUT_PHYA  0x1F                    // HwInit/x/x/x EPHY Lane3 DFE Weight2 Output
#define CND003_PCIEPHYCFG_RESERVED_Z68 0xA55 // Reserved
    #define CND003_PCIEPHYCFG_RSV_A55 PCIEPHYCFG_RESERVED_Z68 // 0/R/x/x Reserved
#define CND003_PCIEPHYCFG_RESERVED_Z69 0xA56 // Reserved
    #define CND003_PCIEPHYCFG_RSV_A56 PCIEPHYCFG_RESERVED_Z69 // 0/R/x/x Reserved
#define CND003_PCIEPHYCFG_RESERVED_Z70 0xA57 // Reserved
    #define CND003_PCIEPHYCFG_RSV_PHYA_A57 PCIEPHYCFG_RESERVED_Z70 // 0/R/x/x Reserved
#define CND003_PCIEPHYCFG_FAR_END_DEV_FULL_SWING_VALUE_LANE03_PHYA 0xA58 // FAR-END Device Full Swing Value Lane03 PHYA
    #define CND003_PCIEPHYCFG_RSV_PHYA_A58 PCIEPHYCFG_FAR_END_DEV_FULL_SWING_VALUE_LANE03_PHYA // 0/R/x/x Reserved
#define CND003_PCIEPHYCFG_FAR_END_DEV_LOW_FREQ_VALUE_LANE03_PHYA 0xA59 // FAR-END Device Low Frequency Value Lane03 PHYA
    #define CND003_PCIEPHYCFG_RSV_PHYA_A59 PCIEPHYCFG_FAR_END_DEV_LOW_FREQ_VALUE_LANE03_PHYA // 0/R/x/x Reserved
#define CND003_PCIEPHYCFG_FAREND_TX_PRESET_03_PHYA 0xA5A // FAREND_TX_PRESET_ 03_PHYA
    #define CND003_PCIEPHYCFG_RSV_PHYA_A5A PCIEPHYCFG_FAREND_TX_PRESET_03_PHYA // 0/R/x/x Reserved
#define CND003_PCIEPHYCFG_FAREND_PRE_CURSOR_03_PHYA 0xA5B // FAREND_PRE_CURSOR_ 03_PHYA
    #define CND003_PCIEPHYCFG_RSV_PHYA_A5B PCIEPHYCFG_FAREND_PRE_CURSOR_03_PHYA // 0/R/x/x Reserved
#define CND003_PCIEPHYCFG_FAREND_CURSOR_03_PHYA 0xA5C // FAREND_CURSOR_ 03_PHYA
    #define CND003_PCIEPHYCFG_RSV_PHYA_A5C PCIEPHYCFG_FAREND_CURSOR_03_PHYA // 0/R/x/x Reserved
#define CND003_PCIEPHYCFG_FAREND_POST_CURSOR_03_PHYA 0xA5D // FAREND_POST_CURSOR_ 03_PHYA
    #define CND003_PCIEPHYCFG_RSV_PHYA_A5D PCIEPHYCFG_FAREND_POST_CURSOR_03_PHYA // 0/R/x/x Reserved
#define CND003_PCIEPHYCFG_BIT_ERR_RATE_03_PHYA 0xA5E // BIT_ERROR_RATE_ 03_PHYA
    #define CND003_PCIEPHYCFG_RSV_A5E PCIEPHYCFG_BIT_ERR_RATE_03_PHYA // 0/0/x/x Reserved
#define CND003_PCIEPHYCFG_FAREND_USE_TX_PRESET_AND_RCV_PHYA_03 0xA5F // Farend Use TX Preset and RCV PHYA 03
    #define CND003_PCIEPHYCFG_RSV_A5F PCIEPHYCFG_FAREND_USE_TX_PRESET_AND_RCV_PHYA_03 // 0/R/x/x Reserved
#define CND003_PCIEPHYCFG_LEQ_DC_OUTPUT_EPHY_PHYB_LANE_00 0xA60 // LEQ DC Output EPHY_PHYB Lane 00
    #define CND003_PCIEPHYCFG_RSV_PHYB_A60     (BIT5 + BIT6 + BIT7)    // 0/R/x/x Reserved
    #define CND003_PCIEPHYCFG_EP00_DCOUT_PHYB  0x1F                    // HwInit/x/x/x EPHY Lane0 LEQ DC Gain Output 
#define CND003_PCIEPHYCFG_LEQ_HF_OUTPUT_EPHY_PHYB_LANE_00 0xA61 // LEQ HF Output EPHY_PHYB Lane 00
    #define CND003_PCIEPHYCFG_RSV_PHYB_A61     (BIT5 + BIT6 + BIT7)    // 0/R/x/x Reserved
    #define CND003_PCIEPHYCFG_EP00_HFOUT_PHYB  0x1F                    // HwInit/x/x/x EPHY Lane0 LEQ HF Gain Output 
#define CND003_PCIEPHYCFG_LEQ_OFS_OUTPUT_EPHY_PHYB_LANE_00 0xA62 // LEQ Offset Output EPHY_PHYB Lane 00
    #define CND003_PCIEPHYCFG_RSV_PHYB_A62     (BIT5 + BIT6 + BIT7)    // 0/R/x/x Reserved
    #define CND003_PCIEPHYCFG_EP00_OSOUT_PHYB  0x1F                    // HwInit/x/x/x EPHY Lane0 LEQ OS Gain Output
#define CND003_PCIEPHYCFG_LEQ_WEIGHT1_OUTPUT_EPHY_PHYB_LANE_00 0xA63 // LEQ Weight1 Output EPHY_PHYB Lane 00
    #define CND003_PCIEPHYCFG_RSV_PHYB_A63     (BIT5 + BIT6 + BIT7)    // 0/R/x/x Reserved
    #define CND003_PCIEPHYCFG_EP00_W1OUT_PHYB  0x1F                    // HwInit/x/x/x EPHY Lane0 DFE Weight1 Output
#define CND003_PCIEPHYCFG_LEQ_WEIGHT2_OUTPUT_EPHY_PHYB_LANE_00 0xA64 // LEQ Weight2 Output EPHY_PHYB Lane 00
    #define CND003_PCIEPHYCFG_RSV_PHYB_A64     (BIT5 + BIT6 + BIT7)    // 0/R/x/x Reserved
    #define CND003_PCIEPHYCFG_EP00_W2OUT_PHYB  0x1F                    // HwInit/x/x/x EPHY Lane0 DFE weight2 output
#define CND003_PCIEPHYCFG_RESERVED_Z71 0xA65 // Reserved
    #define CND003_PCIEPHYCFG_RSV_A65 PCIEPHYCFG_RESERVED_Z71 // 0/R/x/x Reserved
#define CND003_PCIEPHYCFG_RESERVED_Z72 0xA66 // Reserved
    #define CND003_PCIEPHYCFG_RSV_A66 PCIEPHYCFG_RESERVED_Z72 // 0/R/x/x Reserved
#define CND003_PCIEPHYCFG_RESERVED_Z73 0xA67 // Reserved
    #define CND003_PCIEPHYCFG_RSV_PHYB_A67 PCIEPHYCFG_RESERVED_Z73 // 0/R/x/x Reserved
#define CND003_PCIEPHYCFG_FAR_END_DEV_FULL_SWING_VALUE_LANE00_PHYB 0xA68 // FAR-END Device Full Swing Value Lane00 PHYB
    #define CND003_PCIEPHYCFG_RSV_PHYB_A68 PCIEPHYCFG_FAR_END_DEV_FULL_SWING_VALUE_LANE00_PHYB // 0/R/x/x Reserved
#define CND003_PCIEPHYCFG_FAR_END_DEV_LOW_FREQ_VALUE_LANE00_PHYB_Z1 0xA69 // FAR-END Device Low Frequency Value Lane00 PHYB
    #define CND003_PCIEPHYCFG_RSV_PHYB_A69 PCIEPHYCFG_FAR_END_DEV_LOW_FREQ_VALUE_LANE00_PHYB_Z1 // 0/R/x/x Reserved
#define CND003_PCIEPHYCFG_FAREND_TX_PRESET_00_PHYB 0xA6A // FAREND_TX_PRESET_ 00_PHYB
    #define CND003_PCIEPHYCFG_RSV_PHYB_A6A PCIEPHYCFG_FAREND_TX_PRESET_00_PHYB // 0/R/x/x Reserved
#define CND003_PCIEPHYCFG_FAREND_PRE_CURSOR_00_PHYB 0xA6B // FAREND_PRE_CURSOR_ 00_PHYB
    #define CND003_PCIEPHYCFG_RSV_PHYB_A6B PCIEPHYCFG_FAREND_PRE_CURSOR_00_PHYB // 0/R/x/x Reserved
#define CND003_PCIEPHYCFG_FAREND_CURSOR_00_PHYB 0xA6C // FAREND_CURSOR_ 00_PHYB
    #define CND003_PCIEPHYCFG_RSV_PHYB_A6C PCIEPHYCFG_FAREND_CURSOR_00_PHYB // 0/R/x/x Reserved
#define CND003_PCIEPHYCFG_FAREND_POST_CURSOR_00_PHYB 0xA6D // FAREND_POST_CURSOR_ 00_PHYB
    #define CND003_PCIEPHYCFG_RSV_PHYB_A6D PCIEPHYCFG_FAREND_POST_CURSOR_00_PHYB // 0/R/x/x Reserved
#define CND003_PCIEPHYCFG_BIT_ERR_RATE_00_PHYB 0xA6E // BIT_ERROR_RATE_ 00_PHYB
    #define CND003_PCIEPHYCFG_RSV_A6E PCIEPHYCFG_BIT_ERR_RATE_00_PHYB // 0/0/x/x Reserved
#define CND003_PCIEPHYCFG_FAREND_USE_TX_PRESET_AND_RCV_PHYB_00 0xA6F // Farend Use TX Preset and RCV PHYB 00
    #define CND003_PCIEPHYCFG_RSV_A6F PCIEPHYCFG_FAREND_USE_TX_PRESET_AND_RCV_PHYB_00 // 0/R/x/x Reserved
#define CND003_PCIEPHYCFG_LEQ_DC_OUTPUT_EPHY_PHYB_LANE_01 0xA70 // LEQ DC Output EPHY_PHYB Lane 01
    #define CND003_PCIEPHYCFG_RSV_PHYB_A70     (BIT5 + BIT6 + BIT7)    // 0/R/x/x Reserved
    #define CND003_PCIEPHYCFG_EP01_DCOUT_PHYB  0x1F                    // HwInit/x/x/x EPHY Lane1 LEQ DC Gain Output 
#define CND003_PCIEPHYCFG_LEQ_HF_OUTPUT_EPHY_PHYB_LANE_01 0xA71 // LEQ HF Output EPHY_PHYB Lane 01
    #define CND003_PCIEPHYCFG_RSV_PHYB_A71     (BIT5 + BIT6 + BIT7)    // 0/R/x/x Reserved
    #define CND003_PCIEPHYCFG_EP01_HFOUT_PHYB  0x1F                    // HwInit/x/x/x EPHY Lane1 LEQ HF Gain Output 
#define CND003_PCIEPHYCFG_LEQ_OFS_OUTPUT_EPHY_PHYB_LANE_01 0xA72 // LEQ Offset Output EPHY_PHYB Lane 01
    #define CND003_PCIEPHYCFG_RSV_PHYB_A72     (BIT5 + BIT6 + BIT7)    // 0/R/x/x Reserved
    #define CND003_PCIEPHYCFG_EP01_OSOUT_PHYB  0x1F                    // HwInit/x/x/x EPHY Lane1 LEQ OS Gain Output 
#define CND003_PCIEPHYCFG_LEQ_WEIGHT1_OUTPUT_EPHY_PHYB_LANE_01 0xA73 // LEQ Weight1 Output EPHY_PHYB Lane 01
    #define CND003_PCIEPHYCFG_RSV_PHYB_A73     (BIT5 + BIT6 + BIT7)    // 0/R/x/x Reserved
    #define CND003_PCIEPHYCFG_EP01_W1OUT_PHYB  0x1F                    // HwInit/x/x/x EPHY Lane1 DFE Weight1 Output 
#define CND003_PCIEPHYCFG_LEQ_WEIGHT2_OUTPUT_EPHY_PHYB_LANE_01 0xA74 // LEQ Weight2 Output EPHY_PHYB Lane 01
    #define CND003_PCIEPHYCFG_RSV_PHYB_A74     (BIT5 + BIT6 + BIT7)    // 0/R/x/x Reserved
    #define CND003_PCIEPHYCFG_EP01_W2OUT_PHYB  0x1F                    // HwInit/x/x/x EPHY Lane1 DFE Weight2 Output 
#define CND003_PCIEPHYCFG_RESERVED_Z74 0xA75 // Reserved
    #define CND003_PCIEPHYCFG_RSV_A75 PCIEPHYCFG_RESERVED_Z74 // 0/R/x/x Reserved
#define CND003_PCIEPHYCFG_RESERVED_Z75 0xA76 // Reserved
    #define CND003_PCIEPHYCFG_RSV_A76 PCIEPHYCFG_RESERVED_Z75 // 0/R/x/x Reserved
#define CND003_PCIEPHYCFG_RESERVED_Z76 0xA77 // Reserved
    #define CND003_PCIEPHYCFG_RSV_PHYB_A77 PCIEPHYCFG_RESERVED_Z76 // 0/R/x/x Reserved
#define CND003_PCIEPHYCFG_FAR_END_DEV_FULL_SWING_VALUE_LANE01_PHYB 0xA78 // FAR-END Device Full Swing Value Lane01 PHYB
    #define CND003_PCIEPHYCFG_RSV_PHYB_A78 PCIEPHYCFG_FAR_END_DEV_FULL_SWING_VALUE_LANE01_PHYB // 0/R/x/x Reserved
#define CND003_PCIEPHYCFG_FAR_END_DEV_LOW_FREQ_VALUE_LANE01_PHYB 0xA79 // FAR-END Device Low Frequency Value Lane01 PHYB
    #define CND003_PCIEPHYCFG_RSV_PHYB_A79 PCIEPHYCFG_FAR_END_DEV_LOW_FREQ_VALUE_LANE01_PHYB // 0/R/x/x Reserved
#define CND003_PCIEPHYCFG_FAREND_TX_PRESET_01_PHYB 0xA7A // FAREND_TX_PRESET_ 01_PHYB
    #define CND003_PCIEPHYCFG_RSV_PHYB_A7A PCIEPHYCFG_FAREND_TX_PRESET_01_PHYB // 0/R/x/x Reserved
#define CND003_PCIEPHYCFG_FAREND_PRE_CURSOR_01_PHYB 0xA7B // FAREND_PRE_CURSOR_ 01_PHYB
    #define CND003_PCIEPHYCFG_RSV_PHYB_A7B PCIEPHYCFG_FAREND_PRE_CURSOR_01_PHYB // 0/R/x/x Reserved
#define CND003_PCIEPHYCFG_FAREND_CURSOR_01_PHYB 0xA7C // FAREND_CURSOR_ 01_PHYB
    #define CND003_PCIEPHYCFG_RSV_PHYB_A7C PCIEPHYCFG_FAREND_CURSOR_01_PHYB // 0/R/x/x Reserved
#define CND003_PCIEPHYCFG_FAREND_POST_CURSOR_01_PHYB 0xA7D // FAREND_POST_CURSOR_ 01_PHYB
    #define CND003_PCIEPHYCFG_RSV_PHYB_A7D PCIEPHYCFG_FAREND_POST_CURSOR_01_PHYB // 0/R/x/x Reserved
#define CND003_PCIEPHYCFG_BIT_ERR_RATE_01_PHYB 0xA7E // BIT_ERROR_RATE_ 01_PHYB
    #define CND003_PCIEPHYCFG_RSV_A7E PCIEPHYCFG_BIT_ERR_RATE_01_PHYB // 0/0/x/x Reserved
#define CND003_PCIEPHYCFG_FAREND_USE_TX_PRESET_AND_RCV_PHYB_01 0xA7F // Farend Use TX Preset and RCV PHYB 01
    #define CND003_PCIEPHYCFG_RSV_A7F PCIEPHYCFG_FAREND_USE_TX_PRESET_AND_RCV_PHYB_01 // 0/R/x/x Reserved
#define CND003_PCIEPHYCFG_LEQ_DC_OUTPUT_EPHY_PHYB_LANE_02 0xA80 // LEQ DC Output EPHY_PHYB Lane 02
    #define CND003_PCIEPHYCFG_RSV_PHYB_A80     (BIT5 + BIT6 + BIT7)    // 0/R/x/x Reserved
    #define CND003_PCIEPHYCFG_EP02_DCOUT_PHYB  0x1F                    // HwInit/x/x/x EPHY Lane2 LEQ DC Gain Output 
#define CND003_PCIEPHYCFG_LEQ_HF_OUTPUT_EPHY_PHYB_LANE_02 0xA81 // LEQ HF Output EPHY_PHYB Lane 02
    #define CND003_PCIEPHYCFG_RSV_PHYB_A81     (BIT5 + BIT6 + BIT7)    // 0/R/x/x Reserved
    #define CND003_PCIEPHYCFG_EP02_HFOUT_PHYB  0x1F                    // HwInit/x/x/x EPHY Lane2 LEQ HF Gain Output 
#define CND003_PCIEPHYCFG_LEQ_OFS_OUTPUT_EPHY_PHYB_LANE_02 0xA82 // LEQ Offset Output EPHY_PHYB Lane 02
    #define CND003_PCIEPHYCFG_RSV_PHYB_A82     (BIT5 + BIT6 + BIT7)    // 0/R/x/x Reserved
    #define CND003_PCIEPHYCFG_EP02_OSOUT_PHYB  0x1F                    // HwInit/x/x/x EPHY Lane2 LEQ OS Gain Output
#define CND003_PCIEPHYCFG_LEQ_WEIGHT1_OUTPUT_EPHY_PHYB_LANE_02 0xA83 // LEQ Weight1 Output EPHY_PHYB Lane 02
    #define CND003_PCIEPHYCFG_RSV_PHYB_A83     (BIT5 + BIT6 + BIT7)    // 0/R/x/x Reserved
    #define CND003_PCIEPHYCFG_EP02_W1OUT_PHYB  0x1F                    // HwInit/x/x/x EPHY Lane2 DFE Weight1 Output 
#define CND003_PCIEPHYCFG_LEQ_WEIGHT2_OUTPUT_EPHY_PHYB_LANE_02 0xA84 // LEQ Weight2 Output EPHY_PHYB Lane 02
    #define CND003_PCIEPHYCFG_RSV_PHYB_A84     (BIT5 + BIT6 + BIT7)    // 0/R/x/x Reserved
    #define CND003_PCIEPHYCFG_EP02_W2OUT_PHYB  0x1F                    // HwInit/x/x/x EPHY Lane2 DFE Weight2 Output 
#define CND003_PCIEPHYCFG_RESERVED_Z77 0xA85 // Reserved
    #define CND003_PCIEPHYCFG_RSV_A85 PCIEPHYCFG_RESERVED_Z77 // 0/R/x/x Reserved
#define CND003_PCIEPHYCFG_RESERVED_Z78 0xA86 // Reserved
    #define CND003_PCIEPHYCFG_RSV_A86 PCIEPHYCFG_RESERVED_Z78 // 0/R/x/x Reserved
#define CND003_PCIEPHYCFG_RESERVED_Z79 0xA87 // Reserved
    #define CND003_PCIEPHYCFG_RSV_PHYB_A87 PCIEPHYCFG_RESERVED_Z79 // 0/R/x/x Reserved
#define CND003_PCIEPHYCFG_FAR_END_DEV_FULL_SWING_VALUE_LANE02_PHYB 0xA88 // FAR-END Device Full Swing Value Lane02 PHYB
    #define CND003_PCIEPHYCFG_RSV_PHYB_A88 PCIEPHYCFG_FAR_END_DEV_FULL_SWING_VALUE_LANE02_PHYB // 0/R/x/x Reserved
#define CND003_PCIEPHYCFG_FAR_END_DEV_LOW_FREQ_VALUE_LANE02_PHYB 0xA89 // FAR-END Device Low Frequency Value Lane02 PHYB
    #define CND003_PCIEPHYCFG_RSV_PHYB_A89 PCIEPHYCFG_FAR_END_DEV_LOW_FREQ_VALUE_LANE02_PHYB // 0/R/x/x Reserved
#define CND003_PCIEPHYCFG_FAREND_TX_PRESET_02_PHYB 0xA8A // FAREND_TX_PRESET_ 02_PHYB
    #define CND003_PCIEPHYCFG_RSV_PHYB_A8A PCIEPHYCFG_FAREND_TX_PRESET_02_PHYB // 0/R/x/x Reserved
#define CND003_PCIEPHYCFG_FAREND_PRE_CURSOR_02_PHYB 0xA8B // FAREND_PRE_CURSOR_ 02_PHYB
    #define CND003_PCIEPHYCFG_RSV_PHYB_A8B PCIEPHYCFG_FAREND_PRE_CURSOR_02_PHYB // 0/R/x/x Reserved
#define CND003_PCIEPHYCFG_FAREND_CURSOR_02_PHYB 0xA8C // FAREND_CURSOR_ 02_PHYB
    #define CND003_PCIEPHYCFG_RSV_PHYB_A8C PCIEPHYCFG_FAREND_CURSOR_02_PHYB // 0/R/x/x Reserved
#define CND003_PCIEPHYCFG_FAREND_POST_CURSOR_02_PHYB 0xA8D // FAREND_POST_CURSOR_ 02_PHYB
    #define CND003_PCIEPHYCFG_RSV_PHYB_A8D PCIEPHYCFG_FAREND_POST_CURSOR_02_PHYB // 0/R/x/x Reserved
#define CND003_PCIEPHYCFG_BIT_ERR_RATE_02_PHYB 0xA8E // BIT_ERROR_RATE_ 02_PHYB
    #define CND003_PCIEPHYCFG_RSV_A8E PCIEPHYCFG_BIT_ERR_RATE_02_PHYB // 0/0/x/x Reserved
#define CND003_PCIEPHYCFG_FAREND_USE_TX_PRESET_AND_RCV_PHYB_02 0xA8F // Farend Use TX Preset and RCV PHYB 02
    #define CND003_PCIEPHYCFG_RSV_A8F PCIEPHYCFG_FAREND_USE_TX_PRESET_AND_RCV_PHYB_02 // 0/R/x/x Reserved
#define CND003_PCIEPHYCFG_LEQ_DC_OUTPUT_EPHY_PHYB_LANE_03 0xA90 // LEQ DC Output EPHY_PHYB Lane 03
    #define CND003_PCIEPHYCFG_RSV_PHYB_A90     (BIT5 + BIT6 + BIT7)    // 0/R/x/x Reserved
    #define CND003_PCIEPHYCFG_EP03_DCOUT_PHYB  0x1F                    // HwInit/x/x/x EPHY Lane3 LEQ DC Gain Output 
#define CND003_PCIEPHYCFG_LEQ_HF_OUTPUT_EPHY_PHYB_LANE_03 0xA91 // LEQ HF Output EPHY_PHYB Lane 03
    #define CND003_PCIEPHYCFG_RSV_PHYB_A91     (BIT5 + BIT6 + BIT7)    // 0/R/x/x Reserved
    #define CND003_PCIEPHYCFG_EP03_HFOUT_PHYB  0x1F                    // HwInit/x/x/x EPHY Lane3 LEQ HF Gain Output 
#define CND003_PCIEPHYCFG_LEQ_OFS_OUTPUT_EPHY_PHYB_LANE_03 0xA92 // LEQ Offset Output EPHY_PHYB Lane 03
    #define CND003_PCIEPHYCFG_RSV_PHYB_A92     (BIT5 + BIT6 + BIT7)    // 0/R/x/x Reserved
    #define CND003_PCIEPHYCFG_EP03_OSOUT_PHYB  0x1F                    // HwInit/x/x/x EPHY Lane3 LEQ OS Gain Output
#define CND003_PCIEPHYCFG_LEQ_WEIGHT1_OUTPUT_EPHY_PHYB_LANE_03 0xA93 // LEQ Weight1 Output EPHY_PHYB Lane 03
    #define CND003_PCIEPHYCFG_RSV_PHYB_A93     (BIT5 + BIT6 + BIT7)    // 0/R/x/x Reserved
    #define CND003_PCIEPHYCFG_EP03_W1OUT_PHYB  0x1F                    // HwInit/x/x/x EPHY Lane3 DFE Weight1 Output 
#define CND003_PCIEPHYCFG_LEQ_WEIGHT2_OUTPUT_EPHY_PHYB_LANE_03 0xA94 // LEQ Weight2 Output EPHY_PHYB Lane 03
    #define CND003_PCIEPHYCFG_RSV_PHYB_A94     (BIT5 + BIT6 + BIT7)    // 0/R/x/x Reserved
    #define CND003_PCIEPHYCFG_EP03_W2OUT_PHYB  0x1F                    // HwInit/x/x/x EPHY Lane3 DFE Weight2 Output 
#define CND003_PCIEPHYCFG_RESERVED_Z80 0xA95 // Reserved
    #define CND003_PCIEPHYCFG_RSV_A95 PCIEPHYCFG_RESERVED_Z80 // 0/R/x/x Reserved
#define CND003_PCIEPHYCFG_RESERVED_Z81 0xA96 // Reserved
    #define CND003_PCIEPHYCFG_RSV_A96 PCIEPHYCFG_RESERVED_Z81 // 0/R/x/x Reserved
#define CND003_PCIEPHYCFG_RESERVED_Z82 0xA97 // Reserved
    #define CND003_PCIEPHYCFG_RSV_PHYB_A97 PCIEPHYCFG_RESERVED_Z82 // 0/R/x/x Reserved
#define CND003_PCIEPHYCFG_FAR_END_DEV_FULL_SWING_VALUE_LANE03_PHYB 0xA98 // FAR-END Device Full Swing Value Lane03 PHYB
    #define CND003_PCIEPHYCFG_RSV_PHYB_A98 PCIEPHYCFG_FAR_END_DEV_FULL_SWING_VALUE_LANE03_PHYB // 0/R/x/x Reserved
#define CND003_PCIEPHYCFG_FAR_END_DEV_LOW_FREQ_VALUE_LANE03_PHYB 0xA99 // FAR-END Device Low Frequency Value Lane03 PHYB
    #define CND003_PCIEPHYCFG_RSV_PHYB_A99 PCIEPHYCFG_FAR_END_DEV_LOW_FREQ_VALUE_LANE03_PHYB // 0/R/x/x Reserved
#define CND003_PCIEPHYCFG_FAREND_TX_PRESET_03_PHYB 0xA9A // FAREND_TX_PRESET_ 03_PHYB
    #define CND003_PCIEPHYCFG_RSV_PHYB_A9A PCIEPHYCFG_FAREND_TX_PRESET_03_PHYB // 0/R/x/x Reserved
#define CND003_PCIEPHYCFG_FAREND_PRE_CURSOR_03_PHYB 0xA9B // FAREND_PRE_CURSOR_ 03_PHYB
    #define CND003_PCIEPHYCFG_RSV_PHYB_A9B PCIEPHYCFG_FAREND_PRE_CURSOR_03_PHYB // 0/R/x/x Reserved
#define CND003_PCIEPHYCFG_FAREND_CURSOR_03_PHYB 0xA9C // FAREND_CURSOR_ 03_PHYB
    #define CND003_PCIEPHYCFG_RSV_PHYB_A9C PCIEPHYCFG_FAREND_CURSOR_03_PHYB // 0/R/x/x Reserved
#define CND003_PCIEPHYCFG_FAREND_POST_CURSOR_03_PHYB 0xA9D // FAREND_POST_CURSOR_ 03_PHYB
    #define CND003_PCIEPHYCFG_RSV_PHYB_A9D PCIEPHYCFG_FAREND_POST_CURSOR_03_PHYB // 0/R/x/x Reserved
#define CND003_PCIEPHYCFG_BIT_ERR_RATE_03_PHYB 0xA9E // BIT_ERROR_RATE_ 03_PHYB
    #define CND003_PCIEPHYCFG_RSV_A9E PCIEPHYCFG_BIT_ERR_RATE_03_PHYB // 0/0/x/x Reserved
#define CND003_PCIEPHYCFG_FAREND_USE_TX_PRESET_AND_RCV_PHYB_03 0xA9F // Farend Use TX Preset and RCV PHYB 03
    #define CND003_PCIEPHYCFG_RSV_A9F PCIEPHYCFG_FAREND_USE_TX_PRESET_AND_RCV_PHYB_03 // 0/R/x/x Reserved
#define CND003_PCIEPHYCFG_LEQ_DC_OUTPUT_EPHY_EP_LANE_00 0xAB0 // LEQ DC Output EPHY_EP Lane 00
    #define CND003_PCIEPHYCFG_RSV_EP_AB0       (BIT5 + BIT6 + BIT7)    // 0/R/x/x Reserved
    #define CND003_PCIEPHYCFG_EP00_DCOUT_EP    0x1F                    // HwInit/x/x/x EPHY Lane0 LEQ DC Gain Output 
#define CND003_PCIEPHYCFG_LEQ_HF_OUTPUT_EPHY_EP_LANE_00 0xAB1 // LEQ HF Output EPHY_EP Lane 00
    #define CND003_PCIEPHYCFG_RSV_EP_AB1       (BIT5 + BIT6 + BIT7)    // 0/R/x/x Reserved
    #define CND003_PCIEPHYCFG_EP00_HFOUT_EP    0x1F                    // HwInit/x/x/x EPHY Lane0 LEQ HF Gain Output 
#define CND003_PCIEPHYCFG_LEQ_OFS_OUTPUT_EPHY_EP_LANE_00 0xAB2 // LEQ Offset Output EPHY_EP Lane 00
    #define CND003_PCIEPHYCFG_RSV_EP_AB2       (BIT5 + BIT6 + BIT7)    // 0/R/x/x Reserved
    #define CND003_PCIEPHYCFG_EP00_OSOUT_EP    0x1F                    // HwInit/x/x/x EPHY Lane0 LEQ OS Gain Output
#define CND003_PCIEPHYCFG_LEQ_WEIGHT1_OUTPUT_EPHY_EP_LANE_00 0xAB3 // LEQ Weight1 Output EPHY_EP Lane 00
    #define CND003_PCIEPHYCFG_RSV_EP_AB3       (BIT5 + BIT6 + BIT7)    // 0/R/x/x Reserved
    #define CND003_PCIEPHYCFG_EP00_W1OUT_EP    0x1F                    // HwInit/x/x/x EPHY Lane0 DFE Weight1 Output 
#define CND003_PCIEPHYCFG_LEQ_WEIGHT2_OUTPUT_EPHY_EP_LANE_00 0xAB4 // LEQ Weight2 Output EPHY_EP Lane 00
    #define CND003_PCIEPHYCFG_RSV_EP_AB4       (BIT5 + BIT6 + BIT7)    // 0/R/x/x Reserved
    #define CND003_PCIEPHYCFG_EP00_W2OUT_EP    0x1F                    // HwInit/x/x/x EPHY Lane0 DFE Weight2 Output 
#define CND003_PCIEPHYCFG_RESERVED_Z83 0xAB5 // Reserved
    #define CND003_PCIEPHYCFG_RSV_AB5 PCIEPHYCFG_RESERVED_Z83 // 0/R/x/x Reserved
#define CND003_PCIEPHYCFG_RESERVED_Z84 0xAB6 // Reserved
    #define CND003_PCIEPHYCFG_RSV_AB6 PCIEPHYCFG_RESERVED_Z84 // 0/R/x/x Reserved
#define CND003_PCIEPHYCFG_RESERVED_Z85 0xAB7 // Reserved
    #define CND003_PCIEPHYCFG_RSV_EP_AB7 PCIEPHYCFG_RESERVED_Z85 // 0/R/x/x Reserved
#define CND003_PCIEPHYCFG_FAR_END_DEV_FULL_SWING_VALUE_LANE00_EP 0xAB8 // FAR-END Device Full Swing Value Lane00 EP
    #define CND003_PCIEPHYCFG_RSV_EP_AB8       (BIT6 + BIT7)   // 0/R/x/x Reserved
    #define CND003_PCIEPHYCFG_FAREND_FS_00_EP  0x3F            // HwInit/x/x/x FAR-END Device Full Swing Value
#define CND003_PCIEPHYCFG_FAR_END_DEV_LOW_FREQ_VALUE_LANE00_EP 0xAB9 // FAR-END Device Low Frequency Value Lane00 EP
    #define CND003_PCIEPHYCFG_RSV_EP_AB9       (BIT6 + BIT7)   // 0/R/x/x Reserved
    #define CND003_PCIEPHYCFG_FAREND_LF_00_EP  0x3F            // HwInit/x/x/x FAR-END Device Low Frequency Value
#define CND003_PCIEPHYCFG_FAREND_TX_PRESET_00_EP 0xABA // FAREND_TX_PRESET_00_EP
    #define CND003_PCIEPHYCFG_RSV_EP_ABA                   0xF0    // 0/R/x/x Reserved
    #define CND003_PCIEPHYCFG_FAREND_TX_PRESET_00_EP_Z1    0xF     // HwInit/x/x/x Lane0 Farend TX_PRESET
#define CND003_PCIEPHYCFG_FAREND_PRE_CURSOR_00_EP 0xABB // FAREND_PRE_CURSOR_00_EP
    #define CND003_PCIEPHYCFG_RSV_EP_ABB                   (BIT6 + BIT7)   // 0/R/x/x Reserved
    #define CND003_PCIEPHYCFG_FAREND_PRE_CURSOR_00_EP_Z1   0x3F            // HwInit/x/x/x Lane0 Farend PRE_CURSOR
#define CND003_PCIEPHYCFG_FAREND_CURSOR_00_EP 0xABC // FAREND_CURSOR_00_EP
    #define CND003_PCIEPHYCFG_RSV_EP_ABC               (BIT6 + BIT7)   // 0/R/x/x Reserved
    #define CND003_PCIEPHYCFG_FAREND_CURSOR_00_EP_Z1   0x3F            // HwInit/x/x/x Lane0 Farend Cursor
#define CND003_PCIEPHYCFG_FAREND_POST_CURSOR_00_EP 0xABD // FAREND_POST_CURSOR_00_EP
    #define CND003_PCIEPHYCFG_RSV_EP_ABD                   (BIT6 + BIT7)   // 0/R/x/x Reserved
    #define CND003_PCIEPHYCFG_FAREND_POST_CURSOR_00_EP_Z1  0x3F            // HwInit/x/x/x Lane0 Farend POST_CURSOR
#define CND003_PCIEPHYCFG_BIT_ERR_RATE_00_EP 0xABE // BIT_ERROR_RATE_00_EP
    #define CND003_PCIEPHYCFG_BIT_ERROR_RATE_00_EP PCIEPHYCFG_BIT_ERR_RATE_00_EP // HwInit/x/x/x Lane0 Bit Error Rate
#define CND003_PCIEPHYCFG_FAREND_USE_TX_PRESET_AND_RCV_EP_00 0xABF // Farend Use TX Preset and RCV EP 00
    #define CND003_PCIEPHYCFG_RSV_ABF                      0xFC    // 0/R/x/x Reserved
    #define CND003_PCIEPHYCFG_FAREND_USE_TX_PRESET_00_EP   BIT1    // HwInit/x/x/x Farend Use TX Preset
    #define CND003_PCIEPHYCFG_FAREND_RCV_00_EP             BIT0    // 0/x/x/x Farend RCV 
#define CND003_PCIEPHYCFG_LEQ_DC_OUTPUT_EPHY_EP_LANE_01 0xAC0 // LEQ DC Output EPHY_EP Lane 01
    #define CND003_PCIEPHYCFG_RSV_EP_AC0       (BIT5 + BIT6 + BIT7)    // 0/R/x/x Reserved
    #define CND003_PCIEPHYCFG_EP01_DCOUT_EP    0x1F                    // HwInit/x/x/x EPHY Lane1 LEQ DC Gain Output 
#define CND003_PCIEPHYCFG_LEQ_HF_OUTPUT_EPHY_EP_LANE_01 0xAC1 // LEQ HF Output EPHY_EP Lane 01
    #define CND003_PCIEPHYCFG_RSV_EP_AC1       (BIT5 + BIT6 + BIT7)    // 0/R/x/x Reserved
    #define CND003_PCIEPHYCFG_EP01_HFOUT_EP    0x1F                    // HwInit/x/x/x EPHY Lane1 LEQ HF Gain Output 
#define CND003_PCIEPHYCFG_LEQ_OFS_OUTPUT_EPHY_EP_LANE_01 0xAC2 // LEQ Offset Output EPHY_EP Lane 01
    #define CND003_PCIEPHYCFG_RSV_EP_AC2       (BIT5 + BIT6 + BIT7)    // 0/R/x/x Reserved
    #define CND003_PCIEPHYCFG_EP01_OSOUT_EP    0x1F                    // HwInit/x/x/x EPHY Lane1 LEQ OS Gain Output 
#define CND003_PCIEPHYCFG_LEQ_WEIGHT1_OUTPUT_EPHY_EP_LANE_01 0xAC3 // LEQ Weight1 Output EPHY_EP Lane 01
    #define CND003_PCIEPHYCFG_RSV_EP_AC3       (BIT5 + BIT6 + BIT7)    // 0/R/x/x Reserved
    #define CND003_PCIEPHYCFG_EP01_W1OUT_EP    0x1F                    // HwInit/x/x/x EPHY Lane1 DFE Weight1 Output 
#define CND003_PCIEPHYCFG_LEQ_WEIGHT2_OUTPUT_EPHY_EP_LANE_01 0xAC4 // LEQ Weight2 Output EPHY_EP Lane 01
    #define CND003_PCIEPHYCFG_RSV_EP_AC4       (BIT5 + BIT6 + BIT7)    // 0/R/x/x Reserved
    #define CND003_PCIEPHYCFG_EP01_W2OUT_EP    0x1F                    // HwInit/x/x/x EPHY Lane1 DFE Weight2 Output 
#define CND003_PCIEPHYCFG_RESERVED_Z86 0xAC5 // Reserved
    #define CND003_PCIEPHYCFG_RSV_AC5 PCIEPHYCFG_RESERVED_Z86 // 0/R/x/x Reserved
#define CND003_PCIEPHYCFG_RESERVED_Z87 0xAC6 // Reserved
    #define CND003_PCIEPHYCFG_RSV_AC6 PCIEPHYCFG_RESERVED_Z87 // 0/R/x/x Reserved
#define CND003_PCIEPHYCFG_RESERVED_Z88 0xAC7 // Reserved
    #define CND003_PCIEPHYCFG_RSV_EP_AC7 PCIEPHYCFG_RESERVED_Z88 // 0/R/x/x Reserved
#define CND003_PCIEPHYCFG_FAR_END_DEV_FULL_SWING_VALUE_LANE01_EP 0xAC8 // FAR-END Device Full Swing Value Lane01 EP
    #define CND003_PCIEPHYCFG_RSV_EP_AC8       (BIT6 + BIT7)   // 0/R/x/x Reserved
    #define CND003_PCIEPHYCFG_FAREND_FS_01_EP  0x3F            // HwInit/x/x/x FAR-END Device Full Swing Value
#define CND003_PCIEPHYCFG_FAR_END_DEV_LOW_FREQ_VALUE_LANE01_EP 0xAC9 // FAR-END Device Low Frequency Value Lane01 EP
    #define CND003_PCIEPHYCFG_RSV_EP_AC9       (BIT6 + BIT7)   // 0/R/x/x Reserved
    #define CND003_PCIEPHYCFG_FAREND_LF_01_EP  0x3F            // HwInit/x/x/x FAR-END Device Low Frequency Value
#define CND003_PCIEPHYCFG_FAREND_TX_PRESET_01_EP 0xACA // FAREND_TX_PRESET_01_EP
    #define CND003_PCIEPHYCFG_RSV_EP_ACA                   0xF0    // 0/R/x/x Reserved
    #define CND003_PCIEPHYCFG_FAREND_TX_PRESET_01_EP_Z1    0xF     // HwInit/x/x/x Lane1 Farend TX_PRESET
#define CND003_PCIEPHYCFG_FAREND_PRE_CURSOR_01_EP 0xACB // FAREND_PRE_CURSOR_01_EP
    #define CND003_PCIEPHYCFG_RSV_EP_ACB                   (BIT6 + BIT7)   // 0/R/x/x Reserved
    #define CND003_PCIEPHYCFG_FAREND_PRE_CURSOR_01_EP_Z1   0x3F            // HwInit/x/x/x Lane1 Farend PRE_CURSOR
#define CND003_PCIEPHYCFG_FAREND_CURSOR_01_EP 0xACC // FAREND_CURSOR_01_EP
    #define CND003_PCIEPHYCFG_RSV_EP_ACC               (BIT6 + BIT7)   // 0/R/x/x Reserved
    #define CND003_PCIEPHYCFG_FAREND_CURSOR_01_EP_Z1   0x3F            // HwInit/x/x/x Lane1 Farend Cursor
#define CND003_PCIEPHYCFG_FAREND_POST_CURSOR_01_EP 0xACD // FAREND_POST_CURSOR_01_EP
    #define CND003_PCIEPHYCFG_RSV_EP_ACD                   (BIT6 + BIT7)   // 0/R/x/x Reserved
    #define CND003_PCIEPHYCFG_FAREND_POST_CURSOR_01_EP_Z1  0x3F            // HwInit/x/x/x Lane1 Farend POST_CURSOR
#define CND003_PCIEPHYCFG_BIT_ERR_RATE_01_EP 0xACE // BIT_ERROR_RATE_01_EP
    #define CND003_PCIEPHYCFG_BIT_ERROR_RATE_01_EP PCIEPHYCFG_BIT_ERR_RATE_01_EP // HwInit/x/x/x Lane1 Bit Error Rate
#define CND003_PCIEPHYCFG_FAREND_USE_TX_PRESET_AND_RCV_EP_01 0xACF // Farend Use TX Preset and RCV EP 01
    #define CND003_PCIEPHYCFG_RSV_ACF                      0xFC    // 0/R/x/x Reserved
    #define CND003_PCIEPHYCFG_FAREND_USE_TX_PRESET_01_EP   BIT1    // HwInit/x/x/x Farend Use TX Preset
    #define CND003_PCIEPHYCFG_FAREND_RCV_01_EP             BIT0    // 0/x/x/x Farend RCV
#define CND003_PCIEPHYCFG_LEQ_DC_OUTPUT_EPHY_EP_LANE_02 0xAD0 // LEQ DC Output EPHY_EP Lane 02
    #define CND003_PCIEPHYCFG_RSV_EP_AD0       (BIT5 + BIT6 + BIT7)    // 0/R/x/x Reserved
    #define CND003_PCIEPHYCFG_EP02_DCOUT_EP    0x1F                    // HwInit/x/x/x EPHY Lane2 LEQ DC Gain Output
#define CND003_PCIEPHYCFG_LEQ_HF_OUTPUT_EPHY_EP_LANE_02 0xAD1 // LEQ HF Output EPHY_EP Lane 02
    #define CND003_PCIEPHYCFG_RSV_EP_AD1       (BIT5 + BIT6 + BIT7)    // 0/R/x/x Reserved
    #define CND003_PCIEPHYCFG_EP02_HFOUT_EP    0x1F                    // HwInit/x/x/x EPHY Lane2 LEQ HF Gain Output 
#define CND003_PCIEPHYCFG_LEQ_OFS_OUTPUT_EPHY_EP_LANE_02 0xAD2 // LEQ Offset Output EPHY_EP Lane 02
    #define CND003_PCIEPHYCFG_RSV_EP_AD2       (BIT5 + BIT6 + BIT7)    // 0/R/x/x Reserved
    #define CND003_PCIEPHYCFG_EP02_OSOUT_EP    0x1F                    // HwInit/x/x/x EPHY Lane2 LEQ OS Gain Output
#define CND003_PCIEPHYCFG_LEQ_WEIGHT1_OUTPUT_EPHY_EP_LANE_02 0xAD3 // LEQ Weight1 Output EPHY_EP Lane 02
    #define CND003_PCIEPHYCFG_RSV_EP_AD3       (BIT5 + BIT6 + BIT7)    // 0/R/x/x Reserved
    #define CND003_PCIEPHYCFG_EP02_W1OUT_EP    0x1F                    // HwInit/x/x/x EPHY Lane2 DFE Weight1 Output 
#define CND003_PCIEPHYCFG_LEQ_WEIGHT2_OUTPUT_EPHY_EP_LANE_02 0xAD4 // LEQ Weight2 Output EPHY_EP Lane 02
    #define CND003_PCIEPHYCFG_RSV_EP_AD4       (BIT5 + BIT6 + BIT7)    // 0/R/x/x Reserved
    #define CND003_PCIEPHYCFG_EP02_W2OUT_EP    0x1F                    // HwInit/x/x/x EPHY Lane2 DFE Weight2 Output 
#define CND003_PCIEPHYCFG_RESERVED_Z89 0xAD5 // Reserved
    #define CND003_PCIEPHYCFG_RSV_AD5 PCIEPHYCFG_RESERVED_Z89 // 0/R/x/x Reserved
#define CND003_PCIEPHYCFG_RESERVED_Z90 0xAD6 // Reserved
    #define CND003_PCIEPHYCFG_RSV_AD6 PCIEPHYCFG_RESERVED_Z90 // 0/R/x/x Reserved
#define CND003_PCIEPHYCFG_RESERVED_Z91 0xAD7 // Reserved
    #define CND003_PCIEPHYCFG_RSV_EP_AD7 PCIEPHYCFG_RESERVED_Z91 // 0/R/x/x Reserved
#define CND003_PCIEPHYCFG_FAR_END_DEV_FULL_SWING_VALUE_LANE02_EP 0xAD8 // FAR-END Device Full Swing Value Lane02 EP
    #define CND003_PCIEPHYCFG_RSV_EP_AD8       (BIT6 + BIT7)   // 0/R/x/x Reserved
    #define CND003_PCIEPHYCFG_FAREND_FS_02_EP  0x3F            // HwInit/x/x/x FAR-END Device Full Swing Value
#define CND003_PCIEPHYCFG_FAR_END_DEV_LOW_FREQ_VALUE_LANE02_EP 0xAD9 // FAR-END Device Low Frequency Value Lane02 EP
    #define CND003_PCIEPHYCFG_RSV_EP_AD9       (BIT6 + BIT7)   // 0/R/x/x Reserved
    #define CND003_PCIEPHYCFG_FAREND_LF_02_EP  0x3F            // HwInit/x/x/x FAR-END Device Low Frequency Value
#define CND003_PCIEPHYCFG_FAREND_TX_PRESET_02_EP 0xADA // FAREND_TX_PRESET_02_EP
    #define CND003_PCIEPHYCFG_RSV_EP_ADA                   0xF0    // 0/R/x/x Reserved
    #define CND003_PCIEPHYCFG_FAREND_TX_PRESET_02_EP_Z1    0xF     // HwInit/x/x/x Lane2 Farend TX_PRESET
#define CND003_PCIEPHYCFG_FAREND_PRE_CURSOR_02_EP 0xADB // FAREND_PRE_CURSOR_02_EP
    #define CND003_PCIEPHYCFG_RSV_EP_ADB                   (BIT6 + BIT7)   // 0/R/x/x Reserved
    #define CND003_PCIEPHYCFG_FAREND_PRE_CURSOR_02_EP_Z1   0x3F            // HwInit/x/x/x Lane2 Farend PRE_CURSOR
#define CND003_PCIEPHYCFG_FAREND_CURSOR_02_EP 0xADC // FAREND_CURSOR_02_EP
    #define CND003_PCIEPHYCFG_RSV_EP_ADC               (BIT6 + BIT7)   // 0/R/x/x Reserved
    #define CND003_PCIEPHYCFG_FAREND_CURSOR_02_EP_Z1   0x3F            // HwInit/x/x/x Lane2 Farend Cursor
#define CND003_PCIEPHYCFG_FAREND_POST_CURSOR_02_EP 0xADD // FAREND_POST_CURSOR_02_EP
    #define CND003_PCIEPHYCFG_RSV_EP_ADD                   (BIT6 + BIT7)   // 0/R/x/x Reserved
    #define CND003_PCIEPHYCFG_FAREND_POST_CURSOR_02_EP_Z1  0x3F            // HwInit/x/x/x Lane2 Farend POST_CURSOR
#define CND003_PCIEPHYCFG_BIT_ERR_RATE_02_EP 0xADE // BIT_ERROR_RATE_02_EP
    #define CND003_PCIEPHYCFG_BIT_ERROR_RATE_02_EP PCIEPHYCFG_BIT_ERR_RATE_02_EP // HwInit/x/x/x Lane2 Bit Error Rate
#define CND003_PCIEPHYCFG_FAREND_USE_TX_PRESET_AND_RCV_EP_02 0xADF // Farend Use TX Preset and RCV EP 02
    #define CND003_PCIEPHYCFG_RSV_ADF                      0xFC    // 0/R/x/x Reserved
    #define CND003_PCIEPHYCFG_FAREND_USE_TX_PRESET_02_EP   BIT1    // HwInit/x/x/x Farend Use TX Preset
    #define CND003_PCIEPHYCFG_FAREND_RCV_02_EP             BIT0    // 0/x/x/x Farend RCV 
#define CND003_PCIEPHYCFG_LEQ_DC_OUTPUT_EPHY_EP_LANE_03 0xAE0 // LEQ DC Output EPHY_EP Lane 03
    #define CND003_PCIEPHYCFG_RSV_EP_AE0       (BIT5 + BIT6 + BIT7)    // 0/R/x/x Reserved
    #define CND003_PCIEPHYCFG_EP03_DCOUT_EP    0x1F                    // HwInit/x/x/x EPHY Lane3 LEQ DC Gain Output 
#define CND003_PCIEPHYCFG_LEQ_HF_OUTPUT_EPHY_EP_LANE_03 0xAE1 // LEQ HF Output EPHY_EP Lane 03
    #define CND003_PCIEPHYCFG_RSV_EP_AE1       (BIT5 + BIT6 + BIT7)    // 0/R/x/x Reserved
    #define CND003_PCIEPHYCFG_EP03_HFOUT_EP    0x1F                    // HwInit/x/x/x EPHY Lane3 LEQ HF Gain Output 
#define CND003_PCIEPHYCFG_LEQ_OFS_OUTPUT_EPHY_EP_LANE_03 0xAE2 // LEQ Offset Output EPHY_EP Lane 03
    #define CND003_PCIEPHYCFG_RSV_EP_AE2       (BIT5 + BIT6 + BIT7)    // 0/R/x/x Reserved
    #define CND003_PCIEPHYCFG_EP03_OSOUT_EP    0x1F                    // HwInit/x/x/x EPHY Lane3 LEQ OS Gain Output
#define CND003_PCIEPHYCFG_LEQ_WEIGHT1_OUTPUT_EPHY_EP_LANE_03 0xAE3 // LEQ Weight1 Output EPHY_EP Lane 03
    #define CND003_PCIEPHYCFG_RSV_EP_AE3       (BIT5 + BIT6 + BIT7)    // 0/R/x/x Reserved
    #define CND003_PCIEPHYCFG_EP03_W1OUT_EP    0x1F                    // HwInit/x/x/x EPHY Lane3 DFE Weight1 Output 
#define CND003_PCIEPHYCFG_LEQ_WEIGHT2_OUTPUT_EPHY_EP_LANE_03 0xAE4 // LEQ Weight2 Output EPHY_EP Lane 03
    #define CND003_PCIEPHYCFG_RSV_EP_AE4       (BIT5 + BIT6 + BIT7)    // 0/R/x/x Reserved
    #define CND003_PCIEPHYCFG_EP03_W2OUT_EP    0x1F                    // HwInit/x/x/x EPHY Lane3 DFE Weight2 Output 
#define CND003_PCIEPHYCFG_RESERVED_Z92 0xAE5 // Reserved
    #define CND003_PCIEPHYCFG_RSV_AE5 PCIEPHYCFG_RESERVED_Z92 // 0/R/x/x Reserved
#define CND003_PCIEPHYCFG_RESERVED_Z93 0xAE6 // Reserved
    #define CND003_PCIEPHYCFG_RSV_AE6 PCIEPHYCFG_RESERVED_Z93 // 0/R/x/x Reserved
#define CND003_PCIEPHYCFG_RESERVED_Z94 0xAE7 // Reserved
    #define CND003_PCIEPHYCFG_RSV_EP_AE7 PCIEPHYCFG_RESERVED_Z94 // 0/R/x/x Reserved
#define CND003_PCIEPHYCFG_FAR_END_DEV_FULL_SWING_VALUE_LANE03_EP 0xAE8 // FAR-END Device Full Swing Value Lane03 EP
    #define CND003_PCIEPHYCFG_RSV_EP_AE8       (BIT6 + BIT7)   // 0/R/x/x Reserved
    #define CND003_PCIEPHYCFG_FAREND_FS_03_EP  0x3F            // HwInit/x/x/x FAR-END Device Full Swing Value
#define CND003_PCIEPHYCFG_FAR_END_DEV_LOW_FREQ_VALUE_LANE03_EP 0xAE9 // FAR-END Device Low Frequency Value Lane03 EP
    #define CND003_PCIEPHYCFG_RSV_EP_AE9       (BIT6 + BIT7)   // 0/R/x/x Reserved
    #define CND003_PCIEPHYCFG_FAREND_LF_03_EP  0x3F            // HwInit/x/x/x FAR-END Device Low Frequency Value
#define CND003_PCIEPHYCFG_FAREND_TX_PRESET_03_EP 0xAEA // FAREND_TX_PRESET_03_EP
    #define CND003_PCIEPHYCFG_RSV_EP_AEA                   0xF0    // 0/R/x/x Reserved
    #define CND003_PCIEPHYCFG_FAREND_TX_PRESET_03_EP_Z1    0xF     // HwInit/x/x/x Lane3 Farend TX_PRESET
#define CND003_PCIEPHYCFG_FAREND_PRE_CURSOR_03_EP 0xAEB // FAREND_PRE_CURSOR_03_EP
    #define CND003_PCIEPHYCFG_RSV_EP_AEB                   (BIT6 + BIT7)   // 0/R/x/x Reserved
    #define CND003_PCIEPHYCFG_FAREND_PRE_CURSOR_03_EP_Z1   0x3F            // HwInit/x/x/x Lane3 Farend PRE_CURSOR
#define CND003_PCIEPHYCFG_FAREND_CURSOR_03_EP 0xAEC // FAREND_CURSOR_03_EP
    #define CND003_PCIEPHYCFG_RSV_EP_AEC               (BIT6 + BIT7)   // 0/R/x/x Reserved
    #define CND003_PCIEPHYCFG_FAREND_CURSOR_03_EP_Z1   0x3F            // HwInit/x/x/x Lane3 Farend Cursor
#define CND003_PCIEPHYCFG_FAREND_POST_CURSOR_03_EP 0xAED // FAREND_POST_CURSOR_03_EP
    #define CND003_PCIEPHYCFG_RSV_EP_AED                   (BIT6 + BIT7)   // 0/R/x/x Reserved
    #define CND003_PCIEPHYCFG_FAREND_POST_CURSOR_03_EP_Z1  0x3F            // HwInit/x/x/x Lane3 Farend POST_CURSOR
#define CND003_PCIEPHYCFG_BIT_ERR_RATE_03_EP 0xAEE // BIT_ERROR_RATE_03_EP
    #define CND003_PCIEPHYCFG_BIT_ERROR_RATE_03_EP PCIEPHYCFG_BIT_ERR_RATE_03_EP // HwInit/x/x/x Lane3 Bit Error Rate
#define CND003_PCIEPHYCFG_FAREND_USE_TX_PRESET_AND_RCV_EP_03 0xAEF // Farend Use TX Preset and RCV EP 03
    #define CND003_PCIEPHYCFG_RSV_AEF                      0xFC    // 0/R/x/x Reserved
    #define CND003_PCIEPHYCFG_FAREND_USE_TX_PRESET_03_EP   BIT1    // HwInit/x/x/x Farend Use TX Preset
    #define CND003_PCIEPHYCFG_FAREND_RCV_03_EP             BIT0    // 0/x/x/x Farend RCV 
#define CND003_PCIEPHYCFG_MCU_SET_PRESET_LANE_0 0xB30 // MCU Set Preset Lane 0
    #define CND003_PCIEPHYCFG_RSV_B30 PCIEPHYCFG_MCU_SET_PRESET_LANE_0 // 0/x/x/x Reserved
#define CND003_PCIEPHYCFG_MCU_SET_PRE_CURSOR_LANE_0 0xB31 // MCU Set Pre-cursor Lane 0
    #define CND003_PCIEPHYCFG_RSV_B31 PCIEPHYCFG_MCU_SET_PRE_CURSOR_LANE_0 // 0/x/x/x Reserved
#define CND003_PCIEPHYCFG_MCU_SET_CURSOR_LANE_0 0xB32 // MCU Set Cursor Lane 0
    #define CND003_PCIEPHYCFG_RSV_B32 PCIEPHYCFG_MCU_SET_CURSOR_LANE_0 // 0/x/x/x Reserved
#define CND003_PCIEPHYCFG_MCU_SET_POST_CURSOR_LANE_0 0xB33 // MCU Set Post-cursor Lane 0
    #define CND003_PCIEPHYCFG_RSV_B33 PCIEPHYCFG_MCU_SET_POST_CURSOR_LANE_0 // 0/x/x/x Reserved
#define CND003_PCIEPHYCFG_MCU_SET_PRESET_LANE_04_PHYA 0xB40 // MCU Set Preset Lane 04 PHYA
    #define CND003_PCIEPHYCFG_RSV_B40                  (BIT5 + BIT6 + BIT7)    // 0/x/x/x Reserved
    #define CND003_PCIEPHYCFG_MCU_USE_PRESET_04_PHYA   BIT4                    // 0/x/x/x Use Cursor Setting or PRESET Setting
    #define CND003_PCIEPHYCFG_MCU_TX_PRESET_04_PHYA    0xF                     // 0/x/x/x TX_PRESET Value when Doing EQ
#define CND003_PCIEPHYCFG_MCU_SET_PRE_CURSOR_LANE_04_PHYA 0xB41 // MCU Set Pre-cursor Lane 04 PHYA
    #define CND003_PCIEPHYCFG_RSV_B41                  (BIT6 + BIT7)   // 0/x/x/x Reserved
    #define CND003_PCIEPHYCFG_MCU_PRE_CURSOR_04_PHYA   0x3F            // 0/x/x/x Lane 04
#define CND003_PCIEPHYCFG_MCU_SET_CURSOR_LANE_04_PHYA 0xB42 // MCU Set Cursor Lane 04 PHYA
    #define CND003_PCIEPHYCFG_RSV_B42              (BIT6 + BIT7)   // 0/x/x/x Reserved
    #define CND003_PCIEPHYCFG_MCU_CURSOR_04_PHYA   0x3F            // 0/x/x/x Lane 04
#define CND003_PCIEPHYCFG_MCU_SET_POST_CURSOR_LANE_04_PHYA 0xB43 // MCU Set Post-cursor Lane 04 PHYA
    #define CND003_PCIEPHYCFG_RSV_B43                  (BIT6 + BIT7)   // 0/x/x/x Reserved
    #define CND003_PCIEPHYCFG_MCU_POST_CURSOR_04_PHYA  0x3F            // 0/x/x/x Lane 04
#define CND003_PCIEPHYCFG_MCU_SET_PRESET_LANE_0_PHYA 0xB50 // MCU Set Preset Lane 0 PHYA
    #define CND003_PCIEPHYCFG_RSV_B50                  (BIT5 + BIT6 + BIT7)    // 0/x/x/x Reserved
    #define CND003_PCIEPHYCFG_MCU_USE_PRESET_00_PHYA   BIT4                    // 0/x/x/x Use Cursor Setting or PRESET Setting
    #define CND003_PCIEPHYCFG_MCU_TX_PRESET_00_PHYA    0xF                     // 0/x/x/x TX_PRESET Value when Doing EQ
#define CND003_PCIEPHYCFG_MCU_SET_PRE_CURSOR_LANE_0_PHYA 0xB51 // MCU Set Pre-cursor Lane 0 PHYA
    #define CND003_PCIEPHYCFG_RSV_B51                  (BIT6 + BIT7)   // 0/x/x/x Reserved
    #define CND003_PCIEPHYCFG_MCU_PRE_CURSOR_00_PHYA   0x3F            // 0/x/x/x Lane 0 
#define CND003_PCIEPHYCFG_MCU_SET_CURSOR_LANE_0_PHYA 0xB52 // MCU Set Cursor Lane 0 PHYA
    #define CND003_PCIEPHYCFG_RSV_B52              (BIT6 + BIT7)   // 0/x/x/x Reserved
    #define CND003_PCIEPHYCFG_MCU_CURSOR_00_PHYA   0x3F            // 0/x/x/x Lane 0 
#define CND003_PCIEPHYCFG_MCU_SET_POST_CURSOR_LANE_0_PHYA 0xB53 // MCU Set Post-cursor Lane 0 PHYA
    #define CND003_PCIEPHYCFG_RSV_B53                  (BIT6 + BIT7)   // 0/x/x/x Reserved
    #define CND003_PCIEPHYCFG_MCU_POST_CURSOR_00_PHYA  0x3F            // 0/x/x/x Lane 0
#define CND003_PCIEPHYCFG_MCU_SET_PRESET_LANE_1_PHYA 0xB60 // MCU Set Preset Lane 1 PHYA
    #define CND003_PCIEPHYCFG_RSV_B60                  (BIT5 + BIT6 + BIT7)    // 0/x/x/x Reserved
    #define CND003_PCIEPHYCFG_MCU_USE_PRESET_01_PHYA   BIT4                    // 0/x/x/x Use Cursor Setting or PRESET Setting
    #define CND003_PCIEPHYCFG_MCU_TX_PRESET_01_PHYA    0xF                     // 0/x/x/x TX_PRESET Value when Doing EQ
#define CND003_PCIEPHYCFG_MCU_SET_PRE_CURSOR_LANE_1_PHYA 0xB61 // MCU Set Pre-cursor Lane 1 PHYA
    #define CND003_PCIEPHYCFG_RSV_B61                  (BIT6 + BIT7)   // 0/x/x/x Reserved
    #define CND003_PCIEPHYCFG_MCU_PRE_CURSOR_01_PHYA   0x3F            // 0/x/x/x Lane 1
#define CND003_PCIEPHYCFG_MCU_SET_CURSOR_LANE_1_PHYA 0xB62 // MCU Set Cursor Lane 1 PHYA
    #define CND003_PCIEPHYCFG_RSV_B62              (BIT6 + BIT7)   // 0/x/x/x Reserved
    #define CND003_PCIEPHYCFG_MCU_CURSOR_01_PHYA   0x3F            // 0/x/x/x Lane 1 
#define CND003_PCIEPHYCFG_MCU_SET_POST_CURSOR_LANE_1_PHYA 0xB63 // MCU Set Post-cursor Lane 1 PHYA
    #define CND003_PCIEPHYCFG_RSV_B63                  (BIT6 + BIT7)   // 0/x/x/x Reserved
    #define CND003_PCIEPHYCFG_MCU_POST_CURSOR_01_PHYA  0x3F            // 0/x/x/x Lane 1
#define CND003_PCIEPHYCFG_MCU_SET_PRESET_LANE_2_PHYA 0xB70 // MCU Set Preset Lane 2 PHYA
    #define CND003_PCIEPHYCFG_RSV_B70                  (BIT5 + BIT6 + BIT7)    // 0/x/x/x Reserved
    #define CND003_PCIEPHYCFG_MCU_USE_PRESET_02_PHYA   BIT4                    // 0/x/x/x Use Cursor Setting or PRESET Setting
    #define CND003_PCIEPHYCFG_MCU_TX_PRESET_02_PHYA    0xF                     // 0/x/x/x TX_PRESET Value when Doing EQ
#define CND003_PCIEPHYCFG_MCU_SET_PRE_CURSOR_LANE_2_PHYA 0xB71 // MCU Set Pre-cursor Lane 2 PHYA
    #define CND003_PCIEPHYCFG_RSV_B71                  (BIT6 + BIT7)   // 0/x/x/x Reserved
    #define CND003_PCIEPHYCFG_MCU_PRE_CURSOR_02_PHYA   0x3F            // 0/x/x/x Lane 2
#define CND003_PCIEPHYCFG_MCU_SET_CURSOR_LANE_2_PHYA 0xB72 // MCU Set Cursor Lane 2 PHYA
    #define CND003_PCIEPHYCFG_RSV_B72              (BIT6 + BIT7)   // 0/x/x/x Reserved
    #define CND003_PCIEPHYCFG_MCU_CURSOR_02_PHYA   0x3F            // 0/x/x/x Lane 2 
#define CND003_PCIEPHYCFG_MCU_SET_POST_CURSOR_LANE_2_PHYA 0xB73 // MCU Set Post-cursor Lane 2 PHYA
    #define CND003_PCIEPHYCFG_RSV_B73                  (BIT6 + BIT7)   // 0/x/x/x Reserved
    #define CND003_PCIEPHYCFG_MCU_POST_CURSOR_02_PHYA  0x3F            // 0/x/x/x Lane 2
#define CND003_PCIEPHYCFG_MCU_SET_PRESET_LANE_3_PHYA 0xB80 // MCU Set Preset Lane 3 PHYA
    #define CND003_PCIEPHYCFG_RSV_B80                  (BIT5 + BIT6 + BIT7)    // 0/x/x/x Reserved
    #define CND003_PCIEPHYCFG_MCU_USE_PRESET_03_PHYA   BIT4                    // 0/x/x/x Use Cursor Setting or PRESET Setting
    #define CND003_PCIEPHYCFG_MCU_TX_PRESET_03_PHYA    0xF                     // 0/x/x/x TX_PRESET Value when Doing EQ
#define CND003_PCIEPHYCFG_MCU_SET_PRE_CURSOR_LANE_3_PHYA 0xB81 // MCU Set Pre-cursor Lane 3 PHYA
    #define CND003_PCIEPHYCFG_RSV_B81                  (BIT6 + BIT7)   // 0/x/x/x Reserved
    #define CND003_PCIEPHYCFG_MCU_PRE_CURSOR_03_PHYA   0x3F            // 0/x/x/x Lane 3
#define CND003_PCIEPHYCFG_MCU_SET_CURSOR_LANE_3_PHYA 0xB82 // MCU Set Cursor Lane 3 PHYA
    #define CND003_PCIEPHYCFG_RSV_B82              (BIT6 + BIT7)   // 0/x/x/x Reserved
    #define CND003_PCIEPHYCFG_MCU_CURSOR_03_PHYA   0x3F            // 0/x/x/x Lane 3
#define CND003_PCIEPHYCFG_MCU_SET_POST_CURSOR_LANE_3_PHYA 0xB83 // MCU Set Post-cursor Lane 3 PHYA
    #define CND003_PCIEPHYCFG_RSV_B83                  (BIT6 + BIT7)   // 0/x/x/x Reserved
    #define CND003_PCIEPHYCFG_MCU_POST_CURSOR_03_PHYA  0x3F            // 0/x/x/x Lane 3
#define CND003_PCIEPHYCFG_MCU_SET_PRESET_LANE_0_PHYB 0xB90 // MCU Set Preset Lane 0 PHYB
    #define CND003_PCIEPHYCFG_RSV_B90                  (BIT5 + BIT6 + BIT7)    // 0/x/x/x Reserved
    #define CND003_PCIEPHYCFG_MCU_USE_PRESET_00_PHYB   BIT4                    // 0/x/x/x Use Cursor Setting or PRESET Setting
    #define CND003_PCIEPHYCFG_MCU_TX_PRESET_00_PHYB    0xF                     // 0/x/x/x TX_PRESET Value when Doing EQ
#define CND003_PCIEPHYCFG_MCU_SET_PRE_CURSOR_LANE_0_PHYB 0xB91 // MCU Set Pre-cursor Lane 0 PHYB
    #define CND003_PCIEPHYCFG_RSV_B91                  (BIT6 + BIT7)   // 0/x/x/x Reserved
    #define CND003_PCIEPHYCFG_MCU_PRE_CURSOR_00_PHYB   0x3F            // 0/x/x/x Lane 0
#define CND003_PCIEPHYCFG_MCU_SET_CURSOR_LANE_0_PHYB 0xB92 // MCU Set Cursor Lane 0 PHYB
    #define CND003_PCIEPHYCFG_RSV_B92              (BIT6 + BIT7)   // 0/x/x/x Reserved
    #define CND003_PCIEPHYCFG_MCU_CURSOR_00_PHYB   0x3F            // 0/x/x/x Lane 0
#define CND003_PCIEPHYCFG_MCU_SET_POST_CURSOR_LANE_0_PHYB 0xB93 // MCU Set Post-cursor Lane 0 PHYB
    #define CND003_PCIEPHYCFG_RSV_B93                  (BIT6 + BIT7)   // 0/x/x/x Reserved
    #define CND003_PCIEPHYCFG_MCU_POST_CURSOR_00_PHYB  0x3F            // 0/x/x/x Lane 0
#define CND003_PCIEPHYCFG_MCU_SET_PRESET_LANE_1_PHYB 0xBA0 // MCU Set Preset Lane 1 PHYB
    #define CND003_PCIEPHYCFG_RSV_BA0                  (BIT5 + BIT6 + BIT7)    // 0/x/x/x Reserved
    #define CND003_PCIEPHYCFG_MCU_USE_PRESET_01_PHYB   BIT4                    // 0/x/x/x Use Cursor Setting or PRESET Setting
    #define CND003_PCIEPHYCFG_MCU_TX_PRESET_01_PHYB    0xF                     // 0/x/x/x TX_PRESET Value when Doing EQ
#define CND003_PCIEPHYCFG_MCU_SET_PRE_CURSOR_LANE_1_PHYB 0xBA1 // MCU Set Pre-cursor Lane 1 PHYB
    #define CND003_PCIEPHYCFG_RSV_BA1                  (BIT6 + BIT7)   // 0/x/x/x Reserved
    #define CND003_PCIEPHYCFG_MCU_PRE_CURSOR_01_PHYB   0x3F            // 0/x/x/x Lane 1
#define CND003_PCIEPHYCFG_MCU_SET_CURSOR_LANE_1_PHYB 0xBA2 // MCU Set Cursor Lane 1 PHYB
    #define CND003_PCIEPHYCFG_RSV_BA2              (BIT6 + BIT7)   // 0/x/x/x Reserved
    #define CND003_PCIEPHYCFG_MCU_CURSOR_01_PHYB   0x3F            // 0/x/x/x Lane 1
#define CND003_PCIEPHYCFG_MCU_SET_POST_CURSOR_LANE_1_PHYB 0xBA3 // MCU Set Post-cursor Lane 1 PHYB
    #define CND003_PCIEPHYCFG_RSV_BA3                  (BIT6 + BIT7)   // 0/x/x/x Reserved
    #define CND003_PCIEPHYCFG_MCU_POST_CURSOR_01_PHYB  0x3F            // 0/x/x/x Lane 1
#define CND003_PCIEPHYCFG_MCU_SET_PRESET_LANE_2_PHYB 0xBB0 // MCU Set Preset Lane 2 PHYB
    #define CND003_PCIEPHYCFG_RSV_BB0                  (BIT5 + BIT6 + BIT7)    // 0/x/x/x Reserved
    #define CND003_PCIEPHYCFG_MCU_USE_PRESET_02_PHYB   BIT4                    // 0/x/x/x Use Cursor Setting or PRESET Setting
    #define CND003_PCIEPHYCFG_MCU_TX_PRESET_02_PHYB    0xF                     // 0/x/x/x TX_PRESET Value when Doing EQ
#define CND003_PCIEPHYCFG_MCU_SET_PRE_CURSOR_LANE_2_PHYB 0xBB1 // MCU Set Pre-cursor Lane 2 PHYB
    #define CND003_PCIEPHYCFG_RSV_BB1                  (BIT6 + BIT7)   // 0/x/x/x Reserved
    #define CND003_PCIEPHYCFG_MCU_PRE_CURSOR_02_PHYB   0x3F            // 0/x/x/x Lane 2
#define CND003_PCIEPHYCFG_MCU_SET_CURSOR_LANE_2_PHYB 0xBB2 // MCU Set Cursor Lane 2 PHYB
    #define CND003_PCIEPHYCFG_RSV_BB2              (BIT6 + BIT7)   // 0/x/x/x Reserved
    #define CND003_PCIEPHYCFG_MCU_CURSOR_02_PHYB   0x3F            // 0/x/x/x Lane 2
#define CND003_PCIEPHYCFG_MCU_SET_POST_CURSOR_LANE_2_PHYB 0xBB3 // MCU Set Post-cursor Lane 2 PHYB
    #define CND003_PCIEPHYCFG_RSV_BB3                  (BIT6 + BIT7)   // 0/x/x/x Reserved
    #define CND003_PCIEPHYCFG_MCU_POST_CURSOR_02_PHYB  0x3F            // 0/x/x/x Lane 2
#define CND003_PCIEPHYCFG_MCU_SET_PRESET_LANE_3_PHYB 0xBC0 // MCU Set Preset Lane 3 PHYB
    #define CND003_PCIEPHYCFG_RSV_BC0                  (BIT5 + BIT6 + BIT7)    // 0/x/x/x Reserved
    #define CND003_PCIEPHYCFG_MCU_USE_PRESET_03_PHYB   BIT4                    // 0/x/x/x Use Cursor Setting or PRESET Setting
    #define CND003_PCIEPHYCFG_MCU_TX_PRESET_03_PHYB    0xF                     // 0/x/x/x TX_PRESET Value when Doing EQ
#define CND003_PCIEPHYCFG_MCU_SET_PRE_CURSOR_LANE_3_PHYB 0xBC1 // MCU Set Pre-cursor Lane 3 PHYB
    #define CND003_PCIEPHYCFG_RSV_BC1                  (BIT6 + BIT7)   // 0/x/x/x Reserved
    #define CND003_PCIEPHYCFG_MCU_PRE_CURSOR_03_PHYB   0x3F            // 0/x/x/x Lane 3
#define CND003_PCIEPHYCFG_MCU_SET_CURSOR_LANE_3_PHYB 0xBC2 // MCU Set Cursor Lane 3 PHYB
    #define CND003_PCIEPHYCFG_RSV_BC2              (BIT6 + BIT7)   // 0/x/x/x Reserved
    #define CND003_PCIEPHYCFG_MCU_CURSOR_03_PHYB   0x3F            // 0/x/x/x Lane 3
#define CND003_PCIEPHYCFG_MCU_SET_POST_CURSOR_LANE_3_PHYB 0xBC3 // MCU Set Post-cursor Lane 3 PHYB
    #define CND003_PCIEPHYCFG_RSV_BC3                  (BIT6 + BIT7)   // 0/x/x/x Reserved
    #define CND003_PCIEPHYCFG_MCU_POST_CURSOR_03_PHYB  0x3F            // 0/x/x/x Lane 3
#define CND003_PCIEPHYCFG_MCU_SET_PRESET_LANE_0_EP 0xBE0 // MCU Set Preset Lane 0 EP
    #define CND003_PCIEPHYCFG_RSV_BE0              (BIT5 + BIT6 + BIT7)    // 0/x/x/x Reserved
    #define CND003_PCIEPHYCFG_MCU_USE_PRESET_00_EP BIT4                    // 0/x/x/x Use Cursor Setting or PRESET Setting
    #define CND003_PCIEPHYCFG_MCU_TX_PRESET_00_EP  0xF                     // 0/x/x/x TX_PRESET Value when Doing EQ
#define CND003_PCIEPHYCFG_MCU_SET_PRE_CURSOR_LANE_0_EP 0xBE1 // MCU Set Pre-cursor Lane 0 EP
    #define CND003_PCIEPHYCFG_RSV_BE1              (BIT6 + BIT7)   // 0/x/x/x Reserved
    #define CND003_PCIEPHYCFG_MCU_PRE_CURSOR_00_EP 0x3F            // 0/x/x/x Lane 0
#define CND003_PCIEPHYCFG_MCU_SET_CURSOR_LANE_0_EP 0xBE2 // MCU Set Cursor Lane 0 EP
    #define CND003_PCIEPHYCFG_RSV_BE2          (BIT6 + BIT7)   // 0/x/x/x Reserved
    #define CND003_PCIEPHYCFG_MCU_CURSOR_00_EP 0x3F            // 0/x/x/x Lane 0
#define CND003_PCIEPHYCFG_MCU_SET_POST_CURSOR_LANE_0_EP 0xBE3 // MCU Set Post-cursor Lane 0 EP
    #define CND003_PCIEPHYCFG_RSV_BE3                  (BIT6 + BIT7)   // 0/x/x/x Reserved
    #define CND003_PCIEPHYCFG_MCU_POST_CURSOR_00_EP    0x3F            // 0/x/x/x Lane 0 
#define CND003_PCIEPHYCFG_MCU_SET_PRESET_LANE_1_EP 0xBF0 // MCU Set Preset Lane 1 EP
    #define CND003_PCIEPHYCFG_RSV_BF0              (BIT5 + BIT6 + BIT7)    // 0/x/x/x Reserved
    #define CND003_PCIEPHYCFG_MCU_USE_PRESET_01_EP BIT4                    // 0/x/x/x Use Cursor Setting or PRESET Setting
    #define CND003_PCIEPHYCFG_MCU_TX_PRESET_01_EP  0xF                     // 0/x/x/x TX_PRESET Value when Doing EQ
#define CND003_PCIEPHYCFG_MCU_SET_PRE_CURSOR_LANE_1_EP 0xBF1 // MCU Set Pre-cursor Lane 1 EP
    #define CND003_PCIEPHYCFG_RSV_BF1              (BIT6 + BIT7)   // 0/x/x/x Reserved
    #define CND003_PCIEPHYCFG_MCU_PRE_CURSOR_01_EP 0x3F            // 0/x/x/x Lane 1
#define CND003_PCIEPHYCFG_MCU_SET_CURSOR_LANE_1_EP 0xBF2 // MCU Set Cursor Lane 1 EP
    #define CND003_PCIEPHYCFG_RSV_BF2          (BIT6 + BIT7)   // 0/x/x/x Reserved
    #define CND003_PCIEPHYCFG_MCU_CURSOR_01_EP 0x3F            // 0/x/x/x Lane 1
#define CND003_PCIEPHYCFG_MCU_SET_POST_CURSOR_LANE_1_EP 0xBF3 // MCU Set Post-cursor Lane 1 EP
    #define CND003_PCIEPHYCFG_RSV_BF3                  (BIT6 + BIT7)   // 0/x/x/x Reserved
    #define CND003_PCIEPHYCFG_MCU_POST_CURSOR_01_EP    0x3F            // 0/x/x/x Lane 1
#define CND003_PCIEPHYCFG_MCU_SET_PRESET_LANE_2_EP 0xC00 // MCU Set Preset Lane 2 EP
    #define CND003_PCIEPHYCFG_RSV_C00              (BIT5 + BIT6 + BIT7)    // 0/x/x/x Reserved
    #define CND003_PCIEPHYCFG_MCU_USE_PRESET_02_EP BIT4                    // 0/x/x/x Use Cursor Setting or PRESET Setting
    #define CND003_PCIEPHYCFG_MCU_TX_PRESET_02_EP  0xF                     // 0/x/x/x TX_PRESET Value when Doing EQ
#define CND003_PCIEPHYCFG_MCU_SET_PRE_CURSOR_LANE_2_EP 0xC01 // MCU Set Pre-cursor Lane 2 EP
    #define CND003_PCIEPHYCFG_RSV_C01              (BIT6 + BIT7)   // 0/x/x/x Reserved
    #define CND003_PCIEPHYCFG_MCU_PRE_CURSOR_02_EP 0x3F            // 0/x/x/x Lane 2
#define CND003_PCIEPHYCFG_MCU_SET_CURSOR_LANE_2_EP 0xC02 // MCU Set Cursor Lane 2 EP
    #define CND003_PCIEPHYCFG_RSV_C02          (BIT6 + BIT7)   // 0/x/x/x Reserved
    #define CND003_PCIEPHYCFG_MCU_CURSOR_02_EP 0x3F            // 0/x/x/x Lane 2
#define CND003_PCIEPHYCFG_MCU_SET_POST_CURSOR_LANE_2_EP 0xC03 // MCU Set Post-cursor Lane 2 EP
    #define CND003_PCIEPHYCFG_RSV_C03                  (BIT6 + BIT7)   // 0/x/x/x Reserved
    #define CND003_PCIEPHYCFG_MCU_POST_CURSOR_02_EP    0x3F            // 0/x/x/x Lane 2
#define CND003_PCIEPHYCFG_MCU_SET_PRESET_LANE_3_EP 0xC10 // MCU Set Preset Lane 3 EP
    #define CND003_PCIEPHYCFG_RSV_C10              (BIT5 + BIT6 + BIT7)    // 0/x/x/x Reserved
    #define CND003_PCIEPHYCFG_MCU_USE_PRESET_03_EP BIT4                    // 0/x/x/x Use Cursor Setting or PRESET Setting
    #define CND003_PCIEPHYCFG_MCU_TX_PRESET_03_EP  0xF                     // 0/x/x/x TX_PRESET Value when Doing EQ
#define CND003_PCIEPHYCFG_MCU_SET_PRE_CURSOR_LANE_3_EP 0xC11 // MCU Set Pre-cursor Lane 3 EP
    #define CND003_PCIEPHYCFG_RSV_C11              (BIT6 + BIT7)   // 0/x/x/x Reserved
    #define CND003_PCIEPHYCFG_MCU_PRE_CURSOR_03_EP 0x3F            // 0/x/x/x Lane 3
#define CND003_PCIEPHYCFG_MCU_SET_CURSOR_LANE_3_EP 0xC12 // MCU Set Cursor Lane 3 EP
    #define CND003_PCIEPHYCFG_RSV_C12          (BIT6 + BIT7)   // 0/x/x/x Reserved
    #define CND003_PCIEPHYCFG_MCU_CURSOR_03_EP 0x3F            // 0/x/x/x Lane 3
#define CND003_PCIEPHYCFG_MCU_SET_POST_CURSOR_LANE_3_EP 0xC13 // MCU Set Post-cursor Lane 3 EP
    #define CND003_PCIEPHYCFG_RSV_C13                  (BIT6 + BIT7)   // 0/x/x/x Reserved
    #define CND003_PCIEPHYCFG_MCU_POST_CURSOR_03_EP    0x3F            // 0/x/x/x Lane 3
#define CND003_PCIEPHYCFG_EQ_INT_TO_MCU_EP 0xC60 // EQ INT to MCU EP
    #define CND003_PCIEPHYCFG_RSV_C60 PCIEPHYCFG_EQ_INT_TO_MCU_EP // 0/R/x/x Reserved
#define CND003_PCIEPHYCFG_MCU_CHANGE_EQ_SETTING_EP 0xC61 // MCU Change EQ Setting EP
    #define CND003_PCIEPHYCFG_RSV_C61          0xFE    // 0/x/x/x Reserved
    #define CND003_PCIEPHYCFG_MCU_CHANGE_EQ_EP BIT0    // 0/X/x/x MCU Change Preset or Cursor
#define CND003_PCIEPHYCFG_MCU_RESET_EQ_TUNING_EP 0xC62 // MCU Reset EQ Tuning EP
    #define CND003_PCIEPHYCFG_RSV_C62                  0xFC    // 0/x/x/x Reserved
    #define CND003_PCIEPHYCFG_MCU_EQTNEN_EP            BIT1    // 0/x/x/x Reserved
    #define CND003_PCIEPHYCFG_MCU_P1_OR_EQTNRSTB_EP    BIT0    // 1b/x/x/x When EQCTL_SEL is 1?b0, Use P1
#define CND003_PCIEPHYCFG_MCU_SET_EQ_TUNING_EP 0xC63 // MCU Set EQ Tuning EP
    #define CND003_PCIEPHYCFG_RSV_C63          0xFE    // 0/x/x/x Reserved
    #define CND003_PCIEPHYCFG_MCU_EQCTL_SEL_EP BIT0    // 0/x/x/x EQ Active Method Select
#define CND003_PCIEPHYCFG_MCU_WORK_FINISH_EP 0xC64 // MCU Work Finish EP
    #define CND003_PCIEPHYCFG_RSV_C67              0xFFFFFE00  // 0/x/x/x Reserved
    #define CND003_PCIEPHYCFG_EQ_RESULT_DONE_EP    BIT8        // HwInit/x/x/x EQ Result Is Ready for MCU
    #define CND003_PCIEPHYCFG_RSV_C64              0xFE        // 0/x/x/x Reserved
    #define CND003_PCIEPHYCFG_MCU_DONE_EP          BIT0        // 0/x/x/x When MCU EQ Job Finishes, Write 1
#define CND003_PCIEPHYCFG_MCU_INT_EQ_ENABLE_EP 0xC68 // MCU INT_EQ Enable EP
    #define CND003_PCIEPHYCFG_RSV_C68          0xFE    // 0/x/x/x Reserved
    #define CND003_PCIEPHYCFG_PF_EQ_REQ_EN_EP  BIT0    // 1b/x/x/x MCU INT_EQ Enable
#define CND003_PCIEPHYCFG_R_EQPH1_BER_EP 0xC69 // R_EQPH1_BER_EP
    #define CND003_PCIEPHYCFG_RSV_C69              0xFE    // 0/R/x/x Reserved
    #define CND003_PCIEPHYCFG_R_EQPH1_BER_EP_Z1    BIT0    // 1b/x/x/x Check More Data in EQ Phase 1, so MCU Can Get Real Bit Error Rate in...
#define CND003_PCIEPHYCFG_PHYLS_STATE_EP 0xC6A // PHYLS State EP
    #define CND003_PCIEPHYCFG_PHYLS_STATE_EP_Z1 PCIEPHYCFG_PHYLS_STATE_EP // HwInit/x/x/x PHYLS State 
#define CND003_PCIEPHYCFG_LINK_AND_EP_EQ_REQ_EP 0xC6B // Link and EP EQ REQ EP
    #define CND003_PCIEPHYCFG_RSV_C6B          0xFC    // 0/x/x/x Reserved
    #define CND003_PCIEPHYCFG_LINK_EQ_REQ_EP   BIT1    // 0/x/x/x Link EQ REQ 
    #define CND003_PCIEPHYCFG_RSV_C6B_0        BIT0    // 0/x/x/x Reserved
#define CND003_PCIEPHYCFG_RESERVED_Z95 0xC6C // Reserved
    #define CND003_PCIEPHYCFG_RSV_C6C PCIEPHYCFG_RESERVED_Z95 // 0/R/x/x Reserved
#define CND003_PCIEPHYCFG_MCU_TO_BIOS_DOORBELL 0xC6E // MCU to BIOS DoorBell
    #define CND003_PCIEPHYCFG_RSV_C6E      0xFE    // 0/x/x/x Reserved
    #define CND003_PCIEPHYCFG_MCU2BIOS_DB  BIT0    // 0/0/x/x Doorbell bit for MCU to BIOS
#define CND003_PCIEPHYCFG_BIOS_TO_MCU_DOORBELL 0xC6F // BIOS to MCU DoorBell
    #define CND003_PCIEPHYCFG_RSV_C6F      0xFE    // 0/x/x/x Reserved
    #define CND003_PCIEPHYCFG_BIOS2MCU_DB  BIT0    // 0/0/x/x Doorbell bit for MCU to BIOS
#define CND003_PCIEPHYCFG_SCRATCH_REG_0_FOR_MCU_TO_BIOS 0xC70 // Scratch Register_0 for MCU to BIOS
    #define CND003_PCIEPHYCFG_MCU2BIOS_SCRATCH_0 PCIEPHYCFG_SCRATCH_REG_0_FOR_MCU_TO_BIOS // 0/0/x/x Scratch Register0 for MCU to BIOS
#define CND003_PCIEPHYCFG_SCRATCH_REG_1_FOR_MCU_TO_BIOS 0xC74 // Scratch Register_1 for MCU to BIOS
    #define CND003_PCIEPHYCFG_MCU2BIOS_SCRATCH_1 PCIEPHYCFG_SCRATCH_REG_1_FOR_MCU_TO_BIOS // 0/0/x/x Scratch Register1 for MCU to BIOS
#define CND003_PCIEPHYCFG_SCRATCH_REG_2_FOR_MCU_TO_BIOS 0xC78 // Scratch Register_2 for MCU to BIOS
    #define CND003_PCIEPHYCFG_MCU2BIOS_SCRATCH_2 PCIEPHYCFG_SCRATCH_REG_2_FOR_MCU_TO_BIOS // 0/0/x/x Scratch Register2 for MCU to BIOS
#define CND003_PCIEPHYCFG_SCRATCH_REG_3_FOR_MCU_TO_BIOS 0xC7C // Scratch Register_3 for MCU to BIOS
    #define CND003_PCIEPHYCFG_MCU2BIOS_SCRATCH_3 PCIEPHYCFG_SCRATCH_REG_3_FOR_MCU_TO_BIOS // 0/0/x/x Scratch Register3 for MCU to BIOS
#define CND003_PCIEPHYCFG_SCRATCH_REG_4_FOR_MCU_TO_BIOS 0xC80 // Scratch Register_4 for MCU to BIOS
    #define CND003_PCIEPHYCFG_MCU2BIOS_SCRATCH_4 PCIEPHYCFG_SCRATCH_REG_4_FOR_MCU_TO_BIOS // 0/0/x/x Scratch Register4 for MCU to BIOS
#define CND003_PCIEPHYCFG_SCRATCH_REG_5_FOR_MCU_TO_BIOS 0xC84 // Scratch Register_5 for MCU to BIOS
    #define CND003_PCIEPHYCFG_MCU2BIOS_SCRATCH_5 PCIEPHYCFG_SCRATCH_REG_5_FOR_MCU_TO_BIOS // 0/0/x/x Scratch Register5 for MCU to BIOS
#define CND003_PCIEPHYCFG_SCRATCH_REG_6_FOR_MCU_TO_BIOS 0xC88 // Scratch Register_6 for MCU to BIOS
    #define CND003_PCIEPHYCFG_MCU2BIOS_SCRATCH_6 PCIEPHYCFG_SCRATCH_REG_6_FOR_MCU_TO_BIOS // 0/0/x/x Scratch Register6 for MCU to BIOS
#define CND003_PCIEPHYCFG_SCRATCH_REG_7_FOR_MCU_TO_BIOS 0xC8C // Scratch Register_7 for MCU to BIOS
    #define CND003_PCIEPHYCFG_MCU2BIOS_SCRATCH_7 PCIEPHYCFG_SCRATCH_REG_7_FOR_MCU_TO_BIOS // 0/0/x/x Scratch Register7 for MCU to BIOS.
#define CND003_PCIEPHYCFG_SCRATCH_REG_0_FOR_BIOS_TO_MCU 0xC90 // Scratch Register_0 for BIOS to MCU
    #define CND003_PCIEPHYCFG_BIOS2MCU_SCRATCH_0 PCIEPHYCFG_SCRATCH_REG_0_FOR_BIOS_TO_MCU // 0/0/x/x Scratch Register0 for BIOS to MCU
#define CND003_PCIEPHYCFG_SCRATCH_REG_1_FOR_BIOS_TO_MCU 0xC94 // Scratch Register_1 for BIOS to MCU
    #define CND003_PCIEPHYCFG_BIOS2MCU_SCRATCH_1 PCIEPHYCFG_SCRATCH_REG_1_FOR_BIOS_TO_MCU // 0/0/x/x Scratch Register1 for BIOS to MCU
#define CND003_PCIEPHYCFG_SCRATCH_REG_2_FOR_BIOS_TO_MCU 0xC98 // Scratch Register_2 for BIOS to MCU
    #define CND003_PCIEPHYCFG_BIOS2MCU_SCRATCH_2 PCIEPHYCFG_SCRATCH_REG_2_FOR_BIOS_TO_MCU // 0/0/x/x Scratch Register2 for BIOS to MCU
#define CND003_PCIEPHYCFG_SCRATCH_REG_3_FOR_BIOS_TO_MCU 0xC9C // Scratch Register_3 for BIOS to MCU
    #define CND003_PCIEPHYCFG_BIOS2MCU_SCRATCH_3 PCIEPHYCFG_SCRATCH_REG_3_FOR_BIOS_TO_MCU // 0/0/x/x Scratch Register3 for BIOS to MCU
#define CND003_PCIEPHYCFG_SCRATCH_REG_4_FOR_BIOS_TO_MCU 0xCA0 // Scratch Register_4 for BIOS to MCU
    #define CND003_PCIEPHYCFG_BIOS2MCU_SCRATCH_4 PCIEPHYCFG_SCRATCH_REG_4_FOR_BIOS_TO_MCU // 0/0/x/x Scratch Register4 for BIOS to MCU
#define CND003_PCIEPHYCFG_SCRATCH_REG_5_FOR_BIOS_TO_MCU 0xCA4 // Scratch Register_5 for BIOS to MCU
    #define CND003_PCIEPHYCFG_BIOS2MCU_SCRATCH_5 PCIEPHYCFG_SCRATCH_REG_5_FOR_BIOS_TO_MCU // 0/0/x/x Scratch Register5 for BIOS to MCU
#define CND003_PCIEPHYCFG_SCRATCH_REG_6_FOR_BIOS_TO_MCU 0xCA8 // Scratch Register_6 for BIOS to MCU
    #define CND003_PCIEPHYCFG_BIOS2MCU_SCRATCH_6 PCIEPHYCFG_SCRATCH_REG_6_FOR_BIOS_TO_MCU // 0/0/x/x Scratch Register6 for BIOS to MCU
#define CND003_PCIEPHYCFG_SCRATCH_REG_7_FOR_BIOS_TO_MCU 0xCAC // Scratch Register_7 for BIOS to MCU
    #define CND003_PCIEPHYCFG_BIOS2MCU_SCRATCH_7 PCIEPHYCFG_SCRATCH_REG_7_FOR_BIOS_TO_MCU // 0/0/x/x Scratch Register7 for BIOS to MCU
#define CND003_PCIEPHYCFG_LOOPBACK_LATENCY_CTL 0xCC0 // Loopback Latency Control
    #define CND003_PCIEPHYCFG_RSV_CC0          0xFFF0          // 0/R/x/x Reserved
    #define CND003_PCIEPHYCFG_RSV_CC0_1        (BIT2 + BIT3)   // 0/0/x/x Reserved
    #define CND003_PCIEPHYCFG_RLPLTCTL_04_PHYA (BIT0 + BIT1)   // 0/0/x/x Reserved
#define CND003_PCIEPHYCFG_LOOPBACK_LATENCY_CTL_Z1 0xCC2 // Loopback Latency Control
    #define CND003_PCIEPHYCFG_RSV_CC2          0xFF00          // 0/R/x/x Reserved
    #define CND003_PCIEPHYCFG_RLPLTCTL_03_PHYA (BIT6 + BIT7)   // 0/0/x/x Reserved
    #define CND003_PCIEPHYCFG_RLPLTCTL_02_PHYA (BIT4 + BIT5)   // 0/0/x/x Reserved
    #define CND003_PCIEPHYCFG_RLPLTCTL_01_PHYA (BIT2 + BIT3)   // 0/0/x/x Reserved
    #define CND003_PCIEPHYCFG_RLPLTCTL_00_PHYA (BIT0 + BIT1)   // 0/0/x/x Reserved
#define CND003_PCIEPHYCFG_LOOPBACK_LATENCY_CTL_Z2 0xCC4 // Loopback Latency Control
    #define CND003_PCIEPHYCFG_RSV_CC4          0xFF00          // 0/R/x/x Reserved
    #define CND003_PCIEPHYCFG_RLPLTCTL_03_PHYB (BIT6 + BIT7)   // 0/0/x/x Reserved
    #define CND003_PCIEPHYCFG_RLPLTCTL_02_PHYB (BIT4 + BIT5)   // 0/0/x/x Reserved
    #define CND003_PCIEPHYCFG_RLPLTCTL_01_PHYB (BIT2 + BIT3)   // 0/0/x/x Reserved
    #define CND003_PCIEPHYCFG_RLPLTCTL_00_PHYB (BIT0 + BIT1)   // 0/0/x/x Reserved
#define CND003_PCIEPHYCFG_LOOPBACK_LATENCY_CTL_Z3 0xCC6 // Loopback Latency Control
    #define CND003_PCIEPHYCFG_RSV_CC6          0xF000          // 0/0/x/x Reserved
    #define CND003_PCIEPHYCFG_RSV_CC6_1        (BIT10 + BIT11) // 0/0/x/x Reserved
    #define CND003_PCIEPHYCFG_RSV_CC6_2        (BIT8 + BIT9)   // 0/0/x/x Reserved
    #define CND003_PCIEPHYCFG_RLPLTCTL_03_EP   (BIT6 + BIT7)   // 0/0/x/x Reserved
    #define CND003_PCIEPHYCFG_RLPLTCTL_02_EP   (BIT4 + BIT5)   // 0/0/x/x Reserved
    #define CND003_PCIEPHYCFG_RLPLTCTL_01_EP   (BIT2 + BIT3)   // 0/0/x/x Reserved
    #define CND003_PCIEPHYCFG_RLPLTCTL_00_EP   (BIT0 + BIT1)   // 0/0/x/x Reserved
#define CND003_PCIEPHYCFG_EQUALIZATION_CTL_REG_ORIGINAL_VALUE_EP_LANE00 0xCE8 // Equalization Control Register Original Value EP Lane00
    #define CND003_PCIEPHYCFG_RSV_CE9                  BIT15                   // 0/0/x/x Reserved
    #define CND003_PCIEPHYCFG_USRXPRESETHITORG_00_EP   (BIT12 + BIT13 + BIT14) // 000b/000b/x/x EP Lane 00 Upstream RX Preset Hint Original Value
    #define CND003_PCIEPHYCFG_USTXPRESETORG_00_EP      0xF00                   // 0000b/0000b/x/x EP Lane 00 Upstream TX Preset Original Value
    #define CND003_PCIEPHYCFG_RSV_CE8                  BIT7                    // 0/0/x/x Reserved
    #define CND003_PCIEPHYCFG_DSRXPRESETHINTORG_00_EP  (BIT4 + BIT5 + BIT6)    // 000b/000b/x/x EP Lane 00 Downstream RX Preset Hint Original Value
    #define CND003_PCIEPHYCFG_DSTXPRESETORG_00_EP      0xF                     // 0000b/0000b/x/x EP Lane 00 Downstream TX Preset Original Value
#define CND003_PCIEPHYCFG_EQUALIZATION_CTL_REG_ORIGINAL_VALUE_EP_LANE01 0xCEA // Equalization Control Register Original Value EP Lane01
    #define CND003_PCIEPHYCFG_RSV_CEB                  BIT15                   // 0/0/x/x Reserved
    #define CND003_PCIEPHYCFG_USRXPRESETHITORG_01_EP   (BIT12 + BIT13 + BIT14) // 000b/000b/x/x EP Lane 01 Upstream RX Preset Hint Original Value
    #define CND003_PCIEPHYCFG_USTXPRESETORG_01_EP      0xF00                   // 0000b/0000b/x/x EP Lane 01 Upstream TX Preset Original Value
    #define CND003_PCIEPHYCFG_RSV_CEA                  BIT7                    // 0/0/x/x Reserved
    #define CND003_PCIEPHYCFG_DSRXPRESETHINTORG_01_EP  (BIT4 + BIT5 + BIT6)    // 000b/000b/x/x EP Lane 01 Downstream RX Preset Hint Original Value
    #define CND003_PCIEPHYCFG_DSTXPRESETORG_01_EP      0xF                     // 0000b/0000b/x/x EP Lane 01 Downstream TX Preset Original Value
#define CND003_PCIEPHYCFG_EQUALIZATION_CTL_REG_ORIGINAL_VALUE_EP_LANE02 0xCEC // Equalization Control Register Original Value EP Lane02
    #define CND003_PCIEPHYCFG_RSV_CED                  BIT15                   // 0/0/x/x Reserved
    #define CND003_PCIEPHYCFG_USRXPRESETHITORG_02_EP   (BIT12 + BIT13 + BIT14) // 000b/000b/x/x EP Lane 02 Upstream RX Preset Hint Original Value
    #define CND003_PCIEPHYCFG_USTXPRESETORG_02_EP      0xF00                   // 0000b/0000b/x/x EP Lane 02 Upstream TX Preset Original Value
    #define CND003_PCIEPHYCFG_RSV_CEC                  BIT7                    // 0/0/x/x Reserved
    #define CND003_PCIEPHYCFG_DSRXPRESETHINTORG_02_EP  (BIT4 + BIT5 + BIT6)    // 000b/000b/x/x EP Lane 02 Downstream RX Preset Hint Original Value
    #define CND003_PCIEPHYCFG_DSTXPRESETORG_02_EP      0xF                     // 0000b/0000b/x/x EP Lane 02 Downstream TX Preset Original Value
#define CND003_PCIEPHYCFG_EQUALIZATION_CTL_REG_ORIGINAL_VALUE_EP_LANE03 0xCEE // Equalization Control Register Original Value EP Lane03
    #define CND003_PCIEPHYCFG_RSV_CEF                  BIT15                   // 0/0/x/x Reserved
    #define CND003_PCIEPHYCFG_USRXPRESETHITORG_03_EP   (BIT12 + BIT13 + BIT14) // 000b/000b/x/x EP Lane 03 Upstream RX Preset Hint Original Value
    #define CND003_PCIEPHYCFG_USTXPRESETORG_03_EP      0xF00                   // 0000b/0000b/x/x EP Lane 03 Upstream TX Preset Original Value
    #define CND003_PCIEPHYCFG_RSV_CEE                  BIT7                    // 0/0/x/x Reserved
    #define CND003_PCIEPHYCFG_DSRXPRESETHINTORG_03_EP  (BIT4 + BIT5 + BIT6)    // 000b/000b/x/x EP Lane 03 Downstream RX Preset Hint Original Value
    #define CND003_PCIEPHYCFG_DSTXPRESETORG_03_EP      0xF                     // 0000b/0000b/x/x EP Lane 03 Downstream TX Preset Original Value
// PCIEEPHYCFG
#define CND003_PCIEEPHYCFG_TX_SWING_TABLE_LANE00_INDEX00 0xD00 // TX Swing Table Lane00-Index00
    #define CND003_PCIEEPHYCFG_FRP00_V0_00_TXPSR   (BIT29 + BIT30 + BIT31) // 011b/011b/x/x PMOS TX Slew Rate Control
    #define CND003_PCIEEPHYCFG_FRP00_V0_00_TXNSR   (BIT26 + BIT27 + BIT28) // 011b/011b/x/x NMOS TX Slew Rate Control
    #define CND003_PCIEEPHYCFG_FRP00_V0_00_TX_DUTY (BIT24 + BIT25)         // 00b/00b/x/x TX Clock Duty Control
    #define CND003_PCIEEPHYCFG_RSV00_0D00_22       (BIT22 + BIT23)         // 0/0/x/x Reserved
    #define CND003_PCIEEPHYCFG_FRP00_V0_00_TDNCIS  0x3F0000                // 000000b/000000b/x/x TX De-emphasis Set
    #define CND003_PCIEEPHYCFG_RSV00_0D00_13       (BIT13 + BIT14 + BIT15) // 0/0/x/x Reserved
    #define CND003_PCIEEPHYCFG_FRP00_V0_00_TDCIS   0x1F00                  // 10100b/10100b/x/x TX Bias Control Set
    #define CND003_PCIEEPHYCFG_RSV00_0D00_6        (BIT6 + BIT7)           // 0/0/x/x Reserved
    #define CND003_PCIEEPHYCFG_FRP00_V0_00_TDPCIS  0x3F                    // 000000b/000000b/x/x TX Preshoot Set
#define CND003_PCIEEPHYCFG_TX_SWING_TABLE_LANE00_INDEX01 0xD04 // TX Swing Table Lane00-Index01
    #define CND003_PCIEEPHYCFG_FRP00_V0_01_TXPSR   (BIT29 + BIT30 + BIT31) // 011b/011b/x/x PMOS TX Slew Rate Control
    #define CND003_PCIEEPHYCFG_FRP00_V0_01_TXNSR   (BIT26 + BIT27 + BIT28) // 011b/011b/x/x NMOS TX Slew Rate Control
    #define CND003_PCIEEPHYCFG_FRP00_V0_01_TX_DUTY (BIT24 + BIT25)         // 00b/00b/x/x TX Clock Duty Control
    #define CND003_PCIEEPHYCFG_RSV00_0D04_22       (BIT22 + BIT23)         // 0/0/x/x Reserved
    #define CND003_PCIEEPHYCFG_FRP00_V0_01_TDNCIS  0x3F0000                // 001001b/001001b/x/x TX De-emphasis Set
    #define CND003_PCIEEPHYCFG_RSV00_0D04_13       (BIT13 + BIT14 + BIT15) // 0/0/x/x Reserved
    #define CND003_PCIEEPHYCFG_FRP00_V0_01_TDCIS   0x1F00                  // 11111b/11111b/x/x TX Bias Control Set
    #define CND003_PCIEEPHYCFG_RSV00_0D04_6        (BIT6 + BIT7)           // 0/0/x/x Reserved
    #define CND003_PCIEEPHYCFG_FRP00_V0_01_TDPCIS  0x3F                    // 000000b/000000b/x/x TX Preshoot Set
#define CND003_PCIEEPHYCFG_TX_SWING_TABLE_LANE00_INDEX02 0xD08 // TX Swing Table Lane00-Index02
    #define CND003_PCIEEPHYCFG_FRP00_V0_02_TXPSR   (BIT29 + BIT30 + BIT31) // 011b/011b/x/x PMOS TX Slew Rate Control
    #define CND003_PCIEEPHYCFG_FRP00_V0_02_TXNSR   (BIT26 + BIT27 + BIT28) // 011b/011b/x/x NMOS TX Slew Rate Control
    #define CND003_PCIEEPHYCFG_FRP00_V0_02_TX_DUTY (BIT24 + BIT25)         // 00b/00b/x/x TX Clock Duty Control
    #define CND003_PCIEEPHYCFG_RSV00_0D08_22       (BIT22 + BIT23)         // 0/0/x/x Reserved
    #define CND003_PCIEEPHYCFG_FRP00_V0_02_TDNCIS  0x3F0000                // 010010b/010010b/x/x TX De-emphasis Set
    #define CND003_PCIEEPHYCFG_RSV00_0D08_13       (BIT13 + BIT14 + BIT15) // 0/0/x/x Reserved
    #define CND003_PCIEEPHYCFG_FRP00_V0_02_TDCIS   0x1F00                  // 11111b/11111b/x/x TX Bias Control Set
    #define CND003_PCIEEPHYCFG_RSV00_0D08_6        (BIT6 + BIT7)           // 0/0/x/x Reserved
    #define CND003_PCIEEPHYCFG_FRP00_V0_02_TDPCIS  0x3F                    // 000000b/000000b/x/x TX Preshoot Set
#define CND003_PCIEEPHYCFG_TX_SWING_TABLE_LANE00_INDEX03 0xD0C // TX Swing Table Lane00-Index03
    #define CND003_PCIEEPHYCFG_FRP00_V0_03_TXPSR   (BIT29 + BIT30 + BIT31) // 011b/011b/x/x PMOS TX Slew Rate Control
    #define CND003_PCIEEPHYCFG_FRP00_V0_03_TXNSR   (BIT26 + BIT27 + BIT28) // 011b/011b/x/x NMOS TX Slew Rate Control
    #define CND003_PCIEEPHYCFG_FRP00_V0_03_TX_DUTY (BIT24 + BIT25)         // 00b/00b/x/x TX Clock Duty Control
    #define CND003_PCIEEPHYCFG_RSV00_0D0C_22       (BIT22 + BIT23)         // 0/0/x/x Reserved
    #define CND003_PCIEEPHYCFG_FRP00_V0_03_TDNCIS  0x3F0000                // 011010b/011010b/x/x TX De-emphasis Set
    #define CND003_PCIEEPHYCFG_RSV00_0D0C_13       (BIT13 + BIT14 + BIT15) // 0/0/x/x Reserved
    #define CND003_PCIEEPHYCFG_FRP00_V0_03_TDCIS   0x1F00                  // 11110b/11110b/x/x TX Bias Control Set
    #define CND003_PCIEEPHYCFG_RSV00_0D0C_6        (BIT6 + BIT7)           // 0/0/x/x Reserved
    #define CND003_PCIEEPHYCFG_FRP00_V0_03_TDPCIS  0x3F                    // 000000b/000000b/x/x TX Preshoot Set
#define CND003_PCIEEPHYCFG_TX_SWING_TABLE_LANE00_INDEX04 0xD10 // TX Swing Table Lane00-Index04
    #define CND003_PCIEEPHYCFG_FRP00_V0_04_TXPSR   (BIT29 + BIT30 + BIT31) // 011b/011b/x/x PMOS TX Slew Rate Control
    #define CND003_PCIEEPHYCFG_FRP00_V0_04_TXNSR   (BIT26 + BIT27 + BIT28) // 011b/011b/x/x NMOS TX Slew Rate Control
    #define CND003_PCIEEPHYCFG_FRP00_V0_04_TX_DUTY (BIT24 + BIT25)         // 00b/00b/x/x TX Clock Duty Control
    #define CND003_PCIEEPHYCFG_RSV00_0D10_22       (BIT22 + BIT23)         // 0/0/x/x Reserved
    #define CND003_PCIEEPHYCFG_FRP00_V0_04_TDNCIS  0x3F0000                // 100010b/100010b/x/x TX De-emphasis Set
    #define CND003_PCIEEPHYCFG_RSV00_0D10_13       (BIT13 + BIT14 + BIT15) // 0/0/x/x Reserved
    #define CND003_PCIEEPHYCFG_FRP00_V0_04_TDCIS   0x1F00                  // 11101b/11101b/x/x TX Bias Control Set
    #define CND003_PCIEEPHYCFG_RSV00_0D10_6        (BIT6 + BIT7)           // 0/0/x/x Reserved
    #define CND003_PCIEEPHYCFG_FRP00_V0_04_TDPCIS  0x3F                    // 000000b/000000b/x/x TX Preshoot Set
#define CND003_PCIEEPHYCFG_TX_SWING_TABLE_LANE00_INDEX05 0xD14 // TX Swing Table Lane00-Index05
    #define CND003_PCIEEPHYCFG_FRP00_V0_05_TXPSR   (BIT29 + BIT30 + BIT31) // 011b/011b/x/x PMOS TX Slew Rate Control
    #define CND003_PCIEEPHYCFG_FRP00_V0_05_TXNSR   (BIT26 + BIT27 + BIT28) // 011b/011b/x/x NMOS TX Slew Rate Control
    #define CND003_PCIEEPHYCFG_FRP00_V0_05_TX_DUTY (BIT24 + BIT25)         // 00b/00b/x/x TX Clock Duty Control
    #define CND003_PCIEEPHYCFG_RSV00_0D14_22       (BIT22 + BIT23)         // 0/0/x/x Reserved
    #define CND003_PCIEEPHYCFG_FRP00_V0_05_TDNCIS  0x3F0000                // 101010b/101010b/x/x TX De-emphasis Set
    #define CND003_PCIEEPHYCFG_RSV00_0D14_13       (BIT13 + BIT14 + BIT15) // 0/0/x/x Reserved
    #define CND003_PCIEEPHYCFG_FRP00_V0_05_TDCIS   0x1F00                  // 11100b/11100b/x/x TX Bias Control Set
    #define CND003_PCIEEPHYCFG_RSV00_0D14_6        (BIT6 + BIT7)           // 0/0/x/x Reserved
    #define CND003_PCIEEPHYCFG_FRP00_V0_05_TDPCIS  0x3F                    // 000000b/000000b/x/x TX Preshoot Set
#define CND003_PCIEEPHYCFG_TX_SWING_TABLE_LANE00_INDEX06 0xD18 // TX Swing Table Lane00-Index06
    #define CND003_PCIEEPHYCFG_FRP00_V0_06_TXPSR   (BIT29 + BIT30 + BIT31) // 011b/011b/x/x PMOS TX Slew Rate Control
    #define CND003_PCIEEPHYCFG_FRP00_V0_06_TXNSR   (BIT26 + BIT27 + BIT28) // 011b/011b/x/x NMOS TX Slew Rate Control
    #define CND003_PCIEEPHYCFG_FRP00_V0_06_TX_DUTY (BIT24 + BIT25)         // 00b/00b/x/x TX Clock Duty Control
    #define CND003_PCIEEPHYCFG_RSV00_0D18_22       (BIT22 + BIT23)         // 0/0/x/x Reserved
    #define CND003_PCIEEPHYCFG_FRP00_V0_06_TDNCIS  0x3F0000                // 110010b/110010b/x/x TX De-emphasis Set
    #define CND003_PCIEEPHYCFG_RSV00_0D18_13       (BIT13 + BIT14 + BIT15) // 0/0/x/x Reserved
    #define CND003_PCIEEPHYCFG_FRP00_V0_06_TDCIS   0x1F00                  // 11011b/11011b/x/x TX Bias Control Set
    #define CND003_PCIEEPHYCFG_RSV00_0D18_6        (BIT6 + BIT7)           // 0/0/x/x Reserved
    #define CND003_PCIEEPHYCFG_FRP00_V0_06_TDPCIS  0x3F                    // 000000b/000000b/x/x TX Preshoot Set
#define CND003_PCIEEPHYCFG_TX_SWING_TABLE_LANE00_INDEX07 0xD1C // TX Swing Table Lane00-Index07
    #define CND003_PCIEEPHYCFG_FRP00_V0_07_TXPSR   (BIT29 + BIT30 + BIT31) // 011b/011b/x/x PMOS TX Slew Rate Control
    #define CND003_PCIEEPHYCFG_FRP00_V0_07_TXNSR   (BIT26 + BIT27 + BIT28) // 011b/011b/x/x NMOS TX Slew Rate Control
    #define CND003_PCIEEPHYCFG_FRP00_V0_07_TX_DUTY (BIT24 + BIT25)         // 00b/00b/x/x TX Clock Duty Control
    #define CND003_PCIEEPHYCFG_RSV00_0D1C_22       (BIT22 + BIT23)         // 0/0/x/x Reserved
    #define CND003_PCIEEPHYCFG_FRP00_V0_07_TDNCIS  0x3F0000                // 111101b/111101b/x/x TX De-emphasis Set
    #define CND003_PCIEEPHYCFG_RSV00_0D1C_13       (BIT13 + BIT14 + BIT15) // 0/0/x/x Reserved
    #define CND003_PCIEEPHYCFG_FRP00_V0_07_TDCIS   0x1F00                  // 11011b/11011b/x/x TX Bias Control Set
    #define CND003_PCIEEPHYCFG_RSV00_0D1C_6        (BIT6 + BIT7)           // 0/0/x/x Reserved
    #define CND003_PCIEEPHYCFG_FRP00_V0_07_TDPCIS  0x3F                    // 000000b/000000b/x/x TX Preshoot Set
#define CND003_PCIEEPHYCFG_TX_SWING_TABLE_LANE00_INDEX08 0xD20 // TX Swing Table Lane00-Index08
    #define CND003_PCIEEPHYCFG_FRP00_V0_08_TXPSR   (BIT29 + BIT30 + BIT31) // 011b/011b/x/x PMOS TX Slew Rate Control
    #define CND003_PCIEEPHYCFG_FRP00_V0_08_TXNSR   (BIT26 + BIT27 + BIT28) // 011b/011b/x/x NMOS TX Slew Rate Control
    #define CND003_PCIEEPHYCFG_FRP00_V0_08_TX_DUTY (BIT24 + BIT25)         // 00b/00b/x/x TX Clock Duty Control
    #define CND003_PCIEEPHYCFG_RSV00_0D20_22       (BIT22 + BIT23)         // 0/0/x/x Reserved
    #define CND003_PCIEEPHYCFG_FRP00_V0_08_TDNCIS  0x3F0000                // 111111b/111111b/x/x TX De-emphasis Set
    #define CND003_PCIEEPHYCFG_RSV00_0D20_13       (BIT13 + BIT14 + BIT15) // 0/0/x/x Reserved
    #define CND003_PCIEEPHYCFG_FRP00_V0_08_TDCIS   0x1F00                  // 11001b/11001b/x/x TX Bias Control Set
    #define CND003_PCIEEPHYCFG_RSV00_0D20_6        (BIT6 + BIT7)           // 0/0/x/x Reserved
    #define CND003_PCIEEPHYCFG_FRP00_V0_08_TDPCIS  0x3F                    // 000000b/000000b/x/x TX Preshoot Set
#define CND003_PCIEEPHYCFG_TX_SWING_TABLE_LANE00_INDEX09 0xD24 // TX Swing Table Lane00-Index09
    #define CND003_PCIEEPHYCFG_FRP00_V0_09_TXPSR   (BIT29 + BIT30 + BIT31) // 011b/011b/x/x PMOS TX Slew Rate Control
    #define CND003_PCIEEPHYCFG_FRP00_V0_09_TXNSR   (BIT26 + BIT27 + BIT28) // 011b/011b/x/x NMOS TX Slew Rate Control
    #define CND003_PCIEEPHYCFG_FRP00_V0_09_TX_DUTY (BIT24 + BIT25)         // 00b/00b/x/x TX Clock Duty Control
    #define CND003_PCIEEPHYCFG_RSV00_0D24_22       (BIT22 + BIT23)         // 0/0/x/x Reserved
    #define CND003_PCIEEPHYCFG_FRP00_V0_09_TDNCIS  0x3F0000                // 000000b/000000b/x/x TX De-emphasis Set
    #define CND003_PCIEEPHYCFG_RSV00_0D24_13       (BIT13 + BIT14 + BIT15) // 0/0/x/x Reserved
    #define CND003_PCIEEPHYCFG_FRP00_V0_09_TDCIS   0x1F00                  // 11111b/11111b/x/x TX Bias Control Set
    #define CND003_PCIEEPHYCFG_RSV00_0D24_6        (BIT6 + BIT7)           // 0/0/x/x Reserved
    #define CND003_PCIEEPHYCFG_FRP00_V0_09_TDPCIS  0x3F                    // 001001b/001001b/x/x TX Preshoot Set
#define CND003_PCIEEPHYCFG_TX_SWING_TABLE_LANE00_INDEX10 0xD28 // TX Swing Table Lane00-Index10
    #define CND003_PCIEEPHYCFG_FRP00_V0_10_TXPSR   (BIT29 + BIT30 + BIT31) // 011b/011b/x/x PMOS TX Slew Rate Control
    #define CND003_PCIEEPHYCFG_FRP00_V0_10_TXNSR   (BIT26 + BIT27 + BIT28) // 011b/011b/x/x NMOS TX Slew Rate Control
    #define CND003_PCIEEPHYCFG_FRP00_V0_10_TX_DUTY (BIT24 + BIT25)         // 00b/00b/x/x TX Clock Duty Control
    #define CND003_PCIEEPHYCFG_RSV00_0D28_22       (BIT22 + BIT23)         // 0/0/x/x Reserved
    #define CND003_PCIEEPHYCFG_FRP00_V0_10_TDNCIS  0x3F0000                // 001001b/001001b/x/x TX De-emphasis Set
    #define CND003_PCIEEPHYCFG_RSV00_0D28_13       (BIT13 + BIT14 + BIT15) // 0/0/x/x Reserved
    #define CND003_PCIEEPHYCFG_FRP00_V0_10_TDCIS   0x1F00                  // 11111b/11111b/x/x TX Bias Control Set
    #define CND003_PCIEEPHYCFG_RSV00_0D28_6        (BIT6 + BIT7)           // 0/0/x/x Reserved
    #define CND003_PCIEEPHYCFG_FRP00_V0_10_TDPCIS  0x3F                    // 001001b/001001b/x/x TX Preshoot Set
#define CND003_PCIEEPHYCFG_TX_SWING_TABLE_LANE00_INDEX11 0xD2C // TX Swing Table Lane00-Index11
    #define CND003_PCIEEPHYCFG_FRP00_V0_11_TXPSR   (BIT29 + BIT30 + BIT31) // 011b/011b/x/x PMOS TX Slew Rate Control
    #define CND003_PCIEEPHYCFG_FRP00_V0_11_TXNSR   (BIT26 + BIT27 + BIT28) // 011b/011b/x/x NMOS TX Slew Rate Control
    #define CND003_PCIEEPHYCFG_FRP00_V0_11_TX_DUTY (BIT24 + BIT25)         // 00b/00b/x/x TX Clock Duty Control
    #define CND003_PCIEEPHYCFG_RSV00_0D2C_22       (BIT22 + BIT23)         // 0/0/x/x Reserved
    #define CND003_PCIEEPHYCFG_FRP00_V0_11_TDNCIS  0x3F0000                // 010001b/010001b/x/x TX De-emphasis Set
    #define CND003_PCIEEPHYCFG_RSV00_0D2C_13       (BIT13 + BIT14 + BIT15) // 0/0/x/x Reserved
    #define CND003_PCIEEPHYCFG_FRP00_V0_11_TDCIS   0x1F00                  // 11110b/11110b/x/x TX Bias Control Set
    #define CND003_PCIEEPHYCFG_RSV00_0D2C_6        (BIT6 + BIT7)           // 0/0/x/x Reserved
    #define CND003_PCIEEPHYCFG_FRP00_V0_11_TDPCIS  0x3F                    // 001001b/001001b/x/x TX Preshoot Set
#define CND003_PCIEEPHYCFG_TX_SWING_TABLE_LANE00_INDEX12 0xD30 // TX Swing Table Lane00-Index12
    #define CND003_PCIEEPHYCFG_FRP00_V0_12_TXPSR   (BIT29 + BIT30 + BIT31) // 011b/011b/x/x PMOS TX Slew Rate Control
    #define CND003_PCIEEPHYCFG_FRP00_V0_12_TXNSR   (BIT26 + BIT27 + BIT28) // 011b/011b/x/x NMOS TX Slew Rate Control
    #define CND003_PCIEEPHYCFG_FRP00_V0_12_TX_DUTY (BIT24 + BIT25)         // 00b/00b/x/x TX Clock Duty Control
    #define CND003_PCIEEPHYCFG_RSV00_0D30_22       (BIT22 + BIT23)         // 0/0/x/x Reserved
    #define CND003_PCIEEPHYCFG_FRP00_V0_12_TDNCIS  0x3F0000                // 011010b/011010b/x/x TX De-emphasis Set
    #define CND003_PCIEEPHYCFG_RSV00_0D30_13       (BIT13 + BIT14 + BIT15) // 0/0/x/x Reserved
    #define CND003_PCIEEPHYCFG_FRP00_V0_12_TDCIS   0x1F00                  // 11101b/11101b/x/x TX Bias Control Set
    #define CND003_PCIEEPHYCFG_RSV00_0D30_6        (BIT6 + BIT7)           // 0/0/x/x Reserved
    #define CND003_PCIEEPHYCFG_FRP00_V0_12_TDPCIS  0x3F                    // 001001b/001001b/x/x TX Preshoot Set
#define CND003_PCIEEPHYCFG_TX_SWING_TABLE_LANE00_INDEX13 0xD34 // TX Swing Table Lane00-Index13
    #define CND003_PCIEEPHYCFG_FRP00_V0_13_TXPSR   (BIT29 + BIT30 + BIT31) // 011b/011b/x/x PMOS TX Slew Rate Control
    #define CND003_PCIEEPHYCFG_FRP00_V0_13_TXNSR   (BIT26 + BIT27 + BIT28) // 011b/011b/x/x NMOS TX Slew Rate Control
    #define CND003_PCIEEPHYCFG_FRP00_V0_13_TX_DUTY (BIT24 + BIT25)         // 00b/00b/x/x TX Clock Duty Control
    #define CND003_PCIEEPHYCFG_RSV00_0D34_22       (BIT22 + BIT23)         // 0/0/x/x Reserved
    #define CND003_PCIEEPHYCFG_FRP00_V0_13_TDNCIS  0x3F0000                // 100010b/100010b/x/x TX De-emphasis Set
    #define CND003_PCIEEPHYCFG_RSV00_0D34_13       (BIT13 + BIT14 + BIT15) // 0/0/x/x Reserved
    #define CND003_PCIEEPHYCFG_FRP00_V0_13_TDCIS   0x1F00                  // 11100b/11100b/x/x TX Bias Control Set
    #define CND003_PCIEEPHYCFG_RSV00_0D34_6        (BIT6 + BIT7)           // 0/0/x/x Reserved
    #define CND003_PCIEEPHYCFG_FRP00_V0_13_TDPCIS  0x3F                    // 001001b/001001b/x/x TX Preshoot Set
#define CND003_PCIEEPHYCFG_TX_SWING_TABLE_LANE00_INDEX14 0xD38 // TX Swing Table Lane00-Index14
    #define CND003_PCIEEPHYCFG_FRP00_V0_14_TXPSR   (BIT29 + BIT30 + BIT31) // 011b/011b/x/x PMOS TX Slew Rate Control
    #define CND003_PCIEEPHYCFG_FRP00_V0_14_TXNSR   (BIT26 + BIT27 + BIT28) // 011b/011b/x/x NMOS TX Slew Rate Control
    #define CND003_PCIEEPHYCFG_FRP00_V0_14_TX_DUTY (BIT24 + BIT25)         // 00b/00b/x/x TX Clock Duty Control
    #define CND003_PCIEEPHYCFG_RSV00_0D38_22       (BIT22 + BIT23)         // 0/0/x/x Reserved
    #define CND003_PCIEEPHYCFG_FRP00_V0_14_TDNCIS  0x3F0000                // 101010b/101010b/x/x TX De-emphasis Set
    #define CND003_PCIEEPHYCFG_RSV00_0D38_13       (BIT13 + BIT14 + BIT15) // 0/0/x/x Reserved
    #define CND003_PCIEEPHYCFG_FRP00_V0_14_TDCIS   0x1F00                  // 11011b/11011b/x/x TX Bias Control Set
    #define CND003_PCIEEPHYCFG_RSV00_0D38_6        (BIT6 + BIT7)           // 0/0/x/x Reserved
    #define CND003_PCIEEPHYCFG_FRP00_V0_14_TDPCIS  0x3F                    // 001001b/001001b/x/x TX Preshoot Set
#define CND003_PCIEEPHYCFG_TX_SWING_TABLE_LANE00_INDEX15 0xD3C // TX Swing Table Lane00-Index15
    #define CND003_PCIEEPHYCFG_FRP00_V0_15_TXPSR   (BIT29 + BIT30 + BIT31) // 011b/011b/x/x PMOS TX Slew Rate Control
    #define CND003_PCIEEPHYCFG_FRP00_V0_15_TXNSR   (BIT26 + BIT27 + BIT28) // 011b/011b/x/x NMOS TX Slew Rate Control
    #define CND003_PCIEEPHYCFG_FRP00_V0_15_TX_DUTY (BIT24 + BIT25)         // 00b/00b/x/x TX Clock Duty Control
    #define CND003_PCIEEPHYCFG_RSV00_0D3C_22       (BIT22 + BIT23)         // 0/0/x/x Reserved
    #define CND003_PCIEEPHYCFG_FRP00_V0_15_TDNCIS  0x3F0000                // 110010b/110010b/x/x TX De-emphasis Set
    #define CND003_PCIEEPHYCFG_RSV00_0D3C_13       (BIT13 + BIT14 + BIT15) // 0/0/x/x Reserved
    #define CND003_PCIEEPHYCFG_FRP00_V0_15_TDCIS   0x1F00                  // 11011b/11011b/x/x TX Bias Control Set
    #define CND003_PCIEEPHYCFG_RSV00_0D3C_6        (BIT6 + BIT7)           // 0/0/x/x Reserved
    #define CND003_PCIEEPHYCFG_FRP00_V0_15_TDPCIS  0x3F                    // 001001b/001001b/x/x TX Preshoot Set
#define CND003_PCIEEPHYCFG_TX_SWING_TABLE_LANE00_INDEX16 0xD40 // TX Swing Table Lane00-Index16
    #define CND003_PCIEEPHYCFG_FRP00_V0_16_TXPSR   (BIT29 + BIT30 + BIT31) // 011b/011b/x/x PMOS TX Slew Rate Control
    #define CND003_PCIEEPHYCFG_FRP00_V0_16_TXNSR   (BIT26 + BIT27 + BIT28) // 011b/011b/x/x NMOS TX Slew Rate Control
    #define CND003_PCIEEPHYCFG_FRP00_V0_16_TX_DUTY (BIT24 + BIT25)         // 00b/00b/x/x TX Clock Duty Control
    #define CND003_PCIEEPHYCFG_RSV00_0D40_22       (BIT22 + BIT23)         // 0/0/x/x Reserved
    #define CND003_PCIEEPHYCFG_FRP00_V0_16_TDNCIS  0x3F0000                // 111101b/111101b/x/x TX De-emphasis Set
    #define CND003_PCIEEPHYCFG_RSV00_0D40_13       (BIT13 + BIT14 + BIT15) // 0/0/x/x Reserved
    #define CND003_PCIEEPHYCFG_FRP00_V0_16_TDCIS   0x1F00                  // 11010b/11010b/x/x TX Bias Control Set
    #define CND003_PCIEEPHYCFG_RSV00_0D40_6        (BIT6 + BIT7)           // 0/0/x/x Reserved
    #define CND003_PCIEEPHYCFG_FRP00_V0_16_TDPCIS  0x3F                    // 001001b/001001b/x/x TX Preshoot Set
#define CND003_PCIEEPHYCFG_TX_SWING_TABLE_LANE00_INDEX17 0xD44 // TX Swing Table Lane00-Index17
    #define CND003_PCIEEPHYCFG_FRP00_V0_17_TXPSR   (BIT29 + BIT30 + BIT31) // 011b/011b/x/x PMOS TX Slew Rate Control
    #define CND003_PCIEEPHYCFG_FRP00_V0_17_TXNSR   (BIT26 + BIT27 + BIT28) // 011b/011b/x/x NMOS TX Slew Rate Control
    #define CND003_PCIEEPHYCFG_FRP00_V0_17_TX_DUTY (BIT24 + BIT25)         // 00b/00b/x/x TX Clock Duty Control
    #define CND003_PCIEEPHYCFG_RSV00_0D44_22       (BIT22 + BIT23)         // 0/0/x/x Reserved
    #define CND003_PCIEEPHYCFG_FRP00_V0_17_TDNCIS  0x3F0000                // 000000b/000000b/x/x TX De-emphasis Set
    #define CND003_PCIEEPHYCFG_RSV00_0D44_13       (BIT13 + BIT14 + BIT15) // 0/0/x/x Reserved
    #define CND003_PCIEEPHYCFG_FRP00_V0_17_TDCIS   0x1F00                  // 11111b/11111b/x/x TX Bias Control Set
    #define CND003_PCIEEPHYCFG_RSV00_0D44_6        (BIT6 + BIT7)           // 0/0/x/x Reserved
    #define CND003_PCIEEPHYCFG_FRP00_V0_17_TDPCIS  0x3F                    // 010001b/010001b/x/x TX Preshoot Set
#define CND003_PCIEEPHYCFG_TX_SWING_TABLE_LANE00_INDEX18 0xD48 // TX Swing Table Lane00-Index18
    #define CND003_PCIEEPHYCFG_FRP00_V0_18_TXPSR   (BIT29 + BIT30 + BIT31) // 011b/011b/x/x PMOS TX Slew Rate Control
    #define CND003_PCIEEPHYCFG_FRP00_V0_18_TXNSR   (BIT26 + BIT27 + BIT28) // 011b/011b/x/x NMOS TX Slew Rate Control
    #define CND003_PCIEEPHYCFG_FRP00_V0_18_TX_DUTY (BIT24 + BIT25)         // 00b/00b/x/x TX Clock Duty Control
    #define CND003_PCIEEPHYCFG_RSV00_0D48_22       (BIT22 + BIT23)         // 0/0/x/x Reserved
    #define CND003_PCIEEPHYCFG_FRP00_V0_18_TDNCIS  0x3F0000                // 001001b/001001b/x/x TX De-emphasis Set
    #define CND003_PCIEEPHYCFG_RSV00_0D48_13       (BIT13 + BIT14 + BIT15) // 0/0/x/x Reserved
    #define CND003_PCIEEPHYCFG_FRP00_V0_18_TDCIS   0x1F00                  // 11110b/11110b/x/x TX Bias Control Set
    #define CND003_PCIEEPHYCFG_RSV00_0D48_6        (BIT6 + BIT7)           // 0/0/x/x Reserved
    #define CND003_PCIEEPHYCFG_FRP00_V0_18_TDPCIS  0x3F                    // 010001b/010001b/x/x TX Preshoot Set
#define CND003_PCIEEPHYCFG_TX_SWING_TABLE_LANE00_INDEX19 0xD4C // TX Swing Table Lane00-Index19
    #define CND003_PCIEEPHYCFG_FRP00_V0_19_TXPSR   (BIT29 + BIT30 + BIT31) // 011b/011b/x/x PMOS TX Slew Rate Control
    #define CND003_PCIEEPHYCFG_FRP00_V0_19_TXNSR   (BIT26 + BIT27 + BIT28) // 011b/011b/x/x NMOS TX Slew Rate Control
    #define CND003_PCIEEPHYCFG_FRP00_V0_19_TX_DUTY (BIT24 + BIT25)         // 00b/00b/x/x TX Clock Duty Control
    #define CND003_PCIEEPHYCFG_RSV00_0D4C_22       (BIT22 + BIT23)         // 0/0/x/x Reserved
    #define CND003_PCIEEPHYCFG_FRP00_V0_19_TDNCIS  0x3F0000                // 010001b/010001b/x/x TX De-emphasis Set
    #define CND003_PCIEEPHYCFG_RSV00_0D4C_13       (BIT13 + BIT14 + BIT15) // 0/0/x/x Reserved
    #define CND003_PCIEEPHYCFG_FRP00_V0_19_TDCIS   0x1F00                  // 11101b/11101b/x/x TX Bias Control Set
    #define CND003_PCIEEPHYCFG_RSV00_0D4C_6        (BIT6 + BIT7)           // 0/0/x/x Reserved
    #define CND003_PCIEEPHYCFG_FRP00_V0_19_TDPCIS  0x3F                    // 010001b/010001b/x/x TX Preshoot Set
#define CND003_PCIEEPHYCFG_TX_SWING_TABLE_LANE00_INDEX20 0xD50 // TX Swing Table Lane00-Index20
    #define CND003_PCIEEPHYCFG_FRP00_V0_20_TXPSR   (BIT29 + BIT30 + BIT31) // 011b/011b/x/x PMOS TX Slew Rate Control
    #define CND003_PCIEEPHYCFG_FRP00_V0_20_TXNSR   (BIT26 + BIT27 + BIT28) // 011b/011b/x/x NMOS TX Slew Rate Control
    #define CND003_PCIEEPHYCFG_FRP00_V0_20_TX_DUTY (BIT24 + BIT25)         // 00b/00b/x/x TX Clock Duty Control
    #define CND003_PCIEEPHYCFG_RSV00_0D50_22       (BIT22 + BIT23)         // 0/0/x/x Reserved
    #define CND003_PCIEEPHYCFG_FRP00_V0_20_TDNCIS  0x3F0000                // 011000b/011000b/x/x TX De-emphasis Set
    #define CND003_PCIEEPHYCFG_RSV00_0D50_13       (BIT13 + BIT14 + BIT15) // 0/0/x/x Reserved
    #define CND003_PCIEEPHYCFG_FRP00_V0_20_TDCIS   0x1F00                  // 11100b/11100b/x/x TX Bias Control Set
    #define CND003_PCIEEPHYCFG_RSV00_0D50_6        (BIT6 + BIT7)           // 0/0/x/x Reserved
    #define CND003_PCIEEPHYCFG_FRP00_V0_20_TDPCIS  0x3F                    // 010001b/010001b/x/x TX Preshoot Set
#define CND003_PCIEEPHYCFG_TX_SWING_TABLE_LANE00_INDEX21 0xD54 // TX Swing Table Lane00-Index21
    #define CND003_PCIEEPHYCFG_FRP00_V0_21_TXPSR   (BIT29 + BIT30 + BIT31) // 011b/011b/x/x PMOS TX Slew Rate Control
    #define CND003_PCIEEPHYCFG_FRP00_V0_21_TXNSR   (BIT26 + BIT27 + BIT28) // 011b/011b/x/x NMOS TX Slew Rate Control
    #define CND003_PCIEEPHYCFG_FRP00_V0_21_TX_DUTY (BIT24 + BIT25)         // 00b/00b/x/x TX Clock Duty Control
    #define CND003_PCIEEPHYCFG_RSV00_0D54_22       (BIT22 + BIT23)         // 0/0/x/x Reserved
    #define CND003_PCIEEPHYCFG_FRP00_V0_21_TDNCIS  0x3F0000                // 100010b/100010b/x/x TX De-emphasis Set
    #define CND003_PCIEEPHYCFG_RSV00_0D54_13       (BIT13 + BIT14 + BIT15) // 0/0/x/x Reserved
    #define CND003_PCIEEPHYCFG_FRP00_V0_21_TDCIS   0x1F00                  // 11011b/11011b/x/x TX Bias Control Set
    #define CND003_PCIEEPHYCFG_RSV00_0D54_6        (BIT6 + BIT7)           // 0/0/x/x Reserved
    #define CND003_PCIEEPHYCFG_FRP00_V0_21_TDPCIS  0x3F                    // 010001b/010001b/x/x TX Preshoot Set
#define CND003_PCIEEPHYCFG_TX_SWING_TABLE_LANE00_INDEX22 0xD58 // TX Swing Table Lane00-Index22
    #define CND003_PCIEEPHYCFG_FRP00_V0_22_TXPSR   (BIT29 + BIT30 + BIT31) // 011b/011b/x/x PMOS TX Slew Rate Control
    #define CND003_PCIEEPHYCFG_FRP00_V0_22_TXNSR   (BIT26 + BIT27 + BIT28) // 011b/011b/x/x NMOS TX Slew Rate Control
    #define CND003_PCIEEPHYCFG_FRP00_V0_22_TX_DUTY (BIT24 + BIT25)         // 00b/00b/x/x TX Clock Duty Control
    #define CND003_PCIEEPHYCFG_RSV00_0D58_22       (BIT22 + BIT23)         // 0/0/x/x Reserved
    #define CND003_PCIEEPHYCFG_FRP00_V0_22_TDNCIS  0x3F0000                // 101100b/101100b/x/x TX De-emphasis Set
    #define CND003_PCIEEPHYCFG_RSV00_0D58_13       (BIT13 + BIT14 + BIT15) // 0/0/x/x Reserved
    #define CND003_PCIEEPHYCFG_FRP00_V0_22_TDCIS   0x1F00                  // 11011b/11011b/x/x TX Bias Control Set
    #define CND003_PCIEEPHYCFG_RSV00_0D58_6        (BIT6 + BIT7)           // 0/0/x/x Reserved
    #define CND003_PCIEEPHYCFG_FRP00_V0_22_TDPCIS  0x3F                    // 010001b/010001b/x/x TX Preshoot Set
#define CND003_PCIEEPHYCFG_TX_SWING_TABLE_LANE00_INDEX23 0xD5C // TX Swing Table Lane00-Index23
    #define CND003_PCIEEPHYCFG_FRP00_V0_23_TXPSR   (BIT29 + BIT30 + BIT31) // 011b/011b/x/x PMOS TX Slew Rate Control
    #define CND003_PCIEEPHYCFG_FRP00_V0_23_TXNSR   (BIT26 + BIT27 + BIT28) // 011b/011b/x/x NMOS TX Slew Rate Control
    #define CND003_PCIEEPHYCFG_FRP00_V0_23_TX_DUTY (BIT24 + BIT25)         // 00b/00b/x/x TX Clock Duty Control
    #define CND003_PCIEEPHYCFG_RSV00_0D5C_22       (BIT22 + BIT23)         // 0/0/x/x Reserved
    #define CND003_PCIEEPHYCFG_FRP00_V0_23_TDNCIS  0x3F0000                // 110010b/110010b/x/x TX De-emphasis Set
    #define CND003_PCIEEPHYCFG_RSV00_0D5C_13       (BIT13 + BIT14 + BIT15) // 0/0/x/x Reserved
    #define CND003_PCIEEPHYCFG_FRP00_V0_23_TDCIS   0x1F00                  // 11010b/11010b/x/x TX Bias Control Set
    #define CND003_PCIEEPHYCFG_RSV00_0D5C_6        (BIT6 + BIT7)           // 0/0/x/x Reserved
    #define CND003_PCIEEPHYCFG_FRP00_V0_23_TDPCIS  0x3F                    // 010001b/010001b/x/x TX Preshoot Set
#define CND003_PCIEEPHYCFG_TX_SWING_TABLE_LANE00_INDEX24 0xD60 // TX Swing Table Lane00-Index24
    #define CND003_PCIEEPHYCFG_FRP00_V0_24_TXPSR   (BIT29 + BIT30 + BIT31) // 011b/011b/x/x PMOS TX Slew Rate Control
    #define CND003_PCIEEPHYCFG_FRP00_V0_24_TXNSR   (BIT26 + BIT27 + BIT28) // 011b/011b/x/x NMOS TX Slew Rate Control
    #define CND003_PCIEEPHYCFG_FRP00_V0_24_TX_DUTY (BIT24 + BIT25)         // 00b/00b/x/x TX Clock Duty Control
    #define CND003_PCIEEPHYCFG_RSV00_0D60_22       (BIT22 + BIT23)         // 0/0/x/x Reserved
    #define CND003_PCIEEPHYCFG_FRP00_V0_24_TDNCIS  0x3F0000                // 000000b/000000b/x/x TX De-emphasis Set
    #define CND003_PCIEEPHYCFG_RSV00_0D60_13       (BIT13 + BIT14 + BIT15) // 0/0/x/x Reserved
    #define CND003_PCIEEPHYCFG_FRP00_V0_24_TDCIS   0x1F00                  // 11110b/11110b/x/x TX Bias Control Set
    #define CND003_PCIEEPHYCFG_RSV00_0D60_6        (BIT6 + BIT7)           // 0/0/x/x Reserved
    #define CND003_PCIEEPHYCFG_FRP00_V0_24_TDPCIS  0x3F                    // 011010b/011010b/x/x TX Preshoot Set
#define CND003_PCIEEPHYCFG_TX_SWING_TABLE_LANE00_INDEX25 0xD64 // TX Swing Table Lane00-Index25
    #define CND003_PCIEEPHYCFG_FRP00_V0_25_TXPSR   (BIT29 + BIT30 + BIT31) // 011b/011b/x/x PMOS TX Slew Rate Control
    #define CND003_PCIEEPHYCFG_FRP00_V0_25_TXNSR   (BIT26 + BIT27 + BIT28) // 011b/011b/x/x NMOS TX Slew Rate Control
    #define CND003_PCIEEPHYCFG_FRP00_V0_25_TX_DUTY (BIT24 + BIT25)         // 00b/00b/x/x TX Clock Duty Control
    #define CND003_PCIEEPHYCFG_RSV00_0D64_22       (BIT22 + BIT23)         // 0/0/x/x Reserved
    #define CND003_PCIEEPHYCFG_FRP00_V0_25_TDNCIS  0x3F0000                // 001001b/001001b/x/x TX De-emphasis Set
    #define CND003_PCIEEPHYCFG_RSV00_0D64_13       (BIT13 + BIT14 + BIT15) // 0/0/x/x Reserved
    #define CND003_PCIEEPHYCFG_FRP00_V0_25_TDCIS   0x1F00                  // 11101b/11101b/x/x TX Bias Control Set
    #define CND003_PCIEEPHYCFG_RSV00_0D64_6        (BIT6 + BIT7)           // 0/0/x/x Reserved
    #define CND003_PCIEEPHYCFG_FRP00_V0_25_TDPCIS  0x3F                    // 011010b/011010b/x/x TX Preshoot Set
#define CND003_PCIEEPHYCFG_TX_SWING_TABLE_LANE00_INDEX26 0xD68 // TX Swing Table Lane00-Index26
    #define CND003_PCIEEPHYCFG_FRP00_V0_26_TXPSR   (BIT29 + BIT30 + BIT31) // 011b/011b/x/x PMOS TX Slew Rate Control
    #define CND003_PCIEEPHYCFG_FRP00_V0_26_TXNSR   (BIT26 + BIT27 + BIT28) // 011b/011b/x/x NMOS TX Slew Rate Control
    #define CND003_PCIEEPHYCFG_FRP00_V0_26_TX_DUTY (BIT24 + BIT25)         // 00b/00b/x/x TX Clock Duty Control
    #define CND003_PCIEEPHYCFG_RSV00_0D68_22       (BIT22 + BIT23)         // 0/0/x/x Reserved
    #define CND003_PCIEEPHYCFG_FRP00_V0_26_TDNCIS  0x3F0000                // 010001b/010001b/x/x TX De-emphasis Set
    #define CND003_PCIEEPHYCFG_RSV00_0D68_13       (BIT13 + BIT14 + BIT15) // 0/0/x/x Reserved
    #define CND003_PCIEEPHYCFG_FRP00_V0_26_TDCIS   0x1F00                  // 11100b/11100b/x/x TX Bias Control Set
    #define CND003_PCIEEPHYCFG_RSV00_0D68_6        (BIT6 + BIT7)           // 0/0/x/x Reserved
    #define CND003_PCIEEPHYCFG_FRP00_V0_26_TDPCIS  0x3F                    // 011010b/011010b/x/x TX Preshoot Set
#define CND003_PCIEEPHYCFG_TX_SWING_TABLE_LANE00_INDEX27 0xD6C // TX Swing Table Lane00-Index27
    #define CND003_PCIEEPHYCFG_FRP00_V0_27_TXPSR   (BIT29 + BIT30 + BIT31) // 011b/011b/x/x PMOS TX Slew Rate Control
    #define CND003_PCIEEPHYCFG_FRP00_V0_27_TXNSR   (BIT26 + BIT27 + BIT28) // 011b/011b/x/x NMOS TX Slew Rate Control
    #define CND003_PCIEEPHYCFG_FRP00_V0_27_TX_DUTY (BIT24 + BIT25)         // 00b/00b/x/x TX Clock Duty Control
    #define CND003_PCIEEPHYCFG_RSV00_0D6C_22       (BIT22 + BIT23)         // 0/0/x/x Reserved
    #define CND003_PCIEEPHYCFG_FRP00_V0_27_TDNCIS  0x3F0000                // 011010b/011010b/x/x TX De-emphasis Set
    #define CND003_PCIEEPHYCFG_RSV00_0D6C_13       (BIT13 + BIT14 + BIT15) // 0/0/x/x Reserved
    #define CND003_PCIEEPHYCFG_FRP00_V0_27_TDCIS   0x1F00                  // 11011b/11011b/x/x TX Bias Control Set
    #define CND003_PCIEEPHYCFG_RSV00_0D6C_6        (BIT6 + BIT7)           // 0/0/x/x Reserved
    #define CND003_PCIEEPHYCFG_FRP00_V0_27_TDPCIS  0x3F                    // 011010b/011010b/x/x TX Preshoot Set
#define CND003_PCIEEPHYCFG_TX_SWING_TABLE_LANE00_INDEX28 0xD70 // TX Swing Table Lane00-Index28
    #define CND003_PCIEEPHYCFG_FRP00_V0_28_TXPSR   (BIT29 + BIT30 + BIT31) // 011b/011b/x/x PMOS TX Slew Rate Control
    #define CND003_PCIEEPHYCFG_FRP00_V0_28_TXNSR   (BIT26 + BIT27 + BIT28) // 011b/011b/x/x NMOS TX Slew Rate Control
    #define CND003_PCIEEPHYCFG_FRP00_V0_28_TX_DUTY (BIT24 + BIT25)         // 00b/00b/x/x TX Clock Duty Control
    #define CND003_PCIEEPHYCFG_RSV00_0D70_22       (BIT22 + BIT23)         // 0/0/x/x Reserved
    #define CND003_PCIEEPHYCFG_FRP00_V0_28_TDNCIS  0x3F0000                // 100010b/100010b/x/x TX De-emphasis Set
    #define CND003_PCIEEPHYCFG_RSV00_0D70_13       (BIT13 + BIT14 + BIT15) // 0/0/x/x Reserved
    #define CND003_PCIEEPHYCFG_FRP00_V0_28_TDCIS   0x1F00                  // 11011b/11011b/x/x TX Bias Control Set
    #define CND003_PCIEEPHYCFG_RSV00_0D70_6        (BIT6 + BIT7)           // 0/0/x/x Reserved
    #define CND003_PCIEEPHYCFG_FRP00_V0_28_TDPCIS  0x3F                    // 011010b/011010b/x/x TX Preshoot Set
#define CND003_PCIEEPHYCFG_TX_SWING_TABLE_LANE00_INDEX29 0xD74 // TX Swing Table Lane00-Index29
    #define CND003_PCIEEPHYCFG_FRP00_V0_29_TXPSR   (BIT29 + BIT30 + BIT31) // 011b/011b/x/x PMOS TX Slew Rate Control
    #define CND003_PCIEEPHYCFG_FRP00_V0_29_TXNSR   (BIT26 + BIT27 + BIT28) // 011b/011b/x/x NMOS TX Slew Rate Control
    #define CND003_PCIEEPHYCFG_FRP00_V0_29_TX_DUTY (BIT24 + BIT25)         // 00b/00b/x/x TX Clock Duty Control
    #define CND003_PCIEEPHYCFG_RSV00_0D74_22       (BIT22 + BIT23)         // 0/0/x/x Reserved
    #define CND003_PCIEEPHYCFG_FRP00_V0_29_TDNCIS  0x3F0000                // 101010b/101010b/x/x TX De-emphasis Set
    #define CND003_PCIEEPHYCFG_RSV00_0D74_13       (BIT13 + BIT14 + BIT15) // 0/0/x/x Reserved
    #define CND003_PCIEEPHYCFG_FRP00_V0_29_TDCIS   0x1F00                  // 11010b/11010b/x/x TX Bias Control Set
    #define CND003_PCIEEPHYCFG_RSV00_0D74_6        (BIT6 + BIT7)           // 0/0/x/x Reserved
    #define CND003_PCIEEPHYCFG_FRP00_V0_29_TDPCIS  0x3F                    // 011010b/011010b/x/x TX Preshoot Set
#define CND003_PCIEEPHYCFG_TX_SWING_TABLE_LANE00_INDEX30 0xD78 // TX Swing Table Lane00-Index30
    #define CND003_PCIEEPHYCFG_FRP00_V0_30_TXPSR   (BIT29 + BIT30 + BIT31) // 011b/011b/x/x PMOS TX Slew Rate Control
    #define CND003_PCIEEPHYCFG_FRP00_V0_30_TXNSR   (BIT26 + BIT27 + BIT28) // 011b/011b/x/x NMOS TX Slew Rate Control
    #define CND003_PCIEEPHYCFG_FRP00_V0_30_TX_DUTY (BIT24 + BIT25)         // 00b/00b/x/x TX Clock Duty Control
    #define CND003_PCIEEPHYCFG_RSV00_0D78_22       (BIT22 + BIT23)         // 0/0/x/x Reserved
    #define CND003_PCIEEPHYCFG_FRP00_V0_30_TDNCIS  0x3F0000                // 000000b/000000b/x/x TX De-emphasis Set
    #define CND003_PCIEEPHYCFG_RSV00_0D78_13       (BIT13 + BIT14 + BIT15) // 0/0/x/x Reserved
    #define CND003_PCIEEPHYCFG_FRP00_V0_30_TDCIS   0x1F00                  // 11101b/11101b/x/x TX Bias Control Set
    #define CND003_PCIEEPHYCFG_RSV00_0D78_6        (BIT6 + BIT7)           // 0/0/x/x Reserved
    #define CND003_PCIEEPHYCFG_FRP00_V0_30_TDPCIS  0x3F                    // 100010b/100010b/x/x TX Preshoot Set
#define CND003_PCIEEPHYCFG_TX_SWING_TABLE_LANE00_INDEX31 0xD7C // TX Swing Table Lane00-Index31
    #define CND003_PCIEEPHYCFG_FRP00_V0_31_TXPSR   (BIT29 + BIT30 + BIT31) // 011b/011b/x/x PMOS TX Slew Rate Control
    #define CND003_PCIEEPHYCFG_FRP00_V0_31_TXNSR   (BIT26 + BIT27 + BIT28) // 011b/011b/x/x NMOS TX Slew Rate Control
    #define CND003_PCIEEPHYCFG_FRP00_V0_31_TX_DUTY (BIT24 + BIT25)         // 00b/00b/x/x TX Clock Duty Control
    #define CND003_PCIEEPHYCFG_RSV00_0D7C_22       (BIT22 + BIT23)         // 0/0/x/x Reserved
    #define CND003_PCIEEPHYCFG_FRP00_V0_31_TDNCIS  0x3F0000                // 001001b/001001b/x/x TX De-emphasis Set
    #define CND003_PCIEEPHYCFG_RSV00_0D7C_13       (BIT13 + BIT14 + BIT15) // 0/0/x/x Reserved
    #define CND003_PCIEEPHYCFG_FRP00_V0_31_TDCIS   0x1F00                  // 11100b/11100b/x/x TX Bias Control Set
    #define CND003_PCIEEPHYCFG_RSV00_0D7C_6        (BIT6 + BIT7)           // 0/0/x/x Reserved
    #define CND003_PCIEEPHYCFG_FRP00_V0_31_TDPCIS  0x3F                    // 100010b/100010b/x/x TX Preshoot Set
#define CND003_PCIEEPHYCFG_TX_SWING_TABLE_LANE00_INDEX32 0xD80 // TX Swing Table Lane00-Index32
    #define CND003_PCIEEPHYCFG_FRP00_V0_32_TXPSR   (BIT29 + BIT30 + BIT31) // 011b/011b/x/x PMOS TX Slew Rate Control
    #define CND003_PCIEEPHYCFG_FRP00_V0_32_TXNSR   (BIT26 + BIT27 + BIT28) // 011b/011b/x/x NMOS TX Slew Rate Control
    #define CND003_PCIEEPHYCFG_FRP00_V0_32_TX_DUTY (BIT24 + BIT25)         // 00b/00b/x/x TX Clock Duty Control
    #define CND003_PCIEEPHYCFG_RSV00_0D80_22       (BIT22 + BIT23)         // 0/0/x/x Reserved
    #define CND003_PCIEEPHYCFG_FRP00_V0_32_TDNCIS  0x3F0000                // 010000b/010000b/x/x TX De-emphasis Set
    #define CND003_PCIEEPHYCFG_RSV00_0D80_13       (BIT13 + BIT14 + BIT15) // 0/0/x/x Reserved
    #define CND003_PCIEEPHYCFG_FRP00_V0_32_TDCIS   0x1F00                  // 11011b/11011b/x/x TX Bias Control Set
    #define CND003_PCIEEPHYCFG_RSV00_0D80_6        (BIT6 + BIT7)           // 0/0/x/x Reserved
    #define CND003_PCIEEPHYCFG_FRP00_V0_32_TDPCIS  0x3F                    // 100010b/100010b/x/x TX Preshoot Set
#define CND003_PCIEEPHYCFG_TX_SWING_TABLE_LANE00_INDEX33 0xD84 // TX Swing Table Lane00-Index33
    #define CND003_PCIEEPHYCFG_FRP00_V0_33_TXPSR   (BIT29 + BIT30 + BIT31) // 011b/011b/x/x PMOS TX Slew Rate Control
    #define CND003_PCIEEPHYCFG_FRP00_V0_33_TXNSR   (BIT26 + BIT27 + BIT28) // 011b/011b/x/x NMOS TX Slew Rate Control
    #define CND003_PCIEEPHYCFG_FRP00_V0_33_TX_DUTY (BIT24 + BIT25)         // 00b/00b/x/x TX Clock Duty Control
    #define CND003_PCIEEPHYCFG_RSV00_0D84_22       (BIT22 + BIT23)         // 0/0/x/x Reserved
    #define CND003_PCIEEPHYCFG_FRP00_V0_33_TDNCIS  0x3F0000                // 011010b/011010b/x/x TX De-emphasis Set
    #define CND003_PCIEEPHYCFG_RSV00_0D84_13       (BIT13 + BIT14 + BIT15) // 0/0/x/x Reserved
    #define CND003_PCIEEPHYCFG_FRP00_V0_33_TDCIS   0x1F00                  // 11011b/11011b/x/x TX Bias Control Set
    #define CND003_PCIEEPHYCFG_RSV00_0D84_6        (BIT6 + BIT7)           // 0/0/x/x Reserved
    #define CND003_PCIEEPHYCFG_FRP00_V0_33_TDPCIS  0x3F                    // 100010b/100010b/x/x TX Preshoot Set
#define CND003_PCIEEPHYCFG_TX_SWING_TABLE_LANE00_INDEX34 0xD88 // TX Swing Table Lane00-Index34
    #define CND003_PCIEEPHYCFG_FRP00_V0_34_TXPSR   (BIT29 + BIT30 + BIT31) // 011b/011b/x/x PMOS TX Slew Rate Control
    #define CND003_PCIEEPHYCFG_FRP00_V0_34_TXNSR   (BIT26 + BIT27 + BIT28) // 011b/011b/x/x NMOS TX Slew Rate Control
    #define CND003_PCIEEPHYCFG_FRP00_V0_34_TX_DUTY (BIT24 + BIT25)         // 00b/00b/x/x TX Clock Duty Control
    #define CND003_PCIEEPHYCFG_RSV00_0D88_22       (BIT22 + BIT23)         // 0/0/x/x Reserved
    #define CND003_PCIEEPHYCFG_FRP00_V0_34_TDNCIS  0x3F0000                // 100010b/100010b/x/x TX De-emphasis Set
    #define CND003_PCIEEPHYCFG_RSV00_0D88_13       (BIT13 + BIT14 + BIT15) // 0/0/x/x Reserved
    #define CND003_PCIEEPHYCFG_FRP00_V0_34_TDCIS   0x1F00                  // 11010b/11010b/x/x TX Bias Control Set
    #define CND003_PCIEEPHYCFG_RSV00_0D88_6        (BIT6 + BIT7)           // 0/0/x/x Reserved
    #define CND003_PCIEEPHYCFG_FRP00_V0_34_TDPCIS  0x3F                    // 100010b/100010b/x/x TX Preshoot Set
#define CND003_PCIEEPHYCFG_TX_SWING_TABLE_LANE00_INDEX35 0xD8C // TX Swing Table Lane00-Index35
    #define CND003_PCIEEPHYCFG_FRP00_V0_35_TXPSR   (BIT29 + BIT30 + BIT31) // 011b/011b/x/x PMOS TX Slew Rate Control
    #define CND003_PCIEEPHYCFG_FRP00_V0_35_TXNSR   (BIT26 + BIT27 + BIT28) // 011b/011b/x/x NMOS TX Slew Rate Control
    #define CND003_PCIEEPHYCFG_FRP00_V0_35_TX_DUTY (BIT24 + BIT25)         // 00b/00b/x/x TX Clock Duty Control
    #define CND003_PCIEEPHYCFG_RSV00_0D8C_22       (BIT22 + BIT23)         // 0/0/x/x Reserved
    #define CND003_PCIEEPHYCFG_FRP00_V0_35_TDNCIS  0x3F0000                // 000000b/000000b/x/x TX De-emphasis Set
    #define CND003_PCIEEPHYCFG_RSV00_0D8C_13       (BIT13 + BIT14 + BIT15) // 0/0/x/x Reserved
    #define CND003_PCIEEPHYCFG_FRP00_V0_35_TDCIS   0x1F00                  // 11100b/11100b/x/x TX Bias Control Set
    #define CND003_PCIEEPHYCFG_RSV00_0D8C_6        (BIT6 + BIT7)           // 0/0/x/x Reserved
    #define CND003_PCIEEPHYCFG_FRP00_V0_35_TDPCIS  0x3F                    // 101010b/101010b/x/x TX Preshoot Set
#define CND003_PCIEEPHYCFG_TX_SWING_TABLE_LANE00_INDEX36 0xD90 // TX Swing Table Lane00-Index36
    #define CND003_PCIEEPHYCFG_FRP00_V0_36_TXPSR   (BIT29 + BIT30 + BIT31) // 011b/011b/x/x PMOS TX Slew Rate Control
    #define CND003_PCIEEPHYCFG_FRP00_V0_36_TXNSR   (BIT26 + BIT27 + BIT28) // 011b/011b/x/x NMOS TX Slew Rate Control
    #define CND003_PCIEEPHYCFG_FRP00_V0_36_TX_DUTY (BIT24 + BIT25)         // 00b/00b/x/x TX Clock Duty Control
    #define CND003_PCIEEPHYCFG_RSV00_0D90_22       (BIT22 + BIT23)         // 0/0/x/x Reserved
    #define CND003_PCIEEPHYCFG_FRP00_V0_36_TDNCIS  0x3F0000                // 001000b/001000b/x/x TX De-emphasis Set
    #define CND003_PCIEEPHYCFG_RSV00_0D90_13       (BIT13 + BIT14 + BIT15) // 0/0/x/x Reserved
    #define CND003_PCIEEPHYCFG_FRP00_V0_36_TDCIS   0x1F00                  // 11011b/11011b/x/x TX Bias Control Set
    #define CND003_PCIEEPHYCFG_RSV00_0D90_6        (BIT6 + BIT7)           // 0/0/x/x Reserved
    #define CND003_PCIEEPHYCFG_FRP00_V0_36_TDPCIS  0x3F                    // 101010b/101010b/x/x TX Preshoot Set
#define CND003_PCIEEPHYCFG_TX_SWING_TABLE_LANE00_INDEX37 0xD94 // TX Swing Table Lane00-Index37
    #define CND003_PCIEEPHYCFG_FRP00_V0_37_TXPSR   (BIT29 + BIT30 + BIT31) // 011b/011b/x/x PMOS TX Slew Rate Control
    #define CND003_PCIEEPHYCFG_FRP00_V0_37_TXNSR   (BIT26 + BIT27 + BIT28) // 011b/011b/x/x NMOS TX Slew Rate Control
    #define CND003_PCIEEPHYCFG_FRP00_V0_37_TX_DUTY (BIT24 + BIT25)         // 00b/00b/x/x TX Clock Duty Control
    #define CND003_PCIEEPHYCFG_RSV00_0D94_22       (BIT22 + BIT23)         // 0/0/x/x Reserved
    #define CND003_PCIEEPHYCFG_FRP00_V0_37_TDNCIS  0x3F0000                // 010001b/010001b/x/x TX De-emphasis Set
    #define CND003_PCIEEPHYCFG_RSV00_0D94_13       (BIT13 + BIT14 + BIT15) // 0/0/x/x Reserved
    #define CND003_PCIEEPHYCFG_FRP00_V0_37_TDCIS   0x1F00                  // 11011b/11011b/x/x TX Bias Control Set
    #define CND003_PCIEEPHYCFG_RSV00_0D94_6        (BIT6 + BIT7)           // 0/0/x/x Reserved
    #define CND003_PCIEEPHYCFG_FRP00_V0_37_TDPCIS  0x3F                    // 101010b/101010b/x/x TX Preshoot Set
#define CND003_PCIEEPHYCFG_TX_SWING_TABLE_LANE00_INDEX38 0xD98 // TX Swing Table Lane00-Index38
    #define CND003_PCIEEPHYCFG_FRP00_V0_38_TXPSR   (BIT29 + BIT30 + BIT31) // 011b/011b/x/x PMOS TX Slew Rate Control
    #define CND003_PCIEEPHYCFG_FRP00_V0_38_TXNSR   (BIT26 + BIT27 + BIT28) // 011b/011b/x/x NMOS TX Slew Rate Control
    #define CND003_PCIEEPHYCFG_FRP00_V0_38_TX_DUTY (BIT24 + BIT25)         // 00b/00b/x/x TX Clock Duty Control
    #define CND003_PCIEEPHYCFG_RSV00_0D98_22       (BIT22 + BIT23)         // 0/0/x/x Reserved
    #define CND003_PCIEEPHYCFG_FRP00_V0_38_TDNCIS  0x3F0000                // 011010b/011010b/x/x TX De-emphasis Set
    #define CND003_PCIEEPHYCFG_RSV00_0D98_13       (BIT13 + BIT14 + BIT15) // 0/0/x/x Reserved
    #define CND003_PCIEEPHYCFG_FRP00_V0_38_TDCIS   0x1F00                  // 11010b/11010b/x/x TX Bias Control Set
    #define CND003_PCIEEPHYCFG_RSV00_0D98_6        (BIT6 + BIT7)           // 0/0/x/x Reserved
    #define CND003_PCIEEPHYCFG_FRP00_V0_38_TDPCIS  0x3F                    // 101010b/101010b/x/x TX Preshoot Set
#define CND003_PCIEEPHYCFG_TX_SWING_TABLE_LANE00_INDEX39 0xD9C // TX Swing Table Lane00-Index39
    #define CND003_PCIEEPHYCFG_FRP00_V0_39_TXPSR   (BIT29 + BIT30 + BIT31) // 011b/011b/x/x PMOS TX Slew Rate Control
    #define CND003_PCIEEPHYCFG_FRP00_V0_39_TXNSR   (BIT26 + BIT27 + BIT28) // 011b/011b/x/x NMOS TX Slew Rate Control
    #define CND003_PCIEEPHYCFG_FRP00_V0_39_TX_DUTY (BIT24 + BIT25)         // 00b/00b/x/x TX Clock Duty Control
    #define CND003_PCIEEPHYCFG_RSV00_0D9C_22       (BIT22 + BIT23)         // 0/0/x/x Reserved
    #define CND003_PCIEEPHYCFG_FRP00_V0_39_TDNCIS  0x3F0000                // 000000b/000000b/x/x TX De-emphasis Set
    #define CND003_PCIEEPHYCFG_RSV00_0D9C_13       (BIT13 + BIT14 + BIT15) // 0/0/x/x Reserved
    #define CND003_PCIEEPHYCFG_FRP00_V0_39_TDCIS   0x1F00                  // 11011b/11011b/x/x TX Bias Control Set
    #define CND003_PCIEEPHYCFG_RSV00_0D9C_6        (BIT6 + BIT7)           // 0/0/x/x Reserved
    #define CND003_PCIEEPHYCFG_FRP00_V0_39_TDPCIS  0x3F                    // 110010b/110010b/x/x TX Preshoot Set
#define CND003_PCIEEPHYCFG_TX_SWING_TABLE_LANE00_INDEX40 0xDA0 // TX Swing Table Lane00-Index40
    #define CND003_PCIEEPHYCFG_FRP00_V0_40_TXPSR   (BIT29 + BIT30 + BIT31) // 011b/011b/x/x PMOS TX Slew Rate Control
    #define CND003_PCIEEPHYCFG_FRP00_V0_40_TXNSR   (BIT26 + BIT27 + BIT28) // 011b/011b/x/x NMOS TX Slew Rate Control
    #define CND003_PCIEEPHYCFG_FRP00_V0_40_TX_DUTY (BIT24 + BIT25)         // 00b/00b/x/x TX Clock Duty Control
    #define CND003_PCIEEPHYCFG_RSV00_0DA0_22       (BIT22 + BIT23)         // 0/0/x/x Reserved
    #define CND003_PCIEEPHYCFG_FRP00_V0_40_TDNCIS  0x3F0000                // 001001b/001001b/x/x TX De-emphasis Set
    #define CND003_PCIEEPHYCFG_RSV00_0DA0_13       (BIT13 + BIT14 + BIT15) // 0/0/x/x Reserved
    #define CND003_PCIEEPHYCFG_FRP00_V0_40_TDCIS   0x1F00                  // 11011b/11011b/x/x TX Bias Control Set
    #define CND003_PCIEEPHYCFG_RSV00_0DA0_6        (BIT6 + BIT7)           // 0/0/x/x Reserved
    #define CND003_PCIEEPHYCFG_FRP00_V0_40_TDPCIS  0x3F                    // 110010b/110010b/x/x TX Preshoot Set
#define CND003_PCIEEPHYCFG_TX_SWING_TABLE_LANE00_41 0xDA4 // TX Swing Table Lane00-41
    #define CND003_PCIEEPHYCFG_FRP00_V0_41_TXPSR   (BIT29 + BIT30 + BIT31) // 011b/011b/x/x PMOS TX Slew Rate Control
    #define CND003_PCIEEPHYCFG_FRP00_V0_41_TXNSR   (BIT26 + BIT27 + BIT28) // 011b/011b/x/x NMOS TX Slew Rate Control
    #define CND003_PCIEEPHYCFG_FRP00_V0_41_TX_DUTY (BIT24 + BIT25)         // 00b/00b/x/x TX Clock Duty Control
    #define CND003_PCIEEPHYCFG_RSV00_0DA4_22       (BIT22 + BIT23)         // 0/0/x/x Reserved
    #define CND003_PCIEEPHYCFG_FRP00_V0_41_TDNCIS  0x3F0000                // 010001b/010001b/x/x TX De-emphasis Set
    #define CND003_PCIEEPHYCFG_RSV00_0DA4_13       (BIT13 + BIT14 + BIT15) // 0/0/x/x Reserved
    #define CND003_PCIEEPHYCFG_FRP00_V0_41_TDCIS   0x1F00                  // 11010b/11010b/x/x TX Bias Control Set
    #define CND003_PCIEEPHYCFG_RSV00_0DA4_6        (BIT6 + BIT7)           // 0/0/x/x Reserved
    #define CND003_PCIEEPHYCFG_FRP00_V0_41_TDPCIS  0x3F                    // 110010b/110010b/x/x TX Preshoot Set
#define CND003_PCIEEPHYCFG_TX_SWING_TABLE_LANE01_INDEX00 0xE00 // TX Swing Table Lane01-Index00
    #define CND003_PCIEEPHYCFG_FRP01_V0_00_TXPSR   (BIT29 + BIT30 + BIT31) // 011b/011b/x/x PMOS TX Slew Rate Control
    #define CND003_PCIEEPHYCFG_FRP01_V0_00_TXNSR   (BIT26 + BIT27 + BIT28) // 011b/011b/x/x NMOS TX Slew Rate Control
    #define CND003_PCIEEPHYCFG_FRP01_V0_00_TX_DUTY (BIT24 + BIT25)         // 00b/00b/x/x TX Clock Duty Control
    #define CND003_PCIEEPHYCFG_RSV01_0E00_22       (BIT22 + BIT23)         // 0/0/x/x Reserved
    #define CND003_PCIEEPHYCFG_FRP01_V0_00_TDNCIS  0x3F0000                // 000000b/000000b/x/x TX De-emphasis Set
    #define CND003_PCIEEPHYCFG_RSV01_0E00_13       (BIT13 + BIT14 + BIT15) // 0/0/x/x Reserved
    #define CND003_PCIEEPHYCFG_FRP01_V0_00_TDCIS   0x1F00                  // 10100b/10100b/x/x TX Bias Control Set
    #define CND003_PCIEEPHYCFG_RSV01_0E00_6        (BIT6 + BIT7)           // 0/0/x/x Reserved
    #define CND003_PCIEEPHYCFG_FRP01_V0_00_TDPCIS  0x3F                    // 000000b/000000b/x/x TX Preshoot Set
#define CND003_PCIEEPHYCFG_TX_SWING_TABLE_LANE01_INDEX01 0xE04 // TX Swing Table Lane01-Index01
    #define CND003_PCIEEPHYCFG_FRP01_V0_01_TXPSR   (BIT29 + BIT30 + BIT31) // 011b/011b/x/x PMOS TX Slew Rate Control
    #define CND003_PCIEEPHYCFG_FRP01_V0_01_TXNSR   (BIT26 + BIT27 + BIT28) // 011b/011b/x/x NMOS TX Slew Rate Control
    #define CND003_PCIEEPHYCFG_FRP01_V0_01_TX_DUTY (BIT24 + BIT25)         // 00b/00b/x/x TX Clock Duty Control
    #define CND003_PCIEEPHYCFG_RSV01_0E04_22       (BIT22 + BIT23)         // 0/0/x/x Reserved
    #define CND003_PCIEEPHYCFG_FRP01_V0_01_TDNCIS  0x3F0000                // 001001b/001001b/x/x TX De-emphasis Set
    #define CND003_PCIEEPHYCFG_RSV01_0E04_13       (BIT13 + BIT14 + BIT15) // 0/0/x/x Reserved
    #define CND003_PCIEEPHYCFG_FRP01_V0_01_TDCIS   0x1F00                  // 11111b/11111b/x/x TX Bias Control Set
    #define CND003_PCIEEPHYCFG_RSV01_0E04_6        (BIT6 + BIT7)           // 0/0/x/x Reserved
    #define CND003_PCIEEPHYCFG_FRP01_V0_01_TDPCIS  0x3F                    // 000000b/000000b/x/x TX Preshoot Set
#define CND003_PCIEEPHYCFG_TX_SWING_TABLE_LANE01_INDEX02 0xE08 // TX Swing Table Lane01-Index02
    #define CND003_PCIEEPHYCFG_FRP01_V0_02_TXPSR   (BIT29 + BIT30 + BIT31) // 011b/011b/x/x PMOS TX Slew Rate Control
    #define CND003_PCIEEPHYCFG_FRP01_V0_02_TXNSR   (BIT26 + BIT27 + BIT28) // 011b/011b/x/x NMOS TX Slew Rate Control
    #define CND003_PCIEEPHYCFG_FRP01_V0_02_TX_DUTY (BIT24 + BIT25)         // 00b/00b/x/x TX Clock Duty Control
    #define CND003_PCIEEPHYCFG_RSV01_0E08_22       (BIT22 + BIT23)         // 0/0/x/x Reserved
    #define CND003_PCIEEPHYCFG_FRP01_V0_02_TDNCIS  0x3F0000                // 010010b/010010b/x/x TX De-emphasis Set
    #define CND003_PCIEEPHYCFG_RSV01_0E08_13       (BIT13 + BIT14 + BIT15) // 0/0/x/x Reserved
    #define CND003_PCIEEPHYCFG_FRP01_V0_02_TDCIS   0x1F00                  // 11111b/11111b/x/x TX Bias Control Set
    #define CND003_PCIEEPHYCFG_RSV01_0E08_6        (BIT6 + BIT7)           // 0/0/x/x Reserved
    #define CND003_PCIEEPHYCFG_FRP01_V0_02_TDPCIS  0x3F                    // 000000b/000000b/x/x TX Preshoot Set
#define CND003_PCIEEPHYCFG_TX_SWING_TABLE_LANE01_INDEX03 0xE0C // TX Swing Table Lane01-Index03
    #define CND003_PCIEEPHYCFG_FRP01_V0_03_TXPSR   (BIT29 + BIT30 + BIT31) // 011b/011b/x/x PMOS TX Slew Rate Control
    #define CND003_PCIEEPHYCFG_FRP01_V0_03_TXNSR   (BIT26 + BIT27 + BIT28) // 011b/011b/x/x NMOS TX Slew Rate Control
    #define CND003_PCIEEPHYCFG_FRP01_V0_03_TX_DUTY (BIT24 + BIT25)         // 00b/00b/x/x TX Clock Duty Control
    #define CND003_PCIEEPHYCFG_RSV01_0E0C_22       (BIT22 + BIT23)         // 0/0/x/x Reserved
    #define CND003_PCIEEPHYCFG_FRP01_V0_03_TDNCIS  0x3F0000                // 011010b/011010b/x/x TX De-emphasis Set
    #define CND003_PCIEEPHYCFG_RSV01_0E0C_13       (BIT13 + BIT14 + BIT15) // 0/0/x/x Reserved
    #define CND003_PCIEEPHYCFG_FRP01_V0_03_TDCIS   0x1F00                  // 11110b/11110b/x/x TX Bias Control Set
    #define CND003_PCIEEPHYCFG_RSV01_0E0C_6        (BIT6 + BIT7)           // 0/0/x/x Reserved
    #define CND003_PCIEEPHYCFG_FRP01_V0_03_TDPCIS  0x3F                    // 000000b/000000b/x/x TX Preshoot Set
#define CND003_PCIEEPHYCFG_TX_SWING_TABLE_LANE01_INDEX04 0xE10 // TX Swing Table Lane01-Index04
    #define CND003_PCIEEPHYCFG_FRP01_V0_04_TXPSR   (BIT29 + BIT30 + BIT31) // 011b/011b/x/x PMOS TX Slew Rate Control
    #define CND003_PCIEEPHYCFG_FRP01_V0_04_TXNSR   (BIT26 + BIT27 + BIT28) // 011b/011b/x/x NMOS TX Slew Rate Control
    #define CND003_PCIEEPHYCFG_FRP01_V0_04_TX_DUTY (BIT24 + BIT25)         // 00b/00b/x/x TX Clock Duty Control
    #define CND003_PCIEEPHYCFG_RSV01_0E10_22       (BIT22 + BIT23)         // 0/0/x/x Reserved
    #define CND003_PCIEEPHYCFG_FRP01_V0_04_TDNCIS  0x3F0000                // 100010b/100010b/x/x TX De-emphasis Set
    #define CND003_PCIEEPHYCFG_RSV01_0E10_13       (BIT13 + BIT14 + BIT15) // 0/0/x/x Reserved
    #define CND003_PCIEEPHYCFG_FRP01_V0_04_TDCIS   0x1F00                  // 11101b/11101b/x/x TX Bias Control Set
    #define CND003_PCIEEPHYCFG_RSV01_0E10_6        (BIT6 + BIT7)           // 0/0/x/x Reserved
    #define CND003_PCIEEPHYCFG_FRP01_V0_04_TDPCIS  0x3F                    // 000000b/000000b/x/x TX Preshoot Set
#define CND003_PCIEEPHYCFG_TX_SWING_TABLE_LANE01_INDEX05 0xE14 // TX Swing Table Lane01-Index05
    #define CND003_PCIEEPHYCFG_FRP01_V0_05_TXPSR   (BIT29 + BIT30 + BIT31) // 011b/011b/x/x PMOS TX Slew Rate Control
    #define CND003_PCIEEPHYCFG_FRP01_V0_05_TXNSR   (BIT26 + BIT27 + BIT28) // 011b/011b/x/x NMOS TX Slew Rate Control
    #define CND003_PCIEEPHYCFG_FRP01_V0_05_TX_DUTY (BIT24 + BIT25)         // 00b/00b/x/x TX Clock Duty Control
    #define CND003_PCIEEPHYCFG_RSV01_0E14_22       (BIT22 + BIT23)         // 0/0/x/x Reserved
    #define CND003_PCIEEPHYCFG_FRP01_V0_05_TDNCIS  0x3F0000                // 101010b/101010b/x/x TX De-emphasis Set
    #define CND003_PCIEEPHYCFG_RSV01_0E14_13       (BIT13 + BIT14 + BIT15) // 0/0/x/x Reserved
    #define CND003_PCIEEPHYCFG_FRP01_V0_05_TDCIS   0x1F00                  // 11100b/11100b/x/x TX Bias Control Set
    #define CND003_PCIEEPHYCFG_RSV01_0E14_6        (BIT6 + BIT7)           // 0/0/x/x Reserved
    #define CND003_PCIEEPHYCFG_FRP01_V0_05_TDPCIS  0x3F                    // 000000b/000000b/x/x TX Preshoot Set
#define CND003_PCIEEPHYCFG_TX_SWING_TABLE_LANE01_INDEX06 0xE18 // TX Swing Table Lane01-Index06
    #define CND003_PCIEEPHYCFG_FRP01_V0_06_TXPSR   (BIT29 + BIT30 + BIT31) // 011b/011b/x/x PMOS TX Slew Rate Control
    #define CND003_PCIEEPHYCFG_FRP01_V0_06_TXNSR   (BIT26 + BIT27 + BIT28) // 011b/011b/x/x NMOS TX Slew Rate Control
    #define CND003_PCIEEPHYCFG_FRP01_V0_06_TX_DUTY (BIT24 + BIT25)         // 00b/00b/x/x TX Clock Duty Control
    #define CND003_PCIEEPHYCFG_RSV01_0E18_22       (BIT22 + BIT23)         // 0/0/x/x Reserved
    #define CND003_PCIEEPHYCFG_FRP01_V0_06_TDNCIS  0x3F0000                // 110010b/110010b/x/x TX De-emphasis Set
    #define CND003_PCIEEPHYCFG_RSV01_0E18_13       (BIT13 + BIT14 + BIT15) // 0/0/x/x Reserved
    #define CND003_PCIEEPHYCFG_FRP01_V0_06_TDCIS   0x1F00                  // 11011b/11011b/x/x TX Bias Control Set
    #define CND003_PCIEEPHYCFG_RSV01_0E18_6        (BIT6 + BIT7)           // 0/0/x/x Reserved
    #define CND003_PCIEEPHYCFG_FRP01_V0_06_TDPCIS  0x3F                    // 000000b/000000b/x/x TX Preshoot Set
#define CND003_PCIEEPHYCFG_TX_SWING_TABLE_LANE01_INDEX07 0xE1C // TX Swing Table Lane01-Index07
    #define CND003_PCIEEPHYCFG_FRP01_V0_07_TXPSR   (BIT29 + BIT30 + BIT31) // 011b/011b/x/x PMOS TX Slew Rate Control
    #define CND003_PCIEEPHYCFG_FRP01_V0_07_TXNSR   (BIT26 + BIT27 + BIT28) // 011b/011b/x/x NMOS TX Slew Rate Control
    #define CND003_PCIEEPHYCFG_FRP01_V0_07_TX_DUTY (BIT24 + BIT25)         // 00b/00b/x/x TX Clock Duty Control
    #define CND003_PCIEEPHYCFG_RSV01_0E1C_22       (BIT22 + BIT23)         // 0/0/x/x Reserved
    #define CND003_PCIEEPHYCFG_FRP01_V0_07_TDNCIS  0x3F0000                // 111101b/111101b/x/x TX De-emphasis Set
    #define CND003_PCIEEPHYCFG_RSV01_0E1C_13       (BIT13 + BIT14 + BIT15) // 0/0/x/x Reserved
    #define CND003_PCIEEPHYCFG_FRP01_V0_07_TDCIS   0x1F00                  // 11011b/11011b/x/x TX Bias Control Set
    #define CND003_PCIEEPHYCFG_RSV01_0E1C_6        (BIT6 + BIT7)           // 0/0/x/x Reserved
    #define CND003_PCIEEPHYCFG_FRP01_V0_07_TDPCIS  0x3F                    // 000000b/000000b/x/x TX Preshoot Set
#define CND003_PCIEEPHYCFG_TX_SWING_TABLE_LANE01_INDEX08 0xE20 // TX Swing Table Lane01-Index08
    #define CND003_PCIEEPHYCFG_FRP01_V0_08_TXPSR   (BIT29 + BIT30 + BIT31) // 011b/011b/x/x PMOS TX Slew Rate Control
    #define CND003_PCIEEPHYCFG_FRP01_V0_08_TXNSR   (BIT26 + BIT27 + BIT28) // 011b/011b/x/x NMOS TX Slew Rate Control
    #define CND003_PCIEEPHYCFG_FRP01_V0_08_TX_DUTY (BIT24 + BIT25)         // 00b/00b/x/x TX Clock Duty Control
    #define CND003_PCIEEPHYCFG_RSV01_0E20_22       (BIT22 + BIT23)         // 0/0/x/x Reserved
    #define CND003_PCIEEPHYCFG_FRP01_V0_08_TDNCIS  0x3F0000                // 111111b/111111b/x/x TX De-emphasis Set
    #define CND003_PCIEEPHYCFG_RSV01_0E20_13       (BIT13 + BIT14 + BIT15) // 0/0/x/x Reserved
    #define CND003_PCIEEPHYCFG_FRP01_V0_08_TDCIS   0x1F00                  // 11001b/11001b/x/x TX Bias Control Set
    #define CND003_PCIEEPHYCFG_RSV01_0E20_6        (BIT6 + BIT7)           // 0/0/x/x Reserved
    #define CND003_PCIEEPHYCFG_FRP01_V0_08_TDPCIS  0x3F                    // 000000b/000000b/x/x TX Preshoot Set
#define CND003_PCIEEPHYCFG_TX_SWING_TABLE_LANE01_INDEX09 0xE24 // TX Swing Table Lane01-Index09
    #define CND003_PCIEEPHYCFG_FRP01_V0_09_TXPSR   (BIT29 + BIT30 + BIT31) // 011b/011b/x/x PMOS TX Slew Rate Control
    #define CND003_PCIEEPHYCFG_FRP01_V0_09_TXNSR   (BIT26 + BIT27 + BIT28) // 011b/011b/x/x NMOS TX Slew Rate Control
    #define CND003_PCIEEPHYCFG_FRP01_V0_09_TX_DUTY (BIT24 + BIT25)         // 00b/00b/x/x TX Clock Duty Control
    #define CND003_PCIEEPHYCFG_RSV01_0E24_22       (BIT22 + BIT23)         // 0/0/x/x Reserved
    #define CND003_PCIEEPHYCFG_FRP01_V0_09_TDNCIS  0x3F0000                // 000000b/000000b/x/x TX De-emphasis Set
    #define CND003_PCIEEPHYCFG_RSV01_0E24_13       (BIT13 + BIT14 + BIT15) // 0/0/x/x Reserved
    #define CND003_PCIEEPHYCFG_FRP01_V0_09_TDCIS   0x1F00                  // 11111b/11111b/x/x TX Bias Control Set
    #define CND003_PCIEEPHYCFG_RSV01_0E24_6        (BIT6 + BIT7)           // 0/0/x/x Reserved
    #define CND003_PCIEEPHYCFG_FRP01_V0_09_TDPCIS  0x3F                    // 001001b/001001b/x/x TX Preshoot Set
#define CND003_PCIEEPHYCFG_TX_SWING_TABLE_LANE01_INDEX10 0xE28 // TX Swing Table Lane01-Index10
    #define CND003_PCIEEPHYCFG_FRP01_V0_10_TXPSR   (BIT29 + BIT30 + BIT31) // 011b/011b/x/x PMOS TX Slew Rate Control
    #define CND003_PCIEEPHYCFG_FRP01_V0_10_TXNSR   (BIT26 + BIT27 + BIT28) // 011b/011b/x/x NMOS TX Slew Rate Control
    #define CND003_PCIEEPHYCFG_FRP01_V0_10_TX_DUTY (BIT24 + BIT25)         // 00b/00b/x/x TX Clock Duty Control
    #define CND003_PCIEEPHYCFG_RSV01_0E28_22       (BIT22 + BIT23)         // 0/0/x/x Reserved
    #define CND003_PCIEEPHYCFG_FRP01_V0_10_TDNCIS  0x3F0000                // 001001b/001001b/x/x TX De-emphasis Set
    #define CND003_PCIEEPHYCFG_RSV01_0E28_13       (BIT13 + BIT14 + BIT15) // 0/0/x/x Reserved
    #define CND003_PCIEEPHYCFG_FRP01_V0_10_TDCIS   0x1F00                  // 11111b/11111b/x/x TX Bias Control Set
    #define CND003_PCIEEPHYCFG_RSV01_0E28_6        (BIT6 + BIT7)           // 0/0/x/x Reserved
    #define CND003_PCIEEPHYCFG_FRP01_V0_10_TDPCIS  0x3F                    // 001001b/001001b/x/x TX Preshoot Set
#define CND003_PCIEEPHYCFG_TX_SWING_TABLE_LANE01_INDEX11 0xE2C // TX Swing Table Lane01-Index11
    #define CND003_PCIEEPHYCFG_FRP01_V0_11_TXPSR   (BIT29 + BIT30 + BIT31) // 011b/011b/x/x PMOS TX Slew Rate Control
    #define CND003_PCIEEPHYCFG_FRP01_V0_11_TXNSR   (BIT26 + BIT27 + BIT28) // 011b/011b/x/x NMOS TX Slew Rate Control
    #define CND003_PCIEEPHYCFG_FRP01_V0_11_TX_DUTY (BIT24 + BIT25)         // 00b/00b/x/x TX Clock Duty Control
    #define CND003_PCIEEPHYCFG_RSV01_0E2C_22       (BIT22 + BIT23)         // 0/0/x/x Reserved
    #define CND003_PCIEEPHYCFG_FRP01_V0_11_TDNCIS  0x3F0000                // 010001b/010001b/x/x TX De-emphasis Set
    #define CND003_PCIEEPHYCFG_RSV01_0E2C_13       (BIT13 + BIT14 + BIT15) // 0/0/x/x Reserved
    #define CND003_PCIEEPHYCFG_FRP01_V0_11_TDCIS   0x1F00                  // 11110b/11110b/x/x TX Bias Control Set
    #define CND003_PCIEEPHYCFG_RSV01_0E2C_6        (BIT6 + BIT7)           // 0/0/x/x Reserved
    #define CND003_PCIEEPHYCFG_FRP01_V0_11_TDPCIS  0x3F                    // 001001b/001001b/x/x TX Preshoot Set
#define CND003_PCIEEPHYCFG_TX_SWING_TABLE_LANE01_INDEX12 0xE30 // TX Swing Table Lane01-Index12
    #define CND003_PCIEEPHYCFG_FRP01_V0_12_TXPSR   (BIT29 + BIT30 + BIT31) // 011b/011b/x/x PMOS TX Slew Rate Control
    #define CND003_PCIEEPHYCFG_FRP01_V0_12_TXNSR   (BIT26 + BIT27 + BIT28) // 011b/011b/x/x NMOS TX Slew Rate Control
    #define CND003_PCIEEPHYCFG_FRP01_V0_12_TX_DUTY (BIT24 + BIT25)         // 00b/00b/x/x TX Clock Duty Control
    #define CND003_PCIEEPHYCFG_RSV01_0E30_22       (BIT22 + BIT23)         // 0/0/x/x Reserved
    #define CND003_PCIEEPHYCFG_FRP01_V0_12_TDNCIS  0x3F0000                // 011010b/011010b/x/x TX De-emphasis Set
    #define CND003_PCIEEPHYCFG_RSV01_0E30_13       (BIT13 + BIT14 + BIT15) // 0/0/x/x Reserved
    #define CND003_PCIEEPHYCFG_FRP01_V0_12_TDCIS   0x1F00                  // 11101b/11101b/x/x TX Bias Control Set
    #define CND003_PCIEEPHYCFG_RSV01_0E30_6        (BIT6 + BIT7)           // 0/0/x/x Reserved
    #define CND003_PCIEEPHYCFG_FRP01_V0_12_TDPCIS  0x3F                    // 001001b/001001b/x/x TX Preshoot Set
#define CND003_PCIEEPHYCFG_TX_SWING_TABLE_LANE01_INDEX13 0xE34 // TX Swing Table Lane01-Index13
    #define CND003_PCIEEPHYCFG_FRP01_V0_13_TXPSR   (BIT29 + BIT30 + BIT31) // 011b/011b/x/x PMOS TX Slew Rate Control
    #define CND003_PCIEEPHYCFG_FRP01_V0_13_TXNSR   (BIT26 + BIT27 + BIT28) // 011b/011b/x/x NMOS TX Slew Rate Control
    #define CND003_PCIEEPHYCFG_FRP01_V0_13_TX_DUTY (BIT24 + BIT25)         // 00b/00b/x/x TX Clock Duty Control
    #define CND003_PCIEEPHYCFG_RSV01_0E34_22       (BIT22 + BIT23)         // 0/0/x/x Reserved
    #define CND003_PCIEEPHYCFG_FRP01_V0_13_TDNCIS  0x3F0000                // 100010b/100010b/x/x TX De-emphasis Set
    #define CND003_PCIEEPHYCFG_RSV01_0E34_13       (BIT13 + BIT14 + BIT15) // 0/0/x/x Reserved
    #define CND003_PCIEEPHYCFG_FRP01_V0_13_TDCIS   0x1F00                  // 11100b/11100b/x/x TX Bias Control Set
    #define CND003_PCIEEPHYCFG_RSV01_0E34_6        (BIT6 + BIT7)           // 0/0/x/x Reserved
    #define CND003_PCIEEPHYCFG_FRP01_V0_13_TDPCIS  0x3F                    // 001001b/001001b/x/x TX Preshoot Set
#define CND003_PCIEEPHYCFG_TX_SWING_TABLE_LANE01_INDEX14 0xE38 // TX Swing Table Lane01-Index14
    #define CND003_PCIEEPHYCFG_FRP01_V0_14_TXPSR   (BIT29 + BIT30 + BIT31) // 011b/011b/x/x PMOS TX Slew Rate Control
    #define CND003_PCIEEPHYCFG_FRP01_V0_14_TXNSR   (BIT26 + BIT27 + BIT28) // 011b/011b/x/x NMOS TX Slew Rate Control
    #define CND003_PCIEEPHYCFG_FRP01_V0_14_TX_DUTY (BIT24 + BIT25)         // 00b/00b/x/x TX Clock Duty Control
    #define CND003_PCIEEPHYCFG_RSV01_0E38_22       (BIT22 + BIT23)         // 0/0/x/x Reserved
    #define CND003_PCIEEPHYCFG_FRP01_V0_14_TDNCIS  0x3F0000                // 101010b/101010b/x/x TX De-emphasis Set
    #define CND003_PCIEEPHYCFG_RSV01_0E38_13       (BIT13 + BIT14 + BIT15) // 0/0/x/x Reserved
    #define CND003_PCIEEPHYCFG_FRP01_V0_14_TDCIS   0x1F00                  // 11011b/11011b/x/x TX Bias Control Set
    #define CND003_PCIEEPHYCFG_RSV01_0E38_6        (BIT6 + BIT7)           // 0/0/x/x Reserved
    #define CND003_PCIEEPHYCFG_FRP01_V0_14_TDPCIS  0x3F                    // 001001b/001001b/x/x TX Preshoot Set
#define CND003_PCIEEPHYCFG_TX_SWING_TABLE_LANE01_INDEX15 0xE3C // TX Swing Table Lane01-Index15
    #define CND003_PCIEEPHYCFG_FRP01_V0_15_TXPSR   (BIT29 + BIT30 + BIT31) // 011b/011b/x/x PMOS TX Slew Rate Control
    #define CND003_PCIEEPHYCFG_FRP01_V0_15_TXNSR   (BIT26 + BIT27 + BIT28) // 011b/011b/x/x NMOS TX Slew Rate Control
    #define CND003_PCIEEPHYCFG_FRP01_V0_15_TX_DUTY (BIT24 + BIT25)         // 00b/00b/x/x TX Clock Duty Control
    #define CND003_PCIEEPHYCFG_RSV01_0E3C_22       (BIT22 + BIT23)         // 0/0/x/x Reserved
    #define CND003_PCIEEPHYCFG_FRP01_V0_15_TDNCIS  0x3F0000                // 110010b/110010b/x/x TX De-emphasis Set
    #define CND003_PCIEEPHYCFG_RSV01_0E3C_13       (BIT13 + BIT14 + BIT15) // 0/0/x/x Reserved
    #define CND003_PCIEEPHYCFG_FRP01_V0_15_TDCIS   0x1F00                  // 11011b/11011b/x/x TX Bias Control Set
    #define CND003_PCIEEPHYCFG_RSV01_0E3C_6        (BIT6 + BIT7)           // 0/0/x/x Reserved
    #define CND003_PCIEEPHYCFG_FRP01_V0_15_TDPCIS  0x3F                    // 001001b/001001b/x/x TX Preshoot Set
#define CND003_PCIEEPHYCFG_TX_SWING_TABLE_LANE01_INDEX16 0xE40 // TX Swing Table Lane01-Index16
    #define CND003_PCIEEPHYCFG_FRP01_V0_16_TXPSR   (BIT29 + BIT30 + BIT31) // 011b/011b/x/x PMOS TX Slew Rate Control
    #define CND003_PCIEEPHYCFG_FRP01_V0_16_TXNSR   (BIT26 + BIT27 + BIT28) // 011b/011b/x/x NMOS TX Slew Rate Control
    #define CND003_PCIEEPHYCFG_FRP01_V0_16_TX_DUTY (BIT24 + BIT25)         // 00b/00b/x/x TX Clock Duty Control
    #define CND003_PCIEEPHYCFG_RSV01_0E40_22       (BIT22 + BIT23)         // 0/0/x/x Reserved
    #define CND003_PCIEEPHYCFG_FRP01_V0_16_TDNCIS  0x3F0000                // 111101b/111101b/x/x TX De-emphasis Set
    #define CND003_PCIEEPHYCFG_RSV01_0E40_13       (BIT13 + BIT14 + BIT15) // 0/0/x/x Reserved
    #define CND003_PCIEEPHYCFG_FRP01_V0_16_TDCIS   0x1F00                  // 11010b/11010b/x/x TX Bias Control Set
    #define CND003_PCIEEPHYCFG_RSV01_0E40_6        (BIT6 + BIT7)           // 0/0/x/x Reserved
    #define CND003_PCIEEPHYCFG_FRP01_V0_16_TDPCIS  0x3F                    // 001001b/001001b/x/x TX Preshoot Set
#define CND003_PCIEEPHYCFG_TX_SWING_TABLE_LANE01_INDEX17 0xE44 // TX Swing Table Lane01-Index17
    #define CND003_PCIEEPHYCFG_FRP01_V0_17_TXPSR   (BIT29 + BIT30 + BIT31) // 011b/011b/x/x PMOS TX Slew Rate Control
    #define CND003_PCIEEPHYCFG_FRP01_V0_17_TXNSR   (BIT26 + BIT27 + BIT28) // 011b/011b/x/x NMOS TX Slew Rate Control
    #define CND003_PCIEEPHYCFG_FRP01_V0_17_TX_DUTY (BIT24 + BIT25)         // 00b/00b/x/x TX Clock Duty Control
    #define CND003_PCIEEPHYCFG_RSV01_0E44_22       (BIT22 + BIT23)         // 0/0/x/x Reserved
    #define CND003_PCIEEPHYCFG_FRP01_V0_17_TDNCIS  0x3F0000                // 000000b/000000b/x/x TX De-emphasis Set
    #define CND003_PCIEEPHYCFG_RSV01_0E44_13       (BIT13 + BIT14 + BIT15) // 0/0/x/x Reserved
    #define CND003_PCIEEPHYCFG_FRP01_V0_17_TDCIS   0x1F00                  // 11111b/11111b/x/x TX Bias Control Set
    #define CND003_PCIEEPHYCFG_RSV01_0E44_6        (BIT6 + BIT7)           // 0/0/x/x Reserved
    #define CND003_PCIEEPHYCFG_FRP01_V0_17_TDPCIS  0x3F                    // 010001b/010001b/x/x TX Preshoot Set
#define CND003_PCIEEPHYCFG_TX_SWING_TABLE_LANE01_INDEX18 0xE48 // TX Swing Table Lane01-Index18
    #define CND003_PCIEEPHYCFG_FRP01_V0_18_TXPSR   (BIT29 + BIT30 + BIT31) // 011b/011b/x/x PMOS TX Slew Rate Control
    #define CND003_PCIEEPHYCFG_FRP01_V0_18_TXNSR   (BIT26 + BIT27 + BIT28) // 011b/011b/x/x NMOS TX Slew Rate Control
    #define CND003_PCIEEPHYCFG_FRP01_V0_18_TX_DUTY (BIT24 + BIT25)         // 00b/00b/x/x TX Clock Duty Control
    #define CND003_PCIEEPHYCFG_RSV01_0E48_22       (BIT22 + BIT23)         // 0/0/x/x Reserved
    #define CND003_PCIEEPHYCFG_FRP01_V0_18_TDNCIS  0x3F0000                // 001001b/001001b/x/x TX De-emphasis Set
    #define CND003_PCIEEPHYCFG_RSV01_0E48_13       (BIT13 + BIT14 + BIT15) // 0/0/x/x Reserved
    #define CND003_PCIEEPHYCFG_FRP01_V0_18_TDCIS   0x1F00                  // 11110b/11110b/x/x TX Bias Control Set
    #define CND003_PCIEEPHYCFG_RSV01_0E48_6        (BIT6 + BIT7)           // 0/0/x/x Reserved
    #define CND003_PCIEEPHYCFG_FRP01_V0_18_TDPCIS  0x3F                    // 010001b/010001b/x/x TX Preshoot Set
#define CND003_PCIEEPHYCFG_TX_SWING_TABLE_LANE01_INDEX19 0xE4C // TX Swing Table Lane01-Index19
    #define CND003_PCIEEPHYCFG_FRP01_V0_19_TXPSR   (BIT29 + BIT30 + BIT31) // 011b/011b/x/x PMOS TX Slew Rate Control
    #define CND003_PCIEEPHYCFG_FRP01_V0_19_TXNSR   (BIT26 + BIT27 + BIT28) // 011b/011b/x/x NMOS TX Slew Rate Control
    #define CND003_PCIEEPHYCFG_FRP01_V0_19_TX_DUTY (BIT24 + BIT25)         // 00b/00b/x/x TX Clock Duty Control
    #define CND003_PCIEEPHYCFG_RSV01_0E4C_22       (BIT22 + BIT23)         // 0/0/x/x Reserved
    #define CND003_PCIEEPHYCFG_FRP01_V0_19_TDNCIS  0x3F0000                // 010001b/010001b/x/x TX De-emphasis Set
    #define CND003_PCIEEPHYCFG_RSV01_0E4C_13       (BIT13 + BIT14 + BIT15) // 0/0/x/x Reserved
    #define CND003_PCIEEPHYCFG_FRP01_V0_19_TDCIS   0x1F00                  // 11101b/11101b/x/x TX Bias Control Set
    #define CND003_PCIEEPHYCFG_RSV01_0E4C_6        (BIT6 + BIT7)           // 0/0/x/x Reserved
    #define CND003_PCIEEPHYCFG_FRP01_V0_19_TDPCIS  0x3F                    // 010001b/010001b/x/x TX Preshoot Set
#define CND003_PCIEEPHYCFG_TX_SWING_TABLE_LANE01_INDEX20 0xE50 // TX Swing Table Lane01-Index20
    #define CND003_PCIEEPHYCFG_FRP01_V0_20_TXPSR   (BIT29 + BIT30 + BIT31) // 011b/011b/x/x PMOS TX Slew Rate Control
    #define CND003_PCIEEPHYCFG_FRP01_V0_20_TXNSR   (BIT26 + BIT27 + BIT28) // 011b/011b/x/x NMOS TX Slew Rate Control
    #define CND003_PCIEEPHYCFG_FRP01_V0_20_TX_DUTY (BIT24 + BIT25)         // 00b/00b/x/x TX Clock Duty Control
    #define CND003_PCIEEPHYCFG_RSV01_0E50_22       (BIT22 + BIT23)         // 0/0/x/x Reserved
    #define CND003_PCIEEPHYCFG_FRP01_V0_20_TDNCIS  0x3F0000                // 011000b/011000b/x/x TX De-emphasis Set
    #define CND003_PCIEEPHYCFG_RSV01_0E50_13       (BIT13 + BIT14 + BIT15) // 0/0/x/x Reserved
    #define CND003_PCIEEPHYCFG_FRP01_V0_20_TDCIS   0x1F00                  // 11100b/11100b/x/x TX Bias Control Set
    #define CND003_PCIEEPHYCFG_RSV01_0E50_6        (BIT6 + BIT7)           // 0/0/x/x Reserved
    #define CND003_PCIEEPHYCFG_FRP01_V0_20_TDPCIS  0x3F                    // 010001b/010001b/x/x TX Preshoot Set
#define CND003_PCIEEPHYCFG_TX_SWING_TABLE_LANE01_INDEX21 0xE54 // TX Swing Table Lane01-Index21
    #define CND003_PCIEEPHYCFG_FRP01_V0_21_TXPSR   (BIT29 + BIT30 + BIT31) // 011b/011b/x/x PMOS TX Slew Rate Control
    #define CND003_PCIEEPHYCFG_FRP01_V0_21_TXNSR   (BIT26 + BIT27 + BIT28) // 011b/011b/x/x NMOS TX Slew Rate Control
    #define CND003_PCIEEPHYCFG_FRP01_V0_21_TX_DUTY (BIT24 + BIT25)         // 00b/00b/x/x TX Clock Duty Control
    #define CND003_PCIEEPHYCFG_RSV01_0E54_22       (BIT22 + BIT23)         // 0/0/x/x Reserved
    #define CND003_PCIEEPHYCFG_FRP01_V0_21_TDNCIS  0x3F0000                // 100010b/100010b/x/x TX De-emphasis Set
    #define CND003_PCIEEPHYCFG_RSV01_0E54_13       (BIT13 + BIT14 + BIT15) // 0/0/x/x Reserved
    #define CND003_PCIEEPHYCFG_FRP01_V0_21_TDCIS   0x1F00                  // 11011b/11011b/x/x TX Bias Control Set
    #define CND003_PCIEEPHYCFG_RSV01_0E54_6        (BIT6 + BIT7)           // 0/0/x/x Reserved
    #define CND003_PCIEEPHYCFG_FRP01_V0_21_TDPCIS  0x3F                    // 010001b/010001b/x/x TX Preshoot Set
#define CND003_PCIEEPHYCFG_TX_SWING_TABLE_LANE01_INDEX22 0xE58 // TX Swing Table Lane01-Index22
    #define CND003_PCIEEPHYCFG_FRP01_V0_22_TXPSR   (BIT29 + BIT30 + BIT31) // 011b/011b/x/x PMOS TX Slew Rate Control
    #define CND003_PCIEEPHYCFG_FRP01_V0_22_TXNSR   (BIT26 + BIT27 + BIT28) // 011b/011b/x/x NMOS TX Slew Rate Control
    #define CND003_PCIEEPHYCFG_FRP01_V0_22_TX_DUTY (BIT24 + BIT25)         // 00b/00b/x/x TX Clock Duty Control
    #define CND003_PCIEEPHYCFG_RSV01_0E58_22       (BIT22 + BIT23)         // 0/0/x/x Reserved
    #define CND003_PCIEEPHYCFG_FRP01_V0_22_TDNCIS  0x3F0000                // 101100b/101100b/x/x TX De-emphasis Set
    #define CND003_PCIEEPHYCFG_RSV01_0E58_13       (BIT13 + BIT14 + BIT15) // 0/0/x/x Reserved
    #define CND003_PCIEEPHYCFG_FRP01_V0_22_TDCIS   0x1F00                  // 11011b/11011b/x/x TX Bias Control Set
    #define CND003_PCIEEPHYCFG_RSV01_0E58_6        (BIT6 + BIT7)           // 0/0/x/x Reserved
    #define CND003_PCIEEPHYCFG_FRP01_V0_22_TDPCIS  0x3F                    // 010001b/010001b/x/x TX Preshoot Set
#define CND003_PCIEEPHYCFG_TX_SWING_TABLE_LANE01_INDEX23 0xE5C // TX Swing Table Lane01-Index23
    #define CND003_PCIEEPHYCFG_FRP01_V0_23_TXPSR   (BIT29 + BIT30 + BIT31) // 011b/011b/x/x PMOS TX Slew Rate Control
    #define CND003_PCIEEPHYCFG_FRP01_V0_23_TXNSR   (BIT26 + BIT27 + BIT28) // 011b/011b/x/x NMOS TX Slew Rate Control
    #define CND003_PCIEEPHYCFG_FRP01_V0_23_TX_DUTY (BIT24 + BIT25)         // 00b/00b/x/x TX Clock Duty Control
    #define CND003_PCIEEPHYCFG_RSV01_0E5C_22       (BIT22 + BIT23)         // 0/0/x/x Reserved
    #define CND003_PCIEEPHYCFG_FRP01_V0_23_TDNCIS  0x3F0000                // 110010b/110010b/x/x TX De-emphasis Set
    #define CND003_PCIEEPHYCFG_RSV01_0E5C_13       (BIT13 + BIT14 + BIT15) // 0/0/x/x Reserved
    #define CND003_PCIEEPHYCFG_FRP01_V0_23_TDCIS   0x1F00                  // 11010b/11010b/x/x TX Bias Control Set
    #define CND003_PCIEEPHYCFG_RSV01_0E5C_6        (BIT6 + BIT7)           // 0/0/x/x Reserved
    #define CND003_PCIEEPHYCFG_FRP01_V0_23_TDPCIS  0x3F                    // 010001b/010001b/x/x TX Preshoot Set
#define CND003_PCIEEPHYCFG_TX_SWING_TABLE_LANE01_INDEX24 0xE60 // TX Swing Table Lane01-Index24
    #define CND003_PCIEEPHYCFG_FRP01_V0_24_TXPSR   (BIT29 + BIT30 + BIT31) // 011b/011b/x/x PMOS TX Slew Rate Control
    #define CND003_PCIEEPHYCFG_FRP01_V0_24_TXNSR   (BIT26 + BIT27 + BIT28) // 011b/011b/x/x NMOS TX Slew Rate Control
    #define CND003_PCIEEPHYCFG_FRP01_V0_24_TX_DUTY (BIT24 + BIT25)         // 00b/00b/x/x TX Clock Duty Control
    #define CND003_PCIEEPHYCFG_RSV01_0E60_22       (BIT22 + BIT23)         // 0/0/x/x Reserved
    #define CND003_PCIEEPHYCFG_FRP01_V0_24_TDNCIS  0x3F0000                // 000000b/000000b/x/x TX De-emphasis Set
    #define CND003_PCIEEPHYCFG_RSV01_0E60_13       (BIT13 + BIT14 + BIT15) // 0/0/x/x Reserved
    #define CND003_PCIEEPHYCFG_FRP01_V0_24_TDCIS   0x1F00                  // 11110b/11110b/x/x TX Bias Control Set
    #define CND003_PCIEEPHYCFG_RSV01_0E60_6        (BIT6 + BIT7)           // 0/0/x/x Reserved
    #define CND003_PCIEEPHYCFG_FRP01_V0_24_TDPCIS  0x3F                    // 011010b/011010b/x/x TX Preshoot Set
#define CND003_PCIEEPHYCFG_TX_SWING_TABLE_LANE01_INDEX25 0xE64 // TX Swing Table Lane01-Index25
    #define CND003_PCIEEPHYCFG_FRP01_V0_25_TXPSR   (BIT29 + BIT30 + BIT31) // 011b/011b/x/x PMOS TX Slew Rate Control
    #define CND003_PCIEEPHYCFG_FRP01_V0_25_TXNSR   (BIT26 + BIT27 + BIT28) // 011b/011b/x/x NMOS TX Slew Rate Control
    #define CND003_PCIEEPHYCFG_FRP01_V0_25_TX_DUTY (BIT24 + BIT25)         // 00b/00b/x/x TX Clock Duty Control
    #define CND003_PCIEEPHYCFG_RSV01_0E64_22       (BIT22 + BIT23)         // 0/0/x/x Reserved
    #define CND003_PCIEEPHYCFG_FRP01_V0_25_TDNCIS  0x3F0000                // 001001b/001001b/x/x TX De-emphasis Set
    #define CND003_PCIEEPHYCFG_RSV01_0E64_13       (BIT13 + BIT14 + BIT15) // 0/0/x/x Reserved
    #define CND003_PCIEEPHYCFG_FRP01_V0_25_TDCIS   0x1F00                  // 11101b/11101b/x/x TX Bias Control Set
    #define CND003_PCIEEPHYCFG_RSV01_0E64_6        (BIT6 + BIT7)           // 0/0/x/x Reserved
    #define CND003_PCIEEPHYCFG_FRP01_V0_25_TDPCIS  0x3F                    // 011010b/011010b/x/x TX Preshoot Set
#define CND003_PCIEEPHYCFG_TX_SWING_TABLE_LANE01_INDEX26 0xE68 // TX Swing Table Lane01-Index26
    #define CND003_PCIEEPHYCFG_FRP01_V0_26_TXPSR   (BIT29 + BIT30 + BIT31) // 011b/011b/x/x PMOS TX Slew Rate Control
    #define CND003_PCIEEPHYCFG_FRP01_V0_26_TXNSR   (BIT26 + BIT27 + BIT28) // 011b/011b/x/x NMOS TX Slew Rate Control
    #define CND003_PCIEEPHYCFG_FRP01_V0_26_TX_DUTY (BIT24 + BIT25)         // 00b/00b/x/x TX Clock Duty Control
    #define CND003_PCIEEPHYCFG_RSV01_0E68_22       (BIT22 + BIT23)         // 0/0/x/x Reserved
    #define CND003_PCIEEPHYCFG_FRP01_V0_26_TDNCIS  0x3F0000                // 010001b/010001b/x/x TX De-emphasis Set
    #define CND003_PCIEEPHYCFG_RSV01_0E68_13       (BIT13 + BIT14 + BIT15) // 0/0/x/x Reserved
    #define CND003_PCIEEPHYCFG_FRP01_V0_26_TDCIS   0x1F00                  // 11100b/11100b/x/x TX Bias Control Set
    #define CND003_PCIEEPHYCFG_RSV01_0E68_6        (BIT6 + BIT7)           // 0/0/x/x Reserved
    #define CND003_PCIEEPHYCFG_FRP01_V0_26_TDPCIS  0x3F                    // 011010b/011010b/x/x TX Preshoot Set
#define CND003_PCIEEPHYCFG_TX_SWING_TABLE_LANE01_INDEX27 0xE6C // TX Swing Table Lane01-Index27
    #define CND003_PCIEEPHYCFG_FRP01_V0_27_TXPSR   (BIT29 + BIT30 + BIT31) // 011b/011b/x/x PMOS TX Slew Rate Control
    #define CND003_PCIEEPHYCFG_FRP01_V0_27_TXNSR   (BIT26 + BIT27 + BIT28) // 011b/011b/x/x NMOS TX Slew Rate Control
    #define CND003_PCIEEPHYCFG_FRP01_V0_27_TX_DUTY (BIT24 + BIT25)         // 00b/00b/x/x TX Clock Duty Control
    #define CND003_PCIEEPHYCFG_RSV01_0E6C_22       (BIT22 + BIT23)         // 0/0/x/x Reserved
    #define CND003_PCIEEPHYCFG_FRP01_V0_27_TDNCIS  0x3F0000                // 011010b/011010b/x/x TX De-emphasis Set
    #define CND003_PCIEEPHYCFG_RSV01_0E6C_13       (BIT13 + BIT14 + BIT15) // 0/0/x/x Reserved
    #define CND003_PCIEEPHYCFG_FRP01_V0_27_TDCIS   0x1F00                  // 11011b/11011b/x/x TX Bias Control Set
    #define CND003_PCIEEPHYCFG_RSV01_0E6C_6        (BIT6 + BIT7)           // 0/0/x/x Reserved
    #define CND003_PCIEEPHYCFG_FRP01_V0_27_TDPCIS  0x3F                    // 011010b/011010b/x/x TX Preshoot Set
#define CND003_PCIEEPHYCFG_TX_SWING_TABLE_LANE01_INDEX28 0xE70 // TX Swing Table Lane01-Index28
    #define CND003_PCIEEPHYCFG_FRP01_V0_28_TXPSR   (BIT29 + BIT30 + BIT31) // 011b/011b/x/x PMOS TX Slew Rate Control
    #define CND003_PCIEEPHYCFG_FRP01_V0_28_TXNSR   (BIT26 + BIT27 + BIT28) // 011b/011b/x/x NMOS TX Slew Rate Control
    #define CND003_PCIEEPHYCFG_FRP01_V0_28_TX_DUTY (BIT24 + BIT25)         // 00b/00b/x/x TX Clock Duty Control
    #define CND003_PCIEEPHYCFG_RSV01_0E70_22       (BIT22 + BIT23)         // 0/0/x/x Reserved
    #define CND003_PCIEEPHYCFG_FRP01_V0_28_TDNCIS  0x3F0000                // 100010b/100010b/x/x TX De-emphasis Set
    #define CND003_PCIEEPHYCFG_RSV01_0E70_13       (BIT13 + BIT14 + BIT15) // 0/0/x/x Reserved
    #define CND003_PCIEEPHYCFG_FRP01_V0_28_TDCIS   0x1F00                  // 11011b/11011b/x/x TX Bias Control Set
    #define CND003_PCIEEPHYCFG_RSV01_0E70_6        (BIT6 + BIT7)           // 0/0/x/x Reserved
    #define CND003_PCIEEPHYCFG_FRP01_V0_28_TDPCIS  0x3F                    // 011010b/011010b/x/x TX Preshoot Set
#define CND003_PCIEEPHYCFG_TX_SWING_TABLE_LANE01_INDEX29 0xE74 // TX Swing Table Lane01-Index29
    #define CND003_PCIEEPHYCFG_FRP01_V0_29_TXPSR   (BIT29 + BIT30 + BIT31) // 011b/011b/x/x PMOS TX Slew Rate Control
    #define CND003_PCIEEPHYCFG_FRP01_V0_29_TXNSR   (BIT26 + BIT27 + BIT28) // 011b/011b/x/x NMOS TX Slew Rate Control
    #define CND003_PCIEEPHYCFG_FRP01_V0_29_TX_DUTY (BIT24 + BIT25)         // 00b/00b/x/x TX Clock Duty Control
    #define CND003_PCIEEPHYCFG_RSV01_0E74_22       (BIT22 + BIT23)         // 0/0/x/x Reserved
    #define CND003_PCIEEPHYCFG_FRP01_V0_29_TDNCIS  0x3F0000                // 101010b/101010b/x/x TX De-emphasis Set
    #define CND003_PCIEEPHYCFG_RSV01_0E74_13       (BIT13 + BIT14 + BIT15) // 0/0/x/x Reserved
    #define CND003_PCIEEPHYCFG_FRP01_V0_29_TDCIS   0x1F00                  // 11010b/11010b/x/x TX Bias Control Set
    #define CND003_PCIEEPHYCFG_RSV01_0E74_6        (BIT6 + BIT7)           // 0/0/x/x Reserved
    #define CND003_PCIEEPHYCFG_FRP01_V0_29_TDPCIS  0x3F                    // 011010b/011010b/x/x TX Preshoot Set
#define CND003_PCIEEPHYCFG_TX_SWING_TABLE_LANE01_INDEX30 0xE78 // TX Swing Table Lane01-Index30
    #define CND003_PCIEEPHYCFG_FRP01_V0_30_TXPSR   (BIT29 + BIT30 + BIT31) // 011b/011b/x/x PMOS TX Slew Rate Control
    #define CND003_PCIEEPHYCFG_FRP01_V0_30_TXNSR   (BIT26 + BIT27 + BIT28) // 011b/011b/x/x NMOS TX Slew Rate Control
    #define CND003_PCIEEPHYCFG_FRP01_V0_30_TX_DUTY (BIT24 + BIT25)         // 00b/00b/x/x TX Clock Duty Control
    #define CND003_PCIEEPHYCFG_RSV01_0E78_22       (BIT22 + BIT23)         // 0/0/x/x Reserved
    #define CND003_PCIEEPHYCFG_FRP01_V0_30_TDNCIS  0x3F0000                // 000000b/000000b/x/x TX De-emphasis Set
    #define CND003_PCIEEPHYCFG_RSV01_0E78_13       (BIT13 + BIT14 + BIT15) // 0/0/x/x Reserved
    #define CND003_PCIEEPHYCFG_FRP01_V0_30_TDCIS   0x1F00                  // 11101b/11101b/x/x TX Bias Control Set
    #define CND003_PCIEEPHYCFG_RSV01_0E78_6        (BIT6 + BIT7)           // 0/0/x/x Reserved
    #define CND003_PCIEEPHYCFG_FRP01_V0_30_TDPCIS  0x3F                    // 100010b/100010b/x/x TX Preshoot Set
#define CND003_PCIEEPHYCFG_TX_SWING_TABLE_LANE01_INDEX31 0xE7C // TX Swing Table Lane01-Index31
    #define CND003_PCIEEPHYCFG_FRP01_V0_31_TXPSR   (BIT29 + BIT30 + BIT31) // 011b/011b/x/x PMOS TX Slew Rate Control
    #define CND003_PCIEEPHYCFG_FRP01_V0_31_TXNSR   (BIT26 + BIT27 + BIT28) // 011b/011b/x/x NMOS TX Slew Rate Control
    #define CND003_PCIEEPHYCFG_FRP01_V0_31_TX_DUTY (BIT24 + BIT25)         // 00b/00b/x/x TX Clock Duty Control
    #define CND003_PCIEEPHYCFG_RSV01_0E7C_22       (BIT22 + BIT23)         // 0/0/x/x Reserved
    #define CND003_PCIEEPHYCFG_FRP01_V0_31_TDNCIS  0x3F0000                // 001001b/001001b/x/x TX De-emphasis Set
    #define CND003_PCIEEPHYCFG_RSV01_0E7C_13       (BIT13 + BIT14 + BIT15) // 0/0/x/x Reserved
    #define CND003_PCIEEPHYCFG_FRP01_V0_31_TDCIS   0x1F00                  // 11100b/11100b/x/x TX Bias Control Set
    #define CND003_PCIEEPHYCFG_RSV01_0E7C_6        (BIT6 + BIT7)           // 0/0/x/x Reserved
    #define CND003_PCIEEPHYCFG_FRP01_V0_31_TDPCIS  0x3F                    // 100010b/100010b/x/x TX Preshoot Set
#define CND003_PCIEEPHYCFG_TX_SWING_TABLE_LANE01_INDEX32 0xE80 // TX Swing Table Lane01-Index32
    #define CND003_PCIEEPHYCFG_FRP01_V0_32_TXPSR   (BIT29 + BIT30 + BIT31) // 011b/011b/x/x PMOS TX Slew Rate Control
    #define CND003_PCIEEPHYCFG_FRP01_V0_32_TXNSR   (BIT26 + BIT27 + BIT28) // 011b/011b/x/x NMOS TX Slew Rate Control
    #define CND003_PCIEEPHYCFG_FRP01_V0_32_TX_DUTY (BIT24 + BIT25)         // 00b/00b/x/x TX Clock Duty Control
    #define CND003_PCIEEPHYCFG_RSV01_0E80_22       (BIT22 + BIT23)         // 0/0/x/x Reserved
    #define CND003_PCIEEPHYCFG_FRP01_V0_32_TDNCIS  0x3F0000                // 010000b/010000b/x/x TX De-emphasis Set
    #define CND003_PCIEEPHYCFG_RSV01_0E80_13       (BIT13 + BIT14 + BIT15) // 0/0/x/x Reserved
    #define CND003_PCIEEPHYCFG_FRP01_V0_32_TDCIS   0x1F00                  // 11011b/11011b/x/x TX Bias Control Set
    #define CND003_PCIEEPHYCFG_RSV01_0E80_6        (BIT6 + BIT7)           // 0/0/x/x Reserved
    #define CND003_PCIEEPHYCFG_FRP01_V0_32_TDPCIS  0x3F                    // 100010b/100010b/x/x TX Preshoot Set
#define CND003_PCIEEPHYCFG_TX_SWING_TABLE_LANE01_INDEX33 0xE84 // TX Swing Table Lane01-Index33
    #define CND003_PCIEEPHYCFG_FRP01_V0_33_TXPSR   (BIT29 + BIT30 + BIT31) // 011b/011b/x/x PMOS TX Slew Rate Control
    #define CND003_PCIEEPHYCFG_FRP01_V0_33_TXNSR   (BIT26 + BIT27 + BIT28) // 011b/011b/x/x NMOS TX Slew Rate Control
    #define CND003_PCIEEPHYCFG_FRP01_V0_33_TX_DUTY (BIT24 + BIT25)         // 00b/00b/x/x TX Clock Duty Control
    #define CND003_PCIEEPHYCFG_RSV01_0E84_22       (BIT22 + BIT23)         // 0/0/x/x Reserved
    #define CND003_PCIEEPHYCFG_FRP01_V0_33_TDNCIS  0x3F0000                // 011010b/011010b/x/x TX De-emphasis Set
    #define CND003_PCIEEPHYCFG_RSV01_0E84_13       (BIT13 + BIT14 + BIT15) // 0/0/x/x Reserved
    #define CND003_PCIEEPHYCFG_FRP01_V0_33_TDCIS   0x1F00                  // 11011b/11011b/x/x TX Bias Control Set
    #define CND003_PCIEEPHYCFG_RSV01_0E84_6        (BIT6 + BIT7)           // 0/0/x/x Reserved
    #define CND003_PCIEEPHYCFG_FRP01_V0_33_TDPCIS  0x3F                    // 100010b/100010b/x/x TX Preshoot Set
#define CND003_PCIEEPHYCFG_TX_SWING_TABLE_LANE01_INDEX34 0xE88 // TX Swing Table Lane01-Index34
    #define CND003_PCIEEPHYCFG_FRP01_V0_34_TXPSR   (BIT29 + BIT30 + BIT31) // 011b/011b/x/x PMOS TX Slew Rate Control
    #define CND003_PCIEEPHYCFG_FRP01_V0_34_TXNSR   (BIT26 + BIT27 + BIT28) // 011b/011b/x/x NMOS TX Slew Rate Control
    #define CND003_PCIEEPHYCFG_FRP01_V0_34_TX_DUTY (BIT24 + BIT25)         // 00b/00b/x/x TX Clock Duty Control
    #define CND003_PCIEEPHYCFG_RSV01_0E88_22       (BIT22 + BIT23)         // 0/0/x/x Reserved
    #define CND003_PCIEEPHYCFG_FRP01_V0_34_TDNCIS  0x3F0000                // 100010b/100010b/x/x TX De-emphasis Set
    #define CND003_PCIEEPHYCFG_RSV01_0E88_13       (BIT13 + BIT14 + BIT15) // 0/0/x/x Reserved
    #define CND003_PCIEEPHYCFG_FRP01_V0_34_TDCIS   0x1F00                  // 11010b/11010b/x/x TX Bias Control Set
    #define CND003_PCIEEPHYCFG_RSV01_0E88_6        (BIT6 + BIT7)           // 0/0/x/x Reserved
    #define CND003_PCIEEPHYCFG_FRP01_V0_34_TDPCIS  0x3F                    // 100010b/100010b/x/x TX Preshoot Set
#define CND003_PCIEEPHYCFG_TX_SWING_TABLE_LANE01_INDEX35 0xE8C // TX Swing Table Lane01-Index35
    #define CND003_PCIEEPHYCFG_FRP01_V0_35_TXPSR   (BIT29 + BIT30 + BIT31) // 011b/011b/x/x PMOS TX Slew Rate Control
    #define CND003_PCIEEPHYCFG_FRP01_V0_35_TXNSR   (BIT26 + BIT27 + BIT28) // 011b/011b/x/x NMOS TX Slew Rate Control
    #define CND003_PCIEEPHYCFG_FRP01_V0_35_TX_DUTY (BIT24 + BIT25)         // 00b/00b/x/x TX Clock Duty Control
    #define CND003_PCIEEPHYCFG_RSV01_0E8C_22       (BIT22 + BIT23)         // 0/0/x/x Reserved
    #define CND003_PCIEEPHYCFG_FRP01_V0_35_TDNCIS  0x3F0000                // 000000b/000000b/x/x TX De-emphasis Set
    #define CND003_PCIEEPHYCFG_RSV01_0E8C_13       (BIT13 + BIT14 + BIT15) // 0/0/x/x Reserved
    #define CND003_PCIEEPHYCFG_FRP01_V0_35_TDCIS   0x1F00                  // 11100b/11100b/x/x TX Bias Control Set
    #define CND003_PCIEEPHYCFG_RSV01_0E8C_6        (BIT6 + BIT7)           // 0/0/x/x Reserved
    #define CND003_PCIEEPHYCFG_FRP01_V0_35_TDPCIS  0x3F                    // 101010b/101010b/x/x TX Preshoot Set
#define CND003_PCIEEPHYCFG_TX_SWING_TABLE_LANE01_INDEX36 0xE90 // TX Swing Table Lane01-Index36
    #define CND003_PCIEEPHYCFG_FRP01_V0_36_TXPSR   (BIT29 + BIT30 + BIT31) // 011b/011b/x/x PMOS TX Slew Rate Control
    #define CND003_PCIEEPHYCFG_FRP01_V0_36_TXNSR   (BIT26 + BIT27 + BIT28) // 011b/011b/x/x NMOS TX Slew Rate Control
    #define CND003_PCIEEPHYCFG_FRP01_V0_36_TX_DUTY (BIT24 + BIT25)         // 00b/00b/x/x TX Clock Duty Control
    #define CND003_PCIEEPHYCFG_RSV01_0E90_22       (BIT22 + BIT23)         // 0/0/x/x Reserved
    #define CND003_PCIEEPHYCFG_FRP01_V0_36_TDNCIS  0x3F0000                // 001000b/001000b/x/x TX De-emphasis Set
    #define CND003_PCIEEPHYCFG_RSV01_0E90_13       (BIT13 + BIT14 + BIT15) // 0/0/x/x Reserved
    #define CND003_PCIEEPHYCFG_FRP01_V0_36_TDCIS   0x1F00                  // 11011b/11011b/x/x TX Bias Control Set
    #define CND003_PCIEEPHYCFG_RSV01_0E90_6        (BIT6 + BIT7)           // 0/0/x/x Reserved
    #define CND003_PCIEEPHYCFG_FRP01_V0_36_TDPCIS  0x3F                    // 101010b/101010b/x/x TX Preshoot Set
#define CND003_PCIEEPHYCFG_TX_SWING_TABLE_LANE01_INDEX37 0xE94 // TX Swing Table Lane01-Index37
    #define CND003_PCIEEPHYCFG_FRP01_V0_37_TXPSR   (BIT29 + BIT30 + BIT31) // 011b/011b/x/x PMOS TX Slew Rate Control
    #define CND003_PCIEEPHYCFG_FRP01_V0_37_TXNSR   (BIT26 + BIT27 + BIT28) // 011b/011b/x/x NMOS TX Slew Rate Control
    #define CND003_PCIEEPHYCFG_FRP01_V0_37_TX_DUTY (BIT24 + BIT25)         // 00b/00b/x/x TX Clock Duty Control
    #define CND003_PCIEEPHYCFG_RSV01_0E94_22       (BIT22 + BIT23)         // 0/0/x/x Reserved
    #define CND003_PCIEEPHYCFG_FRP01_V0_37_TDNCIS  0x3F0000                // 010001b/010001b/x/x TX De-emphasis Set
    #define CND003_PCIEEPHYCFG_RSV01_0E94_13       (BIT13 + BIT14 + BIT15) // 0/0/x/x Reserved
    #define CND003_PCIEEPHYCFG_FRP01_V0_37_TDCIS   0x1F00                  // 11011b/11011b/x/x TX Bias Control Set
    #define CND003_PCIEEPHYCFG_RSV01_0E94_6        (BIT6 + BIT7)           // 0/0/x/x Reserved
    #define CND003_PCIEEPHYCFG_FRP01_V0_37_TDPCIS  0x3F                    // 101010b/101010b/x/x TX Preshoot Set
#define CND003_PCIEEPHYCFG_TX_SWING_TABLE_LANE01_INDEX38 0xE98 // TX Swing Table Lane01-Index38
    #define CND003_PCIEEPHYCFG_FRP01_V0_38_TXPSR   (BIT29 + BIT30 + BIT31) // 011b/011b/x/x PMOS TX Slew Rate Control
    #define CND003_PCIEEPHYCFG_FRP01_V0_38_TXNSR   (BIT26 + BIT27 + BIT28) // 011b/011b/x/x NMOS TX Slew Rate Control
    #define CND003_PCIEEPHYCFG_FRP01_V0_38_TX_DUTY (BIT24 + BIT25)         // 00b/00b/x/x TX Clock Duty Control
    #define CND003_PCIEEPHYCFG_RSV01_0E98_22       (BIT22 + BIT23)         // 0/0/x/x Reserved
    #define CND003_PCIEEPHYCFG_FRP01_V0_38_TDNCIS  0x3F0000                // 011010b/011010b/x/x TX De-emphasis Set
    #define CND003_PCIEEPHYCFG_RSV01_0E98_13       (BIT13 + BIT14 + BIT15) // 0/0/x/x Reserved
    #define CND003_PCIEEPHYCFG_FRP01_V0_38_TDCIS   0x1F00                  // 11010b/11010b/x/x TX Bias Control Set
    #define CND003_PCIEEPHYCFG_RSV01_0E98_6        (BIT6 + BIT7)           // 0/0/x/x Reserved
    #define CND003_PCIEEPHYCFG_FRP01_V0_38_TDPCIS  0x3F                    // 101010b/101010b/x/x TX Preshoot Set
#define CND003_PCIEEPHYCFG_TX_SWING_TABLE_LANE01_INDEX39 0xE9C // TX Swing Table Lane01-Index39
    #define CND003_PCIEEPHYCFG_FRP01_V0_39_TXPSR   (BIT29 + BIT30 + BIT31) // 011b/011b/x/x PMOS TX Slew Rate Control
    #define CND003_PCIEEPHYCFG_FRP01_V0_39_TXNSR   (BIT26 + BIT27 + BIT28) // 011b/011b/x/x NMOS TX Slew Rate Control
    #define CND003_PCIEEPHYCFG_FRP01_V0_39_TX_DUTY (BIT24 + BIT25)         // 00b/00b/x/x TX Clock Duty Control
    #define CND003_PCIEEPHYCFG_RSV01_0E9C_22       (BIT22 + BIT23)         // 0/0/x/x Reserved
    #define CND003_PCIEEPHYCFG_FRP01_V0_39_TDNCIS  0x3F0000                // 000000b/000000b/x/x TX De-emphasis Set
    #define CND003_PCIEEPHYCFG_RSV01_0E9C_13       (BIT13 + BIT14 + BIT15) // 0/0/x/x Reserved
    #define CND003_PCIEEPHYCFG_FRP01_V0_39_TDCIS   0x1F00                  // 11011b/11011b/x/x TX Bias Control Set
    #define CND003_PCIEEPHYCFG_RSV01_0E9C_6        (BIT6 + BIT7)           // 0/0/x/x Reserved
    #define CND003_PCIEEPHYCFG_FRP01_V0_39_TDPCIS  0x3F                    // 110010b/110010b/x/x TX Preshoot Set
#define CND003_PCIEEPHYCFG_TX_SWING_TABLE_LANE01_40 0xEA0 // TX Swing Table Lane01-40
    #define CND003_PCIEEPHYCFG_FRP01_V0_40_TXPSR   (BIT29 + BIT30 + BIT31) // 011b/011b/x/x PMOS TX Slew Rate Control
    #define CND003_PCIEEPHYCFG_FRP01_V0_40_TXNSR   (BIT26 + BIT27 + BIT28) // 011b/011b/x/x NMOS TX Slew Rate Control
    #define CND003_PCIEEPHYCFG_FRP01_V0_40_TX_DUTY (BIT24 + BIT25)         // 00b/00b/x/x TX Clock Duty Control
    #define CND003_PCIEEPHYCFG_RSV01_0EA0_22       (BIT22 + BIT23)         // 0/0/x/x Reserved
    #define CND003_PCIEEPHYCFG_FRP01_V0_40_TDNCIS  0x3F0000                // 001001b/001001b/x/x TX De-emphasis Set
    #define CND003_PCIEEPHYCFG_RSV01_0EA0_13       (BIT13 + BIT14 + BIT15) // 0/0/x/x Reserved
    #define CND003_PCIEEPHYCFG_FRP01_V0_40_TDCIS   0x1F00                  // 11011b/11011b/x/x TX Bias Control Set
    #define CND003_PCIEEPHYCFG_RSV01_0EA0_6        (BIT6 + BIT7)           // 0/0/x/x Reserved
    #define CND003_PCIEEPHYCFG_FRP01_V0_40_TDPCIS  0x3F                    // 110010b/110010b/x/x TX Preshoot Set
#define CND003_PCIEEPHYCFG_TX_SWING_TABLE_LANE01_41 0xEA4 // TX Swing Table Lane01-41
    #define CND003_PCIEEPHYCFG_FRP01_V0_41_TXPSR   (BIT29 + BIT30 + BIT31) // 011b/011b/x/x PMOS TX Slew Rate Control
    #define CND003_PCIEEPHYCFG_FRP01_V0_41_TXNSR   (BIT26 + BIT27 + BIT28) // 011b/011b/x/x NMOS TX Slew Rate Control
    #define CND003_PCIEEPHYCFG_FRP01_V0_41_TX_DUTY (BIT24 + BIT25)         // 00b/00b/x/x TX Clock Duty Control
    #define CND003_PCIEEPHYCFG_RSV01_0EA4_22       (BIT22 + BIT23)         // 0/0/x/x Reserved
    #define CND003_PCIEEPHYCFG_FRP01_V0_41_TDNCIS  0x3F0000                // 010001b/010001b/x/x TX De-emphasis Set
    #define CND003_PCIEEPHYCFG_RSV01_0EA4_13       (BIT13 + BIT14 + BIT15) // 0/0/x/x Reserved
    #define CND003_PCIEEPHYCFG_FRP01_V0_41_TDCIS   0x1F00                  // 11010b/11010b/x/x TX Bias Control Set
    #define CND003_PCIEEPHYCFG_RSV01_0EA4_6        (BIT6 + BIT7)           // 0/0/x/x Reserved
    #define CND003_PCIEEPHYCFG_FRP01_V0_41_TDPCIS  0x3F                    // 110010b/110010b/x/x TX Preshoot Set
#define CND003_PCIEEPHYCFG_TX_SWING_TABLE_LANE02_INDEX00 0xF00 // TX Swing Table Lane02-Index00
    #define CND003_PCIEEPHYCFG_FRP02_V0_00_TXPSR   (BIT29 + BIT30 + BIT31) // 011b/011b/x/x PMOS TX Slew Rate Control
    #define CND003_PCIEEPHYCFG_FRP02_V0_00_TXNSR   (BIT26 + BIT27 + BIT28) // 011b/011b/x/x NMOS TX Slew Rate Control
    #define CND003_PCIEEPHYCFG_FRP02_V0_00_TX_DUTY (BIT24 + BIT25)         // 00b/00b/x/x TX Clock Duty Control
    #define CND003_PCIEEPHYCFG_RSV02_0F00_22       (BIT22 + BIT23)         // 0/0/x/x Reserved
    #define CND003_PCIEEPHYCFG_FRP02_V0_00_TDNCIS  0x3F0000                // 000000b/000000b/x/x TX De-emphasis Set
    #define CND003_PCIEEPHYCFG_RSV02_0F00_13       (BIT13 + BIT14 + BIT15) // 0/0/x/x Reserved
    #define CND003_PCIEEPHYCFG_FRP02_V0_00_TDCIS   0x1F00                  // 10100b/10100b/x/x TX Bias Control Set
    #define CND003_PCIEEPHYCFG_RSV02_0F00_6        (BIT6 + BIT7)           // 0/0/x/x Reserved
    #define CND003_PCIEEPHYCFG_FRP02_V0_00_TDPCIS  0x3F                    // 000000b/000000b/x/x TX Preshoot Set
#define CND003_PCIEEPHYCFG_TX_SWING_TABLE_LANE02_INDEX01 0xF04 // TX Swing Table Lane02-Index01
    #define CND003_PCIEEPHYCFG_FRP02_V0_01_TXPSR   (BIT29 + BIT30 + BIT31) // 011b/011b/x/x PMOS TX Slew Rate Control
    #define CND003_PCIEEPHYCFG_FRP02_V0_01_TXNSR   (BIT26 + BIT27 + BIT28) // 011b/011b/x/x NMOS TX Slew Rate Control
    #define CND003_PCIEEPHYCFG_FRP02_V0_01_TX_DUTY (BIT24 + BIT25)         // 00b/00b/x/x TX Clock Duty Control
    #define CND003_PCIEEPHYCFG_RSV02_0F04_22       (BIT22 + BIT23)         // 0/0/x/x Reserved
    #define CND003_PCIEEPHYCFG_FRP02_V0_01_TDNCIS  0x3F0000                // 001001b/001001b/x/x TX De-emphasis Set
    #define CND003_PCIEEPHYCFG_RSV02_0F04_13       (BIT13 + BIT14 + BIT15) // 0/0/x/x Reserved
    #define CND003_PCIEEPHYCFG_FRP02_V0_01_TDCIS   0x1F00                  // 11111b/11111b/x/x TX Bias Control Set
    #define CND003_PCIEEPHYCFG_RSV02_0F04_6        (BIT6 + BIT7)           // 0/0/x/x Reserved
    #define CND003_PCIEEPHYCFG_FRP02_V0_01_TDPCIS  0x3F                    // 000000b/000000b/x/x TX Preshoot Set
#define CND003_PCIEEPHYCFG_TX_SWING_TABLE_LANE02_INDEX02 0xF08 // TX Swing Table Lane02-Index02
    #define CND003_PCIEEPHYCFG_FRP02_V0_02_TXPSR   (BIT29 + BIT30 + BIT31) // 011b/011b/x/x PMOS TX Slew Rate Control
    #define CND003_PCIEEPHYCFG_FRP02_V0_02_TXNSR   (BIT26 + BIT27 + BIT28) // 011b/011b/x/x NMOS TX Slew Rate Control
    #define CND003_PCIEEPHYCFG_FRP02_V0_02_TX_DUTY (BIT24 + BIT25)         // 00b/00b/x/x TX Clock Duty Control
    #define CND003_PCIEEPHYCFG_RSV02_0F08_22       (BIT22 + BIT23)         // 0/0/x/x Reserved
    #define CND003_PCIEEPHYCFG_FRP02_V0_02_TDNCIS  0x3F0000                // 010010b/010010b/x/x TX De-emphasis Set
    #define CND003_PCIEEPHYCFG_RSV02_0F08_13       (BIT13 + BIT14 + BIT15) // 0/0/x/x Reserved
    #define CND003_PCIEEPHYCFG_FRP02_V0_02_TDCIS   0x1F00                  // 11111b/11111b/x/x TX Bias Control Set
    #define CND003_PCIEEPHYCFG_RSV02_0F08_6        (BIT6 + BIT7)           // 0/0/x/x Reserved
    #define CND003_PCIEEPHYCFG_FRP02_V0_02_TDPCIS  0x3F                    // 000000b/000000b/x/x TX Preshoot Set
#define CND003_PCIEEPHYCFG_TX_SWING_TABLE_LANE02_INDEX03 0xF0C // TX Swing Table Lane02-Index03
    #define CND003_PCIEEPHYCFG_FRP02_V0_03_TXPSR   (BIT29 + BIT30 + BIT31) // 011b/011b/x/x PMOS TX Slew Rate Control
    #define CND003_PCIEEPHYCFG_FRP02_V0_03_TXNSR   (BIT26 + BIT27 + BIT28) // 011b/011b/x/x NMOS TX Slew Rate Control
    #define CND003_PCIEEPHYCFG_FRP02_V0_03_TX_DUTY (BIT24 + BIT25)         // 00b/00b/x/x TX Clock Duty Control
    #define CND003_PCIEEPHYCFG_RSV02_0F0C_22       (BIT22 + BIT23)         // 0/0/x/x Reserved
    #define CND003_PCIEEPHYCFG_FRP02_V0_03_TDNCIS  0x3F0000                // 011010b/011010b/x/x TX De-emphasis Set
    #define CND003_PCIEEPHYCFG_RSV02_0F0C_13       (BIT13 + BIT14 + BIT15) // 0/0/x/x Reserved
    #define CND003_PCIEEPHYCFG_FRP02_V0_03_TDCIS   0x1F00                  // 11110b/11110b/x/x TX Bias Control Set
    #define CND003_PCIEEPHYCFG_RSV02_0F0C_6        (BIT6 + BIT7)           // 0/0/x/x Reserved
    #define CND003_PCIEEPHYCFG_FRP02_V0_03_TDPCIS  0x3F                    // 000000b/000000b/x/x TX Preshoot Set
#define CND003_PCIEEPHYCFG_TX_SWING_TABLE_LANE02_INDEX04 0xF10 // TX Swing Table Lane02-Index04
    #define CND003_PCIEEPHYCFG_FRP02_V0_04_TXPSR   (BIT29 + BIT30 + BIT31) // 011b/011b/x/x PMOS TX Slew Rate Control
    #define CND003_PCIEEPHYCFG_FRP02_V0_04_TXNSR   (BIT26 + BIT27 + BIT28) // 011b/011b/x/x NMOS TX Slew Rate Control
    #define CND003_PCIEEPHYCFG_FRP02_V0_04_TX_DUTY (BIT24 + BIT25)         // 00b/00b/x/x TX Clock Duty Control
    #define CND003_PCIEEPHYCFG_RSV02_0F10_22       (BIT22 + BIT23)         // 0/0/x/x Reserved
    #define CND003_PCIEEPHYCFG_FRP02_V0_04_TDNCIS  0x3F0000                // 100010b/100010b/x/x TX De-emphasis Set
    #define CND003_PCIEEPHYCFG_RSV02_0F10_13       (BIT13 + BIT14 + BIT15) // 0/0/x/x Reserved
    #define CND003_PCIEEPHYCFG_FRP02_V0_04_TDCIS   0x1F00                  // 11101b/11101b/x/x TX Bias Control Set
    #define CND003_PCIEEPHYCFG_RSV02_0F10_6        (BIT6 + BIT7)           // 0/0/x/x Reserved
    #define CND003_PCIEEPHYCFG_FRP02_V0_04_TDPCIS  0x3F                    // 000000b/000000b/x/x TX Preshoot Set
#define CND003_PCIEEPHYCFG_TX_SWING_TABLE_LANE02_INDEX05 0xF14 // TX Swing Table Lane02-Index05
    #define CND003_PCIEEPHYCFG_FRP02_V0_05_TXPSR   (BIT29 + BIT30 + BIT31) // 011b/011b/x/x PMOS TX Slew Rate Control
    #define CND003_PCIEEPHYCFG_FRP02_V0_05_TXNSR   (BIT26 + BIT27 + BIT28) // 011b/011b/x/x NMOS TX Slew Rate Control
    #define CND003_PCIEEPHYCFG_FRP02_V0_05_TX_DUTY (BIT24 + BIT25)         // 00b/00b/x/x TX Clock Duty Control
    #define CND003_PCIEEPHYCFG_RSV02_0F14_22       (BIT22 + BIT23)         // 0/0/x/x Reserved
    #define CND003_PCIEEPHYCFG_FRP02_V0_05_TDNCIS  0x3F0000                // 101010b/101010b/x/x TX De-emphasis Set
    #define CND003_PCIEEPHYCFG_RSV02_0F14_13       (BIT13 + BIT14 + BIT15) // 0/0/x/x Reserved
    #define CND003_PCIEEPHYCFG_FRP02_V0_05_TDCIS   0x1F00                  // 11100b/11100b/x/x TX Bias Control Set
    #define CND003_PCIEEPHYCFG_RSV02_0F14_6        (BIT6 + BIT7)           // 0/0/x/x Reserved
    #define CND003_PCIEEPHYCFG_FRP02_V0_05_TDPCIS  0x3F                    // 000000b/000000b/x/x TX Preshoot Set
#define CND003_PCIEEPHYCFG_TX_SWING_TABLE_LANE02_INDEX06 0xF18 // TX Swing Table Lane02-Index06
    #define CND003_PCIEEPHYCFG_FRP02_V0_06_TXPSR   (BIT29 + BIT30 + BIT31) // 011b/011b/x/x PMOS TX Slew Rate Control
    #define CND003_PCIEEPHYCFG_FRP02_V0_06_TXNSR   (BIT26 + BIT27 + BIT28) // 011b/011b/x/x NMOS TX Slew Rate Control
    #define CND003_PCIEEPHYCFG_FRP02_V0_06_TX_DUTY (BIT24 + BIT25)         // 00b/00b/x/x TX Clock Duty Control
    #define CND003_PCIEEPHYCFG_RSV02_0F18_22       (BIT22 + BIT23)         // 0/0/x/x Reserved
    #define CND003_PCIEEPHYCFG_FRP02_V0_06_TDNCIS  0x3F0000                // 110010b/110010b/x/x TX De-emphasis Set
    #define CND003_PCIEEPHYCFG_RSV02_0F18_13       (BIT13 + BIT14 + BIT15) // 0/0/x/x Reserved
    #define CND003_PCIEEPHYCFG_FRP02_V0_06_TDCIS   0x1F00                  // 11011b/11011b/x/x TX Bias Control Set
    #define CND003_PCIEEPHYCFG_RSV02_0F18_6        (BIT6 + BIT7)           // 0/0/x/x Reserved
    #define CND003_PCIEEPHYCFG_FRP02_V0_06_TDPCIS  0x3F                    // 000000b/000000b/x/x TX Preshoot Set
#define CND003_PCIEEPHYCFG_TX_SWING_TABLE_LANE02_INDEX07 0xF1C // TX Swing Table Lane02-Index07
    #define CND003_PCIEEPHYCFG_FRP02_V0_07_TXPSR   (BIT29 + BIT30 + BIT31) // 011b/011b/x/x PMOS TX Slew Rate Control
    #define CND003_PCIEEPHYCFG_FRP02_V0_07_TXNSR   (BIT26 + BIT27 + BIT28) // 011b/011b/x/x NMOS TX Slew Rate Control
    #define CND003_PCIEEPHYCFG_FRP02_V0_07_TX_DUTY (BIT24 + BIT25)         // 00b/00b/x/x TX Clock Duty Control
    #define CND003_PCIEEPHYCFG_RSV02_0F1C_22       (BIT22 + BIT23)         // 0/0/x/x Reserved
    #define CND003_PCIEEPHYCFG_FRP02_V0_07_TDNCIS  0x3F0000                // 111101b/111101b/x/x TX De-emphasis Set
    #define CND003_PCIEEPHYCFG_RSV02_0F1C_13       (BIT13 + BIT14 + BIT15) // 0/0/x/x Reserved
    #define CND003_PCIEEPHYCFG_FRP02_V0_07_TDCIS   0x1F00                  // 11011b/11011b/x/x TX Bias Control Set
    #define CND003_PCIEEPHYCFG_RSV02_0F1C_6        (BIT6 + BIT7)           // 0/0/x/x Reserved
    #define CND003_PCIEEPHYCFG_FRP02_V0_07_TDPCIS  0x3F                    // 000000b/000000b/x/x TX Preshoot Set
#define CND003_PCIEEPHYCFG_TX_SWING_TABLE_LANE02_INDEX08 0xF20 // TX Swing Table Lane02-Index08
    #define CND003_PCIEEPHYCFG_FRP02_V0_08_TXPSR   (BIT29 + BIT30 + BIT31) // 011b/011b/x/x PMOS TX Slew Rate Control
    #define CND003_PCIEEPHYCFG_FRP02_V0_08_TXNSR   (BIT26 + BIT27 + BIT28) // 011b/011b/x/x NMOS TX Slew Rate Control
    #define CND003_PCIEEPHYCFG_FRP02_V0_08_TX_DUTY (BIT24 + BIT25)         // 00b/00b/x/x TX Clock Duty Control
    #define CND003_PCIEEPHYCFG_RSV02_0F20_22       (BIT22 + BIT23)         // 0/0/x/x Reserved
    #define CND003_PCIEEPHYCFG_FRP02_V0_08_TDNCIS  0x3F0000                // 111111b/111111b/x/x TX De-emphasis Set
    #define CND003_PCIEEPHYCFG_RSV02_0F20_13       (BIT13 + BIT14 + BIT15) // 0/0/x/x Reserved
    #define CND003_PCIEEPHYCFG_FRP02_V0_08_TDCIS   0x1F00                  // 11001b/11001b/x/x TX Bias Control Set
    #define CND003_PCIEEPHYCFG_RSV02_0F20_6        (BIT6 + BIT7)           // 0/0/x/x Reserved
    #define CND003_PCIEEPHYCFG_FRP02_V0_08_TDPCIS  0x3F                    // 000000b/000000b/x/x TX Preshoot Set
#define CND003_PCIEEPHYCFG_TX_SWING_TABLE_LANE02_INDEX09 0xF24 // TX Swing Table Lane02-Index09
    #define CND003_PCIEEPHYCFG_FRP02_V0_09_TXPSR   (BIT29 + BIT30 + BIT31) // 011b/011b/x/x PMOS TX Slew Rate Control
    #define CND003_PCIEEPHYCFG_FRP02_V0_09_TXNSR   (BIT26 + BIT27 + BIT28) // 011b/011b/x/x NMOS TX Slew Rate Control
    #define CND003_PCIEEPHYCFG_FRP02_V0_09_TX_DUTY (BIT24 + BIT25)         // 00b/00b/x/x TX Clock Duty Control
    #define CND003_PCIEEPHYCFG_RSV02_0F24_22       (BIT22 + BIT23)         // 0/0/x/x Reserved
    #define CND003_PCIEEPHYCFG_FRP02_V0_09_TDNCIS  0x3F0000                // 000000b/000000b/x/x TX De-emphasis Set
    #define CND003_PCIEEPHYCFG_RSV02_0F24_13       (BIT13 + BIT14 + BIT15) // 0/0/x/x Reserved
    #define CND003_PCIEEPHYCFG_FRP02_V0_09_TDCIS   0x1F00                  // 11111b/11111b/x/x TX Bias Control Set
    #define CND003_PCIEEPHYCFG_RSV02_0F24_6        (BIT6 + BIT7)           // 0/0/x/x Reserved
    #define CND003_PCIEEPHYCFG_FRP02_V0_09_TDPCIS  0x3F                    // 001001b/001001b/x/x TX Preshoot Set
#define CND003_PCIEEPHYCFG_TX_SWING_TABLE_LANE02_INDEX10 0xF28 // TX Swing Table Lane02-Index10
    #define CND003_PCIEEPHYCFG_FRP02_V0_10_TXPSR   (BIT29 + BIT30 + BIT31) // 011b/011b/x/x PMOS TX Slew Rate Control
    #define CND003_PCIEEPHYCFG_FRP02_V0_10_TXNSR   (BIT26 + BIT27 + BIT28) // 011b/011b/x/x NMOS TX Slew Rate Control
    #define CND003_PCIEEPHYCFG_FRP02_V0_10_TX_DUTY (BIT24 + BIT25)         // 00b/00b/x/x TX Clock Duty Control
    #define CND003_PCIEEPHYCFG_RSV02_0F28_22       (BIT22 + BIT23)         // 0/0/x/x Reserved
    #define CND003_PCIEEPHYCFG_FRP02_V0_10_TDNCIS  0x3F0000                // 001001b/001001b/x/x TX De-emphasis Set
    #define CND003_PCIEEPHYCFG_RSV02_0F28_13       (BIT13 + BIT14 + BIT15) // 0/0/x/x Reserved
    #define CND003_PCIEEPHYCFG_FRP02_V0_10_TDCIS   0x1F00                  // 11111b/11111b/x/x TX Bias Control Set
    #define CND003_PCIEEPHYCFG_RSV02_0F28_6        (BIT6 + BIT7)           // 0/0/x/x Reserved
    #define CND003_PCIEEPHYCFG_FRP02_V0_10_TDPCIS  0x3F                    // 001001b/001001b/x/x TX Preshoot Set
#define CND003_PCIEEPHYCFG_TX_SWING_TABLE_LANE02_INDEX11 0xF2C // TX Swing Table Lane02-Index11
    #define CND003_PCIEEPHYCFG_FRP02_V0_11_TXPSR   (BIT29 + BIT30 + BIT31) // 011b/011b/x/x PMOS TX Slew Rate Control
    #define CND003_PCIEEPHYCFG_FRP02_V0_11_TXNSR   (BIT26 + BIT27 + BIT28) // 011b/011b/x/x NMOS TX Slew Rate Control
    #define CND003_PCIEEPHYCFG_FRP02_V0_11_TX_DUTY (BIT24 + BIT25)         // 00b/00b/x/x TX Clock Duty Control
    #define CND003_PCIEEPHYCFG_RSV02_0F2C_22       (BIT22 + BIT23)         // 0/0/x/x Reserved
    #define CND003_PCIEEPHYCFG_FRP02_V0_11_TDNCIS  0x3F0000                // 010001b/010001b/x/x TX De-emphasis Set
    #define CND003_PCIEEPHYCFG_RSV02_0F2C_13       (BIT13 + BIT14 + BIT15) // 0/0/x/x Reserved
    #define CND003_PCIEEPHYCFG_FRP02_V0_11_TDCIS   0x1F00                  // 11110b/11110b/x/x TX Bias Control Set
    #define CND003_PCIEEPHYCFG_RSV02_0F2C_6        (BIT6 + BIT7)           // 0/0/x/x Reserved
    #define CND003_PCIEEPHYCFG_FRP02_V0_11_TDPCIS  0x3F                    // 001001b/001001b/x/x TX Preshoot Set
#define CND003_PCIEEPHYCFG_TX_SWING_TABLE_LANE02_INDEX12 0xF30 // TX Swing Table Lane02-Index12
    #define CND003_PCIEEPHYCFG_FRP02_V0_12_TXPSR   (BIT29 + BIT30 + BIT31) // 011b/011b/x/x PMOS TX Slew Rate Control
    #define CND003_PCIEEPHYCFG_FRP02_V0_12_TXNSR   (BIT26 + BIT27 + BIT28) // 011b/011b/x/x NMOS TX Slew Rate Control
    #define CND003_PCIEEPHYCFG_FRP02_V0_12_TX_DUTY (BIT24 + BIT25)         // 00b/00b/x/x TX Clock Duty Control
    #define CND003_PCIEEPHYCFG_RSV02_0F30_22       (BIT22 + BIT23)         // 0/0/x/x Reserved
    #define CND003_PCIEEPHYCFG_FRP02_V0_12_TDNCIS  0x3F0000                // 011010b/011010b/x/x TX De-emphasis Set
    #define CND003_PCIEEPHYCFG_RSV02_0F30_13       (BIT13 + BIT14 + BIT15) // 0/0/x/x Reserved
    #define CND003_PCIEEPHYCFG_FRP02_V0_12_TDCIS   0x1F00                  // 11101b/11101b/x/x TX Bias Control Set
    #define CND003_PCIEEPHYCFG_RSV02_0F30_6        (BIT6 + BIT7)           // 0/0/x/x Reserved
    #define CND003_PCIEEPHYCFG_FRP02_V0_12_TDPCIS  0x3F                    // 001001b/001001b/x/x TX Preshoot Set
#define CND003_PCIEEPHYCFG_TX_SWING_TABLE_LANE02_INDEX13 0xF34 // TX Swing Table Lane02-Index13
    #define CND003_PCIEEPHYCFG_FRP02_V0_13_TXPSR   (BIT29 + BIT30 + BIT31) // 011b/011b/x/x PMOS TX Slew Rate Control
    #define CND003_PCIEEPHYCFG_FRP02_V0_13_TXNSR   (BIT26 + BIT27 + BIT28) // 011b/011b/x/x NMOS TX Slew Rate Control
    #define CND003_PCIEEPHYCFG_FRP02_V0_13_TX_DUTY (BIT24 + BIT25)         // 00b/00b/x/x TX Clock Duty Control
    #define CND003_PCIEEPHYCFG_RSV02_0F34_22       (BIT22 + BIT23)         // 0/0/x/x Reserved
    #define CND003_PCIEEPHYCFG_FRP02_V0_13_TDNCIS  0x3F0000                // 100010b/100010b/x/x TX De-emphasis Set
    #define CND003_PCIEEPHYCFG_RSV02_0F34_13       (BIT13 + BIT14 + BIT15) // 0/0/x/x Reserved
    #define CND003_PCIEEPHYCFG_FRP02_V0_13_TDCIS   0x1F00                  // 11100b/11100b/x/x TX Bias Control Set
    #define CND003_PCIEEPHYCFG_RSV02_0F34_6        (BIT6 + BIT7)           // 0/0/x/x Reserved
    #define CND003_PCIEEPHYCFG_FRP02_V0_13_TDPCIS  0x3F                    // 001001b/001001b/x/x TX Preshoot Set
#define CND003_PCIEEPHYCFG_TX_SWING_TABLE_LANE02_INDEX14 0xF38 // TX Swing Table Lane02-Index14
    #define CND003_PCIEEPHYCFG_FRP02_V0_14_TXPSR   (BIT29 + BIT30 + BIT31) // 011b/011b/x/x PMOS TX Slew Rate Control
    #define CND003_PCIEEPHYCFG_FRP02_V0_14_TXNSR   (BIT26 + BIT27 + BIT28) // 011b/011b/x/x NMOS TX Slew Rate Control
    #define CND003_PCIEEPHYCFG_FRP02_V0_14_TX_DUTY (BIT24 + BIT25)         // 00b/00b/x/x TX Clock Duty Control
    #define CND003_PCIEEPHYCFG_RSV02_0F38_22       (BIT22 + BIT23)         // 0/0/x/x Reserved
    #define CND003_PCIEEPHYCFG_FRP02_V0_14_TDNCIS  0x3F0000                // 101010b/101010b/x/x TX De-emphasis Set
    #define CND003_PCIEEPHYCFG_RSV02_0F38_13       (BIT13 + BIT14 + BIT15) // 0/0/x/x Reserved
    #define CND003_PCIEEPHYCFG_FRP02_V0_14_TDCIS   0x1F00                  // 11011b/11011b/x/x TX Bias Control Set
    #define CND003_PCIEEPHYCFG_RSV02_0F38_6        (BIT6 + BIT7)           // 0/0/x/x Reserved
    #define CND003_PCIEEPHYCFG_FRP02_V0_14_TDPCIS  0x3F                    // 001001b/001001b/x/x TX Preshoot Set
#define CND003_PCIEEPHYCFG_TX_SWING_TABLE_LANE02_INDEX15 0xF3C // TX Swing Table Lane02-Index15
    #define CND003_PCIEEPHYCFG_FRP02_V0_15_TXPSR   (BIT29 + BIT30 + BIT31) // 011b/011b/x/x PMOS TX Slew Rate Control
    #define CND003_PCIEEPHYCFG_FRP02_V0_15_TXNSR   (BIT26 + BIT27 + BIT28) // 011b/011b/x/x NMOS TX Slew Rate Control
    #define CND003_PCIEEPHYCFG_FRP02_V0_15_TX_DUTY (BIT24 + BIT25)         // 00b/00b/x/x TX Clock Duty Control
    #define CND003_PCIEEPHYCFG_RSV02_0F3C_22       (BIT22 + BIT23)         // 0/0/x/x Reserved
    #define CND003_PCIEEPHYCFG_FRP02_V0_15_TDNCIS  0x3F0000                // 110010b/110010b/x/x TX De-emphasis Set
    #define CND003_PCIEEPHYCFG_RSV02_0F3C_13       (BIT13 + BIT14 + BIT15) // 0/0/x/x Reserved
    #define CND003_PCIEEPHYCFG_FRP02_V0_15_TDCIS   0x1F00                  // 11011b/11011b/x/x TX Bias Control Set
    #define CND003_PCIEEPHYCFG_RSV02_0F3C_6        (BIT6 + BIT7)           // 0/0/x/x Reserved
    #define CND003_PCIEEPHYCFG_FRP02_V0_15_TDPCIS  0x3F                    // 001001b/001001b/x/x TX Preshoot Set
#define CND003_PCIEEPHYCFG_TX_SWING_TABLE_LANE02_INDEX16 0xF40 // TX Swing Table Lane02-Index16
    #define CND003_PCIEEPHYCFG_FRP02_V0_16_TXPSR   (BIT29 + BIT30 + BIT31) // 011b/011b/x/x PMOS TX Slew Rate Control
    #define CND003_PCIEEPHYCFG_FRP02_V0_16_TXNSR   (BIT26 + BIT27 + BIT28) // 011b/011b/x/x NMOS TX Slew Rate Control
    #define CND003_PCIEEPHYCFG_FRP02_V0_16_TX_DUTY (BIT24 + BIT25)         // 00b/00b/x/x TX Clock Duty Control
    #define CND003_PCIEEPHYCFG_RSV02_0F40_22       (BIT22 + BIT23)         // 0/0/x/x Reserved
    #define CND003_PCIEEPHYCFG_FRP02_V0_16_TDNCIS  0x3F0000                // 111101b/111101b/x/x TX De-emphasis Set
    #define CND003_PCIEEPHYCFG_RSV02_0F40_13       (BIT13 + BIT14 + BIT15) // 0/0/x/x Reserved
    #define CND003_PCIEEPHYCFG_FRP02_V0_16_TDCIS   0x1F00                  // 11010b/11010b/x/x TX Bias Control Set
    #define CND003_PCIEEPHYCFG_RSV02_0F40_6        (BIT6 + BIT7)           // 0/0/x/x Reserved
    #define CND003_PCIEEPHYCFG_FRP02_V0_16_TDPCIS  0x3F                    // 001001b/001001b/x/x TX Preshoot Set
#define CND003_PCIEEPHYCFG_TX_SWING_TABLE_LANE02_INDEX17 0xF44 // TX Swing Table Lane02-Index17
    #define CND003_PCIEEPHYCFG_FRP02_V0_17_TXPSR   (BIT29 + BIT30 + BIT31) // 011b/011b/x/x PMOS TX Slew Rate Control
    #define CND003_PCIEEPHYCFG_FRP02_V0_17_TXNSR   (BIT26 + BIT27 + BIT28) // 011b/011b/x/x NMOS TX Slew Rate Control
    #define CND003_PCIEEPHYCFG_FRP02_V0_17_TX_DUTY (BIT24 + BIT25)         // 00b/00b/x/x TX Clock Duty Control
    #define CND003_PCIEEPHYCFG_RSV02_0F44_22       (BIT22 + BIT23)         // 0/0/x/x Reserved
    #define CND003_PCIEEPHYCFG_FRP02_V0_17_TDNCIS  0x3F0000                // 000000b/000000b/x/x TX De-emphasis Set
    #define CND003_PCIEEPHYCFG_RSV02_0F44_13       (BIT13 + BIT14 + BIT15) // 0/0/x/x Reserved
    #define CND003_PCIEEPHYCFG_FRP02_V0_17_TDCIS   0x1F00                  // 11111b/11111b/x/x TX Bias Control Set
    #define CND003_PCIEEPHYCFG_RSV02_0F44_6        (BIT6 + BIT7)           // 0/0/x/x Reserved
    #define CND003_PCIEEPHYCFG_FRP02_V0_17_TDPCIS  0x3F                    // 010001b/010001b/x/x TX Preshoot Set
#define CND003_PCIEEPHYCFG_TX_SWING_TABLE_LANE02_INDEX18 0xF48 // TX Swing Table Lane02-Index18
    #define CND003_PCIEEPHYCFG_FRP02_V0_18_TXPSR   (BIT29 + BIT30 + BIT31) // 011b/011b/x/x PMOS TX Slew Rate Control
    #define CND003_PCIEEPHYCFG_FRP02_V0_18_TXNSR   (BIT26 + BIT27 + BIT28) // 011b/011b/x/x NMOS TX Slew Rate Control
    #define CND003_PCIEEPHYCFG_FRP02_V0_18_TX_DUTY (BIT24 + BIT25)         // 00b/00b/x/x TX Clock Duty Control
    #define CND003_PCIEEPHYCFG_RSV02_0F48_22       (BIT22 + BIT23)         // 0/0/x/x Reserved
    #define CND003_PCIEEPHYCFG_FRP02_V0_18_TDNCIS  0x3F0000                // 001001b/001001b/x/x TX De-emphasis Set
    #define CND003_PCIEEPHYCFG_RSV02_0F48_13       (BIT13 + BIT14 + BIT15) // 0/0/x/x Reserved
    #define CND003_PCIEEPHYCFG_FRP02_V0_18_TDCIS   0x1F00                  // 11110b/11110b/x/x TX Bias Control Set
    #define CND003_PCIEEPHYCFG_RSV02_0F48_6        (BIT6 + BIT7)           // 0/0/x/x Reserved
    #define CND003_PCIEEPHYCFG_FRP02_V0_18_TDPCIS  0x3F                    // 010001b/010001b/x/x TX Preshoot Set
#define CND003_PCIEEPHYCFG_TX_SWING_TABLE_LANE02_INDEX19 0xF4C // TX Swing Table Lane02-Index19
    #define CND003_PCIEEPHYCFG_FRP02_V0_19_TXPSR   (BIT29 + BIT30 + BIT31) // 011b/011b/x/x PMOS TX Slew Rate Control
    #define CND003_PCIEEPHYCFG_FRP02_V0_19_TXNSR   (BIT26 + BIT27 + BIT28) // 011b/011b/x/x NMOS TX Slew Rate Control
    #define CND003_PCIEEPHYCFG_FRP02_V0_19_TX_DUTY (BIT24 + BIT25)         // 00b/00b/x/x TX Clock Duty Control
    #define CND003_PCIEEPHYCFG_RSV02_0F4C_22       (BIT22 + BIT23)         // 0/0/x/x Reserved
    #define CND003_PCIEEPHYCFG_FRP02_V0_19_TDNCIS  0x3F0000                // 010001b/010001b/x/x TX De-emphasis Set
    #define CND003_PCIEEPHYCFG_RSV02_0F4C_13       (BIT13 + BIT14 + BIT15) // 0/0/x/x Reserved
    #define CND003_PCIEEPHYCFG_FRP02_V0_19_TDCIS   0x1F00                  // 11101b/11101b/x/x TX Bias Control Set
    #define CND003_PCIEEPHYCFG_RSV02_0F4C_6        (BIT6 + BIT7)           // 0/0/x/x Reserved
    #define CND003_PCIEEPHYCFG_FRP02_V0_19_TDPCIS  0x3F                    // 010001b/010001b/x/x TX Preshoot Set
#define CND003_PCIEEPHYCFG_TX_SWING_TABLE_LANE02_INDEX20 0xF50 // TX Swing Table Lane02-Index20
    #define CND003_PCIEEPHYCFG_FRP02_V0_20_TXPSR   (BIT29 + BIT30 + BIT31) // 011b/011b/x/x PMOS TX Slew Rate Control
    #define CND003_PCIEEPHYCFG_FRP02_V0_20_TXNSR   (BIT26 + BIT27 + BIT28) // 011b/011b/x/x NMOS TX Slew Rate Control
    #define CND003_PCIEEPHYCFG_FRP02_V0_20_TX_DUTY (BIT24 + BIT25)         // 00b/00b/x/x TX Clock Duty Control
    #define CND003_PCIEEPHYCFG_RSV02_0F50_22       (BIT22 + BIT23)         // 0/0/x/x Reserved
    #define CND003_PCIEEPHYCFG_FRP02_V0_20_TDNCIS  0x3F0000                // 011000b/011000b/x/x TX De-emphasis Set
    #define CND003_PCIEEPHYCFG_RSV02_0F50_13       (BIT13 + BIT14 + BIT15) // 0/0/x/x Reserved
    #define CND003_PCIEEPHYCFG_FRP02_V0_20_TDCIS   0x1F00                  // 11100b/11100b/x/x TX Bias Control Set
    #define CND003_PCIEEPHYCFG_RSV02_0F50_6        (BIT6 + BIT7)           // 0/0/x/x Reserved
    #define CND003_PCIEEPHYCFG_FRP02_V0_20_TDPCIS  0x3F                    // 010001b/010001b/x/x TX Preshoot Set
#define CND003_PCIEEPHYCFG_TX_SWING_TABLE_LANE02_INDEX21 0xF54 // TX Swing Table Lane02-Index21
    #define CND003_PCIEEPHYCFG_FRP02_V0_21_TXPSR   (BIT29 + BIT30 + BIT31) // 011b/011b/x/x PMOS TX Slew Rate Control
    #define CND003_PCIEEPHYCFG_FRP02_V0_21_TXNSR   (BIT26 + BIT27 + BIT28) // 011b/011b/x/x NMOS TX Slew Rate Control
    #define CND003_PCIEEPHYCFG_FRP02_V0_21_TX_DUTY (BIT24 + BIT25)         // 00b/00b/x/x TX Clock Duty Control
    #define CND003_PCIEEPHYCFG_RSV02_0F54_22       (BIT22 + BIT23)         // 0/0/x/x Reserved
    #define CND003_PCIEEPHYCFG_FRP02_V0_21_TDNCIS  0x3F0000                // 100010b/100010b/x/x TX De-emphasis Set
    #define CND003_PCIEEPHYCFG_RSV02_0F54_13       (BIT13 + BIT14 + BIT15) // 0/0/x/x Reserved
    #define CND003_PCIEEPHYCFG_FRP02_V0_21_TDCIS   0x1F00                  // 11011b/11011b/x/x TX Bias Control Set
    #define CND003_PCIEEPHYCFG_RSV02_0F54_6        (BIT6 + BIT7)           // 0/0/x/x Reserved
    #define CND003_PCIEEPHYCFG_FRP02_V0_21_TDPCIS  0x3F                    // 010001b/010001b/x/x TX Preshoot Set
#define CND003_PCIEEPHYCFG_TX_SWING_TABLE_LANE02_INDEX22 0xF58 // TX Swing Table Lane02-Index22
    #define CND003_PCIEEPHYCFG_FRP02_V0_22_TXPSR   (BIT29 + BIT30 + BIT31) // 011b/011b/x/x PMOS TX Slew Rate Control
    #define CND003_PCIEEPHYCFG_FRP02_V0_22_TXNSR   (BIT26 + BIT27 + BIT28) // 011b/011b/x/x NMOS TX Slew Rate Control
    #define CND003_PCIEEPHYCFG_FRP02_V0_22_TX_DUTY (BIT24 + BIT25)         // 00b/00b/x/x TX Clock Duty Control
    #define CND003_PCIEEPHYCFG_RSV02_0F58_22       (BIT22 + BIT23)         // 0/0/x/x Reserved
    #define CND003_PCIEEPHYCFG_FRP02_V0_22_TDNCIS  0x3F0000                // 101100b/101100b/x/x TX De-emphasis Set
    #define CND003_PCIEEPHYCFG_RSV02_0F58_13       (BIT13 + BIT14 + BIT15) // 0/0/x/x Reserved
    #define CND003_PCIEEPHYCFG_FRP02_V0_22_TDCIS   0x1F00                  // 11011b/11011b/x/x TX Bias Control Set
    #define CND003_PCIEEPHYCFG_RSV02_0F58_6        (BIT6 + BIT7)           // 0/0/x/x Reserved
    #define CND003_PCIEEPHYCFG_FRP02_V0_22_TDPCIS  0x3F                    // 010001b/010001b/x/x TX Preshoot Set
#define CND003_PCIEEPHYCFG_TX_SWING_TABLE_LANE02_INDEX23 0xF5C // TX Swing Table Lane02-Index23
    #define CND003_PCIEEPHYCFG_FRP02_V0_23_TXPSR   (BIT29 + BIT30 + BIT31) // 011b/011b/x/x PMOS TX Slew Rate Control
    #define CND003_PCIEEPHYCFG_FRP02_V0_23_TXNSR   (BIT26 + BIT27 + BIT28) // 011b/011b/x/x NMOS TX Slew Rate Control
    #define CND003_PCIEEPHYCFG_FRP02_V0_23_TX_DUTY (BIT24 + BIT25)         // 00b/00b/x/x TX Clock Duty Control
    #define CND003_PCIEEPHYCFG_RSV02_0F5C_22       (BIT22 + BIT23)         // 0/0/x/x Reserved
    #define CND003_PCIEEPHYCFG_FRP02_V0_23_TDNCIS  0x3F0000                // 110010b/110010b/x/x TX De-emphasis Set
    #define CND003_PCIEEPHYCFG_RSV02_0F5C_13       (BIT13 + BIT14 + BIT15) // 0/0/x/x Reserved
    #define CND003_PCIEEPHYCFG_FRP02_V0_23_TDCIS   0x1F00                  // 11010b/11010b/x/x TX Bias Control Set
    #define CND003_PCIEEPHYCFG_RSV02_0F5C_6        (BIT6 + BIT7)           // 0/0/x/x Reserved
    #define CND003_PCIEEPHYCFG_FRP02_V0_23_TDPCIS  0x3F                    // 010001b/010001b/x/x TX Preshoot Set
#define CND003_PCIEEPHYCFG_TX_SWING_TABLE_LANE02_INDEX24 0xF60 // TX Swing Table Lane02-Index24
    #define CND003_PCIEEPHYCFG_FRP02_V0_24_TXPSR   (BIT29 + BIT30 + BIT31) // 011b/011b/x/x PMOS TX Slew Rate Control
    #define CND003_PCIEEPHYCFG_FRP02_V0_24_TXNSR   (BIT26 + BIT27 + BIT28) // 011b/011b/x/x NMOS TX Slew Rate Control
    #define CND003_PCIEEPHYCFG_FRP02_V0_24_TX_DUTY (BIT24 + BIT25)         // 00b/00b/x/x TX Clock Duty Control
    #define CND003_PCIEEPHYCFG_RSV02_0F60_22       (BIT22 + BIT23)         // 0/0/x/x Reserved
    #define CND003_PCIEEPHYCFG_FRP02_V0_24_TDNCIS  0x3F0000                // 000000b/000000b/x/x TX De-emphasis Set
    #define CND003_PCIEEPHYCFG_RSV02_0F60_13       (BIT13 + BIT14 + BIT15) // 0/0/x/x Reserved
    #define CND003_PCIEEPHYCFG_FRP02_V0_24_TDCIS   0x1F00                  // 11110b/11110b/x/x TX Bias Control Set
    #define CND003_PCIEEPHYCFG_RSV02_0F60_6        (BIT6 + BIT7)           // 0/0/x/x Reserved
    #define CND003_PCIEEPHYCFG_FRP02_V0_24_TDPCIS  0x3F                    // 011010b/011010b/x/x TX Preshoot Set
#define CND003_PCIEEPHYCFG_TX_SWING_TABLE_LANE02_INDEX25 0xF64 // TX Swing Table Lane02-Index25
    #define CND003_PCIEEPHYCFG_FRP02_V0_25_TXPSR   (BIT29 + BIT30 + BIT31) // 011b/011b/x/x PMOS TX Slew Rate Control
    #define CND003_PCIEEPHYCFG_FRP02_V0_25_TXNSR   (BIT26 + BIT27 + BIT28) // 011b/011b/x/x NMOS TX Slew Rate Control
    #define CND003_PCIEEPHYCFG_FRP02_V0_25_TX_DUTY (BIT24 + BIT25)         // 00b/00b/x/x TX Clock Duty Control
    #define CND003_PCIEEPHYCFG_RSV02_0F64_22       (BIT22 + BIT23)         // 0/0/x/x Reserved
    #define CND003_PCIEEPHYCFG_FRP02_V0_25_TDNCIS  0x3F0000                // 001001b/001001b/x/x TX De-emphasis Set
    #define CND003_PCIEEPHYCFG_RSV02_0F64_13       (BIT13 + BIT14 + BIT15) // 0/0/x/x Reserved
    #define CND003_PCIEEPHYCFG_FRP02_V0_25_TDCIS   0x1F00                  // 11101b/11101b/x/x TX Bias Control Set
    #define CND003_PCIEEPHYCFG_RSV02_0F64_6        (BIT6 + BIT7)           // 0/0/x/x Reserved
    #define CND003_PCIEEPHYCFG_FRP02_V0_25_TDPCIS  0x3F                    // 011010b/011010b/x/x TX Preshoot Set
#define CND003_PCIEEPHYCFG_TX_SWING_TABLE_LANE02_INDEX26 0xF68 // TX Swing Table Lane02-Index26
    #define CND003_PCIEEPHYCFG_FRP02_V0_26_TXPSR   (BIT29 + BIT30 + BIT31) // 011b/011b/x/x PMOS TX Slew Rate Control
    #define CND003_PCIEEPHYCFG_FRP02_V0_26_TXNSR   (BIT26 + BIT27 + BIT28) // 011b/011b/x/x NMOS TX Slew Rate Control
    #define CND003_PCIEEPHYCFG_FRP02_V0_26_TX_DUTY (BIT24 + BIT25)         // 00b/00b/x/x TX Clock Duty Control
    #define CND003_PCIEEPHYCFG_RSV02_0F68_22       (BIT22 + BIT23)         // 0/0/x/x Reserved
    #define CND003_PCIEEPHYCFG_FRP02_V0_26_TDNCIS  0x3F0000                // 010001b/010001b/x/x TX De-emphasis Set
    #define CND003_PCIEEPHYCFG_RSV02_0F68_13       (BIT13 + BIT14 + BIT15) // 0/0/x/x Reserved
    #define CND003_PCIEEPHYCFG_FRP02_V0_26_TDCIS   0x1F00                  // 11100b/11100b/x/x TX Bias Control Set
    #define CND003_PCIEEPHYCFG_RSV02_0F68_6        (BIT6 + BIT7)           // 0/0/x/x Reserved
    #define CND003_PCIEEPHYCFG_FRP02_V0_26_TDPCIS  0x3F                    // 011010b/011010b/x/x TX Preshoot Set
#define CND003_PCIEEPHYCFG_TX_SWING_TABLE_LANE02_INDEX27 0xF6C // TX Swing Table Lane02-Index27
    #define CND003_PCIEEPHYCFG_FRP02_V0_27_TXPSR   (BIT29 + BIT30 + BIT31) // 011b/011b/x/x PMOS TX Slew Rate Control
    #define CND003_PCIEEPHYCFG_FRP02_V0_27_TXNSR   (BIT26 + BIT27 + BIT28) // 011b/011b/x/x NMOS TX Slew Rate Control
    #define CND003_PCIEEPHYCFG_FRP02_V0_27_TX_DUTY (BIT24 + BIT25)         // 00b/00b/x/x TX Clock Duty Control
    #define CND003_PCIEEPHYCFG_RSV02_0F6C_22       (BIT22 + BIT23)         // 0/0/x/x Reserved
    #define CND003_PCIEEPHYCFG_FRP02_V0_27_TDNCIS  0x3F0000                // 011010b/011010b/x/x TX De-emphasis Set
    #define CND003_PCIEEPHYCFG_RSV02_0F6C_13       (BIT13 + BIT14 + BIT15) // 0/0/x/x Reserved
    #define CND003_PCIEEPHYCFG_FRP02_V0_27_TDCIS   0x1F00                  // 11011b/11011b/x/x TX Bias Control Set
    #define CND003_PCIEEPHYCFG_RSV02_0F6C_6        (BIT6 + BIT7)           // 0/0/x/x Reserved
    #define CND003_PCIEEPHYCFG_FRP02_V0_27_TDPCIS  0x3F                    // 011010b/011010b/x/x TX Preshoot Set
#define CND003_PCIEEPHYCFG_TX_SWING_TABLE_LANE02_INDEX28 0xF70 // TX Swing Table Lane02-Index28
    #define CND003_PCIEEPHYCFG_FRP02_V0_28_TXPSR   (BIT29 + BIT30 + BIT31) // 011b/011b/x/x PMOS TX Slew Rate Control
    #define CND003_PCIEEPHYCFG_FRP02_V0_28_TXNSR   (BIT26 + BIT27 + BIT28) // 011b/011b/x/x NMOS TX Slew Rate Control
    #define CND003_PCIEEPHYCFG_FRP02_V0_28_TX_DUTY (BIT24 + BIT25)         // 00b/00b/x/x TX Clock Duty Control
    #define CND003_PCIEEPHYCFG_RSV02_0F70_22       (BIT22 + BIT23)         // 0/0/x/x Reserved
    #define CND003_PCIEEPHYCFG_FRP02_V0_28_TDNCIS  0x3F0000                // 100010b/100010b/x/x TX De-emphasis Set
    #define CND003_PCIEEPHYCFG_RSV02_0F70_13       (BIT13 + BIT14 + BIT15) // 0/0/x/x Reserved
    #define CND003_PCIEEPHYCFG_FRP02_V0_28_TDCIS   0x1F00                  // 11011b/11011b/x/x TX Bias Control Set
    #define CND003_PCIEEPHYCFG_RSV02_0F70_6        (BIT6 + BIT7)           // 0/0/x/x Reserved
    #define CND003_PCIEEPHYCFG_FRP02_V0_28_TDPCIS  0x3F                    // 011010b/011010b/x/x TX Preshoot Set
#define CND003_PCIEEPHYCFG_TX_SWING_TABLE_LANE02_INDEX29 0xF74 // TX Swing Table Lane02-Index29
    #define CND003_PCIEEPHYCFG_FRP02_V0_29_TXPSR   (BIT29 + BIT30 + BIT31) // 011b/011b/x/x PMOS TX Slew Rate Control
    #define CND003_PCIEEPHYCFG_FRP02_V0_29_TXNSR   (BIT26 + BIT27 + BIT28) // 011b/011b/x/x NMOS TX Slew Rate Control
    #define CND003_PCIEEPHYCFG_FRP02_V0_29_TX_DUTY (BIT24 + BIT25)         // 00b/00b/x/x TX Clock Duty Control
    #define CND003_PCIEEPHYCFG_RSV02_0F74_22       (BIT22 + BIT23)         // 0/0/x/x Reserved
    #define CND003_PCIEEPHYCFG_FRP02_V0_29_TDNCIS  0x3F0000                // 101010b/101010b/x/x TX De-emphasis Set
    #define CND003_PCIEEPHYCFG_RSV02_0F74_13       (BIT13 + BIT14 + BIT15) // 0/0/x/x Reserved
    #define CND003_PCIEEPHYCFG_FRP02_V0_29_TDCIS   0x1F00                  // 11010b/11010b/x/x TX Bias Control Set
    #define CND003_PCIEEPHYCFG_RSV02_0F74_6        (BIT6 + BIT7)           // 0/0/x/x Reserved
    #define CND003_PCIEEPHYCFG_FRP02_V0_29_TDPCIS  0x3F                    // 011010b/011010b/x/x TX Preshoot Set
#define CND003_PCIEEPHYCFG_TX_SWING_TABLE_LANE02_INDEX30 0xF78 // TX Swing Table Lane02-Index30
    #define CND003_PCIEEPHYCFG_FRP02_V0_30_TXPSR   (BIT29 + BIT30 + BIT31) // 011b/011b/x/x PMOS TX Slew Rate Control
    #define CND003_PCIEEPHYCFG_FRP02_V0_30_TXNSR   (BIT26 + BIT27 + BIT28) // 011b/011b/x/x NMOS TX Slew Rate Control
    #define CND003_PCIEEPHYCFG_FRP02_V0_30_TX_DUTY (BIT24 + BIT25)         // 00b/00b/x/x TX Clock Duty Control
    #define CND003_PCIEEPHYCFG_RSV02_0F78_22       (BIT22 + BIT23)         // 0/0/x/x Reserved
    #define CND003_PCIEEPHYCFG_FRP02_V0_30_TDNCIS  0x3F0000                // 000000b/000000b/x/x TX De-emphasis Set
    #define CND003_PCIEEPHYCFG_RSV02_0F78_13       (BIT13 + BIT14 + BIT15) // 0/0/x/x Reserved
    #define CND003_PCIEEPHYCFG_FRP02_V0_30_TDCIS   0x1F00                  // 11101b/11101b/x/x TX Bias Control Set
    #define CND003_PCIEEPHYCFG_RSV02_0F78_6        (BIT6 + BIT7)           // 0/0/x/x Reserved
    #define CND003_PCIEEPHYCFG_FRP02_V0_30_TDPCIS  0x3F                    // 100010b/100010b/x/x TX Preshoot Set
#define CND003_PCIEEPHYCFG_TX_SWING_TABLE_LANE02_INDEX31 0xF7C // TX Swing Table Lane02-Index31
    #define CND003_PCIEEPHYCFG_FRP02_V0_31_TXPSR   (BIT29 + BIT30 + BIT31) // 011b/011b/x/x PMOS TX Slew Rate Control
    #define CND003_PCIEEPHYCFG_FRP02_V0_31_TXNSR   (BIT26 + BIT27 + BIT28) // 011b/011b/x/x NMOS TX Slew Rate Control
    #define CND003_PCIEEPHYCFG_FRP02_V0_31_TX_DUTY (BIT24 + BIT25)         // 00b/00b/x/x TX Clock Duty Control
    #define CND003_PCIEEPHYCFG_RSV02_0F7C_22       (BIT22 + BIT23)         // 0/0/x/x Reserved
    #define CND003_PCIEEPHYCFG_FRP02_V0_31_TDNCIS  0x3F0000                // 001001b/001001b/x/x TX De-emphasis Set
    #define CND003_PCIEEPHYCFG_RSV02_0F7C_13       (BIT13 + BIT14 + BIT15) // 0/0/x/x Reserved
    #define CND003_PCIEEPHYCFG_FRP02_V0_31_TDCIS   0x1F00                  // 11100b/11100b/x/x TX Bias Control Set
    #define CND003_PCIEEPHYCFG_RSV02_0F7C_6        (BIT6 + BIT7)           // 0/0/x/x Reserved
    #define CND003_PCIEEPHYCFG_FRP02_V0_31_TDPCIS  0x3F                    // 100010b/100010b/x/x TX Preshoot Set
#define CND003_PCIEEPHYCFG_TX_SWING_TABLE_LANE02_INDEX32 0xF80 // TX Swing Table Lane02-Index32
    #define CND003_PCIEEPHYCFG_FRP02_V0_32_TXPSR   (BIT29 + BIT30 + BIT31) // 011b/011b/x/x PMOS TX Slew Rate Control
    #define CND003_PCIEEPHYCFG_FRP02_V0_32_TXNSR   (BIT26 + BIT27 + BIT28) // 011b/011b/x/x NMOS TX Slew Rate Control
    #define CND003_PCIEEPHYCFG_FRP02_V0_32_TX_DUTY (BIT24 + BIT25)         // 00b/00b/x/x TX Clock Duty Control
    #define CND003_PCIEEPHYCFG_RSV02_0F80_22       (BIT22 + BIT23)         // 0/0/x/x Reserved
    #define CND003_PCIEEPHYCFG_FRP02_V0_32_TDNCIS  0x3F0000                // 010000b/010000b/x/x TX De-emphasis Set
    #define CND003_PCIEEPHYCFG_RSV02_0F80_13       (BIT13 + BIT14 + BIT15) // 0/0/x/x Reserved
    #define CND003_PCIEEPHYCFG_FRP02_V0_32_TDCIS   0x1F00                  // 11011b/11011b/x/x TX Bias Control Set
    #define CND003_PCIEEPHYCFG_RSV02_0F80_6        (BIT6 + BIT7)           // 0/0/x/x Reserved
    #define CND003_PCIEEPHYCFG_FRP02_V0_32_TDPCIS  0x3F                    // 100010b/100010b/x/x TX Preshoot Set
#define CND003_PCIEEPHYCFG_TX_SWING_TABLE_LANE02_INDEX33 0xF84 // TX Swing Table Lane02-Index33
    #define CND003_PCIEEPHYCFG_FRP02_V0_33_TXPSR   (BIT29 + BIT30 + BIT31) // 011b/011b/x/x PMOS TX Slew Rate Control
    #define CND003_PCIEEPHYCFG_FRP02_V0_33_TXNSR   (BIT26 + BIT27 + BIT28) // 011b/011b/x/x NMOS TX Slew Rate Control
    #define CND003_PCIEEPHYCFG_FRP02_V0_33_TX_DUTY (BIT24 + BIT25)         // 00b/00b/x/x TX Clock Duty Control
    #define CND003_PCIEEPHYCFG_RSV02_0F84_22       (BIT22 + BIT23)         // 0/0/x/x Reserved
    #define CND003_PCIEEPHYCFG_FRP02_V0_33_TDNCIS  0x3F0000                // 011010b/011010b/x/x TX De-emphasis Set
    #define CND003_PCIEEPHYCFG_RSV02_0F84_13       (BIT13 + BIT14 + BIT15) // 0/0/x/x Reserved
    #define CND003_PCIEEPHYCFG_FRP02_V0_33_TDCIS   0x1F00                  // 11011b/11011b/x/x TX Bias Control Set
    #define CND003_PCIEEPHYCFG_RSV02_0F84_6        (BIT6 + BIT7)           // 0/0/x/x Reserved
    #define CND003_PCIEEPHYCFG_FRP02_V0_33_TDPCIS  0x3F                    // 100010b/100010b/x/x TX Preshoot Set
#define CND003_PCIEEPHYCFG_TX_SWING_TABLE_LANE02_INDEX34 0xF88 // TX Swing Table Lane02-Index34
    #define CND003_PCIEEPHYCFG_FRP02_V0_34_TXPSR   (BIT29 + BIT30 + BIT31) // 011b/011b/x/x PMOS TX Slew Rate Control
    #define CND003_PCIEEPHYCFG_FRP02_V0_34_TXNSR   (BIT26 + BIT27 + BIT28) // 011b/011b/x/x NMOS TX Slew Rate Control
    #define CND003_PCIEEPHYCFG_FRP02_V0_34_TX_DUTY (BIT24 + BIT25)         // 00b/00b/x/x TX Clock Duty Control
    #define CND003_PCIEEPHYCFG_RSV02_0F88_22       (BIT22 + BIT23)         // 0/0/x/x Reserved
    #define CND003_PCIEEPHYCFG_FRP02_V0_34_TDNCIS  0x3F0000                // 100010b/100010b/x/x TX De-emphasis Set
    #define CND003_PCIEEPHYCFG_RSV02_0F88_13       (BIT13 + BIT14 + BIT15) // 0/0/x/x Reserved
    #define CND003_PCIEEPHYCFG_FRP02_V0_34_TDCIS   0x1F00                  // 11010b/11010b/x/x TX Bias Control Set
    #define CND003_PCIEEPHYCFG_RSV02_0F88_6        (BIT6 + BIT7)           // 0/0/x/x Reserved
    #define CND003_PCIEEPHYCFG_FRP02_V0_34_TDPCIS  0x3F                    // 100010b/100010b/x/x TX Preshoot Set
#define CND003_PCIEEPHYCFG_TX_SWING_TABLE_LANE02_INDEX35 0xF8C // TX Swing Table Lane02-Index35
    #define CND003_PCIEEPHYCFG_FRP02_V0_35_TXPSR   (BIT29 + BIT30 + BIT31) // 011b/011b/x/x PMOS TX Slew Rate Control
    #define CND003_PCIEEPHYCFG_FRP02_V0_35_TXNSR   (BIT26 + BIT27 + BIT28) // 011b/011b/x/x NMOS TX Slew Rate Control
    #define CND003_PCIEEPHYCFG_FRP02_V0_35_TX_DUTY (BIT24 + BIT25)         // 00b/00b/x/x TX Clock Duty Control
    #define CND003_PCIEEPHYCFG_RSV02_0F8C_22       (BIT22 + BIT23)         // 0/0/x/x Reserved
    #define CND003_PCIEEPHYCFG_FRP02_V0_35_TDNCIS  0x3F0000                // 000000b/000000b/x/x TX De-emphasis Set
    #define CND003_PCIEEPHYCFG_RSV02_0F8C_13       (BIT13 + BIT14 + BIT15) // 0/0/x/x Reserved
    #define CND003_PCIEEPHYCFG_FRP02_V0_35_TDCIS   0x1F00                  // 11100b/11100b/x/x TX Bias Control Set
    #define CND003_PCIEEPHYCFG_RSV02_0F8C_6        (BIT6 + BIT7)           // 0/0/x/x Reserved
    #define CND003_PCIEEPHYCFG_FRP02_V0_35_TDPCIS  0x3F                    // 101010b/101010b/x/x TX Preshoot Set
#define CND003_PCIEEPHYCFG_TX_SWING_TABLE_LANE02_INDEX36 0xF90 // TX Swing Table Lane02-Index36
    #define CND003_PCIEEPHYCFG_FRP02_V0_36_TXPSR   (BIT29 + BIT30 + BIT31) // 011b/011b/x/x PMOS TX Slew Rate Control
    #define CND003_PCIEEPHYCFG_FRP02_V0_36_TXNSR   (BIT26 + BIT27 + BIT28) // 011b/011b/x/x NMOS TX Slew Rate Control
    #define CND003_PCIEEPHYCFG_FRP02_V0_36_TX_DUTY (BIT24 + BIT25)         // 00b/00b/x/x TX Clock Duty Control
    #define CND003_PCIEEPHYCFG_RSV02_0F90_22       (BIT22 + BIT23)         // 0/0/x/x Reserved
    #define CND003_PCIEEPHYCFG_FRP02_V0_36_TDNCIS  0x3F0000                // 001000b/001000b/x/x TX De-emphasis Set
    #define CND003_PCIEEPHYCFG_RSV02_0F90_13       (BIT13 + BIT14 + BIT15) // 0/0/x/x Reserved
    #define CND003_PCIEEPHYCFG_FRP02_V0_36_TDCIS   0x1F00                  // 11011b/11011b/x/x TX Bias Control Set
    #define CND003_PCIEEPHYCFG_RSV02_0F90_6        (BIT6 + BIT7)           // 0/0/x/x Reserved
    #define CND003_PCIEEPHYCFG_FRP02_V0_36_TDPCIS  0x3F                    // 101010b/101010b/x/x TX Preshoot Set
#define CND003_PCIEEPHYCFG_TX_SWING_TABLE_LANE02_INDEX37 0xF94 // TX Swing Table Lane02-Index37
    #define CND003_PCIEEPHYCFG_FRP02_V0_37_TXPSR   (BIT29 + BIT30 + BIT31) // 011b/011b/x/x PMOS TX Slew Rate Control
    #define CND003_PCIEEPHYCFG_FRP02_V0_37_TXNSR   (BIT26 + BIT27 + BIT28) // 011b/011b/x/x NMOS TX Slew Rate Control
    #define CND003_PCIEEPHYCFG_FRP02_V0_37_TX_DUTY (BIT24 + BIT25)         // 00b/00b/x/x TX Clock Duty Control
    #define CND003_PCIEEPHYCFG_RSV02_0F94_22       (BIT22 + BIT23)         // 0/0/x/x Reserved
    #define CND003_PCIEEPHYCFG_FRP02_V0_37_TDNCIS  0x3F0000                // 010001b/010001b/x/x TX De-emphasis Set
    #define CND003_PCIEEPHYCFG_RSV02_0F94_13       (BIT13 + BIT14 + BIT15) // 0/0/x/x Reserved
    #define CND003_PCIEEPHYCFG_FRP02_V0_37_TDCIS   0x1F00                  // 11011b/11011b/x/x TX Bias Control Set
    #define CND003_PCIEEPHYCFG_RSV02_0F94_6        (BIT6 + BIT7)           // 0/0/x/x Reserved
    #define CND003_PCIEEPHYCFG_FRP02_V0_37_TDPCIS  0x3F                    // 101010b/101010b/x/x TX Preshoot Set
#define CND003_PCIEEPHYCFG_TX_SWING_TABLE_LANE02_INDEX38 0xF98 // TX Swing Table Lane02-Index38
    #define CND003_PCIEEPHYCFG_FRP02_V0_38_TXPSR   (BIT29 + BIT30 + BIT31) // 011b/011b/x/x PMOS TX Slew Rate Control
    #define CND003_PCIEEPHYCFG_FRP02_V0_38_TXNSR   (BIT26 + BIT27 + BIT28) // 011b/011b/x/x NMOS TX Slew Rate Control
    #define CND003_PCIEEPHYCFG_FRP02_V0_38_TX_DUTY (BIT24 + BIT25)         // 00b/00b/x/x TX Clock Duty Control
    #define CND003_PCIEEPHYCFG_RSV02_0F98_22       (BIT22 + BIT23)         // 0/0/x/x Reserved
    #define CND003_PCIEEPHYCFG_FRP02_V0_38_TDNCIS  0x3F0000                // 011010b/011010b/x/x TX De-emphasis Set
    #define CND003_PCIEEPHYCFG_RSV02_0F98_13       (BIT13 + BIT14 + BIT15) // 0/0/x/x Reserved
    #define CND003_PCIEEPHYCFG_FRP02_V0_38_TDCIS   0x1F00                  // 11010b/11010b/x/x TX Bias Control Set
    #define CND003_PCIEEPHYCFG_RSV02_0F98_6        (BIT6 + BIT7)           // 0/0/x/x Reserved
    #define CND003_PCIEEPHYCFG_FRP02_V0_38_TDPCIS  0x3F                    // 101010b/101010b/x/x TX Preshoot Set
#define CND003_PCIEEPHYCFG_TX_SWING_TABLE_LANE02_INDEX39 0xF9C // TX Swing Table Lane02-Index39
    #define CND003_PCIEEPHYCFG_FRP02_V0_39_TXPSR   (BIT29 + BIT30 + BIT31) // 011b/011b/x/x PMOS TX Slew Rate Control
    #define CND003_PCIEEPHYCFG_FRP02_V0_39_TXNSR   (BIT26 + BIT27 + BIT28) // 011b/011b/x/x NMOS TX Slew Rate Control
    #define CND003_PCIEEPHYCFG_FRP02_V0_39_TX_DUTY (BIT24 + BIT25)         // 00b/00b/x/x TX Clock Duty Control
    #define CND003_PCIEEPHYCFG_RSV02_0F9C_22       (BIT22 + BIT23)         // 0/0/x/x Reserved
    #define CND003_PCIEEPHYCFG_FRP02_V0_39_TDNCIS  0x3F0000                // 000000b/000000b/x/x TX De-emphasis Set
    #define CND003_PCIEEPHYCFG_RSV02_0F9C_13       (BIT13 + BIT14 + BIT15) // 0/0/x/x Reserved
    #define CND003_PCIEEPHYCFG_FRP02_V0_39_TDCIS   0x1F00                  // 11011b/11011b/x/x TX Bias Control Set
    #define CND003_PCIEEPHYCFG_RSV02_0F9C_6        (BIT6 + BIT7)           // 0/0/x/x Reserved
    #define CND003_PCIEEPHYCFG_FRP02_V0_39_TDPCIS  0x3F                    // 110010b/110010b/x/x TX Preshoot Set
#define CND003_PCIEEPHYCFG_TX_SWING_TABLE_LANE02_40 0xFA0 // TX Swing Table Lane02-40
    #define CND003_PCIEEPHYCFG_FRP02_V0_40_TXPSR   (BIT29 + BIT30 + BIT31) // 011b/011b/x/x PMOS TX Slew Rate Control
    #define CND003_PCIEEPHYCFG_FRP02_V0_40_TXNSR   (BIT26 + BIT27 + BIT28) // 011b/011b/x/x NMOS TX Slew Rate Control
    #define CND003_PCIEEPHYCFG_FRP02_V0_40_TX_DUTY (BIT24 + BIT25)         // 00b/00b/x/x TX Clock Duty Control
    #define CND003_PCIEEPHYCFG_RSV02_0FA0_22       (BIT22 + BIT23)         // 0/0/x/x Reserved
    #define CND003_PCIEEPHYCFG_FRP02_V0_40_TDNCIS  0x3F0000                // 001001b/001001b/x/x TX De-emphasis Set
    #define CND003_PCIEEPHYCFG_RSV02_0FA0_13       (BIT13 + BIT14 + BIT15) // 0/0/x/x Reserved
    #define CND003_PCIEEPHYCFG_FRP02_V0_40_TDCIS   0x1F00                  // 11011b/11011b/x/x TX Bias Control Set
    #define CND003_PCIEEPHYCFG_RSV02_0FA0_6        (BIT6 + BIT7)           // 0/0/x/x Reserved
    #define CND003_PCIEEPHYCFG_FRP02_V0_40_TDPCIS  0x3F                    // 110010b/110010b/x/x TX Preshoot Set
#define CND003_PCIEEPHYCFG_TX_SWING_TABLE_LANE02_41 0xFA4 // TX Swing Table Lane02-41
    #define CND003_PCIEEPHYCFG_FRP02_V0_41_TXPSR   (BIT29 + BIT30 + BIT31) // 011b/011b/x/x PMOS TX Slew Rate Control
    #define CND003_PCIEEPHYCFG_FRP02_V0_41_TXNSR   (BIT26 + BIT27 + BIT28) // 011b/011b/x/x NMOS TX Slew Rate Control
    #define CND003_PCIEEPHYCFG_FRP02_V0_41_TX_DUTY (BIT24 + BIT25)         // 00b/00b/x/x TX Clock Duty Control
    #define CND003_PCIEEPHYCFG_RSV02_0FA4_22       (BIT22 + BIT23)         // 0/0/x/x Reserved
    #define CND003_PCIEEPHYCFG_FRP02_V0_41_TDNCIS  0x3F0000                // 010001b/010001b/x/x TX De-emphasis Set
    #define CND003_PCIEEPHYCFG_RSV02_0FA4_13       (BIT13 + BIT14 + BIT15) // 0/0/x/x Reserved
    #define CND003_PCIEEPHYCFG_FRP02_V0_41_TDCIS   0x1F00                  // 11010b/11010b/x/x TX Bias Control Set
    #define CND003_PCIEEPHYCFG_RSV02_0FA4_6        (BIT6 + BIT7)           // 0/0/x/x Reserved
    #define CND003_PCIEEPHYCFG_FRP02_V0_41_TDPCIS  0x3F                    // 110010b/110010b/x/x TX Preshoot Set
#define CND003_PCIEEPHYCFG_TX_SWING_TABLE_LANE03_INDEX00 0x1000 // TX Swing Table Lane03-Index00
    #define CND003_PCIEEPHYCFG_FRP03_V0_00_TXPSR   (BIT29 + BIT30 + BIT31) // 011b/011b/x/x PMOS TX Slew Rate Control
    #define CND003_PCIEEPHYCFG_FRP03_V0_00_TXNSR   (BIT26 + BIT27 + BIT28) // 011b/011b/x/x NMOS TX Slew Rate Control
    #define CND003_PCIEEPHYCFG_FRP03_V0_00_TX_DUTY (BIT24 + BIT25)         // 00b/00b/x/x TX Clock Duty Control
    #define CND003_PCIEEPHYCFG_RSV03_1000_22       (BIT22 + BIT23)         // 0/0/x/x Reserved
    #define CND003_PCIEEPHYCFG_FRP03_V0_00_TDNCIS  0x3F0000                // 000000b/000000b/x/x TX De-emphasis Set
    #define CND003_PCIEEPHYCFG_RSV03_1000_13       (BIT13 + BIT14 + BIT15) // 0/0/x/x Reserved
    #define CND003_PCIEEPHYCFG_FRP03_V0_00_TDCIS   0x1F00                  // 10100b/10100b/x/x TX Bias Control Set
    #define CND003_PCIEEPHYCFG_RSV03_1000_6        (BIT6 + BIT7)           // 0/0/x/x Reserved
    #define CND003_PCIEEPHYCFG_FRP03_V0_00_TDPCIS  0x3F                    // 000000b/000000b/x/x TX Preshoot Set
#define CND003_PCIEEPHYCFG_TX_SWING_TABLE_LANE03_INDEX01 0x1004 // TX Swing Table Lane03-Index01
    #define CND003_PCIEEPHYCFG_FRP03_V0_01_TXPSR   (BIT29 + BIT30 + BIT31) // 011b/011b/x/x PMOS TX Slew Rate Control
    #define CND003_PCIEEPHYCFG_FRP03_V0_01_TXNSR   (BIT26 + BIT27 + BIT28) // 011b/011b/x/x NMOS TX Slew Rate Control
    #define CND003_PCIEEPHYCFG_FRP03_V0_01_TX_DUTY (BIT24 + BIT25)         // 00b/00b/x/x TX Clock Duty Control
    #define CND003_PCIEEPHYCFG_RSV03_1004_22       (BIT22 + BIT23)         // 0/0/x/x Reserved
    #define CND003_PCIEEPHYCFG_FRP03_V0_01_TDNCIS  0x3F0000                // 001001b/001001b/x/x TX De-emphasis Set
    #define CND003_PCIEEPHYCFG_RSV03_1004_13       (BIT13 + BIT14 + BIT15) // 0/0/x/x Reserved
    #define CND003_PCIEEPHYCFG_FRP03_V0_01_TDCIS   0x1F00                  // 11111b/11111b/x/x TX Bias Control Set
    #define CND003_PCIEEPHYCFG_RSV03_1004_6        (BIT6 + BIT7)           // 0/0/x/x Reserved
    #define CND003_PCIEEPHYCFG_FRP03_V0_01_TDPCIS  0x3F                    // 000000b/000000b/x/x TX Preshoot Set
#define CND003_PCIEEPHYCFG_TX_SWING_TABLE_LANE03_INDEX02 0x1008 // TX Swing Table Lane03-Index02
    #define CND003_PCIEEPHYCFG_FRP03_V0_02_TXPSR   (BIT29 + BIT30 + BIT31) // 011b/011b/x/x PMOS TX Slew Rate Control
    #define CND003_PCIEEPHYCFG_FRP03_V0_02_TXNSR   (BIT26 + BIT27 + BIT28) // 011b/011b/x/x NMOS TX Slew Rate Control
    #define CND003_PCIEEPHYCFG_FRP03_V0_02_TX_DUTY (BIT24 + BIT25)         // 00b/00b/x/x TX Clock Duty Control
    #define CND003_PCIEEPHYCFG_RSV03_1008_22       (BIT22 + BIT23)         // 0/0/x/x Reserved
    #define CND003_PCIEEPHYCFG_FRP03_V0_02_TDNCIS  0x3F0000                // 010010b/010010b/x/x TX De-emphasis Set
    #define CND003_PCIEEPHYCFG_RSV03_1008_13       (BIT13 + BIT14 + BIT15) // 0/0/x/x Reserved
    #define CND003_PCIEEPHYCFG_FRP03_V0_02_TDCIS   0x1F00                  // 11111b/11111b/x/x TX Bias Control Set
    #define CND003_PCIEEPHYCFG_RSV03_1008_6        (BIT6 + BIT7)           // 0/0/x/x Reserved
    #define CND003_PCIEEPHYCFG_FRP03_V0_02_TDPCIS  0x3F                    // 000000b/000000b/x/x TX Preshoot Set
#define CND003_PCIEEPHYCFG_TX_SWING_TABLE_LANE03_INDEX03 0x100C // TX Swing Table Lane03-Index03
    #define CND003_PCIEEPHYCFG_FRP03_V0_03_TXPSR   (BIT29 + BIT30 + BIT31) // 011b/011b/x/x PMOS TX Slew Rate Control
    #define CND003_PCIEEPHYCFG_FRP03_V0_03_TXNSR   (BIT26 + BIT27 + BIT28) // 011b/011b/x/x NMOS TX Slew Rate Control
    #define CND003_PCIEEPHYCFG_FRP03_V0_03_TX_DUTY (BIT24 + BIT25)         // 00b/00b/x/x TX Clock Duty Control
    #define CND003_PCIEEPHYCFG_RSV03_100C_22       (BIT22 + BIT23)         // 0/0/x/x Reserved
    #define CND003_PCIEEPHYCFG_FRP03_V0_03_TDNCIS  0x3F0000                // 011010b/011010b/x/x TX De-emphasis Set
    #define CND003_PCIEEPHYCFG_RSV03_100C_13       (BIT13 + BIT14 + BIT15) // 0/0/x/x Reserved
    #define CND003_PCIEEPHYCFG_FRP03_V0_03_TDCIS   0x1F00                  // 11110b/11110b/x/x TX Bias Control Set
    #define CND003_PCIEEPHYCFG_RSV03_100C_6        (BIT6 + BIT7)           // 0/0/x/x Reserved
    #define CND003_PCIEEPHYCFG_FRP03_V0_03_TDPCIS  0x3F                    // 000000b/000000b/x/x TX Preshoot Set
#define CND003_PCIEEPHYCFG_TX_SWING_TABLE_LANE03_INDEX04 0x1010 // TX Swing Table Lane03-Index04
    #define CND003_PCIEEPHYCFG_FRP03_V0_04_TXPSR   (BIT29 + BIT30 + BIT31) // 011b/011b/x/x PMOS TX Slew Rate Control
    #define CND003_PCIEEPHYCFG_FRP03_V0_04_TXNSR   (BIT26 + BIT27 + BIT28) // 011b/011b/x/x NMOS TX Slew Rate Control
    #define CND003_PCIEEPHYCFG_FRP03_V0_04_TX_DUTY (BIT24 + BIT25)         // 00b/00b/x/x TX Clock Duty Control
    #define CND003_PCIEEPHYCFG_RSV03_1010_22       (BIT22 + BIT23)         // 0/0/x/x Reserved
    #define CND003_PCIEEPHYCFG_FRP03_V0_04_TDNCIS  0x3F0000                // 100010b/100010b/x/x TX De-emphasis Set
    #define CND003_PCIEEPHYCFG_RSV03_1010_13       (BIT13 + BIT14 + BIT15) // 0/0/x/x Reserved
    #define CND003_PCIEEPHYCFG_FRP03_V0_04_TDCIS   0x1F00                  // 11101b/11101b/x/x TX Bias Control Set
    #define CND003_PCIEEPHYCFG_RSV03_1010_6        (BIT6 + BIT7)           // 0/0/x/x Reserved
    #define CND003_PCIEEPHYCFG_FRP03_V0_04_TDPCIS  0x3F                    // 000000b/000000b/x/x TX Preshoot Set
#define CND003_PCIEEPHYCFG_TX_SWING_TABLE_LANE03_INDEX05 0x1014 // TX Swing Table Lane03-Index05
    #define CND003_PCIEEPHYCFG_FRP03_V0_05_TXPSR   (BIT29 + BIT30 + BIT31) // 011b/011b/x/x PMOS TX Slew Rate Control
    #define CND003_PCIEEPHYCFG_FRP03_V0_05_TXNSR   (BIT26 + BIT27 + BIT28) // 011b/011b/x/x NMOS TX Slew Rate Control
    #define CND003_PCIEEPHYCFG_FRP03_V0_05_TX_DUTY (BIT24 + BIT25)         // 00b/00b/x/x TX Clock Duty Control
    #define CND003_PCIEEPHYCFG_RSV03_1014_22       (BIT22 + BIT23)         // 0/0/x/x Reserved
    #define CND003_PCIEEPHYCFG_FRP03_V0_05_TDNCIS  0x3F0000                // 101010b/101010b/x/x TX De-emphasis Set
    #define CND003_PCIEEPHYCFG_RSV03_1014_13       (BIT13 + BIT14 + BIT15) // 0/0/x/x Reserved
    #define CND003_PCIEEPHYCFG_FRP03_V0_05_TDCIS   0x1F00                  // 11100b/11100b/x/x TX Bias Control Set
    #define CND003_PCIEEPHYCFG_RSV03_1014_6        (BIT6 + BIT7)           // 0/0/x/x Reserved
    #define CND003_PCIEEPHYCFG_FRP03_V0_05_TDPCIS  0x3F                    // 000000b/000000b/x/x TX Preshoot Set
#define CND003_PCIEEPHYCFG_TX_SWING_TABLE_LANE03_INDEX06 0x1018 // TX Swing Table Lane03-Index06
    #define CND003_PCIEEPHYCFG_FRP03_V0_06_TXPSR   (BIT29 + BIT30 + BIT31) // 011b/011b/x/x PMOS TX Slew Rate Control
    #define CND003_PCIEEPHYCFG_FRP03_V0_06_TXNSR   (BIT26 + BIT27 + BIT28) // 011b/011b/x/x NMOS TX Slew Rate Control
    #define CND003_PCIEEPHYCFG_FRP03_V0_06_TX_DUTY (BIT24 + BIT25)         // 00b/00b/x/x TX Clock Duty Control
    #define CND003_PCIEEPHYCFG_RSV03_1018_22       (BIT22 + BIT23)         // 0/0/x/x Reserved
    #define CND003_PCIEEPHYCFG_FRP03_V0_06_TDNCIS  0x3F0000                // 110010b/110010b/x/x TX De-emphasis Set
    #define CND003_PCIEEPHYCFG_RSV03_1018_13       (BIT13 + BIT14 + BIT15) // 0/0/x/x Reserved
    #define CND003_PCIEEPHYCFG_FRP03_V0_06_TDCIS   0x1F00                  // 11011b/11011b/x/x TX Bias Control Set
    #define CND003_PCIEEPHYCFG_RSV03_1018_6        (BIT6 + BIT7)           // 0/0/x/x Reserved
    #define CND003_PCIEEPHYCFG_FRP03_V0_06_TDPCIS  0x3F                    // 000000b/000000b/x/x TX Preshoot Set
#define CND003_PCIEEPHYCFG_TX_SWING_TABLE_LANE03_INDEX07 0x101C // TX Swing Table Lane03-Index07
    #define CND003_PCIEEPHYCFG_FRP03_V0_07_TXPSR   (BIT29 + BIT30 + BIT31) // 011b/011b/x/x PMOS TX Slew Rate Control
    #define CND003_PCIEEPHYCFG_FRP03_V0_07_TXNSR   (BIT26 + BIT27 + BIT28) // 011b/011b/x/x NMOS TX Slew Rate Control
    #define CND003_PCIEEPHYCFG_FRP03_V0_07_TX_DUTY (BIT24 + BIT25)         // 00b/00b/x/x TX Clock Duty Control
    #define CND003_PCIEEPHYCFG_RSV03_101C_22       (BIT22 + BIT23)         // 0/0/x/x Reserved
    #define CND003_PCIEEPHYCFG_FRP03_V0_07_TDNCIS  0x3F0000                // 111101b/111101b/x/x TX De-emphasis Set
    #define CND003_PCIEEPHYCFG_RSV03_101C_13       (BIT13 + BIT14 + BIT15) // 0/0/x/x Reserved
    #define CND003_PCIEEPHYCFG_FRP03_V0_07_TDCIS   0x1F00                  // 11011b/11011b/x/x TX Bias Control Set
    #define CND003_PCIEEPHYCFG_RSV03_101C_6        (BIT6 + BIT7)           // 0/0/x/x Reserved
    #define CND003_PCIEEPHYCFG_FRP03_V0_07_TDPCIS  0x3F                    // 000000b/000000b/x/x TX Preshoot Set
#define CND003_PCIEEPHYCFG_TX_SWING_TABLE_LANE03_INDEX08 0x1020 // TX Swing Table Lane03-Index08
    #define CND003_PCIEEPHYCFG_FRP03_V0_08_TXPSR   (BIT29 + BIT30 + BIT31) // 011b/011b/x/x PMOS TX Slew Rate Control
    #define CND003_PCIEEPHYCFG_FRP03_V0_08_TXNSR   (BIT26 + BIT27 + BIT28) // 011b/011b/x/x NMOS TX Slew Rate Control
    #define CND003_PCIEEPHYCFG_FRP03_V0_08_TX_DUTY (BIT24 + BIT25)         // 00b/00b/x/x TX Clock Duty Control
    #define CND003_PCIEEPHYCFG_RSV03_1020_22       (BIT22 + BIT23)         // 0/0/x/x Reserved
    #define CND003_PCIEEPHYCFG_FRP03_V0_08_TDNCIS  0x3F0000                // 111111b/111111b/x/x TX De-emphasis Set
    #define CND003_PCIEEPHYCFG_RSV03_1020_13       (BIT13 + BIT14 + BIT15) // 0/0/x/x Reserved
    #define CND003_PCIEEPHYCFG_FRP03_V0_08_TDCIS   0x1F00                  // 11001b/11001b/x/x TX Bias Control Set
    #define CND003_PCIEEPHYCFG_RSV03_1020_6        (BIT6 + BIT7)           // 0/0/x/x Reserved
    #define CND003_PCIEEPHYCFG_FRP03_V0_08_TDPCIS  0x3F                    // 000000b/000000b/x/x TX Preshoot Set
#define CND003_PCIEEPHYCFG_TX_SWING_TABLE_LANE03_INDEX09 0x1024 // TX Swing Table Lane03-Index09
    #define CND003_PCIEEPHYCFG_FRP03_V0_09_TXPSR   (BIT29 + BIT30 + BIT31) // 011b/011b/x/x PMOS TX Slew Rate Control
    #define CND003_PCIEEPHYCFG_FRP03_V0_09_TXNSR   (BIT26 + BIT27 + BIT28) // 011b/011b/x/x NMOS TX Slew Rate Control
    #define CND003_PCIEEPHYCFG_FRP03_V0_09_TX_DUTY (BIT24 + BIT25)         // 00b/00b/x/x TX Clock Duty Control
    #define CND003_PCIEEPHYCFG_RSV03_1024_22       (BIT22 + BIT23)         // 0/0/x/x Reserved
    #define CND003_PCIEEPHYCFG_FRP03_V0_09_TDNCIS  0x3F0000                // 000000b/000000b/x/x TX De-emphasis Set
    #define CND003_PCIEEPHYCFG_RSV03_1024_13       (BIT13 + BIT14 + BIT15) // 0/0/x/x Reserved
    #define CND003_PCIEEPHYCFG_FRP03_V0_09_TDCIS   0x1F00                  // 11111b/11111b/x/x TX Bias Control Set
    #define CND003_PCIEEPHYCFG_RSV03_1024_6        (BIT6 + BIT7)           // 0/0/x/x Reserved
    #define CND003_PCIEEPHYCFG_FRP03_V0_09_TDPCIS  0x3F                    // 001001b/001001b/x/x TX Preshoot Set
#define CND003_PCIEEPHYCFG_TX_SWING_TABLE_LANE03_INDEX10 0x1028 // TX Swing Table Lane03-Index10
    #define CND003_PCIEEPHYCFG_FRP03_V0_10_TXPSR   (BIT29 + BIT30 + BIT31) // 011b/011b/x/x PMOS TX Slew Rate Control
    #define CND003_PCIEEPHYCFG_FRP03_V0_10_TXNSR   (BIT26 + BIT27 + BIT28) // 011b/011b/x/x NMOS TX Slew Rate Control
    #define CND003_PCIEEPHYCFG_FRP03_V0_10_TX_DUTY (BIT24 + BIT25)         // 00b/00b/x/x TX Clock Duty Control
    #define CND003_PCIEEPHYCFG_RSV03_1028_22       (BIT22 + BIT23)         // 0/0/x/x Reserved
    #define CND003_PCIEEPHYCFG_FRP03_V0_10_TDNCIS  0x3F0000                // 001001b/001001b/x/x TX De-emphasis Set
    #define CND003_PCIEEPHYCFG_RSV03_1028_13       (BIT13 + BIT14 + BIT15) // 0/0/x/x Reserved
    #define CND003_PCIEEPHYCFG_FRP03_V0_10_TDCIS   0x1F00                  // 11111b/11111b/x/x TX Bias Control Set
    #define CND003_PCIEEPHYCFG_RSV03_1028_6        (BIT6 + BIT7)           // 0/0/x/x Reserved
    #define CND003_PCIEEPHYCFG_FRP03_V0_10_TDPCIS  0x3F                    // 001001b/001001b/x/x TX Preshoot Set
#define CND003_PCIEEPHYCFG_TX_SWING_TABLE_LANE03_INDEX11 0x102C // TX Swing Table Lane03-Index11
    #define CND003_PCIEEPHYCFG_FRP03_V0_11_TXPSR   (BIT29 + BIT30 + BIT31) // 011b/011b/x/x PMOS TX Slew Rate Control
    #define CND003_PCIEEPHYCFG_FRP03_V0_11_TXNSR   (BIT26 + BIT27 + BIT28) // 011b/011b/x/x NMOS TX Slew Rate Control
    #define CND003_PCIEEPHYCFG_FRP03_V0_11_TX_DUTY (BIT24 + BIT25)         // 00b/00b/x/x TX Clock Duty Control
    #define CND003_PCIEEPHYCFG_RSV03_102C_22       (BIT22 + BIT23)         // 0/0/x/x Reserved
    #define CND003_PCIEEPHYCFG_FRP03_V0_11_TDNCIS  0x3F0000                // 010001b/010001b/x/x TX De-emphasis Set
    #define CND003_PCIEEPHYCFG_RSV03_102C_13       (BIT13 + BIT14 + BIT15) // 0/0/x/x Reserved
    #define CND003_PCIEEPHYCFG_FRP03_V0_11_TDCIS   0x1F00                  // 11110b/11110b/x/x TX Bias Control Set
    #define CND003_PCIEEPHYCFG_RSV03_102C_6        (BIT6 + BIT7)           // 0/0/x/x Reserved
    #define CND003_PCIEEPHYCFG_FRP03_V0_11_TDPCIS  0x3F                    // 001001b/001001b/x/x TX Preshoot Set
#define CND003_PCIEEPHYCFG_TX_SWING_TABLE_LANE03_INDEX12 0x1030 // TX Swing Table Lane03-Index12
    #define CND003_PCIEEPHYCFG_FRP03_V0_12_TXPSR   (BIT29 + BIT30 + BIT31) // 011b/011b/x/x PMOS TX Slew Rate Control
    #define CND003_PCIEEPHYCFG_FRP03_V0_12_TXNSR   (BIT26 + BIT27 + BIT28) // 011b/011b/x/x NMOS TX Slew Rate Control
    #define CND003_PCIEEPHYCFG_FRP03_V0_12_TX_DUTY (BIT24 + BIT25)         // 00b/00b/x/x TX Clock Duty Control
    #define CND003_PCIEEPHYCFG_RSV03_1030_22       (BIT22 + BIT23)         // 0/0/x/x Reserved
    #define CND003_PCIEEPHYCFG_FRP03_V0_12_TDNCIS  0x3F0000                // 011010b/011010b/x/x TX De-emphasis Set
    #define CND003_PCIEEPHYCFG_RSV03_1030_13       (BIT13 + BIT14 + BIT15) // 0/0/x/x Reserved
    #define CND003_PCIEEPHYCFG_FRP03_V0_12_TDCIS   0x1F00                  // 11101b/11101b/x/x TX Bias Control Set
    #define CND003_PCIEEPHYCFG_RSV03_1030_6        (BIT6 + BIT7)           // 0/0/x/x Reserved
    #define CND003_PCIEEPHYCFG_FRP03_V0_12_TDPCIS  0x3F                    // 001001b/001001b/x/x TX Preshoot Set
#define CND003_PCIEEPHYCFG_TX_SWING_TABLE_LANE03_INDEX13 0x1034 // TX Swing Table Lane03-Index13
    #define CND003_PCIEEPHYCFG_FRP03_V0_13_TXPSR   (BIT29 + BIT30 + BIT31) // 011b/011b/x/x PMOS TX Slew Rate Control
    #define CND003_PCIEEPHYCFG_FRP03_V0_13_TXNSR   (BIT26 + BIT27 + BIT28) // 011b/011b/x/x NMOS TX Slew Rate Control
    #define CND003_PCIEEPHYCFG_FRP03_V0_13_TX_DUTY (BIT24 + BIT25)         // 00b/00b/x/x TX Clock Duty Control
    #define CND003_PCIEEPHYCFG_RSV03_1034_22       (BIT22 + BIT23)         // 0/0/x/x Reserved
    #define CND003_PCIEEPHYCFG_FRP03_V0_13_TDNCIS  0x3F0000                // 100010b/100010b/x/x TX De-emphasis Set
    #define CND003_PCIEEPHYCFG_RSV03_1034_13       (BIT13 + BIT14 + BIT15) // 0/0/x/x Reserved
    #define CND003_PCIEEPHYCFG_FRP03_V0_13_TDCIS   0x1F00                  // 11100b/11100b/x/x TX Bias Control Set
    #define CND003_PCIEEPHYCFG_RSV03_1034_6        (BIT6 + BIT7)           // 0/0/x/x Reserved
    #define CND003_PCIEEPHYCFG_FRP03_V0_13_TDPCIS  0x3F                    // 001001b/001001b/x/x TX Preshoot Set
#define CND003_PCIEEPHYCFG_TX_SWING_TABLE_LANE03_INDEX14 0x1038 // TX Swing Table Lane03-Index14
    #define CND003_PCIEEPHYCFG_FRP03_V0_14_TXPSR   (BIT29 + BIT30 + BIT31) // 011b/011b/x/x PMOS TX Slew Rate Control
    #define CND003_PCIEEPHYCFG_FRP03_V0_14_TXNSR   (BIT26 + BIT27 + BIT28) // 011b/011b/x/x NMOS TX Slew Rate Control
    #define CND003_PCIEEPHYCFG_FRP03_V0_14_TX_DUTY (BIT24 + BIT25)         // 00b/00b/x/x TX Clock Duty Control
    #define CND003_PCIEEPHYCFG_RSV03_1038_22       (BIT22 + BIT23)         // 0/0/x/x Reserved
    #define CND003_PCIEEPHYCFG_FRP03_V0_14_TDNCIS  0x3F0000                // 101010b/101010b/x/x TX De-emphasis Set
    #define CND003_PCIEEPHYCFG_RSV03_1038_13       (BIT13 + BIT14 + BIT15) // 0/0/x/x Reserved
    #define CND003_PCIEEPHYCFG_FRP03_V0_14_TDCIS   0x1F00                  // 11011b/11011b/x/x TX Bias Control Set
    #define CND003_PCIEEPHYCFG_RSV03_1038_6        (BIT6 + BIT7)           // 0/0/x/x Reserved
    #define CND003_PCIEEPHYCFG_FRP03_V0_14_TDPCIS  0x3F                    // 001001b/001001b/x/x TX Preshoot Set
#define CND003_PCIEEPHYCFG_TX_SWING_TABLE_LANE03_INDEX15 0x103C // TX Swing Table Lane03-Index15
    #define CND003_PCIEEPHYCFG_FRP03_V0_15_TXPSR   (BIT29 + BIT30 + BIT31) // 011b/011b/x/x PMOS TX Slew Rate Control
    #define CND003_PCIEEPHYCFG_FRP03_V0_15_TXNSR   (BIT26 + BIT27 + BIT28) // 011b/011b/x/x NMOS TX Slew Rate Control
    #define CND003_PCIEEPHYCFG_FRP03_V0_15_TX_DUTY (BIT24 + BIT25)         // 00b/00b/x/x TX Clock Duty Control
    #define CND003_PCIEEPHYCFG_RSV03_103C_22       (BIT22 + BIT23)         // 0/0/x/x Reserved
    #define CND003_PCIEEPHYCFG_FRP03_V0_15_TDNCIS  0x3F0000                // 110010b/110010b/x/x TX De-emphasis Set
    #define CND003_PCIEEPHYCFG_RSV03_103C_13       (BIT13 + BIT14 + BIT15) // 0/0/x/x Reserved
    #define CND003_PCIEEPHYCFG_FRP03_V0_15_TDCIS   0x1F00                  // 11011b/11011b/x/x TX Bias Control Set
    #define CND003_PCIEEPHYCFG_RSV03_103C_6        (BIT6 + BIT7)           // 0/0/x/x Reserved
    #define CND003_PCIEEPHYCFG_FRP03_V0_15_TDPCIS  0x3F                    // 001001b/001001b/x/x TX Preshoot Set
#define CND003_PCIEEPHYCFG_TX_SWING_TABLE_LANE03_INDEX16 0x1040 // TX Swing Table Lane03-Index16
    #define CND003_PCIEEPHYCFG_FRP03_V0_16_TXPSR   (BIT29 + BIT30 + BIT31) // 011b/011b/x/x PMOS TX Slew Rate Control
    #define CND003_PCIEEPHYCFG_FRP03_V0_16_TXNSR   (BIT26 + BIT27 + BIT28) // 011b/011b/x/x NMOS TX Slew Rate Control
    #define CND003_PCIEEPHYCFG_FRP03_V0_16_TX_DUTY (BIT24 + BIT25)         // 00b/00b/x/x TX Clock Duty Control
    #define CND003_PCIEEPHYCFG_RSV03_1040_22       (BIT22 + BIT23)         // 0/0/x/x Reserved
    #define CND003_PCIEEPHYCFG_FRP03_V0_16_TDNCIS  0x3F0000                // 111101b/111101b/x/x TX De-emphasis Set
    #define CND003_PCIEEPHYCFG_RSV03_1040_13       (BIT13 + BIT14 + BIT15) // 0/0/x/x Reserved
    #define CND003_PCIEEPHYCFG_FRP03_V0_16_TDCIS   0x1F00                  // 11010b/11010b/x/x TX Bias Control Set
    #define CND003_PCIEEPHYCFG_RSV03_1040_6        (BIT6 + BIT7)           // 0/0/x/x Reserved
    #define CND003_PCIEEPHYCFG_FRP03_V0_16_TDPCIS  0x3F                    // 001001b/001001b/x/x TX Preshoot Set
#define CND003_PCIEEPHYCFG_TX_SWING_TABLE_LANE03_INDEX17 0x1044 // TX Swing Table Lane03-Index17
    #define CND003_PCIEEPHYCFG_FRP03_V0_17_TXPSR   (BIT29 + BIT30 + BIT31) // 011b/011b/x/x PMOS TX Slew Rate Control
    #define CND003_PCIEEPHYCFG_FRP03_V0_17_TXNSR   (BIT26 + BIT27 + BIT28) // 011b/011b/x/x NMOS TX Slew Rate Control
    #define CND003_PCIEEPHYCFG_FRP03_V0_17_TX_DUTY (BIT24 + BIT25)         // 00b/00b/x/x TX Clock Duty Control
    #define CND003_PCIEEPHYCFG_RSV03_1044_22       (BIT22 + BIT23)         // 0/0/x/x Reserved
    #define CND003_PCIEEPHYCFG_FRP03_V0_17_TDNCIS  0x3F0000                // 000000b/000000b/x/x TX De-emphasis Set
    #define CND003_PCIEEPHYCFG_RSV03_1044_13       (BIT13 + BIT14 + BIT15) // 0/0/x/x Reserved
    #define CND003_PCIEEPHYCFG_FRP03_V0_17_TDCIS   0x1F00                  // 11111b/11111b/x/x TX Bias Control Set
    #define CND003_PCIEEPHYCFG_RSV03_1044_6        (BIT6 + BIT7)           // 0/0/x/x Reserved
    #define CND003_PCIEEPHYCFG_FRP03_V0_17_TDPCIS  0x3F                    // 010001b/010001b/x/x TX Preshoot Set
#define CND003_PCIEEPHYCFG_TX_SWING_TABLE_LANE03_INDEX18 0x1048 // TX Swing Table Lane03-Index18
    #define CND003_PCIEEPHYCFG_FRP03_V0_18_TXPSR   (BIT29 + BIT30 + BIT31) // 011b/011b/x/x PMOS TX Slew Rate Control
    #define CND003_PCIEEPHYCFG_FRP03_V0_18_TXNSR   (BIT26 + BIT27 + BIT28) // 011b/011b/x/x NMOS TX Slew Rate Control
    #define CND003_PCIEEPHYCFG_FRP03_V0_18_TX_DUTY (BIT24 + BIT25)         // 00b/00b/x/x TX Clock Duty Control
    #define CND003_PCIEEPHYCFG_RSV03_1048_22       (BIT22 + BIT23)         // 0/0/x/x Reserved
    #define CND003_PCIEEPHYCFG_FRP03_V0_18_TDNCIS  0x3F0000                // 001001b/001001b/x/x TX De-emphasis Set
    #define CND003_PCIEEPHYCFG_RSV03_1048_13       (BIT13 + BIT14 + BIT15) // 0/0/x/x Reserved
    #define CND003_PCIEEPHYCFG_FRP03_V0_18_TDCIS   0x1F00                  // 11110b/11110b/x/x TX Bias Control Set
    #define CND003_PCIEEPHYCFG_RSV03_1048_6        (BIT6 + BIT7)           // 0/0/x/x Reserved
    #define CND003_PCIEEPHYCFG_FRP03_V0_18_TDPCIS  0x3F                    // 010001b/010001b/x/x TX Preshoot Set
#define CND003_PCIEEPHYCFG_TX_SWING_TABLE_LANE03_INDEX19 0x104C // TX Swing Table Lane03-Index19
    #define CND003_PCIEEPHYCFG_FRP03_V0_19_TXPSR   (BIT29 + BIT30 + BIT31) // 011b/011b/x/x PMOS TX Slew Rate Control
    #define CND003_PCIEEPHYCFG_FRP03_V0_19_TXNSR   (BIT26 + BIT27 + BIT28) // 011b/011b/x/x NMOS TX Slew Rate Control
    #define CND003_PCIEEPHYCFG_FRP03_V0_19_TX_DUTY (BIT24 + BIT25)         // 00b/00b/x/x TX Clock Duty Control
    #define CND003_PCIEEPHYCFG_RSV03_104C_22       (BIT22 + BIT23)         // 0/0/x/x Reserved
    #define CND003_PCIEEPHYCFG_FRP03_V0_19_TDNCIS  0x3F0000                // 010001b/010001b/x/x TX De-emphasis Set
    #define CND003_PCIEEPHYCFG_RSV03_104C_13       (BIT13 + BIT14 + BIT15) // 0/0/x/x Reserved
    #define CND003_PCIEEPHYCFG_FRP03_V0_19_TDCIS   0x1F00                  // 11101b/11101b/x/x TX Bias Control Set
    #define CND003_PCIEEPHYCFG_RSV03_104C_6        (BIT6 + BIT7)           // 0/0/x/x Reserved
    #define CND003_PCIEEPHYCFG_FRP03_V0_19_TDPCIS  0x3F                    // 010001b/010001b/x/x TX Preshoot Set
#define CND003_PCIEEPHYCFG_TX_SWING_TABLE_LANE03_INDEX20 0x1050 // TX Swing Table Lane03-Index20
    #define CND003_PCIEEPHYCFG_FRP03_V0_20_TXPSR   (BIT29 + BIT30 + BIT31) // 011b/011b/x/x PMOS TX Slew Rate Control
    #define CND003_PCIEEPHYCFG_FRP03_V0_20_TXNSR   (BIT26 + BIT27 + BIT28) // 011b/011b/x/x NMOS TX Slew Rate Control
    #define CND003_PCIEEPHYCFG_FRP03_V0_20_TX_DUTY (BIT24 + BIT25)         // 00b/00b/x/x TX Clock Duty Control
    #define CND003_PCIEEPHYCFG_RSV03_1050_22       (BIT22 + BIT23)         // 0/0/x/x Reserved
    #define CND003_PCIEEPHYCFG_FRP03_V0_20_TDNCIS  0x3F0000                // 011000b/011000b/x/x TX De-emphasis Set
    #define CND003_PCIEEPHYCFG_RSV03_1050_13       (BIT13 + BIT14 + BIT15) // 0/0/x/x Reserved
    #define CND003_PCIEEPHYCFG_FRP03_V0_20_TDCIS   0x1F00                  // 11100b/11100b/x/x TX Bias Control Set
    #define CND003_PCIEEPHYCFG_RSV03_1050_6        (BIT6 + BIT7)           // 0/0/x/x Reserved
    #define CND003_PCIEEPHYCFG_FRP03_V0_20_TDPCIS  0x3F                    // 010001b/010001b/x/x TX Preshoot Set
#define CND003_PCIEEPHYCFG_TX_SWING_TABLE_LANE03_INDEX21 0x1054 // TX Swing Table Lane03-Index21
    #define CND003_PCIEEPHYCFG_FRP03_V0_21_TXPSR   (BIT29 + BIT30 + BIT31) // 011b/011b/x/x PMOS TX Slew Rate Control
    #define CND003_PCIEEPHYCFG_FRP03_V0_21_TXNSR   (BIT26 + BIT27 + BIT28) // 011b/011b/x/x NMOS TX Slew Rate Control
    #define CND003_PCIEEPHYCFG_FRP03_V0_21_TX_DUTY (BIT24 + BIT25)         // 00b/00b/x/x TX Clock Duty Control
    #define CND003_PCIEEPHYCFG_RSV03_1054_22       (BIT22 + BIT23)         // 0/0/x/x Reserved
    #define CND003_PCIEEPHYCFG_FRP03_V0_21_TDNCIS  0x3F0000                // 100010b/100010b/x/x TX De-emphasis Set
    #define CND003_PCIEEPHYCFG_RSV03_1054_13       (BIT13 + BIT14 + BIT15) // 0/0/x/x Reserved
    #define CND003_PCIEEPHYCFG_FRP03_V0_21_TDCIS   0x1F00                  // 11011b/11011b/x/x TX Bias Control Set
    #define CND003_PCIEEPHYCFG_RSV03_1054_6        (BIT6 + BIT7)           // 0/0/x/x Reserved
    #define CND003_PCIEEPHYCFG_FRP03_V0_21_TDPCIS  0x3F                    // 010001b/010001b/x/x TX Preshoot Set
#define CND003_PCIEEPHYCFG_TX_SWING_TABLE_LANE03_INDEX22 0x1058 // TX Swing Table Lane03-Index22
    #define CND003_PCIEEPHYCFG_FRP03_V0_22_TXPSR   (BIT29 + BIT30 + BIT31) // 011b/011b/x/x PMOS TX Slew Rate Control
    #define CND003_PCIEEPHYCFG_FRP03_V0_22_TXNSR   (BIT26 + BIT27 + BIT28) // 011b/011b/x/x NMOS TX Slew Rate Control
    #define CND003_PCIEEPHYCFG_FRP03_V0_22_TX_DUTY (BIT24 + BIT25)         // 00b/00b/x/x TX Clock Duty Control
    #define CND003_PCIEEPHYCFG_RSV03_1058_22       (BIT22 + BIT23)         // 0/0/x/x Reserved
    #define CND003_PCIEEPHYCFG_FRP03_V0_22_TDNCIS  0x3F0000                // 101100b/101100b/x/x TX De-emphasis Set
    #define CND003_PCIEEPHYCFG_RSV03_1058_13       (BIT13 + BIT14 + BIT15) // 0/0/x/x Reserved
    #define CND003_PCIEEPHYCFG_FRP03_V0_22_TDCIS   0x1F00                  // 11011b/11011b/x/x TX Bias Control Set
    #define CND003_PCIEEPHYCFG_RSV03_1058_6        (BIT6 + BIT7)           // 0/0/x/x Reserved
    #define CND003_PCIEEPHYCFG_FRP03_V0_22_TDPCIS  0x3F                    // 010001b/010001b/x/x TX Preshoot Set
#define CND003_PCIEEPHYCFG_TX_SWING_TABLE_LANE03_INDEX23 0x105C // TX Swing Table Lane03-Index23
    #define CND003_PCIEEPHYCFG_FRP03_V0_23_TXPSR   (BIT29 + BIT30 + BIT31) // 011b/011b/x/x PMOS TX Slew Rate Control
    #define CND003_PCIEEPHYCFG_FRP03_V0_23_TXNSR   (BIT26 + BIT27 + BIT28) // 011b/011b/x/x NMOS TX Slew Rate Control
    #define CND003_PCIEEPHYCFG_FRP03_V0_23_TX_DUTY (BIT24 + BIT25)         // 00b/00b/x/x TX Clock Duty Control
    #define CND003_PCIEEPHYCFG_RSV03_105C_22       (BIT22 + BIT23)         // 0/0/x/x Reserved
    #define CND003_PCIEEPHYCFG_FRP03_V0_23_TDNCIS  0x3F0000                // 110010b/110010b/x/x TX De-emphasis Set
    #define CND003_PCIEEPHYCFG_RSV03_105C_13       (BIT13 + BIT14 + BIT15) // 0/0/x/x Reserved
    #define CND003_PCIEEPHYCFG_FRP03_V0_23_TDCIS   0x1F00                  // 11010b/11010b/x/x TX Bias Control Set
    #define CND003_PCIEEPHYCFG_RSV03_105C_6        (BIT6 + BIT7)           // 0/0/x/x Reserved
    #define CND003_PCIEEPHYCFG_FRP03_V0_23_TDPCIS  0x3F                    // 010001b/010001b/x/x TX Preshoot Set
#define CND003_PCIEEPHYCFG_TX_SWING_TABLE_LANE03_INDEX24 0x1060 // TX Swing Table Lane03-Index24
    #define CND003_PCIEEPHYCFG_FRP03_V0_24_TXPSR   (BIT29 + BIT30 + BIT31) // 011b/011b/x/x PMOS TX Slew Rate Control
    #define CND003_PCIEEPHYCFG_FRP03_V0_24_TXNSR   (BIT26 + BIT27 + BIT28) // 011b/011b/x/x NMOS TX Slew Rate Control
    #define CND003_PCIEEPHYCFG_FRP03_V0_24_TX_DUTY (BIT24 + BIT25)         // 00b/00b/x/x TX Clock Duty Control
    #define CND003_PCIEEPHYCFG_RSV03_1060_22       (BIT22 + BIT23)         // 0/0/x/x Reserved
    #define CND003_PCIEEPHYCFG_FRP03_V0_24_TDNCIS  0x3F0000                // 000000b/000000b/x/x TX De-emphasis Set
    #define CND003_PCIEEPHYCFG_RSV03_1060_13       (BIT13 + BIT14 + BIT15) // 0/0/x/x Reserved
    #define CND003_PCIEEPHYCFG_FRP03_V0_24_TDCIS   0x1F00                  // 11110b/11110b/x/x TX Bias Control Set
    #define CND003_PCIEEPHYCFG_RSV03_1060_6        (BIT6 + BIT7)           // 0/0/x/x Reserved
    #define CND003_PCIEEPHYCFG_FRP03_V0_24_TDPCIS  0x3F                    // 011010b/011010b/x/x TX Preshoot Set
#define CND003_PCIEEPHYCFG_TX_SWING_TABLE_LANE03_INDEX25 0x1064 // TX Swing Table Lane03-Index25
    #define CND003_PCIEEPHYCFG_FRP03_V0_25_TXPSR   (BIT29 + BIT30 + BIT31) // 011b/011b/x/x PMOS TX Slew Rate Control
    #define CND003_PCIEEPHYCFG_FRP03_V0_25_TXNSR   (BIT26 + BIT27 + BIT28) // 011b/011b/x/x NMOS TX Slew Rate Control
    #define CND003_PCIEEPHYCFG_FRP03_V0_25_TX_DUTY (BIT24 + BIT25)         // 00b/00b/x/x TX Clock Duty Control
    #define CND003_PCIEEPHYCFG_RSV03_1064_22       (BIT22 + BIT23)         // 0/0/x/x Reserved
    #define CND003_PCIEEPHYCFG_FRP03_V0_25_TDNCIS  0x3F0000                // 001001b/001001b/x/x TX De-emphasis Set
    #define CND003_PCIEEPHYCFG_RSV03_1064_13       (BIT13 + BIT14 + BIT15) // 0/0/x/x Reserved
    #define CND003_PCIEEPHYCFG_FRP03_V0_25_TDCIS   0x1F00                  // 11101b/11101b/x/x TX Bias Control Set
    #define CND003_PCIEEPHYCFG_RSV03_1064_6        (BIT6 + BIT7)           // 0/0/x/x Reserved
    #define CND003_PCIEEPHYCFG_FRP03_V0_25_TDPCIS  0x3F                    // 011010b/011010b/x/x TX Preshoot Set
#define CND003_PCIEEPHYCFG_TX_SWING_TABLE_LANE03_INDEX26 0x1068 // TX Swing Table Lane03-Index26
    #define CND003_PCIEEPHYCFG_FRP03_V0_26_TXPSR   (BIT29 + BIT30 + BIT31) // 011b/011b/x/x PMOS TX Slew Rate Control
    #define CND003_PCIEEPHYCFG_FRP03_V0_26_TXNSR   (BIT26 + BIT27 + BIT28) // 011b/011b/x/x NMOS TX Slew Rate Control
    #define CND003_PCIEEPHYCFG_FRP03_V0_26_TX_DUTY (BIT24 + BIT25)         // 00b/00b/x/x TX Clock Duty Control
    #define CND003_PCIEEPHYCFG_RSV03_1068_22       (BIT22 + BIT23)         // 0/0/x/x Reserved
    #define CND003_PCIEEPHYCFG_FRP03_V0_26_TDNCIS  0x3F0000                // 010001b/010001b/x/x TX De-emphasis Set
    #define CND003_PCIEEPHYCFG_RSV03_1068_13       (BIT13 + BIT14 + BIT15) // 0/0/x/x Reserved
    #define CND003_PCIEEPHYCFG_FRP03_V0_26_TDCIS   0x1F00                  // 11100b/11100b/x/x TX Bias Control Set
    #define CND003_PCIEEPHYCFG_RSV03_1068_6        (BIT6 + BIT7)           // 0/0/x/x Reserved
    #define CND003_PCIEEPHYCFG_FRP03_V0_26_TDPCIS  0x3F                    // 011010b/011010b/x/x TX Preshoot Set
#define CND003_PCIEEPHYCFG_TX_SWING_TABLE_LANE03_INDEX27 0x106C // TX Swing Table Lane03-Index27
    #define CND003_PCIEEPHYCFG_FRP03_V0_27_TXPSR   (BIT29 + BIT30 + BIT31) // 011b/011b/x/x PMOS TX Slew Rate Control
    #define CND003_PCIEEPHYCFG_FRP03_V0_27_TXNSR   (BIT26 + BIT27 + BIT28) // 011b/011b/x/x NMOS TX Slew Rate Control
    #define CND003_PCIEEPHYCFG_FRP03_V0_27_TX_DUTY (BIT24 + BIT25)         // 00b/00b/x/x TX Clock Duty Control
    #define CND003_PCIEEPHYCFG_RSV03_106C_22       (BIT22 + BIT23)         // 0/0/x/x Reserved
    #define CND003_PCIEEPHYCFG_FRP03_V0_27_TDNCIS  0x3F0000                // 011010b/011010b/x/x TX De-emphasis Set
    #define CND003_PCIEEPHYCFG_RSV03_106C_13       (BIT13 + BIT14 + BIT15) // 0/0/x/x Reserved
    #define CND003_PCIEEPHYCFG_FRP03_V0_27_TDCIS   0x1F00                  // 11011b/11011b/x/x TX Bias Control Set
    #define CND003_PCIEEPHYCFG_RSV03_106C_6        (BIT6 + BIT7)           // 0/0/x/x Reserved
    #define CND003_PCIEEPHYCFG_FRP03_V0_27_TDPCIS  0x3F                    // 011010b/011010b/x/x TX Preshoot Set
#define CND003_PCIEEPHYCFG_TX_SWING_TABLE_LANE03_INDEX28 0x1070 // TX Swing Table Lane03-Index28
    #define CND003_PCIEEPHYCFG_FRP03_V0_28_TXPSR   (BIT29 + BIT30 + BIT31) // 011b/011b/x/x PMOS TX Slew Rate Control
    #define CND003_PCIEEPHYCFG_FRP03_V0_28_TXNSR   (BIT26 + BIT27 + BIT28) // 011b/011b/x/x NMOS TX Slew Rate Control
    #define CND003_PCIEEPHYCFG_FRP03_V0_28_TX_DUTY (BIT24 + BIT25)         // 00b/00b/x/x TX Clock Duty Control
    #define CND003_PCIEEPHYCFG_RSV03_1070_22       (BIT22 + BIT23)         // 0/0/x/x Reserved
    #define CND003_PCIEEPHYCFG_FRP03_V0_28_TDNCIS  0x3F0000                // 100010b/100010b/x/x TX De-emphasis Set
    #define CND003_PCIEEPHYCFG_RSV03_1070_13       (BIT13 + BIT14 + BIT15) // 0/0/x/x Reserved
    #define CND003_PCIEEPHYCFG_FRP03_V0_28_TDCIS   0x1F00                  // 11011b/11011b/x/x TX Bias Control Set
    #define CND003_PCIEEPHYCFG_RSV03_1070_6        (BIT6 + BIT7)           // 0/0/x/x Reserved
    #define CND003_PCIEEPHYCFG_FRP03_V0_28_TDPCIS  0x3F                    // 011010b/011010b/x/x TX Preshoot Set
#define CND003_PCIEEPHYCFG_TX_SWING_TABLE_LANE03_INDEX29 0x1074 // TX Swing Table Lane03-Index29
    #define CND003_PCIEEPHYCFG_FRP03_V0_29_TXPSR   (BIT29 + BIT30 + BIT31) // 011b/011b/x/x PMOS TX Slew Rate Control
    #define CND003_PCIEEPHYCFG_FRP03_V0_29_TXNSR   (BIT26 + BIT27 + BIT28) // 011b/011b/x/x NMOS TX Slew Rate Control
    #define CND003_PCIEEPHYCFG_FRP03_V0_29_TX_DUTY (BIT24 + BIT25)         // 00b/00b/x/x TX Clock Duty Control
    #define CND003_PCIEEPHYCFG_RSV03_1074_22       (BIT22 + BIT23)         // 0/0/x/x Reserved
    #define CND003_PCIEEPHYCFG_FRP03_V0_29_TDNCIS  0x3F0000                // 101010b/101010b/x/x TX De-emphasis Set
    #define CND003_PCIEEPHYCFG_RSV03_1074_13       (BIT13 + BIT14 + BIT15) // 0/0/x/x Reserved
    #define CND003_PCIEEPHYCFG_FRP03_V0_29_TDCIS   0x1F00                  // 11010b/11010b/x/x TX Bias Control Set
    #define CND003_PCIEEPHYCFG_RSV03_1074_6        (BIT6 + BIT7)           // 0/0/x/x Reserved
    #define CND003_PCIEEPHYCFG_FRP03_V0_29_TDPCIS  0x3F                    // 011010b/011010b/x/x TX Preshoot Set
#define CND003_PCIEEPHYCFG_TX_SWING_TABLE_LANE03_INDEX30 0x1078 // TX Swing Table Lane03-Index30
    #define CND003_PCIEEPHYCFG_FRP03_V0_30_TXPSR   (BIT29 + BIT30 + BIT31) // 011b/011b/x/x PMOS TX Slew Rate Control
    #define CND003_PCIEEPHYCFG_FRP03_V0_30_TXNSR   (BIT26 + BIT27 + BIT28) // 011b/011b/x/x NMOS TX Slew Rate Control
    #define CND003_PCIEEPHYCFG_FRP03_V0_30_TX_DUTY (BIT24 + BIT25)         // 00b/00b/x/x TX Clock Duty Control
    #define CND003_PCIEEPHYCFG_RSV03_1078_22       (BIT22 + BIT23)         // 0/0/x/x Reserved
    #define CND003_PCIEEPHYCFG_FRP03_V0_30_TDNCIS  0x3F0000                // 000000b/000000b/x/x TX De-emphasis Set
    #define CND003_PCIEEPHYCFG_RSV03_1078_13       (BIT13 + BIT14 + BIT15) // 0/0/x/x Reserved
    #define CND003_PCIEEPHYCFG_FRP03_V0_30_TDCIS   0x1F00                  // 11101b/11101b/x/x TX Bias Control Set
    #define CND003_PCIEEPHYCFG_RSV03_1078_6        (BIT6 + BIT7)           // 0/0/x/x Reserved
    #define CND003_PCIEEPHYCFG_FRP03_V0_30_TDPCIS  0x3F                    // 100010b/100010b/x/x TX Preshoot Set
#define CND003_PCIEEPHYCFG_TX_SWING_TABLE_LANE03_INDEX31 0x107C // TX Swing Table Lane03-Index31
    #define CND003_PCIEEPHYCFG_FRP03_V0_31_TXPSR   (BIT29 + BIT30 + BIT31) // 011b/011b/x/x PMOS TX Slew Rate Control
    #define CND003_PCIEEPHYCFG_FRP03_V0_31_TXNSR   (BIT26 + BIT27 + BIT28) // 011b/011b/x/x NMOS TX Slew Rate Control
    #define CND003_PCIEEPHYCFG_FRP03_V0_31_TX_DUTY (BIT24 + BIT25)         // 00b/00b/x/x TX Clock Duty Control
    #define CND003_PCIEEPHYCFG_RSV03_107C_22       (BIT22 + BIT23)         // 0/0/x/x Reserved
    #define CND003_PCIEEPHYCFG_FRP03_V0_31_TDNCIS  0x3F0000                // 001001b/001001b/x/x TX De-emphasis Set
    #define CND003_PCIEEPHYCFG_RSV03_107C_13       (BIT13 + BIT14 + BIT15) // 0/0/x/x Reserved
    #define CND003_PCIEEPHYCFG_FRP03_V0_31_TDCIS   0x1F00                  // 11100b/11100b/x/x TX Bias Control Set
    #define CND003_PCIEEPHYCFG_RSV03_107C_6        (BIT6 + BIT7)           // 0/0/x/x Reserved
    #define CND003_PCIEEPHYCFG_FRP03_V0_31_TDPCIS  0x3F                    // 100010b/100010b/x/x TX Preshoot Set
#define CND003_PCIEEPHYCFG_TX_SWING_TABLE_LANE03_INDEX32 0x1080 // TX Swing Table Lane03-Index32
    #define CND003_PCIEEPHYCFG_FRP03_V0_32_TXPSR   (BIT29 + BIT30 + BIT31) // 011b/011b/x/x PMOS TX Slew Rate Control
    #define CND003_PCIEEPHYCFG_FRP03_V0_32_TXNSR   (BIT26 + BIT27 + BIT28) // 011b/011b/x/x NMOS TX Slew Rate Control
    #define CND003_PCIEEPHYCFG_FRP03_V0_32_TX_DUTY (BIT24 + BIT25)         // 00b/00b/x/x TX Clock Duty Control
    #define CND003_PCIEEPHYCFG_RSV03_1080_22       (BIT22 + BIT23)         // 0/0/x/x Reserved
    #define CND003_PCIEEPHYCFG_FRP03_V0_32_TDNCIS  0x3F0000                // 010000b/010000b/x/x TX De-emphasis Set
    #define CND003_PCIEEPHYCFG_RSV03_1080_13       (BIT13 + BIT14 + BIT15) // 0/0/x/x Reserved
    #define CND003_PCIEEPHYCFG_FRP03_V0_32_TDCIS   0x1F00                  // 11011b/11011b/x/x TX Bias Control Set
    #define CND003_PCIEEPHYCFG_RSV03_1080_6        (BIT6 + BIT7)           // 0/0/x/x Reserved
    #define CND003_PCIEEPHYCFG_FRP03_V0_32_TDPCIS  0x3F                    // 100010b/100010b/x/x TX Preshoot Set
#define CND003_PCIEEPHYCFG_TX_SWING_TABLE_LANE03_INDEX33 0x1084 // TX Swing Table Lane03-Index33
    #define CND003_PCIEEPHYCFG_FRP03_V0_33_TXPSR   (BIT29 + BIT30 + BIT31) // 011b/011b/x/x PMOS TX Slew Rate Control
    #define CND003_PCIEEPHYCFG_FRP03_V0_33_TXNSR   (BIT26 + BIT27 + BIT28) // 011b/011b/x/x NMOS TX Slew Rate Control
    #define CND003_PCIEEPHYCFG_FRP03_V0_33_TX_DUTY (BIT24 + BIT25)         // 00b/00b/x/x TX Clock Duty Control
    #define CND003_PCIEEPHYCFG_RSV03_1084_22       (BIT22 + BIT23)         // 0/0/x/x Reserved
    #define CND003_PCIEEPHYCFG_FRP03_V0_33_TDNCIS  0x3F0000                // 011010b/011010b/x/x TX De-emphasis Set
    #define CND003_PCIEEPHYCFG_RSV03_1084_13       (BIT13 + BIT14 + BIT15) // 0/0/x/x Reserved
    #define CND003_PCIEEPHYCFG_FRP03_V0_33_TDCIS   0x1F00                  // 11011b/11011b/x/x TX Bias Control Set
    #define CND003_PCIEEPHYCFG_RSV03_1084_6        (BIT6 + BIT7)           // 0/0/x/x Reserved
    #define CND003_PCIEEPHYCFG_FRP03_V0_33_TDPCIS  0x3F                    // 100010b/100010b/x/x TX Preshoot Set
#define CND003_PCIEEPHYCFG_TX_SWING_TABLE_LANE03_INDEX34 0x1088 // TX Swing Table Lane03-Index34
    #define CND003_PCIEEPHYCFG_FRP03_V0_34_TXPSR   (BIT29 + BIT30 + BIT31) // 011b/011b/x/x PMOS TX Slew Rate Control
    #define CND003_PCIEEPHYCFG_FRP03_V0_34_TXNSR   (BIT26 + BIT27 + BIT28) // 011b/011b/x/x NMOS TX Slew Rate Control
    #define CND003_PCIEEPHYCFG_FRP03_V0_34_TX_DUTY (BIT24 + BIT25)         // 00b/00b/x/x TX Clock Duty Control
    #define CND003_PCIEEPHYCFG_RSV03_1088_22       (BIT22 + BIT23)         // 0/0/x/x Reserved
    #define CND003_PCIEEPHYCFG_FRP03_V0_34_TDNCIS  0x3F0000                // 100010b/100010b/x/x TX De-emphasis Set
    #define CND003_PCIEEPHYCFG_RSV03_1088_13       (BIT13 + BIT14 + BIT15) // 0/0/x/x Reserved
    #define CND003_PCIEEPHYCFG_FRP03_V0_34_TDCIS   0x1F00                  // 11010b/11010b/x/x TX Bias Control Set
    #define CND003_PCIEEPHYCFG_RSV03_1088_6        (BIT6 + BIT7)           // 0/0/x/x Reserved
    #define CND003_PCIEEPHYCFG_FRP03_V0_34_TDPCIS  0x3F                    // 100010b/100010b/x/x TX Preshoot Set
#define CND003_PCIEEPHYCFG_TX_SWING_TABLE_LANE03_INDEX35 0x108C // TX Swing Table Lane03-Index35
    #define CND003_PCIEEPHYCFG_FRP03_V0_35_TXPSR   (BIT29 + BIT30 + BIT31) // 011b/011b/x/x PMOS TX Slew Rate Control
    #define CND003_PCIEEPHYCFG_FRP03_V0_35_TXNSR   (BIT26 + BIT27 + BIT28) // 011b/011b/x/x NMOS TX Slew Rate Control
    #define CND003_PCIEEPHYCFG_FRP03_V0_35_TX_DUTY (BIT24 + BIT25)         // 00b/00b/x/x TX Clock Duty Control
    #define CND003_PCIEEPHYCFG_RSV03_108C_22       (BIT22 + BIT23)         // 0/0/x/x Reserved
    #define CND003_PCIEEPHYCFG_FRP03_V0_35_TDNCIS  0x3F0000                // 000000b/000000b/x/x TX De-emphasis Set
    #define CND003_PCIEEPHYCFG_RSV03_108C_13       (BIT13 + BIT14 + BIT15) // 0/0/x/x Reserved
    #define CND003_PCIEEPHYCFG_FRP03_V0_35_TDCIS   0x1F00                  // 11100b/11100b/x/x TX Bias Control Set
    #define CND003_PCIEEPHYCFG_RSV03_108C_6        (BIT6 + BIT7)           // 0/0/x/x Reserved
    #define CND003_PCIEEPHYCFG_FRP03_V0_35_TDPCIS  0x3F                    // 101010b/101010b/x/x TX Preshoot Set
#define CND003_PCIEEPHYCFG_TX_SWING_TABLE_LANE03_INDEX36 0x1090 // TX Swing Table Lane03-Index36
    #define CND003_PCIEEPHYCFG_FRP03_V0_36_TXPSR   (BIT29 + BIT30 + BIT31) // 011b/011b/x/x PMOS TX Slew Rate Control
    #define CND003_PCIEEPHYCFG_FRP03_V0_36_TXNSR   (BIT26 + BIT27 + BIT28) // 011b/011b/x/x NMOS TX Slew Rate Control
    #define CND003_PCIEEPHYCFG_FRP03_V0_36_TX_DUTY (BIT24 + BIT25)         // 00b/00b/x/x TX Clock Duty Control
    #define CND003_PCIEEPHYCFG_RSV03_1090_22       (BIT22 + BIT23)         // 0/0/x/x Reserved
    #define CND003_PCIEEPHYCFG_FRP03_V0_36_TDNCIS  0x3F0000                // 001000b/001000b/x/x TX De-emphasis Set
    #define CND003_PCIEEPHYCFG_RSV03_1090_13       (BIT13 + BIT14 + BIT15) // 0/0/x/x Reserved
    #define CND003_PCIEEPHYCFG_FRP03_V0_36_TDCIS   0x1F00                  // 11011b/11011b/x/x TX Bias Control Set
    #define CND003_PCIEEPHYCFG_RSV03_1090_6        (BIT6 + BIT7)           // 0/0/x/x Reserved
    #define CND003_PCIEEPHYCFG_FRP03_V0_36_TDPCIS  0x3F                    // 101010b/101010b/x/x TX Preshoot Set
#define CND003_PCIEEPHYCFG_TX_SWING_TABLE_LANE03_INDEX37 0x1094 // TX Swing Table Lane03-Index37
    #define CND003_PCIEEPHYCFG_FRP03_V0_37_TXPSR   (BIT29 + BIT30 + BIT31) // 011b/011b/x/x PMOS TX Slew Rate Control
    #define CND003_PCIEEPHYCFG_FRP03_V0_37_TXNSR   (BIT26 + BIT27 + BIT28) // 011b/011b/x/x NMOS TX Slew Rate Control
    #define CND003_PCIEEPHYCFG_FRP03_V0_37_TX_DUTY (BIT24 + BIT25)         // 00b/00b/x/x TX Clock Duty Control
    #define CND003_PCIEEPHYCFG_RSV03_1094_22       (BIT22 + BIT23)         // 0/0/x/x Reserved
    #define CND003_PCIEEPHYCFG_FRP03_V0_37_TDNCIS  0x3F0000                // 010001b/010001b/x/x TX De-emphasis Set
    #define CND003_PCIEEPHYCFG_RSV03_1094_13       (BIT13 + BIT14 + BIT15) // 0/0/x/x Reserved
    #define CND003_PCIEEPHYCFG_FRP03_V0_37_TDCIS   0x1F00                  // 11011b/11011b/x/x TX Bias Control Set
    #define CND003_PCIEEPHYCFG_RSV03_1094_6        (BIT6 + BIT7)           // 0/0/x/x Reserved
    #define CND003_PCIEEPHYCFG_FRP03_V0_37_TDPCIS  0x3F                    // 101010b/101010b/x/x TX Preshoot Set
#define CND003_PCIEEPHYCFG_TX_SWING_TABLE_LANE03_INDEX38 0x1098 // TX Swing Table Lane03-Index38
    #define CND003_PCIEEPHYCFG_FRP03_V0_38_TXPSR   (BIT29 + BIT30 + BIT31) // 011b/011b/x/x PMOS TX Slew Rate Control
    #define CND003_PCIEEPHYCFG_FRP03_V0_38_TXNSR   (BIT26 + BIT27 + BIT28) // 011b/011b/x/x NMOS TX Slew Rate Control
    #define CND003_PCIEEPHYCFG_FRP03_V0_38_TX_DUTY (BIT24 + BIT25)         // 00b/00b/x/x TX Clock Duty Control
    #define CND003_PCIEEPHYCFG_RSV03_1098_22       (BIT22 + BIT23)         // 0/0/x/x Reserved
    #define CND003_PCIEEPHYCFG_FRP03_V0_38_TDNCIS  0x3F0000                // 011010b/011010b/x/x TX De-emphasis Set
    #define CND003_PCIEEPHYCFG_RSV03_1098_13       (BIT13 + BIT14 + BIT15) // 0/0/x/x Reserved
    #define CND003_PCIEEPHYCFG_FRP03_V0_38_TDCIS   0x1F00                  // 11010b/11010b/x/x TX Bias Control Set
    #define CND003_PCIEEPHYCFG_RSV03_1098_6        (BIT6 + BIT7)           // 0/0/x/x Reserved
    #define CND003_PCIEEPHYCFG_FRP03_V0_38_TDPCIS  0x3F                    // 101010b/101010b/x/x TX Preshoot Set
#define CND003_PCIEEPHYCFG_TX_SWING_TABLE_LANE03_INDEX39 0x109C // TX Swing Table Lane03-Index39
    #define CND003_PCIEEPHYCFG_FRP03_V0_39_TXPSR   (BIT29 + BIT30 + BIT31) // 011b/011b/x/x PMOS TX Slew Rate Control
    #define CND003_PCIEEPHYCFG_FRP03_V0_39_TXNSR   (BIT26 + BIT27 + BIT28) // 011b/011b/x/x NMOS TX Slew Rate Control
    #define CND003_PCIEEPHYCFG_FRP03_V0_39_TX_DUTY (BIT24 + BIT25)         // 00b/00b/x/x TX Clock Duty Control
    #define CND003_PCIEEPHYCFG_RSV03_109C_22       (BIT22 + BIT23)         // 0/0/x/x Reserved
    #define CND003_PCIEEPHYCFG_FRP03_V0_39_TDNCIS  0x3F0000                // 000000b/000000b/x/x TX De-emphasis Set
    #define CND003_PCIEEPHYCFG_RSV03_109C_13       (BIT13 + BIT14 + BIT15) // 0/0/x/x Reserved
    #define CND003_PCIEEPHYCFG_FRP03_V0_39_TDCIS   0x1F00                  // 11011b/11011b/x/x TX Bias Control Set
    #define CND003_PCIEEPHYCFG_RSV03_109C_6        (BIT6 + BIT7)           // 0/0/x/x Reserved
    #define CND003_PCIEEPHYCFG_FRP03_V0_39_TDPCIS  0x3F                    // 110010b/110010b/x/x TX Preshoot Set
#define CND003_PCIEEPHYCFG_TX_SWING_TABLE_LANE03_INDEX40 0x10A0 // TX Swing Table Lane03-Index40
    #define CND003_PCIEEPHYCFG_FRP03_V0_40_TXPSR   (BIT29 + BIT30 + BIT31) // 011b/011b/x/x PMOS TX Slew Rate Control
    #define CND003_PCIEEPHYCFG_FRP03_V0_40_TXNSR   (BIT26 + BIT27 + BIT28) // 011b/011b/x/x NMOS TX Slew Rate Control
    #define CND003_PCIEEPHYCFG_FRP03_V0_40_TX_DUTY (BIT24 + BIT25)         // 00b/00b/x/x TX Clock Duty Control
    #define CND003_PCIEEPHYCFG_RSV03_10A0_22       (BIT22 + BIT23)         // 0/0/x/x Reserved
    #define CND003_PCIEEPHYCFG_FRP03_V0_40_TDNCIS  0x3F0000                // 001001b/001001b/x/x TX De-emphasis Set
    #define CND003_PCIEEPHYCFG_RSV03_10A0_13       (BIT13 + BIT14 + BIT15) // 0/0/x/x Reserved
    #define CND003_PCIEEPHYCFG_FRP03_V0_40_TDCIS   0x1F00                  // 11011b/11011b/x/x TX Bias Control Set
    #define CND003_PCIEEPHYCFG_RSV03_10A0_6        (BIT6 + BIT7)           // 0/0/x/x Reserved
    #define CND003_PCIEEPHYCFG_FRP03_V0_40_TDPCIS  0x3F                    // 110010b/110010b/x/x TX Preshoot Set
#define CND003_PCIEEPHYCFG_TX_SWING_TABLE_LANE03_INDEX41 0x10A4 // TX Swing Table Lane03-Index41
    #define CND003_PCIEEPHYCFG_FRP03_V0_41_TXPSR   (BIT29 + BIT30 + BIT31) // 011b/011b/x/x PMOS TX Slew Rate Control
    #define CND003_PCIEEPHYCFG_FRP03_V0_41_TXNSR   (BIT26 + BIT27 + BIT28) // 011b/011b/x/x NMOS TX Slew Rate Control
    #define CND003_PCIEEPHYCFG_FRP03_V0_41_TX_DUTY (BIT24 + BIT25)         // 00b/00b/x/x TX Clock Duty Control
    #define CND003_PCIEEPHYCFG_RSV03_10A4_22       (BIT22 + BIT23)         // 0/0/x/x Reserved
    #define CND003_PCIEEPHYCFG_FRP03_V0_41_TDNCIS  0x3F0000                // 010001b/010001b/x/x TX De-emphasis Set
    #define CND003_PCIEEPHYCFG_RSV03_10A4_13       (BIT13 + BIT14 + BIT15) // 0/0/x/x Reserved
    #define CND003_PCIEEPHYCFG_FRP03_V0_41_TDCIS   0x1F00                  // 11010b/11010b/x/x TX Bias Control Set
    #define CND003_PCIEEPHYCFG_RSV03_10A4_6        (BIT6 + BIT7)           // 0/0/x/x Reserved
    #define CND003_PCIEEPHYCFG_FRP03_V0_41_TDPCIS  0x3F                    // 110010b/110010b/x/x TX Preshoot Set
#define CND003_PCIEEPHYCFG_CTL_REG_FOR_PCIE_CFG_SHADOW_REGS_0 0x1FA8 // Control Register for PCIE CFG Shadow Registers 0
    #define CND003_PCIEEPHYCFG_PCIE_SHADOW_R0_MASK_7_0     0xFF000000              // 0/x/x/x Register Mask Bits
    #define CND003_PCIEEPHYCFG_PCIE_SHADOW_R0_PCIEPHYCFG   BIT23                   // 0/x/x/x Register bits for shadow PCIEPHYCFG 
    #define CND003_PCIEEPHYCFG_PCIE_SHADOW_R0_WC           BIT22                   // 0/x/x/x Write Enable Bit 
    #define CND003_PCIEEPHYCFG_PCIE_SHADOW_R0_RC           BIT21                   // 0/x/x/x Read Enable Bit
    #define CND003_PCIEEPHYCFG_PCIE_SHADOW_R0_DEV_4_0      0x1F0000                // 0/x/x/x Device Number
    #define CND003_PCIEEPHYCFG_PCIE_SHADOW_R0_BUSXP1       BIT15                   // 0/x/x/x register bits for shadow Bus xp1
    #define CND003_PCIEEPHYCFG_PCIE_SHADOW_R0_FUN_2_0      (BIT12 + BIT13 + BIT14) // 0/x/x/x Function Number
    #define CND003_PCIEEPHYCFG_PCIE_SHADOW_R0_REG_11_0     0xFFF                   // 0/x/x/x Register Offset
#define CND003_PCIEEPHYCFG_CTL_REG_FOR_PCIE_CFG_SHADOW_REGS_1 0x1FAC // Control Register for PCIE CFG Shadow Registers 1
    #define CND003_PCIEEPHYCFG_PCIE_SHADOW_R1_MASK_7_0     0xFF000000              // 0/x/x/x Register Mask Bits
    #define CND003_PCIEEPHYCFG_PCIE_SHADOW_R1_PCIEPHYCFG   BIT23                   // 0/x/x/x Register bits for shadow PCIEPHYCFG 
    #define CND003_PCIEEPHYCFG_PCIE_SHADOW_R1_WC           BIT22                   // 0/x/x/x Write Enable Bit 
    #define CND003_PCIEEPHYCFG_PCIE_SHADOW_R1_RC           BIT21                   // 0/x/x/x Read Enable Bit
    #define CND003_PCIEEPHYCFG_PCIE_SHADOW_R1_DEV_4_0      0x1F0000                // 0/x/x/x Device Number
    #define CND003_PCIEEPHYCFG_PCIE_SHADOW_R1_BUSXP1       BIT15                   // 0/x/x/x register bits for shadow Bus xp1
    #define CND003_PCIEEPHYCFG_PCIE_SHADOW_R1_FUN_2_0      (BIT12 + BIT13 + BIT14) // 0/x/x/x Function Number
    #define CND003_PCIEEPHYCFG_PCIE_SHADOW_R1_REG_11_0     0xFFF                   // 0/x/x/x Register Offset
#define CND003_PCIEEPHYCFG_CTL_REG_FOR_PCIE_CFG_SHADOW_REGS_2 0x1FB0 // Control Register for PCIE CFG Shadow Registers 2
    #define CND003_PCIEEPHYCFG_PCIE_SHADOW_R2_MASK_7_0     0xFF000000              // 0/x/x/x Register Mask Bits
    #define CND003_PCIEEPHYCFG_PCIE_SHADOW_R2_PCIEPHYCFG   BIT23                   // 0/x/x/x Register bits for shadow PCIEPHYCFG 
    #define CND003_PCIEEPHYCFG_PCIE_SHADOW_R2_WC           BIT22                   // 0/x/x/x Write Enable Bit 
    #define CND003_PCIEEPHYCFG_PCIE_SHADOW_R2_RC           BIT21                   // 0/x/x/x Read Enable Bit
    #define CND003_PCIEEPHYCFG_PCIE_SHADOW_R2_DEV_4_0      0x1F0000                // 0/x/x/x Device Number
    #define CND003_PCIEEPHYCFG_PCIE_SHADOW_R2_BUSXP1       BIT15                   // 0/x/x/x register bits for shadow Bus xp1
    #define CND003_PCIEEPHYCFG_PCIE_SHADOW_R2_FUN_2_0      (BIT12 + BIT13 + BIT14) // 0/x/x/x Function Number
    #define CND003_PCIEEPHYCFG_PCIE_SHADOW_R2_REG_11_0     0xFFF                   // 0/x/x/x Register Offset
#define CND003_PCIEEPHYCFG_CTL_REG_FOR_PCIE_CFG_SHADOW_REGS_3 0x1FB4 // Control Register for PCIE CFG Shadow Registers 3
    #define CND003_PCIEEPHYCFG_PCIE_SHADOW_R3_MASK_7_0     0xFF000000              // 0/x/x/x Register Mask Bits
    #define CND003_PCIEEPHYCFG_PCIE_SHADOW_R3_PCIEPHYCFG   BIT23                   // 0/x/x/x Register bits for shadow PCIEPHYCFG 
    #define CND003_PCIEEPHYCFG_PCIE_SHADOW_R3_WC           BIT22                   // 0/x/x/x Write Enable Bit 
    #define CND003_PCIEEPHYCFG_PCIE_SHADOW_R3_RC           BIT21                   // 0/x/x/x Read Enable Bit
    #define CND003_PCIEEPHYCFG_PCIE_SHADOW_R3_DEV_4_0      0x1F0000                // 0/x/x/x Device Number
    #define CND003_PCIEEPHYCFG_PCIE_SHADOW_R3_BUSXP1       BIT15                   // 0/x/x/x register bits for shadow Bus xp1
    #define CND003_PCIEEPHYCFG_PCIE_SHADOW_R3_FUN_2_0      (BIT12 + BIT13 + BIT14) // 0/x/x/x Function Number
    #define CND003_PCIEEPHYCFG_PCIE_SHADOW_R3_REG_11_0     0xFFF                   // 0/x/x/x Register Offset
#define CND003_PCIEEPHYCFG_CTL_REG_FOR_PCIE_CFG_SHADOW_REGS_4 0x1FB8 // Control Register for PCIE CFG Shadow Registers 4
    #define CND003_PCIEEPHYCFG_PCIE_SHADOW_R4_MASK_7_0     0xFF000000              // 0/x/x/x Register Mask Bits
    #define CND003_PCIEEPHYCFG_PCIE_SHADOW_R4_PCIEPHYCFG   BIT23                   // 0/x/x/x Register bits for shadow PCIEPHYCFG 
    #define CND003_PCIEEPHYCFG_PCIE_SHADOW_R4_WC           BIT22                   // 0/x/x/x Write Enable Bit 
    #define CND003_PCIEEPHYCFG_PCIE_SHADOW_R4_RC           BIT21                   // 0/x/x/x Read Enable Bit
    #define CND003_PCIEEPHYCFG_PCIE_SHADOW_R4_DEV_4_0      0x1F0000                // 0/x/x/x Device Number
    #define CND003_PCIEEPHYCFG_PCIE_SHADOW_R4_BUSXP1       BIT15                   // 0/x/x/x register bits for shadow Bus xp1
    #define CND003_PCIEEPHYCFG_PCIE_SHADOW_R4_FUN_2_0      (BIT12 + BIT13 + BIT14) // 0/x/x/x Function Number
    #define CND003_PCIEEPHYCFG_PCIE_SHADOW_R4_REG_11_0     0xFFF                   // 0/x/x/x Register Offset
#define CND003_PCIEEPHYCFG_CTL_REG_FOR_PCIE_CFG_SHADOW_REGS_5 0x1FBC // Control Register for PCIE CFG Shadow Registers 5
    #define CND003_PCIEEPHYCFG_PCIE_SHADOW_R5_MASK_7_0     0xFF000000              // 0/x/x/x Register Mask Bits
    #define CND003_PCIEEPHYCFG_PCIE_SHADOW_R5_PCIEPHYCFG   BIT23                   // 0/x/x/x Register bits for shadow PCIEPHYCFG 
    #define CND003_PCIEEPHYCFG_PCIE_SHADOW_R5_WC           BIT22                   // 0/x/x/x Write Enable Bit 
    #define CND003_PCIEEPHYCFG_PCIE_SHADOW_R5_RC           BIT21                   // 0/x/x/x Read Enable Bit
    #define CND003_PCIEEPHYCFG_PCIE_SHADOW_R5_DEV_4_0      0x1F0000                // 0/x/x/x Device Number
    #define CND003_PCIEEPHYCFG_PCIE_SHADOW_R5_BUSXP1       BIT15                   // 0/x/x/x register bits for shadow Bus xp1
    #define CND003_PCIEEPHYCFG_PCIE_SHADOW_R5_FUN_2_0      (BIT12 + BIT13 + BIT14) // 0/x/x/x Function Number
    #define CND003_PCIEEPHYCFG_PCIE_SHADOW_R5_REG_11_0     0xFFF                   // 0/x/x/x Register Offset
#define CND003_PCIEEPHYCFG_PCIE_CFG_SHADOW_REG_0 0x1FC0 // PCIE CFG Shadow Register 0
    #define CND003_PCIEEPHYCFG_PCIE_SHADOW_R3_DATA_7_0 0xFF000000  // 0/x/x/x Configuration Shadow Register 3
    #define CND003_PCIEEPHYCFG_PCIE_SHADOW_R2_DATA_7_0 0xFF0000    // 0/x/x/x Configuration Shadow Register 2
    #define CND003_PCIEEPHYCFG_PCIE_SHADOW_R1_DATA_7_0 0xFF00      // 0/x/x/x Configuration Shadow Register 1
    #define CND003_PCIEEPHYCFG_PCIE_SHADOW_R0_DATA_7_0 0xFF        // 0/x/x/x Configuration Shadow Register 0
#define CND003_PCIEEPHYCFG_PCIE_CFG_SHADOW_REG_4 0x1FC4 // PCIE CFG Shadow Register 4
    #define CND003_PCIEEPHYCFG_RSV_1FC4_31_16          0xFFFF0000  // 0/x/x/x Reserved
    #define CND003_PCIEEPHYCFG_PCIE_SHADOW_R5_DATA_7_0 0xFF00      // 0/x/x/x Configuration Shadow Register 5
    #define CND003_PCIEEPHYCFG_PCIE_SHADOW_R4_DATA_7_0 0xFF        // 0/x/x/x Configuration Shadow Register 4
#endif
// Irs2h.exe Revision: 5.0.0.0
// Irs2h.ini Revision: CHX001(1.00)
// Pls contact PLW to report Irs2h bugs.
