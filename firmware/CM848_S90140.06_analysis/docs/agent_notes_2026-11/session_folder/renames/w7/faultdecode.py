import struct, sys
ROM = open('/home/linux/code/kuminz-re/.claude/worktrees/cm848-typing-arrays/firmware/CM848_S90140.06_analysis/originals/cm848_rom.bin','rb').read()
SLOT = 0x5985a
DTC = 0x5b57c
def u16(a): return struct.unpack('>H', ROM[a:a+2])[0]
def decode(n):
    s = u16(SLOT + 2*n)
    if s == 0xaa or s >= 170:
        return s, None
    c = u16(DTC + 2*s)
    return s, 'P%04X' % c
if __name__ == '__main__':
    for a in sys.argv[1:]:
        if '-' in a:
            lo, hi = a.split('-'); lo=int(lo); hi=int(hi)
        else:
            lo=hi=int(a)
        for n in range(lo, hi+1):
            s, c = decode(n)
            print(f"fault {n} (word {n//16} bit {n%16} mask 0x{1<<(n%16):04x}): slot {s} -> {c}")
