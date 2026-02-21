# Cross-Firmware Analysis Methodology

This document describes how to analyze and compare Cummins ECU firmware versions to track code evolution across generations.

## Goals

Track four types of differences between firmware versions:

| Type | Description | Detection Method |
|------|-------------|------------------|
| **Excluded Features** | Code that doesn't exist due to `#ifdef` preprocessor directives | Function in A but `not_found` in B |
| **Method Versioning** | Same function with code changes between versions | `similar` status in relocation map |
| **Added Features** | New functionality in newer firmware | Function in B but `not_found` in A |
| **Removed Features** | Features dropped from newer firmware | Often detected via engine parameters (VP44 vs CP3) |

---

## Relocation Map Format

The `relocation_map.csv` file maps functions between two firmware versions:

```csv
source_address,source_name,target_address,confidence,status
0x00a5c0,initFuelSystemOutputDriver,0x00b666,81,matched
0x00b130,vp44TimingConditionChecker,N/A,0,not_found
0x00b656,engine_speed_governor,0x00c962,86,matched
```

### Status Codes

| Status | Meaning | Confidence |
|--------|---------|------------|
| `matched` | Identical or near-identical function at different address | 75-100 |
| `similar` | Function exists but code differs (version change) | 60-85 |
| `not_found` | Function doesn't exist in target firmware | 0 |

### Current Statistics (J90280.05 → J90350.00)

| Status | Count | Interpretation |
|--------|-------|----------------|
| matched | 293 | Core shared code |
| similar | 350 | Functions that evolved |
| not_found | 150 | Features excluded in J90350.00 |

---

## Preprocessor Directive Patterns

Cummins firmware uses preprocessor directives to enable/disable features at compile time.

### Pattern 1: Stub Function (Feature Disabled)

```c
// Full implementation in source, but compiled as:
short authenticateSession(void) {
    return 0;  // #ifdef AUTH ... #else return 0; #endif
}
```

**Detection:** Function exists but returns constant 0/1 or is trivially empty.

**Example:** `authenticateSession` in J90280.05 returns 0 (auth disabled), but J90350.00 has full implementation.

### Pattern 2: Complete Exclusion

```c
// #ifdef RETARDER_CONTROL
// void initRetarderSystem(void) { ... }
// #endif
```

**Detection:** Function in relocation map shows `not_found`.

### Pattern 3: Conditional RAM Allocation

Features excluded via `#ifdef` don't allocate their RAM variables, explaining why:
- J90280.05 has fewer RAM addresses than J90350.00
- 1821 DAT_ addresses in J90350.00 have no equivalent in J90280.05

---

## Build Date Tracking

Build dates are critical for ordering firmware versions chronologically.

### Sources of Build Date

1. **EEPROM Data Plate** - Date code at 0x010002C0 region
2. **Firmware Strings** - Search for date patterns (YYMMDD, MM/DD/YY)
3. **ECU Label** - Physical date code on ECU housing

### Date Code Format

| Source | Format | Example |
|--------|--------|---------|
| ECU Label | DDMMYY | 060498 (April 6, 1998) |
| EEPROM | Variable | Extracted via `strings` |

### Version Ordering by Date

| Firmware | Date Code | Year | Relative Age |
|----------|-----------|------|--------------|
| J90280.05 | Unknown | Unknown | Reference |
| J90350.00 | 060498 | 1998-04-06 | Confirmed |
| J90270.06 | Unknown | Unknown | Pending |

---

## Feature Categories

Features are categorized for systematic tracking:

| Category | Description | Examples |
|----------|-------------|----------|
| fuel_system | Fuel injection control | VP44 CAN, injection timing |
| security | Authentication & licensing | Session auth, parameter locks |
| drivetrain | Transmission/retarder integration | Retarder control, kickdown |
| protection | Engine protection systems | Derate, shutdown limits |
| diagnostics | Fault codes & monitoring | DTC handling, Insite comm |
| transmission | Automatic transmission interface | Kickdown signal, gear feedback |
| io_control | Hardware I/O management | GPIO, ADC configuration |

---

## Engine Parameter Indicators

Some features can be identified by the engine configuration:

### Fuel System Detection

| Engine Type | Fuel System | Indicator Functions |
|-------------|-------------|---------------------|
| ISB (1998-2002) | VP44 Rotary Pump | `vp44CanMessageDispatcher`, `vp44TimingConditionChecker` |
| ISB (2003+) | CP3 Common Rail | CP3-specific functions (different CAN IDs) |

### Feature Persistence Theory

Even when a feature isn't compiled into a firmware:
- Source code likely still exists at Cummins
- Same codebase compiled with different `#define` flags
- VP44 code probably exists in CP3 firmware source, just not compiled

---

## Analysis Workflow

### Comparing Two Firmware Versions

1. **Generate Relocation Map**
   ```bash
   # In target firmware analysis directory
   npm run match  # Runs address matcher against source firmware
   ```

2. **Review Not-Found Functions**
   ```bash
   grep ',not_found' output/relocation_map.csv
   ```

3. **Categorize Differences**
   - Functions in source but not target → Excluded features
   - Functions in target but not source → Added features
   - `similar` functions → Version changes (compare decompiled code)

4. **Update Feature Comparison**
   - Add entries to `firmware/feature_comparison.csv`
   - Note category and presence status for each firmware

### Adding a New Firmware Version

1. Create analysis directory: `firmware/Jxxxxx.xx_analysis/`
2. Set up Ghidra project and CSV workflow
3. Port function names from closest known firmware
4. Generate relocation map against reference firmware
5. Document feature differences

---

## Cross-Reference Files

| File | Location | Purpose |
|------|----------|---------|
| `ecu_identification.md` | Repo root | ECU hardware/software database |
| `feature_comparison.csv` | `firmware/` | Feature presence matrix |
| `relocation_map.csv` | Each analysis dir | Function address mapping |

---

---

## CM550 vs CM848D Scheduler Architecture Comparison

This section documents the structural comparison between CM550 (VP44 pump) and CM848D (Common Rail) ECU main loops, enabling cross-firmware function naming.

### Scheduler Architecture - Identical Pattern

Both ECU generations use the **same 40-phase cooperative scheduler**:

| Aspect | CM550 (J90280.05) | CM848D (S90140.06) |
|--------|-------------------|---------------------|
| Phase count | 40 (0x00-0x27) | 40 (0x00-0x27) |
| Phase index variable | `_main_loop_phase_index` | `main_loop_phase_index` |
| Wrap behavior | 0x27 → 0 | 0x27 → 0 |
| Tasks per phase | 5-7 | 6-7 |
| Even/odd alternation | Yes | Yes |

### Per-Phase Structure Mapping

| Position | CM550 | CM848D | Purpose |
|----------|-------|--------|---------|
| 1st call | `ioControlAndCanPinSwitchingWrapper()` | `phase_common_processing()` | Common tasks + I/O |
| 2nd call (even) | `evenPhaseSchedulerTaskSet()` | `phase_group_a_processing()` | Even-phase tasks |
| 2nd call (odd) | `oddPhaseSchedulerTaskSet()` | `phase_group_b_processing()` | Odd-phase tasks |
| 3rd-7th | Named coordinator functions | `periodicTaskGroupN_*()` | Domain-specific |

### Core Task Group Mapping (Every 4 Phases)

| CM848D Group | Address | CM550 Equivalent | Confidence |
|--------------|---------|------------------|------------|
| `periodicTaskGroup0_fuelFinal` | 0xb8fc | `fuel_delivery_controller` + `fuel_limit_arbitrator` | High |
| `periodicTaskGroup1_sensorProcessing` | 0xb98c | `engine_speed_governor` | High |
| `periodicTaskGroup2_controlLoop` | 0xba08 | `slowCycle4Coordinator` | Medium |
| `periodicTaskGroup3_auxiliaryControl` | 0xba90 | `auxiliarySystemControlWrapper` | Medium |

### Secondary Task Group Mapping (Every 8 Phases)

| CM848D Group | Address | CM550 Equivalent | Confidence |
|--------------|---------|------------------|------------|
| `periodicTaskGroup4_canTx` | 0xbb18 | `messageQueueDispatcher` (part) | Medium |
| `periodicTaskGroup5_diagnostics` | 0xbb40 | `diagnosticMonitoringCoordinator` | High |
| `periodicTaskGroup6_protection` | 0xbb68 | `advancedEngineProtectionCoordinator` | High |
| `periodicTaskGroup7_timing` | 0xbb90 | `fuelTimingCoordinator` | **Direct** |
| `periodicTaskGroup8_outputs` | 0xbbb8 | `engineRpmHardwareTimerSetup` | Medium |
| `periodicTaskGroup9_sensors` | 0xbbe0 | Part of `evenPhaseSchedulerTaskSet` | Low |
| `periodicTaskGroup10_monitoring` | 0xbc08 | `slowCycle10Coordinator` | **Direct** |
| `periodicTaskGroup11_communication` | 0xbc34 | `diagnosticCommunicationSlowCycle10Coordinator` | **Direct** |

### Slow Cycle Task Mapping (Every 20-40 Phases)

| CM848D Group | CM550 Equivalent | Purpose |
|--------------|------------------|---------|
| `periodicTaskGroup19_diagnostics` | `diagnosticStatisticsSlowCycle20Coordinator` | Diagnostic timers |
| `periodicTaskGroup33_protection2` | `shutdownProtectionSlowCycle40Coordinator` | Engine shutdown protection |
| `periodicTaskGroup35_fuelDemand` | `fuelDemandProportionalCalculationSlowCycle40Coordinator` | Fuel demand coordination |

### Injection System Differences

| Feature | CM550 (VP44) | CM848D (Common Rail) |
|---------|--------------|----------------------|
| Pump communication | `vp44_communication_state_machine` | N/A |
| Cylinder trim | N/A | `cbdCalculateCylinderTrims` |
| Injector control | Via VP44 CAN | Direct `injectorPulseWidthCalc` |
| Fuel trim output | Single value | Per-cylinder via `calculateFuelTrimOutput` |

### Common Processing Function Breakdown

**CM550 `ioControlAndCanPinSwitching`** (simple I/O):
```
- SIM_CAN_CONTROL_PORT register writes
- CAN filter manipulation
- ~15 lines of code
```

**CM848D `phase_common_processing`** (comprehensive):
```
- processJ1939PeriodicMessages()     ← CAN messaging
- protectionAlarmHandler()           ← Engine protection
- injectorTimingCalculation()        ← Fuel timing
- processFaultAndFuelDemand()        ← Fault handling
- processFaultConditionFlags()       ← Fault flags
- 11 total function calls
```

### CM848D Calibration Groups (No CM550 Equivalent)

CM848D has 27 calibration-specific groups (12-38) that CM550 handles inline:

| Group Range | Purpose | Named Functions |
|-------------|---------|-----------------|
| 12-18 | Primary calibration | Mostly BYTE_* (unnamed) |
| 19-24 | Diagnostics/outputs | `updateProtectionDiagnostics`, `processProtectionControlLogic` |
| 25-32 | Extended calibration | `processProtectionFaultSeverity`, `calculateTurboRatios` |
| 33-38 | Protection/auxiliary | `processProtectionCoolantLookup`, `fuelDemandCoordinator` |

---

## Cross-Firmware Naming Opportunities

Based on the scheduler analysis, these CM848D functions can be named by analogy:

### High-Confidence Renames (Direct Equivalents)

| CM848D Address | Current Name | Suggested Name | Source |
|----------------|--------------|----------------|--------|
| 0x0000b76c | `phase_common_processing` | ✓ Already named | Analysis |
| 0x0000b7b4 | `phase_group_a_processing` | ✓ Already named | Analysis |
| 0x0000b854 | `phase_group_b_processing` | ✓ Already named | Analysis |
| 0x0000b8fc | `periodicTaskGroup0_fuelFinal` | `fuelDeliveryAndLimitCoordinator` | CM550 pattern |
| 0x0000b98c | `periodicTaskGroup1_sensorProcessing` | `governorAndSensorCoordinator` | CM550 pattern |

### Subfunctions to Investigate

Functions called within CM848D task groups that likely have CM550 equivalents:

| CM848D Function | Called In | Likely CM550 Equivalent |
|-----------------|-----------|-------------------------|
| `calculateFuelDemandFilter` | Group 1 | `fuelDemandBlendCalculator` |
| `updateGovernorSpeedLimits` | Group 1 | `rpm_system_state_controller` |
| `calculateBoostTorqueOffset` | Group 2 | `boostPressureTargetCalculator` |
| `coldStartRpmTableLookup` | Group 2 | `coldStartFuelControlSlowCycle40Coordinator` |
| `processThermalProtection` | Group 6 | `fuelTempProtectionLimitCalculator` |
| `calculateTorqueCurveValue` | Group 7 | `fuelTimingModeBlendCalculator` |
| `processUdsSecurityService` | Group 11 | `diagnosticServiceSecurityValidator` |

### Bank 2 Functions (BYTE_005xxxxx) - Prime RE Targets

The CM848D calibration groups call many unnamed Bank 2 functions. Priority targets:

| Address | Called By | Call Count | Suggested Investigation |
|---------|-----------|------------|------------------------|
| BYTE_00538ef4 | phase_group_a | High | Compare to CM550 `timerBasedTaskScheduler` |
| BYTE_0050bff4 | phase_group_a | High | Compare to CM550 sensor processing |
| BYTE_00532fac | phase_group_b | High | Compare to CM550 `faultTableEntryProcessor` |
| BYTE_00506780 | Phase 0 | 40/cycle | Likely scheduler bookkeeping |
| BYTE_00538278 | Phase 1 | 40/cycle | Likely scheduler bookkeeping |

---

## Cross-ECU Analysis Workflow

### Naming CM848D Functions from CM550

1. **Identify scheduler position** - Which phase and position in that phase?
2. **Find CM550 equivalent position** - Look at same phase structure
3. **Compare called subfunctions** - Similar function count and patterns?
4. **Trace data flow** - Do they read/write similar RAM regions?
5. **Apply name with confidence tag** - Add to function_renames.csv

### Example: Naming periodicTaskGroup7_timing

```
Position: 4th call in odd phases (1, 3, 5, ...)
CM550 equivalent position: fuelTimingCoordinator (4th call in odd phases)

CM848D calls:
  - calculateTorqueCurveValue()
  - processSensorTemperatureData()
  - processTimingTableLookup()

CM550 fuelTimingCoordinator calls:
  - fuelTimingModeBlendCalculator() → matches calculateTorqueCurveValue
  - fuelTimingOffsetCalculator() → matches processTimingTableLookup

Conclusion: Direct equivalent - periodicTaskGroup7_timing = fuelTimingCoordinator
```

---

## Future Work

- [ ] Reverse relocation map (J90350.00 → J90280.05) to find functions added in J90350.00
- [ ] Extract build dates from all known firmware
- [ ] Automate feature comparison generation from relocation maps
- [ ] Track CP3/common rail firmware when available
- [ ] Create CM848D → CM550 relocation map using scheduler position matching
- [ ] Name top 50 most-called BYTE_005xxxxx functions using CM550 analogs
- [ ] Document CBD (Cylinder Balance Deviation) system unique to CM848D common rail
- [ ] Map CM848D RAM variables using CM550 variable names at equivalent offsets
