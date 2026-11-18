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

## Wave 11 (2026-11-18, PR #51): structs, arrays and bitfields

Four read-only agents (brief `rename_waves/briefs/brief_wave11.md`) worked through a census of named-struct casts,
piece accesses (`._N_M_`) and `(&name)[i]` indexing, plus the wave 10 leftovers. Each shape they proposed was
checked against the asm and its users before it was applied. The results are in
`docs/agent_notes_2026-11/session_2026-11-17_p0500/session_folder/wave11/`.

| Commit | What |
|---|---|
| 3d8c707 | The 30 J1939 transmit descriptors are `j1939_tx_msg_t` instances. A ROM-to-RAM thunk is no longer made inside a named struct or array (the build log says "covering"). |
| 72eb81e | The agents' label-only rows: 16 functions, 36 globals, 20 new rows and the `COLD_START_PHASE` members. |
| 2eb48b0 | Batch A, ROM and the 0x40xxxx working RAM: record arrays, the monitor condition bitfields, word splits and 13 type fixes. |
| (batch B) | The EEPROM mirror and the copy window: the fault records, the DTC lists, the sensor channel bitmaps, `end_of_line_test_settings_cal`, the algorithm enable bitfields and a pointer array type. |

Pieces in the .cpp went from 917 to about 540. A pointer type such as `fault_entry_t *[N]` is now accepted in
`global_variables.csv`; the change is in `ScriptUtils.ARRAY_TYPE` and has a JUnit test.

**Deferred, with the reason:**
- `sensor_channel_filtered_output` / `sensor_channel_adc_forced_reading` (word[128]): would replace named
  per-sensor slots with array elements.
- `qadc_channel_index_table` as word[128]: the extra words hold the boot kernel's `diagnostic_service_dispatch_table`
  (0x3fdb30) and the named slot `transmission_temperature_qadc_channel_cal` (word 103).
- `fault_registered_bits_*` / `fault_previous_pass_bits_*` as arrays: the flat names by fault-bit range are the
  established convention.
- `fault_status_records` (0x3feb92): slots 77-169 share their RAM with the boot kernel (`data_transfer_state_t`,
  `diag_session_state_t`, ...).
- `tpu_a/b_channel_parameters`: overlaps the register CSV.
- `switch_input_hardware_line_cal` with the `qadc_control_word_*` rows: they share RAM with boot kernel rows.
- `eeprom_header_t`: the boot header. Its `calibration_block1` is the stored fuel level.
- `logical_output_request_bits` as byte[10]: conflicts with the bits 16-23 bitfield.
- `COLD_START_PHASE` / `cold_start_phase`: its values are an engine run state. That needs its own review.

**Reverted:** the bitfields on `protection_status_flags_t.status_flags` and
`protection_condition_flags_t.fault_state_flags`. The code updates those bytes with `|` / `&` masks, and Ghidra 12.1
prints such updates as pieces. See the note in `firmware/CLAUDE.md`.

## Follow-ups (still open)

- `engine_protection_timerStateMachine_init` / `engine_coldStart_protection_stateMachine` read and write
  `end_of_line_test_settings_cal.test_flags_2`. They are probably end-of-line test steps, not protection.
- Suggested enums: the transmission temperature rationality state and the output speed sensor check states.
- The misfire response polarity needs a running-engine dump.
- `fault_setters.py` misses setters that write through a temporary (fault 777).
- `function_definitions.csv` carries 3 stale function names: 0x21918, 0x220e4 and 0x227a0. The build warns about
  each, but the prototypes still apply. Check each prototype against its current function before renaming the rows.
- Closed by wave 11:
  - the overspeed log (`engine_overspeed_event_t[5]`);
  - the `i16` limits at 0x408d4a / 0x408d52;
  - the orphan pad rows;
  - `engine_rpm_state_t.filtered_rpm` and `governor_output_t.idle_reference_speed`;
  - the P0720 bit (0x20 of `fault_state_flags`);
  - the misnames listed in wave 10 (commit 72eb81e);
  - `sensor_validation_timeout_cal`, which is `end_of_line_test_settings_cal.maximum_miles` plus a spare byte;
  - the three P0500 gate words: `monitor_enabling_conditions_met` / `monitor_battery_voltage_error_latch` (both
    `monitor_condition_bits_t`) and `algorithm_enable_flags_12_cal`, where bits 8 / 9 are
    `vehicle_speed_sensor_signal_loss_enable` / `vehicle_speed_sensor_zero_under_load_enable`.

## Investigation Log

- 2026-11-17: the first find was on a checkout 36 commits behind main (the PGN 65213 Fan Drive builder, already
  renamed by PR #50); every claim above was rechecked on 809fd25. Notes, scripts, the sweep output and the build logs
  are in the session folder named above.
- 2026-11-18: wave 11, in four commits on PR #51. The agents' drop lists predated commits 1-2, so the shape converter
  (`apply_shapes.py`) recomputed the rows inside each shape from the current CSVs. Each batch was checked as follows:
  - the census of the targeted patterns reached 0;
  - the 7-byte record stride of `fault_state_t` was confirmed, since every index is multiplied by 7;
  - no boot-ROM function changed beyond field renames;
  - the underscore warnings stayed at 43 and the importer stats did not change;
  - `piece_census.py` found the pieces added by the two RMW bitfields, which were reverted.
