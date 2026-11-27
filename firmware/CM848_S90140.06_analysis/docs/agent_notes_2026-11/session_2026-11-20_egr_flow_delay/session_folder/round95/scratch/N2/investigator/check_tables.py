"""Read-only: for every proposed table, the gap to the next e2m record vs the proposed size, and the absolute
references (abs_refs.py) to the rows that lie inside it."""
import json
import re
import subprocess

D = "/home/linux/.claude/jobs/374b0424/tmp/w15/r95/scratch/N2/investigator/"
REPO = "/home/linux/code/kuminz-re/.claude/worktrees/cm848-egr-flow-delay"
d = json.load(open(D + "proposals.json"))
tables = d["tables"]
addrs = [t["address"] for t in tables]
res = subprocess.run(["python3", D + "next_record.py"] + addrs, capture_output=True, text=True).stdout.strip().split("\n")
nxt = {}
for line in res:
    a = int(line.split(":")[0], 16)
    m = re.search(r"next (0x[0-9a-f]+) (\S+) .*?-> (\d+) bytes", line)
    here = re.search(r"here \[(.*?)\]", line).group(1)
    nxt[a] = (int(m.group(3)), m.group(2), m.group(1), here)
for t in tables:
    a = int(t["address"], 16)
    size = int(re.search(r"\[(\d+)\]", t["type"]).group(1)) * 2
    gap, nname, naddr, here = nxt[a]
    flag = "OK" if gap == size else ("GAP>" if gap > size else "OVERLAP")
    print(f"{flag:7} {t['address']} {t['name']} {t['type']} ({size} bytes) next e2m {nname} at {naddr} (+{gap}); here {here}")
    for r in t["inside"]:
        ra = r.split()[0]
        out = subprocess.run(["python3", "/home/linux/.claude/jobs/374b0424/tmp/w15/r93/tools/abs_refs.py", REPO, ra],
                             capture_output=True, text=True).stdout.strip().split("\n")
        refs = [ln.strip() for ln in out[1:]]
        print(f"          inside {r}: {len(refs)} abs refs {'; '.join(x[:60] for x in refs[:3])}")
