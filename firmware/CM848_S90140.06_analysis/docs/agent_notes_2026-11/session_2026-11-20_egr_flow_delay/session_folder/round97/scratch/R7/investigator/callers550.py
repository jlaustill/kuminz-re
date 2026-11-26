"""Find every reference to a CM550 code address: jsr/jmp abs.l, bsr/bra .w/.s (relative), lea/pea abs.l and raw
4-byte pointers (even offsets). usage: callers550.py 0xADDR [...]"""
import bisect
import csv
import sys

ROM = "/home/linux/code/kuminz-re/.claude/worktrees/cm848-egr-flow-delay/firmware/CM550_J90350.00_analysis/firmware/J90350.00.rom.bin"
rom = open(ROM, "rb").read()
names = {}
for row in csv.reader(open("/home/linux/.claude/jobs/374b0424/tmp/w15/r97/frozen/cm550/function_renames.csv")):
    if row and row[0].startswith("0x"):
        names[int(row[0], 16)] = row[1]
starts = sorted(names)


def owner(a):
    i = bisect.bisect_right(starts, a) - 1
    return f"{names[starts[i]]}@0x{starts[i]:x}+0x{a - starts[i]:x}" if i >= 0 else "?"


OPS = {0x4eb9: "jsr", 0x4ef9: "jmp", 0x41f9: "lea a0", 0x43f9: "lea a1", 0x45f9: "lea a2", 0x47f9: "lea a3",
       0x49f9: "lea a4", 0x4bf9: "lea a5", 0x4879: "pea", 0x207c: "movea.l a0", 0x227c: "movea.l a1",
       0x247c: "movea.l a2", 0x267c: "movea.l a3", 0x287c: "movea.l a4", 0x2a7c: "movea.l a5", 0x2c7c: "movea.l a6",
       0x23fc: "move.l #,abs", 0x2f3c: "move.l #,-(a7)"}

for arg in sys.argv[1:]:
    t = int(arg, 16)
    print(f"== 0x{t:x} {names.get(t, '')}")
    pat = t.to_bytes(4, "big")
    i = rom.find(pat)
    while i != -1:
        if i % 2 == 0:
            op = int.from_bytes(rom[i - 2:i], "big")
            kind = OPS.get(op, "ptr?")
            at = i - 2 if kind != "ptr?" else i
            print(f"  {kind} at 0x{at:x} in {owner(at)}")
        i = rom.find(pat, i + 1)
    for pc in range(0, len(rom) - 6, 2):
        w = int.from_bytes(rom[pc:pc + 2], "big")
        hi = w >> 8
        if hi not in (0x60, 0x61):
            continue
        d8 = w & 0xff
        if d8 == 0:
            d = int.from_bytes(rom[pc + 2:pc + 4], "big", signed=True)
            sfx = "w"
        elif d8 == 0xff:
            d = int.from_bytes(rom[pc + 2:pc + 6], "big", signed=True)
            sfx = "l"
        else:
            d = d8 - 256 if d8 & 0x80 else d8
            sfx = "s"
        if pc + 2 + d == t:
            print(f"  {'bsr' if hi == 0x61 else 'bra'}.{sfx} at 0x{pc:x} in {owner(pc)}")
