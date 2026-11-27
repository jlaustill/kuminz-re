"""List jsr/jmp (abs.l), bsr.w/bsr.l and pea/lea/move.l #imm references to CM550 addresses, plus raw 4-byte hits.
usage: callers.py <0xADDR> [...]"""
import sys

ROM = "/home/linux/code/kuminz-re/.claude/worktrees/cm848-egr-flow-delay/firmware/CM550_J90350.00_analysis/firmware/J90350.00.rom.bin"
rom = open(ROM, "rb").read()


def word(i):
    return int.from_bytes(rom[i:i + 2], "big")


for arg in sys.argv[1:]:
    target = int(arg, 16)
    pat = target.to_bytes(4, "big")
    print(f"== 0x{target:x}")
    i = rom.find(pat)
    while i != -1:
        prev = word(i - 2) if i >= 2 else 0
        kind = {0x4eb9: "jsr", 0x4ef9: "jmp", 0x4879: "pea", 0x2f3c: "move.l #imm,-(a7)", 0x41f9: "lea a0", 0x43f9: "lea a1",
                0x45f9: "lea a2", 0x47f9: "lea a3", 0x49f9: "lea a4", 0x4bf9: "lea a5", 0x207c: "movea.l #,a0",
                0x227c: "movea.l #,a1", 0x247c: "movea.l #,a2", 0x267c: "movea.l #,a3", 0x23fc: "move.l #imm,(abs)"}.get(prev, f"raw(prev {prev:04x})")
        print(f"  0x{i - 2:x}: {kind}")
        i = rom.find(pat, i + 1)
    # pc-relative bsr.w / bsr.l
    for j in range(0, len(rom) - 6, 2):
        w = word(j)
        if w == 0x6100:
            d = int.from_bytes(rom[j + 2:j + 4], "big", signed=True)
            if j + 2 + d == target:
                print(f"  0x{j:x}: bsr.w")
        elif w == 0x61ff:
            d = int.from_bytes(rom[j + 2:j + 6], "big", signed=True)
            if j + 2 + d == target:
                print(f"  0x{j:x}: bsr.l")
        elif (w & 0xff00) == 0x6100 and (w & 0xff) not in (0, 0xff):
            d = (w & 0xff) - 256 if (w & 0x80) else (w & 0xff)
            if j + 2 + d == target:
                print(f"  0x{j:x}: bsr.b")
