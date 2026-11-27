"""Scratch: size of globals_out.json and a few samples."""
import json
import sys

d = json.load(open("/home/linux/.claude/jobs/374b0424/tmp/w15/r95/scratch/N2/investigator/globals_out.json"))
print(sum(len(json.dumps(e)) for e in d), "chars total")
for i in [int(x) for x in sys.argv[1:]]:
    print(json.dumps(d[i]))
    print()
