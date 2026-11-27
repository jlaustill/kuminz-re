#!/bin/bash
# usage: dis848.sh <function|0xADDR> [...]   - CM848 PowerPC disassembly through firmware/scripts/disasm_func.py
cd /home/linux/code/kuminz-re/.claude/worktrees/cm848-egr-flow-delay/firmware || exit 1
for f in "$@"; do
  python3 scripts/disasm_func.py "$f" 2>&1 | grep -v "file format binary" | grep -v "^$" | grep -v "Disassembly of section"
done
