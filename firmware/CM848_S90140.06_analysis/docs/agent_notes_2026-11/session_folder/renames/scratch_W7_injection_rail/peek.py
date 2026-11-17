import struct
import sys

BASE = '/home/linux/code/kuminz-re/.claude/worktrees/cm848-typing-arrays/firmware/CM848_S90140.06_analysis/originals/'
rom = open(BASE + 'cm848_rom.bin', 'rb').read()
ram = open(BASE + 'cm848_ram.bin', 'rb').read()
RAM0 = 0x3FA000


def mem(a):
    if a < len(rom):
        return rom, a
    if RAM0 <= a < RAM0 + len(ram):
        return ram, a - RAM0
    raise ValueError(hex(a))


def rd(a, n=1, w=2, signed=False):
    b, o = mem(a)
    f = {1: 'b', 2: 'h', 4: 'i'}[w]
    if not signed:
        f = f.upper()
    return list(struct.unpack_from('>%d%s' % (n, f), b, o))


if __name__ == '__main__':
    # usage: peek.py addr[:count[:width[:s]]] ...
    for t in sys.argv[1:]:
        p = t.split(':')
        a = int(p[0], 16)
        n = int(p[1]) if len(p) > 1 else 1
        w = int(p[2]) if len(p) > 2 else 2
        s = len(p) > 3 and p[3] == 's'
        v = rd(a, n, w, s)
        print('%s[%d x %d byte%s] = %s' % (hex(a), n, w, ' signed' if s else '', v))
