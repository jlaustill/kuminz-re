# Wave 15 agent prompts and reports


## Bin 1

### Prompt

You are agent 1 of 6 in rename wave 15 of the CM848 firmware naming project (reverse engineering of a Cummins ECU; decompiled with Ghidra).

1. Read the brief first and follow it exactly: /home/linux/.claude/jobs/374b0424/tmp/w15/brief_W15.md
2. Your bin: /home/linux/.claude/jobs/374b0424/tmp/w15/bins/bin1.json (62 records).
3. Your result file: /home/linux/.claude/jobs/374b0424/tmp/w15/results/result_W15_bin1.jsonl
   - Exactly one JSON line per record of your bin (62 lines), in the brief's output format.
   - Append to it as you finish each e2m block, so partial work survives an interruption.
4. Your scratch folder: /home/linux/.claude/jobs/374b0424/tmp/w15/agent_scratch/bin1/
5. Do not edit, create or delete any other file. Do not run analyze.sh, git or any build.
6. Finish with the summary the brief asks for.

### Report

## Wave 15 bin 1: summary

Result file: /home/linux/.claude/jobs/374b0424/tmp/w15/results/result_W15_bin1.jsonl, 62 lines, one per record. I checked it with /home/linux/.claude/jobs/374b0424/tmp/w15/agent_scratch/bin1/verify.py. It reported zero problems: valid JSON, every `code_quote` found verbatim in its function of the .cpp, all new names free and unique, `_cal` and abbreviation rules clean. I edited nothing else.

### Counts per verdict
- rename (`confirmed`): 18
- keep: 41 (33 of them are block 8A13)
- drift: 3
- uncertain: 0

### Families renamed (new name prefix in brackets)
- **HSG lead/lag compensator** (`high_speed_governor_compensat*`; was `cruise_speed_*`): 0x40b708 and 0x40b70a.
- **HSG gain set priority** (`high_speed_governor_*_priority`; was `system_speed_limit_working*`): 0x5c950.
- **Intake manifold temperature estimate** (`intake_manifold_temperature_*`; was `pressure_correction_*`, `pressure_sensor_lower_limit_cal`, `injection_timing_offset_floor_cal`, `fuel_demand_phase_status_flags`): 0x405206, 0x405208, 0x40520a, 0x40a464.
- **Ambient air density slew limits** (`ambient_air_density_*_rate_limit`; was `engine_load_ramp_rate_*`): 0x4065be and 0x4065c0.
- **All-speed governor** (`all_speed_governor_*`; was `fuel_correction_output_active_flag`, `fuel_demand_pid_accum_hi/lo`): 0x40a1b2, 0x40a1cc, 0x40a1d4. The code adds both accumulators alike, so hi / lo were meaningless. The e2m QI and QP records settle which is which.
- **Net torque fuel limit** (prefix `net_torque_fuel_limit_`; was `fuel_demand_calc_bypass_flag_cal`): 0x408994.
- **Engine speed filter** (`engine_speed_filter_coefficient`; was `crank_filter_coefficient`): 0x408f72. The filter input is `average_engine_speed`, the main or backup sensor speed, and its output becomes `filtered_engine_speed`.
- **Single renames:**
  - 0x3fd532 `protection_system_init_flag` -> `cruise_discrete_switch_inputs_used_cal`. EEPROM mirror, so `_cal`. The block is aligned: EEPROM 0xac and 0xb2 both read 453 on either side.
  - 0x40b6e2 `fuel_flow_rpm_numerator` -> `engine_speed_to_vss_ratio`. It is tire revolutions per mile x axle ratio / 60, used to predict vehicle speed.
  - 0x5c47c `engine_retarder_configuration_mode` -> `engine_retarder_output_driver_count`.
  - 0x40b4f8 `j1939_msg_slot_hh_control` -> `pci_spare_transmit_message_status`. It is the status byte of the PCI message $16, which has no descriptor in the ROM table. The e2m layout (data 0x40b4f5, status, timer 0x40b4f9, in-frame response 0x40b4fb = `pci_spare_in_frame_response`) and the init store order (Err10, Err16, Err35) both fit.

### Keeps
- All 33 block 8A13 keeps were proven against the ROM descriptor tables (RX 0x5774b, TX 0x578ef). Each record address is the status or timer pointer of the entry whose header equals the e2m message id, and the TX[n] / RX[n] index in the name matches.
- The e2m text for Chry_Err72, Chry_Act72 and Chry_Act92 says "ECM Tx message", but the ROM table lists them as RX[11] and RX[13]. The keep note repeats the e2m wording.
- Other keeps: 0x40afb4, 0x40a36a, 0x5c39e, 0x3fd536, 0x40a350, 0x40b332, 0x40b334, 0x408ab6.

### Drift
- **0x5a9c4, 11F9 +8 OBD_Fuel_Type.** The word is the length word of the ROM table `governor_tuning_set_blend_weight_by_drivetrain_ratio_axis`. e2m 8A4F +0 ASG_Gear_Ratio_Axis shares the address and matches the code. 11F9 +8 has no storage of its own in 11.46.06, like the last record of 8C34 / 8C56 / 8C5B / 1632. The bin's `other_records_at_this_address` was empty here. A scan of all 62 addresses found no other collision.
- **0x40b0b6, 8D14 +A** (known drift). The word is a snapshot of `transmission_output_speed_change` (read with `lha`), not a timer.
- **0x40a372, 1070 +20 EB_Active_Driver_Fraction.** This is "record not implemented as described", not layout drift. The block neighbours +1E and +22 match. The only access is a 0 / 100 store of the wired retarder switch state, with no reader. That is not a 1/8192 fraction of active hardware.

### Types (not changed)
- 0x40a1cc and 0x40a1d4 are `dword`, but the record is signed 4 bytes. i32 candidate.
- 0x4065be: the record is signed and the compare casts to `short`, but a word pointer also loads it with `lhz`, so `word` stays.

### Function names the evidence shows are wrong (not applied)
- 0x3a9a4 `hpcr_initJ1939BufferValues` -> `cm848_initializePciMessageStatusBytes`. It only stores initial PCI status bytes (37 of the 40 table entries, all but TX[4], TX[5], RX[13], plus the spare $16 byte). It touches no J1939 buffer.
- 0xfabc `cm848_initFuelDemandVariables` -> `cm848_initializeAllSpeedGovernorVariables`. It zeroes the QD / QI / QP adjustments and the rpm deceleration limit integral term.
- 0x3257c `cm848_processProtectionStateFlags` and 0x3241c `cm848_calculateProtectionFuelDemandThreshold`. This is 48RE governor pressure logic: it writes `governor_pressure_target` from `transmission_output_speed_in_use` by `transmission_current_gear` and uses `transmission_output_speed_change`. It is not a protection. The new names are unproven. The `protection_*` words of block 8D14 (0x40b0ae, 0x40b0b0, 0x40b0b6, 0x40b0b8, 0x40b0ba) belong to this logic.

### Out-of-bin siblings (so no family is left half-renamed)
All names below are free in the CSVs and .cpp.

**HSG lead/lag compensator** (wrong `cruise_speed_*` prefix; every use is in the two HSG compensator functions):
- 0x3fb55a `cruise_speed_rpm_prev_snapshot` -> `high_speed_governor_compensator_engine_speed_previous`
- 0x3fb55c `cruise_speed_factor_a` -> `high_speed_governor_compensator_working_filter_coefficient_1`
- 0x3fb55e `cruise_speed_factor_b` -> `..._working_filter_coefficient_2`
- 0x3fb560 `cruise_speed_offset` -> `..._working_filter_coefficient_3`
- 0x40b704 `cruise_speed_rpm_base` (previous output) -> `high_speed_governor_compensator_output_previous`
- 0x5c94c `cruise_speed_default_cal` (e2m 13B4 +4 HSG_Comp_Transition_Coefficient; ROM word with a wrong `_cal`) -> `high_speed_governor_compensator_transition_coefficient`
- The comment at 0x40b6ae mentions `cruise_speed_offset`; check it is stale.

**HSG gain set priority:**
- 0x40b70c `system_speed_limit_working` (e2m 1299 +0 HSG_Application_Gain_Set_Priority) -> `high_speed_governor_gain_set_source_priority`

**Intake manifold temperature estimate** (named for pressure or fuel demand):
- 0x3fa624 `pressure_correction_first_filter` and 0x3fa62c `pressure_correction_second_filter` -> `intake_manifold_temperature_lag_first_filter` / `_second_filter`
- 0x3fa620 `pressure_correction_filter1_working` and 0x3fa622 `condition_monitor_status_working` (the two filter outputs) -> `..._lag_first_filter_output` / `_second_filter_output`
- 0x3fa616 `cold_start_pressure_scale_working` (lead time constant lookup result)
- 0x3fa61a `sensor_channel9_pressure_snapshot`, 0x40bd86 `sensor_channel9_pressure_value`, 0x40bd9e `sensor_channel9_pressure_default_value`: channel 9 is the intake manifold temperature sensor.
- 0x40520c `fuel_quantity_ema_axis_cal` and 0x405220 `fuel_quantity_ema_output_cal` (e2m 18D7 / 18D8 lead time constant tables; wrong `_cal` on RAM; only user is the IMT function) -> `intake_manifold_temperature_lead_time_constant_axis` / `_values`
- Block 1A1B: 0x40a452 `fuel_demand_boost_offset_filtered` (Charge_Tmptr_Est, with its filter record 0x3fa60e `fuel_demand_boost_offset_filter`), 0x40a454 `injection_timing_offset_filtered` (TPE_CIT_Ref), 0x40a456 `injection_enable_mode_byte` (Charge_Tmptr_EStat).

**All-speed governor:**
- 0x3fa0e4 `fuel_demand_pid_accumulator` -> `all_speed_governor_pid_accumulator`
- 0x40a1fc `fuel_demand_pid_coeffs` -> `all_speed_governor_gain_set`

**Net torque fuel limit** (prefix `net_torque_fuel_limit_`, so other bins can align):
- 0x408996 `fuel_demand_bypass_value_cal` (8C68 +2) -> `net_torque_fuel_limit_override_value`
- 0x408998 `fuel_demand_rate_step_down` (+4) -> `net_torque_fuel_limit_negative_slew_rate`
- 0x40899a `fuel_demand_rate_step_up` (+6) -> `net_torque_fuel_limit_positive_slew_rate`
- Scrambled table names: 0x40899c `fuel_demand_table_base_cal` is the engine speed axis (8C6A), 0x4089ba `fuel_demand_table_yaxis_cal` is the alpha axis (8C6B), 0x4089c6 `fuel_demand_table_xaxis_cal` is the grid (8C6C). Proposed: `net_torque_fuel_limit_engine_speed_axis`, `_alpha_axis`, `_grid`.
- Working words of `cm848_calculateNetTorqueFuelLimit`: 0x3fb41c `fuel_demand_rate_table_dims`, 0x3fb420 `fuel_demand_rate_limiter_state`, 0x3fb422 / 0x3fb424 / 0x3fb426 `fuel_demand_rate_lookup_a/b/c`.

**Engine speed filter:**
- 0x3fb5c6 `crank_filter_state` (the EMA record for 0x408f72) -> `engine_speed_filter_state`

**Other misname leads from the same functions:**
- 0x3fd920 `fuel_flow_rpm_mode_flag` (e2m 118B +2 Cruise_RSG_Feedback_Parameter, 1 = road speed / 0 = predicted vehicle speed; EEPROM mirror without `_cal`) -> e.g. `cruise_feedback_uses_road_speed_cal`
- 0x3fee7a `protection_timing_period_cal` (e2m 132C +0 Tire_Size) -> `tire_revolutions_per_mile_cal`. It is not a `fuel_flow_rpm_` sibling.


## Bin 2

### Prompt

You are agent 2 of 6 in rename wave 15 of the CM848 firmware naming project (reverse engineering of a Cummins ECU; decompiled with Ghidra).

1. Read the brief first and follow it exactly: /home/linux/.claude/jobs/374b0424/tmp/w15/brief_W15.md
2. Your bin: /home/linux/.claude/jobs/374b0424/tmp/w15/bins/bin2.json (65 records).
3. Your result file: /home/linux/.claude/jobs/374b0424/tmp/w15/results/result_W15_bin2.jsonl
   - Exactly one JSON line per record of your bin (65 lines), in the brief's output format.
   - Append to it as you finish each e2m block, so partial work survives an interruption.
4. Your scratch folder: /home/linux/.claude/jobs/374b0424/tmp/w15/agent_scratch/bin2/
5. Do not edit, create or delete any other file. Do not run analyze.sh, git or any build.
6. Finish with the summary the brief asks for.

### Report

Wave 15, bin 2 (65 records): finished. The result file has 65 lines: 44 keep, 20 rename (verdict "confirmed"), 1 drift, 0 uncertain.

Result file: /home/linux/.claude/jobs/374b0424/tmp/w15/results/result_W15_bin2.jsonl
My scratch validator /home/linux/.claude/jobs/374b0424/tmp/w15/agent_scratch/bin2/build.py checked it. Every new name is snake_case and absent from global_variables.csv and the .cpp. Only the EEPROM-mirror rows end `_cal`. Every `code_quote` is a whole, non-comment line inside its named function. No new name collides with bins 1, 3, 4, 5 or 6 (all present at the last run). My comments name some siblings by their old names, which other bins rename (`governor_fuel_correction_init_cal`, `cold_start_fuel_demand_correction_enable_cal`, `fuel_demand_override_active_min`, `system_speed_limit_working_minimum`), so the reference refresh needs to update them.

## Verdicts
- **keep (44):**
  - All 29 rows of block 8A12 (PCI message status / timer rows). I dumped the PCI RX/TX descriptor tables from the ROM (0x5774b, 0x578ef) and every row's status or timer address sits in the entry whose header equals the record's message id, so no drift. The e2m direction text disagrees with the tables for five messages: 3A / 98 / EA / 1E ("OSS") say "ECM Rx" but sit in TX[6] / [12] / [18] / [1]; 1A says "ECM Tx" but sits in RX[3]. The notes state this.
  - 0x40b412 carries a second e2m record, Store_Freeze_Frame_Now, on bit 7. The code uses bit 7 only as the MIL request, so I kept `pci_receive_message_8_mil_and_fault_bits`.
  - The other 15 keeps: 169A x2, 16A3 x3 (the 0x3fd7e0 / 0x3fd7e2 / 0x3fd7e6 flags), 18F0 +4, 1982 x2, 8022 x3, 8041 +24, 8C50 +3, 8C5E x2 (+4 and +C).
- **rename (20), by family:**
  - Low speed governor, `low_speed_governor_*` (5, from `governor_*`):
    - 0x40ae9a: `low_speed_governor_integral_term`
    - 0x40aea4: `low_speed_governor_derivative_gain_adjustment`
    - 0x40aea6: `low_speed_governor_integral_gain_adjustment`
    - 0x40aeae: `low_speed_governor_integrator_preset_used_previous_flag`
    - 0x4070e6: `low_speed_governor_default_proportional_gain`
  - Engine protection restart limitation (2, from camelCase `governor_faultDerate_*`):
    - 0x40a772: `engine_protection_restart_limitation_shutdown_command_flag`
    - 0x40a774: `engine_protection_restart_limitation_shutdown_approaching_flag`
    - I left "oil pressure" out of the names because the code cannot confirm it (see the oil-pressure note below).
  - Supervisor chip overspeed configuration (2, from `j1939_timer_*`):
    - 0x40a042: `supervisor_chip_engine_speed_targets_per_revolution`
    - 0x40a044: `supervisor_chip_overspeed_non_latching_flag`
  - Injector driver reference levels (4, from `mios_pwmNN_duty_ref`):
    - 0x4090ac: `injector_driver_booster_voltage_level`
    - 0x4090b0: `injector_driver_recharge_voltage_level`
    - 0x4090b4: `injector_driver_hold_current_level`
    - 0x4090b6: `injector_driver_pull_in_current_level`
  - Priority words (2):
    - 0x408de2: `accelerator_interlock_throttle_priority`
    - 0x40b70c: `high_speed_governor_working_gain_set_source_priority`
  - Singles (5):
    - 0x40a79c: `crank_four_dimensional_timing`
    - 0x810e: `flash_operational_code_entry_pointer`
    - 0x3fd7dc: `wastegate_duty_user_override_enable_cal`
    - 0x40b812: `all_speed_governor_equivalent_throttle`
    - 0x40b53e: `net_torque_fuel_limit_table_output`
  - For 0x3fd7dc and the four injector rows, the older `(was ...)` history is carried as "Earlier name: X".
- **drift (1):** 0x409fea, e2m 1B2E from +A. The ROM has no scalar there. 0x409fea is the byte-length word of the 4-breakpoint axis `wastegate_monitor_fail_high_boost_pressure_axis` (dump 8, i.e. 0.03 % on the record scale), followed by the barometric breakpoints 1194 / 1446 / 1697 / 1886. The e2m +C CWG_On_Max_Time record would land on the first breakpoint. Records +0..+8 are fine.

## Findings to carry forward
- **PWM 16-19 are the injector driver reference levels.** `docs/tpu_mios_channel_map.md` still says the device per PWM submodule is unknown.
  - `cm848_tpuMiosOutput_loadCalibration` loads only e2m 8041 injector driver (HPCR) records.
  - 25600 counts (100 % duty) x the record scale equals the record maximum: 103 V and 55 A.
  - Dump values give 32.2 V booster, 80.2 V recharge, 13.5 A hold and 18.5 A pull-in.
- **Low speed governor gain set:**
  - It is a 4-word set in the order P, I, D, jerk. The current names assign the roles wrongly.
  - The RAM dump confirms the roles: the loaded words 0x40ae76 / 78 / 7a read 164 / 164 / 77, the same as the defaults at 0x4070e6 / e8 / ea.
  - Another bin's evidence agrees: the derivative term uses the quantity named `governor_pid_gain_factor_a`.
- **Oil pressure is not confirmed for 0x40a772 / 0x40a774.**
  - The e2m labels the restart limitation algorithm "oil pressure".
  - The code only special-cases channel index 4 in `protection_state_transition`.
  - This ROM's channel loop starts at enable bit 128 (e2m 106B +12, index 0 = fuel temperature). The oil pressure enables are in e2m 106B +10, outside the loop.
  - This calibration has a single channel (index 0), so both flags stay 0.
- **Type notes (not changed):**
  - 0x40a79c is `word` on a signed record; every access is an `sth` of -1024, so `i16` fits.
  - 0x40a042 is a `word` over two 1-byte records, +A at 0x40a042 and +B persistence at 0x40a043 (empty-typed row `j1939_timer_config_byte_c`); both are read with `lbz`.
  - 0x40b410 is a `byte` on the 2-byte Trans_DTC record (0x40b410-0x40b411).
- **Naming lead:** 0x3fd7de `wastegate_duty_first_error_term_limit_enable_flag_cal` and the kept 0x3fd7e6 `..._second_error_term_..._cal` describe mechanism. Another bin uses `wastegate_duty_compressor_outlet_temperature_derate_*`, so the pair could become `..._turbocharger_speed_closed_loop_limit_enable_cal` and `..._compressor_outlet_temperature_closed_loop_limit_enable_cal`.
- The brief's allowed-abbreviation list lacks `pci`; the 8A12 names use it as the repo's bus name, so I left them.

## Function names the evidence shows are wrong (not applied)
- 0x000403e4 `cm848_checkDiagnosticFuelOverride` -> `cm848_claimAcceleratorInterlockThrottleOverride`: with accelerator_interlock_enable and switch 26 it stores the interlock priority into the override arbitration and zeroes the override value.
- 0x0050e610 `cm848_periodicControlLoopFaultHandling` -> `cm848_claimRemoteThrottleOverride`: gated by remote_throttle_enable, copies two remote throttle fault bits and claims the override with the remote throttle priority.
- 0x00045ecc `cm848_calculateFuelDemandWithConditions` -> `cm848_calculateAllSpeedGovernorEquivalentThrottle`: writes the e2m 81AA equivalent throttle from the all speed governor, cruise and PTO terms.
- 0x00027e4c `cm848_updateSpeedProtectionLimits` -> `cm848_presetLowSpeedGovernorIntegrator`: presets the integrator accumulator and clears the P / D / jerk terms.
- 0x00028618 `cm848_initSpeedProtectionParameters` -> `cm848_initializeLowSpeedGovernorParameters`: sets the three gain adjustments to 1.0 (0x80), the fueling clamp and the alternator filter.
- 0x00028a14 `cm848_updateGovernorSetpointParameters` -> `cm848_loadLowSpeedGovernorGainSet`: loads the four gain words P / I / D / jerk.
- 0x0001bb30 `cm848_initColdStartLimits` -> `cm848_initializeCrankTimingOutputs`: only stores -120 deg into `crank_four_dimensional_timing` and `crank_exit_advance`.
- 0x005289d4 `cm848_tpuMiosOutput_loadCalibration` -> `cm848_loadInjectorDriverCalibration`: every value it loads is an e2m 8041 injector driver record.
- 0x00508408 `protection_state_transition` -> `cm848_setEngineProtectionRestartLimitationCommands`, and 0x005084b4 `governor_fault_derateCalc_channelIter` -> `cm848_runEngineProtectionRestartLimitation`: the pair only implements the restart limitation (channel 4 branch) and sets the two 10B1 +0 / +2 flags.
- Struct field `fuel_demand_control_t.override_active` (0x40a588) holds the winning override priority (compare-and-take), not a 1/0 flag; `override_priority` would fit.

## Out-of-bin siblings
"No bin" means no other bin's result file has that address.

**Low speed governor, e2m 1065 / 10ED / 10EC (no bin):**
- 0x40ae96 `governor_speed_weight_a` -> proportional term (+2)
- 0x40ae98 `governor_speed_weight_b` -> derivative term (+4)
- 0x40ae9c `governor_speed_error_derivative` -> jerk term (+8)
- 0x40ae9e `governor_speed_setpoint_integrated` -> fueling clamp maximum (+A)
- 0x40aea0 `governor_speed_pid_output_working` -> integrator clamp maximum (+C)
- 0x40aea2 `governor_speed_reference_computed` -> integrator preset maximum (+E)
- 0x40aea8 `governor_speed_pid_gain` -> proportional gain adjustment (+14, 0x80 = 1.0)
- 0x40aeaa `governor_speed_debounce_b` -> reset delay timer (+16)
- 0x3faf48 `governor_fuel_demand_correction_accumulator` -> the Q16.16 integral accumulator
- Gain-set words with shifted roles:
  - 0x40ae76 `governor_speed_setpoint_raw` (the proportional gain)
  - 0x40ae78 `governor_d_gain_from_table` (the integral gain)
  - 0x40ae7a `governor_p_gain_from_table` (the derivative gain)
  - 0x40ae8a `governor_j1939_gain_extra_working` (the jerk gain)
  - Stored copies:
    - 0x40ae82 `governor_j1939_speed_target` (P)
    - 0x40ae84 `governor_j1939_d_gain_stored` (I)
    - 0x40ae86 `governor_j1939_p_gain_stored` (D)
    - 0x40ae88 `governor_j1939_i_gain_stored` (jerk)
  - Defaults, which wrongly end `_cal` in RAM:
    - 0x4070e8 `governor_j1939_d_gain_default_cal` (e2m 10EC +2, integral)
    - 0x4070ea `governor_j1939_p_gain_default_cal` (+4, derivative)
    - 0x4070ec `governor_j1939_i_gain_default_cal` (+6, jerk)

**Engine protection (no bin).** Same camelCase `governor_faultDerate_*` prefix, to become `engine_protection_*` or `fault_derate_*`:
- 0x3fbd2c `..._task_index`
- 0x3fbd3e `..._peak_value`
- 0x3fdfb8 `..._active_channel`
- 0x3fdfba `..._consecutive_count`
- 0x3fbd28 `..._channel_bit`
- 0x3fbd2a `..._lookup_interp_state`
- 0x3fbd36 `..._prev_rpm`
- 0x3fbd38 `..._latch`
- 0x3fbd3c `..._engine_start_flag`
- 0x3fdfbc `..._total_event_count`
- 0x40a78e `governor_derate_j1939_trigger_pending`

**Supervisor chip, e2m 11AE (no bin):**
- 0x40a040 `j1939_timer_period_factor_a` -> `supervisor_chip_overspeed_limit` (+8, dump 4200 rpm)
- 0x40a043 `j1939_timer_config_byte_c` -> `supervisor_chip_overspeed_consecutive_occurrence_count` (+B, dump 10)

**Injector driver periods, e2m 8041 (no bin).** The names contain the banned `_ref`:
- 0x4090aa `mios_pwm16_period_microseconds_ref` -> `injector_driver_booster_voltage_pwm_period_microseconds` (+A)
- 0x4090ae `mios_pwm17_period_microseconds_ref` -> `injector_driver_recharge_voltage_pwm_period_microseconds` (+E)
- 0x4090b8 `mios_pwm18_period_microseconds_ref` -> `injector_driver_hold_current_pwm_period_microseconds` (+18)
- 0x4090ba `mios_pwm19_period_microseconds_ref` -> `injector_driver_pull_in_current_pwm_period_microseconds` (+1A)
- 0x4090b2 `tpu_ch14_period_base` is e2m +12 HPCR_IRCHG_Period, the recharge current PWM period; it could join the family.

**Priorities and equivalent throttle:**
- 0x4071de `fuel_demand_override_active_min` (e2m 1171 +0, the remote throttle priority): bin 3 already renames it to `remote_throttle_priority`.
- 0x5c950 `system_speed_limit_working_minimum` (e2m 1298 +0): bin 1 already renames it to `high_speed_governor_working_gain_set_application_priority`.
- 0x409eda `fuel_pressure_sensor_plausibility_maximum_governor_output` (no bin) is the limit the plausibility check compares with the equivalent throttle I renamed, so its name could become `..._maximum_equivalent_throttle`.


## Bin 3

### Prompt

You are agent 3 of 6 in rename wave 15 of the CM848 firmware naming project (reverse engineering of a Cummins ECU; decompiled with Ghidra).

1. Read the brief first and follow it exactly: /home/linux/.claude/jobs/374b0424/tmp/w15/brief_W15.md
2. Your bin: /home/linux/.claude/jobs/374b0424/tmp/w15/bins/bin3.json (60 records).
3. Your result file: /home/linux/.claude/jobs/374b0424/tmp/w15/results/result_W15_bin3.jsonl
   - Exactly one JSON line per record of your bin (60 lines), in the brief's output format.
   - Append to it as you finish each e2m block, so partial work survives an interruption.
4. Your scratch folder: /home/linux/.claude/jobs/374b0424/tmp/w15/agent_scratch/bin3/
5. Do not edit, create or delete any other file. Do not run analyze.sh, git or any build.
6. Finish with the summary the brief asks for.

### Report

# Wave 15, agent 3 (bin3, 60 records) - report

Result file: `/home/linux/.claude/jobs/374b0424/tmp/w15/results/result_W15_bin3.jsonl` (60 lines). I rebuilt it from per-block data files and checked it with `/home/linux/.claude/jobs/374b0424/tmp/w15/agent_scratch/bin3/validate.py`; that check passes. I deliberately corrupted a copy and the validator caught every error I planted. The validator checks:
- addresses and `old` names against the bin;
- unique new names;
- no new name in the CSVs or the `.cpp`;
- `_cal` only inside the EEPROM mirror;
- no banned abbreviations;
- every `code_quote` found verbatim, as a code line (not a comment), inside the named function;
- no "(was ...)" in comments.

I touched no repo file and ran no git, build or `analyze.sh`.

## Verdicts
| Verdict | Rows |
|---|---|
| confirmed (rename) | 54 |
| keep | 6 |
| drift | 0 |
| uncertain | 0 |

**Keeps** (each has an `e2m_note`):
- 0x3feff4 `boost_uses_barometric_pressure_flag`. Both readers (`cm848_calculateBoostPressure` and `cm848_evaluateProtectionModeFlags`) use it the same way.
- 0x645ba `consecutive_incomplete_power_down_limit`.
- 0x3fd87a `j1939_pgn65213_priority_cal`, already fixed in an earlier wave.
- 0x409fa4 `battery_temperature_rationality_mismatch_count_threshold`.
- 0x40b576 `park_neutral_switch_start_neutral_count`.
- 0x40b66a `wastegate_solenoid_retest_pass_count`.

## Families renamed
- **J1939 default priorities, e2m 1254 (19 rows):** every one is `j1939_pgn<N>_priority_cal`.
  - 11 rows only lacked `_cal` (0x3fd83c through 0x3fd858).
  - 8 rows said `_source_address_bits`, but every code line is `(value & 7) << 2` on the CAN id top byte, so they are priorities. This follows the 65270 / 65264 / 65249 / 65213 precedent.
  - Two PGN numbers in the old names were wrong. 0x3fd87e is built as header 0xffe000, which is PGN 65504, not 57344. 0x3fd880 is built as 0xdc2800, which is PGN 56320, not 56360. I used the PGNs the code builds.
- **TPE charge temperature estimate, e2m 1A1A / 1A1B (10 rows):** the `injection_timing_*`, `fuel_demand_boost_offset_*` and `fuel_demand_timing_*` names become `compressor_inlet_temperature_reference_{alpha_0,alpha_1,chi_2,chi_3,chi_4}`, `compressor_inlet_temperature_reference`, `charge_temperature_estimate`, `charge_temperature_estimate_{filter_coefficient,offset,compressor_inlet_temperature_gain}`. The comments carry the chi map number to record mapping (map 1 to 4 is +2 to +8).
- **A/C control, e2m 8A14 (4 rows):** `hpcr_protection_eval_mode` and `protection_event26_*` become `air_conditioning_control_configuration`, `air_conditioning_cycle_{on,off}_time` and `air_conditioning_high_pressure_off_threshold`. The code sets logical output 0x26, the A/C clutch request.
- **Torque converter clutch rationality, e2m 8C33 (3 rows):** `protection_*` becomes `converter_clutch_rationality_fail_count_limit`, `converter_clutch_rationality_minimum_ratio_delta_sum` and `converter_clutch_overdrive_rationality_time`. The plate comment of `cm848_accumulateConverterClutchRatioDeltaSum` already says the sum is "not a PID integrator".
- **Cruise / road speed governor droop (6 rows):**
  - `cruise_bottom_droop_offset` (0x408dfc)
  - `cruise_droop_reference_speed` (0x408e12, a speed in mph, not a fuel demand)
  - `cruise_droop_speed_error_delta_{maximum,minimum}` (0x408e14, 0x408e16)
  - `cruise_zone_3_speed_error_threshold` (0x408e2e; the old name had the invented abbreviation "neg", and the value is +5 mph)
  - `cruise_rpm_ratio_integral_limit` (0x408728; the old name said speed error, but the integral sums the engine speed / vehicle speed ratio change)
- **Wastegate duty controller, e2m 16A2 (2 rows):** `governor_*` becomes `wastegate_duty_turbocharger_speed_derate_derivative_term` and `wastegate_duty_compressor_outlet_temperature_derate_error_gain`.
- **Single renames:**
  - `drivetrain_ratio_when_loaded` (0x40b6fe)
  - `low_speed_governor_{high,middle}_gear_proportional_gain` (0x408ed2, 0x408eda)
  - `remote_throttle_priority` (0x4071de)
  - `can_last_message_object_used` (0x40adf2; "alloc" and "tx" are not allowed abbreviations)
  - `air_fuel_control_fueling_override_value` (0x3feff2; the old `_cal` was in the RAM region)
  - `scheduler_overrun_count_cal` (0x3feebe, EEPROM mirror)
  - `injection_end_limit_exceeded_count_threshold` (0x4090cc)
  - `cylinder_balance_service_coolant_temperature_{maximum,minimum}` (0x408f28, 0x408f2a)

## Drift
None. The 8A14 rows (+4 to +E) sit below the known +2C drift. The 1254 PGN constants match the records one by one. At 0x3feebe, 12A6 +0 is the real record and 1930 +18 `BTR_Denominator` is the known 1930 drift; the evidence says so.

## Type notes (no type changed)
- 0x408ed2 and 0x408eda are typed `byte`, but each is the first word of a 4-word signed gain set (61 / 85 / 77 / 0 in the dump). A 4 x i16 retype is open.
- 0x40a3e0 and 0x40a454 are typed `word`, but the record is signed and the code casts to `(short)`. i16 candidates (each has only a `sth` store, so no load proves it).
- The three 11D5 slew-rate siblings (see below) are dwords typed `word`.

## Functions whose names my evidence shows are wrong (not applied)
- 0x00013aec `cm848_processBoostProtectionMode` -> `cm848_estimateChargeTemperature`: it is the TPE charge temperature estimate.
- 0x00013ca4 `cm848_initBoostProtectionState` -> `cm848_initializeChargeTemperatureEstimate`: it seeds the estimate's filter and quality byte.
- 0x00511078 `engine_protection_conditionCode_evaluate` -> `cm848_controlAirConditioningClutchForDrTruck`: A/C clutch algorithm 1 (DR truck), condition codes 1-15, logical output 0x26.
- 0x00510fa0 `engine_protection_fuelMass_rpmCheck` -> `cm848_controlAirConditioningClutchForBrTruck`: A/C clutch algorithm 0 (BR truck).
- 0x005118f8 `hpcr_fuel_mode_state_transition` -> `cm848_controlAirConditioningClutch`: the dispatcher on AC_Control_Configuration.
- 0x005127d8 `governor_cruise_speedError_integrate` -> `governor_cruise_rpmRatio_integrate`: it integrates the change of `cruise_rpm_ratio_ema`, not a speed error.
- 0x00046d90 `cm848_updateEngineStatusTimers` -> `cm848_monitorInjectionLimitViolationCounters`: persistence counters of the TPU-A channel 2 / 7 flags, faults 325 / 326.
- 0x0050e610 `cm848_periodicControlLoopFaultHandling` -> `cm848_applyRemoteThrottleOverride` (medium confidence).
- 0x00524df4 `governorCruiseStateMachine` -> `cm848_initializeCruiseDroopGains` (likely): it only sets the power-up droop gains and offsets.
- 0x0002560c `cm848_initJ1939EngineControlBuffer` -> `cm848_initializePgn65232NonContinuousMonitorTestResultBuffer`: it builds the PGN 65232 (DM8) descriptor.
- 0x0001b900 `initFaultTimerMessage` -> `cm848_initializePgn65251EngineConfigurationMessage`, and 0x0001b730 `cm848_sendFaultTimerMessage` -> `cm848_sendPgn65251EngineConfigurationMessage`: both handle the PGN 65251 engine configuration message.
- 0x00025824 `cm848_initJ1939Etc1ControlBuffer` -> `cm848_initializePgn61441ElectronicBrakeController1Buffer`: header 0xf00100 is PGN 61441, EBC1; ETC1 is 61442.
- 0x00026efc `cm848_initJ1939SafetyStatusBuffer` and 0x00026e90 `cm848_j1939SendSafetyStatusMessage` are PGN 65279 water in fuel indicator (`cm848_initializePgn65279WaterInFuelIndicatorBuffer` / `cm848_sendPgn65279WaterInFuelIndicatorMessage`).

## Out-of-bin siblings
Siblings with the same wrong prefix or `_cal` problem, as address, current name, proposed rename. A read-only look at the other bins' results shows that bins 2, 4 and 5 already rename the four rows marked "done elsewhere" below to the same or compatible names.
- **106C**
  - 0x3fd05c `fuel_flow_rpm_divisor_prev` -> `drivetrain_ratio_user_filtered_previous`. It is the previous-pass `drivetrain_ratio_user_filtered`.
- **10EA**
  - 0x4070aa `governor_setpoint_table_cal` is e2m 10EE +12 LSG_Aggressive_Proportional_Gain, typed byte, `_cal` in RAM. Bin 5 chose `low_speed_governor_aggressive_gain_set`; harmonize it with the `*_proportional_gain` names (mine, and bin 2's 0x4070e6) as `low_speed_governor_aggressive_proportional_gain`.
  - 0x4070e6 `governor_setpoint_table_a` is e2m 10EC +0 LSG_Default_Proportional_Gain. Done elsewhere (bin 2).
- **1171 / 1210**
  - 0x408de2 `fuel_demand_override_min_cal` -> `accelerator_interlock_throttle_priority` (holds 9, `_cal` in RAM). Done elsewhere (bin 2).
- **1187 / 8A0F**
  - 0x40b6a2 `cruise_speed_setpoint_active` -> `cruise_droop_speed_error_delta` (the parent of my 0x408e14 and 0x408e16).
  - 0x408e20 `cruise_zone_speed_error_abs_limit` -> `cruise_zone_2_speed_error_threshold` (e2m 1186 +24 Gain_Thres; "abs" is an abbreviation).
  - 0x40b204 `cruise_speed_error_integral` -> `cruise_rpm_ratio_integral`. Done elsewhere (bin 4).
- **11D5**
  - 0x3feff8 `fuel_demand_load_threshold_c`, 0x3feffa `fuel_demand_load_threshold_b`, 0x3feffc `fuel_demand_load_threshold_a` -> `air_fuel_control_fueling_threshold_1` / `_2` / `_3`.
  - 0x3feffe `fuel_demand_load_threshold_d`, 0x3ff002 `fuel_demand_load_result_working`, 0x3ff006 `fuel_demand_load_select_working` -> `air_fuel_control_fueling_slew_rate_1` / `_2` / `_3`. These are dwords typed `word`.
- **1254**
  - 0x3fd83a `j1939_ackm_priority`, 0x3fd83e `j1939_cruise_ctrl_priority`, 0x3fd842 `j1939_dm1_priority`, 0x3fd844 `j1939_dm2_priority`, 0x3fd84c `j1939_dm11_priority`: all in the EEPROM mirror, all missing `_cal`.
  - 0x3fd84c: the e2m record there says DM10, but `cm848_initPgn65234Dm11Handler` builds PGN 65234, which is DM11. Check this before renaming.
  - 0x3faeb8 `j1939_pgn57344_tx_message` -> `j1939_pgn65504_tx_message`; 0x3faa8c `j1939_pgn56360_tx_message` -> `j1939_pgn56320_tx_message`.
- **16A1 / 16A2 (same function, wrong `fuel_*` / `governor_*` domain)**
  - Bin 5 already renames 0x3ffcaa, 0x3ffcae, 0x3ffcb0 and 0x3ffcb2 (the four 16A1 gain rows) to `wastegate_duty_*`, compatible with my two names.
  - Still open: the working words 0x3fa176 `fuel_demand_delta_working`, 0x3fa184 `fuel_demand_quantity_snapshot` (previous turbocharger speed), 0x3fa182 `fuel_flow_rate_prev_snapshot` (previous compressor outlet temperature), 0x3fa1ac `governor_first_iteration_flag`.
- **1A1A / 1A1B**
  - 0x3fa60e `fuel_demand_boost_offset_filter` -> `charge_temperature_estimate_filter` (the EMA record).
  - 0x40a456 `injection_enable_mode_byte` -> `charge_temperature_estimate_status` (e2m 1A1B +4 Charge_Tmptr_EStat).
- **804A / 804B**
  - 0x4090ce `injection_timing_count_b_max_cal` -> `injection_command_overlap_count_threshold` (`_cal` in RAM).
  - 0x40b858 `injection_timing_count_a` -> `injection_end_limit_exceeded_count`.
  - 0x40b85a `injection_timing_count_b` -> `injection_command_overlap_count`.
- **8A14**
  - 0x4086b4 `protection_event26_rpm_high_gate_lower` (AC_Low_RPM_Off) -> `air_conditioning_low_rpm_off_threshold`.
  - 0x4086b8 `protection_event26_rpm_high_debounce_limit` (AC_Low_RPM_On_Time) -> `air_conditioning_low_rpm_on_time`.
  - The working `protection_event26_*` words at 0x3fcd5e-0x3fcd78 and bytes 0x40b1e6 / 0x40b1e7 and `protection_coolant_classb_active_flag` belong to the same A/C function.
- **8C33**
  - Working words of `cm848_monitorConverterClutchAndOverdrivePerformance` with the wrong `protection_` prefix: 0x3fcefc `protection_output_phase_entry_flag`, 0x3fcefe `protection_pid_rpm_setpoint_prev`, 0x3fcf00 `protection_fuel_demand_prev`, 0x3fcf02 `protection_output_rate_counter`, 0x3fcf04 `protection_fuel_demand_tick_snapshot`, 0x3fcf06 `protection_action_mode_b2_snapshot`.
- **81AE**
  - 0x408f14 `crank_sync_coolant_threshold_cal` (e2m 81AE +32 CBD_Coolant_Temp_Threshold) -> `cylinder_balance_coolant_temperature_threshold`.

The `cruise_fuel_demand_*` rows in e2m 1189 (0x408e5c, 0x408e5e and others) match their records and are not siblings.


## Bin 4

### Prompt

You are agent 4 of 6 in rename wave 15 of the CM848 firmware naming project (reverse engineering of a Cummins ECU; decompiled with Ghidra).

1. Read the brief first and follow it exactly: /home/linux/.claude/jobs/374b0424/tmp/w15/brief_W15.md
2. Your bin: /home/linux/.claude/jobs/374b0424/tmp/w15/bins/bin4.json (64 records).
3. Your result file: /home/linux/.claude/jobs/374b0424/tmp/w15/results/result_W15_bin4.jsonl
   - Exactly one JSON line per record of your bin (64 lines), in the brief's output format.
   - Append to it as you finish each e2m block, so partial work survives an interruption.
4. Your scratch folder: /home/linux/.claude/jobs/374b0424/tmp/w15/agent_scratch/bin4/
5. Do not edit, create or delete any other file. Do not run analyze.sh, git or any build.
6. Finish with the summary the brief asks for.

### Report

Bin 4 is finished: `/home/linux/.claude/jobs/374b0424/tmp/w15/results/result_W15_bin4.jsonl` holds 64 lines, one per record, with 64 unique addresses and `old` equal to `label_in_cpp` on every line.

**Checks run:** a validator over the file, a dry run of the repo gate `scripts/rename_waves/apply_renames.py` on the 28 renames, and a cross-bin duplicate check. The validator found no problems.
- Every new name is free in the CSVs and the `.cpp`, and `_cal` appears only in the EEPROM mirror.
- Every `code_quote` was found verbatim in its named function and contains the old name.
- The gate printed no PROBLEM lines.
- No new name equals one proposed in bins 1, 2, 3, 5 or 6. Those files were still growing when I last checked (about 18:32).
- My scratch scripts are in `.../agent_scratch/bin4/`; I changed no repository file.

**Verdicts:** 28 rename, 36 keep, 0 drift, 0 uncertain.

**Families renamed**
- **Engine retarder, PGN 65249 (9 rows):** 0x5c36a, 0x5c36e, 0x5c370, 0x5c372, 0x5c374, 0x5c378, 0x5c37a, 0x5c37c, 0x5c380 become `engine_retarder_configuration_*`: `reference_torque`, `idle_speed`, `peak_torque_speed`, `point_3_speed`, `point_4_speed`, `maximum_speed_torque_percent`, `point_3_torque_percent`, `point_4_torque_percent`, `point_5_torque_percent`. They were `j1939_protocol_mode_*`, `j1939_pgn65249_cal_*` and `j1939_dtc_spn_cal_*`, with a wrong `_cal`. The payload layout follows the 19 bytes the builder writes.
- **Engine retarder fuel threshold:** 0x408ea8 `fuel_demand_computed_min_cal` becomes `engine_retarder_fuel_demand_threshold`.
- **Low speed governor gain state:** 0x40ae7c becomes `low_speed_governor_user_gain_state` and 0x40ae7e becomes `low_speed_governor_final_gain_state`. The selected 4-word table loads into the LSG P, I, D and jerk gain words at e2m 10ED +0, +2, +4 and +14. The final state is decided in priority order: TSC1 override (state 4), then `governor_j1939_mode_override`, then the user state.
- **Compressor map:** 0x40a60e becomes `compressor_map_corrected_air_flow`, 0x40a612 becomes `compressor_outlet_temperature_to_inlet_temperature_ratio`, and 0x40bab4 becomes `compressor_outlet_temperature_virtual_sensor_copy`.
- **Injector driver booster capacitors (4 rows):** 0x40bdfc, 0x40bdfe, 0x40be00, 0x40be02 become `injector_driver_booster_capacitor_{1,2}_voltage_sensor_{value,default_value}`. The identity is proved: faults 329 and 331 give P2146 and P2149, and `cm848_protection_timer_init` tests the same two channels against the booster-capacitor threshold.
- **Rail pressure key-on check:** 0x409ef4 becomes `fuel_pressure_sensor_pre_start_check_minimum_run_time` and 0x409ef8 becomes `fuel_pressure_sensor_pre_start_check_start_delay`. Both were `cam_sync_validation_*`.
- **Engineering fueling overrides, all EEPROM mirror:** 0x3fd802 becomes `torque_derate_override_fuel_quantity_cal`, 0x3fd804 becomes `user_override_fueling_cal`, and 0x3fd8b4 becomes `user_commanded_fueling_cal`. 0x3fddac becomes `idle_validation_switch_state_at_throttle_validation_process_error_cal`.
- **Singles:**
  - 0x4062d2 becomes `cylinder_residual_gas_mass_upper_limit`.
  - 0x409524 becomes `fuel_pressure_governor_demand_check_low_idle_speed_window`. The dump value is 0, so that check can never set in this calibration.
  - 0x40b204 becomes `cruise_rpm_ratio_integral`. It integrates the engine speed to vehicle speed ratio change and drives the clutch cutout (denied code 11) for manual transmissions.

**Drift:** none. No offset in my bin falls in the known drift ranges. Three e2m descriptions read opposite to the code, but the offsets are right, so all three are keeps with a note:
- 1B2C +8: the text says maximum, the code compares count < value (a minimum). I renamed this row.
- 8000 +6: the text says minimum duration, but the value is a cap on the passes in the low pressure fixed mode.
- 8C5F +0: the text says "if vehicle speed > this", but the code sets the flag only below it.

**Function names my evidence shows are wrong (not applied automatically)**
- 0x00017560 `cm848_fuelDemandSmoothingController` → `cm848_debounceIdleValidationSwitchFaults`. It debounces the idle validation faults P2121 (fault 63), P2127 (fault 62) and P2128 (fault 68) and saves the switch 7 state. There is no fuel demand smoothing in it.
- 0x000428d4 `cm848_setEngineOperatingMode5` → `cm848_selectUserCommandedFueling`. It sets FUELING_STATE_CALIBRATED_FIXED_FUEL_DEMAND (USERCOMD) from `user_commanded_fueling_cal`.
- 0x005127d8 `governor_cruise_speedError_integrate` → `cm848_integrateCruiseRpmRatioChange`. It integrates the N/V ratio change, not a speed error.
- 0x000429a0, 0x00042a2c, 0x00042ab8, 0x00042b44 `cm848_{init,process}ProtectionParameter{1,2}` → `cm848_{initialize,process}InjectorDriverBoosterCapacitor{1,2}VoltageChannel`. These are the Type B sensor channel wrappers for channels 54 and 55; keep the repo's wrapper suffix convention.
- Lower-confidence leads: the gain-set selectors 0x00028670 `cm848_processGovernorLoadCondition` (user gain state 0 or 1), 0x0004256c `cm848_processGovernorSpeedSetpoint` (0, 2 or 3), 0x00028a14 `cm848_updateGovernorSetpointParameters`, 0x000289d0 `cm848_selectGovernorSetpointSource` and 0x00028b38 `cm848_getGovernorOverrideSource`. They select and load the low speed governor gain set, not a load condition or setpoint.

**Out-of-bin siblings, still open (in no bin)**
- 0x0005c37e `j1939_pgn65249_cal_b` → `engine_retarder_configuration_maximum_speed`. It is e2m 10FC +14 (32000 = 4000 rpm) and carries the same wrong prefix and a `_cal` on ROM.
- 0x003fd1dc `cam_sync_validation_dwell_counter` and 0x003fd1de `cam_sync_validation_crank_tick_count` → `fuel_pressure_sensor_pre_start_check_start_delay_counter` and `..._run_time_counter`. They sit in the boot-image window, so check app users first.
- The compressor map tables, all ROM-copied so no `_cal`:
  - 0x4065c6 `fuel_timing_boost_scale_yend_cal` is the grid → `compressor_map_grid`.
  - 0x4066b8 `..._axis1_cal` is the corrected air flow axis → `compressor_map_x_axis`.
  - 0x4066d0 `..._ystart_cal` is the turbocharger speed axis → `compressor_map_y_axis`.
  - 0x4066e8 `fuel_timing_correction_b_axis_cal` and 0x406712 `..._output_cal` are the inlet temperature square root table → `compressor_inlet_temperature_square_root_axis` and `_values`.
- The booster capacitor channels: 0x40be52 and 0x40be54 `sensor_channel54/55_fault_status`, and 0x40b722 and 0x40b72e `protection_param_1/2_channel_state`.
- 0x003fb54a `engine_retarder_fuel_demand_at_minimum_pass_counter`. It counts passes with final_fueling at or below the threshold, so `..._at_or_below_threshold_pass_counter` fits; its name came from the old misname.
- The rest of block 10ED, 0x40ae76 to 0x40ae8a, which should join `low_speed_governor_*`:
  - 0x40ae76 `governor_speed_setpoint_raw` is the LSG P gain at +0, 0x40ae78 `governor_d_gain_from_table` is I at +2, and 0x40ae7a `governor_p_gain_from_table` is D at +4.
  - 0x40ae80 `governor_j1939_mode_override` is the FSS override state at +A, which nothing in the application writes.
  - 0x40ae82 to 0x40ae88 are the FSS gain copies at +C to +12, and 0x40ae8a `governor_j1939_gain_extra_working` is the jerk gain at +14.

**Siblings other bins already took:** 0x408728 → `cruise_rpm_ratio_integral_limit`, 0x4065c4 → `compressor_outlet_temperature_default`, and the four governor gain tables.

**For the caller to align**
- The four gain tables are named two ways by the other bins. Bins 2 and 3 name the first word: 0x4070e6 `low_speed_governor_default_proportional_gain`, 0x408eda `..._mid_gear_...`, 0x408ed2 `..._high_gear_...`. Bin 5 names the whole set: 0x4070aa `low_speed_governor_aggressive_gain_set`. All four are the same 4-word P/I/D/jerk set. The gain state selects: 0 → 0x4070e6, 1 → 0x4070aa, 2 → 0x408eda, 3 → 0x408ed2, 4 → the TSC1 table at `j1939_low_speed_governor_proportional_gain`. Pick one form.
- Same point, two wordings: 0x5c370 uses `peak_torque_speed` while 0x5c380 uses `point_5_torque_percent`.
- Same booster capacitor signal: my `booster_capacitor_1/2` against the existing `injector_group_a/b_supply_voltage_linearization_*` tables.
- 0x409522 keeps `..._at_governed_speed` while 0x409524 now says `low_idle`; the keep note records that governed speed is the low idle.

**Type notes (nothing changed)**
- 0x409530 `fuel_pressure_too_high_count_limit` should be `byte`: the e2m record is 1 byte (+1B is padding) and the only load is `lbz`, but the row is `word`.
- 0x408982 is loaded with `lha` although its record is unsigned and the row is `word`; the value is 1, so it is harmless.

**Note on comments:** I wrote no "(was ...)" parts, so the apply can add them and append the old comment as "earlier note".


## Bin 5

### Prompt

You are agent 5 of 6 in rename wave 15 of the CM848 firmware naming project (reverse engineering of a Cummins ECU; decompiled with Ghidra).

1. Read the brief first and follow it exactly: /home/linux/.claude/jobs/374b0424/tmp/w15/brief_W15.md
2. Your bin: /home/linux/.claude/jobs/374b0424/tmp/w15/bins/bin5.json (62 records).
3. Your result file: /home/linux/.claude/jobs/374b0424/tmp/w15/results/result_W15_bin5.jsonl
   - Exactly one JSON line per record of your bin (62 lines), in the brief's output format.
   - Append to it as you finish each e2m block, so partial work survives an interruption.
4. Your scratch folder: /home/linux/.claude/jobs/374b0424/tmp/w15/agent_scratch/bin5/
5. Do not edit, create or delete any other file. Do not run analyze.sh, git or any build.
6. Finish with the summary the brief asks for.

### Report

Bin 5 is complete: 62 lines in /home/linux/.claude/jobs/374b0424/tmp/w15/results/result_W15_bin5.jsonl. Every line parses and the file is ASCII-only. My validator passes: each address once, `old` equals the bin label, the keys fit the verdict, new names are unique and absent from the .cpp and CSVs, `_cal` matches the region, every `code_quote` is verbatim inside its function, and no comment cites a renamed old name. The read-only cross-check against the other bins' result files shows no name collisions. The validator and the `verdicts_*.py` sources are in /home/linux/.claude/jobs/374b0424/tmp/w15/agent_scratch/bin5/ (`emit.py --final`); the full leads are in `leads.md` there.

**Counts:** 35 confirmed renames, 26 keeps, 1 drift, 0 uncertain.

**Type issues (apply with the renames):**
- 0x3ffcaa `throttle_rate_pid_gain_cal` is typed dword, but it covers two records. e2m 16A1 +12 C_TGC_Turbo_Drt_Scale_Gain is a signed 2-byte word read with `lha`. 0x3ffcac (+14 C_TGC_E_Brake_LLim, the floor while the engine retarder is active) has no row of its own. Until the dword is split into i16 + word, the floor renders as `wastegate_duty_turbocharger_speed_derate_scale_gain._2_2_`.
- 0x4070aa `governor_setpoint_table_cal` is typed byte, but it is the base of a 4-word signed gain record {P, I, D, J}. The same layout sits at 0x4070e6 and 0x40ae76. Retype to i16[4] or one struct.
- Units: the CSV comments call `compressor_outlet_temperature` (0x40a616) 1/64 F and the 0x3ff720 limit "14080 = 220 F". The e2m and the code agree on 1/32 F: the estimate's 1/2048 table ratio times the 1/64 F Rankine ambient, shifted right 12, with floor 0xc680 = -460 x 32. So the limit is 440 F, the dump value 1662 is 52 F, and the new 0x4065c4 default 3200 is 100 F.

**Families renamed:**
- **Output driver diagnostics (e2m 1042), 3 rows:** `auxiliary_driver_*` / `cruise_driver_*`. The old names carried `std` and `ch19_20`.
- **Low speed governor, 10 rows (1064 x7, 10EE x2, 1046 +0):** `low_speed_governor_*`, with the wrong `_cal` and `init` removed. The old names also swapped terms: the old "integral clamp" limits the derivative term, and the old "derivative clamp" limits the jerk term. The row at 0x4070b2, the aggressive-gain minimum run time, is renamed because its old "load" matches nothing in the code. The cruise/road speed governor neutral-fuel ramp (0x3feff0) follows bin 6's 0x408e6e name.
- **Alpha / electronic smart power / programmable power:** 0x3fd514 and 0x3fd516 are now `user_override_alpha_cal` and `electronic_smart_power_override_alpha_cal`. 0x40a2c4 `electronic_smart_power_tau` replaces a bogus "governor startup threshold". 0x40a280 `programmable_power_active_selection` replaces `torque_limit_init_flag`.
- **J1939 anti-theft:** 0x3fdd8a and 0x3fdd8c are `j1939_anti_theft_*_cal`. They are two of the four 2-bit fields in the PGN 56360 status byte, so the old `governor_prop_status_bits_*` names are wrong.
- **Trip, tires, power take-off:** 0x3fdd70 `trip_distance_cal` (the PGN 65248 trip field, scale 1/64 mile, never written), 0x3fdd92 `new_tires_installed_flag_cal`, and 0x40a2b0 `power_take_off_disable_flag`.
- **Droop offset:** 0x40b6b4 `vehicle_speed_limit_fueling_bottom_droop_offset`, the twin of the existing top droop offset.
- **TSC1 lost management:** 0x3feb90 `tsc1_lost_management_maximum_accelerator_pedal_cal`, which needed `_cal`.
- **Wastegate duty controller, 6 rows (16A1):** `wastegate_duty_*_gain`. The old names were throttle, governor-rpm and fuel-flow guesses.
- **Others:** 0x3fd4b8 `ecm_hardware_type_identifier_cal` (the dump holds ASCII "C6"), 0x4065c4 `compressor_outlet_temperature_default`, 0x5c7b8 `vehicle_engine_type_sales_code` (PCI message 0xED payload byte 4, by the same byte counting as the body style), and 0x5c788 `intake_air_heater_crank_time_limit`.

**Drift:** 0x6443c (162A +18 IAH_On_Max_Time). Block 162C +0 (the x vector of the heater threshold lookup) resolves to the same address. The ROM holds the table's length word 14 there, so the 11.45 scalar has no storage in 11.46, and the current axis name matches the code. The other seven 162A rows are keeps. 8A2B +0 agrees with the code; the known 8A2B / 8A37 drift is the +24 tail.

**Function names that are wrong (not applied automatically):**
- 0x28670 `cm848_processGovernorLoadCondition` -> `cm848_updateLowSpeedGovernorGainLogic`. It is the aggressive-gain logic (10EE / 10EF); no load is involved.
- 0x27e4c `cm848_updateSpeedProtectionLimits` -> `cm848_presetLowSpeedGovernorIntegrator`. It is the integrator preset, not a speed protection.
- 0xfe5c `cm848_calculateFuelTimingTarget` -> `cm848_calculateAllSpeedGovernorThrottleReference`. It writes e2m 107A +0 / +2 / +14 / +16 from the pedal; no fuel timing.
- 0x23be0 `cm848_sendJ1939ProprietaryStatus` -> `cm848_sendJ1939AntiTheftStatus`.
- 0x233a0 `cm848_j1939HandleProprietaryCommand` -> e.g. `cm848_j1939HandleServiceResetCommand`. Byte 1 = 0x20 sets the oil change monitor reset flag, 0x30 sets new tires.
- 0x51736c `cm848_updateIntakeAirHeaterRunupPhase` -> `...CrankPhase`. Control state 3 is "crank" per e2m 8A35 +2.

**Out-of-bin siblings:**
- **Low speed governor, swapped P / I / D / J names (most useful lead).** The gain sets are 4 words P, I, D, J, read through `governor_setpoint_table_ptr`.
  - Working set (10ED): 0x40ae76 `governor_speed_setpoint_raw` is the P gain. 0x40ae78 `governor_d_gain_from_table` is the I gain. 0x40ae7a `governor_p_gain_from_table` is the D gain. 0x40ae8a `governor_j1939_gain_extra_working` is the J gain.
  - Default set (10EC): 0x4070e6 `governor_setpoint_table_a` is P. 0x4070e8 `governor_j1939_d_gain_default_cal` is I. 0x4070ea `governor_j1939_p_gain_default_cal` is D. 0x4070ec `governor_j1939_i_gain_default_cal` is J.
  - Terms (1065): 0x40ae96 `governor_speed_weight_a` is the proportional term. 0x40ae98 `governor_speed_weight_b` is the derivative term. 0x40ae9a `governor_fuel_demand_correction` is the integral term. 0x40ae9c `governor_speed_error_derivative` is the jerk term.
  - The remaining 1064 constants at 0x4070b6-0x4070de, the 1065 clamps and adjustments at 0x40ae9e-0x40aea8, and 0x4070b4 (wrong `_cal`) belong to the same family: same `governor_*` prefix and wrong `_cal`. Their records are listed in `leads.md`. 0x40ae74 `governor_enabled_flag` is e2m 10EF +0 LSG_Gain_Logic_Flag, where 0 means allow, so "enabled" reads backwards.
  - Bins 2, 3, 4 and 6 already carry some of these: 0x4070e6, 0x40ae9a, 0x40aea4, 0x40aea6, 0x40aeae, 0x40ae7c, 0x40ae7e, 0x408e6e, 0x40a3e0 and 0x40a3e2. Their `low_speed_governor_*` and `wastegate_duty_*` families match mine.
- **Comment fix:** 0x40a034 `cruise_driver_fault_match_debounce_threshold` says "Other outputs: fault_match_debounce_threshold_std". It should name `auxiliary_driver_fault_match_debounce_threshold`.
- **Other siblings:**
  - 0x3fd51c `j1939_pgn_priority_cal` is e2m 1292 +0 Application_Identifier. EEPROM 0x9a holds ASCII "00", field 6 of the same PGN 65242 message.
  - J1939 anti-theft rows to rename to `j1939_anti_theft_*`, with `_cal` for the 117F mirror rows: 0x3fdd80 `governor_prop_status_bits_1`, 0x3fdd86 `governor_prop_status_byte_b`, 0x3fdd8e `governor_prop_status_pending_flag`, 0x3fdd90 `governor_prop_status_bits_3`, and 0x40a2c2 `j1939_prop_status_tx_state`.
  - Wastegate controller: 0x3ffca2 `governor_rpm_error_gain_cal` (P-gain rate limit), 0x3fa190 and 0x3fa1a6 `governor_rpm_band_rate_*`, 0x3fa176 `fuel_demand_delta_working`, 0x3fa184 `fuel_demand_quantity_snapshot`, and 0x3fa182 `fuel_flow_rate_prev_snapshot`.
  - Intake air heater: `intake_air_heater_runup_*` (0x3fce3f countdown, elapsed ticks, rpm-below count) is the crank phase.
  - 0x40b4d0 `pci_transmit_message_19_byte_4` -> `pci_transmit_message_19_engine_type_sales_code`.
  - CM550 twin: 0x80a9e0 (unnamed `_DAT_0080a9e0`, stored 0 by the shared `initializeEngineSpeedLimitDefaults`) is the same e2m 117D +18 word; its name should agree.


## Bin 6

### Prompt

You are agent 6 of 6 in rename wave 15 of the CM848 firmware naming project (reverse engineering of a Cummins ECU; decompiled with Ghidra).

1. Read the brief first and follow it exactly: /home/linux/.claude/jobs/374b0424/tmp/w15/brief_W15.md
2. Your bin: /home/linux/.claude/jobs/374b0424/tmp/w15/bins/bin6.json (65 records).
3. Your result file: /home/linux/.claude/jobs/374b0424/tmp/w15/results/result_W15_bin6.jsonl
   - Exactly one JSON line per record of your bin (65 lines), in the brief's output format.
   - Append to it as you finish each e2m block, so partial work survives an interruption.
4. Your scratch folder: /home/linux/.claude/jobs/374b0424/tmp/w15/agent_scratch/bin6/
5. Do not edit, create or delete any other file. Do not run analyze.sh, git or any build.
6. Finish with the summary the brief asks for.

### Report

## Bin 6 report: 65 records reviewed

Result file: /home/linux/.claude/jobs/374b0424/tmp/w15/results/result_W15_bin6.jsonl (65 lines, one per record). I edited no other file. Scratch is in /home/linux/.claude/jobs/374b0424/tmp/w15/agent_scratch/bin6/.

**Checks run**
- My own validator is clean. It covers: name format, banned abbreviations, the `_cal` rule, new name absent from the CSVs and the .cpp, new names unique, and every `code_quote` found verbatim in its function.
- A mirror of the gate's row check is clean: exactly one `global_variables.csv` row per address with name equal to `old`, and no register addresses.
- No name clashes with the bin 1-5 result files.
- The permission classifier refused a dry run of `apply_renames.py`, so the real gate has not been run. Please run it.

**Counts:** 34 keep, 30 confirmed (rename), 1 uncertain, 0 drift. Every record's `other_records_at_this_address` was empty, and the code matched the record's role and value range throughout.

**Families renamed**
- **Alpha results, block 104A:** 0x40a16e, 0x40a172, 0x40a174 become `alpha_air_fuel_control_result`, `alpha_on_governor_result`, `alpha_low_speed_governor_result`. They had `pressure_fuel_delay_*` / `fuel_rate_condition_status`.
- **All speed governor (ASG) leftovers, block 107D, old `fuel_demand_*` wording:**
  - 0x3ff68e becomes `all_speed_governor_switch_droop_fueling_offset`.
  - 0x3ff6a0 becomes `all_speed_governor_delta_offset`.
  - 0x3ff6c8 becomes `all_speed_governor_delta_upper_limit`.
  - 0x3ff6c4 becomes `fuel_demand_ramp_drivetrain_ratio_threshold`. It had `engine_temp_protection_threshold`, but the code compares it with `drivetrain_ratio`.
  - 0x3ff6b8 becomes `rpm_deceleration_limit_target_rate_high_zone`.
- **ASG application record, block 1170:** 10 rows `engine_operating_mode_restore_*` become `all_speed_governor_application_*` (see the either/or below).
- **J1939 torque points:** 0x40ad96 and 0x40ad98 had `protection_speed_ratio_c` / `_d`. They become `j1939_indicated_percent_torque_at_point_3_times_256` and `..._point_4_times_256`.
- **Cruise:**
  - 0x408e6e becomes `cruise_road_speed_governor_minimum_fuel_ramp_rate`. I aligned it with bin 5's name for 0x3feff0, `cruise_road_speed_governor_neutral_fuel_ramp_rate`.
  - 0x3fd920 becomes `cruise_feedback_uses_road_speed_flag_cal`. It was missing `_cal` on an EEPROM row.
- **Single rows:**
  - 0x5c29a becomes `accelerator_pedal_fault_delay`.
  - 0x40a885 becomes `master_slave_final_override_alpha`.
  - 0x3fd51c becomes `application_identifier_cal`.
  - 0x5c94c becomes `high_speed_governor_compensator_transition_coefficient`.
  - 0x642c4 becomes `underboost_minimum_engine_speed`.
  - 0x642ba becomes `boost_pressure_sensor_high_reading_idle_reference_speed_offset`. It follows the existing `misfire_monitor_idle_reference_speed_offset`.
  - 0x3ff07a becomes `ambient_air_flow_filter_coefficient`.
  - 0x3fee98 becomes `fuel_system_hardware_shutdown_error_count_cal`.

**Uncertain:** 0x40ae56 `emission_fault_overflow_flag` (e2m 1080 +0 Software_FLT2ERAS, "FAULT TO ERASE"). It has one store of 0 in `cm848_clearDiagnosticState` and no reads. No code line shows a role, and the current name has no support either. `diagnostic_fault_to_erase` is the likely name.

**Drift:** none.

**Type notes** (types not changed)
- 0x3ff6b8: the row is `word`, its one load is `lha`, and the e2m says unsigned. This is in the evidence.
- 0x408e5e `cruise_fuel_demand_floor` (a keep): `word` row, `lha` load, e2m unsigned.

**Decision for you: block 1170 is either/or.** The e2m calls block 1170 +C..+3C (the 25 words 0x40a216-0x40a246) "ASG application specific" (+3C "application defined"). Fueling state 30 carries the e2m label ASG_APPL. No code in either bank stores to these words, and the .cpp uses them only inside `cm848_restoreEngineOperatingMode`, so "restore" has no saving code behind it. The sibling set for mode 7 is `all_speed_governor_throttle_mode_*`, which is why I chose `all_speed_governor_application_*`. Either rename all of the following together with my 10 rows, or skip my 10 rows (0x40a216, 218, 222, 226, 228, 22a, 22c, 22e, 230, 244).
- The 15 other rows `engine_operating_mode_restore_X` become `all_speed_governor_application_X`. Addresses: 0x40a21a, 21c, 21e, 220, 224, 232, 234, 236, 238, 23a, 23c, 23e, 240, 242, 246.
- Function `cm848_restoreEngineOperatingMode` @ 0x0000fb28 becomes `cm848_selectAllSpeedGovernorApplicationMode`.
- Enum member `FUELING_STATE_ALL_SPEED_GOVERNOR_RESTORE` (30) becomes `FUELING_STATE_ALL_SPEED_GOVERNOR_APPLICATION`.

**Function names my evidence shows are wrong (not applied)**
- 0x00525504 `protectionOutputActuatorControl` is the cruise / vehicle speed governor PID, run every pass from `cm848_periodicTaskSet_outputs`. Proposed `cm848_runCruiseAndRoadSpeedGovernor`.
- 0x005251e4 `protectionRampRateControl` starts or resets the cruise ramp and PID state. Proposed `cm848_initializeCruiseAndRoadSpeedGovernorRamp`.
- 0x00017560 `cm848_fuelDemandSmoothingController` debounces and latches the accelerator pedal idle validation faults and does no smoothing. Proposed `cm848_monitorAcceleratorPedalIdleValidationFaults`.
- 0x00529068 `cm848_protection_timer_init` is the engine-shutdown fuel system hardware check. Proposed `cm848_monitorFuelSystemHardwareShutdown`.
- 0x00528b90 `cm848_tpu_interrupt_flag_init` (de-abbreviate `init`) initialises the TPU injection channels. Proposed `cm848_initializeTpuInjectionChannels`.
- The plate comment of `cm848_monitorBoostPressureSensorAndUnderboost` still says "target speed" for engine speed.
- Unverified lead: `cm848_updateProtectionParameters` (0x20b84) and `cm848_updateProtectionInputs` (0x20bfc) load derated J1939 torque curve points.

**Out-of-bin siblings sharing a wrong prefix or a `_cal` break** (I grepped `global_variables.csv` per prefix)

*Accelerator pedal throttle fault, block 1048:*
- 0x5c2a4 `fuel_demand_rate_limit_debounce_cal` (e2m +16 Throttle_Fault_Delay_At_Idle, `_cal` on ROM) becomes `accelerator_pedal_fault_delay_at_idle`. This one is needed to pair with 0x5c29a.
- 0x3fa6e2, 0x3fa6e4, 0x3fa6e6 `fuel_demand_cal_increment_a/_b/_c` (the three fault debounce counters) become `accelerator_pedal_fault_debounce_count_a/_b/_c`.
- 0x5c29e `fuel_demand_cal_offset` (Auto_Zero_Offset) becomes `accelerator_pedal_autozero_offset`.
- 0x5c294 `throttle_fuel_demand_threshold_cal` (Highest_Throttle_Min, `_cal` on ROM) becomes `accelerator_pedal_highest_valid_minimum`.

*ASG decel limit and delta, block 107D:*
- 0x3ff6b0 `engine_rpm_delta_offset_cal` (+2A) becomes `rpm_deceleration_limit_target_rate`.
- 0x3ff6b2 `fuel_demand_integrator_gain_a_cal` (+2C) becomes `rpm_deceleration_limit_integral_gain`.
- 0x3ff6b6 `fuel_demand_integrator_gain_b_cal` (+30) becomes `rpm_deceleration_limit_proportional_gain`. The code uses it for the proportional term, not an integrator gain.
- 0x3ff6c6 `fuel_demand_integrator_divisor_cal` (+40 ASG_Delta_Droop) becomes `all_speed_governor_delta_droop`.
- 0x3ff69c `fuel_demand_pilot_active_flag` is a dword. It is +16 ASG_Deadband_Compensation_Flag, and the word at 0x3ff69e is +18 Decrement_Rate. Proposed `all_speed_governor_deadband_compensation_flag`.
- Optional: 0x3ff6bc `engine_rpm_high_zone_threshold`, and my kept 0x3ff6ba `rpm_drop_fuel_minimum_manifold_pressure`, could join `rpm_deceleration_limit_*`.

*Cruise:*
- 0x3feff0 is in bin 5, which already renames it.
- 0x3fb522 `fuel_demand_corrected_working` is the cruise ramp-down working value. Proposed `cruise_transition_fuel_working`.

*Predicted vehicle speed, old `fuel_flow_rpm_*`:* bin 1 renames 0x40b6e2 and bin 3 renames 0x40b6fe. 0x3fd05c `fuel_flow_rpm_divisor_prev` is still left.

*High speed governor compensator state, wrong `cruise_speed_*` prefix:*
- 0x3fb55a `cruise_speed_rpm_prev_snapshot`
- 0x3fb55c `cruise_speed_factor_a`
- 0x3fb55e `cruise_speed_factor_b`
- 0x3fb560 `cruise_speed_offset`
- 0x40b704 `cruise_speed_rpm_base`
- 0x40b708 `cruise_speed_override_flag`
- 0x40b70a `cruise_speed_offset_saved`

*Ambient air flow filter:*
- 0x3fb9ea `boost_pressure_timing_filter_state` and 0x3fb9d8 `boost_pressure_timing_ema_filtered` share my wrong prefix.
- The same module has `boost_fuel_timing_demand_filter_output` (0x3fb9d6) and the relative humidity table `boost_fuel_rpm_blend_*` (0x3fb9f2, 0x3ff3dc, 0x3ff404, 0x3ff426).

*Fuel system hardware shutdown check:* 0x3fd0bb `tpu_init_restart_pending_flag` (`init`), 0x3fd0ba `tpu_protection_enable_flag`, 0x3fd0b8 `protection_crank_event_counter`.

*Application identifier:* 0x3fd4b8 is in bin 5, renamed to `ecm_hardware_type_identifier_cal`, which pairs with my `application_identifier_cal`.

**Optional notes**
- **Rock cycle:** the repo names the e2m rock cycle feature by its park/neutral exit trigger. I kept 0x40a32c and 0x4086da (and the `park_neutral_exit_engine_speed_limit_*` family). The match is confirmed: e2m TC_Rock_Cycle_Enable (106B +58) is `fuel_feature_control_flags` bit 3, which is the gate in `cm848_calculateParkNeutralExitEngineSpeedLimit`.
- **`temperature_protection_*` rows:** the rows used in that function are the TC_Rock_Cycle parameters of e2m 8C2A. That block is not in the dumped table, but the layout matches from 0x408b6c.
  - 0x408b6e `temperature_protection_fuel_lower_cal` (Commanded_Throttle_Min)
  - 0x408b70 `temperature_protection_fuel_upper_cal` (Commanded_Throttle_Max)
  - 0x408b72 `temperature_protection_trim_threshold_cal` (Road_Speed_Max)
  - 0x408b76 `temperature_protection_timer_threshold_cal` (Active_Too_Long_Time)
  - 0x3fb4e0 `temperature_protection_timer`
  - All have `_cal` outside the EEPROM mirror, and the names are misnomers.
- **Stale `target_rpm` wording:** `engine_speed_state.engine_speed` was once `target_rpm`. It still shows in these rows:
  - 0x408722 `cruise_target_rpm_max`
  - 0x408730 `cruise_target_rpm_min`
  - 0x3fb3ae `engine_acceleration_target_rpm_previous`
  - 0x3fb590 `target_rpm_snapshot`
  - the first two are compared with `engine_speed_state.engine_speed`.
- **Kept on purpose:** 0x3ff6c0 and 0x3ff6c2 `fuel_demand_ramp_rate` / `fuel_demand_ramp_step` are kept. The keep note carries the below/above-threshold distinction.
