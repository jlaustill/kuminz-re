# Batch D1 investigator notes (round 93) - scratch, read-only work

Helpers in this folder: find_refs.py (CM550 abs + relative refs), ppc_xref.py (whole-image CM848 data xref),
check_names.py (name collisions in the frozen CSVs), cm848_executive.txt (CM848 executiveFrameInterruptHandler body).

## Executive (0x1b876 executiveFrameInterruptHandler)
- 40 phases; ISTM is 0.1 s / count and drops 1 per pass of 0x1d9b4 (phases 11 + 31) -> 20 frames = 100 ms -> a frame is 5 ms.
- LCLPONTM (1006 +0, 0x611a0) scale 50 ms / count; lamp task 0x1b70c runs in phases 5 / 15 / 25 / 35 (10 frames = 50 ms). Consistent.
- 0x1b754: phases 1, 21 (jsr 0xe998, 0x4115a, 0x41256)   callers bsr.w 0x1b99e, 0x1bc5c
- 0x1b788: phases 3, 23 (jsr 0x491b4, 0xac3c, 0x26cc8, 0x26e2c)   callers 0x1b9e6, 0x1bc98
- 0x1b7f2: phases 11, 31 (jsr 0x46aac, 0x1d9b4, 0x40b30, 0x422b4)   callers 0x1bafa, 0x1bd88
- 0x1b70c: phases 5, 15, 25, 35 (jsr 0x254b6)   callers 0x1ba24, 0x1bb86, 0x1bcd0, 0x1be02
- CM848 slot mates: phases 1/21 cm848_periodicTaskGroup26_calibration8 (overboost / 4WD switch / trans temp / fuel pressure plausibility: no overlap);
  phases 3/23 cm848_periodicTaskGroup28_calibration10 = cm848_calculateEngineLoadPercentages + cm848_validateFuelDemandRelativeToTiming (0x50e000) + 2 CM848-only;
  phases 11/31 hpcr_periodicTaskGroup36_calibration15 (no overlap). CM848 duty cycle monitor is in cm848_periodicTaskSet_outputs2 (phases 19/39);
  CM848 boost monitor in cm848_periodicTaskGroup21_calibration (phases 16/36).
- mid-body rows (21, already removed by the orchestrator, task 32): 0x1b4ea 0x1b4f6 0x1b558 0x1b56a 0x1b57e 0x1b5b4 0x1b5ba 0x1b604 0x1b60a
  0x1b62a 0x1b6ba 0x1b6c6 0x1b6ce 0x1b6d4 0x1b6f8 0x1b6fe 0x1b70a 0x1b71a 0x1b78e 0x1b794 0x1b7d8. Also 0x1db9a (inside 0x1db8a).

## Idle shutdown (0x1d9b4) - cm550_runIdleShutdownStateMachine
- gates: 0x1d9ca flags 3 & 0x2 (ISAGEN), 0x1d9da flags 28 & 0x10 (ISTAEN) must be clear
- jump table 0x1da00: 000c 0048 00a0 00f8 0122 0148 -> case 0 0x1da0c, 1 0x1da48, 2 0x1daa0, 3 0x1daf8, 4 0x1db22, 5 0x1db48
- e2m 10CD: +0 ISOD 0x80d672, +2 ISST 0x80d674, +4 ISTM 0x80d676, +6 ISTMSS 0x80d678 (no code ref), +8 ISWRRQ 0x80d67a,
  +A ISRSFG 0x80d67c, +C ISRSWNFG 0x80d67e, +E ISODRSFG 0x80d680, +10 ISODFG 0x80d682, +12 ISODRQ 0x80d684
- 0008 +66 ISTMLM 0x803c02 (EEPROM mirror -> _cal; dump 36000 = 60 min); 10CC +8 ISWRTMLM 0x808150 (dump 300 = 30 s)
- private RAM: 0x800752 previous state, 0x800754 warning pass counter, 0x800756 delay timer (600)
- writers in the dumped ROM: ISRSFG only 0x1dbb0 (initializer = 1); ISRSWNFG, ISODRSFG none; ISODFG only cleared (0x1da1a, 0x1dbb4)
  -> the condition evaluation is in the undumped ROM (0x46aac runs just before the machine in 0x1b7f2: a candidate, not proven)
- CHR_B2 e2m: Idle_Shutdown_State 0=RESET:1=COUNT:2=WARNING:3=DELAY:4=OVERRIDE:5=SHUTDOWN (same description text as ISST)
- PGN 65252 (Shutdown) payload builder 0x33d38 (no function row; pea at 0x28d30 / 0x2f588): byte 1 by ISST through the jump table 0x33d5a:
  0 -> 0x00, 1 -> 0x40 (SPN 590 timer state), 2 -> 0x44 (+ SPN 594 driver alert), 3 -> unchanged, 4 -> 0x10 (SPN 592 override), 5 -> 0x01 (SPN 593 has shut down)
  byte 2 = 0x7f / 0x3f by flags 3 bit 1 (SPN 591 timer function)
- J1587 PID 71 status (0xefa2, in insiteCommandByteDispatcher): 0x80 ISTM != 0 and < ISTMLM; 0x08 ISAGEN; 0x04 ISOD and ISODEN; 0x02 SHSS and ISTM == 0; 0x01 ISWRRQ
- CM848: NO idle shutdown machine: flags 3 bits 1 / 2 reserved no reader; flags 28 bit 4 reserved; 27 bit 10 no reader;
  Idle_Shutdown_Period 0x3fdd4c / Max_IMT 0x3fdd48 / Min_IMT 0x3fdd4a no reference (ppc_xref.py, neighbour 0x3fdcf6 found);
  engine_shutdown_command_flag 0x40a784 writers: cm848_updateEngineState, commandEngineShutdown,
  cm848_updateEngineProtectionShutdown, cm848_resetEngineProtectionShutdownState only. CHR_CC e2m has no 10CD block.
- output 30 = bit 6 (0x40) of output image byte 3 (0x80bcf9); override priority slot 30 = 0x80bd38 (array 0x80bd1a + n, e2m 12A7).
  e2m ISDR (000E +2B) text says 'BYTE 3, BIT 4' - the code uses 0x40 (bit 6). Mismatch: report, do not label.
  0x23a90 also drives output 30 from lamp request bits 0x20 / 0x40 every pass.
- initializer 0x1db8a (vp44_FUN_0001db8a), called from mc68k_applicationMain start-up list at 0x287bc.

## Lamp family (0x254b6) - Calterm group LAMP_CON 'LAMP_CONTROL'
- lamp request word 0x80daac: 0x01 stop lamp (output 1), 0x02 warning lamp (output 6), 0x04 output 4 (fluids / maintenance /
  engine protection lamp), 0x08 wait to start (output 0), 0x10 water in fuel (output 2), 0x20 + 0x40 output 30 (0x23a90)
- 0x611a0 LCLPONTM / 0x611a2 LCLPFFTM (warning or stop lamp on / off time when flashing, 50 ms / count), 0x611a8 LCLPTB power-up lamp sequence table (16 words)
- 0x80daae OCITWNFG time to change oil (CM848 oil_change_monitor_change_due_flag); 0x80dab0 OCRSFG manual reset performed (CM848 oil_change_monitor_reset_flag;
  only reader 0x2551a, no writer in the dumped ROM); 0x803c42 OCRNSTEA (0008 +A6, _cal)
- 0x80dab2 / 4 / 6 LCDGSTLP / LCDGWNLP / LCDGFDLP (CM848 stop_fault_lamp_flag / warning_fault_lamp_flag / maintenance_fault_lamp_flag)
- 0x80d28e EPSQ 'EPS SHUTDOWN APPROACHING' (CM848 engine_protection_shutdown_approaching_flag)
- switch byte 0x80bccf: 0x20 idle increment (DSICSWSS), 0x40 idle decrement (DSDTSWSS), 0x80 diagnostic / test switch (DSTESWSS)
- 0x24858 power-up lamp sequence: first pass all 16 table outputs on with override priority 0x80, threshold 40; each step: output off, +10; end: +20 then release
- 0x249ee blink requests: ISWRRQ -> warning lamp (LCLPONTM / LCLPFFTM); EPSQ -> stop lamp; ISODRQ -> warning lamp 10 / 10 ticks x 120 then clears ISODRQ; returns 1 when idle
- 0x24d40 fault code flash-out: diagnostic switch + engine stopped; idle inc / dec step; automatic mode; 0x7d (125) = none -> both lamps on
- 0x24f30 active fault lamps: fault definition flags 0x1 stop / 0x2 warning / 0x4 fluids, 0x8 = blink, 0x40 = no lamp; suppress bitmap 0x803fb6
- 0x25316 oil change due flash at power-up: lamp request bit 0x4; 3 flashes per 48-tick cycle, 5 cycles; window ticks 100..399 (0x801a22)
- 0x253b0 oil change monitor reset flash: warning lamp bit 0x2; on 1-5, 24-29, 48-53 of 72 ticks; busy flag 0x801a1c
- 0x25448 oil change due flash while running: after 36000 ticks (30 min) 4 flashes of 19 on / 60 off; needs OCRNSTEA, OCITWNFG, RUNNING

## Boost in-range high (0xe998)
- fault status word 1 (0x806002): 0x200 -> fault index 3 -> Cummins 122; 0x400 -> index 4 -> 123; 0x2000 -> index 91 -> 433 (DGFUCATB 0x80656c + table 0x8067c4 in the RAM dump)
- e2m 123D: +0 DGBSDCTR 0x807c04 (200), +2 DGBSHTTD 0x807c06 (25), +4 DGLWTD 0x807c08 (1792 = 7 %), +6 DGLSRSOF 0x807c0a (400 = 50 rpm), +8 DGSTBSTD 0x807c0c (314)
- RAM 0x800178 dwell count, 0x80017a debounce count (1 after reset); initializer 0xeadc (3 instructions, no function row, no reference in the dumped ROM)
- CM848 counterpart: the last block of cm848_monitorBoostPressureSensorAndUnderboost (0x52d6a8), globals boost_pressure_sensor_high_reading_* (e2m 1631 = same 5 words at 0x642b4)

## Duty cycle monitor (0xac3c), initializer 0xaf70, power-down save 0xb130
- e2m 111C-1125 (DCMN*); RPM axis data 0x807d20 (8 used), load axis data 0x807d34 (6 used), 0x807d40 = 7th load value 10000 (ratio when max fuel = no-load fuel)
- region = rpm bin + (6 - load bin) x 8 (1..48); negative ratio 49 (below high cutoff) / 50
- long term map counters 0x80546e + 4 x region, total 0x805398 (cap 3600000000); short maps 0x80bada / 0x80bba8, totals 0x80bacc / 0x80bad0, limit 0x800006 = DCMNSHTI x 36000
- working RAM 0x800000 load ratio (dword), 0x800004 max fuel, 0x800010 / 0x800026 2D lookup descriptors (x input +6), 0x80000c / 0x80000e the two lookups
- CM848 counterpart cm848_updateDutyCycleMonitorLoadHistogram (0x50638c): 10 load breakpoints, 82 counters, no short term maps

## Percent load (0x26cc8, 0x26e2c)
- 0x26e2c: SPT0PCLD (10BF +4, 0x80db62) = (FSFNFL 0x80d32e - NLFL 0x80db1c) x 25600 / (FST0MXFL 0x80d36a - NLFL), else 0. No clamp.
- CM848 0x50e000 cm848_validateFuelDemandRelativeToTiming: the same records (10BF +4 Tau_0_Percent_Load, 105A +2, 1051 +0, 109C +0), li 25600, + clamp 0xff00. Called right after
  cm848_calculateEngineLoadPercentages in the phase 3 / 23 task -> twin (CM848 adds the clamp).
- 0x26cc8 calculateSpeedRatioComponent = FSPCLD / JCPCLD percent loads: counterpart of cm848_calculateEngineLoadPercentages (0x50de54), control flow differs.

## Serial EEPROM (0x26834, 0x26852, 0x26854)
- VBR = 0x808ddc (movec at 0x28650); QILR 0x13 (0x28664), QIVR 0x50 (0x2866c) -> QSPI vector 0x51 = 81 -> slot 0x808ddc + 4 x 81 = 0x808f20 = where 0x26860 stores 0x26834
- 0x26854: boot load length 0x148a (0x2694a-0x2695a), refresh length 0x64c (0x269da-0x269ea); RAM = 0x803b0a + EEPROM offset; 12 words per QSPI pass (queue entries 4-15)
- RAM dump: 0x803b0a.. equals the 4096-byte EEPROM dump for offsets 0-0xfff; RAM 0x804b0a-0x804f93 (EEPROM 0x1000-0x1489) is NOT a wrap of the dump -> the EEPROM is larger than the 4 KB dump
- driver RAM: 0x801a86 offset (dump 0x4c8), 0x801a88 length (0x64c), 0x801a8a state (0), 0x801a8e base pointer (0x803b0a), 0x801a92 loaded flag (1)
- CM848 counterparts: cm848_initEepromDriverAndLoadMirror (0x4cb64), cm848_onQspiFinished (0x3dcf4)

# SESSION 2 (re-check of the reused notes; new helper ppc_masks.py)
## Idle shutdown - re-verified
- 0x1d9b4-0x1db88 re-disassembled: gates / jump table / every case as in the notes above (movea a3 = 0x80d674 ISST, a4 = 0x80d676 ISTM, a1 = 0x80d67a ISWRRQ).
- PGN 65252 payload builder 0x33d38 re-disassembled: jump table 0x33d5a = 000c 0010 0016 0026 001c 0022 -> 0: clr.b, 1: 0x40, 2: 0x44, 3: skip, 4: 0x10, 5: 0x01. Confirmed.
  byte 3 (index 2) = 0xfd / 0xfc by switch byte 0x80bcd7 & 1 (SPN 985); byte 4 (index 3) = 0xfd / 0xfc by output image byte 0 (0x80bcf6) & 1 = output 0 = wait to start lamp (SPN 1081).
- CM848 has NO idle shutdown machine - closed proof (4 independent checks):
  (a) algorithm_enable_flags_3_cal 0x3fd5a2: 14 reads, masks 0x40 / 0x10 / 0x80 / 0x8000 / 0x100 only (ppc_masks.py) - never 0x2 / 0x4;
  (b) Idle_Shutdown_Period 0x3fdd4c, Max / Min IMT 0x3fdd48 / 0x3fdd4a, Jcomm_Idle_Shutdown_Message_Default_Priority 0x3fd862: no reference (controls 0x3fdcf6, 0x3fd864 found);
  (c) engine_shutdown_command_flag 0x40a784 (RAM control hit 16 accesses): stores only in cm848_updateEngineProtectionShutdown, cm848_resetEngineProtectionShutdownState,
      cm848_updateEngineState, commandEngineShutdown (registered J1939 diagnostic service, no other caller);
  (d) 0xfee4 in the CM848 images: only ori at 0x50be20 (registerJ1939ReceiveHandler(65252)) - no transmit of PGN 65252; CHR_CC e2m has no Idle_Shutdown_State / 10CD records.
  CHR_B2 e2m (7 files, a newer product) has Idle_Shutdown_State 0=RESET:1=COUNT:2=WARNING:3=DELAY:4=OVERRIDE:5=SHUTDOWN: label corroboration only.
- output image byte 3 (0x80bcf9) e2m S masks: 0x10 SLDR starter, 0x20 T2LGSXDR, 0x40 T2HGSXDR / T2SISXDR, 0x80 T2NUSXDR; ISDR (N record) text says bit 4, code uses 0x40 + priority slot 30.

## Session 2: state of the repository while this batch runs
- HEAD moved after the frozen copy (21:26): 7cf52470 (22:17) names the 45 executive task sets by schedule slot:
  0x1b754 cm550_runEvery20FramesTaskSetPhase1, 0x1b788 cm550_runEvery20FramesTaskSetPhase3, 0x1b7f2 cm550_runEvery20FramesTaskSetPhase11,
  0x1b70c cm550_runEvery10FramesTaskSetPhase5 (plate comments list the callees by their OLD names). Other batches' globals are live too:
  0x80ccee engine_hour_meter, 0x80d32e final_fueling, 0x80db5e engine_load_at_current_speed_percent; task 35 is typing 614 globals (widths only).
  -> check names with check_names2.py (frozen + live); rows2.py shows frozen vs live rows.
- executive re-verified (0x1b876): jump table 0x1b90e; frame 1 = 0x1b98c: jsr (a5)=0x1b4d0, bsr 0x1b504, 0x1b572, 0x1b66a, 0x1b6c8, 0x1b754, jsr 0xd610;
  frame 3 = 0x1b9d4: ... 0x1b6e4, 0x1b788, jsr 0x315be; frame 5 = 0x1ba16: ... 0x1b6a2, 0x1b70c, 0x1b7b0. Call 5 = the 10-frame set, call 6 = the 20-frame set.
- CM848 executive (twin): frames 1 / 21 call cm848_periodicTaskGroup26_calibration8 as the 20-frame set, 3 / 23 cm848_periodicTaskGroup28_calibration10,
  11 / 31 hpcr_periodicTaskGroup36_calibration15; the 10-frame set of frames 5 / 15 / 25 / 35 is cm848_periodicTaskGroup17_calibration5.

## Session 2: duty cycle monitor re-verified (0xac3c, 0xaf70, 0xb130)
- 0xac3c body as noted. The two lookup descriptors (20 bytes each: +0 word x cached offset, +2 dword x axis pointer, +6 word x input, +8 word y cached offset,
  +0xa dword y axis pointer, +0xe word y input, +0x10 dword z table pointer - layout from cm550_tableLookup2D 0x35088 and the initializer):
  0x800010 = e2m 1055 / 1054 / 1056 5DFL01XA / YA / ZA 'STEADY STATE 4D FUELING TABLE' (0x6086e / 0x6089a / 0x608a4), used alone when ALPHA (0x80a8f8) = 0x4000;
  0x800026 = e2m 1058 / 1057 / 1059 5DFL00 'TRANSIENT 4D FUELING TABLE' (0x6094c / 0x60978 / 0x60982), used alone when ALPHA = 0; y input 0x190 = 400 = 100 % throttle.
  -> 0x800004 = the 100 % throttle fueling at the cutoff-limited speed (= FSMXTHFL 0x80d368 itself between the cutoffs).
- 0xaf70 (cm550_FUN_0000af70; called from the start-up list at 0x28822): builds the two descriptors; 0x800006 (dword) = DCMNSHTI (0x807d1c, hours) x 36000 = the short term
  period in 0.1 s ticks; 0x80000a (word) = DCMNSHTI x 60 (minutes); DCPR01TL / DCPR02TL (0x80bacc / 0x80bad0) from the stored totals DCMP01TL / DCMP02TL
  (0x805394 / 0x805396, minutes) x 600, capped at the period; byte counts 0x80bad8 / 0x80bba6 = 2 x the stored maps' first words; regions 1..50: processing
  map counters (0x80bada + 4r, 0x80bba8 + 4r) = stored map words (0x80539c + 2 + 2r, 0x805404 + 2 + 2r) x 600.
- 0xb130 (cm550_writeHourMeterConversionData - wrong name; called at 0x289f4): the reverse - stored totals / maps (minutes) = (ticks x 60 + 18000) / 36000.
- every reference to 0x800000-0x80003a is in these three functions (abs_refs): private working RAM.

## Session 2: lamp family re-verified (bodies read this session + disassembly of 0x253b0, 0x254b6, 0x23a90)
- 0x23a90 (processProtectionFlagConditions - wrong name): applies the lamp request word 0x80daac to the output image, each only while that output's override
  priority byte (0x80bd1a + n) is 0: 0x20 -> output 30 (0x80bcf9 bit 0x40), 0x04 -> output 4 (0x80bcf6 bit 0x10), 0x40 -> output 30 again (overwrites the 0x20 result),
  0x01 -> output 1 (bit 0x02), 0x08 -> output 0 (bit 0x01), 0x02 -> output 6 (bit 0x40), 0x10 -> output 2 (bit 0x04). Confirmed.
  priority names (e2m 12A7): slot 0 wait to start lamp (LAMP1), 1 stop engine lamp (LAMP2), 2 water in fuel lamp (LAMP3), 4 engine protection lamp (LAMP5; = the
  'fluids' lamp of LCDGFDLP / FLLPONTM, CM848 e2m 'Maintenance' lamp), 6 diagnostic = warning lamp (LAMP4).
- 0x254b6 order: (1) 0x8019d2 set -> 0x24858 only; (2) 0x24d40 -> if it returns nonzero 0x249ee -> if nonzero: 0x8019e7 = 0x7d, 0x24f30; (3) 0x801a22++ up to 401;
  100 <= count < 400 and OCITWNFG -> 0x25316; (4) OCRSFG or 0x801a1c -> 0x253b0; (5) OCRNSTEA and OCITWNFG and RUNNING -> 0x25448; (6) 0x8019eb / ec / ed = switch byte
  0x80bccf bits 0x20 / 0x40 / 0x80 (DSICSWSS idle increment / DSDTSWSS idle decrement / DSTESWSS diagnostic test switch) as 0 / 1.
- 0x253b0: tick 0x801a1a++; 1-5 request bit 0x2 on and 0x801a1c = 1; 6-23 off; 24-29 on; 30-47 off; 48-53 on; 54-71 off; else (72) 0x801a1c = 0, tick = 0.
- 0x24858: first pass (0x8019d3): every LCLPTB entry (16 words 0x611a8-0x611c6) whose priority <= 0x80: priority = 0x80, output on; threshold 0x8019f8 = 40, pointer
  0x8019f4 = table. Later: tick 0x8019f0++; at the threshold: that entry's output off, pointer++; next entry nonzero and inside the table: threshold += 10; else first time
  0x8019d4 = 1, threshold += 30; second time threshold += 10, every table output's priority released (0), 0x8019d2 = 0, switch previous states cleared.
- 0x249ee: ISWRRQ -> warning lamp bit 0x2 flashed LCLPONTM on / LCLPFFTM off (flag 0x8019e0); EPSQ (0x80d28e) -> stop lamp bit 0x1 the same way (flag 0x8019e1);
  ISODRQ = 1 -> latch 0x8019e2, warning lamp 10 on / 10 off, 120 cycles (0x8019e3), then ISODRQ = 0. Returns 1 only when none is active.
- 0x24d40: diagnostic switch (0x80) on and engine STOPPED, else (if 0x8019e8) lamps 0x3 off and return 1. Edges: diagnostic switch -> first fault; idle increment -> next
  (0x24c5a); idle decrement -> previous (0x24cd2); else automatic mode (LCFUFHMD) after LCFUFHCU repetitions. 0x7d (125) = none -> both lamps on; else
  cm550_ioControlDigitDisplaySequencer(fault code word from 0x8067c4 + 6 x index): warning lamp on 40 ticks, then the stop lamp flashes hundreds / tens / ones
  (cm550_ioControlToggleCycle: bit 0x1 on 10 ticks, off 10) with 40-tick gaps. Returns 0 (low byte) while active.
- 0x24f30: clears LCDGSTLP / LCDGWNLP / LCDGFDLP; per active fault (active_dtc_list, count in [0]): definition flags word (0x... + 6 x fault) 0x1 stop / 0x2 warning /
  0x4 fluids (first match wins), skipped when 0x40 is set or the fault's bit in the bitmap 0x803fb6 is set; 0x8 = flash. Sets the J1939-73 flag and the request bit, steady or
  flashed with LCLPONTM / LCLPFFTM.
- 0x25316: only while 0x801a16 < 5: tick 0x801a18++: bit 0x4 on 1-5, off 6-11, on 12-17, off 18-23, on 24-29, off 30-47, then tick = 0 and 0x801a16++ (3 flashes x 5).
- 0x25448: 0x801a1d = 0: tick 0x801a1e++ until > 36000 (30 min), then 0x801a1d = 1; = 1: bit 0x4 on ticks 1-19, off 20-79, at 80 count 0x801a20++; after 4: back to waiting.
- CM848: stop / warning / maintenance_fault_lamp_flag (0x40ae62 / 64 / 66) have NO writer (ppc_xref: 3 reads in cm848_buildJ1939LampStatusByte only);
  oil_change_monitor_change_due_flag 0x40ae5e is only written; no lamp sequencing code -> the whole family is CM550 only (standalone).

## Session 2: serial EEPROM driver re-verified (0x266da, 0x26834, 0x26852, 0x26854)
- 0x266da (mc68k_runSerialEepromWriteQueue): state dword 0x801a8a. 0 = read stream: stores RR4..RRF (12 words, 0xfffd08..) at mirror base 0x801a8e + offset 0x801a86
  only while ram_refresh_enable (0x80dc6c) != 0, offset += 2 each, wraps to 0 at length 0x801a88 and sets 0x801a92 = 1; then TR3 = offset (next READ address), or state 1 when
  a write is queued (count 0x80ccac). 1 = TR2 6 (write enable) / TR3 2 (write) / TR4 queue address word / TR5 queue data byte, state 2, read index++ mod 0x500, count--.
  2 = TR2 5 (read status) until RR3 bit 0 (write in progress) is clear, then state 1 (more queued) or 0 with offset = 0x80ccb0 and a READ command.
- 0x26834: movem d0-d1/a0-a1; andi.b #0x7f,SPSR (clear SPIF); bsr 0x266da; ori.w #0x8000,SPCR1 (SPE: start the next queue pass); movem; RTE. Reached only through the
  RAM vector 0x808f20 = VBR 0x808ddc (movec at 0x28650: 4e7b 8801) + 4 x 0x51 (QIVR 0x50 at 0x2866c -> QSPI vector 0x51), stored by 0x26860. No call.
- 0x26852: a single rts; one reference, bsr.s at 0x2685e (first instruction after the prologue of 0x26854).
- 0x26854 (jsr at 0x28674 in mc68k_applicationMain, right after QSMCR / QILR / QIVR): vector store; PQSPAR 0x7b, DDRQS 0xfe, PORTQS 0xff, SPCR0 0x8004, SPCR2 NEWQP 2 /
  ENDQP 15, SPCR1 DSCKL 0x10 / DTL 1; TR2 = 3 (READ) CR2 0xbd, TR3 = offset CR3 0xfd, TR4-TRF 0 / CR 0xfd; ram_refresh_enable = 1; state = 0; base = 0x803b0a;
  length = 0x804f94 - 0x803b08 - 2 = 0x148a; polled loop until 0x801a92: clear SPIF, SPE, wait SPIF and CPTQP = 15, 0x266da, both watchdogs; then DTL 0x23, SPIFIE
  (SPCR2 0x8000), SPE, length = 0x804156 - 0x803b08 - 2 = 0x64c (= the _cal range 0x803b0a-0x804155: the periodic refresh).
- dump: offset 0x4c8, length 0x64c, state 0, base 0x803b0a, loaded 1, RREN 1.
- CM848 counterpart cm848_initEepromDriverAndLoadMirror (0x4cb64): same variable roles in the same order (ram_refresh_enable = ENABLED, eeprom_mirror_load_offset,
  eeprom_page_write_state = 0, eeprom_mirror_base_pointer, eeprom_mirror_load_length 0x1a40 then 0x8e8, while (!eeprom_mirror_loaded_flag)) but QSPI job slots, no
  vector store, plus the block checksum -> counterpart. Interrupt side: cm848_onQspiFinished (0x3dcf4; clears SPIF, runs the job completion) -> counterpart.

## Session 2: boost in-range high (0xe998) re-verified
- DGFUCATB (0x80656c) holds WORDS; bit index = 16 x word + bit (LSB first): word 1 0x200 -> entry 25 = fault index 3 -> code 122; 0x400 -> entry 26 = index 4 -> 123;
  0x2000 -> entry 29 = index 91 -> code 433 (fault data record 0x8067c4 + 6 x index). Dump: status word 1 = 0x0400, confirm word 1 = 0x2600.
- gates in order: flags 27 & 0x10; engine_state == 3 (RUNNING); not (status 0x400 and confirm 0x400); not (status 0x200 and confirm 0x200); ESCMES (0x80ccf4) <= LSRF
  (0x80db02) + DGLSRSOF (0x807c0a); JCPCLD (0x80db5e) <= DGLWTD (0x807c08). Any gate failing (after the enable): dwell 0x800178 = 0, debounce 0x80017a = 1.
- dwell++ up to DGBSDCTR (0x807c04, 200); at the limit: BSTPRS (0x80a320) > DGSTBSTD (0x807c0c, 314): debounce++ while <= DGBSHTTD (0x807c06, 25), else debounce-- (not below 0).
- debounce > DGBSHTTD: status word 1 |= 0x2000 and first-occurrence word 1 (0x806042) |= 0x2000 (interrupts masked); debounce == 0 and status 0x2000 set and first-occurrence
  0x2000 clear: status &= ~0x2000.
- CM848: the last block of cm848_monitorBoostPressureSensorAndUnderboost uses e2m 1631 +0..+8 (the same five records as CM550 123D +0..+8) under the names
  boost_pressure_sensor_high_reading_dwell_limit / _debounce_limit / _maximum_engine_load / _idle_reference_speed_offset / _minimum_boost_pressure, RAM _dwell_count / _debounce_count.

## Session 2: low horsepower curve percent load (0x26e2c) vs CM848 0x50e000
- CM550: (1) FSFNFL (0x80d32e) <= NLFL (0x80db1c) -> 0 [0x26e48-4c]; (2) FST0MXFL (0x80d36a) <= NLFL -> 0 [0x26e4e-52]; (3) (FSFNFL - NLFL) x 25600 [0x26e54-6c]
  divu.l (FST0MXFL - NLFL) [0x26e72]; (4) move.w to SPT0PCLD 0x80db62 [0x26e76]; else clr.w [0x26e7e].
- CM848: (1) final_fueling 0x40a2ce <= no_load_fuel_quantity 0x40aeec -> 0 [0x50e010-24]; (2) throttle_100_fueling_low_horsepower_curve 0x40a899 (lha) <= no load -> 0
  [0x50e028-34]; (3) difference x 25600 (li 25600 at 0x50e040) / difference through the 64-bit divide 0x571b0 [0x50e060]; (3b) clamp at 0xff00 [0x50e068-74] - NOT in CM550;
  (4) sth to engine_load_low_horsepower_curve_percent 0x40af26 [0x50e088]. Same four e2m records (1051 +0, 109C +0, 105A +2, 10BF +4), same slot: the second call of the
  20-frame task set of executive frames 3 / 23, right after the percent load function. One extra step in CM848 -> counterpart by the strict rule (a near twin).
- 0x26cc8 calculateSpeedRatioComponent: FSPCLD (0x80db60) and JCPCLD (0x80db5e) - the counterpart of cm848_calculateEngineLoadPercentages (same constants 0x6400 / 0x7f80 /
  0x1111 / 0x1700, control flow revised in CM848).

## Session 2: J1587 PID 71 status byte (0xefa2) re-verified
- 0x80: ISTM != 0 and ISTM < ISTMLM; 0x08: flags 3 & 0x2; 0x04: ISOD != 0 and flags 3 & 0x4; 0x02: SHSS != 0 and ISTM == 0; 0x01: ISWRRQ != 0.

## Session 2: 2D lookup argument record (cm550_tableLookup2D 0x35088) - 22 bytes
- +0 word x axis cached offset (2 = first value after the axis' byte-count word), +2 dword x axis pointer, +6 word x input, +8 word y axis cached offset,
  +0xa dword y axis pointer, +0xe word y input, +0x10 dword z values pointer (*(int *)(table_args + 8)), +0x14 word: nonzero = return the grid value without
  interpolation (table_args[10]). z index = x offset + ((y offset - 2) >> 1) x (x axis byte count).
- instances in this batch: 0x800010 (steady state 4D fueling) and 0x800026 (transient 4D fueling) - 0x16 apart, +0x14 words at 0x800024 / 0x80003a (0 in the dump).
  Another instance: 0x801a94 (cm550_FUN_000269f2 / cm550_FUN_00026a2e: axes 0x808346 / 0x808372, values 0x80837c; x input engine speed, y input ALPHA; result to 0x80db1a, minimum 1).
- there is no struct for it yet (table_interp_args_t is the 12-byte 1D record of lookupTableInterpolation 0x34de0): lead for a struct table_lookup_2d_args_t.

## Session 2: duty cycle axes / maps (dump)
- DCMNESTB 0x807d1e: byte count 18 then 9 values 0 / 8000 / 10400 / 12800 / 15200 / 16800 / 18400 / 20000 / 22400 (rpm x 8); the code compares the first 8 (0x807d20..).
- DCMNLDTB 0x807d32: byte count 14 then 7 values 0 / 1000 / 3000 / 5000 / 7000 / 9000 / 10000; the code compares the first 6 (0x807d34..) and reads the 7th
  (0x807d40 = 10000) as the load ratio when the 100 % throttle fueling equals the no load fueling. Rows 0x807d20 / 0x807d30 / 0x807d34 / 0x807d40 lie inside the two tables.
- map headers: DCMNLGMP 0x80546c = 204 (51 dword counters from 0x80546e, index = region, 0 unused); DCSHPR01 0x80bad8 = 204, DCSHPR02 0x80bba6 = 204 (0x80bada + 204 = 0x80bba6);
  stored maps DCMNMP01 0x80539c = 102, DCMNMP02 0x805404 = 102 (51 words).
- dump: DCMNSHTI 500 h -> 0x800006 = 18000000 ticks, 0x80000a = 30000 min; both stored totals 30000 -> both processing totals 18000000 (both maps full: active map 0).

## Session 2: decisions
- wrappers: propose HEAD's schedule slot names (0x1b754 / 0x1b788 / 0x1b7f2 / 0x1b70c) - proven by the dispatch; role names are not provable (2 of 3 / 1 of 4 / 3 of 4 callees undumped).
- 0x26e2c: counterpart (CM848 0x50e000 has one more step, the 0xff00 clamp); stem calculateEngineLoadLowHorsepowerCurvePercent for both rows.
- 0x26852: skipped (single rts).
- idle shutdown: cm550_ prefix, standalone; enum IDLE_SHUTDOWN_STATE (CM550 only).
# Batch D1 investigator - session 2 final decisions (round 93; appendix to notes.md)

- Wrappers: HEAD's schedule slot names (commit 7cf52470). 0x1b754 / 0x1b7f2 / 0x1b70c standalone (their CM848 slot
  mates share no task); 0x1b788 counterpart (its slot mate shares the two percent load calls).
- 0x266da keeps mc68k_runSerialEepromWriteQueue (incomplete, not wrong) with an extended plate comment;
  mc68k_runSerialEepromDriver only as a note.
- Lamp callees re-verified from the disassembly, not the decompiler (which misrendered 0x24858):
  0x24858 addi.w #0xa at 0x2492e on every step, addi.w #0x14 at 0x2495a at the table end, cmpi.b #0x80 / bhi at 0x24884;
  0x249ee cmpi.b #0x78 (120 cycles) at 0x24b22, cmpi.w #0xa / #0x13 at 0x24b02 / 0x24b10;
  0x24b4e phases 0x28 / 0x50 / 0x78 / 0xa0 at 0x24bca / 0x24bee / 0x24c12 / 0x24c36;
  0x25316 cmpi.w #5 (groups) at 0x2532a; 0x25448 cmpi.w #0x8ca0 (36000) at 0x2546a.
- Live CSV re-checked after the two typing commits (31f911b4, bf0c580d): all 56 proposed global rows still carry
  their frozen names (types only changed). Eight stale rows inside the long term map range 0x80546e-0x805539, none
  inside the two processing maps; stale rows inside the two lookup records, the two axis tables and the
  can_buffer_setup_t area are named in the comments / notes of the output.
- PGN 65252 SPN bit positions: the standard SAE layout (the local database has the parameter order only); the
  builder's bytes 2 - 4 agree with that order (SPN 591 by the enable bit, SPN 985 by the A/C switch, SPN 1081 by the
  wait to start lamp output).
- 0x26e2c: counterpart (CM848 0x50e000 adds the 0xff00 clamp); stem calculateEngineLoadLowHorsepowerCurvePercent.
- Output: draft_output.json, built by build_output.py + overrides.py; check_refs.py checks every identifier the
  output mentions; schema_check.py checks the required fields.

# SESSION 3 (2026-11-25; re-check of sessions 1-2, then final output)
- build_output.py re-run against the current live CSVs: "problems: none", byte-identical to the session 2 draft
  (copy kept as draft_output_session2.json).
- Re-disassembled and confirmed: 0x1d9b4 (gates, jump table 0x1da00, all six cases, 0x1db7e previous state) and the
  initializer 0x1db8a; the wrapper bodies 0x1b70c / 0x1b754 / 0x1b788 / 0x1b7f2; 0x253b0 / 0x25448 / 0x254b6 (every
  constant in the draft); key constants of 0x24858 / 0x249ee / 0x24d40 / 0x24f30 / 0x25316 / 0xe998;
  0x26834 / 0x26852 / 0x26854 (top); 0x26e2c (no clamp) vs CM848 0x50e000 (cmplwi r31,65280 at 0x50e068: clamp).
- Live CSV: the four wrappers carry the proposed slot names (cm550_runEvery20FramesTaskSetPhase1 / 3 / 11,
  cm550_runEvery10FramesTaskSetPhase5); live types of the proposed globals agree with the proposed widths.
- CM848 idle shutdown re-checked once more: the CHR_CC e2m has NO ISAGEN / ISODEN / ISST / 10CD record (106B +8 lists
  only ANC / cruise / idle speed adjust / PTO / road speed bits); the leftover idle shutdown calibration records
  0008 +54 / +56 / +58 (0x3fdd48 / 4a / 4c) and 1254 +28 (0x3fd862) have no access (ppc_xref: neighbours 0x3fdd42 /
  0x3fdd50 found); its two idle shutdown enable bits (flags 19 bit 8, flags 27 bit 10) carry 'no reader in this build'
  in the frozen structure_definitions.csv. No CM848 function or enum is about idle shutdown. -> no twin.
- 0x26852 (single rts): the repository names empty functions <prefix>_emptyStubFunction<N> (cm550_emptyStubFunction4 /
  7 at 0x15f8c / 0x19aca, 'Empty function (a single rts); its one call is in ...'; CM848 cm848_emptyStubFunction3 / 7).
  Session 3 decision: name it cm550_emptyStubFunction10 (9 was the deleted mid-function row 0x303c8) instead of skipping.
- e2m family check (precise, block column = 10CD): 0 records in the 16 CHR_CC files; 5-10 in each CM550-family
  original (00V2, 42t9, 63c5, 64t6, ...). A naive grep ',10CD,' hits CHR_CC region columns (RE_Unlock_Curve_3_OD_Off_OSS_Axis,
  block 8D74, region 10CD) - not idle shutdown. CHR_B2 keeps Idle_Shutdown_State in block 06B2.
- finalize3.py: loads draft_output.json, names 0x26852 (cm550_emptyStubFunction10), adds the session 3 notes, re-runs
  the checks (frozen + live), writes final_output.json -> "problems: none", 30 functions, 0 skipped, 56 globals, 9 enum members.
- Session 3 additions to the output (finalize3.py): global 0x80546c DCMNLGMP -> duty_cycle_monitor_long_term_map_byte_count
  (word; e2m 1125 +0 T record, dump 204 = 51 x 4; parameter ID table entry at ROM 0x35cc8; no code access), so the long
  term map follows the processing maps' byte_count + counts pattern; 0x266da plate wording; summary cut to 5 sentences.
- Readers of algorithm_enable_flags_3_cal (0x803c9a) bit 0x2 (ISAGEN): 0xefbe (J1587 PID 71 status), 0x1d9ca (the
  machine), 0x33d80 (PGN 65252 builder); bit 0x4 (ISODEN): 0xefd6 and 0x1dab0. Confirms the 0x1d9b4 discriminator.
- FINAL: final_output.json, 30 functions / 0 skipped / 57 globals / 9 enum members, problems: none.
