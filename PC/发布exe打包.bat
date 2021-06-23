
del h7toolPC_release\EMMC /Q /S /F
del h7toolPC_release\USBBus /Q /S /F
del h7toolPC_release\h7toolPC.exe /Q /S /F

del Win32\Debug\EMMC\H7-TOOL\Programmer\User\Demo\*.* /Q /S /F
del Win32\Debug\Backup\*.* /Q /S /F
del Win32\Debug\Readback\*.* /Q /S /F

xcopy Win32\Debug\EMMC h7toolPC_release\EMMC /E /R /K /Y /I
xcopy Win32\Debug\USBBus h7toolPC_release\USBBus /E /R /K /Y /I

copy Win32\Release\Project1.exe h7toolPC_release\h7toolPC.exe
copy Win32\Debug\ChangeLog.txt h7toolPC_release\ChangeLog.txt

pause