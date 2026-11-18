import sys
sys.path.insert(0, '/home/linux/.claude/jobs/d55ae3c6/tmp/renames/scratch_W5_combustion')
from peek import *
print("== CBL block 0x40a466-0x40a47e (hex, unsigned, signed)")
for a in range(0x40a466,0x40a480,2):
    print(hex(a), hex(w(a)), w(a), w(a,True))
print("== CBR block 0x40a480-0x40a500")
for a in range(0x40a480,0x40a502,2):
    print(hex(a), hex(w(a)), w(a), w(a,True))
print("== CBR cal scalars 0x4059d6-0x405a0e")
for a in range(0x4059d6,0x405a10,2):
    print(hex(a), hex(w(a)), w(a), w(a,True))
print("== CBL cal 0x405234-0x40523e")
for a in range(0x405234,0x40523e,2):
    print(hex(a), hex(w(a)), w(a), w(a,True))
