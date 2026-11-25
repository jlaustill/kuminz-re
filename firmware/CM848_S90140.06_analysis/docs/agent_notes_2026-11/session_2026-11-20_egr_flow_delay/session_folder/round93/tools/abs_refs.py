"""Round 92 (read-only): every absolute-long reference to an address in the CM550 ROM, with the opcode words before
it decoded for the common forms (move.w / move.l / move.b abs<->abs, cmpi, tst, clr), to read the access width.
usage: abs_refs_r92.py <repo> <0xADDR>..."""
import os
import sys

repo = sys.argv[1]
rom = open(os.path.join(repo, "firmware/CM550_J90350.00_analysis/firmware/J90350.00.rom.bin"), "rb").read()
SIZE = {0x1: "move.b", 0x3: "move.w", 0x2: "move.l"}
for arg in sys.argv[2:]:
    a = int(arg, 16)
    pat = a.to_bytes(4, "big")
    i = rom.find(pat)
    print(f"== 0x{a:x}")
    while i != -1:
        if i % 2 == 0:
            w2, w6, w4 = (int.from_bytes(rom[i - k:i - k + 2], "big") for k in (2, 6, 4))
            guess = []
            if (w2 >> 12) in SIZE and (w2 & 0x3f) == 0x39:
                guess.append(f"{SIZE[w2 >> 12]} (abs).l,<dst> (source) @0x{i - 2:x}")
            if (w6 >> 12) in SIZE and ((w6 >> 6) & 0x3f) == 0x0f and (w6 & 0x3f) == 0x39:
                guess.append(f"{SIZE[w6 >> 12]} (abs).l,(abs).l (destination) @0x{i - 6:x}")
            if (w2 >> 12) in SIZE and ((w2 >> 6) & 0x3f) == 0x0f:
                guess.append(f"{SIZE[w2 >> 12]} <src>,(abs).l (destination) @0x{i - 2:x}")
            if w4 in (0x0c79, 0x0c39, 0x0cb9):
                guess.append({0x0c79: "cmpi.w", 0x0c39: "cmpi.b", 0x0cb9: "cmpi.l"}[w4] + f" #0x{int.from_bytes(rom[i - 2:i], 'big'):x},(abs).l @0x{i - 4:x}")
            if w2 in (0x4a79, 0x4a39, 0x4ab9, 0x4279, 0x4239, 0x42b9):
                guess.append({0x4a79: "tst.w", 0x4a39: "tst.b", 0x4ab9: "tst.l", 0x4279: "clr.w", 0x4239: "clr.b", 0x42b9: "clr.l"}[w2] + f" (abs).l @0x{i - 2:x}")
            if (w2 & 0xf1ff) == 0xb079:
                guess.append(f"cmp.w (abs).l,d{(w2 >> 9) & 7} @0x{i - 2:x}")
            print(f"  0x{i:x}: prev words {rom[i - 6:i].hex(' ')} | " + ("; ".join(guess) or "?"))
        i = rom.find(pat, i + 1)
