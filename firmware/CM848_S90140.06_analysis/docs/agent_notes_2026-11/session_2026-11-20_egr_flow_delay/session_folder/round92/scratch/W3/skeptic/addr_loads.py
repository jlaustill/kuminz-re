"""Census of 4-byte immediates / absolute operands in an address range, grouped by the containing instruction's
mnemonic, to find base-pointer loads (movea / lea / pea / move.l #imm) that could reach a word by displacement.
usage: addr_loads.py <first hex> <last hex> [--all]   (default: print only non 'move.w/move.b abs' data accesses)"""
import collections
import sys

sys.path.insert(0, '/home/linux/.claude/jobs/374b0424/tmp/w15/r91/scratch/S1/skeptic/venv/lib/python3.12/site-packages')
import capstone  # noqa: E402

ROM = '/home/linux/code/kuminz-re/.claude/worktrees/cm848-egr-flow-delay/firmware/CM550_J90350.00_analysis/firmware/J90350.00.rom.bin'
rom = open(ROM, 'rb').read()
md = capstone.Cs(capstone.CS_ARCH_M68K, capstone.CS_MODE_M68K_020 | capstone.CS_MODE_BIG_ENDIAN)
first, last = int(sys.argv[1], 16), int(sys.argv[2], 16)
show_all = '--all' in sys.argv
kinds = collections.Counter()
for h in range(0, len(rom) - 3, 2):
    v = int.from_bytes(rom[h:h + 4], 'big')
    if not first <= v <= last:
        continue
    best = None
    for back in (2, 4, 6, 8):
        s = h - back
        for i in md.disasm(rom[s:s + 16], s, 1):
            if i.address + len(i.bytes) >= h + 4 and best is None:
                best = i
    if best is None:
        kinds['DATA'] += 1
        print('0x%06x at 0x%05x: DATA? prev=%s' % (v, h, rom[h - 4:h].hex()))
        continue
    imm = '#$%x' % v in best.op_str
    kinds[(best.mnemonic, 'imm' if imm else 'abs')] += 1
    if show_all or imm or best.mnemonic in ('lea', 'pea', 'movea.l'):
        print('0x%06x at 0x%05x: %06x %s %s' % (v, h, best.address, best.mnemonic, best.op_str))
print(sorted(kinds.items(), key=lambda kv: -kv[1]))
