"""For each symbol: the functions of a .cpp whose code (not comments) uses it, with a count.
Usage: users.py <cpp> <symbol>... ; a symbol ending in '()' lists call sites only."""
import re
import sys

cpp, symbols = sys.argv[1], sys.argv[2:]
text = open(cpp).read()
# drop comments so plate comments do not count as uses
code = re.sub(r"/\*.*?\*/", lambda m: "\n" * m.group(0).count("\n"), text, flags=re.S)
code = re.sub(r"//[^\n]*", "", code)
chunks = re.split(r"(?m)^(?=void |[A-Za-z_][\w ]*\*? ?[A-Za-z_]\w*\()", code)
functions = []
current = None
for line_no, line in enumerate(code.split("\n"), 1):
    m = re.match(r"^[A-Za-z_][\w \*]*?\b([A-Za-z_]\w*)\(.*\)\s*$", line)
    if m and not line.startswith(" "):
        current = m.group(1)
    functions.append(current)
lines = code.split("\n")
for sym in symbols:
    call = sym.endswith("()")
    name = sym[:-2] if call else sym
    pat = re.compile(rf"\b{re.escape(name)}\s*\(" if call else rf"\b{re.escape(name)}\b")
    counts = {}
    for i, line in enumerate(lines):
        if pat.search(line) and functions[i] and functions[i] != name:
            counts[functions[i]] = counts.get(functions[i], 0) + 1
    print(f"== {sym}: " + (", ".join(f"{f} x{n}" for f, n in sorted(counts.items())) or "(none)"))
