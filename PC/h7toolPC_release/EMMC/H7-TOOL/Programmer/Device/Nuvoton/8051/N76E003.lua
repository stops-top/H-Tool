-------------------------------------------------------
-- 文件名 : N76E003.lua
-- 版  本 : V1.0  2020-04-28
-- 说  明 : 
-------------------------------------------------------

print("load \"N76E003.lua\" ok")

IncludeList = {
	"0:/H7-TOOL/Programmer/Device/Nuvoton/Lib/cfg_8051.lua"
}

function config_cpu(void)
	DeviceList = {
		--器件名称, APROM最大值,  LDROM最大值,  SPROM最大值
		"N76E003",  18 * 1024, 		4 * 1024,	0,
		"N76E616",  18 * 1024, 		4 * 1024,	0,
		"N76E885",  18 * 1024, 		4 * 1024,	0,
		
		--下面未调试
		"N79E715",  18 * 1024, 		4 * 1024,	0,
		"N79E844",  18 * 1024, 		4 * 1024,	0,
		"N79E8432", 18 * 1024, 		4 * 1024,	0,
		"N79E825",  18 * 1024, 		4 * 1024,	0,
		"N79E824",  18 * 1024, 		4 * 1024,	0,
		"N79E823",  18 * 1024, 		4 * 1024,	0,
		"N79E822",  18 * 1024, 		4 * 1024,	0,
	}

	CHIP_TYPE = "NUVOTON_8051"		--指定器件接口类型: "SWD", "SWIM", "SPI", "I2C", "UART"

	APROM_ADDRESS = 0x00000000
	LDROM_ADDRESS = 0x00010000	--虚拟地址，+0x10000
	SPROM_ADDRESS = 0x00020000	--虚拟地址，+0x20000

	FLASH_ADDRESS = APROM_ADDRESS
	EEPROM_ADDRESS = 0x004000

	for i = 1, #DeviceList, 4 do
		if (DEVICE == DeviceList[i]) then
			APROM_SIZE = DeviceList[i + 1]	--FLASH总容量, APROM
			LDROM_SIZE = DeviceList[i + 2]	--EEPROM容量, LDROM
			SPROM_SIZE = DeviceList[i + 3]	--EEPROM容量, LDROM			

			break
		end
	end

	UID_ADDR = 0			--UID地址，不同的CPU不同

	OB_ADDRESS     = "0000 0001 0002 0003 0004 0005 0006 0007"

	OB_SECURE_OFF  = "FF FF FF FF FF FF FF FF"	--SECURE_ENABLE = 0时，编程完毕后写入该值 (不含反码字节）
	OB_SECURE_ON   = "FD FF FF FF FF FF FF FF"	--SECURE_ENABLE = 1时，编程完毕后写入该值
	
	--判断读保护和写保护的条件(WRP = Write protection)
	OB_WRP_ADDRESS   = {0x00000000} 	--内存地址
	OB_WRP_MASK  	 = {0x02}		--读出数据与此数相与
	OB_WRP_VALUE 	 = {0x02}		--相与后与此数比较，相等表示没有保护
	
	if (MCU_Init ~= nil) then
		MCU_Init()
	end	
end

--用于PC软件, 设置缺省配置参数
function pc_default(void)
	TVCC_VOLT = 3.3			--定义CPU供电电压TVCC
	
	VERIFY_MODE = 1			--校验模式: 0:自动(FLM提供校验函数或读回) 1:读回  2:软件CRC32  3:STM32硬件CRC32

	REMOVE_RDP_POWEROFF = 1 --写完OB后需要断电
	POWEROFF_TIME1 = 0   	--写完OB延迟时间ms
	POWEROFF_TIME2 = 100   	--断电时间ms
	POWEROFF_TIME3 = 20   	--上电后等待时间ms

	SWD_CLOCK_DELAY_0 = 0 	--单路烧录时的时钟延迟
	SWD_CLOCK_DELAY_1 = 0 	--多路烧录时的时钟延迟
	
	AUTO_REMOVE_PROTECT = 1 --自动解除读保护

	NOTE_PC = "LDROM也用APROM算法,用户自己计算好烧录地址"	
	
	--供PC软件选择算法的列表
	AlgoFile_List = {
		"APROM",
		--"LDROM",	LDROM数据可以用APROM算法一起写入
		--"SPROM",
	}	
end

---------------------------结束-----------------------------------
