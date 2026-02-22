# CM848 Firmware Analysis (S90140.06)

## Source ECU

### ECU Sticker Information

| Field | Value |
|-------|-------|
| **ECU Type** | CM848D |
| **Part Number** | 3971104 |
| **Serial Number** | 40333 |
| **Date Code** | 04/16/2004 |
| **ESN** | 57185646 |
| **E/O (Firmware)** | S90140.06 |

### Extracted Data

| Field | Value |
|-------|-------|
| **Vehicle** | 2004 Dodge Ram |
| **VIN** | 3D3MU48C94G228471 |
| **Engine** | 5.9L HPCR (High Pressure Common Rail) |
| **EEPROM Date** | 060410 (calibration date, differs from mfg date) |
| **Calibration ID** | 1504 2RSAO (from EEPROM offset 0x46) |
| **Module ID** | CC (from EEPROM offset 0x217, → CHR_CC e2m family) |
| **ROM Build** | 100902 (from ROM offset 0x10C) |
| **Calibration Version** | 11.46.06.xx (from EEPROM offset 0x130, no exact e2m match) |
| **Extraction Date** | 2026-01-28 |
| **Extraction Method** | Live dump via J1939 Service 0x4A |

### Calibration Data Sources

The firmware identifier **S90140.06** follows the same pattern as CM550's J90350.00.

**Primary Source (Intelect/Calterm):**
- **Location:** `/home/linux/Downloads/S90140.12/intelect/esdn/data/CHR/`
- **Calibration file:** `cal/S90140.chr` (password-protected ZIP, contains S90140.12)
- **Database:** `CHR.cmp` contains CHR.mdb, actcals.txt, chghist.txt
- **Note:** S90140.12 is a later version than our S90140.06 firmware

**E2M Parameter Files:**
- **Family:** CHR_CC (Chrysler, Module CC)
- **Closest match:** `CHR_CC_11.45.01.07.e2m` (version proximity to 11.46.06.xx)
- **E2M location:** `E2M/CM848_2100 CHR/CHR/`

## Memory Map

| Region | Start | End | Size | File |
|--------|-------|-----|------|------|
| ROM | 0x00000000 | 0x0006FFFF | 448 KB | `cm848_rom.bin` |
| RAM | 0x003FA000 | 0x0043FFFF | 280 KB | `cm848_ram.bin` |
| EEPROM | 0x01000000 | 0x01001FFF | 8 KB | `cm848_eeprom.bin` |

## Architecture

- **MCU:** PowerPC (not 68K like CM550)
- **ROM Vectors:** PPC branch table (`48 00 xx xx` = branch instructions)
- **Endianness:** Big-endian

## Key Differences from CM550

| Aspect | CM550 | CM848 |
|--------|-------|-------|
| MCU | MC68336 (68020) | PowerPC |
| ROM Size | 256 KB | 448 KB |
| RAM Size | 37 KB | 280 KB |
| EEPROM Size | 4 KB | 8 KB |
| RAM Base | 0x00800000 | 0x003FA000 |
| Fuel System | VP44 Pump | HPCR |

## EEPROM Structure

```
Offset 0x00: 60 0D 41 42 43 44 45 46  - Header + Security Key "ABCDEF"
Offset 0x46: 31 35 30 34 20 32 52 53  - "1504 2RS" calibration fragment
Offset 0x80: 30 36 30 34 31 30        - "060410" date code
Offset 0x1D1: 43 4D 4D 4E 53          - "CMMNS" (Cummins identifier)
Offset 0x288: VIN (17 chars)          - "3D3MU48C94G228471"
```

Note: Many calibration fields appear zeroed, common for reprogrammed ECUs.

## ROM Structure

```
Offset 0x000: Exception/interrupt vector table (PPC branches)
Offset 0x100: 48 00 16 DE ...         - Code start
Offset 0x10C: 31 30 30 39 30 32       - "100902" version/date
```

## Analysis Status

- [ ] Load into Ghidra with PowerPC processor
- [ ] Identify entry points from vector table
- [ ] Map memory regions
- [ ] Compare with CM550 for shared protocol code
- [ ] Identify HPCR fuel control routines

## Directory Structure

```
CM848_S90140.06_analysis/
├── originals/          # Raw dump files (read-only)
│   ├── cm848_rom.bin
│   ├── cm848_ram.bin
│   └── cm848_eeprom.bin
├── output/             # Analysis outputs (CSVs, decompiled code)
├── ghidra/             # Ghidra project files
├── docs/               # Documentation and notes
└── README.md
```

## Related

- `/firmware/CM550_J90280.05_analysis/` - CM550 reference firmware (ROM only)
- `/firmware/CM550_J90350.00_analysis/` - CM550 live extraction (full ROM + RAM)
- `/ecu_identification.md` - ECU database
