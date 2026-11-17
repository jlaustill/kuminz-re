import struct
import sys

root = sys.argv[1]
rom = open(root + '/firmware/CM848_S90140.06_analysis/originals/cm848_rom.bin', 'rb').read()
ram = open(root + '/firmware/CM848_S90140.06_analysis/originals/cm848_ram.bin', 'rb').read()
BASE = 0x3FA000
OFF = 0x409AD6 - 0x6F6F0

tabs = [
    ('L170 ax', 0x409B2C, 11), ('L170 val', 0x409B42, 11),
    ('L171 ax', 0x409B58, 11), ('L171 val', 0x409B6E, 11),
    ('L172 x', 0x409B84, 9), ('L172 y', 0x409B96, 9), ('L172 g', 0x409BA8, 64),
    ('L173 x', 0x409C28, 9), ('L173 y', 0x409C3A, 9), ('L173 g', 0x409C4C, 64),
    ('L174 x', 0x409CCC, 9), ('L174 y', 0x409CDE, 9), ('L174 g', 0x409CF0, 64),
    ('L175 x', 0x409D70, 9), ('L175 y', 0x409D82, 9), ('L175 g', 0x409D94, 64),
    ('L176 ax', 0x409E14, 11), ('L176 val', 0x409E2A, 11),
]
allsame = True
for name, a, n in tabs:
    r = ram[a - BASE:a - BASE + 2 * n]
    ra = a - OFF
    ro = rom[ra:ra + 2 * n]
    same = (r == ro)
    allsame = allsame and same
    print(name, hex(a), 'rom', hex(ra), 'match' if same else 'DIFF')
print('all match', allsame)
