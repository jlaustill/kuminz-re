"""Find every reference in a CM550 (m68k, big-endian) ROM to the given addresses: 32-bit absolute values (pointers,
jsr / jmp / lea / movea abs.l and #imm), PC-relative branches (bra / bsr / Bcc .b / .w / .l, DBcc), (d16,pc) forms
(jsr / jmp / lea / pea) and CPU32 full-format (bd,pc) forms. Scans every even offset, so a hit inside data or a
misaligned decode is possible: each hit prints its bytes for a check.  usage: references_to.py <rom> <hex address>..."""
import sys

rom = open(sys.argv[1], "rb").read()
targets = {int(a, 16): a for a in sys.argv[2:]}
hits = {t: [] for t in targets}


def word(a):
    return int.from_bytes(rom[a:a + 2], "big")


def signed(a, n):
    return int.from_bytes(rom[a:a + n], "big", signed=True)


def add(t, a, kind):
    if t in hits:
        hits[t].append((a, kind, rom[a:a + 8].hex(" ")))


PC16 = {0x4EBA: "jsr (d16,pc)", 0x4EFA: "jmp (d16,pc)", 0x487A: "pea (d16,pc)"}
PC16.update({0x41FA + (r << 9): f"lea (d16,pc),a{r}" for r in range(8)})
PCFULL = {0x4EBB: "jsr (bd,pc)", 0x4EFB: "jmp (bd,pc)", 0x487B: "pea (bd,pc)"}
PCFULL.update({0x41FB + (r << 9): f"lea (bd,pc),a{r}" for r in range(8)})
for a in range(0, len(rom) - 6, 2):
    v = int.from_bytes(rom[a:a + 4], "big")
    if v in targets:
        add(v, a, "32-bit value")
    w = word(a)
    if 0x6000 <= w <= 0x6FFF:
        low = w & 0xFF
        name = {0x60: "bra", 0x61: "bsr"}.get(w >> 8, "bcc")
        if low == 0:
            add(a + 2 + signed(a + 2, 2), a, name + ".w")
        elif low == 0xFF:
            add(a + 2 + signed(a + 2, 4), a, name + ".l")
        else:
            add(a + 2 + (low - 256 if low > 127 else low), a, name + ".b")
    if (w & 0xF0F8) == 0x50C8:
        add(a + 2 + signed(a + 2, 2), a, "dbcc")
    if w in PC16:
        add(a + 2 + signed(a + 2, 2), a, PC16[w])
    if w in PCFULL:
        ext = word(a + 2)
        if ext & 0x0100:
            size = (ext >> 4) & 3
            if size == 2:
                add(a + 2 + signed(a + 4, 2), a, PCFULL[w] + " bd.w")
            elif size == 3:
                add(a + 2 + signed(a + 4, 4), a, PCFULL[w] + " bd.l")
for t, label in targets.items():
    print(f"{label}: {len(hits[t])} reference(s)")
    for a, kind, b in hits[t][:8]:
        print(f"    0x{a:05x} {kind:22} {b}")
