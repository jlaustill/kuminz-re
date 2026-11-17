import struct, sys
FW = '/home/linux/code/kuminz-re/.claude/worktrees/cm848-typing-arrays/firmware/CM848_S90140.06_analysis/originals/'
RAM = open(FW + 'cm848_ram.bin', 'rb').read()
ROM = open(FW + 'cm848_rom.bin', 'rb').read()
F2 = open(FW + 'cm848_flash2_live.bin', 'rb').read()
RAM_BASE = 0x3FA000


def buf(addr):
    if 0x500000 <= addr < 0x500000 + len(F2):
        return F2, addr - 0x500000
    if addr >= RAM_BASE and addr - RAM_BASE < len(RAM):
        return RAM, addr - RAM_BASE
    return ROM, addr


def words(addr, n, signed=False):
    b, o = buf(addr)
    return list(struct.unpack('>' + ('h' if signed else 'H') * n, b[o:o + 2 * n]))


if __name__ == '__main__':
    # usage: dump.py addr nwords [s]   (several "addr:n[:s]" specs allowed)
    for spec in sys.argv[1:]:
        p = spec.split(':')
        a = int(p[0], 16)
        n = int(p[1])
        s = len(p) > 2
        print(hex(a), words(a, n, s))
