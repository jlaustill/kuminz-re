import re
import csv
BASE = '/home/linux/code/kuminz-re/.claude/worktrees/cm848-egr-flow-delay/firmware/CM550_J90350.00_analysis/'
rom = open(BASE + 'firmware/J90350.00.rom.bin', 'rb').read()

# function starts from the decompile's "// Function: name @ 0xADDR" comments
funcs = []
for line in open(BASE + 'output/J90350.00.ghidra.cpp', errors='replace'):
    m = re.match(r'^// Function: (\S+) @ 0x([0-9a-fA-F]+)', line)
    if m:
        funcs.append((int(m.group(2), 16), m.group(1)))
funcs = sorted(set(funcs))


def owner(a):
    best = None
    for s, n in funcs:
        if s <= a:
            best = (s, n)
        else:
            break
    return best


def next_start(s):
    for f, n in funcs:
        if f > s:
            return f
    return len(rom)


SLOTS = {0x02: 'water in fuel lamp', 0x04: 'engine protection lamp', 0x06: 'warning lamp',
         0x09: 'cold start aid 1', 0x0a: 'cold start aid 2', 0x0d: 'ether start', 0x2d: 'fuel shutoff'}

pat = bytes.fromhex('0080bd1a')
seen = set()
for m in re.finditer(re.escape(pat), rom):
    h = m.start()
    op = int.from_bytes(rom[h - 2:h], 'big')
    kind = '?'
    reg = None
    if (op & 0xf1ff) == 0x207c:
        reg = (op >> 9) & 7
        kind = 'movea.l #,a%d' % reg
    elif op == 0x4879:
        kind = 'pea'
    elif (op & 0xf1ff) == 0x41f9:
        reg = (op >> 9) & 7
        kind = 'lea abs,a%d' % reg
    o = owner(h - 2)
    print('ref at %05x op %04x %-16s in %s @ %05x' % (h - 2, op, kind, o[1] if o else '?', o[0] if o else 0))
    if reg is None or o is None:
        continue
    key = (o[0], reg)
    if key in seen:
        continue
    seen.add(key)
    start, end = o[0], next_start(o[0])
    hits = []
    for a in range(start, end - 3, 2):
        w = int.from_bytes(rom[a:a + 2], 'big')
        d = int.from_bytes(rom[a + 2:a + 4], 'big')
        # byte ops with (d16,An) EA = mode 5: low 6 bits 0b101rrr
        ea = w & 0x3f
        if ea == (0x28 | reg) and d in SLOTS:
            hi = w & 0xffc0
            names = {0x4a00: 'tst.b', 0x4200: 'clr.b', 0x0c00: 'cmpi.b'}
            if hi in names:
                hits.append('%05x %s (%d,a%d) %s' % (a, names[hi], d, reg, SLOTS[d]))
        # move.b #imm,(d16,An): 0001 rrr 101 111100 -> dest mode 5
        if (w & 0xf1ff) == (0x117c) and ((w >> 9) & 7) == reg:
            dd = int.from_bytes(rom[a + 4:a + 6], 'big')
            if dd in SLOTS:
                hits.append('%05x move.b #%d,(%d,a%d) %s' % (a, d & 0xff, dd, reg, SLOTS[dd]))
        # movea.l An,a0 then addq / moveq+adda (address of a slot)
        if w == (0x2048 | reg):
            nxt = int.from_bytes(rom[a + 2:a + 4], 'big')
            if (nxt & 0xf1ff) == 0x5088:
                q = (nxt >> 9) & 7 or 8
                if q in SLOTS:
                    hits.append('%05x movea.l a%d,a0; addq.l #%d,a0 %s' % (a, reg, q, SLOTS[q]))
            if (nxt & 0xff00) == 0x7000:
                q = nxt & 0xff
                if q in SLOTS:
                    hits.append('%05x movea.l a%d,a0; moveq #%d,d0 %s' % (a, reg, q, SLOTS[q]))
    for x in hits:
        print('    ', x)
