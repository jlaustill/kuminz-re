# Q5 judge notes (CM848 0x3fdba4-0x3fdc38)
Started 2026-11-25. Judge dir was empty (no earlier run).
Inputs: investigator 48 globals + 3 cm848_functions; describer 45 roles.

## Boot side - verified by my own disassembly (2026-11-25)
- mpc555_initHardwareConfig 0x1454: mfspr 638, cmpwi 12336, blt 0x15ac skips 0x1478-0x15a8. Inside: stb 1 0x3fdba4 @1480; stw 0x28000000 0x3fdbaa @148c;
  stw 0x1e0000 0x3fdbae @1498; stw 0xc20..0x720 0x3fdbb2+0..28 @14a8-14e0; sth 1 0x3fdbd2 @14ec; stb 8 0x3fdba5 @14f8; sth 100 0x3fdba8 @1504;
  stw 0x28000000 0x3fdbd6 @150c; stw 0x4f0000 x4 / 0xf0000 x4 0x3fdbde+0..28 @151c-153c; stw 0xc20..0x720 0x3fdbfe+0..28 @1548-1564;
  sth 4 4 4 4 20 20 20 48000 0x3fdc1e+0..14 @1574-159c; sth 8 0x3fdbd4 @15a8. Always: sth 0 0x3fdba6 @15e0, stw 9800000 0x3fdc2e @15f0,
  stw 200 0x3fdc32 @15fc, sth 3 0x3fdc36 @1608, sth 50 0x3fdc38 @1614; stw 0x1338 -> 0x302886 @1690.
- mpc555_cmfEraseBlocks 0x49d0: byte 0x3fdba4 flag (==0/!=0 only); byte 0x3fdba5 = erase step count (loop r16 < it; retry pass r16 = count-1);
  0x3fdba6 total (sth 0 @4a28, += step pulses @4db4); 0x3fdba8 total limit (bge exits @4bcc/@4c28/@4cb8); 0x3fdbaa base (lwz @4a30);
  0x3fdbae bits (lwz via r28 at every CMFCTL write); 0x3fdbb2 step 0 CMFTST (lwz @4ac0/@4b54), lwzx 0x3fdbb2+step*4 @4c5c/@4c7c (step!=0);
  0x3fdbd2 word = pulses per erase step (lhz @4c98 r20, @4d94 r19 after the swap). End: CMFTST=0 if flag, CMFCTL=..|4.
- RestoreNormalMode 0x4320: flag ? CMFTST_A/B = [0x3fdbfe] : CMFCTL_A/B = [0x3fdbd6]|[0x3fdbde]; CMFMCR_A/B = 0x85000000.
- SelectBlockAndStartSequence 0x43a4: same flag branch, then block_select(0x3fec90) = [0x3fdbd6] | 0x8000>>n; other CMFCTL = base|[0x3fdbde]; active = select|[0x3fdbde] then |2.
- LoadProgramPage 0x4500: 32 halfwords from 0x3fec3a; step 0x3fec8f=0; 0x3fdbda = select|[0x3fdbde]|3 (stw @455c); count 0x3fec98 = 0.
- ApplyHighVoltagePulse 0x4570: flag -> *test = lwzx 0x3fdbfe+step*4 @45a0; *ctl = lwz 0x3fdbda; count++; if old>=lhzx 0x3fdc1e+step*2 @45e8:
  if lhz 0x3fdbd4 -1 <= step return 0 else step++, count=0; 0x3fdbda = select | lwzx 0x3fdbde+step*4 | 3 @4648; return 1.
- EndHighVoltagePulse 0x46dc: *ctl = select | [0x3fdbde]; flag -> *test = 0.
- flashEraseChip 0x11b4: AMD erase seq; poll limit lwz 0x3fdc2e @1240; retry (r21-1) < lhz 0x3fdc36 @126c; r21 never set (unaff_r21).
- flashWriteWord 0x12a8: unlock-bypass (0x20) once, 0xa0, poll limit lwz 0x3fdc32 @1318.
- flashWriteBlock 0x1338: consecutive failures < lhz 0x3fdc38 (@139c zero test, @13f0 bound).
- flashPollUntilReady 0x1110: param_3 = max polls (SCI / paced serial / watchdog per poll), DQ5 twice = fail.

## Application side - my scan (scan_judge.py, flow + linear, keep / clobber across bl): scan_keep.txt / scan_clobber.txt
- App direct (constant EA) reads in 0x3fdba4-0x3fdc39: 0x3fdba4 (0x2408c PGN65241, 0x512158 brake pair), 0x3fdba8 (0x3be34 A/C),
  0x3fdbb4 (0x2404c PGN65241), 0x3fdbb6 (0x511ba8 park/neutral), 0x3fdbce-0x3fdbd1 (12 functions), 0x3fdbfe (0x4f0f0), 0x3fdc00 (0x4f138, keep-only).
  App bases (X-form): 0x3fdb8e, 0x3fdbce, 0x3fdbd2, 0x3fdbdc. No app store in the range. No range pointer passed as an argument
  (0x533c8 r5 / 0x4f124 r6: callees 0x37580 / 0x4ef24 never read them; r6 kept across the leaf calls). Matches both agents exactly.
- The decompile renders 0x3fdc00 as pwVar1[0x12] (pointer kept across the calls), so a 0x3fdc00 row may not render in the app.
- cm848_applicationMain -> cm848_initEepromDriverAndLoadMirror: load length 0x1a40 from EEPROM 0 -> 0x3fd482-0x3feec1 (covers range), then 0x8e8.
- mpc555_hardwareInitialization: cm848_clearRamRegions, then mpc555_systemInitialization only if strap pins high or ecm_status != CALIBRATION_VALID.
- Dump: RAM == EEPROM over 0x3fdb8e-0x3fdc7c and the ring 0x3fdc3a-0x3fec39; values match every comment (switch lines, outputs, active-low bytes).
- PGN 65241 (j1939 db): SPN 701 #01 at 1.7 (0xc0) = switch 19; SPN 702 #02 at 1.5 (0x30) = switch 11. Comments right.
- switch_input_state_t / logical_output_request_bits_16_to_23_t confirm switch 11 brake ... 31 unwired, output 17 overdrive / 18 TCC.
- cm848_runFlashProgramStateMachine: step 2 -> RestoreNormalMode; step 4 Select+Load+Apply; step 1 verify -> Apply again. Plate claims OK.
- e2m_block_addresses.py --address: no record in 0x3fdb8e-0x3fdc7b; 1069 +0 Powerdown_Memory_Save_Start at 0x3fdc7c (EEPROM 0x7fa).
- cm848_dataTransferBufferWrite: ring (&DAT_003fdc3a)[index], index wraps at 0x1000 -> 0x3fdc3a-0x3fec39 (lead, outside range).
- Periodic mirror reload: cm848_startEepromBlockRead also from cm848_runEvery10FramesTaskSetPhase4 (load length 0x8e8 after start-up).
- Name uniqueness: every proposed new name is absent from all frozen CSVs (global/arrays/function/struct/enum/local).
- Mentions of old names elsewhere: only the plates of 0x4f0dc (qadc_queue_timing_config) and 0x4570 (cmf_pulses_per_step), plus
  0x4320's plate citing 0x3fdba4 as a "test-step count"; the 0x3fdbd2 comment cites cmf_control_base / cmf_control_pulse_value (replaced).
- raw_scan.py (every lis-0x40 displacement in both images, any base): 79 hits, all inside the functions above; the only extra,
  0x51dbe8 addi, is lis r11,0x52 -> 0x51dc1c (flash2 code pointer). No r2 / r13 small-data base is ever set (r2 hits are data).

## Verdicts (decided)
- Investigator's split beats the describer's merged dwords: 0x3fdbb2 word cmf_erase_test_register_step_values + new 0x3fdbb4
  switch_input_19_hardware_line_cal; 0x3fdbfe word logical_output_17_line_cal + new 0x3fdc00 logical_output_18_line_cal.
  Rule: one name per address; the app reads 0x3fdbb4 / 0x3fdbfe / 0x3fdc00 directly, never 0x3fdbb2. Precedent: 0x3fdbda word
  rendered _cmf_control_pulse_value in the kernel. (0x3fdc00 renders pwVar1[0x12] in the app - documentary row, harmless.)
- 0x3fdbd2 dword -> word + new 0x3fdbd4 cmf_program_step_count: right (kernel lhz/sth there; app only lbzx from 0x3fdbd2).
- Arrays dword[8] 0x3fdbde (0x3fdbde-0x3fdbfd) and word[8] 0x3fdc1e (-0x3fdc2d): no app-read row inside; 14 deletes OK.
- Names: all unique, rule-compliant; program_* pairs with the cmf_erase_* rows; flash2_* matches flash2_command_register etc.
- No _cal on boot-only rows (firmware/CLAUDE.md: 78 boot-named rows in the mirror are accepted MISSING); _cal on the 4 app rows.
- Comment amendments: 0x3fdba4 (End / erase-end write CMFTST = 0; Restore / Select write CMFTST instead of CMFCTL),
  0x3fdbaa (first two CMFCTL writes have no block bits), 0x3fdbd6 (block bit is within the module: block - 8 for B),
  plate 0x4570 ("Otherwise" misread: after an advance it also sets the next value and returns 1).
- Plates 0x4320 / 0x4f0dc correct as proposed.
