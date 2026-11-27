import struct
RAM = '/home/linux/code/kuminz-re/.claude/worktrees/cm848-egr-flow-delay/firmware/CM550_J90350.00_analysis/firmware/J90350.00.ram.bin'
ram = open(RAM, 'rb').read()


def d32(a):
    o = a - 0x800000
    return struct.unpack('>I', ram[o:o + 4])[0]


def b8(a):
    return ram[a - 0x800000]


fields = [
    (0x806126, 'TID2VSFU trip drive remainder'),
    (0x80612a, 'TIDCFU lifetime remainder'),
    (0x80612e, 'TID2FU trip remainder'),
    (0x806132, 'TID2ISFU trip idle remainder'),
    (0x806136, 'TID2PTFU trip PTO remainder'),
    (0x80613a, 'TIT2TM lifetime run time'),
    (0x80613e, 'TIT3VSFU trip drive fuel'),
    (0x806142, 'TIT3FU trip fuel'),
    (0x806146, 'TIT3ISFU trip idle fuel'),
    (0x80614a, 'TIT3PTFU trip PTO fuel'),
    (0x80614e, 'TIFUSS overflow flags'),
    (0x806152, 'TIT2ISTM lifetime idle time'),
    (0x806156, 'TIT3ISTM trip idle time'),
    (0x80615a, 'TIT3PTTM trip PTO time'),
    (0x806162, 'TIT3TM trip time'),
    (0x806166, 'TIDCISFU lifetime idle remainder'),
    (0x80616a, 'TIDCPTFU lifetime PTO remainder'),
    (0x80616e, 'TIT2PTFU lifetime PTO fuel'),
    (0x806172, 'TIT2PTTM lifetime PTO time'),
    (0x80617a, 'TIT2FU lifetime fuel'),
    (0x804fa0, '117F +0 TIGAT2 copy'),
    (0x804fa4, '117F +4 TIGAT3 copy'),
    (0x804fb8, '117F +18 lifetime idle fuel'),
]
v = {}
for a, n in fields:
    v[a] = d32(a)
    print('%06x %-34s %12d  0x%08x' % (a, n, v[a], v[a]))

print()
print('trip whole: idle + PTO + drive =', v[0x806146] + v[0x80614a] + v[0x80613e], 'vs trip', v[0x806142])
rem_sum = v[0x806126] + v[0x806132] + v[0x806136]
print('mode remainders sum =', rem_sum, '= trip remainder + 2^20 ?', v[0x80612e] + (1 << 20))
print('trip total in 2^-23 units:', v[0x806142] * (1 << 20) + v[0x80612e])
print('mode total in 2^-23 units:', (v[0x806146] + v[0x80614a] + v[0x80613e]) * (1 << 20) + rem_sum)
print('lifetime fuel gal =', v[0x80617a] * 0.125, ' trip idle gal =', v[0x806146] * 0.125, ' trip PTO gal =', v[0x80614a] * 0.125)
print()
print('priority slots 0x80bd1a..0x80bd49:', ' '.join('%02x' % b8(a) for a in range(0x80bd1a, 0x80bd4a)))
print('image 0x80bcf6..0x80bcfb:', ' '.join('%02x' % b8(a) for a in range(0x80bcf6, 0x80bcfc)))
