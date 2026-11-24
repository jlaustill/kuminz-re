"""Round 90 (read-only): the global_variables.csv rows whose text changed although stage C did not apply / remove them
(the refresh's comment edits), with the changed words. usage: show_refreshed_r90c.py <old.csv> <new.csv> <map.csv>"""
import csv
import difflib
import sys

old = {r[0]: ",".join(r) for r in csv.reader(open(sys.argv[1], newline="")) if r and r[0].startswith("0x")}
new = {r[0]: ",".join(r) for r in csv.reader(open(sys.argv[2], newline="")) if r and r[0].startswith("0x")}
mapped = {r[0].lower() for r in csv.reader(open(sys.argv[3], newline="")) if r and r[0].startswith("0x")}
for a in sorted(set(old) & set(new)):
    if old[a] != new[a] and a.lower() not in mapped:
        sm = difflib.SequenceMatcher(None, old[a], new[a])
        changes = [f"{old[a][i1:i2]!r} -> {new[a][j1:j2]!r}" for op, i1, i2, j1, j2 in sm.get_opcodes() if op != "equal"]
        print(a, new[a].split(",")[1], "|", "; ".join(changes)[:300])
