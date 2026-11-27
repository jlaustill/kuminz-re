"""Skeptic: a small MC68000 / CPU32 disassembler (the integer subset this ROM uses), written from the instruction
formats, because llvm-mc's m68k decoder rejects andi / tst / cmpi and resynchronises silently.
usage: m68k.py START END   (hex ROM offsets; linear sweep from START, START must be an instruction start)"""
import struct
import sys

ROM = "/home/linux/code/kuminz-re/.claude/worktrees/cm848-egr-flow-delay/firmware/CM550_J90350.00_analysis/firmware/J90350.00.rom.bin"
d = open(ROM, "rb").read()
CC = ["t", "f", "hi", "ls", "cc", "cs", "ne", "eq", "vc", "vs", "pl", "mi", "ge", "lt", "gt", "le"]
SZ = {0: "b", 1: "w", 2: "l"}


class Bad(Exception):
    pass


class Dis:
    def __init__(self, pc):
        self.pc = pc
        self.start = pc

    def w(self):
        v = struct.unpack(">H", d[self.pc:self.pc + 2])[0]
        self.pc += 2
        return v

    def l(self):
        v = struct.unpack(">I", d[self.pc:self.pc + 4])[0]
        self.pc += 4
        return v

    def s16(self):
        v = self.w()
        return v - 0x10000 if v & 0x8000 else v

    def imm(self, size):
        if size == 0:
            return "#0x%x" % (self.w() & 0xFF)
        if size == 1:
            return "#0x%x" % self.w()
        return "#0x%x" % self.l()

    def index(self, base, ext_pc):
        ext = self.w()
        reg = "%s%d" % ("a" if ext & 0x8000 else "d", (ext >> 12) & 7)
        size = "l" if ext & 0x800 else "w"
        scale = 1 << ((ext >> 9) & 3)
        if ext & 0x100:
            # full format (68020 / CPU32): base displacement, optional base / index suppress, no memory indirection
            if ext & 0x7:
                raise Bad("memory indirect extension word %04x" % ext)
            bdsize = (ext >> 4) & 3
            if bdsize == 2:
                bd = self.s16()
            elif bdsize == 3:
                bd = self.l()
            elif bdsize == 1:
                bd = 0
            else:
                raise Bad("reserved bd size in %04x" % ext)
            parts = ["0x%x" % (bd & 0xFFFFFFFF)]
            if not ext & 0x80:
                parts.append(base)
            if not ext & 0x40:
                parts.append("%s.%s*%d" % (reg, size, scale))
            return "(" + ",".join(parts) + ")"
        disp = ext & 0xFF
        if disp & 0x80:
            disp -= 0x100
        if base == "pc":
            return "(0x%x,pc,%s.%s*%d)" % (ext_pc + disp, reg, size, scale)
        return "(%d,%s,%s.%s*%d)" % (disp, base, reg, size, scale)

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
            return "(%d,a%d)" % (self.s16(), reg)
        if mode == 6:
            return self.index("a%d" % reg, 0)
        if reg == 0:
            v = self.s16()
            return "(0x%x).w" % (v & 0xFFFFFFFF)
        if reg == 1:
            return "(0x%x).l" % self.l()
        if reg == 2:
            base = self.pc
            return "(0x%x,pc)" % (base + self.s16())
        if reg == 3:
            base = self.pc
            return self.index("pc", base)
        if reg == 4:
            if size is None:
                raise Bad("immediate without size")
            return self.imm(size)
        raise Bad("ea mode 7 reg %d" % reg)

    def movem_list(self, mask, predec):
        names = ["d%d" % i for i in range(8)] + ["a%d" % i for i in range(8)]
        if predec:
            names = names[::-1]
        return "/".join(n for i, n in enumerate(names) if mask & (1 << i)) or "none"

    def one(self):
        op = self.w()
        top = op >> 12
        mode, reg = (op >> 3) & 7, op & 7
        r9 = (op >> 9) & 7
        size = (op >> 6) & 3
        if top == 0:
            if op & 0x0100:
                if mode == 1:
                    raise Bad("movep")
                name = ["btst", "bchg", "bclr", "bset"][size]
                return "%s d%d,%s" % (name, r9, self.ea(mode, reg, 0))
            kind = r9
            if kind == 4:
                name = ["btst", "bchg", "bclr", "bset"][size]
                bit = self.w() & 0xFF
                return "%s #%d,%s" % (name, bit, self.ea(mode, reg, 0))
            if size == 3:
                raise Bad("0x0 size 3")
            name = {0: "ori", 1: "andi", 2: "subi", 3: "addi", 5: "eori", 6: "cmpi"}.get(kind)
            if name is None:
                raise Bad("0x0 kind %d" % kind)
            if mode == 7 and reg == 4:
                i = self.imm(size)
                return "%s.%s %s,%s" % (name, SZ[size], i, "ccr" if size == 0 else "sr")
            i = self.imm(size)
            return "%s.%s %s,%s" % (name, SZ[size], i, self.ea(mode, reg, size))
        if top in (1, 2, 3):
            msize = {1: 0, 3: 1, 2: 2}[top]
            src = self.ea(mode, reg, msize)
            dmode = (op >> 6) & 7
            dst = self.ea(dmode, r9, msize)
            name = "movea" if dmode == 1 else "move"
            return "%s.%s %s,%s" % (name, SZ[msize], src, dst)
        if top == 4:
            if op == 0x4E75:
                return "rts"
            if op == 0x4E73:
                return "rte"
            if op == 0x4E71:
                return "nop"
            if op == 0x4E77:
                return "rtr"
            if op == 0x4E72:
                return "stop #0x%x" % self.w()
            if (op & 0xFFF0) == 0x4E40:
                return "trap #%d" % (op & 15)
            if (op & 0xFFF8) == 0x4E50:
                return "link.w a%d,#%d" % (reg, self.s16())
            if (op & 0xFFF8) == 0x4808:
                v = self.l()
                return "link.l a%d,#%d" % (reg, v - (1 << 32) if v & 0x80000000 else v)
            if (op & 0xFFF8) == 0x4E58:
                return "unlk a%d" % reg
            if (op & 0xFFF0) == 0x4E60:
                return "move usp (%04x)" % op
            if (op & 0xFFC0) == 0x4E80:
                return "jsr %s" % self.ea(mode, reg, None)
            if (op & 0xFFC0) == 0x4EC0:
                return "jmp %s" % self.ea(mode, reg, None)
            if (op & 0xF1C0) == 0x41C0:
                return "lea %s,a%d" % (self.ea(mode, reg, None), r9)
            if (op & 0xF1C0) == 0x4180:
                return "chk.w %s,d%d" % (self.ea(mode, reg, 1), r9)
            if (op & 0xFFF8) == 0x4840:
                return "swap d%d" % reg
            if (op & 0xFFF8) == 0x4880:
                return "ext.w d%d" % reg
            if (op & 0xFFF8) == 0x48C0:
                return "ext.l d%d" % reg
            if (op & 0xFFF8) == 0x49C0:
                return "extb.l d%d" % reg
            if (op & 0xFFC0) == 0x4840:
                return "pea %s" % self.ea(mode, reg, None)
            if (op & 0xFB80) == 0x4880:
                msz = "l" if op & 0x40 else "w"
                mask = self.w()
                if op & 0x400:
                    return "movem.%s %s,%s" % (msz, self.ea(mode, reg, None), self.movem_list(mask, False))
                return "movem.%s %s,%s" % (msz, self.movem_list(mask, mode == 4), self.ea(mode, reg, None))
            if (op & 0xFFC0) == 0x40C0:
                return "move.w sr,%s" % self.ea(mode, reg, 1)
            if (op & 0xFFC0) == 0x44C0:
                return "move.w %s,ccr" % self.ea(mode, reg, 1)
            if (op & 0xFFC0) == 0x46C0:
                return "move.w %s,sr" % self.ea(mode, reg, 1)
            if (op & 0xFFC0) == 0x4AC0:
                return "tas %s" % self.ea(mode, reg, 0)
            if (op & 0xFF80) == 0x4C00:
                ext = self.w()
                src = self.ea(mode, reg, 2)
                dq, dr = (ext >> 12) & 7, ext & 7
                sign = "s" if ext & 0x800 else "u"
                big = bool(ext & 0x400)
                if op & 0x40:
                    if big or dq != dr:
                        return "div%s%s.l %s,d%d:d%d" % (sign, "" if big else "l", src, dr, dq)
                    return "div%s.l %s,d%d" % (sign, src, dq)
                if big:
                    return "mul%s.l %s,d%d:d%d" % (sign, src, dr, dq)
                return "mul%s.l %s,d%d" % (sign, src, dq)
            base = op & 0xFF00
            names = {0x4000: "negx", 0x4200: "clr", 0x4400: "neg", 0x4600: "not", 0x4A00: "tst"}
            if base in names and size != 3:
                return "%s.%s %s" % (names[base], SZ[size], self.ea(mode, reg, size))
            if (op & 0xFFC0) == 0x4800:
                return "nbcd %s" % self.ea(mode, reg, 0)
            raise Bad("0x4 op %04x" % op)
        if top == 5:
            if size == 3:
                cc = (op >> 8) & 15
                if mode == 1:
                    base = self.pc
                    return "db%s d%d,0x%x" % (CC[cc] if cc > 1 else ("t" if cc == 0 else "ra"), reg, base + self.s16())
                return "s%s %s" % (CC[cc], self.ea(mode, reg, 0))
            data = r9 or 8
            name = "subq" if op & 0x100 else "addq"
            return "%s.%s #%d,%s" % (name, SZ[size], data, self.ea(mode, reg, size))
        if top == 6:
            cc = (op >> 8) & 15
            disp = op & 0xFF
            base = self.pc
            if disp == 0:
                target = base + self.s16()
                suffix = ".w"
            elif disp == 0xFF:
                v = self.l()
                target = base + (v - (1 << 32) if v & 0x80000000 else v)
                suffix = ".l"
            else:
                target = base + (disp - 0x100 if disp & 0x80 else disp)
                suffix = ".s"
            name = "bra" if cc == 0 else "bsr" if cc == 1 else "b" + CC[cc]
            return "%s%s 0x%x" % (name, suffix, target)
        if top == 7:
            if op & 0x100:
                raise Bad("0x7 bit 8")
            v = op & 0xFF
            return "moveq #%d,d%d" % (v - 0x100 if v & 0x80 else v, r9)
        if top in (8, 0xC):
            name = "or" if top == 8 else "and"
            if size == 3:
                mname = ("div" if top == 8 else "mul") + ("s" if op & 0x100 else "u")
                return "%s.w %s,d%d" % (mname, self.ea(mode, reg, 1), r9)
            if op & 0x100:
                if mode in (0, 1):
                    if top == 0xC and (op & 0xF8) in (0x40, 0x48, 0x88):
                        kinds = {0x40: ("d", "d"), 0x48: ("a", "a"), 0x88: ("d", "a")}[op & 0xF8]
                        return "exg %s%d,%s%d" % (kinds[0], r9, kinds[1], reg)
                    raise Bad("abcd/sbcd")
                return "%s.%s d%d,%s" % (name, SZ[size], r9, self.ea(mode, reg, size))
            return "%s.%s %s,d%d" % (name, SZ[size], self.ea(mode, reg, size), r9)
        if top in (9, 0xD):
            name = "sub" if top == 9 else "add"
            if size == 3:
                asz = 2 if op & 0x100 else 1
                return "%sa.%s %s,a%d" % (name, SZ[asz], self.ea(mode, reg, asz), r9)
            if op & 0x100:
                if mode == 0:
                    return "%sx.%s d%d,d%d" % (name, SZ[size], reg, r9)
                if mode == 1:
                    return "%sx.%s -(a%d),-(a%d)" % (name, SZ[size], reg, r9)
                return "%s.%s d%d,%s" % (name, SZ[size], r9, self.ea(mode, reg, size))
            return "%s.%s %s,d%d" % (name, SZ[size], self.ea(mode, reg, size), r9)
        if top == 0xB:
            if size == 3:
                asz = 2 if op & 0x100 else 1
                return "cmpa.%s %s,a%d" % (SZ[asz], self.ea(mode, reg, asz), r9)
            if op & 0x100:
                if mode == 1:
                    return "cmpm.%s (a%d)+,(a%d)+" % (SZ[size], reg, r9)
                return "eor.%s d%d,%s" % (SZ[size], r9, self.ea(mode, reg, size))
            return "cmp.%s %s,d%d" % (SZ[size], self.ea(mode, reg, size), r9)
        if top == 0xE:
            if size == 3:
                kind = (op >> 9) & 3
                name = ["as", "ls", "rox", "ro"][kind] + ("l" if op & 0x100 else "r")
                if op & 0x800:
                    raise Bad("bitfield op")
                return "%s.w %s" % (name, self.ea(mode, reg, 1))
            kind = (op >> 3) & 3
            name = ["as", "ls", "rox", "ro"][kind] + ("l" if op & 0x100 else "r")
            if op & 0x20:
                return "%s.%s d%d,d%d" % (name, SZ[size], r9, reg)
            return "%s.%s #%d,d%d" % (name, SZ[size], r9 or 8, reg)
        if top == 0xF:
            if (op & 0xFFC0) == 0xF800:
                ext = self.w()
                dx = (ext >> 12) & 7
                sign = "s" if ext & 0x800 else "u"
                rnd = "n" if ext & 0x400 else ""
                tsz = SZ[(ext >> 6) & 3]
                if ext & 0x100:
                    return "tbl%s%s.%s %s,d%d" % (sign, rnd, tsz, self.ea(mode, reg, None), dx)
                return "tbl%s%s.%s d%d:d%d,d%d" % (sign, rnd, tsz, reg, ext & 7, dx)
            raise Bad("0xF op %04x" % op)
        raise Bad("op %04x" % op)


def disassemble(start, end):
    pc = start
    out = []
    while pc < end:
        dis = Dis(pc)
        try:
            text = dis.one()
            npc = dis.pc
        except (Bad, struct.error, KeyError, IndexError) as e:
            text = ".word 0x%04x   ; ?? %s" % (struct.unpack(">H", d[pc:pc + 2])[0], e)
            npc = pc + 2
        out.append((pc, d[pc:npc].hex(), text))
        pc = npc
    return out


if __name__ == "__main__":
    s, e = int(sys.argv[1], 16), int(sys.argv[2], 16)
    for pc, raw, text in disassemble(s, e):
        print("%06x  %-20s %s" % (pc, raw, text))
