import re
import struct
import sys

root = sys.argv[1]
path = root + '/firmware/CM848_S90140.06_analysis/docs/S90140.12.e2m'
rom_path = root + '/firmware/CM848_S90140.06_analysis/originals/cm848_rom.bin'

mem = {}
pat = re.compile(r'^0x([0-9A-Fa-f]{8}) \| ([0-9A-Fa-f]+)')
with open(path, 'rb') as f:
    for raw in f:
        line = raw.decode('latin-1')
        m = pat.match(line)
        if not m:
            continue
        mem[int(m.group(1), 16)] = bytes.fromhex(m.group(2))

segs = []
cur_start = None
cur = bytearray()
prev_end = None
for a in sorted(mem):
    d = mem[a]
    if prev_end is not None and a == prev_end:
        cur.extend(d)
    else:
        if cur_start is not None:
            segs.append((cur_start, bytes(cur)))
        cur_start = a
        cur = bytearray(d)
    prev_end = a + len(d)
segs.append((cur_start, bytes(cur)))

rom = open(rom_path, 'rb').read()


def find_in(img, base, patbytes):
    res = []
    i = 0
    while True:
        j = img.find(patbytes, i)
        if j < 0:
            break
        res.append(base + j)
        i = j + 1
    return res


tests = {
    'demand axis 41..2049': struct.pack('>5H', 41, 205, 410, 820, 2049),
    'pressure axis 50..100MPa': struct.pack('>6H', 1025, 1230, 1434, 1639, 1844, 2049),
    'rpm axis 800/4800/9600': struct.pack('>4H', 800, 4800, 9600, 13600),
}
for name, p in tests.items():
    print(name)
    print('   .06 rom', [hex(x) for x in find_in(rom, 0, p)])
    for s, b in segs:
        r = find_in(b, s, p)
        if r:
            print('   .12 seg', hex(s), [hex(x) for x in r])
