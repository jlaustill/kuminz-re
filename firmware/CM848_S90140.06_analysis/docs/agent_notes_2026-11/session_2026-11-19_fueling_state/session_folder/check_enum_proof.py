"""Stricter proof for the FUELING_STATE change: after reverse_names.py, every remaining token difference must be one
of the changes the typing is expected to make. Normalizes, on both sides:
  - enum member names -> their value, numeric literals -> their value (so `0xb` == FUELING_STATE_LOW_SPEED_GOVERNOR);
  - the enum type names -> `word` (a local that took the enum type);
  - decompiler auto-named locals (wVar1, FVar1, uStack_e...) -> LOCAL<k> by first appearance in the function;
  - the split dword: `governor_pid_integral_working . _0_2_` -> the word itself, `... . _2_2_` ->
    fuel_demand_enable_sync_flag_shadow.
Prints each function that still differs, with its token-diff chunks, for review.
Usage: check_enum_proof.py pre_canon.cpp reversed.cpp enums.csv"""
import csv
import difflib
import re
import sys

old_path, new_path, enums_path = sys.argv[1:4]
HEADER = re.compile(r"^// Function: (\S+) @ (0x[0-9a-f]+)$", re.M)
LOCAL = re.compile(r"^(?:[a-zA-Z]{1,3}Var\d+|[a-zA-Z]{1,3}Stack_[0-9a-f]+|local_[0-9a-f]+)$")
NUMBER = re.compile(r"^(?:0x[0-9a-fA-F]+|\d+)$")

values = {}
for row in csv.reader(line for line in open(enums_path) if not line.startswith("#")):
    if len(row) >= 3 and row[0] == "FUELING_STATE":
        values[row[2]] = int(row[1], 0)
        values[row[2].replace("FUELING_STATE_", "ENGINE_OPERATING_MODE_")] = int(row[1], 0)   # reversed old names
ENUM_TYPES = {"FUELING_STATE", "ENGINE_OPERATING_MODE"}


def functions(path):
    parts = HEADER.split(open(path).read())
    return {parts[i]: parts[i + 2] for i in range(1, len(parts), 3)}


def normalize(body):
    tokens = re.findall(r"\w+|[^\w\s]", body)
    out, i = [], 0
    while i < len(tokens):
        t = tokens[i]
        if t == "governor_pid_integral_working" and tokens[i + 1:i + 3] in (([".", "_0_2_"]), [".", "_2_2_"]):
            out.append("governor_pid_integral_working" if tokens[i + 2] == "_0_2_" else
                       "fuel_demand_enable_sync_flag_shadow")
            i += 3
            continue
        if t in values:
            out.append(f"#V{values[t]}")
        elif NUMBER.match(t):
            out.append(f"#V{int(t, 0)}")
        elif t in ENUM_TYPES:
            out.append("word")
        else:
            out.append(t)
        i += 1
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
print(f"{still} function(s) still differ after normalizing enum substitution / local types / the dword split")
