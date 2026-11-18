import json, sys
sys.path.insert(0, '/home/linux/code/kuminz-re/.claude/worktrees/cm848-typing-arrays/firmware/scripts')
import xref_addr as X
rows = [json.loads(l) for l in open('/home/linux/.claude/jobs/d55ae3c6/tmp/renames/result_W7_vgt_egr.jsonl')]
bad = []
n = 0
for r in rows:
    if r.get('kind') in ('global', 'new_global') and 'Time-shared window' in r.get('evidence', ''):
        a = int(r['address'], 16)
        n += 1
        name, refs = X.referencing_functions(a)
        low = [(hex(s), f) for s, f in refs if s < 0x7F60]
        if low:
            bad.append((r['address'], low))
print('checked', n, 'time-shared rows; users below 0x7F60:', bad)
