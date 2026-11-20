W14 functions2 is finished. All 28 items are in /home/linux/.claude/jobs/f6a06670/tmp/fueling_state/stage9/result_W14_functions2.jsonl, in bin order. No repo file was touched and `git status` is clean. Scratch is in /tmp/w14_functions2/ (the generator `make_results.py`, `validate.py`, `check_refs.py`, `cross_check.py`).

Validation: every address and old name equals the bin. Every new name passes the gate regex and BANNED set, is unique, and is absent from every CSV, the .cpp, the .hpp files, CM550's CSVs and the other W14 result files (all seven were present at the final run). Every code_quote sits inside one physical line of its function.

**Counts:** 28 confirmed renames, 0 keep, 0 uncertain. No drift found.

**Families renamed**
- **Percent peak torque / friction, e2m 10E2:**
  - 0x18070 `cm848_calculateJ1939PercentPeakTorqueAtSpeed`
  - 0x1811c `cm848_calculateJ1939FrictionLoadFuelingAtBreakpoints`
  - 0x1820c `cm848_calculateJ1939PercentPeakTorquePoints`
  - 0x182e8 `cm848_calculateJ1939PercentPeakTorque`
- **PGN 65251 torque curve, e2m 1102:**
  - 0x1b3a0 `cm848_buildPgn65251EngineConfiguration1Payload`. It fills a buffer and sends nothing; the sender is 0x1b730.
  - 0x20500 `cm848_calculateJ1939ReferenceEngineFueling`
  - 0x209e8 `cm848_calculateActualEnginePercentTorque`
  - 0x20a58 `cm848_calculateEnginePercentLoadAtCurrentSpeed`
  - 0x20c64 `cm848_setJ1939TorqueCurvePoints2And5AtDroopLineFueling`
  - 0x20d10 `cm848_updateJ1939EngineConfigurationTorqueCurve`
  - 0x212dc `cm848_initializeJ1939ReferenceEngineFuelingAndTorque`
  - 0x21ac0 `cm848_lookupMaximumTorqueAtEngineSpeed`
  - 0x21cd4 `cm848_calculateJ1939TorqueCurveFuelingsAndReferenceFuelings`
- **J1939 messages:**
  - 0x2588c `cm848_buildPgn61444ElectronicEngineController1Message`
  - 0x255c0 `cm848_sendPgn65232NonContinuousMonitorTestResultMessage`. I spelled out the PGN title because Dm8 is not on the allowed list.
  - 0x26f80 `cm848_runTsc1LostManagement`
- **J1939 control sessions, e2m 10FD-10FF and 1100:**
  - 0x50be6c `cm848_storeJ1939ControlSessionInHistoryTable`
  - 0x50beec `cm848_startJ1939ControlSession`
  - 0x50bff4 `cm848_trackJ1939ControlSessions`. It is the J1939 monitor, enabled by bit 0x800 of `governor_feature_config_word`.
- **Data collector:**
  - 0x505c20 `cm848_fillDataCollectorRingBuffer`
  - 0x505d94 `cm848_resetDataCollector`. The `hpcr_` prefix does not fit.
  - 0x505df0 `cm848_sendDataCollectorBuffer`
  - 0x505f98 `cm848_runDataCollector`
- **Number to text:** 0x27bc4 `cm848_formatNumberAsDecimalText`.
- **Engine protection shutdown:**
  - 0x508130 `cm848_examineEngineProtectionBeforeCranking`
  - 0x508898 `cm848_updateEngineProtectionShutdown`
  - 0x508e78 `cm848_detectEngineProtectionShutdownOverrideRequest`
  - 0x508ee0 `cm848_latchEngineProtectionShutdownOverride`

**Where I departed from the proposals**
- **0x21ac0:** the wave-13 "fuel table" reading is wrong.
  - The ROM grid at 0x5c58e peaks at 600 and is the e2m MT_Max_Torque_Map in lb-ft.
  - The RAM dump reproduces 1368 in 0x20500: (1030-397) x 10000 / ((290 x 13558) / 850).
- **0x21cd4:** the name covers both outputs, the torque curve fuelings and the reference fuelings.
- **0x1b3a0:** `Payload`, not `Message`.
- **0x20c64:** the literal form. The "breakpoint" proposal omits point 5.
- **0x18070 and 0x1811c:** J1939 added, to match `j1939_friction_load_fueling_at_breakpoint_4`.
- **0x26f80, 0x27bc4 and 0x255c0:** new names, since no usable proposal existed.

**Shared-name holds:** 0x1b3a0 (CM550 0x3320e) and 0x2588c (CM550 0x32c76). The plates cite siblings by their current names on purpose, so the refresh step rewrites them.

**Observations (nothing changed for them)**
- **0x21cd4 reference fuelings:** the code has no x 10000 here, unlike 0x20500. The divisor is 3939 to 9570 for 247 to 600 lb-ft, so the five reference fuelings read 0 in the dump (`algorithm_enable_flags_41_cal` = 0x7ca6, bit 11 set). I did not check what `cm848_clampedDivisionWithBounds` does with a zero denominator in 0x20d10.
- **0x1820c and 0x182e8:**
  - No caller was found: no `bl`, and no 32-bit pointer in ROM or flash2.
  - The 10E2 percent words read 0 in the dump.
  - The idle friction word reads 397, the first table value, so its lookup input was at or below 3600.
  - The other four friction words match the ROM table.
- **ROM 0x5c3ac (e2m 10E7 +2A TSC_Lost_Reset_Speed):** nothing reads it. 0x26f80 restarts from the current rpm instead.
- **This calibration:**
  - `governor_feature_config_word` = 15888 (0x3e10). J1939 monitor (0x800) is on; engine protection shutdown (0x1) and restart (0x20) are off.
  - `governor_fault_status_flags` = 39954 (0x9c12), so Collector_Enable (0x100) is off and the data collector is off.

**Out-of-bin leads**
- **PGN 65251 torque curve helpers:**
  - 0x20b84 `cm848_updateProtectionParameters` sets point 1: the idle reference speed minus a droop term, and the derated idle fueling.
  - 0x20bfc `cm848_updateProtectionInputs` picks point 3.
  - 0x21c3c `cm848_updateProtectionThresholdsIfLow` writes the point speeds from the 12BD broadcast overrides.
  - 0x21bf8 `cm848_getHighestPriorityBit` returns the highest set bit of `j1939_pgn65251_speed_points_request_flags`.
  - 0x507a20 `governor_calculateIntegratorRpmOutput` requests the fault derate curve speeds for those points.
  - 0x507c1c `fault_initBitwiseTimerMask` sets the request priority bit.
- **PGN 65251 transmit:** 0x1b730 `cm848_sendFaultTimerMessage` sends it. 0x1b778 `cm848_processFaultMessageTiming` resends when the payload changes. 0x1b900 `initFaultTimerMessage` sets up the descriptor (can_id 0xfee300, 28 bytes).
- **Torque map in lb-ft:**
  - 0x29c98 `cm848_calculateFuelDemandFilter` does the 0x21ac0 lookup at the current speed.
  - It stores the result in `fuel_demand_filter_dimension` (0x40aee6).
  - The ROM rows `j1939_fuel_table_xaxis_cal` / `_ystart_cal` / `_yend_cal` (0x5c556 / 0x5c582 / 0x5c58e) are the map's axes and grid. They carry a wrong `_cal` and a fuel domain.
  - No other W14 result covers these four.
- **Zero torque fueling:** `fuel_demand_norm_zero_cal` (0x5c398) is e2m 10E7 +16 FSS_Zero_Torque_Fueling, a ROM word (so `_cal` is wrong) that reads 0.
- **Torque normalization bit:** `algorithm_enable_flags_41_t.reserved_bit_11` now has two readers (0x20500 and 0x21cd4). Both scale the J1939 reference fueling with the torque map, so the bit can be promoted from a guess to the torque normalization enable.
- **Friction lookup init:** 0x1ea94 `cm848_initFaultSeverityTables` resets the lookup cache words for the maximum fuel grid, the friction table and the coolant table, then runs the five friction lookups.
- **Engine protection:**
  - 0x507ebc `protection_threshold_check` and 0x508834 `protection_event_timestamp` carry a bare "protection". They are the engine protection channel threshold check and its time-over-threshold counter.
  - `DAT_0005c2f4` is e2m 10B9 +0 Shutdown_Max_Limit (65535 in ROM) and has no name.
- **TSC1 rows:**
  - `etc1_fuel_demand_high_limit` (0x3feb90) is e2m 11C1 +4 TSC_Lost_Max_Throttle_Disable. It sits in the EEPROM mirror, so it needs `_cal`.
  - `fuel_demand_timing_enable_flag` (0x40b1ee) is set with the TSC1 ignored-sender entries in 0x511b64, initial value 1, and read by 0x26f80 and 0x3ecdc. It looks like the TSC1 timing fault state; its semantics are unproved.
- **Cross-bin note:** globals3 and globals4 named the 10E2 and 1102 rows consistently with my functions (`j1939_percent_peak_torque_*_times_256`, `j1939_friction_load_fueling_at_*`, `j1939_torque_curve_*`). They name 0x40a632 `j1939_percent_peak_torque_at_current_speed_times_256`, so 0x182e8 could take an `...AtCurrentSpeed` suffix for symmetry. I left my name unchanged.