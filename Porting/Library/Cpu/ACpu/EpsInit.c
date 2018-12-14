//**********************************************************************
//**********************************************************************
//**                                                                  **
//**     Copyright (c) 2018 Shanghai Zhaoxin Semiconductor Co., Ltd.  **
//**                                                                  **
//**********************************************************************
//**********************************************************************

#include "EpsInit.h"
#include "PStates.h"
BOOLEAN IsAP() {
#define BSP_BIT             0x00000100
#define MSR_APIC_BASE_MSR   0x1B
  UINT64 MsrValue;
  UINT32 Temp;
  
  MsrValue = EfiReadMsr(MSR_APIC_BASE_MSR);
  Temp = (UINT32)MsrValue;
  
  if (Temp & BSP_BIT) {
    return FALSE;
  }
  
  return TRUE;
}

/*===================================================================
Function   : IsEpsSupport()
Precondition :
Input      :  void
Output     : BOOLEAN:
                         TRUE:  this cpu  support EPS function
                          FALSE: this cpu does not support EPS function
Purpose    : judge if cpu support EPS function
Reference  : None
note:       
===================================================================*/

BOOLEAN IsEpsSupport()
{
      EFI_CPUID_REGISTER CpuInfo;

      EfiCpuid(EFI_CPUID_VERSION_INFO, &CpuInfo);

     //EPS flag cpuid[1].RegEcx[7]
     if ((CpuInfo.RegEcx&ACPU_EPS_FLAG) != 0)
	    return TRUE;
    else
	   return FALSE;
}

void TSCFrequenceSync()
{
	UINT64   MsrVal;
	EFI_CPUID_REGISTER CpuidInfo;

	EfiCpuid(EFI_CPUID_VERSION_INFO, &CpuidInfo);

	//Msr 0x1203[32]
	// 0: TSC always runs at the maximum frequency supported by the processor
	// 1: TSC runs at the current operating frequency of the processor
	MsrVal = EfiReadMsr(0x1203);
	MsrVal |= 0x100000000;
	EfiWriteMsr(0x1203, MsrVal);
}


void TSCFrequenceMax()
{
	UINT64   MsrVal;

	//Msr 0x1203[32]
	// 0: TSC always runs at the maximum frequency supported by the processor
	// 1: TSC runs at the current operating frequency of the processor
	MsrVal = EfiReadMsr(0x1203);
	MsrVal &= (~(LShiftU64(1, 32)));
	EfiWriteMsr(0x1203, MsrVal);
}

/*===================================================================
Function   : EnableEps()
Precondition :
Input      : void
Output     : void
Purpose    : Enable  cpu's EPS(Enhanced power saver) function
Reference  : None
note:       
===================================================================*/

void EnableEps()
{
	//EPS_ENABLE have set in SEC phase and doesn't program again.
    UINT64     MsrVal;
    MsrVal = EfiReadMsr(EFI_MSR_IA32_MISC_ENABLE);
	//Disable EPS MSR 0x1A0[16] and and eps lock 0x1A0[20]
    MsrVal = MsrVal |ACPU_EPS_ENABLE ;
    EfiWriteMsr(EFI_MSR_IA32_MISC_ENABLE, MsrVal);

}

/*===================================================================
Function   : DisableEps()
Precondition :
Input      : void
Output     : void
Purpose    : Disable  cpu's EPS(Enhanced power saver) function
Reference  : None
note:       
===================================================================*/

void DisableEps()
{
    UINT64     MsrVal;

    MsrVal = EfiReadMsr(EFI_MSR_IA32_MISC_ENABLE);
    //disable EPS MSR 0x1A0[16] and and eps lock 0x1A0[20]
    MsrVal = MsrVal & (~ACPU_EPS_ENABLE);
    EfiWriteMsr(EFI_MSR_IA32_MISC_ENABLE, MsrVal);
}

/*===================================================================
Function   : ChangeToMaxFrequence()
Precondition : Enable EPS
Input      : void
Output     : void
Purpose    : Switch CPU to MAX P State
Reference  : None
note:       
===================================================================*/
void ChangeToMaxFrequence()
{
    UINT64  MsrVal;
    UINT8  MaxVid, MaxFid;

        //shigt to max P_State
     MsrVal = EfiReadMsr(0x198);
     MaxVid = (UINT8)(RShiftU64(MsrVal, 32) & 0xFF);
     MaxFid = (UINT8)(RShiftU64(MsrVal, 40) & 0xFF);

     if(MaxFid > MAX_FIXED_RATIO)
	  MaxFid = MAX_FIXED_RATIO;
     MsrVal = 0;
     MsrVal = (MaxFid << 8)|MaxVid;
     EfiWriteMsr(0x199, MsrVal);
}

/*===================================================================
Function   : ChangeToMinFrequence()
Precondition : 
Input      : void
Output     : void
Purpose    : Switch CPU to Min P State
Reference  : None
note:       
===================================================================*/
void ChangeToMinFrequence()
{
    UINT64  MsrVal;

        //shigt to min P_State
     MsrVal = EfiReadMsr(0x198);
     MsrVal = RShiftU64(MsrVal, 48) & 0xFFFF;
     EfiWriteMsr(0x199, MsrVal);
}

/*===================================================================
Function   : EpsInitialize()
Precondition :
Input      :  EpsEnable:
                              TRUE: enable this feature
                              FALSE: disable this feature
                MaxFrequence:
                              TRUE: choose the max performance
                              FALSE: choose the max battery life
Output     : EFI_STATUS
                         EFI_SUPPORTED: this cpu don't support this function
                         EFI_SUCCESS:     initialized this feature
Purpose    : according to the input set cpu's function
Reference  : None
note:       
===================================================================*/
EFI_STATUS EpsInitialize(BOOLEAN EpsEnable,
                                           BOOLEAN MaxFrequence)
{

     if(!IsEpsSupport())
	 return EFI_UNSUPPORTED;

    if(EpsEnable)
    	{
	    
	    if (IsAP()) {
        EnableEps();
	      if(MaxFrequence)
	          ChangeToMaxFrequence();
	      else
		      ChangeToMinFrequence();
		  }
		  
    	}
    else
	   DisableEps();
    return EFI_SUCCESS;
}

