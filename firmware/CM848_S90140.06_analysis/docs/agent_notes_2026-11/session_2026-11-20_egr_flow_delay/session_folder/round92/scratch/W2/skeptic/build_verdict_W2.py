"""Skeptic, batch W2: build the verdict list from batch_W2.json (one element per word, per named bit and per CM848
rename), check it is complete, check every quoted 'replace' string is a literal substring of the proposal text it
amends, and write verdict_W2.json next to this script.
usage: build_verdict_W2.py <batch_W2.json>"""
import json
import os
import sys

HERE = os.path.dirname(os.path.abspath(__file__))
prop = json.load(open(sys.argv[1]))["proposal"]
words = {w["word"]: w for w in prop["words"]}
verdicts = []
checks = []  # (description, old string, text that must contain it)


def add(element, verdict, reason, amendment=None):
    v = {"element": element, "verdict": verdict, "reason": reason}
    if amendment:
        v["amendment"] = amendment
    verdicts.append(v)


def field(word, bit):
    return words[word]["fields"][bit]


def must_contain(what, old, text):
    checks.append((what, old, text))


# ---------------------------------------------------------------------------------------------------------- word 7
old7 = "for the oil pressure start-up inhibit"
must_contain("word 7 row", old7, words[7]["row_comment"])
add("word 7", "AMENDED",
    "Bits, name and layout hold. 0x803ca2 = 106B +10 = EEPROM 0x198; 0xffff in EEPROM and RAM. One absolute reference in "
    "the ROM (0x1983e: 3039 00803ca2 0240 1000 = move.w + andi.w #0x1000 + beq), none to 0x803ca3, no store. I "
    "disassembled the five loops: bit number 0x70 + 4 x channel + k (moveq #112 at 0x19718, #113 at 0x18e22, #114 at "
    "0x1902a; addi.w #0x70 at 0x18b64 and moveq #112 at 0x18cf8, then +2 / +3), word = bit / 16 from 0x803c94, mask = "
    "1 shifted left by bit mod 16, 9 channels (36-byte configs 0x807032-0x807176). The channel inputs are set by ROM code "
    "(vp44_engineProtectionSystemInit 0x1873e), and e2m 10B3 +0 EPSOAE lists 'C. LEV. = 0, C. TEMP. = 1, IMT = 2, OIL "
    "PRESS. = 3'. CM848's 16 records at +0010 carry the same masks and its row is a plain word with no reference in its "
    ".cpp. Two points. (1) The direct test is not an inhibit: with bit 12 set and the timer 0x80062e below 0x807f34 it "
    "forces the oil pressure severity and the loop maximum to 0x100 = the full derate; 0x807f34 is e2m 10B4 +2 EPFLSRTM, "
    "which CM848's e2m labels Fueling_Startup_Derate_Time. (2) The type name is the judgment call the proposer flagged: "
    "no bit differs from CM848's word 7, so by the twin rule the cm550_ prefix (kept for types that differ) is not "
    "needed.",
    "Row comment: replace '" + old7 + "' with 'for the oil pressure start-up fueling derate (e2m 10B4 +2 EPFLSRTM - "
    "CM848 label Fueling_Startup_Derate_Time)'. Name algorithm_enable_flags_7_cal and all 16 fields unchanged. "
    "Separately (the flagged judgment call; it can be declined without losing the comment fix): type name "
    "algorithm_enable_flags_7_t in place of cm550_algorithm_enable_flags_7_t; shared_with_cm848 stays false (CM848 has "
    "no such type) and no CM848 row is added or retyped.")

W7 = [("EPCV", "coolant level", "0x8091e6 EPCVSWLO"), ("EPCQ", "coolant temperature", "0x80a336 ADCLTPFT"),
      ("EPIM", "intake manifold temperature", "0x80a26a EPIMTPFT"), ("EPO2", "oil pressure", "0x80a30a ADOLPRFT")]
KSUF = ["FLEN", "RPEN", "SOEN", "RYEN"]
KREAD = ["k 0 = cm550_FUN_00019702 (moveq #112 at 0x19718)",
         "k 1 = cm550_calculateFaultDerateEngineSpeedLimit (moveq #113 at 0x18e22)",
         "k 2 = processDiagnosticLimitStatus (moveq #114 at 0x1902a) and the +2 tests at 0x18b6c / 0x18d1a",
         "k 3 = the +3 tests at 0x18b9a / 0x18d46 (the two restart checks)"]
for bit in range(16):
    ch, k = divmod(bit, 4)
    pre, cname, inp = W7[ch]
    token = "B3." if bit == 3 else ("BIT 5 OF 5-15" if bit == 5 else f"BIT {bit} OF 0-15")
    reader = KREAD[k]
    if ch == 3 and k == 2:
        reader = "k 2 = processDiagnosticLimitStatus (moveq #114 at 0x1902a) and the validator's +2 test at 0x18d1a"
    if ch == 3 and k == 3:
        reader = "k 3 = the validator's +3 test at 0x18d46"
    base = (f"{pre}{KSUF[k]}: N record '{token}' in v64t6_s, S mask 0x{1 << bit:x} in 34 other files (CM848's 16 "
            f"among them); table bit {112 + bit}: {reader}; channel {ch} = {cname}; set.")
    if bit == 12:
        add(f"word 7 bit {bit}", "CONFIRMED", base + " Direct test too: andi.w #0x1000 at 0x1983e (0240 1000); while "
            "set and 0x80062e is below 0x807f34 it writes 0x100 to 0x80581a (= 0x8057c0 + 3 x 30) and to the maximum.")
    elif bit == 14:
        old = "and by the restart checks"
        must_contain("word 7 bit 14", old, field(7, 14)["comment"])
        add(f"word 7 bit {bit}", "AMENDED", base + " One wording slip: cm550_diagnosticProtectionEvaluator returns at "
            "cmpi.w #3,(0x8058ce) (0x18b0a) before its bit tests, so of the restart checks only the validator reads "
            "this bit - as the comment of bit 15 already says.",
            "Comment only; name oil_pressure_shutdown_enable and bit unchanged. Replace '" + old + "' with 'and by the "
            "restart check cm550_protectionState1DiagnosticValidator (cm550_diagnosticProtectionEvaluator skips "
            "channel 3)'.")
    elif bit == 15:
        add(f"word 7 bit {bit}", "CONFIRMED", base + " The evaluator returns at cmpi.w #3,(0x8058ce) (0x18b0a) "
            "first, as the comment says.")
    else:
        add(f"word 7 bit {bit}", "CONFIRMED", base)

# ---------------------------------------------------------------------------------------------------------- word 8
add("word 8", "CONFIRMED",
    "0x803ca4 = 106B +12 = EEPROM 0x19a; 0x0000 in EEPROM and RAM. Two absolute references, both in "
    "vp44_FUN_0001cad6: 0x1caec andi.l #0x1000 + bne and 0x1cafa andi.l #0x2000 + beq (after word 2 andi.l #0x10 at "
    "0x1cade); none to 0x803ca5, no store. Table bits 128-143 are channels 4-7 of the same five loops. The channel "
    "inputs set by ROM 0x1873e are 0x80a46a ADWFFT / 0x80a320 ADFTBSPR / 0x80a2f4 ADSYFPFT (1003 +58 ADSYFPCA "
    "'ENGINE_SYNC_FUEL_PRESSURE_CHANNEL_ADDRESS') / 0x80a254 EPFLTP; their config flags 0x8070c2-0x80712e read 0. CM848's "
    "word 8 has fuel temperature at masks 0x1-0x8 and C_Out / T_In at 0x10-0x800, so cm550_ is right and nothing is "
    "shared.")
KSHORT = ["k 0 (fuel limit loop)", "k 1 (speed limit loop)", "k 2 (shutdown loop and restart checks)",
          "k 3 (restart checks)"]
W8 = [("EPWF", "water in fuel", "0x80a46a ADWFFT"), ("EPBS", "boost pressure", "0x80a320 ADFTBSPR"),
      ("EPFP", "engine sync fuel pressure", "0x80a2f4 ADSYFPFT"), ("EPFT", "fuel temperature", "0x80a254 EPFLTP")]
for bit in range(16):
    ch, k = divmod(bit, 4)
    pre, cname, inp = W8[ch]
    tb = 128 + bit
    if ch < 3:
        r = (f"{pre}{KSUF[k]}: S mask 0x{1 << bit:x} in v64t6_s itself (and 26 other ISB files); table bit {tb}: "
             f"{KSHORT[k]} of channel {4 + ch} = {cname} ({inp}); clear.")
        if bit == 4:
            r += (" Its text is the engine sync record's in all 27 files; the mask sits in the boost nibble and channel "
                  "5's input is the boost pressure, so the name is right.")
    else:
        r = (f"{pre}{KSUF[k]}: N record 'BIT {bit} OF 0-1{'4' if bit == 14 else '5'}' in v64t6_s and 35 other ISB "
             f"files (no S mask in this family); table bit {tb}: {KSHORT[k]} of channel 7 = {cname} ({inp}); clear.")
        if bit == 12:
            r += " Direct test: andi.l #0x1000 at 0x1caec gates the update of 0x80a254 itself, which ties bit 12 to channel 7."
        if bit == 13:
            r += " Direct test: andi.l #0x2000 at 0x1cafa, the second operand of the same update."
    add(f"word 8 bit {bit}", "CONFIRMED", r)

# ---------------------------------------------------------------------------------------------------------- word 9
add("word 9", "CONFIRMED",
    "0x803ca6 = 106B +14 = EEPROM 0x19c; 0x0000 in both dumps. No 32-bit operand 0x803ca6-0x803ca9 anywhere in the ROM "
    "(any byte offset), so a plain word is right: only the five loops reach it, as table bits 144-147 of channel 8 "
    "(input 0x80a2aa + 0x110 = 0x80a3ba ADAAPRFT, set by ROM 0x1873e), and they stop after 9 channels. v64t6_s has four "
    "S records (masks 0x1-0x8). CM848 has no row, no record at +0014 and no reference to 0x3fd5ae (0x0000 in its dump). "
    "For bits 4-11: the 18 files with EPOE* / EPOS* are 63t10r4, the seven 74be*, 74c0 / 74c5 / 74c6, 74t5 / 74t6, "
    "74te3rls / 74te4rls / 74te5rls, 84t0 and Isbp700.")
for bit in range(16):
    if bit < 4:
        add(f"word 9 bit {bit}", "CONFIRMED",
            f"EPAA{KSUF[bit]}: S mask 0x{1 << bit:x} in v64t6_s; table bit {144 + bit}: {KSHORT[bit]} of channel 8 = "
            "ambient air pressure (0x80a3ba ADAAPRFT); clear. Documentation only (the word stays plain).")
    elif bit < 12:
        old = "20 other ISB e2m files"
        must_contain(f"word 9 bit {bit}", old, field(9, bit)["comment"])
        fam = "EPOE* (masks 0x10-0x80)" if bit < 8 else "EPOS* (masks 0x100-0x800)"
        add(f"word 9 bit {bit}", "AMENDED",
            f"reserved_bit_{bit} is right: no v64t6_s record at mask 0x{1 << bit:x}, the loops stop at bit 3, clear. "
            f"The count in the guess is off: {fam} are in 18 other files, not 20.",
            "Documentation only (the word stays plain); name and bit unchanged. Replace '" + old + "' with '18 other ISB "
            "e2m files'.")
    else:
        add(f"word 9 bit {bit}", "CONFIRMED",
            f"No record with mask 0x{1 << bit:x} at 106B +14 in any e2m file (the highest is 0x800); not "
            "read; clear. Documentation only.")

# --------------------------------------------------------------------------------------------------------- word 11
add("word 11", "CONFIRMED",
    "0x803caa = 106B +18 = EEPROM 0x1a0; 0x000b in both dumps (CM848's 0x3fd5b2 reads 0x000b too). Seven absolute "
    "references, all 3039 00803caa 0240 000N (move.w + andi.w) + beq: 0xebac #4, 0xebe0 #2, 0x15fe8 #1, 0x16396 #2, "
    "0x163be #4, 0x1ff4e #8, 0x212c0 #8; none to 0x803cab, no store. All 16 field names equal CM848's "
    "algorithm_enable_flags_11_t and bits 0-3 mean the same there (S masks 0x1 / 0x2 / 0x4 / 0x8 in "
    "CHR_CC_11.45.01.07), so the shared type holds. The rename is right: the word gates the datalink protocols.")
add("word 11 bit 0", "CONFIRMED",
    "JCJPEA is an N record with no bit in all 36 ISB files; CM848's e2m gives the same text as "
    "Proprietary_Communication_Enable with S mask 0x1. Code settles the bit: andi.w #1 at 0x15fe8 gates the J1708 "
    "messages whose first byte is below 8 (key + commands 0x40-0x54, control 0x64-0x76, memory, abort). Set.")
add("word 11 bit 1", "CONFIRMED",
    "JC87CZEA 'BIT 1 OF 0-15' (S mask 0x2 in 34 other files); andi.w #2 at 0xebe0 (every second pass: "
    "vp44_insiteParameterTableIterator) and 0x16396 (first byte 0x80 and up = the J1587 range). Set.")
add("word 11 bit 2", "CONFIRMED",
    "JC22CZEA 'BIT 2 OF 0-15' (S mask 0x4 in 30 other files); andi.w #4 at 0xebac (the 0x45 / 0x53 builders) and "
    "0x163be (first byte 0x45-0x56 = 69-86, the J1922 range). Clear.")
add("word 11 bit 3", "CONFIRMED",
    "JC39CZEA 'BIT 3 OF 0-15' (S mask 0x8 in 34 other files); andi.w #8 at 0x1ff4e (the two 10-byte periodic "
    "schedules at 0x80096e / 0x800a36) and 0x212c0 (CAN receive ring + j1939_receive_handler_table). Set.")
old = "(S mask 0x10 in 14 other ISB e2m files)"
must_contain("word 11 bit 4", old, field(11, 4)["comment"])
add("word 11 bit 4", "AMENDED",
    "reserved_bit_4 is right and equals CM848's field: no v64t6_s record, no test of 0x10 on 0x803caa, clear. The "
    "count is off by one: JCRWDXEN (S mask 0010 at +18) is in 13 other files, not 14.",
    "Comment only; name and bit unchanged. Replace '" + old + "' with '(S mask 0x10 in 13 other ISB e2m files)'.")
for bit in range(5, 16):
    add(f"word 11 bit {bit}", "CONFIRMED",
        f"No record with mask 0x{1 << bit:x} at 106B +18 in any e2m file (the highest is JCRWDXEN 0x10), no test, clear "
        f"in 0x000b; CM848's field is reserved_bit_{bit} too.")

# --------------------------------------------------------------------------------------------------------- word 12
add("word 12", "CONFIRMED",
    "0x803cac = 106B +1A = EEPROM 0x1a2 = word 12 ((0x803cac - 0x803c94) / 2; the records say WORD C), so the old "
    "_word_9 name was misnumbered. 0xbb87 in both dumps. Twelve absolute references, all move.w + andi with one bit: "
    "0xc19c 0x8, 0xc3ea 0x10, 0xfa1c 0x40, 0x1850e 0x40, 0x1abcc 0x10, 0x1ad52 0x20, 0x1ca9a 0x2, 0x1cd96 0x10 (this "
    "one is followed by sne, not a branch), 0x26546 0x1, 0x265a0 0x1, 0x26646 0x4000, 0x34c3e 0x4; none to 0x803cad, "
    "no store. CM848's CHR_CC e2m has S records at 0x1-0x2000 and none at 0x4000 / 0x8000, and v64t6_s has none at "
    "0x400, so cm550_ is right. If the bit 9 amendment is taken, differences_from_cm848 needs the sentence given "
    "there.")
add("word 12 bit 0", "CONFIRMED",
    "LSISSVEN 'BIT 0 OF 0 - 15' (S mask 0x1 in 34 other files); andi.w #1 at 0x26546 (clear zeroes 0x805f0a = 1073 +0 "
    "LSICBKRF, set stores the operator adjustment) and 0x265a0 (start-up). Set.")
add("word 12 bit 1", "CONFIRMED",
    "EPOSFSO: text cut at 'BI' in v64t6_s, 'BIT 1 OF 0 - 15 O' in 4 files, S mask 0x2 in 34. andi.l #2 at 0x1ca9a: in "
    "ENGINE_STATE_OVERSPEED with the bit set the code clears 0x20 of fuel_system_output_driver_control (000E +2D "
    "DRFSEA mask 0x20 'CONTROLS FUEL SHUT OFF DRIVER'). Set.")
add("word 12 bit 2", "CONFIRMED",
    "WFAGEN 'BIT 2' (S mask 0x4 in 34 other files); andi.w #4 at 0x34c3e: clear drops fault word 4 bit 0x2000, set "
    "raises it and lamp bit 0x10 while water_in_fuel_sensor_state.filtered_value is 1. Set.")
add("word 12 bit 3", "CONFIRMED",
    "AFENMAN 'BIT 3 OF 0-15 IN WORD C' (S mask 0x8 in 34 other files); andi.w #8 at 0xc19c selects the e2m override "
    "value over the engine speed x boost table. Clear.")
add("word 12 bit 4", "CONFIRMED",
    "SPAGEN 'BIT 4 OF 0 - 15' (S mask 0x10 in 34 other files, group 43 ESP_08 'ELECTRONIC SMART POWER GROUP'); "
    "andi.w #0x10 at 0x1abcc, andi.l #0x10 at 0xc3ea and 0x1cd96. Clear.")
add("word 12 bit 5", "CONFIRMED",
    "SPRVEN: v64t6_s cuts the text before the bit; S mask 0x20 in 34 other files and 'Bit 5 of 0 - 15' in CM848's. "
    "andi.l #0x20 at 0x1ad52 leads to state 1 of 0x80d2b6 (11DC +6 SPTUST 'NORMAL/LAUNCH/STEEP'). 'reverse' is not in "
    "CM550's text but it is Cummins' own label for this mnemonic (Reverse_ESP_Enable), so the twin name stands; four "
    "older files call the same bit SPLAAGEN (launch application). Clear.")
add("word 12 bit 6", "CONFIRMED",
    "LSDPEN 'BIT 6 OF 0 - 15 IN WORD C' (S mask 0x40 in 34 other files); andi.l #0x40 at 0xfa1c and 0x1850e: speed "
    "point 1 = idle reference - fueling x 0x80daf4 (1065 +16 LSDPSE) / 167. Clear.")
add("word 12 bit 7", "CONFIRMED",
    "ANEN 'BIT 7 OF 0-15 IN WORD C ACCELERATOR INTERLOCK ENABLE B' (S mask 0x80 in 34 other files); no test of 0x80 on "
    "0x803cac in the dumped ROM. e2m only. Set.")
add("word 12 bit 8", "CONFIRMED",
    "VSMVEN 'BIT 8 WORD C. ENABLES VSS SENSOR LOST WHILE MOVING' (S mask 0x100 in 34 other files); no test. 'signal "
    "loss' says no more than the record does, so CM848's name passes. If bit 9 takes the e2m wording, the parallel "
    "name here would be vehicle_speed_sensor_lost_while_moving_detection_enable (optional). Set.")
old9 = "CM848 field name (named there after its detector: the sensor reads 0 while the engine is under load)"
must_contain("word 12 bit 9", old9, field(12, 9)["comment"])
d1 = "field names are reused."
d2 = "Three bits differ"
must_contain("word 12 differences", d1, words[12]["differences_from_cm848"])
must_contain("word 12 differences", d2, words[12]["differences_from_cm848"])
add("word 12 bit 9", "AMENDED",
    "Position holds: VSSTEN 'BIT 9 WORD C. ENABLES VSS SENSOR LOST WHILE STOPPE(D DETECTION)', S mask 0x200 in 34 "
    "other files, set in 0xbb87. The name does not: 'zero under load' is in no CM550 record and J90350.00 has no test "
    "of 0x200 on this word. CM848's own struct comment says that field was 'Named after the detector it gates' "
    "(cm848_detectVehicleSpeedSensorZeroUnderLoad), so the wording is CM848 code, not Cummins' label "
    "(VSS_Stopped_Enable). The type is cm550_, so nothing forces the twin name.",
    "Name vehicle_speed_sensor_lost_while_stopped_detection_enable (bit 9 unchanged). Comment: replace '" + old9 +
    "' with 'the same record as CM848 vehicle_speed_sensor_zero_under_load_enable (CM848 named that field after its "
    "own detector - nothing proves that detector for J90350.00)'. Follow-on in differences_from_cm848: replace '" + d1 +
    "' with 'field names are reused for bits 0 / 2-8 / 11-13; bit 9 is the same record but keeps the e2m wording "
    "because the CM848 name describes the CM848 detector.' and replace '" + d2 + "' with 'Three bits differ in "
    "meaning (10 / 14 / 15) and bit 9 in name only'.")
old = "(mask 0x400 here in 26 other e2m files; CM848 obd_fault_handler_enable)"
must_contain("word 12 bit 10", old, field(12, 10)["comment"])
add("word 12 bit 10", "AMENDED",
    "reserved_bit_10 is right: no v64t6_s record at 106B +1A with mask 0x400, no test of 0x400, clear in 0xbb87. The "
    "count is wrong: an S record with mask 0x400 sits here in 28 other files (all 23 CHR files - 16 CHR_CC with the "
    "mnemonic and 7 CHR_B2 under the label OBD_Fault_Handler_Enable - and 5 ISB files: 00V2, v55t16_s, v57t6_x, "
    "v59t5_t, V59t8_t), and DGOBFUHN is an N record with no bit in 4 more (42t9_rls, 44t9, Isbp400, Phase4).",
    "Comment only; name and bit unchanged. Replace '" + old + "' with '(S mask 0x400 here in 28 other e2m files - the "
    "23 CHR files and 5 ISB files - and an N record with no bit in 4 more ISB files; CM848 "
    "obd_fault_handler_enable)'.")
add("word 12 bit 11", "CONFIRMED",
    "PTBRODEN: v64t6_s cuts the bit letter; 4 other ISB files keep 'WORD C BIT B' and 34 files carry it as an S record "
    "with mask 0x800 (18 ISB, 16 CHR_CC). No test; e2m only. Set.")
add("word 12 bit 12", "CONFIRMED",
    "PTCHODEN: letter cut in v64t6_s; 'WORD C BIT C' in 4 other ISB files, S mask 0x1000 in 34. No test; e2m only. "
    "Set.")
add("word 12 bit 13", "CONFIRMED",
    "OCEA 'ENABLES OIL CHANGE MONITOR FEATURE BIT 13 OF 0-15 OF W' (S mask 0x2000 in 38 other files); no test; e2m "
    "only. Set.")
old = "13 other e2m files"
must_contain("word 12 bit 14", old, field(12, 14)["comment"])
add("word 12 bit 14", "AMENDED",
    "Name and position hold, and the code alone proves them: andi.w #0x4000 at 0x26646 (0240 4000); the cold idle "
    "adder is skipped only when the bit is set and 0x80db08 (1049 +6 LSCIOD 'TRUE INHIBITS COLD IDLE ADJUSTMEN') is "
    "non-zero. CM848's CHR_CC e2m has no record at 0x4000. The count is wrong: '- BIT 14' follows the text in 9 other "
    "files (00V2, 42t9_rls, 44t9, Isbp400, Phase4, v55t16_s, v57t6_x, v59t5_t, V59t8_t), not 13.",
    "Comment only; name and bit unchanged. Replace '" + old + "' with '9 other e2m files'.")
add("word 12 bit 15", "CONFIRMED",
    "EDEN 'BIT 15 OF 0 - 15; ENABLES/DISABLES EDF FEATURE.' with group 12C = ENDTFL07 'ENGINE DATA FILES ENABLE AND "
    "POWER-DOWNS', which spells EDF. No test; e2m only. Set. CM848's CHR_CC files have no record at 0x8000 (EDF_Enable "
    "is only in the six CHR_B2 files).")

# --------------------------------------------------------------------------------------------------------- word 13
add("word 13", "CONFIRMED",
    "0x803cae = 106B +1C = EEPROM 0x1a4; 0x0000 in both dumps. Six absolute reads (0x15830 andi.w #0x2000, 0x15850 "
    "andi.w #0x4000, 0x204e6 andi.w #0x80, 0x20cbe and 0x20e5a andi.l #0x80, 0x32ed4 andi.w #0x80) and one address "
    "load (23fc 00803cae 0080054c at 0x15dd2); no store, and the pointer users only read. The sampler builds status "
    "0x80bcce / 0x80bccf as (input AND NOT mask) OR (0x80bcd8 / 0x80bcd9 AND mask) with mask [1] / [0], so bit s is "
    "logical switch s. The descriptor table at ROM 0x20108 (17 entries of 10 bytes, switch number at +8) gives table "
    "bit 0xd0 + s. e2m blocks 106B, 000E (+0 / +1 status, +A / +B values), 12A8 (+s), 12FC and 1234 (bit s) name the "
    "same function for every switch. CM848's word 13 has four unrelated records, so cm550_ is right.")
S13 = {
    0: "No record with mask 0x1 at 106B +1C in v64t6_s (nor a 12A8 / 12FC / 1234 record for switch 0), so the name "
       "rests on code: mask byte [1] covers all eight bits of status byte 0x80bcce, and its bit 0 is the key switch "
       "(000E +0 DSKYSWSS S mask 0x1; cm550_updateEngineState and mc68k_runPowerDownSequence read it as the key). The "
       "effect of the bit is proved, so a name is allowed. Clear.",
    1: "DSCRRUUO and DS01SWUO S mask 0x2 ('CRUISE CONTROL RESUME SWITCH' in the 4 uncut files); 000E DSRUSWSS 0x2, "
       "12A8 +1 DSPZCRRU; descriptor entry 6 (0x80d716, SPN 601) holds switch 1 = table bit 209. Clear.",
    2: "DSCRSEUO and DS02SWUO S mask 0x4; 000E DSSESWSS 0x4, 12A8 +2 DSPZCRSE; descriptor entry 7 (0x80d717, SPN 599) "
       "holds switch 2 = table bit 210. Clear.",
    3: "DSCRONUO and DS03SWUO S mask 0x8 ('CC/PTO ON/OFF SWITCH'); 000E DSCRSWSS 0x8, 12A8 +3 DSPZCRON; descriptor "
       "entry 5 (0x80d715, SPN 596) holds switch 3 = table bit 211. Clear.",
    4: "DSMNFNUO, DSFACLUO and DS05SWUO S mask 0x10; 000E DSFMSW 0x10 'MANUAL FAN INPUT SWITCH', 12A8 +4 DSPZFMIP. "
       "e2m plus the byte mask [1]. Clear.",
    5: "DSPPSWUO and DS06SWUO S mask 0x20 'PTP SWITCHED INPUT SWITCH'; 000E PTSWINSW 0x20, 12A8 +5 DSP2PTSW; PTP = "
       "powertrain protection by group 10B PTP_07. e2m plus the byte mask [1]. Clear.",
    6: "DSHSDPUO and DS07SWUO S mask 0x40 'HSG DROOP SELECT SWITCH'; 000E HSDRSLSW 0x40, 12A8 +6 DSPZHGSW. e2m plus "
       "the byte mask [1]. Clear.",
    7: "DSIVSWUO and DS08SWUO S mask 0x80 'RAW IDLE SWITCH INPUT'; 000E DSIVSWSS 0x80, 12A8 +7 IDLE_SWITCH. Four "
       "direct tests of 0x80, all on the J1939 low idle switch / pedal path (0x204e6; 0x20cbe and 0x20e5a together with "
       "word 5 bit 10; 0x32ed4 sends the EEC2 switch as 3). Clear.",
    8: "DSNTIVUO and DS09SWUO S mask 0x100 'RAW NOT IDLE SWITCH INPUT'; 000E +1 DSIVNTSW 0x1, 12A8 +8 "
       "NOT_IDLE_SWITCH; mask byte [0] bit 0. Clear.",
    9: "DSOVAISW (text cut after 'WORD 13 BIT 9') and DS10SWUO S mask 0x200; 12A8 +9 DSPZAISW, 12FC DSGDAISW 0x200 and "
       "1234 DSINAISW 0x200 all say ACCELERATOR INTERLOCK; descriptor entry 1 (0x80d710, SPN 972) holds switch 9 = "
       "table bit 217. Clear.",
    10: "DSCHSWUO and DS11SWUO S mask 0x400; 000E +1 DSCHSWSS 0x4; descriptor entry 4 (0x80d713, SPN 598) holds "
        "switch 10 = table bit 218. Clear.",
    11: "DSBRSWUO and DS12SWUO S mask 0x800; 000E +1 DSBRSWSS 0x8; descriptor entry 3 (0x80d712, SPN 597) holds "
        "switch 11 = table bit 219. Clear.",
    12: "DSEBUO01, DSOVEBSW and DS13SWUO S mask 0x1000; 000E +1 DSEBS1 / EGBKSW 0x10, 12A8 +C DSPZEBS1; CM848's "
        "switch 12 is the same Engine_Brake_Select_1 record. e2m plus the byte mask [0]. Clear.",
    13: "DSICSWUO and DS14SWUO S mask 0x2000; 000E +1 DSICSWSS 0x20; descriptor entry 9 (0x80d71b, SPN 968) holds "
        "switch 13 = table bit 221; andi.w #0x2000 at 0x15830 puts status bit 0x20 back from 0x80bcd9 after the "
        "decode from the cruise switches. Clear.",
    14: "DSDTSWUO and DS15SWUO S mask 0x4000; 000E +1 DSDTSWSS 0x40; descriptor entry 8 (0x80d718, SPN 967) holds "
        "switch 14 = table bit 222; andi.w #0x4000 at 0x15850 does the same for status bit 0x40. Clear.",
    15: "DSTESWUO and DS16SWUO S mask 0x8000; 000E +1 DSTESWSS 0x80; descriptor entry 15 (0x80d724, SPN 966) holds "
        "switch 15 = table bit 223. Clear.",
}
for bit in range(16):
    add(f"word 13 bit {bit}", "CONFIRMED", S13[bit])

# --------------------------------------------------------------------------------------------------------- word 14
add("word 14", "CONFIRMED",
    "0x803cb0 = 106B +1E = EEPROM 0x1a6; 0x0000 in both dumps. One absolute reference: 0x207d0 move.w + andi.l #0x8 + "
    "beq.w, after word 18 andi.l #0x1000 at 0x207c0; none to 0x803cb1, no store. Mask bytes [3] / [2] cover status "
    "bytes 0x80bcd0 / 0x80bcd1 with values 0x80bcda / 0x80bcdb, so bit n is logical switch 16 + n; descriptor entries "
    "14 / 13 hold switches 19 / 20 = table bits 227 / 228. CM848 has no row, no record at +001E in any CHR file and no "
    "reference to 0x3fd5b8 (0x0000 in its dump). The five switch_N names use the e2m's own switch numbers (DS17 / 27 / "
    "28 / 23 / 31SWUO), which differ from the logical index for four of them; the comments say so.")
S14 = {
    0: "DS17SWUO S mask 0x1 is the only record; 000E +2 0x1, 12A8 +10, 12FC and 1234 0x10000 also carry only the "
       "generic SWITCH 17 records; no read of 0x80bcd0 bit 0 in the .cpp or by absolute address. The name says what is "
       "proved. Clear.",
    1: "DSAKTKUO and DS18SWUO S mask 0x2; 12A8 +11 DSPZACPT, 12FC DSDFACTK 0x20000 and 1234 DSINACPT 0x20000 say AC "
       "PRESSURE TURNKEY SWITCH; code copies 0x80bcd0 bit 1 into 0x80bcd7 bit 0 (000E +9 DSAKPRSW). Clear.",
    2: "DSRARSUO and DS19SWUO S mask 0x4; 000E +2 DSRARASW 0x4, 12A8 +12 DSPZRARA; the CCVS1 builder at 0x31c84 reads "
       "status bit 0x4. Clear.",
    3: "DSRMTHUO and DS20SWUO S mask 0x8; 000E +2 RMTHSW 0x8; descriptor entry 14 (0x80d723, SPN 969) holds switch 19 "
       "= table bit 227; direct andi.l #0x8 at 0x207d0 gates the J1939 remote accelerator position into "
       "analog_sensor_override_values[11]. Clear.",
    4: "DSRXSWUO and DS21SWUO S mask 0x10; 000E +2 DSRXSWSS 0x10; descriptor entry 13 (0x80d721) holds switch 20 = "
       "table bit 228. Clear.",
    5: "DSCLLOUO and DS22SWUO S mask 0x20; 000E +2 DSCLLOSW / DSLOCLLV 0x20, 12A8 +15 DSPZCLLO; the sampler compares "
       "this status bit with 0x80bcd1 bit 0 (the coolant level pair fault). Clear.",
    6: "DSUSDLUO, DSORUDSW and DS26SWUO S mask 0x40; 000E +2 DSILSSSW 0x40; btst #6,(0x80bcd0) at 0x139f6 is the "
       "datalogger's manual trigger. Clear.",
    7: "DSPRBRUO and DS24SWUO S mask 0x80. The record's own text is the manual fan's (in all 27 files that have it), "
       "but 000E +C DSPRBRUC 0x80, 12A8 +17 DSPZPRBR and 1234 DSPRBRIV 0x800000 all say parking brake for this "
       "switch; the one counter-witness is 12FC DSDFPRBR at 0x80000, as the notes say. Status bit unread. Three "
       "records against one, so the name stands. Clear.",
    8: "DSCLHIUO and DS25SWUO S mask 0x100; 000E +3 DSCLHISW / DSHICLLV 0x1, 12A8 +18 DSPZCLHI; the pair check reads "
       "it. Clear.",
    9: "DSSTCNUO and DS04SWUO S mask 0x200 'STCG ASG DROOP SWITCH'; 000E +3 SLTHCNSW 0x2; move.b (0x80bcd1) + andi.l "
       "#2 at 0xd314 and 0xd4f6 next to word 27 bit 3 (106B +38 STCGASDS 'SWITCHED THROTTLE CONTROL GOVERNOR SELECT', "
       "which spells STCG). The 76-character name is a fair reading; no rule limits length. Clear.",
    10: "DS27SWUO S mask 0x400 is the only 106B record; the other blocks disagree for switch 26 (12A8 +1A / 12FC air "
        "conditioner pressure, 1234 DSINACHP AC high pressure) and descriptor entry 0 puts the J1939 A/C pressure "
        "switch at switch 72. Keeping the e2m switch number is the cautious choice. Clear.",
    11: "DS28SWUO S mask 0x800 plus DSAKHIUO and DSTHILUO (group BD MUX_PARA). Every block gives switch 27 both alias "
        "sets (AC high pressure and throttle interlock), while the ROM routes the J1939 accelerator interlock to "
        "switch 9. Undecided is right. Clear.",
    12: "DS23SWUO S mask 0x1000 is the only 106B record in v64t6_s; 12A8 +1C DSPZEBS2 and 12FC DSDFEBS2 suggest "
        "engine brake select 2 (8 other files have DSEBUO02 here, 21 have DSOROESW OEM_SWITCH). Guess kept in the "
        "comment, as it should be. Clear.",
    13: "DSAKCYUO and DS29SWUO S mask 0x2000 ('WORD 14 BIT 13'); 12A8 +1D DSPZACCY, 12FC DSDFACCY and 1234 DSACCYIV "
        "say AC CYCLE SWITCH. e2m plus the byte mask [2]. Clear.",
    14: "DSAKONUO and DS30SWUO S mask 0x4000; 000E +D DSAKONUC 0x40 'AC_ON_OFF_SWITCH', 12A8 +1E DSPZACOO, 12FC "
        "DSDFACOO, 1234 DSACOOIV. e2m plus the byte mask [2]. Clear.",
    15: "DS31SWUO S mask 0x8000 is the only record in every block; status bit unread. Clear.",
}
for bit in range(16):
    add(f"word 14 bit {bit}", "CONFIRMED", S14[bit])

# ----------------------------------------------------------------------------------------------------- CM848 rename
ren = prop["cm848_field_renames"]
assert len(ren) == 1 and ren[0]["type_name"] == "algorithm_enable_flags_12_t" and ren[0]["bit"] == 1
add("cm848 algorithm_enable_flags_12_t bit 1", "CONFIRMED",
    "CM848's own e2m (CHR_CC_11.45.01.07) has Overspeed_FSO_Override at 106B +001A, S mask 2: '[EPOSFSO] If T, FSO "
    "closes when ovrspd detected by main micro. Bit 1 of 0 - 15 of Word C'. CM848's .cpp never prints "
    "algorithm_enable_flags_12_cal.reserved_bit_1 (11 other fields of the word render), so the rename is label-only. "
    "fuel_shutoff is CM848's existing spelling of FSO (fault_bit_words_t.fuel_shutoff_control_error). 'enable' for the "
    "label's 'Override' matches the record's text and CM550's reader at 0x1ca9a, and equals the CM550 field.")

# ------------------------------------------------------------------------------------------------------------ checks
expected = []
for w in prop["words"]:
    expected.append(f"word {w['word']}")
    expected += [f"word {w['word']} bit {b}" for b in range(16)]
expected.append("cm848 algorithm_enable_flags_12_t bit 1")
got = [v["element"] for v in verdicts]
assert len(got) == len(set(got)), "duplicate element"
assert sorted(got) == sorted(expected), set(expected) ^ set(got)
assert len(got) == 120, len(got)
for what, old, text in checks:
    assert text.count(old) == 1, f"not exactly one occurrence ({text.count(old)}): {what}: {old}"
for v in verdicts:
    assert v["verdict"] in ("CONFIRMED", "AMENDED", "REFUTED")
    assert (v["verdict"] == "AMENDED") == ("amendment" in v), v["element"]
    for key in ("element", "reason", "amendment"):
        assert not set('"<>&') & set(v.get(key, "")) and "\\" not in v.get(key, "") and "\n" not in v.get(key, ""), (v["element"], key)
assert sum(v["verdict"] == "CONFIRMED" for v in verdicts) == 106
assert sum(v["verdict"] == "AMENDED" for v in verdicts) == 14

overall = (
    "No bit position, mask, address, EEPROM offset or dump value in W2 moves, no word is written, and nothing is "
    "refuted: 106 CONFIRMED, 14 AMENDED. One amendment changes a field name (word 12 bit 9), one carries a row "
    "comment fix plus the type name judgment the proposer flagged (word 7), the other twelve are comment fixes (eight of "
    "them the same count in word 9's documentation-only bits).\n\n"
    "How it was checked (from scratch; scripts in /home/linux/.claude/jobs/374b0424/tmp/w15/r92/scratch/W2/skeptic/): "
    "my own CPU32 disassembler (m68k.py; llvm-mc-18 mis-decodes andi / tst here), a scan of the ROM for every 32-bit "
    "operand in the block at any byte offset (absrefs.py), the raw v64t6_s records with their masks (raw106b.py, "
    "blockmasks.py), all 36 ISB and 23 CHR e2m files (survey.py, countfiles.py), both dumps at word width (dumps.py), "
    "CM848's CSVs, e2m and RAM dump. The verdict list was built and checked by build_verdict_W2.py (120 elements, "
    "each quoted 'replace' string occurs exactly once in the proposal text it amends).\n\n"
    "What holds: 30 references to 0x803ca2-0x803cb1, all at even offsets: 29 x move.w (abs).l,d0 followed by andi.w / "
    "andi.l with one bit, and the one address load at 0x15dd2. No reference to words 9 / 10, to an odd address, to the "
    "EEPROM form 0x01000198-0x010001a7, or off the mirror base; no other register is loaded with a block address. All "
    "15 indexed sites are movea.l #0x803c94,a0 + move.w (0,a0,dn.w*2) reads with word = bit / 16 and mask = 1 shifted left by "
    "bit mod 16. Dumps: 0xffff / 0 / 0 / 0x000b / 0xbb87 / 0 / 0, EEPROM = RAM. Two things back the nine protection "
    "channels beyond what the proposal cites: the input pointers are set by ROM code (vp44_engineProtectionSystemInit "
    "0x1873e), not only seen in the dump, and e2m 10B3 +0 EPSOAE lists 'C. LEV. = 0, C. TEMP. = 1, IMT = 2, OIL "
    "PRESS. = 3'. The 32 switch bits follow from the sampler's own byte masks and agree across five e2m blocks (106B, "
    "000E, 12A8, 12FC, 1234) and the J1939 descriptor table at ROM 0x20108.\n\n"
    "The amendments: (1) word 12 bit 9: 'zero under load' is CM848's code wording; CM550 has only VSSTEN 'lost while "
    "stopped' and no reader, so the name becomes vehicle_speed_sensor_lost_while_stopped_detection_enable (bit 8 may "
    "take the parallel 'lost_while_moving_detection' name; its present name is not wrong). (2) word 7: the direct test "
    "is the start-up fueling derate (EPFLSRTM = CM848 Fueling_Startup_Derate_Time), not an inhibit; and, separately, "
    "the type can be the unprefixed algorithm_enable_flags_7_t because no bit differs from CM848. (3) word 7 bit 14: "
    "the evaluator skips channel 3. (4) counts: EPOE* / EPOS* are in 18 files not 20 (word 9 bits 4-11), JCRWDXEN in "
    "13 not 14 (word 11 bit 4), the OBD fault handler mask 0x400 in 28 not 26 (word 12 bit 10), LSCIIHEN '- BIT 14' in 9 not 13 "
    "(word 12 bit 14).\n\n"
    "Corrections to the notes, outside the elements: EPWF / EPBS / EPFP / EPAA are in 27 files, not 33. The read at "
    "0x1cd96 is followed by sne d0, not a branch. AD25OD (the word 20 aside; the test at 0x20fd8 is real, andi.w "
    "#0x200) is in 5 other files, not six. The notes count 15 indexed sites but describe only the protection loops and cm550_FUN_00020890; the fifteenth, at 0x206e6, is "
    "cm550_FUN_000206a8, called five times from cm550_FUN_00021070 with switches 54 / 54 / 33 / 32 / 54, so it "
    "reaches words 15 / 16 only and nothing in this batch. PTBRODEN / PTCHODEN: 4 other ISB files keep the letter and "
    "18 ISB + 16 CHR_CC files carry the mask.\n\n"
    "For the orchestrator: word 13 bits 1 / 2 and W3's word 16 bits 0 / 2 share two field names; word 13's are the "
    "ones their own records back (DSCRRUUO / DSCRSEUO), so if one pair moves it should be W3's. Word 12 bits 7 / 8 / "
    "9 / 11 / 12 / 13 / 15 are named from the e2m alone (no reader in the dumped 256 KB). The CM848 rename is "
    "label-only in its .cpp.")
out = {"batch": "W2", "verdicts": verdicts, "overall": overall}
json.dump(out, open(os.path.join(HERE, "verdict_W2.json"), "w"), indent=1)
import collections  # noqa: E402

print(len(verdicts), "elements", dict(collections.Counter(v["verdict"] for v in verdicts)))
print("longest reason", max(len(v["reason"]) for v in verdicts), "| total json bytes",
      len(json.dumps(out)))
