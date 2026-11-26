# R4 judge notes (CM550 engine position / speed globals)

Started 2026-11-25. No earlier judge run (directory was empty).

## Method
- abs_refs.py for every batch row + every extra row (abs_refs_judge.txt)
- e2m_block_addresses.py --firmware cm550 --address for each
- disassembly spot checks with m68k.py
- uniqueness grep against frozen global_variables.csv / function_renames.csv

## Findings
- uniqueness: all 75 proposed names free in frozen CM550 global/function CSVs; no duplicates among proposals; no param/local named engine_speed etc.
- 0x807839 FLCYCUPZ: 0x34b8c-0x34ba2 next_injected_cylinder(0x80a221) = (index + it) % 6 + 1. byte. CONFIRMED.
- 0x80783a FLTAPSOF / 0x80783e FLTAPSTT: 0x34834-0x34852 start = cyl angle[0x80a23a] + FLTACYOF + FLTAPSOF + 0x80a236 + 0x100; end = start + FLTAPSTT; start -> ch3 param4 0xffff38, end -> param5 0xffff3a; both add.l; e2m 4 bytes S. i32 both. 0x807840 = low word of FLTAPSTT, must be deleted (not only skipped).
- 0x807f4e ESNOTTCU: (angle>>16) % (it + 2) in both ch3 functions; byte reads in ch0 set-ups.
- ch10 set-up 0x1999c: 0x80d078 = lea -4(a3,n*4) (n=ESPECM01), fill a2<=0x80d078; 0x80d080 = table start; if 0x807ec8 > 1 write ptr 0x80cd08 = table + 4*ESPECY01 else = 0x80d080; 0x80d070 = ESPECM01*ESIITB01; 0x80ccf8 = ESPECY01*ESIITB01; vector 0x808f04 = 0x19acc.
- ch10 mode 0 handler 0x19acc: period 0x80d04a <- 0xffffa8; sum 0x80d070 -= *wp += new; *wp=new; wrap at 0x80d078; ESACGR 0x80d03e += period (overflow guard), ESCTGR 0x80d046 +1 to 0xffff; ESPECK01 added to 0x80cd00 (guard); average 0x80ccf8 -= *(0x80d080) += new; 0x80d080 advanced/wrapped; tooth counter 0x80ccea +1 / clr after ESPECM01-1; 0x80a9f4 += 1 at end. Mode 1 0x19e90 same minus tooth counter / CI logic.
- 0x19f82 (no row) = ch0 handler config 1 (vector 0x808edc from 0x19dfa); 0x1a6e8 = ch0 handler config 2 (vector 0x808edc from 0x1a512). 0x80d293 = 0xfffffc>>8, 0x80d292 = byte 0xfffffd. 0/0xff -> save ch10 param1 low byte to 0x80d294, reload with ESPSCURS 0x807f51, status 0x806004 bit 0x2000 if ESPSCURS - saved != 1. 0x80-0x8f with crank sync state 1: speed 0x80ccf6 > ESFXSNTD -> state 2 else 0.
- phase checks 0x1a1e0 (main period, gate 0x80aa16, backup lost counter 0x80cd12==0 -> ESMNIPER=1) / 0x1a298 (backup period, gate 0x80aa18, main lost counter 0x80cd10==0 -> ESBUIPER=1): same body otherwise. diff 0x80d298 = 0x80d054 - 0x80d052 when 0x80ccea==0x80ccec; > ESPLPHTD (ble signed) -> pos count +1 to ESMXPHCU then ESBUIPER=0, neg count=0, ESMNIPER=1; < ESNGPHTD (bge) -> neg count +1 to limit then ESMNIPER=0, pos=0, ESBUIPER=1; band -> both 0, both flags 1.
  ERROR in investigator comment 0x80d296: says 'the backup-period check sets it when the backup sensor is lost' -> it is the MAIN-period check 0x1a1e0 (0x1a206 tst.w 0x80cd12 / 0x1a20e move.b #1). Amend comment.
- CI handler 0x1af32: CMSNTTCU 0x80d2be <- byte 0xffff1b; 0x80d2c2 <- byte 0x807f9d; wide = CMSNCU01 0x807f98, narrow = CMSNCU02 0x807f9a; tooth counter 0x80ccea vs EGPSCU01/EGPICU02 -> states 0x80d0cc/0x80d0cd = 1, CKTTCUER -1; mismatch -> states 2, counter forced (move.w abs,abs), CKTTCUER +1 to 0x807f9e then 0x806000 bit 0x1 + 0x806004 bit 0x800; neither width -> CMSNCUER 0x80d2c0 +1 to 0x807f9f then 0x806000 bit 0x1.
- ch1 set-ups 0x1ae22/0x1b1ea/0x1b39a: 0x80d07c = table_backup + 4(ESPECM02-1), fill; 0x80d084 = table_backup; write ptr 0x80cd0c = +4*ESPECY02 if 0x807eca > 1 else = 0x80d084; 0x80d074 = ESPECM02*ESIITB02; 0x80ccfc = ESPECY02*ESIITB02. 0x1b39a clr.b 0x80d2cc + clr.l 0x80d2d2.
- 0x1b30a: ESSXSNEN bit 3 -> 0x80d04e <- move.l 0xffff18, table_backup[0] and average backup <- it.
- sync detect 0x1025c: 0x80d078 / 0x80d07c = previous entry when write ptr at table start; stored 0x8001b4 as ring end.
- pointer type 'dword *' parses (ImportAnalysis: base type + PointerDataType); word[210] / dword[100] parse.
- block 100C base 0x80ccf2: ESPSTB01 0x80cd1e..0x80cead (100 dwords), ESPSTB02 0x80ceae..0x80d03d (100 dwords). Primary table: no row inside but base. Backup table: 58 rows inside, 0 ROM 4-byte values inside (any alignment) except base, 0 cpp uses.
- PPCVTB 0x8086f2: x 0x8086b0 count 20 (10 pts 0..9), y 0x8086c6 count 42 (21 pts 0..36000 = 4500 rpm), grid rows of 10 equal words to 0x808895, PPSEAVTB 0x808896; RAM 0x8038c2 = {x 0x8086b0, y 0x8086c6, z 0x8086f2}. 55 rows inside besides base, none referenced (ROM consts only 0x36a94/0x36a98 = base pair). word[210] correct.
- unreachable rows: based_refs sweep (positive control OK on 0x80d296/0x80d2bf) finds 0 accesses in 0x801500-0x801900, 0x803380-0x803447, 0x8036e3-0x803780, 0x809a00-0x809c45, and every 'no access' batch address; no RAM/ext pointer into them; dumps zero in 0x801500-0x801900, 0x803380-0x803447, 0x809a00-0x809c45.
- calculateEngineSpeed 0x171be: main speed 0x80cd06 = ESCUCF01/0x80ccf8 while 0x80cd10 counts; at 0 clear + jsr 0x17150. backup 0x80cd04 = ESCUCF02/0x80ccfc if ESSXSNEN&0xc; at 0 clear + jsr 0x1839a. external 0x80cd16 only cleared. lost durations: main 0x80d05a (MNLSMXEL, 0x806004 bit 0x1000), backup 0x80d05c (ESSXSNEN&0xc gate, BKLSMXEL, bit 0x400), external 0x80d05e (EXLSMXEL, 0x806024 mask 0x4), crank sync 0x80d058 (state 0x80d0cd==1 clear; ==0 & speed>ESFXSNTD count to CRLSMXEL 0x807ede, bit 0x4000; ==0 low speed clear). speed compared = 0x80ccf6.
  source select: 0 -> ESAVES=main, ENGRPM=EMA, ESCMES(0x80ccf4)=ESCUCF03/0x80d070; 1 -> backup, ESCMES=ESCUCF03/0x80d074; 2 -> external, ESCMES=ENGRPM. reload bands by ESCMES.
- 0x80ccf4 users: acceleration, cylinder balance, freeze frame, trip, histogram -> 'engine_speed' (CM848 field name for ESCMES) acceptable per reuse directive.
- mode 2 set-up 0x1a350: ch10 param1 = (ESCMTT 0x807ec8 / ESPECM01) << 8 (0x1a402-0x1a412). ch0 mode 2 set-up seeds 0xfffffc = 0xc000.
- 0x1a6e8: 0xc0 -> both sync states 0 else 2.
- mode 3 processor 0x1a95a: tooth counter cleared first period after sync pulse; counts up to ESPECM01; sync pulse checked against ESPECM01 periods.
- crank: 0x177c2 crank_adjusted_initial_rpm = min(0x80d0b2 + CKINRPAJ, 0x807efc); fuel = min(0x80d0a6 + CKINFRAJ, 0x807ef8) in states 2/6/7. 0x17d6a JUMP_START ramps (0x807f0e to 0x803f40; 0x807f0c to 0x808004); clear both only on REENTRY(7) -> STOPPED(1) (0x17dee-0x17dfc). 0x17eba RUNNING->REENTRY with crank exit timer > 0x807f10 loads 0x807f12/0x807f14.
- ERROR 0x807f51 comment: 'status word 0 bit 0x2000' but code is 0x806004 (= status word 2).
- MISSED REUSE: 0x80deda ESVSAVPE = CM848 1008 +4 Average_EPS_Sample_Period 'EPS period between VSS interrupts' = drivetrain_ratio_engine_period_average (0x40b712), same block+offset+length. Free in CM550. -> AMEND.
- CM848 blocks: only 105E / 117D / 1008 exist among the batch blocks; 117D +2C/+2E have no CM848 rows.
- 0x80847a ESPSPGIN / 0x80847c ESPSPGSL: cm550_calculateEnginePositionPhaseLag 0x26e8e: pulse_0 lag 0x80db66 = (it + ESAVES*ESPSPGSL/16 + ESCWAJ)/16. Investigator OMITTED them. Names engine_position_pulse_0_phase_lag_intercept / _slope free.
- e2m coverage (records incl. multi-byte B): 0x809b02/08/0a inside CBDFTTB4 (823D +0x806, B, 600 bytes, 0x8099ee-0x809c45) -> investigator's 'no e2m record' wrong for these 3 (skip still right); 0x807840 inside FLTAPSTT; the other skipped rows: no record.
- naming: repository writes calibration limits as *_count_limit (CM848 cam_sync_error_count_limit, crank_sync_error_count_limit, cam_crank_mismatch_count_limit) -> AMEND 0x807f5c to engine_position_sensor_out_of_phase_count_limit (free).
- comment errors to fix: 0x80d296 (main-period check, not backup-period), 0x807f51 (status word 2 not 0), 0x807ee4 / 0x80d05e ('bit 4' = mask 0x4), 0x807f9a / 0x80d2bf ('bit 1' = mask 0x1), 0x807ee2 ('bits 2-3 are set' = either, mask 0xc), 0x80d0be / 0x80d0bc (clear only on REENTRY -> STOPPED), extras: 'Not in the row file (no row)' becomes false once applied -> clean comments for all 13 extras; 0x80d03e / 0x80d046 comments must carry round 95's code description.
- 0x80ccf4 engine_speed: CONFIRM name (reuse directive + e2m ENGINE_SPEED + CM848 field), drop the 'more specific alternative' sentence.
- comment sweep needed: engine_rpm_primary cited in 33 gv / 9 fr / 1 enum / 1 struct; current_engine_rpm_filtered 13 gv / 1 fr.

## Final verdict plan (76 entries)
- CONFIRMED unchanged: 51 batch rows (all other proposals).
- AMENDED comment only: 0x807ee2, 0x807ee4, 0x807f51, 0x807f9a, 0x80d05e, 0x80d0be, 0x80d296, 0x80d2bf; all 13 extras (clean comments; 0x80d03e / 0x80d046 merge round 95 text).
- AMENDED name: 0x807f5c -> engine_position_sensor_out_of_phase_count_limit; 0x80deda -> drivetrain_ratio_engine_period_average.
- Added (omitted by investigator): 0x80847a engine_position_pulse_0_phase_lag_intercept, 0x80847c engine_position_pulse_0_phase_lag_slope (word).
- skipped[]: all stay skipped; 0x809b0x reason corrected (CBDFTTB4 bytes); deletions with parent types: 0x807840, 0x80d076/7a/7e/82/86/8e, 55 PPCVTB cells, 58 rows inside the backup table.
