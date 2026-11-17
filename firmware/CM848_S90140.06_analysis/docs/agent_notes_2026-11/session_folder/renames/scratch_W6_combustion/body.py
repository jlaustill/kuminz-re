import re
import sys

OUT = "/home/linux/code/kuminz-re/.claude/worktrees/cm848-typing-arrays/firmware/CM848_S90140.06_analysis/output/"
lines = open(OUT + "cm848_rom.ghidra.cpp", errors="replace").read().split("\n")
starts = []
for i, ln in enumerate(lines):
    m = re.match(r"^// Function: (\S+) @ 0x([0-9a-fA-F]+)", ln)
    if m:
        starts.append((i, m.group(1)))
want = sys.argv[1:]
for k, (i, name) in enumerate(starts):
    if name in want:
        j = starts[k + 1][0] if k + 1 < len(starts) else len(lines)
        print("\n".join(lines[i:j]))
