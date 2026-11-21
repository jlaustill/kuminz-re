"""usage: check_names.py name [name ...]  - report where each candidate name already occurs (CM848 CSVs and .cpp)"""
import csv
import re
import sys

out = '/home/linux/code/kuminz-re/.claude/worktrees/cm848-egr-flow-delay/firmware/CM848_S90140.06_analysis/output/'
cpp = open(out + 'cm848_rom.ghidra.cpp', errors='replace').read()
files = ['global_variables.csv', 'function_renames.csv', 'enums.csv', 'structure_definitions.csv', 'arrays.csv',
         'constants.csv', 'local_variables.csv', 'function_definitions.csv', 'labels.csv']
texts = {f: open(out + f, errors='replace').read() for f in files}
for name in sys.argv[1:]:
    pat = re.compile(r'(?<![A-Za-z0-9_])' + re.escape(name) + r'(?![A-Za-z0-9_])')
    hits = []
    for f, t in texts.items():
        n = len(pat.findall(t))
        if n:
            hits.append('%s:%d' % (f, n))
    n = len(pat.findall(cpp))
    if n:
        hits.append('cpp:%d' % n)
    # near-miss: prefix match in global_variables names
    print('%-62s %s' % (name, ', '.join(hits) if hits else 'free'))
