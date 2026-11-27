"""Build the batch D1 investigator output (round 93, session 2) as JSON and check it:
every listed function exactly once (functions[] or skipped[]), unique proposed names, name collisions against the
frozen and the live CSVs. Read-only on the repository; writes draft_output.json next to this file.
usage: build_output.py"""
import csv
import json
import os
from collections import Counter

HERE = os.path.dirname(os.path.abspath(__file__))
F = "/home/linux/.claude/jobs/374b0424/tmp/w15/r93/frozen/"
R = "/home/linux/code/kuminz-re/.claude/worktrees/cm848-egr-flow-delay/firmware/"

functions = []


def fn(address, current_name, proposed_name, role, discriminator, relation, plate_comment, evidence, confidence,
       cm848_address="", cm848_current_name=""):
    functions.append({
        "address": address, "current_name": current_name, "proposed_name": proposed_name, "role": role,
        "discriminator": discriminator, "relation": relation, "plate_comment": plate_comment,
        "evidence": evidence, "confidence": confidence, "cm848_address": cm848_address,
        "cm848_current_name": cm848_current_name,
    })


# ----------------------------------------------------------------------------------------------- listed functions
fn("0x0000ac3c", "cm550_FUN_0000ac3c", "cm550_updateDutyCycleMonitorLoadHistogram",
   "Takes one duty cycle monitor sample: computes the load factor from the fueling, picks the engine speed / load "
   "region and adds 1 to that region's counter in the long term map and in the active short term map.",
   "The only duty cycle monitor function that tests the enable bit (andi.w #0x8 on algorithm_enable_flags_18_cal at "
   "0xac58), computes the region byte DCMNOPRN and increments map counters; its siblings 0xaf70 (start-up: converts "
   "the stored maps into the processing maps) and 0xb130 (power-down: converts them back) only convert.",
   "counterpart",
   "Duty cycle monitor sample (e2m DCMN records; enable = bit 3 of algorithm_enable_flags_18_cal), once per 100 ms "
   "from cm550_runEvery20FramesTaskSetPhase3 while engine_state is not STOPPED. The 100 percent throttle fueling at "
   "the engine speed (limited to the cutoffs DCMNLOES / DCMNHIES) is FSMXTHFL between the cutoffs, else the steady "
   "state and transient 4D fueling tables at 100 percent throttle blended by ALPHA; load ratio = (FSFNFL - NLFL) x "
   "10000 / (that fueling - NLFL), copied to DCMNLDFA (0 when negative). Region DCMNOPRN = speed bin (first 8 "
   "values of DCMNESTB) + (6 - load bin of DCMNLDTB) x 8, or 49 / 50 for a negative ratio below / at or above the "
   "high cutoff; that region's counter and the total get +1 in the long term map (DCMNLGMP, DCLGMPTL, up to "
   "3600000000) and in the short term processing map DCMNSHNU selects (1 or 2; a map fills until its total reaches "
   "DCMNSHTI hours x 36000). The counterpart of cm848_updateDutyCycleMonitorLoadHistogram (CM848 has no short term "
   "maps).",
   "0xac52-0xac68 enable bit 0x8 of 0x803cb8 and engine_state (0x80d0c8) != 1; 0xac6c-0xacba map start times "
   "(0x805390 / 0x805388 / 0x80538c = engine hour meter 0x80ccee); 0xacbc-0xadb8 speed against 0x807d18 / 0x807d1a, "
   "x inputs 0x800016 / 0x80002c, ALPHA 0x80a8f8 = 0x4000 / 0 / blend (mulu, lsr 14) of two cm550_tableLookup2D "
   "calls (0x800010 = e2m 1055 / 1054 / 1056 steady state 4D fueling, 0x800026 = 1058 / 1057 / 1059 transient; y "
   "input 0x190 set by 0xaf70), else move.w 0x80d368 at 0xadb8; 0xadc2-0xae18 ratio: x 10000 (shift-add) then "
   "divs.l, or the word 0x807d40 when the fueling equals NLFL 0x80db1c; 0xae1e-0xae46 negative: 0x80bad4 = 0 and "
   "region 0x31 / 0x32; 0xae4a-0xaec8 two axis searches (0x807d20 8 entries, 0x807d34 6 entries), region = (6 - "
   "load) x 8 + speed at 0xaec0-0xaec8; 0xaeca cmpi.l #0xd693a400 then addq.l on 0x80546e + 4 x region and "
   "0x805398; 0xaeea-0xaf32 active map byte 0x80bad7 from the totals 0x80bacc / 0x80bad0 against the limit "
   "0x800006; 0xaf34-0xaf68 addq.l on 0x80bada / 0x80bba8 + 4 x region and the total. Single caller: jsr at "
   "0x1b78e. CM848 0x50638c: same enable bit, same STOPPED gate, same x 10000 ratio, 8 speed breakpoints, long "
   "term cap 3600000000; differs: 10 load breakpoints (regions to 82), 13000 clamp, no short term maps, percent "
   "time at load words.",
   "high", "0x0050638c", "cm848_updateDutyCycleMonitorLoadHistogram")

fn("0x0000e998", "cm550_FUN_0000e998", "cm550_monitorBoostPressureSensorInRangeHighReading",
   "The boost pressure in-range high diagnostic: at low load near idle speed, boost pressure that stays above a "
   "threshold sets the fault bit of Cummins fault code 433.",
   "The only reader of boost_pressure_in_range_diagnostic_enable in the dumped ROM; it owns the two counters "
   "0x800178 / 0x80017a and holds the only ori.w #0x2000 / andi.w #0xdfff on system error status word 1 "
   "(0x806002; fault index 91 = fault code 433). The out-of-range boost faults 122 / 123 (bits 0x200 / 0x400) are only read "
   "here, as inhibits.",
   "counterpart",
   "Boost pressure in-range high check (e2m 123D DGBSDCTR / DGBSHTTD / DGLWTD / DGLSRSOF / DGSTBSTD; enable = bit 4 "
   "of algorithm_enable_flags_27_cal, DGBSIREN), once per 100 ms from cm550_runEvery20FramesTaskSetPhase1. It runs "
   "while engine_state is RUNNING, neither boost circuit fault (status word 1 bits 0x200 / 0x400 with their "
   "confirm bits) is active, engine speed ESCMES is at most LSRF + DGLSRSOF and percent load JCPCLD is at most "
   "DGLWTD; otherwise the dwell count is zeroed and the debounce count set to 1. After DGBSDCTR passes of dwell "
   "the debounce count goes up while boost pressure BSTPRS is above DGSTBSTD and down otherwise; above DGBSHTTD "
   "it sets bit 0x2000 of system error status word 1 and of the first occurrence word (fault code 433), and at 0 "
   "it clears the status bit once the first occurrence bit is clear. The counterpart of the last block of "
   "cm848_monitorBoostPressureSensorAndUnderboost.",
   "0xe9b4-0xe9be andi.w #0x10 on 0x803cca; 0xe9c2 cmpi.w #3 on engine_state; 0xe9ce-0xea12 the two inhibits "
   "(0x806002 and 0x806abe masks 0x400 then 0x200); 0xea16-0xea32 0x80db02 + 0x807c0a against 0x80ccf4; "
   "0xea36-0xea42 0x80db5e against 0x807c08; 0xea46-0xea4c dwell (a3 = 0x800178) up to (a5) = 0x807c04; "
   "0xea54-0xea70 0x80a320 against 0x807c0c, debounce (a2 = 0x80017a) +1 while <= (a4) = 0x807c06 else -1; "
   "0xea72-0xea90 ori.w #0x2000 on 0x806002 and 0x806042 with interrupts masked; 0xea98-0xeac8 clear; 0xead0 "
   "clr.w (a3), move.w #1,(a2). Fault mapping from the RAM dump: DGFUCATB 0x80656c word 29 (16 x 1 + 13) = 91, "
   "fault data record 0x8067c4 + 6 x 91 = 433; words 25 / 26 = fault indexes 3 / 4 = codes 122 / 123. Dump: "
   "DGBSDCTR 200, DGBSHTTD 25, DGLWTD 1792, DGLSRSOF 400, DGSTBSTD 314. Single caller: jsr at 0x1b754. CM848 "
   "0x52daf0-0x52dca4 inside 0x52d6a8: the same five records (e2m 1631 +0..+8 at ROM 0x642b4-0x642bc) in the "
   "same order of tests (speed 0x52daf0, load 0x52db14, dwell 0x52db34, boost 0x52db94, debounce 0x52dba4, set "
   "0x52dbd8, clear 0x52dc20), but inside a larger monitor with CM848's fault bookkeeping.",
   "high", "0x0052d6a8", "cm848_monitorBoostPressureSensorAndUnderboost")

fn("0x0001b754", "cm550_FUN_0001b754", "cm550_runEvery20FramesTaskSetPhase1",
   "Executive frame task set: runs three tasks in frames 1 and 21 of the 40-frame cycle (every 100 ms), the first "
   "of them the boost pressure in-range high check.",
   "Its position in the dispatch: the sixth call (the 20-frame set) of executive frames 1 and 21 only (bsr.w at "
   "0x1b99e and 0x1bc5c). Two of its three callees (0x4115a, 0x41256) are above the dumped ROM, so no role name "
   "can be proven; the slot is what the code shows.",
   "counterpart",
   "Executive frame task set: runs every 20 frames (100 ms), in frames 1 and 21 of the 40-frame cycle, as call 6 "
   "of those frames in executiveFrameInterruptHandler. Calls, in order: "
   "cm550_monitorBoostPressureSensorInRangeHighReading, 0x4115a (not dumped), 0x41256 (not dumped). CM848's slot "
   "mate is cm848_periodicTaskGroup26_calibration8, with a different task list.",
   "0x1b754 jsr 0xe998 / 0x1b75a jsr 0x4115a / 0x1b760 jsr 0x41256 / 0x1b766 rts. Callers: bsr.w at 0x1b99e (frame "
   "1 code at 0x1b98c = jump table 0x1b90e + 0x7e) and 0x1bc5c (frame 21 at 0x1bc4a = + 0x33c); each frame calls "
   "jsr (a5) = 0x1b4d0, the 2-frame, 4-frame, 8-frame, 10-frame sets and this 20-frame set. A frame is 5 ms: ISTM "
   "(0.1 s per count) drops 1 per pass of a 20-frame task, LCLPONTM (50 ms per count) counts 10-frame passes. "
   "HEAD (commit 7cf52470, after the frozen copy) already carries this name. CM848 executive (twin, 0xc0a0): "
   "cases 1 and 0x15 call cm848_periodicTaskGroup26_calibration8 in the same position.",
   "high", "0x0000bd80", "cm848_periodicTaskGroup26_calibration8")

fn("0x0001b788", "cm550_FUN_0001b788", "cm550_runEvery20FramesTaskSetPhase3",
   "Executive frame task set: runs four tasks in frames 3 and 23 of the 40-frame cycle (every 100 ms): one "
   "undumped task, the duty cycle monitor sample and the two percent load calculations.",
   "Its position in the dispatch: the sixth call (the 20-frame set) of executive frames 3 and 23 only (bsr.w at "
   "0x1b9e6 and 0x1bc98). Its first callee 0x491b4 is above the dumped ROM and the three dumped ones belong to two "
   "subsystems, so the slot is the name.",
   "counterpart",
   "Executive frame task set: runs every 20 frames (100 ms), in frames 3 and 23 of the 40-frame cycle, as call 6 "
   "of those frames in executiveFrameInterruptHandler. Calls, in order: 0x491b4 (not dumped), "
   "cm550_updateDutyCycleMonitorLoadHistogram, cm550_calculateEngineLoadPercentages, "
   "cm550_calculateEngineLoadLowHorsepowerCurvePercent. CM848's slot mate cm848_periodicTaskGroup28_calibration10 "
   "also starts with the two percent load calculations.",
   "0x1b788 jsr 0x491b4 / 0x1b78e jsr 0xac3c / 0x1b794 jsr 0x26cc8 / 0x1b79a jsr 0x26e2c / 0x1b7a0 rts (the frozen "
   "rows 0x1b78e and 0x1b794 are mid-body). Callers: bsr.w at 0x1b9e6 (frame 3 code at 0x1b9d4 = table + 0xc6) "
   "and 0x1bc98 (frame 23 at 0x1bc86 = + 0x378). HEAD (commit 7cf52470) already carries this name. CM848 "
   "executive cases 3 and 0x17 call cm848_periodicTaskGroup28_calibration10 = "
   "cm848_calculateEngineLoadPercentages, 0x50e000, cm848_monitorGovernorPressureSensorOffset, "
   "cm848_runFuelPressureGovernorMonitors.",
   "high", "0x0000bdd8", "cm848_periodicTaskGroup28_calibration10")

fn("0x0001b7f2", "vp44_FUN_0001b7f2", "cm550_runEvery20FramesTaskSetPhase11",
   "Executive frame task set: runs four tasks in frames 11 and 31 of the 40-frame cycle (every 100 ms); the only "
   "dumped one is the idle shutdown state machine.",
   "Its position in the dispatch: the sixth call (the 20-frame set) of executive frames 11 and 31 only (bsr.w at "
   "0x1bafa and 0x1bd88). Three of its four callees (0x46aac, 0x40b30, 0x422b4) are above the dumped ROM. Nothing "
   "in it touches the VP44 pump, so the vp44_ prefix does not hold.",
   "counterpart",
   "Executive frame task set: runs every 20 frames (100 ms), in frames 11 and 31 of the 40-frame cycle, as call 6 "
   "of those frames in executiveFrameInterruptHandler. Calls, in order: 0x46aac (not dumped), "
   "cm550_runIdleShutdownStateMachine, 0x40b30 (not dumped), 0x422b4 (not dumped). The idle shutdown machine's "
   "condition flags have no writer in the dumped ROM, so one of the undumped tasks (0x46aac runs just before it) "
   "probably evaluates them. CM848's slot mate is hpcr_periodicTaskGroup36_calibration15, with a different task "
   "list.",
   "0x1b7f2 jsr 0x46aac / 0x1b7f8 jsr 0x1d9b4 / 0x1b7fe jsr 0x40b30 / 0x1b804 jsr 0x422b4 / 0x1b80a rts. Callers: "
   "bsr.w at 0x1bafa (frame 11 code at 0x1bae8 = table + 0x1da) and 0x1bd88 (frame 31 at 0x1bd76 = + 0x468). HEAD "
   "(commit 7cf52470) already carries this name. CM848 executive cases 0xb and 0x1f call "
   "hpcr_periodicTaskGroup36_calibration15 in the same position.",
   "high", "0x0000bf34", "hpcr_periodicTaskGroup36_calibration15")

fn("0x0001d9b4", "vp44SensorStatusMonitor", "cm550_runIdleShutdownStateMachine",
   "Steps the idle shutdown state machine (state word ISST, six states): counts the idle shutdown timer down, "
   "requests the warning lamp flash, handles the override and, at the end of the warning, commands the engine "
   "shutdown.",
   "The only writer of the state word ISST (0x80d674) apart from the initializer, and the only code that sets the "
   "engine shutdown command SHSS from the idle shutdown timer. The other two readers of idle_shutdown_enable only "
   "report: the J1587 PID 71 status byte (0xefa2) and the PGN 65252 payload builder (0x33d38).",
   "standalone",
   "Idle shutdown state machine (e2m 10CD; state ISST 0 RESET / 1 COUNT / 2 WARNING / 3 DELAY / 4 OVERRIDE / 5 "
   "SHUTDOWN), one pass per 100 ms from cm550_runEvery20FramesTaskSetPhase11 while ISAGEN (bit 1 of "
   "algorithm_enable_flags_3_cal) is set and ISTAEN (bit 4 of word 28) is clear. RESET reloads the timer ISTM from "
   "ISTMLM and waits for ISRSFG = 0; COUNT counts ISTM down, returns to RESET on ISRSFG = 1 and enters WARNING "
   "when ISTM is at or below ISWRTMLM (or DELAY, 600 passes before OVERRIDE, when ISAATPEN and ISODFG are set); "
   "WARNING sets ISWRRQ and after "
   "ISWRTMLM passes enters SHUTDOWN, unless ISODEN with ISODFG gives OVERRIDE or ISRSWNFG gives RESET; OVERRIDE "
   "reloads the timer, sets ISOD and ISODRQ and waits for ISODRSFG; SHUTDOWN sets the engine shutdown command "
   "SHSS once and returns to RESET when the engine is CRANKING. The condition flags ISRSFG / ISRSWNFG / ISODRSFG "
   "/ ISODFG have no writer in the dumped ROM; CM848 S90140.06 has no idle shutdown machine.",
   "0x1d9ca-0x1d9d6 andi.l #0x2 on 0x803c9a (beq exit); 0x1d9da-0x1d9e6 andi.l #0x10 on 0x803ccc (bne exit); "
   "0x1d9ea-0x1d9fc state (a3 = 0x80d674) through the jump table 0x1da00 = 000c 0048 00a0 00f8 0122 0148. Case 0 "
   "0x1da0c: move.w 0x803c02,(a4 = 0x80d676), clr.w (a1 = 0x80d67a), clr.w 0x80d672 and 0x80d682, output 30 off "
   "(andi.b #0xbf on 0x80bcf9 while 0x80bd38 is 0), tst.w 0x80d67c -> state 1. Case 1 0x1da48: subq.w #1,(a4), "
   "clr.w 0x800754, move.w #0x258 to 0x800756, 0x80d67c = 1 -> 0, andi.l #0x400 on 0x803cca with 0x80d682 = 1 -> "
   "3, (a4) <= 0x808150 -> 2. Case 2 0x1daa0: subq, move.w #1,(a1), addq.w #1 on 0x800754, andi.l #0x4 on "
   "0x803c9a with 0x80d682 = 1 -> 4, 0x80d67e = 1 -> 0, 0x800754 >= 0x808150 -> 5. Case 3 0x1daf8: subq.w #1 on "
   "0x800756, 0x80d67c = 1 -> 0, timer 0 -> 4. Case 4 0x1db22: timer reload, clr.w (a1), move.w #1 to 0x80d684 "
   "and 0x80d672, 0x80d680 = 1 -> 0. Case 5 0x1db48: when the previous state 0x800752 is not 5: clr.w (a1), move.w "
   "#1 to 0x80d28c, output 30 on (ori.b #0x40); engine_state = 2 -> 0. 0x1db7e stores the entry state in "
   "0x800752. e2m addresses from the parameter ID table (10CD +0..+12, 0008 +66, 10CC +8). Single caller: jsr at "
   "0x1b7f8. CM848: no reader of bits 1 / 2 of algorithm_enable_flags_3_cal (14 reads, masks 0x40 / 0x10 / 0x80 / "
   "0x8000 / 0x100), no reference to Idle_Shutdown_Period 0x3fdd4c, engine_shutdown_command_flag written only by "
   "the engine protection shutdown, cm848_updateEngineState and commandEngineShutdown, no PGN 65252 transmit.",
   "high")

fn("0x000253b0", "cm550_FUN_000253b0", "cm550_flashWarningLampForOilChangeMonitorReset",
   "Flashes the warning lamp three times (5 ticks on, 18 off, per 50 ms tick) to acknowledge a manual reset of the "
   "oil change monitor.",
   "Of the three fixed-pattern flash generators the lamp task calls, this is the one on lamp request bit 0x2 (the "
   "warning lamp), with its own tick counter 0x801a1a and busy flag 0x801a1c, and the one the caller gates with "
   "OCRSFG (0x80dab0); 0x25316 and 0x25448 flash bit 0x4 for OCITWNFG.",
   "standalone",
   "Oil change monitor reset acknowledgement: called every 50 ms by cm550_runLampControl while OCRSFG (e2m 1094 "
   "+12, 'a manual reset was performed on OCM data') is set or a flash cycle is still running. It counts ticks in "
   "0x801a1a and requests the warning lamp (bit 0x2 of lamp_driver_output_bitmask) during ticks 1-5, 24-29 and "
   "48-53, clears the request in between, and at tick 72 clears the busy flag 0x801a1c and restarts the count. "
   "CM848 has no counterpart.",
   "0x253c4 addq.w #1,(a2 = 0x801a1a); 0x253c6-0x253d8 count 1..5: ori.w #0x2,(a1 = 0x80daac) and move.b #1,(a0 = "
   "0x801a1c); 0x253dc-0x253e8 6..23 andi.w #0xfffd; 0x253f0-0x253fc 24..29 on; 0x25404-0x25410 30..47 off; "
   "0x25418-0x25424 48..53 on; 0x2542c-0x25438 54..71 off; 0x25440 clr.b (a0), clr.w (a2). Single caller: jsr at "
   "0x2552a, reached when tst.w 0x80dab0 (0x2551a) or tst.b 0x801a1c (0x25522) is nonzero. Bit 0x2 -> output 6 "
   "(warning lamp, e2m LCWNLPEA / DGLPPZ) in 0x23a90 (0x23b86-0x23bae). CM848: oil_change_monitor_reset_flag "
   "0x40ae60 is used only by cm848_j1939HandlePgn56832Reset and cm848_updateOilChangeMonitor.",
   "high")

fn("0x000254b6", "cm550_FUN_000254b6", "cm550_runLampControl",
   "The lamp control task (every 50 ms): runs the power-up lamp sequence, then by priority the fault code flash "
   "out, the shutdown warning flashes and the active fault lamps, plus the three oil change monitor flash "
   "patterns, and saves the three diagnostic switch states for edge detection.",
   "The single entry of the lamp family from the executive (its only caller is the 10-frame task set 0x1b70c) and "
   "the only function that calls the seven lamp functions and decides their priority; it owns the power-up tick "
   "count 0x801a22 and the switch previous-state bytes 0x8019eb-0x8019ed.",
   "standalone",
   "Lamp control task (Calterm group LAMP_CON), every 50 ms from cm550_runEvery10FramesTaskSetPhase5. While the "
   "power-up lamp sequence is active it only runs cm550_runPowerUpLampSequence; afterwards "
   "cm550_runFaultCodeFlashOut has the stop and warning lamps first, then cm550_flashShutdownWarningLamps, and "
   "only when both are idle cm550_updateActiveFaultLamps. Independently it runs "
   "cm550_flashEngineProtectionLampForOilChangeDueAtPowerUp (passes 100 to 399 after power-up while OCITWNFG is "
   "set), cm550_flashWarningLampForOilChangeMonitorReset (OCRSFG) and "
   "cm550_flashEngineProtectionLampForOilChangeDueWhileRunning (OCRNSTEA and OCITWNFG while RUNNING). Last it "
   "stores the idle increment / idle decrement / diagnostic switch states (bits 0x20 / 0x40 / 0x80 of the switch "
   "byte 0x80bccf) for the next pass's edge detection.",
   "0x254c6 tst.b 0x8019d2 -> jsr 0x24858 and return; 0x254da jsr 0x24d40, tst.b d0; 0x254e4 jsr 0x249ee, tst.b d0; "
   "0x254ee move.b #0x7d to 0x8019e7 and jsr 0x24f30; 0x254fc-0x25502 count (a2 = 0x801a22) up to 0x191; "
   "0x25504-0x25514 0x64 <= count < 0x190 and tst.w (a3 = 0x80daae) -> jsr 0x25316; 0x2551a tst.w 0x80dab0 or "
   "0x25522 tst.b 0x801a1c -> jsr 0x253b0; 0x25530 tst.w 0x803c42, tst.w (a3), cmpi.w #3 on engine_state -> jsr "
   "0x25448; 0x2554c-0x25588 the three sne of 0x80bccf masks 0x20 / 0x40 / 0x80 into 0x8019eb / 0x8019ec / "
   "0x8019ed. Single caller: jsr at 0x1b70c (frames 5 / 15 / 25 / 35). e2m: 1094 +10 OCITWNFG, +12 OCRSFG, 0008 "
   "+A6 OCRNSTEA, DSICSWSS / DSDTSWSS / DSTESWSS masks 0x20 / 0x40 / 0x80 at 000E +1. CM848: the J1939 lamp flags "
   "0x40ae62 / 64 / 66 have no writer and nothing sequences lamps (the cluster does it over the PCI bus).",
   "high")

fn("0x00026834", "mc68k_FUN_00026834", "mc68k_serialEepromQspiInterruptHandler",
   "The QSPI interrupt handler of the serial EEPROM driver: clears the QSPI finished flag, runs one driver step and "
   "restarts the QSPI queue.",
   "It is the interrupt entry (saves d0-d1 / a0-a1 and ends in RTE) and has no caller: 0x26854 stores its address "
   "in the RAM vector 0x808f20 (vector 0x51, the QSPI vector for QIVR 0x50). The driver step itself is 0x266da, "
   "which the boot loader loop of 0x26854 calls directly.",
   "counterpart",
   "QSPI interrupt handler of the serial EEPROM driver (reached through RAM vector 81 at 0x808f20 = VBR 0x808ddc + "
   "4 x 0x51, installed by mc68k_initializeSerialEepromDriverAndLoadMirror; not called). It clears SPIF (QSM_SPSR "
   "bit 7), runs mc68k_runSerialEepromWriteQueue (stores the 12 words just read into the EEPROM mirror and queues "
   "the next read, or sends / polls a queued byte write) and sets SPE (QSM_SPCR1 bit 15) to start the next queue "
   "pass. The counterpart of cm848_onQspiFinished.",
   "0x26834 movem.l d0-d1/a0-a1; 0x26838 andi.b #0x7f on 0xfffc1f; 0x26840 bsr.w 0x266da; 0x26844 ori.w #0x8000 on "
   "0xfffc1a; 0x26850 4e73 rte. Only reference: the immediate of move.l #0x26834,(0x808f20).l at 0x26860. VBR: "
   "movea.l #0x808ddc,a0 and movec a0,VBR (4e7b 8801) at 0x2864a-0x28650; QILR = 0x13 at 0x28664, QIVR = 0x50 at "
   "0x2866c. CM848 0x3dcf4: clears SPSR SPIF then runs the QSPI job completion - the same two steps for every "
   "QSPI job, not only the EEPROM.",
   "high", "0x0003dcf4", "cm848_onQspiFinished")

fn("0x00026854", "mc68k_FUN_00026854", "mc68k_initializeSerialEepromDriverAndLoadMirror",
   "Start-up of the serial EEPROM driver: installs the QSPI interrupt handler, sets up the QSPI and its read queue, "
   "loads the whole EEPROM (0x148a bytes) into the RAM mirror at 0x803b0a by polling, then switches to interrupt "
   "mode with the refresh length 0x64c.",
   "The only function that writes the QSM / QSPI configuration for the EEPROM (PQSPAR, DDRQS, SPCR0-2, the command "
   "RAM) and the driver's length word 0x801a88, and the only place the driver step runs by polling (with both "
   "watchdogs serviced in the loop).",
   "counterpart",
   "Start-up of the serial EEPROM driver, called once by mc68k_applicationMain after the QSM interrupt set-up. It "
   "stores mc68k_serialEepromQspiInterruptHandler in RAM vector 0x808f20, configures the QSPI (master, 16 bits, "
   "queue entries 2 to 15: READ, the address, 12 data words), sets ram_refresh_enable (e2m 10C7 RREN) and the "
   "mirror base 0x803b0a, and with the length 0x148a runs the queue by polling (mc68k_runSerialEepromWriteQueue "
   "after each pass, both watchdogs serviced) until the mirror is loaded. Then it enables the QSPI interrupt and "
   "sets the length to 0x64c, so the driver keeps refreshing RAM 0x803b0a-0x804155 (the _cal range) from the "
   "EEPROM. The counterpart of cm848_initEepromDriverAndLoadMirror.",
   "0x2685e bsr.s 0x26852 (a lone rts); 0x26860 move.l #0x26834,(0x808f20).l; 0x2686a-0x268c2 PQSPAR 0x7b, DDRQS "
   "0xfe, PORTQS 0xff, SPCR0 0x8004, SPCR2 NEWQP 2 / ENDQP 15, SPCR1 DSCKL 0x10 / DTL 1; 0x268ca-0x26930 TR0-1 = 0 "
   "/ CR 0x7e, TR2 = 3 / CR 0xbd, TR3 = (0x801a86) / CR 0xfd, TR4-15 = 0 / CR 0xfd; 0x26932 move.w #1 to 0x80dc6c; "
   "0x2693a clr.l 0x801a8a; 0x26940 move.l #0x803b0a to 0x801a8e; 0x2694a-0x2695a (0x804f94 - 0x803b08) - 2 = "
   "0x148a to (a2 = 0x801a88); loop 0x2695e-0x269b8: andi.b #0x7f SPSR, ori.w #0x8000 SPCR1, wait SPSR bit 7 and "
   "CPTQP = 15, bsr.w 0x266da, 0x55 / 0xaa to 0xfffa27 and 0xffd00f, until tst.b 0x801a92; 0x269ba-0x269d2 DTL "
   "0x23, SPCR2 bit 15 (SPIFIE), SPE; 0x269da-0x269ea (0x804156 - 0x803b08) - 2 = 0x64c. Single caller: jsr at "
   "0x28674. Dump: offset 0x4c8, length 0x64c, state 0, base 0x803b0a, loaded 1. CM848 0x4cb64 sets the same "
   "variables in the same order (ram_refresh_enable, load offset, write state 0, mirror base, load length 0x1a40, "
   "loop until the loaded flag, then length 0x8e8) but through QSPI job slots, with no vector store and with the "
   "block checksum added.",
   "high", "0x0004cb64", "cm848_initEepromDriverAndLoadMirror")

fn("0x00026e2c", "cm550_FUN_00026e2c", "cm550_calculateEngineLoadLowHorsepowerCurvePercent",
   "Calculates the percent load based on the low horsepower torque curve: (final fueling - no load fueling) x 25600 "
   "/ (low horsepower curve 100 percent throttle fueling - no load fueling), or 0.",
   "The only writer of SPT0PCLD (0x80db62) and the only reader of FST0MXFL (0x80d36a) in the dumped ROM; its "
   "sibling 0x26cc8, called just before it, writes the other two percent load words FSPCLD and JCPCLD from the "
   "normal 100 percent throttle fueling.",
   "counterpart",
   "Percent load on the low horsepower torque curve (e2m 10BF +4 SPT0PCLD, 1/256 percent), once per 100 ms from "
   "cm550_runEvery20FramesTaskSetPhase3. When the final fueling FSFNFL and the low horsepower curve 100 percent "
   "throttle fueling FST0MXFL (105A +2) are both above the no load fueling NLFL it stores (FSFNFL - NLFL) x 25600 "
   "/ (FST0MXFL - NLFL), else 0; it does not clamp the result. The counterpart of CM848 0x50e000 "
   "(cm848_validateFuelDemandRelativeToTiming, a wrong name), which runs the same steps on the same four records "
   "and adds a clamp at 0xff00.",
   "CM550: 0x26e48-0x26e4c move.w (a0 = 0x80d32e),d0 / cmp.w (a2 = 0x80db1c) / bls 0x26e7e; 0x26e4e-0x26e52 the "
   "same test of (a1 = 0x80d36a); 0x26e54-0x26e5a the two differences; 0x26e5c-0x26e6c x 25600 (x 3, << 3, + 1, "
   "<< 8, << 2); 0x26e72 divu.l; 0x26e76 move.w d0,(a3 = 0x80db62); 0x26e7e clr.w (a3). CM848: 0x50e010-0x50e024 "
   "final_fueling 0x40a2ce <= no_load_fuel_quantity 0x40aeec -> 0; 0x50e028-0x50e034 "
   "throttle_100_fueling_low_horsepower_curve 0x40a899 (lha) <= no load -> 0; 0x50e038-0x50e060 difference x "
   "25600 (li r10,25600 at 0x50e040) / difference (bl 0x571b0); 0x50e068-0x50e074 clamp 0xff00 (CM848 only); "
   "0x50e088 sth to engine_load_low_horsepower_curve_percent 0x40af26. Same position: the call after the percent "
   "load function in the 20-frame task set of executive frames 3 / 23 (CM550 jsr at 0x1b79a; CM848 "
   "cm848_periodicTaskGroup28_calibration10). One step more in CM848, so not a twin by the strict rule.",
   "high", "0x0050e000", "cm848_validateFuelDemandRelativeToTiming")

# ------------------------------------------------------------------------------- the lamp callees of 0x254b6
fn("0x00024858", "cm550_ioControlMaskStateMachine", "cm550_runPowerUpLampSequence",
   "Runs the power-up lamp sequence: first pass switches every output of the sequence table on, then switches them "
   "off one by one on a tick schedule and at the end releases them.",
   "The only reader of the table LCLPTB (ROM 0x611a8, 'power-up lamp sequence order') and the only function that "
   "takes the override priority 0x80 on the lamp outputs; it runs instead of every other lamp function while "
   "0x8019d2 is set. The old name fits nothing in it: no I/O control mask, no state word.",
   "standalone",
   "Power-up lamp sequence (e2m 1006 +8 LCLPTB, 16 output numbers), every 50 ms from cm550_runLampControl while "
   "the sequence flag 0x8019d2 is set (cm550_startPowerUpLampSequence sets it). First pass: every table output "
   "whose override priority is at most 0x80 gets priority 0x80 and is switched on; the first switch-off is due at "
   "tick 40. At each due tick the current table output goes off and the next one is due 10 ticks later; after "
   "the last entry (a 0 entry or the table end) one more step follows 30 ticks later, then every table output's "
   "priority is released, the flag is cleared and the three switch previous-state bytes are zeroed.",
   "Decompiled body and the constants in the ROM: first pass flag 0x8019d3; loop over 0x611a8..0x611c6 with "
   "priority[n] = 0x80bd1a + n compared with 0x81, image byte 0x80bcf6 + (n >> 3), bit n & 7; threshold 0x8019f8 "
   "= 0x28, pointer 0x8019f4 = 0x611a8; later passes: tick 0x8019f0 + 1, at the threshold bit cleared, pointer + "
   "2, threshold + 10; end: flag 0x8019d4 then threshold + 0x1e, second time + 10, priorities 0, 0x8019d2 = 0, "
   "0x8019eb-0x8019ed = 0. Single caller: jsr at 0x254ce. LCLPONTM scale 50 ms per count confirms the 50 ms tick.",
   "high")

fn("0x000249ee", "vp44_ioControlLampStateMachine", "cm550_flashShutdownWarningLamps",
   "Flashes the warning lamp while the idle shutdown warning is requested, the stop lamp while an engine "
   "protection shutdown is approaching, and the warning lamp 120 times after an idle shutdown override; returns 1 "
   "when none of the three is active.",
   "The only reader of the two idle shutdown lamp requests ISWRRQ (0x80d67a) and ISODRQ (0x80d684) outside the "
   "state machine and the J1587 status, and the only lamp function that reads EPSQ (0x80d28e); it clears ISODRQ "
   "itself after the 120 flashes. Nothing in it concerns the VP44 pump or I/O control.",
   "standalone",
   "Shutdown warning flashes, every 50 ms from cm550_runLampControl. While ISWRRQ (idle shutdown approaching) is "
   "set it flashes the warning lamp (request bit 0x2) with the on / off times LCLPONTM / LCLPFFTM; while EPSQ "
   "(engine protection shutdown approaching, e2m 10B1 +14) is set it flashes the stop lamp (bit 0x1) the same way; "
   "ISODRQ = 1 (idle shutdown overridden) latches a run of 120 flashes of the warning lamp, 10 ticks on and 10 "
   "off, after which it clears ISODRQ. It returns 0 while any of the three is active, which keeps "
   "cm550_updateActiveFaultLamps from running.",
   "Decompiled body: ISWRRQ branch on 0x80d67a with phase 0x8019dc, LCLPONTM 0x611a0 / LCLPFFTM 0x611a2, flag "
   "0x8019e0; EPSQ branch on 0x80d28e with phase 0x8019da, flag 0x8019e1; ISODRQ branch on 0x80d684 (cmpi.w #1 at "
   "0x24adc) with latch 0x8019e2, phase values 10 / 0x13, cycle count 0x8019e3 compared with 0x77, clr.w 0x80d684 "
   "at 0x24b40. Single caller: jsr at 0x254e4 (its result tested at 0x254ea). Request bits 0x1 / 0x2 -> outputs 1 "
   "/ 6 (stop engine lamp / warning lamp) in 0x23a90.",
   "high")

fn("0x00024d40", "cm550_faultCodeDisplayController", "cm550_runFaultCodeFlashOut",
   "Runs the fault code flash out: with the diagnostic switch on and the engine stopped it picks the active fault "
   "to show (switch edges or automatic mode) and flashes its code on the warning and stop lamps; returns 1 when "
   "the mode is off.",
   "The only reader of the diagnostic test switch bit (0x80 of the switch byte 0x80bccf) together with the idle "
   "increment / decrement edges, and the only caller of the next / previous fault selectors and of the digit "
   "flasher. The old name fits loosely (it does control which fault code is shown), but the code flashes lamps - "
   "there is no display - and Calterm calls the feature fault flash.",
   "standalone",
   "Fault code flash out (e2m 13EF LCFUFHMD automatic fault flash mode / LCFUFHCU fault flash count), every 50 ms "
   "from cm550_runLampControl. Active only while the diagnostic test switch (DSTESWSS) is on and engine_state is "
   "STOPPED; otherwise it clears the stop and warning lamp requests once and returns 1. A rising edge of the "
   "diagnostic switch starts with the first active fault, the idle increment / decrement switches step to the "
   "next / previous one, and in automatic mode each code is repeated LCFUFHCU times before the next. With no "
   "fault to show (index 125) it requests both lamps on, else it calls cm550_flashFaultCodeDigits with the "
   "fault's Cummins code (fault data record 0x8067c4 + 6 x index).",
   "Decompiled body: gate (0x80bccf & 0x80) and engine_state == 1, active flag 0x8019e8, andi 0xfffc on 0x80daac; "
   "edges against the previous-state bytes 0x8019ed (diagnostic), 0x8019eb (0x20, idle increment), 0x8019ec (0x40, "
   "idle decrement); cm550_FUN_00024c5a / cm550_FUN_00024cd2 return 0x7d for none; automatic branch on 0x80820c "
   "and 0x80820d with the repetition count 0x8019ea and the cycle-complete byte 0x8019e9; 0x7d -> ori 3; else "
   "cm550_ioControlDigitDisplaySequencer(word at 0x8067c4 + 6 x index). Single caller: jsr at 0x254da (result "
   "tested at 0x254e0). e2m switch masks DSTESWSS 0x80, DSICSWSS 0x20, DSDTSWSS 0x40 at 000E +1.",
   "high")

fn("0x00024f30", "cm550_activeFaultLampStateMachine", "cm550_updateActiveFaultLamps",
   "Scans the active fault list and requests the stop, warning and engine protection (fluids) lamps their fault "
   "definitions ask for, steady or flashing, and sets the three J1939-73 lamp flags.",
   "The only writer of LCDGSTLP / LCDGWNLP / LCDGFDLP (0x80dab2 / 4 / 6) and the only lamp function that reads "
   "active_dtc_list with the fault definition flag bits 0x1 / 0x2 / 0x4 / 0x8 / 0x40 and the per-fault lamp "
   "suppress bitmap 0x803fb6. It keeps no state word, so it is not a state machine.",
   "standalone",
   "Active fault lamps, every 50 ms from cm550_runLampControl when neither the fault code flash out nor a shutdown "
   "warning flash is active. For each fault of active_dtc_list whose definition flags (e2m 000F fault control "
   "bits, 0x8067c6 + 6 x index) do not have 0x40 and whose bit in the bitmap 0x803fb6 is clear, the first of 0x1 "
   "(stop lamp) / 0x2 (warning lamp) / 0x4 (fluids lamp) picks the lamp and 0x8 asks for flashing. It sets "
   "LCDGSTLP / LCDGWNLP / LCDGFDLP (the lamp flags of the J1939 DM1 lamp status) and the lamp request bits 0x1 / "
   "0x2 / 0x4: flashing with LCLPONTM / LCLPFFTM, else steady on, else off.",
   "Decompiled body: clr.w 0x80dab2 / 0x80dab4 / 0x80dab6 (0x24f5e-0x24f6a), loop 1..active_dtc_list[0] "
   "(0x8058d4), flag word at fault_definition_flags_word 0x8067c6 + 6 x index masks 1 / 2 / 4 / 8 / 0x40, bitmap "
   "byte 0x803fb6 + (index >> 3) bit index & 7, move.w #1 to 0x80dab2 (0x25010) / 0x80dab4 (0x250e6) / 0x80dab6 "
   "(0x251b8); then three blocks on 0x80daac bits 1 / 2 / 4 with the phases 0x8019da / 0x8019dc / 0x8019de and "
   "0x611a0 / 0x611a2. Single caller: jsr at 0x254f6. CM848 reads the three flags (0x40ae62 / 64 / 66) in "
   "cm848_buildJ1939LampStatusByte but has no writer for them.",
   "high")

fn("0x00025316", "cm550_faultLampBlinkPatternGenerator", "cm550_flashEngineProtectionLampForOilChangeDueAtPowerUp",
   "Flashes the engine protection (fluids) lamp in five groups of three short flashes; the lamp task calls it only "
   "between passes 100 and 399 after power-up while the oil change monitor says the oil change is due.",
   "The flash generator on lamp request bit 0x4 with the group counter 0x801a16 (stops after 5 groups) and the "
   "tick counter 0x801a18; its caller gates it with the power-up tick window and OCITWNFG. It reads no fault, so "
   "the old name is wrong.",
   "standalone",
   "Oil change due indication at power-up: called every 50 ms by cm550_runLampControl while its power-up tick "
   "count is 100 to 399 and OCITWNFG (e2m 1094 +10, 'time to change oil') is set. While the group count 0x801a16 "
   "is below 5 it counts ticks in 0x801a18 and requests the engine protection lamp (bit 0x4 of "
   "lamp_driver_output_bitmask, output 4) during ticks 1-5, 12-17 and 24-29, clears the request in between up to "
   "tick 47, then restarts the ticks and adds 1 to the group count: three flashes, five times.",
   "Decompiled body: _DAT_00801a16 < 5; 0x801a18 + 1; windows < 6 on, < 0xc off, < 0x12 on, < 0x18 off, < 0x1e on, "
   "< 0x30 off, else tick = 0 and 0x801a16 + 1; ori.w #4 / andi.w #0xfffb on 0x80daac. Single caller: jsr at "
   "0x25514 after cmpi.w #0x64 / #0x190 on 0x801a22 and tst.w 0x80daae (0x25504-0x25512). Bit 0x4 -> output 4 "
   "(e2m EPLPPZ 'engine protection lamp', LCEGPNLP mask 0x10) in 0x23a90 (0x23ad4-0x23afc).",
   "high")

fn("0x00025448", "cm550_periodicLampFlashController", "cm550_flashEngineProtectionLampForOilChangeDueWhileRunning",
   "Every 36000 ticks (30 minutes) flashes the engine protection (fluids) lamp four times; the lamp task calls it "
   "only while the oil change is due, the running warning is enabled and the engine is running.",
   "The flash generator on lamp request bit 0x4 with the wait / flash flag 0x801a1d, the tick counter 0x801a1e "
   "(compared with 36000) and the flash count 0x801a20; its caller gates it with OCRNSTEA, OCITWNFG and "
   "engine_state RUNNING.",
   "standalone",
   "Oil change due reminder while running: called every 50 ms by cm550_runLampControl while OCRNSTEA (e2m 0008 +A6 "
   "'enables use of warning light with engine in run state'), OCITWNFG and engine_state RUNNING hold. It waits "
   "36000 ticks (30 minutes), then requests the engine protection lamp (bit 0x4 of lamp_driver_output_bitmask) "
   "for ticks 1-19 of each 80-tick cycle, four cycles, and returns to waiting.",
   "Decompiled body: DAT_00801a1d == 0: 0x801a1e + 1, > 36000 -> flag 1, tick 0; else tick + 1: 1..0x13 ori.w #4, "
   "0x14..0x4f andi.w #0xfffb, 0x50 -> 0x801a20 + 1 and tick 0; 0x801a20 > 3 -> flag 0, counters 0. Single "
   "caller: jsr at 0x25546 after tst.w 0x803c42 (0x25530), tst.w 0x80daae (0x25538) and cmpi.w #3 on "
   "engine_state (0x2553c).",
   "high")

# ----------------------------------------------------------------------------------------------- other siblings
fn("0x0001b70c", "cm550_dzgTimingAndPressureSlowCycle10Coordinator", "cm550_runEvery10FramesTaskSetPhase5",
   "Executive frame task set: calls the lamp control task in frames 5, 15, 25 and 35 of the 40-frame cycle (every "
   "50 ms).",
   "Its position in the dispatch: the fifth call (the 10-frame set) of executive frames 5 / 15 / 25 / 35 (bsr.w at "
   "0x1ba24, 0x1bb86, 0x1bcd0, 0x1be02), and a single jsr to 0x254b6. Nothing in it concerns timing or pressure.",
   "counterpart",
   "Executive frame task set: runs every 10 frames (50 ms), in frames 5, 15, 25 and 35 of the 40-frame cycle, as "
   "call 5 of those frames in executiveFrameInterruptHandler. Calls, in order: cm550_runLampControl. CM848's slot "
   "mate is cm848_periodicTaskGroup17_calibration5, with a different task list.",
   "0x1b70c jsr 0x254b6 / 0x1b712 rts. Callers: frame 5 code 0x1ba16 (table 0x1b90e + 0x108), frame 15 0x1bb78 (+ "
   "0x26a), frame 25 0x1bcc2 (+ 0x3b4), frame 35 0x1bdf4 (+ 0x4e6). HEAD (commit 7cf52470) already carries this "
   "name. CM848 executive cases 5 / 0xf / 0x19 / 0x23 call cm848_periodicTaskGroup17_calibration5 in the same "
   "position.",
   "high", "0x0000bd08", "cm848_periodicTaskGroup17_calibration5")

fn("0x0001db8a", "vp44_FUN_0001db8a", "cm550_initializeIdleShutdown",
   "Start-up initialization of the idle shutdown state machine: state RESET, timer reloaded, lamp requests and "
   "flags cleared, the reset flag set, the engine shutdown command cleared and output 30 switched off.",
   "The only writer of the idle shutdown records outside the state machine, and the only place that writes ISRSFG "
   "(= 1) in the dumped ROM; it is called once from the start-up list of mc68k_applicationMain, not from the "
   "executive.",
   "standalone",
   "Start-up initialization of the idle shutdown state machine (e2m 10CD), called from the start-up list of "
   "mc68k_applicationMain. It clears ISOD, sets the timer ISTM to ISTMLM, the state ISST to 0 (RESET), clears "
   "ISWRRQ and ISODRQ, sets ISRSFG to 1, clears ISODFG and the engine shutdown command SHSS, and switches output "
   "30 off unless a client overrides it.",
   "0x1db8a clr.w 0x80d672; 0x1db90 move.w 0x803c02 to 0x80d676; 0x1db9a clr.w 0x80d674; 0x1dba0 clr.w 0x80d67a; "
   "0x1dba6 clr.w 0x80d684; 0x1dbac move.w #1 to 0x80d67c; 0x1dbb4 clr.w 0x80d682; 0x1dbba clr.w 0x80d28c; "
   "0x1dbc0-0x1dbce tst.b 0x80bd38, andi.b #0xbf on 0x80bcf9; 0x1dbd6 rts. Single caller: jsr at 0x287bc. (The "
   "frozen row 0x1db9a is mid-body.)",
   "high")

fn("0x0000af70", "cm550_FUN_0000af70", "cm550_initializeDutyCycleMonitor",
   "Start-up initialization of the duty cycle monitor: builds the two 2D lookup records for the 100 percent "
   "throttle fueling and converts the stored short term maps (minutes) into the processing maps (0.1 s ticks).",
   "The only writer of the two lookup records (0x800010 / 0x800026) and of the short term period words 0x800006 "
   "/ 0x80000a; it converts stored -> processing (x 600), the direction opposite to 0xb130.",
   "standalone",
   "Start-up initialization of the duty cycle monitor, called from the start-up list of mc68k_applicationMain. It "
   "points the two 2D lookup records at the steady state and transient 4D fueling tables with the throttle input "
   "400 (100 percent), sets the short term period to DCMNSHTI x 36000 ticks (and x 60 minutes), and converts the "
   "stored short term map totals DCMP01TL / DCMP02TL and the 50 region words of each stored map (DCMNMP01 / "
   "DCMNMP02, minutes) into the processing totals and counters (DCPR01TL / DCPR02TL, DCSHPR01 / DCSHPR02, x 600; "
   "a total at or over the period becomes the period).",
   "0xaf80-0xafe0 the two records (a1 = 0x800010, a4 = 0x800026): +6 = 0x807d1a, +2 = 0x6086e / 0x6094c, +0 = 2, "
   "+0xe = 0x190, +0xa = 0x6089a / 0x60978, +8 = 2, +0x10 = 0x608a4 / 0x60982 (e2m 1055 / 1054 / 1056 5DFL01 and "
   "1058 / 1057 / 1059 5DFL00); 0xafe8-0xb002 0x807d1c x 36000 to 0x800006; 0xb008-0xb016 x 60 to 0x80000a; "
   "0xb01c-0xb096 totals 0x805394 / 0x805396 -> 0x80bacc / 0x80bad0 (x 36000 / 60); 0xb09c-0xb0b2 byte counts; "
   "0xb0b8-0xb128 regions 1..50: words at 0x80539e / 0x805406 + 2 x region -> dwords from 0x80bade / 0x80bbac. "
   "Single caller: jsr at 0x28822. CM848: only cm848_updateDutyCycleMonitorLoadHistogram touches its monitor's "
   "variables (no short term maps, counters kept in the EEPROM mirror).",
   "high")

fn("0x0000b130", "cm550_writeHourMeterConversionData", "cm550_storeDutyCycleMonitorShortTermMaps",
   "Converts the duty cycle monitor's short term processing maps and totals (0.1 s ticks) back into the stored "
   "maps (minutes, rounded), at power-down.",
   "The only writer of the stored short term map totals and words (0x805394 / 0x805396, 0x80539e.. / 0x805406..); "
   "it converts processing -> stored ((ticks x 60 + 18000) / 36000), the direction opposite to 0xaf70. It writes "
   "no hour meter.",
   "standalone",
   "Stores the duty cycle monitor's short term maps: called by mc68k_applicationMain after the background loop "
   "ends (power-down), with interrupts masked. Each processing total (DCPR01TL / DCPR02TL) becomes the stored "
   "total DCMP01TL / DCMP02TL in minutes ((ticks x 60 + 18000) / 36000, or the period in minutes when the map is "
   "full), and the 50 region counters of each processing map (DCSHPR01 / DCSHPR02) become the words of the "
   "stored maps DCMNMP01 / DCMNMP02 the same way.",
   "0xb140-0xb172 0x80bacc against 0x800006: move.w (a1 = 0x80000a) to 0x805394, else (x 60 + 0x4650) / 0x8ca0; "
   "0xb178-0xb1a2 the same for (a4 = 0x80bad0) and 0x805396; 0xb1a8-0xb208 regions 1..50 from 0x80bade / 0x80bbac "
   "to 0x80539e / 0x805406 + 2 x region. Single caller: jsr at 0x289f4, after the loop that waits on 0x80d0ca and "
   "ori.w #0x700,sr at 0x289ea.",
   "high")

fn("0x00026cc8", "calculateSpeedRatioComponent", "cm550_calculateEngineLoadPercentages",
   "Calculates the two percent load words: FSPCLD = fueling above no load over the 100 percent throttle fueling, "
   "and JCPCLD = the same fueling over what is available at the current engine speed (the high speed governor "
   "droop line above its derate speed), each in 1/256 percent.",
   "The only writer of FSPCLD (0x80db60) and JCPCLD (0x80db5e); its sibling 0x26e2c, called right after it, writes "
   "the third percent load word from the low horsepower curve fueling. Nothing in it is a speed ratio, and CM848 "
   "has no function of this name.",
   "counterpart",
   "Percent load calculation (e2m 10BF +2 FSPCLD and +0 JCPCLD, 1/256 percent), once per 100 ms from "
   "cm550_runEvery20FramesTaskSetPhase3. FSPCLD = (FSFNFL - NLFL) x 25600 / (FSMXTHFL - NLFL), clamped at 0x7f80, "
   "0 when either fueling is not above NLFL. JCPCLD uses as its denominator the fueling available at the current "
   "speed: above the high speed governor derate speed with droop active the droop line (clamped at 0x1700) minus "
   "NLFL, else FSMXTHFL - NLFL; it is clamped at 0x7f80 and forced to 0x6400 (100 percent) while "
   "final_fueling_state is HIGH_SPEED_GOVERNOR. The counterpart of cm848_calculateEngineLoadPercentages.",
   "0x26ce8-0x26cf2 guards (a5 = 0x80d32e) and (a4 = 0x80d368) above (a2 = 0x80db1c); 0x26cf4-0x26d10 "
   "cm550_scaleByRatio(FSFNFL - NLFL, 0x6400, FSMXTHFL - NLFL); 0x26d18-0x26d32 clamp 0x7f80 and move.w to "
   "0x80db60, else clr.w; 0x26d4a-0x26d5e speed 0x80ccf6 above 0x80d654 with the droop flag 0x80d656; "
   "0x26d72-0x26dd2 the droop line: x 0x1111, slope 0x80d652, full fueling 0x80d36c, clamp 0x1700; "
   "0x26de0-0x26e12 x 25600 against denominator x 0x7f80, divu.l, move.w to (a3 = 0x80db5e); 0x26e14 cmpi.w "
   "#0xc on final_fueling_state 0x80d330 -> move.w #0x6400. Single caller: jsr at 0x1b794. CM848 0x50de54: the same "
   "constants (0x6400, 0x7f80, 0x1111, 0x1700) and outputs (10BF +2 / +0), with chi maximum fueling as the full "
   "load reference and a revised control flow in the second half - a counterpart.",
   "high", "0x0050de54", "cm848_calculateEngineLoadPercentages")

fn("0x00023a90", "processProtectionFlagConditions", "cm550_applyLampRequestsToOutputs",
   "Copies each bit of the lamp request word to its discrete output in the output image, skipping any output a "
   "client is overriding.",
   "The only reader of every bit of the lamp request word 0x80daac as a whole and the place that fixes which lamp "
   "each bit is: 0x01 output 1, 0x02 output 6, 0x04 output 4, 0x08 output 0, 0x10 output 2, 0x20 and 0x40 output "
   "30. It tests no protection condition and CM848 has no function of this name.",
   "standalone",
   "Lamp output update: for each bit of lamp_driver_output_bitmask it sets or clears the matching bit of the "
   "output image while that output's override priority byte (0x80bd1a + output number) is 0. 0x01 -> output 1 "
   "(stop engine lamp), 0x02 -> output 6 (warning lamp), 0x04 -> output 4 (engine protection lamp), 0x08 -> output "
   "0 (wait to start lamp), 0x10 -> output 2 (water in fuel lamp), 0x20 and then 0x40 -> output 30 (so bit 0x40 "
   "decides it).",
   "0x23aa6-0x23ad0 andi.w #0x20 -> ori / andi 0x40 on 0x80bcf9 under (a1 = 0x80bd1a + 30); 0x23ad4-0x23afc #0x4 "
   "-> bit 0x10 of (a4 = 0x80bcf6) under 4(a3); 0x23b00-0x23b26 #0x40 -> output 30 again; 0x23b2a-0x23b50 #0x1 -> "
   "bit 0x02 under 1(a3); 0x23b54-0x23b82 #0x8 -> bit 0x01 under 0x80bd1a; 0x23b86-0x23bae #0x2 -> bit 0x40 "
   "under 6(a3); 0x23bb2-0x23bde #0x10 -> bit 0x04 under 2(a3). Priority names from e2m 12A7 +0 WASTLPPZ, +1 "
   "STEGLPPZ, +2 WFLPPZ, +4 EPLPPZ, +6 DGLPPZ. Called from cm550_FUN_00024804 (the 10-frame task set of frames 6 "
   "/ 16 / 26 / 36).",
   "high")

fn("0x0002482e", "cm550_ioControlMaskInit", "cm550_startPowerUpLampSequence",
   "Arms the power-up lamp sequence: sets the sequence-active and first-pass flags and clears the sequence tick "
   "count and the fault flash counters.",
   "The only writer that sets 0x8019d2 (the flag that makes the lamp task run only the power-up sequence); called "
   "from the start-up list and from the application's restart entry, not from the executive.",
   "standalone",
   "Arms the power-up lamp sequence: sets the sequence flag 0x8019d2 and the first-pass flag 0x8019d3, clears the "
   "end flag 0x8019d4, the sequence tick count 0x8019f0 and the fault flash cycle-complete byte and repetition "
   "count. Called from the start-up list of mc68k_applicationMain and from "
   "cm550_restartApplicationWithoutReset; cm550_runPowerUpLampSequence then runs the sequence.",
   "Decompiled body: DAT_008019d2 = 1, DAT_008019d3 = 1, DAT_008019d4 = 0, 0x8019e9 = 0, 0x8019ea = 0, "
   "_DAT_008019f0 = 0. Callers: jsr at 0x287c2 (start-up list) and 0x2898a (restart entry 0x28978).",
   "high")

fn("0x000249b6", "cm550_ioControlToggleCycle", "cm550_runStopLampFlashCycle",
   "One step of a single stop lamp flash: lamp request on at tick 0, off at tick 10, and at tick 20 it restarts the "
   "tick count and returns 1.",
   "The 20-tick on / off cycle on lamp request bit 0x1 with its own counter 0x8019d8; the digit flasher calls it "
   "once per pass and counts its completed cycles as the flashes of one digit.",
   "standalone",
   "One flash of the stop lamp for the fault code flash out: at count 0 it sets request bit 0x1 of "
   "lamp_driver_output_bitmask, at count 10 it clears it, at count 20 it zeroes the count and returns 1; otherwise "
   "it adds 1 to the count 0x8019d8 and returns 0. cm550_flashFaultCodeDigits counts the returned 1s as the "
   "flashes of the current digit.",
   "Decompiled body: _lamp_toggle_cycle_counter (0x8019d8) == 0 -> ori 1 on 0x80daac; == 10 -> andi 0xfffe; == "
   "0x14 -> counter 0, return 1; counter + 1. Callers: the three digit branches of 0x24b4e.",
   "high")

fn("0x00024b4e", "cm550_ioControlDigitDisplaySequencer", "cm550_flashFaultCodeDigits",
   "Flashes one three-digit fault code: the warning lamp on for 40 ticks, then the stop lamp flashes the hundreds, "
   "the tens and the ones digit with 40-tick gaps, then it marks the cycle complete.",
   "The only function that splits its argument into three decimal digits (0x8019e4 / e5 / e6) and steps the "
   "display phase 0x8019d6 through 0x28 / 0x50 / 0x78 / 0xa0; the caller passes the Cummins fault code of the "
   "selected fault.",
   "standalone",
   "Flashes one Cummins fault code on the lamps for cm550_runFaultCodeFlashOut (argument: the code, 0 to 999). "
   "Phase 0: stop lamp request off, warning lamp request on, and the code is split into hundreds / tens / ones. "
   "At phase 40 the warning lamp goes off and cm550_runStopLampFlashCycle flashes the stop lamp once per hundreds "
   "count; at phases 80 and 120 the tens and ones follow; at phase 160 the phase restarts and the cycle-complete "
   "byte 0x8019e9 is set.",
   "Decompiled body: phase 0x8019d6 == 0: 0x80daac & 0xfffe | 2, digits fault_code / 100, / 10 % 10, % 10 into "
   "0x8019e4 / 0x8019e5 / 0x8019e6; == 0x28 / 0x50 / 0x78: blink counter 0x8019ee against the digit, "
   "cm550_ioControlToggleCycle; == 0xa0: phase 0, 0x8019e9 = 1; else phase + 1. Single caller: the last call of "
   "0x24d40.",
   "high")

fn("0x00024c5a", "cm550_FUN_00024c5a", "cm550_selectNextFaultToFlash",
   "Returns the next active fault (stepping the navigation index forward through the active fault list, wrapping) "
   "whose definition allows a lamp, or 125 when there is none.",
   "The forward twin of 0x24cd2: it adds 1 to fault_list_navigation_index (wrapping to 1 past the count), where "
   "0x24cd2 subtracts 1 (wrapping to the count). Both skip faults whose definition flag 0x40 is set.",
   "standalone",
   "Fault code flash out helper: steps fault_list_navigation_index forward through active_dtc_list (restarting at "
   "entry 1 when the argument is 125 = none, or past the end) and returns the first fault index whose definition "
   "flags do not have 0x40; returns 125 when the list is empty or every fault is excluded.",
   "Decompiled body: active_dtc_list[0] != 0; loop at most count times; argument 0x7d or index + 1 > "
   "_active_fault_list_count -> index 1; fault = active_dtc_list[index]; (flag word at 0x8067c6 + 6 x fault) & "
   "0x40 == 0 -> return; else 0x7d. Callers: three sites in 0x24d40 (diagnostic switch edge, idle increment "
   "edge, automatic mode).",
   "high")

fn("0x00024cd2", "cm550_FUN_00024cd2", "cm550_selectPreviousFaultToFlash",
   "Returns the previous active fault (stepping the navigation index backward through the active fault list, "
   "wrapping) whose definition allows a lamp, or 125 when there is none.",
   "The backward twin of 0x24c5a: it subtracts 1 from fault_list_navigation_index and wraps to the list count at "
   "0. Called only for the idle decrement switch edge.",
   "standalone",
   "Fault code flash out helper: steps fault_list_navigation_index backward through active_dtc_list (restarting at "
   "the last entry when the argument is 125 = none, or below 1) and returns the first fault index whose "
   "definition flags do not have 0x40; returns 125 when the list is empty or every fault is excluded.",
   "Decompiled body: as 0x24c5a with index - 1 and index == 0 -> _active_fault_list_count. Caller: the idle "
   "decrement branch of 0x24d40.",
   "high")

fn("0x000266da", "mc68k_runSerialEepromWriteQueue", "mc68k_runSerialEepromDriver",
   "One step of the serial EEPROM driver after a QSPI queue pass: in the read state it stores the 12 words just "
   "read into the RAM mirror and sets the next read address; with a write queued it sends write enable + one "
   "byte write and then polls the status register until the write is done.",
   "The only code that touches the QSPI transmit / receive RAM for the EEPROM after start-up and the only user of "
   "the state dword 0x801a8a. Its current name covers states 1 and 2 only; state 0, the normal one, is the read "
   "stream that loads and refreshes the EEPROM mirror.",
   "standalone",
   "Serial EEPROM driver step, run after each QSPI queue pass (by mc68k_serialEepromQspiInterruptHandler, and by "
   "polling during the start-up load). State 0 (eeprom_byte_write_state): while ram_refresh_enable is set it "
   "copies the 12 received words to the mirror (eeprom_mirror_base_pointer + eeprom_mirror_load_offset), wraps "
   "the offset at eeprom_mirror_load_length (setting eeprom_mirror_loaded_flag) and queues the next READ; when "
   "the write queue is not empty it goes to state 1. State 1 sends command 6 (write enable) and command 2 "
   "(write) with the next queue entry (address word 0x80BDA8 + 2 x read index, data byte 0x80C7A8 + index). State "
   "2 sends command 5 (read status) until the write-in-progress bit is clear, then continues with the next write "
   "or returns to reading at the saved offset.",
   "0x266ea-0x266ee cmp.l #2,(a1 = 0x801a8a): 0x266fc-0x2671c TR2 = 5 / CR2 0xbd ...; 0x26720 RR3 (0xfffd06) & 1; "
   "0x26730 tst.w 0x80ccac -> state 1 else clr.l (a1), move.w 0x80ccb0,(a4 = 0x801a86), TR2 = 3, TR3 = offset. "
   "0x26756 tst.l (a1) (state 0): a2 = 0xfffd08, d2 = 4..15: tst.w 0x80dc6c, move.w (a2),(0x801a8e + offset), "
   "addq.w #2,(a4), cmp.w 0x801a88 -> clr.w (a4), move.b #1 to 0x801a92; 0x2679a tst.w 0x80ccac -> state 1 else "
   "move.w (a4) to 0xfffd26. 0x267b6 cmp.l #1: TR2 = 6 / CR 0x3d, TR3 = 2 / CR 0xbd, TR4 = word 0x80bda8[index], "
   "TR5 = byte 0x80c7a8[index], state 2, index + 1 mod 0x500, count - 1. Callers: bsr.w at 0x26840 and 0x2698e. "
   "CM848 splits this over cm848_onEepromBlockRead, cm848_writeNextQueuedEepromByte and "
   "cm848_onEepromStatusRead, so no single counterpart.",
   "medium")

skipped = [
    {"address": "0x00026852", "current_name": "cm550_FUN_00026852",
     "reason": "The body is a single rts (0x26852: 4e75). Its only reference is the bsr.s at 0x2685e, at the top of "
               "the serial EEPROM driver start-up (0x26854), before the vector store. An empty hook has no code to "
               "derive a role from, and CM848's counterpart (0x4cb64) begins with the ram_refresh_enable store, "
               "with no call in that place to borrow a role from; what the compiled-out body did is missing."},
]

globals_ = []


def gl(address, current_name, proposed_name, proposed_type, comment, evidence, confidence, firmware="CM550"):
    globals_.append({"firmware": firmware, "address": address, "current_name": current_name,
                     "proposed_name": proposed_name, "proposed_type": proposed_type, "comment": comment,
                     "evidence": evidence, "confidence": confidence})


# idle shutdown (e2m 10CD and its calibrations)
gl("0x0080d674", "vp44_sensor_monitor_state", "idle_shutdown_state", "IDLE_SHUTDOWN_STATE",
   "e2m 10CD +2 ISST 'indicates the present state of the idle shutdown algorithm' (0 - 5): the state word of "
   "cm550_runIdleShutdownStateMachine; the PGN 65252 payload builder (0x33d38) maps it to byte 1. CM848 has no "
   "idle shutdown machine, so no twin.",
   "movea.l #0x80d674,a3 at 0x1d9b8, jump table at 0x1da00, move.w #n,(a3) / clr.w (a3) in every case; clr.w at "
   "0x1db9a (initializer); move.w read at 0x33d44. Word accesses only. Dump 0.", "high")
gl("0x0080d676", "vp44_sensor_countdown_timer", "idle_shutdown_timer", "word",
   "e2m 10CD +4 ISTM 'decrement and hold timer which tracks the time vehicle is not moving' (0.1 s per count): "
   "reloaded from idle_shutdown_period_cal in RESET and OVERRIDE, counted down once per pass in COUNT and WARNING; "
   "the J1587 PID 71 status reports it running while it is nonzero and below the period.",
   "movea.l #0x80d676,a4 at 0x1d9be; move.w 0x803c02,(a4) at 0x1da0c / 0x1db22; subq.w #1,(a4) at 0x1da4c / "
   "0x1daa4; initializer 0x1db90; tst.w / move.w at 0xefa4 / 0xefac / 0xeff0. Dump 36000.", "high")
gl("0x0080d67a", "vp44_sensor_warning_active", "idle_shutdown_warning_lamp_request", "word",
   "e2m 10CD +8 ISWRRQ '1 - blink yellow lamp to indicate idle shutdown approach': set in WARNING, cleared in "
   "RESET / OVERRIDE / SHUTDOWN; cm550_flashShutdownWarningLamps flashes the warning lamp while it is set and the "
   "J1587 PID 71 status reports it as bit 0x01.",
   "movea.l #0x80d67a,a1 at 0x1d9c4; move.w #1,(a1) at 0x1daa6; clr.w (a1) at 0x1da12 / 0x1db28 / 0x1db52; tst.w "
   "at 0x24a0c and 0xeffc; initializer 0x1dba0.", "high")
gl("0x0080d67c", "vp44_sensor_monitor_reset_request", "idle_shutdown_reset_flag", "word",
   "e2m 10CD +A ISRSFG '1 - transition to reset from count; 0 - transition to count': 0 lets RESET go to COUNT, 1 "
   "sends COUNT and DELAY back to RESET. Set to 1 by cm550_initializeIdleShutdown; its other writer is not in the "
   "dumped ROM.",
   "tst.w at 0x1da36 (state 0), cmpi.w #1 at 0x1da5c (state 1) and 0x1db06 (state 3), move.w #1 at 0x1dbac. Dump "
   "1.", "high")
gl("0x0080d682", "vp44_sensor_secondary_fault", "idle_shutdown_override_successful_flag", "word",
   "e2m 10CD +10 ISODFG '1 - override procedure was successful; 0 - override not successful': with ISODEN it "
   "takes WARNING to OVERRIDE, with ISAATPEN it takes COUNT to DELAY; cleared in RESET and at start-up. No "
   "writer of 1 in the dumped ROM. It is not a sensor fault.",
   "clr.w at 0x1da1a and 0x1dbb4; cmpi.w #1 at 0x1da7a (after andi.l #0x400 on 0x803cca) and 0x1dabe (after andi.l "
   "#0x4 on 0x803c9a).", "high")
gl("0x0080d684", "vp44_sensor_shutdown_lamp_request", "idle_shutdown_override_lamp_request", "word",
   "e2m 10CD +12 ISODRQ '1 - blink yellow lamp to indicate idle shutdown is overridden': set in OVERRIDE; "
   "cm550_flashShutdownWarningLamps flashes the warning lamp 120 times for it and then clears it.",
   "move.w #1 at 0x1db2a; cmpi.w #1 at 0x24adc; clr.w at 0x24b40 and 0x1dba6.", "high")
gl("0x0080d672", "", "idle_shutdown_overridden_flag", "word",
   "e2m 10CD +0 ISOD '1 - idle shutdown is overridden until vehicle moves': set in OVERRIDE, cleared in RESET and "
   "at start-up; with ISODEN it is bit 0x04 of the J1587 PID 71 status.",
   "clr.w at 0x1da14 and 0x1db8a; move.w #1 at 0x1db32; tst.w at 0xefce. No row in the frozen CSV.", "high")
gl("0x0080d67e", "", "idle_shutdown_reset_from_warning_flag", "word",
   "e2m 10CD +C ISRSWNFG '1 - transition to reset from warning': 1 sends WARNING back to RESET. No writer in the "
   "dumped ROM.",
   "cmpi.w #1 at 0x1dad0, the only reference. No row in the frozen CSV. Dump 0.", "high")
gl("0x0080d680", "", "idle_shutdown_reset_from_override_flag", "word",
   "e2m 10CD +E ISODRSFG '1 - transition to reset from override': 1 sends OVERRIDE back to RESET. No writer in the "
   "dumped ROM.",
   "cmpi.w #1 at 0x1db3a, the only reference. No row in the frozen CSV. Dump 0.", "high")
gl("0x00803c02", "", "idle_shutdown_period_cal", "word",
   "e2m 0008 +66 ISTMLM 'delay period before idle shutdown occurs' (0.1 s per count; 36000 = 60 min in the dump): "
   "the reload value of idle_shutdown_timer. Inside the EEPROM mirror (EEPROM 0xf8), so _cal. CM848's e2m has "
   "the record (Idle_Shutdown_Period, 0x3fdd4c) but no code reads it.",
   "move.w source at 0x1da0c, 0x1db22, 0x1db90; cmp.w at 0xefb2. No row in the frozen CSV.", "high")
gl("0x00808150", "", "idle_shutdown_warning_period", "word",
   "e2m 10CC +8 ISWRTMLM 'time allotted to indicate approaching shutdown' (0.1 s per count; 300 = 30 s in the "
   "dump): COUNT enters WARNING when the timer is at or below it, and WARNING enters SHUTDOWN after this many "
   "passes. Not in the EEPROM mirror, so no _cal.",
   "cmp.w at 0x1da8e and 0x1dae6, the only references. No row in the frozen CSV.", "high")
gl("0x00800752", "", "idle_shutdown_state_previous", "word",
   "The idle shutdown state at the start of the previous pass: SHUTDOWN issues the shutdown command and switches "
   "output 30 on only when this is not 5 (its entry pass).",
   "move.w d2 (the entry state, 0x1d9ea) at 0x1db7e; cmpi.w #5 at 0x1db48. Only these two references.", "high")
gl("0x00800754", "vp44_sensor_failure_counter", "idle_shutdown_warning_pass_count", "word",
   "Passes spent in the idle shutdown WARNING state (0.1 s each): zeroed in COUNT, +1 per WARNING pass; SHUTDOWN "
   "follows when it reaches idle_shutdown_warning_period.",
   "clr.w at 0x1da4e; addq.w #1 at 0x1daaa; move.w / cmp.w 0x808150 at 0x1dae0. Only these references.", "high")
gl("0x00800756", "vp44_sensor_wait_timer", "idle_shutdown_delay_timer", "word",
   "Countdown of the idle shutdown DELAY state: preset to 600 (60 s) in COUNT, -1 per DELAY pass, OVERRIDE "
   "follows at 0.",
   "move.w #0x258 at 0x1da54; tst.w / subq.w #1 at 0x1daf8 / 0x1db00; tst.w at 0x1db14. Only these references.",
   "high")
gl("0x0080bd38", "engine_brake_lamp_driver_control", "output_30_override_priority", "byte",
   "Override priority of output 30 (bit 6 of output image byte 3, 0x80bcf9), slot 30 of the per-output byte "
   "array 0x80bd1a + output number (e2m 12A7; no record at +1E). Several logical drivers share output 30 in this "
   "build: the idle shutdown output (on in SHUTDOWN, off in RESET; e2m ISDR names an idle shutdown relay in this "
   "byte but says bit 4), engine brake drivers 2 to 6 (cm550_ioControlBasedFuelCalculator tests the bit five "
   "times, mc68k_initializeDiscreteOutputDrivers sets it five times) and lamp request bits 0x20 / 0x40. "
   "mc68k_ioDriverStrobeHandler writes image bytes 0 / 1 / 2 / 5 to hardware and not byte 3.",
   "tst.b / clr.b at 0x1da20 / 0x1da28; movea.l at 0x1db5c and 0x1dbc0 (tst.b (a0), clr.b); 0x23aa0-0x23aa4 forms "
   "0x80bd1a + 30. Byte accesses only.", "medium")

# duty cycle monitor
gl("0x00800000", "rpm_rate_limit_countdown", "duty_cycle_monitor_load_ratio", "i32",
   "Working value of cm550_updateDutyCycleMonitorLoadHistogram: (final fueling - no load fueling) x 10000 / (100 "
   "percent throttle fueling - no load fueling), signed, 0.01 percent. Its low word (0x800002) is copied to "
   "DCMNLDFA when it is not negative. The frozen row 0x800002 rpm_control_timer_1 is that low word and should "
   "go.",
   "move.l d0 at 0xadd8 and 0xae18 (after divs.l); tst.l at 0xae1e; move.w (0x800002) to 0x80bad4 at 0xae4a. No "
   "other reference.", "high")
gl("0x00800004", "high_rpm_threshold_countdown", "duty_cycle_monitor_full_throttle_fueling", "word",
   "Working value of the duty cycle monitor: the 100 percent throttle fueling at the engine speed limited to the "
   "monitor's cutoff speeds (FSMXTHFL between them, else the ALPHA blend of the two 4D fueling table lookups); "
   "the denominator of the load ratio.",
   "move.w d0 at 0xad2a / 0xad4a / 0xadb0; move.w 0x80d368 at 0xadb8; read at 0xadc2 and 0xae04. No other "
   "reference.", "high")
gl("0x00800006", "rpm_control_timer_2", "duty_cycle_monitor_short_term_period_ticks", "dword",
   "The duty cycle monitor's short term log period in 0.1 s ticks = DCMNSHTI (hours) x 36000 (18000000 in the "
   "dump): a short term map fills until its total reaches it. The frozen row 0x800008 "
   "rpm_control_timer_previous is its low word and should go.",
   "move.l d0 at 0xb002; cmp.l at 0xac8c / 0xacaa / 0xaef0 / 0xaf14 / 0xaf24 / 0xb146 / 0xb17a; move.l source at "
   "0xb02a / 0xb06a. Long accesses only.", "high")
gl("0x0080000a", "rpm_control_timer_delta", "duty_cycle_monitor_short_term_period_minutes", "word",
   "The duty cycle monitor's short term log period in minutes = DCMNSHTI x 60 (30000 in the dump), the unit of "
   "the stored map totals DCMP01TL / DCMP02TL.",
   "move.w d0 at 0xb016; cmp.w at 0xb022 / 0xb062; movea.l at 0xb13a (move.w (a1) to 0x805394 / 0x805396).",
   "high")
gl("0x0080000c", "previous_engine_rpm", "duty_cycle_monitor_steady_state_fueling_lookup_result", "word",
   "Result of the steady state 4D fueling table lookup at 100 percent throttle, kept only for the ALPHA blend in "
   "cm550_updateDutyCycleMonitorLoadHistogram.",
   "move.w d0 at 0xad5e (after jsr 0x35088 with 0x800010); mulu.w at 0xad7e. No other reference.", "high")
gl("0x0080000e", "dma_descriptor_base1", "duty_cycle_monitor_transient_fueling_lookup_result", "word",
   "Result of the transient 4D fueling table lookup at 100 percent throttle, kept only for the ALPHA blend in "
   "cm550_updateDutyCycleMonitorLoadHistogram.",
   "move.w d0 at 0xad72 (after jsr 0x35088 with 0x800026); move.w read at 0xad9e. No other reference.", "high")
gl("0x00800010", "dma_desc1_source_ptr", "duty_cycle_monitor_steady_state_fueling_lookup", "table_lookup_2d_arguments_t",
   "The 22-byte argument record of cm550_tableLookup2D for the steady state 4D fueling table (e2m 1055 / 1054 / "
   "1056 5DFL01XA / YA / ZA at 0x6086e / 0x6089a / 0x608a4): x input (+6, 0x800016) = the cutoff-limited engine "
   "speed, y input (+0xe) = 400 (100 percent throttle). table_lookup_2d_arguments_t is a NEW struct (layout in the "
   "notes); the frozen rows 0x800012 / 0x800014 / 0x800016 / 0x80001a / 0x80001c / 0x800020 / 0x800022 lie "
   "inside it. No DMA is involved.",
   "pea 0x800010 at 0xad1c / 0xad52; filled at 0xaf80-0xafac; x input stored at 0xace8 / 0xacfe. Dump: 00 02 | 00 "
   "06 08 6e | 19 00 | 00 02 | 00 06 08 9a | 01 90 | 00 06 08 a4 | 00 00.", "medium")
gl("0x00800026", "dma_descriptor_ptr1", "duty_cycle_monitor_transient_fueling_lookup", "table_lookup_2d_arguments_t",
   "The 22-byte argument record of cm550_tableLookup2D for the transient 4D fueling table (e2m 1058 / 1057 / 1059 "
   "5DFL00XA / YA / ZA at 0x6094c / 0x60978 / 0x60982): x input (+6, 0x80002c) = the cutoff-limited engine speed, "
   "y input = 400. The frozen rows 0x80002a / 0x80002e / 0x800032 / 0x800036 lie inside it.",
   "pea 0x800026 at 0xad3c / 0xad64; filled at 0xafb4-0xafe0; x input stored at 0xacf2 / 0xad08. Dump: 00 02 | 00 "
   "06 09 4c | 19 00 | 00 02 | 00 06 09 78 | 01 90 | 00 06 09 82 | 00 00.", "medium")
gl("0x0080bad4", "duty_cycle_monitor_calculated_load_factor_0_0_130_0", "duty_cycle_monitor_load_factor", "word",
   "e2m 111F +8 DCMNLDFA 'duty cycle monitor calculated load factor' (0.01 percent per count): the same record as "
   "CM848's duty_cycle_monitor_load_factor (0x40a648). The low word of duty_cycle_monitor_load_ratio, 0 when the "
   "ratio is negative; the load bin is searched with it.",
   "clr.w at 0xae26; move.w destination at 0xae4a; move.w read at 0xae96. Word accesses only.", "high")
gl("0x0080bad6", "duty_cycle_monitor_current_operating_map_region_1_50", "duty_cycle_monitor_operating_region",
   "byte",
   "e2m 111F +A DCMNOPRN 'duty cycle monitor current operating map region' (1 - 50): the same record as CM848's "
   "duty_cycle_monitor_operating_region (0x40a64a). Speed bin + (6 - load bin) x 8, or 49 / 50 for a negative "
   "load ratio; the index of the map counters.",
   "movea.l #0x80bad6,a5 at 0xac4c; move.b #0x31 / #0x32,(a5) at 0xae3a / 0xae42; move.b d0,(a5) at 0xaec8; move.b "
   "(a5),d0 at 0xaed8 / 0xaf3c / 0xaf5c. Byte accesses only.", "high")
gl("0x0080546e", "", "duty_cycle_monitor_long_term_map_counts", "dword[51]",
   "The long term map counters of the duty cycle monitor (e2m 1125 DCMNLGMP, 0.1 s per count), indexed by the "
   "operating region 1 - 50 (entry 0 unused); they follow the table's byte count word at 0x80546c (204).",
   "movea.l #0x80546e,a0 and addq.l #1,(0,a0,d0.w*4) at 0xaeda-0xaee0. Dump: byte count 0x00cc at 0x80546c.",
   "high")
gl("0x0080bada", "", "duty_cycle_monitor_short_term_processing_map_1_counts", "dword[51]",
   "The counters of short term processing map 1 (e2m 1120 DCSHPR01, 0.1 s per count), indexed by the operating "
   "region; they follow duty_cycle_monitor_short_term_processing_map_1_byte_count (0x80bad8, 204).",
   "movea.l #0x80bada,a0 and addq.l #1,(0,a0,d0.w*4) at 0xaf3e-0xaf44; filled from 0x80bade (region 1) at "
   "0xb0c0-0xb0f2 and read back at 0xb1b0. 0x80bada + 204 = 0x80bba6, the next byte count word.", "high")
gl("0x0080bba8", "", "duty_cycle_monitor_short_term_processing_map_2_counts", "dword[51]",
   "The counters of short term processing map 2 (e2m 1121 DCSHPR02, 0.1 s per count), indexed by the operating "
   "region; they follow duty_cycle_monitor_short_term_processing_map_2_byte_count (0x80bba6, 204).",
   "movea.l #0x80bba8,a0 and addq.l #1,(0,a0,d0.w*4) at 0xaf5e-0xaf64; filled from 0x80bbac at 0xb0ba-0xb120.",
   "high")

# boost in-range high: the records CM848 already names
gl("0x00807c04", "time_required_that_low_boost_cond_exist_before_birh_error_check_0_120",
   "boost_pressure_sensor_high_reading_dwell_limit", "word",
   "e2m 123D +0 DGBSDCTR 'time required that low boost conditions exist before the boost in-range high error "
   "check' (0.1 s per count; 200 = 20 s in the dump): the same record as CM848's "
   "boost_pressure_sensor_high_reading_dwell_limit (e2m 1631 +0). The dwell count must reach it before the "
   "debounce vote starts.",
   "movea.l #0x807c04,a5 at 0xe9ae; cmp.w (a5),d0 at 0xea48 and 0xea50.", "high")
gl("0x00807c06", "time_needed_for_out_of_range_high_boost_for_setting_birh_error_0_60",
   "boost_pressure_sensor_high_reading_debounce_limit", "word",
   "e2m 123D +2 DGBSHTTD 'time needed for out of range high boost for setting the boost in-range high error' (0.1 "
   "s per count; 25 in the dump): the same record as CM848's boost_pressure_sensor_high_reading_debounce_limit. "
   "The debounce count above it sets fault code 433.",
   "movea.l #0x807c06,a4 at 0xe9a8; cmp.w (a4),d0 at 0xea64 and 0xea74.", "high")
gl("0x00807c08", "", "boost_pressure_sensor_high_reading_maximum_engine_load", "word",
   "e2m 123D +4 DGLWTD 'limit that load must be below for the boost in-range high error check' (1/256 percent; "
   "1792 = 7 percent in the dump): the same record as CM848's "
   "boost_pressure_sensor_high_reading_maximum_engine_load. JCPCLD must be at most this.",
   "cmp.w (0x807c08).l,d0 at 0xea3c, the only reference. No row in the frozen CSV.", "high")
gl("0x00807c0a", "offset_added_to_lsg_ref_spd_resulting_in_rpm_limit_for_birh_tes_0_5000",
   "boost_pressure_sensor_high_reading_idle_reference_speed_offset", "word",
   "e2m 123D +6 DGLSRSOF 'offset added to the low speed governor reference speed resulting in the engine speed "
   "limit for the boost in-range high test' (0.125 rpm per count; 400 = 50 rpm in the dump): the same record as "
   "CM848's boost_pressure_sensor_high_reading_idle_reference_speed_offset.",
   "move.w (0x807c0a).l,d1 at 0xea20, added to LSRF 0x80db02 and compared with ESCMES at 0xea30.", "high")
gl("0x00807c0c", "boost_threshold_for_bir_high_error_0_100",
   "boost_pressure_sensor_high_reading_minimum_boost_pressure", "word",
   "e2m 123D +8 DGSTBSTD 'boost threshold for the boost in-range high error' (0.0159 inHg per count; 314 = 5 inHg "
   "in the dump): the same record as CM848's boost_pressure_sensor_high_reading_minimum_boost_pressure. Boost "
   "above it counts toward fault code 433.",
   "cmp.w (0x807c0c).l,d0 at 0xea5a, against BSTPRS 0x80a320.", "high")
gl("0x00800178", "anc_speed_limit_table_2_base", "boost_pressure_sensor_high_reading_dwell_count", "word",
   "Passes (0.1 s) the boost in-range high check's conditions have held, up to the dwell limit; zeroed when a "
   "condition fails. The twin of CM848's boost_pressure_sensor_high_reading_dwell_count (0x3fd172). Nothing to "
   "do with the acceleration noise control.",
   "movea.l #0x800178,a3 at 0xe9a2; addq.w #1,(a3) at 0xea4c; clr.w (a3) at 0xead0; clr.w at 0xeadc. No other "
   "reference.", "high")
gl("0x0080017a", "anc_speed_limit_table_2_ptr", "boost_pressure_sensor_high_reading_debounce_count", "word",
   "Debounce count of the boost in-range high check: +1 per pass with boost above the threshold (while at or "
   "below the limit), -1 otherwise; above the limit sets fault code 433, 0 clears it; preset to 1. The twin of "
   "CM848's boost_pressure_sensor_high_reading_debounce_count (0x3fd174).",
   "movea.l #0x80017a,a2 at 0xe99c; addq.w / subq.w #1,(a2) at 0xea68 / 0xea70; move.w #1,(a2) at 0xead2; move.w "
   "#1 at 0xeae2. No other reference. Dump 1.", "high")

# lamp family
gl("0x0080daae", "set_when_leading_threshold_has_expired_time_to_change_oil_1_0", "oil_change_monitor_change_due_flag",
   "word",
   "e2m 1094 +10 OCITWNFG 'set when leading threshold has expired - time to change oil': the same record as "
   "CM848's oil_change_monitor_change_due_flag (0x40ae5e). cm550_runLampControl gates the two oil change due "
   "flash patterns with it. No writer in the dumped ROM.",
   "movea.l #0x80daae,a3 at 0x254c0; tst.w (a3) at 0x25510 and 0x25538. Dump 0.", "high")
gl("0x0080dab0", "", "oil_change_monitor_reset_flag", "word",
   "e2m 1094 +12 OCRSFG 'indicates a manual reset was performed on OCM data': the same record as CM848's "
   "oil_change_monitor_reset_flag (0x40ae60). While set, cm550_runLampControl runs "
   "cm550_flashWarningLampForOilChangeMonitorReset. No writer in the dumped ROM.",
   "tst.w (0x80dab0).l at 0x2551a, the only reference. No row in the frozen CSV. Dump 0.", "high")
gl("0x0080dab2", "passes_diagnostic_output_for_stop_lamp_to_j1939_73_true_false", "stop_fault_lamp_flag", "word",
   "e2m 1094 +14 LCDGSTLP 'passes diagnostic output for stop lamp to J1939/73': the same record as CM848's "
   "stop_fault_lamp_flag (0x40ae62). cm550_updateActiveFaultLamps clears it and sets it to 1 for an active fault "
   "whose definition asks for the stop lamp.",
   "clr.w at 0x24f5e; move.w #1 at 0x25010.", "high")
gl("0x0080dab4", "passes_diagnostic_output_for_warning_lamp_to_j1939_73_true_false", "warning_fault_lamp_flag",
   "word",
   "e2m 1094 +16 LCDGWNLP 'passes diagnostic output for warning lamp to J1939/73': the same record as CM848's "
   "warning_fault_lamp_flag (0x40ae64). Set by cm550_updateActiveFaultLamps for a warning lamp fault (1 in the "
   "dump).",
   "clr.w at 0x24f64; move.w #1 at 0x250e6.", "high")
gl("0x0080dab6", "passes_diagnostic_output_for_fluids_lamp_to_j1939_73_true_false", "maintenance_fault_lamp_flag",
   "word",
   "e2m 1094 +18 LCDGFDLP 'passes diagnostic output for fluids lamp to J1939/73': the same record as CM848's "
   "maintenance_fault_lamp_flag (0x40ae66; CM848's e2m text says maintenance lamp). Set by "
   "cm550_updateActiveFaultLamps for a fault whose definition asks for the fluids (engine protection) lamp.",
   "clr.w at 0x24f6a; move.w #1 at 0x251b8.", "high")
gl("0x0080d28e", "engine_protection_derate_approaching_flag", "engine_protection_shutdown_approaching_flag", "word",
   "e2m 10B1 +14 EPSQ 'EPS shutdown approaching': the same record as CM848's "
   "engine_protection_shutdown_approaching_flag (0x40a786). cm550_flashShutdownWarningLamps flashes the stop lamp "
   "while it is set. It announces a shutdown, not a derate.",
   "tst.w at 0x24a74 (the lamp reader); clr.w at 0x186a4 / 0x19018 / 0x192ae and move.w #1 at 0x19134 / 0x191e4 / "
   "0x19242 (the engine protection code).", "high")
gl("0x00803c42", "", "oil_change_monitor_running_warning_enable_cal", "word",
   "e2m 0008 +A6 OCRNSTEA 'enables use of warning light with engine in run state' (0 in the dump): with the "
   "change due flag and engine_state RUNNING it lets cm550_runLampControl run the 30-minute reminder flash. "
   "Inside the EEPROM mirror (EEPROM 0x138), so _cal.",
   "tst.w (0x803c42).l at 0x25530, the only reference. No row in the frozen CSV.", "high")
gl("0x008019d2", "", "power_up_lamp_sequence_active_flag", "byte",
   "1 while the power-up lamp sequence runs: cm550_startPowerUpLampSequence sets it, cm550_runLampControl then "
   "runs only cm550_runPowerUpLampSequence, which clears it at the end of the sequence.",
   "tst.b (0x8019d2).l at 0x254c6; set / cleared in the decompiled bodies of 0x2482e / 0x24858. Dump 0.", "high")
gl("0x00801a22", "", "lamp_control_power_up_tick_count", "word",
   "Passes of cm550_runLampControl since start-up after the power-up lamp sequence (50 ms each), saturating at "
   "401: the oil change due flash at power-up runs while it is 100 to 399.",
   "movea.l #0x801a22,a2 at 0x254ba; cmpi.w #0x190 / addq.w #1 at 0x254fc-0x25502; cmpi.w #0x64 / #0x190 at "
   "0x25504 / 0x2550a. Dump 0x191.", "high")
gl("0x00801a1a", "fault_lamp2_blink_tick_counter", "oil_change_monitor_reset_flash_tick_count", "word",
   "Tick count (50 ms) of cm550_flashWarningLampForOilChangeMonitorReset's 72-tick cycle. It has nothing to do "
   "with faults.",
   "movea.l #0x801a1a,a2 at 0x253b2; addq.w #1,(a2) at 0x253c4; clr.w (a2) at 0x25442.", "high")
gl("0x00801a1c", "", "oil_change_monitor_reset_flash_active_flag", "byte",
   "1 while a reset acknowledgement flash cycle is running: keeps cm550_runLampControl calling "
   "cm550_flashWarningLampForOilChangeMonitorReset until the 72-tick cycle ends, after the reset flag has "
   "cleared.",
   "movea.l #0x801a1c,a0 at 0x253be; move.b #1,(a0) at 0x253d4; clr.b (a0) at 0x25440; tst.b at 0x25522.", "high")

# serial EEPROM driver
gl("0x00801a86", "diagnostic_can_response_header", "eeprom_mirror_load_offset", "word",
   "Next EEPROM offset the driver reads into the RAM mirror (the READ command's address word); +2 per stored "
   "word, back to 0 at eeprom_mirror_load_length. The twin of CM848's eeprom_mirror_load_offset (0x3fb814). No "
   "CAN is involved.",
   "movea.l #0x801a86,a4 at 0x266de; move.w (a4) to QSM_TR3 at 0x2674e / 0x267a8; addq.w #2,(a4) at 0x26778; clr.w "
   "(a4) at 0x26784; move.w to 0xfffd26 at 0x268f6. Dump 0x4c8.", "high")
gl("0x00801a88", "diag_can_response_pgn", "eeprom_mirror_load_length", "word",
   "Length in bytes of the EEPROM area the driver reads into the mirror: 0x148a for the start-up load, then 0x64c "
   "(RAM 0x803b0a-0x804155) for the continuous refresh. The twin of CM848's eeprom_mirror_load_length "
   "(0x3fb81a).",
   "movea.l #0x801a88,a2 at 0x26858; move.w d0,(a2) at 0x2695a and 0x269ea; cmp.w at 0x2677c. Dump 0x64c.", "high")
gl("0x00801a8a", "can_buffer_setup1_size", "eeprom_byte_write_state", "EEPROM_BYTE_WRITE_STATE",
   "State dword of the serial EEPROM driver step: 0 = no write in progress (the read stream runs), 1 = send the "
   "next queued byte write, 2 = wait for the write to finish (status polling). It is not a CAN buffer: the "
   "can_buffer_setup_t instance at 0x801a8a (and its member rows 0x801a8c-0x801a9c) should go.",
   "movea.l #0x801a8a,a1 at 0x266e4; cmp.l #2 at 0x266ea; tst.l at 0x26756; cmp.l #1 at 0x267b6; move.l #1 / #2 / "
   "clr.l at 0x2673a / 0x2680a / 0x2673e; clr.l at 0x2693a. Long accesses only. Dump 0.", "high")
gl("0x00801a8e", "can_buffer_setup1_size.data_ptr", "eeprom_mirror_base_pointer", "pointer",
   "Base address of the EEPROM's RAM mirror (0x803b0a = ecu_identity_marker_1): the driver stores each word read "
   "at base + eeprom_mirror_load_offset. The twin of CM848's eeprom_mirror_base_pointer (0x3fb816).",
   "move.l #0x803b0a at 0x26940; add.l (0x801a8e).l,d0 at 0x2676e. Dump 0x00803b0a.", "high")
gl("0x00801a92", "can_buffer_setup1_size.unused_ptr", "eeprom_mirror_loaded_flag", "byte",
   "Set to 1 when the read offset wraps at the load length: the start-up load loop of "
   "mc68k_initializeSerialEepromDriverAndLoadMirror ends on it. The twin of CM848's eeprom_mirror_loaded_flag "
   "(0x3fb81c, a word there).",
   "move.b #1 at 0x26786; tst.b at 0x269b2. Byte accesses only. Dump 1.", "high")

# percent load: the records CM848 already names
gl("0x0080db62", "percent_load_based_on_low_hp_torque_curve_0_255", "engine_load_low_horsepower_curve_percent",
   "word",
   "e2m 10BF +4 SPT0PCLD 'percent load based on low HP torque curve' (1/256 percent): the same record as CM848's "
   "engine_load_low_horsepower_curve_percent (0x40af26). Written only by "
   "cm550_calculateEngineLoadLowHorsepowerCurvePercent.",
   "movea.l #0x80db62,a3 at 0x26e36; move.w d0,(a3) at 0x26e76; clr.w (a3) at 0x26e7e.", "high")
gl("0x0080d36a", "fueling_provided_if_engine_were_using_low_hp_curve_0_100",
   "throttle_100_fueling_low_horsepower_curve", "word",
   "e2m 105A +2 FST0MXFL 'fueling provided if engine were using low HP curve' (0.0679 mm3 per count): the same "
   "record as CM848's throttle_100_fueling_low_horsepower_curve (0x40a899). The denominator's full load "
   "reference in cm550_calculateEngineLoadLowHorsepowerCurvePercent; its writer is not in the dumped ROM.",
   "movea.l #0x80d36a,a1 at 0x26e3c; move.w (a1) at 0x26e4e / 0x26e58 (unsigned compare bls). Dump 1619.", "high")
gl("0x0080db1c", "frictional_no_load_fueling", "no_load_fuel_quantity", "word",
   "e2m 109C +0 NLFL 'fuel required to overcome friction' (0.0679 mm3 per count): the same record as CM848's "
   "no_load_fuel_quantity (0x40aeec). The zero-load reference of the duty cycle load ratio and of the three "
   "percent load words.",
   "cmp.w / sub.w (a2 = 0x80db1c) at 0x26e4a-0x26e5a; cmp.w / move.w at 0xadc8 / 0xadea / 0xae0c. Dump 88.",
   "high")
gl("0x0080db60", "engine_load_percent_normalized", "engine_load_percent", "word",
   "e2m 10BF +2 FSPCLD 'percent load' (1/256 percent, clamped at 0x7f80): the same record as CM848's "
   "engine_load_percent (0x40af24). Written only by cm550_calculateEngineLoadPercentages.",
   "move.w #0x7f80 at 0x26d20, move.w d3 at 0x26d2a, clr.w at 0x26d32 (the only writers). e2m address from the "
   "parameter ID table.", "high")
gl("0x0080d368", "fueling_value_at_100_throttle_0_100", "throttle_100_fueling", "word",
   "e2m 105A +0 FSMXTHFL 'fueling value at 100% throttle' (0.0679 mm3 per count): the same record as CM848's "
   "throttle_100_fueling (0x40a897). The full load reference of the percent load words and, between the cutoff "
   "speeds, of the duty cycle load ratio.",
   "move.w (0x80d368).l at 0xadb8; movea.l #0x80d368,a4 at 0x26cdc with move.w (a4) at 0x26cee / 0x26cf6 / "
   "0x26d60 / 0x26d66. Dump 1619.", "high")

enum_members = []


def en(enum_name, value, proposed_member, comment, evidence, confidence, firmware="CM550", current_member=""):
    enum_members.append({"firmware": firmware, "enum_name": enum_name, "value": value,
                         "current_member": current_member, "proposed_member": proposed_member,
                         "comment": comment, "evidence": evidence, "confidence": confidence})


en("IDLE_SHUTDOWN_STATE", 0, "IDLE_SHUTDOWN_STATE_RESET",
   "Not counting: the timer is held at the idle shutdown period, the lamp requests and the overridden / override "
   "successful flags are cleared and output 30 is off; leaves to COUNT when idle_shutdown_reset_flag is 0. PGN "
   "65252 byte 1 = 0x00. (new enum, size 2, type of idle_shutdown_state)",
   "Case 0 at 0x1da0c-0x1da44. e2m ISRSFG names the pair: '1 - transition to reset from count; 0 - transition to "
   "count' = the 1 -> 0 and 0 -> 1 transitions on 0x80d67c. PGN 65252 builder 0x33d66 clr.b.", "high")
en("IDLE_SHUTDOWN_STATE", 1, "IDLE_SHUTDOWN_STATE_COUNT",
   "The idle shutdown timer counts down (0.1 s per pass): to RESET on the reset flag, to DELAY when the "
   "temperature option and the override successful flag are set, to WARNING when the timer is at or below the "
   "warning period. PGN 65252 byte 1 = 0x40 (SPN 590 idle shutdown timer state active).",
   "Case 1 at 0x1da48-0x1da9c (subq.w #1 on the timer; move.w #0 / #3 / #2 to the state). PGN 65252 builder "
   "0x33d6a move.b #0x40.", "high")
en("IDLE_SHUTDOWN_STATE", 2, "IDLE_SHUTDOWN_STATE_WARNING",
   "Shutdown approaching: sets the warning lamp request ISWRRQ and counts passes; to OVERRIDE when the override is "
   "enabled and successful, to RESET on the reset from warning flag, to SHUTDOWN after the warning period. PGN "
   "65252 byte 1 = 0x44 (timer state active + SPN 594 driver alert mode active).",
   "Case 2 at 0x1daa0-0x1daf4 (move.w #1 to 0x80d67a; move.w #4 / #0 / #5). e2m ISRSWNFG 'transition to reset "
   "from warning' is the 2 -> 0 test at 0x1dad0. PGN 65252 builder 0x33d70 move.b #0x44.", "high")
en("IDLE_SHUTDOWN_STATE", 3, "IDLE_SHUTDOWN_STATE_DELAY",
   "A 600-pass (60 s) delay before the override, entered from COUNT with the temperature option: to RESET on the "
   "reset flag, to OVERRIDE when the delay timer reaches 0. PGN 65252 byte 1 is left unchanged. No J90350.00 "
   "e2m text names this state; the name is the code's delay timer, and the later CHR_B2 e2m labels value 3 "
   "DELAY.",
   "Case 3 at 0x1daf8-0x1db20 (subq.w #1 on 0x800756, preset 0x258 at 0x1da54; move.w #0 / #4). PGN 65252 builder: "
   "table entry 3 = 0x26 -> 0x33d80, no store.", "high")
en("IDLE_SHUTDOWN_STATE", 4, "IDLE_SHUTDOWN_STATE_OVERRIDE",
   "Idle shutdown overridden: the timer is reloaded, the warning request cleared, ISOD (overridden until the "
   "vehicle moves) and the override lamp request ISODRQ set; to RESET on the reset from override flag. PGN 65252 "
   "byte 1 = 0x10 (SPN 592 idle shutdown timer override active).",
   "Case 4 at 0x1db22-0x1db46 (move.w #1 to 0x80d684 and 0x80d672). e2m ISODRSFG 'transition to reset from "
   "override' is the 4 -> 0 test at 0x1db3a. PGN 65252 builder 0x33d76 move.b #0x10.", "high")
en("IDLE_SHUTDOWN_STATE", 5, "IDLE_SHUTDOWN_STATE_SHUTDOWN",
   "The idle shutdown has shut the engine down: on entry the warning request is cleared, the engine shutdown "
   "command SHSS set and output 30 switched on; to RESET when engine_state is CRANKING. PGN 65252 byte 1 = 0x01 "
   "(SPN 593 idle shutdown has shut down engine).",
   "Case 5 at 0x1db48-0x1db7c (move.w #1 to 0x80d28c under cmpi.w #5 on the previous state; cmpi.w #2 on "
   "engine_state). PGN 65252 builder 0x33d7c move.b #0x1.", "high")
en("EEPROM_BYTE_WRITE_STATE", 0, "EEPROM_BYTE_WRITE_STATE_IDLE",
   "No write in progress: the driver step stores the words read into the EEPROM mirror and queues the next read; "
   "a queued write takes it to SEND_WRITE. (new enum, size 4, type of eeprom_byte_write_state)",
   "tst.l (a1 = 0x801a8a) at 0x26756 with the read path 0x2675a-0x267ae; clr.l at 0x2673e and 0x2693a.", "high")
en("EEPROM_BYTE_WRITE_STATE", 1, "EEPROM_BYTE_WRITE_STATE_SEND_WRITE",
   "Send the next queued byte write: write enable (command 6) and write (command 2) with the queue entry's "
   "address and data byte; then WAIT_FOR_COMPLETION.",
   "cmp.l #1 at 0x267b6-0x267ba with the write path 0x267bc-0x2682c; move.l #1 at 0x2673a and 0x267a4.", "high")
en("EEPROM_BYTE_WRITE_STATE", 2, "EEPROM_BYTE_WRITE_STATE_WAIT_FOR_COMPLETION",
   "A write was sent: read the status register (command 5) each pass until the write-in-progress bit is clear, "
   "then SEND_WRITE when more is queued, else IDLE with a READ at the saved offset.",
   "cmp.l #2 at 0x266ea with the status path 0x266f0-0x26754; move.l #2 at 0x2680a.", "high")

summary = (
    "Batch D1 is five unrelated CM550 features plus three executive task-set wrappers. (1) The duty cycle monitor "
    "sample (0xac3c): every 100 ms it turns the fueling into a load ratio, picks one of 50 speed / load regions "
    "and counts it in a long term and an active short term map. (2) The boost pressure in-range high diagnostic "
    "(0xe998): dwell and debounce counters that set fault code 433 when boost stays high at low load near idle. "
    "(3) The idle shutdown state machine (0x1d9b4, state word ISST: RESET / COUNT / WARNING / DELAY / OVERRIDE / "
    "SHUTDOWN) - CM848 S90140.06 has no such machine, so it is CM550 only. (4) The lamp control task (0x254b6) "
    "with its callees: power-up lamp sequence, fault code flash out, shutdown warning flashes, active fault lamps "
    "and three oil change monitor flash patterns (0x253b0 is the reset acknowledgement). (5) The serial EEPROM "
    "driver start-up (0x26854: QSPI set-up, polled load of the EEPROM into the RAM mirror, then the "
    "interrupt-driven refresh through the handler 0x26834) and the low horsepower curve percent load (0x26e2c). "
    "The wrappers are executive schedule slots; most of their callees lie above the dumped ROM, so they take the "
    "slot names HEAD already uses."
)

notes = (
    "REPOSITORY MOVED WHILE THIS RAN: HEAD commit 7cf52470 (after the frozen copy) names the 45 executive task "
    "sets by schedule slot; my four wrapper names equal those live names, so only their plate comments change "
    "(the new callee names). Other batches' names are live too (0x80ccee engine_hour_meter, 0x80d32e "
    "final_fueling, 0x80db5e engine_load_at_current_speed_percent) and two typing commits gave many of the rows "
    "below a width (names unchanged); every proposal here was checked against the frozen AND the live CSVs "
    "(check_names2.py; build_output.py re-checks each row's live name). | WRAPPERS: role names cannot be proven (2 of 3, 1 of 4 and 3 of "
    "4 callees are above 0x40000), the slot is proven by the dispatch (jump table 0x1b90e). Three are standalone "
    "(their CM848 slot mates cm848_periodicTaskGroup26_calibration8 0xbd80 / hpcr_periodicTaskGroup36_calibration15 "
    "0xbf34 / cm848_periodicTaskGroup17_calibration5 0xbd08 share no task); 0x1b788 is a counterpart only as the "
    "slot mate of cm848_periodicTaskGroup28_calibration10, which starts with the same two percent load "
    "calculations. The frozen neighbours' "
    "role names were wrong where checkable (0x1b70c 'dzgTimingAndPressure' calls only the lamp task; 0x1b72a "
    "'camSyncDiagnosticProcessingSlowCycle20' is a 10-frame set that calls the J1708 receive dispatcher) - HEAD "
    "replaced them all. CM848's periodicTaskGroup<N>_calibration<M> names are of the same kind: a lead. | IDLE "
    "SHUTDOWN: the task text says CM848 has an idle shutdown state machine; it does not in S90140.06 - four "
    "independent checks (no reader of flags word 3 bits 1 / 2; no reference to Idle_Shutdown_Period 0x3fdd4c, "
    "Min / Max IMT 0x3fdd4a / 0x3fdd48 or the PGN 65252 priority 0x3fd862, with controls found; "
    "engine_shutdown_command_flag 0x40a784 written only by the engine protection shutdown, cm848_updateEngineState "
    "and commandEngineShutdown; no PGN 65252 transmit). cm848_updateExtendedIdleProtection is the emissions AECD, "
    "not this. The state labels match the Idle_Shutdown_State record of the later CHR_B2 e2m files "
    "(0=RESET:1=COUNT:2=WARNING:3=DELAY:4=OVERRIDE:5=SHUTDOWN) - corroboration only. ISTMSS (0x80d678, 10CD +6) "
    "has no reference in the dumped ROM: left out. The writers of ISRSFG / ISRSWNFG / ISODRSFG / ISODFG are in "
    "the undumped ROM (0x46aac runs just before the machine: a candidate, not proven). | OUTPUT 30: byte 3 of the "
    "output image (0x80bcf9, frozen name bit_4_of_master_status_byte_a_0_1) is never written to hardware by "
    "mc68k_ioDriverStrobeHandler (bytes 0 / 1 / 2 / 5 are), and output 30 serves five engine brake drivers, the "
    "idle shutdown output and two lamp request bits - it looks like the build's stand-in for drivers the hardware "
    "lacks. Also cm550_applyLampRequestsToOutputs (every 50 ms) would switch it off again unless lamp request bit "
    "0x40 is set, and none of the nine functions that write the lamp request word in the dumped ROM (0x249b6, "
    "0x249ee, 0x24b4e, 0x24d40, 0x24f30, 0x25316, 0x253b0, 0x25448, 0x34c36) sets bits 0x08 / 0x20 / 0x40. "
    "0x80bcf9 and 0x80bcf6 deserve "
    "output image names (0x80bcf8 is already port_e_output_image). | LAMPS: output 4 is 'engine protection lamp' "
    "in the priority records (EPLPPZ, LCEGPNLP) and 'fluids lamp' in LCDGFDLP / FLLPONTM; CM848's e2m says "
    "maintenance. I used engine protection lamp in function names (the existing row "
    "engine_protection_lamp_override_priority) and CM848's maintenance_fault_lamp_flag for the shared record. "
    "lamp_driver_output_bitmask (0x80daac) keeps its name; bits: 0x01 stop, 0x02 warning, 0x04 engine "
    "protection, 0x08 wait to start, 0x10 water in fuel, 0x20 / 0x40 output 30. Unnamed lamp RAM left for a "
    "later round: 0x8019d3 first pass, 0x8019d4 end step, 0x8019e0 / e1 / e2 flash-active flags, 0x8019e3 "
    "override flash count, 0x8019e4-e6 digits, 0x8019e8 flash out active, 0x8019eb / ec / ed switch previous "
    "states, 0x8019f0 sequence tick, 0x801a16 / 0x801a1d / 0x801a20. Leads: vp44FaultRegisterBit2Monitor "
    "(0x34c36) sets lamp request bit 0x10 (water in fuel) and a fault bit; vp44_engineHoursPGN_65252_Builder "
    "(0x33dfa) initializes the PGN 65252 Shutdown message (no engine hours) and the payload builder 0x33d38 has "
    "no function row; cm550_iahDisableWaitToStartLamp (0x24812) switches the wait to start lamp off at start-up "
    "(the frozen row 0x2481e cm550_initIoControlRegister sat in its middle; the live CSV has dropped it, like "
    "0x1db9a); processDiagnosticLimitStatus (0x18fcc) is the engine protection shutdown algorithm that sets EPSQ "
    "and SHSS, the counterpart of cm848_updateEngineProtectionShutdown. | EEPROM: the batch title calls 0x26854 a loop step; it is the driver start-up (called once, "
    "0x28674). 0x26834 has no caller - it is installed in RAM vector 81. 0x266da keeps its name "
    "(mc68k_runSerialEepromWriteQueue) and gets an extended plate comment: the name is incomplete (the read "
    "stream that loads and refreshes the mirror is its normal state), not wrong; a fuller name would be "
    "mc68k_runSerialEepromDriver (free in both firmwares) if a rename is wanted later. The RAM dump shows RAM 0x804b0a-0x804f93 "
    "(EEPROM offsets 0x1000-0x1489) loaded, so the EEPROM is larger than the 4 KB dump. The struct instance "
    "can_buffer_setup_t at 0x801a8a is wrong (it covers the driver's state / base pointer / loaded flag and the "
    "start of a 2D lookup record at 0x801a94): remove it. | 0x26e2c: counterpart, not twin, only because CM848 "
    "0x50e000 adds one step (clamp at 0xff00); if the judge accepts that as a twin the shared name is "
    "calculateEngineLoadLowHorsepowerCurvePercent. Either way CM848 0x50e000 "
    "(cm848_validateFuelDemandRelativeToTiming) is misnamed and should become "
    "cm848_calculateEngineLoadLowHorsepowerCurvePercent. | NEW STRUCT (lead): table_lookup_2d_arguments_t, 22 bytes, "
    "the argument of cm550_tableLookup2D (0x35088): x_axis_offset word +0 / x_axis_pointer dword +2 / x_input "
    "word +6 / y_axis_offset word +8 / y_axis_pointer dword +0xa / y_input word +0xe / z_values_pointer dword "
    "+0x10 / no_interpolation_flag word +0x14 (table_args[10] != 0 returns the grid value). About 20 instances "
    "(every cm550_tableLookup2D call site). | DUTY CYCLE TABLES: 0x807d1e (DCMNESTB, byte count 18 + 9 speed "
    "values) and 0x807d32 (DCMNLDTB, byte count 14 + 7 load values) are whole tables; the rows 0x807d20, 0x807d2c, "
    "0x807d2e, 0x807d30 and 0x807d34 to 0x807d40 (rpm_timer_interrupt_threshold_7d20, rpm_source_selector_init, "
    "throttle_frictional_load_upper_threshold / _lower_threshold, intake_temp_frictional_load_threshold, "
    "rpm_fuel_limit_blend_offset, frictional_load_fuel_init, rpm_fuel_limit_threshold_max, "
    "frictional_load_state_init, rpm_fuel_limit_state_max, frictional_load_torque_init) lie inside them and only "
    "0x807d20 / 0x807d34 / 0x807d40 are referenced - 0x807d40 is the 7th load value 10000, read as the load ratio "
    "when the full throttle fueling equals the no load fueling. Suggested: duty_cycle_monitor_engine_speed_axis "
    "word[10] at 0x807d1e and duty_cycle_monitor_load_axis word[8] at 0x807d32. | Scratch (notes.md, helper "
    "scripts, this output as draft_output.json): "
    "/home/linux/.claude/jobs/374b0424/tmp/w15/r93/scratch/D1/investigator/."
)

import sys  # noqa: E402

sys.path.insert(0, HERE)
import overrides  # noqa: E402

overrides.apply(functions, globals_, enum_members)

out = {"batch": "D1", "summary": summary, "functions": functions, "skipped": skipped, "globals": globals_,
       "enum_members": enum_members, "notes": notes}

# ------------------------------------------------------------------------------------------------------- checks
LISTED = ["0x0000ac3c", "0x0000e998", "0x0001b754", "0x0001b788", "0x0001b7f2", "0x0001d9b4", "0x000253b0",
          "0x000254b6", "0x00026834", "0x00026852", "0x00026854", "0x00026e2c"]
seen = Counter([f["address"] for f in functions] + [s["address"] for s in skipped])
for a in LISTED:
    assert seen[a] == 1, (a, seen[a])
assert all(c == 1 for c in seen.values()), [a for a, c in seen.items() if c != 1]


def names(path):
    t = {}
    for row in csv.reader(open(path, errors="replace")):
        if len(row) >= 2 and not row[0].startswith("#"):
            t.setdefault(row[1].strip(), []).append(row[0].strip().lower())
    return t


tables = {
    "frozen cm550 functions": names(F + "cm550/function_renames.csv"),
    "frozen cm550 globals": names(F + "cm550/global_variables.csv"),
    "live cm550 functions": names(R + "CM550_J90350.00_analysis/output/function_renames.csv"),
    "live cm550 globals": names(R + "CM550_J90350.00_analysis/output/global_variables.csv"),
}
cm848 = {
    "cm848 functions": names(F + "cm848/function_renames.csv"),
    "cm848 globals": names(F + "cm848/global_variables.csv"),
}
problems = []
prop = Counter([f["proposed_name"] for f in functions] + [g["proposed_name"] for g in globals_])
for n, c in prop.items():
    if c > 1:
        problems.append(f"duplicate proposal {n}")
for item in functions + globals_:
    n = item["proposed_name"]
    addr = int(item["address"], 16)
    for label, t in tables.items():
        for a in t.get(n, []):
            try:
                if int(a, 16) != addr:
                    problems.append(f"{n} already at {a} in {label}")
            except ValueError:
                pass
# live drift: each global's live name must be the frozen name or the proposal; each function's live name must be the
# frozen name or the proposal
live_g = {}
for row in csv.reader(open(R + "CM550_J90350.00_analysis/output/global_variables.csv", errors="replace")):
    if len(row) >= 2 and row[0].lower().startswith("0x"):
        try:
            live_g.setdefault(int(row[0], 16), row[1].strip())
        except ValueError:
            pass
for g in globals_:
    a = int(g["address"], 16)
    if live_g.get(a, "") not in (g["current_name"], g["proposed_name"]):
        problems.append(f"LIVE global name drift {g['address']}: live '{live_g.get(a, '')}'")
live_f = {}
for row in csv.reader(open(R + "CM550_J90350.00_analysis/output/function_renames.csv", errors="replace")):
    if len(row) >= 2 and row[0].lower().startswith("0x"):
        live_f[int(row[0], 16)] = row[1].strip()
for f in functions + skipped:
    a = int(f["address"], 16)
    if live_f.get(a) not in (f["current_name"], f.get("proposed_name")):
        problems.append(f"LIVE function name drift {f['address']}: live '{live_f.get(a)}'")
# no plate comment may name a function under a name that is neither a proposal nor an existing row
# frozen current names must match the frozen CSV
frozen_f = {}
for row in csv.reader(open(F + "cm550/function_renames.csv", errors="replace")):
    if len(row) >= 2 and row[0].lower().startswith("0x"):
        frozen_f[int(row[0], 16)] = row[1].strip()
for f in functions + skipped:
    a = int(f["address"], 16)
    if frozen_f.get(a) != f["current_name"]:
        problems.append(f"current name mismatch {f['address']}: frozen {frozen_f.get(a)} vs {f['current_name']}")
frozen_g = {}
for row in csv.reader(open(F + "cm550/global_variables.csv", errors="replace")):
    if len(row) >= 2 and row[0].lower().startswith("0x"):
        try:
            frozen_g.setdefault(int(row[0], 16), row[1].strip())
        except ValueError:
            pass
for g in globals_:
    a = int(g["address"], 16)
    if frozen_g.get(a, "") != g["current_name"]:
        problems.append(f"global current name mismatch {g['address']}: frozen '{frozen_g.get(a, '')}' vs "
                        f"'{g['current_name']}'")
for f in functions:
    if f["relation"] in ("twin", "counterpart"):
        a = f["cm848_address"]
        hit = [n for n, addrs in cm848["cm848 functions"].items() if a.lower() in addrs]
        if hit != [f["cm848_current_name"]]:
            problems.append(f"cm848 name mismatch for {f['address']}: {hit} vs {f['cm848_current_name']}")
print("functions", len(functions), "skipped", len(skipped), "globals", len(globals_), "enum members",
      len(enum_members))
print("problems:", problems or "none")
json.dump(out, open(os.path.join(HERE, "draft_output.json"), "w"), indent=1)
print("written", os.path.join(HERE, "draft_output.json"), os.path.getsize(os.path.join(HERE, "draft_output.json")))
