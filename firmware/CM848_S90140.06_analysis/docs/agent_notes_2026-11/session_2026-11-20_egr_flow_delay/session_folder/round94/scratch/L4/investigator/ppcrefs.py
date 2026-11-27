# Find PowerPC d-form references (lis rB,hi ; op rD,lo(rB)) to absolute addresses in the CM848 ROM and flash2 images.
# Usage: ppcrefs.py 0x40aeea [...]
import sys, struct, re, bisect
base = '/home/linux/code/kuminz-re/.claude/worktrees/cm848-egr-flow-delay/firmware/CM848_S90140.06_analysis/originals/'
images = [('rom', 0, open(base + 'cm848_rom.bin', 'rb').read()),
          ('flash2', 0x500000, open(base + 'cm848_flash2_live.bin', 'rb').read())]
cpp = '/home/linux/.claude/jobs/374b0424/tmp/w15/r94/frozen/cm848/cm848_rom.ghidra.cpp'
starts = []
for line in open(cpp, errors='replace'):
    m = re.match(r'// Function: (\S+) @ 0x([0-9a-fA-F]+)', line)
    if m:
        starts.append((int(m.group(2), 16), m.group(1)))
starts.sort()
keys = [s[0] for s in starts]
def func(a):
    i = bisect.bisect_right(keys, a) - 1
    return starts[i][1] if i >= 0 else '?'
OPS = {32: 'lwz', 33: 'lwzu', 34: 'lbz', 35: 'lbzu', 36: 'stw', 37: 'stwu', 38: 'stb', 39: 'stbu', 40: 'lhz', 41: 'lhzu',
       42: 'lha', 43: 'lhau', 44: 'sth', 45: 'sthu', 14: 'addi', 48: 'lfs', 50: 'lfd', 52: 'stfs', 54: 'stfd', 46: 'lmw', 47: 'stmw'}
for a in sys.argv[1:]:
    t = int(a, 16)
    lo = t & 0xffff
    hi = (t >> 16) + (1 if lo & 0x8000 else 0)
    print('== %s (lis %d, d %d)' % (hex(t), hi, lo - 0x10000 if lo & 0x8000 else lo))
    for nm, b, img in images:
        n = len(img) // 4
        words = struct.unpack('>%dI' % n, img[:n * 4])
        for i, w in enumerate(words):
            op = w >> 26
            if op in OPS and (w & 0xffff) == lo:
                ra = (w >> 16) & 31
                # search back for lis ra,hi (addis ra,0,hi)
                ok = False
                for j in range(i - 1, max(-1, i - 24), -1):
                    v = words[j]
                    if (v >> 26) == 15 and ((v >> 21) & 31) == ra and ((v >> 16) & 31) == 0:
                        ok = ((v & 0xffff) == hi)
                        break
                if ok:
                    addr = b + i * 4
                    print('  %s %s r%d  at %s  (%s)' % (OPS[op], nm, (w >> 21) & 31, hex(addr), func(addr)))
