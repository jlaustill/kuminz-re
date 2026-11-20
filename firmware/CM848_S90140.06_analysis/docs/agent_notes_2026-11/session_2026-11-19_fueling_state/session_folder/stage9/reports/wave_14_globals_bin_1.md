W14 globals1 is done: 64 lines in bin order at /home/linux/.claude/jobs/f6a06670/tmp/fueling_state/stage9/result_W14_globals1.jsonl. I edited no repo file and ran no build. Scratch scripts are in /tmp/w14_globals1/.

What I checked: all 62 new names plus 3 split names pass the gate rules. None collides with the CSVs, the .cpp, the headers, or the other six agents' result files, and the format matches the brief. Every code_quote is a verbatim .cpp line or a fragment of one. Dump values were read at the row width from cm848_ram.bin.

**Counts**
- 62 confirmed renames, 1 keep (0x40a3ca `wastegate_duty_controller_state`, e2m 16A2 +C), 1 drift (0x40be14), 0 uncertain.
- 18 rows carry `old_comment_wrong`, mostly the `diag_dm1_*`, `cssc_*` and `protection_*` comments.
- 4 rows carry `type_note` and are held for you: 0x3fddc4 (a dword that is really the head of a 32-entry table) and 3 splits, 0x408f8c, 0x408fa3 and 0x408fa5.

**Families renamed**
- **Data collector**: `diag_dm1_*` is now `data_collector_*`.
  - 0x3fbca6 / aa / ae / b0 / b2 / b6 / b8: `_fill_stop_address`, `_fill_phase`, `_buffer_has_data_flag`, `_multiple_countdown`, `_table_entry_count`, `_sample_capacity`, `_trigger_input_previous_flag`.
  - 0x3fddc4 `data_collector_address_table_cal`.
  - 0x40c274 `data_collector_buffer_end_address`. This pairs with the other agent's `data_collector_buffer_start_address`.
- **Crank / cam block (e2m 8194, 29 rows, plus 0x40b7cc)**: the `mios` names were wrong, because these are TPU-A channel parameters.
  - Channel 0 is the crank signal (the TPU missing-transition function) and channel 1 is the cam signal (the additional-transition function). The functions3 agent reached the same reading for `mpc555_updateEngineCrankState`.
  - New names are `crank_signal_*` (0x408f93-99, 0x408fad) and `cam_signal_*` (0x408f90-92, 0x408fac).
  - Primary/backup pairs: `primary_consecutive_error_threshold`, `primary_pulse_period_timeout`, `backup_period_rpm_conversion_factor`.
  - Error limits are named for the counter they bound, with fault 5 = P0341, 117 = P0016, 92 = P0335, 93 = P0340, 124 = P0336 read through ROM 0x5985a: `cam_sync_error_count_limit`, `crank_sync_error_count_limit`, `cam_crank_mismatch_count_limit`.
  - The old "min" names were maxima.
  - Firing detection: `cylinder_firing_acceleration_threshold` and `cylinder_firing_detection_minimum_fueling`.
  - Pure `_cal` drops: 0x408f60, 0x408f8e, 0x408f9e.
  - Items 0x408f8c / 0x408f9a / 0x408fa3 / 0x408fa5 and 0x408f88 got descriptive names; the splits are listed below.
- **Cylinder balance**: the 0x3fb5a4 / a6 snapshots, and the 8C73 service limits and gain at 0x408f2c / 2e / 30 (`cylinder_balance_service_fueling_trim_maximum` / `_minimum`, `cylinder_contribution_test_gain`).
- **Coolant temperature sensor performance (P0116)**: `cssc_*` at 0x3fd18a-90 now `coolant_temperature_sensor_performance_*`.
  - 0x3fd18e is a one-shot precheck flag, not a "snapshot taken" flag.
  - 0x3fd18f is the soak-conditions flag.
- **Alpha (104A)**: `alpha_state`, `alpha_low_ambient_air_pressure_result`, `alpha_low_speed_governor_timer`, `alpha_air_fuel_control_timer`. The globals2 agent's `*_timer_active_flag` names match.
- **Others**:
  - `cruise_resume_active_flag_previous` (0x3fb528)
  - `egr_orifice_temperature_lead_time_constant_lookup` (0x3fbcf8)
  - `output_shaft_to_vehicle_speed_divisor_low_axle_ratio` and `_high_axle_ratio` (0x3fd062 / 66)
  - `logical_output_request_bits_40_to_47` (0x40c085, the intake air heater relay requests 43 / 44)
  - `cruise_top_droop_width_cal` (0x3fd912, the twin of the RSG top droop width)
  - `j1708_link_fault_timeout_count_cal` (0x3feb8c)
  - `pressure_sensor_check_delay_time` (0x40718c)
  - `wastegate_duty_compressor_outlet_temperature_derate_derivative_term` (0x40a3e4)

**Splits and type notes (apply by hand)**
- 0x408f8c / 0x408f8d: two bytes, `backup_period_capture_count` and `crank_periods_per_speed_interrupt`. Both are used.
- 0x408fa3 / 0x408fa4: `crank_lost_resync_cam_tooth_threshold` and `crank_preliminary_resync_cam_tooth_threshold`, bytes read in run state 1 and 3.
- 0x408fa5 / 0x408fa6: a byte upper limit and a word lower limit for the tooth shift. Their names are `crank_preliminary_sync_tooth_shift_upper_threshold` and `..._lower_threshold`.
- 0x3fddc4: type as `dword[32]`, with a length word at 0x3fddc2 (128 in the dump).

**Drift**
- 0x40be14 `barometric_pressure_sensor_fault_status`: e2m 1966 +94 TVA_Position_Sensor resolves here, but the code holds the barometric sensor channel's fault status. The name is kept.

**Shared-name holds**
- None. No current name in my bin appears in CM550's CSVs or `cross_firmware_matches.csv`.

**Things for you to decide**
- `j1708` in 0x3feb8c rests on the e2m record plus elimination: `etc1_active_state` is only ever stored as 1, so this path is state 0. Confidence is medium. "j1708" is not on the allowed list but is an SAE designation like j1939.
- I used `backup_` for 0x408f8c and 0x40b7cc (`backup_period_capture_index`) because the e2m names are Backup records and the data comes from channel 1. The ring `crank_period_capture_array` (0x40b7dc) keeps its `crank_` name until you rename it.
- 0x3fd062 / 66 and 0x3fbcf8 had no `dump_raw` in the bin. I quoted 113703 (= 453 x 251) and 500 from my own read of the RAM dump, so the dump-value check may flag them.
- I used `cylinder_contribution_test_gain` because `cylinder_contribution_gain` already exists in `e2m_variables.csv`.

**New leads outside my bin** (address, current name, what the code shows)
- 0x3fb52a `fuel_demand_enable_sync_flag_shadow+2` (label row): the previous-pass `cruise_control_engaged_flag`.
- Cylinder test saves in `cm848_runCylinderContributionTest`, all unnamed:
  - DAT_003fb596: previous `cylinder_diag_active_flag`.
  - DAT_003fb597: previous test status.
  - DAT_003fb598 (word[6]): copy of the learned trims.
- DAT_003fbcb4: the collector's bytes used (entries x capacity).
- 0x3fddc2: length word of the collector table, no row.
- 0x40a16e / 0x40a172 / 0x40a174 (`pressure_fuel_delay_b_status`, `fuel_rate_condition_status`, `pressure_fuel_delay_a_status`): e2m 104A +6 / +A / +C Alpha_AFC / Alpha_Governor / Alpha_LSG results, i.e. `alpha_air_fuel_control_result`, `alpha_governor_result`, `alpha_low_speed_governor_result`.
- 0x3fee7a `protection_timing_period_cal`: e2m 132C +0 Tire_Size, tire revolutions per mile. The dump reads 251, below the e2m range 300-725, so it may be drift.
- 0x3fee7c `protection_timing_counter`: VSS_Noise_Counter, in the EEPROM mirror without `_cal`.
- 0x408f28 / 2a `engine_sync_coolant_upper/lower_threshold_cal`: e2m 8C73 +0 / +2 CBD_Service_Max / Min_Coolant_Temp, with a `_cal` in RAM.
- 8194 rows with a `_cal` in RAM:
  - 0x408f58 `crank_pattern_tooth_count_cal`
  - 0x408f5e `crank_sync_phase_counter_threshold_cal`
  - 0x408f7e `crank_speed_setpoint_threshold_cal`
  - 0x408f66 `crank_timer_offset_cal`: a word row over two byte records, +10 at 0x408f66 (read as `._0_1_`) and +11 at 0x408f67 (read as the `(byte)` cast); the label row `crank_timer_offset_cal+1` sits at the second byte.
- 0x408fae / 0x408fba `crank_mios_timing_axis_cal` / `_values_cal`: the cam signal's good-window curve (e2m 819A), wrong `mios` and `_cal`.
- 819B words on the backup (cam) path still named `crank_*`:
  - 0x40b7dc `crank_period_capture_array` is Pulse_Period_Table_Backup, so `backup_period_capture_array`.
  - 0x40b794 `crank_tooth_period_raw` is Average_Pulse_Period_Backup.
  - 0x40b79a `crank_tooth_rpm` is Backup_RPM.
  - 0x40b7d0 `crank_tooth_good_window_fraction` is the cam signal's PMA_Good_Window, so `cam_signal_good_window_fraction`.
  - 0x40b79e `crank_sync_timeout_count` is Cam_Crank_Mismatch_Count, a mismatch count and not a timeout.
  - 0x40b7aa `crank_period_variation_metric` is Cylinder_Acceleration.
  - 0x40b7bc `crank_tooth_count_b` is Firing_Detection_Count.
- Struct `engine_crank_state_t` (e2m 819C): `start_counter` is Cam_Sync_Error_Count, `crank_state` is Cam_Sync_State (0 / 1 / 4 = no / lost / have), `cranking_flag` is Crank_Sync_Error_Count, `run_state` is Crank_Sync_State. The field names and comments are stale.
- Wastegate siblings, plus the stale `wastegate_duty_controller_state_t` field comments ("Governor output RPM", "Gap (0xa3cc)"):
  - 0x40a3e0 `governor_pid_adjustment_output`: TGC_Turbo_Deriv_Term.
  - 0x40a3e2 `governor_trim_lookup_result`: TGC_COT_Drt_SET_Gain.
  - 0x40a3e8 `battery_voltage_gain_lookup`: TGC_ULim_Battery_Voltage_Comp.
- 0x3feb90 `etc1_fuel_demand_high_limit`: e2m 11C1 +4 TSC_Lost_Max_Throttle_Disable, in the EEPROM mirror without `_cal`.
- `protection_group29_startup_timer_count`, `protection_group29_coolant_temp_snapshot` and DAT_003fd184 / 003fd186 belong to the coolant temperature sensor performance family.