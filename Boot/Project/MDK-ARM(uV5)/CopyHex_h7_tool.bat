copy Objects\output.hex ..\boot.hex

hex2bin ..\boot.hex

REM LinkBin ..\h7_tool_boot.bin =VAR @0x0 ..\app0.bin @0xE0000 ..\dap.bin

del ..\boot.hex




