import csv
import json
import re
import sys

sys.path.insert(0, "/home/linux/.claude/jobs/d55ae3c6/tmp/renames/scratch_W6_combustion")
from w6 import *

OUT = "/home/linux/code/kuminz-re/.claude/worktrees/cm848-typing-arrays/firmware/CM848_S90140.06_analysis/output/"
RN = "/home/linux/.claude/jobs/d55ae3c6/tmp/renames/"
lines = open(OUT + "cm848_rom.ghidra.cpp", errors="replace").read().split("\n")
starts = []
for i, ln in enumerate(lines):
    m = re.match(r"^// Function: (\S+) @ 0x([0-9a-fA-F]+)", ln)
    if m:
        starts.append((i, m.group(1)))


def body(name):
    for k, (i, n) in enumerate(starts):
        if n == name:
            j = starts[k + 1][0] if k + 1 < len(starts) else len(lines)
            return lines[i:j]
    return []


def func_of(idx):
    cur = None
    for i, n in starts:
        if i <= idx:
            cur = n
    return cur


glob = {}
for r in csv.reader(open(OUT + "global_variables.csv")):
    if r and r[0].startswith("0x"):
        glob[int(r[0], 16)] = r

print("=== 1. users of fuel_demand_boost_input (full) and the in-use coolant word")
cur = None
users = {}
for i, ln in enumerate(lines):
    if re.search(r"\bfuel_demand_boost_input\b", ln) and not ln.lstrip().startswith(("*", "//", "/*")):
        users.setdefault(func_of(i), []).append(i + 1)
print({k: v[:2] for k, v in users.items()})
for a in (0x40bd88, 0x40bdae, 0x40b152):
    r = glob.get(a)
    print(hex(a), r[1:3] if r else None, (r[3][:160] if r and len(r) > 3 else ""))
for i, ln in enumerate(lines):
    if re.search(r"\bcoolant_temperature_in_use\s*=", ln):
        print("write coolant_temperature_in_use", i + 1, func_of(i), ln.strip()[:120])
    if re.search(r"\bWORD_0040bd88\b", ln) and "=" in ln and ln.strip().startswith("WORD_0040bd88"):
        print("write WORD_0040bd88", i + 1, func_of(i), ln.strip()[:120])

print("=== 3. DAT_003fbd54 / DAT_003fbd50 / DAT_0040656x")
for pat in (r"\bDAT_003fbd54\b", r"\bDAT_003fbd50\b", r"\bDAT_00406568\b", r"\bDAT_0040656a\b", r"\bDAT_003fbd56\b", r"\bDAT_003fbd58\b"):
    for i, ln in enumerate(lines):
        if re.search(pat, ln) and not ln.lstrip().startswith(("*", "//", "/*")):
            print(pat, i + 1, func_of(i), "|", ln.strip()[:110])
print("dump 0x406568/6a:", w(0x406568), w(0x40656a), "| 0x3fbd50..58:", [w(a) for a in range(0x3fbd50, 0x3fbd5a, 2)])

print("=== 4. bit 13/14/15 sites")
for ln_no in (11879, 12139, 60795):
    print("--", ln_no, func_of(ln_no - 1))
    print("\n".join(lines[ln_no - 3:ln_no + 9]))

print("=== 5. overlaps inside the 20 new grids")
maps = [0x40179c, 0x400e1c, 0x40107c, 0x4012dc, 0x40237c, 0x4019fc, 0x401c5c, 0x401ebc, 0x402f5c, 0x4025dc, 0x40283c, 0x402a9c,
        0x403b3c, 0x4031bc, 0x40341c, 0x40367c, 0x40471c, 0x403d9c, 0x403ffc, 0x40425c]
arr = {}
for r in csv.reader(open(OUT + "arrays.csv")):
    if r and r[0].startswith("0x"):
        arr[int(r[0], 16)] = r
hits = 0
for m in maps:
    for a in list(glob) + list(arr):
        if m < a < m + 0x260:
            hits += 1
            print("INSIDE", hex(m), hex(a), (glob.get(a) or arr.get(a))[1:3])
    # also grids that start before and run into m
    for a, r in glob.items():
        t = r[2]
        mm = re.match(r"word\[(\d+)\]", t)
        if mm and a < m < a + 2 * int(mm.group(1)):
            hits += 1
            print("RUNS INTO", hex(a), r[1], t, hex(m))
print("overlap hits:", hits)

print("=== 6. pairing: dualAxis calls of the four reference functions")
for fn in ("cm848_calculateEgrFractionReference", "cm848_calculateMassChargeFlowReference", "cm848_calculateChargeTemperatureReference",
           "cm848_calculateNitrogenOxidesTargetReference"):
    b = body(fn)
    print("--", fn)
    for k, ln in enumerate(b):
        if "cm848_dualAxisTableInterpolation" in ln:
            seg = " ".join(x.strip() for x in b[k - 1:k + 4])
            seg = re.sub(r"\s+", " ", seg)
            print("   ", seg[:330])

print("=== 7. how W5 encoded a kept function name")
for fn in ("result_W5_combustion_rom.jsonl", "aligned_W5_combustion_rom.jsonl"):
    n = 0
    for line in open(RN + fn):
        o = json.loads(line)
        if o.get("kind") == "function":
            if o.get("new") == o.get("old") or "new" not in o:
                n += 1
                if n <= 2:
                    print(fn, {k: (v[:90] if isinstance(v, str) else v) for k, v in o.items()})
    print(fn, "kept-name rows:", n)
