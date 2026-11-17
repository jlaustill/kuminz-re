import struct
import sys

ROM = sys.argv[1]
RAM = sys.argv[2]
rom = open(ROM, 'rb').read()
ram = open(RAM, 'rb').read()
BASE = 0x3FA000

addrs = [0x3fb02e, 0x3fb030, 0x3fb032, 0x3fb034, 0x3fb036, 0x3fb03e, 0x3fb042, 0x3fb046, 0x3fb048, 0x3fb04a, 0x3fb04e, 0x3fb050,
         0x3fb052, 0x3fb054, 0x3fb056, 0x3fb058, 0x3fb05a, 0x3fb05c, 0x3fb05e, 0x3fb060, 0x3fb062, 0x3fb064, 0x3fb066, 0x3fb068,
         0x3fb06a, 0x3fb06c, 0x3fb06e, 0x3fb076, 0x3fb07e, 0x3fb098, 0x3fb09a, 0x3fb09c, 0x3fb09e, 0x3fb0a0, 0x3fb0a2,
         0x3fcce8, 0x3fccf0, 0x3fccf2, 0x3fccf4, 0x3fccf6, 0x3fccfe, 0x3fcd00, 0x3fcd04, 0x3fcd08, 0x3fcd0c, 0x3fcd10, 0x3fcd14,
         0x3fcd16, 0x3fcd18, 0x3fcd20, 0x3fcd28, 0x3fd7de, 0x3fd8cc, 0x3fd8ce, 0x3fd8d0]
LS = {32: 'lwz', 33: 'lwzu', 34: 'lbz', 35: 'lbzu', 36: 'stw', 37: 'stwu', 38: 'stb', 39: 'stbu',
      40: 'lhz', 41: 'lhzu', 42: 'lha', 43: 'lhau', 44: 'sth', 45: 'sthu', 14: 'addi', 24: 'ori'}
lows = {a: a & 0xffff for a in addrs}
hits = {a: [] for a in addrs}
ptr = []
for off in range(0, 0x7f60, 4):
    w = struct.unpack('>I', rom[off:off + 4])[0]
    op = w >> 26
    if op in LS:
        lo = w & 0xffff
        for a in addrs:
            if lo == lows[a]:
                hits[a].append((hex(off), LS[op]))
    if w in addrs:
        ptr.append((hex(off), hex(w)))
bad = {hex(a): h for a, h in hits.items() if h}
print('boot-ROM instructions with a matching low halfword:', bad if bad else 'none for all %d words' % len(addrs))
print('boot-ROM 32-bit words equal to one of the addresses:', ptr if ptr else 'none')


def v(a, w=2, s=False):
    o = a - BASE
    return int.from_bytes(ram[o:o + w], 'big', signed=s)


print('--- calibration block 0x40771a..0x40776e (unsigned / signed)')
for a in range(0x40771a, 0x407770, 2):
    print(hex(a), v(a), v(a, 2, True))
print('--- diag / H-bridge / over-current / thermal calibration 0x407770..0x4077de')
for a in range(0x407770, 0x4077de, 2):
    print(hex(a), v(a), v(a, 2, True))
print('--- EEPROM-mirror flags')
for a in [0x3fd8cc, 0x3fd8ce, 0x3fd8d0, 0x3fd8d2, 0x3fd8d4, 0x3fd8d6, 0x3fd7de, 0x3fdcea]:
    print(hex(a), v(a), v(a, 2, True))
