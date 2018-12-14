/** @file
   ZX-E(CHX002) Asia SbDxe library functions : IoeDxeInit.c

   Copyright (c) 2018 Shanghai Zhaoxin Semiconductor Co., Ltd. 

**/

//**************************************************************************
//**************************************************************************
//**                                                                      **
//**  Copyright (c) 2015 - 2017 Shanghai Zhaoxin Semiconductor Co., Ltd.  **
//**                                                                      **
//**************************************************************************
//**************************************************************************

//CJW-20160905_01   Update the resource assigment strategy for all previous codes



#include "EfiCommon.h"
//#include "AsiaSbDxe.h"
#include "AsiaIoSaveLib.h"
#include "CHX002Cfg.h"
#include "CHX002Reg.h"
#include EFI_PROTOCOL_DEFINITION(PciHostBridgeResourceAllocation)
#include EFI_PROTOCOL_DEFINITION(PciIo)
#include "EfiDriverLib.h"
#include EFI_GUID_DEFINITION(Hob)
#include "EfiHobLib.h"

#include "EfiBootScript.h"
#include "EfiScriptLib.h"

//#include "Protocol\AsiaSbProtocol\AsiaSbProtocol.h"
//#include "HdAc.h"
#include "AsiaCommon.h" //define ASIA_XXX_CFG_HOB_GUID

#include "IoeDxeInit.h"

//#ifdef PCIE_ACPI_SHPC_SUPPORT_IOE
//#define PCAL6416A_PCIE_HOTPLUG_SUPPORT_IOE    1
//#endif


RpList MbRpTblList[] = IOE_SEARCH_TABLE;



STATIC ASIA_IO_TABLE_6432_REV IOE_BusXD0F0_PerformanceTBL_MMIO[]={
	{0x00,	0xFF,	(CND003_PEEP|((UINT64)0x1a0<<32)),	0x10,	0x10},

	{0x00,	0xFF,	(CND003_PEEP|((UINT64)0x1a4<<32)),	0x2041a,	0x1a},

	{0x00,	0xFF,	(CND003_PEEP|((UINT64)0x1b0<<32)),	0x7100003,	0x100003},

	{0x00,	0xFF,	(CND003_PEEP|((UINT64)0x1b4<<32)),	0x3f000007,	0x2b000001},

	{0x00,	0xFF,	(CND003_PEEP|((UINT64)0x1cc<<32)),	0x30100,	0x30100},

	{0x00,	0xFF,	(CND003_PEEP|((UINT64)0x1d0<<32)),	0xffff0000,	0xffff0000},

	{0x00,	0xFF,	(CND003_PEEP|((UINT64)0x1e0<<32)),	0x40ff0000,	0x40030000},

	{0xFF,	0x00,	0x00,	0x00,	0x00}
};
STATIC ASIA_IO_TABLE_6432_REV IOE_BusXD0F0_EnergyTBL_MMIO[]={
	{0x00,	0xFF,	(CND003_PEEP|((UINT64)0x1a0<<32)),	0x10,	0x10},

	{0x00,	0xFF,	(CND003_PEEP|((UINT64)0x1a4<<32)),	0x10,	0x10},

	{0x00,	0xFF,	(CND003_PEEP|((UINT64)0x1b0<<32)),	0x10000,	0x10000},

	{0x00,	0xFF,	(CND003_PEEP|((UINT64)0x1d0<<32)),	0xffff0000,	0x0},

	{0x00,	0xFF,	(CND003_PEEP|((UINT64)0x1e0<<32)),	0x48ff0000,	0x8300000},

	{0x00,	0xFF,	(CND003_PEEP|((UINT64)0x1e8<<32)),	0x3c,	0x3c},

	{0x00,	0xFF,	(CND003_PEEP|((UINT64)0x230<<32)),	0x102ffff,	0x102ffff},

	{0xFF,	0x00,	0x00,	0x00,	0x00}
};
STATIC ASIA_IO_TABLE_6432_REV IOE_BusXMmioIsb_PerformanceTBL_MMIO[]={
	{0xFF,	0x00,	0x00,	0x00,	0x00}
};
STATIC ASIA_IO_TABLE_6432_REV IOE_BusXMmioIsb_EnergyTBL_MMIO[]={
	{0xFF,	0x00,	0x00,	0x00,	0x00}
};
STATIC ASIA_IO_TABLE_6432_REV IOE_BusXp1D0F0_PerformanceTBL_MMIO[]={
	{0x00,	0xFF,	(CND003_XBCTL|((UINT64)0x80<<32)),	0x1,	0x0},

	{0x00,	0xFF,	(CND003_XBCTL|((UINT64)0x8c<<32)),	0x40000000,	0x0},

	{0xFF,	0x00,	0x00,	0x00,	0x00}
};
STATIC ASIA_IO_TABLE_6432_REV IOE_BusXp1D0F0_EnergyTBL_MMIO[]={
	{0x00,	0xFF,	(CND003_XBCTL|((UINT64)0x40<<32)),	0x4,	0x4},  //Rx40[2] Dynamic clock
	
	{0x00,	0xFF,	(CND003_XBCTL|((UINT64)0x80<<32)),	0x1,	0x0},

	{0x00,	0xFF,	(CND003_XBCTL|((UINT64)0x8c<<32)),	0x40000000,	0x0},

	{0xFF,	0x00,	0x00,	0x00,	0x00}
};

STATIC ASIA_IO_TABLE_6432_REV IOE_BusXp1D1F0_PerformanceTBL_MMIO[]={
//	{0x00,	0xFF,	(CND003_PEA0|((UINT64)0x70<<32)),	0x1,	0x0},

	{0x00,	0xFF,	(CND003_PEA0|((UINT64)0x1a0<<32)),	0xc0000,	0x80000},

	{0x00,	0xFF,	(CND003_PEA0|((UINT64)0x1a4<<32)),	0x2,	0x2},

	{0x00,	0xFF,	(CND003_PEA0|((UINT64)0x1b0<<32)),	0x7100003,	0x100003},

	{0x00,	0xFF,	(CND003_PEA0|((UINT64)0x1b4<<32)),	0x3f000007,	0x2b000001},

	{0x00,	0xFF,	(CND003_PEA0|((UINT64)0x1cc<<32)),	0x100,	0x100},

	{0x00,	0xFF,	(CND003_PEA0|((UINT64)0x1d0<<32)),	0xffff0000,	0xffff0000},

	{0x00,	0xFF,	(CND003_PEA0|((UINT64)0x1e0<<32)),	0x40ff0000,	0x40030000},

	{0xFF,	0x00,	0x00,	0x00,	0x00}
};
STATIC ASIA_IO_TABLE_6432_REV IOE_BusXp1D1F0_EnergyTBL_MMIO[]={
//	{0x00,	0xFF,	(CND003_PEA0|((UINT64)0x70<<32)),	0x1,	0x0},

	{0x00,	0xFF,	(CND003_PEA0|((UINT64)0x1a0<<32)),	0x40000,	0x0},

	{0x00,	0xFF,	(CND003_PEA0|((UINT64)0x1b0<<32)),	0x10000,	0x10000},

	{0x00,	0xFF,	(CND003_PEA0|((UINT64)0x1cc<<32)),	0x800,	0x800},

	{0x00,	0xFF,	(CND003_PEA0|((UINT64)0x1d0<<32)),	0xffff0000,	0x0},

	{0x00,	0xFF,	(CND003_PEA0|((UINT64)0x1e0<<32)),	0x48ff0000,	0x8300000},

	{0x00,	0xFF,	(CND003_PEA0|((UINT64)0x1e8<<32)),	0x3c,	0x3c},

	{0x00,	0xFF,	(CND003_PEA0|((UINT64)0x230<<32)),	0x102ffff,	0x102ffff},

	{0x00,	0xFF,	(CND003_PEA0|((UINT64)0x234<<32)),	0x70,	0x70},

	{0xFF,	0x00,	0x00,	0x00,	0x00}
};

STATIC ASIA_IO_TABLE_6432_REV IOE_BusXp1D2F0_PerformanceTBL_MMIO[]={
	{0x00,	0xFF,	(CND003_PEA1|((UINT64)0x1a0<<32)),	0xc0000,	0x80000},

	{0x00,	0xFF,	(CND003_PEA1|((UINT64)0x1a4<<32)),	0x2,	0x2},

	{0x00,	0xFF,	(CND003_PEA1|((UINT64)0x1b0<<32)),	0x7100003,	0x100003},

	{0x00,	0xFF,	(CND003_PEA1|((UINT64)0x1b4<<32)),	0x3f000007,	0x2b000001},

	{0x00,	0xFF,	(CND003_PEA1|((UINT64)0x1cc<<32)),	0x100,	0x100},

	{0x00,	0xFF,	(CND003_PEA1|((UINT64)0x1d0<<32)),	0xffff0000,	0xffff0000},

	{0x00,	0xFF,	(CND003_PEA1|((UINT64)0x1e0<<32)),	0x40ff0000,	0x40030000},

	{0xFF,	0x00,	0x00,	0x00,	0x00}
};
STATIC ASIA_IO_TABLE_6432_REV IOE_BusXp1D2F0_EnergyTBL_MMIO[]={
	{0x00,	0xFF,	(CND003_PEA1|((UINT64)0x1a0<<32)),	0x40000,	0x0},

	{0x00,	0xFF,	(CND003_PEA1|((UINT64)0x1b0<<32)),	0x10000,	0x10000},

	{0x00,	0xFF,	(CND003_PEA1|((UINT64)0x1cc<<32)),	0x800,	0x800},

	{0x00,	0xFF,	(CND003_PEA1|((UINT64)0x1d0<<32)),	0xffff0000,	0x0},

	{0x00,	0xFF,	(CND003_PEA1|((UINT64)0x1e0<<32)),	0x48ff0000,	0x8300000},

	{0x00,	0xFF,	(CND003_PEA1|((UINT64)0x1e8<<32)),	0x3c,	0x3c},

	{0x00,	0xFF,	(CND003_PEA1|((UINT64)0x230<<32)),	0x102ffff,	0x102ffff},

	{0xFF,	0x00,	0x00,	0x00,	0x00}
};
STATIC ASIA_IO_TABLE_6432_REV IOE_BusXp1D3F0_PerformanceTBL_MMIO[]={
	{0x00,	0xFF,	(CND003_PEA2|((UINT64)0x1a0<<32)),	0xc0000,	0x80000},

	{0x00,	0xFF,	(CND003_PEA2|((UINT64)0x1a4<<32)),	0x2,	0x2},

	{0x00,	0xFF,	(CND003_PEA2|((UINT64)0x1b0<<32)),	0x7100003,	0x100003},

	{0x00,	0xFF,	(CND003_PEA2|((UINT64)0x1b4<<32)),	0x3f000007,	0x2b000001},

	{0x00,	0xFF,	(CND003_PEA2|((UINT64)0x1cc<<32)),	0x100,	0x100},

	{0x00,	0xFF,	(CND003_PEA2|((UINT64)0x1d0<<32)),	0xffff0000,	0xffff0000},

	{0x00,	0xFF,	(CND003_PEA2|((UINT64)0x1e0<<32)),	0x40ff0000,	0x40030000},

	{0xFF,	0x00,	0x00,	0x00,	0x00}
};
STATIC ASIA_IO_TABLE_6432_REV IOE_BusXp1D3F0_EnergyTBL_MMIO[]={
	{0x00,	0xFF,	(CND003_PEA2|((UINT64)0x1a0<<32)),	0x40000,	0x0},

	{0x00,	0xFF,	(CND003_PEA2|((UINT64)0x1b0<<32)),	0x10000,	0x10000},

	{0x00,	0xFF,	(CND003_PEA2|((UINT64)0x1cc<<32)),	0x800,	0x800},

	{0x00,	0xFF,	(CND003_PEA2|((UINT64)0x1d0<<32)),	0xffff0000,	0x0},

	{0x00,	0xFF,	(CND003_PEA2|((UINT64)0x1e0<<32)),	0x48ff0000,	0x8300000},

	{0x00,	0xFF,	(CND003_PEA2|((UINT64)0x1e8<<32)),	0x3c,	0x3c},

	{0x00,	0xFF,	(CND003_PEA2|((UINT64)0x230<<32)),	0x102ffff,	0x102ffff},

	{0xFF,	0x00,	0x00,	0x00,	0x00}
};
STATIC ASIA_IO_TABLE_6432_REV IOE_BusXp1D4F0_PerformanceTBL_MMIO[]={
	{0x00,	0xFF,	(CND003_PEA3|((UINT64)0x1a0<<32)),	0xc0000,	0x80000},

	{0x00,	0xFF,	(CND003_PEA3|((UINT64)0x1a4<<32)),	0x2,	0x2},

	{0x00,	0xFF,	(CND003_PEA3|((UINT64)0x1b0<<32)),	0x7100003,	0x100003},

	{0x00,	0xFF,	(CND003_PEA3|((UINT64)0x1b4<<32)),	0x3f000007,	0x2b000001},

	{0x00,	0xFF,	(CND003_PEA3|((UINT64)0x1cc<<32)),	0x100,	0x100},

	{0x00,	0xFF,	(CND003_PEA3|((UINT64)0x1d0<<32)),	0xffff0000,	0xffff0000},

	{0x00,	0xFF,	(CND003_PEA3|((UINT64)0x1e0<<32)),	0x40ff0000,	0x40030000},

	{0xFF,	0x00,	0x00,	0x00,	0x00}
};
STATIC ASIA_IO_TABLE_6432_REV IOE_BusXp1D4F0_EnergyTBL_MMIO[]={
	{0x00,	0xFF,	(CND003_PEA3|((UINT64)0x1a0<<32)),	0x40000,	0x0},

	{0x00,	0xFF,	(CND003_PEA3|((UINT64)0x1b0<<32)),	0x10000,	0x10000},

	{0x00,	0xFF,	(CND003_PEA3|((UINT64)0x1cc<<32)),	0x800,	0x800},

	{0x00,	0xFF,	(CND003_PEA3|((UINT64)0x1d0<<32)),	0xffff0000,	0x0},

	{0x00,	0xFF,	(CND003_PEA3|((UINT64)0x1e0<<32)),	0x48ff0000,	0x8300000},

	{0x00,	0xFF,	(CND003_PEA3|((UINT64)0x1e8<<32)),	0x3c,	0x3c},

	{0x00,	0xFF,	(CND003_PEA3|((UINT64)0x230<<32)),	0x102ffff,	0x102ffff},

	{0xFF,	0x00,	0x00,	0x00,	0x00}
};
STATIC ASIA_IO_TABLE_6432_REV IOE_BusXp1D5F0_PerformanceTBL_MMIO[]={
	{0x00,	0xFF,	(CND003_PEA4|((UINT64)0x1a0<<32)),	0xc0000,	0x80000},

	{0x00,	0xFF,	(CND003_PEA4|((UINT64)0x1a4<<32)),	0x2,	0x2},

	{0x00,	0xFF,	(CND003_PEA4|((UINT64)0x1b0<<32)),	0x7100003,	0x100003},

	{0x00,	0xFF,	(CND003_PEA4|((UINT64)0x1b4<<32)),	0x3f000007,	0x2b000001},

	{0x00,	0xFF,	(CND003_PEA4|((UINT64)0x1cc<<32)),	0x100,	0x100},

	{0x00,	0xFF,	(CND003_PEA4|((UINT64)0x1d0<<32)),	0xffff0000,	0xffff0000},

	{0x00,	0xFF,	(CND003_PEA4|((UINT64)0x1e0<<32)),	0x40ff0000,	0x40030000},

	{0xFF,	0x00,	0x00,	0x00,	0x00}
};
STATIC ASIA_IO_TABLE_6432_REV IOE_BusXp1D5F0_EnergyTBL_MMIO[]={
	{0x00,	0xFF,	(CND003_PEA4|((UINT64)0x1a0<<32)),	0x40000,	0x0},

	{0x00,	0xFF,	(CND003_PEA4|((UINT64)0x1b0<<32)),	0x10000,	0x10000},

	{0x00,	0xFF,	(CND003_PEA4|((UINT64)0x1cc<<32)),	0x800,	0x800},

	{0x00,	0xFF,	(CND003_PEA4|((UINT64)0x1d0<<32)),	0xffff0000,	0x0},

	{0x00,	0xFF,	(CND003_PEA4|((UINT64)0x1e0<<32)),	0x48ff0000,	0x8300000},

	{0x00,	0xFF,	(CND003_PEA4|((UINT64)0x1e8<<32)),	0x3c,	0x3c},

	{0x00,	0xFF,	(CND003_PEA4|((UINT64)0x230<<32)),	0x102ffff,	0x102ffff},

	{0xFF,	0x00,	0x00,	0x00,	0x00}
};
STATIC ASIA_IO_TABLE_6432_REV IOE_BusXp1D6F0_PerformanceTBL_MMIO[]={
	{0x00,	0xFF,	(CND003_PEB0|((UINT64)0x1a0<<32)),	0xc0000,	0x80000},

	{0x00,	0xFF,	(CND003_PEB0|((UINT64)0x1a4<<32)),	0x2,	0x2},

	{0x00,	0xFF,	(CND003_PEB0|((UINT64)0x1b0<<32)),	0x7100003,	0x100003},

	{0x00,	0xFF,	(CND003_PEB0|((UINT64)0x1b4<<32)),	0x3f000007,	0x2b000001},

	{0x00,	0xFF,	(CND003_PEB0|((UINT64)0x1cc<<32)),	0x100,	0x100},

	{0x00,	0xFF,	(CND003_PEB0|((UINT64)0x1d0<<32)),	0xffff0000,	0xffff0000},

	{0x00,	0xFF,	(CND003_PEB0|((UINT64)0x1e0<<32)),	0x40ff0000,	0x40030000},

	{0xFF,	0x00,	0x00,	0x00,	0x00}
};
STATIC ASIA_IO_TABLE_6432_REV IOE_BusXp1D6F0_EnergyTBL_MMIO[]={
	{0x00,	0xFF,	(CND003_PEB0|((UINT64)0x1a0<<32)),	0x40000,	0x0},

	{0x00,	0xFF,	(CND003_PEB0|((UINT64)0x1b0<<32)),	0x10000,	0x10000},

	{0x00,	0xFF,	(CND003_PEB0|((UINT64)0x1cc<<32)),	0x800,	0x800},

	{0x00,	0xFF,	(CND003_PEB0|((UINT64)0x1d0<<32)),	0xffff0000,	0x0},

	{0x00,	0xFF,	(CND003_PEB0|((UINT64)0x1e0<<32)),	0x48ff0000,	0x8300000},

	{0x00,	0xFF,	(CND003_PEB0|((UINT64)0x1e8<<32)),	0x3c,	0x3c},

	{0x00,	0xFF,	(CND003_PEB0|((UINT64)0x230<<32)),	0x102ffff,	0x102ffff},

	{0xFF,	0x00,	0x00,	0x00,	0x00}
};
STATIC ASIA_IO_TABLE_6432_REV IOE_BusXp1D7F0_PerformanceTBL_MMIO[]={
	{0x00,	0xFF,	(CND003_PEB1|((UINT64)0x1a0<<32)),	0xc0000,	0x80000},

	{0x00,	0xFF,	(CND003_PEB1|((UINT64)0x1a4<<32)),	0x2,	0x2},

	{0x00,	0xFF,	(CND003_PEB1|((UINT64)0x1b0<<32)),	0x7100003,	0x100003},

	{0x00,	0xFF,	(CND003_PEB1|((UINT64)0x1b4<<32)),	0x3f000007,	0x2b000001},

	{0x00,	0xFF,	(CND003_PEB1|((UINT64)0x1cc<<32)),	0x100,	0x100},

	{0x00,	0xFF,	(CND003_PEB1|((UINT64)0x1d0<<32)),	0xffff0000,	0xffff0000},

	{0x00,	0xFF,	(CND003_PEB1|((UINT64)0x1e0<<32)),	0x40ff0000,	0x40030000},

	{0xFF,	0x00,	0x00,	0x00,	0x00}
};
STATIC ASIA_IO_TABLE_6432_REV IOE_BusXp1D7F0_EnergyTBL_MMIO[]={
	{0x00,	0xFF,	(CND003_PEB1|((UINT64)0x1a0<<32)),	0x40000,	0x0},

	{0x00,	0xFF,	(CND003_PEB1|((UINT64)0x1b0<<32)),	0x10000,	0x10000},

	{0x00,	0xFF,	(CND003_PEB1|((UINT64)0x1cc<<32)),	0x800,	0x800},

	{0x00,	0xFF,	(CND003_PEB1|((UINT64)0x1d0<<32)),	0xffff0000,	0x0},

	{0x00,	0xFF,	(CND003_PEB1|((UINT64)0x1e0<<32)),	0x48ff0000,	0x8300000},

	{0x00,	0xFF,	(CND003_PEB1|((UINT64)0x1e8<<32)),	0x3c,	0x3c},

	{0x00,	0xFF,	(CND003_PEB1|((UINT64)0x230<<32)),	0x102ffff,	0x102ffff},

	{0xFF,	0x00,	0x00,	0x00,	0x00}
};
STATIC ASIA_IO_TABLE_6432_REV IOE_BusXp1D8F0_PerformanceTBL_MMIO[]={
	{0xFF,	0x00,	0x00,	0x00,	0x00}
};
STATIC ASIA_IO_TABLE_6432_REV IOE_BusXp1D8F0_EnergyTBL_MMIO[]={
	{0xFF,	0x00,	0x00,	0x00,	0x00}
};
STATIC ASIA_IO_TABLE_6432_REV IOE_BusXp2D0F0_PerformanceTBL_MMIO[]={
	{0xFF,	0x00,	0x00,	0x00,	0x00}
};
STATIC ASIA_IO_TABLE_6432_REV IOE_BusXp2D0F0_EnergyTBL_MMIO[]={
	{0x00,	0xFF,	(CND003_PCIEIF|((UINT64)0x190<<32)),	0x3ff,	0x3ff},

	{0x00,	0xFF,	(CND003_PCIEIF|((UINT64)0x198<<32)),	0xff,	0xff},

	{0xFF,	0x00,	0x00,	0x00,	0x00}
};
STATIC ASIA_IO_TABLE_6432_REV IOE_BusXp3D0F0_PerformanceTBL_MMIO[]={
	{0x00,	0xFF,	(CND003_EPTRFC|((UINT64)0x60<<32)),	0x10000,	0x10000},

	{0xFF,	0x00,	0x00,	0x00,	0x00}
};
STATIC ASIA_IO_TABLE_6432_REV IOE_BusXp3D0F0_EnergyTBL_MMIO[]={
	{0x00,	0xFF,	(CND003_EPTRFC|((UINT64)0x8c<<32)),	0xdeff00,	0xdeff00},

	{0xFF,	0x00,	0x00,	0x00,	0x00}
};
STATIC ASIA_IO_TABLE_6432_REV IOE_BusXp3D0F0_SHADOW_PerformanceTBL_MMIO[]={
	{0xFF,	0x00,	0x00,	0x00,	0x00}
};
STATIC ASIA_IO_TABLE_6432_REV IOE_BusXp3D0F0_SHADOW_EnergyTBL_MMIO[]={
	{0xFF,	0x00,	0x00,	0x00,	0x00}
};


/**
  Function description.
  
  @param  PeiServices	EFI_PEI_SERVICES pointer.
  @param SbCfg Point to ASIA_SB_CONFIGURATION struct.

  @return EFI_STATUS.

**/

VOID
IoeDumpMemDxe(
	UINT32 MemBase, 
	UINT16 DCount)
{

	UINT16 offsetx = 0;
	UINT8 readback8;
	DEBUG((EFI_D_ERROR, "[CJW_IOE] IoeDumpMem(Base:0x%08x, Count:0x%04x):\n",MemBase, DCount));
	DEBUG((EFI_D_ERROR, "\n0x%04x: ",offsetx+1));
	for(offsetx = 0; offsetx < DCount; offsetx++){
		readback8 = AsiaMemoryRead8(MemBase + offsetx);
		DEBUG((EFI_D_ERROR, "%02X ",readback8));
		if(offsetx != (DCount -1)){
			if((offsetx & 0xFF) == 0xFF){
				DEBUG((EFI_D_ERROR, "\n\n        00 01 02 03 04 05 06 07 08 09 0A 0B 0C 0D 0E 0F"));
				DEBUG((EFI_D_ERROR, "\n        -----------------------------------------------"));
			}
		}	
		if((offsetx & 0xF) == 0xF){
			DEBUG((EFI_D_ERROR, "\n0x%04x: ",offsetx+1));
		}
		
	}
	DEBUG((EFI_D_ERROR, "\n"));
}

/**
  Function description.
  
  @param  PeiServices	EFI_PEI_SERVICES pointer.
  @param SbCfg Point to ASIA_SB_CONFIGURATION struct.

  @return EFI_STATUS.

**/

VOID
IoeDumpCfgDxe(
	UINT64 PcieBase,
	UINT8 Busx,
	UINT8 Devx, 
	UINT8 Funx, 
	UINT16 DCount)
{

	UINT16 offsetx = 0;
	UINT8 readback8;
	DEBUG((EFI_D_ERROR, "[CJW_IOE] IoeDumpCfg([%d|%d|%d] Count:0x%08x):\n",Busx,Devx,Funx,DCount));
	DEBUG((EFI_D_ERROR, "\n0x%04x: ",offsetx+1));
	for(offsetx = 0; offsetx < DCount; offsetx++){
		readback8 = AsiaPcieRead8(PcieBase, AsiaPciAddress(Busx, Devx, Funx, offsetx));
		DEBUG((EFI_D_ERROR, "%02X ",readback8));
		if(offsetx != (DCount -1)){
			if((offsetx & 0xFF) == 0xFF){
				DEBUG((EFI_D_ERROR, "\n\n        00 01 02 03 04 05 06 07 08 09 0A 0B 0C 0D 0E 0F"));
				DEBUG((EFI_D_ERROR, "\n        -----------------------------------------------"));
			}
		}
		if((offsetx & 0xF) == 0xF){
			DEBUG((EFI_D_ERROR, "\n0x%04x: ",offsetx+1));
		}
		
	}
	DEBUG((EFI_D_ERROR, "\n"));
}


/**
  Function description.
  
  @param  PeiServices	EFI_PEI_SERVICES pointer.
  @param SbCfg Point to ASIA_SB_CONFIGURATION struct.

  @return EFI_STATUS.

**/

STATIC
EFI_STATUS
IoeDumpSPEReCheck(
	ASIA_NB_CONFIGURATION *NbCfg,
	ASIA_IO_TABLE_6432_REV *target, 
	UINT8 ItemCounts,
	char *messages)
{
	UINT8 count = 0;
	UINT8 items = 0;
	UINT32 flagx;
	UINT32 flagy;
	DEBUG((EFI_D_ERROR, "[CJW_IOE] ===>> %a:\n", messages));
	for(items = 0; items < ItemCounts; items++){
		for(count = 0; count <= 31; count++){
			flagx = (((target[items].Mask)>>count) & BIT0);
			if(flagx != 0){
				flagy = (((target[items].Value)>>count)&BIT0);
				DEBUG((EFI_D_ERROR, "   Rx%04x[%d] = %d \n",(UINT16)(0xFFFF&(target[items].Address>>32)), count, flagy));
			}
						
		}
	}
	return EFI_SUCCESS;
}

/**
  Function description.
  
  @param  PeiServices	EFI_PEI_SERVICES pointer.
  @param SbCfg Point to ASIA_SB_CONFIGURATION struct.

  @return EFI_STATUS.

**/

VOID
IoeSpeSettingInit(ASIA_NB_CONFIGURATION *NbCfg)
{
	
	switch(NbCfg->IOESPEValue){
    case CHIP_SPE_VALUE_MANUAL:
        break;
    case CHIP_SPE_VALUE_PERFORMANCE:
		NbCfg->IOEXSPEValue = DEVICE_SPE_VALUE_PERFORMANCE;
  		NbCfg->IOEXSPEValue = DEVICE_SPE_VALUE_PERFORMANCE;
  		NbCfg->IOEXp1D0F0SPEValue = DEVICE_SPE_VALUE_PERFORMANCE;
  		NbCfg->IOEXp1D1F0SPEValue = DEVICE_SPE_VALUE_PERFORMANCE;
  		NbCfg->IOEXp1D2F0SPEValue = DEVICE_SPE_VALUE_PERFORMANCE;
  		NbCfg->IOEXp1D3F0SPEValue = DEVICE_SPE_VALUE_PERFORMANCE;
  		NbCfg->IOEXp1D4F0SPEValue = DEVICE_SPE_VALUE_PERFORMANCE;
  		NbCfg->IOEXp1D5F0SPEValue = DEVICE_SPE_VALUE_PERFORMANCE;
 	 	NbCfg->IOEXp1D6F0SPEValue = DEVICE_SPE_VALUE_PERFORMANCE;
  		NbCfg->IOEXp1D7F0SPEValue = DEVICE_SPE_VALUE_PERFORMANCE;
  		NbCfg->IOEXp1D8F0SPEValue = DEVICE_SPE_VALUE_PERFORMANCE;
  		NbCfg->IOEXp2D0F0SPEValue = DEVICE_SPE_VALUE_PERFORMANCE;
  		NbCfg->IOEXp3D0F0SPEValue = DEVICE_SPE_VALUE_PERFORMANCE;
  		NbCfg->IOEEphySPEValue = DEVICE_SPE_VALUE_PERFORMANCE;
  		NbCfg->IOEMmioISBSPEValue = DEVICE_SPE_VALUE_PERFORMANCE;
        break;
    case CHIP_SPE_VALUE_ENERGY:
		NbCfg->IOEXSPEValue = DEVICE_SPE_VALUE_ENERGY;
  		NbCfg->IOEXSPEValue = DEVICE_SPE_VALUE_ENERGY;
  		NbCfg->IOEXp1D0F0SPEValue = DEVICE_SPE_VALUE_ENERGY;
  		NbCfg->IOEXp1D1F0SPEValue = DEVICE_SPE_VALUE_ENERGY;
  		NbCfg->IOEXp1D2F0SPEValue = DEVICE_SPE_VALUE_ENERGY;
  		NbCfg->IOEXp1D3F0SPEValue = DEVICE_SPE_VALUE_ENERGY;
  		NbCfg->IOEXp1D4F0SPEValue = DEVICE_SPE_VALUE_ENERGY;
  		NbCfg->IOEXp1D5F0SPEValue = DEVICE_SPE_VALUE_ENERGY;
 	 	NbCfg->IOEXp1D6F0SPEValue = DEVICE_SPE_VALUE_ENERGY;
  		NbCfg->IOEXp1D7F0SPEValue = DEVICE_SPE_VALUE_ENERGY;
  		NbCfg->IOEXp1D8F0SPEValue = DEVICE_SPE_VALUE_ENERGY;
  		NbCfg->IOEXp2D0F0SPEValue = DEVICE_SPE_VALUE_ENERGY;
  		NbCfg->IOEXp3D0F0SPEValue = DEVICE_SPE_VALUE_ENERGY;
  		NbCfg->IOEEphySPEValue = DEVICE_SPE_VALUE_ENERGY;
  		NbCfg->IOEMmioISBSPEValue = DEVICE_SPE_VALUE_ENERGY;		
        break;
    case CHIP_SPE_VALUE_STABLE:
	default:
		NbCfg->IOEXSPEValue = DEVICE_SPE_VALUE_STABLE;
  		NbCfg->IOEXSPEValue = DEVICE_SPE_VALUE_STABLE;
  		NbCfg->IOEXp1D0F0SPEValue = DEVICE_SPE_VALUE_STABLE;
  		NbCfg->IOEXp1D1F0SPEValue = DEVICE_SPE_VALUE_STABLE;
  		NbCfg->IOEXp1D2F0SPEValue = DEVICE_SPE_VALUE_STABLE;
  		NbCfg->IOEXp1D3F0SPEValue = DEVICE_SPE_VALUE_STABLE;
  		NbCfg->IOEXp1D4F0SPEValue = DEVICE_SPE_VALUE_STABLE;
  		NbCfg->IOEXp1D5F0SPEValue = DEVICE_SPE_VALUE_STABLE;
 	 	NbCfg->IOEXp1D6F0SPEValue = DEVICE_SPE_VALUE_STABLE;
  		NbCfg->IOEXp1D7F0SPEValue = DEVICE_SPE_VALUE_STABLE;
  		NbCfg->IOEXp1D8F0SPEValue = DEVICE_SPE_VALUE_STABLE;
  		NbCfg->IOEXp2D0F0SPEValue = DEVICE_SPE_VALUE_STABLE;
  		NbCfg->IOEXp3D0F0SPEValue = DEVICE_SPE_VALUE_STABLE;
  		NbCfg->IOEEphySPEValue = DEVICE_SPE_VALUE_STABLE;
  		NbCfg->IOEMmioISBSPEValue = DEVICE_SPE_VALUE_STABLE;			
	}
	
	//Set S/P/E flag to D0F6Rx42[1:0]
	AsiaPciModifySave8(HOST_SCRATCH|D0F6_BIOS_SCRATCH_REG_1 + 2, 0X03, NbCfg->IOESPEValue);
	//;Rx42[7:4]: Scratch record revision
	AsiaPciModifySave8(HOST_SCRATCH|D0F6_BIOS_SCRATCH_REG_1 + 2, 0XF0, 0X10);


	//SwDbg-1-0-SwDbg-2-SPECompare
	if((NbCfg->Cnd003SwDbg1 == 0)&&((NbCfg->Cnd003SwDbg2) & BIT9)){
		DEBUG((EFI_D_ERROR, "SwDbg-1-0-SwDbg-2-SPECompare\n"));

		//For Debug
		// P mode
		IoeDumpSPEReCheck(NbCfg, IOE_BusXD0F0_PerformanceTBL_MMIO, 
				sizeof(IOE_BusXD0F0_PerformanceTBL_MMIO)/sizeof(ASIA_IO_TABLE_6432_REV), "PEEP: P value");	

		IoeDumpSPEReCheck(NbCfg, IOE_BusXp1D1F0_PerformanceTBL_MMIO, 
				sizeof(IOE_BusXp1D1F0_PerformanceTBL_MMIO)/sizeof(ASIA_IO_TABLE_6432_REV), "D1F0: P value");	
		
		IoeDumpSPEReCheck(NbCfg, IOE_BusXp1D2F0_PerformanceTBL_MMIO, 
				sizeof(IOE_BusXp1D2F0_PerformanceTBL_MMIO)/sizeof(ASIA_IO_TABLE_6432_REV), "D2F0: P value");		

		IoeDumpSPEReCheck(NbCfg, IOE_BusXp1D3F0_PerformanceTBL_MMIO, 
				sizeof(IOE_BusXp1D3F0_PerformanceTBL_MMIO)/sizeof(ASIA_IO_TABLE_6432_REV), "D3F0: P value");

		IoeDumpSPEReCheck(NbCfg, IOE_BusXp1D4F0_PerformanceTBL_MMIO, 
				sizeof(IOE_BusXp1D4F0_PerformanceTBL_MMIO)/sizeof(ASIA_IO_TABLE_6432_REV), "D4F0: P value");

		IoeDumpSPEReCheck(NbCfg, IOE_BusXp1D5F0_PerformanceTBL_MMIO, 
				sizeof(IOE_BusXp1D5F0_PerformanceTBL_MMIO)/sizeof(ASIA_IO_TABLE_6432_REV), "D5F0: P value");

		IoeDumpSPEReCheck(NbCfg, IOE_BusXp1D6F0_PerformanceTBL_MMIO, 
				sizeof(IOE_BusXp1D6F0_PerformanceTBL_MMIO)/sizeof(ASIA_IO_TABLE_6432_REV), "D6F0: P value");

		IoeDumpSPEReCheck(NbCfg, IOE_BusXp1D7F0_PerformanceTBL_MMIO, 
				sizeof(IOE_BusXp1D7F0_PerformanceTBL_MMIO)/sizeof(ASIA_IO_TABLE_6432_REV), "D7F0: P value");

		IoeDumpSPEReCheck(NbCfg, IOE_BusXp1D8F0_PerformanceTBL_MMIO, 
				sizeof(IOE_BusXp1D8F0_PerformanceTBL_MMIO)/sizeof(ASIA_IO_TABLE_6432_REV), "D8F0: P value");

		IoeDumpSPEReCheck(NbCfg, IOE_BusXp2D0F0_PerformanceTBL_MMIO, 
				sizeof(IOE_BusXp2D0F0_PerformanceTBL_MMIO)/sizeof(ASIA_IO_TABLE_6432_REV), "PCIEIF: P value");
		// E mode
		IoeDumpSPEReCheck(NbCfg, IOE_BusXD0F0_EnergyTBL_MMIO, 
				sizeof(IOE_BusXD0F0_EnergyTBL_MMIO)/sizeof(ASIA_IO_TABLE_6432_REV), "PEEP: E value");	

		IoeDumpSPEReCheck(NbCfg, IOE_BusXp1D1F0_EnergyTBL_MMIO, 
				sizeof(IOE_BusXp1D1F0_EnergyTBL_MMIO)/sizeof(ASIA_IO_TABLE_6432_REV), "D1F0: E value");	
		
		IoeDumpSPEReCheck(NbCfg, IOE_BusXp1D2F0_EnergyTBL_MMIO, 
				sizeof(IOE_BusXp1D2F0_EnergyTBL_MMIO)/sizeof(ASIA_IO_TABLE_6432_REV), "D2F0: E value");		

		IoeDumpSPEReCheck(NbCfg, IOE_BusXp1D3F0_EnergyTBL_MMIO, 
				sizeof(IOE_BusXp1D3F0_EnergyTBL_MMIO)/sizeof(ASIA_IO_TABLE_6432_REV), "D3F0: E value");

		IoeDumpSPEReCheck(NbCfg, IOE_BusXp1D4F0_EnergyTBL_MMIO, 
				sizeof(IOE_BusXp1D4F0_EnergyTBL_MMIO)/sizeof(ASIA_IO_TABLE_6432_REV), "D4F0: E value");

		IoeDumpSPEReCheck(NbCfg, IOE_BusXp1D5F0_EnergyTBL_MMIO, 
				sizeof(IOE_BusXp1D5F0_EnergyTBL_MMIO)/sizeof(ASIA_IO_TABLE_6432_REV), "D5F0: E value");

		IoeDumpSPEReCheck(NbCfg, IOE_BusXp1D6F0_EnergyTBL_MMIO, 
				sizeof(IOE_BusXp1D6F0_EnergyTBL_MMIO)/sizeof(ASIA_IO_TABLE_6432_REV), "D6F0: E value");

		IoeDumpSPEReCheck(NbCfg, IOE_BusXp1D7F0_EnergyTBL_MMIO, 
				sizeof(IOE_BusXp1D7F0_EnergyTBL_MMIO)/sizeof(ASIA_IO_TABLE_6432_REV), "D7F0: E value");

		IoeDumpSPEReCheck(NbCfg, IOE_BusXp1D8F0_EnergyTBL_MMIO, 
				sizeof(IOE_BusXp1D8F0_EnergyTBL_MMIO)/sizeof(ASIA_IO_TABLE_6432_REV), "D8F0: E value");

		IoeDumpSPEReCheck(NbCfg, IOE_BusXp2D0F0_EnergyTBL_MMIO, 
				sizeof(IOE_BusXp2D0F0_EnergyTBL_MMIO)/sizeof(ASIA_IO_TABLE_6432_REV), "PCIEIF: E value");

	}

	
}

/*
EFI_STATUS
IoeGetBus(
	IN RpList *PortList,
	IN UINT8 RpCounts,
	IN OUT UINT8 *xBusx, 
	IN OUT UINT8 *xBusxp2)
{
	UINT8 ix;

	for(ix = 0; ix < RpCounts; ix++){
		
		AsiaPciRead8(AsiaPciAddress(PortList->Bus, PortList->Dev, PortList->Func, 0x18));

	}

	
	return EFI_SUCCESS;
}
*/



/*
Return: 
	EFI_NOT_FOUNT: not found IOE
	EFI_SUCCESS: found IOE and bus number set completed

Note: 
	We just search IOE on all Rp at normal boot stage.
	when it come to S3 resume process, we set those register 
	directly and never to confirm them exist or not.
*/

/**
  Function description.
  
  @param  PeiServices	EFI_PEI_SERVICES pointer.
  @param SbCfg Point to ASIA_SB_CONFIGURATION struct.

  @return EFI_STATUS.

**/

EFI_STATUS
IoeFindAndAssign(
	IN RpList *PortList,
	IN UINT8 RpCounts,
	UINT8 *TblOffsetDxe
)
{
	EFI_STATUS Statusx = EFI_NOT_FOUND;
	UINT8 ix;
	UINT32 VidTemp;

#if 0		// For debug;
	
	for(ix = 0; ix < RpCounts; ix++){
		DEBUG((EFI_D_ERROR, "[CJW_IOE] Org value of Rx18/19/1A:[%d|%d|%d]=(%d,%d,%d) (should be 0,0,0)\n",
			PortList[ix].Bus, PortList[ix].Dev, PortList[ix].Func,
			AsiaPciRead8(AsiaPciAddress(PortList[ix].Bus, PortList[ix].Dev, PortList[ix].Func, 0x18)),
			AsiaPciRead8(AsiaPciAddress(PortList[ix].Bus, PortList[ix].Dev, PortList[ix].Func, 0x19)),
			AsiaPciRead8(AsiaPciAddress(PortList[ix].Bus, PortList[ix].Dev, PortList[ix].Func, 0x1A))));
	}
#endif
	
	for(ix = 0; ix < RpCounts; ix++){
		//Read VID
		AsiaPciWrite8(AsiaPciAddress(PortList[ix].Bus, PortList[ix].Dev, PortList[ix].Func, 0x18), BUS0);
		AsiaPciWrite8(AsiaPciAddress(PortList[ix].Bus, PortList[ix].Dev, PortList[ix].Func, 0x19), BUSX);
		AsiaPciWrite8(AsiaPciAddress(PortList[ix].Bus, PortList[ix].Dev, PortList[ix].Func, 0x1A), BUSXP3);
		
		VidTemp = AsiaPciRead32(AsiaPciAddress(BUSX, UPPORT_DEV, UPPORT_FUN, 0));
		//DEBUG((EFI_D_ERROR, "[CJW_IOE] VID: %08X\n",VidTemp));
		if((VidTemp == IOEBUSXUSP_VIDDID)||(VidTemp == IOEBUSXUSP_VIDDID_ZX)){
#if MULTI_IOE_SUPPORT			
			if(!IoeDxeIsUsablePort(PortList[ix].Bus, PortList[ix].Dev, PortList[ix].Func)){
				AsiaPciWrite8(AsiaPciAddress(PortList[ix].Bus, PortList[ix].Dev, PortList[ix].Func, 0x19), 0x0);
				AsiaPciWrite8(AsiaPciAddress(PortList[ix].Bus, PortList[ix].Dev, PortList[ix].Func, 0x1A), 0x0);				
				continue;
			}
#endif
			
			DEBUG((EFI_D_ERROR, "[CJW_IOE] -->Under [%d|%d|%d]: IOE Exist!\n",
				PortList[ix].Bus, PortList[ix].Dev, PortList[ix].Func));

			// Save those setting to Boot Script
			AsiaPciWriteSave8(AsiaPciAddress(PortList[ix].Bus, PortList[ix].Dev, PortList[ix].Func, 0x18), BUS0);
			AsiaPciWriteSave8(AsiaPciAddress(PortList[ix].Bus, PortList[ix].Dev, PortList[ix].Func, 0x19), BUSX);
			AsiaPciWriteSave8(AsiaPciAddress(PortList[ix].Bus, PortList[ix].Dev, PortList[ix].Func, 0x1A), BUSXP3);			


			//Assign bus number
			AsiaPciWriteSave8(AsiaPciAddress(BUSX, UPPORT_DEV, UPPORT_FUN, 0x18), BUSX);
			AsiaPciWriteSave8(AsiaPciAddress(BUSX, UPPORT_DEV, UPPORT_FUN, 0x19), BUSXP1);
			AsiaPciWriteSave8(AsiaPciAddress(BUSX, UPPORT_DEV, UPPORT_FUN, 0x1A), BUSXP3);
			AsiaPciWriteSave8(AsiaPciAddress(BUSXP1, PESB, DNPORT_FUN, 0x18), BUSXP1);
			AsiaPciWriteSave8(AsiaPciAddress(BUSXP1, PESB, DNPORT_FUN, 0x19), BUSXP2);
			AsiaPciWriteSave8(AsiaPciAddress(BUSXP1, PESB, DNPORT_FUN, 0x1A), BUSXP3);
			AsiaPciWriteSave8(AsiaPciAddress(BUSXP2, PCIEIF_DEV, PCIEIF_FUN, 0x18), BUSXP2);
			AsiaPciWriteSave8(AsiaPciAddress(BUSXP2, PCIEIF_DEV, PCIEIF_FUN, 0x19), BUSXP3);
			AsiaPciWriteSave8(AsiaPciAddress(BUSXP2, PCIEIF_DEV, PCIEIF_FUN, 0x1A), BUSXP3);

			//*xBusx = BUSX;
			//*xBusxp2 = BUSXP2;
			
			Statusx = EFI_SUCCESS;
			goto _IoeExist;
		}else{
			//DEBUG((EFI_D_ERROR, "[CJW_IOE] -->Under [%d|%d|%d]: Empty!\n",
			//	PortList[ix].Bus, PortList[ix].Dev, PortList[ix].Func));

			AsiaPciWrite8(AsiaPciAddress(PortList[ix].Bus, PortList[ix].Dev, PortList[ix].Func, 0x19), 0x0);
			AsiaPciWrite8(AsiaPciAddress(PortList[ix].Bus, PortList[ix].Dev, PortList[ix].Func, 0x1A), 0x0);			
		}
		
	}

	DEBUG((EFI_D_ERROR, "[CJW_IOE] -->Not Found IOE under gaven ports!\n"));

	AsiaPciWrite8(AsiaPciAddress(PortList[ix].Bus, PortList[ix].Dev, PortList[ix].Func, 0x19), 0x0);
	AsiaPciWrite8(AsiaPciAddress(PortList[ix].Bus, PortList[ix].Dev, PortList[ix].Func, 0x1A), 0x0);	


_IoeExist:

	if(TblOffsetDxe != NULL){
		*TblOffsetDxe = ix;
	}

	return Statusx;
}

/**
  Function description.
  
  @param  PeiServices	EFI_PEI_SERVICES pointer.
  @param SbCfg Point to ASIA_SB_CONFIGURATION struct.

  @return EFI_STATUS.

**/

VOID
IoeClearAssignment(	
	IN RpList *PortList,
	IN UINT8 RpCounts,
	UINT8 *TblOffsetDxe)
{
	UINT8 ix;
	UINT8 Value_1A;


{
	UINT8 temxx;
	temxx = AsiaPciRead8(AsiaPciAddress(BUSX, UPPORT_DEV, UPPORT_FUN, 0x18));
	if(temxx != 0x01){

		DEBUG((EFI_D_ERROR, "[CJW_IOE] Error-DebugMessage:\n"));
		DEBUG((EFI_D_ERROR, "[CJW_IOE] [0|2|0]\n"));
		IoeDumpCfgDxe(0xE0000000, 0, 2, 0, 0x200);

	
		DEBUG((EFI_D_ERROR, "[CJW_IOE] [BUSX|0|0]\n"));
		IoeDumpCfgDxe(0xE0000000, BUSX, UPPORT_DEV, UPPORT_FUN, 0x200);


		DEBUG((EFI_D_ERROR, "[CJW_IOE] [BUSX+1|0|0]\n"));
		IoeDumpCfgDxe( 0xE0000000, BUSXP1, XBCTL, DNPORT_FUN,0x200);


		DEBUG(( EFI_D_ERROR, "[CJW_IOE] [BUSX+1|1|0]\n"));
		IoeDumpCfgDxe( 0xE0000000, BUSXP1, PEA0, DNPORT_FUN,0x200);


		DEBUG(( EFI_D_ERROR, "[CJW_IOE] [BUSX+1|2|0]\n"));
		IoeDumpCfgDxe(0xE0000000, BUSXP1, PEA1, DNPORT_FUN,0x200);
		

		DEBUG(( EFI_D_ERROR, "[CJW_IOE] [BUSX+1|3|0]\n"));
		IoeDumpCfgDxe( 0xE0000000, BUSXP1, PEA2, DNPORT_FUN,0x200);

		
		DEBUG(( EFI_D_ERROR, "[CJW_IOE] [BUSX+1|4|0]\n"));
		IoeDumpCfgDxe(0xE0000000, BUSXP1, PEA3, DNPORT_FUN,0x200);


		DEBUG(( EFI_D_ERROR, "[CJW_IOE] [BUSX+1|5|0]\n"));
		IoeDumpCfgDxe(0xE0000000, BUSXP1, PEA4, DNPORT_FUN,0x200);

		
		DEBUG((EFI_D_ERROR, "[CJW_IOE] [BUSX+1|6|0]\n"));
		IoeDumpCfgDxe(0xE0000000, BUSXP1, PEB0, DNPORT_FUN,0x200);			

	
		DEBUG(( EFI_D_ERROR, "[CJW_IOE] [BUSX+1|7|0]\n"));
		IoeDumpCfgDxe( 0xE0000000, BUSXP1, PEB1, DNPORT_FUN,0x200);


		DEBUG(( EFI_D_ERROR, "[CJW_IOE] [BUSX+1|8|0]\n"));
		IoeDumpCfgDxe(0xE0000000, BUSXP1, PESB, DNPORT_FUN,0x200);


		DEBUG(( EFI_D_ERROR, "[CJW_IOE] [BUSX+2|0|0]\n"));
		IoeDumpCfgDxe( 0xE0000000, BUSXP2, PCIEIF_DEV, PCIEIF_FUN,0x200);
		
		}


	
}

	//Assign bus number
	AsiaPciWriteSave8(AsiaPciAddress(BUSXP2, PCIEIF_DEV, PCIEIF_FUN, 0x18), 0x0);
	AsiaPciWriteSave8(AsiaPciAddress(BUSXP2, PCIEIF_DEV, PCIEIF_FUN, 0x19), 0x0);
	AsiaPciWriteSave8(AsiaPciAddress(BUSXP2, PCIEIF_DEV, PCIEIF_FUN, 0x1A), 0x0);	
	AsiaPciWriteSave8(AsiaPciAddress(BUSXP1, PESB, DNPORT_FUN, 0x18), 0x0);
	AsiaPciWriteSave8(AsiaPciAddress(BUSXP1, PESB, DNPORT_FUN, 0x19), 0x0);
	AsiaPciWriteSave8(AsiaPciAddress(BUSXP1, PESB, DNPORT_FUN, 0x1A), 0x0);	
	AsiaPciWriteSave8(AsiaPciAddress(BUSX, UPPORT_DEV, UPPORT_FUN, 0x18), 0x0);
	AsiaPciWriteSave8(AsiaPciAddress(BUSX, UPPORT_DEV, UPPORT_FUN, 0x19), 0x0);
	AsiaPciWriteSave8(AsiaPciAddress(BUSX, UPPORT_DEV, UPPORT_FUN, 0x1A), 0x0);
	
	for(ix = 0; ix < RpCounts; ix++){
		Value_1A = AsiaPciRead8(AsiaPciAddress(PortList[ix].Bus, PortList[ix].Dev, PortList[ix].Func, 0x1A));

		if((Value_1A == BUSXP3)){
			DEBUG((EFI_D_ERROR, "[CJW_IOE] -->Under [%d|%d|%d]: IOE exist!\n",
				PortList[ix].Bus, PortList[ix].Dev, PortList[ix].Func));			
			goto _IoeLocation;
		}

	}

_IoeLocation:
	if(TblOffsetDxe != NULL){
		*TblOffsetDxe = ix;
	}
		
	AsiaPciWriteSave8(AsiaPciAddress(PortList[ix].Bus, PortList[ix].Dev, PortList[ix].Func, 0x19), 0x0);
	AsiaPciWriteSave8(AsiaPciAddress(PortList[ix].Bus, PortList[ix].Dev, PortList[ix].Func, 0x1A), 0x0);
			
}

/**
  Function description.
  
  @param  PeiServices	EFI_PEI_SERVICES pointer.
  @param SbCfg Point to ASIA_SB_CONFIGURATION struct.

  @return EFI_STATUS.

**/

VOID
IoePcieSpeAdditionalSetting(
	ASIA_NB_CONFIGURATION *NbCfg,
	UINT64 TargetFun)
{
	switch(TargetFun){
		case CND003_PEEP:


			//; Rx1E8[4] & Rx1E3[2]  for all IOE switch ports 
			//; ---Source: To solve S3 hang30 issue, SOC/IOE A0, SOC B0 and IOE A1
			//;            need to keep this setting according to Chunhui's suggestion
			AsiaPcieModifySave8(NbCfg->PcieBar, CND003_PEEP|((UINT64)CND003_BUSX_D0F0_AGGRESSIVE_PM<< 32), 
																			CND003_BUSX_D0F0_RLNPWR, CND003_BUSX_D0F0_RLNPWR);
			AsiaPcieModifySave8(NbCfg->PcieBar, CND003_PEEP|((UINT64)CND003_BUSX_D0F0_GEN2_MAC_ENHANCEMENT<< 32), 
																			CND003_BUSX_D0F0_RDOWNCFG, CND003_BUSX_D0F0_RDOWNCFG);		
			break;

		case CND003_PEA0:
			AsiaPcieModifySave8(NbCfg->PcieBar, CND003_PEA0|((UINT64)CND003_BUSXP1_D1D7F0_AGGRESSIVE_PM<< 32), 	
																CND003_BUSXP1_D1D7F0_RLNPWR, CND003_BUSXP1_D1D7F0_RLNPWR);
			AsiaPcieModifySave8(NbCfg->PcieBar, CND003_PEA0|((UINT64)CND003_BUSXP1_D1D7F0_GEN2_MAC_ENHANCEMENT<< 32), 
																CND003_BUSX_D0F0_RDOWNCFG, CND003_BUSX_D0F0_RDOWNCFG);			
			break;
		case CND003_PEA1:
			AsiaPcieModifySave8(NbCfg->PcieBar, CND003_PEA1|((UINT64)CND003_BUSXP1_D1D7F0_AGGRESSIVE_PM<< 32), 	
																CND003_BUSXP1_D1D7F0_RLNPWR, CND003_BUSXP1_D1D7F0_RLNPWR);
			AsiaPcieModifySave8(NbCfg->PcieBar, CND003_PEA1|((UINT64)CND003_BUSXP1_D1D7F0_GEN2_MAC_ENHANCEMENT<< 32), 
																CND003_BUSX_D0F0_RDOWNCFG, CND003_BUSX_D0F0_RDOWNCFG);			
			break;
		case CND003_PEA2:
			AsiaPcieModifySave8(NbCfg->PcieBar, CND003_PEA2|((UINT64)CND003_BUSXP1_D1D7F0_AGGRESSIVE_PM<< 32), 	
																CND003_BUSXP1_D1D7F0_RLNPWR, CND003_BUSXP1_D1D7F0_RLNPWR);
			AsiaPcieModifySave8(NbCfg->PcieBar, CND003_PEA2|((UINT64)CND003_BUSXP1_D1D7F0_GEN2_MAC_ENHANCEMENT<< 32), 
																CND003_BUSX_D0F0_RDOWNCFG, CND003_BUSX_D0F0_RDOWNCFG);			
			break;
		case CND003_PEA3:
			AsiaPcieModifySave8(NbCfg->PcieBar, CND003_PEA3|((UINT64)CND003_BUSXP1_D1D7F0_AGGRESSIVE_PM<< 32), 	
																CND003_BUSXP1_D1D7F0_RLNPWR, CND003_BUSXP1_D1D7F0_RLNPWR);
			AsiaPcieModifySave8(NbCfg->PcieBar, CND003_PEA3|((UINT64)CND003_BUSXP1_D1D7F0_GEN2_MAC_ENHANCEMENT<< 32), 
																CND003_BUSX_D0F0_RDOWNCFG, CND003_BUSX_D0F0_RDOWNCFG);			
			break;
		case CND003_PEA4:
			AsiaPcieModifySave8(NbCfg->PcieBar, CND003_PEA4|((UINT64)CND003_BUSXP1_D1D7F0_AGGRESSIVE_PM<< 32), 	
																CND003_BUSXP1_D1D7F0_RLNPWR, CND003_BUSXP1_D1D7F0_RLNPWR);
			AsiaPcieModifySave8(NbCfg->PcieBar, CND003_PEA4|((UINT64)CND003_BUSXP1_D1D7F0_GEN2_MAC_ENHANCEMENT<< 32), 
																CND003_BUSX_D0F0_RDOWNCFG, CND003_BUSX_D0F0_RDOWNCFG);			
			break;
		case CND003_PEB0:
			AsiaPcieModifySave8(NbCfg->PcieBar, CND003_PEB0|((UINT64)CND003_BUSXP1_D1D7F0_AGGRESSIVE_PM<< 32), 	
																CND003_BUSXP1_D1D7F0_RLNPWR, CND003_BUSXP1_D1D7F0_RLNPWR);
			AsiaPcieModifySave8(NbCfg->PcieBar, CND003_PEB0|((UINT64)CND003_BUSXP1_D1D7F0_GEN2_MAC_ENHANCEMENT<< 32), 
																CND003_BUSX_D0F0_RDOWNCFG, CND003_BUSX_D0F0_RDOWNCFG);			
			break;
		case CND003_PEB1:
			AsiaPcieModifySave8(NbCfg->PcieBar, CND003_PEB1|((UINT64)CND003_BUSXP1_D1D7F0_AGGRESSIVE_PM<< 32), 	
																CND003_BUSXP1_D1D7F0_RLNPWR, CND003_BUSXP1_D1D7F0_RLNPWR);
			AsiaPcieModifySave8(NbCfg->PcieBar, CND003_PEB1|((UINT64)CND003_BUSXP1_D1D7F0_GEN2_MAC_ENHANCEMENT<< 32), 
																CND003_BUSX_D0F0_RDOWNCFG, CND003_BUSX_D0F0_RDOWNCFG);			
			break;
        default:
			break;
	}

	return;
}

/**
  Function description.
  
  @param  PeiServices	EFI_PEI_SERVICES pointer.
  @param SbCfg Point to ASIA_SB_CONFIGURATION struct.

  @return EFI_STATUS.

**/

EFI_STATUS
IoePcieSpeSetting(
	ASIA_NB_CONFIGURATION *NbCfg)
{


	//
	// Some special setting
	//	--when default value is different with the S mode value,
	//		we need to set it here 
	
	//
	//AsiaPcieModifySave32(NbCfg->PcieBar, AsiaPciAddress(BUSX, UPPORT_DEV, UPPORT_FUN, CND003_BUSX_D0F0_ARBITRATION_CTL), 
	//																					CND003_BUSX_D0F0_RDLARB, BIT0);
	AsiaPcieModifySave8(NbCfg->PcieBar, CND003_PEEP|((UINT64)CND003_BUSX_D0F0_ARBITRATION_CTL<< 32), 
																	CND003_BUSX_D0F0_RDLARB, BIT0);

	//
	// From this point, start to setting IOE's SPE value for PCIE PTN
	//

	//
	//PEEP
	//
    	//if(NbCfg->IoePciePEEP) {
        if(1) {

            if(NbCfg->IOEXSPEValue >= DEVICE_SPE_VALUE_PERFORMANCE) {
                IOE_PROCESS_PCIE_R6432M_TABLE_SAVE_1(
					NbCfg->PcieBar,
					IOE_BusXD0F0_PerformanceTBL_MMIO, sizeof(IOE_BusXD0F0_PerformanceTBL_MMIO)/sizeof(ASIA_IO_TABLE_6432_REV));
                if(NbCfg->IOEXSPEValue == DEVICE_SPE_VALUE_ENERGY) {
                    IOE_PROCESS_PCIE_R6432M_TABLE_SAVE_1(
						NbCfg->PcieBar, 
						IOE_BusXD0F0_EnergyTBL_MMIO, sizeof(IOE_BusXD0F0_EnergyTBL_MMIO)/sizeof(ASIA_IO_TABLE_6432_REV));
                }

            } 
			IoePcieSpeAdditionalSetting(NbCfg, CND003_PEEP);
        }

	//
	//XBCTL
	//
        if(1) {
         
            if(NbCfg->IOEXp1D0F0SPEValue >= DEVICE_SPE_VALUE_PERFORMANCE) {
            	IOE_PROCESS_PCIE_R6432M_TABLE_SAVE_1(
					NbCfg->PcieBar, 
					IOE_BusXp1D0F0_PerformanceTBL_MMIO, sizeof(IOE_BusXp1D0F0_PerformanceTBL_MMIO)/sizeof(ASIA_IO_TABLE_6432_REV));
                if(NbCfg->IOEXp1D0F0SPEValue == DEVICE_SPE_VALUE_ENERGY) {
                    IOE_PROCESS_PCIE_R6432M_TABLE_SAVE_1(
						NbCfg->PcieBar, 
						IOE_BusXp1D0F0_EnergyTBL_MMIO, sizeof(IOE_BusXp1D0F0_EnergyTBL_MMIO)/sizeof(ASIA_IO_TABLE_6432_REV));
                }
				
            } 
			IoePcieSpeAdditionalSetting(NbCfg, CND003_XBCTL);
        }

	//
	// All CND003 PCIE DN ports (not include virtual ports)
	//
	if(NbCfg->IoeDnPortCtl) {		
		//
		//PEA0
		//
        if(NbCfg->IoePEA0Ctl) {
       
            if(NbCfg->IOEXp1D1F0SPEValue >= DEVICE_SPE_VALUE_PERFORMANCE) {
            	IOE_PROCESS_PCIE_R6432M_TABLE_SAVE_1(
					NbCfg->PcieBar, 
					IOE_BusXp1D1F0_PerformanceTBL_MMIO, sizeof(IOE_BusXp1D1F0_PerformanceTBL_MMIO)/sizeof(ASIA_IO_TABLE_6432_REV));
                if(NbCfg->IOEXp1D1F0SPEValue == DEVICE_SPE_VALUE_ENERGY) {
                    IOE_PROCESS_PCIE_R6432M_TABLE_SAVE_1(
						NbCfg->PcieBar, 
						IOE_BusXp1D1F0_EnergyTBL_MMIO, sizeof(IOE_BusXp1D1F0_EnergyTBL_MMIO)/sizeof(ASIA_IO_TABLE_6432_REV));
                }

            } 
			IoePcieSpeAdditionalSetting(NbCfg, CND003_PEA0);
        }


		//
		//PEA1
		//
        if(NbCfg->IoePEA1Ctl) {
            //AsiaPciModifySave8(CND001_SCRCH|(D0F6_BIOS_SCRATCH_REG_7), BIT1, BIT1);
            if(NbCfg->IOEXp1D2F0SPEValue >= DEVICE_SPE_VALUE_PERFORMANCE) {
          		IOE_PROCESS_PCIE_R6432M_TABLE_SAVE_1(
                    NbCfg->PcieBar, 
					IOE_BusXp1D2F0_PerformanceTBL_MMIO, sizeof(IOE_BusXp1D2F0_PerformanceTBL_MMIO)/sizeof(ASIA_IO_TABLE_6432_REV));
                if(NbCfg->IOEXp1D2F0SPEValue == DEVICE_SPE_VALUE_ENERGY) {
                    IOE_PROCESS_PCIE_R6432M_TABLE_SAVE_1(
                         NbCfg->PcieBar, 
						IOE_BusXp1D2F0_EnergyTBL_MMIO, sizeof(IOE_BusXp1D2F0_EnergyTBL_MMIO)/sizeof(ASIA_IO_TABLE_6432_REV));
                }
            }
			IoePcieSpeAdditionalSetting(NbCfg, CND003_PEA1);
            
        }


		//
		//PEA2
		//
		if(NbCfg->IoePEA2Ctl) {
            if(NbCfg->IOEXp1D3F0SPEValue >= DEVICE_SPE_VALUE_PERFORMANCE) {
            	IOE_PROCESS_PCIE_R6432M_TABLE_SAVE_1(
					NbCfg->PcieBar, 
					IOE_BusXp1D3F0_PerformanceTBL_MMIO, sizeof(IOE_BusXp1D3F0_PerformanceTBL_MMIO)/sizeof(ASIA_IO_TABLE_6432_REV));
                if(NbCfg->IOEXp1D3F0SPEValue == DEVICE_SPE_VALUE_ENERGY) {
                    IOE_PROCESS_PCIE_R6432M_TABLE_SAVE_1(
						NbCfg->PcieBar, 
						IOE_BusXp1D3F0_EnergyTBL_MMIO, sizeof(IOE_BusXp1D3F0_EnergyTBL_MMIO)/sizeof(ASIA_IO_TABLE_6432_REV));
                }

            } 
			IoePcieSpeAdditionalSetting(NbCfg, CND003_PEA2);
        }
		//
		//PEA3
		//
        if(NbCfg->IoePEA3Ctl) {

            if(NbCfg->IOEXp1D4F0SPEValue >= DEVICE_SPE_VALUE_PERFORMANCE) {
            	IOE_PROCESS_PCIE_R6432M_TABLE_SAVE_1(
					NbCfg->PcieBar, 
					IOE_BusXp1D4F0_PerformanceTBL_MMIO, sizeof(IOE_BusXp1D4F0_PerformanceTBL_MMIO)/sizeof(ASIA_IO_TABLE_6432_REV));
                if(NbCfg->IOEXp1D4F0SPEValue == DEVICE_SPE_VALUE_ENERGY) {
                    IOE_PROCESS_PCIE_R6432M_TABLE_SAVE_1(
						NbCfg->PcieBar, 
						IOE_BusXp1D4F0_EnergyTBL_MMIO, sizeof(IOE_BusXp1D4F0_EnergyTBL_MMIO)/sizeof(ASIA_IO_TABLE_6432_REV));
                }

            } 
			IoePcieSpeAdditionalSetting(NbCfg, CND003_PEA3);
        }		

		//
		//PEA4
		//
		if(NbCfg->IoePEA4Ctl) {
            //AsiaPciModifySave8(CND001_SCRCH|(D0F6_BIOS_SCRATCH_REG_7), BIT1, BIT1);
            if(NbCfg->IOEXp1D5F0SPEValue >= DEVICE_SPE_VALUE_PERFORMANCE) {

            }
            if(NbCfg->IOEXp1D5F0SPEValue >= DEVICE_SPE_VALUE_PERFORMANCE) {
            	IOE_PROCESS_PCIE_R6432M_TABLE_SAVE_1(
					NbCfg->PcieBar, 
					IOE_BusXp1D5F0_PerformanceTBL_MMIO, sizeof(IOE_BusXp1D5F0_PerformanceTBL_MMIO)/sizeof(ASIA_IO_TABLE_6432_REV));
                if(NbCfg->IOEXp1D5F0SPEValue == DEVICE_SPE_VALUE_ENERGY) {
                    IOE_PROCESS_PCIE_R6432M_TABLE_SAVE_1(
						NbCfg->PcieBar, 
						IOE_BusXp1D5F0_EnergyTBL_MMIO, sizeof(IOE_BusXp1D5F0_EnergyTBL_MMIO)/sizeof(ASIA_IO_TABLE_6432_REV));
                }

            } 
			IoePcieSpeAdditionalSetting(NbCfg, CND003_PEA4);
        }

		//
		//PEB0
		//
		if(NbCfg->IoePEB0Ctl) {

            if(NbCfg->IOEXp1D6F0SPEValue >= DEVICE_SPE_VALUE_PERFORMANCE) {
            	IOE_PROCESS_PCIE_R6432M_TABLE_SAVE_1(
					NbCfg->PcieBar, 
					IOE_BusXp1D6F0_PerformanceTBL_MMIO, sizeof(IOE_BusXp1D6F0_PerformanceTBL_MMIO)/sizeof(ASIA_IO_TABLE_6432_REV));
                if(NbCfg->IOEXp1D6F0SPEValue == DEVICE_SPE_VALUE_ENERGY) {
                    IOE_PROCESS_PCIE_R6432M_TABLE_SAVE_1(
						NbCfg->PcieBar, 
						IOE_BusXp1D6F0_EnergyTBL_MMIO, sizeof(IOE_BusXp1D6F0_EnergyTBL_MMIO)/sizeof(ASIA_IO_TABLE_6432_REV));
                }

            } 
			IoePcieSpeAdditionalSetting(NbCfg, CND003_PEB0);
        }

		//
		//PEB1
		//
		if(NbCfg->IoePEB1Ctl) {

            if(NbCfg->IOEXp1D7F0SPEValue >= DEVICE_SPE_VALUE_PERFORMANCE) {
            	IOE_PROCESS_PCIE_R6432M_TABLE_SAVE_1(
					NbCfg->PcieBar, 
					IOE_BusXp1D7F0_PerformanceTBL_MMIO, sizeof(IOE_BusXp1D7F0_PerformanceTBL_MMIO)/sizeof(ASIA_IO_TABLE_6432_REV));
                if(NbCfg->IOEXp1D7F0SPEValue == DEVICE_SPE_VALUE_ENERGY) {
                    IOE_PROCESS_PCIE_R6432M_TABLE_SAVE_1(
						NbCfg->PcieBar, 
						IOE_BusXp1D7F0_EnergyTBL_MMIO, sizeof(IOE_BusXp1D7F0_EnergyTBL_MMIO)/sizeof(ASIA_IO_TABLE_6432_REV));
                }

            } 
			IoePcieSpeAdditionalSetting(NbCfg, CND003_PEB1);
        }
	}
	//
	//PESB
	//
		if(1){

            if(NbCfg->IOEXp1D8F0SPEValue >= DEVICE_SPE_VALUE_PERFORMANCE) {
            	IOE_PROCESS_PCIE_R6432M_TABLE_SAVE_1(
					NbCfg->PcieBar, 
					IOE_BusXp1D8F0_PerformanceTBL_MMIO, sizeof(IOE_BusXp1D8F0_PerformanceTBL_MMIO)/sizeof(ASIA_IO_TABLE_6432_REV));
                if(NbCfg->IOEXp1D8F0SPEValue == DEVICE_SPE_VALUE_ENERGY) {
                    IOE_PROCESS_PCIE_R6432M_TABLE_SAVE_1(
						NbCfg->PcieBar, 
						IOE_BusXp1D8F0_EnergyTBL_MMIO, sizeof(IOE_BusXp1D8F0_EnergyTBL_MMIO)/sizeof(ASIA_IO_TABLE_6432_REV));
                }

            } 
			IoePcieSpeAdditionalSetting(NbCfg, CND003_PESB);
        }


	//
	//PCIEIF
	//
		if(1){

            if(NbCfg->IOEXp2D0F0SPEValue >= DEVICE_SPE_VALUE_PERFORMANCE) {
            	IOE_PROCESS_PCIE_R6432M_TABLE_SAVE_1(
					NbCfg->PcieBar, 
					IOE_BusXp2D0F0_PerformanceTBL_MMIO, sizeof(IOE_BusXp2D0F0_PerformanceTBL_MMIO)/sizeof(ASIA_IO_TABLE_6432_REV));
                if(NbCfg->IOEXp2D0F0SPEValue == DEVICE_SPE_VALUE_ENERGY) {
                    IOE_PROCESS_PCIE_R6432M_TABLE_SAVE_1(
						NbCfg->PcieBar, 
						IOE_BusXp2D0F0_EnergyTBL_MMIO, sizeof(IOE_BusXp2D0F0_EnergyTBL_MMIO)/sizeof(ASIA_IO_TABLE_6432_REV));
                }
            }
			IoePcieSpeAdditionalSetting(NbCfg, CND003_PCIEIF);
        }


	//
	//EPTRFC
	//
		if(1){

            if(NbCfg->IOEXp3D0F0SPEValue >= DEVICE_SPE_VALUE_PERFORMANCE) {
            	IOE_PROCESS_PCIE_R6432M_TABLE_SAVE_1(
					NbCfg->PcieBar, 
					IOE_BusXp3D0F0_PerformanceTBL_MMIO, sizeof(IOE_BusXp3D0F0_PerformanceTBL_MMIO)/sizeof(ASIA_IO_TABLE_6432_REV));
                if(NbCfg->IOEXp3D0F0SPEValue == DEVICE_SPE_VALUE_ENERGY) {
                    IOE_PROCESS_PCIE_R6432M_TABLE_SAVE_1(
						NbCfg->PcieBar, 
						IOE_BusXp3D0F0_EnergyTBL_MMIO, sizeof(IOE_BusXp3D0F0_EnergyTBL_MMIO)/sizeof(ASIA_IO_TABLE_6432_REV));
                }
            } 
			IoePcieSpeAdditionalSetting(NbCfg, CND003_EPTRFC);
						
        }
		
		/*
		//
		// IOE PCIE EPHY & IOE MMIO_ISB --> SPE value: reserved now
		//
		if(1) {
        	if(NbCfg->PCIEEPHYSPEValue >= DEVICE_SPE_VALUE_PERFORMANCE) {
            	UINT8 nBrEvIsion = (ASIA_NB_REVISION);
              	UINT32 tAbLeIdx, JdbgValue; 
             	UINT64 JdbgAddr;
				for(tAbLeIdx = 0; tAbLeIdx < (sizeof(PCIEEPHYPerformanceMMIOTBL)/sizeof(ASIA_IO_TABLE_6408_REV)); tAbLeIdx++) { 
					if((nBrEvIsion) > (PCIEEPHYPerformanceMMIOTBL)[tAbLeIdx].RevisionMax || (nBrEvIsion) < (PCIEEPHYPerformanceMMIOTBL)[tAbLeIdx].RevisionMin) 
						continue; 
					AsiaMemoryModifySave8(NbCfg->PcieEPHYBar |(PCIEEPHYPerformanceMMIOTBL)[tAbLeIdx].Address, (PCIEEPHYPerformanceMMIOTBL)[tAbLeIdx].Mask, (PCIEEPHYPerformanceMMIOTBL)[tAbLeIdx].Value); 
					JdbgAddr=NbCfg->PcieEPHYBar |(RCRBHPerformanceMMIOTBL)[tAbLeIdx].Address;
					JdbgValue=AsiaMemoryRead8(NbCfg->PcieEPHYBar |(RCRBHPerformanceMMIOTBL)[tAbLeIdx].Address);
					DEBUG((EFI_D_ERROR|EFI_D_INFO, "Debug Pmode - PCIE-EPHY Addr=0%x Value=0%x \n",JdbgAddr, JdbgValue));
				}
				if(NbCfg->PCIEEPHYSPEValue == DEVICE_SPE_VALUE_ENERGY) {
					for(tAbLeIdx = 0; tAbLeIdx < (sizeof(PCIEEPHYEnergyMMIOTBL)/sizeof(ASIA_IO_TABLE_6408_REV)); tAbLeIdx++) { 
						if((nBrEvIsion) > (PCIEEPHYEnergyMMIOTBL)[tAbLeIdx].RevisionMax || (nBrEvIsion) < (PCIEEPHYEnergyMMIOTBL)[tAbLeIdx].RevisionMin) 
							continue; 
						AsiaMemoryModifySave8(NbCfg->PcieEPHYBar |(PCIEEPHYEnergyMMIOTBL)[tAbLeIdx].Address, (PCIEEPHYEnergyMMIOTBL)[tAbLeIdx].Mask, (PCIEEPHYEnergyMMIOTBL)[tAbLeIdx].Value); 
						JdbgAddr=NbCfg->PcieEPHYBar |(PCIEEPHYEnergyMMIOTBL)[tAbLeIdx].Address;
						JdbgValue=AsiaMemoryRead8(NbCfg->PcieEPHYBar |(PCIEEPHYEnergyMMIOTBL)[tAbLeIdx].Address);
						DEBUG((EFI_D_ERROR|EFI_D_INFO, "Debug Emode - PCIE-EPHY Addr=0%x Value=0%x \n",JdbgAddr, JdbgValue));
					} 
					PROCESS_NB_PCIE_R6408M_TABLE_SAVE(NbCfg->PcieEPHYBar, PCIEEPHYEnergyMMIOTBL, sizeof(PCIEEPHYEnergyMMIOTBL)/sizeof(ASIA_IO_TABLE_6408_REV));
				}
			} 
        }
		*/

	return EFI_SUCCESS;
}







/*
For FRPxx_P1EXT_Gx[2:0]
	3'b000: 1us
	3'b001: 2us
	3'b010: 4us
	3'b011: 8us
	3'b100: 16us (default)
	3'b101: 32us
	3'b110: 64us
	3'b111: 128us

*/
#define IOE_L1CAP_REG2REAL(x)  ((2<<x)>>1)
#define IOE_L1CAP_REAL2REG(y)  (((y>>1)==0)?0:\
	(((y>>2)==0)?1:\
	(((y>>3)==0)?2:\
	(((y>>4)==0)?3:\
	(((y>>5)==0)?4:\
	(((y>>6)==0)?5:\
	((y>>7)==0)?6:\
	(((y>>8)==0)?7:0xF)))))))


IOE_L1SET_TBL IoeL1ExitLatencyTblx[] = {
	//PHYCFG 	PEA0		PEA1 		PEA2		PEA3		PEA4		PEB0 	PEB1  	PEEP
	0x303,  	0x216,  	0x218,  	0x21A,   	0x212,   	0x214,   	0,    	0,		0x224,	//EH0  EK0
	
};


#define IOE_L1_EXIST_SBDG   			0x30   	//Steps between different Gen speeds 
#define IOE_LPHY_Rx_L1_Recovery_Time   	4 		//4us   -- pls refer to IRS ItemD
#define IOE_TPLL_PowerUp_Lock_Time  	8		//8us  [Note: currently not used] 
												// 	   --pls refer to IRS ItemA TPLL power up and lock

/**
  Function description.
  
  @param  PeiServices	EFI_PEI_SERVICES pointer.
  @param SbCfg Point to ASIA_SB_CONFIGURATION struct.

  @return EFI_STATUS.

**/									
STATIC
EFI_STATUS
IoeReProgramL1ExitLatency(
	ASIA_NB_CONFIGURATION *NbCfg,
	UINT64 Addr,
	UINT32 PhyBaseAddr,
	IOE_L1SET_TBL *Ptx,
	UINT8 TblIndex)
{
	UINT8 IoeItemC,IoeItemC_us,IoeItemD_us;
	UINT16 RegOff = 0;
	UINT32 ReprogramedValue_us,ReprogramedValue;
	UINT8 IoeCls;

	// Get the real register offset
	switch(Addr){
		case CND003_PEA0:
			RegOff = Ptx[TblIndex].RegForPEA0;
			break;
		case CND003_PEA1:
			RegOff = Ptx[TblIndex].RegForPEA1;
			break;		
		case CND003_PEA2:
			RegOff = Ptx[TblIndex].RegForPEA2;
			break;
		case CND003_PEA3:
			RegOff = Ptx[TblIndex].RegForPEA3;
			break;
		case CND003_PEA4:
			RegOff = Ptx[TblIndex].RegForPEA4;
			break;
		case CND003_PEB0:
			RegOff = Ptx[TblIndex].RegForPEB0;
			break;	
		case CND003_PEB1:
			RegOff = Ptx[TblIndex].RegForPEB1;
			break;
		case CND003_PEEP:
			RegOff = Ptx[TblIndex].RegForPEEP;
			break;
		default:
			break;
	}

	DEBUG((EFI_D_ERROR, "                      RegOff = 0x%04x \n",RegOff));

	// Get Current Link Speed  and get the Real Reg offset in EPHY
	IoeCls = 0xF & AsiaPcieRead8(NbCfg->PcieBar, Addr|((UINT64)CND003_BUSX_D0F0_LINK_STA_1<<32));
	DEBUG((EFI_D_ERROR, "                      IOE_CLS = %d \n",IoeCls));
	if(IoeCls == 2){
		
		RegOff += IOE_L1_EXIST_SBDG;	
		
	}else if(IoeCls == 3){

		RegOff += (IOE_L1_EXIST_SBDG + IOE_L1_EXIST_SBDG);
	}

	// Get the P1 Exit Latency use the Real Register Offset
	IoeItemC = AsiaMemoryRead8(PhyBaseAddr + RegOff);
	IoeItemC = (IoeItemC>>3)&(0x7);
	IoeItemC_us = IOE_L1CAP_REG2REAL(IoeItemC);
	DEBUG((EFI_D_ERROR, "                      IoeItemC_us = %d \n",IoeItemC_us));
	if(IoeItemC_us > 128){
		// invalid value
		DEBUG((EFI_D_ERROR, "                      Invalid EPHY P1 Exit Latency!!!\n"));
		return EFI_NOT_FOUND;
	}
	
	// Get the ItemD;
	IoeItemD_us = IOE_LPHY_Rx_L1_Recovery_Time;	
	
	// Get the L1 Exit Latency(Note: need to see Rx1E8[0] in later project)
	ReprogramedValue_us = IoeItemC_us + IoeItemD_us;
	ReprogramedValue = IOE_L1CAP_REAL2REG(ReprogramedValue_us) + 1;
	DEBUG((EFI_D_ERROR, "                      ReprogramedValue = %d \n",ReprogramedValue));
	


	// Open the backdoor to reprogram the L1 Exit Latency
	DEBUG((EFI_D_ERROR, "                      XBCTL VID/DID: 0x%08x\n",AsiaPciRead32(AsiaPciAddress(BUSXP1, XBCTL, DNPORT_FUN, 0))));
	AsiaPciModifySave8(AsiaPciAddress(BUSXP1, XBCTL, DNPORT_FUN, CND003_MMIO_D0F0_BACKDOOR_REG_CTL_0), 
											CND003_MMIO_D0F0_RPEROWEN, CND003_MMIO_D0F0_RPEROWEN);
	AsiaPcieModifySave32(NbCfg->PcieBar, Addr|((UINT64)CND003_BUSX_D0F0_LINK_CAPS_1<<32), 
											CND003_BUSX_D0F0_LKL1EL,ReprogramedValue<<15);
	AsiaPciModifySave8(AsiaPciAddress(BUSXP1, XBCTL, DNPORT_FUN, CND003_MMIO_D0F0_BACKDOOR_REG_CTL_0), 
											CND003_MMIO_D0F0_RPEROWEN, 0);

	return EFI_SUCCESS;
}

/**
  Function description.
  
  @param  PeiServices	EFI_PEI_SERVICES pointer.
  @param SbCfg Point to ASIA_SB_CONFIGURATION struct.

  @return EFI_STATUS.

**/

STATIC
EFI_STATUS
IoeL1ExitLatencyCalculation(
	ASIA_NB_CONFIGURATION *NbCfg,
	IOE_L1SET_TBL *Ptx,
	UINT8 TblSize)
{
	UINT16 IoePhyCfgFlag;
	UINT8 TblIndex;
	UINT8 ExistFlagx = 0;

	UINT32 MmioBar;
	UINT16 temp16;
	
	
	
	if(NbCfg->IoeDnPortCtl != 1){
		return EFI_SUCCESS;
	}

	// Get current PHYCFG
	MmioBar = AsiaPciRead32(AsiaPciAddress(BUSX, UPPORT_DEV, UPPORT_FUN, CND003_BUSX_D0F0_LOWER_BASE_ADR));
	temp16 = AsiaMemoryRead16(MmioBar + MMIO_ISB_OFFSET + CND003_MMIO_D0F0_STRAPPING_PIN_READ_BACK_REG_GRP_1);
	IoePhyCfgFlag = ((BIT9|BIT8)&(temp16>>2))|((BIT1|BIT0)&(temp16>>8));
	DEBUG((EFI_D_ERROR, "PCIE_L1_EXIT_LATENCY: PHYCFG = 0x%04x\n", IoePhyCfgFlag));

	// Search the porpure item in table
	for(TblIndex = 0; TblIndex < TblSize; TblIndex++){
		if(Ptx[TblIndex].PhyCfg == IoePhyCfgFlag){
			ExistFlagx = 1;
			break;
		}
	}
	if(ExistFlagx != 1){
		DEBUG((EFI_D_ERROR, "                      Failed to reprgraming L1 Exit Latency!!!\n"));
		return EFI_NOT_FOUND;
	}
	
	DEBUG((EFI_D_ERROR, "                      Index = %d\n", TblIndex));

	IoeReProgramL1ExitLatency(NbCfg, CND003_PEEP,MmioBar,Ptx,TblIndex);
	if(NbCfg->IoePEA0Ctl == 1){
		IoeReProgramL1ExitLatency(NbCfg, CND003_PEA0,MmioBar,Ptx,TblIndex);
	}
	if(NbCfg->IoePEA1Ctl == 1){
		IoeReProgramL1ExitLatency(NbCfg, CND003_PEA1,MmioBar,Ptx,TblIndex);
	}
	if(NbCfg->IoePEA2Ctl == 1){
		IoeReProgramL1ExitLatency(NbCfg, CND003_PEA2,MmioBar,Ptx,TblIndex);
	}
	if(NbCfg->IoePEA3Ctl == 1){
		IoeReProgramL1ExitLatency(NbCfg, CND003_PEA3,MmioBar,Ptx,TblIndex);
	}
	if(NbCfg->IoePEA4Ctl == 1){
		IoeReProgramL1ExitLatency(NbCfg, CND003_PEA4,MmioBar,Ptx,TblIndex);
	}
	if(NbCfg->IoePEB0Ctl == 1){
		IoeReProgramL1ExitLatency(NbCfg, CND003_PEB0,MmioBar,Ptx,TblIndex);
	}
	if(NbCfg->IoePEB1Ctl == 1){
		IoeReProgramL1ExitLatency(NbCfg, CND003_PEB1,MmioBar,Ptx,TblIndex);
	}

	return EFI_SUCCESS;
}



/**
  Function description.
  
  @param  PeiServices	EFI_PEI_SERVICES pointer.
  @param SbCfg Point to ASIA_SB_CONFIGURATION struct.

  @return EFI_STATUS.

**/

STATIC
VOID 
IoeAggresivePmMode(
    ASIA_NB_CONFIGURATION *NbCfg,
    UINT64    Addr
)
{
    UINT64 pciebase;
    UINT8 cardPresent;

    cardPresent = AsiaPciRead8(Addr|CND003_BUSXP1_D1D7F0_SLOT_STA_1);
    cardPresent &= CND003_BUSXP1_D1D7F0_SPDCST;

    pciebase = NbCfg->PcieBar;

    //PCIE_Aggresive_PM_Support start
    if(cardPresent != CND003_BUSXP1_D1D7F0_SPDCST){
        //Disable Aggressive Power Management When No Device Plug:[Bit2]
        //!!!: Bit2 must clear before Bit1 set to 1
        AsiaPcieModifySave8(pciebase, Addr|((UINT64)(CND003_BUSXP1_D1D7F0_AGGRESSIVE_PM) << 32), CND003_BUSXP1_D1D7F0_RDEVDETPM, 0);
        //Rx1E8[1] Enable PHYES Level 2 Power Down when there is no device existing behind this root port
        AsiaPcieModifySave8(pciebase, Addr|((UINT64)(CND003_BUSXP1_D1D7F0_AGGRESSIVE_PM) << 32), CND003_BUSXP1_D1D7F0_RPDL2, CND003_BUSXP1_D1D7F0_RPDL2);
        //Rx1E8[7] For the Port that does not support Hot_Plug, program this bit to 1b to power off EPHY RX Electrical Idle Detector to save more power
        AsiaPcieModifySave8(pciebase, Addr|((UINT64)(CND003_BUSXP1_D1D7F0_AGGRESSIVE_PM) << 32), CND003_BUSXP1_D1D7F0_RRXEIDPD, CND003_BUSXP1_D1D7F0_RRXEIDPD);
    }
    else
        AsiaPcieModifySave8(pciebase, Addr|((UINT64)(CND003_BUSXP1_D1D7F0_AGGRESSIVE_PM) << 32), CND003_BUSXP1_D1D7F0_RPDL2, 0);

    //Enable L1 MPLL power down in Gen2 speed:[Bit6]
    //Enable Clock Gating on Unused Lanes in a multilane Link:[Bit5]
    //Enable Power down on Unused lanes in a multilane Link:[Bit4]
    //Enable Aggressive Power Management in Rx Path to Data Link Layer Module(DLLM):[Bit3]
    //Turn off TPLL When in L1 state:[Bit0]

    AsiaPcieModifySave8(pciebase, Addr|((UINT64)(CND003_BUSXP1_D1D7F0_AGGRESSIVE_PM) << 32), 
    					CND003_BUSXP1_D1D7F0_RL1DYNPMG2 +
                        CND003_BUSXP1_D1D7F0_RLNCLKPM +
                        CND003_BUSXP1_D1D7F0_RLNPWR +
                        CND003_BUSXP1_D1D7F0_RDSKWPM +
                        CND003_BUSXP1_D1D7F0_RL1TPLLPD,

                        CND003_BUSXP1_D1D7F0_RL1DYNPMG2 +
                        CND003_BUSXP1_D1D7F0_RLNCLKPM +
                        CND003_BUSXP1_D1D7F0_RLNPWR +
                        CND003_BUSXP1_D1D7F0_RDSKWPM +
                        CND003_BUSXP1_D1D7F0_RL1TPLLPD);


    //Enable Aggressive Power Management When No Device Plug:[Bit2]
    AsiaPcieModifySave8(pciebase, Addr|((UINT64)(CND003_BUSXP1_D1D7F0_AGGRESSIVE_PM) << 32), CND003_BUSXP1_D1D7F0_RDEVDETPM, CND003_BUSXP1_D1D7F0_RDEVDETPM);
}


/**
	To saving power, unused port should do some special
	setting
**/
	/**
	  Function description.
	  
	  @param  PeiServices	EFI_PEI_SERVICES pointer.
	  @param SbCfg Point to ASIA_SB_CONFIGURATION struct.
	
	  @return EFI_STATUS.
	
	**/

STATIC
VOID
IoePowerControl(ASIA_NB_CONFIGURATION *NbCfg)
{

	// Enable PCIE Logic AggresivePmMode.
	if(NbCfg->IOESPEValue == CHIP_SPE_VALUE_ENERGY){
		IoeAggresivePmMode(NbCfg, CND003_PEA0);
		IoeAggresivePmMode(NbCfg, CND003_PEA1);
		IoeAggresivePmMode(NbCfg, CND003_PEA2);
		IoeAggresivePmMode(NbCfg, CND003_PEA3);
		IoeAggresivePmMode(NbCfg, CND003_PEA4);
		IoeAggresivePmMode(NbCfg, CND003_PEB0);
		IoeAggresivePmMode(NbCfg, CND003_PEB1);
	}else if(NbCfg->NBSPEValue  == CHIP_SPE_VALUE_MANUAL){
		if(NbCfg->IOEXp1D1F0SPEValue == CHIP_SPE_VALUE_ENERGY){
			IoeAggresivePmMode(NbCfg, CND003_PEA0);
		}
		if(NbCfg->IOEXp1D2F0SPEValue == CHIP_SPE_VALUE_ENERGY){
			IoeAggresivePmMode(NbCfg, CND003_PEA1);
		}
		if(NbCfg->IOEXp1D3F0SPEValue == CHIP_SPE_VALUE_ENERGY){
			IoeAggresivePmMode(NbCfg, CND003_PEA2);
		}
		if(NbCfg->IOEXp1D4F0SPEValue == CHIP_SPE_VALUE_ENERGY){
			IoeAggresivePmMode(NbCfg, CND003_PEA3);
		}
		if(NbCfg->IOEXp1D5F0SPEValue == CHIP_SPE_VALUE_ENERGY){
			IoeAggresivePmMode(NbCfg, CND003_PEA4);
		}
		if(NbCfg->IOEXp1D6F0SPEValue == CHIP_SPE_VALUE_ENERGY){
			IoeAggresivePmMode(NbCfg, CND003_PEB0);
		}
		if(NbCfg->IOEXp1D7F0SPEValue == CHIP_SPE_VALUE_ENERGY){
			IoeAggresivePmMode(NbCfg, CND003_PEB1);
		}			
	}
	
}


/**
[Function for DEBUG]
Function: 
	Clear AER related registers for IOE
Note:
	This function should not be called in genernal
	since the AER status should be remained 
**/

/**
  Function description.
  
  @param  PeiServices	EFI_PEI_SERVICES pointer.
  @param SbCfg Point to ASIA_SB_CONFIGURATION struct.

  @return EFI_STATUS.

**/

STATIC
VOID 
IoeClearDnPortSlotStatus(
    ASIA_NB_CONFIGURATION *NbCfg
)
{
	if(NbCfg->IoeDnPortCtl != 1){
		return;
	}
  
    // uncorrectable errors Rx104    ---   corrrectable errors Rx110
    // Note:Those status also cleared in IoeAerStatusClear()
    if(NbCfg->IoePEA0Ctl== 1){
		//Clear DN_Rx1F[7:4]
		AsiaPciModifySave8(CND003_PEA0|CND003_BUSXP1_D1D7F0_SECONDARY_STA+1, 0xF0, 0xF0);
		// Clear DN_Rx4A[3:0] - F/N-F/Cor/UR  Error Status
    	// Note:Those status also cleared in IoeAerStatusClear()	
		AsiaPciModifySave8(CND003_PEA0|CND003_BUSXP1_D1D7F0_DEV_STA_1, 0x0F, 0x0F);
		//Slot status	Rx5A[8,4,3,0]
		AsiaPciWriteSave16(CND003_PEA0|CND003_BUSXP1_D1D7F0_SLOT_STA_1, 0xFFFF);
	    AsiaPcieWriteSave32(NbCfg->PcieBar, CND003_PEA0|((UINT64)(CND003_BUSXP1_D1D7F0_UNCORRECTABLE_ERR_STA) << 32), 0xFFFFFFFF); 
	    AsiaPcieWriteSave32(NbCfg->PcieBar, CND003_PEA0|((UINT64)(CND003_BUSXP1_D1D7F0_CORRECTABLE_ERR_STA) << 32), 0xFFFFFFFF);
	}
	if(NbCfg->IoePEA1Ctl== 1){
		AsiaPciModifySave8(CND003_PEA1|CND003_BUSXP1_D1D7F0_SECONDARY_STA+1, 0xF0, 0xF0);
		AsiaPciModifySave8(CND003_PEA1|CND003_BUSXP1_D1D7F0_DEV_STA_1, 0x0F, 0x0F);
		AsiaPciWriteSave16(CND003_PEA1|CND003_BUSXP1_D1D7F0_SLOT_STA_1, 0xFFFF);
		AsiaPcieWriteSave32(NbCfg->PcieBar, CND003_PEA1|((UINT64)(CND003_BUSXP1_D1D7F0_UNCORRECTABLE_ERR_STA) << 32), 0xFFFFFFFF);
	    AsiaPcieWriteSave32(NbCfg->PcieBar, CND003_PEA1|((UINT64)(CND003_BUSXP1_D1D7F0_CORRECTABLE_ERR_STA) << 32), 0xFFFFFFFF);
    }
	if(NbCfg->IoePEA2Ctl== 1){
    	AsiaPciModifySave8(CND003_PEA2|CND003_BUSXP1_D1D7F0_SECONDARY_STA+1, 0xF0, 0xF0);
		AsiaPciModifySave8(CND003_PEA2|CND003_BUSXP1_D1D7F0_DEV_STA_1, 0x0F, 0x0F);
		AsiaPciWriteSave16(CND003_PEA2|CND003_BUSXP1_D1D7F0_SLOT_STA_1, 0xFFFF);
	    AsiaPcieWriteSave32(NbCfg->PcieBar, CND003_PEA2|((UINT64)(CND003_BUSXP1_D1D7F0_UNCORRECTABLE_ERR_STA) << 32), 0xFFFFFFFF);
	    AsiaPcieWriteSave32(NbCfg->PcieBar, CND003_PEA2|((UINT64)(CND003_BUSXP1_D1D7F0_CORRECTABLE_ERR_STA) << 32), 0xFFFFFFFF);
    }
	if(NbCfg->IoePEA3Ctl== 1){
	    AsiaPciModifySave8(CND003_PEA3|CND003_BUSXP1_D1D7F0_SECONDARY_STA+1, 0xF0, 0xF0);
		AsiaPciModifySave8(CND003_PEA3|CND003_BUSXP1_D1D7F0_DEV_STA_1, 0x0F, 0x0F);
		AsiaPciWriteSave16(CND003_PEA3|CND003_BUSXP1_D1D7F0_SLOT_STA_1, 0xFFFF);
	    AsiaPcieWriteSave32(NbCfg->PcieBar, CND003_PEA3|((UINT64)(CND003_BUSXP1_D1D7F0_UNCORRECTABLE_ERR_STA) << 32), 0xFFFFFFFF);
	    AsiaPcieWriteSave32(NbCfg->PcieBar, CND003_PEA3|((UINT64)(CND003_BUSXP1_D1D7F0_CORRECTABLE_ERR_STA) << 32), 0xFFFFFFFF);
    }
	if(NbCfg->IoePEA4Ctl== 1){
    	AsiaPciModifySave8(CND003_PEA4|CND003_BUSXP1_D1D7F0_SECONDARY_STA+1, 0xF0, 0xF0);
		AsiaPciModifySave8(CND003_PEA4|CND003_BUSXP1_D1D7F0_DEV_STA_1, 0x0F, 0x0F);
		AsiaPciWriteSave16(CND003_PEA4|CND003_BUSXP1_D1D7F0_SLOT_STA_1, 0xFFFF);
	    AsiaPcieWriteSave32(NbCfg->PcieBar, CND003_PEA4|((UINT64)(CND003_BUSXP1_D1D7F0_UNCORRECTABLE_ERR_STA) << 32), 0xFFFFFFFF);
	    AsiaPcieWriteSave32(NbCfg->PcieBar, CND003_PEA4|((UINT64)(CND003_BUSXP1_D1D7F0_CORRECTABLE_ERR_STA) << 32), 0xFFFFFFFF);
    }
	if(NbCfg->IoePEB0Ctl== 1){
    	AsiaPciModifySave8(CND003_PEB0|CND003_BUSXP1_D1D7F0_SECONDARY_STA+1, 0xF0, 0xF0);
		AsiaPciModifySave8(CND003_PEB0|CND003_BUSXP1_D1D7F0_DEV_STA_1, 0x0F, 0x0F);
		AsiaPciWriteSave16(CND003_PEB0|CND003_BUSXP1_D1D7F0_SLOT_STA_1, 0xFFFF);
	    AsiaPcieWriteSave32(NbCfg->PcieBar, CND003_PEA0|((UINT64)(CND003_BUSXP1_D1D7F0_UNCORRECTABLE_ERR_STA) << 32), 0xFFFFFFFF);
	    AsiaPcieWriteSave32(NbCfg->PcieBar, CND003_PEA0|((UINT64)(CND003_BUSXP1_D1D7F0_CORRECTABLE_ERR_STA) << 32), 0xFFFFFFFF);
    }
	if(NbCfg->IoePEB1Ctl== 1){
    	AsiaPciModifySave8(CND003_PEB1|CND003_BUSXP1_D1D7F0_SECONDARY_STA+1, 0xF0, 0xF0);
		AsiaPciModifySave8(CND003_PEB1|CND003_BUSXP1_D1D7F0_DEV_STA_1, 0x0F, 0x0F);
		AsiaPciWriteSave16(CND003_PEB1|CND003_BUSXP1_D1D7F0_SLOT_STA_1, 0xFFFF);
	    AsiaPcieWriteSave32(NbCfg->PcieBar, CND003_PEB1|((UINT64)(CND003_BUSXP1_D1D7F0_UNCORRECTABLE_ERR_STA) << 32), 0xFFFFFFFF);
	    AsiaPcieWriteSave32(NbCfg->PcieBar, CND003_PEB1|((UINT64)(CND003_BUSXP1_D1D7F0_CORRECTABLE_ERR_STA) << 32), 0xFFFFFFFF);
    }
}

/**
  Function description.
  
  @param  PeiServices	EFI_PEI_SERVICES pointer.
  @param SbCfg Point to ASIA_SB_CONFIGURATION struct.

  @return EFI_STATUS.

**/

STATIC
VOID 
IoeProgramRpExitLatency(
    ASIA_NB_CONFIGURATION *NbCfg,
    UINT64	Address
)
{
    UINT8 		iData1;
    UINT32	iData2;

    iData1 = AsiaPcieRead8(NbCfg->PcieBar, Address|(((UINT64)(CND003_BUSXP1_D1D7F0_AGGRESSIVE_PM) << 32))) ;
    iData1 &= BIT0;
    if(iData1 == BIT0){
        iData2 = AsiaPciRead32(Address|CND003_BUSXP1_D1D7F0_LINK_CAPS_1_D1F0 );
        iData2 &= ~(CND003_BUSXP1_D1D7F0_LKL0SE + CND003_BUSXP1_D1D7F0_LKL1EL);
        iData2 |= 0x20000;  //L1 Exit Latency: 8us <= Tl_L1 < 16us    L0s Exit Latency < 1us
        AsiaPciWriteSave32(Address|CND003_BUSXP1_D1D7F0_LINK_CAPS_1_D1F0, iData2);

	}else{
        iData2 = AsiaPciRead32(Address|CND003_BUSXP1_D1D7F0_LINK_CAPS_1_D1F0 );
        iData2 &= ~(CND003_BUSXP1_D1D7F0_LKL0SE + CND003_BUSXP1_D1D7F0_LKL1EL);
        iData2 |= 0x18000;	//L1 Exit Latency: 4us <= Tl_L1 < 8us   L0s Exit Latency < 1us
        AsiaPciWriteSave32(Address|CND003_BUSXP1_D1D7F0_LINK_CAPS_1_D1F0, iData2);
    }
}

/**
  Function description.
  
  @param  PeiServices	EFI_PEI_SERVICES pointer.
  @param SbCfg Point to ASIA_SB_CONFIGURATION struct.

  @return EFI_STATUS.

**/

STATIC
VOID 
IoeSetExitLatencyCapability(
    ASIA_NB_CONFIGURATION *NbCfg
)
{
	AsiaPciModifySave8(CND003_XBCTL|CND003_MMIO_D0F0_BACKDOOR_REG_CTL_0, CND003_MMIO_D0F0_RPEROWEN,CND003_MMIO_D0F0_RPEROWEN);
    IoeProgramRpExitLatency(NbCfg, CND003_PEA0);
    IoeProgramRpExitLatency(NbCfg, CND003_PEA1);
    IoeProgramRpExitLatency(NbCfg, CND003_PEA2);
    IoeProgramRpExitLatency(NbCfg, CND003_PEA3);
    IoeProgramRpExitLatency(NbCfg, CND003_PEA4);
    IoeProgramRpExitLatency(NbCfg, CND003_PEB0);
	IoeProgramRpExitLatency(NbCfg, CND003_PEB1);
	AsiaPciModifySave8(CND003_XBCTL|CND003_MMIO_D0F0_BACKDOOR_REG_CTL_0, CND003_MMIO_D0F0_RPEROWEN,0);

}

/**
  Function description.
  
  @param  PeiServices	EFI_PEI_SERVICES pointer.
  @param SbCfg Point to ASIA_SB_CONFIGURATION struct.

  @return EFI_STATUS.

**/

STATIC
VOID 
IoeSetRPSlotPowerLimit(
    ASIA_NB_CONFIGURATION *NbCfg
)
{
	AsiaPciModifySave8(CND003_XBCTL|CND003_MMIO_D0F0_BACKDOOR_REG_CTL_0, CND003_MMIO_D0F0_RPEROWEN,CND003_MMIO_D0F0_RPEROWEN);

	//Set "Slot Power Limut Value" and "Slot Power Limit Scale" to 75W meet the PCIE GEN3 SPEC
	AsiaPcieModifySave16(NbCfg->PcieBar, CND003_PEA0|((UINT64)(CND003_BUSXP1_D1D7F0_SLOT_CAPS_1) << 32), CND003_BUSXP1_D1D7F0_RSPLV, 0x2580);
	AsiaPcieModifySave16(NbCfg->PcieBar, CND003_PEA1|((UINT64)(CND003_BUSXP1_D1D7F0_SLOT_CAPS_1) << 32), CND003_BUSXP1_D1D7F0_RSPLV, 0x2580);
	AsiaPcieModifySave16(NbCfg->PcieBar, CND003_PEA2|((UINT64)(CND003_BUSXP1_D1D7F0_SLOT_CAPS_1) << 32), CND003_BUSXP1_D1D7F0_RSPLV, 0x2580);
	AsiaPcieModifySave16(NbCfg->PcieBar, CND003_PEA3|((UINT64)(CND003_BUSXP1_D1D7F0_SLOT_CAPS_1) << 32), CND003_BUSXP1_D1D7F0_RSPLV, 0x2580);
	AsiaPcieModifySave16(NbCfg->PcieBar, CND003_PEA4|((UINT64)(CND003_BUSXP1_D1D7F0_SLOT_CAPS_1) << 32), CND003_BUSXP1_D1D7F0_RSPLV, 0x2580);
	AsiaPcieModifySave16(NbCfg->PcieBar, CND003_PEB0|((UINT64)(CND003_BUSXP1_D1D7F0_SLOT_CAPS_1) << 32), CND003_BUSXP1_D1D7F0_RSPLV, 0x2580);
	AsiaPcieModifySave16(NbCfg->PcieBar, CND003_PEB1|((UINT64)(CND003_BUSXP1_D1D7F0_SLOT_CAPS_1) << 32), CND003_BUSXP1_D1D7F0_RSPLV, 0x2580);

	AsiaPciModifySave8(CND003_XBCTL|CND003_MMIO_D0F0_BACKDOOR_REG_CTL_0, CND003_MMIO_D0F0_RPEROWEN,0);

	
}

/**
	1) Dxe SPE value set
	2) Power related registers setting
**/

/**
  Function description.
  
  @param  PeiServices	EFI_PEI_SERVICES pointer.
  @param SbCfg Point to ASIA_SB_CONFIGURATION struct.

  @return EFI_STATUS.

**/

STATIC
EFI_STATUS
IoeFillSpeValue(ASIA_NB_CONFIGURATION *NbCfg)
{
	EFI_STATUS Statusx = EFI_SUCCESS;	

	//if(!IoeExist()){
	//	DEBUG((EFI_D_ERROR, "[CJW_IOE] SKIP CND003 Init (5)\n"));
	//	return Statusx;
	//}

	// Assign the temp bus number
	//Statusx = IoeFindAndAssign(MbRpTblList, sizeof(MbRpTblList)/sizeof(RpList),NULL);
	

	// If not found IOE, exit directly
	//if(Statusx != EFI_SUCCESS){
	//	return Statusx;
	//}


	//
	// S/P/E value setting
	//
	DEBUG((EFI_D_ERROR, "[CJW_IOE] Ioe SPE value setting <--Start\n"));
	
	// Initialize the setup
	IoeSpeSettingInit(NbCfg);

	// Real SPE value setting
	IoePcieSpeSetting(NbCfg);
	
	DEBUG((EFI_D_ERROR, "[CJW_IOE] Ioe SPE value setting -->End\n"));

//#ifdef CND003_A0
	//
	// More power related setting 
	//
	//IoePowerControl(NbCfg);

	//IoeClearDnPortSlotStatus(NbCfg);
	
	//IoeSetExitLatencyCapability(NbCfg);
	//IoeSetRPSlotPowerLimit();
//#endif
	

	// Clear the temp bus number
	//IoeClearAssignment(MbRpTblList, sizeof(MbRpTblList)/sizeof(RpList),NULL);
	//IoeDxeClearTempAssignment();

	return Statusx;
}




/**
	[CJW_IOE]
	This function was used to Hide XBCTL and EPTRFC
	called by IoeHideXbctlEptrfcDxe()
**/

/**
  Function description.
  
  @param  PeiServices	EFI_PEI_SERVICES pointer.
  @param SbCfg Point to ASIA_SB_CONFIGURATION struct.

  @return EFI_STATUS.

**/

STATIC
EFI_STATUS
IoeHideXbctlEptrfc(
	IN RpList *PortList,
	IN UINT8 RpCounts,
	ASIA_NB_CONFIGURATION *NbCfg)
{
	EFI_STATUS Statusx = EFI_SUCCESS;
	UINT32 MmioBase;
	//UINT8 ix;
	//UINT32 VidTemp;
	//UINT8 Bx,Dx,Fx;
	
	DEBUG((EFI_D_ERROR, "[CJW_IOE] [Hide] ->Start hide XBCTL & EPTRFC depend on SetupMenu\n"));
/*
	for(ix = 0; ix < RpCounts; ix++){
		//Read VID
		AsiaPciWrite8(AsiaPciAddress(PortList[ix].Bus, PortList[ix].Dev, PortList[ix].Func, 0x18), BUS0);
		AsiaPciWrite8(AsiaPciAddress(PortList[ix].Bus, PortList[ix].Dev, PortList[ix].Func, 0x19), BUSX);
		AsiaPciWrite8(AsiaPciAddress(PortList[ix].Bus, PortList[ix].Dev, PortList[ix].Func, 0x1A), BUSXP3);
		
		VidTemp = AsiaPciRead32(AsiaPciAddress(BUSX, UPPORT_DEV, UPPORT_FUN, 0));
		DEBUG((EFI_D_ERROR, "                 VID: %08X\n",VidTemp));
		if((VidTemp == IOEBUSXUSP_VIDDID)||(VidTemp == IOEBUSXUSP_VIDDID_ZX)){
			DEBUG((EFI_D_ERROR, "                 -->Under [%d|%d|%d]: Exist IOE!\n",
				PortList[ix].Bus, PortList[ix].Dev, PortList[ix].Func));

			goto __IoeLoc;
		}else{
			DEBUG((EFI_D_ERROR, "                 -->Under [%d|%d|%d]: Empty!\n",
				PortList[ix].Bus, PortList[ix].Dev, PortList[ix].Func));

			AsiaPciWrite8(AsiaPciAddress(PortList[ix].Bus, PortList[ix].Dev, PortList[ix].Func, 0x19), 0x0);
			AsiaPciWrite8(AsiaPciAddress(PortList[ix].Bus, PortList[ix].Dev, PortList[ix].Func, 0x1A), 0x0);			
		}
	}

	Statusx = EFI_NOT_FOUND;
	return Statusx;
	
__IoeLoc:
	AsiaPciWrite8(AsiaPciAddress(PortList[ix].Bus, PortList[ix].Dev, PortList[ix].Func, 0x19), 0x0);
	AsiaPciWrite8(AsiaPciAddress(PortList[ix].Bus, PortList[ix].Dev, PortList[ix].Func, 0x1A), 0x0);	


	Bx = PortList[ix].Bus;
	Dx = PortList[ix].Dev;
	Fx = PortList[ix].Func;

	AsiaPcieWriteSave32(PCI_BASE, AsiaPciAddress(Bx, Dx, Fx, 0x20), (BUSX_MMIO_BAR&0xFFFF0000)|((BUSX_MMIO_BAR>>16)&0xFFFF));
	AsiaPcieWriteSave8(PCI_BASE, AsiaPciAddress(Bx, Dx, Fx, 0x19), BUSX);
	AsiaPcieWriteSave8(PCI_BASE, AsiaPciAddress(Bx, Dx, Fx, 0x1A), BUSX+1);
	AsiaPcieWriteSave8(PCI_BASE, AsiaPciAddress(Bx, Dx, Fx, 0x04), 0x7);
	AsiaPcieWriteSave32(PCI_BASE, AsiaPciAddress(BUSX, UPPORT_DEV, UPPORT_DEV, 0x10), BUSX_MMIO_BAR);
	AsiaPcieWriteSave8(PCI_BASE, AsiaPciAddress(BUSX, UPPORT_DEV, UPPORT_DEV, 0x18), BUSX);
	AsiaPcieWriteSave8(PCI_BASE, AsiaPciAddress(BUSX, UPPORT_DEV, UPPORT_DEV, 0x19), BUSX+1);
	AsiaPcieWriteSave8(PCI_BASE, AsiaPciAddress(BUSX, UPPORT_DEV, UPPORT_DEV, 0x1A), BUSX+1);
*/
	DEBUG((EFI_D_ERROR, "[CJW_IOE] [Hide] %d(XBCTL)  %d(EPTRFC)\n",NbCfg->Cnd003HideXbctl,NbCfg->Cnd003HideEptrfc));
	DEBUG((EFI_D_ERROR, "                 Before configure:\n"));
	IoeDumpCfgDxe(NbCfg->PcieBar, BUSXP1, XBCTL, DNPORT_FUN, 0x10);
	IoeDumpCfgDxe(NbCfg->PcieBar, BUSXP3, EPTRFC_DEV, EPTRFC_FUN, 0x10);

	// Hide XBCTL
	if(NbCfg->Cnd003HideXbctl == 1){
		AsiaPciModifySave8(AsiaPciAddress(BUSX, UPPORT_DEV, UPPORT_FUN, CND003_BUSX_D0F0_VEN_CTL), BIT2, BIT2);
		while(AsiaPciRead32(AsiaPciAddress(BUSXP1, XBCTL, DNPORT_FUN, 0)) != 0xFFFFFFFF); //to make sure that XBCTL have hidden successful
	}else{
		AsiaPciModifySave8(AsiaPciAddress(BUSX, UPPORT_DEV, UPPORT_FUN, CND003_BUSX_D0F0_VEN_CTL), BIT2, 0);	
	}

	MmioBase = AsiaPciRead32(AsiaPciAddress(BUSX, UPPORT_DEV, UPPORT_FUN, 0x10));

	// Hide EPTRFC
	if(NbCfg->Cnd003HideEptrfc == 1){
		AsiaMemoryModifySave8(MmioBase+MMIO_ISB_OFFSET+CND003_MMIO_D0F0_CKGSRC_SETTING_GRP2, BIT7, BIT7);
	}else{
		AsiaMemoryModifySave8(MmioBase+MMIO_ISB_OFFSET+CND003_MMIO_D0F0_CKGSRC_SETTING_GRP2, BIT7, 0);
	}
	
	DEBUG((EFI_D_ERROR, "                 After configure:\n"));
	
	IoeDumpCfgDxe(NbCfg->PcieBar, BUSXP1, XBCTL, DNPORT_FUN, 0x10);
	IoeDumpCfgDxe(NbCfg->PcieBar, BUSXP3, EPTRFC_DEV, EPTRFC_FUN, 0x10);
/*
	AsiaPcieWriteSave8(PCI_BASE, AsiaPciAddress(BUSX, UPPORT_DEV, UPPORT_DEV, 0x19), BUSX+1);	
	AsiaPcieWriteSave8(PCI_BASE, AsiaPciAddress(BUSX, UPPORT_DEV, UPPORT_DEV, 0x1A), BUSX+1);
	AsiaPcieWriteSave8(PCI_BASE, AsiaPciAddress(BUSX, UPPORT_DEV, UPPORT_DEV, 0x18), BUSX);
	AsiaPciWriteSave32(AsiaPciAddress(BUSX, UPPORT_DEV, UPPORT_FUN, 0x10), 0);
	AsiaPciWriteSave32(AsiaPciAddress(Bx, Dx, Fx, 0x20), 0);
	AsiaPciWriteSave8(AsiaPciAddress(Bx, Dx, Fx, 0x19), 0);
	AsiaPciWriteSave8(AsiaPciAddress(Bx, Dx, Fx, 0x1A), 0);
*/		
	return Statusx;

}

/**
Founction:
	Set some 'power save' ralated registers for a 
	downstream ports(which without device behind it)
Note:
	1) Addr: Addr of a DN port
	2) this function must be called in CND003 bus temp
		assignment environment
**/

/**
  Function description.
  
  @param  PeiServices	EFI_PEI_SERVICES pointer.
  @param SbCfg Point to ASIA_SB_CONFIGURATION struct.

  @return EFI_STATUS.

**/

EFI_STATUS
IoePciePowerDownDnPort(
	ASIA_NB_CONFIGURATION *NbCfg, 
	UINT64 Addr)
{
	//UINT8 HotPlugCapable = 0;
		UINT8 CardPresentFlag = 0;
		UINT64 Pciebase;
		UINT8 Rx1E8_2_Flag;
	
		Pciebase = NbCfg->PcieBar;
		
		// Card present behind this downstream port?
		CardPresentFlag = AsiaPciRead8(Addr|CND003_BUSXP1_D1D7F0_SLOT_STA_1);
		CardPresentFlag &= CND003_BUSXP1_D1D7F0_SPDCST;
			
		// this is a Hotplug capable port?
		//HotPlugCapable = AsiaPciRead8(Addr|CND003_BUSXP1_D1D7F0_SLOT_CAPS_1);
		//HotPlugCapable &= CND003_BUSXP1_D1D7F0_SCHP_CAP;
	
		/*DEBUG((EFI_D_ERROR, "[CJW_IOE] [%d|%d|%d] -->HP_Cap = %d, CardPRSNT = %d\n",
					(UINT8)RShiftU64(Addr, 24), 
					(UINT8)RShiftU64(Addr, 16),
					(UINT8)RShiftU64(Addr, 8), 
					HotPlugCapable?1:0, 
					CardPresentFlag?1:0));*/
		
		// If card not present
		if(CardPresentFlag != CND003_BUSXP1_D1D7F0_SPDCST){
	
			Rx1E8_2_Flag = CND003_BUSXP1_D1D7F0_RDEVDETPM & AsiaPcieRead8(Pciebase, Addr|((UINT64)(CND003_BUSXP1_D1D7F0_AGGRESSIVE_PM) << 32));
			
			// Rx1E8[2]=0b	 BIT2 must be cleared before BIT1 set to 1b --- same with SOC RP
			AsiaPcieModifySave8(Pciebase, Addr|((UINT64)(CND003_BUSXP1_D1D7F0_AGGRESSIVE_PM) << 32), 
									CND003_BUSXP1_D1D7F0_RDEVDETPM, 0);
			// Rx1E8[1]=1b	 Set this bit to 1 only when there is no device existing behind this downstream port.
			AsiaPcieModifySave8(Pciebase, Addr|((UINT64)(CND003_BUSXP1_D1D7F0_AGGRESSIVE_PM) << 32), 
									CND003_BUSXP1_D1D7F0_RPDL2, CND003_BUSXP1_D1D7F0_RPDL2);
			
				// Rx1E8[7] = 1b
			AsiaPcieModifySave8(Pciebase, Addr|((UINT64)(CND003_BUSXP1_D1D7F0_AGGRESSIVE_PM) << 32), 
										CND003_BUSXP1_D1D7F0_RRXEIDPD, CND003_BUSXP1_D1D7F0_RRXEIDPD);
	
			if(Rx1E8_2_Flag != 0){
				//Rx1E8[2]=1b (for E mode)
				AsiaPcieModifySave8(Pciebase, Addr|((UINT64)(CND003_BUSXP1_D1D7F0_AGGRESSIVE_PM) << 32), 
										CND003_BUSXP1_D1D7F0_RDEVDETPM, CND003_BUSXP1_D1D7F0_RDEVDETPM);
			}
	
			
		}else{
			// Rx1E8[2]=0b	 Set this bit to 1 only when there is no device existing behind this downstream port.
			AsiaPcieModifySave8(Pciebase, Addr|((UINT64)(CND003_BUSXP1_D1D7F0_AGGRESSIVE_PM) << 32), 
									CND003_BUSXP1_D1D7F0_RPDL2, 0);
		}
	
	
		return EFI_SUCCESS;

}

/**
Founction:
	Set some 'power save' ralated registers for some 
	downstream ports(which without device behind them)
Note:
	1) this function must be called in CND003 bus temp
		assignment environment
	2) those registers will be set only in E mode
**/

/**
  Function description.
  
  @param  PeiServices	EFI_PEI_SERVICES pointer.
  @param SbCfg Point to ASIA_SB_CONFIGURATION struct.

  @return EFI_STATUS.

**/

EFI_STATUS
IoePcieArrgessivePM(
	ASIA_NB_CONFIGURATION *NbCfg)
{
	
	DEBUG((EFI_D_ERROR, "[CJW_IOE] %a():\n",__FUNCTION__));

	if((NbCfg->IOEXp1D1F0SPEValue == CHIP_SPE_VALUE_ENERGY)||
		(NbCfg->IOESPEValue == CHIP_SPE_VALUE_ENERGY)){
		if((NbCfg->IoePEA0Ctl == 1)&&(NbCfg->IoeDnPortCtl == 1)){
			IoePciePowerDownDnPort(NbCfg, CND003_PEA0);
		}
	}

	if((NbCfg->IOEXp1D2F0SPEValue == CHIP_SPE_VALUE_ENERGY)||
		(NbCfg->IOESPEValue == CHIP_SPE_VALUE_ENERGY)){
		if((NbCfg->IoePEA1Ctl == 1)&&(NbCfg->IoeDnPortCtl == 1)){
			IoePciePowerDownDnPort(NbCfg, CND003_PEA1);
		}
	}

	if((NbCfg->IOEXp1D3F0SPEValue == CHIP_SPE_VALUE_ENERGY)||
		(NbCfg->IOESPEValue == CHIP_SPE_VALUE_ENERGY)){
		if((NbCfg->IoePEA2Ctl == 1)&&(NbCfg->IoeDnPortCtl == 1)){
			IoePciePowerDownDnPort(NbCfg, CND003_PEA2);
		}
	}

	if((NbCfg->IOEXp1D4F0SPEValue == CHIP_SPE_VALUE_ENERGY)||
		(NbCfg->IOESPEValue == CHIP_SPE_VALUE_ENERGY)){
		if((NbCfg->IoePEA3Ctl == 1)&&(NbCfg->IoeDnPortCtl == 1)){
			IoePciePowerDownDnPort(NbCfg, CND003_PEA3);
		}
	}

	if((NbCfg->IOEXp1D5F0SPEValue == CHIP_SPE_VALUE_ENERGY)||
		(NbCfg->IOESPEValue == CHIP_SPE_VALUE_ENERGY)){
		if((NbCfg->IoePEA4Ctl == 1)&&(NbCfg->IoeDnPortCtl == 1)){
			IoePciePowerDownDnPort(NbCfg, CND003_PEA4);
		}
	}

	if((NbCfg->IOEXp1D6F0SPEValue == CHIP_SPE_VALUE_ENERGY)||
		(NbCfg->IOESPEValue == CHIP_SPE_VALUE_ENERGY)){
		if((NbCfg->IoePEB0Ctl == 1)&&(NbCfg->IoeDnPortCtl == 1)){
			IoePciePowerDownDnPort(NbCfg, CND003_PEB0);
		}
	}

	if((NbCfg->IOEXp1D7F0SPEValue == CHIP_SPE_VALUE_ENERGY)||
		(NbCfg->IOESPEValue == CHIP_SPE_VALUE_ENERGY)){
		if((NbCfg->IoePEB1Ctl == 1)&&(NbCfg->IoeDnPortCtl == 1)){
			IoePciePowerDownDnPort(NbCfg, CND003_PEB1);
		}
	}

	return EFI_SUCCESS;
}



/**
Function:
	Calling this routine to Hide EPTRFC or XBCTL according to 
	the setup data
Note: 
	The behaviour of "Hiding" will be save into BootScript and 
	will also be set in S3 resume process. however, the IOE fw 
	load code will run after the execution of BootScript, so Fw 
	load code need to guarantee the visuality of EPTRFC, this 
	is special attention.
**/

/**
  Function description.
  
  @param  PeiServices	EFI_PEI_SERVICES pointer.
  @param SbCfg Point to ASIA_SB_CONFIGURATION struct.

  @return EFI_STATUS.

**/

VOID
IoeHideXbctlEptrfcDxe(
	ASIA_NB_CONFIGURATION *NbCfg)
{
	EFI_STATUS Statusx;

	if(!IoeExist()){
		DEBUG((EFI_D_ERROR, "[CJW_IOE] SKIP CND003 Init (3)\n"));
		return;
	}

	if(NbCfg->Cnd003ModeSel == BIOS_MODE){

		Statusx = IoeDxeTempAssignment();
		if(Statusx != EFI_SUCCESS){
			DEBUG((EFI_D_ERROR, "[CJW_IOE] Not Found Ioe - DXE[Hide]\n"));
			return;
		}
		
		IoeHideXbctlEptrfc(MbRpTblList, sizeof(MbRpTblList)/sizeof(RpList), NbCfg);	

		IoeDxeClearTempAssignment();

	}else{
		DEBUG((EFI_D_ERROR, "[CJW_IOE] [Hide] In SPI mode --> Not Perform Hide Operation.\n"));
	}
}





/**
	This is the resource assignment table for IOE
**/
DxeRegSet DxeAssignTempx[] = {
// ByteCounts, 	Bus, 		Dev, 		Func, 		Offset, 	Mask, 			Value	
	SET_4BYTE, 	BUSXP3, 	DEV_GNIC, 	FUN_GNIC,  	D13F0_CSR_MEM_MAPPED_BASE_ADDR_REGS,		0xFFFFFFFF, 	BUSXP3_GNIC_BAR1_BASE,
	SET_4BYTE, 	BUSXP3, 	DEV_GNIC, 	FUN_GNIC,  	D13F0_MSI_X_MEM_MAPPED_BASE_ADDR_REGS,		0xFFFFFFFF, 	BUSXP3_GNIC_BAR2_BASE,
	SET_4BYTE, 	BUSX, 		UPPORT_DEV,	UPPORT_FUN, CND003_BUSX_D0F0_LOWER_BASE_ADR,			0xFFFFFFFF, 	BUSX_BAR0_BASE,	
	SET_4BYTE, 	BUSXP2, 	PCIEIF_DEV, PCIEIF_FUN, CND003_BUSX2_D0F0_MEM_BASE,					0xFFFFFFFF, 	MEM_BASE_LIMIT,
	SET_4BYTE, 	BUSXP1, 	PESB,	 	DNPORT_FUN, CND003_BUSXP1_D8F0_MEM_BASE,				0xFFFFFFFF, 	MEM_BASE_LIMIT,
	SET_4BYTE, 	BUSX, 		UPPORT_DEV,	UPPORT_FUN, CND003_BUSX_D0F0_MEM_BASE,					0xFFFFFFFF, 	MEM_BASE_LIMIT,
	SET_1BYTE,	BUSXP3,		DEV_GNIC,	FUN_GNIC,	D13F0_DEV_CMD_AND_STA,						0x03,			0x03,
	SET_1BYTE,	BUSXP2,		PCIEIF_DEV,	PCIEIF_FUN,	CND003_BUSX2_D0F0_PCI_CMD,					0x03,			0x03,
	SET_1BYTE,	BUSXP1,		PESB,		DNPORT_FUN,	CND003_BUSXP1_D8F0_PCI_CMD,					0x03,			0x03,
	SET_1BYTE,	BUSX,		UPPORT_DEV,	UPPORT_FUN,	CND003_BUSX_D0F0_PCI_CMD,					0x03,			0x03,
};


/**
	Temp Assignment
	Call this routine to set table DxeAssignTempx[] into Hardware
**/

/**
  Function description.
  
  @param  PeiServices	EFI_PEI_SERVICES pointer.
  @param SbCfg Point to ASIA_SB_CONFIGURATION struct.

  @return EFI_STATUS.

**/

EFI_STATUS
IoeDxeTA(VOID)
{
	UINT16 ix;
	DEBUG((EFI_D_ERROR, "[CJW_IOE_ASSIGN] =>=> \n\r"));
	for(ix = 0; ix < sizeof(DxeAssignTempx)/sizeof(DxeRegSet); ix++){
		if(DxeAssignTempx[ix].ByteCount  == SET_4BYTE){
			AsiaPciModifySave32(
				AsiaPciAddress(DxeAssignTempx[ix].Busx, DxeAssignTempx[ix].Devx, DxeAssignTempx[ix].Funx, DxeAssignTempx[ix].Offsetx), 
				DxeAssignTempx[ix].Maskx, DxeAssignTempx[ix].Valuex);
			//DEBUG((EFI_D_ERROR, "[CJW_IOE_ASSIGN] => [%d|%d|%d] Rx%x=0x%08x\n\r",
			//	DxeAssignTempx[ix].Busx,DxeAssignTempx[ix].Devx,DxeAssignTempx[ix].Funx,DxeAssignTempx[ix].Offsetx,
			//	AsiaPciRead32(AsiaPciAddress(DxeAssignTempx[ix].Busx, DxeAssignTempx[ix].Devx, DxeAssignTempx[ix].Funx, DxeAssignTempx[ix].Offsetx))));
		}else if(DxeAssignTempx[ix].ByteCount  == SET_1BYTE){
			AsiaPciModifySave8(
				AsiaPciAddress(DxeAssignTempx[ix].Busx, DxeAssignTempx[ix].Devx, DxeAssignTempx[ix].Funx, DxeAssignTempx[ix].Offsetx), 
				(UINT8)(DxeAssignTempx[ix].Maskx), (UINT8)(DxeAssignTempx[ix].Valuex));		
			//DEBUG((EFI_D_ERROR, "[CJW_IOE_ASSIGN] => [%d|%d|%d] Rx%x=0x%02x\n\r",
			//	DxeAssignTempx[ix].Busx, DxeAssignTempx[ix].Devx, DxeAssignTempx[ix].Funx, DxeAssignTempx[ix].Offsetx,
			//	AsiaPciRead8(AsiaPciAddress(DxeAssignTempx[ix].Busx, DxeAssignTempx[ix].Devx, DxeAssignTempx[ix].Funx, DxeAssignTempx[ix].Offsetx))));
		}else{
			DEBUG((EFI_D_ERROR, "[CJW_IOE_ASSIGN] Bad ByteCount!\n"));
		}
	}	
	return EFI_SUCCESS;
}


/**
	Temp assigment clear
	Call this routine to clear the setting of the table DxeAssignTempx[]
**/

/**
  Function description.
  
  @param  PeiServices	EFI_PEI_SERVICES pointer.
  @param SbCfg Point to ASIA_SB_CONFIGURATION struct.

  @return EFI_STATUS.

**/

EFI_STATUS
IoeDxeTAC(VOID)
{
	UINT16 ix;
	DEBUG((EFI_D_ERROR,"[CJW_IOE_CLEAR] <=<=\n\r"));
	for(ix = 0; ix < sizeof(DxeAssignTempx)/sizeof(DxeRegSet); ix++){
		if(DxeAssignTempx[ix].ByteCount  == SET_4BYTE){
			AsiaPciModifySave32(
				AsiaPciAddress(DxeAssignTempx[ix].Busx, DxeAssignTempx[ix].Devx, DxeAssignTempx[ix].Funx, DxeAssignTempx[ix].Offsetx), 
				DxeAssignTempx[ix].Maskx, 0);
			//DEBUG((EFI_D_ERROR,"                 => [%d|%d|%d] Rx%x=0x%08x\n\r",
			//	DxeAssignTempx[ix].Busx,DxeAssignTempx[ix].Devx,DxeAssignTempx[ix].Funx,DxeAssignTempx[ix].Offsetx,
			//	AsiaPciRead32(AsiaPciAddress(DxeAssignTempx[ix].Busx, DxeAssignTempx[ix].Devx, DxeAssignTempx[ix].Funx, DxeAssignTempx[ix].Offsetx))));
		}else if(DxeAssignTempx[ix].ByteCount  == SET_1BYTE){
			AsiaPciModifySave8(
				AsiaPciAddress(DxeAssignTempx[ix].Busx, DxeAssignTempx[ix].Devx, DxeAssignTempx[ix].Funx, DxeAssignTempx[ix].Offsetx), 
				(UINT8)(DxeAssignTempx[ix].Maskx), 0);		
			//DEBUG((EFI_D_ERROR, "                => [%d|%d|%d] Rx%x=0x%02x\n\r",
			//	DxeAssignTempx[ix].Busx,DxeAssignTempx[ix].Devx,DxeAssignTempx[ix].Funx,DxeAssignTempx[ix].Offsetx,
			//	AsiaPciRead8(AsiaPciAddress(DxeAssignTempx[ix].Busx, DxeAssignTempx[ix].Devx, DxeAssignTempx[ix].Funx, DxeAssignTempx[ix].Offsetx))));
		}else{
			DEBUG((EFI_D_ERROR,"[CJW_IOE_CLEAR] Bad ByteCount!\n"));
		}
	}	
	return EFI_SUCCESS;
}

/**
	This routine can be called for temp bus assignment by other module
**/

/**
  Function description.
  
  @param  PeiServices	EFI_PEI_SERVICES pointer.
  @param SbCfg Point to ASIA_SB_CONFIGURATION struct.

  @return EFI_STATUS.

**/

EFI_STATUS
IoeDxeTempAssignment(VOID)
{
	UINT8 Tblx;
	EFI_STATUS Statusx = EFI_SUCCESS;
	
	DEBUG((EFI_D_ERROR,"[CJW_IOE]-------------------------------------------------------------------------------------> \n"));
	DEBUG((EFI_D_ERROR,"         ------------------------------------------------------------------------------------->Assign Start\n"));
	
	Statusx = IoeFindAndAssign(MbRpTblList, sizeof(MbRpTblList)/sizeof(RpList),&Tblx);
	if(Statusx != EFI_SUCCESS){
		DEBUG((EFI_D_ERROR, "[CJW_IOE] Not Found IOE - DXE\n"));
		return Statusx;
	}

	AsiaPciModifySave8(AsiaPciAddress(MbRpTblList[Tblx].Bus, MbRpTblList[Tblx].Dev, MbRpTblList[Tblx].Func, 0x04), 0x07, 0x02);
	AsiaPciModifySave16(AsiaPciAddress(MbRpTblList[Tblx].Bus, MbRpTblList[Tblx].Dev, MbRpTblList[Tblx].Func, 0x20), 0xFFFF, RP_MEM_BASE);
	AsiaPciModifySave16(AsiaPciAddress(MbRpTblList[Tblx].Bus, MbRpTblList[Tblx].Dev, MbRpTblList[Tblx].Func, 0x22), 0xFFFF, RP_MEM_LIMIT);

	IoeDxeTA();
	
	return Statusx;
}


/**
	After register initialization, calling this routine 
	to clear the temp resource assignment 
**/

/**
  Function description.
  
  @param  PeiServices	EFI_PEI_SERVICES pointer.
  @param SbCfg Point to ASIA_SB_CONFIGURATION struct.

  @return EFI_STATUS.

**/

VOID
IoeDxeClearTempAssignment(VOID)
{
	UINT8 Tblx;
	
	IoeDxeTAC();
	IoeClearAssignment(MbRpTblList, sizeof(MbRpTblList)/sizeof(RpList),&Tblx);

	AsiaPciModifySave8(AsiaPciAddress(MbRpTblList[Tblx].Bus, MbRpTblList[Tblx].Dev, MbRpTblList[Tblx].Func, 0x04), 0x07, 0);
	AsiaPciModifySave16(AsiaPciAddress(MbRpTblList[Tblx].Bus, MbRpTblList[Tblx].Dev, MbRpTblList[Tblx].Func, 0x20), 0xFFFF, 0);
	AsiaPciModifySave16(AsiaPciAddress(MbRpTblList[Tblx].Bus, MbRpTblList[Tblx].Dev, MbRpTblList[Tblx].Func, 0x22), 0xFFFF, 0);

	DEBUG((EFI_D_ERROR,"         <------------------------------------------------------------------------------------Clear Assignment\n"));
	DEBUG((EFI_D_ERROR,"[CJW_IOE]<------------------------------------------------------------------------------------\n"));

}


















//[CJW_IOE]
//AER status clear
/**
	Function: Calling this routine to clear 
			all AER related status bits on 
			the specific Pcie port
**/

/**
  Function description.
  
  @param  PeiServices	EFI_PEI_SERVICES pointer.
  @param SbCfg Point to ASIA_SB_CONFIGURATION struct.

  @return EFI_STATUS.

**/

VOID
IoeAerStatusClear(
	UINTN Bus, 
	UINTN Device, 
	UINTN Function)
{
	UINT8 Busx,Devx,Funcx;
	UINT8  pointer,nextp,CapID;
	UINT16 CapID2,p1,np1;

	if(!IoeExist()){
		DEBUG((EFI_D_ERROR, "[CJW_IOE] SKIP CND003 Init [IoeAerStatusClear()]\n"));
		return;
	}

	Busx = (UINT8)Bus;
	Devx = (UINT8)Device;
	Funcx = (UINT8)Function;
	
	//PEI_DEBUG((PeiServices, EFI_D_ERROR, "[CJW_AER] <5>\n"));
	//whether this is a PCIE device or not
	pointer = 0x34;
	pointer = AsiaPcieRead8(PCI_BASE, AsiaPciAddress(Busx, Devx, Funcx, pointer));

	//
	// if device not exist , exit to scan next device
	//
	if(pointer == 0xFF){ //this device not exist
		//PEI_DEBUG((PeiServices, EFI_D_ERROR, "[CJW_AER] [%d|%d|%d] Device Not Exist\n",Bus,Dev,Func));
		goto __GoOut;
	}
	//
	// search PCI Express Capability
	// - if yes, break;
	// - if not, search next one
	// - if last on still not, break
	//
	while(1){	
		CapID = AsiaPcieRead8(PCI_BASE, AsiaPciAddress(Busx, Devx, Funcx, pointer));
		//
		// Found Pcie capability
		//
		if(CapID == 0x10){
			//
			// clear some status
			//
			AsiaPcieModify8(PCI_BASE, AsiaPciAddress(Busx, Devx, Funcx, pointer+0x0A), BIT2|BIT1|BIT0, BIT2|BIT1|BIT0);
							
			p1 = 0x100;
			while(1){
				CapID2 = AsiaPcieRead16(PCI_BASE, AsiaPciAddress(Busx, Devx, Funcx, p1));
				//
				// if not exist extend capability
				//
				if(CapID2 == 0x0000){
					break;  //exit
				}
				//
				// Found extend capabilty 
				//
				else{
					//
					// Found AER capability
					//
					if(CapID2 == 0x0001){
						DEBUG((EFI_D_ERROR, "[CJW_AER] [%d|%d|%d]Found AER at offset [0x%x]\n",Busx, Devx, Funcx,p1));
						AsiaPcieWrite32(PCI_BASE, AsiaPciAddress(Busx, Devx, Funcx, p1+0x04), 0xFFFFFFFF);
						AsiaPcieWrite32(PCI_BASE, AsiaPciAddress(Busx, Devx, Funcx, p1+0x10), 0xFFFFFFFF);
						break;
					}
					//
					// this not AER capability
					//
					else{
						np1 = AsiaPcieRead16(PCI_BASE, AsiaPciAddress(Busx, Devx, Funcx, p1+2));
						p1 = (np1>>4);
					}	
				}
				//
				// AER capability not exit
				//
				if(p1 == 0x000){
					DEBUG((EFI_D_ERROR, "[CJW_AER] [%d|%d|%d] Not Found AER \n",Busx, Devx, Funcx));
					break;
				}
								
			}
			break;
		}
		//
		// Not found , search next pointer
		//
		else{
			nextp = AsiaPcieRead8(PCI_BASE, AsiaPciAddress(Busx, Devx, Funcx, pointer+1));
			pointer = nextp;
		}

		//
		// If no PCI Express Capability, it's not PCIE device
		//
		if(pointer == 0x00){
			DEBUG((EFI_D_ERROR, "[CJW_AER] [%d|%d|%d]Not Pcie device/bridge\n",Busx, Devx, Funcx));
			break;
		}
	}

__GoOut:
	;
				
				
}	








/**
	This function was used to dump Cfg Space of IOE
	before run ProcessPcieBiosOption() routine
**/

/**
  Function description.
  
  @param  PeiServices	EFI_PEI_SERVICES pointer.
  @param SbCfg Point to ASIA_SB_CONFIGURATION struct.

  @return EFI_STATUS.

**/

VOID
DebugIoe_1(VOID)
{

	UINT32 xx;
	UINT32 val;

	if(!IoeExist()){
		DEBUG((EFI_D_ERROR, "[CJW_IOE] SKIP CND003 Init [DebugIoe_1()]\n"));
		return;
	}
	
	DEBUG((EFI_D_ERROR, "\n[CJW_S3_TEST]\n "));

	DEBUG((EFI_D_ERROR, "\nNormal boot->[0:2:0]: "));
	for(xx=0; xx<0xFF; xx+=4){
		if((xx&0xF) == 0){
			DEBUG((EFI_D_ERROR, "\nRx%04x: ",xx));
		}
		//val = MmioRead32(PCI_DEV_MMBASE(0, 7, 0)+xx);
		val = AsiaPcieRead32(0xE0000000, AsiaPciAddress(0, 2, 0,(UINT16)xx));
		DEBUG((EFI_D_ERROR, "%08x ", val));

	}

	DEBUG((EFI_D_ERROR, "\nNormal boot->[1:0:0]: "));
	for(xx=0; xx<0xFF; xx+=4){
		if((xx&0xF) == 0){
			DEBUG((EFI_D_ERROR, "\nRx%04x: ",xx));
		}
		//val = MmioRead32(PCI_DEV_MMBASE(6, 0, 0)+xx);
		val = AsiaPcieRead32(0xE0000000, AsiaPciAddress(1, 0, 0,(UINT16)xx));
		DEBUG((EFI_D_ERROR, "%08x ", val));

	}

	DEBUG((EFI_D_ERROR, "\nNormal boot->[2:1:0]: "));
	for(xx=0; xx<0xFF; xx+=4){
		if((xx&0xF) == 0){
			DEBUG((EFI_D_ERROR, "\nRx%04x: ",xx));
		}
		//val = MmioRead32(PCI_DEV_MMBASE(7, 1, 0)+xx);
		val = AsiaPcieRead32(0xE0000000, AsiaPciAddress(2, 1, 0,(UINT16)xx));
		DEBUG((EFI_D_ERROR, "%08x ", val));

	}


	DEBUG((EFI_D_ERROR, "\nNormal boot->[2:2:0]: "));
	for(xx=0; xx<0xFF; xx+=4){
		if((xx&0xF) == 0){
			DEBUG((EFI_D_ERROR, "\nRx%04x: ",xx));
		}
		//val = MmioRead32(PCI_DEV_MMBASE(7, 2, 0)+xx);
		val = AsiaPcieRead32(0xE0000000, AsiaPciAddress(2, 2, 0,(UINT16)xx));
		DEBUG((EFI_D_ERROR, "%08x ", val));

	}

	DEBUG((EFI_D_ERROR, "\nNormal boot->[2:6:0]: "));
	for(xx=0; xx<0xFF; xx+=4){
		if((xx&0xF) == 0){
			DEBUG((EFI_D_ERROR, "\nRx%04x: ",xx));
		}
		//val = MmioRead32(PCI_DEV_MMBASE(7, 2, 0)+xx);
		val = AsiaPcieRead32(0xE0000000, AsiaPciAddress(2, 6, 0,(UINT16)xx));
		DEBUG((EFI_D_ERROR, "%08x ", val));

	}

}




/*
Param: 
	DevBusNum: A bus number which may belong to IOE upsteam port				
*/

/**
  Function description.
  
  @param  PeiServices	EFI_PEI_SERVICES pointer.
  @param SbCfg Point to ASIA_SB_CONFIGURATION struct.

  @return EFI_STATUS.

**/

EFI_STATUS
IoeSaveBusNumber2BootScript(
	ASIA_NB_CONFIGURATION *NbCfg,
	UINT8 DevBusNum)
{

    //UINT8   DevBusNum;
	//UINT8  DevBusNum1A;
    //UINT16  VendorId, ClassCode;
	UINT8 NextBusNum;		//[CJW_IOE]
	UINT32 VidDid;
	UINT8 B18,B19,B1A;
	UINT32 IoeBar;


	if(!IoeExist()){
		DEBUG((EFI_D_ERROR, "\n[CJW_IOE] SKIP CND003 Init (4)\n"));
		return EFI_SUCCESS;
	}

	//Get the VID
	VidDid = AsiaPciRead32(AsiaPciAddress(DevBusNum, UPPORT_DEV, UPPORT_DEV, 0));

	//If the device under this bus was IOE switch Upstream port
	if((VidDid == IOEBUSXUSP_VIDDID)||(VidDid== IOEBUSXUSP_VIDDID_ZX)){
	//if(VidDid == 0x861310B5){    //for test

		/*
			[CJW_IOE]
			Note: we need to guarantee MB RP's Rx18 19 1A Base/Limit MemoryEnable BusMasterEn have been restored
		*/		
	
		DEBUG((EFI_D_ERROR, "\n[CJE_IOE_BS] IoeSaveBusNumber2BootScript(): Backup BusX BusXp1D8F0 BusXp2 -->For S3 resume FW AutoFill\n"));
		//
		//PEEP
		//backup BusX D0F0 Rx18/19/1A
		//
		B18 = AsiaPciRead8(AsiaPciAddress(DevBusNum,  UPPORT_DEV, UPPORT_DEV, 0x18));
		B19 = AsiaPciRead8(AsiaPciAddress(DevBusNum,  UPPORT_DEV, UPPORT_DEV, 0x19));
		B1A = AsiaPciRead8(AsiaPciAddress(DevBusNum,  UPPORT_DEV, UPPORT_DEV, 0x1A));
		DEBUG((EFI_D_ERROR, "             Backup  DevBusNum=%x: 18/19/1A = [%x|%x|%x]\n",DevBusNum,B18,B19,B1A));
	    SCRIPT_PCI_CFG_WRITE(
	        EFI_ACPI_S3_RESUME_SCRIPT_TABLE,
	        EfiBootScriptWidthUint8,
	        AsiaPciAddress(DevBusNum, UPPORT_DEV, UPPORT_DEV, 0x18),
	        0x01,
	        &B18
	    );
	    SCRIPT_PCI_CFG_WRITE(
	        EFI_ACPI_S3_RESUME_SCRIPT_TABLE,
	        EfiBootScriptWidthUint8,
	        AsiaPciAddress(DevBusNum, UPPORT_DEV, UPPORT_DEV, 0x19),
	        0x01,
	        &B19
	    );
	    SCRIPT_PCI_CFG_WRITE(
	        EFI_ACPI_S3_RESUME_SCRIPT_TABLE,
	        EfiBootScriptWidthUint8,
	        AsiaPciAddress(DevBusNum, UPPORT_DEV, UPPORT_DEV, 0x1A),
	        0x01,
	        &B1A
	    );

		//
		//Backup PEEP MMIO base address
		//
		IoeBar = AsiaPciRead32(AsiaPciAddress(DevBusNum, 0, 0, 0x10)); 
		DEBUG((EFI_D_ERROR, "             IoeBar = 0x%08x\n",IoeBar));
	    SCRIPT_PCI_CFG_WRITE(
	        EFI_ACPI_S3_RESUME_SCRIPT_TABLE,
	        EfiBootScriptWidthUint32,
	        AsiaPciAddress(DevBusNum, UPPORT_DEV, UPPORT_DEV, 0x10),
	        0x1,
	        &IoeBar
	    );		

		//
		//Backup PEEP Mem Base/Limit
		//
		IoeBar = AsiaPciRead32(AsiaPciAddress(DevBusNum, 0, 0, 0x20)); 
		DEBUG((EFI_D_ERROR, "             BaseLimit = 0x%08x\n",IoeBar));
	    SCRIPT_PCI_CFG_WRITE(
	        EFI_ACPI_S3_RESUME_SCRIPT_TABLE,
	        EfiBootScriptWidthUint32,
	        AsiaPciAddress(DevBusNum, UPPORT_DEV, UPPORT_DEV, 0x20),
	        0x1,
	        &IoeBar
	    );		

		//
		//Get the bus number of PE DN ports
		//
		NextBusNum = AsiaPciRead8(AsiaPciAddress(DevBusNum, UPPORT_DEV, UPPORT_DEV, 0x19)); 
		DevBusNum = NextBusNum; 


		//
		//PESB	
		//backup BusX+1 D8F0 Rx18/19/1A
		//
		B18 = AsiaPciRead8(AsiaPciAddress(DevBusNum, PESB, DNPORT_FUN, 0x18));
		B19 = AsiaPciRead8(AsiaPciAddress(DevBusNum, PESB, DNPORT_FUN, 0x19));
		B1A = AsiaPciRead8(AsiaPciAddress(DevBusNum, PESB, DNPORT_FUN, 0x1A));
		DEBUG((EFI_D_ERROR, "             Backup  DevBusNum=%x: 18/19/1A = [%x|%x|%x]\n",DevBusNum,B18,B19,B1A));
	    SCRIPT_PCI_CFG_WRITE(
	        EFI_ACPI_S3_RESUME_SCRIPT_TABLE,
	        EfiBootScriptWidthUint8,
	        AsiaPciAddress(DevBusNum, PESB, DNPORT_FUN, 0x18),
	        0x01,
	        &B18
	    );
	    SCRIPT_PCI_CFG_WRITE(
	        EFI_ACPI_S3_RESUME_SCRIPT_TABLE,
	        EfiBootScriptWidthUint8,
	        AsiaPciAddress(DevBusNum, PESB, DNPORT_FUN, 0x19),
	        0x01,
	        &B19
	    );
	    SCRIPT_PCI_CFG_WRITE(
	        EFI_ACPI_S3_RESUME_SCRIPT_TABLE,
	        EfiBootScriptWidthUint8,
	        AsiaPciAddress(DevBusNum, PESB, DNPORT_FUN, 0x1A),
	        0x01,
	        &B1A
	    );

		
		//
		// PCIEIF
		//
		// Get the Bus Number of PCIEIF 
		NextBusNum = AsiaPciRead8(AsiaPciAddress(DevBusNum, PESB, DNPORT_FUN, 0x19)); 
		DevBusNum = NextBusNum; 
		//backup BusX+2 D0F0 Rx18/19/1A
		B18 = AsiaPciRead8(AsiaPciAddress(DevBusNum, PCIEIF_DEV, PCIEIF_FUN, 0x18));
		B19 = AsiaPciRead8(AsiaPciAddress(DevBusNum, PCIEIF_DEV, PCIEIF_FUN, 0x19));
		B1A = AsiaPciRead8(AsiaPciAddress(DevBusNum, PCIEIF_DEV, PCIEIF_FUN, 0x1A));
		DEBUG((EFI_D_ERROR, "             Backup  DevBusNum=%x: 18/19/1A = [%x|%x|%x]\n",DevBusNum,B18,B19,B1A));
		
	    SCRIPT_PCI_CFG_WRITE(
	        EFI_ACPI_S3_RESUME_SCRIPT_TABLE,
	        EfiBootScriptWidthUint8,
	        AsiaPciAddress(DevBusNum, PCIEIF_DEV, PCIEIF_FUN, 0x18),
	        0x01,
	        &B18
	    );
	    SCRIPT_PCI_CFG_WRITE(
	        EFI_ACPI_S3_RESUME_SCRIPT_TABLE,
	        EfiBootScriptWidthUint8,
	        AsiaPciAddress(DevBusNum, PCIEIF_DEV, PCIEIF_FUN, 0x19),
	        0x01,
	        &B19
	    );
	    SCRIPT_PCI_CFG_WRITE(
	        EFI_ACPI_S3_RESUME_SCRIPT_TABLE,
	        EfiBootScriptWidthUint8,
	        AsiaPciAddress(DevBusNum, PCIEIF_DEV, PCIEIF_FUN, 0x1A),
	        0x01,
	        &B1A
	    );


		//
		// CJW_20170407: 
		//		Record XHCI's bus number to Scratch Reg7 D0F6 Rx58 
		//
		AsiaPciWriteSave8(AsiaPciAddress(CHX002_HB_BUS, CHX002_HB_DEV, CHX002_SCRCH_FUN, D0F6_BIOS_SCRATCH_REG_7), B19);
#if MULTI_IOE_SUPPORT
		// TODO: add code support for Multi-IOE	
#endif
		
		return EFI_SUCCESS;
	}else{
		
		return EFI_NOT_FOUND;
	}

}

/**
  Function description.
  
  @param  PeiServices	EFI_PEI_SERVICES pointer.
  @param SbCfg Point to ASIA_SB_CONFIGURATION struct.

  @return EFI_STATUS.

**/

EFI_STATUS
IoePcieGen3InternalDxe(ASIA_NB_CONFIGURATION *NbCfg)
{
	
	UINT64 PcieBase = NbCfg->PcieBar;
	DEBUG((EFI_D_ERROR, "             %a(): PcieBase = 0x%08x\n",__FUNCTION__, PcieBase));
	
	if((NbCfg->Cnd003PcieEq == IOE_DO_EQ)&&(NbCfg->Cnd003EpCap == 3)){
		AsiaPcieModifySave8(PcieBase,CND003_PEEP|((UINT64)CND003_BUSX_D0F0_LKTGLS_VIA_AND_NEED_EQTS << 32), CND003_BUSX_D0F0_LKTGLS_VIA, CND003_BUSX_D0F0_LKTGLS_VIA);
	}

	//Read current LKTGLS_VIA
	DEBUG((EFI_D_ERROR, "             LKTGLS_VIA = 0x%d\n", 
							(0x6 & AsiaPcieRead8(PcieBase, 
							AsiaPciAddress(BUSX , UPPORT_DEV, UPPORT_FUN, CND003_BUSX_D0F0_LKTGLS_VIA_AND_NEED_EQTS)))>>1));
	IoeDumpCfgDxe(PcieBase, BUSX, UPPORT_DEV, UPPORT_FUN, 0x20);
	
	return EFI_SUCCESS;
}


/**
  Function description.
  
  @param  PeiServices	EFI_PEI_SERVICES pointer.
  @param SbCfg Point to ASIA_SB_CONFIGURATION struct.

  @return EFI_STATUS.

**/


VOID IoeProgramDpSlotPowerLimit(
    ASIA_NB_CONFIGURATION *NbCfg,
    UINT64	Address
)
{

	//Set "Slot Power Limut Value" and "Slot Power Limit Scale" to 75W meet the PCIE GEN3 SPEC
	AsiaPcieModifySave16(NbCfg->PcieBar, Address|((UINT64)(CND003_BUSXP1_D1D7F0_SLOT_CAPS_1) << 32), CND003_BUSXP1_D1D7F0_RSPLV, 0x2580);
}

/**
  Function description.
  
  @param  PeiServices	EFI_PEI_SERVICES pointer.
  @param SbCfg Point to ASIA_SB_CONFIGURATION struct.

  @return EFI_STATUS.

**/

VOID IoeSetDpSlotPowerLimit(
    ASIA_NB_CONFIGURATION *NbCfg
)
{
    AsiaPciModifySave8(CND003_XBCTL|CND003_MMIO_D0F0_BACKDOOR_REG_CTL_0, CND003_MMIO_D0F0_RPEROWEN, CND003_MMIO_D0F0_RPEROWEN);
    if(NbCfg->IoePEA0Ctl) {IoeProgramDpSlotPowerLimit(NbCfg, CND003_PEA0);}
    if(NbCfg->IoePEA1Ctl) {IoeProgramDpSlotPowerLimit(NbCfg, CND003_PEA1);}
    if(NbCfg->IoePEA2Ctl) {IoeProgramDpSlotPowerLimit(NbCfg, CND003_PEA2);}
    if(NbCfg->IoePEA3Ctl) {IoeProgramDpSlotPowerLimit(NbCfg, CND003_PEA3);}
    if(NbCfg->IoePEA4Ctl) {IoeProgramDpSlotPowerLimit(NbCfg, CND003_PEA4);}
    if(NbCfg->IoePEB0Ctl) {IoeProgramDpSlotPowerLimit(NbCfg, CND003_PEB0);}
    if(NbCfg->IoePEB1Ctl) {IoeProgramDpSlotPowerLimit(NbCfg, CND003_PEB1);}
    AsiaPciModifySave8(CND003_XBCTL|CND003_MMIO_D0F0_BACKDOOR_REG_CTL_0, CND003_MMIO_D0F0_RPEROWEN, 0);
}

//JRZ: lock the SID register of all USB2.0 controller in a IOE chip.
/**
  Function description.
  
  @param  PeiServices	EFI_PEI_SERVICES pointer.
  @param SbCfg Point to ASIA_SB_CONFIGURATION struct.

  @return EFI_STATUS.

**/

VOID IoeIsbSidLock()
{
	UINT8 index = 0;
	UINT8 i = 0;
	UINT32 VIDDID = 0;
	UINT8 RootPortSecondaryBus = 0;
	UINT8 ISBDeviceBusNum = 0;
	Path path[] = {{0,0},{8,0},{0,0}};

	for(index = 0; index < (sizeof(MbRpTblList))/(sizeof(RpList)); index++)
	{
		VIDDID = AsiaPciRead32(AsiaPciAddress(MbRpTblList[index].Bus, MbRpTblList[index].Dev, MbRpTblList[index].Func, 0x0));
		if(VIDDID == 0xFFFFFFFF)//this root port does not exist
		{
			DEBUG((EFI_D_ERROR, "[JRZ_IOE] Root port[0x%02X 0x%02X 0x%02X] does not exist!\n", MbRpTblList[index].Bus, MbRpTblList[index].Dev, MbRpTblList[index].Func));
		}
		else//this root port exist
		{
			RootPortSecondaryBus = AsiaPciRead8(AsiaPciAddress(MbRpTblList[index].Bus, MbRpTblList[index].Dev, MbRpTblList[index].Func, 0x19));
			VIDDID = AsiaPciRead32(AsiaPciAddress(RootPortSecondaryBus, UPPORT_DEV, UPPORT_FUN, 0x0));
			if(VIDDID == IOEBUSXUSP_VIDDID || VIDDID == IOEBUSXUSP_VIDDID_ZX)
			{
				DEBUG((EFI_D_ERROR, "[JRZ_IOE] Root port[0x%02X 0x%02X 0x%02X]: the function under this root port is a IOE chip!\n", MbRpTblList[index].Bus, MbRpTblList[index].Dev, MbRpTblList[index].Func));
				DEBUG((EFI_D_ERROR, "[JRZ_IOE] PEEP bus number is 0x%02X.\n", RootPortSecondaryBus));

				//get the ISB devices' bus number.
				ISBDeviceBusNum = RootPortSecondaryBus;
				for(i = 0; i < (sizeof(path))/(sizeof(Path)); i++)
					ISBDeviceBusNum = AsiaPciRead8(AsiaPciAddress(ISBDeviceBusNum, path[i].Dev, path[i].Func, 0x19));
				DEBUG((EFI_D_ERROR, "[JRZ_IOE] ISB devices' bus number is 0x%02X.\n", ISBDeviceBusNum));

				//lock the SID register of all USB2.0 controller in a IOE chip.
				AsiaPciWriteSave16(AsiaPciAddress(ISBDeviceBusNum, CND003_USBC0_DEV, 0, IOEUHCI_CCA_BUS_SRC_ID_D16F0), ((UINT16)ISBDeviceBusNum << 8)|(0x70));
				AsiaPciWriteSave16(AsiaPciAddress(ISBDeviceBusNum, CND003_USBC0_DEV, 1, IOEUHCI_CCA_BUS_SRC_ID_D16F0), ((UINT16)ISBDeviceBusNum << 8)|(0x71));
				AsiaPciWriteSave16(AsiaPciAddress(ISBDeviceBusNum, CND003_USBC0_DEV, 2, IOEUHCI_CCA_BUS_SRC_ID_D16F0), ((UINT16)ISBDeviceBusNum << 8)|(0x72));
				AsiaPciWriteSave16(AsiaPciAddress(ISBDeviceBusNum, CND003_USBC0_DEV, 7, IOEEHCI_CCA_BUS_SRC_ID      ), ((UINT16)ISBDeviceBusNum << 8)|(0x77));
				AsiaPciWriteSave16(AsiaPciAddress(ISBDeviceBusNum, CND003_USBC1_DEV, 0, IOEUHCI_CCA_BUS_SRC_ID_D16F0), ((UINT16)ISBDeviceBusNum << 8)|(0x80));
				AsiaPciWriteSave16(AsiaPciAddress(ISBDeviceBusNum, CND003_USBC1_DEV, 1, IOEUHCI_CCA_BUS_SRC_ID_D16F0), ((UINT16)ISBDeviceBusNum << 8)|(0x81));
				AsiaPciWriteSave16(AsiaPciAddress(ISBDeviceBusNum, CND003_USBC1_DEV, 2, IOEUHCI_CCA_BUS_SRC_ID_D16F0), ((UINT16)ISBDeviceBusNum << 8)|(0x82));
				AsiaPciWriteSave16(AsiaPciAddress(ISBDeviceBusNum, CND003_USBC1_DEV, 7, IOEEHCI_CCA_BUS_SRC_ID      ), ((UINT16)ISBDeviceBusNum << 8)|(0x87));

				//No SID lock operation due to the hardware design problem.
			}
			else
			{
				DEBUG((EFI_D_ERROR, "[JRZ_IOE] Root port[0x%02X 0x%02X 0x%02X]: No IOE chip is founded under this root port.\n", MbRpTblList[index].Bus, MbRpTblList[index].Dev, MbRpTblList[index].Func));
			}	
			
		}
	}
}

EFI_STATUS
IoePrePciInit(ASIA_NB_CONFIGURATION *NbCfg)
{
	EFI_STATUS Statusx = EFI_SUCCESS;

	if(!IoeExist()){
		DEBUG((EFI_D_ERROR, "[CJW_IOE] SKIP CND003 Init (5)\n"));
		return Statusx;
	}
	
	Statusx = IoeDxeTempAssignment();
	if(Statusx != EFI_SUCCESS){
		return Statusx;
	}


	//SwDbg-1-0-SwDbg-2-DxeMmioDump
	if((NbCfg->Cnd003SwDbg1 == 0)&&((NbCfg->Cnd003SwDbg2) & BIT1)){
		DEBUG((EFI_D_ERROR, "SwDbg-1-0-SwDbg-2-DxeMmioDump\n"));
		{
			UINT32 PeBar,GnicBara,GnicBarb;
			PeBar = AsiaPciRead32(AsiaPciAddress(BUSX, UPPORT_DEV, UPPORT_FUN, 0x10));
			GnicBara = AsiaPciRead32(AsiaPciAddress(BUSXP3, CND003_GNIC_DEV, 0, 0x14));
			GnicBarb = AsiaPciRead32(AsiaPciAddress(BUSXP3, CND003_GNIC_DEV, 0, 0x1C));
			IoeDumpMemDxe(PeBar, 0x2000);
			IoeDumpMemDxe(GnicBara, 0x1000);
			IoeDumpMemDxe(GnicBarb, 0x2000);
		}
	}	



	// SPE value setting
	IoeFillSpeValue(NbCfg);

	//Set slot power limit to 75W to meet Gen3 Spec requirment - PCI-SIG
	IoeSetDpSlotPowerLimit(NbCfg);

	// set more registers for E mode
	IoePcieArrgessivePM(NbCfg);

	// L1 Exit Latency Calculation
	IoeL1ExitLatencyCalculation(NbCfg,IoeL1ExitLatencyTblx,sizeof(IoeL1ExitLatencyTblx)/sizeof(IOE_L1SET_TBL));

	//PCIE Gen3 EQ setting
	IoePcieGen3InternalDxe(NbCfg);

	IoeDxeClearTempAssignment();
	
	return EFI_SUCCESS;
}



#if 0
VOID
DebugDxeDumpCfgSpaceDxe(VOID)
{
 	UINT16 tx;
	UINT32 Temp32x;
	
	DEBUG(( EFI_D_INFO, "\n------------------------------------Bus1 D0F0 PEEP:\n"));
	for(tx=0;tx <= 0x1FF; tx+=4){
		if((tx & 0x0F) == 0x00){
			DEBUG(( EFI_D_INFO, "\nRx%03x:",tx));	
		}
		Temp32x = AsiaPcieRead32((UINT64)PCI_BASE, AsiaPciAddress(1, 0, 0, tx));

		DEBUG(( EFI_D_INFO, "%08X  ",Temp32x));		
	}


	DEBUG(( EFI_D_INFO, "\n------------------------------------Bus2 D8F0 PESB:\n"));
	for(tx=0;tx <= 0x1FF; tx+=4){
		if((tx & 0x0F) == 0x00){
			DEBUG(( EFI_D_INFO, "\nRx%03x:",tx));	
		}
		Temp32x = AsiaPcieRead32((UINT64)PCI_BASE, AsiaPciAddress(2, 8, 0, tx));

		DEBUG(( EFI_D_INFO, "%08X  ",Temp32x));		
	}

	DEBUG(( EFI_D_INFO, "\n------------------------------------Bus3 D0F0 PCIEIF:\n"));
	for(tx=0;tx <= 0x1FF; tx+=4){
		if((tx & 0x0F) == 0x00){
			DEBUG(( EFI_D_INFO, "\nRx%03x:",tx));	
		}
		Temp32x = AsiaPcieRead32((UINT64)PCI_BASE, AsiaPciAddress(3, 0, 0, tx));

		DEBUG(( EFI_D_INFO, "%08X  ",Temp32x));		
	}


	DEBUG(( EFI_D_INFO, "\n------------------------------------Bus4 D0F0 EPTRFC:\n"));
	for(tx=0;tx <= 0x1FF; tx+=4){
		if((tx & 0x0F) == 0x00){
			DEBUG(( EFI_D_INFO, "\nRx%03x:",tx));	
		}
		Temp32x = AsiaPcieRead32((UINT64)PCI_BASE, AsiaPciAddress(4, 0, 0, tx));

		DEBUG(( EFI_D_INFO, "%08X  ",Temp32x));		
	}


	DEBUG(( EFI_D_INFO, "\n------------------------------------Bus4 D13F0 GNIC:\n"));
	for(tx=0;tx <= 0x1FF; tx+=4){
		if((tx & 0x0F) == 0x00){
			DEBUG(( EFI_D_INFO, "\nRx%03x:",tx));	
		}
		Temp32x = AsiaPcieRead32((UINT64)PCI_BASE, AsiaPciAddress(4, 13, 0, tx));

		DEBUG(( EFI_D_INFO, "%08X  ",Temp32x));		
	}

	DEBUG(( EFI_D_INFO, "\n------------------------------------Bus4 D15F0 SATA:\n"));
	for(tx=0;tx <= 0x1FF; tx+=4){
		if((tx & 0x0F) == 0x00){
			DEBUG(( EFI_D_INFO, "\nRx%03x:",tx));	
		}
		Temp32x = AsiaPcieRead32((UINT64)PCI_BASE, AsiaPciAddress(4, 15, 0, tx));

		DEBUG(( EFI_D_INFO, "%08X  ",Temp32x));		
	}

	DEBUG(( EFI_D_INFO, "\n------------------------------------Bus4 D16F0 UHCI:\n"));
	for(tx=0;tx <= 0x1FF; tx+=4){
		if((tx & 0x0F) == 0x00){
			DEBUG(( EFI_D_INFO, "\nRx%03x:",tx));	
		}
		Temp32x = AsiaPcieRead32((UINT64)PCI_BASE, AsiaPciAddress(4, 16, 0, tx));

		DEBUG(( EFI_D_INFO, "%08X  ",Temp32x));		
	}

	DEBUG(( EFI_D_INFO, "\n------------------------------------Bus4 D16F7 EHCI:\n"));
	for(tx=0;tx <= 0x1FF; tx+=4){
		if((tx & 0x0F) == 0x00){
			DEBUG(( EFI_D_INFO, "\nRx%03x:",tx));	
		}
		Temp32x = AsiaPcieRead32((UINT64)PCI_BASE, AsiaPciAddress(4, 16, 7, tx));

		DEBUG(( EFI_D_INFO, "%08X  ",Temp32x));		
	}
	
	DEBUG(( EFI_D_INFO, "\n------------------------------------Bus4 D18F0 XHCI:\n"));
	for(tx=0;tx <= 0x1FF; tx+=4){
		if((tx & 0x0F) == 0x00){
			DEBUG(( EFI_D_INFO, "\nRx%03x:",tx));	
		}
		Temp32x = AsiaPcieRead32((UINT64)PCI_BASE, AsiaPciAddress(4, 18, 0, tx));

		DEBUG(( EFI_D_INFO, "%08X  ",Temp32x));		
	}
		

}
#endif

/**************************************************************************
// Library support for Multi-IOE / BIOS mode  
**************************************************************************/
#if MULTI_IOE_SUPPORT

ORDER_D DxeFlagBitRelationship[]= IOE_ORDER_TABLE;   




STATIC UINT8 
IoeDxeGetPortFlagBit(
	UINT8 Bus, 
	UINT8 Dev, 
	UINT8 Fun)
{
	UINT8 ix;
	for(ix = 0; ix < (sizeof(DxeFlagBitRelationship)/sizeof(ORDER_D)); ix++){
		if((DxeFlagBitRelationship[ix].BusNum == Bus)
			&&(DxeFlagBitRelationship[ix].DevNum == Dev)
			&&(DxeFlagBitRelationship[ix].FunNum == Fun)){
			return ix;  //return the index in this table
		}
	}
	
	DEBUG((EFI_D_ERROR, "[CJW_IOE] ERROR!!! - Not found the corresponing flag bit in scratch register! \n"  ));
	return 0xFF; //not found
}

/**
 call this routine to check whether this port is 
 usable, when a port was masked in scratch register, 
 this routine will return FALSE, otherwise, return TURE.

 we offen call this routine to judge whether we can do 
 initialization sequence for a specific port(if it exist in MbRpTblList)
**/
STATIC BOOLEAN
IoeDxeIsUsablePort(
	UINT8 Bus, UINT8 Dev, UINT8 Fun)
{
	UINT8 Var1,Var0;
	UINT16 VarMask16 = 0;
	UINT8 temp;

	Var0 = AsiaPciRead8(AsiaPciAddress(SCRATCH_BUS,SCRATCH_DEV,SCRATCH_FUN,VAR_BYTE0_REG));
	Var1 = AsiaPciRead8(AsiaPciAddress(SCRATCH_BUS,SCRATCH_DEV,SCRATCH_FUN,VAR_BYTE1_REG));	
	VarMask16 = Var1;
	VarMask16 = (VarMask16<<8)|(Var0&0xFF);
	
	temp = IoeDxeGetPortFlagBit(Bus,Dev,Fun);
	if(VarMask16 & (1<<temp)){
		return FALSE;
	}else{
		return TRUE;
	}
	
}

STATIC VOID
IoeDxeMaskSearchPort(
	UINT8 Bus, 
	UINT8 Dev, 
	UINT8 Fun)
{
	UINT8 Var1,Var0;
	UINT8 temp;

	temp = IoeDxeGetPortFlagBit(Bus,Dev,Fun);

	if((temp<8)&&(temp>=0)){
		Var0 = AsiaPciRead8(AsiaPciAddress(SCRATCH_BUS,SCRATCH_DEV,SCRATCH_FUN,VAR_BYTE0_REG));
		Var0 = Var0|(1<<temp);
		AsiaPciWriteSave8(AsiaPciAddress(SCRATCH_BUS,SCRATCH_DEV,SCRATCH_FUN,VAR_BYTE0_REG),Var0);
	}
	if((temp>=8)&&(temp<16)){  
		Var1 = AsiaPciRead8(AsiaPciAddress(SCRATCH_BUS,SCRATCH_DEV,SCRATCH_FUN,VAR_BYTE1_REG));
		Var1 = Var1|(1<<(temp-8));
		AsiaPciWriteSave8(AsiaPciAddress(SCRATCH_BUS,SCRATCH_DEV,SCRATCH_FUN,VAR_BYTE0_REG),Var1);			
	}	

}

/**
 for a specific port, mask it in MbRpTblList. after a 
 port was masked, all initialization code will skip this 
 port(not initialize this port).
 @Param:
 	Bus/Dev/Fun: the port to be Masked(if exist in MbRpTblList)
**/
STATIC VOID
IoeDxeUnmaskSearchPort(
	UINT8 Bus, 
	UINT8 Dev, 
	UINT8 Fun)
{
	UINT8 Var1,Var0;
	UINT8 temp;

	temp = IoeDxeGetPortFlagBit(Bus,Dev,Fun);

	if((temp<8)&&(temp>=0)){
		Var0 = AsiaPciRead8(AsiaPciAddress(SCRATCH_BUS,SCRATCH_DEV,SCRATCH_FUN,VAR_BYTE0_REG));
		Var0 = Var0&(~(1<<temp));
		AsiaPciWriteSave8(AsiaPciAddress(SCRATCH_BUS,SCRATCH_DEV,SCRATCH_FUN,VAR_BYTE0_REG),Var0);
	}
	if((temp>=8)&&(temp<16)){  
		Var1 = AsiaPciRead8(AsiaPciAddress(SCRATCH_BUS,SCRATCH_DEV,SCRATCH_FUN,VAR_BYTE1_REG));
		Var1 = Var1&(~(1<<(temp-8)));
		AsiaPciWriteSave8(AsiaPciAddress(SCRATCH_BUS,SCRATCH_DEV,SCRATCH_FUN,VAR_BYTE0_REG),Var1);			
	}

}

/**
	call this routine to Unmask all port in stratch register,
	when a port is unmasked, All the next initialization for 
	this port will take effect.
**/
VOID 
IoeDxeUnmaskAllPort(VOID)
{
	AsiaPciWriteSave8(AsiaPciAddress(SCRATCH_BUS,SCRATCH_DEV,SCRATCH_FUN,VAR_BYTE0_REG),0);
	AsiaPciWriteSave8(AsiaPciAddress(SCRATCH_BUS,SCRATCH_DEV,SCRATCH_FUN,VAR_BYTE1_REG),0);
}

/**
 After a port initialized, call this routine to mask it in 
 scratch register, when the initialized sequence run again, 
 those mask flag will protect those initialized port to be 
 initialized again
**/
EFI_STATUS
IoeDxeMaskInitializedPort(VOID)
{
	EFI_STATUS Status = EFI_SUCCESS;
	UINT8 ts,ts1;

	for(ts = 0; ts < (sizeof(MbRpTblList)/sizeof(RpList)); ts++){
		Status = IoeFindAndAssign(MbRpTblList, sizeof(MbRpTblList)/sizeof(RpList), &ts);
		if(Status == EFI_SUCCESS){
			if(!IoeDxeIsUsablePort(MbRpTblList[ts].Bus, MbRpTblList[ts].Dev, MbRpTblList[ts].Func)){
				Status = EFI_NOT_FOUND;
				IoeClearAssignment(MbRpTblList, sizeof(MbRpTblList)/sizeof(RpList), &ts1);
				if(ts != ts1){
					DEBUG((EFI_D_ERROR,"[CJW_IOE] ERROR!!! - IoeDxeMaskInitializedPort() Error!\n"));
				}
				continue;
			}
			//if this port connected to IOE && Not be masked, 
			//then we mask it so that to avoid initialized again in next loop
			IoeDxeMaskSearchPort(MbRpTblList[ts].Bus, MbRpTblList[ts].Dev, MbRpTblList[ts].Func);

			//CJW_20181114 IOE CodeBusRepair_Item3_(1/1)
			// after mask this RP, we need to clear the IOE bus resource  under this RP
			IoeClearAssignment(MbRpTblList, sizeof(MbRpTblList)/sizeof(RpList), &ts1);
			if(ts != ts1){
				DEBUG((EFI_D_ERROR,"[CJW_IOE] ERROR!!! - IoeDxeMaskInitializedPort() Error2!\n"));
			}		
			
			break;
		}
	}
	
	return Status;
}
#endif


