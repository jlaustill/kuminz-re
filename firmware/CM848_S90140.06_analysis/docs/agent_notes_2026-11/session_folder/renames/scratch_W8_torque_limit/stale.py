"""List CSV rows whose text (not the name column) cites names that wave 8 retires."""
import csv
import re
import sys

OUT = '/home/linux/code/kuminz-re/.claude/worktrees/cm848-typing-arrays/firmware/CM848_S90140.06_analysis/output/'
OLD = sys.argv[1].split(',')
pat = re.compile(r'(?<![A-Za-z0-9_])(' + '|'.join(re.escape(o) for o in OLD) + r')(?![A-Za-z0-9_])')
files = ['function_renames.csv', 'global_variables.csv', 'structure_definitions.csv', 'enums.csv', 'arrays.csv',
         'local_variables.csv', 'function_definitions.csv', 'constants.csv', 'labels.csv']
for fn in files:
    try:
        lines = open(OUT + fn, errors='replace').read().split('\n')
    except FileNotFoundError:
        continue
    for i, l in enumerate(lines, 1):
        if not l or (l.startswith('#') and fn not in ('structure_definitions.csv',)):
            pass
        parts = l.split(',', 3)
        name_col = parts[1] if len(parts) > 1 else ''
        text = l if l.startswith('#') else (parts[2] if fn == 'function_renames.csv' and len(parts) > 2 else ','.join(parts[3:]) if fn == 'global_variables.csv' else l)
        found = sorted(set(m.group(1) for m in pat.finditer(text)))
        if found:
            print(f'{fn}:{i}: addr={parts[0][:12]} name={name_col[:60]} cites={found}')
