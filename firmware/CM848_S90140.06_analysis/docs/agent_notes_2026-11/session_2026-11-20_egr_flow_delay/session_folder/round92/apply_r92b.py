"""Round 92 stage B (CM550): the fueling state enum. CM550's e2m (v64t6_s.e2m FSFNFLST) labels codes 0x00-0x29 with the
same Cummins numbering as CM848's FUELING_STATE: 32 codes quote the same Calterm label as a CM848 member, and CM550 takes
those member names (a twin enum). The 10 codes CM848 has no member for get the label's words where they are plain
(LOWGEAR / OUTOGEAR / ALT_TORQ / TORQCTRL) and FUELING_STATE_UNIDENTIFIED_<n> otherwise (CM848's convention), with the
label in the comment. The carriers are typed FUELING_STATE:
- user_fueling_state (FSDSFLST), requested_fueling_state (FSLMDSST), fuel_demand_minimum_tracked_state (FSLMAHST);
- FSGVFLST -> adjusted_user_fueling_state, FSLMFLST -> torque_derate_fuel_source_code, FSFNFLST -> final_fueling_state
  (was fuel_limit_selection_state) - CM848's names for the same records;
- PTSLFLST -> power_take_off_or_user_fueling_state (CM848 keeps it as operating_mode_governor_output.mode_code).
Idempotent. usage: apply_r92b.py <repo> <map.csv>"""
import csv
import io
import os
import re
import sys

repo, map_out = os.path.abspath(sys.argv[1]), sys.argv[2]
R = "PR #53 round 92"
O5 = os.path.join(repo, "firmware/CM550_J90350.00_analysis/output")
O8 = os.path.join(repo, "firmware/CM848_S90140.06_analysis/output")
labels = {}
for line in open(os.path.join(repo, "e2m-analysis/originals/v64t6_s.e2m"), encoding="latin-1"):
    if line.startswith("FSFNFLST,"):
        data = line.split(";", 1)[0].split(",")
        if len(data) > 15 and "=" in data[15]:
            k, v = data[15].split("=", 1)
            labels[int(k, 16)] = v.strip()
cm848 = {}
for row in csv.reader(open(os.path.join(O8, "enums.csv"), newline="")):
    if row and row[0] == "FUELING_STATE":
        try:
            cm848[int(row[1], 0)] = (row[2], row[3] if len(row) > 3 else "")
        except ValueError:
            pass
NEW = {14: "FUELING_STATE_LOW_GEAR", 21: "FUELING_STATE_OUT_OF_GEAR", 31: "FUELING_STATE_ALTERNATE_TORQUE",
       35: "FUELING_STATE_TORQUE_CONTROL"}
rows = [f"# FUELING_STATE: the Cummins fueling state numbering of e2m FSFNFLST (v64t6_s.e2m labels 0x00-0x29), the "
        f"twin of CM848's enum ({R})"]
for code in sorted(labels):
    label = labels[code]
    if code in cm848 and label in cm848[code][1]:
        member, how = cm848[code][0], "CM848's member of the same label"
    elif code in NEW:
        member, how = NEW[code], "no CM848 member"
    else:
        member, how = f"FUELING_STATE_UNIDENTIFIED_{code}", "no CM848 member; the label's meaning is not proved"
    rows.append(f"FUELING_STATE,{code},{member},Calterm FSFNFLST {code:X}={label} ({how}),2")
E = os.path.join(O5, "enums.csv")
t = open(E, newline="").read()
if "\nFUELING_STATE," not in t:
    t = t.rstrip("\n") + "\n\n" + "\n".join(rows) + "\n"
    open(E, "w", newline="").write(t)
CARRIERS = [
    ("0x0080ded4", None, "FSDSFLST user fueling state"),
    ("0x0080d334", None, "FSLMDSST requested fueling state"),
    ("0x0080ded0", None, "FSLMAHST minimum tracked fueling state"),
    ("0x0080a8f2", "adjusted_user_fueling_state", "e2m 1045 +2 FSGVFLST 'which algorithm is in control of fueling after it' (1-12): the "
     "user fueling state after the governors; CM848's adjusted_user_fueling_state"),
    ("0x0080deca", "torque_derate_fuel_source_code", "e2m 105D +2 FSLMFLST 'which algorithm is controlling fuel after it has' (13-41): "
     "the limiter that set the derated fuel; CM848's torque_derate_fuel_source_code"),
    ("0x0080d330", "final_fueling_state", "e2m 1051 +2 FSFNFLST FINAL FUELING STATE (1-41; its Calterm labels are FUELING_STATE's "
     "members); CM848's final_fueling_state"),
    ("0x0080dc32", "power_take_off_or_user_fueling_state", "e2m 1265 +6 PTSLFLST 'selected fueling state from PTO fl. state and "
     "user fl. state' (1-8); CM848 keeps the same record as operating_mode_governor_output.mode_code"),
]
G = os.path.join(O5, "global_variables.csv")
lines = open(G, newline="").read().split("\n")
renames = []
for a, new, note in CARRIERS:
    i = next(k for k, l in enumerate(lines) if l.startswith(a + ","))
    parts = lines[i].split(",", 3)
    old, typ, comment = parts[1], parts[2], parts[3] if len(parts) > 3 else ""
    name = new or old
    if typ == "FUELING_STATE" and name == old:
        continue
    if new and new != old:
        comment = f"{note} (was {old}; {R})"
        renames.append((a, new, old))
    elif not comment:
        comment = f"{note}; typed FUELING_STATE ({R})"
    else:
        comment = f"{comment} | typed FUELING_STATE ({R})"
    lines[i] = f"{a},{name},FUELING_STATE,{comment}"
open(G, "w", newline="").write("\n".join(lines))
if renames:      # a re-run (nothing left to rename) must not empty the map
    with open(map_out, "w") as fh:
        fh.write("address,name,old_label,kind,dims\n")
        for a, n, o in renames:
            fh.write(f"{a},{n},{o},symbol,1\n")
print(f"FUELING_STATE: {len(rows) - 1} members; {len(CARRIERS)} carriers, {len(renames)} renamed")
