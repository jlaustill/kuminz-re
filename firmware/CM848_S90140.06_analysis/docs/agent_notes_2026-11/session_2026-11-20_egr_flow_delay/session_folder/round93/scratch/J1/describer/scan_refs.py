"""Round 93 J1 describer (read-only): every way the CM550 ROM could reach a code address.
Scans for absolute-long operands (any alignment), bsr/bra/bcc .w/.l/.s displacements, PC-relative jsr/jmp/lea/pea
(d16,PC) and 4-byte table pointers.
usage: scan_refs.py <rom> <0xTARGET> [...]"""
import sys

rom = open(sys.argv[1], "rb").read()


def s8(b):
    return b - 256 if b > 127 else b


def s16(w):
    return w - 65536 if w > 32767 else w


for arg in sys.argv[2:]:
    target = int(arg, 16)
    hits = []
    pat = target.to_bytes(4, "big")
    i = rom.find(pat)
    while i != -1:
        hits.append((i, "absolute long / pointer (aligned)" if i % 2 == 0 else "absolute long bytes (odd offset)"))
        i = rom.find(pat, i + 1)
    for pc in range(0, len(rom) - 4, 2):
        op = int.from_bytes(rom[pc:pc + 2], "big")
        ext = int.from_bytes(rom[pc + 2:pc + 4], "big")
        # Bcc / BRA / BSR
        if (op & 0xf000) == 0x6000:
            d8 = op & 0xff
            if d8 == 0x00:
                if pc + 2 + s16(ext) == target:
                    hits.append((pc, f"branch.w opcode {op:04x}"))
            elif d8 == 0xff:
                d32 = int.from_bytes(rom[pc + 2:pc + 6], "big")
                if d32 & 0x80000000:
                    d32 -= 1 << 32
                if pc + 2 + d32 == target:
                    hits.append((pc, f"branch.l opcode {op:04x}"))
            else:
                if pc + 2 + s8(d8) == target:
                    hits.append((pc, f"branch.s opcode {op:04x}"))
        # jsr / jmp (d16,PC)
        if op in (0x4eba, 0x4efa) and pc + 2 + s16(ext) == target:
            hits.append((pc, "jsr (d16,PC)" if op == 0x4eba else "jmp (d16,PC)"))
        # lea (d16,PC),An ; pea (d16,PC)
        if (op & 0xf1ff) == 0x41fa and pc + 2 + s16(ext) == target:
            hits.append((pc, "lea (d16,PC)"))
        if op == 0x487a and pc + 2 + s16(ext) == target:
            hits.append((pc, "pea (d16,PC)"))
    print(f"== 0x{target:x}")
    for pc, what in sorted(set(hits)):
        print(f"  0x{pc:05x}: {what}  bytes {rom[pc:pc + 6].hex(' ')}")
    if not hits:
        print("  (no reference of any scanned form)")
