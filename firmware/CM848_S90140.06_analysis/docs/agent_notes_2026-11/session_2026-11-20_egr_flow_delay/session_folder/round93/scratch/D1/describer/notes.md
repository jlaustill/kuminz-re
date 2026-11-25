# D1 describer scratch notes (round 93) - working notes, not a report

## Executive frame layout (0x1b876 executiveFrameInterruptHandler)
- 40 phases, one phase per periodic interrupt. Period groups by bsr.w target (branch_targets.py 1b4b2 1b876):
  every frame 0x1b4d0 (jsr (a5)); every 2: 0x1b4d8 / 0x1b504; every 4: 0x1b518 / 0x1b572 / 0x1b5ce / 0x1b612;
  every 8: 0x1b668 .. 0x1b6b2 (8 entries); every 10: 0x1b6b4 .. 0x1b732 (10 entries); every 20: 0x1b73a .. 0x1b862 (20 entries);
  every 40: direct jsr at the end of some phases.
- frame = 5 ms: ISTM (idle shutdown timer) e2m scale 0.1 s and the machine runs every 20 frames; the duty cycle monitor
  period 0x800006 = hours * 36000 samples.
- 0x1b754 phases 1 / 21; 0x1b788 phases 3 / 23; 0x1b7f2 phases 11 / 31; 0x1b70c phases 5 / 15 / 25 / 35.
- 22 rows sit on a mid-wrapper jsr or on the rts: 0x1b4c2 0x1b4ea 0x1b4f6 0x1b558 0x1b56a 0x1b57e 0x1b5b4 0x1b5ba 0x1b604
  0x1b60a 0x1b62a 0x1b6ba 0x1b6c6 0x1b6ce 0x1b6d4 0x1b6f8 0x1b6fe 0x1b70a 0x1b71a 0x1b78e 0x1b794 0x1b7d8.
  No bsr / jsr / pointer reaches any of them.

## Idle shutdown (0x1d9b4), init 0x1db8a (jsr from 0x287bc)
- e2m block 10CD: +0 ISOD 0x80d672, +2 ISST 0x80d674, +4 ISTM 0x80d676, +6 ISTMSS 0x80d678 (no ref in dump),
  +8 ISWRRQ 0x80d67a, +A ISRSFG 0x80d67c, +C ISRSWNFG 0x80d67e, +E ISODRSFG 0x80d680, +10 ISODFG 0x80d682, +12 ISODRQ 0x80d684.
  0008 +66 ISTMLM 0x803c02 (in the EEPROM mirror), 10CC +8 ISWRTMLM 0x808150. No e2m: 0x800752 / 0x800754 / 0x800756.
- CHR_B2 e2m: Idle_Shutdown_State 0=RESET 1=COUNT 2=WARNING 3=DELAY 4=OVERRIDE 5=SHUTDOWN (same description sentence as ISST).
- PGN 65252 byte 1 from the state (0x33d38, registered by pea at 0x28d2e / 0x2f586): 0 -> 0x00, 1 -> 0x40, 2 -> 0x44,
  3 -> unchanged, 4 -> 0x10, 5 -> 0x01.
- ISRSFG / ISRSWNFG / ISODRSFG have no writer in the dumped ROM except the init (ISRSFG = 1); ISODFG only cleared.
- CM848: no reader of Idle_Shutdown_Period 0x3fdd4c / 0x3fdd48 / 0x3fdd4a (ppc_refs.py, .cpp grep), flags word 3 bits 1 / 2
  reserved, no PGN 65252 transmit, Jcomm_Idle_Shutdown_Message_Default_Priority 0x3fd862 has no reader -> none.

## 0xac3c duty cycle monitor
- counterpart cm848_updateDutyCycleMonitorLoadHistogram 0x50638c (10 load bands, no short term maps, chi maximum fuel).
- 0x800000 dword load ratio (low word 0x800002 -> DCMNLDFA), 0x800004 maximum fuel, 0x800006 short term period in samples.
- 0x807d20 8 speed breakpoints, 0x807d34 6 load breakpoints, 0x807d40 default ratio.
- long term map 0x80546e + 4 x region, short maps 0x80bada / 0x80bba8.

## 0xe998 boost in range high
- faults: 25 / 26 = boost pressure sensor high / low (sensor config channel 5 bytes +20 / +21 in the RAM dump);
  sets fault 29 (word 1 bit 13). 0x806abc = DGFUIDEN fault processing enable bits.
- counterpart: the third block of cm848_monitorBoostPressureSensorAndUnderboost 0x52d6a8 (fault 64 there).
- reset entry 0xeadc (no row, no reference in the dump).

## EEPROM
- 0x26834 = QSPI interrupt handler (rte), RAM vector 0x808f20 = VBR 0x808ddc + 4 x 0x51 (QIVR 0x50 at 0x2866c).
- 0x26854 = init + blocking load 0x803b0a .. 0x804f93 (0x148a), then refresh length 0x64c (0x803b0a .. 0x804155), SPIFIE.
- counterpart cm848_initEepromDriverAndLoadMirror 0x4cb64.

## Lamp family (lamp request word 0x80daac: bit 0 stop, bit 1 warning, bit 2 fluids / maintenance)
- processProtectionFlagConditions 0x23a90 maps the request bits to output bits (stop -> 0x80bcf6 bit 1, warning -> bit 6,
  fluids -> bit 4, 0x08 -> bit 0, 0x10 -> bit 2, 0x20 / 0x40 -> 0x80bcf9 bit 6) under the override priority bytes 0x80bd1a + n.
- 0x24858 power-up output check from ROM list 0x611a8 (not dumped); 0x24d40 fault code flash-out (diagnostic switch, engine stopped);
  0x249ee blink requests (ISWRRQ warning lamp, EPSQ stop lamp, ISODRQ 120 blinks); 0x24f30 lamps from active faults;
  0x25316 oil change due 5 x 3 flashes of the fluids lamp in passes 100-399; 0x253b0 3 warning lamp flashes for OCRSFG;
  0x25448 every 36000 passes 4 flashes of 1 s while running (OCRNSTEA 0x803c42).
- CM848: stop / warning / maintenance fault lamp flags have no writer; no lamp manager -> none.

## Run 2 (continuation after an interruption) - re-checks
- CM848 parameter ID table (flash2 0x53be38, 6-byte records) is ordered by bucket = id mod 1889 (non-decreasing over all 1441
  dumped records); the dump ends at bucket 1417. So absence is only proven for ids whose bucket is < 1417:
  10CC (522), 10CD (523), 0418 (1048), 13EF (1325), 1120 (606), 1121 (607), 123D (891) -> proven absent.
  06B2 (1714), 0738 (1848), 0739 (1849) -> in the UNDUMPED tail: not proven absent (run 1's note (1)(a) overclaimed).
- CM848 .cpp: 1968 functions, none named FUN_; no '= 600;' / '= 0x258;' store; writers of engine_shutdown_command_flag = 1:
  commandEngineShutdown, cm848_updateEngineProtectionShutdown (4 sites); = 0: cm848_updateEngineState,
  cm848_resetEngineProtectionShutdownState. (name-independent store scan: see below)
- ppc_refs.py 0x40a784 (name-independent): sth at 0x216f0 (commandEngineShutdown 0x216e8), 0x508d1c (inside
  cm848_updateEngineProtectionShutdown 0x508898, which also takes the address at 0x508988), 0x508e18
  (cm848_resetEngineProtectionShutdownState 0x508de8); addi at 0x1c760 (cm848_updateEngineState); loads at 0x1c55c /
  0x1c6d4 / 0x1c748 / 0x528718 / 0x529fa4. Nothing else. The neighbours 0x40a772-0x40a782 are only touched from the
  engine protection cluster 0x507a34-0x509840 and three readers (0xe6c4, 0x1fec0, 0x20668).
- ppc_imm.py 0xfee4: PGN 65252 is an immediate once in CM848 (ori at 0x50be20 = registerJ1939ReceiveHandler(0xfee4,
  receivePgn65252ShutdownMessage) in cm848_registerJ1939InputMessageHandlers 0x50bdcc). No transmit registration.
- CM848 .cpp uses of algorithm_enable_flags_3_cal: only cruise_control / power_take_off / road_speed_governor /
  gear_down_protection / cruise_save_set_speed bits; bits 1 / 2 never. idle_shutdown_temperature_enable: no use.
- HIGH_RPM_PROTECTION_STATE (5 members 0-4, 'SHUTDOWN_PENDING ... waiting for idle') and HIGH_RPM_PROTECTION_FLAGS
  (0x80 timer / 0x08 / 0x04 / 0x02 shutdown + timer 0 / 0x01 warning) exist in BOTH firmwares' enums.csv but no global,
  field, parameter or local is typed with them and neither .cpp shows a member: orphans of the old automatic pass. The
  FLAGS masks are exactly CM550's J1587 PID 71 idle shutdown status byte (0xefa2-0xf008) -> stale, not a CM848 machine.
- round 29 e2m audit (repo docs) already lists Idle_Shutdown_Max_IMT / Min_IMT / Period (0x3fdd48 / 4a / 4c) with no reference.
- VERDICT CM848 idle shutdown: none (task premise not supported by the code).

## Run 2 - other re-checks (all from disassembly / e2m)
- 0x26e2c: divu.l d1,d0 then move.w d0,(a3): no overflow branch, no clamp. CM848 0x50e000 clamps at 0xff00 -> counterpart.
- 0x26854 is called once, at 0x28674 in the straight-line start-up part of mc68k_applicationMain (line 79 of 444; the
  forever loop is at the end). The per-pass step is 0x266da (mc68k_runSerialEepromWriteQueue): called from the QSPI
  interrupt handler 0x26834 and from the polled loop inside 0x26854.
- movec a0,vbr at 0x28650 (4e7b 8801), a0 = 0x808ddc; QIVR = 0x50 -> QSPI vector 0x51 -> 0x808ddc + 0x144 = 0x808f20. OK.
- ROM constants above the dump, named by the e2m (block 1006 -> 0x611a0): +0 LCLPONTM 'length of time the warning or
  stop lamp is on when flashing' (50 ms per count), +2 LCLPFFTM (off), +4 / +6 FLLPONTM / FLLPFFTM (fluids lamp),
  +8 LCLPTB 'table - up to 15 values that specify powerup lamp sequence order' (0x611a8, 32 bytes) -> 0x24858 is the
  POWER-UP LAMP SEQUENCE (e2m-proven), +28 / +2A lamp driver error counts, 138B +0 OCWRLP 'lamp chosen to illuminate to
  indicate maintenance' (0x611ce).
- 50 ms per count of LCLPONTM = one pass of the lamp task (every 10 frames) -> 4th confirmation of the 5 ms frame.
- 0x80bccf masks: 0x80 DSTESWSS diagnostic / test switch, 0x20 DSICSWSS idle increment, 0x40 DSDTSWSS idle decrement.
- 0x803fb6 = DGFULPEN + 2 (e2m 12FD +0 at 0x803fb4, 18 bytes, 'bit map parameter for faults, 0 = lamp on, 1 = lamp off').
- 0x806abc DGFUIDEN is 38 bytes (19 words): 0x806abe is its word 1 ('bit mapped parameter used to disable / enable the
  processing of a particular fault'; CM848 label Log_Fault_Indicator).
- fault code assignment table 0x80656c is WORDS (600 bytes = 300 entries): error bit 25 -> record 3 (code 122),
  26 -> record 4 (code 123), 29 -> record 91 (code 433). RAM dump: status word 1 = 0x0400, DGFUIDEN word 1 = 0x2600.
- RAM dump (ram_checks.py): stop lamp control bit 0 on 9 codes (151 155 234 262 361 367 373 376 415), warning bit 1 on 68
  codes, fluids bit 2 on 235 only, bits 3 / 6 on none; ISTMLM 36000, ISWRTMLM 300; idle shutdown block = state 0, timer
  36000, ISRSFG 1 (the initializer's values; feature disabled, flags word 3 = 0x86e8); DGFULPEN = 0x0010 + 16 zero bytes
  (a size word, then the bitmap -> the code's base 0x803fb6); lamp request word 0x0002 and LCDGWNLP 1 (fault 123 active);
  0x8019d2 0 / 0x8019d4 1 / 0x801a22 401 / 0x8019e7 125; EEPROM driver offset 0x4c8, length 0x64c, state 0, base
  0x803b0a, loaded 1; QSPI vector 0x808f20 = 0x00026834; duty cycle period 18,000,000 = 500 h x 36000.
- J1587: 0xefa2-0xf008 is the case insite_parameter_id == 0x47 (PID 71) of insiteCommandByteDispatcher (0xed64).
- 0x33d38 (no row): periodic transmit callback of PGN 65252 (registered at 0x28d2e with period 1000 and at 0x2f586
  on request): fills payload bytes 1-4 and calls cm550_sendCanMessage with j1939_pgn65252_tx_message. 0x33dfa
  vp44_engineHoursPGN_65252_Builder initializes that descriptor (priority from JCISSHPZ 0x803f78 'default network
  priority for idle shutdown message') and bytes 5-8 = 0xff: 'engineHours' is wrong.
- CM848 lamp side: Lamp_Blink_On/Off_Time, Lamp_Sequence_Table, lamp driver error counts (block 1006 -> ROM 0x5a752..)
  and OCM_Warning_While_Running 0x3fdd62 have NO access in ROM / flash2 (ppc_refs.py); stop / warning / maintenance
  fault lamp flags are only read (cm848_buildJ1939LampStatusByte 0x50b5b4); engine_protection_shutdown_override_lamp_flag
  only written. -> no lamp control code in CM848.
- 0x34c36 vp44FaultRegisterBit2Monitor is the water in fuel monitor: sets lamp request bit 4 (0x10) and error bit 77.
- 0x80d28e = e2m 10B1 +14 EPSQ 'EPS shutdown approaching' = CM848 engine_protection_shutdown_approaching_flag (CM550 row
  says ..._derate_approaching_flag).
- CHR_CC_11.45.01.07 (CM848's e2m): no record whose BLOCK column (3) is 06B2 / 0738 / 0739 / 0418 / 10CD / 10CC (a loose
  grep hits 23 lines, all in column 5). The CHR_B2 family has the full set: 06B2 +0 Idle_Shutdown_State
  (0=RESET:1=COUNT:2=WARNING:3=DELAY:4=OVERRIDE:5=SHUTDOWN), +2 _Reset_Flag, +4 _Reset_From_Warning_Flag, +6
  _Reset_From_Override_Flag, +8 _Override_Flag, +A _Delay_Flag, +C _Warning_From_Delay_Flag, +E _Timer, +10 _Override;
  0738 +2 _Warning_Period; 0739 +C _Period; 0418 +0 _Warning_Lamp_Request -> the words of the proposed global names.
- 0x801a16 (oil change flash group counter) and 0x801a22 (lamp task pass counter) have one reference each (their own
  function): nothing resets them in the dumped ROM.
- CM848's cm848_periodicTaskGroup21_calibration / Group28_calibration10 / TaskSet_outputs2 are each called twice in
  CM848's executiveFrameInterruptHandler (twice per 40 phases).
- e2m blocks 1120 / 1121 = DCSHPR01 / DCSHPR02 'short term processing map 1 / 2' at CM550 0x80bad8 / 0x80bba6; both are
  proven absent from CM848's parameter ID table (buckets 606 / 607). 1125 +0 DCMNLGMP = long term map table 0x80546c.
- FINAL ANSWER of run 2: build_final2.py -> final_output2.json (27 roles, 6 enum members). final_output.json is run 1's.
- live repository (commit 7cf52470, after the freeze) already names the 45 wrappers by slot:
  0x1b754 cm550_runEvery20FramesTaskSetPhase1, 0x1b788 ...Phase3, 0x1b7f2 ...Phase11, 0x1b70c cm550_runEvery10FramesTaskSetPhase5.
  My phases (1/21, 3/23, 11/31, 5/15/25/35) agree.
