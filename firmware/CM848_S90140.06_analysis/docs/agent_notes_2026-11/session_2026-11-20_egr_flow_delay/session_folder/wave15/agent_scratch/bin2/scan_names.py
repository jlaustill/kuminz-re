import json
import re

BAD = {'temp', 'tmp', 'cnt', 'ref', 'val', 'calc', 'coef', 'coeff', 'cfg', 'init', 'msg', 'ptr', 'num', 'idx', 'avg', 'lim',
       'limit_', 'pos', 'cmd', 'thd', 'tmptr', 'diag', 'ovr', 'vlv', 'pct', 'cyl', 'est', 'press', 'spd', 'accel', 'hyst', 'inj',
       'veh', 'baro', 'alt', 'trq', 'batt', 'imt', 'ect', 'aps', 'icp', 'cot', 'mcf', 'cmf', 'vgt', 'pto', 'cc', 'eb', 'jcomm',
       'el', 'tpe', 'chp', 'lsg', 'hsg', 'asg', 'vsg', 'asic', 'sw', 'amb', 'adj', 'frac', 'filt', 'param', 'reg', 'cal_', 'mgr',
       'ctrl', 'cfg', 'buf', 'tbl', 'ms', 'sec', 'tmr', 'cur', 'prev', 'src', 'dst', 'len', 'addr', 'ptr', 'hw', 'sw'}
lines = [json.loads(l) for l in open('/home/linux/.claude/jobs/374b0424/tmp/w15/results/result_W15_bin2.jsonl')]
for r in lines:
    name = r['new'] if r['verdict'] in ('confirmed', 'keep') else r['old']
    toks = name.split('_')
    hits = [t for t in toks if t in BAD]
    if hits and r['verdict'] == 'keep':
        print(r['address'], name, hits)
    if re.search(r'[A-Z]', name):
        print('UPPER', r['address'], name)
print(len(lines), 'lines scanned')
