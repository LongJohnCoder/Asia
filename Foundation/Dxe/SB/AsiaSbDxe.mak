#//**********************************************************************
#//**********************************************************************
#//**                                                                  **
#//**     Copyright (c) 2018 Shanghai Zhaoxin Semiconductor Co., Ltd.  **
#//**                                                                  **
#//**********************************************************************
#//**********************************************************************
all : AsiaSbDxe

AsiaSbDxe : $(BUILD_DIR)\AsiaSbDxe.mak AsiaSbDxeBin

$(BUILD_DIR)\AsiaSbDxe.mak : $(ASIA_DIR)\Foundation\Dxe\Sb\$(@B).cif $(ASIA_DIR)\Porting\Dxe\Sb\$(ASIA_SBTYPE)\$(@B)Lib.cif $(ASIA_DIR)\Foundation\Dxe\Sb\$(@B).mak $(BUILD_RULES)
	$(CIF2MAK) $(ASIA_DIR)\Foundation\Dxe\Sb\$(@B).cif $(CIF2MAK_DEFAULTS) $(ASIA_DIR)\Porting\Dxe\Sb\$(ASIA_SBTYPE)\$(@B)Lib.cif

AsiaSbDxeBin : $(BUILD_DIR)\AsiaIoLib.lib $(BUILD_DIR)\AsiaIoSaveLib.Lib $(BUILD_DIR)\AsiaPlatformLib.lib
	$(MAKE) /$(MAKEFLAGS) $(BUILD_DEFAULTS)\
		/f $(BUILD_DIR)\AsiaSbDxe.mak all\
		GUID=AE0F5D72-4702-4175-A3A6-B120360FF114\
		ENTRY_POINT=AsiaSbDxeEntryPoint\
		TYPE=BS_DRIVER \
		COMPRESS=1\
		"CFLAGS=$(CFLAGS) /X /D$(ASIA_S3SUPPORT)" \
		"MY_INCLUDES=/I$(ASIA_DIR)\IBV\Common \
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
		/I$(ASIA_DIR)\IBV\Common\Include\Dxe \
		/I$(ASIA_DIR)\IBV\Common\Library\Dxe\Include \
		/I$(ASIA_DIR)\Porting\Include \
		/I$(ASIA_DIR)\Foundation\include \
		/I$(ASIA_DIR)\Foundation\Library\Include \
		/I$(ASIA_DIR)\Foundation\Dxe\Nb \
		/I$(ASIA_DIR)\Foundation\Dxe\Sb \
		/I$(ASIA_DIR)\Foundation\Pei\Sb \
		/I$(ASIA_DIR)\Foundation\Pei\Nb \
		/I$(ASIA_DIR)\Platform\$(ASIA_MBTYPE) \
		/I$(ASIA_DIR)\Interface" \
		"LIBRARIES= \
!IF "$(x64_BUILD)"=="1"
		$(ASIA_DIR)\IBV\AMI\LibBin\x64\EfiScriptLib.lib \
		$(ASIA_DIR)\IBV\AMI\LibBin\x64\EfiDriverLib.lib"
!ELSE
		$(ASIA_DIR)\IBV\AMI\LibBin\Ia32\EfiScriptLib.lib \
		$(ASIA_DIR)\IBV\AMI\LibBin\Ia32\EfiDriverLib.lib"
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
#**********************************************************************