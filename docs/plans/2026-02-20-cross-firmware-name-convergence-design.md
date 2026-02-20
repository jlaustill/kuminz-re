# Design: Cross-Firmware Name Convergence (CM550 ↔ CM848D)

## Problem

The CM550 (J90280.05, MC68336, 789 functions) and CM848D (S90140.06, PowerPC MPC555, 2,196 functions) share the same Cummins codebase compiled for different architectures and engine configurations (VP44 vs HPCR). Both firmwares have been independently reverse-engineered with high naming coverage, but equivalent functions, variables, structs, and enums often have different names — making side-by-side comparison of the decompiled `.cpp` output impractical.

## Goal

Update the existing CSVs in both firmware analysis directories so that equivalent symbols share the same name. After re-exporting through Ghidra, `J90280.05.ghidra.cpp` and `cm848_rom.ghidra.cpp` read like different versions of the same codebase, diffable with standard tools.

## Current State

### Named Symbol Counts

| Category | CM550 (J90280.05) | CM848D (S90140.06) |
|----------|-------------------|---------------------|
| Functions | 789 | 2,196 |
| Global variables | 6,131 | 4,701 |
| Structs | 35+ shared names | 35+ shared names |
| Enums | 56 shared names | 56 shared names |

### Existing Cross-Firmware Overlap

| Signal | Count | Notes |
|--------|-------|-------|
| Exact function name matches | 14 | `byteSwap32`, `lookupTableInterpolation`, `exponentialMovingAverage`, `main_loop`, etc. |
| Shared variable names | 19 | `current_engine_rpm`, `governor_mode_state`, `fuel_demand_limited`, etc. |
| Shared struct type names | 35 | `j1939_header_t`, `sensor_debounce_state_t`, `fault_status_registers_t`, etc. |
| Shared enum type names | 56 | `DIAG_SERVICE_ID`, `ENGINE_OPERATING_MODE`, `J1939_PGN_LOWER`, etc. |
| Cummins internal parameter codes | 2,227 | TIFSRT, CTIVSWSS, ADBSPR*, etc. — shared namespace across ECU generations |

### What Doesn't Exist Yet

- No cross-architecture relocation map (existing `relocation_map.csv` only covers CM550 → CM550)
- `feature_comparison.csv` has no CM848D column
- The 14 shared function names and 56 shared enum names were incidental, not from a deliberate convergence effort

## Approach

### Why Decompiled C Comparison Works

Binary matching fails across 68K ↔ PowerPC. But at the decompiled C level, equivalent functions share:
- **Magic number fingerprints** — Cummins-specific scaling constants like `0x2136`, `0x39c2c3`, PGN IDs
- **Algorithm structure** — same control flow, same number of branches, same loop patterns
- **Shared callees** — if both functions call `proportionalCalculation()` and `sendCanMessage()`, they're likely the same
- **Cummins parameter codes** — the TIFSRT/CTIVSWSS/ADBSPR namespace spans ECU generations

### Agent Dispatch by Subsystem

Use the proven agent dispatch pattern (same as the Bank 2 naming campaign and DAT_0040xxxx variable naming campaign). Each agent reads the relevant sections of both decompiled `.cpp` files, identifies matching functions/variables, and outputs CSV update lines.

**Split by subsystem (8 agents):**

| # | Subsystem | What to Match |
|---|-----------|---------------|
| 1 | J1939 message dispatch + PGN handlers | PGN builder/handler functions, message buffers, priority variables |
| 2 | Sensor channel init + processing | sensorChannel* functions, ADC config, debounce state |
| 3 | Fuel demand / governor / speed control | Governor state machine, fuel arbitration, torque limits |
| 4 | Fault/DTC handling + diagnostics | Diagnostic state machine, fault tables, DM1-DM11 |
| 5 | Engine protection + derate | Derate functions, protection limits, shutdown logic |
| 6 | EEPROM / calibration access | Data plate, parameter lookup, EEPROM read/write |
| 7 | Timer/scheduler + I/O control | Task scheduler, hardware I/O, TPU/ADC config |
| 8 | Math utilities + shared helpers | Table interpolation, byte swap, fixed-point math, CRC |

### Per Agent Workflow

1. Read the subsystem's functions from both `.cpp` files (agent receives relevant line ranges or function lists)
2. Match functions by shared constants, algorithm structure, and shared callee names
3. For each match, pick the best name — whichever is more descriptive, regardless of which firmware it came from
4. Output CSV-formatted updates for both firmwares: `address,new_name`
5. Flag functions unique to one firmware with a reason: `VP44-only`, `HPCR-only`, `architecture-specific`, `ifdef-excluded`

### After Agent Dispatch

1. Review agent output for conflicts and quality
2. Apply CSV updates to both firmware directories
3. Run `./analyze.sh import && ./analyze.sh export` on both firmwares
4. Diff the `.cpp` outputs to verify convergence
5. Update `feature_comparison.csv` with CM848D column
6. Propagate changes to J90350.00 via its existing bootstrap mechanism

### Naming Conflict Resolution

When equivalent functions have different names:

- **Best name wins** — pick whichever name is more descriptive and accurate, update the other firmware's CSV to match
- **Decimal in names** — per project convention, use decimal not hex in names
- **Verb-first camelCase** — the CM848D's convention (`processX`, `calculateX`, `initX`) is generally more consistent than CM550's mixed style; prefer it when names are equally descriptive
- **Architecture-specific suffixes** — do NOT add suffixes like `_68k` or `_ppc`; the names should be identical

### What NOT to Change

- Functions that genuinely don't exist in the other firmware keep their current names
- VP44-specific functions (e.g., `vp44CanMessageDispatcher`) stay as-is — they have no CM848D equivalent
- HPCR-specific functions (e.g., `calculateRailPressureTarget`) stay as-is — they have no CM550 equivalent
- Architecture-specific low-level functions (interrupt handlers, register setup) stay as-is

## CSV Files Updated

Both firmwares use the same CSV structure. Updates touch:

| CSV File | What Changes |
|----------|-------------|
| `function_renames.csv` | Function names aligned across firmwares |
| `global_variables.csv` | Variable names + types aligned |
| `structure_definitions.csv` | Struct names and field names aligned |
| `enums.csv` | Enum type names and member names aligned |

**No new CSV files or formats are introduced.**

## Success Criteria

1. Equivalent functions share the same name in both firmwares' `.cpp` output
2. Equivalent global variables share the same name and type
3. Shared structs and enums use identical definitions
4. `feature_comparison.csv` has a CM848D column documenting feature presence
5. VP44-only and HPCR-only code is clearly identifiable by name (no false equivalences)
6. The two `.cpp` files can be meaningfully diffed to show how the codebase evolved

## Expected Outcomes

| Category | Expected Matches | Expected Unique |
|----------|-----------------|-----------------|
| CM550 functions (789 total) | ~400-500 mapped to CM848D | ~200-300 VP44-only or architecture-specific |
| CM848D functions (2,196 total) | ~400-500 mapped to CM550 | ~1,700 HPCR-specific, Bank 2, or new features |
| Shared variables | 100+ converged names | Thousands unique per firmware (different RAM layouts) |
| Shared structs | 35+ already shared, expand where possible | Architecture-specific structs stay separate |

## Risks

- **False matches** — Two functions may share constants or structure coincidentally. Agent output must be reviewed before applying.
- **Ghidra decompiler differences** — 68K and PowerPC decompilers may produce structurally different C for the same algorithm. Agents need to look past superficial differences.
- **Scale of CM848D** — At 2,196 functions, CM848D has ~1,400 functions with no CM550 equivalent. Agents should not waste time trying to force matches for HPCR-specific code.

## Relation to Existing Work

- **J90350.00 bootstrap**: J90350.00 was bootstrapped from J90280.05 using `relocation_map.csv`. Name changes to J90280.05 can propagate to J90350.00 via `./analyze.sh bootstrap`.
- **Bank 2 naming campaign (2026-02-05)**: Named 361 of 362 Bank 2 functions. These are CM848D-only (utility functions in flash bank 2) and won't have CM550 equivalents.
- **DAT_0040xxxx variable naming (2026-02-18)**: Named 2,829 CM848D RAM variables. Many of these may find CM550 equivalents in this campaign.
- **Internal parameter codes**: The 2,227 Cummins codes from `internal_names.csv` serve as a cross-generation Rosetta Stone — same codes appear in both CM550 e2m (`common_parameters.json`) and CM848D e2m files.
