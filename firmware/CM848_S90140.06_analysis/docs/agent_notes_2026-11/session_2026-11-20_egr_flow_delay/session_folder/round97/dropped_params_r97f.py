"""Round 97 stage F: for every function whose prototype rows prototypes_r97f.py replaced, compare the committed
(HEAD) parameter indexes with the new ones; print each function that lost a parameter row or changed its count.
usage: dropped_params_r97f.py <head function_definitions.csv> <current function_definitions.csv>"""
import collections
import sys


def params(path):
    out = collections.defaultdict(dict)
    for line in open(path, newline=""):
        q = line.rstrip("\r\n").split(",", 5)
        if len(q) > 4 and q[0].startswith("0x"):
            out[int(q[0], 16)][q[2]] = (q[3], q[4])
    return out


head, now = params(sys.argv[1]), params(sys.argv[2])
changed = [a for a in now if now[a] != head.get(a)]
for a in sorted(changed):
    h = {k for k in head.get(a, {}) if k != "return"}
    n = {k for k in now[a] if k != "return"}
    if h - n or (head.get(a) and len(h) != len(n)):
        print(f"0x{a:x}: head params {sorted(h)} -> now {sorted(n)}; head return {head.get(a, {}).get('return')} now {now[a].get('return')}")
print(len(changed), "functions with changed rows")
