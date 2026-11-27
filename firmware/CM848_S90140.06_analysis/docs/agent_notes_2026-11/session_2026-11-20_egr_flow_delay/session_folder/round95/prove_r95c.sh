#!/bin/bash
# Round 95 stage C proofs (the batches N1-N3 + the post-apply edits): per firmware the function set, the token diff
# with the combined map (the apply's map, its underscore variants, the 0x2efd0 hand rename, the INSITE_PARAM_CODE
# member), the census classification, statement counts, caller census, piece census, old names in code, the render
# check; then the overlap check. Base = HEAD 699816aa (stage B). usage: FIRMWARES="cm550 cm848" prove_r94e.sh <repo>
set -uo pipefail
REPO=$(cd "$1" && pwd)
W=/home/linux/.claude/jobs/374b0424/tmp/w15
PC=$REPO/firmware/CM848_S90140.06_analysis/docs/agent_notes_2026-11/session_2026-11-17_p0500/session_folder/wave11/piece_census.py
OUT=$W/r95/proof_r95c
mkdir -p "$OUT"
for fw in ${FIRMWARES:-cm550 cm848}; do
    if [ $fw = cm550 ]; then POST=$REPO/firmware/CM550_J90350.00_analysis/output/J90350.00.ghidra.cpp
    else POST=$REPO/firmware/CM848_S90140.06_analysis/output/cm848_rom.ghidra.cpp; fi
    PRE=$W/r95/base_r95c_$fw.cpp
    MAP=$OUT/map_r95c_$fw.csv
    python3 - "$W/r95/apply_out/map_r94_$fw.csv" "$W/r95/map_r95c_hand_$fw.csv" "$MAP" <<'EOF'
import sys
rows = []
for path in sys.argv[1:3]:
    lines = open(path).read().splitlines()
    rows += [l for l in lines[1:] if l.strip()]
out = list(rows)
for r in rows:                      # the underscore variants (an old row read wider than its type)
    p = r.split(",")
    if len(p) >= 3 and p[2] and p[2][0].islower():
        out.append(",".join([p[0], p[1], "_" + p[2]] + p[3:]))
open(sys.argv[3], "w").write("address,name,old_label,kind,dims\n" + "\n".join(out) + "\n")
EOF
    echo "######## $fw ($(grep -c '^// Function: ' "$POST") functions; base $(grep -c '^// Function: ' "$PRE"))"
    python3 $W/r84/function_set_check.py "$PRE" "$POST" "$MAP" > "$OUT/function_set_$fw.txt" 2>&1
    head -3 "$OUT/function_set_$fw.txt"
    python3 $W/r87/token_diff.py "$PRE" "$POST" "$MAP" > "$OUT/token_diff_$fw.txt" 2>&1
    echo "-- token diff: $(grep -c ': [0-9]* token changes' "$OUT/token_diff_$fw.txt") functions with unmapped changes"
    python3 $W/r94/classify_census_r94.py "$OUT/token_diff_$fw.txt" "$MAP" | grep "^=="
    python3 $W/r93/line_count_diff_r93.py "$PRE" "$POST" > "$OUT/line_count_$fw.txt" 2>&1
    echo "-- statements: $(grep 'functions with a different statement count' "$OUT/line_count_$fw.txt")"
    grep "^0x" "$OUT/line_count_$fw.txt" | head -12
    python3 $W/r86/caller_census.py "$PRE" "$POST" "$OUT/function_set_$fw.txt" > "$OUT/caller_census_$fw.txt" 2>&1
    tail -2 "$OUT/caller_census_$fw.txt"
    python3 "$PC" "$PRE" "$POST" > "$OUT/piece_census_$fw.txt" 2>&1
    echo "-- pieces:"; tail -5 "$OUT/piece_census_$fw.txt"
    python3 $W/r94/old_names_in_code_r94.py "$POST" "$MAP" | head -8
    python3 $W/r94/render_check_r94.py "$POST" "$W/r95/apply_out/map_r94_$fw.csv" > "$OUT/render_check_$fw.txt"
    echo "-- render: $(head -1 "$OUT/render_check_$fw.txt"); new names not rendering: $(grep -c 'new renders False' "$OUT/render_check_$fw.txt")"
done
python3 $W/r94/overlap_check_r94.py "$REPO" --since HEAD | cut -c1-200
