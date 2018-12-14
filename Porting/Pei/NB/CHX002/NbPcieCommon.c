/** @file
   ZX-E(CHX002) Asia NbPei library functions : NbPcieCommon.c

   Copyright (c) 2018 Shanghai Zhaoxin Semiconductor Co., Ltd. 

**/

#include "pei.h"

#include "CHX002Reg.h"
#include "CHX002Cfg.h"

#include "AsiaNbPeim.h"
#include "AsiaIoLib.h"
#include "SbLibPpi.h"
#include "SIPcieDriving.h"
#include "PeiLib.h"
#include EFI_PPI_DEFINITION(AsiaCpuPpi)
#include <AsiaSbPeim.h>

#include "NbPcieCommon.h"
#include "NbPciePETable.h"

unsigned char  PE0Patch[12][5] = {{4, 0x0A, 0x0B, 0x0C, 0x0D}, //;Configuration 0
			      {4, 0x0A, 0x0B, 0x0C, 0x0D},//;Configuration 1
			      {4, 0x0A, 0x0B, 0x0C, 0x0D},//;Configuration 2
			      {2, 0x0A, 0x0B, 0, 0},//;Configuration 3
			      {1, 0x0A, 0, 0, 0},//;Configuration 4
			      {1, 0x0A, 0, 0, 0},//;Configuration 5
			      {4, 0x0A, 0x0B, 0x0C, 0x0D},//;Configuration 6
			      {4, 0x0A, 0x0B, 0x0C, 0x0D},//;Configuration 7
			      {1, 0x0A, 0, 0, 0},//;Configuration 8
			      {1, 0x0A, 0, 0, 0},//;Configuration 9
			      {4, 0x0A, 0x0B, 0x0C, 0x0D},//;Configuration 10
			      {4, 0x0A, 0x0B, 0x0C, 0x0D}};//;Configuration 11

unsigned char  PE1Patch[12][2] = {{0, 0},//;Configuration 0
			      {0, 0},//;Configuration 1
			      {0, 0},//;Configuration 2
			      {0, 0},//;Configuration 3
			      {1, 0x0B},//;Configuration 4
			      {1, 0x0B},//;Configuration 5
			      {0, 0},//;Configuration 6
			      {0, 0},//;Configuration 7
			      {1, 0x0B},//;Configuration 8
			      {1, 0X0B},//;Configuration 9
			      {0, 0},//;Configuration 10
			      {0, 0}};//;Configuration 11

unsigned char  PE2Patch[12][3] = {{1, 0x0E, 0}, //;Configuration 0
			      {2, 0x0E, 0x0F},//;Configuration 1
			      {0, 0, 0},//;Configuration 2
			      {1, 0x0C,0},//;Configuration 3
			      {1, 0x0C,0},//;Configuration 4
			      {1, 0x0C,0},//;Configuration 5
			      {0, 0,0},//;Configuration 6
			      {0, 0,0},//;Configuration 7
			      {1, 0x0C,0},//;Configuration 8
			      {1, 0x0C,0},//;Configuration 9
			      {0, 0, 0},//;Configuration 10
			      {0, 0, 0}};//;Configuration 11

unsigned char  PE3Patch[12][2] = {{1, 0x0F}, //;Configuration 0
			      {0, 0},//;Configuration 1
			      {0, 0},//;Configuration 2
			      {1, 0x0D},//;Configuration 3
			      {1, 0x0D},//;Configuration 4
			      {1, 0x0D},//;Configuration 5
			      {0, 0},//;Configuration 6
			      {0, 0},//;Configuration 7
			      {1, 0x0D},//;Configuration 8
			      {1, 0X0D},//;Configuration 9
			      {0, 0},//;Configuration 10
			      {0, 0}};//;Configuration 11

unsigned char  PE4Patch[12][9] = {{8, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08, 0x09}, //;Configuration 0
			      {8, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08, 0x09},//;Configuration 1
			      {4, 0x02, 0x03, 0x04, 0x05},//;Configuration 28, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08, 0x09
			      {8, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08, 0x09},//;Configuration 3
			      {8, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08, 0x09},//;Configuration 4
			      {4, 0x02, 0x03, 0x04, 0x05},//;Configuration 5
			      {0, 0, 0, 0, 0, 0, 0, 0, 0},//;Configuration 6
			      {0, 0, 0, 0, 0, 0, 0, 0, 0},//;Configuration 7
			      {0, 0, 0, 0, 0, 0, 0, 0, 0},//;Configuration 8
			      {0, 0, 0, 0, 0, 0, 0, 0, 0},//;Configuration 9
			      {8, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08, 0x09},//;Configuration 10
			      {8, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08, 0x09}};//;Configuration11

unsigned char  PE5Patch[12][5] = {{0, 0, 0, 0, 0}, //;Configuration 0
			      {0, 0, 0, 0, 0},//;Configuration 1
			      {4, 0x06, 0x07, 0x08, 0x09},//;Configuration 2
			      {0, 0, 0, 0, 0},//;Configuration 3
			      {0, 0, 0, 0, 0},//;Configuration 4
			      {4, 0x06, 0x07, 0x08, 0x09},//;Configuration 5
			      {1, 0x0F, 0, 0, 0},//;Configuration 6
			      {0, 0, 0, 0, 0},//;Configuration 7
			      {1, 0x0F, 0, 0, 0},//;Configuration 8
			      {0, 0, 0, 0, 0},//;Configuration 9
			      {0, 0, 0, 0, 0},//;Configuration 10
			      {0, 0, 0, 0, 0}};//;Configuration 11


unsigned char  PE6Patch[12][3] = {{2, 0x00, 0x01}, //;Configuration 0
			      {1, 0x00, 0},//;Configuration 1
			      {1, 0, 0},//;Configuration 2
			      {1, 0, 0},//;Configuration 3
			      {1, 0x00, 0},//;Configuration 4
			      {1, 0x00, 0},//;Configuration 5
			      {1, 0x00, 0},//;Configuration 6
			      {1, 0x00, 0},//;Configuration 7
			      {2, 0x00, 0x01},//;Configuration 8
			      {2, 0x00, 0x01},//;Configuration 9
			      {1, 0x00, 0},//;Configuration 10
			      {2, 0x00, 0x01}};//;Configuration 11

unsigned char  PE7Patch[12][2] = {{0, 0}, //;Configuration 0
			      {1, 0x01},//;Configuration 1
			      {1, 0x01},//;Configuration 2
			      {1, 0x01},//;Configuration 3
			      {1, 0x01},//;Configuration 4
			      {1, 0x01},//;Configuration 5
			      {1, 0x01},//;Configuration 6
			      {1, 0x01},//;Configuration 7
			      {0, 0},//;Configuration 8
			      {0, 0},//;Configuration 9
			      {1, 0x01},//;Configuration 10
			      {0, 0}};//;Configuration11

/**
   PEI NBPEIM used 80 port output function.

  @param  PeiServices	EFI_PEI_SERVICES pointer.
  @param Data target 80 port value

  @return VOID.

**/
void PEI_PCIE_NB_80_PORT(IN EFI_PEI_SERVICES **PeiServices, UINT8 Data)
{
    UINT8 PostCodeValue=Data;
	AsiaIoWrite8(0x80,PostCodeValue);
	PEI_DEBUG((PeiServices,EFI_D_INFO, "POSTCODE=<%02x>\n", AsiaIoRead8(0x80)));
}

/**
   ShfitToMaskBit.

  @param  MaskBit.
  @param  ShiftData

  @return The value from this function.

**/
UINT16 
ShiftToMaskBit(
    IN UINT16 MaskBit,
    IN UINT16 ShiftData)
{
    UINT16 bValue, bIndex, bBuffer=0;

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
   NB PEIM PCIE used Stall function.

  @param  PeiServices	EFI_PEI_SERVICES pointer.
  @param Millisecond target delay range

  @return The value from this function.

**/
EFI_STATUS
PeiNbPcieStall (
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



/**
   Dump dedicated memory range's content.

  @param  PeiServices	EFI_PEI_SERVICES pointer.
  @param  MemBase
  @param DCount

  @return VOID.

**/
VOID
PCIeDumpMem(
	IN EFI_PEI_SERVICES **PeiServices, 
	UINT32 MemBase, 
	UINT16 DCount)
{

	UINT16 offsetx = 0;
	UINT8 readback8;
	PEI_DEBUG((PeiServices, EFI_D_ERROR, "[PCIE] DumpMem(Base:0x%08x, Count:0x%04x):\n",MemBase, DCount));
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
   Dump PCIE Config space.

  @param  PeiServices	EFI_PEI_SERVICES pointer.
  @param  PcieBase
  @param Busx Target Pcie device's bus number
  @param Devx Target Pcie device's device number
  @param Funx Target Pcie device's function number
  @param DCount  

  @return The value from this function.

**/
VOID
PCIeDumpCfg(
	IN EFI_PEI_SERVICES **PeiServices,
	UINT64 PcieBase,
	UINT8 Busx,
	UINT8 Devx, 
	UINT8 Funx, 
	UINT16 DCount)
{

	UINT16 offsetx = 0;
	UINT8 readback8;
	PEI_DEBUG((PeiServices, EFI_D_ERROR, "[PCIE] DumpCfg([%d|%d|%d] Count:0x%08x):\n",Busx,Devx,Funx,DCount));
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


/**
   PCIeCommonBusParser.

  @param  PciAddress

  @return UINT8.

**/
UINT8
PCIeCommonBusParser(UINT64 PciAddress)
{
	UINT8 *pointer;
	UINT64 PciAddr = PciAddress;

	pointer = (UINT8 *)(&PciAddr);

	return ((UINT8)(*(pointer+3)));
}

/**
   PCIeCommonDevParser.

  @param  PciAddress

  @return UINT8.

**/
UINT8
PCIeCommonDevParser(UINT64 PciAddress)
{
	UINT8 *pointer;
	UINT64 PciAddr = PciAddress;

	pointer = (UINT8 *)(&PciAddr);

	return (0x1F&((UINT8)(*(pointer+2))));	
}

/**
   PCIeCommonFuncParser.

  @param  PciAddress

  @return UINT8.

**/

UINT8
PCIeCommonFuncParser(UINT64 PciAddress)
{
	UINT8 *pointer;
	UINT64 PciAddr = PciAddress;

	pointer = (UINT8 *)(&PciAddr);

	return (0x7&((UINT8)(*(pointer+1))));	
}




/******************************************************************************************Start
//code for pcie patch
******************************************************************************************/
#if 1

/*+ DSZ_Porting -- (JIH-2017021401) Add Pcie Patch PCIEBadListWorkaround*/


// CJW-20180119: this struture was PATCH CODE for CHX001, not CHX002, now we 
//just comment out them, the real issued device will be added when A0 silicon come back 
BAD_PCIE_LINKUP_TBL PCIEBadListDeviceTbl[] = {
//Vendor ID		Device ID       Device ID Mask	 Patch Solution
//    0x12D8, 0x2404, 0xFFFF, ForceGen2,
//#ifdef HX001ED0_03   --- CJW-20180119: this was the EVB for CHX001~~~
//    0x1B21, 0x1242, 0xFFFF, ForceGen2, // AsMedia USB2312 U3 to PEx card
//#endif
//    0x2646, 0x0010, 0xFFFF, ForceGen2, // Kingstone PCIe SSD
//    0x1000, 0x0097, 0xFFFF, ForceDelay100ms,// LSI 9311-8i 12Gb/s SAS
    0x1B6F, 0x7052, 0xFFFF, ForceSIAnlogSwitchInternal,   //JNY-Patch ShengWei USB 4 Port card link up GEN2 Fail
	0x9005, 0x028D, 0xFFFF, ForceX4, // Adaptec 84054 Raid Card Lane 6 issue need force X4
	0x1000, 0x005B, 0xFFFF, ExtraPERST, //LSI SAS 9270-8I RAID card  down lane issue(add a PERST will )
	0x1B4B, 0x9170, 0xFFFF, ForceGen1, //RDT-Patch ShengWei PCIE2SATA D3 Command down mode to Gen1
	0x8086, 0xF1A6, 0xFFFF, UnsupportL1, //RDT-Patch Intel 760p ASPM is supported for L0s only, banned L1
	0xFFFF
};

/**
   PCIE Bad List Tune tx power supply function.

  This patch only for shengwei card PCIE2USB fail to link retrain to Gen 2;
	 This patch add to PHYA and PHYB(16 lane);
	 Tune TX Power Supply Switch singnal for anlog internal to get good singal swing.
	 This setting for PE0-PE6 is valid in EE0 EVB,
	 but PE7 is invalid in EE0 EVB,because PE7 trace is too long.

  @param  PeiServices	EFI_PEI_SERVICES pointer.
  @param pNbConfig Point to ASIA_NB_CONFIGURATION
  @param PcIAddress target pcie device's address

  @return The value from this function.

**/

void PCIEBadListTuneTxPowerSupply(    
	IN EFI_PEI_SERVICES **PeiServices,
    IN ASIA_NB_CONFIGURATION *NbConfig,
    IN UINT64 PciAddress)
{ 

	UINT8 EPHYCFG;
	UINT8 LaneX;
	UINT8 i=0;
	EPHYCFG = AsiaPcieRead8(NbConfig->PcieBar, CHX002_GFXAX|((UINT64)(D0F0_PCIE_ROMSIP_REGS_Z1) << 32)) & D0F0_RPCIESATACFG_3_0;
    PEI_DEBUG((PeiServices, EFI_D_INFO, "EPHYCFG= %d on Port: %08X\n",EPHYCFG, PciAddress));
	switch(PciAddress){
		case CHX002_PE0:	
			PEI_DEBUG((PeiServices, EFI_D_INFO, "PE0 Lane Num: %02X\n",PE0Patch[EPHYCFG][0]));
			for (i=0; i< PE0Patch[EPHYCFG][0]; i++)
			{
			    LaneX = PE0Patch[EPHYCFG][i+1];	
				PEI_DEBUG((PeiServices, EFI_D_INFO, "PE0Patch lanex= %02X\n",LaneX));
				if(((LaneX&BIT0)==0)&&(LaneX < 0x0E)){
					AsiaMemoryModify8(NbConfig->PcieEPHYBar |PCIEPHYCFG_RCV_LANE00_G2+ ((LaneX>>1)<<8),PCIEPHYCFG_FRP00_TXPWRSW_G2,0x01<<5);	//anlog 1.0v switch :0 internal
					PEI_DEBUG((PeiServices, EFI_D_INFO, "PE0Patch lanex value: %02X\n",AsiaMemoryRead8(NbConfig->PcieEPHYBar|PCIEPHYCFG_RCV_LANE00_G2+((LaneX>>1)<<8))));
				}else if(((LaneX&BIT0)==BIT0)&&(LaneX < 0x0E)){
					AsiaMemoryModify8(NbConfig->PcieEPHYBar |PCIEPHYCFG_RCV_LANE01_G2+ ((LaneX>>1)<<8),PCIEPHYCFG_FRP01_TXPWRSW_G2,0x01<<5); //anlog 1.0v switch :0 internal
					PEI_DEBUG((PeiServices, EFI_D_INFO, "PE0Patch lanex value: %02X\n",AsiaMemoryRead8(NbConfig->PcieEPHYBar|PCIEPHYCFG_RCV_LANE01_G2+((LaneX>>1)<<8))));
				}else if(((LaneX&BIT0)==0)&&(LaneX >= 0x0E)){
					AsiaMemoryModify8(NbConfig->PcieEPHYBar |PCIEPHYCFG_RCV_LANE14_G2,PCIEPHYCFG_FRP14_TXPWRSW_G2,0x01<<5); //anlog 1.0v switch :0 internal
					PEI_DEBUG((PeiServices, EFI_D_INFO, "PE0Patch lane14 value: %02X\n",AsiaMemoryRead8(NbConfig->PcieEPHYBar|PCIEPHYCFG_RCV_LANE14_G2)));
				}else if(((LaneX&BIT0)==BIT0)&&(LaneX >= 0x0E)){	
					AsiaMemoryModify8(NbConfig->PcieEPHYBar |PCIEPHYCFG_RCV_LANE15_G2,PCIEPHYCFG_FRP14_TXPWRSW_G2,0x01<<5); //anlog 1.0v switch :0 internal
					PEI_DEBUG((PeiServices, EFI_D_INFO, "PE0Patch lane15 value: %02X\n",AsiaMemoryRead8(NbConfig->PcieEPHYBar|PCIEPHYCFG_RCV_LANE15_G2)));
				}
			}
			break;
		case CHX002_PE1:	
			PEI_DEBUG((PeiServices, EFI_D_INFO, "PE1 Lane Num: %02X\n",PE1Patch[EPHYCFG][0]));
			for (i=0; i< PE1Patch[EPHYCFG][0]; i++)
			{
			    LaneX = PE1Patch[EPHYCFG][i+1];
				PEI_DEBUG((PeiServices, EFI_D_INFO, "PE1Patch lanex= %02X\n",LaneX));
					if(((LaneX&BIT0)==0)&&(LaneX < 0x0E)){
						AsiaMemoryModify8(NbConfig->PcieEPHYBar |PCIEPHYCFG_RCV_LANE00_G2+ ((LaneX>>1)<<8),PCIEPHYCFG_FRP00_TXPWRSW_G2,0x01<<5); //anlog 1.0v switch :0 internal
						PEI_DEBUG((PeiServices, EFI_D_INFO, "PE1Patch lanex value: %02X\n",AsiaMemoryRead8(NbConfig->PcieEPHYBar|PCIEPHYCFG_RCV_LANE00_G2+((LaneX>>1)<<8))));

					}else if(((LaneX&BIT0)==BIT0)&&(LaneX < 0x0E)){
						AsiaMemoryModify8(NbConfig->PcieEPHYBar |PCIEPHYCFG_RCV_LANE01_G2+ ((LaneX>>1)<<8),PCIEPHYCFG_FRP01_TXPWRSW_G2,0x01<<5); //anlog 1.0v switch :0 internal
						PEI_DEBUG((PeiServices, EFI_D_INFO, "PE1Patch lanex value: %02X\n",AsiaMemoryRead8(NbConfig->PcieEPHYBar|PCIEPHYCFG_RCV_LANE01_G2+((LaneX>>1)<<8))));
					}else if(((LaneX&BIT0)==0)&&(LaneX >= 0x0E)){
						AsiaMemoryModify8(NbConfig->PcieEPHYBar |PCIEPHYCFG_RCV_LANE14_G2,PCIEPHYCFG_FRP14_TXPWRSW_G2,0x01<<5); //anlog 1.0v switch :0 internal
						PEI_DEBUG((PeiServices, EFI_D_INFO, "PE1Patch lane14 value: %02X\n",AsiaMemoryRead8(NbConfig->PcieEPHYBar|PCIEPHYCFG_RCV_LANE14_G2)));
					}else if(((LaneX&BIT0)==BIT0)&&(LaneX >= 0x0E)){	
						AsiaMemoryModify8(NbConfig->PcieEPHYBar |PCIEPHYCFG_RCV_LANE15_G2,PCIEPHYCFG_FRP14_TXPWRSW_G2,0x01<<5); //anlog 1.0v switch :0 internal
						PEI_DEBUG((PeiServices, EFI_D_INFO, "PE1Patch lane15 value: %02X\n",AsiaMemoryRead8(NbConfig->PcieEPHYBar|PCIEPHYCFG_RCV_LANE15_G2)));
					}

			}
			break;
		case CHX002_PE2:		
			PEI_DEBUG((PeiServices, EFI_D_INFO, "PE2 Lane Num: %02X\n",PE2Patch[EPHYCFG][0]));
			for (i=0; i< PE2Patch[EPHYCFG][0]; i++)
			{
			    LaneX = PE2Patch[EPHYCFG][i+1];		
				PEI_DEBUG((PeiServices, EFI_D_INFO, "PE2Patch lanex= %02X\n",LaneX));
				if(((LaneX&BIT0)==0)&&(LaneX < 0x0E)){	
					AsiaMemoryModify8(NbConfig->PcieEPHYBar |PCIEPHYCFG_RCV_LANE00_G2+ ((LaneX>>1)<<8),PCIEPHYCFG_FRP00_TXPWRSW_G2,0x01<<5);	//anlog 1.0v switch :0 internal
					PEI_DEBUG((PeiServices, EFI_D_INFO, "PE2Patch lanex value: %02X\n",AsiaMemoryRead8(NbConfig->PcieEPHYBar|PCIEPHYCFG_RCV_LANE00_G2+((LaneX>>1)<<8))));

				}else if(((LaneX&BIT0)==BIT0)&&(LaneX < 0x0E)){
					AsiaMemoryModify8(NbConfig->PcieEPHYBar |PCIEPHYCFG_RCV_LANE01_G2+ ((LaneX>>1)<<8),PCIEPHYCFG_FRP01_TXPWRSW_G2,0x01<<5); //anlog 1.0v switch :0 internal
					PEI_DEBUG((PeiServices, EFI_D_INFO, "PE2Patch lanex value: %02X\n",AsiaMemoryRead8(NbConfig->PcieEPHYBar|PCIEPHYCFG_RCV_LANE01_G2+((LaneX>>1)<<8))));
				}else if(((LaneX&BIT0)==0)&&(LaneX >= 0x0E)){
					AsiaMemoryModify8(NbConfig->PcieEPHYBar |PCIEPHYCFG_RCV_LANE14_G2,PCIEPHYCFG_FRP14_TXPWRSW_G2,0x01<<5); //anlog 1.0v switch :0 internal
					PEI_DEBUG((PeiServices, EFI_D_INFO, "PE2Patch lane14 value: %02X\n",AsiaMemoryRead8(NbConfig->PcieEPHYBar|PCIEPHYCFG_RCV_LANE14_G2)));
				}else if(((LaneX&BIT0)==BIT0)&&(LaneX >= 0x0E)){	
					AsiaMemoryModify8(NbConfig->PcieEPHYBar |PCIEPHYCFG_RCV_LANE15_G2,PCIEPHYCFG_FRP14_TXPWRSW_G2,0x01<<5); //anlog 1.0v switch :0 internal
					PEI_DEBUG((PeiServices, EFI_D_INFO, "PE2Patch lane15 value: %02X\n",AsiaMemoryRead8(NbConfig->PcieEPHYBar|PCIEPHYCFG_RCV_LANE15_G2)));
				}

			}
			break;
		case CHX002_PE3:		
			PEI_DEBUG((PeiServices, EFI_D_INFO, "PE3 Lane Num: %02X\n",PE3Patch[EPHYCFG][0]));
			for (i=0; i< PE3Patch[EPHYCFG][0]; i++)
			{
			    LaneX = PE3Patch[EPHYCFG][i+1];	
				PEI_DEBUG((PeiServices, EFI_D_INFO, "PE3Patch lanex= %02X\n",LaneX));
				if(((LaneX&BIT0)==0)&&(LaneX < 0x0E)){		
					AsiaMemoryModify8(NbConfig->PcieEPHYBar |PCIEPHYCFG_RCV_LANE00_G2+ ((LaneX>>1)<<8),PCIEPHYCFG_FRP00_TXPWRSW_G2,0x01<<5);	//anlog 1.0v switch :0 internal
					PEI_DEBUG((PeiServices, EFI_D_INFO, "PE3Patch lanex value: %02X\n",AsiaMemoryRead8(NbConfig->PcieEPHYBar|PCIEPHYCFG_RCV_LANE00_G2+((LaneX>>1)<<8))));

				}else if(((LaneX&BIT0)==BIT0)&&(LaneX < 0x0E)){
					AsiaMemoryModify8(NbConfig->PcieEPHYBar |PCIEPHYCFG_RCV_LANE01_G2+ ((LaneX>>1)<<8),PCIEPHYCFG_FRP01_TXPWRSW_G2,0x01<<5); //anlog 1.0v switch :0 internal
					PEI_DEBUG((PeiServices, EFI_D_INFO, "PE3Patch lanex value: %02X\n",AsiaMemoryRead8(NbConfig->PcieEPHYBar|PCIEPHYCFG_RCV_LANE01_G2+((LaneX>>1)<<8))));
				}else if(((LaneX&BIT0)==0)&&(LaneX >= 0x0E)){
					AsiaMemoryModify8(NbConfig->PcieEPHYBar |PCIEPHYCFG_RCV_LANE14_G2,PCIEPHYCFG_FRP14_TXPWRSW_G2,0x01<<5); //anlog 1.0v switch :0 internal
					PEI_DEBUG((PeiServices, EFI_D_INFO, "PE3Patch lane14 value: %02X\n",AsiaMemoryRead8(NbConfig->PcieEPHYBar|PCIEPHYCFG_RCV_LANE14_G2)));
				}else if(((LaneX&BIT0)==BIT0)&&(LaneX >= 0x0E)){	
					AsiaMemoryModify8(NbConfig->PcieEPHYBar |PCIEPHYCFG_RCV_LANE15_G2,PCIEPHYCFG_FRP14_TXPWRSW_G2,0x01<<5); //anlog 1.0v switch :0 internal
					PEI_DEBUG((PeiServices, EFI_D_INFO, "PE3Patch lane15 value: %02X\n",AsiaMemoryRead8(NbConfig->PcieEPHYBar|PCIEPHYCFG_RCV_LANE15_G2)));
				}

			}
			break;

		case CHX002_PE4:		
			PEI_DEBUG((PeiServices, EFI_D_INFO, "PE4 Lane Num: %02X\n",PE4Patch[EPHYCFG][0]));
			for (i=0; i< PE4Patch[EPHYCFG][0]; i++)
			{
			    LaneX = PE4Patch[EPHYCFG][i+1];
				PEI_DEBUG((PeiServices, EFI_D_INFO, "PE4Patch lanex = %02X\n",LaneX));
				if(((LaneX&BIT0)==0)&&(LaneX < 0x0E)){
					
					AsiaMemoryModify8(NbConfig->PcieEPHYBar |PCIEPHYCFG_RCV_LANE00_G2+ ((LaneX>>1)<<8),PCIEPHYCFG_FRP00_TXPWRSW_G2,0x01<<5);	//anlog 1.0v switch :0 internal
					PEI_DEBUG((PeiServices, EFI_D_INFO, "PE4Patch lanex value: %02X\n",AsiaMemoryRead8(NbConfig->PcieEPHYBar|PCIEPHYCFG_RCV_LANE00_G2+((LaneX>>1)<<8))));

				}else if(((LaneX&BIT0)==BIT0)&&(LaneX < 0x0E)){
					AsiaMemoryModify8(NbConfig->PcieEPHYBar |PCIEPHYCFG_RCV_LANE01_G2+ ((LaneX>>1)<<8),PCIEPHYCFG_FRP01_TXPWRSW_G2,0x01<<5); //anlog 1.0v switch :0 internal
					PEI_DEBUG((PeiServices, EFI_D_INFO, "PE4Patch lanex value: %02X\n",AsiaMemoryRead8(NbConfig->PcieEPHYBar|PCIEPHYCFG_RCV_LANE01_G2+((LaneX>>1)<<8))));
				}else if(((LaneX&BIT0)==0)&&(LaneX >= 0x0E)){
					AsiaMemoryModify8(NbConfig->PcieEPHYBar |PCIEPHYCFG_RCV_LANE14_G2,PCIEPHYCFG_FRP14_TXPWRSW_G2,0x01<<5); //anlog 1.0v switch :0 internal
					PEI_DEBUG((PeiServices, EFI_D_INFO, "PE4Patch lane14 value: %02X\n",AsiaMemoryRead8(NbConfig->PcieEPHYBar|PCIEPHYCFG_RCV_LANE14_G2)));
				}else if(((LaneX&BIT0)==BIT0)&&(LaneX >= 0x0E)){	
					AsiaMemoryModify8(NbConfig->PcieEPHYBar |PCIEPHYCFG_RCV_LANE15_G2,PCIEPHYCFG_FRP14_TXPWRSW_G2,0x01<<5); //anlog 1.0v switch :0 internal
					PEI_DEBUG((PeiServices, EFI_D_INFO, "PE4Patch lane15 value: %02X\n",AsiaMemoryRead8(NbConfig->PcieEPHYBar|PCIEPHYCFG_RCV_LANE15_G2)));
				}

			}

		break;
		case CHX002_PE5:	
			PEI_DEBUG((PeiServices, EFI_D_INFO, "PE5 Lane Num: %02X\n",PE5Patch[EPHYCFG][0]));
			for (i=0; i< PE5Patch[EPHYCFG][0]; i++)
			{
			    LaneX = PE5Patch[EPHYCFG][i+1];		
				PEI_DEBUG((PeiServices, EFI_D_INFO, "PE5Patch lanex = %02X\n",LaneX));
				if(((LaneX&BIT0)==0)&&(LaneX < 0x0E)){	
					AsiaMemoryModify8(NbConfig->PcieEPHYBar |PCIEPHYCFG_RCV_LANE00_G2+ ((LaneX>>1)<<8),PCIEPHYCFG_FRP00_TXPWRSW_G2,0x01<<5);	//anlog 1.0v switch :0 internal
					PEI_DEBUG((PeiServices, EFI_D_INFO, "PE5Patch lanex value: %02X\n",AsiaMemoryRead8(NbConfig->PcieEPHYBar|PCIEPHYCFG_RCV_LANE00_G2+((LaneX>>1)<<8))));
				}else if(((LaneX&BIT0)==BIT0)&&(LaneX < 0x0E)){
					AsiaMemoryModify8(NbConfig->PcieEPHYBar |PCIEPHYCFG_RCV_LANE01_G2+ ((LaneX>>1)<<8),PCIEPHYCFG_FRP01_TXPWRSW_G2,0x01<<5); //anlog 1.0v switch :0 internal
					PEI_DEBUG((PeiServices, EFI_D_INFO, "PE5Patch lanex value: %02X\n",AsiaMemoryRead8(NbConfig->PcieEPHYBar|PCIEPHYCFG_RCV_LANE01_G2+((LaneX>>1)<<8))));
				}else if(((LaneX&BIT0)==0)&&(LaneX >= 0x0E)){
					AsiaMemoryModify8(NbConfig->PcieEPHYBar |PCIEPHYCFG_RCV_LANE14_G2,PCIEPHYCFG_FRP14_TXPWRSW_G2,0x01<<5); //anlog 1.0v switch :0 internal
					PEI_DEBUG((PeiServices, EFI_D_INFO, "PE5Patch lane14 value: %02X\n",AsiaMemoryRead8(NbConfig->PcieEPHYBar|PCIEPHYCFG_RCV_LANE14_G2)));
				}else if(((LaneX&BIT0)==BIT0)&&(LaneX >= 0x0E)){	
					AsiaMemoryModify8(NbConfig->PcieEPHYBar |PCIEPHYCFG_RCV_LANE15_G2,PCIEPHYCFG_FRP14_TXPWRSW_G2,0x01<<5); //anlog 1.0v switch :0 internal
					PEI_DEBUG((PeiServices, EFI_D_INFO, "PE5Patch lane15 value: %02X\n",AsiaMemoryRead8(NbConfig->PcieEPHYBar|PCIEPHYCFG_RCV_LANE15_G2)));
				}

			}

			break;
		case CHX002_PE6:	
			PEI_DEBUG((PeiServices, EFI_D_INFO, "PE6 Lane Num: %02X\n",PE6Patch[EPHYCFG][0]));
			for (i=0; i< PE6Patch[EPHYCFG][0]; i++)
			{
			    LaneX = PE6Patch[EPHYCFG][i+1];
				PEI_DEBUG((PeiServices, EFI_D_INFO, "PE6Patch lanex = %02X\n",LaneX));
				if(((LaneX&BIT0)==0)&&(LaneX < 0x0E)){
					AsiaMemoryModify8(NbConfig->PcieEPHYBar |PCIEPHYCFG_RCV_LANE00_G2+ ((LaneX>>1)<<8),PCIEPHYCFG_FRP00_TXPWRSW_G2,0x01<<5);	//anlog 1.0v switch :0 internal
					PEI_DEBUG((PeiServices, EFI_D_INFO, "PE6Patch lanex value: %02X\n",AsiaMemoryRead8(NbConfig->PcieEPHYBar|PCIEPHYCFG_RCV_LANE00_G2+((LaneX>>1)<<8))));

				}else if(((LaneX&BIT0)==BIT0)&&(LaneX < 0x0E)){
					AsiaMemoryModify8(NbConfig->PcieEPHYBar |PCIEPHYCFG_RCV_LANE01_G2+ ((LaneX>>1)<<8),PCIEPHYCFG_FRP01_TXPWRSW_G2,0x01<<5); //anlog 1.0v switch :0 internal
					PEI_DEBUG((PeiServices, EFI_D_INFO, "PE6Patch lanex value: %02X\n",AsiaMemoryRead8(NbConfig->PcieEPHYBar|PCIEPHYCFG_RCV_LANE01_G2+((LaneX>>1)<<8))));
				}else if(((LaneX&BIT0)==0)&&(LaneX >= 0x0E)){
					AsiaMemoryModify8(NbConfig->PcieEPHYBar |PCIEPHYCFG_RCV_LANE14_G2,PCIEPHYCFG_FRP14_TXPWRSW_G2,0x01<<5); //anlog 1.0v switch :0 internal
					PEI_DEBUG((PeiServices, EFI_D_INFO, "PE6Patch lane14 value: %02X\n",AsiaMemoryRead8(NbConfig->PcieEPHYBar|PCIEPHYCFG_RCV_LANE14_G2)));
				}else if(((LaneX&BIT0)==BIT0)&&(LaneX >= 0x0E)){	
					AsiaMemoryModify8(NbConfig->PcieEPHYBar |PCIEPHYCFG_RCV_LANE15_G2,PCIEPHYCFG_FRP14_TXPWRSW_G2,0x01<<5); //anlog 1.0v switch :0 internal
					PEI_DEBUG((PeiServices, EFI_D_INFO, "PE6Patch lane15 value: %02X\n",AsiaMemoryRead8(NbConfig->PcieEPHYBar|PCIEPHYCFG_RCV_LANE15_G2)));
				}

			}

			break;
		case CHX002_PE7:	
			PEI_DEBUG((PeiServices, EFI_D_INFO, "PE7 Lane Num: %02X",PE7Patch[EPHYCFG][0]));
			for (i=0; i< PE7Patch[EPHYCFG][0]; i++)
			{
			    LaneX = PE7Patch[EPHYCFG][i+1];	
				PEI_DEBUG((PeiServices, EFI_D_INFO, "PE7Patch lanex= %02X\n",LaneX));
				if(((LaneX&BIT0)==0)&&(LaneX < 0x0E)){
					AsiaMemoryModify8(NbConfig->PcieEPHYBar |PCIEPHYCFG_RCV_LANE00_G2+ ((LaneX>>1)<<8),PCIEPHYCFG_FRP00_TXPWRSW_G2,0x01<<5);	//anlog 1.0v switch :0 internal
					PEI_DEBUG((PeiServices, EFI_D_INFO, "PE7Patch lanex value: %02X\n",AsiaMemoryRead8(NbConfig->PcieEPHYBar|PCIEPHYCFG_RCV_LANE00_G2+((LaneX>>1)<<8))));

				}else if(((LaneX&BIT0)==BIT0)&&(LaneX < 0x0E)){
					AsiaMemoryModify8(NbConfig->PcieEPHYBar |PCIEPHYCFG_RCV_LANE01_G2+ ((LaneX>>1)<<8),PCIEPHYCFG_FRP01_TXPWRSW_G2,0x01<<5); //anlog 1.0v switch :0 internal
					PEI_DEBUG((PeiServices, EFI_D_INFO, "PE7Patch lanex value: %02X\n",AsiaMemoryRead8(NbConfig->PcieEPHYBar|PCIEPHYCFG_RCV_LANE01_G2+((LaneX>>1)<<8))));
				}else if(((LaneX&BIT0)==0)&&(LaneX >= 0x0E)){
					AsiaMemoryModify8(NbConfig->PcieEPHYBar |PCIEPHYCFG_RCV_LANE14_G2,PCIEPHYCFG_FRP14_TXPWRSW_G2,0x01<<5); //anlog 1.0v switch :0 internal
					PEI_DEBUG((PeiServices, EFI_D_INFO, "PE7Patch lane14 value: %02X\n",AsiaMemoryRead8(NbConfig->PcieEPHYBar|PCIEPHYCFG_RCV_LANE14_G2)));
				}else if(((LaneX&BIT0)==BIT0)&&(LaneX >= 0x0E)){	
					AsiaMemoryModify8(NbConfig->PcieEPHYBar |PCIEPHYCFG_RCV_LANE15_G2,PCIEPHYCFG_FRP14_TXPWRSW_G2,0x01<<5); //anlog 1.0v switch :0 internal
					PEI_DEBUG((PeiServices, EFI_D_INFO, "PE7Patch lane15 value: %02X\n",AsiaMemoryRead8(NbConfig->PcieEPHYBar|PCIEPHYCFG_RCV_LANE15_G2)));
				}

			}
			break;
			
		 default:
			break;
	}
	
    PEI_DEBUG((PeiServices, EFI_D_INFO, "[JNY-DEBUG]:This card of ShengWei  Patch Done!\n"));
}

/**
   PCIE Bad List extra pe-reset patch function.

  @param  PeiServices	EFI_PEI_SERVICES pointer.
  @param  pNbConfig  point to ASIA_NB_CONFIGURATION
  @param PciAddress Target pcie device's address

  @return The value from this function.

**/
void 
PCIEBadListExtraPERSTPatch(
	IN EFI_PEI_SERVICES **PeiServices,
	IN ASIA_NB_CONFIGURATION *NbConfig,
	IN UINT64 PciAddress)
{

	PEI_DEBUG((PeiServices, EFI_D_INFO, "PCIEBadListExtraPERSTPatch() - An extra PERST# for this device\n"));
	AsiaPcieModify8(NbConfig->PcieBar, PciAddress|((UINT64)D3D5F1_UNRELIABLE_LINK_MANAGEMENT << 32), D3D5F1_RUNRLCLR, D3D5F1_RUNRLCLR);      //clear unreliable status
	PCIeCommonPERST(PeiServices,PciAddress);
	PEI_DEBUG((PeiServices, EFI_D_INFO, "PCIE Port PERST Done!\n"));
		
}

/**
   PCIE Bad List force X4 patch function.

  @param  PeiServices	EFI_PEI_SERVICES pointer.
  @param  pNbConfig  point to ASIA_NB_CONFIGURATION
  @param PciAddress Target pcie device's address

  @return The value from this function.

**/
void 
PCIEBadListForceX4Patch(
    IN EFI_PEI_SERVICES **PeiServices,
    IN ASIA_NB_CONFIGURATION *NbConfig,
    IN UINT64 PciAddress)
{
    UINT16 CurrentWidth;

	//Get Max Supported Link Width
    CurrentWidth = AsiaPciRead16(PciAddress|D3D5F1_LINK_CAPS_1_D4F0) & 
					(D3D5F1_LKMLW_5 |D3D5F1_LKMLW_4 |D3D5F1_LKMLW_3 |D3D5F1_LKMLW_2 |D3D5F1_LKMLW_1 |D3D5F1_LKMLW_0);
    CurrentWidth = (CurrentWidth >> 4);

    PEI_DEBUG((PeiServices, EFI_D_INFO, "PCIEBadListForceX4Patch() - Link Width %d on Port: %08X\n",CurrentWidth, PciAddress));

    if(CurrentWidth <= 0x04){
		return;
	}
		
    // JIH - Enable Back Door for Link Capability
    AsiaPcieModify8(NbConfig->PcieBar, CHX002_APIC|((UINT64)D0F5_PMU_CTL << 32), D0F5_RPEROWEN, D0F5_RPEROWEN);

    AsiaPcieModify16(NbConfig->PcieBar, PciAddress|((UINT64)D3D5F1_LINK_CAPS_1_D4F0 << 32), 
					D3D5F1_LKMLW_5 |D3D5F1_LKMLW_4 |D3D5F1_LKMLW_3 |D3D5F1_LKMLW_2 |D3D5F1_LKMLW_1 |D3D5F1_LKMLW_0, 
					D3D5F1_LKMLW_2);
    // JIH - Disable Back Door for  Link Capability
    AsiaPcieModify8(NbConfig->PcieBar, CHX002_APIC|((UINT64)D0F5_PMU_CTL << 32), D0F5_RPEROWEN, 0x00);

    AsiaPcieModify8(NbConfig->PcieBar, PciAddress|((UINT64)D3D5F1_LINK_CTL_1 << 32), D3D5F1_LCRL, D3D5F1_LCRL);      //Retrain Link

    //wait 100 ms to retrain PCIE Link      
    PeiNbPcieStall(PeiServices, 0x64);      
    PEI_DEBUG((PeiServices, EFI_D_INFO, "PCIE Retrain Done!\n"));
            
}


void PCIEBadListForceGenSpeedPatch(
    IN EFI_PEI_SERVICES **PeiServices,
    IN ASIA_NB_CONFIGURATION *NbConfig,
    IN UINT64 PciAddress,
    IN UINT8 GenSpeed
)
{
    // RDT - Enable Back Door for Link Capability
	//UINT8 TargetSpeed;
	//UINT8 CurrentSpeed;
	
    PEI_DEBUG((PeiServices, EFI_D_INFO, "PCIEBadListForceSpeedPatch() - Gen %d on Port: %X\n",GenSpeed, PciAddress));
	
    AsiaPcieModify8(NbConfig->PcieBar, CHX002_APIC|((UINT64)D0F5_PMU_CTL << 32), D0F5_RPEROWEN, D0F5_RPEROWEN);
    AsiaPciModify8(PciAddress |D3D5F1_LINK_CAPS_1_D4F0, 0x07, GenSpeed);
    AsiaPciModify8(PciAddress |D3D5F1_LINK_CTL_2_D4F0 , 0x07, GenSpeed);
    // RDT - Disable Back Door for  Link Capability
    AsiaPcieModify8(NbConfig->PcieBar, CHX002_APIC|((UINT64)D0F5_PMU_CTL << 32), D0F5_RPEROWEN, 0x00);

    AsiaPcieModify8(NbConfig->PcieBar, PciAddress|((UINT64)D3D5F1_LINK_CTL_1 << 32), D3D5F1_LCRL, D3D5F1_LCRL);      //Retrain Link

	//TargetSpeed = AsiaPcieRead8(NbConfig->PcieBar, PciAddress |D3D5F1_LINK_CTL_2_D4F0);
	//PEI_DEBUG((PeiServices, EFI_D_INFO, "RDT-TargetSpeed = %02x\n",TargetSpeed));

	//CurrentSpeed = AsiaPcieRead8(NbConfig->PcieBar, PciAddress |D3D5F1_LINK_STA_1);
	//PEI_DEBUG((PeiServices, EFI_D_INFO, "RDT-CurrentSpeed = %02x\n",CurrentSpeed));
	
	
    //wait 100 ms to retrain PCIE Link      
    PeiNbPcieStall(PeiServices, 0x64);      
    PEI_DEBUG((PeiServices, EFI_D_INFO, "PCIE Retrain Done!\n"));
            
}



void PCIEBadListUnsupportL1Patch(
    IN EFI_PEI_SERVICES **PeiServices,
    IN ASIA_NB_CONFIGURATION *NbConfig,
    IN UINT64 PciAddress
)
{

	if((!NbConfig->PcieASPM)&&(!NbConfig->PcieASPMBootArch)){
		return;
	}
	
    PEI_DEBUG((PeiServices, EFI_D_INFO, "PCIEBadListUnsupportL1Patch()\n"));
	// RDT - Enable Back Door for Link Capability
    AsiaPcieModify8(NbConfig->PcieBar, CHX002_APIC|((UINT64)D0F5_PMU_CTL << 32), D0F5_RPEROWEN, D0F5_RPEROWEN);
	//banned L1
	AsiaPcieModify16(NbConfig->PcieBar, PciAddress|((UINT64)D3D5F1_LINK_CAPS_1_D4F0 << 32), BIT11,0);
    // RDT - Disable Back Door for  Link Capability
    AsiaPcieModify8(NbConfig->PcieBar, CHX002_APIC|((UINT64)D0F5_PMU_CTL << 32), D0F5_RPEROWEN, 0x00);
	//Retrain Link
    //AsiaPcieModify8(NbConfig->PcieBar, PciAddress|((UINT64)D3D5F1_LINK_CTL_1 << 32), D3D5F1_LCRL, D3D5F1_LCRL);      

	PEI_DEBUG((PeiServices, EFI_D_ERROR, "		 PEIASPMAfterPatch = %X\n",AsiaPciRead16(PciAddress |D3D5F1_LINK_CAPS_1_D4F0)));	
	
    //wait 100 ms to retrain PCIE Link      
    //PeiNbPcieStall(PeiServices, 0x64);      
    //PEI_DEBUG((PeiServices, EFI_D_INFO, "PCIE Retrain Done!\n"));
            
}






/**
   PCIE Bad List workaround main function.

  @param  PeiServices	EFI_PEI_SERVICES pointer.
  @param  pNbConfig  point to ASIA_NB_CONFIGURATION
  @param PciAddress Target pcie device's address
  @param PcieCap point to PCIE_Cap struct

  @return The value from this function.

**/
EFI_STATUS 
PCIEBadListWorkaround(
    IN EFI_PEI_SERVICES **PeiServices,
    IN ASIA_NB_CONFIGURATION *NbConfig,
    IN UINT64 PciAddress,
    OUT PCIE_Cap *PcieCap)
{
	EFI_STATUS Status = EFI_SUCCESS;
	UINT64 PcieBase = NbConfig->PcieBar;
	UINT8 SubBusNo, DevSearch, FuncSearch;
	UINT16	 VendorId, DeviceId;
	UINT16	 i;

	//if port not exist, exit directly
    if((AsiaPciRead16(PciAddress |D3D5F1_VID)) == 0xFFFF){
		return EFI_NOT_FOUND;
	}
		
	//if card not exist under this port, exit directly
    if((AsiaPciRead8(PciAddress |D3D5F1_SLOT_STA_1) & D3D5F1_SPDCST) != D3D5F1_SPDCST){
        return EFI_NOT_FOUND;
	}
	
	PEI_DEBUG((PeiServices, EFI_D_ERROR, "		 PCIEBadListWorkaround()\n"));

	//if LTSSM not 8A
	if((AsiaPcieRead8(NbConfig->PcieBar, PciAddress |((UINT64)D3D5F1_PHYLS_LTSSM_STATE << 32)) < 0x8A)){
		PEI_DEBUG((PeiServices, EFI_D_ERROR, "		 --ERROR! LTSSM not 0x8A, exit\n"));
		PCIeDumpCfg(PeiServices, PcieBase,
						PCIeCommonBusParser(PciAddress), 
						PCIeCommonDevParser(PciAddress), 
						PCIeCommonFuncParser(PciAddress), 0x200);
		return EFI_NOT_FOUND;
	}

	//Dump registers
	PCIeDumpCfg(PeiServices, PcieBase,
					PCIeCommonBusParser(PciAddress), 
					PCIeCommonDevParser(PciAddress), 
					PCIeCommonFuncParser(PciAddress), 0x40);

	//Assign temp bus number for device
    AsiaPciWrite8(PciAddress |D3D5F1_SECONDARY_BUS_NUM, 01) ;
    AsiaPciWrite8(PciAddress |D3D5F1_SUBORDINATE_BUS_NUM, 01) ;

	SubBusNo =  AsiaPciRead8(PciAddress |D3D5F1_SECONDARY_BUS_NUM) ;
	
	for(DevSearch = 0; DevSearch <= 31; DevSearch ++){
		for(FuncSearch = 0; FuncSearch <= 7; FuncSearch++){
	
			VendorId = AsiaPciRead16(AsiaPciAddress(SubBusNo, DevSearch, FuncSearch, 0));
			DeviceId = AsiaPciRead16(AsiaPciAddress(SubBusNo, DevSearch, FuncSearch, 2));
			if(DeviceId == 0xFFFF){
				continue;
			}
			
			for(i=0; i<sizeof(PCIEBadListDeviceTbl)/sizeof(BAD_PCIE_LINKUP_TBL); i++){
				if((VendorId==PCIEBadListDeviceTbl[i].VendorId)&&(DeviceId==(PCIEBadListDeviceTbl[i].DeviceId & PCIEBadListDeviceTbl[i].DeviceIdMask))){
	
					PEI_DEBUG((PeiServices, EFI_D_ERROR, "		 PCIEBadListWorkaround() - ======================>>>>Get Bad Device!\n"));
					PEI_DEBUG((PeiServices, EFI_D_ERROR, "		                         - VID: %04X DID: %04X\n", VendorId, DeviceId));
	
				 	switch(PCIEBadListDeviceTbl[i].PatchSolution){
					//case ForceGen2:
						//PCIEBadListForceSpeedPatch(PeiServices, NbConfig, PciAddress, PE_GEN2);
						//*PcieCap = PE_GEN2;
						//break;
	
					//case ForceDelay100ms:
						//PCIEBadListForceDelayPatch(PeiServices, NbConfig, PciAddress, 0x64);
						//break;
	
					case ForceSIAnlogSwitchInternal:	
						PCIEBadListTuneTxPowerSupply(PeiServices, NbConfig, PciAddress); 
						PEI_DEBUG((PeiServices, EFI_D_ERROR, "[JNY-DEBUG]PCIEBadListWorkaround() - Force SI Setting!\n"));
						break;
					case ForceX4:
						PCIEBadListForceX4Patch(PeiServices, NbConfig, PciAddress);
						break;
	                case ExtraPERST:
						PCIEBadListExtraPERSTPatch(PeiServices,NbConfig,PciAddress);
						break;
					case ForceGen1:
						PCIEBadListForceGenSpeedPatch(PeiServices,NbConfig,PciAddress,PE_GEN1);
						*PcieCap = PE_GEN1;	
						break;
					case UnsupportL1:
						PCIEBadListUnsupportL1Patch(PeiServices,NbConfig,PciAddress);
						break;
				 	default:
						break;
						
					}
					PEI_DEBUG((PeiServices, EFI_D_ERROR, "		 PCIEBadListWorkaround() - ======================<<<<Patch Done!\n"));
				}
			}

			if(!(BIT7 & AsiaPciRead16(AsiaPciAddress(SubBusNo, DevSearch, FuncSearch, 0xE)))){
				FuncSearch = 7; //if this is a single function device, skip all function 1-7 
			}
		}
	}
	
	AsiaPciWrite8(PciAddress |D3D5F1_SECONDARY_BUS_NUM, 00) ;
	AsiaPciWrite8(PciAddress |D3D5F1_SUBORDINATE_BUS_NUM, 00) ;
	
	return Status;
}


#endif
/******************************************************************************************End
//code for pcie patch
******************************************************************************************/



/**
   PCIE Common link status info function.
       This routine is for debugging
 	    this routing provide more message of pcie link

  @param  PeiServices	EFI_PEI_SERVICES pointer.
  @param  pNbConfig  point to ASIA_NB_CONFIGURATION
  @param PciAddress Target pcie device's address

  @return The value from this function.

**/

EFI_STATUS
PCIeCommonLinkStatus(	
	IN EFI_PEI_SERVICES **PeiServices,
	IN ASIA_NB_CONFIGURATION *NbConfig,
	IN UINT64 PcieAddr)
{
	EFI_STATUS Statusx = EFI_SUCCESS;
	UINT16 Vidx;
	UINT64 PcieBarx;
	UINT8 Busx,Devx,Funx;
	
	UINT8 CardPsnt = 0;
	UINT8 LinkLtssm = 0;

	UINT8 PcieLinkError = 100,PcieLinkError1 = 5;
	
	PcieBarx = NbConfig->PcieBar;

	Busx = (UINT8)(((UINT32)PcieAddr)>>24)&0xFF;
	Devx = (UINT8)(((UINT32)PcieAddr)>>16)&0x1F;
	Funx = (UINT8)(((UINT32)PcieAddr)>>8)&0x7;


	Vidx = AsiaPcieRead16(PcieBarx, PcieAddr|((UINT64)D3D5F1_VID << 32));
	if(Vidx == 0xFFFF){
		PEI_DEBUG((PeiServices, EFI_D_INFO, "[PCIE] Error:This Port Not Exist!\n",Vidx));
		Statusx = EFI_NOT_FOUND;
		return Statusx;
	}else{
		PEI_DEBUG((PeiServices, EFI_D_INFO, "[PCIE] [%d:%d.%d]_VID_%04x  -- LinkStatusCheck\n",Busx,Devx,Funx, Vidx));
	}


	//Get link status
	CardPsnt = D3D5F1_SPDCST & AsiaPcieRead8(PcieBarx, PcieAddr|((UINT64)D3D5F1_SLOT_STA_1 << 32));
	LinkLtssm = AsiaPcieRead8(PcieBarx, PcieAddr|((UINT64)D3D5F1_PHYLS_LTSSM_STATE << 32));


	if(CardPsnt){
		while(PcieLinkError--){
			LinkLtssm = AsiaPcieRead8(PcieBarx, PcieAddr|((UINT64)D3D5F1_PHYLS_LTSSM_STATE << 32));
			if(LinkLtssm != 0x8A){
				PeiNbPcieStall(PeiServices,1);	//delay 1ms
			}else{
				break;
			}
		}

		if(PcieLinkError == 0){  //report Error!
			PEI_DEBUG((PeiServices, EFI_D_ERROR, "[PCIE] PCIeCommonLinkStatus() - LTSSM not 0x8A \n"));
			while(PcieLinkError1--){
				AsiaIoWrite8(0x80,0xAB);
				PeiNbPcieStall(PeiServices,500);
				AsiaIoWrite8(0x80,0xBA);
				PeiNbPcieStall(PeiServices,500);
			}

		}
	}
	
	//dump PCIE link status
	PEI_DEBUG((PeiServices, EFI_D_INFO, "[PCIE] COM_CardPresent = 0x%02x\n", CardPsnt));  //Rx5A
#if 0				
	PEI_DEBUG((PeiServices, EFI_D_INFO, "       COM_LTSSM = %02x\n", LinkLtssm));  //Rx1C3
	
	PEI_DEBUG((PeiServices, EFI_D_INFO, "       COM_CurrentLinkWidth/Speed = 0x%02x\n",
				AsiaPcieRead8(PcieBarx, PcieAddr|((UINT64)D3D5F1_LINK_STA_1 << 32))	 ));  //Rx52

	PEI_DEBUG((PeiServices, EFI_D_INFO, "       CorError(Rx110) = 0x%08x\n",
				AsiaPcieRead32(PcieBarx, PcieAddr|((UINT64)D3D5F1_CORRECTABLE_ERR_STA << 32))	 ));  //Rx110
	PEI_DEBUG((PeiServices, EFI_D_INFO, "       UncorError(Rx104) = 0x%08x\n",
				AsiaPcieRead32(PcieBarx, PcieAddr|((UINT64)D3D5F1_UNCORRECTABLE_ERR_STA << 32))	 ));  //Rx104
#endif
	//Dump configure space for this port
	//PCIeDumpCfg(PeiServices,PcieBarx,Busx,Devx,Funx,0x300);


	if(CardPsnt){
		LinkLtssm = AsiaPcieRead8(PcieBarx, PcieAddr|((UINT64)D3D5F1_PHYLS_LTSSM_STATE << 32));
		if(LinkLtssm != 0x8A){
			PEI_DEBUG((PeiServices, EFI_D_INFO, "[CJWx_2018] ERROR:LTSSM=%02xh  ",
									LinkLtssm )); 
			PEI_DEBUG((PeiServices, EFI_D_INFO, " CJWy_%d:%d.%d ",
									0xFF&((UINT8)RShiftU64(PcieAddr,24)), 
									0xFF&((UINT8)RShiftU64(PcieAddr,16)),
									0xFF&((UINT8)RShiftU64(PcieAddr,8))  ));
			PEI_DEBUG((PeiServices, EFI_D_INFO, " CxErr:%08x, UCxErr:%08x, ",
									AsiaPcieRead32(PcieBarx, PcieAddr|((UINT64)D3D5F1_CORRECTABLE_ERR_STA << 32)),
									AsiaPcieRead32(PcieBarx, PcieAddr|((UINT64)D3D5F1_UNCORRECTABLE_ERR_STA << 32))  ));
			PEI_DEBUG((PeiServices, EFI_D_INFO, " Rx52=%02xh ",AsiaPcieRead8(PcieBarx, PcieAddr|((UINT64)D3D5F1_LINK_STA_1 << 32))  ));
			PEI_DEBUG((PeiServices, EFI_D_INFO, " Rx70=%02xh ",AsiaPcieRead8(PcieBarx, PcieAddr|((UINT64)D3D5F1_LINK_CTL_2_D4F0 << 32))  ));
			PEI_DEBUG((PeiServices, EFI_D_INFO, " - Fail!\n"));

		}else{
			PEI_DEBUG((PeiServices, EFI_D_INFO, "[CJWz_2018] ERROR:LTSSM=%02xh  ",
									LinkLtssm )); 
			PEI_DEBUG((PeiServices, EFI_D_INFO, " CJWy_%d:%d.%d ",
									0xFF&((UINT8)RShiftU64(PcieAddr,24)), 
									0xFF&((UINT8)RShiftU64(PcieAddr,16)),
									0xFF&((UINT8)RShiftU64(PcieAddr,8))  ));
			PEI_DEBUG((PeiServices, EFI_D_INFO, " CxErr:%08x, UCxErr:%08x, ",
									AsiaPcieRead32(PcieBarx, PcieAddr|((UINT64)D3D5F1_CORRECTABLE_ERR_STA << 32)),
									AsiaPcieRead32(PcieBarx, PcieAddr|((UINT64)D3D5F1_UNCORRECTABLE_ERR_STA << 32))  ));
			PEI_DEBUG((PeiServices, EFI_D_INFO, " Rx52=%02xh ",AsiaPcieRead8(PcieBarx, PcieAddr|((UINT64)D3D5F1_LINK_STA_1 << 32))  ));
			PEI_DEBUG((PeiServices, EFI_D_INFO, " - Pass!\n"));
		}
				

	}



	return Statusx;
}

/**
   Use this function to search register offset of Specific capability.
   
   Param:
   Busx,Devx,Funx: device routing ID
   PcieCap: when 1, search PCIE capability, when 0,search PCI capability
   CapId: target capability ID

  @param  PeiServices	EFI_PEI_SERVICES pointer.
  @param  pNbConfig  point to ASIA_NB_CONFIGURATION
  @param Busx Target pcie device's address
  @param Devx Target pcie device's address
  @param Funx Target pcie device's address
  @param PcieCap
  @param CapId
  @param pOffset register offset of target capability 

  @return Offset: register offset of target capability
               EFI_STATUS Search result.
               when EFI_NOT_FOUND, not found capability.
		when EFI_DEVICE_ERROR, device register abnormal.

**/

EFI_STATUS
PCIeSearchCapOffset(
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
   This function will get Link Speed Cap of Bus1 D0F0 

  @Special Note:
	  before call this function, need to confirm the target device 
	  must can be accessed; genernally, we need to do temp 
	  assignment for a RP firstly. 
  @Special Note2: 
	  this function can used for RP only!

  @param  PeiServices	EFI_PEI_SERVICES pointer.
  @param  pNbConfig  point to ASIA_NB_CONFIGURATION
  @param PciAddress Target pcie device's address

  @return The value from this function.

**/

EFI_STATUS
PCIeCommonDevCapProbe(
	IN EFI_PEI_SERVICES **PeiServices,
	IN ASIA_NB_CONFIGURATION *NbConfig,
	IN UINT64 PcieAddr,
	IN OUT UINT8 *DevCap)
{
    UINT8 VBus = 0,VDev = 0,VFun = 0;
	UINT64 VPcieBar = 0;
	UINT16 PcieCapOff = 0;
	EFI_STATUS Statusx = EFI_SUCCESS;
	UINT8 DevCapLocal = 0xF;

	VFun = 0x7 & RShiftU64(PcieAddr,8);
	VDev = 0x1F & RShiftU64(PcieAddr,16);
	VBus = 0xFF & RShiftU64(PcieAddr,24);
	
	VPcieBar = NbConfig->PcieBar;

	//Search PCI Express Capability
	Statusx = PCIeSearchCapOffset(PeiServices,NbConfig,1,0,0,
						0,0x10,&PcieCapOff);

	PEI_DEBUG((PeiServices, EFI_D_ERROR, "		!!!!!!!!!!!PcieCapOff(0x%x)!\n",PcieCapOff));	
	if(Statusx == EFI_SUCCESS){
		//Found PCI Express Capability, then to read MaxLinkSpeed Capability
		DevCapLocal = (0xF & AsiaPcieRead8(NbConfig->PcieBar,AsiaPciAddress(1,0,0,PcieCapOff+0x0C)));
	}
	PEI_DEBUG((PeiServices, EFI_D_ERROR, "		!!!!!!!!!!!DevCapLocal(0x%x)!\n",DevCapLocal));	
	*DevCap = DevCapLocal;
	return Statusx;
}





/**
@



#ifdef ZX_DUALSOCKET

#endif
**/
//for NbConfig->PcieCrsMech
#define PCIE_CRS_SW_VISABLE 0 
#define PCIE_CRS_HW_RETRY 1
#define PCIE_CRS_CPL_AS_ALL_FF 2

/**
   PCIE Common CRS Strategy function.
   This function set the CRS implement mechanism

//;Enable CRS SW Visibility Mechanism
// TruthTable  --- CJW_20180118
// Rx1A9   Rx5E(need backdoor)		Rx5C				Result
//		   CRS SW vis cap			CRS SW vis en
//	0		x						x				--> ignore CRS, return FF, ZX implementation 
//	1		0						x				--> will wait for 'Cpl without CRS'  
//	1		1						1				--> will wait for 'Cpl without CRS'  &&  CRS SW visable(Read VID = 0001h)

-->SW Visable (default)  - PCIE_CRS_SW_VISABLE
-->HW Retry   - PCIE_CRS_HW_RETRY
-->CRS Cpl as All FF   - PCIE_CRS_CPL_AS_ALL_FF

  @Special Note: 
  for CRS implement Strategy, Master and Slave socket will use the uniqe SETUP item,
  this means master and slave can't set separately
  

  @param  PeiServices	EFI_PEI_SERVICES pointer.
  @param  pNbConfig  point to ASIA_NB_CONFIGURATION
  @param PciAddress Target pcie device's address

  @return The value from this function.

**/
EFI_STATUS
PCIeCommonCrsStrategy(
	IN EFI_PEI_SERVICES **PeiServices,
	IN ASIA_NB_CONFIGURATION *NbConfig,
	IN UINT64 PcieAddr)
{
	UINT8 VPcieCrsMech = 0xFF;
	UINT64 VPcieBar = 0xFFFFFFFF;

	VPcieCrsMech = NbConfig->PcieCrsMech;
	VPcieBar = NbConfig->PcieBar;

	//
	//Open Backdoor
	//
	AsiaPcieModify8(VPcieBar, CHX002_APIC|((UINT64)D0F5_PMU_CTL << 32), D0F5_RPEROWEN, D0F5_RPEROWEN);
#ifdef ZX_DUALSOCKET
	AsiaPcieModify8(VPcieBar, CHX002_APIC_SLAVE|((UINT64)D0F5_PMU_CTL << 32), D0F5_RPEROWEN, D0F5_RPEROWEN);
#endif

	//
	//Setting for CRS
	//
	if(VPcieCrsMech == PCIE_CRS_CPL_AS_ALL_FF){
		//Rx1A9[0] = 0
		AsiaPcieModify8(VPcieBar, PcieAddr|((UINT64)D3D5F1_CRS_RETRY_CTL << 32), D3D5F1_RRTYCRSEN, 0);
	}else{
		//Rx1A9[0] = 1
		AsiaPcieModify8(VPcieBar, PcieAddr|((UINT64)D3D5F1_CRS_RETRY_CTL << 32), D3D5F1_RRTYCRSEN, D3D5F1_RRTYCRSEN);

		if(VPcieCrsMech == PCIE_CRS_HW_RETRY){
			//Rx5E[0] = 0
			AsiaPcieModify8(VPcieBar, PcieAddr|((UINT64)D3D5F1_ROOT_CAPS << 32), D3D5F1_RSCRSSFV, 0);
		}else{  
			//Rx5E[0] = 1
			AsiaPcieModify8(VPcieBar, PcieAddr|((UINT64)D3D5F1_ROOT_CAPS << 32), D3D5F1_RSCRSSFV, D3D5F1_RSCRSSFV);
			//Rx5C[4] = 1 
			AsiaPcieModify8(VPcieBar, PcieAddr|((UINT64)D3D5F1_ROOT_CTL << 32), D3D5F1_RCCRSSVE, D3D5F1_RCCRSSVE);
			
		}
	}
	
	//
	//Close backdoor
	//
	AsiaPcieModify8(VPcieBar, CHX002_APIC|((UINT64)D0F5_PMU_CTL << 32), D0F5_RPEROWEN, 0x00);
#ifdef ZX_DUALSOCKET
		AsiaPcieModify8(VPcieBar, CHX002_APIC_SLAVE|((UINT64)D0F5_PMU_CTL << 32), D0F5_RPEROWEN, 0x00);
#endif


	return EFI_SUCCESS;
}

/**
  This function will be called to handle CRS cpl received by RP
  
  @Note1: 
	  if we not set Primary/Secondary/Subordinate bus number before, 
	  we must keep those fields(Rx18/19/1A) as 00h
  @Note2:
	  before call this function, need to check PCIE link LTSSM, Link 
	  should get L0 before run here

  @param  PeiServices	EFI_PEI_SERVICES pointer.
  @param  pNbConfig  point to ASIA_NB_CONFIGURATION
  @param PciAddress Target pcie device's address

  @return The value from this function.

**/



EFI_STATUS
PCIeCommonASPMEnable(	
	IN EFI_PEI_SERVICES **PeiServices,
	IN ASIA_NB_CONFIGURATION *NbConfig,
	IN UINT64 PcieAddr)
{
	EFI_STATUS Statusx = EFI_SUCCESS;
	//ASPM supported field modify
	if((NbConfig->PcieASPM)||(NbConfig->PcieASPMBootArch)){
		//open backdoor
		AsiaPcieModify8(NbConfig->PcieBar, CHX002_APIC|((UINT64)D0F5_PMU_CTL << 32), D0F5_RPEROWEN, D0F5_RPEROWEN);
		//enable support bit
		AsiaPcieModify16(NbConfig->PcieBar, PcieAddr|((UINT64)D3D5F1_LINK_CAPS_1_D4F0 << 32), D3D5F1_LKAPMS,D3D5F1_LKAPMS);
		//close backdoor
		AsiaPcieModify8(NbConfig->PcieBar, CHX002_APIC|((UINT64)D0F5_PMU_CTL << 32), D0F5_RPEROWEN, 0);
	}else{
		Statusx = EFI_NOT_FOUND;
		PEI_DEBUG((PeiServices, EFI_D_ERROR, "       ASPM Support [Disable]"));
	}
	PEI_DEBUG((PeiServices, EFI_D_ERROR, "       Rx4C = %04Xh ([11:10]ASPM Support Field)\n",
												AsiaPciRead16(PcieAddr |D3D5F1_LINK_CAPS_1_D4F0)));
	return Statusx;
}

/**
   this funtion used to enable ASPM for PCIE
  Note: we need to enable support bit to 11h 
  instead of the formal value of 00h

  @param  PeiServices	EFI_PEI_SERVICES pointer.
  @param  pNbConfig  point to ASIA_NB_CONFIGURATION
  @param  PciAddress Target pcie device's address 

  @return The value from this function.

**/






EFI_STATUS
PCIeCommonCrsHandle(
	IN EFI_PEI_SERVICES **PeiServices,
	IN ASIA_NB_CONFIGURATION *NbConfig,
	IN UINT64 PcieAddr)
{

    UINT8 VBus = 0,VDev = 0,VFun = 0;
	UINT64 VPcieBar = 0;
	UINT8 V18 = 0,V19 = 0,V1a = 0;
	UINT8 SecondaryBusNum;
	UINT8 VPcieCrsMech;
	UINT16 VidReadBack = 0xFFFF;
	UINT16 DidReadBack = 0x0000;
	UINT16 TimeoutCounter = 0;
	UINT8 SlotPrsnt = 0;
	EFI_STATUS Statusx = EFI_SUCCESS;
	
	VFun = 0x7 & RShiftU64(PcieAddr,8);
	VDev = 0x1F & RShiftU64(PcieAddr,16);
	VBus = 0xFF & RShiftU64(PcieAddr,24);
	VPcieBar = NbConfig->PcieBar;
	VPcieCrsMech = NbConfig->PcieCrsMech;

	PEI_DEBUG((PeiServices, EFI_D_ERROR, "[PCIE_CRS] (%d:%d.%d)\n",VBus,VDev,VFun));

	//to see whether port exist?
	VidReadBack = AsiaPcieRead16(VPcieBar,PcieAddr|((UINT64)D3D5F1_VID << 32));
	if(VidReadBack == 0xFFFF){
		PEI_DEBUG((PeiServices, EFI_D_ERROR, "[PCIE_CRS] this port not exist, exit\n"));
		Statusx = EFI_UNSUPPORTED;
		goto __HandleCrsExit;
	}

	//to see whether card exist?
	SlotPrsnt = (D3D5F1_SPDCST & AsiaPcieRead8(VPcieBar,PcieAddr|((UINT64)D3D5F1_SLOT_STA_1 << 32)));
	if(!SlotPrsnt){
		PEI_DEBUG((PeiServices, EFI_D_ERROR, "[PCIE_CRS] no device detected, exit\n"));
		Statusx = EFI_NOT_FOUND;
		goto __HandleCrsExit;
	}
	
	PEI_DEBUG((PeiServices, EFI_D_ERROR, "[PCIE_CRS] port exist:\n"));
	V18 = AsiaPcieRead8(VPcieBar,PcieAddr|((UINT64)D3D5F1_PRIMARY_BUS_NUM << 32));
	V19 = AsiaPcieRead8(VPcieBar,PcieAddr|((UINT64)D3D5F1_SECONDARY_BUS_NUM << 32));
	V1a = AsiaPcieRead8(VPcieBar,PcieAddr|((UINT64)D3D5F1_SUBORDINATE_BUS_NUM << 32));
	
	//to check whether port not initialized?
	SecondaryBusNum = V19;
	if(SecondaryBusNum == 0){
		//Assign a temp bus resource to this bridge
		AsiaPcieModify8(VPcieBar,PcieAddr|((UINT64)D3D5F1_PRIMARY_BUS_NUM),0xFF,0x0);		
		AsiaPcieModify8(VPcieBar,PcieAddr|((UINT64)D3D5F1_SECONDARY_BUS_NUM),0xFF,0x1);
		AsiaPcieModify8(VPcieBar,PcieAddr|((UINT64)D3D5F1_SUBORDINATE_BUS_NUM),0xFF,0x1);

		switch(VPcieCrsMech){
			case PCIE_CRS_SW_VISABLE:
				VidReadBack = AsiaPcieRead16(VPcieBar,AsiaPciAddress(1,0,0,0));
				DidReadBack = AsiaPcieRead16(VPcieBar,AsiaPciAddress(1,0,0,2));
				while(VidReadBack == 0x0001){
					TimeoutCounter++;
					if(TimeoutCounter >=2000){
						PEI_DEBUG((PeiServices, EFI_D_ERROR, "           ERROR! CRS 2s Timeout(0001h)!\n"));
						Statusx = EFI_TIMEOUT;
						break;
					}
					PeiNbPcieStall(PeiServices,1); //1ms
					VidReadBack = AsiaPcieRead16(VPcieBar,AsiaPciAddress(1,0,0,0));
					DidReadBack = AsiaPcieRead16(VPcieBar,AsiaPciAddress(1,0,0,2));
				}
				if(VidReadBack == 0xFFFF){
					PEI_DEBUG((PeiServices, EFI_D_ERROR, "           ERROR! device broken? \n"));
					Statusx = EFI_DEVICE_ERROR;
				}
				break;
			case PCIE_CRS_HW_RETRY:
				VidReadBack = AsiaPcieRead16(VPcieBar,AsiaPciAddress(1,0,0,0));
				while(VidReadBack == 0xFFFF){
					TimeoutCounter++;
					if(TimeoutCounter >= 20){
						PEI_DEBUG((PeiServices, EFI_D_ERROR, "           ERROR! CRS 20 loops Timeout(HW Retry)!\n"));
						Statusx = EFI_TIMEOUT;
						break;						
					}
					VidReadBack = AsiaPcieRead16(VPcieBar,AsiaPciAddress(1,0,0,0));
				}				
				break;
			case PCIE_CRS_CPL_AS_ALL_FF:
				VidReadBack = AsiaPcieRead16(VPcieBar,AsiaPciAddress(1,0,0,0));
				while(VidReadBack == 0xFFFF){
					TimeoutCounter++;
					if(TimeoutCounter >= 500){
						PEI_DEBUG((PeiServices, EFI_D_ERROR, "           ERROR! CRS 2s Timeout(FFFF)!\n"));
						Statusx = EFI_TIMEOUT;
						break;
					}
					PeiNbPcieStall(PeiServices,1); //1ms
					VidReadBack = AsiaPcieRead16(VPcieBar,AsiaPciAddress(1,0,0,0));
				}				
				break;
		
			default:
				PEI_DEBUG((PeiServices, EFI_D_ERROR, "           ERROR! Unkonwn CRS Mech!\n"));
				break;
		}

		PEI_DEBUG((PeiServices, EFI_D_ERROR, "			 found device VID=%04x under (%d:%d.%d)\n",
													VidReadBack,VBus,VDev,VFun));		


		//New Mech:
		//If device not ready, we not to check Capability of this device
		//otherwise, we need to report the Optimal Target Link Speed
		if((VidReadBack != 0xFFFF)&&(VidReadBack != 0x0001)){
			switch(PcieAddr){
				case CHX002_PE0:
					PCIeCommonDevCapProbe(PeiServices,NbConfig,PcieAddr,&(NbConfig->PcieDevCapPE0));
					PEI_DEBUG((PeiServices, EFI_D_ERROR, "		!!!!!!!!!!!NbConfig->PcieDevCapPE0(0x%x)!\n",NbConfig->PcieDevCapPE0));
					break;
				case CHX002_PE1:
					PCIeCommonDevCapProbe(PeiServices,NbConfig,PcieAddr,&(NbConfig->PcieDevCapPE1));
					break;
				case CHX002_PE2:
					PCIeCommonDevCapProbe(PeiServices,NbConfig,PcieAddr,&(NbConfig->PcieDevCapPE2));
					break;
				case CHX002_PE3:
					PCIeCommonDevCapProbe(PeiServices,NbConfig,PcieAddr,&(NbConfig->PcieDevCapPE3));
					break;
				case CHX002_PE4:
					PCIeCommonDevCapProbe(PeiServices,NbConfig,PcieAddr,&(NbConfig->PcieDevCapPE4));
					break;
				case CHX002_PE5:
					PCIeCommonDevCapProbe(PeiServices,NbConfig,PcieAddr,&(NbConfig->PcieDevCapPE5));
					break;
				case CHX002_PE6:
					PCIeCommonDevCapProbe(PeiServices,NbConfig,PcieAddr,&(NbConfig->PcieDevCapPE6));
					break;
				case CHX002_PE7:
					PCIeCommonDevCapProbe(PeiServices,NbConfig,PcieAddr,&(NbConfig->PcieDevCapPE7));
					break;
#ifdef ZX_DUALSOCKET 				
				case CHX002_PE0_SLAVE:
					PCIeCommonDevCapProbe(PeiServices,NbConfig,PcieAddr,&(NbConfig->PcieDevCapPE0Slave));
					break;
				case CHX002_PE1_SLAVE:
					PCIeCommonDevCapProbe(PeiServices,NbConfig,PcieAddr,&(NbConfig->PcieDevCapPE1Slave));
					break;
				case CHX002_PE2_SLAVE:
					PCIeCommonDevCapProbe(PeiServices,NbConfig,PcieAddr,&(NbConfig->PcieDevCapPE2Slave));
					break;
				case CHX002_PE3_SLAVE:
					PCIeCommonDevCapProbe(PeiServices,NbConfig,PcieAddr,&(NbConfig->PcieDevCapPE3Slave));
					break;
				case CHX002_PE4_SLAVE:
					PCIeCommonDevCapProbe(PeiServices,NbConfig,PcieAddr,&(NbConfig->PcieDevCapPE4Slave));
					break;
				case CHX002_PE5_SLAVE:
					PCIeCommonDevCapProbe(PeiServices,NbConfig,PcieAddr,&(NbConfig->PcieDevCapPE5Slave));
					break;
				case CHX002_PE6_SLAVE:
					PCIeCommonDevCapProbe(PeiServices,NbConfig,PcieAddr,&(NbConfig->PcieDevCapPE6Slave));
					break;
				case CHX002_PE7_SLAVE:
					PCIeCommonDevCapProbe(PeiServices,NbConfig,PcieAddr,&(NbConfig->PcieDevCapPE7Slave));
					break;
#endif
				default:
					break;

			}

	
		}
		
		//clear the temp assignment for this bridge
		AsiaPcieModify8(VPcieBar,PcieAddr|((UINT64)D3D5F1_PRIMARY_BUS_NUM),0xFF,0x0);
		AsiaPcieModify8(VPcieBar,PcieAddr|((UINT64)D3D5F1_SECONDARY_BUS_NUM),0xFF,0x0);
		AsiaPcieModify8(VPcieBar,PcieAddr|((UINT64)D3D5F1_SUBORDINATE_BUS_NUM),0xFF,0x0);

		
	}else{
		PEI_DEBUG((PeiServices, EFI_D_INFO, "[PCIE_CRS] ERROR! PCIeCommonCrsHandle() not running correctly! \n"));
		
	}

__HandleCrsExit:
	

	return Statusx;	
}


/**
   this funtion used to set SPE mode for PCIE
  Note: Master socket and Slave socket will use one 
		  SPE table and use one SPE setup

  @param  PeiServices	EFI_PEI_SERVICES pointer.
  @param  pNbConfig  point to ASIA_NB_CONFIGURATION
  @param CodeFlag 

  @return The value from this function.

**/

EFI_STATUS
PCIeCommonSpeSetting(
	IN EFI_PEI_SERVICES **PeiServices,
	IN ASIA_NB_CONFIGURATION *NbConfig,
	IN UINT8 CodeFlag)
{

	switch(NbConfig->NBSPEValue) {
	case CHIP_SPE_VALUE_MANUAL:
		break;
	case CHIP_SPE_VALUE_PERFORMANCE:
		NbConfig->D3F0SPEValue = DEVICE_SPE_VALUE_PERFORMANCE;
		NbConfig->D3F1SPEValue = DEVICE_SPE_VALUE_PERFORMANCE;
		NbConfig->D3F2SPEValue = DEVICE_SPE_VALUE_PERFORMANCE;
		NbConfig->D3F3SPEValue = DEVICE_SPE_VALUE_PERFORMANCE;
		NbConfig->D4F0SPEValue = DEVICE_SPE_VALUE_PERFORMANCE;
		NbConfig->D4F1SPEValue = DEVICE_SPE_VALUE_PERFORMANCE;
		NbConfig->D5F0SPEValue = DEVICE_SPE_VALUE_PERFORMANCE;
		NbConfig->D5F1SPEValue = DEVICE_SPE_VALUE_PERFORMANCE;
		NbConfig->RCRBHSPEValue = DEVICE_SPE_VALUE_PERFORMANCE;
		break;
	case CHIP_SPE_VALUE_ENERGY:
		NbConfig->D3F0SPEValue = DEVICE_SPE_VALUE_ENERGY;
		NbConfig->D3F1SPEValue = DEVICE_SPE_VALUE_ENERGY;
		NbConfig->D3F2SPEValue = DEVICE_SPE_VALUE_ENERGY;
		NbConfig->D3F3SPEValue = DEVICE_SPE_VALUE_ENERGY;
		NbConfig->D4F0SPEValue = DEVICE_SPE_VALUE_ENERGY;
		NbConfig->D4F1SPEValue = DEVICE_SPE_VALUE_ENERGY;
		NbConfig->D5F0SPEValue = DEVICE_SPE_VALUE_ENERGY;
		NbConfig->D5F1SPEValue = DEVICE_SPE_VALUE_ENERGY;
		NbConfig->RCRBHSPEValue = DEVICE_SPE_VALUE_ENERGY;
		break;
	case CHIP_SPE_VALUE_STABLE:
	default:
		NbConfig->D3F0SPEValue = DEVICE_SPE_VALUE_STABLE;
		NbConfig->D3F1SPEValue = DEVICE_SPE_VALUE_STABLE;
		NbConfig->D3F2SPEValue = DEVICE_SPE_VALUE_STABLE;
		NbConfig->D3F3SPEValue = DEVICE_SPE_VALUE_STABLE;
		NbConfig->D4F0SPEValue = DEVICE_SPE_VALUE_STABLE;
		NbConfig->D4F1SPEValue = DEVICE_SPE_VALUE_STABLE;
		NbConfig->D5F0SPEValue = DEVICE_SPE_VALUE_STABLE;
		NbConfig->D5F1SPEValue = DEVICE_SPE_VALUE_STABLE;
		NbConfig->RCRBHSPEValue = DEVICE_SPE_VALUE_STABLE;
		break;
	}
	


	if(CodeFlag == PCIE_CF_M){
/*+ DSZ_Porting (ALN-2017081701) Set to E mode before root port release link.*/ 
		if(NbConfig->PcieRP) {
			// PCIE Processing
			if(NbConfig->PciePE0) {
				if(NbConfig->D3F0SPEValue >= DEVICE_SPE_VALUE_PERFORMANCE) {		
					PROCESS_NB_PCIE_R6432M_TABLE(NbConfig->PcieBar, D3F0PerformanceMMIOTBL, sizeof(D3F0PerformanceMMIOTBL)/sizeof(ASIA_IO_TABLE_6432_REV));
					if(NbConfig->D3F0SPEValue == DEVICE_SPE_VALUE_ENERGY) {
					PROCESS_NB_PCIE_R6432M_TABLE(NbConfig->PcieBar, D3F0EnergyMMIOTBL, sizeof(D3F0EnergyMMIOTBL)/sizeof(ASIA_IO_TABLE_6432_REV));
					}
				}
			}
		
			if(NbConfig->PciePE1) {
				if(NbConfig->D3F1SPEValue >= DEVICE_SPE_VALUE_PERFORMANCE) {
					PROCESS_NB_PCIE_R6432M_TABLE(NbConfig->PcieBar, D3F1PerformanceMMIOTBL, sizeof(D3F1PerformanceMMIOTBL)/sizeof(ASIA_IO_TABLE_6432_REV));
					if(NbConfig->D3F1SPEValue == DEVICE_SPE_VALUE_ENERGY) {
					PROCESS_NB_PCIE_R6432M_TABLE(NbConfig->PcieBar, D3F1EnergyMMIOTBL, sizeof(D3F1EnergyMMIOTBL)/sizeof(ASIA_IO_TABLE_6432_REV));
					}
				}
			}
		
			if(NbConfig->PciePE2) {
				if(NbConfig->D3F2SPEValue >= DEVICE_SPE_VALUE_PERFORMANCE) {
					PROCESS_NB_PCIE_R6432M_TABLE(NbConfig->PcieBar, D3F2PerformanceMMIOTBL, sizeof(D3F2PerformanceMMIOTBL)/sizeof(ASIA_IO_TABLE_6432_REV));
					if(NbConfig->D3F2SPEValue == DEVICE_SPE_VALUE_ENERGY) {
						PROCESS_NB_PCIE_R6432M_TABLE(NbConfig->PcieBar, D3F2EnergyMMIOTBL, sizeof(D3F2EnergyMMIOTBL)/sizeof(ASIA_IO_TABLE_6432_REV));
					}
				} 
			}
		
			if(NbConfig->PciePE3) {
				if(NbConfig->D3F3SPEValue >= DEVICE_SPE_VALUE_PERFORMANCE) {
					PROCESS_NB_PCIE_R6432M_TABLE(NbConfig->PcieBar, D3F3PerformanceMMIOTBL, sizeof(D3F3PerformanceMMIOTBL)/sizeof(ASIA_IO_TABLE_6432_REV)); 
					if(NbConfig->D3F3SPEValue == DEVICE_SPE_VALUE_ENERGY) {
						PROCESS_NB_PCIE_R6432M_TABLE(NbConfig->PcieBar, D3F3EnergyMMIOTBL, sizeof(D3F3EnergyMMIOTBL)/sizeof(ASIA_IO_TABLE_6432_REV));
					}
				}
			}
		
			if(NbConfig->PciePE4) {
				if(NbConfig->D4F0SPEValue >= DEVICE_SPE_VALUE_PERFORMANCE) {
					PROCESS_NB_PCIE_R6432M_TABLE(NbConfig->PcieBar, D4F0PerformanceMMIOTBL, sizeof(D4F0PerformanceMMIOTBL)/sizeof(ASIA_IO_TABLE_6432_REV));
					if(NbConfig->D4F0SPEValue == DEVICE_SPE_VALUE_ENERGY) {
						PROCESS_NB_PCIE_R6432M_TABLE(NbConfig->PcieBar, D4F0EnergyMMIOTBL, sizeof(D4F0EnergyMMIOTBL)/sizeof(ASIA_IO_TABLE_6432_REV));
					}
				}
			}
			
		
			if(NbConfig->PciePE5) {
				if(NbConfig->D4F1SPEValue >= DEVICE_SPE_VALUE_PERFORMANCE) {
					PROCESS_NB_PCIE_R6432M_TABLE(NbConfig->PcieBar, D4F1PerformanceMMIOTBL, sizeof(D4F1PerformanceMMIOTBL)/sizeof(ASIA_IO_TABLE_6432_REV));
					if(NbConfig->D4F1SPEValue == DEVICE_SPE_VALUE_ENERGY) {
						PROCESS_NB_PCIE_R6432M_TABLE(NbConfig->PcieBar, D4F1EnergyMMIOTBL, sizeof(D4F1EnergyMMIOTBL)/sizeof(ASIA_IO_TABLE_6432_REV));
					}
				}
			}
		
			if(NbConfig->PciePE6) {
				if(NbConfig->D5F0SPEValue >= DEVICE_SPE_VALUE_PERFORMANCE) {
					PROCESS_NB_PCIE_R6432M_TABLE(NbConfig->PcieBar, D5F0PerformanceMMIOTBL, sizeof(D5F0PerformanceMMIOTBL)/sizeof(ASIA_IO_TABLE_6432_REV));
					if(NbConfig->D5F0SPEValue == DEVICE_SPE_VALUE_ENERGY) {
						PROCESS_NB_PCIE_R6432M_TABLE(NbConfig->PcieBar, D5F0EnergyMMIOTBL, sizeof(D5F0EnergyMMIOTBL)/sizeof(ASIA_IO_TABLE_6432_REV));
					}
				}
			}
			
			if(NbConfig->PciePE7) {
				if(NbConfig->D5F1SPEValue >= DEVICE_SPE_VALUE_PERFORMANCE) {
					PROCESS_NB_PCIE_R6432M_TABLE(NbConfig->PcieBar, D5F1PerformanceMMIOTBL, sizeof(D5F1PerformanceMMIOTBL)/sizeof(ASIA_IO_TABLE_6432_REV));
					if(NbConfig->D5F1SPEValue == DEVICE_SPE_VALUE_ENERGY) {
						PROCESS_NB_PCIE_R6432M_TABLE(NbConfig->PcieBar, D5F1EnergyMMIOTBL, sizeof(D5F1EnergyMMIOTBL)/sizeof(ASIA_IO_TABLE_6432_REV));
					}
				}
			}
			
			PEI_PCIE_NB_80_PORT(PeiServices, DXE_NB_PCIE_D3D5F1_SPE);	 //add by jenny 20170413
			if(NbConfig->RCRBHSPEValue) {
				if(NbConfig->RCRBHSPEValue >= DEVICE_SPE_VALUE_PERFORMANCE) {
		
					  UINT8 nBrEvIsion = (ASIA_NB_REVISION);
					  UINT32 tAbLeIdx, JdbgValue; 
					  UINT64 JdbgAddr;
		
					  for(tAbLeIdx = 0; tAbLeIdx < (sizeof(RCRBHPerformanceMMIOTBL)/sizeof(ASIA_IO_TABLE_6432_REV)); tAbLeIdx++) 
					  { 
						if((nBrEvIsion) > (RCRBHPerformanceMMIOTBL)[tAbLeIdx].RevisionMax || (nBrEvIsion) < (RCRBHPerformanceMMIOTBL)[tAbLeIdx].RevisionMin) 
						  continue; 
						AsiaMemoryModify32(NbConfig->RcrbhBar |(RCRBHPerformanceMMIOTBL)[tAbLeIdx].Address, (RCRBHPerformanceMMIOTBL)[tAbLeIdx].Mask, (RCRBHPerformanceMMIOTBL)[tAbLeIdx].Value); 
						JdbgAddr=NbConfig->RcrbhBar |(RCRBHPerformanceMMIOTBL)[tAbLeIdx].Address;
						JdbgValue=AsiaMemoryRead32(NbConfig->RcrbhBar |(RCRBHPerformanceMMIOTBL)[tAbLeIdx].Address);
						PEI_DEBUG((PeiServices, EFI_D_ERROR|EFI_D_INFO, "Pmode - RCRB-H Addr=0%x Value=0%x \n",JdbgAddr, JdbgValue));
					  } 
					if(NbConfig->RCRBHSPEValue == DEVICE_SPE_VALUE_ENERGY) {
						  for(tAbLeIdx = 0; tAbLeIdx < (sizeof(RCRBHEnergyMMIOTBL)/sizeof(ASIA_IO_TABLE_6432_REV)); tAbLeIdx++) 
						  { 
							if((nBrEvIsion) > (RCRBHEnergyMMIOTBL)[tAbLeIdx].RevisionMax || (nBrEvIsion) < (RCRBHEnergyMMIOTBL)[tAbLeIdx].RevisionMin) 
							  continue; 
							AsiaMemoryModify32(NbConfig->RcrbhBar |(RCRBHEnergyMMIOTBL)[tAbLeIdx].Address, (RCRBHEnergyMMIOTBL)[tAbLeIdx].Mask, (RCRBHEnergyMMIOTBL)[tAbLeIdx].Value); 
							JdbgAddr=NbConfig->RcrbhBar |(RCRBHEnergyMMIOTBL)[tAbLeIdx].Address;
							JdbgValue=AsiaMemoryRead32(NbConfig->RcrbhBar |(RCRBHEnergyMMIOTBL)[tAbLeIdx].Address);
							PEI_DEBUG((PeiServices, EFI_D_ERROR|EFI_D_INFO, "Emode - RCRB-H Addr=0%x Value=0%x \n",JdbgAddr, JdbgValue));
						  } 
					}
				} 
		   }
		
		   PEI_PCIE_NB_80_PORT(PeiServices, DXE_NB_PCIE_RCRB_SPE);	  //add by jenny 20170413
		   if(NbConfig->PCIEEPHYSPEValue) {
				if(NbConfig->PCIEEPHYSPEValue >= DEVICE_SPE_VALUE_PERFORMANCE) {
		
					  UINT8 nBrEvIsion = (ASIA_NB_REVISION);
					  UINT32 tAbLeIdx, JdbgValue; 
					  UINT64 JdbgAddr;
		
					  for(tAbLeIdx = 0; tAbLeIdx < (sizeof(PCIEEPHYPerformanceMMIOTBL)/sizeof(ASIA_IO_TABLE_6432_REV)); tAbLeIdx++) 
					  { 
						  if((nBrEvIsion) > (PCIEEPHYPerformanceMMIOTBL)[tAbLeIdx].RevisionMax || (nBrEvIsion) < (PCIEEPHYPerformanceMMIOTBL)[tAbLeIdx].RevisionMin) 
						  continue; 
						  AsiaMemoryModify32(NbConfig->PcieEPHYBar |(PCIEEPHYPerformanceMMIOTBL)[tAbLeIdx].Address, (PCIEEPHYPerformanceMMIOTBL)[tAbLeIdx].Mask, (PCIEEPHYPerformanceMMIOTBL)[tAbLeIdx].Value); 
						  JdbgAddr=NbConfig->PcieEPHYBar |(PCIEEPHYPerformanceMMIOTBL)[tAbLeIdx].Address;
						  JdbgValue=AsiaMemoryRead32(NbConfig->PcieEPHYBar |(PCIEEPHYPerformanceMMIOTBL)[tAbLeIdx].Address);
						  PEI_DEBUG((PeiServices, EFI_D_ERROR|EFI_D_INFO, "Pmode - PCIE-EPHY Addr=0%x Value=0%x \n",JdbgAddr, JdbgValue));
					  } 
					  if(NbConfig->PCIEEPHYSPEValue == DEVICE_SPE_VALUE_ENERGY) {
						  for(tAbLeIdx = 0; tAbLeIdx < (sizeof(PCIEEPHYEnergyMMIOTBL)/sizeof(ASIA_IO_TABLE_6432_REV)); tAbLeIdx++){ 
							if((nBrEvIsion) > (PCIEEPHYEnergyMMIOTBL)[tAbLeIdx].RevisionMax || (nBrEvIsion) < (PCIEEPHYEnergyMMIOTBL)[tAbLeIdx].RevisionMin) 
							  continue; 
							AsiaMemoryModify32(NbConfig->PcieEPHYBar |(PCIEEPHYEnergyMMIOTBL)[tAbLeIdx].Address, (PCIEEPHYEnergyMMIOTBL)[tAbLeIdx].Mask, (PCIEEPHYEnergyMMIOTBL)[tAbLeIdx].Value); 
							JdbgAddr=NbConfig->PcieEPHYBar |(PCIEEPHYEnergyMMIOTBL)[tAbLeIdx].Address;
							JdbgValue=AsiaMemoryRead32(NbConfig->PcieEPHYBar |(PCIEEPHYEnergyMMIOTBL)[tAbLeIdx].Address);
							PEI_DEBUG((PeiServices, EFI_D_ERROR|EFI_D_INFO, "Emode - PCIE-EPHY Addr=0%x Value=0%x \n",JdbgAddr, JdbgValue));
						  } 
//						  PROCESS_NB_PCIE_R6408M_TABLE(NbConfig->PcieEPHYBar, PCIEEPHYEnergyMMIOTBL, sizeof(PCIEEPHYEnergyMMIOTBL)/sizeof(ASIA_IO_TABLE_6408_REV));
					 }
				} 
			}
			 PEI_PCIE_NB_80_PORT(PeiServices, DXE_NB_PCIE_EPHY_SPE);	//add by jenny 20170413
		//;ysw_debug		//PCIE relative
		//;ysw_debug		RCRBAddr = NbCfg->RcrbhBar;
		//;ysw_debug		AsiaMemoryModifySave8(RCRBAddr|RCRBH_GFX_OCCUPANCY_TIMER, 0x80, 0x80);	 //for performace 
			}
	/*- DSZ_Porting (ALN-2017081701) Set to E mode before root port release link.*/ 

		}

#ifdef ZX_DUALSOCKET
	if(CodeFlag == PCIE_CF_S){
/*+ DSZ_Porting (ALN-2017081701) Set to E mode before root port release link.*/ 
		if(NbConfig->PcieRP) {
			// PCIE Processing
			if(NbConfig->PciePE0) {
				if(NbConfig->D3F0SPEValue >= DEVICE_SPE_VALUE_PERFORMANCE) {
					PROCESS_NB_PCIE_R6432M_TABLE_SLAVE(NbConfig->ZxeSlaveBusNum, NbConfig->PcieBar, D3F0PerformanceMMIOTBL, sizeof(D3F0PerformanceMMIOTBL)/sizeof(ASIA_IO_TABLE_6432_REV));
					if(NbConfig->D3F0SPEValue == DEVICE_SPE_VALUE_ENERGY) {
						PROCESS_NB_PCIE_R6432M_TABLE_SLAVE(NbConfig->ZxeSlaveBusNum, NbConfig->PcieBar, D3F0EnergyMMIOTBL, sizeof(D3F0EnergyMMIOTBL)/sizeof(ASIA_IO_TABLE_6432_REV));
					}
				}
			}
		
			if(NbConfig->PciePE1) {
				if(NbConfig->D3F1SPEValue >= DEVICE_SPE_VALUE_PERFORMANCE) {
					PROCESS_NB_PCIE_R6432M_TABLE_SLAVE(NbConfig->ZxeSlaveBusNum, NbConfig->PcieBar, D3F1PerformanceMMIOTBL, sizeof(D3F1PerformanceMMIOTBL)/sizeof(ASIA_IO_TABLE_6432_REV));
					if(NbConfig->D3F1SPEValue == DEVICE_SPE_VALUE_ENERGY) {
						PROCESS_NB_PCIE_R6432M_TABLE_SLAVE(NbConfig->ZxeSlaveBusNum, NbConfig->PcieBar, D3F1EnergyMMIOTBL, sizeof(D3F1EnergyMMIOTBL)/sizeof(ASIA_IO_TABLE_6432_REV));
					}
				}
			}
		
			if(NbConfig->PciePE2) {
				if(NbConfig->D3F2SPEValue >= DEVICE_SPE_VALUE_PERFORMANCE) {
					PROCESS_NB_PCIE_R6432M_TABLE_SLAVE(NbConfig->ZxeSlaveBusNum, NbConfig->PcieBar, D3F2PerformanceMMIOTBL, sizeof(D3F2PerformanceMMIOTBL)/sizeof(ASIA_IO_TABLE_6432_REV));
					if(NbConfig->D3F2SPEValue == DEVICE_SPE_VALUE_ENERGY) {
						PROCESS_NB_PCIE_R6432M_TABLE_SLAVE(NbConfig->ZxeSlaveBusNum, NbConfig->PcieBar, D3F2EnergyMMIOTBL, sizeof(D3F2EnergyMMIOTBL)/sizeof(ASIA_IO_TABLE_6432_REV));
					}
				} 
			}
		
			if(NbConfig->PciePE3) {
				if(NbConfig->D3F3SPEValue >= DEVICE_SPE_VALUE_PERFORMANCE) {
					PROCESS_NB_PCIE_R6432M_TABLE_SLAVE(NbConfig->ZxeSlaveBusNum, NbConfig->PcieBar, D3F3PerformanceMMIOTBL, sizeof(D3F3PerformanceMMIOTBL)/sizeof(ASIA_IO_TABLE_6432_REV)); 
					if(NbConfig->D3F3SPEValue == DEVICE_SPE_VALUE_ENERGY) {
						PROCESS_NB_PCIE_R6432M_TABLE_SLAVE(NbConfig->ZxeSlaveBusNum, NbConfig->PcieBar, D3F3EnergyMMIOTBL, sizeof(D3F3EnergyMMIOTBL)/sizeof(ASIA_IO_TABLE_6432_REV));
					}
				}
			}
		
			if(NbConfig->PciePE4) {
				if(NbConfig->D4F0SPEValue >= DEVICE_SPE_VALUE_PERFORMANCE) {
					PROCESS_NB_PCIE_R6432M_TABLE_SLAVE(NbConfig->ZxeSlaveBusNum, NbConfig->PcieBar, D4F0PerformanceMMIOTBL, sizeof(D4F0PerformanceMMIOTBL)/sizeof(ASIA_IO_TABLE_6432_REV));
					if(NbConfig->D4F0SPEValue == DEVICE_SPE_VALUE_ENERGY) {
						PROCESS_NB_PCIE_R6432M_TABLE_SLAVE(NbConfig->ZxeSlaveBusNum, NbConfig->PcieBar, D4F0EnergyMMIOTBL, sizeof(D4F0EnergyMMIOTBL)/sizeof(ASIA_IO_TABLE_6432_REV));
					}
				}
			}
			
		
			if(NbConfig->PciePE5) {
				if(NbConfig->D4F1SPEValue >= DEVICE_SPE_VALUE_PERFORMANCE) {
					PROCESS_NB_PCIE_R6432M_TABLE_SLAVE(NbConfig->ZxeSlaveBusNum, NbConfig->PcieBar, D4F1PerformanceMMIOTBL, sizeof(D4F1PerformanceMMIOTBL)/sizeof(ASIA_IO_TABLE_6432_REV));
					if(NbConfig->D4F1SPEValue == DEVICE_SPE_VALUE_ENERGY) {
						PROCESS_NB_PCIE_R6432M_TABLE_SLAVE(NbConfig->ZxeSlaveBusNum, NbConfig->PcieBar, D4F1EnergyMMIOTBL, sizeof(D4F1EnergyMMIOTBL)/sizeof(ASIA_IO_TABLE_6432_REV));
					}
				}
			}
		
			if(NbConfig->PciePE6) {
				if(NbConfig->D5F0SPEValue >= DEVICE_SPE_VALUE_PERFORMANCE) {
					PROCESS_NB_PCIE_R6432M_TABLE_SLAVE(NbConfig->ZxeSlaveBusNum, NbConfig->PcieBar, D5F0PerformanceMMIOTBL, sizeof(D5F0PerformanceMMIOTBL)/sizeof(ASIA_IO_TABLE_6432_REV));
					if(NbConfig->D5F0SPEValue == DEVICE_SPE_VALUE_ENERGY) {
						PROCESS_NB_PCIE_R6432M_TABLE_SLAVE(NbConfig->ZxeSlaveBusNum, NbConfig->PcieBar, D5F0EnergyMMIOTBL, sizeof(D5F0EnergyMMIOTBL)/sizeof(ASIA_IO_TABLE_6432_REV));
					}
				}
			}
			
			if(NbConfig->PciePE7) {
				if(NbConfig->D5F1SPEValue >= DEVICE_SPE_VALUE_PERFORMANCE) {
					PROCESS_NB_PCIE_R6432M_TABLE_SLAVE(NbConfig->ZxeSlaveBusNum, NbConfig->PcieBar, D5F1PerformanceMMIOTBL, sizeof(D5F1PerformanceMMIOTBL)/sizeof(ASIA_IO_TABLE_6432_REV));
					if(NbConfig->D5F1SPEValue == DEVICE_SPE_VALUE_ENERGY) {
						PROCESS_NB_PCIE_R6432M_TABLE_SLAVE(NbConfig->ZxeSlaveBusNum, NbConfig->PcieBar, D5F1EnergyMMIOTBL, sizeof(D5F1EnergyMMIOTBL)/sizeof(ASIA_IO_TABLE_6432_REV));
					}
				}
			}
			
			PEI_PCIE_NB_80_PORT(PeiServices, DXE_NB_PCIE_D3D5F1_SPE);	 //add by jenny 20170413
			if(NbConfig->RCRBHSPEValue) {
				if(NbConfig->RCRBHSPEValue >= DEVICE_SPE_VALUE_PERFORMANCE) {
		
					  UINT8 nBrEvIsion = (ASIA_NB_REVISION);
					  UINT32 tAbLeIdx, JdbgValue; 
					  UINT64 JdbgAddr;
		
					  for(tAbLeIdx = 0; tAbLeIdx < (sizeof(RCRBHPerformanceMMIOTBL)/sizeof(ASIA_IO_TABLE_6432_REV)); tAbLeIdx++) 
					  { 
						if((nBrEvIsion) > (RCRBHPerformanceMMIOTBL)[tAbLeIdx].RevisionMax || (nBrEvIsion) < (RCRBHPerformanceMMIOTBL)[tAbLeIdx].RevisionMin) 
						  continue; 
						AsiaMemoryModify32(NbConfig->Slave_RcrbhBar |(RCRBHPerformanceMMIOTBL)[tAbLeIdx].Address, (RCRBHPerformanceMMIOTBL)[tAbLeIdx].Mask, (RCRBHPerformanceMMIOTBL)[tAbLeIdx].Value); 
						JdbgAddr=NbConfig->Slave_RcrbhBar |(RCRBHPerformanceMMIOTBL)[tAbLeIdx].Address;
						JdbgValue=AsiaMemoryRead32(NbConfig->Slave_RcrbhBar |(RCRBHPerformanceMMIOTBL)[tAbLeIdx].Address);
						PEI_DEBUG((PeiServices, EFI_D_ERROR|EFI_D_INFO, "Pmode - RCRB-H Addr=0%x Value=0%x \n",JdbgAddr, JdbgValue));
					  } 
					if(NbConfig->RCRBHSPEValue == DEVICE_SPE_VALUE_ENERGY) {
						  for(tAbLeIdx = 0; tAbLeIdx < (sizeof(RCRBHEnergyMMIOTBL)/sizeof(ASIA_IO_TABLE_6432_REV)); tAbLeIdx++) 
						  { 
							if((nBrEvIsion) > (RCRBHEnergyMMIOTBL)[tAbLeIdx].RevisionMax || (nBrEvIsion) < (RCRBHEnergyMMIOTBL)[tAbLeIdx].RevisionMin) 
							  continue; 
							AsiaMemoryModify32(NbConfig->Slave_RcrbhBar |(RCRBHEnergyMMIOTBL)[tAbLeIdx].Address, (RCRBHEnergyMMIOTBL)[tAbLeIdx].Mask, (RCRBHEnergyMMIOTBL)[tAbLeIdx].Value); 
							JdbgAddr=NbConfig->Slave_RcrbhBar |(RCRBHEnergyMMIOTBL)[tAbLeIdx].Address;
							JdbgValue=AsiaMemoryRead32(NbConfig->Slave_RcrbhBar |(RCRBHEnergyMMIOTBL)[tAbLeIdx].Address);
							PEI_DEBUG((PeiServices, EFI_D_ERROR|EFI_D_INFO, "Emode - RCRB-H Addr=0%x Value=0%x \n",JdbgAddr, JdbgValue));
						  } 
					}
				} 
		   }
		
		   PEI_PCIE_NB_80_PORT(PeiServices, DXE_NB_PCIE_RCRB_SPE);	  //add by jenny 20170413
		   if(NbConfig->PCIEEPHYSPEValue) {
				if(NbConfig->PCIEEPHYSPEValue >= DEVICE_SPE_VALUE_PERFORMANCE) {
		
					  UINT8 nBrEvIsion = (ASIA_NB_REVISION);
					  UINT32 tAbLeIdx, JdbgValue; 
					  UINT64 JdbgAddr;
		
					  for(tAbLeIdx = 0; tAbLeIdx < (sizeof(PCIEEPHYPerformanceMMIOTBL)/sizeof(ASIA_IO_TABLE_6432_REV)); tAbLeIdx++) 
					  { 
						  if((nBrEvIsion) > (PCIEEPHYPerformanceMMIOTBL)[tAbLeIdx].RevisionMax || (nBrEvIsion) < (PCIEEPHYPerformanceMMIOTBL)[tAbLeIdx].RevisionMin) 
						  continue; 
						  AsiaMemoryModify32(NbConfig->Slave_PcieEPHYBar |(PCIEEPHYPerformanceMMIOTBL)[tAbLeIdx].Address, (PCIEEPHYPerformanceMMIOTBL)[tAbLeIdx].Mask, (PCIEEPHYPerformanceMMIOTBL)[tAbLeIdx].Value); 
						  JdbgAddr=NbConfig->Slave_PcieEPHYBar |(PCIEEPHYPerformanceMMIOTBL)[tAbLeIdx].Address;
						  JdbgValue=AsiaMemoryRead32(NbConfig->Slave_PcieEPHYBar |(PCIEEPHYPerformanceMMIOTBL)[tAbLeIdx].Address);
						  PEI_DEBUG((PeiServices, EFI_D_ERROR|EFI_D_INFO, "Pmode - PCIE-EPHY Addr=0%x Value=0%x \n",JdbgAddr, JdbgValue));
					  } 
					  if(NbConfig->PCIEEPHYSPEValue == DEVICE_SPE_VALUE_ENERGY) {
						  for(tAbLeIdx = 0; tAbLeIdx < (sizeof(PCIEEPHYEnergyMMIOTBL)/sizeof(ASIA_IO_TABLE_6432_REV)); tAbLeIdx++){ 
							if((nBrEvIsion) > (PCIEEPHYEnergyMMIOTBL)[tAbLeIdx].RevisionMax || (nBrEvIsion) < (PCIEEPHYEnergyMMIOTBL)[tAbLeIdx].RevisionMin) 
							  continue; 
							AsiaMemoryModify32(NbConfig->Slave_PcieEPHYBar |(PCIEEPHYEnergyMMIOTBL)[tAbLeIdx].Address, (PCIEEPHYEnergyMMIOTBL)[tAbLeIdx].Mask, (PCIEEPHYEnergyMMIOTBL)[tAbLeIdx].Value); 
							JdbgAddr=NbConfig->Slave_PcieEPHYBar |(PCIEEPHYEnergyMMIOTBL)[tAbLeIdx].Address;
							JdbgValue=AsiaMemoryRead32(NbConfig->Slave_PcieEPHYBar |(PCIEEPHYEnergyMMIOTBL)[tAbLeIdx].Address);
							PEI_DEBUG((PeiServices, EFI_D_ERROR|EFI_D_INFO, "Emode - PCIE-EPHY Addr=0%x Value=0%x \n",JdbgAddr, JdbgValue));
						  } 
					//	  PROCESS_NB_PCIE_R6408M_TABLE(NbConfig->Slave_PcieEPHYBar, PCIEEPHYEnergyMMIOTBL, sizeof(PCIEEPHYEnergyMMIOTBL)/sizeof(ASIA_IO_TABLE_6408_REV));
					 }
				} 
			}
			 PEI_PCIE_NB_80_PORT(PeiServices, DXE_NB_PCIE_EPHY_SPE);	//add by jenny 20170413
		//;ysw_debug		//PCIE relative
		//;ysw_debug		RCRBAddr = NbCfg->RcrbhBar;
		//;ysw_debug		AsiaMemoryModifySave8(RCRBAddr|RCRBH_GFX_OCCUPANCY_TIMER, 0x80, 0x80);	 //for performace 
			}
	/*- DSZ_Porting (ALN-2017081701) Set to E mode before root port release link.*/ 

		}
#endif

	return EFI_SUCCESS;
}

#define PCI_EXP_ENDPOINT_DEVICE 0x00
#define LEGACY_PCI_EXP_ENDPOINT_DEVICE 0x01
#define PCI_EXP_ROOT_PORT 0x04
#define PCI_EXP_UPSTREAM_PORT 0x05
#define PCI_EXP_DOWNSTREAM_PORT 0x06
#define PCIE_P2P_BRIDGE 0x07

/**
   Scan PCIE Devices function.

  @param  PeiServices	EFI_PEI_SERVICES pointer.
  @param  Bus
  @param Dev
  @param Func
  @param MaxBus
  @param Flag

  @return VOID.

**/

VOID
ScanPcieDevicePei(
    IN     EFI_PEI_SERVICES       **PeiServices,
    IN     UINT8  Bus,
    IN     UINT8  Dev,
    IN     UINT8  Fun,
    UINT8 *MaxBus,
    BOOLEAN *Flag
)
{
        UINT8 MyBus, MyDev,  MyFun;
        UINT8 CapAddr;
        UINT8 CapId = 0;
        UINT8 PortType, Data8;
        UINT16 Data16;
        UINT32 Data32;
        BOOLEAN Bridge;

        Data32 = AsiaPciRead32(AsiaPciAddress(Bus, Dev, Fun, 0));
        if(Data32 != 0xFFFFFFFF){
                PEI_DEBUG((PeiServices, EFI_D_ERROR, "[%x:%x.%x] DeviceId:VendorId = %x \n", Bus, Dev, Fun, Data32));
        }
        if ((Data32 != 0xFFFFFFFF) && (!*Flag))
        {
                CapAddr = AsiaPciRead8(AsiaPciAddress(Bus, Dev, Fun, 0x34));
                PEI_DEBUG((PeiServices, EFI_D_ERROR, "[%x:%x.%x] CapAddr = %x \n", Bus, Dev, Fun, CapAddr));
                while (CapAddr != 0)
                {
                        CapId = AsiaPciRead8(AsiaPciAddress(Bus, Dev, Fun, CapAddr));
                        PEI_DEBUG((PeiServices, EFI_D_ERROR, "[%x:%x.%x] CapId = %x \n", Bus, Dev, Fun, CapId));
                        if (CapId == 0x10)
                                break;
                        CapAddr = AsiaPciRead8(AsiaPciAddress(Bus, Dev, Fun, CapAddr + 1));
                        PEI_DEBUG((PeiServices, EFI_D_ERROR, "[%x:%x.%x] CapAddr = %x \n", Bus, Dev, Fun, CapAddr));
                }
				/*+ DSZ_Porting -- (JIH-2017053101) Fix BMC VGA card filtered in Asia PEI phase.*/				
                //if (CapId != 0x10)
                //        return;
				/*- DSZ_Porting -- (JIH-2017053101) Fix BMC VGA card filtered in Asia PEI phase.*/
                Data8 = AsiaPciRead8(AsiaPciAddress(Bus, Dev, Fun, 0x0E));
                Bridge = ((Data8 & (~0x80)) == 0x01) ? TRUE : FALSE;
				/*+ DSZ_Porting -- (JIH-2017053101) Fix BMC VGA card filtered in Asia PEI phase.*/				
				if (CapId != 0x10){    // PCIE Cap not found. Is it a PCIE VGA device ?
					if(!Bridge && AsiaPciRead8(AsiaPciAddress(Bus, Dev, Fun, 0xB)) == 3){
						*Flag = TRUE;
					}
				       return;
				}
				/*- DSZ_Porting -- (JIH-2017053101) Fix BMC VGA card filtered in Asia PEI phase.*/

				if (Bridge)     
                        PEI_DEBUG((PeiServices, EFI_D_ERROR, "[%x:%x.%x] is a bridge!\n", Bus, Dev, Fun));
                PortType = AsiaPciRead8(AsiaPciAddress(Bus, Dev, Fun, CapAddr + 0x02));
                PortType >>= 4;
                PEI_DEBUG((PeiServices, EFI_D_ERROR, "[%x:%x.%x] PortType = %x \n", Bus, Dev, Fun, PortType));
                if ((PortType == LEGACY_PCI_EXP_ENDPOINT_DEVICE)\
                        ||(PortType == PCI_EXP_ENDPOINT_DEVICE))
                {
                        //Read the Device's Class code - Base class
                        Data8 = AsiaPciRead8(AsiaPciAddress(Bus, Dev, Fun, 0xB));
                        PEI_DEBUG((PeiServices, EFI_D_ERROR, "0x0B = %x \n", Data8));
                        //For Base Class = 0x03, is a VGA device
                        if (Data8 == 0x03)
                        {                       
                                *Flag = TRUE;
                                PEI_DEBUG((PeiServices, EFI_D_ERROR, "PCIE End Point! \n"));
                                return;
                        }
                }
                else if ((PortType == PCI_EXP_UPSTREAM_PORT) \
                        || (PortType == PCI_EXP_DOWNSTREAM_PORT) \
                        || (PortType == PCI_EXP_ROOT_PORT)\
                        ||(Bridge))
                {
                        PEI_DEBUG((PeiServices, EFI_D_ERROR, "Increase Bus by 1!\n"));
                        *MaxBus += 1;
                        MyBus = *MaxBus;
                        AsiaPciWrite8(AsiaPciAddress(Bus, Dev, Fun, 0x18), Bus);
                        AsiaPciWrite8(AsiaPciAddress(Bus, Dev, Fun, 0x19), MyBus);
                        AsiaPciWrite8(AsiaPciAddress(Bus, Dev, Fun, 0x1A), 0xFF);
                        Data16 = AsiaPciRead16(AsiaPciAddress(Bus, Dev, Fun, 0x18));
                        PEI_DEBUG((PeiServices, EFI_D_ERROR, "[%x:%x.%x] Data16 = %x \n", Bus, Dev, Fun, Data16));
                        for(MyDev = 0; MyDev < 32; MyDev++)
                        {
                                for(MyFun = 0; MyFun < 8; MyFun++)
                                {
                                        ScanPcieDevicePei(PeiServices, MyBus, MyDev, MyFun, MaxBus, Flag);
										if(*Flag){
											break;
										}
                                }
								if(*Flag){
									break;
								}
                        }
                        
                        //everytime we complete all nodes behind a branch, we clear the bridge's configuration
                        AsiaPciWrite8(AsiaPciAddress(Bus, Dev, Fun, 0x18), 0);
            AsiaPciWrite8(AsiaPciAddress(Bus, Dev, Fun, 0x19), 0);
            AsiaPciWrite8(AsiaPciAddress(Bus, Dev, Fun, 0x1A), 0);
                }
        }
        return;
}




/**
   Check and init PCIE GFX Card.
   called by CheckPcieVgaCard() function.
   
  @param  PeiServices	EFI_PEI_SERVICES pointer.
  @param  Bus
  @param Dev
  @param Func

  @return The value from this function.

**/


EFI_STATUS
CheckAndInitializePcieVga (
    IN     EFI_PEI_SERVICES       **PeiServices,
    IN     UINT8                  Bus,
    IN     UINT8                  Dev,
    IN     UINT8                  Func
)
{
    EFI_STATUS  Status = EFI_NOT_FOUND;
    UINT8       CapPtr;
    UINT8       CapNxtPtr;
    UINT8       CapId;
    UINT8       SearchTimes;
    UINT64	    Addr;
	UINT8 	MaxBus = 0; 	
	BOOLEAN Flag = FALSE;  //When we found a VGA device, we set it to TRUE	

    //
    // Check for the presence of a Card.
    //
    SearchTimes = 0;
    Addr = AsiaPciAddress (Bus, Dev, Func, D3D5F1_CAP_POINTER);

    CapNxtPtr = AsiaPciRead8 (Addr);
	if (CapNxtPtr == 0xFF)
		return Status;
    do {
        CapPtr = CapNxtPtr;
        Addr = AsiaPciAddress (Bus, Dev, Func, CapPtr);
        CapId = AsiaPciRead8 (Addr);
        SearchTimes++;

        Addr = AsiaPciAddress (Bus, Dev, Func, CapPtr + 1);
        CapNxtPtr = AsiaPciRead8 (Addr);
    }while ((CapId != 0x10) && (SearchTimes < 64) && (CapNxtPtr != 0));  // One times is 4 Bytes length

    //if not found PCIE compability Ptr rutun EFI_NOT_FOUND
    if (CapId != 0x10)
        return Status;

    //judge device if present
    if (((AsiaPciRead8 (AsiaPciAddress (Bus, Dev, Func, CapPtr + 0x1A))) & BIT6) == BIT6){
        //
        // Assign temp bus number for getting PCIe card type
        //
        MaxBus = Bus;	
		PEI_DEBUG((PeiServices, EFI_D_ERROR, "[VGA] There is a PCIE device behine Root Port! \n"));
		ScanPcieDevicePei(PeiServices, Bus, Dev, Func, &MaxBus, &Flag);
		
		if (Flag)											
			Status = EFI_SUCCESS;							

    }
    return Status;
}


/**
   Check pcie gfx card exist or not.

  @param  PeiServices	EFI_PEI_SERVICES pointer.
  @param  pNbConfig  point to ASIA_NB_CONFIGURATION
  @param PrimaryDisplay

  @return VOID.

**/

VOID
CheckPcieVgaCard(
    IN     EFI_PEI_SERVICES             **PeiServices,
    IN     ASIA_NB_CONFIGURATION        *NbConfig,
    IN OUT DISPLAY_DEVICE               *PrimaryDisplay
)
{
    EFI_STATUS  Status;
  

	//check pcie vga card plug in PE0 port
    if(NbConfig->PciePE0){
        Status = CheckAndInitializePcieVga(PeiServices,CHX002_HB_BUS,CHX002_PE0_3_DEV,CHX002_PE0_FUN);
        if(Status == EFI_SUCCESS){
            *PrimaryDisplay = PE0;
            PEI_DEBUG((PeiServices, EFI_D_ERROR, "[PCIE] VGA card detected! - PE0\n"));
            return;
        }
    }

	//check pcie vga card plug in PE1 port
    if(NbConfig->PciePE1){
        Status = CheckAndInitializePcieVga(PeiServices,CHX002_HB_BUS,CHX002_PE0_3_DEV,CHX002_PE1_FUN);
        if(Status == EFI_SUCCESS){
            *PrimaryDisplay = PE1;
            PEI_DEBUG((PeiServices, EFI_D_ERROR, "[PCIE] VGA card detected! - PE1\n"));
            return;
        }
    }

	//check pcie vga card plug in PE2 port
    if(NbConfig->PciePE2){
        Status = CheckAndInitializePcieVga(PeiServices,CHX002_HB_BUS,CHX002_PE0_3_DEV,CHX002_PE2_FUN);
        if(Status == EFI_SUCCESS){
            *PrimaryDisplay = PE2;
            PEI_DEBUG((PeiServices, EFI_D_ERROR, "[PCIE] VGA card detected! - PE2\n"));
            return;
        }
    }

	//check pcie vga card plug in PE3 port
    if(NbConfig->PciePE3){
        Status = CheckAndInitializePcieVga(PeiServices,CHX002_HB_BUS,CHX002_PE0_3_DEV,CHX002_PE3_FUN);
        if(Status == EFI_SUCCESS){
            *PrimaryDisplay = PE3;
            PEI_DEBUG((PeiServices, EFI_D_ERROR, "[PCIE] VGA card detected! - PE3\n"));
            return;
        }
    }

    //check pcie vga card plug in PE4 port
    if(NbConfig->PciePE4){
        Status = CheckAndInitializePcieVga(PeiServices,CHX002_HB_BUS,CHX002_PE4_5_DEV,CHX002_PE4_FUN);
        if(Status == EFI_SUCCESS){
            *PrimaryDisplay = PE4;
            PEI_DEBUG((PeiServices, EFI_D_ERROR, "[PCIE] VGA card detected! - PE4\n"));
            return;
        }
    }
	
    //check pcie vga card plug in PE5 port
    if(NbConfig->PciePE5){
        Status = CheckAndInitializePcieVga(PeiServices,CHX002_HB_BUS,CHX002_PE4_5_DEV,CHX002_PE5_FUN);
        if(Status == EFI_SUCCESS){
            *PrimaryDisplay = PE5;
            PEI_DEBUG((PeiServices, EFI_D_ERROR, "[PCIE] VGA card detected! - PE5\n"));
            return;
        }
    }

    //check pcie vga card plug in PE6 port
    if(NbConfig->PciePE6){
        Status = CheckAndInitializePcieVga(PeiServices,CHX002_HB_BUS,CHX002_PE6_7_DEV,CHX002_PE6_FUN);
        if(Status == EFI_SUCCESS){
            *PrimaryDisplay = PE6;
            PEI_DEBUG((PeiServices, EFI_D_ERROR, "[PCIE] VGA card detected! - PE6\n"));
            return;
        }
    }
	
    //check pcie vga card plug in PE7 port
    if(NbConfig->PciePE7){
        Status = CheckAndInitializePcieVga(PeiServices,CHX002_HB_BUS,CHX002_PE6_7_DEV,CHX002_PE7_FUN);
        if(Status == EFI_SUCCESS){
            *PrimaryDisplay = PE7;
            PEI_DEBUG((PeiServices, EFI_D_ERROR, "[PCIE] VGA card detected! - PE7\n"));
            return;
        }
    }


#ifdef ZX_DUALSOCKET	
//#ifdef DUAL_SOCKET_CODE
	if(NbConfig->ZxeDualSocket == 1){
		if(NbConfig->Slave_PcieRP){
			//check pcie vga card plug in SLAVE_PE0 port
			if(NbConfig->Slave_PciePE0){
				Status = CheckAndInitializePcieVga(PeiServices,CHX002_SLAVE_BUS,CHX002_PE0_SLAVE_3_DEV,CHX002_PE0_SLAVE_FUN);
				if(Status == EFI_SUCCESS){
					*PrimaryDisplay = PE0_SLAVE;
					PEI_DEBUG((PeiServices, EFI_D_ERROR, "[PCIE] VGA card detected! - PE0-Slave\n"));
					return;
				}
			}

			//check pcie vga card plug in SLAVE_PE1 port
			if(NbConfig->Slave_PciePE1){
				Status = CheckAndInitializePcieVga(PeiServices,CHX002_SLAVE_BUS,CHX002_PE0_SLAVE_3_DEV,CHX002_PE1_SLAVE_FUN);
				if(Status == EFI_SUCCESS){
					*PrimaryDisplay = PE1_SLAVE;
					PEI_DEBUG((PeiServices, EFI_D_ERROR, "[PCIE] VGA card detected! - PE1-Slave\n"));
					return;
				}
			}

			//check pcie vga card plug in SLAVE_PE2 port
			if(NbConfig->Slave_PciePE2){
				Status = CheckAndInitializePcieVga(PeiServices,CHX002_SLAVE_BUS,CHX002_PE0_SLAVE_3_DEV,CHX002_PE2_SLAVE_FUN);
				if(Status == EFI_SUCCESS){
					*PrimaryDisplay = PE2_SLAVE;
					PEI_DEBUG((PeiServices, EFI_D_ERROR, "[PCIE] VGA card detected! - PE2-Slave\n"));
					return;
				}
			}

			//check pcie vga card plug in SLAVE_PE3 port
			if(NbConfig->Slave_PciePE3){
				Status = CheckAndInitializePcieVga(PeiServices,CHX002_SLAVE_BUS,CHX002_PE0_SLAVE_3_DEV,CHX002_PE3_SLAVE_FUN);
				if(Status == EFI_SUCCESS){
					*PrimaryDisplay = PE3_SLAVE;
					PEI_DEBUG((PeiServices, EFI_D_ERROR, "[PCIE] VGA card detected! - PE3-Slave\n"));
					return;
				}
			}

			//check pcie vga card plug in SLAVE_PE4 port
			if(NbConfig->Slave_PciePE4){
				Status = CheckAndInitializePcieVga(PeiServices,CHX002_SLAVE_BUS,CHX002_PE4_SLAVE_5_DEV,CHX002_PE4_SLAVE_FUN);
				if(Status == EFI_SUCCESS){
					*PrimaryDisplay = PE4_SLAVE;
					PEI_DEBUG((PeiServices, EFI_D_ERROR, "[PCIE] VGA card detected! - PE4-Slave\n"));
					return;
				}
			}

			//check pcie vga card plug in SLAVE_PE5 port
			if(NbConfig->Slave_PciePE5){
				Status = CheckAndInitializePcieVga(PeiServices,CHX002_SLAVE_BUS,CHX002_PE4_SLAVE_5_DEV,CHX002_PE5_SLAVE_FUN);
				if(Status == EFI_SUCCESS){
					*PrimaryDisplay = PE5_SLAVE;
					PEI_DEBUG((PeiServices, EFI_D_ERROR, "[PCIE] VGA card detected! - PE5-Slave\n"));
					return;
				}
			}

			//check pcie vga card plug in SLAVE_PE6 port
			if(NbConfig->Slave_PciePE6){
				Status = CheckAndInitializePcieVga(PeiServices,CHX002_SLAVE_BUS,CHX002_PE6_SLAVE_7_DEV,CHX002_PE6_SLAVE_FUN);
				if(Status == EFI_SUCCESS){
					*PrimaryDisplay = PE6_SLAVE;
					PEI_DEBUG((PeiServices, EFI_D_ERROR, "[PCIE] VGA card detected! - PE6-Slave\n"));
					return;
				}
			}

			//check pcie vga card plug in SLAVE_PE7 port
			if(NbConfig->Slave_PciePE7){
				Status = CheckAndInitializePcieVga(PeiServices,CHX002_SLAVE_BUS,CHX002_PE6_SLAVE_7_DEV,CHX002_PE7_SLAVE_FUN);
				if(Status == EFI_SUCCESS){
					*PrimaryDisplay = PE7_SLAVE;
					PEI_DEBUG((PeiServices, EFI_D_ERROR, "[PCIE] VGA card detected! - PE7-Slave\n"));
					return;
				}
			}
		}
	}
#endif
}



/**
   Sync config to register function.
   
   Setting PCIE registers based on ASIA_NB_CONFIGURATION Struct value.
   
  @param  PeiServices	EFI_PEI_SERVICES pointer.
  @param  pNbConfig  point to ASIA_NB_CONFIGURATION

  @return VOID.

**/

void SyncConfigToRegsiter(
	IN EFI_PEI_SERVICES **PeiServices,
	IN ASIA_NB_CONFIGURATION *NbConfig
)
{
	UINT8 Data;
//	UINT16 Data16;
	UINT64 PcieBase;
//	BOOLEAN Bool;

	PcieBase = NbConfig->PcieBar;

// PART 1:
	//
	// Enable PcieRoutingCtrl to debug for PCIE interrupt routing
	// Genernally, this option in OFF state, only ON for debugging
	//
	if(NbConfig->PcieRoutingCtrl){
		// PE0
		if(NbConfig->PciePE0){
			// MSGC - PCIE_INTA~D  routing configure
			Data = NbConfig->PE0_Msgc2PcieIntx;
			Data <<= 6;
			AsiaPcieModify8(PcieBase, CHX002_GFXAX|((UINT64)D0F0_PCIE_INTR_ROUTING_SEL_0 << 32), 
																	D0F0_RMSGCINTRT_PE0_1_0, Data);	
			// PCIE_INTA~D	- NB2SB_INTA~D configure
			Data = NbConfig->PE0_PcieIntx2Nb2sbIntx;
			Data <<= 6;
			AsiaPcieModify8(PcieBase, CHX002_GFXAX|((UINT64)D0F0_PCIE_INTR_ROUTING_SEL_1 << 32), 
																		D0F0_RINTRT_PE0_1_0, Data);	
		}
		// PE1
		if(NbConfig->PciePE1){
			// MSGC - PCIE_INTA~D  routing configure
			Data = NbConfig->PE1_Msgc2PcieIntx;
			Data <<= 4;
			AsiaPcieModify8(PcieBase, CHX002_GFXAX|((UINT64)D0F0_PCIE_INTR_ROUTING_SEL_0 << 32), 
																	D0F0_RMSGCINTRT_PE1_1_0, Data);
			// PCIE_INTA~D	- NB2SB_INTA~D configure
			Data = NbConfig->PE1_PcieIntx2Nb2sbIntx;
			Data <<= 4;
			AsiaPcieModify8(PcieBase, CHX002_GFXAX|((UINT64)D0F0_PCIE_INTR_ROUTING_SEL_1 << 32), 
																		D0F0_RINTRT_PE1_1_0, Data);				
		}
		// PE2
		if(NbConfig->PciePE2){
			// MSGC - PCIE_INTA~D  routing configure
			Data = NbConfig->PE2_Msgc2PcieIntx;
			Data <<= 2;
			AsiaPcieModify8(PcieBase, CHX002_GFXAX|((UINT64)D0F0_PCIE_INTR_ROUTING_SEL_0 << 32), 
																	D0F0_RMSGCINTRT_PE2_1_0, Data);
			// PCIE_INTA~D	- NB2SB_INTA~D configure
			Data = NbConfig->PE2_PcieIntx2Nb2sbIntx;
			Data <<= 2;
			AsiaPcieModify8(PcieBase, CHX002_GFXAX|((UINT64)D0F0_PCIE_INTR_ROUTING_SEL_1 << 32), 
																		D0F0_RINTRT_PE2_1_0, Data);				
		}
		// PE3
		if(NbConfig->PciePE3){
			// MSGC - PCIE_INTA~D  routing configure
			Data = NbConfig->PE3_Msgc2PcieIntx;
			Data <<= 0;
			AsiaPcieModify8(PcieBase, CHX002_GFXAX|((UINT64)D0F0_PCIE_INTR_ROUTING_SEL_0 << 32), 
																	D0F0_RMSGCINTRT_PE3_1_0, Data);
			// PCIE_INTA~D	- NB2SB_INTA~D configure
			Data = NbConfig->PE3_PcieIntx2Nb2sbIntx;
			Data <<= 0;
			AsiaPcieModify8(PcieBase, CHX002_GFXAX|((UINT64)D0F0_PCIE_INTR_ROUTING_SEL_1 << 32), 
																		D0F0_RINTRT_PE3_1_0, Data);				
		}
		// PE4
		if(NbConfig->PciePE4){
			// MSGC - PCIE_INTA~D  routing configure
			Data = NbConfig->PE4_Msgc2PcieIntx;
			Data <<= 6;
			AsiaPcieModify8(PcieBase, CHX002_GFXAX|((UINT64)D0F0_PCIE_INTR_ROUTING_SEL_2 << 32), 
																	D0F0_RMSGCINTRT_PEG0_1_0, Data);
			// PCIE_INTA~D	- NB2SB_INTA~D configure
			Data = NbConfig->PE4_PcieIntx2Nb2sbIntx;
			Data <<= 2;
			AsiaPcieModify8(PcieBase, CHX002_GFXAX|((UINT64)D0F0_PCIE_INTR_ROUTING_SEL_2 << 32), 
																	D0F0_RINTRT_PEG0_1_0, Data);			
		}
		// PE5
		if(NbConfig->PciePE5){
			// MSGC - PCIE_INTA~D  routing configure
			Data = NbConfig->PE5_Msgc2PcieIntx;
			Data <<= 4;
			AsiaPcieModify8(PcieBase, CHX002_GFXAX|((UINT64)D0F0_PCIE_INTR_ROUTING_SEL_2 << 32), 
																	D0F0_RMSGCINTRT_PEG1_1_0, Data);
			// PCIE_INTA~D	- NB2SB_INTA~D configure
			Data = NbConfig->PE5_PcieIntx2Nb2sbIntx;
			Data <<= 0;
			AsiaPcieModify8(PcieBase, CHX002_GFXAX|((UINT64)D0F0_PCIE_INTR_ROUTING_SEL_2 << 32), 
																	D0F0_RINTRT_PEG1_1_0, Data);			
		}
		// PE6
		if(NbConfig->PciePE6){
			// MSGC - PCIE_INTA~D  routing configure
			Data = NbConfig->PE6_Msgc2PcieIntx;
			Data <<= 0;
			AsiaPcieModify8(PcieBase, CHX002_GFXAX|((UINT64)D0F0_PCIE_PORT_G2_INTR_ROUTING_SEL << 32), 
																	D0F0_RMSGCINTRT_PEG2_1_0, Data);
			// PCIE_INTA~D	- NB2SB_INTA~D configure
			Data = NbConfig->PE6_PcieIntx2Nb2sbIntx;
			Data <<= 2;
			AsiaPcieModify8(PcieBase, CHX002_GFXAX|((UINT64)D0F0_PCIE_PORT_G2_INTR_ROUTING_SEL << 32), 
																		D0F0_RINTRT_PEG2_1_0, Data);	
			//For APIC Routing 
			Data = NbConfig->Pe6ApciIrq;
			Data <<= 4;
			AsiaPcieModify8(PcieBase, CHX002_GFXAX|((UINT64)D0F0_PCIE_PORT_G2_INTR_ROUTING_SEL << 32), 
																	D0F0_RINTRTAPIC_PEG2_1_0, Data);			
		}
		// PE7
		if(NbConfig->PciePE7){
			// MSGC - PCIE_INTA~D  routing configure
			Data = NbConfig->PE7_Msgc2PcieIntx;
			Data <<= 0;
			AsiaPcieModify8(PcieBase, CHX002_GFXAX|((UINT64)D0F0_PCIE_PORT_G3_INTR_ROUTING_SEL << 32), 
																	D0F0_RMSGCINTRT_PEG3_1_0, Data);
			// PCIE_INTA~D	- NB2SB_INTA~D configure
			Data = NbConfig->PE7_PcieIntx2Nb2sbIntx;
			Data <<= 2;
			AsiaPcieModify8(PcieBase, CHX002_GFXAX|((UINT64)D0F0_PCIE_PORT_G3_INTR_ROUTING_SEL << 32), 
																		D0F0_RINTRT_PEG3_1_0, Data);
			//For APIC Routing 
			Data = NbConfig->Pe7ApciIrq;
			Data <<= 4;
			AsiaPcieModify8(PcieBase, CHX002_GFXAX|((UINT64)D0F0_PCIE_PORT_G3_INTR_ROUTING_SEL << 32), 
																		D0F0_RINTRTAPIC_PEG3_1_0, Data);			
		}
	}

#if 0    //JNY add for PCIE disable 

// PART 2:
	// JNY Modify for pcie disable -S
	//;lna_debug - 20161014 - start
	// according to user selection, disable/enable PCIE RP
	// [NOTE] those code should only have effect on PXP/HAPS, on silicon, BIOS need to do more power saving 
	// and finally hide those unused ports in DXE PrePci phase
	// PE0
    if((NbConfig->PciePE0==0)||(NbConfig->PcieRP==0))	
	    AsiaPcieModify16(PcieBase, CHX002_APIC|((UINT64)D0F5_DEV_EXIST_REG_SPACE << 32), D0F5_RDV3F0EXST, 0);
    else{
		AsiaPcieModify16(PcieBase, CHX002_APIC|((UINT64)D0F5_DEV_EXIST_REG_SPACE << 32), D0F5_RDV3F0EXST, D0F5_RDV3F0EXST);
	}
	//PE1
	if((NbConfig->PciePE1==0)||(NbConfig->PcieRP==0))
		AsiaPcieModify16(PcieBase, CHX002_APIC|((UINT64)D0F5_DEV_EXIST_REG_SPACE << 32), D0F5_RDV3F1EXST, 0);		
	else{
	    AsiaPcieModify16(PcieBase, CHX002_APIC|((UINT64)D0F5_DEV_EXIST_REG_SPACE << 32), D0F5_RDV3F1EXST, D0F5_RDV3F1EXST);
	}
	//PE2
	if((NbConfig->PciePE2==0)||(NbConfig->PcieRP==0))
		AsiaPcieModify16(PcieBase, CHX002_APIC|((UINT64)D0F5_DEV_EXIST_REG_SPACE << 32), D0F5_RDV3F2EXST, 0);
	else{	
		AsiaPcieModify16(PcieBase, CHX002_APIC|((UINT64)D0F5_DEV_EXIST_REG_SPACE << 32), D0F5_RDV3F2EXST, D0F5_RDV3F1EXST);
	}
	//PE3
	if((NbConfig->PciePE3==0)||(NbConfig->PcieRP==0))
		AsiaPcieModify16(PcieBase, CHX002_APIC|((UINT64)D0F5_DEV_EXIST_REG_SPACE << 32), D0F5_RDV3F3EXST, 0);
	else{	
		AsiaPcieModify16(PcieBase, CHX002_APIC|((UINT64)D0F5_DEV_EXIST_REG_SPACE << 32), D0F5_RDV3F3EXST, D0F5_RDV3F3EXST);
	}
	//PE4
	if((NbConfig->PciePE4==0)||(NbConfig->PcieRP==0))	
		AsiaPcieModify16(PcieBase, CHX002_APIC|((UINT64)D0F5_DEV_EXIST_REG_SPACE << 32), D0F5_RDV4F0EXST, 0);
	else{	
		AsiaPcieModify16(PcieBase, CHX002_APIC|((UINT64)D0F5_DEV_EXIST_REG_SPACE << 32), D0F5_RDV4F0EXST, D0F5_RDV4F0EXST);
	}
	//PE5
	if((NbConfig->PciePE5==0)||(NbConfig->PcieRP==0))
		AsiaPcieModify16(PcieBase, CHX002_APIC|((UINT64)D0F5_DEV_EXIST_REG_SPACE << 32), D0F5_RDV4F1EXST, 0);
	else{	
		AsiaPcieModify16(PcieBase, CHX002_APIC|((UINT64)D0F5_DEV_EXIST_REG_SPACE << 32), D0F5_RDV4F1EXST, D0F5_RDV4F1EXST);
	}
	//PE6
	if((NbConfig->PciePE6==0)||(NbConfig->PcieRP==0))	
		AsiaPcieModify16(PcieBase, CHX002_APIC|((UINT64)D0F5_DEV_EXIST_REG_SPACE << 32), D0F5_RDV5F0EXST, 0);		
	else{	
		AsiaPcieModify16(PcieBase, CHX002_APIC|((UINT64)D0F5_DEV_EXIST_REG_SPACE << 32), D0F5_RDV5F0EXST, D0F5_RDV5F0EXST);
	}
	//PE7
	if((NbConfig->PciePE7==0)||(NbConfig->PcieRP==0))
		AsiaPcieModify16(PcieBase, CHX002_APIC|((UINT64)D0F5_DEV_EXIST_REG_SPACE << 32), D0F5_RDV5F1EXST, 0);
	else{	
		AsiaPcieModify16(PcieBase, CHX002_APIC|((UINT64)D0F5_DEV_EXIST_REG_SPACE << 32), D0F5_RDV5F1EXST, D0F5_RDV5F1EXST);
	}
	//;lna_debug - 20161014 - end
#ifdef ZX_DUALSOCKET	
//#ifdef DUAL_SOCKET_CODE
//SLAVE_PE0
     if((NbConfig->Slave_PciePE0==0)||(NbConfig->Slave_PcieRP==0))	
	    AsiaPcieModify16(PcieBase, CHX002_APIC_SLAVE|((UINT64)D0F5_DEV_EXIST_REG_SPACE << 32), D0F5_RDV3F0EXST, 0);
     else{
		AsiaPcieModify16(PcieBase, CHX002_APIC_SLAVE|((UINT64)D0F5_DEV_EXIST_REG_SPACE << 32), D0F5_RDV3F0EXST, D0F5_RDV3F0EXST);
   }
//SLAVE_PE1
     if((NbConfig->Slave_PciePE1==0)||(NbConfig->Slave_PcieRP==0))	
	    AsiaPcieModify16(PcieBase, CHX002_APIC_SLAVE|((UINT64)D0F5_DEV_EXIST_REG_SPACE << 32), D0F5_RDV3F1EXST, 0);
     else{
		AsiaPcieModify16(PcieBase, CHX002_APIC_SLAVE|((UINT64)D0F5_DEV_EXIST_REG_SPACE << 32), D0F5_RDV3F1EXST, D0F5_RDV3F1EXST);
	}
//SLAVE_PE2
     if((NbConfig->Slave_PciePE2==0)||(NbConfig->Slave_PcieRP==0))	
	    AsiaPcieModify16(PcieBase, CHX002_APIC_SLAVE|((UINT64)D0F5_DEV_EXIST_REG_SPACE << 32), D0F5_RDV3F2EXST, 0);
     else{
		AsiaPcieModify16(PcieBase, CHX002_APIC_SLAVE|((UINT64)D0F5_DEV_EXIST_REG_SPACE << 32), D0F5_RDV3F2EXST, D0F5_RDV3F2EXST);
	}
//SLAVE_PE3
     if((NbConfig->Slave_PciePE3==0)||(NbConfig->Slave_PcieRP==0))	
	    AsiaPcieModify16(PcieBase, CHX002_APIC_SLAVE|((UINT64)D0F5_DEV_EXIST_REG_SPACE << 32), D0F5_RDV3F3EXST, 0);
     else{
		AsiaPcieModify16(PcieBase, CHX002_APIC_SLAVE|((UINT64)D0F5_DEV_EXIST_REG_SPACE << 32), D0F5_RDV3F3EXST, D0F5_RDV3F3EXST);
	}
//SLAVE_PE4
     if((NbConfig->Slave_PciePE4==0)||(NbConfig->Slave_PcieRP==0))	
	    AsiaPcieModify16(PcieBase, CHX002_APIC_SLAVE|((UINT64)D0F5_DEV_EXIST_REG_SPACE << 32), D0F5_RDV4F0EXST, 0);
     else{
		AsiaPcieModify16(PcieBase, CHX002_APIC_SLAVE|((UINT64)D0F5_DEV_EXIST_REG_SPACE << 32), D0F5_RDV4F0EXST, D0F5_RDV4F0EXST);
	}
//SLAVE_PE5
     if((NbConfig->Slave_PciePE5==0)||(NbConfig->Slave_PcieRP==0))	
	    AsiaPcieModify16(PcieBase, CHX002_APIC_SLAVE|((UINT64)D0F5_DEV_EXIST_REG_SPACE << 32), D0F5_RDV4F1EXST, 0);
     else{
		AsiaPcieModify16(PcieBase, CHX002_APIC_SLAVE|((UINT64)D0F5_DEV_EXIST_REG_SPACE << 32), D0F5_RDV4F1EXST, D0F5_RDV4F1EXST);
	}
//SLAVE_PE6
     if((NbConfig->Slave_PciePE6==0)||(NbConfig->Slave_PcieRP==0))	
	    AsiaPcieModify16(PcieBase, CHX002_APIC_SLAVE|((UINT64)D0F5_DEV_EXIST_REG_SPACE << 32), D0F5_RDV5F0EXST, 0);
     else{
		AsiaPcieModify16(PcieBase, CHX002_APIC_SLAVE|((UINT64)D0F5_DEV_EXIST_REG_SPACE << 32), D0F5_RDV5F0EXST, D0F5_RDV5F0EXST);
	}
//SLAVE_PE7
	if((NbConfig->Slave_PciePE7==0)||(NbConfig->Slave_PcieRP==0))  
	    AsiaPcieModify16(PcieBase, CHX002_APIC_SLAVE|((UINT64)D0F5_DEV_EXIST_REG_SPACE << 32), D0F5_RDV5F1EXST, 0);
	else{
		AsiaPcieModify16(PcieBase, CHX002_APIC_SLAVE|((UINT64)D0F5_DEV_EXIST_REG_SPACE << 32), D0F5_RDV5F1EXST, D0F5_RDV5F1EXST);
	}
	// JNY Modify for pcie disable -E
#endif	
	
	
//#else
	//to avoid compile error
//	Bool = TRUE;
//	Data16 = 0;
#endif

}

/**
  PCIE Common EPHY patch function.
  This function was a CHX002 special patch for EPHY default value
  Details
	  for FRP00~15_RCVPWRSW_G1/2/3 all 48 bits in EPHY Space, 
	  they have no correct value in default.  BIOS need to patch this 
	  issue and set those value to 1b

  @param  PeiServices	EFI_PEI_SERVICES pointer.
  @param  pNbConfig  point to ASIA_NB_CONFIGURATION
  @param PhyBar

  @return The value from this function.

**/

EFI_STATUS
PCIeCommonEphyPatch(
	IN EFI_PEI_SERVICES **PeiServices,
	IN ASIA_NB_CONFIGURATION *NbConfig,
	IN UINT64 PhyBar)
{

	AsiaMemoryModify8(PhyBar + PCIEPHYCFG_RCV_LANE00_G1,PCIEPHYCFG_FRP00_RCVPWRSW_G1,PCIEPHYCFG_FRP00_RCVPWRSW_G1);
	AsiaMemoryModify8(PhyBar + PCIEPHYCFG_RCV_LANE00_G2,PCIEPHYCFG_FRP00_RCVPWRSW_G2,PCIEPHYCFG_FRP00_RCVPWRSW_G2);
	AsiaMemoryModify8(PhyBar + PCIEPHYCFG_RCV_LANE00_G3,PCIEPHYCFG_FRP00_RCVPWRSW_G3,PCIEPHYCFG_FRP00_RCVPWRSW_G3);

	AsiaMemoryModify8(PhyBar + PCIEPHYCFG_RCV_LANE01_G1,PCIEPHYCFG_FRP01_RCVPWRSW_G1,PCIEPHYCFG_FRP01_RCVPWRSW_G1);
	AsiaMemoryModify8(PhyBar + PCIEPHYCFG_RCV_LANE01_G2,PCIEPHYCFG_FRP01_RCVPWRSW_G2,PCIEPHYCFG_FRP01_RCVPWRSW_G2);
	AsiaMemoryModify8(PhyBar + PCIEPHYCFG_RCV_LANE01_G3,PCIEPHYCFG_FRP01_RCVPWRSW_G3,PCIEPHYCFG_FRP01_RCVPWRSW_G3);

	AsiaMemoryModify8(PhyBar + PCIEPHYCFG_RCV_LANE02_G1,PCIEPHYCFG_FRP02_RCVPWRSW_G1,PCIEPHYCFG_FRP02_RCVPWRSW_G1);
	AsiaMemoryModify8(PhyBar + PCIEPHYCFG_RCV_LANE02_G2,PCIEPHYCFG_FRP02_RCVPWRSW_G2,PCIEPHYCFG_FRP02_RCVPWRSW_G2);
	AsiaMemoryModify8(PhyBar + PCIEPHYCFG_RCV_LANE02_G3,PCIEPHYCFG_FRP02_RCVPWRSW_G3,PCIEPHYCFG_FRP02_RCVPWRSW_G3);
	
	AsiaMemoryModify8(PhyBar + PCIEPHYCFG_RCV_LANE03_G1,PCIEPHYCFG_FRP03_RCVPWRSW_G1,PCIEPHYCFG_FRP03_RCVPWRSW_G1);
	AsiaMemoryModify8(PhyBar + PCIEPHYCFG_RCV_LANE03_G2,PCIEPHYCFG_FRP03_RCVPWRSW_G2,PCIEPHYCFG_FRP03_RCVPWRSW_G2);
	AsiaMemoryModify8(PhyBar + PCIEPHYCFG_RCV_LANE03_G3,PCIEPHYCFG_FRP03_RCVPWRSW_G3,PCIEPHYCFG_FRP03_RCVPWRSW_G3);

	AsiaMemoryModify8(PhyBar + PCIEPHYCFG_RCV_LANE04_G1,PCIEPHYCFG_FRP04_RCVPWRSW_G1,PCIEPHYCFG_FRP04_RCVPWRSW_G1);
	AsiaMemoryModify8(PhyBar + PCIEPHYCFG_RCV_LANE04_G2,PCIEPHYCFG_FRP04_RCVPWRSW_G2,PCIEPHYCFG_FRP04_RCVPWRSW_G2);
	AsiaMemoryModify8(PhyBar + PCIEPHYCFG_RCV_LANE04_G3,PCIEPHYCFG_FRP04_RCVPWRSW_G3,PCIEPHYCFG_FRP04_RCVPWRSW_G3);

	AsiaMemoryModify8(PhyBar + PCIEPHYCFG_RCV_LANE05_G1,PCIEPHYCFG_FRP05_RCVPWRSW_G1,PCIEPHYCFG_FRP05_RCVPWRSW_G1);
	AsiaMemoryModify8(PhyBar + PCIEPHYCFG_RCV_LANE05_G2,PCIEPHYCFG_FRP05_RCVPWRSW_G2,PCIEPHYCFG_FRP05_RCVPWRSW_G2);
	AsiaMemoryModify8(PhyBar + PCIEPHYCFG_RCV_LANE05_G3,PCIEPHYCFG_FRP05_RCVPWRSW_G3,PCIEPHYCFG_FRP05_RCVPWRSW_G3);

	AsiaMemoryModify8(PhyBar + PCIEPHYCFG_RCV_LANE06_G1,PCIEPHYCFG_FRP06_RCVPWRSW_G1,PCIEPHYCFG_FRP06_RCVPWRSW_G1);
	AsiaMemoryModify8(PhyBar + PCIEPHYCFG_RCV_LANE06_G2,PCIEPHYCFG_FRP06_RCVPWRSW_G2,PCIEPHYCFG_FRP06_RCVPWRSW_G2);
	AsiaMemoryModify8(PhyBar + PCIEPHYCFG_RCV_LANE06_G3,PCIEPHYCFG_FRP06_RCVPWRSW_G3,PCIEPHYCFG_FRP06_RCVPWRSW_G3);

	AsiaMemoryModify8(PhyBar + PCIEPHYCFG_RCV_LANE07_G1,PCIEPHYCFG_FRP07_RCVPWRSW_G1,PCIEPHYCFG_FRP07_RCVPWRSW_G1);
	AsiaMemoryModify8(PhyBar + PCIEPHYCFG_RCV_LANE07_G2,PCIEPHYCFG_FRP07_RCVPWRSW_G2,PCIEPHYCFG_FRP07_RCVPWRSW_G2);
	AsiaMemoryModify8(PhyBar + PCIEPHYCFG_RCV_LANE07_G3,PCIEPHYCFG_FRP07_RCVPWRSW_G3,PCIEPHYCFG_FRP07_RCVPWRSW_G3);

	AsiaMemoryModify8(PhyBar + PCIEPHYCFG_RCV_LANE08_G1,PCIEPHYCFG_FRP08_RCVPWRSW_G1,PCIEPHYCFG_FRP08_RCVPWRSW_G1);
	AsiaMemoryModify8(PhyBar + PCIEPHYCFG_RCV_LANE08_G2,PCIEPHYCFG_FRP08_RCVPWRSW_G2,PCIEPHYCFG_FRP08_RCVPWRSW_G2);
	AsiaMemoryModify8(PhyBar + PCIEPHYCFG_RCV_LANE08_G3,PCIEPHYCFG_FRP08_RCVPWRSW_G3,PCIEPHYCFG_FRP08_RCVPWRSW_G3);

	AsiaMemoryModify8(PhyBar + PCIEPHYCFG_RCV_LANE09_G1,PCIEPHYCFG_FRP09_RCVPWRSW_G1,PCIEPHYCFG_FRP09_RCVPWRSW_G1);
	AsiaMemoryModify8(PhyBar + PCIEPHYCFG_RCV_LANE09_G2,PCIEPHYCFG_FRP09_RCVPWRSW_G2,PCIEPHYCFG_FRP09_RCVPWRSW_G2);
	AsiaMemoryModify8(PhyBar + PCIEPHYCFG_RCV_LANE09_G3,PCIEPHYCFG_FRP09_RCVPWRSW_G3,PCIEPHYCFG_FRP09_RCVPWRSW_G3);

	AsiaMemoryModify8(PhyBar + PCIEPHYCFG_RCV_LANE10_G1,PCIEPHYCFG_FRP10_RCVPWRSW_G1,PCIEPHYCFG_FRP10_RCVPWRSW_G1);
	AsiaMemoryModify8(PhyBar + PCIEPHYCFG_RCV_LANE10_G2,PCIEPHYCFG_FRP10_RCVPWRSW_G2,PCIEPHYCFG_FRP10_RCVPWRSW_G2);
	AsiaMemoryModify8(PhyBar + PCIEPHYCFG_RCV_LANE10_G3,PCIEPHYCFG_FRP10_RCVPWRSW_G3,PCIEPHYCFG_FRP10_RCVPWRSW_G3);

	AsiaMemoryModify8(PhyBar + PCIEPHYCFG_RCV_LANE11_G1,PCIEPHYCFG_FRP11_RCVPWRSW_G1,PCIEPHYCFG_FRP11_RCVPWRSW_G1);
	AsiaMemoryModify8(PhyBar + PCIEPHYCFG_RCV_LANE11_G2,PCIEPHYCFG_FRP11_RCVPWRSW_G2,PCIEPHYCFG_FRP11_RCVPWRSW_G2);
	AsiaMemoryModify8(PhyBar + PCIEPHYCFG_RCV_LANE11_G3,PCIEPHYCFG_FRP11_RCVPWRSW_G3,PCIEPHYCFG_FRP11_RCVPWRSW_G3);

	AsiaMemoryModify8(PhyBar + PCIEPHYCFG_RCV_LANE12_G1,PCIEPHYCFG_FRP12_RCVPWRSW_G1,PCIEPHYCFG_FRP12_RCVPWRSW_G1);
	AsiaMemoryModify8(PhyBar + PCIEPHYCFG_RCV_LANE12_G2,PCIEPHYCFG_FRP12_RCVPWRSW_G2,PCIEPHYCFG_FRP12_RCVPWRSW_G2);
	AsiaMemoryModify8(PhyBar + PCIEPHYCFG_RCV_LANE12_G3,PCIEPHYCFG_FRP12_RCVPWRSW_G3,PCIEPHYCFG_FRP12_RCVPWRSW_G3);

	AsiaMemoryModify8(PhyBar + PCIEPHYCFG_RCV_LANE13_G1,PCIEPHYCFG_FRP13_RCVPWRSW_G1,PCIEPHYCFG_FRP13_RCVPWRSW_G1);
	AsiaMemoryModify8(PhyBar + PCIEPHYCFG_RCV_LANE13_G2,PCIEPHYCFG_FRP13_RCVPWRSW_G2,PCIEPHYCFG_FRP13_RCVPWRSW_G2);
	AsiaMemoryModify8(PhyBar + PCIEPHYCFG_RCV_LANE13_G3,PCIEPHYCFG_FRP13_RCVPWRSW_G3,PCIEPHYCFG_FRP13_RCVPWRSW_G3);

	AsiaMemoryModify8(PhyBar + PCIEPHYCFG_RCV_LANE14_G1,PCIEPHYCFG_FRP14_RCVPWRSW_G1,PCIEPHYCFG_FRP14_RCVPWRSW_G1);
	AsiaMemoryModify8(PhyBar + PCIEPHYCFG_RCV_LANE14_G2,PCIEPHYCFG_FRP14_RCVPWRSW_G2,PCIEPHYCFG_FRP14_RCVPWRSW_G2);
	AsiaMemoryModify8(PhyBar + PCIEPHYCFG_RCV_LANE14_G3,PCIEPHYCFG_FRP14_RCVPWRSW_G3,PCIEPHYCFG_FRP14_RCVPWRSW_G3);

	AsiaMemoryModify8(PhyBar + PCIEPHYCFG_RCV_LANE15_G1,PCIEPHYCFG_FRP15_RCVPWRSW_G1,PCIEPHYCFG_FRP15_RCVPWRSW_G1);
	AsiaMemoryModify8(PhyBar + PCIEPHYCFG_RCV_LANE15_G2,PCIEPHYCFG_FRP15_RCVPWRSW_G2,PCIEPHYCFG_FRP15_RCVPWRSW_G2);
	AsiaMemoryModify8(PhyBar + PCIEPHYCFG_RCV_LANE15_G3,PCIEPHYCFG_FRP15_RCVPWRSW_G3,PCIEPHYCFG_FRP15_RCVPWRSW_G3);


	//EPHY RxE5[2] , BIOS need to set it defaultly , this avoid 'SpeedChange' bit set in TS when no need to send it.
	//Whether consider EP support what speed when software set LCRL to do speed change
	//0: phyls will enter Recovery state to do speed change when LCRL and LKTGLS have been set
	//1: phyls will not enter Recovery state if EP does not support current target speed
	AsiaMemoryModify8(PhyBar + PCIEPHYCFG_MISC,PCIEPHYCFG_RSPDCH,PCIEPHYCFG_RSPDCH);
	
	
	return EFI_SUCCESS;
}

/**
   PCIE Down order queue timing set function.
   
  This function used to set RTRANS2TFIX, Downstream Ordering Queue Timing Option.
  Details
  Downstream Ordering Queue Timing Option Programming rule:
  
  1. IRS description: 
  Rx1A2 [7] = 0: 1T setup time		  1: 2T setup time
  
  If Root Complex is connected to PCIe Endpoint, there is no problem.  
  Because PCIe spec requires Endpoint CPL credits to be infinite.  
  But if Root Complex is connected to "PCIe Switch", the CPL credits are finite.  
  It may cause ERROR.  Need change this bit (RTRANS2TFIX) to 1.
  
  2. Check policy
	  a. Check EP PCIE Capability.
	  b. Check Device/Port Type in offset 0x02
	  c. Check [7:4] = 0x05 Upstream Port of PCI Express Switch
	  d. If EP is Upstream Port of PCI Express Switch, Set Rx1A2[7] = 1 then break this routine
  
  3. Header define name:
  CHX001: D2D5F1_DOWNSTREAM_CTL_3 , D2D5F1_RTRANS2TFIX

  @param  PeiServices	EFI_PEI_SERVICES pointer.
  @param RpBusNum
  @param RpDeviceNum
  @param RpFuncNum
  @param  pNbConfig  point to ASIA_NB_CONFIGURATION
  @param PortSPEValue

  @return VOID.

**/

VOID
PCIEDnOrderingQueueTiming(
	IN EFI_PEI_SERVICES **PeiServices,
    IN UINT8	RpBusNum,
    IN UINT8	RpDeviceNum,
    IN UINT8	RpFuncNum,
    IN ASIA_NB_CONFIGURATION *NbConfig,
    IN UINT8    PortSPEValue){

	UINT8 SlotCap, PcieCapSts, DevicePortType, secBus;
    UINT16 PcieCapOff = 0;
	EFI_STATUS Statusx = EFI_SUCCESS;
	BOOLEAN Assigned = FALSE;
	
	PEI_DEBUG((PeiServices, EFI_D_ERROR, "PCIEDnOrderingQueueTiming bus %d, dev %d, fun %d\n",RpBusNum,RpDeviceNum,RpFuncNum));				

	// If Root Port Slot Capabilities support Hot Plug, set Downstream Ordering Queue Timing Option = 2T
    SlotCap = AsiaPciRead8(AsiaPciAddress(RpBusNum, RpDeviceNum, RpFuncNum, D3D5F1_SLOT_CAPS_1));
	SlotCap = SlotCap & D3D5F1_SCHP_CAP;
	
	if( SlotCap == D3D5F1_SCHP_CAP ){
		AsiaPcieModify8(NbConfig->PcieBar, (AsiaPciAddress(RpBusNum, RpDeviceNum, RpFuncNum, 
		    D3D5F1_DOWNSTREAM_CTL_3)), D3D5F1_RTRANS2TFIX, D3D5F1_RTRANS2TFIX);
		return;
    }
    else{
	    secBus = AsiaPciRead8(AsiaPciAddress(RpBusNum, RpDeviceNum, RpFuncNum, 0x19));
        if(secBus == 0){
		    //Assign a temp bus resource to this bridge
		    AsiaPcieModify8(NbConfig->PcieBar,(AsiaPciAddress(RpBusNum, RpDeviceNum, RpFuncNum, 
				0x18)),0xFF,0x0);		
		    AsiaPcieModify8(NbConfig->PcieBar,(AsiaPciAddress(RpBusNum, RpDeviceNum, RpFuncNum, 
				0x19)),0xFF,0x1);
		    AsiaPcieModify8(NbConfig->PcieBar,(AsiaPciAddress(RpBusNum, RpDeviceNum, RpFuncNum, 
				0x1A)),0xFF,0x1);
			Assigned = TRUE;
    	}
	
	    secBus = AsiaPciRead8(AsiaPciAddress(RpBusNum, RpDeviceNum, RpFuncNum, 0x19));
	
	    //Search PCI Express Capability
	    Statusx = PCIeSearchCapOffset(PeiServices,NbConfig,secBus,0,0,
						0,0x10,&PcieCapOff);

	    if(Statusx == EFI_SUCCESS){
	        PcieCapSts = AsiaPciRead8(AsiaPciAddress(secBus, 0, 0, PcieCapOff + 0x02));
	        DevicePortType = ((PcieCapSts >> 4) & 0x0F);
	        PEI_DEBUG((PeiServices, EFI_D_ERROR, "PCIEDnOrderingQueueTiming DevicePortType 0x%x\n",DevicePortType));				
	        if( DevicePortType == 0x05 ){
	 		 	AsiaPcieModify8(NbConfig->PcieBar, (AsiaPciAddress(RpBusNum, RpDeviceNum, RpFuncNum, 
					D3D5F1_DOWNSTREAM_CTL_3)), D3D5F1_RTRANS2TFIX, D3D5F1_RTRANS2TFIX);
				goto __Exit;
	 	    }
	    }
	    
		if(PortSPEValue >= DEVICE_SPE_VALUE_PERFORMANCE){
		 	AsiaPcieModify8(NbConfig->PcieBar, (AsiaPciAddress(RpBusNum, RpDeviceNum, RpFuncNum, 
			   D3D5F1_DOWNSTREAM_CTL_3)), D3D5F1_RTRANS2TFIX, 0);
		}
		else{
		 	AsiaPcieModify8(NbConfig->PcieBar, (AsiaPciAddress(RpBusNum, RpDeviceNum, RpFuncNum, 
			  D3D5F1_DOWNSTREAM_CTL_3)), D3D5F1_RTRANS2TFIX, D3D5F1_RTRANS2TFIX); 
		} 
	}
 __Exit:
 	
    if (Assigned == TRUE){
        AsiaPcieModify8(NbConfig->PcieBar,(AsiaPciAddress(RpBusNum, RpDeviceNum, RpFuncNum, 
			0x18)),0xFF,0x0);		
		AsiaPcieModify8(NbConfig->PcieBar,(AsiaPciAddress(RpBusNum, RpDeviceNum, RpFuncNum, 
			0x19)),0xFF,0x0);
		AsiaPcieModify8(NbConfig->PcieBar,(AsiaPciAddress(RpBusNum, RpDeviceNum, RpFuncNum, 
			0x1A)),0xFF,0x0);
    }
	return;
}





/**
  PERST# for PCIE slot.
  
  This function call the SetGpo() to do Assert or Deassert the PERST#
  on a specific port.
   
  @param  PeiServices Describes the list of possible PEI Services.
  @param  PciAddress Target pcie RP MMIO base address 

  @retval EFI_SUCESS  PERST# GPIO operation success.
  @retval Others      Failed to operate PERST# GPIO. 

**/
EFI_STATUS
PCIeCommonPERST (
    IN EFI_PEI_SERVICES **PeiServices,
    IN UINT64 PciAddress
)
{
    EFI_STATUS Status;
    UINTN    GpioIndex;
    ASIA_SB_LIB_PPI* AsiaSbLibPpi;
    EFI_GUID AsiaSbLibPpiGuid = EFI_ASIA_SB_LIB_PPI_GUID;
#ifdef ZX_DUALSOCKET
	UINT8 SocketFlag= 0;
#endif
	
    PEI_DEBUG((PeiServices, EFI_D_ERROR, "[PCIE] PCIeCommonPERST()\n"));

    Status = (*PeiServices)->LocatePpi(
                 PeiServices, &AsiaSbLibPpiGuid, 0, NULL, &AsiaSbLibPpi);
    ASSERT_PEI_ERROR(PeiServices, Status);

    //Reset PCIE from GPO pin
    /*
                refer to SIPcieDriving.h
    */
    switch (PciAddress){

    	case CHX002_PE0:{
	        GpioIndex = GPO_Reset_PE0;                                   
	        break;
    	}
    	case CHX002_PE1:{
        	GpioIndex = GPO_Reset_PE1;                                
        	break;
    	}
	    case CHX002_PE2:{
	        GpioIndex = GPO_Reset_PE2;                                      
	        break;
	    }
	    case CHX002_PE3:{
	        GpioIndex = GPO_Reset_PE3;                                  
	        break;
	    }
	    case CHX002_PE4:{
	        GpioIndex = GPO_Reset_PE4;                                   
	        break;
	    }
	    case CHX002_PE5:{
	        GpioIndex = GPO_Reset_PE5;                                 
	        break;
	    }
	    case CHX002_PE6:{
	        GpioIndex = GPO_Reset_PE6;                                       
	        break;
	    }
	    case CHX002_PE7:{
	        GpioIndex = GPO_Reset_PE7;                               
	        break;
	    }
#ifdef ZX_DUALSOCKET
		//
    	case CHX002_PE0_SLAVE:{
	        GpioIndex = GPO_Reset_PE0_SLAVE; 
			SocketFlag = 1;
	        break;
    	}
    	case CHX002_PE1_SLAVE:{
        	GpioIndex = GPO_Reset_PE1_SLAVE; 
			SocketFlag = 1;                                  
        	break;
    	}
	    case CHX002_PE2_SLAVE:{
	        GpioIndex = GPO_Reset_PE2_SLAVE; 
			SocketFlag = 1;                                  
	        break;
	    }
	    case CHX002_PE3_SLAVE:{
	        GpioIndex = GPO_Reset_PE3_SLAVE; 
			SocketFlag = 1;                                   
	        break;
	    }
	    case CHX002_PE4_SLAVE:{
	        GpioIndex = GPO_Reset_PE4_SLAVE; 
			SocketFlag = 1;                                  
	        break;
	    }
	    case CHX002_PE5_SLAVE:{
	        GpioIndex = GPO_Reset_PE5_SLAVE;  
			SocketFlag = 1;                               
	        break;
	    }
	    case CHX002_PE6_SLAVE:{
	        GpioIndex = GPO_Reset_PE6_SLAVE; 
			SocketFlag = 1;                                 
	        break;
	    }
	    case CHX002_PE7_SLAVE:{
	        GpioIndex = GPO_Reset_PE7_SLAVE; 
			SocketFlag = 1;                                          
	        break;
	    }
#endif		
    	default:

		return EFI_INVALID_PARAMETER;
    }


#ifdef ZX_DUALSOCKET
	if(SocketFlag == 0){
		Status = AsiaSbLibPpi->SetGpo(PeiServices, GpioIndex, FALSE,FALSE);
		PeiNbPcieStall(PeiServices, 0x14);	//20 ms
		Status = AsiaSbLibPpi->SetGpo(PeiServices, GpioIndex, TRUE,FALSE);		  
		PeiNbPcieStall(PeiServices, 0x64);	//100 ms
	}else if(SocketFlag == 1){
		Status = AsiaSbLibPpi->SetGpo(PeiServices, GpioIndex, FALSE,FALSE);
		PeiNbPcieStall(PeiServices, 0x14);	//20 ms
		Status = AsiaSbLibPpi->SetGpo(PeiServices, GpioIndex, TRUE,FALSE);		  
		PeiNbPcieStall(PeiServices, 0x64);	//100 ms
	}
#else
    Status = AsiaSbLibPpi->SetGpo(PeiServices, GpioIndex, FALSE);
    PeiNbPcieStall(PeiServices, 0x14);  //20 ms
    Status = AsiaSbLibPpi->SetGpo(PeiServices, GpioIndex, TRUE);        
    PeiNbPcieStall(PeiServices, 0x64);  //100 ms
#endif

    return Status;
}





/**
   PCIE Do EQ function in S3 resume phase.
   This function must be called in S3 process

  @param  PeiServices	EFI_PEI_SERVICES pointer.
  @param  pNbConfig  point to ASIA_NB_CONFIGURATION
  @param PciAddress Target pcie device's address

  @return The value from this function.

**/

EFI_STATUS
PeiNbPcieS3DoEQ(
	IN EFI_PEI_SERVICES **PeiServices,
	IN ASIA_NB_CONFIGURATION *NbConfig,
	UINT64 PciAddress)
{
//	EFI_BOOT_MODE BootMode;	
	UINT8 tmp8;
	UINT8 WaitCounter = 200;
	//
	//S3 DO_EQ 
	//
//	(*PeiServices)->GetBootMode (PeiServices, &BootMode);
//	PEI_DEBUG((PeiServices, EFI_D_ERROR, "PeiNbPcieS3DoEQ() - BootMode:%x\n",BootMode));

//	if(BootMode == BOOT_ON_S3_RESUME){
		tmp8 = AsiaPcieRead8(NbConfig->PcieBar, PciAddress|((UINT64)(D3D5F1_LINK_CAPS_1_D4F0) << 32)) & (D3D5F1_LKMAXLS_0 + D3D5F1_LKMAXLS_1 + D3D5F1_LKMAXLS_2 + D3D5F1_LKMAXLS_3);
		// Target Link-Speed to GEN3 with Do-EQ mechanism
		if((tmp8 == (D3D5F1_LKMAXLS_0 + D3D5F1_LKMAXLS_1)) && (NbConfig->PcieEQ == DOEQ)){	
			//if this port want to do EQ phase2/3
			if(D3D5F1_RWTEXEPH23 & AsiaPcieRead8(NbConfig->PcieBar,PciAddress|((UINT64)D3D5F1_MISC_CTL << 32))){
				PEI_DEBUG((PeiServices, EFI_D_ERROR, "-DoEQ "));
				AsiaPcieModify8(NbConfig->PcieBar, PciAddress|((UINT64)D3D5F1_LINK_CTL_2_D4F0 << 32), D3D5F1_LKTGLS_0 + D3D5F1_LKTGLS_1 + D3D5F1_LKTGLS_2 + D3D5F1_LKTGLS_3, D3D5F1_LKTGLS_0 + D3D5F1_LKTGLS_1);
				AsiaPcieModify8(NbConfig->PcieBar, PciAddress|((UINT64)D3D5F1_LKTGLS_INTER_AND_NEED_EQTS << 32), D3D5F1_LKTGLS_INTER, D3D5F1_LKTGLS_INTER); 	
				AsiaPcieModify8(NbConfig->PcieBar, PciAddress|((UINT64)D3D5F1_LINK_CTL_1 << 32), D3D5F1_LCRL, D3D5F1_LCRL); //Retrain Link	
				
			}

			while(WaitCounter--){
				if(0x8A == AsiaPcieRead8(NbConfig->PcieBar, PciAddress|((UINT64)(D3D5F1_PHYLS_LTSSM_STATE) << 32)) ){
					break;
				}
				//gBS->Stall(1000); //wait max to 200ms
				PeiNbPcieStall(PeiServices, 1); 
			}

			PEI_DEBUG((PeiServices, EFI_D_ERROR, "-CurrentLinkSpeed:\n",
						AsiaPcieRead8(NbConfig->PcieBar, PciAddress|((UINT64)(D3D5F1_LINK_STA_1) << 32))));
		}

//	}

	return EFI_SUCCESS;
}





