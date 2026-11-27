"""For each CM550 struct whose field rows carry several addresses: its rows, the global row at each field address, and
the global rows typed with the struct (with how often each renders as name.field in the .cpp).
usage: multi_address_detail.py <structure_definitions.csv> <global_variables.csv> <cpp>"""
import collections
import csv
import re
import sys

sd, gv, cpp = sys.argv[1:4]
fields = collections.defaultdict(list)
for row in csv.reader(open(sd, newline="")):
    if row and not row[0].startswith("#") and row[0] != "struct_name" and len(row) > 4 and row[2].strip():
        fields[row[0]].append((row[1].strip().lower(), row[2].strip(), row[3].strip(), row[4].strip()))
globals_at, typed = {}, collections.defaultdict(list)
for line in open(gv, newline=""):
    parts = line.rstrip("\r\n").split(",", 3)
    if len(parts) > 2 and parts[0].startswith("0x"):
        globals_at[parts[0].lower()] = (parts[1], parts[2])
        typed[parts[2]].append((parts[0].lower(), parts[1]))
text = open(cpp, errors="replace").read()
for name in sorted(fields):
    rows = fields[name]
    if len({a for a, *_ in rows if a}) < 2:
        continue
    print(f"== {name} ({sum(int(s) for *_, s in rows if s.isdigit())} bytes)")
    for a, f, t, s in rows:
        g = globals_at.get(a, ("-", "-"))
        print(f"   {a} {f} {t}[{s}]  global: {g[0]} ({g[1] or 'untyped'})")
    for a, g in typed.get(name, []):
        n = len(re.findall(rf"\b{re.escape(g)}\.\w+", text)) if g else 0
        print(f"   typed global {a} {g or '(unnamed)'}: {n} field renders")
