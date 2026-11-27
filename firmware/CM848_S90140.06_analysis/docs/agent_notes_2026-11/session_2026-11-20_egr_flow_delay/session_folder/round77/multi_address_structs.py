"""List the structs in a structure_definitions.csv whose FIELD rows (non-empty field name) carry more than one distinct
address - ApplyStructures builds one type from all of a name's rows, so such a struct becomes one oversize type with an
instance at every listed address (marker rows - empty field name - are the correct way to add instances).
usage: multi_address_structs.py <structure_definitions.csv>"""
import collections
import csv
import sys

fields = collections.defaultdict(list)
markers = collections.defaultdict(list)
for row in csv.reader(open(sys.argv[1], newline="")):
    if not row or row[0].startswith("#") or row[0] == "struct_name":
        continue
    name, address, field = row[0], row[1].strip().lower(), row[2].strip()
    (fields if field else markers)[name].append((address, field, row[4] if len(row) > 4 else ""))
for name in sorted(fields):
    addresses = sorted({a for a, _, _ in fields[name] if a})
    if len(addresses) > 1:
        size = sum(int(s) for _, _, s in fields[name] if s.strip().isdigit())
        print(f"{name}: {len(fields[name])} field rows at {len(addresses)} addresses ({addresses[0]} .. {addresses[-1]}), "
              f"type size {size}, markers {len(markers[name])}")
