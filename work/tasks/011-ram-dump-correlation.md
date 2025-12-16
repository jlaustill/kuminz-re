# Task 011: RAM Dump Correlation for Firmware Analysis

## Status: Todo
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
2. [ ] Verify/correct 5+ global variable definitions
3. [ ] Document diagnostic buffer structure completely
4. [ ] Map calibration table format to e2m parameters
5. [ ] Create comprehensive RAM memory map

---

## Strategy 1: Xref Analysis of Known RAM Addresses

Use Ghidra MCP tools (READ-ONLY) to find firmware code that accesses RAM regions:

| RAM Address | Content Found | MCP Query |
|-------------|---------------|-----------|
| 0x800B00 | Diagnostic buffer (our requests) | `get_xrefs_to 0x800B00` |
| 0x8072F4 | RPM breakpoint table | `get_xrefs_to 0x8072F4` |
| 0x807176 | Load breakpoint table | `get_xrefs_to 0x807176` |
| 0x803B00 | ECU identity block | `get_xrefs_to 0x803B00` |
| 0x8002E0 | Timer array (all=10000) | `get_xrefs_to 0x8002E0` |

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

### Phase 2: Ghidra Xref Queries (MCP Tools - READ ONLY)
- [ ] Query xrefs to frequently-referenced addresses
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

---

## Related Tasks

- Task 003: kuminz-ui CLIP implementation (provides RAM dump capability)
- Task 005: Parameter lookup system documentation
- Task 004: E2M address validation against firmware
