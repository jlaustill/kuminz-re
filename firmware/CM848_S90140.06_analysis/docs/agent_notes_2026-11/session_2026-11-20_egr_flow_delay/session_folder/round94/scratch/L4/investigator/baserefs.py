# Find base-register accesses that land on a target address range: lis rA,hi ; addi rB,rA,lo (base value V)
# followed (within 40 instructions, same rB, until rB is overwritten) by a d-form access at V + d inside [lo_t, hi_t].
# Usage: baserefs.py 0x3fb500 0x3fb503
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
lo_t, hi_t = int(sys.argv[1], 16), int(sys.argv[2], 16)
DFORM = {32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 50, 52, 54}
def sx(v):
    return v - 0x10000 if v & 0x8000 else v
for nm, b, img in images:
    n = len(img) // 4
    words = struct.unpack('>%dI' % n, img[:n * 4])
    for i, w in enumerate(words):
        if (w >> 26) == 15 and ((w >> 16) & 31) == 0:  # lis rA,hi
            ra = (w >> 21) & 31
            hi = (w & 0xffff) << 16
            # following addi rB,rA,lo
            for j in range(i + 1, min(n, i + 8)):
                v = words[j]
                if (v >> 26) == 14 and ((v >> 16) & 31) == ra:
                    rb = (v >> 21) & 31
                    val = (hi + sx(v & 0xffff)) & 0xffffffff
                    if lo_t - 0x200 <= val <= hi_t:
                        for k in range(j + 1, min(n, j + 60)):
                            x = words[k]
                            op = x >> 26
                            if op in DFORM and ((x >> 16) & 31) == rb:
                                ea = (val + sx(x & 0xffff)) & 0xffffffff
                                if lo_t <= ea <= hi_t:
                                    print('%s at %s (%s): base %s op %d d %d -> %s' % (nm, hex(b + k * 4), func(b + k * 4), hex(val), op, sx(x & 0xffff), hex(ea)))
                            # stop when rb is overwritten by an integer op with rD=rb (rough)
                            if ((x >> 21) & 31) == rb and op in (14, 15, 32, 34, 40, 42) and k != j:
                                break
                    break
