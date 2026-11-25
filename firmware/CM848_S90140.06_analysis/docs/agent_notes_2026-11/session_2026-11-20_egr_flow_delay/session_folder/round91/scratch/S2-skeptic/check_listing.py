import re, sys
rom = open(sys.argv[1], 'rb').read()
bad = 0
n = 0
for line in open(sys.argv[2]):
    m = re.match(r'^([0-9a-f]{8})\s+([0-9a-f]+)\s+(.*)$', line.rstrip('\n'))
    if not m:
        continue
    addr = int(m.group(1), 16)
    hexbytes = m.group(2)
    b = bytes.fromhex(hexbytes)
    n += 1
    if rom[addr:addr + len(b)] != b:
        bad += 1
        print('MISMATCH', hex(addr), hexbytes, rom[addr:addr + len(b)].hex())
print('checked', n, 'lines, mismatches', bad)
