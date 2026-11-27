import json, csv
draft = json.load(open('/home/linux/.claude/jobs/374b0424/tmp/w15/r91/scratch/S2/draft.json'))
gv = '/home/linux/code/kuminz-re/.claude/worktrees/cm848-egr-flow-delay/firmware/CM550_J90350.00_analysis/output/global_variables.csv'
rows = {}
for line in open(gv):
    if not line.startswith('0x'):
        continue
    parts = line.rstrip('\n').split(',', 3)
    rows.setdefault(int(parts[0], 16), []).append((parts[1], parts[2], parts[3] if len(parts) > 3 else ''))
bad = 0
for r in draft['rows_to_remove']:
    a = int(r['address'], 16)
    got = rows.get(a)
    if not got or got[0][0] != r['name']:
        bad += 1
        print('MISMATCH', r['address'], r['name'], got)
    elif len(got) > 1:
        print('DUPLICATE ROWS', r['address'], got)
    elif got[0][1] != 'undefined' and not r['name'].startswith('datalogger_'):
        print('TYPED', r['address'], got)
print('removals checked', len(draft['rows_to_remove']), 'bad', bad)
# globals with current_name: check the current row exists with that name
for g in draft['globals']:
    a = int(g['address'], 16)
    got = rows.get(a)
    cn = g.get('current_name')
    if cn:
        if not got or got[0][0] != cn:
            print('GLOBAL CURRENT MISMATCH', g['address'], cn, got)
    else:
        if got:
            print('GLOBAL NEW BUT ROW EXISTS', g['address'], got)
# extents: any remaining row (not removed, not the global itself) inside a typed extent
sizes = {'byte': 1, 'word': 2, 'dword': 4, 'byte *': 4, 'datalogger_trigger_t[4]': 64, 'datalogger_data_parameter_t[5]': 30,
         'dword[4]': 16, 'byte[4]': 4, 'byte[400]': 400, 'dword[5]': 20, 'datalogger_trigger_information_t': 8,
         'byte[800]': 800, 'datalogger_trigger_information_t[2]': 16}
removed = {int(r['address'], 16) for r in draft['rows_to_remove']}
gaddrs = {int(g['address'], 16) for g in draft['globals']}
for g in draft['globals']:
    a = int(g['address'], 16)
    n = sizes[g['proposed_type']]
    for b in range(a + 1, a + n):
        if b in rows and b not in removed:
            print('LEFTOVER ROW INSIDE', g['address'], g['proposed_name'], hex(b), rows[b][0][0])
        if b in gaddrs:
            print('OVERLAPS ANOTHER PROPOSED GLOBAL', g['address'], hex(b))
print('extent check done')
