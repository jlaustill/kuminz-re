#!/bin/bash
# Round 53 label proof: apply the map's function renames to the OLD .cpp (prove_caches.py keys on function names),
# strip the scalar casts and fold the two char literals in both copies (a typed new row replacing an untyped DAT_
# render moves casts), then run prove_caches.py with the map's global entries (old labels -> new names).
# usage: prove_r53.sh <old.cpp> <new.cpp> <map.csv>
set -euo pipefail
W=/home/linux/.claude/jobs/374b0424/tmp/w15/r54
python3 - "$1" "$3" "$W/old_renamed.cpp" "$W/map_globals.csv" <<'EOF'
import csv, re, sys
old, mapping, out, globals_out = sys.argv[1:5]
t = open(old, errors="replace").read()
rows = list(csv.DictReader(open(mapping)))
for r in rows:
    if r["kind"] == "function":
        t = re.sub(rf"\b{re.escape(r['old_label'])}\b", r["name"], t)
open(out, "w").write(t)
with open(globals_out, "w") as fh:
    fh.write("address,name,old_label,kind,dims\n")
    for r in rows:
        if r["kind"] != "function":
            fh.write(f"{r['address']},{r['name']},{r['old_label']},{r['kind']},{r['dims']}\n")
EOF
for pair in "$W/old_renamed.cpp:$W/old_stripped.cpp" "$2:$W/new_stripped.cpp"; do
    python3 - "${pair%%:*}" "${pair##*:}" <<'EOF'
import re, sys
t = open(sys.argv[1], errors="replace").read()
t = re.sub(r"\((short|ushort|int|uint|word|dword|undefined1|undefined2|undefined4|char|uchar|byte|longlong|ulonglong)\)",
           "", t)
t = t.replace("'\\0'", "0").replace("'\\x01'", "1")
open(sys.argv[2], "w").write(t)
EOF
done
python3 /home/linux/.claude/jobs/374b0424/tmp/w15/r37/prove_caches.py "$W/old_stripped.cpp" "$W/new_stripped.cpp" "$W/map_globals.csv"
