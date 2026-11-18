import csv
import sys

cpp_rows = {int(r["address"], 16): r for r in csv.DictReader(open(sys.argv[1]))}
dis = {}
for r in csv.DictReader(open(sys.argv[2])):
    if r["table"]:
        dis.setdefault(int(r["table"], 16), set()).add(r["callee"] + ":" + r["role"])
cpp, dis_set = set(cpp_rows), set(dis)
print("both:", len(cpp & dis_set), " only .cpp:", len(cpp - dis_set), " only disasm:", len(dis_set - cpp))
names = {}
for line in open(sys.argv[3]):
    p = line.rstrip("\n").split(",", 3)
    if p[0].startswith("0x"):
        names[int(p[0], 16)] = p[1]
print("-- only disasm (first 40):")
for a in sorted(dis_set - cpp)[:40]:
    print(f"  0x{a:08x} {names.get(a, '-'):45s} {' '.join(sorted(dis[a]))}")
print("-- only .cpp (first 25):")
for a in sorted(cpp - dis_set)[:25]:
    r = cpp_rows[a]
    print(f"  {r['address']} {r['name']:45s} {r['users'][:70]}")
