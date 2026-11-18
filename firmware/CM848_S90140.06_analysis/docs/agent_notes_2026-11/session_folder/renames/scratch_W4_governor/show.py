import json, sys
fn = sys.argv[1]
skip = set(sys.argv[2].split(',')) if len(sys.argv) > 2 else set()
for line in open(fn):
    r = json.loads(line)
    if r['kind'] == 'note':
        continue
    print(json.dumps({k: v for k, v in r.items() if k not in skip}))
