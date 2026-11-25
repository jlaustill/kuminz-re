# J2 judge notes (round 94 judge of batch J2)

Earlier run left only asm dumps (asm_*.txt, no notes) - regenerated/re-checked below.

## Findings
- 0x1fdc0 CONFIRMED cm550_recordJ1922ControlOccurrence: asm 0x1fdc0-0x1fe3e: bit 0x80 of 0x803c98; mode 1 -> 804164++,804170++, hour 0x80bda4 -> 804172/804166; 2 -> 804176/78; 3 -> 80416a/6c. CM848 never reads j1922_monitor_enable (0 hits in cpp; struct says no reader) -> standalone.
- 0x1fd6c CONFIRMED cm550_clearExpiredJ1922ControlOccurrences: bit 0x100; (0x804166)+(0x808190) < (0x80bda4) unsigned -> 8 clears. Caller task set 0x1b6d6.
- 0x2142c CONFIRMED twin of 0x50aec0 (asm both: 0x1000 / mode 2 / dev 1 / mode 1 / dev 1 / fuel>=limit; stores 0,125,0,0). Both directly before the periodic queue runner.
- 0x23820 CONFIRMED twin 0x53c68 (word0/byte2/word4 compare, recovery -> +6, ret 1, step 8).
- 0x239d2 CONFIRMED twin 0x53fa8 (backward loop, word0+byte2 match, last entry copied, 4 fields).
- 0x23870 / 0x238ec / 0x23a3c CONFIRMED counterparts (CM848 6-byte entries with a mode word; CM550 4-byte, byte only).
- 0x23920 CONFIRMED counterpart (CM848 0x53dc8 clears high_idle_override_active_flag + blocked message bits on expiry).
- 0x238ac: code = CM848 0x53d3c except capacity 5 vs 10; CM848 adds caller cm848_updateParkNeutralFlagAndTsc1Activity x3. Counterpart (conservative) kept; precedent findTsc1SourceConfiguration 5/10 was called twin in r91.
- 0x142a8 CONFIRMED twin 0x53a4c (3 low-byte compares 0x60f83/85/87 | 0x5a470/72/74 -> 1/2/3 else 4; callers processEngineTsc1Request x3 + retarder handler x2 both).
- 0x21642/0x2167e/0x216c6/0x21714/0x21778/0x21872 CONFIRMED twins of 0x50b1b8/0x50b228/0x50b298/0x50b300/0x50b38c/0x50b4d8 (asm both, same copies/offsets; registrar same 6 ids same order 44,45,4b,4d,47,49, directly before registerJ1939DiagnosticHandlers in both start-ups).
- enum J1939_DIAGNOSTIC_SERVICE 68/69/71/73/75/77 CONFIRMED: CM848 member names, unique in CM550's enum; the only typed use is j1939_diagnostic_service_entry_t.service_id (dispatcher compare against a variable); handler roles verified in asm.
- 0x21f4e / 0x21fac / 0x22070 CONFIRMED twins of 0x50be6c / 0x50beec / 0x50bff4 (asm both: same index/24/5/12-word copy; same 13 stores per half (mode-word clears ascending vs descending only); tracker same decision tree, network 1 test engine only, 5-mode append/shift, same 5 previous copies in same order; 3rd call of the 10 ms J1939 list in both).
- 0x231da CONFIRMED cm550_resetEngineTsc1Request counterpart (stores mode->0x801982, clr mode/0x80da4e/0x80da60, jsr 0x1fdc0, clr 0x80da80/0x80da7e; 5 callers in 0x23244; CM848 does the reset inside cm848_runTsc1LostManagement).
- 0x23216 CONFIRMED twin 0x27118 (7 stores, 125).
- 0x23244 CONFIRMED counterpart cm550_runJ1939PowertrainControlTimeouts (asm 0x23244-0x2381e).
- 0x1ff38 CONFIRMED counterpart (CM848 adds DM13 bits). Registrar 0x1fe84 (no row; pea at 0x28b8c) writes +0 key / +2 period/10 / +4 tick+offset/10 / +6 builder; capacity 20/10.
- 0x212b2 CONFIRMED mc68k_ counterpart (CTM4 0xfff404 budget 250; 82527 0xffd810+16n; CM848 TouCAN/TBL 9).
- 0x21920 CONFIRMED counterpart (bit4->0x40+0x01, bit1->0x10, bit6->0x04 of 0x80bcf6 | CM848 four flags).
- ROM 'table' 0x1b4da-0x1b4e9 = operands of jsr #1-#3 in task set 0x1b4d8 (live: cm550_runEvery2FramesTaskSetPhase0); bsr.w from 20 frame sites 0x1b960..0x1be4c; 0x1b504 (live ...Phase1) 20 sites. Nobody walks it.
- J1922 handler 0x1f4e8 (tail 0x1f7b0-0x1f84c) sets 0x80da54+0x80da86, 0x80da56+0x80da8a; J1708 handler 0x1f84e sets 0x80da58+0x80da8c (no +1). ETC1 handler 0x2efd0 sets the same. => etc1_/pgn61442_ names over-claim in CM550 -> AMEND 0x80da58 progressive_shift_disable_flag, 0x80da8c progressive_shift_disable_timeout_timer, 0x80198e progressive_shift_disable_flag_previous, 0x801990 driveline_disengaged_flag_previous, 0x808184 j1939_high_idle_override_time_limit (parallel to CM550 j1939_high_idle_override_speed). All unique (frozen + live + batches).
- 0x80da90 REFUTE (only clr.w x4, no reader; CM848 field itself 'inferred').
- swallowed rows OK: 0x8041fc/0x804216 (= +4 count of the records, no abs ref); 0x801998..0x8019b8 (inside engine list; only base-relative in the list functions; 0x8019b8 = retarder base-4). Must be removed by apply.
- CM848 0x40ad56 rename to j1939_source_address_blocking_table CONFIRMED (dispatcher skips handler on match; e2m 10E4 JCSABLTB -> 0x40ad54 length word).
- Comment fixes: 0x22070 plate (source change does not clear the status - it files and reopens; network change files without a duration); 0x80da86 comment (J1922 handler 0x1f4e8 also loads it with its request timeout d3 at 0x1f802).
- Globals checked by abs_refs + e2m: J1922 cells word/dword ok; 0x808190 dword; session words; previous copies (0x800b18/19, 0x801986, 0x80198c byte); flags 0x801992/93 byte; queues (RAM dump: 17 + 2 entries, +0 = PGN 65265.., +2 period ticks, +4 next, +6 builder); 0x80d9e0 byte[4] (dispatcher + init fill 0xFE); 0x80d9de written once (#4) + parameter ID table; 0x803d4a in window -> _cal ok; 0x60f82/84/86 ROM above dump (rows above 0x40000 exist: 0x60fa8) ok.
- Struct types are new in CM550 (none collide): j1939_control_session_t 24, j1939_periodic_transmit_entry_t 10, engine_tsc1_ignored_request_t 8, retarder_tsc1_ignored_request_t 4 - definitions in investigator result_full.json notes #4; layouts proven from every access.
- Apply notes: CM848 twin renames must carry into function_definitions/local_variables (8 of the 14 CM848 twins have rows); CM550 rows too.

## Final (built by build_verdicts.py -> verdicts.json)
- functions 25 CONFIRMED + 1 AMENDED (0x22070 comment); globals 60 CONFIRMED / 6 AMENDED (0x80198e, 0x801990, 0x80da86 comment, 0x80da8c, 0x80da58, 0x808184) / 1 REFUTED (0x80da90); enums 6 CONFIRMED.
- e2m lengths re-checked: JCTRSA/JCABSA/JCARSA 2, JC22CCTM 4, JCEGOSTL 2 (10 ms), JCPSDB 2, VSRSSNTY 2.
