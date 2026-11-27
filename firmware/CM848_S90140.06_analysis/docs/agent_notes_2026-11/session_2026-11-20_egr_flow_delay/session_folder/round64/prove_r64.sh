#!/bin/bash
# Round 64 label proof (prove_r62.sh with W at r63); round 62: (prove_r56.sh, path changed):
# - the per-function parameter renames (params.csv: function,old,new), applied only inside that function's block of
#   the OLD .cpp after the function renames;
# - a count of piece renders (instance._N_M_) and underscore renders (_instance) of the struct instances' bare names,
#   which prove_caches.py's own piece count misses for dotted map names.
# usage: prove_r56.sh <old.cpp> <new.cpp> <map.csv> <params.csv>
set -euo pipefail
W=/home/linux/.claude/jobs/374b0424/tmp/w15/r64
python3 - "$1" "$3" "$W/old_renamed.cpp" "$W/map_globals.csv" "$4" <<'EOF'
import csv, re, sys
old, mapping, out, globals_out, params = sys.argv[1:6]
t = open(old, errors="replace").read()
rows = list(csv.DictReader(open(mapping)))
for r in rows:
    if r["kind"] == "function":
        t = re.sub(rf"\b{re.escape(r['old_label'])}\b", r["name"], t)
for p in csv.DictReader(open(params)):
    i = t.index(f"// Function: {p['function']} @")
    j = t.find("// Function: ", i + 10)
    j = len(t) if j == -1 else j
    t = t[:i] + re.sub(rf"\b{re.escape(p['old'])}\b", p["new"], t[i:j]) + t[j:]
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
python3 - "$2" "$3" <<'EOF'
import csv, re, sys
t = open(sys.argv[1], errors="replace").read()
names = sorted({r["name"].split(".")[0] for r in csv.DictReader(open(sys.argv[2])) if "." in r["name"]})
bad = {n: len(re.findall(rf"\b{re.escape(n)}\._\d+_\d+_|(?<![\w.])_{re.escape(n)}\b", t)) for n in names}
print(f"struct instances {len(names)}; piece or underscore renders: {sum(bad.values())}",
      {k: v for k, v in bad.items() if v} or "")
EOF
