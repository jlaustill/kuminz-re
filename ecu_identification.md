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
| **Date Code** | Manufacturing date code (DDMMYY format on ECU label) |
| **Build Date** | Firmware build date (for version chronology) |
| **Source** | How data was obtained |
| **Notes** | Additional information |

**Related:** See `firmware/feature_comparison.csv` for cross-firmware feature tracking.

---

## Known ECUs

| ECU Type  | Module ID | Firmware  | Calibration   | Engine        | ESN       | CPL | ECM Code  | Part Number | Serial    | Date Code | Build Date | Source              | Notes                           |
|-----------|-----------|-----------|---------------|---------------|-----------|-----|-----------|-------------|-----------|-----------|------------|---------------------|---------------------------------|
|           |           |           |               |               |           |     |           | 3947412     |           |           |            | Physical Chip Dump  |                                 |
| CM550     | EN        | J90350.00 | 100898231658  | ISB 195hp     | -         | -   | -         | 98502       | T03942860 | 060498    | 1998-04-06 | Live ECU dump       | First extraction 2024-12-16     |
| CM550     | EN        | J90280.05 | -             | ISB (unknown) | -         | -   |           | -           | -         | -         | Unknown    | Unknown             | Reference firmware for analysis |
| CM550     | ?         | &I091197  | -             | 5.9L ISB      | -         | -   | -         | -           | -         | -         | 1997-09-11 | Physical Chip Dump  | Pre-production prototype, VIN embedded |
| CM550     | E1        | J90270.06 | -             | 6BTA 5.9L     | -         | -   | -         | FP98456     | 4J,J039479121A0505648 | 062800 | 2000-06-28 | Physical Chip Dump | Chrysler T-300 commercial truck (EEPROM only) |
| CM550     | E1        | J90831.05 | -             | 6BTA 5.9L     | -         | -   | -         | FP98849     | 039474121C0302023 | 012401 | 2001-01-24 | Physical Chip Dump | Dodge Ram Br/BE (EEPROM only) |
| CM848D    |           |           |               |               | 57185646  |     |           | 3971404     | 40333     |           |            |                     |                                 |

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
- `J90xxx.xx` - CM550 ISB/ISC production calibrations
- `&Ixxxxxx` - Pre-production/prototype firmware (date-based identifier)
- `J90280.05` - Reference firmware (unknown application)
- `J90270.06` - T-300 commercial truck calibration
- `J90350.00` - ISB 195hp (extracted 2024-12-16)
- `J90831.05` - Dodge Ram Br/BE calibration

### ROM Build Type Identifier

The ROM header contains a 2-character build type identifier at offset 0x0E:

| Identifier | Hex | Type | Example |
|------------|-----|------|---------|
| `wl` | 0x776C | Production release | J90350.00 |
| `&I` | 0x2649 | Development/prototype | 1999 Dodge ROM |

**Header Structure (offset 0x00-0x17):**
```
00-03: Initial Stack Pointer (0x00810000)
04-07: Initial Program Counter (0x0000001e)
08-0B: Checksum/identifier (varies)
0C-0D: Unknown (varies)
0E-0F: Build type ('wl' = production, '&I' = prototype)
10-15: Build date (MMDDYY ASCII)
16-17: Version bytes
```

**Hypothesis:** The `&I` prefix likely indicates an internal/engineering build not intended for production release. The `&` character would be unusual in a production identifier. The `wl` code may stand for "work level" or similar production designation.

---

## Firmware Chronology

Build dates are critical for understanding firmware evolution. When comparing two firmware versions:
- **Newer firmware** may have features added
- **Older firmware** may have features that were later removed
- **Same date range** suggests preprocessor-excluded features (different compile flags)

### Confirmed Timeline

| Firmware | Build Date | Module ID | Application | Notes |
|----------|------------|-----------|-------------|-------|
| &I091197 | 1997-09-11 | ? | Dodge Ram prototype | Pre-production, VIN embedded in ROM |
| J90350.00 | 1998-04-06 | EN | ISB 195hp | Full auth, more RAM vars |
| J90280.05 | Unknown | EN | ISB (unknown) | Auth stub, fewer RAM vars |
| J90270.06 | 2000-06-28 | E1 | Chrysler T-300 | Commercial truck (EEPROM only) |
| J90831.05 | 2001-01-24 | E1 | Dodge Ram Br/BE | 2nd gen Ram (EEPROM only) |

### Cross-Firmware Analysis

See `docs/cross-firmware-analysis.md` for methodology on:
- Tracking excluded features (preprocessor `#ifdef`)
- Identifying method version changes
- Detecting added/removed features
- Using relocation maps for comparison

---

## Module Naming Convention (ENC/ENB/ENA)

**Key Discovery:** The CM550 is shown as "ENC" in Insite, and e2m calibration files are stored in "EN" folders on InCal DVDs. This naming is defined in firmware enums:

### Module ID Breakdown

| Component | Value | Meaning |
|-----------|-------|---------|
| **EN** | 0x454E | Module family identifier (ASCII "EN") for CM550 VP44 ECUs |
| **E1** | 0x4531 | Module family identifier (ASCII "E1") - possibly hardware revision |
| **A/B/C** | 0x41/0x42/0x43 | InCal calibration variant (ASCII 'A', 'B', 'C') |
| **ENC** | Combined | EN module + variant C |

### E1 vs EN Module ID Discovery

Physical chip dumps revealed a second Module ID `E1` distinct from `EN`:

| Module ID | EEPROM Value | Known Firmware | Notes |
|-----------|--------------|----------------|-------|
| EN | `454E` (ENUU at 0x3A) | J90350.00, J90280.05 | Live extraction, reference |
| E1 | `4531` (E1UU at 0x3A) | J90270.06, J90831.05 | Physical chip dumps |

**Possible meanings:**
- Different hardware revision of CM550
- Different ECU model within same family
- Regional or OEM-specific variant

**Same EEPROM structure:** Both E1 and EN modules use identical EEPROM layout (header `600d ABCDEF`).

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
