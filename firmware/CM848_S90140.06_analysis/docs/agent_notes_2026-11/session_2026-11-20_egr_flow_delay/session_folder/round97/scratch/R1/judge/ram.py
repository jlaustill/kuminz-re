import sys, struct
base = '/home/linux/code/kuminz-re/.claude/worktrees/cm848-egr-flow-delay/firmware/CM550_J90350.00_analysis/firmware/'
ram = open(base + 'J90350.00.ram.bin', 'rb').read()
ext = open(base + 'J90350.00.extended_ram.bin', 'rb').read()


def rd(addr, n):
    if 0x800000 <= addr and addr - 0x800000 + n <= len(ram):
        return ram[addr - 0x800000:addr - 0x800000 + n]
    if 0x809242 <= addr and addr - 0x809242 + n <= len(ext):
        return ext[addr - 0x809242:addr - 0x809242 + n]
    return None


for spec in sys.argv[1:]:
    if ':' in spec:
        a, w = spec.split(':')
    else:
        a, w = spec, 'w'
    addr = int(a, 16)
    size = {'b': 1, 'w': 2, 'l': 4}[w]
    b = rd(addr, size)
    if b is None:
        print('%s: not dumped' % a)
        continue
    if size == 1:
        v = b[0]; s = v - 256 if v >= 128 else v
    elif size == 2:
        v = struct.unpack('>H', b)[0]; s = struct.unpack('>h', b)[0]
    else:
        v = struct.unpack('>I', b)[0]; s = struct.unpack('>i', b)[0]
    print('%s:%s = 0x%x  u=%d  s=%d' % (a, w, v, v, s))
