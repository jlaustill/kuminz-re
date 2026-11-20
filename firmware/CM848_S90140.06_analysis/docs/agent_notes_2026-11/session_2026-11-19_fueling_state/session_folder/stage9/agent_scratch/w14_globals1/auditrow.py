import csv
import sys

rows = list(csv.DictReader(open('/home/linux/.claude/jobs/f6a06670/tmp/fueling_state/stage8/audit_after8c.csv')))
for r in rows:
    if r['block'] in sys.argv[1:]:
        print(r['block'], r['offset'], r['record'], r['size'], r['unit'], r['signed'], r['scale'], r['min'], r['max'], r['address'], r['status'], r['row_name'], 'dump=', r['dump_raw'])
