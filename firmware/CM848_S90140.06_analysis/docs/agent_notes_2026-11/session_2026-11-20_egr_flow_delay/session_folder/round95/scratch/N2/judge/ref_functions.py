"""For each proposed N2 record: the functions that hold its absolute references (by field), and whether the comment
names them. Also the indirect (register / pea (d,An)) users found by the call-site reading. Read-only.
usage: python3 ref_functions.py"""
import bisect
import csv
import json
import re

J = "/home/linux/.claude/jobs/374b0424/tmp/w15/r95/scratch/N2/judge/"
F = "/home/linux/.claude/jobs/374b0424/tmp/w15/r95/frozen/cm550/"
REPO = "/home/linux/code/kuminz-re/.claude/worktrees/cm848-egr-flow-delay"
rom = open(REPO + "/firmware/CM550_J90350.00_analysis/firmware/J90350.00.rom.bin", "rb").read()
starts, names = [], []
for r in csv.reader(open(F + "function_renames.csv")):
    if r and r[0].startswith("0x"):
        starts.append(int(r[0], 16))
        names.append(r[1])
order = sorted(range(len(starts)), key=lambda i: starts[i])
starts = [starts[i] for i in order]
names = [names[i] for i in order]


def func_of(loc):
    i = bisect.bisect_right(starts, loc) - 1
    return f"{names[i]}@0x{starts[i]:x}" if i >= 0 else "?"


props = json.load(open(J + "proposals_globals.json"))
for e in props:
    if e["proposed_type"] != "table_lookup_1d_arguments_t":
        continue
    a = int(e["address"], 16)
    refs = {}
    for i in range(0, len(rom) - 4, 2):
        v = int.from_bytes(rom[i:i + 4], "big")
        if a <= v < a + 14:
            refs.setdefault(func_of(i), []).append(f"+{v - a:x}@{i:x}")
    print(f"=== {e['address']} {e['proposed_name']}")
    for f, rs in refs.items():
        nm = f.split("@")[0]
        print(f"   {f}: {rs}  {'(named in comment)' if nm in e['comment'] else '(NOT named in comment)'}")
