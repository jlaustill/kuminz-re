import sys

ram = open('/home/linux/code/kuminz-re/.claude/worktrees/cm848-fueling-state-enum/firmware/CM848_S90140.06_analysis/originals/cm848_ram.bin', 'rb').read()


def rd(a, n, signed=False):
    off = a - 0x3FA000
    return int.from_bytes(ram[off:off + n], 'big', signed=signed)


for spec in sys.argv[1:]:
    a, n = spec.split(':')
    a = int(a, 16)
    n = int(n)
    print(hex(a), n, rd(a, n), rd(a, n, True))
