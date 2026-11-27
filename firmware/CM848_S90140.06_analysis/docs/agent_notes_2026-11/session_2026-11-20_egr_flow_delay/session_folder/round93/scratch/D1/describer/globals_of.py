"""Describer D1 scratch: for a CM550 code range, list every absolute-long RAM / register address in the
disassembly with its global_variables.csv row and its e2m record(s).
usage: globals_of.py <start hex> <end hex>"""
import re
import subprocess
import sys

R = "/home/linux/.claude/jobs/374b0424/tmp/w15/r93"
REPO = "/home/linux/code/kuminz-re/.claude/worktrees/cm848-egr-flow-delay"
ROM = f"{REPO}/firmware/CM550_J90350.00_analysis/firmware/J90350.00.rom.bin"
dis = subprocess.run(["python3", f"{R}/tools/m68k.py", ROM, sys.argv[1], sys.argv[2]], capture_output=True, text=True).stdout
addrs = {}
for line in dis.split("\n"):
    for m in re.finditer(r"\(0x([0-9a-f]{5,8})\)\.l|#0x(8[0-9a-f]{5})\b", line):
        a = int(m.group(1) or m.group(2), 16)
        if a >= 0x800000 and a < 0xfff000:
            addrs.setdefault(a, []).append(line.split(":")[0])
rows = {}
for line in open(f"{R}/frozen/cm550/global_variables.csv", errors="replace"):
    p = line.rstrip("\n").split(",", 3)
    if p[0].startswith("0x"):
        rows[int(p[0], 16)] = p
e2m = {}
tab = subprocess.run(["python3", f"{REPO}/firmware/scripts/e2m_block_addresses.py", "--firmware", "cm550"] +
                     sum((["--address", hex(a)] for a in []), []), capture_output=True, text=True)
for a in sorted(addrs):
    row = rows.get(a)
    name = f"{row[1]} [{row[2]}]" if row else "(no row)"
    # the nearest row below, for struct members / wider rows
    near = ""
    if not row:
        below = [k for k in rows if k < a and a - k <= 64]
        if below:
            k = max(below)
            near = f"  (nearest row below: 0x{k:x} {rows[k][1]} [{rows[k][2]}] +{a - k})"
    r = subprocess.run(["python3", f"{REPO}/firmware/scripts/e2m_block_addresses.py", "--firmware", "cm550", "--address", hex(a)],
                       capture_output=True, text=True).stdout.strip().split("\n")
    print(f"0x{a:06x} x{len(addrs[a])} {name}{near}")
    if row and len(row) > 3 and row[3]:
        print(f"      comment: {row[3][:300]}")
    seen = set()
    for l in r:
        if l and l not in seen:
            seen.add(l)
            print(f"      e2m: {l[:260]}")
