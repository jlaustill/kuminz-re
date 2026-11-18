# 044 — CM848D: names that clash with the DTC a function sets (P0500 monitor fixed)

## Problem Statement

A fault bit fixes what a monitor checks: fault n → ROM `0x5985a[n]` (slot) → `obd_dtc_code_table[slot]` (an SAE
P-code). A function whose name disagrees with the P-code it sets is misnamed. On 2026-11-17 a scan of every function
that sets a fault bit turned up one confirmed misname and several leads.

## Method (the DTC-code check)

`fault_setters.py` (in `firmware/CM848_S90140.06_analysis/docs/agent_notes_2026-11/session_2026-11-17_p0500/`) lists,
for each function in a `.cpp`, the fault bits it sets (`fault_detected_bits_<first>_to_<last> = ... | mask`) and their
P-codes. It reproduces every documented mapping (407 → P0483, 396 → P0622, 121 → P0480, 333 → P0251, 351 → P0748,
403 → P0243, 82 / 89 → P2509, 91 → P0606, 304 → P0193, 305 → P0192). `slot170` means the fault has no DTC slot
(an internal fault). It only sees setters written as `|= mask`; indexed or table-driven setters need their own look.

## Done (branch `cm848/vehicle-speed-sensor-p0500-monitor`)

- `diag_boostLoad_overtemp_monitor` (0x5269c0) sets only fault 29 = P0500. It is the vehicle speed sensor
  zero-under-load check: 10 events (30 passes each with boost above baro over 94.8 kPa and filtered load over 40 %)
  plus 10 accelerator off-idle entries while the sensor reads 0. Renamed
  `cm848_detectVehicleSpeedSensorZeroUnderLoad`, together with its group:
  - `cm848_clearHealedVehicleSpeedSensorFault` (0x526bc8, was `diag_boostLoad_overtemp_clear`);
  - `cm848_runVehicleSpeedSensorMonitors` (0x526c80, was `cm848_calibration_group30_execute`);
  - `cm848_initializeVehicleSpeedSensorZeroUnderLoadMonitor` (0x526cb8, was `cm848_state_variables_reset`);
  - the state: `vehicle_speed_zero_under_load_*` (pass count, the two EEPROM-backed `_cal` counts, the filtered
    load, the previous accelerator off-idle state) and the `ema_filter_state_t` at 0x3fd070 (was a flat dword
    `engine_load_ema_filter_pointer`);
  - the eight ROM limits at 0x5c964-0x5c974 (two of them belong to `cm848_detectVehicleSpeedSensorSignalLoss`).
- P0500 has a third source, not renamed because the function does much more: `cm848_processGovernorModeTransition`
  (0x2715c). On the J1939 automatic drivetrain, an ETC1 output shaft speed timeout (key on, engine cranking or running)
  zeroes `output_shaft_speed_current` and sets fault 29. `cm848_clearHealedVehicleSpeedSensorFault` heals fault 29
  whichever source set it. The plate comments of the two monitors say "path 1 / path 2" and don't mention this third
  source yet.
- `cm848_buildPgn65213FanDrive1Message` (0x2641c): the invented `dest_address` / `status_type` parameters are gone
  (`void (void)`; r3 / r4 are written before they are read).

## Wave 10 (2026-11-18, PR #51): the leads verified and renamed

Four read-only agents verified every lead from the code: they read the briefs `rename_waves/briefs/brief.md`,
`brief_wave9.md` and `brief_wave10.md`, and their results are in
`docs/agent_notes_2026-11/session_2026-11-17_p0500/session_folder/wave10/`. The P-codes come from ROM 0x5985a and
`obd_dtc_code_table`; the SAE titles are generic. Their rows renamed 28 functions and 115 globals and added 82 rows;
the hand edits are listed below the table. The proof is label-only apart from the typing changes listed in the session
folder.

| Was | Now | What it checks |
|---|---|---|
| `diag_eepromFault_pendingStatus_update` | `cm848_updateTransmissionTemperatureSensorPerformanceFault` | P0711 verdict of `cm848_checkTransmissionTemperatureSensorPerformance`. After a qualified cold soak, it fails above 260 °F, or when a start under 50 °F rises less than 16 °F after 12000 passes above 30 mph. |
| `sensorValidationTimeout` | `cm848_monitorFourWheelDriveSwitch` | P0837. A resistor-ladder switch on sensor channel 76 with a learned-present latch: 90 passes at code 0, or a code that changes every pass. Channel 76 low / high = P0838 / P0839. The four-wheel-drive label rests on the DTC mapping. |
| `cm848_processEngineConditionFlags` | `cm848_monitorTransmissionOutputSpeedSensor` | P0720. Above 15 mph, out of park / neutral and at the governor setpoint, 300 passes under 60 rpm output speed set it; 300 passes at or above clear it. |
| `protection_enable_state_machine` | `cm848_monitorBrakeSwitchPairAgreement` | P0573 / P0572: switch 11 (brake) against switch 2, the second brake signal. |
| `protection_j1939_control_logic` | `cm848_deriveSecondBrakeSwitchSignal` | Derives switch 2 in software when it has no line. No J1939 is involved. |
| `cm848_main_loop_protection_eval` | `cm848_monitorFuelLevelLowDistance` | P0461: distance driven with the stored fuel level below 14.9 % (about 120 miles). |
| `governorSpeedLimitTable` | `cm848_verifyCalibrationAndCodeCrc` | P0602. A background CRC16 of the EEPROM calibration block (EEPROM 0x118-0x171, stored at 0x482) and of ROM 0x8000-0x6fc61 plus flash2 (stored at 0x484). The results are also the OBD mode 9 calibration verification numbers. **An edit to EEPROM 0x118-0x171 must also update the word at 0x482, or P0602 sets.** |
| `hpcr_coldBurndownControl` | `cm848_runMisfireMonitor` | P0301-P0306 / P0300. An idle misfire test that overfuels one cylinder at a time in firing order, with up to 5 retries; 2 or more flagged cylinders set P0300. It is off here: `operating_mode_flags_cal` bit 0x8000 is clear. |
| `mpc555_processColdStartMainLoop` | (kept) | Also holds P0219 overspeed: it latches at 4200 rpm after 4 passes, clears below 4000 rpm, and keeps a 5-record EEPROM log. That log is empty on this truck. |
| `hpcr_calibration_group36_load` | `cm848_detectBarometricPressureSensorAboveMaximum` | P0106: barometric pressure above 108.4 kPa for 20 passes. |
| `cm848_calibration_group21_load` | `cm848_monitorBoostPressureSensorAndUnderboost` | P0236 / P0299 / P0069: before start, MAP high and MAP minus baro too large; then underboost at high load and boost reading high at light load. |
| `cm848_calibration_group22_load` | `cm848_checkEgrDeltaPressureSensorPerformance` | Faults 774-777, which have no DTC slot. The sensor tests are proved; that they are plausibility checks is inferred. |
| `cm848_calibration_group37_load` | `cm848_checkFuelTemperatureSensorAfterColdSoak` | Fault 402 (no slot). After a coolant / battery temperature cold soak it tests the fuel temperature against 150 °F. The old "coolant vs ambient" reading was wrong. |

Plus, by hand:
- **High speed governor gain sets:** `high_speed_governor_gain_set_t`, with five ROM instances (sets 17-21; the three
  named sets were flat rows before). `cm848_loadHighSpeedGovernorWorkingGainSet` (was
  `cm848_processSystemStatusLimits`) loads set 20 / 21. It is off here: `system_feature_config_flags` bit 0x100 is clear.
- **CRC words:** the two CRC result pairs are `word[2]` arrays (`rom_crc_stored_results_cal`, `rom_crc_computed_results`).
- **Misfire state:** the two misfire state words are dwords.
- **Fault word:** `fault_registered_bits_512_to_527` (was `j1939_message_state_flags_b`).

## Follow-ups (from the agents' notes; not done here)

- **Typing.**
  - The overspeed event log at 0x3fdfde is 5 records of 8 bytes, currently typed as one dword.
  - 0x408d4a / 0x408d52 are loaded with `lha`, so they should be `i16`.
  - Two orphan `sensor_val_state_t_*` pad rows (0x3fee49 / 0x3fee4b).
  - Suggested enums: the transmission temperature rationality state and the output speed sensor check states.
- **Struct fields.**
  - `engine_rpm_state_t.target_rpm` holds the filtered engine speed.
  - The high word of `governor_output_t.integrator` is the idle reference speed.
  - `protection_condition_flags_t.threshold_current` is a flags byte; bit 0x20 = P0720.
  - `eeprom_header_t.calibration_block1` is the stored fuel level.
- **Misnames found on the way.**
  - `cm848_j1939BuildEngineStatusByte` / `cm848_initJ1939EngineStatusBuffer` / `j1939_pgn65269_tx_data` are the
    PGN 65241 AUXIO1 message (aux I/O 1-3 = switches 19 / 11 / 2).
  - The `qadc_control_word_*` rows at 0x3fdbb2-0x3fdbca are more entries of `switch_input_hardware_line_cal`.
  - `hpcr_fuelFinal_periodic` is the barometric pressure selector.
  - `protection_sensor_mode_flag` means "boost is gauge pressure".
  - `cm848_calibration_group21_load_cont` is a separate monitor.
  - `engine_protection_timerState_shiftCheck` reads `misfire_monitor_result` and may be an end-of-line test step.
- **Gate words.**
  - `protection_feature_status_flags` is not a configuration word. `cm848_calibration_group27_load` rebuilds it every
    pass as a "monitor enabling conditions met" bitmap.
  - `CSP_CRANKING` (1) means key on before the engine starts; it is an enum rename lead.
- **Unresolved.**
  - `sensor_validation_timeout_cal` (0x3fd944) is uncertain.
  - The misfire response polarity needs a running-engine dump.
  - `fault_setters.py` misses setters that write through a temporary (fault 777).

Also suspect, not renamed: the three gate words of the P0500 monitors. `protection_feature_status_flags` (0x40b9d0)
bits 0 / 1, `boost_fuel_bypass_flags` (0x40b9d4) bits 0 / 1 and `fault_management_status_flags` (0x3fd5b4 = EEPROM
0x132, so it should be `_cal`) bits 0x100 / 0x200 enable / suspend paths 1 / 2. Each word is shared by 30+
unrelated monitors, so they need their own review.

## Investigation Log

- 2026-11-17: the first find was on a checkout 36 commits behind main (the PGN 65213 Fan Drive builder, already
  renamed by PR #50); every claim above was rechecked on 809fd25. Notes, scripts, the sweep output and the build logs
  are in the session folder named above.
