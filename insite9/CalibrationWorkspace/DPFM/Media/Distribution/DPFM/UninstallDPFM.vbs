'********************************
'* CUMMINS, INC. 
'*
'* VBScript
'********************************
Option Explicit
Dim oShell,oFSO
Dim oWMIService, oProcess, colProcess
Dim strCommandline, strComputer, strProcessKill
Dim uninstall
strComputer = "."

'=====================================================================
'ENTER COMMANDLINE TO UNINSTALL APPLICATION AND PROCESS TO TERMINATE IN THIS SECTION

strCommandline = "msiexec.exe /x {79A7CE19-4B74-477A-8D39-432C95859614} /passive"
strProcessKill = "'dpfm_service_tool.exe'"
'"

'=====================================================================
  
set oShell = CreateObject("WScript.Shell")
Set oFSO = CreateObject("Scripting.FileSystemObject")

Set oWMIService = GetObject("winmgmts:" _
& "{impersonationLevel=impersonate}!\\" _ 
& strComputer & "\root\cimv2") 


Set colProcess = oWMIService.ExecQuery _
("Select * from Win32_Process Where Name = "& strProcessKill)
For Each oProcess in colProcess
oProcess.Terminate()
Next 

uninstall = oShell.run(strCommandline,0,True)
   
if uninstall <> 0 then
  WScript.quit -1
Else
  Wscript.quit 0
End if

set oShell= nothing
set oFSO = nothing
   