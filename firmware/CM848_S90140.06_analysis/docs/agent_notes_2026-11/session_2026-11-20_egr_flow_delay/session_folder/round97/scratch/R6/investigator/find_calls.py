"""Find every jsr abs.l / jmp abs.l / bsr to a target in the CM550 ROM, plus other 4-byte references to it.
usage: find_calls.py <0xtarget>..."""
import sys

ROM = "/home/linux/code/kuminz-re/.claude/worktrees/cm848-egr-flow-delay/firmware/CM550_J90350.00_analysis/firmware/J90350.00.rom.bin"
rom = open(ROM, "rb").read()
for arg in sys.argv[1:]:
    t = int(arg, 16)
    hits = []
    for op, kind in ((b"\x4e\xb9", "jsr.l"), (b"\x4e\xf9", "jmp.l")):
        pat = op + t.to_bytes(4, "big")
        i = rom.find(pat)
        while i != -1:
            if i % 2 == 0:
                hits.append((i, kind))
            i = rom.find(pat, i + 1)
    for i in range(0, len(rom) - 6, 2):
        w = int.from_bytes(rom[i:i + 2], "big")
        if (w & 0xfe00) != 0x6000 or (w >> 8) not in (0x60, 0x61):
            continue
        kind = "bsr" if (w >> 8) == 0x61 else "bra"
        lo = w & 0xff
        if lo == 0:
            d = int.from_bytes(rom[i + 2:i + 4], "big", signed=True)
            sz = ".w"
        elif lo == 0xff:
            d = int.from_bytes(rom[i + 2:i + 6], "big", signed=True)
            sz = ".l"
        else:
            d = lo - 256 if lo & 0x80 else lo
            sz = ".s"
        if i + 2 + d == t:
            hits.append((i, kind + sz))
    pat = t.to_bytes(4, "big")
    i = rom.find(pat)
    ptrs = []
    while i != -1:
        if i % 2 == 0 and not any(h[0] + 2 == i for h in hits):
            ptrs.append((i, rom[i - 2:i].hex()))
        i = rom.find(pat, i + 1)
    print(f"== 0x{t:x}: calls " + ", ".join(f"0x{a:x} {k}" for a, k in sorted(hits)))
    print("   other 4-byte refs " + ", ".join(f"0x{a:x} (prev {p})" for a, p in ptrs))
