#//**********************************************************************
#//**********************************************************************
#//**                                                                  **
#//**      Copyright (c) 2018 Shanghai Zhaoxin Semiconductor Co., Ltd.              **
#//**                                                                  **
#//**********************************************************************
#//**********************************************************************
#**********************************************************************
all : AsiaCpuPei

AsiaCpuPei : $(BUILD_DIR)\AsiaCpuPei.mak AsiaCpuPeiBin

$(BUILD_DIR)\AsiaCpuPortingLib.lib : AsiaCpuPortingLib

$(BUILD_DIR)\AsiaCpuPei.mak : $(ASIA_FOUNDATION_DIR)\PEI\CPU\$(@B).cif $(ASIA_FOUNDATION_DIR)\PEI\CPU\$(@B).mak $(BUILD_RULES)
	$(CIF2MAK) $(ASIA_FOUNDATION_DIR)\PEI\CPU\$(@B).cif $(CIF2MAK_DEFAULTS) 

AsiaCpuPeiBin : $(BUILD_DIR)\AsiaCpuPortingLib.lib
	$(MAKE) /$(MAKEFLAGS) BUILD_ROOT=$(BUILD_DIR) \
!IF "$(x64_BUILD)"=="1"		
		"EXT_OBJS=$(**:Build\=Build\IA32\)" \
!ELSE
		EXT_OBJS=$** \
!ENDIF
		PROJECT_DIR=$(PROJECT_DIR)\
		/f $(BUILD_DIR)\AsiaCpuPei.mak all\
		GUID=a55ef9b1-400b-4e06-895e-449f43baa450\
		ENTRY_POINT=AsiaCpuPeimEntry\
		TYPE=PEIM\
		COMPRESS=0\
		VERSIONSTRING=$(CPU_STRING)\
		"CFLAGS=$(CFLAGS) /X" \
		"MY_INCLUDES=/I$(ASIA_DIR)\IBV\Common \
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
		/I$(ASIA_DIR)\Interface"\
		"LIBRARIES=$(ASIA_DIR)\IBV\AMI\LibBin\IA32\EdkFrameworkPpiLib.lib \
		$(ASIA_DIR)\IBV\AMI\LibBin\IA32\PeiLib.lib \
		$(ASIA_DIR)\IBV\AMI\LibBin\IA32\EdkGuidLib.lib"
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