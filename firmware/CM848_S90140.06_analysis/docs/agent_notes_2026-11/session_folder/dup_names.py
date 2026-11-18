import csv
import sys
from collections import defaultdict

globals_csv, tables_csv = sys.argv[1], sys.argv[2]
addresses_by_name = defaultdict(list)
with open(globals_csv) as f:
    for line in f:
        parts = line.rstrip("\n").split(",", 3)
        if parts[0].startswith("0x") and len(parts) > 1 and parts[1]:
            addresses_by_name[parts[1]].append(parts[0])
duplicates = {k: v for k, v in addresses_by_name.items() if len(v) > 1}
print(len(duplicates), "duplicate names in", globals_csv)
table_names = {r["name"] for r in csv.DictReader(open(tables_csv))}
hits = {k: v for k, v in duplicates.items() if k in table_names}
print("used as table arguments:", len(hits))
for name, addrs in sorted(hits.items()):
    print("  ", name, addrs)
