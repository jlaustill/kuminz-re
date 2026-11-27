"""Show the line diff of functions between the old .cpp (with prove_r68.py's renames) and the new one, plates dropped.
usage: diff_r68.py <old.cpp> <new.cpp> <function> [...]"""
import difflib
import re
import sys

sys.path.insert(0, "/home/linux/.claude/jobs/374b0424/tmp/w15/r73")
from prove_r73b_cm550 import PAIRS  # noqa: E402


def body(path, name, rename):
    t = open(path, errors="replace").read()
    m = re.search(rf"^// Function: {re.escape(name)} @[^\n]*\n(.*?)(?=^// Function: |\Z)", t, flags=re.M | re.S)
    b = re.sub(r"/\*.*?\*/\n?", "", m.group(1), flags=re.S)
    if rename:
        for old, new in PAIRS:
            b = b.replace(old, new)
    return [l.rstrip() for l in b.split("\n") if l.strip()]


for name in sys.argv[3:]:
    print("===", name)
    for line in difflib.unified_diff(body(sys.argv[1], name, True), body(sys.argv[2], dict(PAIRS).get(name, name), False), lineterm="", n=0):
        if not line.startswith(("---", "+++", "@@")):
            print("  " + line[:150])
