#!/bin/bash
# Round 95: freeze the repository state the leads workflow reads (the .cpp and every CSV of both firmwares) into
# r94/frozen/{cm550,cm848}/, so later edits and builds in the worktree cannot change what the agents see.
# usage: freeze_r94.sh <repo>
set -euo pipefail
REPO=$(cd "$1" && pwd)
F=/home/linux/.claude/jobs/374b0424/tmp/w15/r96/frozen
rm -rf "$F"
mkdir -p "$F/cm550" "$F/cm848"
cp "$REPO"/firmware/CM550_J90350.00_analysis/output/J90350.00.ghidra.cpp "$REPO"/firmware/CM550_J90350.00_analysis/output/*.csv "$F/cm550/"
cp "$REPO"/firmware/CM848_S90140.06_analysis/output/cm848_rom.ghidra.cpp "$REPO"/firmware/CM848_S90140.06_analysis/output/*.csv "$F/cm848/"
git -C "$REPO" rev-parse --short HEAD > "$F/HEAD.txt"
ls "$F/cm550" | wc -l
ls "$F/cm848" | wc -l
