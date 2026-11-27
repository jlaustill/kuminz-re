"""Find every big-endian 32-bit occurrence of addresses in [lo, hi] in the CM550 ROM,
and report the instruction that contains it (capstone, decoding from known function starts
is not possible here, so we decode backwards: try start offsets 2..10 bytes before the hit
and keep the decode whose instruction covers the hit and ends on an instruction boundary)."""
import sys, struct
from capstone import Cs, CS_ARCH_M68K, CS_MODE_M68K_040, CS_MODE_BIG_ENDIAN
ROM = '/home/linux/code/kuminz-re/.claude/worktrees/cm848-egr-flow-delay/firmware/CM550_J90350.00_analysis/firmware/J90350.00.rom.bin'
d = open(ROM, 'rb').read()
lo = int(sys.argv[1], 16)
hi = int(sys.argv[2], 16)
md = Cs(CS_ARCH_M68K, CS_MODE_M68K_040 + CS_MODE_BIG_ENDIAN)
for off in range(0, len(d) - 3, 2):
    v = struct.unpack('>I', d[off:off+4])[0]
    if lo <= v <= hi:
        best = None
        for back in (2, 4, 6, 8):
            s = off - back
            if s < 0:
                continue
            ins = next(md.disasm(d[s:s+16], s), None)
            if ins and ins.address + ins.size > off + 3 and ins.address < off:
                best = ins
                break
        if best:
            print("%06x  value 0x%06x  in  %06x: %s %s" % (off, v, best.address, best.mnemonic, best.op_str))
        else:
            print("%06x  value 0x%06x  (no instruction decode; data?)" % (off, v))
