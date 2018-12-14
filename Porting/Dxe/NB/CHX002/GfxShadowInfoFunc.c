/** @file
   ZX-E(CHX002) Asia NbDxe library functions : GfxShadowInfoFunc.c

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
#include "AsiaNbDxe.h"
#include "CHX002Cfg.h"
#include "CHX002Reg.h"
#include "EfiDriverLib.h"
#include "CpuIa32.h"
#include "AsiaIoLib.h"

#pragma pack(push)
#pragma pack(1)
typedef struct _SysBIOSInfo
{
	//Header
	UINT8	Version;			// System shadow info version
	UINT8	Reserved0;			// Must be 0x00
	UINT8	Length;				// Total size of system BIOS info, including header
	UINT8	CheckSum;			// Checksum of whole system BIOS info including header
	//	
	UINT32	Reserved1;			
	UINT32	Reserved2;
	UINT32	Reserved3;
	UINT8	Reserved4;
	UINT8	FBSize;				// Bit[7:4]:reserved, 
								// Bit[3:0]: N: Frame Buffer Size = 2^N MB
	UINT8	MCLK;				// DRAM Data Rate
	UINT8	DRAMMode;			// Bit[1]: 0-Interleave, 1-Non-Interleave
								// Bit[0]: 0-Single Channel, 1-Dual Channel, Other bits are reserved
	UINT32	Reserved5;
	UINT32	Reserved6;
	UINT32	Reserved7;
	UINT8	Reserved8;
	UINT8	Reserved9;
	UINT16	SSCCtrl;			// SSC settings control
	UINT16	ChipCapability;		// Bit[0]:0-Package A, 1-Package B
	UINT16	LowTopAddress;		// LowTop Address for memory remapping
	UINT32	Reserved10;
	UINT32	Reserved11;
	UINT32	BootUpDev;			// Display port type setting
	UINT32	DetailedBootUpDev;	// Detailed Boot-up Devics
	UINT32	FeatureSwitch;		// software feature switch bits
	UINT32	ECLK;				// ECLK frequency in MHz
	UINT32	VCLK;				// VCLK frequency in MHz
	UINT32	ICLK;				// ICLK frequency in MHz
} SysBIOSInfo;
#pragma pack(pop)

/**
  Function description.
  
  @param  PeiServices	EFI_PEI_SERVICES pointer.
  @param NbCfg Point to ASIA_NB_CONFIGURATION struct.

  @return EFI_STATUS.

**/
static VOID Asia_BootDeviceSet(
	IN UINT8	DP1,
	IN UINT8	DP2,
	IN UINT8	DVO,
	IN UINT8	CRT,
	OUT UINT32	*BootUpDev,
	OUT UINT32	*DetailedBootUpDev
)
{
	//UINT8 DisDev, i = 0;
	UINT32 tmpBootUpDev = (UINT32) 0;
	UINT32 tmpDetailedBootUpDev = (UINT32) 0;
	

	if(DP1)
		tmpBootUpDev |= 0X8000;
	if(DP2)
		tmpBootUpDev |= 0X0200;
	if(DVO)
		tmpBootUpDev |= 0X0020;
	if(CRT)
			tmpBootUpDev |= 0x0001;
	
	tmpDetailedBootUpDev = (DP2<<16)|(DP1<<8)|DVO;

	*DetailedBootUpDev = tmpDetailedBootUpDev;
	*BootUpDev = tmpBootUpDev;
}

/**
  Function description.
  
  @param  PeiServices	EFI_PEI_SERVICES pointer.
  @param NbCfg Point to ASIA_NB_CONFIGURATION struct.

  @return EFI_STATUS.

**/
static VOID EFIAPI
GfxShadowInfo(ASIA_NB_CONFIGURATION *NbCfg)
{
	EFI_STATUS					Status = EFI_SUCCESS;
	SysBIOSInfo					SystemBiosInfo;
	UINT32						MemBar, UMABar14, CpuDirectAccessFB, UMASize;
	UINT32						FBSizeTmp=0;
	UINT8						MCLK=0;
	UINT32						TempData=0;
	UINT8						DRAMMode=0;
	UINT8						DRAMInfo=0;
	UINT16						SSCCtrl=0;
	UINT16						LowTopAddress=0;
	UINT32						BootUpDev=0, DetailedBootUpDev=0;
	UINT32						FeatureSwitch=0;
	UINT32						ECLK=0, VCLK=0, ICLK=0;
	UINT8						i, Sum=0;
	UINTN						CountN=0;
	UINT64						Data64=0, PciAddress;
	UINT32						DestAddr=0;
	//for Dump
	UINT8    Data;
	UINT16	Index1, Index2;
	UINT16	TempRegVal=0;
	
	EFI_PCI_ROOT_BRIDGE_IO_PROTOCOL *PciRootBridgeIo;


	Status = gBS->LocateProtocol( &gEfiPciRootBridgeIoProtocolGuid, NULL, &PciRootBridgeIo);
	ASSERT_EFI_ERROR(Status);

	PciAddress = AsiaPciAddress(CHX002_HB_BUS, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_CPU_DIRECT_ACCESS_FRAME_BUFFER_CTL_Z1); 
	CpuDirectAccessFB = AsiaPcieRead32(((ASIA_NB_CONFIGURATION *)(NbCfg))->PcieBar, PciAddress);
	DEBUG((EFI_D_ERROR,"Program GfxShadowInfo:CpuDirectAccessFB = 0x%X\n",CpuDirectAccessFB));
	//DEBUG((-1,"SW feature switch = 0x%X\n",SW_feature_switch));

	//Get FBTopAddress
	Status = PciRootBridgeIo->Pci.Read(PciRootBridgeIo, EfiPciWidthUint32, 
										CHX002_EUMA|0x14, 1, &MemBar);
	ASSERT_EFI_ERROR(Status);
	UMABar14 = (MemBar&0xfffffff0);
	DEBUG((EFI_D_ERROR,"Program GfxShadowInfo:UMABar14 = 0x%X\n",UMABar14));
	
	//Get FBSize
    if ((CpuDirectAccessFB & D0F3_RGFXEN) != D0F3_RGFXEN)
    {
        UMASize = 0;
		FBSizeTmp = 0;//for ShadowInfo report
    }
    else
    {
    	FBSizeTmp = (CpuDirectAccessFB & D0F3_RFBSZ_2_0)>>4;
		if (FBSizeTmp > 0x4)
			FBSizeTmp = ((FBSizeTmp&0x3) + 2); //UMAsize = 2^FBSizeTmp (MB)
		else
			FBSizeTmp = (FBSizeTmp + 5); //UMAsize = 2^FBSizeTmp (MB)

		UMASize = 1 << FBSizeTmp; //in unit of M
    }
	
	
	//copy structure to FBTopAddress-64K space
	DestAddr=UMABar14+(UMASize*0x100000)-0x10000;

	//Get MCLK
		//TODO RKD remove for pxp code parpare
	PciAddress = AsiaPciAddress(CHX002_HB_BUS, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_PLLINDDR_CTL_Z1); 
	TempRegVal = AsiaPcieRead16(((ASIA_NB_CONFIGURATION *)(NbCfg))->PcieBar, PciAddress);
	DEBUG((EFI_D_ERROR,"Program GfxShadowInfo:D0F3_PLLINDDR_CTL_Z1 = 0x%X\n",TempRegVal));

		//TODO RKD remove for pxp code parpare
	TempData = TempRegVal & D0F3_RDIV_M_PLLINDDR_7_0;
	TempData >>= 8;

	if (TempData < 6)//800
		TempData = 0x09;
	else if (TempData < 8 )//1066
		TempData = 0x0A;
	else if (TempData < 10 )//1333
		TempData = 0x0B;
	else if (TempData < 12 )//1600
		TempData = 0x0C;
	else if (TempData < 14 )//1866
		TempData = 0x0D;
	else if (TempData < 16 )//2133
		TempData = 0x0E;
	// else if (TempData < 18)//2400
	// 	TempData =     ;
	// else if (TempData < 20)//2666
	// 	TempData =     ;
	// else if (TempData < 22)//2933
	// 	TempData =     ;
	else					 //2400   //3200
		TempData = 0x0F;

	TempData <<= 4;	
	MCLK = (UINT8) TempData;
	TempData = 0;//clear

	//Get DRAM Mode
	Status = PciRootBridgeIo->Pci.Read( PciRootBridgeIo, EfiPciWidthUint8,
								CHX002_SCRCH | (D0F6_BIOS_SCRATCH_REG_4+3),
								1, &DRAMInfo);
	DEBUG((EFI_D_ERROR,"Program GfxShadowInfo:D0F6_BIOS_SCRATCH_REG_4F = 0x%X\n",DRAMInfo));
	
	DRAMMode = DRAMInfo & 0x03;


	//Get SSCCtrl
	//For DP1
	//DP1 SSC enable/disable
	TempData = (UINT32) NbCfg->DP1SSCEn;
	TempData &= 0x01;
	SSCCtrl |= TempData;
	//DP1 Spreading Range
	TempData = (UINT32) NbCfg->DP1SSCMode;
	TempData &= 0x03;
	SSCCtrl |= TempData << 1;

	//For DP2
	//DP2 SSC enable/disable
	TempData = (UINT32) NbCfg->DP2SSCEn;
	TempData &= 0x01;
	SSCCtrl |= TempData << 8;
	//DP2 Spreading Range
	TempData = (UINT32) NbCfg->DP2SSCMode;
	TempData &= 0x03;
	SSCCtrl |= TempData << 9;


	//Get LowTopAddress
	Status = PciRootBridgeIo->Pci.Read(PciRootBridgeIo, EfiPciWidthUint16,
						CHX002_HIF|D0F2_BELOW_4G_HIGHEST_MEM_LIMIT_DRAM_LIMIT_ADR_BELOW_4G, 1, &LowTopAddress);
	ASSERT_EFI_ERROR(Status);
	
	LowTopAddress &= D0F2_RLOWTOPA_31_20;
	DEBUG((EFI_D_ERROR,"Program GfxShadowInfo:LowTopAddress = 0x%X\n",LowTopAddress));


	//Get BootUpDev, DetailedBootUpDev
	//If selectDisplaydevice is "Manual"
	if(NbCfg->SelectDisplayDevice != 0)
	{
		Asia_BootDeviceSet(NbCfg->DP1, NbCfg->DP2,NbCfg->DVO, NbCfg->CRT, &BootUpDev, &DetailedBootUpDev);
	}else
	{
		//If selectDisplaydevice is "AUTO"
		BootUpDev = 0;
		DetailedBootUpDev = 0;
	}


	//Get SW Feature Switch
	FeatureSwitch = (DRAMInfo & 0x04) >> 2;


	//Get ECLK(EngineClockModify), VCLK, ICLK
	if(NbCfg->ECLKCtrl)
	ECLK = (UINT16) NbCfg->ECLKFreq;
	else
		ECLK = (UINT16) 0x0;
	
	if(NbCfg->VCLKCtrl)
	VCLK = (UINT16) NbCfg->VCLKFreq;
	else
		VCLK = (UINT16) 0x0;

	if(NbCfg->ICLKCtrl)
	ICLK = (UINT16) NbCfg->ICLKFreq;
	else
		ICLK = (UINT16) 0x0;

	
	SystemBiosInfo.Version = 0x10;
	SystemBiosInfo.Reserved0 = 0;
	SystemBiosInfo.Length = sizeof(SysBIOSInfo);
	SystemBiosInfo.CheckSum = 0;
	SystemBiosInfo.Reserved1 = 0;
	SystemBiosInfo.Reserved2 = 0;
	SystemBiosInfo.Reserved3 = 0;
	SystemBiosInfo.Reserved4 = 0;
	SystemBiosInfo.FBSize = (UINT8)FBSizeTmp;
	SystemBiosInfo.MCLK = MCLK;
	SystemBiosInfo.DRAMMode = DRAMMode;
	SystemBiosInfo.Reserved5 = 0;
	SystemBiosInfo.Reserved6 = 0;
	SystemBiosInfo.Reserved7 = 0;
	SystemBiosInfo.Reserved8 = 0;
	SystemBiosInfo.Reserved9 = 0;
	SystemBiosInfo.SSCCtrl = SSCCtrl;
	SystemBiosInfo.ChipCapability = 0;
	SystemBiosInfo.LowTopAddress = LowTopAddress;
	SystemBiosInfo.Reserved10 = 0;
	SystemBiosInfo.Reserved11 = 0;
	SystemBiosInfo.BootUpDev = BootUpDev;
	SystemBiosInfo.DetailedBootUpDev = DetailedBootUpDev;
	SystemBiosInfo.FeatureSwitch = FeatureSwitch;
	SystemBiosInfo.ECLK = ECLK;
	SystemBiosInfo.VCLK = VCLK;
	SystemBiosInfo.ICLK = ICLK;
	
	//calulate CheckSum
	for (i=0 ; i < sizeof(SysBIOSInfo) ; i++)
		Sum += *(((UINT8*)&SystemBiosInfo)+i);
	
	SystemBiosInfo.CheckSum = ~Sum + 1;
	
	//Copy SystemBiosInfo to DestAddr
	CountN=(UINTN)sizeof(SysBIOSInfo);
	Data64=(UINT64)(VOID *)&SystemBiosInfo;

    Status = PciRootBridgeIo->CopyMem(PciRootBridgeIo, EfiPciWidthUint8,
        DestAddr, Data64, CountN );

	//dump
	DEBUG((EFI_D_ERROR,"Dump Gfx Shadow Info:\n"));
	DEBUG((EFI_D_ERROR,"DestAddr = %08x\r\n",DestAddr));
	DEBUG((EFI_D_ERROR,"    00 01 02 03 04 05 06 07 08 09 0A 0B 0C 0D 0E 0F\n"));
	DEBUG((EFI_D_ERROR,"---+-----------------------------------------------\n"));
	for(Index1=0;Index1<0x20;Index1++)
	{
		DEBUG((EFI_D_ERROR,"%08x|", Index1*16 + DestAddr));
		for(Index2=0;Index2<0x10;Index2++)
		{
			//Address = AsiaPciAddress(BusNo, DevNo, FunNo, Index1*16 + Index2 + RegBegin);
			//Data = AsiaPcieRead8(0xE0000000, Address);
			Data = AsiaMemoryRead8(Index1*16 + Index2 + DestAddr);
			DEBUG((EFI_D_ERROR,"%02x ", Data));
			if(Index2==0x0F)
				DEBUG((EFI_D_ERROR,"\n"));
		}
		if((Index1%0x10)==0x0F)
			DEBUG((EFI_D_ERROR,"---------------------------------------------------\n"));
	}
	DEBUG((EFI_D_ERROR,"\n"));

}