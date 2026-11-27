"""Round 33: unified diff of named functions between two .cpp files, after renaming the map's old labels to their new
names in the old text (plate comments dropped), so only the structural changes remain to review.
usage: diff_functions.py <old cpp> <new cpp> <map.csv> <function>..."""
import csv
import difflib
import re
import sys

old_t, new_t = open(sys.argv[1], errors="replace").read(), open(sys.argv[2], errors="replace").read()
rows = list(csv.DictReader(open(sys.argv[3])))
renames = sorted(((r["old_label"], r["name"]) for r in rows if r["old_label"] and r["kind"] != "field"),
                 key=lambda p: -len(p[0]))


def body(t, name):
    m = re.search(r"^// Function: " + re.escape(name) + r" @[^\n]*\n(.*?)(?=^// Function: |\Z)", t, re.S | re.M)
    text = re.sub(r"/\*.*?\*/\n?", "", m.group(1), flags=re.S)
    return [l.rstrip() for l in text.split("\n") if l.strip() and not l.startswith("//")]


for name in sys.argv[4:]:
    old_lines = []
    for l in body(old_t, name):
        for o, n in renames:
            l = re.sub(r"(?<![\w.])" + re.escape(o) + r"(?!\w)", n, l)
        old_lines.append(l)
    new_lines = body(new_t, name)
    d = list(difflib.unified_diff(old_lines, new_lines, "old", "new", n=0, lineterm=""))
    print(f"===== {name}: {len([x for x in d if x[:1] in '+-' and x[:3] not in ('---', '+++')])} changed lines")
    for x in d[2:]:
        print(x[:170])
