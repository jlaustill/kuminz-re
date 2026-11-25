"""Read-only: for each record address, every decompiled line (with its function) that names a byte of the record
(row names inside it, DAT_00xxxxxx / _DAT_00xxxxxx forms) - to find the set-up and the input writes.
usage: users.py 0xREC [0xREC ...] [--size N]"""
import csv
import re
import sys

CPP = "/home/linux/.claude/jobs/374b0424/tmp/w15/r95/frozen/cm550/J90350.00.ghidra.cpp"
GLOBALS = "/home/linux/.claude/jobs/374b0424/tmp/w15/r95/frozen/cm550/global_variables.csv"
args = sys.argv[1:]
size = 14
if "--size" in args:
    i = args.index("--size")
    size = int(args[i + 1])
    del args[i:i + 2]
names = {}
for row in csv.reader(open(GLOBALS)):
    if row and row[0].startswith("0x"):
        names.setdefault(int(row[0], 16), []).append(row[1])
lines = open(CPP, errors="replace").read().split("\n")
func_of = []
fn = "?"
for ln in lines:
    m = re.match(r"// Function: (\S+) @ (\S+)", ln)
    if m:
        fn = f"{m.group(1)}@{m.group(2)}"
    func_of.append(fn)
for arg in args:
    rec = int(arg, 16)
    pats = {}
    for a in range(rec, rec + size):
        for n in names.get(a, []):
            pats[n] = a - rec
        pats[f"DAT_{a:08x}"] = a - rec
    rx = re.compile(r"(?<![A-Za-z0-9_])_?(" + "|".join(re.escape(p) for p in sorted(pats, key=len, reverse=True)) + r")(?![A-Za-z0-9_])")
    print(f"=== record 0x{rec:x} ({size} bytes); names: {', '.join(f'{k}(+{v})' for k, v in pats.items() if not k.startswith('DAT_'))}")
    for i, ln in enumerate(lines):
        if ln.startswith("//"):
            continue
        ms = rx.findall(ln)
        if ms:
            print(f"  [{func_of[i]}] {ln.strip()[:150]}")
