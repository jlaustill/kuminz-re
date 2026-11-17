"""Revert the stage-2 type fixes inside the boot-time-shared block 0x3fee34-0x3fee3d (keep the names) and put back
the 0x3fee3b label row; add a TIME-SHARED note to the three rows. Usage: revert_shared_types.py <globals.csv>"""
import sys

path = sys.argv[1]
TYPES = {0x003fee34: "dword", 0x003fee36: "", 0x003fee3a: "word"}
NOTE = ("TIME-SHARED with the boot ROM (0x3fee34-0x3fee3d): mpc555_eepromValidationCycle counts in the dword at "
        "0x3fee34, cm848_lookupEepromParameterAddress returns 0x3fee38 and cm848_bootSciCheckSecurityKey reads the "
        "bytes 0x3fee3a-0x3fee3d, so no single type fits both users; the types stay as they were. ")
lines = open(path).read().split("\n")
out, done = [], set()
for l in lines:
    p = l.split(",", 3)
    if p[0].startswith("0x") and int(p[0], 16) in TYPES:
        a = int(p[0], 16)
        while len(p) < 4:
            p.append("")
        p[2] = TYPES[a]
        p[3] = NOTE + p[3]
        done.add(a)
        l = ",".join(p)
        out.append(l)
        if a == 0x003fee3a:
            out.append("0x003fee3b,sensor_validation_delta+1,,")
        continue
    out.append(l)
assert done == set(TYPES)
open(path, "w").write("\n".join(out))
print("reverted", len(done))
