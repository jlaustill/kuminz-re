"""Per changed function: changed-line count and the first few -/+ lines. Usage: diff_summary.py old.cpp new.cpp [n]"""
import difflib
import re
import sys

old_path, new_path = sys.argv[1:3]
n = int(sys.argv[3]) if len(sys.argv) > 3 else 3
HEADER = re.compile(r"^// Function: (\S+) @ (0x[0-9a-f]+)$", re.M)


def split(path):
    parts = HEADER.split(open(path).read())
    return {parts[i + 1]: (parts[i], parts[i + 2]) for i in range(1, len(parts), 3)}


o, w = split(old_path), split(new_path)
for a in sorted(w):
    if a in o and o[a][1] != w[a][1]:
        d = [l for l in difflib.unified_diff(o[a][1].split("\n"), w[a][1].split("\n"), n=0, lineterm="")
             if l[:1] in "-+" and not l.startswith(("---", "+++"))]
        print(f"== {w[a][0]} ({len(d)} lines)")
        for l in d[:n]:
            print("   " + l.strip()[:150])
