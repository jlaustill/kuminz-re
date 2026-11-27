"""Judge D1: build the verdict list from the investigator's final_output.json and the judge's decisions.
Every proposed function / global / enum member gets exactly one verdict. Writes verdicts.json next to this script."""
import json
import os

BASE = "/home/linux/.claude/jobs/374b0424/tmp/w15/r93/"
HERE = os.path.dirname(os.path.abspath(__file__))
inv = json.load(open(BASE + "scratch/D1/investigator/final_output.json"))

OLD_STEP = "mc68k_runSerialEepromWriteQueue"
NEW_STEP = "mc68k_runSerialEepromDriverStep"

# ---------------------------------------------------------------- functions
F = {}


def f(addr, own_role, reason, verdict="CONFIRMED", final_name=None, final_comment="", relation=None):
    F[addr] = dict(own_role=own_role, reason=reason, verdict=verdict, final_name=final_name,
                   final_comment=final_comment, relation=relation)


f("0x0000ac3c",
  "One duty cycle monitor sample per 100 ms while bit 3 of algorithm_enable_flags_18_cal is set and engine_state is not "
  "STOPPED: stamps the map start times, forms the load ratio (FSFNFL - NLFL) x 10000 / (full throttle fueling - NLFL) "
  "(FSMXTHFL inside DCMNLOES..DCMNHIES, else the ALPHA blend of the steady state / transient 4D fueling lookups at the "
  "cutoff speed), bins engine speed (8) and load (6) into region 1-48 (49 / 50 for a negative ratio) and adds 1 to that "
  "region's counter and total in the long term map (cap 3600000000) and in the active short term processing map.",
  "Re-derived from 0xac3c-0xaf6e: andi.w #8 on 0x803cb8, cmpi #1 engine_state, x 10000 shift-add + divs.l, two axis "
  "searches (0x807d20 x8, 0x807d34 x6), region = (6 - load) x 8 + speed, 49 / 50 for a negative ratio, addq.l on "
  "0x80546e / 0x80bada / 0x80bba8 + 4 x region. It is the only writer of the region, load factor and map counters; "
  "0xaf70 / 0xb130 only convert. Agrees with the describer. CM848 0x50638c has the same skeleton but 10 load bins, a "
  "13000 clamp, no short term maps: counterpart, so cm550_ and the parallel name. Name unique in both CSVs.")
f("0x0000e998",
  "Boost pressure sensor in-range high diagnostic (Cummins 433): with bit 4 of word 27 set, engine RUNNING, neither boost "
  "circuit fault (status word 1 bits 0x400 / 0x200 together with the same DGFUIDEN bits) active, engine speed at most "
  "LSRF + DGLSRSOF and JCPCLD at most DGLWTD, counts a dwell to DGBSDCTR, then debounces boost > DGSTBSTD up / down; above "
  "DGBSHTTD sets bit 0x2000 of status word 1 and its first occurrence bit, at 0 clears the status bit; a failed "
  "condition resets dwell 0 / debounce 1.",
  "Name confirmed: the only reader of the five 123D records and the only setter / clearer of mask 0x2000 of 0x806002 "
  "(RAM dump: DGFUCATB word 29 -> index 91 -> code 433; bits 25 / 26 -> 122 / 123). The CM848 record names "
  "(boost_pressure_sensor_high_reading_*) support the wording; the describer's ...InRangeHighError says the same. "
  "Counterpart of the last block of cm848_monitorBoostPressureSensorAndUnderboost (same tests, larger CM848 body). "
  "Comment amended: 0x806abe is word 1 of e2m DGFUIDEN (000F +570, 'bit mapped parameter used to disable / enable the "
  "processing of a fault'), read-only in the dumped ROM, not 'confirm bits' (the frozen row name fault_confirm_status_word_1 "
  "is the old pass's guess).",
  verdict="AMENDED",
  final_comment=(
      "Boost pressure in-range high check (e2m 123D DGBSDCTR / DGBSHTTD / DGLWTD / DGLSRSOF / DGSTBSTD; enable = bit 4 "
      "of algorithm_enable_flags_27_cal, DGBSIREN), once per 100 ms from cm550_runEvery20FramesTaskSetPhase1. It runs "
      "while engine_state is RUNNING, neither boost pressure circuit fault is active (bit 0x400 / 0x200 of system error "
      "status word 1 = Cummins codes 123 / 122, each counted only while the same bit of word 1 of the fault processing "
      "enable bitmap DGFUIDEN, 0x806abe, is set), engine speed ESCMES is at most LSRF + DGLSRSOF and percent load JCPCLD "
      "is at most DGLWTD; otherwise the dwell count is zeroed and the debounce count set to 1. After DGBSDCTR passes of "
      "dwell the debounce count goes up while boost pressure BSTPRS is above DGSTBSTD and down otherwise; above DGBSHTTD "
      "it sets bit 0x2000 of system error status word 1 and of the first occurrence word (fault code 433), and at 0 it "
      "clears the status bit once the first occurrence bit is clear. The counterpart of the last block of "
      "cm848_monitorBoostPressureSensorAndUnderboost."))
f("0x0001b754",
  "Executive 20-frame task set of frames 1 and 21 (call 6 of those frames): jsr 0xe998, 0x4115a, 0x41256 (the last two "
  "above the dumped ROM).",
  "Jump table 0x1b90e decoded: frames 1 / 21 bsr.w 0x1b754 as the sixth call (0x1b99e, 0x1bc5c). Two of three callees "
  "are not dumped, so the slot name is what the code proves; it equals the live name (7cf52470). CM848's slot mate "
  "cm848_periodicTaskGroup26_calibration8 shares no task: standalone.")
f("0x0001b788",
  "Executive 20-frame task set of frames 3 and 23 (call 6): jsr 0x491b4 (not dumped), 0xac3c (duty cycle sample), "
  "0x26cc8 and 0x26e2c (the percent load words).",
  "Slot decoded from the jump table (bsr.w at 0x1b9e6 / 0x1bc98); equals the live name. The frozen rows 0x1b78e / "
  "0x1b794 sit on its second / third jsr. Relation: CM848's executive (twin) runs cm848_periodicTaskGroup28_calibration10 "
  "in the same slot, starting with the counterparts of 0x26cc8 / 0x26e2c; counterpart is defensible (the describer said "
  "none) and the cm550_ prefix is the same either way.")
f("0x0001b7f2",
  "Executive 20-frame task set of frames 11 and 31 (call 6): jsr 0x46aac, 0x1d9b4 (idle shutdown), 0x40b30, 0x422b4 "
  "(three not dumped).",
  "Slot decoded (bsr.w at 0x1bafa / 0x1bd88); equals the live name. Nothing in it touches the VP44, so the old vp44_ "
  "prefix was wrong; CM848's slot mate hpcr_periodicTaskGroup36_calibration15 shares no task: standalone.")
f("0x0001d9b4",
  "Idle shutdown state machine: word 3 bit 1 set and word 28 bit 4 clear, then a six-way jump table (0x1da00) on ISST "
  "0x80d674: RESET reloads ISTM and clears ISWRRQ / ISOD / ISODFG / output 30; COUNT counts down to WARNING (or DELAY with "
  "ISAATPEN + ISODFG); WARNING raises ISWRRQ and after ISWRTMLM passes goes to SHUTDOWN (or OVERRIDE / RESET); DELAY "
  "600-pass countdown to OVERRIDE; OVERRIDE sets ISOD / ISODRQ; SHUTDOWN sets SHSS and output 30 once and returns to "
  "RESET when CRANKING; saves the entry state in 0x800752.",
  "Name confirmed: the only writer of ISST besides the initializer and the only idle shutdown code that sets SHSS; both "
  "roles agree. CM848: no access to Idle_Shutdown_Period 0x3fdd4c / Min / Max IMT (lis+displacement scan finds the "
  "neighbour 0x3fdd50 four times), engine_shutdown_command_flag stored only at 0x216f0 / 0x508d1c / 0x508e18, no "
  "idle shutdown name in its CSVs and only calibration leftovers in its e2m: the task's premise of a CM848 machine does "
  "not hold, so standalone. Comment amended: the flags are not writer-less - cm550_initializeIdleShutdown sets ISRSFG to 1 "
  "and RESET / the initializer clear ISODFG; no code sets them while running.",
  verdict="AMENDED",
  final_comment=(
      "Idle shutdown state machine (e2m 10CD; state ISST 0 RESET / 1 COUNT / 2 WARNING / 3 DELAY / 4 OVERRIDE / 5 "
      "SHUTDOWN), one pass per 100 ms from cm550_runEvery20FramesTaskSetPhase11 while ISAGEN (idle_shutdown_enable, bit 1 "
      "of algorithm_enable_flags_3_cal) is set and ISTAEN (integrated_idle_management_enable, bit 4 of word 28) is clear. "
      "RESET reloads the timer ISTM from ISTMLM, clears ISWRRQ / ISOD / ISODFG, switches output 30 off and waits for "
      "ISRSFG = 0; COUNT counts ISTM down, returns to RESET on ISRSFG = 1 and enters WARNING when ISTM is at or below "
      "ISWRTMLM (or DELAY, 600 passes before OVERRIDE, when ISAATPEN and ISODFG are set); WARNING keeps counting, sets "
      "ISWRRQ and after ISWRTMLM passes enters SHUTDOWN, unless ISODEN with ISODFG gives OVERRIDE or ISRSWNFG gives RESET; "
      "OVERRIDE reloads the timer, sets ISOD and ISODRQ and waits for ISODRSFG; SHUTDOWN sets the engine shutdown command "
      "SHSS and switches output 30 on once, and returns to RESET when the engine is CRANKING. No code in the dumped ROM "
      "sets ISRSFG / ISRSWNFG / ISODRSFG / ISODFG while running (cm550_initializeIdleShutdown sets ISRSFG to 1 at "
      "start-up; RESET and the initializer clear ISODFG). CM848 S90140.06 has no idle shutdown machine."))
f("0x000253b0",
  "Three warning-lamp flashes: ticks 1-5, 24-29 and 48-53 of a 72-tick cycle on lamp request bit 0x2, busy latch "
  "0x801a1c set in the first on phase and cleared with the count at tick 72; run while OCRSFG or the latch is set.",
  "Re-derived from 0x253b0-0x25446; both roles agree. Discriminator holds: of the three fixed-pattern flashers only this "
  "one drives bit 0x2 and is gated by OCRSFG (0x80dab0, e2m 1094 +12). No CM848 lamp code reads the CM848 reset flag.")
f("0x000254b6",
  "The 50 ms lamp control task: only the power-up sequence while 0x8019d2 is set; else fault code flash out, then the "
  "shutdown warning flashes, then the active fault lamps, each only when the previous returns idle; the three oil change "
  "monitor flash patterns on their conditions; saves switch bits 0x20 / 0x40 / 0x80 of 0x80bccf for edge detection.",
  "Both roles agree and the code confirms the priority order (tst.b d0 after 0x24d40 / 0x249ee) and conditions "
  "(0x801a22 window 100..399 with OCITWNFG, OCRSFG or 0x801a1c, OCRNSTEA + OCITWNFG + RUNNING). LAMP_CON is the e2m group "
  "(G record, group 0x30 LAMP_CONTROL) of the LC records. Single caller 0x1b70c.")
f("0x00026834",
  "QSPI interrupt handler of the serial EEPROM driver (movem, rte): clears SPIF in QSM_SPSR, runs the driver step "
  "0x266da, sets SPE in QSM_SPCR1.",
  "No caller: its address is stored in 0x808f20 at 0x26860 = VBR 0x808ddc (movec at 0x28650) + 4 x 0x51 (QIVR 0x50 at "
  "0x2866c, QSPI vector = QIVR | 1); the RAM dump holds 0x00026834 there. Counterpart of cm848_onQspiFinished (CM848's "
  "serves a shared QSPI job queue). Name confirmed; comment amended only for the renamed callee "
  "(" + NEW_STEP + ").",
  verdict="AMENDED")
f("0x00026852",
  "Empty function: a single rts, called once by bsr.s at 0x2685e at the start of 0x26854.",
  "Body is 4e75 between the rte of 0x26834 and the prologue of 0x26854; only reference is the bsr.s. The repository's "
  "empty-function convention (cm550_emptyStubFunction4 / 7; CM848 cm848_emptyStubFunction3 / 5 / 6 / 7 / 8) states only "
  "what the code shows; 10 is unused in the frozen and live CSVs (9 was the deleted 0x303c8). Kept rather than skipped "
  "(the describer would skip it): the name claims nothing beyond 'empty'.")
f("0x00026854",
  "Serial EEPROM driver start-up (called once at 0x28674): installs the QSPI vector, configures PQSPAR / DDRQS / PORTQS, "
  "SPCR0 0x8004, queue 2-15 (READ, address, 12 data words), sets ram_refresh_enable, state 0, base 0x803b0a, loads 0x148a "
  "bytes by polling (driver step + both watchdogs) until the loaded flag, then DTL 0x23, SPIFIE, SPE and the refresh "
  "length 0x64c.",
  "Re-derived from 0x26854-0x269f0: lengths (0x804f94 - 0x803b08) - 2 = 0x148a (RAM 0x803b0a-0x804f93) and "
  "(0x804156 - 0x803b08) - 2 = 0x64c (RAM 0x803b0a-0x804155); dump offset 0x4c8, length 0x64c, state 0, base 0x803b0a, "
  "loaded 1. It is the initializer, not the loop step. Counterpart of cm848_initEepromDriverAndLoadMirror (same variable "
  "order, QSPI job layer, checksum). Name confirmed; comment amended only for the renamed callee.",
  verdict="AMENDED")
f("0x00026e2c",
  "SPT0PCLD (0x80db62) = (FSFNFL - NLFL) x 25600 / (FST0MXFL - NLFL) when both fuelings are above NLFL (unsigned "
  "compares), else 0; divu.l with the low word stored, no clamp.",
  "Only writer of 0x80db62 (abs_refs); both roles agree. The investigator's discriminator 'only reader of FST0MXFL' is "
  "not true (cm550_updateElectronicSmartPowerTau reads it at 0x1ac3e, cm550_FUN_0001cc72 writes it), but the name rests on "
  "the SPT0PCLD output. CM848 0x50e000 (disassembled): "
  "signed compares, 64-bit divide via 0x571b0 and a clamp at 0xff00 (cmplwi r31,65280) - one more step, so counterpart "
  "with the prefixed parallel name. CM848's own name cm848_validateFuelDemandRelativeToTiming is wrong (lead).")
f("0x00024858",
  "Power-up lamp sequence over LCLPTB (ROM 0x611a8, 16 words): first pass takes priority 0x80 and switches on every listed "
  "output, then one output goes off per due tick (first at 40, then every 10); after the last entry one more step 30 ticks "
  "later releases the priorities, clears 0x8019d2 and the three switch previous-state bytes.",
  "Re-derived from 0x24858-0x249b4; both roles agree (same name). Old name cm550_ioControlMaskStateMachine fits nothing "
  "(no mask, no state word). Single caller 0x254ce.")
f("0x000249ee",
  "Flashes the warning lamp for ISWRRQ and the stop lamp for EPSQ (LCLPONTM / LCLPFFTM), and the warning lamp 120 times "
  "(10 on / 10 off) after ISODRQ = 1, then clears ISODRQ; returns 1 only when none is active.",
  "Re-derived from 0x249ee-0x24b4c; both roles agree. 'flash' is the e2m's word (LCLPONTM 'lamp is on when flashing') and "
  "the family's verb; the describer's 'blink' is a synonym. No VP44 / I/O control content: the old vp44_ name was wrong.")
f("0x00024d40",
  "Fault code flash out while the diagnostic switch (0x80bccf bit 0x80) is on and the engine STOPPED: selects the first / "
  "next / previous fault on switch edges or the next one in automatic mode after LCFUFHCU repetitions, flashes its code "
  "via 0x24b4e or lights both lamps when there is none, returns 0; when inactive it clears both lamp bits once and "
  "returns 1.",
  "Re-derived from 0x24d40-0x24f2e; both roles agree on the behaviour. The rename stands: the old name is a noun phrase "
  "(functions take verb phrases) and 'display' is wrong for a lamp blink code; 'flash out' is the e2m / Cummins term "
  "(LCFUFHMD automatic fault flash).")
f("0x00024f30",
  "Walks active_dtc_list: for each fault the first of control bits 0x1 / 0x2 / 0x4 (stop / warning / fluids lamp; "
  "skipped when bit 0x40 or the fault's bit at 0x803fb6 is set) sets its J1939 lamp flag (0x80dab2 / 4 / 6) and asks for "
  "flashing (bit 0x8) or steady; then drives request bits 0x1 / 0x2 / 0x4 flashing / on / off.",
  "Re-derived from 0x24f30-0x25314; both roles agree. No state word, so 'state machine' was wrong; the investigator's "
  "name and the describer's cm550_updateLampRequestsFromActiveFaults both fit, the proposal is kept.")
f("0x00025316",
  "Five groups of three flashes on lamp request bit 0x4 (on in ticks 1-5, 12-17, 24-29 of a 48-tick group; group count "
  "0x801a16 stops at 5); called 100..399 lamp task passes after the power-up sequence while OCITWNFG is set.",
  "Re-derived from 0x25316-0x253ae; both roles agree. Bit 0x4 is output 4, which the e2m calls the engine protection lamp "
  "(EPLPPZ, LCEGPNLP) and the fluids lamp (LCDGFDLP, FLLPONTM); the repository already has "
  "engine_protection_lamp_override_priority for it, so the proposal's wording is sourced. No fault is involved.")
f("0x00025448",
  "Waits 36000 ticks (30 min) and then gives four flashes on lamp request bit 0x4 (ticks 1-19 of an 80-tick cycle), then "
  "waits again; called while OCRNSTEA, OCITWNFG and engine_state RUNNING hold.",
  "Re-derived from 0x25448-0x254b4 (cmpi.w #0x8ca0, 0x14 / 0x50, count > 3); both roles agree; the old name named "
  "neither lamp nor reason.")
f("0x0001b70c",
  "Executive 10-frame task set of frames 5 / 15 / 25 / 35 (call 5): a single jsr 0x254b6, the lamp control task.",
  "Slot decoded (bsr.w at 0x1ba24 / 0x1bb86 / 0x1bcd0 / 0x1be02); equals the live name. The frozen name "
  "cm550_dzgTimingAndPressureSlowCycle10Coordinator was wrong in its subject. The alternative cm550_runLampControlTask "
  "would also be correct, but the slot scheme is the one round 93 applied to all 45 sets.")
f("0x0001db8a",
  "Start-up initialization of the idle shutdown block: ISOD 0, ISTM = ISTMLM, ISST 0, ISWRRQ / ISODRQ 0, ISRSFG 1, "
  "ISODFG 0, SHSS 0, output 30 off unless its override priority byte is set.",
  "Re-derived from 0x1db8a-0x1dbd6; single caller 0x287bc (start-up list of mc68k_applicationMain); both roles agree.")
f("0x0000af70",
  "Duty cycle monitor start-up: fills the two cm550_tableLookup2D records (5DFL01 / 5DFL00, x = DCMNLOES, y = 400), sets "
  "the period DCMNSHTI x 36000 ticks and x 60 minutes, sets the processing byte counts, and converts the stored short term "
  "totals and maps (minutes) into processing totals and counters (x 600; a full map becomes the period).",
  "Re-derived from 0xaf70-0xb12e; single caller 0x28822. Both roles agree. Only writer of 0x800006 / 0x80000a and of "
  "the two lookup records.")
f("0x0000b130",
  "Power-down store of the duty cycle monitor's short term maps: processing totals and counters (0.1 s) -> stored totals "
  "and map words in minutes ((x 60 + 18000) / 36000; a full map stores the period in minutes).",
  "Re-derived from 0xb130-0xb20e; single caller 0x289f4 between jsr 0x445fc and mc68k_runPowerDownSequence after the "
  "background loop with ori.w #0x700,sr. Writes no hour meter, so the old name was wrong. Not covered by the describer; "
  "the code is unambiguous.")
f("0x00026cc8",
  "FSPCLD (0x80db60) = (FSFNFL - NLFL) x 0x6400 / (FSMXTHFL - NLFL) clamped at 0x7f80; JCPCLD (0x80db5e) = the same fuel "
  "over the fueling available at the current speed (HSG droop line above HSRFBFDP with HSDPFG, clamped at 0x1700; else "
  "FSMXTHFL), clamped at 0x7f80 and forced to 0x6400 while final_fueling_state is FUELING_STATE_HIGH_SPEED_GOVERNOR (12).",
  "Re-derived from 0x26cc8-0x26e2a; only writer of 0x80db60 / 0x80db5e. Both roles agree. Counterpart of "
  "cm848_calculateEngineLoadPercentages (same constants, different full-load reference and branches), hence the "
  "prefixed parallel name; the old unprefixed calculateSpeedRatioComponent was wrong.")
f("0x00023a90",
  "Copies each lamp request bit of 0x80daac to its discrete output image bit while that output's override priority byte "
  "(0x80bd1a + n) is 0: 0x20 and 0x40 -> output 30, 0x04 -> 4, 0x01 -> 1, 0x08 -> 0, 0x02 -> 6, 0x10 -> 2.",
  "Re-derived from 0x23a90-0x23be4 (called by 0x24804 in the 10-frame set of phase 6). No protection condition is tested; "
  "the old unprefixed name was wrong and no CM848 row carries it. Not covered by the describer; the code is unambiguous.")
f("0x0002482e",
  "Arms the power-up lamp sequence: 0x8019d2 = 1, 0x8019d3 = 1, clears 0x8019d4 / 0x8019f0 and the flash out "
  "cycle-complete byte and repetition count.",
  "Re-derived (0x2482e-0x24856); callers 0x287c2 (start-up list) and 0x2898a (cm550_restartApplicationWithoutReset). Both "
  "roles agree.")
f("0x000249b6",
  "One step of a single 20-tick stop lamp flash for the digit flasher: bit 0x1 on at count 0, off at 10, at 20 the count "
  "restarts and it returns 1.",
  "Re-derived (0x249b6-0x249ec); three callers, all in 0x24b4e. The describer's cm550_flashStopLampOnce is equivalent; "
  "'run...Cycle' matches the one-step-per-call siblings (runPowerUpLampSequence).")
f("0x00024b4e",
  "Flashes one three-digit fault code: warning lamp on for 40 ticks, then stop-lamp flashes of the hundreds / tens / ones "
  "digits at phases 40 / 80 / 120 with 40-tick gaps, cycle complete at phase 160.",
  "Re-derived (0x24b4e-0x24c58); same name from both roles; argument = the fault record's code word pushed at 0x24ef4.")
f("0x00024c5a",
  "Returns the next active fault for the flash out: steps fault_list_navigation_index forward through active_dtc_list "
  "(1 on 125 or past the end), skipping faults with control bit 0x40; 125 when none.",
  "Re-derived (0x24c5a-0x24cd0); forward step (addq.b) versus the sibling's subq.b. It returns a fault index, not a code, "
  "so ...FaultToFlash is slightly more exact than the describer's ...FaultCodeToFlash.")
f("0x00024cd2",
  "Returns the previous active fault for the flash out: the same loop stepping backward (to the list count on 125 or 0).",
  "Re-derived (0x24cd2-0x24d3e); only caller is the idle decrement edge (0x24e4c). Both roles agree.")
f("0x000266da",
  "One step of the serial EEPROM driver after each QSPI queue pass: state 0 (no write) copies the 12 received words into "
  "the RAM mirror (while ram_refresh_enable), advances / wraps the offset (setting the loaded flag) and sets the next "
  "READ address, or moves to state 1 when writes are queued; state 1 sends WREN + WRITE of the next queued byte and goes "
  "to state 2; state 2 polls RDSR until the write is done, then the next write or back to reading at the saved offset.",
  "The investigator keeps the name and calls it 'incomplete rather than wrong'. The judge renames it: state 0 - the "
  "start-up mirror load and the continuous RAM refresh that make 0x803b0a-0x804155 EEPROM-backed - is this function's "
  "normal path, and 'runSerialEepromWriteQueue' names only states 1 / 2, so a reader looking for the mirror refresh "
  "would not find it. " + NEW_STEP + " states the role (one step per QSPI pass, called by the interrupt handler and by "
  "the start-up poll loop), keeps the mc68k_ prefix (QSM transmit / receive RAM) and is unused in both firmwares. The "
  "investigator's plate comment fits the new name unchanged. Standalone (CM848 splits the step over three functions).",
  verdict="AMENDED", final_name=NEW_STEP)

# ---------------------------------------------------------------- globals
G = {}


def g(addr, reason, verdict="CONFIRMED", final_name=None, final_type=None, final_comment=""):
    G[addr] = dict(reason=reason, verdict=verdict, final_name=final_name, final_type=final_type,
                   final_comment=final_comment)


g("0x0080d674", "e2m 10CD +2 ISST at this address; word accesses only (movea #imm at 0x1d9b8, clr.w 0x1db9a, move.w "
  "0x33d44); all six values proven by the state machine; CM848 has no idle shutdown state, so no shared name. Enum type "
  "IDLE_SHUTDOWN_STATE (size 2) confirmed below.")
g("0x0080d676", "e2m 10CD +4 ISTM (0.1 s per count); word accesses only (reload at 0x1da0c / 0x1db22 / 0x1db90, subq.w at "
  "0x1da4c / 0x1daa4, PID 71 reads 0xefa4 / 0xefac / 0xeff0); dump 36000.")
g("0x0080d67a", "e2m 10CD +8 ISWRRQ; set in WARNING, cleared in RESET / OVERRIDE / SHUTDOWN / init, read by the lamp "
  "function (0x24a0c) and PID 71 (0xeffc); word accesses.")
g("0x0080d67c", "e2m 10CD +A ISRSFG; tst.w in RESET, cmpi.w #1 in COUNT and DELAY, move.w #1 only in the initializer; "
  "word accesses.")
g("0x0080d682", "e2m 10CD +10 ISODFG ('override procedure was successful'); clr.w in RESET / init, cmpi.w #1 in COUNT "
  "(with ISAATPEN) and WARNING (with ISODEN); not a sensor fault.")
g("0x0080d684", "e2m 10CD +12 ISODRQ; move.w #1 in OVERRIDE, cmpi.w #1 / clr.w in the lamp function (0x24adc / 0x24b40), "
  "clr.w in init.")
g("0x0080d672", "e2m 10CD +0 ISOD; clr.w in RESET / init, move.w #1 in OVERRIDE, tst.w in PID 71 (0xefce); the other two "
  "hits are the parameter ID table (0x35a04). No frozen row.")
g("0x0080d67e", "e2m 10CD +C ISRSWNFG; only reference cmpi.w #1 at 0x1dad0 (WARNING -> RESET). No frozen row.")
g("0x0080d680", "e2m 10CD +E ISODRSFG; only reference cmpi.w #1 at 0x1db3a (OVERRIDE -> RESET). No frozen row.")
g("0x00803c02", "e2m 0008 +66 ISTMLM (0.1 s; 36000 in the dump); inside the EEPROM mirror (EEPROM 0xf8), so _cal is "
  "right; word reads at 0x1da0c / 0x1db22 / 0x1db90 / 0xefb2. CM848 has the record at 0x3fdd4c with no row and no reader.")
g("0x00808150", "e2m 10CC +8 ISWRTMLM (0.1 s; 300 in the dump); outside the mirror, so no _cal; only cmp.w at 0x1da8e / "
  "0x1dae6.")
g("0x00800752", "No e2m record; move.w of the entry state at 0x1db7e and cmpi.w #5 at 0x1db48 only. Name follows the "
  "repository's <thing>_previous pattern.")
g("0x00800754", "No e2m record; clr.w in COUNT, addq.w in WARNING, compared with ISWRTMLM at 0x1dae0; only references. "
  "Old vp44_sensor_failure_counter was wrong.")
g("0x00800756", "No e2m record; move.w #600 in COUNT, tst / subq.w in DELAY, tst.w before OVERRIDE; only references.")
g("0x0080bd38", "Slot 30 of the per-output override priority array 0x80bd1a + n (the power-up sequence and "
  "cm550_applyLampRequestsToOutputs index it that way; image bit = 0x80bcf9 bit 0x40); no e2m record at 12A7 +1E; byte "
  "accesses only. Output 30's driver is not identifiable in this build (ISDR text says bit 4; 000E +2B mask 0x40 records "
  "are Top2 solenoids; cm550_ioControlBasedFuelCalculator tests the bit five times and mc68k_initializeDiscreteOutputDrivers "
  "sets it five times - checked), so the neutral name is the right level of claim. The frozen engine_brake_lamp_driver_control "
  "is unsupported.")
g("0x00800000", "Long accesses only (move.l at 0xadd8 / 0xae18, tst.l at 0xae1e; the other abs hits are the RAM-base "
  "immediate of the RAM test / clear loops); signed (divs.l, bge). The low word 0x800002 (row rpm_control_timer_1, one "
  "move.w at 0xae4a) is absorbed - correct.")
g("0x00800004", "Word writes at 0xad2a / 0xad4a / 0xadb0 / 0xadb8, reads at 0xadc2 / 0xae04; no other code reference.")
g("0x00800006", "Long accesses only (cmp.l x7, move.l at 0xb002 / 0xb02a / 0xb06a); dump 18000000 = 500 h x 36000. The row "
  "0x800008 (no reference) is its low word and goes.")
g("0x0080000a", "Word write at 0xb016 (x 60), cmp.w at 0xb022 / 0xb062, read through a1 at 0xb13a; dump 30000.")
g("0x0080000c", "move.w after the 0x800010 lookup at 0xad5e, mulu.w at 0xad7e; no other reference.")
g("0x0080000e", "move.w after the 0x800026 lookup at 0xad72, read at 0xad9e; no other reference.")
g("0x00800010", "cm550_tableLookup2D (0x35088) reads (a2) / 2 / 6 / 8 / 0xa / 0xe / 0x10 / 0x14(a2) and writes back +0 / +8: "
  "the 22-byte layout is exactly the investigator's (x offset, x pointer, x input, y offset, y pointer, y input, z pointer, "
  "no-interpolation flag). Dump matches (00 02 | 0006086e | 1900 | 00 02 | 0006089a | 0190 | 000608a4 | 0000). The swallowed "
  "rows (0x800012-0x800022, DMA / rpm names) have no reference except the record's own +6 writes. New struct "
  "table_lookup_2d_arguments_t must be created (it is not table_interp_args_t, the 12-byte 1D argument of 0x34de0).")
g("0x00800026", "Same layout and proof as 0x800010; dump 00 02 | 0006094c | 1900 | 00 02 | 00060978 | 0190 | 00060982 | "
  "0000; swallowed rows 0x80002a-0x800036 have no code reference (0x800036's hit at 0xc7b6 is an immediate). Ends at "
  "0x80003b before 0x800042.")
g("0x0080bad4", "e2m 111F +8 DCMNLDFA, same mnemonic as CM848's duty_cycle_monitor_load_factor; word accesses (clr.w "
  "0xae26, move.w 0xae4a, reads 0xae96 and 0x3168a).")
g("0x0080bad6", "e2m 111F +A DCMNOPRN, same mnemonic as CM848's duty_cycle_monitor_operating_region; byte accesses "
  "through a5.")
g("0x0080546c", "e2m 1125 +0 DCMNLGMP is a T record with 4-byte entries: this word is the byte count (204 in the dump); "
  "only the parameter ID table references it. Name parallels the processing maps' _byte_count rows.")
g("0x0080546e", "addq.l #1,(0,a0,d0.w*4) with a0 = 0x80546e and region 1-50; dword[51] ends at 0x805539 before "
  "engine_overspeed_log 0x80553a. The 8 swallowed rows have no reference in the ROM (abs_refs).")
g("0x0080bada", "addq.l on 0x80bada + 4 x region, filled / read from 0x80bade by 0xaf70 / 0xb130; dword[51] ends at "
  "0x80bba5 before the map 2 byte count 0x80bba6; no row inside.")
g("0x0080bba8", "addq.l on 0x80bba8 + 4 x region, filled from 0x80bbac; dword[51] ends at 0x80bc73 before 0x80bc74; no row "
  "inside.")
g("0x00807c04", "e2m 123D +0 DGBSDCTR (0.1 s; 200), the mnemonic CM848 names boost_pressure_sensor_high_reading_dwell_limit "
  "(1631 +0); word compares through a5.")
g("0x00807c06", "e2m 123D +2 DGBSHTTD (0.1 s; 25), CM848's boost_pressure_sensor_high_reading_debounce_limit; word compares "
  "through a4.")
g("0x00807c08", "e2m 123D +4 DGLWTD (1/256 percent; 1792 = 7 percent); only cmp.w at 0xea3c against JCPCLD; CM848's "
  "boost_pressure_sensor_high_reading_maximum_engine_load. No frozen row.")
g("0x00807c0a", "e2m 123D +6 DGLSRSOF (0.125 rpm; 400); added to LSRF at 0xea20; CM848's "
  "boost_pressure_sensor_high_reading_idle_reference_speed_offset.")
g("0x00807c0c", "e2m 123D +8 DGSTBSTD (0.0159 inHg; 314); cmp.w against 0x80a320 at 0xea5a; CM848's "
  "boost_pressure_sensor_high_reading_minimum_boost_pressure.")
g("0x00800178", "addq.w / clr.w through a3 in 0xe998 and clr.w in the unreferenced reset entry 0xeadc; no other reference; "
  "same role as CM848's boost_pressure_sensor_high_reading_dwell_count; nothing to do with acceleration noise control.")
g("0x0080017a", "addq / subq / move.w #1 through a2 in 0xe998 and 0xeadc; dump 1; same role as CM848's "
  "boost_pressure_sensor_high_reading_debounce_count.")
g("0x0080daae", "e2m 1094 +10 OCITWNFG, the same mnemonic as CM848's oil_change_monitor_change_due_flag (1094 +2); only "
  "the lamp task reads it (a3 at 0x254c0); no writer in the dumped ROM.")
g("0x0080dab0", "e2m 1094 +12 OCRSFG, CM848's oil_change_monitor_reset_flag (1094 +4); only tst.w at 0x2551a. No frozen "
  "row.")
g("0x0080dab2", "e2m 1094 +14 LCDGSTLP, CM848's stop_fault_lamp_flag (1094 +6); clr.w 0x24f5e, move.w #1 0x25010.")
g("0x0080dab4", "e2m 1094 +16 LCDGWNLP, CM848's warning_fault_lamp_flag (1094 +8); clr.w 0x24f64, move.w #1 0x250e6; 1 in "
  "the dump.")
g("0x0080dab6", "e2m 1094 +18 LCDGFDLP, CM848's maintenance_fault_lamp_flag (1094 +A, same mnemonic; CM848's text says "
  "maintenance lamp); clr.w 0x24f6a, move.w #1 0x251b8. Sharing the cross-firmware record name is preferred over 'fluids'.")
g("0x0080d28e", "e2m 10B1 +14 EPSQ 'EPS shutdown approaching', CM848's engine_protection_shutdown_approaching_flag; set at "
  "0x19134 / 0x191e4 / 0x19242 and cleared at 0x19018 / 0x192ae / 0x186a4 by the engine protection code, read by the lamp "
  "function at 0x24a74; 'derate' was wrong.")
g("0x00803c42", "e2m 0008 +A6 OCRNSTEA (0 in the dump); inside the mirror (EEPROM 0x138) so _cal; only tst.w at 0x25530. "
  "CM848 keeps the record (0x3fdd62) without a row, so no name to align with.")
g("0x008019d2", "move.b #1 in cm550_startPowerUpLampSequence, tst.b in the lamp task, clr.b at the sequence end; byte only.")
g("0x00801a22", "a2 in the lamp task: addq.w while <= 400 (saturates at 401 = the dump), window 100..399; word.")
g("0x00801a1a", "a2 in 0x253b0: addq.w each call, clr.w at tick 72; word; unrelated to faults.")
g("0x00801a1c", "a0 in 0x253b0: move.b #1 / clr.b; tst.b in the lamp task at 0x25522; byte. No frozen row.")
g("0x00801a86", "EEPROM read offset (TR3 of the READ queue): a4 in 0x266da (addq.w #2, clr.w, move.w to 0xfffd26), "
  "move.w at 0x268f6; dump 0x4c8. Same role and name as CM848's eeprom_mirror_load_offset; no CAN involved.")
g("0x00801a88", "Load length: move.w 0x148a then 0x64c through a2 in 0x26854, cmp.w at 0x2677c; dump 0x64c; CM848's "
  "eeprom_mirror_load_length.")
g("0x00801a8a", "Long accesses only (cmp.l #2 / #1, tst.l, move.l #1 / #2, clr.l); values 0 / 1 / 2 proven (enum below). "
  "The can_buffer_setup_t instance (20 bytes, 0x801a8a-0x801a9d) is wrong: it spans this state, the mirror base pointer, "
  "the loaded flag and the start of a cm550_tableLookup2D record at 0x801a94 (cm550_FUN_000269f2 fills and passes it); "
  "removing the instance and its member rows is right.")
g("0x00801a8e", "move.l #0x803b0a at 0x26940 and add.l at 0x2676e; dump 0x00803b0a; CM848's eeprom_mirror_base_pointer.")
g("0x00801a92", "move.b #1 at 0x26786 (offset wrap) and tst.b at 0x269b2 (end of the start-up poll); byte; dump 1; CM848's "
  "eeprom_mirror_loaded_flag.")
g("0x0080db62", "e2m 10BF +4 SPT0PCLD, CM848's engine_load_low_horsepower_curve_percent (same record); only writer "
  "0x26e2c (a3).")
g("0x0080d36a", "Name and type confirmed: e2m 105A +2 FST0MXFL, CM848's throttle_100_fueling_low_horsepower_curve; word "
  "accesses (unsigned compares in 0x26e2c). Comment amended: the proposal says its writer is not in the dumped ROM, but "
  "cm550_FUN_0001cc72 writes it (a5 = 0x80d36a at 0x1cc88: move.w d0,(a5) after a cm550_tableLookup2D call at 0x1cd64, "
  "add.w d2,(a5) at 0x1cd7c, floor move.w (a2),(a5) at 0x1cd94), and cm550_updateElectronicSmartPowerTau reads it at "
  "0x1ac3e.",
  verdict="AMENDED", final_comment=(
      "e2m 105A +2 FST0MXFL 'fueling provided if engine were using low HP curve' (0.0679 mm3 per count): the same record "
      "as CM848's throttle_100_fueling_low_horsepower_curve (0x40a899). Written by cm550_FUN_0001cc72, which also writes "
      "throttle_100_fueling (a cm550_tableLookup2D result stored at 0x1cd64, the fueling offset added at 0x1cd7c, raised to "
      "a floor at 0x1cd94); read by cm550_updateElectronicSmartPowerTau (0x1ac3e) and, as the full load reference of the "
      "denominator, by cm550_calculateEngineLoadLowHorsepowerCurvePercent."))
g("0x0080db1c", "e2m 109C +0 NLFL 'fuel required to overcome friction', the record CM848 names no_load_fuel_quantity; word "
  "accesses throughout.")
g("0x0080db60", "e2m 10BF +2 FSPCLD, CM848's engine_load_percent; writers only 0x26d20 / 0x26d2a / 0x26d32 (abs_refs).")
g("0x0080d368", "e2m 105A +0 FSMXTHFL, CM848's throttle_100_fueling; word accesses.")

# ---------------------------------------------------------------- enum members
E = {}


def e(key, reason, verdict="CONFIRMED", final_comment=""):
    E[key] = dict(reason=reason, verdict=verdict, final_comment=final_comment)


e("IDLE_SHUTDOWN_STATE:0",
  "Case 0 (jump table 0x1da00 entry 0x000c -> 0x1da0c) and the initializer store 0; PGN 65252 builder 0x33d66 sends 0x00. "
  "ISRSFG's e2m text names the RESET <-> COUNT pair; CHR_B2 labels value 0 RESET. Comment amended: RESET clears only the "
  "warning lamp request ISWRRQ (clr.w (a1)), not ISODRQ, and switches output 30 off only when its override priority byte "
  "is 0.",
  verdict="AMENDED", final_comment=(
      "Not counting: the timer is held at the idle shutdown period, the warning lamp request and the overridden / override "
      "successful flags are cleared and output 30 is switched off (unless a client overrides it); leaves to COUNT when "
      "idle_shutdown_reset_flag is 0. PGN 65252 byte 1 = 0x00. (new enum, size 2, type of idle_shutdown_state)"))
e("IDLE_SHUTDOWN_STATE:1",
  "Case 1 at 0x1da48 (subq.w on ISTM; stores 0 / 3 / 2); move.w #1 at 0x1da40. PGN 65252 byte 1 = 0x40 = bits 7-8 = 01 "
  "(SPN 590 timer state active).")
e("IDLE_SHUTDOWN_STATE:2",
  "Case 2 at 0x1daa0 (ISWRRQ = 1, pass count; stores 4 / 0 / 5); move.w #2 at 0x1da98. PGN 65252 byte 1 = 0x44 (SPN 590 "
  "active + SPN 594 driver alert mode active); ISWRRQ / ISRSWNFG / ISWRTMLM texts name the warning.")
e("IDLE_SHUTDOWN_STATE:3",
  "Case 3 at 0x1daf8: a 600-pass countdown of 0x800756 ending in OVERRIDE, entered only from COUNT (move.w #3 at 0x1da84) "
  "with ISAATPEN and ISODFG; PGN 65252 leaves byte 1 unchanged. 'DELAY' says only what the code shows (a timed delay) and "
  "matches the CHR_B2 label.")
e("IDLE_SHUTDOWN_STATE:4",
  "Case 4 at 0x1db22 (ISOD = 1, ISODRQ = 1, timer reload); stores 4 at 0x1dac8 / 0x1db1c. PGN 65252 byte 1 = 0x10 (SPN 592 "
  "timer override active).")
e("IDLE_SHUTDOWN_STATE:5",
  "Case 5 at 0x1db48 (SHSS = 1 and output 30 on once, previous state != 5; back to 0 on CRANKING); store at 0x1daf0. PGN "
  "65252 byte 1 = 0x01 (SPN 593 idle shutdown has shut down the engine).")
e("EEPROM_BYTE_WRITE_STATE:0",
  "Every store / compare of 0x801a8a checked: clr.l at 0x2673e / 0x2693a, tst.l at 0x26756 selects the read-and-store path. "
  "IDLE = no byte write in progress (the read stream runs).")
e("EEPROM_BYTE_WRITE_STATE:1",
  "move.l #1 at 0x2673a / 0x267a4 (writes queued), cmp.l #1 at 0x267b6 selects the WREN + WRITE path.")
e("EEPROM_BYTE_WRITE_STATE:2",
  "move.l #2 at 0x2680a after the write is sent, cmp.l #2 at 0x266ea selects the RDSR polling path; no other value is "
  "stored, so the enum is complete.")

# ---------------------------------------------------------------- assemble
out = []
fn_names = {}
for fn in inv["functions"]:
    a = fn["address"]
    d = F[a]
    name = d["final_name"] or fn["proposed_name"]
    comment = d["final_comment"]
    if a in ("0x00026834", "0x00026854"):
        comment = fn["plate_comment"].replace(OLD_STEP, NEW_STEP)
        assert comment != fn["plate_comment"]
    v = dict(kind="function", firmware="CM550", address=a, verdict=d["verdict"], final_name=name,
             final_relation=d["relation"] or fn["relation"], own_role=d["own_role"], reason=d["reason"])
    if comment:
        v["final_comment"] = comment
    out.append(v)
    fn_names[a] = name
for gl in inv["globals"]:
    a = gl["address"]
    d = G[a]
    v = dict(kind="global", firmware="CM550", address=a, verdict=d["verdict"],
             final_name=d["final_name"] or gl["proposed_name"], final_type=d["final_type"] or gl["proposed_type"],
             reason=d["reason"])
    if d["final_comment"]:
        v["final_comment"] = d["final_comment"]
    out.append(v)
for em in inv["enum_members"]:
    key = "%s:%d" % (em["enum_name"], em["value"])
    d = E[key]
    v = dict(kind="enum_member", firmware="CM550", address=key, verdict=d["verdict"], final_name=em["proposed_member"],
             reason=d["reason"])
    if d["final_comment"]:
        v["final_comment"] = d["final_comment"]
    out.append(v)

assert len(F) == len(inv["functions"]) and len(G) == len(inv["globals"]) and len(E) == len(inv["enum_members"])
# a plate comment that still names the old step function would go stale after the rename
for fn in inv["functions"]:
    for v in out:
        if v["address"] == fn["address"] and v["kind"] == "function":
            text = v.get("final_comment") or fn["plate_comment"]
            if OLD_STEP in text:
                print("STALE OLD NAME in", fn["address"])
names = [v["final_name"] for v in out if v["kind"] == "function"]
assert len(names) == len(set(names))
json.dump(out, open(os.path.join(HERE, "verdicts.json"), "w"), indent=1)
print(len(out), "verdicts;", sum(1 for v in out if v["verdict"] == "AMENDED"), "amended;",
      sum(1 for v in out if v["verdict"] == "REFUTED"), "refuted")
