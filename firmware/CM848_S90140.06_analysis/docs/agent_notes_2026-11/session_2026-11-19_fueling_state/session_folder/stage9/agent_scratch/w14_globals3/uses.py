"""usage: uses.py NAME [context lines]  -> every cpp line using the NAME token, with its function"""
import re
import sys

CPP = '/home/linux/code/kuminz-re/.claude/worktrees/cm848-fueling-state-enum/firmware/CM848_S90140.06_analysis/output/cm848_rom.ghidra.cpp'
name = sys.argv[1]
ctx = int(sys.argv[2]) if len(sys.argv) > 2 else 0
lines = open(CPP, errors='replace').read().split('\n')
cur = ''
fn = []
for line in lines:
    m = re.match(r'// Function: (\S+) @', line)
    if m:
        cur = m.group(1)
    fn.append(cur)
pat = re.compile(r'(?<![A-Za-z0-9_])' + re.escape(name) + r'(?![A-Za-z0-9_])')
for i, line in enumerate(lines):
    if pat.search(line):
        print(f'--- {fn[i]} line {i + 1}')
        for j in range(max(0, i - ctx), min(len(lines), i + ctx + 1)):
            print(f'{j + 1}: {lines[j]}')
