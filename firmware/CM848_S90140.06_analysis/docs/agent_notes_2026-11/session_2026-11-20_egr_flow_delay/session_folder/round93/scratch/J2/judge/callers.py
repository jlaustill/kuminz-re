"""callers.py <cpp> <name> [...]: list the functions whose decompiled body mentions name( ."""
import re
import sys

text = open(sys.argv[1], errors="replace").read()
funcs = [(m.start(), m.group(1), m.group(2)) for m in re.finditer(r"^// Function: (\S+) @ (\S+)", text, flags=re.M)]
funcs.append((len(text), None, None))
for name in sys.argv[2:]:
    pat = re.compile(r"\b" + re.escape(name) + r"\s*\(")
    hits = []
    for i in range(len(funcs) - 1):
        s, fn, addr = funcs[i]
        e = funcs[i + 1][0]
        body = text[s:e]
        # skip the definition line itself
        first_nl = body.find("\n")
        count = 0
        for m in pat.finditer(body):
            line_start = body.rfind("\n", 0, m.start()) + 1
            line = body[line_start:body.find("\n", m.start())]
            if fn == name and re.match(r"^\S.*\b" + re.escape(name) + r"\s*\(", line):
                continue
            count += 1
        if count:
            hits.append(f"{fn}@{addr} x{count}")
    print(f"{name}: {', '.join(hits) if hits else '(none)'}")
