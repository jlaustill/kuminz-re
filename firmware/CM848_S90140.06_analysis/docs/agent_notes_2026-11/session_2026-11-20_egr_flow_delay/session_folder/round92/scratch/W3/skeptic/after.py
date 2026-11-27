"""For each absolute reference to an address, disassemble the referencing instruction and the next N instructions
(capstone), and name the containing function from the .cpp '// Function:' headers.
usage: after.py <address hex> [N=3]"""
import bisect
import re
import sys

sys.path.insert(0, '/home/linux/.claude/jobs/374b0424/tmp/w15/r91/scratch/S1/skeptic/venv/lib/python3.12/site-packages')
import capstone  # noqa: E402

BASE = '/home/linux/code/kuminz-re/.claude/worktrees/cm848-egr-flow-delay/firmware/CM550_J90350.00_analysis'
rom = open(BASE + '/firmware/J90350.00.rom.bin', 'rb').read()
md = capstone.Cs(capstone.CS_ARCH_M68K, capstone.CS_MODE_M68K_020 | capstone.CS_MODE_BIG_ENDIAN)
funcs = []
for line in open(BASE + '/output/J90350.00.ghidra.cpp', errors='replace'):
    m = re.match(r'// Function: (\S+) @ 0x([0-9a-fA-F]+)', line)
    if m:
        funcs.append((int(m.group(2), 16), m.group(1)))
funcs.sort()
starts = [f[0] for f in funcs]


def func_of(a):
    i = bisect.bisect_right(starts, a) - 1
    return funcs[i][1] if i >= 0 else '?'


addr = int(sys.argv[1], 16)
n = int(sys.argv[2]) if len(sys.argv) > 2 else 3
pat = addr.to_bytes(4, 'big')
pos = 0
while True:
    h = rom.find(pat, pos)
    if h < 0:
        break
    pos = h + 1
    if h % 2:
        continue
    s = h - 2
    out = []
    a = s
    for _ in range(n + 1):
        got = False
        for i in md.disasm(rom[a:a + 16], a, 1):
            out.append('%06x %s %s' % (i.address, i.mnemonic, i.op_str))
            a += len(i.bytes)
            got = True
        if not got:
            out.append('%06x .word %04x' % (a, int.from_bytes(rom[a:a + 2], 'big')))
            a += 2
    print('[%s] %s' % (func_of(s), ' ; '.join(out)))
