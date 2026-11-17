import json
import re
import sys

root = sys.argv[1]
result = '/home/linux/.claude/jobs/d55ae3c6/tmp/tables/result_06.jsonl'
csv_path = root + '/firmware/CM848_S90140.06_analysis/output/global_variables.csv'
other_csvs = ['function_renames.csv', 'structure_definitions.csv', 'enums.csv', 'local_variables.csv',
              'arrays.csv', 'labels.csv', 'constants.csv', 'function_definitions.csv']

text = open(csv_path).read()
others = {n: open(root + '/firmware/CM848_S90140.06_analysis/output/' + n).read() for n in other_csvs}

lines = open(result).read().splitlines()
print('lines', len(lines))
bases = []
for i, line in enumerate(lines):
    row = json.loads(line)
    base = row['base']
    ok = []
    ok.append(re.fullmatch(r'[a-z][a-z0-9_]*', base) is not None)
    ok.append(len(base) <= 48)
    ok.append('_cal' not in base)
    ok.append(not re.search(r'0x|[0-9a-f]{8}', base))
    ok.append('protection' not in base)
    for suffix in ['', '_axis', '_values', '_x_axis', '_y_axis', '_grid']:
        name = base + suffix
        if (',' + name + ',') in text or (',' + name + '\n') in text:
            ok.append(False)
            print('  collision in global_variables.csv:', name)
        for n, t in others.items():
            if name in t:
                ok.append(False)
                print('  collision in', n, name)
    print(row['lookup'], base, len(base), 'OK' if all(ok) else 'PROBLEM', row['confidence'])
    bases.append(base)
    # every required key present
    for key in ['lookup', 'base', 'input', 'output', 'units_check', 'confidence', 'evidence', 'naming_concern']:
        assert key in row and row[key], key
    # non ascii check
    assert all(ord(ch) < 128 for ch in line), 'non ascii in ' + row['lookup']
print('unique bases', len(set(bases)) == len(bases))
