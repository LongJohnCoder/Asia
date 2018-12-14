//**********************************************************************
//**********************************************************************
//**                                                                  **
//**     Copyright (c) 2018 Shanghai Zhaoxin Semiconductor Co., Ltd.  **
//**                                                                  **
//**********************************************************************
//**********************************************************************

#include "DramInit.h"
#include "DramBlock.h"

#ifdef ZX_TXT_SUPPORT
#include "DramSetupECC.h"
#include "AsiaVariable.h"

EFI_GUID gAsiaVariableGuid = ASIA_VARIABLE_GUID;
extern EFI_GUID  gPeiReadOnlyVariable2PpiGuid1;
extern EFI_GUID  gPeiReadOnlyVariablePpiGuid1;

EFI_STATUS DramBlockClean(
    IN EFI_PEI_SERVICES **PeiServices,
    IN DRAM_ATTRIBUTE *DramAttr
){
    EFI_STATUS            Status;
    ASIA_VARIABLE         TxtVariable;
	UINTN                 VarSize;

#if (PI_SPECIFICATION_VERSION < 0x00010000)
	EFI_PEI_READ_ONLY_VARIABLE_PPI *VarPpi;
#else
	EFI_PEI_READ_ONLY_VARIABLE2_PPI *Var2Ppi;
#endif

#if (PI_SPECIFICATION_VERSION < 0x00010000)
	Status = (*PeiServices)->LocatePpi(PeiServices, &gPeiReadOnlyVariablePpiGuid1, 0, NULL, (VOID **)&VarPpi);
	VarSize = sizeof(ASIA_VARIABLE);
	Status = VarPpi->PeiGetVariable(
		PeiServices,
		ASIA_VARIABLE_NAME,
		&gAsiaVariableGuid,
		NULL,
		&VarSize,
		&TxtVariable);
#else
	Status = (*PeiServices)->LocatePpi(PeiServices, &gPeiReadOnlyVariable2PpiGuid1, 0, NULL, (VOID **)&Var2Ppi);
	VarSize = sizeof(ASIA_VARIABLE);
	Status = Var2Ppi->GetVariable(
		Var2Ppi,
		ASIA_VARIABLE_NAME,
		&gAsiaVariableGuid,
		NULL,
		&VarSize,
		&TxtVariable);
#endif
	ASSERT_PEI_ERROR(PeiServices, Status);

	if (TxtVariable.TXT == TRUE)
	{
        UINT8 Cmos0E;
        PEI_DEBUG((PeiServices, EFI_D_INFO, "Clear Mem for TXT \n"));
        __asm {
            mov al, 0eh
            out 70h, al
            in al, 71h
            mov Cmos0E, al
        }

        PEI_DEBUG((PeiServices, EFI_D_INFO, "CMOS 0E=%x  \n", Cmos0E));
        if (Cmos0E & 0x01)
        {
            PEI_DEBUG((PeiServices, EFI_D_INFO, "CALL clearmem \n"));
            ClearMem(PeiServices, DramAttr);
            Cmos0E &= 0xfe;
            __asm {
                mov al, 0eh
                out 70h, al
                mov al, Cmos0E
                out 71h, al
            }
        }
        PEI_DEBUG((PeiServices, EFI_D_INFO, "CMOS2 0E=%x  \n", Cmos0E));
    }

    return Status;
}
#endif