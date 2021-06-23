
-------------------------------------------------------
-- 文件名 : GD32E23x_Lib_M4.lua
-- 版  本 : V1.0  2020-04-28
-- 说  明 : 用于解除读保护的库
-------------------------------------------------------

print("load \"GD32E10x_Lib_M4.lua\" ok")

FLASH_KEYR		= 0x40022004
FLASH_OPTKEYR   = 0x40022008

FLASH_KEY1      = 0x45670123
FLASH_KEY2      = 0xCDEF89AB

FMC_STAT		= 0x4002200C
FMC_CTL         = 0x40022010
FMC_CTL_OBPG    = 0x00000010
FMC_CTL_OBER    = 0x00000020
FMC_CTL_START   = 0x00000040

FMC_STAT_BUSY   = 0x00000001
FMC_STAT_PGERR  = 0x00000004
FMC_STAT_PGAERR = 0x00000008
FMC_STAT_WPERR  = 0x00000010
FMC_STAT_ENDF   = 0x00000020

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

function FMC_WaitBusy(ob)
	local i
	local reg

 	for i = 1, 50, 1 do
 		reg = {pg_read32(FMC_STAT)}
		if (CheckFlagQuit0(reg, FMC_STAT_BUSY) == 0) then
			break
		end
		delayms(10)
	end
end

--没有FLM的MCU，用脚本实现编程OB。 返回 "OK" or "error"
function MCU_ProgOptionBytes(ob)
	local i
	local reg
	local ob_8
	local ob_32
	local ob_read = {}	
	local err = "OK"
	local ch_num

	if (MULTI_MODE > 0) then
		ch_num = MULTI_MODE
	else
		ch_num = 1
	end	

	pg_write32(FLASH_KEYR, FLASH_KEY1)
 	pg_write32(FLASH_KEYR, FLASH_KEY2)
	pg_write32(FLASH_OPTKEYR, FLASH_KEY1)
 	pg_write32(FLASH_OPTKEYR, FLASH_KEY2)

	--start erase the option bytes
 	pg_write32(FMC_CTL, pg_read32(FMC_CTL) | FMC_CTL_OBER)
 	pg_write32(FMC_CTL, pg_read32(FMC_CTL) | FMC_CTL_START)

	FMC_WaitBusy()

	reg = pg_read32(FMC_CTL)
	reg = reg & ~FMC_CTL_OBER
	pg_write32(FMC_CTL, reg)	--reset the OBER bit
	pg_write32(FMC_CTL, pg_read32(FMC_CTL) | FMC_CTL_OBPG)	--set the OBPG bi

	ob_8 = hex_to_bin(ob)	--hex字符串转为二进制数组
	for i = 0, 3, 1 do
		ob_32 = string.byte(ob_8, 2 * i + 1) + (((~string.byte(ob_8, 2 * i + 1)) << 8) & 0xFF00) +
			(((string.byte(ob_8, 2 * i + 2)) << 16) & 0xFF0000) + (((~string.byte(ob_8, 2 * i + 2)) << 24) & 0xFF000000)
		pg_write32(0x1FFFF800 + 4 * i, ob_32)

		FMC_WaitBusy()
	end

	pg_write32(FMC_CTL, pg_read32(FMC_CTL) & ~FMC_CTL_OBPG)	--reset the OBPG bit

	--校验
	for i = 0, 3, 1 do
		ob_32 = string.byte(ob_8, 2 * i + 1) + (((~string.byte(ob_8, 2 * i + 1)) << 8) & 0xFF00) +
			(((string.byte(ob_8, 2 * i + 2)) << 16) & 0xFF0000) + (((~string.byte(ob_8, 2 * i + 2)) << 24) & 0xFF000000)

		ob_read = {pg_read32(0x1FFFF800 + 4 * i)}		
		for j = 1,ch_num,1 do			
			if (ob_32 ~= ob_read[j]) then
				err = "error"
			end			
		end
	end

	return err
end

--【F1】复位期间执行的函数. 目的:debug期间冻结看门狗时钟,低功耗模式启动HCLK和FCLK
function InitUnderReset(void)
	local str = "error"

	print("InitUnderReset()")

	if (pg_write32(0x40015804, 0x00000307) == 0) then
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
	
	g_DevID = {pg_read32(0x40015800)} --全局变量g_DevID[]

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
