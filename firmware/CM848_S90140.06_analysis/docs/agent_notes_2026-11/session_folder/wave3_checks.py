"""Wave-3 post-checks. Usage: wave3_checks.py <tmp> <fw output dir> <cm550 output dir>"""
import csv
import re
import sys
from collections import Counter

tmp, out, cm550 = sys.argv[1:4]
cpp = open(f"{out}/cm848_rom.ghidra.cpp").read()
gv = [l.rstrip("\n").split(",", 3) for l in open(f"{out}/global_variables.csv") if l.startswith("0x")]
SIZE = {"byte": 1, "i8": 1, "word": 2, "i16": 2, "dword": 4, "i32": 4, "pointer": 4, "float": 4}
structs = Counter()
for l in open(f"{out}/structure_definitions.csv"):
    p = next(csv.reader([l]))
    if len(p) > 4 and p[0] and not p[0].startswith("#") and p[4].strip().isdigit():
        structs[p[0]] += int(p[4])


def size(t):
    t = t.strip()
    m = re.fullmatch(r"(\w+)\[(\d+)\]", t)
    if m:
        return size(m.group(1)) * int(m.group(2))
    return SIZE.get(t, structs.get(t, 0))


spans = [(int(p[0], 16), size(p[2] if len(p) > 2 else ""), p[1]) for p in gv]
arrays = [(int(l.split(",")[0], 16), int(l.split(",")[3] or 0) * SIZE.get(l.split(",")[2], 1), l.split(",")[1])
          for l in open(f"{out}/arrays.csv") if l.startswith("0x") and len(l.split(",")) > 3 and l.split(",")[3].strip().isdigit()]
new_rows = list(csv.DictReader(open(f"{tmp}/renames/mapping_w3_newrows.csv")))
print("== new rows that do not render:")
for r in new_rows:
    if not re.search(rf"\b_?{re.escape(r['name'])}\b", cpp):
        print("  ", r["address"], r["name"])
print("== new-row spans overlapping another typed row / array:")
by_addr = {int(p[0], 16): p for p in gv}
for r in new_rows:
    a = int(r["address"], 16)
    s = size(by_addr[a][2])
    for b, n, name in spans + arrays:
        if b != a and n and (b < a + s and a < b + n) and name != r["name"]:
            print(f"   {r['address']} {r['name']} ({s}) overlaps 0x{b:08x} {name} ({n})")
print("== renamed globals in the ROM-to-RAM window used by boot-ROM functions (< 0x7f60):")
HEADER = re.compile(r"^// Function: (\S+) @ (0x[0-9a-f]+)$", re.M)
parts = HEADER.split(cpp)
bodies = [(parts[i], int(parts[i + 1], 16), re.sub(r"/\*.*?\*/", "", parts[i + 2], flags=re.S)) for i in range(1, len(parts), 3)]
for r in csv.DictReader(open(f"{tmp}/renames/mapping_w3_renames.csv")):
    if r["kind"] != "global" or not (0x3F9800 <= int(r["address"], 16) < 0x3FDB30):
        continue
    pat = re.compile(rf"\b_?{re.escape(r['name'])}\b")
    boot = [f for f, a, b in bodies if a < 0x7F60 and pat.search(b)]
    if boot:
        print(f"   {r['address']} {r['name']}: {' '.join(boot[:4])}")
print("== member-label rows ending in an old field name of a renamed struct field:")
fields = [(r["name"], r["old_label"]) for r in csv.DictReader(open(f"{tmp}/renames/mapping_w3_extras.csv")) if r["kind"] == "field"]
for p in gv:
    if "." in p[1]:
        for n, o in fields:
            if p[1].endswith("." + o) and ("fault_entr" in p[1] or "wastegate" in p[1] or "rpm_governor" in p[1]):
                print("  ", p[0], p[1])
print("== duplicate names now:")
print("   globals:", [n for n, c in Counter(p[1] for p in gv if p[1]).items() if c > 1])
fr = [l.rstrip("\n").split(",", 2)[1] for l in open(f"{out}/function_renames.csv") if l.startswith("0x")]
print("   functions:", [n for n, c in Counter(fr).items() if c > 1])
print("== wave-3 old names that CM550 also uses:")
cm = set()
for name in ("global_variables.csv", "function_renames.csv"):
    for l in open(f"{cm550}/{name}"):
        p = l.rstrip("\n").split(",")
        if p[0].startswith("0x") and len(p) > 1:
            cm.add(p[1])
olds = {r["old_label"] for r in csv.DictReader(open(f"{tmp}/renames/mapping_w3_renames.csv"))}
print("  ", sorted(olds & cm))
