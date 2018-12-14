//**********************************************************************
//**********************************************************************
//**                                                                  **
//**     Copyright (c) 2018 Shanghai Zhaoxin Semiconductor Co., Ltd.  **
//**                                                                  **
//**********************************************************************
//**********************************************************************


#include "CpuidMaximumLimit.h"

/*===================================================================
Function   : CpuidMaximumValueLimitEnable()
Precondition :
Input      :  LimitCpuidMaxmumValue:
                              TRUE: enable this feature
                              FALSE: disable this feature
Output     : EFI_STATUS
                         EFI_SUPPORTED: this cpu don't support this function
                         EFI_SUCCESS:     initialized this feature
Purpose    : according to the input set cpu's function
Reference  : None
note:
===================================================================*/

EFI_STATUS CpuidMaximumValueLimitEnable(BOOLEAN LimitCpuidMaximumValue)
{
    UINT64   MsrVal;
    EFI_CPUID_REGISTER CpuidInfo;

    //judge cpuid is support
    //limit cpuid maximum leaf msr 0x1A0 bit[22]
    EfiCpuid(EFI_CPUID_SIGNATURE, &CpuidInfo);
    MsrVal = EfiReadMsr(EFI_MSR_IA32_MISC_ENABLE);
    if ((CpuidInfo.RegEax > 3) && (LimitCpuidMaximumValue == TRUE))
        MsrVal |= 0x400000;
    else
        MsrVal &= ~0x400000;
    EfiWriteMsr(EFI_MSR_IA32_MISC_ENABLE, MsrVal);

    return EFI_SUCCESS;
}