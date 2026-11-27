"""Every absolute-long reference to CM550 enable words in a range: raw bytes, the decoded access and the following
andi mask and branch, plus every '// Function:' entry of the .cpp whose start lies within 0x400 bytes before it
(overlapping entries show the same code under two names). usage: direct_tests.py <repo> <lo hex> <hi hex>"""
import re
import struct
import sys

repo = sys.argv[1]
lo, hi = int(sys.argv[2], 16), int(sys.argv[3], 16)
F = repo + "/firmware/CM550_J90350.00_analysis"
rom = open(F + "/firmware/J90350.00.rom.bin", "rb").read()
funcs = []
for line in open(F + "/output/J90350.00.ghidra.cpp", errors="replace"):
    m = re.match(r"^// Function: (\S+) @ 0x([0-9a-fA-F]+)", line)
    if m:
        funcs.append((int(m.group(2), 16), m.group(1)))
funcs.sort()


def w(a):
    return struct.unpack(">H", rom[a:a + 2])[0]


def cc(op):
    names = ["bra", "bsr", "bhi", "bls", "bcc", "bcs", "bne", "beq", "bvc", "bvs", "bpl", "bmi", "bge", "blt", "bgt",
             "ble"]
    return names[(op >> 8) & 15]


for target in range(lo, hi):
    pat = struct.pack(">I", target)
    i = rom.find(pat)
    while i != -1:
        op = w(i - 2)
        text = "?"
        mask = None
        nxt = i + 4
        if op & 0xF1FF == 0x3039:
            text = "move.w (0x%x).l,d%d" % (target, (op >> 9) & 7)
            n = w(nxt)
            if n & 0xFFF8 == 0x0240:
                mask = w(nxt + 2)
                text += " ; andi.w #0x%x,d%d" % (mask, n & 7)
                nxt += 4
            elif n & 0xFFF8 == 0x0280:
                mask = struct.unpack(">I", rom[nxt + 2:nxt + 6])[0]
                text += " ; andi.l #0x%x,d%d" % (mask, n & 7)
                nxt += 6
            b = w(nxt)
            if b & 0xF000 == 0x6000:
                disp = b & 0xFF
                if disp == 0:
                    dest = nxt + 2 + struct.unpack(">h", rom[nxt + 2:nxt + 4])[0]
                else:
                    dest = nxt + 2 + (disp - 256 if disp > 127 else disp)
                text += " ; %s 0x%x" % (cc(b), dest)
            else:
                text += " ; next %04x" % b
        elif op & 0xF1FF == 0x1039:
            text = "move.b (0x%x).l,d%d  <-- BYTE" % (target, (op >> 9) & 7)
        elif op & 0xF1FF == 0x207C:
            text = "movea.l #0x%x,a%d" % (target, (op >> 9) & 7)
        elif w(i - 2) == 0x23FC or w(i - 6) == 0x23FC:
            text = "move.l #imm,(abs).l  (pointer store; bytes %s)" % rom[i - 6:i + 8].hex()
        else:
            text = "?? bytes %s" % rom[i - 6:i + 8].hex()
        near = [f for f in funcs if i - 0x400 <= f[0] <= i - 2][-3:]
        print("0x%06x ref@0x%05x insn@0x%05x %-62s | %s" % (
            target, i, i - 2, text, " / ".join("%s@0x%x" % (n, a) for a, n in near)))
        i = rom.find(pat, i + 1)
