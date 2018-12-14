/** @file
   ZX-E(CHX002) Asia NbPei library functions : NbPcie.c

   Copyright (c) 2018 Shanghai Zhaoxin Semiconductor Co., Ltd. 

**/
   
#include "pei.h"

#include "CHX002Reg.h"
#include "CHX002Cfg.h"

#include "AsiaNbPeim.h"
#include "AsiaIoLib.h"
#include "SbLibPpi.h"
#include "SIPcieDriving.h"
#include "PeiLib.h"
#include EFI_PPI_DEFINITION(AsiaCpuPpi)
#include <AsiaSbPeim.h>
#ifdef IOE_EXIST
#include "..\..\SB\CND003\IoePreInit.h"
#include "..\..\SB\CND003\IoeDebugSignal.h"
#include "CND003Reg.h"
#endif

#include "PciHotPlug.h"

#ifdef PCIE_ACPI_SHPC_SUPPORT_CHX002

#define PCAL6416A_PCIE_HOTPLUG_SUPPORT_CHX002   1
#endif

#ifdef PCIE_ACPI_SHPC_SUPPORT_IOE

#define PCAL6416A_PCIE_HOTPLUG_SUPPORT_IOE    1
#endif


//DaisyZhang added 20170622, move from REG_CHX002_PCIEPHY.h
#include "NbPcie.h"
#include "NbPcieCommon.h"
/*+ DSZ_Porting (ALN-2017081701) Set to E mode before root port release link.*/ 
#include "NbPciePETable.h"
/*- DSZ_Porting (ALN-2017081701) Set to E mode before root port release link.*/ 


//LNA-2016122701-E
/*+ DSZ_Porting -- (JIH-2017081701) Remove NbPcie.c Configuration Cycle Control init setting*/
//STATIC ASIA_IO_TABLE_6408_REV mPCIEPeiInitTbl[]=
//{
//    0x00, 0xFF, CHX002_APIC|D0F5_CFG_CYCLE_CTL_1,               0x33, 0x33,             //Rx60[5:4],[1:0]
//};
/*- DSZ_Porting -- (JIH-2017081701) Remove NbPcie.c Configuration Cycle Control init setting*/
STATIC ASIA_IO_TABLE_6408_REV mPCIEPeiMmioInitTbl[]=
{
    //S value different with Default Value, so set it !
    //Disable  Downstream Lock Cycle Support
    //lna_pcie_debug 0x00, 0xFF, CHX001_PEG|((UINT64)(D3D5F1_DOWNSTREAM_CTL_1) << 32),   0x10, 0x00, //Rx1A0[4]
    //lna_pcie_debug 0x00, 0xFF, CHX001_PE0|((UINT64)(D3D5F1_DOWNSTREAM_CTL_1) << 32),   0x10, 0x00, //Rx1A0[4]
    //0x00, 0xFF, CHX001_PE1|((UINT64)(D3D5F1_DOWNSTREAM_CTL_1) << 32),   0x10, 0x00, //Rx1A0[4]
    //0x00, 0xFF, CHX001_PE2|((UINT64)(D3D5F1_DOWNSTREAM_CTL_1) << 32),   0x10, 0x00, //Rx1A0[4]
    //0x00, 0xFF, CHX001_PE3|((UINT64)(D3D5F1_DOWNSTREAM_CTL_1) << 32),   0x10, 0x00, //Rx1A0[4]
    //0x00, 0xFF, CHX001_PEG0|((UINT64)(D3D5F1_DOWNSTREAM_CTL_1) << 32),   0x10, 0x00, //Rx1A0[4]
    //0x00, 0xFF, CHX001_PEG1|((UINT64)(D3D5F1_DOWNSTREAM_CTL_1) << 32),   0x10, 0x00, //Rx1A0[4]
    //0x00, 0xFF, CHX001_PEG2|((UINT64)(D3D5F1_DOWNSTREAM_CTL_1) << 32),   0x10, 0x00, //Rx1A0[4]
    //0x00, 0xFF, CHX001_PEG3|((UINT64)(D3D5F1_DOWNSTREAM_CTL_1) << 32),   0x10, 0x00, //Rx1A0[4]

/*
//CHX002_20170509 removed
    //Disable hardware autonomous speed negotiation
    0x00, 0xFF, CHX002_PE0|((UINT64)(D3D5F1_LINK_CTL_2_D4F0) << 32),   0x20, 0x20, //Rx70[5]
	0x00, 0xFF, CHX002_PE2|((UINT64)(D3D5F1_LINK_CTL_2_D4F0) << 32),	 0x20, 0x20, //Rx70[5]
    0x00, 0xFF, CHX002_PE1|((UINT64)(D3D5F1_LINK_CTL_2_D4F0) << 32),   0x20, 0x20, //Rx70[5]
    0x00, 0xFF, CHX002_PE3|((UINT64)(D3D5F1_LINK_CTL_2_D4F0) << 32),   0x20, 0x20, //Rx70[5]
    0x00, 0xFF, CHX002_PE4|((UINT64)(D3D5F1_LINK_CTL_2_D4F0) << 32),   0x20, 0x20, //Rx70[5]
    //0x00, 0xFF, CHX002_PE5|((UINT64)(D3D5F1_LINK_CTL_2_D4F0) << 32),   0x20, 0x20, //Rx70[5]
    0x00, 0xFF, CHX002_PE6|((UINT64)(D3D5F1_LINK_CTL_2_D4F0) << 32),   0x20, 0x20, //Rx70[5]
    0x00, 0xFF, CHX002_PE7|((UINT64)(D3D5F1_LINK_CTL_2_D4F0) << 32),   0x20, 0x20, //Rx70[5]
*/
	0xff, 0x00, 0,0,0
};

//;cjw_debug_pcie - start
typedef enum {
  DSTX = 0,
  DSRX,
  USTX,
  USRX
} PresetType;

typedef struct {
        UINT16          VID;            //; Target Device VID
        UINT16          DID;            //; Target Device DID
        UINT16          Reg;            //; EQ Preset Control Reg
        PresetType      PT;                     //; EQ Preset Type for Upstream/DownStream, Tx/Rx
        UINT8           Value;          //; EQ Preset Setting
} EQPresetTbl;


#if 0   //CJW_20170512 removed -- not used now
EQPresetTbl SKPEQ_Manual_Tbl[] = {
//Test Device - Intel 750 SSD
//      Reg,                                                                                                                            PT,             Value
        (UINT16)0x8068, (UINT16)0x0953, (UINT16)PCIEPHYCFG_EQUALIZATION_CTL_REG_ORIGINAL_VALUE_X8B_LANE00,      DSTX,   0x00,
        (UINT16)0x8068, (UINT16)0x0953, (UINT16)PCIEPHYCFG_EQUALIZATION_CTL_REG_ORIGINAL_VALUE_X8B_LANE00,      DSRX,   0x00,
        (UINT16)0x8068, (UINT16)0x0953, (UINT16)PCIEPHYCFG_EQUALIZATION_CTL_REG_ORIGINAL_VALUE_X8B_LANE00,      USTX,   0x00,
        (UINT16)0x8068, (UINT16)0x0953, (UINT16)PCIEPHYCFG_EQUALIZATION_CTL_REG_ORIGINAL_VALUE_X8B_LANE00,      USRX,   0x00,   
        (UINT16)0x8068, (UINT16)0x0953, (UINT16)PCIEPHYCFG_EQUALIZATION_CTL_REG_ORIGINAL_VALUE_X8B_LANE01,      DSTX,   0x00,
        (UINT16)0x8068, (UINT16)0x0953, (UINT16)PCIEPHYCFG_EQUALIZATION_CTL_REG_ORIGINAL_VALUE_X8B_LANE01,      DSRX,   0x00,
        (UINT16)0x8068, (UINT16)0x0953, (UINT16)PCIEPHYCFG_EQUALIZATION_CTL_REG_ORIGINAL_VALUE_X8B_LANE01,      USTX,   0x00,
        (UINT16)0x8068, (UINT16)0x0953, (UINT16)PCIEPHYCFG_EQUALIZATION_CTL_REG_ORIGINAL_VALUE_X8B_LANE01,      USRX,   0x00,   
        (UINT16)0x8068, (UINT16)0x0953, (UINT16)PCIEPHYCFG_EQUALIZATION_CTL_REG_ORIGINAL_VALUE_X8B_LANE02,      DSTX,   0x00,
        (UINT16)0x8068, (UINT16)0x0953, (UINT16)PCIEPHYCFG_EQUALIZATION_CTL_REG_ORIGINAL_VALUE_X8B_LANE02,      DSRX,   0x00,
        (UINT16)0x8068, (UINT16)0x0953, (UINT16)PCIEPHYCFG_EQUALIZATION_CTL_REG_ORIGINAL_VALUE_X8B_LANE02,      USTX,   0x00,
        (UINT16)0x8068, (UINT16)0x0953, (UINT16)PCIEPHYCFG_EQUALIZATION_CTL_REG_ORIGINAL_VALUE_X8B_LANE02,      USRX,   0x00,   
        (UINT16)0x8068, (UINT16)0x0953, (UINT16)PCIEPHYCFG_EQUALIZATION_CTL_REG_ORIGINAL_VALUE_X8B_LANE03,      DSTX,   0x00,
        (UINT16)0x8068, (UINT16)0x0953, (UINT16)PCIEPHYCFG_EQUALIZATION_CTL_REG_ORIGINAL_VALUE_X8B_LANE03,      DSRX,   0x00,
        (UINT16)0x8068, (UINT16)0x0953, (UINT16)PCIEPHYCFG_EQUALIZATION_CTL_REG_ORIGINAL_VALUE_X8B_LANE03,      USTX,   0x00,
        (UINT16)0x8068, (UINT16)0x0953, (UINT16)PCIEPHYCFG_EQUALIZATION_CTL_REG_ORIGINAL_VALUE_X8B_LANE03,      USRX,   0x00,   
        (UINT16)0x8068, (UINT16)0x0953, (UINT16)PCIEPHYCFG_EQUALIZATION_CTL_REG_ORIGINAL_VALUE_X8B_LANE03,      DSTX,   0x00,
        (UINT16)0x8068, (UINT16)0x0953, (UINT16)PCIEPHYCFG_EQUALIZATION_CTL_REG_ORIGINAL_VALUE_X8B_LANE03,      DSRX,   0x00,
        (UINT16)0x8068, (UINT16)0x0953, (UINT16)PCIEPHYCFG_EQUALIZATION_CTL_REG_ORIGINAL_VALUE_X8B_LANE03,      USTX,   0x00,
        (UINT16)0x8068, (UINT16)0x0953, (UINT16)PCIEPHYCFG_EQUALIZATION_CTL_REG_ORIGINAL_VALUE_X8B_LANE03,      USRX,   0x00,   
        (UINT16)0x8068, (UINT16)0x0953, (UINT16)PCIEPHYCFG_EQUALIZATION_CTL_REG_ORIGINAL_VALUE_X8B_LANE05,      DSTX,   0x00,
        (UINT16)0x8068, (UINT16)0x0953, (UINT16)PCIEPHYCFG_EQUALIZATION_CTL_REG_ORIGINAL_VALUE_X8B_LANE05,      DSRX,   0x00,
        (UINT16)0x8068, (UINT16)0x0953, (UINT16)PCIEPHYCFG_EQUALIZATION_CTL_REG_ORIGINAL_VALUE_X8B_LANE05,      USTX,   0x00,
        (UINT16)0x8068, (UINT16)0x0953, (UINT16)PCIEPHYCFG_EQUALIZATION_CTL_REG_ORIGINAL_VALUE_X8B_LANE05,      USRX,   0x00,
        (UINT16)0x8068, (UINT16)0x0953, (UINT16)PCIEPHYCFG_EQUALIZATION_CTL_REG_ORIGINAL_VALUE_X8B_LANE06,      DSTX,   0x00,
        (UINT16)0x8068, (UINT16)0x0953, (UINT16)PCIEPHYCFG_EQUALIZATION_CTL_REG_ORIGINAL_VALUE_X8B_LANE06,      DSRX,   0x00,
        (UINT16)0x8068, (UINT16)0x0953, (UINT16)PCIEPHYCFG_EQUALIZATION_CTL_REG_ORIGINAL_VALUE_X8B_LANE06,      USTX,   0x00,
        (UINT16)0x8068, (UINT16)0x0953, (UINT16)PCIEPHYCFG_EQUALIZATION_CTL_REG_ORIGINAL_VALUE_X8B_LANE06,      USRX,   0x00,   
        (UINT16)0x8068, (UINT16)0x0953, (UINT16)PCIEPHYCFG_EQUALIZATION_CTL_REG_ORIGINAL_VALUE_X8B_LANE07,      DSTX,   0x00,
        (UINT16)0x8068, (UINT16)0x0953, (UINT16)PCIEPHYCFG_EQUALIZATION_CTL_REG_ORIGINAL_VALUE_X8B_LANE07,      DSRX,   0x00,
        (UINT16)0x8068, (UINT16)0x0953, (UINT16)PCIEPHYCFG_EQUALIZATION_CTL_REG_ORIGINAL_VALUE_X8B_LANE07,      USTX,   0x00,
        (UINT16)0x8068, (UINT16)0x0953, (UINT16)PCIEPHYCFG_EQUALIZATION_CTL_REG_ORIGINAL_VALUE_X8B_LANE07,      USRX,   0x00,   
        (UINT16)0x8068, (UINT16)0x0953, (UINT16)PCIEPHYCFG_EQUALIZATION_CTL_REG_ORIGINAL_VALUE_X8C_LANE00,      DSTX,   0x00,
        (UINT16)0x8068, (UINT16)0x0953, (UINT16)PCIEPHYCFG_EQUALIZATION_CTL_REG_ORIGINAL_VALUE_X8C_LANE00,      DSRX,   0x00,
        (UINT16)0x8068, (UINT16)0x0953, (UINT16)PCIEPHYCFG_EQUALIZATION_CTL_REG_ORIGINAL_VALUE_X8C_LANE00,      USTX,   0x00,
        (UINT16)0x8068, (UINT16)0x0953, (UINT16)PCIEPHYCFG_EQUALIZATION_CTL_REG_ORIGINAL_VALUE_X8C_LANE00,      USRX,   0x00,   
        (UINT16)0x8068, (UINT16)0x0953, (UINT16)PCIEPHYCFG_EQUALIZATION_CTL_REG_ORIGINAL_VALUE_X8C_LANE01,      DSTX,   0x00,
        (UINT16)0x8068, (UINT16)0x0953, (UINT16)PCIEPHYCFG_EQUALIZATION_CTL_REG_ORIGINAL_VALUE_X8C_LANE01,      DSRX,   0x00,
        (UINT16)0x8068, (UINT16)0x0953, (UINT16)PCIEPHYCFG_EQUALIZATION_CTL_REG_ORIGINAL_VALUE_X8C_LANE01,      USTX,   0x00,
        (UINT16)0x8068, (UINT16)0x0953, (UINT16)PCIEPHYCFG_EQUALIZATION_CTL_REG_ORIGINAL_VALUE_X8C_LANE01,      USRX,   0x00,
        (UINT16)0x8068, (UINT16)0x0953, (UINT16)PCIEPHYCFG_EQUALIZATION_CTL_REG_ORIGINAL_VALUE_X8C_LANE02,      DSTX,   0x00,
        (UINT16)0x8068, (UINT16)0x0953, (UINT16)PCIEPHYCFG_EQUALIZATION_CTL_REG_ORIGINAL_VALUE_X8C_LANE02,      DSRX,   0x00,
        (UINT16)0x8068, (UINT16)0x0953, (UINT16)PCIEPHYCFG_EQUALIZATION_CTL_REG_ORIGINAL_VALUE_X8C_LANE02,      USTX,   0x00,
        (UINT16)0x8068, (UINT16)0x0953, (UINT16)PCIEPHYCFG_EQUALIZATION_CTL_REG_ORIGINAL_VALUE_X8C_LANE02,      USRX,   0x00,
        (UINT16)0x8068, (UINT16)0x0953, (UINT16)PCIEPHYCFG_EQUALIZATION_CTL_REG_ORIGINAL_VALUE_X8C_LANE03,      DSTX,   0x00,
        (UINT16)0x8068, (UINT16)0x0953, (UINT16)PCIEPHYCFG_EQUALIZATION_CTL_REG_ORIGINAL_VALUE_X8C_LANE03,      DSRX,   0x00,
        (UINT16)0x8068, (UINT16)0x0953, (UINT16)PCIEPHYCFG_EQUALIZATION_CTL_REG_ORIGINAL_VALUE_X8C_LANE03,      USTX,   0x00,
        (UINT16)0x8068, (UINT16)0x0953, (UINT16)PCIEPHYCFG_EQUALIZATION_CTL_REG_ORIGINAL_VALUE_X8C_LANE03,      USRX,   0x00,   
        (UINT16)0x8068, (UINT16)0x0953, (UINT16)PCIEPHYCFG_EQUALIZATION_CTL_REG_ORIGINAL_VALUE_X8C_LANE04,      DSTX,   0x00,
        (UINT16)0x8068, (UINT16)0x0953, (UINT16)PCIEPHYCFG_EQUALIZATION_CTL_REG_ORIGINAL_VALUE_X8C_LANE04,      DSRX,   0x00,
        (UINT16)0x8068, (UINT16)0x0953, (UINT16)PCIEPHYCFG_EQUALIZATION_CTL_REG_ORIGINAL_VALUE_X8C_LANE04,      USTX,   0x00,
        (UINT16)0x8068, (UINT16)0x0953, (UINT16)PCIEPHYCFG_EQUALIZATION_CTL_REG_ORIGINAL_VALUE_X8C_LANE04,      USRX,   0x00,   
        (UINT16)0x8068, (UINT16)0x0953, (UINT16)PCIEPHYCFG_EQUALIZATION_CTL_REG_ORIGINAL_VALUE_X8C_LANE05,      DSTX,   0x00,
        (UINT16)0x8068, (UINT16)0x0953, (UINT16)PCIEPHYCFG_EQUALIZATION_CTL_REG_ORIGINAL_VALUE_X8C_LANE05,      DSRX,   0x00,
        (UINT16)0x8068, (UINT16)0x0953, (UINT16)PCIEPHYCFG_EQUALIZATION_CTL_REG_ORIGINAL_VALUE_X8C_LANE05,      USTX,   0x00,
        (UINT16)0x8068, (UINT16)0x0953, (UINT16)PCIEPHYCFG_EQUALIZATION_CTL_REG_ORIGINAL_VALUE_X8C_LANE05,      USRX,   0x00,   
        (UINT16)0x8068, (UINT16)0x0953, (UINT16)PCIEPHYCFG_EQUALIZATION_CTL_REG_ORIGINAL_VALUE_X8C_LANE06,      DSTX,   0x00,
        (UINT16)0x8068, (UINT16)0x0953, (UINT16)PCIEPHYCFG_EQUALIZATION_CTL_REG_ORIGINAL_VALUE_X8C_LANE06,      DSRX,   0x00,
        (UINT16)0x8068, (UINT16)0x0953, (UINT16)PCIEPHYCFG_EQUALIZATION_CTL_REG_ORIGINAL_VALUE_X8C_LANE06,      USTX,   0x00,
        (UINT16)0x8068, (UINT16)0x0953, (UINT16)PCIEPHYCFG_EQUALIZATION_CTL_REG_ORIGINAL_VALUE_X8C_LANE06,      USRX,   0x00,
        (UINT16)0x8068, (UINT16)0x0953, (UINT16)PCIEPHYCFG_EQUALIZATION_CTL_REG_ORIGINAL_VALUE_X8C_LANE07,      DSTX,   0x00,
        (UINT16)0x8068, (UINT16)0x0953, (UINT16)PCIEPHYCFG_EQUALIZATION_CTL_REG_ORIGINAL_VALUE_X8C_LANE07,      DSRX,   0x00,
        (UINT16)0x8068, (UINT16)0x0953, (UINT16)PCIEPHYCFG_EQUALIZATION_CTL_REG_ORIGINAL_VALUE_X8C_LANE07,      USTX,   0x00,
        (UINT16)0x8068, (UINT16)0x0953, (UINT16)PCIEPHYCFG_EQUALIZATION_CTL_REG_ORIGINAL_VALUE_X8C_LANE07,      USRX,   0x00,
        (UINT16)0x8068, (UINT16)0x0953, (UINT16)PCIEPHYCFG_EQUALIZATION_CTL_REG_ORIGINAL_VALUE_X8A_LANE00,      DSTX,   0x00,
        (UINT16)0x8068, (UINT16)0x0953, (UINT16)PCIEPHYCFG_EQUALIZATION_CTL_REG_ORIGINAL_VALUE_X8A_LANE00,      DSRX,   0x00,
        (UINT16)0x8068, (UINT16)0x0953, (UINT16)PCIEPHYCFG_EQUALIZATION_CTL_REG_ORIGINAL_VALUE_X8A_LANE00,      USTX,   0x00,
        (UINT16)0x8068, (UINT16)0x0953, (UINT16)PCIEPHYCFG_EQUALIZATION_CTL_REG_ORIGINAL_VALUE_X8A_LANE00,      USRX,   0x00,   
        (UINT16)0x8068, (UINT16)0x0953, (UINT16)PCIEPHYCFG_EQUALIZATION_CTL_REG_ORIGINAL_VALUE_X8A_LANE01,      DSTX,   0x00,
        (UINT16)0x8068, (UINT16)0x0953, (UINT16)PCIEPHYCFG_EQUALIZATION_CTL_REG_ORIGINAL_VALUE_X8A_LANE01,      DSRX,   0x00,
        (UINT16)0x8068, (UINT16)0x0953, (UINT16)PCIEPHYCFG_EQUALIZATION_CTL_REG_ORIGINAL_VALUE_X8A_LANE01,      USTX,   0x00,
        (UINT16)0x8068, (UINT16)0x0953, (UINT16)PCIEPHYCFG_EQUALIZATION_CTL_REG_ORIGINAL_VALUE_X8A_LANE01,      USRX,   0x00,
        (UINT16)0x8068, (UINT16)0x0953, (UINT16)PCIEPHYCFG_EQUALIZATION_CTL_REG_ORIGINAL_VALUE_X8A_LANE02,      DSTX,   0x00,
        (UINT16)0x8068, (UINT16)0x0953, (UINT16)PCIEPHYCFG_EQUALIZATION_CTL_REG_ORIGINAL_VALUE_X8A_LANE02,      DSRX,   0x00,
        (UINT16)0x8068, (UINT16)0x0953, (UINT16)PCIEPHYCFG_EQUALIZATION_CTL_REG_ORIGINAL_VALUE_X8A_LANE02,      USTX,   0x00,
        (UINT16)0x8068, (UINT16)0x0953, (UINT16)PCIEPHYCFG_EQUALIZATION_CTL_REG_ORIGINAL_VALUE_X8A_LANE02,      USRX,   0x00,
        (UINT16)0x8068, (UINT16)0x0953, (UINT16)PCIEPHYCFG_EQUALIZATION_CTL_REG_ORIGINAL_VALUE_X8A_LANE03,      DSTX,   0x00,
        (UINT16)0x8068, (UINT16)0x0953, (UINT16)PCIEPHYCFG_EQUALIZATION_CTL_REG_ORIGINAL_VALUE_X8A_LANE03,      DSRX,   0x00,
        (UINT16)0x8068, (UINT16)0x0953, (UINT16)PCIEPHYCFG_EQUALIZATION_CTL_REG_ORIGINAL_VALUE_X8A_LANE03,      USTX,   0x00,
        (UINT16)0x8068, (UINT16)0x0953, (UINT16)PCIEPHYCFG_EQUALIZATION_CTL_REG_ORIGINAL_VALUE_X8A_LANE03,      USRX,   0x00,
        (UINT16)0x8068, (UINT16)0x0953, (UINT16)PCIEPHYCFG_EQUALIZATION_CTL_REG_ORIGINAL_VALUE_X8A_LANE04,      DSTX,   0x00,
        (UINT16)0x8068, (UINT16)0x0953, (UINT16)PCIEPHYCFG_EQUALIZATION_CTL_REG_ORIGINAL_VALUE_X8A_LANE04,      DSRX,   0x00,
        (UINT16)0x8068, (UINT16)0x0953, (UINT16)PCIEPHYCFG_EQUALIZATION_CTL_REG_ORIGINAL_VALUE_X8A_LANE04,      USTX,   0x00,
        (UINT16)0x8068, (UINT16)0x0953, (UINT16)PCIEPHYCFG_EQUALIZATION_CTL_REG_ORIGINAL_VALUE_X8A_LANE04,      USRX,   0x00,
        (UINT16)0x8068, (UINT16)0x0953, (UINT16)PCIEPHYCFG_EQUALIZATION_CTL_REG_ORIGINAL_VALUE_X8A_LANE05,      DSTX,   0x00,
        (UINT16)0x8068, (UINT16)0x0953, (UINT16)PCIEPHYCFG_EQUALIZATION_CTL_REG_ORIGINAL_VALUE_X8A_LANE05,      DSRX,   0x00,
        (UINT16)0x8068, (UINT16)0x0953, (UINT16)PCIEPHYCFG_EQUALIZATION_CTL_REG_ORIGINAL_VALUE_X8A_LANE05,      USTX,   0x00,
        (UINT16)0x8068, (UINT16)0x0953, (UINT16)PCIEPHYCFG_EQUALIZATION_CTL_REG_ORIGINAL_VALUE_X8A_LANE05,      USRX,   0x00,
        (UINT16)0x8068, (UINT16)0x0953, (UINT16)PCIEPHYCFG_EQUALIZATION_CTL_REG_ORIGINAL_VALUE_X8A_LANE06,      DSTX,   0x00,
        (UINT16)0x8068, (UINT16)0x0953, (UINT16)PCIEPHYCFG_EQUALIZATION_CTL_REG_ORIGINAL_VALUE_X8A_LANE06,      DSRX,   0x00,
        (UINT16)0x8068, (UINT16)0x0953, (UINT16)PCIEPHYCFG_EQUALIZATION_CTL_REG_ORIGINAL_VALUE_X8A_LANE06,      USTX,   0x00,
        (UINT16)0x8068, (UINT16)0x0953, (UINT16)PCIEPHYCFG_EQUALIZATION_CTL_REG_ORIGINAL_VALUE_X8A_LANE06,      USRX,   0x00,
        (UINT16)0x8068, (UINT16)0x0953, (UINT16)PCIEPHYCFG_EQUALIZATION_CTL_REG_ORIGINAL_VALUE_X8A_LANE07,      DSTX,   0x00,
        (UINT16)0x8068, (UINT16)0x0953, (UINT16)PCIEPHYCFG_EQUALIZATION_CTL_REG_ORIGINAL_VALUE_X8A_LANE07,      DSRX,   0x00,
        (UINT16)0x8068, (UINT16)0x0953, (UINT16)PCIEPHYCFG_EQUALIZATION_CTL_REG_ORIGINAL_VALUE_X8A_LANE07,      USTX,   0x00,
        (UINT16)0x8068, (UINT16)0x0953, (UINT16)PCIEPHYCFG_EQUALIZATION_CTL_REG_ORIGINAL_VALUE_X8A_LANE07,      USRX,   0x00,

};
//;cjw_debug_pcie - end
#endif



//;ysw_debug - 20161012 - start

typedef struct {
        PCIE_CFG        PECFG;                    //; PECFG Setting
 //       UINT8           PEG_IOAPICRouting;          //; PCIE APIC Routing for PEG
        UINT8           PE6_IOAPICRouting;         //; PCIE APIC Routing for PE6
        UINT8           PE7_IOAPICRouting;         //; PCIE APIC Routing for PE7
} PEIOAPICTbl;

PEIOAPICTbl PEIOAPIC_Tbl[] = {

//      PECFG,                 PE6_IOAPICRouting,         PE7_IOAPICRouting
//					conflict with PE4			conflict with PE0
		PECFG_0,		0x01, 					0x00,
		PECFG_1,		0x01,					0x01,
		PECFG_2,		0x01,					0x01,
		PECFG_3,		0x01,					0x01,
		PECFG_4,		0x01,					0x01,
		PECFG_5,		0x01,					0x01,
		PECFG_6,		0x01,					0x01,
		PECFG_7,		0x00,					0x01,
		PECFG_8,		0x01,					0x00,
		PECFG_9,		0x00,					0x00,
		PECFG_10,		0x01,					0x01,
		PECFG_11,		0x01,					0x00,
};

//;ysw_debug - 20161012 - end

/**
   This Function Set EQ Preset manually.
  
  @param  PeiServices   EFI_PEI_SERVICES pointer.
  @param  pNbConfig  point to ASIA_NB_CONFIGURATION

  @return The value from this function.

**/
EFI_STATUS
PeiNbSetEQPresetManual(
    IN EFI_PEI_SERVICES **PeiServices,
    IN ASIA_NB_CONFIGURATION *NbConfig    
)
{
	UINT64 PciePhyBase = NbConfig->PcieEPHYBar;
	
	//
	//UP Rx Hint - 7
	//UP Tx - F
	//DP Rx Hint - 7
	//DP Tx - F
	//
	AsiaMemoryWrite16(PciePhyBase + PCIEPHYCFG_EQUALIZATION_CTL_REG_ORIGINAL_VALUE_LANE00,NbConfig->PcieEqCtlOrgValL0);
	AsiaMemoryWrite16(PciePhyBase + PCIEPHYCFG_EQUALIZATION_CTL_REG_ORIGINAL_VALUE_LANE01,NbConfig->PcieEqCtlOrgValL1);
	AsiaMemoryWrite16(PciePhyBase + PCIEPHYCFG_EQUALIZATION_CTL_REG_ORIGINAL_VALUE_LANE02,NbConfig->PcieEqCtlOrgValL2);
	AsiaMemoryWrite16(PciePhyBase + PCIEPHYCFG_EQUALIZATION_CTL_REG_ORIGINAL_VALUE_LANE03,NbConfig->PcieEqCtlOrgValL3);
	AsiaMemoryWrite16(PciePhyBase + PCIEPHYCFG_EQUALIZATION_CTL_REG_ORIGINAL_VALUE_LANE04,NbConfig->PcieEqCtlOrgValL4);
	AsiaMemoryWrite16(PciePhyBase + PCIEPHYCFG_EQUALIZATION_CTL_REG_ORIGINAL_VALUE_LANE05,NbConfig->PcieEqCtlOrgValL5);
	AsiaMemoryWrite16(PciePhyBase + PCIEPHYCFG_EQUALIZATION_CTL_REG_ORIGINAL_VALUE_LANE06,NbConfig->PcieEqCtlOrgValL6);
	AsiaMemoryWrite16(PciePhyBase + PCIEPHYCFG_EQUALIZATION_CTL_REG_ORIGINAL_VALUE_LANE07,NbConfig->PcieEqCtlOrgValL7);
	AsiaMemoryWrite16(PciePhyBase + PCIEPHYCFG_EQUALIZATION_CTL_REG_ORIGINAL_VALUE_LANE08,NbConfig->PcieEqCtlOrgValL8);
	AsiaMemoryWrite16(PciePhyBase + PCIEPHYCFG_EQUALIZATION_CTL_REG_ORIGINAL_VALUE_LANE09,NbConfig->PcieEqCtlOrgValL9);
	AsiaMemoryWrite16(PciePhyBase + PCIEPHYCFG_EQUALIZATION_CTL_REG_ORIGINAL_VALUE_LANE10,NbConfig->PcieEqCtlOrgValL10);
	AsiaMemoryWrite16(PciePhyBase + PCIEPHYCFG_EQUALIZATION_CTL_REG_ORIGINAL_VALUE_LANE11,NbConfig->PcieEqCtlOrgValL11);
	AsiaMemoryWrite16(PciePhyBase + PCIEPHYCFG_EQUALIZATION_CTL_REG_ORIGINAL_VALUE_LANE12,NbConfig->PcieEqCtlOrgValL12);
	AsiaMemoryWrite16(PciePhyBase + PCIEPHYCFG_EQUALIZATION_CTL_REG_ORIGINAL_VALUE_LANE13,NbConfig->PcieEqCtlOrgValL13);
	AsiaMemoryWrite16(PciePhyBase + PCIEPHYCFG_EQUALIZATION_CTL_REG_ORIGINAL_VALUE_LANE14,NbConfig->PcieEqCtlOrgValL14);
	AsiaMemoryWrite16(PciePhyBase + PCIEPHYCFG_EQUALIZATION_CTL_REG_ORIGINAL_VALUE_LANE15,NbConfig->PcieEqCtlOrgValL15);

	return  EFI_SUCCESS;
}


/**
   This Function set Equalization.
   This function must be called after PCIE SI register setting done
   to avoid the  EQ Manual setting coverd by SI setting

  @param  PeiServices   EFI_PEI_SERVICES pointer.
  @param  pNbConfig  point to ASIA_NB_CONFIGURATION

  @return The value from this function.

**/

EFI_STATUS
PeiNbSetEqualization(
    IN EFI_PEI_SERVICES **PeiServices,
    IN ASIA_NB_CONFIGURATION *NbConfig    
)
{
	UINT64 PcieBase = NbConfig->PcieBar;
	UINT64 PciePhyBase = NbConfig->PcieEPHYBar;

    //CHX001-CJW-20151019 Only deal with the EQ condition of SKPEQ_MANUAL
    if(NbConfig->PcieEQ == SKPEQ_MANUAL){
        PeiNbSetEQPresetManual(PeiServices, NbConfig);
    } 
	
		if((NbConfig->PcieEQ == DOEQ)&&(NbConfig->PcieEQPE0 == 1)&&(NbConfig->PciePE0)){
			PEI_DEBUG((PeiServices, EFI_D_ERROR, "[PCIE_EQ] PE0 DOEQ\n"));
			AsiaPcieModify8(PcieBase,CHX002_PE0|(((UINT64)D3D5F1_MISC_CTL) << 32),D3D5F1_RWTEXEPH23,D3D5F1_RWTEXEPH23);
		}else{
			AsiaPcieModify8(PcieBase,CHX002_PE0|(((UINT64)D3D5F1_MISC_CTL) << 32),D3D5F1_RWTEXEPH23,0);
		}
		if((NbConfig->PcieEQ == DOEQ)&&(NbConfig->PcieEQPE1 == 1)&&(NbConfig->PciePE1)){
			PEI_DEBUG((PeiServices, EFI_D_ERROR, "[PCIE_EQ] PE1 DOEQ\n"));
			AsiaPcieModify8(PcieBase,CHX002_PE1|(((UINT64)D3D5F1_MISC_CTL) << 32),D3D5F1_RWTEXEPH23,D3D5F1_RWTEXEPH23);
		}else{
			AsiaPcieModify8(PcieBase,CHX002_PE1|(((UINT64)D3D5F1_MISC_CTL) << 32),D3D5F1_RWTEXEPH23,0);
		}
		if((NbConfig->PcieEQ == DOEQ)&&(NbConfig->PcieEQPE2 == 1)&&(NbConfig->PciePE2)){
			PEI_DEBUG((PeiServices, EFI_D_ERROR, "[PCIE_EQ] PE2 DOEQ\n"));
			AsiaPcieModify8(PcieBase,CHX002_PE2|(((UINT64)D3D5F1_MISC_CTL) << 32),D3D5F1_RWTEXEPH23,D3D5F1_RWTEXEPH23);
		}else{
			AsiaPcieModify8(PcieBase,CHX002_PE2|(((UINT64)D3D5F1_MISC_CTL) << 32),D3D5F1_RWTEXEPH23,0);
		}	
		if((NbConfig->PcieEQ == DOEQ)&&(NbConfig->PcieEQPE3 == 1)&&(NbConfig->PciePE3)){
			PEI_DEBUG((PeiServices, EFI_D_ERROR, "[PCIE_EQ] PE3 DOEQ\n"));
			AsiaPcieModify8(PcieBase,CHX002_PE3|(((UINT64)D3D5F1_MISC_CTL) << 32),D3D5F1_RWTEXEPH23,D3D5F1_RWTEXEPH23);
		}else{
			AsiaPcieModify8(PcieBase,CHX002_PE3|(((UINT64)D3D5F1_MISC_CTL) << 32),D3D5F1_RWTEXEPH23,0);
		}
		if((NbConfig->PcieEQ == DOEQ)&&(NbConfig->PcieEQPE4 == 1)&&(NbConfig->PciePE4)){
			PEI_DEBUG((PeiServices, EFI_D_ERROR, "[PCIE_EQ] PE4 DOEQ\n"));
			AsiaPcieModify8(PcieBase,CHX002_PE4|(((UINT64)D3D5F1_MISC_CTL) << 32),D3D5F1_RWTEXEPH23,D3D5F1_RWTEXEPH23);
		}else{
			AsiaPcieModify8(PcieBase,CHX002_PE4|(((UINT64)D3D5F1_MISC_CTL) << 32),D3D5F1_RWTEXEPH23,0);
		}
		if((NbConfig->PcieEQ == DOEQ)&&(NbConfig->PcieEQPE5 == 1)&&(NbConfig->PciePE5)){
			PEI_DEBUG((PeiServices, EFI_D_ERROR, "[PCIE_EQ] PE5 DOEQ\n"));
			AsiaPcieModify8(PcieBase,CHX002_PE5|(((UINT64)D3D5F1_MISC_CTL) << 32),D3D5F1_RWTEXEPH23,D3D5F1_RWTEXEPH23);
		}else{
			AsiaPcieModify8(PcieBase,CHX002_PE5|(((UINT64)D3D5F1_MISC_CTL) << 32),D3D5F1_RWTEXEPH23,0);
		}
		if((NbConfig->PcieEQ == DOEQ)&&(NbConfig->PcieEQPE6 == 1)&&(NbConfig->PciePE6)){
			PEI_DEBUG((PeiServices, EFI_D_ERROR, "[PCIE_EQ] PE6 DOEQ\n"));
			AsiaPcieModify8(PcieBase,CHX002_PE6|(((UINT64)D3D5F1_MISC_CTL) << 32),D3D5F1_RWTEXEPH23,D3D5F1_RWTEXEPH23);
		}else{
			AsiaPcieModify8(PcieBase,CHX002_PE6|(((UINT64)D3D5F1_MISC_CTL) << 32),D3D5F1_RWTEXEPH23,0);
		}
		if((NbConfig->PcieEQ == DOEQ)&&(NbConfig->PcieEQPE7 == 1)&&(NbConfig->PciePE7)){
			PEI_DEBUG((PeiServices, EFI_D_ERROR, "[PCIE_EQ] PE7 DOEQ\n"));
			AsiaPcieModify8(PcieBase,CHX002_PE7|(((UINT64)D3D5F1_MISC_CTL) << 32),D3D5F1_RWTEXEPH23,D3D5F1_RWTEXEPH23);
		}else{
			AsiaPcieModify8(PcieBase,CHX002_PE7|(((UINT64)D3D5F1_MISC_CTL) << 32),D3D5F1_RWTEXEPH23,0);
		}


	if(NbConfig->PcieEQ == DOEQ){
		//RW Promission for CPU
		//	when you need to delivery some parameters or data to PEMCU, you may need to put them into EPHY MMIO space,
		//	and PEMCU can get them from its EPHY address range. 
		//  	but the CPU access promission on some EPHY MMIO registers was controlled by this control register,
		// 	so if you need to delivery some data to PEMCU or give command to it, set this bit to 1b is required,
		//	details pls refer to EPHY IRS
		AsiaMemoryModify8(PciePhyBase+PCIEPHYCFG_PCIE_ROMSIP_REG,PCIEPHYCFG_R_PEMCU_BIOS,PCIEPHYCFG_R_PEMCU_BIOS);

		// Those register must be set as 10b or 11b for the lanes using Eye Monitor Engine
		//	if not set, the specific lane will not return eye monitor result correctly
		// 	we set all lanes as 10b here
		AsiaMemoryModify8(PciePhyBase+PCIEPHYCFG_RCV_CDR_EQ_CTL_1_LANE_00,PCIEPHYCFG_FHP00_ABCSEL_CDR,2<<2);
		AsiaMemoryModify8(PciePhyBase+PCIEPHYCFG_RCV_CDR_EQ_CTL_1_LANE_01,PCIEPHYCFG_FHP00_ABCSEL_CDR,2<<2);
		AsiaMemoryModify8(PciePhyBase+PCIEPHYCFG_RCV_CDR_EQ_CTL_1_LANE_02,PCIEPHYCFG_FHP00_ABCSEL_CDR,2<<2);
		AsiaMemoryModify8(PciePhyBase+PCIEPHYCFG_RCV_CDR_EQ_CTL_1_LANE_03,PCIEPHYCFG_FHP00_ABCSEL_CDR,2<<2);
		AsiaMemoryModify8(PciePhyBase+PCIEPHYCFG_RCV_CDR_EQ_CTL_1_LANE_04,PCIEPHYCFG_FHP00_ABCSEL_CDR,2<<2);
		AsiaMemoryModify8(PciePhyBase+PCIEPHYCFG_RCV_CDR_EQ_CTL_1_LANE_05,PCIEPHYCFG_FHP00_ABCSEL_CDR,2<<2);
		AsiaMemoryModify8(PciePhyBase+PCIEPHYCFG_RCV_CDR_EQ_CTL_1_LANE_06,PCIEPHYCFG_FHP00_ABCSEL_CDR,2<<2);
		AsiaMemoryModify8(PciePhyBase+PCIEPHYCFG_RCV_CDR_EQ_CTL_1_LANE_07,PCIEPHYCFG_FHP00_ABCSEL_CDR,2<<2);
		AsiaMemoryModify8(PciePhyBase+PCIEPHYCFG_RCV_CDR_EQ_CTL_1_LANE_08,PCIEPHYCFG_FHP00_ABCSEL_CDR,2<<2);
		AsiaMemoryModify8(PciePhyBase+PCIEPHYCFG_RCV_CDR_EQ_CTL_1_LANE_09,PCIEPHYCFG_FHP00_ABCSEL_CDR,2<<2);
		AsiaMemoryModify8(PciePhyBase+PCIEPHYCFG_RCV_CDR_EQ_CTL_1_LANE_10,PCIEPHYCFG_FHP00_ABCSEL_CDR,2<<2);
		AsiaMemoryModify8(PciePhyBase+PCIEPHYCFG_RCV_CDR_EQ_CTL_1_LANE_11,PCIEPHYCFG_FHP00_ABCSEL_CDR,2<<2);
		AsiaMemoryModify8(PciePhyBase+PCIEPHYCFG_RCV_CDR_EQ_CTL_1_LANE_12,PCIEPHYCFG_FHP00_ABCSEL_CDR,2<<2);
		AsiaMemoryModify8(PciePhyBase+PCIEPHYCFG_RCV_CDR_EQ_CTL_1_LANE_13,PCIEPHYCFG_FHP00_ABCSEL_CDR,2<<2);
		AsiaMemoryModify8(PciePhyBase+PCIEPHYCFG_RCV_CDR_EQ_CTL_1_LANE_14,PCIEPHYCFG_FHP00_ABCSEL_CDR,2<<2);
		AsiaMemoryModify8(PciePhyBase+PCIEPHYCFG_RCV_CDR_EQ_CTL_1_LANE_15,PCIEPHYCFG_FHP00_ABCSEL_CDR,2<<2);
	}



	if((NbConfig->PcieEQ == DOEQ)&&(NbConfig->PcieDoEqMethod == METHOD_RXEQ)){
		//Enable this is open the write promission on all EPHY registers for PEMCU
		// 	this is because RXEQ require Write Promission on some EPHY registers for PEMCU,
		//	and this bit can provide this promission
		AsiaMemoryModify8((NbConfig->RcrbhBar)+RCRBH_MISC_0, RCRBH_R_PEMCU_ACCESS_ALL, RCRBH_R_PEMCU_ACCESS_ALL);

		//Change this bit for EPHY RxEQ Adaptive Equalizer duration 
		//	after setting those registers, RxEQ waiting time can be cut down, and save much time for EQ phase3
		AsiaPcieModify8(PcieBase,CHX002_PE0|(((UINT64)D3D5F1_GEN2_MAC_ENHANCEMENT) << 32),D3D5F1_REQLZTM,0x0);
		AsiaPcieModify8(PcieBase,CHX002_PE1|(((UINT64)D3D5F1_GEN2_MAC_ENHANCEMENT) << 32),D3D5F1_REQLZTM,0x0);
		AsiaPcieModify8(PcieBase,CHX002_PE2|(((UINT64)D3D5F1_GEN2_MAC_ENHANCEMENT) << 32),D3D5F1_REQLZTM,0x0);
		AsiaPcieModify8(PcieBase,CHX002_PE3|(((UINT64)D3D5F1_GEN2_MAC_ENHANCEMENT) << 32),D3D5F1_REQLZTM,0x0);

		AsiaPcieModify8(PcieBase,CHX002_PE4|(((UINT64)D3D5F1_GEN2_MAC_ENHANCEMENT) << 32),D3D5F1_REQLZTM,0x0);
		AsiaPcieModify8(PcieBase,CHX002_PE5|(((UINT64)D3D5F1_GEN2_MAC_ENHANCEMENT) << 32),D3D5F1_REQLZTM,0x0);
		AsiaPcieModify8(PcieBase,CHX002_PE6|(((UINT64)D3D5F1_GEN2_MAC_ENHANCEMENT) << 32),D3D5F1_REQLZTM,0x0);
		AsiaPcieModify8(PcieBase,CHX002_PE7|(((UINT64)D3D5F1_GEN2_MAC_ENHANCEMENT) << 32),D3D5F1_REQLZTM,0x0);
	}

    return  EFI_SUCCESS;
}


#if 0
/**
	-- Do not Execute EQ phase 2/3
	-- In "SKIP EQ MANUAL" or "SKIP EQ TABLE" mode, we need to call this routine 
		to skip EQ
**/

EFI_STATUS
PeiNbSkipEQ(
    IN UINT64 PcieBase,
    IN UINT64 RPAddress
)
{
    AsiaPcieModify8(PcieBase, RPAddress|((UINT64)D3D5F1_MISC_CTL << 32), D3D5F1_RWTEXEPH23, 0);             //Skip EQ through Setting RP_Rx290[4] = 0b

    return  EFI_SUCCESS;
}
//;cjw_debug_pcie -end
#endif

/**
   This Function Check pcie error status.
  
  @param  PeiServices   EFI_PEI_SERVICES pointer.
  @param  pNbConfig  point to ASIA_NB_CONFIGURATION
  @param PciAddress target pci device address

  @return The value from this function.

**/
EFI_STATUS PeiNbCheckPcieErrorStatus (
    IN EFI_PEI_SERVICES **PeiServices,
    IN ASIA_NB_CONFIGURATION *NbConfig,
    IN UINT64 PciAddress
)
{
    UINT32 D32;
    UINT64 PcieBase, RPpcieAddress;
    UINT8 D8;

    PcieBase = NbConfig->PcieBar;
    RPpcieAddress = PciAddress;

    D32 = AsiaPcieRead32(PcieBase, RPpcieAddress|(((UINT64)D3D5F1_UNCORRECTABLE_ERR_STA) << 32));       //Rx104
    if(D32)
    {
        PEI_DEBUG((PeiServices, EFI_D_ERROR, "\n RP PCIE Address: %lx, UCERR Status: %x\n",
                   RPpcieAddress, D32));
        return EFI_DEVICE_ERROR;
    }

    D32 = AsiaPcieRead32(PcieBase, RPpcieAddress|(((UINT64)D3D5F1_CORRECTABLE_ERR_STA) << 32)); //Rx110
    if(D32)
    {
        PEI_DEBUG((PeiServices, EFI_D_ERROR, "\n RP PCIE Address: %lx, CERR Status: %x\n",
                   RPpcieAddress, D32));
        return EFI_DEVICE_ERROR;
    }

    D8 = AsiaPcieRead8(PcieBase, RPpcieAddress|(((UINT64)D3D5F1_DEV_STA_1) << 32));     //Rx4A
    if(D8 & (D3D5F1_DSCED + D3D5F1_DSNFED + D3D5F1_DSFED + D3D5F1_DSURD))
    {
        PEI_DEBUG((PeiServices, EFI_D_ERROR, "\n RP PCIE Address: %lx, Dev Status: %x\n",
                   RPpcieAddress, D8));
        return EFI_DEVICE_ERROR;
    }

    D32 = AsiaPcieRead32(PcieBase, RPpcieAddress|(((UINT64)D3D5F1_VC0_RESRC_STA) << 32));       //Rx15A
    if(D32 & D3D5F1_VCRSNP0)
    {
        PEI_DEBUG((PeiServices, EFI_D_ERROR, "\n RP PCIE Address: %lx, VC0RES Status: %x\n",
                   RPpcieAddress, D32));
        return EFI_DEVICE_ERROR;
    }
    return EFI_SUCCESS;
}

/**
   This Function Check PCIE Link status.
  
  @param  PeiServices   EFI_PEI_SERVICES pointer.
  @param  pNbConfig  point to ASIA_NB_CONFIGURATION
  @param PciAddress target pci device address
  @param TempBus target pci bus number

  @return The value from this function.

**/
EFI_STATUS
PeiNbCheckPcieLinkStatus (
    IN EFI_PEI_SERVICES **PeiServices,
    IN ASIA_NB_CONFIGURATION *NbConfig,
    IN UINT64 PciAddress,
    IN UINT8 TempBus

)
{
    UINT8 D8;
    UINT32 D32;
    UINT64 PcieBase;
    UINT16 Loop16;
    BOOLEAN PcieStatus;

    PEI_DEBUG((PeiServices, EFI_D_ERROR, "PeiNbCheckPciePortLinkStatus()\n"));

    PcieStatus = TRUE;

    //Get PCIE MMIO base address
    PcieBase = NbConfig->PcieBar;
    PEI_DEBUG((PeiServices, EFI_D_ERROR, "PCIE Base Address: %x\n", PcieBase));

    //Set PCIe secondary Bus and subordinate Bus Num
    D8 = TempBus;
    AsiaPciWrite8(PciAddress|D3D5F1_SECONDARY_BUS_NUM, D8);     //Rx19
    AsiaPciWrite8(PciAddress|D3D5F1_SUBORDINATE_BUS_NUM, D8);   //Rx1A

    //Wait PCIe In L0 for a while
    for(Loop16 =0; Loop16<0x8000; Loop16++)
    {
        D8 = AsiaPcieRead8(PcieBase, PciAddress|(((UINT64)D3D5F1_PHYLS_LTSSM_STATE) << 32));    //Rx1C3
        if (D8 == PHYLS_State_L0)
        {
            break;
        }
    }
    PEI_DEBUG((PeiServices, EFI_D_ERROR, "D3D5F1_PHYLS_LTSSM_STATE: %x\n", D8));

/*
//CJW_20170510 removed
	//Clear PCIe Error Status
    D32 = 0xffffffff;
    AsiaPcieWrite32(PcieBase, PciAddress|(((UINT64)D3D5F1_UNCORRECTABLE_ERR_STA) << 32), D32);  //Rx104
    AsiaPcieWrite32(PcieBase, PciAddress|(((UINT64)D3D5F1_CORRECTABLE_ERR_STA) << 32), D32);    //Rx110
    AsiaPciModify8(PciAddress|D3D5F1_DEV_STA_1, 0x0F, 0x0F);    //Rx4A[3:0]
*/
    PcieStatus = FALSE;
    //Check PCIE Error Status
    if(PeiNbCheckPcieErrorStatus(PeiServices, NbConfig, PciAddress) == EFI_SUCCESS)
    {
        // if no Error read Device ID
        PEI_DEBUG((PeiServices, EFI_D_ERROR, "no Error read Device ID\n"));
        for (Loop16=0; Loop16<0x1000; Loop16++)
        {
            D32 = AsiaPciRead32(ASIA_PCI_ADDRESS(TempBus, 0, 0, 0));

            if (D32 != 0xFFFFFFFF)              //if read ID success
            {
                if (PeiNbCheckPcieErrorStatus(PeiServices, NbConfig, PciAddress) == EFI_SUCCESS) //but error occur
                {
                    PcieStatus = TRUE;
                }
                else
                {
                    PEI_DEBUG((PeiServices, EFI_D_ERROR, "\n Read Device ID error,Loop16:%x \n",Loop16));
                    PcieStatus = FALSE;
                    break;
                }
            }
            else
            {
                PEI_DEBUG((PeiServices, EFI_D_ERROR, "\n Device ID is 0xffffffff \n"));
                PcieStatus = FALSE;
                break;
            }
        }
    }

    //Reset PCIe secondary Bus and subordinate Bus Num
    D8 = 0;
    AsiaPciWrite8(PciAddress|D3D5F1_SECONDARY_BUS_NUM, D8);     //Rx19
    AsiaPciWrite8(PciAddress|D3D5F1_SUBORDINATE_BUS_NUM, D8);   //Rx1A

    PEI_DEBUG((PeiServices, EFI_D_ERROR, "PCIeStatus = %02x\n", PcieStatus));
    if (!PcieStatus)
    {
        return EFI_DEVICE_ERROR;
    }
    return EFI_SUCCESS;
}
/*+ DSZ_Porting (JIH-2017081401) Remove some PCIe delay for Boot time optimization*/
//CJW_20180119: this function can be moved to COMMON.c later. Just keep here now.
#if 0
void
PeiNbCheckPcieLinkAfterLinkUp (
    IN EFI_PEI_SERVICES **PeiServices,
    IN ASIA_NB_CONFIGURATION *NbConfig,
    IN UINT64 PciAddress
 )
{
    UINT64 PcieBase;
    UINT16 i, regprint;

    PcieBase = NbConfig->PcieBar;    //0xE0000000

    PEI_DEBUG((PeiServices, EFI_D_ERROR, "PeiNbCheckPcieLinkAfterLinkUp()\n"));

    if((AsiaPciRead8(PciAddress|D3D5F1_SLOT_STA_1)) & D3D5F1_SPDCST){
		if((AsiaPcieRead8(PcieBase, PciAddress|((UINT64)D3D5F1_PHYLS_LTSSM_STATE << 32))) < PHYLS_State_L0){
			AsiaIoWrite8(0x80,0xAA);
		       PEI_DEBUG((PeiServices, EFI_D_ERROR, "PeiNbCheckPcieLinkAfterLinkUp() - LTSSM not 0x8A\n"));

		       for(i=0; i <= 512 ; i++) {

		       	if(i%16 == 0)
			       	PEI_DEBUG((PeiServices, EFI_D_ERROR, "\n"));

		       	regprint =  AsiaPciRead8(PciAddress |i) ;
		       	PEI_DEBUG((PeiServices, EFI_D_ERROR, "%02X ",regprint));
				}
			}
		else{
			AsiaIoWrite8(0x80,0xBB);
			}
		}
}
/*- DSZ_Porting (JIH-2017081401) Remove some PCIe delay for Boot time optimization*/
#endif

/**
   This Function get Root Port capability.

  CHX001-CJW-20151025
  In this function ,  we get the capability of one RP   and if capability can reach to Gen3, 
  we decide whether skip EQ or not.
  
  @param  PeiServices	EFI_PEI_SERVICES pointer.
  @param  pNbConfig  point to ASIA_NB_CONFIGURATION
  @param PciAddress target pci device's address
  @param PcieCap    point to PCIE_Cap struct

  @return The value from this function.

**/
EFI_STATUS
PeiNbGetRPCap(
    IN EFI_PEI_SERVICES **PeiServices,
    IN ASIA_NB_CONFIGURATION *NbConfig,
    IN UINT64 PciAddress,
    OUT PCIE_Cap *PcieCap
){

    UINT64 PcieBase;
    UINT32 RomsipCap;
    UINT8 RpCap3;
    //PCIE_Cap RpCap3;
    UINT8 Shift = 1;

    PcieBase = NbConfig->PcieBar;

    switch(PciAddress){
        case CHX002_PE0:
            Shift = 16;
            break;
        case CHX002_PE1:
            Shift = 14;
            break;
        case CHX002_PE2:
            Shift = 12;
            break;
        case CHX002_PE3:
            Shift = 10;
            break;
        case CHX002_PE4:
            Shift = 8;
            break;
        case CHX002_PE5:
            Shift = 6;
            break;
        case CHX002_PE6:
            Shift = 4;
            break;
        case CHX002_PE7:
            Shift = 2;
            break;
        default :
            PEI_DEBUG((PeiServices, EFI_D_INFO, "       Shift Invalid\n"));  
            break;                        
        }       

        RomsipCap = AsiaPciRead32(CHX002_GFXAX|D0F0_PCIE_ROMSIP_REGS);
        PEI_DEBUG((PeiServices, EFI_D_ERROR, "       PCIE RimsipCap RxF8 = 0x%08x\n",RomsipCap));
        RpCap3 = ((RomsipCap>>Shift) & 0x3);    
        //RpCap3 += 1;                  //In D0F0 romsip reg Gen1=00b, But in D2D5F1 Link Capability/Control reg Gen1 = 11b
                                                        //Update the IRS to R90 and both same - CJW
        PEI_DEBUG((PeiServices, EFI_D_ERROR, "       for this port, the RpCap setting = 0x%x\n",RpCap3));
        //skip EQ?
        /*  CJW_201800123: move to 
        if((PCIE_Cap)RpCap3 == PE_GEN3){
            if(NbConfig->PcieEQ == SKPEQ_TABLE || NbConfig->PcieEQ == SKPEQ_MANUAL){
                PeiNbSkipEQ(PcieBase, PciAddress);
            }
        }*/

        *PcieCap = (PCIE_Cap)RpCap3;
        
        return EFI_SUCCESS;
}

/*+ DSZ_Porting Need to check*/
//CJW-20180119:yes, CHX002 don't have this complex EPHY mapping relation,remove it!
/*void PCIeEcfgMapping(
    IN EFI_PEI_SERVICES **PeiServices,
    IN ASIA_NB_CONFIGURATION *NbConfig,
    IN UINT64 PciAddress,
    IN UINT8 UpDnPort,
    IN UINT16 TxPreset
)
{
	UINT8 ECFG, SELPHYA, SELPHYBC, LoopIndex;
	UINT16 TPMask;
	ECFG = (AsiaPciRead8(CHX002_GFXAX |D0F0_PCIE_ROMSIP_REGS_Z1) & D0F0_RPCIESATACFG_3_0);
	SELPHYA = ECFG % 4;
	SELPHYBC = ECFG;
	TPMask = PCIEPHYCFG_DSTXPRESETORG_X8A_00;

	PEI_DEBUG((PeiServices, EFI_D_ERROR, "PCIeEcfgMapping() Pci Addr: %08X\n",PciAddress));

	for(LoopIndex = 0; LoopIndex <=3; LoopIndex++){
		if(SELPHYBC <=3){
			SELPHYBC = LoopIndex;
			break;
			}
		SELPHYBC = SELPHYBC -4;
		}
	
	if(UpDnPort == USTX){
		TxPreset = TxPreset << 8;
		TPMask = TPMask << 8;
		}

	PEI_DEBUG((PeiServices, EFI_D_ERROR, "DSUS = %X, TxPreset = %X, TxPresetMask = %X \n",UpDnPort ,TxPreset ,TPMask));
	
	switch(SELPHYA)
		{
			case 0:
				if(PciAddress == CHX001_PEG){
					AsiaMemoryModify16(NbConfig->PcieEPHYBar |PCIEPHYCFG_EQUALIZATION_CTL_REG_ORIGINAL_VALUE_X8A_LANE00,TPMask,TxPreset);
					AsiaMemoryModify16(NbConfig->PcieEPHYBar |PCIEPHYCFG_EQUALIZATION_CTL_REG_ORIGINAL_VALUE_X8A_LANE01,TPMask,TxPreset);
					AsiaMemoryModify16(NbConfig->PcieEPHYBar |PCIEPHYCFG_EQUALIZATION_CTL_REG_ORIGINAL_VALUE_X8A_LANE02,TPMask,TxPreset);
					AsiaMemoryModify16(NbConfig->PcieEPHYBar |PCIEPHYCFG_EQUALIZATION_CTL_REG_ORIGINAL_VALUE_X8A_LANE03,TPMask,TxPreset);
					AsiaMemoryModify16(NbConfig->PcieEPHYBar |PCIEPHYCFG_EQUALIZATION_CTL_REG_ORIGINAL_VALUE_X8A_LANE04,TPMask,TxPreset);
					AsiaMemoryModify16(NbConfig->PcieEPHYBar |PCIEPHYCFG_EQUALIZATION_CTL_REG_ORIGINAL_VALUE_X8A_LANE05,TPMask,TxPreset);
					AsiaMemoryModify16(NbConfig->PcieEPHYBar |PCIEPHYCFG_EQUALIZATION_CTL_REG_ORIGINAL_VALUE_X8A_LANE06,TPMask,TxPreset);
					AsiaMemoryModify16(NbConfig->PcieEPHYBar |PCIEPHYCFG_EQUALIZATION_CTL_REG_ORIGINAL_VALUE_X8A_LANE07,TPMask,TxPreset);
					}
			break;

			case 1:
				if(PciAddress == CHX001_PEG){
					AsiaMemoryModify16(NbConfig->PcieEPHYBar |PCIEPHYCFG_EQUALIZATION_CTL_REG_ORIGINAL_VALUE_X8A_LANE00,TPMask,TxPreset);
					AsiaMemoryModify16(NbConfig->PcieEPHYBar |PCIEPHYCFG_EQUALIZATION_CTL_REG_ORIGINAL_VALUE_X8A_LANE01,TPMask,TxPreset);
					AsiaMemoryModify16(NbConfig->PcieEPHYBar |PCIEPHYCFG_EQUALIZATION_CTL_REG_ORIGINAL_VALUE_X8A_LANE02,TPMask,TxPreset);
					AsiaMemoryModify16(NbConfig->PcieEPHYBar |PCIEPHYCFG_EQUALIZATION_CTL_REG_ORIGINAL_VALUE_X8A_LANE03,TPMask,TxPreset);
					}
				
				if(PciAddress == CHX001_PE0){
					AsiaMemoryModify16(NbConfig->PcieEPHYBar |PCIEPHYCFG_EQUALIZATION_CTL_REG_ORIGINAL_VALUE_X8A_LANE04,TPMask,TxPreset);
					AsiaMemoryModify16(NbConfig->PcieEPHYBar |PCIEPHYCFG_EQUALIZATION_CTL_REG_ORIGINAL_VALUE_X8A_LANE05,TPMask,TxPreset);
					AsiaMemoryModify16(NbConfig->PcieEPHYBar |PCIEPHYCFG_EQUALIZATION_CTL_REG_ORIGINAL_VALUE_X8A_LANE06,TPMask,TxPreset);
					AsiaMemoryModify16(NbConfig->PcieEPHYBar |PCIEPHYCFG_EQUALIZATION_CTL_REG_ORIGINAL_VALUE_X8A_LANE07,TPMask,TxPreset);
					}
			break;
					
			case 2:
				if(PciAddress == CHX001_PEG){
					AsiaMemoryModify16(NbConfig->PcieEPHYBar |PCIEPHYCFG_EQUALIZATION_CTL_REG_ORIGINAL_VALUE_X8A_LANE00,TPMask,TxPreset);
					AsiaMemoryModify16(NbConfig->PcieEPHYBar |PCIEPHYCFG_EQUALIZATION_CTL_REG_ORIGINAL_VALUE_X8A_LANE01,TPMask,TxPreset);
					AsiaMemoryModify16(NbConfig->PcieEPHYBar |PCIEPHYCFG_EQUALIZATION_CTL_REG_ORIGINAL_VALUE_X8A_LANE02,TPMask,TxPreset);
					AsiaMemoryModify16(NbConfig->PcieEPHYBar |PCIEPHYCFG_EQUALIZATION_CTL_REG_ORIGINAL_VALUE_X8A_LANE03,TPMask,TxPreset);
					}
				
				if(PciAddress == CHX001_PE0){
					AsiaMemoryModify16(NbConfig->PcieEPHYBar |PCIEPHYCFG_EQUALIZATION_CTL_REG_ORIGINAL_VALUE_X8A_LANE04,TPMask,TxPreset);
					}
				if(PciAddress == CHX001_PE1){
					AsiaMemoryModify16(NbConfig->PcieEPHYBar |PCIEPHYCFG_EQUALIZATION_CTL_REG_ORIGINAL_VALUE_X8A_LANE05,TPMask,TxPreset);
					}
				if(PciAddress == CHX001_PE2){
					AsiaMemoryModify16(NbConfig->PcieEPHYBar |PCIEPHYCFG_EQUALIZATION_CTL_REG_ORIGINAL_VALUE_X8A_LANE06,TPMask,TxPreset);
					}
				if(PciAddress == CHX001_PE3){
					AsiaMemoryModify16(NbConfig->PcieEPHYBar |PCIEPHYCFG_EQUALIZATION_CTL_REG_ORIGINAL_VALUE_X8A_LANE07,TPMask,TxPreset);
					}
			break;

			case 3:
				if(PciAddress == CHX001_PEG){
					AsiaMemoryModify16(NbConfig->PcieEPHYBar |PCIEPHYCFG_EQUALIZATION_CTL_REG_ORIGINAL_VALUE_X8A_LANE00,TPMask,TxPreset);
					AsiaMemoryModify16(NbConfig->PcieEPHYBar |PCIEPHYCFG_EQUALIZATION_CTL_REG_ORIGINAL_VALUE_X8A_LANE01,TPMask,TxPreset);
					AsiaMemoryModify16(NbConfig->PcieEPHYBar |PCIEPHYCFG_EQUALIZATION_CTL_REG_ORIGINAL_VALUE_X8A_LANE02,TPMask,TxPreset);
					AsiaMemoryModify16(NbConfig->PcieEPHYBar |PCIEPHYCFG_EQUALIZATION_CTL_REG_ORIGINAL_VALUE_X8A_LANE03,TPMask,TxPreset);
					}
				
				if(PciAddress == CHX001_PE0){
					AsiaMemoryModify16(NbConfig->PcieEPHYBar |PCIEPHYCFG_EQUALIZATION_CTL_REG_ORIGINAL_VALUE_X8A_LANE04,TPMask,TxPreset);
					AsiaMemoryModify16(NbConfig->PcieEPHYBar |PCIEPHYCFG_EQUALIZATION_CTL_REG_ORIGINAL_VALUE_X8A_LANE05,TPMask,TxPreset);
					}
				if(PciAddress == CHX001_PE2){
					AsiaMemoryModify16(NbConfig->PcieEPHYBar |PCIEPHYCFG_EQUALIZATION_CTL_REG_ORIGINAL_VALUE_X8A_LANE06,TPMask,TxPreset);
					}
				if(PciAddress == CHX001_PE3){
					AsiaMemoryModify16(NbConfig->PcieEPHYBar |PCIEPHYCFG_EQUALIZATION_CTL_REG_ORIGINAL_VALUE_X8A_LANE07,TPMask,TxPreset);
					}
			break;

		}
		
	switch(SELPHYBC)
		{
			case 0:
				if(PciAddress == CHX001_PEG0){
					AsiaMemoryModify16(NbConfig->PcieEPHYBar |PCIEPHYCFG_EQUALIZATION_CTL_REG_ORIGINAL_VALUE_X8C_LANE00,TPMask,TxPreset);
					AsiaMemoryModify16(NbConfig->PcieEPHYBar |PCIEPHYCFG_EQUALIZATION_CTL_REG_ORIGINAL_VALUE_X8C_LANE01,TPMask,TxPreset);
					AsiaMemoryModify16(NbConfig->PcieEPHYBar |PCIEPHYCFG_EQUALIZATION_CTL_REG_ORIGINAL_VALUE_X8C_LANE02,TPMask,TxPreset);
					AsiaMemoryModify16(NbConfig->PcieEPHYBar |PCIEPHYCFG_EQUALIZATION_CTL_REG_ORIGINAL_VALUE_X8C_LANE03,TPMask,TxPreset);
					AsiaMemoryModify16(NbConfig->PcieEPHYBar |PCIEPHYCFG_EQUALIZATION_CTL_REG_ORIGINAL_VALUE_X8C_LANE04,TPMask,TxPreset);
					AsiaMemoryModify16(NbConfig->PcieEPHYBar |PCIEPHYCFG_EQUALIZATION_CTL_REG_ORIGINAL_VALUE_X8C_LANE05,TPMask,TxPreset);
					AsiaMemoryModify16(NbConfig->PcieEPHYBar |PCIEPHYCFG_EQUALIZATION_CTL_REG_ORIGINAL_VALUE_X8C_LANE06,TPMask,TxPreset);
					AsiaMemoryModify16(NbConfig->PcieEPHYBar |PCIEPHYCFG_EQUALIZATION_CTL_REG_ORIGINAL_VALUE_X8C_LANE07,TPMask,TxPreset);
					AsiaMemoryModify16(NbConfig->PcieEPHYBar |PCIEPHYCFG_EQUALIZATION_CTL_REG_ORIGINAL_VALUE_X8B_LANE00,TPMask,TxPreset);
					AsiaMemoryModify16(NbConfig->PcieEPHYBar |PCIEPHYCFG_EQUALIZATION_CTL_REG_ORIGINAL_VALUE_X8B_LANE01,TPMask,TxPreset);
					AsiaMemoryModify16(NbConfig->PcieEPHYBar |PCIEPHYCFG_EQUALIZATION_CTL_REG_ORIGINAL_VALUE_X8B_LANE02,TPMask,TxPreset);
					AsiaMemoryModify16(NbConfig->PcieEPHYBar |PCIEPHYCFG_EQUALIZATION_CTL_REG_ORIGINAL_VALUE_X8B_LANE03,TPMask,TxPreset);
					AsiaMemoryModify16(NbConfig->PcieEPHYBar |PCIEPHYCFG_EQUALIZATION_CTL_REG_ORIGINAL_VALUE_X8B_LANE04,TPMask,TxPreset);
					AsiaMemoryModify16(NbConfig->PcieEPHYBar |PCIEPHYCFG_EQUALIZATION_CTL_REG_ORIGINAL_VALUE_X8B_LANE05,TPMask,TxPreset);
					AsiaMemoryModify16(NbConfig->PcieEPHYBar |PCIEPHYCFG_EQUALIZATION_CTL_REG_ORIGINAL_VALUE_X8B_LANE06,TPMask,TxPreset);
					AsiaMemoryModify16(NbConfig->PcieEPHYBar |PCIEPHYCFG_EQUALIZATION_CTL_REG_ORIGINAL_VALUE_X8B_LANE07,TPMask,TxPreset);
					}
			break;

			case 1:
				if(PciAddress == CHX001_PEG0){
					AsiaMemoryModify16(NbConfig->PcieEPHYBar |PCIEPHYCFG_EQUALIZATION_CTL_REG_ORIGINAL_VALUE_X8B_LANE00,TPMask,TxPreset);
					AsiaMemoryModify16(NbConfig->PcieEPHYBar |PCIEPHYCFG_EQUALIZATION_CTL_REG_ORIGINAL_VALUE_X8B_LANE01,TPMask,TxPreset);
					AsiaMemoryModify16(NbConfig->PcieEPHYBar |PCIEPHYCFG_EQUALIZATION_CTL_REG_ORIGINAL_VALUE_X8B_LANE02,TPMask,TxPreset);
					AsiaMemoryModify16(NbConfig->PcieEPHYBar |PCIEPHYCFG_EQUALIZATION_CTL_REG_ORIGINAL_VALUE_X8B_LANE03,TPMask,TxPreset);
					AsiaMemoryModify16(NbConfig->PcieEPHYBar |PCIEPHYCFG_EQUALIZATION_CTL_REG_ORIGINAL_VALUE_X8B_LANE04,TPMask,TxPreset);
					AsiaMemoryModify16(NbConfig->PcieEPHYBar |PCIEPHYCFG_EQUALIZATION_CTL_REG_ORIGINAL_VALUE_X8B_LANE05,TPMask,TxPreset);
					AsiaMemoryModify16(NbConfig->PcieEPHYBar |PCIEPHYCFG_EQUALIZATION_CTL_REG_ORIGINAL_VALUE_X8B_LANE06,TPMask,TxPreset);
					AsiaMemoryModify16(NbConfig->PcieEPHYBar |PCIEPHYCFG_EQUALIZATION_CTL_REG_ORIGINAL_VALUE_X8B_LANE07,TPMask,TxPreset);
					}
				
				if(PciAddress == CHX001_PEG2){
					AsiaMemoryModify16(NbConfig->PcieEPHYBar |PCIEPHYCFG_EQUALIZATION_CTL_REG_ORIGINAL_VALUE_X8C_LANE00,TPMask,TxPreset);
					AsiaMemoryModify16(NbConfig->PcieEPHYBar |PCIEPHYCFG_EQUALIZATION_CTL_REG_ORIGINAL_VALUE_X8C_LANE01,TPMask,TxPreset);
					AsiaMemoryModify16(NbConfig->PcieEPHYBar |PCIEPHYCFG_EQUALIZATION_CTL_REG_ORIGINAL_VALUE_X8C_LANE02,TPMask,TxPreset);
					AsiaMemoryModify16(NbConfig->PcieEPHYBar |PCIEPHYCFG_EQUALIZATION_CTL_REG_ORIGINAL_VALUE_X8C_LANE03,TPMask,TxPreset);
					AsiaMemoryModify16(NbConfig->PcieEPHYBar |PCIEPHYCFG_EQUALIZATION_CTL_REG_ORIGINAL_VALUE_X8C_LANE04,TPMask,TxPreset);
					AsiaMemoryModify16(NbConfig->PcieEPHYBar |PCIEPHYCFG_EQUALIZATION_CTL_REG_ORIGINAL_VALUE_X8C_LANE05,TPMask,TxPreset);
					AsiaMemoryModify16(NbConfig->PcieEPHYBar |PCIEPHYCFG_EQUALIZATION_CTL_REG_ORIGINAL_VALUE_X8C_LANE06,TPMask,TxPreset);
					AsiaMemoryModify16(NbConfig->PcieEPHYBar |PCIEPHYCFG_EQUALIZATION_CTL_REG_ORIGINAL_VALUE_X8C_LANE07,TPMask,TxPreset);
					}
			break;
					
			case 2:
				if(PciAddress == CHX001_PEG0){
					AsiaMemoryModify16(NbConfig->PcieEPHYBar |PCIEPHYCFG_EQUALIZATION_CTL_REG_ORIGINAL_VALUE_X8B_LANE00,TPMask,TxPreset);
					AsiaMemoryModify16(NbConfig->PcieEPHYBar |PCIEPHYCFG_EQUALIZATION_CTL_REG_ORIGINAL_VALUE_X8B_LANE01,TPMask,TxPreset);
					AsiaMemoryModify16(NbConfig->PcieEPHYBar |PCIEPHYCFG_EQUALIZATION_CTL_REG_ORIGINAL_VALUE_X8B_LANE02,TPMask,TxPreset);
					AsiaMemoryModify16(NbConfig->PcieEPHYBar |PCIEPHYCFG_EQUALIZATION_CTL_REG_ORIGINAL_VALUE_X8B_LANE03,TPMask,TxPreset);
					AsiaMemoryModify16(NbConfig->PcieEPHYBar |PCIEPHYCFG_EQUALIZATION_CTL_REG_ORIGINAL_VALUE_X8B_LANE04,TPMask,TxPreset);
					AsiaMemoryModify16(NbConfig->PcieEPHYBar |PCIEPHYCFG_EQUALIZATION_CTL_REG_ORIGINAL_VALUE_X8B_LANE05,TPMask,TxPreset);
					AsiaMemoryModify16(NbConfig->PcieEPHYBar |PCIEPHYCFG_EQUALIZATION_CTL_REG_ORIGINAL_VALUE_X8B_LANE06,TPMask,TxPreset);
					AsiaMemoryModify16(NbConfig->PcieEPHYBar |PCIEPHYCFG_EQUALIZATION_CTL_REG_ORIGINAL_VALUE_X8B_LANE07,TPMask,TxPreset);
					}
				
				if(PciAddress == CHX001_PEG3){
					AsiaMemoryModify16(NbConfig->PcieEPHYBar |PCIEPHYCFG_EQUALIZATION_CTL_REG_ORIGINAL_VALUE_X8C_LANE00,TPMask,TxPreset);
					AsiaMemoryModify16(NbConfig->PcieEPHYBar |PCIEPHYCFG_EQUALIZATION_CTL_REG_ORIGINAL_VALUE_X8C_LANE01,TPMask,TxPreset);
					AsiaMemoryModify16(NbConfig->PcieEPHYBar |PCIEPHYCFG_EQUALIZATION_CTL_REG_ORIGINAL_VALUE_X8C_LANE02,TPMask,TxPreset);
					AsiaMemoryModify16(NbConfig->PcieEPHYBar |PCIEPHYCFG_EQUALIZATION_CTL_REG_ORIGINAL_VALUE_X8C_LANE03,TPMask,TxPreset);
					}
				if(PciAddress == CHX001_PEG2){
					AsiaMemoryModify16(NbConfig->PcieEPHYBar |PCIEPHYCFG_EQUALIZATION_CTL_REG_ORIGINAL_VALUE_X8C_LANE04,TPMask,TxPreset);
					AsiaMemoryModify16(NbConfig->PcieEPHYBar |PCIEPHYCFG_EQUALIZATION_CTL_REG_ORIGINAL_VALUE_X8C_LANE05,TPMask,TxPreset);
					AsiaMemoryModify16(NbConfig->PcieEPHYBar |PCIEPHYCFG_EQUALIZATION_CTL_REG_ORIGINAL_VALUE_X8C_LANE06,TPMask,TxPreset);
					AsiaMemoryModify16(NbConfig->PcieEPHYBar |PCIEPHYCFG_EQUALIZATION_CTL_REG_ORIGINAL_VALUE_X8C_LANE07,TPMask,TxPreset);
					}
			break;

			case 3:
				if(PciAddress == CHX001_PEG1){
					AsiaMemoryModify16(NbConfig->PcieEPHYBar |PCIEPHYCFG_EQUALIZATION_CTL_REG_ORIGINAL_VALUE_X8B_LANE00,TPMask,TxPreset);
					AsiaMemoryModify16(NbConfig->PcieEPHYBar |PCIEPHYCFG_EQUALIZATION_CTL_REG_ORIGINAL_VALUE_X8B_LANE01,TPMask,TxPreset);
					AsiaMemoryModify16(NbConfig->PcieEPHYBar |PCIEPHYCFG_EQUALIZATION_CTL_REG_ORIGINAL_VALUE_X8B_LANE02,TPMask,TxPreset);
					AsiaMemoryModify16(NbConfig->PcieEPHYBar |PCIEPHYCFG_EQUALIZATION_CTL_REG_ORIGINAL_VALUE_X8B_LANE03,TPMask,TxPreset);
					}
				if(PciAddress == CHX001_PEG0){
					AsiaMemoryModify16(NbConfig->PcieEPHYBar |PCIEPHYCFG_EQUALIZATION_CTL_REG_ORIGINAL_VALUE_X8B_LANE04,TPMask,TxPreset);
					AsiaMemoryModify16(NbConfig->PcieEPHYBar |PCIEPHYCFG_EQUALIZATION_CTL_REG_ORIGINAL_VALUE_X8B_LANE05,TPMask,TxPreset);
					AsiaMemoryModify16(NbConfig->PcieEPHYBar |PCIEPHYCFG_EQUALIZATION_CTL_REG_ORIGINAL_VALUE_X8B_LANE06,TPMask,TxPreset);
					AsiaMemoryModify16(NbConfig->PcieEPHYBar |PCIEPHYCFG_EQUALIZATION_CTL_REG_ORIGINAL_VALUE_X8B_LANE07,TPMask,TxPreset);
					}
				
				if(PciAddress == CHX001_PEG3){
					AsiaMemoryModify16(NbConfig->PcieEPHYBar |PCIEPHYCFG_EQUALIZATION_CTL_REG_ORIGINAL_VALUE_X8C_LANE00,TPMask,TxPreset);
					AsiaMemoryModify16(NbConfig->PcieEPHYBar |PCIEPHYCFG_EQUALIZATION_CTL_REG_ORIGINAL_VALUE_X8C_LANE01,TPMask,TxPreset);
					AsiaMemoryModify16(NbConfig->PcieEPHYBar |PCIEPHYCFG_EQUALIZATION_CTL_REG_ORIGINAL_VALUE_X8C_LANE02,TPMask,TxPreset);
					AsiaMemoryModify16(NbConfig->PcieEPHYBar |PCIEPHYCFG_EQUALIZATION_CTL_REG_ORIGINAL_VALUE_X8C_LANE03,TPMask,TxPreset);
					}
				if(PciAddress == CHX001_PEG2){
					AsiaMemoryModify16(NbConfig->PcieEPHYBar |PCIEPHYCFG_EQUALIZATION_CTL_REG_ORIGINAL_VALUE_X8C_LANE04,TPMask,TxPreset);
					AsiaMemoryModify16(NbConfig->PcieEPHYBar |PCIEPHYCFG_EQUALIZATION_CTL_REG_ORIGINAL_VALUE_X8C_LANE05,TPMask,TxPreset);
					AsiaMemoryModify16(NbConfig->PcieEPHYBar |PCIEPHYCFG_EQUALIZATION_CTL_REG_ORIGINAL_VALUE_X8C_LANE06,TPMask,TxPreset);
					AsiaMemoryModify16(NbConfig->PcieEPHYBar |PCIEPHYCFG_EQUALIZATION_CTL_REG_ORIGINAL_VALUE_X8C_LANE07,TPMask,TxPreset);
					}
			break;

		}
}

void PCIEBadSIDevWorkaround(
    IN EFI_PEI_SERVICES **PeiServices,
    IN ASIA_NB_CONFIGURATION *NbConfig,
    IN UINT64 PciAddress,
    IN UINT16 DNTxPreset,
    IN UINT16 UPTxPreset
)
{
    PEI_DEBUG((PeiServices, EFI_D_ERROR, "PCIEBadSIDevWorkaround() Pci Addr: %08X\n",PciAddress));

    PCIeEcfgMapping(PeiServices, NbConfig, PciAddress, DSTX, DNTxPreset);
    PCIeEcfgMapping(PeiServices, NbConfig, PciAddress, USTX, UPTxPreset);

    PEI_DEBUG((PeiServices, EFI_D_INFO, "Device Fill TxPreset DN:%X, UP:%X\n",DNTxPreset, UPTxPreset));
}
*/
/*- DSZ_Porting Need to check*/

#if 0
//CJW-20180119: this function was for patch, keep it , but not call it!, can use if 0 to comment out
void PCIEBadListForceSpeedPatch(
    IN EFI_PEI_SERVICES **PeiServices,
    IN ASIA_NB_CONFIGURATION *NbConfig,
    IN UINT64 PciAddress,
    IN UINT8 GenSpeed
)
{
    // JIH - Enable Back Door for Link Capability
    PEI_DEBUG((PeiServices, EFI_D_INFO, "PCIEBadListForceSpeedPatch() - Gen %D on Port: %X\n",GenSpeed, PciAddress));
	
    AsiaPcieModify8(NbConfig->PcieBar, CHX002_APIC|((UINT64)D0F5_PMU_CTL << 32), D0F5_RPEROWEN, D0F5_RPEROWEN);
    AsiaPciModify8(PciAddress |D3D5F1_LINK_CAPS_1_D4F0, 0x03, GenSpeed);
    AsiaPciModify8(PciAddress |D3D5F1_LINK_CTL_2_D4F0 , 0x03, GenSpeed);
    // JIH - Disable Back Door for  Link Capability
    AsiaPcieModify8(NbConfig->PcieBar, CHX002_APIC|((UINT64)D0F5_PMU_CTL << 32), D0F5_RPEROWEN, 0x00);

    AsiaPcieModify8(NbConfig->PcieBar, PciAddress|((UINT64)D3D5F1_LINK_CTL_1 << 32), D3D5F1_LCRL, D3D5F1_LCRL);      //Retrain Link

    //wait 100 ms to retrain PCIE Link      
    PeiNbPcieStall(PeiServices, 0x64);      
    PEI_DEBUG((PeiServices, EFI_D_INFO, "PCIE Retrain Done!\n"));
            
}

//CJW-20181019: same with PCIEBadListForceSpeedPatch() , comment out is better
void PCIEBadListForceDelayPatch(
    IN EFI_PEI_SERVICES **PeiServices,
    IN ASIA_NB_CONFIGURATION *NbConfig,
    IN UINT64 PciAddress,
    IN UINTN Millisecond
)
{
    PEI_DEBUG((PeiServices, EFI_D_INFO, "PCIEBadListForceDelayPatch() - %dms on Port: %X\n", Millisecond, PciAddress));
    PeiNbPcieStall(PeiServices, Millisecond);      
}

//CJW-20181019: same with PCIEBadListForceSpeedPatch() , comment out is better
BOOLEAN PCIEBadListWorkaround(
    IN EFI_PEI_SERVICES **PeiServices,
    IN ASIA_NB_CONFIGURATION *NbConfig,
    IN UINT64 PciAddress,
    OUT PCIE_Cap *PcieCap
)
{
    UINT8 SubBusNo, DevSearch, FuncSearch;
    UINT16 	VendorId, DeviceId;
    UINT16   i, regprint;

    PEI_DEBUG((PeiServices, EFI_D_ERROR, "PCIEBadListWorkaround() Pci Addr: %08X\n",PciAddress));

    // If slot empty, break check bad device list

    if((AsiaPciRead8(PciAddress |D3D5F1_SLOT_STA_1) & D3D5F1_SPDCST) != D3D5F1_SPDCST)
        return FALSE;

    if((AsiaPciRead16(PciAddress |D3D5F1_VID)) == 0xFFFF)
	return FALSE;

    if((AsiaPcieRead8(NbConfig->PcieBar, PciAddress |((UINT64)D3D5F1_PHYLS_LTSSM_STATE << 32)) < 0x8A)){
        AsiaIoWrite8(0x80, 0xAA);
        PEI_DEBUG((PeiServices, EFI_D_ERROR, "PCIEBadListWorkaround() - LTSSM not 0x8A\n"));

        for(i=0; i <= 1024 ; i++) {

        	if(i%16 == 0)
			PEI_DEBUG((PeiServices, EFI_D_ERROR, "\n"));

		regprint =  AsiaPciRead8(PciAddress |i) ;
        	PEI_DEBUG((PeiServices, EFI_D_ERROR, "%02X ",regprint));

		}

        return FALSE;
    	}

    for(i=0; i <= 127 ; i++) {

		if(i%16 == 0)
			PEI_DEBUG((PeiServices, EFI_D_ERROR, "\n"));

    		regprint =  AsiaPciRead8(PciAddress |i) ;
		PEI_DEBUG((PeiServices, EFI_D_ERROR, "%02X ",regprint));

    	}
    PEI_DEBUG((PeiServices, EFI_D_ERROR, "\n"));

    AsiaPciWrite8(PciAddress |D3D5F1_SECONDARY_BUS_NUM, 01) ;
    AsiaPciWrite8(PciAddress |D3D5F1_SUBORDINATE_BUS_NUM, 01) ;

    SubBusNo =  AsiaPciRead8(PciAddress |D3D5F1_SECONDARY_BUS_NUM) ;

    for(DevSearch = 0; DevSearch <= 31; DevSearch ++){
       for(FuncSearch = 0; FuncSearch <= 7; FuncSearch ++){

            VendorId = AsiaPciRead16(AsiaPciAddress(SubBusNo, DevSearch, FuncSearch, 0));
            DeviceId = AsiaPciRead16(AsiaPciAddress(SubBusNo, DevSearch, FuncSearch, 2));

            for(i=0; i<sizeof(PCIEBadListDeviceTbl)/sizeof(BAD_PCIE_LINKUP_TBL); i++){
            		if((VendorId==PCIEBadListDeviceTbl[i].VendorId)&&(DeviceId==(PCIEBadListDeviceTbl[i].DeviceId & PCIEBadListDeviceTbl[i].DeviceIdMask))){

        			PEI_DEBUG((PeiServices, EFI_D_ERROR, "PCIEBadListWorkaround() - Get Bad Device\n"));
        			PEI_DEBUG((PeiServices, EFI_D_ERROR, "PCIEBadListWorkaround() - VID: %04X DID: %04X\n", VendorId, DeviceId));

				switch(PCIEBadListDeviceTbl[i].PatchSolution){
					case ForceGen2:
						PCIEBadListForceSpeedPatch(PeiServices, NbConfig, PciAddress, PE_GEN2);
						*PcieCap = PE_GEN2;
						break;

					case ForceDelay100ms:
	     					PCIEBadListForceDelayPatch(PeiServices, NbConfig, PciAddress, 0x64);
						break;

					case ForceSIsetDN7UP7:
	     					/*DSZ_porting need to check
	     					//CJW-20180118: yes . CHX002 don't have this complex mapping relationship 
	     					if(NbConfig->PcieEQ != SKPEQ_MANUAL){
							PCIEBadSIDevWorkaround(PeiServices, NbConfig, PciAddress, 0x07, 0x07);       
		  				  	}*/
						break;

					default:
						break;
					}
			}
            }
			
    	}
   }

    AsiaPciWrite8(PciAddress |D3D5F1_SECONDARY_BUS_NUM, 00) ;
    AsiaPciWrite8(PciAddress |D3D5F1_SUBORDINATE_BUS_NUM, 00) ;

    return TRUE;

}
#endif
/*DSZ_porting need to check
BOOLEAN PcieCRSDevDelay(
    IN EFI_PEI_SERVICES **PeiServices,
    IN ASIA_NB_CONFIGURATION *NbConfig,
    IN UINT64 PciAddress
)
{
    UINT8 		PriBusNo, SubBusNo;
    UINT16 	VendorId, DeviceId;
    UINT16   i, delaytime;

    PEI_DEBUG((PeiServices, EFI_D_ERROR, "PcieCRSDevDelay() Pci Addr: %08X\n",PciAddress));

    if((AsiaPciRead8(PciAddress |D3D5F1_SLOT_STA_1) & D3D5F1_SPDCST) != D3D5F1_SPDCST)
        return FALSE;

    if((AsiaPcieRead8(NbConfig->PcieBar, PciAddress |((UINT64)D3D5F1_PHYLS_LTSSM_STATE << 32)) >= 0x8A) 
			&& 	(AsiaPcieRead8(NbConfig->PcieBar, PciAddress |((UINT64)D3D5F1_PHYLS_LTSSM_STATE << 32)) != 0xFF)
			){
			
	    PriBusNo = AsiaPciRead8(PciAddress |D3D5F1_PRIMARY_BUS_NUM);
	    AsiaPciWrite8(PciAddress |D3D5F1_SECONDARY_BUS_NUM, (PriBusNo + 1)) ;
	    AsiaPciWrite8(PciAddress |D3D5F1_SUBORDINATE_BUS_NUM, (PriBusNo + 1)) ;
	    AsiaPciRead8(PciAddress |D3D5F1_SECONDARY_BUS_NUM) ;
	    AsiaPciRead8(PciAddress |D3D5F1_SUBORDINATE_BUS_NUM) ;
		
	    SubBusNo =  AsiaPciRead8(PciAddress |D3D5F1_SECONDARY_BUS_NUM) ;
            VendorId = AsiaPciRead16(AsiaPciAddress(SubBusNo, 0, 0, D3D5F1_VID));
            DeviceId = AsiaPciRead16(AsiaPciAddress(SubBusNo, 0, 0, D3D5F1_DID));
			
  		    if((DeviceId == 0xFFFF) && ((VendorId == 0xFFFF) ||(VendorId == 0x0001))){
		    		PEI_DEBUG((PeiServices, EFI_D_ERROR, "PcieCRSDevDelay() - for CRS delay - Entry\n"));
  				
  			        for(i=0; i <= 2000 ; i++) {

					for(delaytime = 0; delaytime <= 1000; delaytime ++) // delay 1ms
						AsiaIoRead8(0x88);
					AsiaIoWrite8(0x80, 0xDD); 
            				VendorId = AsiaPciRead16(AsiaPciAddress(SubBusNo, 0, 0, D3D5F1_VID));
			            	DeviceId = AsiaPciRead16(AsiaPciAddress(SubBusNo, 0, 0, D3D5F1_DID));
					if(!((DeviceId == 0xFFFF) && ((VendorId == 0xFFFF) ||(VendorId == 0x0001))))
						break;
					if((AsiaPcieRead8(NbConfig->PcieBar, PciAddress |((UINT64)D3D5F1_PHYLS_LTSSM_STATE << 32)) < 0x8A)){
	  					PEI_DEBUG((PeiServices, EFI_D_ERROR, "PcieCRSDevDelay() - Link unstable, LTSSM not L0 state.\n"));
						AsiaIoWrite8(0x80, 0xDE); 
						break;
						}
					
  					}
  				
			       VendorId = AsiaPciRead16(AsiaPciAddress(SubBusNo, 0, 0, D3D5F1_VID));
            			DeviceId = AsiaPciRead16(AsiaPciAddress(SubBusNo, 0, 0, D3D5F1_DID));

  			       if (DeviceId == 0xFFFF){
  					PEI_DEBUG((PeiServices, EFI_D_ERROR, "PcieCRSDevDelay() - for CRS delay - Time Out\n"));
					AsiaPciWrite8(PciAddress |D3D5F1_SECONDARY_BUS_NUM, 00) ;
					AsiaPciWrite8(PciAddress |D3D5F1_SUBORDINATE_BUS_NUM, 00) ;
  					return FALSE;
  					}
  				else{
  					PEI_DEBUG((PeiServices, EFI_D_ERROR, "PcieCRSDevDelay() - for CRS delay - Delay done\n"));
					AsiaPciWrite8(PciAddress |D3D5F1_SECONDARY_BUS_NUM, 00) ;
					AsiaPciWrite8(PciAddress |D3D5F1_SUBORDINATE_BUS_NUM, 00) ;
  					return TRUE;
  					}
  		    	}
  		    else{
  		       PEI_DEBUG((PeiServices, EFI_D_ERROR, "PcieCRSDevDelay() - TempBus_D0F0 VID = %04X\n", VendorId));
  		       PEI_DEBUG((PeiServices, EFI_D_ERROR, "PcieCRSDevDelay() - for CRS delay - VID Not CRS\n"));
			AsiaPciWrite8(PciAddress |D3D5F1_SECONDARY_BUS_NUM, 00) ;
			AsiaPciWrite8(PciAddress |D3D5F1_SUBORDINATE_BUS_NUM, 00) ;
  			return FALSE;
  		    	}
	            
    	}

    return FALSE;

}
*/

/**
   This Function adds patch code before PCIE Linkup.

  @param  PeiServices	EFI_PEI_SERVICES pointer.
  @param  pNbConfig  point to ASIA_NB_CONFIGURATION
  @param BDFno target pci device's address


  @return The value from this function.

**/
VOID
PciePatchBeforeLinkup(
    IN EFI_PEI_SERVICES **PeiServices,
    IN ASIA_NB_CONFIGURATION *NbConfig,
    IN UINT64 BDFno)
{
    UINT64 PcieBase;
    PcieBase = NbConfig->PcieBar; 

	PEI_DEBUG((PeiServices, EFI_D_ERROR, "       PciePatchBeforeLinkup()\n"));
	
	//JIH-20161209 for force link width routine - s 
	if(NbConfig->PcieForceLinkWidth != PcieForceLinkWidth_default){	
		AsiaPcieModify8(PcieBase, CHX002_APIC|((UINT64)D0F5_PMU_CTL << 32), D0F5_RPEROWEN, D0F5_RPEROWEN);
		AsiaPcieModify16(PcieBase, BDFno|((UINT64)D3D5F1_LINK_CAPS_1_D4F0 << 32), 
					D3D5F1_LKMLW_5 |D3D5F1_LKMLW_4 |D3D5F1_LKMLW_3 |D3D5F1_LKMLW_2 |D3D5F1_LKMLW_1 |D3D5F1_LKMLW_0, 
					D3D5F1_LKMLW_0);
		AsiaPcieModify8(PcieBase, CHX002_APIC|((UINT64)D0F5_PMU_CTL << 32), D0F5_RPEROWEN, 0x00);
	}
	
	//DSZ-20180713 Force Rx1C1[5] to 0 to solve PCIE-USB card issue  
	//	 when this bit set to 1b, link may unable to work in a lower GenSpeed when MaxSupportedSpeed can't work in L0
	// 	 so we set this bit to 0b to guarantee Device work in lower speed
	
	if(NbConfig->SB_HS_DBG_SEL == SB_HS_DBG_SEL_DISABLE){
	    AsiaPcieModify8(PcieBase, BDFno|((UINT64)D3D5F1_GENERAL_CTL_2 << 32), D3D5F1_RHATNMSE, 0);
		}
//JNY 20180305 Add for IOE Porting -s
#ifdef IOE_EXIST

	if(BDFno == CHX002_PE0){
		IoeSmbusPreInit(PeiServices, NbConfig);
	}
#endif
//JNY 20180305 Add for IOE Porting -e


#ifdef PCISIG_PLUGFEST_WORKAROUND
	//auto speed change enable
	//	we expect all device can be training to Max supported speed,  
	//	when this register was set, if some port Down Mode caused by some NOT SERIOUS issues, 
	//	HW will try to negotiation to max support speed again
	AsiaPcieModify8(PcieBase, BDFno|((UINT64)D3D5F1_GENERAL_CTL_2 << 32), D3D5F1_RHATNMSE, D3D5F1_RHATNMSE); 

	//Completion timeout change to 500ms
	//	this request come form Chinhui, when do BIOS Gold Test, sometimes there will be some test items random failed,
	//   according to check the log, Chinhui advise to set a larger CTO, finially, we set it as 500ms 
	AsiaPcieModify8(PcieBase, BDFno|((UINT64)D3D5F1_DOWNSTREAM_CTL_2 << 32), D3D5F1_RCPRTM, 0x6); 
#endif

}

/**
   This Function add patch code after PCIE Linkup.

  
  @param  PeiServices	EFI_PEI_SERVICES pointer.
  @param  pNbConfig  point to ASIA_NB_CONFIGURATION
  @param PciAddress target pci device's address
  @param PcieCap    point to PCIE_Cap struct

  @return The value from this function.

**/

VOID 
PciePatchAfterLinkup(
    IN EFI_PEI_SERVICES **PeiServices,
    IN ASIA_NB_CONFIGURATION *NbConfig,
    IN UINT64 PciAddress,
    IN OUT PCIE_Cap *PcieCap)
{
	PEI_DEBUG((PeiServices, EFI_D_ERROR, "       PciePatchAfterLinkup()\n"));

	PCIEBadListWorkaround(PeiServices,NbConfig,PciAddress,PcieCap);
}


/**
   This Function Set 'RP Capability' according to MRD and Setup-Item.

  CHX001-CJW-20151025
  In this function ,  we get the capability of one RP   and if capability can reach to Gen3, 
  we decide whether skip EQ or not.
  
  @param  PeiServices	EFI_PEI_SERVICES pointer.
  @param  pNbConfig  point to ASIA_NB_CONFIGURATION
  @param PciAddress target pci device's address
  @param PcieCap    point to PCIE_Cap struct
  @param PhaseCtrl 

  @return The value from this function.

**/

EFI_STATUS
ConfigPcieRP(
    IN EFI_PEI_SERVICES **PeiServices,
    IN ASIA_NB_CONFIGURATION *NbConfig,
    IN UINT64 PciAddress,
    IN PCIE_Cap PcieCap,
    IN UINT8 PhaseCtl
)
{
	PCIE_Cap PcieCapLocal;
	PCIE_Cap PcieCapLocalMax;
	UINT64 PcieBase;
	UINT8 DevLinkCap = 0xFF;
	UINT8 ThisPortDoEq;
	PcieBase = NbConfig->PcieBar;
	PcieCapLocal = PcieCap;

	//
	//Set Rx4C/6C to real capability
	//TLS = Gen1 (Rx70)
	//TLS_Internal = Gen1 (Rx1E9)
	//
	if(PhaseCtl == INITIME_GEN1){
		AsiaPcieModify8(PcieBase, CHX002_APIC|((UINT64)D0F5_PMU_CTL << 32), D0F5_RPEROWEN, D0F5_RPEROWEN); //make some RO bit come to RW

	
		//MAX Link Speed Setting
		switch (PcieCapLocal){
			case PE_GEN3:	//RP supported to GEN3
				//;Issue EQTS2 in Recovery.RcvrCfg LTSSM State
				//;SendEQTS2(PcieBase, PciAddress);
	
				//Special Patch for PCIE Revision Capability not controlled by ROMSIP Issue
				//AsiaPcieModify8(PcieBase, PciAddress|((UINT64)D2D5F1_PCI_EXPRESS_CAPS_D4F0 << 32), D2D5F1_PCIE_VER_0 + D2D5F1_PCIE_VER_1, D2D5F1_PCIE_VER_1);
	
				//Set RP Supported Link Speed Vector and Max Link Speed
				AsiaPcieModify8(PcieBase, PciAddress|((UINT64)D3D5F1_LINK_CAPS_2_D4F0 << 32), 
											D3D5F1_LKMLS_0 + D3D5F1_LKMLS_1 + D3D5F1_LKMLS_2, 
											D3D5F1_LKMLS_0 + D3D5F1_LKMLS_1 + D3D5F1_LKMLS_2);
				AsiaPcieModify8(PcieBase, PciAddress|((UINT64)D3D5F1_LINK_CAPS_1_D4F0 << 32), 
											D3D5F1_LKMAXLS_0 + D3D5F1_LKMAXLS_1 + D3D5F1_LKMAXLS_2 + D3D5F1_LKMAXLS_3, 
											PcieCapLocal);
	
				//;Setting Perform EQ Control for GEN3 Init
				//AsiaPcieModify8(PcieBase, PciAddress|((UINT64)D2D2F0_LINK_CTL_3_REG << 32), D2D2F0_PERFORMEQ, D2D2F0_PERFORMEQ);		//Perform EQ Control
									
				break;
									
			case PE_GEN2:	//RP supported to GEN2
	
				//Special Patch for PCIE Revision Capability not controlled by ROMSIP Issue
				//AsiaPcieModify8(PcieBase, PciAddress|((UINT64)D2D5F1_PCI_EXPRESS_CAPS_D4F0 << 32), D2D5F1_PCIE_VER_0 + D2D5F1_PCIE_VER_1, D2D5F1_PCIE_VER_1);
	
				//Set RP Supported Link Speed Vector and Max Link Speed
				AsiaPcieModify8(PcieBase, PciAddress|((UINT64)D3D5F1_LINK_CAPS_2_D4F0 << 32), 
											D3D5F1_LKMLS_0 + D3D5F1_LKMLS_1 + D3D5F1_LKMLS_2, 
											D3D5F1_LKMLS_0 + D3D5F1_LKMLS_1);
				AsiaPcieModify8(PcieBase, PciAddress|((UINT64)D3D5F1_LINK_CAPS_1_D4F0 << 32), 
											D3D5F1_LKMAXLS_0 + D3D5F1_LKMAXLS_1 + D3D5F1_LKMAXLS_2 + D3D5F1_LKMAXLS_3, 
											PcieCapLocal);
	
				break;
									
			case PE_GEN1:	//RP supported to GEN1
	
				//Special Patch for PCIE Revision Capability not controlled by ROMSIP Issue
				//AsiaPcieModify8(PcieBase, PciAddress|((UINT64)D2D5F1_PCI_EXPRESS_CAPS_D4F0 << 32), D2D5F1_PCIE_VER_0 + D2D7F0_PCIE_VER_1, D2D7F0_PCIE_VER_0);

				//Set RP Supported Link Speed Vector and Max Link Speed
				AsiaPcieModify8(PcieBase, PciAddress|((UINT64)D3D5F1_LINK_CAPS_2_D4F0 << 32), 
											D3D5F1_LKMLS_0 + D3D5F1_LKMLS_1 + D3D5F1_LKMLS_2, 
											D3D5F1_LKMLS_0);
				AsiaPcieModify8(PcieBase, PciAddress|((UINT64)D3D5F1_LINK_CAPS_1_D4F0 << 32), 
											D3D5F1_LKMAXLS_0 + D3D5F1_LKMAXLS_1 + D3D5F1_LKMAXLS_2 + D3D5F1_LKMAXLS_3,
											PcieCapLocal);
	
				break;
	
			default:		//RP not existed
				break;
		}				
		AsiaPcieModify8(PcieBase, CHX002_APIC|((UINT64)D0F5_PMU_CTL << 32), D0F5_RPEROWEN, 0x0);
	
		//;ysw_debug - 2016080901		 //Start setting Target Link Speed
		//;ysw_debug - 2016080901		 AsiaPcieModify8(PcieBase, PciAddress|((UINT64)D2D5F1_LINK_CTL_2_D4F0 << 32), D2D5F1_LKTGLS_0 + D2D5F1_LKTGLS_1 + D2D5F1_LKTGLS_2 + D2D5F1_LKTGLS_3, PcieCap);	 //Target Link Speed
		//;ysw_debug - 2016080901		 AsiaPcieModify8(PcieBase, PciAddress|((UINT64)D2D5F1_LKTGLS_INTER_AND_NEED_EQTS << 32), D2D5F1_LKTGLS_INTER, ((UINT8)PcieCap << 1));			 //Setting Internal Target Link Speed
		
		//;ysw_debug - 2016080901 - start
		AsiaPcieModify8(PcieBase, PciAddress|((UINT64)D3D5F1_LKTGLS_INTER_AND_NEED_EQTS << 32), 
											D3D5F1_LKTGLS_INTER, 0x01 << 1);			//Setting Internal Target Link Speed
		AsiaPcieModify8(PcieBase, PciAddress|((UINT64)D3D5F1_LINK_CTL_2_D4F0 << 32), 
											D3D5F1_LKTGLS_0 + D3D5F1_LKTGLS_1 + D3D5F1_LKTGLS_2 + D3D5F1_LKTGLS_3, 
											D3D5F1_LKTGLS_0);							//Target Link Speed
	}



	//
	//If not DO_EQ, then set TLS and TLS_Internal to Real Speed
	//
	if(PhaseCtl == RUNTIME_AUTO){

		
//;CJW-20180124-Add new mech - Start
		PcieCapLocalMax = PcieCapLocal; //PcieCapLocalMax store the Max Capability Supported by this RP
		//
		// When we need to set TLS of RP depend on Device's capability,
		// we need to check
		//
		if(NbConfig->PcieOptimalTLS){
			//dump DevCap
			switch(PciAddress){
			case CHX002_PE0:
				DevLinkCap = NbConfig->PcieDevCapPE0;
				break;
			case CHX002_PE1:
				DevLinkCap = NbConfig->PcieDevCapPE1;
				break;
			case CHX002_PE2:
				DevLinkCap = NbConfig->PcieDevCapPE2;
				break;
			case CHX002_PE3:
				DevLinkCap = NbConfig->PcieDevCapPE3;
				break;
			case CHX002_PE4:
				DevLinkCap = NbConfig->PcieDevCapPE4;
				break;
			case CHX002_PE5:
				DevLinkCap = NbConfig->PcieDevCapPE5;
				break;
			case CHX002_PE6:
				DevLinkCap = NbConfig->PcieDevCapPE6;
				break;
			case CHX002_PE7:
				DevLinkCap = NbConfig->PcieDevCapPE7;
				break;
			default:
				DevLinkCap = 0xFE;
				break;
			}

			PEI_DEBUG((PeiServices, EFI_D_ERROR, "[PCIE-DevCap] Gen%d\n",DevLinkCap));	
			if(DevLinkCap < PcieCapLocal){
				
				PcieCapLocal = DevLinkCap;     //PcieCapLocal will change to the Common Max Capability Supported by RP and Dev
			}
			
		}
//;CJW-20180124-Add new mech - End	
		
	
		//Start setting Target Link Speed except "GEN3 with DoEQ Scenario"
		//(Set Internal Target Link-Speed first to avoid auto link-up to GEN2)
		ThisPortDoEq = AsiaPcieRead8(NbConfig->PcieBar,PciAddress|((UINT64)D3D5F1_MISC_CTL << 32));
		if((PcieCapLocal != PE_GEN3) || 
			((PcieCapLocal == PE_GEN3) && (NbConfig->PcieEQ != DOEQ)  ) ||
			((PcieCapLocal == PE_GEN3) && (NbConfig->PcieEQ == DOEQ)&& (!(ThisPortDoEq & D3D5F1_RWTEXEPH23)))){
			
				AsiaPcieModify8(PcieBase, PciAddress|((UINT64)D3D5F1_LKTGLS_INTER_AND_NEED_EQTS << 32), 
												D3D5F1_LKTGLS_INTER, 
												((UINT8)PcieCapLocalMax << 1));						//Setting Internal Target Link Speed
				AsiaPcieModify8(PcieBase, PciAddress|((UINT64)D3D5F1_LINK_CTL_2_D4F0 << 32), 
												D3D5F1_LKTGLS_0 + D3D5F1_LKTGLS_1 + D3D5F1_LKTGLS_2 + D3D5F1_LKTGLS_3, 
												PcieCapLocal);										//Target Link Speed
		}
		

		AsiaPcieModify8(PcieBase, PciAddress|((UINT64)D3D5F1_LINK_CTL_1 << 32), D3D5F1_LCRL, D3D5F1_LCRL);		//Retrain Link
	}
	
	PEI_DEBUG((PeiServices, EFI_D_ERROR, "       Internal Target Link Speed RP_Rx1E9[7:0] = 0x%x\n", 
					AsiaPcieRead8(PcieBase, PciAddress|((UINT64)D3D5F1_LKTGLS_INTER_AND_NEED_EQTS << 32))));
	PEI_DEBUG((PeiServices, EFI_D_ERROR, "       Target Link Speed RP_Rx70 = 0x%x\n", 
					AsiaPcieRead8(PcieBase, PciAddress|((UINT64)D3D5F1_LINK_CTL_2_D4F0 << 32))));
		
	return EFI_SUCCESS;
}

/*- DSZ_Porting -- (JIH-2017021401) Add Pcie Patch PCIEBadListWorkaround*/


/*+ DSZ_Porting -- (JIH-2017021401) Add Pcie Patch PCIEBadListWorkaround*/



/**
   This function called to set link speed in different phase.

  get link speed parameter rules:
  //;								   |				  | 																 |
  //--------------------------------------------------------------------------------------------------------------
  //;PcieLinkSpeed	  value   | AUTO		  | 		 BY_PORT										   |   else   
  //--------------------------------------------------------------------------------------------------------------
  //;PciePEGLinkSpeed value | ignore		 | AUTO 			|		   else (Gen1/2/3)		   |   ignore 
  //====================================================================================
  //;PEG's final speed set	   | Use ROMSIP | Use ROMSIP   | Use PciePEGLinkSpeed(1/2/3) | Use PcieLinkSpeed(1/2/3)  
  //--------------------------------------------------------------------------------------------------------------
  //;Comment					 |					 |					   |  really BY_PORT					| Unified Setting

  
  @param  PeiServices	EFI_PEI_SERVICES pointer.
  @param  pNbConfig  point to ASIA_NB_CONFIGURATION
  @param PciAddress target pci device's address
  @param PhaseCtl

  @return The value from this function.

**/

EFI_STATUS
SetPcieXLink(
    IN EFI_PEI_SERVICES **PeiServices,
    IN ASIA_NB_CONFIGURATION *NbConfig,
    IN UINT64 PciAddress,
    IN UINT8 PhaseCtl
)
{   
    UINT64 PcieBase;
    PCIE_Cap RpCap3 = PE_NA;        
    UINT8 LinkSpeedByPort;
	UINT8 Busx,Devx,Funx;

	PcieBase = NbConfig->PcieBar;

	Funx = 0x7 & RShiftU64(PciAddress,8);
	Devx = 0x1F & RShiftU64(PciAddress,16);
	Busx = 0xFF & RShiftU64(PciAddress,24);

	PEI_DEBUG((PeiServices, EFI_D_ERROR, "[PCIE] (%d:%d.%d)\n",Busx,Devx,Funx));
	switch (PciAddress){
		case CHX002_PE0:
			LinkSpeedByPort = NbConfig->PciePE0LinkSpeed;
			break;
		case CHX002_PE1:
			LinkSpeedByPort = NbConfig->PciePE1LinkSpeed;
			break;
		case CHX002_PE2:
			LinkSpeedByPort = NbConfig->PciePE2LinkSpeed;
			break;
		case CHX002_PE3:
			LinkSpeedByPort = NbConfig->PciePE3LinkSpeed;
			break;
		case CHX002_PE4:
			LinkSpeedByPort = NbConfig->PciePE4LinkSpeed;
			break;
		case CHX002_PE5:
			LinkSpeedByPort = NbConfig->PciePE5LinkSpeed;
			break;
		case CHX002_PE6:
			LinkSpeedByPort = NbConfig->PciePE6LinkSpeed;
			break;
		case CHX002_PE7:
			LinkSpeedByPort = NbConfig->PciePE7LinkSpeed;
			break;
		default:
			LinkSpeedByPort = PCIE_LINK_SPEED_AUTO;
			break;
	}
        
   if((NbConfig->PcieLinkSpeed == PCIE_LINK_SPEED_AUTO) || 
       ((NbConfig->PcieLinkSpeed == PCIE_LINK_SPEED_BY_PORT) && (LinkSpeedByPort == PCIE_LINK_SPEED_AUTO))){

	   //Get the Rp Cap from ROMSIP when SPEED_AUTO
       PeiNbGetRPCap(PeiServices, NbConfig, PciAddress, &RpCap3);

	   if((RpCap3!=PE_GEN1)&&(RpCap3!=PE_GEN2)&&(RpCap3!=PE_GEN3)){                       
           PEI_DEBUG((PeiServices, EFI_D_ERROR, "       ERROR! Capability in ROMSIP invalid!\n",RpCap3));      
       }else{
           PEI_DEBUG((PeiServices, EFI_D_ERROR, "       TLS in ROMSIP is: Gen%d \n",RpCap3));
       }
   }else if(NbConfig->PcieLinkSpeed == PCIE_LINK_SPEED_BY_PORT){				
           RpCap3 = (PCIE_Cap)LinkSpeedByPort;
           PEI_DEBUG((PeiServices, EFI_D_ERROR, "       TLS in SETUP is: Gen%d\n",RpCap3));
   }else{
           RpCap3 = (PCIE_Cap)NbConfig->PcieLinkSpeed;
		   PEI_DEBUG((PeiServices, EFI_D_ERROR, "       TLS in SETUP is: Gen%d\n",RpCap3));


   }
   if(PhaseCtl == INITIME_GEN1){
		; //nothing now
   }
   /*+ DSZ_Porting -- (JIH-2017021401) Add Pcie Patch PCIEBadListWorkaround*/
   if(PhaseCtl == RUNTIME_AUTO){
  		PciePatchAfterLinkup(PeiServices, NbConfig, PciAddress, &RpCap3);
   }
   
   ConfigPcieRP(PeiServices, NbConfig, PciAddress, (PCIE_Cap)RpCap3, PhaseCtl);    //ysw_debug - 2016080901
   /*- DSZ_Porting -- (JIH-2017021401) Add Pcie Patch PCIEBadListWorkaround*/
   
   return EFI_SUCCESS;
}
//;cjw_debug_pcie - end

/**
   This Function trigger Pe-Reset when Link failed.

  @param  PeiServices	EFI_PEI_SERVICES pointer.
  @param  pNbConfig  point to ASIA_NB_CONFIGURATION
  @param PciAddress target pci device's address

  @return The value from this function.

**/
EFI_STATUS PeRstWhenLinkFail(
    IN EFI_PEI_SERVICES **PeiServices,
    IN ASIA_NB_CONFIGURATION *NbConfig,
    IN UINT64 Address
)
{
    UINT8        D8;
    UINT64      PcieBase;
    D8 = AsiaPciRead8(Address|D3D5F1_SLOT_STA_1);
    D8 &= D3D5F1_SPDCST;
    if(D8 != 0)
    {
        PcieBase = NbConfig->PcieBar;
        D8 = AsiaPcieRead8(PcieBase, Address|((UINT64)D3D5F1_PHYLS_LTSSM_STATE << 32));
        if (D8 < PHYLS_State_L0 )
        {
            PCIeCommonPERST(PeiServices,Address);
        }
    }
    return EFI_SUCCESS;

}


#define PCIE_TEMP_BUS_NUMBER  0x02

/**
   This Function check PCIE Link.

  @param  PeiServices	EFI_PEI_SERVICES pointer.
  @param  pNbConfig  point to ASIA_NB_CONFIGURATION

  @return The value from this function.

**/
EFI_STATUS
PeiNbCheckPcieLink(
    IN EFI_PEI_SERVICES **PeiServices,
    IN ASIA_NB_CONFIGURATION *NbConfig
)
{
    EFI_STATUS Status;
    BOOLEAN PcieRst;
    BOOLEAN PE0Rst;
    BOOLEAN PE1Rst;
    BOOLEAN PE2Rst;
    BOOLEAN PE3Rst;
    BOOLEAN PE4Rst;
    BOOLEAN PE5Rst;
    BOOLEAN PE6Rst;
    BOOLEAN PE7Rst;
    UINT8 Retry, Retry1;
    UINT8 D8;
    BOOLEAN PcieLinkFailFlag;

    PcieLinkFailFlag = FALSE;
    PcieRst = NbConfig->PcieRst;	
    PE0Rst = NbConfig->PcieRstPE0;
    PE1Rst = NbConfig->PcieRstPE1;
    PE2Rst = NbConfig->PcieRstPE2;
    PE3Rst = NbConfig->PcieRstPE3;
    PE4Rst = NbConfig->PcieRstPE4;
    PE5Rst = NbConfig->PcieRstPE5;
    PE6Rst = NbConfig->PcieRstPE6;
    PE7Rst = NbConfig->PcieRstPE7;        
    if (!PcieRst)
    {
        return EFI_SUCCESS;
    }

    Retry = 0x01;
    do
    {
        
        // PE0
        if(PE0Rst)
        {
            PEI_DEBUG((PeiServices, EFI_D_ERROR, "PE0Rst\n"));
            Retry1 = 5;
            do
            {
                //Check PCIE Presence
                D8 = AsiaPciRead8(CHX002_PE0|D3D5F1_SLOT_STA_1);        //Rx5A
                if (D8 & D3D5F1_SPDCST)
                {
                    PEI_DEBUG((PeiServices, EFI_D_ERROR, "D3F0-PE0 - Card Present: %x\n", D8));

                    Status = PeiNbCheckPcieLinkStatus(PeiServices, NbConfig, CHX002_PE0, PCIE_TEMP_BUS_NUMBER);
                    if(EFI_ERROR(Status))
                    {
                        PCIeCommonPERST(PeiServices,CHX002_PE0);
                        if(Retry1%3 == 0)
                            PeiNbPcieStall(PeiServices,2000);    // 2 S
                        else
                            PeiNbPcieStall(PeiServices,63);     // 1/16 S
                        Retry1--;
                    }
                    else
                    {
                        break;
                    }

                }
                else
                {
                    // Not Present
                    PEI_DEBUG((PeiServices, EFI_D_ERROR, "D3F0-PE0 - Card Not Present: %x\n", D8));
                    break;
                }
            }
            while(Retry1);

            if(Retry1==0)
            {
                PcieLinkFailFlag = TRUE;
            }
        }

        // PE1
        if(PE1Rst)
        {
            PEI_DEBUG((PeiServices, EFI_D_ERROR, "PE1Rst\n"));
            Retry1 = 5;
            do
            {
                //Check PCIE Presence
                D8 = AsiaPciRead8(CHX002_PE1|D3D5F1_SLOT_STA_1);        //Rx5A
                if (D8 & D3D5F1_SPDCST)
                {
                    PEI_DEBUG((PeiServices, EFI_D_ERROR, "D3F1-PE1 - Card Present: %x\n", D8));

                    Status = PeiNbCheckPcieLinkStatus(PeiServices, NbConfig, CHX002_PE1, PCIE_TEMP_BUS_NUMBER);
                    if(EFI_ERROR(Status))
                    {
                        PCIeCommonPERST(PeiServices,CHX002_PE1);
                        if(Retry1%3 == 0)
                            PeiNbPcieStall(PeiServices,2000);    // 2 S
                        else
                            PeiNbPcieStall(PeiServices,63);     // 1/16 S
                        Retry1--;
                    }
                    else
                    {
                        break;
                    }

                }
                else
                {
                    // Not Present
                    PEI_DEBUG((PeiServices, EFI_D_ERROR, "D3F1-PE1 - Card Not Present: %x\n", D8));
                    break;
                }
            }
            while(Retry1);
            if(Retry1==0)
            {
                PcieLinkFailFlag = TRUE;
            }
        }

        // PE2
//        if((PE2Rst)&& (PE2Exist))
        if(PE2Rst)
        {
                PEI_DEBUG((PeiServices, EFI_D_ERROR, "PE2Rst\n"));
            Retry1 = 5;
            do
            {
                //Check PCIE Presence
                D8 = AsiaPciRead8(CHX002_PE2|D3D5F1_SLOT_STA_1);        //Rx5A
                if (D8 & D3D5F1_SPDCST)
                {
                    PEI_DEBUG((PeiServices, EFI_D_ERROR, "D3F2-PE2 - Card Present: %x\n", D8));

                    Status = PeiNbCheckPcieLinkStatus(PeiServices, NbConfig, CHX002_PE2, PCIE_TEMP_BUS_NUMBER);
                    if(EFI_ERROR(Status))
                    {
                        PCIeCommonPERST(PeiServices,CHX002_PE2);
                        if(Retry1%3 == 0)
                            PeiNbPcieStall(PeiServices,2000);    // 2 S
                        else
                            PeiNbPcieStall(PeiServices,63);     // 1/16 S
                        Retry1--;
                    }
                    else
                    {
                        break;
                    }

                }
                else
                {
                    // Not Present
                    PEI_DEBUG((PeiServices, EFI_D_ERROR, "D3F2-PE2 - Card Not Present: %x\n", D8));
                    break;
                }
            }
            while(Retry1);
            if(Retry1==0)
            {
                PcieLinkFailFlag = TRUE;
            }
        }

        // PE3
        if(PE3Rst)
        {
                        PEI_DEBUG((PeiServices, EFI_D_ERROR, "PE3Rst\n"));
                        Retry1 = 5;
            do
            {
                //Check PCIE Presence
                D8 = AsiaPciRead8(CHX002_PE3|D3D5F1_SLOT_STA_1);        //Rx5A
                if (D8 & D3D5F1_SPDCST)
                {
                    PEI_DEBUG((PeiServices, EFI_D_ERROR, "D3F3-PE3 - Card Present: %x\n", D8));

                    Status = PeiNbCheckPcieLinkStatus(PeiServices, NbConfig, CHX002_PE3, PCIE_TEMP_BUS_NUMBER);
                    if(EFI_ERROR(Status))
                    {
                        PCIeCommonPERST(PeiServices,CHX002_PE3);
                        if(Retry1%3 == 0)
                            PeiNbPcieStall(PeiServices,2000);    // 2 S
                        else
                            PeiNbPcieStall(PeiServices,63);     // 1/16 S
                        Retry1--;
                    }
                    else
                    {
                        break;
                    }

                }
                else
                {
                    // Not Present
                    PEI_DEBUG((PeiServices, EFI_D_ERROR, "D3F3-PE3 - Card Not Present: %x\n", D8));
                    break;
                }
            }
            while(Retry1);
            if(Retry1==0)
            {
                PcieLinkFailFlag = TRUE;
            }
        }

        // PE4
        if(PE4Rst)
        {
            PEI_DEBUG((PeiServices, EFI_D_ERROR, "PE4Rst\n"));
            Retry1 = 5;
            do
            {
                //Check PCIE Presence
                D8 = AsiaPciRead8(CHX002_PE4|D3D5F1_SLOT_STA_1);       //Rx5A
                if (D8 & D3D5F1_SPDCST)
                {
                    PEI_DEBUG((PeiServices, EFI_D_ERROR, "D4F0-PE4 - Card Present: %x\n", D8));

                    Status = PeiNbCheckPcieLinkStatus(PeiServices, NbConfig, CHX002_PE4, PCIE_TEMP_BUS_NUMBER);
                    if(EFI_ERROR(Status))
                    {
                        PCIeCommonPERST(PeiServices,CHX002_PE4);
                        if(Retry1%3 == 0)
                            PeiNbPcieStall(PeiServices,2000);    // 2 S
                        else
                            PeiNbPcieStall(PeiServices,63);     // 1/16 S
                        Retry1--;
                    }
                    else
                    {
                        break;
                    }

                }
                else
                {
                    // Not Present
                    PEI_DEBUG((PeiServices, EFI_D_ERROR, "D4F0-PE4 - Card Not Present: %x\n", D8));
                    break;
                }
            }
            while(Retry1);

            if(Retry1==0)
            {
                PcieLinkFailFlag = TRUE;
            }
        }

        // PE5
        if(PE5Rst)
        {
            PEI_DEBUG((PeiServices, EFI_D_ERROR, "PE5Rst\n"));
            Retry1 = 5;
            do
            {
                //Check PCIE Presence
                D8 = AsiaPciRead8(CHX002_PE5|D3D5F1_SLOT_STA_1);       //Rx5A
                if (D8 & D3D5F1_SPDCST)
                {
                    PEI_DEBUG((PeiServices, EFI_D_ERROR, "D4F1-PE5 - Card Present: %x\n", D8));

                    Status = PeiNbCheckPcieLinkStatus(PeiServices, NbConfig, CHX002_PE5, PCIE_TEMP_BUS_NUMBER);
                    if(EFI_ERROR(Status))
                    {
                        PCIeCommonPERST(PeiServices,CHX002_PE5);
                        if(Retry1%3 == 0)
                            PeiNbPcieStall(PeiServices,2000);    // 2 S
                        else
                            PeiNbPcieStall(PeiServices,63);     // 1/16 S
                        Retry1--;
                    }
                    else
                    {
                        break;
                    }

                }
                else
                {
                    // Not Present
                    PEI_DEBUG((PeiServices, EFI_D_ERROR, "D4F1-PE5 - Card Not Present: %x\n", D8));
                    break;
                }
            }
            while(Retry1);

            if(Retry1==0)
            {
                PcieLinkFailFlag = TRUE;
            }
        }

        // PE6
        if(PE6Rst)
        {
                PEI_DEBUG((PeiServices, EFI_D_ERROR, "PE6Rst\n"));
            Retry1 = 5;
            do
            {
                //Check PCIE Presence
                D8 = AsiaPciRead8(CHX002_PE6|D3D5F1_SLOT_STA_1);       //Rx5A
                if (D8 & D3D5F1_SPDCST)
                {
                    PEI_DEBUG((PeiServices, EFI_D_ERROR, "D5F0-PE6 - Card Present: %x\n", D8));

                    Status = PeiNbCheckPcieLinkStatus(PeiServices, NbConfig, CHX002_PE6, PCIE_TEMP_BUS_NUMBER);
                    if(EFI_ERROR(Status))
                    {
                        PCIeCommonPERST(PeiServices,CHX002_PE6);
                        if(Retry1%3 == 0)
                            PeiNbPcieStall(PeiServices,2000);    // 2 S
                        else
                            PeiNbPcieStall(PeiServices,63);     // 1/16 S
                        Retry1--;
                    }
                    else
                    {
                        break;
                    }

                }
                else
                {
                    // Not Present
                    PEI_DEBUG((PeiServices, EFI_D_ERROR, "D5F0-PE6 - Card Not Present: %x\n", D8));
                    break;
                }
            }
            while(Retry1);

            if(Retry1==0)
            {
                PcieLinkFailFlag = TRUE;
            }
        }

        // PE7
        if(PE7Rst)
        {
            PEI_DEBUG((PeiServices, EFI_D_ERROR, "PE7Rst\n"));
            Retry1 = 5;
            do
            {
                //Check PCIE Presence
                D8 = AsiaPciRead8(CHX002_PE7|D3D5F1_SLOT_STA_1);       //Rx5A
                if (D8 & D3D5F1_SPDCST)
                {
                    PEI_DEBUG((PeiServices, EFI_D_ERROR, "D5F1-PE7 - Card Present: %x\n", D8));

                    Status = PeiNbCheckPcieLinkStatus(PeiServices, NbConfig, CHX002_PE7, PCIE_TEMP_BUS_NUMBER);
                    if(EFI_ERROR(Status))
                    {
                        PCIeCommonPERST(PeiServices,CHX002_PE7);
                        if(Retry1%3 == 0)
                            PeiNbPcieStall(PeiServices,2000);    // 2 S
                        else
                            PeiNbPcieStall(PeiServices,63);     // 1/16 S
                        Retry1--;
                    }
                    else
                    {
                        break;
                    }

                }
                else
                {
                    // Not Present
                    PEI_DEBUG((PeiServices, EFI_D_ERROR, "D5F1-PE7 - Card Not Present: %x\n", D8));
                    break;
                }
            }
            while(Retry1);

            if(Retry1==0)
            {
                PcieLinkFailFlag = TRUE;
            }
        }


        if(!PcieLinkFailFlag)
        {
            // All PCIE Link is OK.
            PEI_DEBUG((PeiServices, EFI_D_ERROR, "All PCIE Link is OK!\n"));
            break;
        }else{
            PEI_DEBUG((PeiServices, EFI_D_ERROR, "Checking Pcie Link...\n"));
        }

    }
    while(Retry--);//Reset all PCIE Link if link still fail after single RP reset

    if(Retry == 0)
    {
        PEI_DEBUG((PeiServices, EFI_D_ERROR, "PCIE Card Init Fail\n"));
    }

    return EFI_SUCCESS;

}

/**
   This Function enable NB PCIE SERR ability.

  @param  PeiServices	EFI_PEI_SERVICES pointer.
  @param  pNbConfig  point to ASIA_NB_CONFIGURATION
  @param PciAddress target pci device's address
  @param PCIE_SETUP_DATA

  @return The value from this function.

**/
EFI_STATUS
PCIE_SERR_NB_Enable(
    IN EFI_PEI_SERVICES **PeiServices,
    IN ASIA_NB_CONFIGURATION *NbConfig,
    IN UINT64 Address,
    IN UINT8 PCIE_SETUP_DATA
)
{
    UINT64      PcieBase;
    
    PcieBase = NbConfig->PcieBar;

    //for AER coming from this PCIE RP
    //No need to proram SERR Enable (RP_Rx04[8]) because it will controlled by Kernel
        
    AsiaPcieModify8(PcieBase, Address|((UINT64)D3D5F1_DEV_CTL_1 << 32), D3D5F1_DCURRE, D3D5F1_DCURRE);      //Enable Unsupported Request Report in this RP

    switch(PCIE_SETUP_DATA){        //Enable AER Reporting Path in this RP according to Setup-Item
        case ERR_Disable:
            AsiaPcieModify8(PcieBase, Address|((UINT64)D3D5F1_DEV_CTL_1 << 32), (D3D5F1_DCCERE + D3D5F1_DCNFERE + D3D5F1_DCFERE), 0x00);    //AER Report in Device Control Reg
            AsiaPcieModify8(PcieBase, Address|((UINT64)D3D5F1_ROOT_CTL << 32), (D3D5F1_RCSECEE + D3D5F1_RCSENFEE + D3D5F1_RCSEFEE), 0x00);  //AER System Error Report in Device Control Reg
            break;                  
        case ERR_Uncorrectable:
            AsiaPcieModify8(PcieBase, Address|((UINT64)D3D5F1_DEV_CTL_1 << 32), (D3D5F1_DCCERE + D3D5F1_DCNFERE + D3D5F1_DCFERE), (D3D5F1_DCNFERE + D3D5F1_DCFERE));        //AER Report in Device Control Reg
            AsiaPcieModify8(PcieBase, Address|((UINT64)D3D5F1_ROOT_CTL << 32), (D3D5F1_RCSECEE + D3D5F1_RCSENFEE + D3D5F1_RCSEFEE), (D3D5F1_RCSENFEE + D3D5F1_RCSEFEE));    //AER System Error Report in Device Control Reg
            break;
        case ERR_Correctable:
            AsiaPcieModify8(PcieBase, Address|((UINT64)D3D5F1_DEV_CTL_1 << 32), (D3D5F1_DCCERE + D3D5F1_DCNFERE + D3D5F1_DCFERE), D3D5F1_DCCERE);   //AER Report in Device Control Reg
            AsiaPcieModify8(PcieBase, Address|((UINT64)D3D5F1_ROOT_CTL << 32), (D3D5F1_RCSECEE + D3D5F1_RCSENFEE + D3D5F1_RCSEFEE), D3D5F1_RCSECEE);        //AER System Error Report in Device Control Reg
            break;
        case ERR_Both:
            AsiaPcieModify8(PcieBase, Address|((UINT64)D3D5F1_DEV_CTL_1 << 32), (D3D5F1_DCCERE + D3D5F1_DCNFERE + D3D5F1_DCFERE), (D3D5F1_DCCERE + D3D5F1_DCNFERE + D3D5F1_DCFERE));        //AER Report in Device Control Reg
            AsiaPcieModify8(PcieBase, Address|((UINT64)D3D5F1_ROOT_CTL << 32), (D3D5F1_RCSECEE + D3D5F1_RCSENFEE + D3D5F1_RCSEFEE), (D3D5F1_RCSECEE + D3D5F1_RCSENFEE + D3D5F1_RCSEFEE));   //AER System Error Report in Device Control Reg
            break;
        default:
            //Impossible Case; do nothing
            break;
    }                               

    //for AER coming from EP behind the RP
    //No need to proram SERR Forwarding (RP_Rx3E[1]) because it will controlled by Kernel

    return EFI_SUCCESS;
}

/**
   This Function set PCIE SERR Interrupt control.

  @param  PeiServices	EFI_PEI_SERVICES pointer.
  @param  pNbConfig  point to ASIA_NB_CONFIGURATION
  @param PciAddress target pci device's address
  @param PCIE_SETUP_DATA

  @return The value from this function.

**/
EFI_STATUS
PCIE_NBSERR_IntCtrl_Enable(
    IN EFI_PEI_SERVICES **PeiServices,
    IN ASIA_NB_CONFIGURATION *NbConfig,
    IN UINT64 Address,
    IN UINT8 PCIE_SETUP_DATA
)
{
    UINT64      PcieBase;
	UINT8 		IntType;
	UINT8		ErrType;

	IntType = NbConfig->SERRNBControl;
	ErrType = PCIE_SETUP_DATA;
    
    PcieBase = NbConfig->PcieBar;

	//disable all Error type disable all interrupt first
	
	AsiaPcieModify8(NbConfig->PcieBar, Address|((UINT64)D3D5F1_SERR_NMI_SMI_SCI_CTL << 32), D3D5F1_FTERR_SMI_EN, 0);
	//Disable NB Non-Fatal Error SMI 
	AsiaPcieModify8(NbConfig->PcieBar, Address|((UINT64)D3D5F1_SERR_NMI_SMI_SCI_CTL << 32), D3D5F1_NFTERR_SMI_EN, 0);
	//Disable NB Correctable Error SMI	
	AsiaPcieModify8(NbConfig->PcieBar, Address|((UINT64)D3D5F1_SERR_NMI_SMI_SCI_CTL << 32), D3D5F1_CORERR_SMI_EN, 0);
	//Disable NB Fatal Error NMI 
	AsiaPcieModify8(NbConfig->PcieBar, Address|((UINT64)D3D5F1_SERR_NMI_SMI_SCI_CTL << 32), D3D5F1_FTERR_NMI_EN, 0);
	//Disable NB Non-Fatal Error NMI 
	AsiaPcieModify8(NbConfig->PcieBar, Address|((UINT64)D3D5F1_SERR_NMI_SMI_SCI_CTL << 32), D3D5F1_NFTERR_NMI_EN, 0);
	//Disable NB Correctable Error NMI	
	AsiaPcieModify8(NbConfig->PcieBar, Address|((UINT64)D3D5F1_SERR_NMI_SMI_SCI_CTL << 32), D3D5F1_CORERR_NMI_EN, 0);
	//Disable NB Fatal Error SCI 
	AsiaPcieModify16(NbConfig->PcieBar, Address|((UINT64)D3D5F1_SERR_NMI_SMI_SCI_CTL << 32), D3D5F1_FTERR_SCI_EN, 0);
	//Disable NB Non-Fatal Error SCI 
	AsiaPcieModify8(NbConfig->PcieBar, Address|((UINT64)D3D5F1_SERR_NMI_SMI_SCI_CTL << 32), D3D5F1_NFTERR_SCI_EN, 0);
	//Disable NB Correctable Error SCI	
	AsiaPcieModify8(NbConfig->PcieBar, Address|((UINT64)D3D5F1_SERR_NMI_SMI_SCI_CTL << 32), D3D5F1_CORERR_SCI_EN, 0);

	switch(ErrType){
		case ERR_Uncorrectable:
			if(IntType == ERR_SMI){
				//Enable NB Fatal Error SMI 
				AsiaPcieModify8(NbConfig->PcieBar, Address|((UINT64)D3D5F1_SERR_NMI_SMI_SCI_CTL << 32), D3D5F1_FTERR_SMI_EN, D3D5F1_FTERR_SMI_EN);
				//Enable NB Non-Fatal Error SMI 
				AsiaPcieModify8(NbConfig->PcieBar, Address|((UINT64)D3D5F1_SERR_NMI_SMI_SCI_CTL << 32), D3D5F1_NFTERR_SMI_EN, D3D5F1_NFTERR_SMI_EN);
				//Disable NB Correctable Error SMI	
				AsiaPcieModify8(NbConfig->PcieBar, Address|((UINT64)D3D5F1_SERR_NMI_SMI_SCI_CTL << 32), D3D5F1_CORERR_SMI_EN, 0);
				}
			else if(IntType == ERR_NMI)
				{
				//Enable NB Fatal Error NMI 
				AsiaPcieModify8(NbConfig->PcieBar, Address|((UINT64)D3D5F1_SERR_NMI_SMI_SCI_CTL << 32), D3D5F1_FTERR_NMI_EN, D3D5F1_FTERR_NMI_EN);
				//Enable NB Non-Fatal Error NMI 
				AsiaPcieModify8(NbConfig->PcieBar, Address|((UINT64)D3D5F1_SERR_NMI_SMI_SCI_CTL << 32), D3D5F1_NFTERR_NMI_EN, D3D5F1_NFTERR_NMI_EN);
				//Disable NB Correctable Error NMI	
				AsiaPcieModify8(NbConfig->PcieBar, Address|((UINT64)D3D5F1_SERR_NMI_SMI_SCI_CTL << 32), D3D5F1_CORERR_NMI_EN, 0);
				}
			else if(IntType == ERR_SCI)
				{
				//Enable NB Fatal Error SCI 
				AsiaPcieModify16(NbConfig->PcieBar, Address|((UINT64)D3D5F1_SERR_NMI_SMI_SCI_CTL << 32), D3D5F1_FTERR_SCI_EN, D3D5F1_FTERR_SCI_EN);
				//Enable NB Non-Fatal Error SCI 
				AsiaPcieModify8(NbConfig->PcieBar, Address|((UINT64)D3D5F1_SERR_NMI_SMI_SCI_CTL << 32), D3D5F1_NFTERR_SCI_EN, D3D5F1_NFTERR_SCI_EN);
				//Disable NB Correctable Error SCI	
				AsiaPcieModify8(NbConfig->PcieBar, Address|((UINT64)D3D5F1_SERR_NMI_SMI_SCI_CTL << 32), D3D5F1_CORERR_SCI_EN, 0);
				}
		
		break;
		case ERR_Correctable:
			if(IntType == ERR_SMI){
				//Disable NB Fatal Error SMI 
				AsiaPcieModify8(NbConfig->PcieBar, Address|((UINT64)D3D5F1_SERR_NMI_SMI_SCI_CTL << 32), D3D5F1_FTERR_SMI_EN, 0);
				//Disable NB Non-Fatal Error SMI 
				AsiaPcieModify8(NbConfig->PcieBar, Address|((UINT64)D3D5F1_SERR_NMI_SMI_SCI_CTL << 32), D3D5F1_NFTERR_SMI_EN, 0);
				//Enable NB Correctable Error SMI	
				AsiaPcieModify8(NbConfig->PcieBar, Address|((UINT64)D3D5F1_SERR_NMI_SMI_SCI_CTL << 32), D3D5F1_CORERR_SMI_EN, D3D5F1_CORERR_SMI_EN);
				}
			else if(IntType == ERR_SCI){
				//Disable NB Fatal Error SCI 
				AsiaPcieModify16(NbConfig->PcieBar, Address|((UINT64)D3D5F1_SERR_NMI_SMI_SCI_CTL << 32), D3D5F1_FTERR_SCI_EN, 0);
				//Disable NB Non-Fatal Error SCI 
				AsiaPcieModify8(NbConfig->PcieBar, Address|((UINT64)D3D5F1_SERR_NMI_SMI_SCI_CTL << 32), D3D5F1_NFTERR_SCI_EN, 0);
				//Enable NB Correctable Error SCI	
				AsiaPcieModify8(NbConfig->PcieBar, Address|((UINT64)D3D5F1_SERR_NMI_SMI_SCI_CTL << 32), D3D5F1_CORERR_SCI_EN, D3D5F1_CORERR_SCI_EN);
				}
			else if(IntType == ERR_NMI)
				{
				//Disable NB Fatal Error NMI 
				AsiaPcieModify8(NbConfig->PcieBar, Address|((UINT64)D3D5F1_SERR_NMI_SMI_SCI_CTL << 32), D3D5F1_FTERR_NMI_EN, 0);
				//Disable NB Non-Fatal Error NMI 
				AsiaPcieModify8(NbConfig->PcieBar, Address|((UINT64)D3D5F1_SERR_NMI_SMI_SCI_CTL << 32), D3D5F1_NFTERR_NMI_EN, 0);
				//Enable NB Correctable Error NMI	
				AsiaPcieModify8(NbConfig->PcieBar, Address|((UINT64)D3D5F1_SERR_NMI_SMI_SCI_CTL << 32), D3D5F1_CORERR_NMI_EN, D3D5F1_CORERR_NMI_EN);
				}
			break;
		case ERR_Both:
			if(IntType == ERR_SMI){
				//Enable NB Fatal Error SMI 
				AsiaPcieModify8(NbConfig->PcieBar, Address|((UINT64)D3D5F1_SERR_NMI_SMI_SCI_CTL << 32), D3D5F1_FTERR_SMI_EN, D3D5F1_FTERR_SMI_EN);
				//Enable NB Non-Fatal Error SMI 
				AsiaPcieModify8(NbConfig->PcieBar, Address|((UINT64)D3D5F1_SERR_NMI_SMI_SCI_CTL << 32), D3D5F1_NFTERR_SMI_EN, D3D5F1_NFTERR_SMI_EN);
				//Enable NB Correctable Error SMI	
				AsiaPcieModify8(NbConfig->PcieBar, Address|((UINT64)D3D5F1_SERR_NMI_SMI_SCI_CTL << 32), D3D5F1_CORERR_SMI_EN, D3D5F1_CORERR_SMI_EN);
				}
			else if(IntType == ERR_SCI){
				//Enable NB Fatal Error SCI 
				AsiaPcieModify16(NbConfig->PcieBar, Address|((UINT64)D3D5F1_SERR_NMI_SMI_SCI_CTL << 32), D3D5F1_FTERR_SCI_EN, D3D5F1_FTERR_SCI_EN);
				//Enable NB Non-Fatal Error SCI 
				AsiaPcieModify8(NbConfig->PcieBar, Address|((UINT64)D3D5F1_SERR_NMI_SMI_SCI_CTL << 32), D3D5F1_NFTERR_SCI_EN, D3D5F1_NFTERR_SCI_EN);
				//Enable NB Correctable Error SCI	
				AsiaPcieModify8(NbConfig->PcieBar, Address|((UINT64)D3D5F1_SERR_NMI_SMI_SCI_CTL << 32), D3D5F1_CORERR_SCI_EN, D3D5F1_CORERR_SCI_EN);
				}
			else if(IntType == ERR_NMI)
				{
				//Enable NB Fatal Error NMI 
				AsiaPcieModify8(NbConfig->PcieBar, Address|((UINT64)D3D5F1_SERR_NMI_SMI_SCI_CTL << 32), D3D5F1_FTERR_NMI_EN, D3D5F1_FTERR_NMI_EN);
				//Enable NB Non-Fatal Error NMI 
				AsiaPcieModify8(NbConfig->PcieBar, Address|((UINT64)D3D5F1_SERR_NMI_SMI_SCI_CTL << 32), D3D5F1_NFTERR_NMI_EN, D3D5F1_NFTERR_NMI_EN);
				//Enable NB Correctable Error NMI	
				AsiaPcieModify8(NbConfig->PcieBar, Address|((UINT64)D3D5F1_SERR_NMI_SMI_SCI_CTL << 32), D3D5F1_CORERR_NMI_EN, D3D5F1_CORERR_NMI_EN);
				}
			break;
		default:
			break;
		}
	return EFI_SUCCESS;
}
//lna_err_debug-end

/**
   This Function Set PCIE PHY Driving values.

  @param  PeiServices	EFI_PEI_SERVICES pointer.
  @param  pNbConfig  point to ASIA_NB_CONFIGURATION

  @return The value from this function.

**/

void SetPciePhyDriving(
    IN EFI_PEI_SERVICES **PeiServices,
    IN ASIA_NB_CONFIGURATION *NbConfig
)
{
    SI_PCIE_RP_PHY_DRIVING_ITEM *Current_Item;//Item2
    UINTN   Index;
    UINTN   Inner1Index;
    UINT8   ChipRevision;
    //UINT16   bData16;  
	UINT8	 bData8;

    //Get chipset revision, D0F4RxF6
    ChipRevision = AsiaPciRead8(CHX002_NPMC|D0F4_INTERNAL_REV_ID);
	//open control bit RxE0[6] ,BIOS write permission to PEMCU related registers.
	AsiaMemoryModify8(NbConfig->PcieEPHYBar |PCIEPHYCFG_PCIE_ROMSIP_REG, PCIEPHYCFG_R_PEMCU_BIOS, PCIEPHYCFG_R_PEMCU_BIOS);

	PCIeCommonEphyPatch(PeiServices,NbConfig,NbConfig->PcieEPHYBar);

    // JIH - Enable Back Door for RP PCIE EPHY configure
    AsiaPcieModify8(NbConfig->PcieBar, CHX002_APIC|((UINT64)D0F5_PMU_CTL << 32), D0F5_RPEROWEN, D0F5_RPEROWEN);

    for (Index = 0; Index < PcieRpDrivingTblItems; Index++) {
        Current_Item = &PcieRpDrivingTbl[Index];  
	
       // bData16 = ShiftToMaskBit(Current_Item->Mask, Current_Item->Value);
        bData8 = Current_Item->Value;
        switch (Current_Item->RegType) {
            case PCIEPHYREGDETECT_DEF:
                           AsiaMemoryModify8(NbConfig->PcieEPHYBar |Current_Item->RegisterNum , Current_Item->Mask, bData8);
                        break;
            case PCIEPHYREGDETECT_CONT : 
                            for(Inner1Index = 0; Inner1Index <= Current_Item->RegLoop; Inner1Index ++)
                           AsiaMemoryModify8(NbConfig->PcieEPHYBar |(Current_Item->RegisterNum + Inner1Index) , Current_Item->Mask, bData8);
                        break;
            case PCIEPHYREGDETECT_EVEN : 
                            for(Inner1Index = 0; Inner1Index <= Current_Item->RegLoop; Inner1Index ++)
                           AsiaMemoryModify8(NbConfig->PcieEPHYBar |(Current_Item->RegisterNum + (Inner1Index << 1)) , Current_Item->Mask, bData8);
                        break;
            case PCIEPHYREGDETECT_ODD :
                            for(Inner1Index = 0; Inner1Index <= Current_Item->RegLoop; Inner1Index ++)
                           AsiaMemoryModify8(NbConfig->PcieEPHYBar |(Current_Item->RegisterNum + (Inner1Index << 1)) , Current_Item->Mask, bData8);
                        break;


           case PCIEPHYREGDETECT_PE4 :
                            for(Inner1Index = 0; Inner1Index <= Current_Item->RegLoop; Inner1Index ++)             
							AsiaPcieModify8(NbConfig->PcieBar, CHX002_PE4|LShiftU64((UINT64)(Current_Item->RegisterNum + (Inner1Index << 1)),32), Current_Item->Mask, bData8);

							break;
           case PCIEPHYREGDETECT_PE5 :
                            for(Inner1Index = 0; Inner1Index <= Current_Item->RegLoop; Inner1Index ++)
                           AsiaPcieModify8(NbConfig->PcieBar, CHX002_PE5|LShiftU64((UINT64)(Current_Item->RegisterNum + (Inner1Index << 1)),32), Current_Item->Mask, bData8);
                        break;
           case PCIEPHYREGDETECT_PE6 :
                            for(Inner1Index = 0; Inner1Index <= Current_Item->RegLoop; Inner1Index ++)
                           AsiaPcieModify8(NbConfig->PcieBar, CHX002_PE6|LShiftU64((UINT64)(Current_Item->RegisterNum + (Inner1Index << 1)),32), Current_Item->Mask, bData8);
                        break;
           case PCIEPHYREGDETECT_PE7 :
                            for(Inner1Index = 0; Inner1Index <= Current_Item->RegLoop; Inner1Index ++)
                           AsiaPcieModify8(NbConfig->PcieBar, CHX002_PE7|LShiftU64((UINT64)(Current_Item->RegisterNum + (Inner1Index << 1)),32), Current_Item->Mask, bData8);
                        break;
           case PCIEPHYREGDETECT_PE0 :
                            for(Inner1Index = 0; Inner1Index <= Current_Item->RegLoop; Inner1Index ++)
                           AsiaPcieModify8(NbConfig->PcieBar, CHX002_PE0|LShiftU64((UINT64)(Current_Item->RegisterNum + (Inner1Index << 1)),32), Current_Item->Mask, bData8);
                        break;
           case PCIEPHYREGDETECT_PE1 :
                            for(Inner1Index = 0; Inner1Index <= Current_Item->RegLoop; Inner1Index ++)
                           AsiaPcieModify8(NbConfig->PcieBar, CHX002_PE1|LShiftU64((UINT64)(Current_Item->RegisterNum + (Inner1Index << 1)),32), Current_Item->Mask, bData8);
                        break;
           case PCIEPHYREGDETECT_PE2 :
                            for(Inner1Index = 0; Inner1Index <= Current_Item->RegLoop; Inner1Index ++)
                           AsiaPcieModify8(NbConfig->PcieBar, CHX002_PE2|LShiftU64((UINT64)(Current_Item->RegisterNum + (Inner1Index << 1)),32), Current_Item->Mask, bData8);
                        break;
           case PCIEPHYREGDETECT_PE3 :
                            for(Inner1Index = 0; Inner1Index <= Current_Item->RegLoop; Inner1Index ++)
                           AsiaPcieModify8(NbConfig->PcieBar, CHX002_PE3|LShiftU64((UINT64)(Current_Item->RegisterNum + (Inner1Index << 1)),32), Current_Item->Mask, bData8);
        }       
    }
        
    // JIH - Disable Back Door for RP PCIE EPHY configure
    AsiaPcieModify8(NbConfig->PcieBar, CHX002_APIC|((UINT64)D0F5_PMU_CTL << 32), D0F5_RPEROWEN, 0x00);
	
    //set PCIE phy driving SI version to D0F6Rx43[7:0]
    AsiaPciWrite8(CHX002_SCRCH|(D0F6_BIOS_SCRATCH_REG_1+3),PCIE_PHY_DRIVING_VER);
	// Close control bit RxE0[6] ,BIOS write permission to PEMCU related registers.
	AsiaMemoryModify8(NbConfig->PcieEPHYBar |PCIEPHYCFG_PCIE_ROMSIP_REG, PCIEPHYCFG_R_PEMCU_BIOS, 0);

}


/**
   This Function programm PCIE SSID/SVID.

  @param  VOID

**/
void ProgramPcieSsidSvid()
{
	/*LNA20160829-01
	AsiaPciWrite32(CHX001_PEG|D3D5F1_SVID_CTL, 0x07161106);//CHX001 D2F0
    AsiaPciWrite32(CHX001_PE0|D3D5F1_SVID_CTL, 0x07171106);//D3F0
    AsiaPciWrite32(CHX001_PE1|D3D5F1_SVID_CTL, 0x07181106);//D3F1
    AsiaPciWrite32(CHX001_PE2|D3D5F1_SVID_CTL, 0x07191106);//D3F2
    AsiaPciWrite32(CHX001_PE3|D3D5F1_SVID_CTL, 0x071a1106);//D3F3
    AsiaPciWrite32(CHX001_PEG0|D3D5F1_SVID_CTL, 0x071b1106);//D4F0
    AsiaPciWrite32(CHX001_PEG1|D3D5F1_SVID_CTL, 0x071c1106);//D4F1
    AsiaPciWrite32(CHX001_PEG2|D3D5F1_SVID_CTL, 0x071d1106);//D5F0
    AsiaPciWrite32(CHX001_PEG3|D3D5F1_SVID_CTL, 0x071e1106);//D5F1*/
}

/**
   This Function get TSSM ROMSIP Value.

  @param  pNbConfig  point to ASIA_NB_CONFIGURATION
  @param PciAddress target pci device's address

  @return BOOLEAN.

**/
BOOLEAN GetLTSSMRomsipValue(
IN ASIA_NB_CONFIGURATION *NbConfig,     
IN UINT64 PciAddress)
{
    UINT64 Data1,Data2;
    UINT64 PcieBase;
    UINT8 Data8;
    PcieBase = NbConfig->PcieBar; 
    Data1 = PciAddress;
    switch(Data1)
    {

        case CHX002_PE6:
            Data8 = AsiaPcieRead8(PcieBase, CHX002_GFXAX|D0F0_PCIE_ROMSIP_REGS_Z1);
            Data8 &= BIT7;
            if(Data8) return TRUE;
            break;  
        case CHX002_PE7:
            Data8 = AsiaPcieRead8(PcieBase, CHX002_GFXAX|D0F0_PCIE_ROMSIP_REGS_Z1);
            Data8 &= BIT6;
            if(Data8) return TRUE;
            break;  
        case CHX002_PE4:
            Data2 = AsiaPcieRead64(PcieBase, CHX002_GFXAX|D0F0_PCIE_ROMSIP_REGS);
            Data2 &= BIT19;
            if(Data2) return TRUE;
            break;  
        case CHX002_PE5:
            Data2 = AsiaPcieRead64(PcieBase, CHX002_GFXAX|D0F0_PCIE_ROMSIP_REGS);
            Data2 &= BIT18;
            if(Data2) return TRUE;
            break;  

			
        case CHX002_PE0:
            Data2 = AsiaPcieRead64(PcieBase, CHX002_GFXAX|D0F0_PCIE_ROMSIP_REGS);
            Data2 &= BIT23;
            if(Data2) return TRUE;
            break;  
        case CHX002_PE1:
            Data2 = AsiaPcieRead64(PcieBase, CHX002_GFXAX|D0F0_PCIE_ROMSIP_REGS);
            Data2 &= BIT22;
            if(Data2) return TRUE;
            break;  
        case CHX002_PE2:
            Data2 = AsiaPcieRead64(PcieBase, CHX002_GFXAX|D0F0_PCIE_ROMSIP_REGS);
            Data2 &= BIT21;
            if(Data2) return TRUE;
            break;
        case CHX002_PE3:
            Data2 = AsiaPcieRead64(PcieBase, CHX002_GFXAX|D0F0_PCIE_ROMSIP_REGS);
            Data2 &= BIT20;
            if(Data2) return TRUE;
        }

        return FALSE;

}

/**
   This Function check LTSSM for software reset

  @param  PeiServices	EFI_PEI_SERVICES pointer.
  @param  pNbConfig  point to ASIA_NB_CONFIGURATION
  @param PciAddress target pci device's address

  @return VOID.

**/
void LTSSMCheckForSwRst(
    IN EFI_PEI_SERVICES **PeiServices,
        IN ASIA_NB_CONFIGURATION *NbConfig,
        IN UINT64 PciAddress)
{
   UINT64 PcieBase;
   UINT8 Data;
   PcieBase = NbConfig->PcieBar; 

/*
// CJW_20170509 removed - this part is required by SI team, cancel it for CHX002 temporary
   // JIH - 2016112301 Selectable De-emphasis -6dB and -3.5dB before LTSSM check for SW reset;
   if(NbConfig->SelectableDeEmphasis != Gen2_DeEmphasis_SItable){
	   AsiaPcieModify8(PcieBase, CHX002_APIC|((UINT64)D0F5_PMU_CTL << 32), D0F5_RPEROWEN, D0F5_RPEROWEN);
	   
	   if(NbConfig->SelectableDeEmphasis == Gen2_DeEmphasis_Force3p5)
		   AsiaPcieModify8(PcieBase, PciAddress|((UINT64)D3D5F1_LINK_CTL_2_D4F0 << 32), D3D5F1_SELDEEMPHS, D3D5F1_SELDEEMPHS);
	   else
		   AsiaPcieModify8(PcieBase, PciAddress|((UINT64)D3D5F1_LINK_CTL_2_D4F0 << 32), D3D5F1_SELDEEMPHS, 0);
	   	
	   AsiaPcieModify8(PcieBase, CHX002_APIC|((UINT64)D0F5_PMU_CTL << 32), D0F5_RPEROWEN, 0x00);
   	}
*/


//D0F0RxFB[7]:PEG2;[6]:PEG3;[5]:PEG
//D0F0RxFA[7]:PE0;[6]:PE1;[5]:PE2;[4]:PE3;[3]:PEG0;[2]:PEG1
//ROMSIP Setting for "LTSSM_SW_RESET_EN_PE*" as "0"
   if(GetLTSSMRomsipValue(NbConfig,PciAddress)){
                
                AsiaPcieModify8(PcieBase, PciAddress|((UINT64)D3D5F1_LTSSM_SW_RST_D3F0 << 32), D3D5F1_LTSSM_SW_RESET, D3D5F1_LTSSM_SW_RESET);
	/*+ DSZ_Porting (JIH-2017081401) Remove some PCIe delay for Boot time optimization*/

				//PeiNbPcieStall(PeiServices,63);         // 1/16 S
      //  Data = AsiaPcieRead8(PcieBase, PciAddress|((UINT64)D3D5F1_PHYLS_LTSSM_STATE << 32));
      //  if (Data < PHYLS_State_L0 )     AsiaIoWrite8(0x80,0xAA);
         // else AsiaIoWrite8(0x80,0xBB);
    /*- DSZ_Porting (JIH-2017081401) Remove some PCIe delay for Boot time optimization*/
        }
   else
        {
        
		/*+ DSZ_Porting (JIH-2017081401) Remove some PCIe delay for Boot time optimization*/
          // PeiNbPcieStall(PeiServices,63);         // 1/16 S
           PEI_DEBUG((PeiServices, EFI_D_INFO, "       Check Link Status for HW reset\n"));
		   
		/*- DSZ_Porting (JIH-2017081401) Remove some PCIe delay for Boot time optimization*/
           Data = AsiaPcieRead8(PcieBase, PciAddress|((UINT64)D3D5F1_PHYLS_LTSSM_STATE << 32));
           if (Data < PHYLS_State_L0 ) AsiaIoWrite8(0x80,0xAA);
           else AsiaIoWrite8(0x80,0xBB);
        }
}


/**
   This Function Set PCIE Routing Control to avoid INT Sharing.

  @param  PeiServices	EFI_PEI_SERVICES pointer.
  @param  pNbConfig  point to ASIA_NB_CONFIGURATION
  @param PciAddress target pci device's address

  @return The value from this function.

**/
void PCIERoutingCtrl(
    IN EFI_PEI_SERVICES **PeiServices,
    IN ASIA_NB_CONFIGURATION *NbConfig,
    IN UINT64 PciAddress)
{
    UINT64 PcieBase;
    UINT8 Tmp1, i;

    PEI_DEBUG((PeiServices, EFI_D_INFO, "[PCIE] RoutingCtrl: entry\n"));

    PcieBase = NbConfig->PcieBar;

	Tmp1 = AsiaPciRead8(CHX002_GFXAX|D0F0_PCIE_ROMSIP_REGS_Z1);
    Tmp1 &= D0F0_RPCIESATACFG_3_0;   //check PCIE Configuration from D0F0_RxFB[4:0]
    PEI_DEBUG((PeiServices, EFI_D_INFO, "[PCIE]ECFG: %d\n",Tmp1));
        
    for(i=0; i<sizeof(PEIOAPIC_Tbl)/sizeof(PEIOAPICTbl); i++) //Check the PEIOAPIC Table for each RP Routing defined for specific ECFG
    {
        if(Tmp1 == PEIOAPIC_Tbl[i].PECFG){

	   	    //D5F0 (PE6)
            if(PciAddress == CHX002_PE6)
                AsiaPcieModify8(PcieBase, CHX002_GFXAX|((UINT64)D0F0_PCIE_PORT_G2_INTR_ROUTING_SEL << 32), 
                				D0F0_RINTRTAPIC_PEG2_1_0, (PEIOAPIC_Tbl[i].PE6_IOAPICRouting << 4));

	   	    //D5F1 (PE7)
            if(PciAddress == CHX002_PE7)
                AsiaPcieModify8(PcieBase, CHX002_GFXAX|((UINT64)D0F0_PCIE_PORT_G3_INTR_ROUTING_SEL << 32), 
                				D0F0_RINTRTAPIC_PEG3_1_0, (PEIOAPIC_Tbl[i].PE7_IOAPICRouting << 4));
        }
    }
}
//;ysw_debug - 20161012 - end
//LNA-2016122701-S


/**
   This Function PCIE OBFF Control.

  @param  PeiServices	EFI_PEI_SERVICES pointer.
  @param  pNbConfig  point to ASIA_NB_CONFIGURATION
  @param PciAddress target pci device's address

  @return The value from this function.

**/
void PCIEOBFFCtrl(
		IN EFI_PEI_SERVICES **PeiServices,
		IN ASIA_NB_CONFIGURATION *NbConfig,
		IN UINT64 PciAddress)
{
    UINT64 PcieBase;
	UINT16 PmioBase = 0;
	EFI_ASIA_SB_PPI	    *pSbPpi;
    EFI_GUID             AsiaSbPpiGuid = EFI_ASIA_SB_PPI_GUID;
    EFI_STATUS          Status;
	ASIA_SB_CONFIGURATION       *SbConfig;
	UINT16 Data;
	
    PEI_DEBUG((PeiServices, EFI_D_INFO, "       [LNA_OBFF]PCIEOBFFCtrl: entry\n"));
	
	Status = (*PeiServices)->LocatePpi(PeiServices, &AsiaSbPpiGuid, 0, NULL, &pSbPpi);
    if(!EFI_ERROR(Status)) {
      SbConfig = pSbPpi->SbCfg;
      PmioBase = SbConfig ->PmioBar;
    }
	
	Data = AsiaIoRead16(PmioBase + PMIO_PM_STA);
	PEI_DEBUG((PeiServices, EFI_D_ERROR, "           PMIO Rx00:%04x <--\n", Data));
	

    PcieBase = NbConfig->PcieBar;

	// OBBF Enable - PMU
	AsiaIoModify8(PmioBase + PMIO_PCIE_OBFF_CTL_REG, PMIO_OBFF_EN, PMIO_OBFF_EN);		


	// OBFF mode select: 
	//		0: monitors Cx Command for OBFF.  
	//		1:monitors the Cx Control Signals for OBFF
	if(NbConfig->PcieOBFFCtrl_PMU == Cx_COMMAND_MONITOR)
		AsiaIoModify8(PmioBase + PMIO_PCIE_OBFF_CTL_REG, PMIO_OBFFMOD, 0);	//Cx command monitor mode
	else
		AsiaIoModify8(PmioBase + PMIO_PCIE_OBFF_CTL_REG, PMIO_OBFFMOD, PMIO_OBFFMOD);	//Cx signal monitor mode

	// Open Backdoor
	AsiaPcieModify8(PcieBase, CHX002_APIC|((UINT64)D0F5_PMU_CTL << 32), D0F5_RPEROWEN, 1);	 
	
	// OBFF supported 
	//		00: OBFF not supported. 
	//		01: OBFF supported using Message signaling only. 
	//		10: OBFF supported using WAKE# signaling only. 
	//		11: OBFF supported using WAKE# and Message signaling. 
	switch(NbConfig->PcieOBFFCtrl_PCIE){
		case OBFF_DISABLE:
			AsiaPcieModify32(PcieBase, PciAddress|((UINT64)D3D5F1_DEV_CAPS_2 << 32), D3D5F1_ROBFFSP, 0);	//NOT support OBFF
			AsiaPcieModify16(PcieBase, PciAddress|((UINT64)D3D5F1_DEV_CTL_2 << 32), D3D5F1_ROBFFEN, 0);
			AsiaIoModify8(PmioBase + PMIO_PCIE_OBFF_CTL_REG, PMIO_OBFF_EN, 0);	//disable PMIO OBFF
			break;
		case OBFF_PEXWAKE:
			AsiaPcieModify32(PcieBase, PciAddress|((UINT64)D3D5F1_DEV_CAPS_2 << 32), D3D5F1_ROBFFSP, D3D5F1_ROBFFSP);
			AsiaPcieModify16(PcieBase, PciAddress|((UINT64)D3D5F1_DEV_CTL_2 << 32), D3D5F1_ROBFFEN, D3D5F1_ROBFFEN);	//WAKE#
			AsiaIoModify8(PmioBase + PMIO_PCIE_OBFF_CTL_REG, PMIO_OBFFMSG, 0);	//use PEXWAKE#
			break;
		case OBFF_MSGA: 
			AsiaPcieModify32(PcieBase, PciAddress|((UINT64)D3D5F1_DEV_CAPS_2 << 32), D3D5F1_ROBFFSP, D3D5F1_ROBFFSP);
			AsiaPcieModify16(PcieBase, PciAddress|((UINT64)D3D5F1_DEV_CTL_2 << 32), D3D5F1_ROBFFEN, BIT13);	//Message A
			AsiaIoModify8(PmioBase + PMIO_PCIE_OBFF_CTL_REG, PMIO_OBFFMSG, PMIO_OBFFMSG);	//use Message
			break;
		case OBFF_MSGB: 
			AsiaPcieModify32(PcieBase, PciAddress|((UINT64)D3D5F1_DEV_CAPS_2 << 32), D3D5F1_ROBFFSP, D3D5F1_ROBFFSP);
			AsiaPcieModify16(PcieBase, PciAddress|((UINT64)D3D5F1_DEV_CTL_2 << 32), D3D5F1_ROBFFEN, BIT14);	//Message B
			AsiaIoModify8(PmioBase + PMIO_PCIE_OBFF_CTL_REG, PMIO_OBFFMSG, PMIO_OBFFMSG);	//use Message
			break;
		default:
			break;
	}

	// Close Backdoor
	AsiaPcieModify8(PcieBase, CHX002_APIC|((UINT64)D0F5_PMU_CTL << 32), D0F5_RPEROWEN, 0); 
	
	Data = AsiaIoRead16(PmioBase + PMIO_PM_STA);
	PEI_DEBUG((PeiServices, EFI_D_ERROR, "           PMIO Rx00:%04x -->\n", Data));

	return;
}
//LNA-2016122701-E


/**
   This Function PCIE GEN-2 DeEmphasis setting.

  @param  PeiServices	EFI_PEI_SERVICES pointer.
  @param  pNbConfig  point to ASIA_NB_CONFIGURATION
  @param PciAddress target pci device's address

  @return The value from this function.

**/

EFI_STATUS 
PeiNbPcieGen2DeEmphasis(
    IN EFI_PEI_SERVICES **PeiServices,
        IN ASIA_NB_CONFIGURATION *NbConfig,
        IN UINT64 PciAddress)
{
	UINT64 PcieBase;
	PcieBase = NbConfig->PcieBar;

	// JIH - 2016112301 Selectable De-emphasis -6dB and -3.5dB before LTSSM check for SW reset;
	if(NbConfig->SelectableDeEmphasis != Gen2_DeEmphasis_SItable){
		AsiaPcieModify8(PcieBase, CHX002_APIC|((UINT64)D0F5_PMU_CTL << 32), D0F5_RPEROWEN, D0F5_RPEROWEN);
		
		if(NbConfig->SelectableDeEmphasis == Gen2_DeEmphasis_Force3p5)
			AsiaPcieModify8(PcieBase, PciAddress|((UINT64)D3D5F1_LINK_CTL_2_D4F0 << 32), D3D5F1_SELDEEMPHS, D3D5F1_SELDEEMPHS);
		else
			AsiaPcieModify8(PcieBase, PciAddress|((UINT64)D3D5F1_LINK_CTL_2_D4F0 << 32), D3D5F1_SELDEEMPHS, 0);
		AsiaPcieModify8(PcieBase, CHX002_APIC|((UINT64)D0F5_PMU_CTL << 32), D0F5_RPEROWEN, 0x00);
	}
	
	return EFI_SUCCESS;
}


/**
   This Function do NB PCIE Init.

  @param  PeiServices	EFI_PEI_SERVICES pointer.
  @param  pNbConfig  point to ASIA_NB_CONFIGURATION

  @return The value from this function.

**/

EFI_STATUS
PeiNbPcieInit(
    IN EFI_PEI_SERVICES **PeiServices,
    IN ASIA_NB_CONFIGURATION *NbConfig
)
{
    UINT64 PcieBase;
    UINT64 PcieEPHYBase;
    UINT64 RCRBhAddr;
    UINT64 Addr;    
	UINT16 PortExistFlag= 0;
#ifdef ZX_DUALSOCKET	
    UINT8 SiSetFlag = 0;
#endif
    //;PcieBase Assignment
    //;PCIE BAR default to 0xE0000000 in CHX001 Project
    //;Might be re-assigned to D0F5_Rx261[7:0] (D0F5_CFG_CYCLE_CTL_2) if you want to change the Base        
    PcieBase = NbConfig->PcieBar;    //0xE0000000
    
    //DSZ_20180720 For each PCIE device, Function 0 must exist.
    if (NbConfig->PciePE1 || NbConfig->PciePE2 || NbConfig->PciePE3)
		    NbConfig->PciePE0 = TRUE;
	  if (NbConfig->PciePE5)
		    NbConfig->PciePE4 = TRUE;
    if (NbConfig->PciePE7)
		    NbConfig->PciePE6 = TRUE;

	AsiaPcieWrite16(PcieBase,CHX002_SCRCH|((UINT64)(D0F6_BIOS_SCRATCH_REG_7+2) << 32),0);
	PortExistFlag |= ((NbConfig->PciePE0)?BIT0:0);
	PortExistFlag |= ((NbConfig->PciePE1)?BIT1:0);
	PortExistFlag |= ((NbConfig->PciePE2)?BIT2:0);
	PortExistFlag |= ((NbConfig->PciePE3)?BIT3:0);
	PortExistFlag |= ((NbConfig->PciePE4)?BIT4:0);
	PortExistFlag |= ((NbConfig->PciePE5)?BIT5:0);
	PortExistFlag |= ((NbConfig->PciePE6)?BIT6:0);
	PortExistFlag |= ((NbConfig->PciePE7)?BIT7:0);
	AsiaPcieModify16(PcieBase,CHX002_SCRCH|((UINT64)(D0F6_BIOS_SCRATCH_REG_7+2) << 32),0xFF,PortExistFlag);
	PEI_DEBUG((PeiServices, EFI_D_INFO, "[PCIE] Port Exist Flag: 0x%04x\n",
				AsiaPcieRead16(PcieBase,CHX002_SCRCH|((UINT64)(D0F6_BIOS_SCRATCH_REG_7+2) << 32)) ));

	PEI_DEBUG((PeiServices, EFI_D_INFO, "[CJW_2018] ---(1)\n"));

	//CJW_20170605  EPHY CFGDONE = 1
	// If we need to set EPHY MPLL related register in D0F0, must to set them before CFGDONE = 1b
	AsiaPcieModify32(PcieBase, CHX002_GFXAX|((UINT64)D0F0_EPHY_CTL << 32), BIT31, BIT31); 

	PEI_DEBUG((PeiServices, EFI_D_INFO, "[CJW_2018] ---(2)\n"));
	//wait 100us
	PeiNbPcieStall(PeiServices, 1);  //1ms

	PEI_DEBUG((PeiServices, EFI_D_INFO, "[CJW_2018] ---(3)\n"));

	
    //set RCRB-H address
    RCRBhAddr = NbConfig->RcrbhBar;
    Addr = AsiaPciAddress(CHX002_HB_BUS,CHX002_HB_DEV,CHX002_APIC_FUN,D0F5_RCRB_H_BASE_ADR);
    AsiaPcieWrite32(PcieBase, Addr, (UINT32)(RShiftU64(RCRBhAddr, 12)) & 0x0FFFFFFF);

    //set PCIE EPHY Base address 
    PcieEPHYBase = NbConfig->PcieEPHYBar;
    Addr = AsiaPciAddress(CHX002_HB_BUS,CHX002_HB_DEV,CHX002_APIC_FUN,D0F5_PCIE_EPHY_BASE_ADR);
    AsiaPcieWrite32(PcieBase, Addr, (UINT32)(RShiftU64(PcieEPHYBase, 14 - 6)) & 0xFFFFFFC0);


    // Init PCIE related registers in D0F5 by Follow Table
	/*+ DSZ_Porting (JIH-2017081701) Remove NbPcie.c Configuration Cycle Control init setting*/
    //PROCESS_NB_R6408M_TABLE(mPCIEPeiInitTbl, sizeof(mPCIEPeiInitTbl)/sizeof(ASIA_IO_TABLE_6408_REV));
	/*- DSZ_Porting (JIH-2017081701) Remove NbPcie.c Configuration Cycle Control init setting*/

    PROCESS_NB_PCIE_R6408M_TABLE(PcieBase, mPCIEPeiMmioInitTbl, sizeof(mPCIEPeiMmioInitTbl)/sizeof(ASIA_IO_TABLE_6408_REV));


	//;fill RP Driving

#ifdef ZX_DUALSOCKET
	SiSetFlag = AsiaPcieRead8(NbConfig->PcieBar,CHX002_SCRCH|(((UINT64)D0F6_BIOS_SCRATCH_REG_8 )<< 32));
	if(BIT0 & SiSetFlag){
		AsiaPcieModify8(NbConfig->PcieBar,CHX002_SCRCH|(((UINT64)D0F6_BIOS_SCRATCH_REG_8 )<< 32),BIT0,0);
		PEI_DEBUG((PeiServices, EFI_D_INFO, "[PCIE-JNY-DEBG] SI Setting in Early VPI!! \n"));
	}else{
		SetPciePhyDriving(PeiServices,NbConfig);
		PEI_DEBUG((PeiServices, EFI_D_INFO, "[PCIE-JNY-DEBG] SI Setting in PCIE Stage!!\n"));
	}
#else
	SetPciePhyDriving(PeiServices,NbConfig);
#endif

	PeiNbSetEqualization(PeiServices,NbConfig);

	PCIeCommonSpeSetting(PeiServices,NbConfig,PCIE_CF_M);

	//
	// SERR config
	//
	if(NbConfig->SERRNBControl){
		PCIE_SERR_NB_Enable(PeiServices, NbConfig, CHX002_PE0, NbConfig->PE0ErrControl);	 //lna_err_debug	   
		PCIE_SERR_NB_Enable(PeiServices, NbConfig, CHX002_PE1, NbConfig->PE1ErrControl);	  
		PCIE_SERR_NB_Enable(PeiServices, NbConfig, CHX002_PE2, NbConfig->PE2ErrControl);		
		PCIE_SERR_NB_Enable(PeiServices, NbConfig, CHX002_PE3, NbConfig->PE3ErrControl);		
		PCIE_SERR_NB_Enable(PeiServices, NbConfig, CHX002_PE4, NbConfig->PE4ErrControl);
		PCIE_SERR_NB_Enable(PeiServices, NbConfig, CHX002_PE5, NbConfig->PE5ErrControl);
		PCIE_SERR_NB_Enable(PeiServices, NbConfig, CHX002_PE6, NbConfig->PE6ErrControl);
		PCIE_SERR_NB_Enable(PeiServices, NbConfig, CHX002_PE7, NbConfig->PE7ErrControl);
	
		PCIE_NBSERR_IntCtrl_Enable(PeiServices, NbConfig, CHX002_PE0, NbConfig->PE0ErrControl); //lna_err_debug
		PCIE_NBSERR_IntCtrl_Enable(PeiServices, NbConfig, CHX002_PE1, NbConfig->PE1ErrControl); //lna_err_debug
		PCIE_NBSERR_IntCtrl_Enable(PeiServices, NbConfig, CHX002_PE2, NbConfig->PE2ErrControl); //lna_err_debug
		PCIE_NBSERR_IntCtrl_Enable(PeiServices, NbConfig, CHX002_PE3, NbConfig->PE3ErrControl); //lna_err_debug
		PCIE_NBSERR_IntCtrl_Enable(PeiServices, NbConfig, CHX002_PE4, NbConfig->PE4ErrControl); //lna_err_debug
		PCIE_NBSERR_IntCtrl_Enable(PeiServices, NbConfig, CHX002_PE5, NbConfig->PE5ErrControl); //lna_err_debug
		PCIE_NBSERR_IntCtrl_Enable(PeiServices, NbConfig, CHX002_PE6, NbConfig->PE6ErrControl); //lna_err_debug
		PCIE_NBSERR_IntCtrl_Enable(PeiServices, NbConfig, CHX002_PE7, NbConfig->PE7ErrControl); //lna_err_debug
	}

	//
    // Set Target Link Speed to Gen1 and Linkup
    //
    if (NbConfig->PciePE0){
		// Set PE0-D3F0
	   PEI_DEBUG((PeiServices, EFI_D_INFO, "[PCIE] ------------------------------------>PE0-->stage1\n"));
	   SetPcieXLink(PeiServices, NbConfig, CHX002_PE0,INITIME_GEN1); 
	   PciePatchBeforeLinkup(PeiServices, NbConfig,CHX002_PE0);	//;ysw_debug_test
	   PCIeCommonCrsStrategy(PeiServices,NbConfig,CHX002_PE0);
	   PCIeCommonASPMEnable(PeiServices,NbConfig,CHX002_PE0); //RDT-20181113
	   PCIEOBFFCtrl(PeiServices, NbConfig, CHX002_PE0); //LNA-2016122701
	   PeiNbPcieGen2DeEmphasis(PeiServices,NbConfig,CHX002_PE0);
       LTSSMCheckForSwRst(PeiServices, NbConfig, CHX002_PE0);  //lana_debug_pcie          
    }
	
    if (NbConfig->PciePE1){
		// Set PE1-D3F1
		PEI_DEBUG((PeiServices, EFI_D_INFO, "[PCIE] ------------------------------------>PE1-->stage1\n"));
		SetPcieXLink(PeiServices, NbConfig, CHX002_PE1,INITIME_GEN1); 
		PciePatchBeforeLinkup(PeiServices, NbConfig,CHX002_PE1);	//;ysw_debug_test
		PCIeCommonCrsStrategy(PeiServices,NbConfig,CHX002_PE1);
		PCIeCommonASPMEnable(PeiServices,NbConfig,CHX002_PE1); //RDT-20181113
		PCIEOBFFCtrl(PeiServices, NbConfig, CHX002_PE1); //LNA-2016122701
		PeiNbPcieGen2DeEmphasis(PeiServices,NbConfig,CHX002_PE1);
		LTSSMCheckForSwRst(PeiServices, NbConfig, CHX002_PE1);  //lana_debug_pcie       
    }
        
    if (NbConfig->PciePE2){
       // Set PE2-D3F2
       PEI_DEBUG((PeiServices, EFI_D_INFO, "[PCIE] ------------------------------------>PE2-->stage1\n"));   
	   SetPcieXLink(PeiServices, NbConfig, CHX002_PE2,INITIME_GEN1); 
#ifdef PCISIG_PLUGFEST_WORKAROUND	 
	   //default set this port to AUTO, this avoid the PCI Compliance BIOS Test UI show Gen1 Link
	   // 	Note: our test board for CHX002 PCI_SIG is EA0, three PCIE slot can be tested: PE2, PE4, PE7
	   //		 *PE2 and PE7 defined as Gen2 X1 port
	   //		 *PE4 defined as Gen3 X8 port
	   // 		 to avoid the LED on PTC card show Gen1 X1 for those port, 
	   //		 those port need to link up as the Max Link speed as we defined, 
	   //		 so here we set the LinkSpeed to AUTO for those three ports
	   SetPcieXLink(PeiServices, NbConfig, CHX002_PE2,RUNTIME_AUTO); 
#endif	   
	   PciePatchBeforeLinkup(PeiServices, NbConfig,CHX002_PE2);	//;ysw_debug_test
	   PCIeCommonCrsStrategy(PeiServices,NbConfig,CHX002_PE2);
	   PCIeCommonASPMEnable(PeiServices,NbConfig,CHX002_PE2); //RDT-20181113
	   PCIEOBFFCtrl(PeiServices, NbConfig, CHX002_PE2); //LNA-2016122701  
	   PeiNbPcieGen2DeEmphasis(PeiServices,NbConfig,CHX002_PE2);
       LTSSMCheckForSwRst(PeiServices, NbConfig, CHX002_PE2);  //lana_debug_pcie       

    }
        
    if (NbConfig->PciePE3){
       // Set PE3-D3F3
       PEI_DEBUG((PeiServices, EFI_D_INFO, "[PCIE] ------------------------------------>PE3-->stage1\n"));
	   SetPcieXLink(PeiServices, NbConfig, CHX002_PE3,INITIME_GEN1); 
	   PciePatchBeforeLinkup(PeiServices, NbConfig,CHX002_PE3);	//;ysw_debug_test
	   PCIeCommonCrsStrategy(PeiServices,NbConfig,CHX002_PE3);
	   PCIeCommonASPMEnable(PeiServices,NbConfig,CHX002_PE3); //RDT-20181113
	   PCIEOBFFCtrl(PeiServices, NbConfig, CHX002_PE3); //LNA-2016122701
	   PeiNbPcieGen2DeEmphasis(PeiServices,NbConfig,CHX002_PE3);
       LTSSMCheckForSwRst(PeiServices, NbConfig, CHX002_PE3);  //lana_debug_pcie       
    }


    if (NbConfig->PciePE4){
       // Set PE4-D4F0
       PEI_DEBUG((PeiServices, EFI_D_INFO, "[PCIE] ------------------------------------>PE4-->stage1\n"));
	   SetPcieXLink(PeiServices, NbConfig, CHX002_PE4,INITIME_GEN1);
#ifdef PCISIG_PLUGFEST_WORKAROUND	 
	   //default set this port to Gen3, this avoid the PCI Compliance BIOS Test UI show Gen1 Link
	   // Details pls refer to PE2
	   SetPcieXLink(PeiServices, NbConfig, CHX002_PE4,RUNTIME_AUTO); 
#endif
	   PciePatchBeforeLinkup(PeiServices, NbConfig,CHX002_PE4);	//;ysw_debug_test
	   PCIeCommonCrsStrategy(PeiServices,NbConfig,CHX002_PE4);
	   PCIeCommonASPMEnable(PeiServices,NbConfig,CHX002_PE4); //RDT-20181113
	   PCIEOBFFCtrl(PeiServices, NbConfig, CHX002_PE4); //LNA-2016122701	
	   PeiNbPcieGen2DeEmphasis(PeiServices,NbConfig,CHX002_PE4);
       LTSSMCheckForSwRst(PeiServices, NbConfig, CHX002_PE4);  //lana_debug_pcie       
    }


    if (NbConfig->PciePE5){
       // Set PE5-D4F1
       PEI_DEBUG((PeiServices, EFI_D_INFO, "[PCIE] ------------------------------------>PE5-->stage1\n"));
	   SetPcieXLink(PeiServices, NbConfig, CHX002_PE5,INITIME_GEN1); 
	   PciePatchBeforeLinkup(PeiServices, NbConfig,CHX002_PE5);	//;ysw_debug_test
	   PCIeCommonCrsStrategy(PeiServices,NbConfig,CHX002_PE5);
	   PCIeCommonASPMEnable(PeiServices,NbConfig,CHX002_PE5); //RDT-20181113
	   PCIEOBFFCtrl(PeiServices, NbConfig, CHX002_PE5); //LNA-2016122701 
	   PeiNbPcieGen2DeEmphasis(PeiServices,NbConfig,CHX002_PE5);
       LTSSMCheckForSwRst(PeiServices, NbConfig, CHX002_PE5);  //lana_debug_pcie       
    }

    if (NbConfig->PciePE6){
       // Set PE6-D5F0
       PEI_DEBUG((PeiServices, EFI_D_INFO, "[PCIE] ------------------------------------>PE6-->stage1\n"));
	   PCIERoutingCtrl(PeiServices,NbConfig,CHX002_PE6);
	   SetPcieXLink(PeiServices, NbConfig, CHX002_PE6,INITIME_GEN1); 
	   PciePatchBeforeLinkup(PeiServices, NbConfig,CHX002_PE6);	//;ysw_debug_test
	   PCIeCommonCrsStrategy(PeiServices,NbConfig,CHX002_PE6);
	   PCIeCommonASPMEnable(PeiServices,NbConfig,CHX002_PE6); //RDT-20181113
	   PCIEOBFFCtrl(PeiServices, NbConfig, CHX002_PE6); //LNA-2016122701
	   PeiNbPcieGen2DeEmphasis(PeiServices,NbConfig,CHX002_PE6);
	   LTSSMCheckForSwRst(PeiServices, NbConfig, CHX002_PE6);  //lana_debug_pcie       
    }

    if (NbConfig->PciePE7){
       // Set PE7-D5F1
       PEI_DEBUG((PeiServices, EFI_D_INFO, "[PCIE] ------------------------------------>PE7-->stage1\n"));
	   PCIERoutingCtrl(PeiServices,NbConfig,CHX002_PE7);
	   SetPcieXLink(PeiServices, NbConfig, CHX002_PE7,INITIME_GEN1); 
#ifdef PCISIG_PLUGFEST_WORKAROUND	 
	   //default set this port to Gen3, this avoid the PCI Compliance BIOS Test UI show Gen1 Link
	   // Details pls refer to PE2
	   SetPcieXLink(PeiServices, NbConfig, CHX002_PE7,RUNTIME_AUTO); 
#endif	   
	   PciePatchBeforeLinkup(PeiServices, NbConfig,CHX002_PE7);	//;ysw_debug_test
	   PCIeCommonCrsStrategy(PeiServices,NbConfig,CHX002_PE7);
	   PCIeCommonASPMEnable(PeiServices,NbConfig,CHX002_PE7); //RDT-20181113
	   PCIEOBFFCtrl(PeiServices, NbConfig, CHX002_PE7); //LNA-2016122701
	   PeiNbPcieGen2DeEmphasis(PeiServices,NbConfig,CHX002_PE7);
       LTSSMCheckForSwRst(PeiServices, NbConfig, CHX002_PE7);  //lana_debug_pcie       
    }
	PEI_PCIE_NB_80_PORT(PeiServices, PEI_PCIE_RELEASE_LTSSM); 
	PEI_DEBUG((PeiServices, EFI_D_INFO, "[PCIE] ------------------------------------>END stage1\n"));

	//
    //wait 100 ms for PCIE Link Training
    //
    PeiNbPcieStall(PeiServices, 0x64);      
    PEI_DEBUG((PeiServices, EFI_D_INFO, "[PCIE] Retrain Done!\n"));

 	//
    // ==Check PCIE Status==
    //
    PeiNbCheckPcieLink(PeiServices, NbConfig);

	//
	// Check PCIE link
	//
	PEI_DEBUG((PeiServices, EFI_D_INFO, "[PCIE] Start to Check PCIE Link:\n"));
	if (NbConfig->PciePE0){
		PCIeCommonLinkStatus(PeiServices, NbConfig, CHX002_PE0);
		PCIeCommonCrsHandle(PeiServices,NbConfig,CHX002_PE0);
        PCIEDnOrderingQueueTiming(PeiServices, CHX002_HB_BUS, CHX002_PE0_3_DEV, CHX002_PE0_FUN, NbConfig, NbConfig->D3F0SPEValue );
	}
	if (NbConfig->PciePE1){
		PCIeCommonLinkStatus(PeiServices, NbConfig, CHX002_PE1);
		PCIeCommonCrsHandle(PeiServices,NbConfig,CHX002_PE1);
        PCIEDnOrderingQueueTiming(PeiServices, CHX002_HB_BUS, CHX002_PE0_3_DEV, CHX002_PE1_FUN, NbConfig, NbConfig->D3F1SPEValue);
	}
	if (NbConfig->PciePE2){
		PCIeCommonLinkStatus(PeiServices, NbConfig, CHX002_PE2);
		PCIeCommonCrsHandle(PeiServices,NbConfig,CHX002_PE2);
        PCIEDnOrderingQueueTiming(PeiServices, CHX002_HB_BUS, CHX002_PE0_3_DEV, CHX002_PE2_FUN, NbConfig, NbConfig->D3F2SPEValue);
	}
	if (NbConfig->PciePE3){
		PCIeCommonLinkStatus(PeiServices, NbConfig, CHX002_PE3);
		PCIeCommonCrsHandle(PeiServices,NbConfig,CHX002_PE3);
        PCIEDnOrderingQueueTiming(PeiServices, CHX002_HB_BUS, CHX002_PE0_3_DEV, CHX002_PE3_FUN, NbConfig, NbConfig->D3F3SPEValue);
	}
	if (NbConfig->PciePE4){
		PCIeCommonLinkStatus(PeiServices, NbConfig, CHX002_PE4);
		PCIeCommonCrsHandle(PeiServices,NbConfig,CHX002_PE4);
        PCIEDnOrderingQueueTiming(PeiServices, CHX002_HB_BUS, CHX002_PE4_5_DEV, CHX002_PE4_FUN, NbConfig, NbConfig->D4F0SPEValue);
	}
	if (NbConfig->PciePE5){
		PCIeCommonLinkStatus(PeiServices, NbConfig, CHX002_PE5);
		PCIeCommonCrsHandle(PeiServices,NbConfig,CHX002_PE5);
        PCIEDnOrderingQueueTiming(PeiServices, CHX002_HB_BUS, CHX002_PE4_5_DEV, CHX002_PE5_FUN, NbConfig, NbConfig->D4F1SPEValue);
	}
	if (NbConfig->PciePE6){
		PCIeCommonLinkStatus(PeiServices, NbConfig, CHX002_PE6);
		PCIeCommonCrsHandle(PeiServices,NbConfig,CHX002_PE6);
        PCIEDnOrderingQueueTiming(PeiServices, CHX002_HB_BUS, CHX002_PE6_7_DEV, CHX002_PE6_FUN, NbConfig, NbConfig->D5F0SPEValue);
	}
	if (NbConfig->PciePE7){
		PCIeCommonLinkStatus(PeiServices, NbConfig, CHX002_PE7);
		PCIeCommonCrsHandle(PeiServices,NbConfig,CHX002_PE7);
        PCIEDnOrderingQueueTiming(PeiServices, CHX002_HB_BUS, CHX002_PE6_7_DEV, CHX002_PE7_FUN, NbConfig, NbConfig->D5F1SPEValue);
	}


	//
    // Hot-Reset PCIE RP after TargetLinkSpeed setting
    //
    if(NbConfig->PcieHotReset){
        PEI_DEBUG((PeiServices, EFI_D_INFO, "[PCIE] HotReset!\n"));

        AsiaPciModify8(CHX002_PE0|D3D5F1_BRIDGE_CTL, D3D5F1_RSRST, D3D5F1_RSRST);
        AsiaPciModify8(CHX002_PE1|D3D5F1_BRIDGE_CTL, D3D5F1_RSRST, D3D5F1_RSRST);       
        AsiaPciModify8(CHX002_PE2|D3D5F1_BRIDGE_CTL, D3D5F1_RSRST, D3D5F1_RSRST);       
        AsiaPciModify8(CHX002_PE3|D3D5F1_BRIDGE_CTL, D3D5F1_RSRST, D3D5F1_RSRST);
        AsiaPciModify8(CHX002_PE4|D3D5F1_BRIDGE_CTL, D3D5F1_RSRST, D3D5F1_RSRST);
        AsiaPciModify8(CHX002_PE5|D3D5F1_BRIDGE_CTL, D3D5F1_RSRST, D3D5F1_RSRST);
        AsiaPciModify8(CHX002_PE6|D3D5F1_BRIDGE_CTL, D3D5F1_RSRST, D3D5F1_RSRST);
        AsiaPciModify8(CHX002_PE7|D3D5F1_BRIDGE_CTL, D3D5F1_RSRST, D3D5F1_RSRST);

        PeiNbPcieStall(PeiServices, 36);

        AsiaPciModify8(CHX002_PE0|D3D5F1_BRIDGE_CTL, D3D5F1_RSRST, 0x00);
        AsiaPciModify8(CHX002_PE1|D3D5F1_BRIDGE_CTL, D3D5F1_RSRST, 0x00);       
        AsiaPciModify8(CHX002_PE2|D3D5F1_BRIDGE_CTL, D3D5F1_RSRST, 0x00);       
        AsiaPciModify8(CHX002_PE3|D3D5F1_BRIDGE_CTL, D3D5F1_RSRST, 0x00);
        AsiaPciModify8(CHX002_PE4|D3D5F1_BRIDGE_CTL, D3D5F1_RSRST, 0x00);
        AsiaPciModify8(CHX002_PE5|D3D5F1_BRIDGE_CTL, D3D5F1_RSRST, 0x00);
        AsiaPciModify8(CHX002_PE6|D3D5F1_BRIDGE_CTL, D3D5F1_RSRST, 0x00);
        AsiaPciModify8(CHX002_PE7|D3D5F1_BRIDGE_CTL, D3D5F1_RSRST, 0x00);

        PeiNbPcieStall(PeiServices, 36);
    }


#ifdef IOE_EXIST
	PEI_PCIE_NB_80_PORT(PeiServices, PEI_PCIE_IOE_INIT); 

	PciePatchforIoeAfterLinkup(PeiServices, NbConfig);

	IoePeiNbPreInit(PeiServices, NbConfig);
	
	IoePeiNbInit(PeiServices, NbConfig);
	
	//Need an additional LinkRetrain on the RP which connected to IOE. 
	// this is because IOE can only report Gen1 supported in LTSSM_Cfg state, RP will record this 
	//	and when we change to Target Link Speed = Gen3, retrain link, the RP still think of IOE only 
	//	support Gen1.  this additional LinkRetrain will update the RP's record, and when it comes to 
	//	next LinkRetrain, the link can training to Gen3.
	// this special behavior mainly because IOE just report Gen1 support in LTSSM_Cfg when the first Linkup
	AsiaPciModify8(AsiaPciAddress(0, 
									IoeGetRpToFindIoe_GetDev(PeiServices),
									IoeGetRpToFindIoe_GetFun(PeiServices),
									D3D5F1_LINK_CTL_1),
								D3D5F1_LCRL,
								D3D5F1_LCRL);		
#endif

  
//;ysw_debug_test - start
	//
	// Set Target Link Speed to Gen3 
	//
	PEI_PCIE_NB_80_PORT(PeiServices, PEI_PCIE_BEFORE_CHANGE_MAX_SPEED); 
    if (NbConfig->PciePE0){
        // Set PE0-D3F0
        PEI_DEBUG((PeiServices, EFI_D_INFO, "[PCIE] ------------------------------------>PE0-->stage2\n"));
        SetPcieXLink(PeiServices, NbConfig, CHX002_PE0,RUNTIME_AUTO);  
		PCIeCommonLinkStatus(PeiServices, NbConfig, CHX002_PE0);
    }
	
    if (NbConfig->PciePE1){
        // Set PE1-D3F1
        PEI_DEBUG((PeiServices, EFI_D_INFO, "[PCIE] ------------------------------------>PE1-->stage2\n"));
        SetPcieXLink(PeiServices, NbConfig, CHX002_PE1,RUNTIME_AUTO); 
		PCIeCommonLinkStatus(PeiServices, NbConfig, CHX002_PE1);
    }
        
    if (NbConfig->PciePE2){
        // Set PE2-D3F2
        PEI_DEBUG((PeiServices, EFI_D_INFO, "[PCIE] ------------------------------------>PE2-->stage2\n"));		
        SetPcieXLink(PeiServices, NbConfig, CHX002_PE2,RUNTIME_AUTO);  
		PCIeCommonLinkStatus(PeiServices, NbConfig, CHX002_PE2);
    }
        
    if (NbConfig->PciePE3){
        // Set PE3-D3F3
        PEI_DEBUG((PeiServices, EFI_D_INFO, "[PCIE] ------------------------------------>PE3-->stage2\n"));
        SetPcieXLink(PeiServices, NbConfig, CHX002_PE3,RUNTIME_AUTO);
		PCIeCommonLinkStatus(PeiServices, NbConfig, CHX002_PE3);
    }
        
    if (NbConfig->PciePE4){
        // Set PE4-D4F0
        PEI_DEBUG((PeiServices, EFI_D_INFO, "[PCIE] ------------------------------------>PE4-->stage2\n"));		
        SetPcieXLink(PeiServices, NbConfig, CHX002_PE4,RUNTIME_AUTO); 
		PCIeCommonLinkStatus(PeiServices, NbConfig, CHX002_PE4);
    }

    if (NbConfig->PciePE5){
        // Set PE5-D4F1
        PEI_DEBUG((PeiServices, EFI_D_INFO, "[PCIE] ------------------------------------>PE5-->stage2\n"));
        SetPcieXLink(PeiServices, NbConfig, CHX002_PE5,RUNTIME_AUTO);  
		PCIeCommonLinkStatus(PeiServices, NbConfig, CHX002_PE5);
    }

    if (NbConfig->PciePE6){
        // Set PE6-D5F0
        PEI_DEBUG((PeiServices, EFI_D_INFO, "[PCIE] ------------------------------------>PE6-->stage2\n"));
        SetPcieXLink(PeiServices, NbConfig, CHX002_PE6,RUNTIME_AUTO); 
		PCIeCommonLinkStatus(PeiServices, NbConfig, CHX002_PE6);
    }
        
    if (NbConfig->PciePE7){
        // Set PE7-D5F1
        PEI_DEBUG((PeiServices, EFI_D_INFO, "[PCIE] ------------------------------------>PE7-->stage2\n"));	
		SetPcieXLink(PeiServices, NbConfig, CHX002_PE7, RUNTIME_AUTO);
		PCIeCommonLinkStatus(PeiServices, NbConfig, CHX002_PE7);
    }
	PEI_DEBUG((PeiServices, EFI_D_INFO, "[PCIE] ------------------------------------>END stage2\n"));
//;ysw_debug_test - end

	

	//jennychen add for PCIE hot plug-s
#if defined(PCAL6416A_PCIE_HOTPLUG_SUPPORT_CHX002) || defined(PCAL6416A_PCIE_HOTPLUG_SUPPORT_IOE)
    PcieHotPlugInit(PeiServices);
	PEI_DEBUG((PeiServices,EFI_D_INFO, "[JNY-HP] hotplug modify 180802\n"));
#endif 
	//jennychen add for PCIE hot plug-e


	PEI_PCIE_NB_80_PORT(PeiServices, PEI_PCIE_END);  //JennyChen add for Chx002 80 Port
    return      EFI_SUCCESS;

}




/*
//;cjw_debug_pcie
We need to cancel this function gradually
Some function still use it now
So keep it temporary
*/
/*
//CJW_20170510 removed
VOID 
ClearTempBusNo(
IN EFI_PEI_SERVICES       **PeiServices,
IN UINT8                  Bus
)
{
        UINT8   MyBus, MyDev;
        UINT8   MyFun;

        MyBus = 0;
        MyDev = 0;
        MyFun = 0;

        if (Bus != 0)
        {
                for (MyBus  = 0;MyBus <= Bus;MyBus++)
                {
                        for (MyDev = 0; MyDev < 32; MyDev++)
                        {
                                for (MyFun = 0; MyFun < 8; MyFun++)
                                {

//;ysw_debug                                   if(MyBus == 0 && MyDev != 3 && MyDev != 4 ) // for PE0 and PE1
//;ysw_debug                                            continue;

                                        if(AsiaPciRead32(AsiaPciAddress(MyBus, MyDev, MyFun, 0)) == 0xFFFFFFFF)
                                                break;
                                        AsiaPciWrite16(AsiaPciAddress(MyBus, MyDev, MyFun, 0x19), 0);
                                }
                        }
                }
        }
}
//lana_debug_pcie-start
*/

