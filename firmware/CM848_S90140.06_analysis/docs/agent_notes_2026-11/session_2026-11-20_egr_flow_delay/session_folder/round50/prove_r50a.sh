#!/bin/bash
# Round 50 stage A proof: typed new rows replace untyped DAT_ renders, which moves casts and turns char literals
# ('\0', '\x01') into integers. Strip the scalar casts and fold the two char literals in both .cpp copies, then run the
# label-only proof (prove_caches.py: DAT_ renders -> the new names, old names -> new).
# usage: prove_r50a.sh <old.cpp> <new.cpp> <map.csv>
set -euo pipefail
W=/home/linux/.claude/jobs/374b0424/tmp/w15/r50
for pair in "$1:$W/old_stripped.cpp" "$2:$W/new_stripped.cpp"; do
    python3 - "${pair%%:*}" "${pair##*:}" <<'EOF'
import re, sys
t = open(sys.argv[1], errors="replace").read()
t = re.sub(r"\((short|ushort|int|uint|word|dword|undefined1|undefined2|undefined4|char|uchar|byte|longlong|ulonglong)\)",
           "", t)
t = t.replace("'\\0'", "0").replace("'\\x01'", "1")
open(sys.argv[2], "w").write(t)
EOF
done
python3 /home/linux/.claude/jobs/374b0424/tmp/w15/r37/prove_caches.py "$W/old_stripped.cpp" "$W/new_stripped.cpp" "$3"
