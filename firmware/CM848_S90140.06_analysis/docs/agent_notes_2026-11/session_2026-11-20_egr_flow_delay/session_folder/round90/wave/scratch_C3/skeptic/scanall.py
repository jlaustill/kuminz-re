import sys, re
sys.path.insert(0, '/home/linux/.claude/jobs/374b0424/tmp/w15/r90/wave/scratch_C3/skeptic')
import dis68k
cpp = '/home/linux/code/kuminz-re/.claude/worktrees/cm848-egr-flow-delay/firmware/CM550_J90350.00_analysis/output/J90350.00.ghidra.cpp'
starts = []
names = {}
for l in open(cpp, encoding='utf-8', errors='replace'):
    m = re.match(r'// Function: (\S+) @ 0x([0-9a-fA-F]+)', l)
    if m:
        a = int(m.group(2), 16)
        starts.append(a); names[a] = m.group(1)
extra = [int(x, 16) for x in sys.argv[1].split(',')] if len(sys.argv) > 1 and sys.argv[1] else []
for a in extra:
    if a not in names:
        starts.append(a); names[a] = 'UNDEF_%x' % a
starts = sorted(set(starts))
targets = {}
for t in sys.argv[2:]:
    if ':' in t:
        lo, hi = [int(x, 16) for x in t.split(':')]
        for v in range(lo, hi + 1):
            targets[v] = t
    else:
        targets[int(t, 16)] = t
import io, contextlib
for i, s in enumerate(starts):
    e = starts[i + 1] if i + 1 < len(starts) else s + 0x400
    e = min(e, s + 0x4000)
    ctx = dis68k.Ctx()
    p = s
    while p < e:
        try:
            t, n, hits = dis68k.decode(p, ctx)
        except dis68k.Bad:
            p += 2; continue
        except IndexError:
            break
        for v, sz, role in hits:
            vv = v[1] if isinstance(v, tuple) else v
            if vv in targets:
                print('%-8s %06x %-45s %-48s ; %s %s %s' % (targets[vv], p, names[s] + '@%x' % s, t, ('idx+%x' % vv) if isinstance(v, tuple) else '%x' % vv, sz, role))
            elif isinstance(v, tuple):
                for tg in targets:
                    if vv <= tg < vv + 0x40:
                        print('%-8s %06x %-45s %-48s ; INDEXED base %x (target %x) %s %s' % (targets[tg], p, names[s] + '@%x' % s, t, vv, tg, sz, role))
                        break
        p += n
