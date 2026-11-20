W14 globals2 is done: 63 lines in bin order, written to /home/linux/.claude/jobs/f6a06670/tmp/fueling_state/stage9/result_W14_globals2.jsonl. Nothing else was edited; no builds, no commits. My scratch is in /tmp/w14_globals2/.

My own checks passed. `old` equals the CSV name on all 63 lines, and 63 lines match the bin order. Every code_quote is one physical .cpp line. Names pass the gate rules and clash with no CSV, .cpp or .hpp name, nor with any other `result_W14_*` file present at the end. Every comment is 400 characters or less and passes the sweep. I re-read all dump values from cm848_ram.bin and they match `dump_raw`.

## Counts
- 61 confirmed renames, 2 keep, 0 drift, 0 uncertain, 0 splits (no `width_problem` in the bin).
- 38 renames only drop a wrong `_cal`; 2 add a missing one (0x3feaa2, 0x3fedbc).
- Shared-name holds: none. No old name in the bin appears in CM550's CSVs or the cross-firmware maps.

## Families renamed
- **81AE cylinder balance (23 rows):** `cylinder_balance_*`, all with a wrong `_cal` dropped.
  - 12 reference rows become `cylinder_balance_reference_{1,2}_cylinder_{1,5,3}_{real,imaginary}`. The old 6cyl/4cyl split was wrong: Reference_2 is used by both 6- and 4-cylinder engines.
  - Filter rows use `_filter_coefficient`, following wave 13.
  - Plus `reference_3`, start tooth, reset enable, intake manifold temperature threshold, cutout disable time, component 3 adjustment, Fourier threshold and compensation reference speed.
- **81B0:** `cylinder1..5_timing_offset` become `cylinder_balance_acceleration_buffer_1..5`.
- **81A9 equivalent throttle governor (9 rows):** `equivalent_throttle_*` (tracking integral gain, minimum droop slope, cruise control / power take-off adjust gains and down speed errors, negative adjust enable and minimum fueling, positive adjust fueling margin). All `_cal` dropped.
- **Alpha (3):** `alpha_fuel_rate_filter_state` and the two `alpha_*_timer_active_flag` rows.
- **Fueling selection (3):** `total_fueling_selected` (it holds the clamped value too), `total_fueling_previous_pass`, and the EEPROM freeze frame `total_fueling_before_shutdown_or_excess_injection_fault_cal`. There is no timing in any of them.
- **Commanded throttle filter (3):** `commanded_throttle_filter_coefficient_lookup_result`, `..._cached_axis_offset`, `commanded_throttle_filter_state`.
- **Others:**
  - `throttle_100_speed_points_request_bit` and `..._initialized_flag`
  - `low_speed_governor_alternator_load_filter`, named `_filter` because it is a signed-filter record
  - `fault_registered_bits_592_to_607`
  - `recent_fault_dtc_codes_cal`
  - `four_dimensional_fueling_interpolation_factor` (it is alpha-driven, not thermal)
  - `power_down_refresh_enable`
  - `j1939_engine_speed_at_point_4` / `_5`
  - `charge_pressure`
  - `oxygen_flow_delay_volume_fraction`, `egr_flow_downstream_model_select`, `egr_flow_delay_fraction`
  - `ambient_air_pressure_initial_scaling_factor`
- **Keeps:** 0x40b56a and 0x40b56c, the P0720 timers. The code matches 8C4E +0 / +2; the 8C58 +C / +E records that also resolve there are the known 8C58 tail overlap.

## Drift and judgment calls
- **0x4086c6:** the bin's record (8A14 +2C) is the known drift. I renamed from 8A2A +0 APC_Initial_Scaling_Factor, which the code matches (barometric pressure x it / 100, 107 in the dump). The result is the y axis of the heater preheat table (ROM 0x5b3d8: 1257..1823 counts = 20..29 inHg). Treat as plain drift if you prefer.
- **0x4002e8:** 9552 in the dump is above the record's 0..1 range (8192 = 1.0), so the code's `< 0x2001` test takes its 0xffff branch. I judged it not drift: +8 and +A on the same block match the code.
- **0x3fedbc:** the bin showed no e2m record. `e2m_block_addresses.py --address` gives 128A +0 Recent_J2012_Codes_Table, so the audit misses array rows. The old comment ("SPN history") is wrong; the values are BCD DTC codes. I set `old_comment_wrong: true`.
- **0x40c04c:** xref shows 0 reads and 2 writes, so the "enable" polarity rests on the e2m text and the initial value 1.
- **0x40a42e:** I chose `charge_pressure` (e2m base name) over a `_selected` form like `barometric_pressure_selected`. The +2 word is Charge_Press_Source.
- **0x409080:** the e2m says "fueling below which ...", but the code needs `min <= final_fueling` (a minimum). The name follows the code and the evidence quotes the compare.

## Held or flagged rows
- **0x40a406:** `type_note` holds it (struct instance).
  - The type `boost_pressure_state_t`, its field names and the seven dotted label rows 0x40a408..0x40a414 must change with it.
  - The `type_note` gives field -> record: `load_input` is the intake manifold temperature in Rankine (177D +2), and the last two words are 177B +0 / +2.
  - New name `charge_flow_estimate_terms`.
- **0x3fea22:** it keeps the family name `fault_registered_bits_592_to_607` without `_cal`, against the brief's region rule. All 49 fault_detected / fault_registered / fault_previous_pass bit rows in the mirror, including its twin 0x3fe9be applied in wave 13, have no `_cal`. The strict rule would add `_cal` to all 49. The `evidence` and a `cal_note` field say so.

## Notes for the apply
- `comment` is at most 400 characters and sweep-clean.
- `evidence` is not: it quotes old names, so do not write it into the CSV.
- Comments cite current function names. Renamed in the other result files (comments not updated):
  - cm848_calculateSensorEma -> cm848_calculateAlphaFuelRateResult
  - cm848_checkPressureFuelDelayA -> cm848_calculateAlphaLowSpeedGovernorResult
  - cm848_checkPressureFuelDelayB -> cm848_calculateAlphaAirFuelControlResult
  - hpcr_calculateFuelTrimOutput -> cm848_calculateAlpha
  - cm848_initFuelPressureVariables -> cm848_initializeAlpha
  - cm848_calculateLoadBasedFuelTrim -> cm848_calculateDownstreamEgrMassFlow
  - cm848_calculateRpmBasedFuelTrim -> cm848_calculateUpstreamEgrMassFlow
  - cm848_selectFuelTrimMode -> cm848_calculateEgrMassFlowBeforeDelay
  - cm848_boostBasedFuelModifier -> cm848_calculateVolumetricEfficiency
  - cm848_calculateFuelDemandChangeRate -> cm848_filterCommandedThrottle
  - cm848_processJ1939RxMessage -> cm848_setJ1939TorqueCurvePoints2And5AtDroopLineFueling
  - cm848_updateProtectionStateMachine -> cm848_updateJ1939EngineConfigurationTorqueCurve
  - cm848_updateProtectionDiagnostics -> cm848_calculateJ1939TorqueCurveFuelingsAndReferenceFuelings
  - hpcr_processLoadThrottle -> hpcr_filterCylinderBalanceFueling
  - cm848_checkSensorDeviationFlags -> cm848_checkPressureSensorAgreement
  - uds_session_state_init -> cm848_initializeRamRefresh
  - Evidence only: cm848_loadBasedFuelAdjustment -> cm848_calculateChargeMassFlow

## Cross-bin pairs
Checked against the other result files present at the end (no globals4 yet).
- Agree:
  - 0x5be66 -> `alpha_fuel_rate_filter_coefficient`
  - 0x40a17e / 0x40a180 -> `alpha_low_speed_governor_timer` / `alpha_air_fuel_control_timer`
  - 0x4070e4 -> `low_speed_governor_alternator_load_filter_coefficient`
- Differ: 0x406a46 / 0x406a52 are named `commanded_throttle_filter_coefficient_by_throttle_difference_axis` / `_values`. By the table grammar my cache word 0x3fa882 would then be `commanded_throttle_filter_coefficient_by_throttle_difference_cached_axis_offset`. I left my file alone; reconcile when applying.
- 0x40a430-0x40a436 (globals4) are not checked: my base for the +0 word is `charge_pressure`, and the siblings should start with it.

## Leads outside my bin
- **0x409072** `governor_speed_proportional_gain_cal`: it is 81A9 +2 Equiv_Throt_Proportional_Gain, used in the same tracking loop. Should be `equivalent_throttle_tracking_proportional_gain`, and RAM so no `_cal`.
- **81AE siblings with a wrong `_cal` or `cbd`, in no bin:**
  - 0x408ee4 `cylinder_sync_rpm_delta_threshold_cal` (CBD_Delta_Speed_Threshold)
  - 0x408ee6 `fuel_demand_zero_rpm_upper_cal` (CBD_Upper_Speed_Limit)
  - 0x408ee8 `fuel_demand_zero_rpm_lower_cal` (CBD_Lower_Speed_Limit)
  - 0x408ef4 `fuel_demand_setpoint_zero_threshold_cal` (CBD_Motoring_Fuel_Threshold)
  - 0x408ef6 `cbd_enable_flag` (CBD_Enable_N)
  - 0x408f14 `crank_sync_coolant_threshold_cal` (CBD_Coolant_Temp_Threshold, a minimum in the same disable chain as 0x408f16)
  - 0x408f20 (CBD_Cylinders = 6, no row)
- **0x3fb57e** `crank_state_debounce_timer`: the countdown reloaded from 0x408f18. It should be `cylinder_balance_cutout_disable_timer`.
- **0x3feaa0** `governor_mode_code_diag_snapshot`: the previous final_fueling_state latched with 0x3feaa2. It is in the mirror without `_cal` and has banned `diag`. xref: 1 write, 0 reads.
- **0x3fa86e** `governor_diag_entry_latch_flag`: banned `diag`; the latch that `cm848_clearFuelDemandFlag` (0x1e4d8) re-arms from the start-up init list.
- **0x3fd804** `fuel_timing_target_working`: in the EEPROM mirror without `_cal`. It is the FUELING_STATE_FUEL_OVERRIDE fueling that `cm848_selectFinalFueling` reads when `governor_feature_flags & 2`; the same "timing" misread.
- **0x40b1ec** `protection_iat_scaled` and **0x3fb224** `protection_iat_scale_pending_flag`: this is barometric pressure x 1.07, not an intake air temperature. Suggested names: `ambient_air_pressure_initial_scaled` and `..._pending_flag`.
- **Acceleration buffer shape:** 0x40b74c..0x40b75b is one `word[8]` array (e2m 81B0 +12..+20). Code indexes `(&cylinder1_timing_offset)[cylinder_event_seq_counter]` and the misfire monitor indexes it too. Buffers 7 and 8 (0x40b758 / 0x40b75a) have no row. I did not hold the five plain renames for this.
- **Signedness (kept out of `type_note` so renames are not held):**
  - e2m-signed rows read with `lha`: 0x409076, 0x40907a, 0x408ef8-0x408f10, 0x408f16, 0x408f1c, 0x40b74c-0x40b754. `i16` would fit.
  - 0x40907c is an unsigned record read as a signed short.
  - 0x40a42e is an unsigned record, but 4 of its 13 accesses are `lha`.