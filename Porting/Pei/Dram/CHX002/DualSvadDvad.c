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
	UINT32 MasterMMIOSize,SlaveMMIOSize;//Eric debug for dual socket	
	UINT8  dual,SlaveBusNum=0x80;
    UINT64  Address;
	UINT16  Temp16;
	UINT32  Temp32;
	 
	 // Set LowTOPA = PCI_Memory_Start	and Set RTOPA
	 PciStart = DramAttr->ConfigData.PCIMemoryStart;
	 dual	  = DramAttr->ConfigData.ZxeDualSocket;
	 SlaveBusNum = DramAttr->ConfigData.ZxeSlaveBusNum;
	 EndAddr16=MasterMemSize+SlaveMemSize;

	if(	dual == 0) {
		PEI_DEBUG((PeiServices, EFI_D_ERROR, "Error!!! This is dual socket SVAD/DVAD code\n"));
		return;
	}
	 RealUmaSize = GetRealUmaSize(PeiServices,DramAttr,NbCfg);
	 if (RealUmaSize != 0)
		 PciStart &= (~(RealUmaSize-1));
	
	 //LGE20160630 Make sure ReadUmaSize is Above 4GB
	 //LGE20160630 EndAddr16 - PciStart > RealUmaSize ==> EndAddr16   > PciStart + RealUmaSize
	 if ((MasterMemSize << 6) > (PciStart + RealUmaSize)){
		 //Set LOWTOPA
		 Address = AsiaPciAddress(CHX002_HB_BUS, CHX002_HB_DEV, CHX002_HIF_FUN, D0F2_BELOW_4G_HIGHEST_MEM_LIMIT_DRAM_LIMIT_ADR_BELOW_4G + 1); 
		 AsiaPcieWrite8(DramAttr->PcieBaseAddress, Address, (UINT8)(PciStart >> 4)); 
		 Address = AsiaPciAddress(SlaveBusNum, CHX002_HB_DEV, CHX002_HIF_FUN, D0F2_BELOW_4G_HIGHEST_MEM_LIMIT_DRAM_LIMIT_ADR_BELOW_4G + 1); 
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
				 //RTOPA = 0x1000 + (EndAddr16 << 6)	- PciStart;  //Not waste memory, but report OS with RTopA-UmaSize  
				 PEI_DEBUG((PeiServices, EFI_D_ERROR, "Waste physical memory about 256M-UmaSize\n"));
				 RTOPA = 0x1000 + (EndAddr16 << 6)	- PciStart - 0x100; //waste physical memory about 256M-UmaSize
			 }				 
		 }
		 else
		 {
			 RTOPA = 0x1000 + (EndAddr16 << 6)	- PciStart; 
		 }
		 //ECS20161103 patch uma enable issue	-E
	
		 AsiaPcieModify32(DramAttr->PcieBaseAddress, Address, D0F2_RTOPA_39_20, RTOPA << 12);
		 Address = AsiaPciAddress(SlaveBusNum, CHX002_HB_DEV, CHX002_HIF_FUN, D0F2_HIGHEST_SVAD_LIMIT_TARGET_TO_MEM_DRAM_LIMIT_ADR_OVER_4G);
		 AsiaPcieModify32(DramAttr->PcieBaseAddress, Address, D0F2_RTOPA_39_20, RTOPA << 12);
		 
		 PEI_DEBUG((PeiServices, EFI_D_ERROR, "LOWTOPA = 0x%08x\n", PciStart));
		 PEI_DEBUG((PeiServices, EFI_D_ERROR, "RTOPA = 0x%08x\n", RTOPA));
	 }
	 //LGE20160630 EndAddr16 - PciStart <= RealUmaSize
	 else{			 
		 //ECS20161128 patch uma enable issue	-S
		 if(NbCfg->UMAEn)
		 {
			 if((MasterMemSize << 6)<=0x800) // if limit rank size=256M 
			 {
				 PciStart=0;//This is posion value.
				 RTOPA=0;//This is posion value.
				 PEI_DEBUG((PeiServices, EFI_D_ERROR, "Can't support Master Memory size <=2G when UMA enable\n"));
				 while(1); 
			 }	 
			 else if(RealUmaSize >= 0x100) // if UMA = 256M/512M
			 {
				 PciStart = (MasterMemSize << 6) - RealUmaSize; 
				 RTOPA = 0x1000+SlaveMemSize;// 0x1000 + (EndAddr16 << 6)	- PciStart - RealUmaSize;
			 }			 
			 else // UMA=64M/128M/8M/16M/32M
			 {
				 PciStart = (MasterMemSize << 6) - 0x100; 
				 RTOPA = 0x1000+SlaveMemSize;// 0x1000 + (EndAddr16 << 6)	- PciStart - RealUmaSize;
				 PEI_DEBUG((PeiServices, EFI_D_ERROR, "Waste physical memory about 256M-UmaSize\n"));
			 }	 
		 }
		 else
		 {
			 PciStart = (MasterMemSize << 6); 
			 RTOPA = 0x1000+SlaveMemSize;// 0x1000 + (EndAddr16 << 6)	- PciStart ;
		 }
		 //ECS20161128 patch uma enable issue	-E
		 if(PciStart<0x800) {
			 PEI_DEBUG((PeiServices, EFI_D_ERROR, "Can't support LowTopA <2G when UMA enable\n"));
			 while(1); 
		 }
		 
		 //Set LOWTOPA & RTOPA
		 Address = AsiaPciAddress(CHX002_HB_BUS, CHX002_HB_DEV, CHX002_HIF_FUN, D0F2_BELOW_4G_HIGHEST_MEM_LIMIT_DRAM_LIMIT_ADR_BELOW_4G + 1);
		 AsiaPcieWrite8(DramAttr->PcieBaseAddress, Address, (UINT8)(PciStart >> 4));
		 Address = AsiaPciAddress(SlaveBusNum, CHX002_HB_DEV, CHX002_HIF_FUN, D0F2_BELOW_4G_HIGHEST_MEM_LIMIT_DRAM_LIMIT_ADR_BELOW_4G + 1);
		 AsiaPcieWrite8(DramAttr->PcieBaseAddress, Address, (UINT8)(PciStart >> 4));
		 Address = AsiaPciAddress(CHX002_HB_BUS, CHX002_HB_DEV, CHX002_HIF_FUN, D0F2_HIGHEST_SVAD_LIMIT_TARGET_TO_MEM_DRAM_LIMIT_ADR_OVER_4G);
		 AsiaPcieModify32(DramAttr->PcieBaseAddress, Address, D0F2_RTOPA_39_20, RTOPA << 12);
		 Address = AsiaPciAddress(SlaveBusNum, CHX002_HB_DEV, CHX002_HIF_FUN, D0F2_HIGHEST_SVAD_LIMIT_TARGET_TO_MEM_DRAM_LIMIT_ADR_OVER_4G);
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
		 Address =	AsiaPciAddress(SlaveBusNum, CHX002_HB_DEV, CHX002_HIF_FUN, D0F2_MMIO_BELOW_2G_MMIOB2G);
		 AsiaPcieModify16(DramAttr->PcieBaseAddress, Address, D0F2_RSVAD_MMIOB2GTAS_1_0, MMIOB2G_DIS);
	
		 MasterMMIOSize = DramAttr->ConfigData.MasterMMIOSize;
		 SlaveMMIOSize	= DramAttr->ConfigData.SlaveMMIOSize;
	
		 Temp16 = 0;
		 Temp16 = (PciStart >> 8) << 4;// unit 256MB
		 Temp16 &= ~0x0F; 
		 Temp16 |= 0x04; //0->Slave; 1->Master
		 if(MasterMMIOSize > 0x10000000) //>256MB
			 Temp16 |= 0x02;//A30 as socket select bit
		 else if (MasterMMIOSize > (208*0x00100000)) //>208MB
			 Temp16 |= 0x00;//A28 as socket select bit
		 else 
			 Temp16 |= 0x01;//A29 as socket select bit
	
		 if(SlaveMMIOSize == 0) {
			 Temp16 &= ~0x0F; //0/1 -> Master
		 }
		 //Set MMIO2T4G
		 Address =	AsiaPciAddress(CHX002_HB_BUS, CHX002_HB_DEV, CHX002_HIF_FUN, D0F2_MMIO_2G_TO_4G_MMIO2T4G);
		 AsiaPcieWrite16(DramAttr->PcieBaseAddress, Address,Temp16 );
		 Address =	AsiaPciAddress(SlaveBusNum, CHX002_HB_DEV, CHX002_HIF_FUN, D0F2_MMIO_2G_TO_4G_MMIO2T4G);
		 AsiaPcieWrite16(DramAttr->PcieBaseAddress, Address,Temp16 );
		 PEI_DEBUG((PeiServices, EFI_D_ERROR, "MMIOB2G Disable\r\n"));
		 PEI_DEBUG((PeiServices, EFI_D_ERROR, "MMIO2T4G BASE = 0x%08x\r\n", PciStart));
	 }
	 //PciStart<2GB
	 else
	 {	  
		 PEI_DEBUG((PeiServices, EFI_D_ERROR, "Can't support MMIO below 2G in Dual socket!!!\r\n"));
		 return;
	 }
	
	 //LGE20160420 flush CFG write for SVAD registers
	FlushCfgWrite(PeiServices, DramAttr, Address);
	
	 //Cal MasterTop & SlaveTop for Numa
	 if(DramAttr->ConfigData.NumaEn && DramAttr->ConfigData.ZxeDualSocket == 1)
	 {		 
		 DramAttr->SlaveTop = RTOPA; //unit is MB		 
		 DramAttr->MasterTop = RTOPA - (SlaveMemSize<<6); //unit is MB
	 }
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

UINT8 Config1SVAD(
	IN UINT32 LowTopA,  //unit of	M
	IN UINT32 RTopA,	 //uinit of M
	IN DRAM_ATTRIBUTE *DramAttr)
{
	UINT64 Address;
	UINT32 SvadLimit;//uinit of M
	UINT8  SvadIndex;
	
	//Special SVAD settings for TA Test
	Address = AsiaPciAddress(CHX002_HB_BUS, CHX002_HB_DEV, CHX002_HIF_FUN, D0F2_MEM_ENT0);
	SvadLimit = 0x400 - 1;//SVAD Limit = 1GB - 1
	AsiaPcieModify32(DramAttr->PcieBaseAddress, Address, D0F2_RSVAD_ME0LADDR_39_28, SvadLimit >> 8);
	AsiaPcieModify32(DramAttr->PcieBaseAddress, Address, D0F2_RSVAD_ME0LOSEL_1_0, LOW_ORDER_SEL_A6);
	AsiaPcieModify32(DramAttr->PcieBaseAddress, Address, D0F2_RSVAD_ME0TLIST_1_0, 0x0000);//0/1 -> Socket0
	Address = AsiaPciAddress(CHX002_HB_BUS, CHX002_HB_DEV, CHX002_HIF_FUN, D0F2_MEM_ENT1);
	//SvadLimit = 0x600 - 1;//SVAD Limit = 1.5GB - 1
	SvadLimit = 0x500 - 1;//SVAD Limit = 1.25GB - 1
	AsiaPcieModify32(DramAttr->PcieBaseAddress, Address, D0F2_RSVAD_ME1LADDR_39_28, SvadLimit >> 8);
	AsiaPcieModify32(DramAttr->PcieBaseAddress, Address, D0F2_RSVAD_ME1LOSEL_1_0, LOW_ORDER_SEL_A6);
	AsiaPcieModify32(DramAttr->PcieBaseAddress, Address, D0F2_RSVAD_ME1TLIST_1_0, 0x3000);//0/1 -> Socket1
	Address = AsiaPciAddress(CHX002_HB_BUS, CHX002_HB_DEV, CHX002_HIF_FUN, D0F2_MEM_ENT2);
	SvadLimit = 0x1000 - 1;//SVAD Limit = 4GB - 1
	AsiaPcieModify32(DramAttr->PcieBaseAddress, Address, D0F2_RSVAD_ME2LADDR_39_28, SvadLimit >> 8);
	AsiaPcieModify32(DramAttr->PcieBaseAddress, Address, D0F2_RSVAD_ME2LOSEL_1_0, LOW_ORDER_SEL_A6);
	AsiaPcieModify32(DramAttr->PcieBaseAddress, Address, D0F2_RSVAD_ME2TLIST_1_0, 0x0000);//0/1 -> Socket0
	Address = AsiaPciAddress(CHX002_HB_BUS, CHX002_HB_DEV, CHX002_HIF_FUN, D0F2_MEM_ENT3);
	SvadLimit = ((RTopA - LowTopA + 0x1400)/2) - 1;
	AsiaPcieModify32(DramAttr->PcieBaseAddress, Address, D0F2_RSVAD_ME3LADDR_39_28, SvadLimit >> 8);
	AsiaPcieModify32(DramAttr->PcieBaseAddress, Address, D0F2_RSVAD_ME3LOSEL_1_0, LOW_ORDER_SEL_A6);
	AsiaPcieModify32(DramAttr->PcieBaseAddress, Address, D0F2_RSVAD_ME3TLIST_1_0, 0x0000);//0/1 -> Socket0
	Address = AsiaPciAddress(CHX002_HB_BUS, CHX002_HB_DEV, CHX002_HIF_FUN, D0F2_MEM_ENT4);
	SvadLimit = RTopA-1;
	AsiaPcieModify32(DramAttr->PcieBaseAddress, Address, D0F2_RSVAD_ME4LADDR_39_28, SvadLimit >> 8);
	AsiaPcieModify32(DramAttr->PcieBaseAddress, Address, D0F2_RSVAD_ME4LOSEL_1_0, LOW_ORDER_SEL_A6);
	AsiaPcieModify32(DramAttr->PcieBaseAddress, Address, D0F2_RSVAD_ME4TLIST_1_0, 0x3000);//0/1 -> Socket1
	
	SvadIndex = 5*4;//From entry5

	return SvadIndex;
}


VOID UpdateSVADMemEntry(
    IN EFI_PEI_SERVICES **PeiServices,
	IN DRAM_ATTRIBUTE *DramAttr)
{
	UINT32 LowTopA;  //unit of	M
	UINT32 RTopA;	 //uinit of M
	UINT32 SvadLimit;//uinit of M
	UINT64 Address;
	UINT8  SvadIndex;
	UINT32 MasterMemSize;
	UINT8  SlaveBusNum = DramAttr->ConfigData.ZxeSlaveBusNum;
	
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
	SvadLimit = 0x1000 - 1;
	AsiaPcieModify32(DramAttr->PcieBaseAddress, Address, D0F2_RSVAD_ME0LADDR_39_28, SvadLimit >> 8);
	
	//SVAD Interleave
	AsiaPcieModify32(DramAttr->PcieBaseAddress, Address, D0F2_RSVAD_ME0LOSEL_1_0, LOW_ORDER_SEL_A6);
	AsiaPcieModify32(DramAttr->PcieBaseAddress, Address, D0F2_RSVAD_ME0TLIST_1_0, 0x0000);//0/1 -> Socket0
	
	//Eric debug for dual socket
	//If Master phyasical memory size = Slave
	MasterMemSize = (RTopA - (0x1000-LowTopA))/2;
	PEI_DEBUG((PeiServices, EFI_D_ERROR, "Special Conf = 0x%x\r\n", DramAttr->ConfigData.SpecialConf));
	PEI_DEBUG((PeiServices, EFI_D_ERROR, "NumaEn = 0x%x\r\n", DramAttr->ConfigData.NumaEn));
	PEI_DEBUG((PeiServices, EFI_D_ERROR, "Socket Interleave = 0x%x\r\n", DramAttr->ConfigData.SocketIntlv));
	
	if(DramAttr->ConfigData.SpecialConf == 0) {
		 if(DramAttr->ConfigData.NumaEn) {
			 if (MasterMemSize <= LowTopA) {
				 //Set SVAD entry 1 same as entry 0
				 Address = AsiaPciAddress(CHX002_HB_BUS, CHX002_HB_DEV, CHX002_HIF_FUN, D0F2_MEM_ENT1);
				 SvadLimit = 0x1000 - 1;
				 AsiaPcieModify32(DramAttr->PcieBaseAddress, Address, D0F2_RSVAD_ME1LADDR_39_28, SvadLimit >> 8);
				 //SVAD Interleave
				 AsiaPcieModify32(DramAttr->PcieBaseAddress, Address, D0F2_RSVAD_ME0LOSEL_1_0, LOW_ORDER_SEL_A6);
				 AsiaPcieModify32(DramAttr->PcieBaseAddress, Address, D0F2_RSVAD_ME0TLIST_1_0, 0x0000);//0/1 -> Socket0
			 }	 
			 else {
				 //SVAD Entry1 for NO interleaving
				 Address = AsiaPciAddress(CHX002_HB_BUS, CHX002_HB_DEV, CHX002_HIF_FUN, D0F2_MEM_ENT1);
				 //SvadLimit = (MasterMemSize - LowTopA + 0x1000); //same as following rule.
				 SvadLimit = ((RTopA - LowTopA + 0x1000)/2) - 1;
				 AsiaPcieModify32(DramAttr->PcieBaseAddress, Address, D0F2_RSVAD_ME1LADDR_39_28, SvadLimit >> 8);
				 //SVAD Interleave
				 AsiaPcieModify32(DramAttr->PcieBaseAddress, Address, D0F2_RSVAD_ME1LOSEL_1_0, LOW_ORDER_SEL_A6);
				 AsiaPcieModify32(DramAttr->PcieBaseAddress, Address, D0F2_RSVAD_ME1TLIST_1_0, 0x0000);//0/1 -> Socket0
			 }
		 }
		 else {
			 //SVAD Entry1 for interleaving
			 Address = AsiaPciAddress(CHX002_HB_BUS, CHX002_HB_DEV, CHX002_HIF_FUN, D0F2_MEM_ENT1);
			 //SvadLimit = ((MasterMemSize - LowTopA)*2 + 0x1000); //same as following rule.
			 SvadLimit = RTopA - LowTopA - 1;
			 AsiaPcieModify32(DramAttr->PcieBaseAddress, Address, D0F2_RSVAD_ME1LADDR_39_28, SvadLimit >> 8);
			 //SVAD Interleave
			 switch (DramAttr->ConfigData.SocketIntlv) {
				 case 0: 
					 AsiaPcieModify32(DramAttr->PcieBaseAddress, Address, D0F2_RSVAD_ME1HEN, 0);
					 AsiaPcieModify32(DramAttr->PcieBaseAddress, Address, D0F2_RSVAD_ME1LOSEL_1_0, LOW_ORDER_SEL_A6);
					 break;//A6 interleaving
				 case 1:
					 AsiaPcieModify32(DramAttr->PcieBaseAddress, Address, D0F2_RSVAD_ME1HEN, 0);
					 AsiaPcieModify32(DramAttr->PcieBaseAddress, Address, D0F2_RSVAD_ME1LOSEL_1_0, LOW_ORDER_SEL_A7);
					 break;//A7 interleaving
				 case 2:
					 AsiaPcieModify32(DramAttr->PcieBaseAddress, Address, D0F2_RSVAD_ME1HEN, 0);
					 AsiaPcieModify32(DramAttr->PcieBaseAddress, Address, D0F2_RSVAD_ME1LOSEL_1_0, LOW_ORDER_SEL_A8);
					 break;//A8 interleaving 
				 case 3:
					 AsiaPcieModify32(DramAttr->PcieBaseAddress, Address, D0F2_RSVAD_ME1HEN, D0F2_RSVAD_ME1HEN);
					 AsiaPcieModify32(DramAttr->PcieBaseAddress, Address, D0F2_RSVAD_ME1HSEL_1_0, 0);
					 AsiaPcieModify32(DramAttr->PcieBaseAddress, Address, D0F2_RSVAD_ME1LOSEL_1_0, LOW_ORDER_SEL_A6);
					 break;//A16^A6 interleaving		 
				 case 4:
					 AsiaPcieModify32(DramAttr->PcieBaseAddress, Address, D0F2_RSVAD_ME1HEN, D0F2_RSVAD_ME1HEN);
					 AsiaPcieModify32(DramAttr->PcieBaseAddress, Address, D0F2_RSVAD_ME1HSEL_1_0, BIT17);
					 AsiaPcieModify32(DramAttr->PcieBaseAddress, Address, D0F2_RSVAD_ME1LOSEL_1_0, LOW_ORDER_SEL_A7);
					 break;//A17^A7 interleaving 
				 case 5:
					 AsiaPcieModify32(DramAttr->PcieBaseAddress, Address, D0F2_RSVAD_ME1HEN, D0F2_RSVAD_ME1HEN);
					 AsiaPcieModify32(DramAttr->PcieBaseAddress, Address, D0F2_RSVAD_ME1HSEL_1_0, BIT18);
					 AsiaPcieModify32(DramAttr->PcieBaseAddress, Address, D0F2_RSVAD_ME1LOSEL_1_0, LOW_ORDER_SEL_A8);
					 break;//A18^A8 interleaving 
				 default:
					 AsiaPcieModify32(DramAttr->PcieBaseAddress, Address, D0F2_RSVAD_ME1HEN, 0);
					 AsiaPcieModify32(DramAttr->PcieBaseAddress, Address, D0F2_RSVAD_ME1LOSEL_1_0, LOW_ORDER_SEL_A6);
					 break;//A6 interleaving	 
			 }
			 AsiaPcieModify32(DramAttr->PcieBaseAddress, Address, D0F2_RSVAD_ME1TLIST_1_0, 0x2000);//0 -> Socket0;1 -> Socket1
		 }
		 //SVAD Entry2
		 Address = AsiaPciAddress(CHX002_HB_BUS, CHX002_HB_DEV, CHX002_HIF_FUN, D0F2_MEM_ENT2);
		 SvadLimit=RTopA-1;
		 AsiaPcieModify32(DramAttr->PcieBaseAddress, Address, D0F2_RSVAD_ME2LADDR_39_28, SvadLimit >> 8);		 
		 //SVAD Interleave
		 AsiaPcieModify32(DramAttr->PcieBaseAddress, Address, D0F2_RSVAD_ME2LOSEL_1_0, LOW_ORDER_SEL_A6);
		 AsiaPcieModify32(DramAttr->PcieBaseAddress, Address, D0F2_RSVAD_ME2TLIST_1_0, 0x3000);//0/1 -> Socket1
		 SvadIndex = 3*4;//From entry3
	 }
	 else if(DramAttr->ConfigData.SpecialConf == 1) {
	 	 SvadIndex = Config1SVAD(LowTopA,RTopA,DramAttr);
	 }
	 else
		 SvadIndex = 3*4;
	
	 for(; D0F2_MEM_ENT0 + SvadIndex <= D0F2_MEM_ENT19 ; SvadIndex += 4){
		  //SVAD Entry X ~ 19
		  Address = AsiaPciAddress(CHX002_HB_BUS, CHX002_HB_DEV, CHX002_HIF_FUN, D0F2_MEM_ENT0 + SvadIndex);
		  //SVAD Entry X ~ 19  Limit =SVAD Entry2 Limit Indicate Those Entry  is Invalid
		  SvadLimit = RTopA - 1;
		  AsiaPcieModify32(DramAttr->PcieBaseAddress, Address, D0F2_RSVAD_ME3LADDR_39_28, SvadLimit >> 8);
		   //SVAD Interleave
		  AsiaPcieModify32(DramAttr->PcieBaseAddress, Address, D0F2_RSVAD_ME3LOSEL_1_0, LOW_ORDER_SEL_NO_INTERLEAVE);
	 }

	//Sync to Slave SVAD setting
	for(SvadIndex = 0; D0F2_MEM_ENT0 + SvadIndex <= D0F2_MEM_ENT19 ; SvadIndex += 4){
		Address = AsiaPciAddress(CHX002_HB_BUS, CHX002_HB_DEV, CHX002_HIF_FUN, D0F2_MEM_ENT0 + SvadIndex);
		SvadLimit = AsiaPcieRead32(DramAttr->PcieBaseAddress, Address);
		Address = AsiaPciAddress(SlaveBusNum, CHX002_HB_DEV, CHX002_HIF_FUN, D0F2_MEM_ENT0 + SvadIndex);
		AsiaPcieWrite32(DramAttr->PcieBaseAddress, Address, SvadLimit );
	}
	
	//LGE20160420 flush CFG write for SVAD registers
	FlushCfgWrite(PeiServices, DramAttr, Address);
	
}

VOID Config1Dvad(UINT32 LowTopA,UINT32 RTopA,UINT8  SlaveBusNum,UINT64 PcieBase)
{
	INT32  DvadBase; //uinit of M
	UINT32 DvadLimit;//uinit of M
	UINT64 Address;
	UINT16 i;

    /*****************************************/
    /* 18.5G~34G Slave     (Limit=8800)
      /* 4G    ~ 18.5G Master(Limit=4A00) 
      /* 2G    ~ 4G MMIO      (Limit=1000)
      /* 1.25G ~ 2G Master     (Limit=800)
      /* 1G    ~ 1.25G Slave    (Limit=500)
      /* 0      ~ 1G Master     (Limit=400)
	/*****************************************/


	//Master DVAD Entry  
	Address = AsiaPciAddress(CHX002_HB_BUS, CHX002_HB_DEV, CHX002_HIF_FUN, D0F2_DVAD_ENTRY_0);
	DvadBase = 0; //unit of MB,   DvadBase = (DvadBase>>7)<<6
	AsiaPcieModify32(PcieBase, Address, D0F2_RDVAD0BASE_40_27, (DvadBase >> 7) << 6);
	DvadLimit = 0x400 - 1;  // unit of MB,  DvadLimit = (DvadLimit >> 8)<<20
	AsiaPcieModify32(PcieBase, Address, D0F2_RDVAD0LIMIT_39_28, (DvadLimit >> 8) << 20);
	AsiaPcieModify32(PcieBase, Address, D0F2_RDVAD0ITLVB_1_0, 0);
	AsiaPcieModify32(PcieBase, Address, D0F2_RDVAD0NXM, 0);
	
	Address = AsiaPciAddress(CHX002_HB_BUS, CHX002_HB_DEV, CHX002_HIF_FUN, D0F2_DVAD_ENTRY_1);
	DvadBase = 0; //unit of MB,   DvadBase = (DvadBase>>7)<<6
	AsiaPcieModify32(PcieBase, Address, D0F2_RDVAD1BASE_40_27, (DvadBase >> 7) << 6);
	//DvadLimit = 0x600 - 1;  // unit of MB,  DvadLimit = (DvadLimit >> 8)<<20
	DvadLimit = 0x500 - 1;  // unit of MB,  DvadLimit = (DvadLimit >> 8)<<20
	AsiaPcieModify32(PcieBase, Address, D0F2_RDVAD1LIMIT_39_28, (DvadLimit >> 8) << 20);
	AsiaPcieModify32(PcieBase, Address, D0F2_RDVAD1ITLVB_1_0, 0);
	AsiaPcieModify32(PcieBase, Address, D0F2_RDVAD1NXM, 1);
	
	Address = AsiaPciAddress(CHX002_HB_BUS, CHX002_HB_DEV, CHX002_HIF_FUN, D0F2_DVAD_ENTRY_2);
	DvadBase = 0x400 - (DvadLimit + 1); //unit of MB,   DvadBase = (DvadBase>>7)<<6
	AsiaPcieModify32(PcieBase, Address, D0F2_RDVAD2BASE_40_27, (DvadBase >> 7) << 6);
	DvadLimit = 0x1000 - 1;  // unit of MB,  DvadLimit = (DvadLimit >> 8)<<20
	AsiaPcieModify32(PcieBase, Address, D0F2_RDVAD2LIMIT_39_28, (DvadLimit >> 8) << 20);
	AsiaPcieModify32(PcieBase, Address, D0F2_RDVAD2ITLVB_1_0, 0);
	AsiaPcieModify32(PcieBase, Address, D0F2_RDVAD2NXM, 0);
	
	Address = AsiaPciAddress(CHX002_HB_BUS, CHX002_HB_DEV, CHX002_HIF_FUN, D0F2_DVAD_ENTRY_3);
	DvadBase = LowTopA - 0x200 - (DvadLimit+1); //unit of MB,   DvadBase = (DvadBase>>7)<<6
	AsiaPcieModify32(PcieBase, Address, D0F2_RDVAD3BASE_40_27, (DvadBase >> 7) << 6);
	DvadLimit = ((RTopA - LowTopA + 0x1400)/2) - 1;  // unit of MB,  DvadLimit = (DvadLimit >> 8)<<20
	AsiaPcieModify32(PcieBase, Address, D0F2_RDVAD3LIMIT_39_28, (DvadLimit >> 8) << 20);
	AsiaPcieModify32(PcieBase, Address, D0F2_RDVAD3ITLVB_1_0, 0);
	AsiaPcieModify32(PcieBase, Address, D0F2_RDVAD3NXM, 0);
	for(i=D0F2_DVAD_ENTRY_4;i<=D0F2_DVAD_ENTRY_7;i+=4) {
		Address = AsiaPciAddress(CHX002_HB_BUS, CHX002_HB_DEV, CHX002_HIF_FUN, i);
		//Disable DVAD 4~7   
		AsiaPcieModify32(PcieBase, Address, D0F2_RDVAD2NXM, 1);
	}	
	
	//Slave DVAD Entry 
	Address = AsiaPciAddress(SlaveBusNum, CHX002_HB_DEV, CHX002_HIF_FUN, D0F2_DVAD_ENTRY_0);
	DvadBase = 0; //unit of MB,   DvadBase = (DvadBase>>7)<<6
	AsiaPcieModify32(PcieBase, Address, D0F2_RDVAD0BASE_40_27, (DvadBase >> 7) << 6);
	DvadLimit = 0x400 - 1;  // unit of MB,  DvadLimit = (DvadLimit >> 8)<<20
	AsiaPcieModify32(PcieBase, Address, D0F2_RDVAD0LIMIT_39_28, (DvadLimit >> 8) << 20);
	AsiaPcieModify32(PcieBase, Address, D0F2_RDVAD0ITLVB_1_0, 0);
	AsiaPcieModify32(PcieBase, Address, D0F2_RDVAD0NXM, 1);
	
	Address = AsiaPciAddress(SlaveBusNum, CHX002_HB_DEV, CHX002_HIF_FUN, D0F2_DVAD_ENTRY_1);
	DvadBase = 0 - (DvadLimit + 1) ; //unit of MB,   DvadBase = (DvadBase>>7)<<6
	AsiaPcieModify32(PcieBase, Address, D0F2_RDVAD1BASE_40_27, (DvadBase >> 7) << 6);
	//DvadLimit = 0x600 - 1;  // unit of MB,  DvadLimit = (DvadLimit >> 8)<<20
	DvadLimit = 0x500 - 1;  // unit of MB,  DvadLimit = (DvadLimit >> 8)<<20
	AsiaPcieModify32(PcieBase, Address, D0F2_RDVAD1LIMIT_39_28, (DvadLimit >> 8) << 20);
	AsiaPcieModify32(PcieBase, Address, D0F2_RDVAD1ITLVB_1_0, 0);
	AsiaPcieModify32(PcieBase, Address, D0F2_RDVAD1NXM, 0);
	
	Address = AsiaPciAddress(SlaveBusNum, CHX002_HB_DEV, CHX002_HIF_FUN, D0F2_DVAD_ENTRY_2);
	DvadBase = 0x200 - (DvadLimit + 1); //unit of MB,   DvadBase = (DvadBase>>7)<<6
	AsiaPcieModify32(PcieBase, Address, D0F2_RDVAD2BASE_40_27, (DvadBase >> 7) << 6);
	DvadLimit = ((RTopA - LowTopA + 0x1400)/2) - 1;  // unit of MB,  DvadLimit = (DvadLimit >> 8)<<20
	AsiaPcieModify32(PcieBase, Address, D0F2_RDVAD2LIMIT_39_28, (DvadLimit >> 8) << 20);
	AsiaPcieModify32(PcieBase, Address, D0F2_RDVAD2ITLVB_1_0, 0);
	AsiaPcieModify32(PcieBase, Address, D0F2_RDVAD2NXM, 1);
	
	Address = AsiaPciAddress(SlaveBusNum, CHX002_HB_DEV, CHX002_HIF_FUN, D0F2_DVAD_ENTRY_3);
	DvadBase = RTopA - (DvadLimit+1); //unit of MB,   DvadBase = (DvadBase>>7)<<6
	AsiaPcieModify32(PcieBase, Address, D0F2_RDVAD3BASE_40_27, (DvadBase >> 7) << 6);
	DvadLimit = RTopA - 1;  // unit of MB,  DvadLimit = (DvadLimit >> 8)<<20
	AsiaPcieModify32(PcieBase, Address, D0F2_RDVAD3LIMIT_39_28, (DvadLimit >> 8) << 20);
	AsiaPcieModify32(PcieBase, Address, D0F2_RDVAD3ITLVB_1_0, 0);
	AsiaPcieModify32(PcieBase, Address, D0F2_RDVAD3NXM, 0);
	
	for(i=D0F2_DVAD_ENTRY_4;i<=D0F2_DVAD_ENTRY_7;i+=4) {
		Address = AsiaPciAddress(SlaveBusNum, CHX002_HB_DEV, CHX002_HIF_FUN, i);
		//Disable DVAD 4~7   
		AsiaPcieModify32(PcieBase, Address, D0F2_RDVAD2NXM, 1);
	}	

	return ;
}

VOID UpdateMasterDVAD(
	IN EFI_PEI_SERVICES **PeiServices,
	IN UINT32 LowTopA,
	IN UINT32 RTopA,
	IN UINT32 MasterMemSize,
	IN DRAM_ATTRIBUTE *DramAttr)
{
	INT32  DvadBase; //uinit of M
	UINT32 DvadLimit;//uinit of M
	UINT64 Address;
	UINT16 i;
	
	//Master DVAD Entry 0    
	Address = AsiaPciAddress(CHX002_HB_BUS, CHX002_HB_DEV, CHX002_HIF_FUN, D0F2_DVAD_ENTRY_0);
	//Base = 0
	DvadBase = 0; //unit of MB,   DvadBase = (DvadBase>>7)<<6
	AsiaPcieModify32(DramAttr->PcieBaseAddress, Address, D0F2_RDVAD0BASE_40_27, (DvadBase >> 7) << 6);
	//LGE20160413 Limit = 4GB -1
	DvadLimit = 0x1000 - 1;  // unit of MB,  DvadLimit = (DvadLimit >> 8)<<20
   	AsiaPcieModify32(DramAttr->PcieBaseAddress, Address, D0F2_RDVAD0LIMIT_39_28, (DvadLimit >> 8) << 20);
   	//No interleave   
   	AsiaPcieModify32(DramAttr->PcieBaseAddress, Address, D0F2_RDVAD0ITLVB_1_0, 0);
   	//Enable DVAD 0   
   	AsiaPcieModify32(DramAttr->PcieBaseAddress, Address, D0F2_RDVAD0NXM, 0);
   	PEI_DEBUG((PeiServices, EFI_D_ERROR, "Master DVAD Entry 0 Base = %08x\r\n", (UINT32)DvadBase));
   	PEI_DEBUG((PeiServices, EFI_D_ERROR, "Master DVAD Entry 0 Limit = %08x\r\n", (UINT32)DvadLimit));

	if(DramAttr->ConfigData.NumaEn) {
		if (MasterMemSize <= LowTopA) {
			Address = AsiaPciAddress(CHX002_HB_BUS, CHX002_HB_DEV, CHX002_HIF_FUN, D0F2_DVAD_ENTRY_1);
			//Disable Master DVAD 1	 
			AsiaPcieModify32(DramAttr->PcieBaseAddress, Address, D0F2_RDVAD1NXM, 1);
		}
		else {
			//Master DVAD Entry 1	 
			Address = AsiaPciAddress(CHX002_HB_BUS, CHX002_HB_DEV, CHX002_HIF_FUN, D0F2_DVAD_ENTRY_1);
			//Base = DVA end of Entry0 - SVA end of Entry0 = LowTopA - entry 0 limit
			DvadBase = LowTopA - (DvadLimit+1); //for NO interleave mode 
			DvadBase &= 0x1FFFFF;  
			AsiaPcieModify32(DramAttr->PcieBaseAddress, Address, D0F2_RDVAD1BASE_40_27, (DvadBase >> 7) << 6);
			DvadLimit = ((RTopA - LowTopA + 0x1000)/2) - 1;  // unit of MB,  DvadLimit = (DvadLimit >> 8)<<20
			AsiaPcieModify32(DramAttr->PcieBaseAddress, Address, D0F2_RDVAD1LIMIT_39_28, (DvadLimit >> 8) << 20);
			//NO interleave   
			AsiaPcieModify32(DramAttr->PcieBaseAddress, Address, D0F2_RDVAD1ITLVB_1_0, 0);
			//Enable DVAD 1   
			AsiaPcieModify32(DramAttr->PcieBaseAddress, Address, D0F2_RDVAD1NXM, 0);
		}
		PEI_DEBUG((PeiServices, EFI_D_ERROR, "Master DVAD Entry 1 Base = %08x\r\n", (UINT32)DvadBase));
		PEI_DEBUG((PeiServices, EFI_D_ERROR, "Master DVAD Entry 1 Limit = %08x\r\n", (UINT32)DvadLimit));

	}
	else {
		//Master DVAD Entry 1	 
		Address = AsiaPciAddress(CHX002_HB_BUS, CHX002_HB_DEV, CHX002_HIF_FUN, D0F2_DVAD_ENTRY_1);
		//Base = DVA end of Entry0 - SVA end of Entry0/2 = LowTopA - entry 0 limit/2
		DvadBase = LowTopA - ((DvadLimit+1)/2); //for interleave mode 
		DvadBase &= 0x1FFFFF;  
		AsiaPcieModify32(DramAttr->PcieBaseAddress, Address, D0F2_RDVAD1BASE_40_27, (DvadBase >> 7) << 6);
		DvadLimit = RTopA - LowTopA - 1;  // unit of MB,  DvadLimit = (DvadLimit >> 8)<<20
		AsiaPcieModify32(DramAttr->PcieBaseAddress, Address, D0F2_RDVAD1LIMIT_39_28, (DvadLimit >> 8) << 20);
		// interleave   
		switch (DramAttr->ConfigData.SocketIntlv) {
			case 0:  
			case 3:
				AsiaPcieModify32(DramAttr->PcieBaseAddress, Address, D0F2_RDVAD1ITLVB_1_0, BIT3);
				break;
			case 1:
			case 4:
				AsiaPcieModify32(DramAttr->PcieBaseAddress, Address, D0F2_RDVAD1ITLVB_1_0, BIT4);
				break;	
			case 2:
			case 5:
				AsiaPcieModify32(DramAttr->PcieBaseAddress, Address, D0F2_RDVAD1ITLVB_1_0, BIT4|BIT3);
				break;
			default:
				AsiaPcieModify32(DramAttr->PcieBaseAddress, Address, D0F2_RDVAD1ITLVB_1_0, BIT3);
				break;
		}
		//Enable DVAD 1   
		AsiaPcieModify32(DramAttr->PcieBaseAddress, Address, D0F2_RDVAD1NXM, 0);
		PEI_DEBUG((PeiServices, EFI_D_ERROR, "Master DVAD Entry 1 Base = %08x\r\n", (UINT32)DvadBase));
		PEI_DEBUG((PeiServices, EFI_D_ERROR, "Master DVAD Entry 1 Limit = %08x\r\n", (UINT32)DvadLimit));
	}
	for(i=D0F2_DVAD_ENTRY_2;i<=D0F2_DVAD_ENTRY_7;i+=4) {
		Address = AsiaPciAddress(CHX002_HB_BUS, CHX002_HB_DEV, CHX002_HIF_FUN, i);
		//Disable DVAD 2~7   
		AsiaPcieModify32(DramAttr->PcieBaseAddress, Address, D0F2_RDVAD2NXM, 1);
	}

	return;
}

VOID UpdateSlaveDVAD(
	IN EFI_PEI_SERVICES **PeiServices,
	IN UINT32 LowTopA,
	IN UINT32 RTopA,
	IN DRAM_ATTRIBUTE *DramAttr)	
{
	INT32  DvadBase; //uinit of M
	UINT32 DvadLimit;//uinit of M
	UINT64 Address;
	UINT16 i;
	UINT8  SlaveBusNum = DramAttr->ConfigData.ZxeSlaveBusNum;
	
	if(DramAttr->ConfigData.NumaEn) {
		//Slave DVAD Entry 0    
   		Address = AsiaPciAddress(SlaveBusNum, CHX002_HB_DEV, CHX002_HIF_FUN, D0F2_DVAD_ENTRY_0);
   		//Base = 0
		DvadBase = 0; //unit of MB,   DvadBase = (DvadBase>>7)<<6
   		AsiaPcieModify32(DramAttr->PcieBaseAddress, Address, D0F2_RDVAD0BASE_40_27, (DvadBase >> 7) << 6);
   		//LGE20160413 Limit = (RTopA - SlaveMemSize)
	   	DvadLimit = ((RTopA - LowTopA + 0x1000)/2) - 1;  // unit of MB,  DvadLimit = (DvadLimit >> 8)<<20
   		AsiaPcieModify32(DramAttr->PcieBaseAddress, Address, D0F2_RDVAD0LIMIT_39_28, (DvadLimit >> 8) << 20);
   		//No interleave   
	   	AsiaPcieModify32(DramAttr->PcieBaseAddress, Address, D0F2_RDVAD0ITLVB_1_0, 0);
   		//Disable DVAD 0   
   		AsiaPcieModify32(DramAttr->PcieBaseAddress, Address, D0F2_RDVAD0NXM, 1);
   	 	PEI_DEBUG((PeiServices, EFI_D_ERROR, "Slave DVAD Entry 0 Base = %08x\r\n", (UINT32)DvadBase));
   		PEI_DEBUG((PeiServices, EFI_D_ERROR, "Slave DVAD Entry 0 Limit = %08x\r\n", (UINT32)DvadLimit));

		//Slave DVAD Entry 1	 
		Address = AsiaPciAddress(SlaveBusNum, CHX002_HB_DEV, CHX002_HIF_FUN, D0F2_DVAD_ENTRY_1);
		//Base = DVA end of Entry1 - SVA end of Entry1 = 0 - entry 0 limit
		DvadBase = 0 - (DvadLimit+1); //for NO interleave mode 
		DvadBase &= 0x1FFFFF;  
		AsiaPcieModify32(DramAttr->PcieBaseAddress, Address, D0F2_RDVAD1BASE_40_27, (DvadBase >> 7) << 6);
		DvadLimit = RTopA - 1;  // unit of MB,  DvadLimit = (DvadLimit >> 8)<<20
		AsiaPcieModify32(DramAttr->PcieBaseAddress, Address, D0F2_RDVAD1LIMIT_39_28, (DvadLimit >> 8) << 20);
		//NO interleave   
		AsiaPcieModify32(DramAttr->PcieBaseAddress, Address, D0F2_RDVAD1ITLVB_1_0, 0);
		//Enable DVAD 1   
		AsiaPcieModify32(DramAttr->PcieBaseAddress, Address, D0F2_RDVAD1NXM, 0);
		PEI_DEBUG((PeiServices, EFI_D_ERROR, "Slave DVAD Entry 1 Base = %08x\r\n", (UINT32)DvadBase));
		PEI_DEBUG((PeiServices, EFI_D_ERROR, "Slave DVAD Entry 1 Limit = %08x\r\n", (UINT32)DvadLimit));

		Address = AsiaPciAddress(SlaveBusNum, CHX002_HB_DEV, CHX002_HIF_FUN, D0F2_DVAD_ENTRY_2);
		//Disable DVAD 2   
		AsiaPcieModify32(DramAttr->PcieBaseAddress, Address, D0F2_RDVAD2NXM, 1);
	}
	else {
   		//Slave DVAD Entry 0    
		Address = AsiaPciAddress(SlaveBusNum, CHX002_HB_DEV, CHX002_HIF_FUN, D0F2_DVAD_ENTRY_0);
		//Base = 0
   		DvadBase = 0; //unit of MB,   DvadBase = (DvadBase>>7)<<6
		AsiaPcieModify32(DramAttr->PcieBaseAddress, Address, D0F2_RDVAD0BASE_40_27, (DvadBase >> 7) << 6);
		//LGE20160413 Limit = 4GB -1
	   	DvadLimit = 0x1000 - 1;  // unit of MB,  DvadLimit = (DvadLimit >> 8)<<20
   		AsiaPcieModify32(DramAttr->PcieBaseAddress, Address, D0F2_RDVAD0LIMIT_39_28, (DvadLimit >> 8) << 20);
   		//No interleave   
	   	AsiaPcieModify32(DramAttr->PcieBaseAddress, Address, D0F2_RDVAD0ITLVB_1_0, 0);
   		//Disable DVAD 0   
   		AsiaPcieModify32(DramAttr->PcieBaseAddress, Address, D0F2_RDVAD0NXM, 1);
   		PEI_DEBUG((PeiServices, EFI_D_ERROR, "Slave DVAD Entry 0 Base = %08x\r\n", (UINT32)DvadBase));
   		PEI_DEBUG((PeiServices, EFI_D_ERROR, "Slave DVAD Entry 0 Limit = %08x\r\n", (UINT32)DvadLimit));
		//Slave DVAD Entry 1	 
		Address = AsiaPciAddress(SlaveBusNum, CHX002_HB_DEV, CHX002_HIF_FUN, D0F2_DVAD_ENTRY_1);
		//Base = DVA end of Entry0 - SVA end of Entry0/2 = 0 - entry 0 limit/2
		DvadBase = 0 - ((DvadLimit+1)/2); //for interleave mode 
		DvadBase &= 0x1FFFFF;  
		AsiaPcieModify32(DramAttr->PcieBaseAddress, Address, D0F2_RDVAD1BASE_40_27, (DvadBase >> 7) << 6);
		DvadLimit = RTopA - LowTopA - 1;  // unit of MB,  DvadLimit = (DvadLimit >> 8)<<20
		AsiaPcieModify32(DramAttr->PcieBaseAddress, Address, D0F2_RDVAD1LIMIT_39_28, (DvadLimit >> 8) << 20);
		// interleave   
		switch (DramAttr->ConfigData.SocketIntlv) {
			case 0:  
			case 3:
				AsiaPcieModify32(DramAttr->PcieBaseAddress, Address, D0F2_RDVAD1ITLVB_1_0, BIT3);
				break;
			case 1:
			case 4:
				AsiaPcieModify32(DramAttr->PcieBaseAddress, Address, D0F2_RDVAD1ITLVB_1_0, BIT4);
				break;	
			case 2:
			case 5:
				AsiaPcieModify32(DramAttr->PcieBaseAddress, Address, D0F2_RDVAD1ITLVB_1_0, BIT4|BIT3);
				break;
			default:
				AsiaPcieModify32(DramAttr->PcieBaseAddress, Address, D0F2_RDVAD1ITLVB_1_0, BIT3);
				break;
		}		
		//Enable DVAD 1   
		AsiaPcieModify32(DramAttr->PcieBaseAddress, Address, D0F2_RDVAD1NXM, 0);
		PEI_DEBUG((PeiServices, EFI_D_ERROR, "Slave DVAD Entry 1 Base = %08x\r\n", (UINT32)DvadBase));
		PEI_DEBUG((PeiServices, EFI_D_ERROR, "Slave DVAD Entry 1 Limit = %08x\r\n", (UINT32)DvadLimit));
		//Slave DVAD Entry 2	 
		Address = AsiaPciAddress(SlaveBusNum, CHX002_HB_DEV, CHX002_HIF_FUN, D0F2_DVAD_ENTRY_2);
		//Base = DVA end of Entry1 - SVA end of Entry1 = (RTopA-LowTopA-4G)/2 - entry 0 limit
		DvadBase = ((RTopA-LowTopA-0x1000)/2) - (DvadLimit+1); //for NO interleave mode 
		DvadBase &= 0x1FFFFF;  
		AsiaPcieModify32(DramAttr->PcieBaseAddress, Address, D0F2_RDVAD2BASE_40_27, (DvadBase >> 7) << 6);
		DvadLimit = RTopA - 1;  // unit of MB,  DvadLimit = (DvadLimit >> 8)<<20
		AsiaPcieModify32(DramAttr->PcieBaseAddress, Address, D0F2_RDVAD2LIMIT_39_28, (DvadLimit >> 8) << 20);
		//NO interleave   
		AsiaPcieModify32(DramAttr->PcieBaseAddress, Address, D0F2_RDVAD2ITLVB_1_0, 0);
		//Enable DVAD 2   
		AsiaPcieModify32(DramAttr->PcieBaseAddress, Address, D0F2_RDVAD2NXM, 0);
		PEI_DEBUG((PeiServices, EFI_D_ERROR, "Slave DVAD Entry 2 Base = %08x\r\n", (UINT32)DvadBase));
		PEI_DEBUG((PeiServices, EFI_D_ERROR, "Slave DVAD Entry 2 Limit = %08x\r\n", (UINT32)DvadLimit));
	}

	for(i=D0F2_DVAD_ENTRY_3;i<=D0F2_DVAD_ENTRY_7;i+=4) {
		Address = AsiaPciAddress(SlaveBusNum, CHX002_HB_DEV, CHX002_HIF_FUN, i);
		//Disable DVAD 3~7   
		AsiaPcieModify32(DramAttr->PcieBaseAddress, Address, D0F2_RDVAD3NXM, 1);
	}	
}

VOID UpdateDVAD(
    IN EFI_PEI_SERVICES **PeiServices,
	IN DRAM_ATTRIBUTE *DramAttr)
{
   UINT32 LowTopA;  //unit of  M
   UINT32 RTopA;    //uinit of M
   UINT64 Address;
   UINT32 MasterMemSize;

   //get Pci Start address (MB)
   Address = AsiaPciAddress(CHX002_HB_BUS, CHX002_HB_DEV, CHX002_HIF_FUN, D0F2_BELOW_4G_HIGHEST_MEM_LIMIT_DRAM_LIMIT_ADR_BELOW_4G);
   LowTopA = AsiaPcieRead16(DramAttr->PcieBaseAddress, Address);
   LowTopA = (LowTopA & 0xFFF0) >> 4;
   //get RTOPA (MB)
   Address = AsiaPciAddress(CHX002_HB_BUS, CHX002_HB_DEV, CHX002_HIF_FUN, D0F2_HIGHEST_SVAD_LIMIT_TARGET_TO_MEM_DRAM_LIMIT_ADR_OVER_4G);
   RTopA = AsiaPcieRead32(DramAttr->PcieBaseAddress, Address);
   RTopA = (RTopA & 0xFFFFF000) >> 12;

	//If Master phyasical memory size = Slave
	MasterMemSize = (RTopA - (0x1000-LowTopA))/2;
		
	if(DramAttr->ConfigData.SpecialConf == 1) {
		Config1Dvad(LowTopA,RTopA,DramAttr->ConfigData.ZxeSlaveBusNum,DramAttr->PcieBaseAddress);
		return ;
	}
		
	UpdateMasterDVAD(PeiServices,LowTopA,RTopA,MasterMemSize,DramAttr);
    UpdateSlaveDVAD(PeiServices,LowTopA,RTopA,DramAttr);

	return;
}


