"""Round 92 stage A: the skeptics' AMENDED verdicts (all comment text; no name, type or bit changed) as exact values
for apply_r92a.py -> amend_r92a.json. Each replacement is asserted against the proposal's text.
Keys: "<word>|" for a word (row_comment / differences), "<word>|<bit>" for a field comment.
usage: make_amend_r92a.py <dir with batch_*.json>"""
import json
import os
import sys

d = sys.argv[1]
batches = {b: json.load(open(os.path.join(d, f"batch_{b}.json")))["proposal"] for b in ("W1", "W2", "W3", "W4")
           if os.path.exists(os.path.join(d, f"batch_{b}.json"))}


def word(b, n):
    return next(w for w in batches[b]["words"] if w["word"] == n)


def field(b, n, bit):
    return next(f for f in word(b, n)["fields"] if f["bit"] == bit).get("comment", "")


def rep(text, old, new):
    assert text.count(old) == 1, (old[:60], text.count(old))
    return text.replace(old, new)


out = {}
# ---- W1
out["-1|"] = {"row_comment": rep(word("W1", -1)["row_comment"], "entry at 0x80e8 holds", "entry at 0x80ea holds")}
out["2|"] = {"differences": "Only bit 3 differs (CM550 ISRPEN S mask 0x8; CM848 reserved_bit_3). CM848 reads bit 6 "
             "(cm848_updateEngineRetarderAllowedState) and has no reader for bits 7 and 8; CM550 reads bits 7 (0x1fdc6) and "
             "8 (0x1fd6c) and has no reader for bits 3, 6 and 15."}
out["2|7"] = {"comment": rep(field("W1", 2, 7), "andi.l 0x80 at 0x1fdc6", "andi.w 0x80 at 0x1fdc6")}
out["2|11"] = {"comment": rep(field("W1", 2, 11), "andi.l 0x800 at 0x22080", "andi.w 0x800 at 0x22080")}
out["6|"] = {"row_comment": rep(word("W1", 6)["row_comment"],
                                "0x200 ISIMEN idle shutdown intake manifold temperature override (0 = the ambient air temperature)",
                                "0x200 ISIMEN idle shutdown intake manifold temperature override (e2m: 1 - IMT OVERRIDE "
                                "SHUTDOWN PROCESS; 0 - AMBIENT TEMP = DO..., cut in every e2m; what 0 selects is not proved)")}
# ---- W3
out["15|"] = {"row_comment": rep(word("W3", 15)["row_comment"], "0x8 no record",
                                 "0x8 no masked record (lamp 4 or lamp 7 - the e2m numbers it both ways)")}
out["16|"] = {"row_comment": rep(word("W3", 16)["row_comment"],
                                 "Set: mc68k_sampleAndDebounceDiscreteInputs takes that status bit from the override values "
                                 "0x80bcde / 0x80bcdf instead of the debounced switch inputs",
                                 "Set (bits 0 / 2 / 4 / 8 / 10 / 12, the six the sampler tests): "
                                 "mc68k_sampleAndDebounceDiscreteInputs ORs that bit of the override values 0x80bcde / 0x80bcdf "
                                 "into the status byte (or.b; it never clears the bit there) instead of copying the debounced "
                                 "switch input")}
for bit in (0, 2, 4, 8, 10, 12):
    c = rep(field("W3", 16, bit), " comes from ", " is ORed in from ")
    c = rep(c, " instead of switch input", " (set only, not cleared) instead of switch input")
    out[f"16|{bit}"] = {"comment": c}
out["16|6"] = {"comment": field("W3", 16, 6) + " In the dumped ROM the override value bit 54 (0x80bcde bit 6) has no reader, and "
               "cm550_FUN_000206a8(0x36, 1 / 4 / 2) also stores output image bits 1 / 4 / 2 (the stop / engine protection / water "
               "in fuel lamp commands) into it after the J1939 entries. The status bit 54 (0x80bcd4 bit 6) is no auxiliary "
               "shutdown status: mc68k_sampleAndDebounceDiscreteInputs sets it on the power take-off on switch's rising edge at "
               "zero road speed while word 28 bit 4 (e2m ISTAEN) is set and clears it on set / resume, and "
               "j1939HandlePgn65265CruiseVehicleSpeed sends it as the CCVS1 parking brake switch (byte 1 0xF7 instead of 0xF3)."}
# ---- W4
c = rep(word("W4", 26)["row_comment"], "calibration_feature_enable_flags_word_0", "algorithm_enable_flags_0_cal")
out["26|"] = {"row_comment": rep(c, "(the bit names below are for this comment only)",
                                 "(plain word: the bit list above is documentation, no field is typed)")}
out["27|0"] = {"comment": rep(field("W4", 27, 0), "(mask 1 at +38 in 21 other ISB e2m files)",
                              "(an S record with mask 1 at +38 in 11 other e2m files; an N record with no bit in 10 more)")}
out["32|9"] = {"comment": rep(field("W4", 32, 9), "'(BIT X OF WORD Y) LSG USE OF LSG_NO_LOAD_FUEL_ENABLE'",
                              "'(BIT X OF WORD Y) LSG USE OF LSG_NO_LOAD_FUEL_ENA[BLE]'")}
out["32|13"] = {"comment": rep(field("W4", 32, 13), "one later file repeats the record as ADO2DBEN",
                               "the sibling file 64t4 carries the same record under the mnemonic ADO2DBEN")}
out["32|15"] = {"comment": rep(field("W4", 32, 15),
                               "adds the coolant temperature x engine speed table to the 100 % throttle fueling at the high speed "
                               "governor droop speed (full_fueling_value_at_hsg_bef_droop_speed_0_100)",
                               "adds the coolant temperature x engine speed table to all three full fueling values it computes: "
                               "fueling_value_at_100_throttle_0_100, full_fueling_value_at_hsg_bef_droop_speed_0_100 and "
                               "fueling_provided_if_engine_were_using_low_hp_curve_0_100 (the block runs only while word 18 bit 9 "
                               "is clear)")}
# ---- W1 word 3 bit 8: CM848's field takes the same name in this change (the skeptic's note on the bit 8 rename)
out["3|8"] = {"comment": rep(field("W1", 3, 8),
                             "CM848 reads this bit below top gear as road_speed_governor_without_droops_below_top_gear",
                             "CM848 reads this bit below top gear (no road speed governor droops there) and its field takes "
                             "the same name in this change")}
# ---- W2 (14 amendments; the eight on word 9's bits are documentation of a plain word and have no row to change).
# The skeptic's optional judgment call (the unprefixed type name algorithm_enable_flags_7_t) is declined: every word
# whose CM848 counterpart has no type keeps the cm550_ prefix (7, 8, 14, 16, 33).
out["7|"] = {"row_comment": rep(word("W2", 7)["row_comment"], "for the oil pressure start-up inhibit",
                                "for the oil pressure start-up fueling derate (e2m 10B4 +2 EPFLSRTM - CM848 label "
                                "Fueling_Startup_Derate_Time)")}
out["7|14"] = {"comment": rep(field("W2", 7, 14), "and by the restart checks",
                              "and by the restart check cm550_protectionState1DiagnosticValidator "
                              "(cm550_diagnosticProtectionEvaluator skips channel 3)")}
out["11|4"] = {"comment": rep(field("W2", 11, 4), "(S mask 0x10 in 14 other ISB e2m files)",
                              "(S mask 0x10 in 13 other ISB e2m files)")}
out["12|9"] = {"name": "vehicle_speed_sensor_lost_while_stopped_detection_enable",
               "comment": rep(field("W2", 12, 9),
                              "CM848 field name (named there after its detector: the sensor reads 0 while the engine is under load)",
                              "the same record as CM848 vehicle_speed_sensor_zero_under_load_enable (CM848 named that field "
                              "after its own detector - nothing proves that detector for J90350.00)")}
out["12|10"] = {"comment": rep(field("W2", 12, 10), "(mask 0x400 here in 26 other e2m files; CM848 obd_fault_handler_enable)",
                               "(S mask 0x400 here in 28 other e2m files - the 23 CHR files and 5 ISB files - and an N record "
                               "with no bit in 4 more ISB files; CM848 obd_fault_handler_enable)")}
out["12|14"] = {"comment": rep(field("W2", 12, 14), "13 other e2m files", "9 other e2m files")}
diff = rep(word("W2", 12)["differences_from_cm848"], "field names are reused.",
           "field names are reused for bits 0 / 2-8 / 11-13; bit 9 is the same record but keeps the e2m wording because the "
           "CM848 name describes the CM848 detector.")
diff = rep(diff, " but CM848 left it reserved_bit_1: a rename is proposed.",
           ": CM848's reserved_bit_1 takes the same name in this change.")
out["12|"] = {"differences": rep(diff, "Three bits differ", "Three bits differ in meaning (10 / 14 / 15) and bit 9 in name only")}
json.dump(out, open(os.path.join(d, "amend_r92a.json"), "w"), indent=1)
print(len(out), "amendments written")
