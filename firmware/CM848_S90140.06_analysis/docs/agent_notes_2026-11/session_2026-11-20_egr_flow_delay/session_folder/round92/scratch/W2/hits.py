"""For each absolute-long reference to an address in [lo, hi) in the CM550 ROM: the enclosing function (from the
.cpp '// Function:' headers) and the raw instruction words before / after the operand.
usage: hits.py <rom> <cpp> <lo> <hi>"""
import re, sys, bisect
rom = open(sys.argv[1], 'rb').read()
funcs = sorted({(int(m.group(2), 16), m.group(1)) for m in re.finditer(r'^// Function: (\S+) @ 0x([0-9a-fA-F]+)', open(sys.argv[2], errors='replace').read(), re.M)})
starts = [a for a, _ in funcs]
lo, hi = int(sys.argv[3], 16), int(sys.argv[4], 16)
for a in range(lo, hi):
    pat = a.to_bytes(4, 'big')
    p = rom.find(pat)
    while p >= 0:
        i = bisect.bisect_right(starts, p) - 1
        f = funcs[i] if i >= 0 else (0, '?')
        before = ' '.join(f'{rom[q]:02x}{rom[q+1]:02x}' for q in range(p - 6, p, 2))
        after = ' '.join(f'{rom[q]:02x}{rom[q+1]:02x}' for q in range(p + 4, p + 12, 2))
        print(f'0x{a:06x} @0x{p:05x} {f[1]}@0x{f[0]:x}  [{before}] <addr> [{after}]')
        p = rom.find(pat, p + 1)
