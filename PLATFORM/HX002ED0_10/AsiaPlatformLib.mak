#//**********************************************************************
#//**********************************************************************
#//**                                                                  **
#//**     Copyright (c) 2008-2015 Zhaoxin Technologies, Inc.               **
#//**                                                                  **
#//**********************************************************************
#//**********************************************************************
all : AsiaPlatformLib

AsiaPlatformLib : $(BUILD_DIR)\AsiaPlatformLib.mak AsiaPlatformLibBin

$(BUILD_DIR)\AsiaIoLib.lib : AsiaIoLib

$(BUILD_DIR)\AsiaPlatformLib.mak : $(ASIA_DIR)\platform\$(ASIA_MBTYPE)\$(@B).cif $(ASIA_DIR)\platform\$(ASIA_MBTYPE)\$(@B).mak $(BUILD_RULES)
	$(CIF2MAK) $(ASIA_DIR)\platform\$(ASIA_MBTYPE)\$(@B).cif $(CIF2MAK_DEFAULTS)

AsiaPlatformLibBin : $(BUILD_DIR)\AsiaIoLib.lib
	$(MAKE) /$(MAKEFLAGS) $(BUILD_DEFAULTS)\
		/f $(BUILD_DIR)\AsiaPlatformLib.mak all\
		TYPE=LIBRARY \
		"CFLAGS=$(CFLAGS) /X /D$(ASIA_DRAMTYPE)" \
		"EXTRA_INCLUDES=/I$(ASIA_DIR)\IBV\Common\Framework \
		/I$(ASIA_DIR)\IBV\Common\Framework\Include \
		/I$(ASIA_DIR)\IBV\Common\Efi\Include \
		/I$(ASIA_DIR)\IBV\Common\
		/I$(ASIA_DIR)\IBV\Common\library\dxe\include \
		/I$(ASIA_DIR)\IBV\Common\Efi \
		/I$(ASIA_DIR)\IBV\Common\Include \
		/I$(ASIA_DIR)\IBV\Common\Include\Pei \
!IF "$(x64_BUILD)"=="1"
		/I$(ASIA_DIR)\IBV\Common\Include\x64 \
!ELSE
		/I$(ASIA_DIR)\IBV\Common\Include\IA32 \
!ENDIF
		/I$(ASIA_DIR)\Porting\Pei\$(ASIA_DRAMTYPE)\$(ASIA_NBTYPE) \
		/I$(ASIA_DIR)\Interface \
		/I$(ASIA_DIR)\Foundation\Library\Include \
		/I$(ASIA_DIR)\Porting\Include \
		/I$(ASIA_DIR)\Foundation\Include \
		/I$(ASIA_DIR)\Foundation\Pei\Cpu \
		/I$(ASIA_DIR)\Ibv\Common\Cpu\Include \
		/I$(ASIA_DIR)\Foundation\Pei\Dram" \
		"LIBRARIES= \
!IF "$(x64_BUILD)"=="1"
		$(ASIA_DIR)\IBV\AMI\LibBin\x64\EfiScriptLib.lib \
		$(ASIA_DIR)\IBV\AMI\LibBin\x64\EfiDriverLib.lib"
!ELSE
		$(ASIA_DIR)\IBV\AMI\LibBin\Ia32\EfiScriptLib.lib \
		$(ASIA_DIR)\IBV\AMI\LibBin\Ia32\EfiDriverLib.lib"
!ENDIF
!IF "$(x64_BUILD)"=="1"
	$(MAKE) /$(MAKEFLAGS) BUILD_ROOT=$(BUILD_DIR) "EXT_OBJS=$(**:Build\=Build\IA32\)" PROJECT_DIR=$(PROJECT_DIR)\
		/f $(BUILD_DIR)\AsiaPlatformLib.mak all\
		BUILD_DIR=$(BUILD_DIR)\IA32 \
		TYPE=PEI_LIBRARY \
		"CFLAGS=$(CFLAGS) /X" \
		"EXTRA_INCLUDES=/I$(ASIA_DIR)\IBV\Common\Framework \
		/I$(ASIA_DIR)\IBV\Common\Framework\Include \
		/I$(ASIA_DIR)\IBV\Common\Efi\Include \
		/I$(ASIA_DIR)\IBV\Common\Efi \
		/I$(ASIA_DIR)\IBV\Common\
		/I$(ASIA_DIR)\IBV\Common\library\dxe\include \
		/I$(ASIA_DIR)\IBV\Common\Include \
		/I$(ASIA_DIR)\IBV\Common\Include\Pei \
		/I$(ASIA_DIR)\IBV\Common\Include\IA32 \
		/I$(ASIA_DIR)\Porting\Pei\Dram\$(ASIA_NBTYPE) \
		/I$(ASIA_DIR)\Interface \
		/I$(ASIA_DIR)\Foundation\Library\Include \
		/I$(ASIA_DIR)\Porting\Include \
		/I$(ASIA_DIR)\Foundation\Include \
		/I$(ASIA_DIR)\Foundation\Pei\Cpu \
		/I$(ASIA_DIR)\Ibv\Common\Cpu\Include \
		/I$(ASIA_DIR)\Foundation\Pei\Dram" \
             "LIBRARIES= \
!IF "$(x64_BUILD)"=="1"
		$(ASIA_DIR)\IBV\AMI\LibBin\x64\EfiScriptLib.lib \
		$(ASIA_DIR)\IBV\AMI\LibBin\x64\EfiDriverLib.lib"
!ELSE
		$(ASIA_DIR)\IBV\AMI\LibBin\Ia32\EfiScriptLib.lib \
		$(ASIA_DIR)\IBV\AMI\LibBin\Ia32\EfiDriverLib.lib"
!ENDIF		
!ENDIF