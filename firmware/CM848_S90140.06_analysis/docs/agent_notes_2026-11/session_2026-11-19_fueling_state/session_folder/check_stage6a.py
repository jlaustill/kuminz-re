"""Stage 6a check: after reverse_names.py (new names back to old labels), map each ema_filter_state_t field access back to
the flat form it replaced and drop pointer casts, then list the functions that still differ.
- `<old record label>.coefficient` -> `<old record label>` (the pointer row);
- `<old record label>.accumulator` -> the removed +4 row as it rendered (`_name` when the row was narrower than the
  dword the code stores, otherwise `name`);
- `(undefined *)` / `(word *)` / `(ema_filter_state_t *)` / `(undefined4 *)` casts removed on both sides.
usage: check_stage6a.py pre_canon.cpp reversed.cpp map_stage6a.csv stage6a_removed_rows.txt apply_stage6a_filter_records.py"""
import csv
import re
import sys

old_path, new_path, map_path, removed_path, apply_path = sys.argv[1:6]
HEADER = re.compile(r"^// Function: (\S+) @ (0x[0-9a-f]+)$", re.M)
new_to_old = {r["name"]: r["old_label"] for r in csv.DictReader(open(map_path))}
ns = {"__name__": "definitions", "__file__": apply_path, "sys": sys}
import os  # noqa: E402
ns["os"] = os
exec(open(apply_path).read().split("def value_text(v):")[0].replace("OUT = sys.argv[1]", "OUT = None"), ns)
removed = {}
for line in open(removed_path):
    if line.strip():
        address, name, typ = line.strip().split(",")[:3]
        removed[int(address, 16)] = (name, typ)
fields = {}
for address, old, new, _function, _what in ns["RECORDS"]:
    base = int(address, 16)
    label = new_to_old.get(new, new) if new else f"ema_filter_state_t_{base:08x}"
    pointer = old or f"PTR_DAT_{base:08x}"
    accumulator = removed.get(base + 4)
    accumulator_label = None
    if accumulator:
        accumulator_label = accumulator[0] if accumulator[1] == "dword" else "_" + accumulator[0]
    fields[label] = (pointer, accumulator_label)


def split(path):
    parts = HEADER.split(open(path).read())
    return {parts[i + 1]: parts[i + 2] for i in range(1, len(parts), 3)}


CAST = re.compile(r"\((?:undefined|word|ema_filter_state_t|undefined4)\s*\*\)\s*")


def normalize(text, mapping):
    for label, (pointer, accumulator) in mapping.items():
        text = re.sub(r"\b" + re.escape(label) + r"\.coefficient\b", pointer, text)
        if accumulator:
            text = re.sub(r"\b" + re.escape(label) + r"\.accumulator\b", accumulator, text)
    text = CAST.sub("", text)
    return re.sub(r"\s+", "", text)


old, new = split(old_path), split(new_path)
differ = [name for name in old if name in new and normalize(old[name], {}) != normalize(new[name], fields)]
print(f"{len(differ)} functions still differ after mapping the field accesses back:")
for name in differ:
    print("  " + name)
