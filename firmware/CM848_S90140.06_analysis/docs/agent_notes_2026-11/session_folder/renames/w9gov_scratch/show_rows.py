import json, sys
path = sys.argv[1]
lo = int(sys.argv[2]) if len(sys.argv) > 2 else 0
hi = int(sys.argv[3]) if len(sys.argv) > 3 else 10**9
rows = [json.loads(l) for l in open(path)]
for i, r in enumerate(rows):
    if i < lo or i > hi:
        continue
    if r.get('kind') != 'note':
        d = {k: (v if k != 'plate_comment' else v[:250]) for k, v in r.items()}
        print(i, json.dumps(d)[:900])
