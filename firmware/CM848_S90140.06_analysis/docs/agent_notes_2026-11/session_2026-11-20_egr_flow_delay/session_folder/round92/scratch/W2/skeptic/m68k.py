"""Skeptic: a small MC68000 / CPU32 disassembler (the subset this ROM uses), written from the instruction set
encoding so the batch can be checked without trusting any earlier scan.
usage: m68k.py <rom> <start hex> <end hex>
An opcode it does not know prints as '.word' and the cursor moves on by 2, so check such lines by hand."""
import struct
import sys

SIZES = {0: "b", 1: "w", 2: "l"}
CC = ["t", "f", "hi", "ls", "cc", "cs", "ne", "eq", "vc", "vs", "pl", "mi", "ge", "lt", "gt", "le"]


class Decoder:
    def __init__(self, rom, base=0):
        self.rom = rom
        self.base = base
        self.pc = 0

    def u16(self):
        v = struct.unpack_from(">H", self.rom, self.pc - self.base)[0]
        self.pc += 2
        return v

    def u32(self):
        v = struct.unpack_from(">I", self.rom, self.pc - self.base)[0]
        self.pc += 4
        return v

    def s16(self):
        v = self.u16()
        return v - 0x10000 if v & 0x8000 else v

    def imm(self, size):
        if size == "b":
            return self.u16() & 0xFF
        if size == "w":
            return self.u16()
        return self.u32()

    def index_ext(self, base_name, ext_pc):
        ext = self.u16()
        reg = ("a" if ext & 0x8000 else "d") + str((ext >> 12) & 7)
        isize = "l" if ext & 0x0800 else "w"
        scale = 1 << ((ext >> 9) & 3)
        if ext & 0x0100:
            # full format (CPU32: no memory indirection)
            bs = (ext >> 7) & 1
            is_ = (ext >> 6) & 1
            bdsize = (ext >> 4) & 3
            bd = 0
            if bdsize == 2:
                bd = self.s16()
            elif bdsize == 3:
                bd = self.u32()
                if bd & 0x80000000:
                    bd -= 1 << 32
            parts = []
            if bd or bdsize > 1:
                if base_name == "pc":
                    parts.append("0x%x" % ((ext_pc + bd) & 0xFFFFFFFF))
                else:
                    parts.append("%s0x%x" % ("-" if bd < 0 else "", abs(bd)))
            if not bs:
                parts.append(base_name)
            if not is_:
                parts.append("%s.%s*%d" % (reg, isize, scale))
            return "(" + ",".join(parts) + ")[full]"
        disp = ext & 0xFF
        if disp & 0x80:
            disp -= 0x100
        if base_name == "pc":
            return "(0x%x,pc,%s.%s*%d)" % ((ext_pc + disp) & 0xFFFFFFFF, reg, isize, scale)
        return "(%s0x%x,%s,%s.%s*%d)" % ("-" if disp < 0 else "", abs(disp), base_name, reg, isize, scale)

    def ea(self, mode, reg, size):
        if mode == 0:
            return "d%d" % reg
        if mode == 1:
            return "a%d" % reg
        if mode == 2:
            return "(a%d)" % reg
        if mode == 3:
            return "(a%d)+" % reg
        if mode == 4:
            return "-(a%d)" % reg
        if mode == 5:
            d = self.s16()
            return "(%s0x%x,a%d)" % ("-" if d < 0 else "", abs(d), reg)
        if mode == 6:
            return self.index_ext("a%d" % reg, 0)
        if mode == 7:
            if reg == 0:
                v = self.s16()
                return "(0x%x).w" % (v & 0xFFFFFFFF)
            if reg == 1:
                return "(0x%x).l" % self.u32()
            if reg == 2:
                ext_pc = self.pc
                d = self.s16()
                return "(0x%x,pc)" % ((ext_pc + d) & 0xFFFFFFFF)
            if reg == 3:
                ext_pc = self.pc
                return self.index_ext("pc", ext_pc)
            if reg == 4:
                return "#0x%x" % self.imm(size)
        raise ValueError("bad ea")

    def movem_list(self, mask, predec):
        names = []
        for i in range(16):
            if mask & (1 << i):
                if predec:
                    n = 15 - i
                else:
                    n = i
                names.append(("d%d" % n) if n < 8 else ("a%d" % (n - 8)))
        return "/".join(names)

    def one(self):
        start = self.pc
        op = self.u16()
        top = op >> 12
        mode = (op >> 3) & 7
        reg = op & 7
        dn = (op >> 9) & 7
        opm = (op >> 6) & 7
        try:
            text = self.decode(op, top, mode, reg, dn, opm, start)
        except (ValueError, struct.error):
            text = None
        if text is None:
            self.pc = start + 2
            return start, ".word 0x%04x" % op
        return start, text

    def decode(self, op, top, mode, reg, dn, opm, start):
        if top == 0:
            if op & 0x0100:
                if mode == 1:
                    return None  # movep
                name = ["btst", "bchg", "bclr", "bset"][(op >> 6) & 3]
                return "%s d%d,%s" % (name, dn, self.ea(mode, reg, "b"))
            kind = (op >> 9) & 7
            if kind == 4:
                name = ["btst", "bchg", "bclr", "bset"][(op >> 6) & 3]
                bit = self.u16() & 0xFF
                return "%s #%d,%s" % (name, bit, self.ea(mode, reg, "b"))
            name = {0: "ori", 1: "andi", 2: "subi", 3: "addi", 5: "eori", 6: "cmpi"}.get(kind)
            sz = (op >> 6) & 3
            if name is None or sz == 3:
                return None
            size = SIZES[sz]
            if mode == 7 and reg == 4:
                v = self.imm(size)
                return "%s.%s #0x%x,%s" % (name, size, v, "ccr" if size == "b" else "sr")
            v = self.imm(size)
            return "%s.%s #0x%x,%s" % (name, size, v, self.ea(mode, reg, size))
        if top in (1, 2, 3):
            size = {1: "b", 3: "w", 2: "l"}[top]
            src = self.ea(mode, reg, size)
            dmode = (op >> 6) & 7
            if dmode == 1:
                return "movea.%s %s,a%d" % (size, src, dn)
            dst = self.ea(dmode, dn, size)
            return "move.%s %s,%s" % (size, src, dst)
        if top == 4:
            if op == 0x4E71:
                return "nop"
            if op == 0x4E75:
                return "rts"
            if op == 0x4E73:
                return "rte"
            if op == 0x4E77:
                return "rtr"
            if op == 0x4E70:
                return "reset"
            if op == 0x4E72:
                return "stop #0x%x" % self.u16()
            if op == 0x4AFC:
                return "illegal"
            if (op & 0xFFF0) == 0x4E40:
                return "trap #%d" % (op & 15)
            if (op & 0xFFF8) == 0x4E50:
                return "link a%d,#%d" % (reg, self.s16())
            if (op & 0xFFF8) == 0x4E58:
                return "unlk a%d" % reg
            if (op & 0xFFF8) == 0x4E60:
                return "move a%d,usp" % reg
            if (op & 0xFFF8) == 0x4E68:
                return "move usp,a%d" % reg
            if (op & 0xFFC0) == 0x4E80:
                return "jsr %s" % self.ea(mode, reg, "l")
            if (op & 0xFFC0) == 0x4EC0:
                return "jmp %s" % self.ea(mode, reg, "l")
            if (op & 0xFFF8) == 0x4840:
                return "swap d%d" % reg
            if (op & 0xFFF8) == 0x4880:
                return "ext.w d%d" % reg
            if (op & 0xFFF8) == 0x48C0:
                return "ext.l d%d" % reg
            if (op & 0xFFF8) == 0x49C0:
                return "extb.l d%d" % reg
            if (op & 0xFFC0) == 0x4840:
                return "pea %s" % self.ea(mode, reg, "l")
            if (op & 0xFB80) == 0x4880:
                size = "l" if op & 0x40 else "w"
                mask = self.u16()
                if op & 0x0400:
                    src = self.ea(mode, reg, size)
                    return "movem.%s %s,%s" % (size, src, self.movem_list(mask, False))
                return "movem.%s %s,%s" % (size, self.movem_list(mask, mode == 4), self.ea(mode, reg, size))
            if (op & 0xF1C0) == 0x41C0:
                return "lea %s,a%d" % (self.ea(mode, reg, "l"), dn)
            if (op & 0xF1C0) == 0x4180:
                return "chk.w %s,d%d" % (self.ea(mode, reg, "w"), dn)
            if (op & 0xFFC0) == 0x40C0:
                return "move.w sr,%s" % self.ea(mode, reg, "w")
            if (op & 0xFFC0) == 0x44C0:
                return "move.w %s,ccr" % self.ea(mode, reg, "w")
            if (op & 0xFFC0) == 0x46C0:
                return "move.w %s,sr" % self.ea(mode, reg, "w")
            if (op & 0xFFC0) == 0x4AC0:
                return "tas %s" % self.ea(mode, reg, "b")
            if (op & 0xFFC0) == 0x4800:
                return "nbcd %s" % self.ea(mode, reg, "b")
            if (op & 0xFF80) == 0x4C00:
                ext = self.u16()
                dq = (ext >> 12) & 7
                dr = ext & 7
                signed = bool(ext & 0x0800)
                wide = bool(ext & 0x0400)
                src = self.ea(mode, reg, "l")
                if op & 0x40:
                    name = "divs" if signed else "divu"
                    if wide:
                        return "%s.l %s,d%d:d%d" % (name, src, dr, dq)
                    if dr != dq:
                        return "%sl.l %s,d%d:d%d" % (name, src, dr, dq)
                    return "%s.l %s,d%d" % (name, src, dq)
                name = "muls" if signed else "mulu"
                if wide:
                    return "%s.l %s,d%d:d%d" % (name, src, dr, dq)
                return "%s.l %s,d%d" % (name, src, dq)
            sz = (op >> 6) & 3
            kind = (op >> 8) & 15
            if sz != 3 and kind in (0, 2, 4, 6, 10):
                name = {0: "negx", 2: "clr", 4: "neg", 6: "not", 10: "tst"}[kind]
                size = SIZES[sz]
                return "%s.%s %s" % (name, size, self.ea(mode, reg, size))
            return None
        if top == 5:
            sz = (op >> 6) & 3
            if sz == 3:
                cond = CC[(op >> 8) & 15]
                if mode == 1:
                    target_pc = self.pc
                    d = self.s16()
                    return "db%s d%d,0x%x" % (cond, reg, (target_pc + d) & 0xFFFFFFFF)
                return "s%s %s" % (cond, self.ea(mode, reg, "b"))
            size = SIZES[sz]
            v = dn or 8
            name = "subq" if op & 0x0100 else "addq"
            return "%s.%s #%d,%s" % (name, size, v, self.ea(mode, reg, size))
        if top == 6:
            cond = (op >> 8) & 15
            name = {0: "bra", 1: "bsr"}.get(cond, "b" + CC[cond])
            d = op & 0xFF
            target_pc = self.pc
            if d == 0:
                d = self.s16()
                suffix = ".w"
            elif d == 0xFF:
                d = self.u32()
                if d & 0x80000000:
                    d -= 1 << 32
                suffix = ".l"
            else:
                if d & 0x80:
                    d -= 0x100
                suffix = ".s"
            return "%s%s 0x%x" % (name, suffix, (target_pc + d) & 0xFFFFFFFF)
        if top == 7:
            if op & 0x0100:
                return None
            v = op & 0xFF
            if v & 0x80:
                v -= 0x100
            return "moveq #%d,d%d" % (v, dn)
        if top in (8, 12):
            if opm == 3:
                return "%s.w %s,d%d" % ("divu" if top == 8 else "mulu", self.ea(mode, reg, "w"), dn)
            if opm == 7:
                return "%s.w %s,d%d" % ("divs" if top == 8 else "muls", self.ea(mode, reg, "w"), dn)
            if top == 12 and (op & 0x01F8) == 0x0140:
                return "exg d%d,d%d" % (dn, reg)
            if top == 12 and (op & 0x01F8) == 0x0148:
                return "exg a%d,a%d" % (dn, reg)
            if top == 12 and (op & 0x01F8) == 0x0188:
                return "exg d%d,a%d" % (dn, reg)
            if (op & 0x01F0) == 0x0100:
                name = "sbcd" if top == 8 else "abcd"
                if mode == 1:
                    return "%s -(a%d),-(a%d)" % (name, reg, dn)
                return "%s d%d,d%d" % (name, reg, dn)
            name = "or" if top == 8 else "and"
            size = SIZES[opm & 3]
            if opm & 4:
                return "%s.%s d%d,%s" % (name, size, dn, self.ea(mode, reg, size))
            return "%s.%s %s,d%d" % (name, size, self.ea(mode, reg, size), dn)
        if top in (9, 13):
            name = "sub" if top == 9 else "add"
            if opm == 3:
                return "%sa.w %s,a%d" % (name, self.ea(mode, reg, "w"), dn)
            if opm == 7:
                return "%sa.l %s,a%d" % (name, self.ea(mode, reg, "l"), dn)
            size = SIZES[opm & 3]
            if opm & 4:
                if mode == 0:
                    return "%sx.%s d%d,d%d" % (name, size, reg, dn)
                if mode == 1:
                    return "%sx.%s -(a%d),-(a%d)" % (name, size, reg, dn)
                return "%s.%s d%d,%s" % (name, size, dn, self.ea(mode, reg, size))
            return "%s.%s %s,d%d" % (name, size, self.ea(mode, reg, size), dn)
        if top == 11:
            if opm == 3:
                return "cmpa.w %s,a%d" % (self.ea(mode, reg, "w"), dn)
            if opm == 7:
                return "cmpa.l %s,a%d" % (self.ea(mode, reg, "l"), dn)
            size = SIZES[opm & 3]
            if opm & 4:
                if mode == 1:
                    return "cmpm.%s (a%d)+,(a%d)+" % (size, reg, dn)
                return "eor.%s d%d,%s" % (size, dn, self.ea(mode, reg, size))
            return "cmp.%s %s,d%d" % (size, self.ea(mode, reg, size), dn)
        if top == 14:
            sz = (op >> 6) & 3
            left = bool(op & 0x0100)
            if sz == 3:
                kind = (op >> 9) & 3
                if (op >> 11) & 1:
                    return None  # bit field instructions (not on CPU32)
                name = ["as", "ls", "rox", "ro"][kind] + ("l" if left else "r")
                return "%s.w %s" % (name, self.ea(mode, reg, "w"))
            kind = (op >> 3) & 3
            name = ["as", "ls", "rox", "ro"][kind] + ("l" if left else "r")
            size = SIZES[sz]
            if op & 0x20:
                return "%s.%s d%d,d%d" % (name, size, dn, reg)
            return "%s.%s #%d,d%d" % (name, size, dn or 8, reg)
        return None


def disassemble(rom, start, end):
    dec = Decoder(rom)
    dec.pc = start
    out = []
    while dec.pc < end:
        addr, text = dec.one()
        raw = rom[addr:dec.pc].hex()
        out.append((addr, raw, text))
    return out


if __name__ == "__main__":
    data = open(sys.argv[1], "rb").read()
    for addr, raw, text in disassemble(data, int(sys.argv[2], 16), int(sys.argv[3], 16)):
        print("%06x: %-24s %s" % (addr, raw, text))
