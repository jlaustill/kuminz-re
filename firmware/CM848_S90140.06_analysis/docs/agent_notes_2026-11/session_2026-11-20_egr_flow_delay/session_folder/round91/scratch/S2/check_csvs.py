#!/usr/bin/env python3
"""Read-only: list rows in CM550 CSVs whose address falls in the datalogger areas, plus name collisions."""
import csv, os, re, sys

OUT = "/home/linux/code/kuminz-re/.claude/worktrees/cm848-egr-flow-delay/firmware/CM550_J90350.00_analysis/output"
RANGES = [(0x803d64, 0x803dc9, "eeprom config blocks 1282-1284"),
          (0x800352, 0x80052b, "RAM working set"),
          (0x804fca, 0x8052fd, "event buffers / info / logged flags"),
          (0x80bac4, 0x80bacb, "block 1285 status words")]
ADDR = re.compile(r"0x0*([0-9a-fA-F]{6,8})\b")

def in_range(a):
    for lo, hi, tag in RANGES:
        if lo <= a <= hi:
            return tag
    return None

for fname in sorted(os.listdir(OUT)):
    if not fname.endswith(".csv"):
        continue
    path = os.path.join(OUT, fname)
    with open(path, errors="replace") as fh:
        for n, line in enumerate(fh, 1):
            if line.startswith("#"):
                continue
            cols = line.split(",")
            hits = []
            for c in cols[:3]:
                m = ADDR.fullmatch(c.strip()) if c.strip().lower().startswith("0x") else None
                if m:
                    a = int(m.group(1), 16)
                    t = in_range(a)
                    if t:
                        hits.append((hex(a), t))
            if hits and fname != "global_variables.csv":
                print(f"{fname}:{n}: {hits} :: {line.strip()[:200]}")

names = sys.argv[1:]
if names:
    print("--- name collision check")
    for fname in sorted(os.listdir(OUT)):
        if not (fname.endswith(".csv") or fname.endswith(".hpp")):
            continue
        text = open(os.path.join(OUT, fname), errors="replace").read()
        for nm in names:
            if re.search(r"\b" + re.escape(nm) + r"\b", text):
                print(f"  {nm} appears in {fname}")
