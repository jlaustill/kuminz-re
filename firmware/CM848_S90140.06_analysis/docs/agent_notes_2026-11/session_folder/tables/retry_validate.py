import csv
import json
import re

ROOT = '/home/linux/code/kuminz-re/.claude/worktrees/cm848-typing-arrays/firmware/CM848_S90140.06_analysis/'
TABLES = '/home/linux/.claude/jobs/d55ae3c6/tmp/tables/'

bin_ids = [lookup['id'] for lookup in json.load(open(TABLES + 'bin_retry.json'))['lookups']]
kinds = {lookup['id']: lookup['kind'] for lookup in json.load(open(TABLES + 'bin_retry.json'))['lookups']}

existing = set()
with open(ROOT + 'output/global_variables.csv') as handle:
    for row in csv.reader(handle):
        if len(row) >= 2:
            existing.add(row[1])

seen = []
named = 0
skipped = 0
for number, line in enumerate(open(TABLES + 'result_retry.jsonl'), 1):
    line = line.strip()
    if not line:
        continue
    record = json.loads(line)
    seen.append(record['lookup'])
    if record.get('skip'):
        skipped += 1
        assert record.get('reason'), number
        continue
    named += 1
    base = record['base']
    assert re.fullmatch(r'[a-z0-9_]+', base), base
    assert len(base) <= 48, (base, len(base))
    assert '_cal' not in base and '0x' not in base, base
    assert record['confidence'] in ('high', 'medium'), record['confidence']
    suffixes = ['_axis', '_values'] if kinds[record['lookup']] == '1-D' else ['_x_axis', '_y_axis', '_grid']
    for suffix in suffixes:
        composed = base + suffix
        assert len(composed) <= 56, (composed, len(composed))
        assert composed not in existing, composed
    print('OK', record['lookup'], base, len(base), kinds[record['lookup']])

assert sorted(seen) == sorted(bin_ids), (sorted(seen), sorted(bin_ids))
assert len(seen) == len(set(seen))
print('lines', len(seen), 'named', named, 'skipped', skipped)
