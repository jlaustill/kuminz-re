#!/bin/sh
# resolve the 50 family rows to their e2m records
cd /home/linux/code/kuminz-re/.claude/worktrees/cm848-egr-flow-delay/firmware || exit 1
for a in $(awk '{print $1}' /home/linux/.claude/jobs/374b0424/tmp/w15/r97/family_R5.txt); do
  python3 scripts/e2m_block_addresses.py --firmware cm550 --address "$a" 2>&1 | head -3
done
