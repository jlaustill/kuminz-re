import sys
rows = []
for line in open('/home/linux/.claude/jobs/374b0424/tmp/w15/r97/scratch/R1/judge/cm550_funcs_sorted.txt'):
    a, n = line.strip().split(',', 1)
    try:
        rows.append((int(a, 16), n.split(',')[0]))
    except ValueError:
        pass
rows.sort()
for x in sys.argv[1:]:
    t = int(x, 16)
    best = None
    for v, n in rows:
        if v <= t:
            best = (v, n)
        else:
            break
    print('%s -> 0x%x %s' % (x, best[0], best[1]))
