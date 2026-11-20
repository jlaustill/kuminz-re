"""Dry run of the repo gate (apply_renames.py, no --apply, no --out) on my confirmed global renames, input kept in /tmp/w14_globals3."""
import json
import subprocess
import sys

REPO = '/home/linux/code/kuminz-re/.claude/worktrees/cm848-fueling-state-enum/'
OUT = REPO + 'firmware/CM848_S90140.06_analysis/output'
RESULT = '/home/linux/.claude/jobs/f6a06670/tmp/fueling_state/stage9/result_W14_globals3.jsonl'
GATE_INPUT = '/tmp/w14_globals3/gate_input_globals3.jsonl'
n = 0
with open(GATE_INPUT, 'w') as f:
    for line in open(RESULT):
        r = json.loads(line)
        if r['verdict'] == 'confirmed':
            n += 1
            f.write(json.dumps({'kind': 'global', 'verdict': 'confirmed', 'address': r['address'], 'old': r['old'], 'new': r['new'],
                                'evidence': r.get('comment') or r.get('evidence', '')}) + '\n')
done = subprocess.run([sys.executable, REPO + 'firmware/scripts/rename_waves/apply_renames.py', OUT, GATE_INPUT],
                      capture_output=True, text=True)
print(n, 'renames fed to the gate')
print(done.stdout.strip())
print(done.stderr.strip()[-500:])
