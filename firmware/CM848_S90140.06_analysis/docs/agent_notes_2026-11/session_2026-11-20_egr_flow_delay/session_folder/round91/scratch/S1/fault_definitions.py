"""Read the fault data records (e2m DG0000FU.., 6 bytes at 0x8067c4) and the countdown times (0x80654c)."""
ROOT = '/home/linux/code/kuminz-re/.claude/worktrees/cm848-egr-flow-delay/firmware/CM550_J90350.00_analysis/firmware/'
ram = open(ROOT + 'J90350.00.ram.bin', 'rb').read()


def at(address, length):
    return ram[address - 0x800000:address - 0x800000 + length]


for mode in range(4):
    start = int.from_bytes(at(0x80654c + 8 * mode, 4), 'big')
    step = int.from_bytes(at(0x806550 + 8 * mode, 4), 'big')
    print('mode %d: elapsed time before countdown %d counts (%.2f h), countdown step %d counts (%.2f h)' % (
        mode, start, start / 18000.0, step, step / 18000.0))
modes = {}
table = ROOT + 'J90350.00.ram.bin'
for index in range(125):
    record = at(0x8067c4 + 6 * index, 6)
    code = int.from_bytes(record[0:2], 'big')
    flags = int.from_bytes(record[2:4], 'big')
    modes.setdefault(record[5], []).append(index)
    count_record = at(0x805a1c + 10 * index, 10)
    if any(count_record):
        print('index %3d fault code %4d flags 0x%04x spn byte %3d mode %d | count record status %d count %d' % (
            index, code, flags, record[4], record[5], count_record[8], count_record[9]))
for mode, indexes in sorted(modes.items()):
    print('mode', mode, ':', len(indexes), 'faults')
