"""Apply struct field renames, DELETE notes and new rows from aligned result files.
Usage: apply_extras.py <firmware_output_dir> <mapping_out.csv> <stage> <aligned result files...>

stage 1: struct field renames (kind "struct_field": struct / old / new) and their member-label rows
         ('<instance>.<field>' names in global_variables.csv); DELETE notes (kind "note", text
         "DELETE 0x<address> <name>: ..."): the row is removed and its name must match.
stage 2: new rows (kind "new_global": address / new / type / evidence), appended. The address must have no row,
         the name must be unused, the type one of byte / word / dword / i8 / i16 / i32 / word[N] / byte[N]. The
         comment is the evidence, cut at a word boundary, + "(new row <today>)".
Struct TYPE renames are rename_struct_types.py's job. Writes a mapping (address,name,old_label,kind)."""
import csv
import datetime
import json
import os
import re
import sys

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
from common import clip  # noqa: E402


OUT, MAP, STAGE = sys.argv[1], sys.argv[2], sys.argv[3]
FILES = [a for a in sys.argv[4:] if not a.startswith("--")]
records = [json.loads(l) for f in FILES for l in open(f) if l.strip()]
gv_path, sd_path = f"{OUT}/global_variables.csv", f"{OUT}/structure_definitions.csv"
gv = open(gv_path).read().split("\n")
mapping = []
names = {l.split(",")[1] for l in gv if l.startswith("0x") and len(l.split(",")) > 1}

if STAGE == "1":
    fields = [(r["struct"], r["old"], r["new"]) for r in records if r.get("kind") == "struct_field"]
    sd = open(sd_path).read().split("\n")
    for s, old, new in fields:
        pat = re.compile(rf"^{re.escape(s)},([^,]*),{re.escape(old)},")
        hits = [i for i, l in enumerate(sd) if pat.match(l)]
        assert len(hits) == 1, (s, old, len(hits))
        sd[hits[0]] = pat.sub(lambda m: f"{s},{m.group(1)},{new},", sd[hits[0]])
        mapping.append(("", new, old, "field"))
    instances = {}                      # struct -> instance names (rows typed with the struct)
    for l in gv:
        p = l.split(",", 3)
        if p[0].startswith("0x") and len(p) > 2:
            base = re.sub(r"\[\d+\]$", "", p[2])
            instances.setdefault(base, []).append(p[1])
    for i, l in enumerate(gv):          # member-label rows '<instance>.<field>'
        p = l.split(",", 3)
        if not p[0].startswith("0x") or "." not in p[1]:
            continue
        inst, field = p[1].split(".", 1)
        for s, old, new in fields:
            if inst in instances.get(s, []) and field == old:
                p[1] = f"{inst}.{new}"
                gv[i] = ",".join(p)
    deletes = set()
    for r in records:
        m = re.match(r"DELETE (0x[0-9a-fA-F]+) (\S+?):", r.get("text", "")) if r.get("kind") == "note" else None
        if m:
            deletes.add((int(m.group(1), 16), m.group(2)))
    keep = []
    removed = 0
    for l in gv:
        p = l.split(",", 2)
        if p[0].startswith("0x") and (int(p[0], 16), p[1]) in deletes:
            removed += 1
            mapping.append((p[0], "", p[1], "delete"))
            continue
        keep.append(l)
    assert removed == len(deletes), (removed, len(deletes))
    gv = keep
    open(sd_path, "w").write("\n".join(sd))
    print(f"fields {len(fields)}, deleted rows {removed}")
else:
    addresses = {int(l.split(",")[0], 16) for l in gv if l.startswith("0x")}
    new_rows = [r for r in records if r.get("kind") == "new_global"]
    tail = gv.pop() if gv and gv[-1] == "" else None
    seen = set()
    today = datetime.date.today().isoformat()
    for r in new_rows:
        a = int(r["address"], 16)
        assert a not in addresses and a not in seen, hex(a)
        assert r["new"] not in names, r["new"]
        assert re.fullmatch(r"(byte|word|dword|i8|i16|i32|word\[\d+\]|byte\[\d+\])", r["type"]), (r["new"], r["type"])
        seen.add(a)
        names.add(r["new"])
        comment = clip(" ".join((r.get("evidence") or "").split()))
        gv.append(f"0x{a:08x},{r['new']},{r['type']},{comment} (new row {today})")
        mapping.append((f"0x{a:08x}", r["new"], f"DAT_{a:08x}", "new row"))
    if tail is not None:
        gv.append(tail)
    print(f"new rows {len(new_rows)}")
open(gv_path, "w").write("\n".join(gv))
with open(MAP, "w", newline="") as f:
    w = csv.writer(f)
    w.writerow(["address", "name", "old_label", "kind"])
    for row in mapping:
        w.writerow(row)
