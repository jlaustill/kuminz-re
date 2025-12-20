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

## Future Work

- [ ] Reverse relocation map (J90350.00 → J90280.05) to find functions added in J90350.00
- [ ] Extract build dates from all known firmware
- [ ] Automate feature comparison generation from relocation maps
- [ ] Track CP3/common rail firmware when available
