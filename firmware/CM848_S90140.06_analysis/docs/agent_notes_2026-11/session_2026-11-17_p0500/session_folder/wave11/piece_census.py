"""Count decompiler piece accesses (`sym._N_M_` / `sym.field._N_M_` / `(&sym)[..]._N_M_`) per base symbol in two .cpp
files and print every symbol whose count went UP (new pieces = a shape regression to inspect) and the totals.
Usage: piece_census.py <pre.cpp> <post.cpp>"""
import collections
import re
import sys

PIECE = re.compile(r"\b([A-Za-z_][A-Za-z0-9_]*)((?:\.[A-Za-z_][A-Za-z0-9_]*|\[[^\]\n]*\])*)\._(\d+)_(\d+)_")


def census(path):
    counts = collections.Counter()
    for m in PIECE.finditer(open(path).read()):
        counts[m.group(1) + m.group(2)] += 1
    return counts


pre, post = census(sys.argv[1]), census(sys.argv[2])
up = sorted(((post[k] - pre.get(k, 0), k) for k in post if post[k] > pre.get(k, 0)), reverse=True)
down = sum(pre[k] - post.get(k, 0) for k in pre if pre[k] > post.get(k, 0))
print(f"pieces total {sum(pre.values())} -> {sum(post.values())} ({down} removed, {sum(d for d, _ in up)} added)")
for d, k in up:
    print(f"  +{d}  {k}  ({pre.get(k, 0)} -> {post[k]})")
