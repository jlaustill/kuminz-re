"""List every function whose canonical text differs between old_stripped.cpp and new_stripped.cpp in a round folder
(the proof prints only its first 12).  usage: differing.py <round folder> [expected names file]"""
import os
import re
import sys

folder = sys.argv[1]


def blocks(path):
    text = open(os.path.join(folder, path), errors="replace").read()
    out = {}
    for b in re.split(r"^// Function: ", text, flags=re.M)[1:]:
        name = b.split(" @ ", 1)[0]
        out[name] = re.sub(r"/\*.*?\*/", "", b, flags=re.S)  # plates and other comments excluded
    return out


a, b = blocks("old_stripped.cpp"), blocks("new_stripped.cpp")
names = sorted(n for n in set(a) | set(b) if a.get(n) != b.get(n))
expected = set(open(sys.argv[2]).read().split()) if len(sys.argv) > 2 else set()
for n in names:
    print(("   " if n in expected else " ! ") + n)
print(f"{len(names)} differ; unexpected: {len([n for n in names if n not in expected]) if expected else 'n/a'}; "
      f"expected but equal: {sorted(expected - set(names)) if expected else 'n/a'}")
