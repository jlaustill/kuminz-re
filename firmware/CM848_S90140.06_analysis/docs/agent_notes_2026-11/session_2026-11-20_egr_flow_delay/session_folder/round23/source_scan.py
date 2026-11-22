"""Round 23: the SENSOR_VALUE_SOURCE reach (round 19 lead). For every global whose name ends in _source and whose type
is word: its e2m record through the parameter ID table (e2m_block_addresses.py --address), the record's value list,
and every literal the code stores or compares (round 19's source_values.py). A word qualifies when the record's list
is 0=PRIMARY, 1=BACKUP, 2=DEFAULT (any zero padding) and the code uses no other literal.
usage: source_scan.py <firmware dir>"""
import os
import re
import subprocess
import sys

fw = sys.argv[1]
out = os.path.join(fw, "CM848_S90140.06_analysis", "output")
cpp = os.path.join(out, "cm848_rom.ghidra.cpp")
rows = []
for l in open(os.path.join(out, "global_variables.csv")):
    if l.startswith("0x"):
        a, n, t = l.split(",", 3)[:3]
        if n.endswith("_source") and t == "word":
            rows.append((a, n))
LIST = re.compile(r"^0*0=PRIMARY:0*1=BACKUP:0*2=DEFAULT$")
for a, n in rows:
    e2m = subprocess.run(["python3", os.path.join(fw, "scripts/e2m_block_addresses.py"), "--address", a],
                         capture_output=True, text=True).stdout.strip().split("\n")[-1]
    m = re.match(r"(\w+) \+(\w+) (\w+)", e2m)
    values = ""
    if m:
        block, off = m.group(1), int(m.group(2), 16)
        for line in open(os.path.join(fw, "../e2m-analysis/CHR/CHR_CC_11.45.01.07.e2m"), errors="replace"):
            f = line.split(";")[0].split(",")
            if len(f) > 18 and f[2] == block and int(f[3], 16) == off:
                values = f[-1]
    lit = subprocess.run(["python3", "/home/linux/.claude/jobs/374b0424/tmp/w15/r19/source_values.py", cpp, n],
                         capture_output=True, text=True).stdout.strip().split("\n")[-1]
    literals = re.findall(r"'(?:==|!=|=)(\w+)'", lit)
    ok = bool(LIST.match(values)) and all(x in ("0", "1", "2") for x in literals)
    print(f"{'QUALIFIES' if ok else 'no       '} {a} {n} list={values!r} literals={sorted(set(literals))}")
