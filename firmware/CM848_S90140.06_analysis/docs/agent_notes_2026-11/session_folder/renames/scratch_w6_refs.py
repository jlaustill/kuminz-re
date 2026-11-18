import json
import os
import re
import sys

ROOT = sys.argv[1]
RES = sys.argv[2]
rows = [json.loads(l) for l in open(RES) if l.strip()]
old = {}
for r in rows:
    if r['kind'] in ('function', 'global') and r.get('old') and r.get('new'):
        old[r['old']] = r['new']
print('old names to look for:', len(old))
tok = re.compile(r'[A-Za-z_][A-Za-z0-9_+]*')
exts = ('.csv', '.md', '.txt', '.json', '.py', '.sh', '.java')
skip_dirs = {'.git', 'node_modules', 'ghidra_projects', 'build', '__pycache__', '.claude'}
skip_files = {'global_variables.csv', 'function_renames.csv'}
hits = {}
for base in ('firmware', 'docs', 'work', 'clip-core', 'kuminz-cli', 'tools'):
    top = os.path.join(ROOT, base)
    if not os.path.isdir(top):
        continue
    for dp, dn, fns in os.walk(top):
        dn[:] = [d for d in dn if d not in skip_dirs]
        for fn in fns:
            if not fn.endswith(exts):
                continue
            p = os.path.join(dp, fn)
            rel = os.path.relpath(p, ROOT)
            if fn in skip_files and 'CM848_S90140.06_analysis/output' in rel:
                continue
            try:
                if os.path.getsize(p) > 20_000_000:
                    continue
                with open(p, errors='replace') as f:
                    for i, line in enumerate(f, 1):
                        for t in set(tok.findall(line)):
                            if t in old:
                                hits.setdefault(rel, {}).setdefault(t, []).append(i)
            except OSError:
                pass
if not hits:
    print('no hit')
for rel in sorted(hits):
    d = hits[rel]
    print(rel, '| distinct', len(d), '| lines', sum(len(v) for v in d.values()), '|',
          ', '.join('%s(%d)' % (k, len(v)) for k, v in sorted(d.items())[:8]))
