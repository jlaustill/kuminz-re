"""Round 93 J1 investigator (read-only): every way the CM550 ROM could reach an address:
absolute long anywhere (even / odd offset), bsr.s / bsr.w / bsr.l and conditional branches, jsr/jmp/lea/pea (d16,pc).
usage: find_callers.py <rom> <0xADDR>..."""
import sys

rom = open(sys.argv[1], "rb").read()
for arg in sys.argv[2:]:
    t = int(arg, 16)
    print(f"== 0x{t:x}")
    pat = t.to_bytes(4, "big")
    i = rom.find(pat)
    while i != -1:
        prev = rom[i - 2:i].hex()
        print(f"  abs long at 0x{i:x} (prev word {prev}; {'even' if i % 2 == 0 else 'ODD'})")
        i = rom.find(pat, i + 1)
    for pc in range(0, len(rom) - 6, 2):
        w = int.from_bytes(rom[pc:pc + 2], "big")
        if (w >> 12) == 6:
            d8 = w & 0xff
            if d8 == 0:
                d = int.from_bytes(rom[pc + 2:pc + 4], "big", signed=True)
                if pc + 2 + d == t:
                    print(f"  branch.w cond={((w >> 8) & 0xf):x} at 0x{pc:x}")
            elif d8 == 0xff:
                d = int.from_bytes(rom[pc + 2:pc + 6], "big", signed=True)
                if pc + 2 + d == t:
                    print(f"  branch.l cond={((w >> 8) & 0xf):x} at 0x{pc:x}")
            else:
                d = d8 - 256 if d8 > 127 else d8
                if pc + 2 + d == t:
                    print(f"  branch.s cond={((w >> 8) & 0xf):x} at 0x{pc:x}")
        if w in (0x4eba, 0x4efa, 0x487a) or (w & 0xf1ff) == 0x41fa:
            d = int.from_bytes(rom[pc + 2:pc + 4], "big", signed=True)
            if pc + 2 + d == t:
                print(f"  pc-relative {w:04x} at 0x{pc:x}")
