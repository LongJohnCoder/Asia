;//**********************************************************************
;//**********************************************************************
;//**                                                                  **
;//**     Copyright (c) 2015 Shanghai Zhaoxin Semiconductor Co., Ltd.  **
;//**                                                                  **
;//**********************************************************************
;//**********************************************************************
.686
.MODEL FLAT,C
.CODE

UINT8 TYPEDEF BYTE
UINT16 TYPEDEF WORD
UINT32 TYPEDEF DWORD
UINT64 TYPEDEF QWORD

; UINT8 AsiaIoRead8(UINT16 Address)
AsiaIoRead8 PROC PUBLIC Address:UINT16
  mov dx, Address
  in al, dx
  ret
AsiaIoRead8 ENDP

; VOID AsiaIoWrite8(UINT16 Address, UINT8 Data)
AsiaIoWrite8 PROC PUBLIC Address:UINT16, Data:UINT8
  mov al, Data
  mov dx, Address
  out dx, al
  ret
AsiaIoWrite8 ENDP

; UINT16 AsiaIoRead16(UINT16 Address)
AsiaIoRead16 PROC PUBLIC Address:UINT16
  mov dx, Address
  in ax, dx
  ret
AsiaIoRead16 ENDP

; VOID AsiaIoWrite16(UINT16 Address, UINT16 Data)
AsiaIoWrite16 PROC PUBLIC Address:UINT16, Data:UINT16
  mov ax, Data
  mov dx, Address
  out dx, ax
  ret
AsiaIoWrite16 ENDP

; UINT32 AsiaIoRead32(UINT16 Address)
AsiaIoRead32 PROC PUBLIC Address:UINT16
  mov dx, Address
  in eax, dx
  ret
AsiaIoRead32 ENDP

; VOID AsiaIoWrite32(UINT16 Address, UINT32 Data)
AsiaIoWrite32 PROC PUBLIC Address:UINT16, Data:UINT32
  mov eax, Data
  mov dx, Address
  out dx, eax
  ret
AsiaIoWrite32 ENDP
END