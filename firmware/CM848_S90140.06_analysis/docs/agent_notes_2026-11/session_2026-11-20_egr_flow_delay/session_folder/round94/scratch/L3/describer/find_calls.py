"""Find every reference to 0x35088 in the CM550 ROM: absolute-long, pc-relative jsr/bsr/jmp/lea/pea."""
import struct

rom = open("/home/linux/code/kuminz-re/.claude/worktrees/cm848-egr-flow-delay/firmware/CM550_J90350.00_analysis/firmware/J90350.00.rom.bin", "rb").read()
T = 0x35088
pat = T.to_bytes(4, "big")
i = rom.find(pat)
print("absolute-long references:")
while i != -1:
    print(f"  0x{i:x}: prev word {rom[i-2:i].hex()}")
    i = rom.find(pat, i + 1)
print("pc-relative (d16,pc) / bsr.w / bsr.b / bsr.l:")
for pc in range(0, len(rom) - 6, 2):
    w = struct.unpack_from(">H", rom, pc)[0]
    if w in (0x4eba, 0x4efa, 0x487a) or (w & 0xf1ff) == 0x41fa:
        d = struct.unpack_from(">h", rom, pc + 2)[0]
        if pc + 2 + d == T:
            print(f"  0x{pc:x}: {w:04x} d16 -> 0x{T:x}")
    if (w & 0xff00) == 0x6100:
        b = w & 0xff
        if b == 0:
            d = struct.unpack_from(">h", rom, pc + 2)[0]
            if pc + 2 + d == T:
                print(f"  0x{pc:x}: bsr.w -> 0x{T:x}")
        elif b == 0xff:
            d = struct.unpack_from(">i", rom, pc + 2)[0]
            if pc + 2 + d == T:
                print(f"  0x{pc:x}: bsr.l -> 0x{T:x}")
        else:
            d = b - 256 if b & 0x80 else b
            if pc + 2 + d == T:
                print(f"  0x{pc:x}: bsr.b -> 0x{T:x}")
