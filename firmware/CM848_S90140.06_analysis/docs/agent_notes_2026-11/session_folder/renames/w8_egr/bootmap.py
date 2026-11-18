"""Which addresses of the time-shared window does the boot ROM 0x0-0x7F5F touch? (positive control for scan.py)"""
import struct
import sys

sys.path.insert(0, "/home/linux/.claude/jobs/d55ae3c6/tmp/renames/w8_egr")
import scan  # noqa: E402

rom = open(scan.D.ROM, "rb").read()
lo_w, hi_w = 0x3F9800, 0x3FDB40
# low halfword of an address in 0x3f8000..0x3fffff addressed off a 0x400000 base: signed displacement
hits = {}
for off in range(0, 0x7F60, 4):
    word = struct.unpack(">I", rom[off:off + 4])[0]
    opcode = word >> 26
    if lo_w <= word < hi_w:
        hits.setdefault(word, []).append((off, "const"))
    if opcode in (32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45):
        disp = word & 0xFFFF
        ea = 0x400000 + (disp - 0x10000 if disp >= 0x8000 else disp)
        if lo_w <= ea < hi_w:
            hits.setdefault(ea, []).append((off, "ldst %08x" % word))
print("distinct window addresses touched by boot ROM:", len(hits))
for ea in sorted(hits)[:80]:
    print("0x%06x" % ea, hits[ea][:3])
sys.exit(0)
