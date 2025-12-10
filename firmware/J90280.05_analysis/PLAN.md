# Plan: Discover and Document New Enums and Structs

## Status: Phase 4 - Pending Verification

## Summary of Changes

### Phase 1 - Initial Enum Work (Completed)

| Enum Name | Entries | Variable | Purpose |
|-----------|---------|----------|---------|
| **SHUTDOWN_SELECTOR_SOURCE** | 10 | `shutdown_minimum_selector_value` | Identifies which fuel limiter won the minimum selection |
| **FUEL_DEMAND_SOURCE** | 8 | `fuel_demand_source_id` | Tracks which subsystem is providing fuel demand |
| **FUEL_DEMAND_LIMIT** | 6 | `fuel_demand_limit_source` | State machine for fuel limiting in fuelDemandFaultStateBuilder |
| **DIAGNOSTIC_STATUS** | 9 | `diagnostic_status_register` | Diagnostic operation mode state machine |
| **VP44_DIAG_MODE** | 10 | `vp44_diagnostic_mode_state` | VP44 diagnostic mode state machine |

### Phase 2 - Additional Enums (Completed)

| Enum Name | Entries | Variable(s) | Purpose |
|-----------|---------|-------------|---------|
| **HIGH_RPM_PROTECTION_STATE** | 5 | `high_rpm_protection_state` | Engine protection state machine (monitoring → warning → shutdown) |
| **TPU_TRANSMISSION_STATE** | 4 | `tpu_transmission_state_machine` | CAN/serial byte transmission sequence |
| **PWM_TIMER_CYCLE_STATE** | 6 | `pwm_timer_cycle_advance_state` | Timing cycle phase (0-5 modulo 6) |
| **DERATE_EVENT_STATE** | 3 | `derate_event_state_machine` (x2) | Derate event duration tracking |
| **IO_CONTROL_STATE** | 3 | `io_control_bit0/1/4/6_state` (x4) | Per-bit output control state machine |
| **RPM_CAPTURE_STATE** | 3 | `rpm_timer_capture_state` | RPM measurement state (init → capture → fault) |
| **TIMING_MODE_SOURCE** | 5 | `timing_mode_source_selector` | Fuel timing blend source identifier |

**Phase 2 Total: 29 new enum values, 11 variables typed**

### Phase 3 - Structure Refinement (Completed)

#### Analysis of `._X_Y_` Patterns

The `._X_Y_` notation in decompiled code means "offset X bytes, size Y bytes" - indicating Ghidra doesn't know the proper structure for sub-field access.

**Most common patterns analyzed:**
| Pattern | Count | Type | Notes |
|---------|-------|------|-------|
| `local_X._Y_Z_` | 95+ | Local variables | Cannot fix without function-level changes |
| `param_X._Y_Z_` | 85+ | Function parameters | Needs prototype fixes |
| `qsm_sci_data_reg._1_1_` | 45 | Hardware register | MC68336 SCI register |
| `fuel_arbitrator_diag_t_*._X_2_` | 54 | Structure fields | Structure has gaps in field definitions |
| `governor_fuel_pid_integral._0_2_` | 14 | Q16.16 fixed point | Added structure definition |

#### New Structures Added

**q16_fixed_point_t** - Generic Q16.16 fixed-point structure:
- `integer_part` (word) - High 16 bits (._0_2_)
- `fractional_part` (word) - Low 16 bits (._2_2_)

**governor_pid_integral_t** @ 0x008016e2 - Specific instance for governor PID:
- `integer_part` (word) - Integer portion of PID integral
- `fractional_part` (word) - Fractional portion of PID integral

#### Key Findings

1. **Local variables** (`local_X._Y_Z_`) are the most common pattern but can't be fixed without function-level type annotation in Ghidra.

2. **Parameter patterns** (`param_X._Y_Z_`) require updating function prototypes.

3. **Existing structures** like `fuel_arbitrator_diag_t` have field gaps causing `._X_2_` patterns - the structure script uses absolute addresses but has incomplete field coverage.

4. **`fuel_command_scaled`** is a local variable in `engine_speed_governor()`, not a global.

### Global Variables Updated

**Phase 1 (6 variables):**
- `shutdown_minimum_selector_value` → type: SHUTDOWN_SELECTOR_SOURCE
- `fuel_demand_source_id` → type: FUEL_DEMAND_SOURCE
- `fuel_demand_limit_source` → type: FUEL_DEMAND_LIMIT
- `diagnostic_status_register` → type: DIAGNOSTIC_STATUS
- `vp44_diagnostic_mode_state` (0x008096b6) → type: VP44_DIAG_MODE
- `vp44_diagnostic_mode_state_2` (0x008096fc) → type: VP44_DIAG_MODE

**Phase 2 (11 variables):**
- `high_rpm_protection_state` → type: HIGH_RPM_PROTECTION_STATE
- `tpu_transmission_state_machine` → type: TPU_TRANSMISSION_STATE
- `pwm_timer_cycle_advance_state` → type: PWM_TIMER_CYCLE_STATE
- `derate_event_state_machine` (0x008032da) → type: DERATE_EVENT_STATE
- `derate_event_state_machine` (0x008094ec) → type: DERATE_EVENT_STATE
- `io_control_bit0_state` → type: IO_CONTROL_STATE
- `io_control_bit1_state` → type: IO_CONTROL_STATE
- `io_control_bit4_state` → type: IO_CONTROL_STATE
- `io_control_bit6_state` → type: IO_CONTROL_STATE
- `rpm_timer_capture_state` → type: RPM_CAPTURE_STATE
- `timing_mode_source_selector` → type: TIMING_MODE_SOURCE

### Before/After Example

**Before:**
```c
if (high_rpm_protection_state == 4) {
    // what is state 4?
}
```

**After (with enum):**
```c
if (high_rpm_protection_state == SHUTDOWN_PENDING) {
    // clearly shows shutdown pending - timer expired waiting for idle
}
```

## Verification Steps

1. Run `Ctrl+Shift+E` (ApplyAndExport) in Ghidra
2. Check that switch statements show enum member names
3. Verify no underscore prefix issues (indicating size mismatches)
4. Match enum sizes to variable sizes (byte=1, word=2)

## Files Changed

- `ghidra/CM550.rep/enums.csv` - +29 enum values (Phase 2)
- `ghidra/CM550.rep/global_variables.csv` - 11 type changes (Phase 2)
- `ghidra/CM550.rep/structure_definitions.csv` - +4 structure fields (Phase 3)

## Future Opportunities

### Further Structure Work
- Fill gaps in `fuel_arbitrator_diag_t` (offsets 4-17, 44-53)
- Add function prototypes for better parameter typing
- Define local variable structures in key functions

### Additional Enum Candidates (Remaining)
- `fuel_timing_mode_blend_factor` - timing mode constants (0x4000)
- ~~`vp44_operating_condition_value` - VP44 condition states (1-4)~~ ✓ DONE
- ~~`vp44_communication_status` - VP44 comm states (1-4)~~ (Found to be bit field, not enum)

### Phase 4 - Final Enum Work (Pending Verification)

| Enum Name | Entries | Variable(s) | Purpose |
|-----------|---------|-------------|---------|
| **VP44_OPERATING_CONDITION** | 5 | `vp44_operating_condition_value`, `vp44_operating_condition_prev`, `vp44_state_operating_condition_cached` | VP44 pump condition state tracking |
| **VP44_STATE** | 6 | `vp44_state_current_debounced`, `vp44_state_previous`, `vp44_state_input_current`, `vp44_state_debounce_value` (x2), `vp44_sensor_prev_debounce`, `vp44_sensor_status_monitor_state` | VP44 pump state machine for communication/debounce |
| **ENGINE_HISTOGRAM_MODE** | 3 | `engine_runtime_histogram_mode` | Hour meter and runtime tracking mode |

**Phase 4 Total: 14 new enum values, 11 variables typed**

### Phase 4 Global Variables Updated

- `vp44_operating_condition_value` (0x008096b4) → type: VP44_OPERATING_CONDITION
- `vp44_operating_condition_prev` (0x0080327c) → type: VP44_OPERATING_CONDITION
- `vp44_state_operating_condition_cached` (0x0080333a) → type: VP44_OPERATING_CONDITION
- `vp44_state_current_debounced` (0x00803336) → type: VP44_STATE
- `vp44_state_previous` (0x00803338) → type: VP44_STATE
- `vp44_state_input_current` (0x00803330) → type: VP44_STATE
- `vp44_state_debounce_value` (0x0080333e) → type: VP44_STATE
- `vp44_state_debounce_value` (0x0080938c) → type: VP44_STATE
- `vp44_sensor_prev_debounce` (0x008033f4) → type: VP44_STATE
- `vp44_sensor_status_monitor_state` (0x008033f6) → type: VP44_STATE
- `engine_runtime_histogram_mode` (0x00809b1b) → type: ENGINE_HISTOGRAM_MODE
