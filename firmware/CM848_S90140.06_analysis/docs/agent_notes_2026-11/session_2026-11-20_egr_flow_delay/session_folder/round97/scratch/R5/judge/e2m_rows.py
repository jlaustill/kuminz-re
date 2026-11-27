"""Resolve the e2m record(s) at each address of family_R5.txt (plus extra addresses given on the command line)."""
import subprocess
import sys

FW = '/home/linux/code/kuminz-re/.claude/worktrees/cm848-egr-flow-delay/firmware'
addresses = []
with open('/home/linux/.claude/jobs/374b0424/tmp/w15/r97/family_R5.txt') as f:
    for line in f:
        if line.strip():
            addresses.append(line.split()[0])
addresses += sys.argv[1:]
for a in addresses:
    out = subprocess.run(['python3', 'scripts/e2m_block_addresses.py', '--firmware', 'cm550', '--address', a],
                         cwd=FW, capture_output=True, text=True).stdout.strip()
    print(f"{a}: {out[:300]}")
