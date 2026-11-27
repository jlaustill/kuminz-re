"""Check that every enums.csv row carrying a marker parses (quote-aware) into 5 columns with a numeric size.
usage: check_enum_rows.py <enums.csv> <marker>"""
import csv
import sys

bad = total = 0
for line in open(sys.argv[1], newline=""):
    if sys.argv[2] not in line or line.startswith("#"):
        continue
    total += 1
    row = next(csv.reader([line.rstrip("\r\n")]))
    if len(row) != 5 or not row[4].strip().isdigit():
        bad += 1
        print("BAD", row[:3], len(row))
print(total, "rows,", bad, "bad")
