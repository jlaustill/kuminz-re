# J1 describer notes (round 93) - CM550 J1939 multiplexed input layer 0x201d6-0x211f4

## Layout match CM550 <-> CM848 (same order of functions)
CM550 0x201d6 clr bit 0x800aa0  <-> 0x509d98 cm848_clearJ1939InputDataErrorBit (0x3fbd5a)
CM550 0x20210 clr bit 0x800aa8  <-> 0x509dd8 cm848_clearJ1939PedalInputTimeoutBit (0x3fbd62)
CM550 0x2024a clr bit 0x800aa4  <-> 0x509e18 cm848_clearJ1939InputTimeoutBit (0x3fbd5e)
CM550 0x20284 any 0x800aa0      <-> 0x509e58 cm848_anyJ1939InputDataErrorActive
CM550 0x202a0 any 0x800aa8      <-> 0x509e98 cm848_anyJ1939PedalInputTimeoutActive
CM550 0x202bc any 0x800aa4      <-> 0x509ed8 cm848_anyJ1939InputTimeoutActive
CM550 0x202d8 set 0x800aa0      <-> 0x509f18 cm848_setJ1939InputDataErrorBit
CM550 0x20310 set 0x800aa8      <-> 0x509f54 cm848_setJ1939PedalInputTimeoutBit
CM550 0x20348 set 0x800aa4      <-> 0x509f90 cm848_setJ1939InputTimeoutBit
CM550 0x20380 retarder (slot 5) <-> 0x509fcc cm848_processJ1939EngineRetarderSelection
CM550 0x2041c fan (slot 0)      <-> 0x50a0cc cm848_processJ1939EngineFanRequestedSpeed
CM550 0x204b0 low idle sw (6)   <-> 0x50a1b4 cm848_processJ1939AcceleratorLowIdleSwitch
CM550 0x205c4 local idle fallbk <-> 0x50a2cc cm848_updateIdleSwitchesFromLocalInputs
CM550 0x206a8 copy output bit   <-> 0x50a4a0 cm848_copyStatusBitToDatalinkSwitch
CM550 0x20784 remote accel (1)  <-> none
CM550 0x20890 descriptor entry  <-> 0x50a57c cm848_evaluateJ1939InputSignalFault
CM550 0x20c98 pedal pos (7)     <-> 0x50a700 cm848_processJ1939AcceleratorPedalPosition
CM550 0x20e14 idle sw pair      <-> 0x50a9d4 cm848_processJ1939AcceleratorIdleSwitchPair
CM550 0x20fac wet tank (9)      <-> none
CM550 0x21070 task A            <-> 0x50aba8 cm848_processJ1939SwitchAndRequestInputs
CM550 0x21146 task B            <-> 0x50ad1c cm848_processJ1939AcceleratorInputs
CM550 0x211f4 initialize        <-> 0x50ae5c cm848_initJ1939InputProcessing

bitmaps: +0 data error, +4 timeout, +8 pedal timeout; +0xc debounce timer; +0xe previous state (both firmwares)
CM848 helper order clear/any/set = (bd5a, bd62, bd5e) x3 ; CM550 = (aa0, aa8, aa4) x3  -> same order.

## RUN 2 (re-check of the above; started from the frozen cpp + a fresh disassembly, identical to fresh_*.txt)
- Layout map above RE-VERIFIED from the decompiled bodies of both firmwares (read every body, run 2).
- Disassembly files of run 2: run2_201d6_20420.txt run2_2041c_20890.txt run2_20890_20c98.txt run2_20c98_21280.txt
- The nine bit helpers: 0x201d6/0x20210/0x2024a clear bit N (and.l not-mask) of the long at 0x800aa0 / 0x800aa8 / 0x800aa4;
  0x20284/0x202a0/0x202bc return 1 when the long at 0x800aa0 / 0x800aa8 / 0x800aa4 is not 0 (loop bound = 1 long);
  0x202d8/0x20310/0x20348 set bit N (or.l) of 0x800aa0 / 0x800aa8 / 0x800aa4. Argument = word on the stack, low byte sign-extended.
- 0x808158: e2m 12FE +0 MXMOPZ 'PRIORITY GIVEN WHICH MUXED PARAMETERS WILL USE FOR THE PRIORITY' 0-255 -> a PRIORITY word, not a source address
  (current names j1939_source_address_of_commanding_device / j1939_switch_override_source_address at 0x808159 look wrong; to check with abs_refs).
- TODO (advisor): twin-vs-counterpart deltas per function; unique-name check.

### 0x20fac = A/D CHANNEL 25 (index one past this ROM's 25-channel tables) - PROVEN
- priority word 0x80a6fc = 0x80a6ca (12D0 base, channel 0) + 2*25 ; channel 10 = 0x80a6de, channel 11 = 0x80a6e0 (same base).
- value word 0x80a760 = analog_sensor_override_values 0x80a72e + 2*25 (channel 10 = 0x80a742, 11 = 0x80a744).
- default 0x806d3c = sensor config base 0x806ae2 + 24*25 + 2 (default_value); ch 10 = 0x806bd4, ch 11 = 0x806bec.
- RAM: config record 24 = 0x806d22 (ADOCSV); 0x806d3a is already e2m 101B +0 ADIMTPXA (IMT linearization x axis) -> the three index-25
  accesses ALIAS 12D1 +0 ADIMTPPR (raw priority[0]), 12D3 +0 ADIMTPUR (raw user value[0]) and linearization word [1].
- gate: move.w 0x803cbc & 0x200 = algorithm enable word 20 bit 9; five sibling e2m files (63c5 64c6 74c0 74c5 74c6) have
  106B +2A mask 0x200 AD25OD 'BIT 9 OF 0-15. A/D CHANNEL 25 OVERRIDE', 12D0 +32 ADPZ25 'PRIORITY OF CLIENT ... OVERRIDING A/D 25',
  12D2 +32 ADUV25 'A/D CHANNEL 25 OVERRIDDEN USER VALUE', 1003 +258/+25A AD25FTCS / AD25GLDF 'CHANNEL 25 GLOBAL DEFAULT'.
- scale: x*9282/100 (shift-add chain 9 -> 145 -> 4641 -> 9282, divu 100). 250 -> 23205.
  CORRECTED: e2m JCWTPRMU scale = 0.7252683 PSIA per bit (5 kPa); 0.7252683 x 128 = 92.83 -> the stored value is psi x 128.
  (my first reading '8 kPa/bit -> 1/80 psi' gives the same product 640 and was a coincidence; the e2m scale decides.)
- all five sibling e2m files (63c5 64c6 74c0 74c5 74c6) have AD25OD + ADPZ25 + ADUV25 + AD25GLDF + JCWTPRMU (checked by count).
- word 20 = 0 in the RAM dump -> inactive in this calibration.

### 0x808158 = the multiplexed input PRIORITY (not a source address) - PROVEN
- e2m 12FE +0 MXMOPZ 'PRIORITY GIVEN WHICH MUXED PARAMETERS WILL USE FOR THE PRIORITY' 0-255, both firmwares (CM848 0x5c340 j1939_input_source_priority).
- every ROM use (abs_refs): word compares with a client priority byte/word (0x203b6 0x2044e 0x207e0 0x2091a 0x20940 0x20cd8 0x20ff0, a5/a3/a4 in
  0x204b0 0x206a8 0x20e14, and 0x107d0 in the throttle selection: cmp.w with 0x80a6de) or is stored AS the new priority (0x20ce2 0x20ff8;
  low byte 0x808159 stored into the switch priority byte at 0x20958 / (1,a5) (1,a3) (1,a4)). 0x808159 = low byte of the same word, not a second variable.
- 12FE +2 ADDFEBLV = 0x80815a (CM848 j1939_engine_retarder_selection_default_percent), +4 ADDFMNFM = 0x80815c (CM848 j1939_engine_fan_requested_speed_default).
- dump: 0x808158 = 0, 0x80815a = 0, 0x80815c = 0.

### e2m 12F7 = same block record for record in both firmwares (CM550 0x80d70c.. / CM848 0x40aaa6..)
+0 MXACDXER 0x80d70c <-> j1939_accelerator_position_error_fallback_flag ; +1 MXIVCFER 0x80d70d <-> j1939_accelerator_low_idle_switch_unavailable_flag ;
+2 MXACTMER 0x80d70e <-> j1939_pedal_input_timeout_active_flag ; +1A ADEBLVPZ 0x80d726 <-> j1939_engine_retarder_selection_source_priority ;
+1B ADMNFMPZ 0x80d727 <-> j1939_engine_fan_request_source_priority ; +1C ADUVEBLV 0x80d728 <-> j1939_engine_retarder_selection_percent ;
+1E ADUVMNFM 0x80d72a <-> j1939_engine_fan_requested_speed ; +20 MXLPRWTH 0x80d72c <-> idle_check_accelerator_pedal_raw.
CM848 only: +22 JCMXRNTR, +24 JCIHMXFU (inhibit flag) - CM550's e2m has neither and its code has no inhibit guard.

### switch arrays (index = logical input number n; byte n>>3 bit n&7 for the bit arrays)
- 0x80bd4a + n = e2m 12A8 +n switch override priority bytes (CM848 12A8 = 0x40c058 switch_input_source_priority[32]); 0x80bd51 = switch 7 (Calterm 'switch 8', idle),
  0x80bd52 = switch 8 (not idle). CM550 inputs go up to 72 (descriptor entry 0).
- 0x80bcd8 = e2m 000E +A.. user supplied switch values (override value bits; CM848 counterpart switch_input_datalink_state_bits 0x40c07c).
- 0x807d6a = e2m 12FC +0 DSGLDFSW global default switch bits, read as LONGS indexed n>>5 (and.l (0,a0,d0.w*4)); CM848 j1939_switch_input_default_state_bits (ROM bytes).
- 0x80bcf6 = e2m 000E +28 output image bytes (lamp / driver command bits), read by 0x206a8 as byte[(bit>>3)] & 1<<(bit&7).
- enable = algorithm enable words 13.. (0x803c94 + 2*13 = 0x803cae): bit 0xd0 + n -> word 13 + n/16 bit n%16 (CM848: switch_input_datalink_source_bits_cal bytes).

### 0x211f4 (hand-decoded; table words 0008 000e 0014 001a at 0x2122c)
link a6,-4; local long = *(long)0x807d5e (e2m 1234 +0 DSSWIV switch inversion mask); d2 = (8 & 0x1f) >> 3 = 1 -> case 1 (0x2123a): move.b (2,a3),(a2)
= byte 2 of the long (bits 8-15) -> 0x800aaf; then 0x800aae = 0xff; bit 0 of 0x806000 cleared (interrupts masked); 0x80d70d cleared.
0x800aaf bit 0 = inversion bit of logical switch 8 (not idle switch); 0x205c4 XORs it with 0x80bced (DSRWNTSW raw not-idle switch) & 1.
scan_refs.py: NO reference of any form (abs long, bsr/bra, jsr/lea/pea pc-relative) in the dumped ROM -> reach unproven (ROM above 0x40000 is not dumped).

### callers
0x21070: one jsr at 0x1b4f6 in the task set 0x1b4d8 (jsr 0x212b2 receive dispatcher, 0x23244, 0x22070, 0x230ee, 0x21edc, 0x21070, 0x420bc; rts).
  The frozen rows 0x1b4ea / 0x1b4f6 (cm550_diagnosticMonitoringCoordinator / cm550_boostPressureControlInit) are mid-function rows of that one task set.
0x21146: one jsr at 0x1b71a in the task set 0x1b714 (jsr 0x24804, jsr 0x21146, rts); rows 0x1b714 / 0x1b71a likewise.
CM848: cm848_processJ1939SwitchAndRequestInputs <- cm848_phase_group_a_processing; cm848_processJ1939AcceleratorInputs <- cm848_periodicTaskGroup18_calibration6;
  cm848_initJ1939InputProcessing <- start-up initialization list (after cm848_loadDefaultJ1939NamesAndSourceAddresses).
CM848 has NO reader of j1939_received_wet_tank_pressure / j1939_received_remote_accelerator_pedal_position (only the EEC2 handler's stores) -> 0x20784, 0x20fac: none.

### PER-FUNCTION FINDINGS (run 2, each read from the disassembly + both decompilations)
Twin rule used (the repo's practice, cf. writeJ1939DiagnosticMemory / registerJ1939ReceiveHandler rows): same source function = same decision tree in
the same order with the same logic constants (input numbers, 0xfb / 0xfe / 3 / 2, x4/10, x16/10, 0x168, 100 / 50) and the same place in the module
(the two modules have the SAME function order, CM550 just has two more processors). Allowed deltas: CM848-only guards (j1939_dm13_fault_log_inhibit_flag,
j1939_input_monitor_inhibit_flag, j1939_multiplex_enable, j1939_input_fault_start_delay), CM550 inlining the priority-0 write helper, each firmware's own
addresses / calibration bit / fault bit / switch + output numbers.
- 0x201d6/0x20210/0x2024a/0x20284/0x202a0/0x202bc/0x202d8/0x20310/0x20348 = TWINS of 0x509d98/dd8/e18/e58/e98/ed8/f18/f54/f90 (PowerPC disassembly read for
  0x509d98, 0x509e58, 0x509f18: same word index = n>>5, bit = n&31, lwz/and|or/stw; the any-helper has the same one-pass 16-bit loop).
- 0x20380 = twin of 0x509fcc (PowerPC read): clear data-error 5 + timeout 5; gate ADEBLVOD (CM550 0x803cd6 & 0x10 = word 33 bit 4; CM848 0x3fd5b6 & 1 = word 13 bit 0);
  mux priority word >= priority byte (0x80d726); timeouts[5]==0 -> timeout bit 5 + default; <=0xfa -> x4/10; 0xfe -> default; else default + data-error 5.
  CM848 adds: dm13 flag, inhibit flag before each set. No claim of the priority byte in either.
- 0x2041c = twin of 0x50a0cc: same with input 0, gate word 25 & 0x8000 in BOTH, priority byte 0x80d727, x16/10, default 0x80815c.
- 0x204b0 (cm550_outputControlState1Handler - WRONG NAME) = twin of 0x50a1b4: clear 6/6/6; gate switch 7 enable (word 13 & 0x80); priority[7] <= mux; claim priority[7]=mux low byte;
  timeouts[6]==0 -> timeout 6 + pedal timeout 6; 3 -> data error 6 + default bit 7; 2 -> default bit 7; else value != 0; each write only if priority[7]==0 (inlined priority-0 helper).
- 0x205c4 = twin (medium) of 0x50a2cc: word 25 & 8 -> raw QADC result of the sampled throttle (0xfff2b0 + 2*config.qadc_result_register_index) -> 0x80d72c; <=0x168 idle (sw7=1, sw8=0, 0x80aa86=0)
  else off idle; else state=(0x80bced ^ 0x800aaf)&1; != previous -> previous=state, timer=100; equal and timer!=0 -> timer-=50, <=0 -> timer=0 and write sw7/sw8/0x80aa86.
  Deltas: CM550 writes the override bits with NO priority test; CM848 has the armed flag (re-arms timer=100) + forced-reading option + reads via cm848_readSwitchHardwareInput(8).
- 0x206a8(switch s, output b) = twin of 0x50a4a0: gate enable bit of s; mux >= priority[b] (the SAME odd index by the output bit in both firmwares); claim priority[s]; if priority[s]==0:
  value bit s = bit b of the output image 0x80bcf6 (CM848 logical_output_request_bits).
- 0x20784 = NONE in CM848 (remote accelerator, input 1): clear 1/1/1; gate word 18 & 0x1000 AND word 14 & 8; mux >= word 0x80a6e0 (A/D 11 priority, NOT claimed);
  timeouts[1]==0 -> override[11]=default(0x806bec), timeout 1 + pedal timeout 1; 0xfe -> default + fault bit 0 + latch; 0xff or 0xfb..0xfd -> data error 1 + default;
  <=0xfa -> clear fault bit 0, override[11] = x16/10. Tests slot 1 (EBC1 remote accelerator enable switch timer) although EEC2 reloads slot 8 for this byte.
- 0x20890(i) = twin of 0x50a57c: entry i of the 10-byte descriptor table 0x20108; clear timeout(slot) then data error(slot); gate enable bit of the entry's switch; priority[sw] <= mux, claim;
  timeout -> timeout bit + default bit; 3 -> data error bit + default bit; 2 -> default bit; else value != 0; writes only when priority[sw]==0. Default bits read as longs (0x807d6a[sw>>5]).
- 0x20c98 = twin (medium) of 0x50a700: gates word 5 & 0x400 AND word 13 & 0x80; priority word 0x80a6de <= mux, claim (word); timeouts[7]==0 -> timeout 7 + pedal timeout 7,
  override[10]=default(0x806bd4), call 0x205c4; <=0xfa: if 0x80d70d -> 0x80d70c=0, default, off-idle 0; else override[10]=x16/10, off-idle=(v!=0), and if fault bit 0 set and
  idle switch != 2 -> 0x80d70c=0 + clear fault bit 0; >0xfa: 0x80d70c=0, default; 0xfe -> fault bit 0 + latch, idle switch >1 -> off-idle 0, else 0x80d70c=1 and off-idle = (switch==0);
  else data error 7, off-idle 0. CM848 adds dm13 branch, inhibit guards, armed-flag clears, a dedicated fault bit (+ registered).
- 0x20e14 = twin of 0x50a9d4: clear 7/7/7; same two gates; mux >= priority[7] and >= priority[8]; claim both; skip while 0x80d70e != 0; switch <=1: sw7 = (v!=0), sw8 = ((~v)&1);
  else sw7/sw8 = default bits 7 / 8; 2 -> fault bit 0 + latch; else (3) 0x80d70d=1 + data error 7.
- 0x20fac = NONE in CM848 (wet tank pressure, input 9 -> A/D channel 25 override; see the section above).
- 0x21070 = twin (medium) of 0x50aba8: 17 x 0x20890, 0x2041c, 0x20380, 0x206a8 x5 (54,1) (54,4) (33,6) (32,0) (54,2), then any-data-error -> fault bit 0 (+latch) else clear,
  any-timeout -> fault bit 0 (+latch) else clear. CM848: enable gate, start delay, bit 2 / bit 0 of fault word 16 (+registered), pairs (31,1) (31,35) (31,0) (4,4) (31,5).
- 0x21146 = twin (medium) of 0x50ad1c: 0x204b0, 0x20fac, 0x20e14, 0x20c98, 0x20784, the two summaries, then 0x80d70e = any pedal timeout. CM848 has no wet tank / remote accelerator call.
- 0x211f4 = twin (medium) of 0x50ae5c: caches the inversion byte, previous=0xff, clears fault bit 0, clears 0x80d70d. CM848: previous=0xff, timer=100, clears its fault bit (+registered),
  clears the same 12F7 +1 flag, sets the inhibit flag. Unreferenced in the dumped ROM.
- Names checked free in BOTH function_renames.csv (unprefixed): clear/set/anyJ1939...; processJ1939...; updateIdleSwitchesFromLocalInputs; initializeJ1939InputProcessing;
  processJ1939SwitchInputSignal; copyOutputRequestBitToDatalinkSwitch; cm550_processJ1939RemoteAcceleratorPedalPosition; cm550_processJ1939WetTankPressure.
- Global names checked free in CM550: the CM848 names of 12F7 / 12FE records + j1939_input_*_bitmap + accelerator_idle_switch_* + switch_input_source_priority (12A8);
  CM550-own: not_idle_switch_inversion_mask_byte (0x800aaf), switch_1_to_8_override_values (0x80bcd8), switch_input_global_default_bits (0x807d6a),
  switch_input_inversion_mask (0x807d5e), lamp_driver_output_image (0x80bcf6), analog_sensor_override_priorities (0x80a6ca), analog_sensor_raw_override_priorities (0x80a6fc).
- CM848 has NO e2m blocks 1234 / 12FC / 12D0-12D3 (script prints nothing) and its switch user values / defaults are blocks 1576 / 1571 (not in its ID table):
  only 12A7 / 12A8 / 12F6 / 12F7 / 12FE are the same records in both.
- 0x25806 (outside the batch) reads 0x80d70c | 0x80d70e while word 5 & 0x400: non-zero -> fueling state 6 (pedal fault mode) + presetPedalFaultModeFuelDemand.

### FINAL (run 2): final_output_draft.json = the StructuredOutput payload (47 roles: 22 functions + 25 globals)
- verdicts: twin/high = 9 helpers, 0x20380, 0x2041c, 0x204b0, 0x206a8, 0x20890, 0x20e14; twin/medium = 0x205c4, 0x20c98, 0x21070, 0x21146 (cm550_ fallback names given);
  counterpart = 0x211f4 (call site not in the dump + different statement sets); none = 0x20784, 0x20fac.
- precedents in the frozen CSVs: writeJ1939DiagnosticMemory (shared despite deltas) vs cm550_tickJ1939InputSupervision 0x21edc (counterpart: most of CM848's body is absent in CM550).
- 'only reference' claims re-checked against the decompiled names (awk over the frozen .cpp): 0x80d728 / 0x80d72a / 0x80d726 / 0x80d727 / 0x80a6fc appear only in their processor;
  0x80d70c also in cm550_FUN_00025806 (read), 0x80d70e also in cm550_FUN_00025806 (read); the 0x107d0 user of 0x808158 sits in vp44_rpmDerateCalculationController.
- 0x808158 has 13 code references (10 direct move.w / cmp.w + 3 movea.l address loads) + 2 parameter table entries.
- all 25 sensor configs hold tri-state fault number 0 with tri-state disabled (RAM dump) -> fault number 0 looks unassigned (not proven).
- names free: functions in both frozen + live function_renames.csv; globals in every CM550 output CSV (live).

### fault bit
All summary / error paths use bit 0 of 0x806000 (system error status word 0; e2m 1036 +0 has S records for masks 0x02 0x04 0x08 0x10 only - no record
for 0x01) + latch 0x806040 bit 0, under move sr / ori #0x700. The same bit 0 is also set / cleared by mc68k_tpuChannel10PrimarySpeedInterruptHandlerMode0/2
and mc68k_dutyCycleMonitorIsrHandler (fault0_users.py). In 0x21070 / 0x21146 the 'any timeout' result overwrites the 'any data error' result (same bit).
Dump: 0x806000 = 0x2800 (bit 0 clear). All enables 0 in the dump (words 13 14 16 = 0, word 5 = 0, word 25 = 0x0180, word 33 = 0, word 20 = 0; word 18 = 0x303a).
