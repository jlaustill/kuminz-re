import json, re
d = json.load(open('/home/linux/.claude/jobs/374b0424/tmp/w15/r94/batch_J2.json'))
p = d['proposal']
fr = '/home/linux/.claude/jobs/374b0424/tmp/w15/r93/frozen/'


def load_names(path, col=1):
    names = {}
    for line in open(path, errors='replace'):
        if line.startswith('#') or not line.strip():
            continue
        parts = line.rstrip('\n').split(',')
        if len(parts) > col:
            names.setdefault(parts[col].strip(), []).append(parts[0])
    return names


cm550f = load_names(fr + 'cm550/function_renames.csv')
cm848f = load_names(fr + 'cm848/function_renames.csv')
cm550g = load_names(fr + 'cm550/global_variables.csv')
cm848g = load_names(fr + 'cm848/global_variables.csv')
print('--- functions')
seen = {}
for f in p['functions']:
    n = f['proposed_name']
    seen.setdefault(n, []).append(f['address'])
    hits = []
    if n in cm550f: hits.append(('cm550f', cm550f[n]))
    if n in cm848f: hits.append(('cm848f', cm848f[n]))
    if n in cm550g: hits.append(('cm550g', cm550g[n]))
    if n in cm848g: hits.append(('cm848g', cm848g[n]))
    base = re.sub(r'^(cm550_|mc68k_|vp44_)', '', n)
    alt = 'cm848_' + base
    althits = cm848f.get(alt)
    print(f"{f['address']:>8} {f['relation']:<11} {n:<55} hits={hits} cm848form={alt if althits else ''}{althits or ''} cm848_addr={f.get('cm848_address','')}")
for n, a in seen.items():
    if len(a) > 1:
        print('DUP within proposal', n, a)
print('--- globals')
seeng = {}
for g in p['globals']:
    n = g['proposed_name']
    seeng.setdefault((g['firmware'], n), []).append(g['address'])
    tbl = cm550g if g['firmware'] == 'CM550' else cm848g
    tblf = cm550f if g['firmware'] == 'CM550' else cm848f
    hits = tbl.get(n, [])
    fh = tblf.get(n, [])
    other = cm848g.get(n, []) if g['firmware'] == 'CM550' else cm550g.get(n, [])
    print(f"{g['firmware']} {g['address']:>9} {g['current_name'][:40]:<40} -> {n:<55} {g['proposed_type']:<38} samefw={hits} fn={fh} otherfw={other}")
for n, a in seeng.items():
    if len(a) > 1:
        print('DUP within proposal', n, a)
