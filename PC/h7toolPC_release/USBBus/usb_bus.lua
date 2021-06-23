beep()
print("Load usb_i2c_host.lua ok")

function bin2hex(bin)
	local s
	local i

	s = ""
	for i=1,#bin,1 do
		s = s..string.format("%02X ", string.byte(bin,i))
	end
	return s
end

----------I2C总线---------------

function I2C_ScanDevice(freq)
	local i
	local re
	local str
	
	beep()
	
	I2C_InitSlave(freq)
	
	print("扫描I2C总线设备...")
	
	for i = 0,255,2 do
		re = i2c_bus("check", i)
		if (re == 0) then
			str = string.format("0x%02X : ACK OK", i)			
			print(str)
		end
		delayms(5)
	end
	
	print("扫描结束")
end

--初始化I2C总线(从站)，频率
function I2C_InitSlave(freq)
	local str
	
	i2c_bus("init",freq)
	
	str = string.format("I2C总线频率已设置为 %dKHz", freq / 1000)
	print(str)
end

--写数据
function I2C_WriteData(addr, data)
	local str
	local ack
	local i
	local len
	local err
	
	err = string.format("I2C send 0x%02X, %s", addr, bin2hex(data))
	
	i2c_bus("start")	
	ack = i2c_bus("send", addr)
	if (ack ~= 0) then
		err = err.." error"
		goto quit
	end
	
	ack = i2c_bus("send", data)
	if (ack ~= 0) then
		err = err.." error"
		goto quit
	end	
	
	err = err.." ok"
::quit::
	i2c_bus("stop")
	print(err)
end

--读数据,芯片地址， 个数，显示宽度
function I2C_ReadData(addr, num, dispwidth)
	local str
	local ack
	local i
	local err
	local rd
	
	err = string.format("I2C read 0x%02X, %d", addr + 1, num)
	
	i2c_bus("start")	
	ack = i2c_bus("send", addr | 1)
	if (ack ~= 0) then
		err = err.." error"
		print(err)
		goto quit
	end

	rd = i2c_bus("recive", num)
	i2c_bus("stop")

	err = err.." ok"
	print(err)

	print_hex(rd, dispwidth, 0)
	
::quit::
	i2c_bus("stop")
end

----------SPI总线---------------
-- D5 : SPI_CLK
-- D2 : SPI_MOSI
-- D3 : SPI_MISO
-- D0 : CS0
-- D1 : CS1
--初始化总线(从站)
function SPI_Init(freqid, phase, polarity)
	local str
	local Baud = {"390.625K", "781.25K", "1.5625M", "3.125M", "6.25M", "12.5M", "25M", "50M"}

	gpio_cfg(0, 1)	--D0做输出CS0
	gpio_cfg(1, 1)	--D1做输出CS1
	
	if (freqid < 8) then
		spi_bus("init", freqid, phase, polarity)
		print("SPI总线频率已设置为 : "..Baud[freqid+1]) delayms(5)

		if (phase == 0) then
			if (polarity == 0) then
				print("时钟相位: 数据在前1个时钟沿采集(上升沿)")
			else
				print("时钟相位: 数据在前1个时钟沿采集(下升沿)")
			end
		else
			if (polarity == 0) then
				print("时钟相位: 数据在后1个时钟沿采集(下升沿)")
			else
				print("时钟相位: 数据在后1个时钟沿采集(上升沿)")
			end
		end
		 delayms(5)
		if (polarity == 0) then
			print("时钟极性: 空闲时为0")
		else
			print("时钟极性: 空闲时为1")
		end

	else
		print("SPI总线频率不支持")
	end	
end

--设置片选， ch: 通道, level:电平
function SPI_SetCS(ch, level)
	if (ch == 0) then
		gpio_write(0, level)
	else if (ch == 1) then
		gpio_write(1, level)
		else
		end
	end	
end

--写数据ch:通道(-1表示不操作), data:二进制数据
function SPI_WriteData(ch, data)
	local str
	local err
	
	err = string.format("SPI send %s", bin2hex(data))
	
	SPI_SetCS(ch, 0)
	spi_bus("send", data)     --发送二进制字符串
	SPI_SetCS(ch, 1)
	
	err = err.." ok"
	print(err)
end

--读数据, ch通道， 个数，显示宽度
function SPI_ReadData(ch, num, dispwidth)
	local str
	local err
	local rd
	
	err = string.format("SPI read  %d",  num)

	SPI_SetCS(ch, 0)
	rd = spi_bus("recive", num)
	SPI_SetCS(ch, 1)
	
	err = err.." ok"
	print(err)

	print_hex(rd, dispwidth, 0)
end


--写数据ch:通道(-1表示不操作), data:二进制数据
function SPI_WriteReadData(ch, data, num)
	local str
	local err
	local rd
	
	err = string.format("SPI send and recive %s, %d", bin2hex(data), num)
	
	SPI_SetCS(ch, 0)
	rd = spi_bus("sendrecive", data, num)
	SPI_SetCS(ch, 1)
	
	err = err.." ok"
	print(err)

	print_hex(rd, dispwidth, 0)
end


