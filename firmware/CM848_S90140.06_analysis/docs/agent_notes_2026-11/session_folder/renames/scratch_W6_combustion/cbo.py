import sys
sys.path.insert(0, "/home/linux/.claude/jobs/d55ae3c6/tmp/renames/scratch_W6_combustion")
from w6 import *

print("CBR scalars (unsigned / signed):")
for a in range(0x4059d6, 0x4059fc, 2):
    print(hex(a), w(a), s(a))
print("CBO scalars:")
for a in range(0x4059fc, 0x405a10, 2):
    print(hex(a), w(a), s(a))
print("CBO charge temperature adj axis (signed 1/64 F):", axis(0x405a10, True), [round(v / 64.0, 1) for v in axis(0x405a10, True)])
print("   values:", axis(0x405a20, True))
print("FSNOx axis:", axis(0x405a30), [round(v / 8192.0, 3) for v in axis(0x405a30)])
print("   values:", axis(0x405a46))
print("composite axis:", axis(0x405a5c, True))
print("   values (timing counts):", axis(0x405a6c, True))
print("timing delta axis:", axis(0x405a7c, True))
print("   values:", axis(0x405a8c, True))
print("torque to fuel limits 0x405a9c/9e:", s(0x405a9c), s(0x405a9e))
print("torque-to-fuel gain x axis rpm:", [v * 0.125 for v in axis(0x405aa0)])
print("RAM CBO words 0x40a518..0x40a54c:")
for a in range(0x40a518, 0x40a550, 2):
    print(hex(a), w(a), s(a))
