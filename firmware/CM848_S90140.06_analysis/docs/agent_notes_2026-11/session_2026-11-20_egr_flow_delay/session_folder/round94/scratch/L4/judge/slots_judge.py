# Judge: decode the 40-entry jump table of executiveFrameInterruptHandler (0xc0a0) straight from the ROM bytes
# and list the bl targets of each case in order, until the case's closing unconditional branch.
import struct, re
ROM = '/home/linux/code/kuminz-re/.claude/worktrees/cm848-egr-flow-delay/firmware/CM848_S90140.06_analysis/originals/cm848_rom.bin'
CPP = '/home/linux/.claude/jobs/374b0424/tmp/w15/r94/frozen/cm848/cm848_rom.ghidra.cpp'
rom = open(ROM, 'rb').read()
names = {}
for line in open(CPP, errors='replace'):
    m = re.match(r'// Function: (\S+) @ 0x([0-9a-fA-F]+)', line)
    if m:
        names[int(m.group(2), 16)] = m.group(1)


def word(a):
    return struct.unpack('>I', rom[a:a + 4])[0]


def branch(a):
    w = word(a)
    if (w >> 26) != 18:
        return None
    li = w & 0x03fffffc
    if li & 0x02000000:
        li -= 0x04000000
    dest = li if (w & 2) else (a + li)
    return dest, bool(w & 1)


table = []
for i in range(40):
    a = 0xc198 + 4 * i
    d, lk = branch(a)
    assert not lk
    table.append(d)
targets = {0xbb68, 0xbce8, 0xbeb4, 0xc050}
for case, start in enumerate(table):
    a = start
    calls = []
    for _ in range(200):
        b = branch(a)
        if b is not None:
            d, lk = b
            if lk:
                calls.append(d)
            else:
                break
        a += 4
    marks = ['call%d=%s' % (i + 1, names.get(c, hex(c))) for i, c in enumerate(calls) if c in targets]
    print('frame %2d start %s: %s %s' % (case, hex(start), ' '.join(hex(c) for c in calls), marks))
