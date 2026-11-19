"""usage: refs.py <cpp> <name>... : every line mentioning each name, with owning function (name-only grep)."""
import re
import sys

cpp = open(sys.argv[1]).read().split("\n")
owner = []
cur = None
for line in cpp:
    m = re.match(r"^// Function: (\S+) @ (0x[0-9a-f]+)", line)
    if m:
        cur = f"{m.group(1)}@{m.group(2)}"
    owner.append(cur)
for name in sys.argv[2:]:
    pat = re.compile(rf"(?<![\w]){re.escape(name)}(?![\w])")
    hits = [(i + 1, owner[i], l.strip()) for i, l in enumerate(cpp) if pat.search(l) and not l.startswith("// Function")]
    print(f"=== {name}: {len(hits)} lines")
    for n, o, t in hits:
        print(f"  {n} [{o}] {t[:170]}")
