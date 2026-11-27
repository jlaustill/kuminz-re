import sys
base='/home/linux/code/kuminz-re/.claude/worktrees/cm848-egr-flow-delay/firmware/CM550_J90350.00_analysis/firmware/'
ram = open(base+'J90350.00.ram.bin','rb').read()
ext = open(base+'J90350.00.extended_ram.bin','rb').read()
rom = open(base+'J90350.00.rom.bin','rb').read()
def rd(a, n):
    if 0x800000 <= a < 0x800000+len(ram):
        return ram[a-0x800000:a-0x800000+n], 'ram'
    if 0x809242 <= a < 0x809242+len(ext):
        return ext[a-0x809242:a-0x809242+n], 'ext'
    return None, 'none'
for arg in sys.argv[1:]:
    a, n = arg.split(':') if ':' in arg else (arg, '2')
    a = int(a,16); n=int(n)
    b, src = rd(a, n)
    if b is None:
        print(hex(a), 'not dumped'); continue
    v = int.from_bytes(b,'big')
    sv = v - (1<<(8*n)) if v >= (1<<(8*n-1)) else v
    print(hex(a), src, b.hex(), v, sv)
