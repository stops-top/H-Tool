-------------------------------------------------------
-- 文件名 : prog_lib.lua
-- 说  明 : 公共lua子程序
-- Copyright (C), 2020-2030, 安富莱电子 www.armfly.com
-------------------------------------------------------
PROG_LIB_FILE_VER = 1.6  --文件版本

print("load \"prog_lib.lua\" ok. version = ",PROG_LIB_FILE_VER)

--编程入口
function start_prog(void)
	return prog_or_erase(0)
end

--擦除入口
function erase_chip_mcu(void)
	return prog_or_erase(1)
end

--擦除入口
function erase_chip_eeprom(void)
	return prog_or_erase(2)
end

--编程或者擦除公共函数
function prog_or_erase(mode)
	local err = ""
	local str
	local mi_error = {0,0,0,0}  --机台烧录错误信号
	
	g_id = {0,0,0,0}	--全局变量，芯片core id

	pg_reload_var("StarPorgTime")	--用于更新烧录开始时间

	if (mi_begin ~= nil) then
		mi_begin() --机台控制信号
	end
	
	if (MULTI_MODE == 0) then
		print("单路烧录")
	elseif (MULTI_MODE == 1) then
		print("多路烧录 1路")
	elseif (MULTI_MODE == 2) then
		print("多路烧录 1-2路")
	elseif (MULTI_MODE == 3) then
		print("多路烧录 1-3路")
	elseif (MULTI_MODE == 4) then
		print("多路烧录 1-4路")
	else
		print("多路烧录, 通道数量参数错误", MULTI_MODE)
		err = "通道参数错误"
		goto quit		
	end

	config_chip1()		--配置烧录参数

	if (CHIP_TYPE == "SWD") then
		print("SWCLK时钟延迟: ", SWD_CLOCK_DELAY)
	else if (CHIP_TYPE == "SWIM") then
		print("Device  = "..DEVICE)
		print(" flash  size = ", FLASH_SIZE)
		print(" eeprom size = ", EEPROM_SIZE)
		if (FLASH_SIZE == nil or EEPROM_SIZE == nil) then
			err = "chip name is invalid"
			goto quit
		end
	end
	end

--	set_tvcc(0)			--断电
--	delayms(20)
	set_tvcc(TVCC_VOLT)	--设置TVCC电压
--	delayms(20)

	if (RemoveSwdLock ~= nil)  then
		RemoveSwdLock()
	end
	
	if (MULTI_MODE > 0) then
		local i
		local CanProg = 0

		g_id = {pg_detect_ic()}
		str = string.format("core_id: = 0x%08X 0x%08X 0x%08X 0x%08X", g_id[1], g_id[2], g_id[3], g_id[4])
		print(str)
		
		if (ABORT_ON_ERROR == 1) then	--必须检测到全部IC
			CanProg = 1
			for i = 1, MULTI_MODE, 1 do
				if (g_id[i] == 0) then
					CanProg = 0
					break
				end
			end
		else	--检测到至少1个IC即可继续编程
			CanProg = 0
			for i = 1, MULTI_MODE, 1 do
				if (g_id[i] > 0) then
					CanProg = 1
					break
				end
			end
		end
		
		if (CanProg == 1) then
			if (mode == 0) then --编程
				config_fix_data()	--在用户lua程序部分实现这个函数
				if (CHIP_TYPE == "SWD") then
					err = swd_start_prog()	--编程ARM (SWD)
				else
					G_CHIP_ERASED = 0	--如果整片已擦除，后面编程文件时无需再擦除
					err = swim_start_prog()	--编程STM8 (SWIM) 新唐51
				end
			else	--mode == 1 擦除
				if (mode == 1) then
					if (MCU_EraseMass == nil) then
						err = erase_chip(FLASH_ADDRESS)	--擦除CPU Flash
					else
						err = MCU_EraseMass()		--新唐arm需要单独的整片擦除指令
					end
				else
					if (EEPROM_ADDRESS ~= nil) then
						err = erase_chip(EEPROM_ADDRESS)	--擦除CPU EEPROM
					else
						print("MCU未配置EEPROM")
					end
				end
			end
			if (err ~= "OK") then
				mi_error = {pg_read_c_var("MultiProgError")}
				goto quit 
			end
			
			goto quit
		end

		err = "未检测到IC"
		for i = 1, MULTI_MODE, 1 do
			if (g_id[i] == 0) then
				err = string.format("%s #%d", err, i)
				mi_error[i] = 1		--发NG信号
			else
				--终止任务后NG信号策略, 0全部发NG  1仅错误通道发NG
				if (ABORT_NG_MODE == 1) then
					mi_error[i] = 2	--2是特殊值，不发NG信号也不发OK信号
				else
					mi_error[i] = 1	--发NG信号
				end
			end
		end

	else
		g_id = {pg_detect_ic()}
		if (g_id[1] > 0) then
			str = string.format("core_id = 0x%08X", g_id[1])
			print(str)

			--核对core id
			if (CHECK_MCU_ID == 1) then
				if (g_id[1] ~= MCU_ID) then
					err = "MCU ID不正确"
					pg_print_text(err)
					goto quit
				end
			end

			if (mode == 0) then --编程
				if (CHIP_TYPE == "SWD") then
					err = swd_start_prog()	--编程ARM (SWD)
				else
					err = swim_start_prog()	--编程STM8 (SWD)
				end
			else	--擦除
				if (mode == 1) then
					err = erase_chip(FLASH_ADDRESS)	--擦除CPU Flash
				else
					if (EEPROM_ADDRESS ~= nil) then
						err = erase_chip(EEPROM_ADDRESS)	--擦除CPU EEPROM
					else
						print("MCU未配置EEPROM")
					end
				end
			end
			if (err ~= "OK") then 
				goto quit 
			end

			goto quit
		end

		mi_error[0] = 1
		err = "未检测到IC"
	end

::quit::
	if (err == "OK") then
		local i
		local MulErr
		
		mi_error = {pg_read_c_var("MultiProgError")}
	
		MulErr = 0
		for i = 1, 4, 1 do
			if (mi_error[i] == 1) then
				MulErr = 1
			end
		end
	
		if (MulErr == 1) then
			beep(20,1,1) --成功叫1次，长鸣
		else
			beep() --成功叫1次
		end
		
		if (MULTI_MODE == 0) then
			pg_print_text("编程成功")
		else
			str = "成功:"
			for i = 1,MULTI_MODE,1 do
				if (mi_error[i] == 0) then
					str = string.format("%s#%d", str, i)
				end
			end

			if (MulErr == 1) then
				str = str.." 失败:"
				for i = 1,MULTI_MODE,1 do
					if (mi_error[i] ~= 0) then
						str = string.format("%s#%d", str, i)
					end
				end			 
			end
			
			pg_print_text(str)
		end
	else		
		beep(5, 5, 3) --失败叫3次
		if (err ~= "error") then
			pg_print_text(err)
		end
	end
		
	if (mi_abort ~= nil) then
		mi_abort(mi_error)	--烧录终止, 有1个失败，则都终止
	end	
	return err
end

--判断芯片移除（用于连续烧录）
function CheckChipRemove(void)
	if (MULTI_MODE > 0) then
		local id1
		local id2
		local id3
		local id4

		id1,id2,id3,id4 = pg_detect_ic(1)
		if (MULTI_MODE == 1) then
			if (id1 == 0) then
				return "removed"
			end
		end
		if (MULTI_MODE == 2) then
			if (id1 == 0 and id2 == 0) then
				return "removed"
			end
		end
		if (MULTI_MODE == 3) then
			if (id1 == 0 and id2 == 0 and id3 == 0) then
				return "removed"
			end
		end
		if (MULTI_MODE == 4) then
			if (id1 == 0 and id2 == 0 and id3 == 0 and id4 == 0) then
				return "removed"
			end
		end
	else
		local core_id

		core_id = pg_detect_ic(1)
		if (core_id == 0) then
			return "removed"
		end
	end

	return "no"
end

--判断芯片插入（用于连续烧录）
function CheckChipInsert(void)
	config_chip1()

	if (MULTI_MODE > 0) then
		local id
		local id1
		local id2
		local id3
		local id4

		id1,id2,id3,id4 = pg_detect_ic(1)
		if (MULTI_MODE == 1) then
			if (id1 > 0) then
				return "inserted"
			end
		end
		if (MULTI_MODE == 2) then
			if (id1 > 0 and id2 > 0) then
				return "inserted"
			end
		end
		if (MULTI_MODE == 3) then
			if (id1 > 0 and id2 > 0 and id3 > 0) then
				return "inserted"
			end
		end
		if (MULTI_MODE == 4) then
			if (id1 > 0 and id2 > 0 and id3 > 0 and id4 > 0) then
				return "inserted"
			end
		end
	else
		local core_id

		core_id = pg_detect_ic(1)
		if (core_id > 0) then
			return "inserted"
		end
	end

	return "no"
end

-------------------------------------------------------
-- 下面的代码一般无需修改
-------------------------------------------------------

--开始编程SWD接口芯片
--供电-擦除全片-动态生成SN、UID加密数据、用户数据
--编程文件(自动擦除、编程、校验)
--写OPTION BYTES
function swd_start_prog(void)
	local err = "OK"
	local re
	local core_id
	local uid_bin
	local str
	local mcu_uid
	local ob_data = {}
	local i
	local ch_num
		
	if (MULTI_MODE > 0) then
		ch_num = MULTI_MODE
	else
		ch_num = 1
	end

	if (check_limit_1() == 1) then
		err = "error"
		goto quit
	end

	--判断读保护和写保护，如果保护了则执行解锁操作
	if (AUTO_REMOVE_PROTECT == 1) then
		local remove_protect

		print("检查读写保护...")
				
		remove_protect = 0;
		for i = 1, #OB_WRP_ADDRESS, 1 do
			local wrp
			local prot

			if (MCU_ReadOptionByte ~= nil) then
				ob_data = {MCU_ReadOptionByte(OB_WRP_ADDRESS[i])}
			else
				ob_data = {pg_read_mem(OB_WRP_ADDRESS[i], 1)}
			end

			if (ob_data[1] == 0) then
				print("  读寄存器失败")
				pg_print_text("  已保护，设置读保护")
				remove_protect = 1
				break
			else
				str = string.format("  0x%08X ：", OB_WRP_ADDRESS[i])
				prot = 0
				for j = 1, ch_num, 1 do
					if (MCU_ReadOptionByte ~= nil) then
						wrp = ob_data[j + 1]
					else
						wrp = tonumber(string.byte(ob_data[j + 1],1,1))
					end
					if (g_id[j] > 0 and ((wrp & OB_WRP_MASK[i]) ~= OB_WRP_VALUE[i])) then
						prot = 1
						remove_protect = 1
					end
					
					str = str..string.format("0x%02X ", wrp)
				end
				str = str..string.format("& 0x%02X == 0x%02X", OB_WRP_MASK[i], OB_WRP_VALUE[i])
				if (prot == 1) then
					str = str.."(已保护)"
				end
				print(str)
			end
		end

		if (remove_protect == 1) then
			pg_print_text("正在解除保护...")
			
			if (MCU_RemoveProtect ~= nil) then
				print("MCU_RemoveProtect()")
				MCU_RemoveProtect()
			end
	
			err = set_read_protect(0)		--解除读保护，内部有复位操作					
			if (err ~= "OK") then
				goto quit
			end
		else
			print("  无保护")
		end
	end

	fix_data_begin()			--开始动态填充SN UID USR数据
	pg_reload_var("FixData")  	--用于更新c程序的全局变量

	if (check_limit_2() ~= 0) then
		pg_print_text("UID未授权")
		err = "error"
		goto quit
	end

	for i = 1, #TaskList, 4 do		
		if (TaskList[i] ~= "") then
			local EndAddress
			local j
			
			print("------------------------")
			str = string.format("FLM : %s", TaskList[i])  print(str)
			str = string.format("Data: %s", TaskList[i + 1]) print(str)
			str = string.format("Addr: 0x%08X, %X", TaskList[i + 2], TaskList[i + 3]) print(str)

			--加载flash算法文件

			re = pg_load_algo_file(TaskList[i], AlgoRamAddr, AlgoRamSize)
			if (re == 0) then
				err = "加载flash算法失败"  goto quit
			end

			--形参增加FLASH结束地址，避免滚码重复写入
			EndAddress = 0xFFFFFFFF
			for j = 1, #TaskList, 4 do
				if (TaskList[i] ~= TaskList[j]) then
					if (TaskList[j + 2] < EndAddress) then
						EndAddress = TaskList[j + 2]
					end
				end
			end		

			--pg_prog_file(数据文件, 目标地址, 结束地址，整片擦除，文件序号)
			re = pg_prog_file(TaskList[i + 1], TaskList[i + 2], EndAddress, TaskList[i + 3], i, TaskList[i])

			if (re == 0) then
				err = "error" goto quit 	--pg_prog_file内部已显示出错信息
			end
		else
			err = "算法文件为空"  goto quit
		end
	end

	--写OPTION BYTES (读保护也在内）
	if (OB_ENABLE == 1) then
		--pg_print_text("写option bytes")
		if (SECURE_ENABLE == 0) then
			set_read_protect(0)
		else
			set_read_protect(1)
		end
		if (re == 0) then
			err = "写选项字失败"  goto quit
			goto quit
		else

		end
	end

	--复位
	if (RESET_AFTER_COMPLETE == 1) then
		pg_reset()
	end

::quit::
	return err
end

--开始编程,步骤：
--供电-擦除全片-动态生成SN、UID加密数据、用户数据
--编程文件(自动擦除、编程、校验)
--写OPTION BYTES
function swim_start_prog(void)
	local err = "OK"
	local re
	local uid_bin
	local str
	local mcu_uid
	local i
	local bin
	local ff
	local ch_num
		
	if (MULTI_MODE > 0) then
		ch_num = MULTI_MODE
	else
		ch_num = 1
	end
	
	--设置TVCC电压
	set_tvcc(TVCC_VOLT)
	delayms(20)

	pg_init()

	if (check_limit_1() == 1) then
		err = "error"
		goto quit
	end

	--判断读保护和写保护，如果保护了则执行解锁操作
	if (AUTO_REMOVE_PROTECT == 1) then
	if (CHIP_TYPE == "SWIM") then
		--先设置读保护，再解除读保护。自动擦除全片。
		pg_print_text("擦除全片")
		--先加保护再解除保护，达到清空芯片的目的
		set_read_protect(1)
		pg_init()
		set_read_protect(0)	
	else
		local remove_protect
		local ob_data = {}
					
		print("检查读写保护...")
		remove_protect = 0;
		for i = 1, #OB_WRP_ADDRESS, 1 do
			local wrp
			local prot

			if (MCU_ReadOptionByte ~= nil) then
				ob_data = {MCU_ReadOptionByte(OB_WRP_ADDRESS[i])}
			else
				ob_data = {pg_read_mem(OB_WRP_ADDRESS[i], 1)}
			end

			if (ob_data[1] == 0) then
				print("  读寄存器失败")
				pg_print_text("  已保护，设置读保护")
				remove_protect = 1
				break
			else
				str = string.format("  0x%08X ：", OB_WRP_ADDRESS[i])
				prot = 0
				for j = 1, ch_num, 1 do
					if (MCU_ReadOptionByte ~= nil) then
						wrp = ob_data[j + 1]
					else
						wrp = tonumber(string.byte(ob_data[j + 1],1,1))
					end

					if ((wrp & OB_WRP_MASK[i]) ~= OB_WRP_VALUE[i]) then
						prot = 1
						remove_protect = 1
					end
					
					str = str..string.format("0x%02X ", wrp)
				end
				str = str..string.format("& 0x%02X == 0x%02X", OB_WRP_MASK[i], OB_WRP_VALUE[i])
				if (prot == 1) then
					str = str.."(已保护)"
				end
				print(str)
			end
		end

		if (remove_protect == 1) then
			pg_print_text("正在解除保护...")
			
			err = set_read_protect(0)		--解除读保护，内部有复位操作					
			if (err ~= "OK") then
				goto quit
			end
			
			G_CHIP_ERASED = 1	--整片已擦除，后面编程文件时无需再擦除
		else
			print("  无保护")
		end		
		
	end	--if (CHIP_TYPE == "SWIM")		
	end --if (AUTO_REMOVE_PROTECT == 1)

	--动态填充SN UID USR数据
	fix_data_begin()
	pg_reload_var("FixData")  	--用于更新c程序的全局变量
	
	if (check_limit_2() ~= 0) then
		pg_print_text("UID未授权")
		err = "error"
		goto quit
	end

	--编程文件（查空、擦除、编程、校验）
	for i = 1, #TaskList, 4 do
		if (TaskList[i+1] ~= "") then
			local EndAddress
			local j
			
			print("------------------------")
			
			if (CHIP_TYPE == "SWD") then
				str = string.format("FLM : %s", TaskList[i])  print(str)
				str = string.format("Data: %s", TaskList[i + 1]) print(str)
				str = string.format("Addr: 0x%08X, %X", TaskList[i + 2], TaskList[i + 3]) print(str)

				pg_print_text("编程文件")
				--加载flash算法文件

				re = pg_load_algo_file(TaskList[i], AlgoRamAddr, AlgoRamSize)
				if (re == 0) then
					err = "加载flash算法失败"  goto quit
				end
			else
				str = string.format("File : %s", TaskList[i + 1])  print(str)
			end
			
			--形参增加FLASH结束地址，避免滚码重复写入
			EndAddress = 0xFFFFFFFF
			for j = 1, #TaskList, 4 do
				if (TaskList[i] ~= TaskList[j]) then
					if (TaskList[j + 2] < EndAddress) then
						EndAddress = TaskList[j + 2]
					end
				end
			end	
			--pg_prog_file(数据文件, 目标地址, 结束地址，整片擦除控制字，文件序号, 算法名)
			re = pg_prog_file(TaskList[i + 1], TaskList[i + 2], EndAddress, TaskList[i + 3], i, TaskList[i])
			if (re == 0) then
				err = "编程失败"  goto quit
				goto quit
			end
		end
	end

	--写OPTION BYTES (读保护也在内）
	if (OB_ENABLE == 1) then
		print("------------------------")
		pg_print_text("写option bytes")
		if (SECURE_ENABLE == 0) then
			set_read_protect(0)
		else
			set_read_protect(1)
		end
		if (re == 0) then
			err = "写OPTION BYTES失败"  goto quit
			goto quit
		else

		end
	end

	--复位
	if (RESET_AFTER_COMPLETE == 1) then
		pg_reset()
	end

::quit::
	return err
end

--检查限制条件1,返回0表示OK, 1表示禁止烧录 [可以在烧录最初检测的]
function check_limit_1(uid)
  local ret = 0

  if (DEADLINE_ENABLE == 1) then
    local now = os.date("%Y-%m-%d %H:%M:%S")
    if (now >= DEADLINE_DATE) then
      ret = 1
      pg_print_text("已到截止时间")
    end

    if (now < "2020-08-01 00:00:00") then
      ret = 1
      pg_print_text("烧录器时钟不正确")
    end	
  end

  return ret
end

--检查限制条件2, 返回0表示OK, 1表示禁止烧录 [必须在芯片解除保护后检测的]
function check_limit_2(void)
	local ret = 0
	local ch_num
	local uid

	if (MULTI_MODE > 0) then
		ch_num = MULTI_MODE
	else
		ch_num = 1
	end

	--UID全局变量
	if (UID_CHECK_ENABLE == 1) then
		local mask = {}
		local xid = ""
		local yid = ""
		local i
		local j
		local m

		if (UID[1] == 0) then
			ret = 1
			goto quit
		end

		for m = 1,ch_num,1 do
			ret = 1
			uid = UID[m + 1]
			for i = 1,#UID_TABLE,2 do
				mask = hex_to_bin(UID_TABLE[i])
				yid = hex_to_bin(UID_TABLE[i+1])
				xid = ""
				for j = 1,#uid,1 do
					xid = xid..string.char((string.byte(uid, j) & string.byte(mask, j)))
				end
				if (xid == yid) then
					ret = 0
					break
				end
			end

			if (ret ~= 0) then
				print("芯片UID未被授权", m)
				break
			end
		end
	end

::quit::
	return ret
end

--二进制字符串转换可见的hex字符串
function bin2hex(s)
	s = string.gsub(s,"(.)", function (x) return string.format("%02X ",string.byte(x)) end)
	return s
end

function hex2bin( hexstr )
	local h2b = {
	    ["0"] = 0,
	    ["1"] = 1,
	    ["2"] = 2,
	    ["3"] = 3,
	    ["4"] = 4,
	    ["5"] = 5,
	    ["6"] = 6,
	    ["7"] = 7,
	    ["8"] = 8,
	    ["9"] = 9,
	    ["A"] = 10,
	    ["B"] = 11,
	    ["C"] = 12,
	    ["D"] = 13,
	    ["E"] = 14,
	    ["F"] = 15
	}

    local s = string.gsub(hexstr, "(.)(.)%s", function ( h, l )
         return string.char(h2b[h]*16+h2b[l])
    end)
    return s
end

function bin2hex(bin)
	local s
	local i

	s = ""
	for i=1,#bin,1 do
		s = s..string.format("%02X ", string.byte(bin,i))
	end
	return s
end

--打印内存数据
function print_flash(_addr, _len, width, dispaddr, _delay)
	local re
	local bin
	local bin1
	local bin2
	local bin3
	local bin4
	local str
	local core_id
	local i
	local addr
	local len
	local n

	--设置TVCC电压
	set_tvcc(TVCC_VOLT)
	delayms(20)

	if (RemoveSwdLock ~= nil)  then
		RemoveSwdLock()
	end
	
	pg_init()

	n = (_len + 1023) / 1024
	addr = _addr

	for i = 1, n, 1 do
		if (_len > 1024) then
			len = 1024
		else
			len = _len
		end

		if (MULTI_MODE > 0) then
			re,bin1,bin2,bin3,bin4 = pg_read_mem(addr, len)
			if (re == 1) then
				if (MULTI_MODE >= 1) then
					str = string.format("#1 address = 0x%08X, len = %d", addr, len)
					print(str)
					if (width == nil) then
						print_hex(bin1,16)
					else
						if (dispaddr == nil) then
							print_hex(bin1,width)
						else
							print_hex(bin1,width, dispaddr)
						end
					end
					delayms(5)
				end

				if (MULTI_MODE >= 2) then
					str = string.format("#2 address = 0x%08X, len = %d", addr, len)
					print(str)
					if (width == nil) then
						print_hex(bin2,16)
					else
						if (dispaddr == nil) then
							print_hex(bin2,width)
						else
							print_hex(bin2,width, dispaddr)
						end
					end
					delayms(5)
				end

				if (MULTI_MODE >= 3) then
					str = string.format("#3 address = 0x%08X, len = %d", addr, len)
					print(str)
					if (width == nil) then
						print_hex(bin3,16)
					else
						if (dispaddr == nil) then
							print_hex(bin3,width)
						else
							print_hex(bin3,width, dispaddr)
						end
					end
					delayms(5)
				end

				if (MULTI_MODE == 4) then
					str = string.format("#4 address = 0x%08X, len = %d", addr, len)
					print(str)
					if (width == nil) then
						print_hex(bin4,16)
					else
						if (dispaddr == nil) then
							print_hex(bin4,width)
						else
							print_hex(bin4,width, dispaddr)
						end
					end
					delayms(5)
				end
			else
				str = "error"
				print(str)
			end
		else
			re,bin = pg_read_mem(addr, len)
			if (re == 1) then
				str = string.format("address = 0x%08X, len = %d", addr, len)
				print(str)
				if (width == nil) then
					print_hex(bin,16)
				else
					if (dispaddr == nil) then
						print_hex(bin,width)
					else
						print_hex(bin,width, dispaddr)
					end
				end
			else
				str = "error"
				print(str)
			end
		end

		_len = _len - len
		addr = addr + len

		if (dispaddr ~= nil) then
			dispaddr = addr
		end

		if (_delay ~= nil) then
			delayms(_delay)
		else
			delayms(20)
		end
	end
end

--打印OPTION BYTES
function print_option_bytes(void)

	print_core_id()

	if (MCU_Init~= nil) then
		MCU_Init()
	end
	
	print("Option bytes Address:")
	print(OB_ADDRESS)
		
	if (MULTI_MODE > 0) then
		local re
		local bin1
		local bin2
		local bin3
		local bin4

		if (MCU_ReadOB ~= nil) then
			re,bin1,bin2,bin3,bin4 = MCU_ReadOB()
		else
			re,bin1,bin2,bin3,bin4 = pg_read_ob(OB_ADDRESS)
		end

		if (re == 1) then
			if (MULTI_MODE >= 1) then
				print("#1 Option bytes data:")
				print_hex(bin1)
			end

			if (MULTI_MODE >= 2) then
				print("#2 Option bytes data:")
				print_hex(bin2)
			end

			if (MULTI_MODE >= 3) then
				print("#3 Option bytes data:")
				print_hex(bin3)
			end

			if (MULTI_MODE >= 4) then
				print("#4 Option bytes data:")
				print_hex(bin4)
			end
		else
			print("error")
		end
	else
		local re
		local bin

		print("Option bytes data:")
		
		if (MCU_ReadOB ~= nil) then
			re,bin = MCU_ReadOB()
		else
			re,bin = pg_read_ob(OB_ADDRESS)
		end

		if (re == 1) then
			print_hex(bin)
		else
			print("error")
		end
	end
end

--设置读保护 0 表示解除读保护，1表示启用读保护
function set_read_protect(on)
	local re
	local err = "OK"
	local time1
	local time2
	local str

	if (REMOVE_RDP_POWEROFF == nil) then
		REMOVE_RDP_POWEROFF = 0
	end

	print("\r\n写选项字...")

	time1 = get_runtime()

--	--设置TVCC电压
--	set_tvcc(TVCC_VOLT)
--	delayms(20)
--
--	--检测IC,打印内核ID
--	local core_id = pg_detect_ic()
--	if (core_id == 0) then
--		err = "未检测到IC"  print(err) return err
--	else
--		str = string.format("core_id = 0x%08X", core_id)
--		print(str)
--	end

	if (CHIP_TYPE == "SWD") then
		if (MCU_ProgOptionBytes == nil) then
			if (AlgoFile_OPT == "") then
				err = "没有OPT算法文件"  print(err) return err
			end

			--加载flash算法文件
			re = pg_load_algo_file(AlgoFile_OPT, AlgoRamAddr, AlgoRamSize)
			if (re == 0) then
				err = "加载flash算法失败"  print(err) return err
			end
		end
	else
		--STM8 N76E专用的解除保护
		if (MCU_RemoveProtect ~= nil) then
			if (on == 0) then
				print("MCU_RemoveProtect()")
				MCU_RemoveProtect()
			end
		end
	end

	if (on == 0) then
		local i

		print("OB_SECURE_OFF = ", OB_SECURE_OFF)
		for i = 1, 3, 1 do
			if (MCU_ProgOptionBytes ~= nil) then
				err = MCU_ProgOptionBytes(OB_SECURE_OFF)
				if (err == "OK") then
					re = 1
				else
					re = 0
				end
			else
				re = pg_prog_buf_ob(OB_ADDRESS, OB_SECURE_OFF)
			end

			if (re == 0) then		--部分芯片需要2次操作来确认是否成功 （STM32L051)
				if (REMOVE_RDP_POWEROFF > 0) then
					print("  prog ob failed", i)
					delayms(POWEROFF_TIME1)
					print("  断电")
					set_tvcc(0)			--断电
					delayms(POWEROFF_TIME2)
					set_tvcc(TVCC_VOLT) --上电
					pg_reset()
					delayms(POWEROFF_TIME3)
					core_id = pg_detect_ic()	--MM32复位后必须读一次ID才能访问内存
				else
					print("  prog ob failed", i)
					delayms(100)
					pg_reset()
					delayms(100)
					core_id = pg_detect_ic()	--MM32复位后必须读一次ID才能访问内存
				end
			else	--成功
				if (REMOVE_RDP_POWEROFF > 0) then
					delayms(POWEROFF_TIME1)
					print("  断电")
					set_tvcc(0)			--断电
					delayms(POWEROFF_TIME2)
					set_tvcc(TVCC_VOLT) --上电
					pg_reset()
					delayms(POWEROFF_TIME3)
					core_id = pg_detect_ic()	--MM32复位后必须读一次ID才能访问内存
				else
					pg_reset()
					--delayms(100)
					core_id = pg_detect_ic()	--MM32复位后必须读一次ID才能访问内存					
				end				
				break
			end
		end
	else
		if (on == 1) then
			print("OB_SECURE_ON = ", OB_SECURE_ON)
			if (MCU_ProgOptionBytes ~= nil) then
				err = MCU_ProgOptionBytes(OB_SECURE_ON)
				if (err == "OK") then
					re = 1
				else
					re = 0
				end
			else
				re = pg_prog_buf_ob(OB_ADDRESS, OB_SECURE_ON)
			end
		end
	end

::quit::
	if (re == 0) then
		err = "写选项字失败"
	end
	time2 = get_runtime()

	if (err == "OK") then
		str = string.format("写选项字成功, 耗时 = %d ms", time2 - time1);
		print(str)
	else

	end

	return err
end

--解锁芯片=擦除芯片
function erase_chip(FlashAddr)
	local re
	local err = "OK"
	local time1
	local time2
	local str

	pg_print_text("擦除...")

	if (CHIP_TYPE == "SWD") then
		if (FlashAddr == FLASH_ADDRESS) then
			re = pg_load_algo_file(AlgoFile_FLASH, AlgoRamAddr, AlgoRamSize)	--加载flash算法文件
		else
			re = pg_load_algo_file(AlgoFile_EEPROM, AlgoRamAddr, AlgoRamSize)	--加载eeprom算法文件
		end
		if (re == 0) then
			err = "加载flash算法失败"  print(str) return err
		end
	else
		if (CHIP_TYPE == "SWIM") then
			if (FlashAddr == FLASH_ADDRESS) then
				str = string.format("开始擦除flash. 地址 : 0x%X 长度 : %dKB ", FlashAddr, FLASH_SIZE / 1024)
			else
				str = string.format("开始擦除eeprom. 地址 : 0x%X 长度 : %dB ", FlashAddr, EEPROM_SIZE)
			end
			print(str)
		else
			print("未知接口")
		end
	end

	time1 = get_runtime()

	--设置TVCC电压
	set_tvcc(TVCC_VOLT)
	delayms(20)

	pg_init()

	re = pg_erase_chip(FlashAddr)
	if (re == 1) then
		pg_print_text("擦除成功")
	else
		pg_print_text("擦除失败")
		err = "err"
	end
	time2 = get_runtime()

	str = string.format("执行时间 = %d ms", time2 - time1);
	print(str)
	return err
end

--显示内核id,
function print_core_id(void)
	local id
	local id1
	local id2
	local id3
	local id4
	local str

	set_tvcc(TVCC_VOLT)

	if (RemoveSwdLock ~= nil)  then
		RemoveSwdLock()
	end

	if (MULTI_MODE > 0) then
		id1,id2,id3,id4 = pg_detect_ic()
		str = string.format("core_id1 = 0x%08X", id1) print(str) delayms(5)
		str = string.format("core_id2 = 0x%08X", id2) print(str) delayms(5)
		str = string.format("core_id3 = 0x%08X", id3) print(str) delayms(5)
		str = string.format("core_id4 = 0x%08X", id4) print(str) delayms(5)
	else
		core_id = pg_detect_ic()
		if (core_id == 0) then
			print("未检测到IC")
		else
			str = string.format("core_id = 0x%08X", core_id) print(str)
		end
	end
end

--显示UID
function print_uid(void)
	local uid1,uid2,uid3,uid4
	local re
	local str

	str = string.format("UID Address = 0x%08X, Length = %d", UID_ADDR, UID_BYTES)
	print(str)

	if (MCU_Init~= nil) then
		MCU_Init()
	end

	if (MULTI_MODE > 0) then
		if (MCU_ReadUID == nil) then
			re,uid1,uid2,uid3,uid4 = pg_read_mem(UID_ADDR, UID_BYTES)
		else
			re,uid1,uid2,uid3,uid4 = MCU_ReadUID(UID_ADDR, UID_BYTES)
		end
		if (re == 1) then
			str = "uid1 = "..bin2hex(uid1) print(str) delayms(5)
			str = "uid2 = "..bin2hex(uid2) print(str) delayms(5)
			str = "uid3 = "..bin2hex(uid3) print(str) delayms(5)
			str = "uid4 = "..bin2hex(uid4) print(str) delayms(5)
		end
	else
		if (MCU_ReadUID == nil) then
			re,uid1 = pg_read_mem(UID_ADDR, UID_BYTES)
		else
			re,uid1 = MCU_ReadUID(UID_ADDR, UID_BYTES)
		end
		if (re == 1) then
			str = "uid1 = "..bin2hex(uid1) print(str) delayms(5)
		end
	end
end

--擦除CPU片外QSPI FLASH
function erase_chip_qspi(void)
	local core_id
	local str
	local addr
	local i
	local nSector
	local percent
	local time1
	local time2

	if (AlgoFile_QSPI == nil or AlgoFile_QSPI == "") then
		print("未配置QSPI Flash")
		return
	end

	print("开始擦除QSPI Flash...")

	time1 = get_runtime()

	config_chip1()		--配置烧录参数
	--set_tvcc(0)			--断电
	--delayms(20)
	set_tvcc(TVCC_VOLT)	--设置TVCC电压

	core_id = pg_detect_ic()
	if (core_id > 0) then
		str = string.format("swd : core_id = 0x%08X", core_id)
		print(str)
	end

	--加载flash算法文件
	re = pg_load_algo_file(AlgoFile_QSPI, AlgoRamAddr, AlgoRamSize)

	addr = 0x90000000
	nSector = 32 * 1024 / 64
	for i = 1, nSector,1 do
		pg_erase_sector(addr)

		percent = 100 * i / nSector;
		str = string.format("erase 0x%08X, %0.2f%%", addr, percent)
		print(str)
		addr = addr + 64 * 1024
	end

	time2 = check_runtime(time1)
	str = string.format("擦除结束  %0.3f 秒", time2 / 1000)
	print(str)
end

---------------------------结束-----------------------------------
