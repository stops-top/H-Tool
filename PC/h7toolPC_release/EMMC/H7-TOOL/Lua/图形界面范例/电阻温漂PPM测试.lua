--GUIMODE=1   --用于识别GUI程序还是print程序
------------------------------------------------
-- 电阻温飘系数测试程序(H7-TOOL)
-- 常温状态,长按S键开始，记录常温阻值
-- 升温后，短按S键，计算PPM
-- 电阻测量使用同惠TH2830电桥，RS232接口协议
------------------------------------------------

g_Temp1 = 0
g_Temp2 = 0

g_CalibT0 = 0
g_CalibT1 = 0

--GPIO口线定义
D_CH1 = 8 
D_CH2 = 6 
D_CH3 = 4 
D_CH4 = 2 
D_CH5 = 0 
D_CH6 = 9

--两个按键未用（使用TOOL上的按键）
D_S1 = 7
D_S2 = 5

--接2个DS18B20，1个测环境温度，一个测高温区问题
D_T1 = 1
D_T2 = 3

tok1 = 0
tok2 = 0

R0  = {0,0,0,0,0,0}	--常温阻值
R1  = {0,0,0,0,0,0}	--高温阻值
PPM  = {0,0,0,0,0,0}	--PPM
 
function main(void)

	beep()
	
	set_tvcc(5)  --TVCC设置输出5V
	
	CfgGpio()
	
	SetChan(0) --关闭全部继电器
	
	TH2830CfgRS232()
	
	lcd_clr(0xFFFF)
	
	DispTitle("电阻温漂系数PPM/℃")
	DispHead()
	lcd_refresh()
	while (get_key() > 0) do end
	ReadTH2830(1)
			
	while(1)
	do
	  tok1, g_Temp1 = read("DS18B20", D_T1)
		tok2, g_Temp2 = read("DS18B20", D_T2)

		DispDS18B20()
		
		lcd_refresh()
		
		key = get_key()
		if (key == 2) then		--短按S，实时采集一次
			g_CalibT1 = g_Temp2
			for i = 1,6,1 do
				SetChan(i) 	
			print("*****", i)		
				delayms(500)	
				ReadTH2830(i) 
				R1[i] = ReadTH2830(i)		
			end			
			SetChan(0)			
			DispResistor()
		elseif (key == 3) then	--长按S，实时采集一次，作为常温
			g_CalibT0 = g_Temp2
			g_CalibT1 = g_Temp2
			for i = 1,6,1 do
				SetChan(i) 			
				print("----", i)			
				delayms(500)
				ReadTH2830(i)				
				R0[i] = ReadTH2830(i)	
				R1[i] = R0[i]
			end
			SetChan(0)			
			DispResistor()	--显示6通道电阻值	
		elseif (key == 8) then
			beep()
		end
	end
end

--配置GPIO
function CfgGpio(void)
	gpio_cfg(D_CH1, 1)
	gpio_cfg(D_CH2, 1)
	gpio_cfg(D_CH3, 1)
	gpio_cfg(D_CH4, 1)
	gpio_cfg(D_CH5, 1)
	gpio_cfg(D_CH6, 1)
	gpio_cfg(D_S1, 0)
	gpio_cfg(D_S2, 0)
	gpio_cfg(D_T1, 0)
	gpio_cfg(D_T2, 0)		
end

--切换测量通道 1-6通道, 0是关闭
function SetChan(ch)
	gpio_write(D_CH1, 0)
	gpio_write(D_CH2, 0)
	gpio_write(D_CH3, 0)
	gpio_write(D_CH4, 0)
	gpio_write(D_CH5, 0)
	gpio_write(D_CH6, 0)
	
	if (ch == 1) then
		gpio_write(D_CH1, 1)
	elseif (ch == 2) then
		gpio_write(D_CH2, 1)
	elseif (ch == 3) then
		gpio_write(D_CH3, 1)
	elseif (ch == 4) then
		gpio_write(D_CH4, 1)
	elseif (ch == 5) then
		gpio_write(D_CH5, 1)
	elseif (ch == 6) then
		gpio_write(D_CH6, 1)		
	end
end

--显示标题
function DispTitle(str)	
	lcd_disp_str(0, 0, str, 24, 0xFFFF, 0x0014, 240, 1)	
end

function DispHead(void)		
	local x
	local y
	local bg
	
	bg = RGB565(150,150,150)
	y = 26 + 30
	x = 5
	lcd_disp_str(5, y,           "常温阻值Ω", 16, 0xFFFF, bg, 80, 1)
	lcd_disp_str(5 + 85, y,      "阻值差Ω",   16, 0xFFFF, bg, 80, 1)
	lcd_disp_str(5 + 85 + 85, y, "ppm/℃",    16, 0xFFFF, bg, 60, 1)
end

--显示温度值
function DispDS18B20()		
	  if (tok1 == 1) then
		  buf = string.format("%0.1f℃", g_Temp1)
		else
		  buf = "---"
	  end
		lcd_disp_str(5, 26, buf, 24, 0x0000, 0xC7F9, 110, 1)

	  if (tok2 == 1) then
		  buf = string.format("%0.1f℃", g_Temp2)
		else
			buf = "---"
	  end
		lcd_disp_str(125, 26, buf, 24, 0xFFF9, 0xF2A6, 110, 1)	
end

function DispResistor()	--显示6通道电阻值
	local i
	local buf
	local x
	local y
	local w
	local diff
	local ppm
	
	for i = 1,6,1 do
		if (R0[i] < 1000) then
			buf = string.format("%f", R0[i])
		elseif (R0[i] < 1000000) then
			buf = string.format("%fK", R0[i] / 1000)
		else
			buf = string.format("%fM", R0[i] / 1000000)			
		end
		x = 5
		y = 26 + 33 + 20 + (i - 1) * 24
		if (i >= 4) then	--分行
			y = y + 8
		end
		
		w = 80
		lcd_disp_str(x, y, buf, 16, 0x0000, 0xC7F9, w, 1)

		diff = R1[i] - R0[i]
		if (diff < 1000) then
			buf = string.format("%f", diff)
		elseif (diff < 1000000) then
			buf = string.format("%fK", diff / 1000)
		else
			buf = string.format("%fM", diff / 1000000)			
		end
		x = x + w + 5
		lcd_disp_str(x, y, buf, 16, 0x0000, 0xFFE0, w, 1)	
	
		if (g_CalibT0 == g_CalibT1) then
			PPM[i] = 0
		else
			PPM[i] = ((diff / R0[i]) / (g_CalibT1 - g_CalibT0)) * 1000000
		end
		
		ppm = PPM[i]
		buf = string.format("%0.2f", ppm)			
		x = x + w + 5
		lcd_disp_str(x, y, buf, 16, 0x0000, 0xE71F, 60, 1)	
	end
end

--读取TH2830电桥数据 
-- FETC?    已0X0A结束
-- -6.00728E-02,+1.79999E+05,+0
-- -3.85409E-01,+1.79998E+05,+0
-- +1.20388E-07,+5.69077E-02,+0
function TH2830CfgRS232(void)
	local COM = 1
	local Parity = 0
	local DataBits = 8
	local StopBits = 1

	uart_cfg(COM, 9600, Parity, DataBits, StopBits)
end

function ReadTH2830(idx)
	local COM = 1
	local rx_len
	local rx_str 
	local ff_str
	local ff

	rx_str = "+1.20388E-07,+0.00000E+00,+0\x0A"
	uart_send(COM, "FETC?\x0A")
	rx_len, rx_str = uart_recive(COM, 30,1000)
	print(rx_len, rx_str)
	--测试代码，模拟电桥应答数据(begiin)
	-- if (idx == 1) then
		-- rx_str = "+1.20388E-07,+5.69077E-04,+0\x0A"
	-- elseif (idx == 2) then
		-- rx_str = "+1.20388E-07,+5.69077E-02,+0\x0A"
	-- elseif (idx == 3) then
		-- rx_str = "+1.20388E-07,+5.69077E+01,+0\x0A"
	-- elseif (idx == 4) then
		-- rx_str = "+1.20388E-07,+5.69077E+02,+0\x0A"
	-- elseif (idx == 5) then
		-- rx_str = "+1.20388E-07,+5.69077E+03,+0\x0A"
	-- elseif (idx == 6) then
		-- rx_str = "+1.20388E-07,+5.69077E+04,+0\x0A"
	-- end
	--测试代码，模拟电桥应答数据(end)
	
	ff_str = string.sub(rx_str, 14, 14+11)
	ff = tonumber(ff_str)
	
	print(ff)
	return ff	
end

main()
