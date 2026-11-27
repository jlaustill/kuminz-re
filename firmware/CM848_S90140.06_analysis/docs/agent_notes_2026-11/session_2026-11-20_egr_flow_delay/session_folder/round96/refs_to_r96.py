"""Round 96: references to a CM550 ROM address: jsr / jmp / pea / lea / move.l #abs (absolute long), bsr.w / bsr.s /
jsr d16(pc) (PC-relative), and the plain 4-byte value anywhere (a pointer table). usage: refs_to_r96.py <hex target>..."""
import struct
import sys

rom = open("/home/linux/code/kuminz-re/.claude/worktrees/cm848-egr-flow-delay/firmware/CM550_J90350.00_analysis/firmware/J90350.00.rom.bin", "rb").read()
for t in (int(a, 16) for a in sys.argv[1:]):
    hits = []
    raw = t.to_bytes(4, "big")
    i = rom.find(raw)
    while i >= 0:
        op = rom[i - 2:i].hex() if i >= 2 else ""
        kind = {"4eb9": "jsr", "4ef9": "jmp", "4879": "pea", "2f3c": "move.l #,-(a7)"}.get(op, f"value (prev {op})")
        hits.append(f"0x{i - 2 if kind != 'value (prev ' + op + ')' else i:x} {kind}")
        i = rom.find(raw, i + 1)
    for pc in range(0, len(rom) - 4, 2):
        w = struct.unpack_from(">H", rom, pc)[0]
        if w == 0x6100:                                   # bsr.w
            d = struct.unpack_from(">h", rom, pc + 2)[0]
            if pc + 2 + d == t:
                hits.append(f"0x{pc:x} bsr.w")
        elif w & 0xff00 == 0x6100 and w & 0xff not in (0, 0xff):   # bsr.s
            d = struct.unpack_from(">b", rom, pc + 1)[0]
            if pc + 2 + d == t:
                hits.append(f"0x{pc:x} bsr.s")
        elif w in (0x4eba, 0x487a, 0x41fa, 0x43fa, 0x45fa, 0x47fa):  # jsr / pea / lea d16(pc)
            d = struct.unpack_from(">h", rom, pc + 2)[0]
            if pc + 2 + d == t:
                hits.append(f"0x{pc:x} pc-relative {w:04x}")
    print(f"0x{t:x}:", "; ".join(hits) or "no reference")
