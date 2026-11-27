"""Sweep every decompiled function with m68k.py's decoder; report each instruction that names a
target address (abs operand or #immediate), plus accesses through an address register last loaded
with a target (movea.l #t / lea t) in the same function. Also reports targets reached by
(d16,An) from a loaded base within +-0x40.
usage: python3 scan_all.py <target_hex> ..."""
import re, sys
sys.path.insert(0, '/home/linux/.claude/jobs/374b0424/tmp/w15/r90/wave/scratch_C3')
import m68k

funcs = []
for line in open('/home/linux/.claude/jobs/374b0424/tmp/w15/r90/wave/scratch_C3/funcs.txt'):
    a, name = line.split()
    funcs.append((int(a, 16), name))
funcs.sort()
targets = [int(t, 16) for t in sys.argv[1:]]
tset = set(targets)
hits = {t: [] for t in targets}
for i, (fa, fname) in enumerate(funcs):
    end = funcs[i + 1][0] if i + 1 < len(funcs) else fa + 0x400
    if end - fa > 0x4000:
        end = fa + 0x4000
    out = m68k.sweep(fa, end)
    areg = {}
    for (p, n, t, a, im) in out:
        for x in a:
            if x in tset:
                hits[x].append((fname, fa, p, t))
        for x in im:
            if x in tset:
                hits[x].append((fname, fa, p, t + '   [immediate]'))
        mm = re.match(r'(movea\.l #\$([0-9a-f]+)|lea \$([0-9a-f]+)),a(\d)', t)
        if mm:
            areg[int(mm.group(4))] = int(mm.group(2) or mm.group(3), 16)
            continue
        mm2 = re.search(r',a(\d)$', t)
        if mm2 and re.match(r'(movea|lea|adda|suba)', t):
            areg.pop(int(mm2.group(1)), None)
        if t.startswith('movem') and '(a7)+' in t:
            pass
        for reg, val in list(areg.items()):
            # (An), (An)+, -(An)
            if re.search(r'\(a%d\)' % reg, t) or re.search(r'-\(a%d\)' % reg, t):
                if val in tset:
                    hits[val].append((fname, fa, p, t + '   ; a%d=$%x' % (reg, val)))
            for md in re.finditer(r'\((-?\d+),a%d\)' % reg, t):
                eff = val + int(md.group(1))
                if eff in tset:
                    hits[eff].append((fname, fa, p, t + '   ; a%d=$%x -> $%x' % (reg, val, eff)))
for t in targets:
    print('=== 0x%06x' % t)
    for fname, fa, p, txt in hits[t]:
        print('  %-48s %05x: %s' % ('%s@%x' % (fname, fa), p, txt))
