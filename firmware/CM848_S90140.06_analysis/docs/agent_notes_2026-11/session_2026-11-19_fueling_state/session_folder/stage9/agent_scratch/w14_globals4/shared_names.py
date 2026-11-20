"""Which of my old global names also appear in CM550's CSVs or the cross-firmware variable map?"""
import json
import re

REPO = "/home/linux/code/kuminz-re/.claude/worktrees/cm848-fueling-state-enum"
files = [REPO + "/firmware/CM550_J90350.00_analysis/output/global_variables.csv",
         REPO + "/firmware/CM550_J90350.00_analysis/output/function_renames.csv",
         REPO + "/docs/cross_firmware_variable_map.csv",
         REPO + "/firmware/cross_firmware_matches.csv"]
texts = {}
for f in files:
    try:
        texts[f.split("/")[-1]] = open(f, errors="replace").read()
    except OSError as e:
        print("missing", f, e)
rows = [json.loads(l) for l in open("/home/linux/.claude/jobs/f6a06670/tmp/fueling_state/stage9/result_W14_globals4.jsonl")]
hits = 0
for r in rows:
    for name in (r["old"],):
        for fn, text in texts.items():
            if re.search(rf"(?<![A-Za-z0-9_]){re.escape(name)}(?![A-Za-z0-9_])", text):
                hits += 1
                print("SHARED", r["address"], name, "in", fn, "| verdict", r["verdict"], "->", r.get("new"))
print("hits:", hits)
