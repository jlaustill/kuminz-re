W12 bin1 is done: 67 lines in /home/linux/.claude/jobs/f6a06670/tmp/fueling_state/stage7/result_W12_bin1.jsonl, one per bin record in bin order, all `kind` new_global with `type`. No repository file was edited. I checked the file for uniqueness against the CSVs and .cpp, banned words, `_cal`, type against size, and cited identifiers (see the last section).

**Verdicts:** 66 confirmed, 1 uncertain, 0 rejected.
- Uncertain is 0x40a672, named `exhaust_pressure_sensor_value_copy`. The e2m calls Exhaust_Pressure the calculated pressure, but the code stores the raw `sensor_channel109_value` (0 in the dump while `boost_pressure_current_raw` reads 1784). The two 191B rows keep `*_virtual_sensor_copy`.

**Drift (1):** 0x5c7ac is claimed by both 8A2B +24 IAH_Pulsewidth_Time_Duration and 8A37 +0 IAH_Default_IMT. The only code use is a signed temperature fallback, so I confirmed IAH_Default_IMT. 8A2B therefore ends at +22 in 11.46.06. Every other block aligned: siblings and neighbours resolve to the cells their own code uses.

**Width:** no disagreements.
- The census was empty at 0x5c1d0 and 0x5c7ac. I resolved both by disassembly: 0x5c1d0 is `lhz r9,0(r3)` at 0x5031a0, and 0x5c7ac is `lha` at 0x5183a4 (typed `i16`).
- `i16` is on six rows: 0x3fddb6, 0x409fd4, 0x409fd6, 0x409fd8, 0x409fda and 0x5c7ac.
- 0x40babe is signed but only stored (`sth`), so it is `word`.
- 0x409fce is `dword`; 0x408a94 and 0x408a95 are `byte`.
- Only 0x3fddb6 ends `_cal` (EEPROM 0x934).

**e2m wording that contradicts the code (the names follow the code):**
- 8C5A +2: the text says "Max speed", but the code needs vehicle speed above it.
- 8C5F +10: the description is another record's; the name, scale and pedal compare say minimum pedal position.
- 1772 +0: "Calculated" versus the raw sensor copy, which is the uncertain row.

**Naming choices:**
- `tsc1` is on four rows (0x5c3aa, 0x5c3ae, 0x5c3b0, 0x5c3b2). Swap it in one pass if you prefer it spelled out.
- Message acronyms are written as decimal PGNs (`j1939_pgn61442_*`, `j1939_pgn65247_*`, `j1939_pgn61443_*`).
- 10B6 mirrors the throttle-mode twins at 0x3ff6d0-d4: `..._reference_filter_coefficient`, `governor_fuel_demand_tracking_{limit,floor}_j1939`.

**Leads (legacy misnames, no extra JSON lines):**

Table-resolved:
- The `diag_dm1_*` words around 0x3fddb6 are the e2m data collector (0030-003B), not J1939 DM1.
- `sensor_channel109_value`, `_default_value` and `_fault_status` are the exhaust pressure sensor (1966 +A, 1966 +30, 1963 +18).
- `engine_to_vehicle_speed_ratio_*` is the e2m Tcase_NV transfer case low-range detection. In 8C60, `_high_flag` is Tcase_Low_Range_Flag and `_invalid_flag` is Tcase_Launch_Flag.
- `throttle_trim_predictor_output_min` is 1A2E +4 C_INM_EGRT_Min (EGR orifice temperature).
- `j1939_address_cached` (0x40a030) is 1042 +4 ASIC_Feedback_Delay_Time (100 us).
- `boost_pressure_synthetic_ema` and `boost_correction_mode_flags` are 1772 +A and +8, the exhaust pressure estimate and its state.
- ROM cells with a wrong `_cal`: `etc1_torque_mode_timeout_cal` (10E7 +A), `fuel_demand_norm_zero_cal` (10E7 +16), `cruise_speed_default_cal` (13B4 +4).
- 155A is past the end of the dumped table, so its link to the 0x5c1d6 gain sets is by offset only.

Inferred from use:
- `cruise_speed_factor_a`, `cruise_speed_factor_b` and `cruise_speed_offset*` are the high speed governor lead/lag compensator state.
- The `etc1_*` timer fields reload from the 10E7 cells:

  | Field | Reloaded from |
  |---|---|
  | `etc1_torque_mode_timer` | overspeed enable timeout |
  | `etc1_torque_active_timer` | overspeed time limit |
  | `etc1_torque_limit_timer` | progressive shift disable timeout |
  | `etc1_speed_override_timer` | driveline disengaged timeout |
  | `etc1_mode_timeout` | out of gear timeout |
  | `etc1_override_timeout` | torque converter lockup timeout |
  | `etc1_speed_cmd_timeout` | output shaft speed timeout |
  | `etc1_message_timeout` | message timeout |

- `j1939_fault_load_protection_*`, `j1939_fault_state*` and `j1939_load_protection_fault_reported_flag` are the P1762 governor pressure offset monitor state.
- `cm848_j1939FormatDm1Message` is the TSC1 lost management (e2m Jcomm_TSC_Lost_Fault).
- `faultTimerHandler` builds the 28-byte `j1939_pgn65251_tx_message` payload.
- `phase_group_a_validateEngineSync` is the exhaust pressure source selection.
- `sensor_channel108_filter` is the EGR orifice temperature lead predictor.

**Checks:** each of my names is unique and absent as a token from the CSVs, the .cpp and the three generated headers. The names also pass the gate's banned-word and hex-looking-part checks, and the `_cal` rule. An emulation of `comment_name_sweep.py` flags nothing in the new comments.

**Scratch (in /tmp, nothing in the repo):**
- /tmp/w12bin1_make.py is the generator; it holds all text and rewrites the JSONL.
- /tmp/w12bin1_check.py, /tmp/w12bin1_idcheck.py and /tmp/w12bin1_sweepcheck.py are the checks.
- /tmp/w12bin1_extract.py prints the full e2m descriptions.
- /tmp/w12bin1_xref.json holds the `xref_addr.py` output for all 67 addresses.