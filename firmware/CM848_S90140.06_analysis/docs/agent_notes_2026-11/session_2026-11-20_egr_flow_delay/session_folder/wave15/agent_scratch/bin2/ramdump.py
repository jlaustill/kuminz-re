"""Read values from the CM848 RAM dump: ramdump.py <hexaddr> [count] [width]  (width 1/2/4, default 2).
Base 0x3fa000 (checked against 38 dump_raw values); the dump misses 0x40c200-0x40c27f, so >= 0x40c280 is read at -0x80."""
import struct
import sys

PATH = '/home/linux/code/kuminz-re/.claude/worktrees/cm848-egr-flow-delay/firmware/CM848_S90140.06_analysis/originals/cm848_ram.bin'
ram = open(PATH, 'rb').read()
BASE = 0x3fa000


def offset(a):
    o = a - BASE
    if a >= 0x40c280:
        o -= 0x80
    return o


if __name__ == '__main__':
    a = int(sys.argv[1], 16)
    count = int(sys.argv[2]) if len(sys.argv) > 2 else 1
    width = int(sys.argv[3]) if len(sys.argv) > 3 else 2
    fmt = {1: '>B', 2: '>H', 4: '>I'}[width]
    out = []
    for i in range(count):
        o = offset(a + i * width)
        v = struct.unpack(fmt, ram[o:o + width])[0]
        out.append(f'0x{a + i * width:x}={v} (0x{v:x})')
    print('  '.join(out))
