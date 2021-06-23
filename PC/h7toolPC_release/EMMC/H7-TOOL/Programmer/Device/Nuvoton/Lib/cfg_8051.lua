-------------------------------------------------------
-- 文件名 : cfg_8051.lua
-- 版  本 : V1.0  2020-07-18
-- 说  明 :
-------------------------------------------------------

--新唐寄存器定义

function MCU_Init(void)

end

--re, uid1,uid2,uid3,uid4
function MCU_ReadUID(void)
	--re, uid1,uid2,uid3,uid4
	return pg_n76e_iap("read_uid");
end

--读选项字1个字节, 地址 0-7
--return re, data[1], data[2], data[3], data[4]
function MCU_ReadOptionByte(addr)
	return pg_n76e_iap("read_cfg_byte", addr);
end

function u32tobin(u32)
	return string.char(u32 & 0xff)..string.char((u32 >> 8) & 0xff)..string.char((u32 >> 16) & 0xff)..string.char((u32 >> 24) & 0xff)
end
	
--读取OB全部字节 re,bin1,bin2,bin3,bin4. 用于打印
function MCU_ReadOB(void)
	local re,bin1,bin2,bin3,bin4
	
	pg_n76e_iap("enter_iap");
	re,bin1,bin2,bin3,bin4 = pg_n76e_iap("read_cfg_all");
	pg_n76e_iap("exit_iap");
	return re,bin1,bin2,bin3,bin4
end

--没有FLM的MCU，用脚本实现编程OB。 返回 "OK" or "error"
function MCU_ProgOptionBytes(ob)
	local i
	local j
	local ob_8
	local cfg_wr = {}
	local ob_read = {}
	local err = "OK"
	local ch_num

	if (MULTI_MODE > 0) then
		ch_num = MULTI_MODE
	else
		ch_num = 1
	end	

	--pg_n76e_iap("enter_iap");
	
	pg_n76e_iap("write_cfg", ob);
	
	ob_read = {pg_n76e_iap("read_cfg_all")}

	--pg_n76e_iap("exit_iap");
	
	--校验
	print("---Verify OB---")	

	ob_8 = hex_to_bin(ob)	--hex字符串转为二进制数组
	for j = 1,ch_num,1 do
		if (ob_8 ~= ob_read[j + 1]) then
			err = "error"
		end
	end
	
	if (err ~= "OK") then
		print("   Verify OB Error")	
	end

::quit_err::
	return err
end

--芯片专有的解除保护函数
function MCU_RemoveProtect(void)
	--pg_n76e_iap("enter_iap");
	pg_n76e_iap("erase_chip");
	--pg_n76e_iap("exit_iap");
end

--芯片专有的整片擦除
function MCU_EraseMass(void)
	MCU_RemoveProtect()
	return "OK"
end

---------------------------结束-----------------------------------

