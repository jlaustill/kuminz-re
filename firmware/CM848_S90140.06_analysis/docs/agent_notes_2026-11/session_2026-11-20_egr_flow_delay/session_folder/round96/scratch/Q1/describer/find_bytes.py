"""Find a hex byte pattern in a binary. usage: find_bytes.py <bin> <base hex> <hexpattern> [...]"""
import sys
data = open(sys.argv[1], "rb").read()
base = int(sys.argv[2], 16)
for pattern in sys.argv[3:]:
    needle = bytes.fromhex(pattern)
    hits = []
    i = data.find(needle)
    while i != -1:
        hits.append(hex(base + i))
        i = data.find(needle, i + 1)
    print(pattern, hits if hits else "NONE")
