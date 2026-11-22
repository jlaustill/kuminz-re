"""Round 39 stage C: each use of the given globals in the .cpp, as the function and the whitespace-collapsed
statement it sits in.  usage: symbol_uses.py <cpp> <name>..."""
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
    for m in re.finditer(r"\b" + re.escape(name) + r"\b", text):
        line_start = text.rfind("\n", 0, m.start()) + 1
        if text[line_start:m.start()].lstrip().startswith(("/*", "*")):
            continue
        s = max(text.rfind(";", 0, m.start()), text.rfind("{", 0, m.start()), text.rfind("}", 0, m.start())) + 1
        e = min(x for x in (text.find(";", m.end()), text.find("{", m.end())) if x != -1)
        stmt = re.sub(r"\s+", " ", text[s:e]).strip()
        if "/*" in stmt:
            continue
        print(f"[{name}] {func_at(m.start())}: {stmt[:230]}")
        seen += 1
        if seen >= 4:
            break
