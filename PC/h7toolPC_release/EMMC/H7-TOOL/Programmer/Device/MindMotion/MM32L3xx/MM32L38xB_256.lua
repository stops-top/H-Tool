-------------------------------------------------------
-- �ļ��� : MM32L38xB_256.lua
-- ��  �� : V1.0  2020-04-28
-- ˵  �� :
-------------------------------------------------------

print("load \"MM32L38xB_256.lua\" ok")

IncludeList = {
	"0:/H7-TOOL/Programmer/Device/MindMotion/Lib/MM32_Lib_M3.lua"
}

function config_cpu(void)
	CHIP_TYPE = "SWD"		--ָ�������ӿ�����: "SWD", "SWIM", "SPI", "I2C", "UART"

	AlgoFile_FLASH = "0:/H7-TOOL/Programmer/Device/MindMotion/MM32F103/MM32F103xCxE_256.FLM"
	AlgoFile_OTP   = ""
	AlgoFile_OPT   = "0:/H7-TOOL/Programmer/Device/MindMotion/OPT/MM32_M3_o_OPT.FLM"
	AlgoFile_QSPI  = ""

	FLASH_ADDRESS = 0x08000000		--CPU�ڲ�FLASH��ʼ��ַ

	RAM_ADDRESS = 0x20000000		--CPU�ڲ�RAM��ʼ��ַ

	--Flash�㷨�ļ������ڴ��ַ�ʹ�С
	AlgoRamAddr = RAM_ADDRESS
	AlgoRamSize = 4 * 1024

	MCU_ID = 0x2BA01477

	UID_ADDR = 0x1FFFF7E8	   	--UID��ַ����ͬ��CPU��ͬ
	UID_BYTES = 12

	--ȱʡУ��ģʽ
	VERIFY_MODE = 0				-- 0:����У��, 1:����CRC32У��, ����:��չӲ��CRC(��Ҫ��Ƭ��֧�֣�

	--��ַ���е�FFFFFFFF��ʾԭʼ�����в���һ��ȡ�����ֽ�
	OB_ADDRESS     = "1FFFF800 FFFFFFFF 1FFFF802 FFFFFFFF 1FFFF804 FFFFFFFF 1FFFF806 FFFFFFFF 1FFFF808 FFFFFFFF 1FFFF80A FFFFFFFF 1FFFF80C FFFFFFFF 1FFFF80E FFFFFFFF "
			       .."1FFFF810 FFFFFFFF 1FFFF812 FFFFFFFF 1FFFF814 FFFFFFFF 1FFFF816 FFFFFFFF 1FFFF818 FFFFFFFF 1FFFF81A FFFFFFFF 1FFFF81C FFFFFFFF 1FFFF81E FFFFFFFF "
			       .."1FFFF820 FFFFFFFF 1FFFF822 FFFFFFFF 1FFFF824 FFFFFFFF 1FFFF826 FFFFFFFF "
			       .."1FFE0000 1FFE0001 1FFE0002 1FFE0003 1FFE0010 1FFE0011 1FFE0012 1FFE0013 "
	OB_SECURE_OFF  = "A5 FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF "	--SECURE_ENABLE = 0ʱ�������Ϻ�д���ֵ
				   .."FF FF FF FF FF FF FF FF "
	OB_SECURE_ON   = "A5 FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF "	--SECURE_ENABLE = 1ʱ�������Ϻ�д���ֵ
				   .."FE 01 00 FF 01 FE 00 FF "

	--�ж϶�������д����������(WRP = Write protection)
	OB_WRP_ADDRESS   = {0x1FFFF800, 0x1FFFF808, 0x1FFFF80A, 0x1FFFF80C, 0x1FFFF80E, 0x1FFFF810, 0x1FFFF812, 0x1FFFF814, 0x1FFFF816, 0x1FFFF818, 0x1FFFF81A, 0x1FFFF81C, 0x1FFFF81E,
						0x1FFFF820,	0x1FFFF822, 0x1FFFF824, 0x1FFFF826,
						0x1FFE0000, 0x1FFE0002, 0x1FFE0004, 0x1FFE0006} 	--�ڴ��ַ
	OB_WRP_MASK  	 = {0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF}		--�����������������
	OB_WRP_VALUE 	 = {0xA5, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF}		--�����������Ƚϣ���ȱ�ʾû�б���
end

--����PC����, ����ȱʡ���ò���
function pc_default(void)
	TVCC_VOLT = 3.3			--����CPU�����ѹTVCC
	
	VERIFY_MODE = 1			--У��ģʽ: 0:�Զ�(FLM�ṩУ�麯�������) 1:����  2:����CRC32  3:STM32Ӳ��CRC32

	REMOVE_RDP_POWEROFF = 1 --д��OB����Ҫ�ϵ�
	POWEROFF_TIME1 = 0   	--д��OB�ӳ�ʱ��ms
	POWEROFF_TIME2 = 100   	--�ϵ�ʱ��ms
	POWEROFF_TIME3 = 20   	--�ϵ��ȴ�ʱ��ms

	SWD_CLOCK_DELAY_0 = 0 	--��·��¼ʱ��ʱ���ӳ�
	SWD_CLOCK_DELAY_1 = 0 	--��·��¼ʱ��ʱ���ӳ�
	
	AUTO_REMOVE_PROTECT = 1 --�Զ����������

	NOTE_PC = ""	
end

---------------------------����-----------------------------------