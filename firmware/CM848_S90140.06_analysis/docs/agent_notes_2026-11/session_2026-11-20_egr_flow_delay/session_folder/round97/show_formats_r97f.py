"""Round 97 stage F: print one entry of each proposal list of batches R5-R7, and the twin fields."""
import json
W = '/home/linux/.claude/jobs/374b0424/tmp/w15/r97'
for b in ('R5', 'R6', 'R7'):
    d = json.load(open(f'{W}/batch_{b}.json'))
    p = d['proposal']
    print('==', b)
    for k in ('functions', 'cm848_functions', 'globals', 'enum_members', 'prototypes', 'skipped'):
        if p.get(k):
            x = p[k][0]
            print(' ', k, len(p[k]), {a: str(v)[:70] for a, v in x.items()})
    tw = [f for f in p.get('functions') or [] if any('twin' in k or 'cm848' in k for k in f) and any(f.get(k) for k in f if 'twin' in k or 'cm848' in k)]
    print('  functions with a twin / cm848 field:', len(tw))
