-------------------------------------------------------
-- 文件名 : M0518_36.lua
-- 版  本 : V1.0  2020-04-28
-- 说  明 : 
-------------------------------------------------------

print("load \"M0518_36.lua\" ok")

IncludeList = {
	"0:/H7-TOOL/Programmer/Device/Nuvoton/Lib/cfg_m0.lua"
}

function config_cpu(void)
	CHIP_TYPE = "SWD"		--指定器件接口类型: "SWD", "SWIM", "SPI", "I2C", "UART"

	AlgoFile_AP	   = "0:/H7-TOOL/Programmer/Device/Nuvoton/FLM/M0518_AP_36.FLM"
	AlgoFile_LD	   = "0:/H7-TOOL/Programmer/Device/Nuvoton/FLM/M0518_LD_4.FLM"
	AlgoFile_DAT   = "0:/H7-TOOL/Programmer/Device/Nuvoton/FLM/M0518_DAT.FLM"
	AlgoFile_CFG   = ""

	AlgoFile_FLASH = AlgoFile_AP
	AlgoFile_OPT = AlgoFile_CFG

	AlgoFile_OTP   = ""
	AlgoFile_QSPI  = ""

	FLASH_ADDRESS = 0x00000000		--CPU内部FLASH起始地址

	RAM_ADDRESS = 0x20000000		--CPU内部RAM起始地址

	--Flash算法文件加载内存地址和大小
	AlgoRamAddr = RAM_ADDRESS
	AlgoRamSize = 4 * 1024

	MCU_ID = 0x2BA01477

	UID_ADDR = 0x1FFFF7AC	   	--UID地址，不同的CPU不同
	UID_BYTES = 12

	--缺省校验模式
	VERIFY_MODE = 0				-- 0:读回校验, 1:软件CRC32校验, 其他:扩展硬件CRC(需要单片机支持）

	ERASE_CHIP_TIME = 5000		--全片擦除时间ms（仅用于进度指示)

	OB_ADDRESS     = "00300000 00300001 00300002 00300003 00300004 00300005 00300006 00300007"

	OB_SECURE_OFF  = "FF FF FF FF FF FF FF FF"	--SECURE_ENABLE = 0时，编程完毕后写入该值(解除加密)
	OB_SECURE_ON   = "FD FF FF FF FF FF FF FF"	--SECURE_ENABLE = 1时，编程完毕后写入该值(芯片加密)
	-- 0x7FFFFFE7

	--判断读保护和写保护的条件(WRP = Write protection)
	OB_WRP_ADDRESS   = {0x00300000} 	--内存地址
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

	NOTE_PC = ""	
end

---------------------------结束-----------------------------------
