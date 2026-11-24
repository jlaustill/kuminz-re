"""Find every big-endian 32-bit occurrence of an address in binary images, and the PowerPC bl / b instructions that
target it (relative branch, opcode 18). usage: find_pointer.py <address> <image:base>..."""
import struct
import sys

target = int(sys.argv[1], 16)
needle = struct.pack(">I", target)
for spec in sys.argv[2:]:
    path, base = spec.rsplit(":", 1)
    base = int(base, 16)
    data = open(path, "rb").read()
    hits = []
    i = data.find(needle)
    while i != -1:
        hits.append(base + i)
        i = data.find(needle, i + 1)
    branches = []
    for off in range(0, len(data) - 3, 4):
        word = struct.unpack(">I", data[off:off + 4])[0]
        if word >> 26 == 18:
            li = word & 0x03fffffc
            if li & 0x02000000:
                li -= 0x04000000
            dest = li if word & 2 else base + off + li
            if dest == target:
                branches.append((base + off, "bl" if word & 1 else "b"))
    print(f"{path}: pointer at {[hex(h) for h in hits]}; branches {[(hex(a), k) for a, k in branches]}")
