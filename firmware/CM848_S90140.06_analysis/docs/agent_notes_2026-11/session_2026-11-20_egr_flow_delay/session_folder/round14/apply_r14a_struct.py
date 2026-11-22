"""Round 14 stage A: the struct at 0x40aec2 is e2m 1496 +10..+19 (the LSG reference speed, its no-load fuel, its
state and the altitude speed): governor_output_t -> low_speed_governor_reference_t, instance
governor_output_t_0040aec2 -> low_speed_governor_reference, four fields. Run AFTER apply_hand_worklist.py. Also adds
the e2m 1496 records to the comments of the two stage 13C rows that keep their names (0x40aecc / 0x40aed0).
- structure_definitions.csv (csv module per row): the type, the fields, new comments.
- global_variables.csv (split(",", 4)): the instance row and the three legacy '<instance>.<field>' label rows.
- every CSV comment / plate and the task docs: qualified field references, then the bare instance and type tokens
  (the instance first: the type is its prefix). Historical files (the table campaign CSV, the archives, the
  worklists) are left alone.
Appends the map rows (global / type / field). usage: apply_r14a_struct.py <repo> <map.csv>"""
import csv
import io
import os
import re
import sys

repo, map_path = os.path.abspath(sys.argv[1]), sys.argv[2]
out = os.path.join(repo, "firmware", "CM848_S90140.06_analysis", "output")
OLD_T, NEW_T = "governor_output_t", "low_speed_governor_reference_t"
OLD_I, NEW_I = "governor_output_t_0040aec2", "low_speed_governor_reference"
FIELDS = {
    "idle_reference_speed": ("reference_speed",
        "e2m 1496 +10 LSG_Reference_Speed '[LSRF] Current reference speed being used by the LSG feature' (1/8 rpm; "
        "6000 = 750 rpm in the RAM dump): written by cm848_slewLowSpeedGovernorReferenceSpeed"),
    "fuel_feed_forward_quantity": ("no_load_fuel",
        "e2m 1496 +12 No_Load_Fuel_At_LSG_Ref 'No load fueling value at LSG reference speed before droop' (signed; lha "
        "@ 0x28060): cm848_calculateLowSpeedGovernorNoLoadFuel"),
    "governor_output": ("reference_speed_state",
        "e2m 1496 +14 LSG_Reference_Speed_State 'Indication of which logic is controlling LSG idle speed': 0 COOLANT / "
        "1 PARK_NEU / 2 EXTENDED / 3 AC / 4 J1850 / 5 BASE / 6 JCOMM / 7 MIN / 8 MAX / 9 ALTITUDE / 10 SIP (shift in "
        "process) / 11 TOOL / 12 MOVING"),
    "idle_speed_barometric_ramped": ("altitude_speed",
        "e2m 1496 +16 LSG_Altitude_Speed (4 bytes; 1/8 rpm x 256): the altitude speed request after its slew (state 9)"),
}
sd = os.path.join(out, "structure_definitions.csv")
lines = open(sd).read().split("\n")
done = 0
for i, l in enumerate(lines):
    if not l.startswith(OLD_T + ","):
        continue
    row = next(csv.reader([l]))
    assert row[0] == OLD_T
    row[0] = NEW_T
    if row[2] in FIELDS:
        new, text = FIELDS[row[2]]
        row[5] = f"{text} (was {row[2]}) | earlier note: {row[5]}"
        row[2] = new
        done += 1
    s = io.StringIO()
    csv.writer(s, lineterminator="").writerow(row)
    lines[i] = s.getvalue()
assert done == 4, done
open(sd, "w").write("\n".join(lines))
gv = os.path.join(out, "global_variables.csv")
lines = open(gv).read().split("\n")
renamed = 0
for i, l in enumerate(lines):
    addr, name, typ, comment = (l.split(",", 3) + ["", "", ""])[:4]
    if name == OLD_I:
        assert addr == "0x0040aec2" and typ == OLD_T, (addr, typ)
        lines[i] = ",".join([addr, NEW_I, NEW_T, "e2m 1496 +10..+19: the LSG reference speed, its no-load fuel, its "
                             f"state and the altitude speed (was {OLD_I})" + (f" | earlier note: {comment}" if comment else "")])
        renamed += 1
    elif name.startswith(OLD_I + "."):
        field = name.split(".", 1)[1]
        lines[i] = ",".join([addr, f"{NEW_I}.{FIELDS[field][0]}", typ, comment])
        renamed += 1
assert renamed == 4, renamed
text = "\n".join(lines)
EXTRA = {  # 13C rows that keep their names: add their e2m 1496 records
    "0x0040aecc,sci_set_engine_speed_request_key,word,": "e2m 1496 +1A SCI_Cmd19_Status 'Indication that SCI CMD19 is "
        "active (0xE5C1 = tool requesting LSG override)'. ",
    "0x0040aed0,sci_set_engine_speed_request,word,": "e2m 1496 +1E SCI_LSG_Speed. ",
}
for head, note in EXTRA.items():
    assert text.count("\n" + head) == 1, head
    text = text.replace("\n" + head, "\n" + head + note)
open(gv, "w").write(text)


def refresh(path):
    t = open(path).read()
    n0 = t
    for old, (new, _) in FIELDS.items():
        t = re.sub(rf"\b{OLD_I}(\.|->){old}\b", rf"{NEW_I}\1{new}", t)
    t = re.sub(rf"\b{OLD_I}\b", NEW_I, t)
    t = re.sub(rf"\b{OLD_T}\b", NEW_T, t)
    if t != n0:
        open(path, "w").write(t)
        return True
    return False


touched = [os.path.basename(p) for p in (
    os.path.join(out, f) for f in ("global_variables.csv", "function_renames.csv", "structure_definitions.csv",
                                   "enums.csv", "function_definitions.csv", "local_variables.csv")) if refresh(p)]
for rel in ("work/tasks/042-table-campaign-rename-leads.md", "work/tasks/044-cm848-dtc-code-name-clashes.md",
            "work/tasks/045-cm848-fueling-state-enum.md", "work/tasks/046-cm848-egr-flow-estimate.md"):
    if refresh(os.path.join(repo, rel)):
        touched.append(rel.split("/")[-1])
with open(map_path, "a") as f:
    f.write(f"0x0040aec2,{NEW_I},{OLD_I},global\n,{NEW_T},{OLD_T},type\n")
    for old, (new, _) in FIELDS.items():
        f.write(f",{new},{old},field\n")
print("struct renamed; refreshed:", ", ".join(touched))
