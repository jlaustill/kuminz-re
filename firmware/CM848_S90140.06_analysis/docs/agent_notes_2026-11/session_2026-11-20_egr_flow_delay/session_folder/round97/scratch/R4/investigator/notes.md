# R4 investigator notes (round 97) - CM550 engine position sensor / speed measurement globals

## Method / sources
- abs_refs_all.txt = abs_refs.py over all 114 rows; cpp_users.txt = decompile users per row; e2m_cm550.txt = e2m record per row.
- No _cal anywhere in this batch: no row lies in the EEPROM image 0x803b0a-0x804f93; the 0x807xxx / 0x808xxx cal
  rows next door carry no _cal (ROM to RAM copy).

## Clusters with NO reference in the dumped ROM
- 0x801400-0x8017ff: no 4-byte constant in that range anywhere in the ROM, no decompile user, RAM dump all zero.
  Rows 0x8016b0..0x801718 (17) came from the removed J90280.05 analysis (git: added by 1d82e3f4). -> skipped.
- 0x803300-0x803447: no ROM constant (first referenced address is 0x803448); 0x803410..0x803424 (9 rows) zero in RAM. -> skipped
- 0x80373c: no ROM constant in 0x8036e3-0x8037ff; RAM byte 0x80373b = 0x8e only. -> skipped
- 0x808700-0x808895: no ROM constant; RAM holds a repeated-word calibration table (0x0b45.. 0x0830) -> rows inside a table
- 0x809a00-0x809bff: no ROM constant; RAM zero -> skipped

## 0x80d078-0x80d087: four dword RAM pointers in the dump (0x80cd7a, 0x80ceae, 0x80cd1e, 0x80ceae)
  -> 0x80d07a / 0x80d07e / 0x80d082 / 0x80d086 are the low halves (skip: delete rows) - to confirm from code

## CM848 records with the same Calterm mnemonic (CM848's labelled e2m quotes the mnemonic in [ ])
- ESTDCU02 (CM550 0x807e9b 11CA +1) = CM848 8194 +0 0x408f56 backup_consecutive_error_threshold byte
- ESTDCU01 (CM550 0x807e9a 11CA +0) = CM848 8194 +2A 0x408f80 primary_consecutive_error_threshold (word in CM848, byte in CM550)
- ESFXSNTD (CM550 0x807eda 100B +32) = CM848 8194 +1A 0x408f70 engine_position_sensor_error_detection_minimum_engine_speed
- CKINRPAJ (CM550 0x80d0be 105E +26) = CM848 105E +22 0x40a7ba crank_initial_rpm_adjustment
- ESACBKGR (CM550 0x80d042 100C +350) = CM848 819B +24 engine_speed_state.backup_speed_period_sum_between_vss_pulses (4 bytes)
- ESCTBKGR (CM550 0x80d048 100C +356) = CM848 819B +2A engine_speed_state.backup_speed_pulse_count_between_vss_pulses
- ESMNISCT / ESBUISCT (CM550 0x80a9f4 / 0x80a9f6 117D +30/+32) = CM848 117D +2C/+2E 0x40a294 / 0x40a296: no CM848 row

## Primary / backup pulse period rings (TPU ch10 primary, ch1 backup) - SURE
- 0x80d078 (was eps_control_mode_param_1): move.l only (18 refs). Set-ups 0x199d2 `lea (-0x4,a3,d0.l*4),a0` a3=0x80cd1e,
  d0=ESPECM01 byte -> &pulse_period_table[n-1]; fill loop `cmpa.l (0x80d078),a2; bls` writes table[0..n-1]; handlers wrap
  the write pointer 0x80cd08 and the average pointer 0x80d080 to 0x80cd1e when they reach it. Round 87 plate of
  cm550_detectEngineSpeedSensorSyncPulse already says 'last entry 0x80d078'. -> pulse_period_table_last_entry_pointer, dword
- 0x80d07c (was eps_control_mode_param_3): move.l only; = n_backup*4 + 0x80ceaa = &pulse_period_table_backup[n-1] (backup set-ups
  0x1ae22 / 0x1b1ea / 0x1b39a); read by cm550_detectEngineSpeedSensorSyncPulse(1). -> pulse_period_table_backup_last_entry_pointer
- 0x80d080 (was eps_override_output_state): move.l; set-up = table base (write pointer = base + n_avg*4); each ch10 handler does
  average_pulse_period += period - *p; p++ (wrap at 0x80d078) -> the oldest entry of the 1-cylinder average window.
  -> pulse_period_table_average_oldest_entry_pointer
- 0x80d084 (was eps_control_mode_init_value_2): move.l; backup set-ups store table base; read only to seed 0x80cd0c when
  teeth_per_cam_rev_backup < 2 (0x1ae9c / 0x1b258 / 0x1b3f0); no backup handler advances it in the dump.
  -> pulse_period_table_backup_average_oldest_entry_pointer
- 0x80d07a / 0x80d07e / 0x80d082 / 0x80d086: no access at all; inside the dwords at 0x80d078 / 0x80d07c / 0x80d080 / 0x80d084
  (RAM dump: 0080cd7a 0080ceae 0080cd1e 0080ceae) -> skip, row to delete
- 0x80d04e ESIPBKPE: 0x1b32c `move.l (0xffff18).l,(a2)` a2=0x80d04e (TPU ch1 captured period), then copied to
  pulse_period_table_backup[0] and average_pulse_period_backup (0x1b36c / 0x1b372); read move.l by 0x102cc.
  -> backup_engine_position_sensor_period dword (main twin = main_engine_position_sensor_period, round 95)

## Phase check (e2m 12A1 / 12A2) - SURE (disassembly 0x1a1e0-0x1a296)
- 0x80d298 ESPHDF word: sub.w main edge (0x80d052) from backup edge (0x80d054), ble/bge = signed vs 0x807f58 / 0x807f5a -> i16
- 0x807f58 ESPLPHTD i16 positive threshold; 0x807f5a ESNGPHTD i16 negative threshold; 0x807f5c ESMXPHCU word persistence
- 0x80d29a ESPLPHCU / 0x80d29c ESNGPHCU word counters (addq.w, clr.w, bcc vs 0x807f5c)
- 0x80d296 ESMNIPER / 0x80d297 ESBUIPER byte flags (move.b #1 / clr.b)
- lead (function, not in batch): 0x1a1e0 cm550_rpmTimingDeltaComparatorWithReturn is the MAIN-period twin of
  0x1a298 cm550_checkEnginePositionSensorPhaseOnBackupPeriod (tests 0x80aa16 = sync result of sensor 0 and the BACKUP lost
  counter 0x80cd12); called from the ch10 handlers -> cm550_checkEnginePositionSensorPhaseOnMainPeriod

## Engine speed calculation cm550_calculateEngineSpeed 0x171be - SURE (disassembly 0x17300-0x174c0)
- 0x807eda ESFXSNTD (=480, 60 rpm): cmp.w with filtered speed 0x80ccf6 before each lost-duration count (0x1731a / 0x17464 / ...),
  also at 0x1a0be in the PMM handler. CM848 name engine_position_sensor_error_detection_minimum_engine_speed.
- 0x807ee0 MNLSMXEL / 0x807ee2 BKLSMXEL / 0x807ee4 EXLSMXEL: cmp.w limits of 0x80d05a / 0x80d05c / 0x80d05e; at the limit
  status word 2 bit 0x1000 / bit 0x400 / status word 18 bit 4.  -> *_lost_duration_limit
- 0x80d058 CRLSEL 'CRANK_SYNC_LOST_DURATION' (was dzg_pressure_threshold_high!): addq.w up to 0x807ede (CRLSMXEL) while
  0x80d0cd (CRSYSS crank sync state; row misnamed cam_sync_status) is 0 -> status word 2 bit 0x4000 (0x1746e-0x1748c).
- 0x80d05a ESMNLSEL / 0x80d05e ESEXLSEL counters (move.w / addq.w / clr.w).
- extra 0x80d05c ESBKLSEL (no row): backup counter (0x17324-0x17362).

## TPU ch0 PMM (period measurement with missing transition) - SURE
- undefined handler 0x19f82 (RAM vector 0x808edc) and mode 2 handler 0x1a6e8: 0xfffffc word >> 8 -> 0x80d293 (CKSYERTY error
  type; 0xc0 in dump) and 0xfffffd byte -> 0x80d292 (CKSYERTT tooth count; 8 in dump). 0x34b0a tst.b 0x80d293.
- 0x807f51 ESPSCURS (=2) byte: 0x19fda written into the low byte of TPU ch10 param 1 (0xffffa2) at the missing tooth;
  0x19fee: ESPSCURS - old low byte (0x80d294) != 1 -> status word 0 bit 0x2000.
- 0x807f4e ESNOTTCU (=34) byte: PMM param 1 = 0x100 | it (0x19e0c / 0x1a4b0); angle pulse modulus it + 2 (0x34866).
- 0x807f4f ESNOTTRA (=186, x1/128 = 1.45) byte: PMM param 3 high byte.
- 0x807f52 ESNMTTMS (=1) word: no access in the dumped ROM.

## Cam index (CI) handler 0x1af32 (named mc68k_dutyCycleMonitorIsrHandler - wrong name, lead) - SURE
- 0x80d2be CMSNTTCU byte = TPU ch1 param byte 0xffff1b (teeth during the CI pulse); vs 0x807f98 CMSNCU01 (=4, wide) /
  0x807f9a CMSNCU02 (=2, narrow) words; then tooth counter 0x80ccea vs 0x807f94 EGPSCU01 (=23) / 0x807f96 EGPICU02 (=11) word;
  equal -> cam_sync_state 1, else 2 and the counter is forced to the expected value; 0x80d2bf CKTTCUER byte counts the
  mismatches up to 0x807f9e (CKTTERMX) -> status word 0 bit 1 + status word 2 bit 0x800.
- lead: 0x80d2c2 ('can_tx_message_type', CMSNFXER neighbour?) = CI timeout counter reloaded from 0x807f9d (low byte of
  CMSNTMCU 0x807f9c) and decremented per primary pulse in mode 0/2 handlers. Not in batch.

## Angle pulse output (TPU ch3, Calterm 'DZG pulse') - SURE
- 0x80783a FLTAPSOF i32 (add.l at 0x3483e): start = cylinder TDC offset[idx] + FLTACYOF + FLTAPSOF + 0x80a236 + 0x100 (16.16 teeth)
- 0x80783e FLTAPSTT i32 (add.l at 0x34852): end = start + it. e2m 4 bytes signed. 0x807840 = its low half (no access) -> skip.
- 0x807839 FLCYCUPZ (=1) byte: next_injected_cylinder = (it + current_cylinder_index) % 6 + 1 (0x34b92).

## Block table (ROM ~0x35224..0x36c00, pairs of the block base): hits at 0x361bc-0x361f8 are DATA (11C4/11C5/11C8/11C9/11CA/11CB
   bases), not code. So 0x807e9a ESTDCU01 has no code reader; 0x807e9b / 0x807ea6 / 0x807faa / 0x807fab / 0x80d2c8-cb /
   0x80deda / 0x80d042 / 0x80d048 / 0x80d064 / 0x80a9f6 / 0x807ec6 have no reference at all -> names from their records.

## 0x808794-0x808814 (14 rows) = elements of PPCVTB 12DF +0 'TABLE OF FUELING CURVES' (Z record) at 0x8086f2:
   X axis PPHPCTI 0x8086b0 (20 bytes = 10 points 0..9), Y axis PPSSFLXA 0x8086c6 (42 bytes = 21 rpm points);
   210 words 0x8086f2-0x808895 (next referenced address 0x808896). RAM 0x8038c2 holds a table_lookup_2d_arguments_t
   (x 0x8086b0, y 0x8086c6, z 0x8086f2) - no code in the dump references 0x803800-0x803b07 or the table: undumped code.
   -> skip the 14 rows (delete); table row 0x8086f2 (now j1939_timeout_clear_value) could be typed word[210].

## Lead (not in batch): 58 rows 0x80ceb2-0x80d03c (can_transmit_buffer_ptr_*, fuel_arbitrator_*, retarder_*, ...) sit
   inside pulse_period_table_backup (e2m 100C +1BC ESPSTB02 .. +34C = 400 bytes = dword[100]); no ROM constant points inside
   0x80ceb2-0x80d03d and no decompile use: J90280.05 leftovers. Same for 0x80d060/0x80d062 (ESRWPE dword, 'governor_pid_*').
## Lead: 0x80d06c 'governor_rpm_target_adjusted' = primary pulse period timeout reload (ESMXTM01 >> 0..3 by speed; copied
   into main_lost_counter by the ch10 handlers) - sibling of pulse_period_timeout_backup 0x80d06e.
## Lead: 0x80d0cd 'cam_sync_status' is e2m 11A8 +1 CRSYSS CRANK_SYNC_STATE.
## Lead (functions): 0x1a1e0 -> main-period twin of 0x1a298; 0x1af32 -> cam index pulse handler; 0x1a6e8 -> PMM mode 2 handler.

## FINAL (round 97 R4 investigator): 61 batch rows named (proposals.tsv), 53 skipped, 13 extras (extras.tsv)
- CI spelled cylinder_identification (rounds 85 / 96 plates use it 3 times; round 90 cam_sync_state comment says cam index once).
- 0x80ccf4 / 0x80ccf6 extras: current_engine_rpm_filtered is the unfiltered one-cam-revolution speed (ESCMES), engine_rpm_primary
  is ENGRPM FILTERED_ENGINE_SPEED of whichever source -> engine_speed / filtered_engine_speed (CM848 engine_speed_state fields).
- CM848 reused names keep its vss initialism (backup_speed_period_sum_between_vss_pulses ...): a both-firmware lead.
- 0x8086f2 PPCVTB word[210] and 0x80ceae pulse_period_table_backup dword[100] cover old rows that must be deleted first
  (0x8086f6..0x80888a; 58 rows 0x80cf78..0x80d03c).
- names: see proposals.tsv / extras.tsv in this folder.
