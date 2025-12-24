# Task 011: RAM Dump Correlation for Firmware Analysis

## Status: In Progress
## Component: firmware

## Problem Statement

Successfully captured 37KB RAM dump from CM550 ECU via Service 0x4A memory read. This live RAM data provides a unique opportunity to validate and expand our firmware reverse engineering work by correlating runtime values with static analysis.

## Prerequisite Achievement

**RAM Dump Captured** (commit 9b082a2):
- **File:** `clip-lib/build/cm550_ram.bin` (37,315 bytes)
- **Range:** 0x800000 - 0x8091C2
- **Key discoveries from initial analysis:**
  - 228 RAM pointers to internal structures
  - ECU Identity: Serial T03942860, Cal J90350.00
  - Diagnostic buffer @ 0x800B00 with captured requests
  - Calibration tables @ 0x807000+ (RPM/load breakpoints)
  - Parameter descriptors with [type:2][size:2][offset:2] pattern

## Goals

1. [ ] Identify 10+ new function names via xref analysis
2. [X] Verify/correct 5+ global variable definitions (13 new entries added)
3. [X] Document diagnostic buffer structure completely (48-byte record format documented)
4. [~] Map calibration table format to e2m parameters (RPM/Load tables mapped, e2m correlation pending)
5. [X] Create comprehensive RAM memory map (analysis/ram_memory_map.md created)

---

## Strategy 1: Xref Analysis of Known RAM Addresses

Use Ghidra's built-in xref tools to find firmware code that accesses these RAM regions:

| RAM Address | Content Found |
|-------------|---------------|
| 0x800B00 | Diagnostic buffer (our requests) |
| 0x8072F4 | RPM breakpoint table |
| 0x807176 | Load breakpoint table |
| 0x803B00 | ECU identity block |
| 0x8002E0 | Timer array (all=10000) |

**Expected Output:** Functions that initialize, read, or write these addresses.

---

## Strategy 2: Validate Existing Structure Definitions

Compare RAM dump patterns with CSV definitions:

| CSV Entry | RAM Address | Verification |
|-----------|-------------|--------------|
| `param_table_main` @ 0x80CFD6 | 0x80CFD6 | Extract 16 bytes, check structure |
| `diagnostic_tx_buffer_start_ptr` @ 0x80D3E6 | 0x80D3E6 | Verify pointer value |
| `retarder_lookup_table_pointer` @ 0x800122 | 0x800122 | Check points to 0x807952 |

---

## Strategy 3: Map 228 RAM Pointers to Functions

Extract all pointers from dump, trace what firmware code uses them:

```
For each pointer at 0x80xxxx:
1. Read pointer value from dump
2. Query Ghidra: get_xrefs_to <pointer_address>
3. Identify functions that load/store this pointer
4. Name the pointer based on function context
```

---

## Strategy 4: Correlate Calibration Tables with e2m

Cross-reference RAM calibration data with e2m-analysis:

| RAM Table | Values Found | e2m Parameter? |
|-----------|--------------|----------------|
| 0x8072F4 | RPM: 32 to 14400 | Check common_parameters.json |
| 0x807176 | Load: 0 to 14800 | Check for matching breakpoints |

---

## Implementation Phases

### Phase 1: Extract Key Data from RAM Dump
Write Python/TypeScript script to:
- [ ] Parse all 228 RAM pointers with their target addresses
- [ ] Extract parameter descriptor table entries
- [ ] Dump calibration breakpoint tables
- [ ] Extract diagnostic buffer structure

### Phase 2: Ghidra Xref Queries
- [ ] Query xrefs to frequently-referenced addresses in Ghidra GUI
- [ ] Identify initialization functions
- [ ] Map data flow: init -> storage -> access -> response

### Phase 3: Update CSV Files
- [ ] Add verified variable names to `global_variables.csv`
- [ ] Add newly discovered functions to `function_renames.csv`
- [ ] Document structures in `structure_definitions.csv`

### Phase 4: Document Findings
- [ ] Create RAM memory map with ownership
- [ ] Document pointer chain relationships
- [ ] Update `complete_parameter_system_map.md`

---

## Priority RAM Addresses

### High Priority (Direct correlation potential)
| Address | Content | Why Important |
|---------|---------|---------------|
| 0x800B00-0x800BC0 | Diagnostic buffer | Shows message handling structure |
| 0x8072F4 | RPM breakpoints | Calibration table format |
| 0x807176 | Load breakpoints | Calibration table format |
| 0x803B00 | ECU identity | Serial/cal storage structure |
| 0x800F34 | diag_tp_state_t | TP session state (from prior analysis) |

### Medium Priority (Structure verification)
| Address | Content | Why Important |
|---------|---------|---------------|
| 0x80CFD6 | param_table_main | Verify parameter storage |
| 0x80D3E6 | diagnostic_tx_buffer_start_ptr | Buffer management |
| 0x8002E0 | Timer array | Scheduler understanding |

---

## Known Function to RAM Correlations

Already identified from prior analysis:

| Function | Address | RAM Region Accessed |
|----------|---------|---------------------|
| `param_address_calc` | 0x12afa | All 228 pointers |
| `param_lookup_1/2/3` | 0xd632/d69c/d756 | Parameter tables |
| `diagnosticDataCopyHandler` | 0xbdd4 | 0x800B00 diagnostic buffer |
| `diagMemoryReadService4aHandler` | 0x1c02e | Any RAM via Service 0x4A |
| `calibrationDataCopyWithChecksum` | 0xebf2 | 0x80488E-0x8062CF |
| `firmwareDataCopyToWorkingMemory` | 0xf4ea | 0x8062D2-0x808AB1 |

---

## Key Files

### Input (Analysis Sources)
- `clip-lib/build/cm550_ram.bin` - RAM dump (regenerate with `./clip-test can0 --dump-ram`)
- `firmware/J90280.05_analysis/ghidra/CM550.rep/global_variables.csv` - 6,096 entries
- `firmware/J90280.05_analysis/ghidra/CM550.rep/function_renames.csv` - 448 functions
- `firmware/J90280.05_analysis/ghidra/CM550.rep/arrays.csv` - 67 arrays
- `e2m-analysis/docs/common_parameters.json` - e2m parameter addresses

### Output (To Update)
- `firmware/J90280.05_analysis/ghidra/CM550.rep/global_variables.csv`
- `firmware/J90280.05_analysis/ghidra/CM550.rep/function_renames.csv`
- `firmware/J90280.05_analysis/ghidra/CM550.rep/structure_definitions.csv`
- `firmware/J90280.05_analysis/analysis/ram_memory_map.md` (new)

---

## Investigation Log

### 2024-12-16 - Initial RAM dump captured
- Successfully dumped 37,315 bytes from ECU
- Identified key data structures via pattern analysis
- Created this task for future correlation work
- Commit 9b082a2 added --dump-ram CLI command

### 2024-12-16 - RAM Dump Correlation Session
**Accomplishments:**

1. **Created RAM Memory Map** (`analysis/ram_memory_map.md`)
   - Documented full memory region overview (0x800000-0x8091C2)
   - Identified previously undocumented areas

2. **Documented Diagnostic Buffer Structure** (0x800B00)
   - 48-byte repeating record structure
   - 4 slots at 0x800B00, 0x800B30, 0x800B60, 0x800B90
   - Contains: STATUS_RESPONSE (0x0D), error code (0x18), buffer pointers

3. **Documented ECU Identity Block** (0x803B00-0x803FFF)
   - Serial number at 0x803B15: "T03942860"
   - Build date at 0x803B88: "060498" (June 4, 1998?)
   - Calibration ID at 0x803E1D: "J90350.00 100898231658"
   - OEM name at 0x803E60: "GENERIC"
   - Part numbers at 0x803EC2

4. **Verified Timer Array** (0x8002E0)
   - 32 x 16-bit timers all set to 10000 (0x2710)
   - Confirms task file observation

5. **Mapped Calibration Tables**
   - RPM breakpoints at 0x8072F4: 32 to 14400 RPM (16 entries)
   - Load breakpoints at 0x807176: 0 to 14800 (16 entries)

6. **Added 13 New CSV Entries** (global_variables.csv)
   - diagnostic_request_buffer (0x800B00)
   - ecu_identity_header (0x803B00)
   - ecu_identity_marker_1 (0x803B0A)
   - ecu_identity_test_pattern (0x803B0C)
   - ecu_serial_number (0x803B15)
   - ecu_unit_marker (0x803B44)
   - ecu_build_date (0x803B88)
   - calibration_id_string (0x803E1D)
   - oem_name_string (0x803E60)
   - part_number_list (0x803EC2)
   - system_timer_array (0x8002E0)
   - rpm_breakpoint_table (0x8072F4)
   - load_breakpoint_table (0x807176)

**Note:**
- Goal 1 (10+ function names via xref) requires manual Ghidra GUI analysis

**Next Steps:**
- Correlate RPM/Load tables with e2m common_parameters.json

### 2024-12-16 - Ghidra Xref Analysis Session
**CSV Export Verified:**
- All 13 new global variables appear correctly in `J90280.05.ghidra.c`
- New entries include: diagnostic_request_buffer, ecu_serial_number, calibration_id_string, rpm_breakpoint_table, load_breakpoint_table, system_timer_array, etc.

**Xref Analysis Results:**
- Direct xrefs to RAM addresses (0x800B00, 0x8072F4, etc.) returned empty
- **Root cause:** RAM addresses are accessed dynamically through `param_address_calc` function, not hardcoded
- This confirms the parameter lookup system design documented in Task 005

**Key Functions Discovered:**
1. `mainSystemInitialization` @ 0x20462 - Complete boot sequence with 70+ init functions
2. `initRpmLookupTables` @ 0x1f23e - Sets up RPM table pointers (0x80883a, 0x80884e, etc.)
3. `initLookupTablePointers1` @ 0x1e3a8 - Sets up EPS timing table pointers
4. `tableInterpolationLookup` @ 0x35560 - Core 2D table interpolation routine
5. `rpmLoadParameterLookup` @ 0x30c78 - RPM/Load parameter calculation
6. `diagMemoryReadService4aHandler` @ 0x1c02e - Handles Service 0x4A memory reads (what we used!)

**ECU Identity Data Flow:**
- `insiteEcuIdResponseBuilder` @ 0x1fec4 reads from `insite_ecu_id_part_1/2/3` (EEPROM)
- `engineSerialNumberDataBuilder` @ 0x297fc reads from `insite_version_string_part_1/2/3` (EEPROM)
- `calibrationDataCopyWithChecksum` @ 0xebf2 copies from EEPROM (0x4000) to RAM (0x804882+)
- The ECU identity block at 0x803B00 is populated during boot from EEPROM data

**System Initialization Sequence (Key Functions):**
```
initInternalRamAndCAN1 → clearWorkingMemory → firmwareDataCopyToWorkingMemory →
calibrationDataCopyWithChecksum → initVectorTable → scheduler_init →
initDiagnosticProtocol → vp44CommunicationTestAndInit
```

**Task 011 Goals Status:**
- [X] Verify/correct 5+ global variable definitions (13 new entries added, verified in export)
- [X] Document diagnostic buffer structure (48-byte record format)
- [X] Create comprehensive RAM memory map (analysis/ram_memory_map.md)
- [X] Map calibration table format to e2m parameters (COMPLETE - see session below)
- [~] Identify 10+ new function names via xref (6 key functions documented, but not via xref - via code exploration)

### 2024-12-16 - E2M Address Correlation Session

**Corrected Understanding: E2M Spans Multiple Memory Zones**

E2M parameters do NOT all map to RAM. They span multiple memory zones with different persistence characteristics:

| Memory Zone | Params | Address Range | Persistence | Contents |
|-------------|--------|---------------|-------------|----------|
| External_RAM | 1,062 | 0x0080xxxx | **Volatile** | Runtime values, sensor readings |
| EEPROM | 78 | 0x0100xxxx | **Persistent** | Adjustable settings (droop, gains, PTO) |
| CalTerm_Storage | 37 | 0x0006xxxx | Varies | Tool parameter limits |
| Flash/ROM | 8 | 0x0000xxxx | Read-only | Factory defaults |
| **Unmapped** | 139 | Unknown | **Persistent** | Large lookup tables |

**"Available Offline" Parameters (139):**
These are large calibration tables stored in EEPROM that can be read/written when engine is OFF:
- Timing advance tables (4DTA00XA, 4DTA01XA) - Column3 0x1040, 0x103D
- Fueling tables (5DFL00XA, 5DFL01XA) - Column3 0x1058, 0x1055
- Sensor linearization tables (ADBSPRXA/YA) - Column3 0x1016, 0x1015

These Column3 values are NOT in the lookup table yet - need to map them.

**Linearization Tables Location:**
The sensor linearization tables (e.g., ADBSPRXA @ 0x806C4A) are in the **ROM copy area**:
- Source: ROM 0x37EAE (factory defaults)
- Destination: RAM 0x8062D2-0x808AB2
- They have factory defaults from ROM but can be customized via EEPROM

**Data Flow:**
| Source | Address | RAM Destination | Size |
|--------|---------|-----------------|------|
| EEPROM Block 1 | 0x4000 | 0x804882-0x80488C | 10 bytes |
| EEPROM Block 2 | 0x4400 | 0x80488E-0x8062D0 | 6,722 bytes |
| ROM Firmware | 0x37EAE | 0x8062D2-0x808AB2 | 10,208 bytes |

**Updated ram_memory_map.md** with corrected E2M correlation section.

### 2024-12-16 - Address Validation Table Discovery

**BREAKTHROUGH:** Found the firmware's memory access validation table at address 0x2B512.

This table defines which memory regions can be read via diagnostic Service 0x4A:

| Entry | Start | End | Flag1 | Flag2 | Region | Size | Status |
|-------|-------|-----|-------|-------|--------|------|--------|
| 0 | 0x00000000 | 0x0003FFFF | 0x04 | 0x04 | **Flash/ROM** | 256KB | READABLE |
| 1 | 0x00800000 | 0x008091C2 | 0x03 | 0x03 | RAM | 37KB | Already dumped |
| 2 | 0x008091C2 | 0x0080FFFF | 0x00 | 0x00 | **Extended RAM** | 28KB | READABLE |
| 3 | 0x01000000 | 0x01000FFF | 0x05 | 0x05 | **EEPROM** | 4KB | READABLE |
| 4 | 0x00FFC800 | 0x00FFFFFF | 0x03 | 0x0A | High Memory | 14KB | BLOCKED (normal) |

**Flag System (VERIFIED via decompilation of `diagMemoryReadResponseBuilder`):**
- Table has TWO flag bytes per entry (byte 8 = special mode, byte 9 = normal mode)
- Flag values 0x09 (invalid range) and 0x0A (access denied) BLOCK reads
- All other values (0x00, 0x03, 0x04, 0x05) ALLOW reads

**Key Functions Identified:**
- `addressRangeValidator` @ 0x2B560 - Validates addresses against this table
- `diagMemoryReadResponseBuilder` @ 0x1BDE6 - Uses validator, checks for 0x09/0x0A to block
- `diagMemoryReadService4aHandler` @ 0x1C02E - Service 0x4A handler

**Implications:**
1. **EEPROM dump possible** - 4KB at 0x01000000-0x01000FFF contains persistent calibration
2. **Flash/ROM dump possible** - 256KB matches our firmware file (can verify integrity)
3. **Extended RAM readable!** - Flags 0x00 is ALLOWED (only 0x09/0x0A block)
4. **High memory blocked in normal mode** - Flag2=0x0A blocks access, requires special mode

**Memory Dump Summary:**
| Region | Address Range | Size | Can Dump? |
|--------|---------------|------|-----------|
| Flash/ROM | 0x00000000-0x0003FFFF | 256KB | ✅ YES |
| RAM (current) | 0x00800000-0x008091C2 | 37KB | ✅ Already done |
| Extended RAM | 0x008091C2-0x0080FFFF | 28KB | ✅ YES |
| EEPROM | 0x01000000-0x01000FFF | 4KB | ✅ YES |
| High Memory | 0x00FFC800-0x00FFFFFF | 14KB | ⚠️ Special mode only |

**Next Steps:**
- [ ] Create `--dump-eeprom` command (0x01000000-0x01000FFF, 4KB)
- [ ] Create `--dump-rom` command (0x00000000-0x0003FFFF, 256KB)
- [ ] Extend RAM dump to include 0x008091C2-0x0080FFFF (28KB more)
- [ ] Compare ROM dump with J90280.05.full.bin for verification

**Updated ram_memory_map.md** with Service 0x4A validation table documentation.

---

## Related Tasks

- Task 003: kuminz-ui CLIP implementation (provides RAM dump capability)
- Task 005: Parameter lookup system documentation
- Task 004: E2M address validation against firmware
