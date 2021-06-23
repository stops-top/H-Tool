
-------------------------------------------------------
-- 文件名 : NUC100xDxxx_64.lua
-- 版  本 : V1.0  2020-04-28
-- 说  明 : MM32F003TW, MM32F003NW
-------------------------------------------------------
function config_cpu(void)
	CHIP_TYPE = "SWD"		--指定器件接口类型: "SWD", "SWIM", "SPI", "I2C", "UART"

	AlgoFile_AP	   = "0:/H7-TOOL/Programmer/Device/Nuvoton/FLM/NUC100_AP_64.FLM"
	AlgoFile_LD	   = "0:/H7-TOOL/Programmer/Device/Nuvoton/FLM/NUC100_LD_4.FLM"
	AlgoFile_DAT   = "0:/H7-TOOL/Programmer/Device/Nuvoton/FLM/NUC100_DAT.FLM"
	AlgoFile_CFG   = "0:/H7-TOOL/Programmer/Device/Nuvoton/FLM/NUC100_CFG.FLM"

	AlgoFile_FLASH = AlgoFile_AP
	AlgoFile_OPT = AlgoFile_CFG

	AlgoFile_OTP   = ""
	AlgoFile_QSPI  = ""

	FLASH_ADDRESS = 0x00000000		--CPU内部FLASH起始地址

	RAM_ADDRESS = 0x20000000		--CPU内部RAM起始地址

	--Flash算法文件加载内存地址和大小
	AlgoRamAddr = RAM_ADDRESS
	AlgoRamSize = 4 * 1024

	MCU_ID = 0x0BB11477

	UID_ADDR = 0x1FFFF7AC	   	--UID地址，不同的CPU不同
	UID_BYTES = 12

	--缺省校验模式
	VERIFY_MODE = 0				-- 0:读回校验, 1:软件CRC32校验, 其他:扩展硬件CRC(需要单片机支持）

	ERASE_CHIP_TIME = 5000		--全片擦除时间ms（仅用于进度指示)

	OB_ADDRESS     = "00300000 00300001 00300002 00300003 00300004 00300005 00300006 00300007"

	OB_SECURE_OFF  = "FF FF FF FF FF FF FF FF"	--SECURE_ENABLE = 0时，编程完毕后写入该值(解除加密)
	OB_SECURE_ON   = "FD FF FF FF FF FF FF FF"	--SECURE_ENABLE = 1时，编程完毕后写入该值(芯片加密)

	--判断读保护和写保护的条件(WRP = Write protection)
	OB_WRP_ADDRESS   = {0x00300000} 	--内存地址
	OB_WRP_MASK  	 = {0x02}		--读出数据与此数相与
	OB_WRP_VALUE 	 = {0x02}		--相与后与此数比较，相等表示没有保护

	if (MCU_Init ~= nil) then
		MCU_Init()
	end
end

---------------------------结束-----------------------------------
