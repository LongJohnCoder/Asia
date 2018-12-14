;//**********************************************************************
;//**********************************************************************
;//**                                                                  **
;//**     Copyright (c) 2015 Shanghai Zhaoxin Semiconductor Co., Ltd.  **
;//**                                                                  **
;//**********************************************************************
;//**********************************************************************
  title   CpuIoAccess.asm

.CODE

;------------------------------------------------------------------------------
;  UINT8
;  CpuIoRead8 (
;    UINT16  Port   // rcx
;    )
;------------------------------------------------------------------------------
AsiaIoRead8 PROC        PUBLIC
    xor   eax, eax
    mov    dx, cx
    in     al, dx
    ret
AsiaIoRead8  ENDP

;------------------------------------------------------------------------------
;  VOID
;  CpuIoWrite8 (
;    UINT16  Port,    // rcx
;    UINT32  Data     // rdx
;    )
;------------------------------------------------------------------------------
AsiaIoWrite8 PROC        PUBLIC
    mov   eax, edx
    mov    dx, cx
    out    dx, al
    ret
AsiaIoWrite8  ENDP

;------------------------------------------------------------------------------
;  UINT16
;  CpuIoRead16 (
;    UINT16  Port   // rcx
;    )
;------------------------------------------------------------------------------
AsiaIoRead16 PROC        PUBLIC
    xor   eax, eax
    mov    dx, cx
    in     ax, dx
    ret
AsiaIoRead16  ENDP

;------------------------------------------------------------------------------
;  VOID
;  CpuIoWrite16 (
;    UINT16  Port,    // rcx
;    UINT32  Data     // rdx
;    )
;------------------------------------------------------------------------------
AsiaIoWrite16 PROC        PUBLIC
    mov   eax, edx
    mov    dx, cx
    out    dx, ax
    ret
AsiaIoWrite16  ENDP

;------------------------------------------------------------------------------
;  UINT32
;  CpuIoRead32 (
;    UINT16  Port   // rcx
;    )
;------------------------------------------------------------------------------
AsiaIoRead32 PROC        PUBLIC
    mov    dx, cx
    in    eax, dx
    ret
AsiaIoRead32  ENDP

;------------------------------------------------------------------------------
;  VOID
;  CpuIoWrite32 (
;    UINT16  Port,    // rcx
;    UINT32  Data     // rdx
;    )
;------------------------------------------------------------------------------
AsiaIoWrite32 PROC        PUBLIC
    mov   eax, edx
    mov    dx, cx
    out    dx, eax
    ret
AsiaIoWrite32  ENDP

END
