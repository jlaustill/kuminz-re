# R4 describer notes (round 97)

## Method / tools (scratch/R4/describer/scripts)
- usage_map.py: cpp-name users + ROM abs-long refs per family row -> usage_map.txt
- range_refs.py: any 4-byte value in a range (any alignment)
- based_refs.py: linear sweep per function, tracks movea.l #imm / lea abs,An and resolves (An)/(d16,An)
- e2m_by_address.txt (CM550 records), cm848_819x.txt (CM848 8192-81A0 blocks)

## Global facts
- No family row is inside the CM550 EEPROM window 0x803b0a-0x804f93 -> no _cal anywhere.
- Rows with NO access at all (abs-long any alignment + based-register sweep): 0x8016b0..0x801718 cluster (RAM all zero),
  0x803410..0x803424 (RAM zero), 0x80373c, 0x807840, 0x807d90, 0x808794, 0x8087c2, 0x8087ec..0x808814, 0x809b02..0x809b0a,
  0x80a9f6, 0x80d076, 0x80d088, 0x80d08a, 0x80d2c8..0x80d2cb, 0x80deda(?check a0=0x80ded4 users), 0x807e9b, 0x807ea6,
  0x807ec6, 0x807f52, 0x807faa, 0x807fab, 0x80d042, 0x80d064.
  These old names (eps_*/dzg_* undefined) were added in commit 1d82e3f4 (J90280.05 removal: rows carried over).
- Halves of dwords: 0x80d07a = low word of dword 0x80d078; 0x80d07e of 0x80d07c; 0x80d082 of 0x80d080; 0x80d086 of 0x80d084;
  0x80d08e of 0x80d08c (function pointer, values 0x1770a / 0x17f74).
- 0x80d078 dword: pointer to the last entry of the primary speed period ring (start 0x80cd1e, next pointer 0x80cd08)
- 0x807d90 (dzg_threshold_level_2): e2m 1300 +12 EDCVTY 'DEFINES THE INPUT SIGNAL TYPE 0 = DISCRETE, 1 = ANALOG, 2 = NONE'
  (one of the per-channel TY words of block 1300: BW/CV/CP/CQ/OS/IM/O2/O3, each with TMFT/PEFT/MNMX). Whole block 0x807d7e-0x807dd3
  referenced only by the parameter ID table entry @0x36b9c (block base). Current name wrong. 'CV' not expandable from code/e2m.
- cm550_calculateEngineSpeed (0x171be): counts down main/backup/external lost counters; sets _DAT_0080cd06 = K1/avg period (main rpm),
  0x80cd04 = backup rpm; ESFXSNTD 0x807eda = rpm threshold (> it) for the lost-duration counters:
  0x80d05a ESMNLSEL (main lost duration) limit 0x807ee0 MNLSMXEL -> status word 2 bit 0x1000
  0x80d05c ESBKLSEL? (backup) limit 0x807ee2 BKLSMXEL -> bit 0x400 ; 0x80d05e ESEXLSEL limit 0x807ee4 EXLSMXEL -> status 18 bit 4
  0x80d058 CRLSEL crank sync lost duration (counts while cam_sync_status==0 & rpm>thr, limit max_crank_sync_lost_duration) -> bit 0x4000
  then calls (*0x80d08c)() = speed measurement function pointer (0x1770a set by initializer, 0x17f74 by the TPU ch10 initializers).
- CM848 mnemonic matches: ESTDCU01 primary_consecutive_error_threshold; ESTDCU02 backup_consecutive_error_threshold;
  ESFXSNTD engine_position_sensor_error_detection_minimum_engine_speed; ESMNISCT/ESBUISCT 117D +2C/+2E (no CM848 row);
  ESACBKGR engine_speed_state.backup_speed_period_sum_between_vss_pulses; ESCTBKGR engine_speed_state.backup_speed_pulse_count_between_vss_pulses;
  CKINRPAJ crank_initial_rpm_adjustment (105E +22 in CM848, +26 in CM550); ESVSAVPE = CM848 1008 +4 (same block/offset/description) drivetrain_ratio_engine_period_average
- No global base register in CM550 (unresolved_base.py: the only unresolved (d16,An) are data decoded as code). No pointer at all into
  0x801500-0x801900, 0x8036f0-0x803780, 0x808780-0x808830, 0x809ae0-0x809b20 (range_refs.py) -> the J90280.05-carried rows there are
  unreferenced in the dumped J90350.00 ROM (RAM 0x8016a0-0x80171f and 0x803400-0x80342f all zero; 0x808790-0x808815 holds a
  descending word series 0x0b45..0x0830 - some table, no code/e2m ref). Skip them (no evidence), suggest the rows be reviewed for removal.

## Primary speed input (TPU ch10) - read from code
- init (0x1999c/0x19caa/0x1a350/0x1a746): 0x80d078 = &pulse_period_table[ESPECM01-1] (last entry; table 0x80cd1e), table filled with
  ESIITB01; 0x80d080 = &table[0] (trailing pointer); next ptr 0x80cd08 = table or table+ESPECY01*4 (if ESCMTT>=2);
  pulse_period_sum_primary = init*ESPECM01; average period = init*ESPECY01.
- handlers 0/1/2 + 0x1a95a: period from TPU 0xffffa8 -> 0x80d04a; sum += new - *next; *next = new; next wraps at 0x80d078;
  average += new - *trailing(0x80d080); trailing wraps at 0x80d078 -> average = sum of the last ESPECY01 periods.
  sample crank degrees += ESPECK01 (0x807ec4, word). tooth counter 0x80ccea (EGPITTCU) 0..ESPECM01-1 (modes 0/2), reset in 0x1a95a.
  ESMNISCT 0x80a9f4 += 1 per primary interrupt (modes 0,1,2,3).
- 0x19f82 (TPU ch0 interrupt, config 1; installed by mc68k_initializeTpuChannel0MissingToothInput as 0x808edc): TPU_CH15_PARAM6 hi byte ->
  0x80d293 CKSYERTY, lo byte -> 0x80d292 CKSYERTT; on no error (0/0xff): ch10 PARAM1 low byte -> 0x80d294, reload it with ESPSCURS
  (0x807f51); ESPSCURS - count != 1 -> fault bit 0x2000 of 0x806004. error 0x80-0x8f with rpm>ESFXSNTD -> crank sync status 2.
- 0x1a6e8 (config 2 TPU ch0 handler): same unpack of TPU_CH15_PARAM6; type 0xc0 -> cam sync state/status 0 else 2.
- 0x808794 / 0x8087c2 / 0x8087ec / 0x8087f6 / 0x8087f8 / 0x808804..0x808814 = CELLS of e2m 12DF PPCVTB 'TABLE OF FUELING CURVES' (Z, 2-byte,
  0.0679 mm3): 0x8086f2..0x808895 = 21 rows (PPSSFLXA engine speed axis at 0x8086c6: length word 0x2a + 21 words 0..0x8ca0 = 0..4500 rpm)
  x 10 curves (PPHPCTI index), next block PPSEAVTB at 0x808896. RAM: rows of 10 equal values 0x0939..0x0830 then 0x0008. Only the
  parameter ID table entry (ROM 0x36a94) points at 0x8086f2; no code ref. Cell index = (addr-0x8086f2)/2: 0x808794=81 (row 8 col 1),
  0x8087c2=104, 0x8087ec=125, 0x8087f6=130, 0x8087f8=131, 0x808804..0x808814 = 137..145.
- 0x809b02 / 0x809b08 / 0x809b0a = bytes 276/282/284 of e2m 823D +0x806 CBDFTTB4 'CYLINDER BALANCING FFT TRENDING TABLE_4' (B, 600 bytes,
  0x8099ee-0x809c45). No ref into 0x8092e6-0x809e9d anywhere. extended RAM zero.
- 0x80d076 = low word of dword 0x80d074 (backup pulse period sum: init*ESPECM02 in the 3 ch1 set-ups, K2/it in cm550_calculateEngineSpeed;
  sibling of pulse_period_sum_primary 0x80d070). 0x80d088/0x80d08a: no access, no e2m record.
- 0x807840 = low word of FLTAPSTT (11FE +6, 4 bytes 0x80783e-0x807841): explains '_dzg_angular_duration...' underscore render.
- block 1008: +0 VSPSPD 0x80ded6 (4 bytes), +4 ESVSAVPE 0x80deda (4 bytes): no access in the dumped ROM; CM848 1008 +4 same description
  -> drivetrain_ratio_engine_period_average (dword, set in cm848_vehicleSpeedSensorInterruptHandler).
- pulse 0 line: 0x80847a ESPSPGIN (11A9 +4), 0x80847c ESPSPGSL (11A9 +6), word each, one read each in cm550_calculateEnginePositionPhaseLag:
  engine_position_pulse_0_phase_lag (0x80db66) = (ESCWAJ + ESPSPGIN + avg_rpm*ESPSPGSL/16)/16 -> names
  engine_position_pulse_0_phase_lag_intercept / _slope (pair with round-96 engine_position_normal_phase_lag_intercept/_slope).
- CKINRPAJ 0x80d0be: crank_adjusted_initial_rpm = it + crank_initial_fuel_break_speed (cm550_rpmBasedFuelLimitCalculator); ramped in
  JUMP_START (0x17d6a), zeroed SHUTDOWN->STOPPED, set to crank_exited_initial_rpm_offset in REENTRY (0x17eba). CM848 crank_initial_rpm_adjustment.

## Phase check (12A1 / 12A2) - read from code
- 0x1a1e0 (called by the 4 primary handlers, abs jsr at 0x19c58/0x19f52/0x1a6b8/0x1a908) and 0x1a298 (no caller): identical bodies except
  the gate: 0x1a1e0 runs while 0x80aa16 (primary period was NOT the sync pulse) == 0, and sets ESMNIPER=1 when the BACKUP lost counter is 0;
  0x1a298 gates on 0x80aa18 (backup) and sets ESBUIPER=1 when the MAIN lost counter is 0. When EGPITTCU == EGPIBKCU:
  ESPHDF 0x80d298 = backup edge 0x80d054 - main edge 0x80d052 (i16). > ESPLPHTD(0x807f58 i16): ESPLPHCU++ up to ESMXPHCU(0x807f5c), at
  the limit ESBUIPER=0; ESNGPHCU=0; ESMNIPER=1. < ESNGPHTD(0x807f5a): ESNGPHCU++ up to ESMXPHCU, then ESMNIPER=0; ESPLPHCU=0, ESBUIPER=1.
  Inside: both counts 0, both flags 1.  EGPIBKCU 0x80ccec and the backup edge time 0x80d054 are only READ in the dumped ROM.
## Cam index (CI) pulse handler 0x1af32 (TPU ch1, cam sync type 1; installed by mc68k_initializeTpuChannel1BackupSpeedInput @0x808ee0)
- CMSNTTCU 0x80d2be = TPU ch1 PARAM5 low byte (0xffff1b) = primary teeth counted during the CI pulse; 0x80d2c2 (named can_tx_message_type!)
  reloaded from 0x807f9d (CMSNTMCU low byte, CI lost count max). == CMSNCU01 0x807f98 (wide) -> check EGPITTCU == EGPSCU01 0x807f94 ;
  == CMSNCU02 0x807f9a (narrow) -> EGPITTCU == EGPICU02 0x807f96. Match: cam sync state/status 1, CKTTCUER 0x80d2bf counted down;
  mismatch: state 2, EGPITTCU := expected, CKTTCUER++ up to 0x807f9e (CKTTERMX) then status word 0 bit 1 + word 2 bit 0x800.
  Neither width: CMSNCUER 0x80d2c0 ++ up to 0x807f9f. (CI = 'CMSN' cam sensor pulse; never spelled out in the e2m)
## Missing tooth (11C4 / 11C5)
- ch0 set-ups: PARAM1 = ESNOTTCU(0x807f4e, byte, 34 in RAM) | 0x100; PARAM3 = ESNOTTRA(0x807f4f, byte, 0xba) << 8 | ESMXTTCU(0x807f50).
  angle pulse code: tooth = (angle>>16) % (ESNOTTCU + 2). ESPSCURS 0x807f51 (2 in RAM) reloads ch10 PARAM1 low byte at the missing tooth.
  ESNMTTMS 0x807f52 (word, 1 in RAM): no access.
## Angle pulse output (TPU ch3, 11FE)
- FLTAPSOF 0x80783a (i32, add.l) + FLTAPSTT 0x80783e (4 bytes, add.l) in mc68k_setUp/updateTpuChannel3AnglePulseOutput: start = base +
  FLTAPSOF + FLTACYOF + per-cylinder angle + 0x100 (16.16 teeth); end = start + FLTAPSTT -> TPU_CH3_PARAM4 / PARAM5.
- FLCYCUPZ 0x807839 (byte): mc68k_alignCylinderIndexToCrankRevolution: next_injected_cylinder = (FLCYCUPZ + index) % 6 + 1.

## Final decisions (names in draft_names.txt, with these changes)
- 0x80d2c8 ESCKSNOF -> crank_sensor_not_used_flag; 0x80d2c9 ESCMSNOF -> cam_sensor_not_used_flag (CK/CM letters; pair with 121D
  CSCKFXCU/CSCMFXCU 'threshold at which crank/cam sensor no longer used'); 0x80d2cb CSCMPSCU -> cam_pulse_count_since_missing_tooth;
  0x80d2cc CSCMSYCU -> cam_pulse_count_since_additional_pulse; 0x807fab CSCKTTCM -> expected_crank_teeth_between_additional_cam_pulses.
- pointer rows typed 'dword *'; trailing pointers -> pulse_period_table_average_oldest_entry_pointer / pulse_period_table_backup_average_oldest_entry_pointer
- RAM evidence: ESPECM01 24, ESPECY01 4, ESPECK01 480 (30 deg), ESCMTT 72, ESTTIP 3; ESPECM02 1, ESPECY02 1, ESPECK02 11520 (720 deg);
  ESFXSNTD 480 (60 rpm); 0x80d078 = 0x80cd7a (&table[23]); 0x80d080 = 0x80cd1e; 0x80cd08 = 0x80cd2e; 0x80d07c = 0x80d084 = 0x80ceae;
  0x80d074 = 6700000 (= ESIITB02 x 1); 0x80d293 = 0xc0, 0x80d292 = 8; EDCVTY = 2 (NONE); FLTAPSOF 0xfffb (~10 deg), FLTAPSTT 0x37fee (~35 deg).
- cm550_calculateEngineSpeed is called from cm550_runEvery4FramesTaskSetPhase0 and Phase2 (10 ms) -> lost durations in 10 ms ticks (MNLSMXEL 0.01 s).
- Skips: 0x8016b0..0x801718 (17), 0x803410..0x803424 (9), 0x80373c, 0x807840 (half of FLTAPSTT), PPCVTB cells (14), CBDFTTB4 bytes (3),
  0x80d076/0x80d07a/0x80d07e/0x80d082/0x80d086/0x80d08e (dword halves), 0x80d088/0x80d08a (no access).
- EDCVTY 0x807d90 -> coolant_level_abuse_input_signal_type (CV = coolant level per EDCVTD01-03 / EDCVSG01-03 in the other e2m files).
