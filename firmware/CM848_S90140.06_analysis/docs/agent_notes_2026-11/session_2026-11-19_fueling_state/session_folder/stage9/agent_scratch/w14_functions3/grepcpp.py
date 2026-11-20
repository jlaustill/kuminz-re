"""usage: grepcpp.py REGEX [context] -- print .cpp lines matching REGEX with the enclosing function name"""
import re
import sys

CPP = "/home/linux/code/kuminz-re/.claude/worktrees/cm848-fueling-state-enum/firmware/CM848_S90140.06_analysis/output/cm848_rom.ghidra.cpp"
pat = re.compile(sys.argv[1])
ctx = int(sys.argv[2]) if len(sys.argv) > 2 else 0
lines = open(CPP, errors="replace").read().split("\n")
fn = ""
fn_at = []
for line in lines:
    m = re.match(r"// Function: (\S+)", line)
    if m:
        fn = m.group(1)
    fn_at.append(fn)
last = -1
for i, line in enumerate(lines):
    if pat.search(line):
        lo, hi = max(0, i - ctx), min(len(lines), i + ctx + 1)
        if lo <= last:
            lo = last + 1
        else:
            if last >= 0 and ctx:
                print("   ----")
        for j in range(lo, hi):
            print(f"{j + 1} [{fn_at[j]}]: {lines[j]}")
        last = hi - 1
