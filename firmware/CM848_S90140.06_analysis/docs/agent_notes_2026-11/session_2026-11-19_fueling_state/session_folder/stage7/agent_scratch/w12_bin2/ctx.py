"""ctx.py <label-or-hexaddr> [before] [after]: every non-comment .cpp line that uses the label, with context.
A hex address (0x....) is turned into the DAT_/WORD_/... label forms (DAT_0005983a, _DAT_..., PTR_DAT_...) and
the current global_variables.csv name, if any."""
import csv
import re
import sys

OUT = "/home/linux/code/kuminz-re/.claude/worktrees/cm848-fueling-state-enum/firmware/CM848_S90140.06_analysis/output/"
cpp = open(OUT + "cm848_rom.ghidra.cpp", errors="replace").read().split("\n")
arg = sys.argv[1]
before = int(sys.argv[2]) if len(sys.argv) > 2 else 3
after = int(sys.argv[3]) if len(sys.argv) > 3 else 3
labels = [arg]
if arg.startswith("0x"):
    a8 = f"{int(arg, 16):08x}"
    labels = [f"DAT_{a8}", f"_DAT_{a8}", f"PTR_DAT_{a8}"]
    for row in csv.reader(open(OUT + "global_variables.csv")):
        if row and row[0].lower() == f"0x{a8}" and row[1]:
            labels.append(row[1])
pattern = re.compile(r"\b(" + "|".join(map(re.escape, labels)) + r")\b")
fn = ""
fn_at = []
for line in cpp:
    m = re.match(r"// Function: (\S+) @ (0x[0-9a-f]+)", line)
    if m:
        fn = f"{m.group(1)}@{m.group(2)}"
    fn_at.append(fn)
shown = set()
for i, line in enumerate(cpp):
    if line.strip().startswith(("//", "/*", "*")):
        continue
    if pattern.search(line):
        lo, hi = max(0, i - before), min(len(cpp), i + after + 1)
        if any(k in shown for k in range(i, i + 1)):
            continue
        print(f"--- {fn_at[i]} line {i + 1} ---")
        for k in range(lo, hi):
            mark = ">>" if k == i else "  "
            print(f"{mark}{k + 1}: {cpp[k]}")
            shown.add(k)
