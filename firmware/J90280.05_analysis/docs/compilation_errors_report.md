# Compilation Error Analysis Report

Generated: $(date)

## Summary

**Total Errors: 2539**

This report categorizes compilation errors to identify what needs to be fixed in the CSV files vs. what are inherent Ghidra decompiler artifacts.

---

## Category 1: Ghidra Decompiler Artifacts (Not CSV-fixable)

These are artifacts of Ghidra's decompiler output that cannot be fixed by CSV changes alone.

### Sub-field Access Patterns (`._X_Y_`)

Ghidra uses `._X_Y_` to represent accessing bytes X through X+Y-1 of a multi-byte value.

| Pattern | Count | Description |
|---------|-------|-------------|
| `_0_2_` | 186 | Access bytes 0-1 (lower 16 bits of 32-bit) |
| `_0_3_` | 145 | Access bytes 0-2 (lower 24 bits) |
| `_1_1_` | 114 | Access byte 1 |
| `_0_1_` | 91 | Access byte 0 (lowest byte) |
| `_2_2_` | 62 | Access bytes 2-3 (upper 16 bits of 32-bit) |
| `_3_1_` | 25 | Access byte 3 (highest byte of 32-bit) |
| `_2_1_` | 22 | Access byte 2 |
| `_1_2_` | 22 | Access bytes 1-2 (middle 16 bits) |

**Subtotal: ~667 errors**

### Struct Sub-field Access

Structs with `_X_Y_` member access (Ghidra accessing sub-ranges of struct fields):

| Struct Type | Missing Member | Count |
|-------------|----------------|-------|
| `diag_transfer_state_t` | `_10_2_` | 19 |
| `fuel_arbitrator_diag_t` | `_28_2_` | 17 |
| `fuel_arbitrator_diag_t` | `_20_2_` | 13 |
| `fuel_arbitrator_diag_t` | `_24_2_` | 11 |

**Subtotal: ~60 errors**

### Pointer/Type Issues

| Issue | Count | Description |
|-------|-------|-------------|
| Invalid dereference of `undefined4` | 109 | Trying to dereference a 32-bit value as pointer |
| Invalid dereference of `uint32_t` | 104 | Same issue with known type |
| Invalid dereference of `int` | 63 | Same issue |
| Void value not ignored | 101 | Function returns void but code uses return value |
| lvalue required for `&` | 50 | Taking address of non-lvalue |
| Cast specifies array type | 46 | Invalid array cast |

**Subtotal: ~473 errors**

### Category 1 Total: ~1200 errors

---

## Category 2: Missing Global Variables (Add to global_variables.csv)

These variables are referenced in decompiled code but not defined in the CSV.

### High-Frequency Missing Variables

| Variable Name | Occurrences | Suggested Match |
|---------------|-------------|-----------------|
| `current_fuel_demand_value` | 38 | `current_fuel_demand_limit` |
| `protection_system_enable_flag` | 19 | `protection_state_enable_flags` |
| `diagnostic_system_flags_1` | 19 | `diagnostic_status_flags` |
| `active_derate_value` | 17 | - |
| `_loopCounter` | 16 | `initLoopCounter` |
| `amount_of_time_since_water_in_fuel_low_failure...` | 16 | (name truncation issue) |
| `vp44_flag_register_1` | 15 | - |
| `diagnostic_system_flags_2` | 15 | `diagnostic_status_flags` |
| `current_engine_rpm_raw` | 15 | `current_engine_rpm` |
| `target_boost_pressure_base` | 14 | - |
| `oil_pressure_precrank_status` | 14 | - |
| `current_engine_fuel_demand` | 14 | - |
| `engine_fault_status_register_3` | 13 | `engine_fault_status_reg` |
| `engine_fault_status_register_1` | 13 | `engine_fault_status_reg` |
| `_enables_input_of_eps_period_data_to_pptb_0_1` | 13 | (underscore prefix) |
| `vp44_communication_status` | 12 | `vp44_communication_status_bdc6` |
| `_insite_response_buffer_ptr` | 12 | `insite_response_buffer_ptr` |
| `_can_transmit_length` | 12 | `can_transmit_length` |
| `derate_threshold_exceeded` | 11 | `derate_threshold_previous` |
| `boost_pressure_feedback` | 11 | `boost_pressure_0_100` |
| `engine_fault_register_a` | 11 | `engine_fault_a_timer` |

### Underscore-Prefixed Variables (Ghidra local copies)

Many variables appear with underscore prefix (e.g., `_governor_speed_setpoint` vs `governor_speed_setpoint`). These may be:
- Local copies of globals in function scope
- Decompiler artifacts for parameter passing

**Category 2 Total: ~1269 errors**

---

## Category 3: Function Signature Issues (Update function_renames.csv)

### Functions with Wrong Argument Count

| Function | Calls | Issue |
|----------|-------|-------|
| `timerSchedulerSetup` | 15 | Too many arguments |
| `sendCanSingleFrame` | 9 | Too many arguments |
| `coreSystemFunction` | 6 | Too many arguments |
| `coreTableInterpolation` | 5 | Too many arguments |
| `j1939MemoryDataCopyResolver` | 4 | Too many arguments |
| `canFrameDataCopy` | 4 | Too many arguments |
| `diagMemoryReadWithOffsetBuilder` | 3 | Too many arguments |
| `diagnosticMemoryAddressResolver` | 3 | Too many arguments |
| `circularBufferWrite` | 2 | Too many arguments |

### Called Object Not a Function

**16 errors** - Variables being called as functions (type mismatch)

**Category 3 Total: ~70 errors**

---

## Action Items

### Priority 1: Missing Global Variables (CSV Work)

Add these to `global_variables.csv`:
1. `active_derate_value` - appears 17 times
2. `vp44_flag_register_1` - appears 15 times  
3. `target_boost_pressure_base` - appears 14 times
4. `oil_pressure_precrank_status` - appears 14 times
5. `current_engine_fuel_demand` - appears 14 times

### Priority 2: Variable Name Mismatches (CSV Corrections)

These appear to be renamed variables - verify if CSV names are correct or if Ghidra labels need updating:
- `current_fuel_demand_value` → `current_fuel_demand_limit`?
- `protection_system_enable_flag` → `protection_state_enable_flags`?
- `diagnostic_system_flags_1/2` → `diagnostic_status_flags`?
- `current_engine_rpm_raw` → `current_engine_rpm`?

### Priority 3: Function Prototypes (CSV Work)

Update `function_renames.csv` prototypes for:
- `timerSchedulerSetup`
- `sendCanSingleFrame`
- `coreSystemFunction`
- `coreTableInterpolation`

### Not Addressable via CSV

The ~1200 decompiler artifact errors require either:
1. Accepting as documentation-only (not compilable)
2. Post-processing transforms on decompiler output
3. Manual Ghidra analysis to improve type information

---

## Error Distribution Summary

| Category | Errors | % of Total | Fixable via CSV? |
|----------|--------|------------|------------------|
| Decompiler Artifacts | ~1200 | 47% | No |
| Missing Variables | ~1269 | 50% | **Yes** |
| Function Signatures | ~70 | 3% | **Yes** |

**~53% of errors are addressable through CSV updates.**
