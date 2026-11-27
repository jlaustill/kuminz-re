#!/bin/bash
# Round 48 stage A proof: new i16 rows and three word -> i16 retypes move casts, so strip the scalar casts from both
# .cpp copies, then run the label-only proof (prove_caches.py: DAT_ renders -> the new names, old names -> new).
# usage: prove_r48a.sh <old.cpp> <new.cpp> <map.csv>
set -euo pipefail
W=/home/linux/.claude/jobs/374b0424/tmp/w15/r48
CAST='s/\((short|ushort|int|uint|word|dword|undefined2|undefined4|char|uchar|byte|longlong|ulonglong)\)//g'
sed -E "$CAST" "$1" > "$W/old_stripped.cpp"
sed -E "$CAST" "$2" > "$W/new_stripped.cpp"
python3 /home/linux/.claude/jobs/374b0424/tmp/w15/r37/prove_caches.py "$W/old_stripped.cpp" "$W/new_stripped.cpp" "$3"
