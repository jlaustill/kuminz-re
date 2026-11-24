"""Full label-only check: strip every /* ... */ comment and the Generated header, apply a rename map (old -> new, whole
words) to the old .cpp, and diff the complete text against the new one. Prints every differing line (both sides).
usage: label_only_check.py <old.cpp> <new.cpp> <map.csv (address,name,old_label,...)>"""
import csv
import difflib
import re
import sys

old_path, new_path, map_path = sys.argv[1:4]
pairs = [(r["old_label"], r["name"]) for r in csv.DictReader(open(map_path))]


def text(path, rename):
    t = open(path, errors="replace").read()
    t = re.sub(r"/\*.*?\*/", "", t, flags=re.S)
    t = re.sub(r"^// Generated:.*$", "", t, flags=re.M)
    if rename:
        for old, new in pairs:
            t = re.sub(rf"(?<![A-Za-z0-9_]){re.escape(old)}(?![A-Za-z0-9_])", new, t)
    return [l.rstrip() for l in t.split("\n") if l.strip()]


a, b = text(old_path, True), text(new_path, False)
diff = [l for l in difflib.unified_diff(a, b, lineterm="", n=0) if not l.startswith(("---", "+++", "@@"))]
print(f"{len(diff)} differing lines")
for l in diff[:40]:
    print("  " + l[:150])
