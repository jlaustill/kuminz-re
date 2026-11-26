"""PC-relative references (jsr/jmp/lea/pea (d16,pc)) to CM550 addresses. usage: pcrel_refs.py <hex addr>..."""
import struct
import sys

ROM = "/home/linux/code/kuminz-re/.claude/worktrees/cm848-egr-flow-delay/firmware/CM550_J90350.00_analysis/firmware/J90350.00.rom.bin"
rom = open(ROM, "rb").read()
targets = [int(a, 16) for a in sys.argv[1:]]
for pc in range(0, len(rom) - 4, 2):
    w = struct.unpack_from(">H", rom, pc)[0]
    kind = None
    if w == 0x4eba:
        kind = "jsr (d16,pc)"
    elif w == 0x4efa:
        kind = "jmp (d16,pc)"
    elif w == 0x487a:
        kind = "pea (d16,pc)"
    elif (w & 0xf1ff) == 0x41fa:
        kind = f"lea (d16,pc),a{(w >> 9) & 7}"
    if kind:
        d = struct.unpack_from(">h", rom, pc + 2)[0]
        t = pc + 2 + d
        if t in targets:
            print(f"0x{pc:x}: {kind} -> 0x{t:x}")
