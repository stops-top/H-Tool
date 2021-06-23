-------------------------------------------------------
-- 文件名 : machine_if.lua
-- 说  明 : 烧录机台接口信号定义
-- Copyright (C), 2020-2030, 安富莱电子 www.armfly.com
-------------------------------------------------------
MACHINE_FILE_VER = 1.2  --文件版本

print("load \"machine_if.lua\" ok. version = ",MACHINE_FILE_VER)

MACHINE_INTERFACE = 1	--烧录机台接口类型

ABORT_ON_ERROR = 1	--1表示出错时全部通道都终止

MI_STD_OK_NG_DELAY = 200	--标准信号，OK NG信号持续时间，ms，0表示一直持续
MI_EOT_TIME1 = 50	--EOT信号时序，延迟1
MI_EOT_TIME2 = 90	--EOT信号时序，延迟2
MI_EOT_TIME3 = 50	--EOT信号时序，延迟3

SWD_BOARD = 0	--多路模式转接板类型 0是简版，1是扩展了IO的SWD转接板
function AutoDetecSwdBorad(void)
	local re = 0
	local i

	uart_cfg(1, 115200, 0, 8, 1)	--配置RS232/RS485串口参数
	--delayms(20)
	
	for i = 1,1,1 do
		re = re + modbus_write_u16(1, 50, 253, 0x1000 + 3 * (i - 1), 1, 1, 1)
	end
	
	if (re == 0) then	--通信无问题
		SWD_BOARD = 1  --机台专用版 1拖4转接板
	else
		SWD_BOARD = 0;
	end

	MULTI_MODE = pg_read_c_var("MultiProgMode")

	mi_CfgGpio()	
end

--读START引脚电平
function ReadStartLevel(void)
	local x
	
	if MACHINE_INTERFACE > 0 then	
		if (SWD_BOARD == 0) then		
			if (read_analog(4) < TVCC_VOLT * 0.6) then
				x = 1
			else		
				if (MULTI_MODE == 0) then
					x = gpio_read(7)	--D7 = START信号(内带上拉)
				else
					x = gpio_read(1)	--D1 = START信号
				end
			end
		else
			local re
			
			--发串口指令读
			--modbus_read_di(port, timeout, addr485, regaddr, regnum)\r\n--parameter erro
			re,x = modbus_read_di(1, 20, 253, 0x1000, 1)	--读0x1000寄存器 START
			if (re == 0) then
				if (x == 0) then
					x = 1
				else
					x = 0
				end
			else
				x = 1
			end
		end
	else
		x = 1
	end
	return x
end
	
--烧录空闲时执行(c程序中调用), 20ms被执行一次
g_last_x = -1
function mi_idle(void)
	local x

	x = ReadStartLevel()	
	if (g_last_x == 1) then
		if (x == 0) then
			put_msg(0x00001001, 0)
		end
	end
	g_last_x = x
end

--开始编程 (被lua程序 start_prog()调用)
function mi_begin(void)
	-- BUSY = 0, OK = 1, NG = 1
	local ch_num
	
	if (MULTI_MODE > 0) then
		ch_num = MULTI_MODE
	else
		ch_num = 1
	end
	
	if (MACHINE_INTERFACE == 1) then
		--BUSY(EOT) = 0  OK = 1  NG = 1
		for i = 1,ch_num,1 do
			mi_SetOutpin(i, 0, 1, 1)
		end
	end
	
	if (MACHINE_INTERFACE == 2) then	--EOT类型
		--BUSY(EOT) = 1  OK = 1  NG = 1
		for i = 1,ch_num,1 do
			mi_SetOutpin(i, 1, 1, 1)
		end	
	end
end

--编程结束终止 (被lua程序 start_prog()调用)
--只有出错的通道设置NG有效
function mi_abort(err_flag)
	local ch_num
		
	if (MULTI_MODE > 0) then
		ch_num = MULTI_MODE
	else
		ch_num = 1
	end

	if (MACHINE_INTERFACE == 1) then	--标准信号 BUSY OK NG
		for i = 1,ch_num,1 do
			if (err_flag[i] == 1) then	--失败
				mi_SetOutpin(i, 1, 1, 0) --BUSY(EOT) = 1  OK = 1  NG = 0
			end
			
			if (err_flag[i] == 0) then	--成功
				mi_SetOutpin(i, 1, 0, 1) --BUSY(EOT) = 1  OK = 0  NG = 1
			end

			if (err_flag[i] == 2) then  --检测到IC，但是未开始烧录
				mi_SetOutpin(i, 1, 1, 1) --BUSY(EOT) = 1  OK = 1  NG = 1
			end			
		end
		
		if (MI_STD_OK_NG_DELAY > 0) then
			delayms(MI_STD_OK_NG_DELAY)	--延迟200ms	
			for i = 1,ch_num,1 do
				mi_SetOutpin(i, 1, 1, 1) --BUSY(EOT) = 1  OK = 1  NG = 1
			end	
		end
	end

	if (MACHINE_INTERFACE == 2) then	--EOT类型  EOT OK NG (执行时间140ms)		
		for i = 1,ch_num,1 do
			if (err_flag[i] == 0) then
				mi_SetOutpin(i, 1, 0, 1) --BUSY(EOT) = 1  OK = 0  NG = 1
			end
			
			if (err_flag[i] == 1) then
				mi_SetOutpin(i, 1, 1, 0) --BUSY(EOT) = 1  OK = 1  NG = 0
			end
		end	
		delayms(MI_EOT_TIME1)	--延迟50ms
		for i = 1,ch_num,1 do
			if (err_flag[i] == 0) then
				mi_SetOutpin(i, 0, 0, 1) --BUSY(EOT) = 0  OK = 0  NG = 1
			end
			
			if (err_flag[i] == 1) then
				mi_SetOutpin(i, 0, 1, 0) --BUSY(EOT) = 0  OK = 1  NG = 0
			end
			
			if (err_flag[i] == 2) then	--检测到IC，但是未开始烧录
				mi_SetOutpin(i, 0, 1, 1) --BUSY(EOT) = 0  OK = 1  NG = 1
			end			
		end		
		delayms(MI_EOT_TIME2)	--延迟90ms
		for i = 1,ch_num,1 do
			if (err_flag[i] == 0) then
				mi_SetOutpin(i, 1, 0, 1) --BUSY(EOT) = 1  OK = 0  NG = 1
			end
			
			if (err_flag[i] == 1) then
				mi_SetOutpin(i, 1, 1, 0) --BUSY(EOT) = 1  OK = 1  NG = 0
			end

			if (err_flag[i] == 2) then	--检测到IC，但是未开始烧录
				mi_SetOutpin(i, 1, 1, 1) --BUSY(EOT) = 1  OK = 1  NG = 1
			end				
		end	
		delayms(MI_EOT_TIME3)	--延迟50ms
		for i = 1,ch_num,1 do
			mi_SetOutpin(i, 1, 1, 1) --BUSY(EOT) = 1  OK = 1  NG = 1
		end	
	end		
end

--配置GPIO
function mi_CfgGpio(void)
	if (MACHINE_INTERFACE > 0) then
		if (MULTI_MODE == 0) then	--单路模式
			--D7 = START   D1 = BUSY   D2 = OK  D3 = NG
			gpio_cfg(7,0)
			gpio_cfg(1,1)
			gpio_cfg(2,1)
			gpio_cfg(3,1)
		else	--多路模式
			if (SWD_BOARD == 0) then	--简版1拖4 SWD转接板(仅支持1-2路机台信号)
				if (MULTI_MODE <= 2) then
					--1路和2路模式支持机台信号
					--D1 = START共用  
					--D4 = SWDIO_3	 用作 OK1
					--D6 = SWCLK_3	 用作 NG1
					--D3 = SWDIO_4	 用作 OK2			
					--D2 = SWCLK_4	 用作 NG2
					--TTLTX = BUSY/EOT(共用)
					gpio_cfg(1,0)
					gpio_cfg(4,1)
					gpio_cfg(6,1)
					gpio_cfg(3,1)
					gpio_cfg(2,1)		
					gpio_cfg(10,1)	--D10 TTLTX 用作普通GPIO				
				else	
					--3路和4路模式不支持机台信号
				end
			end

			if (SWD_BOARD == 1) then	--机台专用 1拖4 SWD转接板 (通过串口控制)
				local re
				local i
				
				--100ms超时，485地址253, 写0x1000寄存器，连续3个, 重试3次
				for i = 1,3,1 do
					re = modbus_write_u16(1, 50, 253, 0x1000 + 3 * (ch - 1), busy, ok, ng)
					if (re == 0) then	--成功
						break
					end
				end
				if (re ~= 0) then	--转接板故障
					pg_print_text("SWD转接板通信故障")
				end
			end		
		end	
	end
end

--设置输出状态，ch : 1-4 表示通道
function mi_SetOutpin(ch, busy, ok, ng)
	local str
	
	str = string.format("--CH%d: BUSY/EOT=%d OK=%d NG=%d",  ch, busy, ok, ng)
	print(str)
	if (MULTI_MODE == 0) then	--单路模式
		--D0 = START   D1 = BUSY   D2 = OK  D3 = NG
		gpio_write(1, busy)
		gpio_write(2, ok)
		gpio_write(3, ng)	
	else	--多路模式
		if (SWD_BOARD == 0) then	--简版1拖4 SWD转接板(仅支持1-2路机台信号)
			if (MULTI_MODE <= 2) then
				--
				--D1 = START共用  
				--D4 = SWDIO_3	 用作 OK1
				--D6 = SWCLK_3	 用作 NG1
				--D3 = SWDIO_4	 用作 OK2			
				--D2 = SWCLK_4	 用作 NG2
				--D10 = BUSY 共用BUSY
				if (ch == 1) then
					gpio_write(10, busy)				
					gpio_write(4, ok)
					gpio_write(6, ng)				
				end
				
				if (ch == 2) then
					gpio_write(3, ok)
					gpio_write(2, ng)					
				end				
			else	
				--3路和4路模式不支持机台信号
			end
		end

		if (SWD_BOARD == 1) then	--机台专用 1拖4 SWD转接板 (通过串口控制)
			local re
			local i
			
			--100ms超时，485地址253, 写0x1000寄存器，连续3个, 重试3次
			for i = 1,3,1 do
				re = modbus_write_u16(1, 50, 253, 0x1000 + 3 * (ch - 1), busy, ok, ng)
				if (re == 0) then	--成功
					break
				end
			end
			if (re ~= 0) then	--转接板故障
				pg_print_text("SWD转接板通信故障")
			end
		end		
	end	
end

AutoDetecSwdBorad()	--检测转接板类型, 选择lua文件时执行一次即可

---------------------------结束-----------------------------------
