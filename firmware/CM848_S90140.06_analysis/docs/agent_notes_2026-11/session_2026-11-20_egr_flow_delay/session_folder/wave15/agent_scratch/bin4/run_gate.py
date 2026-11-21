"""Build a gate input from my result file and run the repo gate (apply_renames.py, dry: no --apply, no --out)."""
import json
import subprocess
import sys

RESULT = "/home/linux/.claude/jobs/374b0424/tmp/w15/results/result_W15_bin4.jsonl"
GATE_IN = "/home/linux/.claude/jobs/374b0424/tmp/w15/agent_scratch/bin4/gate_input.jsonl"
REPO = "/home/linux/code/kuminz-re/.claude/worktrees/cm848-egr-flow-delay/firmware/"
n = 0
with open(GATE_IN, "w") as f:
    for line in open(RESULT):
        r = json.loads(line)
        if r["verdict"] == "confirmed":
            f.write(json.dumps({"kind": "global", "verdict": "confirmed", "address": r["address"], "old": r["old"],
                                "new": r["new"], "evidence": r["comment"]}) + "\n")
            n += 1
done = subprocess.run([sys.executable, REPO + "scripts/rename_waves/apply_renames.py",
                       REPO + "CM848_S90140.06_analysis/output", GATE_IN], capture_output=True, text=True)
print(f"{n} renames to the gate")
print(done.stdout.strip())
print(done.stderr.strip()[-500:])
