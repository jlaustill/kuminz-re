"""Round 95 (read-only): the final types and enums in the judged batches that the firmware CSVs do not define yet
(each needs a structs / new_enums override before the apply). usage: unknown_types_r95.py <repo> <batch.json>..."""
import collections
import csv
import json
import os
import re
import sys

repo = os.path.abspath(sys.argv[1])
PRIMITIVE = {"byte", "sbyte", "char", "uchar", "word", "short", "ushort", "dword", "int", "uint", "long", "ulong",
             "bool", "i16", "u16", "i32", "u32", "pointer", "undefined", "undefined1", "undefined2", "undefined4", "i8",
             "u8", "sword", "sdword", "float"}
known = {}
for fw, d in (("CM550", "firmware/CM550_J90350.00_analysis/output"), ("CM848", "firmware/CM848_S90140.06_analysis/output")):
    k = set(PRIMITIVE)
    for r in csv.reader(open(os.path.join(repo, d, "enums.csv"), newline="")):
        if r and r[0] and not r[0].startswith("#"):
            k.add(r[0])
    for r in csv.reader(l for l in open(os.path.join(repo, d, "structure_definitions.csv"), newline="") if not l.startswith("#")):
        if r and r[0]:
            k.add(r[0])
    known[fw] = k
unknown = collections.defaultdict(list)
for path in sys.argv[2:]:
    d = json.load(open(path))
    b = d["batch"]
    vd = {}
    for x in d["verdict"]["verdicts"]:
        vd[(x.get("kind"), str(x.get("address")).lower())] = x
    for g in d["proposal"].get("globals") or []:
        fw = g.get("firmware") or "CM550"
        v = vd.get(("global", str(g["address"]).lower())) or {}
        t = (v.get("final_type") or g.get("proposed_type") or g.get("type") or "").strip()
        base = re.sub(r"(\s*\[\d+\])+$", "", t).strip().rstrip("*").strip()
        if base and base not in known[fw]:
            unknown[(fw, base)].append(f"{b} {g['address']}")
    for e in d["proposal"].get("enum_members") or []:
        fw = e.get("firmware") or "CM550"
        for f in (["CM550", "CM848"] if fw == "both" else [fw]):
            if e["enum_name"] not in known[f]:
                unknown[(f, "enum " + e["enum_name"])].append(f"{b} {e.get('value')}")
for k, v in sorted(unknown.items()):
    print(k, len(v), v[:6])
print("done;", len(unknown), "unknown")
