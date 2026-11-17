"""List (old auto-label -> new identifier) swaps and whether the new name is used as a call."""
import difflib
import re
import sys

HEADER = re.compile(r"^// Function: (\S+) @ (0x[0-9a-f]+)$", re.M)
AUTO = re.compile(r"\b((?:_?DAT|BYTE|WORD|DWORD|PTR(?:_[A-Za-z]+)*|UNK|SUB|LAB|FUN)_[0-9a-f]{8})\b")

def split(path):
    parts = HEADER.split(open(path).read())
    return {parts[i + 1]: (parts[i], parts[i + 2]) for i in range(1, len(parts), 3)}

old, new = split(sys.argv[1]), split(sys.argv[2])
functions = set(n for n, _ in new.values())
pairs = {}
for a in new:
    if a not in old or old[a][1] == new[a][1]:
        continue
    o = " ".join(old[a][1].split())
    n = " ".join(new[a][1].split())
    sm = difflib.SequenceMatcher(None, re.findall(r"\w+|[^\w\s]", o), re.findall(r"\w+|[^\w\s]", n))
    ot, nt = re.findall(r"\w+|[^\w\s]", o), re.findall(r"\w+|[^\w\s]", n)
    for tag, i1, i2, j1, j2 in sm.get_opcodes():
        if tag == "replace" and i2 - i1 == 1 and j2 - j1 == 1 and AUTO.fullmatch(ot[i1]):
            after = nt[j1 + 1] if j1 + 1 < len(nt) else ""
            kind = "call" if after == "(" else "data"
            pairs.setdefault((ot[i1], nt[j1], kind), set()).add(new[a][0])
for (o, n, kind), fns in sorted(pairs.items(), key=lambda kv: kv[0][2]):
    flag = "  <-- function name used as data" if kind == "data" and n in functions else ""
    print(f"{kind:4s} {o:28s} -> {n:60s} in {sorted(fns)[0]}{flag}")
