import csv, re, sys

# usage: fam.py <regex-on-name-or-address> [comment-width]
# prints matching rows from global_variables.csv, function_renames.csv, arrays.csv
pattern = re.compile(sys.argv[1])
width = int(sys.argv[2]) if len(sys.argv) > 2 else 160
base = '/home/linux/code/kuminz-re/.claude/worktrees/cm848-typing-arrays/firmware/CM848_S90140.06_analysis/output/'
for fn in ['global_variables.csv', 'function_renames.csv', 'arrays.csv']:
    with open(base + fn) as handle:
        for line in handle:
            if line.startswith('#'):
                continue
            parts = line.rstrip('\n').split(',', 3 if fn == 'global_variables.csv' else 2)
            if len(parts) < 2:
                continue
            if pattern.search(parts[1]) or pattern.fullmatch(parts[0]):
                comment = parts[-1] if len(parts) > 2 else ''
                if fn == 'global_variables.csv' and len(parts) >= 4:
                    row = parts[0] + ' ' + parts[1] + ' [' + parts[2] + '] ' + parts[3]
                elif fn == 'function_renames.csv':
                    row = parts[0] + ' ' + parts[1] + ' (fn) ' + (parts[2] if len(parts) > 2 else '')
                else:
                    row = ' | '.join(parts)
                print(fn[:3] + ' ' + row[:width + 60])
