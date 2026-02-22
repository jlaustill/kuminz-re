# CM550 RAM Memory Map

**Source**: 37KB RAM dump captured via Service 0x4A memory read
**RAM Range**: 0x800000 - 0x8091C2 (37,315 bytes)
**Captured**: 2024-12-16
**ECU Serial**: T03942860
**Calibration**: J90350.00 (GENERIC)

## Memory Region Overview

| Region | Address Range | Size | Purpose |
|--------|---------------|------|---------|
| Control Variables | 0x800000-0x8002DF | 736 B | RPM control, DMA, governors |
| Timer Array | 0x800002E0-0x80031F | 64 B | System timers (all=10000) |
| Protection Flags | 0x800320-0x8005FF | 736 B | Fault detection, protection |
| Pointer Tables | 0x800600-0x8007FF | 512 B | RAM structure pointers |
| Working Buffers | 0x800800-0x800AFF | 768 B | General working memory |
| **Diagnostic Buffer** | **0x800B00-0x800BFF** | 256 B | **Diagnostic request/response (UNDOCUMENTED)** |
| Runtime Data | 0x800C00-0x803AFF | 12 KB | Engine runtime variables |
| **ECU Identity Block** | **0x803B00-0x803FFF** | 1.25 KB | **Serial, calibration, OEM (UNDOCUMENTED)** |
| Calibration Tables | 0x804000-0x807FFF | 16 KB | RPM/Load tables, lookup data |
| Parameter Storage | 0x808000-0x8091C2 | 4.5 KB | Live parameter values |

## Newly Discovered Structures (Not in CSV)

### 1. Diagnostic Buffer @ 0x800B00

48-byte repeating record structure for diagnostic message handling:

```
Offset  Size  Field                    Value (from dump)
0x00    16    Header/flags             00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
0x10    1     Status byte              0x0D (STATUS_RESPONSE)
0x11    9     Reserved                 00 00 00 00 00 00 00 00 00
0x1A    1     Error code               0x18 (UNKNOWN_SERVICE)
0x1B    2     PGN/response             0xEFF9
0x1D    1     Padding                  00
0x1E    1     Unknown                  00
0x1F    1     Unknown                  86
0x20    4     Buffer pointer 1         0x00800B2A
0x24    4     Buffer pointer 2         0x00800B28
0x28    2     Service response         0x4B09 (Service 0x4B acknowledgment)
0x2A    4     Self-reference           0x800B0080
0x2E    2     Padding                  00 00
```

**Pattern repeats at**: 0x800B30, 0x800B60, 0x800B90 (4 slots)

### 2. ECU Identity Block @ 0x803B00

| Offset | Address | Size | Field | Value |
|--------|---------|------|-------|-------|
| 0x00 | 0x803B00 | 10 | Header | 00 00 00 00 00 00 00 00 00 00 |
| 0x0A | 0x803B0A | 2 | Marker1 | `\x60\x0D` |
| 0x0C | 0x803B0C | 6 | Test pattern | "ABCDEF" |
| 0x12 | 0x803B12 | 3 | Unknown | ED 79 87 |
| 0x15 | 0x803B15 | 10 | **ECU Serial** | "T03942860" |
| 0x1F | 0x803B1F | 33 | Padding | 00... |
| 0x40 | 0x803B40 | 4 | Unknown | 0D 8F 8E E8 |
| 0x44 | 0x803B44 | 4 | Marker2 | "ENUU" (Engine Unit?) |
| 0x48 | 0x803B48 | 4 | Unknown | 00 3D 65 12 |
| 0x88 | 0x803B88 | 6 | Build date? | "060498" (June 4, 1998?) |

### 3. Calibration Identity @ 0x803E00

| Offset | Address | Size | Field | Value |
|--------|---------|------|-------|-------|
| 0x00 | 0x803E00 | 10 | Header | "8502  \x00\x02..." |
| 0x1D | 0x803E1D | 26 | **Calibration ID** | "J90350.00 100898231658&" |
| 0x60 | 0x803E60 | 80 | **OEM Name** | "GENERIC" (padded to 80 chars) |
| 0xC2 | 0x803EC2 | 60+ | **Part Numbers** | "39453601003945361200..." |

### 4. Timer Array @ 0x8002E0

32 x 16-bit timers, all initialized to 10000 (0x2710):

```
0x8002E0: 2710 2710 2710 2710 2710 2710 2710 2710  '.'.'.'.'.'.'.'.
0x8002F0: 2710 2710 2710 2710 2710 2710 2710 2710  '.'.'.'.'.'.'.'.
0x800300: 2710 2710 2710 2710 2710 2710 2710 2710  '.'.'.'.'.'.'.'.
0x800310: 2710 2710 2710 2710 2710 2710 2710 2710  '.'.'.'.'.'.'.'.
```

**Purpose**: System scheduler timers (10000 = 10 second intervals?)

## Calibration Tables

### RPM Breakpoint Table @ 0x8072F4

16 x 16-bit RPM values (big-endian):

| Index | Hex | Decimal | RPM |
|-------|-----|---------|-----|
| 0 | 0x0020 | 32 | 32 |
| 1 | 0x0C80 | 3200 | 3200 |
| 2 | 0x0FA0 | 4000 | 4000 |
| 3 | 0x12C0 | 4800 | 4800 |
| ... | ... | ... | ... |
| 15 | 0x3840 | 14400 | 14400 |

### Load Breakpoint Table @ 0x807176

16 x 16-bit Load values:

| Index | Value | Interpretation |
|-------|-------|----------------|
| 0 | 48 | 0% load |
| 1 | 0 | - |
| 2 | 1200 | 12% load |
| 3 | 2400 | 24% load |
| ... | ... | ... |
| 15 | 14800 | 148% load (max) |

## RAM Pointer Table @ 0x800600

Contains pointers to various RAM structures:

| Offset | Value | Points To | Purpose |
|--------|-------|-----------|---------|
| 0x00 | 0x00807176 | Load breakpoints | Calibration lookup |
| 0x04 | 0x000071A8 | Unknown | - |
| 0x20 | 0x00807176 | Load breakpoints | (duplicate) |
| 0x24 | 0x0080D27A | Unknown | - |
| 0x28 | 0x008058CE | Unknown | - |
| 0x70 | 0x00807F66 | Unknown | - |
| 0x90 | 0x00809EF2 | Unknown | - |

## Verification Status

### Verified via RAM Dump
- [x] Timer array all=10000 (0x8002E0)
- [x] ECU Serial T03942860 (0x803B15)
- [x] Calibration J90350.00 (0x803E1D)
- [x] OEM name GENERIC (0x803E60)
- [x] RPM breakpoints 32-14400 (0x8072F4)
- [x] Load breakpoints 0-14800 (0x807176)

### Needs Xref Analysis (Ghidra)
- [ ] Diagnostic buffer handlers (0x800B00)
- [ ] ECU identity reading code (0x803B00)
- [ ] Timer array initialization (0x8002E0)
- [ ] Calibration table access (0x8072F4, 0x807176)

## CSV Update Recommendations

### global_variables.csv additions:

```csv
0x00800B00,diagnostic_request_buffer,byte[256],Diagnostic request/response buffer - 4 x 48-byte slots - NOT YET VERIFIED,256,0,,buffer
0x00803B00,ecu_identity_header,byte[10],ECU identity block header,10,0,,header
0x00803B0A,ecu_identity_marker_1,word,ECU identity marker 0x600D,2,0,,marker
0x00803B0C,ecu_identity_test_pattern,byte[6],ECU identity test pattern ABCDEF,6,2,,string
0x00803B15,ecu_serial_number,byte[10],ECU serial number (e.g. T03942860) - VERIFIED via RAM dump,10,2,,string
0x00803B44,ecu_unit_marker,byte[4],ECU unit marker ENUU,4,2,,string
0x00803B88,ecu_build_date,byte[6],ECU build date string (MMDDYY format),6,2,,string
0x00803E1D,calibration_id_string,byte[26],Calibration ID (e.g. J90350.00 100898231658) - VERIFIED via RAM dump,26,2,,string
0x00803E60,oem_name_string,byte[80],OEM name string (e.g. GENERIC) - VERIFIED via RAM dump,80,2,,string
0x00803EC2,part_number_list,byte[60],Concatenated part number strings,60,2,,string
0x008002E0,system_timer_array,word[32],System scheduler timer array - all initialized to 10000 - VERIFIED via RAM dump,64,0,CNT,array
0x008072F4,rpm_breakpoint_table,word[16],RPM breakpoint table 32-14400 RPM - VERIFIED via RAM dump,32,0,RPM,lookup
0x00807176,load_breakpoint_table,word[16],Load breakpoint table 0-14800 - VERIFIED via RAM dump,32,0,LOAD,lookup
```

## E2M Parameter Address Correlation

### E2M Address Formula

```
E2M Address = BaseLookup[Column3] + Column4 (hex offset)
```

**Statistics:**
| Metric | Value |
|--------|-------|
| Total Column3 Mappings | 521 |
| Mapped Parameters | ~2,050 (58.2%) |
| Unmapped (offline tables) | 139 |

### Memory Zone Distribution

**IMPORTANT:** E2M parameters span multiple memory zones, NOT just RAM:

| Memory Zone | Params | Address Range | Persistence | Contents |
|-------------|--------|---------------|-------------|----------|
| External_RAM | 1,062 | 0x0080xxxx | **Volatile** | Runtime values, sensor readings |
| EEPROM | 78 | 0x0100xxxx | **Persistent** | Adjustable settings (droop, gains, PTO speeds) |
| CalTerm_Storage | 37 | 0x0006xxxx | Varies | Tool parameter limits |
| Flash/ROM | 8 | 0x0000xxxx | Read-only | Factory defaults |
| **Unmapped** | 139 | Unknown | **Persistent** | Large lookup tables (timing, fueling, linearization) |

### "Available Offline" Parameters

Parameters marked `availableOffline=true` in Calterm can be read/written when engine is OFF.
These 139 parameters are large calibration tables stored in EEPROM:
- Timing advance tables (4DTA00XA, 4DTA01XA)
- Fueling tables (5DFL00XA, 5DFL01XA)
- Sensor linearization tables (ADBSPRXA/YA for boost pressure)

Their Column3 values (0x1040, 0x1058, 0x1016, etc.) aren't mapped yet.

### Linearization Tables Location

The sensor linearization tables (e.g., ADBSPRXA @ 0x806C4A) are in the **ROM copy area**:
- Source: ROM 0x37EAE (factory defaults)
- Destination: RAM 0x8062D2-0x808AB2

These have factory defaults from ROM but can be overwritten via EEPROM for persistent customization.

### EEPROM to RAM Copy Flow

| Source | Source Address | RAM Destination | Size |
|--------|---------------|-----------------|------|
| EEPROM Block 1 | 0x4000 | 0x804882-0x80488C | 10 bytes |
| EEPROM Block 2 | 0x4400 | 0x80488E-0x8062D0 | 6,722 bytes |
| ROM Firmware | 0x37EAE | 0x8062D2-0x808AB2 | 10,208 bytes |

**Key Functions:**
- `calibrationDataCopyWithChecksum` @ 0xEBF2 - Copies EEPROM (0x4000, 0x4400) to RAM
- `firmwareDataCopyToWorkingMemory` @ 0xF4EA - Copies ROM to RAM

### Ghidra Memory Segments

| Segment | Address Range | Purpose |
|---------|---------------|---------|
| CalTerm_Table_Storage | 0x6000-0x7FFF | e2m parameters (0x0006xxxx) |
| CalTerm_Parameters_A | 0x40000-0xFFFFF | More calibration |
| CalTerm_Parameters_B | 0x100000-0xFFFFFF | Extended calibration |
| External_RAM (our dump) | 0x800000+ | Working memory |

---

## Service 0x4A Address Validation Table

**Discovery:** The firmware validates memory read requests against a table at address 0x2B512.
This table defines which memory regions can be read via diagnostic Service 0x4A.

### Validation Table Structure (at firmware 0x2B512)

Each entry is 10 bytes: `[StartAddr:4][EndAddr:4][Flags:2]`

| Entry | Start | End | Flags | Region | Size | Status |
|-------|-------|-----|-------|--------|------|--------|
| 0 | 0x00000000 | 0x0003FFFF | 0x0404 | **Flash/ROM** | 256KB | READABLE |
| 1 | 0x00800000 | 0x008091C2 | 0x0303 | RAM (dumped) | 37KB | READABLE |
| 2 | 0x008091C2 | 0x0080FFFF | 0x0000 | **Extended RAM** | 28KB | READABLE |
| 3 | 0x01000000 | 0x01000FFF | 0x0505 | **EEPROM** | 4KB | READABLE |
| 4 | 0x00FFC800 | 0x00FFFFFF | 0x030A | High Memory | 14KB | BLOCKED (normal)

### Flag Interpretation (VERIFIED via decompilation)

The table has TWO flag bytes per entry:
- Byte 8: Used when `water_in_fuel_detection_flag == 1` (special mode)
- Byte 9: Used in normal operation

Return values that BLOCK access (from `diagMemoryReadResponseBuilder`):
- 0x09 = Invalid range (not in table)
- 0x0A = Access denied

| Entry | Start | End | Flag1 (special) | Flag2 (normal) | Result |
|-------|-------|-----|-----------------|----------------|--------|
| 0 | 0x00000000 | 0x0003FFFF | 0x04 | 0x04 | READABLE (both modes) |
| 1 | 0x00800000 | 0x008091C2 | 0x03 | 0x03 | READABLE (both modes) |
| 2 | 0x008091C2 | 0x0080FFFF | 0x00 | 0x00 | READABLE (both modes) |
| 3 | 0x01000000 | 0x01000FFF | 0x05 | 0x05 | READABLE (both modes) |
| 4 | 0x00FFC800 | 0x00FFFFFF | 0x03 | **0x0A** | BLOCKED in normal mode |

### Memory Regions Available for Dump

1. **EEPROM (0x01000000-0x01000FFF, 4KB)** ✅
   - Contains persistent calibration settings
   - "Available offline" parameters stored here
   - Can be read without engine running

2. **Flash/ROM (0x00000000-0x0003FFFF, 256KB)** ✅
   - Contains firmware code and factory defaults
   - Factory linearization tables at 0x37EAE
   - Should match our J90280.05.full.bin file

3. **Extended RAM (0x008091C2-0x0080FFFF, 28KB)** ✅
   - Flags 0x00 means ALLOWED (not 0x09 or 0x0A)
   - Additional working memory beyond our current dump

4. **High Memory (0x00FFC800-0x00FFFFFF, 14KB)** ⚠️
   - BLOCKED in normal mode (flag 0x0A)
   - Only accessible when `water_in_fuel_detection_flag == 1`
   - May require special diagnostic mode to access

### Key Functions

- `addressRangeValidator` @ 0x2B4E0 - Validates addresses against this table
- `diagMemoryReadService4aHandler` @ 0x1C02E - Service 0x4A handler
- `diagMemoryReadResponseBuilder` @ 0x1C0B8 - Builds memory read response

---

## Related Tasks

- Task 003: CLIP Protocol - Source of RAM dump capability
- Task 005: Parameter lookup system documentation
- Task 004: E2M address validation
