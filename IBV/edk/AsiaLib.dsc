DEFINE PROCESSOR=IA32
#Asia\Foundation\library\CpuIA32lib\CpuIA32Lib.inf
Asia\Foundation\library\AsiaIoLib\AsiaIoLib.inf
Asia\Foundation\Library\AsiaIoSaveLib\AsiaIoSaveLib.inf
Asia\Interface\Ppi\AsiaPpiLib.inf
Asia\Interface\Protocol\AsiaProtocolLib.inf
Asia\Porting\Library\Cpu\$(ASIA_CPUTYPE)\AsiaCpuPortingLib.inf
Asia\Platform\$(ASIA_MBTYPE)\AsiaPlatformLib.inf
Asia\Porting\Pei\Dram\$(ASIA_NBTYPE)\AsiaDramPeimLib.inf
Asia\Porting\Pei\SB\$(ASIA_SBTYPE)\AsiaSbPeimLib.inf
Asia\Porting\Pei\NB\$(ASIA_NBTYPE)\AsiaNbPeimLib.inf

DEFINE PROCESSOR=$(BUILD_TARGET_PROCESSOR)

#Asia\Foundation\library\CpuIA32lib\CpuIA32Lib.inf
Asia\Foundation\library\AsiaIoLib\AsiaIoLib.inf
Asia\Foundation\Library\AsiaIoSaveLib\AsiaIoSaveLib.inf
Asia\Interface\Ppi\AsiaPpiLib.inf
Asia\Interface\Protocol\AsiaProtocolLib.inf
Asia\Porting\Library\Cpu\$(ASIA_CPUTYPE)\AsiaCpuPortingLib.inf
Asia\Platform\$(ASIA_MBTYPE)\AsiaPlatformLib.inf
Asia\Porting\Dxe\NB\$(ASIA_NBTYPE)\AsiaNbDxePortingLib.inf
Asia\Porting\Dxe\SB\$(ASIA_SBTYPE)\AsiaSbDxePortingLib.inf
