import csv, re, sys
sys.argv = ['x', 'globals']
OUT = '/home/linux/code/kuminz-re/.claude/worktrees/cm848-typing-arrays/firmware/CM848_S90140.06_analysis/output/'
exec(open('/home/linux/.claude/jobs/d55ae3c6/tmp/renames/w7/twin_scan.py').read().split("if len(sys.argv) > 1")[0])
covered = set()
for l in open('/home/linux/.claude/jobs/d55ae3c6/tmp/renames/w7/covered.txt'):
    covered.add(l.strip())
for t, fs in names_in_twin.items():
    ad = byname[t][0]
    if t in covered: continue
    short = ','.join(sorted('%x' % f for f in fs))
    print(f"0x{ad:08x} {t} {rows[ad][2]} [{short}]")
