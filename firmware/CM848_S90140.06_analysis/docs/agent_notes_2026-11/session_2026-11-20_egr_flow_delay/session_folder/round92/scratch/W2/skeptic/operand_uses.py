"""Skeptic: every instruction whose bytes contain a given 32-bit absolute address, decoded with m68k.py (it tries the
instruction starts 2, 4 and 6 bytes before the operand and keeps the one whose decode covers the operand), plus the next
two instructions. usage: operand_uses.py <rom> <addr hex>..."""
import struct
import sys

sys.path.insert(0, __file__.rsplit("/", 1)[0])
import m68k  # noqa: E402

rom = open(sys.argv[1], "rb").read()
for t in sys.argv[2:]:
    target = int(t, 16)
    pat = struct.pack(">I", target)
    print(f"== 0x{target:x}")
    off = 0
    n = 0
    while True:
        off = rom.find(pat, off)
        if off < 0:
            break
        best = None
        for back in (2, 4, 6):
            start = off - back
            if start < 0:
                continue
            dec = m68k.Decoder(rom)
            dec.pc = start
            addr, text = dec.one()
            if not text.startswith(".word") and dec.pc >= off + 4 and ("0x%x" % target) in text:
                best = (start, text, dec.pc)
                break
        if best is None:
            print(f"   0x{off:05x}: (not decoded) {rom[off - 6:off + 8].hex()}")
        else:
            start, text, nxt = best
            dec = m68k.Decoder(rom)
            dec.pc = nxt
            follow = []
            for _ in range(2):
                a, tx = dec.one()
                follow.append(tx)
            print(f"   0x{start:05x}: {text:44} ; {' ; '.join(follow)}")
        n += 1
        off += 1
    print(f"   {n} references")
