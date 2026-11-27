"""R4 investigator scratch: check the proposal table against the frozen CM550 CSVs (uniqueness, batch coverage)."""
import csv

BASE = '/home/linux/.claude/jobs/374b0424/tmp/w15/r97/'
S = BASE + 'scratch/R4/investigator/'
props = [line.rstrip('\n').split('\t') for line in open(S + 'proposals.tsv') if line.strip()]
extras = []
try:
    extras = [line.rstrip('\n').split('\t') for line in open(S + 'extras.tsv') if line.strip()]
except FileNotFoundError:
    pass
rows = list(csv.reader(open(BASE + 'frozen/cm550/global_variables.csv')))[1:]
names = {}
for r in rows:
    try:
        a = int(r[0], 16)
    except ValueError:
        continue
    names.setdefault(r[1], []).append(a)
functions = {r[1] for r in csv.reader(open(BASE + 'frozen/cm550/function_renames.csv')) if len(r) > 1}
batch = {int(line.split()[0], 16) for line in open(BASE + 'family_R4.txt') if line.strip()}
allp = props + extras
proposed_names = [p[1] for p in allp]
print('proposals', len(props), 'extras', len(extras))
print('duplicate proposals:', sorted({n for n in proposed_names if proposed_names.count(n) > 1}))
for a, n, t in allp:
    ai = int(a, 16)
    if [a, n, t] in props and ai not in batch:
        print('NOT IN BATCH', a)
    if n in names and any(x != ai for x in names[n]):
        print('COLLIDES', a, n, [hex(x) for x in names[n]])
    if n in functions:
        print('COLLIDES WITH A FUNCTION', n)
    if len(n) > 70:
        print('LONG', len(n), n)
skipped = sorted(batch - {int(p[0], 16) for p in props})
print('skipped count', len(skipped))
print(' '.join(hex(x) for x in skipped))
