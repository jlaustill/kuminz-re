"""Scan CM848 ROM (base 0) and flash2 (base 0x500000) for references to a RAM address:
 - any 32-bit big-endian word equal to the address (pointer tables)
 - D-form instructions whose 16-bit displacement equals the address's low half (signed) and whose
   high-adjusted half is reached by lis 0x41/0x40 (we report every D-form hit with that displacement;
   the caller filters by context)
 - addi/addic forms with that displacement (address building)
Usage: ppc_refs.py 0x40aaba [extra addresses...]"""
import sys, struct
FW = '/home/linux/code/kuminz-re/.claude/worktrees/cm848-egr-flow-delay/firmware/CM848_S90140.06_analysis/originals/'
images = [(FW + 'cm848_rom.bin', 0x0), (FW + 'cm848_flash2_live.bin', 0x500000)]
DFORM = {32: 'lwz', 33: 'lwzu', 34: 'lbz', 35: 'lbzu', 36: 'stw', 37: 'stwu', 38: 'stb', 39: 'stbu',
         40: 'lhz', 41: 'lhzu', 42: 'lha', 43: 'lhau', 44: 'sth', 45: 'sthu', 14: 'addi', 12: 'addic',
         13: 'addic.', 24: 'ori', 46: 'lmw', 47: 'stmw', 48: 'lfs', 50: 'lfd'}
for target in [int(a, 16) for a in sys.argv[1:]]:
    lo = target & 0xffff
    print("== target 0x%06x (low half 0x%04x = %d)" % (target, lo, lo - 0x10000 if lo >= 0x8000 else lo))
    for path, base in images:
        d = open(path, 'rb').read()
        for off in range(0, len(d) - 3, 2):
            w = struct.unpack('>I', d[off:off + 4])[0]
            if w == target:
                print("  pointer word at 0x%06x" % (base + off))
        for off in range(0, len(d) - 3, 4):
            w = struct.unpack('>I', d[off:off + 4])[0]
            op = w >> 26
            if op in DFORM and (w & 0xffff) == lo:
                rt = (w >> 21) & 31
                ra = (w >> 16) & 31
                print("  %s r%d,%d(r%d) at 0x%06x" % (DFORM[op], rt, (lo - 0x10000 if lo >= 0x8000 else lo), ra, base + off))
