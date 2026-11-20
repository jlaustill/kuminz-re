"""Collision check for candidate names: reads /tmp/w13b5/candidates.txt (address name) and greps the repo outputs."""
import csv
import glob
import os
import re
import sys

OUT = "/home/linux/code/kuminz-re/.claude/worktrees/cm848-fueling-state-enum/firmware/CM848_S90140.06_analysis/output"
FW = "/home/linux/code/kuminz-re/.claude/worktrees/cm848-fueling-state-enum/firmware"
cands = [line.split() for line in open(sys.argv[1] if len(sys.argv) > 1 else "/tmp/w13b5/candidates.txt") if line.strip()]
names = [c[1] for c in cands]
if len(set(names)) != len(names):
    dup = {n for n in names if names.count(n) > 1}
    print("DUPLICATE candidate names:", dup)
texts = {}
for path in glob.glob(OUT + "/*.csv") + [OUT + "/cm848_rom.ghidra.cpp"] + glob.glob(OUT + "/*.hpp"):
    texts[os.path.basename(path)] = open(path, errors="replace").read()
for address, name in cands:
    pat = re.compile(r"(?<![A-Za-z0-9_])" + re.escape(name) + r"(?![A-Za-z0-9_])")
    hits = [(f, len(pat.findall(t))) for f, t in texts.items() if pat.search(t)]
    flag = ""
    if name.endswith("_cal") != (0x3fd482 <= int(address, 16) <= 0x3feec1):
        flag += " CAL-MISMATCH"
    bad = [w for w in re.split(r"_", name) if w in ("temp", "cnt", "ref", "val", "calc", "init", "cfg", "tmptr", "thd", "cmd", "amb", "avg", "frac", "adj", "lmt", "lim", "sw", "pos", "filt", "diag", "ovr", "vlv", "pct", "cyl", "inj", "veh", "baro", "alt", "trq", "batt", "imt", "ct", "aps")]
    if bad:
        flag += " ABBREV:" + ",".join(bad)
    print(f"{address} {name}: {'EXISTS ' + str(hits) if hits else 'free'}{flag}")
