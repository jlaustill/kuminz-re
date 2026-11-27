"""Judge D1: compare each proposed global with the frozen CM550 rows (current row, rows inside the new extent)."""
import csv
import json

BASE = "/home/linux/.claude/jobs/374b0424/tmp/w15/r93/"
rows = list(csv.reader(open(BASE + "frozen/cm550/global_variables.csv")))
g = {}
for r in rows[1:]:
    if not r or r[0].startswith('#'):
        continue
    try:
        a = int(r[0], 16)
    except ValueError:
        continue
    g.setdefault(a, []).append(r)
d = json.load(open(BASE + 'scratch/D1/investigator/final_output.json'))
p = d
sizes = {'byte': 1, 'word': 2, 'dword': 4, 'i32': 4, 'pointer': 4, 'IDLE_SHUTDOWN_STATE': 2,
         'EEPROM_BYTE_WRITE_STATE': 4, 'table_lookup_2d_arguments_t': 22}


def sz(t):
    if '[' in t:
        base, n = t[:-1].split('[')
        return sizes.get(base, 0) * int(n)
    return sizes.get(t, 0)


names = {}
for x, rs in g.items():
    for r in rs:
        names.setdefault(r[1], []).append(hex(x))
for gl in p['globals']:
    a = int(gl['address'], 16)
    t = gl['proposed_type']
    s = sz(t)
    cur = g.get(a)
    inside = [(hex(x), r[1], r[2]) for x in sorted(g) if a < x < a + s for r in g[x]]
    dup = names.get(gl['proposed_name'])
    print(gl['address'], gl['current_name'] or '-', '->', gl['proposed_name'], t, '| frozen:',
          [(r[1], r[2]) for r in cur] if cur else None, '| inside:', inside, '| name used at:', dup)
