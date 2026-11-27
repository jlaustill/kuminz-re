"""List jsr abs.l / jmp abs.l / bsr / bra sites and raw pointers that reach a CM550 address.
usage: find_calls.py <rom> <0xADDR>..."""
import sys

rom = open(sys.argv[1], "rb").read()
for arg in sys.argv[2:]:
    a = int(arg, 16)
    print(f"== 0x{a:x}")
    for opcode, label in ((0x4EB9, "jsr abs.l"), (0x4EF9, "jmp abs.l")):
        pat = opcode.to_bytes(2, "big") + a.to_bytes(4, "big")
        i = rom.find(pat)
        while i != -1:
            print(f"  {label} @0x{i:x}")
            i = rom.find(pat, i + 1)
    for i in range(0, len(rom) - 6, 2):
        w = int.from_bytes(rom[i:i + 2], "big")
        if w in (0x6100, 0x6000):
            d = int.from_bytes(rom[i + 2:i + 4], "big", signed=True)
            if i + 2 + d == a:
                print(f"  {'bsr' if w == 0x6100 else 'bra'}.w @0x{i:x}")
        elif w in (0x61FF, 0x60FF):
            d = int.from_bytes(rom[i + 2:i + 6], "big", signed=True)
            if i + 2 + d == a:
                print(f"  {'bsr' if w == 0x61FF else 'bra'}.l @0x{i:x}")
        elif (w & 0xFF00) == 0x6100 and (w & 0xFF) not in (0, 0xFF):
            d = w & 0xFF
            d = d - 256 if d > 127 else d
            if i + 2 + d == a:
                print(f"  bsr.s @0x{i:x}")
    pat = a.to_bytes(4, "big")
    i = rom.find(pat)
    while i != -1:
        pre = int.from_bytes(rom[i - 2:i], "big")
        if pre not in (0x4EB9, 0x4EF9):
            print(f"  raw 4-byte value @0x{i:x} (previous word {pre:04x})")
        i = rom.find(pat, i + 1)
