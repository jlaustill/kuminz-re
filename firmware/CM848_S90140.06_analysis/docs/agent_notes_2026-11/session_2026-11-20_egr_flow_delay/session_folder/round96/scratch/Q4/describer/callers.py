#!/usr/bin/env python3
"""List the enclosing function of each line that mentions a name (callers)."""
import re
import sys

cpp = sys.argv[1]
names = sys.argv[2:]
lines = open(cpp, encoding='utf-8', errors='replace').read().split('\n')
func_at = []
cur = None
for i, l in enumerate(lines):
    m = re.match(r'// Function: (\S+) @ (\S+)', l)
    if m:
        cur = (m.group(1), m.group(2))
    func_at.append(cur)
for n in names:
    pat = re.compile(r'\b' + re.escape(n) + r'\b')
    found = {}
    for i, l in enumerate(lines):
        if pat.search(l) and not l.startswith('// Function:'):
            f = func_at[i]
            if f and f[0] != n:
                found.setdefault(f, []).append(i + 1)
    print('==', n)
    for f, ls in found.items():
        print('   ', f[0], f[1], ls[:6])
