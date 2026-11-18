"""List functions whose decompiled body differs between two .cpp builds."""
import re
import sys

HEADER = re.compile(r"^// Function: (\S+) @ (0x[0-9a-f]+)$", re.M)

def split(path):
    text = open(path).read()
    parts = HEADER.split(text)
    out = {}
    for i in range(1, len(parts), 3):
        out[parts[i + 1]] = (parts[i], parts[i + 2])
    return out

old, new = split(sys.argv[1]), split(sys.argv[2])
changed = [(a, new[a][0]) for a in new if a in old and old[a][1] != new[a][1]]
renamed = [(a, old[a][0], new[a][0]) for a in new if a in old and old[a][0] != new[a][0]]
added = [a for a in new if a not in old]
removed = [a for a in old if a not in new]
print(f"functions: {len(new)}  changed bodies: {len(changed)}  renamed: {len(renamed)}  added: {len(added)}  removed: {len(removed)}")
limit = int(sys.argv[3]) if len(sys.argv) > 3 else 60
for a, n in changed[:limit]:
    print("  ", a, n)
for a, o, n in renamed:
    print("   renamed", a, o, "->", n)
for a in added[:20]:
    print("   added", a, new[a][0])
for a in removed[:20]:
    print("   removed", a, old[a][0])
