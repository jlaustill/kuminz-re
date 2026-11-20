#!/bin/bash
# usage: g.sh <symbol> [context]  - grep the cpp for symbol with function names
CPP=/home/linux/code/kuminz-re/.claude/worktrees/cm848-fueling-state-enum/firmware/CM848_S90140.06_analysis/output/cm848_rom.ghidra.cpp
python3 - "$CPP" "$1" "${2:-0}" <<'PY'
import re,sys
cpp,sym,ctx=sys.argv[1],sys.argv[2],int(sys.argv[3])
lines=open(cpp,errors='replace').read().split('\n')
fn=''
fnat=[]
for l in lines:
    m=re.match(r'// Function: (\S+) @ (\S+)',l)
    if m: fn=m.group(1)+'@'+m.group(2)
    fnat.append(fn)
pat=re.compile(r'(?<![A-Za-z0-9_])'+re.escape(sym)+r'(?![A-Za-z0-9_])')
last=-10
for i,l in enumerate(lines):
    if pat.search(l):
        lo=max(0,i-ctx); hi=min(len(lines),i+ctx+1)
        if ctx and i-last>2*ctx+1: print('   ---')
        for j in range(lo,hi):
            print('%d [%s]: %s'%(j+1,fnat[j],lines[j]))
        last=i
PY
