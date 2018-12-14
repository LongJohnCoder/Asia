//**********************************************************************
//**********************************************************************
//**                                                                  **
//**     Copyright (c) 2018 Shanghai Zhaoxin Semiconductor Co., Ltd.  **
//**                                                                  **
//**********************************************************************
//**********************************************************************

all : AsiaCpuPortingLib

AsiaCpuPortingLib : $(BUILD_DIR)\AsiaCpuPortingLib.mak AsiaCpuPortingLibBin

!IF "$(x64_BUILD)" == "1"
$(BUILD_DIR)\AsiaCpuAccess.obj : $(ASIA_DIR)\Porting\Library\CPU\$(ASIA_CPUTYPE)\ia32\CpuIa32.asm $(ASIA_DIR)\Porting\Library\CPU\$(ASIA_CPUTYPE)\x64\CpuX64.asm
	ML /nologo /c /Cx /Zd /coff /Fo$(BUILD_DIR)\IA32\AsiaCpuAccess.obj $(ASIA_DIR)\Porting\Library\CPU\$(ASIA_CPUTYPE)\ia32\CpuIa32.asm
	$(ASMx64) /nologo /W3 /WX /c /Fo$@ $(ASIA_DIR)\Porting\Library\CPU\$(ASIA_CPUTYPE)\x64\CpuX64.asm
!ELSE
$(BUILD_DIR)\AsiaCpuAccess.obj : $(ASIA_DIR)\Porting\Library\CPU\$(ASIA_CPUTYPE)\ia32\CpuIa32.asm
	ML /nologo /c /Cx /Zd /coff /Fo$@ $**
!ENDIF

$(BUILD_DIR)\AsiaIoLib.Lib : AsiaIoLib

$(BUILD_DIR)\AsiaCpuPortingLib.mak : $(ASIA_DIR)\Porting\Library\CPU\$(ASIA_CPUTYPE)\$(@B).cif $(ASIA_DIR)\Porting\Library\Cpu\$(ASIA_CPUTYPE)\$(@B).mak $(BUILD_RULES)
	$(CIF2MAK) $(ASIA_DIR)\Porting\Library\CPU\$(ASIA_CPUTYPE)\$(@B).cif $(CIF2MAK_DEFAULTS)

AsiaCpuPortingLibBin : $(BUILD_DIR)\AsiaIoLib.Lib $(BUILD_DIR)\AsiaCpuAccess.obj
	$(MAKE) /$(MAKEFLAGS) $(BUILD_DEFAULTS)\
		/f $(BUILD_DIR)\AsiaCpuPortingLib.mak all\
		TYPE=LIBRARY \
		"CFLAGS=$(CFLAGS) /X" \
		"MY_INCLUDES=/I$(ASIA_DIR)\IBV\Common\CPU\include \
		/I$(ASIA_DIR)\IBV\Common\Framework\Include \
		/I$(ASIA_DIR)\IBV\Common\Framework \
		/I$(ASIA_DIR)\IBV\Common\Efi \
		/I$(ASIA_DIR)\IBV\Common\Efi\Include \
		/I$(ASIA_DIR)\IBV\Common\Include \
!IF "$(x64_BUILD)"=="1"
		/I$(ASIA_DIR)\IBV\Common\Include\x64 \
!ELSE 
		/I$(ASIA_DIR)\IBV\Common\Include\IA32 \
!ENDIF
		/I$(ASIA_DIR)\IBV\Common\Library\Pei\Include \
		/I$(ASIA_DIR)\IBV\Common\Library\Dxe\Include \
		/I$(ASIA_DIR)\IBV\Common\Include\Pei \
		/I$(ASIA_DIR)\IBV\Common\Library\Pei\Include \
		/I$(ASIA_DIR)\Foundation\Library\include \
		/I$(ASIA_DIR)\Interface" 
!IF "$(x64_BUILD)"=="1"
	$(MAKE) /$(MAKEFLAGS) BUILD_ROOT=$(BUILD_DIR) "EXT_OBJS=$(**:Build\=Build\IA32\)" PROJECT_DIR=$(PROJECT_DIR)\
		/f $(BUILD_DIR)\AsiaCpuPortingLib.mak all\
		BUILD_DIR=$(BUILD_DIR)\IA32 \
		TYPE=PEI_LIBRARY \
		"CFLAGS=$(CFLAGS) /X" \
		"MY_INCLUDES=/I$(ASIA_DIR)\IBV\Common\CPU\include \
		/I$(ASIA_DIR)\IBV\Common\Framework\Include \
		/I$(ASIA_DIR)\IBV\Common\Framework \
		/I$(ASIA_DIR)\IBV\Common\Efi \
		/I$(ASIA_DIR)\IBV\Common\Efi\Include \
		/I$(ASIA_DIR)\IBV\Common\Include \
		/I$(ASIA_DIR)\IBV\Common\Include\IA32 \
		/I$(ASIA_DIR)\IBV\Common\Library\Pei\Include \
		/I$(ASIA_DIR)\IBV\Common\Library\Dxe\Include \
		/I$(ASIA_DIR)\IBV\Common\Include\Pei \
		/I$(ASIA_DIR)\IBV\Common\Library\Pei\Include \
		/I$(ASIA_DIR)\Foundation\Library\include \
		/I$(ASIA_DIR)\Interface" 
!ENDIF
#**********************************************************************
#**********************************************************************
#**                                                                  **
#**        (C)Copyright 1985-2012, American Megatrends, Inc.         **
#**                                                                  **
#**                       All Rights Reserved.                       **
#**                                                                  **
#**             6145-F Northbelt Pkwy, Norcross, GA 30071            **
#**                                                                  **
#**                       Phone: (770)-246-8600                      **
#**                                                                  **
#**********************************************************************
#**********************************************************************
