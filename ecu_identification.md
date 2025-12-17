# Cummins ECU Identification Database

This document tracks known Cummins ECU hardware/software combinations encountered during reverse engineering.

## Column Definitions

| Column | Description |
|--------|-------------|
| **ECU Type** | ECU model (CM550, CM570, CM870, CM2250, etc.) |
| **Module ID** | Module family identifier (EN, etc.) - see Module Naming Convention section |
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

| ECU Type | Module ID | Firmware | Calibration | Engine | ESN | CPL | ECM Code | Part Number | Serial | Date Code | Source | Notes |
|----------|-----------|----------|-------------|--------|-----|-----|----------|-------------|--------|-----------|--------|-------|
| CM550 | EN | J90350.00 | 100898231658 | ISB 195hp | - | - | - | 98502 | T03942860 | 060498 | Live ECU dump | First extraction 2024-12-16 |
| CM550 | EN | J90280.05 | - | ISB (unknown) | - | - | - | - | - | - | Unknown | Reference firmware for analysis |

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

## Module Naming Convention (ENC/ENB/ENA)

**Key Discovery:** The CM550 is shown as "ENC" in Insite, and e2m calibration files are stored in "EN" folders on InCal DVDs. This naming is defined in firmware enums:

### Module ID Breakdown

| Component | Value | Meaning |
|-----------|-------|---------|
| **EN** | 0x454E | Module family identifier (ASCII "EN") for CM550 VP44 ECUs |
| **A/B/C** | 0x41/0x42/0x43 | InCal calibration variant (ASCII 'A', 'B', 'C') |
| **ENC** | Combined | EN module + variant C |

### Firmware Enum Definitions

From `firmware/J90280.05_analysis/ghidra/CM550.rep/enums.csv`:

```
CUMMINS_MODULE_IDS,0x454E,MODULE_EN,Cummins EN module family (CM550 VP44 ECUs)
INCAL_VARIANTS,0x41,VARIANT_A,InCal calibration variant A
INCAL_VARIANTS,0x42,VARIANT_B,InCal calibration variant B
INCAL_VARIANTS,0x43,VARIANT_C,InCal calibration variant C (ENC)
```

### Universal ROM Architecture

**Critical Finding:** The firmware ROM is universal - the variant is determined by EEPROM calibration data, not compile-time constants.

```
ROM (256KB)     = Universal code, same for ALL EN variants (ENA/ENB/ENC)
EEPROM (4KB)    = Calibration-specific configuration
  ├── 0x0100003A = Module ID (0x454E = "EN")
  ├── 0x010002C0 = Data plate (engine model, serial, calibration)
  └── variant    = InCal variant code (A/B/C)
```

**Evidence:**
1. Module ID (0x454E) stored in EEPROM at 0x0100003A, not hardcoded in ROM
2. `module_variant_offsets_t` structure contains `incal_variant_code` field in EEPROM
3. No variant-conditional code (`== 0x41`/`0x42`/`0x43`) found in decompiled firmware
4. Data plate at 0x010002C0 stores engine-specific identification

**Implications:**
- Cummins manufactures ONE firmware ROM image for all ENA/ENB/ENC configurations
- InCal calibration process writes variant code and engine parameters to EEPROM
- InCal DVD folder structure (EN/) represents shared firmware family
- Variant suffix (A/B/C) is set during calibration, not manufacturing

---

## Adding New ECUs

When extracting from a new ECU, record:
1. Run `strings` on EEPROM dump to find identification
2. Check EEPROM offset 0x3A for Module ID (e.g., `454E` = "EN")
3. Look for `Jxxxxx.xx` firmware version pattern
4. Look for `JCMMNS` engine identifier (e.g., `JCMMNSISB 195`)
5. Record any part numbers and serial numbers found
6. Add row to table above

Example EEPROM identification block:
```
Offset 0x3A: 454E    <- Module ID ("EN" = CM550 VP44 family)
T03942860            <- Serial
JCMMNSISB 195        <- Engine (ISB 195hp)
J90350.00 100898231658  <- Firmware + Calibration
```
