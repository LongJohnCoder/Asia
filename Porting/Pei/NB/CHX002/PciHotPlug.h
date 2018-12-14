/** @file
   ZX-E(CHX002) Asia NbPei library functions : PciHotPlug.h

   Copyright (c) 2018 Shanghai Zhaoxin Semiconductor Co., Ltd. 

**/


#ifndef __PCI_HOT_PLUG_H__
#define __PCI_HOT_PLUG_H__

/*
  P0.0 - AuxOn       OUT                          MASK
  P0.1 - AttButton   IN                           Latch
  P0.2 - Present     IN              0:Present
  P0.3 - CtrlOn      OUT                          MASK
  P0.4 - Fault       IN     
  P0.5 - Gpio5                                    MASK
  P0.6 - Led3        OUT                          MASK
  P0.7 - PcieClkEn   OUT                          MASK

  P1.0 - PcieRst     OUT
  P1.1 - Ctrl1LED2   OUT
  P1.2 - Ctrl2LED2   OUT
*/

#define PcieHotPlugSMBusAddr 0x20
#define Pcal6416_GPIO_DirOut 0
#define Pcal6416_GPIO_DirIn 1
#define IntUnMask 0
#define IntEnMask 1
#define Pcal6416_InputPort0 0x00
#define Pcal6416_InputPort1 0x01
#define Pcal6416_OutputPort0 0x02
#define Pcal6416_OutputPort1 0x03
#define Pcal6416_PolarityInvPort0 0x04
#define Pcal6416_PolarityInvPort1 0x05
#define Pcal6416_CfgPort0 0x06
#define Pcal6416_CfgPort1 0x07
#define Pcal6416_OutputDriveStrengthReg0_0 0x40
#define Pcal6416_OutputDriveStrengthReg0_1 0x41
#define Pcal6416_OutputDriveStrengthReg1_0 0x42
#define Pcal6416_OutputDriveStrengthReg1_1 0x43
#define Pcal6416_InputLatchReg0 0x44
#define Pcal6416_InputLatchReg1 0x45
#define Pcal6416_PullUpDnEnReg0 0x46
#define Pcal6416_PullUpDnEnReg1 0x44
#define Pcal6416_PullUpDnSelReg0 0x48
#define Pcal6416_PullUpDnSelReg1 0x49
#define Pcal6416_IntMaskReg0 0x4A
#define Pcal6416_IntMaskReg1 0x4B
#define Pcal6416_IntStatusReg0 0x4C
#define Pcal6416_IntStatusReg1 0x4D
#define Pcal6416_OutPortCfgReg 0x4F

EFI_STATUS 
	PcieHotPlugInit (
	  IN EFI_PEI_SERVICES  **PeiServices
		);

#endif
