"""Round 68 label proof: every function body of the old and new .cpp is compared after the old one gets the round's
renames as exact string replacements (prove_r67.sh's \\b-bounded regexes cannot match labels that end in ']'),
casts to the plain integer types are dropped, and comments and whitespace are ignored. Prints each differing function.
usage: prove_r68.py <old.cpp> <new.cpp>"""
import re
import sys

PAIRS = [  # longest first
    ("eeprom_shadow_header.calibration_block1._4_2_", "intake_air_heater_saved_values_cal.inhibit_postheat_start_count"),
    ("eeprom_shadow_header.calibration_block1[0]", "fuel_level_saved_values_cal.in_range_filtered_percent"),
    ("eeprom_shadow_header.calibration_block1[1]", "fuel_level_saved_values_cal.last_valid_percent"),
    ("eeprom_shadow_header.calibration_block1[2]", "fuel_level_saved_values_cal.percent_tank_full_average"),
    ("eeprom_shadow_header.serial_reflash_unlock_request", "boot_serial_reflash_unlock_request"),
    ("eeprom_shadow_header.eeprom_status_flags", "intake_air_heater_saved_values_cal.redundant_preheat_request"),
    ("eeprom_shadow_header.serial_number", "boot_eeprom_status_block"),
    ("eeprom_shadow_header.cal_word2", "engine_off_time_saved_values_cal.previous_trip_value"),
    ("eeprom_shadow_header.cal_word3", "engine_off_time_saved_values_cal.unchanged_trip_count"),
]
CAST = re.compile(r"\((short|ushort|int|uint|word|dword|undefined1|undefined2|undefined4|char|uchar|byte|longlong|"
                  r"ulonglong)\)")


def bodies(path, rename):
    t = open(path, errors="replace").read()
    parts = re.split(r"^// Function: (\S+) @[^\n]*\n", t, flags=re.M)
    out = {}
    for i in range(1, len(parts), 2):
        b = re.sub(r"/\*.*?\*/", "", parts[i + 1], flags=re.S)
        if rename:
            for old, new in PAIRS:
                b = b.replace(old, new)
        b = CAST.sub("", b).replace("'\\0'", "0").replace("'\\x01'", "1")
        out[parts[i]] = re.sub(r"\s+", "", b)
    return out


old_b, new_b = bodies(sys.argv[1], True), bodies(sys.argv[2], False)
diff = [f for f in old_b if old_b[f] != new_b.get(f)]
print(f"functions {len(old_b)}; differing after the renames: {len(diff)}")
for f in diff:
    print(" ", f)
