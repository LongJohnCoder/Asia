#//**********************************************************************
#//**********************************************************************
#//**                                                                  **
#//**      Copyright (c) 2018 Shanghai Zhaoxin Semiconductor Co., Ltd.              **
#//**                                                                  **
#//**********************************************************************
#//**********************************************************************
all : AsiaDramPei

AsiaDramPei : $(BUILD_DIR)\AsiaDramPei.mak AsiaDramPeiBin

$(BUILD_DIR)\AsiaDramPei.mak : $(ASIA_FOUNDATION_DIR)\PEI\Dram\$(@B).cif $(ASIA_PORTING_DIR)\PEI\$(ASIA_DRAMTYPE)\$(ASIA_NBTYPE)\$(@B)Lib.cif $(ASIA_FOUNDATION_DIR)\PEI\Dram\$(@B).mak $(BUILD_RULES)
	$(CIF2MAK) $(ASIA_FOUNDATION_DIR)\PEI\Dram\$(@B).cif $(CIF2MAK_DEFAULTS) $(ASIA_PORTING_DIR)\PEI\$(ASIA_DRAMTYPE)\$(ASIA_NBTYPE)\$(@B)Lib.cif

$(BUILD_DIR)\AsiaIoLib.lib : AsiaIoLib
$(BUILD_DIR)\AsiaPlatformLib.lib : AsiaPlatformLib


AsiaDramPeiBin : $(BUILD_DIR)\AsiaPlatformLib.lib $(BUILD_DIR)\AsiaIoLib.lib
	$(MAKE) /$(MAKEFLAGS) BUILD_ROOT=$(BUILD_DIR) \
!IF "$(x64_BUILD)"=="1"		
		"EXT_OBJS=$(**:Build\=Build\IA32\)" \
!ELSE
		"EXT_OBJS=$**" \
!ENDIF
		PROJECT_DIR=$(PROJECT_DIR)\
		/f $(BUILD_DIR)\AsiaDramPei.mak all\
		GUID=B41B4CD9-2D67-466a-A36F-8E90377390C5\
		ENTRY_POINT=AsiaDramPeimEntryPoint\
		TYPE=PEIM \
		COMPRESS=0\
		"CFLAGS=$(CFLAGS) /X /D$(ASIA_DRAMTYPE)" \
		"MY_INCLUDES=/I$(ASIA_DIR)\IBV\Common\Framework\Include \
		/I$(ASIA_DIR)\IBV\Common \
		/I$(ASIA_DIR)\IBV\Common\Framework \
		/I$(ASIA_DIR)\IBV\Common\Efi \
		/I$(ASIA_DIR)\IBV\Common\Efi\Include \
		/I$(ASIA_DIR)\IBV\Common\Include \
		/I$(ASIA_DIR)\IBV\Common\Include\IA32 \
		/I$(ASIA_DIR)\Foundation\Library\Include \
		/I$(ASIA_DIR)\IBV\Common\Include\Pei \
		/I$(ASIA_DIR)\IBV\Common\Library\Pei\Include \
		/I$(ASIA_DIR)\Porting\Include \
		/I$(ASIA_DIR)\Foundation\Pei\Nb \
		/I$(ASIA_DIR)\Porting\Pei\SB\$(ASIA_SBTYPE)\
		/I$(ASIA_DIR)\Foundation\Pei\Dram \
		/I$(ASIA_DIR)\Foundation\Pei\SB \
		/I$(ASIA_DIR)\Foundation\Include \
		/I$(ASIA_DIR)\Platform\$(ASIA_MBTYPE) \
		/I$(ASIA_DIR)\Interface"\
		"LIBRARIES=$(ASIA_DIR)\IBV\AMI\LibBin\IA32\PeiLib.lib \
		$(ASIA_DIR)\IBV\AMI\LibBin\IA32\EdkGuidLib.lib \
		$(ASIA_DIR)\IBV\AMI\LibBin\IA32\EfiDriverLib.lib \
		$(ASIA_DIR)\IBV\AMI\LibBin\IA32\EdkFrameworkPpiLib.lib"
