"""After a word -> i16 sweep: every new '(ushort)NAME' / '(word)NAME' / '(uint)NAME' occurrence of a retyped name, per
function (a counter-based diff against the old build), so each can be checked against its load instruction.
Usage: unsigned_uses.py <old.cpp> <new.cpp> <global_variables.csv> <marker>"""
import collections
import re
import sys

old_path, new_path, gv_path, marker = sys.argv[1:5]
names = []
for line in open(gv_path):
    p = line.rstrip("\n").split(",", 3)
    if len(p) > 3 and p[0].startswith("0x") and p[2] == "i16" and marker in p[3]:
        names.append(p[1])
pat = re.compile(r"\((ushort|word|uint)\)\s*(" + "|".join(re.escape(n) for n in sorted(names, key=len, reverse=True))
                 + r")\b")


def census(path):
    text = open(path).read()
    count = collections.Counter()
    fn = None
    for line in text.split("\n"):
        m = re.match(r"// Function: (\S+) @", line)
        if m:
            fn = m.group(1)
            continue
        for c in pat.finditer(line):
            count[(fn, c.group(1), c.group(2))] += 1
    return count


a, b = census(old_path), census(new_path)
new = {k: v - a.get(k, 0) for k, v in b.items() if v > a.get(k, 0)}
print(f"retyped names: {len(names)}; new unsigned-cast uses: {sum(new.values())} in {len({k[0] for k in new})} functions")
for (fn, cast, name), n in sorted(new.items()):
    print(f"  {fn}: ({cast}){name} x{n}")
