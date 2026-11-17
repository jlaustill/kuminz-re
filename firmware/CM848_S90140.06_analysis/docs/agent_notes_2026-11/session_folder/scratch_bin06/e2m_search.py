import re
import struct
import sys

root = sys.argv[1]
path = root + '/firmware/CM848_S90140.06_analysis/docs/S90140.12.e2m'

mem = {}
pat = re.compile(r'^0x([0-9A-Fa-f]{8}) \| ([0-9A-Fa-f]+)')
with open(path, 'rb') as f:
    for raw in f:
        line = raw.decode('latin-1')
        m = pat.match(line)
        if not m:
            continue
        addr = int(m.group(1), 16)
        data = bytes.fromhex(m.group(2))
        mem[addr] = data

addrs = sorted(mem)
print('records', len(addrs), 'first', hex(addrs[0]), 'last', hex(addrs[-1]))

# Build contiguous segments
segs = []
cur_start = None
cur = bytearray()
prev_end = None
for a in addrs:
    d = mem[a]
    if prev_end is not None and a == prev_end:
        cur.extend(d)
    else:
        if cur_start is not None:
            segs.append((cur_start, bytes(cur)))
        cur_start = a
        cur = bytearray(d)
    prev_end = a + len(d)
if cur_start is not None:
    segs.append((cur_start, bytes(cur)))
print('segments', [(hex(s), hex(len(b))) for s, b in segs])


def find(patbytes):
    res = []
    for s, b in segs:
        i = 0
        while True:
            j = b.find(patbytes, i)
            if j < 0:
                break
            res.append(s + j)
            i = j + 1
    return res


p1 = struct.pack('>6H', 1025, 1230, 1434, 1639, 1844, 2049)
print('L171 axis pattern', [hex(x) for x in find(p1)])
p2 = struct.pack('>4H', 1391, 1207, 1131, 1056)
print('L176 values pattern', [hex(x) for x in find(p2)])
p3 = struct.pack('>4H', 557, 557, 557, 595)
print('L175 grid first row', [hex(x) for x in find(p3)])
