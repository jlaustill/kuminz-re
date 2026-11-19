Wave 12 bin 5: 66 rows written to /home/linux/.claude/jobs/f6a06670/tmp/fueling_state/stage7/result_W12_bin5.jsonl (read-only research; no repo file touched, no build, no commit). The file passes my checks: it has 66 lines, its address set equals the bin, and every row is `new_global` with a `type`. All names are unique, none ends `_cal`, and none exists in the repo's CSVs, headers or .cpp. They also do not collide with bin3's finished result.

**Verdicts:** 61 confirmed, 5 uncertain, 0 rejected.
- **Types:** 56 word, 5 byte, 3 dword, 2 i16. The i16 rows are 0x5a9bc and 0x40675c (signed, `lha` only). 0x40add4 is signed but its only census access is `sth`, so it stays `word`.
- **Widths:** no census width disagrees with a record size. Five records are census-blind (array or address-taken access): 0x5983a, 0x408e02, 0x408e18, 0x408e26 and 0x6457a. Their width comes from the decompile (`uint *`, `word *`, `ushort`) and matches.
- **Offset drift:** none inside my 16 blocks.
  - The code proves the layouts: stride-8 fault table, zone gain sets in P/I/D/I-acc order, sum 10+2+1+1=14 for the J1939 receive groups, and 1052 bracketed by its clamp bounds.
  - The humidity block 1982 matches the dump to the digit: (71<<10)/1647 = 44.
  - The exhaust-pressure terms in 198C each match their e2m label.
  - The fuel-level block 8A22 ties to the 0.8 s task period.
  - The PCI slot 125 equals P0720's slot (ROM 0x5985a[320] = 125).

**Uncertain: tau polarity (0x5c35a, 0x5c35c, 0x5c35e, 0x5c360, 0x5c362).**
- The roles fit: these are the derated point-2 speed and fueling of the PGN 65251 engine configuration message, plus the point-5 intersection speed.
- The tau index is not proved.
  - Disassembly 0x20dac-0x20ea0 reads the Tau_0-labelled pair when `thermal_fuel_limit_factor` equals 0x4000.
  - That variable is e2m 1053 +2 Fuel_Interp_Factor (a startup/run alpha blend written by `hpcr_calculateFuelTrimOutput`).
  - With it forced to 0, the code computes the e2m "ESP Tau 0" fueling, so the labels read inverted.
  - The cal holds identical pairs (17600 / 736), so the dump cannot decide.
- 0x5c364 (the Tau_1 intersection) has no reader.
- I kept `tau_0` / `tau_1` in the names. If you apply them, the digits may need swapping.

**Overlap with bin2:** 0x5983a (`Fault_Data`, block 000F) is the same address as block 0023 `Fault_Countdown_Elapsed_Time_Mode_0`. Both rows must get one name; mine is `fault_countdown_elapsed_time_mode_0` (dword).
- In code the label is only the base of the fault aging table: 4 × {elapsed, rate} dwords at stride 8, indexed by `aging_flags & 3` with mode 0 excluded.
- The table is a struct-array candidate; all eight words are 0 in the ROM.

**Leads outside my scope:**
- **Collector:** the `diag_dm1_buffer_*` rows at 0x40c278 / 0x40c27c / 0x40c280 / 0x40c284 are e2m 0033-0036 Collector_Start / Center / End_Address / Status, so the data collector, not DM1.
  - My name `data_collector_table_address` follows the e2m, not those neighbours.
  - The whole 0x40c270-0x40c290 block reads 0 in the RAM dump, even pointers the init sets, so no dump value is quoted.
- **Engine configuration cluster:** `faultTimerHandler` (0x1b3a0, sent by `cm848_sendFaultTimerMessage`) builds the PGN 65251 engine configuration message. The `cm848_updateProtection*` functions and the `protection_*` variables in block 1104 (e.g. `protection_threshold_scale_cal` at 0x5c34e) are its point calculation. The existing `_cal` names there are wrong twice: they are legacy misnomers, and they sit in flash.
- **Cruise names:** `cruise_speed_offset_*` are fueling top-droop offsets in mm3, not speeds. My rows use `cruise_top_droop_offset_*`.
- **Other legacy names:** `boost_synthetic_ema_*` and `boost_pressure_synthetic_ema` are the exhaust-pressure estimate. `thermal_fuel_limit_factor` is the e2m Fuel_Interp_Factor.
- **Block 11F9:** +8 (OBD_Fuel_Type, 0x5a9c4) lands on a lookup-table length word (12), probably drift or a dropped record there. My +0 / +4 / +6 are code-proved.
- **Struct candidates:** the three 4-word cruise gain sets at 0x408e02 / 0x408e18 / 0x408e26, and the fault aging table.
- **Behaviour note, tachometer cutoff:** 0x645c2 floors a non-zero speed to 300 rpm rather than dropping it to zero as the e2m text says. I confirmed it because "cutoff" holds either way, and the comment says so.

**Name choices to be aware of:**
- **Spelled out, not abbreviated:** 0x40add4 is `environmental_protection_agency_indicated_friction_torque_percent_times_256` because EPA is not on the allowed abbreviation list.
- **Sibling convention:** the retarder stages follow the existing `engine_retarder_stage_1_weight` as `engine_retarder_stage_2` through `stage_6_weight`.
- **Fuel-level family:** the fuel-level rows use the existing `fuel_level_sensor_high_voltage_*` family rather than the e2m's "out of range" wording.