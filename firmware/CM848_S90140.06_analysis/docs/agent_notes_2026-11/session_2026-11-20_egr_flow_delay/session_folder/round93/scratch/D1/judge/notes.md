# D1 judge notes (round 94 judge run 1)

Started 2026-11-25. Describer roles: /home/linux/.claude/jobs/374b0424/tmp/w15/r94/batch_D1.json key blind.

## Differences investigator vs describer
- 0xe998: inv cm550_monitorBoostPressureSensorInRangeHighReading / desc cm550_monitorBoostPressureInRangeHighError
- 0x249ee: inv cm550_flashShutdownWarningLamps / desc cm550_blinkShutdownWarningLamps
- 0x24d40: inv cm550_runFaultCodeFlashOut / desc keep cm550_faultCodeDisplayController
- 0x249b6: inv cm550_runStopLampFlashCycle / desc cm550_flashStopLampOnce
- 0x24c5a/0x24cd2: inv selectNext/PreviousFaultToFlash / desc ...FaultCodeToFlash
- 0x24f30: inv cm550_updateActiveFaultLamps / desc cm550_updateLampRequestsFromActiveFaults
- 0x25316/0x25448: inv EngineProtectionLamp / desc FluidsLamp
- 0x26852: inv cm550_emptyStubFunction10 / desc no name
- 0x1b788: inv counterpart (cm848 0xbdd8) / desc none

## Verified so far (judge)
- Callers (refs.py): all single callers as the investigator says; 0x26834 only by move.l #imm at 0x26860 (vector 0x808f20); 0x26852 bsr.s at 0x2685e; 0xeadc no reference.
- Executive (exec_frames.py on jump table 0x1b90e): 0x1b754 = frames 1/21 call 6; 0x1b788 = 3/23; 0x1b7f2 = 11/31; 0x1b70c = 5/15/25/35 call 5. Live CSV already has these 4 slot names (7cf52470).
- CM848 slot mates (frozen cpp): 0xbdd8 group28 = loadPercentages, 0x50e000, govPressOffset, fuelPressGovMonitors (shares 2 tasks with 0x1b788); group26/hpcr36/group17 share none.
- CM848 idle shutdown: ppc_refs.py: no access to 0x3fdd4c/48/4a (0x3fdd50 found 4x as control); 0x40a784 stores only 0x216f0, 0x508d1c, 0x508e18 (+addi 0x1c760 / 0x508988). No idle_shutdown name in CM848 CSVs; CM848 e2m has only cal leftovers (0008 +54/56/58, 0009 tool limits, 106B +38 bit, 1254 +28). -> no CM848 machine; task premise false.
- 0x1d9b4 state machine re-derived (dis): gates word3 0x2 / word28 0x10; cases as investigator; 0x803cca 0x400 = idle_shutdown_temperature_enable (word 27 bit 10 ISAATPEN).
- 0x1db8a init: as investigator.
- 0xe998: as investigator; 0x806abe = DGFUIDEN word 1 (000F +570, 'disable/enable the processing of a fault'), frozen name fault_confirm_status_word_1 -> plate 'confirm bits' wording off.
- fault map (RAM): bit 29 -> idx 91 -> 433 (control 0x1112); bit 25 -> 122, bit 26 -> 123.
- RAM dump: DCMN period 18000000 / 30000; lookup records match; 0x807d18 = 20000 (high), 0x807d1a = 6400 (low); 0x807d40 = 10000 (7th load value); EEPROM driver offset 0x4c8 len 0x64c state 0 base 0x803b0a loaded 1; vector 0x808f20 = 0x26834.
- 0x35088 (cm550_tableLookup2D) argument layout = 22 bytes exactly as the investigator says (+0 x off, +2 x ptr, +6 x in, +8 y off, +a y ptr, +e y in, +10 z ptr, +14 no-interp flag). Existing table_interp_args_t (12 bytes) is the 1D lookup (0x34de0) arg.
- Lamp family re-derived from disassembly (dis_lamps.txt): 0x2482e arm, 0x24858 power-up sequence (LCLPTB 0x611a8, 16 entries, prio 0x80, 40 / +10 / +20 ticks), 0x249b6 stop flash 0/10/20 returns 1, 0x249ee three shutdown flashes (ISWRRQ bit 2 / EPSQ bit 1 / ISODRQ 120x 10on-10off, clears ISODRQ), returns 1 when idle; 0x24b4e digits (phase 0/40/80/120/160); 0x24c5a / 0x24cd2 fwd / back selectors (skip ctrl 0x40, 125 none); 0x24d40 flash out (diag switch 0x80 + STOPPED; returns 1 when off); 0x24f30 active fault lamps (ctrl 1/2/4 + 8 flash, 0x40 / bitmap 0x803fb6 excl.; sets 0x80dab2/4/6); 0x25316 bit 4 5x3 flashes; 0x253b0 bit 2 3 flashes (busy 0x801a1c); 0x25448 bit 4 36000 wait + 4 flashes; 0x254b6 order as both say. 0x23a90 bit->output map as investigator.
- Output 4 = 'engine protection lamp' (EPLPPZ, LCEGPNLP) = 'fluids lamp' (LCDGFDLP, FLLPONTM); frozen rows use both (engine_protection_lamp_override_priority, fluids_lamp_blink_phase). Investigator choice OK.
- 0x80bd38: no e2m record at 12A7 +1E; byte; slot 30 of 0x80bd1a array; image bit 0x80bcf9 0x40 (000E +2B: ISDR text says bit 4, T2HGSXDR/T2SISXDR bit 6) -> neutral output_30_override_priority OK.
- EEPROM driver (dis_eeprom.txt): states 0/1/2 of 0x801a8a (all stores/compares checked: cmp #2 0x266ea, move #1 0x2673a/0x267a4, clr 0x2673e/0x2693a, tst 0x26756, cmp #1 0x267b6, move #2 0x2680a). Start-up load 0x804f94-0x803b08-2 = 0x148a (RAM 0x803b0a-0x804f93), then 0x64c (0x803b0a-0x804155). RAM 0x803b0a-0x804b09 == eeprom.bin (4096 B, 0 diffs); 0x804b0a-0x804f93 != eeprom.bin 0..0x489 (1043 diffs, not a wrap).
- can_buffer_setup_t (20 B) at 0x801a8a covers state/base/loaded + start of a 2D lookup record at 0x801a94 (cm550_FUN_000269f2; also 0x801aaa). 0x801a9e 'ambient_conditions_msg_header' = +0xa of that record (lead).
- ERROR in proposal comment: 0x80d36a 'its writer is not in the dumped ROM' is false: cm550_FUN_0001cc72 writes it (move.w d0,(a5) 0x1cd64, add.w 0x1cd7c, move.w 0x1cd94; a5 = 0x80d36a at 0x1cc88); cm550_updateElectronicSmartPowerTau reads it at 0x1ac3e.
- 0x1d9b4 plate: 'condition flags ... have no writer in the dumped ROM' imprecise (init sets ISRSFG = 1; RESET + init clear ISODFG).
- 0xe998 plate: 'with their confirm bits' -> 0x806abe is DGFUIDEN word 1 (fault processing enable bitmap), not confirm.
- PGN 65252 builder 0x33d38: table 0x33d5a -> 0:00 1:40 2:44 3:none 4:10 5:01; byte 2 7f/3f by idle_shutdown_enable. J1939 byte 1 layout (SPN 593/594/592/590) matches the states.
- CHR_B2 (7 files) Idle_Shutdown_State '0=RESET:1=COUNT:2=WARNING:3=DELAY:4=OVERRIDE:5=SHUTDOWN' confirmed.
- CM848 0x50e000: signed compares, 64-bit divide, clamp 0xff00 -> counterpart of 0x26e2c (not twin). CM848 name wrong (lead).
- abs_refs: all widths as proposed. 0x80bad4 has one more reader at 0x3168a (not listed; fine).
## Decisions (judge)
- All 30 function names CONFIRMED except 0x266da -> AMENDED mc68k_runSerialEepromDriverStep (state 0 = the mirror read / refresh stream is its normal job; the old name covers only states 1 / 2). Cascade: plate comments of 0x26834 / 0x26854 amended to the new callee name.
- Comment-only AMENDED: 0xe998 (DGFUIDEN, not 'confirm bits'), 0x1d9b4 ('no writer' imprecise), global 0x80d36a (writer = cm550_FUN_0001cc72), enum IDLE_SHUTDOWN_STATE:0 (RESET clears only the warning lamp request, not ISODRQ).
- 0x26852 emptyStubFunction10 CONFIRMED (repo convention; claims only 'empty').
- 0x1b788 counterpart (slot mate shares 2 tasks) CONFIRMED; prefixes unchanged either way.
- No REFUTED elements. skipped[] empty.
- Leads: CM848 0x50e000 misnamed (-> cm848_calculateEngineLoadLowHorsepowerCurvePercent); HIGH_RPM_PROTECTION_STATE / _FLAGS enums are idle shutdown / PID 71 leftovers; 0x33d38 PGN 65252 builder has no row; 0x33dfa vp44_engineHoursPGN_65252_Builder misnamed; 0x801a94 / 0x801aaa 2D lookup records (0x801a9e row inside); 0x806abe frozen name fault_confirm_status_word_1 wrong (DGFUIDEN word 1); cm550_FUN_0001cc72 = writer of FSMXTHFL / FST0MXFL.
- Task #39 data: start-up load RAM 0x803b0a-0x804f93 (0x148a B), refresh 0x803b0a-0x804155 (0x64c B).
## Final (judge run 1): 96 verdicts in verdicts.json (build_verdicts.py): 89 CONFIRMED, 7 AMENDED, 0 REFUTED. Submitting via StructuredOutput.
