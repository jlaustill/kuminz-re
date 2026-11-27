"""Scan a linear CM550 disassembly for base-register accesses that land in a target range.
Tracks movea.l #imm,aN / lea (imm).l,aN and reports (disp,aN) and (aN) uses whose imm+disp falls in [lo, hi].
Usage: base_scan.py <dis file> <lo hex> <hi hex>"""
import re
import sys

dis, lo, hi = sys.argv[1], int(sys.argv[2], 16), int(sys.argv[3], 16)
load = re.compile(r'(?:movea\.l #0x([0-9a-f]+),a([0-7]))|(?:lea \(0x([0-9a-f]+)\)\.l,a([0-7]))')
use = re.compile(r'\((-?0x[0-9a-f]+),a([0-7])\)')
plain = re.compile(r'(?<![0-9a-fx,])\(a([0-7])\)')
regs = {}
for line in open(dis):
    m = re.match(r'([0-9a-f]+): +[0-9a-f]+ +(.*)', line.strip())
    if not m:
        continue
    addr, ins = int(m.group(1), 16), m.group(2)
    if ins.startswith('rts') or ins.startswith('rte') or ins.startswith('unlk'):
        regs = {}
    for u in use.finditer(ins):
        d, r = int(u.group(1), 16), u.group(2)
        if r in regs and lo <= regs[r] + d <= hi:
            print(hex(addr), ins, '-> base', hex(regs[r]), 'ea', hex(regs[r] + d))
    for u in plain.finditer(ins):
        r = u.group(1)
        if r in regs and lo <= regs[r] <= hi:
            print(hex(addr), ins, '-> base', hex(regs[r]), 'ea', hex(regs[r]))
    lm = load.search(ins)
    if lm:
        if lm.group(1):
            regs[lm.group(2)] = int(lm.group(1), 16)
        else:
            regs[lm.group(4)] = int(lm.group(3), 16)
    else:
        w = re.search(r',a([0-7])$', ins)
        if w:
            regs.pop(w.group(1), None)
