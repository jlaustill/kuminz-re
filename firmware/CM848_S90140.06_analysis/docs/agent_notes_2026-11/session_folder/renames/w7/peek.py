import struct, sys
FW = '/home/linux/code/kuminz-re/.claude/worktrees/cm848-typing-arrays/firmware/CM848_S90140.06_analysis/originals/'
RAM = open(FW + 'cm848_ram.bin', 'rb').read()
ROM = open(FW + 'cm848_rom.bin', 'rb').read()
RAM_BASE = 0x3FA000

def peek(addr, width='w', signed=False):
    if addr >= RAM_BASE and addr - RAM_BASE < len(RAM):
        buf, off = RAM, addr - RAM_BASE
    elif addr < len(ROM):
        buf, off = ROM, addr
    else:
        return None
    fmt = {'b': '>b' if signed else '>B', 'w': '>h' if signed else '>H', 'd': '>i' if signed else '>I'}[width]
    n = {'b': 1, 'w': 2, 'd': 4}[width]
    return struct.unpack(fmt, buf[off:off + n])[0]

if __name__ == '__main__':
    # args: addr[:width[s]]  e.g. 0x40a66a  0x40a66a:ws  0x40a66a:d
    for a in sys.argv[1:]:
        spec = a.split(':')
        addr = int(spec[0], 16)
        w = 'w'; s = False
        if len(spec) > 1:
            w = spec[1][0]
            s = spec[1].endswith('s')
        v = peek(addr, w, s)
        print(f"0x{addr:06x} {w}{'s' if s else ''} = {v} (0x{v & 0xffffffff:x})" if v is not None else f"0x{addr:06x} out of range")
