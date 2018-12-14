//**********************************************************************
//**********************************************************************
//**                                                                  **
//**     Copyright (c) 2018 Shanghai Zhaoxin Semiconductor Co., Ltd.  **
//**                                                                  **
//**********************************************************************
//**********************************************************************

#include "Vt.h"
#include "CpuIa32.h"
#include "AsiaIoLib.h"

VOID
S5Reset (
    VOID
);

/*===================================================================
Function   : IsVtSupport()
Precondition :
Input      :  void
Output     : BOOLEAN:
                         TRUE:  this cpu  support VT(Vitrual Machine extensions) function
                          FALSE: this cpu does not support VT function
Purpose    : judge if cpu support VT function
Reference  : None
note:
===================================================================*/

BOOLEAN IsVtSupport()
{
    EFI_CPUID_REGISTER CpuidInfo;

	 
    //Vt flag bit in CPUID[1].ECX[5]
    EfiCpuid(EFI_CPUID_VERSION_INFO, &CpuidInfo);
    if (CpuidInfo.RegEcx & ACPU_VMX_FLAG)
        return TRUE;
    else
        return FALSE;
}

/*===================================================================
Function   : EnableVt()
Precondition :
Input      : void
Output     : void
Purpose    : Enable  cpu's VT(Vitrual Machine extensions) function
Reference  : None
note:
===================================================================*/

EFI_STATUS EnableVt()
{
    UINT64   MsrVal;

    MsrVal = EfiReadMsr(EFI_MSR_IA32_FEATURE_CONTROL);
    //if VMX lock bit not set,we can enable vmx
    if ((MsrVal & ACPU_VMX_LOCK) == 0)
    {
        MsrVal |= ACPU_VMX_ENABLE;
        EfiWriteMsr(EFI_MSR_IA32_FEATURE_CONTROL, MsrVal);
    }
    else
    {
        //if locked VMX and VMX not enable,we should reset the system
        if ((MsrVal & ACPU_VMX_ENABLE)==0)
            S5Reset();
    }
    return EFI_SUCCESS;
}

/*===================================================================
Function   : disableVt()
Precondition :
Input      : void
Output     : void
Purpose    : disable  cpu's VT(Vitrual Machine extensions) function
Reference  : None
note:
===================================================================*/


EFI_STATUS DisableVt()
{
    UINT64  MsrVal;

    MsrVal = EfiReadMsr(EFI_MSR_IA32_FEATURE_CONTROL);

    //if VMX lock bit not set,we can disable vmx
    if ((MsrVal & ACPU_VMX_LOCK) == 0)
    {
        MsrVal &=  ~ACPU_VMX_ENABLE;
        EfiWriteMsr(EFI_MSR_IA32_FEATURE_CONTROL, MsrVal);
    }
    else
    {
        //if locked VMX and VMX  enable,we should reset the system
        if ((MsrVal & ACPU_VMX_ENABLE)!=0)
            S5Reset();
    }
    return EFI_SUCCESS;
}

VOID LockFeatureBit()
{
    UINT64  MsrVal;

    MsrVal = EfiReadMsr(EFI_MSR_IA32_FEATURE_CONTROL);

    //if lock bit not set,we can set it
    if ((MsrVal & ACPU_VMX_LOCK) == 0)
    {
        MsrVal |= ACPU_VMX_LOCK;
        EfiWriteMsr(EFI_MSR_IA32_FEATURE_CONTROL, MsrVal);
    }
}

/*===================================================================
Function   : VtInitialize()
Precondition :
Input      :  VtEnable:
                              TRUE: enable this feature
                              FALSE: disable this feature
Output     : EFI_STATUS
                         EFI_SUPPORTED: this cpu don't support this function
                         EFI_SUCCESS:     initialized this feature
Purpose    : according to the input set cpu's function
Reference  : None
note:
===================================================================*/

EFI_STATUS VtInitialize(BOOLEAN VtEnable)
{
    if (!IsVtSupport())
        return EFI_UNSUPPORTED;

    if (VtEnable)
        EnableVt();
    else
        DisableVt();

    LockFeatureBit();

    return EFI_SUCCESS;
}

VOID
S5Reset (
)
{
	AsiaIoWrite8(0xcf9,S5RESET);
    //I oOutput8 (0xcf9, S5RESET);
//    __asm
//    {
//        mov al, S5RESET
//        mov dx,0xCf9
//        out dx,al
//    }
}
