"""usage: branch_refs.py <hex target>... : every bsr.w / bsr.s / bsr.l / bra.w / jsr (d16,pc) / lea (d16,pc) / pea (d16,pc)
in the CM550 ROM whose target is one of the given addresses (even addresses only; data may give false hits)."""
import struct
import sys

rom = open("/home/linux/code/kuminz-re/.claude/worktrees/cm848-egr-flow-delay/firmware/CM550_J90350.00_analysis/firmware/J90350.00.rom.bin", "rb").read()
targets = {int(a, 16) for a in sys.argv[1:]}
for pc in range(0, len(rom) - 6, 2):
    w = struct.unpack_from(">H", rom, pc)[0]
    hits = []
    if (w & 0xff00) in (0x6100, 0x6000):  # bsr / bra
        d8 = w & 0xff
        kind = "bsr" if (w & 0xff00) == 0x6100 else "bra"
        if d8 == 0:
            d = struct.unpack_from(">h", rom, pc + 2)[0]
            t = pc + 2 + d
            hits.append((kind + ".w", t))
        elif d8 == 0xff:
            d = struct.unpack_from(">i", rom, pc + 2)[0]
            t = pc + 2 + d
            hits.append((kind + ".l", t))
        else:
            d = d8 - 256 if d8 & 0x80 else d8
            t = pc + 2 + d
            hits.append((kind + ".s", t))
    if w in (0x4eba, 0x41fa, 0x43fa, 0x45fa, 0x47fa, 0x49fa, 0x4bfa, 0x4dfa, 0x487a, 0x4efa):  # jsr/lea/pea/jmp (d16,pc)
        d = struct.unpack_from(">h", rom, pc + 2)[0]
        hits.append((f"0x{w:04x}(d16,pc)", pc + 2 + d))
    for kind, t in hits:
        if t in targets:
            print(f"0x{pc:x}: {kind} -> 0x{t:x}")
