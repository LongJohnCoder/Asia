#//**********************************************************************
#//**********************************************************************
#//**                                                                  **
#//**      Copyright (c) 2018 Shanghai Zhaoxin Semiconductor Co., Ltd.              **
#//**                                                                  **
#//**********************************************************************
#//**********************************************************************
all : AsiaSbPei

AsiaSbPei : $(BUILD_DIR)\AsiaSbPei.mak AsiaSbPeiBin

$(BUILD_DIR)\AsiaIoLib.lib : AsiaIoLib

$(BUILD_DIR)\AsiaPlatformLib.lib : AsiaPlatformLib

$(BUILD_DIR)\AsiaSbPei.mak : $(ASIA_FOUNDATION_DIR)\PEI\SB\$(@B).cif $(ASIA_PORTING_DIR)\PEI\SB\$(ASIA_SBTYPE)\$(@B)Lib.cif $(ASIA_FOUNDATION_DIR)\PEI\SB\$(@B).mak $(BUILD_RULES)
	$(CIF2MAK) $(ASIA_FOUNDATION_DIR)\PEI\SB\$(@B).cif $(CIF2MAK_DEFAULTS) $(ASIA_PORTING_DIR)\PEI\SB\$(ASIA_SBTYPE)\$(@B)Lib.cif

AsiaSbPeiBin : $(BUILD_DIR)\AsiaIoLib.lib $(BUILD_DIR)\AsiaPlatformLib.lib
	$(MAKE) /$(MAKEFLAGS) BUILD_ROOT=$(BUILD_DIR) \
!IF "$(x64_BUILD)"=="1"		
		"EXT_OBJS=$(**:Build\=Build\IA32\)" \
!ELSE
		"EXT_OBJS=$**" \
!ENDIF
		PROJECT_DIR=$(PROJECT_DIR)\
		/f $(BUILD_DIR)\AsiaSbPei.mak all\
		GUID=24FF6EBD-9310-4f0e-9D10-99A486CD9280\
		ENTRY_POINT=AsiaSbPeimEntryPoint\
		TYPE=PEIM \
		COMPRESS=0\
		"CFLAGS=$(CFLAGS) /X" \
		"MY_INCLUDES=/I$(ASIA_DIR)\IBV\Common\Framework\Include \
		/I$(ASIA_DIR)\IBV\Common\Framework \
		/I$(ASIA_DIR)\IBV\Common\Efi \
		/I$(ASIA_DIR)\IBV\Common\Efi\Include \
		/I$(ASIA_DIR)\IBV\Common\Include \
		/I$(ASIA_DIR)\IBV\Common\Include\IA32 \
		/I$(ASIA_DIR)\IBV\Common\Include\Pei \
		/I$(ASIA_DIR)\IBV\Common\Library\Pei\Include \
		/I$(ASIA_DIR)\IBV\Common \
		/I$(ASIA_DIR)\Porting\Include \
		/I$(ASIA_DIR)\Foundation\include \
		/I$(ASIA_DIR)\Foundation\Library\Include \
		/I$(ASIA_DIR)\Foundation\Pei\Nb \
		/I$(ASIA_DIR)\Foundation\Pei\Sb \
		/I$(ASIA_DIR)\Platform\$(ASIA_MBTYPE) \
		/I$(ASIA_DIR)\Interface"\
		"LIBRARIES=$(ASIA_DIR)\IBV\AMI\LibBin\IA32\EdkFrameworkPpiLib.lib \
		$(ASIA_DIR)\IBV\AMI\LibBin\IA32\PeiLib.lib \
		$(ASIA_DIR)\IBV\AMI\LibBin\IA32\EdkGuidLib.lib"

	

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