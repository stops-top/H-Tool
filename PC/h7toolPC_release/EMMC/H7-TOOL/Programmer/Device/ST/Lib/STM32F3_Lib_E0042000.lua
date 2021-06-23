-------------------------------------------------------
-- 文件名 : STM32F3_Lib_E0042000.lua
-- 版  本 : V1.0  2020-07-18
-- 说  明 : 适用于 F4 F2 F3 F7 G4 L1 L4
-------------------------------------------------------

--【F4 F2 F3 F7 G4 L1 L4】复位期间执行的函数. 目的:debug期间冻结看门狗时钟,低功耗模式启动HCLK和FCLK
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
