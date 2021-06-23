-------------------------------------------------------
-- 文件名 : cfg_m0.lua
-- 版  本 : V1.0  2020-07-18
-- 说  明 :
-------------------------------------------------------

--新唐寄存器定义

SYS_WRPROT = 0x50000100
SYSCLK_AHBCLK = 0x50000204
  AHBCLK_ISP_EN  = (1 << 2)
  AHBCLK_SRAM_EN = (1 << 4)
  AHBCLK_TICK_EN = (1 << 5)

FMC_ISPCON = 0x5000C000
  ISPCON_ISPEN   = (1 << 0)
  ISPCON_BS_AP   = (0 << 1)
  ISPCON_BS_LP   = (1 << 1)
  ISPCON_BS_MASK = (1 << 1)
  ISPCON_APUEN   = (1 << 3)
  ISPCON_CFGUEN  = (1 << 4)
  ISPCON_LDUEN   = (1 << 5)
  ISPCON_ISPFF   = (1 << 6)
FMC_ISPADR = 0x5000C004
FMC_ISPDAT = 0x5000C008
FMC_ISPCMD = 0x5000C00C
FMC_ISPTRG = 0x5000C010
--FMC_DFBADR = 0x5000C014
--FMC_FATCON = 0x5000C018
--FMC_ISPSTA = 0x5000C040
FMC_ISPCHEAT = 0x5000C01C

ISPCMD_READ        = 0x00
ISPCMD_PROGRAM     = 0x21
ISPCMD_PAGE_ERASE  = 0x22
ISPCMD_VECMAP      = 0x2e
ISPCMD_READ_UID    = 0x04
ISPCMD_READ_CID    = 0x0B
ISPCMD_READ_DID    = 0x0C

FMC_ISPCON_ISPFF_Msk = 0x40

function MCU_Init(void)
	--SYS_UnlockReg()
	local i
	for i = 1,100, 1 do
		if (pg_read32(SYS_WRPROT) == 1) then
			break
		end

		pg_write32(SYS_WRPROT, 0x59)
		pg_write32(SYS_WRPROT, 0x16)
		pg_write32(SYS_WRPROT, 0x88)
	end

	--Enable ISP/SRAM/TICK Clock
	pg_write32(SYSCLK_AHBCLK, pg_read32(FMC_ISPCON) | AHBCLK_ISP_EN | AHBCLK_SRAM_EN | AHBCLK_TICK_EN)

	--Enable ISP
	pg_write32(FMC_ISPCON, pg_read32(FMC_ISPCON) | ISPCON_ISPFF | ISPCON_LDUEN | ISPCON_APUEN | ISPCON_CFGUEN | ISPCON_ISPEN)

	--文档中没有的指令
	pg_write32(FMC_ISPCHEAT,0x01)
end

-- uid  = EF 00 30 00 83 80 3C FF 03 0A 00 00
function MCU_ReadUID(void)
	local id1,id2,id3,id4
	local i,j
	local uid1 = ""
	local uid2 = ""
	local uid3 = ""
	local uid4 = ""
	local re

	MCU_Init()

	for i = 1, 3, 1 do
		pg_write32(FMC_ISPCMD, ISPCMD_READ_UID)
	 	pg_write32(FMC_ISPADR, (i - 1) * 4)
	 	pg_write32(FMC_ISPTRG, 0x01)

	 	for j = 1, 1000, 1 do
	 		if ((pg_read32(FMC_ISPTRG) & 0x01) == 0) then
	 			break
	 		end
		end

		if (MULTI_MODE > 0) then
			re, id1,id2,id3,id4 = pg_read_mem(FMC_ISPDAT, 4)
			uid1 = uid1..id1
			uid2 = uid2..id2
			uid3 = uid3..id3
			uid4 = uid4..id4
		else
			re, id1 = pg_read_mem(FMC_ISPDAT, 4)
			uid1 = uid1..id1
		end
	end

	if (MULTI_MODE > 0) then
		return re, uid1,uid2,uid3,uid4
	else
		return re, uid1
	end
end

--根据单路或者多路模式，识别数据
function CheckFlagAuto(data, mask)
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

function FMC_Read_User(address)
	local reg

	pg_write32(FMC_ISPCMD, ISPCMD_READ)		--ISPCMD = ISP_Read
 	pg_write32(FMC_ISPADR, address)	--ISPADR = address
 	pg_write32(FMC_ISPDAT, 0) 		--ISPDAT = 0

 	pg_write32(FMC_ISPTRG, 0x01)	--ISPTRG = ISPGO

	reg = {pg_read32(FMC_ISPCON)}		--read FISPCON
	if (CheckFlagAuto(reg, 0x40) > 0) then
		pg_write32(FMC_ISPCON, reg)
		return -1
	end

	return pg_read32(FMC_ISPDAT)	--read ISPDAT
end

function FMC_Write_User(u32Addr, u32Data)
    local Reg;

    pg_write32(FMC_ISPCMD, ISPCMD_PROGRAM)	--ISPCMD = FMC_ISPCMD_PROGRAM
	pg_write32(FMC_ISPADR, u32Addr)	--ISPADR = u32Addr
	pg_write32(FMC_ISPDAT, u32Data)	--ISPDAT = u32Data

	pg_write32(FMC_ISPTRG, 0x01)	--ISPTRG = ISPGO

	--Check ISPFF flag to know whether erase OK or fail
	reg = pg_read32(FMC_ISPCON)		--read FISPCON
	if ((reg & 0x40) > 0) then
		pg_write32(FMC_ISPCON, reg)
		return -1
	else
		return 0
	end
end

--读选项字1个字节
function MCU_ReadOptionByte(addr)
	local cfg1, cfg2
	local re
	local data = {0,0,0,0}
	local idx
	local ch_num
	local j

	if (MULTI_MODE > 0) then
		ch_num = MULTI_MODE
	else
		ch_num = 1
	end

	MCU_Init()
	
	cfg1 = {FMC_Read_User(0x00300000)}
	cfg2 = {FMC_Read_User(0x00300004)}

	if (cfg1[1] == -1 or cfg2[1] == -1) then
		re = 0
		goto quit_err
	end

	if (addr >= 0x00300000 and addr <= 0x00300003) then
		idx = addr - 0x00300000
		
		for j = 1,ch_num,1 do
			data[j] = (cfg1[j] >> (idx * 8)) & 0xFF
		end
	else
		if (addr >= 0x00300004 and addr <= 0x00300007) then
			idx = addr - 0x00300004

			for j = 1,ch_num,1 do
				data[j] = (cfg2[j] >> (idx * 8)) & 0xFF
			end				
		else
			re = 0
			goto quit_err
		end
	end

	re = 1
	
::quit_err::
	return re, data[1], data[2], data[3], data[4]
end

function u32tobin(u32)
	return string.char(u32 & 0xff)..string.char((u32 >> 8) & 0xff)..string.char((u32 >> 16) & 0xff)..string.char((u32 >> 24) & 0xff)
end
	
--读取OB全部字节 re,bin1,bin2,bin3,bin4. 用于打印
function MCU_ReadOB(void)
	local cfg1, cfg2
	local re
	local ch_num
	local j
	local ob = {"","","",""}

	if (MULTI_MODE > 0) then
		ch_num = MULTI_MODE
	else
		ch_num = 1
	end
	
	--Enter ISP
	MCU_Init()

	cfg1 = {FMC_Read_User(0x00300000)}
	cfg2 = {FMC_Read_User(0x00300004)}

	if (cfg1[1] == -1 or cfg2[1] == -1) then
		re = 0
		return 0
	end

	for j = 1,ch_num,1 do
		ob[j] = u32tobin(cfg1[j])..u32tobin(cfg2[j])
	end	

	return 1, ob[1], ob[2], ob[3], ob[4]
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

	--Enter ISP
	MCU_Init()
	
	if (MULTI_MODE > 0) then
		ch_num = MULTI_MODE
	else
		ch_num = 1
	end
		
	ob_8 = hex_to_bin(ob)	--hex字符串转为二进制数组
	
	for i = 0, 1, 1 do 
		cfg_wr[i+1] = string.byte(ob_8, 4 * i + 1) + (string.byte(ob_8, 4 * i + 2) << 8) + 
			(string.byte(ob_8, 4 * i + 3) << 16) + (string.byte(ob_8, 4 * i + 4) << 24)
		--print_hex(cfg_wr[i+1])
		if (FMC_Write_User(0x00300000 + i * 4, cfg_wr[i + 1]) ~= 0) then
			goto quit_err
		end
	end
	
	--校验
	print("---Verify OB---")	

	for i = 0, 1, 1 do
		ob_read = {FMC_Read_User(0x00300000 + 4 * i)}		
		for j = 1,ch_num,1 do
			if (cfg_wr[i + 1] ~= ob_read[j]) then
				err = "error"
			end
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
	local i

	--Enter ISP
	MCU_Init()

	--Erase Chip
	pg_write32(FMC_ISPCMD, 0x26)
 	pg_write32(FMC_ISPADR, 0)
	pg_write32(FMC_ISPDAT, 0)
 	pg_write32(FMC_ISPTRG, 0x01)

 	for i = 1, 1000, 1 do
 		if ((pg_read32(FMC_ISPTRG) & 0x01) == 0) then
 			break
 		end
 		delayms(1)
	end

	--Erase SPROM
	pg_write32(FMC_ISPCMD, 0x22)
 	pg_write32(FMC_ISPADR, 0x00200000)
	pg_write32(FMC_ISPDAT, 0x55AA03)
 	pg_write32(FMC_ISPTRG, 0x01)

 	for i = 1, 500, 1 do
 		if ((pg_read32(FMC_ISPTRG) & 0x01) == 0) then
 			break
 		end
 		delayms(1)
	end
	
	delayms(200) --必须延迟一段时间才能结束
end

--芯片专有的整片擦除
function MCU_EraseMass(void)
	MCU_RemoveProtect()
	return "OK"
end

--【F1】复位期间执行的函数. 目的:debug期间冻结看门狗时钟,低功耗模式启动HCLK和FCLK
function InitUnderReset(void)
	local str = "error"

	print("InitUnderReset()")

	-- if (pg_write32(0xE0042004, 0x00000307) == 0) then
	-- goto quit_err
	-- end

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
	
	g_DevID = {pg_read32(0x50000000)} --全局变量g_DevID[]

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

