//**********************************************************************
//**********************************************************************
//**                                                                  **
//**     Copyright (c) 2018 Shanghai Zhaoxin Semiconductor Co., Ltd.  **
//**                                                                  **
//**********************************************************************
//**********************************************************************

#ifndef _CHX002_ASIA_VARIABLE_H_
#define _CHX002_ASIA_VARIABLE_H_

#ifndef ASIA_VARIABLE_GUID
#define ASIA_VARIABLE_GUID                                                               \
    {                                                                                  \
        0xF4BF17CC, 0x27A9, 0x48B9, { 0x9A, 0x83, 0xBE, 0x63, 0xF2, 0x55, 0x55, 0x95 } \
    }

extern EFI_GUID gAsiaVariableGuid;
#endif

#define ASIA_VARIABLE_NAME L"AsiaVariable"
typedef struct _ASIA_VARIABLE
{
    UINT8 TXT;
} ASIA_VARIABLE;



#endif