#!/bin/bash
# Round 97: frozen copies of both firmwares' decompilations and CSV inputs at HEAD for the workflow's agents (they read
# these while the worktree changes under them), the same file set as round 96's frozen/.
set -euo pipefail
REPO=/home/linux/code/kuminz-re/.claude/worktrees/cm848-egr-flow-delay
R=/home/linux/.claude/jobs/374b0424/tmp/w15/r97
mkdir -p "$R/frozen/cm550" "$R/frozen/cm848" "$R/scratch"
for f in $(ls /home/linux/.claude/jobs/374b0424/tmp/w15/r96/frozen/cm550); do
  if [ -f "$REPO/firmware/CM550_J90350.00_analysis/output/$f" ]; then cp "$REPO/firmware/CM550_J90350.00_analysis/output/$f" "$R/frozen/cm550/"; fi
done
for f in $(ls /home/linux/.claude/jobs/374b0424/tmp/w15/r96/frozen/cm848); do
  if [ -f "$REPO/firmware/CM848_S90140.06_analysis/output/$f" ]; then cp "$REPO/firmware/CM848_S90140.06_analysis/output/$f" "$R/frozen/cm848/"; fi
done
git -C "$REPO" rev-parse HEAD > "$R/frozen/HEAD.txt"
ls "$R/frozen/cm550" | wc -l
ls "$R/frozen/cm848" | wc -l
cat "$R/frozen/HEAD.txt"
