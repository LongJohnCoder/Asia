//**********************************************************************
//**********************************************************************
//**                                                                  **
//**     Copyright (c) 2015 Shanghai Zhaoxin Semiconductor Co., Ltd.  **
//**                                                                  **
//**********************************************************************
//**********************************************************************
#include "AsiaSbDxe.h"
#include "Protocol\AsiaSbProtocol\AsiaSbProtocol.h"
#include "EfiScriptLib.h"
#include "EfiDriverLib.h"

EFI_HANDLE gImageHandle = NULL;

static EFI_GUID mAsiaSbProtocolGuid = EFI_ASIA_SB_PROTOCOL_GUID;

STATIC EFI_ASIA_SB_PROTOCOL gAsiaSbProtocol =
{
  NULL,
  AsiaSbDxePrePciInit,
  AsiaSbDxePreprocessPciController,
  AsiaSbDxePostPciInit,
  AsiaSbDxePreBootInit,
};

EFI_STATUS
AsiaSbDxeEntryPoint (
  IN EFI_HANDLE ImageHandle,
  IN EFI_SYSTEM_TABLE *SystemTable
  )
{
  EFI_STATUS Status;
  EFI_HANDLE Handle = NULL;

  gImageHandle = ImageHandle;

  DxeInitializeDriverLib(ImageHandle, SystemTable);
  INITIALIZE_SCRIPT(ImageHandle, SystemTable);

  Status = GetAsiaSbCfgFromHob(&(gAsiaSbProtocol.SbCfg));

  Status = gBS->InstallProtocolInterface (
    &Handle,
    &mAsiaSbProtocolGuid,
    EFI_NATIVE_INTERFACE,
    &gAsiaSbProtocol
    );
  
  return Status;
}