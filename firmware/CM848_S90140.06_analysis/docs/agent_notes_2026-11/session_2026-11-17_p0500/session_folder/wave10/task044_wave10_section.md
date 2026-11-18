## Wave 10 (2026-11-18, PR #51): the leads verified and renamed

Four read-only agents (briefs `rename_waves/briefs/brief.md` + `brief_wave9.md` + `brief_wave10.md`; results in
`docs/agent_notes_2026-11/session_2026-11-17_p0500/session_folder/wave10/`) verified every lead from the code. The
P-codes come from ROM 0x5985a and `obd_dtc_code_table`; the SAE titles are generic. 28 functions and 116 globals were
renamed, 82 rows added, and the proof is label-only apart from the typing changes listed in the session folder.

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
