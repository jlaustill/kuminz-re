"""Find PC-relative calls / branches / lea to a CM550 address (bsr.w, bsr.l, jsr (d16,pc), lea (d16,pc)) - read-only."""
import sys

rom = open("/home/linux/code/kuminz-re/.claude/worktrees/cm848-egr-flow-delay/firmware/CM550_J90350.00_analysis/firmware/J90350.00.rom.bin", "rb").read()
target = int(sys.argv[1], 16)
for i in range(0, len(rom) - 6, 2):
    w = int.from_bytes(rom[i:i + 2], "big")
    d16 = int.from_bytes(rom[i + 2:i + 4], "big", signed=True)
    if w == 0x6100 and i + 2 + d16 == target:
        print(f"bsr.w at 0x{i:x}")
    if w == 0x61ff and i + 2 + int.from_bytes(rom[i + 2:i + 6], "big", signed=True) == target:
        print(f"bsr.l at 0x{i:x}")
    if w == 0x4eba and i + 2 + d16 == target:
        print(f"jsr (d16,pc) at 0x{i:x}")
    if (w & 0xf1ff) == 0x41fa and i + 2 + d16 == target:
        print(f"lea (d16,pc),a{(w >> 9) & 7} at 0x{i:x}")
    if (w & 0xff00) == 0x6100 and (w & 0xff) not in (0, 0xff):
        d8 = w & 0xff
        d8 = d8 - 256 if d8 > 127 else d8
        if i + 2 + d8 == target:
            print(f"bsr.s at 0x{i:x}")
