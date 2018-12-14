//**********************************************************************
//**********************************************************************
//**                                                                  **
//**     Copyright (c) 2015 Shanghai Zhaoxin Semiconductor Co., Ltd.  **
//**                                                                  **
//**********************************************************************
//**********************************************************************
#ifndef ASIA_SB_PROTOCOL_H
#define ASIA_SB_PROTOCOL_H

#define EFI_ASIA_SB_PROTOCOL_GUID \
{ \
  0xdc38595f, 0x36b2, 0x4651, 0x83, 0xc0, 0xb2, 0x29, 0x7c, 0x7c, 0xac, 0x8b \
}

typedef struct _EFI_ASIA_SB_PROTOCOL EFI_ASIA_SB_PROTOCOL;

typedef
EFI_STATUS (EFIAPI *EFI_ASIA_SB_PROTOCOL_INIT) (
  IN EFI_ASIA_SB_PROTOCOL *This
  );

typedef
EFI_STATUS (EFIAPI *EFI_ASIA_SB_PROTOCOL_PREPROCESS_PCI_CONTROLLER) (
  IN EFI_ASIA_SB_PROTOCOL *This,
  IN EFI_PCI_ROOT_BRIDGE_IO_PROTOCOL *PciRootBridgeIo,
  IN EFI_PCI_ROOT_BRIDGE_IO_PROTOCOL_PCI_ADDRESS PciAddress,
  IN EFI_PCI_CONTROLLER_RESOURCE_ALLOCATION_PHASE Phase
  );

typedef
EFI_STATUS (EFIAPI *EFI_ASIA_SB_PROTOCOL_POST_PCI_INIT) (
  IN EFI_ASIA_SB_PROTOCOL *This,
  IN EFI_PCI_IO_PROTOCOL *PciIo
  );

typedef struct _EFI_ASIA_SB_PROTOCOL {
  VOID* SbCfg;
  EFI_ASIA_SB_PROTOCOL_INIT PrePciInit;
  EFI_ASIA_SB_PROTOCOL_PREPROCESS_PCI_CONTROLLER PreprocessPciController;
  EFI_ASIA_SB_PROTOCOL_POST_PCI_INIT PostPciInit;
  EFI_ASIA_SB_PROTOCOL_INIT PreBootInit;
} EFI_ASIA_SB_PROTOCOL;

extern EFI_GUID gAsiaSbProtocolGuid;

#endif