"""Judge L3: decode table_lookup_2d_arguments_t records from the CM550 RAM dumps, list the frozen global rows that
start inside each record (and rows that start before and overlap it), and decode the axis tables they point at.
usage: records.py <0xADDR> [...]"""
import csv
import struct
import sys

base = "/home/linux/code/kuminz-re/.claude/worktrees/cm848-egr-flow-delay/firmware/CM550_J90350.00_analysis/firmware/"
ram = open(base + "J90350.00.ram.bin", "rb").read()
ext = open(base + "J90350.00.extended_ram.bin", "rb").read()
rom = open(base + "J90350.00.rom.bin", "rb").read()
GV = "/home/linux/.claude/jobs/374b0424/tmp/w15/r94/frozen/cm550/global_variables.csv"

rows = []
with open(GV, newline="") as f:
    for r in csv.reader(f):
        if not r or r[0].startswith("#") or r[0] == "address":
            continue
        try:
            rows.append((int(r[0], 16), r[1], r[2] if len(r) > 2 else "", r[3] if len(r) > 3 else ""))
        except ValueError:
            pass

TYPES = {"byte": 1, "char": 1, "uchar": 1, "bool": 1, "undefined": 1, "undefined1": 1, "word": 2, "short": 2,
         "ushort": 2, "undefined2": 2, "dword": 4, "int": 4, "uint": 4, "long": 4, "ulong": 4, "undefined4": 4,
         "pointer": 4}


def size_of(t):
    t = t.strip()
    if t.endswith("*"):
        return 4
    if "[" in t:
        b, n = t.split("[", 1)
        try:
            n = int(n.split("]")[0], 0)
        except ValueError:
            return None
        s = size_of(b)
        return s * n if s else None
    return TYPES.get(t, None)


def mem(addr, n):
    if 0x800000 <= addr and addr + n <= 0x800000 + len(ram):
        return ram[addr - 0x800000:addr - 0x800000 + n]
    if 0x809242 <= addr and addr + n <= 0x809242 + len(ext):
        return ext[addr - 0x809242:addr - 0x809242 + n]
    if addr + n <= len(rom):
        return rom[addr:addr + n]
    return None


def words(addr, n):
    b = mem(addr, 2 * n)
    if b is None:
        return None
    return list(struct.unpack(">%dH" % n, b))


for a in (int(x, 16) for x in sys.argv[1:]):
    b = mem(a, 22)
    print("== record 0x%x" % a)
    if b is None:
        print("  not dumped")
    else:
        xo, xp, xi, yo, yp, yi, zp, nf = struct.unpack(">HIHHIHIH", b)
        print("  x_off %d x_ptr 0x%x x_in %d | y_off %d y_ptr 0x%x y_in %d | z_ptr 0x%x | flag %d" % (
            xo, xp, xi, yo, yp, yi, zp, nf))
        for nm, p in (("x", xp), ("y", yp)):
            w = words(p, 1)
            if w:
                cnt = w[0]
                vals = words(p + 2, cnt // 2) if cnt < 200 else None
                print("  %s axis @0x%x: count %d -> %s" % (nm, p, cnt, vals))
            else:
                print("  %s axis @0x%x: not dumped" % (nm, p))
    for (ra, nm, t, c) in rows:
        sz = size_of(t) or 1
        if a <= ra < a + 22 or (ra < a < ra + sz):
            print("  row 0x%x %s [%s] %s" % (ra, nm, t, c[:110]))
