"""Prove an enum-typing stage: in the NEW (cast-stripped) text put each member of the given enums back as its value,
drop the enum-type casts the typing adds, remove all whitespace (line wraps move), and require every function that
differs between the two copies to be equal after that.  usage: prove_enum_substitution.py <old_stripped.cpp>
<new_stripped.cpp> <enums.csv> <ENUM_NAME>..."""
import csv
import re
import sys

old_path, new_path, enums_csv, names = sys.argv[1], sys.argv[2], sys.argv[3], set(sys.argv[4:])
members = {}
for r in csv.reader(open(enums_csv)):
    if r and r[0] in names and len(r) > 2:
        members[r[2]] = int(r[1], 0)
assert members, "no members found"


def functions(path):
    t = open(path, errors="replace").read()
    return {m.group(1): m.group(0) for m in re.finditer(r"^// Function: (\S+) @.*?(?=^// Function: |\Z)", t, re.S | re.M)}


def body(text):
    """the code after the plate, comments and whitespace removed, hex integer literals written in decimal (the
    decompiler prints 11 as 0xb, the substitution writes 11)"""
    code = text[text.index("\n", text.index("(")):] if "(" in text else text
    code = re.sub(r"\b0x([0-9a-fA-F]+)\b", lambda m: str(int(m.group(1), 16)), code)
    return re.sub(r"\s+", "", re.sub(r"/\*.*?\*/", "", code, flags=re.S))


pattern = re.compile(r"\b(" + "|".join(sorted(members, key=len, reverse=True)) + r")\b")
casts = re.compile(r"\((" + "|".join(sorted(names)) + r")\)")
old, new = functions(old_path), functions(new_path)
changed = [f for f in new if f in old and old[f] != new[f]]
bad = []
for f in changed:
    n = casts.sub("", pattern.sub(lambda m: str(members[m.group(1)]), new[f]))
    o = casts.sub("", old[f])
    if body(o) != body(n):
        bad.append(f)
for f in changed:
    print(f"{'DIFFERENT' if f in bad else 'same'}  {f}")
print(f"{len(changed)} changed functions, {len(bad)} still different after substitution: "
      f"{'PROVEN' if not bad else 'NOT PROVEN'}")
