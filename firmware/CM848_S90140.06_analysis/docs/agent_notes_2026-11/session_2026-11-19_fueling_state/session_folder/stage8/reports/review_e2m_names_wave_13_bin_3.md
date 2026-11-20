W13 bin3 is finished: 64 lines in /home/linux/.claude/jobs/f6a06670/tmp/fueling_state/stage8/result_W13_bin3.jsonl, in bin order. I edited no repo file and made no scratch file. A script check found no problems: `old` is exactly label_in_cpp, no bad names or `_cal` errors, comments at most 396 characters with no "(was". None of the 40 new names exists in the CSVs, .cpp or .hpp, and none collides with the names in the bin1/2/4/5/6 result files present when I checked.

**Verdicts:** 40 confirmed renames, 20 keep, 4 drift, 0 uncertain.

**Renames, by family**
- **`_cal` fixes (meaning right, rule broken):**
  - Missing `_cal` in the EEPROM mirror: `fault_aging_drive_cycle_counter_cal` (0x3fed90) and `engine_start_count_since_fault_logged_cal` (0x3fedce, was a bare "protection").
  - `_cal` outside the mirror, dropped: the 1944 rows (0x4009d4 and 0x4009d8, which were also the wrong domain) and `shift_in_process_hold_off_time_limit` (0x40869c).
- **Misnames:**
  - **000D:** `not_safe_to_program_flag` (0x40af66, was `prior_boot_faulted`). It holds engine_state != STOPPED.
  - **0036:** `data_collector_status` (0x40c284). The `diag_dm1_*` words around it are the data collector, not J1939 DM1.
  - **1052:** `fuel_demand_minimum` (0x5c30c, was `timing_limit_upper`). Every use is a lower bound. It is not `fuel_demand_minimum_tracked`.
  - **1053:** `four_dimensional_fueling`, `four_dimensional_fueling_user_maximum`, `commanded_throttle_filter_coefficient` and `commanded_throttle_filtered`.
  - **106C:** `drivetrain_ratio_change_settle_counter` (0x40b6fc). `fuel_flow_divisor` is the wrong domain.
  - **10B1:**
    - `engine_protection_precrank_shutdown_command_flag` (0x40a782).
    - `engine_protection_shutdown_approaching_flag` (0x40a786). The old name duplicated `fault_derate_active_flag`; the code sets this when a channel's timer passes the start-warning time.
  - **10E2:** `j1939_friction_load_fueling_at_breakpoint_4` (0x40a644).
  - **118A:** `cruise_governor_reference_speed` (0x40b6d4).
  - **11D4:** `master_slave_final_override_fueling` (0x40a87b) and `master_slave_override_enable_flag` (0x40a87d).
  - **1211:** `monitor_readiness_code_cal` (0x3fed94). The old comment's "clear as faults resolve" is wrong. The bits are OBD monitors still to run.
  - **16A3:** `wastegate_duty_first_error_term_limit_enable_flag_cal` (0x3fd7de). It matches the existing `wastegate_duty_second_error_term_limit_enable_flag_cal`.
  - **1981:** `end_of_line_test_malfunction_indicator_lamp_power_down_state_flag_cal` (0x3fee9b).
  - **80B9:** `injector_diagnostic_bits_{fast_decay, open_circuit, short_to_ground, short_to_battery}`, replacing the letters d, a, b and c.
  - **81B0:** `cylinder_balance_{filtered_fueling, fourier_real_component_1, fourier_imaginary_component_1, adjusted_real_component_2, adjusted_imaginary_component_2, adjusted_real_component_3, acceleration_buffer_6}`. I derived these from the harmonic sums in `hpcr_cbdCalculateCylinderTrims`, because two e2m descriptions are copy-pasted.
  - **8A14:** `shift_in_process_hold_off_time_limit` (0x40869c).
  - **8C33:** `converter_clutch_rationality_maximum_engagement_time` and `converter_clutch_steady_throttle_count_limit`.
  - **8C58:** `governor_pressure_zero_check_{state, debounce_count}` and `governor_pressure_mid_range_check_{fail_count, state, debounce_count}`. They match the existing 8C59 cal names; the monitors are P1757 and P1756, checked against the ROM tables.
- **Keep (accurate synonyms):** 0x40b6fa, 0x40a77e, 0x40a792, 0x3fed92, 0x3fd7f0, 0x40a706, 0x40ba36, 0x40b856, 0x4086be, 0x40b0a8, 0x40b44f, 0x40b450 and the eight 8A13 timers.

**Drift**
- **0x40ba48 and 0x40ba4a (1902 +2A / +2C):** the code uses them as the thermostat monitor's fuel words, not performance ratios.
- **0x4086c8 (8A14 +2E):** only the TSC1 reload fits; dump 20 is 0.3 deg F.
- **0x40b56e (8C58 +10), new:** the word is the P0720 output speed sensor state, which is e2m 8C4E +4 OSS_Rationality_Monitor_State at the same address. 8C4E +0 resolves to 0x40b56a, which is 8C58 +C, so the 8C58 tail (+C..+12) overlaps 8C4E. 8C59 +1A / +1C land on 8C4F +0 / +2.

**Vocabulary choices**
- `four_dimensional_*` follows the e2m ("4D"). The repo's `cm848_calculateDualAxisFuelLimit` and the enum say "dual axis".
- `malfunction_indicator_lamp` is spelled out; the repo's existing `mil_*` names are not on the brief's allow-list.
- `fourier` stands for FFT.
- `cylinder_balance_` follows the existing 81AF rows.
- 80B9 splits a family: eight out-of-bin rows keep the letters. Map: a = open_circuit, b = short_to_ground, c = short_to_battery, d = fast_decay.
  - The out-of-bin rows are `injector_diagnostic_bits_{a,c,b,d}_debounce_count` at 0x3fb6fc / 0x3fb6fe / 0x3fb700 / 0x3fb702 and `_debounce_limit` at 0x409a8c / 0x409a90 / 0x409a8e / 0x409a8a.
  - Short-to-ground versus short-to-battery rests on the e2m byte order only; both bytes feed P2146 / P2149. Open circuit is anchored by P0201-P0206.

**Type notes (not changed)**
- 0x40a87d is `dword` but should be `word`: the record is 2 bytes, every load is `lhz`, and it covers 11D4 +4 at 0x40a87f.
- 0x40b73c, 0x40b73e, 0x40b740, 0x40b742, 0x40b744 and 0x40b756 are signed records read only with `lha`, so `i16` would fit.
- 0x40b856 (a keep) is also signed with three `lha` loads.

**Old facts only in the evidence**
- Comments assume the apply keeps the old comment as an earlier note.
- 0x3fed94: the `lwz`/`stw` proof site (@ 0x52d634) and the note that it is distinct from `diagnostic_fault_flags_a/b` (0x40a813) are not repeated.
- Check the other renames if the apply drops old notes.

**Function names the evidence shows are wrong (not applied; proposed names not gate-checked)**
- 0x2bf44 `cm848_updateFaultOnKeyoff` -> `cm848_updateNotSafeToProgramFlag`. It runs every pass and only stores engine_state != STOPPED.
- 0x1e830 `cm848_updateEngineTimingCompensation` -> `cm848_updateFourDimensionalFueling`. It stores the 4-D fueling; nothing about timing.
- 0x1eae8 `cm848_calculateFuelDemandChangeRate` -> `cm848_filterCommandedThrottle`.
- 0x525e54 `protectionTimeoutControl` -> `cm848_updateDrivetrainRatio`. It computes and filters the drivetrain ratio and its out-of-gear and settle timers.
- 0x508130 `governor_coldStart_faultDerate_trigger` -> `cm848_examineEngineProtectionBeforeCranking`.
- 0x508898 `governor_faultDerate_mainLoop_update` -> `cm848_updateEngineProtectionShutdown`.
- 0x508e78 `cm848_updateJ1939ReceptionControlFlag` -> `cm848_detectEngineProtectionShutdownOverrideRequest`. It edge-detects the override switch, not J1939 reception.
- 0x508ee0 `governor_derateTrigger_latch_clear` -> `cm848_latchEngineProtectionShutdownOverride`.
- 0x1811c `cm848_faultSeverityEvaluation` -> `cm848_calculateFrictionFuelingAtBreakpoints`.
- 0x182e8 `cm848_calculateThrottleProtectionLimit` -> `cm848_calculateJ1939PercentPeakTorque`.
- 0x1820c `cm848_processThrottlePositionLookups` -> `cm848_calculateJ1939PercentPeakTorquePoints`.
- 0x18070 `cm848_throttlePositionProcessing` -> `cm848_calculatePercentPeakTorqueAtSpeed`.
- 0x50ddb4 `diag_suppress_stateMachine` -> `cm848_controlEndOfLineTestMilRequest`. It sets diagnostic_suppress_flag, which forces the MIL on.
- 0x533b18 / 0x533b5c / 0x533b94 `diag_protection_history_increment / _shiftIn / _shift` -> `cm848_incrementEngineStartCountsSinceFaultLogged` / `cm848_shiftInEngineStartCountsSinceFaultLogged` / `cm848_shiftEngineStartCountsSinceFaultLogged`.
- 0x42cfc `hpcr_processLoadThrottle` -> `hpcr_filterCylinderBalanceFueling`. It filters final_fueling for the cylinder balance code.

**Out-of-bin sibling leads (not in my bin)**
- **10E2:** 0x40a630-0x40a646.
  - Percent peak torque rows: `throttle_protection_load_ratio`, `throttle_position_b6` / `b8` / `ba` / `b4`, `throttle_position_from_integrator`.
  - Friction rows: `throttle_torque_integrator_lookup`, `throttle_cal_b4_lookup`, `throttle_cal_b6_lookup`, `throttle_cal_ba_lookup`.
  - They fit `j1939_percent_peak_torque_at_*` and `j1939_friction_load_fueling_at_*`.
  - I did not verify that the percent-torque words feed PGN 65251.
- **106C:** 0x40b6f6 `fuel_flow_rpm_divisor` (User_Filtered_Gear_Ratio), 0x40b6f8 `fuel_flow_divisor_invalid_flag`, 0x40b6fe `fuel_flow_rpm_divisor_saved`. They hold the drivetrain ratio, not fuel flow.
- **10B1:**
  - 0x40a78a `governor_fuel_derate_j1939_latch` is the shutdown override request.
  - 0x40a790 `governor_fuel_derate_state` is the engine protection timer state.
  - 0x40a772 and 0x40a774 (`governor_faultDerate_*`) are camelCase legacy names.
  - 0x40a74c `governor_faultDerate_ch0_threshold_exceeded` is 1152 +18 Fuel_Temperature_Precrank_Error.
- **1053:** 0x40a889 `thermal_fuel_limit_factor` is the 4-D interpolation factor. 0x40a891 `fuel_limit_mode_flags` holds the throttle transient/decrease flags. The `fuel_mode_ema_*` rows at 0x3fa880-0x3fa884, 0x406a46 and 0x406a52 are the same throttle filter.
- **8C33 / 8C34:** the P1740 `protection_*` rows at 0x408ad2, 0x408ad3, 0x408ade and 0x40b57a-0x40b58e. That includes `protection_pid_step_counter` (TCC_Rationality_Timer), `protection_output_stability_counter`, and `governor_pressure_error` (OD_Function_Timer).
- **8C58 / 8C59:**
  - 0x40b55e `protection_coldStart_channelA_trip_count` -> `governor_pressure_zero_check_fail_count`.
  - The window_active flags and 0x408a9c / 0x408aa4 / 0x408aa8 `protection_coldStart_*_threshold`. These are governor pressure target limits, not rpm.
  - 0x408aac / 0x408aae `protection_load_*_threshold`, a transmission temperature window.
- **81B0 and neighbours:**
  - 0x40b74c-0x40b754 `cylinder1..5_timing_offset` are Accel_Buffer_1..5, so `cylinder_balance_acceleration_buffer_1..5`.
  - 0x40b746 `cylinder_sync_valid_flag` and 0x40b747 `crank_pattern_sync_flag` are CBD_Stop_Compensation_Flag and CBD_Trim_Limits_Exceeded.
  - The 81AF rows `cam_timing_prev_capture_a/b` and `cylinder_sync_state`, and the 81B1-3 `cylinder_seq_*` rows.
- **0x3fed98 `fault_pending_flags_b`:** Pending_Readiness_Code, so `monitor_pending_readiness_code_cal`.
- **0x3fedbc `protection_event_spn_history`:** the fault code history; it is in the EEPROM mirror and lacks `_cal`.
- **0x40a19a `boost_fuel_demand_blend_a`:** holds `ambient_air_temperature_selected`.