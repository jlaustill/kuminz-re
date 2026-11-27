"""Scratch (read-only): every absolute-long reference in the CM550 ROM to the given RAM addresses, with the bytes around
it and a hand decode of the common 68k forms that carry an abs.l operand (the operand at +2 or +4 of the opcode).
usage: hits68k.py <repo> <addr hex> [...]"""
import re
import sys

repo = sys.argv[1]
rom = open(repo + "/firmware/CM550_J90350.00_analysis/firmware/J90350.00.rom.bin", "rb").read()
CPP = repo + "/firmware/CM550_J90350.00_analysis/output/J90350.00.ghidra.cpp"
funcs = sorted({(int(m.group(2), 16), m.group(1)) for m in
                (re.match(r"^// Function: (\S+) @ 0x([0-9a-fA-F]+)", l) for l in open(CPP, errors="replace")) if m})
SIZE = {0: "b", 1: "b", 3: "w", 2: "l"}  # move size field (bits 13-12)


def w(a):
    return int.from_bytes(rom[a:a + 2], "big")


def decode(op_at, hit):
    """Return a text decode if the opcode at op_at uses an abs.l operand at hit."""
    op = w(op_at)
    rel = hit - op_at
    # move.<sz> (xxx).l,<dst>  src mode 7 reg 1 = 0x39 in bits 5-0; dst Dn = mode 0
    if (op >> 14) == 0 and (op >> 12) in (1, 2, 3) and (op & 0x3f) == 0x39 and rel == 2:
        sz = SIZE[(op >> 12) & 3]
        dreg, dmode = (op >> 9) & 7, (op >> 6) & 7
        if dmode == 0:
            return f"move.{sz} (0x{int.from_bytes(rom[hit:hit+4],'big'):x}).l,d{dreg}   READ"
        if dmode == 1:
            return f"movea.{sz} (abs).l,a{dreg}   READ"
        if dmode == 7 and dreg == 1:
            return f"move.{sz} (abs).l,(0x{int.from_bytes(rom[hit+4:hit+8],'big'):x}).l   READ (copy)"
        return f"move.{sz} (abs).l,<mode {dmode} reg {dreg}>   READ"
    # move.<sz> <src>,(xxx).l  dst mode 7 reg 1 -> bits 11-6 = 001 111 = 0x03c0 pattern
    if (op >> 14) == 0 and (op >> 12) in (1, 2, 3) and ((op >> 6) & 0x3f) == 0x0f:
        sz = SIZE[(op >> 12) & 3]
        smode, sreg = (op >> 3) & 7, op & 7
        ext = 0
        if smode == 7 and sreg == 4:  # immediate
            ext = 2 if sz in "bw" else 4
        elif smode == 7 and sreg == 1:
            ext = 4
        elif smode == 5:
            ext = 2
        if rel == 2 + ext:
            return f"move.{sz} <mode {smode} reg {sreg}>,(abs).l   WRITE"
    # immediate ops: ori 0x00, andi 0x02, subi 0x04, addi 0x06, eori 0x0a, cmpi 0x0c ; size bits 7-6; ea abs.l 0x39
    if (op & 0xff3f) in (0x0039, 0x0239, 0x0439, 0x0639, 0x0a39, 0x0c39):
        name = {0x00: "ori", 0x02: "andi", 0x04: "subi", 0x06: "addi", 0x0a: "eori", 0x0c: "cmpi"}[op >> 8]
        szb = (op >> 6) & 3
        sz = "bwl"[szb]
        ext = 4 if sz == "l" else 2
        imm = int.from_bytes(rom[op_at + 2:op_at + 2 + ext], "big")
        if rel == 2 + ext:
            kind = "TEST" if name == "cmpi" else "WRITE (read-modify-write)"
            return f"{name}.{sz} #0x{imm:x},(abs).l   {kind}"
    # btst/bchg/bclr/bset #n,(xxx).l : 0x0839 / 0x0879 / 0x08b9 / 0x08f9
    if op in (0x0839, 0x0879, 0x08b9, 0x08f9) and rel == 4:
        name = {0x0839: "btst", 0x0879: "bchg", 0x08b9: "bclr", 0x08f9: "bset"}[op]
        n = w(op_at + 2) & 0xff
        kind = "TEST" if name == "btst" else "WRITE"
        return f"{name} #{n},(abs).l   {kind} (byte at the address: bit {n})"
    # btst Dn,(xxx).l : 0000 rrr1 0011 1001
    if (op & 0xf1ff) == 0x0139 and rel == 2:
        return f"btst d{(op >> 9) & 7},(abs).l   TEST (dynamic bit)"
    # tst.<sz> (xxx).l : 0x4a39 / 0x4a79 / 0x4ab9
    if op in (0x4a39, 0x4a79, 0x4ab9) and rel == 2:
        return f"tst.{'bwl'[(op >> 6) & 3]} (abs).l   TEST (whole)"
    # clr.<sz> (xxx).l : 0x4239 / 0x4279 / 0x42b9
    if op in (0x4239, 0x4279, 0x42b9) and rel == 2:
        return f"clr.{'bwl'[(op >> 6) & 3]} (abs).l   WRITE"
    # lea (xxx).l,An : 0100 rrr1 1111 1001
    if (op & 0xf1ff) == 0x41f9 and rel == 2:
        return f"lea (abs).l,a{(op >> 9) & 7}   ADDRESS"
    # pea (xxx).l
    if op == 0x4879 and rel == 2:
        return "pea (abs).l   ADDRESS"
    # movea.l #imm,An : 0010 rrr0 0111 1100
    if (op & 0xf1ff) == 0x207c and rel == 2:
        return f"movea.l #abs,a{(op >> 9) & 7}   ADDRESS"
    # move.l #imm,Dn : 0010 rrr0 0011 1100
    if (op & 0xf1ff) == 0x203c and rel == 2:
        return f"move.l #abs,d{(op >> 9) & 7}   ADDRESS"
    # and.w/or.w/cmp.w/add.w/sub.w (xxx).l,Dn : xxxx rrr0 01 111 001
    if (op & 0x01ff) == 0x0079 and (op >> 12) in (0x8, 0x9, 0xb, 0xc, 0xd) and rel == 2:
        name = {0x8: "or", 0x9: "sub", 0xb: "cmp", 0xc: "and", 0xd: "add"}[op >> 12]
        return f"{name}.w (abs).l,d{(op >> 9) & 7}   READ"
    # and.w/or.w Dn,(xxx).l : xxxx rrr1 01 111 001
    if (op & 0x01ff) == 0x0179 and (op >> 12) in (0x8, 0xc, 0xd, 0x9, 0xb) and rel == 2:
        name = {0x8: "or", 0x9: "sub", 0xb: "eor", 0xc: "and", 0xd: "add"}[op >> 12]
        return f"{name}.w d{(op >> 9) & 7},(abs).l   WRITE (read-modify-write)"
    return None


for arg in sys.argv[2:]:
    target = int(arg, 16)
    pat = target.to_bytes(4, "big")
    for m in re.finditer(re.escape(pat), rom):
        hit = m.start()
        f = [x for x in funcs if x[0] <= hit]
        fname = f"{f[-1][1]}@0x{f[-1][0]:x}" if f else "?"
        found = None
        for back in (2, 4, 6, 8):
            d = decode(hit - back, hit)
            if d:
                found = (hit - back, d)
                break
        ctx = rom[hit - 6:hit + 10].hex(" ")
        if found:
            nxt = rom[hit + 4:hit + 12].hex(" ")
            print(f"0x{target:x} @0x{hit:x} op@0x{found[0]:x} {found[1]:55} next: {nxt}  [{fname}]")
        else:
            print(f"0x{target:x} @0x{hit:x} UNDECODED bytes: {ctx}  [{fname}]")
