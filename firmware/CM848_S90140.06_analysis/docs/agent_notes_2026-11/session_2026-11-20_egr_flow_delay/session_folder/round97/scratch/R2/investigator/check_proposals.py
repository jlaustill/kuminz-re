"""Check proposals.tsv: every family_R2 row covered once, names unique within the proposals and not already used by
another CM550 row (or used only by the row itself), and say which names exist in CM848 (and at what address).
usage: check_proposals.py"""
import csv
import collections

BASE = "/home/linux/.claude/jobs/374b0424/tmp/w15/r97"
props = [line.rstrip("\n").split("\t") for line in open(f"{BASE}/scratch/R2/investigator/proposals.tsv") if line.strip()]
family = [line.split()[0] for line in open(f"{BASE}/family_R2.txt") if line.strip()]


def load(path):
    rows = {}
    with open(path, newline="") as handle:
        for row in csv.reader(handle):
            if row and row[0].startswith("0x"):
                rows[int(row[0], 16)] = row
    return rows


cm550 = load(f"{BASE}/frozen/cm550/global_variables.csv")
cm848 = load(f"{BASE}/frozen/cm848/global_variables.csv")
cm550_by_name = collections.defaultdict(list)
for address, row in cm550.items():
    cm550_by_name[row[1]].append(address)
cm848_by_name = collections.defaultdict(list)
for address, row in cm848.items():
    cm848_by_name[row[1]].append(address)

addresses = [int(p[0], 16) for p in props]
names = [p[1] for p in props]
print("proposals:", len(props))
missing = [a for a in family if int(a, 16) not in addresses]
print("family rows missing:", missing)
dup_addr = [a for a, c in collections.Counter(addresses).items() if c > 1]
print("duplicate addresses:", [hex(a) for a in dup_addr])
dup_name = [n for n, c in collections.Counter(names).items() if c > 1]
print("duplicate names:", dup_name)
for address, name, _type in props:
    a = int(address, 16)
    users = [u for u in cm550_by_name.get(name, []) if u != a]
    if users:
        print("COLLISION in CM550:", name, [hex(u) for u in users])
    in848 = cm848_by_name.get(name)
    flag = "new" if a not in cm550 else "row"
    print(f"{address} {flag:3} {name:70} cm848={[hex(x) for x in in848] if in848 else '-'}")
