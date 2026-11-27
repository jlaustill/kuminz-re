# L2 judge notes (round 94)

NOTE: the worktree's CM848 .cpp is mid-rebuild (735 functions, 1.3 MB at 08:21) - disasm_func.py snaps flash2
addresses wrong. Use objdump on cm848_flash2_live.bin directly + the FROZEN cpp for boundaries.

## 0x1fe84 -> scheduleJ1939PeriodicMessage (TWIN of CM848 0x538c8c) - CONFIRMED
- CM550 asm 0x1fe84-0x1ff36: count0 0x800a9a / count1 0x800a9b / tick0 0x800a9c / tick1 0x800a9e; queue 0 cap 0x14,
  entries 0x80096e + n*10; queue 1 cap 0xa, entries 0x800a36 + n*10; stores +0 PGN (0x14,a7), +4 offset/10+tick,
  +2 interval/10, +6 builder long; return 1 full / clr.b 0. Switch on 0 / 1 (other values fall to stores with a2 unset).
- CM848 objdump 0x538c8c-0x538d38: count0 0x3fd40e / count1 0x3fd40f / tick0 0x3fd410 / tick1 0x3fd412 (same adjacency),
  cap 20 / 10, entries 0x3fd2e2 / 0x3fd3aa (+200 = queue 1, +100 = count0: SAME LAYOUT as CM550 0x80096e/0x800a36/0x800a9a),
  same store order (+0, +4, +2, +6), li r3 1 / 0. Only diff: CM848 queue != 0 -> queue 1 (if/else vs switch).
- Callers: CM550 mc68k_initializeJ1939Datalink 19 x jsr (a4) (0x28c6e-0x28e14) after 21 buffer initializers;
  CM848 cm848_j1939_system_init 19 calls after the buffer initializers. 15 tuples identical; 61443 (50 vs 20) and
  65247 (250 vs 50) differ in interval; CM550 65266 / 65252 vs CM848 65241 / 65504.
- Name unique in both CSVs (only cm848_scheduleJ1939PeriodicMessage exists). CM848 row 0x538c8c renames too.

## 0x33d38 -> cm550_buildPgn65252ShutdownMessage - CONFIRMED (standalone)
- asm 0x33d38-0x33df8: a0=a1=0x8035f6; jump table 0x33d5a (000c 0010 0016 0026 001c 0022) -> 0:clr 1:0x40 2:0x44 3:none
  4:0x10 5:0x01; byte 2 0x7f/0x3f from 0x803c9a & 2; byte 3 0xfd/0xfc from 0x80bcd7 bit 0; byte 4 0xfd/0xfc from
  0x80bcf6 bit 0; pea 0x8035e8 / jsr 0x104e8 cm550_sendCanMessage.
- Reached: pea 0x33d38 at 0x28d2e (schedule 0, 0xfee4, 1000, 110) and 0x2f586 (0x2f47e(0xfee4, 0x33d38): responder
  table 0x801d5a 6-byte {PGN, handler}, cap 32, count 0x801e1a; walked by 0x2f4be, registered for 0xea00 at 0x2f540).
- CM848: only registerJ1939ReceiveHandler(0xfee4, receivePgn65252ShutdownMessage); no transmitter -> standalone.
- Name free; pattern = cm848_buildPgn<N><Name>Message.

## 0x33dfa -> cm550_initializePgn65252ShutdownBuffer - CONFIRMED (standalone)
- asm: can_id 0xfee400 | (0x803f78 & 7) << 2 in byte 0 (andi.b 0xe3), dlc 8, data 0x8035f6, status 0x8035fe,
  SA byte 3 = 0x80da01, payload [4..7] = 0xff, rts (no send). Called once, jsr at 0x28c30 (15th of 21 initializers).
- No engine hours (that's 65253) and no VP44. Old name wrong.

## globals 0x803f78 / 0x80bcd7
- 0x803f78: e2m 1254 +2A JCISSHPZ 'DEFAULT NETWORK PRIORITY FOR IDLE SHUTDOWN MESSAGE' 0-7, N, length 2; one ref
  0x33e10 move.w. EEPROM window -> _cal. j1939_pgn65252_priority_cal free. CONFIRMED.
- 0x80bcd7: e2m 000E +9 DSAKPRSW 'SOFTWARE VALUE OF AIR CONDITIONER PRESSURE SWITCH INP(UT)' bit 0; written (bit 0) by
  mc68k_sampleAndDebounceDiscreteInputs from 0x80bcd0 bit 1 (000E +2 DSAKTKSW 'byte 2 bit 1 ... debounced switch'),
  read only at 0x33d9a. Byte accesses. air_conditioner_pressure_switch_state free.

## ETC1 0x801d44 / 0x801d48 (handler 0x2efd0, registered 0xf002 at 0x2f114) - AMEND names to PGN form
- asm 0x2efd0: SA (3,a3) == word 0x60f82 or 0x60f82 == 0xff; dlc == 8; move.b (data),(0x801d44); data[4] -> 0x801d48.
  byte5 &3==1 + tsc1_override_control_mode==1 + engine_control_device_indicator==1 (TRANS) -> high_idle_override_active_flag
  + timer (JCEGOSTM)+1; &3 not 1/3 -> clear flag/timers; recovery flag -> timer = JCTMRCTM+1. &0xc==4 -> progressive
  shift disable + timer; !=0xc -> clear. byte1 &0x30==0 && &3==0 -> driveline_disengaged_flag + timer + out_of_gear_network_type=1.
- Only refs: the moveas. ETC1 not in the workflow's acronym list; PGN form follows j1939_pgn61442_* (CM848) and both
  agents offered j1939_received_pgn61442_byte_1 / _5.

## TSC1 extras 0x801d4c-0x801d58 (processEngineTsc1Request 0x2f128) - CONFIRMED
- 0x801d4c <- data[0]; d3 = &3 mode, d4 = &0x30 priority. (2,a3)=0x801d4e <- data[1]; (1,a3)=0x801d4d <- data[2];
  (3,a3)=0x801d4f <- data[3]. Word rebuilt (1,a3)<<8|(2,a3) -> odd address -> byte[2] right for CPU32.
- 0x801d54: cmp.b vs d4 (bhi reject / bne) at 0x2f1f2/0x2f1fc; move.b d4 at 0x2f29e. 0x801d56 word: cmp at 0x2f22c,
  stores 0x2f320 (mode 1) / 0x2f41c (mode 3). 0x801d58: cmp at 0x2f212/0x2f220, stores 0x2f388 (mode 2) / 0x2f42c (mode 3).
- Existing rows only 0x801d44/48/4c/4f; new rows overlap nothing. Names free.

## DGFUIDEN 0x806abc -> fault_processing_enable_flags word[19] - CONFIRMED (comment amended: reader list)
- e2m DGFUIDEN,HEX,F,570,4D,B,37,38: block F 0x80654c + 0x570 = 0x806abc; length decimal (DGTJMSRI +566 len 10 ends at
  +570; +570 + 38 = 0x806ae2 = block 1003 ADIMTPCS intake_manifold_temperature_sensor_config). -> 0x806abc-0x806ae1.
- Every 32-bit operand in range in the ROM is an instruction operand (movea.l #imm / move.w abs,d0) - no pointer tables.
  range_writes.py (judge): 154 reads, 0 writes (absolute, base register, indexed (0,a0,d0.w*2)).
- investigator's dgfuiden_pairs.py re-run: all 27 direct reads SAME BIT as 0x806000 + 2k. 0x115a4: the enable bit
  gates the latch of status word 0 bit 12. 0x148fe fault scan: DGFUCATB 0x80656c index < 125, then enable[word] & bit.
  0xb8b8: status[n>>4] & 1<<(n&15) && enable[n>>4] & same bit.
- Indexed readers: mc68k_processAnalogSensorChannels (2), cm550_initializeAnalogSensorChannels (4),
  vp44_rpmDerateCalculationController (2), vp44_derateThresholdMonitorAndFaultController (2), cm550_processFaultScanGroup (2).
  Word 3 only via base register (cm550_highRpmEngineProtectionStateMachine (6,a2), j1939HandlePgn61443Eec2).
- RAM dump: fc00 2600 d007 006b 2b3f f800 b7ee 0200 ea00 0299 0040 0000 x5 f800 f7bf 0efb (matches).
- Rows swallowed: 0x806abe / ac0 / ac2 / ac4 / aca (all misnamed elements); 0x806ae2 outside. Outside EEPROM window -> no _cal.

## 2D lookup functions - all CONFIRMED (counterparts)
- callers (ROM search, no bsr): 0x269f2 jsr 0x1b56a last of cm550_runEvery4FramesTaskSetPhase0; 0x26a2e jsr 0x2896a and
  0x26a7e jsr 0x28912 in mc68k_applicationMain; 0x26ab8 jsr 0x1b5ec 6th of cm550_runEvery4FramesTaskSetPhase2.
- record table_lookup_2d_arguments_t: +0 x off, +2 x ptr, +6 x_input, +8 y off, +a y ptr, +e y_input, +10 z ptr.
- 0x269f2: x=engine_rpm_primary (MTTQMPXA rpm) y=alpha_blend_factor (MTTQMPYA) -> 0x80db1a, floor 1.
- 0x26a2e: 0x80db1a=1; ptrs 0x808346/0x808372/0x80837c, offsets 2.
- 0x26a7e: y off 2, y ptr 0x807944, x off 2, x ptr 0x80793a, z 0x80794e; clr 0x80a270 then 0x80a26e.
- 0x26ab8: if 0x803cd4 & 1 (misfire_timing_limit_enable, BSTALMEN): x=0x80a320 (boost_pressure_sensor_state.filtered_value),
  y=engine_rpm_primary -> 0x80a26e.
- CM848: 0x29c98 3 lookups (alpha 0 / chi lower / chi upper) + cm848_interpolateAlphaChiValue -> fuel_demand_filter_dimension,
  0->1; 0x29de0 dimension=1 + 3 caches 2; 0x29e24 caches 2 + clear 0x40aeea (8A3D +2 SOI_Before_MST) + 0x40aee8;
  0x29e50 gate + cm848_calculateBoostPressure() x + args lookup. Different code -> counterparts.
- Names unique.

## globals 0x80db1a / 0x80a26e
- 0x80db1a: writers 0x269f2 (lookup + floor), 0x26a2e (=1), AND cm550_FUN_0001c0d4 (0x1c0f0 floor at 1 again) - the
  investigator's comment omits the third writer -> amend comment. Reader/divisor 0x1c0fc. ROM table 0x376a8 (address list).
  CM848 fuel_demand_filter_dimension is used identically (floor 1, divisor + no_load_fuel_quantity). CM848 e2m 1461 not in
  its dumped table. Name OK.
- 0x80a26e: clr 0x26ab0, store 0x26ae6, read cm550_applyMisfireTimingLimit 0x26b24/0x26b2a (bls unsigned; raises
  fuel_timing_advance_value). CONFIRMED.

## 0x801d54 / 0x801d58 comment errors (TSC1 arbitration, CM550 0x2f1f2-0x2f242 == CM848 processEngineTsc1Request)
- equal priority: active mode must be 3; new mode != 3 (1/2) -> ACCEPT at once (bne.s 0x2f242); new mode 3 -> needs
  lower torque, or same torque and lower speed. Investigator's "only a mode 3 request can take over" is wrong -> amend.
- 0x801d58 "needs a lower torque" incomplete (equal torque + lower speed also wins) -> amend.

## 0x803f78 name vs stale rows
- CM550 rows 0x8037b6 can_priority_table_start / 0x8037b8-0x8037ee j1939_priority_pgn<N> (incl. j1939_priority_pgn65252
  at 0x8037e0): no abs ref, no e2m record, dump = pointers/zeros. Real priorities = e2m block 1254 at 0x803f4e (all 6 ...).
  -> lead: those old rows are wrong. j1939_pgn65252_priority_cal is exact-unique; CM848 0x3fd862 has no reader (no 0xd862
  displacement in ROM/flash2).

## FINAL DECISIONS (judge)
- functions: all 7 CONFIRMED (0x1fe84 twin -> CM848 0x538c8c same name; 0x33d38 / 0x33dfa standalone; 4 lookups counterparts).
- cm848_function 0x538c8c CONFIRMED scheduleJ1939PeriodicMessage; comment appends the twin note (repo convention).
- globals: 0x801d44 / 0x801d48 AMENDED -> j1939_received_pgn61442_byte_1 / _byte_5 (ETC1 not in the allowed acronym list;
  PTO precedent; PGN form = j1939_pgn61442_* family; both agents offered it).
  0x801d54 / 0x801d58 AMENDED comments (equal-priority takeover). 0x806abc AMENDED comment (full reader list).
  0x80db1a AMENDED comment (third writer cm550_FUN_0001c0d4 floor). Others CONFIRMED.
- verified: all TSC1/ETC1 image accesses (range_writes 0x801d44-0x801d5a) are in 0x2efd0 + processEngineTsc1Request at the
  proposed widths; 0x80bcd7 writer ori.b/andi.b (9,a4) in mc68k_sampleAndDebounceDiscreteInputs.
- DGFUIDEN contents found only in the RAM dump (not ROM / EEPROM / extended RAM).
- leads: stale comments naming old function names (j1939_pgn65252_tx_message row, misfire_timing_limit_enable bitfield,
  injection_timing_misfire_limit_grid); wrong rows 0x8037b6-0x8037ee j1939_priority_pgn<N>; 0x2efd0 describer extra;
  0x1fe84 function_definitions row.
