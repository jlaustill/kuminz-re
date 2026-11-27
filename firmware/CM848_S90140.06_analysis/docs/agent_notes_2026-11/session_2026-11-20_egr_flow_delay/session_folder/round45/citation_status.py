"""Round 45: for candidate placements (block@address/extent), count the CM848 rows in range and how many already cite the
block ('e2m XXXX'), plus the other e2m blocks their comments cite.  usage: citation_status.py <repo> 8A88@0x409a8a/8 ..."""
import csv
import os
import sys

repo = os.path.abspath(sys.argv[1])
rows = {}
for r in csv.reader(open(os.path.join(repo, "firmware/CM848_S90140.06_analysis/output/global_variables.csv"))):
    if r and r[0].startswith("0x"):
        rows[int(r[0], 16)] = (r[1], r[3] if len(r) > 3 else "")
for item in sys.argv[2:]:
    b, rest = item.split("@")
    a, n = rest.split("/")
    a, n = int(a, 16), int(n)
    rs = [(x, rows[x]) for x in sorted(rows) if a <= x < a + n]
    cited = sum(1 for _, (nm, c) in rs if f"e2m {b}" in c)
    other = sorted({c.split("e2m ")[1][:4] for _, (nm, c) in rs if "e2m " in c and f"e2m {b}" not in c})
    print(f"{b} @ {a:#x}: {len(rs)} rows, {cited} cite {b}; other e2m cites: {other[:6]}")
