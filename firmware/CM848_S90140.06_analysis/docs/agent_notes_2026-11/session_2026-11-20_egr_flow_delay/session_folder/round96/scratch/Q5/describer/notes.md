# Q5 describer notes (CM848 RAM 0x3fdba4-0x3fdc38)

## Ground facts
- App EEPROM load: cm848_initEepromDriverAndLoadMirror (0x4cb64, app) sets eeprom_mirror_base_pointer = &eeprom_mirror (0x3fd482),
  eeprom_mirror_load_length = 0x1a40 and loops cm848_startEepromBlockRead until loaded => RAM 0x3fd482-0x3feec1 = EEPROM 0x0-0x1a3f.
  So 0x3fdba4-0x3fdc38 = EEPROM 0x722-0x7b7 at run time: COVERED by the app load. App-side names there take _cal.
- App tables over the range (existing rows, verified by scan_range.py X-form hits):
  switch_input_hardware_line_cal 0x3fdb8e (32 words, base read lhzx by cm848_readSwitchHardwareInput 0x4eae8,
  cm848_scanAndDebounceSwitchInputs 0x4ec48, cm848_checkDiscreteOutputReadBack 0x537ca0);
  switch_input_datalink_source_bits_cal 0x3fdbce (4 bytes; lbzx by scanAndDebounce 0x4eb64, copyStatusBitToDatalinkSwitch 0x50a4c0,
  evaluateJ1939InputSignalFault 0x50a5d0); logical_output_line_active_low_bits_cal 0x3fdbd2 (10 bytes; lbzx by set/clearLogicalOutput,
  applyLogicalOutputRequests); logical_output_line_cal 0x3fdbdc (80 words; lhzx by set/clear/apply, refreshOutputPortsAndReadback 0x52ea0,
  checkDiscreteOutputReadBack 0x537cb8).
- scan: scan_range.py (base-tracking linear scan, ROM + flash2) -> scan_all.txt

## Boot side (verified from disassembly)
- mpc555_initHardwareConfig (0x1454; called by mpc555_systemInitialization 0x2504, boot ROM): mfspr IMMR (SPR 638);
  only if (IMMR >> 16) & 0xffff >= 0x3030 it fills 0x3fdba4-0x3fdc2d (else they stay unset; then erase limit 0 -> erase fails).
  Always: 0x3fdba6 = 0, 0x3fdc2e = 9800000, 0x3fdc32 = 200, 0x3fdc36 = 3, 0x3fdc38 = 50.
  Values: 3fdba4 b=1, 3fdba5 b=8, 3fdba8 h=100, 3fdbaa w=0x28000000, 3fdbae w=0x1e0000,
  3fdbb2..3fdbce 8 dwords = 0xc20 0xd20 0xe20 0xf20 0x420 0x520 0x620 0x720 (stw 0..28(r9), r9=0x3fdbb2),
  3fdbd2 h=1, 3fdbd4 h=8, 3fdbd6 w=0x28000000, 3fdbde..3fdbfa 8 dwords = 0x4f0000 x4 / 0xf0000 x4,
  3fdbfe..3fdc1a 8 dwords = same 0xc20..0x720, 3fdc1e..3fdc2c 8 halfwords = 4 4 4 4 20 20 20 48000.
- mpc555_cmfEraseBlocks (0x49d0): byte 0x3fdba4 = CMFTST-in-use flag (gates every CMFTST write); byte 0x3fdba5 = erase
  step count (loop bound; retry passes restart at step count-1 = the last step); 0x3fdba6 = erase pulse total (reset 0,
  += pulses of each step); 0x3fdba8 = erase pulse limit (loop ends when total >= it); 0x3fdbaa = erase CMFCTL base (ORed
  with the block mask: A = base | mask&0xff00, B = base | (mask&0xff)<<8); 0x3fdbae = erase CMFCTL bits (ORed into every
  CMFCTL write with |4 PE, |6 PE|SES, |7 PE|SES|EHV); 0x3fdbb2 dword[8] = erase CMFTST value per step (lwzx base 0x3fdbb2 +
  step*4 at 0x4c5c / 0x4c7c; step 0's value written before the interlock writes at 0x4ac0 / 0x4b54);
  0x3fdbd2 = erase pulses per step (inner loop bound at 0x4c98 / 0x4d94 via r19 = 0x3fdbd2).
  (scan_range.py's 0x4cb0 'r20 -> 0x3fdba8' / 0x4d94 'r19 -> 0x3fdbd2' are right after the mr r19,r20 / mr r20,r14 swap.)
- mpc555_cmfApplyHighVoltagePulse (0x4570): CMFTST = (0x3fdbfe dword[step]) if flag; CMFCTL = 0x3fdbda (pulse value);
  pulse count vs 0x3fdc1e word[step]; step count 0x3fdbd4 (step >= count-1 -> return 0); next pulse value =
  cmf_control_block_select | 0x3fdbde dword[step] | 3 (SES|EHV) -> stored to 0x3fdbda.
- mpc555_cmfRestoreNormalMode / mpc555_cmfSelectBlockAndStartSequence: flag ? CMFTST_A/B = 0x3fdbfe[0] : CMFCTL_A/B =
  0x3fdbd6 | 0x3fdbde[0]; Select: block select = 0x3fdbd6 | 0x8000 >> N; LoadProgramPage: 0x3fdbda = select | 0x3fdbde[0] | 3.
- Bank 2 chip (AMD command set at 0x500aaa / 0x500554): cm848_flashEraseChip (0x11b4) polls with limit dword 0x3fdc2e
  (9800000) and retries while counter < word 0x3fdc36 (3) - counter r21 never initialised (unaff_r21);
  cm848_flashWriteWord (0x12a8) polls each word program with limit dword 0x3fdc32 (200);
  cm848_flashWriteBlock (0x1338) gives up on a word after word 0x3fdc38 (50) consecutive failed writes (and skips writing
  when it is 0).

## App side (verified)
- Every word 0x3fdb8e-0x3fdbcd + byte 0x3fdbce-0x3fdbd1 is read each pass by cm848_scanAndDebounceSwitchInputs (loop 0..31),
  every byte 0x3fdbd2-0x3fdbdb + word 0x3fdbdc-0x3fdc7b by cm848_applyLogicalOutputRequests (loop 0..79) -> the app reads
  the WHOLE range, but only through the table bases (0x3fdb8e / 0x3fdbce / 0x3fdbd2 / 0x3fdbdc): those reads render the
  base name, never a row inside the table.
- Constant-offset (row-rendering) app reads inside 0x3fdba4-0x3fdc39 (scan_range.py + scan_range_keep_bl.py):
  0x3fdba4 word = switch 11 (brake) line: cm848_buildPgn65241AuxiliaryInputOutputStatus1Message lhz 22(r5) @0x2408c
     (0 -> SPN 702 bits 0x30 'not available'), cm848_monitorBrakeSwitchPairAgreement lhz 22(r30) @0x512158 (0 -> faults
     394/395 cleared, monitor off).
  0x3fdba8 word = switch 13 (A/C on/off) line: cm848_updateAirConditioningSwitchFromPci lhz -9304 @0x3be34 (0 -> switch 13
     from PCI message 10 (0x52) bit 7).
  0x3fdbb4 word (inside row 0x3fdbb2) = switch 19 (remote PTO) line: cm848_buildPgn65241 lhz 38(r5) @0x2404c (0 -> SPN 701
     'not available' 0xc0); renders qadc_control_word_cal._2_2_.
  0x3fdbb6 word (row 0x3fdbb6 high half) = switch 20 (park/neutral) line: cm848_updateParkNeutralFlagAndTsc1Activity
     lhz -9290 @0x511ba8 (without ETC2 gear: 0 -> flag from transmission_selected_gear, else from switch 20); renders
     qadc_control_word_b._0_2_.
  0x3fdbce-0x3fdbd1 bytes = switch_input_datalink_source_bits_cal (arrays.csv; 12 functions).
  0x3fdbfe word = logical output 17 (overdrive solenoid) line, 0x3fdc00 word = output 18 (converter clutch solenoid) line:
     cm848_mirrorTransmissionSolenoidRequestsToOutputs62And63 lhz 34(r6) @0x4f0f0 / lhz 36(r6) @0x4f138 (r6 kept across bl;
     the plain scan missed 0x4f138). 17 renders as qadc_queue_timing_config._0_2_, 18 as pwVar1[0x12].
- No 4-byte pointer into 0x3fdb80-0x3fdc80 anywhere in ROM / flash2; no &range-name passed as an argument; no e2m record
  resolves into 0x3fdb8e-0x3fdc7b (e2m_block_addresses.py --address).
- Dump (cm848_ram.bin base 0x3fa000) == cm848_eeprom.bin over 0x3fdb8e-0x3fdc7b: the run-time RAM holds the EEPROM
  values, not the kernel's (0x3fdba4 = 147, 0x3fdbb2 = 0, 0x3fdbb4 = 148, 0x3fdbb6 = 13, 0x3fdbfe = 153, 0x3fdc00 = 156).
- Order: mpc555_systemInitialization (boot ROM) calls mpc555_initHardwareConfig on every boot and after
  cm848_runBootKernelLoop; the app's cm848_applicationMain -> cm848_initEepromDriverAndLoadMirror reloads 0x3fd482-0x3feec1
  from EEPROM later, so neither side sees the other's values.

## Cross-checks
- scan_range_keep_bl.py (registers kept across bl): only adds 0x4f138 (0x3fdc00) and 0x4f144 (0x3fdc5a).
- raw_imm_scan.py (every D-form with imm 0xdb80-0xdc80, any base): 115 hits, only 0x51dbe8 not in the scan =
  lis r11,0x52 / addi -> 0x51dc1c (a flash2 code pointer), so nothing missed.

## Per-row verdicts (D = dual-use: a constant-offset app read lands in the row; B = boot-only: app reaches it only by
## table index through 0x3fdb8e / 0x3fdbd2 / 0x3fdbdc, so the row's own name never renders in app code)
- 3fdba4 D word keep switch_input_11_hardware_line_cal; boot byte0 = CMFTST in use flag (1), byte1 = erase step count (8)
- 3fdba6 B word keep cmf_erase_pulse_total (app: switch line [12] = 149)
- 3fdba8 D word keep switch_input_13_hardware_line_cal; boot = erase pulse limit (100)
- 3fdbaa B dword keep cmf_erase_control_base 0x28000000 (app lines [14] [15])
- 3fdbae B dword keep cmf_erase_control_bits 0x1e0000 (app lines [16] [17])
- 3fdbb2 D dword -> switch_input_18_and_19_hardware_lines_cal; boot erase CMFTST step 0 (0xc20) + table base
- 3fdbb6 D -> word switch_input_20_hardware_line_cal (or dword switch_input_20_and_21_hardware_lines_cal); boot step 1 0xd20
- 3fdbba..3fdbca B word->dword cmf_erase_step_2..6_test_register_value (0xe20 0xf20 0x420 0x520 0x620)
- 3fdbce D arrays byte[4] keep switch_input_datalink_source_bits_cal; boot erase step 7 (0x720) - comment lacks the boot role
- 3fdbd2 D dword keep logical_output_line_active_low_bits_cal; boot +0 = erase pulses per step (1), +2 = program step count (8)
- 3fdbd6 B dword cmf_control_base -> cmf_program_control_base (0x28000000; program path only)
- 3fdbda B word cmf_control_pulse_value (-> cmf_program_pulse_control_value); dword in boot, cannot widen over 0x3fdbdc
- 3fdbdc D word keep logical_output_line_cal; boot = low half of the pulse value dword
- 3fdbde B dword -> dword[8] cmf_program_step_control_bits (0x4f0000 x4, 0xf0000 x4); rows 3fdbe2..3fdbfa fold in
- 3fdbfe D dword -> logical_output_17_and_18_lines_cal; boot program CMFTST step 0 + table base
- 3fdc02..3fdc1a B dword cmf_program_step_1..7_test_register_value (0xd20 0xe20 0xf20 0x420 0x520 0x620 0x720)
- 3fdc1e B word -> word[8] cmf_program_pulses_per_step (4 4 4 4 20 20 20 48000); rows 3fdc20..3fdc2c fold in
- 3fdc2e B dword flash2_chip_erase_poll_limit (9800000); 3fdc32 B dword flash2_word_program_poll_limit (200)
- 3fdc36 B word flash2_chip_erase_retry_limit (3); 3fdc38 B word flash2_word_write_retry_limit (50)
- _cal: only on the D rows (app reads EEPROM 0x722-0x7b7 there); B rows are written by boot code constants -> no _cal.

## Extra facts used in the write-up
- App overlay names (structure_definitions.csv): switch 12 exhaust brake, 13 A/C on/off, 14 low oil, 15 clutch, 16/17 EGR/VGT
  driver feedback, 18 reserved, 19 remote PTO, 20 park/neutral, 21 overdrive off, 22 transmission relay feedback, 23 overdrive
  solenoid feedback, 24 converter clutch feedback, 25 cruise vent feedback, 26 throttle interlock, 27 cruise vacuum feedback,
  28 cruise servo supply feedback, 31 unwired. Outputs: 11 engine brake 1 (line 146), 16 transmission relay (154), 17 overdrive
  solenoid (153), 18 converter clutch solenoid (156), 19 cruise vent (152), 20 cruise vacuum (155), 21 cruise servo supply (21),
  27 (42), 38 A/C clutch (145), 43 / 44 intake air heaters (130 / 131).
- cm848_flashWriteBlock (0x1338) has no direct caller: mpc555_initHardwareConfig stores 0x1338 in
  eeprom_xfer_state.flash2_write_callback.
- IMMR gate caveat: when (IMMR >> 16) < 0x3030 nothing initialises 0x3fdba4-0x3fdc2d, so after a warm restart from the app
  the kernel would read the EEPROM line tables there (erase limit 0x3fdba8 = 0 -> mpc555_cmfEraseBlocks returns 0 at once).
- Final output: StructuredOutput roles[] (one per row, 45 incl. arrays.csv 0x3fdbce), no enums.
