"""Describer J2 (read-only): every bsr.s / bsr.w / bsr.l / jsr abs.l / jsr (d16,pc) / pea abs.l / raw 4-byte pointer
in the CM550 ROM that targets one of the given addresses (a scan of even offsets; a hit inside data is possible, so
each is printed with the surrounding bytes).  usage: callers.py <0xADDR> ..."""
import sys

ROM = "/home/linux/code/kuminz-re/.claude/worktrees/cm848-egr-flow-delay/firmware/CM550_J90350.00_analysis/firmware/J90350.00.rom.bin"
rom = open(ROM, "rb").read()
targets = [int(a, 16) for a in sys.argv[1:]]
for t in targets:
    print(f"== 0x{t:x}")
    for i in range(0, len(rom) - 6, 2):
        w = int.from_bytes(rom[i:i + 2], "big")
        if w == 0x6100:  # bsr.w
            d = int.from_bytes(rom[i + 2:i + 4], "big", signed=True)
            if i + 2 + d == t:
                print(f"  bsr.w at 0x{i:x}")
        elif (w & 0xff00) == 0x6100 and (w & 0xff) not in (0, 0xff):
            d = (w & 0xff) - 0x100 if (w & 0x80) else (w & 0xff)
            if i + 2 + d == t:
                print(f"  bsr.s at 0x{i:x}")
        elif w == 0x61ff:
            d = int.from_bytes(rom[i + 2:i + 6], "big", signed=True)
            if i + 2 + d == t:
                print(f"  bsr.l at 0x{i:x}")
        elif w == 0x4eb9 and int.from_bytes(rom[i + 2:i + 6], "big") == t:
            print(f"  jsr (abs).l at 0x{i:x}")
        elif w == 0x4ef9 and int.from_bytes(rom[i + 2:i + 6], "big") == t:
            print(f"  jmp (abs).l at 0x{i:x}")
        elif w == 0x4eba:
            d = int.from_bytes(rom[i + 2:i + 4], "big", signed=True)
            if i + 2 + d == t:
                print(f"  jsr (d16,pc) at 0x{i:x}")
        elif w == 0x4879 and int.from_bytes(rom[i + 2:i + 6], "big") == t:
            print(f"  pea (abs).l at 0x{i:x}")
    pat = t.to_bytes(4, "big")
    j = rom.find(pat)
    while j != -1:
        print(f"  raw pointer bytes at 0x{j:x} (prev word {rom[j - 2:j].hex()})")
        j = rom.find(pat, j + 1)
