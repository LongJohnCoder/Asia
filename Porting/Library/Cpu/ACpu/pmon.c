//**********************************************************************
//**********************************************************************
//**                                                                  **
//**     Copyright (c) 2018 Shanghai Zhaoxin Semiconductor Co., Ltd.  **
//**                                                                  **
//**********************************************************************
//**********************************************************************



#include "pmon.h"
#include "EfiCommonLib.h"

BOOLEAN   IsPmonSupport(VOID)
{
	return TRUE;
}

/*===================================================================
Function   : PmonInitialize()
Precondition :
Input      :  
Output     : EFI_STATUS
                         EFI_SUPPORTED: this cpu don't support this function
                         EFI_SUCCESS:     initialized this feature
Purpose    : according to the input set pmon feature
Reference  : None
note:
===================================================================*/
EFI_STATUS PmonInitialize(BOOLEAN PmonEnable, UINT8 VrmSupport)
{
    UINT64    MsrVal;
    UINT8     MaxVid;
    UINT8     MaxFid;
    
    if (!IsPmonSupport()) {
      return EFI_UNSUPPORTED;
    }
    
    if(PmonEnable == FALSE) {
      return EFI_UNSUPPORTED;
    }
    
    // first check CPU support Pmon
    MsrVal = EfiReadMsr(0x1246);
    if ((MsrVal & PMON_SUPPORT_BIT) == 0) {
      return EFI_UNSUPPORTED;
    }
    
    if (VrmSupport == 1) {
      // Indicate 1 Phase VRM
      MsrVal = EfiReadMsr(0x1234);
      MsrVal &= (~((UINT64)1<<4));
      EfiWriteMsr(0x1234, MsrVal);
    }
    
    if (VrmSupport >= 2) {
      // Indicate 2 Phase VRM
      MsrVal = EfiReadMsr(0x1234);
      MsrVal |= ((UINT64)1<<4);
      EfiWriteMsr(0x1234, MsrVal);
    }

    // Adding VRM-3 support
    if (VrmSupport == 3) {
      // Indicate 2 Phase VRM
      MsrVal = EfiReadMsr(0x1234);
      MsrVal |= ((UINT64)1<<5);
      EfiWriteMsr(0x1234, MsrVal);
    }
    
    MsrVal = EfiReadMsr(0x1234);
    MsrVal |= 1;
    EfiWriteMsr(0x1234, MsrVal);

    // change to MAX P-state after pmon setting
    MsrVal = EfiReadMsr(0x198);
    MaxVid = (UINT8)(RShiftU64(MsrVal, 32) & 0xFF);
    MaxFid = (UINT8)(RShiftU64(MsrVal, 40) & 0xFF);
    MsrVal = 0;
    MsrVal = (MaxFid << 8)|MaxVid;
    EfiWriteMsr(0x199, MsrVal);
    
    return EFI_SUCCESS;
} 
