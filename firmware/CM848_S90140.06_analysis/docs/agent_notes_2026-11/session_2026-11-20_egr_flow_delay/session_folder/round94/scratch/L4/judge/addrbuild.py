# Judge: find every place where code builds one of the given values in a register (lis + addi / addic / ori,
# tracked with disasm_func.step_address_registers over each function window). Finds function pointers or data
# addresses built in registers (e.g. a pointer to an uncalled routine, or a struct base).
# usage: addrbuild.py 0xVALUE [...]
import sys, json, re, bisect
sys.path.insert(0, '/home/linux/code/kuminz-re/.claude/worktrees/cm848-egr-flow-delay/firmware/scripts')
import disasm_func as D

CACHE = '/home/linux/.claude/jobs/374b0424/tmp/w15/r94/scratch/L4/judge/objdump_cache.json'
CPP = '/home/linux/.claude/jobs/374b0424/tmp/w15/r94/frozen/cm848/cm848_rom.ghidra.cpp'
funcs = []
for line in open(CPP, errors='replace'):
    m = re.match(r'^// Function: (\S+) @ 0x([0-9a-fA-F]+)', line)
    if m:
        funcs.append((int(m.group(2), 16), m.group(1)))
funcs = sorted(set(funcs))
keys = [f[0] for f in funcs]


def owner(a):
    i = bisect.bisect_right(keys, a) - 1
    return funcs[i] if i >= 0 else (0, '?')


targets = {int(t, 16) for t in sys.argv[1:]}
images = json.load(open(CACHE))
for name, parsed in images.items():
    regs = {0: 0}
    cur = None
    for a, ln in parsed:
        f = owner(a)
        if f != cur:
            regs = {0: 0}
            cur = f
        m = D.ASM_LINE.match(ln)
        if not m:
            continue
        mnem, ops = m.group(2), m.group(3).replace(' ', '')
        op = ops.split(',')
        if mnem in D.WIDTH:
            continue
        before = dict(regs)
        try:
            D.step_address_registers(regs, mnem, op)
        except (ValueError, IndexError):
            regs.pop(int(op[0][1:]), None) if op and re.fullmatch(r'r\d+', op[0]) else None
            continue
        if op and re.fullmatch(r'r\d+', op[0]):
            v = regs.get(int(op[0][1:]))
            if v in targets and mnem != 'lis':
                print('%s builds %s: %s  [%s @ %s]' % (name, hex(v), ln.strip(), f[1], hex(f[0])))
