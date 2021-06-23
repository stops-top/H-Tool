--版本 V1.1  2020-06-28
--F01=单次测试,TestOnce()
--F02=自动测试,AutoTest()

COM_485 = 1
RS485_ADDR = 1
RS485_TimeOut = 300
MODEL = ""
SOFT_VER = ""
g_PassedCount = 0

beep()

function TestErr(void)
	print("测试失败")
	beep()
	delayms(100)
	beep()
	delayms(100)
	beep()
end

function TestOk(void)
	g_PassedCount = g_PassedCount + 1
	print("测试通过  ", g_PassedCount)
	beep()
end

function InitRS485(void)
	local Parity = 0
	local DataBits = 8
	local StopBits = 1

	uart_cfg(COM_485, 9600, Parity, DataBits, StopBits)
end

--检查型号
function CheckModel(void)
	local err = 0
	local rx_len
	local modle = ""

	uart_send(COM_485, "$001,02&")
	rx_len, modle = uart_recive(COM_485, 20, 100)

	if (modle == "LED-485-034" or modle == "LED-485-043" or modle == "LED-485-054" or modle == "LED-485-083"
		 or modle == "LED-485-184"  or modle == "LED-485-504" or modle == "LED-485-2342" or modle == "LED-485-1842") then
		return modle
	else
		return ""
	end
end

--检查软件版本
function CheckSoftVer(void)
	local err = 0
	local rx_len
	local version = ""

	uart_send(COM_485, "$001,03&")
	rx_len, version = uart_recive(COM_485, 20, 50)

	return version
end

--自动测试
function AutoTest(void)

	local inserted = 0
	local key
	local err
	local flag = 0

	print("进入自动测试模式")

	InitRS485()

	while(1)
	do
		if (inserted == 0) then
			MODEL = CheckModel()
			if (MODEL ~= "") then
				inserted = 1
				TestOnce()

				flag = 0
			end
		else
			if (flag < 10) then
				err = modbus_write_u16(COM_485, RS485_TimeOut, RS485_ADDR, 0x0070, 0x382E, 0x382E,0x382E, 0x382E, 0, 0)
			else
				if (flag < 20) then
					CheckSoftVer()
				else
					flag = 0
				end
			end

			flag = flag + 1
			if (err > 0) then
				inserted = 0
			end
		end

		delayms(50)

	    --按任意键退出循环
	    key = get_key()
	    if (key > 0) then
	    	print("用户结束lua程序")
	    	return
	    end
	end
end

function TestOnce(void)
	InitRS485()
	MODEL = CheckModel()

	delayms(250)
	if (MODEL == "") then
		print("RS485通信错误")
		TestErr()
	end

	if (MODEL == "LED-485-184" or MODEL == "LED-485-504") then
		TestLED184()
	end

	if (MODEL == "LED-485-034" or MODEL == "LED-485-054") then
		TestLED034()
	end

	if (MODEL == "LED-485-043" or MODEL == "LED-485-083") then
		TestLED083()
	end
end

--测试LED-485-034  LED-485-054
function TestLED034(void)
	local err = 0
	local str
	local ret = "OK"
	local i
	local value
	local count

	SOFT_VER = CheckSoftVer()

	print("开始测试")
	print(MODEL, SOFT_VER)

	delayms(300)

	--通过RS485检查结果
	err = modbus_write_u16(COM_485, RS485_TimeOut, RS485_ADDR, 0x0088, 1234)
	if (err > 0) then
		print("RS485通信错误")
		goto quit_err
	end

	--点亮全部LED
	uart_send(COM_485, "$001,8.8.8.8.#")

::quit_err::
	if (err == 0) then
		TestOk()
	else
		TestErr()
	end

	return ret
end

--测试LED-485-034  LED-485-054
function TestLED083(void)
	local err = 0
	local str
	local ret = "OK"
	local i
	local value
	local count

	SOFT_VER = CheckSoftVer()

	print("开始测试")
	print(MODEL, SOFT_VER)

	delayms(300)

	--通过RS485检查结果
	err = modbus_write_u16(COM_485, RS485_TimeOut, RS485_ADDR, 0x0088, 123)
	if (err > 0) then
		print("RS485通信错误")
		goto quit_err
	end

	--点亮全部LED
	uart_send(COM_485, "$001,8.8.8.#")

::quit_err::
	if (err == 0) then
		TestOk()
	else
		TestErr()
	end

	return ret
end

--测试LED-485-034  LED-485-054
function TestLED043(void)
	local err = 0
	local str
	local ret = "OK"
	local i
	local value
	local count

	SOFT_VER = CheckSoftVer()

	print("开始测试")
	print(MODEL, SOFT_VER)

	--通过RS485检查结果
	err = modbus_write_u16(COM_485, RS485_TimeOut, RS485_ADDR, 0x0088, 123)
	if (err > 0) then
		print("RS485通信错误")
		goto quit_err
	end

	--点亮全部LED
	uart_send(COM_485, "$001,8.8.8.#")

::quit_err::
	if (err == 0) then
		TestOk()
	else
		TestErr()
	end

	return ret
end

--测试LED-485-184
function TestLED184(void)
	local err = 0
	local str
	local ret = "OK"
	local i
	local value
	local count

	SOFT_VER = CheckSoftVer()

	print("开始测试")
	print(MODEL, SOFT_VER)

	set_tvcc(5)
	gpio_cfg(2, 1)
	gpio_cfg(3, 1)
	gpio_cfg(4, 1)

	--CLR键
	gpio_write(4, 1)
	delayms(100)
	gpio_write(4, 0)

	--INC键执行3次
	for i = 1, 3, 1 do
		gpio_write(2, 1)
		delayms(70)
		gpio_write(2, 0)
		delayms(70)
	end

	--通过RS485检查结果
	err, count = modbus_read_u16(COM_485, RS485_TimeOut, RS485_ADDR, 0x001D, 1)
	if (err > 0) then
		print("RS485通信错误1")
		goto quit_err
	else
		if (count ~= 3) then
			print("INC键错误")
			goto quit_err
		end
	end

	--DEC键执行2次
	for i = 1, 2, 1 do
		gpio_write(3, 1)
		delayms(70)
		gpio_write(3, 0)
		delayms(70)
	end

	--通过RS485检查结果
	err, count = modbus_read_u16(COM_485, RS485_TimeOut, RS485_ADDR, 0x001D, 1)
	if (err > 0) then
		print("RS485通信错误")
		goto quit_err
	else
		if (count ~= 1) then
			print("DEC键错误2")
			goto quit_err
		end
	end

	--CLR键
	gpio_write(4, 1)
	delayms(100)
	gpio_write(4, 0)

	--通过RS485检查结果
	err, count = modbus_read_u16(COM_485, RS485_TimeOut, RS485_ADDR, 0x001D, 1)
	if (err > 0) then
		print("RS485通信错误3")
		goto quit_err
	else
		if (count ~= 0) then
			print("CLR键错误")
			goto quit_err
		end
	end

	--点亮全部LED
	uart_send(COM_485, "$001,8.8.8.8.#")

::quit_err::
	if (err == 0) then
		TestOk()
	else
		TestErr()
	end

	set_tvcc(3.3)

	return ret
end

