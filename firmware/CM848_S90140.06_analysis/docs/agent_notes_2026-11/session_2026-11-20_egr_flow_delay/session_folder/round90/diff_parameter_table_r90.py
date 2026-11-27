"""Round 90 (read-only): compare a regenerated CM550 parameter ID table CSV with the committed one, per column.
usage: diff_parameter_table_r90.py <committed.csv> <regenerated.csv>"""
import csv
import sys

old = {r["param_id_hex"]: r for r in csv.DictReader(open(sys.argv[1], newline=""))}
new = {r["param_id_hex"]: r for r in csv.DictReader(open(sys.argv[2], newline=""))}
print("ids equal:", set(old) == set(new), len(old), len(new))
for col in ("param_id", "address", "address_hex", "region", "firmware_variable", "e2m_parameter"):
    d = [k for k in old if k in new and old[k][col] != new[k][col]]
    print(f"{col}: {len(d)} differ; e.g. " + "; ".join(f"{k} {old[k][col]!r} -> {new[k][col]!r}" for k in d[:3]))
