#//**********************************************************************
#//**********************************************************************
#//**                                                                  **
#//**     Copyright (c) 2018 Shanghai Zhaoxin Semiconductor Co., Ltd.                **
#//**                                                                  **
#//**********************************************************************
#//**********************************************************************
#**********************************************************************
all : AsiaProtocolLib

AsiaProtocolLib : $(BUILD_DIR)\AsiaProtocolLib.mak AsiaProtocolLibBin

$(BUILD_DIR)\AsiaProtocolLib.mak : $(ASIA_DIR)\Interface\Protocol\$(@B).cif $(ASIA_DIR)\Interface\Protocol\$(@B).mak $(BUILD_RULES)
	$(CIF2MAK) $(ASIA_DIR)\Interface\Protocol\$(@B).cif $(CIF2MAK_DEFAULTS)

AsiaProtocolLibBin : 
	$(MAKE) /$(MAKEFLAGS) $(BUILD_DEFAULTS)\
		/f $(BUILD_DIR)\AsiaProtocolLib.mak all\
		TYPE=LIBRARY \
		"CFLAGS=$(CFLAGS) /X" \
		"EXTRA_INCLUDES=/I$(ASIA_DIR)\IBV\Common\Framework \
		/I$(ASIA_DIR)\IBV\Common\Framework\Include \
		/I$(ASIA_DIR)\IBV\Common\Efi\Include \
		/I$(ASIA_DIR)\IBV\Common\Efi \
		/I$(ASIA_DIR)\IBV\Common\Include \
		/I$(ASIA_DIR)\IBV\Common\Include\Pei \
		/I$(ASIA_DIR)\IBV\Common\Include\IA32"
