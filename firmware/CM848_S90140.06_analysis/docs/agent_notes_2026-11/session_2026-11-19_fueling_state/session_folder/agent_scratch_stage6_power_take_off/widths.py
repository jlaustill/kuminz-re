"""For each (data address -> functions that reference it in the .cpp), run disasm_func.py's width check.
usage: widths.py <name>=<addr> ...   (name is the .cpp symbol; addr is 0x...)"""
import re
import subprocess
import sys

REPO = "/home/linux/code/kuminz-re/.claude/worktrees/cm848-fueling-state-enum"
CPP = "/tmp/pto_research/snap.cpp"
DISASM = "/tmp/pto_research/disasm_func.py"

lines = open(CPP).read().split("\n")
owner = []
cur = None
for line in lines:
    m = re.match(r"^// Function: (\S+) @ (0x[0-9a-f]+)", line)
    if m:
        cur = m.group(1)
    owner.append(cur)

for arg in sys.argv[1:]:
    name, addr = arg.split("=")
    pat = re.compile(rf"(?<![\w]){re.escape(name)}(?![\w])")
    funcs = []
    for i, line in enumerate(lines):
        if pat.search(line) and not line.startswith("// Function") and owner[i] and owner[i] not in funcs:
            funcs.append(owner[i])
    print(f"##### {name} @ {addr}: functions {funcs}")
    for f in funcs:
        out = subprocess.run(["python3", DISASM, f, addr], capture_output=True, text=True).stdout
        print(out.strip())
        print()
