"""Find every big-endian 32-bit occurrence of each address (and +-1..3 neighbours) in the CM550 ROM,
and report the containing function from function_renames.csv."""
import csv, sys, bisect
ROM = '/home/linux/code/kuminz-re/.claude/worktrees/cm848-egr-flow-delay/firmware/CM550_J90350.00_analysis/firmware/J90350.00.rom.bin'
FR = '/home/linux/code/kuminz-re/.claude/worktrees/cm848-egr-flow-delay/firmware/CM550_J90350.00_analysis/output/function_renames.csv'
data = open(ROM, 'rb').read()
funcs = []
with open(FR, newline='') as f:
    r = csv.reader(f)
    hdr = next(r)
    for row in r:
        try:
            a = int(row[0], 16)
        except Exception:
            continue
        funcs.append((a, row[1] if len(row) > 1 else ''))
funcs.sort()
addrs = [a for a, _ in funcs]


def owner(off):
    i = bisect.bisect_right(addrs, off) - 1
    if i < 0:
        return '-'
    return '%s@0x%x' % (funcs[i][1], funcs[i][0])


for arg in sys.argv[1:]:
    target = int(arg, 16)
    print('=== 0x%08x' % target)
    for delta in range(-3, 4):
        t = target + delta
        pat = t.to_bytes(4, 'big')
        start = 0
        while True:
            i = data.find(pat, start)
            if i < 0:
                break
            print('  addr%+d (0x%08x) at ROM 0x%05x  [%s]  ctx: %s' % (delta, t, i, owner(i), data[max(0, i - 4):i + 6].hex()))
            start = i + 1
