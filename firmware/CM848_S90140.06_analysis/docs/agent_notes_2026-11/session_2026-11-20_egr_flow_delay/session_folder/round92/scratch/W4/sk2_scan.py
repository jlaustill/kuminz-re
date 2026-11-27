"""Skeptic pass 2 (read-only): every 4-byte big-endian occurrence of each address in [lo, hi] in a ROM image, with the
bytes before / after for hand decoding, and the containing function from the decompilation.
usage: sk2_scan.py <rom> <cpp> <lo hex> <hi hex>"""
import re
import sys

rom = open(sys.argv[1], "rb").read()
funcs = sorted({(int(m.group(2), 16), m.group(1)) for m in
                (re.match(r"^// Function: (\S+) @ 0x([0-9a-fA-F]+)", l) for l in open(sys.argv[2], errors="replace")) if m})
lo, hi = int(sys.argv[3], 16), int(sys.argv[4], 16)
for t in range(lo, hi + 1):
    pat = t.to_bytes(4, "big")
    start = 0
    while True:
        i = rom.find(pat, start)
        if i < 0:
            break
        f = [x for x in funcs if x[0] <= i]
        fn = "%s@0x%x" % (f[-1][1], f[-1][0]) if f else "?"
        print("0x%06x at 0x%05x %s: [%s] %s [%s]  %s" % (t, i, "even" if i % 2 == 0 else "ODD ", rom[max(0, i - 10):i].hex(" "),
                                                     pat.hex(" "), rom[i + 4:i + 14].hex(" "), fn))
        start = i + 1
