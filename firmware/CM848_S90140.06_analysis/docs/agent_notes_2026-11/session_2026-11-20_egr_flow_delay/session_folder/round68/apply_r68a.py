"""Round 68 stage A: the application's EEPROM mirror words at 0x3fee18-0x3fee23, typed from e2m. Idempotent (each
change keys on its row and skips when the new text is there).

eeprom_header_t (the boot kernel's 'shadow header' at 0x3fee08) ran to 0x3fee29 over words that the application
reads as its own EEPROM mirror (RAM 0x3fd482 + EEPROM offset): e2m 8A24 (EEPROM 0x1996), 8A36 (0x199a) and 8C36
(0x199e). Fourteen application functions (13 in the first version of this note) rendered them as eeprom_shadow_header.calibration_block1[N] / cal_word2 /
cal_word3 / eeprom_status_flags; three boot functions use 0x3fee1e-0x3fee22 for their copies of EEPROM 0x50-0x54.
- eeprom_header_t ends at 0x3fee17 (config_word).
- fuel_level_saved_values_t @ 0x3fee18 (e2m 8A24: 4 bytes - the last one e2m's own 'space filler to prevent
  compiler complaints', so the source has a struct), intake_air_heater_saved_values_t @ 0x3fee1c (8A36: 2 words),
  engine_off_time_saved_values_t @ 0x3fee20 (8C36: 2 words). Widths from the asm: lbz at 0x3fee18 / 19 / 1a, lhz /
  sth at 0x3fee1c / 1e / 20 / 22 (one sth at 0x3fee1c that the byte[6] field split in two).
- 0x3fee24 / 0x3fee26 (boot only) become boot_serial_reflash_unlock_request / boot_eeprom_status_block (the old
  'serial_number' is EEPROM 0x0c; the serial number is EEPROM 0x8e).
usage: apply_r68a.py <repo> <map.csv>"""
import os
import sys

repo, map_path = os.path.abspath(sys.argv[1]), sys.argv[2]
O = os.path.join(repo, "firmware/CM848_S90140.06_analysis/output")
R = "PR #53 round 68"
R67 = "PR #53 round 67"


def load(name):
    return open(os.path.join(O, name)).read().split("\n")


def save(name, lines):
    open(os.path.join(O, name), "w").write("\n".join(lines))


def one(lines, pred, what):
    idx = [i for i, l in enumerate(lines) if pred(l)]
    assert len(idx) == 1, (what, len(idx))
    return idx[0]


def text_replace(name, pairs):
    """Replace old mention text on lines that are not this round's own (so history notes stay)."""
    lines = load(name)
    for i, l in enumerate(lines):
        if R in l:
            continue
        for old, new in pairs:
            l = l.replace(old, new)
        lines[i] = l
    save(name, lines)


FUEL, HEATER, OFF = "fuel_level_saved_values_cal", "intake_air_heater_saved_values_cal", "engine_off_time_saved_values_cal"
MENTIONS = [  # the longer forms first
    ("eeprom_shadow_header.calibration_block1[0]", f"{FUEL}.in_range_filtered_percent"),
    ("eeprom_shadow_header.calibration_block1[1]", f"{FUEL}.last_valid_percent"),
    ("eeprom_shadow_header.calibration_block1[2]", f"{FUEL}.percent_tank_full_average"),
    ("it also sets bytes 4-5 of eeprom_shadow_header.calibration_block1 to 0 / 0x19",
     f"it also sets {HEATER}.inhibit_postheat_start_count to 0x19 (25 engine starts)"),
]

# ---- structure_definitions.csv -----------------------------------------------------------------------------------------
T = "structure_definitions.csv"
lines = load(T)
DROP = ["calibration_block1", "eeprom_status_flags", "cal_word2", "cal_word3", "serial_reflash_unlock_request",
        "serial_number"]
old_unlock = [l for l in lines if l.startswith("eeprom_header_t,0x003fee08,serial_reflash_unlock_request,")]
if old_unlock:
    unlock_comment = old_unlock[0].split(",", 5)[5].rsplit(",,", 1)[0]
    if unlock_comment.startswith('"') and unlock_comment.endswith('"'):
        unlock_comment = unlock_comment[1:-1].replace('""', '"')
    open(os.path.join(os.path.dirname(map_path), "unlock_comment.txt"), "w").write(unlock_comment)
else:
    unlock_comment = open(os.path.join(os.path.dirname(map_path), "unlock_comment.txt")).read()
NEW_TYPES = [
    f"# fuel_level_saved_values_t - e2m 8A24 (EEPROM 0x1996-0x1999 = the application's mirror 0x3fee18): the fuel level "
    f"bytes kept over a power down ({R}). The boot kernel time-shares 0x3fee18-0x3fee1d for its copy of EEPROM 0x4a "
    "(eeprom_calibration_block - cm848_loadCalibrationFromEeprom) and reads none of it back by name",
    "fuel_level_saved_values_t,0x003fee18,in_range_filtered_percent,byte,1,e2m 8A24 +0 Fuel_Lvl_In_Range_Filtered [%] "
    "'Filtered Fuel Level Goods Readings' (1/2.55 % per count) - seeds fuel_level_fast_filter at power up,,verified",
    "fuel_level_saved_values_t,0x003fee18,last_valid_percent,byte,1,e2m 8A24 +1 Fuel_Lvl_Last_Valid_Percent [%] 'Last "
    "Valid Fuel_Lvl_Percent_Tank_Full' - seeds fuel_level_slow_filter_reference,,verified",
    "fuel_level_saved_values_t,0x003fee18,percent_tank_full_average,byte,1,e2m 8A24 +2 Fuel_Lvl_Percent_Tank_Full_Avg [%] "
    "'Averaged percent tank full sent on bus for fuel level gauge control' - PCI TX[13] header 0xA4 sends it / seeds "
    "fuel_level_slow_filter,,verified",
    "fuel_level_saved_values_t,0x003fee18,dummy_byte_1,byte,1,e2m 8A24 +3 Fuel_Lvl_Dummy_Byte_1 'Dummy value used as "
    "space filler to prevent compiler complaints',,verified",
    f"# intake_air_heater_saved_values_t - e2m 8A36 (EEPROM 0x199a-0x199d = the mirror 0x3fee1c) ({R})",
    "intake_air_heater_saved_values_t,0x003fee1c,inhibit_postheat_start_count,word,2,e2m 8A36 +0 "
    "IAH_Inhibit_Postheat_Counter 'IAH: Inhibits postheat phase for this number of engine starts' - "
    "cm848_runEndOfLineTestStartStep sets it to 0x19,,verified",
    "intake_air_heater_saved_values_t,0x003fee1c,redundant_preheat_request,word,2,e2m 8A36 +2 IAH_Redundant_Preheat_Req "
    "'If preheat w/o cranking - this param=1; saved at powerdown' | boot kernel (time-shared): its copy of EEPROM 0x50 "
    "serial_reflash_status_flags_cal (cm848_beginSerialReflash / mpc555_verifyDownloadedCalibration change bits 1 and "
    "3),,verified",
    f"# engine_off_time_saved_values_t - e2m 8C36 (EEPROM 0x199e-0x19a1 = the mirror 0x3fee20): the PCI engine-off time "
    f"check of cm848_latchAndCheckEngineOffTime ({R})",
    "engine_off_time_saved_values_t,0x003fee20,previous_trip_value,word,2,e2m 8C36 +0 Chry_Dat42_Previous [HEX] "
    "'Chry_Dat42 in previous trip' - pci_receive_message_14_engine_off_time as the last check saved it | boot kernel "
    "(time-shared): its copy of EEPROM 0x52 serial_reflash_success_count_cal,,verified",
    "engine_off_time_saved_values_t,0x003fee20,unchanged_trip_count,word,2,e2m 8C36 +2 Chry_Dat42_Stuck_Times 'Number of "
    "trips in which Chry_Dat42 message stucks' - counted while the time moved less than engine_off_time_unchanged_delta "
    "(the fault bit sets at engine_off_time_unchanged_count_limit) | boot kernel (time-shared): its copy of EEPROM 0x54 "
    "serial_reflash_attempt_count_cal,,verified",
]
if NEW_TYPES[1] not in lines:
    keep = [l for l in lines if not any(l.startswith(f"eeprom_header_t,0x003fee08,{f},") for f in DROP)]
    assert len(lines) - len(keep) == 6
    lines = keep
    i = one(lines, lambda l: l == "# Total size: 32 bytes (0x003fee08-0x003fee27)", "header size")
    lines[i] = (f"# Total size: 16 bytes (0x003fee08-0x003fee17) - the words after it are the application's EEPROM "
                f"mirror ({R}: was 32 bytes to 0x3fee27 while the fields ran to 0x3fee29)")
    j = one(lines, lambda l: l.startswith("eeprom_header_t,0x003fee08,config_word,"), "config_word")
    lines[j + 1:j + 1] = NEW_TYPES
    save(T, lines)
text_replace(T, MENTIONS)

# ---- global_variables.csv ----------------------------------------------------------------------------------------------
G = "global_variables.csv"
ROWS = {
    "0x003fee18": f"0x003fee18,{FUEL},fuel_level_saved_values_t,e2m 8A24 Fuel_Lvl_*: the fuel level bytes kept over a "
                  "power down - EEPROM 0x1996 in the application's mirror (was eeprom_shadow_header.calibration_block1[0] - "
                  f"the boot kernel's struct ran over it; {R})",
    "0x003fee19": f"0x003fee19,{FUEL}.last_valid_percent,,(was eeprom_shadow_header.calibration_block1[1]; {R})",
    "0x003fee1a": f"0x003fee1a,{FUEL}.percent_tank_full_average,,(was eeprom_shadow_header.calibration_block1[2]; {R})",
    "0x003fee1c": f"0x003fee1c,{HEATER},intake_air_heater_saved_values_t,e2m 8A36 IAH_*: EEPROM 0x199a in the "
                  "application's mirror (was eeprom_shadow_header.calibration_block1[4] / [5] - the end-of-line step's one "
                  f"sth rendered as two byte stores; {R})",
    "0x003fee1e": f"0x003fee1e,{HEATER}.redundant_preheat_request,,(was eeprom_shadow_header.eeprom_status_flags; {R})",
    "0x003fee20": f"0x003fee20,{OFF},engine_off_time_saved_values_t,e2m 8C36 Chry_Dat42_*: EEPROM 0x199e in the "
                  f"application's mirror (was eeprom_shadow_header.cal_word2; {R})",
    "0x003fee22": f"0x003fee22,{OFF}.unchanged_trip_count,,(was eeprom_shadow_header.cal_word3; {R})",
    "0x003fee24": f"0x003fee24,boot_serial_reflash_unlock_request,word,{unlock_comment} (was "
                  f"eeprom_shadow_header.serial_reflash_unlock_request; {R})",
    "0x003fee26": "0x003fee26,boot_eeprom_status_block,dword,Boot kernel: cm848_loadCalibrationFromEeprom's copy of EEPROM "
                  "0x0c-0x0f (eeprom_status_block) - no reader found (was eeprom_shadow_header.serial_number 'ECU serial "
                  f"number from EEPROM' - the serial number is EEPROM 0x8e eeprom_serial_number; {R})",
}
lines = load(G)
for addr, new in ROWS.items():
    i = one(lines, lambda l, a=addr: l.startswith(a + ","), addr)
    lines[i] = new
if "0x003fee1d,eeprom_shadow_header.calibration_block1[5],," in lines:
    lines.remove("0x003fee1d,eeprom_shadow_header.calibration_block1[5],,")
i = one(lines, lambda l: l.startswith("0x003fee08,eeprom_shadow_header,eeprom_header_t,"), "header row")
if R not in lines[i]:
    lines[i] = ("0x003fee08,eeprom_shadow_header,eeprom_header_t,RAM shadow of EEPROM header loaded at boot (the boot "
                "kernel's) - 0x3fee08-0x3fee17; the words after it are the application's EEPROM mirror "
                f"(fuel_level_saved_values_cal and on) ({R}: the struct ran to 0x3fee29)")
save(G, lines)
text_replace(G, MENTIONS)

# ---- function_renames.csv ----------------------------------------------------------------------------------------------
F = "function_renames.csv"
text_replace(F, MENTIONS)
lines = load(F)
NOTES = {
    "0x00000428": (f" (was mpc555_loadEepromCalibration; {R67})",
                   f" Here {HEATER}.redundant_preheat_request and {OFF}.previous_trip_value are the boot kernel's copies of "
                   f"EEPROM 0x50 and 0x52 (it time-shares the application's EEPROM mirror; {R})"),
    "0x00003710": (f" (was cm848_beginEepromCalibrationWrite; {R67})",
                   f" Here {HEATER}.redundant_preheat_request and {OFF}.unchanged_trip_count are the boot kernel's copies "
                   f"of EEPROM 0x50 and 0x54 (it time-shares the application's EEPROM mirror; {R})"),
}
for addr, (anchor, note) in NOTES.items():
    i = one(lines, lambda l, a=addr: l.startswith(a + ","), addr)
    if note not in lines[i]:
        assert lines[i].count(anchor) == 1, (addr, anchor)
        lines[i] = lines[i].replace(anchor, note + anchor)
i = one(lines, lambda l: l.startswith("0x00000ec0,cm848_loadCalibrationFromEeprom"), "loader")
if lines[i] == "0x00000ec0,cm848_loadCalibrationFromEeprom":
    lines[i] = ("0x00000ec0,cm848_loadCalibrationFromEeprom,Boot kernel: mpc555_eepromValidationCycle and "
                "mpc555_keyOnStateMachine / then copies EEPROM 0x4a (6 bytes) / 0x50 / 0x52 / 0x54 / 0x0c (4) / 0x56 into "
                "RAM 0x3fee18 / 0x3fee1e / 0x3fee20 / 0x3fee22 / 0x3fee26 / 0x3fee24 - from 0x3fee18 to 0x3fee23 the "
                f"application's EEPROM mirror words take its own names ({R})")
save(F, lines)

with open(map_path, "w") as fh:
    fh.write("address,name,old_label,kind,dims\n"
             f"0x003fee1e,{HEATER}.redundant_preheat_request,eeprom_shadow_header.eeprom_status_flags,global,1\n"
             f"0x003fee20,{OFF}.previous_trip_value,eeprom_shadow_header.cal_word2,global,1\n"
             f"0x003fee22,{OFF}.unchanged_trip_count,eeprom_shadow_header.cal_word3,global,1\n"
             "0x003fee24,boot_serial_reflash_unlock_request,eeprom_shadow_header.serial_reflash_unlock_request,global,1\n"
             "0x003fee26,boot_eeprom_status_block,eeprom_shadow_header.serial_number,global,1\n")
print("round 68 stage A applied")
