"""Scan the CM550 ROM for 'move.l #imm,(abs).l' (23fc <imm> <dst>) stores of table pointers into RAM and report
every base A with stores to both A+2 and A+8 (the x / y pointers of a 14-byte 1-D record) that is not a known record.
Also list the 'move.l #imm,(d16,An)' (2?7c <imm> <d16>) stores with d16 = 2 or 8 and the instruction address, so the
address-register form can be matched by hand."""
import re
import struct

rom = open("/home/linux/code/kuminz-re/.claude/worktrees/cm848-egr-flow-delay/firmware/CM550_J90350.00_analysis/"
           "firmware/J90350.00.rom.bin", "rb").read()
known = {0x80004a, 0x800058, 0x800102, 0x800118, 0x800126, 0x800136, 0x800144, 0x800184, 0x800192, 0x8001ea,
         0x80020e, 0x80024e, 0x80025c, 0x80026a, 0x80db20, 0x80db2e, 0x80058e, 0x80059c, 0x8005fe, 0x800632,
         0x8006aa, 0x80071e, 0x80072c, 0x80073a, 0x801a3e, 0x801a4c, 0x801c0e, 0x801c1c, 0x801c2a, 0x801c38,
         0x801e30, 0x801e3e, 0x801e4c, 0x801e5a, 0x801e68, 0x8036c6, 0x8036d4, 0x8005b4, 0x800278, 0x800286,
         0x800294}
dst = {}
for m in re.finditer(re.escape(bytes.fromhex("23fc")), rom):
    i = m.start()
    if i % 2:
        continue
    imm, d = struct.unpack(">II", rom[i + 2:i + 10])
    if 0x800000 <= d < 0x810000 and (0x60000 <= imm < 0x70000 or 0x800000 <= imm < 0x810000):
        dst.setdefault(d, []).append((i, imm))
for d in sorted(dst):
    base = d - 2
    if base + 8 in dst and base not in known:
        print("abs pair base 0x%x: +2 %s / +8 %s" % (base, [(hex(i), hex(v)) for i, v in dst[d]],
                                                     [(hex(i), hex(v)) for i, v in dst[base + 8]]))
# address-register form: move.l #imm,(d16,An) = 0010 aaa1 0111 1100 -> 0x217c | (n << 9)
count = 0
for i in range(0, len(rom) - 10, 2):
    op = struct.unpack(">H", rom[i:i + 2])[0]
    if (op & 0xF1FF) == 0x217C:
        imm, d16 = struct.unpack(">Ih", rom[i + 2:i + 8])
        if d16 in (2, 8) and (0x60000 <= imm < 0x70000 or 0x800000 <= imm < 0x810000):
            count += 1
            print("reg form at 0x%x: move.l #0x%x,(0x%x,a%d)" % (i, imm, d16, (op >> 9) & 7))
print("reg-form stores:", count)
