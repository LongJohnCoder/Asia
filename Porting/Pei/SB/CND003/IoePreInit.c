/** @file
   ZX-E(CHX002) Asia SbPei library functions : IoePreInit.c

   Copyright (c) 2018 Shanghai Zhaoxin Semiconductor Co., Ltd. 

**/

//**************************************************************************
//**************************************************************************
//**                                                                      **
//**  Copyright (c) 2015 - 2017 Shanghai Zhaoxin Semiconductor Co., Ltd.  **
//**                                                                      **
//**************************************************************************
//**************************************************************************

//CJW-20160613_01	Change the HardCode-1
//CJW-20160618_01	Create the file and add some base code
//CJW-20160905_01   Update the resource assigment strategy for all previous codes

#include "Pei.h"
#include "CHX002Reg.h"
#include "CHX002Cfg.h"
#include "AsiaCommon.h"
#include "IoePreInit.h"
#include "AsiaIoLib.h"

#include EFI_PPI_DEFINITION(AsiaSbPpi)
#include "AsiaSbPeim.h"
#include "SbLibPpi.h"
#include "SbDriving.h"


#include "SIPcieDriving.h"


#include "PeiApi.h"

#include "CND003Reg.h"

#include "IoeConfig.h"
#include "IoeSIPcieDriving.h"
#include "IoeDebugSignal.h"


//#include "AsiaPlatform.h"
#include EFI_PPI_DEFINITION (Smbus)


//List all possible PCIE port for insert IOE
//Will search IOE follow the order in this struct!
SEARCH_TBL IoeSearchTbl[] = IOE_SEARCH_TABLE;


/**
   IoePeiPort80

   
  @param  PeiServices	EFI_PEI_SERVICES pointer.
  @param Cmd

  @return VOID.

**/

STATIC
VOID
IoePeiPort80(IN EFI_PEI_SERVICES **PeiServices,UINT8 Cmd)
{
	UINT32 temp32;
	PEI_DEBUG((PeiServices, EFI_D_ERROR, "[CJW_IOE] Port 80\n"));	
	switch(Cmd){
	//This 80 Port can only called after temp bus assigment
	case 0x22:
		temp32 = AsiaPciRead32(HOST_SCRATCH|HOST_D0F6_BIOS_SCRATCH_REG_2);
		if(!(temp32 & BIT24)){
			AsiaIoWrite8(0x80, 0x22);
			PEI_DEBUG((PeiServices, EFI_D_ERROR, "          NOT FOUND IOE\n"));
			while(1);
		}
	break;
	default:
	break;
	}

}


/**
   IoeDumpMem.
   
  @param  PeiServices	EFI_PEI_SERVICES pointer.
  @param MemBase
  @param DCount

  @return VOID.

**/

VOID
IoeDumpMem(
	IN EFI_PEI_SERVICES **PeiServices, 
	UINT32 MemBase, 
	UINT16 DCount)
{

	UINT16 offsetx = 0;
	UINT8 readback8;
	PEI_DEBUG((PeiServices, EFI_D_ERROR, "[CJW_IOE] IoeDumpMem(Base:0x%08x, Count:0x%04x):\n",MemBase, DCount));
	PEI_DEBUG((PeiServices, EFI_D_ERROR, "\n0x%04x: ",offsetx+1));
	for(offsetx = 0; offsetx < DCount; offsetx++){
		readback8 = AsiaMemoryRead8(MemBase + offsetx);
		PEI_DEBUG((PeiServices, EFI_D_ERROR, "%02X ",readback8));
		if(offsetx != (DCount -1)){
			if((offsetx & 0xFF) == 0xFF){
				PEI_DEBUG((PeiServices, EFI_D_ERROR, "\n\n        00 01 02 03 04 05 06 07 08 09 0A 0B 0C 0D 0E 0F"));
				PEI_DEBUG((PeiServices, EFI_D_ERROR, "\n        -----------------------------------------------"));
			}
		}	
		if((offsetx & 0xF) == 0xF){
			PEI_DEBUG((PeiServices, EFI_D_ERROR, "\n0x%04x: ",offsetx+1));
		}
		
	}
	PEI_DEBUG((PeiServices, EFI_D_ERROR, "\n"));
}

/**
   IoeDumpCfg.
   
  @param  PeiServices	EFI_PEI_SERVICES pointer.
  @param PcieBase
  @param Busx
  @param Devx
  @param Funx
  @param DCount

  @return VOID.

**/

VOID
IoeDumpCfg(
	IN EFI_PEI_SERVICES **PeiServices,
	UINT64 PcieBase,
	UINT8 Busx,
	UINT8 Devx, 
	UINT8 Funx, 
	UINT16 DCount)
{

	UINT16 offsetx = 0;
	UINT8 readback8;
	PEI_DEBUG((PeiServices, EFI_D_ERROR, "[CJW_IOE] IoeDumpCfg([%d|%d|%d] Count:0x%08x):\n",Busx,Devx,Funx,DCount));
	PEI_DEBUG((PeiServices, EFI_D_ERROR, "\n0x%04x: ",offsetx+1));
	for(offsetx = 0; offsetx < DCount; offsetx++){
		readback8 = AsiaPcieRead8(PcieBase, AsiaPciAddress(Busx, Devx, Funx, offsetx));
		PEI_DEBUG((PeiServices, EFI_D_ERROR, "%02X ",readback8));
		if(offsetx != (DCount -1)){
			if((offsetx & 0xFF) == 0xFF){
				PEI_DEBUG((PeiServices, EFI_D_ERROR, "\n\n        00 01 02 03 04 05 06 07 08 09 0A 0B 0C 0D 0E 0F"));
				PEI_DEBUG((PeiServices, EFI_D_ERROR, "\n        -----------------------------------------------"));
			}
		}
		if((offsetx & 0xF) == 0xF){
			PEI_DEBUG((PeiServices, EFI_D_ERROR, "\n0x%04x: ",offsetx+1));
		}
		
	}
	PEI_DEBUG((PeiServices, EFI_D_ERROR, "\n"));
}

/**************************************************************************
// Local Library
**************************************************************************/
/**
   IoeShiftToMaskBit.

   
  @param  MaskBit
  @param ShiftData

  @return UINT16.
 
**/

UINT16 IoeShiftToMaskBit(
    IN UINT16 MaskBit,
    IN UINT16 ShiftData)
{
    UINT16				bValue, bIndex, bBuffer=0;

    for (bIndex=0; bIndex<16; bIndex++)
    {
        bBuffer = MaskBit;
        if ((bBuffer >> bIndex) & 0x01)
            break;
    }
    bValue = ShiftData << bIndex;
    return bValue;
}

/**
   PeiNbPcieStallx.
   
  @param  PeiServices	EFI_PEI_SERVICES pointer.
  @param Millisecond

  @return EFI_STATUS.

**/

STATIC
EFI_STATUS
PeiNbPcieStallx (
    IN EFI_PEI_SERVICES **PeiServices,
    IN UINTN Millisecond
)
/*
    This piece of code will cost 300 micro seconds at least.
    So if the MicroSecends is little than 300, the delay will be NOT exactly.
*/
{

    EFI_STATUS               Status;

    UINTN                    Ticks;
    UINTN                    Counts;
    UINT32                   CurrentTick;
    UINT32                   OriginalTick;
    UINT32                   RemainingTick;
    BOOLEAN                  Extended;

    ASIA_SB_LIB_PPI          *pAsiaSbLibPpi;
    EFI_GUID                 AsiaSbLibPpiGuid = EFI_ASIA_SB_LIB_PPI_GUID;
    UINTN                    Microseconds;

    if (Millisecond == 0)
    {
        return EFI_SUCCESS;
    }
    //The following codes in this function are by Microseconds unit.
    Microseconds =Millisecond * 1000;
    //Locate ASIA_SB_LIB_PPI
    Status = (*PeiServices)->LocatePpi(PeiServices,
                                       &AsiaSbLibPpiGuid,
                                       0,
                                       NULL,
                                       &pAsiaSbLibPpi
                                      );
    ASSERT_PEI_ERROR(PeiServices, Status);

    pAsiaSbLibPpi->GetAcpiTimerValue(PeiServices, pAsiaSbLibPpi, &OriginalTick, &Extended);

    CurrentTick  = OriginalTick;

    //
    // The timer frequency is 3.579545 MHz, so 1 ms corresponds 3.58 clocks
    //
    Ticks = Microseconds * 358 / 100 + OriginalTick + 1;

    //
    // The loops needed by timer overflow
    //
    Counts = (Ticks & 0xFF000000)>>24;    // 24-bit Timer

    //
    // remaining clocks within one loop
    //
    RemainingTick = Ticks & 0xFFFFFF; // 24-bit Timer

    //
    // not intend to use TMROF_STS bit of register PM1_STS, because this adds extra
    // one I/O operation, and maybe generate SMI
    //
    while (Counts != 0)
    {
        pAsiaSbLibPpi->GetAcpiTimerValue(PeiServices, pAsiaSbLibPpi, &CurrentTick, NULL);

        if (CurrentTick <= OriginalTick)
        {
            Counts--;
        }

        OriginalTick = CurrentTick;
    }

    while ((RemainingTick > CurrentTick) && (OriginalTick <= CurrentTick))
    {
        OriginalTick  = CurrentTick;
        pAsiaSbLibPpi->GetAcpiTimerValue(PeiServices, pAsiaSbLibPpi, &CurrentTick, NULL);
    }

    return EFI_SUCCESS;
}


//
/**
   PeiNbResetPciePortx.

  CJW:This function is copy from NbPcie.h
   
  @param  PeiServices	EFI_PEI_SERVICES pointer.
  @param PciAddress

  @return VOID.

**/

EFI_STATUS
PeiNbResetPciePortx (
    IN EFI_PEI_SERVICES **PeiServices,
    IN UINT64 PciAddress
)
{
    EFI_STATUS Status;
    UINTN    GpioIndex;
    ASIA_SB_LIB_PPI* AsiaSbLibPpi;
    EFI_GUID AsiaSbLibPpiGuid = EFI_ASIA_SB_LIB_PPI_GUID;
    PEI_DEBUG((PeiServices, EFI_D_ERROR, "PeiNbResetPciePort()\n"));

    Status = (*PeiServices)->LocatePpi(
                 PeiServices, &AsiaSbLibPpiGuid, 0, NULL, &AsiaSbLibPpi);
    ASSERT_PEI_ERROR(PeiServices, Status);

    //Reset PCIE from GPO pin
    /*
                refer to SIPcieDriving.h
    */
    switch (PciAddress)
    {
	HOST_PERST_PIN
    default:
        return EFI_INVALID_PARAMETER;
    }

    Status = AsiaSbLibPpi->SetGpo(PeiServices, GpioIndex, FALSE);
    PeiNbPcieStallx(PeiServices, 0x14);  //20 ms
    Status = AsiaSbLibPpi->SetGpo(PeiServices, GpioIndex, TRUE);        
    PeiNbPcieStallx(PeiServices, 0x64);  //100 ms

    return Status;
}


/**
   IoeDnPortResetPciePortx.

  Function:
	  This routine is used to trigger PEXRST# of Switch downstream ports
	  This function will slect pin mux as PEXRST# temporary and save the orginal 
	  configuration, this orginal configuration will be set back after the return 
	  from this routine.
  Note:
	  (1) when calling this function, the temp bus number must be assigned,
	  and from the view of this routine, BUSX is BUS1, BUSX+1 is BUS2,
	  BUSX+2 is BUS3 and BUSX+3 is BUS4. so take care of using this!
	  (2) Currently, this function can only support GPIO as PEXRST#, if require 
	  GPO as PEXRST#, need to implement more codes.
  Example:
	  // PERST_PEA0 for 100ms
	  IoeDnPortResetPciePortx(PeiServices, CND003_PEA1); 

   
  @param  PeiServices	EFI_PEI_SERVICES pointer.
  @param PciAddress

  @return VOID.

**/

STATIC
VOID
IoeDnPortResetPciePortx(    
	IN EFI_PEI_SERVICES **PeiServices,
    IN UINT64 PciAddress)
{
	UINT32 MmioBarx;
	UINT16 IoePexRstGpio;
	UINT16 BackupGpioPinMuxCfg,BackupGpioOutputCfg;


	MmioBarx = AsiaPciRead32(AsiaPciAddress(BUSX, UPPORT_DEV, UPPORT_FUN, CND003_BUSX_D0F0_LOWER_BASE_ADR));
	if(!(MmioBarx & 0xFFFF0000)){
		PEI_DEBUG((PeiServices, EFI_D_ERROR, "[CJW_IOE] IoeDnPortResetPciePortx() Warning: Base address of MMIO_ISB not avilable!\n"));
		return;
	}

	switch(PciAddress){
	case CND003_PEA0:
		PEI_DEBUG((PeiServices, EFI_D_ERROR, "[CJW_IOE] -->PEXRST# [PEA0]\n"));
		IoePexRstGpio = GPIO_RESET_PEA0;
		break;
	case CND003_PEA1:
		PEI_DEBUG((PeiServices, EFI_D_ERROR, "[CJW_IOE] -->PEXRST# [PEA1]\n"));
		IoePexRstGpio = GPIO_RESET_PEA1;
		break;
	case CND003_PEA2:
		PEI_DEBUG((PeiServices, EFI_D_ERROR, "[CJW_IOE] -->PEXRST# [PEA2]\n"));
		IoePexRstGpio = GPIO_RESET_PEA2;
		break;
	case CND003_PEA3:
		PEI_DEBUG((PeiServices, EFI_D_ERROR, "[CJW_IOE] -->PEXRST# [PEA3]\n"));
		IoePexRstGpio = GPIO_RESET_PEA3;
		break;
	case CND003_PEA4:
		PEI_DEBUG((PeiServices, EFI_D_ERROR, "[CJW_IOE] -->PEXRST# [PEA4]\n"));
		IoePexRstGpio = GPIO_RESET_PEA4;
		break;
	case CND003_PEB0:
		PEI_DEBUG((PeiServices, EFI_D_ERROR, "[CJW_IOE] -->PEXRST# [PEB0]\n"));
		IoePexRstGpio = GPIO_RESET_PEB0;
		break;
	case CND003_PEB1:
		PEI_DEBUG((PeiServices, EFI_D_ERROR, "[CJW_IOE] -->PEXRST# [PEB1]\n"));
		IoePexRstGpio = GPIO_RESET_PEB1;
		break;
	default:
		PEI_DEBUG((PeiServices, EFI_D_ERROR, "[CJW_IOE_ERROR] -->PEXRST# [Unknown]->use PEA0\n"));
		IoePexRstGpio = GPIO_RESET_PEA0;
	}

	//GPIO or GPO?
	if((IoePexRstGpio&0xF) == IoePexRstGpio){
		//
		//Read the orignal configuration(PinMux) and save them
		//
		BackupGpioPinMuxCfg = AsiaMemoryRead16(MmioBarx + MMIO_ISB_OFFSET + CND003_MMIO_D0F0_VCORE_GPIO_PAD_SEL);
		BackupGpioOutputCfg = AsiaMemoryRead16(MmioBarx + MMIO_ISB_OFFSET + CND003_MMIO_D0F0_VCORE_GENERAL_PURPOSE_OUTPUT);

		//Set it as GPIO
		AsiaMemoryModify16(MmioBarx + MMIO_ISB_OFFSET + CND003_MMIO_D0F0_VCORE_GPIO_PAD_SEL, 
									0x3<<(IoePexRstGpio<<1), 0); 
		//GPIOx = LowLevel(0)
		AsiaMemoryModify16(MmioBarx + MMIO_ISB_OFFSET + CND003_MMIO_D0F0_VCORE_GENERAL_PURPOSE_OUTPUT,
									1<<IoePexRstGpio, 0);

		PeiNbPcieStallx(PeiServices, 100);	//100 ms
		
		//GPIOx = HighLevel(1)
		AsiaMemoryModify16(MmioBarx + MMIO_ISB_OFFSET + CND003_MMIO_D0F0_VCORE_GENERAL_PURPOSE_OUTPUT,
									1<<IoePexRstGpio, 1<IoePexRstGpio);

		PeiNbPcieStallx(PeiServices, 100);	//100 ms

		//
		// restore PinMux setting 
		//
		AsiaMemoryWrite16(MmioBarx + MMIO_ISB_OFFSET + CND003_MMIO_D0F0_VCORE_GPIO_PAD_SEL, BackupGpioPinMuxCfg);
		AsiaMemoryWrite16(MmioBarx + MMIO_ISB_OFFSET + CND003_MMIO_D0F0_VCORE_GENERAL_PURPOSE_OUTPUT, BackupGpioOutputCfg);

	}else{     // GPO
		//
		//Read the orignal configuration(PinMux) and save them
		//
		BackupGpioPinMuxCfg = AsiaMemoryRead16(MmioBarx + MMIO_ISB_OFFSET + CND003_MMIO_D0F0_VCORE_GPO_PAD_SEL);
		BackupGpioOutputCfg = AsiaMemoryRead16(MmioBarx + MMIO_ISB_OFFSET + CND003_MMIO_D0F0_VCORE_GPO_MODE_SETTING);

		//Set it as GP0
		AsiaMemoryModify16(MmioBarx + MMIO_ISB_OFFSET + CND003_MMIO_D0F0_VCORE_GPO_PAD_SEL, 
									0x3<<(IoePexRstGpio<<1), 0); 
		//GPIOx = LowLevel(0)
		AsiaMemoryModify16(MmioBarx + MMIO_ISB_OFFSET + CND003_MMIO_D0F0_VCORE_GPO_MODE_SETTING,
									1<<IoePexRstGpio, 0);

		PeiNbPcieStallx(PeiServices, 100);	//100 ms
		
		//GPIOx = HighLevel(1)
		AsiaMemoryModify16(MmioBarx + MMIO_ISB_OFFSET + CND003_MMIO_D0F0_VCORE_GPO_MODE_SETTING,
									1<<IoePexRstGpio, 1<IoePexRstGpio);

		PeiNbPcieStallx(PeiServices, 100);	//100 ms

		//
		// restore PinMux setting 
		//
		AsiaMemoryWrite16(MmioBarx + MMIO_ISB_OFFSET + CND003_MMIO_D0F0_VCORE_GPO_PAD_SEL, BackupGpioPinMuxCfg);
		AsiaMemoryWrite16(MmioBarx + MMIO_ISB_OFFSET + CND003_MMIO_D0F0_VCORE_GPO_MODE_SETTING, BackupGpioOutputCfg);
		
	}
}



#if 1
/**
   IoeCheckPcieErrorStatus.
   
  @param  PeiServices	EFI_PEI_SERVICES pointer.
  @param NbCfg point to ASIA_NB_CONFIGURATION struct
  @param PciAddress

  @return EFI_STATUS.

**/

EFI_STATUS IoeCheckPcieErrorStatus (
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

    D32 = AsiaPcieRead32(PcieBase, RPpcieAddress|(((UINT64)CND003_BUSXP1_D1D7F0_UNCORRECTABLE_ERR_STA) << 32));	//Rx104
    if(D32){
        PEI_DEBUG((PeiServices, EFI_D_ERROR, "\n RP PCIE Address: %lx, UCERR Status: %x\n",
                   RPpcieAddress, D32));
        return EFI_DEVICE_ERROR;
    }

    D32 = AsiaPcieRead32(PcieBase, RPpcieAddress|(((UINT64)CND003_BUSXP1_D1D7F0_CORRECTABLE_ERR_STA) << 32));	//Rx110
    if(D32){
        PEI_DEBUG((PeiServices, EFI_D_ERROR, "\n RP PCIE Address: %lx, CERR Status: %x\n",
                   RPpcieAddress, D32));
        return EFI_DEVICE_ERROR;
    }

    D8 = AsiaPcieRead8(PcieBase, RPpcieAddress|(((UINT64)CND003_BUSXP1_D1D7F0_DEV_STA_1) << 32));	//Rx4A
    if(D8 & (CND003_BUSXP1_D1D7F0_DSCED + CND003_BUSXP1_D1D7F0_DSNFED + CND003_BUSXP1_D1D7F0_DSFED + CND003_BUSXP1_D1D7F0_DSURD)){
        PEI_DEBUG((PeiServices, EFI_D_ERROR, "\n RP PCIE Address: %lx, Dev Status: %x\n",
                   RPpcieAddress, D8));
        return EFI_DEVICE_ERROR;
    }

    D32 = AsiaPcieRead32(PcieBase, RPpcieAddress|(((UINT64)CND003_BUSXP1_D1D7F0_VC0_RESRC_STA) << 32));	//Rx15A
    if(D32 & CND003_BUSXP1_D1D7F0_VCRSNP0) {
        PEI_DEBUG((PeiServices, EFI_D_ERROR, "\n RP PCIE Address: %lx, VC0RES Status: %x\n",
                   RPpcieAddress, D32));
        return EFI_DEVICE_ERROR;
    }
	
    return EFI_SUCCESS;
}


/**
   IoeCheckPcieLinkStatus.

  Note1:
	  This function can only called in Pei Ioe temp bus assignment stage,
	  because this function think the enumeration on PCI bus tree only 
	  occurs on IOE.
  Note2:
	  [PEEP]  - 1/2/5(TempBus) 
	  |
	  [A0] [A1] [A2] [A3] [A4] [B0] [B1] [PESB] -2/3/4
										  |
										 [PCIEIF]  -3/4/4
										  |
										 [EPTRFC] [ISB devices]
	  For A0/A1/A2/A3/A4/B0/B1: 
		  Rx18 = 2
		  Rx19 = 5(TempBus)
		  Rx1A = 5(TempBus)
	  So Bus5 was assigned for the device under the DN ports
	  since the PEEP's subordinate bus number(Rx1A) was 4 before, 
	  we need to change it to 5(TempBus) here, and change back to 4 in the end

   
  @param  PeiServices	EFI_PEI_SERVICES pointer.
  @param NbCfg point to ASIA_NB_CONFIGURATION struct

  @return EFI_STATUS.

**/

EFI_STATUS
IoeCheckPcieLinkStatus(
	IN EFI_PEI_SERVICES **PeiServices,
	IN ASIA_NB_CONFIGURATION *NbConfig,
	IN UINT64 PciAddress
){
  	// TempBus should be 5
	//EFI_STATUS Statusx = EFI_SUCCESS;
	UINT8 D8 = 0;
    UINT32 D32;
    UINT64 PcieBase;
    UINT16 Loop16;
    BOOLEAN PcieStatus = TRUE;
	UINT8 TempBus;

	PEI_DEBUG((PeiServices, EFI_D_ERROR, "[CJW_IOE] %a()\n", __FUNCTION__));

    //Get PCIE MMIO base address
    PcieBase = NbConfig->PcieBar;
    PEI_DEBUG((PeiServices, EFI_D_ERROR, "          PCIE Base Address: %x\n", PcieBase));
    //Set PCIe secondary Bus and subordinate Bus Number
    // Fix PEEP's Rx1A
    TempBus = AsiaPciRead8(CND003_PEEP|CND003_BUSX_D0F0_SUBORDINATE_BUS_NUM) + 1;
	AsiaPciWrite8(CND003_PEEP|CND003_BUSX_D0F0_SUBORDINATE_BUS_NUM, TempBus);
	// Set DN port Rx18/19/1A
	AsiaPciWrite8(PciAddress|CND003_BUSXP1_D1D7F0_PRIMARY_BUS_NUM, BUSXP1);	
    AsiaPciWrite8(PciAddress|CND003_BUSXP1_D1D7F0_SECONDARY_BUS_NUM, TempBus);	//Rx19
    AsiaPciWrite8(PciAddress|CND003_BUSXP1_D1D7F0_SUBORDINATE_BUS_NUM, TempBus);	//Rx1A
	
    //Wait PCIe In L0
    for(Loop16 =0; Loop16<0x8000; Loop16++) {
        D8 = AsiaPcieRead8(PcieBase, PciAddress|(((UINT64)CND003_BUSXP1_D1D7F0_PHYLS_LTSSM_STATE) << 32));	//Rx1C3
        if (D8 == 0x8A){
            break;
        }
    }	
	PEI_DEBUG((PeiServices, EFI_D_ERROR, "          IOE DN ports PHYLS_LTSSM_STATE: %02x\n", D8));

    //Clear PCIe Error Status
    D32 = 0xffffffff;
    AsiaPcieWrite32(PcieBase, PciAddress|(((UINT64)CND003_BUSXP1_D1D7F0_UNCORRECTABLE_ERR_STA) << 32), D32);	//Rx104
    AsiaPcieWrite32(PcieBase, PciAddress|(((UINT64)CND003_BUSXP1_D1D7F0_CORRECTABLE_ERR_STA) << 32), D32);	//Rx110
    AsiaPciModify8(PciAddress|CND003_BUSXP1_D1D7F0_DEV_STA_1, 0x0F, 0x0F);	//Rx4A[3:0]

	PcieStatus = FALSE;
    //Check PCIE Error Status
    if(IoeCheckPcieErrorStatus(PeiServices, NbConfig, PciAddress) == EFI_SUCCESS){
        // if no Error read Device ID
        PEI_DEBUG((PeiServices, EFI_D_ERROR, "          no Error read Device ID\n"));

		for (Loop16=0; Loop16<0x1000; Loop16++){
            D32 = AsiaPciRead32(ASIA_PCI_ADDRESS(TempBus, 0, 0, 0));  //Read VID DID
            if (D32 != 0xFFFFFFFF) {		//if read ID success
                if (IoeCheckPcieErrorStatus(PeiServices, NbConfig, PciAddress) == EFI_SUCCESS) { //but error occur
                    PcieStatus = TRUE;
                }else{
                    PEI_DEBUG((PeiServices, EFI_D_ERROR, "\n          Read Device ID error,Loop16:%x \n",Loop16));
                    PcieStatus = FALSE;
                    break;
                }
            }else{
                PEI_DEBUG((PeiServices, EFI_D_ERROR, "\n          Device ID is 0xffffffff \n"));
                PcieStatus = FALSE;
                break;
            }
        }
    }

    //Reset PCIe secondary Bus and subordinate Bus Num
    AsiaPciWrite8(PciAddress|CND003_BUSXP1_D1D7F0_SECONDARY_BUS_NUM, 0);	//Rx19
    AsiaPciWrite8(PciAddress|CND003_BUSXP1_D1D7F0_SUBORDINATE_BUS_NUM, 0);	//Rx1A
	//Fix back the PEEP's subordinate bus number
	AsiaPciWrite8(CND003_PEEP|CND003_BUSX_D0F0_SUBORDINATE_BUS_NUM, TempBus-1);
	
    PEI_DEBUG((PeiServices, EFI_D_ERROR, "          PCIeStatus = %02x\n", PcieStatus));
    if (!PcieStatus)
    {
        return EFI_DEVICE_ERROR;
    }
    return EFI_SUCCESS;	
}

/*


*/
#define RETRY_COUNT_TOTAL   1
#define RETRY_COUNT_SINGLE  5

/**
   IoeCheckPcieLink.
   
  @param  PeiServices	EFI_PEI_SERVICES pointer.
  @param NbCfg point to ASIA_NB_CONFIGURATION struct

  @return VOID.

**/

EFI_STATUS
IoeCheckPcieLink(
    IN EFI_PEI_SERVICES **PeiServices,
    IN ASIA_NB_CONFIGURATION *NbConfig
)
{ 

	EFI_STATUS Statusx = EFI_SUCCESS;
	
	BOOLEAN Cnd003PcieRstTest;
	BOOLEAN Cnd003PEA0RstTest;
	BOOLEAN Cnd003PEA1RstTest;
	BOOLEAN Cnd003PEA2RstTest;
	BOOLEAN Cnd003PEA3RstTest;
	BOOLEAN Cnd003PEA4RstTest;
	BOOLEAN Cnd003PEB0RstTest;
	BOOLEAN Cnd003PEB1RstTest;
	
	UINT8 RetryCountTotal;   		//for total ports retry counts 
	UINT8 RetryCountSingle;   		//for singal port retry counts
	UINT8 D8;
	BOOLEAN PcieLinkFailFlag = FALSE;

	//
	// Read reset test enable/disable from SetupMenu
	//
	//JNY add for IOE control -S
	if(NbConfig->IoeDnPortCtl == 1)
	{
	  Cnd003PcieRstTest = NbConfig->Cnd003PcieRstTest;
	  
	  if(NbConfig->IoePEA0Ctl == 1){
		  Cnd003PEA0RstTest = NbConfig->Cnd003PEA0RstTest;
	  }else{
		  Cnd003PEA0RstTest = FALSE;
	  }
	  if(NbConfig->IoePEA1Ctl == 1){
		  Cnd003PEA1RstTest = NbConfig->Cnd003PEA1RstTest;
	  }else{
		  Cnd003PEA1RstTest = FALSE;
	  }
	  if(NbConfig->IoePEA2Ctl == 1){
		  Cnd003PEA2RstTest = NbConfig->Cnd003PEA2RstTest;
	  }else{
		  Cnd003PEA2RstTest = FALSE;
	  }
	  if(NbConfig->IoePEA3Ctl == 1){
	  	 Cnd003PEA3RstTest = NbConfig->Cnd003PEA3RstTest;
	  }else{
	  	 Cnd003PEA3RstTest = FALSE;
	  }
	  if(NbConfig->IoePEA4Ctl == 1){
	  	 Cnd003PEA4RstTest = NbConfig->Cnd003PEA4RstTest;
	  }else{
	  	 Cnd003PEA4RstTest = FALSE;
	  }
	  if(NbConfig->IoePEB0Ctl == 1){
	  	 Cnd003PEB0RstTest = NbConfig->Cnd003PEB0RstTest;
	  }else{
	  	 Cnd003PEB0RstTest = FALSE;
	  }	  
	  if(NbConfig->IoePEB1Ctl == 1){
	  	 Cnd003PEB1RstTest = NbConfig->Cnd003PEB1RstTest;
	  }else{
	  	 Cnd003PEB1RstTest = FALSE;
	  }
	
	}else{
		Cnd003PcieRstTest = FALSE;
		Cnd003PEA0RstTest = FALSE;
		Cnd003PEA1RstTest = FALSE;
		Cnd003PEA2RstTest = FALSE;
		Cnd003PEA3RstTest = FALSE;
		Cnd003PEA4RstTest = FALSE;
		Cnd003PEB0RstTest = FALSE;
		Cnd003PEB1RstTest = FALSE;
	}
	
    //JNY add for IOE control -E
	//
	// Check if CND003 PEXRST# link test enable or disable
	//
	if(Cnd003PcieRstTest == FALSE){
		//if not enable, return directly.
		return Statusx;
	}else{
		RetryCountTotal = RETRY_COUNT_TOTAL;	
		do{
			//
			// For PEA0
			//
			if(Cnd003PEA0RstTest){
				RetryCountSingle = RETRY_COUNT_SINGLE;
				do{
					//Check PCIE Presence
					D8 = AsiaPciRead8(CND003_PEA0|CND003_BUSXP1_D1D7F0_SLOT_STA_1);	//Rx5A
					if (D8 & CND003_BUSXP1_D1D7F0_SPDCST){
						PEI_DEBUG((PeiServices, EFI_D_ERROR, "[CJW_IOE] Card present under PEA0: %x\n", D8));
						Statusx = IoeCheckPcieLinkStatus(PeiServices, NbConfig, CND003_PEA0);
						if(Statusx != EFI_SUCCESS){
							IoeDnPortResetPciePortx(PeiServices, CND003_PEA0);
							// we try to keep waiting for link up longer for the last tree times
							if(RetryCountSingle%3 == 0){
								PeiNbPcieStallx(PeiServices,2000);    // 2 S
							}else{
								PeiNbPcieStallx(PeiServices,63);     // 1/16 S
							}
							RetryCountSingle--;
						}else{
							break;
						}
					}else{
						//Not found device under this port, no need to build link.
						break;
					}

				}while(RetryCountSingle);

				if(RetryCountSingle == 0){
					PcieLinkFailFlag = TRUE;
				}
			}


			//
			// For PEA1
			//
			if(Cnd003PEA1RstTest){
				RetryCountSingle = RETRY_COUNT_SINGLE;
				do{
					//Check PCIE Presence
					D8 = AsiaPciRead8(CND003_PEA1|CND003_BUSXP1_D1D7F0_SLOT_STA_1);	//Rx5A
					if (D8 & CND003_BUSXP1_D1D7F0_SPDCST){
						PEI_DEBUG((PeiServices, EFI_D_ERROR, "[CJW_IOE] Card present under PEA1: %x\n", D8));
						Statusx = IoeCheckPcieLinkStatus(PeiServices, NbConfig, CND003_PEA1);
						if(Statusx != EFI_SUCCESS){
							IoeDnPortResetPciePortx(PeiServices, CND003_PEA1);
							// we try to keep waiting for link up longer for the last tree times
							if(RetryCountSingle%3 == 0){
								PeiNbPcieStallx(PeiServices,2000);    // 2 S
							}else{
								PeiNbPcieStallx(PeiServices,63);     // 1/16 S
							}
							RetryCountSingle--;
						}else{
							break;
						}
					}else{
						//Not found device under this port, no need to build link.
						break;
					}

				}while(RetryCountSingle);

				if(RetryCountSingle == 0){
					PcieLinkFailFlag = TRUE;
				}
			}


			//
			// For PEA2
			//
			if(Cnd003PEA2RstTest){
				RetryCountSingle = RETRY_COUNT_SINGLE;
				do{
					//Check PCIE Presence
					D8 = AsiaPciRead8(CND003_PEA2|CND003_BUSXP1_D1D7F0_SLOT_STA_1);	//Rx5A
					if (D8 & CND003_BUSXP1_D1D7F0_SPDCST){
						PEI_DEBUG((PeiServices, EFI_D_ERROR, "[CJW_IOE] Card present under PEA2: %x\n", D8));
						Statusx = IoeCheckPcieLinkStatus(PeiServices, NbConfig, CND003_PEA2);
						if(Statusx != EFI_SUCCESS){
							IoeDnPortResetPciePortx(PeiServices, CND003_PEA2);
							// we try to keep waiting for link up longer for the last tree times
							if(RetryCountSingle%3 == 0){
								PeiNbPcieStallx(PeiServices,2000);    // 2 S
							}else{
								PeiNbPcieStallx(PeiServices,63);     // 1/16 S
							}
							RetryCountSingle--;
						}else{
							break;
						}
					}else{
						//Not found device under this port, no need to build link.
						break;
					}

				}while(RetryCountSingle);

				if(RetryCountSingle == 0){
					PcieLinkFailFlag = TRUE;
				}
			}

			//
			// For PEA3
			//
			if(Cnd003PEA3RstTest){
				RetryCountSingle = RETRY_COUNT_SINGLE;
				do{
					//Check PCIE Presence
					D8 = AsiaPciRead8(CND003_PEA3|CND003_BUSXP1_D1D7F0_SLOT_STA_1);	//Rx5A
					if (D8 & CND003_BUSXP1_D1D7F0_SPDCST){
						PEI_DEBUG((PeiServices, EFI_D_ERROR, "[CJW_IOE] Card present under PEA3: %x\n", D8));
						Statusx = IoeCheckPcieLinkStatus(PeiServices, NbConfig, CND003_PEA3);
						if(Statusx != EFI_SUCCESS){
							IoeDnPortResetPciePortx(PeiServices, CND003_PEA3);
							// we try to keep waiting for link up longer for the last tree times
							if(RetryCountSingle%3 == 0){
								PeiNbPcieStallx(PeiServices,2000);    // 2 S
							}else{
								PeiNbPcieStallx(PeiServices,63);     // 1/16 S
							}
							RetryCountSingle--;
						}else{
							break;
						}
					}else{
						//Not found device under this port, no need to build link.
						break;
					}

				}while(RetryCountSingle);

				if(RetryCountSingle == 0){
					PcieLinkFailFlag = TRUE;
				}
			}


			//
			// For PEA4
			//
			if(Cnd003PEA4RstTest){
				RetryCountSingle = RETRY_COUNT_SINGLE;
				do{
					//Check PCIE Presence
					D8 = AsiaPciRead8(CND003_PEA4|CND003_BUSXP1_D1D7F0_SLOT_STA_1);	//Rx5A
					if (D8 & CND003_BUSXP1_D1D7F0_SPDCST){
						PEI_DEBUG((PeiServices, EFI_D_ERROR, "[CJW_IOE] Card present under PEA4: %x\n", D8));
						Statusx = IoeCheckPcieLinkStatus(PeiServices, NbConfig, CND003_PEA4);
						if(Statusx != EFI_SUCCESS){
							IoeDnPortResetPciePortx(PeiServices, CND003_PEA4);
							// we try to keep waiting for link up longer for the last tree times
							if(RetryCountSingle%3 == 0){
								PeiNbPcieStallx(PeiServices,2000);    // 2 S
							}else{
								PeiNbPcieStallx(PeiServices,63);     // 1/16 S
							}
							RetryCountSingle--;
						}else{
							break;
						}
					}else{
						//Not found device under this port, no need to build link.
						break;
					}

				}while(RetryCountSingle);

				if(RetryCountSingle == 0){
					PcieLinkFailFlag = TRUE;
				}
			}


			//
			// For PEB0
			//
			if(Cnd003PEB0RstTest){
				RetryCountSingle = RETRY_COUNT_SINGLE;
				do{
					//Check PCIE Presence
					D8 = AsiaPciRead8(CND003_PEB0|CND003_BUSXP1_D1D7F0_SLOT_STA_1);	//Rx5A
					if (D8 & CND003_BUSXP1_D1D7F0_SPDCST){
						PEI_DEBUG((PeiServices, EFI_D_ERROR, "[CJW_IOE] Card present under PEB0: %x\n", D8));
						Statusx = IoeCheckPcieLinkStatus(PeiServices, NbConfig, CND003_PEB0);
						if(Statusx != EFI_SUCCESS){
							IoeDnPortResetPciePortx(PeiServices, CND003_PEB0);
							// we try to keep waiting for link up longer for the last tree times
							if(RetryCountSingle%3 == 0){
								PeiNbPcieStallx(PeiServices,2000);    // 2 S
							}else{
								PeiNbPcieStallx(PeiServices,63);     // 1/16 S
							}
							RetryCountSingle--;
						}else{
							break;
						}
					}else{
						//Not found device under this port, no need to build link.
						break;
					}

				}while(RetryCountSingle);

				if(RetryCountSingle == 0){
					PcieLinkFailFlag = TRUE;
				}
			}


			//
			// For PEB1
			//
			if(Cnd003PEB1RstTest){
				RetryCountSingle = RETRY_COUNT_SINGLE;
				do{
					//Check PCIE Presence
					D8 = AsiaPciRead8(CND003_PEB1|CND003_BUSXP1_D1D7F0_SLOT_STA_1);	//Rx5A
					if (D8 & CND003_BUSXP1_D1D7F0_SPDCST){
						PEI_DEBUG((PeiServices, EFI_D_ERROR, "[CJW_IOE] Card present under PEB1: %x\n", D8));
						Statusx = IoeCheckPcieLinkStatus(PeiServices, NbConfig, CND003_PEB1);
						if(Statusx != EFI_SUCCESS){
							IoeDnPortResetPciePortx(PeiServices, CND003_PEB1);
							// we try to keep waiting for link up longer for the last tree times
							if(RetryCountSingle%3 == 0){
								PeiNbPcieStallx(PeiServices,2000);    // 2 S
							}else{
								PeiNbPcieStallx(PeiServices,63);     // 1/16 S
							}
							RetryCountSingle--;
						}else{
							break;
						}
					}else{
						//Not found device under this port, no need to build link.
						break;
					}

				}while(RetryCountSingle);

				if(RetryCountSingle == 0){
					PcieLinkFailFlag = TRUE;
				}
			}
	
		}while(RetryCountTotal--);

	    if(RetryCountTotal== 0){
	        PEI_DEBUG((PeiServices, EFI_D_ERROR, "          PCIE Card Init Fail\n"));
	    }
		return EFI_SUCCESS;
	}
}
#endif






/**************************************************************************
// Bus number temp assignment
**************************************************************************/
	
/**
	Assign temp Pri/Sec/Sub bus number for this Port
	And clear it immediately.
	This action's target is to read the VIDDID of the device behind the bridge.
	
	Return EFI_SUCCESS if VIDDID we read same to IOE
**/
STATIC
EFI_STATUS
CfgRpTemporaryAndLookup(
	IN EFI_PEI_SERVICES **PeiServices,
	IN UINT8 BusNum,
	IN UINT8 DevNum,
	IN UINT8 FunNum
)
{
	EFI_STATUS Status;
	UINT8 HeaderType;
	UINT32 VidDid;
	UINT8 LtssmStatus = 0x00;
	UINT8 ByPass = 0;
	UINT8 FailCounter = 0;
	BOOLEAN AssignedFlag;
		
	//this configure only for Bridge
	HeaderType =  AsiaPciRead8 (AsiaPciAddress(BusNum,DevNum,FunNum,0x0E));
	HeaderType &= 0x7F;
	if(HeaderType != 0x01){ //it's not a Bridge
		return EFI_NOT_FOUND;
	}

	//CJW_20181114 IOE CodeBusRepair_Item1_(1/3)
	//To check whether the IOE have been assigned bus number
	// 	if yes, we do not need to assign it again(we just need to access BusX here)
	//	if no, we need to assign a bus number to BUSX
	if(AsiaPciRead8 (AsiaPciAddress(BusNum,DevNum,FunNum,0x1A))!=0){
		AssignedFlag = TRUE ;
	}else{
		AssignedFlag = FALSE;
	}
	if(!AssignedFlag){
		//Assign temp Pri/Sec/Sub BusNumber 
		AsiaPciWrite8(AsiaPciAddress(BusNum,DevNum,FunNum,0x18), BUS0);
		AsiaPciWrite8(AsiaPciAddress(BusNum,DevNum,FunNum,0x19), BUSX);
		AsiaPciWrite8(AsiaPciAddress(BusNum,DevNum,FunNum,0x1A), BUSX);	
	}


	


	//
	// Now, we can confirm that there was a device under this RP,
	// before we search IOE, we must keep on reading LinkStatus 
	// and hope to get in L0 state
	//
	// Note: when we call this routine at the first time, RP's Ephy 
	// SI driving just fill in, but IOE's Ephy SI driving still not 
	// avaliable, and maybe link not stable enough.
	//
	do{
		ByPass = 0;
		LtssmStatus= AsiaPcieRead8(0xE0000000, AsiaPciAddress(BusNum,DevNum,FunNum, HOST_PHYLS_LTSSM_STATE));
		if(LtssmStatus == HOST_PHYLS_State_L0){
			ByPass = 1;
		}else{
			FailCounter++;
			PeiNbPcieStallx(PeiServices, 1); 	//delay 1ms
			if(FailCounter >= 100){				//100ms timeout, give up to wait L0 state
				ByPass = 1;
			}
		}
	}while(ByPass!=1);
	if(FailCounter != 0){
		PEI_DEBUG((PeiServices, EFI_D_ERROR, "[CJW_IOE] Fail Counts: %d(delay 1ms each time)\n",FailCounter));
	}
	



	//Read the VIDDID of device 
	VidDid = AsiaPciRead32 (AsiaPciAddress(BUSX,UPPORT_DEV,UPPORT_FUN,CND003_BUSX_D0F0_VID)); // bus-1 dev-0 func-0 offset-0

#ifdef ASSIGN_DEBUG_EN	
	PEI_DEBUG((PeiServices, EFI_D_ERROR, "[CJW_IOE] %a() Line%d: Card Present and it's VidDid = %x [%d|%d|%d]\n",
												__FUNCTION__,__LINE__,VidDid,BusNum,DevNum,FunNum));

	//
	// Add some code for Debug
	//
	if(VidDid == 0xFFFFFFFF){
		PEI_DEBUG((PeiServices, EFI_D_ERROR, "[CJW_IOE] For Debuging EK0 'Not Found IOE' issue! \n"  ));

		IoeDumpCfg(PeiServices, 0xE0000000, BusNum,DevNum,FunNum,  0x300);
		IoeDumpCfg(PeiServices, 0xE0000000, 1,0,0,  0x40);
		
		PeiNbPcieStallx(PeiServices, 0x1000);
		PEI_DEBUG((PeiServices, EFI_D_ERROR, "[CJW_IOE] after 1s \n"  ));
		IoeDumpCfg(PeiServices, 0xE0000000, BusNum,DevNum,FunNum,  0x300);
		IoeDumpCfg(PeiServices, 0xE0000000, 1,0,0,  0x40);


		PEI_DEBUG((PeiServices, EFI_D_ERROR, "[CJW_IOE] retrain link \n"  ));
		AsiaPciModify8(AsiaPciAddress(BusNum,DevNum,FunNum, 0x50), BIT5, BIT5);
		

		PeiNbPcieStallx(PeiServices, 0x1000);
		PEI_DEBUG((PeiServices, EFI_D_ERROR, "[CJW_IOE] after 1s \n"  ));
		IoeDumpCfg(PeiServices, 0xE0000000, BusNum,DevNum,FunNum,  0x300);
		IoeDumpCfg(PeiServices, 0xE0000000, 1,0,0,  0x40);
	
	}
	

	

#endif

	//if(VidDid == 0x071F1106){
	if((VidDid == IOEBUSXUSP_VIDDID)||(VidDid == IOEBUSXUSP_VIDDID_ZX)||(VidDid == IOEBUSXUSP_VIDDID_ZERO)){
		//Found IOE!
		Status = EFI_SUCCESS;
	}else{
		//Not IOE
		Status = EFI_NOT_FOUND;
	}

	//CJW_20181114 IOE CodeBusRepair_Item1_(2/3)
	if(!AssignedFlag){
		//Clear those registers for avoid side effect
		AsiaPciWrite8(AsiaPciAddress(BusNum,DevNum,FunNum,0x18), 0);
		AsiaPciWrite8(AsiaPciAddress(BusNum,DevNum,FunNum,0x19), 0);
		AsiaPciWrite8(AsiaPciAddress(BusNum,DevNum,FunNum,0x1A), 0);	
	}
	return Status;
}


/**
	Search IOE upstream port
	
	Return EFI_SUCCESS when we found the IOE BusxD0F0
**/
STATIC
EFI_STATUS
IoeSearchPcieRpTemporary(
	IN EFI_PEI_SERVICES **PeiServices,
	IN UINT8 BusNum,
	IN UINT8 DevNum,
	IN UINT8 FunNum
)
{
	UINT64  Addr;
	UINT8 CapNxtPtr,CapPtr;
	UINT8 CapId;
	EFI_STATUS  Status = EFI_NOT_FOUND;
	UINT8 SearchTimes = 0;
	UINT8 TempValue;
	UINT32 TempValue32;

	//Firstly, we must ensure this 'Device/Bridge' really exist
	TempValue32 = AsiaPciRead32(AsiaPciAddress(BusNum,DevNum,FunNum,0x00));
	if(TempValue32 == 0xFFFFFFFF){
		//PEI_DEBUG((PeiServices, EFI_D_ERROR, "[CJW_IOE] %a() Line%d: This device/bridge not available! [%d|%d|%d]\n",
		//										__FUNCTION__,__LINE__,BusNum,DevNum,FunNum));
		return Status;
	}

	
	//To detect card presence or not
	Addr = AsiaPciAddress(BusNum,DevNum,FunNum,0x34);
	CapNxtPtr = AsiaPciRead8 (Addr);					//read the capability pointer register
	if(CapNxtPtr == 0xFF){								//not found the PCIE capability block
		//PEI_DEBUG((PeiServices, EFI_D_ERROR, "[CJW_IOE] %a() Line%d: No Capability blocks on this port[%d|%d|%d]\n",
		//										__FUNCTION__,__LINE__,BusNum,DevNum,FunNum));
		return Status;									//Not found Capability
	}
	do{
		CapPtr = CapNxtPtr;
		Addr = AsiaPciAddress (BusNum, DevNum, FunNum, CapPtr);
		CapId = AsiaPciRead8 (Addr); 					//Read the CapId which in the Capability Block CapID field
		SearchTimes++;

		Addr = AsiaPciAddress (BusNum, DevNum, FunNum, CapPtr + 1); 
        CapNxtPtr = AsiaPciRead8 (Addr);   				//Get the offset of next Capability Block
	}while((CapId != 0x10) && (SearchTimes < 64) && (CapNxtPtr != 0));

   	//if not found PCIE compability Ptr rutun EFI_NOT_FOUND
    if (CapId != 0x10){
		//PEI_DEBUG((PeiServices, EFI_D_ERROR, "[CJW_IOE] %a() Line%d: No PCI Express Capability blocks on this port[%d|%d|%d]\n",
		//										__FUNCTION__,__LINE__,BusNum,DevNum,FunNum));
        return Status;									//Not found PCI Express Capability Block
    }
	//Judge weither device present
	TempValue = AsiaPciRead8 (AsiaPciAddress (BusNum, DevNum, FunNum, CapPtr + 0x1A));
	if ((TempValue & BIT6) == BIT6){
		//card present, is it IOE?
		Status = CfgRpTemporaryAndLookup(PeiServices,BusNum,DevNum,FunNum); 
		if(Status != EFI_SUCCESS){
		//	PEI_DEBUG((PeiServices, EFI_D_ERROR, "[CJW_IOE] %a() Line%d: The device present but not IOE [%d|%d|%d]\n",
		//										__FUNCTION__,__LINE__,BusNum,DevNum,FunNum));
		}
	}else{
		//	PEI_DEBUG((PeiServices, EFI_D_ERROR, "[CJW_IOE] %a() Line%d: Card not present on:[%d|%d|%d]\n",
		//										__FUNCTION__,__LINE__,BusNum,DevNum,FunNum));
	}

	
	
	return Status;
}





#if 1
/*
	Input:	any BusNumber
	Output:	the Subordinate Bus Number under the Whole tree appointed by "Input"

	Return SubBus Number
*/
STATIC
UINT8
IoeLoopToEnumerateTemporary(
	IN EFI_PEI_SERVICES **PeiServices,
	IN UINT8 Bus)
{
	UINT8 SecBus,SubBus;
	UINT8 Dev;
	UINT16 Vid,ClassCode,Did;
	UINT32 VidDid;

#ifdef ASSIGN_DEBUG_EN
	PEI_DEBUG((PeiServices, EFI_D_ERROR, "          LoopToEnumerate - Bus[%d]\n",Bus));
#endif

	SecBus = Bus; //bus 1
	SubBus = 0x0;

	for(Dev = 31; (Dev < 32)&&(Dev >= 0); Dev--){
		Vid = AsiaPciRead16(AsiaPciAddress(Bus, Dev, 0, 0x00));  		//Device/Bridge exist?
		Did = AsiaPciRead16(AsiaPciAddress(Bus, Dev, 0, 0x02));
		if(Vid == 0xFFFF){
			//PEI_DEBUG((PeiServices, EFI_D_ERROR, "             Bus[%d]Dev[%d]Fun 0  NotFound!\n",Bus,Dev));
			continue;
		}else{
#ifdef ASSIGN_DEBUG_EN
			PEI_DEBUG((PeiServices, EFI_D_ERROR, "             Bus[%d]Dev[%d]Fun 0  VID is %04X,DID is 0x%04X\n",Bus,Dev,Vid,Did));			
#endif
		}
#if 0

		//We just want to enumerate the IOE self part 
		//so it will not assign Bus Number for 
		//some of PCIE DN ports(PCIE BusX+1 D0-D7F0)  even Device exist under it.
		//Then we can confirm the BusX=Bus1  BusX+2=Bus3  BUSX+3=Bus4
		Did = AsiaPciRead16(AsiaPciAddress(Bus, Dev, 0, 0x02)); 
 
		if(((Vid == IOE_VID_VIA)||(Vid == IOE_VID_ZX)||(Vid == 0x0000))&&
			((Did==DID_XBCTL)||
			(Did==DID_PEA1)||
			(Did==DID_PEA2)||
			(Did==DID_PEA3)||
			(Did==DID_PEA4)||
			(Did==DID_PEB0)|| 
			(Did==DID_PEB1)|| 
			(Did==DID_PEA0))){	
#ifdef ASSIGN_DEBUG_EN			
			PEI_DEBUG((PeiServices, EFI_D_ERROR, "             Bus[%d]Dev[%d]Fun 0 Skip the enumerate under this bridge\n",Bus,Dev));
#endif
			continue;
		}
	
#endif

		//
		//If we need to assign MMIO space for each pci device
		//Add some code here
		//At the same time, 
		//Must to cancel those temporary MMIO base address later
		//
		

		ClassCode = AsiaPciRead16(AsiaPciAddress(Bus, Dev, 0, 0x0A)); 	//Is bridge?
		if(ClassCode == 0x0604){
			SecBus++;
			AsiaPciWrite8(AsiaPciAddress(Bus,Dev,0,0x18), Bus);
			AsiaPciWrite8(AsiaPciAddress(Bus,Dev,0,0x19), SecBus);
			AsiaPciWrite8(AsiaPciAddress(Bus,Dev,0,0x1A), 0xFF);		//Set the temp Sub Bus Number


//;cjw-A0-debug  20161030
			VidDid = AsiaPciRead32(AsiaPciAddress(Bus, Dev, 0, 0x0));
			if((VidDid == IOE_PCIEIF_VIDDID)||(VidDid == IOE_PCIEIF_VIDDID_ZX)||(VidDid == IOE_PCIEIF_VIDDID_ZERO)){
				//if we found PCIEIF, then we not go to search the next bridge, because we have found the whole IOE now
				SubBus = SecBus;   //Sub bus number of PCIEIF is BUSXP3
			 	PEI_DEBUG((PeiServices, EFI_D_ERROR, "           PCIEIF - Completed\n"));
			}else{
				// A config write is required in order for the device to re-capture the Bus number,
				// according to PCI Express Base Specification, 2.2.6.2	
				SubBus = IoeLoopToEnumerateTemporary(PeiServices,SecBus); 		//Get the Subordinate Bus Number
			}
//;cjw-A0-debug  END

	
			// A config write is required in order for the device to re-capture the Bus number,
			// according to PCI Express Base Specification, 2.2.6.2	
			//SubBus = IoeLoopToEnumerateTemporary(PeiServices,SecBus); 		//Get the Subordinate Bus Number

#ifdef ASSIGN_DEBUG_EN
			PEI_DEBUG((PeiServices, EFI_D_ERROR, "           Enumerate-->[%d|%d|%d]->Rx18,19,1A = %d,%d,%d\n",Bus,Dev,0,Bus,SecBus,SubBus));
#endif
			AsiaPciWrite8(AsiaPciAddress(Bus,Dev,0,0x1A), SubBus);		//Set the real Sub Bus Number
			SecBus = SubBus;											//Calculate SecBusNumber of the next PCI tree's branch		
		}else{
			PEI_DEBUG((PeiServices, EFI_D_ERROR, "             Bus[%d]Dev[%d]Fun 0  Rx0A[15:0]ClassCode=0x%04x, Not 0604h, Stop to enumerate!\n",Bus,Dev,ClassCode));	
		}

	}

	if(SubBus == 0){
		return Bus;
	}else{
		return SubBus;
	}
	 		
}


/*
	Enumeration to assign a temp bus number for IOE

	Do typical enumeration only for the specific PCIE port[Just enumeration for IOE]
	That's mean:
	we assume that all PCIE port on MB was not conneted to any other PCIE device
	so NO BusNumber was assigned to other PCIE port
	and IOE upstream port's  BusNumber=1, we should also record the BusNumber of BusX+2
	
Param:
	IN:Bus/Dev/Func Number
	OUT:Subordinate Bus Number of IOE
*/
#if ASSIGN_STRATEGY_A
STATIC
EFI_STATUS
IoePeiAssignPciTemporary(	
	IN EFI_PEI_SERVICES **PeiServices,
	IN UINT8 BusNum,
	IN UINT8 DevNum,
	IN UINT8 FunNum
	)
{
/*[1] This is a typical implement*/

	UINT8 Bus,SubBus;
	UINT16 Vid;

	//PEI_DEBUG((PeiServices, EFI_D_ERROR, "[CJW_IOE] %a() Line%d<--\n",__FUNCTION__,__LINE__));
	//PEI_DEBUG((PeiServices, EFI_D_ERROR, "[CJW_IOE] %a() Line%d  Congratulations! Next we assign the temp Bar/Bus/Base/Limit\n",__FUNCTION__,__LINE__));

	//loop to search the IoeSearchTbl to lookup IOE 
	Bus = BusNum;  															//Rp's BusNum  0
	Vid = AsiaPciRead16(AsiaPciAddress(BusNum, DevNum, FunNum, 0x00));
	if(Vid == 0xFFFF){
		//PEI_DEBUG((PeiServices, EFI_D_ERROR, "[CJW_IOE] %a() Line%d NotFound IOE under this RP ?! \n",__FUNCTION__,__LINE__));
		return EFI_DEVICE_ERROR;
	}else{
		//PEI_DEBUG((PeiServices, EFI_D_ERROR, "[CJW_IOE] %a() Line%d FoundIoe: IOE exist under [%d|%d|%d]\n",__FUNCTION__,__LINE__,BusNum,DevNum,FunNum));
	}

	Bus++;  																//next bus number - BusX
	AsiaPciWrite8(AsiaPciAddress(BusNum,DevNum,FunNum,0x19), Bus);
	AsiaPciWrite8(AsiaPciAddress(BusNum,DevNum,FunNum,0x1A), 0xFF);
	
	// A config write is required in order for the device to re-capture the Bus number,
	// according to PCI Express Base Specification, 2.2.6.2	
	// AsiaPciWrite8(AsiaPciAddress(Bus,0,0,0x00), 0x0);	 					//BusX_D0F0    temp del

	//Get the Subordinate Bus Number of IOE
	SubBus = IoeLoopToEnumerateTemporary(PeiServices, Bus); 				//input:Bus1  OutPut:SubBusNumber of the whole tree!
	AsiaPciWrite8(AsiaPciAddress(BusNum,DevNum,FunNum,0x1A), SubBus);    	//Subordinate Bus Number of MB RP is equal to IOE USP 
	//PEI_DEBUG((PeiServices, EFI_D_ERROR, "[CJW_IOE] SubBus[%d]\n",SubBus));

#if 0
	//Those code only for Debug - Must clear those cfg  before PCIE PEI init
{
	UINT8 Dev;
	UINT16 ClassCode;
	for(Bus = SubBus; Bus >= 1; Bus--){
		for(Dev = 0; Dev < 32; Dev++){
			Vid = AsiaPciRead16(AsiaPciAddress(Bus, Dev, 0, 0x00));
			if(Vid == 0xFFFF){
				continue;
			}
			ClassCode = AsiaPciRead16(AsiaPciAddress(Bus, Dev, 0, 0x0A));
			if(ClassCode == 0x0604){
				AsiaPciWrite8(AsiaPciAddress(Bus, Dev, 0, 0x18), 0); //clear the bus number
			}
		}
	}
	//We must clear the RP's Pri/Sec/Sub bus number. otherwise , it will hang in PeiNbPcieInit();
	AsiaPciWrite8(AsiaPciAddress(BusNum, DevNum, FunNum, 0x18), 0); //clear the bus number
	AsiaPciWrite8(AsiaPciAddress(BusNum, DevNum, FunNum, 0x19), 0); 
	AsiaPciWrite8(AsiaPciAddress(BusNum, DevNum, FunNum, 0x1A), 0); 
}
#endif



	return EFI_SUCCESS;
}
#endif

#if ASSIGN_STRATEGY_B
STATIC
EFI_STATUS
IoePeiAssignPciTemporary(	
	IN EFI_PEI_SERVICES **PeiServices,
	IN UINT8 BusNum,
	IN UINT8 DevNum,
	IN UINT8 FunNum
	)
{
//CJW_IOE_NEW
//assign temp bus number for SATA PEI INIT
  AsiaPciWrite8(AsiaPciAddress(BusNum, DevNum, FunNum, 0x18), BUS0);
  AsiaPciWrite8(AsiaPciAddress(BusNum, DevNum, FunNum, 0x19), BUSX);
  AsiaPciWrite8(AsiaPciAddress(BusNum, DevNum, FunNum, 0x1A), BUSXP3);

  AsiaPciWrite8(AsiaPciAddress(BUSX, UPPORT_DEV, UPPORT_FUN, 0x18), BUSX);
  AsiaPciWrite8(AsiaPciAddress(BUSX, UPPORT_DEV, UPPORT_FUN, 0x19), BUSXP1);
  AsiaPciWrite8(AsiaPciAddress(BUSX, UPPORT_DEV, UPPORT_FUN, 0x1A), BUSXP3);

  AsiaPciWrite8(AsiaPciAddress(BUSXP1, PESB, DNPORT_FUN, 0x18), BUSXP1);
  AsiaPciWrite8(AsiaPciAddress(BUSXP1, PESB, DNPORT_FUN, 0x19), BUSXP2);
  AsiaPciWrite8(AsiaPciAddress(BUSXP1, PESB, DNPORT_FUN, 0x1A), BUSXP3);

  AsiaPciWrite8(AsiaPciAddress(BUSXP2, PCIEIF_DEV, PCIEIF_FUN, 0x18), BUSXP2);
  AsiaPciWrite8(AsiaPciAddress(BUSXP2, PCIEIF_DEV, PCIEIF_FUN, 0x19), BUSXP3);
  AsiaPciWrite8(AsiaPciAddress(BUSXP2, PCIEIF_DEV, PCIEIF_FUN, 0x1A), BUSXP3);	
	
	return EFI_SUCCESS;
}
#endif

#endif





#if 0
/*
	This function is reservd now
*/
STATIC
EFI_STATUS
IoePeiClearPciTemporary(
	IN EFI_PEI_SERVICES **PeiServices,
	IN RpBus,
	IN RpDev,
	IN RpFunc,
	IN SubBus
)
{
		
	return EFI_SUCCESS;
}
#endif



/*
CJW:
Since we need to access IOE's Standard-Configuration_Space
We need to assign temp PCI bus number
before PEI sb initialization stage.

Assignment after PCIE PTN:
     [__MB's_RP___]
		|
		|_________________________________Bus 1
		|
	____|____________
	[___Switch_UP____]
					|
					|_____________________Bus 2
					|
	________________|___________________
	[____PEB0_____________D8F0_________]
		|					|
		|					|_____________Bus 3
							|
					________|_______
					[___PCIEIF_____]
						|
						|_________________Bus 4
						|
					____|_______
					[___ISB____]
	
*/



/**
  !!!Usable range: After temp assignment
  
  Search to get the Device Number and Function Number of Rp which connected to IOE

  When Multi-IOE Support enabled, this routine will return the Device/Function number 
  of RP which connected to the first 'Unmasked' IOE
  
  @param   PeiServices   PEI servervices
  @param   Devx   Device Number of RP which connected to IOE
  @param   Funx   Function Number of RP which connected to IOE

  @return   EFI_SUCCESS   found IOE, and Devx and Funx was valid.
  @return   EFI_NOT_FOUND   not found IOE, and Devx and Funx was invalid.
**/

EFI_STATUS
IoeGetRpToFindIoe(
	IN EFI_PEI_SERVICES **PeiServices,	
	IN OUT UINT8 *Devx, 
	IN OUT UINT8 *Funx )
{
	UINT8 ts;
	UINT8 SecBus;
	UINT32 VidDid;
	
	for(ts = 0; ts < (sizeof(IoeSearchTbl)/sizeof(SEARCH_TBL)); ts++){

		SecBus = AsiaPciRead8(AsiaPciAddress(IoeSearchTbl[ts].BusNum,IoeSearchTbl[ts].DevNum,IoeSearchTbl[ts].FunNum, 0x19));
		if((SecBus != 0)&&(SecBus != 0xFF)){
			VidDid = AsiaPciRead32(AsiaPciAddress(SecBus,0,0, 0x00));
			if((VidDid == IOEBUSXUSP_VIDDID)||(VidDid == IOEBUSXUSP_VIDDID_ZX)||(VidDid == IOEBUSXUSP_VIDDID_ZERO)){
#if MULTI_IOE_SUPPORT				
				if(!IoeIsUsablePort(PeiServices,IoeSearchTbl[ts].BusNum,IoeSearchTbl[ts].DevNum,IoeSearchTbl[ts].FunNum)){
					continue;
				}
#endif				
				*Devx = IoeSearchTbl[ts].DevNum;
				*Funx = IoeSearchTbl[ts].FunNum;
				PEI_DEBUG((PeiServices, EFI_D_ERROR, "[CJW_IOE] ->Ioe behind the [0|%d|%d]\n",IoeSearchTbl[ts].DevNum,IoeSearchTbl[ts].FunNum));
				return EFI_SUCCESS;				
			}
		}
	}
	PEI_DEBUG((PeiServices, EFI_D_ERROR, "[CJW_IOE] ->Ioe behind the [0|?|?]\n"));
	return EFI_NOT_FOUND;
}

/**
  !!!Usable range: Out of temp assignment
  
  Search to get the Device Number of RP which connected to IOE

  When Multi-IOE Support enabled, this routine will return the Device number 
  of RP which connected to the first 'Unmasked' IOE
  
  @param   PeiServices   PEI servervices

  @return  FunctionNumber  Function number of RP which connected to the first 'Unmasked' IOE
**/

UINT8 
IoeGetRpToFindIoe_GetDev(IN EFI_PEI_SERVICES **PeiServices)
{
	EFI_STATUS Statusx = EFI_NOT_FOUND;
	UINT8 a = 0, b = 0;
	UINT8 ts;

	for(ts = 0; ts < (sizeof(IoeSearchTbl)/sizeof(SEARCH_TBL)); ts++){
		AsiaPciWrite8(AsiaPciAddress(IoeSearchTbl[ts].BusNum,IoeSearchTbl[ts].DevNum,IoeSearchTbl[ts].FunNum,0x18), BUS0);
		AsiaPciWrite8(AsiaPciAddress(IoeSearchTbl[ts].BusNum,IoeSearchTbl[ts].DevNum,IoeSearchTbl[ts].FunNum,0x19), BUSX);
		AsiaPciWrite8(AsiaPciAddress(IoeSearchTbl[ts].BusNum,IoeSearchTbl[ts].DevNum,IoeSearchTbl[ts].FunNum,0x1A), BUSX);

		Statusx = IoeGetRpToFindIoe(PeiServices, &a, &b);
		if(Statusx == EFI_SUCCESS){
#if MULTI_IOE_SUPPORT			
			if(!IoeIsUsablePort(PeiServices,IoeSearchTbl[ts].BusNum,IoeSearchTbl[ts].DevNum,IoeSearchTbl[ts].FunNum)){
				Statusx = EFI_NOT_FOUND;
				AsiaPciWrite8(AsiaPciAddress(IoeSearchTbl[ts].BusNum,IoeSearchTbl[ts].DevNum,IoeSearchTbl[ts].FunNum,0x18), 0);
				AsiaPciWrite8(AsiaPciAddress(IoeSearchTbl[ts].BusNum,IoeSearchTbl[ts].DevNum,IoeSearchTbl[ts].FunNum,0x19), 0);
				AsiaPciWrite8(AsiaPciAddress(IoeSearchTbl[ts].BusNum,IoeSearchTbl[ts].DevNum,IoeSearchTbl[ts].FunNum,0x1A), 0);	
				continue;
			}		
#endif			
			PEI_DEBUG((PeiServices, EFI_D_ERROR, "[CJW_IOE] ->Dev:%d\n",IoeSearchTbl[ts].DevNum));
			AsiaPciWrite8(AsiaPciAddress(IoeSearchTbl[ts].BusNum,IoeSearchTbl[ts].DevNum,IoeSearchTbl[ts].FunNum,0x18), 0);
			AsiaPciWrite8(AsiaPciAddress(IoeSearchTbl[ts].BusNum,IoeSearchTbl[ts].DevNum,IoeSearchTbl[ts].FunNum,0x19), 0);
			AsiaPciWrite8(AsiaPciAddress(IoeSearchTbl[ts].BusNum,IoeSearchTbl[ts].DevNum,IoeSearchTbl[ts].FunNum,0x1A), 0);
			return (IoeSearchTbl[ts].DevNum);
		}
		AsiaPciWrite8(AsiaPciAddress(IoeSearchTbl[ts].BusNum,IoeSearchTbl[ts].DevNum,IoeSearchTbl[ts].FunNum,0x18), 0);
		AsiaPciWrite8(AsiaPciAddress(IoeSearchTbl[ts].BusNum,IoeSearchTbl[ts].DevNum,IoeSearchTbl[ts].FunNum,0x19), 0);
		AsiaPciWrite8(AsiaPciAddress(IoeSearchTbl[ts].BusNum,IoeSearchTbl[ts].DevNum,IoeSearchTbl[ts].FunNum,0x1A), 0);		
	}
	PEI_DEBUG((PeiServices, EFI_D_ERROR, "[CJW_IOE] ->ERROR!!! No IOE Found!\n"));
	return 0xFF;
}


/**
  !!!Usable range: Out of temp assignment
  
  Search to get the Function Number of RP which connected to IOE

  When Multi-IOE Support enabled, this routine will return the Function number 
  of RP which connected to the first 'Unmasked' IOE
  
  @param   PeiServices   PEI servervices

  @return  FunctionNumber  Function number of RP which connected to the first 'Unmasked' IOE
**/
UINT8 
IoeGetRpToFindIoe_GetFun(IN EFI_PEI_SERVICES **PeiServices)
{
	EFI_STATUS Statusx = EFI_NOT_FOUND;
	UINT8 a = 0, b = 0;
	UINT8 ts;

	for(ts = 0; ts < (sizeof(IoeSearchTbl)/sizeof(SEARCH_TBL)); ts++){
		AsiaPciWrite8(AsiaPciAddress(IoeSearchTbl[ts].BusNum,IoeSearchTbl[ts].DevNum,IoeSearchTbl[ts].FunNum,0x18), BUS0);
		AsiaPciWrite8(AsiaPciAddress(IoeSearchTbl[ts].BusNum,IoeSearchTbl[ts].DevNum,IoeSearchTbl[ts].FunNum,0x19), BUSX);
		AsiaPciWrite8(AsiaPciAddress(IoeSearchTbl[ts].BusNum,IoeSearchTbl[ts].DevNum,IoeSearchTbl[ts].FunNum,0x1A), BUSX);

		Statusx = IoeGetRpToFindIoe(PeiServices, &a, &b);
		if(Statusx == EFI_SUCCESS){
#if MULTI_IOE_SUPPORT			
			if(!IoeIsUsablePort(PeiServices,IoeSearchTbl[ts].BusNum,IoeSearchTbl[ts].DevNum,IoeSearchTbl[ts].FunNum)){
				Statusx = EFI_NOT_FOUND;
				AsiaPciWrite8(AsiaPciAddress(IoeSearchTbl[ts].BusNum,IoeSearchTbl[ts].DevNum,IoeSearchTbl[ts].FunNum,0x18), 0);
				AsiaPciWrite8(AsiaPciAddress(IoeSearchTbl[ts].BusNum,IoeSearchTbl[ts].DevNum,IoeSearchTbl[ts].FunNum,0x19), 0);
				AsiaPciWrite8(AsiaPciAddress(IoeSearchTbl[ts].BusNum,IoeSearchTbl[ts].DevNum,IoeSearchTbl[ts].FunNum,0x1A), 0);					
				continue;
			}
#endif			
			PEI_DEBUG((PeiServices, EFI_D_ERROR, "[CJW_IOE] ->Func:%d\n",IoeSearchTbl[ts].FunNum));
			AsiaPciWrite8(AsiaPciAddress(IoeSearchTbl[ts].BusNum,IoeSearchTbl[ts].DevNum,IoeSearchTbl[ts].FunNum,0x18), 0);
			AsiaPciWrite8(AsiaPciAddress(IoeSearchTbl[ts].BusNum,IoeSearchTbl[ts].DevNum,IoeSearchTbl[ts].FunNum,0x19), 0);
			AsiaPciWrite8(AsiaPciAddress(IoeSearchTbl[ts].BusNum,IoeSearchTbl[ts].DevNum,IoeSearchTbl[ts].FunNum,0x1A), 0);			
			return (IoeSearchTbl[ts].FunNum);
		}
		AsiaPciWrite8(AsiaPciAddress(IoeSearchTbl[ts].BusNum,IoeSearchTbl[ts].DevNum,IoeSearchTbl[ts].FunNum,0x18), 0);
		AsiaPciWrite8(AsiaPciAddress(IoeSearchTbl[ts].BusNum,IoeSearchTbl[ts].DevNum,IoeSearchTbl[ts].FunNum,0x19), 0);
		AsiaPciWrite8(AsiaPciAddress(IoeSearchTbl[ts].BusNum,IoeSearchTbl[ts].DevNum,IoeSearchTbl[ts].FunNum,0x1A), 0);
	}
	PEI_DEBUG((PeiServices, EFI_D_ERROR, "[CJW_IOE] ->ERROR!!! No IOE Found!\n"));
	return 0xFF;

}





STATIC
EFI_STATUS
IoeBeforePeiInit(
	IN EFI_PEI_SERVICES **PeiServices,
	UINT8 *TblOffset
)
{
	EFI_STATUS Status = EFI_NOT_FOUND;
	UINT8 ts;

	//PEI_DEBUG((PeiServices, EFI_D_ERROR, "\n[CJW_IOE] IoeBeforePeiInit(): Search IOE's Location\n"));
	
	for(ts = 0; ts < (sizeof(IoeSearchTbl)/sizeof(SEARCH_TBL)); ts++){
		//PEI_DEBUG((PeiServices, EFI_D_ERROR, "[CJW_IOE] --\n"));
		
		//Search for IOE on each ports in list
		Status = IoeSearchPcieRpTemporary(PeiServices,IoeSearchTbl[ts].BusNum,IoeSearchTbl[ts].DevNum,IoeSearchTbl[ts].FunNum);
		if(Status == EFI_SUCCESS){
#if MULTI_IOE_SUPPORT			
			if(!IoeIsUsablePort(PeiServices,IoeSearchTbl[ts].BusNum,IoeSearchTbl[ts].DevNum,IoeSearchTbl[ts].FunNum)){
				Status = EFI_NOT_FOUND;
				continue;
			}
#endif			
#ifdef ASSIGN_DEBUG_EN
			//Found IOE
			PEI_DEBUG((PeiServices, EFI_D_ERROR, "[CJW_IOE] %a() Line%d: Found IOE! [%d|%d|%d]\n",
												__FUNCTION__,__LINE__,IoeSearchTbl[ts].BusNum,IoeSearchTbl[ts].DevNum,IoeSearchTbl[ts].FunNum));
#endif
			IoePeiAssignPciTemporary(PeiServices,IoeSearchTbl[ts].BusNum,IoeSearchTbl[ts].DevNum,IoeSearchTbl[ts].FunNum); //Assign temp resource for IOE

			//return Status; 
			goto __FoundIoe;	//stop to scan the else target in list.
		}else{
			//PEI_DEBUG((PeiServices, EFI_D_ERROR, "[CJW_IOE] %a() Line%d: Not Found IOE [%d|%d|%d]\n",
			//									__FUNCTION__,__LINE__,IoeSearchTbl[ts].BusNum,IoeSearchTbl[ts].DevNum,IoeSearchTbl[ts].FunNum));	
		}	

	}

__FoundIoe:    
	//Print some Status
	/*PEI_DEBUG((PeiServices, EFI_D_ERROR, "[CJW_IOE_p] BusNumberOfBusX = %d\n",BusNumberOfBusX));
	PEI_DEBUG((PeiServices, EFI_D_ERROR,   "            BUSNumberOfBusXp2 = %d\n",BUSNumberOfBusXp2));
	PEI_DEBUG((PeiServices, EFI_D_ERROR,   "            IoeSubBusNumber = %d\n",IoeSubBusNumber));
	PEI_DEBUG((PeiServices, EFI_D_ERROR,   "            IoeConnectDevNum = %d\n",IoeConnectDevNum));
	PEI_DEBUG((PeiServices, EFI_D_ERROR,   "            IoeConnectFunNum = %d\n",IoeConnectFunNum));*/
	if(TblOffset != NULL){
		*TblOffset = ts;  
	}
	
	return Status;
}


/*
Before calling this function
we must confirm that we have found the IOE
*/
STATIC
EFI_STATUS
IoeAfterPeiInit(
	IN EFI_PEI_SERVICES **PeiServices,
	UINT8 *TblOffset
)
{
	EFI_STATUS Status = EFI_NOT_FOUND;
	UINT8 ts;
	UINT8 SubBusAssign;
	UINT8 Gbus,Gdev,Gfunc;

#ifdef ASSIGN_DEBUG_EN		//for test whether read IOE cfg space is ok  - For debug
	UINT8 Tmp8;
	Tmp8 = AsiaPciRead8(AsiaPciAddress(BUSX, UPPORT_DEV, UPPORT_FUN, 0x18));
	PEI_DEBUG((PeiServices, EFI_D_ERROR, "[CJW_IOE_DEBUG] Read from [%d|%d|%d] Rx18=%02X\n",BUSX, UPPORT_DEV, UPPORT_FUN,Tmp8));

	//for abnormal situation, dump cfg space
	if((Tmp8 != 0x01)&&(Tmp8 != 0xFF)){
		
		PEI_DEBUG((PeiServices, EFI_D_ERROR, "[CJW_IOE] Error-DebugMessage:\n"));
		IoeGetRpToFindIoe(PeiServices, &Gdev, &Gfunc);
		PEI_DEBUG((PeiServices, EFI_D_ERROR, "[CJW_IOE] [0|%d|%d]\n",Gdev, Gfunc));
		IoeDumpCfg(PeiServices, PCI_BASE, 0, Gdev, Gfunc, 0x200);

	
		PEI_DEBUG((PeiServices, EFI_D_ERROR, "[CJW_IOE] [BUSX|0|0]\n"));
		IoeDumpCfg(PeiServices, PCI_BASE, BUSX, UPPORT_DEV, UPPORT_FUN, 0x200);


		PEI_DEBUG((PeiServices, EFI_D_ERROR, "[CJW_IOE] [BUSX+1|0|0]\n"));
		IoeDumpCfg(PeiServices, PCI_BASE, BUSXP1, XBCTL, DNPORT_FUN,0x200);


		PEI_DEBUG((PeiServices, EFI_D_ERROR, "[CJW_IOE] [BUSX+1|1|0]\n"));
		IoeDumpCfg(PeiServices, PCI_BASE, BUSXP1, PEA0, DNPORT_FUN,0x200);


		PEI_DEBUG((PeiServices, EFI_D_ERROR, "[CJW_IOE] [BUSX+1|2|0]\n"));
		IoeDumpCfg(PeiServices, PCI_BASE, BUSXP1, PEA1, DNPORT_FUN,0x200);
		

		PEI_DEBUG((PeiServices, EFI_D_ERROR, "[CJW_IOE] [BUSX+1|3|0]\n"));
		IoeDumpCfg(PeiServices, PCI_BASE, BUSXP1, PEA2, DNPORT_FUN,0x200);

		
		PEI_DEBUG((PeiServices, EFI_D_ERROR, "[CJW_IOE] [BUSX+1|4|0]\n"));
		IoeDumpCfg(PeiServices, PCI_BASE, BUSXP1, PEA3, DNPORT_FUN,0x200);


		PEI_DEBUG((PeiServices, EFI_D_ERROR, "[CJW_IOE] [BUSX+1|5|0]\n"));
		IoeDumpCfg(PeiServices, PCI_BASE, BUSXP1, PEA4, DNPORT_FUN,0x200);

		
		PEI_DEBUG((PeiServices, EFI_D_ERROR, "[CJW_IOE] [BUSX+1|6|0]\n"));
		IoeDumpCfg(PeiServices, PCI_BASE, BUSXP1, PEB0, DNPORT_FUN,0x200);			

	
		PEI_DEBUG((PeiServices, EFI_D_ERROR, "[CJW_IOE] [BUSX+1|7|0]\n"));
		IoeDumpCfg(PeiServices, PCI_BASE, BUSXP1, PEB1, DNPORT_FUN,0x200);


		PEI_DEBUG((PeiServices, EFI_D_ERROR, "[CJW_IOE] [BUSX+1|8|0]\n"));
		IoeDumpCfg(PeiServices, PCI_BASE, BUSXP1, PESB, DNPORT_FUN,0x200);


		PEI_DEBUG((PeiServices, EFI_D_ERROR, "[CJW_IOE] [BUSX+2|0|0]\n"));
		IoeDumpCfg(PeiServices, PCI_BASE, BUSXP2, PCIEIF_DEV, PCIEIF_FUN,0x200);

		//}
	}


	Tmp8 = AsiaPciRead8(AsiaPciAddress(BUSXP1, XBCTL, DNPORT_FUN, 0x18));
	PEI_DEBUG((PeiServices, EFI_D_ERROR, "                Read from [%d|%d|%d] Rx18=%02X\n",BUSXP1, XBCTL, DNPORT_FUN,Tmp8));
	Tmp8 = AsiaPciRead8(AsiaPciAddress(BUSXP1, PEA0, DNPORT_FUN, 0x18));
	PEI_DEBUG((PeiServices, EFI_D_ERROR, "                Read from [%d|%d|%d] Rx18=%02X\n",BUSXP1, PEA0, DNPORT_FUN,Tmp8));
	Tmp8 = AsiaPciRead8(AsiaPciAddress(BUSXP1, PEB0, DNPORT_FUN, 0x18));
	PEI_DEBUG((PeiServices, EFI_D_ERROR, "                Read from [%d|%d|%d] Rx18=%02X\n",BUSXP1, PEB0, DNPORT_FUN,Tmp8));
	Tmp8 = AsiaPciRead8(AsiaPciAddress(BUSXP1, PEB1, DNPORT_FUN, 0x18));
	PEI_DEBUG((PeiServices, EFI_D_ERROR, "                Read from [%d|%d|%d] Rx18=%02X\n",BUSXP1, PEB1, DNPORT_FUN,Tmp8));
	Tmp8 = AsiaPciRead8(AsiaPciAddress(BUSXP1, PESB, DNPORT_FUN, 0x18));
	PEI_DEBUG((PeiServices, EFI_D_ERROR, "                Read from [%d|%d|%d] Rx18=%02X\n",BUSXP1, PESB, DNPORT_FUN,Tmp8));	
	Tmp8 = AsiaPciRead8(AsiaPciAddress(BUSXP2, PCIEIF_DEV, PCIEIF_FUN, 0x18));
	PEI_DEBUG((PeiServices, EFI_D_ERROR, "                Read from [%d|%d|%d] Rx18=%02X\n",BUSXP2, PCIEIF_DEV, PCIEIF_FUN,Tmp8));	
	Tmp8 = AsiaPciRead8(AsiaPciAddress(BUSXP3, EPTRFC_DEV, EPTRFC_FUN, 0x18));
	PEI_DEBUG((PeiServices, EFI_D_ERROR, "                Read from [%d|%d|%d] Rx18=%02X\n",BUSXP3, EPTRFC_DEV, EPTRFC_FUN,Tmp8));
	PEI_DEBUG((PeiServices, EFI_D_ERROR, "                Read from [%d|%d|%d] Rx00=%08X\n",BUSXP3, EPTRFC_DEV, EPTRFC_FUN,
															AsiaPciRead32(AsiaPciAddress(BUSXP3, EPTRFC_DEV, EPTRFC_FUN, 0x00))));	
#endif



	
	//[1] Get to know the PCIe RP number connected to IOE
	//PEI_DEBUG((PeiServices, EFI_D_ERROR, "\n[CJW_IOE] IoeAfterPeiInit(): Search IOE's Location\n"));
	
	for(ts = 0; ts < (sizeof(IoeSearchTbl)/sizeof(SEARCH_TBL)); ts++){
		//PEI_DEBUG((PeiServices, EFI_D_ERROR, "[CJW_IOE] --\n"));
		
		//Search for IOE on each ports in list
		Status = IoeSearchPcieRpTemporary(PeiServices,IoeSearchTbl[ts].BusNum,IoeSearchTbl[ts].DevNum,IoeSearchTbl[ts].FunNum);
		if(Status == EFI_SUCCESS){
#if MULTI_IOE_SUPPORT			
			if(!IoeIsUsablePort(PeiServices,IoeSearchTbl[ts].BusNum,IoeSearchTbl[ts].DevNum,IoeSearchTbl[ts].FunNum)){
				Status = EFI_NOT_FOUND;
				continue;
			}
#endif			
			//Found IOE
				
			goto __FoundIoe2;	//stop to scan the else target in list.
		}else{
			//PEI_DEBUG((PeiServices, EFI_D_ERROR, "[CJW_IOE] %a() Line%d: Not Found IOE [%d|%d|%d]\n",
			//									__FUNCTION__,__LINE__,IoeSearchTbl[ts].BusNum,IoeSearchTbl[ts].DevNum,IoeSearchTbl[ts].FunNum));		
		}	

	}

	if(ts >= (sizeof(IoeSearchTbl)/sizeof(SEARCH_TBL))){
		goto __FailToFindIoe2;
	}

__FoundIoe2:
	if(TblOffset != NULL){
		*TblOffset = ts;
	}

	Gbus = IoeSearchTbl[ts].BusNum;
	Gdev = IoeSearchTbl[ts].DevNum;
	Gfunc = IoeSearchTbl[ts].FunNum;

	//[2] Find out the Subordinate Bus Number of IOE tree
	SubBusAssign = AsiaPciRead8(AsiaPciAddress(Gbus, Gdev, Gfunc, 0x1A));
	//PEI_DEBUG((PeiServices, EFI_D_ERROR, "[CJW_IOE]   -SubBusNum[Rx1A] on MB RP is %d\n",SubBusAssign));

	//[3] Clear all temp assignment
	{
		UINT8 Bus,Dev,SubBus;
		UINT16 ClassCode,Vid;
		SubBus = SubBusAssign;
		for(Bus = SubBus; Bus >= 1; Bus--){
			for(Dev = 0; Dev < 32; Dev++){

				//CJW_20181114 IOE CodeBusRepair_Item1_(3/3)
				//IOE XHCI(BusXp3 D18F0) can't be accessed before CFGDONE set to 1b
				// to avoid accessing IOE XHCI, We not touch it no matter CFGDONE is 1 or 0b
				// here is the patch code for this issue(SKIP Accessing All BusN D18F0)
				if(Dev == 18){
					continue;
				}
				
				Vid = AsiaPciRead16(AsiaPciAddress(Bus, Dev, 0, 0x00));
				if(Vid == 0xFFFF){
					continue;
				}
				ClassCode = AsiaPciRead16(AsiaPciAddress(Bus, Dev, 0, 0x0A));
				if(ClassCode == 0x0604){
					//CJW_20181114 IOE CodeBusRepair_Item2_(1/1)
					// Clear all assignment bus number on Rx18/19/1A
					AsiaPciWrite8(AsiaPciAddress(Bus, Dev, 0, 0x18), 0); //clear the bus number
					AsiaPciWrite8(AsiaPciAddress(Bus, Dev, 0, 0x19), 0); 
					AsiaPciWrite8(AsiaPciAddress(Bus, Dev, 0, 0x1A), 0); 
				}
			}
		}
		//We must clear the RP's Pri/Sec/Sub bus number. otherwise , it will hang in PeiNbPcieInit();
		AsiaPciWrite8(AsiaPciAddress(Gbus, Gdev, Gfunc, 0x18), 0); //clear the bus number
		AsiaPciWrite8(AsiaPciAddress(Gbus, Gdev, Gfunc, 0x19), 0); 
		AsiaPciWrite8(AsiaPciAddress(Gbus, Gdev, Gfunc, 0x1A), 0); 
	}

	PEI_DEBUG((PeiServices, EFI_D_ERROR, "[CJW_IOE] <P> Clear temp assinment done for IOE\n"));
	return EFI_SUCCESS;
	
__FailToFindIoe2:
	PEI_DEBUG((PeiServices, EFI_D_ERROR, "[CJW_IOE] <P> Could not find IOE, No need to clear them\n"));

	return EFI_SUCCESS;
}



RegSet AssignTempx[] = {
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


//Temp Assignment 
STATIC
EFI_STATUS
IoeTA(
	IN EFI_PEI_SERVICES **PeiServices)
{
	UINT16 ix;
	PEI_DEBUG((PeiServices, EFI_D_ERROR,"[CJW_IOE_ASSIGN] =>:: Resource assignment\n"));
	for(ix = 0; ix < sizeof(AssignTempx)/sizeof(RegSet); ix++){
		if(AssignTempx[ix].ByteCount  == SET_4BYTE){
			AsiaPciModify32(
				AsiaPciAddress(AssignTempx[ix].Busx, AssignTempx[ix].Devx, AssignTempx[ix].Funx, AssignTempx[ix].Offsetx), 
				AssignTempx[ix].Maskx, AssignTempx[ix].Valuex);
			//PEI_DEBUG((PeiServices,EFI_D_ERROR, "                 => [%d|%d|%d] Rx%x=0x%08x\n\r",
			//	AssignTempx[ix].Busx,AssignTempx[ix].Devx,AssignTempx[ix].Funx,AssignTempx[ix].Offsetx,
			//	AsiaPciRead32(AsiaPciAddress(AssignTempx[ix].Busx, AssignTempx[ix].Devx, AssignTempx[ix].Funx, AssignTempx[ix].Offsetx))));
		}else if(AssignTempx[ix].ByteCount  == SET_1BYTE){
			AsiaPciModify8(
				AsiaPciAddress(AssignTempx[ix].Busx, AssignTempx[ix].Devx, AssignTempx[ix].Funx, AssignTempx[ix].Offsetx), 
				(UINT8)(AssignTempx[ix].Maskx), (UINT8)(AssignTempx[ix].Valuex));		
			//PEI_DEBUG((PeiServices,EFI_D_ERROR, "                 => [%d|%d|%d] Rx%x=0x%02x\n\r",
			//	AssignTempx[ix].Busx, AssignTempx[ix].Devx, AssignTempx[ix].Funx, AssignTempx[ix].Offsetx,
			//	AsiaPciRead8(AsiaPciAddress(AssignTempx[ix].Busx, AssignTempx[ix].Devx, AssignTempx[ix].Funx, AssignTempx[ix].Offsetx))));
		}else{
			PEI_DEBUG((PeiServices,EFI_D_ERROR, "[CJW_IOE_ASSIGN] Bad ByteCount!\n"));
		}
	}	
	return EFI_SUCCESS;
}



//
/**
   IoeTAC.

   Temp assigment clear
   
  @param  PeiServices	EFI_PEI_SERVICES pointer.

  @return EFI_STATUS.

**/

STATIC
EFI_STATUS
IoeTAC(
	IN EFI_PEI_SERVICES **PeiServices)
{
	UINT16 ix;
	PEI_DEBUG((PeiServices, EFI_D_ERROR,"[CJW_IOE_CLEAR] ::<= Resource assignment clear\n"));
	for(ix = 0; ix < sizeof(AssignTempx)/sizeof(RegSet); ix++){
		if(AssignTempx[ix].ByteCount  == SET_4BYTE){
			AsiaPciModify32(
				AsiaPciAddress(AssignTempx[ix].Busx, AssignTempx[ix].Devx, AssignTempx[ix].Funx, AssignTempx[ix].Offsetx), 
				AssignTempx[ix].Maskx, 0);
			//PEI_DEBUG((PeiServices, EFI_D_ERROR,"                => [%d|%d|%d] Rx%x=0x%08x\n\r",
			//	AssignTempx[ix].Busx,AssignTempx[ix].Devx,AssignTempx[ix].Funx,AssignTempx[ix].Offsetx,
			//	AsiaPciRead32(AsiaPciAddress(AssignTempx[ix].Busx, AssignTempx[ix].Devx, AssignTempx[ix].Funx, AssignTempx[ix].Offsetx))));
		}else if(AssignTempx[ix].ByteCount  == SET_1BYTE){
			AsiaPciModify8(
				AsiaPciAddress(AssignTempx[ix].Busx, AssignTempx[ix].Devx, AssignTempx[ix].Funx, AssignTempx[ix].Offsetx), 
				(UINT8)(AssignTempx[ix].Maskx), 0);		
			//PEI_DEBUG((PeiServices,EFI_D_ERROR, "                => [%d|%d|%d] Rx%x=0x%02x\n\r",
			//	AssignTempx[ix].Busx,AssignTempx[ix].Devx,AssignTempx[ix].Funx,AssignTempx[ix].Offsetx,
			//	AsiaPciRead8(AsiaPciAddress(AssignTempx[ix].Busx, AssignTempx[ix].Devx, AssignTempx[ix].Funx, AssignTempx[ix].Offsetx))));
		}else{
			PEI_DEBUG((PeiServices, EFI_D_ERROR,"[CJW_IOE_CLEAR] Bad ByteCount!\n"));
		}
	}	
	return EFI_SUCCESS;
}


EFI_STATUS
IoePeiTempAssignment(
	IN EFI_PEI_SERVICES **PeiServices)
{
	UINT8 Tblx;
	EFI_STATUS Statusx = EFI_NOT_FOUND;

	PEI_DEBUG((PeiServices, EFI_D_ERROR,"[CJW_IOE]-------------------------------------------------------------------------------------> \n"));
	PEI_DEBUG((PeiServices, EFI_D_ERROR,"         ------------------------------------------------------------------------------------->Assign Start\n"));
	
	Statusx = IoeBeforePeiInit(PeiServices,&Tblx);
	if(Statusx == EFI_NOT_FOUND)
		return Statusx;
	AsiaPciModify8(AsiaPciAddress(IoeSearchTbl[Tblx].BusNum, IoeSearchTbl[Tblx].DevNum, IoeSearchTbl[Tblx].FunNum, 0x04), 0x07, 0x02);
	AsiaPciModify16(AsiaPciAddress(IoeSearchTbl[Tblx].BusNum, IoeSearchTbl[Tblx].DevNum, IoeSearchTbl[Tblx].FunNum, 0x20), 0xFFFF, RP_MEM_BASE);
	AsiaPciModify16(AsiaPciAddress(IoeSearchTbl[Tblx].BusNum, IoeSearchTbl[Tblx].DevNum, IoeSearchTbl[Tblx].FunNum, 0x22), 0xFFFF, RP_MEM_LIMIT);

	IoeTA(PeiServices);

	//;cjw-A0-debug 20161202
	PEI_DEBUG((PeiServices, EFI_D_ERROR,"         [CJW_IOE] Rx18 = 0x%08x(PEEP)\n",AsiaPciRead32(AsiaPciAddress(BUSX, UPPORT_DEV, UPPORT_FUN, 0x18))));
	PEI_DEBUG((PeiServices, EFI_D_ERROR,"         [CJW_IOE] Rx18 = 0x%08x(XBCTL)\n",AsiaPciRead32(AsiaPciAddress(BUSXP1, XBCTL, DNPORT_FUN, 0x18))));
	PEI_DEBUG((PeiServices, EFI_D_ERROR,"         [CJW_IOE] Rx18 = 0x%08x(PEA0)\n",AsiaPciRead32(AsiaPciAddress(BUSXP1, PEA0, DNPORT_FUN, 0x18))));	
	PEI_DEBUG((PeiServices, EFI_D_ERROR,"         [CJW_IOE] Rx18 = 0x%08x(PEA1)\n",AsiaPciRead32(AsiaPciAddress(BUSXP1, PEA1, DNPORT_FUN, 0x18))));	
	PEI_DEBUG((PeiServices, EFI_D_ERROR,"         [CJW_IOE] Rx18 = 0x%08x(PEA2)\n",AsiaPciRead32(AsiaPciAddress(BUSXP1, PEA2, DNPORT_FUN, 0x18))));	
	PEI_DEBUG((PeiServices, EFI_D_ERROR,"         [CJW_IOE] Rx18 = 0x%08x(PEA3)\n",AsiaPciRead32(AsiaPciAddress(BUSXP1, PEA3, DNPORT_FUN, 0x18))));	
	PEI_DEBUG((PeiServices, EFI_D_ERROR,"         [CJW_IOE] Rx18 = 0x%08x(PEA4)\n",AsiaPciRead32(AsiaPciAddress(BUSXP1, PEA4, DNPORT_FUN, 0x18))));	
	PEI_DEBUG((PeiServices, EFI_D_ERROR,"         [CJW_IOE] Rx18 = 0x%08x(PEB0)\n",AsiaPciRead32(AsiaPciAddress(BUSXP1, PEB0, DNPORT_FUN, 0x18))));	
	PEI_DEBUG((PeiServices, EFI_D_ERROR,"         [CJW_IOE] Rx18 = 0x%08x(PEB1)\n",AsiaPciRead32(AsiaPciAddress(BUSXP1, PEB1, DNPORT_FUN, 0x18))));	
	PEI_DEBUG((PeiServices, EFI_D_ERROR,"         [CJW_IOE] Rx18 = 0x%08x(PESB)\n",AsiaPciRead32(AsiaPciAddress(BUSXP1, PESB, DNPORT_FUN, 0x18))));	
	PEI_DEBUG((PeiServices, EFI_D_ERROR,"         [CJW_IOE] Rx18 = 0x%08x(PCIEIF)\n",AsiaPciRead32(AsiaPciAddress(BUSXP2, PCIEIF_DEV, PCIEIF_FUN, 0x18))));	
	//;cjw-A0-debug END
	
	return Statusx;
}


VOID
IoePeiClearTempAssignment(
	IN EFI_PEI_SERVICES **PeiServices)
{
	UINT8 Tblx;
	
	IoeTAC(PeiServices);
	IoeAfterPeiInit(PeiServices,&Tblx);

	AsiaPciModify8(AsiaPciAddress(IoeSearchTbl[Tblx].BusNum, IoeSearchTbl[Tblx].DevNum, IoeSearchTbl[Tblx].FunNum, 0x04), 0x07, 0x00);
	AsiaPciModify16(AsiaPciAddress(IoeSearchTbl[Tblx].BusNum, IoeSearchTbl[Tblx].DevNum, IoeSearchTbl[Tblx].FunNum, 0x20), 0xFFFF, 0);
	AsiaPciModify16(AsiaPciAddress(IoeSearchTbl[Tblx].BusNum, IoeSearchTbl[Tblx].DevNum, IoeSearchTbl[Tblx].FunNum, 0x22), 0xFFFF, 0);
	
	PEI_DEBUG((PeiServices, EFI_D_ERROR,"         <------------------------------------------------------------------------------------Clear Assignment\n"));
	PEI_DEBUG((PeiServices, EFI_D_ERROR,"[CJW_IOE]<------------------------------------------------------------------------------------\n"));
}



/**************************************************************************
// CND003 PHY Configure
**************************************************************************/
/**
   IoeSetPciePhyDriving.

   This function used to set SI setting 
   
  @param  PeiServices	EFI_PEI_SERVICES pointer.
  @param NbCfg point to ASIA_NB_CONFIGURATION struct

  @return VOID.

**/

STATIC
VOID
IoeSetPciePhyDriving(
    IN EFI_PEI_SERVICES **PeiServices,
    IN ASIA_NB_CONFIGURATION *NbConfig,
    IN UINT32 MmioBarx)
{
	SI_PCIE_PHY_CND003DRIVING_ITEM *Item2;  

    UINTN   Index;
    UINTN   Inner1Index;
    UINT8   ChipRevision;
	UINT8 bData8;
	PEI_DEBUG((PeiServices, EFI_D_ERROR,"--IOE SI Driving--\n"));
    //Get chipset revision
    //ChipRevision = NbConfig->ChipRevision;
    ChipRevision = AsiaPciRead8(AsiaPciAddress(BUSX, UPPORT_DEV, UPPORT_FUN, CND003_BUSX_D0F0_INTERNAL_REV_ID));


	//Fetch different table depend on ChipRevision
	if(ChipRevision == IOE_REVISION_A0){
		PEI_DEBUG((PeiServices, EFI_D_ERROR,"--A0--\n"));
		
	    for (Index = 0; Index < PcieCND003DrivingTblItems_A0; Index++) {
	    	Item2 = &PcieCND003DrivingTbl_A0[Index];
			//bData16 = IoeShiftToMaskBit(Item2->Mask, Item2->Value); 
			bData8 = Item2->Value;
			switch (Item2->RegType){
	       	case PCIEPHYREGDETECT_DEF:
				
				AsiaMemoryModify8(MmioBarx|Item2->RegisterNum , Item2->Mask, bData8);
				//PEI_DEBUG((PeiServices, EFI_D_ERROR, "[CJW_IOE] 0x%08x\n",AsiaMemoryRead32(MmioBarx + 0x314)));
	         	break;
	      	case PCIEPHYREGDETECT_CONT : 
				for(Inner1Index = 0; Inner1Index < Item2->RegLoop; Inner1Index ++)
			   		AsiaMemoryModify8(MmioBarx |(Item2->RegisterNum + Inner1Index) , Item2->Mask, bData8);
	      		break;
	      	case PCIEPHYREGDETECT_EVEN : 
				for(Inner1Index = 0; Inner1Index < Item2->RegLoop; Inner1Index ++){
					//PEI_DEBUG((PeiServices, EFI_D_ERROR, "[CJW_IOE--] 0x%04x,0x%04x,%02x,%02x\n",Item2->RegisterNum,(Item2->RegisterNum + (Inner1Index << 1)),Item2->Mask, bData8 ));
					AsiaMemoryModify8(MmioBarx +(Item2->RegisterNum + (Inner1Index << 1)) , Item2->Mask, bData8);
					
					//PEI_DEBUG((PeiServices, EFI_D_ERROR, "[CJW_IOE]Res 0x%08x\n",AsiaMemoryRead32((MmioBarx + (Item2->RegisterNum + (Inner1Index << 1)) )&0xFFFFFFFC) ));
				}
				//PEI_DEBUG((PeiServices, EFI_D_ERROR, "[CJW_IOE] 0x%08x\n",AsiaMemoryRead32(MmioBarx + 0x314)));
	         	break;
	     	case PCIEPHYREGDETECT_ODD :
				for(Inner1Index = 0; Inner1Index < Item2->RegLoop; Inner1Index ++){
					//PEI_DEBUG((PeiServices, EFI_D_ERROR, "[CJW_IOE++] 0x%04x,0x%04x,%02x,%02x\n",Item2->RegisterNum,(Item2->RegisterNum + (Inner1Index << 1)),Item2->Mask, bData8 ));
					AsiaMemoryModify8(MmioBarx +(Item2->RegisterNum + (Inner1Index << 1)) , Item2->Mask, bData8);
					
					//PEI_DEBUG((PeiServices, EFI_D_ERROR, "[CJW_IOE]Rus 0x%08x\n",AsiaMemoryRead32((MmioBarx + (Item2->RegisterNum + (Inner1Index << 1)) )&0xFFFFFFFC) ));
				}
				//PEI_DEBUG((PeiServices, EFI_D_ERROR, "[CJW_IOE] 0x%08x\n",AsiaMemoryRead32(MmioBarx + 0x314)));
				break;
	        }

	  	}


		//SwDbg-1-0-SwDbg-2-TempDCGain
		//if((NbConfig->Cnd003SwDbg1 == 0)&&((NbConfig->Cnd003SwDbg2) & BIT16)){
			//CJW- If not set those registers on A0 chip, Compliance Test PTC card link not stable on Gen2 link??,Designer agree to add in BIOS
			PEI_DEBUG((PeiServices, EFI_D_ERROR, "CJW_IOE_Patch: SwDbg-1-0-SwDbg-2-TempDCGain\n"));
			AsiaMemoryModify8(MmioBarx + 0x6A3, 0x3F, 0x1F);
			AsiaMemoryModify8(MmioBarx + 0x6A4, 0x3F, 0x1F);
			AsiaMemoryModify8(MmioBarx + 0x6A5, 0x3F, 0x1F);
			AsiaMemoryModify8(MmioBarx + 0x6A1, 0x3F, 0x1F);
		//}	
	
	}else if(ChipRevision == IOE_REVISION_A1){
		PEI_DEBUG((PeiServices, EFI_D_ERROR,"--A1--\n"));
		
	    for (Index = 0; Index < PcieCND003DrivingTblItems_A1; Index++) {
	    	Item2 = &PcieCND003DrivingTbl_A1[Index];
			//bData16 = IoeShiftToMaskBit(Item2->Mask, Item2->Value); 
			bData8 = Item2->Value;
			switch (Item2->RegType){
	       	case PCIEPHYREGDETECT_DEF:
				
				AsiaMemoryModify8(MmioBarx|Item2->RegisterNum , Item2->Mask, bData8);
				break;
	      	case PCIEPHYREGDETECT_CONT : 
				for(Inner1Index = 0; Inner1Index < Item2->RegLoop; Inner1Index ++)
			   		AsiaMemoryModify8(MmioBarx |(Item2->RegisterNum + Inner1Index) , Item2->Mask, bData8);
	      		break;
	      	case PCIEPHYREGDETECT_EVEN : 
				for(Inner1Index = 0; Inner1Index < Item2->RegLoop; Inner1Index ++){
					AsiaMemoryModify8(MmioBarx +(Item2->RegisterNum + (Inner1Index << 1)) , Item2->Mask, bData8);
					
				}
				break;
	     	case PCIEPHYREGDETECT_ODD :
				for(Inner1Index = 0; Inner1Index < Item2->RegLoop; Inner1Index ++){
					AsiaMemoryModify8(MmioBarx +(Item2->RegisterNum + (Inner1Index << 1)) , Item2->Mask, bData8);
				}
				break;
	        }

	  	}
				
	}else{
		PEI_DEBUG((PeiServices, EFI_D_ERROR,"--Unknown ChipRevision--\n"));
	}


	//SwDbg-1-0-SwDbg-2-DumpPhySi
	if((NbConfig->Cnd003SwDbg1 == 0)&&((NbConfig->Cnd003SwDbg2) & BIT5)){
		PEI_DEBUG((PeiServices, EFI_D_ERROR, "SwDbg-1-0-SwDbg-2-DumpPhySi\n"));
		IoeDumpMem(PeiServices, MmioBarx, 0x2000);
	}


}

STATIC
EFI_STATUS
IoeWaitLinkStable(	
	IN EFI_PEI_SERVICES  **PeiServices,
	ASIA_NB_CONFIGURATION *NbConfig)
{

	//;cjw-A0-debug 20161129
	UINT8 Temp8;
	UINT8 Temp81;
	UINT8 counter = 0;
	UINT8 Wdev = 0,Wfunc = 0;
	EFI_STATUS Statusx = EFI_SUCCESS;


	
	//Gen3 && DO_EQ
	if((NbConfig->Cnd003EpCap == 3)&&(NbConfig->Cnd003PcieEq == 2)){
		return EFI_SUCCESS;
	}


_recheckx:	
	counter++;
	if(counter >= 80){
		goto _goout;  //timeout!
	}
	PeiNbPcieStallx(PeiServices, 50);  //wait 50ms
	Statusx = IoeGetRpToFindIoe(PeiServices, &Wdev, &Wfunc);
	if(Statusx != EFI_SUCCESS)
		return Statusx;
	Temp8 = AsiaPcieRead8(PCI_BASE, AsiaPciAddress(0,Wdev,Wfunc, HOST_PHYLS_LTSSM_STATE));
	Temp81 =AsiaPcieRead8(PCI_BASE, AsiaPciAddress(0,Wdev,Wfunc, HOST_LINK_STA_1));
	if((Temp8 != HOST_PHYLS_State_L0)||((Temp81&0xF)!=(NbConfig->Cnd003EpCap))){
		//AsiaIoWrite8(0x80, WAIT_L0);

		PEI_DEBUG((PeiServices, EFI_D_ERROR, "[CJW_IOE] Temp8 = 0x%02x\n",Temp8));
		PEI_DEBUG((PeiServices, EFI_D_ERROR, "[CJW_IOE] Temp81 = 0x%02x\n",Temp81));
		PEI_DEBUG((PeiServices, EFI_D_ERROR, "[CJW_IOE] NbConfig->Cnd003EpCap = 0x%02x\n",NbConfig->Cnd003EpCap));
		
		AsiaPciModify8(AsiaPciAddress(0, Wdev,Wfunc, HOST_LINK_CTL_1), HOST_LCRL, HOST_LCRL); 	//retrain link
		//PeiNbPcieStallx(PeiServices, 8000);  //wait 50ms
		goto _recheckx;
	}
_goout:
		;
	//;cjw-A0-debug END

	return EFI_SUCCESS;
}

/*
This function need to be called after PEXRST#.
the correct sequence is:
	1. BIOS set CAP_VER to all IOE ports
	2. BIOS set BIOSMOD = 1 to quarantine SPI header influence
	3. PEXRST#
	4. PHY A/B CFG, and set PHY CFGDONE
	5. Set PEEP Rx1E9[2:1]  to support Gen3 if "Skip EQ" and  "Target Link Speed is Gen3"
Note:
	This function should be called in both <Code Boot Sequence> and <S3 Resume Sequence>
*/
STATIC
EFI_STATUS
IoePcieGen3Internal(
	IN EFI_PEI_SERVICES  **PeiServices,
	ASIA_NB_CONFIGURATION *NbConfig)
{
	EFI_STATUS Statusx = EFI_SUCCESS;
	UINT64 PcieBase;

	PcieBase = NbConfig->PcieBar; 
	PEI_DEBUG((PeiServices, EFI_D_ERROR, "[CJW_IOE] In IoePcieGen3Internal()\n"));
	PEI_DEBUG((PeiServices, EFI_D_ERROR, "          PcieBase = 0x%08x\n", PcieBase));


	if(NbConfig->Cnd003PcieEq == IOE_SKIP_EQ_MANUAL){
		// TODO: manual set preset or cursors

	}

	if(NbConfig->Cnd003PcieEq != IOE_DO_EQ){
	//Note: if Not DO_EQ, we never be care of the Equalization Process, 
	// 		only in Gen3 & DO_EQ case, we need to take care of the ordering 
	//		of register setting, now, LKTGLS can be target Gen3, but LKTGLS_VIA will 
	//		determaine the TS1/2 capability, the setting position of LKTGLS_VIA 
	// 		depend on the Cnd003PcieEq is DO_EQ or Not.
	//
		//Rx290[4]  Not do EQ Phase 2/3 , Vcc power
		AsiaPcieModify8(PcieBase, CND003_PEEP|((UINT64)CND003_BUSX_D0F0_MISC_CTL << 32) , CND003_BUSX_D0F0_RWTEXEPH23, 0);
	}


	if((NbConfig->Cnd003EpCap != 3) || ((NbConfig->Cnd003EpCap == 3)&&(NbConfig->Cnd003PcieEq != IOE_DO_EQ))){
	//Note: The only special case is ((Cnd003EpCap == Gen3)&(Cnd003PcieEq == DO_EQ)), in this case, 
	// 		we need to wait for 8051 FW autofill completion, only in that time, the TS1/2 can take 
	// 		<Support Gen3 Capability> messages, and then, equalization phase2/3 occurs 
		

		//Real Target Link Speed   Rx1E9[2:1] , Vcc Power
		AsiaPcieModify8(PcieBase,CND003_PEEP|((UINT64)CND003_BUSX_D0F0_LKTGLS_VIA_AND_NEED_EQTS << 32) , CND003_BUSX_D0F0_LKTGLS_VIA, (NbConfig->Cnd003EpCap)<<1);
	}
	


	return Statusx;
}




/**
	This function is for DO_EQ with table & manual
	
**/
// TODO: Update Setup and code
STATIC
EFI_STATUS
IoePcieGen3EphyInit(	
	IN EFI_PEI_SERVICES **PeiServices ,
	IN ASIA_NB_CONFIGURATION *NbConfig)
{
	UINT32 EphyBase;

	EphyBase = AsiaPciRead32(AsiaPciAddress(BUSX, UPPORT_DEV, UPPORT_FUN, CND003_BUSX_D0F0_LOWER_BASE_ADR));
	PEI_DEBUG((PeiServices, EFI_D_ERROR, "[CJW_IOE]%a - EPHY Base = 0x%08x\n",__FUNCTION__));

	//Set EQ Preset Manual
	if(NbConfig->Cnd003PcieEq == 2){  //if DO_EQ

		//
		// Set Preset
		//
		AsiaMemoryModify32(EphyBase + 0xF8, BIT31, BIT31);  //Preset valid flag

		AsiaMemoryModify32(EphyBase + 0xF8, BIT24, BIT24);  // Tx Preset index 0 = valid
		AsiaMemoryModify32(EphyBase + 0xF8, 0xF<<0, 8<<0);  //Tx Preset value = P8

		//AsiaMemoryModify32(EphyBase + 0xF8, BIT25, BIT25);  // Tx Preset index 1 = valid
		//AsiaMemoryModify32(EphyBase + 0xF8, 0xF<<4, 1<<4);  //Tx Preset value = P1
/*		
		//
		// Set Cursors
		//
		AsiaMemoryModify32(EphyBase + 0xC70, BIT24, BIT24);  //Cursor Group 0 valid
		AsiaMemoryModify32(EphyBase + 0xC70, 0xFF, 0x4);
		AsiaMemoryModify32(EphyBase + 0xC70, 0xFF<<8, 0x18<<8);
		AsiaMemoryModify32(EphyBase + 0xC70, 0xFF<<16, 0x2<<16);

		AsiaMemoryModify32(EphyBase + 0xC74, 0xFF, 0x2);
		AsiaMemoryModify32(EphyBase + 0xC74, 0xFF<<8, 0x18<<8);
		AsiaMemoryModify32(EphyBase + 0xC74, 0xFF<<16, 0x4<<16);

		AsiaMemoryModify32(EphyBase + 0xC78, 0xFF, 0x1);
		AsiaMemoryModify32(EphyBase + 0xC78, 0xFF<<8, 0x18<<8);
		AsiaMemoryModify32(EphyBase + 0xC78, 0xFF<<16, 0x5<<16);

		AsiaMemoryModify32(EphyBase + 0xC7c, 0xFF, 0x3);
		AsiaMemoryModify32(EphyBase + 0xC7c, 0xFF<<8, 0x18<<8);
		AsiaMemoryModify32(EphyBase + 0xC7c, 0xFF<<16, 0x3<<16);


		
		AsiaMemoryModify32(EphyBase + 0xC80, BIT24, BIT24);  //Cursor Group 1 valid
		AsiaMemoryModify32(EphyBase + 0xC80, 0xFF, 0x1);
		AsiaMemoryModify32(EphyBase + 0xC80, 0xFF<<8, 0x16<<8);
		AsiaMemoryModify32(EphyBase + 0xC80, 0xFF<<16, 0x1<<16);

		AsiaMemoryModify32(EphyBase + 0xC84, 0xFF, 0x2);
		AsiaMemoryModify32(EphyBase + 0xC84, 0xFF<<8, 0x16<<8);
		AsiaMemoryModify32(EphyBase + 0xC84, 0xFF<<16, 0x0<<16);

		AsiaMemoryModify32(EphyBase + 0xC88, 0xFF, 0x0);
		AsiaMemoryModify32(EphyBase + 0xC88, 0xFF<<8, 0x16<<8);
		AsiaMemoryModify32(EphyBase + 0xC88, 0xFF<<16, 0x2<<16);
		
		AsiaMemoryModify32(EphyBase + 0xC8c, 0xFF, 0x1);
		AsiaMemoryModify32(EphyBase + 0xC8c, 0xFF<<8, 0x16<<8);
		AsiaMemoryModify32(EphyBase + 0xC8c, 0xFF<<16, 0x1<<16);
		//read FS/LF to set cursors
*/
	}


	return EFI_SUCCESS;
}



/**
   IoePhyCfgS3Resume.

   
  @param  PeiServices	EFI_PEI_SERVICES pointer.
  @param NbCfg point to ASIA_NB_CONFIGURATION struct

  @return VOID.

**/

STATIC
VOID
IoePhyCfgS3Resume(
	IN EFI_PEI_SERVICES **PeiServices,
	IN ASIA_NB_CONFIGURATION *NbConfig,
	IN UINT32 MmioBarx)
{
	UINT8 Gpio7Flag = 0;

	//
	// SI setting registers
	// [S3Resume-Step4]

	IoeSetPciePhyDriving(PeiServices, NbConfig, MmioBarx);
	
//;cjw-A0-patch 20161124
	//recovery the debugsignal setting 
	if((NbConfig->IoeChipRevision) == IOE_REVISION_A0){
		IoePatchDbgSignal(PeiServices, NbConfig);
	}
	
	IoeDebugSignalSelPostCfgDone(PeiServices, NbConfig);
//;cjw-A0-patch END
	
	IoePcieGen3Internal(PeiServices, NbConfig);



//This new circuit for IOE PCIe DN port, there are three cases:
// 1. For compliance test: EH2,  we enable the token PCISIG_PLUGFEST_WORKAROUND,
//     those code must be run
// 2. For boards designed to hold DN port Linkup, like EH2, EN0, when setup  
//     NbConfig->Cnd003SwCtlDnPortLinkup enabled, those code will be run, will should NOT to set
//    NbConfig->Cnd003SwCtlDnPortLinkup to 0
// 3. For boards without holding DN port linkup,  but part of them reworked fot this, like EM0
//    those code will be run when NbConfig->Cnd003SwCtlDnPortLinkup == 1
//	 and those code will not be run when NbConfig->Cnd003SwCtlDnPortLinkup == 0
// 4. for all other type MB without this issue, like EK0, EI0 ... , even  NbConfig->Cnd003SwCtlDnPortLinkup == 1
//     those code will NOT be run
//
	if(NbConfig->Cnd003SwCtlDnPortLinkup == 1){
#if GPIO7_CTL_LINKUP_PLATFORM
		//PEI_DEBUG((PeiServices, EFI_D_ERROR, "[EN0-1]			Busx D0F0 Bar0 - 0x%08x\n",MmioBarx));
		//IoeDumpCfg(PeiServices,0xE0000000,1,0,0,0x200);
		//IoeDumpCfg(PeiServices,0xE0000000,2,3,0,0x200);
		//IoeDumpMem(PeiServices,MmioBarx+MMIO_ISB_OFFSET,0x100);
		
		AsiaMemoryModify8(MmioBarx + MMIO_ISB_OFFSET + CND003_MMIO_D0F0_VCORE_GENERAL_PURPOSE_OUTPUT, BIT7, 0);
		AsiaIoWrite8(0x80, 0x1C);
		PeiNbPcieStallx(PeiServices, 100);	
		Gpio7Flag++;
		
		//PEI_DEBUG((PeiServices, EFI_D_ERROR, "[EN0-2]			Busx D0F0 Bar0 - 0x%08x\n",MmioBarx));
		//IoeDumpCfg(PeiServices,0xE0000000,2,3,0,0x200);
		//IoeDumpMem(PeiServices,MmioBarx+MMIO_ISB_OFFSET,0x100);	
#endif
	}else{
		
	}
//CND003 Logo test workaround
#ifdef PCISIG_PLUGFEST_WORKAROUND
	if(Gpio7Flag == 0){
		AsiaMemoryModify8(MmioBarx + MMIO_ISB_OFFSET + CND003_MMIO_D0F0_VCORE_GENERAL_PURPOSE_OUTPUT, BIT7, 0);
		AsiaIoWrite8(0x80, 0x1C);
		PeiNbPcieStallx(PeiServices, 100);
	}
#endif
	Gpio7Flag++;



	
}

/**
   IoePhyCfgColdBoot.
   
  @param  PeiServices	EFI_PEI_SERVICES pointer.
  @param NbCfg point to ASIA_NB_CONFIGURATION struct

  @return VOID.

**/

STATIC
VOID
IoePhyCfgColdBoot(
	IN EFI_PEI_SERVICES **PeiServices,
	IN ASIA_NB_CONFIGURATION *NbConfig,
	IN UINT32 MmioBarx)
{
	UINT16 CapEP,CapPEA0,CapPEA1,CapPEA2,CapPEA3,CapPEA4,CapPEB0,CapPEB1,CapPESB,CapXBCTL;
	UINT16 CapSel;	
	UINT16 PhyA,PhyB;

	UINT16 temp16s;
	UINT16 Value16x;
	UINT8 Datax8;

	UINT8 RpDev,RpFunc;

	UINT8 Gpio7Flag = 0;

	PEI_DEBUG((PeiServices, EFI_D_ERROR, "[CJW_IOE_CAP] ->%a\n",__FUNCTION__));
	
	//
	// BIOS set PCIE_Capability_Selection register for each CND003 PCIE Port according to MRD requirement
	// BIOS set PCIEVER_SEL_BIOSMD = 1(BusX D0F0 Rx1EB[7])
	// [ColdBoot-Step4]
	//
	temp16s = AsiaPcieRead16(PCI_BASE, ASIA_PCI_ADDRESS(BUSX, UPPORT_DEV, UPPORT_FUN, CND003_BUSX_D0F0_PCIE_CAP_SEL));
	PEI_DEBUG((PeiServices, EFI_D_ERROR, "[CJW_IOE_CAP] Rx1EA=0x%04x(1-Default value)\n",temp16s));
	
	CapEP = (NbConfig->Cnd003EpCap)&0x03;
	CapPEA0 = ((NbConfig->Cnd003CapPEA0)&0x01)<<3;
	CapPEA1 = ((NbConfig->Cnd003CapPEA1)&0x01)<<4;
	CapPEA2 = ((NbConfig->Cnd003CapPEA2)&0x01)<<5;
	CapPEA3 = ((NbConfig->Cnd003CapPEA3)&0x01)<<6;
	CapPEA4 = ((NbConfig->Cnd003CapPEA4)&0x01)<<7;
	CapPEB0 = ((NbConfig->Cnd003CapPEB0)&0x01)<<8;
	CapPEB1 = ((NbConfig->Cnd003CapPEB1)&0x01)<<9;
	//CapPESB = ((NbConfig->Cnd003CapPESB)&0x01)<<10;
	CapPESB = 0<<10; 			//fixed
	CapXBCTL = 1<<2;
	CapSel= (CapEP|CapPEA0|CapPEA1|CapPEA2|CapPEA3|CapPEA4|CapPEB0|CapPEB1|CapPESB|CapXBCTL);

	// Set PCIE_Capability_Selection
	AsiaPcieWrite16(PCI_BASE, ASIA_PCI_ADDRESS(BUSX, UPPORT_DEV, UPPORT_FUN, 0)|((UINT64)CND003_BUSX_D0F0_PCIE_CAP_SEL << 32), CapSel);

	//
	// PCIEVER_SEL_BIOSMD = 1'b1 
	// [ColdBoot-Step5]
	//
	AsiaPcieModify16(PCI_BASE, ASIA_PCI_ADDRESS(BUSX, UPPORT_DEV, UPPORT_FUN, 0)|((UINT64)CND003_BUSX_D0F0_PCIE_CAP_SEL << 32), BIT15, BIT15);  

	temp16s = AsiaPcieRead16(PCI_BASE, ASIA_PCI_ADDRESS(BUSX, UPPORT_DEV, UPPORT_FUN, 0)|((UINT64)CND003_BUSX_D0F0_PCIE_CAP_SEL << 32));
	PEI_DEBUG((PeiServices, EFI_D_ERROR, "[CJW_IOE_CAP] Rx1EA=0x%04x(2-After setting)\n",temp16s));


//#ifndef CND003_FPGA  jny modify 0307

	if((NbConfig->IoeChipRevision) == IOE_REVISION_A0){
		//
		// BIOS PERST CND003 through CHX001's GPO pin
		// [ColdBoot-Step6] 
		//
	//;cjw-A0-debug
		HOST_PEXRST_FOR_CND003();   														// this is a platform related routine
		PEI_DEBUG((PeiServices, EFI_D_ERROR, "[CJW_IOE] RP PeRst#--> Pls wait...PERST*\n"));
		PeiNbPcieStallx(PeiServices, 100);		

		// Read after PERST
		PEI_DEBUG((PeiServices, EFI_D_ERROR, "[CJW_IOE] RP PeRst#--> (x) [BUSX|0|0] DIDVID = 0x%08X\n",AsiaPciRead32(AsiaPciAddress(BUSX, UPPORT_DEV, UPPORT_FUN, 0x00))));
		PEI_DEBUG((PeiServices, EFI_D_ERROR, "[CJW_IOE] RP PeRst#--> (C) [BUSX|0|0] Rx05 = 0x%02X\n",AsiaPciRead8(AsiaPciAddress(BUSX, UPPORT_DEV, UPPORT_FUN, 0x05))));
		PEI_DEBUG((PeiServices, EFI_D_ERROR, "[CJW_IOE] RP PeRst#--> Rx4C=0x%02X([3:0] To check whether PCIE_Capability_Selection[] was loaded to CapRelatedReg)\n",
												AsiaPcieRead8((UINT64)PCI_BASE, AsiaPciAddress(BUSX, UPPORT_DEV, UPPORT_FUN, 0x4C))));
		PEI_DEBUG((PeiServices, EFI_D_ERROR, "[CJW_IOE] RP PeRst#--> Rx70=0x%02X([3:0] To check whether PCIE_Capability_Selection[] was loaded to CapRelatedReg)\n",
												AsiaPcieRead8((UINT64)PCI_BASE, AsiaPciAddress(BUSX, UPPORT_DEV, UPPORT_FUN, 0x70))));
		PEI_DEBUG((PeiServices, EFI_D_ERROR, "[CJW_IOE] RP PeRst#--> Rx1EA=0x%04X([15:0] To check PCIE_Capability_Selection[])\n", 
												AsiaPcieRead16((UINT64)PCI_BASE, AsiaPciAddress(BUSX, UPPORT_DEV, UPPORT_FUN, 0x1EA))));

		
		//
		// BIOS assign temp bus number again(after PEXRST, we need to assign again)
		// [ColdBoot-Step7]
		//
	//cjw-A0-debug 20161030
		IoePeiTempAssignment(PeiServices);
	//cjw-A0-debug END



		if(NbConfig->Cnd003BootErrorClear == 1){
			//
			// Clear the AER status of RP
			// Because the PEXRST# will lead to the Error Occurs on RP
			//		
			IoeGetRpToFindIoe(PeiServices, &RpDev, &RpFunc);
			PEI_DEBUG((PeiServices, EFI_D_ERROR, "[CJW_IOE] Before Clear AER[0|%d|%d]: \n",RpDev,RpFunc));
			PEI_DEBUG((PeiServices, EFI_D_ERROR, "          RP_Rx104 = 0x%08x\n",
						AsiaPcieRead32(PCI_BASE, AsiaPciAddress(0, RpDev, RpFunc, HOST_UNCORRECTABLE_ERR_STA))));
			PEI_DEBUG((PeiServices, EFI_D_ERROR, "          RP_Rx110 = 0x%08x\n",
						AsiaPcieRead32(PCI_BASE, AsiaPciAddress(0, RpDev, RpFunc, HOST_CORRECTABLE_ERR_STA))));
			AsiaPcieModify32(PCI_BASE, AsiaPciAddress(0, RpDev, RpFunc, HOST_UNCORRECTABLE_ERR_STA), 0xFFFFFFFF, 0xFFFFFFFF);
			AsiaPcieModify32(PCI_BASE, AsiaPciAddress(0, RpDev, RpFunc, HOST_CORRECTABLE_ERR_STA), 0xFFFFFFFF,0xFFFFFFFF);
			AsiaPcieModify8(0xE0000000, AsiaPciAddress(0, RpDev, RpFunc, HOST_ROOT_ERR_STA), 0x7F, 0x7F);
			AsiaPcieModify8(0xE0000000, AsiaPciAddress(0, RpDev, RpFunc, HOST_DEV_STA_1), 0x0F, 0x0F);	
		}

	
	}else if((NbConfig->IoeChipRevision) == IOE_REVISION_A1){

		// Toggle PCIE PTN local CFGDONE
		PEI_DEBUG((PeiServices, EFI_D_ERROR, "[CJW_IOE] Toggle local CFGDONE - MMIO Rx1FC6[0]\n"));
		AsiaMemoryModify8(MmioBarx + CND003_PCIEEPHYCFG_PCIE_CFG_SHADOW_REG_4 + 2, BIT0, 0);
		AsiaMemoryModify8(MmioBarx + CND003_PCIEEPHYCFG_PCIE_CFG_SHADOW_REG_4 + 2, BIT0, BIT0);
		AsiaMemoryModify8(MmioBarx + CND003_PCIEEPHYCFG_PCIE_CFG_SHADOW_REG_4 + 2, BIT0, 0);
	}


//#endif  JNY modify 0307- e





	//SwDbg-1-0-SwDbg-2-PeiGen2Stress
	if((NbConfig->Cnd003SwDbg1 == 0)&&((NbConfig->Cnd003SwDbg2) & BIT3)){
		PEI_DEBUG((PeiServices, EFI_D_ERROR, "SwDbg-1-0-SwDbg-2-PeiGen2Stress\n"));

		do{
			PeiNbPcieStallx(PeiServices, 1000);
			PEI_DEBUG((PeiServices, EFI_D_ERROR, "Wait Link to Gen2 - Currently:0x%02x\n",
											0xF & AsiaPciRead8(AsiaPciAddress(BUSX, UPPORT_DEV, UPPORT_FUN, CND003_BUSX_D0F0_LINK_STA_1))));
			IoeDumpCfg(PeiServices, PCI_BASE, BUSX, UPPORT_DEV, UPPORT_FUN, 0x100);
		}while((0xF & AsiaPciRead8(AsiaPciAddress(BUSX, UPPORT_DEV, UPPORT_FUN, CND003_BUSX_D0F0_LINK_STA_1))) != 0x02);
		{
			UINT16 ix;
			for(ix = 0; ix< 0x8FF; ix++){
				PEI_DEBUG((PeiServices, EFI_D_ERROR, "~=_=~ Number: %d\n",ix));
				IoeDumpCfg(PeiServices, PCI_BASE, BUSX, UPPORT_DEV, UPPORT_FUN, 0x100);
				IoeDumpMem(PeiServices, MmioBarx, 0x2000);
			}
		}
	}

	//SwDbg-1-0-SwDbg-2-PeiGen1Stress
	if((NbConfig->Cnd003SwDbg1 == 0)&&((NbConfig->Cnd003SwDbg2) & BIT4)){
		PEI_DEBUG((PeiServices, EFI_D_ERROR, "SwDbg-1-0-SwDbg-2-PeiGen1Stress\n"));

		do{
			PeiNbPcieStallx(PeiServices, 1000);
			PEI_DEBUG((PeiServices, EFI_D_ERROR, "Wait Link to Gen1 - Currently:0x%02x\n",
											0xF & AsiaPciRead8(AsiaPciAddress(BUSX, UPPORT_DEV, UPPORT_FUN, CND003_BUSX_D0F0_LINK_STA_1))));
			IoeDumpCfg(PeiServices, PCI_BASE, BUSX, UPPORT_DEV, UPPORT_FUN, 0x100);
		}while((0xF & AsiaPciRead8(AsiaPciAddress(BUSX, UPPORT_DEV, UPPORT_FUN, CND003_BUSX_D0F0_LINK_STA_1))) != 0x01);
		
		{
			UINT16 ix;
			for(ix = 0; ix< 0x8FF; ix++){
				PEI_DEBUG((PeiServices, EFI_D_ERROR, "~=_=~ Number: %d\n",ix));
				IoeDumpCfg(PeiServices, PCI_BASE, BUSX, UPPORT_DEV, UPPORT_FUN, 0x100);
				IoeDumpMem(PeiServices, MmioBarx, 0x2000);
			}
		}			
	}


	if((NbConfig->IoeChipRevision) == IOE_REVISION_A0){
	//;cjw-A0-patch 20161124
		//recovery the debugsignal setting 
		IoePatchDbgSignal(PeiServices, NbConfig);
		//IoeDebugSignalSelPostCfgDone(PeiServices, NbConfig);
	//;cjw-A0-patch END
	}


	//
	// [ColdBoot-Step8]
	//  8.1. Set PCIE/SATA Combo EPHY configuration related registers 
	//  8.2. Set SATA/PCIE EPHY reference clock selection 
	//  8.3. Set USB31EPHY reference clcok selection
	//  8.4. SI setting registers
	//  8.5. RCMPHY_CFGDONE = 1'b1
	//  Note: For FPGA, only 8.1 and 8.5 is necessary
	//

	// PCIE/SATA Combo PHY Configuration related register(PHY cfg & RCMBPHY_CFGDONE)
	PEI_DEBUG((PeiServices, EFI_D_ERROR, "[CJW_IOE] Read MMIO_ISB before setting:\n"));
	Value16x = AsiaMemoryRead16(MmioBarx+MMIO_ISB_OFFSET+CND003_MMIO_D0F0_STRAPPING_PIN_READ_BACK_REG_GRP_2);
	PEI_DEBUG((PeiServices, EFI_D_ERROR, "          MMIO_ISB Rx36 = 0x%04X\n",Value16x));
	Value16x = AsiaMemoryRead16(MmioBarx+MMIO_ISB_OFFSET+CND003_MMIO_D0F0_STRAPPING_PIN_READ_BACK_REG_GRP_0);
	PEI_DEBUG((PeiServices, EFI_D_ERROR, "          MMIO_ISB Rx32 = 0x%04X\n",Value16x));
	Value16x = AsiaMemoryRead16(MmioBarx+MMIO_ISB_OFFSET+CND003_MMIO_D0F0_STRAPPING_PIN_READ_BACK_REG_GRP_1);
	PEI_DEBUG((PeiServices, EFI_D_ERROR, "          MMIO_ISB Rx34 = 0x%04X\n",Value16x));
	Value16x = AsiaMemoryRead16(MmioBarx+MMIO_ISB_OFFSET+CND003_MMIO_D0F0_STRAPPING_PIN_READ_BACK_REG_PCIE_SATA_COMBO_PHY_CFG);
	PEI_DEBUG((PeiServices, EFI_D_ERROR, "          MMIO_ISB Rx30 = 0x%04X\n",Value16x));		

#ifdef CND003_FPGA
		PhyA = (UINT16)(NbConfig->Cnd003PhyACfg);  	//default PE_CFG3
		PhyB = (UINT16)(NbConfig->Cnd003PhyBCfg);  	//default PE_CFG2
#else
	if(NbConfig->Cnd003PhyCfg == 1){  				//fixed
		PhyA = 	IoePhyCfg.PhyACfg;
		PhyB = IoePhyCfg.PhyBCfg;
	}else{
		PhyA = (UINT16)(NbConfig->Cnd003PhyACfg);
		PhyB = (UINT16)(NbConfig->Cnd003PhyBCfg);
	}
#endif

	PEI_DEBUG((PeiServices, EFI_D_ERROR, "[CJW_IOE_PHY] 0x%04x\n",PhyA));
	PEI_DEBUG((PeiServices, EFI_D_ERROR, "              0x%04x\n",PhyB));
	PhyA = (PhyA<<8)&(BIT9|BIT8);
	PhyB = (PhyB<<10)&(BIT11|BIT10);
	PEI_DEBUG((PeiServices, EFI_D_ERROR, "[CJW_IOE_PHY] 0x%04x\n",PhyA));
	PEI_DEBUG((PeiServices, EFI_D_ERROR, "              0x%04x\n",PhyB));	
	AsiaMemoryModify16(MmioBarx+MMIO_ISB_OFFSET+CND003_MMIO_D0F0_STRAPPING_PIN_READ_BACK_REG_GRP_1, BIT9|BIT8, PhyA); 	//CFG PHYA  ConfigA3- four x1 
	AsiaMemoryModify16(MmioBarx+MMIO_ISB_OFFSET+CND003_MMIO_D0F0_STRAPPING_PIN_READ_BACK_REG_GRP_1, BIT11|BIT10, PhyB); //CFG PHYB  ConfigB2- two x2


#if  1
	// TODO: Set SATA/PCIE EPHY reference clock selection 
	// 1: Internal clock
	// 0: External clock
	AsiaMemoryModify8(MmioBarx + MMIO_ISB_OFFSET + CND003_MMIO_D0F0_STRAPPING_PIN_READ_BACK_REG_GRP_1, BIT7|BIT6, BIT7); 
	PEI_DEBUG((PeiServices, EFI_D_ERROR, "          Reference Clock:\n"));
	PEI_DEBUG((PeiServices, EFI_D_ERROR, "            PHYA: %a\n",
			(BIT7 & AsiaMemoryRead8(MmioBarx + MMIO_ISB_OFFSET + CND003_MMIO_D0F0_STRAPPING_PIN_READ_BACK_REG_GRP_1))?"Internal":"External"));
	PEI_DEBUG((PeiServices, EFI_D_ERROR, "            PHYB: %a\n",
			(BIT6 & AsiaMemoryRead8(MmioBarx + MMIO_ISB_OFFSET + CND003_MMIO_D0F0_STRAPPING_PIN_READ_BACK_REG_GRP_1))?"Internal":"External"));

//;cjw-A0-debug 20161102
#if 0   //currently , we not set those registers	
	// TODO: Set USB31EPHY reference clcok selection
	// 0: Internal clock
	// 1: External clock
	AsiaMemoryModify8(MmioBarx + MMIO_ISB_OFFSET + CND003_MMIO_D0F0_STRAPPING_PIN_READ_BACK_REG_GRP_1, BIT5, 0); 
	PEI_DEBUG((PeiServices, EFI_D_ERROR, "            USB3.1: %a\n",
			(BIT5 & AsiaMemoryRead8(MmioBarx + MMIO_ISB_OFFSET + CND003_MMIO_D0F0_STRAPPING_PIN_READ_BACK_REG_GRP_1))?"External":"Internal"));
	
#endif
//;cjw-A0-debug END
#endif

	// SI setting registers
	IoeSetPciePhyDriving(PeiServices, NbConfig, MmioBarx);

	IoePcieGen3Internal(PeiServices, NbConfig);

//;cjw-A0-patch 20161101
	//recovery the debugsignal setting 
	//IoePatchDbgSignal(PeiServices, NbConfig);
//;cjw-A0-patch END



//;cjw-A0-debug 20161030
	{
		//Debug - Read MMIO_ISB to confirm that which USB phy we use
		UINT32 ddd,i;
		PEI_DEBUG((PeiServices, EFI_D_ERROR, "\nMMIO_ISB:\n"));
		for(i=0;i<0xFF;i+=4){
			if((i&0xF)==0x0){
				PEI_DEBUG((PeiServices, EFI_D_ERROR, "\n              Rx0x%02x: ",i));
			}
			ddd = AsiaMemoryRead32(MmioBarx + MMIO_ISB_OFFSET + i);
			PEI_DEBUG((PeiServices, EFI_D_ERROR, " 0x%08x ",ddd));
		}
		PEI_DEBUG((PeiServices, EFI_D_ERROR, "\n"));
		PEI_DEBUG((PeiServices, EFI_D_ERROR, "==>Dump BUSX:\n"));
		IoeDumpCfg(PeiServices, PCI_BASE, BUSX, UPPORT_DEV, UPPORT_FUN, 0x40); //add some cfg cycle
	}
//;cjw-A0-debug END


	//AsiaMemoryModify16(MmioBarx+MMIO_ISB_OFFSET+CND003_MMIO_D0F0_STRAPPING_PIN_READ_BACK_REG_GRP_2, BIT13, 0);			//RCMBPHY_CFGDONE = 0
	//PeiNbPcieStallx(PeiServices, 1000);
	AsiaMemoryModify16(MmioBarx+MMIO_ISB_OFFSET+CND003_MMIO_D0F0_STRAPPING_PIN_READ_BACK_REG_GRP_2, BIT13, BIT13); 		//RCMBPHY_CFGDONE = 1
	PEI_DEBUG((PeiServices, EFI_D_ERROR, "[CJW_IOE] ==>PHYA/PHYB config ok! and RCMBPHY_CFGDONE=1\n"));
		
	PEI_DEBUG((PeiServices, EFI_D_ERROR, "[CJW_IOE] Read MMIO_ISB after setting:\n"));
	Value16x = AsiaMemoryRead16(MmioBarx+MMIO_ISB_OFFSET+CND003_MMIO_D0F0_STRAPPING_PIN_READ_BACK_REG_GRP_2);
	PEI_DEBUG((PeiServices, EFI_D_ERROR, "          MMIO_ISB Rx36 = 0x%04X\n",Value16x));
	Value16x = AsiaMemoryRead16(MmioBarx+MMIO_ISB_OFFSET+CND003_MMIO_D0F0_STRAPPING_PIN_READ_BACK_REG_GRP_0);
	PEI_DEBUG((PeiServices, EFI_D_ERROR, "          MMIO_ISB Rx32 = 0x%04X\n",Value16x));
	Value16x = AsiaMemoryRead16(MmioBarx+MMIO_ISB_OFFSET+CND003_MMIO_D0F0_STRAPPING_PIN_READ_BACK_REG_GRP_1);
	PEI_DEBUG((PeiServices, EFI_D_ERROR, "          MMIO_ISB Rx34 = 0x%04X\n",Value16x));
	Value16x = AsiaMemoryRead16(MmioBarx+MMIO_ISB_OFFSET+CND003_MMIO_D0F0_STRAPPING_PIN_READ_BACK_REG_PCIE_SATA_COMBO_PHY_CFG);
	PEI_DEBUG((PeiServices, EFI_D_ERROR, "          MMIO_ISB Rx30 = 0x%04X\n",Value16x));	

	//To check the load status of capability selection
	Datax8 = AsiaPcieRead8((UINT64)PCI_BASE, AsiaPciAddress(BUSX, UPPORT_DEV, UPPORT_FUN, CND003_BUSX_D0F0_LINK_CAPS_1));
	PEI_DEBUG((PeiServices, EFI_D_ERROR, "[CJW_IOE] Rx4C=0x%02X([3:0] To check whether PCIE_Capability_Selection[] was loaded to CapRelatedReg)\n",Datax8));
	Datax8 = AsiaPcieRead8((UINT64)PCI_BASE, AsiaPciAddress(BUSX, UPPORT_DEV, UPPORT_FUN, CND003_BUSX_D0F0_LINK_CTL_2));
	PEI_DEBUG((PeiServices, EFI_D_ERROR, "          Rx70=0x%02X([1:0] To check whether PCIE_Capability_Selection[] was loaded to CapRelatedReg)\n",Datax8));








//This new circuit for IOE PCIe DN port, there are three cases:
// 1. For compliance test: EH2,  we enable the token PCISIG_PLUGFEST_WORKAROUND,
//     those code must be run
// 2. For boards designed to hold DN port Linkup, like EH2, EN0, when setup  
//     NbConfig->Cnd003SwCtlDnPortLinkup enabled, those code will be run, will should NOT to set
//    NbConfig->Cnd003SwCtlDnPortLinkup to 0
// 3. For boards without holding DN port linkup,  but part of them reworked fot this, like EM0
//    those code will be run when NbConfig->Cnd003SwCtlDnPortLinkup == 1
//	 and those code will not be run when NbConfig->Cnd003SwCtlDnPortLinkup == 0
// 4. for all other type MB without this issue, like EK0, EI0 ... , even  NbConfig->Cnd003SwCtlDnPortLinkup == 1
//     those code will NOT be run
//
	if(NbConfig->Cnd003SwCtlDnPortLinkup == 1){
#if GPIO7_CTL_LINKUP_PLATFORM
		//PEI_DEBUG((PeiServices, EFI_D_ERROR, "[EN0-1]			Busx D0F0 Bar0 - 0x%08x\n",MmioBarx));
		//IoeDumpCfg(PeiServices,0xE0000000,1,0,0,0x200);
		//IoeDumpCfg(PeiServices,0xE0000000,2,3,0,0x200);
		//IoeDumpMem(PeiServices,MmioBarx+MMIO_ISB_OFFSET,0x100);
		
		AsiaMemoryModify8(MmioBarx + MMIO_ISB_OFFSET + CND003_MMIO_D0F0_VCORE_GENERAL_PURPOSE_OUTPUT, BIT7, 0);
		AsiaIoWrite8(0x80, 0x1C);
		PeiNbPcieStallx(PeiServices, 100);	
		Gpio7Flag++;
		
		//PEI_DEBUG((PeiServices, EFI_D_ERROR, "[EN0-2]			Busx D0F0 Bar0 - 0x%08x\n",MmioBarx));
		//IoeDumpCfg(PeiServices,0xE0000000,2,3,0,0x200);
		//IoeDumpMem(PeiServices,MmioBarx+MMIO_ISB_OFFSET,0x100);	
#endif
	}else{
		
	}
//CND003 Logo test workaround
#ifdef PCISIG_PLUGFEST_WORKAROUND
	if(Gpio7Flag == 0){
		AsiaMemoryModify8(MmioBarx + MMIO_ISB_OFFSET + CND003_MMIO_D0F0_VCORE_GENERAL_PURPOSE_OUTPUT, BIT7, 0);
		AsiaIoWrite8(0x80, 0x1C);
		PeiNbPcieStallx(PeiServices, 100);
	}
#endif
	Gpio7Flag++;






	
	//
	// Set Design Patching Done
	// [ColdBoot-Setp9]
	//

    
    //;cjw-A0-patch 20161124----------------------TTPAN
        //recovery the debugsignal setting 
		// XHCI cfg space can only accessed after ISB_CFGDONE = 1 -- Chris J.Wang
        IoeDebugSignalSelPostCfgDone(PeiServices, NbConfig);
    //;cjw-A0-patch END ---------------TTPAN
}


/**
   IoePhyCfgColdBoot2.
   
  @param  PeiServices	EFI_PEI_SERVICES pointer.
  @param NbCfg point to ASIA_NB_CONFIGURATION struct

  @return VOID.

**/

STATIC
VOID
IoePhyCfgColdBoot2(
	IN EFI_PEI_SERVICES **PeiServices,
	IN ASIA_NB_CONFIGURATION *NbConfig,
	IN UINT32 MmioBarx)
{
	//UINT16 CapEP,CapPEA0,CapPEA1,CapPEA2,CapPEA3,CapPEA4,CapPEB0,CapPEB1,CapPESB,CapXBCTL;
	//UINT16 CapSel;	
	//UINT16 PhyA,PhyB;

	UINT16 temp16s;

	PEI_DEBUG((PeiServices, EFI_D_ERROR, "[CJW_IOE_CAP] ->%a\n",__FUNCTION__));

	temp16s = AsiaPcieRead16(PCI_BASE, ASIA_PCI_ADDRESS(BUSX, UPPORT_DEV, UPPORT_FUN, 0)|((UINT64)CND003_BUSX_D0F0_PCIE_CAP_SEL << 32));
	PEI_DEBUG((PeiServices, EFI_D_ERROR, "[CJW_IOE_CAP] Rx1EA=0x%04x(2-After setting)\n",temp16s));



//;cjw-A0-patch 20161124
	if((NbConfig->IoeChipRevision) == IOE_REVISION_A0){
		//recovery the debugsignal setting 
		IoePatchDbgSignal(PeiServices, NbConfig);
	}

	// XHCI cfg space can only accessed after ISB_CFGDONE = 1 -- Chris J.Wang
	IoeDebugSignalSelPostCfgDone(PeiServices, NbConfig);
//;cjw-A0-patch END



	PEI_DEBUG((PeiServices, EFI_D_ERROR, "          Reference Clock:\n"));
	PEI_DEBUG((PeiServices, EFI_D_ERROR, "            PHYA: %a\n",
			(BIT7 & AsiaMemoryRead8(MmioBarx + MMIO_ISB_OFFSET + CND003_MMIO_D0F0_STRAPPING_PIN_READ_BACK_REG_GRP_1))?"Internal":"External"));
	PEI_DEBUG((PeiServices, EFI_D_ERROR, "            PHYB: %a\n",
			(BIT6 & AsiaMemoryRead8(MmioBarx + MMIO_ISB_OFFSET + CND003_MMIO_D0F0_STRAPPING_PIN_READ_BACK_REG_GRP_1))?"Internal":"External"));


	IoePcieGen3Internal(PeiServices, NbConfig);


//;cjw-A0-debug 20161030
	{
		//Debug - Read MMIO_ISB to confirm that which USB phy we use
		UINT32 ddd,i;
		PEI_DEBUG((PeiServices, EFI_D_ERROR, "\nMMIO_ISB:\n"));
		for(i=0;i<0xFF;i+=4){
			if((i&0xF)==0x0){
				PEI_DEBUG((PeiServices, EFI_D_ERROR, "\n              Rx0x%02x: ",i));
			}
			ddd = AsiaMemoryRead32(MmioBarx + MMIO_ISB_OFFSET + i);
			PEI_DEBUG((PeiServices, EFI_D_ERROR, " 0x%08x ",ddd));
		}
		PEI_DEBUG((PeiServices, EFI_D_ERROR, "\n"));
		PEI_DEBUG((PeiServices, EFI_D_ERROR, "==>Dump BUSX:\n"));
		IoeDumpCfg(PeiServices, PCI_BASE, BUSX, UPPORT_DEV, UPPORT_FUN, 0x40); //add some cfg cycle
	}
//;cjw-A0-debug END

}







#if 1

/**
  IoeSmbusSetPciePhyDriving
   
  @param  PeiServices	EFI_PEI_SERVICES pointer.
  @param NbCfg point to ASIA_NB_CONFIGURATION struct
  @param MmioBarx

  @return VOID.

**/

STATIC
VOID
IoeSmbusSetPciePhyDriving(
    IN EFI_PEI_SERVICES **PeiServices,
    IN ASIA_NB_CONFIGURATION *NbConfig,
    IN UINT32 MmioBarx)
{
	SI_PCIE_PHY_CND003DRIVING_ITEM *Item2;  

    UINTN   Index;
    UINTN   Inner1Index;
    UINT8   ChipRevision;
	UINT8 bData8;
	PEI_DEBUG((PeiServices, EFI_D_ERROR,"--IOE SI Driving[SMBus]--\n"));
    //Get chipset revision
    //ChipRevision = NbConfig->ChipRevision;

	//ChipRevision = AsiaPciRead8(AsiaPciAddress(BUSX, UPPORT_DEV, UPPORT_FUN, CND003_BUSX_D0F0_INTERNAL_REV_ID));
	IoeSmbusCfgDebugRead8(PeiServices, 0,0,0, 0xF6, &ChipRevision);
	if((ChipRevision != IOE_REVISION_A0)&&(ChipRevision != IOE_REVISION_A1)){
		while(1){
			AsiaIoWrite8(0x80, SMBUS_CHIPVERSION_ERROR_1);
			PeiNbPcieStallx(PeiServices, 500);
			AsiaIoWrite8(0x80, SMBUS_CHIPVERSION_ERROR_2);
			PeiNbPcieStallx(PeiServices, 500);
		}
	}

	if(ChipRevision == IOE_REVISION_A0){
	    for (Index = 0; Index < PcieCND003DrivingTblItems_A0; Index++) {
	    	Item2 = &PcieCND003DrivingTbl_A0[Index];
			//bData16 = IoeShiftToMaskBit(Item2->Mask, Item2->Value); 
			bData8 = Item2->Value;
			switch (Item2->RegType){
	       	case PCIEPHYREGDETECT_DEF:
				IoeSmbusDebugModify8(PeiServices,MmioBarx|Item2->RegisterNum,1,Item2->Mask, bData8);
				
				//AsiaMemoryModify8(MmioBarx|Item2->RegisterNum , Item2->Mask, bData8);
	         	break;
	      	case PCIEPHYREGDETECT_CONT : 
				for(Inner1Index = 0; Inner1Index < Item2->RegLoop; Inner1Index ++){
					IoeSmbusDebugModify8(PeiServices,MmioBarx |(Item2->RegisterNum + Inner1Index),1,Item2->Mask, bData8);
					
					//AsiaMemoryModify8(MmioBarx |(Item2->RegisterNum + Inner1Index) , Item2->Mask, bData8);
				}
	      		break;
	      	case PCIEPHYREGDETECT_EVEN : 
				for(Inner1Index = 0; Inner1Index < Item2->RegLoop; Inner1Index ++){
					IoeSmbusDebugModify8(PeiServices,MmioBarx +(Item2->RegisterNum + (Inner1Index << 1)),1,Item2->Mask, bData8);
					
					//AsiaMemoryModify8(MmioBarx +(Item2->RegisterNum + (Inner1Index << 1)) , Item2->Mask, bData8);
				}
	         	break;
	     	case PCIEPHYREGDETECT_ODD :
				for(Inner1Index = 0; Inner1Index < Item2->RegLoop; Inner1Index ++){
					IoeSmbusDebugModify8(PeiServices,MmioBarx +(Item2->RegisterNum + (Inner1Index << 1)),1,Item2->Mask, bData8);
					
					//AsiaMemoryModify8(MmioBarx +(Item2->RegisterNum + (Inner1Index << 1)) , Item2->Mask, bData8);
						
				}
				break;
	        }

	  	}
	}

	if(ChipRevision == IOE_REVISION_A1){
	  for (Index = 0; Index < PcieCND003DrivingTblItems_A1; Index++) {
	    	Item2 = &PcieCND003DrivingTbl_A1[Index];
			//bData16 = IoeShiftToMaskBit(Item2->Mask, Item2->Value); 
			bData8 = Item2->Value;
			switch (Item2->RegType){
	       	case PCIEPHYREGDETECT_DEF:
				IoeSmbusDebugModify8(PeiServices,MmioBarx|Item2->RegisterNum,1,Item2->Mask, bData8);
				
				//AsiaMemoryModify8(MmioBarx|Item2->RegisterNum , Item2->Mask, bData8);
	         	break;
	      	case PCIEPHYREGDETECT_CONT : 
				for(Inner1Index = 0; Inner1Index < Item2->RegLoop; Inner1Index ++){
					IoeSmbusDebugModify8(PeiServices,MmioBarx |(Item2->RegisterNum + Inner1Index),1,Item2->Mask, bData8);
					
					//AsiaMemoryModify8(MmioBarx |(Item2->RegisterNum + Inner1Index) , Item2->Mask, bData8);
				}
	      		break;
	      	case PCIEPHYREGDETECT_EVEN : 
				for(Inner1Index = 0; Inner1Index < Item2->RegLoop; Inner1Index ++){
					IoeSmbusDebugModify8(PeiServices,MmioBarx +(Item2->RegisterNum + (Inner1Index << 1)),1,Item2->Mask, bData8);
					
					//AsiaMemoryModify8(MmioBarx +(Item2->RegisterNum + (Inner1Index << 1)) , Item2->Mask, bData8);
				}
	         	break;
	     	case PCIEPHYREGDETECT_ODD :
				for(Inner1Index = 0; Inner1Index < Item2->RegLoop; Inner1Index ++){
					IoeSmbusDebugModify8(PeiServices,MmioBarx +(Item2->RegisterNum + (Inner1Index << 1)),1,Item2->Mask, bData8);
					
					//AsiaMemoryModify8(MmioBarx +(Item2->RegisterNum + (Inner1Index << 1)) , Item2->Mask, bData8);
						
				}
				break;
	        }

	  	}


	}

	
	
	//SwDbg-1-0-SwDbg-2-TempDCGain
	if((NbConfig->Cnd003SwDbg1 == 0)&&((NbConfig->Cnd003SwDbg2) & BIT16)){
		PEI_DEBUG((PeiServices, EFI_D_ERROR, "CJW_IOE_Patch: SwDbg-1-0-SwDbg-2-TempDCGain  -- SMBus\n"));
		IoeSmbusDebugModify8(PeiServices,MmioBarx+ 0x6A3 ,1,0x3F, 0x1F);
		IoeSmbusDebugModify8(PeiServices,MmioBarx+ 0x6A4 ,1,0x3F, 0x1F);
		IoeSmbusDebugModify8(PeiServices,MmioBarx+ 0x6A5 ,1,0x3F, 0x1F);
		IoeSmbusDebugModify8(PeiServices,MmioBarx+ 0x6A1 ,1,0x3F, 0x1F);
	}	
	


}




/**************************************************************************
// Initialization of CND003 through SMBus
**************************************************************************/
/**
   IoeSmbusPreInit.

  Before IOE can work steady
  BIOS need to do some SI setting & Function Patching for IOE
  Those operations can be done through SMBus
  All SMBus operations will be completed in this function.
  Tips:those routine can only run once before Restart The System. 

   
  @param  PeiServices	EFI_PEI_SERVICES pointer.
  @param NbCfg point to ASIA_NB_CONFIGURATION struct

  @return EFI_STATUS.

**/

EFI_STATUS
IoeSmbusPreInit(
	IN EFI_PEI_SERVICES **PeiServices,
	ASIA_NB_CONFIGURATION *NbConfig
)
{
	UINT16 CapEP,CapPEA0,CapPEA1,CapPEA2,CapPEA3,CapPEA4,CapPEB0,CapPEB1,CapPESB,CapXBCTL;
	UINT16 CapSel;	
	UINT16 PhyA,PhyB;
	EFI_BOOT_MODE BootMode;
	

	//SwDbg-1-0-SwDbg-2-BootSequence
	if((NbConfig->Cnd003SwDbg1 == 0)&&(!((NbConfig->Cnd003SwDbg2) & BIT8))){
		return EFI_SUCCESS;	
	}

	PEI_DEBUG((PeiServices, EFI_D_ERROR, "[CJW] SwDbg-1-0-SwDbg-2-BootSequence\n"));

	(*PeiServices)->GetBootMode (PeiServices, &BootMode);


	PEI_DEBUG((PeiServices, EFI_D_ERROR, "[CJW] %a() Line%d<--\n",__FUNCTION__,__LINE__));
	//IOE init from SMBus

	IoeSmbusDebugPathEnable(PeiServices,1);

	if(BootMode != BOOT_ON_S3_RESUME){
		CapEP = (NbConfig->Cnd003EpCap)&0x03;
		CapPEA0 = ((NbConfig->Cnd003CapPEA0)&0x01)<<3;
		CapPEA1 = ((NbConfig->Cnd003CapPEA1)&0x01)<<4;
		CapPEA2 = ((NbConfig->Cnd003CapPEA2)&0x01)<<5;
		CapPEA3 = ((NbConfig->Cnd003CapPEA3)&0x01)<<6;
		CapPEA4 = ((NbConfig->Cnd003CapPEA4)&0x01)<<7;
		CapPEB0 = ((NbConfig->Cnd003CapPEB0)&0x01)<<8;
		CapPEB1 = ((NbConfig->Cnd003CapPEB1)&0x01)<<9;
		//CapPESB = ((NbConfig->Cnd003CapPESB)&0x01)<<10;
		CapPESB = 0<<10; 								//fixed
		CapXBCTL = 1<<2;
		CapSel= (CapEP|CapPEA0|CapPEA1|CapPEA2|CapPEA3|CapPEA4|CapPEB0|CapPEB1|CapPESB|CapXBCTL);

		//[1]Set PCIE_Capability_Selection
		IoeSmbusCfgDebugWrite8(PeiServices, 0, 0, 0, CND003_BUSX_D0F0_PCIE_CAP_SEL, (UINT8)(CapSel&0xFF));
		IoeSmbusCfgDebugWrite8(PeiServices, 0, 0, 0, CND003_BUSX_D0F0_PCIE_CAP_SEL+1, (UINT8)((CapSel>>8)&0xFF));

		//[2]PCIEVER_SEL_BIOSMD = 1'b1 
		IoeSmbusCfgDebugModify8(PeiServices, 0, 0, 0, CND003_BUSX_D0F0_PCIE_CAP_SEL+1, BIT7, BIT7);

		IoeSmbusDumpCfg(PeiServices, NbConfig, 0,0,0, CND003_BUSX_D0F0_PCIE_CAP_SEL, 1);

		//[3]PEXRST
		HOST_PEXRST_FOR_CND003();  
		PeiNbPcieStallx(PeiServices, 100);	
		
		IoeSmbusDebugPathEnable(PeiServices,1);

	}
    IoeSmbusCfgDebugWrite8(PeiServices,0,0,0,CND003_BUSX_D0F0_LOWER_BASE_ADR+3,0xF0);
	IoeSmbusCfgDebugWrite8(PeiServices,0,0,0,CND003_BUSX_D0F0_LOWER_BASE_ADR+2,0x20);


	if(BootMode != BOOT_ON_S3_RESUME){
		//[4]PHY setting
		if(NbConfig->Cnd003PhyCfg == 1){  				//fixed
			PhyA = 	IoePhyCfg.PhyACfg;
			PhyB = IoePhyCfg.PhyBCfg;
		}else{
			PhyA = (UINT16)(NbConfig->Cnd003PhyACfg);
			PhyB = (UINT16)(NbConfig->Cnd003PhyBCfg);
		}
		PhyA = (PhyA<<8)&(BIT9|BIT8);
		PhyB = (PhyB<<10)&(BIT11|BIT10);
		PEI_DEBUG((PeiServices, EFI_D_ERROR, "[CJW_IOE] PHYA = 0x%04x, PHYB = 0x%04x\n",PhyA,PhyB));
		IoeSmbusDebugModify8(PeiServices,
							BUSX_BAR0_BASE+MMIO_ISB_OFFSET+CND003_MMIO_D0F0_STRAPPING_PIN_READ_BACK_REG_GRP_1+1,
							1,	BIT1|BIT0,	(UINT8)(PhyA>>8));	
		IoeSmbusDebugModify8(PeiServices,
							BUSX_BAR0_BASE+MMIO_ISB_OFFSET+CND003_MMIO_D0F0_STRAPPING_PIN_READ_BACK_REG_GRP_1+1,
							1,	BIT3|BIT2,	(UINT8)(PhyB>>8));

		//[5]reference clock setting - PHYA=Internal  PHYB=External
		IoeSmbusDebugModify8(PeiServices,
							BUSX_BAR0_BASE+MMIO_ISB_OFFSET+CND003_MMIO_D0F0_STRAPPING_PIN_READ_BACK_REG_GRP_1,
							1,	BIT7|BIT6,	BIT7);
	}
	
	//[6] SI driving
	IoeSmbusSetPciePhyDriving(PeiServices, NbConfig, BUSX_BAR0_BASE);

	if(BootMode != BOOT_ON_S3_RESUME){
		//[7] CFGDONE -- //RCMBPHY_CFGDONE = 1
		IoeSmbusDebugModify8(PeiServices,
							BUSX_BAR0_BASE+MMIO_ISB_OFFSET+CND003_MMIO_D0F0_STRAPPING_PIN_READ_BACK_REG_GRP_2+1,
							1,	BIT5,	BIT5);
	}

    IoeSmbusCfgDebugWrite8(PeiServices,0,0,0,CND003_BUSX_D0F0_LOWER_BASE_ADR+3,0x00);
	IoeSmbusCfgDebugWrite8(PeiServices,0,0,0,CND003_BUSX_D0F0_LOWER_BASE_ADR+2,0x00);	
	IoeSmbusDebugPathEnable(PeiServices,0);
	
/*	
	temp16s = AsiaPcieRead16(PCI_BASE, ASIA_PCI_ADDRESS(BUSX, UPPORT_DEV, UPPORT_FUN, CND003_BUSX_D0F0_PCIE_CAP_SEL));
	PEI_DEBUG((PeiServices, EFI_D_ERROR, "[CJW_IOE_CAP] Rx1EA=0x%04x(1-Default value)\n",temp16s));
	
	CapEP = (NbConfig->Cnd003EpCap)&0x03;
	CapPEA0 = ((NbConfig->Cnd003CapPEA0)&0x01)<<3;
	CapPEA1 = ((NbConfig->Cnd003CapPEA1)&0x01)<<4;
	CapPEA2 = ((NbConfig->Cnd003CapPEA2)&0x01)<<5;
	CapPEA3 = ((NbConfig->Cnd003CapPEA3)&0x01)<<6;
	CapPEA4 = ((NbConfig->Cnd003CapPEA4)&0x01)<<7;
	CapPEB0 = ((NbConfig->Cnd003CapPEB0)&0x01)<<8;
	CapPEB1 = ((NbConfig->Cnd003CapPEB1)&0x01)<<9;
	//CapPESB = ((NbConfig->Cnd003CapPESB)&0x01)<<10;
	CapPESB = 0<<10; 			//fixed
	CapXBCTL = 1<<2;
	CapSel= (CapEP|CapPEA0|CapPEA1|CapPEA2|CapPEA3|CapPEA4|CapPEB0|CapPEB1|CapPESB|CapXBCTL);

	// Set PCIE_Capability_Selection
	AsiaPcieWrite16(PCI_BASE, ASIA_PCI_ADDRESS(BUSX, UPPORT_DEV, UPPORT_FUN, 0)|((UINT64)CND003_BUSX_D0F0_PCIE_CAP_SEL << 32), CapSel);

*/




	
	//check pcie link between CND001 RP and IOE USP
	
	
	//load 8051 fw
	//*[this procedure should be moved to somewhere after DRAM ready]
	//* Because in BIOS mode, the only usages for IOE MCU is to process the EQ phase2 of EP
	//* we don't need to load it too early 
	
	return EFI_SUCCESS;
}





#endif


/**
   IoePhyCfgInBiosMode.

  Bios mode is the mainly method for CHX002+IOE
  so we need to test some function and do some initilizaiton in bios.
  
  Those code is responsible for IOE PCIE PHY initialization  
  
  Note: Before calling this routine, we must guarantee that 
  all resource have assigned

   
  @param  PeiServices	EFI_PEI_SERVICES pointer.
  @param NbCfg point to ASIA_NB_CONFIGURATION struct

  @return VOID.

**/

STATIC
VOID
IoePhyCfgInBiosMode(	
	IN EFI_PEI_SERVICES **PeiServices,
	IN ASIA_NB_CONFIGURATION *NbConfig)
{

	UINT32 MmioBar;
	UINT16 temp16;
	EFI_BOOT_MODE   BootMode;

	//
	// Read RCMBPHY_CFGDONE(BUSX D0F0 MMIO_ISB Rx37-36[13]) to determine code-boot
	// [ColdBoot-step2]
	//
	MmioBar = AsiaPciRead32(AsiaPciAddress(BUSX, UPPORT_DEV, UPPORT_FUN, 0x10));
	temp16 = AsiaMemoryRead16(MmioBar + MMIO_ISB_OFFSET + CND003_MMIO_D0F0_STRAPPING_PIN_READ_BACK_REG_GRP_2);



	//SwDbg-1-0-SwDbg-2-BootSequence
	if((NbConfig->Cnd003SwDbg1 == 0)&&((NbConfig->Cnd003SwDbg2) & BIT8)){

		PEI_DEBUG((PeiServices, EFI_D_ERROR, "[CJW] SwDbg-1-0-SwDbg-2-BootSequence\n"));

		IoePhyCfgColdBoot2(PeiServices, NbConfig, MmioBar);		
	
	}else{
		//;cjw-A0-fixed 20161031
	    (*PeiServices)->GetBootMode (PeiServices, &BootMode);

	    if(BootMode != BOOT_ON_S3_RESUME){
			// Cold boot
			PEI_DEBUG((PeiServices, EFI_D_ERROR, "[CJW_IOE] %a() Line%d ==> PHYCFG: ColdBoot Method\n",__FUNCTION__,__LINE__));
			IoePhyCfgColdBoot(PeiServices, NbConfig, MmioBar);
	    }else{
			// S3 resume 
			PEI_DEBUG((PeiServices, EFI_D_ERROR, "[CJW_IOE] %a() Line%d ==> PHYCFG: S3 Method\n",__FUNCTION__,__LINE__));
			IoePhyCfgS3Resume(PeiServices, NbConfig, MmioBar);
		}
		//;cjw-A0-fixed END
	}




	//SwDbg-1-0-SwDbg-2-FFissue
	if((NbConfig->Cnd003SwDbg1 == 0)&&((NbConfig->Cnd003SwDbg2) & BIT0)){
//;cjw-A0-debug 20161130
	PEI_DEBUG((PeiServices, EFI_D_ERROR, "SwDbg-1-0-SwDbg-2-FFissue\n"));
	AsiaPcieModify16(PCI_BASE, ASIA_PCI_ADDRESS(BUSX, UPPORT_DEV, UPPORT_FUN, 0)|((UINT64)CND003_BUSX_D0F0_PCIE_CAP_SEL << 32),0x7FF,0x001);
//;cjw-A0-debug END
	}
	
	//IoeWaitLinkStable(PeiServices, NbConfig);

}


#if 0
/*
This function used for PERST to DN port of IOE PCIE PTN
*/
STATIC
EFI_STATUS
IoePowerOnDnPortPeRst(
	IN EFI_PEI_SERVICES **PeiServices
)
{
	UINT32 Datax;
	UINT32 MmioData;
	UINTN i;

	#define UNDER_BUS 	IOE_UNDER_BUS
	#define UNDER_DEV 	IOE_UNDER_DEV
	#define UNDER_FUN 	IOE_UNDER_FUN

	//
	// assign bus number for switch upstream port temp
	//
	AsiaPciWrite8(AsiaPciAddress(UNDER_BUS,UNDER_DEV,UNDER_FUN,0x18), BUS0);
	AsiaPciWrite8(AsiaPciAddress(UNDER_BUS,UNDER_DEV,UNDER_FUN,0x19), BUSX);
	AsiaPciWrite8(AsiaPciAddress(UNDER_BUS,UNDER_DEV,UNDER_FUN,0x1A), BUSXP1);
	Datax = AsiaPcieRead32((UINT64)PCI_BASE, AsiaPciAddress(UNDER_BUS, UNDER_DEV, UNDER_FUN, 0x18));
	PEI_DEBUG((PeiServices, EFI_D_ERROR, "[CJW_IOE] Assign--> After setting: [0,7,0]Rx18:%08X  \n",Datax));

	AsiaPciWrite8(AsiaPciAddress(BUSX,UPPORT_DEV,UPPORT_FUN,0x18), BUSX);
	AsiaPciWrite8(AsiaPciAddress(BUSX,UPPORT_DEV,UPPORT_FUN,0x19), BUSXP1);
	AsiaPciWrite8(AsiaPciAddress(BUSX,UPPORT_DEV,UPPORT_FUN,0x1A), BUSXP1);
	Datax = AsiaPcieRead32((UINT64)PCI_BASE, AsiaPciAddress(BUSX, UPPORT_DEV, UPPORT_FUN, 0x18));
	PEI_DEBUG((PeiServices, EFI_D_ERROR, "[CJW_IOE] Assign--> After setting: [1,0,0]Rx18:%08X  \n",Datax));		


	//
	// Assign MMIO space for BUSx D0F0
	//
	//MMIO address is 0xFE028000
	AsiaPciWrite8(AsiaPciAddress(BUSX, UPPORT_DEV, UPPORT_FUN, 0x13), (BUSX_MMIO_BAR>>24)&0xFF);
	AsiaPciWrite8(AsiaPciAddress(BUSX, UPPORT_DEV, UPPORT_FUN, 0x12), (BUSX_MMIO_BAR>>16)&0xFF);
	AsiaPciWrite8(AsiaPciAddress(BUSX, UPPORT_DEV, UPPORT_FUN, 0x11), (BUSX_MMIO_BAR>>8)&0xFF);
	AsiaPciWrite8(AsiaPciAddress(BUSX, UPPORT_DEV, UPPORT_FUN, 0x10), BUSX_MMIO_BAR&0xFF);
	Datax = AsiaPcieRead32((UINT64)PCI_BASE, AsiaPciAddress(BUSX, UPPORT_DEV, UPPORT_FUN, 0x10));
	PEI_DEBUG((PeiServices, EFI_D_ERROR, "[CJW_IOE] Assign--> After setting: [1,0,0]Rx10:%08X  \n",Datax));
	//Just for test
	Datax = AsiaPcieRead32((UINT64)PCI_BASE, AsiaPciAddress(BUSX, UPPORT_DEV, UPPORT_FUN, 0x00)); //CFG read DID VID
	PEI_DEBUG((PeiServices, EFI_D_ERROR, "[CJW_IOE] Assign--> Read IOE EP DIDVID=0x%08X\n",Datax));
	PEI_DEBUG((PeiServices, EFI_D_ERROR, "[CJW_IOE] Assign--> Read MMIO Rx18=0x%08X\n",AsiaMemoryRead32(0xFE028000+MMIO_ISB_OFFSET+0x18)));
	PEI_DEBUG((PeiServices, EFI_D_ERROR, "[CJW_IOE] Assign--> Read MMIO Rx18=0x%02X\n",AsiaMemoryRead8(0xFE028000+MMIO_ISB_OFFSET+0x18)));

	AsiaPciModify8(AsiaPciAddress(UNDER_BUS, UNDER_DEV, UNDER_FUN, 0x04), BIT0|BIT1|BIT2, BIT0|BIT1|BIT2);
	AsiaPciModify8(AsiaPciAddress(BUSX, UPPORT_DEV, UPPORT_FUN, 0x04), BIT0|BIT1|BIT2, BIT0|BIT1|BIT2);
		
	//Base/Limit setting   FE020000-FE03FFFF  --  for MB's RP
	AsiaPciWrite16(AsiaPciAddress(UNDER_BUS, UNDER_DEV, UNDER_FUN, 0x20), (BUSX_MMIO_BAR>>16)&0xFFFF);
	AsiaPciWrite16(AsiaPciAddress(UNDER_BUS, UNDER_DEV, UNDER_FUN, 0x22), ((BUSX_MMIO_BAR>>16)&0xFFFF)+1);
	


	//
	// PERST#  PCIe DN port through GPIO pin in CND003
	//
	//Read before PERST
	PEI_DEBUG((PeiServices, EFI_D_ERROR, "[CJW_IOE] RP PeRst#--> (x) [2|6|0] DIDVID = 0x%08X\n",AsiaPciRead32(AsiaPciAddress(2, 6, 0, 0x00))));
		
	//4 Memory Read Test       FE029100-FE02912C
	AsiaMemoryRead32(0xFE028000+MMIO_ISB_OFFSET+0x00); //Memory Read MMIO_ISB
	AsiaMemoryRead32(0xFE028000+MMIO_ISB_OFFSET+0x04);
	AsiaMemoryRead32(0xFE028000+MMIO_ISB_OFFSET+0x08);
	AsiaMemoryRead32(0xFE028000+MMIO_ISB_OFFSET+0x0C);
	AsiaMemoryRead32(0xFE028000+MMIO_ISB_OFFSET+0x10);
	AsiaMemoryRead32(0xFE028000+MMIO_ISB_OFFSET+0x14);
	AsiaMemoryRead32(0xFE028000+MMIO_ISB_OFFSET+0x18);
	AsiaMemoryRead32(0xFE028000+MMIO_ISB_OFFSET+0x1C);
	AsiaMemoryRead32(0xFE028000+MMIO_ISB_OFFSET+0x20);
	AsiaMemoryRead32(0xFE028000+MMIO_ISB_OFFSET+0x24);
	AsiaMemoryRead32(0xFE028000+MMIO_ISB_OFFSET+0x28);
	AsiaMemoryRead32(0xFE028000+MMIO_ISB_OFFSET+0x2C);


	//4 R_DBGINGPIOGRP_EN = 0  -->Rx10[4]=0
	AsiaMemoryModify16(BUSX_MMIO_BAR + MMIO_ISB_OFFSET+0x10, 0x0010, 0x0000);
	//4 R_JTAG_EN = 0 -->Rx10[5]=0
	AsiaMemoryModify16(BUSX_MMIO_BAR + MMIO_ISB_OFFSET+0x10, 0x0020, 0x0000);
	//4 GPIO PAD selection: -->Rx0C[0][2][4][6][8][10]=1 -->Rx0C=0x00000555
	AsiaMemoryModify16(BUSX_MMIO_BAR + MMIO_ISB_OFFSET+0x0C, 0x3<<0, 0x1<<0);
	AsiaMemoryModify16(BUSX_MMIO_BAR + MMIO_ISB_OFFSET+0x0C, 0x3<<2, 0x1<<2);
	AsiaMemoryModify16(BUSX_MMIO_BAR + MMIO_ISB_OFFSET+0x0C, 0x3<<4, 0x1<<4);
	AsiaMemoryModify16(BUSX_MMIO_BAR + MMIO_ISB_OFFSET+0x0C, 0x3<<6, 0x1<<6);
	AsiaMemoryModify16(BUSX_MMIO_BAR + MMIO_ISB_OFFSET+0x0C, 0x3<<8, 0x1<<8);
	AsiaMemoryModify16(BUSX_MMIO_BAR + MMIO_ISB_OFFSET+0x0C, 0x3<<10, 0x1<<10);
	PEI_DEBUG((PeiServices, EFI_D_ERROR, "[CJW_IOE] DN PeRst#-->PERST GPIO configuration:\n"));
	PEI_DEBUG((PeiServices, EFI_D_ERROR, "[CJW_IOE] DN PeRst#-->       MMIO Rx0C = 0x%08X\n",AsiaMemoryRead32(BUSX_MMIO_BAR+MMIO_ISB_OFFSET+0x0C)));

	//4 Read Rx1C3[LTSSM] of all ports
	PEI_DEBUG((PeiServices, EFI_D_ERROR, "[CJW_IOE] DN PeRst#-->       PEB0 Rx1C3 = 0x%02X\n",AsiaPcieRead8((UINT64)PCI_BASE, AsiaPciAddress(BUSXP1, PEB0, 0, 0)|(((UINT64)0x1C3) << 32))));
	PEI_DEBUG((PeiServices, EFI_D_ERROR, "[CJW_IOE] DN PeRst#-->       PEB1 Rx1C3 = 0x%02X\n",AsiaPcieRead8((UINT64)PCI_BASE, AsiaPciAddress(BUSXP1, PEB1, 0, 0)|(((UINT64)0x1C3) << 32))));
	PEI_DEBUG((PeiServices, EFI_D_ERROR, "[CJW_IOE] DN PeRst#-->       UP Rx1C3 = 0x%02X\n",AsiaPcieRead8((UINT64)PCI_BASE, AsiaPciAddress(BUSX, UPPORT_DEV, UPPORT_FUN, 0)|(((UINT64)0x1C3) << 32))));

	//4 Memory write 0xFE029104 = 0x0000_0000
	AsiaMemoryModify32(BUSX_MMIO_BAR + MMIO_ISB_OFFSET + 0x04, 1<<0, 0<<0);
	AsiaMemoryModify32(BUSX_MMIO_BAR + MMIO_ISB_OFFSET + 0x04, 1<<1, 0<<1);
	AsiaMemoryModify32(BUSX_MMIO_BAR + MMIO_ISB_OFFSET + 0x04, 1<<2, 0<<2);
	AsiaMemoryModify32(BUSX_MMIO_BAR + MMIO_ISB_OFFSET + 0x04, 1<<3, 0<<3);
	AsiaMemoryModify32(BUSX_MMIO_BAR + MMIO_ISB_OFFSET + 0x04, 1<<4, 0<<4);
	AsiaMemoryModify32(BUSX_MMIO_BAR + MMIO_ISB_OFFSET + 0x04, 1<<5, 0<<5);
	PeiNbPcieStallx(PeiServices, 200); //90ms
	PEI_DEBUG((PeiServices, EFI_D_ERROR, "[CJW_IOE] DN PeRst#--> 0\n"));
	PEI_DEBUG((PeiServices, EFI_D_ERROR, "[CJW_IOE] DN PeRst#--> EB0 Rx1C3 = 0x%02X\n",AsiaMemoryRead32(BUSX_MMIO_BAR + MMIO_ISB_OFFSET + 0x04)));
		

	//4 Read Rx1C3[LTSSM] of all ports
	PEI_DEBUG((PeiServices, EFI_D_ERROR, "[CJW_IOE] DN PeRst#-->       PEB0 Rx1C3 = 0x%02X\n",AsiaPcieRead8((UINT64)PCI_BASE, AsiaPciAddress(BUSXP1, PEB0, 0, 0)|(((UINT64)0x1C3) << 32))));
	PEI_DEBUG((PeiServices, EFI_D_ERROR, "[CJW_IOE] DN PeRst#-->       PEB1 Rx1C3 = 0x%02X\n",AsiaPcieRead8((UINT64)PCI_BASE, AsiaPciAddress(BUSXP1, PEB1, 0, 0)|(((UINT64)0x1C3) << 32))));
	PEI_DEBUG((PeiServices, EFI_D_ERROR, "[CJW_IOE] DN PeRst#-->       UP Rx1C3 = 0x%02X\n",AsiaPcieRead8((UINT64)PCI_BASE, AsiaPciAddress(BUSX, UPPORT_DEV, UPPORT_FUN, 0)|(((UINT64)0x1C3) << 32))));
		
	AsiaMemoryModify32(BUSX_MMIO_BAR+MMIO_ISB_OFFSET+0x04, 1<<0, 1<<0);
	AsiaMemoryModify32(BUSX_MMIO_BAR+MMIO_ISB_OFFSET+0x04, 1<<1, 1<<1);
	AsiaMemoryModify32(BUSX_MMIO_BAR+MMIO_ISB_OFFSET+0x04, 1<<2, 1<<2);
	AsiaMemoryModify32(BUSX_MMIO_BAR+MMIO_ISB_OFFSET+0x04, 1<<3, 1<<3);
	AsiaMemoryModify32(BUSX_MMIO_BAR+MMIO_ISB_OFFSET+0x04, 1<<4, 1<<4);
	AsiaMemoryModify32(BUSX_MMIO_BAR+MMIO_ISB_OFFSET+0x04, 1<<5, 1<<5);	
	PEI_DEBUG((PeiServices, EFI_D_ERROR, "[CJW_IOE] DN PeRst#--> 1\n"));
	PEI_DEBUG((PeiServices, EFI_D_ERROR, "[CJW_IOE] DN PeRst#--> EB0 Rx1C3 = 0x%02X\n",AsiaMemoryRead32(BUSX_MMIO_BAR + MMIO_ISB_OFFSET + 0x04)));

		
	//4 Read Rx1C3[LTSSM] of all ports
	PEI_DEBUG((PeiServices, EFI_D_ERROR, "[CJW_IOE] DN PeRst#-->       PEB0 Rx1C3 = 0x%02X\n",AsiaPcieRead8((UINT64)PCI_BASE, AsiaPciAddress(BUSXP1, PEB0, 0, 0)|(((UINT64)0x1C3) << 32))));
	PEI_DEBUG((PeiServices, EFI_D_ERROR, "[CJW_IOE] DN PeRst#-->       PEB1 Rx1C3 = 0x%02X\n",AsiaPcieRead8((UINT64)PCI_BASE, AsiaPciAddress(BUSXP1, PEB1, 0, 0)|(((UINT64)0x1C3) << 32))));
	PEI_DEBUG((PeiServices, EFI_D_ERROR, "[CJW_IOE] DN PeRst#-->       UP Rx1C3 = 0x%02X\n",AsiaPcieRead8((UINT64)PCI_BASE, AsiaPciAddress(BUSX, UPPORT_DEV, UPPORT_FUN, 0)|(((UINT64)0x1C3) << 32))));
	
	PeiNbPcieStallx(PeiServices, 200); //90ms

	//Read after PERST
	PEI_DEBUG((PeiServices, EFI_D_ERROR, "[CJW_IOE] RP PeRst#--> (x) [2|6|0] DIDVID = 0x%08X\n",AsiaPciRead32(AsiaPciAddress(2, 6, 0, 0x00))));
	//PEI_DEBUG((PeiServices, EFI_D_ERROR, "[CJW_IOE] DN PeRst#--> (C) [2|6|0] Rx05 = 0x%02X\n",AsiaPciRead8(AsiaPciAddress(2, 6, 0, 0x05))));

#if 0
	Datax = AsiaPcieRead8((UINT64)PCI_BASE, AsiaPciAddress(1, 0, 0, 0x4C));
	PEI_DEBUG((PeiServices, EFI_D_ERROR, "[CJW_IOE] RP PeRst#--> (S3)Rx4C=0x%02X([3:0] To check whether PCIE_Capability_Selection[] was loaded to CapRelatedReg)\n",Datax));
	Datax = AsiaPcieRead8((UINT64)PCI_BASE, AsiaPciAddress(1, 0, 0, 0x70));
	PEI_DEBUG((PeiServices, EFI_D_ERROR, "[CJW_IOE] RP PeRst#--> (S3)Rx4C=0x%02X([3:0] To check whether PCIE_Capability_Selection[] was loaded to CapRelatedReg)\n",Datax));
	Datax = AsiaPcieRead8((UINT64)PCI_BASE, AsiaPciAddress(2, 6, 0, 0x4C));
	PEI_DEBUG((PeiServices, EFI_D_ERROR, "[CJW_IOE] RP PeRst#--> (S3)Rx4C=0x%02X([3:0] To check whether PCIE_Capability_Selection[] was loaded to CapRelatedReg)\n",Datax));
	Datax = AsiaPcieRead8((UINT64)PCI_BASE, AsiaPciAddress(2, 6, 0, 0x70));
	PEI_DEBUG((PeiServices, EFI_D_ERROR, "[CJW_IOE] RP PeRst#--> (S3)Rx4C=0x%02X([3:0] To check whether PCIE_Capability_Selection[] was loaded to CapRelatedReg)\n",Datax));
	Datay = AsiaPcieRead16((UINT64)PCI_BASE, AsiaPciAddress(1, 0, 0, 0x1EA));
	PEI_DEBUG((PeiServices, EFI_D_ERROR, "[CJW_IOE] RP PeRst#--> (S3)Rx1EA=0x%04X([15:0] To check PCIE_Capability_Selection[])\n",Datay));
#endif				

	//
	// MMIO UART en
	//
	//CJW_IOE_FPGA_PATCH	
	AsiaMemoryModify32(BUSX_MMIO_BAR+MMIO_ISB_OFFSET+CND003_MMIO_D0F0_STRAPPING_PIN_READ_BACK_REG_GRP1, BIT12, 0);
	AsiaMemoryModify32(BUSX_MMIO_BAR+MMIO_ISB_OFFSET+CND003_MMIO_D0F0_STRAPPING_PIN_READ_BACK_REG_GRP1, BIT13, BIT13);
	AsiaMemoryModify32(BUSX_MMIO_BAR+MMIO_ISB_OFFSET+CND003_MMIO_D0F0_VCORE_GPIO_PAD_SEL, BIT29|BIT28, BIT29);
	for(i = 0; i< 0x40;i+=4){
		MmioData = AsiaMemoryRead32(BUSX_MMIO_BAR + MMIO_ISB_OFFSET + i);
		PEI_DEBUG((PeiServices, EFI_D_ERROR, "[CJW_IOE] MMIO content: offset 0x%02x->0x%08X \n",i, MmioData));
	}





#if 0
	//CJW_IOE_FPGA_PATCH
	//4 [3.3] Hide EPTRFC (To avoid additional trouble) BUSxD0F0 MMIO_ISB Rx30[8]
	{
		UINT8 XS;
		AsiaMemoryModify8(BUSX_MMIO_BAR + MMIO_ISB_OFFSET+0x52, BIT7, BIT7);
		
		XS = AsiaMemoryRead8(BUSX_MMIO_BAR + MMIO_ISB_OFFSET+0x52);
		PEI_DEBUG((PeiServices, EFI_D_ERROR, "[CJW_IOE] MMIO ISB Rx52 = 0x%02x \n",XS));
	}
#endif

	//
	// Release MMIO space for BUSx D0F0
	//

	//Base/Limit setting clear
	AsiaPciWrite16(AsiaPciAddress(UNDER_BUS, UNDER_DEV, UNDER_FUN, 0x20), 0);
	AsiaPciWrite16(AsiaPciAddress(UNDER_BUS, UNDER_DEV, UNDER_FUN, 0x22), 0);
	//
	AsiaPciModify8(AsiaPciAddress(UNDER_BUS, UNDER_DEV, UNDER_FUN, 0x04), BIT0|BIT1|BIT2, 0);
	AsiaPciModify8(AsiaPciAddress(BUSX, UPPORT_DEV, UPPORT_FUN, 0x04), BIT0|BIT1|BIT2, 0);
	//MMIO address is 0xFE028000
	AsiaPciWrite8(AsiaPciAddress(BUSX, UPPORT_DEV, UPPORT_FUN, 0x13), (0>>24)&0xFF);
	AsiaPciWrite8(AsiaPciAddress(BUSX, UPPORT_DEV, UPPORT_FUN, 0x12), (0>>16)&0xFF);
	AsiaPciWrite8(AsiaPciAddress(BUSX, UPPORT_DEV, UPPORT_FUN, 0x11), (0>>8)&0xFF);
	AsiaPciWrite8(AsiaPciAddress(BUSX, UPPORT_DEV, UPPORT_FUN, 0x10), 0&0xFF);
	Datax = AsiaPcieRead32((UINT64)PCI_BASE, AsiaPciAddress(BUSX, UPPORT_DEV, UPPORT_FUN, 0x10));
	PEI_DEBUG((PeiServices, EFI_D_INFO, "[CJW_IOE] ClearAssign--> After clear: [1,0,0]Rx10:%08X  \n",Datax));	


	
	//
	// release the temp bus number
	//
	AsiaPciWrite8(AsiaPciAddress(BUSX,UPPORT_DEV,UPPORT_FUN,0x18), 0);
	AsiaPciWrite8(AsiaPciAddress(BUSX,UPPORT_DEV,UPPORT_FUN,0x19), 0);
	AsiaPciWrite8(AsiaPciAddress(BUSX,UPPORT_DEV,UPPORT_FUN,0x1A), 0);
		
	AsiaPciWrite8(AsiaPciAddress(UNDER_BUS,UNDER_DEV,UNDER_FUN,0x18), 0);
	AsiaPciWrite8(AsiaPciAddress(UNDER_BUS,UNDER_DEV,UNDER_FUN,0x19), 0);
	AsiaPciWrite8(AsiaPciAddress(UNDER_BUS,UNDER_DEV,UNDER_FUN,0x1A), 0);		


	return EFI_SUCCESS;
}


/*
Careful: this routine need to fix to common use
we assume that IOE is behind the D7F0 PEG1
*/
STATIC
EFI_STATUS
IoePowerOnUpPortPeRst(
	IN EFI_PEI_SERVICES **PeiServices
)
{

	//4 [0] MB's RP PERST#
	//PeiNbResetPciePortx(PeiServices, CND001_PEG1);
	PeiNbResetPciePortx(PeiServices, CND001_PEG1);

	
	{	
		UINT8 Ltssm;
		UINT8 PresentDetect;
		
		//read Present Detect state
		PresentDetect = AsiaPcieRead8((UINT64)PCI_BASE, CND001_PEG1|(((UINT64)0x5A) << 32));
		if(PresentDetect & 0x40){
			PEI_DEBUG((PeiServices, EFI_D_ERROR, "[CJW_IOE] card present on D7F0\n"));
		}else{
			PEI_DEBUG((PeiServices, EFI_D_ERROR, "[CJW_IOE] card not present on D7F0\n"));
			return EFI_SUCCESS;
		}
		
		Ltssm = AsiaPcieRead8((UINT64)PCI_BASE, CND001_PEG1|(((UINT64)0x1C3) << 32));
		while(Ltssm != 0x8A){
			Ltssm = AsiaPcieRead8((UINT64)PCI_BASE, CND001_PEG1|(((UINT64)0x1C3) << 32));
			PEI_DEBUG((PeiServices, EFI_D_ERROR, "[CJW_IOE] Wait... PEG1 LTSSM 8A. current:0x%02X\n",Ltssm));
		}
		PEI_DEBUG((PeiServices, EFI_D_ERROR, "[CJW_IOE] PEG1 LTSSM 8A!\n"));
	}
	return EFI_SUCCESS;
}



EFI_STATUS
IoePowerOnPeRst(
	IN EFI_PEI_SERVICES **PeiServices
)
{

	//IoePowerOnUpPortPeRst(PeiServices);
	
	IoePowerOnDnPortPeRst(PeiServices);

	return EFI_SUCCESS;
}
#endif



void xHCI_MMIO_Bar_32bit_patch(IN EFI_PEI_SERVICES **PeiServices)
{
	UINT32 BAR0 = 0;
	//check whether BAR0 is 64 bit BAR
	BAR0 = AsiaPciRead32(CND003_XHCI|CND003_D18F0_XHCI_MEM_MAPPED_IO_LOW_BASE_ADR);
	
	if(BAR0 & BIT2)//64 bit, do not need patch
	{
	PEI_DEBUG((PeiServices, EFI_D_ERROR, "[ALJ_IOE] 64 bit, do not need patch!\n"));//do nothing
	}
	else//need patch
	{
	PEI_DEBUG((PeiServices, EFI_D_ERROR, "[ALJ_IOE] 32 bit,need patch!\n"));//do nothing
	AsiaPcieWrite32(0xE0000000, AsiaPciAddress(4, 0, 0, 0x180), 0x00190015);
	AsiaPcieWrite32(0xE0000000, AsiaPciAddress(4, 0, 0, 0x1C0), 0x80000000); 
	}
}

void UpdateIOESVIDSSID(void)
{
 AsiaPciWrite32(CND003_PEEP|CND003_BUSX_D0F0_SVID_CTL,AsiaPciRead32(CND003_PEEP|CND003_BUSX_D0F0_VID));//CND003_PEEP
 AsiaPciWrite32(CND003_PEA0|CND003_BUSXP1_D1D7F0_SVID_CTL,AsiaPciRead32(CND003_PEA0|CND003_BUSXP1_D1D7F0_VID_D1F0));//PEA0
 AsiaPciWrite32(CND003_PEA1|CND003_BUSXP1_D1D7F0_SVID_CTL,AsiaPciRead32(CND003_PEA1|CND003_BUSXP1_D1D7F0_VID_D1F0));//PEA1
 AsiaPciWrite32(CND003_PEA2|CND003_BUSXP1_D1D7F0_SVID_CTL,AsiaPciRead32(CND003_PEA2|CND003_BUSXP1_D1D7F0_VID_D1F0));//PEA2
 AsiaPciWrite32(CND003_PEA3|CND003_BUSXP1_D1D7F0_SVID_CTL,AsiaPciRead32(CND003_PEA3|CND003_BUSXP1_D1D7F0_VID_D1F0));//PEA3
 AsiaPciWrite32(CND003_PEA4|CND003_BUSXP1_D1D7F0_SVID_CTL,AsiaPciRead32(CND003_PEA4|CND003_BUSXP1_D1D7F0_VID_D1F0));//PEA4
 AsiaPciWrite32(CND003_PEB0|CND003_BUSXP1_D1D7F0_SVID_CTL,AsiaPciRead32(CND003_PEB0|CND003_BUSXP1_D1D7F0_VID_D1F0));//PEB0
 AsiaPciWrite32(CND003_PEB1|CND003_BUSXP1_D1D7F0_SVID_CTL,AsiaPciRead32(CND003_PEB1|CND003_BUSXP1_D1D7F0_VID_D1F0));//PEB1
 AsiaPciWrite32(CND003_PESB|CND003_BUSXP1_D1D7F0_SVID_CTL,AsiaPciRead32(CND003_PESB|CND003_BUSXP1_D1D7F0_VID_D1F0));//PESB
 AsiaPciModify8(CND003_PCIEIF|CND003_BUSX2_D0F0_GUARD_BIT_CTL,BIT0,BIT0);
 AsiaPciWrite32(CND003_PCIEIF|CND003_BUSX2_D0F0_SVID_CTL,AsiaPciRead32(CND003_PCIEIF|CND003_BUSX2_D0F0_VID));//CND003_PCIEIF
 AsiaPciModify8(CND003_PCIEIF|CND003_BUSX2_D0F0_GUARD_BIT_CTL,BIT0,0x0);
 
 //CND003_SATA
 AsiaPciModify8(CND003_SATA|CND003_D15F0_VID_ENCLOUSER_MANEGEMENT_BUFFER_CTL_OPTIONAL_REG,BIT1,BIT1);//SATA D15 F0 
 AsiaPciModify8(CND003_SATA|CND003_D15F0_VID_ENCLOUSER_MANEGEMENT_BUFFER_CTL_OPTIONAL_REG,BIT2|BIT3,0x0);//SATA D15 F0 

 //CND003_GNIC
 AsiaPciModify8(CND003_GNIC|0x60,BIT2,0x0);
 AsiaPciWrite32(CND003_GNIC|D13F0_SVID_AND_SSID_REGS,AsiaPciRead32(CND003_GNIC|D13F0_VENDER_ID_AND_DID));//CND003_PCIEIF
 //CND003_UHCI
 AsiaPciModify8(CND003_D14UHC0|IOEUHCI_CTL_REG_3,BIT4,BIT4);
 AsiaPciWrite32(CND003_D14UHC0|IOEUHCI_SVID,AsiaPciRead32(CND003_D14UHC0|IOEUHCI_VID));
 AsiaPciModify8(CND003_D14UHC0|IOEUHCI_CTL_REG_3,BIT4,0x0);
 AsiaPciModify8(CND003_D14UHC1|IOEUHCI_CTL_REG_3,BIT4,BIT4);
 AsiaPciWrite32(CND003_D14UHC1|IOEUHCI_SVID,AsiaPciRead32(CND003_D14UHC1|IOEUHCI_VID));
 AsiaPciModify8(CND003_D14UHC1|IOEUHCI_CTL_REG_3,BIT4,0x0);
 AsiaPciModify8(CND003_D14UHC2|IOEUHCI_CTL_REG_3,BIT4,BIT4);
 AsiaPciWrite32(CND003_D14UHC2|IOEUHCI_SVID,AsiaPciRead32(CND003_D14UHC2|IOEUHCI_VID));
 AsiaPciModify8(CND003_D14UHC2|IOEUHCI_CTL_REG_3,BIT4,0x0);

 AsiaPciModify8(CND003_D16UHC0|IOEUHCI_CTL_REG_3,BIT4,BIT4);
 AsiaPciWrite32(CND003_D16UHC0|IOEUHCI_SVID,AsiaPciRead32(CND003_D14UHC0|IOEUHCI_VID));
 AsiaPciModify8(CND003_D16UHC0|IOEUHCI_CTL_REG_3,BIT4,0x0);
 AsiaPciModify8(CND003_D16UHC1|IOEUHCI_CTL_REG_3,BIT4,BIT4);
 AsiaPciWrite32(CND003_D16UHC1|IOEUHCI_SVID,AsiaPciRead32(CND003_D14UHC1|IOEUHCI_VID));
 AsiaPciModify8(CND003_D16UHC1|IOEUHCI_CTL_REG_3,BIT4,0x0);
 AsiaPciModify8(CND003_D16UHC2|IOEUHCI_CTL_REG_3,BIT4,BIT4);
 AsiaPciWrite32(CND003_D16UHC2|IOEUHCI_SVID,AsiaPciRead32(CND003_D14UHC2|IOEUHCI_VID));
 AsiaPciModify8(CND003_D16UHC2|IOEUHCI_CTL_REG_3,BIT4,0x0);

 //CND003_EHCI
 AsiaPciModify8(CND003_D14EHCI|IOEEHCI_CTL_REG_2,BIT4,BIT4);
 AsiaPciWrite32(CND003_D14EHCI|IOEEHCI_SVID,AsiaPciRead32(CND003_D14EHCI|IOEEHCI_VID));
 AsiaPciModify8(CND003_D14EHCI|IOEEHCI_CTL_REG_2,BIT4,0x0);
 AsiaPciModify8(CND003_D16EHCI|IOEEHCI_CTL_REG_2,BIT4,BIT4);
 AsiaPciWrite32(CND003_D16EHCI|IOEEHCI_SVID,AsiaPciRead32(CND003_D16EHCI|IOEEHCI_VID)); 
 AsiaPciModify8(CND003_D16EHCI|IOEEHCI_CTL_REG_2,BIT4,0x0);
 //CND003_XHCI
 AsiaPciModify8(CND003_XHCI|CND003_D18F0_XHCI_OPTION_BITS_RX44_XHCOPTRX44,BIT0,0);
}

/**************************************************************************
// Normal Initialization of CND003
**************************************************************************/
/**
	VID DID RID lock bit setting 
**/
// TODO:  add VID lock code for ISB devices
STATIC
EFI_STATUS
IoeVidDidRidLock(
	IN EFI_PEI_SERVICES **PeiServices,
	ASIA_NB_CONFIGURATION *NbConfig
)
{
	PEI_DEBUG((PeiServices, EFI_D_ERROR, "[CJW_IOE] VID DID RID lock!\n"));

	AsiaPciModify8(AsiaPciAddress(BUSX, UPPORT_DEV, UPPORT_FUN, CND003_BUSX_D0F0_VEN_CTL), 
					CND003_BUSX_D0F0_DID_RID_LOCK|CND003_BUSX_D0F0_VID_LOCK, 
					CND003_BUSX_D0F0_DID_RID_LOCK|CND003_BUSX_D0F0_VID_LOCK);	//BusX D0F0 VID/DRID lock
	AsiaPciModify8(AsiaPciAddress(BUSXP1, XBCTL, DNPORT_FUN, CND003_MMIO_D0F0_BACKDOOR_REG_CTL_0), 
					CND003_MMIO_D0F0_DID_RID_LOCK|CND003_MMIO_D0F0_VID_LOCK, 
					CND003_MMIO_D0F0_DID_RID_LOCK|CND003_MMIO_D0F0_VID_LOCK); 

	if(NbConfig->IoeDnPortCtl == 1){
		//
		// Open the Backdoor
		//
		AsiaPciModify8(AsiaPciAddress(BUSXP1, XBCTL, DNPORT_FUN, CND003_MMIO_D0F0_BACKDOOR_REG_CTL_0), BIT0, BIT0);
		
		if(NbConfig->IoePEA0Ctl){
			PEI_DEBUG((PeiServices, EFI_D_ERROR, "          -->PEA0\n"));
			
			// Change VID to make difference between this chip with earlier chips
			AsiaPciModify8(AsiaPciAddress(BUSXP1, PEA0, DNPORT_FUN, CND003_BUSXP1_D1D7F0_REV_ID), 0xFF, 0x01);
			
			AsiaPciModify8(AsiaPciAddress(BUSXP1, PEA0, DNPORT_FUN, CND003_BUSXP1_D1D7F0_VEN_CTL_D1F0), 
						CND003_BUSXP1_D1D7F0_DID_RID_LOCK|CND003_BUSXP1_D1D7F0_VID_LOCK, 
						CND003_BUSXP1_D1D7F0_DID_RID_LOCK|CND003_BUSXP1_D1D7F0_VID_LOCK);	 
		}
		if(NbConfig->IoePEA1Ctl){
			PEI_DEBUG((PeiServices, EFI_D_ERROR, "          -->PEA1\n"));
			
			// Change VID to make difference between this chip with earlier chips
			AsiaPciModify8(AsiaPciAddress(BUSXP1, PEA1, DNPORT_FUN, CND003_BUSXP1_D1D7F0_REV_ID), 0xFF, 0x01);
			
			AsiaPciModify8(AsiaPciAddress(BUSXP1, PEA1, DNPORT_FUN, CND003_BUSXP1_D1D7F0_VEN_CTL_D1F0), 
						CND003_BUSXP1_D1D7F0_DID_RID_LOCK|CND003_BUSXP1_D1D7F0_VID_LOCK, 
						CND003_BUSXP1_D1D7F0_DID_RID_LOCK|CND003_BUSXP1_D1D7F0_VID_LOCK);	 
		}
		if(NbConfig->IoePEA2Ctl){
			PEI_DEBUG((PeiServices, EFI_D_ERROR, "          -->PEA2\n"));

			// Change VID to make difference between this chip with earlier chips
			AsiaPciModify8(AsiaPciAddress(BUSXP1, PEA2, DNPORT_FUN, CND003_BUSXP1_D1D7F0_REV_ID), 0xFF, 0x01);
			
			AsiaPciModify8(AsiaPciAddress(BUSXP1, PEA2, DNPORT_FUN, CND003_BUSXP1_D1D7F0_VEN_CTL_D1F0), 
						CND003_BUSXP1_D1D7F0_DID_RID_LOCK|CND003_BUSXP1_D1D7F0_VID_LOCK, 
						CND003_BUSXP1_D1D7F0_DID_RID_LOCK|CND003_BUSXP1_D1D7F0_VID_LOCK); 
		}
		if(NbConfig->IoePEA3Ctl){
			PEI_DEBUG((PeiServices, EFI_D_ERROR, "          -->PEA3\n"));

			// Change VID to make difference between this chip with earlier chips
			AsiaPciModify8(AsiaPciAddress(BUSXP1, PEA3, DNPORT_FUN, CND003_BUSXP1_D1D7F0_REV_ID), 0xFF, 0x01);
			
			AsiaPciModify8(AsiaPciAddress(BUSXP1, PEA3, DNPORT_FUN, CND003_BUSXP1_D1D7F0_VEN_CTL_D1F0), 
						CND003_BUSXP1_D1D7F0_DID_RID_LOCK|CND003_BUSXP1_D1D7F0_VID_LOCK, 
						CND003_BUSXP1_D1D7F0_DID_RID_LOCK|CND003_BUSXP1_D1D7F0_VID_LOCK);	 
		}
		if(NbConfig->IoePEA4Ctl){
			PEI_DEBUG((PeiServices, EFI_D_ERROR, "          -->PEA4\n"));

			// Change VID to make difference between this chip with earlier chips
			AsiaPciModify8(AsiaPciAddress(BUSXP1, PEA4, DNPORT_FUN, CND003_BUSXP1_D1D7F0_REV_ID), 0xFF, 0x01);
			
			AsiaPciModify8(AsiaPciAddress(BUSXP1, PEA4, DNPORT_FUN, CND003_BUSXP1_D1D7F0_VEN_CTL_D1F0), 
						CND003_BUSXP1_D1D7F0_DID_RID_LOCK|CND003_BUSXP1_D1D7F0_VID_LOCK, 
						CND003_BUSXP1_D1D7F0_DID_RID_LOCK|CND003_BUSXP1_D1D7F0_VID_LOCK);	 
		}
		if(NbConfig->IoePEB0Ctl){
			PEI_DEBUG((PeiServices, EFI_D_ERROR, "          -->PEB0\n"));

			// Change VID to make difference between this chip with earlier chips
			AsiaPciModify8(AsiaPciAddress(BUSXP1, PEB0, DNPORT_FUN, CND003_BUSXP1_D1D7F0_REV_ID), 0xFF, 0x01);
			
			AsiaPciModify8(AsiaPciAddress(BUSXP1, PEB0, DNPORT_FUN, CND003_BUSXP1_D1D7F0_VEN_CTL_D1F0), 
						CND003_BUSXP1_D1D7F0_DID_RID_LOCK|CND003_BUSXP1_D1D7F0_VID_LOCK, 
						CND003_BUSXP1_D1D7F0_DID_RID_LOCK|CND003_BUSXP1_D1D7F0_VID_LOCK);
		}
		if(NbConfig->IoePEB1Ctl){
			PEI_DEBUG((PeiServices, EFI_D_ERROR, "          -->PEB1\n"));

			// Change VID to make difference between this chip with earlier chips
			AsiaPciModify8(AsiaPciAddress(BUSXP1, PEB1, DNPORT_FUN, CND003_BUSXP1_D1D7F0_REV_ID), 0xFF, 0x01);
			
			AsiaPciModify8(AsiaPciAddress(BUSXP1, PEB1, DNPORT_FUN, CND003_BUSXP1_D1D7F0_VEN_CTL_D1F0), 
						CND003_BUSXP1_D1D7F0_DID_RID_LOCK|CND003_BUSXP1_D1D7F0_VID_LOCK, 
						CND003_BUSXP1_D1D7F0_DID_RID_LOCK|CND003_BUSXP1_D1D7F0_VID_LOCK);
		}

		//
		// Close the Backdoor
		//
		AsiaPciModify8(AsiaPciAddress(BUSXP1, XBCTL, DNPORT_FUN, CND003_MMIO_D0F0_BACKDOOR_REG_CTL_0), BIT0, 0);
	}


	
	AsiaPciModify8(AsiaPciAddress(BUSXP1, PESB, DNPORT_FUN, CND003_BUSXP1_D8F0_VEN_CTL), 
					CND003_BUSXP1_D8F0_DID_RID_LOCK|CND003_BUSXP1_D8F0_VID_LOCK, 
					CND003_BUSXP1_D8F0_DID_RID_LOCK|CND003_BUSXP1_D8F0_VID_LOCK);	 
	AsiaPciModify32(AsiaPciAddress(BUSXP2, PCIEIF_DEV, PCIEIF_FUN, CND003_BUSX2_D0F0_IOCFG), 
					CND003_BUSX2_D0F0_VID_LOCK|CND003_BUSX2_D0F0_DID_RID_LOCK, 
					CND003_BUSX2_D0F0_VID_LOCK|CND003_BUSX2_D0F0_DID_RID_LOCK);	 
	AsiaPciModify8(AsiaPciAddress(BUSXP3, EPTRFC_DEV, EPTRFC_FUN, CND003_EPTRFC_D0F0_DOWNSTREAM_CTL), 
					CND003_EPTRFC_D0F0_DID_LOCK|CND003_EPTRFC_D0F0_VID_LOCK, 
					CND003_EPTRFC_D0F0_DID_LOCK|CND003_EPTRFC_D0F0_VID_LOCK);	 
	//AsiaPciModify8(AsiaPciAddress(4, 15, 0, 0x7C), BIT1|BIT0, BIT1|BIT0);	 
				

	PEI_DEBUG((PeiServices, EFI_D_ERROR, "[CJW_IOE] After lock:\n"));
	PEI_DEBUG((PeiServices, EFI_D_ERROR, "          After lock: 0x%08x-Rx7C[1:0]\n",
		AsiaPciRead32(AsiaPciAddress(BUSX, UPPORT_DEV, UPPORT_FUN, CND003_BUSX_D0F0_VEN_CTL))));
	PEI_DEBUG((PeiServices, EFI_D_ERROR, "          After lock: 0x%08x-Rx40[4][1]\n",
		AsiaPciRead32(AsiaPciAddress(BUSXP1, XBCTL, DNPORT_FUN, CND003_MMIO_D0F0_BACKDOOR_REG_CTL_0))));
	PEI_DEBUG((PeiServices, EFI_D_ERROR, "          After lock: 0x%08x\n",
		AsiaPciRead32(AsiaPciAddress(BUSXP1, PEA0, DNPORT_FUN, CND003_BUSXP1_D1D7F0_VEN_CTL_D1F0))));
	PEI_DEBUG((PeiServices, EFI_D_ERROR, "          After lock: 0x%08x\n",
		AsiaPciRead32(AsiaPciAddress(BUSXP1, PEA1, DNPORT_FUN, CND003_BUSXP1_D1D7F0_VEN_CTL_D1F0))));
	PEI_DEBUG((PeiServices, EFI_D_ERROR, "          After lock: 0x%08x\n",
		AsiaPciRead32(AsiaPciAddress(BUSXP1, PEA2, DNPORT_FUN, CND003_BUSXP1_D1D7F0_VEN_CTL_D1F0))));
	PEI_DEBUG((PeiServices, EFI_D_ERROR, "          After lock: 0x%08x\n",
		AsiaPciRead32(AsiaPciAddress(BUSXP1, PEA3, DNPORT_FUN, CND003_BUSXP1_D1D7F0_VEN_CTL_D1F0))));
	PEI_DEBUG((PeiServices, EFI_D_ERROR, "          After lock: 0x%08x\n",
		AsiaPciRead32(AsiaPciAddress(BUSXP1, PEA4, DNPORT_FUN, CND003_BUSXP1_D1D7F0_VEN_CTL_D1F0))));
	PEI_DEBUG((PeiServices, EFI_D_ERROR, "          After lock: 0x%08x\n",
		AsiaPciRead32(AsiaPciAddress(BUSXP1, PEB0, DNPORT_FUN, CND003_BUSXP1_D1D7F0_VEN_CTL_D1F0))));
	PEI_DEBUG((PeiServices, EFI_D_ERROR, "          After lock: 0x%08x\n",
		AsiaPciRead32(AsiaPciAddress(BUSXP1, PEB1, DNPORT_FUN, CND003_BUSXP1_D1D7F0_VEN_CTL_D1F0))));
	PEI_DEBUG((PeiServices, EFI_D_ERROR, "          After lock: 0x%08x\n",
		AsiaPciRead32(AsiaPciAddress(BUSXP1, PESB, DNPORT_FUN, CND003_BUSXP1_D8F0_VEN_CTL))));
	PEI_DEBUG((PeiServices, EFI_D_ERROR, "          After lock: 0x%08x-Rx83[7:6]\n",
		AsiaPciRead32(AsiaPciAddress(BUSXP2, PCIEIF_DEV, PCIEIF_FUN, CND003_BUSX2_D0F0_IOCFG+3))));
	PEI_DEBUG((PeiServices, EFI_D_ERROR, "          After lock: 0x%08x-Rx62[4:3]\n",
		AsiaPciRead32(AsiaPciAddress(BUSXP3, EPTRFC_DEV, EPTRFC_FUN, CND003_EPTRFC_D0F0_DOWNSTREAM_CTL))));
	//PEI_DEBUG((PeiServices, EFI_D_ERROR, "[CJW_IOE] After lock: 0x%08x\n",AsiaPciRead32(AsiaPciAddress(4, 15, 0, 0x7C))));


	return EFI_SUCCESS;
}



/**
	CJW:
	This routine is for fpga patching
	all special patching for fpga should putin this routine
	this can separate Normal Module Code from FPGA Special patch 
	--Param:BusNum-->Bus number of BusXDOF0
**/
STATIC
VOID
IoeFpgaSpecialPatch(
	IN EFI_PEI_SERVICES **PeiServices)
{
	UINT8 Temp8xx;
	
//
// [patch 1] SATA channel 2 disable
//

	//[CJW_IOE_FPGA_PATCH]
	//this patch is for SATA controll IO space access fail
	//just for test - 20160421
	//---For Current status: We can't get into Windows without this patch
		
	Temp8xx = AsiaPcieRead8((UINT64)PCI_BASE, AsiaPciAddress(BUSXP3, DEV_SATA, FUN_SATA, 0x40));
	PEI_DEBUG((PeiServices, EFI_D_INFO, "[CJW_IOE_FPGA_PATCH] Rx40 = 0x%02x\n",Temp8xx));
		
	AsiaPcieModify8((UINT64)PCI_BASE, AsiaPciAddress(BUSXP3, DEV_SATA, FUN_SATA, 0x40), BIT0, 0);
		
	Temp8xx = AsiaPcieRead8((UINT64)PCI_BASE, AsiaPciAddress(BUSXP3, DEV_SATA, FUN_SATA, 0x40));
	PEI_DEBUG((PeiServices, EFI_D_INFO, "[CJW_IOE_FPGA_PATCH] Rx40 = 0x%02x\n",Temp8xx));


//
// [patch 2] UpStream port Rx7C[3] = 1 for CND003 HAPS verfiy
//

	//CJW_IOE_FPGA_PATCH
	//This just for FPGA verfiy
	PEI_DEBUG((PeiServices, EFI_D_INFO,"[CJW_IOE_FPGA_PATCH] Rx7C[3]=1b\n"));
	AsiaPciModify8(AsiaPciAddress(BUSX,UPPORT_DEV,UPPORT_FUN,CND003_BUSX_D0F0_VEN_CTL), CND003_BUSX_D0F0_ALLTRANS_SF, CND003_BUSX_D0F0_ALLTRANS_SF);

}



/**

@param
	PortNumber: A0 A1 A2 .. A4..B0 B1
**/
VOID
DebugIoeDnPortLink(
	IN EFI_PEI_SERVICES **PeiServices,
	IN ASIA_NB_CONFIGURATION *NbConfig,
	IN UINT64 Address,
	IN UINT8 PortNumber)
{
	UINT64 PcieBase = NbConfig->PcieBar;
	UINT8 Prsnt,LtssmStatus,LtssmStatusSave;
	
	Prsnt = AsiaPcieRead8(PcieBase, Address|((UINT64)CND003_BUSXP1_D1D7F0_SLOT_STA_1 << 32));
	Prsnt &= CND003_BUSXP1_D1D7F0_SPDCST;
	if(Prsnt){
		// found device
		LtssmStatusSave = AsiaPcieRead8(PcieBase, Address|((UINT64)CND003_BUSXP1_D1D7F0_PHYLS_LTSSM_STATE << 32));
		if(LtssmStatusSave != 0x8A){
			while(1){
				AsiaIoWrite8(0x80,0x88);
				PeiNbPcieStallx(PeiServices,800);

				AsiaIoWrite8(0x80,PortNumber);
				PeiNbPcieStallx(PeiServices,800);

				AsiaIoWrite8(0x80,LtssmStatusSave);
				PeiNbPcieStallx(PeiServices,800);

				LtssmStatus = AsiaPcieRead8(PcieBase, Address|((UINT64)CND003_BUSXP1_D1D7F0_PHYLS_LTSSM_STATE << 32));
				AsiaIoWrite8(0x80,LtssmStatus);
				PeiNbPcieStallx(PeiServices,1500);
			}
			
		}
	}else{
		// not found device
		return;
	}
	
}

/**
Note this routing maybe handle the CRS issue,  
	also, it may wait handle the BAD Device too. 
**/
EFI_STATUS
IoePcieCrsHandle(
	IN EFI_PEI_SERVICES **PeiServices,
	IN ASIA_NB_CONFIGURATION *NbConfig,
	IN UINT64 PcieAddr)
{
	UINT64 VPcieBar = 0;
	UINT8 TempBus;
	UINT16 VidTemp;
	EFI_STATUS Statusx = EFI_SUCCESS;
	UINT16 TimeoutCounter = 0;
	UINT8 SlotPrsnt = 0;
	
	VPcieBar = NbConfig->PcieBar;


	//to see whether port exist?
	VidTemp = AsiaPcieRead16(VPcieBar,PcieAddr|((UINT64)CND003_BUSXP1_D1D7F0_VID_D1F0 << 32));
	if(VidTemp == 0xFFFF){
		PEI_DEBUG((PeiServices, EFI_D_ERROR, "[IOE_PCIE_CRS] this port not exist, exit\n"));
		Statusx = EFI_UNSUPPORTED;
		goto __IOEHandleCrsExit;
	}

	//to see whether card exist?
	SlotPrsnt = (CND003_BUSXP1_D1D7F0_SPDCST & AsiaPcieRead8(VPcieBar,PcieAddr|((UINT64)CND003_BUSXP1_D1D7F0_SLOT_STA_1 << 32)));
	if(!SlotPrsnt){
		PEI_DEBUG((PeiServices, EFI_D_ERROR, "[IOE_PCIE_CRS] no device detected, exit\n"));
		Statusx = EFI_NOT_FOUND;
		goto __IOEHandleCrsExit;
	}
	
	// check whether Link in L0?
	if(0x8A != AsiaPcieRead8(VPcieBar,PcieAddr|((UINT64)CND003_BUSXP1_D1D7F0_PHYLS_LTSSM_STATE << 32))){
		PEI_DEBUG((PeiServices, EFI_D_ERROR, "[IOE_PCIE_CRS] Link Not L0!!\n"));
		Statusx = EFI_NOT_FOUND;
		goto __IOEHandleCrsExit;

	}
	
	//get the temp bus number of Device
	TempBus = AsiaPcieRead8(VPcieBar,PcieAddr|((UINT64)CND003_BUSXP1_D1D7F0_SECONDARY_BUS_NUM << 32));
	if(TempBus == 0){
		PEI_DEBUG((PeiServices, EFI_D_ERROR, "[IOE_PCIE_CRS] ERROR: temp bus number assigned failed!\n"));
		Statusx = EFI_NOT_FOUND;
		goto __IOEHandleCrsExit;
	}

	do{
		VidTemp = AsiaPcieRead16(VPcieBar,AsiaPciAddress(TempBus,0,0,0x00));
		if((VidTemp == 0xFFFF) ||( VidTemp == 0x0001)){

			TimeoutCounter++;
			if(TimeoutCounter >=2000){
				PEI_DEBUG((PeiServices, EFI_D_ERROR, "			 ERROR! CRS 2s Timeout(CRS issue)!\n"));
				Statusx = EFI_TIMEOUT;
				break;
			}
			PeiNbPcieStallx(PeiServices,1); //1ms
			VidTemp = AsiaPcieRead16(VPcieBar,AsiaPciAddress(TempBus,0,0,0));		
		}else{
			break;
		}
	}while(1);


__IOEHandleCrsExit:

		
	return Statusx;	
}
VOID
IoePeiSpeSettingInit(ASIA_NB_CONFIGURATION *NbCfg)
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
}

/**
@Use this function to search register offset of Specific capability
@Param:
	Busx,Devx,Funx: device routing ID
	PcieCap: when 1, search PCIE capability, when 0,search PCI capability
	CapId: target capability ID
@Return:
	Offset: register offset of target capability
	EFI_STATUS: search result, 
		when EFI_NOT_FOUND, not found capability
		when EFI_DEVICE_ERROR, device register abnormal
**/

EFI_STATUS
IOEPCIeSearchCapOffset(
	IN EFI_PEI_SERVICES **PeiServices,
	IN ASIA_NB_CONFIGURATION *NbConfig,
	IN UINT8 Busx,
	IN UINT8 Devx,
	IN UINT8 Funx,
	IN UINT8 PcieCap,
	IN UINT16 CapId,
	OUT UINT16* pOffset)
{
	EFI_STATUS Statusx = EFI_SUCCESS;
	UINT64 PcieBar = NbConfig->PcieBar;
	
	UINT8 CapIdP = 0xFF;
	UINT16 CapIdPe= 0xFF;
	
	UINT8 NextPtrP;
	UINT16 NextPtrPe;

	
	if(PcieCap){
		CapIdPe = CapId;
	}else{
		CapIdP = (UINT8) CapId; 
	}

	if(PcieCap){
		NextPtrPe = 0x100;
		while(NextPtrPe<0xFFF){
			PEI_DEBUG((PeiServices, EFI_D_ERROR, "       NextPtrP = 0x%x\n",NextPtrPe));	
			if(CapIdPe ==  AsiaPcieRead16(PcieBar, AsiaPciAddress(Busx,Devx,Funx,NextPtrPe))){
				//found it!
				*pOffset = NextPtrPe;
				break;
			}else{
				NextPtrPe = AsiaPcieRead16(PcieBar, AsiaPciAddress(Busx,Devx,Funx,NextPtrPe+2));
				NextPtrPe = NextPtrPe>>4;			
				if(NextPtrPe == 0){
					//end of this cap list
					*pOffset = 0;
					Statusx = EFI_NOT_FOUND;
					break;
				}
			}
		}

	}else{
		NextPtrP = AsiaPcieRead8(PcieBar, AsiaPciAddress(Busx,Devx,Funx,0x34));
		PEI_DEBUG((PeiServices, EFI_D_ERROR, " IOEPCIeSearchCapOffset NextPtrP is 0x%2x\n",NextPtrP));				
		
		if((NextPtrP == 0xFF) ||(NextPtrP == 0x00)){
			Statusx = EFI_DEVICE_ERROR;
			goto __DevCapExit;
		}		
		while(NextPtrP<0xFF){
			PEI_DEBUG((PeiServices, EFI_D_ERROR, "       NextPtrP = 0x%x\n",NextPtrP));	
			if(CapIdP ==  AsiaPcieRead8(PcieBar, AsiaPciAddress(Busx,Devx,Funx,NextPtrP))){
				//found it!
				*pOffset = (UINT16)NextPtrP;
				break;
			}else{
				NextPtrP = AsiaPcieRead8(PcieBar, AsiaPciAddress(Busx,Devx,Funx,NextPtrP+1));							
				if(NextPtrP == 0){
					//end of this cap list
					*pOffset = 0;
					Statusx = EFI_NOT_FOUND;
					break;
				}
			}
		}

	}
		
__DevCapExit:	
	if(Statusx != EFI_SUCCESS){
		PEI_DEBUG((PeiServices, EFI_D_ERROR, "       [%d:%d.%d]CapId(%04xh) Not Found!\n",Busx,Devx,Funx,CapId));				
	}else{
		PEI_DEBUG((PeiServices, EFI_D_ERROR, "       [%d:%d.%d]CapId(%04xh) at Rx%x\n",Busx,Devx,Funx,CapId,*pOffset));			
	}

	return Statusx;
}
/**
@Use this function to set RTRANS2TFIX, Downstream Ordering Queue Timing Option.
@Details

Downstream Ordering Queue Timing Option Programming rule:

1. IRS description: 
Rx1A2 [7] = 0: 1T setup time		1: 2T setup time

If Root Complex is connected to PCIe Endpoint, there is no problem.  
Because PCIe spec requires Endpoint CPL credits to be infinite.  
But if Root Complex is connected to "PCIe Switch", the CPL credits are finite.  
It may cause ERROR.  Need change this bit (RTRANS2TFIX) to 1.

2. Check policy
	a. Check DN Port connect EP PCIE Capability when RP setting done
	b. Check Device/Port Type in offset 0x02
	c. Check [7:4] = 0x05 Upstream Port of PCI Express Switch
	d. If EP is Upstream Port of PCI Express Switch, Set Rx1A2[7] = 1 then break this routine

3. Header define name:
CND003: CND003_BUSXP1_D1D7F0_DOWNSTREAM_CTL_3 , CND003_BUSXP1_D1D7F0_RTRANS2TFIX

**/

VOID
IOEPCIEDnOrderingQueueTiming(
	IN EFI_PEI_SERVICES **PeiServices,
    IN UINT8	BusNum,
    IN UINT8	DeviceNum,
    IN UINT8	FuncNum,
    IN ASIA_NB_CONFIGURATION *NbConfig,
    IN UINT8    PortSPEValue){

	UINT8 SlotCap, PcieCapSts, DevicePortType, secBus;
    UINT16 PcieCapOff = 0;
	EFI_STATUS Statusx = EFI_SUCCESS;

	PEI_DEBUG((PeiServices, EFI_D_ERROR, "[IOEPCIEDnOrderingQueueTiming] bus = 0x%02x, dev = 0x%02x, fun = 0x%02x\n",BusNum, DeviceNum, FuncNum));

	// If Root Port Slot Capabilities support Hot Plug, set Downstream Ordering Queue Timing Option = 2T
    SlotCap = AsiaPciRead8(AsiaPciAddress(BusNum, DeviceNum, FuncNum, CND003_BUSXP1_D1D7F0_SLOT_CAPS_1));
	SlotCap = SlotCap & CND003_BUSXP1_D1D7F0_SCHP_CAP;
	if( SlotCap == CND003_BUSXP1_D1D7F0_SCHP_CAP ){
		AsiaPcieModify8(NbConfig->PcieBar, (AsiaPciAddress(BusNum, DeviceNum, FuncNum, 
		   CND003_BUSXP1_D1D7F0_DOWNSTREAM_CTL_3)), CND003_BUSXP1_D1D7F0_RTRANS2TFIX, CND003_BUSXP1_D1D7F0_RTRANS2TFIX);
		return;
    }
	else{
	    secBus = AsiaPciRead8(AsiaPciAddress(BusNum, DeviceNum, FuncNum, 0x19));
	    PEI_DEBUG((PeiServices, EFI_D_ERROR, "[IOEPCIEDnOrderingQueueTiming] secbus = 0x%02x\n",secBus));
        if(secBus == 0){
			PEI_DEBUG((PeiServices, EFI_D_ERROR, "[IOEPCIEDnOrderingQueueTiming] Port not init\n"));
			return;
        	}
		   
	    //Search PCI Express Capability
	    Statusx = IOEPCIeSearchCapOffset(PeiServices,NbConfig,secBus,0,0,
						0,0x10,&PcieCapOff);
		
	    if(Statusx == EFI_SUCCESS){
	        PEI_DEBUG((PeiServices, EFI_D_ERROR, "[IOEPCIEDnOrderingQueueTiming] PcieCapOff = 0x%02x\n",PcieCapOff));
	        PcieCapSts = AsiaPciRead8(AsiaPciAddress(secBus, 0, 0, PcieCapOff + 0x02));
	        DevicePortType = ((PcieCapSts >> 4) & 0x0F);
	        if( DevicePortType == 0x05 ){
	 	        AsiaPcieModify8(NbConfig->PcieBar, (AsiaPciAddress(BusNum, DeviceNum, FuncNum, 
					CND003_BUSXP1_D1D7F0_DOWNSTREAM_CTL_3)), CND003_BUSXP1_D1D7F0_RTRANS2TFIX, CND003_BUSXP1_D1D7F0_RTRANS2TFIX);
		        return;
	 	    }
	    }
	 
		if(PortSPEValue >= DEVICE_SPE_VALUE_PERFORMANCE){
		 	AsiaPcieModify8(NbConfig->PcieBar, (AsiaPciAddress(BusNum, DeviceNum, FuncNum, 
			   CND003_BUSXP1_D1D7F0_DOWNSTREAM_CTL_3)), CND003_BUSXP1_D1D7F0_RTRANS2TFIX, 0);
		}
		else{
		 	AsiaPcieModify8(NbConfig->PcieBar, (AsiaPciAddress(BusNum, DeviceNum, FuncNum, 
			  CND003_BUSXP1_D1D7F0_DOWNSTREAM_CTL_3)), CND003_BUSXP1_D1D7F0_RTRANS2TFIX, CND003_BUSXP1_D1D7F0_RTRANS2TFIX); 
		} 
	    return;
		
   }
}


/**
	This function called to do some normal setting on CND003
**/
STATIC
EFI_STATUS
IoePcieNormalInit(
	IN EFI_PEI_SERVICES **PeiServices ,
	IN ASIA_NB_CONFIGURATION *NbConfig)
{

	UINT32 MmioBar;
	UINT8 tex = 0;
	UINT8 DnPortExistFlag = 0;
	UINT16 loopwait;
	
	IoePeiSpeSettingInit(NbConfig);
	
	MmioBar = AsiaPciRead32(AsiaPciAddress(BUSX, UPPORT_DEV, UPPORT_FUN, 0x10));


	//
	// Rx1B4[2:0] = 3'b001
	// Note: A0 chip will use this setting, 
	// Strict priority: FCU > ACK/NAK > TLP.
	// designer think this setting will have 
	// less influence on normal data transfer
	//
	//AsiaPcieModify8(PCI_BASE, AsiaPciAddress(BUSX,UPPORT_DEV,UPPORT_FUN, CND003_BUSX_D0F0_ARBITRATION_CTL), 
	//							CND003_BUSX_D0F0_RDLARB, BIT0);
	// PEEP Rx1A6[1] = 1
	//AsiaPcieModify8(PCI_BASE, AsiaPciAddress(BUSX,UPPORT_DEV,UPPORT_FUN,CND003_BUSX_D0F0_RESERVE_FOR_ECO),
	//							CND003_BUSX_D0F0_RXCPLODR, CND003_BUSX_D0F0_RXCPLODR);
	// PCIEIF Rx192[0] = 1
	//AsiaPcieModify8(PCI_BASE, AsiaPciAddress(BUSXP2,PCIEIF_DEV,PCIEIF_FUN,CND003_BUSX2_D0F0_TRANSACTION_LAYER_CTL), 
	//							CND003_BUSX2_D0F0_RDNCPLPRO, CND003_BUSX2_D0F0_RDNCPLPRO);


	//
	// CND003 TC7 Favor Mechanism Enable/Disable
	// PCIEIF RISOEN
	//
	if(NbConfig->Cnd003TCxFavor == 1){
		PEI_DEBUG((PeiServices, EFI_D_ERROR, "[CJW_IOE] TC7 Favor Mechanism [Enable]\n"));	

		// PCIEIF	
		// Isoch enable/disable
		AsiaPcieModify8(PCI_BASE, AsiaPciAddress(BUSXP2,PCIEIF_DEV,PCIEIF_FUN,CND003_BUSX2_D0F0_ISO_TRANSACTION_CTL), 
									CND003_BUSX2_D0F0_RISOEN, CND003_BUSX2_D0F0_RISOEN);
		// TC select = fix as TC7 now
		AsiaPcieModify8(PCI_BASE, AsiaPciAddress(BUSXP2,PCIEIF_DEV,PCIEIF_FUN,CND003_BUSX2_D0F0_ISO_TRANSACTION_CTL), 
									CND003_BUSX2_D0F0_RISOTC, CND003_BUSX2_D0F0_RISOTC);	

		// PEEP
		// Data Link TX Packets Arbitration Scheme
		// 		001: Strict priority: FCU > ACK/NAK > TLP.
		AsiaPcieModify8(PCI_BASE, AsiaPciAddress(BUSX,UPPORT_DEV,UPPORT_FUN,CND003_BUSX_D0F0_ARBITRATION_CTL), 
									CND003_BUSX_D0F0_RDLARB, 0x01);
		// Rx1A6[1] = 1
		AsiaPcieModify8(PCI_BASE, AsiaPciAddress(BUSX,UPPORT_DEV,UPPORT_FUN,CND003_BUSX_D0F0_RESERVE_FOR_ECO), 
									CND003_BUSX_D0F0_RXCPLODR, CND003_BUSX_D0F0_RXCPLODR);		
		// PCIEIF
		// Rx192[0] = 1  , default value is 1b
		AsiaPcieModify8(PCI_BASE, AsiaPciAddress(BUSXP2,PCIEIF_DEV,PCIEIF_FUN,CND003_BUSX2_D0F0_TRANSACTION_LAYER_CTL), 
									CND003_BUSX2_D0F0_RDNCPLPRO, CND003_BUSX2_D0F0_RDNCPLPRO);	

		// RxE8
		AsiaPcieModify16(PCI_BASE, AsiaPciAddress(BUSXP1,XBCTL,DNPORT_FUN,CND003_MMIO_D0F0_XBCTL_BW_CTL_22), 
									CND003_MMIO_D0F0_RRDTHR_GEN1_X1, 0x001);	
		
	}else{
		PEI_DEBUG((PeiServices, EFI_D_ERROR, "[CJW_IOE] TC7 Favor Mechanism [Disable]\n"));	
		PEI_DEBUG((PeiServices, EFI_D_ERROR, "          Set related register to default value!\n"));	
		
		// Isoch enable/disable
		AsiaPcieModify8(PCI_BASE, AsiaPciAddress(BUSXP2,PCIEIF_DEV,PCIEIF_FUN,CND003_BUSX2_D0F0_ISO_TRANSACTION_CTL), 
									CND003_BUSX2_D0F0_RISOEN, 0);	
		// TC select = select TC0   --- Default value is 111b
		AsiaPcieModify8(PCI_BASE, AsiaPciAddress(BUSXP2,PCIEIF_DEV,PCIEIF_FUN,0x1C8), 
									CND003_BUSX2_D0F0_RISOTC, CND003_BUSX2_D0F0_RISOTC);	

		// PEEP
		// Data Link TX Packets Arbitration Scheme
		// 		001: Strict priority: FCU > ACK/NAK > TLP.
		AsiaPcieModify8(PCI_BASE, AsiaPciAddress(BUSX,UPPORT_DEV,UPPORT_FUN,CND003_BUSX_D0F0_ARBITRATION_CTL), 
									CND003_BUSX_D0F0_RDLARB, 0x0);		
		// Rx1A6[1] = 0
		AsiaPcieModify8(PCI_BASE, AsiaPciAddress(BUSX,UPPORT_DEV,UPPORT_FUN,CND003_BUSX_D0F0_RESERVE_FOR_ECO), 
									CND003_BUSX_D0F0_RXCPLODR, 0);	
		// PCIEIF
		// Rx192[0] = 1  , default value is 1b
		AsiaPcieModify8(PCI_BASE, AsiaPciAddress(BUSXP2,PCIEIF_DEV,PCIEIF_FUN,CND003_BUSX2_D0F0_TRANSACTION_LAYER_CTL), 
									CND003_BUSX2_D0F0_RDNCPLPRO, CND003_BUSX2_D0F0_RDNCPLPRO);	

		// RxE8 - default value
		AsiaPcieModify16(PCI_BASE, AsiaPciAddress(BUSXP1,XBCTL,DNPORT_FUN,CND003_MMIO_D0F0_XBCTL_BW_CTL_22), 
									CND003_MMIO_D0F0_RRDTHR_GEN1_X1, 0x100);			

		
	}




	//
	// Disable some PCIE Switch downstream port 
	//
	// Note: 
	// Coding rules: 
	// 		[1] Setup default value is 0
	//		[2] GPIO_RESET_PExx 
	//
	// Special Note: Those code was not apply to EH2, 
	//				this is because there is a new circuit before GPIO connet to PERST# on Gold Finger,
	//				that make the RESET logic was inverted, so the RESET behavior here was not work
	if((NbConfig->IoePEA0PEXRST == 1)&&(NbConfig->IoeDnPortPEXRST == 1)){
		if(GPIO_RESET_PEA0 != 0xFF){
			tex = GPIO_RESET_PEA0;
			if((tex&0xF) == tex){   //for GPIO (lower then 0xF)
				AsiaMemoryModify16(MmioBar + MMIO_ISB_OFFSET + CND003_MMIO_D0F0_VCORE_GPIO_PAD_SEL, 
											0x3<<(tex<<1),0x0<<(tex<<1));
				AsiaMemoryModify16(MmioBar + MMIO_ISB_OFFSET + CND003_MMIO_D0F0_VCORE_GENERAL_PURPOSE_OUTPUT, 
											1<<tex, 0);
			}else{					//for GPO (higher then 0xF, lower then 0x20)
				tex = tex&0xF;		
				AsiaMemoryModify16(MmioBar + MMIO_ISB_OFFSET + CND003_MMIO_D0F0_VCORE_GPO_PAD_SEL, 
											0x03<<(tex<<1), 0x0<<(tex<<1));
				AsiaMemoryModify16(MmioBar + MMIO_ISB_OFFSET + CND003_MMIO_D0F0_VCORE_GPO_MODE_SETTING, 
											1<<tex, 0);
			}
			PEI_DEBUG((PeiServices, EFI_D_ERROR, "[CJW_IOE] PEA0 --> Disabled\n"));
		}	
	}
	if((NbConfig->IoePEA1PEXRST == 1)&&(NbConfig->IoeDnPortPEXRST == 1)){
		if(GPIO_RESET_PEA1 != 0xFF){
			tex = GPIO_RESET_PEA1;
			if((tex&0xF) == tex){
				AsiaMemoryModify16(MmioBar + MMIO_ISB_OFFSET + CND003_MMIO_D0F0_VCORE_GPIO_PAD_SEL, 
											0x3<<(tex<<1),0x0<<(tex<<1));
				AsiaMemoryModify16(MmioBar + MMIO_ISB_OFFSET + CND003_MMIO_D0F0_VCORE_GENERAL_PURPOSE_OUTPUT, 
											1<<tex, 0);			
			}else{
				tex = tex&0xF;
				AsiaMemoryModify16(MmioBar + MMIO_ISB_OFFSET + CND003_MMIO_D0F0_VCORE_GPO_PAD_SEL, 
											0x03<<(tex<<1), 0x0<<(tex<<1));
				AsiaMemoryModify16(MmioBar + MMIO_ISB_OFFSET + CND003_MMIO_D0F0_VCORE_GPO_MODE_SETTING, 
											1<<tex, 0);
			}
			PEI_DEBUG((PeiServices, EFI_D_ERROR, "[CJW_IOE] PEA1 --> Disabled\n"));
		}	
	}
	if((NbConfig->IoePEA2PEXRST == 1)&&(NbConfig->IoeDnPortPEXRST == 1)){
		if(GPIO_RESET_PEA2 != 0xFF){
			tex = GPIO_RESET_PEA2;
			if((tex&0xF) == tex){
				AsiaMemoryModify16(MmioBar + MMIO_ISB_OFFSET + CND003_MMIO_D0F0_VCORE_GPIO_PAD_SEL, 
											0x3<<(tex<<1),0x0<<(tex<<1));
				AsiaMemoryModify16(MmioBar + MMIO_ISB_OFFSET + CND003_MMIO_D0F0_VCORE_GENERAL_PURPOSE_OUTPUT, 
											1<<tex, 0);			
			}else{
				tex = tex&0xF;
				AsiaMemoryModify16(MmioBar + MMIO_ISB_OFFSET + CND003_MMIO_D0F0_VCORE_GPO_PAD_SEL, 
											0x03<<(tex<<1), 0x0<<(tex<<1));
				AsiaMemoryModify16(MmioBar + MMIO_ISB_OFFSET + CND003_MMIO_D0F0_VCORE_GPO_MODE_SETTING, 
											1<<tex, 0);
			}
			PEI_DEBUG((PeiServices, EFI_D_ERROR, "[CJW_IOE] PEA2 --> Disabled\n"));
		}	
	}
	if((NbConfig->IoePEA3PEXRST == 1)&&(NbConfig->IoeDnPortPEXRST == 1)){
		if(GPIO_RESET_PEA3 != 0xFF){
			tex = GPIO_RESET_PEA3;
			if((tex&0xF) == tex){
				AsiaMemoryModify16(MmioBar + MMIO_ISB_OFFSET + CND003_MMIO_D0F0_VCORE_GPIO_PAD_SEL, 
											0x3<<(tex<<1),0x0<<(tex<<1));
				AsiaMemoryModify16(MmioBar + MMIO_ISB_OFFSET + CND003_MMIO_D0F0_VCORE_GENERAL_PURPOSE_OUTPUT, 
											1<<tex, 0);			
			}else{
				tex = tex&0xF;
				AsiaMemoryModify16(MmioBar + MMIO_ISB_OFFSET + CND003_MMIO_D0F0_VCORE_GPO_PAD_SEL, 
											0x03<<(tex<<1), 0x0<<(tex<<1));
				AsiaMemoryModify16(MmioBar + MMIO_ISB_OFFSET + CND003_MMIO_D0F0_VCORE_GPO_MODE_SETTING, 
											1<<tex, 0);
			}
			PEI_DEBUG((PeiServices, EFI_D_ERROR, "[CJW_IOE] PEA3 --> Disabled\n"));
		}	
	}
	if((NbConfig->IoePEA4PEXRST == 1)&&(NbConfig->IoeDnPortPEXRST == 1)){
		if(GPIO_RESET_PEA4 != 0xFF){
			tex = GPIO_RESET_PEA4;
			if((tex&0xF) == tex){
				AsiaMemoryModify16(MmioBar + MMIO_ISB_OFFSET + CND003_MMIO_D0F0_VCORE_GPIO_PAD_SEL, 
											0x3<<(tex<<1),0x0<<(tex<<1));
				AsiaMemoryModify16(MmioBar + MMIO_ISB_OFFSET + CND003_MMIO_D0F0_VCORE_GENERAL_PURPOSE_OUTPUT, 
											1<<tex,0);			
			}else{
				tex = tex&0xF;
				AsiaMemoryModify16(MmioBar + MMIO_ISB_OFFSET + CND003_MMIO_D0F0_VCORE_GPO_PAD_SEL, 
											0x03<<(tex<<1), 0x0<<(tex<<1));
				AsiaMemoryModify16(MmioBar + MMIO_ISB_OFFSET + CND003_MMIO_D0F0_VCORE_GPO_MODE_SETTING, 
											1<<tex, 0);
			}
			PEI_DEBUG((PeiServices, EFI_D_ERROR, "[CJW_IOE] PEA4 --> Disabled\n"));
		}	
	}
	if((NbConfig->IoePEB0PEXRST == 1)&&(NbConfig->IoeDnPortPEXRST == 1)){
		if(GPIO_RESET_PEB0 != 0xFF){
			tex = GPIO_RESET_PEB0;
			if((tex&0xF) == tex){
				AsiaMemoryModify16(MmioBar + MMIO_ISB_OFFSET + CND003_MMIO_D0F0_VCORE_GPIO_PAD_SEL, 
											0x3<<(tex<<1),0x0<<(tex<<1));
				AsiaMemoryModify16(MmioBar + MMIO_ISB_OFFSET + CND003_MMIO_D0F0_VCORE_GENERAL_PURPOSE_OUTPUT, 
											1<<tex, 0);			
			}else{
				tex = tex&0xF;
				AsiaMemoryModify16(MmioBar + MMIO_ISB_OFFSET + CND003_MMIO_D0F0_VCORE_GPO_PAD_SEL, 
											0x03<<(tex<<1), 0x0<<(tex<<1));
				AsiaMemoryModify16(MmioBar + MMIO_ISB_OFFSET + CND003_MMIO_D0F0_VCORE_GPO_MODE_SETTING, 
											1<<tex, 0);
			}
			PEI_DEBUG((PeiServices, EFI_D_ERROR, "[CJW_IOE] PEB0 --> Disabled\n"));
		}	
	}
	if((NbConfig->IoePEB1PEXRST == 1)&&(NbConfig->IoeDnPortPEXRST == 1)){
		if(GPIO_RESET_PEB1 != 0xFF){
			tex = GPIO_RESET_PEB1;
			if((tex&0xF) == tex){
				AsiaMemoryModify16(MmioBar + MMIO_ISB_OFFSET + CND003_MMIO_D0F0_VCORE_GPIO_PAD_SEL, 
											0x3<<(tex<<1),0x0<<(tex<<1));
				AsiaMemoryModify16(MmioBar + MMIO_ISB_OFFSET + CND003_MMIO_D0F0_VCORE_GENERAL_PURPOSE_OUTPUT, 
											1<<tex, 0);			
			}else{
				tex = tex&0xF;
				AsiaMemoryModify16(MmioBar + MMIO_ISB_OFFSET + CND003_MMIO_D0F0_VCORE_GPO_PAD_SEL, 
											0x03<<(tex<<1), 0x0<<(tex<<1));
				AsiaMemoryModify16(MmioBar + MMIO_ISB_OFFSET + CND003_MMIO_D0F0_VCORE_GPO_MODE_SETTING, 
											1<<tex, 0);
			}
			PEI_DEBUG((PeiServices, EFI_D_ERROR, "[CJW_IOE] PEB1 --> Disabled\n"));
		}	
	}

	// @CJW_20170817
	// Those code was EH2 special code, for EH2 IOE DN ports, need software to control
	//	the time to release PERST#, and if we not do this for EH2, IOE DN ports will 
	//   never work correctly
	//NOTE:	
	//  PCISIG_PLUGFEST_WORKAROUND - we not use this token for those code because 
	//   even though the EH2 was for PCIE compliance test usage, but when we not do 
	//	compliance test, this setting still needed on EH2, in other words, those code was 
	//   EH2 specially but not Compliance test specially 
#if IOE_GPIO_CTL_PERST_RELEASE
		//
		// GPIO 0/1/2/3/5 - four IOE DN port slots on EC0_01 ,will take out NOR Circuit in future.
		//
		if(NbConfig->IoePEA0Ctl == 1){ 
			tex = GPIO_RESET_PEA0;
			AsiaMemoryModify16(MmioBar + MMIO_ISB_OFFSET + CND003_MMIO_D0F0_VCORE_GPIO_PAD_SEL, 
												0x3<<(tex<<1),0x0<<(tex<<1));
			AsiaMemoryModify16(MmioBar + MMIO_ISB_OFFSET + CND003_MMIO_D0F0_VCORE_GENERAL_PURPOSE_OUTPUT, 
												1<<tex, 0<<tex);	
			}
		if(NbConfig->IoePEA1Ctl == 1){ 
			tex = GPIO_RESET_PEA1;
			AsiaMemoryModify16(MmioBar + MMIO_ISB_OFFSET + CND003_MMIO_D0F0_VCORE_GPIO_PAD_SEL, 
												0x3<<(tex<<1),0x0<<(tex<<1));
			AsiaMemoryModify16(MmioBar + MMIO_ISB_OFFSET + CND003_MMIO_D0F0_VCORE_GENERAL_PURPOSE_OUTPUT, 
												1<<tex, 0<<tex);
		    }
		if(NbConfig->IoePEA2Ctl == 1){ 
			tex = GPIO_RESET_PEA2;
			AsiaMemoryModify16(MmioBar + MMIO_ISB_OFFSET + CND003_MMIO_D0F0_VCORE_GPIO_PAD_SEL, 
												0x3<<(tex<<1),0x0<<(tex<<1));
			AsiaMemoryModify16(MmioBar + MMIO_ISB_OFFSET + CND003_MMIO_D0F0_VCORE_GENERAL_PURPOSE_OUTPUT, 
												1<<tex, 0<<tex);
			}
		if(NbConfig->IoePEA3Ctl == 1){ 		
			tex = GPIO_RESET_PEA3;
			AsiaMemoryModify16(MmioBar + MMIO_ISB_OFFSET + CND003_MMIO_D0F0_VCORE_GPIO_PAD_SEL, 
												0x3<<(tex<<1),0x0<<(tex<<1));
			AsiaMemoryModify16(MmioBar + MMIO_ISB_OFFSET + CND003_MMIO_D0F0_VCORE_GENERAL_PURPOSE_OUTPUT, 
												1<<tex, 0<<tex);
			}
		if(NbConfig->IoePEA4Ctl == 1){ 
			tex = GPIO_RESET_PEA4;
			AsiaMemoryModify16(MmioBar + MMIO_ISB_OFFSET + CND003_MMIO_D0F0_VCORE_GPIO_PAD_SEL, 
												0x3<<(tex<<1),0x0<<(tex<<1));
			AsiaMemoryModify16(MmioBar + MMIO_ISB_OFFSET + CND003_MMIO_D0F0_VCORE_GENERAL_PURPOSE_OUTPUT, 
												1<<tex, 0<<tex);
			}
		
			PeiNbPcieStallx(PeiServices, 100);				
#endif

	// Retrain DN ports link
	// after toggle CFGDONE_TOGGLE, SI setting completed and set CFGDONE to 1
	// we need a link retrain for DN ports
	//  --- if not do this, some HWinit registers may not be updated when boot next time after change some 
	//		setup(example: link speed..)
	if((NbConfig->IoePEA0Ctl == 1)&&(NbConfig->IoeDnPortCtl == 1)){
		AsiaPcieModify8(PCI_BASE, AsiaPciAddress(BUSXP1, PEA0, DNPORT_FUN, CND003_BUSXP1_D1D7F0_LINK_CTL_1),
													CND003_BUSXP1_D1D7F0_LCRL, CND003_BUSXP1_D1D7F0_LCRL);
		DnPortExistFlag++;	
		//Wait L0(not wait CRS)
		for(loopwait=0 ; loopwait<1000; loopwait++){
			if(0x8A == AsiaPcieRead8(PCI_BASE, AsiaPciAddress(BUSXP1, PEA0, DNPORT_FUN, CND003_BUSXP1_D1D7F0_PHYLS_LTSSM_STATE))){
				break;
			}
		}
		IoePcieCrsHandle(PeiServices,NbConfig,CND003_PEA0);
		IOEPCIEDnOrderingQueueTiming(PeiServices,BUSXP1, PEA0, DNPORT_FUN,NbConfig,NbConfig->IOEXp1D1F0SPEValue);
	}
	if((NbConfig->IoePEA1Ctl == 1)&&(NbConfig->IoeDnPortCtl == 1)){
		AsiaPcieModify8(PCI_BASE, AsiaPciAddress(BUSXP1, PEA1, DNPORT_FUN, CND003_BUSXP1_D1D7F0_LINK_CTL_1),
													CND003_BUSXP1_D1D7F0_LCRL, CND003_BUSXP1_D1D7F0_LCRL);
		DnPortExistFlag++;
		//Wait L0(not wait CRS)
		for(loopwait=0 ; loopwait<1000; loopwait++){
			if(0x8A == AsiaPcieRead8(PCI_BASE, AsiaPciAddress(BUSXP1, PEA1, DNPORT_FUN, CND003_BUSXP1_D1D7F0_PHYLS_LTSSM_STATE))){
				break;
			}
		}	
		IoePcieCrsHandle(PeiServices,NbConfig,CND003_PEA1);
		IOEPCIEDnOrderingQueueTiming(PeiServices,BUSXP1, PEA1, DNPORT_FUN,NbConfig,NbConfig->IOEXp1D2F0SPEValue);
	}
	if((NbConfig->IoePEA2Ctl == 1)&&(NbConfig->IoeDnPortCtl == 1)){
		AsiaPcieModify8(PCI_BASE, AsiaPciAddress(BUSXP1, PEA2, DNPORT_FUN, CND003_BUSXP1_D1D7F0_LINK_CTL_1),
													CND003_BUSXP1_D1D7F0_LCRL, CND003_BUSXP1_D1D7F0_LCRL);
		DnPortExistFlag++;
		//Wait L0(not wait CRS)
		for(loopwait=0 ; loopwait<1000; loopwait++){
			if(0x8A == AsiaPcieRead8(PCI_BASE, AsiaPciAddress(BUSXP1, PEA2, DNPORT_FUN, CND003_BUSXP1_D1D7F0_PHYLS_LTSSM_STATE))){
				break;
			}
		}	
		IoePcieCrsHandle(PeiServices,NbConfig,CND003_PEA2);
		IOEPCIEDnOrderingQueueTiming(PeiServices,BUSXP1, PEA2, DNPORT_FUN,NbConfig,NbConfig->IOEXp1D3F0SPEValue);
	}
	if((NbConfig->IoePEA3Ctl == 1)&&(NbConfig->IoeDnPortCtl == 1)){
		AsiaPcieModify8(PCI_BASE, AsiaPciAddress(BUSXP1, PEA3, DNPORT_FUN, CND003_BUSXP1_D1D7F0_LINK_CTL_1),
													CND003_BUSXP1_D1D7F0_LCRL, CND003_BUSXP1_D1D7F0_LCRL);
		DnPortExistFlag++;
		//Wait L0(not wait CRS)
		for(loopwait=0 ; loopwait<1000; loopwait++){
			if(0x8A == AsiaPcieRead8(PCI_BASE, AsiaPciAddress(BUSXP1, PEA3, DNPORT_FUN, CND003_BUSXP1_D1D7F0_PHYLS_LTSSM_STATE))){
				break;
			}
		}
		IoePcieCrsHandle(PeiServices,NbConfig,CND003_PEA3);
		IOEPCIEDnOrderingQueueTiming(PeiServices,BUSXP1, PEA3, DNPORT_FUN,NbConfig,NbConfig->IOEXp1D4F0SPEValue);
	}
	if((NbConfig->IoePEA4Ctl == 1)&&(NbConfig->IoeDnPortCtl == 1)){
		AsiaPcieModify8(PCI_BASE, AsiaPciAddress(BUSXP1, PEA4, DNPORT_FUN, CND003_BUSXP1_D1D7F0_LINK_CTL_1),
													CND003_BUSXP1_D1D7F0_LCRL, CND003_BUSXP1_D1D7F0_LCRL);
		DnPortExistFlag++;
		//Wait L0(not wait CRS)
		for(loopwait=0 ; loopwait<1000; loopwait++){
			if(0x8A == AsiaPcieRead8(PCI_BASE, AsiaPciAddress(BUSXP1, PEA4, DNPORT_FUN, CND003_BUSXP1_D1D7F0_PHYLS_LTSSM_STATE))){
				break;
			}
		}
		IoePcieCrsHandle(PeiServices,NbConfig,CND003_PEA4);
		IOEPCIEDnOrderingQueueTiming(PeiServices,BUSXP1, PEA4, DNPORT_FUN,NbConfig,NbConfig->IOEXp1D5F0SPEValue);
	}
	if((NbConfig->IoePEB0Ctl == 1)&&(NbConfig->IoeDnPortCtl == 1)){
		AsiaPcieModify8(PCI_BASE, AsiaPciAddress(BUSXP1, PEB0, DNPORT_FUN, CND003_BUSXP1_D1D7F0_LINK_CTL_1),
													CND003_BUSXP1_D1D7F0_LCRL, CND003_BUSXP1_D1D7F0_LCRL);
		DnPortExistFlag++;
		//Wait L0(not wait CRS)
		for(loopwait=0 ; loopwait<1000; loopwait++){
			if(0x8A == AsiaPcieRead8(PCI_BASE, AsiaPciAddress(BUSXP1, PEB0, DNPORT_FUN, CND003_BUSXP1_D1D7F0_PHYLS_LTSSM_STATE))){
				break;
			}
		}	
		IoePcieCrsHandle(PeiServices,NbConfig,CND003_PEB0);
		IOEPCIEDnOrderingQueueTiming(PeiServices,BUSXP1, PEB0, DNPORT_FUN,NbConfig,NbConfig->IOEXp1D6F0SPEValue);
	}
	if((NbConfig->IoePEB1Ctl == 1)&&(NbConfig->IoeDnPortCtl == 1)){
		AsiaPcieModify8(PCI_BASE, AsiaPciAddress(BUSXP1, PEB1, DNPORT_FUN, CND003_BUSXP1_D1D7F0_LINK_CTL_1),
													CND003_BUSXP1_D1D7F0_LCRL, CND003_BUSXP1_D1D7F0_LCRL);
		DnPortExistFlag++;
		//Wait L0(not wait CRS)
		for(loopwait=0 ; loopwait<1000; loopwait++){
			if(0x8A == AsiaPcieRead8(PCI_BASE, AsiaPciAddress(BUSXP1, PEB1, DNPORT_FUN, CND003_BUSXP1_D1D7F0_PHYLS_LTSSM_STATE))){
				break;
			}
		}	
		IoePcieCrsHandle(PeiServices,NbConfig,CND003_PEB1);
		IOEPCIEDnOrderingQueueTiming(PeiServices,BUSXP1, PEB1, DNPORT_FUN,NbConfig,NbConfig->IOEXp1D7F0SPEValue);
	}
	/*if(DnPortExistFlag != 0){
		//delay 100ms
		PeiNbPcieStallx(PeiServices, 100);	
	}*/
	PEI_DEBUG((PeiServices, EFI_D_ERROR, "[CJW_IOE] PEA0 PEA1 PEA2 PEA3 PEA4 PEB0 PEB1 - LTSSM Rx1C3\n"));
	PEI_DEBUG((PeiServices, EFI_D_ERROR, "          %02x   %02x   %02x   %02x   %02x   %02x   %02x\n",
				AsiaPcieRead8(PCI_BASE, AsiaPciAddress(BUSXP1, PEA0, DNPORT_FUN, CND003_BUSXP1_D1D7F0_PHYLS_LTSSM_STATE)),
				AsiaPcieRead8(PCI_BASE, AsiaPciAddress(BUSXP1, PEA1, DNPORT_FUN, CND003_BUSXP1_D1D7F0_PHYLS_LTSSM_STATE)),
				AsiaPcieRead8(PCI_BASE, AsiaPciAddress(BUSXP1, PEA2, DNPORT_FUN, CND003_BUSXP1_D1D7F0_PHYLS_LTSSM_STATE)),
				AsiaPcieRead8(PCI_BASE, AsiaPciAddress(BUSXP1, PEA3, DNPORT_FUN, CND003_BUSXP1_D1D7F0_PHYLS_LTSSM_STATE)),
				AsiaPcieRead8(PCI_BASE, AsiaPciAddress(BUSXP1, PEA4, DNPORT_FUN, CND003_BUSXP1_D1D7F0_PHYLS_LTSSM_STATE)),
				AsiaPcieRead8(PCI_BASE, AsiaPciAddress(BUSXP1, PEB0, DNPORT_FUN, CND003_BUSXP1_D1D7F0_PHYLS_LTSSM_STATE)),
				AsiaPcieRead8(PCI_BASE, AsiaPciAddress(BUSXP1, PEB1, DNPORT_FUN, CND003_BUSXP1_D1D7F0_PHYLS_LTSSM_STATE))
			));	

	//
	// LTR Lswitch setting
	// Note: the actual Lswitch of IOE switch was located PEEP Rx1D9
	// 		software need to reprogram this register according to the 
	//		performance on silicon. For CND003 A0/A1 chip, this value 
	//		should be 0xD7(215ns)
	//		
	//		LTR Value on Upstream port = DnPortMinLatency - Lswitch
	//
	AsiaPcieModify8(NbConfig->PcieBar, AsiaPciAddress(BUSX, UPPORT_DEV, UPPORT_FUN, CND003_BUSX_D0F0_LTR_LSWITCH_VALUE), 
									0xFF, 0xD7);

	//
	// RPTOFFEN setting
	// Note:
	//  Timeout Period Enable
	//  This is newly added for CND003 to enable the timer of 
	//  counting the time of waiting PME_To_Ack from ISB. 
	//  While 1, the timer defined in Rx1D0[6:4] will start 
	//  counting to send PME_To_Ack while time-out 
	//  while 0, the counter is stall. Always waiting the PME_To_Ack from ISB.
	//
	// Note2; 
	//  Rx1D0[6:4] default is 32us(101b) timeout
	AsiaPcieModify8(NbConfig->PcieBar, 
					AsiaPciAddress(BUSX, UPPORT_DEV, UPPORT_FUN, CND003_BUSX_D0F0_PMU_TIMEOUT_AND_PMU_CTL), 
					CND003_BUSX_D0F0_RPTOFFEN, CND003_BUSX_D0F0_RPTOFFEN);
	//AsiaPcieModify8(NbConfig->PcieBar, 
	//				AsiaPciAddress(BUSX, UPPORT_DEV, UPPORT_FUN, CND003_BUSX_D0F0_PM_UNIT_PMU_CTL), 
	//				CND003_BUSX_D0F0_RPTOFF, LShiftU64(0x5, 4));



	//
	//	PCIEIF RCHGID Rx199[7] : Change SID
	//		change SID for PCI ISB device
	//
	if(NbConfig->Cnd003ChangeSIDForISB){
		//PCIEIF_Rx199[0] = 1b
		AsiaPcieModify8(NbConfig->PcieBar, 
						AsiaPciAddress(BUSXP2, PCIEIF_DEV, PCIEIF_FUN, CND003_BUSX2_D0F0_SHADOW_AND_PRIORITY_CTL), 
						CND003_BUSX2_D0F0_RCHGID, CND003_BUSX2_D0F0_RCHGID);
		//PCIEIF_Rx68[4] = 1(Disable Completion timout)   RDISCPLTM
		AsiaPcieModify8(NbConfig->PcieBar, 
						AsiaPciAddress(BUSXP2, PCIEIF_DEV, PCIEIF_FUN, CND003_BUSX2_D0F0_DEV_CTL_2), 
						CND003_BUSX2_D0F0_RDISCPLTM,CND003_BUSX2_D0F0_RDISCPLTM);		
	}



	//
	// Check CND003 DN port link status
	//
	// after PEI Link initialization, we need to check link status of all exist DN ports
	// those code just for debug
	//
#if 0	
	PeiNbPcieStallx(PeiServices, 100); //delay 100ms
	if((NbConfig->IoePEA0Ctl == 1)&&(NbConfig->IoeDnPortCtl == 1)){
		DebugIoeDnPortLink(PeiServices,NbConfig,CND003_PEA0,0xA0);
	}
	if((NbConfig->IoePEA1Ctl == 1)&&(NbConfig->IoeDnPortCtl == 1)){
		DebugIoeDnPortLink(PeiServices,NbConfig,CND003_PEA1,0xA1);
	}
	if((NbConfig->IoePEA2Ctl == 1)&&(NbConfig->IoeDnPortCtl == 1)){
		DebugIoeDnPortLink(PeiServices,NbConfig,CND003_PEA2,0xA2);
	}
	if((NbConfig->IoePEA3Ctl == 1)&&(NbConfig->IoeDnPortCtl == 1)){
		DebugIoeDnPortLink(PeiServices,NbConfig,CND003_PEA3,0xA3);
	}
	if((NbConfig->IoePEA4Ctl == 1)&&(NbConfig->IoeDnPortCtl == 1)){
		DebugIoeDnPortLink(PeiServices,NbConfig,CND003_PEA4,0xA4);	
	}
	if((NbConfig->IoePEB0Ctl == 1)&&(NbConfig->IoeDnPortCtl == 1)){
		DebugIoeDnPortLink(PeiServices,NbConfig,CND003_PEB0,0xB0);
	}
	if((NbConfig->IoePEB1Ctl == 1)&&(NbConfig->IoeDnPortCtl == 1)){
		DebugIoeDnPortLink(PeiServices,NbConfig,CND003_PEB1,0xB1);
	}	 
#endif

	return EFI_SUCCESS;
	
}



/**
	Calling this routine to set some registers 
	in BUSX MMIO Space 

	Note: Since we have assigned the resource for 
	Ioe before calling this routine, so we can 
	read BAR to get Base Address directly
**/
STATIC
EFI_STATUS
IoePcieMmioIsbInit(
	IN EFI_PEI_SERVICES **PeiServices ,
	IN ASIA_NB_CONFIGURATION *NbConfig)
{

	UINT32 MmioBar;
	EFI_STATUS Statusx = EFI_SUCCESS;

	//CJW_IOE_FPGA_DEBUG
	UINT32 MmioData;
	UINTN i;
	

	MmioBar = AsiaPciRead32(AsiaPciAddress(BUSX, UPPORT_DEV, UPPORT_FUN, 0x10));
	
	//
	// [2]SCI GPO Enable Setting
	//

	//SCI is GPO3 pinmux2 function
	//BXD0F0 MMIO ISB:
	//		RX10[4]=0 &
	//		SDBG_EN=0 &    --> sw can't control this, HW default to 0
	//		RX0C[23:22]=2'b10
//;cjw-A0-fixed 20161031
	if(NbConfig->Cnd003DbgPadG0En == 1){
		//Because the DbgPadG0En will use the pin of Rx10[4] while SCI output also
		//use this pin to signal the SCI, we skip the init to SCI if Dbgsignal Pad 
		//group 0 was enabled
		; 
	}else{
	/*
		PEI_DEBUG((PeiServices, EFI_D_INFO, "[CJW_IOE] SCI GPO enable\n"));
		PEI_DEBUG((PeiServices, EFI_D_INFO, "          MMIO_ISB Rx10=0x%02x\n",
					AsiaMemoryRead8(MmioBar+MMIO_ISB_OFFSET+0x10)));
		PEI_DEBUG((PeiServices, EFI_D_INFO, "          MMIO_ISB Rx0C=0x%08x\n",
					AsiaMemoryRead32(MmioBar+MMIO_ISB_OFFSET+0x0C)));
		AsiaMemoryModify8(MmioBar + MMIO_ISB_OFFSET + 0x10, BIT4, 0);
		AsiaMemoryModify32(MmioBar + MMIO_ISB_OFFSET + 0x0C, BIT23|BIT22, BIT23);
		PEI_DEBUG((PeiServices, EFI_D_INFO, "          MMIO_ISB Rx10=0x%02x -->bit4=0\n",
					AsiaMemoryRead8(MmioBar+MMIO_ISB_OFFSET+0x10)));
		PEI_DEBUG((PeiServices, EFI_D_INFO, "          MMIO_ISB Rx0C=0x%08x-->bit23:22=2'b10\n",
					AsiaMemoryRead32(MmioBar+MMIO_ISB_OFFSET+0x0C)));	
	*/	
	}
//;cjw-A0-fixed END

		
	//
	// [3] MMIO UART en
	// 		this code just set the pinmux to the UART Tx/Rx Usage.
	//
	if(NbConfig->Cnd003UartPinEn == 1){
		PEI_DEBUG((PeiServices, EFI_D_ERROR, "[CJW_IOE_MCU_UART] Pinmux to 8051 MCU UART en\n"));
		AsiaMemoryModify32(MmioBar + MMIO_ISB_OFFSET + CND003_MMIO_D0F0_STRAPPING_PIN_READ_BACK_REG_GRP_1, BIT12, 0);
		AsiaMemoryModify32(MmioBar + MMIO_ISB_OFFSET + CND003_MMIO_D0F0_STRAPPING_PIN_READ_BACK_REG_GRP_1, BIT13, BIT13);
		AsiaMemoryModify32(MmioBar + MMIO_ISB_OFFSET + CND003_MMIO_D0F0_VCORE_GPIO_PAD_SEL, BIT29|BIT28, BIT29);
	} else if(NbConfig->Cnd003UartPinEn == 2){
	    PEI_DEBUG((PeiServices, EFI_D_ERROR, "[CJW_IOE_MCU_UART] Pinmux to XHCI MCU UART en\n"));
		AsiaMemoryModify32(MmioBar + MMIO_ISB_OFFSET + CND003_MMIO_D0F0_STRAPPING_PIN_READ_BACK_REG_GRP_1, BIT12, BIT12);
		AsiaMemoryModify32(MmioBar + MMIO_ISB_OFFSET + CND003_MMIO_D0F0_STRAPPING_PIN_READ_BACK_REG_GRP_1, BIT13, BIT13);
		AsiaMemoryModify32(MmioBar + MMIO_ISB_OFFSET + CND003_MMIO_D0F0_VCORE_GPIO_PAD_SEL, BIT29|BIT28, BIT29);
	}


	for(i = 0; i< 0x40;i+=4){
		MmioData = AsiaMemoryRead32(MmioBar + MMIO_ISB_OFFSET + i);
		PEI_DEBUG((PeiServices, EFI_D_ERROR, "                   MMIO content: offset 0x%02x->0x%08X \n",i, MmioData));
	}	
	PEI_DEBUG((PeiServices, EFI_D_ERROR, "\n"));


	return Statusx;
}



/**
     Use shadow register to patch some register,should set after PEXRST
     1,Patch PCIEIF Rx64[11]=1,Rx68[10]=1(RW)
**/
EFI_STATUS
IoePeiPatch(
	IN EFI_PEI_SERVICES  **PeiServices,
	ASIA_NB_CONFIGURATION *NbCfg)
{
    UINT64 PcieBase;
    UINT16 temp;
	PcieBase = PCI_BASE;  
	//1,Patch PCIEIF Rx64[11]=1,RO.
	AsiaPcieWrite16(PcieBase, CND003_PCIEIF|((UINT64)CND003_BUSX2_D0F0_SHADOW_REG_BYTE_0<<32),0x65);
	temp=AsiaPcieRead16(PcieBase,CND003_PCIEIF|((UINT64)CND003_BUSX2_D0F0_SHADOW_REG_BYTE_0<<32));
	PEI_DEBUG((PeiServices, EFI_D_ERROR, "IoePeiNbPreInitPatch 0x1A8:[%x]\n",temp));
	AsiaPcieModify8(PcieBase,CND003_PCIEIF|((UINT64)CND003_BUSX2_D0F0_SHADOW_AND_PRIORITY_CTL<<32),BIT6,BIT6);
	AsiaPcieModify32(PcieBase,CND003_PCIEIF|((UINT64)CND003_BUSX2_D0F0_SHADOW_REG_READ_AND_WRITE_CTL<<32),BIT0|BIT8,BIT0|BIT8);
	AsiaPcieModify16(PcieBase,CND003_PCIEIF|CND003_BUSX2_D0F0_DEV_CAPS_2,BIT11,BIT11);
	AsiaPcieModify32(PcieBase,CND003_PCIEIF|((UINT64)CND003_BUSX2_D0F0_SHADOW_REG_READ_AND_WRITE_CTL<<32),BIT0,0);

	//2,Patch PCIEIF Rx68[10]=RW;
	AsiaPcieWrite16(PcieBase, CND003_PCIEIF|((UINT64)CND003_BUSX2_D0F0_SHADOW_REG_BYTE_1<< 32),0x69);
	AsiaPcieModify8(PcieBase,CND003_PCIEIF|((UINT64)CND003_BUSX2_D0F0_SHADOW_AND_PRIORITY_CTL<<32),BIT6,BIT6);
	AsiaPcieModify32(PcieBase,CND003_PCIEIF|((UINT64)CND003_BUSX2_D0F0_SHADOW_REG_READ_AND_WRITE_CTL<<32),BIT1|BIT9,BIT1|BIT9);
	return EFI_SUCCESS;
}

EFI_STATUS
IoePeiDIDVID(
	IN EFI_PEI_SERVICES  **PeiServices,
	ASIA_NB_CONFIGURATION *NbCfg)
{
    UINT64 PcieBase;
	PcieBase = PCI_BASE;
#ifdef ZX_SECRET_CODE
	if(NbCfg->Cnd003DIDVIDChoose == 0){		 
	//Not VAS 
		//temp=0x1106;
		AsiaPcieModify8(PcieBase,CND003_XBCTL|CND003_MMIO_D0F0_BACKDOOR_REG_CTL_0,BIT0,BIT0);//Rx40[0]=1
	    //PEEP
	    AsiaPcieWrite16(PcieBase, CND003_PEEP|CND003_BUSX_D0F0_VID,0x1106);
		AsiaPcieModify8(PcieBase,CND003_PEEP|CND003_BUSX_D0F0_VEN_CTL,BIT0,BIT0);
	    //XBCTL
	    AsiaPcieWrite16(PcieBase, CND003_XBCTL|CND003_MMIO_D0F0_VID,0x1106);
		AsiaPcieModify8(PcieBase,CND003_XBCTL|CND003_MMIO_D0F0_BACKDOOR_REG_CTL_0,BIT1,BIT1);
		//PEA0
		AsiaPcieWrite16(PcieBase, CND003_PEA0|CND003_BUSXP1_D1D7F0_VID_D1F0,0x1106);
		AsiaPcieModify8(PcieBase,CND003_PEA0|CND003_BUSXP1_D1D7F0_VEN_CTL_D1F0,BIT0,BIT0);
		//PEA1
		AsiaPcieWrite16(PcieBase, CND003_PEA1|CND003_BUSXP1_D1D7F0_VID_D1F0,0x1106);
		AsiaPcieModify8(PcieBase,CND003_PEA1|CND003_BUSXP1_D1D7F0_VEN_CTL_D1F0,BIT0,BIT0);
		//PEA2
		AsiaPcieWrite16(PcieBase, CND003_PEA2|CND003_BUSXP1_D1D7F0_VID_D1F0,0x1106);
		AsiaPcieModify8(PcieBase,CND003_PEA2|CND003_BUSXP1_D1D7F0_VEN_CTL_D1F0,BIT0,BIT0);
		//PEA3
		AsiaPcieWrite16(PcieBase, CND003_PEA3|CND003_BUSXP1_D1D7F0_VID_D1F0,0x1106);
		AsiaPcieModify8(PcieBase,CND003_PEA3|CND003_BUSXP1_D1D7F0_VEN_CTL_D1F0,BIT0,BIT0);
		//PEA4
		AsiaPcieWrite16(PcieBase, CND003_PEA4|CND003_BUSXP1_D1D7F0_VID_D1F0,0x1106);
		AsiaPcieModify8(PcieBase,CND003_PEA4|CND003_BUSXP1_D1D7F0_VEN_CTL_D1F0,BIT0,BIT0);
		//PEB0
		AsiaPcieWrite16(PcieBase, CND003_PEB0|CND003_BUSXP1_D1D7F0_VID_D1F0,0x1106);
		AsiaPcieModify8(PcieBase,CND003_PEB0|CND003_BUSXP1_D1D7F0_VEN_CTL_D1F0,BIT0,BIT0);
		//PEB1
		AsiaPcieWrite16(PcieBase, CND003_PEB1|CND003_BUSXP1_D1D7F0_VID_D1F0,0x1106);
		AsiaPcieModify8(PcieBase,CND003_PEB1|CND003_BUSXP1_D1D7F0_VEN_CTL_D1F0,BIT0,BIT0);
	    //PESB
	    AsiaPcieWrite16(PcieBase, CND003_PESB|CND003_BUSXP1_D8F0_VID,0x1106);
		AsiaPcieModify8(PcieBase,CND003_PESB|CND003_BUSXP1_D8F0_VEN_CTL,BIT0,BIT0);
		//PCIEIF
		AsiaPcieWrite16(PcieBase, CND003_PCIEIF|CND003_BUSX2_D0F0_VID,0x1106);
		AsiaPcieModify8(PcieBase,CND003_PCIEIF|(CND003_BUSX2_D0F0_IOCFG+3),BIT7,BIT7);
		//EPTRFC
		AsiaPcieWrite16(PcieBase, CND003_EPTRFC|CND003_EPTRFC_D0F0_VID,0x1106);
		AsiaPcieModify8(PcieBase, CND003_EPTRFC|CND003_EPTRFC_D0F0_DOWNSTREAM_CTL,BIT3,BIT3);
		//SATA
		AsiaPcieWrite16(PcieBase, CND003_SATA|CND003_D15F0_VID,0x1106);
		AsiaPcieModify8(PcieBase, CND003_SATA|CND003_D15F0_VID_ENCLOUSER_MANEGEMENT_BUFFER_CTL_OPTIONAL_REG,BIT0,BIT0);
		//GNIC
		AsiaPcieWrite16(PcieBase, CND003_GNIC|D13F0_VENDER_ID_AND_DID,0x1106);
		AsiaPcieModify8(PcieBase,CND003_GNIC|0x60,BIT1,BIT1);
		//XHCI
		AsiaPcieWrite16(PcieBase, CND003_XHCI|CND003_D18F0_VID,0x1106);
		AsiaPcieModify8(PcieBase,CND003_XHCI|CND003_D18F0_XHCI_OPTION_BITS_RX45_XHCOPTRX45,BIT4,BIT4);
		//UHCI
		AsiaPcieWrite16(PcieBase, CND003_D14UHC0|IOEUHCI_DID_OPTIONAL,0x1106);
		AsiaPcieModify8(PcieBase,CND003_D14UHC0|IOEUHCI_FLR_AND_VID_OPTIONAL_REG,BIT2,BIT2);
		AsiaPcieWrite16(PcieBase, CND003_D14UHC1|IOEUHCI_DID_OPTIONAL,0x1106);
		AsiaPcieModify8(PcieBase,CND003_D14UHC1|IOEUHCI_FLR_AND_VID_OPTIONAL_REG,BIT2,BIT2);
		AsiaPcieWrite16(PcieBase, CND003_D14UHC2|IOEUHCI_DID_OPTIONAL,0x1106);
		AsiaPcieModify8(PcieBase,CND003_D14UHC2|IOEUHCI_FLR_AND_VID_OPTIONAL_REG,BIT2,BIT2);
		AsiaPcieWrite16(PcieBase, CND003_D16UHC0|IOEUHCI_DID_OPTIONAL,0x1106);
		AsiaPcieModify8(PcieBase,CND003_D16UHC0|IOEUHCI_FLR_AND_VID_OPTIONAL_REG,BIT2,BIT2);
		AsiaPcieWrite16(PcieBase, CND003_D16UHC1|IOEUHCI_DID_OPTIONAL,0x1106);
		AsiaPcieModify8(PcieBase,CND003_D16UHC1|IOEUHCI_FLR_AND_VID_OPTIONAL_REG,BIT2,BIT2);
		AsiaPcieWrite16(PcieBase, CND003_D16UHC2|IOEUHCI_DID_OPTIONAL,0x1106);
		AsiaPcieModify8(PcieBase,CND003_D16UHC2|IOEUHCI_FLR_AND_VID_OPTIONAL_REG,BIT2,BIT2);
		//EHCI
	    AsiaPcieWrite16(PcieBase, CND003_D14EHCI|IOEEHCI_DID_OPTIONAL_Z2,0x1106);
		AsiaPcieModify8(PcieBase,CND003_D14EHCI|IOEEHCI_FLR_AND_VID_OPTIONAL_REG,BIT2,BIT2);
		AsiaPcieWrite16(PcieBase, CND003_D16EHCI|IOEEHCI_DID_OPTIONAL_Z2,0x1106);
		AsiaPcieModify8(PcieBase,CND003_D16EHCI|IOEEHCI_FLR_AND_VID_OPTIONAL_REG,BIT2,BIT2);

	}
	else{	
	//VAS
#endif
		//temp=(UINT16)0x1D17;
		AsiaPcieModify8(PcieBase,CND003_XBCTL|CND003_MMIO_D0F0_BACKDOOR_REG_CTL_0,BIT0,BIT0);//Rx40[0]=1
	    //PEEP
	    AsiaPcieWrite16(PcieBase, CND003_PEEP|CND003_BUSX_D0F0_VID,0x1D17);
		AsiaPcieModify8(PcieBase,CND003_PEEP|CND003_BUSX_D0F0_VEN_CTL,BIT0,BIT0);
	    //XBCTL
	    AsiaPcieWrite16(PcieBase, CND003_XBCTL|CND003_MMIO_D0F0_VID,0x1D17);
		AsiaPcieModify8(PcieBase,CND003_XBCTL|CND003_MMIO_D0F0_BACKDOOR_REG_CTL_0,BIT1,BIT1);
		//PEA0
		AsiaPcieWrite16(PcieBase, CND003_PEA0|CND003_BUSXP1_D1D7F0_VID_D1F0,0x1D17);
		AsiaPcieModify8(PcieBase,CND003_PEA0|CND003_BUSXP1_D1D7F0_VEN_CTL_D1F0,BIT0,BIT0);
		//PEA1
		AsiaPcieWrite16(PcieBase, CND003_PEA1|CND003_BUSXP1_D1D7F0_VID_D1F0,0x1D17);
		AsiaPcieModify8(PcieBase,CND003_PEA1|CND003_BUSXP1_D1D7F0_VEN_CTL_D1F0,BIT0,BIT0);
		//PEA2
		AsiaPcieWrite16(PcieBase, CND003_PEA2|CND003_BUSXP1_D1D7F0_VID_D1F0,0x1D17);
		AsiaPcieModify8(PcieBase,CND003_PEA2|CND003_BUSXP1_D1D7F0_VEN_CTL_D1F0,BIT0,BIT0);
		//PEA3
		AsiaPcieWrite16(PcieBase, CND003_PEA3|CND003_BUSXP1_D1D7F0_VID_D1F0,0x1D17);
		AsiaPcieModify8(PcieBase,CND003_PEA3|CND003_BUSXP1_D1D7F0_VEN_CTL_D1F0,BIT0,BIT0);
		//PEA4
		AsiaPcieWrite16(PcieBase, CND003_PEA4|CND003_BUSXP1_D1D7F0_VID_D1F0,0x1D17);
		AsiaPcieModify8(PcieBase,CND003_PEA4|CND003_BUSXP1_D1D7F0_VEN_CTL_D1F0,BIT0,BIT0);
		//PEB0
		AsiaPcieWrite16(PcieBase, CND003_PEB0|CND003_BUSXP1_D1D7F0_VID_D1F0,0x1D17);
		AsiaPcieModify8(PcieBase,CND003_PEB0|CND003_BUSXP1_D1D7F0_VEN_CTL_D1F0,BIT0,BIT0);
		//PEB1
		AsiaPcieWrite16(PcieBase, CND003_PEB1|CND003_BUSXP1_D1D7F0_VID_D1F0,0x1D17);
		AsiaPcieModify8(PcieBase,CND003_PEB1|CND003_BUSXP1_D1D7F0_VEN_CTL_D1F0,BIT0,BIT0);
	    //PESB
	    AsiaPcieWrite16(PcieBase, CND003_PESB|CND003_BUSXP1_D8F0_VID,0x1D17);
		AsiaPcieModify8(PcieBase,CND003_PESB|CND003_BUSXP1_D8F0_VEN_CTL,BIT0,BIT0);
		//PCIEIF
		AsiaPcieWrite16(PcieBase, CND003_PCIEIF|CND003_BUSX2_D0F0_VID,0x1D17);
		AsiaPcieModify8(PcieBase,CND003_PCIEIF|(CND003_BUSX2_D0F0_IOCFG+3),BIT7,BIT7);
		//EPTRFC
		AsiaPcieWrite16(PcieBase, CND003_EPTRFC|CND003_EPTRFC_D0F0_VID,0x1D17);
		AsiaPcieModify8(PcieBase,CND003_EPTRFC|CND003_EPTRFC_D0F0_DOWNSTREAM_CTL,BIT3,BIT3);
		//SATA
		AsiaPcieWrite16(PcieBase, CND003_SATA|CND003_D15F0_VID,0x1D17);
		AsiaPcieModify8(PcieBase,CND003_SATA|CND003_D15F0_VID_ENCLOUSER_MANEGEMENT_BUFFER_CTL_OPTIONAL_REG,BIT0,BIT0);
		//GNIC
		AsiaPcieWrite16(PcieBase, CND003_GNIC|D13F0_VENDER_ID_AND_DID,0x1D17);
		AsiaPcieModify8(PcieBase,CND003_GNIC|0x60,BIT1,BIT1);
		//XHCI
		AsiaPcieWrite16(PcieBase, CND003_XHCI|CND003_D18F0_VID,0x1D17);
		AsiaPcieModify8(PcieBase,CND003_XHCI|CND003_D18F0_XHCI_OPTION_BITS_RX45_XHCOPTRX45,BIT4,BIT4);
		//UHCI
		AsiaPcieWrite16(PcieBase, CND003_D14UHC0|IOEUHCI_DID_OPTIONAL,0x1D17);
		AsiaPcieModify8(PcieBase,CND003_D14UHC0|IOEUHCI_FLR_AND_VID_OPTIONAL_REG,BIT2,BIT2);
		AsiaPcieWrite16(PcieBase, CND003_D14UHC1|IOEUHCI_DID_OPTIONAL,0x1D17);
		AsiaPcieModify8(PcieBase,CND003_D14UHC1|IOEUHCI_FLR_AND_VID_OPTIONAL_REG,BIT2,BIT2);
		AsiaPcieWrite16(PcieBase, CND003_D14UHC2|IOEUHCI_DID_OPTIONAL,0x1D17);
		AsiaPcieModify8(PcieBase,CND003_D14UHC2|IOEUHCI_FLR_AND_VID_OPTIONAL_REG,BIT2,BIT2);
		AsiaPcieWrite16(PcieBase, CND003_D16UHC0|IOEUHCI_DID_OPTIONAL,0x1D17);
		AsiaPcieModify8(PcieBase,CND003_D16UHC0|IOEUHCI_FLR_AND_VID_OPTIONAL_REG,BIT2,BIT2);
		AsiaPcieWrite16(PcieBase, CND003_D16UHC1|IOEUHCI_DID_OPTIONAL,0x1D17);
		AsiaPcieModify8(PcieBase,CND003_D16UHC1|IOEUHCI_FLR_AND_VID_OPTIONAL_REG,BIT2,BIT2);
		AsiaPcieWrite16(PcieBase, CND003_D16UHC2|IOEUHCI_DID_OPTIONAL,0x1D17);
		AsiaPcieModify8(PcieBase,CND003_D16UHC2|IOEUHCI_FLR_AND_VID_OPTIONAL_REG,BIT2,BIT2);
		//EHCI
	    AsiaPcieWrite16(PcieBase, CND003_D14EHCI|IOEEHCI_DID_OPTIONAL_Z2,0x1D17);
		AsiaPcieModify8(PcieBase,CND003_D14EHCI|IOEEHCI_FLR_AND_VID_OPTIONAL_REG,BIT2,BIT2);
		AsiaPcieWrite16(PcieBase, CND003_D16EHCI|IOEEHCI_DID_OPTIONAL_Z2,0x1D17);
		AsiaPcieModify8(PcieBase,CND003_D16EHCI|IOEEHCI_FLR_AND_VID_OPTIONAL_REG,BIT2,BIT2);
#ifdef ZX_SECRET_CODE
	}
#endif	
	return EFI_SUCCESS;

}

/*
This routine is for CND003 PCIE PEI initialization
*/
STATIC
EFI_STATUS
IoePciePeiInit(
	IN EFI_PEI_SERVICES **PeiServices ,
	IN ASIA_NB_CONFIGURATION *NbConfig)
{
	//PEI_DEBUG((PeiServices, EFI_D_ERROR, "[CJW_IOE] IoePciePeiInit() TblOff=%d\n",TblOff));

	IoePatchPeiNb(PeiServices,NbConfig);
	
	IoePcieMmioIsbInit(PeiServices,NbConfig);

	IoePcieGen3EphyInit(PeiServices,NbConfig);

	IoePcieNormalInit(PeiServices,NbConfig);
    //Patch LTR issue alj20161129
    //IoePeiPatch(PeiServices, NbConfig);
	return EFI_SUCCESS;
}



//For a special patch
/*
Note:
This routine not be called because we need to clear
all AER status on PCI tree, but we must enumerate by
ourself in PEI stage. Instead, We clear AER status in DXE 
stage after device bus numer assignment completed.

This routine just used for FPGA
*/
STATIC
EFI_STATUS
AerErrorStatusClear(IN EFI_PEI_SERVICES  **PeiServices)
{
	EFI_STATUS Status = EFI_SUCCESS;
	
	UINT8 Bus,Dev,Func,Funx;
	UINT32 Val;
	//UINT8 Val8;
	UINT8  pointer,nextp,CapID;
	UINT16 CapID2,p1,np1;

	PEI_DEBUG((PeiServices, EFI_D_ERROR, "[CJW_AER]\n"));

	for(Bus = 0; Bus<0xFF;Bus++){
		//PEI_DEBUG((PeiServices, EFI_D_ERROR, "[CJW_AER] <1>\n"));
		for(Dev = 0; Dev<32; Dev++){
			//PEI_DEBUG((PeiServices, EFI_D_ERROR, "[CJW_AER] <2>\n"));
			Val = AsiaPcieRead32(PCI_BASE, AsiaPciAddress(Bus, Dev, 0, 0x00));
			//4 [] If no Function 0, skip other functions
			if(Val == 0xFFFFFFFF){
				Funx = 0;
				//PEI_DEBUG((PeiServices, EFI_D_ERROR, "[CJW_AER] <3>\n"));
			}else{
				Funx = 8;
				//PEI_DEBUG((PeiServices, EFI_D_ERROR, "[CJW_AER] <4>\n"));
			}
			
			for(Func = 0; Func < Funx; Func++){
				//PEI_DEBUG((PeiServices, EFI_D_ERROR, "[CJW_AER] <5>\n"));
				//whether this is a PCIE device or not
				pointer = 0x34;
				pointer = AsiaPcieRead8(PCI_BASE, AsiaPciAddress(Bus, Dev, Func, pointer));

				//4 [] if device not exist , exit to scan next device
				if(pointer == 0xFF){ //this device not exist
					//PEI_DEBUG((PeiServices, EFI_D_ERROR, "[CJW_AER] [%d|%d|%d] Device Not Exist\n",Bus,Dev,Func));
					continue;
				}
				//4 [] search PCI Express Capability
				//if yes, break;
				//if not, search next one
				//if last on still not, break
				while(1){
						
					CapID = AsiaPcieRead8(PCI_BASE, AsiaPciAddress(Bus, Dev, Func, pointer));
					//4 [] Found Pcie capability
					if(CapID == 0x10){
						//4 [] clear some status
						AsiaPcieModify8(PCI_BASE, AsiaPciAddress(Bus, Dev, Func, pointer+0x0A), BIT2|BIT1|BIT0, BIT2|BIT1|BIT0);
#if 0
						//Force Enable ASPM for all PCIE device
						AsiaPcieModify8(PCI_BASE, AsiaPciAddress(Bus, Dev, Func, pointer+0x10), BIT1|BIT0, BIT1);

#endif						
						p1 = 0x100;
						while(1){
							CapID2 = AsiaPcieRead16(PCI_BASE, AsiaPciAddress(Bus, Dev, Func, p1));
							//4 [] if not exist extend capability
							if(CapID2 == 0x0000){
								break;  //exit
							}
							//4 [] Found extend capabilty 
							else{
								//4 []Found AER capability
								if(CapID2 == 0x0001){
									PEI_DEBUG((PeiServices, EFI_D_ERROR, "[CJW_AER] [%d|%d|%d]Found AER at offset [0x%x]\n",Bus,Dev,Func,p1));
									AsiaPcieWrite32(PCI_BASE, AsiaPciAddress(Bus, Dev, Func, p1+0x04), 0xFFFFFFFF);
									AsiaPcieWrite32(PCI_BASE, AsiaPciAddress(Bus, Dev, Func, p1+0x10), 0xFFFFFFFF);
									break;
								}
								//4 [] this not AER capability
								else{
									np1 = AsiaPcieRead16(PCI_BASE, AsiaPciAddress(Bus, Dev, Func, p1+2));
									p1 = (np1>>4);
								}	
							}

							//4 [] AER capability not exit
							if(p1 == 0x000){
								PEI_DEBUG((PeiServices, EFI_D_ERROR, "[CJW_AER] [%d|%d|%d] Not Found AER \n",Bus,Dev,Func));
								break;
							}
							
						}
						break;
					}
					//4 [] Not found , search next pointer
					else{
						nextp = AsiaPcieRead8(PCI_BASE, AsiaPciAddress(Bus, Dev, Func, pointer+1));
						pointer = nextp;
					}

					//4 [] If no PCI Express Capability, it's not PCIE device
					if(pointer == 0x00){
						PEI_DEBUG((PeiServices, EFI_D_ERROR, "[CJW_AER] [%d|%d|%d]Not Pcie device/bridge\n",Bus,Dev,Func));
						break;
					}
				}	
			}
		}
	}

	

	return Status;
}





/*
	Reversal lanes of rp and PERST#
Note:
	Since BIOS don't know which Rp connected to IOE before linkup,
	so BIOS need to know the BDF of Host RP. those information was
	defined in PLATFORM/ND003xxx_xx/ folders.
*/
STATIC
EFI_STATUS
IoeLaneReversal(
	IN EFI_PEI_SERVICES  **PeiServices)
{
	EFI_STATUS Status = EFI_SUCCESS;
	//UINT8 ts;
	UINT8 Bus, Dev, Func;
	UINT8 Ltssmx;

	Bus = HOST_LANE_REVERSAL_BUS;
	Dev = HOST_LANE_REVERSAL_DEV;
	Func = HOST_LANE_REVERSAL_FUN;
	
	if(HOST_LANE_REVERSAL_EN == 0){
		PEI_DEBUG((PeiServices, EFI_D_ERROR, "[CJW_IOE_LR] Lane Reversal <Disable>\n"));
		return Status;
	}


	// Set Host Rp to support/enable Lane reversal
	// This is only for EVBs which implement lane reversal on board
	// e.g. EVB#9 #10
	else if(HOST_LANE_REVERSAL_EN == 1){
		PEI_DEBUG((PeiServices, EFI_D_ERROR, "             Lane Reversal <Enable>\n"));
		
		//Enable the LaneReversal  -- Rx1CD[4] = 1
		AsiaPcieModify8(PCI_BASE, AsiaPciAddress(Bus, Dev, Func, HOST_MAC), HOST_RLNRVSL, HOST_RLNRVSL);
	
		//PERST# to retrain the link  - PEXRST# will reset the register setting of RP
		//PeiNbResetPciePortx(PeiServices,ASIA_PCI_ADDRESS(Bus, Dev, Func, 0));
		PeiNbPcieStallx(PeiServices, 50); //50ms delay
		AsiaPciModify8(AsiaPciAddress(Bus, Dev, Func, HOST_LINK_CTL_1), HOST_LCRL, HOST_LCRL);  //retrain link
		PeiNbPcieStallx(PeiServices, 100); //100ms delay

		Ltssmx = AsiaPcieRead8(PCI_BASE, AsiaPciAddress(Bus, Dev, Func, HOST_PHYLS_LTSSM_STATE));
		if(Ltssmx != HOST_PHYLS_State_L0){
			Status = EFI_NOT_READY;
		}
		PEI_DEBUG((PeiServices, EFI_D_ERROR, "             Waiting for LinkUp... LTSSM STATE=0x%02x\n",Ltssmx));
		//AsiaIoWrite8(0x80, WAIT_LINK_UP_AFTER_LANE_REVERSAL); //0x38
				
/*_WaitLinkUp:
		AsiaIoWrite8(0x80, WAIT_LINK_UP_AFTER_LANE_REVERSAL); //0x38
		for(ts = 0; ts < (sizeof(IoeSearchTbl)/sizeof(SEARCH_TBL)); ts++){	
			Status = IoeSearchPcieRpTemporary(PeiServices,IoeSearchTbl[ts].BusNum,IoeSearchTbl[ts].DevNum,IoeSearchTbl[ts].FunNum);
			if(Status == EFI_SUCCESS){
				PEI_DEBUG((PeiServices, EFI_D_ERROR, "Done!\n"));
				return Status;
			}
		}
		goto _WaitLinkUp;
*/
		
	}

	else{
		// ...
	}


	return Status;
}






/*
	This Function can be called either PeiSbInit or PeiNbInit
	For AMx, this should be called in Pei NB init
	For BYx, this should be called in Pei SB init
*/
STATIC
EFI_STATUS
IoeCmbphyCfgDone(
	IN EFI_PEI_SERVICES  **PeiServices,
	ASIA_NB_CONFIGURATION *NbConfig)
{
	EFI_STATUS Statusx = EFI_SUCCESS;

	Statusx = IoePeiTempAssignment(PeiServices);
	if(Statusx != EFI_SUCCESS){
		PEI_DEBUG((PeiServices, EFI_D_ERROR, "[CJW_IOE_MODE] IoeCmbphyCfgDone() Not Found IOE!\n"));
		return Statusx;
	}

	//
	// BIOS mode Setting
	//
	if((NbConfig->Cnd003ModeSel) == BIOS_MODE){
		
		PEI_DEBUG((PeiServices, EFI_D_ERROR, "[CJW_IOE_MODE] Boot in BIOS mode\n"));
		//IoePhyCfgUnderBiosMode(PeiServices,NbConfig);
		IoePhyCfgInBiosMode(PeiServices, NbConfig);
	}else{

		// BIOSMD = 0
		AsiaPcieModify16(PCI_BASE, AsiaPciAddress(BUSX, UPPORT_DEV, UPPORT_FUN, CND003_BUSX_D0F0_PCIE_CAP_SEL), BIT15, 0);
		PEI_DEBUG((PeiServices, EFI_D_ERROR, "[CJW_IOE_MODE] Boot in SPI mode\n"));
	}


	IoePeiClearTempAssignment(PeiServices);

	return EFI_SUCCESS;
}


/*
	Note:
	Before calling this function, temp bus number must 
	have been assigned.
*/
STATIC
EFI_STATUS
IoeLinkWidthCfg(
	IN EFI_PEI_SERVICES  **PeiServices, 
	ASIA_NB_CONFIGURATION *NbConfig)
{
	EFI_STATUS Statusx = EFI_SUCCESS;


	if(NbConfig->Cnd003LinkWidth == 0){
		PEI_DEBUG((PeiServices, EFI_D_ERROR, "[CJW_IOE] LinkWidth = AUTO\n"));
		return Statusx;
	}

	
	// 
	// PCIE switch upstream port - Link Width Setting
	//


	//Rx1CD[3]
	AsiaPcieModify8(PCI_BASE, AsiaPciAddress(BUSX, UPPORT_DEV, UPPORT_FUN, CND003_BUSX_D0F0_MAC), 
					CND003_BUSX_D0F0_RWDCONFIG, CND003_BUSX_D0F0_RWDCONFIG);
	//Rx1E3[2]
	AsiaPcieModify8(PCI_BASE, AsiaPciAddress(BUSX, UPPORT_DEV, UPPORT_FUN, CND003_BUSX_D0F0_GEN2_MAC_ENHANCEMENT), 
					CND003_BUSX_D0F0_RDOWNCFG, CND003_BUSX_D0F0_RDOWNCFG);
	
	switch(NbConfig->Cnd003LinkWidth){
		case 0:  //AURO
			PEI_DEBUG((PeiServices, EFI_D_ERROR, "[CJW_IOE] LinkWidth = AUTO\n"));
		case 1:  //X4
			PEI_DEBUG((PeiServices, EFI_D_ERROR, "[CJW_IOE] LinkWidth = X4\n"));

			//Rx1E0[2] - set target link width
			AsiaPcieModify8(PCI_BASE, AsiaPciAddress(BUSX, UPPORT_DEV, UPPORT_FUN, CND003_BUSX_D0F0_TARGET_LINK_WIDTH), 
					0x1F, 0x04);
			break;
		case 2:  //x2
			PEI_DEBUG((PeiServices, EFI_D_ERROR, "[CJW_IOE] LinkWidth = X2\n"));

			//Rx1E0[2] - set target link width
			AsiaPcieModify8(PCI_BASE, AsiaPciAddress(BUSX, UPPORT_DEV, UPPORT_FUN, CND003_BUSX_D0F0_TARGET_LINK_WIDTH), 
					0x1F, 0x02);			
			break;
		case 3:  //x1
			PEI_DEBUG((PeiServices, EFI_D_ERROR, "[CJW_IOE] LinkWidth = X1\n"));

			//Rx1E0[2] - set target link width
			AsiaPcieModify8(PCI_BASE, AsiaPciAddress(BUSX, UPPORT_DEV, UPPORT_FUN, CND003_BUSX_D0F0_TARGET_LINK_WIDTH), 
					0x1F, 0x01);			
			break;
		default:
			Statusx = EFI_INVALID_PARAMETER;
			PEI_DEBUG((PeiServices, EFI_D_ERROR, "[CJW_IOE_ERROR] LinkWidth of Switch Upstream port => Invalid setting!\n"));
			break;
	}

	//Rx1D0[0] - reconfigure lane width
	AsiaPcieModify8(PCI_BASE, AsiaPciAddress(BUSX, UPPORT_DEV, UPPORT_FUN, CND003_BUSX_D0F0_PM_UNIT_PMU_CTL), 
					CND003_BUSX_D0F0_LCRCNFG, CND003_BUSX_D0F0_LCRCNFG);

	return Statusx;
}



STATIC
EFI_STATUS
IoeRetrainEpLink(	
	IN EFI_PEI_SERVICES  **PeiServices, 
	ASIA_NB_CONFIGURATION *NbConfig)
{
	UINT8 ts; 	
	EFI_STATUS Statusx = EFI_SUCCESS;
	for(ts = 0; ts < (sizeof(IoeSearchTbl)/sizeof(SEARCH_TBL)); ts++){
		Statusx = IoeSearchPcieRpTemporary(PeiServices,IoeSearchTbl[ts].BusNum,IoeSearchTbl[ts].DevNum,IoeSearchTbl[ts].FunNum);
		if(Statusx == EFI_SUCCESS){
#if MULTI_IOE_SUPPORT			
			if(!IoeIsUsablePort(PeiServices,IoeSearchTbl[ts].BusNum,IoeSearchTbl[ts].DevNum,IoeSearchTbl[ts].FunNum)){
				Statusx = EFI_NOT_FOUND;
				continue;
			}
#endif			
			goto _RetrainLink;
		}		
	}
	PEI_DEBUG((PeiServices, EFI_D_ERROR, "[CJW_IOE] IoeRetrainEpLink(): Not Found IOE!\n"));
	return Statusx;
	
_RetrainLink:

	PEI_DEBUG((PeiServices, EFI_D_ERROR, "[CJW_IOE] IoeRetrainEpLink(): Found IOE! -> Bus Number of IOE have been cleared\n"));
	PEI_DEBUG((PeiServices, EFI_D_ERROR, "          Retrain Link[%d|%d|%d]\n",IoeSearchTbl[ts].BusNum,IoeSearchTbl[ts].DevNum,IoeSearchTbl[ts].FunNum));
	AsiaPciModify8(AsiaPciAddress(IoeSearchTbl[ts].BusNum,IoeSearchTbl[ts].DevNum,IoeSearchTbl[ts].FunNum, 0x50), BIT5, BIT5);
	
	return Statusx;
	
}


STATIC
EFI_STATUS
IoeErrorReportingEn(
	IN EFI_PEI_SERVICES  **PeiServices, 
	ASIA_NB_CONFIGURATION *NbConfig)
{
	EFI_STATUS Statusx = EFI_SUCCESS;	
	UINT8 Devx, Funx;
	UINT32 temp321,temp322;


	PEI_DEBUG((PeiServices, EFI_D_ERROR, "[CJW_IOE] %a()\n",__FUNCTION__));

	if(NbConfig->IoeDnPortCtl != 1){
		PEI_DEBUG((PeiServices, EFI_D_ERROR, "          Exit!\n",__FUNCTION__));
		return EFI_SUCCESS;
	}

	Statusx = IoeGetRpToFindIoe(PeiServices, &Devx, &Funx);
	if(Statusx != EFI_SUCCESS){
		return Statusx;
	}

	if(NbConfig->IoePEA0Ctl == 1){
		temp321 = AsiaPcieRead32(NbConfig->PcieBar, AsiaPciAddress(BUSXP1, PEA0, DNPORT_FUN, CND003_BUSXP1_D1D7F0_UNCORRECTABLE_ERR_STA));
		temp322 = AsiaPcieRead32(NbConfig->PcieBar, AsiaPciAddress(BUSXP1, PEA0, DNPORT_FUN, CND003_BUSXP1_D1D7F0_CORRECTABLE_ERR_STA));
		AsiaPcieWrite32(NbConfig->PcieBar, AsiaPciAddress(BUSXP1, PEA0, DNPORT_FUN, CND003_BUSXP1_D1D7F0_UNCORRECTABLE_ERR_STA), 0xFFFFFFFF);
		AsiaPcieWrite32(NbConfig->PcieBar, AsiaPciAddress(BUSXP1, PEA0, DNPORT_FUN, CND003_BUSXP1_D1D7F0_CORRECTABLE_ERR_STA), 0xFFFFFFFF);
		PEI_DEBUG((PeiServices, EFI_D_ERROR, "[%d|%d|%d] Rx104=0x%08x, Rx110=0x%08x\n", BUSXP1, PEA0, DNPORT_FUN,temp321,temp322));

		//SwDbg-1-0-SwDbg-2-AER
		if((NbConfig->Cnd003SwDbg1 == 0)&&(!((NbConfig->Cnd003SwDbg2) & BIT10))){
			AsiaPcieModify8(NbConfig->PcieBar, AsiaPciAddress(BUSXP1, PEA0, DNPORT_FUN, CND003_BUSXP1_D1D7F0_DEV_CTL_1), 0xF, 0xF);			//Enable UR/Fatal/Non-Fatal/Correctable Error reporting[Device Control 1]
			AsiaPcieModify16(NbConfig->PcieBar, AsiaPciAddress(BUSXP1, PEA0, DNPORT_FUN, CND003_BUSXP1_D1D7F0_PCI_CMD), 0x100, 0x100); 	//SERR Enable[Bridge Control]
			AsiaPcieModify16(NbConfig->PcieBar, AsiaPciAddress(BUSXP1, PEA0, DNPORT_FUN, CND003_BUSXP1_D1D7F0_BRIDGE_CTL), BIT1, BIT1); 		//SERR# enable[PCI Command]
		}
		
	}

	if(NbConfig->IoePEA1Ctl == 1){
		temp321 = AsiaPcieRead32(NbConfig->PcieBar, AsiaPciAddress(BUSXP1, PEA1, DNPORT_FUN, CND003_BUSXP1_D1D7F0_UNCORRECTABLE_ERR_STA));
		temp322 = AsiaPcieRead32(NbConfig->PcieBar, AsiaPciAddress(BUSXP1, PEA1, DNPORT_FUN, CND003_BUSXP1_D1D7F0_CORRECTABLE_ERR_STA));
		AsiaPcieWrite32(NbConfig->PcieBar, AsiaPciAddress(BUSXP1, PEA1, DNPORT_FUN, CND003_BUSXP1_D1D7F0_UNCORRECTABLE_ERR_STA), 0xFFFFFFFF);
		AsiaPcieWrite32(NbConfig->PcieBar, AsiaPciAddress(BUSXP1, PEA1, DNPORT_FUN, CND003_BUSXP1_D1D7F0_CORRECTABLE_ERR_STA), 0xFFFFFFFF);
		PEI_DEBUG((PeiServices, EFI_D_ERROR, "[%d|%d|%d] Rx104=0x%08x, Rx110=0x%08x\n", BUSXP1, PEA1, DNPORT_FUN,temp321,temp322));

		//SwDbg-1-0-SwDbg-2-AER
		if((NbConfig->Cnd003SwDbg1 == 0)&&(!((NbConfig->Cnd003SwDbg2) & BIT10))){
			AsiaPcieModify8(NbConfig->PcieBar, AsiaPciAddress(BUSXP1, PEA1, DNPORT_FUN, CND003_BUSXP1_D1D7F0_DEV_CTL_1), 0xF, 0xF);			//Enable UR/Fatal/Non-Fatal/Correctable Error reporting[Device Control 1]
			AsiaPcieModify16(NbConfig->PcieBar, AsiaPciAddress(BUSXP1, PEA1, DNPORT_FUN, CND003_BUSXP1_D1D7F0_PCI_CMD), 0x100, 0x100); 	//SERR Enable[Bridge Control]
			AsiaPcieModify16(NbConfig->PcieBar, AsiaPciAddress(BUSXP1, PEA1, DNPORT_FUN, CND003_BUSXP1_D1D7F0_BRIDGE_CTL), BIT1, BIT1); 		//SERR# enable[PCI Command]
		}
	}

	if(NbConfig->IoePEA2Ctl == 1){
		temp321 = AsiaPcieRead32(NbConfig->PcieBar, AsiaPciAddress(BUSXP1, PEA2, DNPORT_FUN, CND003_BUSXP1_D1D7F0_UNCORRECTABLE_ERR_STA));
		temp322 = AsiaPcieRead32(NbConfig->PcieBar, AsiaPciAddress(BUSXP1, PEA2, DNPORT_FUN, CND003_BUSXP1_D1D7F0_CORRECTABLE_ERR_STA));
		AsiaPcieWrite32(NbConfig->PcieBar, AsiaPciAddress(BUSXP1, PEA2, DNPORT_FUN, CND003_BUSXP1_D1D7F0_UNCORRECTABLE_ERR_STA), 0xFFFFFFFF);
		AsiaPcieWrite32(NbConfig->PcieBar, AsiaPciAddress(BUSXP1, PEA2, DNPORT_FUN, CND003_BUSXP1_D1D7F0_CORRECTABLE_ERR_STA), 0xFFFFFFFF);
		PEI_DEBUG((PeiServices, EFI_D_ERROR, "[%d|%d|%d] Rx104=0x%08x, Rx110=0x%08x\n", BUSXP1, PEA2, DNPORT_FUN,temp321,temp322));

		//SwDbg-1-0-SwDbg-2-AER
		if((NbConfig->Cnd003SwDbg1 == 0)&&(!((NbConfig->Cnd003SwDbg2) & BIT10))){
			AsiaPcieModify8(NbConfig->PcieBar, AsiaPciAddress(BUSXP1, PEA2, DNPORT_FUN, CND003_BUSXP1_D1D7F0_DEV_CTL_1), 0xF, 0xF);			//Enable UR/Fatal/Non-Fatal/Correctable Error reporting[Device Control 1]
			AsiaPcieModify16(NbConfig->PcieBar, AsiaPciAddress(BUSXP1, PEA2, DNPORT_FUN, CND003_BUSXP1_D1D7F0_PCI_CMD), 0x100, 0x100); 	//SERR Enable[Bridge Control]
			AsiaPcieModify16(NbConfig->PcieBar, AsiaPciAddress(BUSXP1, PEA2, DNPORT_FUN, CND003_BUSXP1_D1D7F0_BRIDGE_CTL), BIT1, BIT1); 		//SERR# enable[PCI Command]
		}
	}

	if(NbConfig->IoePEA3Ctl == 1){
		temp321 = AsiaPcieRead32(NbConfig->PcieBar, AsiaPciAddress(BUSXP1, PEA3, DNPORT_FUN, CND003_BUSXP1_D1D7F0_UNCORRECTABLE_ERR_STA));
		temp322 = AsiaPcieRead32(NbConfig->PcieBar, AsiaPciAddress(BUSXP1, PEA3, DNPORT_FUN, CND003_BUSXP1_D1D7F0_CORRECTABLE_ERR_STA));
		AsiaPcieWrite32(NbConfig->PcieBar, AsiaPciAddress(BUSXP1, PEA3, DNPORT_FUN, CND003_BUSXP1_D1D7F0_UNCORRECTABLE_ERR_STA), 0xFFFFFFFF);
		AsiaPcieWrite32(NbConfig->PcieBar, AsiaPciAddress(BUSXP1, PEA3, DNPORT_FUN, CND003_BUSXP1_D1D7F0_CORRECTABLE_ERR_STA), 0xFFFFFFFF);
		PEI_DEBUG((PeiServices, EFI_D_ERROR, "[%d|%d|%d] Rx104=0x%08x, Rx110=0x%08x\n", BUSXP1, PEA3, DNPORT_FUN,temp321,temp322));

		//SwDbg-1-0-SwDbg-2-AER
		if((NbConfig->Cnd003SwDbg1 == 0)&&(!((NbConfig->Cnd003SwDbg2) & BIT10))){
			AsiaPcieModify8(NbConfig->PcieBar, AsiaPciAddress(BUSXP1, PEA3, DNPORT_FUN, CND003_BUSXP1_D1D7F0_DEV_CTL_1), 0xF, 0xF);			//Enable UR/Fatal/Non-Fatal/Correctable Error reporting[Device Control 1]
			AsiaPcieModify16(NbConfig->PcieBar, AsiaPciAddress(BUSXP1, PEA3, DNPORT_FUN, CND003_BUSXP1_D1D7F0_PCI_CMD), 0x100, 0x100); 	//SERR Enable[Bridge Control]
			AsiaPcieModify16(NbConfig->PcieBar, AsiaPciAddress(BUSXP1, PEA3, DNPORT_FUN, CND003_BUSXP1_D1D7F0_BRIDGE_CTL), BIT1, BIT1); 		//SERR# enable[PCI Command]
		}
	}

	if(NbConfig->IoePEA4Ctl == 1){
		temp321 = AsiaPcieRead32(NbConfig->PcieBar, AsiaPciAddress(BUSXP1, PEA4, DNPORT_FUN, CND003_BUSXP1_D1D7F0_UNCORRECTABLE_ERR_STA));
		temp322 = AsiaPcieRead32(NbConfig->PcieBar, AsiaPciAddress(BUSXP1, PEA4, DNPORT_FUN, CND003_BUSXP1_D1D7F0_CORRECTABLE_ERR_STA));
		AsiaPcieWrite32(NbConfig->PcieBar, AsiaPciAddress(BUSXP1, PEA4, DNPORT_FUN, CND003_BUSXP1_D1D7F0_UNCORRECTABLE_ERR_STA), 0xFFFFFFFF);
		AsiaPcieWrite32(NbConfig->PcieBar, AsiaPciAddress(BUSXP1, PEA4, DNPORT_FUN, CND003_BUSXP1_D1D7F0_CORRECTABLE_ERR_STA), 0xFFFFFFFF);
		PEI_DEBUG((PeiServices, EFI_D_ERROR, "[%d|%d|%d] Rx104=0x%08x, Rx110=0x%08x\n", BUSXP1, PEA4, DNPORT_FUN,temp321,temp322));

		//SwDbg-1-0-SwDbg-2-AER
		if((NbConfig->Cnd003SwDbg1 == 0)&&(!((NbConfig->Cnd003SwDbg2) & BIT10))){
			AsiaPcieModify8(NbConfig->PcieBar, AsiaPciAddress(BUSXP1, PEA4, DNPORT_FUN, CND003_BUSXP1_D1D7F0_DEV_CTL_1), 0xF, 0xF);			//Enable UR/Fatal/Non-Fatal/Correctable Error reporting[Device Control 1]
			AsiaPcieModify16(NbConfig->PcieBar, AsiaPciAddress(BUSXP1, PEA4, DNPORT_FUN, CND003_BUSXP1_D1D7F0_PCI_CMD), 0x100, 0x100); 	//SERR Enable[Bridge Control]
			AsiaPcieModify16(NbConfig->PcieBar, AsiaPciAddress(BUSXP1, PEA4, DNPORT_FUN, CND003_BUSXP1_D1D7F0_BRIDGE_CTL), BIT1, BIT1); 		//SERR# enable[PCI Command]
		}
	}	

	if(NbConfig->IoePEB0Ctl == 1){
		temp321 = AsiaPcieRead32(NbConfig->PcieBar, AsiaPciAddress(BUSXP1, PEB0, DNPORT_FUN, CND003_BUSXP1_D1D7F0_UNCORRECTABLE_ERR_STA));
		temp322 = AsiaPcieRead32(NbConfig->PcieBar, AsiaPciAddress(BUSXP1, PEB0, DNPORT_FUN, CND003_BUSXP1_D1D7F0_CORRECTABLE_ERR_STA));
		AsiaPcieWrite32(NbConfig->PcieBar, AsiaPciAddress(BUSXP1, PEB0, DNPORT_FUN, CND003_BUSXP1_D1D7F0_UNCORRECTABLE_ERR_STA), 0xFFFFFFFF);
		AsiaPcieWrite32(NbConfig->PcieBar, AsiaPciAddress(BUSXP1, PEB0, DNPORT_FUN, CND003_BUSXP1_D1D7F0_CORRECTABLE_ERR_STA), 0xFFFFFFFF);
		PEI_DEBUG((PeiServices, EFI_D_ERROR, "[%d|%d|%d] Rx104=0x%08x, Rx110=0x%08x\n", BUSXP1, PEB0, DNPORT_FUN,temp321,temp322));

		//SwDbg-1-0-SwDbg-2-AER
		if((NbConfig->Cnd003SwDbg1 == 0)&&(!((NbConfig->Cnd003SwDbg2) & BIT10))){
			AsiaPcieModify8(NbConfig->PcieBar, AsiaPciAddress(BUSXP1, PEB0, DNPORT_FUN, CND003_BUSXP1_D1D7F0_DEV_CTL_1), 0xF, 0xF);			//Enable UR/Fatal/Non-Fatal/Correctable Error reporting[Device Control 1]
			AsiaPcieModify16(NbConfig->PcieBar, AsiaPciAddress(BUSXP1, PEB0, DNPORT_FUN, CND003_BUSXP1_D1D7F0_PCI_CMD), 0x100, 0x100); 	//SERR Enable[Bridge Control]
			AsiaPcieModify16(NbConfig->PcieBar, AsiaPciAddress(BUSXP1, PEB0, DNPORT_FUN, CND003_BUSXP1_D1D7F0_BRIDGE_CTL), BIT1, BIT1); 		//SERR# enable[PCI Command]
		}
	}

	if(NbConfig->IoePEB1Ctl == 1){
		temp321 = AsiaPcieRead32(NbConfig->PcieBar, AsiaPciAddress(BUSXP1, PEB1, DNPORT_FUN, CND003_BUSXP1_D1D7F0_UNCORRECTABLE_ERR_STA));
		temp322 = AsiaPcieRead32(NbConfig->PcieBar, AsiaPciAddress(BUSXP1, PEB1, DNPORT_FUN, CND003_BUSXP1_D1D7F0_CORRECTABLE_ERR_STA));
		AsiaPcieWrite32(NbConfig->PcieBar, AsiaPciAddress(BUSXP1, PEB1, DNPORT_FUN, CND003_BUSXP1_D1D7F0_UNCORRECTABLE_ERR_STA), 0xFFFFFFFF);
		AsiaPcieWrite32(NbConfig->PcieBar, AsiaPciAddress(BUSXP1, PEB1, DNPORT_FUN, CND003_BUSXP1_D1D7F0_CORRECTABLE_ERR_STA), 0xFFFFFFFF);
		PEI_DEBUG((PeiServices, EFI_D_ERROR, "[%d|%d|%d] Rx104=0x%08x, Rx110=0x%08x\n", BUSXP1, PEB1, DNPORT_FUN,temp321,temp322));

		//SwDbg-1-0-SwDbg-2-AER
		if((NbConfig->Cnd003SwDbg1 == 0)&&(!((NbConfig->Cnd003SwDbg2) & BIT10))){
			AsiaPcieModify8(NbConfig->PcieBar, AsiaPciAddress(BUSXP1, PEB1, DNPORT_FUN, CND003_BUSXP1_D1D7F0_DEV_CTL_1), 0xF, 0xF);			//Enable UR/Fatal/Non-Fatal/Correctable Error reporting[Device Control 1]
			AsiaPcieModify16(NbConfig->PcieBar, AsiaPciAddress(BUSXP1, PEB1, DNPORT_FUN, CND003_BUSXP1_D1D7F0_PCI_CMD), 0x100, 0x100); 	//SERR Enable[Bridge Control]
			AsiaPcieModify16(NbConfig->PcieBar, AsiaPciAddress(BUSXP1, PEB1, DNPORT_FUN, CND003_BUSXP1_D1D7F0_BRIDGE_CTL), BIT1, BIT1); 		//SERR# enable[PCI Command]
		}
	}	


	temp321 = AsiaPcieRead32(NbConfig->PcieBar, AsiaPciAddress(BUSX, UPPORT_DEV, UPPORT_FUN, CND003_BUSX_D0F0_UNCORRECTABLE_ERR_STA));
	temp322 = AsiaPcieRead32(NbConfig->PcieBar, AsiaPciAddress(BUSX, UPPORT_DEV, UPPORT_FUN, CND003_BUSX_D0F0_CORRECTABLE_ERR_STA));
	AsiaPcieWrite32(NbConfig->PcieBar, AsiaPciAddress(BUSX, UPPORT_DEV, UPPORT_FUN, CND003_BUSX_D0F0_UNCORRECTABLE_ERR_STA), 0xFFFFFFFF);
	AsiaPcieWrite32(NbConfig->PcieBar, AsiaPciAddress(BUSX, UPPORT_DEV, UPPORT_FUN, CND003_BUSX_D0F0_CORRECTABLE_ERR_STA), 0xFFFFFFFF);
	PEI_DEBUG((PeiServices, EFI_D_ERROR, "[%d|%d|%d] Rx104=0x%08x, Rx110=0x%08x\n", BUSX, UPPORT_DEV, UPPORT_FUN,temp321,temp322));

	//SwDbg-1-0-SwDbg-2-AER
	if((NbConfig->Cnd003SwDbg1 == 0)&&(!((NbConfig->Cnd003SwDbg2) & BIT10))){
		AsiaPcieModify8(NbConfig->PcieBar, AsiaPciAddress(BUSX, UPPORT_DEV, UPPORT_FUN, CND003_BUSX_D0F0_DEV_CTL_1), 0xF, 0xF);			//Enable UR/Fatal/Non-Fatal/Correctable Error reporting[Device Control 1]
		AsiaPcieModify16(NbConfig->PcieBar, AsiaPciAddress(BUSX, UPPORT_DEV, UPPORT_FUN, CND003_BUSX_D0F0_PCI_CMD), 0x100, 0x100); 	//SERR Enable[Bridge Control]
		AsiaPcieModify16(NbConfig->PcieBar, AsiaPciAddress(BUSX, UPPORT_DEV, UPPORT_FUN, CND003_BUSX_D0F0_BRIDGE_CTL), BIT1, BIT1); 		//SERR# enable[PCI Command]
	}


	temp321 = AsiaPcieRead32(NbConfig->PcieBar, AsiaPciAddress(0, Devx, Funx, HOST_UNCORRECTABLE_ERR_STA));
	temp322 = AsiaPcieRead32(NbConfig->PcieBar, AsiaPciAddress(0, Devx, Funx, HOST_CORRECTABLE_ERR_STA));
	AsiaPcieWrite32(NbConfig->PcieBar, AsiaPciAddress(0, Devx, Funx, HOST_UNCORRECTABLE_ERR_STA), 0xFFFFFFFF);
	AsiaPcieWrite32(NbConfig->PcieBar, AsiaPciAddress(0, Devx, Funx, HOST_CORRECTABLE_ERR_STA), 0xFFFFFFFF);	
	PEI_DEBUG((PeiServices, EFI_D_ERROR, "[%d|%d|%d] Rx104=0x%08x, Rx110=0x%08x\n", 0,Devx,Funx,temp321,temp322));

	//SwDbg-1-0-SwDbg-2-AER
	if((NbConfig->Cnd003SwDbg1 == 0)&&(!((NbConfig->Cnd003SwDbg2) & BIT10))){
		//AsiaPcieModify8(NbConfig->PcieBar, AsiaPciAddress(BUSXP1, PEA0, DNPORT_FUN, 0x48), 0xF, 0xF);			//Enable UR/Fatal/Non-Fatal/Correctable Error reporting[Device Control 1]
		//AsiaPcieModify16(NbConfig->PcieBar, AsiaPciAddress(BUSXP1, PEA0, DNPORT_FUN, 0x04), 0x100, 0x100); 	//SERR Enable[Bridge Control]
		AsiaPcieModify16(NbConfig->PcieBar, AsiaPciAddress(0, Devx, Funx, HOST_BRIDGE_CTL), BIT1, BIT1); 		//SERR# enable[PCI Command]
	}

	
	return Statusx;
}
 
 /**
	IoePeiNbInit
	
   @param  PeiServices	 EFI_PEI_SERVICES pointer.
   @param NbCfg point to ASIA_NB_CONFIGURATION struct
 
   @return EFI_STATUS.
 
 **/

EFI_STATUS
IoePeiNbInit(
	IN EFI_PEI_SERVICES  **PeiServices, 
	ASIA_NB_CONFIGURATION *NbConfig)
{

	EFI_STATUS Statusx = EFI_SUCCESS;
	//UINT8 TblOff = 0;

	if(!IoeExist()){
		PEI_DEBUG((PeiServices, EFI_D_ERROR, "[CJW_IOE] SKIP CND003 Init (2)\n"));
		return EFI_SUCCESS;
	}


	//
	// Ioe CMBPHY_CFGDONE
	// Note: In BIOS mode. before RCMBPHY_CFGDONE was set,  
	// 		VID of PCIE PTN was 0000h
	//
	IoeCmbphyCfgDone(PeiServices, NbConfig);
	

	//////IoeSmbusDebugSelection(PeiServices,0);
	//IoePowerOnDnPortPeRst(PeiServices);
	//---------------------------------------------------------------------
	///////IoeSmbusPreInit(PeiServices);

	//
	// Temp resource assignment for Ioe
	//
	Statusx = IoePeiTempAssignment(PeiServices);
	if(Statusx != EFI_SUCCESS){
		PEI_DEBUG((PeiServices, EFI_D_ERROR, "[CJW_IOE] Warning: Not Found IOE!\n"));

		/*For Debug purpose*/
		//AsiaIoWrite8(0x80, NOT_FOUND_IOE_POST);
		PeiNbPcieStallx(PeiServices, 3000); 			//wait 3s

		goto _SkipIoeInit;
	}

	// Just for debug
	PEI_DEBUG((PeiServices, EFI_D_ERROR, "[CJW_IOE]           BusxD0F0 DIDVID:0x%08X\n",AsiaPciRead32(IOE_BUSX_D0F0)));
	PEI_DEBUG((PeiServices, EFI_D_ERROR, "                    BusX+1 D0F0 DIDVID:0x%08X\n",AsiaPciRead32(IOE_BUSXp1_D0F0)));
	PEI_DEBUG((PeiServices, EFI_D_ERROR, "                    BusX+1 D8F0 DIDVID:0x%08X\n",AsiaPciRead32(IOE_BUSXp1_D8F0)));
	PEI_DEBUG((PeiServices, EFI_D_ERROR, "                    BusX+2 D0F0 DIDVID:0x%08X\n",AsiaPciRead32(IOE_BUSXp2_D0F0)));	
	PEI_DEBUG((PeiServices, EFI_D_ERROR, "                    BusX+3 D0F0 DIDVID:0x%08X\n",AsiaPciRead32(IOE_BUSXp3_D0F0)));
	PEI_DEBUG((PeiServices, EFI_D_ERROR, "                    BusX+3 D15F0 DIDVID:0x%08X\n",AsiaPciRead32(IOE_BUSXp3_D15F0)));	

	//
	// Clear AER registers on CND003
	//
	//IoeErrorReportingEn(PeiServices,NbConfig);


	//
	// Set LinkWidth of switch upstream port
	//
	IoeLinkWidthCfg(PeiServices,NbConfig);
	//
	//Choose VID according to SetUp option
	//
    IoePeiDIDVID(PeiServices,NbConfig);
	//
	//SVID SDID  update ,ALJ 20170307
	//
	UpdateIOESVIDSSID();
	// Before any pei initializaiton, we lock the VID DID RID there
	//
	IoeVidDidRidLock(PeiServices,NbConfig);
    //efuse patch for XHCI MMIO
	xHCI_MMIO_Bar_32bit_patch(PeiServices);

	//
	// FPGA patch for IOE
	// all patching for FPGA should setting in this routine
	//
#ifdef CND003_FPGA

	IoeFpgaSpecialPatch(PeiServices);

#endif

	//
	// CND003 PCIE PEI initializaiton
	//
	IoePciePeiInit(PeiServices,NbConfig);

	//
	// CND003 DN ports PCIE link Reset Check (Optional)
	//
	IoeCheckPcieLink(PeiServices, NbConfig);
	
	//
	// Retrain link --> When Skip EQ, Come to Gen3
	//
	//IoeRetrainEpLink(PeiServices,NbConfig);
	
	//
	// Clear the resource we assigned before
	//
	IoePeiClearTempAssignment(PeiServices);
	
	return EFI_SUCCESS;

_SkipIoeInit:

	return EFI_NOT_FOUND;
	
}






/*
[CJW_IOE]
	This routine is for guarantee the XBCTL & EPTRFC 
	can be accessed in PEI stage.

	In S3 resume process, we need to let them visiable temporarily. 
*/
STATIC
EFI_STATUS
IoeAbolishHideXbctlEptrfc(
	IN EFI_PEI_SERVICES  **PeiServices)
{

	EFI_STATUS Status = EFI_SUCCESS;
	UINT32 MmioBar;
	UINT32 temp32x,temp32y;


		
	PEI_DEBUG((PeiServices, EFI_D_ERROR, "[CJW_IOE] IoeAbolishHideXbctlEptrfc() Found IOE!\n"));
	MmioBar = AsiaPciRead32(AsiaPciAddress(BUSX, UPPORT_DEV, DNPORT_FUN, 0x10));

	// Hide XBCTL & EPTRFC
	AsiaMemoryModify8(MmioBar + MMIO_ISB_OFFSET + CND003_MMIO_D0F0_CKGSRC_SETTING_GRP2, CND003_MMIO_D0F0_R_BUSXP3D0F0_HIDE, 0);
	AsiaPcieModify8(PCI_BASE, AsiaPciAddress(BUSX, UPPORT_DEV, UPPORT_FUN, CND003_BUSX_D0F0_VEN_CTL), CND003_BUSX_D0F0_HIDE_XP1_D0, 0);	


	temp32x = AsiaPciRead32(AsiaPciAddress(BUSXP1, XBCTL, DNPORT_FUN, 0));
	temp32y = AsiaPciRead32(AsiaPciAddress(BUSXP3, EPTRFC_DEV, EPTRFC_FUN, 0));

	// Read to test 
	PEI_DEBUG((PeiServices, EFI_D_ERROR, "          Read to Test: VIDDID of XBCTL/EPTRFC = 0x%08x/0x%08x \n",
								temp32x,
								temp32y ));

//;cjw-A0-debug 20161206
	if((temp32x == 0xFFFFFFFF)||(temp32y == 0xFFFFFFFF)){
		//PEI_DEBUG((PeiServices, EFI_D_ERROR, "<84 Port> = 0xEE\n",0));
		//AsiaIoWrite8(0x84, 0xEE);
		
		PEI_DEBUG((PeiServices, EFI_D_ERROR, "[CJW_IOE] Debug-ErrorMessage-Hide\n"));
		IoeDumpCfg(PeiServices, PCI_BASE, 0, 2, 0, 0x200);
		IoeDumpCfg(PeiServices, PCI_BASE, BUSX, UPPORT_DEV, UPPORT_FUN, 0x200);
		IoeDumpMem(PeiServices, MmioBar+0x1100, 0x100);
	}
//;cjw-A0-debug END

	return Status;

}



STATIC
EFI_STATUS
IoeGpioConfigure(	
	IN EFI_PEI_SERVICES  **PeiServices)
{
	EFI_STATUS Statusx;
	UINT32 MmioBar;
	

		PEI_DEBUG((PeiServices, EFI_D_ERROR, "[CJW_IOE] IoeGpioConfigure() Found IOE!\n"));
		MmioBar = AsiaPciRead32(AsiaPciAddress(BUSX, UPPORT_DEV, DNPORT_FUN, 0x10));


		//
		// Set GPIO 0~5 as PEXRST#
		//
		AsiaMemoryModify16(MmioBar + MMIO_ISB_OFFSET + CND003_MMIO_D0F0_VCORE_GPIO_PAD_SEL, CND003_MMIO_D0F0_R_PAD_GPIO0, 1<<0);
		AsiaMemoryModify16(MmioBar + MMIO_ISB_OFFSET + CND003_MMIO_D0F0_VCORE_GPIO_PAD_SEL, CND003_MMIO_D0F0_R_PAD_GPIO1, 1<<2);
		AsiaMemoryModify16(MmioBar + MMIO_ISB_OFFSET + CND003_MMIO_D0F0_VCORE_GPIO_PAD_SEL, CND003_MMIO_D0F0_R_PAD_GPIO2, 1<<4);
		AsiaMemoryModify16(MmioBar + MMIO_ISB_OFFSET + CND003_MMIO_D0F0_VCORE_GPIO_PAD_SEL, CND003_MMIO_D0F0_R_PAD_GPIO3, 1<<6);
		AsiaMemoryModify16(MmioBar + MMIO_ISB_OFFSET + CND003_MMIO_D0F0_VCORE_GPIO_PAD_SEL, CND003_MMIO_D0F0_R_PAD_GPIO4, 1<<8);
		AsiaMemoryModify16(MmioBar + MMIO_ISB_OFFSET + CND003_MMIO_D0F0_VCORE_GPIO_PAD_SEL, CND003_MMIO_D0F0_R_PAD_GPIO5, 1<<10);



	return Statusx;
}

/**
   IoeTopPinFunctionSel.

  This function used to initialize some Pin & functions 
  in MMIO_ISB,	some TOP_PMU, CLK and GPIO configuration 
  need to be done

   
  @param  PeiServices	EFI_PEI_SERVICES pointer.

  @return EFI_STATUS.

**/

STATIC
EFI_STATUS 
IoeTopPinFunctionSel(IN EFI_PEI_SERVICES  **PeiServices)
{

	EFI_STATUS Status = EFI_SUCCESS;
	UINT32 MmioBar;
	UINT16 PinMuxBuf;

	//
	// Different on each board
	//
	PEI_DEBUG((PeiServices, EFI_D_ERROR, "[CJW_IOE] IoePinMuxSelection() Found IOE!\n"));
	MmioBar = AsiaPciRead32(AsiaPciAddress(BUSX, UPPORT_DEV, DNPORT_FUN, 0x10));

	PinMuxBuf = ((IoePinMuxCfg.gpio7)<<14) + ((IoePinMuxCfg.gpio6)<<12) +
							((IoePinMuxCfg.gpio5)<<10) + ((IoePinMuxCfg.gpio4)<<8) + 
							((IoePinMuxCfg.gpio3)<<6) + ((IoePinMuxCfg.gpio2)<<4) + 
							((IoePinMuxCfg.gpio1)<<2) + ((IoePinMuxCfg.gpio0)<<0) ;
	//MMIO_ISB Rx0C-0D
	AsiaMemoryWrite16(MmioBar + MMIO_ISB_OFFSET + CND003_MMIO_D0F0_VCORE_GPIO_PAD_SEL, PinMuxBuf);


	PinMuxBuf = ((IoePinMuxCfg.gpio9)<<14) + ((IoePinMuxCfg.gpio8)<<12) +
							((IoePinMuxCfg.gpo5)<<10) + ((IoePinMuxCfg.gpo4)<<8) + 
							((IoePinMuxCfg.gpo3)<<6) + ((IoePinMuxCfg.gpo2)<<4) + 
							((IoePinMuxCfg.gpo1)<<2) + ((IoePinMuxCfg.gpo0)<<0) ;		
	//MMIO_ISB Rx0E-0F
	AsiaMemoryWrite16(MmioBar + MMIO_ISB_OFFSET + CND003_MMIO_D0F0_VCORE_GPO_PAD_SEL, PinMuxBuf);

	//
	// Common part
	//
	//For A0, PHYA Refclk = Internal, PHYB Refclk = External
	//AsiaMemoryModify8(MmioBar + MMIO_ISB_OFFSET + 0x34, BIT7|BIT6, BIT7);

	//SCI enable
	//AsiaMemoryModify16(MmioBar + MMIO_ISB_OFFSET + 0x14, BIT2, BIT2);

	//Disable UART use GPIO related pads, default to disable it! if need, enable it later!
	AsiaMemoryModify16(MmioBar + MMIO_ISB_OFFSET + CND003_MMIO_D0F0_STRAPPING_PIN_READ_BACK_REG_GRP_1, BIT13, 0);
		
	return Status;
}


/**
Function:
	This function used for IOE CKGSRC group 
	register setting
Regs:	
	CKGSRC PLLPCIEA SSC Enable - Enabled   		--  Rx52[0]
	CKGSRC PLLPCIEA SSC Magnitude - -0.5%     	-- Rx52[6:4]
	CKGSRC PLLPCIEA SSC Spread Mode �C Down Spread - Rx52[1]

	CKGSRC PLLPCIEB SSC Enable - Disabled    	--Rx54[0]
	CKGSRC PLLPCIEB SSC Magnitude - NA
	CKGSRC PLLPCIEB SSC Spread Mode - NA

	USB Clock Selection - PLLA         			--Rx51[1]
	SATA Clock Selection - PLLA       			--Rx51[0]

	PCIECLKN/P[9:0] IO Power up/Output Control - Auto   -- Rx
**/
EFI_STATUS
IoeCKGSRCInit(
	IN EFI_PEI_SERVICES  **PeiServices,
	ASIA_NB_CONFIGURATION *NbCfg)
{
	UINT32 MmioBar = 0;
	MmioBar = AsiaPciRead32(AsiaPciAddress(BUSX, UPPORT_DEV, UPPORT_FUN, CND003_BUSX_D0F0_LOWER_BASE_ADR));

	
	//CKGSRC restore to A0 default value Rx51[6:4]=111'b 
	AsiaMemoryModify32(MmioBar + MMIO_ISB_OFFSET + 0x50, BIT14|BIT13|BIT12, BIT14|BIT13);
	AsiaMemoryModify32(MmioBar + MMIO_ISB_OFFSET + 0x50, BIT16, 0); 
	AsiaMemoryModify32(MmioBar + MMIO_ISB_OFFSET + 0x50, BIT16, BIT16);  //toggle

	if(NbCfg->CND003PLLPCIEASSCEn){
		AsiaMemoryModify8(MmioBar + MMIO_ISB_OFFSET + CND003_MMIO_D0F0_CKGSRC_SETTING_GRP2, 
						CND003_MMIO_D0F0_RSRC_SSCEN_A, CND003_MMIO_D0F0_RSRC_SSCEN_A);

		AsiaMemoryModify8(MmioBar + MMIO_ISB_OFFSET + CND003_MMIO_D0F0_CKGSRC_SETTING_GRP2, 
						CND003_MMIO_D0F0_RSRC_SSCMA_A, (0x7&(NbCfg->CND003PLLPCIEASSCMagnitude))<<4);
		AsiaMemoryModify8(MmioBar + MMIO_ISB_OFFSET + CND003_MMIO_D0F0_CKGSRC_SETTING_GRP2, 
						CND003_MMIO_D0F0_RSRC_SSCSPRD_A, (0x1&(NbCfg->CND003CKGSRCPLLPCIEASSCSpread))<<1);		

	}else{
		AsiaMemoryModify8(MmioBar + MMIO_ISB_OFFSET + CND003_MMIO_D0F0_CKGSRC_SETTING_GRP2, 
						CND003_MMIO_D0F0_RSRC_SSCEN_A, 0);
	}

	if(NbCfg->CND003PLLPCIEBSSCEn){
		AsiaMemoryModify8(MmioBar + MMIO_ISB_OFFSET + CND003_MMIO_D0F0_CKGSRC_SETTING_GRP_3, 
						CND003_MMIO_D0F0_RSRC_SSCEN_B, CND003_MMIO_D0F0_RSRC_SSCEN_B);	
		
		AsiaMemoryModify8(MmioBar + MMIO_ISB_OFFSET + CND003_MMIO_D0F0_CKGSRC_SETTING_GRP_3, 
						CND003_MMIO_D0F0_RSRC_SSCMA_B, (0x7&(NbCfg->CND003PLLPCIEASSCMagnitude))<<4);
		AsiaMemoryModify8(MmioBar + MMIO_ISB_OFFSET + CND003_MMIO_D0F0_CKGSRC_SETTING_GRP_3, 
						CND003_MMIO_D0F0_RSRC_SSCSPRD_B, (0x1&(NbCfg->CND003CKGSRCPLLPCIEASSCSpread))<<1);	
		
	}else{
		AsiaMemoryModify8(MmioBar + MMIO_ISB_OFFSET + CND003_MMIO_D0F0_CKGSRC_SETTING_GRP_3, 
						CND003_MMIO_D0F0_RSRC_SSCEN_B, 0);		
	}

	//USB
	AsiaMemoryModify8(MmioBar + MMIO_ISB_OFFSET + CND003_MMIO_D0F0_CKGSRC_SETTING_GRP_1, 
						CND003_MMIO_D0F0_RUSBCLK_SEL, (0x1&(NbCfg->CND003USBCLKSEL))<<1);
	//SATA
	AsiaMemoryModify8(MmioBar + MMIO_ISB_OFFSET + CND003_MMIO_D0F0_CKGSRC_SETTING_GRP_1, 
						CND003_MMIO_D0F0_RSATACLK_SEL, (0x1&(NbCfg->CND003USBCLKSEL)));

	// PCIECLKN/P[9:0] IO Power up/Output Control
	AsiaMemoryModify16(MmioBar + MMIO_ISB_OFFSET + CND003_MMIO_D0F0_CKGSRC_SETTING_GRP_6, 
						CND003_MMIO_D0F0_RPCIE_PU_IO, 0x3FF&(NbCfg->CND003_RPCIE_PU_IO));
	AsiaMemoryModify16(MmioBar + MMIO_ISB_OFFSET + CND003_MMIO_D0F0_CKGSRC_SETTING_GRP_7, 
						CND003_MMIO_D0F0_RPCIE_TNO_IO, 0x3FF&(NbCfg->CND003_RPCIE_TNO_IO));

	
	return EFI_SUCCESS;
}





#if IOE_PRE_INIT_LOCATION == IOE_ASIA_PEI_SB

/*
	In SPI mode
	before to initialize the IOE
	we need to guarantee the PATCHDONE have been set by MCU

	In BIOS mode
	return EFI_SUCCESS directly
*/
STATIC
EFI_STATUS
IoeWaitPatchDone(
	IN EFI_PEI_SERVICES  **PeiServices, 
	ASIA_SB_CONFIGURATION *SbCfg)
{
	EFI_STATUS Status;
	UINT8 ts;

	//AsiaIoWrite8(0x80, WAIT_MCU_PATCHDONE);
	
	if(SbCfg->Cnd003ModeSel == BIOS_MODE){
		PEI_DEBUG((PeiServices, EFI_D_ERROR, "[CJW_IOE] In BIOS mode - SbInit()\n"));

		return EFI_SUCCESS;
	}
	PEI_DEBUG((PeiServices, EFI_D_ERROR, "[CJW_IOE] In SPI mode - SbInit()\n"));
_WaitPatchDone:	
	for(ts = 0; ts < (sizeof(IoeSearchTbl)/sizeof(SEARCH_TBL)); ts++){	
		Status = IoeSearchPcieRpTemporary(PeiServices,IoeSearchTbl[ts].BusNum,IoeSearchTbl[ts].DevNum,IoeSearchTbl[ts].FunNum);
		if(Status == EFI_SUCCESS){
#if MULTI_IOE_SUPPORT			
			if(!IoeIsUsablePort(PeiServices,IoeSearchTbl[ts].BusNum,IoeSearchTbl[ts].DevNum,IoeSearchTbl[ts].FunNum)){
				Status = EFI_NOT_FOUND;
				continue;
			}
#endif			
			return Status;
		}
	}
	goto _WaitPatchDone;

	
}

/**
	In BIOS mode, scan RP table to search IOE and set Scratch Register
	In SPI mode, set Scratch Register to 0 directly
**/
STATIC
EFI_STATUS
IoeExistFlagSetting(
	IN EFI_PEI_SERVICES  **PeiServices,
	ASIA_SB_CONFIGURATION *SbCfg)
{
	

	EFI_STATUS Status = EFI_NOT_FOUND;
	UINT8 ts;

	PEI_DEBUG((PeiServices, EFI_D_ERROR, "\n[CJW_IOE] IoeExistFlagSetting(): Search IOE's Location\n"));

	if(SbCfg->Cnd003ModeSel == SPI_MODE){
		AsiaPcieModify32(PCI_BASE, HOST_SCRATCH|D0F6_BIOS_SCRATCH_REG_2, BIT24, 0);
		PEI_DEBUG((PeiServices, EFI_D_ERROR, "\n[CJW_IOE] BIOS: IOE work in SPI mode!\n"));
		return EFI_SUCCESS;
	}

#ifndef CND003_FPGA
	//
	// before scaning IOE, need to do lane reversal if necessory
	//
	IoeLaneReversal(PeiServices);
#endif

	for(ts = 0; ts < (sizeof(IoeSearchTbl)/sizeof(SEARCH_TBL)); ts++){
		PEI_DEBUG((PeiServices, EFI_D_ERROR, "[CJW_IOE] --\n"));
		
		//Search for IOE on each ports in list
		Status = IoeSearchPcieRpTemporary(PeiServices,IoeSearchTbl[ts].BusNum,IoeSearchTbl[ts].DevNum,IoeSearchTbl[ts].FunNum);
		if(Status == EFI_SUCCESS){
#if MULTI_IOE_SUPPORT			
			if(!IoeIsUsablePort(PeiServices,IoeSearchTbl[ts].BusNum,IoeSearchTbl[ts].DevNum,IoeSearchTbl[ts].FunNum)){
				Status = EFI_NOT_FOUND;
				continue;
			}
#endif			
			//Found IOE
			PEI_DEBUG((PeiServices, EFI_D_ERROR, "[CJW_IOE] %a() Line%d: Found IOE! [%d|%d|%d]\n",
												__FUNCTION__,__LINE__,IoeSearchTbl[ts].BusNum,IoeSearchTbl[ts].DevNum,IoeSearchTbl[ts].FunNum));

			// Set IOE Exist Flag - D0F6 Rx47[0]
			AsiaPcieModify32(PCI_BASE, HOST_SCRATCH|D0F6_BIOS_SCRATCH_REG_2, BIT24, BIT24);

			Status = EFI_SUCCESS;
			goto __FoundIoe;	
		}else{
			PEI_DEBUG((PeiServices, EFI_D_ERROR, "[CJW_IOE] %a() Line%d: Not Found IOE [%d|%d|%d]\n",
												__FUNCTION__,__LINE__,IoeSearchTbl[ts].BusNum,IoeSearchTbl[ts].DevNum,IoeSearchTbl[ts].FunNum));	
		}	

	}

	AsiaPcieModify32(PCI_BASE, HOST_SCRATCH|D0F6_BIOS_SCRATCH_REG_2, BIT24, 0);

__FoundIoe:    
	//Print some Status
	/*PEI_DEBUG((PeiServices, EFI_D_ERROR, "[CJW_IOE_p] BusNumberOfBusX = %d\n",BusNumberOfBusX));
	PEI_DEBUG((PeiServices, EFI_D_ERROR, "[CJW_IOE_p] BUSNumberOfBusXp2 = %d\n",BUSNumberOfBusXp2));
	PEI_DEBUG((PeiServices, EFI_D_ERROR, "[CJW_IOE_p] IoeSubBusNumber = %d\n",IoeSubBusNumber));
	PEI_DEBUG((PeiServices, EFI_D_ERROR, "[CJW_IOE_p] IoeConnectDevNum = %d\n",IoeConnectDevNum));
	PEI_DEBUG((PeiServices, EFI_D_ERROR, "[CJW_IOE_p] IoeConnectFunNum = %d\n",IoeConnectFunNum));*/

	// Just for Test
	{
		UINT32 IoeExistFlag;
		IoeExistFlag = AsiaPcieRead32(PCI_BASE, HOST_SCRATCH|D0F6_BIOS_SCRATCH_REG_2);
		PEI_DEBUG((PeiServices, EFI_D_INFO, "[CJW_IOE] IoeExistFlag = %d\n", 
											 	(IoeExistFlag&BIT24)?1:0));
	}
	
	return Status;	

}





/**
	The behavior of this routine is same with IoePeiNbPreInit()
	the only different is this routine can only be called in 
	PeiSbPreMemoryInit()
**/
EFI_STATUS
IoePeiSbPreInit(
	IN EFI_PEI_SERVICES  **PeiServices,
	ASIA_SB_CONFIGURATION *SbCfg)
{

	IoeWaitPatchDone(PeiServices, SbCfg);

	IoeExistFlagSetting(PeiServices,SbCfg);

	if(IoeExist()){
		IoeTopPinFunctionSel(PeiServices);
		
		IoeDebugSignalSel(PeiServices, SbCfg);

		IoeAbolishHideXbctlEptrfc(PeiServices);	

		//IoeGpioConfigure(PeiServices);
		
	}else{
		PEI_DEBUG((PeiServices, EFI_D_ERROR, "[CJW_IOE] SKIP CND003 Init (1)\n"));
	}
	return EFI_SUCCESS;
}

#elif IOE_PRE_INIT_LOCATION == IOE_ASIA_PEI_NB 

/*
	In SPI mode
	before to initialize the IOE
	we need to guarantee the PATCHDONE have been set by MCU

	In BIOS mode
	return EFI_SUCCESS directly
*/
STATIC
EFI_STATUS
IoeWaitPatchDone(
	IN EFI_PEI_SERVICES  **PeiServices, 
	ASIA_NB_CONFIGURATION *NbCfg)
{
	EFI_STATUS Status;
	UINT8 ts;

	//AsiaIoWrite8(0x80, WAIT_MCU_PATCHDONE);
	
	if(NbCfg->Cnd003ModeSel == BIOS_MODE){
		PEI_DEBUG((PeiServices, EFI_D_ERROR, "[CJW_IOE] In BIOS mode - SbInit()\n"));
		
		return EFI_SUCCESS;
	}
	PEI_DEBUG((PeiServices, EFI_D_ERROR, "[CJW_IOE] In SPI mode - SbInit()\n"));
_WaitPatchDone:	
	for(ts = 0; ts < (sizeof(IoeSearchTbl)/sizeof(SEARCH_TBL)); ts++){	
		Status = IoeSearchPcieRpTemporary(PeiServices,IoeSearchTbl[ts].BusNum,IoeSearchTbl[ts].DevNum,IoeSearchTbl[ts].FunNum);
		if(Status == EFI_SUCCESS){
#if MULTI_IOE_SUPPORT			
			if(!IoeIsUsablePort(PeiServices,IoeSearchTbl[ts].BusNum,IoeSearchTbl[ts].DevNum,IoeSearchTbl[ts].FunNum)){
				Status = EFI_NOT_FOUND;
				continue;
			}
#endif
			return Status;
		}
	}
	goto _WaitPatchDone;

	
}

/**
	In BIOS mode, scan RP table to search IOE and set Scratch Register
	In SPI mode, set Scratch Register to 0 directly
**/
STATIC
EFI_STATUS
IoeExistFlagSetting(
	IN EFI_PEI_SERVICES  **PeiServices,
	ASIA_NB_CONFIGURATION *NbCfg,
	UINT8 *Devp, 
	UINT8 *Funcp)
{
	

	EFI_STATUS Status = EFI_NOT_FOUND;
	UINT8 ts;

	PEI_DEBUG((PeiServices, EFI_D_ERROR, "\n[CJW_IOE] IoeExistFlagSetting(): Search IOE's Location\n"));

	if(NbCfg->Cnd003ModeSel == SPI_MODE){
		AsiaPcieModify32(PCI_BASE, HOST_SCRATCH|D0F6_BIOS_SCRATCH_REG_2, BIT24, 0);
		PEI_DEBUG((PeiServices, EFI_D_ERROR, "\n[CJW_IOE] BIOS: IOE work in SPI mode!\n"));
		return EFI_SUCCESS;
	}

#ifndef CND003_FPGA
	//
	// before scaning IOE, need to do lane reversal if necessory
	//
	IoeLaneReversal(PeiServices);
#endif
	
	for(ts = 0; ts < (sizeof(IoeSearchTbl)/sizeof(SEARCH_TBL)); ts++){
		PEI_DEBUG((PeiServices, EFI_D_ERROR, "[CJW_IOE] --\n"));
		
		//Search for IOE on each ports in list
		Status = IoeSearchPcieRpTemporary(PeiServices,IoeSearchTbl[ts].BusNum,IoeSearchTbl[ts].DevNum,IoeSearchTbl[ts].FunNum);
		if(Status == EFI_SUCCESS){
#if MULTI_IOE_SUPPORT
			if(!IoeIsUsablePort(PeiServices,IoeSearchTbl[ts].BusNum,IoeSearchTbl[ts].DevNum,IoeSearchTbl[ts].FunNum)){
				Status = EFI_NOT_FOUND;
				continue;
			}
#endif			
			//Found IOE
			PEI_DEBUG((PeiServices, EFI_D_ERROR, "[CJW_IOE] %a() Line%d: Found IOE! [%d|%d|%d]\n",
												__FUNCTION__,__LINE__,IoeSearchTbl[ts].BusNum,IoeSearchTbl[ts].DevNum,IoeSearchTbl[ts].FunNum));

			// Set IOE Exist Flag - D0F6 Rx47[0]
			AsiaPcieModify32(PCI_BASE, HOST_SCRATCH|D0F6_BIOS_SCRATCH_REG_2, BIT24, BIT24);

			// Get the Internal Chip Revision ID
			AsiaPciWrite8(AsiaPciAddress(IoeSearchTbl[ts].BusNum,IoeSearchTbl[ts].DevNum,IoeSearchTbl[ts].FunNum, 0x18), BUS0);
			AsiaPciWrite8(AsiaPciAddress(IoeSearchTbl[ts].BusNum,IoeSearchTbl[ts].DevNum,IoeSearchTbl[ts].FunNum, 0x19), BUSX);
			AsiaPciWrite8(AsiaPciAddress(IoeSearchTbl[ts].BusNum,IoeSearchTbl[ts].DevNum,IoeSearchTbl[ts].FunNum, 0x1A), BUSX);
			NbCfg->IoeChipRevision = AsiaPciRead8(AsiaPciAddress(BUSX,UPPORT_DEV,UPPORT_FUN, CND003_BUSX_D0F0_INTERNAL_REV_ID));
			PEI_DEBUG((PeiServices, EFI_D_ERROR, "[CJW_IOE] IOE Internal Revision ID = 0x%02x(NB)\n",NbCfg->IoeChipRevision));
			
			AsiaPciWrite8(AsiaPciAddress(IoeSearchTbl[ts].BusNum,IoeSearchTbl[ts].DevNum,IoeSearchTbl[ts].FunNum, 0x18), 0);
			AsiaPciWrite8(AsiaPciAddress(IoeSearchTbl[ts].BusNum,IoeSearchTbl[ts].DevNum,IoeSearchTbl[ts].FunNum, 0x19), 0);
			AsiaPciWrite8(AsiaPciAddress(IoeSearchTbl[ts].BusNum,IoeSearchTbl[ts].DevNum,IoeSearchTbl[ts].FunNum, 0x1A), 0);

			*Devp = IoeSearchTbl[ts].DevNum;
			*Funcp= IoeSearchTbl[ts].FunNum;
			
			Status = EFI_SUCCESS;
			goto __FoundIoe;	
		}else{
			PEI_DEBUG((PeiServices, EFI_D_ERROR, "[CJW_IOE] %a() Line%d: Not Found IOE [%d|%d|%d]\n",
												__FUNCTION__,__LINE__,IoeSearchTbl[ts].BusNum,IoeSearchTbl[ts].DevNum,IoeSearchTbl[ts].FunNum));	
		}	

	}

	AsiaPcieModify32(PCI_BASE, HOST_SCRATCH|D0F6_BIOS_SCRATCH_REG_2, BIT24, 0);
	
__FoundIoe:    
	//Print some Status
	/*PEI_DEBUG((PeiServices, EFI_D_ERROR, "[CJW_IOE_p] BusNumberOfBusX = %d\n",BusNumberOfBusX));
	PEI_DEBUG((PeiServices, EFI_D_ERROR, "[CJW_IOE_p] BUSNumberOfBusXp2 = %d\n",BUSNumberOfBusXp2));
	PEI_DEBUG((PeiServices, EFI_D_ERROR, "[CJW_IOE_p] IoeSubBusNumber = %d\n",IoeSubBusNumber));
	PEI_DEBUG((PeiServices, EFI_D_ERROR, "[CJW_IOE_p] IoeConnectDevNum = %d\n",IoeConnectDevNum));
	PEI_DEBUG((PeiServices, EFI_D_ERROR, "[CJW_IOE_p] IoeConnectFunNum = %d\n",IoeConnectFunNum));*/

	// Just for Test
	{
		UINT32 IoeExistFlag;
		IoeExistFlag = AsiaPcieRead32(PCI_BASE, HOST_SCRATCH|D0F6_BIOS_SCRATCH_REG_2);
		PEI_DEBUG((PeiServices, EFI_D_INFO, "[CJW_IOE] IoeExistFlag = %d\n", 
											 	(IoeExistFlag&BIT24)?1:0));
	}

	//SwDbg-1-0-SwDbg-2-Hang22
	if((NbCfg->Cnd003SwDbg1 == 0)&&((NbCfg->Cnd003SwDbg2) & BIT2)){
		PEI_DEBUG((PeiServices, EFI_D_ERROR, "SwDbg-1-0-SwDbg-2-Hang22\n"));
		IoePeiPort80(PeiServices, 0x22);
	}

	return Status;	

}


/**
	The behavior of this routine is same with IoePeiSbPreInit()
	the only different is this routine can only be called in 
	PeiNbPreMemoryInit()
**/
EFI_STATUS
IoePeiNbPreInit(
	IN EFI_PEI_SERVICES  **PeiServices,
	ASIA_NB_CONFIGURATION *NbCfg)
{
	EFI_STATUS Statusx = EFI_SUCCESS;
    #if 0
    UINT8 value8;
	PEI_DEBUG((PeiServices, EFI_D_ERROR, "[ALJ_IOE] Smbus DebugPath Test Start\n"));
    IoeSmbusDebugPathEnable(PeiServices,1);
	IoeSmbusCfgDebugRead8(PeiServices,0,0,0,0x0,&value8);
	PEI_DEBUG((PeiServices, EFI_D_INFO, "[ALJ_IOE] ISmbus 0x0= %02x\n",value8));
	IoeSmbusCfgDebugRead8(PeiServices,0,0,0,0x18,&value8);
	PEI_DEBUG((PeiServices, EFI_D_INFO, "[ALJ_IOE] ISmbus 0x18 = %02x\n", value8));
	IoeSmbusCfgDebugWrite8(PeiServices,0,0,0,0x18,0xed);
	IoeSmbusCfgDebugRead8(PeiServices,0,0,0,0x18,&value8);
	PEI_DEBUG((PeiServices, EFI_D_INFO, "[ALJ_IOE] ISmbus 0x18 = %02x\n", value8));
	IoeSmbusCfgDebugModify8(PeiServices,0,0,0,0x18,BIT7|BIT5|BIT6,0x00);
	IoeSmbusCfgDebugRead8(PeiServices,0,0,0,0x18,&value8);
	PEI_DEBUG((PeiServices, EFI_D_INFO, "[ALJ_IOE] ISmbus 0x18 = %02x\n", value8));
	PEI_DEBUG((PeiServices, EFI_D_ERROR, "[ALJ_IOE] Smbus DebugPath Test End\n"));
	IoeSmbusDebugPathEnable(PeiServices,0);										
 #endif
 #if 0
	IoeSmbusDebugPathEnable(PeiServices,1);
    IoeSmbusCfgDebugWrite8(PeiServices,0,0,0,0x13,0xfe);
	IoeSmbusDebugModify8(PeiServices,0xfe001100+0x53,1,0xe0,0x00);
	IoeSmbusDebugModify8(PeiServices,0xfe001100+0x55,1,0xe0,0x00);
	IoeSmbusDebugModify8(PeiServices,0xfe001100+0x51,1,BIT0|BIT1, BIT0|BIT1);
    IoeSmbusCfgDebugWrite8(PeiServices,0,0,0,0x13,0x00);
	IoeSmbusDebugPathEnable(PeiServices,0);
	IoeDbgCapSetup(PeiServices, NbCfg);
#endif
	//IoeWaitPatchDone(PeiServices, NbCfg);

	if(IoeExist()){

		Statusx = IoePeiTempAssignment(PeiServices);
		if(Statusx == EFI_SUCCESS){

			IoeCKGSRCInit(PeiServices,NbCfg);

			IoeTopPinFunctionSel(PeiServices);

			IoeDebugSignalSel(PeiServices, NbCfg);

			IoeAbolishHideXbctlEptrfc(PeiServices);	

			//IoeGpioConfigure(PeiServices);

			IoePeiClearTempAssignment(PeiServices);
		}else{
			PEI_DEBUG((PeiServices, EFI_D_ERROR, "[CJW_IOE] IoePeiNbPreInit() Not Found IOE!\n"));
		}

		
		
	}else{
		PEI_DEBUG((PeiServices, EFI_D_ERROR, "[CJW_IOE] SKIP CND003 Init (1)\n"));
	}
	return EFI_SUCCESS;
}

#endif


/********************************************************************************************/


EFI_STATUS
IoePatchPeiNb(	
	IN EFI_PEI_SERVICES  **PeiServices,
	ASIA_NB_CONFIGURATION *NbCfg)
{

	if(NbCfg->Cnd003ForceMPS128B == 1){
		//
		// For CND003 Design bug, we need to force Max Payload Size
		//	of IOE tree to 128B
		//  Note: when set to 256Byte, will cause performance reduce
		//
		AsiaPciModify8(AsiaPciAddress(BUSXP1, XBCTL, DNPORT_FUN, CND003_MMIO_D0F0_BACKDOOR_REG_CTL_0), 
												CND003_MMIO_D0F0_RPEROWEN, CND003_MMIO_D0F0_RPEROWEN);
		AsiaPciModify8(AsiaPciAddress(BUSX, UPPORT_DEV, UPPORT_FUN, CND003_BUSX_D0F0_DEV_CAPS_1), 
																	CND003_BUSX_D0F0_DAMPSS, 0);
		AsiaPciModify8(AsiaPciAddress(BUSXP1, XBCTL, DNPORT_FUN, CND003_MMIO_D0F0_BACKDOOR_REG_CTL_0), 
												CND003_MMIO_D0F0_RPEROWEN, 0);
	}



	return EFI_SUCCESS;
}


/**
   PciePatchforIOE.
  This routine have some RP's register setting to patch IOE  -- before linkup

   
  @param  PeiServices	EFI_PEI_SERVICES pointer.
  @param SbCfg point to ASIA_SB_CONFIGURATION struct

  @return VOID.

**/

EFI_STATUS
PciePatchforIOE(
	IN EFI_PEI_SERVICES  **PeiServices,
	IN ASIA_NB_CONFIGURATION *NbCfg,
	IN UINT64 BDFno)
{

    	UINT64 PcieBase;
	UINT8 Busx,Devx,Funcx;
	UINT64 BDFLocal = BDFno;
	UINT8 *tmp = (UINT8 *)(&BDFLocal);
	
	Busx = *(tmp+3);
	Devx = *(tmp+2);
	Funcx = *(tmp+1);	

	if(EFI_SUCCESS != IoeSearchPcieRpTemporary(PeiServices, Busx, Devx, Funcx)){
		PEI_DEBUG((PeiServices, EFI_D_INFO, "[CJW_IOE] No need to patch for this port (%d:%d.%d)\n",Busx,Devx,Funcx));
		return EFI_SUCCESS;
	}
	
	PcieBase = NbCfg->PcieBar; 

	//Set Target Link-Speed to GEN1 for Initialization
	PEI_DEBUG((PeiServices, EFI_D_INFO, "[PCIE] Set Target Link-Speed to GEN1 for IOE Initialization - "));
	AsiaPcieModify8(PcieBase, BDFno|((UINT64)HOST_LINK_CTL_2_D4F0 << 32), HOST_LKTGLS_0 + HOST_LKTGLS_1 + HOST_LKTGLS_2 + HOST_LKTGLS_3, HOST_LKTGLS_0);

	PEI_DEBUG((PeiServices, EFI_D_INFO, "RP_Rx70 (Target Link-Speed) = 0x%x after setting\n", AsiaPcieRead8(PcieBase, BDFno|((UINT64)HOST_LINK_CTL_2_D4F0 << 32))));


	return EFI_SUCCESS;
}


/**
	This routine have some RP's register setting to patch IOE -- after linkup
**/
EFI_STATUS
PciePatchforIoeAfterLinkup(	
	IN EFI_PEI_SERVICES  **PeiServices,
	ASIA_NB_CONFIGURATION *NbCfg)
{
	UINT8 IoeRpDev,IoeRpFunc;
    UINT64 PcieBase;
    PcieBase = NbCfg->PcieBar; 
	
	// Before any patch executed, we need to detect whether IOE exist and read Chip Internal Revision ID
	IoeExistFlagSetting(PeiServices,NbCfg, &IoeRpDev, &IoeRpFunc);

	PEI_DEBUG((PeiServices, EFI_D_ERROR, "==> Get RP D%dF%d\n",IoeRpDev,IoeRpFunc));

	if(IoeExist()){
		if((NbCfg->IoeChipRevision) == IOE_REVISION_A0){

			if(NbCfg->PcieForceLinkWidth == PcieForceLinkWidth_default){	//only do following patch when "RP Link-Width Capability Control" Setup-Item (i.e., Force Link-Width select) selected to "default"

				//;Force PEG to x2 Link-Width Capability for avoiding CND003_A0 Credit Design Issue
				AsiaPcieModify8(PcieBase, HOST_BACKDOOR_APIC|((UINT64)HOST_BACKDOOR_D0F5_PMU_CTL << 32), HOST_BACKDOOR_D0F5_RPEROWEN, D0F5_RPEROWEN);
				AsiaPcieModify16(PcieBase, AsiaPciAddress(BUS0, IoeRpDev, IoeRpFunc, HOST_LINK_CAPS_1_D4F0),HOST_LKMLW_0 + HOST_LKMLW_1 + HOST_LKMLW_2 + HOST_LKMLW_3 + HOST_LKMLW_4 + HOST_LKMLW_5, 0x20);
				AsiaPcieModify8(PcieBase, HOST_BACKDOOR_APIC|((UINT64)HOST_BACKDOOR_D0F5_PMU_CTL << 32), HOST_BACKDOOR_D0F5_RPEROWEN, 0x00);	

				// Retrain link
				AsiaPcieModify8(PcieBase, AsiaPciAddress(BUS0, IoeRpDev, IoeRpFunc, HOST_LINK_CTL_1), HOST_LCRL, HOST_LCRL);
				while(AsiaPcieRead8(PcieBase, AsiaPciAddress(BUS0, IoeRpDev, IoeRpFunc, HOST_PHYLS_LTSSM_STATE)) != HOST_PHYLS_State_L0);
			}

		}	
	}else{
		PEI_DEBUG((PeiServices, EFI_D_ERROR, "[CJW_IOE] SKIP CND003 Init (0)\n"));
	}
	

	return EFI_SUCCESS;
}







/********************************************************************************************/
//Verfication related code


//#define FOR_TEMP 1 //for skip bug
/**
   DebugPciePtnDefaultVerify.

  This routine only written for debug/Verification

  @param  PeiServices	EFI_PEI_SERVICES pointer.

  @return VOID.

**/

VOID
DebugPciePtnDefaultVerify(
	IN EFI_PEI_SERVICES **PeiServices
)
{
//
//To select the test item
//
//#define VSUS_POWER_TEST_MMIOISB		1





//print Default value
//Only for PCIE PTN
#if 1   //lab7 
	{
	//for dump  registers of MMIO space
	//assign a temp bar for it
	/*
		FE028000
	*/
	
		UINT8 xBus = 0;
		UINT8 xDev;
		UINT8 xFunc;

		
		
	
		//#define xBus  	IOE_UNDER_BUS
		//#define xDev  	IOE_UNDER_DEV
		//#define xFunc  	IOE_UNDER_FUN




		#define xBUS_ISB			4
		#define xDEV_ISB_EPTRFC		0
		#define xFUNC_ISB_EPTRFC	0
		#define xDEV_ISB_SATA		15
		#define xFUNC_ISB_SATA		0		

		
		//UINT16 offsetx = 0;
		UINT16 tx;
		UINT32 Temp32x;
		

		PEI_DEBUG((PeiServices, EFI_D_ERROR, "[CJW_IOE] In IoePciePtnVerify() <--\n"));


		IoeGetRpToFindIoe(PeiServices, &xDev, &xFunc);

		//To see some registers
		Temp32x = AsiaPciRead32(AsiaPciAddress(0, 0, 5, 0x60));
		PEI_DEBUG((PeiServices, EFI_D_ERROR, "[CJW_IOE] Rx63-60 = %08X\n",Temp32x));
		Temp32x = AsiaPciRead32(AsiaPciAddress(0, 0, 5, 0x64));
		PEI_DEBUG((PeiServices, EFI_D_ERROR, "[CJW_IOE] Rx67-64 = %08X\n",Temp32x));
		Temp32x = AsiaPciRead32(AsiaPciAddress(0, 0, 5, 0x68));
		PEI_DEBUG((PeiServices, EFI_D_ERROR, "[CJW_IOE] Rx6B-68 = %08X\n",Temp32x));
		Temp32x = AsiaPciRead32(AsiaPciAddress(0, 0, 5, 0x6C));
		PEI_DEBUG((PeiServices, EFI_D_ERROR, "[CJW_IOE] Rx6F-6C = %08X\n",Temp32x));

//4 [1] Setting for Bus0 D7F0
		//Bus Assign
		AsiaPciWrite8(AsiaPciAddress(xBus, xDev, xFunc, 0x18), 0x00);
		AsiaPciWrite8(AsiaPciAddress(xBus, xDev, xFunc, 0x19), 0x01);
		AsiaPciWrite8(AsiaPciAddress(xBus, xDev, xFunc, 0x1A), 0x04);

		//Base/Limit setting   FE020000-FE03FFFF  --  for MB's RP
		AsiaPciWrite16(AsiaPciAddress(xBus, xDev, xFunc, 0x20), 0xFE02);
		AsiaPciWrite16(AsiaPciAddress(xBus, xDev, xFunc, 0x22), 0xFE03);
		//D7F0 Memory Space enable
		AsiaPciWrite8(AsiaPciAddress(xBus, xDev, xFunc, 0x04), 0x7); 

//4 [1.1] Dump B0D7F0 / BusX D0F0
		PEI_DEBUG((PeiServices, EFI_D_INFO, "\n------------------------------------D7F0:\n"));
		for(tx=0;tx <= 0xFF; tx+=4){
			if((tx & 0x0F) == 0x00){
				PEI_DEBUG((PeiServices, EFI_D_INFO, "\nRx%02x:",tx));	
			}
			Temp32x = AsiaPcieRead32((UINT64)PCI_BASE, AsiaPciAddress(0, 7, 0, tx));

			PEI_DEBUG((PeiServices, EFI_D_INFO, "%08X  ",Temp32x));		
		}
		
		//BusX D0F0
		PEI_DEBUG((PeiServices, EFI_D_INFO, "\n------------------------------------BusX D0F0:\n"));	
		for(tx=0;tx <= 0x2FF; tx+=4){
			if((tx & 0x0F) == 0x00){
				PEI_DEBUG((PeiServices, EFI_D_INFO, "\nRx%03x:",tx));	
			}
			Temp32x = AsiaPcieRead32((UINT64)PCI_BASE, AsiaPciAddress(1, 0, 0, tx));

			PEI_DEBUG((PeiServices, EFI_D_INFO, "%08X  ",Temp32x));		
		}


//4 [2] Setting for BUSX D0F0
		//MMIO Bar assignment  -- For BusX D0F0
		Temp32x = AsiaPcieRead32((UINT64)PCI_BASE, AsiaPciAddress(1, 0, 0, 0x10));
		PEI_DEBUG((PeiServices, EFI_D_INFO, "[CJW_IOE] Original [1,0,0]Rx10:%08X  \n",Temp32x));
		AsiaPciWrite8(AsiaPciAddress(1, 0, 0, 0x13), 0xFE);
		AsiaPciWrite8(AsiaPciAddress(1, 0, 0, 0x12), 0x02);
		AsiaPciWrite8(AsiaPciAddress(1, 0, 0, 0x11), 0x80);
		Temp32x = AsiaPcieRead32((UINT64)PCI_BASE, AsiaPciAddress(1, 0, 0, 0x10));
		PEI_DEBUG((PeiServices, EFI_D_INFO, "[CJW_IOE] After setting: [1,0,0]Rx10:%08X  \n",Temp32x));
		
		//Enable bridge's Mem space -- command register  of MB's RP
		Temp32x = AsiaPcieRead32((UINT64)PCI_BASE, AsiaPciAddress(1, 0, 0, 0x04));
		PEI_DEBUG((PeiServices, EFI_D_INFO, "[CJW_IOE] Original [1,0,0]Rx04:%08X  \n",Temp32x));
		AsiaPciWrite8(AsiaPciAddress(1, 0, 0, 0x04), 0x7); //BusX Memory Space enable

		//Assign more bus number  -- Behind BusX D0F0
		Temp32x = AsiaPcieRead32((UINT64)PCI_BASE, AsiaPciAddress(1, 0, 0, 0x18));
		PEI_DEBUG((PeiServices, EFI_D_INFO, "[CJW_IOE] Original [1,0,0]Rx18:%08X  \n",Temp32x));
		AsiaPciWrite8(AsiaPciAddress(1, 0, 0, 0x18), 0x01);
		AsiaPciWrite8(AsiaPciAddress(1, 0, 0, 0x19), 0x02);
		AsiaPciWrite8(AsiaPciAddress(1, 0, 0, 0x1A), 0x04);

/*
		Temp32x = AsiaPcieRead32((UINT64)PCI_BASE, AsiaPciAddress(2, 8, 0, 0x18));
		PEI_DEBUG((PeiServices, EFI_D_ERROR, "Original [2,8,0]Rx18:%08X  \n",Temp32x));
		AsiaPciWrite8(AsiaPciAddress(2, 8, 0, 0x18), 0x02);
		AsiaPciWrite8(AsiaPciAddress(2, 8, 0, 0x19), 0x03);
		AsiaPciWrite8(AsiaPciAddress(2, 8, 0, 0x1A), 0x04);

		Temp32x = AsiaPcieRead32((UINT64)PCI_BASE, AsiaPciAddress(3, 0, 0, 0x18));
		PEI_DEBUG((PeiServices, EFI_D_ERROR, "Original [3,0,0]Rx18:%08X  \n",Temp32x));
		AsiaPciWrite8(AsiaPciAddress(3, 0, 0, 0x18), 0x03);
		AsiaPciWrite8(AsiaPciAddress(3, 0, 0, 0x19), 0x04);
		AsiaPciWrite8(AsiaPciAddress(3, 0, 0, 0x1A), 0x04);
*/
		

		
#if 0
		//Temp test  - Hide the BusX+1 D0F0 in bios and boot to Win10	
		PEI_DEBUG((PeiServices, EFI_D_INFO, "[CJW_IOE]  Now we hide the Busx+1 D0F0\n"));		
		AsiaPciWrite8(AsiaPciAddress(1, 0, 0, 0x7C), 0x04);
#endif


		
		//For attribute test
		//AttrexCheck1(PeiServices,1,0,0);
		
//4 [2.1] Dump MMIO_EPHY
		PEI_DEBUG((PeiServices, EFI_D_INFO, "\n------------------------------------MMIO: EPHY\n"));
		for(tx=0;tx <= 0x10FF; tx+=4){
			if((tx & 0x0F) == 0x00){
				PEI_DEBUG((PeiServices, EFI_D_INFO, "\nRx%04x:",tx));	
			}
			Temp32x = AsiaMemoryRead32(0xFE028000 + tx);

			PEI_DEBUG((PeiServices, EFI_D_INFO, "%08X  ",Temp32x));		
		}

#if 1
//4 [2.2] Dump MMIO_ISB
		PEI_DEBUG((PeiServices, EFI_D_INFO, "\n------------------------------------MMIO: BUSx D0F0 MMIO_ISB\n"));
		for(tx=MMIO_ISB_OFFSET;tx <= 0x11FF; tx+=4){
			if((tx & 0x0F) == 0x00){
				PEI_DEBUG((PeiServices, EFI_D_INFO, "\nRx%04x:",tx));	
			}
			Temp32x = AsiaMemoryRead32(0xFE028000 + tx);

			PEI_DEBUG((PeiServices, EFI_D_INFO, "%08X  ",Temp32x));		
		}
		
		PEI_DEBUG((PeiServices, EFI_D_INFO, "\n------------------------------------BusX+3 D0F0  TBD:\n"));
#endif	


//4 [2.2.1] MMIO_ISB  Vsus Test
#ifdef VSUS_POWER_TEST_MMIOISB
{
		for(tx=MMIO_ISB_OFFSET;tx <= 0x11FF; tx+=4){
			Temp32x = AsiaMemoryRead32(0xFE028000 + tx);
			AsiaMemoryWrite32(0xFE028000 + tx, ~Temp32x);
		}
		PEI_DEBUG((PeiServices, EFI_D_INFO,"[CJW_IOE_VSUS_TEST] MMIO ISB VSUS test-->all reverse!\n"));
		PEI_DEBUG((PeiServices, EFI_D_INFO,"[CJW_IOE_VSUS_TEST] After reverse:\n"));

		for(tx=MMIO_ISB_OFFSET;tx <= 0x11FF; tx+=4){
			if((tx & 0x0F) == 0x00){
				PEI_DEBUG((PeiServices, EFI_D_INFO, "\nRx%04x:",tx));	
			}
			Temp32x = AsiaMemoryRead32(0xFE028000 + tx);

			PEI_DEBUG((PeiServices, EFI_D_INFO, "%08X  ",Temp32x));		
		}	
		
		PEI_DEBUG((PeiServices, EFI_D_INFO,"[CJW_IOE_VSUS_TEST] ....while(1)\n"));
		while(1);
}
#endif



//4 [2.3] Dump BusX+1 D0F0
		//BusX+1 D0F0
		PEI_DEBUG((PeiServices, EFI_D_INFO, "\n------------------------------------BusX+1 D0F0:\n"));
		for(tx=0;tx <= 0x1FF; tx+=4){
			if((tx & 0x0F) == 0x00){
				PEI_DEBUG((PeiServices, EFI_D_INFO, "\nRx%03x:",tx));	
			}
			Temp32x = AsiaPcieRead32((UINT64)PCI_BASE, AsiaPciAddress(2, 0, 0, tx));

			PEI_DEBUG((PeiServices, EFI_D_INFO, "%08X  ",Temp32x));		
		}

//4 [2.3] Dump BusX+1 D1_D5F0
		//BusX+1 D1F0		
		PEI_DEBUG((PeiServices, EFI_D_INFO, "\n------------------------------------BusX+1 D1F0:\n"));
		for(tx=0;tx <= 0x2FF; tx+=4){
			if((tx & 0x0F) == 0x00){
				PEI_DEBUG((PeiServices, EFI_D_INFO, "\nRx%03x:",tx));	
			}
			Temp32x = AsiaPcieRead32((UINT64)PCI_BASE, AsiaPciAddress(2, 1, 0, tx));

			PEI_DEBUG((PeiServices, EFI_D_INFO, "%08X  ",Temp32x));		
		}
	
		PEI_DEBUG((PeiServices, EFI_D_INFO, "\n------------------------------------BusX+1 D2F0  TBD:\n"));
		PEI_DEBUG((PeiServices, EFI_D_INFO, "\n------------------------------------BusX+1 D3F0  TBD:\n"));
		PEI_DEBUG((PeiServices, EFI_D_INFO, "\n------------------------------------BusX+1 D4F0  TBD:\n"));
		PEI_DEBUG((PeiServices, EFI_D_INFO, "\n------------------------------------BusX+1 D5F0  TBD:\n"));


//4 [2.4] Dump BusX+1 D6_D7F0
		//BusX+1 D6F0		
		PEI_DEBUG((PeiServices, EFI_D_INFO, "\n------------------------------------BusX+1 D6F0  TBD:\n"));
		for(tx=0;tx <= 0x2FF; tx+=4){
			if((tx & 0x0F) == 0x00){
				PEI_DEBUG((PeiServices, EFI_D_INFO, "\nRx%03x:",tx));	
			}
			Temp32x = AsiaPcieRead32((UINT64)PCI_BASE, AsiaPciAddress(2, 6, 0, tx));

			PEI_DEBUG((PeiServices, EFI_D_INFO, "%08X  ",Temp32x));		
		}
		//Assign more bus number  -- Behind BusX+1 D6F0
		Temp32x = AsiaPcieRead32((UINT64)PCI_BASE, AsiaPciAddress(2, 6, 0, 0x18));
		PEI_DEBUG((PeiServices, EFI_D_ERROR, "Original [2,6,0]Rx18:%08X  \n",Temp32x));


		
		//BusX+1 D7F0		
		PEI_DEBUG((PeiServices, EFI_D_INFO, "\n------------------------------------BusX+1 D7F0:\n"));
		for(tx=0;tx <= 0x2FF; tx+=4){
			if((tx & 0x0F) == 0x00){
				PEI_DEBUG((PeiServices, EFI_D_INFO, "\nRx%03x:",tx));	
			}
			Temp32x = AsiaPcieRead32((UINT64)PCI_BASE, AsiaPciAddress(2, 7, 0, tx));

			PEI_DEBUG((PeiServices, EFI_D_INFO, "%08X  ",Temp32x));		
		}
		//Assign more bus number  -- Behind BusX+1 D7F0
		Temp32x = AsiaPcieRead32((UINT64)PCI_BASE, AsiaPciAddress(2, 7, 0, 0x18));
		PEI_DEBUG((PeiServices, EFI_D_ERROR, "Original [3,0,0]Rx18:%08X  \n",Temp32x));


		//For attribute test
		//AttrexCheck1(PeiServices,2,7,0);
		
//4 [2.5] Dump BusX+1 D8F0	 & Setting  Bus Number	
#if 1		
		PEI_DEBUG((PeiServices, EFI_D_INFO, "\n------------------------------------BusX+1 D8F0:\n"));
		for(tx=0;tx <= 0x1FF; tx+=4){
			if((tx & 0x0F) == 0x00){
				PEI_DEBUG((PeiServices, EFI_D_INFO, "\nRx%03x:",tx));	
			}
			Temp32x = AsiaPcieRead32((UINT64)PCI_BASE, AsiaPciAddress(2, 8, 0, tx));

			PEI_DEBUG((PeiServices, EFI_D_INFO, "%08X  ",Temp32x));		
		}

		//setting bus number
		Temp32x = AsiaPcieRead32((UINT64)PCI_BASE, AsiaPciAddress(2, 8, 0, 0x18));
		PEI_DEBUG((PeiServices, EFI_D_ERROR, "Original [2,8,0]Rx18:%08X  \n",Temp32x));
		AsiaPciWrite8(AsiaPciAddress(2, 8, 0, 0x18), 0x02);
		AsiaPciWrite8(AsiaPciAddress(2, 8, 0, 0x19), 0x03);
		AsiaPciWrite8(AsiaPciAddress(2, 8, 0, 0x1A), 0x04);		
#endif

#if 1
//4 [2.6] Dump PCIEIF & Setting Bus Number
		PEI_DEBUG((PeiServices, EFI_D_INFO, "\n------------------------------------BusX+2 D0F0 PCIEIF:\n"));
		for(tx=0;tx <= 0x2FF; tx+=4){
			if((tx & 0x0F) == 0x00){
				PEI_DEBUG((PeiServices, EFI_D_INFO, "\nRx%03x:",tx));	
			}
			Temp32x = AsiaPcieRead32((UINT64)PCI_BASE, AsiaPciAddress(3, 0, 0, tx));

			PEI_DEBUG((PeiServices, EFI_D_INFO, "%08X  ",Temp32x));		
		}

		//setting bus number
		Temp32x = AsiaPcieRead32((UINT64)PCI_BASE, AsiaPciAddress(3, 0, 0, 0x18));
		PEI_DEBUG((PeiServices, EFI_D_ERROR, "Original [3,0,0]Rx18:%08X  \n",Temp32x));
		AsiaPciWrite8(AsiaPciAddress(3, 0, 0, 0x18), 0x03);
		AsiaPciWrite8(AsiaPciAddress(3, 0, 0, 0x19), 0x04);
		AsiaPciWrite8(AsiaPciAddress(3, 0, 0, 0x1A), 0x04);
		
#endif


//4 [2.7] Dump ISB: 
#if 1
//4 [2.7.1] Dump EPTRFC
		PEI_DEBUG((PeiServices, EFI_D_INFO, "\n------------------------------------BusX+3 D0F0 EPTRFC:\n"));
		for(tx=0;tx <= 0x1FF; tx+=4){
			if((tx & 0x0F) == 0x00){
				PEI_DEBUG((PeiServices, EFI_D_INFO, "\nRx%03x:",tx));	
			}
			Temp32x = AsiaPcieRead32((UINT64)PCI_BASE, AsiaPciAddress(xBUS_ISB, xDEV_ISB_EPTRFC, xFUNC_ISB_EPTRFC, tx));

			PEI_DEBUG((PeiServices, EFI_D_INFO, "%08X  ",Temp32x));		
		}
#endif 



#if 1
//4 [2.7.2] Dump SATA Controll
		PEI_DEBUG((PeiServices, EFI_D_INFO, "\n------------------------------------BusX+3 D15F0 SATA:\n"));
		for(tx=0;tx <= 0xFF; tx+=4){
			if((tx & 0x0F) == 0x00){
				PEI_DEBUG((PeiServices, EFI_D_INFO, "\nRx%03x:",tx));	
			}
			Temp32x = AsiaPcieRead32((UINT64)PCI_BASE, AsiaPciAddress(xBUS_ISB, xDEV_ISB_SATA, xFUNC_ISB_SATA, tx));

			PEI_DEBUG((PeiServices, EFI_D_INFO, "%08X  ",Temp32x));		
		}
#endif






		PEI_DEBUG((PeiServices, EFI_D_INFO, "\n\n\n"));
		///////////////////////////////////////////////////////////////////////////////
		//Clear those setting
#if 1
		AsiaPciWrite8(AsiaPciAddress(3, 0, 0, 0x18), 0x03);
		AsiaPciWrite8(AsiaPciAddress(3, 0, 0, 0x19), 0x04);
		AsiaPciWrite8(AsiaPciAddress(3, 0, 0, 0x1A), 0x04);
#endif

#if 1
		AsiaPciWrite8(AsiaPciAddress(2, 8, 0, 0x18), 0x02);
		AsiaPciWrite8(AsiaPciAddress(2, 8, 0, 0x19), 0x03);
		AsiaPciWrite8(AsiaPciAddress(2, 8, 0, 0x1A), 0x04);
#endif

		AsiaPciWrite8(AsiaPciAddress(2, 7, 0, 0x18), 0x00);
		AsiaPciWrite8(AsiaPciAddress(2, 7, 0, 0x19), 0x00);
		AsiaPciWrite8(AsiaPciAddress(2, 7, 0, 0x1A), 0x00);

		AsiaPciWrite8(AsiaPciAddress(2, 6, 0, 0x18), 0x00);
		AsiaPciWrite8(AsiaPciAddress(2, 6, 0, 0x19), 0x00);
		AsiaPciWrite8(AsiaPciAddress(2, 6, 0, 0x1A), 0x00);		

		//enable bridge's Mem space - command register
		AsiaPciWrite8(AsiaPciAddress(1, 0, 0, 0x04), 0x0);	
		AsiaPciWrite8(AsiaPciAddress(xBus, xDev, xFunc, 0x04), 0x0); //D7F0 Memory Space enable
	
		//address assign for device Bar
		AsiaPciWrite8(AsiaPciAddress(1, 0, 0, 0x13), 0x0);
		AsiaPciWrite8(AsiaPciAddress(1, 0, 0, 0x12), 0x0);
		AsiaPciWrite8(AsiaPciAddress(1, 0, 0, 0x11), 0x0);

		//Clear bus number
		AsiaPciWrite8(AsiaPciAddress(1, 0, 0, 0x18), 0x01);
		AsiaPciWrite8(AsiaPciAddress(1, 0, 0, 0x19), 0x02);
		AsiaPciWrite8(AsiaPciAddress(1, 0, 0, 0x1A), 0x04);
		
		//Base/Limit setting   FE020000-FE03FFFF
		AsiaPciWrite16(AsiaPciAddress(xBus, xDev, xFunc, 0x20), 0x0);
		AsiaPciWrite16(AsiaPciAddress(xBus, xDev, xFunc, 0x22), 0x0);
		
		//Bus Assign	
		AsiaPciWrite8(AsiaPciAddress(xBus, xDev, xFunc, 0x18), 0x00);
		AsiaPciWrite8(AsiaPciAddress(xBus, xDev, xFunc, 0x19), 0x00);
		AsiaPciWrite8(AsiaPciAddress(xBus, xDev, xFunc, 0x1A), 0x00); 


	}	



	PEI_DEBUG((PeiServices, EFI_D_ERROR, "[CJW_IOE] Out IoePciePtnVerify() -->\n"));
#endif






}



/*
This routine only written for debug/Verification
*/
VOID
DebugAttrexCheck1(
	IN EFI_PEI_SERVICES **PeiServices,
	IN UINT8 BusNum,
	IN UINT8 DevNum,
	IN UINT8 Func
)
{
	UINT8 Temp8x;


		//For attribute test
		Temp8x = AsiaPcieRead8((UINT64)PCI_BASE, AsiaPciAddress(BusNum,DevNum,Func,0xE4)); //read orignal value
		PEI_DEBUG((PeiServices, EFI_D_INFO, "\n[CJW_IOE]    (%d|%d|%d) : read RxE4 = \n",Temp8x,BusNum,DevNum,Func));
		AsiaPcieWrite8((UINT64)PCI_BASE, AsiaPciAddress(BusNum,DevNum,Func,0xE4), 0xA5);  //first write 
		PEI_DEBUG((PeiServices, EFI_D_INFO, "[CJW_IOE]    (%d|%d|%d) : write RxE4 = 0xA5\n",Temp8x,BusNum,DevNum,Func));
		Temp8x = AsiaPcieRead8((UINT64)PCI_BASE, AsiaPciAddress(BusNum,DevNum,Func,0xE4));  //then read 
		PEI_DEBUG((PeiServices, EFI_D_INFO, "[CJW_IOE]    (%d|%d|%d) : read RxE4 = \n",Temp8x,BusNum,DevNum,Func));
		AsiaPcieWrite8((UINT64)PCI_BASE, AsiaPciAddress(BusNum,DevNum,Func,0xE4), 0x5A);  //second write
		PEI_DEBUG((PeiServices, EFI_D_INFO, "[CJW_IOE]    (%d|%d|%d) : write RxE4 = 0x5A\n",Temp8x,BusNum,DevNum,Func));
		Temp8x = AsiaPcieRead8((UINT64)PCI_BASE, AsiaPciAddress(BusNum,DevNum,Func,0xE4)); //then read
		PEI_DEBUG((PeiServices, EFI_D_INFO, "[CJW_IOE]    (%d|%d|%d) : read RxE4 = \n",Temp8x,BusNum,DevNum,Func));
		//For RxE5
		Temp8x = AsiaPcieRead8((UINT64)PCI_BASE, AsiaPciAddress(BusNum,DevNum,Func,0xE5)); //read orignal value
		PEI_DEBUG((PeiServices, EFI_D_INFO, "\n[CJW_IOE]    (%d|%d|%d) : read RxE5 = \n",Temp8x,BusNum,DevNum,Func));
		AsiaPcieWrite8((UINT64)PCI_BASE, AsiaPciAddress(BusNum,DevNum,Func,0xE5), 0xA5);  //first write 
		PEI_DEBUG((PeiServices, EFI_D_INFO, "[CJW_IOE]    (%d|%d|%d) : write RxE5 = 0xA5\n",Temp8x,BusNum,DevNum,Func));
		Temp8x = AsiaPcieRead8((UINT64)PCI_BASE, AsiaPciAddress(BusNum,DevNum,Func,0xE5));  //then read 
		PEI_DEBUG((PeiServices, EFI_D_INFO, "[CJW_IOE]    (%d|%d|%d) : read RxE5 = \n",Temp8x,BusNum,DevNum,Func));
		AsiaPcieWrite8((UINT64)PCI_BASE, AsiaPciAddress(BusNum,DevNum,Func,0xE5), 0x5A);  //second write
		PEI_DEBUG((PeiServices, EFI_D_INFO, "[CJW_IOE]    (%d|%d|%d) : write RxE5 = 0x5A\n",Temp8x,BusNum,DevNum,Func));
		Temp8x = AsiaPcieRead8((UINT64)PCI_BASE, AsiaPciAddress(BusNum,DevNum,Func,0xE5)); //then read
		PEI_DEBUG((PeiServices, EFI_D_INFO, "[CJW_IOE]    (%d|%d|%d) : read RxE5 = \n",Temp8x,BusNum,DevNum,Func));
		//For RxE6
		Temp8x = AsiaPcieRead8((UINT64)PCI_BASE, AsiaPciAddress(BusNum,DevNum,Func,0xE6)); //read orignal value
		PEI_DEBUG((PeiServices, EFI_D_INFO, "\n[CJW_IOE]    (%d|%d|%d) : read RxE6 = \n",Temp8x,BusNum,DevNum,Func));
		AsiaPcieWrite8((UINT64)PCI_BASE, AsiaPciAddress(BusNum,DevNum,Func,0xE6), 0xA5);  //first write 
		PEI_DEBUG((PeiServices, EFI_D_INFO, "[CJW_IOE]    (%d|%d|%d) : write RxE6 = 0xA5\n",Temp8x,BusNum,DevNum,Func));
		Temp8x = AsiaPcieRead8((UINT64)PCI_BASE, AsiaPciAddress(BusNum,DevNum,Func,0xE6));  //then read 
		PEI_DEBUG((PeiServices, EFI_D_INFO, "[CJW_IOE]    (%d|%d|%d) : read RxE6 = \n",Temp8x,BusNum,DevNum,Func));
		AsiaPcieWrite8((UINT64)PCI_BASE, AsiaPciAddress(BusNum,DevNum,Func,0xE6), 0x5A);  //second write
		PEI_DEBUG((PeiServices, EFI_D_INFO, "[CJW_IOE]    (%d|%d|%d) : write RxE6 = 0x5A\n",Temp8x,BusNum,DevNum,Func));
		Temp8x = AsiaPcieRead8((UINT64)PCI_BASE, AsiaPciAddress(BusNum,DevNum,Func,0xE6)); //then read
		PEI_DEBUG((PeiServices, EFI_D_INFO, "[CJW_IOE]    (%d|%d|%d) : read RxE6 = \n",Temp8x,BusNum,DevNum,Func));
		//For RxE7
		Temp8x = AsiaPcieRead8((UINT64)PCI_BASE, AsiaPciAddress(BusNum,DevNum,Func,0xE7)); //read orignal value
		PEI_DEBUG((PeiServices, EFI_D_INFO, "\n[CJW_IOE]    (%d|%d|%d) : read RxE7 = \n",Temp8x,BusNum,DevNum,Func));
		AsiaPcieWrite8((UINT64)PCI_BASE, AsiaPciAddress(BusNum,DevNum,Func,0xE7), 0xA5);  //first write 
		PEI_DEBUG((PeiServices, EFI_D_INFO, "[CJW_IOE]    (%d|%d|%d) : write RxE7 = 0xA5\n",Temp8x,BusNum,DevNum,Func));
		Temp8x = AsiaPcieRead8((UINT64)PCI_BASE, AsiaPciAddress(BusNum,DevNum,Func,0xE7));  //then read 
		PEI_DEBUG((PeiServices, EFI_D_INFO, "[CJW_IOE]    (%d|%d|%d) : read RxE7 = \n",Temp8x,BusNum,DevNum,Func));
		AsiaPcieWrite8((UINT64)PCI_BASE, AsiaPciAddress(BusNum,DevNum,Func,0xE7), 0x5A);  //second write
		PEI_DEBUG((PeiServices, EFI_D_INFO, "[CJW_IOE]    (%d|%d|%d) : write RxE7 = 0x5A\n",Temp8x,BusNum,DevNum,Func));
		Temp8x = AsiaPcieRead8((UINT64)PCI_BASE, AsiaPciAddress(BusNum,DevNum,Func,0xE7)); //then read
	
	

}






/**
   DebugDumpCfgSpace.
   
  @param  PeiServices	EFI_PEI_SERVICES pointer.

  @return VOID.

**/


VOID
DebugDumpCfgSpace(
	IN EFI_PEI_SERVICES **PeiServices)
{
 	UINT16 tx;
	UINT32 Temp32x;
	
	PEI_DEBUG((PeiServices, EFI_D_INFO, "\n------------------------------------Bus1 D0F0 PEEP:\n"));
	for(tx=0;tx <= 0x1FF; tx+=4){
		if((tx & 0x0F) == 0x00){
			PEI_DEBUG((PeiServices, EFI_D_INFO, "\nRx%03x:",tx));	
		}
		Temp32x = AsiaPcieRead32((UINT64)PCI_BASE, AsiaPciAddress(1, 0, 0, tx));

		PEI_DEBUG((PeiServices, EFI_D_INFO, "%08X  ",Temp32x));		
	}


	PEI_DEBUG((PeiServices, EFI_D_INFO, "\n------------------------------------Bus2 D8F0 PESB:\n"));
	for(tx=0;tx <= 0x1FF; tx+=4){
		if((tx & 0x0F) == 0x00){
			PEI_DEBUG((PeiServices, EFI_D_INFO, "\nRx%03x:",tx));	
		}
		Temp32x = AsiaPcieRead32((UINT64)PCI_BASE, AsiaPciAddress(2, 8, 0, tx));

		PEI_DEBUG((PeiServices, EFI_D_INFO, "%08X  ",Temp32x));		
	}

	PEI_DEBUG((PeiServices, EFI_D_INFO, "\n------------------------------------Bus3 D0F0 PCIEIF:\n"));
	for(tx=0;tx <= 0x1FF; tx+=4){
		if((tx & 0x0F) == 0x00){
			PEI_DEBUG((PeiServices, EFI_D_INFO, "\nRx%03x:",tx));	
		}
		Temp32x = AsiaPcieRead32((UINT64)PCI_BASE, AsiaPciAddress(3, 0, 0, tx));

		PEI_DEBUG((PeiServices, EFI_D_INFO, "%08X  ",Temp32x));		
	}


	PEI_DEBUG((PeiServices, EFI_D_INFO, "\n------------------------------------Bus4 D0F0 EPTRFC:\n"));
	for(tx=0;tx <= 0x1FF; tx+=4){
		if((tx & 0x0F) == 0x00){
			PEI_DEBUG((PeiServices, EFI_D_INFO, "\nRx%03x:",tx));	
		}
		Temp32x = AsiaPcieRead32((UINT64)PCI_BASE, AsiaPciAddress(4, 0, 0, tx));

		PEI_DEBUG((PeiServices, EFI_D_INFO, "%08X  ",Temp32x));		
	}


	PEI_DEBUG((PeiServices, EFI_D_INFO, "\n------------------------------------Bus4 D13F0 GNIC:\n"));
	for(tx=0;tx <= 0x1FF; tx+=4){
		if((tx & 0x0F) == 0x00){
			PEI_DEBUG((PeiServices, EFI_D_INFO, "\nRx%03x:",tx));	
		}
		Temp32x = AsiaPcieRead32((UINT64)PCI_BASE, AsiaPciAddress(4, 13, 0, tx));

		PEI_DEBUG((PeiServices, EFI_D_INFO, "%08X  ",Temp32x));		
	}

	PEI_DEBUG((PeiServices, EFI_D_INFO, "\n------------------------------------Bus4 D15F0 SATA:\n"));
	for(tx=0;tx <= 0x1FF; tx+=4){
		if((tx & 0x0F) == 0x00){
			PEI_DEBUG((PeiServices, EFI_D_INFO, "\nRx%03x:",tx));	
		}
		Temp32x = AsiaPcieRead32((UINT64)PCI_BASE, AsiaPciAddress(4, 15, 0, tx));

		PEI_DEBUG((PeiServices, EFI_D_INFO, "%08X  ",Temp32x));		
	}

	PEI_DEBUG((PeiServices, EFI_D_INFO, "\n------------------------------------Bus4 D16F0 UHCI:\n"));
	for(tx=0;tx <= 0x1FF; tx+=4){
		if((tx & 0x0F) == 0x00){
			PEI_DEBUG((PeiServices, EFI_D_INFO, "\nRx%03x:",tx));	
		}
		Temp32x = AsiaPcieRead32((UINT64)PCI_BASE, AsiaPciAddress(4, 16, 0, tx));

		PEI_DEBUG((PeiServices, EFI_D_INFO, "%08X  ",Temp32x));		
	}

	PEI_DEBUG((PeiServices, EFI_D_INFO, "\n------------------------------------Bus4 D16F7 EHCI:\n"));
	for(tx=0;tx <= 0x1FF; tx+=4){
		if((tx & 0x0F) == 0x00){
			PEI_DEBUG((PeiServices, EFI_D_INFO, "\nRx%03x:",tx));	
		}
		Temp32x = AsiaPcieRead32((UINT64)PCI_BASE, AsiaPciAddress(4, 16, 7, tx));

		PEI_DEBUG((PeiServices, EFI_D_INFO, "%08X  ",Temp32x));		
	}
	
	PEI_DEBUG((PeiServices, EFI_D_INFO, "\n------------------------------------Bus4 D18F0 XHCI:\n"));
	for(tx=0;tx <= 0x1FF; tx+=4){
		if((tx & 0x0F) == 0x00){
			PEI_DEBUG((PeiServices, EFI_D_INFO, "\nRx%03x:",tx));	
		}
		Temp32x = AsiaPcieRead32((UINT64)PCI_BASE, AsiaPciAddress(4, 18, 0, tx));

		PEI_DEBUG((PeiServices, EFI_D_INFO, "%08X  ",Temp32x));		
	}
		

}


/**
    This function is just for test GPIO/GPO	   

  @param  PeiServices	EFI_PEI_SERVICES pointer.

  @return EFI_STATUS.

**/

EFI_STATUS
DebugIoeGpioTest(IN EFI_PEI_SERVICES  **PeiServices)
{
	EFI_STATUS Statusx;
	UINT32 MmioBar;
	
	Statusx = IoePeiTempAssignment(PeiServices);
	if(Statusx == EFI_SUCCESS){
		MmioBar = AsiaPciRead32(AsiaPciAddress(BUSX, UPPORT_DEV, DNPORT_FUN, 0x10));

		PEI_DEBUG((PeiServices, EFI_D_ERROR, "[CJW_IOE] IoeGpioTest() Found IOE! - MMIO_ISB BAR = %08x\n",MmioBar));

		// Disable Debugsignal Output Function
		AsiaMemoryModify16(MmioBar + MMIO_ISB_OFFSET + 0x10, BIT4, 0);  //GPIO related IO use as debugsignal - disable
		AsiaMemoryModify16(MmioBar + MMIO_ISB_OFFSET + 0x7C, BIT9, 0);
		AsiaMemoryModify16(MmioBar + MMIO_ISB_OFFSET + 0x7C, BIT8, 0);
		AsiaMemoryModify16(MmioBar + MMIO_ISB_OFFSET + 0x7C, BIT11, 0);
		
		//
		// set those GPIO/GPO pinmux
		//
		// 1.GPO
		AsiaMemoryModify16(MmioBar + MMIO_ISB_OFFSET + 0xE, BIT1|BIT0, 0);  	//GPO0
		AsiaMemoryModify16(MmioBar + MMIO_ISB_OFFSET + 0xE, BIT2, 0); 			//GPO1	
		AsiaMemoryModify16(MmioBar + MMIO_ISB_OFFSET + 0xE, BIT4, 0);			//GPO2
		AsiaMemoryModify16(MmioBar + MMIO_ISB_OFFSET + 0xE, BIT7|BIT6, 0);		//GPO3
		AsiaMemoryModify16(MmioBar + MMIO_ISB_OFFSET + 0xE, BIT9|BIT8, 0); 		//GPO4 
		AsiaMemoryModify16(MmioBar + MMIO_ISB_OFFSET + 0xE, BIT11|BIT10, 0);    //GPO5
		// 2.GPIO 0-9
		AsiaMemoryModify16(MmioBar + MMIO_ISB_OFFSET + 0xC, BIT1|BIT0, 0);  	//GPIO0
		AsiaMemoryModify16(MmioBar + MMIO_ISB_OFFSET + 0xC, BIT3|BIT2, 0);  	//GPIO1
		AsiaMemoryModify16(MmioBar + MMIO_ISB_OFFSET + 0xC, BIT5|BIT4, 0);  	//GPIO2
		AsiaMemoryModify16(MmioBar + MMIO_ISB_OFFSET + 0xC, BIT7|BIT6, 0);  	//GPIO3
		AsiaMemoryModify16(MmioBar + MMIO_ISB_OFFSET + 0xC, BIT9|BIT8, 0);  	//GPIO4
		AsiaMemoryModify16(MmioBar + MMIO_ISB_OFFSET + 0xC, BIT11|BIT10, 0);  	//GPIO5
		AsiaMemoryModify16(MmioBar + MMIO_ISB_OFFSET + 0xC, BIT13|BIT12, 0);  	//GPIO6
		AsiaMemoryModify16(MmioBar + MMIO_ISB_OFFSET + 0xC, BIT15|BIT14, 0);  	//GPIO7
		AsiaMemoryModify16(MmioBar + MMIO_ISB_OFFSET + 0xE, BIT13|BIT12, 0);  	//GPIO8
		AsiaMemoryModify16(MmioBar + MMIO_ISB_OFFSET + 0xE, BIT14, 0);  		//GPIO9

		// 3.CCBMCGPIO --> GPIO
		AsiaMemoryModify16(MmioBar + MMIO_ISB_OFFSET + 0x7A, BIT15|BIT14, BIT14);  		//CCBMCGPIO-0
		AsiaMemoryModify16(MmioBar + MMIO_ISB_OFFSET + 0x7A, BIT13|BIT12, BIT12);  		//CCBMCGPIO-1
		AsiaMemoryModify16(MmioBar + MMIO_ISB_OFFSET + 0x7A, BIT7|BIT6, BIT6);  		//CCBMCGPIO-2
		AsiaMemoryModify16(MmioBar + MMIO_ISB_OFFSET + 0x7A, BIT5|BIT4, BIT4);  		//CCBMCGPIO-3
		AsiaMemoryModify16(MmioBar + MMIO_ISB_OFFSET + 0x7A, BIT3|BIT2, BIT2);  		//CCBMCGPIO-4
		AsiaMemoryModify16(MmioBar + MMIO_ISB_OFFSET + 0x7A, BIT1|BIT0, BIT0);  		//CCBMCGPIO-5
		AsiaMemoryModify16(MmioBar + MMIO_ISB_OFFSET + 0x7C, BIT1, BIT1);  				//CCBMCGPIO-6
		AsiaMemoryModify16(MmioBar + MMIO_ISB_OFFSET + 0x7C, BIT0, BIT0);  				//CCBMCGPIO-

		// 4.other GPIOs 
		AsiaMemoryModify16(MmioBar + MMIO_ISB_OFFSET + 0x78, BIT1, 0);  	//GPIO13
		AsiaMemoryModify16(MmioBar + MMIO_ISB_OFFSET + 0x78, BIT2, 0);  	//GPIO14
		AsiaMemoryModify16(MmioBar + MMIO_ISB_OFFSET + 0x78, BIT9, 0);  	//GPIO21
		AsiaMemoryModify16(MmioBar + MMIO_ISB_OFFSET + 0x78, BIT10, 0);  	//GPIO22
		

		IoePeiClearTempAssignment(PeiServices);
	}else{
		PEI_DEBUG((PeiServices, EFI_D_ERROR, "[CJW_IOE] IoeGpioTest() Not Found IOE!\n"));
	}

	return Statusx;


}









/**************************************************************************
// Library support for Multi-IOE / BIOS mode  
**************************************************************************/
#if MULTI_IOE_SUPPORT
ORDER_D FlagBitRelationship[]= IOE_ORDER_TABLE;   



/**
   IoeGetPortFlagBit.
   
  @param  PeiServices	EFI_PEI_SERVICES pointer.
  @param Bus
  @param Dev
  @param Fun

  @return UINT8.

**/

STATIC UINT8 
IoeGetPortFlagBit(
	IN EFI_PEI_SERVICES **PeiServices,
	UINT8 Bus, 
	UINT8 Dev, 
	UINT8 Fun)
{
	UINT8 ix;
	for(ix = 0; ix < (sizeof(FlagBitRelationship)/sizeof(ORDER_D)); ix++){
		if((FlagBitRelationship[ix].BusNum == Bus)
			&&(FlagBitRelationship[ix].DevNum == Dev)
			&&(FlagBitRelationship[ix].FunNum == Fun)){
			return ix;  //return the index in this table
		}
	}
	
	PEI_DEBUG((PeiServices, EFI_D_ERROR, "[CJW_IOE] ERROR!!! - Not found the corresponing flag bit in scratch register! \n"  ));
	return 0xFF; //not found
}

/**
   IoeIsUsablePort.
   
  @param  PeiServices	EFI_PEI_SERVICES pointer.
  @param Bus
  @param Dev
  @param Fun

  @return boolean.

**/

STATIC BOOLEAN
IoeIsUsablePort(
	IN EFI_PEI_SERVICES **PeiServices,
	UINT8 Bus, UINT8 Dev, UINT8 Fun)
{
	UINT8 Var1,Var0;
	UINT16 VarMask16 = 0;
	UINT8 temp;

	Var0 = AsiaPciRead8(AsiaPciAddress(SCRATCH_BUS,SCRATCH_DEV,SCRATCH_FUN,VAR_BYTE0_REG));
	Var1 = AsiaPciRead8(AsiaPciAddress(SCRATCH_BUS,SCRATCH_DEV,SCRATCH_FUN,VAR_BYTE1_REG));	
	VarMask16 = Var1;
	VarMask16 = (VarMask16<<8)|(Var0&0xFF);
	
	temp = IoeGetPortFlagBit(PeiServices,Bus,Dev,Fun);
	if(VarMask16 & (1<<temp)){
		return FALSE;
	}else{
		return TRUE;
	}
	
}

/**
   IoeMaskSearchPort.
   
  @param  PeiServices	EFI_PEI_SERVICES pointer.

  @return VOID.

**/

STATIC VOID
IoeMaskSearchPort(
	IN EFI_PEI_SERVICES **PeiServices,
	UINT8 Bus, 
	UINT8 Dev, 
	UINT8 Fun)
{
	UINT8 Var1,Var0;
	UINT8 temp;

	temp = IoeGetPortFlagBit(PeiServices,Bus,Dev,Fun);

	if((temp<8)&&(temp>=0)){
		Var0 = AsiaPciRead8(AsiaPciAddress(SCRATCH_BUS,SCRATCH_DEV,SCRATCH_FUN,VAR_BYTE0_REG));
		Var0 = Var0|(1<<temp);
		AsiaPciWrite8(AsiaPciAddress(SCRATCH_BUS,SCRATCH_DEV,SCRATCH_FUN,VAR_BYTE0_REG),Var0);
	}
	if((temp>=8)&&(temp<16)){  
		Var1 = AsiaPciRead8(AsiaPciAddress(SCRATCH_BUS,SCRATCH_DEV,SCRATCH_FUN,VAR_BYTE1_REG));
		Var1 = Var1|(1<<(temp-8));
		AsiaPciWrite8(AsiaPciAddress(SCRATCH_BUS,SCRATCH_DEV,SCRATCH_FUN,VAR_BYTE0_REG),Var1);			
	}	

}

/**
   IoeUnmaskSearchPort.
   
  @param  PeiServices	EFI_PEI_SERVICES pointer.

  @return VOID.

**/

STATIC VOID
IoeUnmaskSearchPort(
	IN EFI_PEI_SERVICES **PeiServices,
	UINT8 Bus, 
	UINT8 Dev, 
	UINT8 Fun)
{
	UINT8 Var1,Var0;
	UINT8 temp;

	temp = IoeGetPortFlagBit(PeiServices,Bus,Dev,Fun);

	if((temp<8)&&(temp>=0)){
		Var0 = AsiaPciRead8(AsiaPciAddress(SCRATCH_BUS,SCRATCH_DEV,SCRATCH_FUN,VAR_BYTE0_REG));
		Var0 = Var0&(~(1<<temp));
		AsiaPciWrite8(AsiaPciAddress(SCRATCH_BUS,SCRATCH_DEV,SCRATCH_FUN,VAR_BYTE0_REG),Var0);
	}
	if((temp>=8)&&(temp<16)){  
		Var1 = AsiaPciRead8(AsiaPciAddress(SCRATCH_BUS,SCRATCH_DEV,SCRATCH_FUN,VAR_BYTE1_REG));
		Var1 = Var1&(~(1<<(temp-8)));
		AsiaPciWrite8(AsiaPciAddress(SCRATCH_BUS,SCRATCH_DEV,SCRATCH_FUN,VAR_BYTE0_REG),Var1);			
	}

}

/**
   IoeUnmaskAllPort.
   
  @param  VOID


  @return VOID.

**/

VOID 
IoeUnmaskAllPort(VOID)
{
	AsiaPciWrite8(AsiaPciAddress(SCRATCH_BUS,SCRATCH_DEV,SCRATCH_FUN,VAR_BYTE0_REG),0);
	AsiaPciWrite8(AsiaPciAddress(SCRATCH_BUS,SCRATCH_DEV,SCRATCH_FUN,VAR_BYTE1_REG),0);
}


/**
   IoeMaskInitializedPort.
   
  @param  PeiServices	EFI_PEI_SERVICES pointer.

  @return EFI_STATUS.

**/

EFI_STATUS
IoeMaskInitializedPort(
	IN EFI_PEI_SERVICES **PeiServices)
{
	EFI_STATUS Status = EFI_SUCCESS;
	UINT8 ts;
	for(ts = 0; ts < (sizeof(IoeSearchTbl)/sizeof(SEARCH_TBL)); ts++){	
		Status = IoeSearchPcieRpTemporary(PeiServices,IoeSearchTbl[ts].BusNum,IoeSearchTbl[ts].DevNum,IoeSearchTbl[ts].FunNum);
		if(Status == EFI_SUCCESS){
			if(!IoeIsUsablePort(PeiServices,IoeSearchTbl[ts].BusNum,IoeSearchTbl[ts].DevNum,IoeSearchTbl[ts].FunNum)){
				Status = EFI_NOT_FOUND;
				continue;
			}
			IoeMaskSearchPort(PeiServices,IoeSearchTbl[ts].BusNum,IoeSearchTbl[ts].DevNum,IoeSearchTbl[ts].FunNum);
			break;
		}
	}


	return Status;
}

#endif

