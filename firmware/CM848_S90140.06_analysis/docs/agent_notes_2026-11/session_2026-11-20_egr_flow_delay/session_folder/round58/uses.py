"""Round 58: list each name's uses in a .cpp, by function, outside plate comments (whole words; a name is matched
also as name.field / name[i]).  usage: uses.py <cpp> <name>..."""
import re
import sys

text = open(sys.argv[1], errors="replace").read()
parts = re.split(r"^// Function: (\S+) @[^\n]*\n", text, flags=re.M)
bodies = {parts[i]: re.sub(r"/\*.*?\*/", "", parts[i + 1], flags=re.S) for i in range(1, len(parts), 2)}
for name in sys.argv[2:]:
    pat = re.compile(rf"(?<![\w.]){re.escape(name)}\b")
    hits = [(f, l.strip()) for f, b in bodies.items() for l in b.splitlines() if pat.search(l)]
    print(f"== {name}: {len(hits)} lines in {len({f for f, _ in hits})} functions")
    for f, l in hits[:10]:
        print(f"  {f}: {l[:120]}")
