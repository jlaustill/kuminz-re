"""For every address of bin1 run e2m_block_addresses.py --address and print the addresses that resolve to more than
one e2m record (a collision between two blocks)."""
import json
import subprocess

FW = '/home/linux/code/kuminz-re/.claude/worktrees/cm848-egr-flow-delay/firmware'
d = json.load(open('/home/linux/.claude/jobs/374b0424/tmp/w15/bins/bin1.json'))
for r in d:
    out = subprocess.run(['python3', FW + '/scripts/e2m_block_addresses.py', '--address', r['address']],
                         capture_output=True, text=True, cwd=FW).stdout.strip().split('\n')
    out = [l for l in out if l.strip()]
    if len(out) != 1:
        print(r['address'], r['record'], '->', len(out))
        for l in out:
            print('    ', l[:200])
print('checked', len(d))
