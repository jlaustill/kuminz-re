Wave 12 bin4 is done. The result file is /home/linux/.claude/jobs/f6a06670/tmp/fueling_state/stage7/result_W12_bin4.jsonl. It has 66 lines in bin order, all kind `new_global`. I validated it by script: every bin address is present once, no name is duplicated, and no name exists in global_variables.csv, the .cpp, or the other agents' result files. `_cal` appears if and only if the address is in the EEPROM mirror, and every type matches its record size.

**Counts:** 65 confirmed, 0 uncertain, 1 rejected (0x004086ca `AC_Driver_ON_Max_Time`, with `new` empty like bin2's rejected rows).

**Width:** no width rejects. The census was blind for three groups, so the widths come from the instructions cited in each evidence line.
- 0x5c4a6: `lha 0/2/4/6(r3)` at 0x28a80-0x28aa4. The address is taken as a pointer.
- 0x40a74e and 0x40a750: `sth r4,26(r5)` and `sth r4,28(r5)` at 0x508e34 and 0x508e38. These are fields +0x1a and +0x1c of a 62-byte per-input record at 0x40a734.
- The 12 rows of block 1930: `stb`/`lbz` and `sth`/`lhz` through the pointer arguments of `cm848_checkSensorStuckOverDistance`.
- 0x3fddae and 0x3fddb2 are `lwz`/`stw` (4 bytes).
- Types: `i16` only for 0x5c334, 0x4086a4 and 0x4086a6. The signed rows 0x40b6c6, 0x40b6ce, 0x40b6d0, 0x40b996 and 0x5c4a6 stay `word`, because their census is store-only or empty. 0x5c2b2 is unsigned but read with `lha`, so it is also `word`.

**Drift:**
- **Block 8A14:** it fits the code through +2A (0x4086c4) and not from +2C.
  - 0x4086ca is rejected. Its only reader loads it into the TSC1 activity counter, and its dump is 1 (0.1 s), which cannot be a maximum A/C run time.
  - The existing rows 0x4086c6 (`protection_iat_scale_factor_cal`, a percent factor of barometric pressure) and 0x4086c8 (`j1939_tsc1_active_duration_reload`) must not get e2m 8A14 comments.
- **Block 1930:** it fits through +10 and not from +12. The 12 in-bin rows (+00 to +0E) are proven by the callee, which uses each address in the matching argument slot.
  - From +12, the e2m's AATR_Numerator is a word, but the code puts the dword `water_in_fuel_distance` at 0x3feeb8, and BTR_Numerator/Denominator sit on unrelated names.
  - 0x3feec0 holds 0xa1a1, a marker rather than a counter.
- **No drift in the other blocks:**
  - Block 10DF's dump matches the truck's rating: 555 ft-lb, 1600 rpm, 2900 rpm rated.
  - Block 1152 matches its 62-byte layout.
  - Blocks 1034, 10EB, 118A, 12BD, 12FE, 164A, 1918, 1965, 1A9B, 806C and 81C9 also fit the code.

**Naming departures your consistency check will flag:**
- Block 8A14 uses `air_conditioning_*`, not the sibling `protection_event26_*`. That function is the A/C clutch request logic (logical output 38).
- Block 164A uses `end_of_line_test_*`, not the sibling `radiator_fan_speed_*`. The two intake air heater rows (IAH, 0x642ea and 0x642ec) are prefixed `end_of_line_test_` too, because their only readers are the end-of-line sequence.
- The 1930 rows end `_cal` as the brief requires. The existing rows at 0x3feeb6 and 0x3feeb8 sit in the same mirror without it.
- Rows 0x405d4a, 0x405d4c and 0x405d50 reuse the stem `injection_quantity_temperature_headroom_cap_`.
- Block 1152 follows the sibling prefix `fuel_temperature_derate_`.

**Leads:**
- `governor_speed_setpoint_raw`, `governor_d_gain_from_table`, `governor_p_gain_from_table` and `governor_j1939_gain_extra_working` actually hold the P, I, D and J gains of block 10EB. I checked the consumer code in `cm848_runLowSpeedGovernor`. The four words at 0x5c4a6 are a struct candidate.
- `faultTimerHandler` builds the 28-byte J1939 PGN 65251 payload, which is what the five speed points of block 12BD feed. The `throttle_position_*` words are e2m block 10E2 Jcomm percent peak torque.
- The note on `injection_quantity_temperature_headroom_cap` ("neither word has an e2m counterpart") is now outdated. 0x405d4e `C_TFC_Texhaust_Lim` is unnamed because its dump is out of range (6000 = 3000 F against a 0..1500 e2m range), and the cap is a constant 200 mm3 here (both limits are 2944).
- 0x642ee `EOL_EVR_Test_Time` (dump 150 = 15.0 s, over its e2m maximum of 10 s) is the alternator test end time, next to my 0x642f0 and 0x642f2 rows.
- In the compiled code, any battery voltage fall passes the 0x642f2 threshold, and no fall fails. The row comment says so.