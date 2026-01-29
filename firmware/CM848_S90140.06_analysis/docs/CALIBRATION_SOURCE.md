# S90140 Calibration Source Files

## Overview

This folder contains the Intelect/Calterm calibration package for the S90140 firmware family.
The ECU has firmware **S90140.06**, and these files are from **S90140.12** (a later version).

## Extracted Files

| File | Size | Description |
|------|------|-------------|
| `S90140.12` | 1.9 MB | Full calibration data (Intel HEX format with e2m header) |
| `CHR.mdb` | 880 KB | Access database - parameter definitions |
| `actcals.txt` | 21 KB | Active calibrations list (88 S90xxx.xx versions) |
| `chghist.txt` | 25 KB | Change history |
| `CERTCODE.MDB` | 504 KB | Certification codes database |

## Archive Password

**Password:** `fULhOPQtsuO3tFlq3RE3`

Works for all .cmp and .chr files in this package.

## S90140.12 Calibration Header

```
CalibrationVersion=11201316  (11.20.13.16)
ModuleID=CC
ProductID=CHR
ModulePN=3949993
MarketID=AUTOMOTIVE
InterfaceLevel=38
CreationDate=072607  (July 26, 2007)
StartBootLoaderVersion=04000100
EngineID=CHRYSLER
FuelSystemID=HPCR
ByteOrder=BigEndian
AddressLength=32
CPPDataLink=J1939
FileDescriptor=Chrysler_AH V11.20.13.16, Copyright 2007 Cummins Inc.
```

## ECU vs Calibration Version Mapping

| ECU Field | Value | Notes |
|-----------|-------|-------|
| **E/O (Firmware)** | S90140.06 | From ECU sticker |
| **Calibration (EEPROM)** | 11.46.06.xx | From EEPROM offset 0x130 |
| **S90140.12 file** | 11.20.13.16 | From this calibration package |

The S90140.12 calibration file contains version 11.20.13.16, which is different from our ECU's
EEPROM calibration version (11.46.06.xx). This is expected - the .12 suffix in S90140.12 refers
to the firmware revision, not the calibration version.

## Calibration Versions in actcals.txt

The actcals.txt file lists 88 calibration versions for Chrysler vehicles:
- DR = Dodge Ram
- DH/D1 = Dodge Heavy Duty
- DC = Dodge chassis cab
- DM = Dodge Medium duty
- MEGA CAB = Mega Cab variant

Our ECU's firmware **S90140.06** appears to be an earlier revision (v06 vs v12).

## Original Source

```
S90140.12_source/
└── intelect/
    └── esdn/
        └── data/
            ├── esdndata.cmp  → CERTCODE.MDB
            └── CHR/
                ├── CHR.cmp   → CHR.mdb, actcals.txt, chghist.txt
                └── cal/
                    └── S90140.chr → S90140.12
```

Original download location: `/home/linux/Downloads/S90140.12/`
