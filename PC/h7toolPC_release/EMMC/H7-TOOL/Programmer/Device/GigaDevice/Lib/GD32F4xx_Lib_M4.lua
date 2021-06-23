
-------------------------------------------------------
-- 文件名 : GD32F4xx_Lib_M4.lua
-- 版  本 : V1.0  2020-04-28
-- 说  明 : 用于解除读保护的库
-------------------------------------------------------

print("load \"GD32F4xx_Lib_M4.lua\" ok")

--寄存器地址
FMC_WS 		= 0x40023C00
FMC_KEY 	= 0x40023C04
FMC_OBKEY	= 0x40023C08
FMC_STAT	= 0x40023C0C
FMC_CTL		= 0x40023C10
FMC_OBCTL0	= 0x40023C14
FMC_OBCTL1	= 0x40023C18
FMC_WSEN	= 0x40023CFC

--常量值
UNLOCK_KEY0	= 0x45670123
UNLOCK_KEY1 = 0xCDEF89AB

OB_UNLOCK_KEY0 = 0x08192A3B
OB_UNLOCK_KEY1 = 0x4C5D6E7F

FMC_OBCTL0_OB_START = 0x0002

FMC_FLAG_BUSY = 0x00010000

--判断data数组标志，全部为0则退出
function CheckFlagQuit0(data, mask)
	local i
	local ret

	if (MULTI_MODE > 0) then
		ret = 0
		for i = 1, MULTI_MODE, 1 do
			ret = ret | (data[i] & mask)
		end
	else
		ret = data[1] & mask
	end

	return ret
end

--芯片专有的解除保护函数
function MCU_RemoveProtect(void)
	MCU_ProgOptionBytes(OB_SECURE_OFF)
end

--等待超时，10秒（解除读保护时会执行全面擦除，3.5秒1MB)	
function FMC_WaitBusy(ob)
	local i
	local reg = {}

 	for i = 1, 1000, 1 do
 		reg = {pg_read32(FMC_STAT)}
		if (CheckFlagQuit0(reg, FMC_FLAG_BUSY) == 0) then
			break
		end
		delayms(10)
	end
end

--没有FLM的MCU，用脚本实现编程OB。 返回 "OK" or "error"
function MCU_ProgOptionBytes(ob)
	local i
	local j
	local reg
	local ob_8
	local ob1
	local ob2	
	local rd1 = {}
	local rd2 = {}
	local err = "OK"	
	local ch_num

	if (MULTI_MODE > 0) then
		ch_num = MULTI_MODE
	else
		ch_num = 1
	end	

	print("MCU_ProgOptionBytes()")
	pg_write32(FMC_KEY, UNLOCK_KEY0)
 	pg_write32(FMC_KEY, UNLOCK_KEY1)
	pg_write32(FMC_OBKEY, OB_UNLOCK_KEY0)
 	pg_write32(FMC_OBKEY, OB_UNLOCK_KEY1)

	ob_8 = hex_to_bin(ob)	--hex字符串转为二进制数组
	
	--复位值： 0x2FFF AAED。	
	ob1 = string.byte(ob_8, 1) + (((string.byte(ob_8, 2)) << 8) & 0xFF00) +
			(((string.byte(ob_8, 3)) << 16) & 0xFF0000)  + (((string.byte(ob_8, 4)) << 24) & 0xFF000000)

	ob1 = (ob1 & 0x0FFFFFEC) | 0x30000000
	pg_write32(FMC_OBCTL0, ob1)

	--复位值： 0x0FFF 0000
	ob2 = string.byte(ob_8, 5) + (((string.byte(ob_8, 6)) << 8) & 0xFF00)
	ob2	= ob2 & 0x0FFF
	pg_write32(FMC_OBCTL1, (ob2 << 16) & 0x0FFF0000)

	pg_write32(FMC_OBCTL0, ob1 | FMC_OBCTL0_OB_START)
	
	FMC_WaitBusy()

	--校验
	rd1 = {pg_read16(0x1FFFC000)}
	rd1_1 = {pg_read16(0x1FFFC008)}
	rd2 = {pg_read16(0x1FFEC008)}
	for j = 1, ch_num, 1 do
		rd1[j] = rd1[j] + (rd1_1[j] << 16)				
		rd1[j] = (rd1[j] & 0xCFFFFFEC) | 0x30000000
		rd2[j] = rd2[j] & 0x0FFF

		if ( (ob1 ~= rd1[j]) or (ob2 ~= rd2[j]) ) then
			err = "error"
		end
	end
	
	return err
end

--【F1】复位期间执行的函数. 目的:debug期间冻结看门狗时钟,低功耗模式启动HCLK和FCLK
function InitUnderReset(void)
	local str = "error"

	print("InitUnderReset()")

	if (pg_write32(0xE0042004, 0x00000307) == 0) then
		goto quit_err
	end

	if (ReadDeviceID() ~= 0) then
		goto quit_err
	end

::quit_ok::
	str = "OK"

::quit_err::
	print(str)

	return str
end

--读芯片ID
function ReadDeviceID(void)
	local str
	local err = 0
	local j
	local ch_num

	if (MULTI_MODE == 0) then
		ch_num = 1
	else
		ch_num = MULTI_MODE
	end
	
	g_DevID = {pg_read32(0xE0042000)} --全局变量g_DevID[]

	str = "..DeviceID = "
	for j = 1, ch_num, 1 do
		str = str..string.format("%08X ", g_DevID[j])
		if (g_DevID[j] == 0) then
			err = 1
		end
	end

	print(str)
	return err
end

---------------------------结束-----------------------------------
