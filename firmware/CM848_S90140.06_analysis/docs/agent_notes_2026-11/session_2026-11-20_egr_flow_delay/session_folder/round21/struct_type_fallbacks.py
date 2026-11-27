"""List the structure_definitions.csv field types that ApplyStructures.java does not know: getDataType falls back to
byte for them, so a 2-byte field silently becomes byte[2] (round 21: the i16 fields). usage: struct_type_fallbacks.py
<firmware dir>..."""
import csv
import os
import sys

KNOWN = {"byte", "word", "dword", "short", "ushort", "uint16_t", "uint32_t", "int", "uint", "undefined1", "undefined2",
         "undefined4", "undefined3", "ptr", "pointer"}
for fw in sys.argv[1:]:
    path = os.path.join(fw, "output", "structure_definitions.csv")
    rows = [r for r in csv.reader(open(path)) if r and not r[0].startswith("#") and r[0] != "struct_name"]
    structs = {r[0] for r in rows}
    enum_path = os.path.join(fw, "output", "enums.csv")
    enums = set()
    if os.path.exists(enum_path):
        enums = {r[0] for r in csv.reader(open(enum_path)) if r and not r[0].startswith("#")}
    bad = {}
    for r in rows:
        if len(r) < 4 or not r[2]:
            continue
        t = r[3].strip()
        if (t.startswith("bitfield") or t.endswith("*") or t.startswith("ptr:") or t.lower() in KNOWN or t in structs
                or t in enums):
            continue
        bad.setdefault(t, []).append(f"{r[0]}.{r[2]} ({r[4]} bytes)")
    print(os.path.basename(fw), "fallback types:", len(bad))
    for t, v in sorted(bad.items()):
        print(f"  {t!r}: {len(v)} fields, e.g. {v[:4]}")
