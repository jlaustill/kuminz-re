W12 bin3 is finished: 66 result lines, in bin order, written to /home/linux/.claude/jobs/f6a06670/tmp/fueling_state/stage7/result_W12_bin3.jsonl. All 66 records are `new_global`. 64 names are unique and none collides with global_variables.csv or the .cpp. No name is a word-order permutation of an existing name.

**Verdicts: 64 confirmed, 0 uncertain, 2 rejected.**

**Rejected (neither is a bad address or a width problem):**
- **0x5a4aa, e2m 1253 +2 Fault_Data_J1939_111.**
  - The record is right at that address: slot 0 is fault 111, the value 0x00600275 carries SPN 629, and the DM1 builder reads it with `lwzx` (4 bytes).
  - What fails is the rest of block 1253. The e2m 11.45 slot order does not match this ROM (ROM: 111, 122, 123, 124, 131, 131, 132 ...; e2m: 111, 912, 184, 185, 115 ...). Only 1 of 90 e2m SPNs matches at the e2m offsets.
  - Also, 0x5a4aa is the base of a stride-4 table of 170 entries (header word 0x2a8 at 0x5a4a8), indexed by fault slot in three J1939 functions.
  - A scalar row would sit on that array base. I suggest one `dword[170]` row `j1939_dtc_definition_table` instead, and the scalar left unapplied.
- **0x40ba4c, e2m 1902 +2E IMTR_Ratio.**
  - The code uses the word as the thermostat monitor's current fuel total (`cm848_runThermostatMonitor`).
  - Its e2m neighbours AATR_Ratio and BTR_Ratio at 0x40ba48 / 0x40ba4a are already named thermostat fuel words.
  - So the +2A..+2E layout drifted from 11.45. A code-based candidate name is in the evidence: `thermostat_monitor_current_fuel_total`.

**Drift and widths:**
- **Drift:** block 1253 slot order and block 1902 +2A..+2E, as above.
- **Smaller e2m label problems, none affecting identity:**
  - Top_Gear_Ratio says "above which"; the code tests the ratio below it.
  - The 0x406768 boost coefficient is labelled per inHg, but the `/16384` divisor works in psi. The injection timing and engine speed divisors do reproduce the e2m scales.
  - The e2m descriptions of C_BT_Min_Vehicle_Speed and C_BT_VSS_Min_Timer are copy-pasted.
- **Widths:** no disagreements. Census-blind records were resolved by disassembly:
  - 0x597b2 (`lhz` through the record pointer);
  - 0x597bc, 0x597be and 0x597c0 (`lha` through the channel pointers; the 0x597c0 read is at 0x507fd8);
  - 0x40ba1e, 0x40ba22 and 0x40ba26 (4-byte `stw` through a pointer);
  - 0x5a4aa (4-byte `lwzx`, rejected).
- **Types:** by record size, except 0x597c0 `Fuel_Temperature_RPM_Lower_Limit`, typed `i16`. It is the only signed record, and its only reader is `lha`.
- **Block 1977/197A/197B check:** run with the tool; 1977 +4 = 0x3ff078 and +8 = 0x3ff07c. 197A / 197B resolve to 0x3ff0c4 / 0x3ff0e6, the pressure-drop lookup's axis and values used by the 197E code.

**Caveats for you:**
- **`_cal` on 0x3feb86 / 0x3feb88 (block 1100).** I applied `_cal` by the brief's region rule. These are logged J1939 control source slots, not tunables. The parameter ID table lists block 1100 as a plain RAM address, so the "EEPROM 0x1704 / 0x1706" offsets in the comments are my arithmetic, and the comments say so.
- **Prefix choices.**
  - Block 10CE uses the code's `pedal_fault_mode_` family, not the e2m's "limp home".
  - Block 8041 uses `injector_driver_`.
  - Block 112E uses `fuel_temperature_derate_` and spells the three temperatures as `_temperature`.
  - Block 17A2 uses `exhaust_temperature_estimate_`, not the neighbours' misleading `boost_target_*`.
  - I renamed 0x5c49e, 0x5c4a0, 0x5c4a2 and 0x5c4a4 so they are not a word permutation of the existing `engine_speed_limit_pedal_fault_mode`.

**Sibling rows outside my bin that look wrong (leads for you):**
- 0x40a899 `injection_timing_demand_output` is e2m 105A +2 Tau_0_Throttle_100_Fueling, the low-horsepower-curve full-throttle fueling. `cm848_validateFuelDemandRelativeToTiming` is really the engine load relative to that curve.
- 0x3fd912 / 0x3fd916 `cruise_ramp_zone_b/d_fuel_demand_threshold` are the cruise and road speed governor top droop widths in 1/256 mph. They are subtracted from `cruise_fuel_demand_ramp_ceiling` = 21760 = 85 mph.
- 0x40676c `boost_target_load_gain`, 0x40a67e `boost_target_fuel_normalized_ratio` and 0x40a682 `boost_target_load_rpm_output` belong to the exhaust temperature estimate, not a boost target.
- 0x3feb82 / 0x3feb84 / 0x3feb8a `*_calib_*` are J1939 engine and retarder control status and the history index.
- The `protection_coldStart_channelA/B_*` and `protection_load_*_threshold` rows in block 8C59 are the 48RE governor pressure zero and mid range monitors and their transmission temperature window.
- 0x40b9c6 `cam_sync_validation_state` is the fuel pressure key-on rationality state (`hpcr_checkRailPressureSensorBeforeStart`). The `cam_sync_validation_*` siblings in block 1B2C are its rationality parameters.
- 0x597b2..0x597d5 is a single 36-byte fault derate channel record, a candidate for a struct.
- 0x5c48e (the e2m limp home engine speed filter coefficient) already has an unnamed row; `pedal_fault_mode_target_speed_filter_coefficient` would fit.

**Files:** I modified only the result file. I also created two scratch scripts outside the repo, and they are still there:
- `/tmp/w12_bin3_build.py` is the generator that writes the result file.
- `/tmp/w12_bin3_check.py` is the validator.

Archive or delete them as you prefer.