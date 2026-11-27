"""Read-only mirror of the two apply_renames.py checks my validate.py lacked: exactly one global_variables.csv row per
address whose name equals `old`, and no register address. Also the used-name set across the three CSVs."""
import json

OUT = '/home/linux/code/kuminz-re/.claude/worktrees/cm848-egr-flow-delay/firmware/CM848_S90140.06_analysis/output/'
rows = {}
for line in open(OUT + 'global_variables.csv', errors='replace'):
    p = line.rstrip('\n').split(',', 3)
    if p[0].startswith('0x'):
        rows.setdefault(int(p[0], 16), []).append(p[1])
registers = set()
for line in open(OUT + 'mpc555_registers.csv', errors='replace'):
    p = line.split(',', 1)
    if p[0].startswith('0x'):
        registers.add(int(p[0], 16))
problems = 0
for line in open('/home/linux/.claude/jobs/374b0424/tmp/w15/results/result_W15_bin6.jsonl'):
    r = json.loads(line)
    a = int(r['address'], 16)
    names = rows.get(a, [])
    if len(names) != 1 or names[0] != r['old']:
        print('ROW MISMATCH', r['address'], r['old'], names)
        problems += 1
    if a in registers:
        print('REGISTER ADDRESS', r['address'])
        problems += 1
print('checked; problems:', problems)
