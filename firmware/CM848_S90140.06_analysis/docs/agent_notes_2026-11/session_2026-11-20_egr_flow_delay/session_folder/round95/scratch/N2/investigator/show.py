"""Scratch: print globals_out.json entries [start, end) one JSON object per line."""
import json
import sys

d = json.load(open("/home/linux/.claude/jobs/374b0424/tmp/w15/r95/scratch/N2/investigator/globals_out.json"))
a, b = int(sys.argv[1]), int(sys.argv[2])
for e in d[a:b]:
    print(json.dumps(e, ensure_ascii=False) + ",")
