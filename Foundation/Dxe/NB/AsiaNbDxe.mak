#//**********************************************************************
#//**********************************************************************
#//**                                                                  **
#//**     Copyright (c) 2018 Shanghai Zhaoxin Semiconductor Co., Ltd.  **
#//**                                                                  **
#//**********************************************************************
#//**********************************************************************
all : AsiaNbDxe

$(BUILD_DIR)\AsiaIoLib.lib : AsiaIoLib
$(BUILD_DIR)\AsiaIoSaveLib.lib : AsiaIoSaveLib

AsiaNbDxe : $(BUILD_DIR)\AsiaNbDxe.mak AsiaNbDxeBin

$(BUILD_DIR)\AsiaNbDxe.mak : $(ASIA_DIR)\Foundation\Dxe\Nb\$(@B).cif $(ASIA_DIR)\Porting\Dxe\Nb\$(ASIA_NBTYPE)\$(@B)Lib.cif $(ASIA_DIR)\Foundation\Dxe\Nb\$(@B).mak $(BUILD_RULES)
	$(CIF2MAK) $(ASIA_DIR)\Foundation\Dxe\Nb\$(@B).cif $(CIF2MAK_DEFAULTS) $(ASIA_DIR)\Porting\Dxe\Nb\$(ASIA_NBTYPE)\$(@B)Lib.cif

AsiaNbDxeBin : $(BUILD_DIR)\AsiaIoLib.lib $(BUILD_DIR)\AsiaIoSaveLib.Lib $(BUILD_DIR)\AsiaPlatformLib.lib
	$(MAKE) /$(MAKEFLAGS) $(BUILD_DEFAULTS)\
		/f $(BUILD_DIR)\AsiaNbDxe.mak all\
		GUID=BEAA039C-24BD-43ad-821A-BEC3C88C8B12\
		ENTRY_POINT=AsiaNbDxeEntryPoint\
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
		/I$(ASIA_DIR)\IBV\Common\Cpu\Include \
		/I$(ASIA_DIR)\Porting\Include \
		/I$(ASIA_DIR)\Foundation\include \
		/I$(ASIA_DIR)\Foundation\Library\Include \
		/I$(ASIA_DIR)\Foundation\Dxe\Nb \
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