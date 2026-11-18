"""Artifact classes the piece census misses: default data names (DAT_ / _DAT_ / xRam) that appear only in the post
build, and CONCAT combines counted by their operand names. Usage: artifact_census.py <pre.cpp> <post.cpp>"""
import collections
import re
import sys

pre, post = open(sys.argv[1]).read(), open(sys.argv[2]).read()
DEFAULT = re.compile(r"\b_?(?:DAT_[0-9a-f]{8}|[a-z]{1,2}Ram[0-9a-f]{8})\b")
a, b = collections.Counter(DEFAULT.findall(pre)), collections.Counter(DEFAULT.findall(post))
new = sorted((k, v) for k, v in b.items() if k not in a)
grown = sorted((k, a[k], v) for k, v in b.items() if k in a and v > a[k])
print(f"default data names: {sum(a.values())} -> {sum(b.values())} uses; only in post: {len(new)}; grown: {len(grown)}")
for k, v in new:
    print(f"  NEW   {k} x{v}")
for k, x, y in grown:
    print(f"  GROWN {k} {x} -> {y}")

CONCAT = re.compile(r"CONCAT\d\d\(([^()]*(?:\([^()]*\))*[^()]*)\)")
OPERAND = re.compile(r"\b[a-z][a-z0-9]*_[a-z0-9_]+\b")


def concats(text):
    counts = collections.Counter()
    for m in CONCAT.finditer(text):
        for name in set(OPERAND.findall(m.group(1))):
            counts[name] += 1
    return counts


c1, c2 = concats(pre), concats(post)
up = sorted(((v - c1.get(k, 0), k, c1.get(k, 0), v) for k, v in c2.items() if v > c1.get(k, 0)), reverse=True)
print(f"CONCAT total {pre.count('CONCAT')} -> {post.count('CONCAT')}; operands with more CONCATs: {len(up)}")
for d, k, x, y in up:
    print(f"  +{d} {k} ({x} -> {y})")
