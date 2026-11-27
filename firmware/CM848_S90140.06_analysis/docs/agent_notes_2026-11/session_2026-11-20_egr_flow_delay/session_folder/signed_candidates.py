"""Signedness sweep candidates: named word rows (not inside a struct / array) whose table-resolved e2m record is a
signed 2-byte value. Usage: signed_candidates.py <audit.csv> [--list]"""
import csv
import sys

rows = list(csv.DictReader(open(sys.argv[1])))
c = [r for r in rows if r["status"] == "named" and r["row_type"] == "word" and r["signed"] == "S" and r["size"] == "2"
     and not r["inside"]]
print("word rows with a signed 2-byte e2m record:", len(c))
print("with references > 0:", sum(1 for r in c if r["references"] not in ("", "0")))
if "--list" in sys.argv:
    for r in c:
        print(r["address"], r["row_name"], r["block"], r["offset"], r["record"], r["references"])
