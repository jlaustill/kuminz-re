"""Skeptic W1: build the verdict list (written to verdicts_W1.json next to this script)."""
import json
import os

V = []


def add(element, verdict, reason, amendment=None):
    d = {"element": element, "verdict": verdict, "reason": reason}
    if amendment:
        d["amendment"] = amendment
    V.append(d)


C, A = "CONFIRMED", "AMENDED"

# ---------------------------------------------------------------- length word
add("word -1", A,
    "Name, type and value hold: v64t6_s has one record at 106B +0 (AENBLFLG, type B, size 72, 'LENGTH OF ALGORITHM_ENABLE_FLAGS'); "
    "parameter_id_table entry 154 (0x356f4 / 0x356f8) = 0x01000188 -> mirror 0x803c92; EEPROM 0x188 and RAM 0x803c92 both read 0x0046 "
    "(70 = 35 flag words x 2; 72 bytes = this word + words 0-34, the highest e2m offset is 0x44 = word 33). A scan of the ROM for every "
    "32-bit value 0x803c92-0x803ca1 at any alignment finds no reference to 0x803c92 / 0x803c93, so no reader and no store. CM848's EEPROM "
    "0x118 also reads 0x0046 and its B record is 90 bytes. One address in the comment is wrong: the region list is 8-byte "
    "[address][length] pairs from 0x8082 (0x80e2 = 0x00060000 / 0x9e, 0x80ea = 0x01000188 / 0x48), so the entry is at 0x80ea, not 0x80e8.",
    "name algorithm_enable_flags_table_length_cal, type word unchanged; row comment (and code_tests): 'the ROM region list entry at 0x80ea "
    "holds (0x01000188 / 0x48)' instead of 0x80e8")

# ---------------------------------------------------------------- word 0
add("word 0", C,
    "0x803c94 = 106B +2 (EEPROM 0x18a). My own census gives 23 references: 8 move.w (0x803c94).l,d0 + andi with one bit (0xc3ba 0x4000; "
    "0xc5a0 0x400; 0xc5b4 0x800; 0xc5cc 0x1000; 0xc5e4 0x2000; 0xc5fc 0x8000; 0x13630 0x100; 0x1ca86 andi.l 0x40) and 15 movea.l "
    "#0x803c94,a0 + move.w (0,a0,dn.w*2). I disassembled all 15: the bit numbers start at 112 / 113 / 114 (+4 per channel; +2 / +3 in "
    "cm550_diagnosticProtectionEvaluator and cm550_protectionState1DiagnosticValidator), 0x1a0 (+1 per channel) and 0xd0 + switch, so they reach words 7+, 13+ and 26+ only. No store, no byte or "
    "btst access. 0x5c10 in both dumps. CM848's word 0 is a plain word for the same reason and has the extra S record 0x2 "
    "(AFC_Low_Boost_Derate_Enable, which its code reads); CM550's e2m has 12 N records, bits 4-15. A plain word with the bits in the comment is right.")
add("word 0 bit 0", C, "No record for mask 0x1 at 106B +2 in v64t6_s, no test of that mask on 0x803c94, clear in 0x5c10 (comment only: word 0 stays a word).")
add("word 0 bit 1", C, "No CM550 record for 0x2 and no test of it; CM848's e2m has AFC_Low_Boost_Derate_Enable S 0x2 and its code tests '& 2'; clear in 0x5c10 (comment only).")
for b in (2, 3):
    add("word 0 bit %d" % b, C, "No record for mask 0x%x at 106B +2 in v64t6_s, no test of that mask on 0x803c94, clear in 0x5c10 (comment only: word 0 stays a word)." % (1 << b))
add("word 0 bit 4", C, "JCSBR1AO N 'BIT 4 OF 0-15. IF TRUE LOAD SHADOW RAM DURING INITIALIZATI'; the e2m files with an S record give mask 0x10 (37 files). No test of 0x10; set in 0x5c10.")
add("word 0 bit 5", C, "PSAGEN N 'BIT 5 OF 0-15. CUSTOMER TRIM FLAG TO ENABLE/DISABLE PR' (longer text: PROG. SHIFT FEATU; S mask 0x20 elsewhere). No test of 0x20; clear.")
add("word 0 bit 6", C, "EBODEN N 'BIT 6 OF 0-15 ... ENABLES FSO VAL(VE TO CLOSE ON'; S 0x40 elsewhere). 0x1ca86 move.w, 0x1ca8c andi.l #0x40: reached only with 0x80a9c8 (engine_retarder_active_flag) non-zero, and a set bit takes the branch that clears bit 0x20 of fuel_system_output_driver_control. Clear in the dumps.")
add("word 0 bit 7", C, "VSBKEN N 'BIT 7 WORD 0. ENABLES VSS ANTI-TAMPERING DETECTION' (S 0x80 elsewhere). No test of 0x80 on word 0; clear. The name spells the sensor out.")
add("word 0 bit 8", C, "DCAGEN N 'BIT 8 OF 0-15. EEPROM INDICATOR SET BY TOOLS TO ENABLE DATA COLLE'. andi.w #0x100 at 0x13636 after the load at 0x13630: the whole data collector sampler body is inside that test. Clear.")
add("word 0 bit 9", C, "DPAGEN N 'BIT 9 OF 0-15. ENABLE/DISABLE THE DOUBLE PULSING FEATURE' (S 0x200 elsewhere). No test of 0x200; clear.")
add("word 0 bit 10", C, "APLSEN N 'BIT A WORD 0. ENABLES ALPHA LSG SUB-ALGO'. 0xc5a0 andi.w #0x400 -> bsr 0xc4b2 (tests final_fueling_state == LOW_SPEED_GOVERNOR and the LSG exit timer), result to 0x80a904. Set in 0x5c10.")
add("word 0 bit 11", C, "APAFEN N 'BIT B WORD 0. ENABLES ALPHA AFC SUBALGORITHM'. 0xc5b4 andi.w #0x800 -> bsr 0xc504 (the AFC latch / exit timer), result to 0x80a8fe. Set.")
add("word 0 bit 12", C, "APFLRTEN N 'BIT C WORD 0. ENABLES ALPHA FUEL RATE SUB-ALGO'. 0xc5cc andi.w #0x1000 -> bsr 0xc404 (the fuel rate filter against two thresholds), result to 0x80a900. Set.")
add("word 0 bit 13", C, "APONGVEN N 'BIT D WORD 0. ENABLES ALPHA ON GOVERNOR SUB-ALGO'. 0xc5e4 andi.w #0x2000 -> bsr 0xc496 (road speed governor state or cruise active), result to 0x80a902. Clear.")
add("word 0 bit 14", C, "APEGPNEN N 'BIT E WORD 0. ENABLES LOGIC TO USE ENGINE PROTECTIO(N ALPHA)'. 0xc3ba move.w, 0xc3c0 andi.w #0x4000: with 0x80d286 (engine protection fuel derate active) = 1 calculateAlpha stores alpha_state 3 and the alpha from 0x807aac. Set.")
add("word 0 bit 15", C, "AATBPEN N 'BIT F WORD 0. ENABLE BIT FOR THE ALPHA AMBIENT AIR PRES' (CM848 label Alpha_Turbo_Protection_Enable, S 0x8000). 0xc5fc andi.w #0x8000 -> bsr 0xc556 (ambient air pressure against two thresholds), result to 0x80a90a. Clear.")

# ---------------------------------------------------------------- word 1
add("word 1", C,
    "0x803c96 = 106B +4 (EEPROM 0x18c). 11 references, each move.w (0x803c96).l,d0 followed by andi with one bit (0x1, 0x2, 0x4 twice, 0x8, "
    "0x10, 0x20, 0x1000, 0x2000, 0x4000, 0x8000); no store, no byte access. 0x1000 in both dumps. The 10 CM550 records are the same 10 "
    "mnemonics as CM848's word 1; the CM550 text bits (0-5) and CM848's S masks agree with the masks the CM550 code tests, and the CM848 twins "
    "do the same per bit (cm848_selectLowSpeedGovernorGearGainSet: 0x4000 -> state 2 middle gear set, 0x2000 -> state 3 high gear set; "
    "0x8000 -> state 4). CM848's algorithm_enable_flags_1_t has exactly these 16 field names at these bits, 6-11 reserved in both, so the shared type is right.")
add("word 1 bit 0", C, "APUOAPEN N 'BIT 0 WORD 1' (CM848 S 0x1). 0xc3a2 move.w, andi.w #1: calculateAlpha stores alpha_state 1 and the alpha from 0x803d4c. Clear.")
add("word 1 bit 1", C, "FSUOFLEN N 'BIT 1 WORD 1' (CM848 S 0x2). 0x1c204 andi.w #2: fuel limit = 0x803f2c with final state 23 (0x17 FUEL_OVERRIDE). Clear.")
add("word 1 bit 2", C, "CTTHSWOD N 'DISABLES AUTOZERO & IDLE VALIDATION, BIT 2 OF 0-15' (CM848 S 0x4). andi.l #4 at 0x10602 / 0x1084e: the throttle validation fault checks / the idle validation diagnostic run only while it is clear. CM848's twin tests the same bit for its test cell autozero. Clear.")
add("word 1 bit 3", C, "TSUOTAEN N 'BIT 3 WORD 1' (CM848 S 0x8, no CM848 reader). 0x30bc2 andi.w #8: selected timing = 0x804024, timing state 7. Clear.")
add("word 1 bit 4", C, "FSTQUOEN N 'BIT 4 WORD 1' (CM848 S 0x10). 0x1c16e andi.w #0x10: fuel_limit_shutdown_minimum = 0x803f2a with source 13 (0xd TORQUE_DERATE_OVERRIDE). Clear.")
add("word 1 bit 5", C, "ATAGEN N 'BIT 5 OF 0-15 ... ENABLE THE ALTITUDE' (CM848 S 0x20). 0xc686 andi.w #0x20: clear (or engine not running) gives the peak fueling value, set gives the 2D lookup on ambient air pressure. Clear.")
for b in range(6, 12):
    add("word 1 bit %d" % b, C, "No record for mask 0x%x at 106B +4 in v64t6_s or in CM848's e2m, no test of that mask, clear in 0x1000; reserved in CM848's type too." % (1 << b))
add("word 1 bit 12", C, "LSAGGNEN N (no bit in the text); CM848 S 0x1000 (the same mask in every e2m file with an S record). 0x26188 andi.w #0x1000: with the aggressive logic allowed and gain set 0 it selects gain set 1. Set in the dumps.")
add("word 1 bit 13", C, "LSHGGNEN N (no bit); CM848 S 0x2000. 0x26408 andi.l #0x2000: when set (and below the mid/high breakpoint) gain set 3 with the pointer to the 'when in high gears' gains; CM848's twin has the same structure. Clear.")
add("word 1 bit 14", C, "LSMGGNEN N (no bit); CM848 S 0x4000. 0x263e0 andi.l #0x4000: required for any gear gain set; gives gain set 2 with the pointer to the 'used when in middle gears' gains. Clear.")
add("word 1 bit 15", C, "LSJCGNEN N 'ENABLES/DISABLES THE LSG JCOMM PID GAINS'; CM848 S 0x8000. 0x265ee andi.l #0x8000: with the datalink speed control mode non-zero it sets gain set 4 and its pointer. Clear. The field name is CM848's.")

# ---------------------------------------------------------------- word 2
add("word 2", A,
    "Row name, type and row comment hold: 0x803c98 = 106B +6 (EEPROM 0x18e); 16 references, each a word read + andi with one bit (0x1 x3, "
    "0x10 x3, 0x20 x2, 0x80, 0x100, 0x800, 0x1000 x3, 0x2000, 0x4000); no store; 0x1870 in both dumps. CM550's own e2m has ISRPEN as an S "
    "record with mask 0x8, CM848's e2m has no record at 0x8 and no reader, so the type cannot be shared: cm550_algorithm_enable_flags_2_t "
    "with CM848's other 15 field names is right. The differences_from_cm848 text is wrong on one fact and garbled: CM848 does not read bit 7 "
    "(its .cpp has no j1922_monitor_enable or j1922_monitor_clear_enable reference and its struct says 'no reader in this build'). Two field "
    "comments (bits 7 and 11) name the wrong instruction size.",
    "name algorithm_enable_flags_2_cal and type cm550_algorithm_enable_flags_2_t unchanged; differences_from_cm848: 'Only bit 3 differs "
    "(CM550 ISRPEN S mask 0x8; CM848 reserved_bit_3). CM848 reads bit 6 (cm848_updateEngineRetarderAllowedState) and has no reader for "
    "bits 7 and 8; CM550 reads bits 7 (0x1fdc6) and 8 (0x1fd6c) and has no reader for bits 3, 6 and 15.'")
add("word 2 bit 0", C, "EPSOEN N 'BIT 0 OF 0-15. ENABLE SHUTDOWN ALGORITHM' (CM848 S 0x1). andi.l #1 at 0x18ade / 0x18cba / 0x18fe6 (cm550_diagnosticProtectionEvaluator / cm550_protectionState1DiagnosticValidator / processDiagnosticLimitStatus), each time ahead of the per-channel shutdown enable bits. Clear in 0x1870.")
add("word 2 bit 1", C, "Reserved is right: JC22CCSW's text says 'BIT 1 OF BITS 0:15' but every e2m file with an S record for it gives 0x100 (the same text beside the mask), the CM550 code tests that flag at 0x100, and nothing tests 0x2. Clear.")
add("word 2 bit 2", C, "No record for 0x4 at 106B +6, no test of 0x4, clear.")
add("word 2 bit 3", C, "ISRPEN is an S record in CM550's own e2m: mask 08, 'BIT 3 WORD2. 1 - PTO WILL NOT OVERRIDE SHUTDOWN, 0 - P(TO WILL OVERRID)'; the labelled e2m files call it Idle_Shutdown_PTO_Enable, 0x8. No test of 0x8 on word 2; clear. CM848's e2m has no record there. The name states the set meaning.")
add("word 2 bit 4", C, "EPEN N 'BIT 4 OF 0-15. ENGINE PROTECTION FEATURES ENABLE' (CM848 S 0x10). 0x18628 andi.w #0x10: clear = rated speed limit, peak fuel limit, no derate; set = the five protection phases. Also 0x18ace and 0x1cade. Set.")
add("word 2 bit 5", C, "EPRYEN N 'BIT 5 OF 0-15. ENABLE RESTART ALGORITHM' (CM848 S 0x20). andi.l #0x20 at 0x18aee / 0x18cca, tested with bits 4 and 0 before the per-channel shutdown / restart enable bits. Set.")
add("word 2 bit 6", C, "EBCHDBEN N 'BIT 6 OF 0-15 ... USED TO ENABLE EN(GINE BRAKE DEAC' (CM848 S 0x40, label EB_Clutch_Enable). No test of 0x40 on word 2 in the dumped ROM; set in 0x1870. CM848's field name.")
add("word 2 bit 7", A, "Position and name hold: JC22MRSW 'J1922 MONITOR ENABLE' has S mask 0x80 in CM848's e2m and in every other file that gives one; the code at 0x1fdc6 counts control mode 1 / 2 / 3 sessions with key-on hour stamps only while 0x80 is set. Clear in the dumps. The comment's instruction is wrong: the bytes at 0x1fdcc are 0240 0080 = andi.w #0x80,d0.",
    "bit 7 j1922_monitor_enable unchanged; comment: 'andi.w 0x80 at 0x1fdc6' (not andi.l)")
add("word 2 bit 8", C, "JC22CCSW 'J1922 MONITOR CLEAR ENABLE' with S mask 0x100 in CM848's e2m and 30+ files. 0x1fd6c move.w, andi.l #0x100: when set and the last-control hour stamp plus the J1922 clear occurrence time has passed, it zeroes the eight session counter / hour stamp variables. Clear.")
add("word 2 bit 9", C, "No record for 0x200, no test, clear.")
add("word 2 bit 10", C, "No record for 0x400, no test, clear.")
add("word 2 bit 11", A, "Position and name hold: JC39MREA 'J1939 MONITOR ENABLE' has S mask 0x800 in CM848's e2m; 0x22080 gates the function that records the datalink speed control and retarder session history. Set in 0x1870. The comment's instruction is wrong: the bytes at 0x22086 are 0240 0800 = andi.w #0x800,d0.",
    "bit 11 j1939_monitor_enable unchanged; comment: 'andi.w 0x800 at 0x22080' (not andi.l)")
add("word 2 bit 12", C, "JCRDTXEA 'ENABLE FOR SPEED CONTROL / ENGINE BRAKING INTERACTION', CM848 S 0x1000. Tests of 0x1000 at 0x21432 (ends retarder mode 2 when the selected fueling reaches the limit), 0x2f850 (retarder TSC1 handler) and 0x33900 (retarder status byte = 0x40 while set, else 0). Set.")
add("word 2 bit 13", C, "PTTHOVEN N 'BIT 13 OF 0-15' (CM848 S 0x2000). 0x2dd34 andi.l #0x2000: with PTO active and the throttle fueling at or above the PTO fueling, the throttle fueling wins and the override flag is set. Clear.")
add("word 2 bit 14", C, "TSUCICEN N 'BIT 14 WORD 2 ... USER TIMING' (CM848 S 0x4000). 0x1c770 andi.w #0x4000: adds 0x803f3c to the 4D timing and sets the increment flag. Clear.")
add("word 2 bit 15", C, "ZVPTLMEN N 'BIT 15 WORD 2 - ENABLE ENGINE SPEED TO BE LIMITED' (CM848 S 0x8000, Zero_Vss_PTO_Limit_Enable). No test of 0x8000 on word 2; clear. CM848's field name.")

# ---------------------------------------------------------------- word 3
add("word 3", C,
    "0x803c9a = 106B +8 (EEPROM 0x190). 13 references, each a word read + andi with one bit (0x2 x3, 0x4 x2, 0x8, 0x10, 0x200 x2, 0x800, "
    "0x1000, 0x2000, 0x4000); no store; 0x86e8 in both dumps (bits 3 5 6 7 9 10 15). Fifteen CM550 records cover bits 1-15; CM848's own e2m "
    "has no record for 0x2 0x4 0x20 0x100 0x200 0x800 and its code reads none of them except 0x100, so the type must be CM550's own. The "
    "field names of bits 3 4 6 7 10 15 are CM848's verbatim.")
add("word 3 bit 0", C, "No record for 0x1 at 106B +8, no test of 0x1, clear.")
add("word 3 bit 1", C, "ISAGEN is an S record in CM550's own e2m, mask 02, 'WORD 3, BIT 1 OF 0-15. 1 - IDLE SHUTDOWN ENABLED'. Tests of 0x2 at 0x1d9ca (the state machine whose state word 0x80d674 is e2m 10CD ISST), 0xefbe (PID 71 status bit 0x08 = function enabled) and 0x33d80 (PGN 65252 payload byte 0x8035f7 = 0x7f set / 0x3f clear). Clear.")
add("word 3 bit 2", C, "ISODEN S record, mask 04, 'WORD 3, BIT 2 OF 0-15. 1 - ISOD IS ABLE TO BE SET'; CM550's e2m 10CD +0 ISOD (0x80d672) = '1 - IDLE SHUTDOWN IS OVERRIDDEN UNTIL VEHICLE MOVES'. andi.l #4 at 0x1dab0 (warning state -> override state with ISODFG) and 0xefd6 (PID 71 bit 0x04 with ISOD). Clear.")
add("word 3 bit 3", C, "LSISAJEN N 'BIT 3 OF 0-15. ENABLE ALLOWS OPERATOR TO ADJUST SPEED' (CM848 S 0x8). 0x26490 andi.l #8: clear zeroes the adjustment, set lets the two switch bits step it between the limits. Set in 0x86e8.")
add("word 3 bit 4", C, "PTAGEN S record, mask 10, 'BIT 4 OF 0-15. PARAMETER USED TO ENABLE/DISABLE PTO'. 0x2dd0a andi.l #0x10: the PTO fueling / FUELING_STATE_POWER_TAKE_OFF branch is taken only while set. Clear.")
add("word 3 bit 5", C, "PTRXEN N 'BIT 5 OF 0-15. CALIBRATION INDICATOR AS TO WHETHER R' (longest text: REMOTE PTO IS ALLO; S mask 0x20 in the files that give one). No test of 0x20; set in 0x86e8. CM848's e2m has no record.")
add("word 3 bit 6", C, "CRAGEN N 'BIT 6 OF 0-15. STATUS INDICATOR WHICH ENABLES/DISABL' (CM848 S 0x40 Cruise_Control_Enable). No test of 0x40 in the dumped ROM; set.")
add("word 3 bit 7", C, "RSAGEN N 'BIT 7, ENABLE/DISABLE ROAD SPEED GOVERNOR' (CM848 S 0x80). No test of 0x80; set.")
add("word 3 bit 8", C, "GRGDPNEN N 'GEAR DOWN PROTECTION ENABLE, BIT 8 OF 0-15' in CM550's own e2m (Gear_Down_Protection_Enable S 0x100 in the CHR_B2 files). No test of 0x100 in the dumped ROM; clear. If the CM848 rename below is applied, the comment should cite the new CM848 field name.")
add("word 3 bit 9", C, "TIEN N 'BIT 9 OF 0-15 IN WORD 3. TRIP INFO SYSTEM ENABLED = 1' (S 0x200 elsewhere; Fuel_Log_Enable 0x200). andi.w #0x200 at 0x306e0 (the trip record reset and the trip statistics run only while set) and 0x30a64. Set.")
add("word 3 bit 10", C, "CRDPEN N 'BIT 10 OF 0-15. BIT 10 IS CRUISE_RSG_DROOP_ENABLE' (CM848 S 0x400). No test of 0x400; set. CM848's field name.")
add("word 3 bit 11", C, "CPAGEN N 'BIT 11 OF 0-15. ENABLES AND DISABLES THE CYLINDER PRES(SURE MAINTENANC'. 0x11e74 andi.l #0x800: clear zeroes the cylinder pressure maintenance status, its timing increment and the method. Clear.")
add("word 3 bit 12", C, "NZFLAGEN N (no bit in the text), CM848 S 0x1000. 0xb2c6 andi.w #0x1000 gates the function that computes the ANC fuel limit value (its calibrations are the 'ANC may limit fueling' ones). Clear.")
add("word 3 bit 13", C, "NZTAAGEN N 'ENABLE FOR TIMING ADVANCE OF THE ACCELERATION NOISE' (no bit), CM848 S 0x2000. 0xb3ec andi.w #0x2000 gates the function that computes the ANC timing limit, which 0xb4ce then applies as a ceiling on the timing advance (state 3); CM848's e2m names the output NZTALM 'Timing advance limit as determined by ANC'. timing_limit is what the code does. Clear.")
add("word 3 bit 14", C, "NZESAGEN N 'ENABLE FOR SPEED LIMITING OF THE ACCELERATION NOISE' (no bit), CM848 S 0x4000. 0xb50e andi.w #0x4000 gates the ANC engine speed limit ramp. Clear.")
add("word 3 bit 15", C, "CRSVPWEN N 'BIT 15 OF 0-15, ENABLES/DISABLES SAVING CRUISE SET SP' (CM848 S 0x8000). No test of 0x8000; set. CM848's field name.")

# ---------------------------------------------------------------- word 4
add("word 4", C,
    "0x803c9c = 106B +A (EEPROM 0x192), no row today. Two references: 0x1c67a move.w + andi.w #0x100 and 0x3456e move.w + andi.l #1; no "
    "store; 0x0000 in both dumps. Records: FSUCFLEN 'BIT 0 WORD 4', TSUCTAEN and ADV_OVER 'BIT 8 OF WORD 4' (CM848 S 0x1 and 0x100). CM848's "
    "algorithm_enable_flags_4_t has user_commanded_fueling_enable at bit 0, user_commanded_timing_enable at bit 8 and reserved elsewhere, and "
    "its two readers do what the CM550 ones do, so the shared type is right.")
add("word 4 bit 0", C, "FSUCFLEN N 'BIT 0 WORD 4. ENABLES THE USE OF USER_COMMANDED_FUELING'. 0x3456e andi.l #1: with no user fueling state selected it sets state 5 (Calterm USERCOMD) and the fuel demand from 0x80404a. Clear.")
for b in range(1, 8):
    add("word 4 bit %d" % b, C, "No record for mask 0x%x at 106B +A, no test, clear; reserved in CM848's type too." % (1 << b))
add("word 4 bit 8", C, "TSUCTAEN and ADV_OVER N 'BIT 8 OF WORD 4. ENABLE INDICATOR FOR THE ENGINE(ERING COMMAND TIMING'. 0x1c67a andi.w #0x100: set takes the 4D timing from 0x803f3e with intermediate timing state 2. Clear.")
for b in range(9, 16):
    add("word 4 bit %d" % b, C, "No record for mask 0x%x at 106B +A, no test, clear; reserved in CM848's type too." % (1 << b))

# ---------------------------------------------------------------- word 5
add("word 5", C,
    "0x803c9e = 106B +C (EEPROM 0x194). 8 references: the whole-word load to d5 at 0xb7d2 and 7 single-bit reads (0x400 at 0x10584, "
    "0x1083e, 0x20cae, 0x20e4a, 0x2582e, 0x32f78; 0x800 at 0x32fd8); no store; 0x0000 in the dumps. The loop disassembles as: d2 = 1, "
    "'move.w d5,d0; and.w d2,d0' selects 0x80a72e[d3] (analog_sensor_override_values) as the filtered value, add.w d2,d2 per channel, and at "
    "d3 = 16 d2 = 1 again with d5 = word 6; it ends at 0x80a4d0 = 25 channels. So bit n = channel n. In CM550's own e2m the OD record with "
    "mask 1 << n has the stem of channel n's block 1003 record for all 16 (checked from the CA / HE / LE records). The word is tested and "
    "never written, so a bitfield suits it (7 named tests against one whole-word load). CM848's word 5 is a different set, so the type is CM550's own.")
ch = [
    (0, "ADIMTPOD", "01", "INTAKE_MANIFOLD_TEMPERATURE_OVERRIDE", "ADIMTPCA 'INTAKE_MANIFOLD_TEMPERATURE_CHANNEL_ADDRESS'"),
    (1, "ADFLTPOD", "02", "FUEL_TEMPERATURE_OVERRIDE", "ADFLTPCA 'FUEL_TEMPERATURE_CHANNEL_ADDRESS'"),
    (2, "ADCVOD", "04", "COOLANT_LEVEL_OVERRIDE", "ADCVCA 'COOLANT LEVEL CHANNEL ADDRESS'"),
    (3, "ADSYFPOD", "08", "ALGORITHM_ENABLE_FLAGS WORD 5 BIT 3", "ADSYFPCA 'ENGINE_SYNC_FUEL_PRESSURE_CHANNEL_ADDRESS' (the meaning comes from the channel, the OD text gives only the bit)"),
    (4, "ADOLPROD", "10", "OIL_PRESSURE_OVERRIDE", "ADOLPRCA 'OIL_PRESSURE_CHANNEL_ADDRESS'"),
    (5, "ADBSPROD", "20", "BOOST_PRESSURE_OVERRIDE", "ADBSPRCA 'BOOST_PRESSURE_CHANNEL_ADDRESS'"),
    (6, "ADCLTPOD", "40", "COOLANT_TEMPERATURE_OVERRIDE", "ADCLTPCA 'COOLANT_TEMPERATURE_CHANNEL_ADDRESS'"),
    (7, "ADAATPOD", "80", "AMBIENT_AIR_TEMPERATURE_OVERRIDE", "ADAATPCA 'AMBIENT AIR TEMPERATURE CHANNEL ADDRESS'"),
    (8, "ADPOTPOD", "100", "POWER_STEERING_TEMPERATURE_OVERRIDE", "ADPOTPCA 'POWER_STEERING_TEMPERATURE_CHANNEL_ADDRESS'"),
    (9, "ADSYEPOD", "200", "SPARE_CHANNEL_1_OVERRIDE", None),
    (10, "ADSATHOD", "400", "SAMPLED_THROTTLE_OVERRIDE", "ADSATHCA 'SAMPLED_THROTTLE_CHANNEL_ADDRESS'"),
    (11, "ADROTHOD", "800", "REMOTE_THROTTLE_OVERRIDE", "ADROTHCA 'REMOTE_THROTTLE_CHANNEL_ADDRESS'"),
    (12, "ADAAPROD", "1000", "AMBIENT_AIR_PRESSURE_OVERRIDE", "ADAAPRCA 'AMBIENT_AIR_PRESSURE_CHANNEL_ADDRESS'"),
    (13, "ADBTVTOD", "2000", "ALGORITHM_ENABLE_FLAGS WORD 5 BIT 13", "ADBTVTCA 'BATTERY_VOLTAGE_CHANNEL_ADDRESS' (the meaning comes from the channel, the OD text gives only the bit)"),
    (14, "ADESSVOD", "4000", "ENGINE_SPEED_SENSOR_SV_OVERRIDE", "ADESSVCA 'ENGINE_SPEED_SENSOR_SV_CHANNEL_ADDRESS'"),
    (15, "ADTHSVOD", "8000", "THROTTLE_POSITION_SENSOR_SV_OVERRIDE", "ADTHSVCA 'THROTTLE_POSITION_SENSOR_SV_CHANNEL_ADDRESS'"),
]
for b, mn, mask, text, ca in ch:
    if b == 9:
        add("word 5 bit 9", C,
            "ADSYEPOD S mask 200 'SPARE_CHANNEL_1_OVERRIDE'. The loop proves bit 9 = channel 9, and CM550's own e2m names that channel: "
            "ADSYEPCA (1003 +E8 = 24 x 9 + 16) 'ENGINE_SYNC_EXHAUST_PRESSURE_CHANNEL_ADDRESS', ADSYEPHE / ADSYEPLE "
            "'ENGINE_SYNC_EXHAUST_PRESSURE_HIGH / LOW_ERR'; only the override records (ADSYEPOD / PZ / PR / UR) say SPARE_CHANNEL_1. The field "
            "follows the channel's row name (exhaust_pressure_sensor_state), which is consistent; the comment would be stronger citing ADSYEPCA "
            "than the other product's ADEXPROD. Clear.")
        continue
    extra = ""
    if b == 10:
        extra = " Also tested alone: andi.l #0x400 at 0x10584 / 0x1083e (throttle processing and idle validation skipped while set), 0x20cae / 0x20e4a (the J1939 pedal writes analog_sensor_override_values[10]), andi.w at 0x2582e (pedal fault selection) and 0x32f78 (EEC2 pedal byte 0xff)."
    if b == 11:
        extra = " Also tested alone: andi.l #0x800 at 0x32fd8 (EEC2 remote accelerator byte 0xff)."
    add("word 5 bit %d" % b, C, "%s S mask %s '%s'; channel %d by the loop (mask 1 << %d), and the channel's own record is %s.%s Clear in the dumps." % (mn, mask, text, b, b, ca, extra))

# ---------------------------------------------------------------- word 6
add("word 6", A,
    "0x803ca0 = 106B +E (EEPROM 0x196), no row today. One reference: the whole-word load to d5 at 0xbccc, taken when the channel counter "
    "reaches 16 with the mask reset to 1; the loop ends after channel 24, so only bits 0-8 are ever tested and no fixed-mask test exists. No "
    "store; 0x0000 in the dumps. A plain word is right (nothing would render by name). Bits 0-8 match the OD records and the channel "
    "records of channels 16-24; bits 10-15 have the bit in their N text and CM848's field names. One gloss in the row comment is not "
    "proved: ISIMEN's text is cut at '0 - AMBIENT TEMP = DO' in every e2m file (the longest of them), and bit 9 has no reader, so "
    "'(0 = the ambient air temperature)' is a guess.",
    "name algorithm_enable_flags_6_cal, type word unchanged; row comment: '0x200 ISIMEN idle shutdown intake manifold temperature override "
    "(e2m: 1 - IMT OVERRIDE SHUTDOWN PROCESS; 0 - AMBIENT TEMP = DO..., cut in every e2m; what 0 selects is not proved)' instead of "
    "'(0 = the ambient air temperature)'")
ch6 = [
    (0, "ADVHSVOD", "01", "VEHICLE_CONNECTOR_SENSORS_SV_OVERRIDE", 16, "ADVHSVCA 'VEHICLE_CONNECTOR_SENSORS_SV_CHANNEL_ADDRESS'"),
    (1, "ADECSVOD", "02", "ENGINE SENSOR SV OVERRIDE", 17, "ADECSVCA 'ENGINE_CONN_SENSORS_SV_CHANNEL_ADDRESS'"),
    (2, "ADFTSVOD", "04", "FREQUENCY_THROTTLE_INPUT_SV_OVERRIDE", 18, "ADFTSVCA 'FREQUENCY_THROTTLE_INPUT_SENSOR_SV_CHANNEL_ADDRESS'"),
    (3, "ADCROD", "08", "CRUISE_CONTROL_SWITCH_MUX_OVERRIDE", 19, "ADCRCA 'CRUISE_CONTROL_SWITCH_MUX_CHANNEL_ADDRESS'"),
    (4, "ADWFOD", "10", "WATER_IN_FUEL_OVERRIDE", 20, "ADWFCA 'WATER_IN_FUEL_CHANNEL_ADDRESS'"),
    (5, "ADEGCFOD", "20", "EGR_CURRENT_FEEDBACK_OVERRIDE", 21, "ADEGCFCA 'EGR_CURRENT_FEEDBACK_CHANNEL_ADDRESS'"),
    (6, "ADPSSVOD", "40", "PROGRAMMING_PULSE_SV_OVERRIDE", 22, "ADPSSVCA 'PROGRAMMING_PULSE_SV_CHANNEL_ADDRESS'"),
    (7, "ADHBSVOD", "80", "HIGH_SIDE_GATE_BIAS_SV_OVERRIDE", 23, "ADHBSVCA 'HIGH_SIDE_GATE_BIAS_SV_CHANNEL_ADDRESS'"),
    (8, "ADOCSVOD", "100", "OP_AMPS_AND_COMPARATORS_SV_OVERRIDE", 24, "ADOCSVCA 'OP_AMPS_AND_COMPARATORS_SV_CHANNEL_ADDRESS'"),
]
for b, mn, mask, text, chn, ca in ch6:
    add("word 6 bit %d" % b, C, "%s S mask %s '%s'; channel %d by the loop (mask restarts at 1 at channel 16), whose own record is %s. Clear. Comment only (word 6 stays a word)." % (mn, mask, text, chn, ca))
add("word 6 bit 9", A,
    "Position holds: ISIMEN is an S record in CM550's own e2m, mask 200, 'BIT 9 WORD 6. 1 - IMT OVERRIDE SHUTDOWN PROCESS; 0 - AM'; the "
    "name is a literal reading of that. No reader (the loop stops at bit 8), clear. The comment's '(the idle shutdown temperature override "
    "uses the intake manifold temperature instead of the ambient air temperature)' is not in any e2m: the longest text in the repo ends "
    "'0 - AMBIENT TEMP = DO'.",
    "bit 9 idle_shutdown_intake_manifold_temperature_override_enable unchanged; comment: quote '1 - IMT OVERRIDE SHUTDOWN PROCESS; 0 - "
    "AMBIENT TEMP = DO' (cut in every e2m) and mark the 'instead of the ambient air temperature' reading as a guess")
fans = [
    (10, "FCAKAGEN", "BIT 10 OF 0-15, ALLOWS PRESSURE SWITCH FUNCTIONALITY", "0x400", "fan_air_conditioning_pressure_enable"),
    (11, "FCAKVSEN", "BIT 11 OF 0-15, ALLOWS SPECIAL AC PRESSURE SWITCH FUNCTIONALITY", "0x800", "fan_air_conditioning_vehicle_speed_interaction_enable"),
    (12, "FC02EN", "BIT 12 OF 0-15 ALLOWS BUS APPLICATIONS IMT FAN CONTROL", "0x1000", "fan_clutch_2_enable"),
    (13, "FCEBAGEN", "BIT 13 OF 0-15, ALLOWS ENGINE BRAKE FUNCTIONALITY", "0x2000", "fan_engine_retarder_enable"),
    (14, "FCEN", "BIT 14 OF 0-15, ALLOWS MANUAL SWITCH INPUT FUNCTIONALITY", "0x4000", "fan_manual_input_enable"),
    (15, "CREBEN", "TRIM PARAMETER ENABLES/DISABLES CC/EBRAKE BIT 15 OF 0", "0x8000", "cruise_engine_retarder_enable"),
]
for b, mn, text, mask, name in fans:
    add("word 6 bit %d" % b, C, "%s N '%s'; CM848's S mask is %s and its field at that bit is %s. No reader in the dumped ROM (the loop tests bits 0-8 only); clear. Comment only." % (mn, text, mask, name))

# ---------------------------------------------------------------- CM848 renames
add("cm848 algorithm_enable_flags_3_t bit 12", C,
    "CM848's own e2m (CHR_CC_11.45.01.07): ANC_Fuel_Algorithm_Enable, 106B +8, S mask 1000, '[NZFLAGEN] Enable for fuel limiting of the "
    "acceleration noise control algorithm'. No reader in cm848_rom.ghidra.cpp, like idle_speed_adjust_enable and "
    "cruise_governor_droop_enable, which are named from their records. CM550 tests the same mask in its ANC fuel limit function.")
add("cm848 algorithm_enable_flags_3_t bit 13", C,
    "CM848's own e2m: ANC_Timing_Algorithm_Enable, S mask 2000, '[NZTAAGEN] Enable for timing advance of the acceleration noise control "
    "algorithm'; the same e2m names the algorithm's output NZTALM 'Timing advance limit as determined by ANC' and has "
    "ANC_Timing_Limit_Status / _Inhibit, so timing_limit is CM848's own wording too. No CM848 reader. CM550 tests 0x2000 in the function "
    "that computes the limit.")
add("cm848 algorithm_enable_flags_3_t bit 14", C,
    "CM848's own e2m: ANC_Speed_Algorithm_Enable, S mask 4000, '[NZESAGEN] Enable for speed limiting of the acceleration noise control "
    "algorithm'. No CM848 reader. CM550 tests 0x4000 in its ANC engine speed limit function.")
add("cm848 algorithm_enable_flags_3_t bit 8", C,
    "A judgment call, and the evidence supports it; the current name is not wrong (it describes the code), so the rename is optional "
    "convergence on the e2m label. CM848's own e2m has no record for 0x100 at 106B +8, but it does carry the feature (Gear_Down_Active, "
    "Gear_Down_Gear_Ratio 'gear down gear ratio, down from top gear'). The bit's two CM848 readers "
    "(cm848_calculateRoadSpeedGovernorFueling, cm848_selectCruiseGovernorGainSet) are the only readers of drivetrain_gear_range, the range "
    "built from that gear down ratio, and both act only when it is not top gear. The same table position is GRGDPNEN 'GEAR DOWN PROTECTION "
    "ENABLE, BIT 8 OF 0-15' in CM550's e2m and Gear_Down_Protection_Enable S 100 in the seven later Chrysler CHR_B2 files, so the label "
    "held before and after CM848. If it is applied: keep the behaviour text (no droops below top gear) in the field comment, and update "
    "the two texts that carry the old description - the algorithm_enable_flags_3_cal row comment ('bit 8 has no record (the road speed "
    "governor without droops below top gear)') and the CM550 word 3 bit 8 field comment, which quotes the old field name.")

out = os.path.join(os.path.dirname(os.path.abspath(__file__)), "verdicts_W1.json")
json.dump(V, open(out, "w"), indent=1)
print(len(V), "verdicts ->", out)
import collections
print(collections.Counter(v["verdict"] for v in V))
