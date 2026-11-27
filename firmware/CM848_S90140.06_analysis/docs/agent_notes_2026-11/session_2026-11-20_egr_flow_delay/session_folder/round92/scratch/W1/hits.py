"""Classify every absolute-long reference to an address range in the CM550 ROM (read / write / address)."""
import re
import struct
import sys

REPO = "/home/linux/code/kuminz-re/.claude/worktrees/cm848-egr-flow-delay/firmware/CM550_J90350.00_analysis"
rom = open(REPO + "/firmware/J90350.00.rom.bin", "rb").read()
funcs = []
for line in open(REPO + "/output/J90350.00.ghidra.cpp", errors="replace"):
    m = re.match(r"^// Function: (\S+) @ 0x([0-9a-fA-F]+)", line)
    if m:
        funcs.append((int(m.group(2), 16), m.group(1)))
funcs.sort()


def func_of(a):
    best = None
    for fa, fn in funcs:
        if fa <= a:
            best = (fa, fn)
        else:
            break
    return best


def w(a):
    return struct.unpack(">H", rom[a:a + 2])[0]


def classify(h):
    """h = offset of the 4-byte address. Return (start, text, kind)."""
    op2 = w(h - 2)
    reg = (op2 >> 9) & 7
    lo = op2 & 0xF1FF
    table2 = {
        0x3039: ("move.w abs,D%d" % reg, "read.w"), 0x1039: ("move.b abs,D%d" % reg, "read.b"),
        0x2039: ("move.l abs,D%d" % reg, "read.l"), 0x3079: ("movea.w abs,A%d" % reg, "read.w"),
        0xC079: ("and.w abs,D%d" % reg, "read.w"), 0xC039: ("and.b abs,D%d" % reg, "read.b"),
        0x8079: ("or.w abs,D%d" % reg, "read.w"), 0xB079: ("cmp.w abs,D%d" % reg, "read.w"),
        0xB039: ("cmp.b abs,D%d" % reg, "read.b"),
        0x0139: ("btst D%d,abs" % reg, "read.b"), 0x01F9: ("bset D%d,abs" % reg, "WRITE.b"),
        0x01B9: ("bclr D%d,abs" % reg, "WRITE.b"), 0x0179: ("bchg D%d,abs" % reg, "WRITE.b"),
        0x8179: ("or.w D%d,abs" % reg, "WRITE.w"), 0xC179: ("and.w D%d,abs" % reg, "WRITE.w"),
        0x8139: ("or.b D%d,abs" % reg, "WRITE.b"), 0xC139: ("and.b D%d,abs" % reg, "WRITE.b"),
        0x41F9: ("lea abs,A%d" % reg, "ADDRESS"), 0x207C: ("movea.l #abs,A%d" % reg, "ADDRESS"),
        0x203C: ("move.l #abs,D%d" % reg, "ADDRESS"),
        0x30B9: ("move.w abs,(A%d)" % reg, "read.w"), 0x3179: ("move.w abs,(d16,A%d)" % reg, "read.w"),
    }
    if lo in table2:
        t, k = table2[lo]
        return h - 2, t, k
    table2x = {
        0x4A79: ("tst.w abs", "read.w"), 0x4A39: ("tst.b abs", "read.b"), 0x4279: ("clr.w abs", "WRITE.w"),
        0x4239: ("clr.b abs", "WRITE.b"), 0x4879: ("pea abs", "ADDRESS"), 0x2F3C: ("move.l #abs,-(sp)", "ADDRESS"),
        0x33F9: ("move.w abs,abs (source)", "read.w"),
    }
    if op2 in table2x:
        t, k = table2x[op2]
        return h - 2, t, k
    if (op2 & 0xFFF8) in (0x33C0, 0x13C0, 0x23C0, 0x33C8, 0x33D0, 0x33D8):
        return h - 2, "move %04x Rn/(An),abs" % op2, "WRITE"
    op4 = w(h - 4)
    imm = w(h - 2)
    table4 = {
        0x0839: ("btst #%d,abs" % imm, "read.b"), 0x08F9: ("bset #%d,abs" % imm, "WRITE.b"),
        0x08B9: ("bclr #%d,abs" % imm, "WRITE.b"), 0x0879: ("bchg #%d,abs" % imm, "WRITE.b"),
        0x0279: ("andi.w #0x%x,abs" % imm, "WRITE.w"), 0x0079: ("ori.w #0x%x,abs" % imm, "WRITE.w"),
        0x0239: ("andi.b #0x%x,abs" % imm, "WRITE.b"), 0x0039: ("ori.b #0x%x,abs" % imm, "WRITE.b"),
        0x0C79: ("cmpi.w #0x%x,abs" % imm, "read.w"), 0x0C39: ("cmpi.b #0x%x,abs" % imm, "read.b"),
        0x33FC: ("move.w #0x%x,abs" % imm, "WRITE.w"), 0x13FC: ("move.b #0x%x,abs" % imm, "WRITE.b"),
    }
    if op4 in table4:
        t, k = table4[op4]
        return h - 4, t, k
    if (op4 & 0xFFF8) == 0x33E8:
        return h - 4, "move.w (d16,A%d),abs" % (op4 & 7), "WRITE.w"
    op6 = w(h - 6)
    if op6 == 0x33F9:
        return h - 6, "move.w abs,abs (destination)", "WRITE.w"
    return None, "?? %04x %04x %04x" % (op6, op4, op2), "UNKNOWN"


def follow(h):
    """Decode the next instruction after the access for the mask (andi / btst / cmpi on the register)."""
    a = h + 4
    nxt = w(a)
    if (nxt & 0xFFF8) == 0x0240:
        return "andi.w #0x%04x,D%d" % (w(a + 2), nxt & 7)
    if (nxt & 0xFFF8) == 0x0200:
        return "andi.b #0x%02x,D%d" % (w(a + 2) & 0xFF, nxt & 7)
    if (nxt & 0xFFF8) == 0x0800:
        return "btst #%d,D%d" % (w(a + 2), nxt & 7)
    if (nxt & 0xFFF8) == 0x0280:
        return "andi.l #0x%08x,D%d" % (struct.unpack('>I', rom[a + 2:a + 6])[0], nxt & 7)
    if (nxt & 0xF1F8) == 0xC040:
        return "and.w D%d,D%d" % (nxt & 7, (nxt >> 9) & 7)
    return "next %04x %04x %04x" % (nxt, w(a + 2), w(a + 4))


lo, hi = int(sys.argv[1], 16), int(sys.argv[2], 16)
for target in range(lo, hi):
    pat = bytes([0, 0x80, (target >> 8) & 0xFF, target & 0xFF])
    i = rom.find(pat)
    while i != -1:
        s, t, k = classify(i)
        f = func_of(i)
        extra = follow(i) if k.startswith("read") and t.startswith("move") else ""
        print("0x%06x 0x%05x %-10s %-28s %-26s %s @0x%x" % (
            target, s if s is not None else i, k, t, extra, f[1] if f else "?", f[0] if f else 0))
        i = rom.find(pat, i + 1)
