//************************************************************************
//************************************************************************
//**									                                **
//**     Copyright (c) 2018 Shanghai Zhaoxin Semiconductor Co., Ltd. 	**
//**     Project:		CHX002					                        **
//**     Module:		TXT					                            **
//**									                                **
//************************************************************************
//************************************************************************
// This file is auto converted by ZhaoXin Irs2h from IRS_CHX002_TXT_R091(A0).doc(final)MOD_TXT.xls
#ifndef _CHX002_TXT_H
#define _CHX002_TXT_H
//TXT
#define TXT_TXT_STA		0x00	//TXT Status
    #define TXT_TXT_RSV00_31_17			0xFFFE0000	//0/x/x/x Reserved
    #define TXT_TXT_LOCALITY2_OPEN_STS			BIT16	//0/x/x/x TXT.LOCALITY2.OPEN.STS
    #define TXT_TXT_LOCALITY1_OPEN_STS			BIT15	//0/x/x/x TXT.LOCALITY1.OPEN.STS
    #define TXT_TXT_RSV00_14_12			(BIT12 + BIT13 + BIT14)	//0/x/x/x Reserved
    #define TXT_MEM_CONFIG_OK_STS			BIT11	//0/x/x/x MEM-CONFIG-OK.STS
    #define TXT_TXT_RSV00_10_8			(BIT8 + BIT9 + BIT10)	//0/x/x/x Reserved
    #define TXT_PRIVATE_OPEN_STS			BIT7	//0/x/x/x PRIVATE-OPEN.STS
    #define TXT_MEM_CONFIG_LOCK_STS			BIT6	//0/x/x/x MEM-CONFIG-LOCK.STS
    #define TXT_BASE_LOCKED_STS			BIT5	//0/x/x/x BASE.LOCKED.STS
    #define TXT_TXT_RSV00_4_2			(BIT2 + BIT3 + BIT4)	//0/x/x/x Reserved
    #define TXT_SEXIT_DONE_STS			BIT1	//HwInit/x/x/x SEXIT.DONE STS
    #define TXT_SENTER_DONE_STS			BIT0	//HwInit/x/x/x SENTER.DONE.STS
#define TXT_TXT_STA_Z1		0x04	//TXT Status
    #define TXT_TXT_RSV04_31_0			0xFFFFFFFF	//0/x/x/x Reserved
#define TXT_TXT_ESTS_ERR_STA		0x08	//TXT.ESTS - Error Status
    #define TXT_TXT_RSV08_31_1			0xFFFFFFFE	//0/x/x/x Reserved
    #define TXT_TXT_ESTS			BIT0	//0/x/x/x TXT.ESTS
#define TXT_TXT_THREADS_EXIST_IXXXX_TXT_THREAD_EXIST_REG_1		0x10	//TXT.THREADS.EXIST- Ixxxx TXT Thread Exist Register 1
    #define TXT_TXT_THREADS_EXIST_31_16			0xFFFF0000	//0/x/x/x TXT.THREADS.EXIST Register 1
    #define TXT_TXT_THREADS_EXIST_15_0			0xFFFF	//HwInit/x/x/x TXT.THREADS.EXIST Register 1
#define TXT_TXT_THREADS_EXIST_IXXXX_TXT_THREAD_EXIST_REG_2		0x14	//TXT.THREADS.EXIST- Ixxxx TXT Thread Exist Register 2
    #define TXT_TXT_THREADS_EXIST_63_32			0xFFFFFFFF	//0/x/x/x TXT.THREADS.EXIST Register 2
#define TXT_TXT_THREADS_JOIN_IXXXX_TXT_THREAD_JOIN_REG_1		0x20	//TXT.THREADS.JOIN- Ixxxx TXT Thread Join Register 1
    #define TXT_TXT_THREADS_JOIN_31_16			0xFFFF0000	//0/x/x/x TXT.THREADS.JOIN Register 1
    #define TXT_TXT_THREADS_JOIN_15_0			0xFFFF	//HwInit/x/x/x TXT.THREADS.JOIN Register 1
#define TXT_TXT_THREADS_JOIN_IXXXX_TXT_THREAD_JOIN_REG_2		0x24	//TXT.THREADS.JOIN- Ixxxx TXT Thread Join Register 2
    #define TXT_TXT_THREADS_JOIN_63_32			0xFFFFFFFF	//0/x/x/x TXT.THREADS.JOIN Register 2
#define TXT_TXT_ESTS_SET		0x28	//TXT.ESTS.SET
    #define TXT_TXT_RSV28_31_8			0xFFFFFF00	//0/x/x/x Reserved
    #define TXT_TXT_RSV28_7_1			0xFE	//0/x/x/x Reserved
    #define TXT_TXT_ESTS_SET_Z1			BIT0	//0/x/x/x TXT_ESTS_SET
#define TXT_TXT_ERRCODE_ERR_CODE		0x30	//TXT.ERRORCODE - Error Code
    #define TXT_TXT_ERROR_VALID			BIT31	//0/x/x/x Valid/Invalid
    #define TXT_TXT_ERROR_PRO			BIT30	//0/x/x/x Processor (ucode)/Software
    #define TXT_TXT_ERROR_TYPE1_13_0			0x3FFF0000	//0/x/x/x Type1
    #define TXT_TXT_ERROR_SSRC			BIT15	//0/x/x/x Software Source
    #define TXT_TXT_ERROR_TYPE2_14_0			0x7FFF	//0/x/x/x Type2
#define TXT_TXT_CMD_RESET_SYSTEM_RESET_CMD		0x38	//TXT.CMD.RESET - System Reset Command
    #define TXT_TXT_RSV38_31_8			0xFFFFFF00	//0/x/x/x Reserved
    #define TXT_TXT_CMD_RESET			0xFF	//0/x/x/x System Reset Command
#define TXT_TXT_CMD_CLOSE_PRIVATE_CLOSE_PRIVATE_SPACE_CMD		0x48	//TXT.CMD.CLOSE-PRIVATE - Close Private Space Command
    #define TXT_TXT_RSV48_31_8			0xFFFFFF00	//0/x/x/x Reserved
    #define TXT_TXT_CMD_CLOSE_PRIVATE_7_0			0xFF	//0/x/x/x Close Private Space Command
#define TXT_TXT_VER_FSBIF_FRONTSIDE_BUS_IF		0x100	//TXT.VER.FSBIF - Frontside Bus Interface
    #define TXT_TXT_VER_FSBIF			BIT31	//HwInit/x/x/x DEBUG.FUSE_1
    #define TXT_TXT_RSV100_30_0			0x7FFFFFFF	//0/x/x/x Reserved
#define TXT_TXT_DIDVID_TXT_DID		0x110	//TXT.DIDVID - TXT Device ID
    #define TXT_TXT_DEVICE_ID_15_0			0xFFFF0000	//0/x/x/x Device ID
    #define TXT_TXT_VENDOR_ID_15_0			0xFFFF	//1106h/x/x/x Vendor ID
#define TXT_TXT_DIDVID_TXT_DID_Z1		0x114	//TXT.DIDVID - TXT Device ID
    #define TXT_TXT_ID_EXT_15_0			0xFFFF0000	//0/x/x/x ID-EXT
    #define TXT_TXT_REVISION_ID_15_0			0xFFFF	//0/x/x/x Revision ID
#define TXT_TXT_VER_QPIIF_IXXXX_QUICKPATH_INTERCONNECT_IF		0x200	//TXT.VER.QPIIF - Ixxxx QuickPath Interconnect Interface
    #define TXT_TXT_VER_QPIIF			BIT31	//HwInit/x/x/x DEBUG.FUSE_2
    #define TXT_TXT_RSV200_30_0			0x7FFFFFFF	//0/x/x/x Reserved
#define TXT_TXT_CMD_LOCK_MEM_CONFIG		0x210	//TXT.CMD.LOCK-MEM-CONFIG
    #define TXT_TXT_RSV210_31_8			0xFFFFFF00	//0/x/x/x Reserved
    #define TXT_TXT_CMD_LOCK_MEM_CONFIG_7_0			0xFF	//0/x/x/x TXT.CMD.LOCK-MEM-CONFIG
#define TXT_TXT_CMD_UNLOCK_MEM_CONFIG		0x218	//TXT.CMD.UNLOCK-MEM-CONFIG
    #define TXT_TXT_RSV218_31_8			0xFFFFFF00	//0/x/x/x Reserved
    #define TXT_TXT_CMD_UNLOCK_MEM_CONFIG_7_0			0xFF	//0/x/x/x TXT.CMD.UNLOCK-MEM-CONFIG
#define TXT_TXT_CMD_MEM_CONFIG_CHECKED		0x220	//TXT.CMD. MEM-CONFIG-CHECKED
    #define TXT_TXT_RSV220_31_8			0xFFFFFF00	//0/x/x/x Reserved
    #define TXT_TXT_CMD_MEM_CONFIG_CHECKED_7_0			0xFF	//0/x/x/x TXT.CMD.MEM-CONFIG-CHECKED
#define TXT_TXT_CMD_LOCK_BASE_LOCK_BASE_CMD_REG		0x230	//TXT.CMD.LOCK.BASE - Lock Base Command Register
    #define TXT_TXT_RSV230_31_8			0xFFFFFF00	//0/x/x/x Reserved
    #define TXT_TXT_CMD_LOCK_BASE_7_0			0xFF	//0/x/x/x TXT.CMD.LOCK.BASE - Lock Base Command Register
#define TXT_TXT_CMD_UNLOCK_BASE_UNLOCK_BASE_CMD_REG		0x238	//TXT.CMD.UNLOCK.BASE - Unlock Base Command Register
    #define TXT_TXT_RSV238_31_8			0xFFFFFF00	//0/x/x/x Reserved
    #define TXT_TXT_CMD_UNLOCK_BASE_7_0			0xFF	//0/x/x/x TXT.CMD.UNLOCK.BASE
#define TXT_TXT_SINIT_BASE_SINIT_BASE_ADR		0x270	//TXT.SINIT.BASE - SINIT Base Address
    #define TXT_TXT_SINIT_BASE_31_0			0xFFFFFFFF	//0/x/x/x TXT_SINIT_BASE
#define TXT_TXT_SINIT_SIZE_SINIT_SIZE		0x278	//TXT.SINIT.SIZE - SINIT Size
    #define TXT_TXT_SINIT_SIZE_31_0			0xFFFFFFFF	//0/x/x/x TXT.SINIT.SIZE
#define TXT_TXT_MLE_JOIN_MLE_JOIN_BASE_ADR		0x290	//TXT.MLE.JOIN - MLE Join Base Address
    #define TXT_TXT_MLE_JOIN_31_0			0xFFFFFFFF	//0/x/x/x TXT_MLE_JOIN
#define TXT_TXT_HEAP_BASE_TXT_HEAP_BASE_ADR		0x300	//TXT.HEAP.BASE - TXT Heap Base Address
    #define TXT_TXT_HEAP_BASE_31_0			0xFFFFFFFF	//0/x/x/x TXT_HEAP_BASE
#define TXT_TXT_HEAP_SIZE_TXT_HEAP_SIZE		0x308	//TXT.HEAP.SIZE - TXT Heap Size
    #define TXT_TXT_HEAP_SIZE_31_0			0xFFFFFFFF	//0/x/x/x TXT_HEAP_SIZE
#define TXT_TXT_MSEG_BASE_MSEG_BASE_REG_0		0x310	//TXT.MSEG.BASE - MSEG Base Register 0
    #define TXT_TXT_MSEG_BASE_31_0			0xFFFFFFFF	//0/x/x/x TXT_MSEG_BASE Register 1
#define TXT_TXT_MSEG_BASE_MSEG_BASE_REG_1		0x314	//TXT.MSEG.BASE - MSEG Base Register 1
    #define TXT_TXT_MSEG_BASE_63_32			0xFFFFFFFF	//0/x/x/x TXT_MSEG_BASE Register 2
#define TXT_TXT_MSEG_SIZE_MSEG_SIZE_REG_1		0x318	//TXT.MSEG.SIZE - MSEG Size Register 1
    #define TXT_TXT_MSEG_SIZE_31_0			0xFFFFFFFF	//0/x/x/x TXT_MSEG_SIZE Register 1
#define TXT_TXT_MSEG_SIZE_MSEG_SIZE_REG_2		0x31C	//TXT.MSEG.SIZE - MSEG Size Register 2
    #define TXT_TXT_MSEG_SIZE_63_0			0xFFFFFFFF	//0/x/x/x TXT_MSEG_SIZE Register 2
#define TXT_TXT_SCRATCHPAD0_SCRATCH_PAD_REG0_1		0x320	//TXT.SCRATCHPAD0 - Scratch Pad Register0 1
    #define TXT_TXT_SCRATCHP_AD0_31_0			0xFFFFFFFF	//0/x/x/x TXT_SCRATCHP_AD0 1
#define TXT_TXT_SCRATCHPAD0_SCRATCH_PAD_REG0_2		0x324	//TXT.SCRATCHPAD0 - Scratch Pad Register0 2
    #define TXT_TXT_SCRATCHP_AD0_63_0			0xFFFFFFFF	//0/x/x/x TXT_SCRATCHP_AD0 2
#define TXT_TXT_SCRATCHPAD1_SCRATCH_PAD_REG1_1		0x328	//TXT.SCRATCHPAD1 - Scratch Pad Register1 1
    #define TXT_TXT_SCRATCHP_AD1_31_0			0xFFFFFFFF	//0/x/x/x TXT_SCRATCHP_AD1 1
#define TXT_TXT_SCRATCHPAD1_SCRATCH_PAD_REG1_2		0x32C	//TXT.SCRATCHPAD1 - Scratch Pad Register1 2
    #define TXT_TXT_SCRATCHP_AD1_63_32			0xFFFFFFFF	//0/x/x/x TXT_SCRATCHP_AD1 2
#define TXT_TXT_DPR_DMA_PROTECTED_RANGE		0x330	//TXT.DPR - DMA Protected Range
    #define TXT_TXT_DPR_TOP_11_0			0xFFF00000	//0/x/x/x TOP
    #define TXT_TXT_RSV330_19_12			0xFF000	//0/x/x/x Reserved
    #define TXT_TXT_DPR_SIZE_7_0			0xFF0	//0/x/x/x SIZE
    #define TXT_TXT_RSV330_3_1			(BIT1 + BIT2 + BIT3)	//0/x/x/x Reserved
    #define TXT_TXT_LOCK			BIT0	//0/x/x/x LOCK
#define TXT_TXT_CMD_OPEN_LOCALITY1_OPEN_LOCALITY_1_CMD		0x380	//TXT.CMD.OPEN.LOCALITY1 - Open Locality 1 Command
    #define TXT_TXT_RSV380_31_8			0xFFFFFF00	//0/x/x/x Reserved
    #define TXT_TXT_CMD_OPEN_LOCALITY1_7_0			0xFF	//0/x/x/x TXT_CMD_OPEN_LOCALITY1
#define TXT_TXT_CMD_CLOSE_LOCALITY1_CLOSE_LOCALITY_1_CMD		0x388	//TXT.CMD.CLOSE.LOCALITY1 - Close Locality 1 Command
    #define TXT_TXT_RSV388_31_8			0xFFFFFF00	//0/x/x/x Reserved
    #define TXT_TXT_CMD_CLOSE_LOCALITY1_7_0			0xFF	//0/x/x/x TXT_CMD_CLOSE.LOCALITY1
#define TXT_TXT_CMD_OPEN_LOCALITY2_OPEN_LOCALITY_2_CMD		0x390	//TXT.CMD.OPEN.LOCALITY2 - Open Locality 2 Command
    #define TXT_TXT_RSV390_31_8			0xFFFFFF00	//0/x/x/x Reserved
    #define TXT_TXT_CMD_OPEN_LOCALITY2_7_0			0xFF	//0/x/x/x TXT_CMD_OPEN_LOCALITY2
#define TXT_TXT_CMD_CLOSE_LOCALITY2_CLOSE_LOCALITY_2_CMD		0x398	//TXT.CMD.CLOSE.LOCALITY2 - CLOSE Locality 2 Command
    #define TXT_TXT_RSV398_31_8			0xFFFFFF00	//0/x/x/x Reserved
    #define TXT_TXT_CMD_CLOSE_LOCALITY2_7_0			0xFF	//0/x/x/x TXT_CMD_CLOSE_LOCALITY2
#define TXT_TXT_PUBLIC_KEY_AC_MODULE_PUBLIC_KEY_HASH		0x400	//TXT.PUBLIC.KEY - AC Module Public Key Hash
    #define TXT_TXT_PUBLIC_KEY3_7_0			0xFF000000	//HwInit/x/x/x TXT_PUBLIC_KEY 1
    #define TXT_TXT_PUBLIC_KEY2_7_0			0xFF0000	//HwInit/x/x/x TXT_PUBLIC_KEY 1
    #define TXT_TXT_PUBLIC_KEY1_7_0			0xFF00	//HwInit/x/x/x TXT_PUBLIC_KEY 1
    #define TXT_TXT_PUBLIC_KEY0_7_0			0xFF	//HwInit/x/x/x TXT_PUBLIC_KEY 1
#define TXT_TXT_PUBLIC_KEY_AC_MODULE_PUBLIC_KEY_HASH_Z1		0x404	//TXT.PUBLIC.KEY - AC Module Public Key Hash
    #define TXT_TXT_PUBLIC_KEY7_7_0			0xFF000000	//HwInit/x/x/x TXT_PUBLIC_KEY 2
    #define TXT_TXT_PUBLIC_KEY6_7_0			0xFF0000	//HwInit/x/x/x TXT_PUBLIC_KEY 2
    #define TXT_TXT_PUBLIC_KEY5_7_0			0xFF00	//HwInit/x/x/x TXT_PUBLIC_KEY 2
    #define TXT_TXT_PUBLIC_KEY4_7_0			0xFF	//HwInit/x/x/x TXT_PUBLIC_KEY 2
#define TXT_TXT_PUBLIC_KEY_AC_MODULE_PUBLIC_KEY_HASH_Z2		0x408	//TXT.PUBLIC.KEY - AC Module Public Key Hash
    #define TXT_TXT_PUBLIC_KEY11_7_0			0xFF000000	//HwInit/x/x/x TXT_PUBLIC_KEY 3
    #define TXT_TXT_PUBLIC_KEY10_7_0			0xFF0000	//HwInit/x/x/x TXT_PUBLIC_KEY 3
    #define TXT_TXT_PUBLIC_KEY9_7_0			0xFF00	//HwInit/x/x/x TXT_PUBLIC_KEY 3
    #define TXT_TXT_PUBLIC_KEY8_7_0			0xFF	//HwInit/x/x/x TXT_PUBLIC_KEY 3
#define TXT_TXT_PUBLIC_KEY_AC_MODULE_PUBLIC_KEY_HASH_Z3		0x40C	//TXT.PUBLIC.KEY - AC Module Public Key Hash
    #define TXT_TXT_PUBLIC_KEY15_7_0			0xFF000000	//HwInit/x/x/x TXT_PUBLIC_KEY 4
    #define TXT_TXT_PUBLIC_KEY14_7_0			0xFF0000	//HwInit/x/x/x TXT_PUBLIC_KEY 4
    #define TXT_TXT_PUBLIC_KEY13_7_0			0xFF00	//HwInit/x/x/x TXT_PUBLIC_KEY 4
    #define TXT_TXT_PUBLIC_KEY12_7_0			0xFF	//HwInit/x/x/x TXT_PUBLIC_KEY 4
#define TXT_TXT_PUBLIC_KEY_AC_MODULE_PUBLIC_KEY_HASH_Z4		0x410	//TXT.PUBLIC.KEY - AC Module Public Key Hash
    #define TXT_TXT_PUBLIC_KEY19_7_0			0xFF000000	//HwInit/x/x/x TXT_PUBLIC_KEY 5
    #define TXT_TXT_PUBLIC_KEY18_7_0			0xFF0000	//HwInit/x/x/x TXT_PUBLIC_KEY 5
    #define TXT_TXT_PUBLIC_KEY17_7_0			0xFF00	//HwInit/x/x/x TXT_PUBLIC_KEY 5
    #define TXT_TXT_PUBLIC_KEY16_7_0			0xFF	//HwInit/x/x/x TXT_PUBLIC_KEY 5
#define TXT_TXT_PUBLIC_KEY_AC_MODULE_PUBLIC_KEY_HASH_Z5		0x414	//TXT.PUBLIC.KEY - AC Module Public Key Hash
    #define TXT_TXT_PUBLIC_KEY23_7_0			0xFF000000	//HwInit/x/x/x TXT_PUBLIC_KEY 6
    #define TXT_TXT_PUBLIC_KEY22_7_0			0xFF0000	//HwInit/x/x/x TXT_PUBLIC_KEY 6
    #define TXT_TXT_PUBLIC_KEY21_7_0			0xFF00	//HwInit/x/x/x TXT_PUBLIC_KEY 6
    #define TXT_TXT_PUBLIC_KEY20_7_0			0xFF	//HwInit/x/x/x TXT_PUBLIC_KEY 6
#define TXT_TXT_PUBLIC_KEY_AC_MODULE_PUBLIC_KEY_HASH_Z6		0x418	//TXT.PUBLIC.KEY - AC Module Public Key Hash
    #define TXT_TXT_PUBLIC_KEY27_7_0			0xFF000000	//HwInit/x/x/x TXT_PUBLIC_KEY 7
    #define TXT_TXT_PUBLIC_KEY26_7_0			0xFF0000	//HwInit/x/x/x TXT_PUBLIC_KEY 7
    #define TXT_TXT_PUBLIC_KEY25_7_0			0xFF00	//HwInit/x/x/x TXT_PUBLIC_KEY 7
    #define TXT_TXT_PUBLIC_KEY24_7_0			0xFF	//HwInit/x/x/x TXT_PUBLIC_KEY 7
#define TXT_TXT_PUBLIC_KEY_AC_MODULE_PUBLIC_KEY_HASH_Z7		0x41C	//TXT.PUBLIC.KEY - AC Module Public Key Hash
    #define TXT_TXT_PUBLIC_KEY31_7_0			0xFF000000	//HwInit/x/x/x TXT_PUBLIC_KEY 8
    #define TXT_TXT_PUBLIC_KEY30_7_0			0xFF0000	//HwInit/x/x/x TXT_PUBLIC_KEY 8
    #define TXT_TXT_PUBLIC_KEY29_7_0			0xFF00	//HwInit/x/x/x TXT_PUBLIC_KEY 8
    #define TXT_TXT_PUBLIC_KEY28_7_0			0xFF	//HwInit/x/x/x TXT_PUBLIC_KEY 8
#define TXT_TXT_CMD_SECRETS_SET_SECRETS_CMD		0x8E0	//TXT.CMD.SECRETS - Set Secrets Command
    #define TXT_TXT_RSV8E0_31_8			0xFFFFFF00	//0/x/x/x Reserved
    #define TXT_TXT_CMD_SECRETS_7_0			0xFF	//0/x/x/x TXT_CMD_SECRETS
#define TXT_TXT_CMD_NO_SECRETS_CLEAN_SECRETS_CMD		0x8E8	//TXT.CMD.NO-SECRETS - Clean Secrets Command
    #define TXT_TXT_RSV8E8_31_8			0xFFFFFF00	//0/x/x/x Reserved
    #define TXT_TXT_CMD_NO_SECRETS_7_0			0xFF	//0/x/x/x TXT_CMD_NO_SECRETS
#define TXT_TXT_E2STS_EXTENDED_ERR_STA		0x8F0	//TXT.E2STS - Extended Error Status
    #define TXT_TXT_RSV8F0_31_2			0xFFFFFFFC	//0/x/x/x Reserved
    #define TXT_TXT_SECRETS_STS			BIT1	//0/x/x/x TXT_SECRETS_STS
    #define TXT_TXT_RSV8F0			BIT0	//0/x/x/x Reserved
#define TXT_TXT_E2STS_EXTENDED_ERR_STA_Z1		0x8F4	//TXT.E2STS - Extended Error Status
    #define TXT_TXT_RSV8F4_31_0			0xFFFFFFFF	//0/x/x/x Reserved
#endif
