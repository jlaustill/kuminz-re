"""Describer D1 scratch: every bsr.w / bsr.s / jsr abs.l / jmp abs.l / bra.w whose target lies in a range.
A brute scan of every even ROM offset (it can report false hits inside data; hits are checked by hand).
usage: branch_targets.py <lo hex> <hi hex>"""
import sys

ROM = "/home/linux/code/kuminz-re/.claude/worktrees/cm848-egr-flow-delay/firmware/CM550_J90350.00_analysis/firmware/J90350.00.rom.bin"
rom = open(ROM, "rb").read()
lo, hi = int(sys.argv[1], 16), int(sys.argv[2], 16)
hits = {}
for i in range(0, len(rom) - 6, 2):
    w = int.from_bytes(rom[i:i + 2], "big")
    kind = None
    if w == 0x6100:  # bsr.w
        d = int.from_bytes(rom[i + 2:i + 4], "big", signed=True)
        t, kind = i + 2 + d, "bsr.w"
    elif w == 0x6000:  # bra.w
        d = int.from_bytes(rom[i + 2:i + 4], "big", signed=True)
        t, kind = i + 2 + d, "bra.w"
    elif (w & 0xff00) == 0x6100 and (w & 0xff) not in (0, 0xff):  # bsr.s
        d = w & 0xff
        d = d - 256 if d > 127 else d
        t, kind = i + 2 + d, "bsr.s"
    elif w == 0x4eb9:
        t, kind = int.from_bytes(rom[i + 2:i + 6], "big"), "jsr"
    elif w == 0x4ef9:
        t, kind = int.from_bytes(rom[i + 2:i + 6], "big"), "jmp"
    if kind and lo <= t <= hi:
        hits.setdefault(t, []).append((i, kind))
for t in sorted(hits):
    srcs = hits[t]
    print(f"0x{t:05x}: {len(srcs)} refs: " + ", ".join(f"{k}@0x{a:x}" for a, k in srcs[:12]) + (" ..." if len(srcs) > 12 else ""))
