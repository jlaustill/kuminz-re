#!/bin/bash
# Round 97: firmware/CLAUDE.md's line changes per stage (from the snapshots taken before each stage).
W=/home/linux/.claude/jobs/374b0424/tmp/w15/r97
C=/home/linux/code/kuminz-re/.claude/worktrees/cm848-egr-flow-delay/firmware/CLAUDE.md
OUT=$W/claude_md_changes_r97.txt
{
  echo "== stage A"; diff "$W/firmware_CLAUDE_before_r97a.md" "$W/firmware_CLAUDE_before_r97c.md"
  echo "== stage C"; diff "$W/firmware_CLAUDE_before_r97c.md" "$W/firmware_CLAUDE_before_r97d.md"
  echo "== stage D"; diff "$W/firmware_CLAUDE_before_r97d.md" "$C"
} > "$OUT"
grep "^== \|^[0-9]" "$OUT"
