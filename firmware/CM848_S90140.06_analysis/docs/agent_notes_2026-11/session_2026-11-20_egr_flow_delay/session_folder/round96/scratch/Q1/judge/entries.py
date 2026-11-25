"""Read-only: every way into a CM550 code range - absolute 4-byte occurrences of any address inside it, and every
even-address PC-relative branch / jsr / jmp / pea / lea (d16,pc) whose target lands inside it (brute force, so a
data word can show up as a false hit; the hit's own address is printed for checking).
usage: entries.py <start hex> <end hex exclusive> [...pairs]"""
import sys

rom = open("/home/linux/code/kuminz-re/.claude/worktrees/cm848-egr-flow-delay/firmware/CM550_J90350.00_analysis/"
           "firmware/J90350.00.rom.bin", "rb").read()
args = sys.argv[1:]
for k in range(0, len(args), 2):
    lo, hi = int(args[k], 16), int(args[k + 1], 16)
    print(f"== range 0x{lo:x}-0x{hi - 1:x}")
    # absolute longs pointing inside the range
    for a in range(lo, hi):
        pat = a.to_bytes(4, "big")
        i = rom.find(pat)
        while i != -1:
            print(f"  abs 0x{a:x} at 0x{i:x}")
            i = rom.find(pat, i + 1)
    # PC-relative
    for pc in range(0, len(rom) - 4, 2):
        w = int.from_bytes(rom[pc:pc + 2], "big")
        tgt = None
        kind = None
        if (w & 0xf000) == 0x6000:
            d8 = w & 0xff
            if d8 == 0:
                d16 = int.from_bytes(rom[pc + 2:pc + 4], "big", signed=True)
                tgt, kind = pc + 2 + d16, "bcc.w"
            elif d8 == 0xff:
                d32 = int.from_bytes(rom[pc + 2:pc + 6], "big", signed=True)
                tgt, kind = pc + 2 + d32, "bcc.l"
            else:
                d = d8 - 256 if d8 >= 128 else d8
                tgt, kind = pc + 2 + d, "bcc.s"
        elif w in (0x4eba, 0x4efa, 0x487a) or (w & 0xf1ff) == 0x41fa:
            d16 = int.from_bytes(rom[pc + 2:pc + 4], "big", signed=True)
            tgt, kind = pc + 2 + d16, {0x4eba: "jsr(pc)", 0x4efa: "jmp(pc)", 0x487a: "pea(pc)"}.get(w, "lea(pc)")
        if tgt is not None and lo <= tgt < hi and not (lo <= pc < hi):
            print(f"  {kind} at 0x{pc:x} (word {w:04x}) -> 0x{tgt:x}")
