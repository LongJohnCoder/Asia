//**********************************************************************
//**********************************************************************
//**                                                                  **
//**     Copyright (c) 2015 Shanghai Zhaoxin Semiconductor Co., Ltd.  **
//**                                                                  **
//**********************************************************************
//**********************************************************************
#ifndef __IOE_PORTING_H__
#define __IOE_PORTING_H__



#define MULTI_IOE_SUPPORT  0


/******************************************************************************
					              	PCIE part
*******************************************************************************/

//
//define the scratch register for IOE Scan Table Flag
//Usage: those two register will provide a 16 bits mask flag, 
//each bit in this field represent a target PORT in IoeSearchTbl[]
//when a bit set to 1, this mean the corresponing PORT was invalid, 
//and even though the IOE was found behind it, SW will skip it and 
//continue to search another IOE.
//
#define SCRATCH_BUS 0
#define SCRATCH_DEV 0
#define SCRATCH_FUN 6
#define VAR_BYTE0_REG  (D0F6_BIOS_SCRATCH_REG_15+2) //0x7A 
#define VAR_BYTE1_REG  (D0F6_BIOS_SCRATCH_REG_15+3)  //0x7B


//
//this table define the relationship between the 'PORT' and 'BitField in VAR_BYTEX_REG'
//Note: 
//	VAR_BYTEX_REG[7:0] = VAR_BYTE0_REG[7:0]
//	VAR_BYTEX_REG[15:8] = VAR_BYTE1_REG[7:0]
//
typedef struct OrderDefined{
	UINT8 BusNum;
	UINT8 DevNum;
	UINT8 FunNum;
	UINT8 Bit;
}ORDER_D;

#define IOE_ORDER_TABLE { \
0,		3,		0, 0,\
0,		3,		1, 1,\
0,		3,		2, 2,\
0,		3,		3, 3,\
0,		4,		0, 4,\
0,		4,		1, 5,\
0,		5,		0, 6,\
0,		5,		1, 7,\
}

//
//this table define all possible PORT for seatching IOE
//
//#define SEARCH_COUNT 6
#define IOE_SEARCH_TABLE { \
0,		3,		0,\
0,		3,		1,\
0,		3,		2,\
0,		3,		3,\
0,		4,		0,\
0,		4,		1,\
0,		5,		0,\
0,		5,		1,\
}


//
//Macro for PERST
// this macro define PERST for IOE, copy from NbPcie.c
//
//Attention:
// using this function to do PERST# for IOE was not encouraged,
// only use for debug is better, and now, we never use this function.
//
#define HOST_PERST_PIN case CHX002_PE0:\
{\
	GpioIndex = GPO_Reset_PE0; \
	break;\
}\
case CHX002_PE1:\
{\
	GpioIndex = GPO_Reset_PE1;\
	break;\
}\
case CHX002_PE2:\
{\
	GpioIndex = GPO_Reset_PE2;\
	break;\
}\
case CHX002_PE3:\
{\
	GpioIndex = GPO_Reset_PE3; \
	break;\
}\
case CHX002_PE4:\
{\
	GpioIndex = GPO_Reset_PE4; 	\
	break;\
}\
case CHX002_PE5:\
{\
	GpioIndex = GPO_Reset_PE5; \
	break;\
}\
case CHX002_PE6:\
{\
	GpioIndex = GPO_Reset_PE6; \
	break;\
}\
case CHX002_PE7:\
{\
	GpioIndex = GPO_Reset_PE7;						\
	break;\
}

//
//Register defination
// here define some platform related registers
//
#define HOST_SCRATCH CHX002_SCRCH
#define HOST_D0F6_BIOS_SCRATCH_REG_2 D0F6_BIOS_SCRATCH_REG_2 
#define HOST_BACKDOOR_APIC CHX002_APIC

#define HOST_PHYLS_LTSSM_STATE    D3D5F1_PHYLS_LTSSM_STATE
	#define HOST_PHYLS_State_L0 PHYLS_State_L0
#define HOST_LINK_STA_1      D3D5F1_LINK_STA_1
#define HOST_LINK_CTL_1 D3D5F1_LINK_CTL_1
	#define HOST_LCRL  D3D5F1_LCRL

#define HOST_UNCORRECTABLE_ERR_STA  D3D5F1_UNCORRECTABLE_ERR_STA
#define HOST_CORRECTABLE_ERR_STA  D3D5F1_CORRECTABLE_ERR_STA
#define HOST_UNCORRECTABLE_ERR_STA  D3D5F1_UNCORRECTABLE_ERR_STA
#define HOST_CORRECTABLE_ERR_STA  D3D5F1_CORRECTABLE_ERR_STA
#define HOST_ROOT_ERR_STA  D3D5F1_ROOT_ERR_STA
#define HOST_DEV_STA_1 D3D5F1_DEV_STA_1
#define HOST_MAC D3D5F1_MAC 
	#define HOST_RLNRVSL D3D5F1_RLNRVSL
#define HOST_BRIDGE_CTL D3D5F1_BRIDGE_CTL 
#define HOST_LINK_CTL_2_D4F0 D3D5F1_LINK_CTL_2_D4F0
	#define HOST_LKTGLS_0 D3D5F1_LKTGLS_0
	#define HOST_LKTGLS_1 D3D5F1_LKTGLS_1
	#define HOST_LKTGLS_2 D3D5F1_LKTGLS_2
	#define HOST_LKTGLS_3 D3D5F1_LKTGLS_3
	
#define HOST_BACKDOOR_D0F5_PMU_CTL D0F5_PMU_CTL 
	#define HOST_BACKDOOR_D0F5_RPEROWEN D0F5_RPEROWEN
#define HOST_LINK_CAPS_1_D4F0 D3D5F1_LINK_CAPS_1_D4F0	
	#define HOST_LKMLW_0 D3D5F1_LKMLW_0
	#define HOST_LKMLW_1 D3D5F1_LKMLW_1
	#define HOST_LKMLW_2 D3D5F1_LKMLW_2
	#define HOST_LKMLW_3 D3D5F1_LKMLW_3
	#define HOST_LKMLW_4 D3D5F1_LKMLW_4
	#define HOST_LKMLW_5 D3D5F1_LKMLW_5
	



//
//GPIO7 control IOE DN port linkup
//	here declare Platforms which need software to control IOE DN port linkup by using GPIO7
//Why not put it in Platform folder?
//   because some upgraded board don't have dedicated Platform Folder, like CHX001 EH0 and EH2
//   EH0 no need to do this , EH2 require it, but they have common Platform Folder
//
#if  defined(HX002EC0_01)||defined(HX002EC0_10)||defined(HX002EH0_01)
#define GPIO7_CTL_LINKUP_PLATFORM  1	
#else
#define GPIO7_CTL_LINKUP_PLATFORM  0	
#endif


//
//CND003 Local GPIO control DN port PERST#
// here declare Platform which need software to control IOE GPIO to release PERST# of ports
//Notice:
// the board design on this is not normally, and most of IOE don't have this board design,
// the later boards not recommand to do this
// to do in CHX002.......
#if defined(ZX_EH2_PCIE_LOGO_FLAG)
#define IOE_GPIO_CTL_PERST_RELEASE 1	
#else
#define IOE_GPIO_CTL_PERST_RELEASE 0
#endif


/******************************************************************************
					              	USB part
*******************************************************************************/
//TODO








/******************************************************************************
					              	SATA part
*******************************************************************************/
//TODO






/******************************************************************************
					              	GNIC part
*******************************************************************************/
//TODO





#endif
