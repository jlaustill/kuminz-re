"""Read CM550 dump bytes at an address: python3 dump.py <addr> <nbytes>"""
import sys
BASE = '/home/linux/code/kuminz-re/.claude/worktrees/cm848-egr-flow-delay/firmware/CM550_J90350.00_analysis/firmware/'
ram = open(BASE + 'J90350.00.ram.bin', 'rb').read()
ext = open(BASE + 'J90350.00.extended_ram.bin', 'rb').read()
rom = open(BASE + 'J90350.00.rom.bin', 'rb').read()


def read(addr, n):
    if addr < 0x40000:
        return rom[addr:addr + n], 'rom'
    if 0x800000 <= addr < 0x8091C2:
        return ram[addr - 0x800000:addr - 0x800000 + n], 'ram'
    if addr >= 0x8092C2:
        return ext[addr - 0x809242:addr - 0x809242 + n], 'ext'
    return b'', 'uncertain'


args = sys.argv[1:]
for i in range(0, len(args), 2):
    a = int(args[i], 16)
    n = int(args[i + 1])
    b, region = read(a, n)
    words = ' '.join(b[j:j + 2].hex() for j in range(0, len(b) - 1, 2)) if n >= 2 else ''
    print('0x%06x [%s] %d bytes: %s   words: %s' % (a, region, n, b.hex(), words))
