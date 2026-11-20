Wave 13 bin 4 is done: 63 lines, one per record, in /home/linux/.claude/jobs/f6a06670/tmp/fueling_state/stage8/result_W13_bin4.jsonl. The repo gate was not run (see "Gate not run"); my hand copy of its checks passes.

**Counts:** 21 rename (verdict confirmed), 42 keep, 0 drift, 0 uncertain.

**Families renamed** (each comment leads with the e2m record, then the code role):
- Data collector: 0x3fddb8 `diag_dm1_protection_warning_active` -> `data_collector_trigger_active_cal`. It is in the EEPROM mirror, so `_cal`.
- System switch status, e2m 1092: `diagnostic_fault_flags_a` / `_b` -> `system_switch_status` / `_2`. The dump reads 0x60 (accelerator at idle plus key on).
- J1939 source addresses, e2m 10E3 +4 / +6 / +8: `j1939_tsc1_*_sa` -> `j1939_transmission_source_address`, `j1939_anti_lock_brake_source_address`, `j1939_anti_slip_regulation_source_address`.
  - Independent proof: e2m 117D +14 orders the devices TRANS / ABS / ASR / UNKNOWN as 1 / 2 / 3 / 4, which is what `cm848_lookupJ1939SourceAddressIndex` returns.
- Non-continuous monitors: 0x5a494 `j1939_feature_config_word` -> `supported_non_continuous_monitors_bits` (see drift below).
- EGR orifice, e2m 19CA / 1A19:
  - `throttle_trim_predictor_output` -> `egr_orifice_temperature_after_lead`.
  - `throttle_trim_predictor_gain` -> `egr_orifice_temperature_lead_time_constant`.
  - `boost_fuel_correction_prev` -> `egr_orifice_delta_pressure`.
- Fuel pressure governor proportional gains, e2m 8014: `injection_timing_scale_cyl1_a_cal`, `cyl2_a_cal`, `cyl3_a_cal` -> `fuel_pressure_governor_proportional_gain_small_signal`, `_positive_large_signal`, `_negative_large_signal`.
  - Proof: they are the gain block of `cm848_applyPiecewiseLinearGain`. The window words at 0x4094ae read +-10 MPa. Each gain has its own e2m 8005-800A scaling curve.
- Injection scheduler, e2m 805C / 805E:
  - `injection_timing_tooth_base_offset_mode2` -> `injection_timing_tooth_base_offset_cylinder_0`. 'mode2' is wrong because both scheduling paths use it.
  - `injection_tpu_timing_mode` -> `injection_tpu_period_parameter_address`. The values 2 and 0x12 are the low bytes of 0x304102 / 0x304112, which are TPU-A channel 0 / channel 1 parameter 1.
  - `cam_sync_position_high_byte` -> `injection_timing_tooth_separation_per_cylinder`. It is tooth count / cylinders = 120 / 6 = 20.
- Singles:
  - `fuel_demand_cmd20_pending_flag` -> `duty_cycle_monitor_map_reset_pending_flag`.
  - `protection_temp_scale_factor` -> `rear_axle_ratio` (dump 453 = 3.54).
  - `governor_speed_engage_reset_flag` -> `ecm_power_down_delay_request_flag`.
  - `fuel_demand_enable_sync_flag` -> `cruise_resume_active_flag`.
  - `map_fuel_correction_multiplier_cal` -> `engine_displacement_cubic_inches` (359.2 cu in). The old `_cal` was wrong.

**Drift found**
- 0x5a494: the labelled record, e2m 10E3 +28 DDT_TSC_ASG_Filter_Slew_Rate, is the 11.45 e2m's shifted tail. The record that also resolves there, 1228 +8 Supported_Non_Continuous_Monitors, matches the DM5 / DM10 / DM7 code. This line is a rename taken from the 1228 record, so the caller can downgrade it to leave-as-is.
- No drift in 10E3 +4 / +6 / +8, 117D, 805C / 805E, or 8A12. For 8A12 I checked all seven timer / status pointers against the PCI descriptor tables.

**Function names the evidence shows are wrong** (not applied)

| Address | Current | Proposed | Reason |
|---|---|---|---|
| 0x00505c20 | `diag_dm1Buffer_circularFill` | `cm848_fillDataCollectorRingBuffer` | fills the data collector ring buffer, not DM1 |
| 0x00505f98 | `cm848_phase_groupB_calculation` | `cm848_runDataCollector` | the collector pass |
| 0x00505d94 | `hpcr_exception_process` | `cm848_resetDataCollector` | resets the collector, called at start-up by `cm848_applicationMain` |
| 0x00505df0 | `j1939_dm1_diagnosticMessage_send` | `cm848_sendDataCollectorBuffer` | sends the collector buffer by transport protocol in stop mode 3 |
| 0x0050638c | `cm848_outputs2_periodic` | `cm848_updateDutyCycleMonitor` | the duty cycle monitor load histogram |
| 0x0004272c | `cm848_applyProtectionControlLimit` | `cm848_selectTwoSpeedRearAxleRatio` | selects `rear_axle_ratio` |
| 0x00042770 | `cm848_setProtectionControlValue` | `cm848_selectSingleSpeedRearAxleRatio` | loads `rear_axle_ratio` from the EEPROM word |
| 0x0003e210 | `cm848_setFuelDemandActiveFlag` | `cm848_requestPowerDownDelayWhileMoving` | sets the power-down delay flag |
| 0x00529ea4 | `cm848_sensor_diagnostic_flag_update` | `cm848_initializeInjectionAngleScheduler` | sets state 1, TPU address 2, channel 6 and the tooth separation |
| 0x00506f88 | `sensor_channel108_filter` | `cm848_applyEgrOrificeTemperatureLeadCompensation` | channel 108 is the EGR orifice temperature sensor |
| 0x00507028 | `sensor_throttleTrim_ema_faultProcess` | `cm848_filterEgrOrificeTemperature` | same |
| 0x0050716c | `sensor_throttleTrim_inputSelect` | `cm848_selectEgrOrificeTemperature` | same |
| 0x00017f50 | `cm848_calculateFuelFlowWithMode` | `cm848_calculateEgrDeltaPressures` | writes the orifice / valve / engine delta pressures |
| 0x0001242c | `cm848_calculateLoadBasedFuelTrim` | `cm848_calculateEgrOrificeFlowTerms` | medium confidence; its inputs are the EGR orifice delta pressure ratio, valve position and orifice temperature |
| 0x00012cf4 | `cm848_loadBasedFuelAdjustment` | `cm848_calculateChargeMassFlow` | speed-density charge flow |
| 0x00525e54 | `protectionTimeoutControl` | `cm848_estimateDrivetrainRatio` | it is the drivetrain ratio estimator |

**Out-of-bin siblings** (summary only, no lines written)
- Cruise resume: `fuel_demand_enable_sync_flag_shadow` (0x3fb528) and `_shadow_2` embed the old name.
- Axle ratio, e2m 1180:
  - `protection_temp_scale_cal` (0x3fd534) is Rear_Axle_Ratio_High, so `rear_axle_ratio_high_cal`.
  - `protection_temp_scale_factor_working` (0x3fd52e) is Rear_Axle_Ratio_Low, so `rear_axle_ratio_low_cal`.
  - `protection_trim_divisor_cal` / `_working` are the timing period times those two.
- EGR 1A19: `boost_fuel_mode_state` (0x40a626, EGR_Orifice_Delta_Press_Source) and `fuel_demand_enable_state_cached` (0x40a62e, Engine_Delta_Press_Source).
- EGR orifice temperature: `throttle_trim_predictor_gain_lookup` (0x3fbcf8) and `throttle_trim_predictor_output_min` (0x406776).
- 177C charge flow: the rest of 0x400932-0x400948 (C_CHP_* words) carry `boost_*` / `fuel_*` names, several with a wrong `_cal`.
- 8014 and 8005-800A:
  - `engine_sync_prot_scale_a_cal` (0x4094ae) is a dword over the two window widths, with a junk `+2` label row.
  - `injection_timing_scale_cyl4_a` / `cyl5_a` / `cyl6_a_cal` are the integral gains.
  - `cam_sync_cyl1-3_timing_{axis,values}_a_cal` (0x40918a, 0x4091a0, 0x4091b6, 0x4091cc, 0x4091e2, 0x4091f8) are the HPCR_SF_Propcomp curves.
  - `cam_timing_alt_mode_enable_cal` (0x4090fa) is HPCR_Governor_Mode.
- Remaining `diag_dm1_*` collector rows: 0x40c270-0x40c284, 0x3fbca6-0x3fbcb8, 0x3fddba (Collector_Stop_Mode), 0x3fddc4 (Collector_Table).
- Struct `fault_entry_t`: fields `diagnostic_fault_flags_a` / `_b` have stale "Sensor scale factor" comments.
- `protection_enable_byte_35` (0x40c085) is byte 5 of `logical_output_request_bits`, requests 40-47.
- `governor_startup_threshold` (0x40a2c4) is e2m 117D +5C ESP_Tau.
- 81C9 cutout: the four kept `cylinder_cutout_*` rows act on one injector bank (masks 0x55 / 0xaa, three cylinders each), and the e2m says bank. I kept them because the rest of the `cylinder_cutout_*` family is outside my bin. Rename the whole family if you want the bank wording.
- 8A12: the e2m calls message $98 an Rx message, but the PCI tables list it as TX[12].

**Type notes**
- Renamed rows: 0x40a2b4 is a dword accessed as a halfword (should be word). 0x40a624 is a word read signed (i16). 0x3fddb8 is a word but e2m signed with lha reads (i16).
- Kept rows: 0x40b05c is a dword read as a word. 0x40b9e0 is a word used signed.

**Gate not run:** the repo's `apply_renames.py` was denied by the permission system, so I did not retry it. A hand copy of its rules (banned words, name format, `_cal` rule, no existing name, one CSV row per address with a matching old name) shows no PROBLEM lines. New names do not collide with the result files of bins 1, 3, 5 and 6; bin 2 had no result file when I checked.

**Scratch folder to archive:** /tmp/w13_bin4 (spec.py, build.py, gate_check.py, collide.py, peek.py, show.py).