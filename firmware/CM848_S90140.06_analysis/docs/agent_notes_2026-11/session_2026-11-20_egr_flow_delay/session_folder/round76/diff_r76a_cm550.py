"""Line diff of functions between the old .cpp (register renders renamed as in prove_r76a_cm550.py) and the new one.
usage: diff_r76a_cm550.py <old.cpp> <new.cpp> <global_variables.csv> <function> [...]"""
import difflib
import re
import sys

old_path, new_path, gv = sys.argv[1:4]
names = {}
for line in open(gv, newline=""):
    parts = line.rstrip("\r\n").split(",", 3)
    if len(parts) > 2 and parts[0].startswith("0x00fff") and parts[1]:
        names[parts[0][4:]] = parts[1]
OLD = re.compile(r"\b_?(?:Ram|DAT_|uRam|bRam|cRam|sRam|iRam)00(fff[0-9a-f]{3})\b")


def body(path, name, rename):
    t = open(path, errors="replace").read()
    m = re.search(rf"^// Function: {re.escape(name)} @[^\n]*\n(.*?)(?=^// Function: |\Z)", t, flags=re.M | re.S)
    b = re.sub(r"/\*.*?\*/\n?", "", m.group(1), flags=re.S)
    if rename:
        b = OLD.sub(lambda x: names.get(x.group(1), x.group(0)), b)
    return [l.rstrip() for l in b.split("\n") if l.strip()]


for name in sys.argv[4:]:
    print("===", name)
    for line in difflib.unified_diff(body(old_path, name, True), body(new_path, name, False), lineterm="", n=0):
        if not line.startswith(("---", "+++", "@@")):
            print("  " + line[:150])
