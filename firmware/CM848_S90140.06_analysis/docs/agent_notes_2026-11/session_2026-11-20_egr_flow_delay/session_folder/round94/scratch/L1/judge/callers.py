import sys
ROM = '/home/linux/code/kuminz-re/.claude/worktrees/cm848-egr-flow-delay/firmware/CM550_J90350.00_analysis/firmware/J90350.00.rom.bin'
rom = open(ROM, 'rb').read()
targets = [int(x, 16) for x in sys.argv[1:]]
for t in targets:
    hits = []
    # jsr/jmp abs.l: 4eb9 / 4ef9 + 32-bit
    tb = t.to_bytes(4, 'big')
    i = 0
    while True:
        i = rom.find(tb, i)
        if i < 0:
            break
        op = rom[i-2:i] if i >= 2 else b''
        kind = {b'\x4e\xb9': 'jsr.l', b'\x4e\xf9': 'jmp.l', b'\x48\x79': 'pea.l'}.get(op, 'data/other(%s)' % op.hex())
        hits.append((i-2 if kind != 'data/other(%s)' % op.hex() else i, kind))
        i += 1
    # bsr.w / bra.w: 6100 disp16 / 6000 disp16 ; bsr.s 61xx
    for a in range(0, len(rom) - 4, 2):
        w = int.from_bytes(rom[a:a+2], 'big')
        if w == 0x6100 or w == 0x6000:
            d = int.from_bytes(rom[a+2:a+4], 'big', signed=True)
            if a + 2 + d == t:
                hits.append((a, 'bsr.w' if w == 0x6100 else 'bra.w'))
        elif (w >> 8) == 0x61 and (w & 0xff) not in (0, 0xff):
            d = (w & 0xff)
            d = d - 256 if d >= 128 else d
            if a + 2 + d == t:
                hits.append((a, 'bsr.s'))
        elif w == 0x61ff:
            d = int.from_bytes(rom[a+2:a+6], 'big', signed=True)
            if a + 2 + d == t:
                hits.append((a, 'bsr.l'))
    print(hex(t), [(hex(a), k) for a, k in sorted(hits)])
