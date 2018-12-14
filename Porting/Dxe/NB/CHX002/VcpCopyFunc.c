/** @file
   ZX-E(CHX002) Asia NbDxe library functions : VcpCopyFunc.c

   Copyright (c) 2018 Shanghai Zhaoxin Semiconductor Co., Ltd. 

**/

//**********************************************************************
//**********************************************************************
//**                                                                  **
//**     Copyright (c) 2015 Shanghai Zhaoxin Semiconductor Co., Ltd.  **
//**                                                                  **
//**********************************************************************
//**********************************************************************
///
#include "EfiCommon.h"
#include "AsiaNbDxe.h"
#include "CHX002Cfg.h"
#include "CHX002Reg.h"
#include "EfiDriverLib.h"
#include "CpuIa32.h"
#include "AsiaIoLib.h"

/**
  Function description.
  
  @param NbCfg Point to ASIA_NB_CONFIGURATION struct.

  @return EFI_STATUS.

**/

static VOID EFIAPI
VcpCopy(ASIA_NB_CONFIGURATION *NbCfg)
{
	VOID *VcpFileBuffer = (VOID*)(UINTN)(NbCfg->VcpFileBaseAddr);
	UINT16 VcpFileSize = NbCfg->VcpFileSize;
    EFI_STATUS Status;
    EFI_PCI_ROOT_BRIDGE_IO_PROTOCOL *PciRootBridgeIo;
    UINT32 UMABar14, FBTopAddress, RegVal, FBSize;
    //UINT16 FBSize;
    UINTN DestAddress;
    EFI_PHYSICAL_ADDRESS PhysicalAddress, PciAddress;

    if( NULL == VcpFileBuffer || 0 == VcpFileSize )
    {
		return;
    }

    Status = gBS->LocateProtocol(&gEfiPciRootBridgeIoProtocolGuid, NULL, &PciRootBridgeIo);
    ASSERT_EFI_ERROR(Status);
     
    //Get FBTopAddress
    Status = PciRootBridgeIo->Pci.Read(PciRootBridgeIo, EfiPciWidthUint32, 
                        CHX002_EUMA|0x14, 1, &UMABar14);
    ASSERT_EFI_ERROR(Status);
	
	UMABar14 = UMABar14&0xfffffff0;
    DEBUG((EFI_D_ERROR, " UMABar14 = %x\n",UMABar14));

    //Get FBSize
	PciAddress = AsiaPciAddress(CHX002_HB_BUS, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_CPU_DIRECT_ACCESS_FRAME_BUFFER_CTL_Z1); 
	RegVal = AsiaPcieRead32(((ASIA_NB_CONFIGURATION *)(NbCfg))->PcieBar, PciAddress);

	DEBUG((EFI_D_ERROR, "D0F3_CPU_DIRECT_ACCESS_FRAME_BUFFER_CTL_Z1 = %x\n",RegVal));

    if ((RegVal & D0F3_RGFXEN) != D0F3_RGFXEN)
    {
        FBSize = 0;
    }
    else
    {
    	RegVal = (RegVal & D0F3_RFBSZ_2_0)>>4;
		if (RegVal > 0x4)
			FBSize = 1 << ((RegVal&0x3) + 2); //in unit of M
		else
			FBSize = 1 << (RegVal + 5); //in unit of M
    }
	
    DEBUG((EFI_D_ERROR, " FBSize = %x\n",FBSize));
    FBTopAddress = UMABar14 + (FBSize * 0x100000);
    DEBUG((EFI_D_ERROR, " FBTopAddress = %x\n",FBTopAddress));
	
    //Copy VCP data to TOPMEM-128K space
    PhysicalAddress = (FBTopAddress-(0x20000))&0xffffffff;
    DEBUG((EFI_D_ERROR, " PhysicalAddress = %x\n",PhysicalAddress));
    DestAddress = (UINTN) PhysicalAddress;   
    DEBUG((EFI_D_ERROR, "DestAddress = %x\n",DestAddress)); 

    // do copy operation. 
    DEBUG((EFI_D_ERROR, " VcpFileBuffer = %x,VcpFileSize = %x\n",VcpFileBuffer,VcpFileSize));
    EfiCopyMem ((VOID*)DestAddress, VcpFileBuffer, VcpFileSize);
    
    // Flush data from cache to DRAM
    EfiWbinvd();
    
    gBS->FreePool(VcpFileBuffer);
    VcpFileBuffer = NULL;
}

///
