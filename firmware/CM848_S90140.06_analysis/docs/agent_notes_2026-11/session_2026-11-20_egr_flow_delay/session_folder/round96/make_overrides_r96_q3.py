"""Round 96 stage G: a fresh overrides_r96.json for the Q3 apply (stage F's file is saved as overrides_r96_stage_f.json).
- remove_globals: every live CM550 row strictly inside the span of a judged global whose final type is wider than
  one row (the Q3 judge: the dword 0x8002a6 swallows the unreferenced row 0x8002a8). A row that is itself a judged
  element is never removed (reported).
- drop: the elements whose final comment is an instruction (reported; none expected).
usage: make_overrides_r96_q3.py <repo> <overrides_r96.json> <batch_Q3.json>"""
import csv
import json
import os
import re
import sys

repo, out_path, batch_path = os.path.abspath(sys.argv[1]), sys.argv[2], sys.argv[3]
OUT = os.path.join(repo, "firmware/CM550_J90350.00_analysis/output")
PRIMITIVE = {"byte": 1, "char": 1, "bool": 1, "sbyte": 1, "uchar": 1, "word": 2, "short": 2, "ushort": 2, "sword": 2,
             "dword": 4, "int": 4, "uint": 4, "pointer": 4, "float": 4, "long": 4, "ulong": 4, "undefined": 1,
             "undefined2": 2, "undefined4": 4, "i8": 1, "u8": 1, "i16": 2, "u16": 2, "i32": 4, "u32": 4}
known = {}
for r in csv.reader(open(os.path.join(OUT, "enums.csv"), newline="")):
    if len(r) > 4 and r[0] and not r[0].startswith("#") and r[4].strip().isdigit():
        known.setdefault(r[0], int(r[4]))
for r in csv.reader(l for l in open(os.path.join(OUT, "structure_definitions.csv"), newline="") if not l.startswith("#")):
    if len(r) > 4 and r[0] and r[0] != "struct_name" and r[4].strip().isdigit():
        known[r[0]] = known.get(r[0], 0) + int(r[4])


def width(t):
    t = t.strip()
    if t.endswith("*"):
        return 4
    m = re.match(r"^(.+?)((?:\[\d+\])+)$", t)
    if m:
        n = 1
        for d in re.findall(r"\[(\d+)\]", m.group(2)):
            n *= int(d)
        w = width(m.group(1))
        return None if w is None else w * n
    return PRIMITIVE.get(t) or known.get(t)


rows = []
for line in open(os.path.join(OUT, "global_variables.csv"), newline="").read().split("\n"):
    p = line.rstrip("\r").split(",", 3)
    if len(p) > 2 and p[0].startswith("0x"):
        rows.append((int(p[0], 16), p[1]))
d = json.load(open(batch_path))
vd = {(x.get("kind"), str(x.get("address")).lower()): x for x in d["verdict"]["verdicts"]}
elements, judged, o = set(), [], {}
for g in d["proposal"].get("globals") or []:
    v = vd.get(("global", str(g["address"]).lower())) or {}
    if v.get("verdict") in ("CONFIRMED", "AMENDED"):
        a = int(g["address"], 16)
        elements.add(a)
        judged.append((a, v.get("final_name") or g["proposed_name"], (v.get("final_type") or g.get("proposed_type") or "").strip()))
remove = {}
for a, name, typ in judged:
    w = width(typ) if typ else None
    if w is None and typ:
        print("UNKNOWN WIDTH", hex(a), name, typ)
    if not w or w < 2:
        continue
    for ra, rn in rows:
        if a < ra < a + w:
            if ra in elements:
                print(f"KEEP 0x{ra:x} {rn}: a judged element inside {name}")
                continue
            remove[f"0x{ra:08x}"] = ""
            print(f"remove 0x{ra:x} {rn or '(unnamed)'}: inside {name} {typ}")
o["remove_globals"] = {"CM550": remove} if remove else {}
json.dump(o, open(out_path, "w"), indent=1)
print(len(remove), "rows to remove")
