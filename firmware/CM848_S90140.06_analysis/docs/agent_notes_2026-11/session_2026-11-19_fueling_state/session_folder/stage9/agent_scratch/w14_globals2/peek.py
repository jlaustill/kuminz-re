"""peek.py [-nLIMIT] <name-or-0xaddr>... : CSV row (full) + every code line using the name (function, line no, text)."""
import re
import sys

OUT = "/home/linux/code/kuminz-re/.claude/worktrees/cm848-fueling-state-enum/firmware/CM848_S90140.06_analysis/output"
lines = open(f"{OUT}/cm848_rom.ghidra.cpp", errors="replace").read().split("\n")
fn_at, cur = [], ""
for l in lines:
    m = re.match(r"// Function: (\S+)", l)
    if m:
        cur = m.group(1)
    fn_at.append(cur)
rows = {}
for l in open(f"{OUT}/global_variables.csv", errors="replace"):
    if l.startswith("0x"):
        p = (l.rstrip("\n").split(",", 3) + ["", "", "", ""])[:4]
        rows[int(p[0], 16)] = p
byname = {p[1]: a for a, p in rows.items() if p[1]}
limit = 40
args = sys.argv[1:]
if args and args[0].startswith("-n"):
    limit = int(args[0][2:])
    args = args[1:]
for a in args:
    if a.startswith("0x"):
        addr = int(a, 16)
        row = rows.get(addr)
    else:
        addr = byname.get(a)
        row = rows.get(addr) if addr is not None else None
    print(f"##### {a}: " + (f"0x{addr:08x} {row[1]} [{row[2]}] :: {row[3]}" if row else "no CSV row"))
    if not row or not row[1]:
        continue
    n = 0
    for i, l in enumerate(lines):
        if re.search(rf"(?<![A-Za-z0-9_]){re.escape(row[1])}(?![A-Za-z0-9_])", l) and not l.strip().startswith(("//", "/*", "*")):
            n += 1
            if n <= limit:
                print(f"  {fn_at[i]}:{i+1}: {l.strip()[:200]}")
    print(f"  ({n} code lines)")
