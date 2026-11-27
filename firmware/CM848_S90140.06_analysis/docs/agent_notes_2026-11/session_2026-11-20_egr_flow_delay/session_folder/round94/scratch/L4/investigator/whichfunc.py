# Map instruction addresses to the containing function (by the "// Function: name @ addr" headers in the frozen cpp).
import sys, re, bisect
cpp = '/home/linux/.claude/jobs/374b0424/tmp/w15/r94/frozen/cm848/cm848_rom.ghidra.cpp'
starts = []
for line in open(cpp, errors='replace'):
    m = re.match(r'// Function: (\S+) @ 0x([0-9a-fA-F]+)', line)
    if m:
        starts.append((int(m.group(2), 16), m.group(1)))
starts.sort()
keys = [s[0] for s in starts]
for a in sys.argv[1:]:
    t = int(a, 16)
    i = bisect.bisect_right(keys, t) - 1
    print(hex(t), '->', starts[i][1], hex(starts[i][0]) if i >= 0 else '')
