"""For an audit TSV's function changes: the current name at each address in HEAD's function_renames.csv vs the
audit's 'current' (the audit read an older frozen copy). usage: check_current.py <repo> <changes.tsv>"""
import csv
import os
import sys

repo, tsv = sys.argv[1], sys.argv[2]
DIRS = {"CM550": "firmware/CM550_J90350.00_analysis/output", "CM848": "firmware/CM848_S90140.06_analysis/output"}
names = {}
for fw, d in DIRS.items():
    names[fw] = {int(r[0], 16): r[1] for r in csv.reader(open(os.path.join(repo, d, "function_renames.csv"), newline=""))
                 if r and r[0].startswith("0x") and len(r) > 1}
for line in open(tsv):
    group, fw, kind, address, current, final, *_ = line.rstrip("\n").split("\t")
    if kind != "function":
        continue
    head = names[fw].get(int(address, 16), "(no row)")
    flag = "" if head == current else "  <-- HEAD differs"
    print(f"{fw} {address} audit:{current} head:{head} -> {final}{flag}")
