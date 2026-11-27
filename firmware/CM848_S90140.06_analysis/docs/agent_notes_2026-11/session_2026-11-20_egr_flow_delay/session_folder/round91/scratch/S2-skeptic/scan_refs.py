import struct, sys
rom = open('/home/linux/code/kuminz-re/.claude/worktrees/cm848-egr-flow-delay/firmware/CM550_J90350.00_analysis/firmware/J90350.00.rom.bin', 'rb').read()


def find_all(pat):
    out = []
    i = rom.find(pat)
    while i >= 0:
        out.append(i)
        i = rom.find(pat, i + 1)
    return out


# 1) every 4-byte big-endian occurrence of values in given ranges
ranges = [(0x803d60, 0x803dcc), (0x800350, 0x800540), (0x80bac4, 0x80bacc), (0x804fca, 0x805300)]
for lo, hi in ranges:
    hits = {}
    for i in range(0, len(rom) - 3, 2):  # word-aligned operands
        v = struct.unpack('>I', rom[i:i + 4])[0]
        if lo <= v < hi:
            hits.setdefault(v, []).append(i)
    print('== range %x-%x (word-aligned 4-byte hits)' % (lo, hi))
    for v in sorted(hits):
        print('  %06x: %s' % (v, ' '.join('%05x' % x for x in hits[v])))

# 2) callers of the nine functions (jsr abs.l, jmp abs.l, bsr.w/bsr.l relative)
funcs = [0x138b6, 0x13a5c, 0x13cc8, 0x13d42, 0x13dbe, 0x13e12, 0x13e64, 0x13ed8, 0x14292]
for f in funcs:
    pats = {'jsr.l': b'\x4e\xb9' + struct.pack('>I', f), 'jmp.l': b'\x4e\xf9' + struct.pack('>I', f), 'abs32': struct.pack('>I', f)}
    res = []
    for k, p in pats.items():
        for i in find_all(p):
            if k == 'abs32' and (rom[i - 2:i] in (b'\x4e\xb9', b'\x4e\xf9')):
                continue
            res.append('%s@%05x' % (k, i if k == 'abs32' else i))
    # bsr.w: 0x6100 disp16 ; target = pc+2+disp
    for i in range(0, len(rom) - 3, 2):
        if rom[i] == 0x61:
            d8 = rom[i + 1]
            if d8 == 0:
                disp = struct.unpack('>h', rom[i + 2:i + 4])[0]
                if i + 2 + disp == f:
                    res.append('bsr.w@%05x' % i)
            elif d8 == 0xff:
                disp = struct.unpack('>i', rom[i + 2:i + 6])[0]
                if i + 2 + disp == f:
                    res.append('bsr.l@%05x' % i)
            else:
                disp = d8 - 256 if d8 > 127 else d8
                if i + 2 + disp == f:
                    res.append('bsr.b@%05x' % i)
    print('callers of %05x: %s' % (f, ' '.join(res)))
