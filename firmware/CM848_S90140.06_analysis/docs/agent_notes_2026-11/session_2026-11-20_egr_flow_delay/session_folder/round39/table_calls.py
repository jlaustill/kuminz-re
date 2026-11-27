"""Round 39: each lookup call that uses a given table name: the function, the statement it is in (what the result is
assigned to), the inputs and the cache. usage: table_calls.py <cpp> <table name>..."""
import re
import sys

text = open(sys.argv[1], errors="replace").read()
marks = [(m.start(), m.group(1)) for m in re.finditer(r"^// Function: (\S+) @", text, re.M)]


def func_at(pos):
    f = None
    for s, n in marks:
        if s > pos:
            break
        f = n
    return f


for name in sys.argv[2:]:
    seen = 0
    for m in re.finditer(r"[^;{}]*\b(lookupTableInterpolation|cm848_dualAxisTableInterpolation|"
                         r"cm848_interpolateTableWithoutCache)\s*\(([^;]*?)\);", text, re.S):
        if not re.search(r"\b" + re.escape(name) + r"\b", m.group(0)):
            continue
        stmt = re.sub(r"\s+", " ", m.group(0)).strip()
        print(f"[{name}] {func_at(m.start())}: {stmt[:260]}")
        seen += 1
        if seen >= 3:
            break
