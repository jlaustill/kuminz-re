"""Judge D1: every reference to a CM550 code address: jsr/jmp abs.l, any 4-byte big-endian occurrence (pointer tables,
move.l #imm), and bsr.w / bsr.s / bra.w relative branches whose target is the address.
usage: refs.py 0xADDR [...]"""
import sys

ROM = "/home/linux/code/kuminz-re/.claude/worktrees/cm848-egr-flow-delay/firmware/CM550_J90350.00_analysis/firmware/J90350.00.rom.bin"
rom = open(ROM, "rb").read()


def s8(v):
    return v - 0x100 if v & 0x80 else v


def s16(v):
    return v - 0x10000 if v & 0x8000 else v


for arg in sys.argv[1:]:
    t = int(arg, 16)
    hits = []
    pat = t.to_bytes(4, "big")
    i = rom.find(pat)
    while i >= 0:
        op = rom[i - 2:i]
        kind = {b"\x4e\xb9": "jsr.l", b"\x4e\xf9": "jmp.l", b"\x48\x79": "pea.l", b"\x41\xf9": "lea.l"}.get(op, "data/imm (prev %s)" % op.hex())
        hits.append((i - 2 if kind != "data/imm (prev %s)" % op.hex() else i, kind))
        i = rom.find(pat, i + 1)
    for a in range(0, len(rom) - 4, 2):
        w = int.from_bytes(rom[a:a + 2], "big")
        if (w & 0xff00) == 0x6100:  # bsr
            d = w & 0xff
            if d == 0:
                tgt = a + 2 + s16(int.from_bytes(rom[a + 2:a + 4], "big"))
                if tgt == t:
                    hits.append((a, "bsr.w"))
            elif d != 0xff:
                tgt = a + 2 + s8(d)
                if tgt == t:
                    hits.append((a, "bsr.s"))
        elif w == 0x6000:  # bra.w
            tgt = a + 2 + s16(int.from_bytes(rom[a + 2:a + 4], "big"))
            if tgt == t:
                hits.append((a, "bra.w"))
    print("== 0x%x:" % t, ", ".join("0x%x %s" % h for h in sorted(hits)) or "none")
