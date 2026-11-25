# Tabulate the executive frame handler's cases: for each case (frame) list its bl targets in order.
import re, subprocess, sys
out = subprocess.run(['python3', 'scripts/disasm_func.py', '0xc0a0'], capture_output=True, text=True,
                     cwd='/home/linux/code/kuminz-re/.claude/worktrees/cm848-egr-flow-delay/firmware').stdout
lines = out.splitlines()
table = []
for l in lines:
    m = re.match(r'\s+([0-9a-f]+):\s+(?:[0-9a-f]{2} ){4}\s*b\s+0x([0-9a-f]+)', l)
    if m and 0xc198 <= int(m.group(1), 16) <= 0xc234:
        table.append(int(m.group(2), 16))
print('cases', len(table))
ins = {}
for l in lines:
    m = re.match(r'\s+([0-9a-f]+):\s+((?:[0-9a-f]{2} ){4})\s*(.*)', l)
    if m:
        ins[int(m.group(1), 16)] = m.group(3).strip()
targets = {0xbb68: 'protection', 0xbce8: 'protection2', 0xbeb4: 'protection3', 0xc050: 'protection4'}
for case, start in enumerate(table):
    a = start
    calls = []
    while a in ins:
        t = ins[a]
        m = re.match(r'bl\s+0x([0-9a-f]+)', t)
        if m:
            calls.append(int(m.group(1), 16))
        if re.match(r'b\s', t):
            break
        a += 4
    marks = [(i + 1, targets[c]) for i, c in enumerate(calls) if c in targets]
    print(case, ' '.join(hex(c) for c in calls), marks)
