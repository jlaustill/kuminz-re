#!/bin/bash
# Round 51 stage A proof (labels / rows only): rename the one renamed function in the OLD .cpp first (prove_caches.py
# keys on function names), strip the scalar casts and fold the two char literals in both copies (a typed new row
# replacing an untyped DAT_ render moves casts), then run the label-only proof (prove_caches.py: DAT_ renders -> the
# new names, old names -> new).
# usage: prove_r51a.sh <old.cpp> <new.cpp> <globals map.csv>
set -euo pipefail
W=/home/linux/.claude/jobs/374b0424/tmp/w15/r51
sed -e 's/\bsensorDiagnosticsConfiguration\b/cm848_flagTripInformationPowerDownDataLoss/g' "$1" > "$W/old_renamed.cpp"
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
python3 /home/linux/.claude/jobs/374b0424/tmp/w15/r37/prove_caches.py "$W/old_stripped.cpp" "$W/new_stripped.cpp" "$3"
