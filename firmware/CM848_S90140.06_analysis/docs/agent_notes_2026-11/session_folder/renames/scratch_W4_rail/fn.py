import sys
sys.path.insert(0, '/home/linux/.claude/jobs/d55ae3c6/tmp/renames/scratch_W4_rail')
import ctx
# usage: fn.py <name_or_addr> [grep-pattern]   -> prints the function, or only matching lines with 2 lines of context
name = sys.argv[1]
pat = sys.argv[2] if len(sys.argv) > 2 else None
if name.startswith('@'):
    # find the function containing an address
    a = int(name[1:], 16)
    best = None
    for k, v in ctx.funcs.items():
        if k.startswith('0x'):
            ka = int(k, 16)
            if ka <= a and (best is None or ka > best[0]):
                best = (ka, k, v)
    print('containing function:', best[1], best[2][0], 'lines', best[2][1] + 1, '-', best[2][2])
    name = best[1]
f = ctx.funcs[name]
body = ctx.cpp[f[1]:f[2]]
print('// ', f[0], 'lines', f[1] + 1, '-', f[2], '(%d lines)' % (f[2] - f[1]))
if pat is None:
    print('\n'.join(body))
else:
    import re
    for i, l in enumerate(body):
        if re.search(pat, l):
            for j in range(max(0, i - 2), min(len(body), i + 3)):
                print('%d: %s' % (f[1] + 1 + j, body[j]))
            print('--')
