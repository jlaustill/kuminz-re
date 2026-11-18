import csv, re, json
OUT = '/home/linux/code/kuminz-re/.claude/worktrees/cm848-typing-arrays/firmware/CM848_S90140.06_analysis/output/'
names = set()
for r in csv.reader(open(OUT + 'global_variables.csv')):
    if len(r) >= 3 and r[0].startswith('0x') and r[1]:
        names.add(r[1])
fpat = re.compile(r'^// Function: (\S+) @ 0x([0-9a-fA-F]+)')
ident = re.compile(r'[A-Za-z_][A-Za-z_0-9]*')
users = {}
cur = None
for line in open(OUT + 'cm848_rom.ghidra.cpp', errors='replace'):
    m = fpat.match(line)
    if m:
        cur = '0x' + m.group(2).lower()
        continue
    if cur is None:
        continue
    for t in ident.findall(line):
        if t in names:
            s = users.setdefault(t, [])
            if not s or s[-1] != cur:
                s.append(cur)
for k in users:
    users[k] = sorted(set(users[k]))
json.dump(users, open('/home/linux/.claude/jobs/d55ae3c6/tmp/renames/w7/users.json', 'w'))
print(len(users))
