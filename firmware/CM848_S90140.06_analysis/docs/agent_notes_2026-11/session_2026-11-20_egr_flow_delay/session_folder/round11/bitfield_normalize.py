"""Proof helper for new bitfield structs and enums: in the new .cpp, rewrite each `<instance>.<field>` as
`(<instance> & 0xMM)` (masks from a JSON {instance: {field: mask}}) and each member of the listed enums as its value,
so cast_normalized_diff.py can compare the result with the old .cpp. A bitfield test `x.f != 0` becomes
`(x & 0xMM) != 0`, the old form; `(byte)x & m` (a bit value) is unchanged by the type.
usage: bitfield_normalize.py <new.cpp> <out.cpp> <masks.json> <enums.csv> [ENUM,...]"""
import csv
import json
import re
import sys

new_path, out_path, masks_path, enums_path = sys.argv[1:5]
enum_names = set(sys.argv[5].split(",")) if len(sys.argv) > 5 else set()
masks = json.load(open(masks_path))
text = open(new_path).read()
counts = {}
for instance, fields in masks.items():
    for field, mask in fields.items():
        pattern = re.compile(r"(?<![A-Za-z0-9_])" + re.escape(instance) + r"\." + re.escape(field) + r"(?![A-Za-z0-9_])")
        text, n = pattern.subn(f"({instance} & 0x{mask:x})", text)
        counts[f"{instance}.{field}"] = n
members = {}
for r in csv.reader(open(enums_path)):
    if r and r[0] in enum_names:
        members[r[2]] = r[1]
for name, value in members.items():
    text, n = re.subn(r"(?<![A-Za-z0-9_])" + re.escape(name) + r"(?![A-Za-z0-9_])", value, text)
    counts[name] = n
open(out_path, "w").write(text)
left = {i: len(re.findall(r"(?<![A-Za-z0-9_])" + re.escape(i) + r"\.[a-z_0-9]+", text)) for i in masks}
print("replaced:", {k: v for k, v in counts.items() if v}, "| unreplaced field uses left:", left)
