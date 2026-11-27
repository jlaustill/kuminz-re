#!/bin/bash
# Round 96: disassemble CM550 ROM bytes with llvm-mc (m68k, cpu 68020). usage: m68k_dis_r96.sh <hex start> <byte count>
ROM=/home/linux/code/kuminz-re/.claude/worktrees/cm848-egr-flow-delay/firmware/CM550_J90350.00_analysis/firmware/J90350.00.rom.bin
python3 -c "
import sys
b = open('$ROM', 'rb').read()[int('$1', 16):int('$1', 16) + int('$2')]
print(' '.join('0x%02x' % x for x in b))
" | llvm-mc-18 --disassemble --triple=m68k -mcpu=M68020 --show-encoding 2>&1 | grep -v "^\s*\.text" | head -${3:-60}
