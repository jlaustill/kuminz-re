"""Print the fault count table records from the CM550 RAM dump and the two flash parameter block copies."""
import sys
BASE = '/home/linux/code/kuminz-re/.claude/worktrees/cm848-egr-flow-delay/firmware/CM550_J90350.00_analysis/firmware/'
ram = open(BASE + 'J90350.00.ram.bin', 'rb').read()
rom = open(BASE + 'J90350.00.rom.bin', 'rb').read()
T = 0x805a1c


def show(name, buf, off):
    print('==', name)
    used = 0
    for i in range(126):
        r = buf[off + 10 * i: off + 10 * i + 10]
        if any(r) or i >= 124:
            used += 1
            t0 = int.from_bytes(r[0:4], 'big')
            t4 = int.from_bytes(r[4:8], 'big')
            print('  rec %3d @0x%06x: t0=%08x t4=%08x status=%02x count=%3d  raw=%s' % (i, T + 10 * i, t0, t4, r[8], r[9], r.hex()))
    print('  nonzero records:', used)


show('RAM', ram, T - 0x800000)
# flash copies: RAM 0x804f9a.. maps to flash 0x4a86 / 0x6a86 per proposal? check offset
for flash_base_ram in (0x4a86, 0x6a86):
    pass
if len(sys.argv) > 1:
    for a in sys.argv[1:]:
        off = int(a, 16)
        show('ROM copy at 0x%x' % off, rom, off)
