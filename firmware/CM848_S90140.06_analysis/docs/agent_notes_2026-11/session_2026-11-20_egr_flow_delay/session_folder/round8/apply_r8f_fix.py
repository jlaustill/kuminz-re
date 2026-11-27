"""Round 8 stage F post-fix, after apply_hand_worklist.py:
- the rows / plates stage E had named get no 'earlier note' (it carried stage E's misreading); their '(was ...)' names
  both earlier names;
- the cm848_calculateOutputShaftAcceleration plate gets its two methods;
- the new row 0x408370 (e2m 8C18 +7C RE_Ovr_Heat_Lockup_Delay_4_3_Max) and its map row;
- transmission_lockup_timers_t.low_range_hold_timer: Status needs_review -> verified (stage B proved it).
usage: apply_r8f_fix.py <repo> <map_r8e.csv> <map_r8f.csv>"""
import csv
import io
import os
import re
import sys

repo, map_e, map_f = os.path.abspath(sys.argv[1]), sys.argv[2], sys.argv[3]
out = os.path.join(repo, "firmware", "CM848_S90140.06_analysis", "output")
original = {r["address"].lower(): r["old_label"] for r in csv.DictReader(open(map_e)) if r.get("address")}
STAGE_E_ROWS = {"0x0040b14c", "0x0040838a", "0x003fb1cc", "0x0040837c", "0x0040837e", "0x00408380", "0x00408382",
                "0x00408384", "0x00408386"}
STRIP_ONLY = {"0x0040b0fe"}


def text_of(row):
    s = io.StringIO()
    csv.writer(s, lineterminator="").writerow(row)
    return s.getvalue()


# globals
p = os.path.join(out, "global_variables.csv")
lines = open(p).read().split("\n")
done = 0
# global_variables.csv is split(",", 4) by the importer: the comment takes commas unquoted, so never use csv here
UNQUOTE = {"0x003fd900", "0x003feb50"}
fixed_other = 0
for i, l in enumerate(lines):
    a = l[:10].lower()
    if a in STAGE_E_ROWS or a in STRIP_ONLY:
        addr, name, typ, comment = l.split(",", 3)
        comment = re.sub(r" \| earlier note: .*$", "", comment)
        if a in STAGE_E_ROWS:
            m = re.search(r" \(was ([A-Za-z0-9_]+)\)$", comment)
            assert m, (a, comment[-80:])
            comment = comment[:m.start()] + f" (was {m.group(1)} in stage E, before that {original[a]})"
        assert '"' not in comment, a
        lines[i] = ",".join([addr, name, typ, comment])
        done += 1
    elif a in UNQUOTE:
        addr, name, typ, comment = l.split(",", 3)
        assert comment.startswith('"') and comment.endswith('"'), a
        comment = comment[1:-1].replace('""', '"')
        if a == "0x003fd900":
            t = "so the address is from the code. lhz"
            assert comment.endswith(t)
            comment = comment[: -len(t)] + "so the address is from the code: cm848_updateDrivetrainRatio loads it with lhz"
        lines[i] = ",".join([addr, name, typ, comment])
        fixed_other += 1
    elif a == "0x0040786a":
        t = "Typed byte, read as words"
        assert l.count(t) == 1
        lines[i] = l.replace(t, "word[6] (round 8 stage C): index 6 would be the next table's length header")
        fixed_other += 1
assert done == len(STAGE_E_ROWS) + len(STRIP_ONLY), done
assert fixed_other == 3, fixed_other
assert not any(l.startswith("0x00408370,") for l in lines)
new = ["0x00408370", "transmission_overheat_lockup_delay_4_3_time", "word",
       "e2m 8C18 +7C RE_Ovr_Heat_Lockup_Delay_4_3_Max ('Timer to delay lockup after 4-3 downshift in overheat mode'): 100 "
       "= 1 s; cm848_processOverdriveSwitchAndShift loads transmission_lockup_timers.lockup_delay_4_3_timer with it at "
       "a 4-3 downshift, then the normal value unless transmission_overheat_protection_active_flag is set"]
idx = next(i for i, l in enumerate(lines) if re.match(r"^0x[0-9a-f]{8},", l) and int(l[:10], 16) > 0x408370)
lines.insert(idx, ",".join(new))
open(p, "w").write("\n".join(lines))
print("globals: fixed", done, "+", fixed_other, "comment fixes + 1 new row")
with open(map_f, "a") as f:
    f.write("0x00408370,transmission_overheat_lockup_delay_4_3_time,DAT_00408370,global\n")

# function plates
p = os.path.join(out, "function_renames.csv")
lines = open(p).read().split("\n")
PLATE_3491C = ("The output shaft acceleration, by e2m 8C18 +70 RE_OSS_Accel_Method (transmission_output_shaft_acceleration_method, "
               "1 in this calibration). Method 0: every transmission_output_shaft_acceleration_sample_period passes (RE_Acc_Loop_Ctr_Max, "
               "27) the output speed change since the last sample, clamped to 16 bits, goes straight into "
               "transmission_output_shaft_acceleration. Method 1: a 27-word ring of the output speed at 0x3fb192 (the "
               "length is fixed in the code); the change over the last 27 passes goes into "
               "transmission_output_shaft_acceleration_unfiltered (8C17 +48 RE_OSS_Accel_Unfiltered) and its signed "
               "first-order filter (transmission_output_shaft_acceleration_filter) into transmission_output_shaft_acceleration "
               "(RE_OSS_Accel) (was cm848_filterProtectionLoadValue)")
fixed = 0
for i, l in enumerate(lines):
    head = l[:10].lower()
    if head in ("0x00034f4c", "0x00035154"):
        a, name, plate = l.split(",", 2)
        plate = re.sub(r" \| earlier note: .*$", "", plate)
        plate = re.sub(r" \(was cm848_(monitorConverterClutchEngagement|selectGovernorPressureHighGear)\)$", "", plate)
        lines[i] = f"{a},{name},{plate}"
        fixed += 1
    elif head == "0x0003491c":
        a, name, _ = l.split(",", 2)
        assert name == "cm848_calculateOutputShaftAcceleration"
        lines[i] = f"{a},{name},{PLATE_3491C}"
        fixed += 1
assert fixed == 3, fixed
open(p, "w").write("\n".join(lines))
print("plates: fixed", fixed)

# struct status
p = os.path.join(out, "structure_definitions.csv")
lines = open(p).read().split("\n")
k = 0
for i, l in enumerate(lines):
    if l.startswith("transmission_lockup_timers_t,0x0040b11c,low_range_hold_timer,") and l.endswith(",needs_review"):
        lines[i] = l[: -len("needs_review")] + "verified"
        k += 1
assert k == 1, k
open(p, "w").write("\n".join(lines))
print("struct status fixed")
