"""For each named cache word matching a pattern, list the tables of the lookups that take it as first argument (or as
the y-axis cache of a 2-D lookup) and the calling functions. usage: cache_tables.py <cpp> <name regex>"""
import collections
import re
import sys

cpp, pattern = sys.argv[1], re.compile(sys.argv[2])
text = open(cpp).read()
starts = [(m.start(), m.group(1)) for m in re.finditer(r"^// Function: (\S+) @", text, re.M)]


def func_of(pos):
    name = None
    for s, f in starts:
        if s > pos:
            break
        name = f
    return name


uses = collections.defaultdict(lambda: [set(), set(), 0])
for m in re.finditer(r"(\w+)\s*\(([^;]*?)\)\s*;", text, re.S):
    args = m.group(2)
    for c in set(re.findall(r"&?\b([a-z0-9_]+)\b", args)):
        if pattern.search(c):
            tables = re.findall(r"\b([a-z0-9_]+?_(?:x_axis|y_axis|axis|values|grid|table))\b", args)
            u = uses[c]
            u[0].update(tables)
            u[1].add(f"{m.group(1)}@{func_of(m.start())}")
for c in sorted(uses):
    tables, calls, _ = uses[c]
    print(c, "|", " ".join(sorted(tables)) or "-", "|", " ".join(sorted(calls))[:200])
