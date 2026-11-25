"""Round 95 (read-only): what CM848's hwregs stage (ApplyMPC555Registers) would do if it ran, per mpc555_registers.csv
row, and whether the code references the address. The stage skips a row when a named symbol sits at its address;
otherwise it creates the label, clears the code units over the register and creates u16 / u8 data (which splits any
data item that covers the address). Coverage = a typed global row's span (struct / array / enum / primitive width) or
a structure_definitions.csv instance (its first-field address or a marker row) with the struct's size.
References: the .cpp's DAT_ / _DAT_ / uRam / UNK_ / ram0x / PTR_ forms of the address, or a raw 0x<address> constant.
usage: register_stage_preview_r95.py <repo> [--list]"""
import csv
import os
import re
import sys

repo = os.path.abspath(sys.argv[1])
out = os.path.join(repo, "firmware/CM848_S90140.06_analysis/output")
PRIMITIVE = {"byte": 1, "char": 1, "bool": 1, "i8": 1, "u8": 1, "word": 2, "i16": 2, "u16": 2, "short": 2,
             "ushort": 2, "dword": 4, "i32": 4, "u32": 4, "int": 4, "uint": 4, "float": 4, "pointer": 4,
             "qword": 8, "double": 8, "undefined": 1, "": 1}
enums, structs, instances = {}, {}, []
for r in csv.reader(open(os.path.join(out, "enums.csv"), newline="")):
    if len(r) > 4 and r[0] and not r[0].startswith("#") and r[4].strip().isdigit():
        enums.setdefault(r[0], int(r[4]))
for r in csv.reader(l for l in open(os.path.join(out, "structure_definitions.csv"), newline="") if not l.startswith("#")):
    if len(r) > 4 and r[0] and r[0] != "struct_name":
        if r[4].strip().isdigit():
            structs[r[0]] = structs.get(r[0], 0) + int(r[4])
        if r[1].strip().startswith("0x"):
            instances.append((int(r[1], 16), r[0]))


def width(t):
    t = t.strip()
    if t.endswith("*"):
        return 4
    m = re.match(r"^(.+?)((\[\d+\])+)$", t)
    if m:
        n = 1
        for d in re.findall(r"\[(\d+)\]", m.group(2)):
            n *= int(d)
        w = width(m.group(1))
        return None if w is None else w * n
    return PRIMITIVE.get(t, enums.get(t, structs.get(t)))


spans = []
named = {}
for line in open(os.path.join(out, "global_variables.csv"), newline="").read().split("\n"):
    parts = line.rstrip("\r").split(",", 3)
    if len(parts) > 2 and parts[0].startswith("0x"):
        a = int(parts[0], 16)
        if parts[1]:
            named[a] = parts[1]
        w = width(parts[2]) or 1
        if w > 1:
            spans.append((a, a + w, parts[1] or parts[2]))
for a, s in set(instances):
    if s in structs:
        spans.append((a, a + structs[s], f"{s} instance"))
cpp = open(os.path.join(out, "cm848_rom.ghidra.cpp"), errors="replace").read()
REFS = {}
for m in re.finditer(r"(?:DAT_|uRam|UNK_|ram0x|BYTE_|WORD_)00(3[0-9a-f]{5}|2f[c-f][0-9a-f]{3})\b|\b0x(3[0-9a-f]{5}|2f[c-f][0-9a-f]{3})\b", cpp, re.I):
    a = int(m.group(1) or m.group(2), 16)
    REFS[a] = REFS.get(a, 0) + 1
rows = []
for r in csv.reader(l for l in open(os.path.join(out, "mpc555_registers.csv"), newline="") if not l.startswith("#")):
    if r and r[0].startswith("0x"):
        rows.append((int(r[0], 16), r[1], r[2] if len(r) > 2 else ""))
result = {}
for a, n, t in rows:
    if a in named:
        kind = "SKIPPED"
        detail = named[a]
    else:
        cover = [s for s in spans if s[0] < a < s[1] or (s[0] == a and s[1] - s[0] > 1)]
        if cover:
            kind, detail = "SPLITS", cover[0][2]
        else:
            kind, detail = "APPLIES", ""
    refs = REFS.get(a, 0)
    result.setdefault(kind, []).append((a, n, t, detail, refs))
for k, v in result.items():
    print(f"{k}: {len(v)} (referenced in the .cpp: {sum(1 for x in v if x[4])})")
if "--list" in sys.argv:
    for k in ("APPLIES", "SPLITS"):
        for a, n, t, d, refs in result.get(k, []):
            print(f"  {k:8s} 0x{a:06x} {n:30s} {t:5s} refs {refs:3d} {d}")
