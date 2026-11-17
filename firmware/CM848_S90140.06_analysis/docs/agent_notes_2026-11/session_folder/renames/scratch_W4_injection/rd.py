import sys, struct
FW = '/home/linux/code/kuminz-re/.claude/worktrees/cm848-typing-arrays/firmware/CM848_S90140.06_analysis/originals/'
ram = open(FW + 'cm848_ram.bin', 'rb').read()
rom = open(FW + 'cm848_rom.bin', 'rb').read()


def rw(a, signed=True):
    o = a - 0x3FA000
    return struct.unpack('>h' if signed else '>H', ram[o:o + 2])[0]


def rb(a):
    return ram[a - 0x3FA000]


def romw(a, signed=True):
    return struct.unpack('>h' if signed else '>H', rom[a:a + 2])[0]


if __name__ == '__main__':
    for s in sys.argv[1:]:
        a = int(s, 16)
        if a < 0x3F9800 or a >= 0x440000:
            print(hex(a), 'ROM word', romw(a), hex(romw(a, False)))
        else:
            print(hex(a), 'RAM word', rw(a), hex(rw(a, False)), 'byte', rb(a))
