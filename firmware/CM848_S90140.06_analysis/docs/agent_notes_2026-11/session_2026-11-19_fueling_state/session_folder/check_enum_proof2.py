"""check_enum_proof.py generalised (stage 4): after reverse_names.py every remaining token difference must be an enum
substitution or a local-variable effect of the typing. Normalizes, on both sides: the members of the listed enums (new
names and, from the proof map, the old member names they replaced) and numeric literals -> their value; the enum type
names -> `word`; decompiler auto-named locals -> LOCAL<k> by first appearance.
Usage: check_enum_proof2.py pre_canon.cpp reversed.cpp enums.csv proof_map.csv ENUM[,ENUM...]"""
import csv
import difflib
import re
import sys

old_path, new_path, enums_path, map_path, enum_list = sys.argv[1:6]
ENUMS = set(enum_list.split(","))
HEADER = re.compile(r"^// Function: (\S+) @ (0x[0-9a-f]+)$", re.M)
LOCAL = re.compile(r"^(?:[a-zA-Z]{1,3}Var\d+|[a-zA-Z]{1,3}Stack_[0-9a-f]+|local_[0-9a-f]+)$")
NUMBER = re.compile(r"^(?:0x[0-9a-fA-F]+|\d+)$")

values = {}
for row in csv.reader(line for line in open(enums_path) if not line.startswith("#")):
    if len(row) >= 3 and row[0] in ENUMS:
        values[row[2]] = int(row[1], 0)
enum_types = set(ENUMS)
for r in csv.DictReader(open(map_path)):
    if r["kind"] == "enum member" and r["name"] in values:
        values[r["old_label"]] = values[r["name"]]
    elif r["kind"] == "enum":
        enum_types.add(r["old_label"])


def functions(path):
    parts = HEADER.split(open(path).read())
    return {parts[i]: parts[i + 2] for i in range(1, len(parts), 3)}


def normalize(body):
    out = []
    for t in re.findall(r"\w+|[^\w\s]", body):
        if t in values:
            out.append(f"#V{values[t]}")
        elif NUMBER.match(t):
            out.append(f"#V{int(t, 0)}")
        elif t in enum_types:
            out.append("word")
        else:
            out.append(t)
    seen = {}
    return [seen.setdefault(t, f"LOCAL{len(seen)}") if LOCAL.match(t) else t for t in out]


old, new = functions(old_path), functions(new_path)
assert old.keys() == new.keys(), "function sets differ"
still = 0
for name in old:
    a, b = normalize(old[name]), normalize(new[name])
    if a == b:
        continue
    still += 1
    print(f"=== {name}")
    for op, i1, i2, j1, j2 in difflib.SequenceMatcher(None, a, b, autojunk=False).get_opcodes():
        if op != "equal":
            print(f"   {op}: - {' '.join(a[max(i1 - 4, 0):i2 + 2])}\n          + {' '.join(b[max(j1 - 4, 0):j2 + 2])}")
print(f"{still} function(s) still differ after normalizing {sorted(ENUMS)} substitution and local types")
