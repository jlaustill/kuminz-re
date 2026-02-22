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

| ECU Type  | Module ID | Firmware           | Calibration   | Engine        | ESN       | CPL | ECM Code  | Part Number | Serial    | Date Code | Build Date | Source              | Notes                           |
|-----------|-----------|--------------------|---------------|---------------|-----------|-----|-----------|-------------|-----------|-----------|------------|---------------------|---------------------------------|
|           |           |                    |               |               |           |     |           | 3947412     |           |           |            | Physical Chip Dump  |                                 |
| CM550     | EN        | J90350.00          | 100898231658  | ISB 195hp     | -         | -   | -         | 98502       | T03942860 | 060498    | 1998-04-06 | Live ECU dump       | First extraction 2024-12-16     |
| CM550     | EN        | J90280.05          | -             | ISB (unknown) | -         | -   |           | -           | -         | -         | Unknown    | Internet ROM only   | Reference firmware only (no RAM) |
| CM550     | ?         | &I091197  | -             | 5.9L ISB      | -         | -   | -         | -           | -         | -         | 1997-09-11 | Physical Chip Dump  | Pre-production prototype, VIN embedded |
| CM550     | E1        | J90270.06 | -             | 6BTA 5.9L     | -         | -   | -         | FP98456     | 4J,J039479121A0505648 | 062800 | 2000-06-28 | Physical Chip Dump | Chrysler T-300 commercial truck (EEPROM only) |
| CM550     | E1        | J90831.05 | -             | 6BTA 5.9L     | -         | -   | -         | FP98849     | 039474121C0302023 | 012401 | 2001-01-24 | Physical Chip Dump | Dodge Ram Br/BE (EEPROM only) |
| CM848D    | CC        | S90140.06 | 1504 2RSAO    | 5.9L HPCR     | 57185646  | -   | -         | 3971104     | 40333     | 041604    | 2004-04-16 | Live ECU dump       | 2004 Dodge Ram, VIN 3D3MU48C94G228471, first CM848 extraction 2026-01-28, EEPROM cal version 11.46.06.xx |

---

## ECU Type Reference

| ECU Type | Years | Engine Family | MCU | Notes |
|----------|-------|---------------|-----|-------|
| CM550 | 1998-2002 | ISB, ISC | MC68336 (68K) | First Cummins electronic ECU for ISB, VP44 pump |
| CM570 | 2002-2006 | ISB, ISC | ? | Updated CM550 |
| CM848 | 2003-2006 | ISB 5.9L | PowerPC | Dodge Ram, HPCR (High Pressure Common Rail) |
| CM850 | 2003-2007 | ISM, ISX | ? | Heavy duty |
| CM870 | 2007-2010 | ISB, ISC, ISL | ? | EPA07 compliant |
| CM2250 | 2010+ | ISX15 | ? | Modern architecture |

---

## Firmware Version Patterns

Based on observed patterns:
- `J90xxx.xx` - CM550 ISB/ISC production calibrations
- `S90xxx.xx` - CM848 production calibrations (PowerPC architecture)
- `&Ixxxxxx` - Pre-production/prototype firmware (date-based identifier)
- `J90280.05` - Reference firmware (unknown application)
- `J90270.06` - T-300 commercial truck calibration
- `J90350.00` - ISB 195hp (extracted 2024-12-16)
- `J90831.05` - Dodge Ram Br/BE calibration
- `S90140.06` - CM848D Dodge Ram HPCR (extracted 2026-01-28)

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
| J90280.05 | Unknown | EN | ISB (unknown) | Auth stub, fewer RAM vars (ROM only) |
| J90270.06 | 2000-06-28 | E1 | Chrysler T-300 | Commercial truck (EEPROM only) |
| J90831.05 | 2001-01-24 | E1 | Dodge Ram Br/BE | 2nd gen Ram (EEPROM only) |

### Cross-Firmware Analysis

See `docs/cross-firmware-analysis.md` for methodology on:
- Tracking excluded features (preprocessor `#ifdef`)
- Identifying method version changes
- Detecting added/removed features
- Using relocation maps for comparison

---

## CM848 Architecture (2003-2006 Dodge Ram 5.9L)

The CM848 is a significant departure from CM550 architecture, using PowerPC instead of 68K.

### Memory Map Comparison

| Region | CM550 | CM848 | Notes |
|--------|-------|-------|-------|
| **ROM** | 0x00000000 - 0x0003FFFF (256KB) | 0x00000000 - 0x0006FFFF (448KB) | 1.75x larger |
| **RAM** | 0x00800000 - 0x008091C2 (37KB) | 0x003FA000 - 0x0043FFFF (280KB) | 7.5x larger, different base |
| **EEPROM** | 0x01000000 - 0x01000FFF (4KB) | 0x01000000 - 0x01001FFF (8KB) | 2x larger, same base |

### Key Differences

| Aspect | CM550 | CM848 |
|--------|-------|-------|
| MCU | Motorola MC68336 (68020 core) | PowerPC |
| ROM vectors | 68K exception table | PPC branch table (`48 00 xx xx`) |
| Fuel system | VP44 injection pump | HPCR (High Pressure Common Rail) |
| Build marker location | ROM offset 0x0E | Embedded in code |

### Protocol Compatibility

Despite the architecture change, CM848 uses the **same diagnostic protocol** as CM550:
- J1939 CAN bus at 250kbps
- Service 0x4A memory read works identically
- EEPROM header format unchanged (`60 0D ABCDEF`)

---

## Protocol Matrix

This matrix documents protocol and service support across ECU types based on testing with kuminz-cli.

### Diagnostic Services (J1939 Proprietary A - PGN 0xEF00)

| Service | Code | CM550 | CM848 | Description |
|---------|------|-------|-------|-------------|
| **Memory Read** | 0x4A | ✓ | ✓ | Read memory by address (up to 255 bytes) |
| **Memory Write** | 0x4B | ✓ | ? | Write memory by address (authenticated) |
| **Read Param by ID** | 0x46 | ✓ | ? | Read parameter by ID |
| **Read Param+Offset** | 0x43 | ✓ | ? | Read parameter with offset |
| **Service 0x05** | 0x05 | J1708 only | ? | Write service (J1708 bus, not CAN) |

### CLIP Protocol (Session-Based)

| Command | Code | CM550 | CM848 | Description |
|---------|------|-------|-------|-------------|
| **GetParametersByID** | 0x10 | ✓ | ? | Read parameters by ID |
| **SetParametersByID** | 0x11 | ✓ | ? | Write parameters by ID |
| **ExecuteOperation** | 0x12 | ✓ | ? | Execute ECU operation |
| **GetDataByAddress** | 0x14 | ✓ | ? | Read memory (session) |
| **SetDataByAddress** | 0x15 | ✓ | ? | Write memory (session) |
| **GetAddressByParamID** | 0x16 | ✓ | ? | Resolve param ID to address |

### Authentication

| Aspect | CM550 | CM848 | Notes |
|--------|-------|-------|-------|
| **Security Key** | `ABCDEF` | `ABCDEF` | Same 6-byte key |
| **Hour Meter Address** | 0x80BDA4 | 0x40B7BA? | Used for auth payload |
| **Auth Algorithm** | Bit-packing | Same? | XOR + reorder tables |
| **Write Protection** | RAM only | RAM only | ROM/EEPROM read-only via 0x4A |

### CAN Bus Configuration

| Parameter | CM550 | CM848 | Notes |
|-----------|-------|-------|-------|
| **Bus Speed** | 250 kbps | 250 kbps | J1939 standard |
| **Tool Address** | 0xF9 | 0xF9 | Diagnostic tool SA |
| **ECU Address** | 0x00 | 0x00 | Engine controller SA |
| **PGN (Tool→ECU)** | 0xEF00 | 0xEF00 | Proprietary A |
| **CAN ID (Tool→ECU)** | 0x18EF00F9 | 0x18EF00F9 | PDU1 format |
| **CAN ID (ECU→Tool)** | 0x18EFF900 | 0x18EFF900 | PDU1 format |

### Transport Protocol

| Aspect | CM550 | CM848 | Notes |
|--------|-------|-------|-------|
| **Single Frame** | ≤8 bytes | ≤8 bytes | Direct response |
| **Multi-Frame** | J1939 TP | J1939 TP | RTS/CTS/DT/EOM |
| **TP PGN (CM)** | 0xEC00 | 0xEC00 | Connection Management |
| **TP PGN (DT)** | 0xEB00 | 0xEB00 | Data Transfer |
| **Max TP Payload** | 1785 bytes | 1785 bytes | 255 frames × 7 bytes |

### Memory Regions Accessible via Service 0x4A

| Region | CM550 | CM848 | Access |
|--------|-------|-------|--------|
| **ROM/Flash** | ✓ 256KB | ✓ 448KB | Read-only |
| **RAM** | ✓ 37KB | ✓ 280KB | Read/Write (auth) |
| **EEPROM** | ✓ 4KB | ✓ 8KB | Read-only via 0x4A |
| **Flash Bank 2** | N/A | ✓ 248KB | Read-only |

**Legend:** ✓ = Confirmed working, ? = Untested, N/A = Not applicable

### CM848 Variants

| Variant | HP | Notes |
|---------|-----|-------|
| CM848B | 305 | Standard |
| CM848C | 325 | High output |
| CM848D | ? | Unknown variant |

### Dump Commands

```bash
# Added to kuminz-cli (2026-01-28)
./kuminz-cli can0 --cm848-dump-rom [file]     # 448KB firmware
./kuminz-cli can0 --cm848-dump-ram [file]     # 280KB runtime data
./kuminz-cli can0 --cm848-dump-eeprom [file]  # 8KB calibration
./kuminz-cli can0 --cm848-dump-all [dir]      # All regions
```

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
| EN | `454E` (ENUU at 0x3A) | J90350.00, J90280.05 | Live extraction (J90350), ROM only reference (J90280) |
| E1 | `4531` (E1UU at 0x3A) | J90270.06, J90831.05 | Physical chip dumps |

**Possible meanings:**
- Different hardware revision of CM550
- Different ECU model within same family
- Regional or OEM-specific variant

**Same EEPROM structure:** Both E1 and EN modules use identical EEPROM layout (header `600d ABCDEF`).

### Firmware Enum Definitions

From `firmware/CM550_J90280.05_analysis/ghidra/CM550.rep/enums.csv`:

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
