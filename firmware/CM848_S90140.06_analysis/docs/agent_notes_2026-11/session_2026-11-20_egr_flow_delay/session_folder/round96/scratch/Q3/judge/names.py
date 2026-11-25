"""usage: names.py <firmware cm550|cm848> <hex addr>... : print the function_renames row (name, first 160 chars of comment)"""
import csv
import sys

fw = sys.argv[1]
path = f"/home/linux/.claude/jobs/374b0424/tmp/w15/r96/frozen/{fw}/function_renames.csv"
rows = {}
with open(path, newline="", errors="replace") as f:
    for r in csv.reader(f):
        if not r or not r[0].startswith("0x"):
            continue
        try:
            rows[int(r[0], 16)] = r
        except ValueError:
            pass
width = int(sys.argv[2]) if sys.argv[2].isdigit() and len(sys.argv[2]) < 4 else 160
args = sys.argv[3:] if width != 160 or (sys.argv[2].isdigit() and len(sys.argv[2]) < 4) else sys.argv[2:]
for a in args:
    v = int(a, 16)
    r = rows.get(v)
    if r:
        print(f"0x{v:x} {r[1]} | {(r[2] if len(r) > 2 else '')[:width]}")
    else:
        print(f"0x{v:x} (no row)")
