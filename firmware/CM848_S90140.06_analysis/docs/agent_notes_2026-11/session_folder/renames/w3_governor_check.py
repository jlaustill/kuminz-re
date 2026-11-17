import csv, sys
OUT = '/home/linux/code/kuminz-re/.claude/worktrees/cm848-typing-arrays/firmware/CM848_S90140.06_analysis/output/'
names = [l.strip() for l in open('/home/linux/.claude/jobs/d55ae3c6/tmp/renames/w3_governor_names.txt') if l.strip()]
existing = {}
for fn in ['global_variables.csv', 'function_renames.csv', 'arrays.csv', 'constants.csv', 'enums.csv']:
    with open(OUT + fn, newline='') as f:
        for line in f:
            if line.startswith('#') or not line.strip():
                continue
            parts = line.split(',', 2)
            if len(parts) > 1:
                existing.setdefault(parts[1].strip(), []).append(fn + ':' + parts[0])
bad = 0
for n in names:
    if n in existing:
        print('COLLISION', n, existing[n])
        bad += 1
print('checked', len(names), 'names,', bad, 'collisions')
dups = [n for n in set(names) if names.count(n) > 1]
print('duplicates inside my list:', dups)
for key in ['fan_drive_state', 'fan_drive_estimated', 'engine_retarder_configuration', 'all_speed_governor_droop']:
    print(key, [k for k in existing if key in k][:8])
