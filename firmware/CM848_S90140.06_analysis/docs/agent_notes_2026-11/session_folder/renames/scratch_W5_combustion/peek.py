import struct, sys
ORIG='/home/linux/code/kuminz-re/.claude/worktrees/cm848-typing-arrays/firmware/CM848_S90140.06_analysis/originals/'
ram=open(ORIG+'cm848_ram.bin','rb').read()
rom=open(ORIG+'cm848_rom.bin','rb').read()
RAMBASE=0x3FA000
def w(addr, signed=False):
    if addr>=RAMBASE:
        o=addr-RAMBASE
        return struct.unpack('>h' if signed else '>H', ram[o:o+2])[0]
    return struct.unpack('>h' if signed else '>H', rom[addr:addr+2])[0]
def b(addr):
    if addr>=RAMBASE: return ram[addr-RAMBASE]
    return rom[addr]
def table(addr,n,signed=False):
    return [w(addr+2*i,signed) for i in range(n)]
