-------------------------------------------------------
-- 文件名 : fix_data.lua
-- 说  明 : 用于烧录产品序号、程序UID加密字符、自定义字符串
-- Copyright (C), 2020-2030, 安富莱电子 www.armfly.com
-------------------------------------------------------
FIX_DATA_FILE_VER = 1.1  --文件版本

print("load \"fix_data.lua\" ok. version = ", FIX_DATA_FILE_VER)

--返回C程序用的table，结构为 {
--  文件编号,通道号,地址,二进制数据
--  1, 0, 0x08000000, "1234567",   0表示全部通道数据一样， 1表示第1通，4表示4通道
--  1, 1, 0x08000200, "AAA",
--  1, 2, 0x08000300, "BBBB",
-- }

FIX_TABLE = {}		--全局变量
	
--修正数据前执行一次
function fix_data_begin(void)
	local idx = 1
	local ch_num
	local i
	local j
	local k

	if (MULTI_MODE > 0) then
		ch_num = MULTI_MODE
	else
		ch_num = 1
	end

	--计算出SN
	if (SN_ENABLE >= 1) then
		for i = 1, ch_num, 1 do
			SN_DATA[i] = sn_new()	--根据上次SN生成新的SN
			FIX_TABLE[idx] = SN_ENABLE		--文件编号
			idx = idx + 1
			FIX_TABLE[idx] = i		--通道号1-4
			idx = idx + 1
			FIX_TABLE[idx] = SN_ADDR
			idx = idx + 1
			FIX_TABLE[idx] = SN_DATA[i]
			idx = idx + 1
		end
	end

--	CONST_CFG = {
--		1, 0x00000010, "12 34",	--使能位, 存储地址, 字符串数据
--		1, 0x00000020, "34 56",
--		1, 0x00000030, "56",
--		1, 0x00000040, "88"
--	}
	--常量
	for i = 1, 12, 3 do
		if (CONST_CFG[i] >= 1) then
			FIX_TABLE[idx] = CONST_CFG[i]		--文件编号
			idx = idx + 1		
			FIX_TABLE[idx] = 0	--通道号0
			idx = idx + 1
			FIX_TABLE[idx] = CONST_CFG[i+1]
			idx = idx + 1
			FIX_TABLE[idx] = hex_to_bin(CONST_CFG[i+2])
			idx = idx + 1
		end
	end

	--计算出生产日期
	if (DATE_ENABLE >= 1) then
		DATE_DATA = date_new()
		FIX_TABLE[idx] = DATE_ENABLE		--文件编号
		idx = idx + 1	
		FIX_TABLE[idx] = 0		--通道号0 表示所有通道一致
		idx = idx + 1
		FIX_TABLE[idx] = DATE_ADDR
		idx = idx + 1
		FIX_TABLE[idx] = DATE_DATA
		idx = idx + 1
	end

	--工厂代码
	if (TOOL_FACTORY_ENABLE >= 1) then
		local tid = pg_read_c_var("FactoryId")

		print("FactoryId = ", tid)
		for i = 1, ch_num, 1 do
			FIX_TABLE[idx] = TOOL_FACTORY_ENABLE		--文件编号
			idx = idx + 1			
			FIX_TABLE[idx] = 0
			idx = idx + 1
			FIX_TABLE[idx] = TOOL_FACTORY_ADDR
			idx = idx + 1
			FIX_TABLE[idx] = string.char(tid & 0xFF)
			idx = idx + 1
		end
	end

	--烧录器编号
	if (TOOL_SN_ENABLE >= 1) then
		local tid = pg_read_c_var("ToolSn")

		print("ToolSn = ", tid)
		for i = 1, ch_num, 1 do
			FIX_TABLE[idx] = TOOL_SN_ENABLE		--文件编号
			idx = idx + 1		
			FIX_TABLE[idx] = 0
			idx = idx + 1
			FIX_TABLE[idx] = TOOL_SN_ADDR
			idx = idx + 1
			FIX_TABLE[idx] = string.char(tid & 0xFF)
			idx = idx + 1
		end
	end

	--烧录器通道(1-4)
	if (TOOL_CHANNAL_ENABLE >= 1) then
		for i = 1, ch_num, 1 do
			FIX_TABLE[idx] = TOOL_CHANNAL_ENABLE		--文件编号
			idx = idx + 1		
			FIX_TABLE[idx] = i
			idx = idx + 1
			FIX_TABLE[idx] = TOOL_CHANNAL_ADDR
			idx = idx + 1
			FIX_TABLE[idx] = string.char(i)
			idx = idx + 1
		end
	end

	--	RNG_CONST_DATA = ""
	--	RNG_CONST_ADDR = 0x08000000
	if (RNG_CONST_DATA ~= "") then
		if (ENCRYPT_RND_IDX == 0) then
			for i = 1, ch_num, 1 do
				ENCRYPT_RND_DATA[i] = hex_to_bin(RNG_CONST_DATA)	--保存数据，用于后面加密
			end
		end
	end

	--	RNG_TAB = {
	--		0,0x08000000,4, --随机数#1
	--		0,0x08000000,4, --随机数#2
	--		0,0x08000000,4, --随机数#3
	--		0,0x08000000,4, --随机数#4
	--	}
	k = 1
	for j = 1,4,1 do
		if (RNG_TAB[k] >= 1) then
			for i = 1, ch_num, 1 do
				FIX_TABLE[idx] = RNG_TAB[k]		--文件编号
				idx = idx + 1
				FIX_TABLE[idx] = i		--通道号
				idx = idx + 1
				FIX_TABLE[idx] = RNG_TAB[k + 1]		--地址
				idx = idx + 1
				FIX_TABLE[idx] = get_rng(RNG_TAB[k + 2])	--数据

				if (ENCRYPT_RND_IDX == j) then
					for i = 1, ch_num, 1 do
						ENCRYPT_RND_DATA[i] = FIX_TABLE[idx]	--保存数据，用于后面加密
					end
				end

				idx = idx + 1
			end
		end
		k = k + 3
	end

	--读uid
	local uid
	if (MCU_ReadUID == nil) then
		UID = {pg_read_mem(UID_ADDR, UID_BYTES)}
	else
		UID = {MCU_ReadUID(UID_ADDR, UID_BYTES)}
	end

	if (UID[1] == 1) then
		local str
		for i = 1,ch_num,1 do
			str = string.format("uid%d = ", i)
			str = str..bin2hex(UID[i+1]) print(str)

			if (ENCRYPT_ENABLE >= 1) then
				FIX_TABLE[idx] = ENCRYPT_ENABLE		--文件编号
				idx = idx + 1			
				FIX_TABLE[idx] = i		--通道号
				idx = idx + 1
				FIX_TABLE[idx] = ENCRYPT_ADDR	--地址
				idx = idx + 1
				FIX_TABLE[idx] = string.sub(encrypt(UID[i + 1], ENCRYPT_RND_DATA[i]), 1,ENCRYPT_LEN)	--数据
				idx = idx + 1
			end
		end
	end
end

--打印修正结果
function PringFixData(void)
	print("FIX_TABLE count = ", #FIX_TABLE)

	local i
	local str
	for i = 1,#FIX_TABLE, 4 do
	   str = string.format("%d, %d, 0x%08X,", FIX_TABLE[i], FIX_TABLE[i + 1], FIX_TABLE[i+2])
	   str = str.." "..bin2hex(FIX_TABLE[i+3])
	   print(str)
	end
end

--产品序号SN生成函数 （last_sn是一个UINT32整数滚码）输出是二进制字符串
function sn_new(void)
	local bin = {}
	local out = {}
	local sn1
	local s
	local i

	if (SN_TYPE == 0) then	--普通滚码
		sn1 = pg_read_sn()	--读上次SN （必须是整数）
		str = string.format("Last SN. = %d", sn1) print(str)
		pg_write_sn(sn1 + 1)	--编程成功后才会保存本次SN
	else
		--1970年秒数
		sn1 = os.time()
	end

	if (SN_FORMAT == 0) then
		s = ""
		for i = 1,SN_LEN,1 do
			s = s..string.char((sn1 >> (8 * (i - 1))) & 0xFF)
		end
	else
		if (SN_FORMAT == 1) then
			s = ""
			for i = 1,SN_LEN,1 do
				s = s..string.char((sn1 >> (8 * (SN_LEN - i))) & 0xFF)
			end
		else
			local c
			s = ""
			for i = 1,SN_LEN,1 do
				c = math.floor(sn1 / (10 ^ (SN_LEN - i)))
				c = c % 10
				print(c)
				s = s..string.format("%d", c)
			end
		end
	end

	return s
end

--生产日期
function date_new(void)
	local s
	local tt

	tt = os.date("DateTime %Y-%m-%d %H:%M:%S")
	print(tt)

	if (DATE_FORMAT == 0) then
		tt = os.date("%Y%m%d%H%M%S")	--返回ASCII字符串 2020 01 21 23 25 01
		s = tt
	else if (DATE_FORMAT == 1) then	--1 : 1970基准秒数, 4字节,小端
			tt = os.time()
			s = string.char((tt >> 24) & 0xFF)..string.char((tt >> 16) & 0xFF)
				..string.char((tt >> 8) & 0xFF)..string.char((tt >> 0) & 0xFF)
	else if (DATE_FORMAT == 2) then	--2 : 1970基准秒数, 4字节,大端
			tt = os.time()
			s = string.char((tt >> 24) & 0xFF)..string.char((tt >> 16) & 0xFF)
				..string.char((tt >> 8) & 0xFF)..string.char((tt >> 0) & 0xFF)
	else if (DATE_FORMAT == 3) then	--3 : 1970基准秒数, 8字节,小端
			tt = os.time()
			s = string.char((tt >> 0) & 0xFF)..string.char((tt >> 8) & 0xFF)
				..string.char((tt >> 16) & 0xFF)..string.char((tt >> 24) & 0xFF)
				..string.char((tt >> 32) & 0xFF)..string.char((tt >> 40) & 0xFF)
				..string.char((tt >> 48) & 0xFF)..string.char((tt >> 56) & 0xFF)
	else if (DATE_FORMAT == 4) then	--4 : 1970基准秒数, 4字节,大端
			tt = os.time()
			s = string.char((tt >> 56) & 0xFF)..string.char((tt >> 48) & 0xFF)
				..string.char((tt >> 40) & 0xFF)..string.char((tt >> 32) & 0xFF)
				..string.char((tt >> 24) & 0xFF)..string.char((tt >> 16) & 0xFF)
				..string.char((tt >> 8) & 0xFF)..string.char((tt >> 0) & 0xFF)
		else
			s = ""
		end
		end
		end
		end
	end

	return s
end

---------------------------结束-----------------------------------
