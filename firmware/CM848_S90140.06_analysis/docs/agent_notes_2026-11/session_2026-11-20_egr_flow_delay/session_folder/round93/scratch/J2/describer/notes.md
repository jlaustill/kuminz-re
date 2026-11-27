# J2 describer notes (round 93) - second run

An earlier run of this task left notes.txt / draft_roles.md / build_answer.py / final_answer.json in this folder.
This run re-read every function (decompilation + m68k.py disassembly) and re-checked each claim it reuses.
Entries marked RECHECKED were verified again in this run with the evidence quoted.

## The "ROM table" 0x1b4da-0x1b4e9 (RECHECKED)
- It is CODE: 0x1b4d8 = jsr 0x212b2 / jsr 0x23244 / jsr 0x22070 / jsr 0x230ee / jsr 0x21edc / jsr 0x21070 /
  jsr 0x420bc / rts (opcode 4EB9 + 4-byte target; the hits 0x1b4da / 0x1b4e0 / 0x1b4e6 are JSR operands).
- callers.py: 20 x bsr.w to 0x1b4d8 (0x1b960 ... 0x1be4c) and 20 x bsr.w to 0x1b504, all inside
  executiveFrameInterruptHandler (0x1b876-0x1bf53): phase 0 -> 0x1b4d8, phase 1 -> 0x1b504, ... (even / odd).
- 0x1b504 = jsr 0x2142c / jsr 0x1ff38 / jsr 0x23920 / rts.
- Rows 0x1b4ea (cm550_diagnosticMonitoringCoordinator) and 0x1b4f6 (cm550_boostPressureControlInit) are labels in
  the middle of 0x1b4d8's JSR chain; two rows share the name vp44_evenPhaseSchedulerTaskSet (0x1b4d8, 0x1b62a).
- CM848 cm848_phase_group_a_processing (0xb7b4): dispatch / control timeouts / track sessions / transport sessions /
  input supervision / switch+request inputs / end retarder shift assist / periodic transmit queues / ...

## Functions (all RECHECKED against disassembly)
- 0x1fdc0: bit 0x80 of 0x803c98 (j1922_monitor_enable); mode 1 -> ++0x804164, ++0x804170, hour meter -> 0x804172,
  0x804166; mode 2 -> 0x804176 / 0x804178; mode 3 -> 0x80416a / 0x80416c. Callers: 0x231fc (0x231da), 0x234c2
  (0x23244, only when 0x801984 == 0). Neighbour 0x1fd6c (bit 0x100; called from 0x1b6d6) clears the 8 cells when
  0x804166 + 0x808190 < key_on_hour_meter; 0x1fd8e has no caller (mid-function label). CM848: no reader of bits 7/8.
- 0x1ff38: bit 8 of 0x803caa; 0x80aa12 & 4 -> walk 0x80096e (count 0x800a9a, tick 0x800a9c); & 8 -> 0x800a36
  (count 0x800a9b, tick 0x800a9e). Entry +0 PGN, +2 period, +4 next tick, +6 builder. 0x1fe84 (no row; reached by
  movea.l #0x1fe84,a4 at 0x28b8a in mc68k_initializeJ1939Datalink) fills them: limit 20 / 10, period = ms / 10.
  RAM dump: count 17 / 2, PGN 65265 every 10, 61444 every 2, 61443 every 5 ...; queue 1: 61440, 65249.
  CM848 0x538d3c adds (j1939_dm13_broadcast_enable_flags & 4 / 8) -> counterpart.
- 0x212b2: budget 250 counts of 0xfff404; ring 18-byte records 0x80d72e..0x80d884 (20 records), read ptr 0x80d9ba,
  write ptr 0x80d9b6, full flag 0x80d9bf; key = bytes 1-2 with the PS rule; skip list 0x80d9e0[4] ended by 0xFE;
  table 0x800ab0 (6-byte entries, count 0x800b10); full flag 1 -> clear, sr mask, 0xFB to 0xffd800 + 16 n for
  n = transmit object + 1 .. last receive object (mc68k_queueCanCs4ReceiveMessage wrote 0xF7 / 0xFD there when the
  ring filled). CM848 0x538ef4: budget 9 of TBLr >> 7, DM13 hook, TouCAN IMASK -> counterpart; mc68k_ prefix.
- 0x2142c: bit 0x1000; 0x80d9e4 == 2; 0x80d9e6 == 1; 0x80da50 == 1; 0x80da4e == 1; 0x80ded2 >= 0x8089a8 ->
  clr 0x80d9e4, 125 -> 0x80d9ee, clr 0x80da8e, clr 0x80da90. CM848 0x50aec0 same tests / stores -> twin.
  Both firmwares read e2m 1050 +0 FSDSFL (user fueling) and JCEBSILM.
- 0x21642: lookup 0x10e16(id, &address); nonzero -> 8; else 0x2148a(request, address + offset, length).
- 0x2167e (0x44): id = bytes 1-2, length = byte 3, offset 0. 0x216c6 (0x45): id bytes 1-2, length bytes 3-6,
  offset 0. 0x21714 (0x47): id, offset bytes 3-4, length byte 5. 0x21778 (0x49): id, offset 3-6, length 7-10.
- 0x21872: a2 = 0x2ee62; (0x44, 0x2167e) (0x45, 0x216c6) (0x4b, 0x217de) (0x4d, 0x21826) (0x47, 0x21714)
  (0x49, 0x21778). Called at 0x28e4a (mc68k_initializeJ1939Datalink). CM848 0x50b4d8 same six in the same order.
- 0x21920: byte 0x80bcf6: bit 4 -> 0x40 and 0x01; bit 1 -> 0x10; bit 6 -> 0x04. Callers 0x322f2 (store 0x801f64,
  j1939HandlePgn65226Dm1ActiveDtc) and 0x3243c (store 0x80266a, cm550_previousDtcListBuilder).
  e2m 000E +28: bit 4 MLLP / LCEGPNLP, bit 1 LCSPLPEA / LCSPEGLP, bit 6 LCWNLPEA / LCDGLP.
- 0x21f4e: index 0x804232 (post-increment, >= 5 -> 0); dest 0x80417e + 24 x index; source 0x8041f8 (arg 0) or
  0x804212; 12 words. Callers: 5 x bsr in 0x22070.
- 0x21fac: arg 0: 0x80422a = 1; 0x80422e = 0x80da4e; record 0x8041f8: +0 = 0, +1 = byte 0x80da70, +2 = 0x80da4e,
  +4 = 1, +6 = 0x80da50, +8..+0xe = 0, +0x10 = hour meter, +0x14 = 0. Else: 0x80422c, 0x804230 = 0x80d9e6, record
  0x804212 with +0 = 1, +1 = byte 0x80d9e9, 0x80d9e6, 0x80d9e4.
- 0x22070: bit 0x800; engine: copies 0x800b12 / 0x800b16 / 0x800b18; close: clr 0x80422a, duration, file(0);
  open / append (count < 5, else shift) / source change: duration, file, open; other network after network 1:
  clr flag, file (no duration). Retarder: 0x800b14 / 0x800b19, no network test. CM848 0x50bff4 identical order
  (disassembly 0x50c0a4: flag clear, duration, branch to file) -> twin.
- 0x231da: 0x801982 = 0x80da50; clr 0x80da50, 0x80da4e, 0x80da60; jsr 0x1fdc0(0x801982); clr 0x80da80, 0x80da7e.
  5 call sites in 0x23244. CM848 calls cm848_runTsc1LostManagement at these points -> counterpart.
- 0x23216: clr 0x80d9e4, 0x80d9e6; 125 -> 0x80d9ee; clr 0x80da84, 0x80da82, 0x80da8e, 0x80da90. 3 call sites in
  0x23244. CM848 0x27118 same 7 stores in the same order -> twin.
- 0x23244: flags d2 (new / changed request), d3 (timeout this pass), d4 (J1939 timeout), d5 (other link timeout).
  High idle override (0x801988 vs 0x80da54; 0x80da88 = 0x808184 + 1; 0x80da86; 0x80da98; 0x808188 + 1), 0x80da8c /
  0x80da58, 0x80da8a / 0x80da56, 0x80da8e, sensor type 0x803d4a 4 / 5: 0x80da92 / 0x80da6c, 0x80aa10 / 0x80aa08;
  type 4: 0x80da94 -> mask 0x100 of 0x806008 + 0x806048. Engine request unchanged: count down 0x80da80 / 0x80da7e;
  mode 1: timeout -> 0x231da, d3; time limit -> 0x238ac(network, source, 1), 0x231da; mode 2: same but the time
  limit needs 0x80da56 == 0; mode 3: timeout only. Changed: 0x80da7e = 0 / +6 + 1 / +0xa + 1 / 0 by mode; then
  0x801984 == 0 -> 0x1fdc0(0x801982). d3 -> d4 (network 1) or d5; else d2 -> 0x801992 = 1 (network 1) or
  0x801993 = 1. Copies 0x801982 / 84 / 86 / 88 / 8e / 90. Retarder (0x80198a / 0x80198c): unchanged: count down
  0x80da84 / 0x80da82; mode 2 timeout -> 0x23216, d4; time limit -> 0x238ec(byte 0x80d9e9), 0x23216; mode 3 timeout
  -> 0x23216, d4. Changed: mode 2 -> 0x80da82 = +0x10 + 1, 0x801992 = 1; else clr, mode 3 -> 0x801992 = 1.
  d5: 0x804266 < 0x8081fc - 1 (signed) -> ++, else mask 0x0008 in 0x80600e + 0x80604e, count = 0; clr 0x801993.
  else 0x801993 == 1: error bit clear or 0x806aca bit clear -> clr 0x801993; both set and 0x80604e bit clear ->
  clear the 0x80600e bit, 0x801993, 0x804266. d4: 0x804268 < 0x8081fc (unsigned) -> ++, else mask 0x0400 in
  0x80600a + 0x80604a, count = 0; clr 0x801992; else the same clear logic with 0x806ac6 / 0x80604a (no count clear).
  NOTE the masks: J1708 link = status word 7 mask 0x0008, J1939 link = word 5 mask 0x0400 (the e2m's JC39TMER is
  word 7 mask 0x01 - not the bit this ROM sets).
- 0x238ac: count 0x8019d0 < 5: entry 0x801994 + 8 n: +0 word network, +2 byte source, +4 word mode, +6 word =
  0x808188. 0x238ec: count 0x8019d1 < 5: entry 0x8019bc + 4 n: +0 byte source, +2 word = 0x808188.
  Siblings: 0x23820 find + reload (engine), 0x23870 (retarder), 0x23920 count down / drop (third call of the odd
  set), 0x239d2 remove (engine), 0x23a3c remove (retarder). abs_refs: the lists are referenced only in
  0x23820-0x23a8e; rows 0x801998 .. 0x8019b8 have no reference (fields of entries).

## e2m (RECHECKED with e2m_block_addresses.py --firmware cm550)
- 1101 +0 JC22CU 0x804164; +2 JC22TM 0x804166; +6 JC22LMCU 0x80416a; +8 JC22LMTM 0x80416c; +C JC22RPCU 0x804170;
  +E JC22RPTM 0x804172; +12 JC22TQCU 0x804176; +14 JC22TQTM 0x804178 (EEPROM 0x65a.. -> RAM 0x803b0a + offset).
- 10FD JCHSTB 0x80417c (type T: length word, data from 0x80417e); 10FE JCAEEG 0x8041f6; 10FF JCAERD 0x804210;
  1100 +0 JCEGCOSS 0x80422a; +2 JCRDCOSS 0x80422c; +4 JCEGCOSA 0x80422e; +6 JCRDCOSA 0x804230; +8 JCHSTBPO
  0x804232; 11C0 J39PDBLK 0x804264; 11C1 +0 JC17TMCU 0x804266; +2 JC39TMCU 0x804268.
- 10E8 +2 JCEGCOID 0x80da4e; +4 JCEGMD 0x80da50; +8 JCHII1OD 0x80da54; +A JCOG 0x80da56; +C JCPSDB 0x80da58;
  +14 JCRPGVSS 0x80da60; 10E6 +0 JCRDMD 0x80d9e4; +2 JCRDCOID 0x80d9e6; 10E5 +4 JCRDLM 0x80d9ee.
- 10E7 +4 JCEGOSTM 0x808182; +6 JCEGOSTL 0x808184; +A JCTMRCTM 0x808188; +C JCDRDITM 0x80818a; +E JCPSTM 0x80818c;
  +12 JC22CCTM 0x808190; +7E JCTMERLM 0x8081fc; 10FC +2 JCEBSILM 0x8089a8; 102E +0 JCBCFGLC 0x80aa12 (bit 0 JC87EN,
  1 JC22EN, 2 JCEGBCEA, 3 JCRDBCEA); 1180 +10 VSRSSNTY 0x803d4a; 1050 +0 FSDSFL 0x80ded2.
- RAM dump: 0x80417c = 0x0078, five records FE FE 00..; 0x8041f6 = 0x0018; 0x804210 = 0x0018; 0x80aa12 = 0x000d;
  0x8081fc = 100; 0x8089a8 = 15; 0x80d9e0 = FE FE FE FE.
- J90350.00.eeprom.bin equals the RAM dump at 0x803b0a for all 0x1000 bytes (ram.py --eeprom-compare), so the cells
  0x804164-0x804269 hold EEPROM content although they are outside the stated mirror range 0x803B0A-0x804155.

## ETC1 handler 0x2efd0 (RECHECKED, outside the batch; it loads the timers 0x23244 counts down)
- 0x80da98 == 0: byte 4 & 3 == 1 with mode 1 and device 1 -> 0x80da54 = 1, 0x80da86 = 0x808182 + 1; other than 3 ->
  clear 0x80da54 / 0x80da86 / 0x80da88. 0x80da98 != 0 -> 0x80da86 = 0x808188 + 1.
- byte 4 & 0xc == 4 -> 0x80da58 = 1, 0x80da8c = 0x80818c + 1; other than 0xc -> both 0.
- byte 0 & 0x30 == 0 and & 3 == 0 -> 0x80da56 = 1, 0x80da8a = 0x80818a + 1, 0x80da6a = 1; else both 0.

## Globals with no proof in the dumped ROM (not named)
- 0x80da90: four clr.w (0x21482, 0x2323c, 0x2fa30, 0x2fa8a), no read, no other store. Position = CM848
  retarder_tsc1_speed_control_flag.
- 0x80da92 / 0x80da6c / 0x80aa10 / 0x80aa08 / 0x80da94: only 0x23244 touches them (count down / clear); no loader
  below 0x40000. Positions = CM848 etc1_out_of_gear_data_timer / etc1_out_of_gear_data_valid_flag /
  etc2_gear_ratio_timeout / etc2_gear_ratio_valid_flag / etc1_output_shaft_speed_timer.

## Name checks
- check_names.py over names.txt: every proposed name is free in CM550; the CM848 hits are the same records.

## Exclusivity batch (abs_refs.py, this run) - after the advisor's review
- History / session records / flags 0x80417c-0x804232: only 0x21f4e / 0x21fac / 0x22070. The hit on 0x804202 at
  0x278e0 is a false one (move.b #0x80,(a2)+ followed by clr.b d2: the bytes 0080 4202 straddle two instructions).
- 0x800b12-0x800b19: only 0x22070. 0x801982-0x801993: only 0x231da / 0x23244 (0x80198c also as the list base minus
  one entry at 0x2393a in 0x23920; 0x8019b8 likewise at 0x2398e).
- Schedules 0x80096e / 0x800a36 / 0x800a9a-0x800a9e: only 0x1fe84 and 0x1ff38.
- J1922 cells 0x804164-0x804178 and 0x808190: only 0x1fd6c and 0x1fdc0.
- 0x80da7e: 0x2320a + the a2 base in 0x23244. 0x80da98: 0x232b0, 0x232e2, 0x2f024 (ETC1 handler).
- NEW: 0x80da8c is also loaded by the J1922 command handler 0x1f84e (row cm550_fuelDemandScaleFactorCalculator):
  message byte 0 == 2 and bit 7 -> 0x80da58 = 1, 0x80da8c = 0x80818c (no + 1); else both cleared.
- NEW: 0x808184 is also read at 0x33332 (buildPgn65251EngineConfiguration1Payload: / 10 -> byte +0x17).
- 0x80da60 (JCRPGVSS): 1 only in the mode 1 branch of processEngineTsc1Request (0x2f310) and of the J1922 handlers
  (0x1f654, 0x1fa22); 0 in the other branches and in 0x231da -> CM848 tsc1_speed_control_flag (same e2m record).
- 0x803d4a (VSRSSNTY, EEPROM 0x240, inside the mirror): three compares, all in 0x23244 ->
  vehicle_speed_sensor_type_cal.
- 0x80d9e0: 0x21346 (dispatcher) and 0x28bca (start-up fills 4 x 0xFE; 0x80d9de = 4 just before).
- 0x21920 callers re-read: DM1 builder stores at 0x801f64 (DTCs from 0x801f66; 0 when no active DTC), DM2 builder
  at 0x80266a (DTCs from 0x80266c).
- 0x21872 position: mc68k_initializeJ1939Datalink calls ... 0x21ef6, 0x226da, 0x22370, 0x21872, 0x11b36
  (registerJ1939DiagnosticHandlers), 0x200c6; CM848: ... MemoryReadServices, GetAddressByParameterIdService,
  MemoryWriteServices, registerJ1939DiagnosticHandlers, BroadcastAndNoOperationServices.
- Fault bits in 0x23244: J1708 link = 0x80600e mask 0x0008 (+ 0x80604e), J1939 link = 0x80600a mask 0x0400
  (+ 0x80604a); e2m JC39TMER = 1036 +E mask 0x01 is not what this ROM sets.

## Deliverable
- build_answer_v2.py -> final_answer_v2.json (81 roles: 14 functions, 3 helpers, 64 globals; 16 enum roles).
