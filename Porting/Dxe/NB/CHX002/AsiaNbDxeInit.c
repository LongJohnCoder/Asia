/** @file
   ZX-E(CHX002) Asia NbDxe library functions : AsiaNbDxeInit.c

   Copyright (c) 2018 Shanghai Zhaoxin Semiconductor Co., Ltd. 

**/

//**********************************************************************
//**********************************************************************
//**                                                                  **
//**     Copyright (c) 2015 Shanghai Zhaoxin Semiconductor Co., Ltd.  **
//**                                                                  **
//**********************************************************************
//**********************************************************************

#include "EfiCommon.h"
#include EFI_PROTOCOL_DEFINITION(AsiaCpuProtocol)
#include EFI_PROTOCOL_DEFINITION(PciHostBridgeResourceAllocation)
#include EFI_PROTOCOL_DEFINITION(PciIo)
#include EFI_PROTOCOL_DEFINITION(AsiaSbProtocol)
#include "AsiaNbDxe.h"
#include "AsiaIoSaveLib.h"
#include "CHX002Cfg.h"
#include "CHX002Reg.h"
#include "EfiDriverLib.h"
#include EFI_GUID_DEFINITION(Hob)
#include "NbDxePcie.h"
#include "EfiHobLib.h"
#include "EfiScriptLib.h"
#include "AsiaCommon.h" 

#include "DramInit.h"
#include "VirtualSPD.h"

#include "NbDxePcie.h"
#include "NbDxePciePrePci.h"
#ifdef ZX_DUALSOCKET
#include "NbDxePciePrePciSlave.h"
#include "NbDxePciePrePciSlave.c"
#endif
#ifdef IOE_EXIST
#include "..\..\SB\CND003\IoeDxeInit.h"
#endif
#ifdef ZX_TXT_SUPPORT
#include "AsiaVariable.h"
#define TXT_PUBLIC_CONFIG_REGS_BASE 0xFED30000
#endif

//static ASIA_NB_CONFIGURATION gDefaultNbCfg = ASIA_NB_DEFAULT_CONFIGURATION;
/**
  Function description.
  
  @param  PeiServices	EFI_PEI_SERVICES pointer.
  @param NbCfg Point to ASIA_NB_CONFIGURATION struct.

  @return EFI_STATUS.

**/

EFI_STATUS GetAsiaNbCfgFromHob(
    OUT VOID** NbCfg
)
{
    EFI_STATUS Status;
    EFI_HOB_GENERIC_HEADER *HobList;
    EFI_GUID EfiHobListGuid = EFI_HOB_LIST_GUID;
    EFI_GUID NbCfgHobGuid = ASIA_NB_CFG_HOB_GUID;
    VOID* pNbCfg = NULL;

    Status = EfiLibGetSystemConfigurationTable(&EfiHobListGuid, &HobList);
    if(!EFI_ERROR(Status))
        Status = GetNextGuidHob(&HobList, &NbCfgHobGuid, &pNbCfg, NULL);

    if(EFI_ERROR(Status)) {
	DEBUG((EFI_D_ERROR, "\n\n ASIA_NB_CFG HOB lost, Bug! Bug! Bug!\n\n"));	
	ASSERT(!EFI_ERROR(Status)); // should not come here. TGR-20180509001	
        //gBS->AllocatePool(EfiBootServicesData, sizeof(ASIA_NB_CONFIGURATION), &pNbCfg);
        //gBS->CopyMem(pNbCfg, &gDefaultNbCfg, sizeof(ASIA_NB_CONFIGURATION));
    }

    *NbCfg = pNbCfg;
    return EFI_SUCCESS;
}

STATIC ASIA_IO_TABLE_6408_REV C5DisableBeforePCI[] = {
    0x00, 0xFF, CHX002_NPMC|D0F4_NEW_PMU_FUN_CTL,               0x80, 0x00,       //;D0F4_Rx96[7]=0
    0xFF, 0x00, 0x00,                       0x00, 0x00
};
STATIC ASIA_IO_TABLE_6408_REV C5EnableBeforePCI[] = {
    0xFF, 0x00,  0x00,                      0x00, 0x00
};


STATIC ASIA_IO_TABLE_6408_REV NBSafeTBL[]= {

    //  mVer MVer   Reg Offset                  Mask    Value

    ///////////////////////D0F0///////////////////////
    
    ///////////////////////D0F1///////////////////////
    
    ///////////////////////D0F2///////////////////////

    ///////////////////////D0F3///////////////////////
    
    ///////////////////////D0F4///////////////////////

    ///////////////////////D0F5///////////////////////

    ///////////////////////D0F7///////////////////////

    ///////////////////////D2F0///////////////////////

    ///////////////////////D3F0 ///////////////////////

    ///////////////////////D4F0 ///////////////////////

    ///////////////////////D5F0 ///////////////////////

    ///////////////////////D6F0 ///////////////////////


    0xFF, 0x00,  0x00,                      0x00,  0x00
};

STATIC ASIA_IO_TABLE_6408_REV NBSafeMMIOTBL[]= {
    //Device 2 Function 0 ;

    //Device 3 Function 0 ;

    //Device 4 Function 0 ;

    //Device 5 Function 0 ;

    //Device 6 Function 0 ;

    0xFF, 0x00,  0x00,                                          0x00,  0x00
};

STATIC ASIA_IO_TABLE_6408_REV D0F0PerformanceTBL[]= {
    //  mVer MVer   Reg Offset                  Mask    Value
    0xFF, 0x00,  0x00,                                0x00,  0x00
};

STATIC ASIA_IO_TABLE_6408_REV D0F1PerformanceTBL[]= {
    //  mVer MVer   Reg Offset                  Mask    Value
    0xFF, 0x00,  0x00,                                0x00,  0x00
};

STATIC ASIA_IO_TABLE_6432_REV D0F3_PerformanceTBL[]={
	{0x00,	0xFF,	(CHX002_DRAM|(UINT64)0x160 << 32),	0xf00,	0xd00},

	{0x00,	0xFF,	(CHX002_DRAM|(UINT64)0x164 << 32),	0x48400000,	0x08400000},

	{0x00,	0xFF,	(CHX002_DRAM|(UINT64)0x16c << 32),	0x7f0000,	0x40000},

	{0x00,	0xFF,	(CHX002_DRAM|(UINT64)0x170 << 32),	0x0900,	0x0900},

	{0x00,	0xFF,	(CHX002_DRAM|(UINT64)0x174 << 32),	0xff000000,	0xff000000},

	{0x00,	0xFF,	(CHX002_DRAM|(UINT64)0x178 << 32),	0xff00,	0xff00},

	{0x00,	0xFF,	(CHX002_DRAM|(UINT64)0x17c << 32),	0xff,	0xff},

	{0x00,	0xFF,	(CHX002_DRAM|(UINT64)0x1cc << 32),	0x1000,	0x1000},

	{0x00,	0xFF,	(CHX002_DRAM|(UINT64)0x1d8 << 32),	0xfdef0000,	0xfdef0000},

	{0x00,	0xFF,	(CHX002_DRAM|(UINT64)0x400 << 32),	0xc04040,	0xc04040},

	{0x00,	0xFF,	(CHX002_DRAM|(UINT64)0x404 << 32),	0xc0c000c0,	0xc0c000c0},

	{0x00,	0xFF,	(CHX002_DRAM|(UINT64)0x408 << 32),	0xc000,	0xc000},

	{0x00,	0xFF,	(CHX002_DRAM|(UINT64)0xbdc << 32),	0x40000,	0x40000},

	{0x00,	0xFF,	(CHX002_DRAM|(UINT64)0xcc4 << 32),	0x30000,	0x30000},

	{0xFF,	0x00,	0x00,	0x00,	0x00} 
};

STATIC ASIA_IO_TABLE_6408_REV D0F4PerformanceTBL[]= {
    ///////////////////////D0F4///////////////////////NB_Performance_TBL
    //  mVer MVer   Reg Offset                  Mask    Value
    0x00, 0xFF, CHX002_NPMC|(UINT64)D0F4_PM_MODE << 32,                     0x80, 0x80,        //Rx60[7]
    0x00, 0xFF, CHX002_NPMC|(UINT64)D0F4_DYNAMIC_CLK_STOP_CTL << 32,        0x01, 0x01,        //Rx61[0]
    0x00, 0xFF, CHX002_NPMC|(UINT64)D0F4_DRAMC_PM_REG_1 << 32,              0x60, 0x60,        //Rx71[6:5]
    0x00, 0xFF, CHX002_NPMC|(UINT64)D0F4_DRAMC_PM_REG_2 << 32,              0xFF, 0xFF,        //Rx72[7:0]
    0x00, 0xFF, CHX002_NPMC|(UINT64)D0F4_DRAMC_PM_REG_3 << 32,              0x9F, 0x9F,        //Rx73[7,4:0]
    0x00, 0xFF, CHX002_NPMC|(UINT64)D0F4_RAIDA_DYNAMIC_CLK_CTL << 32,       0x03, 0x03,        //Rx74[1,0]
    0x00, 0xFF, CHX002_NPMC|(UINT64)D0F4_GMINT_DYNAMIC_CLK_CTL << 32,		  0x0F, 0x0F,        //Rx76[3:0]
    0x00, 0xFF, CHX002_NPMC|(UINT64)D0F4_GMINT_DYNAMIC_CLK_CTL_Z1 << 32,    0xF0, 0xF0,        //Rx77[7:4]
    0x00, 0xFF, CHX002_NPMC|(UINT64)D0F4_PXPTRF_DYNAMIC_CLK_1 << 32,        0xFF, 0xFF,        //Rx78[7:0]
    0x00, 0xFF, CHX002_NPMC|(UINT64)D0F4_PXPTRF_DYNAMIC_CLK_2 << 32,        0xFF, 0xFF,        //Rx79[7:0]
    0x00, 0xFF, CHX002_NPMC|(UINT64)D0F4_PXPTRF_DYNAMIC_CLK_3 << 32,        0xFF, 0xFF,        //Rx7A[7-0]
    0x00, 0xFF, CHX002_NPMC|(UINT64)D0F4_TACTL_DYNAMIC_CLK << 32,   		  0x3F, 0x3F,        //Rx7B[5:0]
    0x00, 0xFF, CHX002_NPMC|(UINT64)D0F4_APICX_DYNAMIC_CLK << 32,           0xE0, 0xE0,        //Rx7C[7,6,5]
    0x00, 0xFF, CHX002_NPMC|(UINT64)D0F4_VKCFG_IF_PM << 32,                 0x80, 0x80,        //Rx7D[7]
    0x00, 0xFF, CHX002_NPMC|(UINT64)D0F4_PXPTRF_DYNAMIC_CLK_4 << 32,         0x07, 0x07,        //Rx7E[2-0]
    0x00, 0xFF, CHX002_NPMC|(UINT64)D0F4_CPUIF_PM << 32,					  0xFF, 0xFF,        //Rx80[7-0]
    0x00, 0xFF, CHX002_NPMC|(UINT64)(D0F4_CPUIF_PM + 1) << 32,				  0xFF, 0xFF,        //Rx81[7-0]
    0x00, 0xFF, CHX002_NPMC|(UINT64)(D0F4_CPUIF_PM + 3) << 32,				  0x80, 0x80,        //Rx83[7]
  //  0x00, 0xFF, CHX002_NPMC|(UINT64)D0F4_PWR_GATING_CTL_0 << 32,			  0x0F, 0x0F,      //Rx98[3:0]
    0xFF, 0x00,  0x00,                      0x00,  0x00

};



STATIC ASIA_IO_TABLE_6408_REV D0F5PerformanceTBL[]= {
    ///////////////////////D0F5///////////////////////NB_Performance_TBL

    //  mVer MVer   Reg Offset                  Mask    Value
    //Willy: Remove D0F5_RMIDQBYPASS porting temporary to avoid hang 99/9A issue 
    0x00, 0xFF, CHX002_APIC|(UINT64)D0F5_TRAFFIC_FLOW_CTL_UPSTREAM_CTL_UPSIDE_NEAR_CPUIF_1 << 32,     D0F5_RTPQ1T, D0F5_RTPQ1T,  //Rx80[3]
    //Jerry: Remove D0F5_RMIDQBYPASS to avoid abnormal work of APIC when IOV is enabled in P mode. 
    0x00, 0xFF, CHX002_APIC|(UINT64)D0F5_TRAFFIC_FLOW_CTL_UPSTREAM_CTL_UPSIDE_NEAR_CPUIF_2 << 32,     D0F5_RPERPSH1T, D0F5_RPERPSH1T,  //Rx81[2]
    0x00, 0xFF, CHX002_APIC|(UINT64)D0F5_UPSTREAM_MIDQ_DYNAMIC_CLK_CTL << 32,     0xfd, 0xfd,  //Rx82[7:2,0]
    0x00, 0xFF, CHX002_APIC|(UINT64)D0F5_TA_HIGH_PRIORITY_SET << 32,     D0F5_RPEXTQUECLKSEL|D0F5_RMSIDTRKCLKSEL, D0F5_RPEXTQUECLKSEL|D0F5_RMSIDTRKCLKSEL,  //Rx83[2:1]
    0x00, 0xFF, CHX002_APIC|(UINT64)D0F5_TRAFFIC_FLOW_CTL_UPSTREAM_CTL_DOWNSIDE_NEAR_GFX << 32,       D0F5_RUSBYPASS|D0F5_RUS2QWMERGE, D0F5_RUSBYPASS|D0F5_RUS2QWMERGE,  //Rx86[1:0]
    0x00, 0xFF, CHX002_APIC|(UINT64)D0F5_TRAFFIC_FLOW_CTL_DOWNSTREAM_CTL_DOWNSIDE_NEAR_PCIE << 32,    D0F5_RPEV1RDY1TE|D0F5_RPEQ1T, D0F5_RPEV1RDY1TE|D0F5_RPEQ1T,  //Rx88[6,3]
    0x00, 0xFF, CHX002_APIC|(UINT64)D0F5_RAID0_RELATED << 32,  D0F5_RRAID0MIDQDYN, D0F5_RRAID0MIDQDYN,  //Rx144[1]
    0x00, 0xFF, CHX002_APIC|(UINT64)D0F5_RAID1_RELATED << 32,  D0F5_RRAID1MIDQDYN, D0F5_RRAID1MIDQDYN,  //Rx146[1]
    0x00, 0xFF, CHX002_APIC|(UINT64)D0F5_DYNAMIC_CLK_OF_DBX_DOWNSTREAM_WRITE_FIFO << 32,  0x9f, 0x9f,  //Rx14B[7,4:0]
    0x00, 0xFF, CHX002_APIC|(UINT64)D0F5_DYNAMIC_CLK_OF_DBX_DOWNSTREAM_WRITE_FIFO_PART_2<<32, D0F5_RDYN_WCLK_EN_AHCI|D0F5_RDYN_WCLK_EN_XHCI, D0F5_RDYN_WCLK_EN_AHCI|D0F5_RDYN_WCLK_EN_XHCI, //Rx152[1:0] 
    0x00, 0xFF, CHX002_APIC|(UINT64)D0F5_PXPTRF_RELATED_REG << 32,  D0F5_RTDADS1TE_PE|D0F5_RDNRFIFO_1T, D0F5_RTDADS1TE_PE,  //Rx266[2:1]
    0x00, 0xFF, CHX002_APIC|(UINT64)D0F5_TRAFFIC_FLOW_CTL_DOWNSTREAM_CTL_DOWNSIDE_NEAR_PCIE_1 << 32,  D0F5_RTDNIWRDY1T, D0F5_RTDNIWRDY1T,  //Rx274[5]
    0x00, 0xFF, CHX002_APIC|(UINT64)D0F5_REG_FOR_PXPTRF_1 << 32,  D0F5_RVPIMIDQDYN, D0F5_RVPIMIDQDYN,  //Rx281[0]
    0xFF, 0x00,  0x00,                  0x00,  0x00
};

STATIC ASIA_IO_TABLE_6408_REV D0F6PerformanceTBL[]= {
    //  mVer MVer   Reg Offset                  Mask    Value
    0xFF, 0x00,  0x00,                  0x00,  0x00
};

STATIC ASIA_IO_TABLE_6408_REV D0F7PerformanceTBL[]= {
    //  mVer MVer   Reg Offset                  Mask    Value
    0xFF, 0x00,  0x00,                  0x00,  0x00
};

STATIC ASIA_IO_TABLE_6408_REV D1F0PerformanceTBL[]= {
    0xFF, 0x00,  0x00,                  0x00,  0x00
};

/*+ DSZ_Porting (ALN-2017081701) Set to E mode before root port release link.*/ 
STATIC ASIA_IO_TABLE_6408_REV D8F0PerformanceTBL[]= {
    //  mVer MVer   Reg Offset                  Mask    Value
    0xFF, 0x00,  0x00,                  0x00,  0x00
};

STATIC ASIA_IO_TABLE_6408_REV D9F0PerformanceTBL[]= {
    //  mVer MVer   Reg Offset                  Mask    Value
    0xFF, 0x00,  0x00,                  0x00,  0x00
};


/*- DSZ_Porting (ALN-2017081701) Set to E mode before root port release link.*/
STATIC ASIA_IO_TABLE_6408_REV D0F0EnergyTBL[]= {
    //  mVer MVer   Reg Offset                  Mask    Value
    0xFF, 0x00,  0x00,                      0x00,  0x00
};

STATIC ASIA_IO_TABLE_6408_REV D0F1EnergyTBL[]= {
    //  mVer MVer   Reg Offset                  Mask    Value
    0xFF, 0x00,  0x00,                      0x00,  0x00
};


STATIC ASIA_IO_TABLE_6432_REV D0F3_EnergyTBL[]={
	{0x00,	0xFF,	(CHX002_DRAM|(UINT64)0x50 << 32),	0x3,	0x3},

	{0x00,	0xFF,	(CHX002_DRAM|(UINT64)0x164 << 32),	0x80000,	0x0},

	//{0x00,	0xFF,	(CHX002_DRAM|(UINT64)0x16c << 32),	0x4000000,	0x4000000},

	{0x00,	0xFF,	(CHX002_DRAM|(UINT64)0x174 << 32),	0xff000000,	0x0},

	{0x00,	0xFF,	(CHX002_DRAM|(UINT64)0x17c << 32),	0xff,	0x0},

	{0x00,	0xFF,	(CHX002_DRAM|(UINT64)0x170 << 32),	0x0900,	0x0900},

	{0xFF,	0x00,	0x00,	0x00,	0x00} 
};

STATIC ASIA_IO_TABLE_6408_REV D0F4EnergyTBL[]= {
    //  mVer MVer   Reg Offset                                Mask    Value
   // 0x00, 0xFF, CHX002_NPMC|(UINT64)D0F4_PXPTRF_DYNAMIC_CLK_1 << 32,        0x02, 0x02,        //Rx78[1]
   // 0x00, 0xFF, CHX002_NPMC|(UINT64)D0F4_C3_PMU_CTL << 32,                  0x10, 0x10,        //Rx93[4]
   // 0x00, 0xFF, CHX002_NPMC|(UINT64)D0F4_NEW_PMU_FEATURES << 32,				0x70, 0x70, 	   //Rx94[6,5,4] E:1 P:0
    0x00, 0xFF, CHX002_NPMC|(UINT64)D0F4_NEW_PMU_FUN_CTL << 32,                 0x64, 0x64,        //Rx96[6,5,2]
  //  0x00, 0xFF, CHX002_NPMC|(UINT64)D0F4_NEW_PMU_FUN_CTL_Z1 << 32,              0xC0, 0xC0,        //Rx97[7,6]
    0x00, 0xFF, CHX002_NPMC|(UINT64)D0F4_NEW_PMU_FUNC_VPI << 32,			   0x64, 0x64,      //Rx9A[6,5,2]
    0x00, 0xFF, CHX002_NPMC|(UINT64)D0F4_NEW_PMU_FUNC_PCIEPHY_X14_PLL << 32,   0x0A, 0x0A,      //Rx9B[3,1]
    0xFF, 0x00,  0x00,						0x00,  0x00

};


STATIC ASIA_IO_TABLE_6408_REV D0F5EnergyTBL[]= {
    //  mVer MVer   Reg Offset                  Mask    Value
    0x00, 0xFF,  CHX002_APIC|(UINT64)D0F5_LINK_CTL_1 << 32,   D0F5_LCAPMS, D0F5_LCAPMS,        //Rx50[1-0]
    //0x00, 0xFF,  CHX002_APIC|(UINT64)D0F5_UPSTREAM_MIDQ_DYNAMIC_CLK_CTL << 32, 0xFF , 0xFF,    //Rx82[7-0]
    //0x00, 0xFF,  CHX002_APIC|(UINT64)D0F5_TA_HIGH_PRIORITY_SET << 32, D0F5_RPEXTQUECLKSEL|D0F5_RMSIDTRKCLKSEL , D0F5_RPEXTQUECLKSEL|D0F5_RMSIDTRKCLKSEL,    //Rx83[2-1]
    //0x00, 0xFF,  CHX002_APIC|(UINT64)D0F5_RAID0_RELATED << 32, D0F5_RRAID0MIDQDYN , D0F5_RRAID0MIDQDYN,    //Rx144[1]
    //0x00, 0xFF,  CHX002_APIC|(UINT64)D0F5_RAID1_RELATED << 32, D0F5_RRAID0MIDQDYN , D0F5_RRAID0MIDQDYN,    //Rx146[1]
    //0x00, 0xFF,  CHX002_APIC|(UINT64)D0F5_DYNAMIC_CLK_OF_DBX_DOWNSTREAM_WRITE_FIFO << 32, 0x9F ,0x9F ,    //Rx14B[7, 5-0]
    //0x00, 0xFF,  CHX002_APIC|(UINT64)D0F5_TERFF_CLK_SEL_INTERNAL_BLOCK_CTL << 32, 0x9F ,0x9F ,    //Rx14B[7, 5-0]
    0xFF, 0x00,  0x00,                      0x00,  0x00
};

STATIC ASIA_IO_TABLE_6408_REV D0F6EnergyTBL[]= {
    //  mVer MVer   Reg Offset                  Mask    Value
    0xFF, 0x00,  0x00,                      0x00,  0x00
};

STATIC ASIA_IO_TABLE_6408_REV D0F7EnergyTBL[]= {
    //  mVer MVer   Reg Offset                  Mask    Value
    0xFF, 0x00,  0x00,                      0x00,  0x00
};

STATIC ASIA_IO_TABLE_6408_REV D1F0EnergyTBL[]= {
    0xFF, 0x00,  0x00,                      0x00,  0x00
};

 
 /*+ DSZ_Porting (ALN-2017081701) Set to E mode before root port release link.*/ 
 STATIC ASIA_IO_TABLE_6408_REV D8F0EnergyTBL[]= {
	 //  mVer MVer	 Reg Offset 					  Mask	Value
	 //0x00, 0xFF, CHX002_RAIDA0|D8F0_RAIDA_CTL_REGS,	0x02, 0x02, 	   //Rx40[1]
	 0xFF, 0x00,  0x00, 					  0x00,  0x00
 };
 
 STATIC ASIA_IO_TABLE_6408_REV D9F0EnergyTBL[]= {
	 //  mVer MVer	 Reg Offset 					 Mask	Value
	 //0x00, 0xFF, CHX002_RAIDA1|D9F0_RAIDA_CTL_REGS,  0x02,  0x02, 	   //Rx40[1]
	 0xFF, 0x00,  0x00, 					  0x00,  0x00
 };
/*- DSZ_Porting (ALN-2017081701) Set to E mode before root port release link.*/ 
		
ASIA_VID_DID_RID_LOCK NbVidDidLockTbl[]=
{
	{CHX002_HB_DEV,	CHX002_GFXAX_FUN,	D0F0_MULT_FUN_CTL,	D0F0_MULT_FUN_CTL,	D0F0_D0F0_RX83B2,	D0F0_D0F0_RX83B1},
	{CHX002_HB_DEV,	CHX002_ERRC_FUN,	D0F1_VID_Z1,		D0F1_VID_Z1,		D0F1_D0F1_RX40B1,	D0F1_D0F1_RX40B0},
	{CHX002_HB_DEV,	CHX002_HIF_FUN,		D0F2_MMIOCFG_DECODER + 3,	D0F2_MMIOCFG_DECODER + 3, BIT5, BIT7},
	{CHX002_HB_DEV,	CHX002_DRAM_FUN,	D0F3_RID_DID_RVENDOR_LOCK_BIT,		D0F3_RID_DID_RVENDOR_LOCK_BIT, 	D0F3_D0F3_RX39CB3, 	D0F3_D0F3_RX39CB2},
	{CHX002_HB_DEV,	CHX002_NPMC_FUN,	D0F4_PLL_TEST_MODE_0,	D0F4_PLL_TEST_MODE_0,	D0F4_D0F4_RX40B1,	D0F4_D0F4_RX40B0},
	{CHX002_HB_DEV,	CHX002_APIC_FUN,	D0F5_CFG_CYCLE_CTL_1,	D0F5_TRAFFIC_FLOW_CTL_UPSTREAM_CTL_DOWNSIDE_NEAR_GFX,	D0F5_D0F5_RX260B2,	D0F5_RX86_2},
	{CHX002_HB_DEV,	CHX002_SCRCH_FUN,	D0F6_NM_PWR_STATE,	D0F6_NM_PWR_STATE,	D0F6_D0F6_RXE8B4,	D0F6_D0F6_RXE8B3},
	//{CHX002_EUMA_DEV,CHX002_EUMA_FUN},
	//{CHX002_EUMA_DEV,CHX002_S3AC_FUN},
//	{CHX002_PEG_DEV,	CHX002_PEG_FUN,		D3D5F1_VEN_CTL_D2F0,	D3D5F1_RESERVED_Z17, D3D5F1_D2F0_VID_DID_LOCK_BIT,	D3D5F1_DID_RID_LOCK_BIT},

   //DSZ-20180807, Add VID/DID lock for CHX002 PCIE RPs
	{CHX002_PE0_3_DEV,	CHX002_PE0_FUN,		D3D5F1_VENDOR_CTL,	D3D5F1_RESERVED_Z37, D3D5F1_D5F1_VID_DID_LOCK_BIT,	D3D5F1_C},
	{CHX002_PE0_3_DEV,	CHX002_PE1_FUN,		D3D5F1_VENDOR_CTL,	D3D5F1_RESERVED_Z37, D3D5F1_D5F1_VID_DID_LOCK_BIT,	D3D5F1_C},
	{CHX002_PE0_3_DEV,	CHX002_PE2_FUN,		D3D5F1_VENDOR_CTL,	D3D5F1_RESERVED_Z37, D3D5F1_D5F1_VID_DID_LOCK_BIT,	D3D5F1_C},
	{CHX002_PE0_3_DEV,	CHX002_PE3_FUN,		D3D5F1_VENDOR_CTL,	D3D5F1_RESERVED_Z37, D3D5F1_D5F1_VID_DID_LOCK_BIT,	D3D5F1_C},
	{CHX002_PE4_5_DEV,	CHX002_PE4_FUN,	    D3D5F1_VENDOR_CTL,	D3D5F1_RESERVED_Z37, D3D5F1_D5F1_VID_DID_LOCK_BIT,	D3D5F1_C},
	{CHX002_PE4_5_DEV,	CHX002_PE5_FUN,	    D3D5F1_VENDOR_CTL,	D3D5F1_RESERVED_Z37, D3D5F1_D5F1_VID_DID_LOCK_BIT,	D3D5F1_C},
	{CHX002_PE6_7_DEV,	CHX002_PE6_FUN,	    D3D5F1_VENDOR_CTL,	D3D5F1_RESERVED_Z37, D3D5F1_D5F1_VID_DID_LOCK_BIT,	D3D5F1_C},
	{CHX002_PE6_7_DEV,	CHX002_PE7_FUN,	    D3D5F1_VENDOR_CTL,	D3D5F1_RESERVED_Z37, D3D5F1_D5F1_VID_DID_LOCK_BIT,	D3D5F1_C},
  //JYZ-20180807, Add VID/DID lock for CHX002 RAIDA0/RAIDA1
	{CHX002_RAIDA0_DEV,	CHX002_RAIDA0_FUN,	D8F0_RAIDA_CTL_REGS + 1,	D8F0_RAIDA_CTL_REGS + 1,	BIT7,	BIT6},
	{CHX002_RAIDA1_DEV,	CHX002_RAIDA1_FUN,	D9F0_RAIDA_CTL_REGS + 1,	D9F0_RAIDA_CTL_REGS + 1,	BIT7,	BIT6}

};

STATIC ASIA_IO_TABLE_6408_REV NbClassCodeLockTbl[]= {
    0x00, 0xFF,  CHX002_GFXAX|(UINT64)D0F0_MULT_FUN_CTL << 32,   D0F0_D0F0_RX83B3, D0F0_D0F0_RX83B3,        //Rx83[3]
    0x00, 0xFF,  CHX002_ERRC|(UINT64)D0F1_VID_Z1 << 32,   D0F1_D0F1_RX40B2, D0F1_D0F1_RX40B2,        //Rx40[2]
    0x00, 0xFF,  CHX002_HIF|(UINT64)(D0F2_MMIOCFG_DECODER+3) << 32,   BIT3, BIT3,        //Rx40[27]
    0x00, 0xFF,  CHX002_DRAM|(UINT64)D0F3_RID_DID_RVENDOR_LOCK_BIT << 32,   D0F3_RCLASS_CODE_LOCK_D0F3, D0F3_RCLASS_CODE_LOCK_D0F3, //Rx39C[0]
    0x00, 0xFF,  CHX002_NPMC|(UINT64)D0F4_PLL_TEST_MODE_0 << 32,   D0F4_D0F4_RX40B2, D0F4_D0F4_RX40B2, //Rx40[2]
    0x00, 0xFF,  CHX002_APIC|(UINT64)D0F5_CFG_CYCLE_CTL_1 << 32,   D0F5_D0F5_RX260B6, D0F5_D0F5_RX260B6, //Rx260[6]
    0x00, 0xFF,  CHX002_SCRCH|(UINT64)D0F6_NM_PWR_STATE << 32,   D0F6_D0F6_RXE8B5, D0F6_D0F6_RXE8B5, //RxE8[5]

    0xFF, 0x00,  0x00,                       0x00,  0x00

};

/**
  Function description.
  
  @param  PeiServices	EFI_PEI_SERVICES pointer.
  @param NbCfg Point to ASIA_NB_CONFIGURATION struct.

  @return EFI_STATUS.

**/

EFI_STATUS AsiaNbLockVidDidRid(
	ASIA_NB_CONFIGURATION   *NbCfg
)
{
	BOOLEAN		VidNeedChange = FALSE, VidNeedLock = FALSE;
	UINT8		Index, Tmp8;
	UINT16		TmpVid = 0;
	UINT64		Address;
	EFI_STATUS	Status;
	EFI_GUID	AsiaSbCfgGuid = EFI_ASIA_SB_PROTOCOL_GUID;
	EFI_ASIA_SB_PROTOCOL    *pSb;
	ASIA_SB_CONFIGURATION  * SbCfg;
 

	Status = gBS->LocateProtocol(&AsiaSbCfgGuid, NULL, &pSb);
	if (EFI_ERROR(Status)) {
		return Status;
	}
	
	SbCfg = (ASIA_SB_CONFIGURATION*) pSb->SbCfg;


	Tmp8 = AsiaPciRead8(CHX002_SCRCH|D0F6_BIOS_SCRATCH_REG_13);

	//VID_Lock_Default is 0, BIOS can change VID if needed. We must lock VID after change.
	if((Tmp8 & 0x02) == 0) {
		VidNeedLock = TRUE;
#ifdef ZX_SECRET_CODE
		//If default VID is different from user selected, change it.
		if((Tmp8 & 0x1) != SbCfg->VidSelect) {
			VidNeedChange = TRUE;
			TmpVid = SbCfg->VidSelect ? PCI_VID_VIA : PCI_VID_ZX;
		}
#endif		
	}

	DEBUG((EFI_D_ERROR|EFI_D_INFO, "%a: Tmp8=%x, VidNeedLock=%x,VidNeedChange=%d\n", __FUNCTION__, Tmp8, VidNeedLock, VidNeedChange));
	for(Index = 0; Index < sizeof(NbVidDidLockTbl)/sizeof(NbVidDidLockTbl[0]); Index++) {
		Address = ASIA_PCI_ADDRESS(CHX002_HB_BUS, NbVidDidLockTbl[Index].Device, NbVidDidLockTbl[Index].Function, 0x00);
		//In case some functions are disabled.
		if(AsiaPciRead16(Address) == 0xFFFF)
			continue;

		//Lock VID
		if(VidNeedLock) {
			if(VidNeedChange) {
				AsiaPciWriteSave16(Address, TmpVid);
			}
			Address = AsiaPciAddress(CHX002_HB_BUS, NbVidDidLockTbl[Index].Device, 
			NbVidDidLockTbl[Index].Function, 
			NbVidDidLockTbl[Index].VIDLockReg);
			AsiaPcieModifySave8(NbCfg->PcieBar, Address, NbVidDidLockTbl[Index].VIDLockBit, NbVidDidLockTbl[Index].VIDLockBit);
		}
		//Lock DID/RID
		Address = AsiaPciAddress(CHX002_HB_BUS, NbVidDidLockTbl[Index].Device, 
		NbVidDidLockTbl[Index].Function, 
		NbVidDidLockTbl[Index].DIDLockReg);
		AsiaPcieModifySave8(NbCfg->PcieBar, Address, NbVidDidLockTbl[Index].DIDLockBit, NbVidDidLockTbl[Index].DIDLockBit);
		
	}

        PROCESS_NB_PCIE_R6408M_TABLE_SAVE(NbCfg->PcieBar, NbClassCodeLockTbl, sizeof(NbClassCodeLockTbl)/sizeof(ASIA_IO_TABLE_6408_REV));

	return EFI_SUCCESS;
	
}

 //YKN-20161025 -s
 /**
  Function description.
  
  @param  PeiServices	EFI_PEI_SERVICES pointer.
  @param NbCfg Point to ASIA_NB_CONFIGURATION struct.

  @return EFI_STATUS.

**/
VOID
UpdateNbSVIDSSID()
{
    AsiaPciWriteSave32((CHX002_GFXAX|D0F0_SVID), AsiaPciRead32(CHX002_GFXAX|D0F0_VID));
    AsiaPciWriteSave32((CHX002_ERRC|D0F1_SVID), AsiaPciRead32(CHX002_ERRC|D0F1_VID));
    AsiaPciWriteSave32((CHX002_HIF|D0F2_SVID), AsiaPciRead32(CHX002_HIF|D0F2_VID));
	//TODO RKD remove for pxp code parpare
    AsiaPciWriteSave32((CHX002_DRAM|D0F3_SVID), AsiaPciRead32(CHX002_DRAM|D0F3_VID));
    AsiaPciWriteSave32((CHX002_NPMC|D0F4_SVID), AsiaPciRead32(CHX002_NPMC|D0F4_VID));
    AsiaPciWriteSave32((CHX002_APIC|D0F5_SVID), AsiaPciRead32(CHX002_APIC|D0F5_VID));
    AsiaPciWriteSave32((CHX002_SCRCH|D0F6_SVID), AsiaPciRead32(CHX002_SCRCH|D0F6_VID));
    AsiaPciWriteSave32((CHX002_RAIDA0|D8F0_SVID), AsiaPciRead32(CHX002_RAIDA0|D8F0_VID));
    AsiaPciWriteSave32((CHX002_RAIDA1|D9F0_SVID), AsiaPciRead32(CHX002_RAIDA1|D9F0_VID));

	if(0xFFFF != AsiaPciRead16(CHX002_PE0|D3D5F1_VID)){
		AsiaPciWriteSave32((CHX002_PE0|D3D5F1_SVID_CTL), AsiaPciRead32(CHX002_PE0|D3D5F1_VID));
	}
	if(0xFFFF != AsiaPciRead16(CHX002_PE1|D3D5F1_VID)){
		AsiaPciWriteSave32((CHX002_PE1|D3D5F1_SVID_CTL), AsiaPciRead32(CHX002_PE1|D3D5F1_VID));
	}
	if(0xFFFF != AsiaPciRead16(CHX002_PE2|D3D5F1_VID)){
		AsiaPciWriteSave32((CHX002_PE2|D3D5F1_SVID_CTL), AsiaPciRead32(CHX002_PE2|D3D5F1_VID));
	}
	if(0xFFFF != AsiaPciRead16(CHX002_PE3|D3D5F1_VID)){
		AsiaPciWriteSave32((CHX002_PE3|D3D5F1_SVID_CTL), AsiaPciRead32(CHX002_PE3|D3D5F1_VID));
	}
	if(0xFFFF != AsiaPciRead16(CHX002_PE4|D3D5F1_VID)){
		AsiaPciWriteSave32((CHX002_PE4|D3D5F1_SVID_CTL), AsiaPciRead32(CHX002_PE4|D3D5F1_VID));
	}
	if(0xFFFF != AsiaPciRead16(CHX002_PE5|D3D5F1_VID)){
		AsiaPciWriteSave32((CHX002_PE5|D3D5F1_SVID_CTL), AsiaPciRead32(CHX002_PE5|D3D5F1_VID));
	}
	if(0xFFFF != AsiaPciRead16(CHX002_PE6|D3D5F1_VID)){
		AsiaPciWriteSave32((CHX002_PE6|D3D5F1_SVID_CTL), AsiaPciRead32(CHX002_PE6|D3D5F1_VID));
	}
	if(0xFFFF != AsiaPciRead16(CHX002_PE7|D3D5F1_VID)){
		AsiaPciWriteSave32((CHX002_PE7|D3D5F1_SVID_CTL), AsiaPciRead32(CHX002_PE7|D3D5F1_VID));
	}
	

	
}
 //YKN-20161025 -e

 //JennyChen add for CHX002 80 port-s
 /**
  Function description.
  
  @param  PeiServices	EFI_PEI_SERVICES pointer.
  @param NbCfg Point to ASIA_NB_CONFIGURATION struct.

  @return EFI_STATUS.

**/
VOID
PCIE_DXE_80_PORT(UINT8 Data)
 {
	 UINT8 PostCodeValue=Data;
	 AsiaIoWrite8(0x80,PostCodeValue);
	 DEBUG((EFI_D_ERROR, "POSTCODE=<%02x>\n", AsiaIoRead8(0x80)));
 }
 //JennyChen add for CHX002 80 port-e

 /**
  Function description.
  
  @param  PeiServices	EFI_PEI_SERVICES pointer.
  @param NbCfg Point to ASIA_NB_CONFIGURATION struct.

  @return EFI_STATUS.

**/
EFI_STATUS VPIL_TA_PowerControl(IN ASIA_NB_CONFIGURATION *NbConfig)
{
#ifdef ZX_DUALSOCKET
		  UINT8 SlaveBusNum = NbConfig->ZxeSlaveBusNum;
#endif
		  
		  if((NbConfig->NBSPEValue)>= CHIP_SPE_VALUE_PERFORMANCE && !(NbConfig->IOVEnable) && !(NbConfig->RAIDA0Enable || NbConfig->RAIDA1Enable))
		  { 	  
			  AsiaPcieModifySave8(NbConfig->PcieBar, AsiaPciAddress(CHX002_HB_BUS,CHX002_HB_DEV,CHX002_NPMC_FUN,D0F4_PWR_GATING_CTL_0), D0F4_RTAISOEN, D0F4_RTAISOEN);
			  AsiaPcieModifySave8(NbConfig->PcieBar, AsiaPciAddress(CHX002_HB_BUS,CHX002_HB_DEV,CHX002_NPMC_FUN,D0F4_PWR_GATING_CTL_0), D0F4_RTAPSOEN, D0F4_RTAPSOEN);
		  }
		  else
		  {
			  AsiaPcieModifySave8(NbConfig->PcieBar, AsiaPciAddress(CHX002_HB_BUS,CHX002_HB_DEV,CHX002_NPMC_FUN,D0F4_PWR_GATING_CTL_0), D0F4_RTAISOEN, 0);
			  AsiaPcieModifySave8(NbConfig->PcieBar, AsiaPciAddress(CHX002_HB_BUS,CHX002_HB_DEV,CHX002_NPMC_FUN,D0F4_PWR_GATING_CTL_0), D0F4_RTAPSOEN, 0);
		  }
	 
#ifdef ZX_DUALSOCKET
		 if((NbConfig->NBSPEValue)>= CHIP_SPE_VALUE_PERFORMANCE && !(NbConfig->IOVEnable))
		 {		 
			 AsiaPcieModifySave8(NbConfig->PcieBar, AsiaPciAddress(SlaveBusNum,CHX002_HB_DEV,CHX002_NPMC_FUN,D0F4_PWR_GATING_CTL_0), D0F4_RTAISOEN, D0F4_RTAISOEN);
			 AsiaPcieModifySave8(NbConfig->PcieBar, AsiaPciAddress(SlaveBusNum,CHX002_HB_DEV,CHX002_NPMC_FUN,D0F4_PWR_GATING_CTL_0), D0F4_RTAPSOEN, D0F4_RTAPSOEN);
		 }
		 else
		 {
			 AsiaPcieModifySave8(NbConfig->PcieBar, AsiaPciAddress(SlaveBusNum,CHX002_HB_DEV,CHX002_NPMC_FUN,D0F4_PWR_GATING_CTL_0), D0F4_RTAISOEN, 0);
			 AsiaPcieModifySave8(NbConfig->PcieBar, AsiaPciAddress(SlaveBusNum,CHX002_HB_DEV,CHX002_NPMC_FUN,D0F4_PWR_GATING_CTL_0), D0F4_RTAPSOEN, 0);
		 }
#endif

#ifndef ZX_DUALSOCKET
      //Only for single socket.
       if(NbConfig->NBSPEValue>= CHIP_SPE_VALUE_PERFORMANCE) {
 	     AsiaPcieModifySave8(NbConfig->PcieBar, AsiaPciAddress(CHX002_HB_BUS,CHX002_HB_DEV,CHX002_NPMC_FUN,D0F4_PWR_GATING_CTL_0), D0F4_VPI_ISOEN, D0F4_VPI_ISOEN);
            AsiaPcieModifySave8(NbConfig->PcieBar, AsiaPciAddress(CHX002_HB_BUS,CHX002_HB_DEV,CHX002_NPMC_FUN,D0F4_PWR_GATING_CTL_0), D0F4_VPI_PSOEN, D0F4_VPI_PSOEN);
 	}
#endif
			  
		  return EFI_SUCCESS;

}

 /**
  Function description.
  
  @param  PeiServices	EFI_PEI_SERVICES pointer.
  @param NbCfg Point to ASIA_NB_CONFIGURATION struct.

  @return EFI_STATUS.

**/
 VOID AsiaNbDxeSidLock(ASIA_NB_CONFIGURATION* NbCfg)
 {
#ifdef ZX_DUALSOCKET
		  UINT8 SlaveBusNum = NbCfg->ZxeSlaveBusNum;
#endif
		  
		  //master device
		  //Now PEMCU is reported as an PCI endpoint, and PEMCU will use B0D0F6 as its source ID, because there is a real PCI device with B0D0F6. JRZ-20181016
		  AsiaMemoryModifySave16(NbCfg->PcieEPHYBar | PCIEPHYCFG_PEMCU_SID, 0xFFFF, 0x0006);
		  AsiaMemoryModifySave8(NbCfg->PcieEPHYBar | PCIEPHYCFG_PEMCU_RESET_AND_INSTRUCTION_AUTO_FILL_ENABLE_AND_DONE_Z1, PCIEPHYCFG_PEMCU_SID_LOCKBIT, PCIEPHYCFG_PEMCU_SID_LOCKBIT);
		  
		  //JRZ: the address must be aligned to the access width!
		  AsiaPcieModifySave8(NbCfg->PcieBar, AsiaPciAddress(CHX002_HB_BUS,CHX002_HB_DEV,CHX002_APIC_FUN,D0F5_GFX_BUS_NUM), 0xFF, 0x00);
		  AsiaPcieModifySave8(NbCfg->PcieBar, AsiaPciAddress(CHX002_HB_BUS,CHX002_HB_DEV,CHX002_APIC_FUN,D0F5_GFX_DEV_NUM), 0xF8, 0x08);
		  AsiaPcieModifySave8(NbCfg->PcieBar, AsiaPciAddress(CHX002_HB_BUS,CHX002_HB_DEV,CHX002_APIC_FUN,D0F5_GFX_DEV_NUM), D0F5_D0F5_RX154B0, D0F5_D0F5_RX154B0);
	  
		  AsiaPcieModifySave32(NbCfg->PcieBar, AsiaPciAddress(CHX002_HB_BUS, CHX002_RAIDA0_DEV, CHX002_RAIDA0_FUN, D8F0_RAIDA0_BUS_NUM), D8F0_RDA0BUSNUM|D8F0_RDA0DEVNUM|D8F0_RDA0FUNNUM, (0x0 << 10)|(0x8 << 5)|(0x0));
		  AsiaPcieModifySave32(NbCfg->PcieBar, AsiaPciAddress(CHX002_HB_BUS, CHX002_RAIDA0_DEV, CHX002_RAIDA0_FUN, D8F0_RAIDA0_BUS_NUM), D8F0_IOV_SID_LOCK_BIT, D8F0_IOV_SID_LOCK_BIT);
		  
		  AsiaPcieModifySave32(NbCfg->PcieBar, AsiaPciAddress(CHX002_HB_BUS,CHX002_RAIDA1_DEV, CHX002_RAIDA1_FUN, D9F0_RAIDA1_BUS_NUM), D9F0_RDA1BUSNUM|D9F0_RDA1DEVNUM|D9F0_RDA1FUNNUM, (0x0 << 10)|(0x9 << 5)|(0x0));
		  AsiaPcieModifySave32(NbCfg->PcieBar, AsiaPciAddress(CHX002_HB_BUS,CHX002_RAIDA1_DEV, CHX002_RAIDA1_FUN, D9F0_RAIDA1_BUS_NUM), D9F0_IOV_SID_LOCK_BIT, D9F0_IOV_SID_LOCK_BIT);
		  
		  AsiaPcieModifySave16(NbCfg->PcieBar, AsiaPciAddress(CHX002_HB_BUS,CHX002_HB_DEV,CHX002_APIC_FUN,D0F5_APICX_UPSTREAM_CYCLE_SID), 0xFFFF, 0x0005);
		  AsiaPcieModifySave8(NbCfg->PcieBar, AsiaPciAddress(CHX002_HB_BUS,CHX002_HB_DEV,CHX002_APIC_FUN,D0F5_LOCK_CTL_AND_OTHERS), D0F5_D0F5_RX14AB7, D0F5_D0F5_RX14AB7);
	  
		  //slave device
#ifdef ZX_DUALSOCKET
		  //Now PEMCU is reported as an PCI endpoint, and PEMCU will use B0D0F6 as its source ID, because there is a real PCI device with B0D0F6. JRZ-20181016
		  AsiaMemoryModifySave16(NbCfg->Slave_PcieEPHYBar | PCIEPHYCFG_PEMCU_SID, 0xFFFF, (SlaveBusNum << 8)|0x06);
		  AsiaMemoryModifySave8(NbCfg->Slave_PcieEPHYBar | PCIEPHYCFG_PEMCU_RESET_AND_INSTRUCTION_AUTO_FILL_ENABLE_AND_DONE_Z1, PCIEPHYCFG_PEMCU_SID_LOCKBIT, PCIEPHYCFG_PEMCU_SID_LOCKBIT);
	  
		  AsiaPcieModifySave32(NbCfg->PcieBar, AsiaPciAddress(SlaveBusNum, CHX002_RAIDA0_DEV, CHX002_RAIDA0_FUN, D8F0_RAIDA0_BUS_NUM), D8F0_RDA0BUSNUM|D8F0_RDA0DEVNUM|D8F0_RDA0FUNNUM, (SlaveBusNum << 10)|(0x8 << 5)|(0x0));
		  AsiaPcieModifySave32(NbCfg->PcieBar, AsiaPciAddress(SlaveBusNum, CHX002_RAIDA0_DEV, CHX002_RAIDA0_FUN, D8F0_RAIDA0_BUS_NUM), D8F0_IOV_SID_LOCK_BIT, D8F0_IOV_SID_LOCK_BIT);
		  
		  AsiaPcieModifySave32(NbCfg->PcieBar, AsiaPciAddress(SlaveBusNum,CHX002_RAIDA1_DEV, CHX002_RAIDA1_FUN, D9F0_RAIDA1_BUS_NUM), D9F0_RDA1BUSNUM|D9F0_RDA1DEVNUM|D9F0_RDA1FUNNUM, (SlaveBusNum << 10)|(0x9 << 5)|(0x0));
		  AsiaPcieModifySave32(NbCfg->PcieBar, AsiaPciAddress(SlaveBusNum,CHX002_RAIDA1_DEV, CHX002_RAIDA1_FUN, D9F0_RAIDA1_BUS_NUM), D9F0_IOV_SID_LOCK_BIT, D9F0_IOV_SID_LOCK_BIT);
		  
		  AsiaPcieModifySave16(NbCfg->PcieBar, AsiaPciAddress(SlaveBusNum,CHX002_HB_DEV,CHX002_APIC_FUN,D0F5_APICX_UPSTREAM_CYCLE_SID), 0xFFFF, (SlaveBusNum << 8)|0x05);
		  AsiaPcieModifySave8(NbCfg->PcieBar, AsiaPciAddress(SlaveBusNum,CHX002_HB_DEV,CHX002_APIC_FUN,D0F5_LOCK_CTL_AND_OTHERS), D0F5_D0F5_RX14AB7, D0F5_D0F5_RX14AB7);
#endif

 }
 
#ifdef ZX_TXT_SUPPORT
/**
  Function description.
  
  @param  PeiServices	EFI_PEI_SERVICES pointer.
  @param NbCfg Point to ASIA_NB_CONFIGURATION struct.

  @return EFI_STATUS.

**/

EFI_STATUS TXTDprInit(
	ASIA_NB_CONFIGURATION    *NbCfg)
 {
	EFI_STATUS                Status;	
    EFI_HOB_GENERIC_HEADER    *HobList;
    EFI_GUID                  EfiHobListGuid = EFI_HOB_LIST_GUID;
    VOID                      *TxtVariable = NULL;
    EFI_GUID                  AsiaVariableGuid = ASIA_VARIABLE_GUID;
	UINT64                    Address;
	UINT16                    LowTopAddress;
	UINT16                    DprSize;

    Status = EfiLibGetSystemConfigurationTable(&EfiHobListGuid, &HobList);
    if (!EFI_ERROR(Status))
        Status = GetNextGuidHob(&HobList, &AsiaVariableGuid, &TxtVariable, NULL);
    if (EFI_ERROR(Status))
    {
        DEBUG((EFI_D_ERROR, "TXT Variable Hob Not Found!!! \n"));
        ASSERT(!EFI_ERROR(Status));
    }

	if (((ASIA_VARIABLE *)TxtVariable)->TXT == 1){
		// Init TXT.DPR
		Address = AsiaPciAddress(CHX002_HB_BUS, CHX002_HB_DEV, CHX002_HIF_FUN, D0F2_BELOW_4G_HIGHEST_MEM_LIMIT_DRAM_LIMIT_ADR_BELOW_4G);
		LowTopAddress = (AsiaPcieRead16(NbCfg->PcieBar, Address) & D0F2_RLOWTOPA_31_20) >> 4;
		DEBUG((EFI_D_ERROR, "TXT: LowTopAddress = 0x%x . \n", LowTopAddress));
		AsiaMemoryModifySave32(TXT_PUBLIC_CONFIG_REGS_BASE | TXT_TXT_DPR_DMA_PROTECTED_RANGE, TXT_TXT_DPR_TOP_11_0, LowTopAddress << 20); // set TXT_DPR_TOP

		Address = AsiaPciAddress(CHX002_HB_BUS, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_DMA_PROTECTION_CTL);
		DprSize = (AsiaPcieRead16(NbCfg->PcieBar, Address) & D0F3_DPR_SIZE_7_0) >> 4;
		DEBUG((EFI_D_ERROR, "TXT: DprSize = 0x%x . \n", DprSize));
		AsiaMemoryModifySave16(TXT_PUBLIC_CONFIG_REGS_BASE | TXT_TXT_DPR_DMA_PROTECTED_RANGE, TXT_TXT_DPR_SIZE_7_0, DprSize);
		AsiaMemoryModifySave8(TXT_PUBLIC_CONFIG_REGS_BASE | TXT_TXT_DPR_DMA_PROTECTED_RANGE, TXT_TXT_LOCK, BIT0);
	}

	return EFI_SUCCESS;
 }
 #endif

 /**
   Function description.
   
   @param  PeiServices	 EFI_PEI_SERVICES pointer.
   @param NbCfg Point to ASIA_NB_CONFIGURATION struct.
 
   @return EFI_STATUS.
 
 **/

 EFI_STATUS AsiaNbDxePrePciInit(
	 IN EFI_ASIA_NB_PROTOCOL *This)
 {
	 ASIA_NB_CONFIGURATION *NbCfg;
	 UINT8 X, Y, Z;
	 UINT8 NbSPEValue;
	 EFI_STATUS Status;
	 UINT8 CpuCoreCount;

	 UINT64 Address;

    EFI_ASIA_CPU_PPI_PROTOCOL *pCpuPpi;
    EFI_GUID AsiaCpuPpiGuid = EFI_ASIA_CPU_PROTOCOL_GUID;
    ACPU_VERSION_INFO    VersionInfo;
    UINT8     Clusters;

	UINT8					RTE_Index;
	UINT32					RTE_Hi, RTE_Lo;
    UINT8 					Clk;
	
    Status = gBS->LocateProtocol(&AsiaCpuPpiGuid, NULL, &pCpuPpi);
    if (EFI_ERROR(Status)) {
        return Status;
    }
    pCpuPpi->GetCpuVersionInfo(&VersionInfo);
    CpuCoreCount = pCpuPpi->GetCpuCores();
	//Recode alive cpu number into scratch, don't change it!!!!!!!!!!
    AsiaPciModifySave8(CHX002_SCRCH|D0F6_BIOS_SCRATCH_REG_14, 0xFF, CpuCoreCount);

    if (NULL != This->NbCfg && ((ASIA_NB_CONFIGURATION*)(This->NbCfg))->Signature == ASIA_NB_CONFIGURATION_SIGNATURE) {
        NbCfg = (ASIA_NB_CONFIGURATION*)(This->NbCfg);
    }
    else {
        //NbCfg = &gDefaultNbCfg;
        NbCfg = NULL;
        ASSERT(FALSE); // should not come here. TGR-20180509001
    }
	//JennyChen add for CHX002 80 port
	PCIE_DXE_80_PORT(DXE_NB_PCIE_PRE_INIT);   //JennyChen add for CHX002 80 port


    NbSPEValue = NbCfg->NBSPEValue;

    //processs STABLE table
    PROCESS_NB_R6408M_TABLE_SAVE(NBSafeTBL, sizeof(NBSafeTBL)/sizeof(ASIA_IO_TABLE_6408_REV));
    PROCESS_NB_PCIE_R6408M_TABLE_SAVE(NbCfg->PcieBar, NBSafeMMIOTBL, sizeof(NBSafeMMIOTBL)/sizeof(ASIA_IO_TABLE_6408_REV));


    switch(NbCfg->NBSPEValue) {
    case CHIP_SPE_VALUE_MANUAL:
        break;
    case CHIP_SPE_VALUE_PERFORMANCE:
        NbCfg->D0F0SPEValue = DEVICE_SPE_VALUE_PERFORMANCE;
        NbCfg->D0F1SPEValue = DEVICE_SPE_VALUE_PERFORMANCE;
        NbCfg->D0F2SPEValue = DEVICE_SPE_VALUE_PERFORMANCE;
        NbCfg->D0F3SPEValue = DEVICE_SPE_VALUE_PERFORMANCE;
        NbCfg->D0F4SPEValue = DEVICE_SPE_VALUE_PERFORMANCE;
        NbCfg->D0F5SPEValue = DEVICE_SPE_VALUE_PERFORMANCE;
        NbCfg->D0F6SPEValue = DEVICE_SPE_VALUE_PERFORMANCE;
        NbCfg->D0F7SPEValue = DEVICE_SPE_VALUE_PERFORMANCE;
        NbCfg->D1F0SPEValue = DEVICE_SPE_VALUE_PERFORMANCE;
 //       NbCfg->D2F0SPEValue = DEVICE_SPE_VALUE_PERFORMANCE;
        NbCfg->D3F0SPEValue = DEVICE_SPE_VALUE_PERFORMANCE;
		NbCfg->D3F1SPEValue = DEVICE_SPE_VALUE_PERFORMANCE;
		NbCfg->D3F2SPEValue = DEVICE_SPE_VALUE_PERFORMANCE;
		NbCfg->D3F3SPEValue = DEVICE_SPE_VALUE_PERFORMANCE;
        NbCfg->D4F0SPEValue = DEVICE_SPE_VALUE_PERFORMANCE;
		NbCfg->D4F1SPEValue = DEVICE_SPE_VALUE_PERFORMANCE;
        NbCfg->D5F0SPEValue = DEVICE_SPE_VALUE_PERFORMANCE;
		NbCfg->D5F1SPEValue = DEVICE_SPE_VALUE_PERFORMANCE;
		NbCfg->RCRBHSPEValue = DEVICE_SPE_VALUE_PERFORMANCE;
        //CHX001-CJW-20151014   NbCfg->D6F0SPEValue = DEVICE_SPE_VALUE_PERFORMANCE;
	 	//CHX001-CJW-20151014   NbCfg->D7F0SPEValue = DEVICE_SPE_VALUE_PERFORMANCE;  //CND001-R01-VTG-01
		NbCfg->D8F0SPEValue = DEVICE_SPE_VALUE_PERFORMANCE;
		NbCfg->D9F0SPEValue = DEVICE_SPE_VALUE_PERFORMANCE;
        break;
    case CHIP_SPE_VALUE_ENERGY:
        NbCfg->D0F0SPEValue = DEVICE_SPE_VALUE_ENERGY;
        NbCfg->D0F1SPEValue = DEVICE_SPE_VALUE_ENERGY;
        NbCfg->D0F2SPEValue = DEVICE_SPE_VALUE_ENERGY;
        NbCfg->D0F3SPEValue = DEVICE_SPE_VALUE_ENERGY;
        NbCfg->D0F4SPEValue = DEVICE_SPE_VALUE_ENERGY;
        NbCfg->D0F5SPEValue = DEVICE_SPE_VALUE_ENERGY;
        NbCfg->D0F6SPEValue = DEVICE_SPE_VALUE_ENERGY;
        NbCfg->D0F7SPEValue = DEVICE_SPE_VALUE_ENERGY;
        NbCfg->D1F0SPEValue = DEVICE_SPE_VALUE_ENERGY;
 //       NbCfg->D2F0SPEValue = DEVICE_SPE_VALUE_ENERGY;
        NbCfg->D3F0SPEValue = DEVICE_SPE_VALUE_ENERGY;
		NbCfg->D3F1SPEValue = DEVICE_SPE_VALUE_ENERGY;
		NbCfg->D3F2SPEValue = DEVICE_SPE_VALUE_ENERGY;
		NbCfg->D3F3SPEValue = DEVICE_SPE_VALUE_ENERGY;
		NbCfg->D4F0SPEValue = DEVICE_SPE_VALUE_ENERGY;
        NbCfg->D4F1SPEValue = DEVICE_SPE_VALUE_ENERGY;
		NbCfg->D5F0SPEValue = DEVICE_SPE_VALUE_ENERGY;
        NbCfg->D5F1SPEValue = DEVICE_SPE_VALUE_ENERGY;
		NbCfg->RCRBHSPEValue = DEVICE_SPE_VALUE_ENERGY;
        //CHX001-CJW-20151014   NbCfg->D6F0SPEValue = DEVICE_SPE_VALUE_ENERGY;
	 	//CHX001-CJW-20151014   NbCfg->D7F0SPEValue = DEVICE_SPE_VALUE_ENERGY;   //CND001-R01-VTG-01
		NbCfg->D8F0SPEValue = DEVICE_SPE_VALUE_ENERGY;
		NbCfg->D9F0SPEValue = DEVICE_SPE_VALUE_ENERGY;
        break;
    case CHIP_SPE_VALUE_STABLE:
    default:
        NbCfg->D0F0SPEValue = DEVICE_SPE_VALUE_STABLE;
        NbCfg->D0F1SPEValue = DEVICE_SPE_VALUE_STABLE;
        NbCfg->D0F2SPEValue = DEVICE_SPE_VALUE_STABLE;
        NbCfg->D0F3SPEValue = DEVICE_SPE_VALUE_STABLE;
        NbCfg->D0F4SPEValue = DEVICE_SPE_VALUE_STABLE;
        NbCfg->D0F5SPEValue = DEVICE_SPE_VALUE_STABLE;
        NbCfg->D0F6SPEValue = DEVICE_SPE_VALUE_STABLE;
        NbCfg->D0F7SPEValue = DEVICE_SPE_VALUE_STABLE;
        NbCfg->D1F0SPEValue = DEVICE_SPE_VALUE_STABLE;
 //       NbCfg->D2F0SPEValue = DEVICE_SPE_VALUE_STABLE;
        NbCfg->D3F0SPEValue = DEVICE_SPE_VALUE_STABLE;
		NbCfg->D3F1SPEValue = DEVICE_SPE_VALUE_STABLE;
		NbCfg->D3F2SPEValue = DEVICE_SPE_VALUE_STABLE;
		NbCfg->D3F3SPEValue = DEVICE_SPE_VALUE_STABLE;
        NbCfg->D4F0SPEValue = DEVICE_SPE_VALUE_STABLE;
		NbCfg->D4F1SPEValue = DEVICE_SPE_VALUE_STABLE;
        NbCfg->D5F0SPEValue = DEVICE_SPE_VALUE_STABLE;
		NbCfg->D5F1SPEValue = DEVICE_SPE_VALUE_STABLE;
		NbCfg->RCRBHSPEValue = DEVICE_SPE_VALUE_STABLE;
        //CHX001-CJW-20151014   NbCfg->D6F0SPEValue = DEVICE_SPE_VALUE_STABLE;
	 	//CHX001-CJW-20151014   NbCfg->D7F0SPEValue = DEVICE_SPE_VALUE_STABLE;  //CND001-R01-VTG-01
		NbCfg->D8F0SPEValue = DEVICE_SPE_VALUE_STABLE;
		NbCfg->D9F0SPEValue = DEVICE_SPE_VALUE_STABLE;
        break;
    }

    
    //process APIC config
    if (NbCfg->NbApicEnable) {

		Address = AsiaPciAddress(CHX002_HB_BUS,CHX002_HB_DEV,CHX002_APIC_FUN,D0F5_APIC_ACCESS_CTL);

		AsiaPcieModifySave8(NbCfg->PcieBar, Address, D0F5_RLGAPIC, D0F5_RLGAPIC);
		
        X= (UINT8)(RShiftU64(NbCfg->NbApicBaseAddress, 16) & 0xF);

		AsiaPcieModifySave8(NbCfg->PcieBar, Address, D0F5_RLGAX_19_16, X);


		Address = AsiaPciAddress(CHX002_HB_BUS,CHX002_HB_DEV,CHX002_APIC_FUN,D0F5_NB_IOAPIC_ADR_RANGE);
		
        Y = (UINT8)(RShiftU64(NbCfg->NbApicBaseAddress, 12) & 0xF);

		AsiaPcieModifySave8(NbCfg->PcieBar, Address, D0F5_RLGAY_15_12, Y << 4);

        Z = (UINT8)(RShiftU64(NbCfg->NbApicBaseAddress, 8) & 0xF);

		AsiaPcieModifySave8(NbCfg->PcieBar, Address, D0F5_RLGAZ_11_8, Z);
		

        //set NB APIC ID ;
        AsiaMemoryWriteSave8(NbCfg->NbApicBaseAddress, 0x00);
        AsiaMemoryWriteSave32(NbCfg->NbApicBaseAddress + 0x10, NbCfg->NbApicID<<24);

        //set NB APIC use FSB
        AsiaMemoryWriteSave8(NbCfg->NbApicBaseAddress, 0x03);
        AsiaMemoryWriteSave32(NbCfg->NbApicBaseAddress + 0x10, 0x01);


		//For debug, dump all RT entry
		//RTE index from 0x10 - 0x3E, total 24 entry
		for(RTE_Index = 0x10 ; RTE_Index < 0x40 ; RTE_Index += 2)
		{	
			AsiaMemoryWrite8(NbCfg->NbApicBaseAddress, RTE_Index);
			RTE_Lo = AsiaMemoryRead32(NbCfg->NbApicBaseAddress + 0x10);
			AsiaMemoryWrite8(NbCfg->NbApicBaseAddress, RTE_Index + 1);
			RTE_Hi = AsiaMemoryRead32(NbCfg->NbApicBaseAddress + 0x10);
			DEBUG((EFI_D_ERROR|EFI_D_INFO, "WIC NB RET%d Hi:%X Lo:%X\n",(RTE_Index - 0x10)/2, RTE_Hi, RTE_Lo));
		}		
		 

		//Clear bit 48 for each I/O Redirection Table Entry due to design issue cause default value randomly
		for(RTE_Index = 0x10 ; RTE_Index < 0x40 ; RTE_Index += 2)
		{	
			AsiaMemoryWriteSave8(NbCfg->NbApicBaseAddress, RTE_Index + 1);

			AsiaMemoryModifySave32(NbCfg->NbApicBaseAddress + 0x10, 0x10000 , 0);

			 RTE_Hi = AsiaMemoryRead32(NbCfg->NbApicBaseAddress + 0x10);
			 DEBUG((EFI_D_ERROR|EFI_D_INFO, "WIC NB RET%d Hi:%X\n",(RTE_Index - 0x10)/2, RTE_Hi));
		}


    }
    else {

		Address = AsiaPciAddress(CHX002_HB_BUS,CHX002_HB_DEV,CHX002_APIC_FUN,D0F5_APIC_ACCESS_CTL);
		AsiaPcieModifySave8(NbCfg->PcieBar, Address, D0F5_RLGAPIC, 0);
    }

    //TODO: Nb related early initializations
    //TODO: Do B0D0F0 related initializations
    if(NbCfg->D0F0SPEValue >= DEVICE_SPE_VALUE_PERFORMANCE) {
        PROCESS_NB_R6408M_TABLE_SAVE(D0F0PerformanceTBL, sizeof(D0F0PerformanceTBL)/sizeof(ASIA_IO_TABLE_6408_REV));
        if(NbCfg->D0F0SPEValue == DEVICE_SPE_VALUE_ENERGY) {
            PROCESS_NB_R6408M_TABLE_SAVE(D0F0EnergyTBL, sizeof(D0F0EnergyTBL)/sizeof(ASIA_IO_TABLE_6408_REV));
        }
    }


    if(NbCfg->D0F1SPEValue >= DEVICE_SPE_VALUE_PERFORMANCE) {
        PROCESS_NB_R6408M_TABLE_SAVE(D0F1PerformanceTBL, sizeof(D0F1PerformanceTBL)/sizeof(ASIA_IO_TABLE_6408_REV));
        if(NbCfg->D0F1SPEValue == DEVICE_SPE_VALUE_ENERGY) {
            PROCESS_NB_R6408M_TABLE_SAVE(D0F1EnergyTBL, sizeof(D0F1EnergyTBL)/sizeof(ASIA_IO_TABLE_6408_REV));
        }
    }

   
    if(NbCfg->D0F3SPEValue >= DEVICE_SPE_VALUE_PERFORMANCE) {
        //PROCESS_NB_PCIE_R6408M_TABLE_SAVE(NbCfg->PcieBar,D0F3PerformanceTBL, sizeof(D0F3PerformanceTBL)/sizeof(ASIA_IO_TABLE_6408_REV));
        PROCESS_NB_PCIE_R6432M_TABLE_SAVE(NbCfg->PcieBar,D0F3_PerformanceTBL, sizeof(D0F3_PerformanceTBL)/sizeof(ASIA_IO_TABLE_6432_REV));		
		
        if(NbCfg->D0F3SPEValue == DEVICE_SPE_VALUE_ENERGY) {
            //PROCESS_NB_PCIE_R6408M_TABLE_SAVE(NbCfg->PcieBar, D0F3EnergyTBL, sizeof(D0F3EnergyTBL)/sizeof(ASIA_IO_TABLE_6408_REV));
			PROCESS_NB_PCIE_R6432M_TABLE_SAVE(NbCfg->PcieBar, D0F3_EnergyTBL, sizeof(D0F3_EnergyTBL)/sizeof(ASIA_IO_TABLE_6432_REV));
        }

		//Design limitation Item 6 +S
		Address = AsiaPciAddress(CHX002_HB_BUS, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_PLLIN_CTL_Z1);
		Clk = (UINT8)((AsiaPcieRead16(NbCfg->PcieBar, Address) & D0F3_RDIV_M_PLLIN_7_0) >> 8);
			
		Address = AsiaPciAddress(CHX002_HB_BUS, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_MERGE_RELATED_CTL);
		if(AsiaPcieRead16(NbCfg->PcieBar, Address) & D0F3_RMWCTL0)  //enable GFX RMW
		{
			if (Clk != DRAM_FREQ_1600)
			{
				Address = AsiaPciAddress(CHX002_HB_BUS, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_DRAMC_REQ_REORDER_CTL_I_DRAM_REQ_CTL);  //disable inorder
				AsiaPcieModifySave16(NbCfg->PcieBar, Address, D0F3_RINORDER, 0);
			}
		}
		//Design limitation Item 6 +E

		//DRAMC limitation Item 11 +s
	    //LGE20161230 When Burst chop Enable, Set RINORDER = 0 -S
		{
			UINT8 BurstChop;
			Address = AsiaPciAddress(CHX002_HB_BUS, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_PAD_CTL_DRAM_DATA_BURST_CTL);  
			BurstChop = AsiaPcieRead8(NbCfg->PcieBar, Address);

			Address = AsiaPciAddress(CHX002_HB_BUS, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_DRAMC_REQ_REORDER_CTL_I_DRAM_REQ_CTL);
			if(BurstChop&D0F3_RDMBCOTF)			          
				AsiaPcieModifySave16(NbCfg->PcieBar, Address, D0F3_RINORDER, 0);
		   
		}
	    //LGE20161230 When Burst chop Enable, Set RINORDER = 0 -E 
	    //DRAMC limitation Item 11 +e


		//DRAMC limitation Item 1 +s
		//Not support in-order and dynamic non-page mode at the same time
		//if(ASIA_NB_REVISION == 0)
		//{
			Address = AsiaPciAddress(CHX002_HB_BUS, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_DRAMC_REQ_REORDER_CTL_I_DRAM_REQ_CTL);
			if(AsiaPcieRead16(NbCfg->PcieBar, Address)&D0F3_RINORDER)
			{			
				Address = AsiaPciAddress(CHX002_HB_BUS, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_DRAMC_PAGE_CTL_DRAMC_PAGE_ALL_CTL);
				AsiaPcieModify16(NbCfg->PcieBar, Address, D0F3_RNONPGMEN, 0);
			}
    		//DEBUG((EFI_D_ERROR|EFI_D_INFO, "A0 Limitation\n"));

		//}
		//DRAMC limitation Item 1 +e
		
		//A0&A2 limitation Item 13 +s		
		//Not support in-order and RBYPASSRDQEN at the same time
		if(ASIA_NB_REVISION == 0)
		{
		Address = AsiaPciAddress(CHX002_HB_BUS, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_DRAMC_REQ_REORDER_CTL_I_DRAM_REQ_CTL);
		if(AsiaPcieRead16(NbCfg->PcieBar, Address)&D0F3_RBYPASSRDQEN)
		{			
			Address = AsiaPciAddress(CHX002_HB_BUS, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_DRAMC_PAGE_CTL_DRAMC_PAGE_ALL_CTL);
			AsiaPcieModify16(NbCfg->PcieBar, Address, D0F3_RNONPGMEN, 0);
		}
		DEBUG((EFI_D_ERROR|EFI_D_INFO, "A0 Limitation\n"));
		}
		//A0&A2 limitation Item 13 +e

		
    }


    if(NbCfg->D0F4SPEValue >= DEVICE_SPE_VALUE_PERFORMANCE) {
        PROCESS_NB_PCIE_R6408M_TABLE_SAVE(NbCfg->PcieBar, D0F4PerformanceTBL, sizeof(D0F4PerformanceTBL)/sizeof(ASIA_IO_TABLE_6408_REV));
        if(NbCfg->D0F4SPEValue == DEVICE_SPE_VALUE_ENERGY) {
            PROCESS_NB_PCIE_R6408M_TABLE_SAVE(NbCfg->PcieBar, D0F4EnergyTBL, sizeof(D0F4EnergyTBL)/sizeof(ASIA_IO_TABLE_6408_REV));
        }	
    }


    if(NbCfg->D0F5SPEValue >= DEVICE_SPE_VALUE_PERFORMANCE) {
        PROCESS_NB_PCIE_R6408M_TABLE_SAVE(NbCfg->PcieBar, D0F5PerformanceTBL, sizeof(D0F5PerformanceTBL)/sizeof(ASIA_IO_TABLE_6408_REV));
        if(NbCfg->D0F5SPEValue == DEVICE_SPE_VALUE_ENERGY) {
            PROCESS_NB_PCIE_R6408M_TABLE_SAVE(NbCfg->PcieBar, D0F5EnergyTBL, sizeof(D0F5EnergyTBL)/sizeof(ASIA_IO_TABLE_6408_REV));
        }


		//When TA is enable, D0F5 Rx81[1] must set to 0.
		//When TA is disable, D0F5 Rx81[1] can set to 1 to enhance performance. 
		//Willy debug 20161125: This setting will casue reboot burn-in fail, keep it to 0 before designer found the root cause.
		if(!NbCfg->IOVEnable)
		{
			AsiaPciModifySave8(CHX002_APIC|D0F5_TRAFFIC_FLOW_CTL_UPSTREAM_CTL_UPSIDE_NEAR_CPUIF_2, D0F5_RMIDQBYPASS, D0F5_RMIDQBYPASS);
		}

    }

    Clusters = pCpuPpi->GetCpuClusters();
    AsiaPciModifySave8(CHX002_APIC|D0F5_STPGNT_CYCLE_CTL,
                       D0F5_RMSCMD_2_0,
                       (Clusters - 1) << 1);


    if(NbCfg->D0F6SPEValue >= DEVICE_SPE_VALUE_PERFORMANCE) {
        PROCESS_NB_R6408M_TABLE_SAVE(D0F6PerformanceTBL, sizeof(D0F6PerformanceTBL)/sizeof(ASIA_IO_TABLE_6408_REV));
        if(NbCfg->D0F6SPEValue == DEVICE_SPE_VALUE_ENERGY) {
            PROCESS_NB_R6408M_TABLE_SAVE(D0F6EnergyTBL, sizeof(D0F6EnergyTBL)/sizeof(ASIA_IO_TABLE_6408_REV));
        }
    }



    if(NbCfg->D0F7SPEValue >= DEVICE_SPE_VALUE_PERFORMANCE) {
        PROCESS_NB_R6408M_TABLE_SAVE(D0F7PerformanceTBL, sizeof(D0F7PerformanceTBL)/sizeof(ASIA_IO_TABLE_6408_REV));
        if(NbCfg->D0F7SPEValue == DEVICE_SPE_VALUE_ENERGY) {
            PROCESS_NB_R6408M_TABLE_SAVE(D0F7EnergyTBL, sizeof(D0F7EnergyTBL)/sizeof(ASIA_IO_TABLE_6408_REV));
        }
    }


    if(NbCfg->D1F0SPEValue >= DEVICE_SPE_VALUE_PERFORMANCE) {
        PROCESS_NB_R6408M_TABLE_SAVE(D1F0PerformanceTBL, sizeof(D1F0PerformanceTBL)/sizeof(ASIA_IO_TABLE_6408_REV));
        if(NbCfg->D1F0SPEValue == DEVICE_SPE_VALUE_ENERGY) {
            PROCESS_NB_R6408M_TABLE_SAVE(D1F0EnergyTBL, sizeof(D1F0EnergyTBL)/sizeof(ASIA_IO_TABLE_6408_REV));
        }
    }


    //LNA20160829-01 AsiaPciModify8(CHX002_SCRCH|(D0F6_BIOS_SCRATCH_REG_7), 0x3F, 0);	//D0F6Rx58[5:0] = 0

/*+ DSZ_Porting (ALN-2017081701) Set to E mode before root port release link.*/ 
/*- DSZ_Porting (ALN-2017081701) Set to E mode before root port release link.*/ 
	Address = AsiaPciAddress(CHX002_HB_BUS,CHX002_HB_DEV,CHX002_APIC_FUN,D0F5_PXPTRF_RELATED_REG_CFG_READ_FLUSH_UPSTREAM_WRITE_FOR_DEV);
	if(NbCfg->RAIDA0Enable) {
	 
	  AsiaPcieModifySave8(NbCfg->PcieBar, Address,  D0F5_RNPEQ_C2RAID0_MMIO_FLUSH_EN|D0F5_RD8F0_EN|D0F5_RNPEQ_C2RAID0_CFG_FLUSH_EN,
			D0F5_RNPEQ_C2RAID0_MMIO_FLUSH_EN|D0F5_RD8F0_EN|D0F5_RNPEQ_C2RAID0_CFG_FLUSH_EN);

	  AsiaPciModifySave8(CHX002_APIC|D0F5_PMU_CTL, D0F5_RPEROWEN, D0F5_RPEROWEN);
	  AsiaPciModifySave32(CHX002_RAIDA0|D8F0_RX08_7_0, 0xffffff00, 0x8800000);
	  AsiaPciModifySave8(CHX002_APIC|D0F5_PMU_CTL, D0F5_RPEROWEN, 0);
	  if(NbCfg->D8F0SPEValue >= DEVICE_SPE_VALUE_PERFORMANCE) {
	  	PROCESS_NB_R6408M_TABLE_SAVE(D8F0PerformanceTBL, sizeof(D8F0PerformanceTBL)/sizeof(ASIA_IO_TABLE_6408_REV));

	  if(NbCfg->D8F0SPEValue == DEVICE_SPE_VALUE_ENERGY) {
            PROCESS_NB_R6408M_TABLE_SAVE(D8F0EnergyTBL, sizeof(D8F0EnergyTBL)/sizeof(ASIA_IO_TABLE_6408_REV));
        }
     
	  }
	}
	else{
	   AsiaPcieModifySave8(NbCfg->PcieBar, Address,  D0F5_RNPEQ_C2RAID0_MMIO_FLUSH_EN|D0F5_RD8F0_EN|D0F5_RNPEQ_C2RAID0_CFG_FLUSH_EN,
			0);
	}
	if(NbCfg->RAIDA1Enable) {
	  	AsiaPcieModifySave8(NbCfg->PcieBar, Address,  D0F5_RNPEQ_C2RAID1_MMIO_FLUSH_EN|D0F5_RD9F0_EN|D0F5_RNPEQ_C2RAID1_CFG_FLUSH_EN,
			D0F5_RNPEQ_C2RAID1_MMIO_FLUSH_EN|D0F5_RD9F0_EN|D0F5_RNPEQ_C2RAID1_CFG_FLUSH_EN);

			
	  //YKN-20170118 -s
	  AsiaPciModifySave8(CHX002_APIC|D0F5_PMU_CTL, D0F5_RPEROWEN, D0F5_RPEROWEN);
	  AsiaPciModifySave32(CHX002_RAIDA1|D9F0_RX08_7_0, 0xffffff00, 0x8800000);
	  AsiaPciModifySave8(CHX002_APIC|D0F5_PMU_CTL, D0F5_RPEROWEN, 0);
	  if(NbCfg->D9F0SPEValue >= DEVICE_SPE_VALUE_PERFORMANCE) {
	  	PROCESS_NB_R6408M_TABLE_SAVE(D9F0PerformanceTBL, sizeof(D9F0PerformanceTBL)/sizeof(ASIA_IO_TABLE_6408_REV));
    
	  if(NbCfg->D9F0SPEValue == DEVICE_SPE_VALUE_ENERGY) {
            PROCESS_NB_R6408M_TABLE_SAVE(D9F0EnergyTBL, sizeof(D9F0EnergyTBL)/sizeof(ASIA_IO_TABLE_6408_REV));
        }

	  }
	}
    else{
		AsiaPcieModifySave8(NbCfg->PcieBar, Address,  D0F5_RNPEQ_C2RAID1_MMIO_FLUSH_EN|D0F5_RD9F0_EN|D0F5_RNPEQ_C2RAID1_CFG_FLUSH_EN,
			0);
    }

#ifdef IOE_EXIST
	// [CJW] CALL_IOE_CODE
	IoePrePciInit(NbCfg);
#endif

	PCIE_DXE_80_PORT(DXE_NB_IOE_PRE_INIT);   //add by jenny 20170413
    //Set S/P/E flag to D0F6Rx40[1:0]
    AsiaPciModifySave8(CHX002_SCRCH|D0F6_BIOS_SCRATCH_REG_1, 0X03, NbCfg->NBSPEValue);
    //;Rx40[7:4]: Scratch record revision
    AsiaPciModifySave8(CHX002_SCRCH|D0F6_BIOS_SCRATCH_REG_1, 0XF0, 0X10);


	PciePrePciInit(NbCfg);

#ifdef ZX_DUALSOCKET
//#ifdef DUAL_SOCKET_CODE
	if(NbCfg->ZxeDualSocket == 1){
		PciePrePciInitSlave(NbCfg);
	}
#endif	

#ifdef IOE_EXIST	
		// [CJW] CALL_IOE_CODE
		IoeHideXbctlEptrfcDxe(NbCfg);
#endif

	//JRZ: TA Isolation Cell is gated when TACTL isn't supported in E mode setting.
	VPIL_TA_PowerControl(NbCfg);

	//JRZ: the lock operation of NB devices' source id register
	AsiaNbDxeSidLock(NbCfg);

    //EnablePcieMsiCap(); 
//YKN-20151025 -s
//YKN-20161024 -s
// Temp disable VID/DID lock for S3 resume
//    AsiaNbLockVidDidRid();
//YKN-20161024 -e	
    AsiaNbLockVidDidRid(NbCfg);
    UpdateNbSVIDSSID();
//YKN-20151025 -e
#ifdef ZX_TXT_SUPPORT
    TXTDprInit(NbCfg);
#endif
	return EFI_SUCCESS;
}

/**
  Function description.
  
  @param  PeiServices	EFI_PEI_SERVICES pointer.
  @param NbCfg Point to ASIA_NB_CONFIGURATION struct.

  @return EFI_STATUS.

**/

EFI_STATUS AsiaNbDxePreprocessPciController (
    IN EFI_ASIA_NB_PROTOCOL *This,
    IN EFI_PCI_ROOT_BRIDGE_IO_PROTOCOL *PciRootBridgeIo,
    IN EFI_PCI_ROOT_BRIDGE_IO_PROTOCOL_PCI_ADDRESS PciAddress,
    IN EFI_PCI_CONTROLLER_RESOURCE_ALLOCATION_PHASE Phase
)
{
    return EFI_SUCCESS;
}

/**
  Function description.
  
  @param  PeiServices	EFI_PEI_SERVICES pointer.
  @param NbCfg Point to ASIA_NB_CONFIGURATION struct.

  @return EFI_STATUS.

**/

VOID ProcessPcieBiosOption(
    ASIA_NB_CONFIGURATION *NbCfg,
    UINT8    RpBusNum,
    UINT8    RpDeviceNum,
    UINT8    RpFuncNum
)
{
    UINT8   DevBusNum,SubBusNum;
    UINT16  VendorId, ClassCode;

    //decide if there are PCIE device behind this root port
    DevBusNum = AsiaPciRead8(AsiaPciAddress(RpBusNum, RpDeviceNum, RpFuncNum, D3D5F1_SECONDARY_BUS_NUM));
	SubBusNum = AsiaPciRead8(AsiaPciAddress(RpBusNum, RpDeviceNum, RpFuncNum, D3D5F1_SUBORDINATE_BUS_NUM));
    VendorId = 0xFFFF;
    VendorId = AsiaPciRead16(AsiaPciAddress(DevBusNum, 0, 0, 0));

	if(VendorId != 0xFFFF){
		
		SCRIPT_PCI_CFG_WRITE(
			EFI_ACPI_S3_RESUME_SCRIPT_TABLE,
			EfiBootScriptWidthUint8,
			AsiaPciAddress(RpBusNum, RpDeviceNum, RpFuncNum, D3D5F1_SECONDARY_BUS_NUM),
			0x01,
			&DevBusNum
		);
	
		SCRIPT_PCI_CFG_WRITE(
			EFI_ACPI_S3_RESUME_SCRIPT_TABLE,
			EfiBootScriptWidthUint8,
			AsiaPciAddress(RpBusNum, RpDeviceNum, RpFuncNum, D3D5F1_SUBORDINATE_BUS_NUM),
			0x01,
			&SubBusNum
		);
	
		ClassCode = AsiaPciRead16(AsiaPciAddress((UINT8)DevBusNum, 0, 0, D3D5F1_CLASS_CODE + 1));
		if (ClassCode == 0x0300) {
			AsiaPciModifySave8(AsiaPciAddress(RpBusNum, RpDeviceNum, RpFuncNum,D3D5F1_BRIDGE_CTL), D3D5F1_RVGA16, D3D5F1_RVGA16);
		}
#ifdef IOE_EXIST
		//[CJW_IOE]
		IoeSaveBusNumber2BootScript(NbCfg, DevBusNum);
#endif
	
		ProgramPcieTreeFeature(NbCfg, RpBusNum, RpDeviceNum, RpFuncNum);
		
	}

	ConfigPcieRPDoEq(NbCfg, RpBusNum, RpDeviceNum, RpFuncNum);

}


static UINT64 ExternalVgaLocation = 0;
#include "VcpCopyFunc.c"
#include "GfxShadowInfoFunc.c"

/**
  Function description.
  
  @param  PeiServices	EFI_PEI_SERVICES pointer.
  @param NbCfg Point to ASIA_NB_CONFIGURATION struct.

  @return EFI_STATUS.

**/

EFI_STATUS AsiaNbDxePostPciInit (
    IN EFI_ASIA_NB_PROTOCOL *This,
    IN EFI_PCI_IO_PROTOCOL *PciIo
)
{
    ASIA_NB_CONFIGURATION *NbCfg;
    UINTN Segment, Bus, Device, Function;
    UINT8	CacheLineSize, LatencyTimer;
    UINT32 UMABar10, UMABar14, RegVal, UmaSize, GfxFbSizeSave;
	UINT8 GfxPciSave, RVGAENsave, GfxIoSave1, GfxIoSave2, GfxIoSave3, GfxIoSave4, GfxIoSave5,GfxFbAccessSave;//RpPciSave[4][4]={0},
	//UINT8 DevIndex, FunIndex;
	UINT32 SVID;
	
    UINT16 ClassCode;
    UINT64 Address;
	
    PciIo->GetLocation(PciIo, &Segment, &Bus, &Device, &Function);
    DEBUG((EFI_D_ERROR|EFI_D_INFO, "AsiaNbPostPciInit! B%dD%dF%d\n",Bus, Device, Function));
    if(Segment != 0) {
        return EFI_SUCCESS;
    }

	// Save/Restore All Device/Function's Cache Line Size & Latency Timer for S3Resume
	CacheLineSize = AsiaPciRead8( AsiaPciAddress((UINT8)Bus, (UINT8)Device, (UINT8)Function, D0F0_CACHE_LINE_SIZE) ); 
	AsiaPciWriteSave8( AsiaPciAddress( (UINT8)Bus, (UINT8)Device, (UINT8)Function, D0F0_CACHE_LINE_SIZE),CacheLineSize );

	LatencyTimer = AsiaPciRead8( AsiaPciAddress((UINT8)Bus, (UINT8)Device, (UINT8)Function, D0F0_PCI_MASTER_LATENCY_TIMER) ); 
	AsiaPciWriteSave8( AsiaPciAddress( (UINT8)Bus, (UINT8)Device, (UINT8)Function, D0F0_PCI_MASTER_LATENCY_TIMER),LatencyTimer );
	
    NbCfg = (ASIA_NB_CONFIGURATION*)(This->NbCfg);
    switch(AsiaPciAddress((UINT8)Bus, (UINT8)Device, (UINT8)Function, 0)) {
    case CHX002_EUMA:
		//Get Base Address 0 of UMA in 32-bit address space (hardwired)
		UMABar10 = AsiaPciRead32(CHX002_EUMA|0x10);
		AsiaPciModifySave32(CHX002_EUMA|0x10, 0xFFFFFFFF, UMABar10);
		UMABar10 = (UMABar10&0xfffffff0);

				UMABar14 = AsiaPciRead32(CHX002_EUMA|0x14);
		AsiaPciModifySave32(CHX002_EUMA|0x14, 0xFFFFFFFF, UMABar14);
        

		//Get frame buffer size in unit of M
		Address = AsiaPciAddress(CHX002_HB_BUS, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_CPU_DIRECT_ACCESS_FRAME_BUFFER_CTL_Z1); 
		RegVal = AsiaPcieRead32(((ASIA_NB_CONFIGURATION *)(This->NbCfg))->PcieBar, Address)&D0F3_RFBSZ_2_0;
		RegVal = RegVal >> 4;
		if (RegVal > 0x4)
			UmaSize = 1 << ((RegVal&0x3) + 2); //in unit of M
		else
			UmaSize = 1 << (RegVal + 5); //in unit of M
		DEBUG((EFI_D_ERROR,"Set IGD FB size = %x MB \n",UmaSize));
        
		//Mem space enable for MMIO
		GfxPciSave = AsiaPciRead8(CHX002_EUMA|0x04);
		AsiaPciModifySave8(CHX002_EUMA|0x04, BIT1, BIT1);

		/*
		//Setting for IO Cycle of UMA-START (for dual VGA = enable and UMA as secondary display device)		
		//D2F0~D5F0 Rx04 - save
		//set D2F0 Rx04[0] = 0
		DevIndex = 2;
		for(FunIndex = 0; FunIndex < 1; FunIndex++) 
		{
			if(AsiaPciRead8(ASIA_PCI_ADDRESS(CHX002_HB_BUS, DevIndex, FunIndex, 0)) != 0xFF)
			{
				RpPciSave[DevIndex-2][FunIndex] = AsiaPciRead8(ASIA_PCI_ADDRESS(CHX002_HB_BUS, DevIndex, FunIndex, 0x04));
				AsiaPciModifySave8(ASIA_PCI_ADDRESS(CHX002_HB_BUS, DevIndex, FunIndex, 0x04), BIT0, 0); 			
			}
		}
		//set D3F0 Rx04[0] = 0
		DevIndex = 3;
		for(FunIndex = 0; FunIndex < 4; FunIndex++) 
		{
			if(AsiaPciRead8(ASIA_PCI_ADDRESS(CHX002_HB_BUS, DevIndex, FunIndex, 0)) != 0xFF)
			{
				RpPciSave[DevIndex-2][FunIndex] = AsiaPciRead8(ASIA_PCI_ADDRESS(CHX002_HB_BUS, DevIndex, FunIndex, 0x04));
				AsiaPciModifySave8(ASIA_PCI_ADDRESS(CHX002_HB_BUS, DevIndex, FunIndex, 0x04), BIT0, 0); 			
			}
		}
		//set D4F0 Rx04[0] = 0
		DevIndex = 4;
		for(FunIndex = 0; FunIndex < 2; FunIndex++) 
		{
			if(AsiaPciRead8(ASIA_PCI_ADDRESS(CHX002_HB_BUS, DevIndex, FunIndex, 0)) != 0xFF)
			{
				RpPciSave[DevIndex-2][FunIndex] = AsiaPciRead8(ASIA_PCI_ADDRESS(CHX002_HB_BUS, DevIndex, FunIndex, 0x04));
				AsiaPciModifySave8(ASIA_PCI_ADDRESS(CHX002_HB_BUS, DevIndex, FunIndex, 0x04), BIT0, 0); 			
			}
		}
		//set D5F0 Rx04[0] = 0
		DevIndex = 5;
		for(FunIndex = 0; FunIndex < 2; FunIndex++) 
		{
			if(AsiaPciRead8(ASIA_PCI_ADDRESS(CHX002_HB_BUS, DevIndex, FunIndex, 0)) != 0xFF)
			{
				RpPciSave[DevIndex-2][FunIndex] = AsiaPciRead8(ASIA_PCI_ADDRESS(CHX002_HB_BUS, DevIndex, FunIndex, 0x04));
				AsiaPciModifySave8(ASIA_PCI_ADDRESS(CHX002_HB_BUS, DevIndex, FunIndex, 0x04), BIT0, 0); 			
			}
		}
		*/

		//RVGAEN - save
		Address = AsiaPciAddress(CHX002_HB_BUS, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_DDRPHY_CTL_MISC_CTL);
		RVGAENsave = AsiaPcieRead8(((ASIA_NB_CONFIGURATION *)(This->NbCfg))->PcieBar, Address);
		//set RVGAEN(Rx1F8[5]) = 1
		AsiaPcieModify8(((ASIA_NB_CONFIGURATION *)(This->NbCfg))->PcieBar, Address, D0F3_RVGAEN, D0F3_RVGAEN);

		//set D1F0 Rx04[0] = 1
		//AsiaPciModifySave8(CHX002_EUMA|0x04, BIT0, BIT0);
		//Setting for IO Cycle of UMA-END

		//enable GFX
		/*
		GfxIoSave1 = AsiaIoRead8(0x3C3);
		AsiaIoWriteSave8(0x3C3, GfxIoSave1|0x01);
		*/
		GfxIoSave1 = AsiaMemoryRead8(UMABar10+0x850C);
		AsiaMemoryModifySave8(UMABar10+0x850C, 0x02, 0x02);
		GfxIoSave2 = AsiaMemoryRead8(UMABar10+0x8AA0);
		AsiaMemoryModifySave8(UMABar10+0x8AA0, 0x02, 0x02);

		//Set CR38 = 48h, Unlocks accessing CR registers CR2D~3F
		/*
		AsiaIoWrite8(0x3D4, 0x38);
    	GfxIoSave3 = AsiaIoRead8(0x3D5);
		AsiaIoWriteSave16(0x3D4, 0x4838);
		*/
		GfxIoSave3 = AsiaMemoryRead8(UMABar10+0x8838);
		AsiaMemoryModifySave8(UMABar10+0x8838, 0xFF, 0x48);
		
		//Set CR39 = A5h, Unlocks accessing CR registers higher than CR40
		/*
		AsiaIoWrite8(0x3D4, 0x39);
    	GfxIoSave4 = AsiaIoRead8(0x3D5);
		AsiaIoWriteSave16(0x3D4, 0xA539);
		*/
		GfxIoSave4 = AsiaMemoryRead8(UMABar10+0x8839);
		AsiaMemoryModifySave8(UMABar10+0x8839, 0xFF, 0xA5);
		
        
		//Set SR08 = 06h, Unlocks accessing SR registers higher than SR09
		/*
		AsiaIoWrite8(0x3C4, 0x08);
    	GfxIoSave5 = AsiaIoRead8(0x3C5);
		AsiaIoWriteSave16(0x3C4, 0x0608);
		*/
		GfxIoSave5 = AsiaMemoryRead8(UMABar10+0x8608);
		AsiaMemoryModifySave8(UMABar10+0x8608, 0xFF, 0x06);
      
		//enable GFX access FB
		//Setup correct FB size to MXU register
		RegVal = 0;
		RegVal = ((((UmaSize/16) -1)<<24)&0xFF000000)|(0xFFFF<<8)|(((UmaSize/16) -1)&0xFF);
		AsiaMemoryModifySave32(UMABar10+0x490A0, 0xFFFFFFFF, RegVal);
		GfxFbSizeSave = AsiaMemoryRead32(UMABar10+0x490A0);
		DEBUG((EFI_D_ERROR,"UMA 0x490A0 = %x \n", GfxFbSizeSave));

		//Set CR_C_A0[4]=1 to Enable linear Addressing (G2M FB access enable)
		GfxFbAccessSave = AsiaMemoryRead8(UMABar10+0x8AA0);
		AsiaMemoryModifySave8(UMABar10+0x8AA0, BIT4, BIT4);
	  
		//------------------------------------------------------------------

		//Program Scratch Register(according to CND001)-START
		//Set SVID for D1F0
		SVID = AsiaPciRead32(CHX002_EUMA);
		AsiaMemoryWriteSave32(UMABar10 + 0x8A84, SVID);
		//Set SVID for D1F1, HDAudio
		SVID = AsiaPciRead32(CHX002_S3AC);
		AsiaMemoryWriteSave32(UMABar10 + 0x8A98, SVID);
		//AsiaMemoryWriteSave16(UMABar10 + 0x82D2, SVID);	
		//Program Scratch Register(according to CND001)-END

		//copy VCP
        DEBUG((EFI_D_ERROR,"%a(%d) PostPciInit -- VcpCopy \n",__FILE__,__LINE__));
        DEBUG((EFI_D_ERROR,"VcpFileBase = %x, VcpFileSize = %x \n", NbCfg->VcpFileBaseAddr, NbCfg->VcpFileSize));
	 	VcpCopy(NbCfg);

		//copy ShadowInfo
		GfxShadowInfo(NbCfg);

		//------------------------------------------------------------------
		
		//Gfx access FB - restore
		//AsiaMemoryModifySave8(UMABar10+0x8AA0, 0xFF, GfxFbAccessSave);
		//AsiaMemoryModifySave8(UMABar10+0x490A0, 0xFF, GfxFbSizeSave);
		//Gfx IO Reg - restore 
		/*
		AsiaIoWriteSave16(0x3C4, (GfxIoSave6<<8)|0x002A);
		AsiaIoWriteSave16(0x3C4, (GfxIoSave5<<8)|0x0008);
		AsiaIoWriteSave16(0x3D4, (GfxIoSave4<<8)|0x0039);
		AsiaIoWriteSave16(0x3D4, (GfxIoSave3<<8)|0x0038);
		AsiaIoWriteSave8(0x3C2, GfxIoSave2);
		AsiaIoWriteSave8(0x3C3, GfxIoSave1);
		
		AsiaMemoryModifySave8(UMABar10+0x862A, 0xFF, GfxIoSave6);
		AsiaMemoryModifySave8(UMABar10+0x8608, 0xFF, GfxIoSave5);
		AsiaMemoryModifySave8(UMABar10+0x8839, 0xFF, GfxIoSave4);
		AsiaMemoryModifySave8(UMABar10+0x8838, 0xFF, GfxIoSave3);
		AsiaMemoryModifySave8(UMABar10+0x83C2, 0xFF, GfxIoSave2);
		AsiaMemoryModifySave8(UMABar10+0x850C, 0xFF, GfxIoSave1);
		*/

		//D1F0 Rx04 - restore
		AsiaPciModifySave8(CHX002_EUMA|0x04, 0xFF, GfxPciSave);
		
		//RVGAEN - restore
		Address = AsiaPciAddress(CHX002_HB_BUS, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_DDRPHY_CTL_MISC_CTL);
		//set RVGAEN(Rx1F8[5]) = 1
		AsiaPcieModify8(((ASIA_NB_CONFIGURATION *)(This->NbCfg))->PcieBar, Address, D0F3_RVGAEN, RVGAENsave);

		/*
		//D2F0~D5F0 Rx04 - restore
		//set D2F0 Rx04[0]
		DevIndex = 2;
		for(FunIndex = 0; FunIndex < 1; FunIndex++) 
		{
			if(AsiaPciRead8(ASIA_PCI_ADDRESS(CHX002_HB_BUS, DevIndex, FunIndex, 0)) != 0xFF)
			{
				AsiaPciModifySave8(ASIA_PCI_ADDRESS(CHX002_HB_BUS, DevIndex, FunIndex, 0x04), 0xFF, RpPciSave[DevIndex-2][FunIndex]); 			
			}
		}
		//set D3F0 Rx04[0]
		DevIndex = 3;
		for(FunIndex = 0; FunIndex < 4; FunIndex++) 
		{
			if(AsiaPciRead8(ASIA_PCI_ADDRESS(CHX002_HB_BUS, DevIndex, FunIndex, 0)) != 0xFF)
			{
				AsiaPciModifySave8(ASIA_PCI_ADDRESS(CHX002_HB_BUS, DevIndex, FunIndex, 0x04), 0xFF, RpPciSave[DevIndex-2][FunIndex]); 
			}
		}
		//set D4F0 Rx04[0]
		DevIndex = 4;
		for(FunIndex = 0; FunIndex < 2; FunIndex++) 
		{
			if(AsiaPciRead8(ASIA_PCI_ADDRESS(CHX002_HB_BUS, DevIndex, FunIndex, 0)) != 0xFF)
			{
				AsiaPciModifySave8(ASIA_PCI_ADDRESS(CHX002_HB_BUS, DevIndex, FunIndex, 0x04), 0xFF, RpPciSave[DevIndex-2][FunIndex]); 
			}
		}
		//set D5F0 Rx04[0]
		DevIndex = 5;
		for(FunIndex = 0; FunIndex < 2; FunIndex++) 
		{
			if(AsiaPciRead8(ASIA_PCI_ADDRESS(CHX002_HB_BUS, DevIndex, FunIndex, 0)) != 0xFF)
			{
				AsiaPciModifySave8(ASIA_PCI_ADDRESS(CHX002_HB_BUS, DevIndex, FunIndex, 0x04), 0xFF, RpPciSave[DevIndex-2][FunIndex]); 
			}
		}
		*/

        break;

    case CHX002_S3AC:

        break;


    case CHX002_PE0:
        ProcessPcieBiosOption(NbCfg, CHX002_HB_BUS, CHX002_PE0_3_DEV, 0);
	 //ConfigPcieRPDoEq(NbCfg, CHX002_HB_BUS, CHX002_PE0_3_DEV, CHX002_PE0_FUN);
        break;

    case CHX002_PE1:
        ProcessPcieBiosOption(NbCfg, CHX002_HB_BUS, CHX002_PE0_3_DEV, 1);
	 //ConfigPcieRPDoEq(NbCfg, CHX002_HB_BUS, CHX002_PE0_3_DEV, CHX002_PE1_FUN);
        break;

    case CHX002_PE2:
        ProcessPcieBiosOption(NbCfg, CHX002_HB_BUS, CHX002_PE0_3_DEV, 2);
	 //ConfigPcieRPDoEq(NbCfg, CHX002_HB_BUS, CHX002_PE0_3_DEV, CHX002_PE2_FUN);
        break;

    case CHX002_PE3:
        ProcessPcieBiosOption(NbCfg, CHX002_HB_BUS, CHX002_PE0_3_DEV, 3);
	 //ConfigPcieRPDoEq(NbCfg, CHX002_HB_BUS, CHX002_PE0_3_DEV, CHX002_PE3_FUN);
        break;
		
    case CHX002_PE4:
        ProcessPcieBiosOption(NbCfg, CHX002_HB_BUS, CHX002_PE4_5_DEV, 0);
	 //ConfigPcieRPDoEq(NbCfg, CHX002_HB_BUS, CHX002_PE4_5_DEV, CHX002_PE4_FUN);
        break;
		
    case CHX002_PE5:
        ProcessPcieBiosOption(NbCfg, CHX002_HB_BUS, CHX002_PE4_5_DEV, 1);
	 //ConfigPcieRPDoEq(NbCfg, CHX002_HB_BUS, CHX002_PE4_5_DEV, CHX002_PE5_FUN);
        break;
		
    case CHX002_PE6:
        ProcessPcieBiosOption(NbCfg, CHX002_HB_BUS, CHX002_PE6_7_DEV, 0);
	 //ConfigPcieRPDoEq(NbCfg, CHX002_HB_BUS, CHX002_PE6_7_DEV, CHX002_PE6_FUN);
        break;
		
    case CHX002_PE7:
        ProcessPcieBiosOption(NbCfg, CHX002_HB_BUS, CHX002_PE6_7_DEV, 1);
	 //ConfigPcieRPDoEq(NbCfg, CHX002_HB_BUS, CHX002_PE6_7_DEV, CHX002_PE7_FUN);
        break;

#ifdef ZX_DUALSOCKET
	//#ifdef DUAL_SOCKET_CODE
	case CHX002_PE0_SLAVE:
		ProcessPcieBiosOption(NbCfg, CHX002_SLAVE_BUS, CHX002_PE0_SLAVE_3_DEV, 0);
	 //ConfigPcieRPDoEq(NbCfg, CHX002_SLAVE_BUS, CHX002_PE0_SLAVE_3_DEV, CHX002_PE0_SLAVE_FUN);
		break;

	case CHX002_PE1_SLAVE:
		ProcessPcieBiosOption(NbCfg, CHX002_SLAVE_BUS, CHX002_PE0_SLAVE_3_DEV, 1);
	 //ConfigPcieRPDoEq(NbCfg, CHX002_SLAVE_BUS, CHX002_PE0_SLAVE_3_DEV, CHX002_PE1_SLAVE_FUN);
		break;

	case CHX002_PE2_SLAVE:
		ProcessPcieBiosOption(NbCfg, CHX002_SLAVE_BUS, CHX002_PE0_SLAVE_3_DEV, 2);
	 //ConfigPcieRPDoEq(NbCfg, CHX002_SLAVE_BUS, CHX002_PE0_SLAVE_3_DEV, CHX002_PE2_SLAVE_FUN);
		break;

	case CHX002_PE3_SLAVE:
		ProcessPcieBiosOption(NbCfg, CHX002_SLAVE_BUS, CHX002_PE0_SLAVE_3_DEV, 3);
	 //ConfigPcieRPDoEq(NbCfg, CHX002_SLAVE_BUS, CHX002_PE0_SLAVE_3_DEV, CHX002_PE3_SLAVE_FUN);
		break;
		
	case CHX002_PE4_SLAVE:
		ProcessPcieBiosOption(NbCfg, CHX002_SLAVE_BUS, CHX002_PE4_SLAVE_5_DEV, 0);
	 //ConfigPcieRPDoEq(NbCfg, CHX002_SLAVE_BUS, CHX002_PE4_SLAVE_5_DEV, CHX002_PE4_SLAVE_FUN);
		break;
		
	case CHX002_PE5_SLAVE:
		ProcessPcieBiosOption(NbCfg, CHX002_SLAVE_BUS, CHX002_PE4_SLAVE_5_DEV, 1);
	 //ConfigPcieRPDoEq(NbCfg, CHX002_SLAVE_BUS, CHX002_PE4_SLAVE_5_DEV, CHX002_PE5_SLAVE_FUN);
		break;
		
	case CHX002_PE6_SLAVE:
		ProcessPcieBiosOption(NbCfg, CHX002_SLAVE_BUS, CHX002_PE6_SLAVE_7_DEV, 0);
	 //ConfigPcieRPDoEq(NbCfg, CHX002_SLAVE_BUS, CHX002_PE6_SLAVE_7_DEV, CHX002_PE6_SLAVE_FUN);
		break;
		
	case CHX002_PE7_SLAVE:
		ProcessPcieBiosOption(NbCfg, CHX002_SLAVE_BUS, CHX002_PE6_SLAVE_7_DEV, 1);
	 //ConfigPcieRPDoEq(NbCfg, CHX002_SLAVE_BUS, CHX002_PE6_SLAVE_7_DEV, CHX002_PE7_SLAVE_FUN);
		break;
#endif


    default:
        break;
    }

    //detect external GFX card
    if (Bus > 0) {
        ClassCode = AsiaPciRead16(AsiaPciAddress((UINT8)Bus, (UINT8)Device, (UINT8)Function, 0x0A));
        if (ClassCode == 0x0300) {
            ExternalVgaLocation = AsiaPciAddress((UINT8)Bus, (UINT8)Device, (UINT8)Function, 0x00);
            if (NbCfg->UMAEn && (NbCfg->PrimaryGraphicAdapter == PCIE_PCI_UMA)){
				//CHX001-LGE-20150601
				Address = AsiaPciAddress(CHX002_HB_BUS, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_DDRPHY_CTL_MISC_CTL);
	            AsiaPcieModify8(NbCfg->PcieBar, Address, D0F3_RVGAEN, 0);
				//CHX001-LGE-20150601
            }
            AsiaPciWrite8(CHX002_EUMA|0x04,0x06);
        }
    }

    return EFI_SUCCESS;
}

/**
  Function description.
  
  @param  PeiServices	EFI_PEI_SERVICES pointer.
  @param NbCfg Point to ASIA_NB_CONFIGURATION struct.

  @return EFI_STATUS.

**/

VOID UmaDisable(UINT64 Bar)
{
    UINT64 Address;
	
    //Disable UMA
	Address = AsiaPciAddress(CHX002_HB_BUS, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_CPU_DIRECT_ACCESS_FRAME_BUFFER_CTL_Z1);
	AsiaPcieModify32(Bar, Address, D0F3_RGFXEN|D0F3_RFBSZ_2_0, 0);

    //disable UMA IO port
    Address = AsiaPciAddress(CHX002_HB_BUS, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_DDRPHY_CTL_MISC_CTL);
	AsiaPcieModify8(Bar, Address, D0F3_RVGAEN, 0);
	//<--------------UmaDisable-End-------------->
}
//lna_err_debug-start
/**
  Function description.
  
  @param  PeiServices	EFI_PEI_SERVICES pointer.
  @param NbCfg Point to ASIA_NB_CONFIGURATION struct.

  @return EFI_STATUS.

**/

EFI_STATUS
NbSerrInit(    
    IN ASIA_NB_CONFIGURATION *NbCfg,
    IN ASIA_SB_CONFIGURATION *SbCfg
)
{
	UINT64						PcieBase;
	UINT16						Pmio;    
	UINT64 						RcrbhBase;
	   
    PcieBase = NbCfg->PcieBar;
	Pmio = SbCfg->PmioBar;
	RcrbhBase = NbCfg->RcrbhBar;
	//AsiaPcieModify8(PcieBase, CHX002_PE4|((UINT64)D3D5F1_PCIE_ROOT_PORT_ERR_CTL_D4F0 << 32), D3D5F1_RPEERREN, D3D5F1_RPEERREN);		//PCIE SERR_NB Sent to SB Control
	AsiaMemoryModify8(RcrbhBase +RCRBH_PCIE_ROOT_PORT_ERR_CTL ,RCRBH_RPEERREN,RCRBH_RPEERREN);//PCIE SERR_NB Sent to SB Control - CJW_20170612


    //;Enable SERR_NB Mechanism according to Setup-Item
    switch(NbCfg->SERRNBControl)
    {
        case ERR_Disable:
			//AsiaPcieModify8(PcieBase, CHX002_PE4|((UINT64)RCRBH_PCIE_ROOT_PORT_ERR_CTL << 32), RCRBH_RPEERREN, 0);		//PCIE SERR_NB Sent to SB Control
			AsiaMemoryModify8(RcrbhBase +RCRBH_PCIE_ROOT_PORT_ERR_CTL ,RCRBH_RPEERREN,0);//PCIE SERR_NB Sent to SB Control - CJW_20170612
			AsiaIoModify8(Pmio + PMIO_GENERAL_PURPOSE_SMI_ENABLE, PMIO_NB2SB_SMI_SM, 0x00);	//Disable NB2SB_SMI Path
			AsiaIoModify8(Pmio + PMIO_GENERAL_PURPOSE_SCI_ENABLE, PMIO_NB2SB_SCI_SC, 0x00);	//Disable NB2SB_SCI Path			
			AsiaIoModify8(0X70,BIT7, BIT7);
			break;						
        case ERR_SMI:	
			AsiaIoModify8(Pmio + PMIO_GENERAL_PURPOSE_SMI_ENABLE, PMIO_NB2SB_SMI_SM, PMIO_NB2SB_SMI_SM);	//Enable NB2SB_SMI Path
			AsiaIoModify8(Pmio + PMIO_GENERAL_PURPOSE_SCI_ENABLE, PMIO_NB2SB_SCI_SC, 0x00);	//Disable NB2SB_SCI Path			
			AsiaIoModify8(0X70,BIT7, BIT7);
			break;
        case ERR_NMI:
			AsiaIoModify8(Pmio + PMIO_GENERAL_PURPOSE_SMI_ENABLE, PMIO_NB2SB_SMI_SM, 0x00);	//Disable NB2SB_SMI Path
			AsiaIoModify8(Pmio + PMIO_GENERAL_PURPOSE_SCI_ENABLE, PMIO_NB2SB_SCI_SC, 0x00);	//Disable NB2SB_SCI Path			
			AsiaIoModify8(0X70,BIT7, 0);
			break;
        case ERR_SCI:
			AsiaIoModify8(Pmio + PMIO_GENERAL_PURPOSE_SMI_ENABLE, PMIO_NB2SB_SMI_SM, 0x00);	//Disable NB2SB_SMI Path
			AsiaIoModify8(Pmio + PMIO_GENERAL_PURPOSE_SCI_ENABLE, PMIO_NB2SB_SCI_SC, PMIO_NB2SB_SCI_SC);	//Enable NB2SB_SCI Path			
			AsiaIoModify8(0X70,BIT7, BIT7);
			break;			
	 	default:
			//; Impossible Case; do nothing
			break;		
    } 
	DEBUG((EFI_D_ERROR, "(qlp)NbCfg->SERRNBControl=0%x \n",NbCfg->SERRNBControl));	//Enable NB2SB_SMI Path
	DEBUG((EFI_D_ERROR, "(qlp)NbSerrInit pmio RxCC=0%x \n",AsiaIoRead8(Pmio + PMIO_GENERAL_PURPOSE_SMI_ENABLE)));	//Enable NB2SB_SMI Path
	//DEBUG((EFI_D_ERROR, "(qlp)Rx211 =0%x \n",AsiaPcieRead8(PcieBase, CHX002_PE4|((UINT64)D3D5F1_PCIE_ROOT_PORT_ERR_CTL_D4F0 << 32))));	//Enable NB2SB_SMI Path
	DEBUG((EFI_D_ERROR, "(cjw)RCRBH_Rx2A1 =0%x \n",AsiaMemoryRead8(RcrbhBase +RCRBH_PCIE_ROOT_PORT_ERR_CTL)));	//Enable NB2SB_SMI Path - CJW_20170612	
	return EFI_SUCCESS;
}




//LGE20161202 Add for Save DRAMC IOTiming to FLASH---S



#define NVINFO_IO_VAR_NAME           L"IOTIMING"
#define NVINFO_IO_VAR_ATTRIBUTE      (EFI_VARIABLE_BOOTSERVICE_ACCESS | EFI_VARIABLE_NON_VOLATILE)
EFI_GUID gAsiaIoTimingInfoGuid = { 0xe1c2c2a6, 0x2cd0, 0x4834, { 0xa5, 0x4e, 0x61, 0xae, 0x6c, 0x2e, 0x9f, 0xa7 }};
EFI_GUID gAsiaDramInfoSaveGuid = { 0xe1c2c2a6, 0x2cd0, 0x4834, { 0xa6, 0x4e, 0x62, 0xae, 0x6A, 0x2e, 0x96, 0xa7 }};

/**
  Function description.
  
  @param  PeiServices	EFI_PEI_SERVICES pointer.
  @param NbCfg Point to ASIA_NB_CONFIGURATION struct.

  @return EFI_STATUS.

**/

VOID SaveIoTimingVariable()
{
////
#if 1
    EFI_STATUS             Status;
    IO_TIMING   *IoTimingData;
	DRAM_INFO_SAVE *DramInfoSave;
    UINT16 RegIndex = 0;
	UINT16 Index = 0;
    UINT64 Address;

   
    EFI_HOB_GENERIC_HEADER *HobList;
    EFI_GUID EfiHobListGuid = EFI_HOB_LIST_GUID;    
	EFI_GUID AsiaDramAttrGuid = ASIA_DRAM_ATTR_HOB_GUID;
    VOID* pDramAttr = NULL;
    DRAM_ATTRIBUTE *DramAttr;
    gBS->AllocatePool(EfiBootServicesData, sizeof(DRAM_INFO_SAVE), &DramInfoSave);
    gBS->AllocatePool(EfiBootServicesData, sizeof(IO_TIMING), &IoTimingData);
	
    Status = EfiLibGetSystemConfigurationTable(&EfiHobListGuid, &HobList);
    if(!EFI_ERROR(Status))
        Status = GetNextGuidHob(&HobList, &AsiaDramAttrGuid, &pDramAttr, NULL);

    DramAttr = (DRAM_ATTRIBUTE *)pDramAttr;
	
    DramInfoSave->DramFreq= DramAttr->ConfigData.DramClk;
	//DramInfoSave->WPREA = DramAttr->WPREA;
	//DramInfoSave->RPREA = DramAttr->RPREA;
	DramInfoSave->DramFastBoot = DramAttr->ConfigData.DramFastBoot;
    DramInfoSave->TxIoTimingMethod = DramAttr->ConfigData.TxIoTimingMethod;
    DramInfoSave->RxIoTimingMethod = DramAttr->ConfigData.RxIoTimingMethod;
    DramInfoSave->RxVref = DramAttr->ConfigData.RxVref;
    DramInfoSave->TxVref = DramAttr->ConfigData.TxVref;
    DramInfoSave->DramECC = DramAttr->ConfigData.DRAMECC;
	DramInfoSave->DQSIByRank = DramAttr->ConfigData.DQSIByRank;
	DramInfoSave->TxVrefAllByte = DramAttr->ConfigData.TxVrefAllByte;
	DramInfoSave->MemoryChipODTDebug = DramAttr->ConfigData.MemoryChipODTDebug;
	DramInfoSave->MemoryChipODTWRDebug = DramAttr->ConfigData.MemoryChipODTWRDebug;
	DramInfoSave->MemoryChipODTParkDebug = DramAttr->ConfigData.MemoryChipODTParkDebug;


    DEBUG((EFI_D_ERROR|EFI_D_ERROR, "DramClock = %02x--LGE DEBUG\n", DramInfoSave->DramFreq));



    if((DramAttr->DramFastBoot == DRAM_FAST_BOOT_DISABLE) && (DramAttr->ConfigData.DramFastBoot == DRAM_FAST_BOOT_AUTO)){
		DEBUG((EFI_D_ERROR|EFI_D_ERROR, "Begin to Save DramInfo\n"));
		for (Index = 0; Index < ASIA_MAX_DIMMS; Index++) {			
		
			//LGE20160630 Get DIMM Manufacturer  Info
			DramInfoSave->MfrInfo[0][Index].MFR_ID = DramAttr->MfrInfo[0][Index].MFR_ID; 			                                  
			DramInfoSave->MfrInfo[0][Index].SERIAL_NO = DramAttr->MfrInfo[0][Index].SERIAL_NO;

			DEBUG((EFI_D_ERROR|EFI_D_ERROR, "DIMM%02x SERIALNO:%08x:\n",Index, DramAttr->MfrInfo[0][Index].SERIAL_NO));	
		
			}

		Status = gRT->SetVariable (
					NVINFO_DRAMINFO_VAR_NAME,
					&gAsiaDramInfoSaveGuid,
					NVINFO_IO_VAR_ATTRIBUTE,
					sizeof(DRAM_INFO_SAVE),
					DramInfoSave
					);
		ASSERT(!EFI_ERROR(Status));

		DEBUG((EFI_D_ERROR|EFI_D_ERROR, "Save DramInfo success\n"));


		DEBUG((EFI_D_ERROR|EFI_D_ERROR, "Begin to Save IO Timing\n"));
		//RX
		//TNI 0x46C-0x4BA
		for(RegIndex = 0x46C, Index = 0; RegIndex <= 0x4BA; RegIndex += 2, Index++)
		{
			Address = AsiaPciAddress(CHX002_HB_BUS, CHX002_HB_DEV, CHX002_DRAM_FUN, RegIndex);
			IoTimingData->TNIVAL[Index] = AsiaPcieRead16(0xE0000000, Address);
		}
		//DQSI 0x4FC-0x97A
		for(RegIndex = 0x4FC, Index = 0; RegIndex <= 0x97A; RegIndex += 2, Index++)
		{
			Address = AsiaPciAddress(CHX002_HB_BUS, CHX002_HB_DEV, CHX002_DRAM_FUN, RegIndex);
			IoTimingData->DQSIVAL[Index] = AsiaPcieRead16(0xE0000000, Address);
		}
		//RXWholeT 0xA0C-0xA3A
		for(RegIndex = 0xA0C, Index = 0; RegIndex <= 0xA3A; RegIndex += 2, Index++)
		{
			Address = AsiaPciAddress(CHX002_HB_BUS, CHX002_HB_DEV, CHX002_DRAM_FUN, RegIndex);
			IoTimingData->RXWholeT[Index] = AsiaPcieRead16(0xE0000000, Address);
		}
		//RXVREF  0xA98-0xB02 
		for(RegIndex = 0xA98, Index = 0; RegIndex <= 0xB02; RegIndex += 2, Index++)
		{
			Address = AsiaPciAddress(CHX002_HB_BUS, CHX002_HB_DEV, CHX002_DRAM_FUN, RegIndex);
			IoTimingData->RxVref[Index] = AsiaPcieRead16(0xE0000000, Address);
		}
		//TX	
		//DQSO Phase 0x438-0x44A
		for(RegIndex = 0x438, Index = 0; RegIndex <= 0x44A; RegIndex += 2, Index++)
		{
			Address = AsiaPciAddress(CHX002_HB_BUS, CHX002_HB_DEV, CHX002_DRAM_FUN, RegIndex);
			IoTimingData->DQSOPhase[Index] = AsiaPcieRead16(0xE0000000, Address);
		}
		//DQO Phase 0x424-0x436
		for(RegIndex = 0x424, Index = 0; RegIndex <= 0x436; RegIndex += 2, Index++)
		{
			Address = AsiaPciAddress(CHX002_HB_BUS, CHX002_HB_DEV, CHX002_DRAM_FUN, RegIndex);
			IoTimingData->DQOPhase[Index] = AsiaPcieRead16(0xE0000000, Address);
		}
		//TXWholeT 0xA3C-0xA4E
		for(RegIndex = 0xA3C, Index = 0; RegIndex <= 0xA4E; RegIndex += 2, Index++)
		{
			Address = AsiaPciAddress(CHX002_HB_BUS, CHX002_HB_DEV, CHX002_DRAM_FUN, RegIndex);
			IoTimingData->TXWholeT[Index] = AsiaPcieRead16(0xE0000000, Address);
		}
		//TXVREF
		for(Index = 0; Index <= 7; Index++){
			IoTimingData->TxVref[Index] = DramAttr->TxVrefInfo[Index].TxVrefCENTER;// temporarily
		}
		IoTimingData->CHAOverlap = DramAttr->CHAOverlap;
		IoTimingData->CHBOverlap = DramAttr->CHBOverlap;
		IoTimingData->CHACoarseMode = DramAttr->CHACoarseMode;
		IoTimingData->CHBCoarseMode = DramAttr->CHBCoarseMode;	
	
		Status = gRT->SetVariable (
						NVINFO_IO_VAR_NAME,
						&gAsiaIoTimingInfoGuid,
						NVINFO_IO_VAR_ATTRIBUTE,
						sizeof(IO_TIMING),
						IoTimingData
						);
		ASSERT(!EFI_ERROR(Status));

		DEBUG((EFI_D_ERROR|EFI_D_ERROR, "Save IO Timing success\n"));
   }


	{
	UINT16 RDMBCOTF;	
	//Address =AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_DRAMC_REQ_REORDER_CTL_I_DRAM_REQ_CTL);
	//if(DramAttr->ConfigData.WriteMerge)
		//AsiaPcieModify16(DramAttr->PcieBaseAddress, Address, D0F3_RWMERGEEN, D0F3_RWMERGEEN);
	//else
		//AsiaPcieModify16(DramAttr->PcieBaseAddress, Address, D0F3_RWMERGEEN, 0);


	//Address =AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_MERGE_RELATED_CTL);
    //if(DramAttr->ConfigData.RMWCTL)
		//AsiaPcieModify8(DramAttr->PcieBaseAddress, Address, D0F3_RMWCTL3|D0F3_RMWCTL0,D0F3_RMWCTL3|D0F3_RMWCTL0);
	//else
		//AsiaPcieModify8(DramAttr->PcieBaseAddress, Address,D0F3_RMWCTL3|D0F3_RMWCTL0,0);


	//Design limitation Item 5 +S
	Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_MERGE_RELATED_CTL);
	if((AsiaPcieRead16(DramAttr->PcieBaseAddress, Address) & D0F3_RMWCTL0) == 0x0)  //disable GFX RMW
	{
		Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_PAD_CTL_DRAM_DATA_BURST_CTL);
		RDMBCOTF = AsiaPcieRead16(DramAttr->PcieBaseAddress, Address);

		if (RDMBCOTF & D0F3_RDMBCOTF)  //if  RDMBCOTF == 1
		{
			Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_DRAMC_REQ_REORDER_CTL_I_DRAM_REQ_CTL);
			AsiaPcieModify16(DramAttr->PcieBaseAddress, Address, D0F3_RWMERGEEN, 0);	//RWMERGEEN = 0
		}
	}
	//Design limitation Item 5 +S
}

#endif	
}

//LGE20161202 Add for Save DRAMC IOTiming to FLASH---E

/**
  Function description.
  
  @param  PeiServices	EFI_PEI_SERVICES pointer.
  @param NbCfg Point to ASIA_NB_CONFIGURATION struct.

  @return EFI_STATUS.

**/

void EccClearDram3(ASIA_NB_CONFIGURATION *NbCfg)
{
	UINT32 clocks1=0,clocks2=0;
	UINT64 i,j,Buf;
	UINT64 DramEnd;
	UINT64 Address;

	/*Address = AsiaPciAddress(CHX002_HB_BUS, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_DRAM_ENDING_ADR);*/
    /*DramEnd = AsiaPcieRead16(NbCfg->PcieBar, Address)& D0F3_REND7_37_24;*/
	/*DramEnd <<= 4;*/
	Address = AsiaPciAddress(CHX002_HB_BUS, CHX002_HB_DEV, CHX002_HIF_FUN, D0F2_HIGHEST_SVAD_LIMIT_TARGET_TO_MEM_DRAM_LIMIT_ADR_OVER_4G);
    DramEnd = (UINT64)((AsiaPcieRead32(NbCfg->PcieBar, Address) & D0F2_RTOPA_39_20)>>12);			
	//Clear Mem
	if(DramEnd > 4096){
		DEBUG((EFI_D_ERROR,"Clear Memory 4GB~%dMB\n", DramEnd));

		//record clocks1
		clocks1 = AsiaIoRead32(0x808);

		//Clear Memory by setting every 64 bytes
		for(i = 4096; i < DramEnd; i++)
		{
			Buf = MultU64x32(i, 0x100000);
			for(j=Buf;j<Buf+0x100000;j+=4)
			{
				AsiaMemoryWrite32(j, 0);
			}
		}

		//record clocks2
		clocks2 = AsiaIoRead32(0x808); 


		DEBUG((EFI_D_ERROR, "clocks1 = %08x\n", clocks1));
		DEBUG((EFI_D_ERROR, "clocks2 = %08x\n", clocks2));
		DEBUG((EFI_D_ERROR, "TIME = %08x\n", clocks2-clocks1));
		DEBUG((EFI_D_ERROR, "Clear Done\n"));

		//Clear ECC staus
		Address = AsiaPciAddress(CHX002_HB_BUS, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_ECC_CTL_1_ECC_ERR_STA);
		while(AsiaPcieRead16(NbCfg->PcieBar, Address) & (D0F3_RMEFS_CHB | D0F3_RSEFS_CHB |D0F3_RMEFS_CHA |D0F3_RSEFS_CHA))
		{
			DEBUG((EFI_D_ERROR, "*"));
			AsiaPcieModify16(NbCfg->PcieBar, Address, D0F3_RMEFS_CHB | D0F3_RSEFS_CHB |D0F3_RMEFS_CHA |D0F3_RSEFS_CHA, D0F3_RMEFS_CHB | D0F3_RSEFS_CHB |D0F3_RMEFS_CHA |D0F3_RSEFS_CHA);
		}	
		DEBUG((EFI_D_ERROR, "\n\r"));
	}
}

/**
  Function description.
  
  @param  PeiServices	EFI_PEI_SERVICES pointer.
  @param NbCfg Point to ASIA_NB_CONFIGURATION struct.

  @return EFI_STATUS.

**/

EFI_STATUS AsiaNbDxePreBootInit (
    IN EFI_ASIA_NB_PROTOCOL *This
)
{
    ASIA_NB_CONFIGURATION *NbCfg;
    ASIA_SB_CONFIGURATION *SbCfg;
    EFI_ASIA_SB_PROTOCOL    *pSb;
    EFI_STATUS            Status;
    EFI_GUID AsiaSbCfgGuid = EFI_ASIA_SB_PROTOCOL_GUID;
    UINT8 RankPresent =0, DRAMSupportSnoopOnly = 0;
    UINT64 Address;

	DEBUG((EFI_D_ERROR|EFI_D_ERROR, "AsiaNbDxePreBootInit\n"));
    NbCfg = (ASIA_NB_CONFIGURATION*)(This->NbCfg);

    Status = gBS->LocateProtocol(&AsiaSbCfgGuid, NULL, &pSb);
    if (EFI_ERROR(Status)) {
        return Status;
    }
    SbCfg = (ASIA_SB_CONFIGURATION*) pSb->SbCfg;

	DEBUG((EFI_D_ERROR|EFI_D_ERROR, "NbCfg->UMAEn\n"));

	//JRZ-20180326
	//dose the DRAM configuration support snoop only mode?
	DRAMSupportSnoopOnly = AsiaPciRead8(CHX002_SCRCH|0x4F) & BIT2;

	//D0F4_RxA1[4] should be set when IOV and UMA are both enabled. 
	//Report G2M Access DVAD Error when Support GFX_Snoop_mode_only	
	if(NbCfg->IOVEnable && NbCfg->UMAEn && DRAMSupportSnoopOnly)
	{
		AsiaPcieModifySave8(NbCfg->PcieBar, AsiaPciAddress(CHX002_HB_BUS,CHX002_HB_DEV,CHX002_NPMC_FUN, D0F4_GMINT_REG_1), D0F4_RGMISNPOEN, D0F4_RGMISNPOEN);
#ifdef ZX_DUALSOCKET
		AsiaPcieModifySave8(NbCfg->PcieBar, AsiaPciAddress(NbCfg->ZxeSlaveBusNum,CHX002_HB_DEV,CHX002_NPMC_FUN, D0F4_GMINT_REG_1), D0F4_RGMISNPOEN, D0F4_RGMISNPOEN);
#endif

		DEBUG((EFI_D_ERROR|EFI_D_ERROR, "[JRZ]UMAEn can be enabled with the current DRAM configuration supporting snoop only mode and abort mechanism enabled.\n"));
	}
	//Scratch register(D0F6Rx4F[2])cleared indicates that current DRAM configuration can not support snoop only mode.
	//So the UMA should be disabled if IOV is enabled and D0F6Rx4F[2] is cleared.
	else if(NbCfg->IOVEnable && NbCfg->UMAEn && !DRAMSupportSnoopOnly)
	{
		//report an error code 0x74 and CPU executes a dead loop, add by jerry 20180518
	 	AsiaIoWrite8(0x80,0x74);
	 	DEBUG((EFI_D_ERROR, "[JRZ]POSTCODE=<%02x>\n", AsiaIoRead8(0x80)));
	 	DEBUG((EFI_D_ERROR, "[JRZ]Current DRAM configuration can not support snoop only mode, BIOS now stops booting with TACTL and UMA both enabled.\n"));
	 	DEBUG((EFI_D_ERROR, "[JRZ]Try PCIE graphics card and boot again.\n"));
		EFI_DEADLOOP();

		NbCfg->UMAEn = FALSE;
		
		//if UMA is disabled, the abort mechanism can also be disabled.
		AsiaPcieModifySave8(NbCfg->PcieBar, AsiaPciAddress(CHX002_HB_BUS,CHX002_HB_DEV,CHX002_NPMC_FUN, D0F4_GMINT_REG_1), D0F4_RGMISNPOEN, 0);	
#ifdef ZX_DUALSOCKET
		AsiaPcieModifySave8(NbCfg->PcieBar, AsiaPciAddress(NbCfg->ZxeSlaveBusNum,CHX002_HB_DEV,CHX002_NPMC_FUN, D0F4_GMINT_REG_1), D0F4_RGMISNPOEN, 0);
#endif

		DEBUG((EFI_D_ERROR|EFI_D_ERROR, "[JRZ]UMAEn will be disabled due to the current DRAM configuration can not support snoop only mode.\n"));
	}
	
    if(NbCfg->UMAEn)
    {
        EFI_PHYSICAL_ADDRESS HDAudioBar;
        UINT8   SaveControl;

        SaveControl = AsiaPciRead8(CHX002_EUMA|0x04);
        AsiaPciModifySave8(CHX002_EUMA|0x04, 0x06, 0x06);

        //after VBIOS, add NB HDMI setting
        //get MMIO base address, bus0 dev1 fun0 Rx13~10
        HDAudioBar = AsiaPciRead32(CHX002_EUMA|0x10) & (~0x0F);
		//For codec1:
		if(!(NbCfg->DisableHDAC1)){
			AsiaMemoryWriteSave32(HDAudioBar + 0x8380, 0x0001C000);
			AsiaMemoryWriteSave32(HDAudioBar + 0x82E0, 0x001E07F0);
			AsiaMemoryWriteSave32(HDAudioBar + 0x82EC, 0x00006201);
			AsiaMemoryWriteSave32(HDAudioBar + 0x82F0, 0x00407381);
			AsiaMemoryWriteSave32(HDAudioBar + 0x82F4, 0x08000094);
			AsiaMemoryWriteSave32(HDAudioBar + 0x82F8, 0x18564030);
			AsiaMemoryWriteSave32(HDAudioBar + 0x8350, 0x76543210);
			AsiaMemoryWriteSave32(HDAudioBar + 0x837C, 0x0);
			AsiaMemoryWriteSave32(HDAudioBar + 0x82A0, 0x00000010);
		}
		else{
			AsiaMemoryWriteSave32(HDAudioBar + 0x82A0, 0);
		}
		//For codec2:
		if(!(NbCfg->DisableHDAC2)){
			AsiaMemoryWriteSave32(HDAudioBar + 0x33120, 0x0);	
			AsiaMemoryWriteSave32(HDAudioBar + 0x33080, 0x001E07F0);
			AsiaMemoryWriteSave32(HDAudioBar + 0x3308C, 0x00006201);
			AsiaMemoryWriteSave32(HDAudioBar + 0x33090, 0x00407381);
			AsiaMemoryWriteSave32(HDAudioBar + 0x33094, 0x08000094);
			AsiaMemoryWriteSave32(HDAudioBar + 0x33098, 0x18564030);
			AsiaMemoryWriteSave32(HDAudioBar + 0x330F0, 0x76543210);
			AsiaMemoryWriteSave32(HDAudioBar + 0x3311C, 0x0);
			AsiaMemoryWriteSave32(HDAudioBar + 0x33040, 0x00000010);
		}
		else{
			AsiaMemoryWriteSave32(HDAudioBar + 0x33040, 0);
		}
        // if UMA and external GFX coexist
        if (ExternalVgaLocation != 0) {
            //external GFX as primary display device, UMA as secondary
            if (NbCfg->PrimaryGraphicAdapter == PCIE_PCI_UMA) {

                AsiaPciWriteSave8(CHX002_EUMA|0x04,0x06);

	            if(NbCfg->DualVGA==0)
	            {
	                if((AsiaPciRead16(CHX002_EUMA|0x00)!=0xFFFF) && (AsiaPciRead16(CHX002_EUMA|0x02)!=0xFFFF))
	                {	               
	                    Address = AsiaPciAddress(CHX002_HB_BUS, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_DDRPHY_CTL_MISC_CTL);
	                    AsiaPcieModifySave8(NbCfg->PcieBar, Address, D0F3_RVGAEN, D0F3_RVGAEN);	                  
						UmaDisable(NbCfg->PcieBar);
					}
	            }
            }
            //UMA as primary display, external GFX as secondary
            else {
				if(NbCfg->DualVGA==0){
					AsiaPciWriteSave8(ExternalVgaLocation|0x04,0x00);
				}
                
            }
        }
        //only exist UMA
        else {
            AsiaPciWriteSave8(CHX002_EUMA|0x04,SaveControl);
        }
    }

	DEBUG((EFI_D_ERROR|EFI_D_ERROR, "C5Control\n"));

    if (SbCfg->C5Control) {
        PROCESS_NB_R6408M_TABLE_SAVE(C5EnableBeforePCI, sizeof(C5EnableBeforePCI)/sizeof(ASIA_IO_TABLE_6408_REV));
    }
    else {
        PROCESS_NB_R6408M_TABLE_SAVE(C5DisableBeforePCI, sizeof(C5DisableBeforePCI)/sizeof(ASIA_IO_TABLE_6408_REV));
    }

	DEBUG((EFI_D_ERROR|EFI_D_ERROR, "DramSelfRefresh\n"));

	// Set self refresh
	if (NbCfg->DramSelfRefresh)
	{
		DEBUG((EFI_D_ERROR|EFI_D_ERROR, "DKS-DramSelfRefresh\n"));
		//CS_n can go to float state when rank_n is not present.
		Address = AsiaPciAddress(CHX002_HB_BUS, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_PAD_CTL_DRAM_DATA_BURST_CTL);
		RankPresent = (UINT8)((AsiaPcieRead16(NbCfg->PcieBar, Address) & 0xFF00) >> 8);

		//Enable pair-wise and set to auto refreshes.
		Address = AsiaPciAddress(CHX002_HB_BUS, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_PM_DURING_SELF_REFRESH_BY_RANK_SELF_REFRESH_RELATED_REGS_III);
        AsiaPcieModifySave16(NbCfg->PcieBar, Address, D0F3_RENTERREF_2_0, 0x10);


        //DRAMC limitation Item 14 +s Enable by rank self-refresh  RSFREFRKxEN = 0xFF
		Address = AsiaPciAddress(CHX002_HB_BUS, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_BY_RANK_SELF_REFRESH_RELATED_REGS_II_I);
        //AsiaPcieWriteSave8(NbCfg->PcieBar, Address, RankPresent);
        AsiaPcieWriteSave8(NbCfg->PcieBar, Address, 0xFF);

		//DRAMC limitation Item 14 +e Enable by rank self-refresh  RSFREFRKxEN = 0xFF

		DEBUG((EFI_D_ERROR|EFI_D_ERROR, "DramSelfRefresh - 2\n"));

		//CHA		
	    //LGE20170508 SET 0 AS Designer  recommend	
		Address = AsiaPciAddress(CHX002_HB_BUS, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_BY_RANK_SELF_REFRESH_RELATED_REGS_II_I);
		AsiaPcieModifySave16(NbCfg->PcieBar, Address, D0F3_RREFGFX_RK3 | 
													  D0F3_RREFPMU_RK3 | 
													  D0F3_RREFGFX_RK2 | 
													  D0F3_RREFPMU_RK2 | 
													  D0F3_RREFGFX_RK1 |
													  D0F3_RREFPMU_RK1 |
													  D0F3_RREFGFX_RK0 |
													  D0F3_RREFPMU_RK0 , 0x00);

		//CHB		
		//LGE20170508 SET 0 AS Designer  recommend
        Address = AsiaPciAddress(CHX002_HB_BUS, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_BY_RANK_AUTO_REFRESH_CTL_BY_RANK_SELF_REFRESH_RELATED_REGS_II);
		AsiaPcieWriteSave8(NbCfg->PcieBar, Address, 0x00);

	//	DEBUG((EFI_D_ERROR|EFI_D_ERROR, "DramSelfRefresh - 3\n"));

    //    Address = AsiaPciAddress(CHX002_HB_BUS, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_PM_DURING_SELF_REFRESH_BY_RANK_SELF_REFRESH_RELATED_REGS_III); 
   //     AsiaPcieModifySave16(NbCfg->PcieBar, Address, D0F3_RPAIRREFOUT, D0F3_RPAIRREFOUT);
		
	    DEBUG((EFI_D_ERROR|EFI_D_ERROR, "DramSelfRefresh - 4\n"));

		// Set D0F4_Rx97, Enable Self-Refresh in C3/C4 state
		AsiaPciModifySave8( CHX002_NPMC|D0F4_NEW_PMU_FUN_CTL_Z1, D0F4_RC3SRFEN|D0F4_RC4SRFEN, D0F4_RC3SRFEN|D0F4_RC4SRFEN);


		//LGE20161208 Disable auto refresh in selfrefresh mode		
		//Address = AsiaPciAddress(CHX002_HB_BUS, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_DRAM_REQ_CTL);
        //AsiaPcieModifySave8(NbCfg->PcieBar, Address, BIT7, BIT7);
	}
	
	NbSerrInit(NbCfg, SbCfg);


	PcieEyeMonitorDbg(NbCfg);



    //LGE20161202 Save DRAMC IOTiming to FLASH
    
   
	SaveIoTimingVariable();

	// Modify PLL14318 DIVN value to adjust PLL14318 frequency.
	AsiaPciModifySave8 (CHX002_NPMC|D0F4_SB_PLL14318_CTL_3,    D0F4_RPLL14318DIVN_7_0, 0x84);  // D0F4 RxC7=0x84;
	AsiaPciModifySave16(CHX002_NPMC|D0F4_SB_PLL14318_CTL_3_Z1, D0F4_RPLL14318DIVN_19_8, 0x0E0F); // D0F4 RxC8[11:0]=0x0E0F;

    AsiaPciWriteSave32((CHX002_HIF|D0F2_VGA_DECODING), AsiaPciRead32(CHX002_HIF|D0F2_VGA_DECODING));
    AsiaPciWriteSave8((CHX002_HIF|D0F2_TPR_CTL), AsiaPciRead8(CHX002_HIF|D0F2_TPR_CTL));

#if 0
    //RKD-20180823 Clear DRAM FOR ECC
	Address = AsiaPciAddress(CHX002_HB_BUS, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_ECC_CTL_1_ECC_ERR_STA);
   //Judge ECC Enable or NOT
   if((AsiaPcieRead16(NbCfg->PcieBar, Address) & D0F3_RECCEN) != 0){
	   EccClearDram3(NbCfg);
   }
#endif
    return EFI_SUCCESS;
}
