!***********************************************************
! InstallShield Repackager Script
!This script file contains information necessary for
!converting repackaged traditional setups into Windows
!Installer (MSI) packages. Open this file with the Import
!Repackaged Setup wizard in InstallShield Author to perform
!conversion to an InstallShield Author project (.ism). You 
!can then build the .ism into an MSI. 
!***********************************************************
! 
! Script Version
ScriptVersion('5.00')
! 
! 
! Operating System
OSInfo('Windows 7','6.1.7600 ','1033','1033','x86')
! 
! 
! Path to Original Setup
OrigSetup('')
! 
! External: WindowsVolume - current value C:\
! External: LocalAppDataFolder - current value C:\Users\adminacct\AppData\Local
! External: WindowsFolder - current value C:\Windows
! External: ProgramFilesFolder - current value C:\Program Files
! External: SystemFolder - current value C:\Windows\system32
!
!Variables
Set('_PC_TOOL','D:\MEDIA\PC_TOOL')
!
!Files
InstallFileList('%ProgramFilesFolder%\DPFM Service Tool')
 C:\PACKAGES\PROGRAMFILESFOLDER\DPFM Service Tool\dpfm.cfg|32|466||1033|dpfm.cfg
 C:\PACKAGES\PROGRAMFILESFOLDER\DPFM Service Tool\DPFM_Help.chm|32|249664||1033|DPFM_H~1.CHM
 C:\PACKAGES\PROGRAMFILESFOLDER\DPFM Service Tool\DPFM_Service_Tool.exe|32|537600|6.1.0.8|1033|DPFM_S~1.EXE
 C:\PACKAGES\PROGRAMFILESFOLDER\DPFM Service Tool\ST5UNST.LOG|32|3927||1033|ST5UNST.LOG
EndProc/U
InstallFileList('%LocalAppDataFolder%\Microsoft\Windows\WER\ReportQueue\NonCritical_SETUP.EXE_1766fc443f5ffd417c271722866bc9a5dbe03c72_cab_0af9d02e')
 C:\PACKAGES\LOCALAPPDATAFOLDER\Microsoft\Windows\WER\ReportQueue\NonCritical_SETUP.EXE_1766fc443f5ffd417c271722866bc9a5dbe03c72_cab_0af9d02e\appcompat.txt|10240|1830||1033|APPCOM~1.TXT
 C:\PACKAGES\LOCALAPPDATAFOLDER\Microsoft\Windows\WER\ReportQueue\NonCritical_SETUP.EXE_1766fc443f5ffd417c271722866bc9a5dbe03c72_cab_0af9d02e\Report.wer|10272|2524||1033|Report.wer
 C:\PACKAGES\LOCALAPPDATAFOLDER\Microsoft\Windows\WER\ReportQueue\NonCritical_SETUP.EXE_1766fc443f5ffd417c271722866bc9a5dbe03c72_cab_0af9d02e\TabD010.tmp|10240|40||1033|TabD010.tmp
EndProc/U
InstallFileList('%WindowsFolder%')
 C:\PACKAGES\WINDOWSFOLDER\Repack_adminacct.LOG|32|46487||1033|REPACK~1.LOG
 C:\PACKAGES\WINDOWSFOLDER\ST5UNST.EXE|32|0||1033|ST5UNST.EXE
EndProc/U
InstallFileList('%WindowsFolder%\ServiceProfiles\NetworkService\AppData\Local\Microsoft\Windows Media Player NSS\3.0\Icon Files')
 C:\PACKAGES\WINDOWSFOLDER\ServiceProfiles\NetworkService\AppData\Local\Microsoft\Windows Media Player NSS\3.0\Icon Files\00-26-2D-FB-CB-F3.png|8224|4265||1033|00-26-~3.PNG
 C:\PACKAGES\WINDOWSFOLDER\ServiceProfiles\NetworkService\AppData\Local\Microsoft\Windows Media Player NSS\3.0\Icon Files\00-26-2D-FB-D0-3E.png|8224|4265||1033|00-26-~1.PNG
 C:\PACKAGES\WINDOWSFOLDER\ServiceProfiles\NetworkService\AppData\Local\Microsoft\Windows Media Player NSS\3.0\Icon Files\00-26-2D-FB-DA-28.png|8224|4265||1033|00172A~1.PNG
 C:\PACKAGES\WINDOWSFOLDER\ServiceProfiles\NetworkService\AppData\Local\Microsoft\Windows Media Player NSS\3.0\Icon Files\00-26-2D-FB-E4-59.png|8224|4265||1033|00-26-~2.PNG
 C:\PACKAGES\WINDOWSFOLDER\ServiceProfiles\NetworkService\AppData\Local\Microsoft\Windows Media Player NSS\3.0\Icon Files\h66kz1h37t6RD6nXxwtENOSLAo3ldZl+XLhGuiKmQ3M.png|8224|4265||1033|H66KZ1~1.PNG
 C:\PACKAGES\WINDOWSFOLDER\ServiceProfiles\NetworkService\AppData\Local\Microsoft\Windows Media Player NSS\3.0\Icon Files\mL+vAe6URrVDk54Sd8yZz64nVfwYvWnexrrayGi3ar4.png|8224|4265||1033|ML_VAE~1.PNG
 C:\PACKAGES\WINDOWSFOLDER\ServiceProfiles\NetworkService\AppData\Local\Microsoft\Windows Media Player NSS\3.0\Icon Files\pyJ8EVaR23vGyRUeLRxQj5qtCNRTixm7VI0lf7-LS24.png|8224|4265||1033|PYJ8EV~1.PNG
 C:\PACKAGES\WINDOWSFOLDER\ServiceProfiles\NetworkService\AppData\Local\Microsoft\Windows Media Player NSS\3.0\Icon Files\wQO7-meFFUXkhtpp+YD1Ri9-+Ez9nE99tl-SVUdYuOc.png|8224|4265||1033|WQO7-M~1.PNG
EndProc/U
InstallFileList('%SystemFolder%')
 C:\PACKAGES\SYSTEMFOLDER\MSCOMCTL.OCX|32|1077336|6.1.95.45|1033|MSCOMCTL.OCX
 C:\PACKAGES\SYSTEMFOLDER\Msflxgrd.ocx|32|244232|6.0.84.18|1033|Msflxgrd.ocx
 C:\PACKAGES\SYSTEMFOLDER\MSVBVM50.dll|32|1355776|5.2.82.44|1033|MSVBVM50.dll
 C:\PACKAGES\SYSTEMFOLDER\TABCTL32.OCX|32|209608|6.0.90.43|1033|TABCTL32.OCX
EndProc/U
!
!Registry
RegLoad('C:\Packages\Standard.nir')
!
!File Changes
AddIni('%ProgramFilesFolder%\DPFM Service Tool\dpfm.ini')
 [PASSWORDS]
 LEVEL1=¢
 LEVEL2=÷ãõþàç
 
 [UNITS]
 PRESSURE=kpa    
 
 [TRIMS]
 CONFIG_FILE=.\dpfm.cfg                                                               
 
 [DATALINK]
 ADAPTER=Kvaser
 PORT=INLINE4/5, COM1
 UCM_PORT= 1
 
 [MODULE]
 ECU=DPFM
 
 [LEVEL2_UTILITY]
 PARALLEL_RESISTANCE= 200000
 VOLTAGE_DIVIDER= 1000
 REFERENCE_VOLTAGE= 5
EndProc
!
!Icons/Links
CreateLink('DPFM Service Tool','%ProgramFilesFolder%\DPFM Service Tool\DPFM_Service_Tool.exe','%ProgramFilesFolder%\DPFM Service Tool','','PROGRAMS','',)
CreateLink('DPFM Service Tool','%ProgramFilesFolder%\DPFM Service Tool\DPFM_Service_Tool.exe','%ProgramFilesFolder%\DPFM Service Tool','','DESKTOP\Programs','',cgAsCommon)
