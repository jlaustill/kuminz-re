"""Print each 22-byte table_lookup_2d_arguments_t record from the CM550 RAM dumps, and the axis tables its pointers
point at (when the pointer lands in RAM; ROM pointers above 0x40000 are not dumped).
usage: dump_records.py 0xADDR [...]"""
import struct
import sys

FW = "/home/linux/code/kuminz-re/.claude/worktrees/cm848-egr-flow-delay/firmware/CM550_J90350.00_analysis/firmware/"
ram = open(FW + "J90350.00.ram.bin", "rb").read()
ext = open(FW + "J90350.00.extended_ram.bin", "rb").read()
rom = open(FW + "J90350.00.rom.bin", "rb").read()


def read(addr, n):
    if 0x800000 <= addr and addr + n <= 0x800000 + len(ram):
        return ram[addr - 0x800000:addr - 0x800000 + n]
    if 0x809242 <= addr and addr + n <= 0x809242 + len(ext):
        return ext[addr - 0x809242:addr - 0x809242 + n]
    if addr + n <= len(rom):
        return rom[addr:addr + n]
    return None


def words(addr, n):
    b = read(addr, 2 * n)
    if b is None:
        return None
    return list(struct.unpack(">" + "H" * n, b))


def axis(ptr):
    w = words(ptr, 1)
    if w is None:
        return f"0x{ptr:x}: not dumped"
    count = w[0]
    n = count // 2
    vals = words(ptr + 2, n) if n < 64 else None
    return f"0x{ptr:x}: byte count {count} -> {n} values {vals}"


for arg in sys.argv[1:]:
    a = int(arg, 16)
    b = read(a, 22)
    if b is None:
        print(f"== 0x{a:x}: not in a dump")
        continue
    xo, xp, xi, yo, yp, yi, zp, ni = struct.unpack(">HIHHIHIH", b)
    print(f"== 0x{a:x}: x_axis_offset {xo} x_axis_pointer 0x{xp:x} x_input {xi} | y_axis_offset {yo} "
          f"y_axis_pointer 0x{yp:x} y_input {yi} | z_values_pointer 0x{zp:x} no_interpolation_flag {ni}")
    print("   x axis", axis(xp))
    print("   y axis", axis(yp))
    xw = words(xp, 1)
    yw = words(yp, 1)
    if xw and yw:
        nx, ny = xw[0] // 2, yw[0] // 2
        z = words(zp, nx * ny) if nx * ny < 400 else None
        if z is None:
            print(f"   z 0x{zp:x}: not dumped ({nx} x {ny})")
        else:
            print(f"   z 0x{zp:x}: {nx} x {ny} grid")
            for r in range(ny):
                print("     ", z[r * nx:(r + 1) * nx])
