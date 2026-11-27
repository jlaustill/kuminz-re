"""Round 94 (read-only): the code lines where each row of <changes.csv> carries a sign cast in the current .cpp
(and in the untyped render before round 93's typing), to see what kind of use each cast is: a compare (<, >, <=,
>=), arithmetic, an index, or a copy / store into a buffer. usage: cast_contexts_r94.py <cpp> <before cpp> <changes.csv>"""
import csv
import re
import sys

now, before, changes = sys.argv[1], sys.argv[2], sys.argv[3]
texts = {"now": open(now, errors="replace").read().split("\n"), "before": open(before, errors="replace").read().split("\n")}
for r in csv.DictReader(open(changes)):
    name = r["name"]
    print(f"== {r['address']} {name}: {r['current']} -> {r['decided']} ({r['reason']})")
    for label, lines in texts.items():
        pat = re.compile(rf"\((?:short|int|long|char|ushort|uint|ulong|byte|uchar)\)\s*_?{re.escape(name)}\b")
        for n, l in enumerate(lines):
            if pat.search(l):
                kind = "compare" if re.search(r"[<>]=?", l) and not re.search(r">>|<<", l) else "other"
                print(f"   {label}:{n + 1} [{kind}] {l.strip()[:150]}")
