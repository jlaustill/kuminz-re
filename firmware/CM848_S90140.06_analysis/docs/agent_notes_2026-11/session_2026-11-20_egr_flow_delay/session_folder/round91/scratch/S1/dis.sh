#!/bin/bash
# usage: dis.sh START END   (hex, CM550 ROM addresses)
ROM=/home/linux/code/kuminz-re/.claude/worktrees/cm848-egr-flow-delay/firmware/CM550_J90350.00_analysis/firmware/J90350.00.rom.bin
python3 -c "import sys;d=open('$ROM','rb').read();s=int(sys.argv[1],16);e=int(sys.argv[2],16);sys.stdout.write(' '.join('0x%02x'%b for b in d[s:e]))" "$1" "$2" \
  | llvm-mc-18 --disassemble --triple=m68k --show-encoding 2>&1 \
  | python3 -c "
import sys,re
pc=int(sys.argv[1],16)
for line in sys.stdin:
    line=line.rstrip()
    m=re.search(r'encoding: \[(.*)\]',line)
    if not m:
        if line.strip() and not line.strip().startswith('.text'):
            print('      ',line.strip())
        continue
    n=len(m.group(1).split(','))
    ins=line.split('#')[0].strip()
    print('%06x  %s'%(pc,ins))
    pc+=n
" "$1"
