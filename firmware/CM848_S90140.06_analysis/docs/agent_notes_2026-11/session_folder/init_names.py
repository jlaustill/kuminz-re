"""List names this PR added (present in + lines, absent from - lines) that use `init` instead of `initialize`."""
import re
import sys

added, removed = {}, set()
f = None
for line in open(sys.argv[1]):
    if line.startswith("+++ "):
        f = line.split("/")[-1].strip()
        continue
    if line[:1] not in "+-" or line.startswith(("+++", "---")):
        continue
    p = line[1:].split(",")
    col = 2 if f in ("structure_definitions.csv", "enums.csv") else 1
    if len(p) > col and p[col]:
        if line[0] == "+":
            added.setdefault(p[col], f)
        else:
            removed.add(p[col])
INIT = re.compile(r"(?:^|_)init(?:_|$)|(?<=[a-z0-9])Init(?=[A-Z0-9_]|$)|^(?:[a-z0-9]+_)*init(?=[A-Z0-9])", re.I)
bad = sorted(n for n in added if n not in removed and INIT.search(n) and not re.search(r"initiali[sz]|initial", n, re.I))
print(len(bad), "names added by this PR use init:")
for n in bad:
    print(f"  {n} ({added[n]})")
