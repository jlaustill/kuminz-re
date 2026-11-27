"""Round 94 (read-only): the sign evidence of a row needs two renders - typed unsigned, a signed use prints as a
signed cast and an unsigned use prints plain; typed signed, the reverse. For each row of <rows.csv> (address,name),
counts the signed casts in <unsigned view .cpp> and the unsigned casts in <signed view .cpp> (on the bare name).
usage: both_views_r94.py <rows.csv> <unsigned view .cpp> <signed view .cpp>"""
import csv
import re
import sys

rows, unsigned_view, signed_view = sys.argv[1:4]


def code(path):
    t = open(path, errors="replace").read()
    t = re.sub(r"/\*.*?\*/", " ", t, flags=re.S)
    return "\n".join(l for l in t.split("\n") if not l.lstrip().startswith("//"))


u, s = code(unsigned_view), code(signed_view)
for r in csv.DictReader(open(rows)):
    n = r["name"]
    sig = len(re.findall(rf"\((?:short|int|long|char)\)\s*{re.escape(n)}\b", u))
    uns = len(re.findall(rf"\((?:ushort|uint|ulong|byte|uchar)\)\s*{re.escape(n)}\b", s))
    verdict = "signed" if sig and not uns else "unsigned" if uns and not sig else "mixed" if sig and uns else "no evidence"
    print(f"{r['address']} {n[:64]:64} signed uses {sig:2} unsigned uses {uns:2} -> {verdict}")
