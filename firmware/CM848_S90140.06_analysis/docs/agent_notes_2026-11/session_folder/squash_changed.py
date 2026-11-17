"""Functions whose bodies differ after removing all whitespace. Usage: squash_changed.py old.cpp new.cpp"""
import re
import sys

HEADER = re.compile(r"^// Function: (\S+) @ (0x[0-9a-f]+)$", re.M)


def split(path):
    parts = HEADER.split(open(path).read())
    return {parts[i + 1]: (parts[i], re.sub(r"\s+", "", parts[i + 2])) for i in range(1, len(parts), 3)}


o, n = split(sys.argv[1]), split(sys.argv[2])
changed = [n[a][0] for a in sorted(n) if a in o and o[a][1] != n[a][1]]
print(f"functions differing beyond whitespace: {len(changed)}")
for f in changed:
    print("  ", f)
