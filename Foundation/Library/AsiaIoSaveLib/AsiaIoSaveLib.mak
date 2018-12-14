#//**********************************************************************
#//**********************************************************************
#//**                                                                  **
#//**     Copyright (c) 2018 Shanghai Zhaoxin Semiconductor Co., Ltd.               **
#//**                                                                  **
#//**********************************************************************
#//**********************************************************************
all : AsiaIoSaveLib

AsiaIoSaveLib : $(BUILD_DIR)\AsiaIoSaveLib.mak AsiaIoSaveLibBin

$(BUILD_DIR)\AsiaIoLib.lib : AsiaIoLib

$(BUILD_DIR)\AsiaIoSaveLib.mak : $(ASIA_FOUNDATION_DIR)\Library\AsiaIoSaveLib\$(@B).cif $(ASIA_FOUNDATION_DIR)\Library\AsiaIoSaveLib\$(@B).mak $(BUILD_RULES)
	$(CIF2MAK) $(ASIA_FOUNDATION_DIR)\Library\AsiaIoSaveLib\$(@B).cif $(CIF2MAK_DEFAULTS)

AsiaIoSaveLibBin : $(BUILD_DIR)\AsiaIoLib.lib
	$(MAKE) /$(MAKEFLAGS) $(BUILD_DEFAULTS)\
		/f $(BUILD_DIR)\AsiaIoSaveLib.mak all\
		TYPE=LIBRARY \
		"CFLAGS=$(CFLAGS) /X /D$(ASIA_S3SUPPORT)" \
		"MY_INCLUDES=/I$(ASIA_DIR)\IBV\Common\Framework \
		/I$(ASIA_DIR)\IBV\Common\Framework\Include \
		/I$(ASIA_DIR)\IBV\Common\Efi \
		/I$(ASIA_DIR)\IBV\Common\Efi\Include \
		/I$(ASIA_DIR)\IBV\Common\Include \
		/I$(ASIA_DIR)\IBV\Common\Include\IA32 \
		/I$(ASIA_DIR)\IBV\Common\Library\Dxe\Include \
		/I$(ASIA_DIR)\Foundation\Library\Include \
		/I$(ASIA_DIR)\Foundation\Include" \
		"LIBRARIES= \
!IF "$(x64_BUILD)"=="1"
		$(ASIA_DIR)\IBV\AMI\LibBin\x64\EfiScriptLib.lib"
!ELSE
		$(ASIA_DIR)\IBV\AMI\LibBin\Ia32\EfiScriptLib.lib"
!ENDIF
!IF "$(x64_BUILD)"=="1"
	$(MAKE) /$(MAKEFLAGS) BUILD_ROOT=$(BUILD_DIR) "EXT_OBJS=$(**:Build\=Build\IA32\)" PROJECT_DIR=$(PROJECT_DIR)\
		/f $(BUILD_DIR)\AsiaIoSaveLib.mak all\
		BUILD_DIR=$(BUILD_DIR)\IA32 \
		TYPE=PEI_LIBRARY \
		"CFLAGS=$(CFLAGS) /X" \
		"MY_INCLUDES=/I$(ASIA_DIR)\IBV\Common\Framework \
		/I$(ASIA_DIR)\IBV\Common\Framework\Include \
		/I$(ASIA_DIR)\IBV\Common\Efi \
		/I$(ASIA_DIR)\IBV\Common\Efi\Include \
		/I$(ASIA_DIR)\IBV\Common\Include \
		/I$(ASIA_DIR)\IBV\Common\Include\IA32 \
		/I$(ASIA_DIR)\IBV\Common\Library\Dxe\Include \
		/I$(ASIA_DIR)\Foundation\Library\Include \
		/I$(ASIA_DIR)\Foundation\Include" \
		"LIBRARIES= $(ASIA_DIR)\IBV\AMI\LibBin\Ia32\EfiScriptLib.lib"
!ENDIF

#**********************************************************************
#**********************************************************************
#**                                                                  **
#**        (C)Copyright 1985-2007, American Megatrends, Inc.         **
#**                                                                  **
#**                       All Rights Reserved.                       **
#**                                                                  **
#**             6145-F Northbelt Pkwy, Norcross, GA 30071            **
#**                                                                  **
#**                       Phone: (770)-246-8600                      **
#**                                                                  **
#**********************************************************************
#**********************************************************************