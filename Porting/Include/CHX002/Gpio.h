/*******************************************************************************
Copyright(C) 2017 ZX Technologies, Inc. All Rights Reserved.

Information in this file is the intellectual property of Shanghai Zhaoxin Technologies, Inc.,
and may contains trade secrets that must be stored and viewed confidentially.

\file Gpio.h
\brief GPIO definitions for CHX002.
\author Tiger Liu
\date 2017-05-17

Modification History:
*******************************************************************************/
//----------------------------------------------------------------------------
//----------------------------------------------------------------------------
//
// ASIA GPIO: Enum of GPIO, GPI and GPO for AsiaSbLibPpi GetGpi() and SetGpo()
//

//
// GPIO
//
#define GPIO_00_OUT_REG (PMIO_GENERAL_PURPOSE_OUTPUT + 1)//0x4D
#define GPIO_00_OUT_DAT 1 << 3
#define GPIO_00_IN_REG  (PMIO_GENERAL_PURPOSE_INPUT + 1)//0x49

#define GPIO_01_OUT_REG (PMIO_GENERAL_PURPOSE_OUTPUT + 1)//0x4D
#define GPIO_01_OUT_DAT 1 << 4
#define GPIO_01_IN_REG  (PMIO_GENERAL_PURPOSE_INPUT + 1)//0x49

#define GPIO_02_SEL_REG D17F0_PMU_MISC_CFG_4_PWR_WELL//0x97
#define GPIO_02_SEL_DAT 1 << 6
#define GPIO_02_OUT_REG (PMIO_GENERAL_PURPOSE_OUTPUT + 1)//0x4D
#define GPIO_02_OUT_DAT 1 << 5
#define GPIO_02_IN_REG  (PMIO_GENERAL_PURPOSE_INPUT + 1)//0x49

#define GPIO_03_SEL_REG D17F0_PMU_MISC_CFG_4_PWR_WELL//0x97
#define GPIO_03_SEL_DAT 1 << 6
#define GPIO_03_OUT_REG (PMIO_GENERAL_PURPOSE_OUTPUT + 1)//0x4D
#define GPIO_03_OUT_DAT 1 << 6
#define GPIO_03_IN_REG  (PMIO_GENERAL_PURPOSE_INPUT + 1)//0x49

#define GPIO_04_SEL_REG D17F0_PMU_MISC_CFG_4_PWR_WELL//0x97
#define GPIO_04_SEL_DAT 1 << 0
#define GPIO_04_OUT_REG (PMIO_GENERAL_PURPOSE_OUTPUT + 1)//0x4D
#define GPIO_04_OUT_DAT 1 << 7
#define GPIO_04_IN_REG  (PMIO_GENERAL_PURPOSE_INPUT + 1)//0x49

#define GPIO_05_SEL_REG D17F0_PMU_MISC_CFG_4_PWR_WELL//0x97
#define GPIO_05_SEL_DAT 1 << 0
#define GPIO_05_OUT_REG (PMIO_GENERAL_PURPOSE_OUTPUT + 2)//0x4E
#define GPIO_05_OUT_DAT 1 << 0
#define GPIO_05_IN_REG  (PMIO_GENERAL_PURPOSE_INPUT + 1)//0x49

#define GPIO_06_SEL_REG D17F0_PMU_MULTI_FUN_SEL_2//0xE4
#define GPIO_06_SEL_DAT 1 << 1
#define GPIO_06_OUT_REG (PMIO_GENERAL_PURPOSE_OUTPUT + 2)//0x4E
#define GPIO_06_OUT_DAT 1 << 1
#define GPIO_06_IN_REG  (PMIO_GENERAL_PURPOSE_INPUT + 2)//0x4A

#define GPIO_07_SEL_REG PMIO_CKGPCI_SMB_PAD_CTL//0xBC
#define GPIO_07_SEL_DAT 1 << 0
#define GPIO_07_OUT_REG (PMIO_GENERAL_PURPOSE_OUTPUT + 2)//0x4E
#define GPIO_07_OUT_DAT 1 << 2
#define GPIO_07_IN_REG  (PMIO_GENERAL_PURPOSE_INPUT + 2)//0x4A


#define GPIO_10_SEL_REG PMIO_CR_GPIO_PAD_CTL//0xB4
#define GPIO_10_SEL_DAT 0
#define GPIO_10_OUT_REG (PMIO_GENERAL_PURPOSE_OUTPUT + 2)//0x4E
#define GPIO_10_OUT_DAT 1 << 5
#define GPIO_10_IN_REG  (PMIO_GENERAL_PURPOSE_INPUT + 2)//0x4A

#define GPIO_11_SEL_REG PMIO_CR_GPIO_PAD_CTL//0xB4
#define GPIO_11_SEL_DAT 0 
#define GPIO_11_OUT_REG (PMIO_GENERAL_PURPOSE_OUTPUT + 2)//0x4E
#define GPIO_11_OUT_DAT 1 << 6
#define GPIO_11_IN_REG  (PMIO_GENERAL_PURPOSE_INPUT + 2)//0x4A

#define GPIO_12_SEL_REG PMIO_CR_GPIO_PAD_CTL//0xB4
#define GPIO_12_SEL_DAT 0 
#define GPIO_12_OUT_REG (PMIO_GENERAL_PURPOSE_OUTPUT + 2)//0x4E
#define GPIO_12_OUT_DAT 1 << 7
#define GPIO_12_IN_REG  (PMIO_GENERAL_PURPOSE_INPUT + 2)//0x4A

#define GPIO_13_SEL_REG PMIO_CR_GPIO_PAD_CTL//0xB4
#define GPIO_13_SEL_DAT 0 
#define GPIO_13_OUT_REG (PMIO_GENERAL_PURPOSE_OUTPUT + 3)//0x4F
#define GPIO_13_OUT_DAT 1 << 0
#define GPIO_13_IN_REG  (PMIO_GENERAL_PURPOSE_INPUT + 2)//0x4A

#define GPIO_14_SEL_REG PMIO_GPIO_PAD_CTL//0xB8
#define GPIO_14_OUT_REG (PMIO_GENERAL_PURPOSE_OUTPUT + 3)//0x4F
#define GPIO_14_OUT_DAT 1 << 3
#define GPIO_14_IN_REG  (PMIO_GENERAL_PURPOSE_INPUT + 3)//0x4B

#define GPIO_26_SEL_REG PMIO_GPIO_PAD_CTL//0xB8
#define GPIO_26_SEL_DAT 1 << 3
#define GPIO_26_OUT_REG (PMIO_GENERAL_PURPOSE_OUTPUT_INPUT+3) //0x3F
#define GPIO_26_OUT_DAT 1 << 1
#define GPIO_26_IN_REG  (PMIO_GENERAL_PURPOSE_OUTPUT_INPUT+1) //0x3D

#define GPIO_27_SEL_REG PMIO_GPIO_PAD_CTL//0xB8
#define GPIO_27_SEL_DAT 1 << 8
#define GPIO_27_OUT_REG (PMIO_GENERAL_PURPOSE_OUTPUT_INPUT+3) //0x3F
#define GPIO_27_OUT_DAT 1 << 2
#define GPIO_27_IN_REG  (PMIO_GENERAL_PURPOSE_OUTPUT_INPUT+1) //0x3D


#define GPIO_28_OUT_REG (PMIO_GENERAL_PURPOSE_OUTPUT_INPUT+3) //0x3F
#define GPIO_28_OUT_DAT 1 << 3
#define GPIO_28_IN_REG  (PMIO_GENERAL_PURPOSE_OUTPUT_INPUT+1) //0x3D


#define GPIO_29_OUT_REG (PMIO_GENERAL_PURPOSE_OUTPUT_INPUT+3) //0x3F
#define GPIO_29_OUT_DAT 1 << 4
#define GPIO_29_IN_REG  (PMIO_GENERAL_PURPOSE_OUTPUT_INPUT+1) //0x3D



#define GPIO_30_OUT_REG (PMIO_GENERAL_PURPOSE_OUTPUT_INPUT+3) //0x3F
#define GPIO_30_OUT_DAT 1 << 5
#define GPIO_30_IN_REG (PMIO_GENERAL_PURPOSE_OUTPUT_INPUT+1) //0x3D


#define GPIO_31_OUT_REG (PMIO_GENERAL_PURPOSE_OUTPUT_INPUT+3) //0x3F
#define GPIO_31_OUT_DAT 1 << 6
#define GPIO_31_IN_REG  (PMIO_GENERAL_PURPOSE_OUTPUT_INPUT+1) //0x3D


#define GPIO_32_OUT_REG (PMIO_GENERAL_PURPOSE_OUTPUT_INPUT+3) //0x3F
#define GPIO_32_OUT_DAT 1 << 7
#define GPIO_32_IN_REG  (PMIO_GENERAL_PURPOSE_OUTPUT_INPUT+1) //0x3D


#define GPIO_33_OUT_REG (PMIO_GENERAL_PURPOSE_OUTPUT_INPUT_Z1+1) //0x47
#define GPIO_33_OUT_DAT 1 << 0
#define GPIO_33_IN_REG  PMIO_GENERAL_PURPOSE_OUTPUT_INPUT_Z1 //0x46

#define GPIO_36_SEL_REG PMIO_PAD_CTL_REG_Z1 //0x9A
#define GPIO_36_SEL_DAT 0
#define GPIO_36_OUT_REG (PMIO_GENERAL_PURPOSE_OUTPUT_INPUT_Z1 + 1) //0x47
#define GPIO_36_OUT_DAT 1 << 3
#define GPIO_36_IN_REG  PMIO_GENERAL_PURPOSE_OUTPUT_INPUT_Z1 //0x46

#define GPIO_37_SEL_REG PMIO_PAD_CTL_REG_Z1 //0x9A
#define GPIO_37_SEL_DAT 0
#define GPIO_37_OUT_REG (PMIO_GENERAL_PURPOSE_OUTPUT_INPUT_Z1 + 1) //0x47
#define GPIO_37_OUT_DAT 1 << 4
#define GPIO_37_IN_REG  PMIO_GENERAL_PURPOSE_OUTPUT_INPUT_Z1 //0x46

//
// GPI
//
#define GPI_00_SEL_REG D17F0_PMU_MULTI_FUN_SEL_2 //0xE4
#define GPI_00_SEL_DAT 1 << 1
#define GPI_00_IN_REG  PMIO_GENERAL_PURPOSE_INPUT//0x48


#define GPI_01_IN_REG  PMIO_GENERAL_PURPOSE_INPUT//0x48

#define GPI_02_SEL_REG (D17F0_MISC_CFG_1_PWR_WELL+3) //0x97
#define GPI_02_SEL_DAT 1 << 5
#define GPI_02_IN_REG  PMIO_GENERAL_PURPOSE_INPUT //0x48

#define GPI_03_SEL_REG (D17F0_MISC_CFG_1_PWR_WELL+3) //0x97
#define GPI_03_SEL_DAT 1 << 5
#define GPI_03_IN_REG  PMIO_GENERAL_PURPOSE_INPUT //0x48


#define GPI_04_IN_REG  PMIO_GENERAL_PURPOSE_INPUT //0x48


#define GPI_05_IN_REG  PMIO_GENERAL_PURPOSE_INPUT //0x48


#define GPI_06_IN_REG  PMIO_GENERAL_PURPOSE_INPUT //0x48


#define GPI_07_SEL_REG D17F0_HOST_PM_CTL //0x8C
#define GPI_07_SEL_DAT 1 << 3 
#define GPI_07_IN_REG  PMIO_GENERAL_PURPOSE_INPUT //0x48


#define GPI_10_SEL_REG PMIO_SUSPEND_PWR_DOMAIN //0x6F
#define GPI_10_SEL_DAT 1 << 1
#define GPI_10_IN_REG  (PMIO_GENERAL_PURPOSE_INPUT + 3)//0x4B

//
// GPO
//
#define GPO_00_SEL_REG D17F0_PMU_MULTI_FUN_SEL_2 //0xE4
#define GPO_00_SEL_DAT 1 << 4
#define GPO_00_OUT_REG PMIO_GENERAL_PURPOSE_OUTPUT //0x4C
#define GPO_00_OUT_DAT 1 << 0

#define GPO_01_SEL_REG D17F0_PMU_MULTI_FUN_SEL_2 //0xE4
#define GPO_01_SEL_DAT 1 << 1
#define GPO_01_OUT_REG PMIO_GENERAL_PURPOSE_OUTPUT //0x4C
#define GPO_01_OUT_DAT 1 << 1

#define GPO_02_SEL_REG D17F0_PMU_MULTI_FUN_SEL_2 //0xE4
#define GPO_02_SEL_DAT 1 << 1
#define GPO_02_OUT_REG PMIO_GENERAL_PURPOSE_OUTPUT //0x4C
#define GPO_02_OUT_DAT 1 << 2

#define GPO_03_SEL_REG D17F0_PMU_MULTI_FUN_SEL_2 //0xE4
#define GPO_03_SEL_DAT 1 << 1
#define GPO_03_OUT_REG PMIO_GENERAL_PURPOSE_OUTPUT //0x4C
#define GPO_03_OUT_DAT 1 << 3

#define GPO_04_SEL_REG D17F0_PMU_MISC_CFG_2_PWR_WELL //0x95
#define GPO_04_SEL_DAT 1 << 1
#define GPO_04_OUT_REG PMIO_GENERAL_PURPOSE_OUTPUT //0x4C
#define GPO_04_OUT_DAT 1 << 4


#define GPO_05_SEL_REG D17F0_PMU_MISC_CFG_1_PWR_WELL //0x94
#define GPO_05_SEL_DAT 1 << 2
#define GPO_05_OUT_REG PMIO_GENERAL_PURPOSE_OUTPUT //0x4C
#define GPO_05_OUT_DAT 1 << 5


#define GPO_06_SEL_REG D17F0_PMU_MISC_CFG_1_PWR_WELL //0x94
#define GPO_06_SEL_DAT 1 << 2
#define GPO_06_OUT_REG PMIO_GENERAL_PURPOSE_OUTPUT //0x4C
#define GPO_06_OUT_DAT 1 << 6



#define GPO_07_SEL_REG D17F0_PMU_PM_CAP //0xC0
#define GPO_07_SEL_DAT 1 << 27
#define GPO_07_OUT_REG PMIO_GENERAL_PURPOSE_OUTPUT //0x4C
#define GPO_07_OUT_DAT 1 << 7


#define GPO_36_SEL_REG PMIO_GPIO_PAD_CTL //0xB8
#define GPO_36_SEL_DAT 0
#define GPO_36_OUT_REG PMIO_GENERAL_PURPOSE_OUTPUT_Z1//0x83
#define GPO_36_OUT_DAT 1 << 0

#define GPO_37_SEL_REG PMIO_GPIO_PAD_CTL //0xB8
#define GPO_37_SEL_DAT 0
#define GPO_37_OUT_REG PMIO_GENERAL_PURPOSE_OUTPUT_Z1//0x83
#define GPO_37_OUT_DAT 1 << 1

#define GPO_38_SEL_REG PMIO_GPIO_PAD_CTL //0xB8
#define GPO_38_SEL_DAT 0
#define GPO_38_OUT_REG PMIO_GENERAL_PURPOSE_OUTPUT_Z1//0x83
#define GPO_38_OUT_DAT 1 << 2

#define GPO_39_SEL_REG PMIO_GPIO_PAD_CTL //0xB8
#define GPO_39_SEL_DAT 0
#define GPO_39_OUT_REG PMIO_GENERAL_PURPOSE_OUTPUT_Z1//0x83
#define GPO_39_OUT_DAT 1 << 3

#define GPO_40_SEL_REG PMIO_GPIO_PAD_CTL //0xB8
#define GPO_40_SEL_DAT 0
#define GPO_40_OUT_REG PMIO_GENERAL_PURPOSE_OUTPUT_Z1//0x83
#define GPO_40_OUT_DAT 1 << 4
