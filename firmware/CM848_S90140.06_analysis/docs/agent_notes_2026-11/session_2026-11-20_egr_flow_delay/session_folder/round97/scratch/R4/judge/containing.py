"""Map ROM addresses (abs_refs sites) to the containing CM550 function (frozen function_renames.csv)."""
import bisect
import csv
import sys

frozen = '/home/linux/.claude/jobs/374b0424/tmp/w15/r97/frozen/cm550/'
rows = sorted((int(r[0], 16), r[1]) for r in csv.reader(open(frozen + 'function_renames.csv')) if r and r[0].startswith('0x'))
starts = [r[0] for r in rows]
for arg in sys.argv[1:]:
    a = int(arg, 16)
    i = bisect.bisect_right(starts, a) - 1
    print(f'0x{a:x} in {rows[i][1]} @0x{rows[i][0]:x}' if i >= 0 else f'0x{a:x} ?')
