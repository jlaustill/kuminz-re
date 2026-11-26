"""Round 96: a proof-only map = the refresh map + one row per global or function that had no name at HEAD and has
one now (old label DAT_<addr> / FUN_<addr> / the HEAD placeholder name, as the base decompilation shows it).
usage: proof_map_r96.py <repo> <cm550|cm848> <refresh map.csv> <out.csv>"""
import csv
import os
import subprocess
import sys

repo, fw, mp, out = os.path.abspath(sys.argv[1]), sys.argv[2], sys.argv[3], sys.argv[4]
D = {"cm550": "firmware/CM550_J90350.00_analysis/output", "cm848": "firmware/CM848_S90140.06_analysis/output"}[fw]


def rows(text):
    r = {}
    for line in text.split("\n"):
        p = line.rstrip("\r").split(",", 2)
        if len(p) > 1 and p[0].startswith("0x"):
            r[int(p[0], 16)] = p[1]
    return r


maprows = list(csv.DictReader(open(mp)))
have = {r["old_label"] for r in maprows}
added = 0
for f, prefix in (("global_variables.csv", "DAT_"), ("function_renames.csv", "FUN_")):
    head = rows(subprocess.run(["git", "-C", repo, "show", f"HEAD:{D}/{f}"], capture_output=True, text=True).stdout)
    now = rows(open(os.path.join(repo, D, f), newline="").read())
    for a, name in now.items():
        if name and not head.get(a) and "." not in name:
            for old in (f"{prefix}{a:08x}", f"_{prefix}{a:08x}") if prefix == "DAT_" else (f"{prefix}{a:08x}",):
                if old not in have:
                    maprows.append({"address": f"0x{a:08x}", "name": name, "old_label": old, "kind": "symbol", "dims": "1"})
                    added += 1
with open(out, "w", newline="") as fh:
    w = csv.DictWriter(fh, fieldnames=["address", "name", "old_label", "kind", "dims"])
    w.writeheader()
    w.writerows(maprows)
print(fw, "proof map:", len(maprows), "rows,", added, "new-name rows added")
