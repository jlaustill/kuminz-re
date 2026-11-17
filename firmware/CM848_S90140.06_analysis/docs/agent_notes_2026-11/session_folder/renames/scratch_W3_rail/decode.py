import struct, sys
ROM = open('/home/linux/code/kuminz-re/.claude/worktrees/cm848-typing-arrays/firmware/CM848_S90140.06_analysis/originals/cm848_rom.bin','rb').read()
def u8(a): return ROM[a]
def u16(a): return struct.unpack('>H', ROM[a:a+2])[0]
def s16(a): return struct.unpack('>h', ROM[a:a+2])[0]
def u32(a): return struct.unpack('>I', ROM[a:a+4])[0]
def dtc(code):
    sysl = 'PCBU'[(code >> 14) & 3]
    return '%s%d%03X' % (sysl, (code >> 12) & 3, code & 0xfff)
def decode(n, entry=1):
    slot = u8(0x5985a + n) if entry == 1 else u16(0x5985a + 2*n)
    code = u16(0x5b57c + 2*slot)
    return slot, code
if __name__ == '__main__':
    for n in [int(x) for x in sys.argv[1:]]:
        for entry in (1,):
            slot, code = decode(n, entry)
            print('fault %d (word %d mask 0x%x): slot %d code word 0x%04x -> %s' % (n, n//16, 1 << (n % 16), slot, code, dtc(code)))
