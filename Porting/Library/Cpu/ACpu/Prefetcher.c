//**********************************************************************
//**********************************************************************
//**                                                                  **
//**     Copyright (c) 2018 Shanghai Zhaoxin Semiconductor Co., Ltd.  **
//**                                                                  **
//**********************************************************************
//**********************************************************************


#include "Prefetcher.h"
//#include "ACpuCommon.h"

/*===================================================================
Function   : PrefetcherInitialize()
Precondition :
Input      :  EpsEnable:
                 AdjacentCacheLinePrefetch:
                              TRUE: enable this feature
                              FALSE: disable this feature
Output     : EFI_STATUS
                         EFI_SUPPORTED: this cpu don't support this function
                         EFI_SUCCESS:     initialized this feature
Purpose    : according to the input set cpu's function
Reference  : None
note:       
===================================================================*/

EFI_STATUS PrefetcherInitialize(BOOLEAN HwPrefetcher, BOOLEAN AdjacentCacheLinePrefetch)
{
    UINT64    MsrVal;

   //Queue line disable bit in MSR[0x1A0].bit[9]
   MsrVal = EfiReadMsr(EFI_MSR_IA32_MISC_ENABLE);
   if (HwPrefetcher)
   	MsrVal &= ~ACPU_PREFETCH_QUEUE_DISABLE ;
   else
   	MsrVal |= ACPU_PREFETCH_QUEUE_DISABLE;

   //adjacent cache prefetch enable bit in MSR[0x1A0].bit[19]
   if(AdjacentCacheLinePrefetch)
   	MsrVal |= ACPU_ADJACENT_CACHE_PREFETCH_ENABLE;
   else
   	MsrVal &= ~ACPU_ADJACENT_CACHE_PREFETCH_ENABLE;

   EfiWriteMsr(EFI_MSR_IA32_MISC_ENABLE, MsrVal);

   return EFI_SUCCESS;
	
}