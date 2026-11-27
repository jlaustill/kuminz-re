import sys
B = '/home/linux/code/kuminz-re/.claude/worktrees/cm848-egr-flow-delay/firmware/CM550_J90350.00_analysis/firmware/'
ram = open(B + 'J90350.00.ram.bin', 'rb').read()
ext = open(B + 'J90350.00.extended_ram.bin', 'rb').read()
def rd(a, n):
    if 0x800000 <= a < 0x8091c2:
        return ram[a - 0x800000:a - 0x800000 + n], 'ram'
    if a >= 0x8092c2:
        return ext[a - 0x809242:a - 0x809242 + n], 'ext'
    if 0x8091c2 <= a < 0x8092c2:
        return ext[a - 0x809242:a - 0x809242 + n], 'ext(uncertain)'
    return b'', '?'
for arg in sys.argv[1:]:
    a, n = arg.split(':') if ':' in arg else (arg, '2')
    a = int(a, 16); n = int(n)
    b, src = rd(a, n)
    print('%06x [%s] %s' % (a, src, b.hex()))
