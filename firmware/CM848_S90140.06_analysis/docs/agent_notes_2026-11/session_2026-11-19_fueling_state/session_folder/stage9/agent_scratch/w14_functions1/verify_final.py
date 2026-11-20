"""verify_final.py: re-read the final result file and re-check it against the bin and the .cpp."""
import json
import re

FINAL = "/home/linux/.claude/jobs/f6a06670/tmp/fueling_state/stage9/result_W14_functions1.jsonl"
BIN = "/home/linux/.claude/jobs/f6a06670/tmp/fueling_state/stage9/bins/functions1.json"
CPP = "/home/linux/code/kuminz-re/.claude/worktrees/cm848-fueling-state-enum/firmware/CM848_S90140.06_analysis/output/cm848_rom.ghidra.cpp"
items = json.load(open(BIN))["functions"]
rows = [json.loads(l) for l in open(FINAL) if l.strip()]
assert len(rows) == len(items) == 31, (len(rows), len(items))
text = open(CPP).read().split("\n")
starts = [(i, m.group(1)) for i, line in enumerate(text) if (m := re.match(r"^// Function: (\S+) @", line))]
spans = {n: text[i:(starts[k + 1][0] if k + 1 < len(starts) else len(text))] for k, (i, n) in enumerate(starts)}
need = {"kind", "verdict", "address", "old", "new", "evidence", "code_quote", "plate_comment"}
bad = 0
for x, r in zip(items, rows):
    ok = (set(r) == need and r["kind"] == "function" and r["verdict"] == "confirmed" and r["address"] == x["address"]
          and r["old"] == x["current"] and any(r["code_quote"] in l for l in spans[r["old"]]) and "(was" not in r["plate_comment"]
          and r["new"] != r["old"] and "\n" not in r["plate_comment"])
    if not ok:
        bad += 1
        print("BAD", x["address"], x["current"])
print("lines", len(rows), "bad", bad, "distinct new names", len({r["new"] for r in rows}))
verdicts = {}
for r in rows:
    verdicts[r["verdict"]] = verdicts.get(r["verdict"], 0) + 1
print(verdicts)
