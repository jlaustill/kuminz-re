import sys
base = '/home/linux/code/kuminz-re/.claude/worktrees/cm848-egr-flow-delay/firmware/CM550_J90350.00_analysis/firmware/'
ram = open(base + 'J90350.00.ram.bin', 'rb').read()
ext = open(base + 'J90350.00.extended_ram.bin', 'rb').read()
rom = open(base + 'J90350.00.rom.bin', 'rb').read()
eep = open(base + 'J90350.00.eeprom.bin', 'rb').read()
print('ram len %#x ext len %#x rom len %#x eep len %#x' % (len(ram), len(ext), len(rom), len(eep)))


def rd(a, n):
    if a < 0x800000:
        src, off, tag = rom, a, 'rom'
    elif a <= 0x8091c1:
        src, off, tag = ram, a - 0x800000, 'ram'
    elif a < 0x8092c2:
        src, off, tag = ext, a - 0x809242, 'ext(uncertain)'
    else:
        src, off, tag = ext, a - 0x809242, 'ext'
    b = src[off:off + n]
    if len(b) < n:
        return tag, None
    return tag, int.from_bytes(b, 'big')


for arg in sys.argv[1:]:
    a, n = arg.split(':')
    a = int(a, 16)
    n = int(n)
    tag, v = rd(a, n)
    extra = ''
    if 0x803b0a <= a <= 0x804155:
        eo = a - 0x803b0a
        ev = int.from_bytes(eep[eo:eo + n], 'big')
        extra = ' eeprom[%#x]=%#x (%d)' % (eo, ev, ev)
    print('%#08x %d %s = %s%s' % (a, n, tag, ('%#x (%d)' % (v, v)) if v is not None else 'n/a', extra))
