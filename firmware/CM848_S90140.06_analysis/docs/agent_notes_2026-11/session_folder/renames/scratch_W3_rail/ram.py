import struct, sys
D = '/home/linux/code/kuminz-re/.claude/worktrees/cm848-typing-arrays/firmware/CM848_S90140.06_analysis/originals/'
RAM = open(D + 'cm848_ram.bin', 'rb').read()
ROM = open(D + 'cm848_rom.bin', 'rb').read()
EE = open(D + 'cm848_eeprom.bin', 'rb').read()
def rd(buf, off, w):
    if w == 'b': return buf[off], struct.unpack('>b', buf[off:off+1])[0]
    if w == 'h': return struct.unpack('>H', buf[off:off+2])[0], struct.unpack('>h', buf[off:off+2])[0]
    if w == 'w': return struct.unpack('>I', buf[off:off+4])[0], struct.unpack('>i', buf[off:off+4])[0]
# usage: ram.py r:0x409ee2:h  (r = ram, o = rom, e = eeprom)   n = array count optional :h:5
for a in sys.argv[1:]:
    p = a.split(':')
    kind, addr, w = p[0], int(p[1], 16), p[2]
    cnt = int(p[3]) if len(p) > 3 else 1
    size = {'b': 1, 'h': 2, 'w': 4}[w]
    vals = []
    for i in range(cnt):
        ad = addr + i * size
        if kind == 'r': u, s = rd(RAM, ad - 0x3FA000, w)
        elif kind == 'o': u, s = rd(ROM, ad, w)
        else: u, s = rd(EE, ad, w)
        vals.append('%d/0x%x%s' % (u, u, '' if s == u else '(s%d)' % s))
    print('%s 0x%x %s: %s' % (kind, addr, w, ' '.join(vals)))
