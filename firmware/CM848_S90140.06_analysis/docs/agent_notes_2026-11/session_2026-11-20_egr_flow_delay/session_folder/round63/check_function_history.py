"""For a function rename map: each row's function_renames.csv entry carries the new name at its address and keeps
"(was <old_label>" in its plate.  usage: check_function_history.py <repo> <map.csv>"""
import csv
import os
import sys

repo, map_path = os.path.abspath(sys.argv[1]), sys.argv[2]
rows = {}
for line in open(os.path.join(repo, "firmware/CM848_S90140.06_analysis/output/function_renames.csv")):
    parts = line.rstrip("\n").split(",", 2)
    if parts[0].startswith("0x"):
        rows[parts[0]] = (parts[1], parts[2] if len(parts) > 2 else "")
bad = 0
for r in csv.DictReader(open(map_path)):
    if r["kind"] != "function":
        continue
    name, plate = rows.get(r["address"], ("(missing)", ""))
    ok = name == r["name"] and f"(was {r['old_label']}" in plate
    bad += not ok
    print(("ok  " if ok else "LOST"), r["address"], r["name"])
print("lost:", bad)
