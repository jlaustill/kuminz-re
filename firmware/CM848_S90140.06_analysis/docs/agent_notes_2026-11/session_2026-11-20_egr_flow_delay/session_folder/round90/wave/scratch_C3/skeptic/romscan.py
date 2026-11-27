import sys, struct
rom = open('/home/linux/code/kuminz-re/.claude/worktrees/cm848-egr-flow-delay/firmware/CM550_J90350.00_analysis/firmware/J90350.00.rom.bin', 'rb').read()
# scan for 32-bit absolute address occurrences within +-range
for arg in sys.argv[1:]:
    if ':' in arg:
        lo, hi = arg.split(':')
        lo = int(lo, 16); hi = int(hi, 16)
    else:
        lo = hi = int(arg, 16)
    print('#### %06x-%06x' % (lo, hi))
    for off in range(0, len(rom) - 3, 2):
        v = struct.unpack('>I', rom[off:off+4])[0]
        if lo <= v <= hi:
            ctx = ' '.join('%04x' % struct.unpack('>H', rom[o:o+2])[0] for o in range(max(0, off-6), min(len(rom), off+8), 2))
            print('  @%05x val=%06x  ctx(from %05x): %s' % (off, v, max(0, off-6), ctx))
