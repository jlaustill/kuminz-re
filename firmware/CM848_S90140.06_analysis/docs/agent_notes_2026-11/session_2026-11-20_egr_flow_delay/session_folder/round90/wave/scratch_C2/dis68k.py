#!/usr/bin/env python3
"""Disassemble a CM550 ROM range with llvm-mc-18 (m68k), print each instruction with its address.
Invalid encodings are skipped 2 bytes at a time by llvm-mc; we rebuild addresses from the warning
columns and the per-instruction encodings. Usage: dis68k.py START END [grep-hex-addr ...]"""
import re, subprocess, sys
ROM = '/home/linux/code/kuminz-re/.claude/worktrees/cm848-egr-flow-delay/firmware/CM550_J90350.00_analysis/firmware/J90350.00.rom.bin'
start = int(sys.argv[1], 16); end = int(sys.argv[2], 16)
targets = [a.lower() for a in sys.argv[3:]]
d = open(ROM, 'rb').read()[start:end]
text = ' '.join('0x%02x' % b for b in d)
p = subprocess.run(['llvm-mc-18', '--disassemble', '--triple=m68k', '--show-encoding'], input=text, capture_output=True, text=True)
bad = set()
for m in re.finditer(r'<stdin>:1:(\d+): warning: invalid instruction encoding', p.stderr):
    bad.add((int(m.group(1)) - 1) // 5)
cur = 0
out = []
for line in p.stdout.split('\n'):
    m = re.match(r'\s+(\S.*?)\s*; encoding: \[(.*)\]', line)
    if not m:
        continue
    while cur in bad:
        out.append((start + cur, '%02x %02x' % (d[cur], d[cur+1]) if cur + 1 < len(d) else '', '<invalid>'))
        cur += 2
    enc = [int(x, 16) for x in m.group(2).split(',')]
    if list(d[cur:cur+len(enc)]) != enc:
        out.append((start + cur, '', '!!! desync'))
    out.append((start + cur, ' '.join('%02x' % b for b in enc), m.group(1)))
    cur += len(enc)
while cur < len(d):
    if cur in bad:
        out.append((start + cur, '%02x %02x' % (d[cur], d[cur+1]) if cur + 1 < len(d) else '', '<invalid>'))
        cur += 2
    else:
        break
for a, e, s in out:
    s2 = s
    # annotate absolute addresses in hex
    def rep(mm):
        v = int(mm.group(1))
        return '#0x%x' % v
    s2 = re.sub(r'#(\d{5,})', rep, s2)
    line = '%06x: %-30s %s' % (a, e, s2)
    if targets:
        if any(t in line.lower() for t in targets):
            print(line)
    else:
        print(line)
