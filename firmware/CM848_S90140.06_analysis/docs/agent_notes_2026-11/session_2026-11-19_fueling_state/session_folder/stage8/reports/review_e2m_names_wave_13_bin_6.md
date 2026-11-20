Wave 13, bin 6 is done: 63 verdicts in `/home/linux/.claude/jobs/f6a06670/tmp/fueling_state/stage8/result_W13_bin6.jsonl`, one line per bin record, in bin order. Nothing else was edited, built or committed. The repo gate script was blocked by the permission classifier, so I ran a read-only re-implementation of its name rules on the file: BANNED words, `_cal` by region, hex-looking parts, format, old name equals the CSV row. It reports 0 problems. Checks against global_variables.csv, the .cpp and bins 1-5 found no collision. None of my old names is shared with CM550, so none would be held back.

## Counts
- 42 rename (`confirmed`), 20 keep, 1 drift, 0 uncertain.

## Families renamed
- **alpha** (e2m 104A): the `cold_start_*` words, `intake_temp_ema`, `governor_init_countdown` and `fuel_demand_ramp_factor` become `alpha_*`. `timingProtectionFlagsOrchestrator` is the alpha ramp. 6 rows.
- **all-speed governor** (107C): the `fuel_demand_*` / `governor_*` words become `all_speed_governor_*` (6 rows) and `rpm_deceleration_limit_integral_term`. The e2m reset-state block 1170 fixes the state meanings: X1 is the speed error, X6 the fuel correction.
- **data collector**: `diag_dm1_buffer_read_ptr` becomes `data_collector_start_address`, matching bins 1-3, which name the center, end and status words.
- **J1939 control session**: `etc1_*` / `governor_*calib*` become `j1939_*_cal` (3 rows). All three lacked `_cal` in the EEPROM mirror.
- **compressor map** (175F, 3 rows) and **ambient / compressor inlet** (1921, 4 rows): the `fuel_timing_*` and `boost_fuel_*` names become `compressor_*` / `ambient_*`. `ambient_air_temperature_reference` parallels `barometric_pressure_reference`. 1921 +14 is relative humidity, since the code multiplies saturation vapor pressure by it >> 10.
- **exhaust temperature model** (17A1, 2 rows): `boost_target_*` becomes `exhaust_temperature_model_*`.
- **HPCR fuel metering** (8000, 3 rows): `engine_sync_*_cal` becomes `fuel_metering_feedback_trim_{maximum,minimum}_scaling_factor` and `fuel_pressure_sensor_filter_coefficient`. The old `_cal` was wrong for this RAM region.
- **crank** (819B, 7 rows):
  - `engine_sync_startup_countdown` becomes `crank_tooth_period_countdown`. `mpc555_updateEngineCrankState` reloads it on every tooth capture.
  - `crank_sync_valid_flag` becomes `crank_low_speed_filtering_flag`.
  - `crank_mios_timing_output` becomes `crank_tooth_good_window_fraction`. It programs TPU-A channel 1, not MIOS.
  - `engine_event_countdown` becomes `crank_preliminary_sync_count`. I flipped this one from keep because bin 5 renames its `_cal` twin to `crank_preliminary_sync_evaluation_count`.
  - `timebase_previous_capture` becomes `first_speed_interrupt_time_ticks`, and `timebase_delta_ticks` becomes `crank_resync_time_ticks`.
  - `cam_sync_position_min` becomes `fuel_pressure_start_undershoot`. It is the lowest rail pressure reading during the start.
- **Singles**:
  - `pumping_torque_adjustment` (was `fuel_demand_blend_adjusted`)
  - `cylinder_residual_gas_mass_lower_limit`
  - `fuel_temperature_derate_fueling_severity_index_cal` (the first word of the single fault-derate channel record)
  - `water_in_fuel_distance_cal` (the name only gains `_cal`)
  - `cruise_coast_accelerate_hold_time` (was camelCase `cruiseOverride`)
  - `intake_air_heater_monitor_result` (see the judgment call below)

## Drift
- **0x40b9ee** (`misfire_monitor_cylinder_attempt_counts`), e2m 162B +A IAH_Function_Timer. It resolves to the same address as e2m 1651 +0 Misfire_Cyl_1_Attempt_Number, which the code matches. The IAH words end at +8, so 162B +A and +C (IAH_Ratio at 0x40b9f0) have no counterpart. I kept the name.
- **Block 1930 +12**: AATR_Numerator resolves to 0x3feeb8, but the code matches 191A WIF_Miles, not that record.
- **8C5B +A** (not in my bin): PN_Ratio resolves to 0x40b57a. That is `protection_output_hold_flag` in `cm848_monitorConverterClutchAndOverdrivePerformance`.
- **1B2E +A / +C** (not in my bin, unverified): they land on the `wastegate_monitor_fail_high_boost_pressure_axis` word[5] table and an unnamed word.

## Functions whose names the evidence shows are wrong (not auto-applied)

| Address | Current name | Proposed name | Reason |
|---|---|---|---|
| 0xe518 | `hpcr_calculateFuelTrimOutput` | `cm848_calculateAlpha` | selects the alpha source and outputs `combustion_alpha_input` |
| 0xe3a4 | `timingProtectionFlagsOrchestrator` | `cm848_calculateAlphaBase` | the alpha ramp |
| 0xe164 | `cm848_calculateSensorEma` | `cm848_calculateAlphaFuelRate` | fuel rate hysteresis on `fuel_mass_flow_raw` |
| 0xe218 | `cm848_checkFuelRateCondition` | `cm848_calculateAlphaGovernor` | on-governor condition |
| 0xe248 | `cm848_checkPressureFuelDelayA` | `cm848_calculateAlphaLowSpeedGovernor` | low speed governor alpha latch |
| 0xe2cc | `cm848_checkPressureFuelDelayB` | `cm848_calculateAlphaAirFuelControl` | air fuel control alpha latch |
| 0xe360 | `cm848_checkPressureHysteresis` | `cm848_calculateAlphaLowAmbientAirPressure` | barometric hysteresis of alpha |
| 0xe0f4 | `cm848_checkPressureFuelState` | `cm848_calculateAlphaAltitudeDerateLatch` | altitude derate alpha timer |
| 0xe748 | `cm848_initFuelPressureVariables` | `cm848_initializeAlpha` | clears the alpha latches, timers and filter |
| 0x505c20 | `diag_dm1Buffer_circularFill` | `cm848_fillDataCollectorBuffer` | data collector, not DM1 |
| 0x505d94 | `hpcr_exception_process` | `cm848_initializeDataCollector` | sets the collector pointers |
| 0x505df0 | `j1939_dm1_diagnosticMessage_send` | `cm848_sendDataCollectorBuffer` | sends the collector ring over the transport protocol |
| 0x505f98 | `cm848_phase_groupB_calculation` | `cm848_runDataCollector` | uses `data_collector_schedule_cal`, trigger line and count |
| 0x50beec | `governor_sourceData_init` | `cm848_startJ1939ControlSession` | opens an engine or retarder control session |
| 0x50bff4 | `phase_group_a_setupETC1Controller` | `cm848_trackJ1939ControlSessions` | opens, closes and files control sessions |
| 0x50be6c | `governor_calibSnapshot_rollingBuffer_update` | `cm848_storeJ1939ControlSessionInHistoryTable` | 5 x 24-byte history ring |
| 0x255c0 | `cm848_j1939SendDm1ResponseMessage` | `cm848_j1939SendDm8TestResultMessage` | sends PGN 65232 with test id and value |
| 0x130dc | `cm848_calculateBoostPressureOffset` | `cm848_calculatePumpingTorque` | e2m 1781 CHP pumping torque |
| 0x502b6c | `hpcr_fuelFinal_exponentialAverage` | `cm848_calculateAmbientConditions` | e2m 1921 ambient and compressor inlet conditions |
| 0x506e28 | `cm848_auxiliaryControl_exponentialAverage` | `cm848_calculateExhaustTemperatureEstimate` | exhaust virtual temperature and metal temperature |
| 0x50e7f4 | `cm848_blendBoostAndThrottleFuelDemand` | `cm848_calculateWaterVaporFractions` | humidity, vapor pressure and dew point model |
| 0x49004 | `cm848_resetEngineSyncState` | `cm848_resetFuelPressureGovernorState` | its own plate comment says it resets the fuel pressure governor |

## Out-of-bin twins left half-renamed
- **0x4062d2** `boost_pressure_ratio_upper_limit` should be `cylinder_residual_gas_mass_upper_limit` (e2m C_CBP_Residual_Mass_Max).
- **Alpha siblings:** all are alpha results or timers, none is a pressure or fuel-rate flag.
  - 0x40a16c `governor_startup_state` → `alpha_state`
  - 0x40a16e `pressure_fuel_delay_b_status` → `alpha_air_fuel_control_result`
  - 0x40a172 `fuel_rate_condition_status` → `alpha_governor_result` (it is the On Governor result and now reads confusingly next to `alpha_fuel_rate_result`)
  - 0x40a174 `pressure_fuel_delay_a_status` → `alpha_low_speed_governor_result`
  - 0x40a17a `pressure_hysteresis_state` → `alpha_low_ambient_air_pressure_result`
  - 0x40a17e / 0x40a180 `cold_start_timer_a` / `cold_start_timer_b`, 0x3fa0da / 0x3fa0dc `cold_start_timer_*_active_flag`
  - 0x3fa0d2 `cold_start_intake_temperature_filter_state`, 0x5be66 `cold_start_intake_temperature_filter_coefficient`
- **107C siblings** to take `all_speed_governor_*`: 0x40a1aa, 0x40a1b2, 0x40a1b8, 0x40a1ba, 0x40a1bc, 0x40a1c4, 0x40a1cc, 0x40a1d4, and 0x40a208 `fuel_demand_integrator_b_sum` (e2m Decel_Limit_Fuel).
- **Compressor map:**
  - 0x40a60e `boost_pressure_normalized` → `compressor_map_corrected_air_flow`
  - 0x40a612 `fuel_timing_boost_scale_lookup` → compressor map output ratio
  - 0x40a618 `fuel_timing_state_code` → `compressor_outlet_temperature_source`
- **Other siblings:**
  - 0x40a418 and 0x40a41c (CHP nominal delta-P and pumping torque without offset)
  - 0x40a682 `boost_target_load_rpm_output` → `exhaust_temperature_model_energy_fraction`
  - 1921 sources and pressure drop: 0x40a198 / 0x40a19c / 0x40a1a0 / 0x40a1a2 / `DAT_0040a1a6`
  - the remaining `diag_dm1_buffer_*` physical start and end pointers (0x40c270 / 0x40c274), fill and slot words, and `diag_dm1_fault_source_table`
  - `crank_tbl_event_counter` (Crank_Resync_Count)
  - 0x3fcd92 `governor_cruiseOverride_holdoff_countdown`
  - the rest of block 8000 (0x409110-0x409138): `engine_sync_*_cal`, `cam_sync_*_cal` and `engine_speed_override_*_cal` are HPCR governor settings and carry a wrong `_cal` in that RAM region

## Notes for the apply
- **Types (not changed).**
  - Signed in the e2m and loaded with `lha` or cast to short: 0x40a1ac, 0x40a1ae, 0x40a1b6, 0x40a1be, 0x40a41a, 0x40a19a, 0x40911a, 0x40911c. The rows are `word`, so `i16` would fit.
  - 0x40b808 is compared as short, and its e2m record is signed.
  - 0x40a204 (`fuel_demand_integrator_b`) is a dword over the I term and the P term. After the rename the P term would render as `rpm_deceleration_limit_integral_term._2_2_`, and the `fuel_demand_integrator_b+2` sub-row goes stale. Split the row: word at 0x40a204, word at 0x40a206 (e2m +5C).
- **Old comments that are wrong** (candidates for `WRONG_OLD_COMMENTS`): 0x3feb82, 0x3feb84, 0x3feb8a, 0x3fdfbe ("2x30B array"; there is one 30-byte channel record), 0x40a67e, 0x40a684, 0x40a1a4, 0x40a1a8, 0x408720.
- **[44] finding.** e2m 801D +0 says `fuel_metering_feedback_input` is the pressure regulator valve current (mA, 1.2218 per count). The repo notes still call that signal unidentified. I kept the name and put this in the note.
- **Judgment calls.**
  - 0x40ad82: the intake air heater attribution comes from the e2m name and the DM7 test order (test 0 = this word, test 1 = `misfire_monitor_result`). The word has no store anywhere in ROM or flash2.
  - `pumping_torque_adjustment` follows the brief's "Adj = adjustment" and fits net = gross minus it.
- **`e2m_variables.csv` coincidence.** `alpha_altitude_derate_timer` and `ambient_relative_humidity` also appear in `output/e2m_variables.csv`, a reference list of mechanical e2m names at e2m virtual addresses that no build step reads. They pass the brief's check against global_variables.csv and the .cpp, but a stricter grep over `output/*.csv` would flag them.

Scratch scripts are in `/tmp/w13b6`.