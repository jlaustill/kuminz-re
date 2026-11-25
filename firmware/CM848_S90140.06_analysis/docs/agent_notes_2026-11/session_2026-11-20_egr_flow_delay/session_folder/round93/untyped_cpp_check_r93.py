"""Round 93 (read-only): the second witness for the untyped-row width scan - the decompiler. For each CANDIDATE of
untyped_width_scan_r93.tsv, how the current .cpp prints the row in code (comments removed): with a leading underscore
(the code reads more than the 1 byte an 'undefined' row has) or plain. A word / dword candidate passes when it prints
only with the underscore; a byte candidate when it prints only plain. Also drops dword candidates whose ROM accesses
include a movea.l load (a pointer: its type should name the pointee). Writes the rows that pass as
address,name,type. usage: untyped_cpp_check_r93.py <repo> <scan.tsv> <out.csv>"""
import csv
import os
import re
import sys

repo, scan, out = os.path.abspath(sys.argv[1]), sys.argv[2], sys.argv[3]
cpp = open(os.path.join(repo, "firmware/CM550_J90350.00_analysis/output/J90350.00.ghidra.cpp"), errors="replace").read()
code = re.sub(r"/\*.*?\*/", " ", cpp, flags=re.S)
code = "\n".join(l for l in code.split("\n") if not l.lstrip().startswith("//"))
words = {}
for m in re.finditer(r"[A-Za-z_][A-Za-z0-9_]*", code):
    words[m.group(0)] = words.get(m.group(0), 0) + 1
rom = open(os.path.join(repo, "firmware/CM550_J90350.00_analysis/firmware/J90350.00.rom.bin"), "rb").read()


def pointer_load(a):
    pat = a.to_bytes(4, "big")
    i = rom.find(pat)
    while i != -1:
        if i % 2 == 0 and i >= 2:
            w = int.from_bytes(rom[i - 2:i], "big")
            if (w & 0xf1ff) == 0x2079:          # movea.l (abs).l,An
                return True
        i = rom.find(pat, i + 1)
    return False


passed, why = [], {}
for r in csv.DictReader(open(scan), delimiter="\t"):
    if r["verdict"] != "CANDIDATE":
        continue
    name, typ = r["name"], r["width"]
    under, plain = words.get("_" + name, 0), words.get(name, 0)
    if typ == "byte":
        ok, reason = (plain > 0 and under == 0), "byte row printed with an underscore" if under else "not in the code"
    else:
        ok, reason = (under > 0 and plain == 0), "printed plain somewhere" if plain else "not in the code"
        if ok and typ == "dword" and pointer_load(int(r["address"], 16)):
            ok, reason = False, "pointer (movea.l load)"
    if ok:
        passed.append((r["address"], name, typ, under + plain))
    else:
        why[reason] = why.get(reason, 0) + 1
with open(out, "w") as fh:
    fh.write("address,name,type,renders\n")
    for row in passed:
        fh.write(",".join(str(x) for x in row) + "\n")
by = {}
for _, _, t, n in passed:
    by.setdefault(t, [0, 0])
    by[t][0] += 1
    by[t][1] += n
print("passed:", {t: f"{v[0]} rows / {v[1]} renders" for t, v in by.items()}, "| dropped:", why)
