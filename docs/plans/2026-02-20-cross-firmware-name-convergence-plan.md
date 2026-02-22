# Cross-Firmware Name Convergence Implementation Plan

> **For Claude:** REQUIRED SUB-SKILL: Use superpowers:executing-plans to implement this plan task-by-task.

**Goal:** Align symbol names (functions, variables, structs, enums) between CM550 (J90280.05) and CM848D (S90140.06) so their decompiled .cpp outputs can be compared side-by-side.

**Architecture:** Agent dispatch by subsystem — each agent reads both decompiled .cpp files, identifies matching functions by algorithm structure and shared constants, then outputs CSV update lines for both firmwares. Updates are applied through the existing `analyze.sh import && export` workflow. No new tooling or file formats.

**Tech Stack:** Ghidra CSV workflow (bash), Claude agent dispatch (haiku model)

---

## Prerequisites

- Both firmware Ghidra projects are current (last export includes all recent naming campaigns)
- Decompiled output files exist:
  - `firmware/CM550_J90280.05_analysis/output/J90280.05.ghidra.cpp` (~789 functions)
  - `firmware/CM848_S90140.06_analysis/output/cm848_rom.ghidra.cpp` (~2,196 functions)
- Both `function_renames.csv` and `global_variables.csv` are current

## Subsystem Inventory

| # | Subsystem | CM550 Functions | CM848D Functions | Match Potential |
|---|-----------|----------------|-----------------|-----------------|
| 8 | Math utilities + shared helpers | 16 | ~55 | Highest — algorithmic fingerprints |
| 1 | J1939 message dispatch + PGN handlers | 38 | 75 | High — PGN IDs are shared constants |
| 3 | Fuel demand / governor / speed control | ~89 | ~110 | High — largest CM550 subsystem |
| 4 | Fault/DTC handling + diagnostics | ~78 | ~115 | High — DM message formats shared |
| 5 | Engine protection + derate | ~53 | ~90 | Medium — architecture differs (selector-tree vs state-machine) |
| 2 | Sensor channel init + processing | 11 | 68 | Medium — different HAL (QADC vs channel pairs) |
| 6 | EEPROM / calibration access | 11 | 40 | Medium — different write paths |
| 7 | Timer/scheduler + I/O control | 42 | ~185 | Low — hardware is fundamentally different (MC68336 TPU vs MPC555 MIOS) |

---

## Round 1: Anchor Subsystems (Parallel)

These subsystems establish the shared function names that later subsystems reference. Run both agents in parallel.

### Task 1: Math Utilities + Shared Helpers (Subsystem 8)

**Files:**
- Read: `firmware/CM550_J90280.05_analysis/output/J90280.05.ghidra.cpp`
- Read: `firmware/CM848_S90140.06_analysis/output/cm848_rom.ghidra.cpp`
- Modify: `firmware/CM550_J90280.05_analysis/output/function_renames.csv`
- Modify: `firmware/CM848_S90140.06_analysis/output/function_renames.csv`

**Agent context:**

The 14 exact name matches are the anchors: `byteSwap16`, `byteSwap32`, `exponentialMovingAverage`, `lookupTableInterpolation`, `main_loop`. The agent should start from these and expand outward to match remaining math/utility functions.

Known CM550 math functions to find CM848D equivalents for:
- `proportionalCalculation` (0x000357d2) — used everywhere, likely exists in CM848D
- `safeDivideWithClamp` (0x00012966) — compare against `clampedDivisionWithBounds` (0x000562fc)
- `signedLinearInterpolation` (0x0003566e) — compare against `linearInterpolate1D` (0x00055f24)
- `unsignedLinearInterpolation` (0x0003574e)
- `coreTableInterpolation` (0x000356f8) — internal helper called by `lookupTableInterpolation`
- `minimumOfTwoValues` (0x0002d748)
- `clampedDivisionCalculator` (0x00012a26)
- `param_interpolate` (0x0000d8b4) — compare against CM848D Bank 2 interpolation functions

Agent should compare function bodies for shared magic numbers and identical algorithmic patterns. Output: CSV lines with `address,name` for both firmwares, choosing the best name for each pair.

**Step 1: Dispatch agent**

Agent reads both .cpp files focusing on math/utility functions (CM550 addresses 0x000128xx-0x00012bxx, 0x000354xx-0x000358xx, 0x0002d748; CM848D addresses 0x00055exx-0x000571xx, 0x0050b2xx, 0x005185xx-0x005187xx). Proposes name alignment as CSV lines.

**Step 2: Review agent output**

Check for false matches — math functions with similar structure but different purposes. Verify constant fingerprints actually match.

**Step 3: Apply CSV updates**

Append/modify lines in both `function_renames.csv` files.

**Step 4: Commit**

```bash
git add firmware/CM550_J90280.05_analysis/output/function_renames.csv firmware/CM848_S90140.06_analysis/output/function_renames.csv
git commit -m "firmware: Align math utility function names between CM550 and CM848D"
```

### Task 2: J1939 Message Dispatch + PGN Handlers (Subsystem 1)

**Files:**
- Read: both `.ghidra.cpp` files
- Modify: both `function_renames.csv` files

**Agent context:**

PGN IDs are the matching key — both firmwares handle the same set of standard J1939 PGNs. The agent should match by PGN number in function name or by PGN constant in function body.

Known PGN handler pairs to verify and align names:

| PGN | CM550 Name | CM848D Name | Notes |
|-----|-----------|-------------|-------|
| 65226 (DM1) | `engineCoolantPGN_65226_Builder` | `j1939_handle_pgn_65226_dm1_active_dtc` | Different naming conventions |
| 65227 (DM2) | `diagnosticDM2PGN_65227_Builder` | `j1939_handle_pgn_65227_dm2_previous_dtc` | |
| 65229 (DM4) | `diagnosticDM4PGN_65229_Builder` | `j1939_handle_pgn_65229_dm4_freeze_frame` | |
| 65230 (DM5) | `diagnosticDM5PGN_65230_Builder` | `j1939_handle_pgn_65230_dm5_readiness` | |
| 65234 (DM11) | `diagnosticDM11PGN_65234_Builder` | `j1939_handle_pgn_65234_dm11_clear_active` | |
| 65248 | `vehicleDistancePGN_65248_Builder` | `j1939_handle_pgn_65248_vehicle_distance` | |
| 65259 | `engineSerialNumberPGN_65259_Builder` | `j1939_handle_pgn_65259_component_id` | |
| 65262 | `engineTemperaturePGN_65262_Builder` | `j1939_handle_pgn_65262_engine_temp` | |
| 65263 | `engineFluidLevelPGN_65263_Builder` | `j1939_handle_pgn_65263_fluid_level_pressure` | |
| 65265 | `j1939MessageSetup_PGN_65265` | `j1939_handle_pgn_65265_cruise_vehicle_speed` | |
| 65269 | `ambientConditionsPGN_65269_Builder` | `j1939_handle_pgn_65269_ambient_conditions` | |
| 65270 | `intakeExhaustConditionsPGN_65257_Builder` | `j1939_handle_pgn_65270_inlet_exhaust_conditions` | PGN number differs in CM550 name? |

The agent needs to decide on a consistent naming convention for PGN handlers. The CM848D's `j1939_handle_pgn_NNNNN_description` pattern is more systematic. But the CM550's `descriptionPGN_NNNNN_Builder` pattern is also well-established. Pick whichever is more descriptive.

Also match the supporting infrastructure: CAN message send/receive functions, transport protocol handlers, message buffer setup.

CM550 PGNs with NO CM848D equivalent (mark as VP44-only):
- `fuelEconomyPGN_65266_Builder` — excluded via ifdef in CM848D
- `engineHoursPGN_65252_Builder` — excluded
- `vehicleHoursPGN_65255_Builder` — excluded
- `ioControlPGN_65244_Builder` — excluded
- `diagnosticDM8PGN_65232_Builder` — excluded
- `electronicBrakePGN_65527_Builder` — excluded
- `intakeManifoldPGN_65526_Builder` — excluded (Cummins proprietary range)
- `retarderConfigPGN_65249_Builder` — excluded
- `vp44Command0x100Builder` — VP44-specific
- `cumminsProprietaryTSC_PGN_15728640_Builder` — check if CM848D has equivalent

**Step 1-4:** Same pattern as Task 1 (dispatch, review, apply, commit).

---

## Round 2: Core Subsystems (Parallel)

These subsystems form the bulk of the engine control logic. Run all three agents in parallel, referencing names established in Round 1.

### Task 3: Fuel Demand / Governor / Speed Control (Subsystem 3)

**Files:**
- Read: both `.ghidra.cpp` files
- Modify: both `function_renames.csv` and `global_variables.csv` files

**Agent context:**

This is the largest CM550 subsystem (~89 functions). Key matching strategy:

1. **Governor functions** — CM550 uses `governorFuelPidController`/`governorPidFuelCalculator` (PID-based). CM848D uses `governorDroopCalculation`/`governorSpeedControl` (droop-based). These may be evolutionary changes to the same function, or genuinely different algorithms. Agent should compare the actual decompiled bodies.

2. **Fuel demand chain** — Both firmwares have `fuelDemandModeSelector` (exact name match). Trace outward from this anchor to match the rest of the fuel demand calculation pipeline.

3. **Fuel limit arbitration** — CM550 has `fuel_limit_arbitrator`, `fuelArbitratorInit`, `fuelArbitratorControlService`. CM848D likely has equivalents. Match by call graph and shared fuel limit constants.

4. **Throttle processing** — `throttlePositionValidator` (CM550) vs `throttlePositionProcessing`/`processThrottlePosition` (CM848D).

5. **VP44-only functions** — any function with `vp44` in the name has no CM848D equivalent. Mark as VP44-only. The CM848D equivalent is HPCR-specific injector code.

Also align global variables: `current_engine_rpm`, `fuel_demand_limited`, `governor_speed_setpoint`, `target_engine_rpm`, `throttle_position_filtered`, `throttle_position_raw` are already shared names — use these as variable alignment anchors and find more.

**Step 1-4:** Same pattern (dispatch, review, apply, commit).

### Task 4: Fault/DTC Handling + Diagnostics (Subsystem 4)

**Files:**
- Read: both `.ghidra.cpp` files
- Modify: both `function_renames.csv` and `global_variables.csv` files

**Agent context:**

1. **DM message builders** — already partially aligned in Task 2 (J1939 PGN handlers). This task focuses on the internal fault processing chain that feeds DM1/DM2/DM4.

2. **Diagnostic state machine** — CM550 has `diagnosticStateMachineProcessor`. CM848D has equivalent fault state processing. Match by state transition constants and fault table access patterns.

3. **Fault code registration** — CM550 has `diagnosticCodeRegistrar`, `diagnosticCodeClearHandler`, `diagnosticCodeDebounceHandler`. CM848D has `addFaultToActiveList`, `clearFaultFromActiveList`, `scanAndProcessActiveFaults`. These are the same operations with different naming conventions — pick the best name.

4. **Insite/diagnostic protocol** — CM550 has 7+ `insite*` functions (the diagnostic tool interface). CM848D's equivalent is the `processCommandQueueStateMachine`/`dispatchByCommandCode` command dispatch. These may be architecturally different enough that name alignment isn't possible — agent should assess.

5. **Diagnostic memory read/write** — CM550 has `diagnosticMemoryReadHandler`/`diagnosticMemoryWriteHandler`. CM848D has these in the CLIP/EF00 service layer. Match by Service ID constants (0x4A, 0x14, 0x15).

**Step 1-4:** Same pattern (dispatch, review, apply, commit).

### Task 5: Engine Protection + Derate (Subsystem 5)

**Files:**
- Read: both `.ghidra.cpp` files
- Modify: both `function_renames.csv` and `global_variables.csv` files

**Agent context:**

1. **Architecture difference** — CM550 uses a selector-tree pattern (`shutdownMinimumSelector15` through `shutdownMinimumSelector29`). CM848D uses a state-machine pattern (`protectionNormalHandler`, `protectionOverloadHandler`, `protectionShutdownHandler`). These are genuinely different architectures for the same protection logic. The agent should identify which functions serve equivalent purposes even if the implementation pattern differs.

2. **Protection threshold calculation** — both firmwares calculate temperature/pressure thresholds and compare against limits. Match by shared protection constants and sensor variable references.

3. **Derate system** — CM550 has `derate_application_controller`, `initDerateSystem`, `derateChangeDetector`. CM848D has equivalent derate functions. Match by the fuel limit values they produce.

4. **Oil pressure protection** — CM550 has `advanced_oil_pressure_protection_system`, `oil_pressure_protection_controller`, `oil_pressure_shutdown_controller`. CM848D likely has equivalents. Match by oil pressure variable references.

**Step 1-4:** Same pattern (dispatch, review, apply, commit).

---

## Round 3: Remaining Subsystems (Parallel)

### Task 6: Sensor Channel Init + Processing (Subsystem 2)

**Files:**
- Read: both `.ghidra.cpp` files
- Modify: both `function_renames.csv` and `global_variables.csv` files

**Agent context:**

CM848D has a well-structured sensor HAL with 17 named `sensorChannelN_init/process` pairs plus aux channels. CM550 has a simpler QADC-based architecture with only 11 sensor functions named.

The agent should:
1. Identify which CM848D sensor channels correspond to CM550 sensor processing (by tracing which physical sensor each channel reads — boost pressure, oil pressure, coolant temp, etc.)
2. Align the higher-level sensor fault detection and blending functions
3. NOT try to force-match the low-level ADC/QADC hardware functions — these are architecture-specific

### Task 7: EEPROM / Calibration Access (Subsystem 6)

**Files:**
- Read: both `.ghidra.cpp` files
- Modify: both `function_renames.csv` and `global_variables.csv` files

**Agent context:**

Small subsystem (11 CM550, 40 CM848D). Focus on:
1. `param_lookup_1/2/3` (CM550) vs `lookupEepromParameterAddress` (CM848D) — the parameter resolution chain
2. EEPROM write paths — different hardware but same logical flow
3. Calibration validation — `calibrationDataValidatorInit` (CM550) vs CM848D equivalents
4. Data plate access — both firmwares read engine serial/calibration from EEPROM

### Task 8: Timer/Scheduler + I/O Control (Subsystem 7)

**Files:**
- Read: both `.ghidra.cpp` files
- Modify: both `function_renames.csv` files

**Agent context:**

Lowest match potential — the hardware is fundamentally different (MC68336 TPU vs MPC555 MIOS). The agent should:
1. Match the scheduler/task dispatch layer (software abstraction above the hardware)
2. Match I/O control state machines (lamp blink patterns, output driver logic)
3. NOT try to match TPU channel functions to MIOS channel functions — hardware-specific
4. Focus on naming consistency for the shared concepts (periodic task scheduling, watchdog timers)

**Steps for Tasks 6-8:** Same pattern as previous rounds (dispatch, review, apply, commit).

---

## Round 4: Verification + Feature Comparison

### Task 9: Re-export Both Firmwares

**Step 1: Import and export CM550**

```bash
cd firmware/CM550_J90280.05_analysis/ghidra
./analyze.sh import
./analyze.sh export
```

**Step 2: Import and export CM848D**

```bash
cd firmware/CM848_S90140.06_analysis/ghidra
./analyze.sh import
./analyze.sh export
```

**Step 3: Verify convergence**

Spot-check that equivalent functions now share names in both .cpp files. Pick 10-15 matched function pairs and verify the names appear identically in both outputs.

**Step 4: Propagate to J90350.00**

```bash
cd firmware/CM550_J90350.00_analysis/ghidra
./analyze.sh bootstrap
./analyze.sh export
```

**Step 5: Commit all exported output**

```bash
git add firmware/CM550_J90280.05_analysis/output/ firmware/CM848_S90140.06_analysis/output/ firmware/CM550_J90350.00_analysis/output/
git commit -m "firmware: Re-export all firmwares after cross-firmware name convergence"
```

### Task 10: Update Feature Comparison

**Files:**
- Modify: `firmware/feature_comparison.csv`

Add CM848D (S90140.06) as a new column. For each feature row, mark `present`, `stub`, `not_found`, or `different` based on the cross-firmware mapping results. Add new rows for CM848D-only features (HPCR injector control, Bank 2 utilities, etc.).

**Step 1:** Review the cross-firmware mapping from Tasks 1-8 to identify which features exist in which firmware.

**Step 2:** Update `feature_comparison.csv` with the CM848D column.

**Step 3: Commit**

```bash
git add firmware/feature_comparison.csv
git commit -m "firmware: Add CM848D column to feature comparison matrix"
```

### Task 11: Update work/todo.md

Mark task 017 as done, update any related tasks.

---

## Agent Dispatch Details

### Agent Input Per Subsystem

Each agent receives:
1. The relevant sections of both .cpp files (by line range or function list)
2. Both `function_renames.csv` files (for current name inventory)
3. The list of already-matched names from previous rounds (for Rounds 2-3)
4. Clear instructions: output CSV lines as `address,proposed_name` for both firmwares

### Agent Output Format

```
# CM550 updates (firmware/CM550_J90280.05_analysis/output/function_renames.csv)
0x0002ada8,fuelEconomyPGN_65266_Builder    # no change (VP44-only, no CM848D match)
0x000357d2,proportionalCalculation         # no change (already matched)
0x0003566e,signedLinearInterpolation       # rename to match CM848D

# CM848D updates (firmware/CM848_S90140.06_analysis/output/function_renames.csv)
0x00055f24,signedLinearInterpolation       # renamed from linearInterpolate1D to match CM550

# No match found (VP44-only):
# CM550 0x0002ada8 fuelEconomyPGN_65266_Builder — excluded via ifdef in CM848D

# No match found (HPCR-only):
# CM848D 0x00012e60 fuelControlMainCalculation — HPCR injector control, no CM550 equivalent
```

### Model Selection

Use **haiku** for cost efficiency — the pattern recognition task (comparing decompiled C function bodies) is well within haiku's capabilities, same as the previous naming campaigns.

### Round Sequencing

Rounds execute sequentially because later subsystems reference names established in earlier rounds:
- **Round 1** (Tasks 1-2): Establishes anchor names (math utilities, J1939 PGN handlers)
- **Round 2** (Tasks 3-5): Core engine control, references Round 1 names
- **Round 3** (Tasks 6-8): Remaining subsystems, references Rounds 1-2 names
- **Round 4** (Tasks 9-11): Verification and documentation

Within each round, agents run in parallel.

---

## Success Criteria

1. Equivalent functions share the same name in both .cpp outputs
2. Equivalent global variables share the same name and type
3. Shared structs and enums use identical definitions where possible
4. `feature_comparison.csv` has a populated CM848D column
5. VP44-only and HPCR-only code is clearly identifiable (no false equivalences forced)
6. The two .cpp files can be meaningfully diffed subsystem-by-subsystem
