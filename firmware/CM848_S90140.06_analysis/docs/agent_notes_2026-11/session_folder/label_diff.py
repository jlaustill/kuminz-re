"""Classify each changed line between two builds: a pure auto-label rename, or something else."""
import difflib
import re
import sys
from collections import Counter

HEADER = re.compile(r"^// Function: (\S+) @ (0x[0-9a-f]+)$", re.M)
AUTO = re.compile(r"\b(?:_?DAT|BYTE|WORD|DWORD|PTR(?:_[A-Za-z]+)*|UNK|SUB|LAB|FUN|u_[^ ,;()]*?)_[0-9a-f]{8}\b")

def split(path):
    parts = HEADER.split(open(path).read())
    return {parts[i + 1]: (parts[i], parts[i + 2]) for i in range(1, len(parts), 3)}

old, new = split(sys.argv[1]), split(sys.argv[2])
swaps, other = Counter(), []
for a in new:
    if a not in old or old[a][1] == new[a][1]:
        continue
    o, n = old[a][1].split("\n"), new[a][1].split("\n")
    for tag, i1, i2, j1, j2 in difflib.SequenceMatcher(None, o, n).get_opcodes():
        if tag == "equal":
            continue
        if tag == "replace" and i2 - i1 == j2 - j1:
            for x, y in zip(o[i1:i2], n[j1:j2]):
                if AUTO.sub("@", x) == AUTO.sub("@", y) or re.sub(r"[A-Za-z_][A-Za-z0-9_]*", "@", x) == re.sub(r"[A-Za-z_][A-Za-z0-9_]*", "@", y):
                    for m in AUTO.findall(x):
                        swaps[m] += 1
                    continue
                other.append((new[a][0], x.strip()[:90], y.strip()[:90]))
        else:
            other.append((new[a][0], " | ".join(l.strip() for l in o[i1:i2])[:90], " | ".join(l.strip() for l in n[j1:j2])[:90]))
print("identifier-only line changes:", sum(swaps.values()), " other changes:", len(other))
for f, x, y in other[:20]:
    print(f"  {f}\n    - {x}\n    + {y}")
