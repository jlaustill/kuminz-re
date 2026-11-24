"""Token-level diff of two decompilations, per function, ignoring line wrapping and comments: apply the rename map
(old -> new, whole words) to the old text, tokenize each function body, and print each function's token changes as
'old tokens => new tokens'. Then a census of the distinct changes. usage: token_diff.py <old.cpp> <new.cpp> <map.csv>"""
import collections
import csv
import difflib
import re
import sys

old_path, new_path, map_path = sys.argv[1:4]
pairs = [(r["old_label"], r["name"]) for r in csv.DictReader(open(map_path))]
FUNC = re.compile(r"^// Function: (\S+) @ (0x[0-9a-fA-F]+)", re.M)
TOKEN = re.compile(r"0x[0-9a-fA-F]+[UuLl]*|\d+[UuLl]*|[A-Za-z_][A-Za-z0-9_]*|->|<<|>>|<=|>=|==|!=|&&|\|\||\S")


def strip(text):
    text = re.sub(r"/\*.*?\*/", " ", text, flags=re.S)
    return re.sub(r"//[^\n]*", lambda m: m.group(0) if m.group(0).startswith("// Function:") else " ", text)


def functions(text, rename):
    out = {}
    marks = list(FUNC.finditer(text))
    for i, m in enumerate(marks):
        body = text[m.end():marks[i + 1].start() if i + 1 < len(marks) else len(text)]
        if rename:
            for old, new in pairs:
                body = re.sub(rf"(?<![A-Za-z0-9_]){re.escape(old)}(?![A-Za-z0-9_])", new, body)
        out[m.group(2).lower()] = TOKEN.findall(strip(body))
    return out


old = functions(open(old_path, errors="replace").read(), True)
new = functions(open(new_path, errors="replace").read(), False)
census = collections.Counter()
for address in sorted(set(old) & set(new)):
    a, b = old[address], new[address]
    if a == b:
        continue
    changes = []
    for tag, i1, i2, j1, j2 in difflib.SequenceMatcher(None, a, b, autojunk=False).get_opcodes():
        if tag != "equal":
            change = f"{' '.join(a[i1:i2])} => {' '.join(b[j1:j2])}"
            changes.append(change)
            census[change] += 1
    print(f"{address}: {len(changes)} token changes: " + " | ".join(changes)[:600])
print("---- census of distinct changes")
for change, n in census.most_common():
    print(f"{n:4} {change[:200]}")
