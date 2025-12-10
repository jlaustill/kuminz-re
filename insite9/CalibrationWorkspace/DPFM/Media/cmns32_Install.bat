@echo off


xcopy C:\Software\CMNS32\Media C:\Windows\SysWOW64 /m /e /y


regsvr32.exe C:\Windows\syswow64\cmns32.ocx /s