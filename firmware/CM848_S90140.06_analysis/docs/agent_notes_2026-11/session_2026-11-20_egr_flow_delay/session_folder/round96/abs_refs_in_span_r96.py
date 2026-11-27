"""Round 96: every big-endian 32-bit value in the CM550 ROM that falls in [start, end) - absolute operands and pointer
tables (m68k reaches 0x80xxxx only with absolute long addressing or a register base). usage: abs_refs_in_span_r96.py <hex start> <hex end>"""
import collections
import struct
import sys

rom = open("/home/linux/code/kuminz-re/.claude/worktrees/cm848-egr-flow-delay/firmware/CM550_J90350.00_analysis/firmware/J90350.00.rom.bin", "rb").read()
start, end = int(sys.argv[1], 16), int(sys.argv[2], 16)
hits = collections.defaultdict(list)
for pc in range(0, len(rom) - 3, 2):
    v = struct.unpack_from(">I", rom, pc)[0]
    if start <= v < end:
        hits[v].append(pc)
for v in sorted(hits):
    print(f"0x{v:x}: {len(hits[v])} at {', '.join(f'0x{p:x}' for p in hits[v][:8])}")
print(len(hits), "distinct targets")
