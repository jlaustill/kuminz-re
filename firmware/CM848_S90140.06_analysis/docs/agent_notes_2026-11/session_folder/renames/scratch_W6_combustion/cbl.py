import sys
sys.path.insert(0, "/home/linux/.claude/jobs/d55ae3c6/tmp/renames/scratch_W6_combustion")
from w6 import *

print("min limit: x axis rpm:", [v * 0.125 for v in axis(0x40523e)])
print("min limit: y axis fuel mm3:", [round(v * 0.0679, 1) for v in axis(0x405266)])
print("min grid unique (counts):", uniq(0x405288, 304, True))
print("max limit: x axis rpm:", [v * 0.125 for v in axis(0x4054e8)])
print("max limit: y axis fuel mm3:", [round(v * 0.0679, 1) for v in axis(0x405510)])
print("max grid unique:", uniq(0x405532, 304, True))
print("mcf: x axis rpm:", [v * 0.125 for v in axis(0x405792)])
print("mcf: y axis density counts:", axis(0x4057b4), [round(v * 6.103515625e-5, 4) for v in axis(0x4057b4)])
g = grid(0x4057d6, 16, 16)
print("mcf grid rows (y = density row):")
for r in g:
    print(r)
print("mcf grid lb/min unique:", sorted(set(round(v / 128.0, 1) for r in g for v in r)))
