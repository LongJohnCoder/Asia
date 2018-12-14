#//**********************************************************************
#//**********************************************************************
#//**                                                                  **
#//**    Copyright (c) 2018 Shanghai Zhaoxin Semiconductor Co., Ltd.               **
#//**                                                                  **
#//**********************************************************************
#//**********************************************************************
all : AsiaIoLib

!IF "$(x64_BUILD)"=="1"
$(BUILD_DIR)\AsiaIoAccess.obj : $(ASIA_DIR)\Foundation\Library\AsiaIoLib\Ia32\AsiaIoAccess.asm $(ASIA_DIR)\Foundation\Library\AsiaIoLib\x64\AsiaIoAccess.asm
	ML /nologo /c /Cx /Zd /coff /Fo$(BUILD_DIR)\IA32\AsiaIoAccess.obj $(ASIA_DIR)\Foundation\Library\AsiaIoLib\Ia32\AsiaIoAccess.asm
	$(ASMx64) /nologo /W3 /WX /c /Fo$@ $(ASIA_DIR)\Foundation\Library\AsiaIoLib\x64\AsiaIoAccess.asm
!ELSE
$(BUILD_DIR)\AsiaIoAccess.obj : $(ASIA_DIR)\Foundation\Library\AsiaIoLib\Ia32\AsiaIoAccess.asm
	ML /nologo /c /Cx /Zd /coff /Fo$@ $**
!ENDIF

AsiaIoLib : $(BUILD_DIR)\AsiaIoLib.mak AsiaIoLibBin

$(BUILD_DIR)\AsiaIoLib.mak : $(ASIA_FOUNDATION_DIR)\Library\AsiaIoLib\$(@B).cif $(ASIA_FOUNDATION_DIR)\Library\AsiaIoLib\$(@B).mak $(BUILD_RULES)
	$(CIF2MAK) $(ASIA_FOUNDATION_DIR)\Library\AsiaIoLib\$(@B).cif $(CIF2MAK_DEFAULTS)

AsiaIoLibBin : $(BUILD_DIR)\AsiaIoAccess.obj
	$(MAKE) /$(MAKEFLAGS) $(BUILD_DEFAULTS)\
		/f $(BUILD_DIR)\AsiaIoLib.mak all\
		TYPE=LIBRARY\
		"CFLAGS=$(CFLAGS) /X" \
		"MY_INCLUDES=/I$(ASIA_DIR)\IBV\Common\Framework\Include \
		/I$(ASIA_DIR)\IBV\Common\CPU\include \
		/I$(ASIA_DIR)\IBV\Common\efi \
		/I$(ASIA_DIR)\IBV\Common\Efi\Include \
		/I$(ASIA_DIR)\IBV\Common\Include \
!IF "$(x64_BUILD)"=="1"
		/I$(ASIA_DIR)\IBV\Common\Include\x64 \
!ELSE 
		/I$(ASIA_DIR)\IBV\Common\Include\IA32 \
!ENDIF
		/I$(ASIA_DIR)\Foundation\Library\Include \
		/I$(ASIA_DIR)\Foundation\Include"
!IF "$(x64_BUILD)"=="1"
	$(MAKE) /$(MAKEFLAGS) BUILD_ROOT=$(BUILD_DIR) "EXT_OBJS=$(**:Build\=Build\IA32\)" PROJECT_DIR=$(PROJECT_DIR)\
		/f $(BUILD_DIR)\AsiaIoLib.mak all\
		BUILD_DIR=$(BUILD_DIR)\IA32 \
		TYPE=PEI_LIBRARY\
		"CFLAGS=$(CFLAGS) /X" \
		"MY_INCLUDES=/I$(ASIA_DIR)\IBV\Common\Framework\Include \
		/I$(ASIA_DIR)\IBV\Common\CPU\include \
		/I$(ASIA_DIR)\IBV\Common\efi \
		/I$(ASIA_DIR)\IBV\Common\Efi\Include \
		/I$(ASIA_DIR)\IBV\Common\Include \
		/I$(ASIA_DIR)\IBV\Common\Include\IA32 \
		/I$(ASIA_DIR)\Foundation\Library\Include \
		/I$(ASIA_DIR)\Foundation\Include" \
!ENDIF