"""Per renamed global, the functions that use it outside the verified (renamed) functions, ranked."""
import csv
import re
import sys

cpp, mapping = sys.argv[1:3]
rows = list(csv.DictReader(open(mapping)))
verified = {r["name"] for r in rows if r["kind"] == "function"}
globals_ = [r for r in rows if r["kind"] == "global"]
HEADER = re.compile(r"^// Function: (\S+) @ (0x[0-9a-f]+)$", re.M)
parts = HEADER.split(open(cpp).read())
bodies = {parts[i]: parts[i + 2] for i in range(1, len(parts), 3)}
ranked = []
for g in globals_:
    pat = re.compile(rf"\b_?{re.escape(g['name'])}\b")
    users = [f for f, b in bodies.items() if pat.search(re.sub(r"/\*.*?\*/", "", b, flags=re.S))]
    outside = [f for f in users if f not in verified]
    ranked.append((len(outside), g["name"], g["address"], outside))
ranked.sort(reverse=True)
print("globals used only inside verified functions:", sum(1 for r in ranked if r[0] == 0), "of", len(ranked))
for n, name, a, outside in ranked[:25]:
    print(f"{n:3d} {name} ({a}): {' '.join(outside[:6])}{' ...' if n > 6 else ''}")
