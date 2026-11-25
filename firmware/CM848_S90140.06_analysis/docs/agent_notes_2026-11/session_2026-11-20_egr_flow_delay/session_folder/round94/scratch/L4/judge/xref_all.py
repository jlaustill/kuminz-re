# Judge: every load/store to the given CM848 data addresses, over ALL code of ROM + flash2.
# Disassembles each image once with objdump, splits it into function windows (from the frozen cpp's
# "// Function:" headers), and runs disasm_func.find_accesses (register tracking: lis / addi / ori / li / mr,
# displacement, struct-member and indexed forms) on each window.
# usage: xref_all.py 0xADDR [0xADDR ...]
import os, re, subprocess, sys, bisect, json
sys.path.insert(0, '/home/linux/code/kuminz-re/.claude/worktrees/cm848-egr-flow-delay/firmware/scripts')
import disasm_func as D

CPP = '/home/linux/.claude/jobs/374b0424/tmp/w15/r94/frozen/cm848/cm848_rom.ghidra.cpp'
CACHE = '/home/linux/.claude/jobs/374b0424/tmp/w15/r94/scratch/L4/judge/objdump_cache.json'
ORIG = '/home/linux/code/kuminz-re/.claude/worktrees/cm848-egr-flow-delay/firmware/CM848_S90140.06_analysis/originals/'

funcs = []
for line in open(CPP, errors='replace'):
    m = re.match(r'^// Function: (\S+) @ 0x([0-9a-fA-F]+)', line)
    if m:
        funcs.append((int(m.group(2), 16), m.group(1)))
funcs = sorted(set(funcs))
keys = [f[0] for f in funcs]


def load_lines():
    if os.path.exists(CACHE):
        return {k: [tuple(x) for x in v] for k, v in json.load(open(CACHE)).items()}
    out = {}
    for name, vma in (('cm848_rom.bin', 0), ('cm848_flash2_live.bin', 0x500000)):
        cmd = ['powerpc-linux-gnu-objdump', '-D', '-b', 'binary', '-m', 'powerpc', '-EB',
               '--adjust-vma=%s' % hex(vma), ORIG + name]
        txt = subprocess.run(cmd, capture_output=True, text=True).stdout.splitlines()
        parsed = []
        for ln in txt:
            m = re.match(r'^\s*([0-9a-f]+):\t', ln)
            if m:
                parsed.append((int(m.group(1), 16), ln))
        out[name] = parsed
    json.dump(out, open(CACHE, "w"))
    return out


def owner(a):
    i = bisect.bisect_right(keys, a) - 1
    return funcs[i] if i >= 0 else (0, '?')


def main():
    targets = [int(t, 16) for t in sys.argv[1:]]
    images = load_lines()
    # group lines per function window
    windows = {}
    for name, parsed in images.items():
        for a, ln in parsed:
            f = owner(a)
            # only code windows: skip addresses before the first function in that image region
            windows.setdefault(f, []).append(ln)
    for t in targets:
        print('== %s' % hex(t))
        for f in sorted(windows):
            hits, offs = D.find_accesses(windows[f], t)
            for kind, ln, w in hits:
                print('  %-5s %-5s %s  [%s @ %s]' % (kind, w, ln, f[1], hex(f[0])))


main()
