"""Read-only: absolute references to every record's +0 / +2 / +4 / +6 / +8 / +0xa / +0xc, to confirm each access
fits the 14-byte layout (and that nothing writes the no_interpolation_flag)."""
import json
import subprocess

D = "/home/linux/.claude/jobs/374b0424/tmp/w15/r95/scratch/N2/investigator/"
REPO = "/home/linux/code/kuminz-re/.claude/worktrees/cm848-egr-flow-delay"
d = json.load(open(D + "proposals.json"))
for r in d["records"]:
    rec = int(r["address"], 16)
    fields = [hex(rec + k) for k in (0, 2, 4, 6, 8, 10, 12)]
    out = subprocess.run(["python3", "/home/linux/.claude/jobs/374b0424/tmp/w15/r93/tools/abs_refs.py", REPO] + fields,
                         capture_output=True, text=True).stdout.strip().split("\n")
    cur = None
    summary = {}
    for ln in out:
        if ln.startswith("=="):
            cur = int(ln.split()[1], 16) - rec
            summary[cur] = []
        elif ln.strip():
            summary[cur].append(ln.strip().split(":")[0])
    print(r["address"], r["name"], " ".join(f"+{k}:{len(v)}" for k, v in summary.items()),
          "FLAG REFS " + ",".join(summary.get(12, [])) if summary.get(12) else "")
