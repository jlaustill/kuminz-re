import re, sys
cpp = sys.argv[1]
names = sys.argv[2:]
cur = None
users = {n: {} for n in names}
pats = {n: re.compile(r'(?<![A-Za-z0-9_])_?' + re.escape(n) + r'(?![A-Za-z0-9_])') for n in names}
for line in open(cpp, errors='replace'):
    m = re.match(r'^// Function: (\S+) @', line)
    if m:
        cur = m.group(1)
        continue
    for n in names:
        if pats[n].search(line):
            users[n][cur] = users[n].get(cur, 0) + 1
for n in names:
    print(n, '->', ', '.join('%s(%d)' % (k, v) for k, v in sorted(users[n].items(), key=lambda kv: str(kv[0]))) or 'NONE')
