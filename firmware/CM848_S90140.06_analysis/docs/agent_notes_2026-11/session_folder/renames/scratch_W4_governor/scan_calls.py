import json
import re

ROOT = '/home/linux/code/kuminz-re/.claude/worktrees/cm848-typing-arrays/'
CPP = ROOT + 'firmware/CM848_S90140.06_analysis/output/cm848_rom.ghidra.cpp'
RESULT = '/home/linux/.claude/jobs/d55ae3c6/tmp/renames/result_W4_governor.jsonl'

names = {}
for raw in open(RESULT):
    row = json.loads(raw)
    if row['kind'] in ('global', 'new_global') and 'address' in row:
        value = int(row['address'], 16)
        if 0x3f9800 <= value <= 0x3fdb30 or 0x3fee08 <= value <= 0x3fee3d:
            names[row.get('old') or ('DAT_%08x' % value)] = value

patterns = {}
for name, value in names.items():
    patterns[name] = re.compile(r'(?<![A-Za-z0-9_])_?' + re.escape(name) + r'\s*\(')
    patterns['func_0x%08x' % value] = re.compile(r'func_0x%08x|FUN_%08x' % (value, value))

current = None
found = {}
with open(CPP) as handle:
    for number, line in enumerate(handle, 1):
        match = re.match(r'^// Function: (\S+) @ (0x[0-9a-f]+)', line)
        if match:
            current = (match.group(1), match.group(2))
            continue
        for name, pattern in patterns.items():
            if pattern.search(line):
                found.setdefault(name, []).append((number, current))
print('window names checked:', len(names))
for name, hits in sorted(found.items()):
    print(name, len(hits), [(n, c[0], c[1]) for n, c in hits[:3]])
print('done')
