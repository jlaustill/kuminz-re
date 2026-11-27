"""Read-only heuristic scan of the CM550 RAM dumps for 14-byte lookupTableInterpolation records:
+0 even offset 2..0x200, +2 pointer to a table (ROM 0x60000-0x6ffff or RAM 0x806000-0x80a000), +8 pointer likewise,
+0xc word 0. For RAM tables the byte count must be even and >= the offset."""
REPO = "/home/linux/code/kuminz-re/.claude/worktrees/cm848-egr-flow-delay"
FW = REPO + "/firmware/CM550_J90350.00_analysis/firmware/"
ram = open(FW + "J90350.00.ram.bin", "rb").read()
ext = open(FW + "J90350.00.extended_ram.bin", "rb").read()
KNOWN = {0x80004a, 0x800058, 0x800102, 0x800118, 0x800126, 0x800136, 0x800144, 0x800184, 0x800192, 0x8001ea,
         0x80020e, 0x80024e, 0x80025c, 0x80026a, 0x80058e, 0x80059c, 0x8005fe, 0x800632, 0x8006aa, 0x80071e,
         0x80072c, 0x80073a, 0x801a3e, 0x801a4c, 0x801c0e, 0x801c1c, 0x801c2a, 0x801c38, 0x801e30, 0x801e3e,
         0x801e4c, 0x801e5a, 0x801e68, 0x8036c6, 0x8036d4, 0x80db20, 0x80db2e, 0x8005b4}
KNOWN |= {0x80a792 + 14 * n for n in range(25)}


def word_at(a):
    if 0x800000 <= a < 0x800000 + len(ram) - 1:
        return int.from_bytes(ram[a - 0x800000:a - 0x800000 + 2], "big")
    if 0x809242 <= a < 0x809242 + len(ext) - 1:
        return int.from_bytes(ext[a - 0x809242:a - 0x809242 + 2], "big")
    return None


def dword_at(a):
    h, l = word_at(a), word_at(a + 2)
    return None if h is None or l is None else (h << 16) | l


def table_ok(p, off):
    if 0x60000 <= p < 0x70000:
        return p % 2 == 0
    if 0x806000 <= p < 0x80a000 and p % 2 == 0:
        n = word_at(p)
        return n is not None and n % 2 == 0 and 2 <= n <= 0x200 and off <= n
    return False


for base, data in ((0x800000, ram), (0x809242, ext)):
    for a in range(base, base + len(data) - 14, 2):
        off, xp, vp, flag = word_at(a), dword_at(a + 2), dword_at(a + 8), word_at(a + 12)
        if off is None or xp is None or vp is None:
            continue
        if off % 2 or not 2 <= off <= 0x200 or flag != 0:
            continue
        if table_ok(xp, off) and table_ok(vp, 0) and xp != vp:
            print(f"0x{a:x} offset {off} axis 0x{xp:x} values 0x{vp:x} input {word_at(a + 6)}"
                  + ("" if a in KNOWN else "   <-- NEW"))
