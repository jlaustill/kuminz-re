"""Round 96: the refresh maps for a two-firmware apply. The refresh rewrites each map in its own firmware and also in
the other one, so a row whose old label is still a live function or global name in the OTHER firmware (a counterpart
that keeps the name, not a twin) must not cross: it is kept for its own firmware and dropped from the cross copy.
Writes <out>/map_own_<fw>.csv (all rows plus the hand rows) and <out>/map_cross_<fw>.csv (filtered).
usage: filter_maps_r96.py <repo> <cm550 map> <cm848 map> <out dir> [hand rows csv: firmware,address,name,old_label]"""
import csv
import os
import sys

repo, out = os.path.abspath(sys.argv[1]), sys.argv[4]
maps = {"cm550": sys.argv[2], "cm848": sys.argv[3]}
OUT = {"cm550": "firmware/CM550_J90350.00_analysis/output", "cm848": "firmware/CM848_S90140.06_analysis/output"}


def live(fw):
    names = set()
    for f in ("function_renames.csv", "global_variables.csv"):
        for line in open(os.path.join(repo, OUT[fw], f), newline=""):
            p = line.rstrip("\r\n").split(",", 2)
            if len(p) > 1 and p[0].startswith("0x") and p[1]:
                names.add(p[1])
    return names


hand = {"cm550": [], "cm848": []}
if len(sys.argv) > 5:
    for r in csv.DictReader(open(sys.argv[5])):
        hand[r["firmware"].lower()].append({"address": r["address"], "name": r["name"], "old_label": r["old_label"], "kind": "symbol", "dims": "1"})
for fw, path in maps.items():
    rows = list(csv.DictReader(open(path))) + hand[fw]
    other = live("cm848" if fw == "cm550" else "cm550")
    cross = [r for r in rows if r["old_label"] not in other]
    for r in rows:
        if r["old_label"] in other:
            print(f"{fw} row kept home only: {r['address']} {r['old_label']} -> {r['name']}")
    for name, data in (("own", rows), ("cross", cross)):
        with open(os.path.join(out, f"map_{name}_{fw}.csv"), "w", newline="") as f:
            w = csv.DictWriter(f, fieldnames=["address", "name", "old_label", "kind", "dims"])
            w.writeheader()
            w.writerows(data)
    print(fw, len(rows), "own;", len(cross), "cross")
