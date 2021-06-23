-------------------------------------------------------
-- 文件名 : FM25xxxx.lua
-- 版  本 : V1.0  2020-11-06
-- 说  明 : 
-------------------------------------------------------
function config_cpu(void)
	DeviceList = {
		--器件名称, 容量(KB),   擦除扇区大小,   擦除指令, 	全片擦除超时, 	编程AAI模式(1表示AAI, 0表示page 256写)		
		"FM25F005",   64, 		64 * 1024,  	0xD8,		500,   		0,  
		"FM25F01",	  128, 		64 * 1024,  	0xD8,		500,   		0,     
		"FM25W01",	  128, 		64 * 1024,  	0xD8,		500,   		0,        
		"FM25Q02",   256, 		64 * 1024,  	0xD8,		500,   		0,     
		"FM25W02",   256, 		64 * 1024,  	0xD8,		500,   		0,     
		"FM25Q04",   512, 		64 * 1024,  	0xD8,		1500,       0,     
		"FM25W04",   512, 		64 * 1024,  	0xD8,		1500,       0,   
		"FM25Q08",   1 * 1024, 	64 * 1024,  	0xD8,		2000,		0,       
		"FM25Q16",   2 * 1024, 	64 * 1024,  	0xD8,		5000,       0,     
		"FM25W16",   2 * 1024, 	64 * 1024,  	0xD8,		5000,       0,     
		"FM25Q32",   4 * 1024, 	64 * 1024,  	0xD8,		10000,		0,   
		"FM25W32",   4 * 1024, 	64 * 1024,  	0xD8,		10000,		0,   
		"FM25Q64",   8 * 1024, 	64 * 1024,  	0xD8,		16000,   	0,    
		"FM25Q128",  16 * 1024, 64 * 1024,  	0xD8,		25000,   	0,    
		"FM25W128",  16 * 1024, 64 * 1024,  	0xD8,		25000,   	0,    
	}

	CHIP_TYPE = "SPI"			--指定器件接口类型: "SWD", "SWIM", "SPI", "I2C"

	FLASH_ADDRESS = 0x00000000	--定义FLASH起始地址

	UNLOCK_CMD = 0x00		--0x00 表示写状态字为0x00解锁  0x98表示发0x98指令解锁
	
	ERASE_CHIP_CMD = 0xC7	--擦除全片的指令，缺省是0xC7
	
	for i = 1, #DeviceList, 6 do
		if (DEVICE == DeviceList[i]) then
			FLASH_SIZE  = DeviceList[i + 1] * 1024	--FLASH总容量
			SECTOR_SIZE = DeviceList[i + 2]
			ERASE_SECTOR_CMD = DeviceList[i + 3]
			ERASE_SECTOR_TIMEOUT = 1000	--擦除扇区超时固定1秒
			ERASE_CHIP_TIMEOUT = DeviceList[i + 4]	--全片擦除超时
			PROG_AAI = DeviceList[i + 5]
			break
		end
	end

	--以下字段无用
	UID_ADDR = 0x00000			--UID地址，不同的CPU不同

	OB_ADDRESS     = "00000000 00000000 00000000 00000000"

	OB_SECURE_OFF  = "FF FF FF FF"	--SECURE_ENABLE = 0时，编程完毕后写入该值 (不含反码字节）
	OB_SECURE_ON   = "FF FF FF FF"	--SECURE_ENABLE = 1时，编程完毕后写入该值
end

--用于PC软件, 设置缺省配置参数
function pc_default(void)
	TVCC_VOLT = 3.3			--定义CPU供电电压TVCC
	
	VERIFY_MODE = 1			--校验模式: 0:自动(FLM提供校验函数或读回) 1:读回  2:软件CRC32  3:STM32硬件CRC32

	REMOVE_RDP_POWEROFF = 0 --写完OB后需要断电
	POWEROFF_TIME1 = 0   	--写完OB延迟时间ms
	POWEROFF_TIME2 = 100   	--断电时间ms
	POWEROFF_TIME3 = 20   	--上电后等待时间ms

	SWD_CLOCK_DELAY_0 = 0 	--单路烧录时的时钟延迟
	SWD_CLOCK_DELAY_1 = 0 	--多路烧录时的时钟延迟
	
	AUTO_REMOVE_PROTECT = 0 --自动解除读保护

	ERASE_CHIP_MODE = 0		--0按扇区擦除 1擦除全片  

	if (FLASH_SIZE >= 1024 * 1024) then
		NOTE_PC = string.format("容量 : %d MB", FLASH_SIZE / (1024 * 1024))
	else
		NOTE_PC = string.format("容量 : %d KB", FLASH_SIZE / 1024)
	end

	--供PC软件选择算法的列表
	AlgoFile_List = {
		"FLASH",
	}	
end

---------------------------结束-----------------------------------
