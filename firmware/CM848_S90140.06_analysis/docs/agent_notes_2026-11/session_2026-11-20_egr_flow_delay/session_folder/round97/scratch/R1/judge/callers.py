import sys, struct
rom = open('/home/linux/code/kuminz-re/.claude/worktrees/cm848-egr-flow-delay/firmware/CM550_J90350.00_analysis/firmware/J90350.00.rom.bin', 'rb').read()
names = {0x4eb9: 'jsr', 0x4ef9: 'jmp', 0x41f9: 'lea a0', 0x43f9: 'lea a1', 0x45f9: 'lea a2', 0x47f9: 'lea a3', 0x4879: 'pea'}
for a in sys.argv[1:]:
    t = int(a, 16)
    res = []
    tb = struct.pack('>I', t)
    i = rom.find(tb)
    while i != -1:
        op = struct.unpack('>H', rom[i - 2:i])[0] if i >= 2 else 0
        kind = names.get(op, 'ptr/data(prev %04x)' % op)
        res.append('%s@%x' % (kind, i - 2 if op in names else i))
        i = rom.find(tb, i + 1)
    for p in range(0, len(rom) - 4, 2):
        op = struct.unpack('>H', rom[p:p + 2])[0]
        if op in (0x6100, 0x6000):
            d = struct.unpack('>h', rom[p + 2:p + 4])[0]
            if p + 2 + d == t:
                res.append('%s.w@%x' % ('bsr' if op == 0x6100 else 'bra', p))
        elif (op & 0xff00) == 0x6100 and (op & 0xff) not in (0, 0xff):
            d = op & 0xff
            if d >= 0x80:
                d -= 0x100
            if p + 2 + d == t:
                res.append('bsr.s@%x' % p)
        elif op in (0x4eba, 0x41fa, 0x487a, 0x43fa, 0x45fa, 0x47fa):
            d = struct.unpack('>h', rom[p + 2:p + 4])[0]
            if p + 2 + d == t:
                res.append('pcrel(%04x)@%x' % (op, p))
    print(a, ' '.join(res))
