-------------------------------------------------------
-- 文件名 : encypt_001.lua
-- 说  明 : 加密公式001, 根据UID进行交换移位运算
-- 版  本 : V1.0  2020-09-06
-- Copyright (C), 2020-2030, 安富莱电子 www.armfly.com
-------------------------------------------------------

--UID加密函数，传入uid 和 rnd(随机数)
--uid和_rnd格式为二进制字符串
--	&	按位与
--	|	按位或
--	~	按位异或
--	>>	右移
--	<<	左移
--	~	按位非
--	%   取模
--	^   乘方
--	-   取负

--A1 - A16 参数由PC软件配置后，将覆盖如下的初值
A1 = 1
A2 = 2
A3 = 3
A4 = 3
A5 = 4
A6 = 5
A7 = 6
A8 = 8
A9 = 9
A10 = 10
A11 = 11
A12 = 12
A13 = 13
A14 = 14
A15 = 15
A16 = 16

--调试加密函数的方法:
--print_hex(encrypt("\x12\x34\x56\x78\x90\x12", "1234"))
--_rnd : 算法函数第2个形参随机数
function encrypt(_uid, _rnd)
	local uid = {}
	local rnd = {}
	local out = {}
	local s
	local i

	--将二进制的字符串转换为整数字节数组
	if (_uid == nil) then
		return
	end

	--#_uid表示字符串的长度。转换到整数数组存放
	for i = 1,#_uid,1 do
		uid[i] = tonumber(string.byte(_uid, i,i))
	end

	if (_rnd ~= nil) then
		for i = 1,#_rnd,1 do
			rnd[i] = tonumber(string.byte(_rnd, i,i))
		end
	end

	--进行逻辑运算 用户可自行修改为保密算法
	out[1] = uid[A0] ~ (uid[A1] >> 1) ~ (uid[A2]  >> 1)
	out[2] = uid[A3] ~ (uid[A4] >> 0) ~ (uid[A5] >> 1)
	out[3] = uid[A6] ~ (uid[A7] >> 1) ~ (uid[A8] >> 3)
	out[4] = uid[A9] ~ (uid[A10] >> 2) ~ (uid[A11] >> 0)

	out[5] = uid[A0] ~ (uid[A10] << 1) ~ (uid[A2]  >> 0)
	out[6] = uid[A3] ~ (uid[A7] << 1) ~ (uid[A5] << 2)
	out[7] = uid[A6] ~ (uid[A4] >> 0) ~ (uid[A8] << 0)
	out[8] = uid[A9] ~ (uid[A1] >> 2) ~ (uid[A11] << 1)

	out[9] = uid[A0] ~ (uid[A10] >> 1)
	out[10] = uid[A3] ~ (uid[A7] << 1)
	out[11] = uid[A6] ~ (uid[A4] << 1)
	out[12] = uid[A9] ~ (uid[A1] >> 2)

	out[13] = uid[A0] ~ (uid[A2]  >> 1)
	out[14] = uid[A3] ~ (uid[A5] >> 0)
	out[15] = uid[A6] ~ (uid[A8] << 2)
	out[16] = uid[A9] ~ (uid[A11] >> 0)

	for i = 1,#out,1 do
		out[i] = out[i] ~ rnd[((i - 1) % #rnd) + 1]
	end

	--拼接为二进制串返回（固定16字节，存储时可以只保存4,8字节
	s =    string.char(out[1] & 0xFF)
	s = s..string.char(out[2] & 0xFF)
	s = s..string.char(out[3] & 0xFF)
	s = s..string.char(out[4] & 0xFF)
	s = s..string.char(out[5] & 0xFF)
	s = s..string.char(out[6] & 0xFF)
	s = s..string.char(out[7] & 0xFF)
	s = s..string.char(out[8] & 0xFF)
	s = s..string.char(out[9] & 0xFF)
	s = s..string.char(out[10] & 0xFF)
	s = s..string.char(out[11] & 0xFF)
	s = s..string.char(out[12] & 0xFF)
	s = s..string.char(out[13] & 0xFF)
	s = s..string.char(out[14] & 0xFF)
	s = s..string.char(out[15] & 0xFF)
	s = s..string.char(out[16] & 0xFF)
	return s
end

---------------------------结束-----------------------------------
