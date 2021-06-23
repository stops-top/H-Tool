beep()
print("Load usb_i2c_host.lua ok")

function ScanDevice(void)
	local i
	local re
	local str
	
	i2c_bus("init")	
	
	beep()
	print("扫描I2C总线设备...")
	
	for i = 0,255,2 do
		re = i2c_bus("check", i)
		if (re == 0) then
			str = string.format("0x%02X : ACK OK", i)			
			print(str)
		end
		delayms(5)
	end
end