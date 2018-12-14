/** @file
   ZX-E(CHX002) Asia SbPei library functions : IoeDebugSignal.c

   Copyright (c) 2018 Shanghai Zhaoxin Semiconductor Co., Ltd. 

**/

//**************************************************************************
//**************************************************************************
//**                                                                      **
//**  Copyright (c) 2015 - 2017 Shanghai Zhaoxin Semiconductor Co., Ltd.  **
//**                                                                      **
//**************************************************************************
//**************************************************************************


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

#include "IoePreInit.h"
#include "CND003Reg.h"
#include "IoeDebugSignal.h"

#include EFI_PPI_DEFINITION (Smbus)



/**
Note: 
	Start: must be 1DW alignment
	Dcount: means how many DW need to be dump
**/
	/**
	   SATA PEI Init function.
	   Called by SataInitPei()
	   
	  @param  PeiServices	EFI_PEI_SERVICES pointer.
	  @param SbCfg point to ASIA_SB_CONFIGURATION struct
	
	  @return VOID.
	
	**/

VOID
IoeSmbusDumpCfg(
	IN EFI_PEI_SERVICES **PeiServices,
	ASIA_NB_CONFIGURATION *NbConfig,
	UINT8 bus, 
	UINT8 dev, 
	UINT8 func,
	UINT16 Start,
	UINT16 Dcount)
{
	UINT8 temp8s1,temp8s2,temp8s3,temp8s4;
	UINT32 temp32s;	
	UINT16 ix;
	PEI_DEBUG((PeiServices, EFI_D_ERROR, "[CJW_IOE] SMBus-> [%d|%d|%d]:\n",bus,dev,func));
	for(ix = Start ; ix < Dcount; ix+=4){
		IoeSmbusCfgDebugRead8(PeiServices, 0, 0, 0, ix, &temp8s1);
		IoeSmbusCfgDebugRead8(PeiServices, 0, 0, 0, ix+1, &temp8s2);
		IoeSmbusCfgDebugRead8(PeiServices, 0, 0, 0, ix+2, &temp8s3);
		IoeSmbusCfgDebugRead8(PeiServices, 0, 0, 0, ix+3, &temp8s4);
		temp32s = (temp8s4<<24)|(temp8s3<<16)|(temp8s2<<8)|(temp8s1);
		PEI_DEBUG((PeiServices, EFI_D_ERROR, "Rx%04x = 0x%08x\n",Start+ix, temp32s));
	}

}











/**************************************************************************
// SMBus R/W to select DebugSignal
**************************************************************************/
	/**
	   SATA PEI Init function.
	   Called by SataInitPei()
	   
	  @param  PeiServices	EFI_PEI_SERVICES pointer.
	  @param SbCfg point to ASIA_SB_CONFIGURATION struct
	
	  @return VOID.
	
	**/

STATIC
UINTN
IoeSmbusWrite(
	IN EFI_PEI_SERVICES **PeiServices,
	IN UINT8 Taddr,
	IN UINT8 Tdata
)
{
	#define NA	0  		//Don't care
	
	EFI_STATUS Status;
    PEI_SMBUS_PPI* AsiaPeiSmbusPpi;
    EFI_GUID AsiaPeiSmbusPpiGuid = PEI_SMBUS_PPI_GUID; //EFI_ASIA_SB_LIB_PPI_GUID;

	UINTN Len = 2;		//means write
	UINT8 Buf[2];
	UINTN ErrorCount = 0;
	EFI_STATUS Statusx; 

	EFI_SMBUS_DEVICE_ADDRESS Addr;
	Addr.SmbusDeviceAddress = (0xEC>>1);
	
	
   	//DEBUG((EFI_D_ERROR, "[CJW_SMBus] %a() Line%d<--\n",__FUNCTION__,__LINE__));	
	
    Status = (*PeiServices)->LocatePpi(
                 PeiServices, &AsiaPeiSmbusPpiGuid, 0, NULL, &AsiaPeiSmbusPpi);
	//DEBUG((EFI_D_ERROR, "[CJW_SMBus] LocatePpi: status:-->%d\n",Status));	
    //ASSERT_EFI_ERROR(Status);
	ASSERT_PEI_ERROR(PeiServices, Status);
	
/*
SmbusExec (
  IN  CONST EFI_PEI_SERVICES          **PeiServices,
  IN      EFI_PEI_SMBUS_PPI         *This,
  IN      EFI_SMBUS_DEVICE_ADDRESS  SlaveAddress,
  IN      EFI_SMBUS_DEVICE_COMMAND  Command,
  IN      EFI_SMBUS_OPERATION       Operation,
  IN      BOOLEAN                   PecCheck,
  IN OUT  UINTN                     *Length,
  IN OUT  VOID                      *Buffer
  )
*/	

	Buf[0] = Taddr;		//addr offset
	Buf[1] = Tdata;		//data write in
	Statusx = AsiaPeiSmbusPpi->Execute((EFI_PEI_SERVICES **)PeiServices,
								AsiaPeiSmbusPpi,
								Addr,
								(EFI_SMBUS_DEVICE_COMMAND)NA,
								EfiSmbusWriteBlock,
								FALSE,
								&Len,
								Buf);
	if(Statusx!=0){
		ErrorCount+=1;
	}

	//PEI_DEBUG((PeiServices, EFI_D_ERROR, "[CJW_SMBus]           -->W Status: 0x%x\n"));
	//DEBUG((EFI_D_ERROR, "[CJW_SMBus]           -->W Status: 0x%x\n",ErrorCount));
	return ErrorCount;
}

/**
   SATA PEI Init function.
   Called by SataInitPei()
   
  @param  PeiServices	EFI_PEI_SERVICES pointer.
  @param SbCfg point to ASIA_SB_CONFIGURATION struct

  @return VOID.

**/

STATIC
UINTN
IoeSmbusRead(
	IN EFI_PEI_SERVICES **PeiServices,
	IN UINT8 Taddr,
	IN OUT UINT8 *Gdata
)
{
	#define NA	0  		//Don't care
	
	EFI_STATUS Status;
    PEI_SMBUS_PPI* AsiaPeiSmbusPpi;
    EFI_GUID AsiaPeiSmbusPpiGuid = PEI_SMBUS_PPI_GUID; //EFI_ASIA_SB_LIB_PPI_GUID;

	UINTN Len = 1;		//means write
	UINT8 Buf[2];
	UINTN ErrorCount = 0;
	EFI_STATUS Statusx; 

	EFI_SMBUS_DEVICE_ADDRESS Addr;
	Addr.SmbusDeviceAddress = (0xEC>>1);
	

   	//DEBUG((EFI_D_ERROR, "[CJW_SMBus] %a() Line%d<--\n",__FUNCTION__,__LINE__));	

    Status = (*PeiServices)->LocatePpi(
                 PeiServices, &AsiaPeiSmbusPpiGuid, 0, NULL, &AsiaPeiSmbusPpi);
	//DEBUG((EFI_D_ERROR, "[CJW_SMBus] LocatePpi: status:-->%d\n",Status));	
    //ASSERT_EFI_ERROR(Status);
	ASSERT_PEI_ERROR(PeiServices, Status);
	
/*
SmbusExec (
  IN  CONST EFI_PEI_SERVICES          **PeiServices,
  IN      EFI_PEI_SMBUS_PPI         *This,
  IN      EFI_SMBUS_DEVICE_ADDRESS  SlaveAddress,
  IN      EFI_SMBUS_DEVICE_COMMAND  Command,
  IN      EFI_SMBUS_OPERATION       Operation,
  IN      BOOLEAN                   PecCheck,
  IN OUT  UINTN                     *Length,
  IN OUT  VOID                      *Buffer
  )
*/	

	Buf[0] = Taddr;		//addr offset
	Statusx = AsiaPeiSmbusPpi->Execute((EFI_PEI_SERVICES **)PeiServices,
								AsiaPeiSmbusPpi,
								Addr,
								(EFI_SMBUS_DEVICE_COMMAND)NA,
								EfiSmbusWriteBlock,
								FALSE,
								&Len,
								Buf);
	if(Statusx!=0){
		ErrorCount+=1;
	}

	Statusx = AsiaPeiSmbusPpi->Execute((EFI_PEI_SERVICES **)PeiServices,
								AsiaPeiSmbusPpi,
								Addr,
								(EFI_SMBUS_DEVICE_COMMAND)NA,
								EfiSmbusReadBlock,
								FALSE,
								&Len,
								Buf);
	if(Statusx!=0){
		ErrorCount+=3;
	}	

	*Gdata = Buf[0]; 		//return value
	
	//DEBUG((EFI_D_ERROR, "[CJW_SMBus]           -->R Status: 0x%x  Buf[0]= 0x%02x, Buf[1]= 0x%02x\n",ErrorCount,Buf[0], Buf[1]));
	//PEI_DEBUG((PeiServices, EFI_D_ERROR, "[CJW_SMBus]           -->R Status: 0x%x  Buf[0]= 0x%02x, Buf[1]= 0x%02x\n",ErrorCount,Buf[0], Buf[1]));
	return ErrorCount;
}


/**
   SATA PEI Init function.
   Called by SataInitPei()
   
  @param  PeiServices	EFI_PEI_SERVICES pointer.
  @param SbCfg point to ASIA_SB_CONFIGURATION struct

  @return VOID.

**/

STATIC 
UINTN
IoeSmbusModify8(
	IN EFI_PEI_SERVICES **PeiServices,
	IN UINT8 Taddr,
	IN UINT8 Mask,
	IN UINT8 Val)
{
	UINT8 temp8;

	IoeSmbusRead((EFI_PEI_SERVICES **)PeiServices, Taddr, &temp8);
	temp8 &= (~Mask);
	temp8 |=(Val & Mask);
	IoeSmbusWrite((EFI_PEI_SERVICES **)PeiServices, Taddr, temp8);

	return 0;
}

/**
   SATA PEI Init function.
   Called by SataInitPei()
   
  @param  PeiServices	EFI_PEI_SERVICES pointer.
  @param SbCfg point to ASIA_SB_CONFIGURATION struct

  @return VOID.

**/

UINT32 PCIAddrToSMBusAddr(UINT8 bus,UINT8 dev,UINT8 fun, UINT16 byRegOffset)
{
   UINT32 SMBusAddr=0;
   UINT16 bdf=0;
   UINT8 temp=byRegOffset&0xff;
   SMBusAddr|=(byRegOffset&0xf00);
   SMBusAddr|=bus;
   SMBusAddr<<=16;
   bdf|=((dev<<3)|fun);
   bdf<<=8;
   bdf|=temp;
   SMBusAddr|=bdf;
   return SMBusAddr;
}

/**
   SATA PEI Init function.
   Called by SataInitPei()
   
  @param  PeiServices	EFI_PEI_SERVICES pointer.
  @param SbCfg point to ASIA_SB_CONFIGURATION struct

  @return VOID.

**/

STATIC
UINTN
IoeSmbusDebugRead(
	IN EFI_PEI_SERVICES **PeiServices,
	IN UINT32 address,//cfg address,or mem addr,or io addr
	IN UINT8 flag,//0 for cfg,1 for mem,2 for io
	IN OUT UINT32* Gdata
)
{
	#define NA	0  		//Don't care
	EFI_STATUS Status;
    PEI_SMBUS_PPI* AsiaPeiSmbusPpi;
    EFI_GUID AsiaPeiSmbusPpiGuid = PEI_SMBUS_PPI_GUID; //EFI_ASIA_SB_LIB_PPI_GUID;
	UINTN Len = 5;		//means write
	UINT8 Buf[5];   //for read 
	UINTN ErrorCount = 0;
	EFI_STATUS Statusx; 
	EFI_SMBUS_DEVICE_ADDRESS Addr;
	Addr.SmbusDeviceAddress = (0xEC>>1);
	Buf[0]=(UINT8)address&0xff;
    Buf[1]=(UINT8)((address>>8)&0xff);
    Buf[2]=(UINT8)((address>>16)&0xff);
	Buf[3]=(UINT8)((address>>24)&0xff);
	Buf[4]=flag;
    Status = (*PeiServices)->LocatePpi(
                 PeiServices, &AsiaPeiSmbusPpiGuid, 0, NULL, &AsiaPeiSmbusPpi);
	ASSERT_PEI_ERROR(PeiServices, Status);
	Statusx = AsiaPeiSmbusPpi->Execute((EFI_PEI_SERVICES **)PeiServices,
								AsiaPeiSmbusPpi,
								Addr,
								(EFI_SMBUS_DEVICE_COMMAND)NA,
								EfiSmbusWriteBlock,
								FALSE,
								&Len,
								Buf);
	if(Statusx!=0){
		ErrorCount+=1;
	}
    Len=4;
	Statusx = AsiaPeiSmbusPpi->Execute((EFI_PEI_SERVICES **)PeiServices,
								AsiaPeiSmbusPpi,
								Addr,
								(EFI_SMBUS_DEVICE_COMMAND)NA,
								EfiSmbusReadBlock,
								FALSE,
								&Len,
								Gdata);
	if(Statusx!=0){
		ErrorCount+=3;
	}	
	//PEI_DEBUG((PeiServices, EFI_D_ERROR, "[CJW_SMBus]           -->R Status: 0x%x  Gdata:0x%04x\n",ErrorCount,*Gdata));
	return ErrorCount;
}

/**
   SATA PEI Init function.
   Called by SataInitPei()
   
  @param  PeiServices	EFI_PEI_SERVICES pointer.
  @param SbCfg point to ASIA_SB_CONFIGURATION struct

  @return VOID.

**/

STATIC
UINTN
IoeSmbusDebugWrite(
	IN EFI_PEI_SERVICES **PeiServices,
	IN UINT32 address,//cfg address,or mem addr,or io addr
	IN UINT8 flag,//0 for cfg,1 for mem,2 for io
	IN OUT UINT8 Gdata//for now,we support single byte write only
)
{
	#define NA	0  		//Don't care
	EFI_STATUS Status;
    PEI_SMBUS_PPI* AsiaPeiSmbusPpi;
    EFI_GUID AsiaPeiSmbusPpiGuid = PEI_SMBUS_PPI_GUID; //EFI_ASIA_SB_LIB_PPI_GUID;
	UINTN Len = 6;		//means write
	UINT8 Buf[6];   //for read 
	UINTN ErrorCount = 0;
	EFI_STATUS Statusx; 
	EFI_SMBUS_DEVICE_ADDRESS Addr;
	Addr.SmbusDeviceAddress = (0xEC>>1);
	Buf[0]=(UINT8)address&0xff;
	Buf[1]=(UINT8)((address>>8)&0xff);
    Buf[2]=(UINT8)((address>>16)&0xff);
	Buf[3]=(UINT8)((address>>24)&0xff);
	Buf[4]=flag;
	Buf[5]=Gdata;
    Status = (*PeiServices)->LocatePpi(
                 PeiServices, &AsiaPeiSmbusPpiGuid, 0, NULL, &AsiaPeiSmbusPpi);
	ASSERT_PEI_ERROR(PeiServices, Status);
	Statusx = AsiaPeiSmbusPpi->Execute((EFI_PEI_SERVICES **)PeiServices,
								AsiaPeiSmbusPpi,
								Addr,
								(EFI_SMBUS_DEVICE_COMMAND)NA,
								EfiSmbusWriteBlock,
								FALSE,
								&Len,
								Buf);
	if(Statusx!=0){
		ErrorCount+=1;
	}
	//PEI_DEBUG((PeiServices, EFI_D_ERROR, "[CJW_SMBus]           -->R Status: 0x%x  Gdata:0x%02x\n",ErrorCount,Gdata));
	return ErrorCount;
}

/**
   SATA PEI Init function.
   Called by SataInitPei()
   
  @param  PeiServices	EFI_PEI_SERVICES pointer.
  @param SbCfg point to ASIA_SB_CONFIGURATION struct

  @return VOID.

**/

UINTN
IoeSmbusDebugModify8(IN EFI_PEI_SERVICES **PeiServices,
	IN UINT32 address,//cfg address,or mem addr,or io addr
	IN UINT8 flag,//0 for cfg,1 for mem,2 for io
	IN UINT8 Mask,
	IN OUT UINT8 Gdata//for now,we support single byte write only
	)
{
	UINT32 temp32;
	UINT8 value8;
	UINT8 temp=address&0x03;
	IoeSmbusDebugRead(PeiServices,address&0xfffffffc,flag,&temp32);
	value8=((temp32&(0xff<<temp*8))>>temp*8);
	value8 &= (~Mask);
	value8 |=(Gdata & Mask);
	IoeSmbusDebugWrite(PeiServices,address,flag,value8);
    return 0;
}

/**
   SATA PEI Init function.
   Called by SataInitPei()
   
  @param  PeiServices	EFI_PEI_SERVICES pointer.
  @param SbCfg point to ASIA_SB_CONFIGURATION struct

  @return VOID.

**/

UINTN
IoeSmbusCfgDebugRead8(
	IN EFI_PEI_SERVICES **PeiServices,
	IN UINT8 bus,
	IN UINT8 dev,
	IN UINT8 fun,
	IN UINT16 regoffset,
	IN OUT UINT8* Gdata
)
{
   UINT32 address;
   UINT32 readvalue;
   UINT8 temp=regoffset&0x03;
   address=PCIAddrToSMBusAddr(bus, dev, fun, regoffset);
   IoeSmbusDebugRead(PeiServices,address,0,&readvalue);
   *Gdata=((readvalue&(0xff<<temp*8))>>temp*8);
   return 0;
}

/**
   SATA PEI Init function.
   Called by SataInitPei()
   
  @param  PeiServices	EFI_PEI_SERVICES pointer.
  @param SbCfg point to ASIA_SB_CONFIGURATION struct

  @return VOID.

**/

UINTN
IoeSmbusCfgDebugWrite8(
	IN EFI_PEI_SERVICES **PeiServices,
	IN UINT8 bus,
	IN UINT8 dev,
	IN UINT8 fun,
	IN UINT16 regoffset,
	IN OUT UINT8 Gdata
)
{
	UINT32 address;
	address=PCIAddrToSMBusAddr(bus, dev, fun, regoffset);
	IoeSmbusDebugWrite(PeiServices,address,0,Gdata);
	return 0;
}

/**
   SATA PEI Init function.
   Called by SataInitPei()
   
  @param  PeiServices	EFI_PEI_SERVICES pointer.
  @param SbCfg point to ASIA_SB_CONFIGURATION struct

  @return VOID.

**/

UINTN
IoeSmbusCfgDebugModify8(
	IN EFI_PEI_SERVICES **PeiServices,
	IN UINT8 bus,
	IN UINT8 dev,
	IN UINT8 fun,
	IN UINT16 regoffset,
	IN UINT8 Mask,
	IN UINT8 Val)
{
	UINT8 temp8;
	IoeSmbusCfgDebugRead8((EFI_PEI_SERVICES **)PeiServices,bus,dev,fun,regoffset, &temp8);
	temp8 &= (~Mask);
	temp8 |=(Val & Mask);
	IoeSmbusCfgDebugWrite8((EFI_PEI_SERVICES **)PeiServices, bus,dev,fun,regoffset,temp8);
	return 0;
}

/**
   SATA PEI Init function.
   Called by SataInitPei()
   
  @param  PeiServices	EFI_PEI_SERVICES pointer.
  @param SbCfg point to ASIA_SB_CONFIGURATION struct

  @return VOID.

**/

UINTN IoeSmbusDebugPathEnable(IN EFI_PEI_SERVICES **PeiServices,UINT8 flag)
{
  if(flag)
  	{
	  IoeSmbusModify8(PeiServices,0x00,BIT0,BIT0);
  }
 else
 	 IoeSmbusModify8(PeiServices,0x00,BIT0,0x0);
 return 0;
}




#if IOE_PRE_INIT_LOCATION == IOE_ASIA_PEI_SB


/**
	This routine is for CND003 DebugSignal Group selection
	the debug signal group/module will be read from SetupMenu
	this routine should be called in NbPcie.c 
**/
	/**
	   SATA PEI Init function.
	   Called by SataInitPei()
	   
	  @param  PeiServices	EFI_PEI_SERVICES pointer.
	  @param SbCfg point to ASIA_SB_CONFIGURATION struct
	
	  @return VOID.
	
	**/

EFI_STATUS
IoeDebugSignalSel(
	IN EFI_PEI_SERVICES **PeiServices,
	ASIA_NB_CONFIGURATION *NbCfg)
{
	//TODO: sad
	EFI_GUID SMBusGUID = PEI_SMBUS_PPI_GUID;
	PEI_SMBUS_PPI *pSMBusPPI;
	EFI_STATUS Status = EFI_SUCCESS;
	UINT32 MmioBar;


	UINT8 ModuleG0,ModuleG1;
	UINT16 Group0,Group1,Group2,Group3;
    UINT16 Group0_XHCI,Group1_XHCI,Group2_XHCI,Group3_XHCI;
	UINT8 SuspendModule;
	UINT8 HighSpeedEnable,HighSpeedModuleGx;
	UINT16 HighSpeedGx;
	UINT8 CorePowerOff;
	UINT8 Cnd003DbgPadG0En,Cnd003DbgPadG1En,Cnd003DbgPadG2En,Cnd003DbgPadG3En;
	UINT8 vc,ix;


	if(NbCfg->Cnd003DebugFromCpu == 0){
		PEI_DEBUG((PeiServices,EFI_D_ERROR,"[CJW_IOE] IoeDebugSignalSel() Exist Directly!\n"));
		return EFI_SUCCESS;
	}

		
	//Get SMBUS operator :
	Status = (*PeiServices)->LocatePpi(PeiServices, &SMBusGUID, 0, NULL, &pSMBusPPI);
	ASSERT_PEI_ERROR (PeiServices, Status);	

	

	MmioBar = AsiaPciRead32(AsiaPciAddress(BUSX, UPPORT_DEV, UPPORT_FUN, 0x10));


	//
	// Step 0: Setting the DebugSignal selection source 
	//
	if(NbCfg->Cnd003DebugFromCpu == 0){  //disable-SPI
		AsiaMemoryModify8(MmioBar + MMIO_ISB_OFFSET + CND003_MMIO_D0F0_STRAPPING_PIN_READ_BACK_REG_GRP_2, CND003_MMIO_D0F0_RSPIHDR_DBGCTLSEL, BIT0);
		PEI_DEBUG((PeiServices,EFI_D_ERROR,"[CJW_IOE] DBG source: Disable/SPI\n"));
	}else if(NbCfg->Cnd003DebugFromCpu == 1){ //MMIO CPU
		AsiaMemoryModify8(MmioBar + MMIO_ISB_OFFSET + CND003_MMIO_D0F0_STRAPPING_PIN_READ_BACK_REG_GRP_2, CND003_MMIO_D0F0_RSPIHDR_DBGCTLSEL, BIT1);
		PEI_DEBUG((PeiServices,EFI_D_ERROR,"[CJW_IOE] DBG source: MMIO\n"));
	}else if(NbCfg->Cnd003DebugFromCpu == 2){ //SMBus
		AsiaMemoryModify8(MmioBar + MMIO_ISB_OFFSET + CND003_MMIO_D0F0_STRAPPING_PIN_READ_BACK_REG_GRP_2, CND003_MMIO_D0F0_RSPIHDR_DBGCTLSEL, 0);
		PEI_DEBUG((PeiServices,EFI_D_ERROR,"[CJW_IOE] DBG source: SMBus\n"));
	}else{
		PEI_DEBUG((PeiServices,EFI_D_ERROR,"[CJW_IOE] DBG source: unknown\n"));
	}



	//Get the setting from Setup Menu
	ModuleG0 = (UINT8)(NbCfg->Cnd003ModuleG0);
	ModuleG1 = (UINT8)(NbCfg->Cnd003ModuleG1);
	Group0 = (UINT16)(NbCfg->Cnd003DebugG0);
	Group1 = (UINT16)(NbCfg->Cnd003DebugG1);
	Group2 = (UINT16)(NbCfg->Cnd003DebugG2);
	Group3 = (UINT16)(NbCfg->Cnd003DebugG3);
    Group0_XHCI = (UINT16)(NbCfg->Cnd003DebugG0_XHCI);
	Group1_XHCI = (UINT16)(NbCfg->Cnd003DebugG1_XHCI);
	Group2_XHCI = (UINT16)(NbCfg->Cnd003DebugG2_XHCI);
	Group3_XHCI = (UINT16)(NbCfg->Cnd003DebugG3_XHCI);
	SuspendModule = (UINT8)(NbCfg->Cnd003DebugSuspend);
	HighSpeedEnable = (UINT8)(NbCfg->Cnd003HighSpeed);
	HighSpeedModuleGx = (UINT8)(NbCfg->Cnd003HighSpeedModuleSel);
	HighSpeedGx = (UINT16)(NbCfg->Cnd003HighSpeedDbgSel);
	CorePowerOff = (UINT8)(NbCfg->Cnd003CorePowerOff);
	Cnd003DbgPadG0En = (UINT8)(NbCfg->Cnd003DbgPadG0En);
	Cnd003DbgPadG1En = (UINT8)(NbCfg->Cnd003DbgPadG1En);
	Cnd003DbgPadG2En = (UINT8)(NbCfg->Cnd003DbgPadG2En);
	Cnd003DbgPadG3En = (UINT8)(NbCfg->Cnd003DbgPadG3En);
			
	//
	PEI_DEBUG((PeiServices, EFI_D_ERROR, "[CJW_IOE_DEBUG_SIGNAL] Select From Cpu [On]\n"));
	PEI_DEBUG((PeiServices, EFI_D_ERROR, "[CJW_IOE_DEBUG_SIGNAL] ModuleG0[0x%02x]\n",ModuleG0));
	PEI_DEBUG((PeiServices, EFI_D_ERROR, "[CJW_IOE_DEBUG_SIGNAL] ModuleG1[0x%02x]\n",ModuleG1));
	PEI_DEBUG((PeiServices, EFI_D_ERROR, "[CJW_IOE_DEBUG_SIGNAL] G0[0x%04x]\n",Group0));
	PEI_DEBUG((PeiServices, EFI_D_ERROR, "[CJW_IOE_DEBUG_SIGNAL] G1[0x%04x]\n",Group1));
	PEI_DEBUG((PeiServices, EFI_D_ERROR, "[CJW_IOE_DEBUG_SIGNAL] G2[0x%04x]\n",Group2));
	PEI_DEBUG((PeiServices, EFI_D_ERROR, "[CJW_IOE_DEBUG_SIGNAL] G3[0x%04x]\n",Group3));
	PEI_DEBUG((PeiServices, EFI_D_ERROR, "[CJW_IOE_DEBUG_SIGNAL] SuspendModule[0x%02x]\n",SuspendModule));
	PEI_DEBUG((PeiServices, EFI_D_ERROR, "[CJW_IOE_DEBUG_SIGNAL] HighSpeedEnable[0x%02x]\n",HighSpeedEnable));
	PEI_DEBUG((PeiServices, EFI_D_ERROR, "[CJW_IOE_DEBUG_SIGNAL] HighSpeedModuleGx[0x%02x]\n",HighSpeedModuleGx));
	PEI_DEBUG((PeiServices, EFI_D_ERROR, "[CJW_IOE_DEBUG_SIGNAL] HighSpeedGx[0x%04x]\n",HighSpeedGx));
	PEI_DEBUG((PeiServices, EFI_D_ERROR, "[CJW_IOE_DEBUG_SIGNAL] CorePowerOff[0x%02x]\n",CorePowerOff));



	//
	//3 Case 1: [Disable]
	//	
	if(NbCfg->Cnd003DebugFromCpu == 0){

		PEI_DEBUG((PeiServices, EFI_D_ERROR, "[CJW_IOE] Debug Signal Selection [Disable] -> From SPI header(Only for SPI mode)\n"));	
		//IoePeiClearTempAssignment(PeiServices);
		//return Status;
	}


	//
	//3 Case 2: [From MMIO_ISB]
	//	
	else if(NbCfg->Cnd003DebugFromCpu == 1){

		PEI_DEBUG((PeiServices, EFI_D_ERROR, "[CJW_IOE] Debug Signal Selection [From MMIO_ISB]\n"));


		//set MMIO_ISB Rx36[1:0]  - select from CPU
		AsiaMemoryModify8(MmioBar + MMIO_ISB_OFFSET + CND003_MMIO_D0F0_STRAPPING_PIN_READ_BACK_REG_GRP_2, CND003_MMIO_D0F0_RSPIHDR_DBGCTLSEL, BIT1);


		//
		//4 Step 2.1 Clear Pin Setting & Clear HS/SUS
		//
		// Non-HighSpeed
		// R_IOEDEBUGPAD_EN (For Silicon) -> Disable Pin
		AsiaMemoryModify8(MmioBar + MMIO_ISB_OFFSET + CND003_MMIO_D0F0_VCORE_PAD_SETTING, CND003_MMIO_D0F0_R_IOEDEBUGPAD_EN, 0);		
		
		// Non-Sus(CorePowerOff)
		//
		AsiaMemoryModify8(MmioBar + MMIO_ISB_OFFSET + 0xCE, BIT1, 0);

		// Normal
		AsiaMemoryModify16(MmioBar+MMIO_ISB_OFFSET+0x7C, BIT11, 0);		//RGMII pin <- DebugSignal[44:32]
		if((NbCfg->IoeChipRevision) == IOE_REVISION_A0){
		AsiaMemoryModify16(MmioBar+MMIO_ISB_OFFSET+CND003_MMIO_D0F0_VCORE_PAD_SETTING, BIT4, 0); 		//GPIO pin <- DebugSignal[15:0]
			}
		else//IOE AI patch,Debug signal select-GPIO change to ISB Rx51[2]
			{
        AsiaMemoryModify16(MmioBar+MMIO_ISB_OFFSET+CND003_MMIO_D0F0_CKGSRC_SETTING_GRP_1, BIT2, 0); 		//GPIO pin <- DebugSignal[15:0]
		}
		AsiaMemoryModify16(MmioBar+MMIO_ISB_OFFSET+0x7C, BIT9|BIT8, 0); //USBoc io & CCPHY io <- DebugSignal[31:16]		

		// MemRd cycle for debug - catc capture
		AsiaMemoryRead32(MmioBar+MMIO_ISB_OFFSET+0xFF);
		AsiaMemoryRead32(MmioBar+MMIO_ISB_OFFSET+0xFF);
		AsiaMemoryRead32(MmioBar+MMIO_ISB_OFFSET+0xFF);
		AsiaMemoryRead32(MmioBar+MMIO_ISB_OFFSET+0xFF);
		
		//
		//4 Step 2.2 Case: HighSpeed
		//
		if(HighSpeedEnable == 1){
			//RDBG_HIGH_MODULE_SEL
			AsiaMemoryModify32(MmioBar + MMIO_ISB_OFFSET + CND003_MMIO_D0F0_DEBUG_SEL_SETTING_2, CND003_MMIO_D0F0_RDBG_HIGH_MODULE_SEL, HighSpeedModuleGx<<24);
			//RDBG_HIGH_SEL
			AsiaMemoryModify32(MmioBar + MMIO_ISB_OFFSET + CND003_MMIO_D0F0_DEBUG_SEL_SETTING_3, CND003_MMIO_D0F0_RDBG_HIGH_SEL, HighSpeedGx);

			//R_IOEDEBUGPAD_EN (For Silicon) -> Enable Pin
			AsiaMemoryModify8(MmioBar + MMIO_ISB_OFFSET + CND003_MMIO_D0F0_VCORE_PAD_SETTING, BIT7, BIT7);

			//return EFI_SUCCESS;
		}

		//
		//4 Step 2.3 Case: Suspend - CorePowerOff
		//
		if(CorePowerOff == 1){
			AsiaMemoryModify8(MmioBar + MMIO_ISB_OFFSET + 0xCE, BIT1, BIT1);
			
			//SUS Module Select
			AsiaMemoryWrite8(MmioBar+MMIO_ISB_OFFSET+0xCA, SuspendModule);

			AsiaMemoryWrite16(MmioBar+MMIO_ISB_OFFSET+0xC2, Group1);			//only group1 can be used

			//AsiaMemoryModify16(MmioBar+MMIO_ISB_OFFSET+0x7C, BIT9|BIT8, BIT9|BIT8); //USBoc io & CCPHY io -> DebugSignal[31:16]
			//AsiaMemoryModify16(MmioBar+MMIO_ISB_OFFSET+0x7C, BIT11, BIT11);			//RGMII pin -> DBG[31]

			// Need set Rx7C[8][9][11] to enable dbg output
			goto _exitdbg;
			//return EFI_SUCCESS;
		}

		//
		//4 Step 2.4 Case: [Suspend - CorePowerOn] or [Normal Case] 
		//
		if((ModuleG0 == 0xA)||(ModuleG1 == 0xA)){ 
			// Suspend(core power on) special
			
			PEI_DEBUG((PeiServices, EFI_D_ERROR, "[CJW_IOE_DEBUG_SIGNAL] ISB_SUS\n"));	
			//Module Select
			AsiaMemoryWrite8(MmioBar + MMIO_ISB_OFFSET + 0xC8, ModuleG0);
			AsiaMemoryWrite8(MmioBar + MMIO_ISB_OFFSET + 0xC9, ModuleG1);

			//SUS Module Select
			AsiaMemoryWrite8(MmioBar+MMIO_ISB_OFFSET+0xCA, SuspendModule);
		}
        //
        //Step 2.5 Case: XHCI Module Select 
        //
        //if((ModuleG0 == 0xD)||(ModuleG1 == 0xD)){
        //    AsiaPciModify8((CND003_XHCI | 0x43),	  0x01,  0x01); // Enable Access
		//    AsiaPciModify32((CND003_XHCI | 0x78), 0xFFFFF, 0x54);
		//    AsiaPciModify32((CND003_XHCI | 0x7C), 0xFFFF0000, (Group0_XHCI<<16|Group1_XHCI<<20|Group2_XHCI<<24|Group3_XHCI<<28));    
		//    AsiaPciModify8((CND003_XHCI | 0x43),	  0x01,  0x00); // Disable Access
        // }
								
		//Module Select
		AsiaMemoryWrite8(MmioBar+MMIO_ISB_OFFSET+0xC8, ModuleG0);
		AsiaMemoryWrite8(MmioBar+MMIO_ISB_OFFSET+0xC9, ModuleG1);
					
		//G select
		AsiaMemoryWrite16(MmioBar+MMIO_ISB_OFFSET+0xC0, Group0);	
		AsiaMemoryWrite16(MmioBar+MMIO_ISB_OFFSET+0xC2, Group1);	
		AsiaMemoryWrite16(MmioBar+MMIO_ISB_OFFSET+0xC4, Group2);	
		AsiaMemoryWrite16(MmioBar+MMIO_ISB_OFFSET+0xC6, Group3);	

		//Pin Mux - Select for DebugSignal
		//AsiaMemoryModify16(MmioBar+MMIO_ISB_OFFSET+0x7C, BIT11, BIT11);	//RGMII pin -> DebugSignal[44:32]
		//AsiaMemoryModify16(MmioBar+MMIO_ISB_OFFSET+0x10, BIT4, BIT4); //GPIO pin -> DebugSignal[15:0]
		//AsiaMemoryModify16(MmioBar+MMIO_ISB_OFFSET+0x7C, BIT9|BIT8, BIT9|BIT8); //USBoc io & CCPHY io -> DebugSignal[31:16]


		// MemRd cycle for debug - catc capture
		AsiaMemoryRead32(MmioBar+MMIO_ISB_OFFSET+0xF0);
		AsiaMemoryRead32(MmioBar+MMIO_ISB_OFFSET+0xF0);
		AsiaMemoryRead32(MmioBar+MMIO_ISB_OFFSET+0xF0);
		AsiaMemoryRead32(MmioBar+MMIO_ISB_OFFSET+0xF0);

		goto _exitdbg;
	}

	//
	//3 Case 1.3:[From SMBus]
	//
	else if(NbCfg->Cnd003DebugFromCpu == 2){
		PEI_DEBUG((PeiServices, EFI_D_ERROR, "[CJW_IOE] Debug Signal Selection [From SMBus]\n"));
		
		//set MMIO_ISB Rx36[1:0]  - select from SMBus
		// --Need PEEP link up
		AsiaMemoryModify8(MmioBar + MMIO_ISB_OFFSET + CND003_MMIO_D0F0_STRAPPING_PIN_READ_BACK_REG_GRP_2, CND003_MMIO_D0F0_RSPIHDR_DBGCTLSEL, 0);


		//
		//4 Step 3.1: HighSpeed
		//
		if(NbCfg->Cnd003HighSpeed){
			// TODO: Question - Can not set pin mux - still need to set by MMIO? If so, when PCIE upstream port link not ready, this will not work?
			
			//HIGH_MODULE_SEL  0E[3:0] = G0
			IoeSmbusWrite((EFI_PEI_SERVICES **)PeiServices, 0x0E, HighSpeedModuleGx);
			//RDBG_HIGH_SEL
			IoeSmbusWrite((EFI_PEI_SERVICES **)PeiServices, 0x0C, HighSpeedGx&0xFF);
			IoeSmbusWrite((EFI_PEI_SERVICES **)PeiServices, 0x0D, (HighSpeedGx>>8)&0xF);

		//
		//4 Step 3.2: Suspend
		//
		}else if((ModuleG0 == 0xA)||(ModuleG1 == 0xA)){
			//Module sel -- ISB_SUS 
			IoeSmbusWrite((EFI_PEI_SERVICES **)PeiServices, 0x0A, 0xFF&(((ModuleG1&0xF)<<4)|(ModuleG0&0xF)));//all sel Sus

			//SMB_DBG_SUS_MODULE_SEL
			IoeSmbusWrite((EFI_PEI_SERVICES **)PeiServices, 0x0B, 0xF&SuspendModule);
				
			//SMB_DBG_SEL_G0 ~ SMB_DBG_SEL_G3  
			//IoeSmbusWrite((EFI_PEI_SERVICES **)PeiServices, 0x02, 0xFF&Group0);
			//IoeSmbusWrite((EFI_PEI_SERVICES **)PeiServices, 0x03, 0xF&(Group0>>8));
			//IoeSmbusWrite((EFI_PEI_SERVICES **)PeiServices, 0x04, 0xFF&Group1);
			//IoeSmbusWrite((EFI_PEI_SERVICES **)PeiServices, 0x05, 0xF&(Group1>>8));
			//IoeSmbusWrite((EFI_PEI_SERVICES **)PeiServices, 0x06, 0xFF&Group2);
			//IoeSmbusWrite((EFI_PEI_SERVICES **)PeiServices, 0x07, 0xF&(Group2>>8));
			//IoeSmbusWrite((EFI_PEI_SERVICES **)PeiServices, 0x08, 0xFF&Group3);
			//IoeSmbusWrite((EFI_PEI_SERVICES **)PeiServices, 0x09, 0xF&(Group3>>8));

			//Sus En
			//Not found in SMBus internal registers	
			// TODO: There was not found Sus En register in SMBus internal register, so how can we set it? or we can't use this from SMBus?
		}

		//
		//4 Step 3.3: Normal
		//
		// TODO: Currently, "Normal" path is the only one to work correctly...
		
		//[1]
		//SMB_DBGINGPIOGRP_EN = 1 (Not implemented on HAPS)
		//IoeSmbusModify((EFI_PEI_SERVICES **)PeiServices, 0x0F, BIT3, BIT3);
				
		//[2]
		//SMB_DBG_MODULE_SEL_G1 = 0100b --> for MCU
		//SMB_DBG_MODULE_SEL_G0 = 0100b	--> for MCU
		/* SMB_DBG_MODULE_SEL_G1/G0
		0h: clock counter
		1h: PCIEIF
		2h: EPTRFC
		3h: ISB_BUSXD0F0_CORE
		4h: DBGMCU
		5h: SATA
		6h: USBC_CORE_D14
		7h: USBC_CORE_D16
		8h: GNIC
		9h: TOP
		Ah: ISB_SUS
		Bh: INTMAP
		Ch: DBGCAP
		Dh: XHCI
		Eh: PCIE
		*/
		IoeSmbusWrite((EFI_PEI_SERVICES **)PeiServices, 0x0A, (0xF0&(ModuleG1<<4))|(ModuleG0&0xF));

		//[3] 
		//SMB_DBG_SEL_G0 ~ SMB_DBG_SEL_G3  
		IoeSmbusWrite((EFI_PEI_SERVICES **)PeiServices, 0x02, 0xFF&Group0);
		IoeSmbusWrite((EFI_PEI_SERVICES **)PeiServices, 0x03, 0xF&(Group0>>8));
		IoeSmbusWrite((EFI_PEI_SERVICES **)PeiServices, 0x04, 0xFF&Group1);
		IoeSmbusWrite((EFI_PEI_SERVICES **)PeiServices, 0x05, 0xF&(Group1>>8));
		IoeSmbusWrite((EFI_PEI_SERVICES **)PeiServices, 0x06, 0xFF&Group2);
		IoeSmbusWrite((EFI_PEI_SERVICES **)PeiServices, 0x07, 0xF&(Group2>>8));
		IoeSmbusWrite((EFI_PEI_SERVICES **)PeiServices, 0x08, 0xFF&Group3);
		IoeSmbusWrite((EFI_PEI_SERVICES **)PeiServices, 0x09, 0xF&(Group3>>8));

		//[4]
		//Dump SMBus register setting
		PEI_DEBUG((PeiServices,EFI_D_ERROR, "[CJW_SMBus]  Dump SMBus register setting \n"));
		for(ix = 0; ix<0x10; ix++){
			IoeSmbusRead((EFI_PEI_SERVICES **)PeiServices, ix, &vc);
			PEI_DEBUG((PeiServices,EFI_D_ERROR, "[CJW_SMBus]  Rx%02X = 0x%02X \n",ix,vc));
		}


	}
	//
	// Case 4: Unknown path
	//
	else{
		PEI_DEBUG((PeiServices, EFI_D_ERROR, "[CJW_IOE] Debug Signal Selection [Unknown path]\n"));
	}



_exitdbg:
	//
	// DebugSingal PAD configure
	//
	if(NbCfg->Cnd003DebugFromCpu == 0){  //disable-SPI
		//Disable Normal Pin used for DebugSignal
		if((NbCfg->IoeChipRevision) == IOE_REVISION_A0){
		AsiaMemoryModify16(MmioBar + MMIO_ISB_OFFSET + CND003_MMIO_D0F0_VCORE_PAD_SETTING, BIT4, 0);
			}
		 else//IOE AI patch,Debug signal select-GPIO change to ISB Rx51[2]
			{
        AsiaMemoryModify16(MmioBar+MMIO_ISB_OFFSET+CND003_MMIO_D0F0_CKGSRC_SETTING_GRP_1, BIT2, 0);
			}
		AsiaMemoryModify16(MmioBar + MMIO_ISB_OFFSET + 0x7C, BIT9, 0);
		AsiaMemoryModify16(MmioBar + MMIO_ISB_OFFSET + 0x7C, BIT8, 0);
		AsiaMemoryModify16(MmioBar + MMIO_ISB_OFFSET + 0x7C, BIT11, 0);	

		//
		// Non-HighSpeed
		// R_IOEDEBUGPAD_EN (For Silicon) -> Disable Pin
		AsiaMemoryModify8(MmioBar + MMIO_ISB_OFFSET + CND003_MMIO_D0F0_VCORE_PAD_SETTING, CND003_MMIO_D0F0_R_IOEDEBUGPAD_EN, 0);		
		
		// Non-Sus(CorePowerOff)
		//
		AsiaMemoryModify8(MmioBar + MMIO_ISB_OFFSET + 0xCE, BIT1, 0);	

		//Special case: for EHCI, we must make sure that D16F7 Rx4D[7],
		// if disable debugsignal selection, need to set it to 0 to save power
		AsiaPciModify8(AsiaPciAddress(BUSXP3, 16, 7, 0x4D), BIT7, 0);
	}else if(NbCfg->Cnd003DebugFromCpu == 1){ //MMIO CPU
		//Set Pin->DebugSignal from Setup Menu
		if((NbCfg->IoeChipRevision) == IOE_REVISION_A0){
		  AsiaMemoryModify16(MmioBar + MMIO_ISB_OFFSET + CND003_MMIO_D0F0_VCORE_PAD_SETTING, BIT4, (Cnd003DbgPadG0En == 1)?BIT4:0);
			}
		else//IOE AI patch,Debug signal select-GPIO change to ISB Rx51[2]
			{
		  AsiaMemoryModify16(MmioBar + MMIO_ISB_OFFSET + CND003_MMIO_D0F0_CKGSRC_SETTING_GRP_1, BIT2, (Cnd003DbgPadG0En == 1)?BIT2:0);
			}
		AsiaMemoryModify16(MmioBar + MMIO_ISB_OFFSET + 0x7C, BIT9, (Cnd003DbgPadG1En == 1)?BIT9:0);
		AsiaMemoryModify16(MmioBar + MMIO_ISB_OFFSET + 0x7C, BIT8, (Cnd003DbgPadG2En == 1)?BIT8:0);
		AsiaMemoryModify16(MmioBar + MMIO_ISB_OFFSET + 0x7C, BIT11, (Cnd003DbgPadG3En == 1)?BIT11:0);	

		//Special case: for EHCI, we must make sure that D16F7 Rx4D[7],
		// if disable debugsignal selection, need to set it to 0 to save power
		//AsiaPciModify8(AsiaPciAddress(BUSXP3, 16, 7, 0x4D), BIT7, BIT7);//ALJ20161031 remove 	
	}else if(NbCfg->Cnd003DebugFromCpu == 2){ //SMBus
	
		//Set Pin->DebugSignal from Setup Menu
		if((NbCfg->IoeChipRevision) == IOE_REVISION_A0){
		  AsiaMemoryModify16(MmioBar + MMIO_ISB_OFFSET + CND003_MMIO_D0F0_VCORE_PAD_SETTING, BIT4, (Cnd003DbgPadG0En == 1)?BIT4:0);
			}
		else//IOE AI patch,Debug signal select-GPIO change to ISB Rx51[2]
			{
		  AsiaMemoryModify16(MmioBar + MMIO_ISB_OFFSET + CND003_MMIO_D0F0_CKGSRC_SETTING_GRP_1, BIT2, (Cnd003DbgPadG0En == 1)?BIT2:0);
			}
		AsiaMemoryModify16(MmioBar + MMIO_ISB_OFFSET + 0x7C, BIT9, (Cnd003DbgPadG1En == 1)?BIT9:0);
		AsiaMemoryModify16(MmioBar + MMIO_ISB_OFFSET + 0x7C, BIT8, (Cnd003DbgPadG2En == 1)?BIT8:0);
		AsiaMemoryModify16(MmioBar + MMIO_ISB_OFFSET + 0x7C, BIT11, (Cnd003DbgPadG3En == 1)?BIT11:0);	

		//Special case: for EHCI, we must make sure that D16F7 Rx4D[7],
		// if disable debugsignal selection, need to set it to 0 to save power
		//AsiaPciModify8(AsiaPciAddress(BUSXP3, 16, 7, 0x4D), BIT7, BIT7);//ALJ20161031 remove		
	}else{
		;
	}



	return Status;

}

#elif IOE_PRE_INIT_LOCATION == IOE_ASIA_PEI_NB


/**
	This routine is for CND003 DebugSignal Group selection
	the debug signal group/module will be read from SetupMenu
	this routine should be called in NbPcie.c 
**/
	/**
	   SATA PEI Init function.
	   Called by SataInitPei()
	   
	  @param  PeiServices	EFI_PEI_SERVICES pointer.
	  @param SbCfg point to ASIA_SB_CONFIGURATION struct
	
	  @return VOID.
	
	**/

EFI_STATUS
IoeDebugSignalSel(
	IN EFI_PEI_SERVICES **PeiServices,
	ASIA_NB_CONFIGURATION *NbCfg)
{
	//TODO: sad
	EFI_GUID SMBusGUID = PEI_SMBUS_PPI_GUID;
	PEI_SMBUS_PPI *pSMBusPPI;
	EFI_STATUS Status = EFI_SUCCESS;
	UINT32 MmioBar;


	UINT8 ModuleG0,ModuleG1;
	UINT16 Group0,Group1,Group2,Group3;
    UINT16 Group0_XHCI,Group1_XHCI,Group2_XHCI,Group3_XHCI;
	UINT8 SuspendModule;
	UINT8 HighSpeedEnable,HighSpeedModuleGx;
	UINT16 HighSpeedGx;
	UINT8 CorePowerOff;
	UINT8 Cnd003DbgPadG0En,Cnd003DbgPadG1En,Cnd003DbgPadG2En,Cnd003DbgPadG3En;
	UINT8 vc,ix;


	if(NbCfg->Cnd003DebugFromCpu == 0){
		PEI_DEBUG((PeiServices,EFI_D_ERROR,"[CJW_IOE] IoeDebugSignalSel() Exist Directly!\n"));
		return EFI_SUCCESS;
	}

		
	//Get SMBUS operator :
	Status = (*PeiServices)->LocatePpi(PeiServices, &SMBusGUID, 0, NULL, &pSMBusPPI);
	ASSERT_PEI_ERROR (PeiServices, Status);	

	

	MmioBar = AsiaPciRead32(AsiaPciAddress(BUSX, UPPORT_DEV, UPPORT_FUN, 0x10));


	//
	// Step 0: Setting the DebugSignal selection source 
	//
	if(NbCfg->Cnd003DebugFromCpu == 0){  //disable-SPI
		AsiaMemoryModify8(MmioBar + MMIO_ISB_OFFSET + CND003_MMIO_D0F0_STRAPPING_PIN_READ_BACK_REG_GRP_2, CND003_MMIO_D0F0_RSPIHDR_DBGCTLSEL, BIT0);
		PEI_DEBUG((PeiServices,EFI_D_ERROR,"[CJW_IOE] DBG source: Disable/SPI\n"));
	}else if(NbCfg->Cnd003DebugFromCpu == 1){ //MMIO CPU
		AsiaMemoryModify8(MmioBar + MMIO_ISB_OFFSET + CND003_MMIO_D0F0_STRAPPING_PIN_READ_BACK_REG_GRP_2, CND003_MMIO_D0F0_RSPIHDR_DBGCTLSEL, BIT1);
		PEI_DEBUG((PeiServices,EFI_D_ERROR,"[CJW_IOE] DBG source: MMIO\n"));
	}else if(NbCfg->Cnd003DebugFromCpu == 2){ //SMBus
		AsiaMemoryModify8(MmioBar + MMIO_ISB_OFFSET + CND003_MMIO_D0F0_STRAPPING_PIN_READ_BACK_REG_GRP_2, CND003_MMIO_D0F0_RSPIHDR_DBGCTLSEL, 0);
		PEI_DEBUG((PeiServices,EFI_D_ERROR,"[CJW_IOE] DBG source: SMBus\n"));
	}else{
		PEI_DEBUG((PeiServices,EFI_D_ERROR,"[CJW_IOE] DBG source: unknown\n"));
	}



	//Get the setting from Setup Menu
	ModuleG0 = (UINT8)(NbCfg->Cnd003ModuleG0);
	ModuleG1 = (UINT8)(NbCfg->Cnd003ModuleG1);
	Group0 = (UINT16)(NbCfg->Cnd003DebugG0);
	Group1 = (UINT16)(NbCfg->Cnd003DebugG1);
	Group2 = (UINT16)(NbCfg->Cnd003DebugG2);
	Group3 = (UINT16)(NbCfg->Cnd003DebugG3);
    Group0_XHCI = (UINT16)(NbCfg->Cnd003DebugG0_XHCI);
	Group1_XHCI = (UINT16)(NbCfg->Cnd003DebugG1_XHCI);
	Group2_XHCI = (UINT16)(NbCfg->Cnd003DebugG2_XHCI);
	Group3_XHCI = (UINT16)(NbCfg->Cnd003DebugG3_XHCI);
	SuspendModule = (UINT8)(NbCfg->Cnd003DebugSuspend);
	HighSpeedEnable = (UINT8)(NbCfg->Cnd003HighSpeed);
	HighSpeedModuleGx = (UINT8)(NbCfg->Cnd003HighSpeedModuleSel);
	HighSpeedGx = (UINT16)(NbCfg->Cnd003HighSpeedDbgSel);
	CorePowerOff = (UINT8)(NbCfg->Cnd003CorePowerOff);
	Cnd003DbgPadG0En = (UINT8)(NbCfg->Cnd003DbgPadG0En);
	Cnd003DbgPadG1En = (UINT8)(NbCfg->Cnd003DbgPadG1En);
	Cnd003DbgPadG2En = (UINT8)(NbCfg->Cnd003DbgPadG2En);
	Cnd003DbgPadG3En = (UINT8)(NbCfg->Cnd003DbgPadG3En);
			
	//
	PEI_DEBUG((PeiServices, EFI_D_ERROR, "[CJW_IOE_DEBUG_SIGNAL] Select From Cpu [On]\n"));
	PEI_DEBUG((PeiServices, EFI_D_ERROR, "[CJW_IOE_DEBUG_SIGNAL] ModuleG0[0x%02x]\n",ModuleG0));
	PEI_DEBUG((PeiServices, EFI_D_ERROR, "[CJW_IOE_DEBUG_SIGNAL] ModuleG1[0x%02x]\n",ModuleG1));
	PEI_DEBUG((PeiServices, EFI_D_ERROR, "[CJW_IOE_DEBUG_SIGNAL] G0[0x%04x]\n",Group0));
	PEI_DEBUG((PeiServices, EFI_D_ERROR, "[CJW_IOE_DEBUG_SIGNAL] G1[0x%04x]\n",Group1));
	PEI_DEBUG((PeiServices, EFI_D_ERROR, "[CJW_IOE_DEBUG_SIGNAL] G2[0x%04x]\n",Group2));
	PEI_DEBUG((PeiServices, EFI_D_ERROR, "[CJW_IOE_DEBUG_SIGNAL] G3[0x%04x]\n",Group3));
	PEI_DEBUG((PeiServices, EFI_D_ERROR, "[CJW_IOE_DEBUG_SIGNAL] SuspendModule[0x%02x]\n",SuspendModule));
	PEI_DEBUG((PeiServices, EFI_D_ERROR, "[CJW_IOE_DEBUG_SIGNAL] HighSpeedEnable[0x%02x]\n",HighSpeedEnable));
	PEI_DEBUG((PeiServices, EFI_D_ERROR, "[CJW_IOE_DEBUG_SIGNAL] HighSpeedModuleGx[0x%02x]\n",HighSpeedModuleGx));
	PEI_DEBUG((PeiServices, EFI_D_ERROR, "[CJW_IOE_DEBUG_SIGNAL] HighSpeedGx[0x%04x]\n",HighSpeedGx));
	PEI_DEBUG((PeiServices, EFI_D_ERROR, "[CJW_IOE_DEBUG_SIGNAL] CorePowerOff[0x%02x]\n",CorePowerOff));



	//
	//3 Case 1: [Disable]
	//	
	if(NbCfg->Cnd003DebugFromCpu == 0){

		PEI_DEBUG((PeiServices, EFI_D_ERROR, "[CJW_IOE] Debug Signal Selection [Disable] -> From SPI header(Only for SPI mode)\n"));	
		//IoePeiClearTempAssignment(PeiServices);
		//return Status;
	}


	//
	//3 Case 2: [From MMIO_ISB]
	//	
	else if(NbCfg->Cnd003DebugFromCpu == 1){

		PEI_DEBUG((PeiServices, EFI_D_ERROR, "[CJW_IOE] Debug Signal Selection [From MMIO_ISB]\n"));


		//set MMIO_ISB Rx36[1:0]  - select from CPU
		AsiaMemoryModify8(MmioBar + MMIO_ISB_OFFSET + CND003_MMIO_D0F0_STRAPPING_PIN_READ_BACK_REG_GRP_2, CND003_MMIO_D0F0_RSPIHDR_DBGCTLSEL, BIT1);
//ALJ201712128,remove issue code ,s3 will have problem with these setting
#if 0

		//
		//4 Step 2.1 Clear Pin Setting & Clear HS/SUS
		//
		// Non-HighSpeed
		// R_IOEDEBUGPAD_EN (For Silicon) -> Disable Pin
		AsiaMemoryModify8(MmioBar + MMIO_ISB_OFFSET + CND003_MMIO_D0F0_VCORE_PAD_SETTING, CND003_MMIO_D0F0_R_IOEDEBUGPAD_EN, 0);		
		
		// Non-Sus(CorePowerOff)
		//
		AsiaMemoryModify8(MmioBar + MMIO_ISB_OFFSET + 0xCE, BIT1, 0);

		// Normal
		AsiaMemoryModify16(MmioBar+MMIO_ISB_OFFSET+0x7C, BIT11, 0);		//RGMII pin <- DebugSignal[44:32]
		if((NbCfg->IoeChipRevision) == IOE_REVISION_A0){
		AsiaMemoryModify16(MmioBar+MMIO_ISB_OFFSET+CND003_MMIO_D0F0_VCORE_PAD_SETTING, BIT4, 0); 		//GPIO pin <- DebugSignal[15:0]
			}
		else//IOE AI patch,Debug signal select-GPIO change to ISB Rx51[2]
			{
        AsiaMemoryModify16(MmioBar+MMIO_ISB_OFFSET+CND003_MMIO_D0F0_CKGSRC_SETTING_GRP_1, BIT2, 0); 		//GPIO pin <- DebugSignal[15:0]
		}
		AsiaMemoryModify16(MmioBar+MMIO_ISB_OFFSET+0x7C, BIT9|BIT8, 0); //USBoc io & CCPHY io <- DebugSignal[31:16]		

		// MemRd cycle for debug - catc capture
		AsiaMemoryRead32(MmioBar+MMIO_ISB_OFFSET+0xFF);
		AsiaMemoryRead32(MmioBar+MMIO_ISB_OFFSET+0xFF);
		AsiaMemoryRead32(MmioBar+MMIO_ISB_OFFSET+0xFF);
		AsiaMemoryRead32(MmioBar+MMIO_ISB_OFFSET+0xFF);
#endif
		//
		//4 Step 2.2 Case: HighSpeed
		//
		if(HighSpeedEnable == 1){
			//RDBG_HIGH_MODULE_SEL
			AsiaMemoryModify32(MmioBar + MMIO_ISB_OFFSET + CND003_MMIO_D0F0_DEBUG_SEL_SETTING_2, CND003_MMIO_D0F0_RDBG_HIGH_MODULE_SEL, HighSpeedModuleGx<<24);
			//RDBG_HIGH_SEL
			AsiaMemoryModify32(MmioBar + MMIO_ISB_OFFSET + CND003_MMIO_D0F0_DEBUG_SEL_SETTING_3, CND003_MMIO_D0F0_RDBG_HIGH_SEL, HighSpeedGx);

			//R_IOEDEBUGPAD_EN (For Silicon) -> Enable Pin
			if((NbCfg->IoeChipRevision) == IOE_REVISION_A0){
			AsiaMemoryModify8(MmioBar + MMIO_ISB_OFFSET + CND003_MMIO_D0F0_VCORE_PAD_SETTING, BIT7, BIT7);
				}
            else//IOE AI patch,R_IOEDEBUGPAD_EN change to ISB Rx51[3]
			{
            AsiaMemoryModify16(MmioBar+MMIO_ISB_OFFSET+CND003_MMIO_D0F0_CKGSRC_SETTING_GRP_1, BIT3, BIT3);
		    }
			//return EFI_SUCCESS;
		}

		//
		//4 Step 2.3 Case: Suspend - CorePowerOff
		//
		if(CorePowerOff == 1){
			AsiaMemoryModify8(MmioBar + MMIO_ISB_OFFSET + 0xCE, BIT1, BIT1);
			
			//SUS Module Select
			AsiaMemoryWrite8(MmioBar+MMIO_ISB_OFFSET+0xCA, SuspendModule);

			AsiaMemoryWrite16(MmioBar+MMIO_ISB_OFFSET+0xC2, Group1);			//only group1 can be used

			//AsiaMemoryModify16(MmioBar+MMIO_ISB_OFFSET+0x7C, BIT9|BIT8, BIT9|BIT8); //USBoc io & CCPHY io -> DebugSignal[31:16]
			//AsiaMemoryModify16(MmioBar+MMIO_ISB_OFFSET+0x7C, BIT11, BIT11);			//RGMII pin -> DBG[31]

			// Need set Rx7C[8][9][11] to enable dbg output
			goto _exitdbg;
			//return EFI_SUCCESS;
		}

		//
		//4 Step 2.4 Case: [Suspend - CorePowerOn] or [Normal Case] 
		//
		if((ModuleG0 == 0xA)||(ModuleG1 == 0xA)){ 
			// Suspend(core power on) special
			
			PEI_DEBUG((PeiServices, EFI_D_ERROR, "[CJW_IOE_DEBUG_SIGNAL] ISB_SUS\n"));	
			//Module Select
			AsiaMemoryWrite8(MmioBar + MMIO_ISB_OFFSET + 0xC8, ModuleG0);
			AsiaMemoryWrite8(MmioBar + MMIO_ISB_OFFSET + 0xC9, ModuleG1);

			//SUS Module Select
			AsiaMemoryWrite8(MmioBar+MMIO_ISB_OFFSET+0xCA, SuspendModule);
		}
        //
        //Step 2.5 Case: XHCI Module Select 
        //
        //if((ModuleG0 == 0xD)||(ModuleG1 == 0xD)){
        //    AsiaPciModify8((CND003_XHCI | 0x43),	  0x01,  0x01); // Enable Access
		//    AsiaPciModify32((CND003_XHCI | 0x78), 0xFFFFF, 0x54);
		//    AsiaPciModify32((CND003_XHCI | 0x7C), 0xFFFF0000, (Group0_XHCI<<16|Group1_XHCI<<20|Group2_XHCI<<24|Group3_XHCI<<28));    
		//    AsiaPciModify8((CND003_XHCI | 0x43),	  0x01,  0x00); // Disable Access
        // }
								
		//Module Select
		AsiaMemoryWrite8(MmioBar+MMIO_ISB_OFFSET+0xC8, ModuleG0);
		AsiaMemoryWrite8(MmioBar+MMIO_ISB_OFFSET+0xC9, ModuleG1);
					
		//G select
		AsiaMemoryWrite16(MmioBar+MMIO_ISB_OFFSET+0xC0, Group0);	
		AsiaMemoryWrite16(MmioBar+MMIO_ISB_OFFSET+0xC2, Group1);	
		AsiaMemoryWrite16(MmioBar+MMIO_ISB_OFFSET+0xC4, Group2);	
		AsiaMemoryWrite16(MmioBar+MMIO_ISB_OFFSET+0xC6, Group3);	

		//Pin Mux - Select for DebugSignal
		//AsiaMemoryModify16(MmioBar+MMIO_ISB_OFFSET+0x7C, BIT11, BIT11);	//RGMII pin -> DebugSignal[44:32]
		//AsiaMemoryModify16(MmioBar+MMIO_ISB_OFFSET+0x10, BIT4, BIT4); //GPIO pin -> DebugSignal[15:0]
		//AsiaMemoryModify16(MmioBar+MMIO_ISB_OFFSET+0x7C, BIT9|BIT8, BIT9|BIT8); //USBoc io & CCPHY io -> DebugSignal[31:16]


		// MemRd cycle for debug - catc capture
		AsiaMemoryRead32(MmioBar+MMIO_ISB_OFFSET+0xF0);
		AsiaMemoryRead32(MmioBar+MMIO_ISB_OFFSET+0xF0);
		AsiaMemoryRead32(MmioBar+MMIO_ISB_OFFSET+0xF0);
		AsiaMemoryRead32(MmioBar+MMIO_ISB_OFFSET+0xF0);

		goto _exitdbg;
	}

	//
	//3 Case 1.3:[From SMBus]
	//
	else if(NbCfg->Cnd003DebugFromCpu == 2){
		PEI_DEBUG((PeiServices, EFI_D_ERROR, "[CJW_IOE] Debug Signal Selection [From SMBus]\n"));
		
		//set MMIO_ISB Rx36[1:0]  - select from SMBus
		// --Need PEEP link up
		AsiaMemoryModify8(MmioBar + MMIO_ISB_OFFSET + CND003_MMIO_D0F0_STRAPPING_PIN_READ_BACK_REG_GRP_2, CND003_MMIO_D0F0_RSPIHDR_DBGCTLSEL, 0);


		//
		//4 Step 3.1: HighSpeed
		//
		if(NbCfg->Cnd003HighSpeed){
			// TODO: Question - Can not set pin mux - still need to set by MMIO? If so, when PCIE upstream port link not ready, this will not work?
			
			//HIGH_MODULE_SEL  0E[3:0] = G0
			IoeSmbusWrite((EFI_PEI_SERVICES **)PeiServices, 0x0E, HighSpeedModuleGx);
			//RDBG_HIGH_SEL
			IoeSmbusWrite((EFI_PEI_SERVICES **)PeiServices, 0x0C, HighSpeedGx&0xFF);
			IoeSmbusWrite((EFI_PEI_SERVICES **)PeiServices, 0x0D, (HighSpeedGx>>8)&0xF);

		//
		//4 Step 3.2: Suspend
		//
		}else if((ModuleG0 == 0xA)||(ModuleG1 == 0xA)){
			//Module sel -- ISB_SUS 
			IoeSmbusWrite((EFI_PEI_SERVICES **)PeiServices, 0x0A, 0xFF&(((ModuleG1&0xF)<<4)|(ModuleG0&0xF)));//all sel Sus

			//SMB_DBG_SUS_MODULE_SEL
			IoeSmbusWrite((EFI_PEI_SERVICES **)PeiServices, 0x0B, 0xF&SuspendModule);
				
			//SMB_DBG_SEL_G0 ~ SMB_DBG_SEL_G3  
			//IoeSmbusWrite((EFI_PEI_SERVICES **)PeiServices, 0x02, 0xFF&Group0);
			//IoeSmbusWrite((EFI_PEI_SERVICES **)PeiServices, 0x03, 0xF&(Group0>>8));
			//IoeSmbusWrite((EFI_PEI_SERVICES **)PeiServices, 0x04, 0xFF&Group1);
			//IoeSmbusWrite((EFI_PEI_SERVICES **)PeiServices, 0x05, 0xF&(Group1>>8));
			//IoeSmbusWrite((EFI_PEI_SERVICES **)PeiServices, 0x06, 0xFF&Group2);
			//IoeSmbusWrite((EFI_PEI_SERVICES **)PeiServices, 0x07, 0xF&(Group2>>8));
			//IoeSmbusWrite((EFI_PEI_SERVICES **)PeiServices, 0x08, 0xFF&Group3);
			//IoeSmbusWrite((EFI_PEI_SERVICES **)PeiServices, 0x09, 0xF&(Group3>>8));

			//Sus En
			//Not found in SMBus internal registers	
			// TODO: There was not found Sus En register in SMBus internal register, so how can we set it? or we can't use this from SMBus?
		}

		//
		//4 Step 3.3: Normal
		//
		// TODO: Currently, "Normal" path is the only one to work correctly...
		
		//[1]
		//SMB_DBGINGPIOGRP_EN = 1 (Not implemented on HAPS)
		//IoeSmbusModify((EFI_PEI_SERVICES **)PeiServices, 0x0F, BIT3, BIT3);
				
		//[2]
		//SMB_DBG_MODULE_SEL_G1 = 0100b --> for MCU
		//SMB_DBG_MODULE_SEL_G0 = 0100b	--> for MCU
		/* SMB_DBG_MODULE_SEL_G1/G0
		0h: clock counter
		1h: PCIEIF
		2h: EPTRFC
		3h: ISB_BUSXD0F0_CORE
		4h: DBGMCU
		5h: SATA
		6h: USBC_CORE_D14
		7h: USBC_CORE_D16
		8h: GNIC
		9h: TOP
		Ah: ISB_SUS
		Bh: INTMAP
		Ch: DBGCAP
		Dh: XHCI
		Eh: PCIE
		*/
		IoeSmbusWrite((EFI_PEI_SERVICES **)PeiServices, 0x0A, (0xF0&(ModuleG1<<4))|(ModuleG0&0xF));

		//[3] 
		//SMB_DBG_SEL_G0 ~ SMB_DBG_SEL_G3  
		IoeSmbusWrite((EFI_PEI_SERVICES **)PeiServices, 0x02, 0xFF&Group0);
		IoeSmbusWrite((EFI_PEI_SERVICES **)PeiServices, 0x03, 0xF&(Group0>>8));
		IoeSmbusWrite((EFI_PEI_SERVICES **)PeiServices, 0x04, 0xFF&Group1);
		IoeSmbusWrite((EFI_PEI_SERVICES **)PeiServices, 0x05, 0xF&(Group1>>8));
		IoeSmbusWrite((EFI_PEI_SERVICES **)PeiServices, 0x06, 0xFF&Group2);
		IoeSmbusWrite((EFI_PEI_SERVICES **)PeiServices, 0x07, 0xF&(Group2>>8));
		IoeSmbusWrite((EFI_PEI_SERVICES **)PeiServices, 0x08, 0xFF&Group3);
		IoeSmbusWrite((EFI_PEI_SERVICES **)PeiServices, 0x09, 0xF&(Group3>>8));

		//[4]
		//Dump SMBus register setting
		PEI_DEBUG((PeiServices,EFI_D_ERROR, "[CJW_SMBus]  Dump SMBus register setting \n"));
		for(ix = 0; ix<0x10; ix++){
			IoeSmbusRead((EFI_PEI_SERVICES **)PeiServices, ix, &vc);
			PEI_DEBUG((PeiServices,EFI_D_ERROR, "[CJW_SMBus]  Rx%02X = 0x%02X \n",ix,vc));
		}


	}
	//
	// Case 4: Unknown path
	//
	else{
		PEI_DEBUG((PeiServices, EFI_D_ERROR, "[CJW_IOE] Debug Signal Selection [Unknown path]\n"));
	}



_exitdbg:
	//
	// DebugSingal PAD configure
	//
	if(NbCfg->Cnd003DebugFromCpu == 0){  //disable-SPI
		//Disable Normal Pin used for DebugSignal
		if((NbCfg->IoeChipRevision) == IOE_REVISION_A0){
		AsiaMemoryModify16(MmioBar + MMIO_ISB_OFFSET + CND003_MMIO_D0F0_VCORE_PAD_SETTING, BIT4, 0);
			}
		 else//IOE AI patch,Debug signal select-GPIO change to ISB Rx51[2]
			{
        AsiaMemoryModify16(MmioBar+MMIO_ISB_OFFSET+CND003_MMIO_D0F0_CKGSRC_SETTING_GRP_1, BIT2, 0);
			}
		AsiaMemoryModify16(MmioBar + MMIO_ISB_OFFSET + 0x7C, BIT9, 0);
		AsiaMemoryModify16(MmioBar + MMIO_ISB_OFFSET + 0x7C, BIT8, 0);
		AsiaMemoryModify16(MmioBar + MMIO_ISB_OFFSET + 0x7C, BIT11, 0);	

		//
		// Non-HighSpeed
		// R_IOEDEBUGPAD_EN (For Silicon) -> Disable Pin
		if((NbCfg->IoeChipRevision) == IOE_REVISION_A0){
		AsiaMemoryModify8(MmioBar + MMIO_ISB_OFFSET + CND003_MMIO_D0F0_VCORE_PAD_SETTING, CND003_MMIO_D0F0_R_IOEDEBUGPAD_EN, 0);		
			}
		else
			{
		AsiaMemoryModify16(MmioBar+MMIO_ISB_OFFSET+CND003_MMIO_D0F0_CKGSRC_SETTING_GRP_1, BIT3, 0);
			}
		// Non-Sus(CorePowerOff)
		//
		AsiaMemoryModify8(MmioBar + MMIO_ISB_OFFSET + 0xCE, BIT1, 0);	

		//Special case: for EHCI, we must make sure that D16F7 Rx4D[7],
		// if disable debugsignal selection, need to set it to 0 to save power
		AsiaPciModify8(AsiaPciAddress(BUSXP3, 16, 7, 0x4D), BIT7, 0);
	}else if(NbCfg->Cnd003DebugFromCpu == 1){ //MMIO CPU
		//Set Pin->DebugSignal from Setup Menu
		if((NbCfg->IoeChipRevision) == IOE_REVISION_A0){
		  AsiaMemoryModify16(MmioBar + MMIO_ISB_OFFSET + CND003_MMIO_D0F0_VCORE_PAD_SETTING, BIT4, (Cnd003DbgPadG0En == 1)?BIT4:0);
			}
		else//IOE AI patch,Debug signal select-GPIO change to ISB Rx51[2]
			{
		  AsiaMemoryModify16(MmioBar + MMIO_ISB_OFFSET + CND003_MMIO_D0F0_CKGSRC_SETTING_GRP_1, BIT2, (Cnd003DbgPadG0En == 1)?BIT2:0);
			}
		AsiaMemoryModify16(MmioBar + MMIO_ISB_OFFSET + 0x7C, BIT9, (Cnd003DbgPadG1En == 1)?BIT9:0);
		AsiaMemoryModify16(MmioBar + MMIO_ISB_OFFSET + 0x7C, BIT8, (Cnd003DbgPadG2En == 1)?BIT8:0);
		AsiaMemoryModify16(MmioBar + MMIO_ISB_OFFSET + 0x7C, BIT11, (Cnd003DbgPadG3En == 1)?BIT11:0);	

		//Special case: for EHCI, we must make sure that D16F7 Rx4D[7],
		// if disable debugsignal selection, need to set it to 0 to save power
		//AsiaPciModify8(AsiaPciAddress(BUSXP3, 16, 7, 0x4D), BIT7, BIT7);//ALJ20161031 remove 	
	}else if(NbCfg->Cnd003DebugFromCpu == 2){ //SMBus
	
		//Set Pin->DebugSignal from Setup Menu
		if((NbCfg->IoeChipRevision) == IOE_REVISION_A0){
		  AsiaMemoryModify16(MmioBar + MMIO_ISB_OFFSET + CND003_MMIO_D0F0_VCORE_PAD_SETTING, BIT4, (Cnd003DbgPadG0En == 1)?BIT4:0);
			}
		else//IOE AI patch,Debug signal select-GPIO change to ISB Rx51[2]
			{
		  AsiaMemoryModify16(MmioBar + MMIO_ISB_OFFSET + CND003_MMIO_D0F0_CKGSRC_SETTING_GRP_1, BIT2, (Cnd003DbgPadG0En == 1)?BIT2:0);
			}
		AsiaMemoryModify16(MmioBar + MMIO_ISB_OFFSET + 0x7C, BIT9, (Cnd003DbgPadG1En == 1)?BIT9:0);
		AsiaMemoryModify16(MmioBar + MMIO_ISB_OFFSET + 0x7C, BIT8, (Cnd003DbgPadG2En == 1)?BIT8:0);
		AsiaMemoryModify16(MmioBar + MMIO_ISB_OFFSET + 0x7C, BIT11, (Cnd003DbgPadG3En == 1)?BIT11:0);	

		//Special case: for EHCI, we must make sure that D16F7 Rx4D[7],
		// if disable debugsignal selection, need to set it to 0 to save power
		//AsiaPciModify8(AsiaPciAddress(BUSXP3, 16, 7, 0x4D), BIT7, BIT7);//ALJ20161031 remove		
	}else{
		;
	}



	return Status;

}


/*
	we can't set XHCI cfg space before PHY CFGDONE
	we can access it only after XHCI Phy ready
*/

/**
   SATA PEI Init function.
   Called by SataInitPei()
   
  @param  PeiServices	EFI_PEI_SERVICES pointer.
  @param SbCfg point to ASIA_SB_CONFIGURATION struct

  @return VOID.

**/

EFI_STATUS
IoeDebugSignalSelPostCfgDone(	
	IN EFI_PEI_SERVICES **PeiServices,
	ASIA_NB_CONFIGURATION *NbCfg)
{
	//TODO: sad
	//EFI_GUID SMBusGUID = PEI_SMBUS_PPI_GUID;
	//PEI_SMBUS_PPI *pSMBusPPI;
	//EFI_STATUS Status = EFI_SUCCESS;
	//UINT32 MmioBar;


	UINT8 ModuleG0,ModuleG1;
	//UINT16 Group0,Group1,Group2,Group3;
    UINT16 Group0_XHCI,Group1_XHCI,Group2_XHCI,Group3_XHCI;
	UINT8 SuspendModule;
	//UINT8 HighSpeedEnable,HighSpeedModuleGx;
	//UINT16 HighSpeedGx;
	//UINT8 CorePowerOff;
	//UINT8 Cnd003DbgPadG0En,Cnd003DbgPadG1En,Cnd003DbgPadG2En,Cnd003DbgPadG3En;
	//UINT8 vc,ix;

		
	//Get SMBUS operator :
	//Status = (*PeiServices)->LocatePpi(PeiServices, &SMBusGUID, 0, NULL, &pSMBusPPI);
	//ASSERT_PEI_ERROR (PeiServices, Status);	

	//MmioBar = AsiaPciRead32(AsiaPciAddress(BUSX, UPPORT_DEV, UPPORT_FUN, 0x10));

	//Get the setting from Setup Menu
	ModuleG0 = (UINT8)(NbCfg->Cnd003ModuleG0);
	ModuleG1 = (UINT8)(NbCfg->Cnd003ModuleG1);
	//Group0 = (UINT16)(NbCfg->Cnd003DebugG0);
	//Group1 = (UINT16)(NbCfg->Cnd003DebugG1);
	//Group2 = (UINT16)(NbCfg->Cnd003DebugG2);
	//Group3 = (UINT16)(NbCfg->Cnd003DebugG3);
    Group0_XHCI = (UINT16)(NbCfg->Cnd003DebugG0_XHCI);
	Group1_XHCI = (UINT16)(NbCfg->Cnd003DebugG1_XHCI);
	Group2_XHCI = (UINT16)(NbCfg->Cnd003DebugG2_XHCI);
	Group3_XHCI = (UINT16)(NbCfg->Cnd003DebugG3_XHCI);
	SuspendModule = (UINT8)(NbCfg->Cnd003DebugSuspend);
	//HighSpeedEnable = (UINT8)(NbCfg->Cnd003HighSpeed);
	//HighSpeedModuleGx = (UINT8)(NbCfg->Cnd003HighSpeedModuleSel);
	//HighSpeedGx = (UINT16)(NbCfg->Cnd003HighSpeedDbgSel);
	//CorePowerOff = (UINT8)(NbCfg->Cnd003CorePowerOff);

			
	//
	//3 Case 2: [From MMIO_ISB]
	//	
 	if(NbCfg->Cnd003DebugFromCpu == 1){
		
        //
        //Step 2.5 Case: XHCI Module Select 
        //
        if((ModuleG0 == 0xD)||(ModuleG1 == 0xD) ||(SuspendModule == 0xC)){
		    AsiaPciModify32((CND003_XHCI | 0x54), 0xFFFF0000, (Group0_XHCI<<16|Group1_XHCI<<20|Group2_XHCI<<24|Group3_XHCI<<28));    
         }

		goto _exitdbg;
	}

_exitdbg:
	return EFI_SUCCESS;
	
}



#endif






/**************************************************************************
// Code for DBGCAP
**************************************************************************/
/*

DBGCAP function[Disable/SBDBG Path/DebugSignalCap Path]
	--Disable
		(nothing)
	--SBDBG Path
		--Module Select [SATA/EHCI/XHCI...]
		--Cycle Direction[Upstream RW/Downstream R/Downstream W]
		--Request[Enable/Disable]
			If Enable --> data patten[xxxxxxxh]/request patten[xxxxxh]......
		--Data[Enable/Disable]
			If Enable --> data patten[xxxxxxxh]/request patten[xxxxxh]......
		...
		...
		...
	--DebugSignalCap Path
		Group Sel[xxxb] ->3'bxxx
		Module Sel
	
*/
#define IOE_DCBASE 0x30
#define IOE_DCBASE_EPTRFC 0xC0

/**
   SATA PEI Init function.
   Called by SataInitPei()
   
  @param  PeiServices	EFI_PEI_SERVICES pointer.
  @param SbCfg point to ASIA_SB_CONFIGURATION struct

  @return EFI_STATUS.

**/

EFI_STATUS
IoeDbgCapSetup(
	IN EFI_PEI_SERVICES **PeiServices, 
	ASIA_NB_CONFIGURATION *NbCfg)
{

	UINT64 PcieBase;

	UINT64 PciePort = CND003_PEA0;
	UINT8 DCdestid = 0;
	UINT32 MmioBar;
	
	EFI_GUID SMBusGUID = PEI_SMBUS_PPI_GUID;
	PEI_SMBUS_PPI *pSMBusPPI;
	EFI_STATUS Status;

	//Get SMBUS operator :
	Status = (*PeiServices)->LocatePpi(PeiServices, &SMBusGUID, 0, NULL, &pSMBusPPI);
	ASSERT_PEI_ERROR (PeiServices, Status);	

	
	if(NbCfg->Cnd003DC == 0){
		IoeSmbusModify8(PeiServices, IOE_DCBASE + 3, BIT7, 0); 
		return EFI_SUCCESS;
	}

	Status = IoePeiTempAssignment(PeiServices);
	if(Status != EFI_SUCCESS){
		PEI_DEBUG((PeiServices,EFI_D_ERROR,"[CJW_IOE] IoeDbgCapSetup() Not Found IOE!\n"));
		return Status;
	}else{
		PEI_DEBUG((PeiServices,EFI_D_ERROR,"[CJW_IOE] IoeDbgCapSetup() Found IOE!\n"));
	}	

	PcieBase = NbCfg->PcieBar;  
	MmioBar = AsiaPciRead32(AsiaPciAddress(BUSX, UPPORT_DEV, UPPORT_FUN, 0x10))&0xFFFFFFFC;
	
	//
	// Select port
	//
	switch(NbCfg->Cnd003DCOutput){
		case 1:
			PciePort = CND003_PEA0;
			DCdestid = 1;
			break;
		case 2:
			PciePort = CND003_PEA1;
			DCdestid = 2;
			break;
		case 3: 
			PciePort = CND003_PEA2;
			DCdestid = 3;
			break;
		case 4:
			PciePort = CND003_PEA3;
			DCdestid = 4;
			break;
		case 5:
			PciePort = CND003_PEA4;
			DCdestid = 5;
			break;
		case 6:
			PciePort = CND003_PEB0;
			DCdestid = 9;
			break;
		case 7:
			PciePort = CND003_PEB1;
			DCdestid = 0xA;
			break;
		default:
			PciePort = CND003_PEA0;
			DCdestid = 1;
			break;
	}

	// TODO: the sequences in step 1 should implemented by SMBus DebugPath - or , DBGCAP can only be set by EPTRFC.
	//2 Step 1. PCIE setting
	//4 1.a  
	//Rx50[1:0] PEXC.LCAPMS_PEA0[1:0] = 2'b0
	AsiaPcieModify8(PcieBase, PciePort|((UINT64)CND003_BUSXP1_D1D7F0_LINK_CTL_1<< 32), BIT1|BIT0, 0);
	//Rx70[3:0] PEXC.LKTGLS_PEA0 = 'h2
	AsiaPcieModify8(PcieBase, PciePort|((UINT64)CND003_BUSXP1_D1D7F0_LINK_CTL_2_D1F0<< 32), BIT3|BIT2|BIT1|BIT0, 2);
	//Rx1C1[5]   (force `PEXC.RHATNMSE_PEA0 = 1;)
	AsiaPcieModify8(PcieBase, PciePort|((UINT64)CND003_BUSXP1_D1D7F0_ELASTIC_BUFFER_BASE_REGS_FOR_LANE_2_TO_3_D1F0_D6F0<< 32), BIT5, BIT5);
	//Rx1B2[4]  (force `PEXC.RFRTMDLP_PEA0 = 1;)
	AsiaPcieModify8(PcieBase, PciePort|((UINT64)CND003_BUSXP1_D1D7F0_FLOW_CTL_INIT_FCI_FLOW_CTL_UNIT_FCU_CTL_AND_STA<< 32), BIT4, BIT4);
	//Rx1B2[6]     (force `PEXC.RFRTMEN_PEA0 = 0;)
	AsiaPcieModify8(PcieBase, PciePort|((UINT64)CND003_BUSXP1_D1D7F0_FLOW_CTL_INIT_FCI_FLOW_CTL_UNIT_FCU_CTL_AND_STA<< 32), BIT6, 0);
	//4 1.b  retry buffer level
	//	Bus(X+1)D1F0(BusX+1):         Rx1A3[7:4] = 4'bF
	AsiaPcieModify8(PcieBase, PciePort|((UINT64)0x1A3<< 32), BIT7|BIT6|BIT5|BIT4, BIT7|BIT6|BIT5|BIT4);
		
	//4 1.c 
	//  Bus(X+1)D0F0(XBCTL):         Rx168[3:0] = 4'b1	
	AsiaPcieModify8(PcieBase, CND003_XBCTL|((UINT64)0x168<< 32), 0xF, DCdestid);
	//4 1.d
	//d.	Bus(X+1)D0F0:         Rx169[5] = 1'b1	
	AsiaPcieModify8(PcieBase, CND003_XBCTL|((UINT64)0x169<< 32), BIT5, BIT5);
	//4 1.e
	//e.	Bus(X+1)D1F0:         Rx3E[6] = 1'b1 
	AsiaPcieModify8(PcieBase, PcieBase|((UINT64)0x3E<< 32), BIT6, BIT6);
	// TODO: wait 2ms
	//4 1.f
	//f.	Bus(X+1)D1F0:         Rx3E[6] = 1'b0
	AsiaPcieModify8(PcieBase, PcieBase|((UINT64)0x3E<< 32), BIT6, 0);	
	// TODO:wait 2ms
	//4 1.g
	//g.	Bus(X+3)D0F0(EPTRFC): 	Rx45[0] = 1'b1;
	AsiaPciModify8(CND003_EPTRFC|0x45, BIT0, BIT0);
		
	
	
	//2 Step 2 
	switch(NbCfg->Cnd003DC){
		//3 -->SBDBG
		case 1:
			//Basic setting: DBGCAP_Rx00[30]
			IoeSmbusModify8(PeiServices, IOE_DCBASE + 3, BIT6, 0); 

			//Module selection
			IoeSmbusModify8(PeiServices, IOE_DCBASE + 3, BIT5|BIT4|BIT3, (NbCfg->Cnd003DCModule)<<3); 

			//Trans selection
			IoeSmbusModify8(PeiServices, IOE_DCBASE + 2, BIT4|BIT3, (NbCfg->Cnd003DCTrans)<<3); 
			
			break;
		//3 -->DebugSignal
		case 2:
			//Basic setting: DBGCAP_Rx00[30]
			IoeSmbusModify8(PeiServices, IOE_DCBASE + 3, BIT6, 0); 


			switch(NbCfg->Cnd003DCCfgPath){
				//4 ---->Setting from EPTRFC
				case 3:
					//Basic setting: selection cfg source - EPTRFC
					IoeSmbusModify8(PeiServices, 0x01, BIT1, BIT1); 
					//Clock gate enable
					AsiaPciModify8(AsiaPciAddress(BUSXP3, 0, 0, 0x45), BIT0, BIT0);
					
					//Set channel sel   DBGCAP_Rx00[29:27]
					AsiaPciModify8(AsiaPciAddress(BUSXP3, 0, 0, IOE_DCBASE_EPTRFC+3), BIT5|BIT4|BIT3, (UINT8)((NbCfg->Cnd003DCChannel)<<3));
										
					//Module Select
					AsiaMemoryWrite8(MmioBar+MMIO_ISB_OFFSET+0xC8, NbCfg->Cnd003ModuleG0);
					AsiaMemoryWrite8(MmioBar+MMIO_ISB_OFFSET+0xC9, NbCfg->Cnd003ModuleG1);
								
					//G select
					AsiaMemoryWrite16(MmioBar+MMIO_ISB_OFFSET+0xC0, NbCfg->Cnd003DebugG0);	
					AsiaMemoryWrite16(MmioBar+MMIO_ISB_OFFSET+0xC2, NbCfg->Cnd003DebugG1);	
					AsiaMemoryWrite16(MmioBar+MMIO_ISB_OFFSET+0xC4, NbCfg->Cnd003DebugG2);	
					AsiaMemoryWrite16(MmioBar+MMIO_ISB_OFFSET+0xC6, NbCfg->Cnd003DebugG3);

					//Mask0 & Mask1
					AsiaPciWrite32(AsiaPciAddress(BUSXP3, 0, 0, IOE_DCBASE_EPTRFC+0x28), (UINT32)(NbCfg->Cnd003DCDbg0Mask));
					AsiaPciWrite32(AsiaPciAddress(BUSXP3, 0, 0, IOE_DCBASE_EPTRFC+0x2C), (UINT32)(NbCfg->Cnd003DCDbg1Mask));
					
					//Different Tigger Mode Cases:
					switch(NbCfg->Cnd003DCTriggerMode){
						case 8:   //O Trigger Mode Enable
							AsiaPciWrite8(AsiaPciAddress(BUSXP3, 0, 0, IOE_DCBASE_EPTRFC+0x01), BIT0);
							break;
						case 9:   //User Trigger Mode Enable
							AsiaPciWrite8(AsiaPciAddress(BUSXP3, 0, 0, IOE_DCBASE_EPTRFC+0x01), BIT1);
							break;
						case 10:  //No Request Trigger Mode Enable
							AsiaPciWrite8(AsiaPciAddress(BUSXP3, 0, 0, IOE_DCBASE_EPTRFC+0x01), BIT2);

							AsiaPciWrite32(AsiaPciAddress(BUSXP3, 0, 0, IOE_DCBASE_EPTRFC+0x04), NbCfg->Cnd003DCReqPtn);	
							AsiaPciWrite32(AsiaPciAddress(BUSXP3, 0, 0, IOE_DCBASE_EPTRFC+0x08), NbCfg->Cnd003DCReqPtnMask);	
							AsiaPciWrite32(AsiaPciAddress(BUSXP3, 0, 0, IOE_DCBASE_EPTRFC+0x1C), NbCfg->Cnd003DCStartTimer);	
							AsiaPciWrite32(AsiaPciAddress(BUSXP3, 0, 0, IOE_DCBASE_EPTRFC+0x20), NbCfg->Cnd003DCPeriodTimer);	

							break;
						case 11:  //Request Count Trigger Mode Enable
							AsiaPciWrite8(AsiaPciAddress(BUSXP3, 0, 0, IOE_DCBASE_EPTRFC+0x01), BIT3);
							
							AsiaPciWrite32(AsiaPciAddress(BUSXP3, 0, 0, IOE_DCBASE_EPTRFC+0x04), NbCfg->Cnd003DCReqPtn);	
							AsiaPciWrite32(AsiaPciAddress(BUSXP3, 0, 0, IOE_DCBASE_EPTRFC+0x08), NbCfg->Cnd003DCReqPtnMask);	
							AsiaPciWrite32(AsiaPciAddress(BUSXP3, 0, 0, IOE_DCBASE_EPTRFC+0x18), NbCfg->Cnd003DCReqCnt);
							
							break;
						case 12:  //No Toggle Trigger Mode Enable
							AsiaPciWrite8(AsiaPciAddress(BUSXP3, 0, 0, IOE_DCBASE_EPTRFC+0x01), BIT4);
							
							AsiaPciWrite32(AsiaPciAddress(BUSXP3, 0, 0, IOE_DCBASE_EPTRFC+0x04), NbCfg->Cnd003DCReqPtn);	
							AsiaPciWrite32(AsiaPciAddress(BUSXP3, 0, 0, IOE_DCBASE_EPTRFC+0x08), NbCfg->Cnd003DCReqPtnMask);	
							AsiaPciWrite32(AsiaPciAddress(BUSXP3, 0, 0, IOE_DCBASE_EPTRFC+0x0C), NbCfg->Cnd003DCDataPtn);	
							AsiaPciWrite32(AsiaPciAddress(BUSXP3, 0, 0, IOE_DCBASE_EPTRFC+0x10), NbCfg->Cnd003DCDataPtnMask);	
							AsiaPciWrite32(AsiaPciAddress(BUSXP3, 0, 0, IOE_DCBASE_EPTRFC+0x1C), NbCfg->Cnd003DCStartTimer);	
							AsiaPciWrite32(AsiaPciAddress(BUSXP3, 0, 0, IOE_DCBASE_EPTRFC+0x20), NbCfg->Cnd003DCPeriodTimer);								

							break;
						case 13:  //Request Plus Data Trigger Mode Enable
							AsiaPciWrite8(AsiaPciAddress(BUSXP3, 0, 0, IOE_DCBASE_EPTRFC+0x01), BIT5);

							AsiaPciWrite32(AsiaPciAddress(BUSXP3, 0, 0, IOE_DCBASE_EPTRFC+0x04), NbCfg->Cnd003DCReqPtn);	
							AsiaPciWrite32(AsiaPciAddress(BUSXP3, 0, 0, IOE_DCBASE_EPTRFC+0x08), NbCfg->Cnd003DCReqPtnMask);	
							AsiaPciWrite32(AsiaPciAddress(BUSXP3, 0, 0, IOE_DCBASE_EPTRFC+0x0C), NbCfg->Cnd003DCDataPtn);	
							AsiaPciWrite32(AsiaPciAddress(BUSXP3, 0, 0, IOE_DCBASE_EPTRFC+0x10), NbCfg->Cnd003DCDataPtnMask);
							AsiaPciWrite32(AsiaPciAddress(BUSXP3, 0, 0, IOE_DCBASE_EPTRFC+0x14), NbCfg->Cnd003DCPlusTimer);	

							break;
						case 14:  //Data Trigger Mode Enable
							AsiaPciWrite8(AsiaPciAddress(BUSXP3, 0, 0, IOE_DCBASE_EPTRFC+0x01), BIT6);

							AsiaPciWrite32(AsiaPciAddress(BUSXP3, 0, 0, IOE_DCBASE_EPTRFC+0x0C), NbCfg->Cnd003DCDataPtn);	
							AsiaPciWrite32(AsiaPciAddress(BUSXP3, 0, 0, IOE_DCBASE_EPTRFC+0x10), NbCfg->Cnd003DCDataPtnMask);
							
							break;
						case 15:  //Request Trigger Mode Enable
							AsiaPciWrite8(AsiaPciAddress(BUSXP3, 0, 0, IOE_DCBASE_EPTRFC+0x01), BIT7);

							AsiaPciWrite32(AsiaPciAddress(BUSXP3, 0, 0, IOE_DCBASE_EPTRFC+0x04), NbCfg->Cnd003DCReqPtn);	
							AsiaPciWrite32(AsiaPciAddress(BUSXP3, 0, 0, IOE_DCBASE_EPTRFC+0x08), NbCfg->Cnd003DCReqPtnMask);	
							break;
						default:
							break;
					}
										


					break;
				//4 ---->Setting from SMBus (00-2F form base address 0x30)
				case 1:
					//Basic setting: selection cfg source - SMBus
					IoeSmbusModify8(PeiServices, 0x01, BIT1, 0);
					//Clock gate enable
					IoeSmbusModify8(PeiServices, 0x01, BIT0, BIT0);

					//Set channel sel   DBGCAP_Rx00[29:27]
					IoeSmbusModify8(PeiServices,IOE_DCBASE + 3, BIT5|BIT4|BIT3, (UINT8)((NbCfg->Cnd003DCChannel)<<3));
					
					//Module and Group selection - Use DebugSignal setup page
					IoeSmbusWrite(PeiServices, 0x0A, (0xF0&((NbCfg->Cnd003ModuleG1)<<4))|((NbCfg->Cnd003ModuleG0)&0xF));

					//SMB_DBG_SEL_G0 ~ SMB_DBG_SEL_G3
					IoeSmbusWrite(PeiServices, 0x02, 0xFF&(NbCfg->Cnd003DebugG0));
					IoeSmbusWrite(PeiServices, 0x03, 0xF&((NbCfg->Cnd003DebugG0)>>8));
					IoeSmbusWrite(PeiServices, 0x04, 0xFF&(NbCfg->Cnd003DebugG1));
					IoeSmbusWrite(PeiServices, 0x05, 0xF&((NbCfg->Cnd003DebugG1)>>8));
					IoeSmbusWrite(PeiServices, 0x06, 0xFF&(NbCfg->Cnd003DebugG2));
					IoeSmbusWrite(PeiServices, 0x07, 0xF&((NbCfg->Cnd003DebugG2)>>8));
					IoeSmbusWrite(PeiServices, 0x08, 0xFF&(NbCfg->Cnd003DebugG3));
					IoeSmbusWrite(PeiServices, 0x09, 0xF&((NbCfg->Cnd003DebugG3)>>8));

					//Mask0 & Mask1
					IoeSmbusWrite(PeiServices, IOE_DCBASE+0x28,  (UINT8)((NbCfg->Cnd003DCDbg0Mask)&0xFF) );
					IoeSmbusWrite(PeiServices, IOE_DCBASE+0x29, (UINT8)(((NbCfg->Cnd003DCDbg0Mask)>>8)&0xFF) );
					IoeSmbusWrite(PeiServices, IOE_DCBASE+0x2A, (UINT8)(((NbCfg->Cnd003DCDbg0Mask)>>16))&0xFF);
					IoeSmbusWrite(PeiServices, IOE_DCBASE+0x2B, (UINT8)(((NbCfg->Cnd003DCDbg0Mask)>>24)&0xFF) );

					IoeSmbusWrite(PeiServices, IOE_DCBASE+0x2C,  (UINT8)((NbCfg->Cnd003DCDbg1Mask)&0xFF) );
					IoeSmbusWrite(PeiServices, IOE_DCBASE+0x2D, (UINT8)(((NbCfg->Cnd003DCDbg1Mask)>>8)&0xFF) );
					IoeSmbusWrite(PeiServices, IOE_DCBASE+0x2E, (UINT8)(((NbCfg->Cnd003DCDbg1Mask)>>16))&0xFF);
					IoeSmbusWrite(PeiServices, IOE_DCBASE+0x2F, (UINT8)(((NbCfg->Cnd003DCDbg1Mask)>>24)&0xFF) );
					
					//Different Tigger Mode Cases:
					switch(NbCfg->Cnd003DCTriggerMode){
						case 8:   //O Trigger Mode Enable
							IoeSmbusWrite(PeiServices, IOE_DCBASE+0x01, BIT0);
							break;
						case 9:   //User Trigger Mode Enable
							IoeSmbusWrite(PeiServices, IOE_DCBASE+0x01, BIT1);
							break;
						case 10:  //No Request Trigger Mode Enable
							IoeSmbusWrite(PeiServices, IOE_DCBASE+0x01, BIT2);

							IoeSmbusWrite(PeiServices, IOE_DCBASE+0x04,  (UINT8)((NbCfg->Cnd003DCReqPtn)&0xFF) );
							IoeSmbusWrite(PeiServices, IOE_DCBASE+0x05, (UINT8)(((NbCfg->Cnd003DCReqPtn)>>8)&0xFF) );
							IoeSmbusWrite(PeiServices, IOE_DCBASE+0x06, (UINT8)(((NbCfg->Cnd003DCReqPtn)>>16))&0xFF);
							IoeSmbusWrite(PeiServices, IOE_DCBASE+0x07, (UINT8)(((NbCfg->Cnd003DCReqPtn)>>24)&0xFF) );						

							IoeSmbusWrite(PeiServices, IOE_DCBASE+0x08,  (UINT8)((NbCfg->Cnd003DCReqPtnMask)&0xFF) );
							IoeSmbusWrite(PeiServices, IOE_DCBASE+0x09, (UINT8)(((NbCfg->Cnd003DCReqPtnMask)>>8)&0xFF) );
							IoeSmbusWrite(PeiServices, IOE_DCBASE+0x0A, (UINT8)(((NbCfg->Cnd003DCReqPtnMask)>>16))&0xFF);
							IoeSmbusWrite(PeiServices, IOE_DCBASE+0x0B, (UINT8)(((NbCfg->Cnd003DCReqPtnMask)>>24)&0xFF) );

							IoeSmbusWrite(PeiServices, IOE_DCBASE+0x1C,  (UINT8)((NbCfg->Cnd003DCStartTimer)&0xFF) );
							IoeSmbusWrite(PeiServices, IOE_DCBASE+0x1D, (UINT8)(((NbCfg->Cnd003DCStartTimer)>>8)&0xFF) );
							IoeSmbusWrite(PeiServices, IOE_DCBASE+0x1E, (UINT8)(((NbCfg->Cnd003DCStartTimer)>>16))&0xFF);
							IoeSmbusWrite(PeiServices, IOE_DCBASE+0x1F, (UINT8)(((NbCfg->Cnd003DCStartTimer)>>24)&0xFF) );						

							IoeSmbusWrite(PeiServices, IOE_DCBASE+0x20,  (UINT8)((NbCfg->Cnd003DCPeriodTimer)&0xFF) );
							IoeSmbusWrite(PeiServices, IOE_DCBASE+0x21, (UINT8)(((NbCfg->Cnd003DCPeriodTimer)>>8)&0xFF) );
							IoeSmbusWrite(PeiServices, IOE_DCBASE+0x22, (UINT8)(((NbCfg->Cnd003DCPeriodTimer)>>16))&0xFF);
							IoeSmbusWrite(PeiServices, IOE_DCBASE+0x23, (UINT8)(((NbCfg->Cnd003DCPeriodTimer)>>24)&0xFF) );

							break;
						case 11:  //Request Count Trigger Mode Enable
							IoeSmbusWrite(PeiServices, IOE_DCBASE+0x01, BIT3);
							
							IoeSmbusWrite(PeiServices, IOE_DCBASE+0x04,  (UINT8)((NbCfg->Cnd003DCReqPtn)&0xFF) );
							IoeSmbusWrite(PeiServices, IOE_DCBASE+0x05, (UINT8)(((NbCfg->Cnd003DCReqPtn)>>8)&0xFF) );
							IoeSmbusWrite(PeiServices, IOE_DCBASE+0x06, (UINT8)(((NbCfg->Cnd003DCReqPtn)>>16))&0xFF);
							IoeSmbusWrite(PeiServices, IOE_DCBASE+0x07, (UINT8)(((NbCfg->Cnd003DCReqPtn)>>24)&0xFF) );						

							IoeSmbusWrite(PeiServices, IOE_DCBASE+0x08,  (UINT8)((NbCfg->Cnd003DCReqPtnMask)&0xFF) );
							IoeSmbusWrite(PeiServices, IOE_DCBASE+0x09, (UINT8)(((NbCfg->Cnd003DCReqPtnMask)>>8)&0xFF) );
							IoeSmbusWrite(PeiServices, IOE_DCBASE+0x0A, (UINT8)(((NbCfg->Cnd003DCReqPtnMask)>>16))&0xFF);
							IoeSmbusWrite(PeiServices, IOE_DCBASE+0x0B, (UINT8)(((NbCfg->Cnd003DCReqPtnMask)>>24)&0xFF) );

							IoeSmbusWrite(PeiServices, IOE_DCBASE+0x18,  (UINT8)((NbCfg->Cnd003DCReqCnt)&0xFF) );
							IoeSmbusWrite(PeiServices, IOE_DCBASE+0x19, (UINT8)(((NbCfg->Cnd003DCReqCnt)>>8)&0xFF) );
							IoeSmbusWrite(PeiServices, IOE_DCBASE+0x1A, (UINT8)(((NbCfg->Cnd003DCReqCnt)>>16))&0xFF);
							IoeSmbusWrite(PeiServices, IOE_DCBASE+0x1B, (UINT8)(((NbCfg->Cnd003DCReqCnt)>>24)&0xFF) );
							
							break;
						case 12:  //No Toggle Trigger Mode Enable
							IoeSmbusWrite(PeiServices, IOE_DCBASE+0x01, BIT4);

							IoeSmbusWrite(PeiServices, IOE_DCBASE+0x04,  (UINT8)((NbCfg->Cnd003DCReqPtn)&0xFF) );
							IoeSmbusWrite(PeiServices, IOE_DCBASE+0x05, (UINT8)(((NbCfg->Cnd003DCReqPtn)>>8)&0xFF) );
							IoeSmbusWrite(PeiServices, IOE_DCBASE+0x06, (UINT8)(((NbCfg->Cnd003DCReqPtn)>>16))&0xFF);
							IoeSmbusWrite(PeiServices, IOE_DCBASE+0x07, (UINT8)(((NbCfg->Cnd003DCReqPtn)>>24)&0xFF) );						

							IoeSmbusWrite(PeiServices, IOE_DCBASE+0x08,  (UINT8)((NbCfg->Cnd003DCReqPtnMask)&0xFF) );
							IoeSmbusWrite(PeiServices, IOE_DCBASE+0x09, (UINT8)(((NbCfg->Cnd003DCReqPtnMask)>>8)&0xFF) );
							IoeSmbusWrite(PeiServices, IOE_DCBASE+0x0A, (UINT8)(((NbCfg->Cnd003DCReqPtnMask)>>16))&0xFF);
							IoeSmbusWrite(PeiServices, IOE_DCBASE+0x0B, (UINT8)(((NbCfg->Cnd003DCReqPtnMask)>>24)&0xFF) );

							IoeSmbusWrite(PeiServices, IOE_DCBASE+0x0C,  (UINT8)((NbCfg->Cnd003DCDataPtn)&0xFF) );
							IoeSmbusWrite(PeiServices, IOE_DCBASE+0x0D, (UINT8)(((NbCfg->Cnd003DCDataPtn)>>8)&0xFF) );
							IoeSmbusWrite(PeiServices, IOE_DCBASE+0x0E, (UINT8)(((NbCfg->Cnd003DCDataPtn)>>16))&0xFF);
							IoeSmbusWrite(PeiServices, IOE_DCBASE+0x0F, (UINT8)(((NbCfg->Cnd003DCDataPtn)>>24)&0xFF) );						

							IoeSmbusWrite(PeiServices, IOE_DCBASE+0x10,  (UINT8)((NbCfg->Cnd003DCDataPtnMask)&0xFF) );
							IoeSmbusWrite(PeiServices, IOE_DCBASE+0x11, (UINT8)(((NbCfg->Cnd003DCDataPtnMask)>>8)&0xFF) );
							IoeSmbusWrite(PeiServices, IOE_DCBASE+0x12, (UINT8)(((NbCfg->Cnd003DCDataPtnMask)>>16))&0xFF);
							IoeSmbusWrite(PeiServices, IOE_DCBASE+0x13, (UINT8)(((NbCfg->Cnd003DCDataPtnMask)>>24)&0xFF) );
							
							IoeSmbusWrite(PeiServices, IOE_DCBASE+0x1C,  (UINT8)((NbCfg->Cnd003DCStartTimer)&0xFF) );
							IoeSmbusWrite(PeiServices, IOE_DCBASE+0x1D, (UINT8)(((NbCfg->Cnd003DCStartTimer)>>8)&0xFF) );
							IoeSmbusWrite(PeiServices, IOE_DCBASE+0x1E, (UINT8)(((NbCfg->Cnd003DCStartTimer)>>16))&0xFF);
							IoeSmbusWrite(PeiServices, IOE_DCBASE+0x1F, (UINT8)(((NbCfg->Cnd003DCStartTimer)>>24)&0xFF) );						

							IoeSmbusWrite(PeiServices, IOE_DCBASE+0x20,  (UINT8)((NbCfg->Cnd003DCPeriodTimer)&0xFF) );
							IoeSmbusWrite(PeiServices, IOE_DCBASE+0x21, (UINT8)(((NbCfg->Cnd003DCPeriodTimer)>>8)&0xFF) );
							IoeSmbusWrite(PeiServices, IOE_DCBASE+0x22, (UINT8)(((NbCfg->Cnd003DCPeriodTimer)>>16))&0xFF);
							IoeSmbusWrite(PeiServices, IOE_DCBASE+0x23, (UINT8)(((NbCfg->Cnd003DCPeriodTimer)>>24)&0xFF) );
							
							break;
						case 13:  //Request Plus Data Trigger Mode Enable
							IoeSmbusWrite(PeiServices, IOE_DCBASE+0x01, BIT5);

							IoeSmbusWrite(PeiServices, IOE_DCBASE+0x04,  (UINT8)((NbCfg->Cnd003DCReqPtn)&0xFF) );
							IoeSmbusWrite(PeiServices, IOE_DCBASE+0x05, (UINT8)(((NbCfg->Cnd003DCReqPtn)>>8)&0xFF) );
							IoeSmbusWrite(PeiServices, IOE_DCBASE+0x06, (UINT8)(((NbCfg->Cnd003DCReqPtn)>>16))&0xFF);
							IoeSmbusWrite(PeiServices, IOE_DCBASE+0x07, (UINT8)(((NbCfg->Cnd003DCReqPtn)>>24)&0xFF) );						

							IoeSmbusWrite(PeiServices, IOE_DCBASE+0x08,  (UINT8)((NbCfg->Cnd003DCReqPtnMask)&0xFF) );
							IoeSmbusWrite(PeiServices, IOE_DCBASE+0x09, (UINT8)(((NbCfg->Cnd003DCReqPtnMask)>>8)&0xFF) );
							IoeSmbusWrite(PeiServices, IOE_DCBASE+0x0A, (UINT8)(((NbCfg->Cnd003DCReqPtnMask)>>16))&0xFF);
							IoeSmbusWrite(PeiServices, IOE_DCBASE+0x0B, (UINT8)(((NbCfg->Cnd003DCReqPtnMask)>>24)&0xFF) );

							IoeSmbusWrite(PeiServices, IOE_DCBASE+0x0C,  (UINT8)((NbCfg->Cnd003DCDataPtn)&0xFF) );
							IoeSmbusWrite(PeiServices, IOE_DCBASE+0x0D, (UINT8)(((NbCfg->Cnd003DCDataPtn)>>8)&0xFF) );
							IoeSmbusWrite(PeiServices, IOE_DCBASE+0x0E, (UINT8)(((NbCfg->Cnd003DCDataPtn)>>16))&0xFF);
							IoeSmbusWrite(PeiServices, IOE_DCBASE+0x0F, (UINT8)(((NbCfg->Cnd003DCDataPtn)>>24)&0xFF) );						

							IoeSmbusWrite(PeiServices, IOE_DCBASE+0x10,  (UINT8)((NbCfg->Cnd003DCDataPtnMask)&0xFF) );
							IoeSmbusWrite(PeiServices, IOE_DCBASE+0x11, (UINT8)(((NbCfg->Cnd003DCDataPtnMask)>>8)&0xFF) );
							IoeSmbusWrite(PeiServices, IOE_DCBASE+0x12, (UINT8)(((NbCfg->Cnd003DCDataPtnMask)>>16))&0xFF);
							IoeSmbusWrite(PeiServices, IOE_DCBASE+0x13, (UINT8)(((NbCfg->Cnd003DCDataPtnMask)>>24)&0xFF) );

							IoeSmbusWrite(PeiServices, IOE_DCBASE+0x14,  (UINT8)((NbCfg->Cnd003DCPlusTimer)&0xFF) );
							IoeSmbusWrite(PeiServices, IOE_DCBASE+0x15, (UINT8)(((NbCfg->Cnd003DCPlusTimer)>>8)&0xFF) );
							IoeSmbusWrite(PeiServices, IOE_DCBASE+0x16, (UINT8)(((NbCfg->Cnd003DCPlusTimer)>>16))&0xFF);
							IoeSmbusWrite(PeiServices, IOE_DCBASE+0x17, (UINT8)(((NbCfg->Cnd003DCPlusTimer)>>24)&0xFF) );	

							break;
						case 14:  //Data Trigger Mode Enable
							IoeSmbusWrite(PeiServices, IOE_DCBASE+0x01, BIT6);

							IoeSmbusWrite(PeiServices, IOE_DCBASE+0x0C,  (UINT8)((NbCfg->Cnd003DCDataPtn)&0xFF) );
							IoeSmbusWrite(PeiServices, IOE_DCBASE+0x0D, (UINT8)(((NbCfg->Cnd003DCDataPtn)>>8)&0xFF) );
							IoeSmbusWrite(PeiServices, IOE_DCBASE+0x0E, (UINT8)(((NbCfg->Cnd003DCDataPtn)>>16))&0xFF);
							IoeSmbusWrite(PeiServices, IOE_DCBASE+0x0F, (UINT8)(((NbCfg->Cnd003DCDataPtn)>>24)&0xFF) );						

							IoeSmbusWrite(PeiServices, IOE_DCBASE+0x10,  (UINT8)((NbCfg->Cnd003DCDataPtnMask)&0xFF) );
							IoeSmbusWrite(PeiServices, IOE_DCBASE+0x11, (UINT8)(((NbCfg->Cnd003DCDataPtnMask)>>8)&0xFF) );
							IoeSmbusWrite(PeiServices, IOE_DCBASE+0x12, (UINT8)(((NbCfg->Cnd003DCDataPtnMask)>>16))&0xFF);
							IoeSmbusWrite(PeiServices, IOE_DCBASE+0x13, (UINT8)(((NbCfg->Cnd003DCDataPtnMask)>>24)&0xFF) );
							
							break;
						case 15:  //Request Trigger Mode Enable
							IoeSmbusWrite(PeiServices, IOE_DCBASE+0x01, BIT7);

							IoeSmbusWrite(PeiServices, IOE_DCBASE+0x04,  (UINT8)((NbCfg->Cnd003DCReqPtn)&0xFF) );
							IoeSmbusWrite(PeiServices, IOE_DCBASE+0x05, (UINT8)(((NbCfg->Cnd003DCReqPtn)>>8)&0xFF) );
							IoeSmbusWrite(PeiServices, IOE_DCBASE+0x06, (UINT8)(((NbCfg->Cnd003DCReqPtn)>>16))&0xFF);
							IoeSmbusWrite(PeiServices, IOE_DCBASE+0x07, (UINT8)(((NbCfg->Cnd003DCReqPtn)>>24)&0xFF) );						

							IoeSmbusWrite(PeiServices, IOE_DCBASE+0x08,  (UINT8)((NbCfg->Cnd003DCReqPtnMask)&0xFF) );
							IoeSmbusWrite(PeiServices, IOE_DCBASE+0x09, (UINT8)(((NbCfg->Cnd003DCReqPtnMask)>>8)&0xFF) );
							IoeSmbusWrite(PeiServices, IOE_DCBASE+0x0A, (UINT8)(((NbCfg->Cnd003DCReqPtnMask)>>16))&0xFF);
							IoeSmbusWrite(PeiServices, IOE_DCBASE+0x0B, (UINT8)(((NbCfg->Cnd003DCReqPtnMask)>>24)&0xFF) );
							break;
						default:
							break;
					}
					

					break;
				default:
					break;
			}
		

			break;
		//3 Disable & Default
		case 0:
		default:
			break;
	}

	//Enable DBGCAP		
	IoeSmbusModify8(PeiServices, IOE_DCBASE+0x03, BIT7,BIT7);

	IoePeiClearTempAssignment(PeiServices);
	return EFI_SUCCESS;
}


/**
Reason:
	This patch is for DebugSignal Group 0 output pad
	Since CND003 A0 MMIO_ISB Rx10[4] [7] was Vcc power,
	PEXRST will reset them and this have influence on power
	on and S3 debug. 
Note:
	So this function should be called after
	PEXRST# of CND003 Capability Selection and TempBusAssignemnt
	completed
	Each time we set PEXRST, we need to call this function to
	patch on A0 chip
**/

/**
   SATA PEI Init function.
   Called by SataInitPei()
   
  @param  PeiServices	EFI_PEI_SERVICES pointer.
  @param SbCfg point to ASIA_SB_CONFIGURATION struct

  @return EFI_STATUS.

**/

EFI_STATUS
IoePatchDbgSignal(	
	IN EFI_PEI_SERVICES **PeiServices, 
	ASIA_NB_CONFIGURATION *NbCfg)
{
	UINT32 MemBar;
	MemBar = AsiaPciRead32(AsiaPciAddress(BUSX, 0, 0, 0x10));
	
	if(NbCfg->Cnd003DbgPadG0En == 1){
		AsiaMemoryModify8(MemBar + MMIO_ISB_OFFSET + 0x10, BIT4, BIT4);
	}

	if(NbCfg->Cnd003HighSpeed == 1){
		AsiaMemoryModify8(MemBar + MMIO_ISB_OFFSET + 0x10, BIT7, BIT7);
	}
	return EFI_SUCCESS;
}




