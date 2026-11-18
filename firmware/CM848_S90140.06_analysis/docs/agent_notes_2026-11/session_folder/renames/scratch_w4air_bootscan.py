import struct
import sys

ROM = sys.argv[1]
rom = open(ROM, 'rb').read()
addrs = [0x3fb37c, 0x3fb37e, 0x3fb380, 0x3fb382, 0x3fb384, 0x3fb386, 0x3fb388,
         0x3fd7dc, 0x3fd7de, 0x3fd7e6, 0x3fd8cc, 0x3fd5c2]
lows = {a: (a & 0xffff) for a in addrs}
LS = {32: 'lwz', 33: 'lwzu', 34: 'lbz', 35: 'lbzu', 36: 'stw', 37: 'stwu', 38: 'stb', 39: 'stbu',
      40: 'lhz', 41: 'lhzu', 42: 'lha', 43: 'lhau', 44: 'sth', 45: 'sthu', 14: 'addi', 24: 'ori'}
res = {a: [] for a in addrs}
for off in range(0, 0x7f60, 4):
    w = struct.unpack('>I', rom[off:off + 4])[0]
    op = w >> 26
    if op in LS:
        lo = w & 0xffff
        for a in addrs:
            if lo == lows[a]:
                res[a].append((hex(off), LS[op]))
for a in addrs:
    print(hex(a), res[a] if res[a] else 'no boot-ROM instruction with that low halfword')
