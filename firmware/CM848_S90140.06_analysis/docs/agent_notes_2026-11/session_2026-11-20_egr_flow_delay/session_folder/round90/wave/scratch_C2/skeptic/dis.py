#!/usr/bin/env python3
"""Disassemble a CM550 ROM range with llvm-mc-18 (m68k). Usage: dis.py START END [filter ...]
Prints address, encoding, instruction. Invalid words are shown as <invalid>."""
import re, subprocess, sys
ROM = '/home/linux/code/kuminz-re/.claude/worktrees/cm848-egr-flow-delay/firmware/CM550_J90350.00_analysis/firmware/J90350.00.rom.bin'
start = int(sys.argv[1], 16)
end = int(sys.argv[2], 16)
filters = [f.lower() for f in sys.argv[3:]]
d = open(ROM, 'rb').read()[start:end]
pos = 0
out = []
while pos < len(d):
    chunk = d[pos:]
    text = ' '.join('0x%02x' % b for b in chunk[:64])
    p = subprocess.run(['llvm-mc-18', '--disassemble', '--triple=m68k', '--show-encoding'], input=text, capture_output=True, text=True)
    # take only the first instruction
    first = None
    for line in p.stdout.split('\n'):
        m = re.match(r'\s+(\S.*?)\s*; encoding: \[(.*)\]', line)
        if m:
            first = m
            break
    # was the first word invalid?
    bad_first = re.search(r'<stdin>:1:1: warning: invalid instruction encoding', p.stderr)
    if bad_first or first is None:
        out.append((start + pos, '%02x %02x' % (chunk[0], chunk[1]) if len(chunk) > 1 else '', '<invalid>'))
        pos += 2
        continue
    enc = [int(x, 16) for x in first.group(2).split(',')]
    s = first.group(1)
    s = re.sub(r'#(-?\d{4,})', lambda mm: '#0x%x' % (int(mm.group(1)) & 0xffffffff), s)
    s = re.sub(r'\$([0-9a-f]+)', lambda mm: '$' + mm.group(1), s)
    out.append((start + pos, ' '.join('%02x' % b for b in enc), s))
    pos += len(enc)
for a, e, s in out:
    line = '%06x: %-32s %s' % (a, e, s)
    if not filters or any(f in line.lower() for f in filters):
        print(line)
