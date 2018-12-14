//**********************************************************************
//**********************************************************************
//**                                                                  **
//**     Copyright (c) 2018 Shanghai Zhaoxin Semiconductor Co., Ltd.  **
//**                                                                  **
//**********************************************************************
//**********************************************************************

/* 

Legacy Bus SI related setting

*/
#include "AsiaIoLib.h"
#include "CHX002Reg.h"


ASIA_IO_TABLE_6408_REV	eSPI_SI_TBL[]=
{
	
	{0x00,	0xFF,	(CHX002_ESPI|D11F0_ESPI_INPUT_DATA_SAMPLE_CLK_SEL),	D11F0_ESPICLK_DELAY_SEL, 0x0C} // D11F0 Rx43[3:0], eSPI: Suggest modifying the Rx clock delay phase to Ch at eSPI 50MHz/66MHz mode.

};
UINTN eSPI_SI_TBL_Items = sizeof(eSPI_SI_TBL)/sizeof(ASIA_IO_TABLE_6408_REV);

// Update eSPI SI setting.
EFI_STATUS
UpdateEspiSI(VOID)
{
    UINTN Index;
    ASIA_IO_TABLE_6408_REV  *pItem;

    for (Index = 0; Index < eSPI_SI_TBL_Items; Index++) {
      pItem = &eSPI_SI_TBL[Index];  
      AsiaPciModify8(pItem->Address, pItem->Mask, pItem->Value);
    }

    return EFI_SUCCESS;
}

// Update SPI SI setting.
EFI_STATUS
UpdateSpiSI(VOID)
{
  UINT16 PmioBar;
  UINT32 Group15Index = 0x8000;
  UINT32 Data32;
  
	PmioBar = AsiaPciRead16(CHX002_BUSC | D17F0_PMU_PM_IO_BASE);
	PmioBar &= D17F0_PMU_PMIOBA;
	
	// Read group15 data.
	AsiaIoModify32(PmioBar + PMIO_PAD_CTL_REG, PMIO_PAD_ADDR, Group15Index); // Set the index data.
	AsiaIoModify32(PmioBar + PMIO_PAD_CTL_REG, PMIO_PAD_WR, 0);  // Write disable
	Data32 = AsiaIoRead32(PmioBar + PMIO_PAD_CTL_REG_READ_DATA); // Read data from PMIO Rx90
	
	// Modify the data.
	Data32 &= (UINT32)~0x3F00; // Clear bit13-bit8
	Data32 |= 0x3600;          // bit13-11: 110b, bit10-08:110b
	
	// Write back to group15.
	AsiaIoModify32(PmioBar + PMIO_PAD_CTL_REG, PMIO_PAD_ADDR, Group15Index);     // Set the index data.
	AsiaIoModify32(PmioBar + PMIO_PAD_CTL_REG_WRITE_DATA, PMIO_PAD_DIN, Data32); // Set the input data.
	AsiaIoModify32(PmioBar + PMIO_PAD_CTL_REG, PMIO_PAD_WR, BIT31);  // Write enable
	AsiaIoModify32(PmioBar + PMIO_PAD_CTL_REG, PMIO_PAD_WR, 0);      // Write disable
 
  return EFI_SUCCESS;
}

// Update legacy SI setting
EFI_STATUS
UpdateLegacySISetting(VOID)
{
  
  UpdateEspiSI();
  
  UpdateSpiSI();
  
  return EFI_SUCCESS;
}