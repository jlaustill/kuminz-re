W13 bin5 is done: 63 lines in /home/linux/.claude/jobs/f6a06670/tmp/fueling_state/stage8/result_W13_bin5.jsonl, address set equal to the bin, and no repo file touched (git status is clean). Checks: every `old` equals the row's current name in global_variables.csv; every new name is free in all CSVs, the .cpp and the headers, is snake_case, avoids the gate's BANNED words (plus `mil`) and keeps the `_cal` rule; none of the five other result_W13 bins uses the same new name.

**Counts:** 42 renames (verdict `confirmed`), 20 keeps, 1 drift (0x40b9a2). 0x40b55e is counted as a rename, but the bin's own record there is drift; report it under both.

**Families renamed**
- **Converter clutch rationality monitor (8C34), 8 rows:** `protection_*` become `converter_clutch_*`.
  - Rows: 0x40b57a, 0x40b57c, 0x40b581, 0x40b583, 0x40b585, 0x40b586, 0x40b588, 0x40b58a.
  - The `protection_*` / 0x408ad5 / 0x408ad6 names in bin3 already use the same prefix.
- **48RE governor pressure monitors:** `governor_pressure_rationality_fail_count` (0x40b55a), `governor_pressure_rationality_timer` (0x40b55b) and `governor_pressure_zero_check_fail_count` (0x40b55e). Same prefix as the wave-12 cals and bin3's siblings.
- **Fuel metering coil resistance estimator (8019):** `fuel_metering_command_filtered` (0x40b893), `fuel_metering_coil_resistance_filtered` (0x40b895) and `fuel_metering_coil_temperature` (0x40b897). The old `cam_speed_rate` / `engine_sync_*` names were cam-sync guesses.
- **Fuel pressure governor integral gains (8015):** `fuel_pressure_governor_integral_gain_small_signal` / `_positive_large_signal` / `_negative_large_signal` (0x4094b2, 0x4094b6, 0x4094ba). The prefix matches bin1 and bin4.
- **Charge pressure in range (1A2C / 1A2D):** `charge_pressure_in_range_fault_count_increment` (0x4051e4), `_set_threshold` (0x4051e6) and `_fault_count` (0x40a438). I avoided "boost in range" because block 1632 (BIR) is a different monitor.
- **Pressure sensor agreement tolerances (165C):** `barometric_pressure_sensor_tolerance`, `boost_pressure_sensor_tolerance` and `oil_pressure_sensor_tolerance` (0x407186, 0x407188, 0x40718a). The check is off in this calibration (`algorithm_enable_flags_6_cal` bit 0x20 clear) and all three tolerances read 0. Channel 38 behind the "oil" one has no sensor wrapper and reads 0, so oil comes from the e2m order, not from the channel.
- **Crank/cam block 8194, 7 rows:**
  - 0x408f56 `backup_consecutive_error_threshold`
  - 0x408f68 `primary_period_rpm_conversion_factor`
  - 0x408f78 `tooth_period_buffer_initial_engine_speed`. The old `crank_teeth_per_rev` was an initial speed, 120 x 0.125 = 15 rpm, and the code's ×8 supports that.
  - 0x408f84 `backup_pulse_period_timeout`
  - 0x408f8a `cam_wheel_pulse_count`
  - 0x408f9c `crank_preliminary_sync_evaluation_count`
  - 0x408fa0 `engine_speed_interrupts_per_cylinder`
  - "Backup" is the TPU-A channel 1 (cam signal) path, so I did not call it crank.
- **End-of-line test lamp override:** `end_of_line_test_malfunction_indicator_lamp_override_state` (0x40af0a) and `_flash_request_flag` (0x40af0b). The prefix is aligned with bin3 and "mil" is spelled out.
- **EEPROM-mirror `_cal` fixes:** 0x3fde48 `load_histogram_total_sample_count_cal`, 0x3feb8e `j1939_link_fault_timeout_count_cal`, 0x3fedfa `transmission_learned_information_stored_flags_byte_1_cal` and 0x3fedfb `output_speed_to_vehicle_speed_ratio_learned_flag_cal`. For 0x3fedfa, the byte's only code users are the boot kernel's SCI routines; its application meaning comes from the table's address map.
- **Single renames:**
  - 0x3fd510 `calibration_download_security_key_cal`. The 0xFF value bypasses the six seed/key checks.
  - 0x40aeb0 `low_speed_governor_alternator_load_fuel`. This is LSG Alternator_Load; the e2m LSG_EVR_Gain / LSG_EVR_Offset cals sit at its inputs.
  - 0x40af07 `warm_up_cycle_condition_flags`
  - 0x40a404 `engine_volumetric_efficiency`
  - 0x40b778 `cylinder_cutout_test_mask`
  - 0x409082 `equivalent_throttle_vacuum_all_speed_governor_offset`. The e2m's own Vac_Throttle_* records define "vac" as the vacuum throttle actuator.

**Keeps (20), listed so you can override:** 0x3fd4b2, 0x40ae6c, 0x40ae6e, 0x40afaa, 0x40b99e, 0x40a532, 0x40ba62, 0x40b886, 0x40b88c, 0x40b766, 0x40b784 and the four PCI rows 0x40b38e, 0x40b3a5, 0x40b3bc, 0x40b3bd are plain synonyms. The generic ones I left alone:
- 0x40af06 `fault_aging_triggered_flag` is Drive_Cycle, next to a renamed Warm_Up sibling. An option is `drive_cycle_completed_flag`.
- 0x40b78c `injection_quantity_scale_factor` is the speed limp home derate. An option is `speed_limp_home_fuel_derate_scale`.
- 0x408fa2 `cylinder_event_count_max` is Engine_Cylinders. An option is `engine_cylinder_count`.
- 0x40b780 `cylinder_cutout_mask` is Bank_Cutoff.
- 0x40b891 `fuel_pressure_feedback_previous` is the governor's copy of the filtered feedback.

**Drift**
- **0x40b9a2:** e2m 1632 +4 BIR_Ratio resolves here, but the code holds the coolant-sensor monitor's pass counter, next to `cssc_coolant_temp_span` and `engine_cssc_coolant_state`. Block 1632 ends after +2 in this build. I left the name; `cssc` is an invented abbreviation, so the whole family wants one rename (see leads).
- **0x40b55e:** the bin's record 8C56 +4 Gov_Press_Rat_Ratio is drift, but the table also resolves 8C58 +0 RE_Governor_Pr_Zero_Rat_Fails_This_DC to this address and the code matches that one, so I renamed from it. Say so if you would rather treat it as plain drift and keep `protection_coldStart_channelA_trip_count`.
- **Pattern:** every in-use "ratio" record I hit is the last record of its block and has no storage of its own here. BIR_Ratio, Gov_Press_Rat_Ratio and PN_Ratio (8C5B +A, which resolves to 0x40b57a, a bin5 row; I documented the TCC record there) land on another variable's address. TCC_Ratio (8C34 +16, 0x40b590) lands inside the dword `governor_pressure_error`. Gov_Press_Control_Ratio (8C58 +12) lands on the next block's first word, `park_neutral_switch_monitor_state`.
- 8C34 +12 / +14 (0x40b58c `protection_throttle_velocity_term`, 0x40b58e `governor_pressure_error`) probably drift too: the governor pressure solenoid loop uses them, not TCC / OD timers.

**Function names the evidence shows are wrong (not applied)**

| Address | Current | Proposed | Reason |
|---|---|---|---|
| 0x5341a8 | `engine_coolantTemp_overheat_monitor` | `cm848_monitorWarmUpCycle` | Sets the OBD warm-up bits: rise over 40 F and above 140 F. At 3 it counts a cycle and auto-clears the fault ring. No overheat check. |
| 0x50ddb4 | `diag_suppress_stateMachine` | `cm848_setEndOfLineTestMalfunctionIndicatorLampOverride` | It is the in-plant end-of-line test's lamp override states 0-3. |
| 0x29f54 | `cm848_checkSensorDeviationFlags` | `cm848_checkPressureSensorAgreement` | Compares barometric pressure with two other pressure readings using the three tolerances. |
| 0x1359c | `cm848_processBoostControlState` | `cm848_updateChargePressureInRangeFaultCount` | It is the up/down fault counter that sets and clears fault 527. |
| 0x12ad4 | `cm848_boostBasedFuelModifier` | `cm848_calculateVolumetricEfficiency` | It computes the clamped volumetric efficiency and the pressure-ratio terms, not a fuel modifier. |
| 0x50638c | `cm848_outputs2_periodic` | `cm848_updateLoadHistogram` | It is the duty cycle monitor histogram, every 0.1 s. |
| 0x51ba6c | `cm848_pidError_calc` | `cm848_calculateConverterClutchRatioDelta` | Previous ratio minus ratio, not a PID error. |
| 0x51ba1c | `cm848_pidIntegrator_accumulate` | `cm848_accumulateConverterClutchRatioDeltaSum` | Sums those deltas. |
| 0x457d0 | `mpc555_updateEngineCrankState` | `mpc555_handleCamSignalInterrupt` | Weaker lead: it is the TPU-A channel 1 handler, and e2m PMA_Edge_Type (channel 1) says cam signal. |

`cm848_throttleBasedFuelCalculation` (0x128a0) also reads as the charge flow / EGR fraction model, but I have no proved name.

**Sibling leads outside the bin (not in my output)**
- **8015:** the window dword 0x4094be `engine_sync_prot_scale_b_cal` holds two signed words, +205 and -204. Split it into positive and negative window widths. 0x4094ae `engine_sync_prot_scale_a_cal` holds the same values for the proportional gains.
- **LSG_EVR cals:**
  - 0x4070e0 `governor_speed_filter_input_scale_cal`, e2m 1064 +2A LSG_EVR_Gain
  - 0x4070e2 `governor_speed_filter_fuel_offset_cal`, +2C LSG_EVR_Offset
  - 0x4070e4 `governor_speed_filter_coefficient`, +2E Alternator_Load_Filter_Coefficient
  - 0x3faf56 `governor_speed_filter`, the filter state

  The first two carry a wrong `_cal` in RAM; a family like `low_speed_governor_alternator_*` fits all four.
- **1A2C / 1A2D:**
  - 0x4051e0 `fuel_demand_step_min_threshold_cal` becomes `charge_pressure_in_range_fault_clear_threshold`
  - 0x4051e2 `fuel_demand_step_decrement_cal` becomes `charge_pressure_in_range_fault_count_decrement`
  - 0x40a42e / 0x40a430 / 0x40a432 / 0x40a434 / 0x40a436 are Charge_Press / Source / State / IR_Cond / IR_Enable and are named `map_*`, `fuel_*` and `boost_*`.
- **8C33 / 8C34 leftovers:** 0x408ad2, 0x408ad3, 0x408ade, 0x40b57d, 0x40b57f, 0x40b58b and the monitor's snapshot words still read `protection_*`. In the same order they are fail count limit, minimum ratio delta sum, overdrive rationality time, ratio delta, monitor state, third lockup flag.
- **`cssc_*` family:** 0x40b9a2, 0x40b9a4, 0x40b9a6, 0x3fd18a-0x3fd190 should become `coolant_temperature_sensor_performance_*`. The drifted row would be `coolant_temperature_sensor_performance_monitoring_cycle_count`.
- **165C / 177D:** 0x40718c `cold_start_sensor_deviation_delay_cal` has a wrong `_cal`, and `iat_sensor_deviation_flags` (0x3fe9be) says iat for pressure flags. `governor_integrator_bound_a` / `_b` (0x40bb8a / 0x40bb3c) are sensor channels 77 and 38. 0x400940 / 0x400942 `fuel_demand_rpm_factor_upper_cal` / `_base_cal` are the volumetric efficiency clamps (1.0 / 0.8) with a wrong `_cal` in RAM.
- **8194 backup/primary pairs:** 0x408f80 `crank_sync_period_confirm_count_cal` (Main_Consec_Error_Thres), 0x408f82 `crank_period_raw` (Maximum_Pulse_Period_Timeout) and 0x408f6c `crank_tooth_rpm_divisor_cal` (the backup speed constant) should pair with my primary/backup names.
- **Cross-bin mismatch:** bin6 renamed 0x40b798 to `crank_tooth_period_countdown`, the reload target of my `backup_pulse_period_timeout` and part of the same channel 1 backup path. `backup_pulse_period_countdown` would pair better; please reconcile.
- **11C1:** 0x3feb8c `etc1_state_timeout_counter` is e2m J1708_Link_Fault_Timeout_Count, and 0x3feb90 `etc1_fuel_demand_high_limit` is TSC_Lost_Max_Throttle_Disable. Both sit in the EEPROM mirror without `_cal`; 0x3feb8c would become `j1708_link_fault_timeout_count_cal`.

**Type remarks (types unchanged)**
- 0x40aeb0, 0x40b897 and 0x40b583 are signed with `lha` accesses, so `i16` would fit.
- The `word` row at 0x408f56 swallows the byte at 0x408f57, e2m +1 Bank_With_Added_Tooth, which already has a typeless label `crank_sync_reference_flag_cal`. It should be a byte row plus a byte row at 0x408f57. Until then the `(byte)` reads of the second byte render under my new name.