//**********************************************************************
//**********************************************************************
//**                                                                  **
//**     Copyright (c) 2018 Shanghai Zhaoxin Semiconductor Co., Ltd.  **
//**                                                                  **
//**********************************************************************
//**********************************************************************

////
////
#include "Pei.h"
#include "Draminit.h"
#include "FinalTableProgramming.h"

VOID DDRIOThermalReading(
	IN EFI_PEI_SERVICES **PeiServices,
#if (PI_SPECIFICATION_VERSION < 0x00010000) 
	IN PEI_PCI_CFG_PPI *pPCIPPI,
#else
	IN EFI_PEI_PCI_CFG2_PPI *pPCIPPI,
#endif
	IN DRAM_ATTRIBUTE *DramAttr)
{

	UINT64 Address;		
	//Set D0F3 RxBD4
	Address = AsiaPciAddress(CHX002_HB_BUS, CHX002_HB_DEV,CHX002_DRAM_FUN, D0F3_TMON_DDR_CTL_REG_PART_3_Z1);
	AsiaPcieModify16(DramAttr->PcieBaseAddress, Address, D0F3_RTM_USE_D3_CAL_Q|D0F3_RTM_DDR_EN,D0F3_RTM_USE_D3_CAL_Q|D0F3_RTM_DDR_EN);

	
	//Set D0F3 RxBDE
	Address = AsiaPciAddress(CHX002_HB_BUS, CHX002_HB_DEV,CHX002_DRAM_FUN, D0F3_TMON_DDR_ANALOG_IP_CTL_REG_PART_2);
	AsiaPcieModify16(DramAttr->PcieBaseAddress, Address, D0F3_TM_CLKSEL_2_0,0x3);


	//Set D0F3 RxBDC
	Address = AsiaPciAddress(CHX002_HB_BUS, CHX002_HB_DEV,CHX002_DRAM_FUN, D0F3_TMON_DDR_TEMPERATURE_THRESHOLD);
	AsiaPcieWrite16(DramAttr->PcieBaseAddress, Address, DramAttr->ConfigData.CriticalDDRIOTemperatureValue);
	//Set D0F3 Rx170

	Address = AsiaPciAddress(CHX002_HB_BUS, CHX002_HB_DEV,CHX002_DRAM_FUN, D0F3_DRAM_BUS_TOGGLE_REDUCTION_CTL_BY_DDR_IO_TEMPERATURE_SENSOR);
	AsiaPcieWrite8(DramAttr->PcieBaseAddress, Address, D0F3_RTHERMALEN|(DramAttr->ConfigData.DramDDRIOReduceRate));


}

VOID ThermalReading(
	IN EFI_PEI_SERVICES **PeiServices,
#if (PI_SPECIFICATION_VERSION < 0x00010000) 
	IN PEI_PCI_CFG_PPI *pPCIPPI,
#else
	IN EFI_PEI_PCI_CFG2_PPI *pPCIPPI,
#endif
	IN PEI_SMBUS_PPI *pSMBusPPI,
	IN DRAM_ATTRIBUTE *DramAttr)
{
	EFI_SMBUS_DEVICE_COMMAND SMBCMD;
	EFI_SMBUS_DEVICE_ADDRESS SlaveAddress;
	ASIA_SPD_DATA     *CurrentSpdData;
	UINTN SMBDataLength=1;
	UINT8 Val8, Index;
	UINT16 Val16;
	UINT16 Val16tmp;
	UINT16 PmioBar;
	EFI_STATUS Status;
	UINT8 Dimm_Thermal_Support;
	UINT64 Address;


	for (Index = 0; Index < ASIA_MAX_DIMMS; Index++) {	
		PEI_DEBUG((PeiServices, EFI_D_INFO, "----------------------------------------------------------------------\n"));
		CurrentSpdData = &(DramAttr->SpdData[DramAttr->AttrNo][Index]);
		if ( CurrentSpdData->SpdPresent ) {
			Val8 = CurrentSpdData->Buffer[DDR4_SPD_THERMAL_SENSOR] & 0x80;
			if(Val8==0xFF)
			{
				Dimm_Thermal_Support = 0;		
				PEI_DEBUG((PeiServices, EFI_D_INFO, "Dimm %d: not support thermal\n", Index+1));
			}
			else
			{
				if(Val8&0x80)
				{
					Dimm_Thermal_Support = 0x01; 	
					PEI_DEBUG((PeiServices, EFI_D_INFO, "Dimm %d: support thermal\n", Index+1));
				}
				else			
				{
					Dimm_Thermal_Support = 0;		
					PEI_DEBUG((PeiServices, EFI_D_INFO, "Dimm %d: not support thermal\n", Index+1));
				}
			}
		}
		else
		{
			Dimm_Thermal_Support = 0;	
			PEI_DEBUG((PeiServices, EFI_D_INFO, "Dimm %d: not present\n", Index+1));
		}

		SlaveAddress.SmbusDeviceAddress = 0x18+Index;//address
		

		//Set critical temperature assert EVENT#
		SMBCMD=0x00;//Offset 00 = Capability register
		Status= pSMBusPPI->Execute(PeiServices, pSMBusPPI, SlaveAddress, SMBCMD, EfiSmbusReadWord, 0, &SMBDataLength, &Val16);
		Val16tmp = ((Val16&0x00FF)<<8) |( (Val16&0xFF00)>>8); //swap upper byte and lower byte

		SMBCMD=0x00;//Offset 00 = Capability register
		Status= pSMBusPPI->Execute(PeiServices, pSMBusPPI, SlaveAddress, SMBCMD, EfiSmbusReadWord, 0, &SMBDataLength, &Val16);
		Val16tmp = ((Val16&0x00FF)<<8) |( (Val16&0xFF00)>>8); //swap upper byte and lower byte
		
		if(Dimm_Thermal_Support && (DramAttr->ConfigData.CriticalTemperatureEvent==1) && (Val16tmp&0x0001))
		{
			PEI_DEBUG((PeiServices, EFI_D_INFO, "Set critical temperature assert EVENT# %x\n",DramAttr->ConfigData.CriticalTemperatureEvent));
			
			//Set Critical event only, Event output control, Set Event polarity according MB type
			//Set Event polarity
//			if(ASIA_DRAMTEMP_EVENT_NOTGATE)
				Val16 = 0x000C;
//			else
//				Val16 = 0x000E;	
			
			Val16tmp = ((Val16&0x00FF)<<8) |( (Val16&0xFF00)>>8);
			SMBCMD=0x01;//Offset
			Status= pSMBusPPI->Execute(PeiServices, pSMBusPPI, SlaveAddress, SMBCMD, EfiSmbusWriteWord, 0, &SMBDataLength, &Val16tmp);//koen
		
			//Set critical temperature
			Val16 = (DramAttr->ConfigData.CriticalTemperatureValue)<<4;
			Val16tmp = ((Val16&0x00FF)<<8) |( (Val16&0xFF00)>>8);
			SMBCMD=0x04;//Offset
			Status= pSMBusPPI->Execute(PeiServices, pSMBusPPI, SlaveAddress, SMBCMD, EfiSmbusWriteWord, 0, &SMBDataLength, &Val16tmp);//koen

			PmioBar = (UINT16)AsiaPciRead32(CHX002_BUSC | D17F0_PMU_PM_IO_BASE);
			PmioBar &= D17F0_PMU_PMIOBA;
			AsiaIoModify8(PmioBar|PMIO_CR_GPIO_PAD_CTL+2, 0x3F, 0x09);//RxB6 GPIO10 Mux Control=001:SB2NB_PMUTEMPREQ, GPIO11 Mux Control=001:SB2NB_PMUTEMPREQB

			//Set D0F3 Rx170
			Address = AsiaPciAddress(CHX002_HB_BUS, CHX002_HB_DEV,CHX002_DRAM_FUN, D0F3_DRAM_BUS_TOGGLE_REDUCTION_CTL_BY_DIMM_TEMPERATURE_SENSOR);
			
			AsiaPcieWrite8(DramAttr->PcieBaseAddress, Address, D0F3_RTEMPCNTEN|(DramAttr->ConfigData.DramReduceRate));
			
			Address = AsiaPciAddress(CHX002_HB_BUS, CHX002_HB_DEV,CHX002_DRAM_FUN, D0F3_DRAM_BUS_TOGGLE_REDUCTION_CTL_BY_DIMM_TEMPERATURE_SENSOR);
			
			AsiaPcieModify16(DramAttr->PcieBaseAddress, Address, D0F3_D0F3_RX163B15|D0F3_RTEMPNUM2_6_0,D0F3_D0F3_RX163B15|0x2000);
			PEI_DEBUG((PeiServices, EFI_D_INFO, "CKS REG162 = %x\n",AsiaPcieRead16(DramAttr->PcieBaseAddress, Address)));

			//Set GPIO 10, 11 Mux by PMIO according to MB type
//			if(MB_TYPE)
//			{
//			}
		}	


		if(Dimm_Thermal_Support && (DramAttr->ConfigData.MemoryTemperatureDetect))
		{
			//Index 0x00
			SMBCMD=0x00;//Offset 00 = Capability register
			Status= pSMBusPPI->Execute(PeiServices, pSMBusPPI, SlaveAddress, SMBCMD, EfiSmbusReadWord, 0, &SMBDataLength, &Val16);
			Val16tmp = ((Val16&0x00FF)<<8) |( (Val16&0xFF00)>>8); //swap upper byte and lower byte
			PEI_DEBUG((PeiServices, EFI_D_INFO, "Alarm and critical trips = %x\n",(Val16tmp&0x0001)));
			PEI_DEBUG((PeiServices, EFI_D_INFO, "Accuracy = %x\n",(Val16tmp&0x0002)>>1));
			PEI_DEBUG((PeiServices, EFI_D_INFO, "Range width = %x\n",(Val16tmp&0x0004)>>2));
			PEI_DEBUG((PeiServices, EFI_D_INFO, "Temperature resolution = %x\n",(Val16tmp&0x0018)>>3));
			PEI_DEBUG((PeiServices, EFI_D_INFO, "(VHV) high voltage support for A0 (pin 1) = %x\n",(Val16tmp&0x0020)>>5));
			PEI_DEBUG((PeiServices, EFI_D_INFO, "TMOUT - bus timeout support (for temperature sensor only) = %x\n",(Val16tmp&0x0040)>>6));
			PEI_DEBUG((PeiServices, EFI_D_INFO, "EVSD - EVENT behavior upon shutdown = %x\n",(Val16tmp&0x0080)>>7));
				
			//Index 0x01
			SMBCMD=0x01;//Offset 
			Status= pSMBusPPI->Execute(PeiServices, pSMBusPPI, SlaveAddress, SMBCMD, EfiSmbusReadWord, 0, &SMBDataLength, &Val16);
			Val16tmp = ((Val16&0x00FF)<<8) |( (Val16&0xFF00)>>8); //swap upper byte and lower byte
			PEI_DEBUG((PeiServices, EFI_D_INFO, "Event mode = %x\n",(Val16tmp&0x0001)));
			PEI_DEBUG((PeiServices, EFI_D_INFO, "Event polarity (0 = Active-low, 1 = Active-high) = %x\n",(Val16tmp&0x0002)>>1));
			PEI_DEBUG((PeiServices, EFI_D_INFO, "Critical event only = %x\n",(Val16tmp&0x0004)>>2));
			PEI_DEBUG((PeiServices, EFI_D_INFO, "Event output control = %x\n",(Val16tmp&0x0008)>>3));
			PEI_DEBUG((PeiServices, EFI_D_INFO, "Event status = %x\n",(Val16tmp&0x0010)>>4));
			PEI_DEBUG((PeiServices, EFI_D_INFO, "Alarm window lock bit = %x\n",(Val16tmp&0x0040)>>6));
			PEI_DEBUG((PeiServices, EFI_D_INFO, "Critical trip lock bit = %x\n",(Val16tmp&0x0080)>>7));
			PEI_DEBUG((PeiServices, EFI_D_INFO, "Shutdown mode = %x\n",(Val16tmp&0x0100)>>8));
			PEI_DEBUG((PeiServices, EFI_D_INFO, "Hysteresis enable = %x\n",(Val16tmp&0x0600)>>9));
			
			//Index 0x02
			SMBCMD=0x02;//Offset
			Status= pSMBusPPI->Execute(PeiServices, pSMBusPPI, SlaveAddress, SMBCMD, EfiSmbusReadWord, 0, &SMBDataLength, &Val16);
			Val16tmp = ((Val16&0x00FF)<<8) |( (Val16&0xFF00)>>8); //swap upper byte and lower byte
			Val16tmp = (Val16tmp & 0x0FFC) >> 2; //get bit 11:2
			Val16tmp = Val16tmp>>2; //unit=0.25celsius, so divide by 4
			PEI_DEBUG((PeiServices, EFI_D_INFO, "Alarm temperature upper boundary: %03d\n", Val16tmp));

			//Index 0x03
			SMBCMD=0x03;//Offset
			Status= pSMBusPPI->Execute(PeiServices, pSMBusPPI, SlaveAddress, SMBCMD, EfiSmbusReadWord, 0, &SMBDataLength, &Val16);
			Val16tmp = ((Val16&0x00FF)<<8) |( (Val16&0xFF00)>>8); //swap upper byte and lower byte
			Val16tmp = (Val16tmp & 0x0FFC) >> 2; //get bit 11:2
			Val16tmp = Val16tmp>>2; //unit=0.25celsius, so divide by 4
			PEI_DEBUG((PeiServices, EFI_D_INFO, "Alarm temperature lower boundary: %03d\n", Val16tmp));
			
			//Index 0x04
			SMBCMD=0x04;//Offset
			Status= pSMBusPPI->Execute(PeiServices, pSMBusPPI, SlaveAddress, SMBCMD, EfiSmbusReadWord, 0, &SMBDataLength, &Val16);
			Val16tmp = ((Val16&0x00FF)<<8) |( (Val16&0xFF00)>>8); //swap upper byte and lower byte
			Val16tmp = (Val16tmp & 0x0FFC) >> 2; //get bit 11:2
			Val16tmp = Val16tmp>>2; //unit=0.25celsius, so divide by 4
			PEI_DEBUG((PeiServices, EFI_D_INFO, "Critical temperature: %03d\n", Val16tmp));
			
			//Index 0x05
			SMBCMD=0x05;//Offset
			Status= pSMBusPPI->Execute(PeiServices, pSMBusPPI, SlaveAddress, SMBCMD, EfiSmbusReadWord, 0, &SMBDataLength, &Val16);
			Val16tmp = ((Val16&0x00FF)<<8) |( (Val16&0xFF00)>>8); //swap upper byte and lower byte
			PEI_DEBUG((PeiServices, EFI_D_INFO, "Above critical input = %x\n",(Val16tmp&0x8000)>>15));
			PEI_DEBUG((PeiServices, EFI_D_INFO, "Above alarm window = %x\n",(Val16tmp&0x4000)>>14));
			PEI_DEBUG((PeiServices, EFI_D_INFO, "Below alarm window = %x\n",(Val16tmp&0x2000)>>13));
			Val16tmp = (Val16tmp & 0x0FFC) >> 2; //get bit 11:2
			Val16tmp = Val16tmp>>2; //unit=0.25celsius, so divide by 4
			PEI_DEBUG((PeiServices, EFI_D_INFO, "Dimm %d Ambient Temperature: %03d\n", Index+1, Val16tmp));
			
			//Index 0x06
			SMBCMD=0x06;//Offset 
			Status= pSMBusPPI->Execute(PeiServices, pSMBusPPI, SlaveAddress, SMBCMD, EfiSmbusReadWord, 0, &SMBDataLength, &Val16);
			Val16tmp = ((Val16&0x00FF)<<8) |( (Val16&0xFF00)>>8); //swap upper byte and lower byte
			PEI_DEBUG((PeiServices, EFI_D_INFO, "Manufacturer?|s ID = %x\n",(Val16tmp)));
			
			//Index 0x07
			SMBCMD=0x07;//Offset 
			Status= pSMBusPPI->Execute(PeiServices, pSMBusPPI, SlaveAddress, SMBCMD, EfiSmbusReadWord, 0, &SMBDataLength, &Val16);
			Val16tmp = ((Val16&0x00FF)<<8) |( (Val16&0xFF00)>>8); //swap upper byte and lower byte
			PEI_DEBUG((PeiServices, EFI_D_INFO, "Device ID/revision = %x\n",(Val16tmp)));
			
			//Index 0x08
			SMBCMD=0x08;//Offset 
			Status= pSMBusPPI->Execute(PeiServices, pSMBusPPI, SlaveAddress, SMBCMD, EfiSmbusReadByte, 0, &SMBDataLength, &Val8);
			PEI_DEBUG((PeiServices, EFI_D_INFO, "Temperature resolution register = %x\n",(Val8)));
		}	

	}

	PEI_DEBUG((PeiServices, EFI_D_INFO, "----------------------------------------------------------------------\n"));

}

VOID DRAMPerformanceSetting(IN EFI_PEI_SERVICES **PeiServices,
#if (PI_SPECIFICATION_VERSION < 0x00010000) 
		IN PEI_PCI_CFG_PPI *pPCIPPI,
#else
		IN EFI_PEI_PCI_CFG2_PPI *pPCIPPI,
#endif
		IN DRAM_ATTRIBUTE *DramAttr)           
{ 
	UINT64 Address;
	UINT16 RegIndx;

	//Register limitation Item 4 +S
	//DDRPHY_A0_REV[15:0] --DDRPHY_B8_REV[15:0] set default 0
	//D0F3_RxCA2 --> D0F3_RxCC4
	for (RegIndx = D0F3_DDRPHY_A0_RESERVED_REG; RegIndx <= D0F3_DDRPHY_B8_RESERVED_REG; RegIndx += 2)
	{
		Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN, RegIndx);
		AsiaPcieWrite16(DramAttr->PcieBaseAddress, Address, 0);
	}
	//Register limitation Item 4 +S

	//For performance -s	
	//(3)	RAGELIMIT[3:0]	 0x169[15:12] = 4'b1111 (max num of a request being bypassed in reorder queue)
	Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_DRAMC_REQ_REORDER_CTL_III_II);
	AsiaPcieModify16(DramAttr->PcieBaseAddress, Address, D0F3_RAGELIMIT_3_0, 0x0F << 12);
	//For performance -e

	
}

EFI_STATUS FinalTableProgramming(
	IN EFI_PEI_SERVICES **PeiServices,
#if (PI_SPECIFICATION_VERSION < 0x00010000) 
	IN PEI_PCI_CFG_PPI *pPCIPPI,
#else
	IN EFI_PEI_PCI_CFG2_PPI *pPCIPPI,
#endif
	IN PEI_SMBUS_PPI *pSMBusPPI,
	IN DRAM_ATTRIBUTE *DramAttr)
{

	UINT8  Data;
    UINT64 Address, AddressCHA, AddressCHB;
    UINT16  tempCHA,tempCHB;
    

    UINT8 RankIndex;
	BOOLEAN ChAB_RankSizeEqual;
	//UINT16 RDMBCOTF;

	//Swap VR beginning address and ending address of channel A and channel B
	ChAB_RankSizeEqual = 1;
	for (RankIndex = 0; RankIndex < 4; RankIndex++){
		if(DramAttr->RankInfo[DramAttr->AttrNo][RankIndex].RankSize != DramAttr->RankInfo[DramAttr->AttrNo][RankIndex+4].RankSize)
		{
			ChAB_RankSizeEqual=0;
			PEI_DEBUG((PeiServices, EFI_D_INFO, "SwapChAB failed\n"));
			break;
		}
	}
	
	if (DramAttr->ConfigData.SwapChAB && ChAB_RankSizeEqual)
	{
		for (RankIndex = 0; RankIndex < 4; RankIndex++)
		{
		    AddressCHA = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN,
		                     D0F3_DRAM_RANK0_BEGINNING_ADR_37_26 + RankIndex*2);
			AddressCHB = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN,
		                     D0F3_DRAM_RANK4_BEGINNING_ADR_37_26 + RankIndex*2);
			tempCHA = AsiaPcieRead16(DramAttr->PcieBaseAddress, AddressCHA);
			tempCHB = AsiaPcieRead16(DramAttr->PcieBaseAddress, AddressCHB);
			AsiaPcieWrite16(DramAttr->PcieBaseAddress, AddressCHA, tempCHB);
			AsiaPcieWrite16(DramAttr->PcieBaseAddress, AddressCHB, tempCHA);


			AddressCHA = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN,
		                     D0F3_DRAM_RANK0_ENDING_ADR_37_26 + RankIndex*2);
			AddressCHB = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN,
		                     D0F3_DRAM_RANK4_ENDING_ADR_37_26 + RankIndex*2);
			tempCHA = AsiaPcieRead16(DramAttr->PcieBaseAddress, AddressCHA);
			tempCHB = AsiaPcieRead16(DramAttr->PcieBaseAddress, AddressCHB);
			AsiaPcieWrite16(DramAttr->PcieBaseAddress, AddressCHA, tempCHB);
			AsiaPcieWrite16(DramAttr->PcieBaseAddress, AddressCHB, tempCHA);
			
		}
		   PEI_DEBUG((PeiServices, EFI_D_INFO, "SwapChAB = enable\n"));
	}

	
	//Leave DRAM dynamic CKE (D0F4_Rx71[7]) control by BIOS setup item.    
	Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_NPMC_FUN, D0F4_DRAMC_PM_REG_1);
	if ( DramAttr ->ConfigData.DynamicCKE) {
		AsiaPcieModify8(DramAttr->PcieBaseAddress, Address, D0F4_RDYNCKE, D0F4_RDYNCKE);
	}
	else {
       	AsiaPcieModify8(DramAttr->PcieBaseAddress, Address, D0F4_RDYNCKE, 0);
	}
    //Leave DRAM dynamic clock (D0F4_Rx73[7]) control by BIOS setup item.    
	//if (DramAttr->ConfigData.DramDynamicClk == DRAM_DYNAMIC_CLK_ENABLE) {
		//AsiaPciModify8( CHX002_NPMC|D0F4_DRAMC_PM_REG_3,
			//            D0F4_RDRAMCPM,
			  //          D0F4_RDRAMCPM);
	//}
	//else{
		//AsiaPciModify8( CHX002_NPMC|D0F4_DRAMC_PM_REG_3,
			//            D0F4_RDRAMCPM,
			  //          0);
		
	//}

    //LGE20160510 Add DataScramble  control
    if(DramAttr->ConfigData.DataScmb)
    {
      
	  Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_DRAM_TYPE_DRAM_INIT_CTL);
	  AsiaPcieModify16(DramAttr->PcieBaseAddress, Address, D0F3_RSCRMBLEN, D0F3_RSCRMBLEN);

	  //if CWL <= 9 , SET RSCRAM_LFREQ = 1
	  if(DramAttr->CWL[DramAttr->AttrNo] <= 9)
	  {
           Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_WCLK_PTR_LOG_CHA);  
           AsiaPcieModify16(DramAttr->PcieBaseAddress, Address, D0F3_RSCRAM_LFREQ, D0F3_RSCRAM_LFREQ);
	  }
	  
	}

	//enable ZQCS
	//RX162[15]
	Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_DRAM_TIMING_FOR_ALL_RANKS_X);
	//set ZQCS period = 128ms
	//RX162[11:0]
    AsiaPcieModify16(DramAttr->PcieBaseAddress, Address, D0F3_RZQCSNUM_11_0, 0x803);	
	AsiaPcieModify16(DramAttr->PcieBaseAddress, Address, D0F3_RZQCSEN, D0F3_RZQCSEN);
	
	


   
    //RX11C[8]
	if (DramAttr->Dram1TCommandRate == CMD_1T){
		Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_DRAM_MA_MAP_TYPE);
		AsiaPcieModify16(DramAttr->PcieBaseAddress, Address, D0F3_RCMD1T, D0F3_RCMD1T);
		}
		
	//CS_n can go to float state when rank_n is not present.
	//RX14A[7:0]
	Data = DramAttr->RankPresent[DramAttr->AttrNo];
    Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_PAD_CTL_DRAM_DATA_BURST_CTL);
    AsiaPcieModify16(DramAttr->PcieBaseAddress, Address, 0xFF00, Data << 8);



   
    //Address = AsiaPciAddress(CHX002_HB_BUS, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_DRAMC_REQ_REORDER_CTL_I_DRAM_REQ_CTL);
    //AsiaPcieModify16(DramAttr->PcieBaseAddress, Address, D0F3_RBYPASS1TEN, 0);



	
	
	//ODT Patch Extern 1T D0F3_Rx398[1:0] = 01b based on IRS Description"It should be set 01b in this chip ((CHX002))."
	Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_CMPEN_ALWAYS_ON_CHN_A);
	AsiaPcieModify16(DramAttr->PcieBaseAddress, Address, D0F3_RODTLAT1 | D0F3_RODTLAT0, D0F3_RODTLAT0);
	

#if 1
	if(DramAttr->WPREA == WPREA2CLK)
	{
		//Register limitation Item 6 +S
		//debug A3E[3] = 1
		////////////////////debug A3E[3] = 1/////////////////////
		Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_TX_WHOLE_T_TIMING_CTL_A2_A3_CHN_A);
		AsiaPcieModify16(DramAttr->PcieBaseAddress, Address, D0F3_RDQSOEDD_MUX, D0F3_RDQSOEDD_MUX);
		///////////////////////////////////////////////////////
		//Register limitation Item 6 +E
	}
#endif



  	//Register limitation Item 5 +S
	Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_PATROL_BEGIN_ADR_CHN_B);
	Data = AsiaPcieRead8(DramAttr->PcieBaseAddress, Address) & D0F3_RCMDFLAGDIS;

	Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_DRAMC_SUBMODULE_DYNAMIC_CLK_CTL);

	if (Data)
		AsiaPcieModify16(DramAttr->PcieBaseAddress, Address, D0F3_D0F3_RX1DB_9, D0F3_D0F3_RX1DB_9);
	else
		AsiaPcieModify16(DramAttr->PcieBaseAddress, Address, D0F3_D0F3_RX1DB_9, 0);
	//Register limitation Item 5 +E



	//Register limitation Item 8 +S
	Address = AsiaPciAddress(DramAttr->CHX002_BUS_NUM, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_DRAM_TIMING_FOR_ALL_RANKS_IV_V);
	AsiaPcieModify16(DramAttr->PcieBaseAddress, Address, D0F3_RT8BKEN, D0F3_RT8BKEN);
   	//Register limitation Item 8 +E

	DRAMPerformanceSetting(PeiServices, pPCIPPI, DramAttr);	
	//read thermal smbus test
	if (DramAttr->ConfigData.SwapByte78)
	{	
	DramAttr->ECCSupport=NO_ECC;
	Address = AsiaPciAddress(CHX002_HB_BUS, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_ECC_CTL_1_ECC_ERR_STA);
	AsiaPcieModify16(DramAttr->PcieBaseAddress,Address,D0F3_RECCEN+D0F3_RFBECCEN,0); 

	Address = AsiaPciAddress(CHX002_HB_BUS, CHX002_HB_DEV, CHX002_DRAM_FUN, D0F3_MASTERCTL_ECC_BYTE_SEL);
	AsiaPcieModify16(DramAttr->PcieBaseAddress,Address,D0F3_RECC_BYTE_SEL,D0F3_RECC_BYTE_SEL); 
	PEI_DEBUG((PeiServices, EFI_D_INFO, "Swap Byte 7 and 8 = enable\n"));
			}	 
	if (DramAttr->ConfigData.CriticalDDRIOTemperatureEvent==DDRIO_Event_AUTO)
	DDRIOThermalReading(PeiServices, pPCIPPI, DramAttr);
	
	ThermalReading(PeiServices, pPCIPPI, pSMBusPPI, DramAttr);

	return EFI_SUCCESS;	
}
