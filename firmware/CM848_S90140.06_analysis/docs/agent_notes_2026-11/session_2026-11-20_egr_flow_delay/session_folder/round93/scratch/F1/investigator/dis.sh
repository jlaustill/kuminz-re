#!/bin/bash
# usage: dis.sh <label> <start hex> <end hex> [...triples]   - CM550 CPU32 disassembly through the round's m68k.py
ROM=/home/linux/code/kuminz-re/.claude/worktrees/cm848-egr-flow-delay/firmware/CM550_J90350.00_analysis/firmware/J90350.00.rom.bin
TOOL=/home/linux/.claude/jobs/374b0424/tmp/w15/r93/tools/m68k.py
while [ $# -ge 3 ]; do
  echo "=== $1 $2-$3"
  python3 "$TOOL" "$ROM" "$2" "$3"
  shift 3
done
