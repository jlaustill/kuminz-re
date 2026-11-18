"""Find every rendered use of a newly named table outside an interpolator call the agents saw: lines that
mention the name in a function whose calls did not include that table. Usage: unseen_uses.py <cpp> <tables_dir>
<mapping.csv>..."""
import csv
import json
import re
import sys

cpp, tables = sys.argv[1], sys.argv[2]
names = {}
for m in sys.argv[3:]:
    for r in csv.DictReader(open(m)):
        names[r["name"]] = int(r["address"], 16)
lookups = json.load(open(f"{tables}/lookups.json"))
seen = {}
for lk in lookups:
    for t in lk["tables"]:
        if t.get("address"):
            for c in lk["calls"]:
                seen.setdefault(int(t["address"], 16), set()).add(c["function"])
HEADER = re.compile(r"^// Function: (\S+) @ (0x[0-9a-f]+)$", re.M)
parts = HEADER.split(open(cpp).read())
pattern = re.compile(r"\b(" + "|".join(sorted(map(re.escape, names), key=len, reverse=True)) + r")\b")
extra = []
for i in range(1, len(parts), 3):
    fn, body = parts[i], parts[i + 2]
    for line in body.split("\n"):
        if line.lstrip().startswith(("//", "/*", "*")):
            continue
        for m in pattern.finditer(line):
            a = names[m.group(1)]
            if fn not in seen.get(a, set()):
                extra.append((fn, m.group(1), line.strip()[:150]))
print(f"uses outside the lookups the agents saw: {len(extra)}")
for fn, n, line in extra[:40]:
    print(f"  {fn}: {n}\n      {line}")
