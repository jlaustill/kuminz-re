'********************************
'* CUMMINS, INC. 
'*
'* VBScript
'********************************
Option Explicit
Dim oShell,oFSO
Dim strCommandline
Dim Install
'=====================================================================
'ENTER COMMANDLINE TO INSTALL PREREQS IN THIS SECTION

'=====================================================================
'=====================================================================
'ENTER COMMANDLINE TO INSTALL APPLICATION IN THIS SECTION

strCommandline = "DPFM.msi /qb! /norestart"
'=====================================================================

  
set oShell = CreateObject("WScript.Shell")
Set oFSO = CreateObject("Scripting.FileSystemObject")

Install = oShell.run(strCommandline,0,True)

if Install <> 0 then
  WScript.quit -1
Else
  Wscript.quit 0
End if

set oShell= nothing
set oFSO = nothing
   
