"""Rename struct types and their single default-labelled instance (+ member-label rows).
Usage: rename_struct_types.py <output_dir> <mapping_out.csv>"""
import csv
import re
import sys

OUT, MAP = sys.argv[1:3]
RENAMES = [  # old type, new type, instance address, new instance name
    ("fuel_blend_state_t", "combustion_reference_state_t", 0x0040a494, "combustion_reference_state"),
    ("protection_threshold_set_t", "combustion_chi_maximum_fuel_points_t", 0x0040a502, "combustion_chi_maximum_fuel_points"),
]
sd_path, gv_path = f"{OUT}/structure_definitions.csv", f"{OUT}/global_variables.csv"
sd = open(sd_path).read().split("\n")
gv = open(gv_path).read().split("\n")
mapping = []
for old_t, new_t, inst_addr, new_i in RENAMES:
    old_i = f"{old_t}_{inst_addr:08x}"
    n = 0
    for i, l in enumerate(sd):
        if l.startswith(old_t + ","):
            sd[i] = new_t + l[len(old_t):]
            n += 1
    assert n > 0, old_t
    m = 0
    for i, l in enumerate(gv):
        p = l.split(",", 3)
        if not p[0].startswith("0x"):
            continue
        if p[1] == old_i or p[1].startswith(old_i + "."):
            p[1] = new_i + p[1][len(old_i):]
            m += 1
        if len(p) > 2 and re.fullmatch(rf"{re.escape(old_t)}(\[\d+\])?", p[2]):
            p[2] = new_t + p[2][len(old_t):]
        gv[i] = ",".join(p)
    assert m >= 1, old_i
    mapping += [("", new_t, old_t, "token"), (f"0x{inst_addr:08x}", new_i, old_i, "global")]
    print(f"{old_t} -> {new_t}: {n} struct rows, {m} instance / member-label rows")
open(sd_path, "w").write("\n".join(sd))
open(gv_path, "w").write("\n".join(gv))
with open(MAP, "w", newline="") as f:
    w = csv.writer(f)
    w.writerow(["address", "name", "old_label", "kind"])
    w.writerows(mapping)
