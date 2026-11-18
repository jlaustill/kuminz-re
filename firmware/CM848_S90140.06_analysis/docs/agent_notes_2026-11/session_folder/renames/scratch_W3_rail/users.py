import sys, re
sys.path.insert(0, '/home/linux/.claude/jobs/d55ae3c6/tmp/renames/scratch_W3_rail')
import ctx
# usage: users.py <regex-or-names...>   -> for each global row whose name matches, list users (functions mentioning the name in the .cpp)
pats = [re.compile(p) for p in sys.argv[1:]]
names = [n for n in ctx.rows if any(p.search(n) for p in pats)]
# build name -> functions index lazily
idx = {}
fn_list = [(k, v) for k, v in ctx.funcs.items() if not k.startswith('0x')]
for fname, (addr, s, e) in fn_list:
    text = '\n'.join(ctx.cpp[s:e])
    for t in set(ctx.ident_set(text)):
        if t in names:
            idx.setdefault(t, []).append(fname)
for n in sorted(names, key=lambda x: ctx.rows[x][0]):
    r = ctx.rows[n]
    print(f"{r[0]} {n} [{r[2] if len(r) > 2 else ''}] users={idx.get(n, [])}\n     {(r[3] if len(r) > 3 else '')[:260]}")
