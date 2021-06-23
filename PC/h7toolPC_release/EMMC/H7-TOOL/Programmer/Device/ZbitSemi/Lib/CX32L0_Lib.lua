-------------------------------------------------------
-- 文件名 : CX32L0_Lib.lua
-- 版  本 : V1.0  2020-07-18
-- 说  明 : 
-------------------------------------------------------

--解除SWD锁
function RemoveSwdLock(void)
	pg_iap("CX32L003", "remove_swd_lock")
end

--复位期间执行的函数. 目的:debug期间冻结看门狗时钟,低功耗模式启动HCLK和FCLK
function InitUnderReset(void)
	local str = "error"
	
	print("InitUnderReset()")

	--解除寄存器写入保护
	if (pg_write32(0x40020060, 0x55AA6699) == 0) then
		goto quit_err
	end
	
	--开始debug模块时钟
	if (pg_write32(0x4002000C, 0x00100000) == 0) then
		goto quit_err
	end
	
	--调试期间禁止看门狗时钟
	if (pg_write32(0x40004C00, 0x5A690600) == 0) then
		goto quit_err
	end
	
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
			if (ABORT_ON_ERROR == 1) then
				err = 1
			end
		end
	end

	print(str)
	return err
end

---------------------------结束-----------------------------------
