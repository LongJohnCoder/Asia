/** @file
   ZX-E(CHX002) Asia NbPei library functions : PciHotPlug.c

   Copyright (c) 2018 Shanghai Zhaoxin Semiconductor Co., Ltd. 

**/

#include "Pei.h"
#include "CHX002Reg.h"
#include "CHX002Cfg.h"
#include "AsiaCommon.h"
#include "AsiaIoLib.h"
#include "AsiaNbPeim.h"
#include "PeiLib.h"
#include "SbLibPpi.h"
#include "PciHotPlug.h"           //JNY PCIE-IOE Hotplug debug

#include EFI_PPI_CONSUMER(Smbus)  //JNY PCIE-IOE Hotplug debug


typedef union {
    UINT8       Port0;
    struct  {
        BOOLEAN   AUXON  : 1;
        BOOLEAN   AttButton  : 1;
        BOOLEAN   Pres_DET  : 1;
        BOOLEAN   CtrlON  : 1;
        BOOLEAN   Fault  : 1;
        BOOLEAN   GPIO5  : 1;
        BOOLEAN   CtrlLED3  : 1;
        BOOLEAN   CtrlPcieClkEn  : 1;
    } P0;
} HX001HP_P0;

typedef union {
    UINT8       Port1;
    struct {
        BOOLEAN   CtrlPcieRst : 1;
        BOOLEAN   Ctrl1LED2   : 1;
        BOOLEAN   Ctrl2LED2   : 1;
        UINT8     Rsv         : 5;
    } P1;
} HX001HP_P1;


/**
   Pcie HotPlug init function.
   Do pcie hotplug external card init by smbus ppi.
   
  @param  PeiServices	EFI_PEI_SERVICES pointer.

  @return The value from this function.

**/

EFI_STATUS 
PcieHotPlugInit (
  IN EFI_PEI_SERVICES  **PeiServices
	)
{
	EFI_STATUS						      Status;
	PEI_SMBUS_PPI 					*pSMBusPPI=NULL;
	EFI_GUID 						SMBusGUID = PEI_SMBUS_PPI_GUID;
	EFI_SMBUS_DEVICE_ADDRESS		SlaveAddress;
	UINTN							          SMBDataLength;
	UINT8							          SMBData;

	volatile HX001HP_P0         HP_P0;
	volatile HX001HP_P1         HP_P1;
 // JNY PCIE-IOE Hotplug debug-s
 // ASSERT(sizeof(HX001HP_P0) == 1);
 // ASSERT(sizeof(HX001HP_P1) == 1);  
	Status = (*PeiServices)->LocatePpi(PeiServices, &SMBusGUID, 0, NULL, &pSMBusPPI);
    ASSERT_PEI_ERROR(PeiServices, Status);

	SlaveAddress.SmbusDeviceAddress = PcieHotPlugSMBusAddr;
	SMBDataLength = 0x01;
	if(pSMBusPPI==NULL)
	{
		
		PEI_DEBUG((PeiServices,EFI_D_INFO, "[JNY]:SMbus PPI load error!!!"));
	}
	// Set IO expander cfg
	SMBData = 0;
	Status = pSMBusPPI->Execute (
                      PeiServices, 
                      pSMBusPPI, 
                      SlaveAddress, 
                      Pcal6416_CfgPort0, 
                      EfiSmbusReadByte, 
                      FALSE, 
                      &SMBDataLength, 
                      &SMBData
                      );
	if(Status!=EFI_SUCCESS)
	{
		
		PEI_DEBUG((PeiServices,EFI_D_INFO, "[JNY]:SMbus read data error!!!"));
		
		PEI_DEBUG((PeiServices,EFI_D_INFO, "[JNY]Status= %02x",Status));
	}
	//JNY PCIE-IOE Hotplug debug-e
	PEI_DEBUG((PeiServices,EFI_D_INFO, "[PCAL6416] [%X] = %X\n", Pcal6416_CfgPort0, SMBData));

	HP_P0.Port0            = SMBData;
	HP_P0.P0.AUXON         = Pcal6416_GPIO_DirOut;
	HP_P0.P0.AttButton     = Pcal6416_GPIO_DirIn;
	HP_P0.P0.Pres_DET      = Pcal6416_GPIO_DirIn;
	HP_P0.P0.CtrlON        = Pcal6416_GPIO_DirOut;
	HP_P0.P0.Fault         = Pcal6416_GPIO_DirIn;
	HP_P0.P0.CtrlLED3      = Pcal6416_GPIO_DirOut;
	HP_P0.P0.CtrlPcieClkEn = Pcal6416_GPIO_DirOut;
	SMBData = HP_P0.Port0;
	Status = pSMBusPPI->Execute(
                        PeiServices, 
                        pSMBusPPI, 
                        SlaveAddress, 
                        Pcal6416_CfgPort0, 
                        EfiSmbusWriteByte, 
                        FALSE, 
                        &SMBDataLength, 
                        &SMBData
                        );
	PEI_DEBUG((PeiServices,EFI_D_INFO, "[PCAL6416] [%X] = %X\n", Pcal6416_CfgPort0, SMBData));
	
	SMBData = 0;
	Status = pSMBusPPI->Execute(
                        PeiServices, 
                        pSMBusPPI, 
                        SlaveAddress, 
                        Pcal6416_CfgPort1, 
                        EfiSmbusReadByte, 
                        FALSE, 
                        &SMBDataLength, 
                        &SMBData
                        );
   PEI_DEBUG((PeiServices,EFI_D_INFO, "[PCAL6416] [%X] = %X\n", Pcal6416_CfgPort1, SMBData));
	HP_P1.Port1 = SMBData;
	HP_P1.P1.CtrlPcieRst = Pcal6416_GPIO_DirOut;
	HP_P1.P1.Ctrl1LED2   = Pcal6416_GPIO_DirOut;
	HP_P1.P1.Ctrl2LED2   = Pcal6416_GPIO_DirOut;
	SMBData = HP_P1.Port1;
	Status = pSMBusPPI->Execute(
                        PeiServices, 
                        pSMBusPPI, 
                        SlaveAddress, 
                        Pcal6416_CfgPort1, 
                        EfiSmbusWriteByte, 
                        FALSE, 
                        &SMBDataLength, 
                        &SMBData
                        );
   PEI_DEBUG((PeiServices,EFI_D_INFO,"[PCAL6416] [%X] = %X\n", Pcal6416_CfgPort1, SMBData));

	SMBData = 0x02;
	Status = pSMBusPPI->Execute(
                        PeiServices, 
                        pSMBusPPI, 
                        SlaveAddress, 
                        Pcal6416_InputLatchReg0, 
                        EfiSmbusWriteByte, 
                        FALSE, 
                        &SMBDataLength, 
                        &SMBData
                        );

	SMBData = 0;
	Status = pSMBusPPI->Execute(
                        PeiServices, 
                        pSMBusPPI, 
                        SlaveAddress, 
                        Pcal6416_InputPort0, 
                        EfiSmbusReadByte, 
                        FALSE, 
                        &SMBDataLength, 
                        &SMBData
                        );
	PEI_DEBUG((PeiServices,EFI_D_INFO,"[PCAL6416] [%X] = %X\n", Pcal6416_InputPort0, SMBData));

	HP_P0.Port0 = SMBData;

	if( HP_P0.P0.Pres_DET == 0 ){
		HP_P0.P0.AUXON = 1;
		HP_P0.P0.CtrlON  =1;
		HP_P0.P0.CtrlLED3  = 0;
		HP_P0.P0.CtrlPcieClkEn = 1;
    
		HP_P1.P1.CtrlPcieRst  = 1;
		HP_P1.P1.Ctrl1LED2  = 1;   //jennychen path for IOE hot plug
		HP_P1.P1.Ctrl2LED2  = 1;
   PEI_DEBUG((PeiServices,EFI_D_INFO, "Card Present!\n"));
	}	else {
		HP_P0.P0.AUXON = 0;
		HP_P0.P0.CtrlON  =0;
		HP_P0.P0.CtrlLED3  = 1;
		HP_P0.P0.CtrlPcieClkEn  = 0;
		HP_P1.P1.CtrlPcieRst  = 0;
		HP_P1.P1.Ctrl1LED2  = 1;
		HP_P1.P1.Ctrl2LED2  = 0;
  PEI_DEBUG((PeiServices,EFI_D_INFO,"Card Not Present!\n"));
	}

	SMBData = HP_P0.Port0;
	Status = pSMBusPPI->Execute(
                        PeiServices, 
                        pSMBusPPI, 
                        SlaveAddress, 
                        Pcal6416_OutputPort0, 
                        EfiSmbusWriteByte, 
                        FALSE, 
                        &SMBDataLength, 
                        &SMBData
                        );
   PEI_DEBUG((PeiServices,EFI_D_INFO,"[PCAL6416] [%X] = %X\n", Pcal6416_OutputPort0, SMBData));

	SMBData = HP_P1.Port1;
	Status = pSMBusPPI->Execute(
                        PeiServices, 
                        pSMBusPPI, 
                        SlaveAddress, 
                        Pcal6416_OutputPort1, 
                        EfiSmbusWriteByte, 
                        FALSE, 
                        &SMBDataLength, 
                        &SMBData
                        );
  PEI_DEBUG((PeiServices,EFI_D_INFO,"[PCAL6416] [%X] = %X\n", Pcal6416_OutputPort1, SMBData));

	if( HP_P0.P0.Pres_DET == 0 ){
		SMBData = 0xED;
	} else {
		SMBData = 0xEB;
	}
	Status = pSMBusPPI->Execute(
                        PeiServices, 
                        pSMBusPPI, 
                        SlaveAddress, 
                        Pcal6416_IntMaskReg0, 
                        EfiSmbusWriteByte, 
                        FALSE, 
                        &SMBDataLength, 
                        &SMBData
                        );

	return EFI_SUCCESS;
}


