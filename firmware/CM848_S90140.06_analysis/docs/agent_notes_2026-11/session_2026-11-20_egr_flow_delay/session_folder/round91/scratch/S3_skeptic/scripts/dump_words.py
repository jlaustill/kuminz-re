import sys
base = sys.argv[1]
ram = open(base + '/J90350.00.ram.bin', 'rb').read()
ext = open(base + '/J90350.00.extended_ram.bin', 'rb').read()

def read(addr, n):
    if 0x800000 <= addr and addr + n <= 0x8091C2:
        o = addr - 0x800000; return ram[o:o+n], 'ram'
    if addr >= 0x8092C2:
        o = addr - 0x809242; return ext[o:o+n], 'ext'
    return None, 'none'

def s16(b):
    v = int.from_bytes(b, 'big'); return v - 0x10000 if v & 0x8000 else v

for spec in sys.argv[2:]:
    a, count = spec.split(':')
    a = int(a, 16); count = int(count)
    b, where = read(a, count * 2)
    if b is None:
        print('%06x: not in a dump' % a); continue
    words = [b[i:i+2] for i in range(0, len(b), 2)]
    print('%06x (%s): ' % (a, where) + ' '.join('%d' % s16(w) for w in words))
    print('         hex: ' + ' '.join(w.hex() for w in words))
