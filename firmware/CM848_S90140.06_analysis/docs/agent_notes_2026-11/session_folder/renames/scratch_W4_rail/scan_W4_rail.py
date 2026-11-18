import json, re, glob, os, subprocess
WT = '/home/linux/code/kuminz-re/.claude/worktrees/cm848-typing-arrays'
REN = '/home/linux/.claude/jobs/d55ae3c6/tmp/renames/'
os.chdir(WT)

print('=== (a) boot-ROM filter sanity on the wave 3 time-shared words')
out = subprocess.run(['python3', '-I', REN + 'scratch_W4_rail/xrefs.py', '0x3fee34', '0x3fee38', '0x3fee3a', '0x3fa0fc'],
                     capture_output=True, text=True).stdout
print(out)

print('=== (b) retired names in the cross-firmware files')
mine = [json.loads(l) for l in open(REN + 'result_W4_rail.jsonl')]
olds = sorted(set(r['old'] for r in mine if r['kind'] in ('function', 'global') and r.get('new') and r['new'] != r['old']))
files = ['firmware/CM550_J90350.00_analysis/output/function_renames.csv',
         'firmware/CM550_J90350.00_analysis/output/global_variables.csv',
         'docs/cross_firmware_variable_map.csv',
         'firmware/cross_firmware_matches.csv']
texts = {}
for f in files:
    p = os.path.join(WT, f)
    texts[f] = open(p, errors='replace').read() if os.path.exists(p) else None
    print('  file', f, 'exists' if texts[f] is not None else 'MISSING')
hits = 0
for o in olds:
    pat = re.compile(r'(?<![A-Za-z0-9_])' + re.escape(o) + r'(?![A-Za-z0-9_])')
    for f, t in texts.items():
        if t and pat.search(t):
            hits += 1
            line = [l for l in t.split('\n') if pat.search(l)][0]
            print('  HIT', o, 'in', f, '::', line[:160])
print('  retired names checked:', len(olds), 'hits:', hits)

print('=== (c) overlap with other wave-4 result files')
keys = set()
for r in mine:
    if r['kind'] in ('function', 'global', 'new_global'):
        keys.add(r['address'].lower())
mynew = set(r['new'] for r in mine if r.get('new'))
for f in sorted(glob.glob(REN + 'result_W4_*.jsonl')):
    if f.endswith('result_W4_rail.jsonl'):
        continue
    n = 0
    for l in open(f):
        try:
            r = json.loads(l)
        except Exception:
            continue
        a = (r.get('address') or '').lower()
        txt = json.dumps(r)
        if a in keys or any(x in txt for x in mynew):
            n += 1
            print('  OVERLAP', os.path.basename(f), r.get('kind'), r.get('address'), r.get('old'), '->', r.get('new'))
    print('  ', os.path.basename(f), 'overlaps:', n)
print('files:', [os.path.basename(x) for x in sorted(glob.glob(REN + 'result_W4_*.jsonl'))])
