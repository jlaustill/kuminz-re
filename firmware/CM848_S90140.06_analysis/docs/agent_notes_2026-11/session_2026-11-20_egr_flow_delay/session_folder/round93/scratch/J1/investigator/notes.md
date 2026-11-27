# J1 investigator notes (round 93) - CM550 J1939 multiplexed input / override layer 0x201d6-0x211f4

(An earlier cut-off run left only cm550_*.asm / cm848_*.asm / find_callers.py and no notes. Everything below is from this run.)

## Skeleton (from the decompile, to be proven in asm)
CM550 address order == CM848 0x509d98-0x50ae5c address order:
- 201d6 clear bit in 0x800aa0  <-> 509d98 cm848_clearJ1939InputDataErrorBit
- 20210 clear bit in 0x800aa8  <-> 509dd8 cm848_clearJ1939PedalInputTimeoutBit
- 2024a clear bit in 0x800aa4  <-> 509e18 cm848_clearJ1939InputTimeoutBit
- 20284 any 0x800aa0           <-> 509e58 cm848_anyJ1939InputDataErrorActive
- 202a0 any 0x800aa8           <-> 509e98 cm848_anyJ1939PedalInputTimeoutActive
- 202bc any 0x800aa4           <-> 509ed8 cm848_anyJ1939InputTimeoutActive
- 202d8 set bit 0x800aa0 (setBitInArray) <-> 509f18 cm848_setJ1939InputDataErrorBit
- 20310 set bit 0x800aa8       <-> 509f54 cm848_setJ1939PedalInputTimeoutBit
- 20348 set bit 0x800aa4       <-> 509f90 cm848_setJ1939InputTimeoutBit
- 20380 retarder selection (input 5) <-> 509fcc cm848_processJ1939EngineRetarderSelection
- 2041c fan request (input 0)  <-> 50a0cc cm848_processJ1939EngineFanRequestedSpeed
- 204b0 cm550_outputControlState1Handler (input 6 idle switch) <-> 50a1b4 cm848_processJ1939AcceleratorLowIdleSwitch
- 205c4 local idle switch fallback <-> 50a2cc cm848_updateIdleSwitchesFromLocalInputs
- 206a8 copy status bit -> switch <-> 50a4a0 cm848_copyStatusBitToDatalinkSwitch
- 20784 remote throttle (CM550 only?)
- 20890 per descriptor entry   <-> 50a57c cm848_evaluateJ1939InputSignalFault
- 20c98 pedal position (input 7) <-> 50a700 cm848_processJ1939AcceleratorPedalPosition
- 20e14 idle switch pair       <-> 50a9d4 cm848_processJ1939AcceleratorIdleSwitchPair
- 20fac wet tank pressure (input 9; CM550 only?)
- 21070 switch + request task  <-> 50aba8 cm848_processJ1939SwitchAndRequestInputs
- 21146 accelerator task       <-> 50ad1c cm848_processJ1939AcceleratorInputs
- 211f4 ?                      <-> 50ae5c cm848_initJ1939InputProcessing ?

## Verified findings

### The nine bit helpers = TWINS of CM848 0x509d98-0x509f90 (asm compared instruction by instruction)
- CM550 arrays: 0x800aa0 (+0), 0x800aa4 (+4), 0x800aa8 (+8); every access is a 32-bit and.l / or.l / tst.l with index = bit >> 5 scaled by 4 and mask 1 << (bit & 31). The three 'any' functions loop for d1 == 0 only (addq.w #1,d1; tst.w d1; beq) = ONE dword each.
- CM848 arrays: 0x3fbd5a (+0) j1939_input_data_error_bitmap, 0x3fbd5e (+4) j1939_input_timeout_bitmap, 0x3fbd62 (+8) j1939_pedal_input_timeout_bitmap (lis 64; addi -17062 = 0x3fbd5a; an earlier note here said 0x40bd5a - wrong); lwz/stw, index = bit >> 5, mask 1 << (bit % 32); the 'any' loops run while index <= 0 = one dword (cmpwi r5,0; ble).
- Same order in both: clear(+0) clear(+8) clear(+4) any(+0) any(+8) any(+4) set(+0) set(+8) set(+4):
  201d6<->509d98, 20210<->509dd8, 2024a<->509e18, 20284<->509e58, 202a0<->509e98, 202bc<->509ed8, 202d8<->509f18, 20310<->509f54, 20348<->509f90.
- Usage (CM550): 0x20348 (set +4) is called exactly where a j1939_input_signal_timeouts slot is 0 (203d4, 2046a, 20524, 207fe, ...); 0x202d8 (set +0) where the received value is 'not available' (0xfb-0xfd / 0xff for a byte, 3 for a 2-bit switch); 0x20310 (set +8) only with inputs 6 (204b0), 7 (20c98) and 1 (20784 remote throttle) together with the +4 bit; 0x202a0 (any +8) feeds byte 0x80d70e only (21146).
- abs_refs: 0x800aa0 / aa4 / aa8 are referenced by these nine functions only.
- setBitInArray (0x202d8) is not generic: it ORs into 0x800aa0 only -> rename.

### 0x211f4
- No reference of any kind in the dumped ROM (find_callers.py: no abs long, no bsr/bcc, no pc-relative). Body 0x211f4-0x21270 (link/unlk; a switch through the table at 0x2122c is why the decompiler shows 5 lines).
- Steps: local = dword 0x807d5e; switch number 8 -> byte index 1 -> 0x800aaf = byte 2 of the dword (0x807d60 = bits 8-15); 0x800aae = 0xff; 0x806000 &= ~1 (interrupts masked); 0x80d70d = 0.
- cm848_initJ1939InputProcessing (0x50ae5c, called once from the start-up list after cm848_loadDefaultJ1939NamesAndSourceAddresses): previous state = 0xff, timer = 100, clears a fault bit, clears the unavailable flag, sets the monitor inhibit flag. Same slot (right after the accelerator task), shared steps: previous state 0xff + fault bit clear + unavailable flag clear. COUNTERPART.

### e2m 12F7 (same block, same mnemonics in v64t6_s.e2m and CM848's CHR e2m) - CM550 base 0x80d70c, CM848 base 0x40aaa6
- +0 MXACDXER 'APS ERROR FLAG FOR THROTTLE INDICATING BAD DATA. NOT LOGGED' 0x80d70c = CM848 0x40aaa6 j1939_accelerator_position_error_fallback_flag
- +1 MXIVCFER 'IVS PARAMETER NOT PROPERLY CONFIGURED' 0x80d70d = CM848 0x40aaa7 j1939_accelerator_low_idle_switch_unavailable_flag
- +2 MXACTMER 'PGN TIMEOUT ERROR FLAG FOR APS/IVS/REMOTE THROTTLE' 0x80d70e = CM848 0x40aaa8 j1939_pedal_input_timeout_active_flag
- +1A ADEBLVPZ 0x80d726 = CM848 0x40aac0 j1939_engine_retarder_selection_source_priority (byte)
- +1B ADMNFMPZ 0x80d727 = CM848 0x40aac1 j1939_engine_fan_request_source_priority (byte)
- +1C ADUVEBLV 0x80d728 = CM848 0x40aac2 j1939_engine_retarder_selection_percent (word)
- +1E ADUVMNFM 0x80d72a = CM848 0x40aac4 j1939_engine_fan_requested_speed (word)
- +20 MXLPRWTH 0x80d72c = CM848 0x40aac6 idle_check_accelerator_pedal_raw (word)
- CM848 only: +22 JCMXRNTR run timer, +24 JCIHMXFU inhibit flag (0x40aaca j1939_input_monitor_inhibit_flag): CM550 has no such gate anywhere in 0x201d6-0x21270.

### Fault bits
- Every fault set / clear in the family writes bit 0 of 0x806000 (and latches bit 0 of 0x806040): 0x20826 / 0x20872 (remote throttle 0xfe / valid), 0x20db8 / 0x20d76 (pedal 0xfe / valid), 0x20f7a (idle switch error), 0x210e0 / 0x210fc + 0x21118 / 0x21136 (both summaries of 0x21070), 0x2117e / 0x2119a + 0x211b6 / 0x211d2 (both summaries of 0x21146), 0x21258 (clear in 0x211f4). Interrupts masked around each (move sr / ori #0x700).
- CM848 uses four different fault bits (fault 127 APS system error, 128 PGN timeout, 129 remote throttle data error, 130 configuration error); v64t6_s.e2m has MXPRTMER / MXRTDXER / MXCFER at 1036 +10 bits 0 / 1 / 2. J90350.00 writes fault 0 for all of them; the same bit 0 of 0x806000 is also written at 0x19be4 0x1a644 (the two TPU channel 10 speed interrupt handlers) and 0x1b05a 0x1b17a 0x1b1be (the duty cycle monitor). What fault 0 is has NOT been shown (an earlier note here called it a shared bucket - not proven). In 0x21070 / 0x21146 the timeout summary therefore overwrites the data-error summary (same bit).

### A/D channel override arrays (ECU parameter ID table: 12D0 0x80a6ca, 12D1 0x80a6fc, 12D2 0x80a72e, 12D3 0x80a760 - 50 bytes apart = 25 words each; 25 channels 0-24, config 0x806ae2 + 24 x n, block 101B at 0x806d3a)
- 0x20c98 (channel 10 sampled throttle): enable word 5 bit 10; priority 0x80a6de = 12D0 + 2 x 10; value 0x80a742 = 12D2 + 2 x 10; default 0x806bd4 = config[10] + 2.
- 0x20784 (channel 11 remote throttle): enable word 18 bit 12 + word 14 bit 3; priority 0x80a6e0 = 12D0 + 2 x 11; value 0x80a744 = 12D2 + 2 x 11; default 0x806bec = config[11] + 2.
- 0x20fac (wet tank pressure): enable word 20 bit 9; priority 0x80a6fc = 12D0 + 2 x 25; value 0x80a760 = 12D2 + 2 x 25; default 0x806d3c = 0x806ae2 + 24 x 25 + 2. All three = index 25 of 25-element arrays = one past the end: they land on 12D1 +0 (raw priority of channel 0), 12D3 +0 (raw user value of channel 0) and 101B +2 (the FIRST breakpoint of the intake manifold temperature linearization table: 0x806d3a is the table length word 50, 0x806d3c is X[0] = 0). Value scale: raw x 9282 / 100 = (5 kPa per bit) in psi x 128 = an engineering value like the other final override values (oil pressure is psi / 128), not A/D counts. Round 92's word 20 row: other ISB e2m files name bit 9 AD25OD 'A/D CHANNEL 25 OVERRIDE'. So the function is the J1939 feed of A/D channel 25, a channel this build does not have.

### Descriptor table 0x20108 (ROM bytes read): 17 x {byte* signal, byte slot, 0, dword switch}
- slots / switches: (10,72) (4,9) (2,54) (16,11) (15,10) (17,3) (18,1) (19,2) (21,14) (20,13) (12,60) (13,56) (14,58) (11,20) (1,19) (22,15) (3,54). CM848 0x53a278 same pointers order and slots, switches 31 26 31 11 15 31 31 31 31 31 3 31 31 19 31 31 31.
- 0x201b2-0x201d5: a second table, 6 x {byte slot, 0, dword switch}: (2,54) (16,11) (15,10) (17,3) (18,1) (19,2). No reference in the dumped ROM (lead only).
- Index 54 (0x36) is used by entries 2 and 16 and by three of the five 0x206a8 calls; CM848 uses 31 the same way - what input 54 is has NOT been shown (an earlier note here called it the unassigned index - not proven).

### AD25 records (63c5.e2m, 64c6, 74c0, 74c5, 74c6) confirm channel 25
- AD25FTCS 1003 +258 'A/D DIGITAL FILTER CONSTANT CHANNEL 25' (+0x258 = 24 x 25), AD25GLDF 1003 +25A 'CHANNEL 25 GLOBAL DEFAULT' (= 0x806ae2 + 0x25a = 0x806d3c, the word 0x20fac reads), AD25OD 106B +2A mask 0x200 'A/D CHANNEL 25 OVERRIDE' (= flags word 20 bit 9, the bit 0x20fac tests), AD25RWOD 106B +30 mask 0x200.
- J90350.00 RAM 0x806d3a = [50, 0, 30, 31, 34, ... 1023] = the length word + 25 breakpoints of block 101B (ADIMTPXA); so 0x806d3c is X[0] = 0 here, not a channel 25 default: this build has 25 channels and the wet tank code runs off the end of three arrays.

### Call graph (both firmwares)
- CM550 0x21070 <- task set 0x1b4d8 (every 2 frames = 10 ms; the same set runs cm550_tickJ1939InputSupervision just before it); 0x21146 <- task set 0x1b714 (every 10 frames = 50 ms). CM848: cm848_processJ1939SwitchAndRequestInputs <- cm848_phase_group_a_processing right after cm848_tickJ1939InputSupervision; cm848_processJ1939AcceleratorInputs <- cm848_periodicTaskGroup18_calibration6.
- CM848 helper callers (decompile grep): clearDataError <- evaluate, idle pair, low idle, fan, retarder; clearPedalTimeout <- idle pair, low idle; clearTimeout <- the same five; anyDataError / anyTimeout <- both tasks; anyPedalTimeout <- accelerator task; setDataError <- evaluate, idle pair, low idle, pedal position, fan, retarder; setPedalTimeout <- low idle, pedal position; setTimeout <- evaluate, low idle, pedal position, fan, retarder. CM550's callers are the counterparts of exactly these plus the two CM550-only processors 0x20784 / 0x20fac.
- CM848 has NO reader of j1939_received_remote_accelerator_pedal_position (0x40aabc) or j1939_received_wet_tank_pressure (0x40aaba) (xref_addr.py: 1 store each, 0 reads) -> 0x20784 and 0x20fac are standalone.
- 0x211f4: no caller in the dumped ROM; cm550_initIoControlRegister (0x2481e) is in the same position (no reference). RAM dump: 0x800aae = 0x00 and 0x800aaf = 0x00, where 0x211f4 would leave 0xff and 0xf1 (0x807d60 = 0xf1); nothing else writes them while the J1939 pedal is off -> it had not run on the dumped ECU.

### Decisions (functions)
- TWINS (unprefixed, both rows change): 201d6 clearJ1939InputDataErrorBit / 20210 clearJ1939PedalInputTimeoutBit / 2024a clearJ1939InputTimeoutBit / 20284 anyJ1939InputDataErrorActive / 202a0 anyJ1939PedalInputTimeoutActive / 202bc anyJ1939InputTimeoutActive / 202d8 setJ1939InputDataErrorBit (was setBitInArray) / 20310 setJ1939PedalInputTimeoutBit / 20348 setJ1939InputTimeoutBit.
- COUNTERPARTS (CM848 adds the DM13 flag 0x40adda and / or the monitor inhibit flag 0x40aaca gates, uses helper calls for the switch write, or other enable bits): 20380 cm550_processJ1939EngineRetarderSelection; 2041c cm550_processJ1939EngineFanRequestedSpeed; 204b0 cm550_processJ1939AcceleratorLowIdleSwitch (was cm550_outputControlState1Handler); 205c4 mc68k_updateIdleSwitchesFromLocalInputs (reads the QADC result register 0xfff2b0 + 2 x index directly; CM848 also has the armed flag); 206a8 cm550_copyOutputBitToSwitchOverrideValue (cm848_copyStatusBitToDatalinkSwitch; same logic incl. the priority[status bit] quirk; CM848 writes through the IfPriority helpers); 20890 cm550_processJ1939SwitchInput (cm848_evaluateJ1939InputSignalFault); 20c98 cm550_processJ1939AcceleratorPedalPosition; 20e14 cm550_processJ1939AcceleratorIdleSwitchPair; 21070 cm550_processJ1939SwitchAndRequestInputs (CM848 adds the multiplex enable bit and the start delay); 21146 cm550_processJ1939AcceleratorInputs; 211f4 cm550_initializeJ1939InputProcessing.
- STANDALONE: 20784 cm550_processJ1939RemoteAcceleratorPedalPosition; 20fac cm550_processJ1939WetTankPressure.
- Leads for CM848 (not in my output's scope): cm848_evaluateJ1939InputSignalFault under-describes (it also writes the switch state) -> cm848_processJ1939SwitchInput; cm848_initJ1939InputProcessing -> cm848_initializeJ1939InputProcessing; cm848_copyStatusBitToDatalinkSwitch: the 'status bit' is a logical output request bit.

### Switch I/O arrays (CM550)
- 0x80bd4a = e2m 12A8, 80 bytes (next block 0x80bd9a): byte priority per logical input; indexed by 0x206a8 (d2 / d3) and 0x20890 (table switch, up to 72 = 0x80bd92). CM848 12A8 -> 0x40c058 switch_input_source_priority byte[32]. 56 description-named 'undefined' rows sit inside 0x80bd4b-0x80bd98 (0x80bd8c-0x80bd98 are old wrong names: fuel_demand_percentage_current ... speed_difference_interp_result_4, no reference anywhere).
- 0x807d6a = e2m 12FC, 12 bytes = dword[3]: default state bits, indexed dword-wise (and.l (0,a0,d.w*4), index switch >> 5, bit switch & 31) at 0x209d6 / 0x20a8a / 0x20b62 and as move.l + btst #7 / #8 at 0x20552 / 0x20582 / 0x20f2a / 0x20f4e. Row 0x807d6e sits inside.
- 0x807d5e = e2m 1234, 12 bytes = dword[3]: inversion masks; mc68k_sampleAndDebounceDiscreteInputs XORs the three sampled dwords with 0x807d5e / 0x807d62 / 0x807d66 (0x15070 / 0x1508e / 0x150ac) and mc68k_ioDriverStrobeHandler uses the same three (0x15bfe-0x15c34); 0x211f4 copies byte 2 (bits 8-15) to 0x800aaf. Rows 0x807d60 / 62 / 64 / 66 (engine_rpm_overspeed_exit_threshold, engine_overspeed_counter_limit, engine_rpm_idle_threshold, protection_state_config_table) are old names inside it.
- 0x80bcec.. = raw input image (0x15024: move.b (-1,a6) -> 0x80bcec = inputs 0-7, (-2,a6) -> 0x80bced = inputs 8-15, ...), stored before the inversion XOR; 0x205c4 reads 0x80bced bit 0 (input 8 = not idle switch; e2m 000E +1F DSRWNTSW) XOR 0x800aaf bit 0.
- 0x80bcd8.. = user supplied (override) values, byte per 8 inputs (000E +A..): 0x80bcd8 bit 7 = idle switch (input 7), 0x80bcd9 bit 0 = not idle switch (input 8).
- 0x80bcf6.. = output image (000E +28..): 0x206a8 reads bit (output & 7) of byte (output >> 3).
- Enable bits: bit (input + 0xd0) of the word array at 0x803c94 = words 13-17 (the 10-byte DSSWUO record).

### 0x808158 = e2m 12FE +0 MXMOPZ 'PRIORITY GIVEN WHICH MUXED PARAMETERS WILL USE FOR THE PRIORITY' (word)
- = CM848 j1939_input_source_priority (0x5c340, ROM constant). 12FE +2 ADDFEBLV (0x80815a) = CM848 0x5c342 j1939_engine_retarder_selection_default_percent; 12FE +4 ADDFMNFM (0x80815c) = CM848 0x5c344 j1939_engine_fan_requested_speed_default.
- 0x808159 is the LOW BYTE of that word (move.b (0x1,a5),(0x7,a2) at 0x20512 with a5 = 0x808158; move.b (0x808159).l at 0x20958) - not a separate record. Current names 'j1939_source_address_of_commanding_device' / 'j1939_switch_override_source_address' are wrong.

### Decisions (globals) - full text in draft_output.json (the final answer is built from it)
- CM848 names for the same records: 0x800aa0 j1939_input_data_error_bitmap / 0x800aa4 j1939_input_timeout_bitmap / 0x800aa8 j1939_pedal_input_timeout_bitmap (dword each); 0x800aac accelerator_idle_switch_debounce_timer (short); 0x800aae accelerator_idle_switch_previous_state (byte); 0x808158 j1939_input_source_priority (word; 0x808159 row goes); 0x80815a j1939_engine_retarder_selection_default_percent; 0x80815c j1939_engine_fan_requested_speed_default; 0x80d70c j1939_accelerator_position_error_fallback_flag; 0x80d70d j1939_accelerator_low_idle_switch_unavailable_flag; 0x80d70e j1939_pedal_input_timeout_active_flag; 0x80d726 j1939_engine_retarder_selection_source_priority; 0x80d727 j1939_engine_fan_request_source_priority; 0x80d728 j1939_engine_retarder_selection_percent; 0x80d72a j1939_engine_fan_requested_speed; 0x80d72c idle_check_accelerator_pedal_raw; 0x80bd4a switch_input_source_priority byte[80]; 0x807d6a j1939_switch_input_default_state_bits dword[3].
- CM550-only: 0x800aaf switch_9_to_16_polarity_bits_snapshot; 0x807d5e switch_input_polarity_bits dword[3]; 0x80bcd8 switch_1_to_8_override_values; 0x80bced switch_9_to_16_raw_values (RAM dump 0xff, NOT 0x09 - that was the status byte +3); 0x80a6de sampled_throttle_override_priority; 0x80a6e0 remote_throttle_override_priority; 0x80a6fc intake_manifold_temperature_raw_override_priority (medium: named by its record 12D1 +0; the wet tank code only aliases it).
- Correction: A/D channel and percent outputs are written right after the priority claim; only the switch override values have the extra priority == 0 test.
- RAM dump: all family state is 0 (0x800aa0-0x800aaf, 12F7, 12A8, 12D0-12D3, 12FE); enables 0x803c9e = 0, 0x803cae = 0, 0x803cb0 = 0, 0x803cbc = 0, 0x803cd6 = 0, 0x803cc6 = 0x0180 (bits 3 and 15 clear), 0x803cb8 = 0x303a (bit 12 set).
