-------------------------------------------------------
-- 文件名 : M2Sxxx_Lib.lua
-- 版  本 : V1.0  2020-07-18
-- 说  明 : 未完善
-------------------------------------------------------

--没有UID，固定返回0

--复位期间执行的函数. 目的:debug期间冻结看门狗时钟,低功耗模式启动HCLK和FCLK
function InitUnderReset(void)
	local str = "error"
	
	print("InitUnderReset()")

	--403A 407系列缺省没有开PWR标志位
	-- if (pg_write32(RCC_APB1ENR_M3M0_M3N4, 0x10000000) == 0) then
		-- goto quit_err
	-- end
	
	-- if (pg_write32(0xE0042004, 0x00000307) == 0) then
		-- goto quit_err
	-- end

	-- if (ReadDeviceID() ~= 0) then
		-- goto quit_err
	-- end

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
