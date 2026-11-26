import sys
import struct

rom = open(sys.argv[1], 'rb').read()
targets = [int(t, 16) for t in sys.argv[2:]]
for t in targets:
    hits = []
    pat = struct.pack('>I', t)
    i = rom.find(pat)
    while i != -1:
        ctx = rom[i - 2:i].hex() if i >= 2 else ''
        hits.append(('abs32', hex(i), 'prefix', ctx))
        i = rom.find(pat, i + 1)
    for a in range(0, len(rom) - 5, 2):
        op = rom[a:a + 2]
        if op in (b'\x61\x00', b'\x60\x00', b'\x4e\xba'):
            d = struct.unpack('>h', rom[a + 2:a + 4])[0]
            if a + 2 + d == t:
                hits.append(('pcrel16', hex(a), op.hex()))
        elif op == b'\x61\xff':
            d = struct.unpack('>i', rom[a + 2:a + 6])[0]
            if a + 2 + d == t:
                hits.append(('bsr.l', hex(a)))
        elif rom[a] == 0x61:
            d = struct.unpack('>b', rom[a + 1:a + 2])[0]
            if a + 2 + d == t:
                hits.append(('bsr.b', hex(a)))
    print(hex(t), hits)
