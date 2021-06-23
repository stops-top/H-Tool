-------------------------------------------------------
-- 文件名 : RT105x_Lib.lua
-- 版  本 : V1.0  2020-07-18
-- 说  明 : 适用于 RT1050
-------------------------------------------------------

-- uid 
function MCU_ReadUID(void)
	local id1 = {}
	local id2 = {}
	local ch_num
	local j
	local uid = {"","","",""}

	if (MULTI_MODE > 0) then
		ch_num = MULTI_MODE
	else
		ch_num = 1
	end
	
	--RT1052，UID在FUSEMAP区，2个32bit组合而成
	id1 = {pg_read_mem(0x401F4410, 4)}	
	id2 = {pg_read_mem(0x401F4420, 4)}
	
	for j = 1, ch_num, 1 do
		uid[j] = id1[j + 1]..id2[j + 1]
	end

	return 1, uid[1],uid[2],uid[3],uid[4]
end


--复位期间执行的函数. 目的:debug期间冻结看门狗时钟,低功耗模式启动HCLK和FCLK
function InitUnderReset(void)
	local str = "error"

	print("InitUnderReset()")

	-- if (pg_write32(0x40015804, 0x00000006) == 0) then
		-- goto quit_err
	-- end

	-- if (pg_write32(0x40015808, 0x00001800) == 0) then
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
