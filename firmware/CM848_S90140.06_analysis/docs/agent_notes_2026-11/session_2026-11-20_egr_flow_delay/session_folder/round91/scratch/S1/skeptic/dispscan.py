"""Linear sweep of every function (from funcs.txt starts to the next start) tracking address registers loaded with
an absolute RAM base (movea.l #imm,An / lea abs.l,An / movea.l An,Am copies), and reporting every memory operand
whose base + displacement lands in [lo, hi]. Also reports abs.l operands in range. A crude data-flow: a register is
forgotten at any other write to it, at a branch target is not tracked (conservative: we keep state across)."""
import sys, capstone
from capstone import m68k as M
ROM = '/home/linux/code/kuminz-re/.claude/worktrees/cm848-egr-flow-delay/firmware/CM550_J90350.00_analysis/firmware/J90350.00.rom.bin'
FUNCS = '/home/linux/.claude/jobs/374b0424/tmp/w15/r91/scratch/S1/skeptic/funcs.txt'
d = open(ROM, 'rb').read()
lo = int(sys.argv[1], 16)
hi = int(sys.argv[2], 16)
starts = sorted(int(l.split()[0], 16) for l in open(FUNCS))
md = capstone.Cs(capstone.CS_ARCH_M68K, capstone.CS_MODE_BIG_ENDIAN | capstone.CS_MODE_M68K_020)
md.detail = True
A0 = M.M68K_REG_A0
hits = []
for idx, s in enumerate(starts):
    e = starts[idx + 1] if idx + 1 < len(starts) else min(s + 0x2000, len(d))
    areg = {}
    pc = s
    while pc < e:
        progressed = False
        for ins in md.disasm(d[pc:e], pc):
            progressed = True
            pc = ins.address + ins.size
            try:
                ops = ins.operands
            except Exception:
                continue
            text = ins.mnemonic + ' ' + ins.op_str
            # check memory operands
            for o in ops:
                if o.type == M.M68K_OP_MEM:
                    am = o.address_mode
                    base = o.mem.base_reg
                    disp = o.mem.disp
                    if am in (M.M68K_AM_REGI_ADDR_DISP, M.M68K_AM_AREGI_INDEX_8_BIT_DISP, M.M68K_AM_REGI_ADDR, M.M68K_AM_REGI_ADDR_POST_INC, M.M68K_AM_REGI_ADDR_PRE_DEC, M.M68K_AM_AREGI_INDEX_BASE_DISP):
                        if base in areg:
                            ea = areg[base] + disp
                            if lo <= ea <= hi and disp != 0:
                                hits.append((ins.address, text, hex(areg[base]), disp))
                    if am in (M.M68K_AM_ABSOLUTE_DATA_LONG,):
                        if lo <= o.imm <= hi:
                            pass
            # track writes to address registers
            if len(ops) == 2 and ops[1].type == M.M68K_OP_REG and M.M68K_REG_A0 <= ops[1].reg <= M.M68K_REG_A7:
                dst = ops[1].reg
                src = ops[0]
                if ins.mnemonic.startswith('movea') and src.type == M.M68K_OP_IMM:
                    areg[dst] = src.imm & 0xffffffff
                elif ins.mnemonic.startswith('lea') and src.type == M.M68K_OP_MEM and src.address_mode == M.M68K_AM_ABSOLUTE_DATA_LONG:
                    areg[dst] = src.imm & 0xffffffff
                elif ins.mnemonic.startswith('movea') and src.type == M.M68K_OP_REG and src.reg in areg:
                    areg[dst] = areg[src.reg]
                elif ins.mnemonic.startswith('adda') or ins.mnemonic.startswith('suba') or ins.mnemonic.startswith('addq') or ins.mnemonic.startswith('subq') or ins.mnemonic.startswith('lea'):
                    areg.pop(dst, None)
                else:
                    areg.pop(dst, None)
            if ins.mnemonic in ('rts', 'rte') or ins.mnemonic.startswith('jsr') or ins.mnemonic.startswith('bsr'):
                if ins.mnemonic.startswith('jsr') or ins.mnemonic.startswith('bsr'):
                    # a0/a1 are scratch across calls
                    areg.pop(M.M68K_REG_A0, None)
                    areg.pop(M.M68K_REG_A1, None)
        if not progressed or pc < e:
            pc += 2
for h in hits:
    print('0x%06x %-40s base=%s disp=%d' % h)
print(len(hits), 'displacement hits')
