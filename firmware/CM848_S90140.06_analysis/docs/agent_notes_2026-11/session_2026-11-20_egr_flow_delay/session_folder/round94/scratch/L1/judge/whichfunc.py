import sys, bisect
FR = {
    'cm550': '/home/linux/.claude/jobs/374b0424/tmp/w15/r94/frozen/cm550/function_renames.csv',
    'cm848': '/home/linux/.claude/jobs/374b0424/tmp/w15/r94/frozen/cm848/function_renames.csv',
}
fw = 'cm550'
args = sys.argv[1:]
if args and args[0] in FR:
    fw = args[0]
    args = args[1:]
rows = []
with open(FR[fw]) as f:
    for line in f:
        if not line.startswith('0x'):
            continue
        a, n = line.split(',')[:2]
        rows.append((int(a, 16), n))
rows.sort()
keys = [r[0] for r in rows]
for x in args:
    v = int(x, 16)
    i = bisect.bisect_right(keys, v) - 1
    print(x, '->', hex(rows[i][0]), rows[i][1])
