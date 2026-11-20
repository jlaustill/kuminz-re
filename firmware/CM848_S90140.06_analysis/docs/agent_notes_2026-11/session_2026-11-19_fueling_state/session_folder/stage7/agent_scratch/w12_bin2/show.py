import json
import sys

OUTFILE = "/home/linux/.claude/jobs/f6a06670/tmp/fueling_state/stage7/result_W12_bin2.jsonl"
rows = [json.loads(line) for line in open(OUTFILE)]
lo, hi = int(sys.argv[1]), int(sys.argv[2])
for i in range(lo, min(hi, len(rows))):
    r = rows[i]
    print(f"#{i} {r['address']} {r['verdict']} {r['type']} NEW={r['new']!r}")
    print("  EV:", r["evidence"])
    print("  CM:", r["comment"])
