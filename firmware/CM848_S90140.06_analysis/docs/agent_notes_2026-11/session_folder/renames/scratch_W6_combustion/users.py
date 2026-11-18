import csv
import re
import sys

OUT = "/home/linux/code/kuminz-re/.claude/worktrees/cm848-typing-arrays/firmware/CM848_S90140.06_analysis/output/"
by_addr = {}
for r in csv.reader(open(OUT + "global_variables.csv")):
    if r and r[0].startswith("0x"):
        by_addr[int(r[0], 16)] = r

lines = open(OUT + "cm848_rom.ghidra.cpp", errors="replace").read().split("\n")
func_at = []
cur = None
for i, ln in enumerate(lines):
    m = re.match(r"^// Function: (\S+) @ 0x([0-9a-fA-F]+)", ln)
    if m:
        cur = m.group(1)
    func_at.append(cur)


def users(name):
    out = {}
    pat = re.compile(r"\b" + re.escape(name) + r"\b")
    for i, ln in enumerate(lines):
        if pat.search(ln) and not ln.startswith("//") and not ln.startswith("/*") and not ln.lstrip().startswith("*"):
            out.setdefault(func_at[i], []).append(i + 1)
    return out


want = [int(x, 16) for x in sys.argv[1:]]
for a in want:
    r = by_addr.get(a)
    if not r:
        print(hex(a), "NO ROW")
        continue
    u = users(r[1])
    print(hex(a), r[1], r[2], "->", {k: v[:3] for k, v in u.items()})
