"""Assemble result_W9_gear_down.jsonl from rows_item*.py (each defines ROWS)."""
import importlib.util
import json
import os
import sys

HERE = os.path.dirname(os.path.abspath(__file__))
OUT = os.path.join(HERE, '..', 'result_W9_gear_down.jsonl')
rows = []
for name in sorted(os.listdir(HERE)):
    if name.startswith('rows_item') and name.endswith('.py'):
        spec = importlib.util.spec_from_file_location(name[:-3], os.path.join(HERE, name))
        mod = importlib.util.module_from_spec(spec)
        spec.loader.exec_module(mod)
        rows.extend(mod.ROWS)
with open(OUT, 'w') as fh:
    for r in rows:
        fh.write(json.dumps(r, ensure_ascii=True) + '\n')
from collections import Counter
print(len(rows), Counter((r['kind'], r.get('verdict')) for r in rows))
