"""Describer D1 scratch (run 2): re-check the RAM dump facts quoted in the output.
- the fault record table 0x8067c4 (6 bytes: code word, control bits word, 2 more bytes) and which codes carry which lamp bits
- ISTMLM 0x803c02, ISWRTMLM 0x808150, the idle shutdown block 0x80d672-0x80d684, flags words
- DGFULPEN 0x803fb4 (18 bytes), OCRNSTEA 0x803c42, LCFUFHMD / LCFUFHCU
"""
FW = "/home/linux/code/kuminz-re/.claude/worktrees/cm848-egr-flow-delay/firmware/CM550_J90350.00_analysis/firmware"
ram = open(f"{FW}/J90350.00.ram.bin", "rb").read()
ext = open(f"{FW}/J90350.00.extended_ram.bin", "rb").read()
B = 0x800000
EB = 0x809242


def raw(a, n):
    if a - B + n <= len(ram):
        return ram[a - B:a - B + n]
    if a >= EB and a - EB + n <= len(ext):
        return ext[a - EB:a - EB + n]
    return None


def w(a):
    r = raw(a, 2)
    return None if r is None else int.from_bytes(r, "big")


def b(a):
    r = raw(a, 1)
    return None if r is None else r[0]


print("ram dump covers 0x800000-0x%x, extended 0x%x-0x%x" % (B + len(ram) - 1, EB, EB + len(ext) - 1))
by_bit = {0: [], 1: [], 2: [], 3: [], 6: []}
for rec in range(125):
    a = 0x8067c4 + 6 * rec
    code, ctl = w(a), w(a + 2)
    if not code:
        continue
    for bit in by_bit:
        if ctl & (1 << bit):
            by_bit[bit].append(code)
for bit, codes in by_bit.items():
    print(f"control bit {bit}: {len(codes)} codes: {codes}")
print("ISTMLM 0x803c02 =", w(0x803c02), " ISWRTMLM 0x808150 =", w(0x808150))
print("idle shutdown block 0x80d672..0x80d684:", [(hex(a), w(a)) for a in range(0x80d672, 0x80d686, 2)])
print("0x800752/54/56:", w(0x800752), w(0x800754), w(0x800756))
print("flags word 3 0x803c9a = %04x, word 27 0x803cca = %04x, word 28 0x803ccc = %04x, word 18 0x803cb8 = %04x" %
      (w(0x803c9a), w(0x803cca), w(0x803ccc), w(0x803cb8)))
print("DGFULPEN 0x803fb4:", raw(0x803fb4, 18).hex())
print("OCRNSTEA 0x803c42 =", w(0x803c42), " LCFUFHMD 0x80820c =", b(0x80820c), " LCFUFHCU 0x80820d =", b(0x80820d))
print("lamp request word 0x80daac = %04x, OCITWNFG 0x80daae = %s, OCRSFG 0x80dab0 = %s, LCDG* = %s %s %s" %
      (w(0x80daac), w(0x80daae), w(0x80dab0), w(0x80dab2), w(0x80dab4), w(0x80dab6)))
print("active fault list 0x? - see active_dtc_list row; engine_state 0x80d0c8 =", w(0x80d0c8))
print("output bytes 0x80bcf6..0x80bcf9:", raw(0x80bcf6, 4).hex(), " override priorities 0x80bd1a..+31:", raw(0x80bd1a, 32).hex())
print("lamp task: 0x8019d2..d4 =", raw(0x8019d2, 3).hex(), " 0x801a22 =", w(0x801a22), " 0x8019e7 =", b(0x8019e7))
print("EEPROM driver: offset 0x801a86 = %04x, length 0x801a88 = %04x, state 0x801a8a = %s, base 0x801a8e = %s, loaded 0x801a92 = %s"
      % (w(0x801a86), w(0x801a88), raw(0x801a8a, 4).hex(), raw(0x801a8e, 4).hex(), b(0x801a92)))
print("ram_refresh_enable 0x80dc6c =", w(0x80dc6c), " QSPI vector 0x808f20 =", raw(0x808f20, 4).hex())
print("duty cycle: period 0x800006 =", int.from_bytes(raw(0x800006, 4), "big"), " long total 0x805398 =",
      int.from_bytes(raw(0x805398, 4), "big"), " region 0x80bad6 =", b(0x80bad6), " active map 0x80bad7 =", b(0x80bad7))
