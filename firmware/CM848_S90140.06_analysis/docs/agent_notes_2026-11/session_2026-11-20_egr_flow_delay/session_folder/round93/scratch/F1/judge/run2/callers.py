"""Judge F1 run 2: every jsr / jmp / bsr / address load / raw 4-byte pointer to each batch function in the CM550 ROM."""
import struct
import sys

ROM = "/home/linux/code/kuminz-re/.claude/worktrees/cm848-egr-flow-delay/firmware/CM550_J90350.00_analysis/firmware/J90350.00.rom.bin"
rom = open(ROM, "rb").read()
OPS = {b"\x4e\xb9": "jsr", b"\x4e\xf9": "jmp", b"\x20\x7c": "movea a0", b"\x22\x7c": "movea a1", b"\x24\x7c": "movea a2",
       b"\x26\x7c": "movea a3", b"\x28\x7c": "movea a4", b"\x2a\x7c": "movea a5", b"\x41\xf9": "lea a0",
       b"\x43\xf9": "lea a1", b"\x45\xf9": "lea a2", b"\x47\xf9": "lea a3", b"\x49\xf9": "lea a4", b"\x4b\xf9": "lea a5",
       b"\x2f\x3c": "move.l #,-(a7)", b"\x48\x79": "pea"}
targets = [int(a, 16) for a in sys.argv[1:]]
bsr = {t: [] for t in targets}
for o in range(0, 0x40000 - 6, 2):
    w = struct.unpack(">H", rom[o:o + 2])[0]
    if (w & 0xff00) == 0x6100:
        d8 = w & 0xff
        if d8 == 0:
            dest = o + 2 + struct.unpack(">h", rom[o + 2:o + 4])[0]
            kind = "bsr.w"
        elif d8 == 0xff:
            dest = o + 2 + struct.unpack(">i", rom[o + 2:o + 6])[0]
            kind = "bsr.l"
        else:
            dest = o + 2 + (d8 - 256 if d8 > 127 else d8)
            kind = "bsr.s"
        if dest in bsr:
            bsr[dest].append(f"{kind}@{o:#x}")
for t in targets:
    hits = []
    pat = t.to_bytes(4, "big")
    i = rom.find(pat)
    while i != -1:
        kind = OPS.get(rom[i - 2:i])
        hits.append(f"{kind}@{i - 2:#x}" if kind else f"raw@{i:#x}(prev {rom[i - 2:i].hex()})")
        i = rom.find(pat, i + 1)
    hits += bsr[t]
    print(f"{t:#x}: " + (", ".join(hits) if hits else "NONE"))
