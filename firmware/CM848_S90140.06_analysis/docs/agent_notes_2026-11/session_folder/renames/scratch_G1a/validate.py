import csv, json, re
B = '/home/linux/code/kuminz-re/.claude/worktrees/cm848-typing-arrays/firmware/CM848_S90140.06_analysis/output/'
g = {}
for r in csv.reader(open(B + 'global_variables.csv')):
    if len(r) > 1:
        g.setdefault(int(r[0], 16) if r[0].startswith('0x') else -1, []).append(r[1])
f = {}
for r in csv.reader(open(B + 'function_renames.csv')):
    if len(r) > 1 and r[0].startswith('0x'):
        f[int(r[0], 16)] = r[1]
allnames = set()
for fn in ('global_variables.csv', 'function_renames.csv', 'arrays.csv'):
    for r in csv.reader(open(B + fn)):
        if len(r) > 1:
            allnames.add(r[1])
recs = [json.loads(l) for l in open('/home/linux/.claude/jobs/d55ae3c6/tmp/renames/result_G1a.jsonl')]
seen_new = {}
seen_addr = {}
bad = 0
for r in recs:
    k = r['kind']
    if k == 'note':
        continue
    a = int(r['address'], 16)
    if k == 'function':
        ok = f.get(a) == r['old']
    else:
        ok = r['old'] in g.get(a, [])
    if not ok:
        print('OLD NAME/ADDRESS MISMATCH', r['address'], r['old'], g.get(a), f.get(a)); bad += 1
    new = r.get('new')
    if new:
        if new in allnames:
            print('COLLISION', new); bad += 1
        if new in seen_new:
            print('DUPLICATE NEW', new, seen_new[new], r['address']); bad += 1
        seen_new[new] = r['address']
        if k == 'function':
            if not re.fullmatch(r'cm848_[a-z][A-Za-z]+', new):
                print('FN STYLE', new); bad += 1
        else:
            if not re.fullmatch(r'[a-z][a-z_]*', new):
                print('STYLE (digits/caps)', new); bad += 1
            if new.endswith('_cal') and not (0x3fd482 <= a <= 0x3feec1):
                print('_cal outside EEPROM', new); bad += 1
            if 'protection' in new or '_aux_' in new or new.startswith('aux_') or 'ctrl' in new:
                print('NAME RULE', new); bad += 1
    if a in seen_addr:
        print('DUPLICATE ADDRESS', r['address']); bad += 1
    seen_addr[a] = 1
print('records', len(recs), 'bad', bad)
cnt = {}
for r in recs:
    cnt[(r['kind'], r.get('verdict'))] = cnt.get((r['kind'], r.get('verdict')), 0) + 1
print(cnt)
