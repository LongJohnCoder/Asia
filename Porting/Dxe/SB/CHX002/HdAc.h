/** @file
   ZX-E(CHX002) Asia SbDxe library functions : Hdac.h

   Copyright (c) 2018 Shanghai Zhaoxin Semiconductor Co., Ltd. 

**/
//**********************************************************************
//**********************************************************************
//**                                                                  **
//**     Copyright (c) 2015 Shanghai Zhaoxin Semiconductor Co., Ltd.  **
//**                                                                  **
//**********************************************************************
//**********************************************************************

#ifndef _HDAC_H_
#define _HDAC_H_

#include "Tiano.h"
#include "CHX002Cfg.h"

EFI_STATUS
InitAzaliaAudio (
  IN  ASIA_SB_CONFIGURATION             *SbCfg
);

typedef struct {
  UINT32                                  CodecID;
  UINT32                                  *PinInfo;
} HDAudio_Codec_Tbl;

#endif