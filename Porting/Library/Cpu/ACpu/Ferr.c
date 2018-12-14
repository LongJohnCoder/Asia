//**********************************************************************
//**********************************************************************
//**                                                                  **
//**     Copyright (c) 2018 Shanghai Zhaoxin Semiconductor Co., Ltd.  **
//**                                                                  **
//**********************************************************************
//**********************************************************************


#include "Ferr.h"

/*===================================================================
Function   : IsFerrSupport()
Precondition :
Input      :  void
Output     : BOOLEAN:
                         TRUE:  this cpu  support Ferr as PBE function
                          FALSE: this cpu does not support Ferr as PBE function
Purpose    : judge if cpu support Ferr as PBE function
Reference  : None
note:       
===================================================================*/

BOOLEAN IsFerrSupport()
{
      EFI_CPUID_REGISTER CpuInfo;

      EfiCpuid(EFI_CPUID_VERSION_INFO, &CpuInfo);

     //ferr flag cpuid[1].RegEdx[31]
     if ((CpuInfo.RegEdx&ACPU_FERR_FLAG) != 0)
	    return TRUE;
    else
	   return FALSE;
}

/*===================================================================
Function   : EnableFerr()
Precondition :
Input      : void
Output     : void
Purpose    : Enable  cpu's FERR as PBE  function
Reference  : None
note:       
===================================================================*/

void EnableFerr()
{
    UINT64      MsrVal;

    MsrVal = EfiReadMsr(EFI_MSR_IA32_MISC_ENABLE);
    //enable ferr MSR 0x1A0[10] 
    MsrVal |=  ACPU_FERR_ENABLE;
    EfiWriteMsr(EFI_MSR_IA32_MISC_ENABLE, MsrVal);
}

/*===================================================================
Function   : DisableFerr()
Precondition :
Input      : void
Output     : void
Purpose    : Disable  cpu's FERR as PBE  function
Reference  : None
note:       
===================================================================*/

void DisableFerr()
{
    UINT64      MsrVal;

    MsrVal = EfiReadMsr(EFI_MSR_IA32_MISC_ENABLE);
    //disable ferr MSR 0x1A0[10]
    MsrVal &=  ~ACPU_FERR_ENABLE;
    EfiWriteMsr(EFI_MSR_IA32_MISC_ENABLE, MsrVal);
}


/*===================================================================
Function   : FerrInitialize()
Precondition :
Input      :  FerrInterruptReporting:
                              TRUE: enable this feature
                              FALSE: disable this feature
Output     : EFI_STATUS
                         EFI_SUPPORTED: this cpu don't support this function
                         EFI_SUCCESS:     initialized this feature
Purpose    : according to the input set cpu's function
Reference  : None
note:       
===================================================================*/

EFI_STATUS FerrInitialize(BOOLEAN FerrInterruptReporting)
{
     if(!IsFerrSupport())
	 return EFI_UNSUPPORTED;

    if(FerrInterruptReporting)
	EnableFerr();
    else
	DisableFerr();

    return EFI_SUCCESS;
}

