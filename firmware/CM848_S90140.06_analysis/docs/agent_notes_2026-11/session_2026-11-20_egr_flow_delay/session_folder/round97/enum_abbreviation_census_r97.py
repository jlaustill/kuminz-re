"""Round 97 (read-only): enum types and members whose words are invented abbreviations, both firmwares; also how many
member names render in each decompilation. usage: enum_abbreviation_census_r97.py <repo>"""
import collections
import csv
import os
import re
import sys

repo = os.path.abspath(sys.argv[1])
WATCH = {"DIAG", "SVC", "SUBFUNC", "CMD", "PARAM", "PARAMS", "MSG", "INIT", "ADDR", "RESP", "REQ", "ACK", "NACK", "CFG",
         "CONFIG", "CTRL", "STAT", "ERR", "SEL", "SEQ", "TMP", "TEMP", "MEM", "OP", "PROP", "BUF", "IDX", "CNT", "VAL",
         "NUM", "HDR", "LEN", "PTR", "SRC", "DST", "DEST", "TX", "RX", "CALC", "MAX", "MIN", "SW", "HW", "EXT", "INT",
         "XFER", "PROT", "THR", "LIM", "SPD", "TRQ", "ENG", "VEH", "PWR", "BRK", "ACCEL", "DECEL", "INFO", "ID2", "B",
         "2B", "4B", "REG", "REGS", "SEC", "MS", "US", "HI", "LO", "LSB", "MSB", "ANC", "LSG", "HSG", "ASG", "RSG", "AFC",
         "EPS", "EPF", "CBD", "VSG", "PID", "TOD", "DTC"}
ALLOWED = {"PID", "DTC", "ID"}
for fw, out in (("CM550", "firmware/CM550_J90350.00_analysis/output"), ("CM848", "firmware/CM848_S90140.06_analysis/output")):
    cpp = open(os.path.join(repo, out, "J90350.00.ghidra.cpp" if fw == "CM550" else "cm848_rom.ghidra.cpp"), errors="replace").read()
    types = collections.Counter()
    members = []
    for r in csv.reader(l for l in open(os.path.join(repo, out, "enums.csv"), newline="") if not l.startswith("#")):
        if len(r) < 3 or not r[0] or r[0] == "enum_name":
            continue
        tw = set(r[0].split("_")) & (WATCH - ALLOWED)
        mw = set(r[2].split("_")) & (WATCH - ALLOWED)
        if tw:
            types[r[0]] += 1
        if mw:
            renders = len(re.findall(r"(?<![A-Za-z0-9_])%s(?![A-Za-z0-9_])" % re.escape(r[2]), cpp))
            members.append((r[0], r[2], sorted(mw), renders))
    print(f"== {fw}: {len(types)} enum types with abbreviations, {len(members)} members ({sum(1 for m in members if m[3])} render)")
    for t, n in types.most_common():
        print(f"   type {t} ({n} members)")
    c = collections.Counter(w for m in members for w in m[2])
    print("   member words:", ", ".join(f"{w} {n}" for w, n in c.most_common(25)))
