"""Round 93 (read-only): the access widths of CM550 addresses, from every absolute-long occurrence in the ROM:
per address the count of word / long / byte accesses (move / cmpi / tst / clr / cmp / add / sub / or / and forms
with the address as an operand), of address loads (movea / lea / pea: the width is then at the use), and of
occurrences not decoded; also the occurrences of address+1 (a byte access to the low half).
usage: width_census_r93.py <repo> 0xADDR..."""
import os
import sys

repo = os.path.abspath(sys.argv[1])
rom = open(os.path.join(repo, "firmware/CM550_J90350.00_analysis/firmware/J90350.00.rom.bin"), "rb").read()


def classify(i):
    """Width of the instruction whose absolute-long operand starts at i ('?' when not recognised)."""
    for back in (2, 4, 6, 8):
        if i - back < 0:
            continue
        w = int.from_bytes(rom[i - back:i - back + 2], "big")
        top = w >> 12
        if back == 2:
            if top in (1, 2, 3) and (w & 0x3f) == 0x39:                       # move <abs>,<dst>
                return {1: "b", 3: "w", 2: "l"}[top]
            if top in (1, 2, 3) and ((w >> 6) & 0x3f) == 0x0f:                 # move <src>,<abs> (src without extension)
                return {1: "b", 3: "w", 2: "l"}[top]
            if (w & 0xf1ff) == 0x2079 or (w & 0xf1ff) == 0x41f9 or w == 0x4879:
                return "load"
            if (w & 0xff3f) == 0x4a39 or (w & 0xff3f) == 0x4239:               # tst / clr
                return "bwl"[(w >> 6) & 3]
            if top in (0x8, 0x9, 0xb, 0xc, 0xd) and (w & 0x3f) == 0x39:        # or / sub / cmp / and / add  <abs>,Dn or Dn,<abs>
                size = (w >> 6) & 7
                return {0: "b", 1: "w", 2: "l", 4: "b", 5: "w", 6: "l", 3: "w", 7: "l"}[size]
            if (w & 0xf0c0) == 0x5000 and (w & 0x3f) == 0x39:                  # addq / subq
                return "bwl"[(w >> 6) & 3]
            if (w & 0xff00) in (0x0800,) and (w & 0x3f) == 0x39:
                return "b"                                                      # btst #n (static) has an extension: back 4
        if back == 4:
            if w in (0x0c39, 0x0c79, 0x0039, 0x0079, 0x0239, 0x0279, 0x0439, 0x0479, 0x0639, 0x0679, 0x0a39, 0x0a79):
                return "b" if (w & 0xc0) == 0 else "w"                          # cmpi / ori / andi / subi / addi / eori .b/.w
            if w in (0x0839, 0x0879, 0x08b9, 0x08f9):
                return "b"                                                      # btst / bchg / bclr / bset #n
            if top in (1, 2, 3) and ((w >> 6) & 0x3f) == 0x0f and (w & 0x3f) in (0x3c, 0x28, 0x29, 0x2a, 0x2b, 0x2c, 0x2d, 0x2e, 0x38):
                return {1: "b", 3: "w", 2: "l"}[top]                            # move #imm.w / (d16,An) / abs.w ,<abs>
        if back == 6:
            if top in (1, 2, 3) and ((w >> 6) & 0x3f) == 0x0f and (w & 0x3f) in (0x39, 0x3c):
                return {1: "b", 3: "w", 2: "l"}[top]                            # move <abs>,<abs> / move #imm.l,<abs>
            if w in (0x0cb9, 0x00b9, 0x02b9, 0x04b9, 0x06b9):
                return "l"
    return "?"


for arg in sys.argv[2:]:
    a = int(arg, 16)
    out = []
    for addr in (a, a + 1):
        counts = {}
        i = rom.find(addr.to_bytes(4, "big"))
        while i != -1:
            if i % 2 == 0:
                k = classify(i)
                counts[k] = counts.get(k, 0) + 1
            i = rom.find(addr.to_bytes(4, "big"), i + 1)
        out.append(" ".join(f"{k}:{v}" for k, v in sorted(counts.items())) or "-")
    print(f"0x{a:x}: {out[0]:28} | at +1: {out[1]}")
