"""Round 39 stage C survey: every HARD row of audit_cal_suffixes.py (a _cal name outside the EEPROM mirror) with its
type, the name without _cal, banned words, a name collision, the e2m record the parameter ID table resolves at the
address, whether a 0x40xxxx address is ROM-copied (the RAM dump word equals ROM at RAM - 0x39a3e6) and the .cpp lines
that assign it.  usage: hard_scalars.py <repo> <audit.txt> <out.tsv>"""
import ast
import os
import re
import subprocess
import sys

repo, audit, out = os.path.abspath(sys.argv[1]), sys.argv[2], sys.argv[3]
fw = os.path.join(repo, "firmware")
src = open("/home/linux/.claude/jobs/374b0424/tmp/w15/apply_hand_worklist.py").read()
BANNED = ast.literal_eval(re.search(r"BANNED = (\{.*?\})", src, re.S).group(1))
rows, names = {}, set()
for l in open(os.path.join(fw, "CM848_S90140.06_analysis/output/global_variables.csv"), errors="replace"):
    p = l.split(",", 3)
    if len(p) >= 3 and p[0].startswith("0x"):
        rows[p[1]] = (p[0], p[2], p[3].strip() if len(p) > 3 else "")
        names.add(p[1])
ram = open(os.path.join(fw, "CM848_S90140.06_analysis/originals/cm848_ram.bin"), "rb").read()
rom = open(os.path.join(fw, "CM848_S90140.06_analysis/originals/cm848_rom.bin"), "rb").read()
cpp = open(os.path.join(fw, "CM848_S90140.06_analysis/output/cm848_rom.ghidra.cpp"), errors="replace").read()
hard = []
sec = None
for l in open(audit):
    if l.startswith("==="):
        sec = l.split()[1]
        continue
    m = re.match(r"\s+(0x[0-9a-f]+)\s+(\S+)\s+(\S+)", l)
    if m and sec == "HARD":
        hard.append((m.group(1), m.group(2), m.group(3)))
with open(out, "w") as fh:
    for a, region, name in hard:
        addr, typ, comment = rows[name]
        ai = int(addr, 16)
        new = re.sub(r"_cal(?=_|$)", "", name)
        bad = [t for t in new.split("_") if t in BANNED]
        clash = new in names
        width = {"byte": 1, "word": 2, "i16": 2, "dword": 4}.get(typ, 2)
        copied = ""
        if 0x400000 <= ai < 0x40c200:
            r_val = ram[ai - 0x3FA000:ai - 0x3FA000 + width]
            o_val = rom[ai - 0x39a3e6:ai - 0x39a3e6 + width]
            copied = "rom-copied" if r_val == o_val else f"ram {r_val.hex()} rom {o_val.hex()}"
        e2m = subprocess.run(["python3", os.path.join(fw, "scripts/e2m_block_addresses.py"), "--address", addr],
                             capture_output=True, text=True, cwd=fw).stdout.strip().splitlines()
        e2m = e2m[0][:150] if e2m else ""
        writes = len(re.findall(r"\b" + re.escape(name) + r"(?:\.[A-Za-z_0-9]+)? = ", cpp))
        fh.write("\t".join([addr, region, typ, name, new, ",".join(bad), "CLASH" if clash else "", copied,
                            f"writes={writes}", e2m, comment[:120]]) + "\n")
print(len(hard), "rows")
