	INLINE II DATALINK ADAPTER REFLASH PROGRAM

This program provides a means to upgrade the software (termed:  reflash) inside of an INLINE II datalink adapter.

***********************************************************************

INSTALLATION PROCEDURE:

If loading from a diskette, run the following program:  a:\setup.exe.  If you obtained the software via download, run setup.exe found in the destination directory of your download.  You will be prompted for a directory to install the program files.  The installation procedure will add the following files to your system:

Created the specified installation Directory.

Copied REFLASH.EXE to the intallation Directory.

Copied FLASH.DLL to the intallation Directory.

Copied PRCNT25.VBX to the intallation Directory.

Copied Readme.Txt to the intallation Directory.

Created or modified REFLASH.INI in the windows directory. 

***********************************************************************

RUNNING REFLASH

The reflash icon is linked to reflash.exe.  Double click this icon to launch the program.

***********************************************************************

CONNECTING TO AN INLINE II DATALINK ADAPTER

You do not need to be connected to an ECM to reflash an INLINE II datalink 
adapter.  The 9-pin to 9-pin serial cable must be connected from the 
INLINE II datalink adapter to the computer running the reflash software.
The INLINE II datalink adapter must be powered using one of the available
cable configurations found in the INLINE II datalink adapter kit.
***********************************************************************

REFLASH FUNCTIONALITY

1.0  SETUP BUTTON

   1.1  SERIAL PORT
	1.1.1  Select the communications port to which the INLINE II 
	       datalink	adapter is connected.
   
   1.2  FILE NAME
        1.2.1  Firmware file names will have a ".hex" extension.
	1.2.2  Select the appropriate file name for download into the 
               INLINE II datalink adapter.

2.0  REFLASH BUTTON

   2.1  This button begins the reflash process provided all configuration 
        settings have been sufficiently specified and the INLINE II
	adapter has been connected correctly.
   2.2  The reflah process will begin immediately and will continue until
	complete.

3.0  HELP

   3.1  This will open the file reflash.txt.

4.0  EXIT

   4.1  This will exit the reflash program.
