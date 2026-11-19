W12 bin2 is done: 67 lines written to /home/linux/.claude/jobs/f6a06670/tmp/fueling_state/stage7/result_W12_bin2.jsonl. Counts: 63 confirmed, 1 uncertain, 3 rejected.

I ran my own self-check, and it passed. That covers the line count, the address order against the bin, and the gate rules from `apply_renames.py` (banned words, hex-looking parts, `_cal` only inside the mirror). It also covers uniqueness against `global_variables.csv`, `function_renames.csv`, `arrays.csv` and the .cpp, and every comment staying within the 400-character clip. No repo file was touched.

**Drift (the 3 rejected rows)**
- 0x5a48e, 0x5a490 and 0x5a492 are 10E3 +22 / +24 / +26 in the labelled e2m. In the truck they are block 1228 +02 / +04 / +06.
- The code at those addresses is the DM4 freeze-frame vehicle-speed switch (`== 1`) and the DM5 OBD-compliance and continuous-monitors bytes. Block 1228 starts at 0x5a48c, so block 10E3 ends before +20 in the truck.
- These rows have an empty `new`, because bin 6 owns the three addresses.
- No other drift turned up. Anchors from existing named rows hold in 1189, 1048, 106D, 12BA, 1791, 179C, 1977, 1A53, 117F, 1143 and 175C.

**Shape (the 1 uncertain row, plus a collision)**
- 0x5a486 `j1939_command_security_flags` is typed `dword`, but the only access is bytewise (`lbzx` over 4 bytes). The role fits, so I marked it uncertain for the shape only. `byte[4]` against `dword` is your call.
- 0x5983a and 0x5983e are entry 0 of a 4-mode × 2-dword table. `cm848_faultTimeoutHandler` indexes it by `(aging_flags & 3) * 8`, and the mode-0 pair is never read.
- Bin 5 will also propose a row for 0x5983a (000F `Fault_Data`), so two `new_global` rows will hit that address.

**Width and sign**
- No census width contradicts a record.
- Several records are typed `word` despite their sign, because the rule needs every access to be `lha` for `i16`.
  - 0x408e6c is signed but loaded with `lhz`.
  - 0x408e72, 0x408e82 and 0x408e84 are unsigned but loaded with `lha`.
  - 0x40afb6, 0x40afb8, 0x40afba and 0x40afbc are signed but only ever stored. They are never read in the binary, and their torque grid is all zero, so the dump proves nothing there.
- Where the census said "none", I took the width from my own assembly reads. That covers the filter coefficients through the two second-order filter helpers, and 0x408e5c through `lha 0(r31)` at 0x52547c. It also covers 0x3fdfc0 (`sth 2(r27)`, r27 = 0x3fdfbe), 0x406752 and 0x5983a / 0x5983e.
- `i16` is used only on 0x408e54, 0x408e56, 0x408e62, 0x408e76, 0x408e80, 0x3ff078, 0x3ff07c and 0x5b336.
- `_cal` is on exactly 0x3fdfc0, 0x3fdd7e, 0x3fdd82 and 0x3fdd84.

**Neighbours noticed:** the named 10FC rows (`j1939_pgn65249_cal_*`, `j1939_protocol_mode_*`, `j1939_dtc_spn_cal_*`) are the PGN 65249 retarder-configuration points in e2m order. 0x5a494 `j1939_feature_config_word` is 1228 +08, the DM5 non-continuous monitors word.