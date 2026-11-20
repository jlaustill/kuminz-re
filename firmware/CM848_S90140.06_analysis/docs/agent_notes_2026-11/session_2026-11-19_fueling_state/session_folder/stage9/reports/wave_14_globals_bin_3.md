## W14 globals3: summary

The result file has 63 lines in bin order: `/home/linux/.claude/jobs/f6a06670/tmp/fueling_state/stage9/result_W14_globals3.jsonl`. It was written with `json.dumps` from `/tmp/w14_globals3/gen.py`.

Checks run against the final file:
- My self-check (`check.py`) reports no problems. It covers address and `old` against the bin and the CSV, name format, uniqueness within the file and against the CSVs, the .cpp and the headers, and all other `result_W14_*.jsonl` files. It also checks `_cal` by region, that each quote is in the .cpp and holds the old name, and the dump values I quote.
- The repo gate (`apply_renames.py`, dry run, nothing written) reports no PROBLEM for the 54 renames.
- `git status --short` is clean. I touched no repo file.

### Counts
- 54 rename (`confirmed`), 8 keep, 1 drift, 0 uncertain.
- 0x40912a is held by the apply: it carries a `type_note` and a one-entry `split` (a byte row over a 2-byte record; widen to word).
- 0x40b58c is a rename from the code and also drift in the record. List it under both.

### Families renamed
- **Throttle filter table (0x406a46, 0x406a52):** `commanded_throttle_filter_coefficient_by_throttle_difference_axis` / `_values`.
  - Blocks 1583 / 1584 are not in the dumped ID table, so there is no table-resolved record.
  - The basis is the X / Y pair, the units and scales, the description and the code role. It is stated in each comment.
- **Data collector (0x40c270):** `data_collector_buffer_start_address`. It pairs with globals1's `data_collector_buffer_end_address`.
- **Alpha fuel rate filter (0x5be66):** `alpha_fuel_rate_filter_coefficient`. It pairs with globals2's `alpha_fuel_rate_filter_state`.
- **Low speed governor alternator load (0x4070e0 / e2 / e4):** `low_speed_governor_alternator_load_{fuel_gain, duty_offset, filter_coefficient}`.
- **e2m 10E2 J1939 block (11 rows, 0x40a630-0x40a646):**
  - `j1939_no_load_fueling`
  - `j1939_percent_peak_torque_at_{current_speed, breakpoint_3, breakpoint_4, breakpoint_5, idle, rated_speed}_times_256`
  - `j1939_friction_load_fueling_at_{low_idle, rated_speed, breakpoint_3, breakpoint_5}`
  - The two functions that write the percent words have no caller (see the leads), so those words read 0.
- **Cruise droop, e2m 1187 (6 rows):**
  - `cruise_control_fueling_{bottom, top}_droop_{gain, offset}` are the values passed to the fueling procedure.
  - `cruise_{bottom, top}_droop_gain` are the computed slopes.
- **Air fuel control, e2m 11D5 (4 rows):** `air_fuel_control_low_boost_time_delay`, `_normal_boost_time_delay`, and `air_fuel_control_low_boost_blend_fraction_{increase, decrease}_step`.
- **OBD pending readiness code (0x3fed98):** `monitor_pending_readiness_code_cal`. It gains the missing `_cal`.
- **Wastegate (0x3ffca6):** `wastegate_duty_override_value`. The comment and evidence cite the `wastegate_duty_integrator_preset_flag_cal` branch.
- **Charge flow and volumetric efficiency, e2m 177C (11 rows):**
  - `charge_mass_flow_{filter_coefficient, estimate_maximum, estimate_minimum}`
  - `engine_{stroke, bore, valve_diameter}_inches`
  - `engine_volumetric_efficiency_{maximum, minimum, parameter_a, parameter_b, parameter_c}`
- **Exhaust temperature model (0x40a682):** `exhaust_temperature_model_energy_fraction`.
- **HPCR fuel pressure governor / fuel metering command, e2m 8000 (10 renames, 8 keeps):**
  - `fuel_pressure_governor_demand_minimum_when_{not_running, running}`
  - `fuel_metering_command_{override_enable, override_value, maximum, minimum}`
  - `fuel_pressure_governor_accelerator_feed_forward_{gain, minimum, maximum}`
  - `fuel_metering_battery_voltage_filter_coefficient` (0x40912a, held)
- **Converter clutch (0x40b57d):** `converter_clutch_rationality_ratio_delta`.
- **Governor pressure loop (0x40b58c):** `governor_pressure_controller_error_delta_term`.

The 8 keeps are 0x409114, 16, 18, 1e, 23, 26, 28 and 2e. Their names are accurate and each has an `e2m_note`.

### Drift
- New: e2m 8C34 drifts from +12 on. 0x40b58c, 0x40b58e and 0x40b590 are the governor pressure solenoid loop; the 8C34 monitor words end at +10.
- 0x40b58e (`governor_pressure_error`) is `drift` with no rename and no split. Both accesses are 4-byte `lwz` / `stw`, and neither e2m record is used.
- 0x40b58c is a rename from the code.
  - The old comment called the term "(D)". The new comment does not, because the loop adds three helper terms to `governor_pressure_controller_output` every pass in an incremental form.
  - A term on the per-pass error change acts like a proportional term there, so the name states what the term is computed from, the error delta.

### Shared-name holds
None. This bin has no function items.

### Names to reconcile
- `cruise_bottom_droop_gain` and `cruise_top_droop_gain` also appear in `e2m_variables.csv`. The gate does not read that file; wave 13 had the same coincidence for `friction_fueling`. They pair with `cruise_bottom_droop_width_cal` and with globals4's `cruise_top_droop_gain_for_rear_axle_ratio_low`.
- My comments cite five names from other bins' results. All were checked against the result files present at 21:43.
  - `data_collector_buffer_end_address`
  - `commanded_throttle_filter_coefficient_lookup_result`
  - `alpha_fuel_rate_filter_state`
  - `low_speed_governor_alternator_load_filter`
  - `charge_pressure` (the new name of `map_fuel_correction_factor`)
- They also cite current names of 11 functions that functions1-3 propose to rename (a comment name sweep can handle these):
  - `cm848_boostBasedFuelModifier`
  - `cm848_calculateFuelDemandChangeRate`
  - `cm848_calculateSensorEma`
  - `cm848_calculateThrottleProtectionLimit`
  - `cm848_faultSeverityEvaluation`
  - `cm848_initFuelPressureVariables`
  - `cm848_loadBasedFuelAdjustment`
  - `cm848_pidError_calc`
  - `cm848_pidIntegrator_accumulate`
  - `cm848_processThrottlePositionLookups`
  - `hpcr_exception_process`

### Type remarks (not in `type_note`)
- These rows have signed e2m records and are typed `word`. Their reads are `lha` or `sth`, so `i16` would fit.
  - 0x400944
  - 0x409110, 0x409112, 0x409114, 0x40911e, 0x409121, 0x409123, 0x409132, 0x409134, 0x409136, 0x409138
  - the six percent rows 0x40a632-0x40a63c
  - 0x40b57d
- 0x40b58c is read as signed (`(int)(short)`) although its e2m record is unsigned.
- 0x409121 and 0x40b57d are words at odd addresses; that matches their e2m offsets.

### Leads outside my bin
1. **The RAM dump has a gap (inferred).**
   - `cm848_ram.bin` is 0x45f80 bytes, which is 0x80 short of 0x440000.
   - The values 0x0040c28a / 0 / 0x003fddc4 sit at dump 0x40c200 / 0x40c204 / 0x40c206. That is 0x80 below the rows 0x40c280 / 0x40c284 / 0x40c286: the collector end pointer, status and table address.
   - Those three named rows read 0 at their own address and the expected value at address - 0x80.
   - The EEPROM mirror and the rows below 0x40c200 match.
   - So 0x40c200-0x40c27f is not in the dump, and rows from 0x40c280 up must be read at -0x80. The dump value 0 for 0x40c270 is not usable.
   - Affected rows: 0x40c200, 0x40c204, 0x40c234, 0x40c244 (`actuator_d_period_command`, `alternator_field_period_microseconds`, `egr_valve_motor_pwm_period_command`, `variable_geometry_turbocharger_motor_pwm_period_command`), 0x40c258 `output_read_back_fault_bits`, 0x40c25e / 0x40c260 `engine_rpm_override_value` / `_enable`, 0x40c262 `protection_timeout_sentinel`, and 0x40c270-0x40c27c.
   - globals1's comment for 0x40c274 says "0 in the dump, the collector is idle". The existing `data_collector_center_address` comment says "0 here". Neither is backed by the dump.
   - The collector end pointer is 0x40c28a (stored by `hpcr_exception_process`) and the table address is 0x3fddc4.
2. **`cm848_processThrottlePositionLookups` (0x1820c) and `cm848_calculateThrottleProtectionLimit` (0x182e8) have no caller.**
   - There is no `bl`, `b` or `bc` to them in all.dis, and no 32-bit pointer to them in the ROM or flash2 images.
   - Both are functions2 items. The Jcomm percent words stay 0.
3. **Siblings that are in no bin:**
   - 0x40094a / 0x40096c / 0x40098e / 0x4009b0 `boost_rpm_scale_axis_cal` / `boost_rpm_scale_output_cal` / `boost_load_axis_cal` / `boost_load_output_cal`. These are word[17] RAM rows with a wrong `_cal`, the tables of the volumetric efficiency model.
     - The axis is engine speed x stroke (800..3500 rpm x 4.7244 in).
     - The load axis is the absolute intake manifold temperature in 1/64 deg F (`intake_manifold_temperature_filtered + 0x7300`).
     - Its values are 157.5 x sqrt(axis).
   - 0x3fa5d6 `boost_modifier_filter_state` is the EMA record of `charge_mass_flow_filtered`.
   - 0x409472 / 0x40947e `cam_sync_speed_output_scale_axis_cal` / `_values_cal` (word[6], RAM, wrong `_cal`), 0x3fb697 `cam_sync_speed_filter_state`, and 0x40b884 (`engine_sync_state_t.reserved_05`) form the battery voltage compensation of `fuel_metering_command`: filtered battery voltage, then a scale table, then command x scale >> 12.
   - 0x3feff2 `fuel_demand_load_base_cal` (AFC_Fueling_Override_Value, `_cal` outside the mirror) and 0x3feff8 / 0x3feffa / 0x3feffc / 0x3feffe `fuel_demand_load_threshold_c / _b / _a / _d`.
   - 0x3ff002 / 0x3ff006 `fuel_demand_load_result_working` / `_select_working` and 0x3ff012 `boost_fuel_limit_maximum_decrease_step`. All of these are the air fuel control fueling thresholds and slew rates used in `cm848_calculateAirFuelControlFuelLimit`.
   - 0x40aeec `fuel_demand_base_offset` is e2m 109C +0 No_Load_Fuel, a table-resolved row with no comment. It is the friction fuel plus the coolant, A/C and fan adjustments, with about 25 readers.
   - 0x3fa712 `throttle_demand_offset_cal_working` is the friction fuel correction by coolant temperature, with a wrong `_cal` in the copy window.
   - 0x3fcefe `protection_pid_rpm_setpoint_prev` is the previous `converter_clutch_rationality_ratio`.
   - 0x40b596 `protection_throttle_error_delta` (dword) is `governor_pressure_error` minus the previous error. 0x408af0 `protection_throttle_velocity_gain` is its ROM gain. DAT_0040b59e and DAT_0040b594 are the other two terms. The `cm848_throttleGain_*` and `cm848_throttleSetpoint_limit` functions are governor pressure controller helpers misnamed "throttle".
   - 0x40b6b4 `cruise_speed_setpoint_c` (e2m RSG_BDO) and 0x40b6be `cruise_speed_offset_latched` (e2m Cruise_RSG_Top_Droop_Offset) are still unrenamed. Both were already named in the wave 13 report.

### Scratch folder (for the archive)
`/tmp/w14_globals3`: `gen.py`, `check.py`, `gate_dry.py`, `stale.py`, `names_check.py` and the lookup helpers (`item.py`, `uses.py`, `ptrsearch.py`, `dumpgap.py`, `others.py`, `inbins.py`).