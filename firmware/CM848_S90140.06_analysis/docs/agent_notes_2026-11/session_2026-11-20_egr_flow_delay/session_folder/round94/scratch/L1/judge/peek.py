import sys, struct
FW = '/home/linux/code/kuminz-re/.claude/worktrees/cm848-egr-flow-delay/firmware/CM550_J90350.00_analysis/firmware/'
ram = open(FW + 'J90350.00.ram.bin', 'rb').read()
ext = open(FW + 'J90350.00.extended_ram.bin', 'rb').read()
rom = open(FW + 'J90350.00.rom.bin', 'rb').read()
def get(addr, n):
    if addr < 0x40000:
        return rom[addr:addr+n]
    if 0x800000 <= addr <= 0x8091C1:
        return ram[addr-0x800000:addr-0x800000+n]
    if addr >= 0x809242:
        return ext[addr-0x809242:addr-0x809242+n]
    return None
for a in sys.argv[1:]:
    addr, _, w = a.partition(':')
    addr = int(addr, 16); w = int(w or '2')
    b = get(addr, w)
    if b is None or len(b) < w:
        print(hex(addr), 'not dumped'); continue
    v = int.from_bytes(b, 'big')
    print(hex(addr), w, b.hex(), v)
