W14 globals4 is done. The result file is /home/linux/.claude/jobs/f6a06670/tmp/fueling_state/stage9/result_W14_globals4.jsonl: 63 lines in bin order. I edited no repo file. Scratch is in /tmp/w14_globals4/ (peek.py, fault.py, addr_records.py, spec_a/b/c.py, build.py, verify.py, cross_check.py, shared_names.py).

My checks on the final file: `old` equals the CSV name, and every new name passes the apply_renames.py rules (copied by hand, since the gate was not run). `_cal` appears only in the EEPROM mirror, and no new name collides with a CSV row, a .cpp token, or another W14 result file. Every code_quote sits on an executable .cpp line.

## Verdicts
- 61 renames (`confirmed`), 2 keeps, 0 drift, 0 uncertain.
- Keeps:
  - 0x40af54 `transmission_park_or_neutral_flag`: two records resolve here.
    - 109E +8 Chrysler_Park_Neutral_Flag matches the proved code use.
    - 1226 +56 CANC_Requested_MIL is a drift alias; it lands inside the power take-off words.
    - The e2m_note carries 109E +8.
  - 0x40b9cb `general_diagnostic_battery_voltage_in_range_flag`: no record resolves to that byte (1B2D +6 resolves to 0x40b9ca), the name is accurate, and the e2m_note is empty.
- 15 renames carry `old_comment_wrong`: 0x3fcff0, 0x3fcff4, 0x40a198, 0x40a19c, 0x40a78a, 0x40a790, 0x40b57f, 0x40b58b, 0x40b9a4, 0x40b9a6, 0x40b9c6, 0x3fddba, 0x40a1a2, 0x406776, 0x408a9c / aa4 / aa8. Each new comment carries the old comment's proved facts.
- One rename is held for the main session: 0x40b87f `engine_sync_state_t_0040b87f` -> `fuel_pressure_governor_state`. It has a `type_note`:
  - the struct is 6 bytes with a 1-byte `reserved_05`, but 0x40b884 is a word (lhz at 0x48d14, sth at 0x49250);
  - e2m 8019 +5 HPCR_Filtered_Battery_Voltage is a 2-byte record there, so the struct should be 7 bytes;
  - the type and its field labels want the matching `fuel_pressure_governor_state_t` rename in the same change.
- No `split` entries.

## Families renamed
- **The 1102 PGN 65251 torque curve (17 rows):**
  - `j1939_determined_engine_speed_at_point_1` / `_3`;
  - `j1939_torque_curve_speed_at_point_1` / `_3`;
  - `j1939_torque_curve_fueling_at_point_1`;
  - `j1939_torque_curve_calculated_fueling_at_point_1..5`;
  - `j1939_torque_curve_reference_fueling_at_point_1..5`;
  - `j1939_nominal_friction_percent_torque_times_256`.
  - I checked the point numbering against `cm848_updateProtectionStateMachine`: the calculated fuelings are snapshots taken before the working fueling resets to `fuel_demand_maximum`.
- **Air handling source words:** `barometric_pressure_reference_source`, `ambient_air_temperature_reference_source`, `compressor_inlet_pressure_source`, `intake_manifold_temperature_filtered_source`, `compressor_outlet_temperature_source`, `egr_orifice_delta_pressure_source`, `egr_delta_pressure_negated_source`, `charge_pressure_source`.
- **Charge pressure (1A2D / 1A2C):** `charge_pressure_state`, `charge_pressure_in_range_condition`, `charge_pressure_in_range_enable_flag`, `charge_pressure_in_range_fault_clear_threshold`, `charge_pressure_in_range_fault_count_decrement`.
  - 0x40a434 is 1 when the deviation exceeds the limit, so the old "below threshold" was backwards.
- **All-speed governor 107C:**
  - `all_speed_governor_derivative_term` (0x40a1aa);
  - `all_speed_governor_state_integral` (X2), `_pid_clamp_value` (X4), `_pid_integral_clamped` (X5), mirroring the 1170 reset-state names;
  - `all_speed_governor_derivative_adjustment` (the QD word).
- **Governor pressure monitors (8C59):**
  - `governor_pressure_zero_check_target_high_limit`;
  - `governor_pressure_mid_range_check_target_low_limit` / `_high_limit`;
  - `governor_pressure_check_maximum_transmission_temperature` / `_minimum_...`.
  - These are pressure targets and a transmission temperature window, not rpm or load.
- **Converter clutch monitor (8C34):** `converter_clutch_rationality_monitor_state`, `converter_clutch_first_lockup_in_third_gear_flag`.
- **Cylinder balance (81B0):** `cylinder_balance_stop_compensation_flag` (the old "valid" had the polarity reversed), `cylinder_balance_trim_limits_exceeded_flag`.
- **Rail pressure key-on check (1B2D):** `fuel_pressure_sensor_pre_start_check_state`, `fuel_pressure_sensor_pre_start_check_abort_code`.
- **Coolant temperature sensor performance (P0116):** `coolant_temperature_sensor_performance_temperature_span`, `_state`. They match the globals1 agent's `..._temperature_minimum` / `_maximum` suffix style.
- **Cruise droop gains:**
  - `cruise_top_droop_gain_for_rear_axle_ratio_low` (0x3fcff0);
  - `road_speed_governor_top_droop_gain_for_rear_axle_ratio_low` (0x3fcff4);
  - these pair with globals3's `cruise_top_droop_gain`.
- **Drivetrain ratio (106C):** `drivetrain_ratio_user_filtered`, `drivetrain_ratio_out_of_gear_cruise_disable_flag`.
- **Other renames:**
  - `data_collector_stop_mode_cal` (0x3fddba, EEPROM mirror);
  - `cruise_coast_accelerate_hold_countdown`;
  - `engine_protection_shutdown_override_request_flag` and `engine_protection_timer_state`;
  - `commanded_throttle_transient_flags`;
  - `compressor_inlet_pressure_drop`;
  - `egr_orifice_temperature_estimate_minimum_limit`;
  - `sensor_channel38_filtered_output` and `boost_pressure_channel77_sensor_filtered`.

## Drift and e2m contradictions
- The 1226 +56 alias at 0x40af54, described under Keeps.
- 0030 +4 Collector_Stop_Mode has range 0-2 in the e2m, but the code tests 1, 2 and 3. The record is correct by the parameter ID table.
- 1B2D +0 abort code 5 is "keyon too long" in the e2m. In the code it is set when the engine leaves STOPPED before the minimum number of samples. Both are recorded in the comment.
- The e2m description of 1921 +8 Ambient_Air_Tmptr_Source is copied from the pressure source. The code confirms it is the ambient temperature source.

## Holds and caveats
- **Shared-name holds:** none. None of the 61 old names appears in CM550's global_variables.csv or function_renames.csv, docs/cross_firmware_variable_map.csv, or cross_firmware_matches.csv.
- 0x40bb8a rests on this calibration: `qadc_channel_index_table[1]` and `[77]` hold the same index in the RAM dump. The code role holds regardless: the boost tolerance pairing and the compressor pressure ratio.
- 0x40bb3c is named by slot on purpose. Nothing writes channel 38, and "oil" comes only from the e2m tolerance order.
- 0x40a790 has no decompiled reader (three sth writes and no load). The name avoids SPN numbers and the J1939 coding, which is only the e2m's wording.
- `compressor_inlet_pressure_drop` also exists in `output/e2m_variables.csv`, the reference list that no build step reads. It collides with no CSV row or .cpp token.
- Comments cite current function names, several of which the function bins rename.
- Scaled dump values follow the brief's "N in the dump = X unit" form. The wave-13 `check_quoted_dump_values_W13.py` regex would misread the `= X` part as a quoted dump value.

## New leads outside my bin (current name; what the code shows)
- **Coolant sensor monitor:**
  - 0x40b9a2 `cssc_coolant_monitoring_cycle_count` -> `coolant_temperature_sensor_performance_monitoring_cycle_count`.
  - 0x3fd182 `protection_group29_coolant_temp_snapshot` and 0x3fd188 `protection_group29_startup_timer_count` belong to the same monitor.
  - So do DAT_003fd184 and DAT_003fd186, the intake manifold and battery temperature snapshots.
- **Thermostat monitor (P0128) `cssc` leftovers:** 0x40ba5e `cssc_initial_warmup_budget`, 0x40ba60 `cssc_conditioning_cycle_count`, 0x3fd262 `cssc_oiltemp_cooling_rate_fraction`, and the `engine_cssc_oilTemp_*` functions -> `thermostat_monitor_*`.
- **Sensor-select sources:**
  - 0x40a164 `fuel_boost_mode_state` (i16) is the barometric pressure selection state; the unsuffixed `barometric_pressure_source` is left for it.
  - 0x40a60a `fuel_demand_state_b` is the ambient air temperature input state.
  - 0x40a7d2 `fuel_demand_droop_state` is the source of `boost_pressure_current_raw`: 0 sensor, 1 synthetic EMA, 2 default (`phase_group_a_validateEngineSync`).
  - `boost_pressure_state_t_0040a406.reserved_0e` is the fresh air mass flow state, and `reserved_0a` is e2m 177D +C Charge_Flow_Source.
- **1102:** 0x40ad96 / 0x40ad98 `protection_speed_ratio_c` / `_d` are the percent torque x 256 at points 3 and 4 (`cm848_updateProtectionStateMachine`).
- **107C (the 1102 / 107C items are siblings of my renamed rows):**
  - 0x40a1cc / 0x40a1d4 `fuel_demand_pid_accum_hi` / `_lo` are the ASG QI / QP adjustments.
  - 0x40a1b2 and 0x40a208 are other 107C siblings.
  - 0x3fa0e8 `governor_pid_integral_state` is the dword whose high word is X2.
- **106C:** 0x40b6fe `fuel_flow_rpm_divisor_saved` is +A Gear_Ratio_When_Loaded.
- **10B1:** DAT_0040a78b is +19 EPF_Shutdown_Override_Lamp_Flag, with no row yet.
- **Cruise droop:** DAT_003fcff2 / DAT_003fcff6 are the rear_axle_ratio_high twins of my two cruise droop rows.
- **Pre-start check leftovers:** 0x3fd1de, 0x3fd1dc, 0x409ef4 and 0x409ef8 still say `cam_sync_validation_*` in `hpcr_checkRailPressureSensorBeforeStart`.
- **8019:** 0x40b890 `engine_sync_cold_start_flag` is HPCR_Dutycycle_Output_Tool_Override (1 B). 0x40b899 `engine_sync_signal_flag` is Temperature_Reset_Status.
- **Converter clutch monitor rows still named `protection_*`:** `protection_output_rate_counter`, `protection_output_phase_entry_flag`, `protection_action_mode_b2_snapshot`, `protection_pid_rpm_setpoint_prev`, `protection_fuel_demand_prev`, `protection_fuel_demand_tick_snapshot`, and 0x408ad2 / 0x408ad3 / 0x408ade.
- **Governor pressure tracking rows:** `protection_coldStart_channelA/B_window_active_flag`, `protection_coldStart_eval_cycle_count` and `_protection_coldStart_channelB_fault_reported_flag`.