#!/bin/bash
# usage: dis.sh START END   (hex addresses in ROM)
ROM=/home/linux/code/kuminz-re/.claude/worktrees/cm848-egr-flow-delay/firmware/CM550_J90350.00_analysis/firmware/J90350.00.rom.bin
S=$(($1)); E=$(($2))
python3 -c "import sys;d=open('$ROM','rb').read();sys.stdout.write(' '.join('0x%02x'%b for b in d[$S:$E]))" | llvm-mc-18 --disassemble --triple=m68k --show-encoding 2>&1 | awk -v base=$S 'BEGIN{pc=base} /^\s*\.text/ {next} {print}'
