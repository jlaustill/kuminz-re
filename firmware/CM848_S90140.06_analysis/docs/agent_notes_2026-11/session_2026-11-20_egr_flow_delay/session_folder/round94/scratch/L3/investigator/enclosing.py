import sys
starts = []
for line in open('/home/linux/.claude/jobs/374b0424/tmp/w15/r94/scratch/L3/investigator/func_starts.txt'):
    a, n = line.split()
    starts.append((int(a, 16), n))
starts.sort()
for arg in sys.argv[1:]:
    x = int(arg, 16)
    best = None
    for a, n in starts:
        if a <= x:
            best = (a, n)
    print(hex(x), hex(best[0]), best[1])
