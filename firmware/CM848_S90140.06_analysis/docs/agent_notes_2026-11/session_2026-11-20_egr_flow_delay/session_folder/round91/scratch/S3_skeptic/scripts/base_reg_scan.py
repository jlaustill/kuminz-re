"""Linear-sweep the ROM. After each `movea.l #X,aN` / `lea X.l,aN`, follow the next instructions
until aN is written again (or an unconditional flow break, or a call for a0 / a1), and report every
memory operand through aN whose effective address (X + displacement) lands in a target range.
Indexed forms (d8,aN,Xn) are reported with their base + displacement and the index register.
Also reports every absolute-address operand / immediate that lands in a target range.
Usage: base_reg_scan.py ROM lo-hi [lo-hi ...]   (hex)"""
import sys, re, capstone
from capstone import m68k as M
rom = open(sys.argv[1], 'rb').read()
ranges = []
for spec in sys.argv[2:]:
    lo, hi = spec.split('-'); ranges.append((int(lo, 16), int(hi, 16)))
def hit(a):
    return any(lo <= a <= hi for lo, hi in ranges)
md = capstone.Cs(capstone.CS_ARCH_M68K, capstone.CS_MODE_BIG_ENDIAN | capstone.CS_MODE_M68K_040)
md.detail = True
insns = []
addr, end = 0, len(rom)
while addr < end:
    win_end = min(end, addr + 0x1000)
    last = addr
    for ins in md.disasm(rom[addr:win_end], addr):
        insns.append(ins); last = ins.address + ins.size
    if last == addr:
        addr += 2
    else:
        addr = last if last >= win_end - 10 else last + 2
AREG = {M.M68K_REG_A0 + i: 'a%d' % i for i in range(8)}
def text(i):
    return '%06x: %-8s %s' % (i.address, i.mnemonic, i.op_str)
def parse_disp(d):
    if d in ('', '-'):
        return 0
    neg = d.startswith('-'); d = d.lstrip('-').lstrip('$')
    return int(d, 16) * (-1 if neg else 1)
FLOW = ('rts', 'rte', 'jmp', 'unlk')
for idx, ins in enumerate(insns):
    # every 32-bit absolute / immediate in range
    for m in re.finditer(r'\$([0-9a-f]{5,8})', ins.op_str):
        v = int(m.group(1), 16)
        if hit(v):
            print('ABS  %06x | %s' % (v, text(ins)))
    if not (ins.mnemonic.startswith('movea.l') or ins.mnemonic.startswith('lea')):
        continue
    try:
        ops = ins.operands
    except capstone.CsError:
        continue
    if len(ops) != 2 or ops[1].type != M.M68K_OP_REG or ops[1].reg not in AREG:
        continue
    m = re.match(r'#?\$([0-9a-f]+)(\.l)?, a\d$', ins.op_str)
    if not m or (ins.mnemonic.startswith('movea') and not ins.op_str.startswith('#')):
        continue
    base = int(m.group(1), 16)
    reg = ops[1].reg; rname = AREG[reg]
    for j in range(idx + 1, min(idx + 200, len(insns))):
        nx = insns[j]; s = nx.op_str
        for mm in re.finditer(r'(-?\$?[0-9a-f]*)\(' + rname + r'\)', s):
            ea = (base + parse_disp(mm.group(1))) & 0xffffffff
            if hit(ea):
                print('BASE %06x | %s   [%s = %06x at %06x]' % (ea, text(nx), rname, base, ins.address))
        for mm in re.finditer(r'(-?\$?[0-9a-f]*)\(' + rname + r', ([ad][0-7]\.[wl][^)]*)\)', s):
            ea = (base + parse_disp(mm.group(1))) & 0xffffffff
            if any(lo - 0x100 <= ea <= hi for lo, hi in ranges):
                print('INDX %06x+%s | %s   [%s = %06x at %06x]' % (ea, mm.group(2), text(nx), rname, base, ins.address))
        try:
            nops = nx.operands
        except capstone.CsError:
            break
        if len(nops) >= 1:
            dst = nops[-1]
            if dst.type == M.M68K_OP_REG and dst.reg == reg:
                break
        if nx.mnemonic in FLOW:
            break
        if nx.mnemonic.startswith(('jsr', 'bsr')) and rname in ('a0', 'a1'):
            break
