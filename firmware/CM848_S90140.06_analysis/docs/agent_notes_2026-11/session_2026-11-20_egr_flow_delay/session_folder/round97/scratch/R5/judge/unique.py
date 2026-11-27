"""Check that each name appears in no row of the frozen CSVs of either firmware (function, global, struct, enum names)."""
import csv
import re
import sys

FROZEN = '/home/linux/.claude/jobs/374b0424/tmp/w15/r97/frozen/'
files = {
    'cm550 functions': FROZEN + 'cm550/function_renames.csv',
    'cm848 functions': FROZEN + 'cm848/function_renames.csv',
    'cm550 globals': FROZEN + 'cm550/global_variables.csv',
    'cm848 globals': FROZEN + 'cm848/global_variables.csv',
    'cm550 structs': FROZEN + 'cm550/structure_definitions.csv',
    'cm848 structs': FROZEN + 'cm848/structure_definitions.csv',
    'cm550 enums': FROZEN + 'cm550/enums.csv',
    'cm848 enums': FROZEN + 'cm848/enums.csv',
}
names = {}
for label, path in files.items():
    with open(path, newline='') as f:
        for line in f:
            if line.startswith('#'):
                continue
            parts = line.split(',')
            if len(parts) < 2:
                continue
            if 'struct' in label:
                keys = [parts[0], parts[2] if len(parts) > 2 else '']
            elif 'enum' in label:
                keys = [parts[0], parts[2] if len(parts) > 2 else '']
            else:
                keys = [parts[1]]
            for k in keys:
                names.setdefault(k.strip(), []).append(f"{label}:{parts[0]}")
for n in sys.argv[1:]:
    print(f"{n}: {names.get(n, 'FREE')}")
