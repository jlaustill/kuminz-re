"""Search the CM550 ROM and both RAM dumps for 4-byte big-endian occurrences of the given addresses (any alignment),
plus 68k PC-relative lea/pea/jsr/bsr/bra forms that reach them from even code addresses."""
import sys

base = '/home/linux/code/kuminz-re/.claude/worktrees/cm848-egr-flow-delay/firmware/CM550_J90350.00_analysis/firmware/'
rom = open(base + 'J90350.00.rom.bin', 'rb').read()
ram = open(base + 'J90350.00.ram.bin', 'rb').read()
ext = open(base + 'J90350.00.extended_ram.bin', 'rb').read()
for arg in sys.argv[1:]:
    t = int(arg, 16)
    pat = t.to_bytes(4, 'big')
    for name, img, off in (('rom', rom, 0), ('ram', ram, 0x800000), ('extended_ram', ext, 0x809242)):
        i = img.find(pat)
        while i != -1:
            print(f"0x{t:x}: {name} 0x{i + off:x}")
            i = img.find(pat, i + 1)
    # PC-relative: word displacement d16 at pc+2 for lea/pea (d16,pc); bsr.w / bra.w / jsr (d16,pc)
    for i in range(0, len(rom) - 4, 2):
        op = int.from_bytes(rom[i:i + 2], 'big')
        d16 = int.from_bytes(rom[i + 2:i + 4], 'big', signed=True)
        if op in (0x6100, 0x6000) or (op & 0xf1ff) == 0x41fa or op in (0x487a, 0x4eba, 0x4efa):
            if i + 2 + d16 == t:
                print(f"0x{t:x}: pc-relative from 0x{i:x} (op {op:04x})")
        if (op & 0xff00) in (0x6100, 0x6000) and (op & 0xff) not in (0, 0xff):
            d8 = op & 0xff
            if d8 >= 0x80:
                d8 -= 0x100
            if i + 2 + d8 == t:
                print(f"0x{t:x}: short branch from 0x{i:x} (op {op:04x})")
