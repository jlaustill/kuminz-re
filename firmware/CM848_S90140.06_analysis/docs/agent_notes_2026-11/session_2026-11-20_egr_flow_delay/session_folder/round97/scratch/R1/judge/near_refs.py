import sys, struct
rom = open('/home/linux/code/kuminz-re/.claude/worktrees/cm848-egr-flow-delay/firmware/CM550_J90350.00_analysis/firmware/J90350.00.rom.bin', 'rb').read()
lo = int(sys.argv[1], 16)
hi = int(sys.argv[2], 16)
for p in range(0, len(rom) - 4, 2):
    v = struct.unpack('>I', rom[p:p + 4])[0]
    if lo <= v <= hi:
        prev = struct.unpack('>H', rom[p - 2:p])[0] if p >= 2 else 0
        print('0x%x: 0x%x prev op %04x' % (p, v, prev))
