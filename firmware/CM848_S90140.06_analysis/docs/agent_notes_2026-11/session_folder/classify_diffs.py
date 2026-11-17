"""Classify every token-level difference of the functions that differ between two (reverse-mapped, comment-free)
.cpp files. Usage: classify_diffs.py old new"""
import difflib
import re
import sys
from collections import Counter

HEADER = re.compile(r"^// Function: (\S+) @ (0x[0-9a-f]+)$", re.M)
TYPES = r"(?:short|int|word|sword|byte|char|dword|ushort|uint|undefined\d?|ulonglong|longlong|bool)"


def split(path):
    parts = HEADER.split(open(path).read())
    return {parts[i + 1]: (parts[i], re.findall(r"\w+|[^\w\s]", parts[i + 2])) for i in range(1, len(parts), 3)}


def classify(a, b):
    sa, sb = " ".join(a), " ".join(b)
    cast = re.compile(rf"^(\( {TYPES} \*? ?\) ?)+$")
    if (not a and cast.match(sb + " ")) or (not b and cast.match(sa + " ")) or (not a and re.fullmatch(rf"\) \( {TYPES}", sb)) \
            or (not b and re.fullmatch(rf"\) \( {TYPES}", sa)):
        return "cast added / removed"
    if all(re.fullmatch(TYPES, t) for t in a + b) and a and b:
        return "cast / declaration type"
    if re.fullmatch(r"' \\ (0|x[0-9a-f]+) '", sa) and re.fullmatch(r"\d+", sb):
        return "char literal -> integer"
    if all(re.fullmatch(r"[a-z]{1,2}Var\d+", t) for t in a + b) and a and b:
        return "decompiler temporary renamed"
    if len(a) == len(b) == 1 and a[0].lstrip("_") == b[0].lstrip("_"):
        return "underscore variant fixed"
    if len(a) == len(b) == 1 and a[0].startswith("PTR_") and a[0][4:] == b[0]:
        return "PTR_ label -> row label"
    if "*" in a and "[" in b:
        return "pointer arithmetic -> array index"
    return "OTHER"


o, n = split(sys.argv[1]), split(sys.argv[2])
total = Counter()
others = []
for addr in sorted(n):
    if addr not in o or o[addr][1] == n[addr][1]:
        continue
    a, b = o[addr][1], n[addr][1]
    kinds = Counter()
    for tag, i1, i2, j1, j2 in difflib.SequenceMatcher(None, a, b, autojunk=False).get_opcodes():
        if tag == "equal":
            continue
        k = classify(a[i1:i2], b[j1:j2])
        kinds[k] += 1
        if k == "OTHER":
            others.append((n[addr][0], " ".join(a[max(0, i1 - 4):i2 + 2]), " ".join(b[max(0, j1 - 4):j2 + 2])))
    total.update(kinds)
    print(f"{n[addr][0]}: {dict(kinds)}")
print("TOTAL:", dict(total))
for f, x, y in others[:40]:
    print(f"OTHER {f}\n   - {x[:160]}\n   + {y[:160]}")
