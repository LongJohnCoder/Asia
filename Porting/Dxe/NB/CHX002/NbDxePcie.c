/** @file
   ZX-E(CHX002) Asia NbDxe library functions : NbDxePcie.c

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
#include EFI_PROTOCOL_DEFINITION(AsiaCpuProtocol)
#include EFI_PROTOCOL_DEFINITION(PciHostBridgeResourceAllocation)
#include EFI_PROTOCOL_DEFINITION(PciIo)
#include EFI_PROTOCOL_DEFINITION(AsiaSbProtocol)

#include "AsiaIoSaveLib.h"

#include "CHX002Cfg.h"
#include "CHX002Reg.h"
#include "NbDxePcie.h"

#include "EfiDriverLib.h"
#include EFI_GUID_DEFINITION(Hob)
#include "EfiHobLib.h"
#include "EfiScriptLib.h"


/**
  Function description.
  
  @param  PeiServices	EFI_PEI_SERVICES pointer.
  @param NbCfg Point to ASIA_NB_CONFIGURATION struct.

  @return EFI_STATUS.

**/


VOID
DumpMemDxe(
	UINT64 MemBase, 
	UINT16 DCount)
{

	UINT16 offsetx = 0;
	UINT8 readback8;
	DEBUG((EFI_D_ERROR, "[PCIE_DXE] DumpMem(Base:0x%08x, Count:0x%04x):\n",MemBase, DCount));
	DEBUG((EFI_D_ERROR, "\n0x%04x: ",offsetx+1));
	for(offsetx = 0; offsetx < DCount; offsetx++){
		readback8 = AsiaMemoryRead8(MemBase + offsetx);
		DEBUG((EFI_D_ERROR, "%02X ",readback8));
		if(offsetx != (DCount -1)){
			if((offsetx & 0xFF) == 0xFF){
				DEBUG((EFI_D_ERROR, "\n\n        00 01 02 03 04 05 06 07 08 09 0A 0B 0C 0D 0E 0F"));
				DEBUG((EFI_D_ERROR, "\n        -----------------------------------------------"));
			}
		}	
		if((offsetx & 0xF) == 0xF){
			DEBUG((EFI_D_ERROR, "\n0x%04x: ",offsetx+1));
		}
		
	}
	DEBUG((EFI_D_ERROR, "\n"));
}

/**
  Function description.
  
  @param  PeiServices	EFI_PEI_SERVICES pointer.
  @param NbCfg Point to ASIA_NB_CONFIGURATION struct.

  @return EFI_STATUS.

**/

VOID
DumpCfgDxe(
	UINT64 PcieBase,
	UINT8 Busx,
	UINT8 Devx, 
	UINT8 Funx, 
	UINT16 DCount)
{

	UINT16 offsetx = 0;
	UINT8 readback8;
	DEBUG((EFI_D_ERROR, "[PCIE_DXE] DumpCfg([%d|%d|%d] Count:0x%08x):\n",Busx,Devx,Funx,DCount));
	DEBUG((EFI_D_ERROR, "\n0x%04x: ",offsetx+1));
	for(offsetx = 0; offsetx < DCount; offsetx++){
		readback8 = AsiaPcieRead8(PcieBase, AsiaPciAddress(Busx, Devx, Funx, offsetx));
		DEBUG((EFI_D_ERROR, "%02X ",readback8));
		if(offsetx != (DCount -1)){
			if((offsetx & 0xFF) == 0xFF){
				DEBUG((EFI_D_ERROR, "\n\n        00 01 02 03 04 05 06 07 08 09 0A 0B 0C 0D 0E 0F"));
				DEBUG((EFI_D_ERROR, "\n        -----------------------------------------------"));
			}
		}
		if((offsetx & 0xF) == 0xF){
			DEBUG((EFI_D_ERROR, "\n0x%04x: ",offsetx+1));
		}
		
	}
	DEBUG((EFI_D_ERROR, "\n"));
}



/**
  Function description.
  
  @param  PeiServices	EFI_PEI_SERVICES pointer.
  @param NbCfg Point to ASIA_NB_CONFIGURATION struct.

  @return EFI_STATUS.

**/
EFI_STATUS PcieTopo(
    UINT8 Bus,
    UINT8 Dev,
    UINT8 Func,
    PCIE_RESOURCE* Ptr
)
{


    UINT32	Data32;
    UINT8	ChldBus, ChldDev, ChldFunc;
    UINT8 	Data8;
    BOOLEAN Bridge;
    UINTN 	Pos;
    UINT8 	PcieCapability;

    Data32 = AsiaPciRead32(AsiaPciAddress(Bus, Dev, Func, 0x00));

    if(Data32 != 0xFFFFFFFF)
    {
        Pos = Ptr->PcieNodeNum;
        Ptr->PcieNodeTbl[Pos].BusNum = Bus;
        Ptr->PcieNodeTbl[Pos].DevNum = Dev;
        Ptr->PcieNodeTbl[Pos].FuncNum = Func;
		Ptr->PcieNodeTbl[Pos].AspmSupported = 0xFF; 
		Ptr->PcieNodeTbl[Pos].SecBusNum = 0xFF;
		/*+ DSZ_Porting -- (YSW-20170303) Update PCIE Module Code for the programming of Common Clock Configuration*/
		Ptr->PcieNodeTbl[Pos].SlotClkCfg = 0xFF;
		/*- DSZ_Porting -- (YSW-20170303) Update PCIE Module Code for the programming of Common Clock Configuration*/
        Ptr->PcieNodeNum++;

		DEBUG((EFI_D_ERROR, "[PCIE-POST-PCI] %a() Scanning PCIE Tree - Current:(%02x:%02x.%02x)hex\n",__FUNCTION__,Bus, Dev, Func));

        //Get PCIE Capacity Offset
        PcieCapability = AsiaPciRead8(AsiaPciAddress(Bus, Dev, Func, 0x34));
        while(PcieCapability != 0x00)
        {
            //read CAP ID
            Data8 = AsiaPciRead8(AsiaPciAddress(Bus, Dev, Func, PcieCapability));
            if (Data8 == 0x10)
            {
                break;
            }
            PcieCapability = AsiaPciRead8(AsiaPciAddress(Bus, Dev, Func, PcieCapability + 1));
        }
        Ptr->PcieNodeTbl[Pos].PcieCapOff = PcieCapability;

        if(PcieCapability == 0x00){							 
            Ptr->PcieNodeTbl[Pos].PcieCapOff = 0xFF;

			DEBUG((EFI_D_ERROR, "                PCIE Capability not found!! Skip PCIE Topology Search under this PCI Component\n"));

			return EFI_SUCCESS;
        }

        //Get PCIE MAX PayLoad Size
        Data8 = AsiaPciRead8(AsiaPciAddress(Bus, Dev, Func, PcieCapability + 4));
        Data8 &= 0x07;
        if(Ptr->MinMpsSupport > Data8)
            Ptr->MinMpsSupport = Data8;
 		/*+ DSZ_Porting -- (YSW-20170303) Update PCIE Module Code for the programming of Common Clock Configuration*/
        //Get PCIE Slot Clock Configuration Setting
        Data8 = AsiaPciRead8(AsiaPciAddress(Bus, Dev, Func, PcieCapability + 0x13));
        Data8 = ((Data8 & 0x10) >> 4);
        Ptr->PcieNodeTbl[Pos].SlotClkCfg = Data8;	//0/1: Common/Independent reference clock; 0xFF: not scaned
 		/*- DSZ_Porting -- (YSW-20170303) Update PCIE Module Code for the programming of Common Clock Configuration*/

        //Search Child Node
        Data8 = AsiaPciRead8(AsiaPciAddress(Bus, Dev, Func, 0x0E));
        Bridge = ((Data8 & (~0x80)) == 0x01) ? TRUE : FALSE;
        //Post PCI, secondary bus has been already allocated. otherwise, increase bus no. to emurate Node's child device.
        if(Bridge)	//Bridge
        {
            ChldBus = AsiaPciRead8(AsiaPciAddress(Bus, Dev, Func, 0x19)); //secondary bus no.
            Ptr->PcieNodeTbl[Pos].SecBusNum = ChldBus;
        }
        else
        {
			DEBUG((EFI_D_ERROR, "                Reach the EP; Stop PCIE Topology Search under this PCI Component\n"));
            return EFI_SUCCESS;
        }
        for(ChldDev = 0; ChldDev < 0x20; ChldDev++)
        {
            for(ChldFunc = 0; ChldFunc < 0x08; ChldFunc++)		//for every device attached to a bus, run PcieTopo()
            {
                PcieTopo(ChldBus, ChldDev, ChldFunc, Ptr);		//recursive function
            }
        }
    }

    return EFI_SUCCESS;
} 

//CHX001-CJW-20151021 -start    
/*
VOID EphyAggresivePmMode(
    ASIA_NB_CONFIGURATION *NbCfg
)
{
	//CHX001-CJW-20151021 if all rp disabled, shutdown TPLL/MPLL/EPHY's power
    if((!NbCfg->PcieRP) || ((!NbCfg->PciePEG) && (!NbCfg->PciePE0) && (!NbCfg->PciePE1) && (!NbCfg ->PciePE2) && (!NbCfg->PciePE3)&&(!NbCfg->PciePEG0)&&(!NbCfg->PciePEG1)&&(!NbCfg->PciePEG2)&&(!NbCfg->PciePEG3)))
    {
        //Set D0F7 EPHY_Rx42[2] = 1b (TPLL Power Down)
        AsiaPciModifySave8(CHX001_PEPHY|D0F7_EPHY0_MAIN0_TPLL0, D0F7_FHPS0_TPLLPD, D0F7_FHPS0_TPLLPD);

        //Set D0F7 EPHY_Rx41[0] = 1b (MPLL Power Down)
        AsiaPciModifySave8(CHX001_PEPHY|D0F7_EPHY0_MPLL0, D0F7_FHP_MPLL0PD, D0F7_FHP_MPLL0PD);

        //Set D0F5 RxF1[6] = 0(Disable PCIE_EPHY)
        //AsiaPciModifySave8(CHX002_APIC|D0F5_PCIE_DEVS_REG_SPACE, D0F5_RDV0F7EXST, 0);
        AsiaPciModifySave32(CHX002_APIC|D0F5_DEV_EXIST_REG_SPACE, D0F5_RDV2F0EXST|D0F5_RDV3F0EXST|D0F5_RDV3F1EXST|D0F5_RDV3F2EXST||D0F5_RDV4F0EXST|D0F5_RDV4F1EXST|D0F5_RDV5F0EXST|D0F5_RDV5F0EXST, 0);
		
        
    }
}
*/
//CHX001-CJW-20151021 -end




#if 0   //CJW_20170510 removed  -- not used
//Clear some status registers' content of RP
VOID ClearRpSlotStatus(
    ASIA_NB_CONFIGURATION *NbCfg
)
{
/*
    //Clear RP_Rx1F[7:4]  Secondary Status Register
    AsiaPciModifySave8(CHX002_PEG|D3D5F1_SECONDARY_STA+1, 0xF0, 0xF0);
    AsiaPciModifySave8(CHX002_PE0|D3D5F1_SECONDARY_STA+1, 0xF0, 0xF0);
    AsiaPciModifySave8(CHX002_PE1|D3D5F1_SECONDARY_STA+1, 0xF0, 0xF0);
    AsiaPciModifySave8(CHX002_PE2|D3D5F1_SECONDARY_STA+1, 0xF0, 0xF0);
    AsiaPciModifySave8(CHX002_PE3|D3D5F1_SECONDARY_STA+1, 0xF0, 0xF0);
	AsiaPciModifySave8(CHX002_PEG0|D3D5F1_SECONDARY_STA+1, 0xF0, 0xF0);
    AsiaPciModifySave8(CHX002_PEG1|D3D5F1_SECONDARY_STA+1, 0xF0, 0xF0);
	AsiaPciModifySave8(CHX002_PEG2|D3D5F1_SECONDARY_STA+1, 0xF0, 0xF0);
	AsiaPciModifySave8(CHX002_PEG3|D3D5F1_SECONDARY_STA+1, 0xF0, 0xF0);
*/
	AsiaPcieWrite8(NbCfg->PcieBar,CHX002_PEG|((UINT64)(D3D5F1_SECONDARY_STA+1) << 32),0xF0);
    AsiaPcieWrite8(NbCfg->PcieBar,CHX002_PE2|((UINT64)(D3D5F1_SECONDARY_STA+1) << 32),0xF0);

    //Clear RP_Rx4A[3:0] Device Status 1 Register
/*
    AsiaPciModifySave8(CHX002_PEG|D3D5F1_DEV_STA_1, 0x0F, 0x0F);
    AsiaPciModifySave8(CHX002_PE0|D3D5F1_DEV_STA_1, 0x0F, 0x0F);
    AsiaPciModifySave8(CHX002_PE1|D3D5F1_DEV_STA_1, 0x0F, 0x0F);
    AsiaPciModifySave8(CHX002_PE2|D3D5F1_DEV_STA_1, 0x0F, 0x0F);
    AsiaPciModifySave8(CHX002_PE3|D3D5F1_DEV_STA_1, 0x0F, 0x0F);
    AsiaPciModifySave8(CHX002_PEG0|D3D5F1_DEV_STA_1, 0x0F, 0x0F);
	AsiaPciModifySave8(CHX002_PEG1|D3D5F1_DEV_STA_1, 0x0F, 0x0F);
	AsiaPciModifySave8(CHX002_PEG2|D3D5F1_DEV_STA_1, 0x0F, 0x0F);
	AsiaPciModifySave8(CHX002_PEG3|D3D5F1_DEV_STA_1, 0x0F, 0x0F);
*/
	AsiaPcieWrite8(NbCfg->PcieBar,CHX002_PEG|((UINT64)(D3D5F1_DEV_STA_1) << 32), 0x0F);
	AsiaPcieWrite8(NbCfg->PcieBar,CHX002_PE2|((UINT64)(D3D5F1_DEV_STA_1) << 32), 0x0F);

    //Slot status	Rx5A[8,4,3,0]  Slot Status 1 Register
/*
    AsiaPciWriteSave16(CHX002_PEG|D3D5F1_SLOT_STA_1, 0xFFFF);
    AsiaPciWriteSave16(CHX002_PE0|D3D5F1_SLOT_STA_1, 0xFFFF);
    AsiaPciWriteSave16(CHX002_PE1|D3D5F1_SLOT_STA_1, 0xFFFF);
    AsiaPciWriteSave16(CHX002_PE2|D3D5F1_SLOT_STA_1, 0xFFFF);
    AsiaPciWriteSave16(CHX002_PE3|D3D5F1_SLOT_STA_1, 0xFFFF);
    AsiaPciWriteSave16(CHX002_PEG0|D3D5F1_SLOT_STA_1, 0xFFFF);
	AsiaPciWriteSave16(CHX002_PEG1|D3D5F1_SLOT_STA_1, 0xFFFF);
	AsiaPciWriteSave16(CHX002_PEG2|D3D5F1_SLOT_STA_1, 0xFFFF);
	AsiaPciWriteSave16(CHX002_PEG3|D3D5F1_SLOT_STA_1, 0xFFFF);
*/
	AsiaPcieWrite16(NbCfg->PcieBar, CHX002_PEG|((UINT64)(D3D5F1_SLOT_STA_1) << 32), 0xFFFF);
	AsiaPcieWrite16(NbCfg->PcieBar, CHX002_PE2|((UINT64)(D3D5F1_SLOT_STA_1) << 32), 0xFFFF);

    //uncorrectable errors Rx104
/*
    AsiaPcieWriteSave32(NbCfg->PcieBar, CHX002_PEG|((UINT64)(D3D5F1_UNCORRECTABLE_ERR_STA) << 32), 0xFFFFFFFF);
	AsiaPcieWriteSave32(NbCfg->PcieBar, CHX002_PE0|((UINT64)(D3D5F1_UNCORRECTABLE_ERR_STA) << 32), 0xFFFFFFFF);
	AsiaPcieWriteSave32(NbCfg->PcieBar, CHX002_PE1|((UINT64)(D3D5F1_UNCORRECTABLE_ERR_STA) << 32), 0xFFFFFFFF);
	AsiaPcieWriteSave32(NbCfg->PcieBar, CHX002_PE2|((UINT64)(D3D5F1_UNCORRECTABLE_ERR_STA) << 32), 0xFFFFFFFF);
	AsiaPcieWriteSave32(NbCfg->PcieBar, CHX002_PE3|((UINT64)(D3D5F1_UNCORRECTABLE_ERR_STA) << 32), 0xFFFFFFFF);
	AsiaPcieWriteSave32(NbCfg->PcieBar, CHX002_PEG0|((UINT64)(D3D5F1_UNCORRECTABLE_ERR_STA) << 32), 0xFFFFFFFF);
	AsiaPcieWriteSave32(NbCfg->PcieBar, CHX002_PEG1|((UINT64)(D3D5F1_UNCORRECTABLE_ERR_STA) << 32), 0xFFFFFFFF);
	AsiaPcieWriteSave32(NbCfg->PcieBar, CHX002_PEG2|((UINT64)(D3D5F1_UNCORRECTABLE_ERR_STA) << 32), 0xFFFFFFFF);
	AsiaPcieWriteSave32(NbCfg->PcieBar, CHX002_PEG3|((UINT64)(D3D5F1_UNCORRECTABLE_ERR_STA) << 32), 0xFFFFFFFF);
*/
	AsiaPcieWrite32(NbCfg->PcieBar, CHX002_PEG|((UINT64)(D3D5F1_UNCORRECTABLE_ERR_STA) << 32), 0xFFFFFFFF);
	AsiaPcieWrite32(NbCfg->PcieBar, CHX002_PE2|((UINT64)(D3D5F1_UNCORRECTABLE_ERR_STA) << 32), 0xFFFFFFFF);
	
    //corrrectable errors Rx110
/*
    AsiaPcieWriteSave32(NbCfg->PcieBar, CHX002_PEG|((UINT64)(D3D5F1_CORRECTABLE_ERR_STA) << 32), 0xFFFFFFFF);
    AsiaPcieWriteSave32(NbCfg->PcieBar, CHX002_PE0|((UINT64)(D3D5F1_CORRECTABLE_ERR_STA) << 32), 0xFFFFFFFF);    
    AsiaPcieWriteSave32(NbCfg->PcieBar, CHX002_PE1|((UINT64)(D3D5F1_CORRECTABLE_ERR_STA) << 32), 0xFFFFFFFF);  
    AsiaPcieWriteSave32(NbCfg->PcieBar, CHX002_PE2|((UINT64)(D3D5F1_CORRECTABLE_ERR_STA) << 32), 0xFFFFFFFF);
    AsiaPcieWriteSave32(NbCfg->PcieBar, CHX002_PE3|((UINT64)(D3D5F1_CORRECTABLE_ERR_STA) << 32), 0xFFFFFFFF);
    AsiaPcieWriteSave32(NbCfg->PcieBar, CHX002_PEG0|((UINT64)(D3D5F1_CORRECTABLE_ERR_STA) << 32), 0xFFFFFFFF);
	AsiaPcieWriteSave32(NbCfg->PcieBar, CHX002_PEG1|((UINT64)(D3D5F1_CORRECTABLE_ERR_STA) << 32), 0xFFFFFFFF);
	AsiaPcieWriteSave32(NbCfg->PcieBar, CHX002_PEG2|((UINT64)(D3D5F1_CORRECTABLE_ERR_STA) << 32), 0xFFFFFFFF);
	AsiaPcieWriteSave32(NbCfg->PcieBar, CHX002_PEG3|((UINT64)(D3D5F1_CORRECTABLE_ERR_STA) << 32), 0xFFFFFFFF);
*/
	AsiaPcieWrite32(NbCfg->PcieBar, CHX002_PEG|((UINT64)(D3D5F1_CORRECTABLE_ERR_STA) << 32), 0xFFFFFFFF);
	AsiaPcieWrite32(NbCfg->PcieBar, CHX002_PE2|((UINT64)(D3D5F1_CORRECTABLE_ERR_STA) << 32), 0xFFFFFFFF);

	//corrrectable errors Rx1CC
	AsiaPcieWrite8(NbCfg->PcieBar, CHX002_PEG|((UINT64)(D3D5F1_SYS_DEBUG_REG_D4F0_D2F0) << 32), 0xFF);
	AsiaPcieWrite8(NbCfg->PcieBar, CHX002_PE2|((UINT64)(D3D5F1_SYS_DEBUG_REG_D4F0_D2F0) << 32), 0xFF);
}
#endif

/**
  Function description.
  
  @param  PeiServices	EFI_PEI_SERVICES pointer.
  @param NbCfg Point to ASIA_NB_CONFIGURATION struct.

  @return EFI_STATUS.

**/

EFI_STATUS ProgramMaxPayloadSize(
    ASIA_NB_CONFIGURATION *NbCfg,
    UINT8	RpBusNum,
    UINT8	RpDeviceNum,
    UINT8	RpFuncNum,
    PCIE_RESOURCE	*NodePtr
)
{

    UINT8	BnIdx, DevNum, FuncNum, PcieCapability;
    UINTN	PcieNodeTblIndex;
    UINT8	D8 = 0;
    UINT8   SupportFeature;

    if (NodePtr != NULL)
    {
        if (NodePtr->PcieNodeNum != 0)
        {
            for (PcieNodeTblIndex = 0; PcieNodeTblIndex < NodePtr->PcieNodeNum; PcieNodeTblIndex++)
            {
                BnIdx = NodePtr->PcieNodeTbl[PcieNodeTblIndex].BusNum;
                DevNum = NodePtr->PcieNodeTbl[PcieNodeTblIndex].DevNum;
                FuncNum = NodePtr->PcieNodeTbl[PcieNodeTblIndex].FuncNum;
                PcieCapability = NodePtr->PcieNodeTbl[PcieNodeTblIndex].PcieCapOff;
                SupportFeature = NodePtr->MinMpsSupport;

				if(PcieCapability == 0xFF)
					continue;				
	
                if (NbCfg->MaxPayloadSize == MAX_PAYLOAD_SIZE_256B)
                {
                    if (SupportFeature >= 0x01)
                    {
                        D8 = 1;
                    }
                    else
                    {
                        D8 = 0;
                    }
                }
                else
                    D8 = 0;

                AsiaPciModifySave8(AsiaPciAddress(BnIdx, DevNum, FuncNum, PcieCapability + 8), 0xE0, D8 << 5);
                AsiaPciModifySave8(AsiaPciAddress(CHX002_HB_BUS, CHX002_HB_DEV, CHX002_APIC_FUN, D0F5_PMU_CTL), D0F5_RPEROWEN, D0F5_RPEROWEN);   // open back door
				AsiaPciModifySave8(AsiaPciAddress(BnIdx, DevNum, FuncNum, PcieCapability + 4), 0x07, D8);     //JNY-2018 add capability control for maxpay load
                AsiaPciModifySave8(AsiaPciAddress(CHX002_HB_BUS, CHX002_HB_DEV, CHX002_APIC_FUN, D0F5_PMU_CTL), D0F5_RPEROWEN, 0);   // close back door
            }
        }
    }
    return EFI_SUCCESS;
}

/**
  Function description.
  
  @param  PeiServices	EFI_PEI_SERVICES pointer.
  @param NbCfg Point to ASIA_NB_CONFIGURATION struct.

  @return EFI_STATUS.

**/

EFI_STATUS ProgramRelaxedOrder(
    ASIA_NB_CONFIGURATION *NbCfg,
    UINT8    RpBusNum,
    UINT8    RpDeviceNum,
    UINT8    RpFuncNum,
    PCIE_RESOURCE	*NodePtr
)
{
    UINT8	BnIdx, DevNum, FuncNum, PcieCapability;
    UINTN	PcieNodeTblIndex;

    if (NodePtr != NULL)
    {
        if (NodePtr->PcieNodeNum != 0)
        {
            for (PcieNodeTblIndex = 0; PcieNodeTblIndex < NodePtr->PcieNodeNum; PcieNodeTblIndex++)
            {
                BnIdx = NodePtr->PcieNodeTbl[PcieNodeTblIndex].BusNum;
                DevNum = NodePtr->PcieNodeTbl[PcieNodeTblIndex].DevNum;
                FuncNum = NodePtr->PcieNodeTbl[PcieNodeTblIndex].FuncNum;
                PcieCapability = NodePtr->PcieNodeTbl[PcieNodeTblIndex].PcieCapOff;
				if(PcieCapability == 0xFF)
					continue;

                if(NbCfg->RelaxedOrder)
                    AsiaPciModifySave8(AsiaPciAddress(BnIdx, DevNum, FuncNum, PcieCapability + 0x08), 0x10, 0x10);
                else
                    AsiaPciModifySave8(AsiaPciAddress(BnIdx, DevNum, FuncNum, PcieCapability + 0x08), 0x10, 0x00);
            }
        }
    }
    return EFI_SUCCESS;
}

/**
  Function description.
  
  @param  PeiServices	EFI_PEI_SERVICES pointer.
  @param NbCfg Point to ASIA_NB_CONFIGURATION struct.

  @return EFI_STATUS.

**/

EFI_STATUS ProgramExtTag(
    ASIA_NB_CONFIGURATION *NbCfg,
    UINT8    RpBusNum,
    UINT8    RpDeviceNum,
    UINT8    RpFuncNum,
    PCIE_RESOURCE	*NodePtr
)
{
    UINT8	BnIdx, DevNum, FuncNum, PcieCapability;
    UINTN	PcieNodeTblIndex;

    if (NodePtr != NULL)
    {
        if (NodePtr->PcieNodeNum != 0)
        {
            for (PcieNodeTblIndex = 0; PcieNodeTblIndex < NodePtr->PcieNodeNum; PcieNodeTblIndex++)
            {
                BnIdx = NodePtr->PcieNodeTbl[PcieNodeTblIndex].BusNum;
                DevNum = NodePtr->PcieNodeTbl[PcieNodeTblIndex].DevNum;
                FuncNum = NodePtr->PcieNodeTbl[PcieNodeTblIndex].FuncNum;
                PcieCapability = NodePtr->PcieNodeTbl[PcieNodeTblIndex].PcieCapOff;
				if(PcieCapability == 0xFF) continue;	//LNA-2016122702

				if(PcieCapability == 0xFF)
					continue;

                AsiaPciModifySave8(CHX002_APIC|D0F5_PMU_CTL, D0F5_RPEROWEN, 1);
#ifdef ZX_DUALSOCKET	
//#ifdef DUAL_SOCKET_CODE
				if(NbCfg->ZxeDualSocket == 1){
					AsiaPciModifySave8(CHX002_APIC_SLAVE|D0F5_PMU_CTL, D0F5_RPEROWEN, 1);
				}
#endif
                if(NbCfg->ExtTag == EXT_TAG_DISABLED)
                {
                    AsiaPciModifySave8(AsiaPciAddress(BnIdx, DevNum, FuncNum, PcieCapability + 0x04), 0x20, 0x00);   
                }
                else if(NbCfg->ExtTag == EXT_TAG_ENABLED)
                {
                    AsiaPciModifySave8(AsiaPciAddress(BnIdx, DevNum, FuncNum, PcieCapability + 0x04), 0x20, 0x20);  
                    AsiaPciModifySave16(AsiaPciAddress(BnIdx, DevNum, FuncNum, PcieCapability + 0x08), 0x100, 0x100); 
                }

                AsiaPciModifySave8(CHX002_APIC|D0F5_PMU_CTL, D0F5_RPEROWEN, 0);
#ifdef ZX_DUALSOCKET	
//#ifdef DUAL_SOCKET_CODE
				if(NbCfg->ZxeDualSocket == 1){
					AsiaPciModifySave8(CHX002_APIC_SLAVE|D0F5_PMU_CTL, D0F5_RPEROWEN, 0);
				}
#endif
            }
        }
    }

    return EFI_SUCCESS;

}

/*  
EFI_STATUS ProgramNoSnoop(
	ASIA_NB_CONFIGURATION *NbCfg,
    UINT8    RpBusNum,
    UINT8    RpDeviceNum,
    UINT8    RpFuncNum,
    PCIE_RESOURCE	*NodePtr

)
{
	UINT8	BnIdx, DevNum, FuncNum, PcieCapability;
	UINTN	PcieNodeTblIndex;

	if (NodePtr != NULL)
	{
		if (NodePtr->PcieNodeNum != 0)
		{
			for (PcieNodeTblIndex = 0; PcieNodeTblIndex < NodePtr->PcieNodeNum; PcieNodeTblIndex++)
			{
		        BnIdx = NodePtr->PcieNodeTbl[PcieNodeTblIndex].BusNum;
		        DevNum = NodePtr->PcieNodeTbl[PcieNodeTblIndex].DevNum;
		        FuncNum = NodePtr->PcieNodeTbl[PcieNodeTblIndex].FuncNum;
		        PcieCapability = NodePtr->PcieNodeTbl[PcieNodeTblIndex].PcieCapOff;

				if(NbCfg->NoSnoop)
					AsiaPciModifySave16(AsiaPciAddress(BnIdx, DevNum, FuncNum, PcieCapability + 0x08), 0x800, 0x800);
				else
					AsiaPciModifySave16(AsiaPciAddress(BnIdx, DevNum, FuncNum, PcieCapability + 0x08), 0x800, 0x000);
			}
		}
	}

    return EFI_SUCCESS;

}
*/  

/**
  Function description.
  
  @param  PeiServices	EFI_PEI_SERVICES pointer.
  @param NbCfg Point to ASIA_NB_CONFIGURATION struct.

  @return EFI_STATUS.

**/

EFI_STATUS ProgramExtSync(
    ASIA_NB_CONFIGURATION *NbCfg,
    UINT8    RpBusNum,
    UINT8    RpDeviceNum,
    UINT8    RpFuncNum,
    PCIE_RESOURCE	*NodePtr
)
{
    UINT8	BnIdx, DevNum, FuncNum, PcieCapability;
    UINTN	PcieNodeTblIndex;

    if (NodePtr != NULL)
    {
        if (NodePtr->PcieNodeNum != 0)
        {
            for (PcieNodeTblIndex = 0; PcieNodeTblIndex < NodePtr->PcieNodeNum; PcieNodeTblIndex++)
            {
                BnIdx = NodePtr->PcieNodeTbl[PcieNodeTblIndex].BusNum;
                DevNum = NodePtr->PcieNodeTbl[PcieNodeTblIndex].DevNum;
                FuncNum = NodePtr->PcieNodeTbl[PcieNodeTblIndex].FuncNum;
                PcieCapability = NodePtr->PcieNodeTbl[PcieNodeTblIndex].PcieCapOff;
				if(PcieCapability == 0xFF) continue;	//LNA-2016122702
				if(PcieCapability == 0xFF)
					continue;

                if(NbCfg->ExtSync)
                    AsiaPciModifySave16(AsiaPciAddress(BnIdx, DevNum, FuncNum, PcieCapability + 0x10), 0x80, 0x80);
                else
                    AsiaPciModifySave16(AsiaPciAddress(BnIdx, DevNum, FuncNum, PcieCapability + 0x10), 0x80, 0x00);
            }
        }
    }
    return EFI_SUCCESS;
}

UINT8 L1ExitLatencyRangeLevel =  0x08;

UINT8 L1ExitLatencyTbl[] = {
    0x00, 0x01,
    0x01, 0x02,
    0x02, 0x04,
    0x04, 0x08,
    0x08, 0x10,
    0x10, 0x20,
    0x20, 0x40,
    0x40, 0xFF
};

/*
	NewL1MergeAddLatency()

	1)transfer L1 exit latency range level to delay us according to the table.
	2)add switch additional L1 latency.
	3)find the new L1 range level in the table again.
*/

/**
  Function description.
  
  @param  PeiServices	EFI_PEI_SERVICES pointer.
  @param NbCfg Point to ASIA_NB_CONFIGURATION struct.

  @return EFI_STATUS.

**/

UINT8 NewL1MergeAddLatency(
    UINT8	L1ExitLatency,
    UINT8	AddL1Latency
)
{
    UINT8	Index;
    UINT8	D8;

    if (AddL1Latency == 0)
    {
        return L1ExitLatency;
    }

    Index = L1ExitLatency << 1; //for each range in table has 2 subitems;
    D8 = L1ExitLatencyTbl[Index + 1];
    D8 += AddL1Latency;

    for (Index = 0; Index < L1ExitLatencyRangeLevel; Index++)
    {
        if (D8 < L1ExitLatencyTbl[(Index << 1)+ 1])
            return Index;
    }
    return 0xFF;
}

#define LEGACY_PCI_EXP_ENDPOINT_DEVICE 0x01
#define PCI_EXP_ROOT_PORT 0x04
#define PCI_EXP_UPSTREAM_PORT 0x05
#define PCI_EXP_DOWNSTREAM_PORT 0x06
#define PCIE_P2P_BRIDGE 0x07

// algorithm for ASPM
/*
case1: downstream component issue exit L1

type1:    Endpoint->downstream1  max{endpoint, downstream1}
type2:    downstrean1/2->upstream1/2  1
type3:    upstream1->downstream2  1 * n(us) + max{upstream1, downstream2}
type4:    upstream2->rootport    1 * n(us) + max{upstream2, rootport}
type5:    endpoint->rootport    max{endpoint, rootport}

case2: upsteam component issue exit L1

type1:    downstream1-> Endpoint 1 * n(us) + max{endpoint, downstream1}
type2:    upstream1/2-> downstream1/2 1
type3:    downstream2-> upstream1 1 * n(us) + max{upstream1, downstream2}
type4:    rootport-> upstream2   max{upstream2, rootport}
type5:    rootport-> endpoint   max{endpoint, rootport}

if parent and child relationship is type1 or type5
    max(parent, child)
else if parent and child relationship is type2
    inc switch delay number
else
    max(parent, child) + this level switch delay number

for case1:
from type1 to type5, ASPM maxium exit latency is:

1 * n + max{upstream1, downstream2, upstream2, rootport}

for case2:
from type1 to type5, ASPM maxium exit latency is:

1 * n + max{endpoint, downstream1, upstream1, downstream2}

Merge two cases:

1) each path max latency = 1 * n + max{endpoint, downstream1, upstream1, downstream2, upstream2, rootport}

2) if different PCIE pathes have common nodes, these common nodes adapt the min ASPM feature of these different pathes.
*/
//Output: New L1 Exit Latency range after merge switch additional latency

/**
  Function description.
  
  @param  PeiServices	EFI_PEI_SERVICES pointer.
  @param NbCfg Point to ASIA_NB_CONFIGURATION struct.

  @return EFI_STATUS.

**/

UINT32 ScanPciePathExitLatency(
    ASIA_NB_CONFIGURATION *NbCfg,
    PCIE_RESOURCE	*NodePtr,
    UINTN	DevPos,
    UINT16 	PortType,			//parent's porttype
    UINT8	AspmSupported		//Func 0: scan exit latency; Func 1: 1/3 enable ASPM
)
{
    UINT8	BusNo, DevNo, FuncNo, PcieCap;
    UINTN	TblIndex;
    UINTN	ChildIndex;
    UINT8	ParentPortType;
    UINT8	ParenL0sLatency, ParentL1Latency;
    UINT8	ChildL0s, ChildL1;
    UINT32	D32;
    UINT8	SwitchLatency;
    UINT8	MaxL1AspmLatency;

    ChildIndex = DevPos;
    BusNo = NodePtr->PcieNodeTbl[ChildIndex].BusNum;
    DevNo = NodePtr->PcieNodeTbl[ChildIndex].DevNum;
    FuncNo = NodePtr->PcieNodeTbl[ChildIndex].FuncNum;
    PcieCap = NodePtr->PcieNodeTbl[ChildIndex].PcieCapOff;

    DEBUG((EFI_D_ERROR, "Child BusNum = %x, DevNum = %x, FunNum = %x\n", BusNo, DevNo, FuncNo));

    //Get Child L0s exit latency
    D32 = AsiaPciRead32(AsiaPciAddress(BusNo, DevNo, FuncNo, PcieCap + 0x0C));
    //DEBUG((EFI_D_ERROR, "Child L0s/L1 exit latency = %x\n", D32));
    ChildL0s = (UINT8)(AsiaPciRead32(AsiaPciAddress(BusNo, DevNo, FuncNo, PcieCap + 0x0C)) >> 12);
    ChildL0s &= 0x07;
    DEBUG((EFI_D_ERROR, "ChildL0s = %x\n", ChildL0s));

    //Get Child L1 exit latency
    ChildL1 = (UINT8)(AsiaPciRead32(AsiaPciAddress(BusNo, DevNo, FuncNo, PcieCap + 0x0C)) >> 15);
    ChildL1 &= 0x07;
    DEBUG((EFI_D_ERROR, "ChildL1 = %x\n", ChildL1));
    MaxL1AspmLatency = ChildL1;

    SwitchLatency = 0;	//special for switch, one switch add 1us delay

    //search matched parent nodes
    for (TblIndex = NodePtr->PcieNodeNum - 1; ((TblIndex >= 0) && (TblIndex < NodePtr->PcieNodeNum)); TblIndex--)	//TblIndex = 0 is root port, doesn't deal with in this routine
    {
        if (NodePtr->PcieNodeTbl[TblIndex].SecBusNum == 0xFF)	//skip endpoint device
            continue;

        BusNo = NodePtr->PcieNodeTbl[ChildIndex].BusNum;

        if (BusNo == NodePtr->PcieNodeTbl[TblIndex].SecBusNum)
        {
            BusNo = NodePtr->PcieNodeTbl[TblIndex].BusNum;
            DevNo = NodePtr->PcieNodeTbl[TblIndex].DevNum;
            FuncNo = NodePtr->PcieNodeTbl[TblIndex].FuncNum;
            PcieCap = NodePtr->PcieNodeTbl[TblIndex].PcieCapOff;

            DEBUG((EFI_D_ERROR, "BusNo = %x, DevNo = %x, FuncNo = %x\n", BusNo, DevNo, FuncNo));

            ParentPortType = (UINT8)(AsiaPciRead32(AsiaPciAddress(BusNo, DevNo, FuncNo, PcieCap + 0x00)) >> 20); 	//get parent node port type
            ParentPortType &= 0x0F;

            //DEBUG((EFI_D_ERROR, "ParentPortType = %x\n", ParentPortType));

            if ((ParentPortType == (UINT8)PortType)||(ParentPortType == (UINT8)(PortType >> 8)))
            {
                D32 = AsiaPciRead32(AsiaPciAddress(BusNo, DevNo, FuncNo, PcieCap + 0x0C));
                DEBUG((EFI_D_ERROR, "D32 = %x\n", D32));
                D32 >>= 10;

                //Get L0s exit Latency
                if (ChildL0s != 0xFF)
                {
                    if ((D32 & 0x01) == 0x01)
                    {
                        ParenL0sLatency = (UINT8)((D32 >> 2) & 0x07);
                        DEBUG((EFI_D_ERROR, "ParenL0sLatency = %x\n", ParenL0sLatency));
                        ChildL0s = (ParenL0sLatency > ChildL0s) ? ParenL0sLatency : ChildL0s;
                        //DEBUG((EFI_D_ERROR, "Get Aspm L0s!\n"));
                    }
                    else
                    {
                        ChildL0s = 0xFF;
                        DEBUG((EFI_D_ERROR, "Aspm L0s not supported!\n"));
                    }
                }
                //Get L1 exit Latency
                if (ParentPortType == PCI_EXP_ROOT_PORT)
                {
                    if (ChildL1 != 0xFF)
                    {
                        if ((D32 & 0x03) == 0x03)
                        {
                            ParentL1Latency = (UINT8)((D32 >> 5) & 0x07);
                            DEBUG((EFI_D_ERROR, "Root Port ParentL1Latency = %x\n", ParentL1Latency));
                            MaxL1AspmLatency =(MaxL1AspmLatency > ParentL1Latency)? MaxL1AspmLatency: ParentL1Latency;
                        }
                        else
                        {
                            ChildL1 = 0xFF;	//disable ASPM L1
                            MaxL1AspmLatency = 0xFF;
                            DEBUG((EFI_D_ERROR, "Root Port Aspm L1 not supported!\n"));
                        }
                    }

                }
                else if (ParentPortType == PCI_EXP_UPSTREAM_PORT)
                {
                    //Get L1 exit Latency
                    if (ChildL1 != 0xFF)
                    {
                        if ((D32 & 0x03) == 0x03)
                        {
                            //In this case, switch intel L1 latency is 1 micro second
                            ParentL1Latency = (UINT8)((D32 >> 5) & 0x07);
                            MaxL1AspmLatency =(MaxL1AspmLatency > ParentL1Latency)? MaxL1AspmLatency: ParentL1Latency;
                            DEBUG((EFI_D_ERROR, "Switch Upstream Port ParentL1Latency = %x!\n", ParentL1Latency));

                            SwitchLatency++;
                        }
                        else
                        {
                            ChildL1 = 0xFF;	//disable ASPM L1
                            MaxL1AspmLatency = 0xFF;
                            DEBUG((EFI_D_ERROR, "Switch Upstream Port Aspm L1 not supported!\n"));
                        }
                    }
                    PortType = (PCI_EXP_DOWNSTREAM_PORT << 8)|(PCI_EXP_ROOT_PORT);
                }
                else if (ParentPortType == PCI_EXP_DOWNSTREAM_PORT)
                {
                    //Get L1 exit Latency
                    if (ChildL1 != 0xFF)
                    {
                        if ((D32 & 0x03) == 0x03)    
                        {
                            ParentL1Latency = (UINT8)((D32 >> 5) & 0x07);
                            DEBUG((EFI_D_ERROR, "Switch Downstream Port ParentL1Latency = %x!\n", ParentL1Latency));
                            MaxL1AspmLatency = (MaxL1AspmLatency > ParentL1Latency)? MaxL1AspmLatency: ParentL1Latency;
                        }
                        else
                        {
                            ChildL1 = 0xFF;	//disable ASPM L1
                            MaxL1AspmLatency = 0xFF;
                            DEBUG((EFI_D_ERROR, "Switch Downstream Port Aspm L1 not supported!\n"));
                        }

                        PortType = (0xFF << 8) | PCI_EXP_UPSTREAM_PORT;
                    }
                }
                if(AspmSupported)
                {
                    //Enable ASPM of the parent node
                    DEBUG((EFI_D_ERROR, "Enable ASPM of the parent node BusNo = %x, DevNo = %x, FuncNo = %x, Aspm = %x\n", BusNo, DevNo, FuncNo, AspmSupported));
                    if (AspmSupported < NodePtr->PcieNodeTbl[TblIndex].AspmSupported)
                    {
                        AsiaPciModifySave32(AsiaPciAddress(BusNo, DevNo, FuncNo, PcieCap + 0x10), 0x03, AspmSupported);
                        NodePtr->PcieNodeTbl[TblIndex].AspmSupported = AspmSupported;   //3
                    }

                    if (ParentPortType == PCI_EXP_ROOT_PORT)
                        break;
                }
                ChildIndex = TblIndex;	//this parent node change to device node to search it's parent node again
            }
        }
    }
    return ((SwitchLatency << 16)|(MaxL1AspmLatency << 8) | ChildL0s);
}

BAD_PCIE_ASPM_TBL BadPcieAspmL0sTbl[]= {
    0xFFFF, 0xFFFF, 0xFFFF
};

/**
  Function description.
  
  @param  PeiServices	EFI_PEI_SERVICES pointer.
  @param NbCfg Point to ASIA_NB_CONFIGURATION struct.

  @return EFI_STATUS.

**/

BOOLEAN Check_L1_Acceptable(
    UINT8   AcceptableExitL1,
    UINT8   ExitL1Latency,
    UINT8   SwtichDelay

)
{
    UINT8 Data8;
    Data8 = NewL1MergeAddLatency(ExitL1Latency, SwtichDelay);
    if(AcceptableExitL1 >= Data8)
        return TRUE;
    else
        return FALSE;
}


/*+ DSZ_Porting -- (YSW-20170303) Update PCIE Module Code for the programming of Common Clock Configuration*/


//;Using IO-Cycle Delay Counting for BYO BIOS temporarily
/**
  Function description.
  
  @param  PeiServices	EFI_PEI_SERVICES pointer.
  @param NbCfg Point to ASIA_NB_CONFIGURATION struct.

  @return EFI_STATUS.

**/

VOID 
FixedDelayMicroSecond (
    UINTN           Usec                           
 )
{
    UINTN   Counter = 0;

	while(Counter != Usec){
		AsiaIoRead8(0x88);
		Counter++;
	}    
} 

/**
  Function description.
  
  @param  PeiServices	EFI_PEI_SERVICES pointer.
  @param NbCfg Point to ASIA_NB_CONFIGURATION struct.

  @return EFI_STATUS.

**/

VOID ScanParantSlotClock(
    ASIA_NB_CONFIGURATION *NbCfg,
    PCIE_RESOURCE	*NodePtr,
    UINTN	DevPos
)
{

    UINT8	ChildBusNo, ChildDevNo, ChildFuncNo, ChildPcieCap;
	UINT8	BusNo, DevNo, FuncNo, PcieCap;
    UINTN	TblIndex;
    UINTN	ChildIndex;
    UINT8	ParentPortType;        

    ChildIndex = DevPos;
    ChildBusNo = NodePtr->PcieNodeTbl[ChildIndex].BusNum;
    ChildDevNo = NodePtr->PcieNodeTbl[ChildIndex].DevNum;
    ChildFuncNo = NodePtr->PcieNodeTbl[ChildIndex].FuncNum;
    ChildPcieCap = NodePtr->PcieNodeTbl[ChildIndex].PcieCapOff;

    DEBUG((EFI_D_ERROR, "       Child BusNum = %x, DevNum = %x, FunNum = %x\n", ChildBusNo, ChildDevNo, ChildFuncNo));

    //search matched parent nodes
    for (TblIndex = NodePtr->PcieNodeNum - 1; ((TblIndex >= 0) && (TblIndex < NodePtr->PcieNodeNum)); TblIndex--)
    {
        if (NodePtr->PcieNodeTbl[TblIndex].SecBusNum == 0xFF)	//skip endpoint device
            continue;

        ChildBusNo = NodePtr->PcieNodeTbl[ChildIndex].BusNum;

        if (ChildBusNo == NodePtr->PcieNodeTbl[TblIndex].SecBusNum)
        {
            BusNo = NodePtr->PcieNodeTbl[TblIndex].BusNum;
            DevNo = NodePtr->PcieNodeTbl[TblIndex].DevNum;
            FuncNo = NodePtr->PcieNodeTbl[TblIndex].FuncNum;
            PcieCap = NodePtr->PcieNodeTbl[TblIndex].PcieCapOff;

            DEBUG((EFI_D_ERROR, "       BusNo = %x, DevNo = %x, FuncNo = %x\n", BusNo, DevNo, FuncNo));

            ParentPortType = (UINT8)(AsiaPciRead32(AsiaPciAddress(BusNo, DevNo, FuncNo, PcieCap + 0x00)) >> 20); 	//get parent node port type
            ParentPortType &= 0x0F;

            //DEBUG((EFI_D_ERROR, "ParentPortType = %x\n", ParentPortType));

            if ((ParentPortType == PCI_EXP_ROOT_PORT) || (ParentPortType == PCI_EXP_DOWNSTREAM_PORT))
            {
                //Check the Slot Clock Configuration between the Target Component and its parant Component for setting the Common Clock Configuration Register
                if((NodePtr->PcieNodeTbl[ChildIndex].SlotClkCfg == 0x01) && (NodePtr->PcieNodeTbl[TblIndex].SlotClkCfg == 0x01)){
					AsiaPciModifySave8(AsiaPciAddress(ChildBusNo, ChildDevNo, ChildFuncNo, ChildPcieCap + 0x10), 0x40, 0x40);
					AsiaPciModifySave8(AsiaPciAddress(BusNo, DevNo, FuncNo, PcieCap + 0x10), 0x40, 0x40);
                }else{
					AsiaPciModifySave8(AsiaPciAddress(ChildBusNo, ChildDevNo, ChildFuncNo, ChildPcieCap + 0x10), 0x40, 0x00);
					AsiaPciModifySave8(AsiaPciAddress(BusNo, DevNo, FuncNo, PcieCap + 0x10), 0x40, 0x00);               
                }
				
				//retrain PCIE Link through parant Component
				AsiaPciModifySave8(AsiaPciAddress(BusNo, DevNo, FuncNo, PcieCap + 0x10), 0x20, 0);
            }
        }
    }
}

/**
  Function description.
  
  @param  PeiServices	EFI_PEI_SERVICES pointer.
  @param NbCfg Point to ASIA_NB_CONFIGURATION struct.

  @return EFI_STATUS.

**/

BOOLEAN ProgramCommonClockConfiguration(
    ASIA_NB_CONFIGURATION *NbCfg,
    PCIE_RESOURCE	*NodePtr
)
{
    UINTN	DevPos;
    UINT8	PortType;    
    UINT8	BusNo,DevNo,FuncNo;
    UINT8 	PcieCap;       

    if (NodePtr->PcieNodeNum == 0)
    {
        return EFI_SUCCESS;
    }

	DEBUG((EFI_D_ERROR, "[PCIE-POST-PCI] Start Setting PCIE Common Clock Configuration Register\n"));

    //Find PCIE device in PCIE node tree to program Common Clock Configuration Register
    for (DevPos = NodePtr->PcieNodeNum - 1; ((DevPos >= 0) && (DevPos < NodePtr->PcieNodeNum)); DevPos--)
    {
        BusNo = NodePtr->PcieNodeTbl[DevPos].BusNum;
        DevNo = NodePtr->PcieNodeTbl[DevPos].DevNum;
        FuncNo = NodePtr->PcieNodeTbl[DevPos].FuncNum;
        PcieCap = NodePtr->PcieNodeTbl[DevPos].PcieCapOff;

		if(PcieCap == 0xFF)
			continue;

        PortType = (UINT8)(AsiaPciRead32(AsiaPciAddress(BusNo, DevNo, FuncNo, PcieCap + 0x00)) >> 20);
        PortType &= 0x0F;
        
        DEBUG((EFI_D_ERROR, "DevPos = %x\n", DevPos));
		DEBUG((EFI_D_ERROR, "       Port Type = %x!\n", PortType));
        DEBUG((EFI_D_ERROR, "       BusNum = %x\n", BusNo));
        DEBUG((EFI_D_ERROR, "       DevNum = %x\n", DevNo));
        DEBUG((EFI_D_ERROR, "       FunNum = %x\n", FuncNo));
        DEBUG((EFI_D_ERROR, "       PcieCapOff = %x\n", PcieCap));
        DEBUG((EFI_D_ERROR, "       SecBusNum = %x\n", NodePtr->PcieNodeTbl[DevPos].SecBusNum));

 
        //Proceed for ASPM only if PCIe device is a endpoint device, PCIE-PCI brdige, or a Switch Upstream-Port
        if ((PortType <= LEGACY_PCI_EXP_ENDPOINT_DEVICE)||(PortType == PCIE_P2P_BRIDGE)||(PortType == PCI_EXP_UPSTREAM_PORT))
        {
            //Scan Pcie path to get Slot Clock Configuration of parent Component and set the Common Clock Configuration accordingly
            ScanParantSlotClock(NbCfg, NodePtr, DevPos);
        } 
    }

   //;wait 100ms for retrain
   FixedDelayMicroSecond(100000);

    return EFI_SUCCESS;

}
/*- DSZ_Porting -- (YSW-20170303) Update PCIE Module Code for the programming of Common Clock Configuration*/

/**
  Function description.
  
  @param  PeiServices	EFI_PEI_SERVICES pointer.
  @param NbCfg Point to ASIA_NB_CONFIGURATION struct.

  @return EFI_STATUS.

**/

BOOLEAN CheckBadPcieAspmL0sDevice(
    PCIE_RESOURCE	*NodePtr,
    UINTN DevPos
)
{
    UINT8	BusNo,DevNo,FuncNo;
    UINT16 	VendorId, DeviceId;
    UINT8   i;

    BusNo = NodePtr->PcieNodeTbl[DevPos].BusNum;
    DevNo = NodePtr->PcieNodeTbl[DevPos].DevNum;
    FuncNo = NodePtr->PcieNodeTbl[DevPos].FuncNum;

    VendorId = AsiaPciRead16(AsiaPciAddress(BusNo, DevNo, FuncNo, 0));
    DeviceId = AsiaPciRead16(AsiaPciAddress(BusNo, DevNo, FuncNo, 2));

    for(i=0; i<sizeof(BadPcieAspmL0sTbl)/sizeof(BAD_PCIE_ASPM_TBL); i++)
    {
        if((VendorId==BadPcieAspmL0sTbl[i].VendorId)&&(DeviceId==(BadPcieAspmL0sTbl[i].DeviceId & BadPcieAspmL0sTbl[i].DeviceIdMask)))
        {
            return TRUE;
        }
    }

    return FALSE;
}

BAD_PCIE_ASPM_TBL BadPcieAspmL1Tbl[] = {
//	Vendor ID	Device ID	Device ID Mask
    0x1033, 0x0194, 0xFFFF, //for ASUS U3S6
    0xFFFF, 0xFFFF, 0xFFFF
};

/**
  Function description.
  
  @param  PeiServices	EFI_PEI_SERVICES pointer.
  @param NbCfg Point to ASIA_NB_CONFIGURATION struct.

  @return EFI_STATUS.

**/

BOOLEAN CheckBadPcieAspmL1Device(
    PCIE_RESOURCE	*NodePtr,
    UINTN DevPos
)
{
    UINT8	BusNo,DevNo,FuncNo;
    UINT16 	VendorId, DeviceId;
    UINT8   i;


    BusNo = NodePtr->PcieNodeTbl[DevPos].BusNum;
    DevNo = NodePtr->PcieNodeTbl[DevPos].DevNum;
    FuncNo = NodePtr->PcieNodeTbl[DevPos].FuncNum;


    VendorId = AsiaPciRead16(AsiaPciAddress(BusNo, DevNo, FuncNo, 0));
    DeviceId = AsiaPciRead16(AsiaPciAddress(BusNo, DevNo, FuncNo, 2));

    for(i=0; i<sizeof(BadPcieAspmL1Tbl)/sizeof(BAD_PCIE_ASPM_TBL); i++)
    {
        if((VendorId==BadPcieAspmL1Tbl[i].VendorId)&&(DeviceId==(BadPcieAspmL1Tbl[i].DeviceId & BadPcieAspmL1Tbl[i].DeviceIdMask)))
        {
            return TRUE;
        }
    }
    return FALSE;
}

BAD_PCIE_ASPM_TBL BadPcieAspmTbl[] = {
//Vendor ID		Device ID       Device ID Mask
    0x197B, 		0x2360, 		0xFFF0,
    0x197B, 		0x2380, 		0xFFF0,
    0x104C, 		0x8231, 		0xFFFF,
    0x9710, 		0x9835, 		0xFFFF,
    0x11C1, 		0xED00, 		0xFFFF,
    0x14E4, 		0x169D, 		0xFFFF,
    0x1102, 		0x7006, 		0xFFFF,
    0x9005, 		0x0285, 		0xFFFF,
    0x1B21,  		0x0611,  		0xFFFF,	 
    0x1106,		0x3432,		0xFFFF,	 
    0xFFFF
};

/**
  Function description.
  
  @param  PeiServices	EFI_PEI_SERVICES pointer.
  @param NbCfg Point to ASIA_NB_CONFIGURATION struct.

  @return EFI_STATUS.

**/

BOOLEAN CheckBadPcieAspmDevice(
    PCIE_RESOURCE	*NodePtr,
    UINTN DevPos
)
{
    UINT8	BusNo,DevNo,FuncNo;
    UINT16 	VendorId, DeviceId;
    UINT8   i;

    BusNo = NodePtr->PcieNodeTbl[DevPos].BusNum;
    DevNo = NodePtr->PcieNodeTbl[DevPos].DevNum;
    FuncNo = NodePtr->PcieNodeTbl[DevPos].FuncNum;

    VendorId = AsiaPciRead16(AsiaPciAddress(BusNo, DevNo, FuncNo, 0));
    DeviceId = AsiaPciRead16(AsiaPciAddress(BusNo, DevNo, FuncNo, 2));

    for(i=0; i<sizeof(BadPcieAspmTbl)/sizeof(BAD_PCIE_ASPM_TBL); i++)
    {
        if((VendorId==BadPcieAspmTbl[i].VendorId)&&(DeviceId==(BadPcieAspmTbl[i].DeviceId & BadPcieAspmTbl[i].DeviceIdMask)))
        {
            return TRUE;
        }
    }

    return FALSE;

}

PROTECT_ENDP_DEV_TBL ProtectedEndPointDev[] = {
    0x104C, 0x8231,		//; KEC 222NE PCIE COM port (Secondary)
    0x9710, 0x9835,		//; KEC 222NE PCIE COM port (Primary)
    0x11C1, 0xED00,		//; AGERE NIC
    0x14E4, 0x169D,		//; Broadcom 5789
    0x1102, 0x7006,		//; Creative X-Fi Xtreme
    0xFFFF, 0xFFFF
};

/**
  Function description.
  
  @param  PeiServices	EFI_PEI_SERVICES pointer.
  @param NbCfg Point to ASIA_NB_CONFIGURATION struct.

  @return EFI_STATUS.

**/

BOOLEAN CheckProtectedEndPoint(
    PCIE_RESOURCE	*NodePtr,
    UINTN DevPos
)
{
    UINT8	BusNo,DevNo,FuncNo;
    UINT16 	VendorId, DeviceId;
    UINT8   i;

    BusNo = NodePtr->PcieNodeTbl[DevPos].BusNum;
    DevNo = NodePtr->PcieNodeTbl[DevPos].DevNum;
    FuncNo = NodePtr->PcieNodeTbl[DevPos].FuncNum;

    VendorId = AsiaPciRead16(AsiaPciAddress(BusNo, DevNo, FuncNo, 0));
    DeviceId = AsiaPciRead16(AsiaPciAddress(BusNo, DevNo, FuncNo, 2));
    for(i=0; i<sizeof(ProtectedEndPointDev)/sizeof(PROTECT_ENDP_DEV_TBL); i++)
    {
        if((VendorId==ProtectedEndPointDev[i].VendorId)&&(DeviceId==ProtectedEndPointDev[i].DeviceId))
        {
            return TRUE;
        }
    }

    return FALSE;
}


/**
	RpAspmSupportedCfg
	Before enable ASPM(no matter BIOS to set or OSPM to set), we must to 
	ensure the PCIE RP support ASPM,  here is to modify the ASPM Supported Field 
	in PCI Express Capability Device Capability Register
	
	@Param RpBusNum    bus numer of target RP
	@Param RpDeviceNum    device  numer of target RP
	@Param RpFuncNum   function  numer of target RP
**/

/**
  Function description.
  
  @param  PeiServices	EFI_PEI_SERVICES pointer.
  @param NbCfg Point to ASIA_NB_CONFIGURATION struct.

  @return EFI_STATUS.

**/
	/*

EFI_STATUS 
RpAspmSupportedCfg(
	ASIA_NB_CONFIGURATION *NbCfg,
	UINT8	RpBusNum,
    UINT8	RpDeviceNum,
    UINT8	RpFuncNum)
{
	//ASPM supported field default is Disable, need to reprogram the supported filed before enable it
	if((NbCfg->PcieASPM)||(NbCfg->PcieASPMBootArch)){
		AsiaPciModifySave8(AsiaPciAddress(CHX002_HB_BUS,CHX002_HB_DEV,CHX002_APIC_FUN,D0F5_PMU_CTL),D0F5_RPEROWEN,D0F5_RPEROWEN);
		AsiaPciModifySave16(AsiaPciAddress(RpBusNum,RpDeviceNum,RpFuncNum,D3D5F1_LINK_CAPS_1_D4F0),D3D5F1_LKAPMS,D3D5F1_LKAPMS);
		AsiaPciModifySave8(AsiaPciAddress(CHX002_HB_BUS,CHX002_HB_DEV,CHX002_APIC_FUN,D0F5_PMU_CTL),D0F5_RPEROWEN,0);
	}
	return EFI_SUCCESS;
}*/

/**
  Function description.
  
  @param  PeiServices	EFI_PEI_SERVICES pointer.
  @param NbCfg Point to ASIA_NB_CONFIGURATION struct.

  @return EFI_STATUS.

**/

EFI_STATUS ProgramAspmTree(
    ASIA_NB_CONFIGURATION *NbCfg,
    PCIE_RESOURCE	*NodePtr
)
{
    UINTN	DevPos;
    UINT8	PortType;
    UINT8  L0sDevAcceptLatency,L1DevAcceptLatency;
    UINT8  L0sLinkExitLatency, L1LinkExitLatency;
    UINT8	AspmSupported;
    UINT8	BusNo,DevNo,FuncNo;
    UINT8 	PcieCap;
    UINT32  D32;
    UINT16	D16;
    UINT8   SwtichDelay;     



#if 0	//CJW_20170510  removed --- those code is for VLI ASPM abnormal issue,  new EVB(CHX002) would not have this chip behind this port
//LNA-2016110802 - S	
#ifdef HX002EA0_10
//Disable ASPM Capability in both the root port and VLI xHCI Host(hard code it)
		AsiaPciModify8(AsiaPciAddress(0, 0, 5, D0F5_PMU_CTL), 0x01, 1);
		AsiaPciModify16(AsiaPciAddress(0, 3, 2, D3D5F1_LINK_CAPS_1_D4F0), 0x0C00, 0);
		AsiaPciModify8(AsiaPciAddress(0, 0, 5, D0F5_PMU_CTL), 0x01, 0);
#endif
//LNA-2016110802 - E
#endif
	DEBUG((EFI_D_ERROR, "[PCIE-POST-PCI] ProgramAspmTree()\n"));
    if (!NbCfg->PcieASPM)
    { 
        for (DevPos = NodePtr->PcieNodeNum - 1; ((DevPos >= 0) && (DevPos < NodePtr->PcieNodeNum)); DevPos--)
        {
            BusNo = NodePtr->PcieNodeTbl[DevPos].BusNum;
            DevNo = NodePtr->PcieNodeTbl[DevPos].DevNum;
            FuncNo = NodePtr->PcieNodeTbl[DevPos].FuncNum;
            PcieCap = NodePtr->PcieNodeTbl[DevPos].PcieCapOff;
            if(PcieCap!= 0xFF)
            {
            	DEBUG((EFI_D_ERROR, "       Disable ASPM on this RP - Pls change it through SETUP UI\n"));
                AsiaPciModifySave32(AsiaPciAddress(BusNo, DevNo, FuncNo, PcieCap + 0x10), 0x03, 0);
            }
        } 
        return EFI_SUCCESS;
    }

    if (NodePtr->PcieNodeNum == 0)
    {
        return EFI_SUCCESS;
    }

    //Find PCIE device in PCIE node tree to program ASPM
    for (DevPos = NodePtr->PcieNodeNum - 1; ((DevPos >= 0) && (DevPos < NodePtr->PcieNodeNum)); DevPos--)
    {
        BusNo = NodePtr->PcieNodeTbl[DevPos].BusNum;
        DevNo = NodePtr->PcieNodeTbl[DevPos].DevNum;
        FuncNo = NodePtr->PcieNodeTbl[DevPos].FuncNum;
        PcieCap = NodePtr->PcieNodeTbl[DevPos].PcieCapOff;

		if(PcieCap == 0xFF)
			continue;

        PortType = (UINT8)(AsiaPciRead32(AsiaPciAddress(BusNo, DevNo, FuncNo, PcieCap + 0x00)) >> 20);
        PortType &= 0x0F;

        DEBUG((EFI_D_ERROR, "DevPos = %x\n", DevPos));
		DEBUG((EFI_D_ERROR, "       Port Type = %x!\n", PortType));
        DEBUG((EFI_D_ERROR, "       BusNum = %x\n", BusNo));
        DEBUG((EFI_D_ERROR, "       DevNum = %x\n", DevNo));
        DEBUG((EFI_D_ERROR, "       FunNum = %x\n", FuncNo));
        DEBUG((EFI_D_ERROR, "       PcieCapOff = %x\n", PcieCap));
        DEBUG((EFI_D_ERROR, "       SecBusNum = %x\n", NodePtr->PcieNodeTbl[DevPos].SecBusNum));

        //Check bad ASPM pcie device or not
        if (CheckBadPcieAspmDevice(NodePtr, DevPos))
            continue;
 
        //Proceed for ASPM only if PCIe device is a endpoint device or a PCIE-PCI brdige
        if ((PortType <= LEGACY_PCI_EXP_ENDPOINT_DEVICE)||(PortType == PCIE_P2P_BRIDGE))
        {
            //Check whether is protected endpoint device
            if (CheckProtectedEndPoint(NodePtr, DevPos))
                continue;

            //Get device acceptable L0s/L1 exit latency
            D16 = AsiaPciRead16(AsiaPciAddress(BusNo, DevNo, FuncNo, PcieCap + 0x04));
            DEBUG((EFI_D_ERROR, "       Get device acceptable L0s/L1 exit latency, D16 = %x\n", D16));
            L0sDevAcceptLatency = (D16 >> 6) & 0x07;
            L1DevAcceptLatency = (D16 >> 9) & 0x07;
            DEBUG((EFI_D_ERROR, "       L0sDevAcceptLatency = %x\n", L0sDevAcceptLatency));
            DEBUG((EFI_D_ERROR, "       L1DevAcceptLatency = %x\n", L1DevAcceptLatency));

            //Get the level of ASPM supported by this device
            AspmSupported = (UINT8)(AsiaPciRead16(AsiaPciAddress(BusNo, DevNo, FuncNo, PcieCap + 0x0C)) >> 10);
            AspmSupported &= 0x03;

            //Scan Pcie path to get device L0s/L1 exit latency
            D32 = ScanPciePathExitLatency(NbCfg, NodePtr, DevPos, (PCI_EXP_DOWNSTREAM_PORT << 8)|PCI_EXP_ROOT_PORT, 0);
            DEBUG((EFI_D_ERROR, "       After Scan pcie Path Exit Latency, D32 = %x\n", D32));
            if ((UINT16)D32 == 0xFFFF)
                continue;
            L0sLinkExitLatency = (UINT8)D32;
            L1LinkExitLatency = (UINT8)(D32 >> 8);
            SwtichDelay = (UINT8)(D32 >> 16);    
            DEBUG((EFI_D_ERROR, "       L0sLinkExitLatency = %x\n", L0sLinkExitLatency));
            DEBUG((EFI_D_ERROR, "       L1LinkExitLatency = %x\n", L1LinkExitLatency));
            DEBUG((EFI_D_ERROR, "       SwtichDelay = %x\n", SwtichDelay));

            //Get actual L0s/L1 ASPM exit latency for this device
            if (L0sLinkExitLatency > L0sDevAcceptLatency)
                continue;
            else if (CheckBadPcieAspmL0sDevice(NodePtr, DevPos))	//Check bad ASPM L0s device
                AspmSupported &= ~0x01;

          if ((L1LinkExitLatency == 0xFF)||(!Check_L1_Acceptable(L1DevAcceptLatency,L1LinkExitLatency, SwtichDelay)||(CheckBadPcieAspmL1Device(NodePtr, DevPos))))	 
            {
                //Add latency to L1 to check it is acceptable
                AspmSupported &= ~0x02;
            }

            {
                DEBUG((EFI_D_ERROR, "       Busno: %x, Devno: %x, Funcno: %x\n", BusNo, DevNo,FuncNo));
                DEBUG((EFI_D_ERROR, "       Aspm Supported = %x\n", AspmSupported));
            }

            //According to check result determine to disable or enable ASPM
            DEBUG((EFI_D_ERROR, "       Enter ScanPciePathExitLatency Second time!\n"));

            ScanPciePathExitLatency(NbCfg, NodePtr, DevPos, (PCI_EXP_DOWNSTREAM_PORT << 8)|PCI_EXP_ROOT_PORT, AspmSupported);

            //Enable deivce ASPM
            DEBUG((EFI_D_ERROR, "       Enable ASPM of the leaf device node BusNo = %x, DevNo = %x, FuncNo = %x\n", BusNo, DevNo, FuncNo ));
            DEBUG((EFI_D_ERROR, "       ASPM = %x\n", AspmSupported)); 
            AsiaPciModifySave32(AsiaPciAddress(BusNo, DevNo, FuncNo, PcieCap + 0x10), 0x03, AspmSupported); 
            NodePtr->PcieNodeTbl[DevPos].AspmSupported =  AspmSupported;
        } 
    }
    return EFI_SUCCESS;
}

/**
  Function description.
  
  @param  PeiServices	EFI_PEI_SERVICES pointer.
  @param NbCfg Point to ASIA_NB_CONFIGURATION struct.

  @return EFI_STATUS.

**/

EFI_STATUS ProgramPcieTreeFeature(
    ASIA_NB_CONFIGURATION *NbCfg,
    UINT8	RpBusNum,
    UINT8	RpDeviceNum,
    UINT8	RpFuncNum
)
{
    PCIE_RESOURCE *NodePtr;
    EFI_STATUS Status;

    NodePtr = NULL;

    Status = gBS->AllocatePool(
                 EfiBootServicesData,
                 sizeof (PCIE_RESOURCE),
                 &NodePtr
             );
    if (Status != EFI_SUCCESS)
        return Status;

    NodePtr->PcieNodeNum = 0;
    NodePtr->MinMpsSupport = 0xFF; 

    PcieTopo(RpBusNum, RpDeviceNum, RpFuncNum, NodePtr); 
 
    //for debug-start
    {
        UINTN Data;
        UINT16 DeviceId;
        UINT16 VendorId;
        UINT64 Addr;

		DEBUG((EFI_D_ERROR, "[PCIE-POST-PCI] Dump all PCIE nodes(I-DIDVID):\n"));
        for(Data = 0; Data < NodePtr->PcieNodeNum; Data++)
        { 
        	DEBUG((EFI_D_ERROR, "                [%d:%d.%d]", 
								NodePtr->PcieNodeTbl[Data].BusNum,
								NodePtr->PcieNodeTbl[Data].DevNum,
								NodePtr->PcieNodeTbl[Data].FuncNum));
            Addr = AsiaPciAddress(NodePtr->PcieNodeTbl[Data].BusNum,
									NodePtr->PcieNodeTbl[Data].DevNum, 
									NodePtr->PcieNodeTbl[Data].FuncNum, 0x0);
            DeviceId = AsiaPciRead16(Addr);
            VendorId = AsiaPciRead16(Addr + 2);
            DEBUG((EFI_D_ERROR, "-->Device ID = %x, Vendor ID = %x\n",DeviceId, VendorId));
        }
    } 
    //for debug-end

    ProgramMaxPayloadSize(NbCfg, RpBusNum, RpFuncNum, RpFuncNum, NodePtr);

    ProgramRelaxedOrder(NbCfg, RpBusNum, RpFuncNum, RpFuncNum, NodePtr);

    ProgramExtTag(NbCfg, RpBusNum, RpFuncNum, RpFuncNum, NodePtr);

//ProgramNoSnoop(NbCfg, RpBusNum, RpFuncNum, RpFuncNum, NodePtr);

    ProgramExtSync(NbCfg, RpBusNum, RpFuncNum, RpFuncNum, NodePtr);
	/*+ DSZ_Porting -- (YSW-20170303) Update PCIE Module Code for the programming of Common Clock Configuration*/

    ProgramCommonClockConfiguration(NbCfg, NodePtr);
 	/*- DSZ_Porting -- (YSW-20170303) Update PCIE Module Code for the programming of Common Clock Configuration*/

   // RpAspmSupportedCfg(NbCfg, RpBusNum, RpDeviceNum, RpFuncNum); //CJW_20180509 CHX002 new
    ProgramAspmTree(NbCfg, NodePtr);
 
    //for debug-start
    {
        UINTN Data;
		DEBUG((EFI_D_ERROR, "[PCIE-POST-PCI] Dump all PCIE nodes(II-ASPM):\n"));
        for(Data = 0; Data < NodePtr->PcieNodeNum; Data++)
        {
        	DEBUG((EFI_D_ERROR, "                [%d:%d.%d]", 
								NodePtr->PcieNodeTbl[Data].BusNum,
								NodePtr->PcieNodeTbl[Data].DevNum,
								NodePtr->PcieNodeTbl[Data].FuncNum));        
            DEBUG((EFI_D_ERROR, "-->Aspm supported = %x\n", NodePtr->PcieNodeTbl[Data].AspmSupported));
        }
    }
    //for debug-end

    if (NodePtr != NULL)
        gBS->FreePool(NodePtr);

    return EFI_SUCCESS;
}

/**
  Function description.
  
  @param  PeiServices	EFI_PEI_SERVICES pointer.
  @param NbCfg Point to ASIA_NB_CONFIGURATION struct.

  @return EFI_STATUS.

**/

EFI_STATUS ConfigPcieRPDoEq(
    ASIA_NB_CONFIGURATION *NbCfg,
    UINT8	RpBusNum,
    UINT8	RpDeviceNum,
    UINT8	RpFuncNum
)
{

	UINT8 tmp8;
	UINT8 WaitCounter = 200;

	// JNY-DOEQ or SKIPEQ??
	
	// get RP Max Link-Speed
	tmp8 = AsiaPcieRead8(NbCfg->PcieBar, ASIA_PCI_ADDRESS(RpBusNum, RpDeviceNum, RpFuncNum, 0)|((UINT64)(D3D5F1_LINK_CAPS_1_D4F0) << 32)) & (D3D5F1_LKMAXLS_0 + D3D5F1_LKMAXLS_1 + D3D5F1_LKMAXLS_2 + D3D5F1_LKMAXLS_3);

	// Target Link-Speed to GEN3 with Do-EQ mechanism
	if((tmp8 == (D3D5F1_LKMAXLS_0 + D3D5F1_LKMAXLS_1)) && (NbCfg->PcieEQ == DOEQ)){

		//if this port want to do EQ phase2/3
		if(D3D5F1_RWTEXEPH23 & AsiaPcieRead8(NbCfg->PcieBar,ASIA_PCI_ADDRESS(RpBusNum, RpDeviceNum, RpFuncNum, 0)|((UINT64)D3D5F1_MISC_CTL << 32))){
			DEBUG((EFI_D_ERROR, "[PCIE-POST-PCI] Do Eq in PCIe RP Bus = %x, Dev = %x, Fun = %x.\n", RpBusNum, RpDeviceNum, RpFuncNum));
			//AsiaPcieModifySave8(NbCfg->PcieBar, ASIA_PCI_ADDRESS(RpBusNum, RpDeviceNum, RpFuncNum, 0)|((UINT64)D3D5F1_MISC_CTL << 32), D3D5F1_RWTEXEPH23, D3D5F1_RWTEXEPH23);  //Do EQ Phase2 /3 or not ,Rx290[4]
			AsiaPcieModify8(NbCfg->PcieBar, ASIA_PCI_ADDRESS(RpBusNum, RpDeviceNum, RpFuncNum, 0)|((UINT64)D3D5F1_LINK_CTL_2_D4F0 << 32), D3D5F1_LKTGLS_0 + D3D5F1_LKTGLS_1 + D3D5F1_LKTGLS_2 + D3D5F1_LKTGLS_3, D3D5F1_LKTGLS_0 + D3D5F1_LKTGLS_1);
			AsiaPcieModify8(NbCfg->PcieBar, ASIA_PCI_ADDRESS(RpBusNum, RpDeviceNum, RpFuncNum, 0)|((UINT64)D3D5F1_LKTGLS_INTER_AND_NEED_EQTS << 32), D3D5F1_LKTGLS_INTER, D3D5F1_LKTGLS_INTER); 	
			AsiaPcieModify8(NbCfg->PcieBar, ASIA_PCI_ADDRESS(RpBusNum, RpDeviceNum, RpFuncNum, 0)|((UINT64)D3D5F1_LINK_CTL_1 << 32), D3D5F1_LCRL, D3D5F1_LCRL); //Retrain Link	


			while(WaitCounter--){
				if(0x8A == AsiaPcieRead8(NbCfg->PcieBar, ASIA_PCI_ADDRESS(RpBusNum, RpDeviceNum, RpFuncNum, 0)|((UINT64)(D3D5F1_PHYLS_LTSSM_STATE) << 32)) ){
					break;
				}
				gBS->Stall(1000); //wait max to 200ms
			}
		}

	}
	
	// JNY-Force EQTS2 when Redo EQ?
	if(NbCfg->PcieEQTS2){
	// Set this register will force RP to trigger EQTS2 for the re-EQ.
	// Rx1E9[0]
	   AsiaPcieModifySave8(NbCfg->PcieBar, ASIA_PCI_ADDRESS(RpBusNum, RpDeviceNum, RpFuncNum, 0)|((UINT64)D3D5F1_LKTGLS_INTER_AND_NEED_EQTS << 32), D3D5F1_NEED_EQTS, D3D5F1_NEED_EQTS); 	
	}else{
	   AsiaPcieModifySave8(NbCfg->PcieBar, ASIA_PCI_ADDRESS(RpBusNum, RpDeviceNum, RpFuncNum, 0)|((UINT64)D3D5F1_LKTGLS_INTER_AND_NEED_EQTS << 32), D3D5F1_NEED_EQTS, 0);	 
	}

	return EFI_SUCCESS;
}

//Support PCIE MSI Enable capability
/**
  Function description.
  
  @param  PeiServices	EFI_PEI_SERVICES pointer.
  @param NbCfg Point to ASIA_NB_CONFIGURATION struct.

  @return EFI_STATUS.

**/

VOID EnablePcieMsiCap()
{
    //There is a engagement between  and Microsoft, if D0F0Rx08 = 0x80,
    //Can OS support PCIE MSI

    //Set D0F6RxA0~A3, shodow D0F0Rx08
    AsiaPciWrite32(CHX002_SCRCH|D0F6_CTL_REG_FOR_CFG_SHADOW_REGS_0, 0x7E200008);
    //Set D0F6RxC0 to 0x80, to return D0F0Rx08 (Chip Version) = 0x80 to CPU
    AsiaPciWrite8(CHX002_SCRCH|D0F6_CFG_SHADOW_REG_0, 0x80);

    return ;
}

/**
  Function description.
  
  @param  PeiServices	EFI_PEI_SERVICES pointer.
  @param NbCfg Point to ASIA_NB_CONFIGURATION struct.

  @return EFI_STATUS.

**/

BOOLEAN IsPciePresent(UINT64 Address)
{
    UINT8 cardPresent;

    cardPresent = AsiaPciRead8(Address|D3D5F1_SLOT_STA_1);
    cardPresent &= D3D5F1_SPDCST;
    if(cardPresent == D3D5F1_SPDCST)
        return TRUE;
    else
        return FALSE;
}




//
//this function do some Eye monitor debug releate things
//
/**
  Function description.
  
  @param  PeiServices	EFI_PEI_SERVICES pointer.
  @param NbCfg Point to ASIA_NB_CONFIGURATION struct.

  @return EFI_STATUS.

**/

EFI_STATUS
PcieEyeMonitorDbg(ASIA_NB_CONFIGURATION *NbCfg)
{
{
	UINT64 PemcuDSRAMBase;
	UINT16 ix,ErrorCounter = 0;
	UINT16 EmTimeS[8] = {0};
	UINT16 EmTimeE[8] = {0};
	UINT16 PortDetailOffset ;
	UINT8 CursorDetail[8][4]={0};
	UINT16 iy;
		
	if((!NbCfg->PcieEMEQDebug)||(NbCfg->PcieEQ != DOEQ)){
		return EFI_SUCCESS;
	}
	if(NbCfg->PEMCU_LoadFW_WhenBoot != 1){
		return EFI_SUCCESS;
	}

	
	DEBUG((EFI_D_ERROR, "[CJW_PCIE_EYE_DEBUG] START\n"));
	
	PemcuDSRAMBase = AsiaMemoryRead32((NbCfg->PcieEPHYBar)+PCIEPHYCFG_BASE_ADR_OF_PEMCU_FW_FOR_DATA_SPACE);
	PemcuDSRAMBase = PemcuDSRAMBase<<16;
	DumpMemDxe(PemcuDSRAMBase+0x1000,0x100);
	DumpMemDxe(PemcuDSRAMBase+0x1100,0x300);
	DumpMemDxe(PemcuDSRAMBase+0x1400,0x800);

	DumpCfgDxe(0xE0000000,0,3,0,0x80);
	DumpCfgDxe(0xE0000000,0,3,1,0x80);
	DumpCfgDxe(0xE0000000,0,3,2,0x80);
	DumpCfgDxe(0xE0000000,0,3,3,0x80);
	DumpCfgDxe(0xE0000000,0,4,0,0x80);
	DumpCfgDxe(0xE0000000,0,4,1,0x80);
	DumpCfgDxe(0xE0000000,0,5,0,0x80);
	DumpCfgDxe(0xE0000000,0,5,1,0x80);
	
	//DEBUG((EFI_D_ERROR, "[CJW_PCIE_EYE_DEBUG] 1\n"));


	//Error Code check (offset 1200)
	for(ix = 0 ; ix<0x100; ix++){
		if(AsiaMemoryRead8(PemcuDSRAMBase+0x1200+ix)){
			ErrorCounter++;
		}
	}
	//DEBUG((EFI_D_ERROR, "[CJW_PCIE_EYE_DEBUG] 2\n"));

	for(ix= 0; ix<8;ix++){
		EmTimeS[ix] = (AsiaMemoryRead8(PemcuDSRAMBase+0x1300+0x20+ix)<<8)+(AsiaMemoryRead8(PemcuDSRAMBase+0x1300+0x30+ix));
		EmTimeE[ix] = (AsiaMemoryRead8(PemcuDSRAMBase+0x1300+0x40+ix)<<8)+(AsiaMemoryRead8(PemcuDSRAMBase+0x1300+0x50+ix));
	}
	//DEBUG((EFI_D_ERROR, "[CJW_PCIE_EYE_DEBUG] 3\n"));

	for(ix = 0; ix<8; ix++){
		PortDetailOffset = 0x1400+(0x100*ix);
		//DEBUG((EFI_D_ERROR, "[CJW_PCIE_EYE_DEBUG] 3-%x\n",PortDetailOffset));
		for(iy = 0x20; iy<0x100;iy+=0x10){
			//DEBUG((EFI_D_ERROR, "[CJW_PCIE_EYE_DEBUG] 3-%x\n",PemcuDSRAMBase+PortDetailOffset+iy));
			if(0xA5 == AsiaMemoryRead8(PemcuDSRAMBase+PortDetailOffset+iy)){
				CursorDetail[ix][0] = AsiaMemoryRead8(PemcuDSRAMBase+PortDetailOffset+iy+1);
				CursorDetail[ix][1] = AsiaMemoryRead8(PemcuDSRAMBase+PortDetailOffset+iy+2);
				CursorDetail[ix][2] = AsiaMemoryRead8(PemcuDSRAMBase+PortDetailOffset+iy+3);	
				CursorDetail[ix][3] = AsiaMemoryRead8(PemcuDSRAMBase+PortDetailOffset+iy+5);
				break;
			}
		}
		if(CursorDetail[ix][1] == 0){//not found
			CursorDetail[ix][0] = 0x0;
			CursorDetail[ix][1] = 0x0;
			CursorDetail[ix][2] = 0x0;
			CursorDetail[ix][3] = 0x0;
		}		
	}




	DEBUG((EFI_D_ERROR, "[CJW_EMEQ_SEARCH] Error:%d%c%c ",
										ErrorCounter,9,9));
	DEBUG((EFI_D_ERROR, "%d%c %d%c %d%c %d%c ",
										EmTimeE[0]-EmTimeS[0],9,
										EmTimeE[1]-EmTimeS[1],9,
										EmTimeE[2]-EmTimeS[2],9,
										EmTimeE[3]-EmTimeS[3],9));
	DEBUG((EFI_D_ERROR, "%d%c %d%c %d%c %d%c ",
										EmTimeE[4]-EmTimeS[4],9,
										EmTimeE[5]-EmTimeS[5],9,
										EmTimeE[6]-EmTimeS[6],9,
										EmTimeE[7]-EmTimeS[7],9));	
	DEBUG((EFI_D_ERROR, "%d,%d,%d;%d   %d,%d,%d;%d   ",
										CursorDetail[0][0],CursorDetail[0][1],CursorDetail[0][2],CursorDetail[0][3],
										CursorDetail[1][0],CursorDetail[1][1],CursorDetail[1][2],CursorDetail[1][3]
										));
	DEBUG((EFI_D_ERROR, "%d,%d,%d;%d   %d,%d,%d;%d   ",
										CursorDetail[2][0],CursorDetail[2][1],CursorDetail[2][2],CursorDetail[2][3],
										CursorDetail[3][0],CursorDetail[3][1],CursorDetail[3][2],CursorDetail[3][3]
										));	
	DEBUG((EFI_D_ERROR, "%d,%d,%d;%d   %d,%d,%d;%d   ",
										CursorDetail[4][0],CursorDetail[4][1],CursorDetail[4][2],CursorDetail[4][3],
										CursorDetail[5][0],CursorDetail[5][1],CursorDetail[5][2],CursorDetail[5][3]
										));
	DEBUG((EFI_D_ERROR, "%d,%d,%d;%d   %d,%d,%d;%d   ",
										CursorDetail[6][0],CursorDetail[6][1],CursorDetail[6][2],CursorDetail[6][3],
										CursorDetail[7][0],CursorDetail[7][1],CursorDetail[7][2],CursorDetail[7][3]
										));	

	DEBUG((EFI_D_ERROR, "-- %02x,%02x,%02x,%02x,%02x,%02x,%02x,%02x ",
										AsiaPciRead8(AsiaPciAddress(0,3,0,0x52)),
										AsiaPciRead8(AsiaPciAddress(0,3,1,0x52)),
										AsiaPciRead8(AsiaPciAddress(0,3,2,0x52)),
										AsiaPciRead8(AsiaPciAddress(0,3,3,0x52)),
										AsiaPciRead8(AsiaPciAddress(0,4,0,0x52)),
										AsiaPciRead8(AsiaPciAddress(0,4,1,0x52)),
										AsiaPciRead8(AsiaPciAddress(0,5,0,0x52)),
										AsiaPciRead8(AsiaPciAddress(0,5,1,0x52))
										));	

		DEBUG((EFI_D_ERROR, "--COR-- %08x,%08x,%08x,%08x,",
										AsiaPcieRead32(0xE0000000,AsiaPciAddress(0,3,0,0x110)),
										AsiaPcieRead32(0xE0000000,AsiaPciAddress(0,3,1,0x110)),
										AsiaPcieRead32(0xE0000000,AsiaPciAddress(0,3,2,0x110)),
										AsiaPcieRead32(0xE0000000,AsiaPciAddress(0,3,3,0x110))
										));	
		DEBUG((EFI_D_ERROR, "%08x,%08x,%08x,%08x",
										AsiaPcieRead32(0xE0000000,AsiaPciAddress(0,4,0,0x110)),
										AsiaPcieRead32(0xE0000000,AsiaPciAddress(0,4,1,0x110)),
										AsiaPcieRead32(0xE0000000,AsiaPciAddress(0,5,0,0x110)),
										AsiaPcieRead32(0xE0000000,AsiaPciAddress(0,5,1,0x110))	
										));	
		DEBUG((EFI_D_ERROR, "--UNCOR-- %08x,%08x,%08x,%08x,",
										AsiaPcieRead32(0xE0000000,AsiaPciAddress(0,3,0,0x104)),
										AsiaPcieRead32(0xE0000000,AsiaPciAddress(0,3,1,0x104)),
										AsiaPcieRead32(0xE0000000,AsiaPciAddress(0,3,2,0x104)),
										AsiaPcieRead32(0xE0000000,AsiaPciAddress(0,3,3,0x104))
										));	
		DEBUG((EFI_D_ERROR, "%08x,%08x,%08x,%08x\n",
										AsiaPcieRead32(0xE0000000,AsiaPciAddress(0,4,0,0x104)),
										AsiaPcieRead32(0xE0000000,AsiaPciAddress(0,4,1,0x104)),
										AsiaPcieRead32(0xE0000000,AsiaPciAddress(0,5,0,0x104)),
										AsiaPcieRead32(0xE0000000,AsiaPciAddress(0,5,1,0x104))
										));	
	if(NbCfg->PcieEMEQDebug >=2){   //debug level 2 -clear AER
		AsiaPcieModify32(0xE0000000,AsiaPciAddress(0,3,0,0x110),0xFFFFFFFF,0xFFFFFFFF);
		AsiaPcieModify32(0xE0000000,AsiaPciAddress(0,3,1,0x110),0xFFFFFFFF,0xFFFFFFFF);
		AsiaPcieModify32(0xE0000000,AsiaPciAddress(0,3,2,0x110),0xFFFFFFFF,0xFFFFFFFF);
		AsiaPcieModify32(0xE0000000,AsiaPciAddress(0,3,3,0x110),0xFFFFFFFF,0xFFFFFFFF);
		AsiaPcieModify32(0xE0000000,AsiaPciAddress(0,4,0,0x110),0xFFFFFFFF,0xFFFFFFFF);
		AsiaPcieModify32(0xE0000000,AsiaPciAddress(0,4,1,0x110),0xFFFFFFFF,0xFFFFFFFF);
		AsiaPcieModify32(0xE0000000,AsiaPciAddress(0,5,0,0x110),0xFFFFFFFF,0xFFFFFFFF);
		AsiaPcieModify32(0xE0000000,AsiaPciAddress(0,5,1,0x110),0xFFFFFFFF,0xFFFFFFFF);


		AsiaPcieModify32(0xE0000000,AsiaPciAddress(0,3,0,0x104),0xFFFFFFFF,0xFFFFFFFF);
		AsiaPcieModify32(0xE0000000,AsiaPciAddress(0,3,1,0x104),0xFFFFFFFF,0xFFFFFFFF);
		AsiaPcieModify32(0xE0000000,AsiaPciAddress(0,3,2,0x104),0xFFFFFFFF,0xFFFFFFFF);
		AsiaPcieModify32(0xE0000000,AsiaPciAddress(0,3,3,0x104),0xFFFFFFFF,0xFFFFFFFF);
		AsiaPcieModify32(0xE0000000,AsiaPciAddress(0,4,0,0x104),0xFFFFFFFF,0xFFFFFFFF);
		AsiaPcieModify32(0xE0000000,AsiaPciAddress(0,4,1,0x104),0xFFFFFFFF,0xFFFFFFFF);
		AsiaPcieModify32(0xE0000000,AsiaPciAddress(0,5,0,0x104),0xFFFFFFFF,0xFFFFFFFF);
		AsiaPcieModify32(0xE0000000,AsiaPciAddress(0,5,1,0x104),0xFFFFFFFF,0xFFFFFFFF);
	}
			
	DumpMemDxe(NbCfg->PcieEPHYBar+0x2900,0x200);
	DumpMemDxe(NbCfg->PcieEPHYBar+0xA00,0x100);
	DEBUG((EFI_D_ERROR, "[CJW] END\n"));

	//AsiaIoWrite8(0xCF9,0x06);

}	
	return EFI_SUCCESS;
}





