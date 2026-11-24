"""Print decoded instruction + raw bytes at given ROM addresses: python3 rawbytes.py 0xc39a 0xcb84 ..."""
import sys
sys.path.insert(0, '/home/linux/.claude/jobs/374b0424/tmp/w15/r90/wave/scratch_C3')
import m68k
for a in sys.argv[1:]:
    p = int(a, 16)
    n, t, ab, im = m68k.decode(p)
    print('0x%05x: %-40s %s' % (p, t, ' '.join(m68k.data[p + i:p + i + 2].hex() for i in range(0, n, 2))))
