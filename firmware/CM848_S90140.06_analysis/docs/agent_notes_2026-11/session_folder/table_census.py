"""Census of unnamed lookup tables: region, role, readers; how they group into lookups (call sites)."""
import csv
import sys
from collections import Counter

plan = list(csv.DictReader(open(sys.argv[1])))
unnamed = [r for r in plan if not r["name"]]
print("tables:", len(plan), "unnamed:", len(unnamed))

def region(a):
    if 0x3fd482 <= a <= 0x3feec1:
        return "EEPROM mirror (_cal)"
    if 0x3f9800 <= a < 0x3fdb30:
        return "ROM->RAM window"
    if a >= 0x500000:
        return "bank 2 flash"
    if a < 0x70000:
        return "bank 1 ROM"
    return "other RAM"

print("by region:", Counter(region(int(r["address"], 16)) for r in unnamed))
print("by role:", Counter(r["roles"] for r in unnamed))
readers = Counter(len(r["readers"].split()) for r in unnamed)
print("reader-function count:", sorted(readers.items()))
fns = Counter()
for r in unnamed:
    for f in r["readers"].split():
        fns[f] += 1
print("distinct reader functions:", len(fns))
print("top readers:", fns.most_common(15))
none = [r["address"] for r in unnamed if not r["readers"].strip()]
print("no readers:", len(none), none[:8])
