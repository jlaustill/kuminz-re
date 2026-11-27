"""Round 70: classify the named rows in 0x302000-0x3037ff (the 6 KB RAM the boot kernel clears) by which kernel
renders them, and count the renders of three suspected stale rows inside ecu_power_state_flags.
usage: classify_dptram_rows.py <repo>"""
import collections
import os
import re
import sys

repo = os.path.abspath(sys.argv[1])
C = os.path.join(repo, "firmware/CM848_S90140.06_analysis/output/cm848_rom.ghidra.cpp")
G = os.path.join(repo, "firmware/CM848_S90140.06_analysis/output/global_variables.csv")
rows = []
for line in open(G):
    p = line.rstrip("\n").split(",", 3)
    if p[0].startswith("0x") and 0x302000 <= int(p[0], 16) < 0x303800 and p[1] and not p[1].startswith("TPU3_"):
        rows.append((p[0], p[1]))
bases = {}
for a, n in rows:
    bases.setdefault(n.split(".")[0].split("[")[0], a)
func = addr = None
uses = collections.defaultdict(collections.Counter)
for line in open(C):
    m = re.match(r"// Function: (\S+) @ 0x([0-9a-f]+)", line)
    if m:
        func, addr = m.group(1), int(m.group(2), 16)
        continue
    for b in bases:
        if re.search(rf"\b{re.escape(b)}\b", line):
            kind = "boot" if addr is not None and (addr < 0x7f60 or 0x3f9800 <= addr < 0x3fdb30) else "app"
            uses[b][kind] += 1
print(len(bases), "named bases in 0x302000-0x3037ff;", sum(1 for b in bases if b in uses), "render")
app = {b: dict(c) for b, c in uses.items() if c.get("app")}
print("with application renders:", app or "none")
for b in ("keyon_state_machine_phase", "qadc_a_portqa", "ecm_runtime_accumulator"):
    print(b, dict(uses.get(b, {})))
