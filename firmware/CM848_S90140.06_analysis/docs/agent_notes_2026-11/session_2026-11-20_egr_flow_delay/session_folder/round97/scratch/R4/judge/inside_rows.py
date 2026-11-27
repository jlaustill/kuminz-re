"""List every frozen CM550 global row inside [lo, hi] and count ROM 4-byte constants pointing at each,
plus any 4-byte constant pointing anywhere inside the range (any alignment), and decompile uses of the name."""
import csv
import re
import sys

frozen = '/home/linux/.claude/jobs/374b0424/tmp/w15/r97/frozen/cm550/'
rom = open('/home/linux/code/kuminz-re/.claude/worktrees/cm848-egr-flow-delay/firmware/CM550_J90350.00_analysis/firmware/J90350.00.rom.bin', 'rb').read()
cpp = open(frozen + 'J90350.00.ghidra.cpp', errors='replace').read()
rows = []
for r in csv.reader(open(frozen + 'global_variables.csv')):
    if r and r[0].startswith('0x'):
        rows.append(r)

lo = int(sys.argv[1], 16)
hi = int(sys.argv[2], 16)
# any 4-byte big-endian value in [lo, hi] anywhere in the ROM
hits = []
for i in range(0, len(rom) - 3):
    v = int.from_bytes(rom[i:i + 4], 'big')
    if lo <= v <= hi:
        hits.append((i, v))
print(f"range 0x{lo:x}-0x{hi:x}: {len(hits)} ROM 4-byte values inside")
for i, v in hits[:60]:
    print(f"   rom 0x{i:x} -> 0x{v:x}")
n = 0
for r in rows:
    a = int(r[0], 16)
    if lo <= a <= hi:
        n += 1
        name = r[1]
        uses = len(re.findall(r'\b_?' + re.escape(name) + r'\b', cpp)) if name else 0
        print(f"{r[0]} {name} [{r[2]}] cpp_uses={uses} | {(r[3][:90] if len(r) > 3 else '')}")
print('rows inside:', n)
