
-------------------------------------------------------
-- 文件名 : STM8AF6226_F6223_F6221.lua
-- 版  本 : V1.0  2020-04-28
-- 说  明 :
-------------------------------------------------------
function config_cpu(void)
	DeviceList = {
		"STM8AF6226",  8 * 1024, 640,
		"STM8AF6223",  8 * 1024, 640,

		"STM8AF6223A",  8 * 1024, 640,
		"STM8AF6213",  4 * 1024,  640,
		"STM8AF6213A",  4 * 1024, 640,
	}

	CHIP_TYPE = "SWIM"			--指定器件接口类型: "SWD", "SWIM", "SPI", "I2C"

	STM8_SERIAL = "STM8S"		--选择2个系列: "STM8S" 或 "STM8L"

	FLASH_BLOCK_SIZE = 128		--定义BLOCK SIZE, 只有64和128两种

	FLASH_ADDRESS = 0x008000	--定义FLASH起始地址

	EEPROM_ADDRESS = 0x004000 	--定义FLASH起始地址(STM8S和STM8L不同）

	for i = 1, #DeviceList, 3 do
		if (DEVICE == DeviceList[i]) then
			FLASH_SIZE  = DeviceList[i + 1]	--FLASH总容量
			EEPROM_SIZE = DeviceList[i + 2]	--EEPROM容量

			--定义BLOCK SIZE, 只有64和128两种
			if (FLASH_SIZE <= 8 * 1024) then
				FLASH_BLOCK_SIZE = 64
			else
				FLASH_BLOCK_SIZE = 128
			end
		end
	end

	UID_ADDR = 0x4865			--UID地址

	OB_ADDRESS      = "4800 4801 FFFF 4803 FFFF 4805 FFFF 4807 FFFF 4809 FFFF"
	OB_SECURE_OFF  =  "00 00 00 00 00 00"	--SECURE_ENABLE = 0时，编程完毕后写入该值 (不含反码字节）
	OB_SECURE_ON   =  "AA 00 00 00 00 00"	--SECURE_ENABLE = 1时，编程完毕后写入该值
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

	NOTE_PC = ""

	--供PC软件选择算法的列表
	AlgoFile_List = {
		"FLASH",
		"EEPROM",
	}	
end

---------------------------结束-----------------------------------
