import importlib
import json
import sys

sys.path.insert(0, '/home/linux/.claude/jobs/d55ae3c6/tmp/renames/w9gov_scratch')
OUT = '/home/linux/.claude/jobs/d55ae3c6/tmp/renames/result_W9_governor.jsonl'
PARTS = ['part2_droop', 'part1_cm550', 'part3_enums', 'part4_flags', 'part5_condensation', 'part6_skipped']

rows = []
for name in PARTS:
    try:
        mod = importlib.import_module(name)
    except ModuleNotFoundError as e:
        if e.name != name:
            raise
        print('missing part', name)
        continue
    rows.extend(mod.ROWS)
    print(name, len(mod.ROWS))

with open(OUT, 'w') as f:
    for r in rows:
        f.write(json.dumps(r, ensure_ascii=True) + '\n')
print('wrote', len(rows), 'rows to', OUT)
