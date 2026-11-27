"""check_enum_proof2.py (fueling state session) with one change for byte enums: each listed enum type normalizes to
the base type of its enums.csv size (1 -> byte, 2 -> word, 4 -> dword) instead of always `word`, so a byte global's
local copies compare equal. Every remaining token difference after reverse_names.py must be an enum substitution:
members of the listed enums and numeric literals -> their value; decompiler auto-named locals -> LOCAL<k>.
Usage: check_enum_proof3.py old.cpp reversed_new.cpp enums.csv ENUM[,ENUM...]"""
import csv
import difflib
import re
import sys

old_path, new_path, enums_path, enum_list = sys.argv[1:5]
ENUMS = set(enum_list.split(","))
HEADER = re.compile(r"^// Function: (\S+) @ (0x[0-9a-f]+)$", re.M)
LOCAL = re.compile(r"^(?:[a-zA-Z]{1,3}Var\d+|[a-zA-Z]{1,3}Stack_[0-9a-f]+|local_[0-9a-f]+)$")
NUMBER = re.compile(r"^(?:0x[0-9a-fA-F]+|\d+)$")
BASE = {"1": "byte", "2": "word", "4": "dword"}
values, base_of = {}, {}
for row in csv.reader(line for line in open(enums_path) if not line.startswith("#")):
    if len(row) >= 5 and row[0] in ENUMS:
        values[row[2]] = int(row[1], 0)
        base_of[row[0]] = BASE[row[4]]
assert set(base_of) == ENUMS, ENUMS - set(base_of)


def functions(path):
    parts = HEADER.split(open(path).read())
    return {parts[i]: parts[i + 2] for i in range(1, len(parts), 3)}


def normalize(body):
    out = []
    for t in re.findall(r"\w+|[^\w\s]", body):
        if t in values:
            out.append(f"#V{values[t]}")
        elif NUMBER.match(t):
            out.append(f"#V{int(t, 16) if t.lower().startswith('0x') else int(t, 10)}")
        elif t in base_of:
            out.append(base_of[t])
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
