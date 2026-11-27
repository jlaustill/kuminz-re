"""Census of how the CM550 .cpp uses each enable word: masked tests in conditions, masked values assigned or returned
(value flow), and CONCAT22 forms. usage: use_census.py <cpp> <symbol>..."""
import re
import sys
cpp = open(sys.argv[1], errors='replace').read().splitlines()
fn = re.compile(r'^// Function: (\S+) @ 0x([0-9a-fA-F]+)')
for sym in sys.argv[2:]:
    s = re.escape(sym)
    test = re.compile(r'\(_?' + s + r' & (0x[0-9a-f]+|\d+)\) [!=]= 0')
    flow = re.compile(r'(\w+ = |return )_?' + s + r' & (0x[0-9a-f]+|\d+)')
    concat = re.compile(r'CONCAT22\([^,]+,_?' + s + r'\) & (0x[0-9a-f]+)')
    other = re.compile(r'\b_?' + s + r'\b')
    cur = '?'
    counts = {'test': [], 'flow': [], 'concat': [], 'other': []}
    for i, line in enumerate(cpp, 1):
        m = fn.match(line)
        if m:
            cur = m.group(1)
            continue
        t = test.findall(line)
        f = flow.findall(line)
        c = concat.findall(line)
        n = len(other.findall(line))
        for x in t:
            counts['test'].append((i, cur, x))
        for x in f:
            counts['flow'].append((i, cur, x[1]))
        for x in c:
            counts['concat'].append((i, cur, x))
        rest = n - len(t) - len(f) - len(c)
        if rest > 0:
            counts['other'].append((i, cur, line.strip()[:120]))
    print(f'== {sym}: tests {len(counts["test"])}, value flow {len(counts["flow"])}, concat {len(counts["concat"])}, other {len(counts["other"])}')
    for k in ('test', 'flow', 'concat', 'other'):
        for item in counts[k]:
            print(f'   {k:6} {item[0]:6} {item[1]}: {item[2]}')
