//**********************************************************************
//**********************************************************************
//**                                                                  **
//**     Copyright (c) 2018 Shanghai Zhaoxin Semiconductor Co., Ltd.  **
//**                                                                  **
//**********************************************************************
//**********************************************************************
#include "SvadDvad.h"

extern VOID FlushCfgWrite(
	IN EFI_PEI_SERVICES **PeiServices,
	IN DRAM_ATTRIBUTE *DramAttr,
	IN UINT64 Address);

VOID SetSVADMMIOCFG(
    IN EFI_PEI_SERVICES **PeiServices,
	IN ASIA_NB_CONFIGURATION *NbCfg,
	IN DRAM_ATTRIBUTE *DramAttr,
	UINT16  MasterMemSize, //unit of 64M, =EndAddr16Temp[0]
	UINT16  SlaveMemSize //unit of 64M, =EndAddr16Temp[1]
	)
{
	UINT16	PciStart, RealUmaSize;      //unit of  M
	UINT32  RTOPA;                      //unit of M
	UINT16	EndAddr16=0; //unit of 64M
    UINT64  Address;
	UINT16  Temp16;
	UINT32  Temp32;

 	// Set LowTOPA = PCI_Memory_Start	and Set RTOPA
 	PciStart = DramAttr->ConfigData.PCIMemoryStart;
 	EndAddr16 = MasterMemSize + SlaveMemSize;//For single socket, Slave memory size = 0;
	
 	RealUmaSize = GetRealUmaSize(PeiServices,DramAttr,NbCfg);
 	if (RealUmaSize != 0)
		PciStart &= (~(RealUmaSize-1));

 	//LGE20160630 Make sure ReadUmaSize is Above 4GB
 	//LGE20160630 EndAddr16 - PciStart > RealUmaSize ==> EndAddr16   > PciStart + RealUmaSize
 	if ((EndAddr16 << 6) > (PciStart + RealUmaSize)){
		 //Set LOWTOPA
	 	Address = AsiaPciAddress(CHX002_HB_BUS, CHX002_HB_DEV, CHX002_HIF_FUN, D0F2_BELOW_4G_HIGHEST_MEM_LIMIT_DRAM_LIMIT_ADR_BELOW_4G + 1); 
	 	AsiaPcieWrite8(DramAttr->PcieBaseAddress, Address, (UINT8)(PciStart >> 4)); 
	 	//Set RTOPA = 4GB + EndAddr16 - PciStart
	 	Address = AsiaPciAddress(CHX002_HB_BUS, CHX002_HB_DEV, CHX002_HIF_FUN, D0F2_HIGHEST_SVAD_LIMIT_TARGET_TO_MEM_DRAM_LIMIT_ADR_OVER_4G);
	 	//ECS20161103 patch uma enable issue	-S
	 	if(NbCfg->UMAEn)
		{
			if(RealUmaSize >= 0x100) // if UMA = 256M/512M
		 	{
			 	RTOPA = 0x1000 + (EndAddr16 << 6)	- PciStart - RealUmaSize; 
		 	}
		 	else// UMA=64M/128M/8M/16M/32M
		 	{
			 	RTOPA = 0x1000 + (EndAddr16 << 6)	- PciStart; 
		 	}				 
	 	}
	 	else
	 	{
		 	RTOPA = 0x1000 + (EndAddr16 << 6)	- PciStart; 
	 	}
	 	//ECS20161103 patch uma enable issue	-E

	 	AsiaPcieModify32(DramAttr->PcieBaseAddress, Address, D0F2_RTOPA_39_20, RTOPA << 12);
	 	PEI_DEBUG((PeiServices, EFI_D_ERROR, "LOWTOPA = 0x%08x\n", PciStart));
	 	PEI_DEBUG((PeiServices, EFI_D_ERROR, "RTOPA = 0x%08x\n", RTOPA));
	}
 	//LGE20160630 EndAddr16 - PciStart <= RealUmaSize
 	else{			 
		//ECS20161128 patch uma enable issue	-S
	 	if(NbCfg->UMAEn)
	 	{
		 	if((EndAddr16 << 6)==0x100) // if limit rank size=256M 
		 	{
			 	PciStart=0;//This is posion value.
			 	RTOPA=0;//This is posion value.
			 	PEI_DEBUG((PeiServices, EFI_D_ERROR, "Can't support Memory size <=256M when UMA enable\n"));
			 	while(1);
		 	}	 
		 	else if(RealUmaSize >= 0x100) // if UMA = 256M/512M
		 	{
			 	PciStart = (EndAddr16 << 6) - RealUmaSize; 
			 	RTOPA = 0x1000; 
		 	}			 
		 	else // UMA=64M/128M/8M/16M/32M
		 	{
			 	PciStart = (EndAddr16 << 6) - 0x100; 
			 	RTOPA = 0x1000 + 0x100; 
		 	}	 
	 	}
	 	else
	 	{
	 
		 	PciStart = (EndAddr16 << 6) - RealUmaSize; 
		 	RTOPA = 0x1000 + RealUmaSize;
	 	}
	 	//ECS20161128 patch uma enable issue	-E

	 
	 	//Set LOWTOPA
	 	Address = AsiaPciAddress(CHX002_HB_BUS, CHX002_HB_DEV, CHX002_HIF_FUN, D0F2_BELOW_4G_HIGHEST_MEM_LIMIT_DRAM_LIMIT_ADR_BELOW_4G + 1);
	 	AsiaPcieWrite8(DramAttr->PcieBaseAddress, Address, (UINT8)(PciStart >> 4));

	 	Address = AsiaPciAddress(CHX002_HB_BUS, CHX002_HB_DEV, CHX002_HIF_FUN, D0F2_HIGHEST_SVAD_LIMIT_TARGET_TO_MEM_DRAM_LIMIT_ADR_OVER_4G);
	 	AsiaPcieModify32(DramAttr->PcieBaseAddress, Address, D0F2_RTOPA_39_20, RTOPA << 12);
 
	 
	 	PEI_DEBUG((PeiServices, EFI_D_ERROR, "EndAddr16 = 0x%08x\n", EndAddr16 << 6));
	 	PEI_DEBUG((PeiServices, EFI_D_ERROR, "LOWTOPA = 0x%08x\n", PciStart));
	 	PEI_DEBUG((PeiServices, EFI_D_ERROR, "RTOPA = 0x%08x\n", RTOPA));
	 
 	}	
 
 	//Set MMIOB2G & MMIO2T4G
 	//PciStart>=2GB
 	if(PciStart >= 0x800)
 	{
	 	//disable MMIOB2G
	 	Address =	AsiaPciAddress(CHX002_HB_BUS, CHX002_HB_DEV, CHX002_HIF_FUN, D0F2_MMIO_BELOW_2G_MMIOB2G);
	 	AsiaPcieModify16(DramAttr->PcieBaseAddress, Address, D0F2_RSVAD_MMIOB2GTAS_1_0, MMIOB2G_DIS);

	 	//Set MMIO2T4G
	 	Address =	AsiaPciAddress(CHX002_HB_BUS, CHX002_HB_DEV, CHX002_HIF_FUN, D0F2_MMIO_2G_TO_4G_MMIO2T4G);
	 	//MMIO2T4G  base address
	 	AsiaPcieModify16(DramAttr->PcieBaseAddress, Address, D0F2_RSVAD_MMIO2T4GBASE_30_28,(PciStart >> 8) << 4);// unit 256MB
	 	//target mapping value
	 	AsiaPcieModify16(DramAttr->PcieBaseAddress, Address, D0F2_RSVAD_MMIO2T4GTMVEQ1, 0);
	 	//target mapping value
	 	AsiaPcieModify16(DramAttr->PcieBaseAddress, Address, D0F2_RSVAD_MMIO2T4GTMVEQ0, 0);
	 	//target address select
	 	AsiaPcieModify16(DramAttr->PcieBaseAddress, Address, D0F2_RSVAD_MMIO2T4GTAS_1_0, MMIO2T4G_TARGET_SELECT_A30);

	 	PEI_DEBUG((PeiServices, EFI_D_ERROR, "MMIOB2G Disable\r\n"));
	 	PEI_DEBUG((PeiServices, EFI_D_ERROR, "MMIO2T4G BASE = 0x%08x\r\n", PciStart));
 	}
 	//PciStart<2GB
 	else
 	{	  
	 	//Set MMIOB2G
	 	Address =	AsiaPciAddress(CHX002_HB_BUS, CHX002_HB_DEV, CHX002_HIF_FUN, D0F2_MMIO_BELOW_2G_MMIOB2G);
	 	AsiaPcieModify16(DramAttr->PcieBaseAddress, Address, D0F2_RSVAD_MMIOB2GBASE_30_28, (PciStart >> 8) << 4);// unit 256MB
	 	//target mapping value
	 	AsiaPcieModify16(DramAttr->PcieBaseAddress, Address, D0F2_RSVAD_MMIOB2GTMVEQ1, 0);
	 	//target mapping value
	 	AsiaPcieModify16(DramAttr->PcieBaseAddress, Address, D0F2_RSVAD_MMIOB2GTMVEQ0, 0);
	 	//target address select
	 	AsiaPcieModify16(DramAttr->PcieBaseAddress, Address, D0F2_RSVAD_MMIOB2GTAS_1_0, MMIOB2G_TARGET_SELECT_A28);


	 	//Set MMIO2T4G
	 	Address =	AsiaPciAddress(CHX002_HB_BUS, CHX002_HB_DEV, CHX002_HIF_FUN, D0F2_MMIO_2G_TO_4G_MMIO2T4G);
	 	//MMIO2T4G  base address
	 	AsiaPcieModify16(DramAttr->PcieBaseAddress, Address, D0F2_RSVAD_MMIO2T4GBASE_30_28, 0x00);// unit 256MB
	 	//target mapping value
	 	AsiaPcieModify16(DramAttr->PcieBaseAddress, Address, D0F2_RSVAD_MMIO2T4GTMVEQ1, 0);
	 	//target mapping value
	 	AsiaPcieModify16(DramAttr->PcieBaseAddress, Address, D0F2_RSVAD_MMIO2T4GTMVEQ0, 0);
	 	//target address select
	 	AsiaPcieModify16(DramAttr->PcieBaseAddress, Address, D0F2_RSVAD_MMIO2T4GTAS_1_0, MMIO2T4G_TARGET_SELECT_A30);	 

	 	PEI_DEBUG((PeiServices, EFI_D_ERROR, "MMIOB2G BASE = 0x%08x\r\n", PciStart));
	 	PEI_DEBUG((PeiServices, EFI_D_ERROR, "MMIO2T4G BASE = 0x%08x\r\n", 0x800));
	 
 	}

 	//LGE20160420 flush CFG write for SVAD registers
	FlushCfgWrite(PeiServices, DramAttr, Address);



 	//LGE20160504 Add Save D0F2 Register for S3 Resume
 	//save MMIOB2G   D0F2_RX44[15:0] to D0F6_RX60[15:0]  for S3 Resume
 	Address =	AsiaPciAddress(CHX002_HB_BUS, CHX002_HB_DEV, CHX002_HIF_FUN, D0F2_MMIO_BELOW_2G_MMIOB2G);
 	Temp16 = AsiaPcieRead16(DramAttr->PcieBaseAddress, Address);

 	Address =	AsiaPciAddress(CHX002_HB_BUS, CHX002_HB_DEV, CHX002_SCRCH_FUN, D0F6_BIOS_SCRATCH_REG_9);
 	AsiaPcieWrite16(DramAttr->PcieBaseAddress, Address, Temp16);

 	//save MMIO2T4G  D0F2_RX46[15:0] to  D0F6_RX62[15:0]  for S3 Resume
 	Address =	AsiaPciAddress(CHX002_HB_BUS, CHX002_HB_DEV, CHX002_HIF_FUN, D0F2_MMIO_2G_TO_4G_MMIO2T4G);
 	Temp16 = AsiaPcieRead16(DramAttr->PcieBaseAddress, Address);

 	Address =	AsiaPciAddress(CHX002_HB_BUS, CHX002_HB_DEV, CHX002_SCRCH_FUN, D0F6_BIOS_SCRATCH_REG_9 + 2);
 	AsiaPcieWrite16(DramAttr->PcieBaseAddress, Address, Temp16);

 	//save RtopA	 D0F2_RXA4[31:0] to D0F6_RX64[31:0]  for S3 Resume
 	Address = AsiaPciAddress(CHX002_HB_BUS, CHX002_HB_DEV, CHX002_HIF_FUN, D0F2_HIGHEST_SVAD_LIMIT_TARGET_TO_MEM_DRAM_LIMIT_ADR_OVER_4G);
 	Temp32 = AsiaPcieRead32(DramAttr->PcieBaseAddress, Address);

 	Address =	AsiaPciAddress(CHX002_HB_BUS, CHX002_HB_DEV, CHX002_SCRCH_FUN, D0F6_BIOS_SCRATCH_REG_10);
 	AsiaPcieWrite32(DramAttr->PcieBaseAddress, Address, Temp32);

 	//save LowTopa D0F2_RxA8[15:0] to D0F6Rx68[15:0] for S3 Resume
 	Address = AsiaPciAddress(CHX002_HB_BUS, CHX002_HB_DEV, CHX002_HIF_FUN, D0F2_BELOW_4G_HIGHEST_MEM_LIMIT_DRAM_LIMIT_ADR_BELOW_4G);
 	Temp16 = AsiaPcieRead16(DramAttr->PcieBaseAddress, Address);

 	Address =	AsiaPciAddress(CHX002_HB_BUS, CHX002_HB_DEV, CHX002_SCRCH_FUN, D0F6_BIOS_SCRATCH_REG_11);
 	AsiaPcieWrite16(DramAttr->PcieBaseAddress, Address, Temp16);	 

	return;
}

VOID UpdateSVADMemEntry(
    IN EFI_PEI_SERVICES **PeiServices,
	IN DRAM_ATTRIBUTE *DramAttr)
{
	 UINT32 LowTopA;  //unit of  M
	 UINT32 RTopA;	  //uinit of M
	 UINT32 SvadLimit;//uinit of M
	 UINT64 Address;
	 UINT8	SvadIndex;
	
	 //get Pci Start address
	 Address = AsiaPciAddress(CHX002_HB_BUS, CHX002_HB_DEV, CHX002_HIF_FUN, D0F2_BELOW_4G_HIGHEST_MEM_LIMIT_DRAM_LIMIT_ADR_BELOW_4G);
	 LowTopA = AsiaPcieRead16(DramAttr->PcieBaseAddress, Address);
	 LowTopA = (LowTopA & 0xFFF0) >> 4;
	 //get RTOPA
	 Address = AsiaPciAddress(CHX002_HB_BUS, CHX002_HB_DEV, CHX002_HIF_FUN, D0F2_HIGHEST_SVAD_LIMIT_TARGET_TO_MEM_DRAM_LIMIT_ADR_OVER_4G);
	 RTopA = AsiaPcieRead32(DramAttr->PcieBaseAddress, Address);
	 RTopA = (RTopA & 0xFFFFF000) >> 12;
	
	
	 //SVAD Entry0
	 Address = AsiaPciAddress(CHX002_HB_BUS, CHX002_HB_DEV, CHX002_HIF_FUN, D0F2_MEM_ENT0);
	 //SVAD Limit = 4GB - 1
	 SvadLimit = (0x1000 - 1) >> 8;
	 AsiaPcieModify32(DramAttr->PcieBaseAddress, Address, D0F2_RSVAD_ME0LADDR_39_28, SvadLimit);
	
	 //SVAD Interleave
	 AsiaPcieModify32(DramAttr->PcieBaseAddress, Address, D0F2_RSVAD_ME0LOSEL_1_0, LOW_ORDER_SEL_NO_INTERLEAVE);
	
	
	  SvadIndex = D0F2_MEM_ENT1;
	  if(RTopA > 0x1000) {
		 //SVAD Entry1
		 Address = AsiaPciAddress(CHX002_HB_BUS, CHX002_HB_DEV, CHX002_HIF_FUN, D0F2_MEM_ENT1);
		 //SVAD Limit = RTopA - 1
		 SvadLimit = (RTopA - 1) >> 8;
		 AsiaPcieModify32(DramAttr->PcieBaseAddress, Address, D0F2_RSVAD_ME1LADDR_39_28, SvadLimit);
		 //SVAD Interleave
		 AsiaPcieModify32(DramAttr->PcieBaseAddress, Address, D0F2_RSVAD_ME1LOSEL_1_0, LOW_ORDER_SEL_NO_INTERLEAVE);
		 SvadIndex = D0F2_MEM_ENT2;
	  }
	
	  if(DramAttr->ConfigData.Above4GEnable) {
	   // 1T.limit=0xfff, 512G.limit=0x7ff, 256G.limit=0x3ff etc.
		  SvadLimit = 0xfff;
		  SvadLimit >>= DramAttr->ConfigData.Above4GLocation;	
		  Address = AsiaPciAddress(CHX002_HB_BUS, CHX002_HB_DEV, CHX002_HIF_FUN, SvadIndex);
		  AsiaPcieModify32(DramAttr->PcieBaseAddress, Address, D0F2_RSVAD_ME1LADDR_39_28, SvadLimit);
		  AsiaPcieModify32(DramAttr->PcieBaseAddress, Address, D0F2_RSVAD_ME1LOSEL_1_0|D0F2_RSVAD_ME1ATTR, LOW_ORDER_SEL_NO_INTERLEAVE|D0F2_RSVAD_ME1ATTR);
		  SvadIndex += 4; 
	}
	
	
	  //Remainig Entries
	  for(; SvadIndex <= D0F2_MEM_ENT19 ; SvadIndex += 4){
		 Address = AsiaPciAddress(CHX002_HB_BUS, CHX002_HB_DEV, CHX002_HIF_FUN, SvadIndex);
		 AsiaPcieModify32(DramAttr->PcieBaseAddress, Address, D0F2_RSVAD_ME2LADDR_39_28, SvadLimit);
		 //SVAD Interleave
		 AsiaPcieModify32(DramAttr->PcieBaseAddress, Address, D0F2_RSVAD_ME2LOSEL_1_0, LOW_ORDER_SEL_NO_INTERLEAVE);
	  }
	
	
	 //LGE20160420 flush CFG write for SVAD registers
	 FlushCfgWrite(PeiServices, DramAttr, Address);

}

VOID UpdateDVAD(
    IN EFI_PEI_SERVICES **PeiServices,
	IN DRAM_ATTRIBUTE *DramAttr)
{
	UINT32 LowTopA;  //unit of	M
	UINT32 RTopA;	 //uinit of M
	INT32  DvadBase; //uinit of M
	UINT32 DvadLimit;//uinit of M
	UINT64 Address;
	
	//get Pci Start address
	Address = AsiaPciAddress(CHX002_HB_BUS, CHX002_HB_DEV, CHX002_HIF_FUN, D0F2_BELOW_4G_HIGHEST_MEM_LIMIT_DRAM_LIMIT_ADR_BELOW_4G);
	LowTopA = AsiaPcieRead16(DramAttr->PcieBaseAddress, Address);
	LowTopA = (LowTopA & 0xFFF0) >> 4;
	//get RTOPA
	Address = AsiaPciAddress(CHX002_HB_BUS, CHX002_HB_DEV, CHX002_HIF_FUN, D0F2_HIGHEST_SVAD_LIMIT_TARGET_TO_MEM_DRAM_LIMIT_ADR_OVER_4G);
	RTopA = AsiaPcieRead32(DramAttr->PcieBaseAddress, Address);
	RTopA = (RTopA & 0xFFFFF000) >> 12;
	
	//DVAD Entry 0	  
	Address = AsiaPciAddress(CHX002_HB_BUS, CHX002_HB_DEV, CHX002_HIF_FUN, D0F2_DVAD_ENTRY_0);
	//Base = 0
	DvadBase = 0; //unit of MB,   DvadBase = (DvadBase>>7)<<6
	AsiaPcieModify32(DramAttr->PcieBaseAddress, Address, D0F2_RDVAD0BASE_40_27, (DvadBase >> 7) << 6);
	//LGE20160413 Limit = 4GB -1
	DvadLimit = 0x1000 - 1;  // unit of MB,  DvadLimit = (DvadLimit >> 8)<<20
	AsiaPcieModify32(DramAttr->PcieBaseAddress, Address, D0F2_RDVAD0LIMIT_39_28, (DvadLimit >> 8) << 20);
	//Enable DVAD 0   
	AsiaPcieModify32(DramAttr->PcieBaseAddress, Address, D0F2_RDVAD0NXM, 0);
	
	PEI_DEBUG((PeiServices, EFI_D_ERROR, "DVAD Entry 0 Base = %08x\r\n", (UINT32)DvadBase));
	PEI_DEBUG((PeiServices, EFI_D_ERROR, "DVAD Entry 0 Limit = %08x\r\n", (UINT32)DvadLimit));
	
	
	//DVAD Entry 1	
	Address = AsiaPciAddress(CHX002_HB_BUS, CHX002_HB_DEV, CHX002_HIF_FUN, D0F2_DVAD_ENTRY_1);
	//Base = LowTopA - 4GB	 
	DvadBase = (INT32)LowTopA - 0x1000; //unit of MB 
	DvadBase &= 0x1FFFFF;	
	AsiaPcieModify32(DramAttr->PcieBaseAddress, Address, D0F2_RDVAD1BASE_40_27, (DvadBase >> 7) << 6);
	
	//Limit = RTOPA - 1
	DvadLimit = RTopA - 1; //unit of MB
	AsiaPcieModify32(DramAttr->PcieBaseAddress, Address, D0F2_RDVAD1LIMIT_39_28, (DvadLimit >> 8) << 20);
	
	//Enable DVAD 1   
	AsiaPcieModify32(DramAttr->PcieBaseAddress, Address, D0F2_RDVAD1NXM, 0);
	PEI_DEBUG((PeiServices, EFI_D_ERROR, "DVAD Entry 1 Base = %08x\r\n", (UINT32)DvadBase));
	PEI_DEBUG((PeiServices, EFI_D_ERROR, "DVAD Entry 1 Limit = %08x\r\n", (UINT32)DvadLimit));	 

}
