ROM = '/home/linux/code/kuminz-re/.claude/worktrees/cm848-egr-flow-delay/firmware/CM550_J90350.00_analysis/firmware/J90350.00.rom.bin'
rom = open(ROM, 'rb').read()
checks = [
    (0x3071a, '42b900806126'),
    (0x30720, '42b90080612e'),
    (0x30726, '42b900806132'),
    (0x3072c, '42b900806136'),
    (0x30732, '42b90080613e'),
    (0x30738, '42b900806142'),
    (0x3073e, '42b900806146'),
    (0x30744, '42b90080614a'),
    (0x309ac, '48790080617a'),
    (0x309ca, '487900806142'),
    (0x309d0, '48790080612e'),
    (0x309ec, '23f90080617a00804fa0'),
    (0x309f6, '23f90080614200804fa4'),
    (0x30a1e, '48790080613e'),
    (0x30a24, '487900806126'),
    (0x30432, '487900806146'),
    (0x30438, '487900806132'),
    (0x30472, '48790080614a'),
    (0x30478, '487900806136'),
    (0x317f4, '20390080617a'),
]
for a, exp in checks:
    n = len(exp) // 2
    got = rom[a:a + n].hex()
    print(hex(a), got, 'OK' if got == exp else 'MISMATCH exp ' + exp)

# context dumps: the carry helper body, the constant-arg pushes, the snapshot at 0x31608
for a, n in [(0x303d4, 64), (0x309a0, 16), (0x30440, 20), (0x30480, 24), (0x31600, 20)]:
    print('ctx', hex(a), rom[a:a + n].hex())

# scan the whole ROM for any absolute-long reference to each trip address, to list every access
import re
targets = [0x806126, 0x80612a, 0x80612e, 0x806132, 0x806136, 0x80613e, 0x806142, 0x806146,
           0x80614a, 0x806166, 0x80616a, 0x80616e, 0x80617a, 0x804fa0, 0x804fa4, 0x804fb8]
for t in targets:
    pat = t.to_bytes(4, 'big')
    hits = [m.start() for m in re.finditer(re.escape(pat), rom)]
    desc = []
    for h in hits:
        op = rom[h - 2:h].hex() if h >= 2 else '??'
        desc.append('%x[%s]' % (h - 2, op))
    print('ref %06x:' % t, ' '.join(desc))
