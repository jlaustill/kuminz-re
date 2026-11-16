# 042 — Rename leads from the table-naming campaign (CM848)

**Type:** implementation (naming / readability)
**Source:** PR #50, 2026-11-16. Twenty agents named 519 lookup tables. Each traced its tables' inputs and
outputs and recorded the misnamed functions and variables around them. These are **leads, not verified
renames**: check each against the code (and `xref_addr.py` / the disassembly) before renaming, per the
`review-function-readability` skill. Where two agents agreed independently, it says so.

## Functions (what they compute)

| Function | What the code does | Evidence |
|---|---|---|
| `cm848_auxiliary_boundary_condition_eval` | auxiliary (third, post-main) injection timing | two independent agents (bin 02 A / B) |
| `cm848_calculateGovernorOutput` | auxiliary injection quantity limit (`crank_sync_threshold` is its output) | bin 03 |
| `cm848_torque_limit_state_update` | pilot injection quantity (capped at half the fuel demand) | bin 00, RAM-dump reproduction |
| `cm848_calculateEngineTimingData` | main injection timing (`torque_limit_fault_snapshot`, PGN 65504) | bin 05, RAM-dump reproduction |
| `engine_injectionTiming_arbitration_calc` | an injection timing offset added to the main timing (which event: open) | bin 01 |
| `cm848_sensor_channel_state_load` | rail pressure setpoint (`fuel_pressure_setpoint`) | bin 04, RAM-dump reproduction |
| `cm848_calculateTimingWithTables` / `cm848_calculateEngineFaultTiming` | main / auxiliary injector on-time | bin 09 |
| `cm848_calculateEngineTimingInterpolation` | pilot injector on-time | bins 00 / 13 |
| `engine_camTiming_positionCorrection_calc` | fuel-metering feedback monitor (fault bit 60 = P1223) | bin 06 |
| `cm848_processEnginePositionDiagnostics` / `engine_camSync_referenceCheck_update` | rail pressure diagnostics (fault bit 303 = P0088) / a no-injection pressure check (fault 58 = P1222 - verification corrected the P0088 pairing for engine_camSync_referenceCheck_update) | bins 07 / 13 |
| `cm848_boostCompensatedRpmGovernor` | wastegate duty: `rpm_governor_state_t.desired_rpm` / `lower_rpm_limit` / `commanded_rpm` are duty / 2 (12800 = 100 %) | bin 07 |
| `hpcr_fuelDemandProc` | electronic wastegate monitor (pass window) | bin 10 |
| `cm848_filterProtectionOutput` | 4-state charging-voltage (alternator field) regulator | bin 08 |
| `hpcr_injectPressureTuning` | intake air heater performance test (P2609) | bin 17 |
| `j1939FormatMultiFrameResponse` / `cm848_calculateSpeedControlError` | TSC1 retarder request quantizer / ERC1 byte 2 builder | bin 12 |
| `cm848_calculateFuelTrimValues` | governor PID gains | bin 12 |
| `cm848_calculateFuelTimingBlend` (+ `fuel_timing_blend_factor`) | a drivetrain-ratio (gear) blend of two governor tunings | bins 10 / 12 |
| `cm848_fuelTimingRateLimitedBlend` | an engine-speed blend, not injection timing | bin 15 |
| `protection_fuel_demand_limiting` | rail-pressure-shortfall fuel quantity limiter | bin 18 |
| `governorCruiseTimerManagement` | weighted-fuel / distance / power accumulator, maybe a service-interval monitor (unverified) | bin 11 |
| `cm848_processProtectionCoolantLookup` | reads battery temperature | bin 15 |

## Variables

- **Injection quantities and on-times are swapped by name:** `engine_timing_reference*`, `engine_timing_delta`,
  `cam_timing_reference_offset` hold fuel quantities; `fuel_quantity_active`, `fuel_quantity_table_result`,
  `fuel_quantity_trim`, `injection_timing_active_flag` hold on-times (bins 00 / 09 / 13).
- `torque_limit_fault_snapshot` = the main injection timing (bins 02 / 05). `torque_limit_demand_output` = the pilot quantity.
- `boost_map_index_current` / `_target` = blend table numbers 1..4 (several bins).
- `fuel_pressure_sensor_reference` = barometric (ambient) pressure reference, capped at 30 inHg (bins 08 / 10 / 11).
- `governor_adjustment_input` = altitude in feet; `governor_adjustment_rpm_axis_cal` is an altitude axis (bins 07 / 08; the altitude table matches the standard atmosphere).
- `sensor_channelGeneric_*` = the coolant temperature channel (slot 2); `fuel_demand_boost_input` = that coolant value (bins 17 / 18).
- `sensor_channel9_pressure_value` / `_default_value` = intake manifold temperature (bin 16).
- `governor_torque_output` (0x40bb00) = the remote accelerator pedal position (bin 16).
- `cruise_speed_current_a` / `_b` (0x40bbb2 / 0x40bbb4) = the two accelerator pedal tracks (bin 15).
- `battery_voltage_prev` (0x40b26e) = the charging voltage target (bin 15).
- `fuel_timing_sensor_value` = slot 4 = battery voltage (P0563 / P0562); `governor_speed_input_value` = slot 75 (sensor unknown).
- `cruise_state_machine_index` / `cruise_prev_state_index` / `cruise_voltage_*` = the alternator regulator state (bin 08; task 029).
- `protection_iat_scaled`, `governor_cold_start_iat_correction`, `iat_fuel_trim_*` use barometric pressure, not intake air temperature (bins 12 / 14).
- `fuel_correction_upper_limit` = a maximum fuel quantity limit; `timing_limit_lower` (ROM 0x5c306 = 5888) is its no-limit value (bin 09).
- `cold_start_*` / `fuel_coldStart_*` at 0x5139b8-0x513ddc = a coolant-overheat derate (bin 14).
- `injection_timing_factor_cyl2/3/4_*` / `injection_timing_demand_cyl*` = the intake-temperature / coolant / boost / barometric components, not cylinders (bin 05).

## Duplicate names in global_variables.csv

- `fuel_demand_offset_correction` at 0x0040a550 and 0x0040b22a (bin 13).
- `sensor_channel7_fault_status` at 0x0040be18 and 0x0040be3a (bin 16).

## Vocabulary the table names follow (change them together)

- `cold_start_*`: the table names follow `cold_start_phase`. Bin 05 found that the phase machine steps on rpm only
  (no coolant condition), so "cold start" may be a misnomer for an engine start / run-up machine. If
  `cold_start_phase` is renamed, rename `injection_timing_main_cold_start_*`, `injection_timing_offset_cold_start_*`,
  `fuel_pressure_setpoint_cold_start_*` and the other `cold_start_*` tables with it.
- `auxiliary` (the third injection event) is used for the tables next to the legacy `injection_timing_aux_*`
  variables. If the event is confirmed to be a post injection, rename both together.

## Tables left unnamed (45)

Their lookups were skipped: an input of unknown units, an untraced output, or a flat / all-zero table with no
shape. Each skip reason (and every named table's evidence) is in
`firmware/CM848_S90140.06_analysis/docs/table_naming_campaign_2026-11-16.csv`; re-run the naming for a lookup
once its input or output is named.

## DONE 2026-11-16 (PR #50): verified and renamed

Five read-only agents verified the leads above against the code (RAM-dump reproductions where possible); every lead held. Applied: 27 function renames (new plate comments), 234 global renames (each comment now starts with the evidence and `(was <old>)`), 3 new rows for unnamed words, and 89 table renames that follow the new family vocabulary (`injection_timing_offset_*` -> `injection_timing_pilot_offset_*`, `pilot_quantity_*` -> `injection_quantity_pilot_*`). Proof: mapping every new name back to its old one gives back the previous .cpp (plate comments aside; three functions only reorder their declarations).

### Functions

- `cm848_calculateAllSpeedGovernorNoLoadFuel` (was `cm848_calculateFuelTimingBlend`, 0x0000fcd0)
- `cm848_calculateAlternatorFieldDutyByRegulatorState` (was `cm848_filterProtectionOutput`, 0x00037744)
- `cm848_calculateAuxiliaryInjectionPulseWidth` (was `cm848_calculateEngineFaultTiming`, 0x00047394)
- `cm848_calculateAuxiliaryInjectionQuantityLimit` (was `cm848_calculateGovernorOutput`, 0x000466a8)
- `cm848_calculateAuxiliaryInjectionTiming` (was `cm848_auxiliary_boundary_condition_eval`, 0x005279d8)
- `cm848_calculateChargingVoltageTarget` (was `cm848_processProtectionCoolantLookup`, 0x000375c8)
- `cm848_calculateEngineRetarderTorque` (was `cm848_calculateSpeedControlError`, 0x00021314)
- `cm848_calculateFuelPressureSetpoint` (was `cm848_sensor_channel_state_load`, 0x00529f58)
- `cm848_calculateGovernorCompensatorCoefficients` (was `cm848_calculateFuelTrimValues`, 0x0000ff04)
- `cm848_calculateGovernorReferenceSpeedBlend` (was `cm848_fuelTimingRateLimitedBlend`, 0x0000e8dc)
- `cm848_calculateMainInjectionPulseWidth` (was `cm848_calculateTimingWithTables`, 0x00046f7c)
- `cm848_calculateMainInjectionTiming` (was `cm848_calculateEngineTimingData`, 0x0004ae20)
- `cm848_calculatePilotInjectionPulseWidth` (was `cm848_calculateEngineTimingInterpolation`, 0x00047140)
- `cm848_calculatePilotInjectionQuantity` (was `cm848_torque_limit_state_update`, 0x0052ba30)
- `cm848_calculatePilotInjectionTiming` (was `cm848_pressure_control_state_load`, 0x0052d140)
- `cm848_calculatePilotInjectionTimingOffset` (was `engine_injectionTiming_arbitration_calc`, 0x0052c780)
- `cm848_calculateWastegateDutyRequest` (was `cm848_boostCompensatedRpmGovernor`, 0x00011ab4)
- `cm848_checkFuelPressureWithoutInjection` (was `engine_camSync_referenceCheck_update`, 0x0052acfc)
- `cm848_diagnoseFuelPressureGovernor` (was `cm848_processEnginePositionDiagnostics`, 0x00049264)
- `cm848_initializePilotInjectionQuantityState` (was `cm848_initialization_fault_state`, 0x0052c688)
- `cm848_limitFuelQuantityOnRailPressureShortfall` (was `protection_fuel_demand_limiting`, 0x00519e2c)
- `cm848_monitorFuelMeteringFeedbackAgainstGovernorDemand` (was `engine_camTiming_positionCorrection_calc`, 0x0052b32c)
- `cm848_monitorIntakeAirHeaterPerformance` (was `hpcr_injectPressureTuning`, 0x00532418)
- `cm848_monitorWastegateBoostPressure` (was `hpcr_fuelDemandProc`, 0x00537584)
- `cm848_selectEngineRetarderStagePercent` (was `j1939FormatMultiFrameResponse`, 0x000234a4)
- `cm848_setMainQuantityAndPulseWidthLimits` (was `cm848_selectGovernorFilterOutput`, 0x0004769c)
- `cm848_updateOilChangeMonitor` (was `governorCruiseTimerManagement`, 0x0051a878)

### Globals by family (count)

`fuel_pressure_*` 47, `injection_timing_*` 37, `injection_quantity_*` 34, `alternator_field_*` 15, `engine_retarder_*` 11, `main_injection_*` 9, `wastegate_monitor_*` 9, `intake_air_*` 9, `wastegate_duty_*` 9, `auxiliary_injection_*` 8, `pilot_injection_*` 8, `charging_voltage_*` 5, `fuel_metering_*` 4, `fuel_quantity_*` 4, `oil_change_*` 4, `governor_reference_*` 3, `fuel_blend_*` 2, `pilot_to_*` 2, `main_to_*` 2, `injection_pulse_*` 2, `governor_tuning_*` 2, `fuel_demand_*` 2, `total_injection_*` 1, `barometric_pressure_*` 1, `battery_voltage_*` 1, `barometric_altitude_*` 1, `fuel_rpm_*` 1, `sensor_channel75_*` 1

### Left uncertain (not renamed)

- `injection_timing_timing_mode_cal` (0x004090f6): Read in three places: state 2 of engine_injectionAngle_tpuChannel6EventHandler adds the main on-time (as an angle) to the third start angle when the value is nonzero, state 4 adds it when the value is 0 (opposite polarity), and cm848_calculateEngineFaultTiming subtracts the main on-time from the int
- `cam_sync_position_lower_threshold_cal` (0x0040951e): 30738 in the dump; flag 2 (fault 315, no OBD slot) is set when fuel_pressure_sensor is above it, so it is a second, higher limit (the old 'lower' is wrong) that cannot trip within the sensor's 3689-count range; its purpose is not clear. RAM copy of ROM: no _cal. No name proposed.
- `engine_position_diag_flags` (0x0040b8cc): Not the rail pressure flags (those are 0x3fb6e0): written by cm848_updateProtectionBitFlags, which I did not read, and read by the injection-angle cylinder selection / cut-out code, mpc555_evaluateProtectionSyncFaults and the three monitors as a 'no fault' gate. The same holds for protection_fault_s
- `protection_fuel_output_idle_cal` (0x004087fa): Behaviour is certain, the right name is not: it is read only in regulator state 0, where alternator_field_duty_target = this value, then forced to 0 unless fault_detected_bits_368_to_383 mask 0x1 is set (the state handlers return to state 0 whenever that fault is set). Value 0 in the dump. What faul

### Further leads, notes and type issues from the verification agents

- [G1a] Extra function verified as the consumer of lead 3: cm848_pressure_control_state_load (0x0052d140) calls engine_injectionTiming_arbitration_calc (or, if ROM flag 0x409e6e is set, takes the override DAT_00409e70 with source 7), adds the offset to torque_limit_fault_snapshot unless ROM flag 0x409e72 is set, and caps the sum at the earliest schedulable angle (DAT_0005fbb2 / 5 - tooth base offset - an rpm-proportional lat
- [G1a] Slot facts for firmware/CLAUDE.md and the TPU-channel wording: the three event angles are written by engine_injectionAngle_writeTpuEvent into TPU-A channel 5 parameter RAM (angle words 0x304154 / 0x304158 / 0x30415c = slots 4 / 8 / 12, on-time words +2); the channel 6 interrupt handler engine_injectionAngle_tpuChannel6EventHandler only schedules them. The angle argument is timing counts x -5: 0.1171875 deg / 5 = 0.02
- [G1a] Event order is now backed by the code and not only by sign inference: slot 4 timing = main + offset (pilot offset tables 81..490 counts, positive = earlier), slot 8 = main, slot 12 = main - retard (retard base map 0..143 counts). cm848_calculateEngineFaultTiming gives the third event an on-time only when it starts after the main event. Whether Cummins calls it a post injection is still open, so auxiliary stays. Cauti
- [G1a] Table family: the injection_timing_offset_* tables (bin 01: base_map, map_1..4, coolant / intake_temperature / barometric_pressure / boost angle and factor, cold_start) feed only the pilot injection timing offset, so they should be renamed pilot_injection_timing_offset_* together with the variables above if these are accepted. Not to be confused with injection_timing_offset_cal (0x3fd808, EEPROM range, correct _cal),
- [G1a] Struct and source-code notes (no struct rename proposed): torque_limit_arb_t_0040a2f6.source_priority is the winning-source code of the main injection timing (5 cold-start map, 7 fixed, 11 floor, 18 injection_timing_advance, 19 intake temperature, 20 coolant, 21 barometric, 22 boost, 23 governor-limit minimum, 24 working minimum, 29 / 30 mode variants, 31 constant); the other torque_limit_arb_t fields were not checke
- [G1a] Combination mode words (decimal): main timing injection_timing_select_mode_cal 0 = sum, 1 = highest, other = lowest (1 here); pilot offset mode word 0x409e74: 0 = sum, 1 = highest, 2 = lowest, 3 = the component of the same kind as the main timing winner (2 here); auxiliary mode word 0x409094: 2 = lowest, otherwise highest (1 here). The terms are candidates, not corrections, in the highest / lowest modes.
- [G1a] Observation: in the auxiliary timing function the override branch (ROM flag 0x409090) writes DAT_0040b842 (no reader found by xref_addr) and the source byte 7 and returns before writing injection_timing_aux_offset, so by the xrefs the override does not move the third event angle, whereas the auxiliary quantity function (cm848_calculateGovernorOutput) overrides its real output crank_sync_threshold.
- [G1a] Constants without rows: DAT_0005a48a (ROM word -171 = -20.04 deg) is a fixed timing reference used in the PGN 65504 byte, in delivery mode 3 and as the reference of the auxiliary timing when ROM flag 0x409096 is set. The unnamed pilot-chain factor words (0x40b972 coolant, 0x40b96a intake temperature, 0x40b964 barometric, 0x40b980 boost) and the input copies 0x3fd16a (coolant temperature), 0x3fd16c (intake manifold te
- [G1a] Checked and kept: injection_timing_auxiliary_boost_factor (0x40b84e, Q12 factor from the rpm x boost grid) and injection_timing_auxiliary_boost_component (0x40b852, boost angle x boost factor / 4096 clamped +/-1024) already say what they hold; injection_timing_rpm_axis (0x40b98a) and injection_timing_rpm_snap_active_flag (0x40b988) in the pilot offset function are also right.
- [G1a] Same wrong-domain names sit in the auxiliary QUANTITY chain in cm848_calculateGovernorOutput (not my lead, read from the code only): injection_timing_factor_cyl6_a (0x40b818) is the Q12 factor of injection_quantity_auxiliary_coolant_factor_grid, injection_timing_factor_cyl6_b (0x40b81c) the output of injection_quantity_auxiliary_coolant_limit_grid, injection_timing_demand_cyl6 (0x40b81a) their product / 4096, and inj
- [G1b] Cross-check source for all the proposals above: output/e2m_parameters.csv (Cummins Calterm parameter database for the same ECM family). Its consecutive blocks line up one-for-one with CM848 RAM: pilot variables 0x01806A00-0x01806A24 = CM848 0x40b938-0x40b95c (Pilot_Base_Fuel_Quantity, Pilot_Fuel_Quantity, cool corr factor / value / setpoint, Fuel_With_Hyst, RPM_With_Hyst, air temp, temp, ambient, Max_Pilot_Fuel, boos
- [G1b] Unnamed (DAT_) cells in the same chain, not in global_variables.csv, suggested names: 0x3fd07e pilot_quantity_unscaled_snapshot and 0x3fd080 auxiliary_quantity_unscaled_snapshot (written by cm848_fuel_demand_state_capture, read only by engine_injectionAngle_updateCutoutAndTimingDemand); 0x40908c auxiliary_quantity_ratio_limit (Aux_Quantity_Ratio_Limit, 2662 / 4096 = 0.65 of total minus pilot); 0x409e66 pilot_to_main_
- [G1b] More rename candidates beyond the 10-per-function cap, same evidence: 0x00409086 crank_sync_threshold_override_enable_cal -> auxiliary_quantity_override_switch; 0x00409088 crank_sync_threshold_override_cal -> auxiliary_quantity_override_value; 0x0040908e engine_sync_force_reset_cal -> auxiliary_quantity_speed_limp_home_switch (1 = auxiliary off during speed limp home, e2m Aux_Speed_Limp_Home_Switch; 0 in the dump); 0
- [G1b] Type note (no change proposed here): timing_limit_slew_q16 (0x3fd104) and timing_limit_arbitrated_target (0x3fd108) are typed word in global_variables.csv but cm848_torque_limit_state_update reads and writes them as dwords (Q16), which is the source of the 'Globals starting with _ overlap smaller symbols' warning and the leading-underscore rendering. torque_limit_timing_load_correction and governor_fuel_demand_limit_
- [G1b] crank_position_valid_flag (0x40b7d6) left uncertain: the pilot and auxiliary functions gate their zero output on it together with the Pilot_Speed_Limp_Home_Switch / Aux_Speed_Limp_Home_Switch cals (so it looks like 'running on the backup speed sensor / speed limp home'; mpc555_initEngineCrankSequence sets it to 1 while disabling TPU-A channel 0 and enabling channel 1), but it has 16 users in the crank state machines 
- [G1b] Snapshot neighbours (angle workers' area): cm848_fuel_demand_state_capture copies injection_load_snapshot (0x3fd082), injection_timing_pressure_snapshot (0x3fd084) and injection_timing_aux_offset_snapshot (0x3fd086) into injection_period_capture_a / cam_sync_period_reference_a / cam_sync_period_reference_b, which engine_injectionAngle_computeLoadCh6 multiplies by -5 into DAT_0040b871 / b873 / b87d = the main / pilot 
- [G1b] Event order and units verified: pilot (slot 4) < main (slot 8) < auxiliary (slot 12) in crank angle (the pilot and third-pulse tests both require the later start minus the earlier start to be positive); on-time unit 0.4 us per tick (e2m HPCR_Duration_*); the pilot-to-main interval and main-to-auxiliary interval globals are in 3.2 us counts (ticks >> 3). In the RAM dump (engine off) the interaction correction grids ma
- [G2] Fault decode (ROM 0x5985a slot table, then obd_dtc_code_table; fault n = word n / 16 bit n % 16): bit 57 (word 3 mask 0x200) = slot 162 = P1221, 58 (0x400) = slot 163 = P1222, 59 (0x800) = slot 158 (code 0000), 60 (0x1000) = slot 164 = P1223, 303 = slot 90 = P0088. The meanings of P1221-P1223 are not established. The other bits set by 0x49264 (290, 315, 316, 317, 323, 324) are slot 170: no OBD slot. 317 / 290 / 324 (
- [G2] Sibling function, not in my lead list: engine_camTiming_speedWindow_update (0x52a9ac) is the third monitor of this group (fault 57 = P1221). It is switched off in this calibration (byte 0x409aa0 = 0); when enabled, with engine speed within governor_speed_limit_output +/- 160 counts, vehicle_speed_copy 0, cold_start_phase at the governor setpoint, coolant 180-205 F and no related faults, it debounces (80 net passes) f
- [G2] Sibling functions: hpcr_register_state_save (0x52a910) is the init of the setpoint calculator (cam_timing_transition_state = 1, winning term code = 1, the 2-D lookup cache words 0x3fd0ca-0x3fd0e8 = 2): suggested cm848_initFuelPressureSetpointState (cam_timing_advance_table_interp_states 0x3fd0ca is the first of those cache words). cm848_calibration_group28_load (0x52b998) only calls the three monitors (suggested cm84
- [G2] hpcr_camTimingMonitor (0x531d34, its reset hpcr_camTimingReset 0x532208) is a rail pressure tracking monitor, not cam timing: each cycle it integrates (fuel_pressure_setpoint - fuel_pressure_feedback_previous) / the ROM divisor at 0x64420 into cam_timing_advance_accumulator (0x40b9d8) and, negated, cam_timing_retard_accumulator (0x40b9dc) via cam_timing_delta_per_cycle (0x40b9e0); above the ROM limits 0x6440e / 0x644
- [G2] Support code around cm848_processEnginePositionDiagnostics, names suspect: cm848_updateEngineDiagnosticCounters (0x49a54) holds the two debounce counters of the diagnostics and also the fuel metering feedback circuit check (faults 264 / 265, fuel_metering_feedback_fault_code); cm848_initEngineDiagnosticData (0x4a258) initialises these variables and the seven lookup cache words cam_sync_filter_init_state_0-6 (0x3fb6ce
- [G2] Setpoint calculator constants and flags without CSV rows (or with DAT_ names), suggested names: DAT_0040b8c4 fuel_pressure_setpoint_deadband_active_flag (1 below DAT_00409a82 = 12000 = 1500 rpm and DAT_00409a80 = 736 = 50 mm3 per stroke; write-only), DAT_0040b8c6 fuel_pressure_setpoint_rise_limited_flag, DAT_0040b8c8 fuel_pressure_setpoint_override_additive_flag (both write-only), DAT_00409a78 fuel_pressure_setpoint_
- [G2] Feedback monitor and check A / B variables left out of the rows above (all used only inside their own function), suggested names: 0x40b8e6 cam_timing_position_correction_effective -> fuel_pressure_governor_demand_residual_effective (41 here: DAT_00409aba nonzero replaces the residual); 0x40b8e8 cam_timing_position_correction_scaled -> fuel_pressure_governor_demand_threshold_residual_term (effective x gain / 41, clamp
- [G2] protection_fuel_demand_* family: only 0x40b52c, 0x40b52e, 0x40b530 and 0x3fcea8 (rows above) belong to the limiter. About twenty other protection_fuel_demand_* rows (_entry_threshold_cal, _l_threshold_cal, _l4_threshold_cal, _corr_*_cal, _status10 / _status80 thresholds, _snapshot_*, _threshold_derate*_interp_state, _exit_derate*, _limit_derate*, _prev, _tick_snapshot, _working, _correction) are used by other functio
- [G2] Type notes (not proposed as changes by me): 0x3fd0c6 (cam_timing_advance_slew_working) is a dword (8 lwz / stw) typed word, which is why the .cpp shows a leading underscore; 0x409530 is typed word but read as one byte (value 150); 0x409a6d (override value) is a word at an odd address; DAT_0040b8c0 is correctly a dword. engine_timing_arb_status_packed (0x40b932) = byte 0 torque_limit_arb_t_0040a2f6.source_priority, by
- [G2] Other readers of fuel_pressure_setpoint that I did not read, so their names are unverified: hpcr_setFaultActiveStatus (0x1e098 / 0x1e1ac), cm848_runOperatingModeSpeedGovernor (0xf75c), engine_protection_fuelCorrection_stateMachine (0x530e04), hpcr_injectSystemDiagnostic (0x536ee0). work/tasks/042 pairs 0x49264 and 0x52acfc with fault 303: only 0x49264 sets it. All three monitors (0x52a9ac, 0x52acfc, 0x52b32c) are in 
- [G3] struct rpm_governor_state_t (0x40a3ca) is the wastegate duty controller state, all in half-duty counts (12800 = 100 %, the output stage sends 2 x commanded_rpm = 25600): commanded_rpm = final request; desired_rpm = duty ceiling; lower_rpm_limit = duty floor; reserved_0c = ceiling grid lookup (wastegate_duty_ceiling_*: x engine speed, y engine_load_input_b); reserved_0e = floor grid lookup; adjustment_delta = ceiling 
- [G3] Dump numbers for the wastegate path: fuel_feature_control_flags = 0x11DC (mask 0x1000 set, output stage enabled); wastegate_duty_ceiling_grid and _floor_grid are flat 11532 (90.1 % duty) with a last row of 0 and both grid enable flags are 0, so the grids are unused; ceiling = 9600 x battery gain, floor = 128. cm848_applyWastegateSolenoidDuty output = 21792 (85.1 %) at 12.0 V, exactly 2 x (9600 x 4649 / 4096).
- [G3] Second reader of the wastegate duty request: rpm_governor_state_t.commanded_rpm is also read by cm848_calculateSpeedControlLimit (0x2ca14). It clamps the word with speed_control_rpm_upper_limit_cal (12800 = 100 % in half-duty counts) and, when governor_status_flags mask 0x4000 is set, into the window [fuel_control_setpoint_cal, 0x3200 - fuel_control_setpoint_cal] = [1856, 10944] (about 14.5 - 85.5 % duty), i.e. in th
- [G3] cm848_checkSpeedBandCondition (0x11a4c) is the integrator anti-windup of this controller: it sets throttle_acceleration_active_flag (integrator enabled) unless commanded_rpm is pinned at desired_rpm / lower_rpm_limit in the direction of the error. cm848_turboCompensationWrapper (0x1231c, phase group A) and mpc555_initTurboCompensationVariables (0x1233c) are its wrapper and init and should follow the rename (e.g. cm84
- [G3] Charging regulator chain, evidence from disassembly of the four state handlers (ROM 0x38338 / 0x38384 / 0x383f0 / 0x3844c) and the dump: next state 0 -> 1 when engine speed >= the threshold at 0x4087a8 or cold_start_phase = 3, and fault 368 clear; every state falls back to 0 when speed < the threshold at 0x4087a2 or fault 368 is set; 1 -> 2 when the duty reaches 25600 or battery_voltage_delta <= the threshold at 0x40
- [G3] Existing CSV comment to fix: alternator_field_duty_target (0x40b266) says it is 'filtered by cm848_filterProtectionOutput'; that function calculates the per-state duty and does not filter it. operating_mode_flags (0x3fd5ee) is inside the EEPROM mirror (EEPROM 0x16c) and has no _cal suffix; its bits seen here: 0x20 = charging PID enable, 0x200 = heater performance test enable, 0x400 = overboost monitor enable (value 0
- [G3] Unnamed ROM / RAM words in the wastegate monitor (no global_variables.csv row, so no rename proposed): DAT_00409fe0 = wastegate driver duty threshold (11520 = 45 %, e2m CWG_Driver_Duty_Cycle_Threshold), DAT_00409fe4 = high load threshold (19200 = 75 %, 1/256 % units), DAT_00409fe8 = minimum start battery temperature (1280 = 20 F, 1/64 F), DAT_003fd270 = monitor armed flag (byte, set in cm848_initAdaptiveControl), DAT
- [G3] hpcr_throttlePositionDiagnostic (0x53227c) is the arming step of the heater performance test, not a throttle diagnostic: it zeroes the sample count, ring index, hpcr_pressure_diag_reference_avg and hpcr_pressure_diag_sample_sum_state0, loads the dwell from DAT_0006442c, and sets the state to 0 only when the battery temperature and the intake manifold temperature agree within DAT_0006443a (a cold-soaked engine) and fa
- [G3] engine_protection_batteryLoad_check (0x53232c) is not a battery load check: it returns 1 and sets the heater test state to 6 (aborted) when intake manifold temperature is below DAT_00064432, any of fault bits 16..31 & 0x18 / 288..303 & 0x3c0 is set, battery voltage is outside 10-13 V (DAT_00064436 / DAT_00064434), or the heater is neither in preheat-on nor preheat-done. Suggested name: cm848_checkIntakeAirHeaterPerfo
- [G3] Array typing (a type change, so a note only): the forced-reading words are one per sensor slot, 2 bytes each, starting at 0x40bc80 (slot 4 = 0x40bc88 = battery_voltage_adc_forced_reading, slot 69 = 0x40bd0a = DAT_0040bd0a, the battery temperature slot read by cm848_sciCommand20Callback case 1); the matching override enables are bit (slot mod 16) of word (slot / 16) of diagnostic_service_dispatch_table starting at +72
- [G4] OUTSIDE THE LEADS, same chain: cm848_j1939BuildVehicleOperatingStatus @ 0x26238 builds ERC1 (PGN 61440: header 0xF000 from cm848_initJ1939SpeedControlMessage, source address j1939_source_address_b), not a vehicle operating status. Byte 1 = j1939_vehicle_op_status_byte (0x3fae08, retarder torque mode + enable bits), byte 2 = j1939_pgn61440_engine_load_byte (0x3fae09, its comment 'EEC2 engine percent load byte' is wron
- [G4] OUTSIDE THE LEADS: cm848_j1939SetupMultiFrameTransfer @ 0x2346c decodes TSC1 byte 4 (requested torque, -125 percent offset) to a retarding magnitude 0..100 (suggest cm848_decodeRetarderTorqueRequestPercent); cm848_j1939ProcessGovernorRequest @ 0x236f0 is the TSC1 handler for the retarder source address (suggest cm848_processRetarderTorqueRequest). The governor_* / j1939_governor_output_percent_* variables around cm84
- [G4] OUTSIDE THE LEADS: cm848_initJ1939BrakeRetarderBuffer @ 0x26480 and cm848_j1939SendDiagnosticStatusMessage @ 0x2641c serve PGN 65213 (fan drive FD1: duty 25600 * 5 >> 9 = 250 = 0.4 percent per bit), not a brake retarder.
- [G4] fuel_demand_config_flags (0x40c081, byte) is not a config word: it is byte 1 of logical_output_request_bits (0x40c080, outputs 8-15), an alias into that array (other readers: diagnosticMainStateProcessor, cm848_processTemperatureTrim, engine_protection_fuelCorrection_stateMachine). cm848_calculateSpeedControlError reads bits 3-7 (outputs 11-15) as retarder stage requests (inferred). Needs an alias / struct-field fix,
- [G4] lookupTableInterpolation's first argument is a per-lookup state word initialised to 2 (diag_service_slot_state_1..5, fuel_ema_mode_slot_state_1/2, diag_state_group3_a/b/c_state, diag_state_group4_*_state): the domain words in those names are wrong but they are just interpolation hints; not renamed here.
- [G4] governor_speed_scale_factor (0x40a258) behaves like the ASG droop (rpm per mm3/stroke at the reference speed; e2m ASG_Droop_Axis / ASG_Alt_Droop_Axis): cm848_calculateEffectiveFuelLimit uses fuel = governor_fuel_demand_reference + (filtered reference - speed) x 9813 / (8 x scale). governor_fuel_demand_reference is the ASG no-load fuel (e2m ASNLFL). speed_request_filtered is the UNfiltered reference (= speed_request_b
- [G4] Unnamed drivetrain-ratio blend tables used by cm848_calculateRpmLimitsFromProtection: ROM 0x5a9c4 (axis, 6 breakpoints after the length word: 1843 / 2458 / 3482 / 6144 / 10240 / 40960 = ratio x 2048) and ROM 0x5a9d2 (6 weights, all 128 in this ROM); candidates governor_tuning_set_blend_by_drivetrain_ratio_axis / _values.
- [G4] If the soot reading of 0x3fee3e is accepted, the table rows engine_power_accumulator_increment_axis / _values (ROM 0x5c902 / 0x5c918, the campaign's names) should follow, e.g. oil_change_monitor_soot_increment_by_fuel_rpm_offset_axis / _values; leave them alone if the neutral reading is chosen.
- [G4] Oil change monitor words that need dword splits or unnamed rows (type changes, so notes only): 0x3fee34 'sensor_initialization_sequence_count' dword = high word fault-event bits (|= 4 / 0x100) + low word 0x3fee36 weighted fuel counter (suggest oil_change_monitor_fault_event_bits_cal / oil_change_monitor_fuel_count_cal); 0x3fee3a 'sensor_validation_delta' is used as a dword = distance in pulses since the reset (oil_ch
- [G4] battery_voltage_correction_enable_cal is used inverted in cm848_processProtectionCoolantLookup (0 selects the temperature table, non-zero selects battery_voltage_correction_default_cal), so 'enable' reads backwards; the neighbours cm848_processProtectionVoltageOffset / cm848_dispatchProtectionOutputMode / cm848_filterProtectionOutput are the same charging-voltage regulator.
- [G4] Slot 75 (0x40be18 via cm848_sensorChannel7_*): its fault status is read by boost_pressureSource_faultSelect_update and governor_speedRamp_stabilityFlag_calc, which suggests a boost-pressure related sensor, so the governor_speed_input_value / _default_value names (0x40bd96 / 0x40bda0) on the same channel look wrong; unverified.
- [G4] Not renamed (insufficient evidence): fuel_timing_blend_accumulator (read in the PID loop of cm848_runOperatingModeSpeedGovernor, not a blend) and the fuel_trim_* family (fuel_trim_speed_active_flag / _upper_threshold / _lower_threshold / _decay_cal ...) around the same loop: they belong to the governor reference speed handling in mode 7, not to a fuel trim; needs its own pass.

Also still open from the list above: the struct fields (`rpm_governor_state_t.desired_rpm` / `lower_rpm_limit` / `commanded_rpm` are wastegate duty / 2), and `cold_start_phase` (see the vocabulary note).

### Review of the rename wave (2026-11-16)

- **Second pass:** `cm848_calculateAuxiliaryInjectionQuantityLimit` (the function's result caps
  `auxiliary_injection_quantity`; its terms are `injection_quantity_auxiliary_coolant_limit` / `_boost_limit`, like
  the tables), `cm848_calculateGovernorCompensatorCoefficients` (a bilinear-transform pole a and (a + 1024) / 2 -
  "PID gains" claimed more than the code shows), `fuel_pressure_governor_demand_limit_at_governed_speed` /
  `..._check_minimum_coolant_temperature` (governor mode 11 = governed speed, only probably idle),
  `oil_change_monitor_engine_power_accumulator_cal` (0x3fee3e: "soot" was only by elimination; the address is
  time-shared - the boot ROM uses byte 0 as its SCI diagnostic timeout counter).
- **Independence check:** 155 of the 234 renamed globals are used only inside the verified functions; the outside
  users of the rest fit their names (PGN 65504 sends `main_injection_timing`, the PCI fuel-used message reads
  `main_injection_pulse_width`, the charging chain uses `alternator_field_regulator_state`, ...).
- **Decoded:** fault 411 = P2609; `fuel_pressure_limp_home_active_flag` triggers = P0193 / P0192 / P0088 / P0251 +
  faults 264 / 265 (no DTC slot) + two fault reaction requests.
- **e2m block layout matches CM848 RAM by relative offset (verified for two blocks):** e2m Pilot_Fuel_Quantity /
  RPM_With_Hyst / Pilot_Fuel_State at 0x01806A00 + 0x02 / 0x0C / 0x1E = CM848 0x40b938 + 0x02 / 0x0C / 0x1E (same
  scales), and HPCR_Duration_Main_Injection / _Pilot1 / _Aux at 0x01805B00 + 0 / 2 / 4 = CM848 0x40b85c / 5e / 60
  (0.4 us). Names that lean on e2m words: the oil change monitor, the all-speed governor no-load fuel, the wastegate
  (CWG) monitor and G1b's quantity / on-time blocks.
- **CM550 shares three renamed names (cross-firmware links now broken; CM550 semantics not checked):**
  `crank_sync_threshold` (CM550 0x80707a), `fuel_timing_blend_factor` (0x80c9aa), `j1939FormatMultiFrameResponse`
  (0x2f632). Check the CM550 counterparts before renaming them to the CM848 names.
- **Duplicate names that predate this wave (not fixed):** globals `cruise_speed_setpoint_b`,
  `cruise_speed_target_working`, `engine_data_log_buffer`, `engine_data_log_read_ptr`, `fuel_demand_mode_code`,
  `fuel_demand_rate_output`, `fuel_demand_rpm_factor`, `governor_setpoint_table_ptr`, `governor_speed_error_delta`,
  `injection_timing_compensation_lower_cal`, `j1939_tsc1_active_flag`, `protection_confirm_counter_a` / `_b`,
  `switchD`, `USIU_PITR`, `USIU_RTCAL`; functions `cm848_addCoolantCalEntry`, `cm848_emptyStubFunction`,
  `cm848_processFaultIncrement`, `emptyStubFunction3`, `mpc555_updateSensorDiagnosticFlags`.
- Pre-existing underscore variants (dwords typed word in the ROM-to-RAM window): `_fuel_pressure_setpoint_offset_slewed`
  (0x3fd0c6), `_injection_quantity_pilot_slewed_q16` (0x3fd104).
