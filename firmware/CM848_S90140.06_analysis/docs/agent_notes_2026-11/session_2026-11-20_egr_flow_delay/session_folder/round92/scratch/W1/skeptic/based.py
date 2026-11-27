"""Skeptic: look for (d16,An) accesses that could reach 0x803c92-0x803ca1 from an address register loaded with a
lower base (movea.l #imm,An / lea abs.l,An with imm in [LO, 0x803c92)). For each base load, sweep the next 0x400 bytes
with the disassembler and print instructions whose text contains '(d,aN)' with base + d inside the target range.
Read-only."""
import re
import struct
import sys

sys.path.insert(0, "/home/linux/.claude/jobs/374b0424/tmp/w15/r92/scratch/W1/skeptic")
import m68k  # noqa: E402

d = m68k.d
T_LO, T_HI = 0x803C92, 0x803CA2
LO = 0x803000
hits = 0
loads = 0
for i in range(0, len(d) - 6, 2):
    op = struct.unpack(">H", d[i:i + 2])[0]
    reg = None
    if (op & 0xF1FF) == 0x207C:      # movea.l #imm,An
        reg = (op >> 9) & 7
    elif (op & 0xF1FF) == 0x41F9:    # lea abs.l,An
        reg = (op >> 9) & 7
    if reg is None:
        continue
    v = struct.unpack(">I", d[i + 2:i + 6])[0]
    if not (LO <= v < T_HI):
        continue
    loads += 1
    rows = m68k.disassemble(i, min(len(d), i + 0x400))
    for pc, raw, text in rows[1:]:
        # stop when the register is reloaded
        if re.search(r"(movea\.l|lea) .*,a%d$" % reg, text):
            break
        for m in re.finditer(r"\((-?\d+),a%d[,)]" % reg, text):
            disp = int(m.group(1))
            if T_LO <= v + disp < T_HI and not (T_LO <= v < T_HI and disp == 0):
                print("base 0x%x in a%d at 0x%x -> 0x%05x %s  (=0x%x)" % (v, reg, i, pc, text, v + disp))
                hits += 1
        if text in ("rts", "rte"):
            break
print("base loads examined", loads, "hits", hits)
