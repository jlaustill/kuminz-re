"""Skeptic: find calls / jumps / address loads of a ROM address: jsr (abs).l, jmp (abs).l, bsr.w / bsr.s / bra,
pea / lea / move.l #imm, and raw 32-bit pointers (tables).
usage: callers.py <rom> <target hex>..."""
import struct
import sys

rom = open(sys.argv[1], "rb").read()
for t in sys.argv[2:]:
    target = int(t, 16)
    print(f"== 0x{target:x}")
    pat = struct.pack(">I", target)
    off = 0
    while True:
        off = rom.find(pat, off)
        if off < 0:
            break
        prev = rom[off - 2:off].hex() if off >= 2 else ""
        kind = {"4eb9": "jsr", "4ef9": "jmp", "4879": "pea", "41f9": "lea a0", "43f9": "lea a1", "45f9": "lea a2",
                "47f9": "lea a3", "49f9": "lea a4", "4bf9": "lea a5"}.get(prev, "ptr/imm (prev %s)" % prev)
        print(f"   0x{off - 2:05x}: {kind}{'' if off % 2 == 0 else '  (odd offset)'}")
        off += 1
    # bsr.w / bra.w / bcc.w with 16-bit displacement, bsr.s with 8-bit
    for a in range(0, len(rom) - 3, 2):
        op = rom[a]
        if (op & 0xF0) != 0x60:
            continue
        d8 = rom[a + 1]
        if d8 == 0:
            d = struct.unpack_from(">h", rom, a + 2)[0]
            if a + 2 + d == target:
                print(f"   0x{a:05x}: b{'sr' if op == 0x61 else 'cc/ra'}.w (op 0x{op:02x})")
        elif d8 != 0xFF:
            d = d8 - 0x100 if d8 & 0x80 else d8
            if a + 2 + d == target and op == 0x61:
                print(f"   0x{a:05x}: bsr.s")
