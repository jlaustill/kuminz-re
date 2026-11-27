"""J2 investigator (round 93, read-only): every reference to a CM550 function address in the ROM - jsr / jmp / pea /
movea absolute long, bsr.w / bsr.s displacement, and any other aligned 4-byte occurrence (a stored pointer).
The owner is the last function_renames row at or below the site.
usage: callers.py <address hex> [...]"""
import bisect
import csv
import sys

csv.field_size_limit(10 ** 9)
rom = open("/home/linux/code/kuminz-re/.claude/worktrees/cm848-egr-flow-delay/firmware/CM550_J90350.00_analysis/firmware/J90350.00.rom.bin", "rb").read()
rows = []
for r in csv.reader(open("/home/linux/.claude/jobs/374b0424/tmp/w15/r93/frozen/cm550/function_renames.csv", errors="replace")):
    if r and r[0].startswith("0x") and len(r) > 1:
        rows.append((int(r[0], 16), r[1]))
rows.sort()
starts = [a for a, _ in rows]


def owner(site):
    i = bisect.bisect_right(starts, site) - 1
    return f"{rows[i][1]}@0x{rows[i][0]:x}" if i >= 0 else "?"


KIND = {0x4eb9: "jsr", 0x4ef9: "jmp", 0x4879: "pea", 0x207c: "movea a0", 0x227c: "movea a1", 0x247c: "movea a2",
        0x267c: "movea a3", 0x287c: "movea a4", 0x2a7c: "movea a5", 0x2c7c: "movea a6"}
for arg in sys.argv[1:]:
    t = int(arg, 16)
    print(f"== 0x{t:x}")
    pat = t.to_bytes(4, "big")
    i = rom.find(pat)
    while i != -1:
        if i % 2 == 0:
            op = int.from_bytes(rom[i - 2:i], "big")
            print(f"  0x{i - 2:x}: {KIND.get(op, 'long (prev word %04x)' % op)}  in {owner(i - 2)}")
        i = rom.find(pat, i + 1)
    for site in range(0, len(rom) - 4, 2):
        op = int.from_bytes(rom[site:site + 2], "big")
        if op == 0x6100:
            d = int.from_bytes(rom[site + 2:site + 4], "big", signed=True)
            if site + 2 + d == t:
                print(f"  0x{site:x}: bsr.w  in {owner(site)}")
        elif (op & 0xff00) == 0x6100 and (op & 0xff) not in (0, 0xff):
            d = op & 0xff
            d = d - 256 if d > 127 else d
            if site + 2 + d == t:
                print(f"  0x{site:x}: bsr.s  in {owner(site)}")
