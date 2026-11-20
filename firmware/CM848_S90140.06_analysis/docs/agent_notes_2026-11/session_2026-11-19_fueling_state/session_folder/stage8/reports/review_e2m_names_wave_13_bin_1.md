W13 bin1 is written: /home/linux/.claude/jobs/f6a06670/tmp/fueling_state/stage8/result_W13_bin1.jsonl. It has 64 lines in bin order. The `old` names match global_variables.csv, and the 28 new names pass the apply_renames / gate_W12 name rules and appear nowhere else in the firmware tree. `git status` is clean.

## Counts
- 28 rename (verdict `confirmed`), 31 keep, 5 drift, 0 uncertain.
- Comment clipping: the comments run up to ~980 characters. The apply clips at 360-400, so only the e2m record and the role sentence survive. Raise the limit if the lead wants more.

## Families renamed
- `engine_speed_limit_droop_type_select_cal` (0x3fdd38)
- `data_collector_center_address` (0x40c27c)
- `accelerator_pedal_autozero_cal` (0x3fddaa)
- `fault_detected_bits_592_to_607` (0x3fe9be, was `iat_sensor_deviation_flags`)
- `throttle_100_fueling`, `throttle_100_fueling_low_horsepower_curve`, `throttle_100_fueling_without_programmable_power` (0x40a897 / 899 / 89f)
- `j1939_derated_fueling_at_point_4` / `_5` (0x5c356 / 0x5c358)
- `fuel_temperature_derate_precrank_error_flag` (0x40a74c)
- The road speed governor (RSG) droop words in two prefixes:
  - Values passed to the fueling code: `vehicle_speed_limit_fueling_bottom_droop_gain`, `_top_droop_gain` and `_top_droop_offset` (0x40b6b2, 0x40b6b8, 0x40b6ba).
  - Values computed by the governor: `road_speed_governor_bottom_droop_gain` and `road_speed_governor_top_droop_gain` (0x40b6b6, 0x40b6bc).
  - Another bin may hold the Cruise twins or block 1102, so the lead may need to reconcile the prefixes.
- `j1939_pgn65251_speed_points_request_flags` (0x40a732)
- `wastegate_duty_feedforward_term`, `wastegate_duty_proportional_term`, `wastegate_duty_compressor_outlet_temperature_derate_error_term` (0x40a3be / 3c2 / 3e6)
- `egr_mass_flow_estimate_maximum` / `_minimum` (0x4002e4 / e6). The old `lower` / `upper` meaning was swapped: 0x4002e4 is the ceiling.
- `stoichiometric_oxygen_fuel_ratio` (0x406004)
- `injector_driver_pull_in_duration`, `injector_driver_delay_duration` (0x4090a0 / a4)
- `fuel_pressure_governor_derivative_gain_small_signal`, `_positive_large_signal`, `_negative_large_signal` (0x4094c4 / c8 / cc)
- `cruise_resume_downshift_delay_timer` (0x40b0ac)

## Type flags (types not changed)
- 0x4002e4 and 0x4002e6 are signed (`lha`, e2m S): i16.
- 0x4094c4 / c8 / cc are 4-byte records read with `lwz`, but the rows are `word`. Retype to dword and remove the `_lo_cal` rows at 0x4094c6 / ca / ce. The apply tool should not carry that to-do into the comments.

## Drift
- **1930 +16 (0x3feebc, BTR_Numerator) confirms the known drift from +12 on.** The word is a 0/1 latch for the engine retarder selector switch (switch 12), set in `cm848_mainLoopMonitor` and gating the logical output 11 check (faults 41/42 = P0478/P0477). The name also breaks the rules: EEPROM mirror without `_cal`, and a bare `protection_b`. A later pass should rename it to `engine_retarder_switch_learned_flag_cal`.
- **8D14 from +2 is new drift.** +0 holds (0x40b0ac, renamed): it reloads 150 = 1.5 s, counts down in 4th gear with the cruise flag, and gates the 4-3 downshift request. +2, +4, +C and +E (0x40b0ae / b0 / b8 / ba) are 16-bit shift-prediction words of the 48RE transmission governor pressure code, not timers or a lamp. Their `protection_*` prefix is wrong for that code.
- **8C4E +6 OSS_Ratio and 8C58 +12 Gov_Press_Control_Ratio alias one word with 8C5B +0 RE_PN_Rationality_Status.** That word is `park_neutral_switch_monitor_state` (0x40b570). I used `keep` with the 8C5B note, which also names the bin's records. The lead can flip it to drift if the gate wants the bin's record.
- Everything else matched: 0004, 0008, 0034, 101A, 1036, 105A, 1080, 1104, 1152, 1187, 11A4, 12BB, 162E, 16A2, 174F, 177E, 1791, 17AC, 801A, 8041, 80EF.

## Notes for the apply
- The old comment on 0x40b0ac ("overtemp ... derate level 4") is wrong. Do not carry it as "earlier note".
- The keep note for 0x6456c duplicates the wave 12 comment, which already leads with that record. Skip appending it.
- For 0x40b6bc (`road_speed_governor_top_droop_gain`), the old name `cruise_ramp_rate_d_working` is a different address from the existing `cruise_ramp_rate_d_computed` (0x3fcff4).
- 0x40a899 and 0x40a89f rest on e2m labels plus code corroboration. The "ESP Tau 0" wording on 0x40a89f is not reproduced by the code and is left open in the evidence and comment.

## Out-of-bin siblings, same wrong names (not applied)
- 0x3fea22 `j1939_tsc1_mode_shadow` → `fault_registered_bits_592_to_607` (registered twin of word 37)
- 0x5c34e / 0x5c350 `protection_threshold_scale_cal` / `_base_cal` → `j1939_engine_speed_at_point_4` / `_5`
- 0x40b6b4 `cruise_speed_setpoint_c` → `vehicle_speed_limit_fueling_bottom_droop_offset`
- Cruise twins, with proposed names:
  - 0x40b698 `cruise_speed_reference_a` → `cruise_control_fueling_bottom_droop_gain`
  - 0x40b6ac `cruise_speed_reference_b` → `cruise_control_fueling_top_droop_gain`
  - 0x40b6ae `cruise_speed_offset_b` → `cruise_control_fueling_top_droop_offset`
  - 0x40b69a `cruise_governor_fuel_demand_lower_ramp_start` → `cruise_control_fueling_bottom_droop_offset`
  - 0x40b69c / 0x40b6b0 `cruise_ramp_rate_a_working` / `_b_working` → `cruise_bottom_droop_gain` / `cruise_top_droop_gain`
- 0x3fa8ae / 0x3fa8b0 `protection_mode_request_bit` / `protection_mode_request_initialized_flag` (same wrong prefix as 0x40a732)
- 16A2:
  - 0x40a3e0 `governor_pid_adjustment_output` → `wastegate_duty_first_error_derivative_term`
  - 0x40a3e2 `governor_trim_lookup_result` → `wastegate_duty_second_error_gain`
  - 0x40a3e4 `governor_rpm_correction_term` → `wastegate_duty_second_error_derivative_term`
  - The feedforward calibration source 0x3ffca6 `throttle_rate_integrator_cal`, and its `throttle_rate_*` cal siblings, also belong to the wastegate controller.
- 177E +6 / +A / +C: 0x4002e8 `throttle_conversion_scale_cal`, 0x4002ec `rpm_fuel_trim_select_cal` (upstream/downstream EGR flow model select), 0x4002ee `throttle_load_scale_factor_cal`
- 80EF: 0x4094c2 `engine_sync_prot_gain_cal` → `fuel_pressure_governor_derivative_gain_constant`; 0x4094d0 `engine_sync_prot_limit_cal` and 0x4094d2 `engine_sync_prot_gain_b_cal` → `fuel_pressure_governor_derivative_positive_window_width` / `_negative_window_width`
- 8041: `mios_pwm16..19_*_ref` and `tpu_ch14_period_base` still carry `ref`

## Function names the evidence shows wrong (not applied)
| Address | Current name | Proposed name | Reason |
|---|---|---|---|
| 0x0001f17c | `cm848_calculateFuelDemandWithTrim` | `cm848_calculateThrottle100Fueling` | stores the five e2m 105A Throttle_100 fueling values |
| 0x000173a8 | `cm848_fuelDemandOverrideHandler` | `cm848_learnAcceleratorPedalAutozero` | tracks the lowest pedal reading with the idle switch on and writes the EEPROM autozero |
| 0x00020c64 | `cm848_processJ1939RxMessage` | `cm848_setTorqueCurvePoints2And5AtDroopLineFueling` | takes a fueling in param_1 and sets curve points 2 and 5; handles no message |
| 0x00020d10 | `cm848_updateProtectionStateMachine` | `cm848_updateJ1939EngineConfigurationTorqueCurve` | fills the e2m 1102 Jcomm speed / fueling / torque points of PGN 65251 |
| 0x00021ac0 | `cm848_initUdsServiceHandlers` | `cm848_lookupJ1939FuelTableAtEngineSpeed` | returns the chi/alpha-interpolated `j1939_fuel_table` value at the engine speed passed; no UDS |
| 0x000127bc | `cm848_selectFuelTrimMode` | `cm848_selectEgrMassFlowModel` | clamps the EGR mass flow estimate (`throttle_fuel_trim_t.final_trim`) |
| 0x000125f4 | `cm848_calculateRpmBasedFuelTrim` | `cm848_calculateEgrMassFlowUpstreamModel` | feeds that EGR estimate; selected by `rpm_fuel_trim_select_cal` = 0 |
| 0x0001242c | `cm848_calculateLoadBasedFuelTrim` | `cm848_calculateEgrMassFlowDownstreamModel` | feeds that EGR estimate; selected by `rpm_fuel_trim_select_cal` != 0 |

Cluster lead, no names proposed: `cm848_protectionScaledLimitCalculation` (0x320e0), `cm848_protectionRateOfChangeCalculation` (0x32250), `cm848_calculateProtectionFuelDemandThreshold` (0x3241c) and `cm848_processProtectionStateFlags` (0x3257c). They are 48RE shift / governor pressure code (`transmission_current_gear`, `transmission_output_speed_change`, `governor_pressure_target`), not protection.