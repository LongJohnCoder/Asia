//**********************************************************************
//**********************************************************************
//**                                                                  **
//**     Copyright (c) 2015 Shanghai Zhaoxin Semiconductor Co., Ltd.  **
//**                                                                  **
//**********************************************************************
//**********************************************************************
#include "AsiaNbDxe.h"
#include "EfiScriptLib.h"
#include "EfiDriverLib.h"

EFI_HANDLE gImageHandle = NULL;
static EFI_GUID mAsiaNbProtocolGuid = EFI_ASIA_NB_PROTOCOL_GUID;

STATIC EFI_ASIA_NB_PROTOCOL gAsiaNbProtocol =
{
    NULL,
    AsiaNbDxePrePciInit,
    AsiaNbDxePreprocessPciController,
    AsiaNbDxePostPciInit,
    AsiaNbDxePreBootInit,
};

EFI_STATUS
AsiaNbDxeEntryPoint (
    IN EFI_HANDLE ImageHandle,
    IN EFI_SYSTEM_TABLE *SystemTable
)
{
  EFI_STATUS Status;
  EFI_HANDLE Handle = NULL;

  gImageHandle = ImageHandle; 

  DxeInitializeDriverLib(ImageHandle, SystemTable);
  INITIALIZE_SCRIPT(ImageHandle, SystemTable);

	DEBUG((EFI_D_ERROR, "%a(%d) AsiaNbDxe Entrypoint ++++++ +++++\n",__FILE__,__LINE__));

    Status = GetAsiaNbCfgFromHob(&(gAsiaNbProtocol.NbCfg));
  if(EFI_ERROR(Status))
      return Status;
  Status = gBS->InstallProtocolInterface (
               &Handle,
                 &mAsiaNbProtocolGuid,
               EFI_NATIVE_INTERFACE,
                 &gAsiaNbProtocol
               );

  return Status;
}