#!/bin/bash
# Round 96: the decompiler's failure reason for each CM550 function without an exported body (against the last build).
cd /tmp/kuminz-fwbuild-374b0424/firmware/CM550_J90350.00_analysis/ghidra || exit 1
for a in 0x103ba 0x16cd8 0x18dae 0x1e0bc 0x21642 0x2ee62; do
  echo "== $a"
  timeout 300 ./analyze.sh decompile $a 2>&1 | sed 's/\x1b\[[0-9;]*m//g' | grep -a "DecompileFunction.java>" | cut -c1-200
done
