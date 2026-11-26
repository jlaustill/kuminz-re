import sys
rom = open(sys.argv[1], 'rb').read()
for h in sys.argv[2:]:
    v = int(h, 16).to_bytes(4, 'big')
    hits = []
    i = rom.find(v)
    while i != -1:
        hits.append(hex(i))
        i = rom.find(v, i + 1)
    print(h, hits)
