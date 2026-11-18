"""Rows whose name is a Ghidra auto-label: plan type-only (typed) or removal (untyped). --apply edits."""
import re
import sys
from collections import Counter

OUT = sys.argv[1]
APPLY = "--apply" in sys.argv
AUTO = re.compile(r"^(?:_?DAT|BYTE|WORD|DWORD|QWORD|PTR(?:_[A-Z]+)*|UNK|SUB|LAB|FUN|ram0x|uRam|u|s)_[^,]*?[0-9a-fA-F]{8}$|^u_[^,]*$|^s_[^,]*$")
registers = set()
for line in open(f"{OUT}/mpc555_registers.csv"):
    p = line.split(",", 1)
    if p[0].startswith("0x"):
        registers.add(int(p[0], 16))
functions = set()
for line in open(f"{OUT}/function_renames.csv"):
    p = line.split(",", 1)
    if p[0].startswith("0x"):
        functions.add(int(p[0], 16))
lines = open(f"{OUT}/global_variables.csv").read().split("\n")
out, plan = [], Counter()
examples = {}
for line in lines:
    p = line.split(",", 3)
    if p[0].startswith("0x") and len(p) > 1 and AUTO.match(p[1]):
        a = int(p[0], 16)
        typ = p[2] if len(p) > 2 else ""
        if a in registers:
            plan["kept (register address)"] += 1
        elif not typ:
            plan["removed (no type)"] += 1
            examples.setdefault("removed", []).append(p[1])
            continue
        else:
            plan["type-only"] += 1
            examples.setdefault("type-only", []).append(f"{p[1]}:{typ}")
            p[1] = ""
            line = ",".join(p)
        plan["at a function entry"] += a in functions
    out.append(line)
print(dict(plan))
for k, v in examples.items():
    print(k, len(v), v[:10])
if APPLY:
    open(f"{OUT}/global_variables.csv", "w").write("\n".join(out))
    print("applied")
