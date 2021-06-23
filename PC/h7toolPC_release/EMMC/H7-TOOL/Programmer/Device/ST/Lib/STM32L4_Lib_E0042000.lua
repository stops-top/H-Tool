-------------------------------------------------------
-- 文件名 : STM32L4_Lib_E0042000.lua
-- 版  本 : V1.0  2020-07-18
-- 说  明 : 适用于 F4 F2 F3 F7 G4 L1 L4
-------------------------------------------------------

-- 10:18:32:390 : Bank : 0x00
-- 10:18:32:390 : Address : 0x40022020
-- 10:18:32:390 : Size : 20 Bytes
-- 10:18:32:391 : Reading data...
-- 10:18:32:391 : r ap 0 @0x40022020 0x00000014 bytes
-- 10:18:32:392 : Bank : 0x01
-- 10:18:32:392 : Address : 0x40022044
-- 10:18:32:393 : Size : 16 Bytes
-- 10:18:32:393 : Reading data...
-- 10:18:32:393 : r ap 0 @0x40022044 0x00000010 bytes
-- 10:18:32:394 : Bank : 0x02
-- 10:18:32:394 : Address : 0x40022070
-- 10:18:32:395 : Size : 8 Bytes
-- 10:18:32:395 : Reading data...
-- 10:18:32:395 : r ap 0 @0x40022070 0x00000008 bytes
-- FLASH_KEYR		= 0x40022004
-- FLASH_OPTKEYR   = 0x40022008

-- FLASH_KEY1      = 0x45670123
-- FLASH_KEY2      = 0xCDEF89AB

-- FMC_STAT		= 0x4002200C
-- FMC_CTL         = 0x40022010
-- FMC_CTL_OBPG    = 0x00000010
-- FMC_CTL_OBER    = 0x00000020
-- FMC_CTL_START   = 0x00000040

-- FMC_STAT_BUSY   = 0x00000001
-- FMC_STAT_PGERR  = 0x00000004
-- FMC_STAT_PGAERR = 0x00000008
-- FMC_STAT_WPERR  = 0x00000010
-- FMC_STAT_ENDF   = 0x00000020

--判断data数组标志，全部为0则退出
-- function CheckFlagQuit0(data, mask)
	-- local j
	-- local ret
	-- local ch_num

	-- if (MULTI_MODE > 0) then
		-- ch_num = MULTI_MODE
	-- else
		-- ch_num = 1
	-- end

	-- ret = 0
	-- for j = 1,ch_num,1 do
		-- ret = ret | (data[j] & mask)
	-- end

	-- return ret
-- end

--芯片专有的解除保护函数
-- function MCU_RemoveProtect(void)
	-- return MCU_ProgOptionBytes(OB_SECURE_OFF)
-- end

-- function FMC_WaitBusy(t100ms)
	-- local i
	-- local reg = {}
	-- local re = "error"
	-- local ch_num

	-- if (MULTI_MODE > 0) then
		-- ch_num = MULTI_MODE
	-- else
		-- ch_num = 1
	-- end	
	
	-- if (t100ms == nil) then
		-- t100ms = 50
	-- end
	
 	-- for i = 1, t100ms, 1 do
 		-- reg = {pg_read32(FMC_STAT)}

		--解除读保护过程中读状态字会失败，必须成功读取后才能判断标志
		-- if (reg[ch_num + 1] == 1) then 
			-- if (CheckFlagQuit0(reg, FMC_STAT_BUSY) == 0) then
				-- re = "OK"
				-- break
			-- end
		-- end
		-- delayms(100)
	-- end
	-- return re
-- end

--没有FLM的MCU，用脚本实现编程OB。 返回 "OK" or "error"
-- function MCU_ProgOptionBytes(ob)
	-- local i
	-- local j
	-- local reg
	-- local ob_8
	-- local ob_16
	-- local ob_read = {}
	-- local err = "OK"
	-- local ch_num

	-- if (MULTI_MODE > 0) then
		-- ch_num = MULTI_MODE
	-- else
		-- ch_num = 1
	-- end

		
	-- pg_write32(FLASH_KEYR, FLASH_KEY1)
 	-- pg_write32(FLASH_KEYR, FLASH_KEY2)
	-- pg_write32(FLASH_OPTKEYR, FLASH_KEY1)
 	-- pg_write32(FLASH_OPTKEYR, FLASH_KEY2)

	--start erase the option bytes
	-- print("---Erase the option bytes---")
 	-- pg_write32(FMC_CTL, pg_read32(FMC_CTL) | FMC_CTL_OBER)
 	-- pg_write32(FMC_CTL, pg_read32(FMC_CTL) | FMC_CTL_START)

	-- if (FMC_WaitBusy(5) ~= "OK") then
		-- print("Erase the option bytes error")
		-- goto quit_err
	-- end
	
	-- reg = pg_read32(FMC_CTL)
	-- reg = reg & ~FMC_CTL_OBER
	-- pg_write32(FMC_CTL, reg)	--reset the OBER bit
	
	-- pg_write32(FMC_CTL, pg_read32(FMC_CTL) | FMC_CTL_OBPG)	--set the OBPG bi

	-- ob_8 = hex_to_bin(ob)	--hex字符串转为二进制数组
	
	-- for i = 0, 7, 1 do
		-- ob_16 = string.byte(ob_8, i + 1) + (((~string.byte(ob_8, i + 1)) << 8) & 0xFF00)		
		
		-- pg_write16(0x1FFFF800 + 2 * i, ob_16)

		-- delayms(10)
		
		-- if (FMC_WaitBusy() ~= "OK") then
			-- goto quit_err
		-- end
		

	-- end
	
	-- pg_write32(FMC_CTL, pg_read32(FMC_CTL) & ~FMC_CTL_OBPG)	--reset the OBPG bit

	--校验
	-- print("---Verify OB---")
	-- for i = 0, 7, 1 do
		-- ob_16 = string.byte(ob_8, i + 1) + (((~string.byte(ob_8, i + 1)) << 8) & 0xFF00)
		-- ob_read = {pg_read16(0x1FFFF800 + 2 * i)}
		
		-- for j = 1,ch_num,1 do
			-- if (ob_16 ~= ob_read[j]) then
				-- err = "error"
			-- end
		-- end
	-- end

-- ::quit_err::
	-- return err
-- end

--复位期间执行的函数. 目的:debug期间冻结看门狗时钟,低功耗模式启动HCLK和FCLK
function InitUnderReset(void)
	local str = "error"

	print("InitUnderReset()")

	if (pg_write32(0xE0042004, 0x00000007) == 0) then
		goto quit_err
	end

	if (pg_write32(0xE0042008, 0x00001800) == 0) then
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
			if (ABORT_ON_ERROR == 1) then
				err = 1
			end
		end
	end

	print(str)
	return err
end

---------------------------结束-----------------------------------
