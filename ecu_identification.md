# Cummins ECU Identification Database

This document tracks known Cummins ECU hardware/software combinations encountered during reverse engineering.

## Column Definitions

| Column | Description |
|--------|-------------|
| **ECU Type** | ECU model (CM550, CM570, CM870, CM2250, etc.) |
| **Firmware** | Firmware version identifier (Jxxxxx.xx format) |
| **Calibration** | Calibration code (numeric identifier) |
| **Engine** | Engine model and horsepower rating |
| **ESN** | Engine Serial Number (if available) |
| **CPL** | Control Parts List - calibration configuration |
| **ECM Code** | ECM module identifier (from Insite) |
| **Part Number** | Cummins part number |
| **Serial** | ECU serial number |
| **Date Code** | Manufacturing date code |
| **Source** | How data was obtained |
| **Notes** | Additional information |

---

## Known ECUs

| ECU Type | Firmware | Calibration | Engine | ESN | CPL | ECM Code | Part Number | Serial | Date Code | Source | Notes |
|----------|----------|-------------|--------|-----|-----|----------|-------------|--------|-----------|--------|-------|
| CM550 | J90350.00 | 100898231658 | ISB 195hp | - | - | - | 98502 | T03942860 | 060498 | Live ECU dump | First extraction 2024-12-16 |
| CM550 | J90280.05 | - | ISB (unknown) | - | - | - | - | - | - | Unknown | Reference firmware for analysis |

---

## ECU Type Reference

| ECU Type | Years | Engine Family | Notes |
|----------|-------|---------------|-------|
| CM550 | 1998-2002 | ISB, ISC | First Cummins electronic ECU for ISB |
| CM570 | 2002-2006 | ISB, ISC | Updated CM550 |
| CM850 | 2003-2007 | ISM, ISX | Heavy duty |
| CM870 | 2007-2010 | ISB, ISC, ISL | EPA07 compliant |
| CM2250 | 2010+ | ISX15 | Modern architecture |

---

## Firmware Version Patterns

Based on observed patterns:
- `J90xxx.xx` - CM550 ISB/ISC calibrations
- `J90280.05` - Reference firmware (unknown application)
- `J90350.00` - ISB 195hp (extracted 2024-12-16)

---

## Adding New ECUs

When extracting from a new ECU, record:
1. Run `strings` on EEPROM dump to find identification
2. Look for `Jxxxxx.xx` firmware version pattern
3. Look for `JCMMNS` engine identifier (e.g., `JCMMNSISB 195`)
4. Record any part numbers and serial numbers found
5. Add row to table above

Example EEPROM identification block:
```
T03942860           <- Serial
JCMMNSISB 195       <- Engine (ISB 195hp)
J90350.00 100898231658  <- Firmware + Calibration
```
