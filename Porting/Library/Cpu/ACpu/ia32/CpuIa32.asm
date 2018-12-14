;//**********************************************************************
;//**********************************************************************
;//**                                                                  **
;//**     Copyright (c) 2018 Shanghai Zhaoxin Semiconductor Co., Ltd.  **
;//**                                                                  **
;//**********************************************************************
;//**********************************************************************
.686P
.MODEL FLAT,C
.CODE

UINT8 TYPEDEF BYTE
UINT16 TYPEDEF WORD
UINT32 TYPEDEF DWORD
UINT64 TYPEDEF QWORD

GetPState PROC  PUBLIC MsrIndex:UINT32, Indexer:UINT8
  push ecx
  push esi
  mov ecx, MsrIndex
  movzx esi, Indexer
  rdmsr
  pop esi
  pop ecx
  ret
GetPState ENDP

#ifdef ZX_TXT_SUPPORT
;------------------------------------------------------------------------------
; UINTN
; EFIAPI
; EfiReadCr4 (
;   VOID
;   );
;------------------------------------------------------------------------------
EfiReadCr4  PROC
    mov     eax, cr4
    ret
EfiReadCr4  ENDP

;------------------------------------------------------------------------------
; UINTN
; EFIAPI
; EfiWriteCr4 (
;   UINTN  Cr4
;   );
;------------------------------------------------------------------------------
EfiWriteCr4 PROC
    mov     eax, [esp + 4]
    mov     cr4, eax
    ret
EfiWriteCr4 ENDP
#endif

END