"""Search the CM550 RAM dumps (RAM 0x800000.. and extended RAM 0x809242..) for big-endian 4-byte values in [lo, hi),
and print words at given addresses. usage: ram_find.py find 0xLO 0xHI | ram_find.py words 0xADDR [n] | bytes 0xADDR n"""
import sys
D = "/home/linux/code/kuminz-re/.claude/worktrees/cm848-egr-flow-delay/firmware/CM550_J90350.00_analysis/firmware/"
ram = open(D + "J90350.00.ram.bin", "rb").read()
ext = open(D + "J90350.00.extended_ram.bin", "rb").read()
REGIONS = ((0x800000, ram), (0x809242, ext))


def read(addr, n):
    for base, data in REGIONS:
        if base <= addr and addr + n <= base + len(data):
            return data[addr - base:addr - base + n]
    return None


cmd = sys.argv[1]
if cmd == "find":
    lo, hi = int(sys.argv[2], 16), int(sys.argv[3], 16)
    for base, data in REGIONS:
        for i in range(0, len(data) - 4, 2):
            v = int.from_bytes(data[i:i + 4], "big")
            if lo <= v < hi:
                print("RAM 0x%06x: 0x%08x" % (base + i, v))
elif cmd == "words":
    a = int(sys.argv[2], 16)
    n = int(sys.argv[3]) if len(sys.argv) > 3 else 1
    for k in range(n):
        b = read(a + 2 * k, 2)
        if b is None:
            print("0x%06x: (not dumped)" % (a + 2 * k))
        else:
            v = int.from_bytes(b, "big")
            print("0x%06x: 0x%04x %6d %6d" % (a + 2 * k, v, v, v - 65536 if v > 32767 else v))
elif cmd == "bytes":
    a = int(sys.argv[2], 16)
    n = int(sys.argv[3])
    b = read(a, n)
    print("0x%06x: %s" % (a, b.hex(" ") if b else "(not dumped)"))
