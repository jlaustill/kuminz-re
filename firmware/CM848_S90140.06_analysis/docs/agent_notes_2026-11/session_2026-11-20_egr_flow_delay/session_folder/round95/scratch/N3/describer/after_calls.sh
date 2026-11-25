#!/bin/sh
# usage: after_calls.sh <bytes after> <hex address>...  - disassembles from each address for <bytes after> bytes
ROM=/home/linux/code/kuminz-re/.claude/worktrees/cm848-egr-flow-delay/firmware/CM550_J90350.00_analysis/firmware/J90350.00.rom.bin
TOOL=/home/linux/.claude/jobs/374b0424/tmp/w15/r93/tools/m68k.py
span=$1
shift
for a in "$@"; do
  end=$(printf '%x' $((0x$a + span)))
  echo "---- $a"
  python3 "$TOOL" "$ROM" "$a" "$end"
done
