# Q5 investigator notes (CM848 0x3fdba4-0x3fdc38, time-shared boot kernel RAM)

## Dump fact
- cm848_ram.bin (base 0x3fa000) == cm848_eeprom.bin (RAM = 0x3fd482 + offset) byte for byte over 0x3fdb8e-0x3fdc7c
  (dump_compare.py). So at run time the range holds EEPROM 0x70c-0x7fa, not the kernel's CMF values
  (kernel fill would leave 01 08 at 0x3fdba4, 0x0c20 dwords at 0x3fdbb2 etc).

## Boot fill mpc555_initHardwareConfig 0x1454 (only when IMMR>>16 > 0x302f, else the CMF block is not written)
- 0x3fdba4 stb 1 (0x1480) | 0x3fdba5 stb 8 (0x14f8) | 0x3fdba8 sth 100 (0x1504)
- 0x3fdbaa stw 0x28000000 (0x148c) | 0x3fdbae stw 0x1e0000 (0x1498)
- 0x3fdbb2 8 x stw 0xc20 0xd20 0xe20 0xf20 0x420 0x520 0x620 0x720 (0x14a8-0x14e0, r9 base)
- 0x3fdbd2 sth 1 (0x14ec) | 0x3fdbd4 sth 8 (0x15a8)
- 0x3fdbd6 stw 0x28000000 (0x150c)
- 0x3fdbde 8 x stw 0x4f0000 x4 then 0xf0000 x4 (0x151c-0x153c, r29 base)
- 0x3fdbfe 8 x stw 0xc20..0x720 (0x1548-0x1564)
- 0x3fdc1e 8 x sth 4 4 4 4 20 20 20 48000 (0x1574-0x159c, r31 base; 14(r31)=0x3fdc2c=48000)
- unconditional: 0x3fdba6 sth 0 (0x15e0) 0x3fdc2e stw 9800000 (0x15f0) 0x3fdc32 stw 200 (0x15fc) 0x3fdc36 sth 3 (0x1608) 0x3fdc38 sth 50 (0x1614)

## Application EEPROM load (covers the range)
- cm848_applicationMain (0x544c4) -> cm848_initEepromDriverAndLoadMirror (0x4cb64): eeprom_mirror_load_length = 0x1a40, reads EEPROM 0x0-0x1a3f
  into 0x3fd482.. (cm848_startEepromBlockRead / cm848_onEepromBlockRead, 30 words per read); afterwards load length = 0x8e8 so the
  periodic reload (cm848_runEvery10FramesTaskSetPhase4) keeps rewriting EEPROM 0x0-0x8e7 = RAM 0x3fd482-0x3fdd69 while ram_refresh_enable.
  0x3fdba4-0x3fdc39 = EEPROM 0x722-0x7b7: inside both. => app reads them as EEPROM values (_cal OK for app names).

## Application tables over the range (all indexed over every entry)
- switch_input_hardware_line_cal 0x3fdb8e word[32] (0x3fdb8e-0x3fdbcd): cm848_scanAndDebounceSwitchInputs loops 0..31 (lhzx 0x4ec48),
  cm848_readSwitchHardwareInput (lhzx 0x4eae8), cm848_checkDiscreteOutputReadBack (lhzx 0x537ca0).
  Direct app reads in range: [11] 0x3fdba4 (lhz 22(r5) 0x2408c PGN65241; lhz 22(r30) 0x512158 brake pair), [13] 0x3fdba8 (lhz abs 0x3be34
  cm848_updateAirConditioningSwitchFromPci), [19] 0x3fdbb4 (lhz 38(r5) 0x2404c PGN65241 - renders qadc_control_word_cal._2_2_),
  [20] 0x3fdbb6 (lhz abs 0x511ba8 cm848_updateParkNeutralFlagAndTsc1Activity).
- switch_input_datalink_source_bits_cal 0x3fdbce byte[4]: many app users (base + bytes 1/2/3).
- logical_output_line_active_low_bits_cal 0x3fdbd2 byte[10] (outputs 0-79): lbzx in set/clear/apply (0x4efb4 0x4f090 0x4f218).
- logical_output_line_cal 0x3fdbdc word[80] (0x3fdbdc-0x3fdc7b): cm848_applyLogicalOutputRequests loops 0..79 (lhzx 0x4f1e0), set/clear
  (lhzx), cm848_refreshOutputPortsAndReadback (lhzx 0x52eea0), cm848_checkDiscreteOutputReadBack (lhzx 0x537cb8).
  Direct app reads in range: [17] 0x3fdbfe (lhz 34(r6) 0x4f0f0, renders qadc_queue_timing_config._0_2_), [18] 0x3fdc00 (pwVar1[0x12] 0x4f0f4?).

## Boot external flash2 (AMD-style command set at 0x500000) routines
- cm848_flashEraseChip 0x11b4: aa/55/80/aa/55/10 to 0x500aaa/0x500554, cm848_flashPollUntilReady(0xffff, 0x500000, lwz 0(r26)=0x3fdc2e @0x1240);
  retry while (attempt-1) < lhz 0(r25)=0x3fdc36 @0x126c.
- cm848_flashWriteWord 0x12a8: 0xa0 program, poll limit lwz 0x3fdc32 @0x1318.
- cm848_flashWriteBlock 0x1338: per-word consecutive-failure limit lhz 0x3fdc38 @0x139c / @0x13f0.
- cm848_flashPollUntilReady 0x1110: param 3 = maximum poll iterations (each services SCI + watchdog); DQ5 (0x20) twice = fail.

## When the boot owns the block
- mpc555_hardwareInitialization 0x2694: cm848_clearRamRegions (0x3f9800-0x3fffd0 = 0) then mpc555_systemInitialization (the boot service loop,
  which calls mpc555_initHardwareConfig at start and after each cm848_runBootKernelLoop) ONLY when boot_mode_strap_pins_high or
  ecm_status != CALIBRATION_VALID; otherwise it jumps to the application. So the CMF values live only in the boot service / reflash loop;
  a normal start loads the EEPROM mirror over them. Kernel functions are called only from the boot (no app caller).
- The CMF block (all but 0x3fdba6 / 0x3fdc2e-0x3fdc39) is written only when IMMR >> 16 >= 0x3030 (mfspr 638, cmpwi 12336 @0x1470).

## Scan method + results (scan_range.py / scan_range_keep.py / raw_imm_scan.py)
- function-aware base tracking (lis/addi/ori/mr/add) both banks; the call-clobber version and keep-across-calls version differ only by
  0x3fdc00 @0x4f138 (cm848_mirrorTransmission... keeps r6 over bl). raw immediate scan: no extra absolute hits.
- App direct (fixed address) reads in 0x3fdba4-0x3fdc39: 0x3fdba4 0x3fdba8 0x3fdbb4 0x3fdbb6 0x3fdbce-0x3fdbd1 0x3fdbfe 0x3fdc00; app table
  bases: 0x3fdbce 0x3fdbd2 0x3fdbdc. No app store anywhere in the range. Everything else = app reads by index only.

## Program path (kernel) confirmed from disasm
- ApplyHighVoltagePulse 0x4570: CMFTST(active) = lwzx 0x3fdbfe + step*4 @0x45a0 (only when byte 0x3fdba4 != 0); CMFCTL(active) = lwz 0x3fdbda;
  count++; if old count >= lhzx 0x3fdc1e + step*2 @0x45e8: if lhz 0x3fdbd4 - 1 <= step return 0 else step++ count=0; next value =
  block_select | lwzx 0x3fdbde + step*4 @0x463c | 3 -> stw 0x3fdbda @0x4648.
- LoadProgramPage 0x4500: 32 words from 0x3fec3a to the page; step = 0; stw 0x3fdbda = block_select | lwz 0x3fdbde | 3 (@0x455c); count = 0.
- RestoreNormalMode / SelectBlock / EndHighVoltagePulse use step 0 entries only (0x3fdbfe, 0x3fdbde) + 0x3fdbd6 base.
## Erase path confirmed (mpc555_cmfEraseBlocks 0x49d0)
- 0x3fdba4 byte = CMFTST used flag; 0x3fdba5 byte = erase step count (r16 < it; repeat pass restarts at count-1); 0x3fdba6 total;
  0x3fdba8 = total pulse limit; 0x3fdbaa base; 0x3fdbae bits ORed into each CMFCTL; 0x3fdbb2 + step*4 = CMFTST (lwz @0x4ac0 step 0,
  lwzx @0x4c5c / @0x4c7c steps 1-7); 0x3fdbd2 word = pulses per step (lhz @0x4c98 / @0x4d94).
- CMF register map: CMFMCR_A 0x2fc800 CMFTST_A 0x2fc804 CMFCTL_A 0x2fc808 (B +0x40). CMFCTL |4 PE, |2 SES, |1 EHV, HVS = 0x80000000 polled.

## App meanings (switch_input_state_t / logical_output_request_bits_16_to_23_t)
- switch 11 brake (0x3fdba4, line 147), 12 exhaust brake (0x3fdba6, 149), 13 A/C (0x3fdba8, 0), 14 low oil (0x3fdbaa, 150), 19 remote PTO
  (0x3fdbb4, 148), 20 park/neutral (0x3fdbb6, 13), 21 O/D off (18), 22 transmission relay feedback (154), 23 overdrive feedback (153),
  24 TCC feedback (156), 25 cruise vent feedback (152), 27 cruise vacuum feedback (155), 28 cruise servo supply feedback (22).
- output 17 overdrive solenoid (0x3fdbfe, line 153), 18 converter clutch solenoid (0x3fdc00, 156), 62 (0x3fdc58, 158), 63 (0x3fdc5a, 159).
- No e2m (CHR 11.45) record over 0x3fdb8e-0x3fdc7b; the next record Powerdown_Memory_Save_Start is at 0x3fdc7c (= end of the 80-word table).

## PGN 65241 (j1939 db): byte 1 bits 7-8 Aux I/O #01 SPN 701 = switch 19 line/state; bits 5-6 #02 SPN 702 = switch 11; bits 3-4 #03 SPN 703 = switch 2; bits 1-2 #04 = 3 (n/a)
## Parameter ID table (flash2 0x53be38, 1441 dumped records): no entry over EEPROM 0x70c-0x7f9 (next: block 1069 at 0x7fa); table incomplete -> not proof
## Boot 4 KB reflash ring buffer DAT_003fdc3a: cm848_dataTransferBufferWrite index wraps at 0x1000 -> 0x3fdc3a-0x3fec39 (also time-shared: logical_output_line_cal[47..79] incl. 62/63)

## DECISIONS (rule: a row whose address the app reads directly, or that is an app table base, = app name; a row the app reaches only by index from another base = boot name + both roles in comment)
- keep app: 0x3fdba4 switch_input_11_hardware_line_cal word | 0x3fdba8 switch_input_13_hardware_line_cal word | 0x3fdbce switch_input_datalink_source_bits_cal byte[4] (arrays.csv) | 0x3fdbdc logical_output_line_cal word
- 0x3fdbd2 logical_output_line_active_low_bits_cal dword -> word (frees 0x3fdbd4) ; NEW 0x3fdbd4 cmf_program_step_count word
- NEW app rows: 0x3fdbb4 switch_input_19_hardware_line_cal | 0x3fdc00 logical_output_18_line_cal ; renamed to app: 0x3fdbb6 switch_input_20_hardware_line_cal word | 0x3fdbfe logical_output_17_line_cal word
- boot keep: 0x3fdba6 cmf_erase_pulse_total | 0x3fdbaa cmf_erase_control_base | 0x3fdbae cmf_erase_control_bits
- boot rename: 0x3fdbb2 cmf_erase_test_register_step_values (word: 0x3fdbb4 must stay free) | 0x3fdbba..ca cmf_erase_step_2..6_test_register_value dword
  | 0x3fdbd6 cmf_program_control_base | 0x3fdbda cmf_program_pulse_control_value (word) | 0x3fdbde cmf_program_control_step_bits dword[8] (delete 0x3fdbe2-0x3fdbfa)
  | 0x3fdc02..1a cmf_program_step_1..7_test_register_value dword | 0x3fdc1e cmf_program_step_pulse_limits word[8] (delete 0x3fdc20-0x3fdc2c; 0x3fdc2c = 48000 = step 7 limit, not a QADC rate)
  | 0x3fdc2e flash2_chip_erase_poll_limit | 0x3fdc32 flash2_word_program_poll_limit | 0x3fdc36 flash2_chip_erase_retry_limit | 0x3fdc38 flash2_word_program_retry_limit (no _cal: boot constants)
- plate comments naming old rows: mpc555_cmfApplyHighVoltagePulse (cmf_pulses_per_step), cm848_mirrorTransmissionSolenoidRequestsToOutputs62And63 (qadc_queue_timing_config._0_2_), mpc555_cmfRestoreNormalMode ("test-step count at 0x3fdba4" - it is a flag)
## LEADS (outside range)
- 0x3fdc5a no row: logical_output_63_line_cal (lhz 126(r6) @0x4f144, line 159); 0x3fdc58 comment "past the kernel's range" is wrong: it is inside the boot 4 KB ring 0x3fdc3a-0x3fec39
- program-path-only rows 0x3fec8f cmf_pulse_step_index / 0x3fec90 cmf_control_block_select / 0x3fec98 cmf_pulse_count could take "program" too
- cm848_flashEraseChip: retry counter r21 never initialized (unaff_r21) - attempts depend on the caller's r21
