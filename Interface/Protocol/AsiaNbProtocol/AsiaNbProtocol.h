//**********************************************************************
//**********************************************************************
//**                                                                  **
//**     Copyright (c) 2015 Shanghai Zhaoxin Semiconductor Co., Ltd.  **
//**                                                                  **
//**********************************************************************
//**********************************************************************
#ifndef ASIA_NB_PROTOCOL_H
#define ASIA_NB_PROTOCOL_H

#define EFI_ASIA_NB_PROTOCOL_GUID \
{ \
  0x8369b7c, 0xa839, 0x5256, 0x94, 0xb7, 0x87, 0x63, 0x55, 0xd5, 0x59, 0xd8 \
}

typedef struct _EFI_ASIA_NB_PROTOCOL EFI_ASIA_NB_PROTOCOL;

typedef
EFI_STATUS (EFIAPI *EFI_ASIA_NB_PROTOCOL_INIT) (
  IN EFI_ASIA_NB_PROTOCOL *This
  );

typedef
EFI_STATUS (EFIAPI *EFI_ASIA_NB_PROTOCOL_PREPROCESS_PCI_CONTROLLER) (
  IN EFI_ASIA_NB_PROTOCOL *This,
  IN EFI_PCI_ROOT_BRIDGE_IO_PROTOCOL *PciRootBridgeIo,
  IN EFI_PCI_ROOT_BRIDGE_IO_PROTOCOL_PCI_ADDRESS PciAddress,
  IN EFI_PCI_CONTROLLER_RESOURCE_ALLOCATION_PHASE Phase
  );

typedef
EFI_STATUS (EFIAPI *EFI_ASIA_NB_PROTOCOL_POST_PCI_INIT) (
  IN EFI_ASIA_NB_PROTOCOL *This,
  IN EFI_PCI_IO_PROTOCOL *PciIo
  );

typedef struct _EFI_ASIA_NB_PROTOCOL {
  VOID* NbCfg;
  EFI_ASIA_NB_PROTOCOL_INIT PrePciInit;
  EFI_ASIA_NB_PROTOCOL_PREPROCESS_PCI_CONTROLLER PreprocessPciController;
  EFI_ASIA_NB_PROTOCOL_POST_PCI_INIT PostPciInit;
  EFI_ASIA_NB_PROTOCOL_INIT PreBootInit;
} EFI_ASIA_NB_PROTOCOL;

extern EFI_GUID gAsiaNbProtocolGuid;

#endif