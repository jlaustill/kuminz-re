"""Round 93 (read-only): signedness of the word / dword rows typed this round, from the decompiler's own casts.
- AFTER typing (unsigned word / dword), a use the code treats as signed prints '(short)name' / '(int)name';
- BEFORE typing (the row was 'undefined'), a use the code treats as unsigned printed '(ushort)_name' / '(uint)_name'.
A row is SIGNED when it has signed-cast renders after and no unsigned-cast render before; it is MIXED when both.
Writes address,name,type,new_type for the SIGNED rows (word -> short, dword -> int).
usage: signedness_r93.py <before.cpp> <after.cpp> <pass.csv> <out.csv>"""
import csv
import re
import sys

before, after, passed, out = sys.argv[1:5]


def code(path):
    text = open(path, errors="replace").read()
    text = re.sub(r"/\*.*?\*/", " ", text, flags=re.S)
    return "\n".join(l for l in text.split("\n") if not l.lstrip().startswith("//"))


b, a = code(before), code(after)
signed_after, unsigned_before, total_after = {}, {}, {}
for m in re.finditer(r"\((short|int|long)\)\s*([A-Za-z_][A-Za-z0-9_]*)\b", a):
    signed_after[m.group(2)] = signed_after.get(m.group(2), 0) + 1
for m in re.finditer(r"\((ushort|uint|ulong|word|dword)\)\s*_([A-Za-z][A-Za-z0-9_]*)\b", b):
    unsigned_before[m.group(2)] = unsigned_before.get(m.group(2), 0) + 1
for m in re.finditer(r"[A-Za-z_][A-Za-z0-9_]*", a):
    total_after[m.group(0)] = total_after.get(m.group(0), 0) + 1
rows, counts = [], {}
for r in csv.DictReader(open(passed)):
    if r["type"] == "byte":
        continue
    name = r["name"]
    s, u, t = signed_after.get(name, 0), unsigned_before.get(name, 0), total_after.get(name, 0)
    kind = "SIGNED" if s and not u else "MIXED" if s and u else "unsigned-or-neutral"
    counts[kind] = counts.get(kind, 0) + 1
    if kind == "SIGNED":
        rows.append((r["address"], name, r["type"], "short" if r["type"] == "word" else "int", s, t))
    elif kind == "MIXED":
        print(f"MIXED {name}: {s} signed-cast renders after, {u} unsigned-cast renders before, {t} renders")
with open(out, "w") as fh:
    fh.write("address,name,type,new_type,signed_cast_renders,renders\n")
    for row in rows:
        fh.write(",".join(str(x) for x in row) + "\n")
print(counts, "| signed-cast renders on SIGNED rows:", sum(r[4] for r in rows), "of", sum(r[5] for r in rows), "renders")
