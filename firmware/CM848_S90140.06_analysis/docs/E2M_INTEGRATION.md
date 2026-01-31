# E2M Calibration Integration for CM848 Firmware Analysis

## Summary

We extracted **2,204 internal variable names** from the S90140.12 calibration file. These names follow Cummins' internal naming conventions and provide semantic meaning for firmware parameters.

## E2M File Structure (Two Distinct Sections)

E2M files contain **two different types of data**:

### 1. CSV Parameter Records (Documented in e2m-analysis/)

The CSV section defines calibration parameters using the Column 3 + Column 4 formula:
```
Memory Address = BaseLookup[Column3] + Column4
```

This is used for:
- Tuning parameters (lookup tables, constants)
- Configuration settings
- Sensor scaling factors

**Calterm resolves these addresses at runtime** using `GetAddressByParameterID` (CLIP command 0x16).

### 2. Binary Hex Dump Records (Data Records Section)

The `[Data Records]` section contains **raw binary code and data** at absolute addresses:

```
[Data Records]
# Address    | Hex Data                                         | ASCII
0x00008000 | 4801056248010562480543CE48010562                   | H..bH..bH.C.H..b
...
# Extended linear address: 0x00500000
0x00500000 | 0000A1A19421FFE07C0802A690010024                   | .....!..|......$
...
# Extended linear address: 0x01000000
0x01000000 | FFFFFFFFFFFFFFFF...                                | ................
```

This section contains:
| Region | Address Range | Content |
|--------|---------------|---------|
| ROM | 0x00008000+ | Firmware code |
| Bank 2 (FLASH2) | 0x00500000+ | Utility functions (sensor processing, math) |
| EEPROM | 0x01000000+ | Non-volatile calibration data |

### Critical: Binary Code is Version-Specific

The Bank 2 binary code contains **RAM addresses compiled into PowerPC instructions**:
```
addi r12, r12, 0xB8FE   ; E2M (S90140.12)
addi r12, r12, 0xBD88   ; Live ECU (different version)
```

**Different firmware versions have different RAM layouts**, so:
- Same code structure, different address operands
- E2M binary is only correct for matching firmware version
- Live ECU dump should be used for analysis if versions differ

### Calterm Download Flow (from RE)

1. Calterm tries to load **BDS (Block Data Structure)** from ECU via parameters
2. If that fails: "Using Generic e2m for download"
3. Binary blocks from e2m file are transferred to ECU at specified addresses

This means e2m files are used to **program** the ECU, not just configure parameters.

## Generated Files

| File | Description |
|------|-------------|
| `output/internal_names.csv` | 2,204 internal names with parameter mappings |
| `output/internal_names.txt` | Simple list for grep searching |
| `output/internal_names_reference.md` | Reference document grouped by prefix |
| `output/internal_names_crossref.md` | Cross-reference with decompiled code |
| `output/suggested_variable_names.csv` | Concrete suggestions for global_variables.csv |
| `output/e2m_parameters.csv` | 9,777 e2m parameters with addresses and units |
| `output/e2m_variables.csv` | 9,777 e2m variables for Ghidra import |

## Internal Naming Convention

Cummins uses a systematic naming scheme:

### Prefixes (Top 10)

| Prefix | Count | Meaning |
|--------|-------|---------|
| AD | 225 | A/D Converter (sensor inputs, filtering, faults) |
| JC | 163 | J1939 CAN Protocol |
| HS | 120 | High Speed / Horsepower System |
| EP | 96 | Engine Protection |
| LS | 95 | Limiting System |
| PT | 87 | Protection / Power Train |
| AS | 70 | Acceleration System |
| FS | 61 | Fuel System |
| MX | 54 | Maximum Limits |
| DG | 36 | Diagnostics |

### AD Prefix Sensor Patterns

| Pattern | Meaning | Example |
|---------|---------|---------|
| ADAAPR* | Ambient Air Pressure | ADAAPRHL = AAP High Limit |
| ADBSPR* | Boost Pressure | ADBSPRCC = Boost Fault Clear |
| ADBTVT* | Battery Voltage | ADBTVTHE = BTV High Error |
| ADCLTP* | Coolant Temperature | ADCLTPCS = CLT Filter Constant |
| ADFLTP* | Fuel Temperature | ADFLTPLL = FLT Low Limit |
| ADIMTP* | Intake Manifold Temp | ADIMTPHE = IMT High Error |
| ADOLPR* | Oil Pressure | ADOLPRSE = OLP Fault Set |

### AD Prefix Suffixes

| Suffix | Meaning |
|--------|---------|
| CC | Fault Clear count |
| CS | Filter Constant |
| DT | Fault Decrement |
| HE | High Error threshold |
| HL | High Limit (raw value) |
| IC | Fault Increment count |
| LE | Low Error threshold |
| LL | Low Limit (raw value) |
| OD | Override value |
| SE | Fault Set threshold |
| XA | X Axis (lookup table) |
| YA | Y Axis (lookup table) |
| PZ | Priority (for override logic) |

## J1939 Diagnostic Fault Codes

The DG prefix contains **J1939 SPN (Suspect Parameter Number)** fault codes:

```
DG0111JC = SPN 629 - ECM Internal Failure (Red)
DG0115JC = SPN 190 - Engine Speed Signals Lost (Red)
DG0122JC = SPN 102 - Boost Pressure Shorted High (Yellow)
DG0131JC = SPN 91  - Accelerator Pedal Shorted High (Red)
DG0135JC = SPN 100 - Oil Pressure Shorted High (Yellow)
DG0144JC = SPN 110 - Coolant Temp Shorted High (Yellow)
DG0221JC = SPN 108 - Ambient Air Pressure Shorted High (Yellow)
```

Severity levels: **Red** = critical, **Yellow** = warning, **ENGINE PROTECTION** = derate/shutdown

## How to Use These Resources

### 1. Search for Related Variables

```bash
# Find all boost pressure related names
grep "ADBSPR" output/internal_names.csv

# Find all fault/diagnostic codes
grep "^DG" output/internal_names.csv | grep SPN

# Search decompiled code for patterns
grep -i "boost" output/cm848_rom.ghidra.cpp
```

### 2. Apply Suggested Names

Review `output/suggested_variable_names.csv` and add approved names to `output/global_variables.csv`:

```bash
# Apply to Ghidra
./ghidra/analyze.sh import
./ghidra/analyze.sh export
```

### 3. Cross-Reference Function Analysis

When analyzing a function, use the naming patterns to identify purpose:

1. Look at existing named variables (e.g., `_coolant_temp_sensor`)
2. Check what prefix applies (ADCLTP for coolant temp)
3. Search internal_names.csv for related parameters
4. Apply appropriate names to unnamed DAT_ variables

### 4. Understand Fault Handling

The fault system uses:
- **Increment counter** (IC) to count fault occurrences
- **Set threshold** (SE) to trigger fault
- **Clear counter** (CC) to count good readings
- **Decrement threshold** (DT) to clear fault

## Statistics

- **Total internal names**: 2,204
- **Named functions in Ghidra**: 146
- **Named variables in Ghidra**: 750
- **Unnamed RAM variables**: 4,434
- **Variables with suggested matches**: 283

## Next Steps

1. Review `suggested_variable_names.csv` and add validated names to `global_variables.csv`
2. Use internal names to guide analysis of protection and fault handling functions
3. Cross-reference J1939 SPN codes with diagnostic message handlers
4. Match e2m calibration addresses with EEPROM read patterns in firmware
