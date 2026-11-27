"""usage: others.py addr...  -> what the other bins' agents decided for these addresses (read only)"""
import glob
import json
import sys

want = {a.lower() for a in sys.argv[1:]}
for p in sorted(glob.glob("/home/linux/.claude/jobs/374b0424/tmp/w15/results/result_W15_bin[12356].jsonl")):
    for line in open(p):
        line = line.strip()
        if not line.startswith("{"):
            continue
        try:
            r = json.loads(line)
        except json.JSONDecodeError:
            continue
        a = r.get("address", "").lower()
        if a in want:
            print(p[-11:-6], a, r.get("verdict"), r.get("old"), "->", r.get("new"))
