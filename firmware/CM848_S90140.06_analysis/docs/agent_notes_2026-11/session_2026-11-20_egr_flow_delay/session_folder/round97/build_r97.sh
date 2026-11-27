#!/bin/bash
# Round 97: sync the worktree's output/ and scripts/ into the build copy, then './analyze.sh verify' (two builds,
# byte-identical) CM550 then CM848, with a one-line summary each. usage: build_r97.sh <repo> <stage letter>
REPO=$(cd "$1" && pwd)
S=$2
W=/home/linux/.claude/jobs/374b0424/tmp/w15/r97
C=/tmp/kuminz-fwbuild-374b0424/firmware
rsync -a --exclude project "$REPO/firmware/scripts/" "$C/scripts/"
for fw in CM550_J90350.00_analysis CM848_S90140.06_analysis; do
    rsync -a --exclude project "$REPO/firmware/$fw/output/" "$C/$fw/output/"
done
for pair in cm550:CM550_J90350.00_analysis cm848:CM848_S90140.06_analysis; do
    f=${pair%%:*}
    d=${pair#*:}
    (cd "$C/$d/ghidra" && ./analyze.sh verify > "$W/verify_r97${S}_$f.log" 2>&1)
    echo "$f exit $?"
done
for f in cm550 cm848; do
    L=$W/verify_r97${S}_$f.log
    v=$(sed 's/\x1b\[[0-9;]*m//g' "$L" | grep -o "DETERMINISTIC[^|]*\|NOT DETERMINISTIC[^|]*" | tail -1)
    imp=$(sed 's/\x1b\[[0-9;]*m//g' "$L" | grep -oi "[0-9]* functions\? imports\? failed" | tail -1)
    err=$(sed 's/\x1b\[[0-9;]*m//g' "$L" | grep -ci "script error\|SCRIPT ERROR")
    echo "$f: $v | import failures: ${imp:-0} | script error lines: $err"
done
