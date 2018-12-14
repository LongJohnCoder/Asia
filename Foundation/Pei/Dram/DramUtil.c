//**********************************************************************
//**********************************************************************
//**                                                                  **
//**     Copyright (c) 2015 Shanghai Zhaoxin Semiconductor Co., Ltd.  **
//**                                                                  **
//**********************************************************************
//**********************************************************************
#include "Pei.h"
#include "DramUtil.h"
#include "PeiDebug.h"
#include "SbLibPpi.h"
#include "AsiaIoLib.h"
#include <AsiaSbPeim.h>

/*
 * Wait n microsecond.
 */

/*===================================================================
Function   : WaitForMicroSec()
Precondition :
Input      :  PeiServieces
                MicroSeconds: the time to wait in microseconds unit
Output     : void
Purpose    :
Reference  : None
===================================================================*/
VOID WaitForMicroSec(IN struct _EFI_PEI_SERVICES **PeiServices,
                  IN UINTN   MicroSeconds)
/*
    This piece of code will cost 300 micro seconds at least. 
    So if the MicroSecends is little than 300, the delay will NOT be exactly.
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

    if (MicroSeconds == 0) {
        return ;
    }

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
    Ticks = MicroSeconds * 358 / 100 + OriginalTick + 1;

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
    while (Counts != 0) {
        pAsiaSbLibPpi->GetAcpiTimerValue(PeiServices, pAsiaSbLibPpi, &CurrentTick, NULL);

        if (CurrentTick <= OriginalTick) {
            Counts--;
        }

        OriginalTick = CurrentTick;
    }

    while ((RemainingTick > CurrentTick) && (OriginalTick <= CurrentTick)) {
        OriginalTick  = CurrentTick;
        pAsiaSbLibPpi->GetAcpiTimerValue(PeiServices, pAsiaSbLibPpi, &CurrentTick, NULL);
    }

    return;
}

/*===================================================================
Function   : write_phys()
Precondition :
Input      :  addr
                  value
Output     : void
Purpose    :
Reference  : None
===================================================================*/

VOID  write_phys(UINT32 addr, UINT32 value)
{
    volatile UINT32 *ptr;
    ptr = (VOID *)addr;
    *ptr = value;
}

/*===================================================================
Function   : read_phys()
Precondition :
Input      :  addr
Output     : UINT32
Purpose    :
Reference  : None
===================================================================*/

UINT32 read_phys(UINT32 addr)
{
    volatile UINT32 *ptr;
    ptr = (VOID *)addr;
    return *ptr;
}

/*===================================================================
Function   : DramBaseTest()
Precondition : this function used to verify memory
Input      :  PeiServices:pointer point to pointer that point to _EFI_PEI_SERVICES structor
                 BaseAdd,
                 length,
                 mode
Output     : UINT32
Purpose    :write into and read out to verify if dram is correct
Reference  : None
===================================================================*/
BOOLEAN DramBaseTest(IN struct _EFI_PEI_SERVICES **PeiServices,
                     IN UINT32                        BaseAdd, 
                     IN UINT32                        Length,
                     IN DRAM_TEST_MODE                Mode,
                     IN BOOLEAN                       PrintFlag)
{
    UINT32 TestSpan;
    UINT32 Data,Address;
    INT8 i, TestCount;
    BOOLEAN Flag = TRUE;


    //decide the test mode is continous or step
    if (Mode == EXTENSIVE)
    {
        //the test mode is continuos and must test each unit
        TestSpan = 4;
        TestCount = 1;
    }
    else if (Mode == SPARE)
    {
        // the test mode is step and test some unit
        TestSpan = STEPSPAN;
        TestCount = TESTCOUNT;
    }
    else
    {
        PEI_DEBUG((PeiServices, EFI_D_INFO, "the test mode is error\r"));
        return FALSE;
    }

	PEI_DEBUG((PeiServices, EFI_D_INFO,"%a(%d)+++++ BaseAddress = %x    Length = %x  TestSpan = %x \r",__FILE__,__LINE__, BaseAdd, Length, TestSpan));

    //write each test unit the value with TEST_PATTERN
    for (Address = BaseAdd; Address < BaseAdd + Length; Address += TestSpan)
    {
        for ( i = 0; i < TestCount; i++)
            write_phys(Address + i *4, TEST_PATTERN);

        if (PrintFlag)
        {
            //if ((UINT32)Address % 0x10000000 == SkipCacheRange)
            //{
            //    PEI_DEBUG((PeiServices, EFI_D_INFO, "Write in Addr = %x\r", (UINT32)Address));
            //}
        }
    }

	PEI_DEBUG((PeiServices, EFI_D_INFO,"%a(%d)+++++++++++++++++++ \r",__FILE__,__LINE__));
    //compare each test unit with the value of TEST_PATTERN
    //and write it with compliment of TEST_PATTERN
    for (Address = BaseAdd; Address < BaseAdd + Length; Address += TestSpan)
    {
        for ( i = 0; i < TestCount; i++)
        {
            Data = read_phys(Address + i * 4);
            write_phys(Address + i * 4, (UINT32)(~TEST_PATTERN));
            if (Data != TEST_PATTERN)
            {
                PEI_DEBUG((PeiServices, EFI_D_ERROR, "1.ERROR !!!!! %08x : %08x\r", (UINT32)(Address + i*4), Data));
                Flag = FALSE;
                break;
            }
        }
        if (PrintFlag)
        {
            //if ((UINT32)Address % 0x10000000 ==0)
            //{
            //    PEI_DEBUG((PeiServices, EFI_D_INFO, "Write in Addr = %x\r", (UINT32)Address));
            //}
        }
        if(!Flag)
            break;
    }

	PEI_DEBUG((PeiServices, EFI_D_INFO,"%a(%d)+++++++++++++++++++ \r",__FILE__,__LINE__));
    //compare each test unit with the value of ~TEST_PATTERN
    for (Address = BaseAdd; Address < BaseAdd + Length; Address += TestSpan)
    {
        for (i= (UINT8)(TestCount - 1); i >= 0; i--)
        {
            Data = Data = read_phys(Address + i * 4);
            if (Data != ~TEST_PATTERN)
            {
                PEI_DEBUG((PeiServices, EFI_D_INFO, "2.ERROR !!!!! %08x : %08x\r", (UINT32)(Address + i*4), Data));
                Flag = FALSE;
                break;
            }
        }
        if(!Flag)
            break;
    }
	PEI_DEBUG((PeiServices, EFI_D_INFO,"%a(%d)+++++++++++++++++++ \r",__FILE__,__LINE__));
    /*
    if(!Flag)
    {
    for (Address = BaseAdd; Address < BaseAdd + Length; Address += TestSpan)
        {
        for ( i = 0; i < TestCount; i++)
            write_phys(Address + i *4, 0);
        }
    return FALSE;
    }
    */

    return TRUE;
}
/*===================================================================
Function   : DumpRegisters()
Precondition :
Input      :  PeiServices:pointer point to pointer that point to _EFI_PEI_SERVICES structor
                pPCIPPI,
                DevNum,
                FuncNum
Output     : Void
Purpose    :
Reference  : None
===================================================================*/

VOID DumpRegisters(
    IN struct _EFI_PEI_SERVICES **PeiServices,
#if (PI_SPECIFICATION_VERSION < 0x00010000) 
    IN PEI_PCI_CFG_PPI *pPCIPPI,
#else
    IN EFI_PEI_PCI_CFG2_PPI *pPCIPPI,
#endif
    IN INTN DevNum,
    IN INTN FuncNum
)
{
    INTN i, j;
    UINT64 Addr;
    UINT8 ByteVal;

    ByteVal = 0;
    PEI_DEBUG((PeiServices, EFI_D_INFO,"\n Dev %02x Fun %02x\n", DevNum, FuncNum));
    PEI_DEBUG((PeiServices, EFI_D_INFO,"\n    00 01 02 03 04 05 06 07 08 09 0a 0b 0c 0d 0e 0f\n"));
    PEI_DEBUG((PeiServices, EFI_D_INFO,"---------------------------------------------------\n"));
    for (i=0; i<0x10; i++)
    {
        PEI_DEBUG((PeiServices, EFI_D_INFO,"%02x  ", i));
        for (j=0; j<0x10; j++)
        {
            Addr = PEI_PCI_CFG_ADDRESS(0, DevNum, FuncNum, i*0x10+j);
            pPCIPPI->Read(PeiServices, pPCIPPI, PeiPciCfgWidthUint8, Addr, &ByteVal);
            PEI_DEBUG((PeiServices, EFI_D_INFO, "%02x ", ByteVal));
        }
        PEI_DEBUG((PeiServices, EFI_D_INFO,"\n"));
    }

    return;
}

VOID DumpPcieRegisters(
    IN struct _EFI_PEI_SERVICES **PeiServices,
#if (PI_SPECIFICATION_VERSION < 0x00010000) 
    IN PEI_PCI_CFG_PPI *pPCIPPI,
#else
    IN EFI_PEI_PCI_CFG2_PPI *pPCIPPI,
#endif
    IN UINT64 PcieBaseAddr,
    IN UINTN  DevNum,
    IN UINTN  FuncNum,
    IN UINTN  RegNum,
    IN UINTN  Count
	)
{
    UINTN i;
    UINT64 Addr;
    UINT8 ByteVal;

    ByteVal = 0;
	//make sure RegNum aligned to 16bytes
    i = RegNum & 0x0F;
	RegNum = RegNum - i;
	Count = Count + i;
    PEI_DEBUG((PeiServices, EFI_D_INFO,"\n Dev %02x Fun %02x Reg %02x RegCount %02x\n", \
		                                   DevNum, FuncNum,RegNum,Count));

	for (i = 0; i < Count; i++){
		if ((i & 0x0F) == 0)
			PEI_DEBUG((PeiServices, EFI_D_INFO,"%02x  ", RegNum + i));	
		Addr = AsiaPciAddress(0, (UINT8)DevNum, (UINT8)FuncNum, (UINT16)(RegNum + i));
		ByteVal = AsiaPcieRead8(PcieBaseAddr, Addr);
		PEI_DEBUG((PeiServices, EFI_D_INFO, "%02x	", ByteVal));
		if ((i & 0x0F) == 0x0F)
			PEI_DEBUG((PeiServices, EFI_D_INFO,"\n "));	
	}
    return;
}


UINT16 ShiftToMaskBit(
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

UINT8  RegisterOffset8bit(
	IN      UINT8                			MaskBit)
{
    UINT8 bIndex, bBuffer=0;
	
    for (bIndex=0; bIndex<8; bIndex++)
    {
        bBuffer = MaskBit;
        if ((bBuffer >> bIndex) & 0x01)
            break;
    }

	return bIndex;
}

UINT16  RegisterOffset16bit(
	IN      UINT16                			MaskBit)
{
    UINT16 bIndex, bBuffer=0;
	
    for (bIndex=0; bIndex<16; bIndex++)
    {
        bBuffer = MaskBit;
        if ((bBuffer >> bIndex) & 0x01)
            break;
    }

	return bIndex;
}

