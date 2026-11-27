"""Round 57: diff one function between the old .cpp (the map's function and global renames applied) and the new one,
after removing plates and declarations. usage: diff_function_r57.py <old.cpp> <new.cpp> <map.csv> <new function name>"""
import csv
import difflib
import re
import sys

old_t, new_t = open(sys.argv[1], errors="replace").read(), open(sys.argv[2], errors="replace").read()
rows = list(csv.DictReader(open(sys.argv[3])))
for r in rows:
    old_t = re.sub(rf"(?<![\w.]){re.escape(r['old_label'])}\b", r["name"], old_t)


def body(t, name):
    m = re.search(r"^// Function: " + re.escape(name) + r" @.*?(?=^// Function: |\Z)", t, re.S | re.M)
    b = re.sub(r"/\*.*?\*/", "", m.group(0), flags=re.S)
    return [l.strip() for l in b.splitlines() if l.strip() and not re.fullmatch(r"[A-Za-z_][\w *]* \**\w+;", l.strip())]


for line in difflib.unified_diff(body(old_t, sys.argv[4]), body(new_t, sys.argv[4]), lineterm="", n=1):
    print(line)
