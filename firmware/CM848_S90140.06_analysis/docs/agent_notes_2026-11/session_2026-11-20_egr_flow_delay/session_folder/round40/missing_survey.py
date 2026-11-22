"""Round 40 survey: audit_cal_suffixes.py's MISSING rows (a name in the EEPROM mirror 0x3fd482-0x3feec1 or the
EEPROM itself without _cal), grouped: documentation rows (dotted / indexed: they inherit their instance's name), rows
in the boot kernel's time-shared ranges (0x3fd482-0x3fdb2f overlaps the kernel image window; 0x3fdba4-0x3fdc38 and
0x3fee08-0x3fee3f are documented time-shared), struct / array instances, and plain scalars; each with its .cpp
reference count and whether CM550 uses the same name.  usage: missing_survey.py <repo> <audit.txt> <out.tsv>"""
import os
import re
import sys

repo, audit, out = os.path.abspath(sys.argv[1]), sys.argv[2], sys.argv[3]
fw = os.path.join(repo, "firmware")
rows = {}
for l in open(os.path.join(fw, "CM848_S90140.06_analysis/output/global_variables.csv"), errors="replace"):
    p = l.split(",", 3)
    if len(p) >= 3 and p[0].startswith("0x"):
        rows.setdefault(p[1], (p[0], p[2], p[3].strip() if len(p) > 3 else ""))
cpp = open(os.path.join(fw, "CM848_S90140.06_analysis/output/cm848_rom.ghidra.cpp"), errors="replace").read()
cm550 = ""
d550 = os.path.join(fw, "CM550_J90350.00_analysis/output")
for fn in os.listdir(d550):
    if fn.endswith(".csv"):
        cm550 += open(os.path.join(d550, fn), errors="replace").read()
sec, missing = None, []
for l in open(audit):
    if l.startswith("==="):
        sec = l.split()[1]
        continue
    m = re.match(r"\s+(0x[0-9a-f]+)\s+(\S+)\s+(\S+)", l)
    if m and sec == "MISSING":
        missing.append((m.group(1), m.group(2), m.group(3)))
groups = {}
with open(out, "w") as fh:
    for a, region, name in missing:
        addr, typ, comment = rows.get(name, (a, "?", ""))
        ai = int(a, 16)
        if "." in name or "[" in name:
            g = "documentation"
        elif 0x3fee08 <= ai <= 0x3fee3f or 0x3fdba4 <= ai <= 0x3fdc38:
            g = "time-shared"
        elif 0x3fd482 <= ai < 0x3fdb30:
            g = "kernel-window"
        elif typ in ("byte", "word", "dword", "i16", "i32", "pointer", "undefined1") or typ.endswith("_STATE") or typ.isupper():
            g = "scalar"
        else:
            g = "instance"
        refs = len(re.findall(r"\b" + re.escape(name) + r"\b", cpp))
        shared = "CM550" if re.search(r"\b" + re.escape(name) + r"\b", cm550) else ""
        groups.setdefault(g, []).append(name)
        fh.write("\t".join([a, g, typ, name, str(refs), shared, comment[:110]]) + "\n")
for g, ns in groups.items():
    print(f"{g}: {len(ns)}")
