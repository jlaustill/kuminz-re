"""Read-only: print the frozen CM550 (or CM848 with --cm848) global rows in [start, end).
usage: rows.py [--cm848] <start hex> <end hex> [width]"""
import csv
import sys

args = sys.argv[1:]
fw = "cm550"
if args and args[0] == "--cm848":
    fw = "cm848"
    args = args[1:]
start, end = int(args[0], 16), int(args[1], 16)
width = int(args[2]) if len(args) > 2 else 300
path = f"/home/linux/.claude/jobs/374b0424/tmp/w15/r95/frozen/{fw}/global_variables.csv"
for row in csv.reader(open(path)):
    if not row or not row[0].startswith("0x"):
        continue
    a = int(row[0], 16)
    if start <= a < end:
        print((",".join(row))[:width])
