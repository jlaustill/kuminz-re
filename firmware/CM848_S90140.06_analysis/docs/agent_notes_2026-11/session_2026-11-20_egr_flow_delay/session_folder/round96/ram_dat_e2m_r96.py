"""Round 96 (read-only): CM848's unnamed DAT_ symbols in the EEPROM mirror (0x3fd482-0x3feec1) and working RAM
(>= 0x40a049) with their use counts, the e2m record the ECU's parameter ID table resolves at each address
(e2m_block_addresses.py --address) and the functions that use them. usage: ram_dat_e2m_r96.py <repo>"""
import collections
import os
import re
import subprocess
import sys

repo = os.path.abspath(sys.argv[1])
cpp = open(os.path.join(repo, "firmware/CM848_S90140.06_analysis/output/cm848_rom.ghidra.cpp"), errors="replace").read()
uses = collections.Counter()
funcs = collections.defaultdict(set)
current = "?"
for line in cpp.split("\n"):
    m = re.match(r"^// Function: (\S+) @", line)
    if m:
        current = m.group(1)
    for d in re.findall(r"\b_?DAT_00([0-9a-f]{6})\b", line):
        a = int(d, 16)
        if 0x3fd482 <= a <= 0x3feec1 or a >= 0x40a049:
            uses[a] += 1
            funcs[a].add(current)
tool = os.path.join(repo, "firmware/scripts/e2m_block_addresses.py")
resolved = 0
for a in sorted(uses):
    out = subprocess.run([sys.executable, tool, "--address", hex(a)], capture_output=True, text=True, cwd=repo).stdout.strip()
    record = out.split("\n")[0][:140] if out else "-"
    resolved += bool(out)
    region = "EEPROM" if a <= 0x3feec1 else "RAM"
    print(f"0x{a:06x} {region} uses {uses[a]:2d} | {record} | {', '.join(sorted(funcs[a]))[:120]}")
print(len(uses), "symbols,", resolved, "resolve to an e2m record")
