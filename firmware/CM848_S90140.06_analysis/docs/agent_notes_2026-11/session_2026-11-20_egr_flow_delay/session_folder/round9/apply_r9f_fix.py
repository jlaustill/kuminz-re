"""Round 9 stage F post-fix (string edits; global_variables.csv / function_renames.csv take commas unquoted):
- 0x40b59e: governor_pressure_proportional_term, a label-only row (e2m 8BB6 +12 RE_Prop_Term; written by
  cm848_calculateGovernorPressureProportionalTerm), and its map row;
- the 8BB6 records go into the comments of the controller's other RAM rows; the wrong 8C34 note on 0x40b58c goes;
- stage D's bare old field names (condition_eval bit 6 ...) in 48RE comments and plates become the new field names;
- the P0720 monitor's plate names limp_home_flags_4 (it had the stale threshold_current);
- the state_flags / limp_home_flags_4 field comments: bit 5 of state_flags is an inference from its readers; bit 5 of
  limp_home_flags_4 is RE_OSS_Limp (set by the P0720 monitor).
usage: apply_r9f_fix.py <repo> <map.csv>"""
import csv
import io
import os
import re
import sys

repo, map_path = os.path.abspath(sys.argv[1]), sys.argv[2]
out = os.path.join(repo, "firmware", "CM848_S90140.06_analysis", "output")
FIELDS = [("condition_eval", "request_flags"), ("condition_flags_1", "mode_flags"), ("load_condition_flags", "state_flags"),
          ("overdrive_control_flags", "overdrive_flags"), ("condition_flags_3", "limp_home_flags_1"),
          ("condition_flags_2", "limp_home_flags_2"), ("fault_state_flags", "limp_home_flags_4"),
          ("action_flags", "low_range_boost_flags"), ("rate_limit_flags", "limp_home_and_temperature_flags"),
          ("status_flags", "wide_open_throttle_flags"), ("output_flags", "service_test_request_flags")]
CONTEXT = re.compile(r"RE_|48RE|governor_pressure|transmission_control_flags|transmission_shift_strategy_flags|"
                     r"converter_clutch|transmission_")
HISTORY = re.compile(r"(\bwas|\bwere|\(was|earlier note:?)\s*`?$")


def fix_bare(text):
    changes = []
    for old, new in FIELDS:
        pat = re.compile(r"(?<![A-Za-z0-9_.])" + re.escape(old) + r"(?![A-Za-z0-9_])")

        def sub(m):
            before = text[max(0, m.start() - 16):m.start()]
            if HISTORY.search(before):
                return m.group(0)
            changes.append((old, new))
            return new
        text = pat.sub(sub, text)
    for old, new in [("flags[0]", "anti_hunt_flags"), ("flags[2]", "actuator_test_flags")]:
        if old in text and ("transmission_shift_strategy_flags" in text or "anti-hunt" in text):
            text = text.replace(old, new)
            changes.append((old, new))
    return text, changes


p = os.path.join(out, "global_variables.csv")
lines = open(p).read().split("\n")
RECORD = {
    "0x0040b58e": "e2m 8BB6 +02 RE_Governor_Delta ('RE governor pressure control error term (RE_Governor_Set-RE_Governor_Pressure)'; signed dword): ",
    "0x0040b592": "e2m 8BB6 +06 RE_Governor_Pressure ('RE governor pressure control adjusted for gage and temperature'): ",
    "0x0040b594": "e2m 8BB6 +08 RE_Int_Term ('RE governor pressure control integral term'): ",
    "0x0040b59a": "e2m 8BB6 +0E RE_PID_Error_Sum ('RE governor pressure control error sum'): ",
    "0x0040b5a0": "e2m 8BB6 +14 RE_Trans_Press_Offset ('RE governor pressure sensor offset determined during cal period'): ",
    "0x0040b5a2": "e2m 8BB6 +16 RE_VFS_PWM_On_Time ('RE governor pressure control duty cycle before inversion'): ",
    "0x0040b5a4": "e2m 8BB6 +18 Transmission_VFS_PWM_Driver_Inhibit_Protection ('Indicates off cycle for Transmission VFS PWM "
                  "driver when fault exists'): ",
}
seen, changed = set(), 0
for i, l in enumerate(lines):
    if not re.match(r"^0x[0-9a-f]{8},", l):
        continue
    addr, name, typ, comment = (l.split(",", 3) + [""])[:4]
    a = addr.lower()
    new_comment = comment
    if a in RECORD and not comment.startswith("e2m 8BB6"):
        new_comment = RECORD[a] + new_comment
        seen.add(a)
    if a == "0x0040b58c":
        new_comment = re.sub(r" \| earlier note: .*$", "", new_comment)
        seen.add(a)
    if CONTEXT.search(name + " " + new_comment):
        new_comment, ch = fix_bare(new_comment)
        if ch:
            print(f"gv {a} {name}: {sorted(set(ch))}")
    if new_comment != comment:
        assert '"' not in new_comment or '"' in comment, a
        lines[i] = ",".join([addr, name, typ, new_comment])
        changed += 1
assert seen == set(RECORD) | {"0x0040b58c"}, sorted(set(RECORD) | {"0x0040b58c"} - seen)
assert not any(l.startswith("0x0040b59e,") for l in lines)
row = ",".join(["0x0040b59e", "governor_pressure_proportional_term", "",
                "e2m 8BB6 +12 RE_Prop_Term ('RE governor pressure control proportional term'): "
                "cm848_calculateGovernorPressureProportionalTerm writes it and adds it to governor_pressure_controller_output"])
k = next(i for i, l in enumerate(lines) if re.match(r"^0x[0-9a-f]{8},", l) and int(l[:10], 16) > 0x40b59e)
lines.insert(k, row)
open(p, "w").write("\n".join(lines))
with open(map_path, "a") as f:
    f.write("0x0040b59e,governor_pressure_proportional_term,DAT_0040b59e,global\n")
print("global rows changed:", changed)
p = os.path.join(out, "function_renames.csv")
lines = open(p).read().split("\n")
changed = 0
for i, l in enumerate(lines):
    if not re.match(r"^0x[0-9a-f]{8},", l) or l.count(",") < 2:
        continue
    a, name, plate = l.split(",", 2)
    new_plate = plate
    if a.lower() == "0x0003dd98":
        assert "transmission_control_flags_t.threshold_current" in new_plate
        new_plate = new_plate.replace("transmission_control_flags_t.threshold_current",
                                      "transmission_control_flags_t.limp_home_flags_4 (e2m RE_OSS_Limp)")
    if CONTEXT.search(name + " " + new_plate):
        new_plate, ch = fix_bare(new_plate)
        if ch:
            print(f"fn {a} {name}: {sorted(set(ch))}")
    if new_plate != plate:
        lines[i] = f"{a},{name},{new_plate}"
        changed += 1
open(p, "w").write("\n".join(lines))
print("plates changed:", changed)
p = os.path.join(out, "structure_definitions.csv")
lines = open(p).read().split("\n")
k = 0
for i, l in enumerate(lines):
    if l.startswith("transmission_control_flags_t,0x0040b0e8,state_flags,") or \
       l.startswith("transmission_control_flags_t,0x0040b0e8,limp_home_flags_4,"):
        row = next(csv.reader([l]))
        if row[2] == "state_flags":
            a0 = "bit 5 = service lockup (with the lockup / unlock service output speed limits)"
            assert a0 in row[5]
            row[5] = row[5].replace(a0, "bit 5 is read with the lockup / unlock service output speed limits, so it is "
                                        "probably RE_Service_Lockup_Switch (no setter found in the decompile)")
        else:
            row[5] = row[5] + "; bit 5 (0x20) = RE_OSS_Limp, set and cleared by the P0720 monitor " \
                              "(cm848_monitorTransmissionOutputSpeedSensor)"
        s = io.StringIO()
        csv.writer(s, lineterminator="").writerow(row)
        lines[i] = s.getvalue()
        k += 1
assert k == 2
open(p, "w").write("\n".join(lines))
print("struct comments fixed")
