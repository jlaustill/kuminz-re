"""Round 32: rank functions by their unnamed data renders (code only): DAT_ / ram0x / uRam / WORD_ / BYTE_ / DWORD_ labels
and ._N_M_ pieces of named globals. The top of the list is where naming or typing still pays.
usage: messy_functions.py <cpp> [top]"""
import re
import sys
from collections import Counter

cpp = sys.argv[1]
top = int(sys.argv[2]) if len(sys.argv) > 2 else 25
text = open(cpp, errors="replace").read()
marks = list(re.finditer(r"^// Function: (\S+) @ (0x[0-9a-f]+)", text, re.M))
rows = []
for i, m in enumerate(marks):
    body = text[m.end(): marks[i + 1].start() if i + 1 < len(marks) else len(text)]
    body = re.sub(r"/\*.*?\*/", "", body, flags=re.S)
    labels = re.findall(r"\b(?:DAT|ram0x|uRam|WORD|BYTE|DWORD|UNK)_?[0-9a-f]{6,8}\b", body)
    pieces = re.findall(r"\b[a-z][a-z0-9_]*\._\d+_\d+_", body)
    distinct = len(set(labels))
    rows.append((len(labels) + len(pieces), distinct, len(pieces), m.group(1), m.group(2)))
rows.sort(reverse=True)
print("total distinct-labels pieces function")
for total, distinct, pieces, name, addr in rows[:top]:
    print(f"{total:5} {distinct:5} {pieces:5}  {name} @ {addr}")
c = Counter()
for total, distinct, pieces, name, addr in rows:
    c["functions with any"] += total > 0
    c["renders"] += total
print(dict(c))
