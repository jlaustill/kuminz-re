#!/bin/bash
# usage: w3_governor_pf.sh <function name> [max lines]
# prints a decompiled function body from the CM848 .cpp (read-only helper)
F=/home/linux/code/kuminz-re/.claude/worktrees/cm848-typing-arrays/firmware/CM848_S90140.06_analysis/output/cm848_rom.ghidra.cpp
awk -v name="$1" 'BEGIN{p=0} /^\/\/ Function: /{ if (index($0, "// Function: " name " @")==1) p=1; else if (p) exit } p{print}' "$F" | head -"${2:-80}"
