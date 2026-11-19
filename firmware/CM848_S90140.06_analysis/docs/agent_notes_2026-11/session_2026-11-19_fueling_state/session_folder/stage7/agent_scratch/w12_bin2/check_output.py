import json

OUTFILE = "/home/linux/.claude/jobs/f6a06670/tmp/fueling_state/stage7/result_W12_bin2.jsonl"
rows = [json.loads(line) for line in open(OUTFILE)]
print(len(rows), "rows")
for i, r in enumerate(rows):
    c = len(r["comment"])
    flag = "  <-- over 400" if c > 400 else ""
    if flag or "--all" in __import__("sys").argv:
        print(f"#{i} {r['address']} {r['verdict']:9s} {r['type']:5s} {r['new']:70s} comment {c} evidence {len(r['evidence'])}{flag}")
