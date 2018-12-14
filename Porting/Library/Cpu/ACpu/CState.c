//**********************************************************************
//**********************************************************************
//**                                                                  **
//**     Copyright (c) 2018 Shanghai Zhaoxin Semiconductor Co., Ltd.  **
//**                                                                  **
//**********************************************************************
//**********************************************************************

#include "CState.h"
#include "EfiCommonLib.h"

extern UINT8 GetACpuCores();

/*===================================================================
Function   : CxeInitialize()
Precondition :
Input      :  CxeEnable:
                              TRUE: enable this feature
                              FALSE: disable this feature
Output     : EFI_STATUS
                         EFI_SUPPORTED: this cpu don't support this function
                         EFI_SUCCESS:     initialized this feature
Purpose    : according to the input set cpu's function
Reference  : None
note:       
===================================================================*/

EFI_STATUS CxeInitialize(BOOLEAN CxeEnable)
{
    UINT64   MsrVal;

    //Enable CxE  MSR 0x1A0 bit[25]
	MsrVal = EfiReadMsr(EFI_MSR_IA32_MISC_ENABLE);
	if(CxeEnable == TRUE)
		MsrVal |= 0x2000000;
	else
	      MsrVal &= ~0x2000000;
	EfiWriteMsr(EFI_MSR_IA32_MISC_ENABLE, MsrVal);

	return EFI_SUCCESS;
}


EFI_STATUS SetCStatesIoBase(ASIA_CPU_CONFIGURATION *Feature)
{
	UINT64   MsrVal=0;
	UINT8    Cstate;
	UINT16   PLV2Base;

    PLV2Base = Feature->PLVL2IoBase;
	//0xE2 bitfield 
	//  DYN_L2_PWRMNGT_ENABLE_BIT  3   // enables dynamic sizing on l2
	//  STPGRNT_ISSUE              9   // 1=Issue stopgrant per core, 0=only 1/package                      
	//  ENABLE_IO_REDIRECT_BIT     10  // enables IN redirection        
	//  INTERRUPT_FILTERING        24  // 0=all awake  1 = dest core awakes
	//Need to know which Cstate is requested and program 0xE2 correctly
	//case 5 is overloaded because of C4 with C5Control
	Cstate = 0;
	switch(Feature->ProcessorCState) {
		case 0: Cstate = 1; break;
		case 1: Cstate = 2; break;
		case 2: Cstate = 3; break;
		case 3: Cstate = 3; break;
		case 4: 
			Cstate = 4; 
			//If C2C4 and C5control enable, then request C5 in 0xE2
			if (Feature->C5Control == 1)
				Cstate = 5;
			break;
		case 5: 
			Cstate = 5; 
			//if C2C4 Updown and C5control disable, then request C4 in 0xE2
			if (Feature->C5Control == 0)
				Cstate = 4;
			break;
	} 



	MsrVal = Cstate;
	MsrVal |= 0x00000400; //all c states get io redirect
	if (Feature->C5L2sizingControl && (Cstate == 5)){
		MsrVal |= 0x00000008; //BIT 3 only if C5 is set
	}
	if (Feature->CxIntFilterControl){
		MsrVal |= 0x01000000; //BIT 24
	}


	EfiWriteMsr(MSR_PM_CFG_CTRL, MsrVal);

	//iobase to C2 io port
	MsrVal = PLV2Base;
	EfiWriteMsr(MSR_IO_BASE_ADDR , MsrVal);

	//set c2 io base and C state capability to C5
	MsrVal = PLV2Base | 0x30000;

	EfiWriteMsr(MSR_IO_CAPT_ADDR , MsrVal);

	return EFI_SUCCESS;
}

/*===================================================================
Function   : WorkAroundForC4State()
Precondition :
Input      :  
Output     : EFI_STATUS
                         EFI_SUPPORTED: this cpu don't support this function
                         EFI_SUCCESS:     initialized this feature
Purpose    : according to the input set register to workaround C4 state
Reference  : None
note:       
==================================================================*/
EFI_STATUS WorkAroundForC4State(ASIA_CPU_CONFIGURATION *Feature) 
{
	return EFI_SUCCESS;
}

EFI_STATUS WorkAroundForC5State(ASIA_CPU_CONFIGURATION *Feature, UINT32 RegEax) 
{
	return EFI_SUCCESS;
}

/*===================================================================
Function   : CStatesInitialize()
Precondition :
Input      :  
Output     : EFI_STATUS
                         EFI_SUPPORTED: this cpu don't support this function
                         EFI_SUCCESS:     initialized this feature
Purpose    : according to the input set cpu's function
Reference  : None
note:       
===================================================================*/
EFI_STATUS CStatesInitialize(ASIA_CPU_CONFIGURATION *Feature)
{
   EFI_STATUS   Status = EFI_SUCCESS;
   UINT64       MsrVal;

		SetCStatesIoBase(Feature);

   Status = CxeInitialize(Feature->ProcessorCxeEnable);
   
   // eps lock bit MSR_1a0[20]
   //
   MsrVal = EfiReadMsr(EFI_MSR_IA32_MISC_ENABLE);
   MsrVal |= (1<<20);
   EfiWriteMsr(EFI_MSR_IA32_MISC_ENABLE, MsrVal);

   return Status;
}

/*===================================================================
Function   : NAPSNAPInit()
Precondition :
Input      :  NapSnapEnable:
                              TRUE: enable this feature
                              FALSE: disable this feature
Output     : EFI_STATUS
                         EFI_SUPPORTED: this cpu don't support this function
                         EFI_SUCCESS:     initialized this feature
Purpose    : according to the input set cpu's function
Reference  : None
note:       
===================================================================*/
EFI_STATUS NAPSNAPInit(BOOLEAN NapSnapEnable)
{
  UINT64 MsrVal;

  //For ACPU: MSR_0x1407[8]

      MsrVal = EfiReadMsr(0x1407);
      if (NapSnapEnable)
          MsrVal = MsrVal | 0x100;
      else
          MsrVal = MsrVal & (~0x100);
      EfiWriteMsr(0x1407, MsrVal);

   return EFI_SUCCESS;
}
