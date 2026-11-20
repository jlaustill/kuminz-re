W13 bin2 is done: 64 lines written to /home/linux/.claude/jobs/f6a06670/tmp/fueling_state/stage8/result_W13_bin2.jsonl, in bin order. Nothing else was touched; `git status` is clean.

My own self-check passed. It covered address and `old` against the bin and the CSV row, name uniqueness against CSV fields and .cpp tokens, the BANNED set, `_cal` by region, comments of 360 characters or fewer, quoted dump values against `dump_raw`, and no comment citing a name this bin renames.

**Verdicts:** 48 rename (confirmed), 10 keep, 6 drift, 0 uncertain.

**Families renamed**
- **104C AFC (3):** `air_fuel_control_{normal_boost_timer, low_boost_timer, low_boost_blend_fraction}`. The old `fuel_ramp_*` names read backwards.
- **109C friction fuel (4) and 175C +8:** `friction_fueling` and `friction_fuel_adjustment_for_{coolant_temperature, air_conditioning_clutch, radiator_fan}`; `friction_torque_adjustment_for_coolant_temperature`. The old names said `governor_*` and `fuel_demand_rpm_correction_lookup`.
- **1102 Jcomm block (17):** the old `protection_*` / `j1939_dm1_*` / `fuel_demand_*` names, which are the PGN 65251 engine configuration and torque curve. New names:
  - `actual_engine_percent_torque_times_256`
  - `j1939_engine_percent_load_at_current_speed_times_256`
  - `j1939_indicated_percent_torque_at_{idle,point_2,point_5}_times_256`
  - `j1939_determined_engine_speed_at_point_{2,4,5}`
  - `j1939_reference_engine_fueling`
  - `reference_engine_torque_working` (old `_cal` was wrong)
  - `j1939_torque_curve_speed_at_point_{2,4,5}`
  - `j1939_torque_curve_fueling_at_point_{2..5}`
- **81AE/81AF cylinder balance (9):** `cylinder_balance_*`. The old "low / high threshold" names were reversed, and `cam_timing_*` was wrong.
- **18D9 intake manifold temperature lead (3):** `intake_manifold_temperature_{after_lead, lead_term, lead_time_constant}`. The old names said pressure.
- **Singles:**
  - `data_collector_end_address` (was `diag_dm1_*`)
  - `supervisor_chip_driver_feedback_delay_microseconds` (was `j1939_address_cached`)
  - `cruise_driver_fault_match_debounce_threshold` (was `protection_*`)
  - `ram_refresh_enable` and `development_mode` (see judgment calls)
  - `rear_axle_ratio_{low,high}_cal`
  - `road_speed_governor_top_droop_width_cal` (gains the mirror `_cal`)
  - `key_off_shutdown_mode`
  - `total_fueling`
  - `exhaust_temperature_estimate_injection_timing_coefficient`

**Drift**
- **1B2D, +4 on (4 rows, 0x40b9c8..ce):**
  - The code there is the OBD monitor enabling inputs, which an earlier pass tied to block 160A. Block 160A is outside the dumped ID table.
  - 1B2D +0 and +2 (0x40b9c4 / 0x40b9c6) hold: they are the key-on rationality abort code and state.
- **1966, +94 on (0x40be16):** the value/default pairs end at +92, and fault status words start at 0x40be14.
- **1649, +10 on (0x3fd948):**
  - The 193A +0 Test_Sensor1_Ratio_Supply_ID array starts here; the in-plant EOL struct ends at +F.
  - 193A +0 matches the current name and could be added as the cross-reference.

**Judgment calls to review**
- **0x40c04a `diagnostic_session_state` -> `ram_refresh_enable`, and 0x40aa9a `j1939_standby_flag` -> `development_mode`.** The evidence is strong:
  - `cm848_initProtectionModule` is the compare-and-rewrite loop, and it sets fault bit 0x1, which is e2m `RAM_Image_Word_Error`.
  - `cm848_runCylinderContributionTest` clears the flag while it edits calibration RAM.
  - Boot sets it ACTIVE.
  - The reset service sets `development_mode` and clears the refresh enable together.

  The enums `DIAG_SESSION_STATE` / `J1939_STANDBY_STATE` and their member descriptions still follow the old reading, and I did not change types.
- **0x40a33a `fuel_timing_arbitration_output` -> `total_fueling`.** There is no timing in it. `timing_limit_upper` (0x5c30c) is e2m 1052 +6 Minimum_Fueling.
- **0x3fd482 `eeprom_mirror`:** kept without `_cal`, as the base symbol of the whole mirror. It is the one mirror-region row I left deliberately.
- **`friction_fueling` and `total_fueling`:** these equal names in `e2m_variables.csv`. They are not in `global_variables.csv` or the .cpp, and 18 globals already coincide with that file.
- **Type remarks:**
  - Signed records typed `word` with `lha` reads are `i16` candidates: 0x40aef6, 0x40ad8a, 0x40afbe, 0x40676c, 0x40a458, 0x408eee and 0x408ef0.
  - 0x40a45a, 0x408f24, 0x408f26, 0x3fee94 and 0x3fee96 are signed and read through `(short)` casts.
  - 0x408ef2 is unsigned but read with `lha`.

**Functions whose names the evidence shows are wrong (not applied automatically)**

| Address | Current -> proposed | Reason |
|---|---|---|
| 0x0001b3a0 | `faultTimerHandler` -> `cm848_buildPgn65251EngineConfigurationMessage` | Fills the 28-byte PGN 65251 payload from the torque curve snapshots. |
| 0x00020d10 | `cm848_updateProtectionStateMachine` -> `cm848_updateJ1939TorqueCurve` | Builds the speeds, fuelings and percent torques at points 1-5; no protection state. |
| 0x00020c64 | `cm848_processJ1939RxMessage` -> `cm848_calculateJ1939TorqueCurveDroopBreakpoint` | Tail helper of the above, not a receive handler. |
| 0x00020500 | `cm848_calculateProtectionActivationDelay` -> `cm848_calculateReferenceEngineFueling` | Computes the Jcomm peak fueling. |
| 0x000209e8 | `cm848_calculateLoadRateOfChange` -> `cm848_calculateActualEnginePercentTorque` | Computes the EEC1 actual percent torque x 256. |
| 0x00020a58 | `cm848_calculateLoadToFuelRatio` -> `cm848_calculateEnginePercentLoadAtCurrentSpeed` | Computes the EEC2 percent load. |
| 0x0002588c | `j1939GetEngineStateCode` -> `cm848_buildPgn61444ElectronicEngineController1Message` | Builds and sends EEC1. |
| 0x000212dc | `cm848_initProtectionDelayDefaults` -> `cm848_initializeJ1939ReferenceEngineFuelingAndTorque` | Loads the ROM peak fueling and reference torque. |
| 0x00021cd4 | `cm848_updateProtectionDiagnostics` -> `cm848_updateJ1939TorqueCurveReferenceFuelings` | Skimmed only: it sets the five per-point reference fuelings. |
| 0x0050dba8 | `governor_computeSpeedTargetWithThermalCorrection` -> `cm848_calculateNoLoadFuel` | Sums friction fuel plus the coolant, A/C and fan adjustments. |
| 0x0050eaa8 | `cm848_applyProtectionRpmCorrectionFilter` -> `cm848_calculateEngineFrictionAndNetMachineTorque` | Computes the 175C friction, no-load and net machine torques. |
| 0x00013d14 / 0x00013dc8 | `cm848_calculatePressureSensorDerivative` / `...Filtered` -> `cm848_calculateIntakeManifoldTemperatureLeadTerm` / `cm848_filterIntakeManifoldTemperature` | Channel 9 is the intake manifold temperature. |
| 0x00538a84 / 0x005389c4 | `cm848_initProtectionModule` / `uds_session_state_init` -> `cm848_refreshRamCalibration` / `cm848_initializeRamRefresh` | The RAM refresh loop and its setup. |
| 0x00021624 / 0x00021668 / 0x00021694 | `cm848_activate` / `reset` / `forceActivateDiagnosticSession` | They set or clear `ram_refresh_enable` and `development_mode`; reset enters development mode. Review the names. |
| 0x00505c20 | `diag_dm1Buffer_circularFill` -> `cm848_fillDataCollectorBuffer` | It is the data collector. |
| 0x0004272c / 0x00042770 / 0x005268e8 | `cm848_applyProtectionControlLimit` / `cm848_setProtectionControlValue` / `cm848_computeProtectionTrimDivisors` -> `cm848_selectRearAxleRatioInUse` / `cm848_selectRearAxleRatioHigh` / `cm848_calculateRearAxleTrimDivisors` | Axle ratio selection and its trim divisors. |

**Siblings outside the bin that keep wrong names (for another pass)**
- **1102:**
  - 0x40ad90 `j1939_engine_torque_output_b` is the EEC3 nominal friction percent.
  - 0x40ad96 `protection_speed_ratio_c` and 0x40ad98 `protection_speed_ratio_d` are the point 3 and 4 percent torques.
  - 0x40ada0 and 0x40ada2 are the determined speeds at points 1 and 3.
  - 0x40adac and 0x40adb0 are the torque curve speeds at points 1 and 3.
  - 0x40adb6 is the point 1 fueling.
  - 0x40adc0..c8 `protection_*_cached` are the Calc_Fueling points 1-5.
  - 0x40adca..d2 `governor_speed_ref_channel_a..e` are the per-point reference fuelings.
  - ROM 1104: 0x5c34e, 0x5c350, 0x5c356 and 0x5c358 (`protection_*_cal`) are the Jcomm speeds and derated fuelings at points 4 and 5.
  - 0x40a298 `protection_temp_scale_factor` is the axle ratio in use, and 0x3fd062 / 0x3fd066 `protection_trim_divisor_*` are the axle ratio times the timing period.
- **18D9:**
  - 0x40a462 `fuel_demand_phase_state` and 0x40a464 `fuel_demand_phase_status_flags` are Charge_Tmptr_Source / State.
  - The `sensor_channel9_pressure_*` rows are the intake manifold temperature channel.
- **10C7 +2:** 0x40c04c `sensor_validation_result` is Powerdown_Refresh_Enable.
- **1B2D +0 / +2:** 0x40b9c4 and 0x40b9c6 `cam_sync_validation_abort_reason` / `_state` are the fuel pressure key-on rationality abort code and state.
- **1042:**
  - 0x40a036 `fault_active_recovery_threshold_ch19_20` carries a `ch` abbreviation; it is Cruise_Driver_Recover_Count.
  - The `j1939_can_frame_word_*` / `j1939_timer_*` rows are supervisor chip words.
- **11D5:** 0x3ff00a..10 `fuel_ramp_*_cal` carry a `_cal` outside the mirror. They are the AFC time delay and select slew records.
- **Data collector:** 0x40c270..84 `diag_dm1_buffer_*`, 0x3fddba and 0x3fddb8. Mechanical names would be `data_collector_buffer_start_address` and so on.
- **120C:** 0x5c30c `timing_limit_upper`, 0x3fa86c, 0x3fa870 and 0x3feaa2 carry the same misread "timing".
- **1185 +4:** 0x3fd912 `cruise_ramp_zone_b_fuel_demand_threshold` should be `cruise_top_droop_width_cal`.
- **81AE:**
  - 0x408f2c and 0x408f2e `cylinder_diag_*_threshold_cal` are the CBD service trim maximum / minimum, with a `_cal` outside the mirror.
  - 0x3fb5a4 and 0x3fb5a6 are the matching snapshots.
  - 0x408f30 is the cylinder contribution gain.
  - 0x408f13 and 0x408eec `cam_timing_*` also need a pass.