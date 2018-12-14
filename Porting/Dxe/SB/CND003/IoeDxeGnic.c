/** @file
   ZX-E(CHX002) Asia SbDxe library functions : IoeDxeGnic.c

   Copyright (c) 2018 Shanghai Zhaoxin Semiconductor Co., Ltd. 

**/

//**************************************************************************
//**************************************************************************
//**                                                                      **
//**  Copyright (c) 2015 - 2017 Shanghai Zhaoxin Semiconductor Co., Ltd.  **
//**                                                                      **
//**************************************************************************
//**************************************************************************

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


#include "AsiaCommon.h" //define ASIA_XXX_CFG_HOB_GUID

#include "IoeDxeGnic.h"

/**
  Function description.
  
  @param  PeiServices	EFI_PEI_SERVICES pointer.
  @param SbCfg Point to ASIA_SB_CONFIGURATION struct.

  @return EFI_STATUS.

**/

EFI_STATUS
EFIAPI
IOEGnicDxeInit(
ASIA_SB_CONFIGURATION* SbCfg 
)
{
    UINT8 IOEGnicSpe;
	UINT8 Temp8;
	UINT16 Temp16;
	UINT32 Temp32, TempBar;
  	DEBUG((EFI_D_ERROR, "CND003 GNIC DXE Initialize Start\n"));

	if(!IoeExist()){
		DEBUG((EFI_D_ERROR, "[CJW_IOE] SKIP CND003 Init [IOEGnicDxeInit()]\n"));
		return EFI_SUCCESS;
	}	

  	//
	//Enumerate IOE temp
	//
	IoeDxeTempAssignment();

	//Init Beginning
	if(SbCfg->IOEGnicEn){
    	AsiaPciModifySave8((CND003_EPTRFC | CND003_EPTRFC_D0F0_SM_DEV_ENABLE_2), BIT0, BIT0);
		
		switch(SbCfg->IOESPEValue)
		{
			case CHIP_SPE_VALUE_MANUAL:
			  IOEGnicSpe = SbCfg->IOEGNICSPEValue;
			  break;
			case CHIP_SPE_VALUE_STABLE:
			  IOEGnicSpe = DEVICE_SPE_VALUE_STABLE;
			  break;
			case CHIP_SPE_VALUE_PERFORMANCE:
			  IOEGnicSpe = DEVICE_SPE_VALUE_PERFORMANCE;
			  break;
			case CHIP_SPE_VALUE_ENERGY:
			  IOEGnicSpe = DEVICE_SPE_VALUE_ENERGY;
			  break;
			default:
			  IOEGnicSpe = DEVICE_SPE_VALUE_STABLE;
		}
		
	    AsiaPciModifySave8((CND003_GNIC| D13F0_MODE_REG), D13F0_MSI64, D13F0_MSI64);

		TempBar = AsiaPciRead32((CND003_GNIC| D13F0_CSR_MEM_MAPPED_BASE_ADDR_REGS)) & D13F0_MMBLA3;
		DEBUG((EFI_D_ERROR, "[GNIC] TempBar = %x\n", TempBar));

		AsiaMemoryModifySave8( TempBar 
| GNICMMIO_DYNAMIC_CLK_CTL, 0xFF, 0x00);		
		
		switch(SbCfg->IOEGnicTXDCS)
		{
			case 0:
				AsiaMemoryModifySave8( TempBar 
| GNICMMIO_DELAY_COMP_SETLECTION, GNICMMIO_DIOTXSEL, 0x00);
			  break;
			case 1:
				AsiaMemoryModifySave8( TempBar 
| GNICMMIO_DELAY_COMP_SETLECTION, GNICMMIO_DIOTXSEL, 0x40);
			  break;
			case 2:
				AsiaMemoryModifySave8( TempBar 
| GNICMMIO_DELAY_COMP_SETLECTION, GNICMMIO_DIOTXSEL, 0x60);
			  break;
			case 3:
				AsiaMemoryModifySave8( TempBar 
| GNICMMIO_DELAY_COMP_SETLECTION, GNICMMIO_DIOTXSEL, 0x80);
			  break;
			case 4:
				AsiaMemoryModifySave8( TempBar 
| GNICMMIO_DELAY_COMP_SETLECTION, GNICMMIO_DIOTXSEL, 0x10);
			  break;
			case 5:
				AsiaMemoryModifySave8( TempBar 
| GNICMMIO_DELAY_COMP_SETLECTION, GNICMMIO_DIOTXSEL, 0x50);
			  break;
			case 6:
				AsiaMemoryModifySave8( TempBar 
| GNICMMIO_DELAY_COMP_SETLECTION, GNICMMIO_DIOTXSEL, 0x70);
			  break;
			case 7:
				AsiaMemoryModifySave8( TempBar 
| GNICMMIO_DELAY_COMP_SETLECTION, GNICMMIO_DIOTXSEL, 0x90);				
			  break;
			default:
				AsiaMemoryModifySave8( TempBar 
| GNICMMIO_DELAY_COMP_SETLECTION, GNICMMIO_DIOTXSEL, 0x00);
		}		

		Temp32 = (UINT32) (SbCfg->IOEGnicTXDC0 | (SbCfg->IOEGnicTXDC1 << 8) | (SbCfg->IOEGnicTXDC2 << 16));
		AsiaMemoryModifySave32( TempBar 
| GNICMMIO_DELAY_COMP_CNTER_0_3, 0x00FFFFFF, Temp32);

		switch(SbCfg->IOEGnicRXDCS)
		{
			case 0:
				AsiaMemoryModifySave8( TempBar 
| GNICMMIO_DELAY_COMP_SETLECTION, GNICMMIO_DIORXSEL, 0x00);
			  break;
			case 1:
				AsiaMemoryModifySave8( TempBar 
| GNICMMIO_DELAY_COMP_SETLECTION, GNICMMIO_DIORXSEL, 0x04);
			  break;
			case 2:
				AsiaMemoryModifySave8( TempBar 
| GNICMMIO_DELAY_COMP_SETLECTION, GNICMMIO_DIORXSEL, 0x06);
			  break;
			case 3:
				AsiaMemoryModifySave8( TempBar 
| GNICMMIO_DELAY_COMP_SETLECTION, GNICMMIO_DIORXSEL, 0x08);
			  break;
			case 4:
				AsiaMemoryModifySave8( TempBar 
| GNICMMIO_DELAY_COMP_SETLECTION, GNICMMIO_DIORXSEL, 0x01);
			  break;
			case 5:
				AsiaMemoryModifySave8( TempBar 
| GNICMMIO_DELAY_COMP_SETLECTION, GNICMMIO_DIORXSEL, 0x05);
			  break;
			case 6:
				AsiaMemoryModifySave8( TempBar 
| GNICMMIO_DELAY_COMP_SETLECTION, GNICMMIO_DIORXSEL, 0x07);
			  break;
			case 7:
				AsiaMemoryModifySave8( TempBar 
| GNICMMIO_DELAY_COMP_SETLECTION, GNICMMIO_DIORXSEL, 0x09);				
			  break;
			default:
				AsiaMemoryModifySave8( TempBar 
| GNICMMIO_DELAY_COMP_SETLECTION, GNICMMIO_DIORXSEL, 0x00);
		}		

		Temp32 = (UINT32) (SbCfg->IOEGnicRXDC0 | (SbCfg->IOEGnicRXDC1 << 8) | (SbCfg->IOEGnicRXDC2 << 16));
		AsiaMemoryModifySave32( TempBar 
| GNICMMIO_DELAY_COMP_CNTER_4_7, 0x00FFFFFF, Temp32);

		Temp16 = (UINT16) (SbCfg->IOEGnicDPDC256 | (SbCfg->IOEGnicDPDC128 << 4) | (SbCfg->IOEGnicDPDC64 << 8));
		AsiaMemoryModifySave16( TempBar 
| GNICMMIO_DATA_PATH_DELAY_INNER_CTL, 0x0FFF, Temp16);

		if(SbCfg->IOEGnicForceSizeEn) {
			AsiaMemoryModifySave8( TempBar 
| GNICMMIO_MAX_PAYLOAD_SIZE_AND_MAX_RD_REQ_SIZE_INNER_CTL+1, BIT0, BIT0);
			if(SbCfg->IOEGnicForceRDR)
				Temp8 = 0x1;
			else
				Temp8 = 0x0;			
			
			if(SbCfg->IOEGnicForcePayload)
				Temp8 |= 0x1 << 3;

			AsiaMemoryModifySave8( TempBar 
| GNICMMIO_MAX_PAYLOAD_SIZE_AND_MAX_RD_REQ_SIZE_INNER_CTL, 0x3F, Temp8);
		} else 
			AsiaMemoryModifySave8( TempBar 
| GNICMMIO_MAX_PAYLOAD_SIZE_AND_MAX_RD_REQ_SIZE_INNER_CTL+1, BIT0, 0);

		if(SbCfg->IOEGnicEventCtrl)
			AsiaMemoryModifySave8( TempBar 
| GNICMMIO_NEW_FEATURE_OPTION_REG+3, BIT7, BIT7);
		else
			AsiaMemoryModifySave8( TempBar 
| GNICMMIO_NEW_FEATURE_OPTION_REG+3, BIT7, 0);
	
		if(SbCfg->IOEGnicPendingCtrl)
			AsiaMemoryModifySave8( TempBar 
| GNICMMIO_NEW_FEATURE_OPTION_REG+3, BIT6, BIT6);
		else
			AsiaMemoryModifySave8( TempBar 
| GNICMMIO_NEW_FEATURE_OPTION_REG+3, BIT6, 0);

		if(SbCfg->IOEGnicMsiCtrl)
			AsiaPciModifySave8((CND003_GNIC| D13F0_MODE_REG), D13F0_MSIBDIS, 0);
		else
			AsiaPciModifySave8((CND003_GNIC| D13F0_MODE_REG), D13F0_MSIBDIS, D13F0_MSIBDIS);

		if(SbCfg->IOEGnicMsiXCtrl)
			AsiaPciModifySave8((CND003_GNIC| D13F0_MODE_REG), D13F0_MSIXBDIS, 0);
		else
			AsiaPciModifySave8((CND003_GNIC| D13F0_MODE_REG), D13F0_MSIXBDIS, D13F0_MSIXBDIS);

		AsiaMemoryModifySave8( TempBar 
| GNICMMIO_CHIP_OPERATION_AND_DIAGNOSE_REG+2, BIT4, BIT4);
		if(SbCfg->IOEGnicD0PME) {
			AsiaMemoryModifySave8( TempBar 
| GNICMMIO_TX_RX_SRAM_BIST_CTL_AND_STAREG_BCSR+2, 0x1F, 0x1F);	
		} else {
			AsiaMemoryModifySave8( TempBar 
| GNICMMIO_TX_RX_SRAM_BIST_CTL_AND_STAREG_BCSR+2, 0x1F, 0x1E);	
		}
		AsiaMemoryModifySave8( TempBar 
| GNICMMIO_CHIP_OPERATION_AND_DIAGNOSE_REG+2, BIT4, BIT0);

		if(IOEGnicSpe == DEVICE_SPE_VALUE_ENERGY)
			AsiaMemoryModifySave8( TempBar 
| GNICMMIO_DYNAMIC_CLK_CTL, 0xFF, 0xFF);	
		
if(SbCfg->IOEGnicVEEPROM) {
			AsiaMemoryModifySave8( TempBar 
| GNICMMIO_INNER_STRAPPING_OPTIONAL_CFG_CTL, 0x02, 0x02);	
		} else {
			AsiaMemoryModifySave8( TempBar 
| GNICMMIO_INNER_STRAPPING_OPTIONAL_CFG_CTL, 0x02, 0x00);	
			AsiaPciModifySave8((CND003_GNIC| 0x5F), 0x03, 0);
		}
    }else
    	AsiaPciModifySave8((CND003_EPTRFC | CND003_EPTRFC_D0F0_SM_DEV_ENABLE_2), BIT0, 0);

	//
	//Clear bus number assignment
	//
	IoeDxeClearTempAssignment();
	
  	DEBUG((EFI_D_ERROR, "CND003 GNIC Initialize End\n"));
	return EFI_SUCCESS;
}

