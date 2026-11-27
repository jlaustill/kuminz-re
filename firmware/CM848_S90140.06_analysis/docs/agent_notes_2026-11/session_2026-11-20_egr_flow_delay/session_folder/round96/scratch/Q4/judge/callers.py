"""List the functions of a decompiled .cpp that mention each target name (callers / pointer users).
usage: callers.py <cpp> <name> [<name> ...]"""
import re
import sys

text = open(sys.argv[1], errors="replace").read()
funcs = [(m.group(1), m.start()) for m in re.finditer(r"^// Function: (\S+) @", text, flags=re.M)]
bounds = []
for i, (n, s) in enumerate(funcs):
    e = funcs[i + 1][1] if i + 1 < len(funcs) else len(text)
    bounds.append((n, s, e))
for target in sys.argv[2:]:
    callers = []
    for n, s, e in bounds:
        if n == target:
            continue
        body = text[s:e]
        c = len(re.findall(rf"\b{re.escape(target)}\b", body))
        if c:
            callers.append(f"{n}({c})")
    print(target, "<-", ", ".join(callers) if callers else "NONE")
