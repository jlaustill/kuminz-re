import json
import re

CPP = '/home/linux/code/kuminz-re/.claude/worktrees/cm848-egr-flow-delay/firmware/CM848_S90140.06_analysis/output/cm848_rom.ghidra.cpp'
lines = open(CPP).read().split('\n')
starts = [(i, m.group(1)) for i, line in enumerate(lines) if (m := re.match(r'^// Function: (\S+) @', line))]
rng = {n: (i, starts[k + 1][0] if k + 1 < len(starts) else len(lines)) for k, (i, n) in enumerate(starts)}
rows = [json.loads(l) for l in open('/home/linux/.claude/jobs/374b0424/tmp/w15/results/result_W15_bin2.jsonl')]
for r in rows:
    if r['verdict'] != 'confirmed':
        continue
    func, q = r['code_quote'].split(': ', 1)
    s, e = rng[func]
    exact = [n + 1 for n in range(s, e) if lines[n].strip() == q.strip()]
    part = [n + 1 for n in range(s, e) if q.strip() in lines[n]]
    print(r['address'], 'EXACT' if exact else 'PARTIAL', exact or part, '|', q[:90])
