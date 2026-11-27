"""Describer D1 scratch (run 2): builds final_output2.json (the StructuredOutput payload) so the JSON is valid by
construction. Supersedes build_final.py / final_output.json of run 1 (kept for the archive): every claim was re-checked
in run 2 (notes.md, section 'Run 2') and the advisor's five points were fixed."""
import json

roles = []


def role(address, text, discriminator, name, confidence, counterpart):
    roles.append({"address": address, "role": text, "discriminator": discriminator, "suggested_name": name,
                  "confidence": confidence, "cm848_counterpart": counterpart})


# ---------------------------------------------------------------------------------------------- duty cycle monitor
role("0x0ac3c",
     "Takes one duty cycle monitor sample per 100 ms pass while duty_cycle_monitor_enable (flags word 18 bit 3) is set "
     "and engine_state is not STOPPED: it computes the load factor (final fueling - no-load fueling) x 10000 / (maximum "
     "fuel at the engine speed - no-load fueling) and bins engine speed (8 breakpoints) and load factor (6 breakpoints) "
     "into an operating region 1-48 (49 / 50 for a negative ratio). It then adds 1 to that region's counter and to the "
     "total of the long term map and of the short term map being filled, and stamps a map's start time when its total "
     "is 0.",
     "The only code in the dumped ROM that writes the three map counter arrays (long term 0x80546e + 4 x region with "
     "total 0x805398, capped at 3,600,000,000; short term 1 0x80bada / total 0x80bacc; short term 2 0x80bba8 / total "
     "0x80bad0), the region DCMNOPRN (0x80bad6), the load factor DCMNLDFA (0x80bad4) and the active map selector "
     "DCMNSHNU (0x80bad7, picked from the two totals against the log period 0x800006). The maximum fuel is FSMXTHFL "
     "(0x80d368) inside the cutoffs DCMNLOES..DCMNHIES, otherwise an ALPHA-blended lookup of two 2D tables (descriptors "
     "0x800010 / 0x800026) at the cutoff speed; 0x800002 (rpm_control_timer_1) is only the low word of the ratio dword "
     "0x800000. The wrapper siblings 0x26cc8 / 0x26e2c compute percent load words and keep no histogram. The second "
     "caller in the family list, cm550_slowCycle8Coordinator (0x1b78e), is the jsr to this function inside wrapper "
     "0x1b788, not a function.",
     "cm550_updateDutyCycleMonitorLoadHistogram", "high",
     "cm848_updateDutyCycleMonitorLoadHistogram @ 0x50638c - counterpart, not a twin. Same enable bit, STOPPED gate, "
     "low / high cutoff, x 10000 ratio, 1-based 8-breakpoint speed binning, the word after the last load breakpoint as "
     "the ratio when the maximum fuel equals the no-load fuel, two negative-ratio regions and the 3,600,000,000 cap. "
     "Different: CM848 has 10 load bands (regions 1-80, 81 / 82), clamps the ratio at 13000, takes the maximum fuel "
     "from cm848_lookupChiMaximumFuelAtSpeed, has no short term maps (e2m blocks 1120 / 1121, DCSHPR01 / DCSHPR02 "
     "'short term processing map' at CM550's 0x80bad8 / 0x80bba6, are proven absent from its parameter ID table) and "
     "adds the percent-time-at-load words and the map reset.")

role("0x0af70",
     "Start-up initializer of the duty cycle monitor (jsr from 0x28822 in mc68k_applicationMain): it loads the two "
     "maximum fuel table descriptors (0x800010 / 0x800026, tables above the dumped ROM) with the low cutoff speed as "
     "their input, converts the short term log period from hours to samples (x 36000, into 0x800006) and rebuilds the "
     "two short term processing totals and maps from the stored maps (x 36000 / 60).",
     "Runs once and only writes what 0xac3c reads; it takes no sample. Extra entry (not in the family list), given "
     "because its role is certain and it is the only other code that touches the short term processing maps.",
     "cm550_initializeDutyCycleMonitor", "high",
     "none: in CM848 only cm848_updateDutyCycleMonitorLoadHistogram, cm848_runDataCollector and "
     "cm848_sciCommand35Callback touch the duty cycle monitor words.")

# ---------------------------------------------------------------------------------------------- boost in range high
role("0x0e998",
     "Boost pressure in-range high check (the e2m's BIR high / BIRH error), every 100 ms while "
     "boost_pressure_in_range_diagnostic_enable (flags word 27 bit 4) is set: with engine_state RUNNING, neither boost "
     "sensor circuit error active, engine speed at or below the low speed governor reference plus an offset and percent "
     "load at or below a limit, it counts a dwell time and then debounces 'filtered boost pressure above the threshold' "
     "up and down. Above the debounce limit it sets system error bit 29 and its first-occurrence bit, at debounce 0 it "
     "clears the status bit once the first-occurrence bit is clear, and a failed condition resets the dwell to 0 and "
     "the debounce to 1.",
     "The only reader of the five BIR constants of e2m block 123D (DGBSDCTR 0x807c04 dwell, DGBSHTTD 0x807c06 debounce "
     "limit, DGLWTD 0x807c08 load limit against JCPCLD 0x80db5e, DGLSRSOF 0x807c0a speed offset above the LSG reference "
     "LSRF 0x80db02, DGSTBSTD 0x807c0c boost threshold against 0x80a320) and the only code that sets or clears mask "
     "0x2000 of status word 1 (0x806002 / first-occurrence 0x806042, interrupts masked). Counters: dwell 0x800178, "
     "debounce 0x80017a. The gate tests masks 0x400 / 0x200 of 0x806002 together with the same bits of 0x806abe, which "
     "is word 1 of the e2m record DGFUIDEN (000F +570, 38 bytes: 'bit mapped parameter used to disable / enable the "
     "processing of a fault'), so the row name fault_confirm_status_word_1 is wrong. The RAM dump identifies the bits: "
     "the fault code assignment table (e2m DGFUCATB 0x80656c, words) maps error bit 29 to fault record 91 = Cummins "
     "code 433 and bits 25 / 26 to codes 122 / 123. Its reset entry 0xeadc (dwell 0, debounce 1) has no row and no "
     "reference in the dump.",
     "cm550_monitorBoostPressureInRangeHighError", "high",
     "cm848_monitorBoostPressureSensorAndUnderboost @ 0x52d6a8 - counterpart, not a twin. Its last block (CM848's "
     "boost_pressure_sensor_high_reading_* words) has the same steps in the same order: RUNNING, the two sensor circuit "
     "faults clear, engine speed at or below LSG reference + offset, load at or below the limit, else dwell = 0 / "
     "debounce = 1; dwell to its limit; boost above the threshold counts up, else down; above the limit set the fault, "
     "at 0 clear it. CM848 does the pre-start check, the underboost check and the monitor report in the same body, "
     "compares engine_load_percent (not the load at the current speed) and sets fault 64.")

# ---------------------------------------------------------------------------------------------- the three wrappers
SLOT = ("The live repository renamed all 45 executive frame task sets by schedule slot after the freeze (commit "
        "7cf52470), and this one is {live} there; my phase analysis of the frozen code agrees with that slot. ")

role("0x1b754",
     "Executive frame task set of the every-20-frames group, run in phases 1 and 21 of the 40-phase executive (bsr.w "
     "from 0x1b99e and 0x1bc5c; every 100 ms): it calls 0xe998 (the boost pressure in-range high check), then 0x4115a "
     "and 0x41256, which are above the dumped ROM.",
     SLOT.format(live="cm550_runEvery20FramesTaskSetPhase1") +
     "It is the only caller of 0xe998. Two of its three callees are not in the dump, so a name from what it runs "
     "(cm550_boostPressureInRangeMonitorTaskSet) would rest on one callee out of three; the slot name is what the code "
     "proves.",
     "cm550_runEvery20FramesTaskSetPhase1", "high",
     "none proven. CM848 runs its boost monitor from cm848_periodicTaskGroup21_calibration @ 0xc000, between the oil "
     "pressure task and an EGR orifice temperature check: a different list, and two CM550 callees are unknown.")

role("0x1b788",
     "Executive frame task set of the every-20-frames group, run in phases 3 and 23 (bsr.w from 0x1b9e6 and 0x1bc98; "
     "every 100 ms): it calls 0x491b4 (above the dumped ROM; also the single callee of the task set 0x1b836 in phases "
     "15 / 35), 0xac3c (the duty cycle monitor sample), 0x26cc8 (the two engine percent load words) and 0x26e2c (the "
     "percent load on the low horsepower curve).",
     SLOT.format(live="cm550_runEvery20FramesTaskSetPhase3") +
     "Three of its four callees are dumped, so a name from what it runs would be "
     "cm550_dutyCycleMonitorAndEngineLoadTaskSet (medium: the first callee is unknown). The rows "
     "cm550_slowCycle8Coordinator (0x1b78e) and cm550_engineParameterAndBoostControlWrapper (0x1b794) sit on its second "
     "and third jsr: nothing branches or points to them.",
     "cm550_runEvery20FramesTaskSetPhase3", "high",
     "none. CM848 runs the engine load percentages and the low horsepower percent load from "
     "cm848_periodicTaskGroup28_calibration10 @ 0xbdd8 (with two other monitors) and the duty cycle monitor from "
     "cm848_periodicTaskSet_outputs2 @ 0xc078.")

role("0x1b7f2",
     "Executive frame task set of the every-20-frames group, run in phases 11 and 31 (bsr.w from 0x1bafa and 0x1bd88; "
     "every 100 ms): it calls 0x46aac (above the dumped ROM), 0x1d9b4 (the idle shutdown state machine), then 0x40b30 "
     "and 0x422b4 (above the dumped ROM).",
     SLOT.format(live="cm550_runEvery20FramesTaskSetPhase11") +
     "It is the only caller of 0x1d9b4. Three of its four callees are above the dumped ROM, so a name from what it "
     "runs (cm550_idleShutdownTaskSet) would rest on one callee out of four. The four flags the state machine only "
     "reads have no setter in the dump, so one of the unknown callees may set them - the code does not show that. "
     "Nothing here touches the VP44 pump: the vp44_ prefix is unsupported.",
     "cm550_runEvery20FramesTaskSetPhase11", "high",
     "none (CM848 has no idle shutdown code; see 0x1d9b4).")

# ---------------------------------------------------------------------------------------------- idle shutdown
role("0x1d9b4",
     "The idle shutdown state machine, every 100 ms while idle_shutdown_enable (flags word 3 bit 1) is set and "
     "integrated_idle_management_enable (word 28 bit 4) is clear: a six-way switch on the state word 0x80d674 (e2m "
     "ISST) that reloads or counts down the idle shutdown timer, raises the warning and override lamp requests, waits "
     "out the warning period and then sets engine_shutdown_command_flag. It ends by saving the state it entered with "
     "as the previous state (0x800752).",
     "The only writer of the state word besides the initializer 0x1db8a, and the only idle shutdown code that sets "
     "engine_shutdown_command_flag. Every input is an idle shutdown flag (ISRSFG 0x80d67c, ISRSWNFG 0x80d67e, ISODRSFG "
     "0x80d680, ISODFG 0x80d682 - none has a setter in the dumped ROM), a calibration word (period ISTMLM 0x803c02, "
     "warning period ISWRTMLM 0x808150, the option bits idle_shutdown_override_enable and "
     "idle_shutdown_temperature_enable) or engine_state CRANKING: it reads no sensor, switch or VP44 word, so the "
     "'vp44 sensor status monitor' name is wrong in every word. RESET clears and SHUTDOWN sets output 30 (mask 0x40 of "
     "the output command byte 0x80bcf9) when that output's override priority byte 0x80bd38 is 0. The per-state "
     "behaviour is in enum_roles and the proposed global names are in note 2. Its words are read by the J1587 PID 71 "
     "status byte (case 0x47 at 0xefa2-0xf008), by the PGN 65252 transmit callback 0x33d38 and by the lamp blink "
     "function 0x249ee.",
     "cm550_runIdleShutdownStateMachine", "high",
     "none - the task's premise that CM848 has an idle shutdown state machine does not hold for S90140.06. The e2m "
     "blocks of CM550's machine (10CD state / timer / flags, 10CC warning period) are proven absent from CM848's "
     "parameter ID table, no code loads Idle_Shutdown_Period, flags word 3 bits 1 / 2 have no reader, the only stores "
     "to engine_shutdown_command_flag are the diagnostic service and the engine protection shutdown, and PGN 65252 is "
     "only received. The evidence is in note 1. So the state word and the enum are CM550-only names.")

role("0x1db8a",
     "Start-up initializer of the idle shutdown state machine (jsr from 0x287bc in mc68k_applicationMain's start "
     "list): it clears the overridden flag ISOD, loads the timer with the period, sets the state word to 0 and the "
     "reset flag ISRSFG to 1, and clears both lamp requests, ISODFG and engine_shutdown_command_flag. It also clears "
     "output 30 (mask 0x40 of 0x80bcf9) when that output's override priority byte 0x80bd38 is 0.",
     "Writes only the idle shutdown block 10CD (0x80d672-0x80d684), the shutdown command and output 30, and runs once "
     "at start; the RAM dump still holds its values (state 0, timer 36000 = the period, ISRSFG 1). The row "
     "vp44_fuelArbitratorVariablesReset (0x1db9a) is the third instruction of this function: nothing branches or "
     "points to it.",
     "cm550_initializeIdleShutdown", "high",
     "none (no idle shutdown code in CM848).")

# ---------------------------------------------------------------------------------------------- lamp control
role("0x254b6",
     "The lamp control task, every 50 ms: while the power-up lamp sequence is in progress it runs only that; otherwise "
     "it runs the fault code flash-out, then the shutdown warning blinks when the flash-out is idle, then the active "
     "fault lamps when those are idle too. It then runs the three oil change monitor lamp flashes on their conditions "
     "and saves the idle increment, idle decrement and diagnostic switch states as the previous states for the next "
     "pass.",
     "The only caller of all seven lamp functions and the place that orders them by priority (0x8019d2 in progress -> "
     "0x24858 and return; 0x24d40; 0x249ee; 0x24f30 after storing 'no fault' 0x7d in 0x8019e7). Conditions: pass "
     "counter 0x801a22 (counts to 401) between 100 and 399 with the oil change due flag OCITWNFG 0x80daae -> 0x25316; "
     "reset flag OCRSFG 0x80dab0 or latch 0x801a1c -> 0x253b0; OCRNSTEA 0x803c42 nonzero, due flag and engine_state "
     "RUNNING -> 0x25448; previous switch states 0x8019eb / 0x8019ec / 0x8019ed from masks 0x20 / 0x40 / 0x80 of "
     "0x80bccf. Its product is the lamp request word 0x80daac (bit 0 stop lamp, bit 1 warning lamp, bit 2 fluids "
     "lamp), which processProtectionFlagConditions (0x23a90) copies to the lamp driver outputs from the next task set. "
     "'Lamp control' is the e2m's own module prefix (LC: LCLPTB, LCFUFHMD, LCDGSTLP). It is more than a fault lamp "
     "family: power-up sequence, fault flash-out, shutdown warnings, fault lamps and oil change reminders.",
     "cm550_runLampControl", "high",
     "none. CM848 has the lamp records (block 1006 Lamp_Blink_On_Time / Lamp_Sequence_Table at ROM 0x5a752, block 1094 "
     "flags) but no code reads the block 1006 constants, its stop / warning / maintenance fault lamp flags have no "
     "writer, its oil change due flag has no reader, and the fault flash block 13EF is proven absent from its "
     "parameter ID table.")

role("0x1b70c",
     "Executive frame task set of the every-10-frames group, run in phases 5, 15, 25 and 35 (bsr.w from 0x1ba24, "
     "0x1bb86, 0x1bcd0 and 0x1be02; every 50 ms): a single jsr to 0x254b6, the lamp control task.",
     SLOT.format(live="cm550_runEvery10FramesTaskSetPhase5") +
     "Its frozen name (cm550_dzgTimingAndPressureSlowCycle10Coordinator) is wrong in its subject: it runs the lamp "
     "control and nothing about timing or pressure; only the period 10 is right. As a one-call wrapper it could also "
     "take its callee's name with a task suffix (cm550_runLampControlTask). Extra entry: the caller of 0x254b6.",
     "cm550_runEvery10FramesTaskSetPhase5", "high",
     "none.")

role("0x24858",
     "The power-up lamp sequence: on its first pass it turns on every output listed in a 16-word ROM table and takes "
     "each one's override priority with 0x80, then turns them off one at a time, the first after 40 passes (2 s) and "
     "one more every 10 passes. After the end of the list and 30 more passes it releases the override priorities, "
     "clears the in-progress byte that made the lamp task run nothing else and zeroes the three previous switch "
     "states.",
     "The only lamp function that writes the output command bits (0x80bcf6 + n / 8, bit n mod 8) and the override "
     "priority bytes (0x80bd1a + n) directly instead of the lamp request word, and the only one driven by a ROM list: "
     "0x611a8-0x611c6, above the dumped ROM, which the e2m names LCLPTB 'table - up to 15 values that specify powerup "
     "lamp sequence order' (block 1006 +8, 32 bytes). State: 0x8019d2 in progress, 0x8019d3 first pass, 0x8019d4 end "
     "phase, counter 0x8019f0, threshold 0x8019f8, list pointer 0x8019f4. The current name "
     "(cm550_ioControlMaskStateMachine) does not fit: no I/O control mask, and the e2m record names the job.",
     "cm550_runPowerUpLampSequence", "high",
     "none: CM848's Lamp_Sequence_Table (e2m 1006 +4, ROM 0x5a756) has no reader.")

role("0x2482e",
     "Arms the power-up lamp sequence at start-up (jsr from 0x287c2 and 0x2898a): in-progress byte 0x8019d2 = 1, "
     "first-pass byte 0x8019d3 = 1, end-phase byte 0x8019d4 = 0, pass counter 0x8019f0 = 0. It also clears the fault "
     "flash-out's cycle-complete byte and repetition count.",
     "Only stores constants; 0x24858 does the sequence. The current name (cm550_ioControlMaskInit) does not fit. Extra "
     "entry (a helper of the family).",
     "cm550_startPowerUpLampSequence", "medium",
     "none.")

role("0x249ee",
     "Blinks lamps for three shutdown warnings and returns 1 only when none of them is active: the warning lamp while "
     "the idle shutdown warning request is set, the stop lamp while the engine protection shutdown approaching flag is "
     "set, and the warning lamp for 120 blinks once the idle shutdown override lamp request is 1, after which it "
     "clears that request.",
     "The only lamp function whose inputs are the idle shutdown requests ISWRRQ (0x80d67a) and ISODRQ (0x80d684) and "
     "the engine protection flag EPSQ (0x80d28e, e2m 'EPS shutdown approaching'), and the only one that clears ISODRQ. "
     "The first two blinks use the ROM on / off pass counts 0x611a0 / 0x611a2 (e2m LCLPONTM / LCLPFFTM 'length of time "
     "the warning or stop lamp is on / off when flashing', 50 ms per count); the override blink is 10 passes on / 10 "
     "off, its blinks counted in 0x8019e3; active latches 0x8019e0-0x8019e2. The current name "
     "(vp44_ioControlLampStateMachine) "
     "does not fit: no VP44 data, no I/O control, no state word.",
     "cm550_blinkShutdownWarningLamps", "high",
     "none. CM848 sets the same approaching flag and an override lamp flag (e2m 10B1 +14 / +19) but nothing reads the "
     "lamp flag.")

role("0x24d40",
     "Fault code flash-out, active only while the diagnostic test switch is on and engine_state is STOPPED (otherwise "
     "it turns the stop and warning lamps off once and returns 1): it picks an active fault - the first on the "
     "switch's rising edge, the next / previous on a rising edge of the idle increment / decrement switch, or the next "
     "by itself in automatic mode after the set number of flashes - and flashes that fault's three-digit code. With no "
     "fault to show it lights both lamps, and it returns 0 so the lamp task skips the other stop / warning lamp logic.",
     "The only lamp function gated by the diagnostic test switch (DSTESWSS, mask 0x80 of 0x80bccf) with the engine "
     "stopped, and the only caller of the fault selectors 0x24c5a / 0x24cd2 and the digit sequencer 0x24b4e. Code = "
     "word 0 of the fault record (0x8067c4 + 6 x index); automatic mode LCFUFHMD 0x80820c, flash count LCFUFHCU "
     "0x80820d; current fault 0x8019e7, repetition count 0x8019ea. The current name "
     "(cm550_faultCodeDisplayController) fits its code, so no rename is proposed (the e2m's word for the job is 'fault "
     "flash').",
     "cm550_faultCodeDisplayController", "high",
     "none (the fault flash block 13EF is proven absent from CM848's parameter ID table).")

role("0x24b4e",
     "Flashes one three-digit fault code, one step per pass: a warning lamp flash of 40 passes with the stop lamp off, "
     "then the hundreds, tens and units digits as that many stop lamp flashes with pauses between them, then it sets "
     "the cycle-complete byte. On its first step it splits the code into the three digits.",
     "Takes the fault code as its argument and is called only by 0x24d40. Phase word 0x8019d6 (digits start at 40, 80 "
     "and 120, the end is 160), digits 0x8019e4-0x8019e6, flash counter 0x8019ee, cycle-complete byte 0x8019e9. The "
     "current name (cm550_ioControlDigitDisplaySequencer) is right about digits and sequencing but 'ioControl' is "
     "wrong. Extra entry (a helper of the family).",
     "cm550_flashFaultCodeDigits", "high",
     "none.")

role("0x249b6",
     "One stop lamp flash for a fault code digit: stop lamp bit on at count 0, off at count 10, and at count 20 it "
     "resets the counter and returns 1 (the flash is done); otherwise it counts and returns 0.",
     "Called three times, only by the digit sequencer 0x24b4e; counter 0x8019d8. The current name "
     "(cm550_ioControlToggleCycle) does not say which lamp or why. Extra entry (a helper of the family).",
     "cm550_flashStopLampOnce", "high",
     "none.")

role("0x24c5a",
     "Returns the next active fault to flash: it steps the navigation index (0x8019f2) forward through "
     "active_dtc_list (to entry 1 from 'none' 0x7d or past the count), at most once per list entry, and returns the "
     "first fault whose control bits have mask 0x40 clear, or 0x7d when there is none.",
     "Forward step; called for the diagnostic switch edge, the idle increment switch edge and the automatic mode. "
     "0x24cd2 is the same loop stepping backward.",
     "cm550_selectNextFaultCodeToFlash", "high",
     "none.")

role("0x24cd2",
     "Returns the previous active fault to flash: the same loop as 0x24c5a with the navigation index stepping backward "
     "(to the list count from 'none' or from entry 1).",
     "Backward step; its only caller is the idle decrement switch edge in 0x24d40.",
     "cm550_selectPreviousFaultCodeToFlash", "high",
     "none.")

role("0x24f30",
     "Sets the stop, warning and fluids lamp requests from the active fault list: each active fault's control bits "
     "pick its lamp (stop before warning before fluids) and whether it blinks, unless the fault is marked 'no lamp' or "
     "its bit is set in the per-fault lamp-off bitmap. It also sets the three J1939-73 diagnostic lamp flags, and then "
     "makes each lamp blink, stay on or go off.",
     "The only lamp function that walks active_dtc_list and the only writer of LCDGSTLP / LCDGWNLP / LCDGFDLP "
     "(0x80dab2 / 0x80dab4 / 0x80dab6); it runs last, only when neither the flash-out nor a shutdown warning blink is "
     "active. Control bits word 0x8067c6 + 6 x index (e2m DGnnnnCB 'fault control bits'): bit 0 stop lamp, bit 1 "
     "warning lamp, bit 2 fluids lamp, bit 3 blink, bit 6 no lamp; bitmap 0x803fb6 = e2m DGFULPEN + 2 ('bit map "
     "parameter for faults, 0 = lamp on, 1 = lamp off'; all 0 in the dump); blink on / off counts LCLPONTM / LCLPFFTM. "
     "The current name (cm550_activeFaultLampStateMachine) has the right subject but the function is not a state "
     "machine - it has three blink phase counters and no state word - so a rename is proposed.",
     "cm550_updateLampRequestsFromActiveFaults", "high",
     "none. CM848 names the same three flags stop_fault_lamp_flag / warning_fault_lamp_flag / "
     "maintenance_fault_lamp_flag (e2m 1094 +6 / +8 / +A) and reads them in cm848_buildJ1939LampStatusByte, but "
     "nothing writes them.")

role("0x25316",
     "Flashes the fluids lamp bit (mask 0x4 of the lamp request word) in groups of three flashes and stops after 5 "
     "groups; nothing in the dumped ROM resets the group counter, so it runs once per power-up. Its caller runs it "
     "only between passes "
     "100 and 399 of the lamp task (5 to 20 s after start) while the oil change due flag OCITWNFG (0x80daae) is set.",
     "Fluids lamp bit, a limit of five groups and the start-up window: the oil change due signal after key-on. Pass "
     "counter 0x801a18 (on in passes 1-5, 12-17 and 24-29; a group is 48 passes), group counter 0x801a16. The current "
     "name (cm550_faultLampBlinkPatternGenerator) does not fit: no fault is involved. 'Fluids lamp' is CM550's e2m "
     "word for this lamp (LCDGFDLP, FLLPONTM); CM848's e2m calls the same record the maintenance lamp.",
     "cm550_flashFluidsLampForOilChangeDueAfterPowerUp", "high",
     "none (oil_change_monitor_change_due_flag has no reader in CM848).")

role("0x253b0",
     "One pass of a three-flash sequence on the warning lamp bit (mask 0x2) of the lamp request word: a pass counter "
     "turns the lamp on three times, about 0.25 s each with 0.9 s gaps, and an in-progress latch makes a started "
     "sequence run to its end. Its caller starts it when the oil change monitor reset flag OCRSFG (0x80dab0, "
     "'indicates a manual reset was performed on OCM data') is set.",
     "Warning lamp bit, exactly three flashes, one sequence per trigger: counter 0x801a1a (on in passes 1-5, 24-29 and "
     "48-53, off in between), latch 0x801a1c set in the first on phase and cleared with the counter at pass 72. The "
     "neighbours 0x25316 and 0x25448 flash the fluids lamp bit (0x4) for the oil change due flag instead.",
     "cm550_flashWarningLampForOilChangeMonitorReset", "high",
     "none. CM848 has the flag (oil_change_monitor_reset_flag, e2m 1094 +4, consumed by cm848_updateOilChangeMonitor) "
     "but no lamp flash code.")

role("0x25448",
     "Periodic reminder on the fluids lamp bit (mask 0x4): it counts 36000 passes (30 minutes), then gives 4 flashes "
     "of about 1 s on and 3 s off, then starts over. Its caller runs it only while OCRNSTEA (0x803c42, 'enables use of "
     "warning light with engine in run state') is nonzero, the oil change due flag is set and engine_state is RUNNING.",
     "The only lamp function with the 36000-pass wait and the RUNNING gate. Counter 0x801a1e, flashing byte 0x801a1d, "
     "flash count 0x801a20 (19 passes on, 60 off per flash). The current name (cm550_periodicLampFlashController) is "
     "true but names neither the lamp nor the reason, so a rename is proposed.",
     "cm550_flashFluidsLampForOilChangeDueWhileRunning", "high",
     "none (CM848 keeps the calibration word OCM_Warning_While_Running, 0x3fdd62, with no access in its code).")

# ---------------------------------------------------------------------------------------------- serial EEPROM
role("0x26834",
     "The QSPI interrupt handler of the serial EEPROM driver (it ends in rte): it clears SPIF in QSM_SPSR, runs one "
     "step of the driver (bsr 0x266da) and sets SPE in QSM_SPCR1 to start the next queue pass.",
     "It is not called: 0x26854 stores its address in 0x808f20, the QSPI vector 0x51 of the RAM vector table (movec "
     "a0,vbr with 0x808ddc at 0x28650; QIVR = 0x50 at 0x2866c), and the RAM dump holds 0x00026834 there. The polled "
     "loop in 0x26854 does the same three steps inline before the interrupt is enabled.",
     "mc68k_serialEepromQspiInterruptHandler", "high",
     "cm848_onQspiFinished @ 0x3dcf4 (clears SPIF, then cm848_completeQspiJob) - counterpart, not a twin: CM848's "
     "handler serves a job queue shared by every QSPI device; CM550's serves the EEPROM alone and restarts the queue "
     "itself.")

role("0x26852",
     "An empty function: a single rts, called once by bsr.s at the start of 0x26854.",
     "No code, so no role can be read from it; the only fact is its one caller, the serial EEPROM initialization. A "
     "name would be a guess.",
     "", "high",
     "none.")

role("0x26854",
     "Start-up initialization of the serial EEPROM driver, called once from the straight-line start section of "
     "mc68k_applicationMain (0x28674), which also loads the EEPROM image into RAM before it returns: it installs the "
     "QSPI interrupt handler, sets up the QSM pins, control registers and a READ queue, sets ram_refresh_enable and "
     "runs the queue in a polled loop (servicing both watchdogs) until the whole image has been read. It then enables "
     "the QSPI interrupt and shortens the length, so the interrupt-driven driver keeps re-reading only the EEPROM "
     "mirror.",
     "It is the initializer, not the loop step of the batch title: the per-pass EEPROM write / RAM refresh step is "
     "0x266da (mc68k_runSerialEepromWriteQueue), which this function calls from its polled loop and which the "
     "interrupt handler 0x26834 calls afterwards. The only writer of the QSPI set-up for the EEPROM (PQSPAR / DDRQS / "
     "PORTQS, SPCR0 0x8004, queue entries 2-15: READ opcode 3, the address word, 12 data words), of the destination "
     "pointer 0x801a8e (= 0x803b0a) and of the two lengths in 0x801a88: 0x148a for the power-up load "
     "(0x803b0a-0x804f93), then 0x64c (the mirror 0x803b0a-0x804155). It waits on the loaded flag 0x801a92 and "
     "afterwards sets the delay DTL to 0x23 and SPIFIE.",
     "mc68k_initializeSerialEepromDriverAndLoadMirror", "high",
     "cm848_initEepromDriverAndLoadMirror @ 0x4cb64 - counterpart, not a twin: the same sequence of ram_refresh_enable "
     "= 1, mirror base pointer, full length (0x1a40), loop until the loaded flag, then the shorter refresh length "
     "(0x8e8), but through CM848's QSPI job layer and followed by the block checksum.")

# ---------------------------------------------------------------------------------------------- percent load
role("0x26e2c",
     "Calculates the percent load on the low horsepower curve SPT0PCLD (0x80db62): when final fueling (0x80d32e) and "
     "the low horsepower curve fueling FST0MXFL (0x80d36a) are both above the no-load fueling (0x80db1c) it stores "
     "(final - no-load) x 0x6400 / (low horsepower fueling - no-load), else 0.",
     "The only reference to 0x80db62 in the dumped ROM. Its sibling 0x26cc8 divides by the 100 percent throttle "
     "fueling and by the fuel left on the high speed governor droop line; this one divides by the low horsepower "
     "curve fueling. The divide is divu.l followed by move.w of the low word: no overflow branch and no clamp.",
     "cm550_calculateEngineLoadLowHorsepowerCurvePercent", "high",
     "cm848_validateFuelDemandRelativeToTiming @ 0x50e000 - counterpart, not a twin. Same inputs and output by e2m "
     "record (final fueling, no-load fuel, 105A +2, result 10BF +4), same two tests, same x 0x6400 division, and it "
     "also runs right after the engine load percentages in a task set that runs twice per 40 phases "
     "(cm848_periodicTaskGroup28_calibration10); but CM848 clamps the quotient at 0xff00 "
     "and CM550 has no clamp, so by the twin rule the two keep separate prefixed names. CM848's current name is an old "
     "one that does not describe it (it stores engine_load_low_horsepower_curve_percent): "
     "cm848_calculateEngineLoadLowHorsepowerCurvePercent would make the pair parallel.")

role("0x26cc8",
     "Calculates the two engine percent load words in 1/256 percent: FSPCLD (0x80db60) = (final fueling - no-load "
     "fueling) x 0x6400 / (100 percent throttle fueling - no-load fueling), and JCPCLD (0x80db5e), the same fuel over "
     "what is available at the current speed - the fuel left on the high speed governor droop line when the engine "
     "speed is above the droop speed and the droop is active, else the 100 percent throttle fueling. Both are clamped "
     "at 0x7f80, and JCPCLD is forced to 0x6400 while final_fueling_state is FUELING_STATE_HIGH_SPEED_GOVERNOR.",
     "The percent load producer: the boost check 0xe998 reads its JCPCLD. Its current name "
     "(calculateSpeedRatioComponent) is wrong in subject and is unprefixed although no CM848 row carries it.",
     "cm550_calculateEngineLoadPercentages", "high",
     "cm848_calculateEngineLoadPercentages @ 0x50de54 - counterpart, not a twin: same two outputs, constants (0x6400, "
     "0x7f80, 0x1111, 0x1700) and the governor state 12 override, but the full-load fuel is "
     "injection_quantity_combustion_chi_maximum and the zero / droop-inactive cases give different results.")

# ---------------------------------------------------------------------------------------------- enum
LABEL = ("Corroboration: the Idle_Shutdown_State record of the later CHR_B2 e2m files, whose description is ISST's "
         "sentence, labels the values 0=RESET:1=COUNT:2=WARNING:3=DELAY:4=OVERRIDE:5=SHUTDOWN.")
enum_roles = [
    {"enum_name": "IDLE_SHUTDOWN_STATE", "value": 0,
     "meaning": "IDLE_SHUTDOWN_STATE_RESET - the timer is reloaded with the period, the warning request, the "
                "overridden flag ISOD and ISODFG are cleared and output 30 is cleared; it leaves to COUNT when the "
                "reset flag ISRSFG is 0.",
     "evidence": "Case 0 at 0x1da0c-0x1da44 (jump table 0x1da00). The e2m text of the flag it tests, ISRSFG at "
                 "0x80d67c, names both states: '1 - transition to reset from count; 0 - transition to count' - and "
                 "the code goes 0 -> 1 on ISRSFG = 0 and 1 -> 0 on ISRSFG = 1. The initializer stores 0, and the "
                 "PGN 65252 callback sends byte 1 = 0x00 for it (nothing active). " + LABEL},
    {"enum_name": "IDLE_SHUTDOWN_STATE", "value": 1,
     "meaning": "IDLE_SHUTDOWN_STATE_COUNT - the timer counts down; back to RESET on ISRSFG = 1, to DELAY when the "
                "temperature option is enabled and ISODFG is 1, to WARNING when the timer is at or below the warning "
                "period. It also zeroes the warning timer and loads the delay timer with 600.",
     "evidence": "Case 1 at 0x1da48-0x1da9c: subq.w #1 on the timer ISTM ('dec. and hold timer'). ISRSFG text as "
                 "for state 0. PGN 65252 byte 1 = 0x40 (SPN 590 idle shutdown timer state = active)."},
    {"enum_name": "IDLE_SHUTDOWN_STATE", "value": 2,
     "meaning": "IDLE_SHUTDOWN_STATE_WARNING - the timer keeps counting down, the lamp request ISWRRQ is 1 and a "
                "warning timer (0x800754) counts up; to OVERRIDE when the override option is enabled and ISODFG is 1, "
                "to RESET on ISRSWNFG = 1, to SHUTDOWN when the warning timer reaches the warning period.",
     "evidence": "Case 2 at 0x1daa0-0x1daf4. The texts of the words it uses name the state: ISWRRQ 'blink yellow lamp "
                 "to indicate idle shutdown approach', ISRSWNFG '1 - transition to reset from warning', ISWRTMLM "
                 "'time allotted to indicate approaching shutdown'. PGN 65252 byte 1 = 0x44 (timer active + SPN 594 "
                 "driver alert mode)."},
    {"enum_name": "IDLE_SHUTDOWN_STATE", "value": 3,
     "meaning": "IDLE_SHUTDOWN_STATE_DELAY - a 600-pass (60 s) countdown of the delay timer 0x800756 before the "
                "override; to RESET on ISRSFG = 1, to OVERRIDE when the countdown reaches 0.",
     "evidence": "Case 3 at 0x1daf8-0x1db20: it only counts 0x800756 down and tests ISRSFG; entered only from COUNT "
                 "with idle_shutdown_temperature_enable set and ISODFG = 1, and COUNT loads the 600 each pass. So the "
                 "code proves 'a timed delay before the override'; a fully code-derived member name would be "
                 "IDLE_SHUTDOWN_STATE_DELAY_BEFORE_OVERRIDE. No e2m text of this ROM names the state, and the PGN "
                 "65252 callback leaves byte 1 unchanged for it (jump table entry 0x26 at 0x33d5a). The word DELAY "
                 "is the later family's label (0=RESET:1=COUNT:2=WARNING:3=DELAY:4=OVERRIDE:5=SHUTDOWN in the CHR_B2 "
                 "Idle_Shutdown_State record). This is the weakest member."},
    {"enum_name": "IDLE_SHUTDOWN_STATE", "value": 4,
     "meaning": "IDLE_SHUTDOWN_STATE_OVERRIDE - the timer is held at the period, the warning request is cleared, the "
                "overridden flag ISOD and the override lamp request ISODRQ are set; to RESET on ISODRSFG = 1.",
     "evidence": "Case 4 at 0x1db22-0x1db46. The texts of its words name the state: ISOD '1 - idle shutdown is "
                 "overridden until vehicle moves', ISODRQ 'blink yellow lamp to indicate idle shutdown is "
                 "overridden', ISODRSFG '1 - transition to reset from override'. PGN 65252 byte 1 = 0x10 (SPN 592 "
                 "idle shutdown timer override)."},
    {"enum_name": "IDLE_SHUTDOWN_STATE", "value": 5,
     "meaning": "IDLE_SHUTDOWN_STATE_SHUTDOWN - on entry (previous state 0x800752 not 5) it clears the warning "
                "request and sets engine_shutdown_command_flag and output 30; back to RESET when engine_state is "
                "CRANKING.",
     "evidence": "Case 5 at 0x1db48-0x1db7c: move.w #1 to 0x80d28c (e2m SHSS, the engine shutdown command). PGN "
                 "65252 byte 1 = 0x01 (SPN 593 idle shutdown has shut down engine), and the J1587 PID 71 byte sets "
                 "mask 0x02 when the shutdown command is set and the timer is 0 (0xefe8-0xeff8)."},
]

# ---------------------------------------------------------------------------------------------- notes
notes = " ".join([
    "(1) CM848 IDLE SHUTDOWN = NONE. The task says CM848 has an idle shutdown state machine too; the S90140.06 images "
    "do not support that. Points (a) to (d) are scans of the images by address and do not depend on any name; (e) "
    "and (f) come from the decompilation and the CSVs. (a) CM848's parameter ID table (flash2 "
    "0x53be38) is ordered by block id mod 1889 and the dump ends at bucket 1417, so absence is provable below that: "
    "CM550's idle shutdown blocks 10CD (state / timer / flags, bucket 523) and 10CC (warning period, bucket 522) are "
    "absent. The later family's blocks 06B2 / 0738 / 0739 fall in the part of the table that was not dumped, so they "
    "are not proven absent - but CM848's own e2m (CHR_CC_11.45.01.07) has no record whose block column is one of "
    "them; (b) that e2m keeps only "
    "calibration leftovers: Idle_Shutdown_Period / _Max_IMT / _Min_IMT (0x3fdd4c / 0x3fdd48 / 0x3fdd4a), tool limits, "
    "Idle_Shutdown_Temperature_Enable and Jcomm_Idle_Shutdown_Message_Default_Priority (0x3fd862). A scan of ROM and "
    "flash2 for lis + displacement accesses finds none of them (the same scan finds the neighbour "
    "power_take_off_resume_speed_cal 0x3fdd50 four times), which the round 29 e2m audit also recorded; (c) the same "
    "scan on engine_shutdown_command_flag (0x40a784) finds stores only at 0x216f0 (commandEngineShutdown), 0x508d1c "
    "(cm848_updateEngineProtectionShutdown, which also takes the address at 0x508988) and 0x508e18 "
    "(cm848_resetEngineProtectionShutdownState), plus the clear in cm848_updateEngineState; (d) 0xfee4 (PGN 65252) is "
    "an immediate once in CM848: the receive registration at 0x50be20 - no transmit; (e) every use of "
    "algorithm_enable_flags_3_cal in the .cpp is a cruise, power take-off, road speed governor, gear down or save set "
    "speed bit - never bit 1 or 2 - and idle_shutdown_temperature_enable has no use; (f) the enum "
    "HIGH_RPM_PROTECTION_STATE (0-4, 'SHUTDOWN_PENDING ... waiting for idle') and HIGH_RPM_PROTECTION_FLAGS sit in "
    "BOTH firmwares' enums.csv but no global, field, parameter or local is typed with them and neither .cpp shows a "
    "member. They are leftovers of the old automatic pass: the FLAGS masks (0x80 / 0x08 / 0x04 / 0x02 / 0x01) are "
    "exactly CM550's J1587 PID 71 idle shutdown status byte, and INSITE_PARAM_CODE 0x47 HIGH_RPM_PROTECTION_STATUS is "
    "PID 71. They can be retired or renamed with this batch; they are not a CM848 machine.",

    "(2) IDLE SHUTDOWN GLOBALS (address -> proposed name; e2m record; every access is a word): 0x80d672 -> "
    "idle_shutdown_overridden_flag (10CD +0 ISOD '1 - idle shutdown is overridden until vehicle moves'); 0x80d674 -> "
    "idle_shutdown_state, type IDLE_SHUTDOWN_STATE (10CD +2 ISST 'indicates the present state of the idle shutdown "
    "algorithm' 0-5; now vp44_sensor_monitor_state); 0x80d676 -> idle_shutdown_timer (10CD +4 ISTM 'dec. and hold "
    "timer', 0.1 s per count; now vp44_sensor_countdown_timer); 0x80d678 -> idle_shutdown_timer_status (10CD +6 "
    "ISTMSS 'timer status as used in J1587 PID 71'; no reference in the dumped ROM, a record-only name); 0x80d67a -> "
    "idle_shutdown_warning_lamp_request (10CD +8 ISWRRQ; now vp44_sensor_warning_active); 0x80d67c -> "
    "idle_shutdown_reset_flag (10CD +A ISRSFG; tested in RESET, COUNT and DELAY; now "
    "vp44_sensor_monitor_reset_request); 0x80d67e -> idle_shutdown_reset_from_warning_flag (10CD +C ISRSWNFG); "
    "0x80d680 -> idle_shutdown_reset_from_override_flag (10CD +E ISODRSFG); 0x80d682 -> "
    "idle_shutdown_override_successful_flag (10CD +10 ISODFG '1 - override procedure was successful'; now "
    "vp44_sensor_secondary_fault); 0x80d684 -> idle_shutdown_override_lamp_request (10CD +12 ISODRQ; now "
    "vp44_sensor_shutdown_lamp_request); 0x803c02 -> idle_shutdown_period_cal (0008 +66 ISTMLM 'delay period before "
    "idle shutdown occurs', 0.1 s; inside the EEPROM mirror; 36000 = 1 h in the dump); 0x808150 -> "
    "idle_shutdown_warning_period (10CC +8 ISWRTMLM 'time allotted to indicate approaching shutdown'; outside the "
    "mirror, so no _cal; 300 = 30 s in the dump). No e2m record: 0x800752 -> idle_shutdown_previous_state (the state "
    "at entry of the previous pass; only compared with 5), 0x800754 -> idle_shutdown_warning_timer (zeroed in COUNT, "
    "+1 per pass in WARNING, compared with the warning period; now vp44_sensor_failure_counter), 0x800756 -> "
    "idle_shutdown_delay_timer (600 in COUNT, -1 per pass in DELAY; now vp44_sensor_wait_timer). The later CHR_B2 "
    "e2m family labels the records with these same descriptions Idle_Shutdown_State / _Reset_Flag / "
    "_Reset_From_Warning_Flag / _Reset_From_Override_Flag / _Override_Flag ('override procedure was successful') / "
    "_Override ('overridden until vehicle moves') / _Timer / _Warning_Lamp_Request / _Warning_Period / _Period, "
    "which is where the proposed words come from. 0x80bd38 "
    "(engine_brake_lamp_driver_control) is output 30's override priority byte (0x80bd1a + 30) and the bit it guards "
    "is output 30 = mask 0x40 of 0x80bcf9 (bit_4_of_master_status_byte_a_0_1). The e2m puts the idle shutdown relay "
    "record ISDR 'auxiliary output for relay to turn off electrics' on that byte with a text that says bit 4, and "
    "its mask 0x40 records are Top2 transmission solenoids, so the output's name is not proven; "
    "processProtectionFlagConditions drives the same output from lamp request bits 0x20 / 0x40. 0x80d28e "
    "(engine_protection_derate_approaching_flag) is e2m 10B1 +14 EPSQ 'EPS shutdown approaching', the record CM848 "
    "names engine_protection_shutdown_approaching_flag. In the RAM dump the idle shutdown is disabled (flags word 3 = "
    "0x86e8).",

    "(3) FRAME PERIOD = 5 ms, from independent e2m scales: on tasks of the every-20-frames group ISTM (0.1 s per "
    "count, one decrement per pass), the duty cycle log period (hours x 36000 samples) and the BIR times DGBSDCTR / "
    "DGBSHTTD (0.1 s); on the lamp task (every 10 frames) LCLPONTM / LCLPFFTM (50 ms per count, one count per pass).",

    "(4) WRAPPER BLOCK 0x1b4d0-0x1b874 (the task asked whether the named neighbours are wrong): in the frozen copy "
    "the real entries are the 45 addresses after an rts, every one a bsr.w target of the executive (0x1b4d0 through "
    "jsr (a5)): every frame 0x1b4d0; every 2 frames 0x1b4d8 / 0x1b504; every 4 0x1b518 / 0x1b572 / 0x1b5ce / "
    "0x1b612; every 8 0x1b668-0x1b6b2 (8 entries); every 10 0x1b6b4-0x1b732 (10); every 20 0x1b73a-0x1b862 (20). 21 "
    "frozen rows sit on a jsr inside a wrapper or on its rts (0x1b4ea, 0x1b4f6, 0x1b558, 0x1b56a, 0x1b57e, 0x1b5b4, "
    "0x1b5ba, 0x1b604, 0x1b60a, 0x1b62a, 0x1b6ba, 0x1b6c6, 0x1b6ce, 0x1b6d4, 0x1b6f8, 0x1b6fe, 0x1b70a, 0x1b71a, "
    "0x1b78e, 0x1b794, 0x1b7d8) and 0x1b4c2 is an instruction inside the interrupt handler 0x1b4b2: no branch and no "
    "pointer in the ROM reaches any of them. Frozen names of real entries that are wrong: 0x1b70c (lamp control, not "
    "timing and pressure); 0x1b72a cm550_camSyncDiagnosticProcessingSlowCycle20Coordinator runs every 10 frames, not "
    "20, and its one callee is mc68k_dispatchJ1708ReceivedMessages; 0x1b714 cm550_rpmBasedFuelLimiterCoordinator runs "
    "0x24804 (the lamp request word to the lamp driver outputs, then the lamp driver feedback faults) and 0x21146 - "
    "no fuel limiter; 0x1b85a vp44DiagnosticControlSlowCycle20Coordinator has one callee above the dump, so its name "
    "cannot be checked. The live repository has since removed the 21 rows (commit a417e39e) and named the 45 entries "
    "by slot (commit 7cf52470); the four slot names I give are those, and they match my phases (1 / 21, 3 / 23, "
    "11 / 31 and 5 / 15 / 25 / 35).",

    "(5) LAMP REQUEST WORD 0x80daac (row lamp_driver_output_bitmask): processProtectionFlagConditions (0x23a90) "
    "copies bit 0 to output 1 (mask 0x02 of 0x80bcf6, override priority 12A7 +1 'stop engine lamp'), bit 1 to output "
    "6 (mask 0x40, priority +6 'diagnostic lamp' = the warning lamp), bit 2 to output 4 (mask 0x10, priority +4 "
    "'engine protection lamp' = the e2m's fluids lamp), bit 3 to output 0 (wait to start lamp), bit 4 to output 2 "
    "(water in fuel lamp; set by the water in fuel monitor 0x34c36, whose name vp44FaultRegisterBit2Monitor is also "
    "wrong) and bits 5 / 6 to output 30. Cross-check from the fault record table in the RAM dump (0x8067c4, 6 bytes "
    "per fault, sorted by fault code): control bit 0 is set on 9 codes (151, 155, 234, 262, 361, 367, 373, 376, 415 - "
    "stop lamp faults), bit 1 on 68 codes (122 / 123 / 433 among them), bit 2 on code 235 only (coolant level) and "
    "bits 3 / 6 on none. active_dtc_list holds indices into that table and 0x7d (125) means none.",

    "(6) CM848 NAMES TO REUSE for the same e2m records in CM550: 0x80daae OCITWNFG -> "
    "oil_change_monitor_change_due_flag; 0x80dab0 OCRSFG -> oil_change_monitor_reset_flag; 0x80dab2 / 0x80dab4 / "
    "0x80dab6 LCDGSTLP / LCDGWNLP / LCDGFDLP -> stop_fault_lamp_flag / warning_fault_lamp_flag / "
    "maintenance_fault_lamp_flag (CM848's e2m calls CM550's fluids lamp the maintenance lamp; if the flag takes "
    "CM848's name, the two function names with FluidsLamp could say MaintenanceLamp instead).",

    "(7) UNLISTED ENTRIES AND STALE ROWS: 0xeadc (after the rts of 0xe998) resets the two BIR counters - no row, no "
    "reference in the dump. 0x33d38 (after the rts at 0x33d36; no row) is the PGN 65252 transmit callback, "
    "registered with period 1000 at 0x28d2e and on request at 0x2f586: it fills payload byte 1 from the idle "
    "shutdown state (0 -> 0x00, 1 -> 0x40, 2 -> 0x44, 3 unchanged, 4 -> 0x10, 5 -> 0x01; J1939 lists SPN 593 has "
    "shut down engine, 594 driver alert mode, 592 timer override and 590 timer state in that order, two bits each), "
    "byte 2 = 0x7f / 0x3f from idle_shutdown_enable (SPN 591 timer function), bytes 3 / 4 = 0xfd / 0xfc from bit 0 "
    "of 0x80bcd7 (A/C pressure switch) and bit 0 of 0x80bcf6 (wait to start lamp), then calls cm550_sendCanMessage; "
    "a name in CM848's pattern would be cm550_buildPgn65252ShutdownMessage. 0x33dfa "
    "vp44_engineHoursPGN_65252_Builder initializes that message's descriptor (priority from JCISSHPZ 0x803f78 "
    "'default network priority for idle shutdown message') and bytes 5-8 = 0xff: 'engineHours' is wrong, PGN 65252 "
    "is Shutdown. Rows inside other functions: 0x1db9a (vp44_fuelArbitratorVariablesReset, inside 0x1db8a) and "
    "0x2481e (cm550_initIoControlRegister, inside 0x24812).",

    "(8) SERIAL EEPROM DRIVER WORDS, typed can_buffer_setup_t with CAN names but used only by 0x266da / 0x26854: "
    "0x801a86 (diagnostic_can_response_header) = the EEPROM read offset, 0x801a88 (diag_can_response_pgn) = the load "
    "length, 0x801a8a = the driver state (0 read, 1 start a write, 2 write in progress), 0x801a8e = the mirror base "
    "pointer, 0x801a92 = the loaded flag; CM848's counterparts are eeprom_mirror_load_offset / "
    "eeprom_mirror_load_length / eeprom_driver_operation / eeprom_mirror_base_pointer / eeprom_mirror_loaded_flag. "
    "0x803b0a (ecu_identity_marker_1) is the first byte of the EEPROM mirror. The existing name "
    "mc68k_runSerialEepromWriteQueue (0x266da) covers half of that step: with no write queued it copies the 24 bytes "
    "just read into the mirror while ram_refresh_enable is on and queues the next read.",

    "(9) METHOD: this is the second run of the task. The first run was cut off after it had written its answer file; "
    "I re-checked every claim I reuse against the disassembly (m68k.py), the frozen CSVs, the e2m records at the "
    "addresses and the RAM dump, and changed what did not hold (the proof of absence in CM848's parameter ID table, "
    "the stop lamp code list, the power-up lamp sequence name, one verdict for 0x26e2c). Scratch scripts and notes: "
    "/home/linux/.claude/jobs/374b0424/tmp/w15/r93/scratch/D1/describer/ (notes.md, build_final2.py, "
    "final_output2.json).",
])

out = {"batch": "D1", "roles": roles, "enum_roles": enum_roles, "notes": notes}
path = "/home/linux/.claude/jobs/374b0424/tmp/w15/r93/scratch/D1/describer/final_output2.json"
json.dump(out, open(path, "w"), indent=1)
print("roles", len(roles), "enum members", len(enum_roles), "notes chars", len(notes))
names = [r["suggested_name"] for r in roles if r["suggested_name"]]
assert len(names) == len(set(names)), "duplicate suggested name"
for r in roles:
    assert r["confidence"] in ("high", "medium", "low")
    assert r["address"].startswith("0x")
    n = r["role"].count(". ") + 1
    print(r["address"], r["suggested_name"] or "(empty)", r["confidence"], "sentences~", n, "role chars", len(r["role"]))
for e in enum_roles:
    assert isinstance(e["value"], int)
